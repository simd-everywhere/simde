#if !defined(SIMDE_TEST_ARM_SVE_TEST_SVE_H)
#define SIMDE_TEST_ARM_SVE_TEST_SVE_H

#include "../../test.h"

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION

static int32_t
simde_test_arm_sve_random_length(size_t buf_size, size_t elem_size) {
  return
    (simde_test_codegen_random_i32() & HEDLEY_STATIC_CAST(int32_t, (buf_size / elem_size) - 1)) |
    HEDLEY_STATIC_CAST(int32_t, (buf_size / 2) / elem_size);
}

HEDLEY_DIAGNOSTIC_POP

#if !defined(SIMDE_TEST_BARE)
  #define SIMDE_TEST_DECLARE_SUITE(name) SIMDE_TEST_SUITE_DECLARE_GETTERS(HEDLEY_CONCAT(simde_test_arm_sve_get_suite_,name))
  #include <test/arm/sve/declare-suites.h>
  #undef SIMDE_TEST_DECLARE_SUITE
#endif

#endif /* !defined(SIMDE_TEST_ARM_SVE_TEST_SVE_H) */
