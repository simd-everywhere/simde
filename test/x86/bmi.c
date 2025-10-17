/* Copyright (c) 2025 Thomas Magnusson <herr.thomas.magnusson@gmail.com>
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

#define SIMDE_TESTS_CURRENT_ISAX bmi
#include <test/test.h>
#include <simde/x86/bmi.h>

SIMDE_DIAGNOSTIC_DISABLE_DISABLED_MACRO_EXPANSION_

static int
test_simde_pext_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a;
    const uint64_t mask;
    const uint64_t r;
  } test_vec[] = {
    { UINT64_C(13508802676154064692),                                                                                                      UINT64_C(11916219417575033503),
      UINT64_C(         14930477268) },
    { UINT64_C( 8991466077046260319),
      UINT64_C(14641148062227237465),
      UINT64_C(          3289795231) },
    { UINT64_C(13357491886950986029),
      UINT64_C(15308863738357189474),
      UINT64_C(          1435180554) },
    { UINT64_C( 4144360453951243588),
      UINT64_C( 8297196516043487171),
      UINT64_C(           444086868) },
    { UINT64_C(13876845397803402690),
      UINT64_C( 9099808071694104576),
      UINT64_C(           134403376) },
    { UINT64_C(13177823827260160712),
      UINT64_C(10752403294007607935),
      UINT64_C(           973594824) },
    { UINT64_C(14147783096320151098),
      UINT64_C(12895358146796250685),
      UINT64_C(        143671947644) },
    { UINT64_C(  172892167702477501),
      UINT64_C(16566209390605465214),
      UINT64_C(         65440733022) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_pext_u64(test_vec[i].a, test_vec[i].mask);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t mask = simde_test_codegen_random_u64();
    uint64_t r = simde_pext_u64(a, mask);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, mask, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_pext_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a;
    const uint32_t mask;
    const uint32_t r;
  } test_vec[] = {
    { UINT32_C(1111109271),
      UINT32_C( 675947618),
      UINT32_C(       121) },
    { UINT32_C( 664139222),
      UINT32_C(2575968697),
      UINT32_C(      3252) },
    { UINT32_C(2877007551),
      UINT32_C( 675555399),
      UINT32_C(       935) },
    { UINT32_C(2159581581),
      UINT32_C(3131094819),
      UINT32_C(     34633) },
    { UINT32_C(1224596197),
      UINT32_C(3564128254),
      UINT32_C(     81266) },
    { UINT32_C(4143646269),
      UINT32_C(4002383151),
      UINT32_C(    490333) },
    { UINT32_C(1939474988),
      UINT32_C(3214663218),
      UINT32_C(    850988) },
    { UINT32_C(2604618615),
      UINT32_C(4032159498),
      UINT32_C(     77517) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_pext_u32(test_vec[i].a, test_vec[i].mask);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();
    uint32_t mask = simde_test_codegen_random_u32();
    uint32_t r = simde_pext_u32(a, mask);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, mask, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_pdep_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a;
    const uint64_t mask;
    const uint64_t r;
  } test_vec[] = {
    { UINT64_C(14136722556426182504),
      UINT64_C( 3856714733867923395),
      UINT64_C( 3856488691884516992) },
    { UINT64_C( 2651191373339471723),
      UINT64_C( 1628280712112929606),
      UINT64_C( 1592234167215347974) },
    { UINT64_C( 2213305207005028783),
      UINT64_C( 2776333631088422325),
      UINT64_C(  470345373591284021) },
    { UINT64_C( 3735974406343426355),
      UINT64_C( 8437226467174446419),
      UINT64_C( 7205764368775005443) },
    { UINT64_C( 1668336692889134509),
      UINT64_C(15991702468143162893),
      UINT64_C( 4631055016355439113) },
    { UINT64_C( 2743372581226806257),
      UINT64_C( 4654820487256835679),
      UINT64_C( 4652508764059305553) },
    { UINT64_C( 3376978585943867747),
      UINT64_C( 2890716362294249110),
      UINT64_C(    2604760226350086) },
    { UINT64_C( 8707456002679091166),
      UINT64_C(11489023756557155999),
      UINT64_C( 1824241523379961374) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_pdep_u64(test_vec[i].a, test_vec[i].mask);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t mask = simde_test_codegen_random_u64();
    uint64_t r = simde_pdep_u64(a, mask);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, mask, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_pdep_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a;
    const uint32_t mask;
    const uint32_t r;
  } test_vec[] = {
    { UINT32_C(1482996279),
      UINT32_C(3246801195),
      UINT32_C(2164277515) },
    { UINT32_C(3204611208),
      UINT32_C(1038557023),
      UINT32_C(  19337736) },
    { UINT32_C(3891195598),
      UINT32_C(2791294215),
      UINT32_C( 639467782) },
    { UINT32_C(4292410563),
      UINT32_C(1771981106),
      UINT32_C(1770389522) },
    { UINT32_C( 801243652),
      UINT32_C(3438299204),
      UINT32_C( 134219776) },
    { UINT32_C( 596374212),
      UINT32_C(3764417042),
      UINT32_C(1080033792) },
    { UINT32_C(1757957729),
      UINT32_C(3591317267),
      UINT32_C(1108091905) },
    { UINT32_C(1440081699),
      UINT32_C( 884962096),
      UINT32_C( 881729584) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_pdep_u32(test_vec[i].a, test_vec[i].mask);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();
    uint32_t mask = simde_test_codegen_random_u32();
    uint32_t r = simde_pdep_u32(a, mask);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, mask, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_bextr_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint64_t a;
    const uint32_t start;
    const uint32_t len;
    const uint64_t r;
  } test_vec[] = {
    { UINT64_C(13496859581136023557),
      UINT32_C(        27),
      UINT32_C(        60),
      UINT64_C(        100559440114) },
    { UINT64_C( 3295939537066738438),
      UINT32_C(        31),
      UINT32_C(         3),
      UINT64_C(                   7) },
    { UINT64_C( 7096665068755864698),
      UINT32_C(        63),
      UINT32_C(         1),
      UINT64_C(                   0) },
    { UINT64_C( 8557580189262171914),
      UINT32_C(        16),
      UINT32_C(        60),
      UINT64_C(     130578310993380) },
    { UINT64_C(16407727128880642057),
      UINT32_C(        23),
      UINT32_C(         4),
      UINT64_C(                   0) },
    { UINT64_C(13061677406725915895),
      UINT32_C(        25),
      UINT32_C(        34),
      UINT64_C(         11311198951) },
    { UINT64_C( 1091260034605401180),
      UINT32_C(        45),
      UINT32_C(        43),
      UINT64_C(               31015) },
    { UINT64_C( 2569363282946286733),
      UINT32_C(        27),
      UINT32_C(        20),
      UINT64_C(              444766) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_bextr_u64(test_vec[i].a, test_vec[i].start, test_vec[i].len);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint32_t start = simde_test_codegen_random_u32() % 64;
    uint32_t len = simde_test_codegen_random_u32() % 64;
    uint64_t r = simde_bextr_u64(a, start, len);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, start, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, len, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_bextr_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint32_t a;
    const uint32_t start;
    const uint32_t len;
    const uint32_t r;
  } test_vec[] = {
    { UINT32_C( 997542281),
      UINT32_C(         1),
      UINT32_C(        16),
      UINT32_C(     42180) },
    { UINT32_C( 947374697),
      UINT32_C(        14),
      UINT32_C(         8),
      UINT32_C(       223) },
    { UINT32_C(1051594646),
      UINT32_C(        11),
      UINT32_C(        27),
      UINT32_C(    513473) },
    { UINT32_C(1742405783),
      UINT32_C(         1),
      UINT32_C(        29),
      UINT32_C( 334331979) },
    { UINT32_C(3404032929),
      UINT32_C(        16),
      UINT32_C(         5),
      UINT32_C(         5) },
    { UINT32_C( 654630444),
      UINT32_C(        13),
      UINT32_C(        19),
      UINT32_C(     79910) },
    { UINT32_C( 784320401),
      UINT32_C(        25),
      UINT32_C(        14),
      UINT32_C(        23) },
    { UINT32_C( 971321684),
      UINT32_C(        12),
      UINT32_C(         9),
      UINT32_C(        83) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_bextr_u32(test_vec[i].a, test_vec[i].start, test_vec[i].len);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();
    uint32_t start = simde_test_codegen_random_u32() % 32;
    uint32_t len = simde_test_codegen_random_u32() % 32;
    uint32_t r = simde_bextr_u32(a, start, len);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, start, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, len, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(pext_u64)
  SIMDE_TEST_FUNC_LIST_ENTRY(pext_u32)
  SIMDE_TEST_FUNC_LIST_ENTRY(pdep_u64)
  SIMDE_TEST_FUNC_LIST_ENTRY(pdep_u32)
  SIMDE_TEST_FUNC_LIST_ENTRY(bextr_u64)
  SIMDE_TEST_FUNC_LIST_ENTRY(bextr_u32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
