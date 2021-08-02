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

#define SIMDE_TEST_WASM_RELAXED_SIMD_INSN blend
#include "../../../simde/wasm/relaxed-simd.h"
#include "test-relaxed-simd.h"

static int
test_simde_wasm_i8x16_blend(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int8_t a[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t b[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t mask[sizeof(simde_v128_t) / sizeof(int8_t)];
      int8_t r[sizeof(simde_v128_t) / sizeof(int8_t)];
    } test_vec[] = {
      { { -INT8_C(  47),  INT8_C(  48), -INT8_C(  38),  INT8_C(  57), -INT8_C(  47), -INT8_C(  71), -INT8_C(  70),  INT8_C( 114),
          -INT8_C( 114), -INT8_C(   4), -INT8_C(  13),  INT8_C(  88),  INT8_C(  35),  INT8_C(  87),  INT8_C(  26),  INT8_C(  62) },
        {  INT8_C( 118), -INT8_C(  57),      INT8_MAX, -INT8_C(   1),  INT8_C( 107), -INT8_C(  24),  INT8_C( 124),  INT8_C(  76),
           INT8_C(  41),  INT8_C(  29), -INT8_C(  49), -INT8_C(  45), -INT8_C( 119),  INT8_C(  57),  INT8_C(  79),  INT8_C(  90) },
        {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
           INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) },
        {  INT8_C( 118), -INT8_C(  57), -INT8_C(  38), -INT8_C(   1), -INT8_C(  47), -INT8_C(  24), -INT8_C(  70),  INT8_C(  76),
           INT8_C(  41), -INT8_C(   4), -INT8_C(  13), -INT8_C(  45),  INT8_C(  35),  INT8_C(  87),  INT8_C(  26),  INT8_C(  90) } },
      { { -INT8_C(  87),  INT8_C(  43),  INT8_C( 109),  INT8_C(  21),  INT8_C(  20), -INT8_C(  23),  INT8_C(  97),  INT8_C(  61),
           INT8_C(   6),  INT8_C(  48),  INT8_C(  17), -INT8_C( 113),  INT8_C( 105),  INT8_C(  96), -INT8_C(  23), -INT8_C(  45) },
        { -INT8_C( 119),  INT8_C( 125),  INT8_C(  13),  INT8_C( 107), -INT8_C(  52), -INT8_C(  70), -INT8_C(  37),  INT8_C(  23),
           INT8_C(  90), -INT8_C(  92), -INT8_C( 123),  INT8_C(  82), -INT8_C( 122),  INT8_C(  49), -INT8_C(  65),  INT8_C(  48) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
          -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) },
        { -INT8_C( 119),  INT8_C( 125),  INT8_C(  13),  INT8_C( 107), -INT8_C(  52), -INT8_C(  23),  INT8_C(  97),  INT8_C(  23),
           INT8_C(   6),  INT8_C(  48),  INT8_C(  17),  INT8_C(  82), -INT8_C( 122),  INT8_C(  96), -INT8_C(  65), -INT8_C(  45) } },
      { {  INT8_C(  17),  INT8_C(  32),  INT8_C(  19), -INT8_C(  35), -INT8_C(  38), -INT8_C(  17), -INT8_C(  12),  INT8_C(  53),
          -INT8_C( 109),  INT8_C( 121), -INT8_C( 121),  INT8_C(  25), -INT8_C(  85),  INT8_C(  70),  INT8_C(  73),  INT8_C(   8) },
        {  INT8_C( 115), -INT8_C( 114),  INT8_C( 121), -INT8_C( 120),  INT8_C(  52),  INT8_C(  39), -INT8_C(  92),  INT8_C(  10),
          -INT8_C(  25),  INT8_C(  78),  INT8_C(  74),  INT8_C(   6), -INT8_C(  30),  INT8_C(  92), -INT8_C(  81), -INT8_C(  12) },
        {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) },
        {  INT8_C( 115),  INT8_C(  32),  INT8_C(  19), -INT8_C( 120), -INT8_C(  38), -INT8_C(  17), -INT8_C(  12),  INT8_C(  10),
          -INT8_C(  25),  INT8_C(  78),  INT8_C(  74),  INT8_C(  25), -INT8_C(  30),  INT8_C(  70),  INT8_C(  73),  INT8_C(   8) } },
      { {  INT8_C(  54),  INT8_C( 107),  INT8_C(  85),  INT8_C( 106), -INT8_C( 109), -INT8_C(   7),  INT8_C( 117),  INT8_C( 122),
           INT8_C(  71), -INT8_C(  65),      INT8_MIN,  INT8_C(  42),  INT8_C(  27),  INT8_C(  47),  INT8_C(  30), -INT8_C( 104) },
        { -INT8_C(  14), -INT8_C(  17), -INT8_C(  17), -INT8_C(  93), -INT8_C(  75),  INT8_C( 123), -INT8_C(  24), -INT8_C(  11),
          -INT8_C( 114),  INT8_C(  70), -INT8_C(  33), -INT8_C(  25), -INT8_C(  19), -INT8_C(  46), -INT8_C(  76),  INT8_C(  35) },
        {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
          -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) },
        { -INT8_C(  14), -INT8_C(  17),  INT8_C(  85),  INT8_C( 106), -INT8_C(  75),  INT8_C( 123), -INT8_C(  24), -INT8_C(  11),
           INT8_C(  71), -INT8_C(  65), -INT8_C(  33),  INT8_C(  42),  INT8_C(  27),  INT8_C(  47), -INT8_C(  76), -INT8_C( 104) } },
      { { -INT8_C( 127),  INT8_C( 100), -INT8_C( 112),  INT8_C(  54), -INT8_C(  33),  INT8_C( 120),  INT8_C(  43),  INT8_C( 109),
          -INT8_C(  66),  INT8_C(  11),  INT8_C(  85), -INT8_C(  85), -INT8_C(  35),  INT8_C(   9), -INT8_C(  49),  INT8_C(  26) },
        {  INT8_C(  18),  INT8_C(  93), -INT8_C(  21),  INT8_C(  20),  INT8_C(  96),  INT8_C(  53),  INT8_C(  93),  INT8_C(  34),
           INT8_C(   0), -INT8_C(  47), -INT8_C(   1), -INT8_C(   5),  INT8_C(  98),  INT8_C( 117), -INT8_C(  25), -INT8_C(  29) },
        { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
           INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) },
        { -INT8_C( 127),  INT8_C(  93), -INT8_C(  21),  INT8_C(  54), -INT8_C(  33),  INT8_C(  53),  INT8_C(  93),  INT8_C( 109),
           INT8_C(   0), -INT8_C(  47), -INT8_C(   1), -INT8_C(   5), -INT8_C(  35),  INT8_C( 117), -INT8_C(  25),  INT8_C(  26) } },
      { { -INT8_C( 123),  INT8_C(  51), -INT8_C(  86), -INT8_C(  27),  INT8_C( 104),  INT8_C(   8),  INT8_C(   7),  INT8_C( 105),
          -INT8_C(  39),  INT8_C(   6),  INT8_C( 100),  INT8_C(  59),  INT8_C( 123),  INT8_C(  75),  INT8_C(  31),  INT8_C(  85) },
        { -INT8_C(  61),  INT8_C(  57),  INT8_C(  14), -INT8_C(  78),  INT8_C( 126),  INT8_C(  52),  INT8_C(  96), -INT8_C(  49),
          -INT8_C(  80), -INT8_C(  71), -INT8_C(   4),  INT8_C(  52), -INT8_C(  31),  INT8_C(  68), -INT8_C(  53),  INT8_C( 102) },
        {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) },
        { -INT8_C(  61),  INT8_C(  57),  INT8_C(  14), -INT8_C(  27),  INT8_C( 126),  INT8_C(  52),  INT8_C(  96), -INT8_C(  49),
          -INT8_C(  80),  INT8_C(   6),  INT8_C( 100),  INT8_C(  59),  INT8_C( 123),  INT8_C(  75), -INT8_C(  53),  INT8_C(  85) } },
      { { -INT8_C(  22),  INT8_C(  55),  INT8_C( 110),  INT8_C( 104),  INT8_C( 107), -INT8_C(  50),  INT8_C(  55),  INT8_C(  27),
          -INT8_C( 121),  INT8_C(  52),  INT8_C(  80),  INT8_C( 104),  INT8_C( 120),  INT8_C(  27), -INT8_C(  50), -INT8_C(  16) },
        { -INT8_C( 112),  INT8_C(  25), -INT8_C(  48),  INT8_C(  14),  INT8_C( 107),  INT8_C(  25),  INT8_C( 100), -INT8_C(  61),
          -INT8_C(  58), -INT8_C(  10), -INT8_C( 105), -INT8_C(  66), -INT8_C(  89), -INT8_C(  64),  INT8_C( 122), -INT8_C( 111) },
        { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) },
        { -INT8_C(  22),  INT8_C(  55),  INT8_C( 110),  INT8_C(  14),  INT8_C( 107),  INT8_C(  25),  INT8_C( 100), -INT8_C(  61),
          -INT8_C(  58),  INT8_C(  52),  INT8_C(  80),  INT8_C( 104),  INT8_C( 120), -INT8_C(  64), -INT8_C(  50), -INT8_C( 111) } },
      { { -INT8_C( 116), -INT8_C(  98), -INT8_C( 120), -INT8_C(   9), -INT8_C(  73), -INT8_C(  20), -INT8_C(  70),  INT8_C( 125),
          -INT8_C(  29),  INT8_C(  82),  INT8_C(  59), -INT8_C( 118),  INT8_C(  18), -INT8_C(  75),  INT8_C(  28),  INT8_C(  10) },
        { -INT8_C(  99),  INT8_C(  22),  INT8_C( 109),  INT8_C(  83),  INT8_C(  71), -INT8_C(  21), -INT8_C( 112), -INT8_C(  83),
          -INT8_C(  70),  INT8_C(  53), -INT8_C( 117), -INT8_C(  93), -INT8_C(  88),  INT8_C(  89),  INT8_C(  29),  INT8_C(  52) },
        { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
           INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) },
        { -INT8_C( 116), -INT8_C(  98),  INT8_C( 109), -INT8_C(   9), -INT8_C(  73), -INT8_C(  20), -INT8_C( 112), -INT8_C(  83),
          -INT8_C(  70),  INT8_C(  53),  INT8_C(  59), -INT8_C(  93), -INT8_C(  88),  INT8_C(  89),  INT8_C(  29),  INT8_C(  10) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t mask = simde_wasm_v128_load(test_vec[i].mask);
      simde_v128_t r = simde_wasm_i8x16_blend(a, b, mask);
      simde_test_wasm_i8x16_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i8x16_random(),
        b = simde_test_wasm_i8x16_random(),
        mask = simde_wasm_i8x16_shr(simde_test_wasm_i8x16_random(), 7),
        r;

      r = simde_wasm_i8x16_blend(a, b, mask);

      simde_test_wasm_i8x16_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i8x16_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, mask, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i8x16_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i16x8_blend(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int16_t a[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t b[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t mask[sizeof(simde_v128_t) / sizeof(int16_t)];
      int16_t r[sizeof(simde_v128_t) / sizeof(int16_t)];
    } test_vec[] = {
      { {  INT16_C( 32134), -INT16_C( 14619), -INT16_C( 12998),  INT16_C( 16363),  INT16_C( 31700), -INT16_C(  5370), -INT16_C( 15572), -INT16_C( 29959) },
        {  INT16_C( 31938),  INT16_C( 30682), -INT16_C( 21172), -INT16_C(  2301),  INT16_C(   762),  INT16_C( 22561), -INT16_C( 11973), -INT16_C( 16115) },
        { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
        {  INT16_C( 32134), -INT16_C( 14619), -INT16_C( 21172),  INT16_C( 16363),  INT16_C( 31700),  INT16_C( 22561), -INT16_C( 11973), -INT16_C( 16115) } },
      { {  INT16_C( 32501),  INT16_C( 16842), -INT16_C( 13012),  INT16_C(  9784),  INT16_C( 23248),  INT16_C(  2942), -INT16_C( 29909),  INT16_C( 31436) },
        {  INT16_C( 21374),  INT16_C( 15875), -INT16_C( 13370), -INT16_C( 18990),  INT16_C( 21145),  INT16_C( 10959),  INT16_C( 29899), -INT16_C( 16002) },
        {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) },
        {  INT16_C( 21374),  INT16_C( 15875), -INT16_C( 13370),  INT16_C(  9784),  INT16_C( 23248),  INT16_C(  2942), -INT16_C( 29909),  INT16_C( 31436) } },
      { {  INT16_C( 15632), -INT16_C( 10486), -INT16_C(  8952), -INT16_C( 24180),  INT16_C( 23343), -INT16_C(  1076),  INT16_C( 19151), -INT16_C( 15684) },
        { -INT16_C( 16750), -INT16_C( 22304),  INT16_C(  9721), -INT16_C( 29042),  INT16_C( 32744),  INT16_C( 13903), -INT16_C( 30404),  INT16_C( 19715) },
        {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) },
        { -INT16_C( 16750), -INT16_C( 10486), -INT16_C(  8952), -INT16_C( 29042),  INT16_C( 32744), -INT16_C(  1076),  INT16_C( 19151),  INT16_C( 19715) } },
      { {  INT16_C( 32143), -INT16_C( 30270),  INT16_C( 20642), -INT16_C( 30185),  INT16_C( 26320),  INT16_C(  3265), -INT16_C( 15120), -INT16_C( 18599) },
        {  INT16_C( 32209), -INT16_C( 17274), -INT16_C(  2259),  INT16_C( 14806), -INT16_C(  5324), -INT16_C( 17644), -INT16_C( 20036),  INT16_C( 19413) },
        { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) },
        {  INT16_C( 32143), -INT16_C( 30270),  INT16_C( 20642), -INT16_C( 30185), -INT16_C(  5324), -INT16_C( 17644), -INT16_C( 20036), -INT16_C( 18599) } },
      { { -INT16_C( 32613), -INT16_C( 14226),  INT16_C( 17527), -INT16_C( 21503),  INT16_C(  5423), -INT16_C(  5273),  INT16_C( 15558), -INT16_C(  2762) },
        {  INT16_C(  3027), -INT16_C( 17466),  INT16_C(  8695),  INT16_C( 18802),  INT16_C( 13886),  INT16_C(  7820), -INT16_C( 31404), -INT16_C(  4144) },
        {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) },
        {  INT16_C(  3027), -INT16_C( 17466),  INT16_C( 17527), -INT16_C( 21503),  INT16_C(  5423), -INT16_C(  5273),  INT16_C( 15558), -INT16_C(  2762) } },
      { {  INT16_C( 20702), -INT16_C( 10917), -INT16_C( 12687), -INT16_C( 20706), -INT16_C( 22012),  INT16_C( 22734), -INT16_C( 25040),  INT16_C( 13639) },
        { -INT16_C(    35),  INT16_C( 24498), -INT16_C(  9288), -INT16_C( 31215), -INT16_C( 21140),  INT16_C( 14619), -INT16_C( 23168),  INT16_C( 24281) },
        {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) },
        { -INT16_C(    35),  INT16_C( 24498), -INT16_C(  9288), -INT16_C( 31215), -INT16_C( 22012),  INT16_C( 14619), -INT16_C( 25040),  INT16_C( 24281) } },
      { {  INT16_C(  5286),  INT16_C( 24255), -INT16_C( 12048),  INT16_C( 23781),  INT16_C(   126), -INT16_C(   363),  INT16_C( 28326), -INT16_C( 25763) },
        { -INT16_C( 28509), -INT16_C( 23038),  INT16_C(  6626), -INT16_C(  8274),  INT16_C(  3837), -INT16_C( 32757),  INT16_C( 28085),  INT16_C( 23776) },
        { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
        {  INT16_C(  5286), -INT16_C( 23038), -INT16_C( 12048),  INT16_C( 23781),  INT16_C(  3837), -INT16_C( 32757),  INT16_C( 28085),  INT16_C( 23776) } },
      { { -INT16_C(  6950), -INT16_C( 17125), -INT16_C( 13827), -INT16_C(  1380), -INT16_C( 22569), -INT16_C( 29317),  INT16_C( 23317), -INT16_C( 26647) },
        { -INT16_C( 23557),  INT16_C( 27657), -INT16_C( 10429), -INT16_C(  7334),  INT16_C( 18234),  INT16_C(  2857),  INT16_C(  2705),  INT16_C( 27776) },
        { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) },
        { -INT16_C(  6950), -INT16_C( 17125), -INT16_C( 13827), -INT16_C(  7334),  INT16_C( 18234), -INT16_C( 29317),  INT16_C( 23317), -INT16_C( 26647) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t mask = simde_wasm_v128_load(test_vec[i].mask);
      simde_v128_t r = simde_wasm_i16x8_blend(a, b, mask);
      simde_test_wasm_i16x8_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i16x8_random(),
        b = simde_test_wasm_i16x8_random(),
        mask = simde_wasm_i16x8_shr(simde_test_wasm_i16x8_random(), 15),
        r;

      r = simde_wasm_i16x8_blend(a, b, mask);

      simde_test_wasm_i16x8_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i16x8_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, mask, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i16x8_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i32x4_blend(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int32_t a[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t b[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t mask[sizeof(simde_v128_t) / sizeof(int32_t)];
      int32_t r[sizeof(simde_v128_t) / sizeof(int32_t)];
    } test_vec[] = {
      { { -INT32_C(   550903393),  INT32_C(   915823364), -INT32_C(  1353539952),  INT32_C(  1660758645) },
        {  INT32_C(  1657433796), -INT32_C(   417913372), -INT32_C(   522906996),  INT32_C(  1171144101) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) },
        {  INT32_C(  1657433796),  INT32_C(   915823364), -INT32_C(  1353539952),  INT32_C(  1660758645) } },
      { { -INT32_C(   503514115), -INT32_C(  1396174048), -INT32_C(   879976922), -INT32_C(    99591461) },
        { -INT32_C(  1541655214),  INT32_C(  1233614320), -INT32_C(   149415647), -INT32_C(  1500427864) },
        {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) },
        { -INT32_C(  1541655214), -INT32_C(  1396174048), -INT32_C(   879976922), -INT32_C(  1500427864) } },
      { { -INT32_C(   923868968),  INT32_C(  1980855637),  INT32_C(   913123726), -INT32_C(  1227030926) },
        {  INT32_C(   756704396), -INT32_C(  1561056332), -INT32_C(  1083472184),  INT32_C(    17379113) },
        {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) },
        {  INT32_C(   756704396),  INT32_C(  1980855637), -INT32_C(  1083472184), -INT32_C(  1227030926) } },
      { {  INT32_C(   620775537),  INT32_C(  1002959987), -INT32_C(  1527106950),  INT32_C(  1889862497) },
        {  INT32_C(  1725263866),  INT32_C(  1314959434),  INT32_C(  1069912568),  INT32_C(   252900254) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) },
        {  INT32_C(   620775537),  INT32_C(  1002959987), -INT32_C(  1527106950),  INT32_C(  1889862497) } },
      { { -INT32_C(  2092379079),  INT32_C(  2110957700), -INT32_C(   675506375), -INT32_C(   974729334) },
        { -INT32_C(   395109663),  INT32_C(  1130978325),  INT32_C(   668110400), -INT32_C(  1844915880) },
        {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
        { -INT32_C(   395109663),  INT32_C(  1130978325),  INT32_C(   668110400), -INT32_C(  1844915880) } },
      { {  INT32_C(   553402891), -INT32_C(   547134049),  INT32_C(  1275475443), -INT32_C(  1377956345) },
        {  INT32_C(  1490547551),  INT32_C(  1519026139),  INT32_C(   375624931), -INT32_C(  1876282747) },
        {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) },
        {  INT32_C(  1490547551), -INT32_C(   547134049),  INT32_C(   375624931), -INT32_C(  1876282747) } },
      { {  INT32_C(  2025772445),  INT32_C(   936528212),  INT32_C(  1649227485), -INT32_C(   571312280) },
        {  INT32_C(   737256350),  INT32_C(    11265207), -INT32_C(   447645731), -INT32_C(  1102361055) },
        {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) },
        {  INT32_C(   737256350),  INT32_C(    11265207),  INT32_C(  1649227485), -INT32_C(  1102361055) } },
      { { -INT32_C(   549685464),  INT32_C(   971040603),  INT32_C(  2132685150), -INT32_C(  1556190849) },
        { -INT32_C(   971344525), -INT32_C(  1091057282),  INT32_C(   929467076),  INT32_C(   944368399) },
        { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) },
        { -INT32_C(   549685464),  INT32_C(   971040603),  INT32_C(  2132685150), -INT32_C(  1556190849) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t mask = simde_wasm_v128_load(test_vec[i].mask);
      simde_v128_t r = simde_wasm_i32x4_blend(a, b, mask);
      simde_test_wasm_i32x4_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i32x4_random(),
        b = simde_test_wasm_i32x4_random(),
        mask = simde_wasm_i32x4_shr(simde_test_wasm_i32x4_random(), 31),
        r;

      r = simde_wasm_i32x4_blend(a, b, mask);

      simde_test_wasm_i32x4_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i32x4_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, mask, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i32x4_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_wasm_i64x2_blend(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t b[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t mask[sizeof(simde_v128_t) / sizeof(int64_t)];
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[] = {
      { { -INT64_C(  920230559648029186), -INT64_C( 1260599374326882247) },
        { -INT64_C( 5174174656278783751),  INT64_C(  227901295051177144) },
        { -INT64_C(                   1), -INT64_C(                   1) },
        { -INT64_C(  920230559648029186), -INT64_C( 1260599374326882247) } },
      { { -INT64_C( 2416918810298711507), -INT64_C( 7861527371947059491) },
        {  INT64_C( 8969767625585485343),  INT64_C( 5835319466009005665) },
        {  INT64_C(                   0),  INT64_C(                   0) },
        {  INT64_C( 8969767625585485343),  INT64_C( 5835319466009005665) } },
      { { -INT64_C( 6613997556779106663), -INT64_C( 8332271935948416534) },
        {  INT64_C( 5040138132682205949),  INT64_C(  810520879441068029) },
        {  INT64_C(                   0),  INT64_C(                   0) },
        {  INT64_C( 5040138132682205949),  INT64_C(  810520879441068029) } },
      { { -INT64_C( 8543658848418766532), -INT64_C( 1977126302010339822) },
        { -INT64_C( 1668121512941300234),  INT64_C( 6547745806153174316) },
        { -INT64_C(                   1),  INT64_C(                   0) },
        { -INT64_C( 8543658848418766532),  INT64_C( 6547745806153174316) } },
      { {  INT64_C( 4703844971547029517), -INT64_C( 9137620180819994697) },
        {  INT64_C( 2709879060874572645), -INT64_C( 8645716682788060227) },
        { -INT64_C(                   1), -INT64_C(                   1) },
        {  INT64_C( 4703844971547029517), -INT64_C( 9137620180819994697) } },
      { { -INT64_C(  199729314788289681), -INT64_C( 1859452044379490002) },
        {  INT64_C(  806334851516536955), -INT64_C( 1818383909588779911) },
        {  INT64_C(                   0),  INT64_C(                   0) },
        {  INT64_C(  806334851516536955), -INT64_C( 1818383909588779911) } },
      { {  INT64_C( 1977869283759027488), -INT64_C( 8293437078112952695) },
        {  INT64_C( 5010054574651597405), -INT64_C( 8803420830434632438) },
        { -INT64_C(                   1), -INT64_C(                   1) },
        {  INT64_C( 1977869283759027488), -INT64_C( 8293437078112952695) } },
      { { -INT64_C( 5337968786438725489),  INT64_C( 8863428825777084183) },
        { -INT64_C( 4203068692968641367), -INT64_C( 5930079492408315549) },
        { -INT64_C(                   1),  INT64_C(                   0) },
        { -INT64_C( 5337968786438725489), -INT64_C( 5930079492408315549) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t b = simde_wasm_v128_load(test_vec[i].b);
      simde_v128_t mask = simde_wasm_v128_load(test_vec[i].mask);
      simde_v128_t r = simde_wasm_i64x2_blend(a, b, mask);
      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t
        a = simde_test_wasm_i64x2_random(),
        b = simde_test_wasm_i64x2_random(),
        mask = simde_wasm_i64x2_shr(simde_test_wasm_i64x2_random(), 63),
        r;

      r = simde_wasm_i64x2_blend(a, b, mask);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_wasm_i64x2_write(3, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, mask, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_blend)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_blend)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_blend)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_blend)
SIMDE_TEST_FUNC_LIST_END

#include "test-relaxed-simd-footer.h"
