/* SPDX-License-Identifier: MIT
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
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 *   2020      Hidayat Khan <huk2209@gmail.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN test

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/test.h>

static int
test_simde_mm512_mask_test_epi32_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__mmask16 r;
  } test_vec[8] = {
    { UINT16_C(13733),
      simde_mm512_set_epi32(INT32_C(-1058044212), INT32_C( 1745554146), INT32_C( -938028173), INT32_C( 1123843978),
                            INT32_C(          0), INT32_C(  369104615), INT32_C(  288860030), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C( 1441724088), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)),
      simde_mm512_set_epi32(INT32_C( -173456664), INT32_C(          0), INT32_C( 1847983972), INT32_C(          0),
                            INT32_C( 1618889484), INT32_C(-1607295283), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1566474746), INT32_C(          0), INT32_C(          0), INT32_C( -427236235),
                            INT32_C( 1934991438), INT32_C( -587656653), INT32_C(  -72145550), INT32_C(          0)),
      UINT16_C( 9216) },
    { UINT16_C(63633),
      simde_mm512_set_epi32(INT32_C( -839841286), INT32_C(          0), INT32_C(-1528318158), INT32_C(-1752243244),
                            INT32_C(          0), INT32_C(-1210241348), INT32_C(-1908519219), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(  521483609), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(  543914332),
                            INT32_C( 2140721152), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)),
      UINT16_C( 4096) },
    { UINT16_C(46032),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(  329000619),
                            INT32_C(-1407469850), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( -102278232), INT32_C(   43450551), INT32_C(          0), INT32_C( 1603148048),
                            INT32_C(          0), INT32_C(  306941628), INT32_C(          0), INT32_C( 1716086600)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( -262488052), INT32_C(          0), INT32_C( -979944078),
                            INT32_C(          0), INT32_C(          0), INT32_C( -671140903), INT32_C( 2141932562),
                            INT32_C( -937827627), INT32_C( -402281975), INT32_C( 1596901579), INT32_C(  735909604),
                            INT32_C(          0), INT32_C(-1202496908), INT32_C(          0), INT32_C( 1187626051)),
      UINT16_C( 4304) },
    { UINT16_C(22689),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C( 1163951893), INT32_C(          0),
                            INT32_C(          0), INT32_C( -972105386), INT32_C(          0), INT32_C( -189029459),
                            INT32_C( -225058862), INT32_C(-1537122616), INT32_C(          0), INT32_C(-1756788873),
                            INT32_C(          0), INT32_C(          0), INT32_C( -184793757), INT32_C( 1418114595)),
      simde_mm512_set_epi32(INT32_C(-1354385088), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1841164366), INT32_C(  -94325362), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(  594617140), INT32_C(          0),
                            INT32_C(  239227634), INT32_C(          0), INT32_C(  895132574), INT32_C( -123965580)),
      UINT16_C(    1) },
    { UINT16_C(25521),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( 1916556758), INT32_C(  729046451), INT32_C(  516587379),
                            INT32_C( 1306886393), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C( 2010256146), INT32_C( -351991039), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)),
      simde_mm512_set_epi32(INT32_C(-1549799175), INT32_C( -926637576), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C( 1633420708), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(-1070649171), INT32_C( -629074644),
                            INT32_C( -658686596), INT32_C( 1058031607), INT32_C(          0), INT32_C(  590507721)),
      UINT16_C(16416) },
    { UINT16_C(62461),
      simde_mm512_set_epi32(INT32_C(-1777930200), INT32_C(-2074304971), INT32_C(-1238248254), INT32_C(          0),
                            INT32_C(          0), INT32_C(-2126101806), INT32_C( 1488735838), INT32_C(-1941730876),
                            INT32_C(          0), INT32_C(          0), INT32_C(-1287988933), INT32_C( -234166092),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C( 1899039383)),
      simde_mm512_set_epi32(INT32_C(-2019508611), INT32_C(          0), INT32_C(  630346390), INT32_C( 1865079685),
                            INT32_C( -135665525), INT32_C(          0), INT32_C(  751170486), INT32_C(  580518147),
                            INT32_C(  875750845), INT32_C(  263799439), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C( -889468036), INT32_C(  606319308), INT32_C(          0)),
      UINT16_C(41728) },
    { UINT16_C(64894),
      simde_mm512_set_epi32(INT32_C( 1983606396), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1668321234), INT32_C( 1230207891), INT32_C(-1334904081), INT32_C(-1369460101),
                            INT32_C(          0), INT32_C(          0), INT32_C(  556969985), INT32_C(  844640930),
                            INT32_C(-1447169687), INT32_C( -621740127), INT32_C( 1847803343), INT32_C(          0)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C( -578157153),
                            INT32_C(          0), INT32_C(-1740019927), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(  136767631), INT32_C(          0), INT32_C(-1994887012),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(-1203448248)),
      UINT16_C( 1040) },
    { UINT16_C(   72),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( -302271050), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1073370549), INT32_C(  911478852), INT32_C( 2032788905), INT32_C(          0),
                            INT32_C(  398076492), INT32_C(  901163928), INT32_C(          0), INT32_C(-1022133203),
                            INT32_C( -345543230), INT32_C(          0), INT32_C( 2110415254), INT32_C(          0)),
      simde_mm512_set_epi32(INT32_C(          0), INT32_C( 1062395075), INT32_C( -125220770), INT32_C(          0),
                            INT32_C(          0), INT32_C(-1603705335), INT32_C(-1563808089), INT32_C(          0),
                            INT32_C(          0), INT32_C( 1591467282), INT32_C(  -57010818), INT32_C(          0),
                            INT32_C(          0), INT32_C( 1904594022), INT32_C(          0), INT32_C( -170170916)),
      UINT16_C(   64) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask16 r = simde_mm512_mask_test_epi32_mask(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_mmask16(HEDLEY_STATIC_CAST(uint16_t, r), ==, HEDLEY_STATIC_CAST(uint16_t, test_vec[i].r));
  }

  return 0;
}

static int
test_simde_mm512_mask_test_epi64_mask(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i b;
    simde__mmask8 r;
  } test_vec[8] = {
      { UINT8_C( 51),
      simde_mm512_set_epi64(INT64_C(-1021777151925940720), INT64_C(-8606874489654438743),
                            INT64_C( 2982642907250026668), INT64_C( 1121557266302837638),
                            INT64_C( 2431134246593116065), INT64_C(  613583019816833791),
                            INT64_C( 1064733599562411669), INT64_C( 2423175833785490495)),
      simde_mm512_set_epi64(INT64_C( 1320056489604494378), INT64_C( 8016850443050245285),
                            INT64_C(-1985397303830803362), INT64_C( 3490054501014041612),
                            INT64_C(-5459290507928993205), INT64_C( 7649116850053105819),
                            INT64_C( 2306883418990405350), INT64_C( -533675138939657219)),
      UINT8_C( 51) },
    { UINT8_C(107),
      simde_mm512_set_epi64(INT64_C(-5107242476853461048), INT64_C( 8011490560794608442),
                            INT64_C( 6781928010904462143), INT64_C(-2849262341734469560),
                            INT64_C( -680409599063304510), INT64_C(-5566534159487294326),
                            INT64_C( 1845249206901740837), INT64_C( -995351966812894672)),
      simde_mm512_set_epi64(INT64_C( 5576021829988608395), INT64_C( 6950975376569962720),
                            INT64_C(-6894298607029431267), INT64_C(  627810606408873629),
                            INT64_C( 5554191263207946561), INT64_C(-8076655846804767103),
                            INT64_C(  298038848695084217), INT64_C(  984575648746107146)),
      UINT8_C(107) },
    { UINT8_C( 37),
      simde_mm512_set_epi64(INT64_C( 7893528652770105648), INT64_C( 6530680127391412513),
                            INT64_C( 8552423929938430730), INT64_C(-2756847038438887047),
                            INT64_C(-4669427049793346259), INT64_C(-1241821792536551210),
                            INT64_C(-3299061013747874632), INT64_C(-6836802816564857048)),
      simde_mm512_set_epi64(INT64_C(-6002777026216974201), INT64_C(-4636334703117125394),
                            INT64_C( 1607894826575669284), INT64_C( 4780984352817723804),
                            INT64_C( 6091782245426739371), INT64_C(  678622961946838177),
                            INT64_C(-5016020090857558708), INT64_C( 6626170086889501267)),
      UINT8_C( 37) },
    { UINT8_C(219),
      simde_mm512_set_epi64(INT64_C(-2186517171747754940), INT64_C(-7709006576096545178),
                            INT64_C(-4148769136791016488), INT64_C(-1135438727484114896),
                            INT64_C( 8260953320246547916), INT64_C(-1100980776979386438),
                            INT64_C(-5918460005278991975), INT64_C(-9003997367625569086)),
      simde_mm512_set_epi64(INT64_C( 4216784995205036162), INT64_C( -610629877628633270),
                            INT64_C( 8989369503655563805), INT64_C( 7802074548335401303),
                            INT64_C(-8877282827036376912), INT64_C(  503689220758847744),
                            INT64_C(-1271186344370845002), INT64_C(-7863377575460447119)),
      UINT8_C(219) },
    { UINT8_C(231),
      simde_mm512_set_epi64(INT64_C(-1315792135193853217), INT64_C(  645488177526442731),
                            INT64_C(-9165154544452808856), INT64_C( 6660247336280542891),
                            INT64_C( 6275701276122863077), INT64_C( 6727198969638040444),
                            INT64_C(-7884988216343642316), INT64_C(-2772157409458686119)),
      simde_mm512_set_epi64(INT64_C(-3947691112861846019), INT64_C(-6027683744476655452),
                            INT64_C( 7878786769508596925), INT64_C(  898779895364838727),
                            INT64_C( 1691913248175202869), INT64_C(  925600519637433490),
                            INT64_C(-7786666185996880531), INT64_C(   83985053119720048)),
      UINT8_C(231) },
    { UINT8_C(185),
      simde_mm512_set_epi64(INT64_C(-1840026123275896761), INT64_C( 2958979742732699034),
                            INT64_C( 8087751231081622093), INT64_C(-8600769129449664089),
                            INT64_C( 4437078864330373252), INT64_C(-7780807660685149956),
                            INT64_C(-2075154109213332653), INT64_C( 4181892367727099352)),
      simde_mm512_set_epi64(INT64_C(  774147715399030450), INT64_C( -164954981177608742),
                            INT64_C( 2704996814905355295), INT64_C(-8428935692581869552),
                            INT64_C( 9058580247051597222), INT64_C(-5265103403663862315),
                            INT64_C(  -26456365246944797), INT64_C(-2390663458830548776)),
      UINT8_C(185) },
    { UINT8_C(101),
      simde_mm512_set_epi64(INT64_C( -500144007601202828), INT64_C( 1632600048776630049),
                            INT64_C( -841897496147484648), INT64_C(-9027608573250153699),
                            INT64_C( 5145549241007852287), INT64_C( 3253065934430492129),
                            INT64_C(-7159974623801904746), INT64_C(-5093282550607071469)),
      simde_mm512_set_epi64(INT64_C(-5525231520825547752), INT64_C(-8701772324698157173),
                            INT64_C(-8951932473020511764), INT64_C( 3775424668993203418),
                            INT64_C( 6848385375992501495), INT64_C(  530028931531319450),
                            INT64_C(-2966939250988120843), INT64_C( 8223727294178057916)),
      UINT8_C(101) },
    { UINT8_C( 49),
      simde_mm512_set_epi64(INT64_C(-6089529524580685715), INT64_C(-7930651770137634148),
                            INT64_C( 5513049874271089607), INT64_C( -418315818469941774),
                            INT64_C( 5583867531021541749), INT64_C( 3646229040969122240),
                            INT64_C(  298432255739992787), INT64_C( 8383322056459699927)),
      simde_mm512_set_epi64(INT64_C( 6173222450906561792), INT64_C(-2639921841557235108),
                            INT64_C( 1632309106004579853), INT64_C(-5099037996367773534),
                            INT64_C(-4229050909659913228), INT64_C(-6254506698641899913),
                            INT64_C( 1797655404582044593), INT64_C( 7065183211262770455)),
      UINT8_C( 49) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask8 r = simde_mm512_mask_test_epi64_mask(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_mmask8(r, ==, test_vec[i].r);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_test_epi32_mask)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_test_epi64_mask)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
