#define SIMDE_TEST_ARM_NEON_INSN ld2

#include "test-neon.h"
#include "../../../simde/arm/neon/ld2.h"

static int
test_simde_vld2_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[2][8];
  } test_vec[] = {

    { { UINT8_C(144), UINT8_C(234), UINT8_C(130), UINT8_C(145), UINT8_C( 26), UINT8_C(241), UINT8_C( 35), UINT8_C( 43) },
      { UINT8_C( 76), UINT8_C(223), UINT8_C(152), UINT8_C(128), UINT8_C(203), UINT8_C( 66), UINT8_C( 17), UINT8_C(218) },
        { { UINT8_C(144), UINT8_C(130), UINT8_C( 26), UINT8_C( 35), UINT8_C( 76), UINT8_C(152), UINT8_C(203), UINT8_C( 17) },
          { UINT8_C(234), UINT8_C(145), UINT8_C(241), UINT8_C( 43), UINT8_C(223), UINT8_C(128), UINT8_C( 66), UINT8_C(218) } },
    },
    { { UINT8_C(196), UINT8_C( 14), UINT8_C( 36), UINT8_C( 59), UINT8_C(230), UINT8_C(253), UINT8_C(216), UINT8_C( 14) },
      { UINT8_C( 31), UINT8_C( 73), UINT8_C( 48), UINT8_C( 55), UINT8_C(200), UINT8_C( 71), UINT8_C(176), UINT8_C( 88) },
        { { UINT8_C(196), UINT8_C( 36), UINT8_C(230), UINT8_C(216), UINT8_C( 31), UINT8_C( 48), UINT8_C(200), UINT8_C(176) },
          { UINT8_C( 14), UINT8_C( 59), UINT8_C(253), UINT8_C( 14), UINT8_C( 73), UINT8_C( 55), UINT8_C( 71), UINT8_C( 88) } },
    },
    { { UINT8_C( 49), UINT8_C( 50), UINT8_C(233), UINT8_C( 76), UINT8_C( 35), UINT8_C( 13), UINT8_C(119), UINT8_C(111) },
      { UINT8_C(236), UINT8_C( 15), UINT8_C(240), UINT8_C(184), UINT8_C( 81), UINT8_C(  1), UINT8_C(146), UINT8_C( 22) },
        { { UINT8_C( 49), UINT8_C(233), UINT8_C( 35), UINT8_C(119), UINT8_C(236), UINT8_C(240), UINT8_C( 81), UINT8_C(146) },
          { UINT8_C( 50), UINT8_C( 76), UINT8_C( 13), UINT8_C(111), UINT8_C( 15), UINT8_C(184), UINT8_C(  1), UINT8_C( 22) } },
    },
    { { UINT8_C( 15), UINT8_C(182), UINT8_C( 81), UINT8_C(245), UINT8_C(179), UINT8_C( 41), UINT8_C(  4), UINT8_C(211) },
      { UINT8_C(115), UINT8_C( 52), UINT8_C( 10), UINT8_C( 59), UINT8_C(123), UINT8_C(187), UINT8_C(147), UINT8_C(173) },
        { { UINT8_C( 15), UINT8_C( 81), UINT8_C(179), UINT8_C(  4), UINT8_C(115), UINT8_C( 10), UINT8_C(123), UINT8_C(147) },
          { UINT8_C(182), UINT8_C(245), UINT8_C( 41), UINT8_C(211), UINT8_C( 52), UINT8_C( 59), UINT8_C(187), UINT8_C(173) } },
    },
    { { UINT8_C(237), UINT8_C(125), UINT8_C(249), UINT8_C( 17), UINT8_C(138), UINT8_C(112), UINT8_C(128), UINT8_C(118) },
      { UINT8_C(127), UINT8_C(112), UINT8_C( 46), UINT8_C(208), UINT8_C(113), UINT8_C(193), UINT8_C(230), UINT8_C(129) },
        { { UINT8_C(237), UINT8_C(249), UINT8_C(138), UINT8_C(128), UINT8_C(127), UINT8_C( 46), UINT8_C(113), UINT8_C(230) },
          { UINT8_C(125), UINT8_C( 17), UINT8_C(112), UINT8_C(118), UINT8_C(112), UINT8_C(208), UINT8_C(193), UINT8_C(129) } },
    },
    { { UINT8_C(119), UINT8_C( 56), UINT8_C(118), UINT8_C( 43), UINT8_C( 97), UINT8_C(122), UINT8_C(254), UINT8_C(212) },
      { UINT8_C(175), UINT8_C(  8), UINT8_C( 15), UINT8_C( 42), UINT8_C(195), UINT8_C(163), UINT8_C(215), UINT8_C(177) },
        { { UINT8_C(119), UINT8_C(118), UINT8_C( 97), UINT8_C(254), UINT8_C(175), UINT8_C( 15), UINT8_C(195), UINT8_C(215) },
          { UINT8_C( 56), UINT8_C( 43), UINT8_C(122), UINT8_C(212), UINT8_C(  8), UINT8_C( 42), UINT8_C(163), UINT8_C(177) } },
    },
    { { UINT8_C( 32), UINT8_C(208), UINT8_C(194), UINT8_C(170), UINT8_C( 64), UINT8_C( 66), UINT8_C( 32), UINT8_C(191) },
      { UINT8_C(179), UINT8_C( 79), UINT8_C(144), UINT8_C( 36), UINT8_C( 16), UINT8_C(118), UINT8_C(165), UINT8_C(135) },
        { { UINT8_C( 32), UINT8_C(194), UINT8_C( 64), UINT8_C( 32), UINT8_C(179), UINT8_C(144), UINT8_C( 16), UINT8_C(165) },
          { UINT8_C(208), UINT8_C(170), UINT8_C( 66), UINT8_C(191), UINT8_C( 79), UINT8_C( 36), UINT8_C(118), UINT8_C(135) } },
    },
    { { UINT8_C(174), UINT8_C( 28), UINT8_C(178), UINT8_C( 16), UINT8_C(150), UINT8_C(176), UINT8_C(228), UINT8_C( 69) },
      { UINT8_C(185), UINT8_C(244), UINT8_C(112), UINT8_C(124), UINT8_C(151), UINT8_C( 71), UINT8_C( 45), UINT8_C(183) },
        { { UINT8_C(174), UINT8_C(178), UINT8_C(150), UINT8_C(228), UINT8_C(185), UINT8_C(112), UINT8_C(151), UINT8_C( 45) },
          { UINT8_C( 28), UINT8_C( 16), UINT8_C(176), UINT8_C( 69), UINT8_C(244), UINT8_C(124), UINT8_C( 71), UINT8_C(183) } },
    },


  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x2_t r = simde_vld2_u8(test_vec[i].a);

    simde_uint8x8x2_t expected = {
        {simde_vld1_u8(test_vec[i].r[0]), simde_vld1_u8(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint8_t buf[16];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint8x8x2_t r = simde_vld2_u8(buf);

    simde_test_arm_neon_write_u8x8x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_u8)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
