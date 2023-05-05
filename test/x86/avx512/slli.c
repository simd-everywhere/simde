/* SPDX-License-Identifier: MIT
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
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 *   2020      Hidayat Khan <huk2209@gmail.com>
 *   2020      Christopher Moore <moore@free.fr>
 */

#define SIMDE_TEST_X86_AVX512_INSN slli

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/slli.h>

static int
test_simde_mm512_slli_epi16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    const int16_t a[32];
    const int16_t r0[32];
    const int16_t r3[32];
    const int16_t r7[32];
    const int16_t r13[32];
    const int16_t r24[32];
  } test_vec[] = {
    { { -INT16_C(  4513), -INT16_C( 32064), -INT16_C( 20539),  INT16_C( 16953), -INT16_C( 19443),  INT16_C(  8904),  INT16_C( 17111), -INT16_C( 18058),
         INT16_C(  9034), -INT16_C( 18739), -INT16_C( 25271),  INT16_C(  4847), -INT16_C( 27918), -INT16_C(  9400), -INT16_C(  4204), -INT16_C(  3107),
        -INT16_C( 24867), -INT16_C( 23691), -INT16_C( 20915),  INT16_C( 23269), -INT16_C( 21149),  INT16_C( 14973), -INT16_C(  3088),  INT16_C( 15091),
        -INT16_C( 16362),  INT16_C( 24561), -INT16_C(  8099),  INT16_C( 20594), -INT16_C( 17806),  INT16_C(  1579),  INT16_C(  2218), -INT16_C( 30727) },
      { -INT16_C(  4513), -INT16_C( 32064), -INT16_C( 20539),  INT16_C( 16953), -INT16_C( 19443),  INT16_C(  8904),  INT16_C( 17111), -INT16_C( 18058),
         INT16_C(  9034), -INT16_C( 18739), -INT16_C( 25271),  INT16_C(  4847), -INT16_C( 27918), -INT16_C(  9400), -INT16_C(  4204), -INT16_C(  3107),
        -INT16_C( 24867), -INT16_C( 23691), -INT16_C( 20915),  INT16_C( 23269), -INT16_C( 21149),  INT16_C( 14973), -INT16_C(  3088),  INT16_C( 15091),
        -INT16_C( 16362),  INT16_C( 24561), -INT16_C(  8099),  INT16_C( 20594), -INT16_C( 17806),  INT16_C(  1579),  INT16_C(  2218), -INT16_C( 30727) },
      {  INT16_C( 29432),  INT16_C(  5632),  INT16_C( 32296),  INT16_C(  4552), -INT16_C( 24472),  INT16_C(  5696),  INT16_C(  5816), -INT16_C( 13392),
         INT16_C(  6736), -INT16_C( 18840), -INT16_C(  5560), -INT16_C( 26760), -INT16_C( 26736), -INT16_C(  9664),  INT16_C( 31904), -INT16_C( 24856),
        -INT16_C(  2328),  INT16_C(  7080),  INT16_C( 29288), -INT16_C( 10456),  INT16_C( 27416), -INT16_C( 11288), -INT16_C( 24704), -INT16_C( 10344),
         INT16_C(   176), -INT16_C(   120),  INT16_C(   744), -INT16_C( 31856), -INT16_C( 11376),  INT16_C( 12632),  INT16_C( 17744),  INT16_C( 16328) },
      {  INT16_C( 12160),  INT16_C( 24576), -INT16_C(  7552),  INT16_C(  7296),  INT16_C(  1664),  INT16_C( 25600),  INT16_C( 27520), -INT16_C( 17664),
        -INT16_C( 23296),  INT16_C( 26240), -INT16_C( 23424),  INT16_C( 30592),  INT16_C( 30976), -INT16_C( 23552), -INT16_C( 13824), -INT16_C(  4480),
         INT16_C( 28288), -INT16_C( 17792),  INT16_C(  9856),  INT16_C( 29312), -INT16_C( 20096),  INT16_C( 16000), -INT16_C(  2048),  INT16_C( 31104),
         INT16_C(  2816), -INT16_C(  1920),  INT16_C( 11904),  INT16_C( 14592),  INT16_C( 14592),  INT16_C(  5504),  INT16_C( 21760), -INT16_C(   896) },
      { -INT16_C(  8192),  INT16_C(     0), -INT16_C( 24576),  INT16_C(  8192), -INT16_C( 24576),  INT16_C(     0), -INT16_C(  8192), -INT16_C( 16384),
         INT16_C( 16384), -INT16_C( 24576),  INT16_C(  8192), -INT16_C(  8192),  INT16_C( 16384),  INT16_C(     0),       INT16_MIN, -INT16_C( 24576),
        -INT16_C( 24576), -INT16_C( 24576), -INT16_C( 24576), -INT16_C( 24576),  INT16_C( 24576), -INT16_C( 24576),  INT16_C(     0),  INT16_C( 24576),
        -INT16_C( 16384),  INT16_C(  8192), -INT16_C( 24576),  INT16_C( 16384),  INT16_C( 16384),  INT16_C( 24576),  INT16_C( 16384),  INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 28582), -INT16_C(  3030),  INT16_C(  3869), -INT16_C( 32690), -INT16_C( 13379), -INT16_C( 21062), -INT16_C( 20801), -INT16_C( 10777),
        -INT16_C( 10130), -INT16_C( 13259), -INT16_C( 22600),  INT16_C( 11036),  INT16_C( 18273),  INT16_C(  2865),  INT16_C( 11087), -INT16_C(  2413),
        -INT16_C( 16998), -INT16_C( 18454),  INT16_C( 14541), -INT16_C( 30152), -INT16_C(  3580), -INT16_C( 15561),  INT16_C(  7840),  INT16_C(  3992),
        -INT16_C( 12809), -INT16_C( 20517), -INT16_C(  2188), -INT16_C( 10534),  INT16_C(  3134), -INT16_C( 29215),  INT16_C( 29751), -INT16_C( 11901) },
      {  INT16_C( 28582), -INT16_C(  3030),  INT16_C(  3869), -INT16_C( 32690), -INT16_C( 13379), -INT16_C( 21062), -INT16_C( 20801), -INT16_C( 10777),
        -INT16_C( 10130), -INT16_C( 13259), -INT16_C( 22600),  INT16_C( 11036),  INT16_C( 18273),  INT16_C(  2865),  INT16_C( 11087), -INT16_C(  2413),
        -INT16_C( 16998), -INT16_C( 18454),  INT16_C( 14541), -INT16_C( 30152), -INT16_C(  3580), -INT16_C( 15561),  INT16_C(  7840),  INT16_C(  3992),
        -INT16_C( 12809), -INT16_C( 20517), -INT16_C(  2188), -INT16_C( 10534),  INT16_C(  3134), -INT16_C( 29215),  INT16_C( 29751), -INT16_C( 11901) },
      {  INT16_C( 32048), -INT16_C( 24240),  INT16_C( 30952),  INT16_C(   624),  INT16_C( 24040),  INT16_C( 28112),  INT16_C( 30200), -INT16_C( 20680),
        -INT16_C( 15504),  INT16_C( 25000),  INT16_C( 15808),  INT16_C( 22752),  INT16_C( 15112),  INT16_C( 22920),  INT16_C( 23160), -INT16_C( 19304),
        -INT16_C(  4912), -INT16_C( 16560), -INT16_C( 14744),  INT16_C( 20928), -INT16_C( 28640),  INT16_C(  6584), -INT16_C(  2816),  INT16_C( 31936),
         INT16_C( 28600),  INT16_C( 32472), -INT16_C( 17504), -INT16_C( 18736),  INT16_C( 25072),  INT16_C( 28424), -INT16_C( 24136), -INT16_C( 29672) },
      { -INT16_C( 11520),  INT16_C(  5376), -INT16_C( 29056),  INT16_C(  9984), -INT16_C(  8576), -INT16_C(  8960),  INT16_C( 24448), -INT16_C(  3200),
         INT16_C( 14080),  INT16_C(  6784), -INT16_C(  9216), -INT16_C( 29184), -INT16_C( 20352), -INT16_C( 26496), -INT16_C( 22656),  INT16_C( 18816),
        -INT16_C( 13056), -INT16_C(  2816),  INT16_C( 26240),  INT16_C(  7168),  INT16_C(   512), -INT16_C( 25728),  INT16_C( 20480), -INT16_C( 13312),
        -INT16_C(  1152), -INT16_C(  4736), -INT16_C( 17920),  INT16_C( 27904),  INT16_C(  7936), -INT16_C(  3968),  INT16_C(  7040), -INT16_C( 16000) },
      { -INT16_C( 16384),  INT16_C( 16384), -INT16_C( 24576), -INT16_C( 16384), -INT16_C( 24576),  INT16_C( 16384), -INT16_C(  8192), -INT16_C(  8192),
        -INT16_C( 16384), -INT16_C( 24576),  INT16_C(     0),       INT16_MIN,  INT16_C(  8192),  INT16_C(  8192), -INT16_C(  8192),  INT16_C( 24576),
         INT16_C( 16384),  INT16_C( 16384), -INT16_C( 24576),  INT16_C(     0),       INT16_MIN, -INT16_C(  8192),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(  8192),  INT16_C( 24576),       INT16_MIN,  INT16_C( 16384), -INT16_C( 16384),  INT16_C(  8192), -INT16_C(  8192),  INT16_C( 24576) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 27954), -INT16_C(   120), -INT16_C( 16218), -INT16_C( 21879), -INT16_C( 16205),  INT16_C( 21357),  INT16_C(  1502), -INT16_C( 10910),
         INT16_C( 15827),  INT16_C( 18309),  INT16_C( 24372),  INT16_C( 29213), -INT16_C(   149), -INT16_C( 24064), -INT16_C( 31885), -INT16_C( 23181),
        -INT16_C(   783), -INT16_C( 26716),  INT16_C( 11708),  INT16_C( 28481), -INT16_C( 20755), -INT16_C( 13117),  INT16_C(  9651), -INT16_C( 31071),
         INT16_C(  9827), -INT16_C( 26674), -INT16_C(  5242), -INT16_C(  3830),  INT16_C(  2794),  INT16_C( 24212),  INT16_C(  1933),  INT16_C( 32259) },
      {  INT16_C( 27954), -INT16_C(   120), -INT16_C( 16218), -INT16_C( 21879), -INT16_C( 16205),  INT16_C( 21357),  INT16_C(  1502), -INT16_C( 10910),
         INT16_C( 15827),  INT16_C( 18309),  INT16_C( 24372),  INT16_C( 29213), -INT16_C(   149), -INT16_C( 24064), -INT16_C( 31885), -INT16_C( 23181),
        -INT16_C(   783), -INT16_C( 26716),  INT16_C( 11708),  INT16_C( 28481), -INT16_C( 20755), -INT16_C( 13117),  INT16_C(  9651), -INT16_C( 31071),
         INT16_C(  9827), -INT16_C( 26674), -INT16_C(  5242), -INT16_C(  3830),  INT16_C(  2794),  INT16_C( 24212),  INT16_C(  1933),  INT16_C( 32259) },
      {  INT16_C( 27024), -INT16_C(   960),  INT16_C(  1328),  INT16_C( 21576),  INT16_C(  1432), -INT16_C( 25752),  INT16_C( 12016), -INT16_C( 21744),
        -INT16_C(  4456),  INT16_C( 15400), -INT16_C(  1632), -INT16_C( 28440), -INT16_C(  1192),  INT16_C(  4096),  INT16_C(  7064),  INT16_C( 11160),
        -INT16_C(  6264), -INT16_C( 17120),  INT16_C( 28128),  INT16_C( 31240),  INT16_C( 30568),  INT16_C( 26136),  INT16_C( 11672),  INT16_C( 13576),
         INT16_C( 13080), -INT16_C( 16784),  INT16_C( 23600), -INT16_C( 30640),  INT16_C( 22352), -INT16_C(  2912),  INT16_C( 15464), -INT16_C(  4072) },
      { -INT16_C( 26368), -INT16_C( 15360),  INT16_C( 21248),  INT16_C( 17536),  INT16_C( 22912), -INT16_C( 18816), -INT16_C(  4352), -INT16_C( 20224),
        -INT16_C(  5760), -INT16_C( 15744), -INT16_C( 26112),  INT16_C(  3712), -INT16_C( 19072),  INT16_C(     0), -INT16_C( 18048), -INT16_C( 18048),
         INT16_C( 30848), -INT16_C( 11776), -INT16_C(  8704), -INT16_C( 24448),  INT16_C( 30336),  INT16_C( 24960), -INT16_C(  9856),  INT16_C( 20608),
         INT16_C( 12672), -INT16_C(  6400), -INT16_C( 15616), -INT16_C( 31488),  INT16_C( 29952),  INT16_C( 18944), -INT16_C( 14720),  INT16_C(   384) },
      {  INT16_C( 16384),  INT16_C(     0), -INT16_C( 16384),  INT16_C(  8192),  INT16_C( 24576), -INT16_C( 24576), -INT16_C( 16384),  INT16_C( 16384),
         INT16_C( 24576), -INT16_C( 24576),       INT16_MIN, -INT16_C( 24576),  INT16_C( 24576),  INT16_C(     0),  INT16_C( 24576),  INT16_C( 24576),
         INT16_C(  8192),       INT16_MIN,       INT16_MIN,  INT16_C(  8192), -INT16_C( 24576),  INT16_C( 24576),  INT16_C( 24576),  INT16_C(  8192),
         INT16_C( 24576), -INT16_C( 16384), -INT16_C( 16384),  INT16_C( 16384),  INT16_C( 16384),       INT16_MIN, -INT16_C( 24576),  INT16_C( 24576) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 22525), -INT16_C( 16363),  INT16_C( 22229), -INT16_C( 15569), -INT16_C(  3580), -INT16_C( 18289),  INT16_C( 12312),  INT16_C( 31550),
         INT16_C(  3159), -INT16_C(  8942),  INT16_C(  7416), -INT16_C(  7474),  INT16_C( 25126), -INT16_C( 19392),  INT16_C( 17514),  INT16_C( 27954),
         INT16_C( 18668), -INT16_C( 16083),  INT16_C( 23966), -INT16_C( 23676),  INT16_C(  4943),  INT16_C( 26459), -INT16_C( 26300), -INT16_C( 25630),
        -INT16_C(  2650), -INT16_C( 24968),  INT16_C( 17937),  INT16_C( 14464), -INT16_C( 15959),  INT16_C(  5100),  INT16_C(  7685), -INT16_C(  3712) },
      { -INT16_C( 22525), -INT16_C( 16363),  INT16_C( 22229), -INT16_C( 15569), -INT16_C(  3580), -INT16_C( 18289),  INT16_C( 12312),  INT16_C( 31550),
         INT16_C(  3159), -INT16_C(  8942),  INT16_C(  7416), -INT16_C(  7474),  INT16_C( 25126), -INT16_C( 19392),  INT16_C( 17514),  INT16_C( 27954),
         INT16_C( 18668), -INT16_C( 16083),  INT16_C( 23966), -INT16_C( 23676),  INT16_C(  4943),  INT16_C( 26459), -INT16_C( 26300), -INT16_C( 25630),
        -INT16_C(  2650), -INT16_C( 24968),  INT16_C( 17937),  INT16_C( 14464), -INT16_C( 15959),  INT16_C(  5100),  INT16_C(  7685), -INT16_C(  3712) },
      {  INT16_C( 16408),  INT16_C(   168), -INT16_C( 18776),  INT16_C(  6520), -INT16_C( 28640), -INT16_C( 15240), -INT16_C( 32576), -INT16_C(  9744),
         INT16_C( 25272), -INT16_C(  6000), -INT16_C(  6208),  INT16_C(  5744),  INT16_C(  4400), -INT16_C( 24064),  INT16_C(  9040),  INT16_C( 27024),
         INT16_C( 18272),  INT16_C(  2408), -INT16_C(  4880),  INT16_C(  7200), -INT16_C( 25992),  INT16_C( 15064), -INT16_C( 13792), -INT16_C(  8432),
        -INT16_C( 21200), -INT16_C(  3136),  INT16_C( 12424), -INT16_C( 15360),  INT16_C(  3400), -INT16_C( 24736), -INT16_C(  4056), -INT16_C( 29696) },
      {  INT16_C(   384),  INT16_C(  2688),  INT16_C( 27264), -INT16_C( 26752),  INT16_C(   512),  INT16_C( 18304),  INT16_C(  3072), -INT16_C( 24832),
         INT16_C( 11136), -INT16_C( 30464),  INT16_C( 31744),  INT16_C( 26368),  INT16_C(  4864),  INT16_C(  8192),  INT16_C( 13568), -INT16_C( 26368),
         INT16_C( 30208), -INT16_C( 27008), -INT16_C( 12544), -INT16_C( 15872), -INT16_C( 22656), -INT16_C( 21120), -INT16_C( 24064), -INT16_C(  3840),
        -INT16_C( 11520),  INT16_C( 15360),  INT16_C(  2176),  INT16_C( 16384), -INT16_C( 11136), -INT16_C(  2560),  INT16_C(   640), -INT16_C( 16384) },
      {  INT16_C( 24576), -INT16_C( 24576), -INT16_C( 24576), -INT16_C(  8192),       INT16_MIN, -INT16_C(  8192),  INT16_C(     0), -INT16_C( 16384),
        -INT16_C(  8192),  INT16_C( 16384),  INT16_C(     0), -INT16_C( 16384), -INT16_C( 16384),  INT16_C(     0),  INT16_C( 16384),  INT16_C( 16384),
              INT16_MIN, -INT16_C( 24576), -INT16_C( 16384),       INT16_MIN, -INT16_C(  8192),  INT16_C( 24576),       INT16_MIN,  INT16_C( 16384),
        -INT16_C( 16384),  INT16_C(     0),  INT16_C(  8192),  INT16_C(     0),  INT16_C(  8192),       INT16_MIN, -INT16_C( 24576),  INT16_C(     0) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 20890),  INT16_C(  1458),  INT16_C( 14091),  INT16_C( 23208),  INT16_C(   842), -INT16_C( 28990), -INT16_C( 23396),  INT16_C( 16937),
        -INT16_C( 24167), -INT16_C( 21536),  INT16_C( 25064), -INT16_C( 28189), -INT16_C( 12510),  INT16_C( 10148),  INT16_C(  9453),  INT16_C( 21528),
        -INT16_C( 13614), -INT16_C(  8871),  INT16_C(   257),  INT16_C( 19512), -INT16_C(  1532), -INT16_C( 24358),  INT16_C(  1182),  INT16_C( 14563),
        -INT16_C( 15451), -INT16_C( 29213), -INT16_C( 14812),  INT16_C( 17950), -INT16_C( 15723), -INT16_C( 32147), -INT16_C( 31257), -INT16_C( 17962) },
      { -INT16_C( 20890),  INT16_C(  1458),  INT16_C( 14091),  INT16_C( 23208),  INT16_C(   842), -INT16_C( 28990), -INT16_C( 23396),  INT16_C( 16937),
        -INT16_C( 24167), -INT16_C( 21536),  INT16_C( 25064), -INT16_C( 28189), -INT16_C( 12510),  INT16_C( 10148),  INT16_C(  9453),  INT16_C( 21528),
        -INT16_C( 13614), -INT16_C(  8871),  INT16_C(   257),  INT16_C( 19512), -INT16_C(  1532), -INT16_C( 24358),  INT16_C(  1182),  INT16_C( 14563),
        -INT16_C( 15451), -INT16_C( 29213), -INT16_C( 14812),  INT16_C( 17950), -INT16_C( 15723), -INT16_C( 32147), -INT16_C( 31257), -INT16_C( 17962) },
      {  INT16_C( 29488),  INT16_C( 11664), -INT16_C( 18344), -INT16_C( 10944),  INT16_C(  6736),  INT16_C( 30224),  INT16_C(  9440),  INT16_C(  4424),
         INT16_C(  3272),  INT16_C( 24320),  INT16_C(  3904), -INT16_C( 28904),  INT16_C( 30992),  INT16_C( 15648),  INT16_C( 10088), -INT16_C( 24384),
         INT16_C( 22160), -INT16_C(  5432),  INT16_C(  2056),  INT16_C( 25024), -INT16_C( 12256),  INT16_C(  1744),  INT16_C(  9456), -INT16_C( 14568),
         INT16_C(  7464),  INT16_C( 28440),  INT16_C( 12576),  INT16_C( 12528),  INT16_C(  5288),  INT16_C(  4968),  INT16_C( 12088), -INT16_C( 12624) },
      {  INT16_C( 13056), -INT16_C(  9984), -INT16_C( 31360),  INT16_C( 21504), -INT16_C( 23296),  INT16_C( 24832),  INT16_C( 19968),  INT16_C(  5248),
        -INT16_C( 13184), -INT16_C(  4096), -INT16_C(  3072), -INT16_C(  3712), -INT16_C( 28416), -INT16_C( 11776),  INT16_C( 30336),  INT16_C(  3072),
         INT16_C( 26880), -INT16_C( 21376), -INT16_C( 32640),  INT16_C(  7168),  INT16_C(   512),  INT16_C( 27904),  INT16_C( 20224),  INT16_C( 29056),
        -INT16_C( 11648), -INT16_C(  3712),  INT16_C(  4608),  INT16_C(  3840),  INT16_C( 19072),  INT16_C( 13952), -INT16_C(  3200), -INT16_C(  5376) },
      { -INT16_C( 16384),  INT16_C( 16384),  INT16_C( 24576),  INT16_C(     0),  INT16_C( 16384),  INT16_C( 16384),       INT16_MIN,  INT16_C(  8192),
         INT16_C(  8192),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24576),  INT16_C( 16384),       INT16_MIN, -INT16_C( 24576),  INT16_C(     0),
         INT16_C( 16384),  INT16_C(  8192),  INT16_C(  8192),  INT16_C(     0),       INT16_MIN,  INT16_C( 16384), -INT16_C( 16384),  INT16_C( 24576),
        -INT16_C( 24576),  INT16_C( 24576),       INT16_MIN, -INT16_C( 16384), -INT16_C( 24576), -INT16_C( 24576), -INT16_C(  8192), -INT16_C( 16384) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 12112),  INT16_C( 20887), -INT16_C( 12496),  INT16_C( 13469),  INT16_C( 30921),  INT16_C( 26581), -INT16_C( 18308),  INT16_C(  8607),
        -INT16_C( 32133), -INT16_C( 24401), -INT16_C( 12984), -INT16_C(  8730),  INT16_C( 21648),  INT16_C( 30560),  INT16_C( 14041),  INT16_C( 10544),
        -INT16_C( 14490), -INT16_C( 27013),  INT16_C(  6294),  INT16_C( 24523), -INT16_C( 24432),  INT16_C(  3271),  INT16_C( 26200), -INT16_C( 11474),
        -INT16_C(  8727),  INT16_C( 12659),  INT16_C( 23210),  INT16_C( 14863),  INT16_C( 28590), -INT16_C( 30799), -INT16_C(  7515),  INT16_C(  2993) },
      {  INT16_C( 12112),  INT16_C( 20887), -INT16_C( 12496),  INT16_C( 13469),  INT16_C( 30921),  INT16_C( 26581), -INT16_C( 18308),  INT16_C(  8607),
        -INT16_C( 32133), -INT16_C( 24401), -INT16_C( 12984), -INT16_C(  8730),  INT16_C( 21648),  INT16_C( 30560),  INT16_C( 14041),  INT16_C( 10544),
        -INT16_C( 14490), -INT16_C( 27013),  INT16_C(  6294),  INT16_C( 24523), -INT16_C( 24432),  INT16_C(  3271),  INT16_C( 26200), -INT16_C( 11474),
        -INT16_C(  8727),  INT16_C( 12659),  INT16_C( 23210),  INT16_C( 14863),  INT16_C( 28590), -INT16_C( 30799), -INT16_C(  7515),  INT16_C(  2993) },
      {  INT16_C( 31360), -INT16_C( 29512),  INT16_C( 31104), -INT16_C( 23320), -INT16_C( 14776),  INT16_C( 16040), -INT16_C( 15392),  INT16_C(  3320),
         INT16_C(  5080),  INT16_C(  1400),  INT16_C( 27200), -INT16_C(  4304), -INT16_C( 23424), -INT16_C( 17664), -INT16_C( 18744),  INT16_C( 18816),
         INT16_C( 15152), -INT16_C( 19496), -INT16_C( 15184), -INT16_C(   424),  INT16_C(  1152),  INT16_C( 26168),  INT16_C( 12992), -INT16_C( 26256),
        -INT16_C(  4280), -INT16_C( 29800), -INT16_C( 10928), -INT16_C( 12168),  INT16_C( 32112),  INT16_C( 15752),  INT16_C(  5416),  INT16_C( 23944) },
      { -INT16_C( 22528), -INT16_C( 13440), -INT16_C( 26624),  INT16_C( 20096),  INT16_C( 25728), -INT16_C(  5504),  INT16_C( 15872), -INT16_C( 12416),
         INT16_C( 15744),  INT16_C( 22400), -INT16_C( 23552), -INT16_C(  3328),  INT16_C( 18432), -INT16_C( 20480),  INT16_C( 27776), -INT16_C( 26624),
        -INT16_C( 19712),  INT16_C( 15744),  INT16_C( 19200), -INT16_C(  6784),  INT16_C( 18432),  INT16_C( 25472),  INT16_C( 11264), -INT16_C( 26880),
        -INT16_C(  2944), -INT16_C( 18048),  INT16_C( 21760),  INT16_C(  1920), -INT16_C( 10496), -INT16_C( 10112),  INT16_C( 21120), -INT16_C( 10112) },
      {  INT16_C(     0), -INT16_C(  8192),  INT16_C(     0), -INT16_C( 24576),  INT16_C(  8192), -INT16_C( 24576),       INT16_MIN, -INT16_C(  8192),
         INT16_C( 24576), -INT16_C(  8192),  INT16_C(     0), -INT16_C( 16384),  INT16_C(     0),  INT16_C(     0),  INT16_C(  8192),  INT16_C(     0),
        -INT16_C( 16384),  INT16_C( 24576), -INT16_C( 16384),  INT16_C( 24576),  INT16_C(     0), -INT16_C(  8192),  INT16_C(     0), -INT16_C( 16384),
         INT16_C(  8192),  INT16_C( 24576),  INT16_C( 16384), -INT16_C(  8192), -INT16_C( 16384),  INT16_C(  8192), -INT16_C( 24576),  INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 11433),  INT16_C( 16546),  INT16_C( 27972), -INT16_C( 10849),  INT16_C( 26125),  INT16_C( 26081),  INT16_C(  4045), -INT16_C( 18888),
        -INT16_C( 21268), -INT16_C( 26649), -INT16_C(  2554), -INT16_C( 19247), -INT16_C( 31899),  INT16_C(  2875), -INT16_C(  5019),  INT16_C(  3606),
        -INT16_C( 18408),  INT16_C( 23886), -INT16_C(  4571),  INT16_C( 12850),  INT16_C(  4948),  INT16_C(  8599), -INT16_C( 12253),  INT16_C(  4055),
        -INT16_C( 16516), -INT16_C( 32090),  INT16_C( 30901),  INT16_C(  6966),  INT16_C( 29179),  INT16_C( 24614),  INT16_C( 15454),  INT16_C( 30318) },
      {  INT16_C( 11433),  INT16_C( 16546),  INT16_C( 27972), -INT16_C( 10849),  INT16_C( 26125),  INT16_C( 26081),  INT16_C(  4045), -INT16_C( 18888),
        -INT16_C( 21268), -INT16_C( 26649), -INT16_C(  2554), -INT16_C( 19247), -INT16_C( 31899),  INT16_C(  2875), -INT16_C(  5019),  INT16_C(  3606),
        -INT16_C( 18408),  INT16_C( 23886), -INT16_C(  4571),  INT16_C( 12850),  INT16_C(  4948),  INT16_C(  8599), -INT16_C( 12253),  INT16_C(  4055),
        -INT16_C( 16516), -INT16_C( 32090),  INT16_C( 30901),  INT16_C(  6966),  INT16_C( 29179),  INT16_C( 24614),  INT16_C( 15454),  INT16_C( 30318) },
      {  INT16_C( 25928),  INT16_C(  1296),  INT16_C( 27168), -INT16_C( 21256),  INT16_C( 12392),  INT16_C( 12040),  INT16_C( 32360), -INT16_C( 20032),
         INT16_C( 26464), -INT16_C( 16584), -INT16_C( 20432), -INT16_C( 22904),  INT16_C(  6952),  INT16_C( 23000),  INT16_C( 25384),  INT16_C( 28848),
        -INT16_C( 16192), -INT16_C(  5520),  INT16_C( 28968), -INT16_C( 28272), -INT16_C( 25952),  INT16_C(  3256), -INT16_C( 32488),  INT16_C( 32440),
        -INT16_C(  1056),  INT16_C(  5424), -INT16_C( 14936), -INT16_C(  9808), -INT16_C( 28712),  INT16_C(   304), -INT16_C(  7440), -INT16_C( 19600) },
      {  INT16_C( 21632),  INT16_C( 20736), -INT16_C( 24064), -INT16_C( 12416),  INT16_C(  1664), -INT16_C(  3968), -INT16_C(  6528),  INT16_C(  7168),
         INT16_C( 30208), -INT16_C(  3200),  INT16_C(   768),  INT16_C( 26752), -INT16_C( 19840), -INT16_C( 25216),  INT16_C( 12928),  INT16_C(  2816),
         INT16_C(  3072), -INT16_C( 22784),  INT16_C(  4736),  INT16_C(  6400), -INT16_C( 22016), -INT16_C( 13440),  INT16_C(  4480), -INT16_C(  5248),
        -INT16_C( 16896),  INT16_C( 21248),  INT16_C( 23168), -INT16_C( 25856), -INT16_C(   640),  INT16_C(  4864),  INT16_C( 12032),  INT16_C( 14080) },
      {  INT16_C(  8192),  INT16_C( 16384),       INT16_MIN, -INT16_C(  8192), -INT16_C( 24576),  INT16_C(  8192), -INT16_C( 24576),  INT16_C(     0),
              INT16_MIN, -INT16_C(  8192), -INT16_C( 16384),  INT16_C(  8192), -INT16_C( 24576),  INT16_C( 24576), -INT16_C( 24576), -INT16_C( 16384),
         INT16_C(     0), -INT16_C( 16384), -INT16_C( 24576),  INT16_C( 16384),       INT16_MIN, -INT16_C(  8192),  INT16_C( 24576), -INT16_C(  8192),
              INT16_MIN, -INT16_C( 16384), -INT16_C( 24576), -INT16_C( 16384),  INT16_C( 24576), -INT16_C( 16384), -INT16_C( 16384), -INT16_C( 16384) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 16907),  INT16_C(  6867),  INT16_C(  1451), -INT16_C(   179), -INT16_C(  7143),  INT16_C( 15393), -INT16_C(  1868),  INT16_C( 12363),
        -INT16_C(  3401),  INT16_C( 28082), -INT16_C(  6038),  INT16_C( 25992), -INT16_C( 20902), -INT16_C( 18235),  INT16_C( 13290), -INT16_C(  8402),
         INT16_C(   752), -INT16_C( 25606),  INT16_C( 18183),  INT16_C(  8347), -INT16_C( 17365), -INT16_C(  8100), -INT16_C( 22348),  INT16_C( 27664),
        -INT16_C( 15462),  INT16_C(  1241),  INT16_C( 25003),  INT16_C(  1385),  INT16_C( 11791), -INT16_C(  1603), -INT16_C(  5023),  INT16_C( 21209) },
      { -INT16_C( 16907),  INT16_C(  6867),  INT16_C(  1451), -INT16_C(   179), -INT16_C(  7143),  INT16_C( 15393), -INT16_C(  1868),  INT16_C( 12363),
        -INT16_C(  3401),  INT16_C( 28082), -INT16_C(  6038),  INT16_C( 25992), -INT16_C( 20902), -INT16_C( 18235),  INT16_C( 13290), -INT16_C(  8402),
         INT16_C(   752), -INT16_C( 25606),  INT16_C( 18183),  INT16_C(  8347), -INT16_C( 17365), -INT16_C(  8100), -INT16_C( 22348),  INT16_C( 27664),
        -INT16_C( 15462),  INT16_C(  1241),  INT16_C( 25003),  INT16_C(  1385),  INT16_C( 11791), -INT16_C(  1603), -INT16_C(  5023),  INT16_C( 21209) },
      { -INT16_C(  4184), -INT16_C( 10600),  INT16_C( 11608), -INT16_C(  1432),  INT16_C(  8392), -INT16_C(  7928), -INT16_C( 14944), -INT16_C( 32168),
        -INT16_C( 27208),  INT16_C( 28048),  INT16_C( 17232),  INT16_C( 11328),  INT16_C( 29392), -INT16_C( 14808), -INT16_C( 24752), -INT16_C(  1680),
         INT16_C(  6016), -INT16_C(  8240),  INT16_C( 14392),  INT16_C(  1240), -INT16_C(  7848),  INT16_C(   736),  INT16_C( 17824),  INT16_C( 24704),
         INT16_C(  7376),  INT16_C(  9928),  INT16_C(  3416),  INT16_C( 11080),  INT16_C( 28792), -INT16_C( 12824),  INT16_C( 25352), -INT16_C( 26936) },
      { -INT16_C(  1408),  INT16_C( 27008), -INT16_C( 10880), -INT16_C( 22912),  INT16_C(  3200),  INT16_C(  4224),  INT16_C( 23040),  INT16_C(  9600),
         INT16_C( 23424), -INT16_C(  9984),  INT16_C( 13568), -INT16_C( 15360),  INT16_C( 11520),  INT16_C( 25216), -INT16_C(  2816), -INT16_C( 26880),
         INT16_C( 30720), -INT16_C(   768), -INT16_C( 31872),  INT16_C( 19840),  INT16_C(  5504),  INT16_C( 11776),  INT16_C( 23040),  INT16_C(  2048),
        -INT16_C( 13056),  INT16_C( 27776), -INT16_C( 10880), -INT16_C( 19328),  INT16_C(  1920), -INT16_C(  8576),  INT16_C( 12416),  INT16_C( 27776) },
      { -INT16_C( 24576),  INT16_C( 24576),  INT16_C( 24576), -INT16_C( 24576),  INT16_C(  8192),  INT16_C(  8192),       INT16_MIN,  INT16_C( 24576),
        -INT16_C(  8192),  INT16_C( 16384),  INT16_C( 16384),  INT16_C(     0),  INT16_C( 16384), -INT16_C( 24576),  INT16_C( 16384), -INT16_C( 16384),
         INT16_C(     0),  INT16_C( 16384), -INT16_C(  8192),  INT16_C( 24576),  INT16_C( 24576),       INT16_MIN,       INT16_MIN,  INT16_C(     0),
         INT16_C( 16384),  INT16_C(  8192),  INT16_C( 24576),  INT16_C(  8192), -INT16_C(  8192), -INT16_C( 24576),  INT16_C(  8192),  INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a, r0, r3, r7, r13, r24;
    a = simde_mm512_loadu_epi16(test_vec[i].a);
    r0 = simde_mm512_slli_epi16(a, 0);
    simde_test_x86_assert_equal_i16x32(r0, simde_mm512_loadu_epi16(test_vec[i].r0));
    r3 = simde_mm512_slli_epi16(a, 3);
    simde_test_x86_assert_equal_i16x32(r3, simde_mm512_loadu_epi16(test_vec[i].r3));
    r7 = simde_mm512_slli_epi16(a, 7);
    simde_test_x86_assert_equal_i16x32(r7, simde_mm512_loadu_epi16(test_vec[i].r7));
    r13 = simde_mm512_slli_epi16(a, 13);
    simde_test_x86_assert_equal_i16x32(r13, simde_mm512_loadu_epi16(test_vec[i].r13));
    r24 = simde_mm512_slli_epi16(a, 24);
    simde_test_x86_assert_equal_i16x32(r24, simde_mm512_loadu_epi16(test_vec[i].r24));
  }

  return 0;
}

