#define SIMDE_TEST_X86_AVX512_INSN bitshuffle

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/bitshuffle.h>

static int
test_simde_mm_bitshuffle_epi64_mask (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t b[2];
    const int64_t c[2];
    const simde__mmask16 r;
  } test_vec[] = {
    { { -INT64_C( 5804274169211770984),  INT64_C( 1811127749735916979) },
      { -INT64_C( 3307710871945461515), -INT64_C( 6257706525836889001) },
      UINT16_C(59753) },
    { {  INT64_C( 1685571549138473296), -INT64_C( 6831978591596756737) },
      {  INT64_C( 3061993457926679855), -INT64_C( 3435932602296084586) },
      UINT16_C(40744) },
    { { -INT64_C( 7932269877341570962), -INT64_C( 2992686315798481109) },
      { -INT64_C( 5115244597806448379), -INT64_C( 8887939532714805161) },
      UINT16_C(32071) },
    { {  INT64_C( 4831588449147825642), -INT64_C( 7893524209444735497) },
      {  INT64_C( 5561784970141955666),  INT64_C( 3242533743124320357) },
      UINT16_C(53889) },
    { { -INT64_C( 8262778660660423175),  INT64_C( 5875684581292338539) },
      { -INT64_C( 3974155768042097259), -INT64_C( 4470312149981070201) },
      UINT16_C(38645) },
    { { -INT64_C( 4559008054794609001),  INT64_C( 2009524104003643027) },
      {  INT64_C( 2837971042963008056),  INT64_C( 9152976798180550012) },
      UINT16_C(15722) },
    { { -INT64_C( 8026989045841340539), -INT64_C( 3607658635433192882) },
      { -INT64_C( 7892617624756382033), -INT64_C( 3037999764792252304) },
      UINT16_C(33764) },
    { {  INT64_C( 4053039461975425970),  INT64_C( 1729096827091575451) },
      { -INT64_C( 6828901580093823342), -INT64_C( 7103355376489721785) },
      UINT16_C(54687) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i c = simde_x_mm_loadu_epi64(test_vec[i].c);
    simde__mmask16 r = simde_mm_bitshuffle_epi64_mask(b, c);
    simde_assert_equal_mmask16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i c = simde_test_x86_random_i64x2();
    simde__mmask16 r = simde_mm_bitshuffle_epi64_mask(b, c);

    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_mmask16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_bitshuffle_epi64_mask)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
