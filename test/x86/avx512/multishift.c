#define SIMDE_TEST_X86_AVX512_INSN multishift

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/multishift.h>

static int
test_simde_mm_multishift_epi64_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t b[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 5944759368420685759),  INT64_C( 7528678319989171196) },
      {  INT64_C( 7075844600884306077), -INT64_C( 2565661876566908370) },
      {  INT64_C( 7250023321283445818), -INT64_C( 1091147691208801299) } },
    { {  INT64_C( 5359135457743030247),  INT64_C( 6670079259268514332) },
      { -INT64_C( 4138983330115935231), -INT64_C( 2379294822119307518) },
      {  INT64_C( 5273402577707550913),  INT64_C( 8189790446477623409) } },
    { { -INT64_C( 8364510043903888046),  INT64_C( 3740031899925696972) },
      {  INT64_C( 8630568650511816039), -INT64_C( 3905585733035397897) },
      {  INT64_C( 2503514409926573784),  INT64_C( 4117590180061858678) } },
    { { -INT64_C( 3638534656532826233), -INT64_C( 2374733495049636699) },
      {  INT64_C( 6071313391608032341), -INT64_C(  986552838882404337) },
      { -INT64_C(  924736376198289192), -INT64_C( 2928729660537297797) } },
    { { -INT64_C( 5578437055502305082), -INT64_C( 8938355335261131107) },
      { -INT64_C( 8885163955097579007), -INT64_C( 3907900703707040665) },
      {  INT64_C( 3236618561012008008), -INT64_C( 8314612406915624674) } },
    { { -INT64_C( 5417505900794368751), -INT64_C( 1024923025553138923) },
      {  INT64_C(  614742040698033039), -INT64_C(  234011344798838028) },
      { -INT64_C( 8635932585716400089),  INT64_C( 6938824095551815358) } },
    { { -INT64_C( 8208113264754994612),  INT64_C( 3109902239906520903) },
      {  INT64_C( 7661950584759482026),  INT64_C( 1815270389549444681) },
      { -INT64_C( 4815391206839563273),  INT64_C( 2603758790863002204) } },
    { {  INT64_C( 9186096638152428660), -INT64_C( 8270052698926723982) },
      {  INT64_C( 7653071665451526484),  INT64_C( 3261398573838735195) },
      { -INT64_C( 6301109365654518109), -INT64_C(  230840166318212784) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_multishift_epi64_epi8(a, b);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_multishift_epi64_epi8(a, b);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_multishift_epi64_epi8)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