static int
test_simde_mm512_slli_epi32(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    unsigned int b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi32(INT32_C( -687706949), INT32_C( 1593775683), INT32_C(  332932989), INT32_C(  583872054),
                            INT32_C( 1838832857), INT32_C(  847835558), INT32_C(-1396128258), INT32_C( -183977070),
                            INT32_C( -902383138), INT32_C( -512492201), INT32_C(-1812249336), INT32_C( -562835271),
                            INT32_C(-1029714159), INT32_C( 1476158556), INT32_C(  877549641), INT32_C( 1218378177)),
      0xac,
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm512_set_epi32(INT32_C(  241549121), INT32_C( 1732816264), INT32_C(  875489890), INT32_C(   72071518),
                            INT32_C(-1641761300), INT32_C(  313288882), INT32_C(-1735158939), INT32_C( 1219761116),
                            INT32_C(  877921588), INT32_C( 2045964482), INT32_C( -360092415), INT32_C(-1302958505),
                            INT32_C(-1122092800), INT32_C( -177019481), INT32_C(  875636041), INT32_C( -150268654)),
      0x8017,
      simde_mm512_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)) },
    { simde_mm512_set_epi32(INT32_C(  -52534216), INT32_C( -794188551), INT32_C( -186449823), INT32_C( 1580979103),
                            INT32_C( -972993456), INT32_C( -666426563), INT32_C( -645023430), INT32_C(-1043227266),
                            INT32_C( 1237525980), INT32_C(  349749966), INT32_C( -978999744), INT32_C( -487689408),
                            INT32_C(  898649460), INT32_C(-1217796896), INT32_C( 1277301360), INT32_C( 1454357892)),
      0x10,
      simde_mm512_set_epi32(INT32_C( 1681391616), INT32_C(-1527185408), INT32_C(    6356992), INT32_C( -744554496),
                            INT32_C( 1280311296), INT32_C(  591200256), INT32_C(-1187381248), INT32_C(-1652686848),
                            INT32_C(  635174912), INT32_C(-1026686976), INT32_C(-1505755136), INT32_C( 1933574144),
                            INT32_C( 1299447808), INT32_C( -455081984), INT32_C(  309329920), INT32_C(-1115422720)) },
    { simde_mm512_set_epi32(INT32_C(-1898779532), INT32_C( 1141724513), INT32_C( -782352739), INT32_C(  973072470),
                            INT32_C( 1112939167), INT32_C(  368903984), INT32_C( 1631675339), INT32_C(  -86505288),
                            INT32_C( 2011287771), INT32_C( 1938765310), INT32_C( 2078191935), INT32_C( -616151900),
                            INT32_C( -454977425), INT32_C(  544105809), INT32_C(-1307935124), INT32_C(-1400984309)),
      0xa,
      simde_mm512_set_epi32(INT32_C( 1269944320), INT32_C(  894796800), INT32_C( 2029679616), INT32_C(   -6203392),
                            INT32_C( 1483373568), INT32_C( -199442432), INT32_C(   93268992), INT32_C( 1612898304),
                            INT32_C(-2025624576), INT32_C( 1020786688), INT32_C( 2059729920), INT32_C(  420646912),
                            INT32_C(-2040415232), INT32_C(-1181400064), INT32_C(  704229376), INT32_C(  -88855552)) },
    { simde_mm512_set_epi32(INT32_C( -955538666), INT32_C( 1399393330), INT32_C( 1832782688), INT32_C(-1931362608),
                            INT32_C(-1247233529), INT32_C( -537843102), INT32_C( -120831887), INT32_C( 1329473476),
                            INT32_C( 1569899726), INT32_C(  920247722), INT32_C(  275348332), INT32_C( 1640312018),
                            INT32_C( -873496512), INT32_C(  957396290), INT32_C(  390504842), INT32_C( 1781792417)),
      0xf,
      simde_mm512_set_epi32(INT32_C( -779419648), INT32_C(-2045181952), INT32_C(   95420416), INT32_C( -546832384),
                            INT32_C( 1560510464), INT32_C(-1791950848), INT32_C(  540573696), INT32_C(  333578240),
                            INT32_C( 1650917376), INT32_C( -288030720), INT32_C(-1112145920), INT32_C(-1771503616),
                            INT32_C(-1071644672), INT32_C( 1520500736), INT32_C( 1355087872), INT32_C(  -11501568)) },
    { simde_mm512_set_epi32(INT32_C(  188085108), INT32_C(  489074602), INT32_C( 1720231560), INT32_C(  106164094),
                            INT32_C( 1250223633), INT32_C( -962071158), INT32_C(   38255424), INT32_C(  801121683),
                            INT32_C(-1580720854), INT32_C(  609844423), INT32_C(   44983522), INT32_C(  481953328),
                            INT32_C( -181212371), INT32_C(  912186226), INT32_C(  -42587351), INT32_C(  680089879)),
      0x18,
      simde_mm512_set_epi32(INT32_C( 1946157056), INT32_C(-1442840576), INT32_C(-2013265920), INT32_C( 2113929216),
                            INT32_C(  285212672), INT32_C(-1979711488), INT32_C( 1073741824), INT32_C(-1828716544),
                            INT32_C(  704643072), INT32_C( -956301312), INT32_C( -503316480), INT32_C(  805306368),
                            INT32_C(  754974720), INT32_C( 1912602624), INT32_C(  687865856), INT32_C(  385875968)) },
    { simde_mm512_set_epi32(INT32_C(-1878529143), INT32_C(  968369206), INT32_C(-2025408372), INT32_C( -521427427),
                            INT32_C(  750337953), INT32_C( 1599422728), INT32_C( 1832999614), INT32_C( -922516627),
                            INT32_C( 1054703043), INT32_C( -229764941), INT32_C(-1888970968), INT32_C( -770679003),
                            INT32_C(  957667650), INT32_C(-1367078699), INT32_C(  400185050), INT32_C(  619858989)),
      0,
      simde_mm512_set_epi32(INT32_C(-1878529143), INT32_C(  968369206), INT32_C(-2025408372), INT32_C( -521427427),
                            INT32_C(  750337953), INT32_C( 1599422728), INT32_C( 1832999614), INT32_C( -922516627),
                            INT32_C( 1054703043), INT32_C( -229764941), INT32_C(-1888970968), INT32_C( -770679003),
                            INT32_C(  957667650), INT32_C(-1367078699), INT32_C(  400185050), INT32_C(  619858989)) },
    { simde_mm512_set_epi32(INT32_C( -939632719), INT32_C( 1727963384), INT32_C( 1880331239), INT32_C(  699090974),
                            INT32_C( 1068401563), INT32_C(-1558361689), INT32_C(-1814494206), INT32_C( 1865180366),
                            INT32_C(-1767733366), INT32_C(-1147256695), INT32_C(-1631901793), INT32_C( -198157319),
                            INT32_C(  285018015), INT32_C(  583696937), INT32_C( 1785762602), INT32_C(-1724046997)),
      0x16,
      simde_mm512_set_epi32(INT32_C( -331350016), INT32_C( 1040187392), INT32_C( -104857600), INT32_C(  125829120),
                            INT32_C( -423624704), INT32_C( 1774190592), INT32_C(    8388608), INT32_C(  864026624),
                            INT32_C( -494927872), INT32_C(  574619648), INT32_C( -406847488), INT32_C(  -29360128),
                            INT32_C( -406847488), INT32_C(-1975517184), INT32_C( -897581056), INT32_C( 1522532352)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_slli_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_slli_epi64(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    unsigned int b;
    simde__m512i r;
  } test_vec[8] = {
    { simde_mm512_set_epi64(INT64_C(-2953678853593164221), INT64_C( 1429936300098399798),
                            INT64_C( 7897726984473080230), INT64_C(-5996325205020460142),
                            INT64_C(-3875706062389379753), INT64_C(-7783551626585583431),
                            INT64_C(-4422588635656985508), INT64_C( 3769047009929918913)),
      0xac,
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { simde_mm512_set_epi64(INT64_C( 1037445576805363080), INT64_C( 3760200445600708958),
                            INT64_C(-7051311091025155918), INT64_C(-7452450895147297828),
                            INT64_C( 3770644510958350530), INT64_C(-1546585142970651049),
                            INT64_C(-4819351874959120985), INT64_C( 3760828163438613778)),
      0x8017,
      simde_mm512_set_epi64(INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0),
                            INT64_C(                   0), INT64_C(                   0)) },
    { simde_mm512_set_epi64(INT64_C( -225632736140221191), INT64_C( -800795890549009505),
                            INT64_C(-4178975069113474243), INT64_C(-2770354533752005250),
                            INT64_C( 5315133612400100046), INT64_C(-4204771879465094336),
                            INT64_C( 3859670044345230560), INT64_C( 5485967569790680452)),
      0x10,
      simde_mm512_set_epi64(INT64_C( 7221751429524422656), INT64_C(   27406683787427840),
                            INT64_C( 5499132945064853504), INT64_C(-5099550522009059328),
                            INT64_C( 2728078395493449728), INT64_C(-6466919551140364288),
                            INT64_C( 5581287503658221568), INT64_C( 1328657202873106432)) },
    { simde_mm512_set_epi64(INT64_C(  854012069371251830), INT64_C(-7338075353641633319),
                            INT64_C(-3664756911608965568), INT64_C( 6190577389993756354),
                            INT64_C(-5695521678932466387), INT64_C( 8986269833406294113),
                            INT64_C(-6594347992267195055), INT64_C(  897886006004895547)),
      0x2a,
      simde_mm512_set_epi64(INT64_C( 1455181649128980480), INT64_C(-8005319861464989696),
                            INT64_C(-8117456853358608384), INT64_C(-7918726723707863040),
                            INT64_C(-4137484245553643520), INT64_C( -675113333593997312),
                            INT64_C( 7635083510067232768), INT64_C(-2504867807980683264)) },
    { simde_mm512_set_epi64(INT64_C( 6876450537877586373), INT64_C(-2498836913726354503),
                            INT64_C(-5925650014767999746), INT64_C(-5091981247482556140),
                            INT64_C( 2276397305581596841), INT64_C( 4333846664358463853),
                            INT64_C( -724672155607878887), INT64_C( 3417746373838389455)),
      0x2a,
      simde_mm512_set_epi64(INT64_C( -934756407423533056), INT64_C(-3157335600089006080),
                            INT64_C(-2570438283414732800), INT64_C( 7513218039291052032),
                            INT64_C( 7188488275143688192), INT64_C( 7216371890024087552),
                            INT64_C(-9165841190443024384), INT64_C( 1225889494272573440)) },
    { simde_mm512_set_epi64(INT64_C(-8036497785869311574), INT64_C( 3581702479948115598),
                            INT64_C(  748249211564829520), INT64_C( -816680525172154454),
                            INT64_C(-4839891842343135042), INT64_C(-6001583230129728210),
                            INT64_C(-4279294013059977744), INT64_C(-1555144075545091790)),
      0x26,
      simde_mm512_set_epi64(INT64_C(-4397647938138931200), INT64_C( 2043406626093793280),
                            INT64_C(-5590422890961960960), INT64_C(-8604150727591329792),
                            INT64_C( 8423472379845410816), INT64_C(-8411233715916636160),
                            INT64_C(-8742757912167841792), INT64_C(-6541394346116120576)) },
    { simde_mm512_set_epi64(INT64_C(-6276545081940248579), INT64_C(-9016855820360504888),
                            INT64_C( 2589347389053699338), INT64_C(-6212989007002338187),
                            INT64_C( 5925964847698460032), INT64_C( 8758478916256841908),
                            INT64_C( 5134329058456078862), INT64_C(-4414137185393506410)),
      0x18,
      simde_mm512_set_epi64(INT64_C(-9176583453456465920), INT64_C( 7465982649455083520),
                            INT64_C(-4954907897243893760), INT64_C( 7673069422566703104),
                            INT64_C(-6790719338690117632), INT64_C( 3134572139001151488),
                            INT64_C( 1398716822424911872), INT64_C(-7065366029995606016)) },
    { simde_mm512_set_epi64(INT64_C(-4035691796628594440), INT64_C( 8075961177851250718),
                            INT64_C( 4588749774816889255), INT64_C(-7793193271686306610),
                            INT64_C(-7592356991870287735), INT64_C(-7008964827121951751),
                            INT64_C( 1224143053779534377), INT64_C( 7669791976580784491)),
      0x16,
      simde_mm512_set_epi64(INT64_C(-1415889878515712000), INT64_C( -447427762668437504),
                            INT64_C(-1807976093613817856), INT64_C(   43851930488799232),
                            INT64_C(-2112496568954257408), INT64_C(-1730213388945981440),
                            INT64_C(-1744948453022105600), INT64_C(-3844298059735367680)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_slli_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_slli_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_slli_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_slli_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
