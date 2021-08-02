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

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_dpwssds_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
