/* Copyright (c) 2021 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define SIMDE_TEST_WASM_SIMD128_INSN avgr
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_u8x16_avgr(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint8_t a[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t b[sizeof(simde_v128_t) / sizeof(uint8_t)];
      uint8_t r[sizeof(simde_v128_t) / sizeof(uint8_t)];
    } test_vec[] = {
      { { UINT8_C( 42), UINT8_C(161), UINT8_C(251), UINT8_C( 72), UINT8_C( 66), UINT8_C(140), UINT8_C(190), UINT8_C( 51),
          UINT8_C( 89), UINT8_C(145), UINT8_C( 73), UINT8_C(227), UINT8_C(111), UINT8_C(240), UINT8_C(188), UINT8_C(251) },
        { UINT8_C( 52), UINT8_C(176), UINT8_C( 44), UINT8_C(  9), UINT8_C( 98), UINT8_C(217), UINT8_C(118), UINT8_C(229),
          UINT8_C(247), UINT8_C(138), UINT8_C( 25), UINT8_C( 86), UINT8_C(103), UINT8_C( 82), UINT8_C( 42), UINT8_C( 97) },
        { UINT8_C( 47), UINT8_C(169), UINT8_C(148), UINT8_C( 41), UINT8_C( 82), UINT8_C(179), UINT8_C(154), UINT8_C(140),
          UINT8_C(168), UINT8_C(142), UINT8_C( 49), UINT8_C(157), UINT8_C(107), UINT8_C(161), UINT8_C(115), UINT8_C(174) } },
      { { UINT8_C(167), UINT8_C( 93), UINT8_C(188), UINT8_C( 81), UINT8_C( 64), UINT8_C(157), UINT8_C(136), UINT8_C(173),
          UINT8_C( 27), UINT8_C( 62), UINT8_C( 16), UINT8_C( 24), UINT8_C(116), UINT8_C( 39), UINT8_C(168), UINT8_C(193) },
        { UINT8_C( 60), UINT8_C(232), UINT8_C(  0), UINT8_C( 76), UINT8_C(210), UINT8_C( 72), UINT8_C( 59), UINT8_C(234),
          UINT8_C(160), UINT8_C( 74), UINT8_C(238), UINT8_C(155), UINT8_C( 67), UINT8_C( 17), UINT8_C(195), UINT8_C(244) },
        { UINT8_C(114), UINT8_C(163), UINT8_C( 94), UINT8_C( 79), UINT8_C(137), UINT8_C(115), UINT8_C( 98), UINT8_C(204),
          UINT8_C( 94), UINT8_C( 68), UINT8_C(127), UINT8_C( 90), UINT8_C( 92), UINT8_C( 28), UINT8_C(182), UINT8_C(219) } },
      { { UINT8_C(177), UINT8_C( 79), UINT8_C( 75), UINT8_C(125), UINT8_C( 16), UINT8_C(198), UINT8_C(100), UINT8_C( 85),
          UINT8_C( 82), UINT8_C(160), UINT8_C( 97), UINT8_C( 72), UINT8_C(118), UINT8_C( 20), UINT8_C(245), UINT8_C(  9) },
        { UINT8_C(238), UINT8_C(171), UINT8_C( 68), UINT8_C(235), UINT8_C(105), UINT8_C( 82), UINT8_C(151), UINT8_C( 62),
          UINT8_C(165), UINT8_C(108), UINT8_C(193), UINT8_C( 49), UINT8_C( 35), UINT8_C(166), UINT8_C( 52), UINT8_C( 66) },
        { UINT8_C(208), UINT8_C(125), UINT8_C( 72), UINT8_C(180), UINT8_C( 61), UINT8_C(140), UINT8_C(126), UINT8_C( 74),
          UINT8_C(124), UINT8_C(134), UINT8_C(145), UINT8_C( 61), UINT8_C( 77), UINT8_C( 93), UINT8_C(149), UINT8_C( 38) } },
      { { UINT8_C( 56), UINT8_C(252), UINT8_C(249), UINT8_C(174), UINT8_C( 35), UINT8_C( 31), UINT8_C(247), UINT8_C(156),
          UINT8_C( 62), UINT8_C( 47), UINT8_C( 85), UINT8_C(225), UINT8_C(247), UINT8_C( 82), UINT8_C(219), UINT8_C(132) },
        { UINT8_C(238), UINT8_C(243), UINT8_C( 45), UINT8_C(112), UINT8_C( 45), UINT8_C( 88), UINT8_C( 31), UINT8_C( 81),
          UINT8_C(206), UINT8_C(145), UINT8_C(147), UINT8_C(221), UINT8_C(146), UINT8_C(115), UINT8_C(123), UINT8_C(225) },
        { UINT8_C(147), UINT8_C(248), UINT8_C(147), UINT8_C(143), UINT8_C( 40), UINT8_C( 60), UINT8_C(139), UINT8_C(119),
          UINT8_C(134), UINT8_C( 96), UINT8_C(116), UINT8_C(223), UINT8_C(197), UINT8_C( 99), UINT8_C(171), UINT8_C(179) } },
      { { UINT8_C( 92), UINT8_C( 44), UINT8_C(106), UINT8_C( 68), UINT8_C(216), UINT8_C(248), UINT8_C(176), UINT8_C( 73),
          UINT8_C(179), UINT8_C(106), UINT8_C(223), UINT8_C( 66), UINT8_C(134), UINT8_C(136), UINT8_C(  0), UINT8_C(155) },
        { UINT8_C( 17), UINT8_C( 99), UINT8_C( 75), UINT8_C(107), UINT8_C(  8), UINT8_C(245), UINT8_C(246), UINT8_C(201),
          UINT8_C(236), UINT8_C(126), UINT8_C( 66), UINT8_C( 15), UINT8_C(142), UINT8_C(153), UINT8_C(186), UINT8_C( 47) },
        { UINT8_C( 55), UINT8_C( 72), UINT8_C( 91), UINT8_C( 88), UINT8_C(112), UINT8_C(247), UINT8_C(211), UINT8_C(137),
          UINT8_C(208), UINT8_C(116), UINT8_C(145), UINT8_C( 41), UINT8_C(138), UINT8_C(145), UINT8_C( 93), UINT8_C(101) } },
      { { UINT8_C( 78), UINT8_C( 28), UINT8_C(139), UINT8_C(134), UINT8_C( 72), UINT8_C( 65), UINT8_C( 46), UINT8_C(150),
          UINT8_C(219), UINT8_C(114), UINT8_C(168), UINT8_C(141), UINT8_C(108), UINT8_C( 51), UINT8_C(193), UINT8_C(237) },
        { UINT8_C(251), UINT8_C( 63), UINT8_C( 72), UINT8_C(154), UINT8_C( 87), UINT8_C( 37), UINT8_C(239), UINT8_C( 88),
          UINT8_C( 81), UINT8_C(114), UINT8_C( 23), UINT8_C(107), UINT8_C(249), UINT8_C(126), UINT8_C( 57), UINT8_C(139) },
        { UINT8_C(165), UINT8_C( 46), UINT8_C(106), UINT8_C(144), UINT8_C( 80), UINT8_C( 51), UINT8_C(143), UINT8_C(119),
          UINT8_C(150), UINT8_C(114), UINT8_C( 96), UINT8_C(124), UINT8_C(179), UINT8_C( 89), UINT8_C(125), UINT8_C(188) } },
      { { UINT8_C(174), UINT8_C( 49), UINT8_C( 13), UINT8_C(146), UINT8_C(153), UINT8_C(108), UINT8_C( 39), UINT8_C(200),
          UINT8_C(113), UINT8_C( 22), UINT8_C( 99), UINT8_C(238), UINT8_C(223), UINT8_C(229), UINT8_C(245), UINT8_C( 72) },
        { UINT8_C( 64), UINT8_C(218), UINT8_C( 23), UINT8_C(147), UINT8_C(250), UINT8_C(233), UINT8_C( 61), UINT8_C( 30),
          UINT8_C(210), UINT8_C(244), UINT8_C(228), UINT8_C(215), UINT8_C(133), UINT8_C(211), UINT8_C(242), UINT8_C( 16) },
        { UINT8_C(119), UINT8_C(134), UINT8_C( 18), UINT8_C(147), UINT8_C(202), UINT8_C(171), UINT8_C( 50), UINT8_C(115),
          UINT8_C(162), UINT8_C(133), UINT8_C(164), UINT8_C(227), UINT8_C(178), UINT8_C(220), UINT8_C(244), UINT8_C( 44) } },
      { { UINT8_C(107), UINT8_C( 44), UINT8_C( 87), UINT8_C(196), UINT8_C(198), UINT8_C(207), UINT8_C(207), UINT8_C( 77),
          UINT8_C(131), UINT8_C(108), UINT8_C(166), UINT8_C(102), UINT8_C(170), UINT8_C( 10), UINT8_C( 58), UINT8_C( 38) },
        { UINT8_C(  1), UINT8_C(144), UINT8_C(177), UINT8_C(242), UINT8_C(224), UINT8_C(101), UINT8_C(144), UINT8_C(125),
          UINT8_C( 71), UINT8_C( 43), UINT8_C(152), UINT8_C(  4), UINT8_C( 38), UINT8_C( 15), UINT8_C(151), UINT8_C(211) },
        { UINT8_C( 54), UINT8_C( 94), UINT8_C(132), UINT8_C(219), UINT8_C(211), UINT8_C(154), UINT8_C(176), UINT8_C(101),
          UINT8_C(101), UINT8_C( 76), UINT8_C(159), UINT8_C( 53), UINT8_C(104), UINT8_C( 13), UINT8_C(105), UINT8_C(125) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u8x16_avgr(a, b);
      simde_test_wasm_u8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u8x16_random(),
        b = simde_test_wasm_u8x16_random(),
        r;

      r = simde_wasm_u8x16_avgr(a, b);

      simde_test_wasm_u8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_u16x8_avgr(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      uint16_t a[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t b[sizeof(simde_v128_t) / sizeof(uint16_t)];
      uint16_t r[sizeof(simde_v128_t) / sizeof(uint16_t)];
    } test_vec[] = {
      { { UINT16_C(56098), UINT16_C(41983), UINT16_C(35317), UINT16_C(21695), UINT16_C(57521), UINT16_C( 6205), UINT16_C(11107), UINT16_C(41910) },
        { UINT16_C(12302), UINT16_C( 1097), UINT16_C(35352), UINT16_C(31170), UINT16_C(44166), UINT16_C(31317), UINT16_C(32254), UINT16_C(39446) },
        { UINT16_C(34200), UINT16_C(21540), UINT16_C(35335), UINT16_C(26433), UINT16_C(50844), UINT16_C(18761), UINT16_C(21681), UINT16_C(40678) } },
      { { UINT16_C(20987), UINT16_C(19138), UINT16_C(57669), UINT16_C(60251), UINT16_C(50667), UINT16_C( 4871), UINT16_C(44823), UINT16_C(65123) },
        { UINT16_C(63360), UINT16_C(61186), UINT16_C(12896), UINT16_C(37373), UINT16_C(53735), UINT16_C( 8202), UINT16_C(46031), UINT16_C( 6820) },
        { UINT16_C(42174), UINT16_C(40162), UINT16_C(35283), UINT16_C(48812), UINT16_C(52201), UINT16_C( 6537), UINT16_C(45427), UINT16_C(35972) } },
      { { UINT16_C(36873), UINT16_C(22522), UINT16_C(12055), UINT16_C(39612), UINT16_C(29102), UINT16_C(40265), UINT16_C( 8566), UINT16_C(37330) },
        { UINT16_C(65501), UINT16_C(24362), UINT16_C(51253), UINT16_C( 6752), UINT16_C(35648), UINT16_C(20103), UINT16_C(41190), UINT16_C(45122) },
        { UINT16_C(51187), UINT16_C(23442), UINT16_C(31654), UINT16_C(23182), UINT16_C(32375), UINT16_C(30184), UINT16_C(24878), UINT16_C(41226) } },
      { { UINT16_C(50732), UINT16_C(20372), UINT16_C(15077), UINT16_C(30739), UINT16_C(50633), UINT16_C(65156), UINT16_C(61833), UINT16_C(19317) },
        { UINT16_C(13236), UINT16_C(45805), UINT16_C(26976), UINT16_C( 6442), UINT16_C(46180), UINT16_C(20503), UINT16_C( 1681), UINT16_C(40644) },
        { UINT16_C(31984), UINT16_C(33089), UINT16_C(21027), UINT16_C(18591), UINT16_C(48407), UINT16_C(42830), UINT16_C(31757), UINT16_C(29981) } },
      { { UINT16_C(63595), UINT16_C(37514), UINT16_C( 7307), UINT16_C(53396), UINT16_C(18326), UINT16_C(51921), UINT16_C(47067), UINT16_C(44901) },
        { UINT16_C(49854), UINT16_C(41102), UINT16_C(34053), UINT16_C(41053), UINT16_C(58148), UINT16_C(30356), UINT16_C(33797), UINT16_C(50263) },
        { UINT16_C(56725), UINT16_C(39308), UINT16_C(20680), UINT16_C(47225), UINT16_C(38237), UINT16_C(41139), UINT16_C(40432), UINT16_C(47582) } },
      { { UINT16_C(15319), UINT16_C(48598), UINT16_C(42778), UINT16_C(13273), UINT16_C(46265), UINT16_C(45234), UINT16_C(63275), UINT16_C(19366) },
        { UINT16_C( 4475), UINT16_C(26911), UINT16_C( 2355), UINT16_C(43237), UINT16_C(48589), UINT16_C(39936), UINT16_C( 5333), UINT16_C(56460) },
        { UINT16_C( 9897), UINT16_C(37755), UINT16_C(22567), UINT16_C(28255), UINT16_C(47427), UINT16_C(42585), UINT16_C(34304), UINT16_C(37913) } },
      { { UINT16_C(25320), UINT16_C(40174), UINT16_C(18212), UINT16_C( 6604), UINT16_C( 4198), UINT16_C(48751), UINT16_C(25495), UINT16_C(45813) },
        { UINT16_C(12113), UINT16_C(32692), UINT16_C(63732), UINT16_C(28228), UINT16_C(52004), UINT16_C(14747), UINT16_C( 4315), UINT16_C(13787) },
        { UINT16_C(18717), UINT16_C(36433), UINT16_C(40972), UINT16_C(17416), UINT16_C(28101), UINT16_C(31749), UINT16_C(14905), UINT16_C(29800) } },
      { { UINT16_C(13659), UINT16_C(37556), UINT16_C(25741), UINT16_C(63245), UINT16_C(15895), UINT16_C(13285), UINT16_C(40787), UINT16_C(65031) },
        { UINT16_C(51502), UINT16_C(45087), UINT16_C(38874), UINT16_C(18865), UINT16_C(52713), UINT16_C(58747), UINT16_C(47018), UINT16_C(61353) },
        { UINT16_C(32581), UINT16_C(41322), UINT16_C(32308), UINT16_C(41055), UINT16_C(34304), UINT16_C(36016), UINT16_C(43903), UINT16_C(63192) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t r = simde_wasm_u16x8_avgr(a, b);
      simde_test_wasm_u16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_u16x8_random(),
        b = simde_test_wasm_u16x8_random(),
        r;

      r = simde_wasm_u16x8_avgr(a, b);

      simde_test_wasm_u16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_u16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_u16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u8x16_avgr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_avgr)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
