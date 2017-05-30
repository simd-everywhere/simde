/* Copyright (c) 2017 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <test/simd-js/simd-js.h>
#include <simde/simd-js/simd-js.h>

#include <math.h>

static MunitResult
test_simde_em_int32x4_set(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a[4];
    int32_t r[4];
  } test_vec[8] = {
    { { INT32_C( 1686923533), INT32_C( -339399594), INT32_C( 1208422230), INT32_C( 1863337896) },
      { INT32_C( 1686923533), INT32_C( -339399594), INT32_C( 1208422230), INT32_C( 1863337896) } },
    { { INT32_C(  921619215), INT32_C( 1488585756), INT32_C( 1420288323), INT32_C(-1081566784) },
      { INT32_C(  921619215), INT32_C( 1488585756), INT32_C( 1420288323), INT32_C(-1081566784) } },
    { { INT32_C(  842412681), INT32_C( -271480119), INT32_C(-1186702606), INT32_C( 1949472484) },
      { INT32_C(  842412681), INT32_C( -271480119), INT32_C(-1186702606), INT32_C( 1949472484) } },
    { { INT32_C( -479621788), INT32_C(  519644324), INT32_C(  234954023), INT32_C( -954271943) },
      { INT32_C( -479621788), INT32_C(  519644324), INT32_C(  234954023), INT32_C( -954271943) } },
    { { INT32_C( 1854916977), INT32_C(-1817496280), INT32_C(  371629665), INT32_C(  584223329) },
      { INT32_C( 1854916977), INT32_C(-1817496280), INT32_C(  371629665), INT32_C(  584223329) } },
    { { INT32_C(-1930420089), INT32_C( 1125994374), INT32_C( 1692020876), INT32_C( -969781295) },
      { INT32_C(-1930420089), INT32_C( 1125994374), INT32_C( 1692020876), INT32_C( -969781295) } },
    { { INT32_C( 1629102615), INT32_C( 1060700216), INT32_C(   77198508), INT32_C(-1943787893) },
      { INT32_C( 1629102615), INT32_C( 1060700216), INT32_C(   77198508), INT32_C(-1943787893) } },
    { { INT32_C(-1096411985), INT32_C( 1818939186), INT32_C( 1520107459), INT32_C(-1787952693) },
      { INT32_C(-1096411985), INT32_C( 1818939186), INT32_C( 1520107459), INT32_C(-1787952693) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_set(test_vec[i].a[0], test_vec[i].a[1], test_vec[i].a[2], test_vec[i].a[3]);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_splat(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { INT32_C(  408003717),
      simde_em_int32x4_set(INT32_C(  408003717), INT32_C(  408003717), INT32_C(  408003717), INT32_C(  408003717)) },
    { INT32_C(-1301003433),
      simde_em_int32x4_set(INT32_C(-1301003433), INT32_C(-1301003433), INT32_C(-1301003433), INT32_C(-1301003433)) },
    { INT32_C(-1258097748),
      simde_em_int32x4_set(INT32_C(-1258097748), INT32_C(-1258097748), INT32_C(-1258097748), INT32_C(-1258097748)) },
    { INT32_C( -593002803),
      simde_em_int32x4_set(INT32_C( -593002803), INT32_C( -593002803), INT32_C( -593002803), INT32_C( -593002803)) },
    { INT32_C( -234816804),
      simde_em_int32x4_set(INT32_C( -234816804), INT32_C( -234816804), INT32_C( -234816804), INT32_C( -234816804)) },
    { INT32_C( 2091689241),
      simde_em_int32x4_set(INT32_C( 2091689241), INT32_C( 2091689241), INT32_C( 2091689241), INT32_C( 2091689241)) },
    { INT32_C( -250193710),
      simde_em_int32x4_set(INT32_C( -250193710), INT32_C( -250193710), INT32_C( -250193710), INT32_C( -250193710)) },
    { INT32_C(-2147113257),
      simde_em_int32x4_set(INT32_C(-2147113257), INT32_C(-2147113257), INT32_C(-2147113257), INT32_C(-2147113257)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_splat(test_vec[i].a);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_add(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C( -130054789), INT32_C( -401734081), INT32_C( 1269747402), INT32_C( -508892901)),
      simde_em_int32x4_set(INT32_C(  734233905), INT32_C( -878683482), INT32_C( 1174096883), INT32_C(-1544702640)),
      simde_em_int32x4_set(INT32_C(  604179116), INT32_C(-1280417563), INT32_C(-1851123011), INT32_C(-2053595541)) },
    { simde_em_int32x4_set(INT32_C( 1788993036), INT32_C( 2015130024), INT32_C(-1454134978), INT32_C( 1814399676)),
      simde_em_int32x4_set(INT32_C( -657913328), INT32_C(-1955918330), INT32_C( 1090706297), INT32_C( -241091274)),
      simde_em_int32x4_set(INT32_C( 1131079708), INT32_C(   59211694), INT32_C( -363428681), INT32_C( 1573308402)) },
    { simde_em_int32x4_set(INT32_C( -133951728), INT32_C(-1602274563), INT32_C(  813553307), INT32_C( -909785972)),
      simde_em_int32x4_set(INT32_C(  923795685), INT32_C(  188916954), INT32_C( 1558620902), INT32_C( -213941642)),
      simde_em_int32x4_set(INT32_C(  789843957), INT32_C(-1413357609), INT32_C(-1922793087), INT32_C(-1123727614)) },
    { simde_em_int32x4_set(INT32_C(   89193042), INT32_C( 1146928390), INT32_C(  228884520), INT32_C( -318784613)),
      simde_em_int32x4_set(INT32_C( -882737959), INT32_C(-1087386362), INT32_C(  647187678), INT32_C(-1024342776)),
      simde_em_int32x4_set(INT32_C( -793544917), INT32_C(   59542028), INT32_C(  876072198), INT32_C(-1343127389)) },
    { simde_em_int32x4_set(INT32_C(-1256057379), INT32_C(-1986030630), INT32_C(-1207245357), INT32_C( -900753160)),
      simde_em_int32x4_set(INT32_C(  295338101), INT32_C( 1938958840), INT32_C( -577851625), INT32_C(-1964292814)),
      simde_em_int32x4_set(INT32_C( -960719278), INT32_C(  -47071790), INT32_C(-1785096982), INT32_C( 1429921322)) },
    { simde_em_int32x4_set(INT32_C(-1836674315), INT32_C(  276208638), INT32_C( 1208429270), INT32_C(-2088893437)),
      simde_em_int32x4_set(INT32_C( -696286550), INT32_C( 1080546136), INT32_C( -464480723), INT32_C( 1763719828)),
      simde_em_int32x4_set(INT32_C( 1762006431), INT32_C( 1356754774), INT32_C(  743948547), INT32_C( -325173609)) },
    { simde_em_int32x4_set(INT32_C(-1784409930), INT32_C(  684654184), INT32_C(-1809625286), INT32_C( 1429970648)),
      simde_em_int32x4_set(INT32_C( 2144186007), INT32_C( 1898630377), INT32_C( 1398983174), INT32_C( -271810807)),
      simde_em_int32x4_set(INT32_C(  359776077), INT32_C(-1711682735), INT32_C( -410642112), INT32_C( 1158159841)) },
    { simde_em_int32x4_set(INT32_C( 1191160897), INT32_C( -508418983), INT32_C(  685454140), INT32_C(-1319802529)),
      simde_em_int32x4_set(INT32_C(  957908541), INT32_C( -382522768), INT32_C( 2102744472), INT32_C(-1526513662)),
      simde_em_int32x4_set(INT32_C(-2145897858), INT32_C( -890941751), INT32_C(-1506768684), INT32_C( 1448651105)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_add(test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_sub(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C( 1171034757), INT32_C( 1301599556), INT32_C(-1899411024), INT32_C(    1895820)),
      simde_em_int32x4_set(INT32_C( 1452423188), INT32_C(-1873896616), INT32_C(  219225954), INT32_C(-1496571263)),
      simde_em_int32x4_set(INT32_C( -281388431), INT32_C(-1119471124), INT32_C(-2118636978), INT32_C( 1498467083)) },
    { simde_em_int32x4_set(INT32_C(-1892767265), INT32_C( -758835286), INT32_C(-1965424001), INT32_C( 1186393509)),
      simde_em_int32x4_set(INT32_C(  930412480), INT32_C(-1507141936), INT32_C( 1371803635), INT32_C(  856145635)),
      simde_em_int32x4_set(INT32_C( 1471787551), INT32_C(  748306650), INT32_C(  957739660), INT32_C(  330247874)) },
    { simde_em_int32x4_set(INT32_C( -872156952), INT32_C(-1413825413), INT32_C( 2007885730), INT32_C( -395381350)),
      simde_em_int32x4_set(INT32_C( 1411707706), INT32_C(   72463335), INT32_C( -730931721), INT32_C( 2059992351)),
      simde_em_int32x4_set(INT32_C( 2011102638), INT32_C(-1486288748), INT32_C(-1556149845), INT32_C( 1839593595)) },
    { simde_em_int32x4_set(INT32_C( 2115626144), INT32_C( -315360303), INT32_C(   38470968), INT32_C( -280023022)),
      simde_em_int32x4_set(INT32_C(-1871186200), INT32_C( 2047425728), INT32_C(-2020529665), INT32_C( -923560291)),
      simde_em_int32x4_set(INT32_C( -308154952), INT32_C( 1932181265), INT32_C( 2059000633), INT32_C(  643537269)) },
    { simde_em_int32x4_set(INT32_C(  303010912), INT32_C( 1573848957), INT32_C(   53143155), INT32_C( -984600909)),
      simde_em_int32x4_set(INT32_C(  516264231), INT32_C(-1828880590), INT32_C( 1670486809), INT32_C( 1856062973)),
      simde_em_int32x4_set(INT32_C( -213253319), INT32_C( -892237749), INT32_C(-1617343654), INT32_C( 1454303414)) },
    { simde_em_int32x4_set(INT32_C( -879119083), INT32_C(-1163095336), INT32_C(  655734221), INT32_C( 1270016985)),
      simde_em_int32x4_set(INT32_C(  125997037), INT32_C( -102393225), INT32_C( 2055351476), INT32_C( 1591598034)),
      simde_em_int32x4_set(INT32_C(-1005116120), INT32_C(-1060702111), INT32_C(-1399617255), INT32_C( -321581049)) },
    { simde_em_int32x4_set(INT32_C(-1955519684), INT32_C(  526101249), INT32_C(-2004258965), INT32_C(  981184505)),
      simde_em_int32x4_set(INT32_C(  -55197038), INT32_C( -158449914), INT32_C( 1299340339), INT32_C( 1757148687)),
      simde_em_int32x4_set(INT32_C(-1900322646), INT32_C(  684551163), INT32_C(  991367992), INT32_C( -775964182)) },
    { simde_em_int32x4_set(INT32_C(-1972837826), INT32_C( 1806252159), INT32_C(  847393469), INT32_C(  848361403)),
      simde_em_int32x4_set(INT32_C(  849648236), INT32_C( -893962239), INT32_C( 1364936275), INT32_C( -971361447)),
      simde_em_int32x4_set(INT32_C( 1472481234), INT32_C(-1594752898), INT32_C( -517542806), INT32_C( 1819722850)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_sub(test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_mul(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C(-1560811561), INT32_C(-1403083270), INT32_C(     494198), INT32_C(-1161358910)),
      simde_em_int32x4_set(INT32_C(-2114570857), INT32_C(  -99146865), INT32_C( -119795904), INT32_C( -293405313)),
      simde_em_int32x4_set(INT32_C(-1831648559), INT32_C( 1191568550), INT32_C(-1066956928), INT32_C( -976058050)) },
    { simde_em_int32x4_set(INT32_C(-1946618876), INT32_C( -993132571), INT32_C(-1534046454), INT32_C(-1179602562)),
      simde_em_int32x4_set(INT32_C(-1502836051), INT32_C(-1946906427), INT32_C( -267806115), INT32_C( 1979587286)),
      simde_em_int32x4_set(INT32_C( 1417088692), INT32_C(-1883587783), INT32_C(-1085097310), INT32_C( -591451308)) },
    { simde_em_int32x4_set(INT32_C(-1173967818), INT32_C( -652266151), INT32_C( 1875904741), INT32_C(-1827831069)),
      simde_em_int32x4_set(INT32_C(  -43629496), INT32_C(-1465843629), INT32_C( -335477536), INT32_C( -534402209)),
      simde_em_int32x4_set(INT32_C(  321046320), INT32_C( 1511476187), INT32_C(  990927968), INT32_C(  591409981)) },
    { simde_em_int32x4_set(INT32_C(  349032241), INT32_C( -998863186), INT32_C( 2113943593), INT32_C(-1176290458)),
      simde_em_int32x4_set(INT32_C( 1172132624), INT32_C( 1693117938), INT32_C(  808440034), INT32_C( -892383455)),
      simde_em_int32x4_set(INT32_C(  425121296), INT32_C( -583666052), INT32_C( 1767498802), INT32_C(-1726406106)) },
    { simde_em_int32x4_set(INT32_C(-1116214467), INT32_C(-1007081170), INT32_C( 1661319406), INT32_C(   18487980)),
      simde_em_int32x4_set(INT32_C( -933286115), INT32_C( -603665234), INT32_C(  160922604), INT32_C( -475426202)),
      simde_em_int32x4_set(INT32_C( 1852365033), INT32_C( -320690876), INT32_C( 2072171880), INT32_C( 1932048520)) },
    { simde_em_int32x4_set(INT32_C(-1072914281), INT32_C( 1140050996), INT32_C(-2099106205), INT32_C(-1549697967)),
      simde_em_int32x4_set(INT32_C(  175366662), INT32_C(  724985897), INT32_C( -777257858), INT32_C(  586122419)),
      simde_em_int32x4_set(INT32_C(-1343876726), INT32_C(-1141320620), INT32_C( -534951750), INT32_C( 2141368483)) },
    { simde_em_int32x4_set(INT32_C( 1951386016), INT32_C( -773957576), INT32_C( 1446631235), INT32_C(-1582286610)),
      simde_em_int32x4_set(INT32_C( -301501293), INT32_C(   76332231), INT32_C( -581420062), INT32_C( 1682294414)),
      simde_em_int32x4_set(INT32_C(  881673952), INT32_C(-1958759544), INT32_C( 1236564518), INT32_C( 1273866244)) },
    { simde_em_int32x4_set(INT32_C(-2017022165), INT32_C(-1150642358), INT32_C(  442182040), INT32_C(  705579870)),
      simde_em_int32x4_set(INT32_C(  302298485), INT32_C(-2012578749), INT32_C(  -21687377), INT32_C( -433670233)),
      simde_em_int32x4_set(INT32_C( 1246983591), INT32_C( -418287522), INT32_C(   14661352), INT32_C( 1260870738)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_mul(test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_neg(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C(-2119394226), INT32_C(  789749198), INT32_C( -314946973), INT32_C(-1131060559)),
      simde_em_int32x4_set(INT32_C( 2119394226), INT32_C( -789749198), INT32_C(  314946973), INT32_C( 1131060559)) },
    { simde_em_int32x4_set(INT32_C( 1676628729), INT32_C( 1980772481), INT32_C(  843588474), INT32_C( -629532177)),
      simde_em_int32x4_set(INT32_C(-1676628729), INT32_C(-1980772481), INT32_C( -843588474), INT32_C(  629532177)) },
    { simde_em_int32x4_set(INT32_C(  314310243), INT32_C(-1991434040), INT32_C(-1014156958), INT32_C(-2067877043)),
      simde_em_int32x4_set(INT32_C( -314310243), INT32_C( 1991434040), INT32_C( 1014156958), INT32_C( 2067877043)) },
    { simde_em_int32x4_set(INT32_C( -705513988), INT32_C( -329115372), INT32_C( -562695311), INT32_C(  153674395)),
      simde_em_int32x4_set(INT32_C(  705513988), INT32_C(  329115372), INT32_C(  562695311), INT32_C( -153674395)) },
    { simde_em_int32x4_set(INT32_C( 1250132064), INT32_C( -809589594), INT32_C( 1567155766), INT32_C(    7686570)),
      simde_em_int32x4_set(INT32_C(-1250132064), INT32_C(  809589594), INT32_C(-1567155766), INT32_C(   -7686570)) },
    { simde_em_int32x4_set(INT32_C( -234734872), INT32_C(-1434217973), INT32_C( -983384476), INT32_C( 1310011772)),
      simde_em_int32x4_set(INT32_C(  234734872), INT32_C( 1434217973), INT32_C(  983384476), INT32_C(-1310011772)) },
    { simde_em_int32x4_set(INT32_C(  929211916), INT32_C( -607667571), INT32_C(  881370835), INT32_C( 1388655955)),
      simde_em_int32x4_set(INT32_C( -929211916), INT32_C(  607667571), INT32_C( -881370835), INT32_C(-1388655955)) },
    { simde_em_int32x4_set(INT32_C( -161496664), INT32_C(-1960127881), INT32_C(-1322054492), INT32_C(  197214141)),
      simde_em_int32x4_set(INT32_C(  161496664), INT32_C( 1960127881), INT32_C( 1322054492), INT32_C( -197214141)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_neg(test_vec[i].a);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_and(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C(-1944676286), INT32_C(  -36080688), INT32_C(   17224214), INT32_C( 1061095412)),
      simde_em_int32x4_set(INT32_C(-1311079230), INT32_C( 1927258725), INT32_C(  508469977), INT32_C(-1306267556)),
      simde_em_int32x4_set(INT32_C(-2146271166), INT32_C( 1893278272), INT32_C(     426512), INT32_C(  841154644)) },
    { simde_em_int32x4_set(INT32_C( 1697875404), INT32_C(-1572146468), INT32_C(-1360222112), INT32_C(  348191759)),
      simde_em_int32x4_set(INT32_C(  274882261), INT32_C( 1662557591), INT32_C(  397924109), INT32_C(-2126592829)),
      simde_em_int32x4_set(INT32_C(    2229444), INT32_C(  570986644), INT32_C(  111443968), INT32_C(      50179)) },
    { simde_em_int32x4_set(INT32_C(-1705179665), INT32_C(  397610263), INT32_C( -343568002), INT32_C(  179791034)),
      simde_em_int32x4_set(INT32_C( -227702514), INT32_C( -917769649), INT32_C(-1222946550), INT32_C( 1188294510)),
      simde_em_int32x4_set(INT32_C(-1840447218), INT32_C(   16973831), INT32_C(-1560211190), INT32_C(   43213866)) },
    { simde_em_int32x4_set(INT32_C( 1950893393), INT32_C( 2096517266), INT32_C(-1535391191), INT32_C(  117896683)),
      simde_em_int32x4_set(INT32_C( 1564493337), INT32_C( 2027662391), INT32_C(-1953835643), INT32_C(-1904129579)),
      simde_em_int32x4_set(INT32_C( 1413497873), INT32_C( 2027028498), INT32_C(-2146779135), INT32_C(  100680129)) },
    { simde_em_int32x4_set(INT32_C(-1148257439), INT32_C( 1048214398), INT32_C( -435334802), INT32_C(-1069672417)),
      simde_em_int32x4_set(INT32_C(  469777213), INT32_C( -875166656), INT32_C(  109731065), INT32_C(  713994968)),
      simde_em_int32x4_set(INT32_C(  402668321), INT32_C(  173146176), INT32_C(  101208168), INT32_C(     921624)) },
    { simde_em_int32x4_set(INT32_C( -331861652), INT32_C(-1089330721), INT32_C(-1237842359), INT32_C(  850466372)),
      simde_em_int32x4_set(INT32_C( 1030989647), INT32_C(-1975154292), INT32_C( -632774530), INT32_C( -920664314)),
      simde_em_int32x4_set(INT32_C(  741351756), INT32_C(-1979711092), INT32_C(-1844969400), INT32_C(    1115652)) },
    { simde_em_int32x4_set(INT32_C(  437523049), INT32_C( 1631291869), INT32_C( 1545912588), INT32_C( -613541384)),
      simde_em_int32x4_set(INT32_C(-1575915245), INT32_C(  544262506), INT32_C(-1784972599), INT32_C( 1278852786)),
      simde_em_int32x4_set(INT32_C(   34607105), INT32_C(  540051784), INT32_C(  335560712), INT32_C( 1210587312)) },
    { simde_em_int32x4_set(INT32_C(  802286343), INT32_C( -144055949), INT32_C( 1100536633), INT32_C( 1940491614)),
      simde_em_int32x4_set(INT32_C(-1512721196), INT32_C( -648374172), INT32_C(-1709998512), INT32_C(-1813185142)),
      simde_em_int32x4_set(INT32_C(  634494980), INT32_C( -783777696), INT32_C(    1071632), INT32_C(  329813258)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_and(test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_xor(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C(  210868924), INT32_C( 1005630024), INT32_C(-1503131968), INT32_C(-1649331060)),
      simde_em_int32x4_set(INT32_C(  636823718), INT32_C( 1334897918), INT32_C(  859513435), INT32_C( -847009083)),
      simde_em_int32x4_set(INT32_C(  694465050), INT32_C( 1952472758), INT32_C(-1789713253), INT32_C( 1345494601)) },
    { simde_em_int32x4_set(INT32_C(-1232813829), INT32_C(   85468281), INT32_C(  548857119), INT32_C( -458257280)),
      simde_em_int32x4_set(INT32_C(  356360074), INT32_C( -775901744), INT32_C( -193706742), INT32_C(-1268538041)),
      simde_em_int32x4_set(INT32_C(-1548132495), INT32_C( -724006487), INT32_C( -725442539), INT32_C( 1355557319)) },
    { simde_em_int32x4_set(INT32_C(-1565341507), INT32_C(-1898034534), INT32_C( 1762200922), INT32_C( 2010029621)),
      simde_em_int32x4_set(INT32_C(  461151037), INT32_C(  257672388), INT32_C( -915655139), INT32_C( 1322268597)),
      simde_em_int32x4_set(INT32_C(-1177660544), INT32_C(-2121953698), INT32_C(-1603978425), INT32_C(  958310784)) },
    { simde_em_int32x4_set(INT32_C( -660356766), INT32_C( -721684777), INT32_C( -267386408), INT32_C( 1048074506)),
      simde_em_int32x4_set(INT32_C( 1429727629), INT32_C(  633180018), INT32_C( 1133652494), INT32_C(  436246129)),
      simde_em_int32x4_set(INT32_C(-1919670033), INT32_C( -247039579), INT32_C(-1283314730), INT32_C(  611897211)) },
    { simde_em_int32x4_set(INT32_C(  552400717), INT32_C( 1079934376), INT32_C(-1843922237), INT32_C(  981494209)),
      simde_em_int32x4_set(INT32_C( -119621060), INT32_C( 1154103075), INT32_C(-1329531641), INT32_C( -683096589)),
      simde_em_int32x4_set(INT32_C( -667792015), INT32_C(   76827275), INT32_C(  584519620), INT32_C( -305615822)) },
    { simde_em_int32x4_set(INT32_C( -244106178), INT32_C(-1951440103), INT32_C( 1121924671), INT32_C( 1794916406)),
      simde_em_int32x4_set(INT32_C(-1742318852), INT32_C( 1993818008), INT32_C(  540959054), INT32_C(  513187346)),
      simde_em_int32x4_set(INT32_C( 1767206594), INT32_C(  -42443647), INT32_C( 1658935153), INT32_C( 1953160740)) },
    { simde_em_int32x4_set(INT32_C( -635279238), INT32_C(-1842414117), INT32_C( -199117055), INT32_C(  773300056)),
      simde_em_int32x4_set(INT32_C(-1437863211), INT32_C(-1206482895), INT32_C( -764476590), INT32_C( 1652821317)),
      simde_em_int32x4_set(INT32_C( 1885969071), INT32_C(  708343274), INT32_C(  642692179), INT32_C( 1284739613)) },
    { simde_em_int32x4_set(INT32_C( -444530452), INT32_C( -252535784), INT32_C( 2117046163), INT32_C( 1621549094)),
      simde_em_int32x4_set(INT32_C(-1172819657), INT32_C(-1314376744), INT32_C(-1790795998), INT32_C(-1411705733)),
      simde_em_int32x4_set(INT32_C( 1603875291), INT32_C( 1096462272), INT32_C( -345173839), INT32_C( -880937891)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_xor(test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_or(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C(  612634458), INT32_C( -859004355), INT32_C(   59160418), INT32_C(-1213765045)),
      simde_em_int32x4_set(INT32_C(  241477088), INT32_C(  208660520), INT32_C( 1642879984), INT32_C( 1523517968)),
      simde_em_int32x4_set(INT32_C(  786739194), INT32_C( -856692163), INT32_C( 1676607474), INT32_C(   -1086885)) },
    { simde_em_int32x4_set(INT32_C(-1510430166), INT32_C( -908332341), INT32_C(  886684575), INT32_C( 1263076634)),
      simde_em_int32x4_set(INT32_C(  815832058), INT32_C(  285914535), INT32_C( 1676910387), INT32_C(-1118236151)),
      simde_em_int32x4_set(INT32_C(-1241990150), INT32_C( -639895569), INT32_C( 2012987327), INT32_C(  -10938597)) },
    { simde_em_int32x4_set(INT32_C( 2111675849), INT32_C(-2071816822), INT32_C( 1696695924), INT32_C(-1577562872)),
      simde_em_int32x4_set(INT32_C( -104074462), INT32_C(  708400741), INT32_C(-1689045440), INT32_C( -979241437)),
      simde_em_int32x4_set(INT32_C(  -35651605), INT32_C(-1363421201), INT32_C(   -9193868), INT32_C( -436601045)) },
    { simde_em_int32x4_set(INT32_C( 1997721777), INT32_C(  179181832), INT32_C(-1598754518), INT32_C(  515576405)),
      simde_em_int32x4_set(INT32_C(-2121665287), INT32_C( 2071885406), INT32_C( 1385923539), INT32_C( 1835211431)),
      simde_em_int32x4_set(INT32_C( -140774151), INT32_C( 2080276318), INT32_C( -222301189), INT32_C( 2147162871)) },
    { simde_em_int32x4_set(INT32_C(-2059816495), INT32_C(-2141383366), INT32_C( -457795320), INT32_C( 1606714318)),
      simde_em_int32x4_set(INT32_C(-1399740547), INT32_C( 1240134726), INT32_C(   75457251), INT32_C(-1616974208)),
      simde_em_int32x4_set(INT32_C(-1380337667), INT32_C( -905972354), INT32_C( -452985877), INT32_C( -539037746)) },
    { simde_em_int32x4_set(INT32_C( 1817679142), INT32_C(-1083433063), INT32_C( 1018384959), INT32_C(-1220425481)),
      simde_em_int32x4_set(INT32_C(  620883526), INT32_C(-1804830209), INT32_C( -274690695), INT32_C(-1870059968)),
      simde_em_int32x4_set(INT32_C( 1834483558), INT32_C(-1083408385), INT32_C(   -4989057), INT32_C(-1211502857)) },
    { simde_em_int32x4_set(INT32_C( 1219714983), INT32_C( -612107397), INT32_C(-1313313001), INT32_C(  239780973)),
      simde_em_int32x4_set(INT32_C(  600599829), INT32_C(  900272730), INT32_C(  435673003), INT32_C( 2078792716)),
      simde_em_int32x4_set(INT32_C( 1811906487), INT32_C(   -5506181), INT32_C(-1174405185), INT32_C( 2146425965)) },
    { simde_em_int32x4_set(INT32_C(  166802073), INT32_C( -563853411), INT32_C(  503422173), INT32_C(-1286881861)),
      simde_em_int32x4_set(INT32_C(  976470397), INT32_C(   29604222), INT32_C(  831596085), INT32_C( 1847732190)),
      simde_em_int32x4_set(INT32_C( 1005843453), INT32_C( -538443777), INT32_C( 1066516221), INT32_C(   -9715713)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_or(test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_not(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C( 1505760985), INT32_C( 1390822226), INT32_C(   30759388), INT32_C( 1731963796)),
      simde_em_int32x4_set(INT32_C(-1505760986), INT32_C(-1390822227), INT32_C(  -30759389), INT32_C(-1731963797)) },
    { simde_em_int32x4_set(INT32_C(-1850431043), INT32_C( -976761722), INT32_C( 2118758360), INT32_C( 1017388403)),
      simde_em_int32x4_set(INT32_C( 1850431042), INT32_C(  976761721), INT32_C(-2118758361), INT32_C(-1017388404)) },
    { simde_em_int32x4_set(INT32_C(-1126551480), INT32_C(  128410428), INT32_C(  233069974), INT32_C(-1388756245)),
      simde_em_int32x4_set(INT32_C( 1126551479), INT32_C( -128410429), INT32_C( -233069975), INT32_C( 1388756244)) },
    { simde_em_int32x4_set(INT32_C( -540291506), INT32_C(-1752278563), INT32_C(-1570332542), INT32_C(  523975081)),
      simde_em_int32x4_set(INT32_C(  540291505), INT32_C( 1752278562), INT32_C( 1570332541), INT32_C( -523975082)) },
    { simde_em_int32x4_set(INT32_C(-1388487580), INT32_C( 1924801847), INT32_C(  788035944), INT32_C(  594079074)),
      simde_em_int32x4_set(INT32_C( 1388487579), INT32_C(-1924801848), INT32_C( -788035945), INT32_C( -594079075)) },
    { simde_em_int32x4_set(INT32_C(  706062732), INT32_C(-1031470908), INT32_C( 1531233047), INT32_C(   54437932)),
      simde_em_int32x4_set(INT32_C( -706062733), INT32_C( 1031470907), INT32_C(-1531233048), INT32_C(  -54437933)) },
    { simde_em_int32x4_set(INT32_C( 1156708076), INT32_C(-1339483913), INT32_C( -345112269), INT32_C( 1973870097)),
      simde_em_int32x4_set(INT32_C(-1156708077), INT32_C( 1339483912), INT32_C(  345112268), INT32_C(-1973870098)) },
    { simde_em_int32x4_set(INT32_C(  758342222), INT32_C( -520430797), INT32_C( -191576597), INT32_C(-1264920102)),
      simde_em_int32x4_set(INT32_C( -758342223), INT32_C(  520430796), INT32_C(  191576596), INT32_C( 1264920101)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_not(test_vec[i].a);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_lessThan(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_bool32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C( 1092235822), INT32_C(  521896959), INT32_C(-1981216208), INT32_C(  280312298)),
      simde_em_int32x4_set(INT32_C( -268700853), INT32_C( 1174997007), INT32_C(  917950565), INT32_C( -552664038)),
      simde_x_em_bool32x4_set(0, 1, 1, 0) },
    { simde_em_int32x4_set(INT32_C( 1570417678), INT32_C( -291609988), INT32_C( 1483442540), INT32_C(  688786664)),
      simde_em_int32x4_set(INT32_C( 1385628029), INT32_C( 1321858834), INT32_C(-2132734277), INT32_C(  688786664)),
      simde_x_em_bool32x4_set(0, 1, 0, 0) },
    { simde_em_int32x4_set(INT32_C(-1900061626), INT32_C(-1276264837), INT32_C( -230456444), INT32_C( 1675702898)),
      simde_em_int32x4_set(INT32_C(-1900061626), INT32_C(-1220766127), INT32_C( -230456444), INT32_C(-1639786335)),
      simde_x_em_bool32x4_set(0, 1, 0, 0) },
    { simde_em_int32x4_set(INT32_C(-1468687815), INT32_C(  557119643), INT32_C(-1592862231), INT32_C(  604354765)),
      simde_em_int32x4_set(INT32_C(-1468687815), INT32_C(  704070555), INT32_C(-1592862231), INT32_C( 1091598294)),
      simde_x_em_bool32x4_set(0, 1, 0, 1) },
    { simde_em_int32x4_set(INT32_C(  155138017), INT32_C( -670968615), INT32_C(  678414942), INT32_C(  856166385)),
      simde_em_int32x4_set(INT32_C(-1840590067), INT32_C(-1278708738), INT32_C(  678414942), INT32_C(-1279068837)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) },
    { simde_em_int32x4_set(INT32_C(  241532853), INT32_C( -351418851), INT32_C(-1136073875), INT32_C( 1446720271)),
      simde_em_int32x4_set(INT32_C(  241532853), INT32_C( -351418851), INT32_C(-1136073875), INT32_C( 1446720271)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) },
    { simde_em_int32x4_set(INT32_C( -538700709), INT32_C(  239630400), INT32_C(  745020446), INT32_C( -681088560)),
      simde_em_int32x4_set(INT32_C( -538700709), INT32_C(  239630400), INT32_C(  745020446), INT32_C( -681088560)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) },
    { simde_em_int32x4_set(INT32_C(-1102325832), INT32_C( 1667870885), INT32_C( -295329958), INT32_C(-1235440046)),
      simde_em_int32x4_set(INT32_C(-1342911133), INT32_C( 1667870885), INT32_C( -295329958), INT32_C(-1235440046)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_bool32x4 r = simde_em_int32x4_lessThan(test_vec[i].a, test_vec[i].b);
    simde_assert_bool32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_lessThanOrEqual(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_bool32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C( 1289601731), INT32_C( -319721605), INT32_C(-2026535782), INT32_C( 1282313245)),
      simde_em_int32x4_set(INT32_C(-1723028259), INT32_C( -112809512), INT32_C( 1965337511), INT32_C( 1239822517)),
      simde_x_em_bool32x4_set(0, 1, 1, 0) },
    { simde_em_int32x4_set(INT32_C(  123833593), INT32_C( 1602399090), INT32_C( 1625557702), INT32_C(  600173843)),
      simde_em_int32x4_set(INT32_C(  123833593), INT32_C(-1958718101), INT32_C(-1995230831), INT32_C(  600173843)),
      simde_x_em_bool32x4_set(1, 0, 0, 1) },
    { simde_em_int32x4_set(INT32_C( -340856936), INT32_C( 1830512609), INT32_C(  954520830), INT32_C( 1460150271)),
      simde_em_int32x4_set(INT32_C( -340856936), INT32_C( 1830512609), INT32_C(  954520830), INT32_C( -918157795)),
      simde_x_em_bool32x4_set(1, 1, 1, 0) },
    { simde_em_int32x4_set(INT32_C( 1646319550), INT32_C( -935150855), INT32_C( -423241529), INT32_C( 1101255164)),
      simde_em_int32x4_set(INT32_C(-1488408298), INT32_C( -935150855), INT32_C( -423241529), INT32_C( 1264655494)),
      simde_x_em_bool32x4_set(0, 1, 1, 1) },
    { simde_em_int32x4_set(INT32_C(  513540727), INT32_C( 1863776688), INT32_C( -269321526), INT32_C( 1869155167)),
      simde_em_int32x4_set(INT32_C(  105918018), INT32_C(  468079464), INT32_C( -269321526), INT32_C( 1869155167)),
      simde_x_em_bool32x4_set(0, 0, 1, 1) },
    { simde_em_int32x4_set(INT32_C(-1133169873), INT32_C( 1319816148), INT32_C(-1258819419), INT32_C(-1489489160)),
      simde_em_int32x4_set(INT32_C(-1133169873), INT32_C( 1319816148), INT32_C( -768006835), INT32_C( -545767272)),
      simde_x_em_bool32x4_set(1, 1, 1, 1) },
    { simde_em_int32x4_set(INT32_C( -822356440), INT32_C( -925640620), INT32_C(  733710692), INT32_C( 1720909009)),
      simde_em_int32x4_set(INT32_C( -822356440), INT32_C( -925640620), INT32_C( 1630517743), INT32_C( 1720909009)),
      simde_x_em_bool32x4_set(1, 1, 1, 1) },
    { simde_em_int32x4_set(INT32_C( 1349800668), INT32_C(  341848254), INT32_C( -142248995), INT32_C(  940764224)),
      simde_em_int32x4_set(INT32_C( 1349800668), INT32_C(-1389524007), INT32_C( -142248995), INT32_C(-1258821746)),
      simde_x_em_bool32x4_set(1, 0, 1, 0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_bool32x4 r = simde_em_int32x4_lessThanOrEqual(test_vec[i].a, test_vec[i].b);
    simde_assert_bool32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_greaterThan(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_bool32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C(  -29498040), INT32_C( 1459262127), INT32_C( -675662853), INT32_C(-2044735394)),
      simde_em_int32x4_set(INT32_C(  -29498040), INT32_C( 1459262127), INT32_C(-1329246615), INT32_C( 1823845153)),
      simde_x_em_bool32x4_set(0, 0, 1, 0) },
    { simde_em_int32x4_set(INT32_C( 1427187246), INT32_C(  638935870), INT32_C(  124311015), INT32_C(  171977902)),
      simde_em_int32x4_set(INT32_C( 1427187246), INT32_C(-1040744365), INT32_C(  407281094), INT32_C(  171977902)),
      simde_x_em_bool32x4_set(0, 1, 0, 0) },
    { simde_em_int32x4_set(INT32_C(-1395165916), INT32_C(  999416415), INT32_C( 1618702498), INT32_C( 1350247618)),
      simde_em_int32x4_set(INT32_C(-1395165916), INT32_C(  999416415), INT32_C( 1618702498), INT32_C( 1350247618)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) },
    { simde_em_int32x4_set(INT32_C(-1460887903), INT32_C(-1143610913), INT32_C(  901697834), INT32_C(-1971531475)),
      simde_em_int32x4_set(INT32_C(-1460887903), INT32_C(-1143610913), INT32_C(  901697834), INT32_C(-1690144073)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) },
    { simde_em_int32x4_set(INT32_C(-1558574432), INT32_C( 1323309990), INT32_C(  -37597193), INT32_C( 1190337199)),
      simde_em_int32x4_set(INT32_C(-1558574432), INT32_C( 1323309990), INT32_C(-1773182197), INT32_C(  186150571)),
      simde_x_em_bool32x4_set(0, 0, 1, 1) },
    { simde_em_int32x4_set(INT32_C(-1507511311), INT32_C(-1895370705), INT32_C( 2003373997), INT32_C(  286615577)),
      simde_em_int32x4_set(INT32_C(-1435538628), INT32_C( 1348305969), INT32_C(-1733416914), INT32_C( 1903510077)),
      simde_x_em_bool32x4_set(0, 0, 1, 0) },
    { simde_em_int32x4_set(INT32_C(  755982467), INT32_C(  -29017187), INT32_C(-1072374315), INT32_C( -228735545)),
      simde_em_int32x4_set(INT32_C(-1366677914), INT32_C( 1771443494), INT32_C(-2121722468), INT32_C( 1320421661)),
      simde_x_em_bool32x4_set(1, 0, 1, 0) },
    { simde_em_int32x4_set(INT32_C( -592977517), INT32_C( 1678140927), INT32_C( -651542780), INT32_C(-1409304847)),
      simde_em_int32x4_set(INT32_C( -592977517), INT32_C(-1042471500), INT32_C( -736963286), INT32_C(-1409304847)),
      simde_x_em_bool32x4_set(0, 1, 1, 0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_bool32x4 r = simde_em_int32x4_greaterThan(test_vec[i].a, test_vec[i].b);
    simde_assert_bool32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_greaterThanOrEqual(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_bool32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C( -977439411), INT32_C( 1816011069), INT32_C(-2086020825), INT32_C( -756430953)),
      simde_em_int32x4_set(INT32_C(-1926804724), INT32_C(-2032842472), INT32_C(-2086020825), INT32_C( -102553847)),
      simde_x_em_bool32x4_set(1, 1, 1, 0) },
    { simde_em_int32x4_set(INT32_C( -768689307), INT32_C( -482913265), INT32_C( 1797131902), INT32_C( 1553125525)),
      simde_em_int32x4_set(INT32_C( 1568295540), INT32_C( -374276567), INT32_C( 1797131902), INT32_C(  -62317034)),
      simde_x_em_bool32x4_set(0, 0, 1, 1) },
    { simde_em_int32x4_set(INT32_C( -133169533), INT32_C(  965245165), INT32_C(  852487122), INT32_C( 1800483902)),
      simde_em_int32x4_set(INT32_C(  933136894), INT32_C( 1651516201), INT32_C(  852487122), INT32_C( 1800483902)),
      simde_x_em_bool32x4_set(0, 0, 1, 1) },
    { simde_em_int32x4_set(INT32_C(  -36998047), INT32_C( -370494853), INT32_C(  714180183), INT32_C(-1528854787)),
      simde_em_int32x4_set(INT32_C(  -36998047), INT32_C(-1058061314), INT32_C(  714180183), INT32_C( 1308978950)),
      simde_x_em_bool32x4_set(1, 1, 1, 0) },
    { simde_em_int32x4_set(INT32_C(-1744057326), INT32_C( -639013406), INT32_C(-1876714050), INT32_C( -503613740)),
      simde_em_int32x4_set(INT32_C(  263839779), INT32_C(-2058081093), INT32_C(-1876714050), INT32_C( 2147330293)),
      simde_x_em_bool32x4_set(0, 1, 1, 0) },
    { simde_em_int32x4_set(INT32_C(-1728179588), INT32_C(-1589063271), INT32_C(-2026642495), INT32_C(-1293583884)),
      simde_em_int32x4_set(INT32_C(-1728179588), INT32_C(-1589063271), INT32_C( -544212143), INT32_C(-1293583884)),
      simde_x_em_bool32x4_set(1, 1, 0, 1) },
    { simde_em_int32x4_set(INT32_C(-1309852415), INT32_C( 2033357852), INT32_C(-2074842674), INT32_C(  492079640)),
      simde_em_int32x4_set(INT32_C( 1928722545), INT32_C( 2061774195), INT32_C(-1417705102), INT32_C(  492079640)),
      simde_x_em_bool32x4_set(0, 0, 0, 1) },
    { simde_em_int32x4_set(INT32_C( 1967494154), INT32_C(  643204272), INT32_C(   82085871), INT32_C( 1395279597)),
      simde_em_int32x4_set(INT32_C(-1276351410), INT32_C( -951234377), INT32_C(   82085871), INT32_C( 1626425357)),
      simde_x_em_bool32x4_set(1, 1, 1, 0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_bool32x4 r = simde_em_int32x4_greaterThanOrEqual(test_vec[i].a, test_vec[i].b);
    simde_assert_bool32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_equal(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_bool32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C(-1154265497), INT32_C(-1143780182), INT32_C(  834953698), INT32_C(-1612230697)),
      simde_em_int32x4_set(INT32_C( 1547151816), INT32_C(-1143780182), INT32_C(  834953698), INT32_C( -387108199)),
      simde_x_em_bool32x4_set(0, 1, 1, 0) },
    { simde_em_int32x4_set(INT32_C( -372275148), INT32_C(-1674496556), INT32_C( -492399347), INT32_C( 2048414074)),
      simde_em_int32x4_set(INT32_C( -550139593), INT32_C( -511437417), INT32_C( 1402557526), INT32_C( 2048414074)),
      simde_x_em_bool32x4_set(0, 0, 0, 1) },
    { simde_em_int32x4_set(INT32_C(-1697331709), INT32_C(   20952961), INT32_C( 2043787411), INT32_C(-1302618105)),
      simde_em_int32x4_set(INT32_C(-1697331709), INT32_C(   20952961), INT32_C( -153195942), INT32_C(-1302618105)),
      simde_x_em_bool32x4_set(1, 1, 0, 1) },
    { simde_em_int32x4_set(INT32_C(-1095168578), INT32_C(  724082866), INT32_C( 1102805107), INT32_C( -861519320)),
      simde_em_int32x4_set(INT32_C(-1095168578), INT32_C(  724082866), INT32_C(  156901222), INT32_C( -861519320)),
      simde_x_em_bool32x4_set(1, 1, 0, 1) },
    { simde_em_int32x4_set(INT32_C( 2052964815), INT32_C( 2024364879), INT32_C(-1703129164), INT32_C(-1307982520)),
      simde_em_int32x4_set(INT32_C(  906217315), INT32_C( 1275813007), INT32_C(  668333861), INT32_C(-1307982520)),
      simde_x_em_bool32x4_set(0, 0, 0, 1) },
    { simde_em_int32x4_set(INT32_C(-1728140179), INT32_C(  205269311), INT32_C(   57352691), INT32_C(  721231702)),
      simde_em_int32x4_set(INT32_C(  -34993881), INT32_C(  205269311), INT32_C(  989184594), INT32_C(  721231702)),
      simde_x_em_bool32x4_set(0, 1, 0, 1) },
    { simde_em_int32x4_set(INT32_C(  745740475), INT32_C( -157134540), INT32_C( -880430869), INT32_C( 1148789626)),
      simde_em_int32x4_set(INT32_C( 1258486780), INT32_C( -157134540), INT32_C( -986599826), INT32_C( 1148789626)),
      simde_x_em_bool32x4_set(0, 1, 0, 1) },
    { simde_em_int32x4_set(INT32_C( -288110265), INT32_C(  809162443), INT32_C(   52634501), INT32_C(-1005509632)),
      simde_em_int32x4_set(INT32_C(-1649833187), INT32_C(  236732201), INT32_C( 1617700013), INT32_C(-1005509632)),
      simde_x_em_bool32x4_set(0, 0, 0, 1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_bool32x4 r = simde_em_int32x4_equal(test_vec[i].a, test_vec[i].b);
    simde_assert_bool32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_notEqual(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_bool32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C(-1388116334), INT32_C(-1698067227), INT32_C(  339237999), INT32_C( -493017317)),
      simde_em_int32x4_set(INT32_C(-1388116334), INT32_C(-1698067227), INT32_C(  339237999), INT32_C( -493017317)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) },
    { simde_em_int32x4_set(INT32_C( 1352723249), INT32_C(-1569649155), INT32_C( -374713803), INT32_C(-1448811026)),
      simde_em_int32x4_set(INT32_C( 1352723249), INT32_C(-1569649155), INT32_C( -374713803), INT32_C(  233337211)),
      simde_x_em_bool32x4_set(0, 0, 0, 1) },
    { simde_em_int32x4_set(INT32_C(-1732488007), INT32_C( 1642175213), INT32_C(-1232887679), INT32_C( 1499392289)),
      simde_em_int32x4_set(INT32_C( -922053912), INT32_C( 1643017273), INT32_C( -774139582), INT32_C( 1869870552)),
      simde_x_em_bool32x4_set(1, 1, 1, 1) },
    { simde_em_int32x4_set(INT32_C( 2018660388), INT32_C(-1421749600), INT32_C(   30849066), INT32_C(   86646558)),
      simde_em_int32x4_set(INT32_C(-2108270740), INT32_C(-1421749600), INT32_C(  -23883672), INT32_C(   86646558)),
      simde_x_em_bool32x4_set(1, 0, 1, 0) },
    { simde_em_int32x4_set(INT32_C( -704673215), INT32_C(-1807567806), INT32_C( -739466479), INT32_C(-2115910792)),
      simde_em_int32x4_set(INT32_C( -704673215), INT32_C( 1145449558), INT32_C( -739466479), INT32_C(-2115910792)),
      simde_x_em_bool32x4_set(0, 1, 0, 0) },
    { simde_em_int32x4_set(INT32_C(  461369666), INT32_C(-1753520638), INT32_C(  846820471), INT32_C( 1643109857)),
      simde_em_int32x4_set(INT32_C(-1309100533), INT32_C(-1753520638), INT32_C( -192834650), INT32_C(-1328760352)),
      simde_x_em_bool32x4_set(1, 0, 1, 1) },
    { simde_em_int32x4_set(INT32_C( -735856300), INT32_C(-1663037738), INT32_C(-1468766368), INT32_C(  963867224)),
      simde_em_int32x4_set(INT32_C( -735856300), INT32_C(-1663037738), INT32_C(-1468766368), INT32_C(  992110576)),
      simde_x_em_bool32x4_set(0, 0, 0, 1) },
    { simde_em_int32x4_set(INT32_C( 1719239506), INT32_C( 1966320088), INT32_C(-1161114937), INT32_C(  -38315074)),
      simde_em_int32x4_set(INT32_C( -824909939), INT32_C( 2124693919), INT32_C(-1161114937), INT32_C(  -38315074)),
      simde_x_em_bool32x4_set(1, 1, 0, 0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_bool32x4 r = simde_em_int32x4_notEqual(test_vec[i].a, test_vec[i].b);
    simde_assert_bool32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_anyTrue(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_bool32x4 r;
  } test_vec[] = {
    { simde_em_int32x4_set(INT32_C(          0), INT32_C(-1642209200), INT32_C(          0), INT32_C(          0)),
      simde_x_em_bool32x4_set(1, 1, 1, 1) },
    { simde_em_int32x4_set(INT32_C(-1464498813), INT32_C( -646874599), INT32_C(          0), INT32_C(-1658432920)),
      simde_x_em_bool32x4_set(1, 1, 1, 1) },
    { simde_em_int32x4_set(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) },
    { simde_em_int32x4_set(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(  282476292)),
      simde_x_em_bool32x4_set(1, 1, 1, 1) },
    { simde_em_int32x4_set(INT32_C( -142013167), INT32_C( -332185942), INT32_C(          0), INT32_C(          0)),
      simde_x_em_bool32x4_set(1, 1, 1, 1) },
    { simde_em_int32x4_set(INT32_C(          0), INT32_C(          0), INT32_C(-1995834622), INT32_C(-1115654080)),
      simde_x_em_bool32x4_set(1, 1, 1, 1) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_bool32x4 r = simde_em_int32x4_anyTrue(test_vec[i].a);
    simde_assert_bool32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_allTrue(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_bool32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C( 1924755501), INT32_C(-1487094809), INT32_C(          0), INT32_C(          0)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) },
    { simde_em_int32x4_set(INT32_C(-1563852499), INT32_C(          0), INT32_C(-1164461569), INT32_C(          0)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) },
    { simde_em_int32x4_set(INT32_C(  166325311), INT32_C( -663110561), INT32_C( 1779011063), INT32_C( -851266434)),
      simde_x_em_bool32x4_set(1, 1, 1, 1) },
    { simde_em_int32x4_set(INT32_C(  381345185), INT32_C(-1082961579), INT32_C(          0), INT32_C(          0)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) },
    { simde_em_int32x4_set(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) },
    { simde_em_int32x4_set(INT32_C(-1600691899), INT32_C(          0), INT32_C(          0), INT32_C(          0)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) },
    { simde_em_int32x4_set(INT32_C( 1542884964), INT32_C(          0), INT32_C( 1150791959), INT32_C(          0)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) },
    { simde_em_int32x4_set(INT32_C(  990770967), INT32_C(  776141755), INT32_C(    -506037), INT32_C(          0)),
      simde_x_em_bool32x4_set(0, 0, 0, 0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_bool32x4 r = simde_em_int32x4_allTrue(test_vec[i].a);
    simde_assert_bool32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_select(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_bool32x4 s;
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_x_em_bool32x4_set(1, 1, 0, 0),
      simde_em_int32x4_set(INT32_C( 1901257370), INT32_C(  967768475), INT32_C(-1337551580), INT32_C(  505988701)),
      simde_em_int32x4_set(INT32_C( 1712719998), INT32_C(-1607451780), INT32_C(-1357072628), INT32_C( 1679364714)),
      simde_em_int32x4_set(INT32_C( 1901257370), INT32_C(  967768475), INT32_C(-1357072628), INT32_C( 1679364714)) },
    { simde_x_em_bool32x4_set(0, 1, 0, 1),
      simde_em_int32x4_set(INT32_C( 1236094408), INT32_C( -820540649), INT32_C( -859459180), INT32_C( -113608291)),
      simde_em_int32x4_set(INT32_C( 2084503524), INT32_C( -158126085), INT32_C( -511769031), INT32_C( 1638707875)),
      simde_em_int32x4_set(INT32_C( 2084503524), INT32_C( -820540649), INT32_C( -511769031), INT32_C( -113608291)) },
    { simde_x_em_bool32x4_set(0, 1, 0, 1),
      simde_em_int32x4_set(INT32_C( -252463302), INT32_C(  918402397), INT32_C(-1349892770), INT32_C( 1898327572)),
      simde_em_int32x4_set(INT32_C(-1222569841), INT32_C(   98389388), INT32_C( 1625326455), INT32_C( -588464704)),
      simde_em_int32x4_set(INT32_C(-1222569841), INT32_C(  918402397), INT32_C( 1625326455), INT32_C( 1898327572)) },
    { simde_x_em_bool32x4_set(0, 0, 0, 0),
      simde_em_int32x4_set(INT32_C(-1202082781), INT32_C( 1538500407), INT32_C( -461926721), INT32_C(-1185757745)),
      simde_em_int32x4_set(INT32_C(  267080363), INT32_C(  850100401), INT32_C( -741005798), INT32_C(  452308867)),
      simde_em_int32x4_set(INT32_C(  267080363), INT32_C(  850100401), INT32_C( -741005798), INT32_C(  452308867)) },
    { simde_x_em_bool32x4_set(1, 1, 0, 0),
      simde_em_int32x4_set(INT32_C( 1326871517), INT32_C( -619941226), INT32_C(-1598698361), INT32_C( 1801486108)),
      simde_em_int32x4_set(INT32_C(  418228221), INT32_C( -663994478), INT32_C( 1727401646), INT32_C(-1146131637)),
      simde_em_int32x4_set(INT32_C( 1326871517), INT32_C( -619941226), INT32_C( 1727401646), INT32_C(-1146131637)) },
    { simde_x_em_bool32x4_set(1, 0, 0, 1),
      simde_em_int32x4_set(INT32_C(-1124598595), INT32_C(  -57506955), INT32_C( 1712054782), INT32_C(-1283930574)),
      simde_em_int32x4_set(INT32_C( 2131324626), INT32_C(-1181534261), INT32_C(-1703630560), INT32_C(-1534567034)),
      simde_em_int32x4_set(INT32_C(-1124598595), INT32_C(-1181534261), INT32_C(-1703630560), INT32_C(-1283930574)) },
    { simde_x_em_bool32x4_set(0, 1, 0, 1),
      simde_em_int32x4_set(INT32_C( 1402723002), INT32_C( 1091950284), INT32_C(  265102102), INT32_C(-1418464151)),
      simde_em_int32x4_set(INT32_C(  377113974), INT32_C(  302949443), INT32_C( 2080295339), INT32_C(-1608540278)),
      simde_em_int32x4_set(INT32_C(  377113974), INT32_C( 1091950284), INT32_C( 2080295339), INT32_C(-1418464151)) },
    { simde_x_em_bool32x4_set(1, 1, 1, 0),
      simde_em_int32x4_set(INT32_C(  -65887108), INT32_C(  686572110), INT32_C(-2109295094), INT32_C( -924341975)),
      simde_em_int32x4_set(INT32_C(  104394633), INT32_C( -797264894), INT32_C( 1571485842), INT32_C( 1036654717)),
      simde_em_int32x4_set(INT32_C(  -65887108), INT32_C(  686572110), INT32_C(-2109295094), INT32_C( 1036654717)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_select(test_vec[i].s, test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_shiftLeftByScalar(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    int b;
    simde_em_int32x4 r;
  } test_vec[] = {
    { simde_em_int32x4_set(INT32_C(-1154265497), INT32_C(-1143780182), INT32_C(  834953698), INT32_C(-1612230697)), 23,
      simde_em_int32x4_set(INT32_C(  864026624), INT32_C( 1426063360), INT32_C( -251658240), INT32_C( -343932928)) },
    { simde_em_int32x4_set(INT32_C( 1547151816), INT32_C( -539465004), INT32_C(  489904522), INT32_C( -368859633)), 25,
      simde_em_int32x4_set(INT32_C(-1879048192), INT32_C(-1476395008), INT32_C(  335544320), INT32_C(  503316480)) },
    { simde_em_int32x4_set(INT32_C( -372275148), INT32_C(-1674496556), INT32_C( -492399347), INT32_C( 2048414074)), 31,
      simde_em_int32x4_set(INT32_C(          0), INT32_C(          0), INT32_C(-2147483648), INT32_C(          0)) },
    { simde_em_int32x4_set(INT32_C( -550139593), INT32_C( -884298505), INT32_C( -511437417), INT32_C(-1575352639)), 22,
      simde_em_int32x4_set(INT32_C( 1304428544), INT32_C( 1035993088), INT32_C( 1707081728), INT32_C(-1337982976)) },
    { simde_em_int32x4_set(INT32_C(  428403412), INT32_C(-1697331709), INT32_C(   20952961), INT32_C( 2043787411)), 7,
      simde_em_int32x4_set(INT32_C( -998938112), INT32_C( 1784873344), INT32_C(-1612988288), INT32_C( -388216448)) },
    { simde_em_int32x4_set(INT32_C(  803984386), INT32_C(-1460405562), INT32_C(-1455987963), INT32_C( -153195942)), 6,
      simde_em_int32x4_set(INT32_C(  -84606848), INT32_C( 1023324544), INT32_C( 1306050880), INT32_C(-1214605696)) },
    { simde_em_int32x4_set(INT32_C(-1095168578), INT32_C(  724082866), INT32_C( 1102805107), INT32_C( -861519320)), 6,
      simde_em_int32x4_set(INT32_C(-1371312256), INT32_C( -903336832), INT32_C( 1860050112), INT32_C(  697338368)) },
    { simde_em_int32x4_set(INT32_C(  113376994), INT32_C(  -98914073), INT32_C(  156901222), INT32_C(  -13150024)), 15,
      simde_em_int32x4_set(INT32_C(   -9371648), INT32_C( 1483964416), INT32_C(  263389184), INT32_C(-1403256832)) },
    { simde_em_int32x4_set(INT32_C(-2042086230), INT32_C( 1618101753), INT32_C( 1378251684), INT32_C( 1647528488)), 0,
      simde_em_int32x4_set(INT32_C(-2042086230), INT32_C( 1618101753), INT32_C( 1378251684), INT32_C( 1647528488)) },
    { simde_em_int32x4_set(INT32_C(  -86406734), INT32_C( -405172900), INT32_C(  289408871), INT32_C(-1344350612)), 31,
      simde_em_int32x4_set(INT32_C(          0), INT32_C(          0), INT32_C(-2147483648), INT32_C(          0)) },
    { simde_em_int32x4_set(INT32_C( 1557583456), INT32_C(-2103083075), INT32_C( 1504077010), INT32_C(-1872159520)), 32,
      simde_em_int32x4_set(INT32_C( 1557583456), INT32_C(-2103083075), INT32_C( 1504077010), INT32_C(-1872159520)) },
    { simde_em_int32x4_set(INT32_C( -189540642), INT32_C(  966330585), INT32_C(  180055066), INT32_C( 1124112614)), 33,
      simde_em_int32x4_set(INT32_C( -379081284), INT32_C( 1932661170), INT32_C(  360110132), INT32_C(-2046742068)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_shiftLeftByScalar(test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_shiftRightByScalar(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    int b;
    simde_em_int32x4 r;
  } test_vec[] = {
    { simde_em_int32x4_set(INT32_C(  191308578), INT32_C( -192266108), INT32_C( 1691595981), INT32_C(  578691109)), 0,
      simde_em_int32x4_set(INT32_C(  191308578), INT32_C( -192266108), INT32_C( 1691595981), INT32_C(  578691109)) },
    { simde_em_int32x4_set(INT32_C( 1142685665), INT32_C( -621236311), INT32_C( -818217683), INT32_C( 1895809901)), 9,
      simde_em_int32x4_set(INT32_C(    2231807), INT32_C(   -1213353), INT32_C(   -1598082), INT32_C(    3702753)) },
    { simde_em_int32x4_set(INT32_C( -113308677), INT32_C( 1559996871), INT32_C( -736076951), INT32_C( 1523056014)), 20,
      simde_em_int32x4_set(INT32_C(       -109), INT32_C(       1487), INT32_C(       -702), INT32_C(       1452)) },
    { simde_em_int32x4_set(INT32_C(  188464722), INT32_C(  697229571), INT32_C( 1200100845), INT32_C( -390013753)), 7,
      simde_em_int32x4_set(INT32_C(    1472380), INT32_C(    5447106), INT32_C(    9375787), INT32_C(   -3046983)) },
    { simde_em_int32x4_set(INT32_C( -118564785), INT32_C( 2008904313), INT32_C( 1868370712), INT32_C( 1748154675)), 26,
      simde_em_int32x4_set(INT32_C(         -2), INT32_C(         29), INT32_C(         27), INT32_C(         26)) },
    { simde_em_int32x4_set(INT32_C(-1582940129), INT32_C(-1743970480), INT32_C( 1465257489), INT32_C( -724944183)), 3,
      simde_em_int32x4_set(INT32_C( -197867517), INT32_C( -217996310), INT32_C(  183157186), INT32_C(  -90618023)) },
    { simde_em_int32x4_set(INT32_C( -953623432), INT32_C(-1766175635), INT32_C( -845153619), INT32_C(   45413277)), 19,
      simde_em_int32x4_set(INT32_C(      -1819), INT32_C(      -3369), INT32_C(      -1613), INT32_C(         86)) },
    { simde_em_int32x4_set(INT32_C( 1256138768), INT32_C(  243235125), INT32_C( 1668777688), INT32_C( -617631972)), 24,
      simde_em_int32x4_set(INT32_C(         74), INT32_C(         14), INT32_C(         99), INT32_C(        -37)) },
    { simde_em_int32x4_set(INT32_C(  706600192), INT32_C(  424072325), INT32_C(  698295689), INT32_C( -673535771)), 31,
      simde_em_int32x4_set(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(         -1)) },
    { simde_em_int32x4_set(INT32_C( 1963971325), INT32_C( -575424867), INT32_C(  295336403), INT32_C( -967898752)), 32,
      simde_em_int32x4_set(INT32_C( 1963971325), INT32_C( -575424867), INT32_C(  295336403), INT32_C( -967898752)) },
    { simde_em_int32x4_set(INT32_C( 1736389341), INT32_C( -354986062), INT32_C( -797417243), INT32_C(  195986277)), 33,
      simde_em_int32x4_set(INT32_C(  868194670), INT32_C( -177493031), INT32_C( -398708622), INT32_C(   97993138)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_shiftRightByScalar(test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_store(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    int32_t r[4];
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C( -874342913), INT32_C(-1187479894), INT32_C(  905482520), INT32_C( -632088408)),
      { INT32_C( -874342913), INT32_C(-1187479894), INT32_C(  905482520), INT32_C( -632088408) } },
    { simde_em_int32x4_set(INT32_C(-1679785361), INT32_C( 1510543621), INT32_C( -701761037), INT32_C(-1724840226)),
      { INT32_C(-1679785361), INT32_C( 1510543621), INT32_C( -701761037), INT32_C(-1724840226) } },
    { simde_em_int32x4_set(INT32_C(  -91322883), INT32_C( 1433497093), INT32_C(-2027463216), INT32_C(-1375112229)),
      { INT32_C(  -91322883), INT32_C( 1433497093), INT32_C(-2027463216), INT32_C(-1375112229) } },
    { simde_em_int32x4_set(INT32_C(  193680238), INT32_C( 1228976669), INT32_C( -603627036), INT32_C( 1032765535)),
      { INT32_C(  193680238), INT32_C( 1228976669), INT32_C( -603627036), INT32_C( 1032765535) } },
    { simde_em_int32x4_set(INT32_C( 1230355780), INT32_C( -747750768), INT32_C(-1675953158), INT32_C( -586545241)),
      { INT32_C( 1230355780), INT32_C( -747750768), INT32_C(-1675953158), INT32_C( -586545241) } },
    { simde_em_int32x4_set(INT32_C( -318979488), INT32_C(  870447334), INT32_C(  488216963), INT32_C( 1882916721)),
      { INT32_C( -318979488), INT32_C(  870447334), INT32_C(  488216963), INT32_C( 1882916721) } },
    { simde_em_int32x4_set(INT32_C(-1203278003), INT32_C( 1593221512), INT32_C( -156775926), INT32_C(-1961327053)),
      { INT32_C(-1203278003), INT32_C( 1593221512), INT32_C( -156775926), INT32_C(-1961327053) } },
    { simde_em_int32x4_set(INT32_C(  163526504), INT32_C( -931818186), INT32_C(-1527789476), INT32_C(-1841022596)),
      { INT32_C(  163526504), INT32_C( -931818186), INT32_C(-1527789476), INT32_C(-1841022596) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r[4];
    munit_rand_memory(sizeof(r), (uint8_t*) r);
    simde_em_int32x4_store(r, test_vec[i].a);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_store1(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    int32_t r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C(  514001735), INT32_C( -148782675), INT32_C( -657027721), INT32_C( 1938559351)), INT32_C(  514001735) },
    { simde_em_int32x4_set(INT32_C(-1750602100), INT32_C( -302081577), INT32_C(-1089905893), INT32_C(  395500323)), INT32_C(-1750602100) },
    { simde_em_int32x4_set(INT32_C( 1592018939), INT32_C(-1993969641), INT32_C(  621150503), INT32_C( -328617516)), INT32_C( 1592018939) },
    { simde_em_int32x4_set(INT32_C( -836133263), INT32_C(  548932868), INT32_C( 1556558905), INT32_C(  264214561)), INT32_C( -836133263) },
    { simde_em_int32x4_set(INT32_C( -422991692), INT32_C( -119016138), INT32_C(-1196278505), INT32_C(-1902025164)), INT32_C( -422991692) },
    { simde_em_int32x4_set(INT32_C( 2023768635), INT32_C(-1397474436), INT32_C( -372162977), INT32_C( -886358730)), INT32_C( 2023768635) },
    { simde_em_int32x4_set(INT32_C( -878830806), INT32_C(-1327692990), INT32_C(  930269172), INT32_C(-2087458606)), INT32_C( -878830806) },
    { simde_em_int32x4_set(INT32_C( -804621531), INT32_C(-1254931710), INT32_C( 1047840347), INT32_C(-1327747438)), INT32_C( -804621531) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r = (int32_t) munit_rand_uint32();
    simde_em_int32x4_store1(&r, test_vec[i].a);
    munit_assert_int32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_store2(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    int32_t r[2];
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C(  482403464), INT32_C(  614485428), INT32_C(  240615429), INT32_C( -221362594)),
      { INT32_C(  482403464), INT32_C(  614485428) } },
    { simde_em_int32x4_set(INT32_C( 1605903673), INT32_C(  713719419), INT32_C( -652484472), INT32_C(  186960609)),
      { INT32_C( 1605903673), INT32_C(  713719419) } },
    { simde_em_int32x4_set(INT32_C(  111653274), INT32_C( 1113753966), INT32_C(-2052064259), INT32_C( 1941947990)),
      { INT32_C(  111653274), INT32_C( 1113753966) } },
    { simde_em_int32x4_set(INT32_C(-1110771816), INT32_C( -861766383), INT32_C( -341186564), INT32_C( -918753780)),
      { INT32_C(-1110771816), INT32_C( -861766383) } },
    { simde_em_int32x4_set(INT32_C( -546183052), INT32_C( 1863765408), INT32_C(  776845138), INT32_C(-1682897840)),
      { INT32_C( -546183052), INT32_C( 1863765408) } },
    { simde_em_int32x4_set(INT32_C( -458202392), INT32_C(-1456484722), INT32_C( -240150474), INT32_C(-1918236448)),
      { INT32_C( -458202392), INT32_C(-1456484722) } },
    { simde_em_int32x4_set(INT32_C(-1259935189), INT32_C(-1393296185), INT32_C( 1113249304), INT32_C(-1819617239)),
      { INT32_C(-1259935189), INT32_C(-1393296185) } },
    { simde_em_int32x4_set(INT32_C(-2116986529), INT32_C(  539654173), INT32_C( -937145916), INT32_C( 1460329889)),
      { INT32_C(-2116986529), INT32_C(  539654173) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int32_t r[2];
    munit_rand_memory(sizeof(r), (uint8_t*) r);
    simde_em_int32x4_store2(r, test_vec[i].a);
    munit_assert_int32(r[0], ==, test_vec[i].r[0]);
    munit_assert_int32(r[1], ==, test_vec[i].r[1]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_load(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t src[4];
    simde_em_int32x4 r;
  } test_vec[8] = {
    { { INT32_C(  199375418), INT32_C( -984540799), INT32_C( 1229971388), INT32_C(  398269917) },
      simde_em_int32x4_set(INT32_C(  199375418), INT32_C( -984540799), INT32_C( 1229971388), INT32_C(  398269917)) },
    { { INT32_C(  894714720), INT32_C(  539797535), INT32_C(-1066346243), INT32_C( -651608557) },
      simde_em_int32x4_set(INT32_C(  894714720), INT32_C(  539797535), INT32_C(-1066346243), INT32_C( -651608557)) },
    { { INT32_C( -434636221), INT32_C( -979686206), INT32_C(-1318172019), INT32_C(-1737951411) },
      simde_em_int32x4_set(INT32_C( -434636221), INT32_C( -979686206), INT32_C(-1318172019), INT32_C(-1737951411)) },
    { { INT32_C(  670067578), INT32_C( 1306292391), INT32_C( 1364382140), INT32_C(-1509945161) },
      simde_em_int32x4_set(INT32_C(  670067578), INT32_C( 1306292391), INT32_C( 1364382140), INT32_C(-1509945161)) },
    { { INT32_C( -934984868), INT32_C(-1867470477), INT32_C( -724253733), INT32_C( 1860301244) },
      simde_em_int32x4_set(INT32_C( -934984868), INT32_C(-1867470477), INT32_C( -724253733), INT32_C( 1860301244)) },
    { { INT32_C(-1836707595), INT32_C(-1745875131), INT32_C( 1423936703), INT32_C(-1556829156) },
      simde_em_int32x4_set(INT32_C(-1836707595), INT32_C(-1745875131), INT32_C( 1423936703), INT32_C(-1556829156)) },
    { { INT32_C( 1619533797), INT32_C( 1195964398), INT32_C(  -10146923), INT32_C(  342064430) },
      simde_em_int32x4_set(INT32_C( 1619533797), INT32_C( 1195964398), INT32_C(  -10146923), INT32_C(  342064430)) },
    { { INT32_C( -321017491), INT32_C(-1750303828), INT32_C(-1850689995), INT32_C(-1891788493) },
      simde_em_int32x4_set(INT32_C( -321017491), INT32_C(-1750303828), INT32_C(-1850689995), INT32_C(-1891788493)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_load(test_vec[i].src);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_load1(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t src[4];
    simde_em_int32x4 r;
  } test_vec[8] = {
    { {                    INT32_C( 1224063280), INT32_C(-1259152814), INT32_C(-1864645927), INT32_C( -403435611) },
      simde_em_int32x4_set(INT32_C( 1224063280), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C(  781841948), INT32_C(  414073821), INT32_C( 1351406094), INT32_C( 2098656323) },
      simde_em_int32x4_set(INT32_C(  781841948), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C(-2116140729), INT32_C(  335513427), INT32_C(  451414133), INT32_C( 1179075667) },
      simde_em_int32x4_set(INT32_C(-2116140729), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C( 1275850928), INT32_C( -357274099), INT32_C(-1261678072), INT32_C( 1773421561) },
      simde_em_int32x4_set(INT32_C( 1275850928), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C(  736375942), INT32_C(  500157024), INT32_C( -261925699), INT32_C( 1350153983) },
      simde_em_int32x4_set(INT32_C(  736375942), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C(  946372943), INT32_C( -734323831), INT32_C(  276422225), INT32_C( 1283761231) },
      simde_em_int32x4_set(INT32_C(  946372943), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C( 1599350174), INT32_C(-1326125305), INT32_C(-1239109778), INT32_C( 2013859671) },
      simde_em_int32x4_set(INT32_C( 1599350174), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C( 1467476095), INT32_C( 1453520461), INT32_C( 1460550221), INT32_C(-1193112123) },
      simde_em_int32x4_set(INT32_C( 1467476095), INT32_C(          0), INT32_C(          0), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_load1(test_vec[i].src);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_load2(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t src[4];
    simde_em_int32x4 r;
  } test_vec[8] = {
    { {                    INT32_C(-1984060388), INT32_C(  340238800), INT32_C(-1509323764), INT32_C(-1172938899) },
      simde_em_int32x4_set(INT32_C(-1984060388), INT32_C(  340238800), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C(  130527694), INT32_C( -922814146), INT32_C(-1746635706), INT32_C(  655578368) },
      simde_em_int32x4_set(INT32_C(  130527694), INT32_C( -922814146), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C(-1329200701), INT32_C(  703134460), INT32_C( -143027818), INT32_C(-1895581072) },
      simde_em_int32x4_set(INT32_C(-1329200701), INT32_C(  703134460), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C(-1070105926), INT32_C( 2071424536), INT32_C( 1553341360), INT32_C( 1548506472) },
      simde_em_int32x4_set(INT32_C(-1070105926), INT32_C( 2071424536), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C(-1348132127), INT32_C( 1891018379), INT32_C(-2140787847), INT32_C( -590718344) },
      simde_em_int32x4_set(INT32_C(-1348132127), INT32_C( 1891018379), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C(  643529277), INT32_C(-1596377181), INT32_C(  159291698), INT32_C(-1398334062) },
      simde_em_int32x4_set(INT32_C(  643529277), INT32_C(-1596377181), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C(  352392325), INT32_C(  597400926), INT32_C( 1122511899), INT32_C(  298275696) },
      simde_em_int32x4_set(INT32_C(  352392325), INT32_C(  597400926), INT32_C(          0), INT32_C(          0)) },
    { {                    INT32_C( -131443762), INT32_C(-1029176882), INT32_C( 1015301206), INT32_C( -742394792) },
      simde_em_int32x4_set(INT32_C( -131443762), INT32_C(-1029176882), INT32_C(          0), INT32_C(          0)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_load2(test_vec[i].src);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_swizzle(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    int32_t lanes[4];
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C( -486327773), INT32_C(-1224836817), INT32_C( 2024622827), INT32_C(-1023538938)),
      { 0, 3, 3, 2 },
      simde_em_int32x4_set(INT32_C( -486327773), INT32_C(-1023538938), INT32_C(-1023538938), INT32_C( 2024622827)) },
    { simde_em_int32x4_set(INT32_C( 1038037888), INT32_C(  403249920), INT32_C( 1995367771), INT32_C(-1177149161)),
      { 3, 1, 0, 0 },
      simde_em_int32x4_set(INT32_C(-1177149161), INT32_C(  403249920), INT32_C( 1038037888), INT32_C( 1038037888)) },
    { simde_em_int32x4_set(INT32_C( -517027392), INT32_C( -345699559), INT32_C(-1536780185), INT32_C(   42805841)),
      { 3, 3, 1, 2 },
      simde_em_int32x4_set(INT32_C(   42805841), INT32_C(   42805841), INT32_C( -345699559), INT32_C(-1536780185)) },
    { simde_em_int32x4_set(INT32_C( -669352962), INT32_C( -434993702), INT32_C( 1389340806), INT32_C(-1412107278)),
      { 3, 2, 1, 2 },
      simde_em_int32x4_set(INT32_C(-1412107278), INT32_C( 1389340806), INT32_C( -434993702), INT32_C( 1389340806)) },
    { simde_em_int32x4_set(INT32_C( 1023706154), INT32_C( -863925091), INT32_C(-2001592732), INT32_C(-1839160060)),
      { 1, 1, 2, 2 },
      simde_em_int32x4_set(INT32_C( -863925091), INT32_C( -863925091), INT32_C(-2001592732), INT32_C(-2001592732)) },
    { simde_em_int32x4_set(INT32_C(-1541533251), INT32_C(  194860725), INT32_C(  625344303), INT32_C(-1563539126)),
      { 2, 0, 0, 0 },
      simde_em_int32x4_set(INT32_C(  625344303), INT32_C(-1541533251), INT32_C(-1541533251), INT32_C(-1541533251)) },
    { simde_em_int32x4_set(INT32_C( 2076734270), INT32_C(-1957149487), INT32_C(-1196359850), INT32_C( -254125712)),
      { 2, 3, 1, 2 },
      simde_em_int32x4_set(INT32_C(-1196359850), INT32_C( -254125712), INT32_C(-1957149487), INT32_C(-1196359850)) },
    { simde_em_int32x4_set(INT32_C( 1438789288), INT32_C( 1063188987), INT32_C( 2142678168), INT32_C(-1148005155)),
      { 1, 0, 2, 0 },
      simde_em_int32x4_set(INT32_C( 1063188987), INT32_C( 1438789288), INT32_C( 2142678168), INT32_C( 1438789288)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_swizzle(test_vec[i].a, test_vec[i].lanes[0], test_vec[i].lanes[1], test_vec[i].lanes[2], test_vec[i].lanes[3]);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_shuffle(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    int32_t lanes[4];
    simde_em_int32x4 r;
  } test_vec[8] = {
    { simde_em_int32x4_set(INT32_C( 2136239748), INT32_C( -885165370), INT32_C( 1052376198), INT32_C(-1021952574)),
      simde_em_int32x4_set(INT32_C(  797317320), INT32_C(-1978956497), INT32_C(-1616660045), INT32_C(-1574806603)),
      { 1, 2, 6, 0 },
      simde_em_int32x4_set(INT32_C( -885165370), INT32_C( 1052376198), INT32_C(-1616660045), INT32_C( 2136239748)) },
    { simde_em_int32x4_set(INT32_C( -446719501), INT32_C( -923534333), INT32_C( 1944324872), INT32_C( -263112943)),
      simde_em_int32x4_set(INT32_C(-1444509903), INT32_C(-2017136201), INT32_C(-1014128631), INT32_C( 1154451032)),
      { 4, 7, 5, 6 },
      simde_em_int32x4_set(INT32_C(-1444509903), INT32_C( 1154451032), INT32_C(-2017136201), INT32_C(-1014128631)) },
    { simde_em_int32x4_set(INT32_C(-1332217168), INT32_C(    3120231), INT32_C(  852808015), INT32_C(-1386449459)),
      simde_em_int32x4_set(INT32_C( 1696535778), INT32_C( -198880471), INT32_C(  576841866), INT32_C(-1868273263)),
      { 6, 7, 0, 5 },
      simde_em_int32x4_set(INT32_C(  576841866), INT32_C(-1868273263), INT32_C(-1332217168), INT32_C( -198880471)) },
    { simde_em_int32x4_set(INT32_C(  912198238), INT32_C( 1358570903), INT32_C(-2116094120), INT32_C(-1581935706)),
      simde_em_int32x4_set(INT32_C(-1749319824), INT32_C(  -44157689), INT32_C( 1793469193), INT32_C(-2037759442)),
      { 6, 7, 1, 1 },
      simde_em_int32x4_set(INT32_C( 1793469193), INT32_C(-2037759442), INT32_C( 1358570903), INT32_C( 1358570903)) },
    { simde_em_int32x4_set(INT32_C( 1016326898), INT32_C( -334231495), INT32_C( 1643192332), INT32_C(  443647117)),
      simde_em_int32x4_set(INT32_C(-1944805728), INT32_C(-1112842524), INT32_C(  336416395), INT32_C( -607664508)),
      { 3, 2, 4, 1 },
      simde_em_int32x4_set(INT32_C(  443647117), INT32_C( 1643192332), INT32_C(-1944805728), INT32_C( -334231495)) },
    { simde_em_int32x4_set(INT32_C( 1619504139), INT32_C( -720724761), INT32_C( -475513320), INT32_C(  608193936)),
      simde_em_int32x4_set(INT32_C(   83063025), INT32_C(-1803840377), INT32_C(-1750754438), INT32_C( 1439826980)),
      { 3, 6, 0, 3 },
      simde_em_int32x4_set(INT32_C(  608193936), INT32_C(-1750754438), INT32_C( 1619504139), INT32_C(  608193936)) },
    { simde_em_int32x4_set(INT32_C( -182071478), INT32_C( -406473434), INT32_C(-1073247373), INT32_C( -702043232)),
      simde_em_int32x4_set(INT32_C(-1356269225), INT32_C( -984503349), INT32_C( -731683825), INT32_C( -537386515)),
      { 2, 5, 0, 3 },
      simde_em_int32x4_set(INT32_C(-1073247373), INT32_C( -984503349), INT32_C( -182071478), INT32_C( -702043232)) },
    { simde_em_int32x4_set(INT32_C(  -36559617), INT32_C( 2042352461), INT32_C( 2050487493), INT32_C(  433020392)),
      simde_em_int32x4_set(INT32_C(-1522909343), INT32_C(-1293448563), INT32_C( 2122212969), INT32_C(-1435299068)),
      { 1, 2, 5, 4 },
      simde_em_int32x4_set(INT32_C( 2042352461), INT32_C( 2050487493), INT32_C(-1293448563), INT32_C(-1522909343)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_shuffle(test_vec[i].a, test_vec[i].b, test_vec[i].lanes[0], test_vec[i].lanes[1], test_vec[i].lanes[2], test_vec[i].lanes[3]);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  SIMD_JS_TEST_FUNC(int32x4, set),
  SIMD_JS_TEST_FUNC(int32x4, splat),
  SIMD_JS_TEST_FUNC(int32x4, add),
  SIMD_JS_TEST_FUNC(int32x4, sub),
  SIMD_JS_TEST_FUNC(int32x4, mul),
  SIMD_JS_TEST_FUNC(int32x4, neg),
  SIMD_JS_TEST_FUNC(int32x4, and),
  SIMD_JS_TEST_FUNC(int32x4, xor),
  SIMD_JS_TEST_FUNC(int32x4, or),
  SIMD_JS_TEST_FUNC(int32x4, not),
  SIMD_JS_TEST_FUNC(int32x4, lessThan),
  SIMD_JS_TEST_FUNC(int32x4, lessThanOrEqual),
  SIMD_JS_TEST_FUNC(int32x4, greaterThan),
  SIMD_JS_TEST_FUNC(int32x4, greaterThanOrEqual),
  SIMD_JS_TEST_FUNC(int32x4, equal),
  SIMD_JS_TEST_FUNC(int32x4, notEqual),
  SIMD_JS_TEST_FUNC(int32x4, anyTrue),
  SIMD_JS_TEST_FUNC(int32x4, allTrue),
  SIMD_JS_TEST_FUNC(int32x4, select),
  SIMD_JS_TEST_FUNC(int32x4, shiftLeftByScalar),
  SIMD_JS_TEST_FUNC(int32x4, shiftRightByScalar),
  SIMD_JS_TEST_FUNC(int32x4, store),
  SIMD_JS_TEST_FUNC(int32x4, store1),
  SIMD_JS_TEST_FUNC(int32x4, store2),
  SIMD_JS_TEST_FUNC(int32x4, load),
  SIMD_JS_TEST_FUNC(int32x4, load1),
  SIMD_JS_TEST_FUNC(int32x4, load2),
  SIMD_JS_TEST_FUNC(int32x4, swizzle),
  SIMD_JS_TEST_FUNC(int32x4, shuffle),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

#if defined(SIMDE_NO_NATIVE)
#  define simde_simd_js_int32x4_test_suite simde_simd_js_int32x4_emul_test_suite
#endif

MunitSuite simde_simd_js_int32x4_test_suite = {
  (char*) "/int32x4",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
