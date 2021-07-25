#define SIMDE_TEST_X86_AVX512_INSN dpwssd

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/dpwssd.h>

static int
test_simde_mm_dpwssd_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   162181129),  INT32_C(  1617503567), -INT32_C(  1477930415),  INT32_C(   981415384) },
      { -INT32_C(  1038565035),  INT32_C(   289426369),  INT32_C(  2134447221),  INT32_C(   594328108) },
      {  INT32_C(  1494860042),  INT32_C(   934904806), -INT32_C(   304176619),  INT32_C(   740842967) },
      { -INT32_C(   265077087),  INT32_C(  1064382197), -INT32_C(  1755028904),  INT32_C(   654484908) } },
    { { -INT32_C(   521256929),  INT32_C(    32583307),  INT32_C(  1870670402), -INT32_C(   275583515) },
      { -INT32_C(  1790399314),  INT32_C(  1154220335),  INT32_C(  2050075555),  INT32_C(   665213192) },
      {  INT32_C(   621253786),  INT32_C(    86440130),  INT32_C(   141862691),  INT32_C(  1123485332) },
      { -INT32_C(   193776189),  INT32_C(    55234161), -INT32_C(  1865294657), -INT32_C(    63200337) } },
    { { -INT32_C(   505987150), -INT32_C(   467295168),  INT32_C(  1465800527),  INT32_C(  1249838512) },
      {  INT32_C(  1550878361), -INT32_C(  1570662785), -INT32_C(   777333443), -INT32_C(  1911250469) },
      {  INT32_C(   544205792), -INT32_C(   570124913), -INT32_C(  1674157076),  INT32_C(    31962472) },
      { -INT32_C(   149385950),  INT32_C(   477185973),  INT32_C(  1488802919),  INT32_C(  1695868340) } },
    { { -INT32_C(  1168287941),  INT32_C(   727498477),  INT32_C(  1878787731), -INT32_C(  2013458265) },
      { -INT32_C(  1951896324), -INT32_C(   311776255),  INT32_C(  2005573647), -INT32_C(  1871089323) },
      { -INT32_C(  1253321016),  INT32_C(   685811605),  INT32_C(  1436016046), -INT32_C(   371354387) },
      { -INT32_C(   893069741),  INT32_C(  1164431170), -INT32_C(  1529866197),  INT32_C(  1648032205) } },
    { {  INT32_C(    41256193),  INT32_C(  1106304817), -INT32_C(   726107521), -INT32_C(  1285279253) },
      { -INT32_C(  1654083832),  INT32_C(    96815447),  INT32_C(   324689190), -INT32_C(   218286095) },
      { -INT32_C(   285904196), -INT32_C(   802167471),  INT32_C(  1252321119),  INT32_C(   570230809) },
      { -INT32_C(   457444503),  INT32_C(   959972835), -INT32_C(   781795519), -INT32_C(  1284574851) } },
    { {  INT32_C(   264136120), -INT32_C(   736853074), -INT32_C(   756519200),  INT32_C(  1657071014) },
      { -INT32_C(  1471104681), -INT32_C(    42434658), -INT32_C(  2142823321), -INT32_C(   593411036) },
      {  INT32_C(  1491820458), -INT32_C(  1020395550),  INT32_C(   345314670),  INT32_C(  1366710778) },
      { -INT32_C(   689847314), -INT32_C(   727743166), -INT32_C(   888910987),  INT32_C(  1870043140) } },
    { { -INT32_C(  1309030637), -INT32_C(  1381011130), -INT32_C(  1322387827), -INT32_C(   443625925) },
      {  INT32_C(   272464173), -INT32_C(   405575047),  INT32_C(  2046519423), -INT32_C(   724930111) },
      {  INT32_C(  2139538232), -INT32_C(  1054067404),  INT32_C(  1718835755),  INT32_C(  1447756072) },
      { -INT32_C(  1656007975), -INT32_C(   910226914),  INT32_C(   114096035), -INT32_C(   679376751) } },
    { { -INT32_C(   211383942),  INT32_C(  1943681523),  INT32_C(  1659688353),  INT32_C(  2134357831) },
      { -INT32_C(  1342259846),  INT32_C(   493890546), -INT32_C(  1383799931),  INT32_C(  1594085348) },
      {  INT32_C(  1280469336),  INT32_C(  1136602530),  INT32_C(  1235659522), -INT32_C(   573973150) },
      { -INT32_C(  1070826298), -INT32_C(  2089166425),  INT32_C(  1420204867),  INT32_C(  2030457066) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_dpwssd_epi32(src, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_dpwssd_epi32(src, a, b);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_dpwssd_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
