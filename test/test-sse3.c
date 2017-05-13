/* Copyright (c) 2017 Evan Nemerson <evan@nemerson.com>
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

#include "test.h"
#include "../sse3.h"

#include <stdio.h>

static MunitResult
test_simde_mm_hadd_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(  732.68f,  -915.27f,  -191.77f,  -862.58f),
      simde_mm_set_ps(   81.80f,   547.56f,   259.82f,    55.94f),
      simde_mm_set_ps(  629.36f,   315.76f,  -182.59f, -1054.35f) },
    { simde_mm_set_ps(  429.35f,  -314.15f,  -691.69f,  -113.96f),
      simde_mm_set_ps( -636.15f,   881.85f,   515.05f,  -694.57f),
      simde_mm_set_ps(  245.70f,  -179.52f,   115.20f,  -805.65f) },
    { simde_mm_set_ps(  163.17f,   585.35f,   889.94f,   989.94f),
      simde_mm_set_ps(  558.88f,  -287.71f,   978.54f,  -729.07f),
      simde_mm_set_ps(  271.17f,   249.47f,   748.52f,  1879.88f) },
    { simde_mm_set_ps(  396.52f,   255.51f,   531.47f,  -510.49f),
      simde_mm_set_ps( -162.17f,   929.03f,  -176.85f,   827.75f),
      simde_mm_set_ps(  766.86f,   650.90f,   652.03f,    20.98f) },
    { simde_mm_set_ps(  348.14f,  -946.97f,  -177.74f,   520.68f),
      simde_mm_set_ps(  339.94f,   653.25f,   168.00f,   216.81f),
      simde_mm_set_ps(  993.19f,   384.81f,  -598.83f,   342.94f) },
    { simde_mm_set_ps( -341.20f,  -395.72f,  -751.71f,   483.71f),
      simde_mm_set_ps(  214.25f,   187.29f,   627.65f,  -993.70f),
      simde_mm_set_ps(  401.54f,  -366.05f,  -736.92f,  -268.00f) },
    { simde_mm_set_ps( -117.08f,  -155.79f,   327.94f,  -604.45f),
      simde_mm_set_ps( -924.11f,    -3.93f,  -496.48f,  -281.24f),
      simde_mm_set_ps( -928.04f,  -777.72f,  -272.87f,  -276.51f) },
    { simde_mm_set_ps( -207.92f,   955.09f,   949.83f,  -476.81f),
      simde_mm_set_ps( -883.98f,   810.86f,   947.09f,  -558.58f),
      simde_mm_set_ps(  -73.12f,   388.51f,   747.17f,   473.02f) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_hadd_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  { (char*) "/sse3/mm_hadd_ps",      test_simde_mm_hadd_ps,      NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

const MunitSuite simde_sse3_test_suite = {
  (char*) "/sse3",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};
