#define SIMDE_TEST_X86_AVX512_INSN rorv

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/rorv.h>

static int
test_simde_mm_rorv_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(    69354328), -INT32_C(  1197998948),  INT32_C(   293111754),  INT32_C(  1832942147) },
      { -INT32_C(   411975625),  INT32_C(  1192461355),  INT32_C(  1780271933),  INT32_C(  1641329593) },
      { -INT32_C(  1149677065), -INT32_C(  1818815745), -INT32_C(  1950073264), -INT32_C(  1606606410) } },
    { {  INT32_C(   207401327),  INT32_C(  2009396397), -INT32_C(  1098367621), -INT32_C(   282277449) },
      { -INT32_C(  1261003383),  INT32_C(  1593567521),  INT32_C(  1858607028),  INT32_C(   986684618) },
      { -INT32_C(  1215943080), -INT32_C(  1142785450), -INT32_C(  2083013656),  INT32_C(  1845218098) } },
    { { -INT32_C(    96064435), -INT32_C(  1687090656), -INT32_C(    10880441),  INT32_C(  1290700227) },
      {  INT32_C(  1140900898),  INT32_C(  1638071213), -INT32_C(   573609198),  INT32_C(  1427611399) },
      {  INT32_C(  2123467539),  INT32_C(  1359272840),  INT32_C(  2123497430), -INT32_C(  2036736757) } },
    { { -INT32_C(   347120181), -INT32_C(  1350123161),  INT32_C(  2125389755), -INT32_C(  2016764827) },
      {  INT32_C(   231459424), -INT32_C(   680628539), -INT32_C(   525058343), -INT32_C(  1472869411) },
      { -INT32_C(   347120181),  INT32_C(  1031550475),  INT32_C(  1466949055),  INT32_C(  1045750572) } },
    { { -INT32_C(  1869380312),  INT32_C(    20912454),  INT32_C(  1568665080), -INT32_C(   370849399) },
      { -INT32_C(   654921709), -INT32_C(   139500514),  INT32_C(  2144887970),  INT32_C(  1478954287) },
      {  INT32_C(  1889866258),  INT32_C(    83649816),  INT32_C(   392166270), -INT32_C(  1827417142) } },
    { { -INT32_C(   655836526), -INT32_C(   858183725), -INT32_C(  1658234860), -INT32_C(  1266282847) },
      { -INT32_C(   577995585), -INT32_C(  2083177248), -INT32_C(   821908064),  INT32_C(  1294412474) },
      { -INT32_C(  1311673051), -INT32_C(   858183725), -INT32_C(  1658234860),  INT32_C(   562276461) } },
    { { -INT32_C(  1205530652),  INT32_C(  1250230070), -INT32_C(   102257321),  INT32_C(  2074963388) },
      { -INT32_C(   900187415),  INT32_C(   374156662), -INT32_C(  1780133926),  INT32_C(  1591872889) },
      { -INT32_C(   228846969),  INT32_C(   335337770),  INT32_C(  2045466110), -INT32_C(   692658627) } },
    { {  INT32_C(  1393952540),  INT32_C(  1587386886),  INT32_C(    56067399), -INT32_C(   595720974) },
      { -INT32_C(  1264134338), -INT32_C(   540347644), -INT32_C(  1133203390), -INT32_C(   652585283) },
      {  INT32_C(  1280842865),  INT32_C(  1709824416), -INT32_C(  1059724975), -INT32_C(   470800490) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_rorv_epi32(a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_rorv_epi32(a, b);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_rorv_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
