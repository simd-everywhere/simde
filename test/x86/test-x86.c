#include "test-x86.h"
#include "test-x86-internal.h"

#include <stdio.h>

#define SET_CHILDREN_FOR_ARCH(isax) \
  children[i++] = *SIMDE_TESTS_GENERATE_SYMBOL_FULL(suite, SIMDE_TESTS_CURRENT_ARCH, isax, native, c)(); \
  children[i++] = *SIMDE_TESTS_GENERATE_SYMBOL_FULL(suite, SIMDE_TESTS_CURRENT_ARCH, isax, emul,   c)(); \
  children[i++] = *SIMDE_TESTS_GENERATE_SYMBOL_FULL(suite, SIMDE_TESTS_CURRENT_ARCH, isax, native, cpp)(); \
  children[i++] = *SIMDE_TESTS_GENERATE_SYMBOL_FULL(suite, SIMDE_TESTS_CURRENT_ARCH, isax, emul,   cpp)()

MunitSuite*
simde_tests_x86_get_suite(void) {
  static MunitSuite children[(10 * 4) + 1];
  static MunitSuite suite = { "/x86", NULL, children, 1, MUNIT_SUITE_OPTION_NONE };
  static const MunitSuite empty = { NULL, NULL, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  size_t i = 0;
  
  SET_CHILDREN_FOR_ARCH(mmx);
  SET_CHILDREN_FOR_ARCH(sse);
  SET_CHILDREN_FOR_ARCH(sse2);
  SET_CHILDREN_FOR_ARCH(sse3);
  SET_CHILDREN_FOR_ARCH(ssse3);
  SET_CHILDREN_FOR_ARCH(sse4_1);
  SET_CHILDREN_FOR_ARCH(sse4_2);
  SET_CHILDREN_FOR_ARCH(avx);
  SET_CHILDREN_FOR_ARCH(fma);
  SET_CHILDREN_FOR_ARCH(avx2);

  children[i++] = empty;

  munit_assert_size(i, ==, sizeof(children) / sizeof(children[0]));

  return &suite;
}
