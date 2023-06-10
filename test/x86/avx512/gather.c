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
 *   2023      Michael R. Crusoe <crusoe@debian.org>
 */

#define SIMDE_TEST_X86_AVX512_INSN gather

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/gather.h>

static simde_float32 f32gather_buffer[8192];

static int
test_simde_mm512_i32gather_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t vindex[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { {  INT32_C(          91),  INT32_C(           6),  INT32_C(         243),  INT32_C(         110),  INT32_C(         160),  INT32_C(           8),  INT32_C(          28),  INT32_C(         103),
         INT32_C(         208),  INT32_C(         170),  INT32_C(         227),  INT32_C(         152),  INT32_C(          69),  INT32_C(         234),  INT32_C(         211),  INT32_C(         131) },
      { SIMDE_FLOAT32_C(   182.00), SIMDE_FLOAT32_C(    12.00), SIMDE_FLOAT32_C(   486.00), SIMDE_FLOAT32_C(   220.00),
        SIMDE_FLOAT32_C(   320.00), SIMDE_FLOAT32_C(    16.00), SIMDE_FLOAT32_C(    56.00), SIMDE_FLOAT32_C(   206.00),
        SIMDE_FLOAT32_C(   416.00), SIMDE_FLOAT32_C(   340.00), SIMDE_FLOAT32_C(   454.00), SIMDE_FLOAT32_C(   304.00),
        SIMDE_FLOAT32_C(   138.00), SIMDE_FLOAT32_C(   468.00), SIMDE_FLOAT32_C(   422.00), SIMDE_FLOAT32_C(   262.00) } },
    { {  INT32_C(         180),  INT32_C(         211),  INT32_C(         170),  INT32_C(         243),  INT32_C(         162),  INT32_C(         194),  INT32_C(          27),  INT32_C(         150),
         INT32_C(         247),  INT32_C(          93),  INT32_C(         249),  INT32_C(          19),  INT32_C(         102),  INT32_C(          42),  INT32_C(         208),  INT32_C(         193) },
      { SIMDE_FLOAT32_C(   360.00), SIMDE_FLOAT32_C(   422.00), SIMDE_FLOAT32_C(   340.00), SIMDE_FLOAT32_C(   486.00),
        SIMDE_FLOAT32_C(   324.00), SIMDE_FLOAT32_C(   388.00), SIMDE_FLOAT32_C(    54.00), SIMDE_FLOAT32_C(   300.00),
        SIMDE_FLOAT32_C(   494.00), SIMDE_FLOAT32_C(   186.00), SIMDE_FLOAT32_C(   498.00), SIMDE_FLOAT32_C(    38.00),
        SIMDE_FLOAT32_C(   204.00), SIMDE_FLOAT32_C(    84.00), SIMDE_FLOAT32_C(   416.00), SIMDE_FLOAT32_C(   386.00) } },
    { {  INT32_C(          49),  INT32_C(         196),  INT32_C(          48),  INT32_C(         209),  INT32_C(         204),  INT32_C(          76),  INT32_C(          56),  INT32_C(         156),
         INT32_C(         246),  INT32_C(          27),  INT32_C(          52),  INT32_C(          60),  INT32_C(           5),  INT32_C(           8),  INT32_C(         191),  INT32_C(         186) },
      { SIMDE_FLOAT32_C(    98.00), SIMDE_FLOAT32_C(   392.00), SIMDE_FLOAT32_C(    96.00), SIMDE_FLOAT32_C(   418.00),
        SIMDE_FLOAT32_C(   408.00), SIMDE_FLOAT32_C(   152.00), SIMDE_FLOAT32_C(   112.00), SIMDE_FLOAT32_C(   312.00),
        SIMDE_FLOAT32_C(   492.00), SIMDE_FLOAT32_C(    54.00), SIMDE_FLOAT32_C(   104.00), SIMDE_FLOAT32_C(   120.00),
        SIMDE_FLOAT32_C(    10.00), SIMDE_FLOAT32_C(    16.00), SIMDE_FLOAT32_C(   382.00), SIMDE_FLOAT32_C(   372.00) } },
    { {  INT32_C(         219),  INT32_C(         105),  INT32_C(         173),  INT32_C(         126),  INT32_C(          44),  INT32_C(         200),  INT32_C(          20),  INT32_C(          35),
         INT32_C(          37),  INT32_C(          14),  INT32_C(          55),  INT32_C(         139),  INT32_C(          56),  INT32_C(           7),  INT32_C(          76),  INT32_C(         105) },
      { SIMDE_FLOAT32_C(   438.00), SIMDE_FLOAT32_C(   210.00), SIMDE_FLOAT32_C(   346.00), SIMDE_FLOAT32_C(   252.00),
        SIMDE_FLOAT32_C(    88.00), SIMDE_FLOAT32_C(   400.00), SIMDE_FLOAT32_C(    40.00), SIMDE_FLOAT32_C(    70.00),
        SIMDE_FLOAT32_C(    74.00), SIMDE_FLOAT32_C(    28.00), SIMDE_FLOAT32_C(   110.00), SIMDE_FLOAT32_C(   278.00),
        SIMDE_FLOAT32_C(   112.00), SIMDE_FLOAT32_C(    14.00), SIMDE_FLOAT32_C(   152.00), SIMDE_FLOAT32_C(   210.00) } },
    { {  INT32_C(         203),  INT32_C(         124),  INT32_C(          59),  INT32_C(         151),  INT32_C(         200),  INT32_C(         115),  INT32_C(          52),  INT32_C(         191),
         INT32_C(         143),  INT32_C(         104),  INT32_C(         251),  INT32_C(         148),  INT32_C(         112),  INT32_C(         186),  INT32_C(          78),  INT32_C(          76) },
      { SIMDE_FLOAT32_C(   406.00), SIMDE_FLOAT32_C(   248.00), SIMDE_FLOAT32_C(   118.00), SIMDE_FLOAT32_C(   302.00),
        SIMDE_FLOAT32_C(   400.00), SIMDE_FLOAT32_C(   230.00), SIMDE_FLOAT32_C(   104.00), SIMDE_FLOAT32_C(   382.00),
        SIMDE_FLOAT32_C(   286.00), SIMDE_FLOAT32_C(   208.00), SIMDE_FLOAT32_C(   502.00), SIMDE_FLOAT32_C(   296.00),
        SIMDE_FLOAT32_C(   224.00), SIMDE_FLOAT32_C(   372.00), SIMDE_FLOAT32_C(   156.00), SIMDE_FLOAT32_C(   152.00) } },
    { {  INT32_C(          36),  INT32_C(         251),  INT32_C(         202),  INT32_C(          80),  INT32_C(         195),  INT32_C(         222),  INT32_C(         115),  INT32_C(         232),
         INT32_C(         236),  INT32_C(         170),  INT32_C(         115),  INT32_C(          37),  INT32_C(         178),  INT32_C(         192),  INT32_C(         142),  INT32_C(         125) },
      { SIMDE_FLOAT32_C(    72.00), SIMDE_FLOAT32_C(   502.00), SIMDE_FLOAT32_C(   404.00), SIMDE_FLOAT32_C(   160.00),
        SIMDE_FLOAT32_C(   390.00), SIMDE_FLOAT32_C(   444.00), SIMDE_FLOAT32_C(   230.00), SIMDE_FLOAT32_C(   464.00),
        SIMDE_FLOAT32_C(   472.00), SIMDE_FLOAT32_C(   340.00), SIMDE_FLOAT32_C(   230.00), SIMDE_FLOAT32_C(    74.00),
        SIMDE_FLOAT32_C(   356.00), SIMDE_FLOAT32_C(   384.00), SIMDE_FLOAT32_C(   284.00), SIMDE_FLOAT32_C(   250.00) } },
    { {  INT32_C(          60),  INT32_C(         201),  INT32_C(          21),  INT32_C(           5),  INT32_C(          61),  INT32_C(          73),  INT32_C(         196),  INT32_C(         204),
         INT32_C(         177),  INT32_C(         191),  INT32_C(          96),  INT32_C(          34),  INT32_C(         121),  INT32_C(         175),  INT32_C(         110),  INT32_C(         157) },
      { SIMDE_FLOAT32_C(   120.00), SIMDE_FLOAT32_C(   402.00), SIMDE_FLOAT32_C(    42.00), SIMDE_FLOAT32_C(    10.00),
        SIMDE_FLOAT32_C(   122.00), SIMDE_FLOAT32_C(   146.00), SIMDE_FLOAT32_C(   392.00), SIMDE_FLOAT32_C(   408.00),
        SIMDE_FLOAT32_C(   354.00), SIMDE_FLOAT32_C(   382.00), SIMDE_FLOAT32_C(   192.00), SIMDE_FLOAT32_C(    68.00),
        SIMDE_FLOAT32_C(   242.00), SIMDE_FLOAT32_C(   350.00), SIMDE_FLOAT32_C(   220.00), SIMDE_FLOAT32_C(   314.00) } },
    { {  INT32_C(         170),  INT32_C(          56),  INT32_C(         237),  INT32_C(         110),  INT32_C(          22),  INT32_C(          97),  INT32_C(          86),  INT32_C(           3),
         INT32_C(          11),  INT32_C(         202),  INT32_C(          40),  INT32_C(         189),  INT32_C(         138),  INT32_C(         182),  INT32_C(          59),  INT32_C(         198) },
      { SIMDE_FLOAT32_C(   340.00), SIMDE_FLOAT32_C(   112.00), SIMDE_FLOAT32_C(   474.00), SIMDE_FLOAT32_C(   220.00),
        SIMDE_FLOAT32_C(    44.00), SIMDE_FLOAT32_C(   194.00), SIMDE_FLOAT32_C(   172.00), SIMDE_FLOAT32_C(     6.00),
        SIMDE_FLOAT32_C(    22.00), SIMDE_FLOAT32_C(   404.00), SIMDE_FLOAT32_C(    80.00), SIMDE_FLOAT32_C(   378.00),
        SIMDE_FLOAT32_C(   276.00), SIMDE_FLOAT32_C(   364.00), SIMDE_FLOAT32_C(   118.00), SIMDE_FLOAT32_C(   396.00) } },
  };
  for (size_t i = 0 ; i < (sizeof(f32gather_buffer) / sizeof(f32gather_buffer[0])) ; i++) { f32gather_buffer[i] = HEDLEY_STATIC_CAST(simde_float32, i); }

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i vindex = simde_mm512_loadu_epi32(test_vec[i].vindex);
    simde__m512 r = simde_mm512_i32gather_ps(vindex, HEDLEY_STATIC_CAST(const void*, f32gather_buffer), 8);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);

  for (size_t i = 0 ; i < (sizeof(f32gather_buffer) / sizeof(f32gather_buffer[0])) ; i++) { f32gather_buffer[i] = HEDLEY_STATIC_CAST(simde_float32, i); }

  for (int i = 0; i < 8; i++) {
    simde__m512i vindex = simde_mm512_set_epi32(
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())),
        HEDLEY_STATIC_CAST(int32_t, (simde_test_codegen_random_u8())));
    simde__m512  r = simde_mm512_i32gather_ps(vindex, f32gather_buffer, 8);

    simde_test_x86_write_i32x16(2, vindex, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_i32gather_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
