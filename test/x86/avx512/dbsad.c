#define SIMDE_TEST_X86_AVX512_INSN dbsad

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/dbsad.h>

static int
test_simde_mm_dbsad_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint8_t a[16];
    const uint8_t b[16];
    const int imm8;
    const int64_t r[2];
  } test_vec[] = {
    { { UINT8_C(  0), UINT8_C( 71), UINT8_C( 67), UINT8_C(102), UINT8_C(109), UINT8_C( 53), UINT8_C( 10), UINT8_C(151),
        UINT8_C( 11), UINT8_C(165), UINT8_C(142), UINT8_C(142), UINT8_C(107), UINT8_C(188), UINT8_C( 42), UINT8_C( 27) },
      { UINT8_C(161), UINT8_C(166), UINT8_C(  0), UINT8_C( 12), UINT8_C(113), UINT8_C(146), UINT8_C(120), UINT8_C(115),
        UINT8_C(162), UINT8_C( 68), UINT8_C( 17), UINT8_C(216), UINT8_C( 31), UINT8_C( 65), UINT8_C(184), UINT8_C( 31) },
       INT32_C(         136),
      {  INT64_C(  112028694316319133),  INT64_C(   44193478339854759) } },
    { { UINT8_C( 49), UINT8_C(144), UINT8_C(141), UINT8_C( 60), UINT8_C( 53), UINT8_C( 27), UINT8_C(202), UINT8_C(160),
        UINT8_C(215), UINT8_C(244), UINT8_C(188), UINT8_C(121), UINT8_C(155), UINT8_C(188), UINT8_C(133), UINT8_C( 12) },
      { UINT8_C( 78), UINT8_C(254), UINT8_C(127), UINT8_C(240), UINT8_C( 66), UINT8_C(144), UINT8_C(200), UINT8_C( 97),
        UINT8_C(210), UINT8_C(129), UINT8_C(129), UINT8_C( 90), UINT8_C(124), UINT8_C(  7), UINT8_C( 80), UINT8_C(173) },
       INT32_C(         151),
      {  INT64_C(   72340464888447362),  INT64_C(   56577887677382941) } },
    { { UINT8_C(249), UINT8_C(179), UINT8_C(109), UINT8_C(209), UINT8_C(168), UINT8_C( 41), UINT8_C( 74), UINT8_C( 67),
        UINT8_C(229), UINT8_C(207), UINT8_C( 79), UINT8_C( 52), UINT8_C(205), UINT8_C(207), UINT8_C( 36), UINT8_C( 16) },
      { UINT8_C( 95), UINT8_C(237), UINT8_C(113), UINT8_C( 49), UINT8_C(110), UINT8_C(242), UINT8_C(140), UINT8_C(234),
        UINT8_C(249), UINT8_C(220), UINT8_C(152), UINT8_C(145), UINT8_C(186), UINT8_C(129), UINT8_C( 94), UINT8_C(180) },
       INT32_C(          53),
      {  INT64_C(  105836446686773506),  INT64_C(  122443410188861704) } },
    { { UINT8_C(245), UINT8_C(207), UINT8_C( 32), UINT8_C(218), UINT8_C(158), UINT8_C(111), UINT8_C( 14), UINT8_C(108),
        UINT8_C( 62), UINT8_C( 51), UINT8_C(124), UINT8_C(158), UINT8_C( 32), UINT8_C(237), UINT8_C(207), UINT8_C(142) },
      { UINT8_C(224), UINT8_C( 91), UINT8_C(120), UINT8_C(217), UINT8_C( 56), UINT8_C( 16), UINT8_C(106), UINT8_C(242),
        UINT8_C(146), UINT8_C(200), UINT8_C(166), UINT8_C(199), UINT8_C(148), UINT8_C( 43), UINT8_C(164), UINT8_C(137) },
       INT32_C(         250),
      {  INT64_C(   90073366958244099),  INT64_C(  106962166197452955) } },
    { { UINT8_C( 51), UINT8_C(114), UINT8_C(  5), UINT8_C(114), UINT8_C(165), UINT8_C(129), UINT8_C( 16), UINT8_C(197),
        UINT8_C(110), UINT8_C(223), UINT8_C( 83), UINT8_C( 78), UINT8_C( 59), UINT8_C(203), UINT8_C( 40), UINT8_C(115) },
      { UINT8_C(220), UINT8_C(146), UINT8_C(101), UINT8_C(110), UINT8_C( 91), UINT8_C( 12), UINT8_C( 53), UINT8_C(239),
        UINT8_C( 55), UINT8_C(217), UINT8_C(120), UINT8_C( 50), UINT8_C(157), UINT8_C(219), UINT8_C(203), UINT8_C(208) },
       INT32_C(          77),
      {  INT64_C(   87540371344130363),  INT64_C(   71214410366320877) } },
    { { UINT8_C( 81), UINT8_C( 82), UINT8_C(183), UINT8_C(191), UINT8_C( 50), UINT8_C( 10), UINT8_C( 14), UINT8_C(109),
        UINT8_C(214), UINT8_C( 54), UINT8_C(224), UINT8_C(178), UINT8_C(200), UINT8_C( 69), UINT8_C( 32), UINT8_C( 35) },
      { UINT8_C( 81), UINT8_C( 85), UINT8_C( 18), UINT8_C(137), UINT8_C( 46), UINT8_C(138), UINT8_C(187), UINT8_C(203),
        UINT8_C(102), UINT8_C(134), UINT8_C(155), UINT8_C(179), UINT8_C( 86), UINT8_C(222), UINT8_C(166), UINT8_C(167) },
       INT32_C(          48),
      {  INT64_C(   90073066303914206),  INT64_C(   32370614477128045) } },
    { { UINT8_C(104), UINT8_C(116), UINT8_C(207), UINT8_C( 62), UINT8_C(170), UINT8_C(175), UINT8_C(240), UINT8_C(115),
        UINT8_C(245), UINT8_C( 16), UINT8_C(150), UINT8_C( 70), UINT8_C(101), UINT8_C(169), UINT8_C(207), UINT8_C(147) },
      { UINT8_C( 51), UINT8_C(138), UINT8_C( 94), UINT8_C(153), UINT8_C( 16), UINT8_C(249), UINT8_C( 77), UINT8_C(102),
        UINT8_C(215), UINT8_C(243), UINT8_C( 13), UINT8_C(  8), UINT8_C( 80), UINT8_C(116), UINT8_C(106), UINT8_C(184) },
       INT32_C(         232),
      {  INT64_C(   45600024281153815),  INT64_C(   88384890749125064) } },
    { { UINT8_C(233), UINT8_C(230), UINT8_C(  6), UINT8_C(222), UINT8_C(246), UINT8_C(156), UINT8_C( 37), UINT8_C( 91),
        UINT8_C( 69), UINT8_C(244), UINT8_C(238), UINT8_C(121), UINT8_C(127), UINT8_C( 76), UINT8_C( 18), UINT8_C(143) },
      { UINT8_C( 70), UINT8_C( 95), UINT8_C(246), UINT8_C( 29), UINT8_C( 82), UINT8_C(  3), UINT8_C( 37), UINT8_C(163),
        UINT8_C(119), UINT8_C(144), UINT8_C( 91), UINT8_C( 96), UINT8_C(202), UINT8_C( 82), UINT8_C(243), UINT8_C(179) },
       INT32_C(          56),
      {  INT64_C(  101613591892329179),  INT64_C(   66992414559830374) } },
  };

  simde__m128i a, b, r;

  a = simde_x_mm_loadu_epi8(test_vec[0].a);
  b = simde_x_mm_loadu_epi8(test_vec[0].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(         136));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[0].r));

  a = simde_x_mm_loadu_epi8(test_vec[1].a);
  b = simde_x_mm_loadu_epi8(test_vec[1].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(         151));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[1].r));

  a = simde_x_mm_loadu_epi8(test_vec[2].a);
  b = simde_x_mm_loadu_epi8(test_vec[2].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(          53));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[2].r));

  a = simde_x_mm_loadu_epi8(test_vec[3].a);
  b = simde_x_mm_loadu_epi8(test_vec[3].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(         250));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[3].r));

  a = simde_x_mm_loadu_epi8(test_vec[4].a);
  b = simde_x_mm_loadu_epi8(test_vec[4].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(          77));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[4].r));

  a = simde_x_mm_loadu_epi8(test_vec[5].a);
  b = simde_x_mm_loadu_epi8(test_vec[5].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(          48));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[5].r));

  a = simde_x_mm_loadu_epi8(test_vec[6].a);
  b = simde_x_mm_loadu_epi8(test_vec[6].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(         232));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[6].r));

  a = simde_x_mm_loadu_epi8(test_vec[7].a);
  b = simde_x_mm_loadu_epi8(test_vec[7].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(          56));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_u8x16();
    simde__m128i b = simde_test_x86_random_u8x16();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_dbsad_epu8, r, simde_mm_setzero_si128(), imm8, a, b);

    simde_test_x86_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_dbsad_epu8)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
