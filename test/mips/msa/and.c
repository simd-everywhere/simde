#define SIMDE_TEST_MIPS_MSA_INSN and

#include "test-msa.h"
#include "../../../simde/mips/msa/and.h"

static int
test_simde_and_v (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(  4), UINT8_C(166), UINT8_C(206), UINT8_C(113), UINT8_C(106), UINT8_C(124), UINT8_C(117), UINT8_C( 15),
        UINT8_C(161), UINT8_C( 59), UINT8_C(172), UINT8_C(152), UINT8_C( 68), UINT8_C(  9), UINT8_C(246), UINT8_C(112) },
      { UINT8_C( 82), UINT8_C(177), UINT8_C( 43), UINT8_C(254), UINT8_C(120), UINT8_C(241), UINT8_C( 32), UINT8_C( 34),
        UINT8_C(198), UINT8_C(158), UINT8_C(232), UINT8_C(  3), UINT8_C( 18), UINT8_C(230), UINT8_C(120), UINT8_C( 23) },
      { UINT8_C(  0), UINT8_C(160), UINT8_C( 10), UINT8_C(112), UINT8_C(104), UINT8_C(112), UINT8_C( 32), UINT8_C(  2),
        UINT8_C(128), UINT8_C( 26), UINT8_C(168), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(112), UINT8_C( 16) } },
    { { UINT8_C(140), UINT8_C( 70), UINT8_C(136), UINT8_C(246), UINT8_C(194), UINT8_C(254), UINT8_C(  6), UINT8_C( 99),
        UINT8_C( 57), UINT8_C(178), UINT8_C(251), UINT8_C(125), UINT8_C(187), UINT8_C(241), UINT8_C(238), UINT8_C( 14) },
      { UINT8_C(163), UINT8_C( 25), UINT8_C( 12), UINT8_C( 27), UINT8_C( 10), UINT8_C( 45), UINT8_C( 62), UINT8_C(208),
        UINT8_C(203), UINT8_C( 38), UINT8_C(212), UINT8_C(221), UINT8_C( 12), UINT8_C( 76), UINT8_C(244), UINT8_C(152) },
      { UINT8_C(128), UINT8_C(  0), UINT8_C(  8), UINT8_C( 18), UINT8_C(  2), UINT8_C( 44), UINT8_C(  6), UINT8_C( 64),
        UINT8_C(  9), UINT8_C( 34), UINT8_C(208), UINT8_C( 93), UINT8_C(  8), UINT8_C( 64), UINT8_C(228), UINT8_C(  8) } },
    { { UINT8_C(146), UINT8_C(125), UINT8_C(143), UINT8_C( 85), UINT8_C(123), UINT8_C(149), UINT8_C(184), UINT8_C(180),
        UINT8_C( 71), UINT8_C(180), UINT8_C( 50), UINT8_C(  2), UINT8_C(165), UINT8_C( 32), UINT8_C( 16), UINT8_C( 72) },
      { UINT8_C( 57), UINT8_C( 29), UINT8_C(100), UINT8_C( 67), UINT8_C( 74), UINT8_C(162), UINT8_C( 20), UINT8_C( 21),
        UINT8_C(200), UINT8_C(232), UINT8_C(242), UINT8_C(213), UINT8_C( 52), UINT8_C(231), UINT8_C(109), UINT8_C(198) },
      { UINT8_C( 16), UINT8_C( 29), UINT8_C(  4), UINT8_C( 65), UINT8_C( 74), UINT8_C(128), UINT8_C( 16), UINT8_C( 20),
        UINT8_C( 64), UINT8_C(160), UINT8_C( 50), UINT8_C(  0), UINT8_C( 36), UINT8_C( 32), UINT8_C(  0), UINT8_C( 64) } },
    { { UINT8_C(100), UINT8_C(252), UINT8_C( 27), UINT8_C(223), UINT8_C(145), UINT8_C(212), UINT8_C(147), UINT8_C(216),
        UINT8_C(136), UINT8_C(197), UINT8_C(219), UINT8_C( 45), UINT8_C(229), UINT8_C(235), UINT8_C(118), UINT8_C( 30) },
      { UINT8_C(  8), UINT8_C(218), UINT8_C( 98), UINT8_C( 82), UINT8_C(124), UINT8_C(118), UINT8_C(103), UINT8_C( 68),
        UINT8_C( 94), UINT8_C( 90), UINT8_C( 25), UINT8_C(146), UINT8_C( 65), UINT8_C(135), UINT8_C( 88), UINT8_C(165) },
      { UINT8_C(  0), UINT8_C(216), UINT8_C(  2), UINT8_C( 82), UINT8_C( 16), UINT8_C( 84), UINT8_C(  3), UINT8_C( 64),
        UINT8_C(  8), UINT8_C( 64), UINT8_C( 25), UINT8_C(  0), UINT8_C( 65), UINT8_C(131), UINT8_C( 80), UINT8_C(  4) } },
    { { UINT8_C(131), UINT8_C(116), UINT8_C(132), UINT8_C( 21), UINT8_C( 72), UINT8_C( 23), UINT8_C(237), UINT8_C(208),
        UINT8_C(221), UINT8_C(200), UINT8_C(253), UINT8_C(194), UINT8_C(180), UINT8_C(115), UINT8_C(225), UINT8_C(188) },
      { UINT8_C( 77), UINT8_C( 67), UINT8_C( 15), UINT8_C(201), UINT8_C(185), UINT8_C(118), UINT8_C( 14), UINT8_C( 23),
        UINT8_C(208), UINT8_C( 39), UINT8_C(169), UINT8_C( 17), UINT8_C(174), UINT8_C(  1), UINT8_C(182), UINT8_C( 50) },
      { UINT8_C(  1), UINT8_C( 64), UINT8_C(  4), UINT8_C(  1), UINT8_C(  8), UINT8_C( 22), UINT8_C( 12), UINT8_C( 16),
        UINT8_C(208), UINT8_C(  0), UINT8_C(169), UINT8_C(  0), UINT8_C(164), UINT8_C(  1), UINT8_C(160), UINT8_C( 48) } },
    { { UINT8_C(117), UINT8_C( 58), UINT8_C( 71), UINT8_C(189), UINT8_C( 82), UINT8_C( 52), UINT8_C(141), UINT8_C( 47),
        UINT8_C(253), UINT8_C(139), UINT8_C(241), UINT8_C(177), UINT8_C(254), UINT8_C(210), UINT8_C(109), UINT8_C( 76) },
      { UINT8_C( 21), UINT8_C(124), UINT8_C( 21), UINT8_C(206), UINT8_C(243), UINT8_C( 35), UINT8_C(229), UINT8_C(195),
        UINT8_C( 75), UINT8_C(142), UINT8_C(213), UINT8_C(249), UINT8_C(144), UINT8_C(139), UINT8_C( 43), UINT8_C(  5) },
      { UINT8_C( 21), UINT8_C( 56), UINT8_C(  5), UINT8_C(140), UINT8_C( 82), UINT8_C( 32), UINT8_C(133), UINT8_C(  3),
        UINT8_C( 73), UINT8_C(138), UINT8_C(209), UINT8_C(177), UINT8_C(144), UINT8_C(130), UINT8_C( 41), UINT8_C(  4) } },
    { { UINT8_C(198), UINT8_C(114), UINT8_C(195), UINT8_C( 24), UINT8_C(167), UINT8_C( 80), UINT8_C( 71), UINT8_C(164),
        UINT8_C(219), UINT8_C( 56), UINT8_C( 85), UINT8_C(218), UINT8_C( 11), UINT8_C(194), UINT8_C( 38), UINT8_C( 32) },
      { UINT8_C( 63), UINT8_C( 59), UINT8_C(239), UINT8_C( 50), UINT8_C( 95), UINT8_C(212), UINT8_C(245), UINT8_C(170),
        UINT8_C( 99), UINT8_C(202), UINT8_C(163), UINT8_C(243), UINT8_C( 86), UINT8_C(207), UINT8_C(248), UINT8_C( 28) },
      { UINT8_C(  6), UINT8_C( 50), UINT8_C(195), UINT8_C( 16), UINT8_C(  7), UINT8_C( 80), UINT8_C( 69), UINT8_C(160),
        UINT8_C( 67), UINT8_C(  8), UINT8_C(  1), UINT8_C(210), UINT8_C(  2), UINT8_C(194), UINT8_C( 32), UINT8_C(  0) } },
    { { UINT8_C( 65), UINT8_C(187), UINT8_C( 52), UINT8_C(232), UINT8_C( 12), UINT8_C(123), UINT8_C(140), UINT8_C(231),
        UINT8_C(179), UINT8_C(225), UINT8_C(193), UINT8_C(190), UINT8_C(164), UINT8_C(231), UINT8_C(223), UINT8_C(227) },
      { UINT8_C( 35), UINT8_C(206), UINT8_C( 21), UINT8_C(130), UINT8_C(162), UINT8_C( 10), UINT8_C( 44), UINT8_C(  5),
        UINT8_C(213), UINT8_C(207), UINT8_C(248), UINT8_C( 43), UINT8_C(158), UINT8_C(241), UINT8_C( 71), UINT8_C(224) },
      { UINT8_C(  1), UINT8_C(138), UINT8_C( 20), UINT8_C(128), UINT8_C(  0), UINT8_C( 10), UINT8_C( 12), UINT8_C(  5),
        UINT8_C(145), UINT8_C(193), UINT8_C(192), UINT8_C( 42), UINT8_C(132), UINT8_C(225), UINT8_C( 71), UINT8_C(224) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v16u8 a = simde_x_msa_ld_u_b(test_vec[i].a, 0);
    simde_v16u8 b = simde_x_msa_ld_u_b(test_vec[i].b, 0);
    simde_v16u8 r = simde_msa_and_v(a, b);

    simde_test_msa_v16u8_assert_equal(r, simde_x_msa_ld_u_b(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v16u8 a = simde_test_msa_v16u8_random();
    simde_v16u8 b = simde_test_msa_v16u8_random();
    simde_v16u8 r = simde_msa_and_v(a, b);

    simde_test_msa_v16u8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v16u8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v16u8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(and_v)
SIMDE_TEST_FUNC_LIST_END

#include "test-msa-footer.h"
