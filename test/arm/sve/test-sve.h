#if !defined(SIMDE_TEST_ARM_SVE_TEST_SVE_H)
#define SIMDE_TEST_ARM_SVE_TEST_SVE_H

#include "../../test.h"



#if !defined(SIMDE_TEST_BARE)
  #define SIMDE_TEST_DECLARE_SUITE(name) SIMDE_TEST_SUITE_DECLARE_GETTERS(HEDLEY_CONCAT(simde_test_arm_sve_get_suite_,name))
  #include "declare-suites.h"
  #undef SIMDE_TEST_DECLARE_SUITE
#endif

#endif /* !defined(SIMDE_TEST_ARM_SVE_TEST_SVE_H) */
