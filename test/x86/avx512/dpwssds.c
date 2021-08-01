#define SIMDE_TEST_X86_AVX512_INSN dpwssds

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/dpwssds.h>

static int
test_simde_mm_dpwssds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   629088326), -INT32_C(   805699612), -INT32_C(   857846724), -INT32_C(  1442410483) },
      { -INT32_C(   982448532), -INT32_C(    63242410),  INT32_C(  1652543832),  INT32_C(  1711208107) },
      { -INT32_C(  1186955307), -INT32_C(  1165411970), -INT32_C(  1836685435),  INT32_C(  1664978423) },
      { -INT32_C(   303771434), -INT32_C(   791023294), -INT32_C(  1881050258), -INT32_C(   709343856) } },
    { { -INT32_C(   383209837),  INT32_C(   115696557), -INT32_C(   546806476),  INT32_C(   826632027) },
      {  INT32_C(  1693091302),  INT32_C(  1126134718), -INT32_C(   774461990), -INT32_C(   986377422) },
      {  INT32_C(  1856921025), -INT32_C(   193686336),  INT32_C(  1423236601),  INT32_C(   713365828) },
      { -INT32_C(   401452539), -INT32_C(   748617671), -INT32_C(   602413706),  INT32_C(   694585644) } },
    { {  INT32_C(  1552838814), -INT32_C(  1096831517), -INT32_C(  2054195885),  INT32_C(  1229702280) },
      { -INT32_C(   491194078), -INT32_C(  2032718707),  INT32_C(  1306241801),  INT32_C(  1651990724) },
      { -INT32_C(  1262614832),  INT32_C(   108158387),  INT32_C(  1535902163), -INT32_C(   391784506) },
      {  INT32_C(  1694190798), -INT32_C(   874437832), -INT32_C(  1597250686),  INT32_C(   823887571) } },
    { {  INT32_C(  1590320592), -INT32_C(  1813732983),  INT32_C(   283164492), -INT32_C(   260941792) },
      {  INT32_C(   295972958),  INT32_C(  1628968590), -INT32_C(   558062568),  INT32_C(  1271292283) },
      {  INT32_C(  1219072190),  INT32_C(  2128318002),  INT32_C(  1838136141),  INT32_C(  1901986067) },
      {  INT32_C(  1321658584), -INT32_C(  1174754099),  INT32_C(   458103176),  INT32_C(   308889589) } },
    { { -INT32_C(  1065156046),  INT32_C(   824285977), -INT32_C(  1173365441), -INT32_C(    49949377) },
      { -INT32_C(  1757040795), -INT32_C(  1978261443), -INT32_C(   268917284), -INT32_C(   664709466) },
      {  INT32_C(  1905845336), -INT32_C(  1096631937), -INT32_C(   696733289), -INT32_C(   321684090) },
      { -INT32_C(  1698724126),  INT32_C(  1180460104), -INT32_C(   666527165),  INT32_C(   712638998) } },
    { {  INT32_C(  1770199340),  INT32_C(   368351545), -INT32_C(   452596674), -INT32_C(  1698863550) },
      { -INT32_C(   921938358), -INT32_C(  1501057521), -INT32_C(   428015776), -INT32_C(  1445834628) },
      { -INT32_C(  1575856535),  INT32_C(   783812335),  INT32_C(   873709042),  INT32_C(  1842335779) },
      {              INT32_MAX,  INT32_C(    57173570), -INT32_C(   536969166),              INT32_MIN } },
    { {  INT32_C(   909564710), -INT32_C(   371409527),  INT32_C(   953178556),  INT32_C(   316777129) },
      { -INT32_C(   390793992), -INT32_C(   317297414),  INT32_C(  1277241641),  INT32_C(   549056761) },
      {  INT32_C(  1431760843),  INT32_C(  1748906668),  INT32_C(   882970251), -INT32_C(  1454996815) },
      {  INT32_C(   790991942), -INT32_C(   138730283),  INT32_C(  1254983104),  INT32_C(   254198888) } },
    { {  INT32_C(  1905392502), -INT32_C(  1856067737), -INT32_C(   891453488),  INT32_C(  1005229936) },
      {  INT32_C(   865091718), -INT32_C(    23343246), -INT32_C(  1909310243),  INT32_C(   892893631) },
      { -INT32_C(   609826444),  INT32_C(  1097598065), -INT32_C(   200586620),  INT32_C(  1731196385) },
      {  INT32_C(  1551895950), -INT32_C(  1876179683), -INT32_C(   505051158),  INT32_C(  1284354199) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_dpwssds_epi32(src, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_dpwssds_epi32(src, a, b);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_dpwssds_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
