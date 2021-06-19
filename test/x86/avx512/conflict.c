#define SIMDE_TEST_X86_AVX512_INSN conflict

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/conflict.h>

static int
test_simde_mm_conflict_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1541612005),  INT32_C(           0), -INT32_C(   452408368), -INT32_C(  1876308071) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           3),  INT32_C(           7) } },
    { {  INT32_C(           0),  INT32_C(  2003804893), -INT32_C(  1362424684),  INT32_C(    42207387) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1122030031),  INT32_C(           0),  INT32_C(   519959946),  INT32_C(   652835466) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           3),  INT32_C(           7) } },
    { {  INT32_C(   434925335),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           6) } },
    { {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   191370707) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           3),  INT32_C(           0) } },
    { { -INT32_C(   910903619), -INT32_C(   789467214),  INT32_C(   552321512), -INT32_C(   150677719) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_conflict_epi32(a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int a_[4] = {0, 0, 0, 0};
    for (int j = 0 ; j < 4 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i32();
      }
    }
    simde__m128i a = simde_mm_set_epi32(a_[3], a_[2], a_[1], a_[0]);
    simde__m128i r = simde_mm_conflict_epi32(a);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_conflict_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
