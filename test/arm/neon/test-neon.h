#include "../../../simde/hedley.h"
HEDLEY_DIAGNOSTIC_PUSH
#if HEDLEY_HAS_WARNING("-Wvla")
#pragma clang diagnostic ignored "-Wvla"
#endif
#if HEDLEY_HAS_WARNING("-Wpadded")
#pragma clang diagnostic ignored "-Wpadded"
#endif
#include "../../munit/munit.h"
HEDLEY_DIAGNOSTIC_POP

#define SIMDE_TESTS_CURRENT_ISAX neon

HEDLEY_BEGIN_C_DECLS

MunitSuite* simde_tests_arm_neon_get_suite(void);

HEDLEY_END_C_DECLS
