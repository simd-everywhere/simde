#include "test-neon.h"
#include "test-neon-internal.h"

#include <stdio.h>

#if defined(SIMDE_BUILD_CPP_TESTS)
#define CHILD_GROUP_LEN 4
#define SET_CHILDREN_FOR_OP(op) \
  children[i++] = *SIMDE_TESTS_GENERATE_SYMBOL_FULL(op, SIMDE_TESTS_CURRENT_ARCH, neon, native, c)  (); \
  children[i++] = *SIMDE_TESTS_GENERATE_SYMBOL_FULL(op, SIMDE_TESTS_CURRENT_ARCH, neon, emul,   c)  (); \
  children[i++] = *SIMDE_TESTS_GENERATE_SYMBOL_FULL(op, SIMDE_TESTS_CURRENT_ARCH, neon, native, cpp)(); \
  children[i++] = *SIMDE_TESTS_GENERATE_SYMBOL_FULL(op, SIMDE_TESTS_CURRENT_ARCH, neon, emul,   cpp)()
#else
#define CHILD_GROUP_LEN 2
#define SET_CHILDREN_FOR_OP(op) \
  children[i++] = *SIMDE_TESTS_GENERATE_SYMBOL_FULL(op, SIMDE_TESTS_CURRENT_ARCH, neon, native, c)  (); \
  children[i++] = *SIMDE_TESTS_GENERATE_SYMBOL_FULL(op, SIMDE_TESTS_CURRENT_ARCH, neon, emul,   c)  ()

#endif

MunitSuite*
simde_tests_arm_neon_get_suite(void) {
  static MunitSuite children[(4 * CHILD_GROUP_LEN) + 1];
  static MunitSuite suite = { "/neon", NULL, children, 1, MUNIT_SUITE_OPTION_NONE };
  static const MunitSuite empty = { NULL, NULL, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  size_t i = 0;
  
  SET_CHILDREN_FOR_OP(add);
  SET_CHILDREN_FOR_OP(dup);
  SET_CHILDREN_FOR_OP(mul);
  SET_CHILDREN_FOR_OP(sub);

  children[i++] = empty;

  munit_assert_size(i, ==, sizeof(children) / sizeof(children[0]));

  return &suite;
}
