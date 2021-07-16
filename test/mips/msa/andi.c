#define SIMDE_TEST_MIPS_MSA_INSN andi

#include "test-msa.h"
#include "../../../simde/mips/msa/andi.h"

static int
test_simde_andi_b (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t    a[16];
    uint8_t  r43[16];
    uint8_t  r13[16];
    uint8_t r161[16];
  } test_vec[] = {
    { { UINT8_C(112), UINT8_C( 96), UINT8_C(174), UINT8_C(211), UINT8_C( 64), UINT8_C(113), UINT8_C(100), UINT8_C( 91),
        UINT8_C(206), UINT8_C(229), UINT8_C(168), UINT8_C( 89), UINT8_C(  3), UINT8_C(203), UINT8_C(194), UINT8_C(209) },
      { UINT8_C( 32), UINT8_C( 32), UINT8_C( 42), UINT8_C(  3), UINT8_C(  0), UINT8_C( 33), UINT8_C( 32), UINT8_C( 11),
        UINT8_C( 10), UINT8_C( 33), UINT8_C( 40), UINT8_C(  9), UINT8_C(  3), UINT8_C( 11), UINT8_C(  2), UINT8_C(  1) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C( 12), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  4), UINT8_C(  9),
        UINT8_C( 12), UINT8_C(  5), UINT8_C(  8), UINT8_C(  9), UINT8_C(  1), UINT8_C(  9), UINT8_C(  0), UINT8_C(  1) },
      { UINT8_C( 32), UINT8_C( 32), UINT8_C(160), UINT8_C(129), UINT8_C(  0), UINT8_C( 33), UINT8_C( 32), UINT8_C(  1),
        UINT8_C(128), UINT8_C(161), UINT8_C(160), UINT8_C(  1), UINT8_C(  1), UINT8_C(129), UINT8_C(128), UINT8_C(129) } },
    { { UINT8_C(141), UINT8_C(121), UINT8_C( 20), UINT8_C(133), UINT8_C(205), UINT8_C(177), UINT8_C(104), UINT8_C( 42),
        UINT8_C( 75), UINT8_C(131), UINT8_C( 40), UINT8_C(252), UINT8_C(190), UINT8_C(105), UINT8_C(132), UINT8_C( 47) },
      { UINT8_C(  9), UINT8_C( 41), UINT8_C(  0), UINT8_C(  1), UINT8_C(  9), UINT8_C( 33), UINT8_C( 40), UINT8_C( 42),
        UINT8_C( 11), UINT8_C(  3), UINT8_C( 40), UINT8_C( 40), UINT8_C( 42), UINT8_C( 41), UINT8_C(  0), UINT8_C( 43) },
      { UINT8_C( 13), UINT8_C(  9), UINT8_C(  4), UINT8_C(  5), UINT8_C( 13), UINT8_C(  1), UINT8_C(  8), UINT8_C(  8),
        UINT8_C(  9), UINT8_C(  1), UINT8_C(  8), UINT8_C( 12), UINT8_C( 12), UINT8_C(  9), UINT8_C(  4), UINT8_C( 13) },
      { UINT8_C(129), UINT8_C( 33), UINT8_C(  0), UINT8_C(129), UINT8_C(129), UINT8_C(161), UINT8_C( 32), UINT8_C( 32),
        UINT8_C(  1), UINT8_C(129), UINT8_C( 32), UINT8_C(160), UINT8_C(160), UINT8_C( 33), UINT8_C(128), UINT8_C( 33) } },
    { { UINT8_C(201), UINT8_C( 50), UINT8_C(  2), UINT8_C(  9), UINT8_C(164), UINT8_C(102), UINT8_C(100), UINT8_C(114),
        UINT8_C( 76), UINT8_C( 12), UINT8_C(203), UINT8_C( 79), UINT8_C(215), UINT8_C(142), UINT8_C( 32), UINT8_C(100) },
      { UINT8_C(  9), UINT8_C( 34), UINT8_C(  2), UINT8_C(  9), UINT8_C( 32), UINT8_C( 34), UINT8_C( 32), UINT8_C( 34),
        UINT8_C(  8), UINT8_C(  8), UINT8_C( 11), UINT8_C( 11), UINT8_C(  3), UINT8_C( 10), UINT8_C( 32), UINT8_C( 32) },
      { UINT8_C(  9), UINT8_C(  0), UINT8_C(  0), UINT8_C(  9), UINT8_C(  4), UINT8_C(  4), UINT8_C(  4), UINT8_C(  0),
        UINT8_C( 12), UINT8_C( 12), UINT8_C(  9), UINT8_C( 13), UINT8_C(  5), UINT8_C( 12), UINT8_C(  0), UINT8_C(  4) },
      { UINT8_C(129), UINT8_C( 32), UINT8_C(  0), UINT8_C(  1), UINT8_C(160), UINT8_C( 32), UINT8_C( 32), UINT8_C( 32),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(129), UINT8_C(  1), UINT8_C(129), UINT8_C(128), UINT8_C( 32), UINT8_C( 32) } },
    { { UINT8_C(  7), UINT8_C( 53), UINT8_C(234), UINT8_C(212), UINT8_C(230), UINT8_C( 82),    UINT8_MAX, UINT8_C( 49),
        UINT8_C(214), UINT8_C( 39), UINT8_C( 45), UINT8_C(148), UINT8_C(144), UINT8_C(177), UINT8_C(195), UINT8_C( 89) },
      { UINT8_C(  3), UINT8_C( 33), UINT8_C( 42), UINT8_C(  0), UINT8_C( 34), UINT8_C(  2), UINT8_C( 43), UINT8_C( 33),
        UINT8_C(  2), UINT8_C( 35), UINT8_C( 41), UINT8_C(  0), UINT8_C(  0), UINT8_C( 33), UINT8_C(  3), UINT8_C(  9) },
      { UINT8_C(  5), UINT8_C(  5), UINT8_C(  8), UINT8_C(  4), UINT8_C(  4), UINT8_C(  0), UINT8_C( 13), UINT8_C(  1),
        UINT8_C(  4), UINT8_C(  5), UINT8_C( 13), UINT8_C(  4), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  9) },
      { UINT8_C(  1), UINT8_C( 33), UINT8_C(160), UINT8_C(128), UINT8_C(160), UINT8_C(  0), UINT8_C(161), UINT8_C( 33),
        UINT8_C(128), UINT8_C( 33), UINT8_C( 33), UINT8_C(128), UINT8_C(128), UINT8_C(161), UINT8_C(129), UINT8_C(  1) } },
    { { UINT8_C(227), UINT8_C(198), UINT8_C( 98), UINT8_C(135), UINT8_C( 44), UINT8_C(198), UINT8_C(250), UINT8_C(120),
        UINT8_C(211), UINT8_C(197), UINT8_C(200), UINT8_C(170), UINT8_C( 83), UINT8_C(232), UINT8_C( 15), UINT8_C( 91) },
      { UINT8_C( 35), UINT8_C(  2), UINT8_C( 34), UINT8_C(  3), UINT8_C( 40), UINT8_C(  2), UINT8_C( 42), UINT8_C( 40),
        UINT8_C(  3), UINT8_C(  1), UINT8_C(  8), UINT8_C( 42), UINT8_C(  3), UINT8_C( 40), UINT8_C( 11), UINT8_C( 11) },
      { UINT8_C(  1), UINT8_C(  4), UINT8_C(  0), UINT8_C(  5), UINT8_C( 12), UINT8_C(  4), UINT8_C(  8), UINT8_C(  8),
        UINT8_C(  1), UINT8_C(  5), UINT8_C(  8), UINT8_C(  8), UINT8_C(  1), UINT8_C(  8), UINT8_C( 13), UINT8_C(  9) },
      { UINT8_C(161), UINT8_C(128), UINT8_C( 32), UINT8_C(129), UINT8_C( 32), UINT8_C(128), UINT8_C(160), UINT8_C( 32),
        UINT8_C(129), UINT8_C(129), UINT8_C(128), UINT8_C(160), UINT8_C(  1), UINT8_C(160), UINT8_C(  1), UINT8_C(  1) } },
    { { UINT8_C( 29), UINT8_C(249), UINT8_C( 47), UINT8_C(  3), UINT8_C( 75), UINT8_C( 46), UINT8_C( 52), UINT8_C( 33),
        UINT8_C( 86), UINT8_C( 97), UINT8_C(182), UINT8_C(230), UINT8_C( 18), UINT8_C(121), UINT8_C( 64), UINT8_C(246) },
      { UINT8_C(  9), UINT8_C( 41), UINT8_C( 43), UINT8_C(  3), UINT8_C( 11), UINT8_C( 42), UINT8_C( 32), UINT8_C( 33),
        UINT8_C(  2), UINT8_C( 33), UINT8_C( 34), UINT8_C( 34), UINT8_C(  2), UINT8_C( 41), UINT8_C(  0), UINT8_C( 34) },
      { UINT8_C( 13), UINT8_C(  9), UINT8_C( 13), UINT8_C(  1), UINT8_C(  9), UINT8_C( 12), UINT8_C(  4), UINT8_C(  1),
        UINT8_C(  4), UINT8_C(  1), UINT8_C(  4), UINT8_C(  4), UINT8_C(  0), UINT8_C(  9), UINT8_C(  0), UINT8_C(  4) },
      { UINT8_C(  1), UINT8_C(161), UINT8_C( 33), UINT8_C(  1), UINT8_C(  1), UINT8_C( 32), UINT8_C( 32), UINT8_C( 33),
        UINT8_C(  0), UINT8_C( 33), UINT8_C(160), UINT8_C(160), UINT8_C(  0), UINT8_C( 33), UINT8_C(  0), UINT8_C(160) } },
    { { UINT8_C( 63), UINT8_C(162), UINT8_C(125), UINT8_C(108), UINT8_C(105), UINT8_C(119), UINT8_C(228), UINT8_C( 60),
        UINT8_C( 61), UINT8_C(172), UINT8_C(230), UINT8_C(144), UINT8_C(149), UINT8_C(245), UINT8_C(235), UINT8_C(178) },
      { UINT8_C( 43), UINT8_C( 34), UINT8_C( 41), UINT8_C( 40), UINT8_C( 41), UINT8_C( 35), UINT8_C( 32), UINT8_C( 40),
        UINT8_C( 41), UINT8_C( 40), UINT8_C( 34), UINT8_C(  0), UINT8_C(  1), UINT8_C( 33), UINT8_C( 43), UINT8_C( 34) },
      { UINT8_C( 13), UINT8_C(  0), UINT8_C( 13), UINT8_C( 12), UINT8_C(  9), UINT8_C(  5), UINT8_C(  4), UINT8_C( 12),
        UINT8_C( 13), UINT8_C( 12), UINT8_C(  4), UINT8_C(  0), UINT8_C(  5), UINT8_C(  5), UINT8_C(  9), UINT8_C(  0) },
      { UINT8_C( 33), UINT8_C(160), UINT8_C( 33), UINT8_C( 32), UINT8_C( 33), UINT8_C( 33), UINT8_C(160), UINT8_C( 32),
        UINT8_C( 33), UINT8_C(160), UINT8_C(160), UINT8_C(128), UINT8_C(129), UINT8_C(161), UINT8_C(161), UINT8_C(160) } },
    { { UINT8_C(238), UINT8_C( 27), UINT8_C(182), UINT8_C( 58), UINT8_C( 73), UINT8_C(234), UINT8_C( 91), UINT8_C(159),
        UINT8_C( 76), UINT8_C( 17), UINT8_C(134), UINT8_C( 94), UINT8_C(139), UINT8_C(198), UINT8_C( 84), UINT8_C(202) },
      { UINT8_C( 42), UINT8_C( 11), UINT8_C( 34), UINT8_C( 42), UINT8_C(  9), UINT8_C( 42), UINT8_C( 11), UINT8_C( 11),
        UINT8_C(  8), UINT8_C(  1), UINT8_C(  2), UINT8_C( 10), UINT8_C( 11), UINT8_C(  2), UINT8_C(  0), UINT8_C( 10) },
      { UINT8_C( 12), UINT8_C(  9), UINT8_C(  4), UINT8_C(  8), UINT8_C(  9), UINT8_C(  8), UINT8_C(  9), UINT8_C( 13),
        UINT8_C( 12), UINT8_C(  1), UINT8_C(  4), UINT8_C( 12), UINT8_C(  9), UINT8_C(  4), UINT8_C(  4), UINT8_C(  8) },
      { UINT8_C(160), UINT8_C(  1), UINT8_C(160), UINT8_C( 32), UINT8_C(  1), UINT8_C(160), UINT8_C(  1), UINT8_C(129),
        UINT8_C(  0), UINT8_C(  1), UINT8_C(128), UINT8_C(  0), UINT8_C(129), UINT8_C(128), UINT8_C(  0), UINT8_C(128) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v16u8    a = simde_x_msa_ld_u_b(test_vec[i].a, 0);
    simde_v16u8  r43 = simde_msa_andi_b(a, 43);
    simde_v16u8  r13 = simde_msa_andi_b(a, 13);
    simde_v16u8 r161 = simde_msa_andi_b(a, 161);

    simde_test_msa_v16u8_assert_equal( r43, simde_x_msa_ld_u_b(test_vec[i].r43 , 0));
    simde_test_msa_v16u8_assert_equal( r13, simde_x_msa_ld_u_b(test_vec[i].r13 , 0));
    simde_test_msa_v16u8_assert_equal(r161, simde_x_msa_ld_u_b(test_vec[i].r161, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v16u8    a = simde_test_msa_v16u8_random();
    simde_v16u8  r43 = simde_msa_andi_b(a, 43);
    simde_v16u8  r13 = simde_msa_andi_b(a, 13);
    simde_v16u8 r161 = simde_msa_andi_b(a, 161);

    simde_test_msa_v16u8_write(2,   a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v16u8_write(2,  r43, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v16u8_write(2,  r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v16u8_write(2, r161, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(andi_b)
SIMDE_TEST_FUNC_LIST_END

#include "test-msa-footer.h"
