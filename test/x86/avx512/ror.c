#define SIMDE_TEST_X86_AVX512_INSN ror

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/ror.h>

static int
test_simde_mm_ror_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    int imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   151286297),  INT32_C(   644597991),  INT32_C(   746973119), -INT32_C(  2023297337) },
       INT32_C(          92),
      {  INT32_C(  1874386559),  INT32_C(  1723633266), -INT32_C(   933331982),  INT32_C(  1986980984) } },
    { { -INT32_C(  1723844743), -INT32_C(   766494864),  INT32_C(   320937772), -INT32_C(  1828119380) },
       INT32_C(         228),
      { -INT32_C(  1718353033),  INT32_C(   220529527), -INT32_C(  1053683214), -INT32_C(   919563830) } },
    { {  INT32_C(   584007515), -INT32_C(  1985333971),  INT32_C(   321118361), -INT32_C(  2018745321) },
       INT32_C(         155),
      {  INT32_C(  1508371300),  INT32_C(   893822385),  INT32_C(  1685852962), -INT32_C(   175340816) } },
    { { -INT32_C(   925140197),  INT32_C(  2069620119), -INT32_C(  1256319655), -INT32_C(  2099778220) },
       INT32_C(          34),
      { -INT32_C(   231285050), -INT32_C(   556336795),  INT32_C(  1833403734),  INT32_C(   548797269) } },
    { {  INT32_C(  2026778465),  INT32_C(   771783315), -INT32_C(  1829348746),  INT32_C(  1817891541) },
       INT32_C(         183),
      { -INT32_C(  1671511311),  INT32_C(    16066140), -INT32_C(   323687131), -INT32_C(  1247434024) } },
    { {  INT32_C(   533005771),  INT32_C(   346136050), -INT32_C(  2133873378),  INT32_C(  1878564572) },
       INT32_C(          24),
      { -INT32_C(   989476065), -INT32_C(  1583484396), -INT32_C(   810738048), -INT32_C(   123806609) } },
    { {  INT32_C(   656512082),  INT32_C(   496204646), -INT32_C(    80905680),  INT32_C(  1897657215) },
       INT32_C(         144),
      { -INT32_C(  1806555359),  INT32_C(  2070289811),  INT32_C(  2050030381), -INT32_C(   209751781) } },
    { {  INT32_C(  1160664425),  INT32_C(   196356083),  INT32_C(  1922716191),  INT32_C(  1285143526) },
       INT32_C(          54),
      { -INT32_C(  1185569516), -INT32_C(   794833874),  INT32_C(  1766358474),  INT32_C(  1726978354) } },
  };

  simde__m128i a, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  r = simde_mm_ror_epi32(a, INT32_C(          92));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  r = simde_mm_ror_epi32(a, INT32_C(         228));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  r = simde_mm_ror_epi32(a, INT32_C(         155));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  r = simde_mm_ror_epi32(a, INT32_C(          34));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  r = simde_mm_ror_epi32(a, INT32_C(         183));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  r = simde_mm_ror_epi32(a, INT32_C(          24));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  r = simde_mm_ror_epi32(a, INT32_C(         144));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  r = simde_mm_ror_epi32(a, INT32_C(          54));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_ror_epi32, r, simde_mm_setzero_si128(), imm8, a);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ror_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
