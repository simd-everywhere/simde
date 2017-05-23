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
    { simde_em_int32x4_set(UINT32_C( -130054789), UINT32_C( -401734081), UINT32_C( 1269747402), UINT32_C( -508892901)),
      simde_em_int32x4_set(UINT32_C(  734233905), UINT32_C( -878683482), UINT32_C( 1174096883), UINT32_C(-1544702640)),
      simde_em_int32x4_set(UINT32_C(  604179116), UINT32_C(-1280417563), UINT32_C(-1851123011), UINT32_C(-2053595541)) },
    { simde_em_int32x4_set(UINT32_C( 1788993036), UINT32_C( 2015130024), UINT32_C(-1454134978), UINT32_C( 1814399676)),
      simde_em_int32x4_set(UINT32_C( -657913328), UINT32_C(-1955918330), UINT32_C( 1090706297), UINT32_C( -241091274)),
      simde_em_int32x4_set(UINT32_C( 1131079708), UINT32_C(   59211694), UINT32_C( -363428681), UINT32_C( 1573308402)) },
    { simde_em_int32x4_set(UINT32_C( -133951728), UINT32_C(-1602274563), UINT32_C(  813553307), UINT32_C( -909785972)),
      simde_em_int32x4_set(UINT32_C(  923795685), UINT32_C(  188916954), UINT32_C( 1558620902), UINT32_C( -213941642)),
      simde_em_int32x4_set(UINT32_C(  789843957), UINT32_C(-1413357609), UINT32_C(-1922793087), UINT32_C(-1123727614)) },
    { simde_em_int32x4_set(UINT32_C(   89193042), UINT32_C( 1146928390), UINT32_C(  228884520), UINT32_C( -318784613)),
      simde_em_int32x4_set(UINT32_C( -882737959), UINT32_C(-1087386362), UINT32_C(  647187678), UINT32_C(-1024342776)),
      simde_em_int32x4_set(UINT32_C( -793544917), UINT32_C(   59542028), UINT32_C(  876072198), UINT32_C(-1343127389)) },
    { simde_em_int32x4_set(UINT32_C(-1256057379), UINT32_C(-1986030630), UINT32_C(-1207245357), UINT32_C( -900753160)),
      simde_em_int32x4_set(UINT32_C(  295338101), UINT32_C( 1938958840), UINT32_C( -577851625), UINT32_C(-1964292814)),
      simde_em_int32x4_set(UINT32_C( -960719278), UINT32_C(  -47071790), UINT32_C(-1785096982), UINT32_C( 1429921322)) },
    { simde_em_int32x4_set(UINT32_C(-1836674315), UINT32_C(  276208638), UINT32_C( 1208429270), UINT32_C(-2088893437)),
      simde_em_int32x4_set(UINT32_C( -696286550), UINT32_C( 1080546136), UINT32_C( -464480723), UINT32_C( 1763719828)),
      simde_em_int32x4_set(UINT32_C( 1762006431), UINT32_C( 1356754774), UINT32_C(  743948547), UINT32_C( -325173609)) },
    { simde_em_int32x4_set(UINT32_C(-1784409930), UINT32_C(  684654184), UINT32_C(-1809625286), UINT32_C( 1429970648)),
      simde_em_int32x4_set(UINT32_C( 2144186007), UINT32_C( 1898630377), UINT32_C( 1398983174), UINT32_C( -271810807)),
      simde_em_int32x4_set(UINT32_C(  359776077), UINT32_C(-1711682735), UINT32_C( -410642112), UINT32_C( 1158159841)) },
    { simde_em_int32x4_set(UINT32_C( 1191160897), UINT32_C( -508418983), UINT32_C(  685454140), UINT32_C(-1319802529)),
      simde_em_int32x4_set(UINT32_C(  957908541), UINT32_C( -382522768), UINT32_C( 2102744472), UINT32_C(-1526513662)),
      simde_em_int32x4_set(UINT32_C(-2145897858), UINT32_C( -890941751), UINT32_C(-1506768684), UINT32_C( 1448651105)) }
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
    { simde_em_int32x4_set(UINT32_C( 1171034757), UINT32_C( 1301599556), UINT32_C(-1899411024), UINT32_C(    1895820)),
      simde_em_int32x4_set(UINT32_C( 1452423188), UINT32_C(-1873896616), UINT32_C(  219225954), UINT32_C(-1496571263)),
      simde_em_int32x4_set(UINT32_C( -281388431), UINT32_C(-1119471124), UINT32_C(-2118636978), UINT32_C( 1498467083)) },
    { simde_em_int32x4_set(UINT32_C(-1892767265), UINT32_C( -758835286), UINT32_C(-1965424001), UINT32_C( 1186393509)),
      simde_em_int32x4_set(UINT32_C(  930412480), UINT32_C(-1507141936), UINT32_C( 1371803635), UINT32_C(  856145635)),
      simde_em_int32x4_set(UINT32_C( 1471787551), UINT32_C(  748306650), UINT32_C(  957739660), UINT32_C(  330247874)) },
    { simde_em_int32x4_set(UINT32_C( -872156952), UINT32_C(-1413825413), UINT32_C( 2007885730), UINT32_C( -395381350)),
      simde_em_int32x4_set(UINT32_C( 1411707706), UINT32_C(   72463335), UINT32_C( -730931721), UINT32_C( 2059992351)),
      simde_em_int32x4_set(UINT32_C( 2011102638), UINT32_C(-1486288748), UINT32_C(-1556149845), UINT32_C( 1839593595)) },
    { simde_em_int32x4_set(UINT32_C( 2115626144), UINT32_C( -315360303), UINT32_C(   38470968), UINT32_C( -280023022)),
      simde_em_int32x4_set(UINT32_C(-1871186200), UINT32_C( 2047425728), UINT32_C(-2020529665), UINT32_C( -923560291)),
      simde_em_int32x4_set(UINT32_C( -308154952), UINT32_C( 1932181265), UINT32_C( 2059000633), UINT32_C(  643537269)) },
    { simde_em_int32x4_set(UINT32_C(  303010912), UINT32_C( 1573848957), UINT32_C(   53143155), UINT32_C( -984600909)),
      simde_em_int32x4_set(UINT32_C(  516264231), UINT32_C(-1828880590), UINT32_C( 1670486809), UINT32_C( 1856062973)),
      simde_em_int32x4_set(UINT32_C( -213253319), UINT32_C( -892237749), UINT32_C(-1617343654), UINT32_C( 1454303414)) },
    { simde_em_int32x4_set(UINT32_C( -879119083), UINT32_C(-1163095336), UINT32_C(  655734221), UINT32_C( 1270016985)),
      simde_em_int32x4_set(UINT32_C(  125997037), UINT32_C( -102393225), UINT32_C( 2055351476), UINT32_C( 1591598034)),
      simde_em_int32x4_set(UINT32_C(-1005116120), UINT32_C(-1060702111), UINT32_C(-1399617255), UINT32_C( -321581049)) },
    { simde_em_int32x4_set(UINT32_C(-1955519684), UINT32_C(  526101249), UINT32_C(-2004258965), UINT32_C(  981184505)),
      simde_em_int32x4_set(UINT32_C(  -55197038), UINT32_C( -158449914), UINT32_C( 1299340339), UINT32_C( 1757148687)),
      simde_em_int32x4_set(UINT32_C(-1900322646), UINT32_C(  684551163), UINT32_C(  991367992), UINT32_C( -775964182)) },
    { simde_em_int32x4_set(UINT32_C(-1972837826), UINT32_C( 1806252159), UINT32_C(  847393469), UINT32_C(  848361403)),
      simde_em_int32x4_set(UINT32_C(  849648236), UINT32_C( -893962239), UINT32_C( 1364936275), UINT32_C( -971361447)),
      simde_em_int32x4_set(UINT32_C( 1472481234), UINT32_C(-1594752898), UINT32_C( -517542806), UINT32_C( 1819722850)) }
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
    { simde_em_int32x4_set(UINT32_C(-1560811561), UINT32_C(-1403083270), UINT32_C(     494198), UINT32_C(-1161358910)),
      simde_em_int32x4_set(UINT32_C(-2114570857), UINT32_C(  -99146865), UINT32_C( -119795904), UINT32_C( -293405313)),
      simde_em_int32x4_set(UINT32_C(-1831648559), UINT32_C( 1191568550), UINT32_C(-1066956928), UINT32_C( -976058050)) },
    { simde_em_int32x4_set(UINT32_C(-1946618876), UINT32_C( -993132571), UINT32_C(-1534046454), UINT32_C(-1179602562)),
      simde_em_int32x4_set(UINT32_C(-1502836051), UINT32_C(-1946906427), UINT32_C( -267806115), UINT32_C( 1979587286)),
      simde_em_int32x4_set(UINT32_C( 1417088692), UINT32_C(-1883587783), UINT32_C(-1085097310), UINT32_C( -591451308)) },
    { simde_em_int32x4_set(UINT32_C(-1173967818), UINT32_C( -652266151), UINT32_C( 1875904741), UINT32_C(-1827831069)),
      simde_em_int32x4_set(UINT32_C(  -43629496), UINT32_C(-1465843629), UINT32_C( -335477536), UINT32_C( -534402209)),
      simde_em_int32x4_set(UINT32_C(  321046320), UINT32_C( 1511476187), UINT32_C(  990927968), UINT32_C(  591409981)) },
    { simde_em_int32x4_set(UINT32_C(  349032241), UINT32_C( -998863186), UINT32_C( 2113943593), UINT32_C(-1176290458)),
      simde_em_int32x4_set(UINT32_C( 1172132624), UINT32_C( 1693117938), UINT32_C(  808440034), UINT32_C( -892383455)),
      simde_em_int32x4_set(UINT32_C(  425121296), UINT32_C( -583666052), UINT32_C( 1767498802), UINT32_C(-1726406106)) },
    { simde_em_int32x4_set(UINT32_C(-1116214467), UINT32_C(-1007081170), UINT32_C( 1661319406), UINT32_C(   18487980)),
      simde_em_int32x4_set(UINT32_C( -933286115), UINT32_C( -603665234), UINT32_C(  160922604), UINT32_C( -475426202)),
      simde_em_int32x4_set(UINT32_C( 1852365033), UINT32_C( -320690876), UINT32_C( 2072171880), UINT32_C( 1932048520)) },
    { simde_em_int32x4_set(UINT32_C(-1072914281), UINT32_C( 1140050996), UINT32_C(-2099106205), UINT32_C(-1549697967)),
      simde_em_int32x4_set(UINT32_C(  175366662), UINT32_C(  724985897), UINT32_C( -777257858), UINT32_C(  586122419)),
      simde_em_int32x4_set(UINT32_C(-1343876726), UINT32_C(-1141320620), UINT32_C( -534951750), UINT32_C( 2141368483)) },
    { simde_em_int32x4_set(UINT32_C( 1951386016), UINT32_C( -773957576), UINT32_C( 1446631235), UINT32_C(-1582286610)),
      simde_em_int32x4_set(UINT32_C( -301501293), UINT32_C(   76332231), UINT32_C( -581420062), UINT32_C( 1682294414)),
      simde_em_int32x4_set(UINT32_C(  881673952), UINT32_C(-1958759544), UINT32_C( 1236564518), UINT32_C( 1273866244)) },
    { simde_em_int32x4_set(UINT32_C(-2017022165), UINT32_C(-1150642358), UINT32_C(  442182040), UINT32_C(  705579870)),
      simde_em_int32x4_set(UINT32_C(  302298485), UINT32_C(-2012578749), UINT32_C(  -21687377), UINT32_C( -433670233)),
      simde_em_int32x4_set(UINT32_C( 1246983591), UINT32_C( -418287522), UINT32_C(   14661352), UINT32_C( 1260870738)) }
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
    { simde_em_int32x4_set(UINT32_C(-2119394226), UINT32_C(  789749198), UINT32_C( -314946973), UINT32_C(-1131060559)),
      simde_em_int32x4_set(UINT32_C( 2119394226), UINT32_C( -789749198), UINT32_C(  314946973), UINT32_C( 1131060559)) },
    { simde_em_int32x4_set(UINT32_C( 1676628729), UINT32_C( 1980772481), UINT32_C(  843588474), UINT32_C( -629532177)),
      simde_em_int32x4_set(UINT32_C(-1676628729), UINT32_C(-1980772481), UINT32_C( -843588474), UINT32_C(  629532177)) },
    { simde_em_int32x4_set(UINT32_C(  314310243), UINT32_C(-1991434040), UINT32_C(-1014156958), UINT32_C(-2067877043)),
      simde_em_int32x4_set(UINT32_C( -314310243), UINT32_C( 1991434040), UINT32_C( 1014156958), UINT32_C( 2067877043)) },
    { simde_em_int32x4_set(UINT32_C( -705513988), UINT32_C( -329115372), UINT32_C( -562695311), UINT32_C(  153674395)),
      simde_em_int32x4_set(UINT32_C(  705513988), UINT32_C(  329115372), UINT32_C(  562695311), UINT32_C( -153674395)) },
    { simde_em_int32x4_set(UINT32_C( 1250132064), UINT32_C( -809589594), UINT32_C( 1567155766), UINT32_C(    7686570)),
      simde_em_int32x4_set(UINT32_C(-1250132064), UINT32_C(  809589594), UINT32_C(-1567155766), UINT32_C(   -7686570)) },
    { simde_em_int32x4_set(UINT32_C( -234734872), UINT32_C(-1434217973), UINT32_C( -983384476), UINT32_C( 1310011772)),
      simde_em_int32x4_set(UINT32_C(  234734872), UINT32_C( 1434217973), UINT32_C(  983384476), UINT32_C(-1310011772)) },
    { simde_em_int32x4_set(UINT32_C(  929211916), UINT32_C( -607667571), UINT32_C(  881370835), UINT32_C( 1388655955)),
      simde_em_int32x4_set(UINT32_C( -929211916), UINT32_C(  607667571), UINT32_C( -881370835), UINT32_C(-1388655955)) },
    { simde_em_int32x4_set(UINT32_C( -161496664), UINT32_C(-1960127881), UINT32_C(-1322054492), UINT32_C(  197214141)),
      simde_em_int32x4_set(UINT32_C(  161496664), UINT32_C( 1960127881), UINT32_C( 1322054492), UINT32_C( -197214141)) }
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
    { simde_em_int32x4_set(UINT32_C(-1944676286), UINT32_C(  -36080688), UINT32_C(   17224214), UINT32_C( 1061095412)),
      simde_em_int32x4_set(UINT32_C(-1311079230), UINT32_C( 1927258725), UINT32_C(  508469977), UINT32_C(-1306267556)),
      simde_em_int32x4_set(UINT32_C(-2146271166), UINT32_C( 1893278272), UINT32_C(     426512), UINT32_C(  841154644)) },
    { simde_em_int32x4_set(UINT32_C( 1697875404), UINT32_C(-1572146468), UINT32_C(-1360222112), UINT32_C(  348191759)),
      simde_em_int32x4_set(UINT32_C(  274882261), UINT32_C( 1662557591), UINT32_C(  397924109), UINT32_C(-2126592829)),
      simde_em_int32x4_set(UINT32_C(    2229444), UINT32_C(  570986644), UINT32_C(  111443968), UINT32_C(      50179)) },
    { simde_em_int32x4_set(UINT32_C(-1705179665), UINT32_C(  397610263), UINT32_C( -343568002), UINT32_C(  179791034)),
      simde_em_int32x4_set(UINT32_C( -227702514), UINT32_C( -917769649), UINT32_C(-1222946550), UINT32_C( 1188294510)),
      simde_em_int32x4_set(UINT32_C(-1840447218), UINT32_C(   16973831), UINT32_C(-1560211190), UINT32_C(   43213866)) },
    { simde_em_int32x4_set(UINT32_C( 1950893393), UINT32_C( 2096517266), UINT32_C(-1535391191), UINT32_C(  117896683)),
      simde_em_int32x4_set(UINT32_C( 1564493337), UINT32_C( 2027662391), UINT32_C(-1953835643), UINT32_C(-1904129579)),
      simde_em_int32x4_set(UINT32_C( 1413497873), UINT32_C( 2027028498), UINT32_C(-2146779135), UINT32_C(  100680129)) },
    { simde_em_int32x4_set(UINT32_C(-1148257439), UINT32_C( 1048214398), UINT32_C( -435334802), UINT32_C(-1069672417)),
      simde_em_int32x4_set(UINT32_C(  469777213), UINT32_C( -875166656), UINT32_C(  109731065), UINT32_C(  713994968)),
      simde_em_int32x4_set(UINT32_C(  402668321), UINT32_C(  173146176), UINT32_C(  101208168), UINT32_C(     921624)) },
    { simde_em_int32x4_set(UINT32_C( -331861652), UINT32_C(-1089330721), UINT32_C(-1237842359), UINT32_C(  850466372)),
      simde_em_int32x4_set(UINT32_C( 1030989647), UINT32_C(-1975154292), UINT32_C( -632774530), UINT32_C( -920664314)),
      simde_em_int32x4_set(UINT32_C(  741351756), UINT32_C(-1979711092), UINT32_C(-1844969400), UINT32_C(    1115652)) },
    { simde_em_int32x4_set(UINT32_C(  437523049), UINT32_C( 1631291869), UINT32_C( 1545912588), UINT32_C( -613541384)),
      simde_em_int32x4_set(UINT32_C(-1575915245), UINT32_C(  544262506), UINT32_C(-1784972599), UINT32_C( 1278852786)),
      simde_em_int32x4_set(UINT32_C(   34607105), UINT32_C(  540051784), UINT32_C(  335560712), UINT32_C( 1210587312)) },
    { simde_em_int32x4_set(UINT32_C(  802286343), UINT32_C( -144055949), UINT32_C( 1100536633), UINT32_C( 1940491614)),
      simde_em_int32x4_set(UINT32_C(-1512721196), UINT32_C( -648374172), UINT32_C(-1709998512), UINT32_C(-1813185142)),
      simde_em_int32x4_set(UINT32_C(  634494980), UINT32_C( -783777696), UINT32_C(    1071632), UINT32_C(  329813258)) }
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
    { simde_em_int32x4_set(UINT32_C(  210868924), UINT32_C( 1005630024), UINT32_C(-1503131968), UINT32_C(-1649331060)),
      simde_em_int32x4_set(UINT32_C(  636823718), UINT32_C( 1334897918), UINT32_C(  859513435), UINT32_C( -847009083)),
      simde_em_int32x4_set(UINT32_C(  694465050), UINT32_C( 1952472758), UINT32_C(-1789713253), UINT32_C( 1345494601)) },
    { simde_em_int32x4_set(UINT32_C(-1232813829), UINT32_C(   85468281), UINT32_C(  548857119), UINT32_C( -458257280)),
      simde_em_int32x4_set(UINT32_C(  356360074), UINT32_C( -775901744), UINT32_C( -193706742), UINT32_C(-1268538041)),
      simde_em_int32x4_set(UINT32_C(-1548132495), UINT32_C( -724006487), UINT32_C( -725442539), UINT32_C( 1355557319)) },
    { simde_em_int32x4_set(UINT32_C(-1565341507), UINT32_C(-1898034534), UINT32_C( 1762200922), UINT32_C( 2010029621)),
      simde_em_int32x4_set(UINT32_C(  461151037), UINT32_C(  257672388), UINT32_C( -915655139), UINT32_C( 1322268597)),
      simde_em_int32x4_set(UINT32_C(-1177660544), UINT32_C(-2121953698), UINT32_C(-1603978425), UINT32_C(  958310784)) },
    { simde_em_int32x4_set(UINT32_C( -660356766), UINT32_C( -721684777), UINT32_C( -267386408), UINT32_C( 1048074506)),
      simde_em_int32x4_set(UINT32_C( 1429727629), UINT32_C(  633180018), UINT32_C( 1133652494), UINT32_C(  436246129)),
      simde_em_int32x4_set(UINT32_C(-1919670033), UINT32_C( -247039579), UINT32_C(-1283314730), UINT32_C(  611897211)) },
    { simde_em_int32x4_set(UINT32_C(  552400717), UINT32_C( 1079934376), UINT32_C(-1843922237), UINT32_C(  981494209)),
      simde_em_int32x4_set(UINT32_C( -119621060), UINT32_C( 1154103075), UINT32_C(-1329531641), UINT32_C( -683096589)),
      simde_em_int32x4_set(UINT32_C( -667792015), UINT32_C(   76827275), UINT32_C(  584519620), UINT32_C( -305615822)) },
    { simde_em_int32x4_set(UINT32_C( -244106178), UINT32_C(-1951440103), UINT32_C( 1121924671), UINT32_C( 1794916406)),
      simde_em_int32x4_set(UINT32_C(-1742318852), UINT32_C( 1993818008), UINT32_C(  540959054), UINT32_C(  513187346)),
      simde_em_int32x4_set(UINT32_C( 1767206594), UINT32_C(  -42443647), UINT32_C( 1658935153), UINT32_C( 1953160740)) },
    { simde_em_int32x4_set(UINT32_C( -635279238), UINT32_C(-1842414117), UINT32_C( -199117055), UINT32_C(  773300056)),
      simde_em_int32x4_set(UINT32_C(-1437863211), UINT32_C(-1206482895), UINT32_C( -764476590), UINT32_C( 1652821317)),
      simde_em_int32x4_set(UINT32_C( 1885969071), UINT32_C(  708343274), UINT32_C(  642692179), UINT32_C( 1284739613)) },
    { simde_em_int32x4_set(UINT32_C( -444530452), UINT32_C( -252535784), UINT32_C( 2117046163), UINT32_C( 1621549094)),
      simde_em_int32x4_set(UINT32_C(-1172819657), UINT32_C(-1314376744), UINT32_C(-1790795998), UINT32_C(-1411705733)),
      simde_em_int32x4_set(UINT32_C( 1603875291), UINT32_C( 1096462272), UINT32_C( -345173839), UINT32_C( -880937891)) }
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
    { simde_em_int32x4_set(UINT32_C(  612634458), UINT32_C( -859004355), UINT32_C(   59160418), UINT32_C(-1213765045)),
      simde_em_int32x4_set(UINT32_C(  241477088), UINT32_C(  208660520), UINT32_C( 1642879984), UINT32_C( 1523517968)),
      simde_em_int32x4_set(UINT32_C(  786739194), UINT32_C( -856692163), UINT32_C( 1676607474), UINT32_C(   -1086885)) },
    { simde_em_int32x4_set(UINT32_C(-1510430166), UINT32_C( -908332341), UINT32_C(  886684575), UINT32_C( 1263076634)),
      simde_em_int32x4_set(UINT32_C(  815832058), UINT32_C(  285914535), UINT32_C( 1676910387), UINT32_C(-1118236151)),
      simde_em_int32x4_set(UINT32_C(-1241990150), UINT32_C( -639895569), UINT32_C( 2012987327), UINT32_C(  -10938597)) },
    { simde_em_int32x4_set(UINT32_C( 2111675849), UINT32_C(-2071816822), UINT32_C( 1696695924), UINT32_C(-1577562872)),
      simde_em_int32x4_set(UINT32_C( -104074462), UINT32_C(  708400741), UINT32_C(-1689045440), UINT32_C( -979241437)),
      simde_em_int32x4_set(UINT32_C(  -35651605), UINT32_C(-1363421201), UINT32_C(   -9193868), UINT32_C( -436601045)) },
    { simde_em_int32x4_set(UINT32_C( 1997721777), UINT32_C(  179181832), UINT32_C(-1598754518), UINT32_C(  515576405)),
      simde_em_int32x4_set(UINT32_C(-2121665287), UINT32_C( 2071885406), UINT32_C( 1385923539), UINT32_C( 1835211431)),
      simde_em_int32x4_set(UINT32_C( -140774151), UINT32_C( 2080276318), UINT32_C( -222301189), UINT32_C( 2147162871)) },
    { simde_em_int32x4_set(UINT32_C(-2059816495), UINT32_C(-2141383366), UINT32_C( -457795320), UINT32_C( 1606714318)),
      simde_em_int32x4_set(UINT32_C(-1399740547), UINT32_C( 1240134726), UINT32_C(   75457251), UINT32_C(-1616974208)),
      simde_em_int32x4_set(UINT32_C(-1380337667), UINT32_C( -905972354), UINT32_C( -452985877), UINT32_C( -539037746)) },
    { simde_em_int32x4_set(UINT32_C( 1817679142), UINT32_C(-1083433063), UINT32_C( 1018384959), UINT32_C(-1220425481)),
      simde_em_int32x4_set(UINT32_C(  620883526), UINT32_C(-1804830209), UINT32_C( -274690695), UINT32_C(-1870059968)),
      simde_em_int32x4_set(UINT32_C( 1834483558), UINT32_C(-1083408385), UINT32_C(   -4989057), UINT32_C(-1211502857)) },
    { simde_em_int32x4_set(UINT32_C( 1219714983), UINT32_C( -612107397), UINT32_C(-1313313001), UINT32_C(  239780973)),
      simde_em_int32x4_set(UINT32_C(  600599829), UINT32_C(  900272730), UINT32_C(  435673003), UINT32_C( 2078792716)),
      simde_em_int32x4_set(UINT32_C( 1811906487), UINT32_C(   -5506181), UINT32_C(-1174405185), UINT32_C( 2146425965)) },
    { simde_em_int32x4_set(UINT32_C(  166802073), UINT32_C( -563853411), UINT32_C(  503422173), UINT32_C(-1286881861)),
      simde_em_int32x4_set(UINT32_C(  976470397), UINT32_C(   29604222), UINT32_C(  831596085), UINT32_C( 1847732190)),
      simde_em_int32x4_set(UINT32_C( 1005843453), UINT32_C( -538443777), UINT32_C( 1066516221), UINT32_C(   -9715713)) }
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
    { simde_em_int32x4_set(UINT32_C( 1505760985), UINT32_C( 1390822226), UINT32_C(   30759388), UINT32_C( 1731963796)),
      simde_em_int32x4_set(UINT32_C(-1505760986), UINT32_C(-1390822227), UINT32_C(  -30759389), UINT32_C(-1731963797)) },
    { simde_em_int32x4_set(UINT32_C(-1850431043), UINT32_C( -976761722), UINT32_C( 2118758360), UINT32_C( 1017388403)),
      simde_em_int32x4_set(UINT32_C( 1850431042), UINT32_C(  976761721), UINT32_C(-2118758361), UINT32_C(-1017388404)) },
    { simde_em_int32x4_set(UINT32_C(-1126551480), UINT32_C(  128410428), UINT32_C(  233069974), UINT32_C(-1388756245)),
      simde_em_int32x4_set(UINT32_C( 1126551479), UINT32_C( -128410429), UINT32_C( -233069975), UINT32_C( 1388756244)) },
    { simde_em_int32x4_set(UINT32_C( -540291506), UINT32_C(-1752278563), UINT32_C(-1570332542), UINT32_C(  523975081)),
      simde_em_int32x4_set(UINT32_C(  540291505), UINT32_C( 1752278562), UINT32_C( 1570332541), UINT32_C( -523975082)) },
    { simde_em_int32x4_set(UINT32_C(-1388487580), UINT32_C( 1924801847), UINT32_C(  788035944), UINT32_C(  594079074)),
      simde_em_int32x4_set(UINT32_C( 1388487579), UINT32_C(-1924801848), UINT32_C( -788035945), UINT32_C( -594079075)) },
    { simde_em_int32x4_set(UINT32_C(  706062732), UINT32_C(-1031470908), UINT32_C( 1531233047), UINT32_C(   54437932)),
      simde_em_int32x4_set(UINT32_C( -706062733), UINT32_C( 1031470907), UINT32_C(-1531233048), UINT32_C(  -54437933)) },
    { simde_em_int32x4_set(UINT32_C( 1156708076), UINT32_C(-1339483913), UINT32_C( -345112269), UINT32_C( 1973870097)),
      simde_em_int32x4_set(UINT32_C(-1156708077), UINT32_C( 1339483912), UINT32_C(  345112268), UINT32_C(-1973870098)) },
    { simde_em_int32x4_set(UINT32_C(  758342222), UINT32_C( -520430797), UINT32_C( -191576597), UINT32_C(-1264920102)),
      simde_em_int32x4_set(UINT32_C( -758342223), UINT32_C(  520430796), UINT32_C(  191576596), UINT32_C( 1264920101)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_not(test_vec[i].a);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  TEST_FUNC(em_int32x4_set),
  TEST_FUNC(em_int32x4_splat),
  TEST_FUNC(em_int32x4_add),
  TEST_FUNC(em_int32x4_sub),
  TEST_FUNC(em_int32x4_mul),
  TEST_FUNC(em_int32x4_neg),
  TEST_FUNC(em_int32x4_and),
  TEST_FUNC(em_int32x4_xor),
  TEST_FUNC(em_int32x4_or),
  TEST_FUNC(em_int32x4_not),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

#if defined(SIMDE_NO_NATIVE)
#  define simde_simd_js_test_suite simde_simd_js_emul_test_suite
#endif

MunitSuite simde_simd_js_test_suite = {
  (char*) "",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
