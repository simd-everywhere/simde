#define SIMDE_TEST_X86_AVX512_INSN align

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/setzero.h>
#include <simde/x86/avx512/align.h>
#include <stdio.h>

static int
test_simde_mm512_alignr_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i b;
    const simde__mmask8 imm8;
    simde__m512i r;
  } test_vec[] = {
    { simde_mm512_set_epi32(INT32_C(168), INT32_C( 54), INT32_C( 25), INT32_C( 16),
                            INT32_C( 42), INT32_C( 64), INT32_C(892), INT32_C( 79),
                            INT32_C( 35), INT32_C( 14), INT32_C(522), INT32_C( 49),
                            INT32_C( 42), INT32_C( 64), INT32_C(  7), INT32_C( 19)),
      simde_mm512_set_epi32(INT32_C(  1), INT32_C(  2), INT32_C(  3), INT32_C(  4),
                            INT32_C(  5), INT32_C(  6), INT32_C(  7), INT32_C(  8),
                            INT32_C(  9), INT32_C( 10), INT32_C( 11), INT32_C( 12),
                            INT32_C( 13), INT32_C( 14), INT32_C( 15), INT32_C( 16)),
      1,
      simde_mm512_set_epi32(INT32_C( 19), INT32_C(  1), INT32_C(  2), INT32_C(  3),
                            INT32_C(  4), INT32_C(  5), INT32_C(  6), INT32_C(  7),
                            INT32_C(  8), INT32_C(  9), INT32_C( 10), INT32_C( 11),
                            INT32_C( 12), INT32_C( 13), INT32_C( 14), INT32_C( 15)),
    },
    { simde_mm512_set_epi32(INT32_C(168), INT32_C( 54), INT32_C( 25), INT32_C( 16),
                            INT32_C( 42), INT32_C( 64), INT32_C(892), INT32_C( 79),
                            INT32_C( 35), INT32_C( 14), INT32_C(522), INT32_C( 49),
                            INT32_C( 42), INT32_C( 64), INT32_C(  7), INT32_C( 19)),
      simde_mm512_set_epi32(INT32_C(  1), INT32_C(  2), INT32_C(  3), INT32_C(  4),
                            INT32_C(  5), INT32_C(  6), INT32_C(  7), INT32_C(  8),
                            INT32_C(  9), INT32_C( 10), INT32_C( 11), INT32_C( 12),
                            INT32_C( 13), INT32_C( 14), INT32_C( 15), INT32_C( 16)),
      17,
      simde_mm512_set_epi32(INT32_C( 19), INT32_C(  1), INT32_C(  2), INT32_C(  3),
                            INT32_C(  4), INT32_C(  5), INT32_C(  6), INT32_C(  7),
                            INT32_C(  8), INT32_C(  9), INT32_C( 10), INT32_C( 11),
                            INT32_C( 12), INT32_C( 13), INT32_C( 14), INT32_C( 15)),
    },
    {
      simde_mm512_set_epi32(INT32_C(8642), INT32_C(7802), INT32_C(1252), INT32_C(1585),
                            INT32_C(3509), INT32_C(5362), INT32_C(8605), INT32_C(5927),
                            INT32_C(6701), INT32_C(3014), INT32_C(2816), INT32_C(2818),
                            INT32_C(6544), INT32_C(9829), INT32_C(7991), INT32_C(1111)),
      simde_mm512_set_epi32(INT32_C(4513), INT32_C(3854), INT32_C(4402), INT32_C(6551),
                            INT32_C(5642), INT32_C(3525), INT32_C(3873), INT32_C(5884),
                            INT32_C(3443), INT32_C(1354), INT32_C(1070), INT32_C(5500),
                            INT32_C(2349), INT32_C(1754), INT32_C(8819), INT32_C( 716)),
      4,
      simde_mm512_set_epi32(INT32_C(6544), INT32_C(9829), INT32_C(7991), INT32_C(1111),
                            INT32_C(4513), INT32_C(3854), INT32_C(4402), INT32_C(6551),
                            INT32_C(5642), INT32_C(3525), INT32_C(3873), INT32_C(5884),
                            INT32_C(3443), INT32_C(1354), INT32_C(1070), INT32_C(5500)),
    }
  };

  simde__m512i r = simde_mm512_alignr_epi32(test_vec[0].a, test_vec[0].b, 1);
  simde_assert_m512i_i32(r, ==, test_vec[0].r);

  r = simde_mm512_alignr_epi32(test_vec[1].a, test_vec[1].b, 17);
  simde_assert_m512i_i32(r, ==, test_vec[1].r);

  r = simde_mm512_alignr_epi32(test_vec[2].a, test_vec[2].b, 4);
  simde_assert_m512i_i32(r, ==, test_vec[2].r);

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_alignr_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
