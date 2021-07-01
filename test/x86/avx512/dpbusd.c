#define SIMDE_TEST_X86_AVX512_INSN dpbusd

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/dpbusd.h>

static int
test_simde_mm_dpbusd_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   323980410),  INT32_C(  1251535663), -INT32_C(    30467478),  INT32_C(   741325049) },
      { -INT32_C(  1157873637), -INT32_C(   442077135), -INT32_C(  1344200384),  INT32_C(   775580596) },
      {  INT32_C(   641829623), -INT32_C(   529409675), -INT32_C(   304176909),  INT32_C(  1947798872) },
      {  INT32_C(   323996063),  INT32_C(  1251548458), -INT32_C(    30482453),  INT32_C(   741349066) } },
    { {  INT32_C(  2133726542), -INT32_C(   966470266), -INT32_C(  1435154698), -INT32_C(  1445417039) },
      { -INT32_C(  1345381831), -INT32_C(   410042125),  INT32_C(   970223072), -INT32_C(   928125574) },
      { -INT32_C(  1991714045), -INT32_C(  1504727888), -INT32_C(  1538210574), -INT32_C(  1387452045) },
      {  INT32_C(  2133719830), -INT32_C(   966504575), -INT32_C(  1435152658), -INT32_C(  1445396571) } },
    { {  INT32_C(   912006211),  INT32_C(  1025370973), -INT32_C(   763956904), -INT32_C(   493149217) },
      { -INT32_C(  1351883777), -INT32_C(  2108245361), -INT32_C(   249125250),  INT32_C(   312374223) },
      { -INT32_C(   330696049),  INT32_C(  1026189029),  INT32_C(   923836504), -INT32_C(  1021727804) },
      {  INT32_C(   911980345),  INT32_C(  1025397626), -INT32_C(   763947889), -INT32_C(   493168560) } },
    { {  INT32_C(   494044302), -INT32_C(  1130379202),  INT32_C(  1051575663), -INT32_C(   934196168) },
      {  INT32_C(   750033478),  INT32_C(  1483333120),  INT32_C(  1133476223), -INT32_C(  1308186588) },
      {  INT32_C(  1792047148), -INT32_C(  1339658431),  INT32_C(  1844368437),  INT32_C(  1714765600) },
      {  INT32_C(   494061886), -INT32_C(  1130357610),  INT32_C(  1051581799), -INT32_C(   934165958) } },
    { { -INT32_C(   627905831),  INT32_C(  1194523848), -INT32_C(  1702182283), -INT32_C(  1756589974) },
      {  INT32_C(  1241586697), -INT32_C(  1040570228),  INT32_C(   472836348),  INT32_C(    25322536) },
      {  INT32_C(   383456590), -INT32_C(  2040656367),  INT32_C(   975235280), -INT32_C(  2100204167) },
      { -INT32_C(   627902950),  INT32_C(  1194526742), -INT32_C(  1702196851), -INT32_C(  1756580470) } },
    { {  INT32_C(   365745033), -INT32_C(   136919301), -INT32_C(   703396434), -INT32_C(  1210542743) },
      { -INT32_C(  1144147030), -INT32_C(  1857934399), -INT32_C(  1915985388),  INT32_C(  1494195663) },
      {  INT32_C(  1802427248),  INT32_C(  1331840417), -INT32_C(  1289325238), -INT32_C(  1251279349) },
      {  INT32_C(   365800009), -INT32_C(   136916746), -INT32_C(   703386593), -INT32_C(  1210545865) } },
    { {  INT32_C(  1936799665),  INT32_C(  1996796771), -INT32_C(   452669419), -INT32_C(   566357138) },
      { -INT32_C(  1890931474),  INT32_C(  1004449009),  INT32_C(   770573346), -INT32_C(  1260234750) },
      { -INT32_C(   215526512),  INT32_C(   476719878),  INT32_C(  1778478844),  INT32_C(  1867005825) },
      {  INT32_C(  1936788312),  INT32_C(  1996830797), -INT32_C(   452664107), -INT32_C(   566315596) } },
    { { -INT32_C(   570518805),  INT32_C(  1629019199), -INT32_C(   477231135), -INT32_C(   275287969) },
      { -INT32_C(   891109692), -INT32_C(   421114646),  INT32_C(   995157946),  INT32_C(   313169958) },
      {  INT32_C(  1794091051),  INT32_C(  1724581765),  INT32_C(  1850300686), -INT32_C(  1923227191) },
      { -INT32_C(   570509527),  INT32_C(  1629002219), -INT32_C(   477195642), -INT32_C(   275281031) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_dpbusd_epi32(src, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_dpbusd_epi32(src, a, b);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_dpbusd_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
