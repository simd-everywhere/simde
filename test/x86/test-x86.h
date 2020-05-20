#include "../../simde/hedley.h"
HEDLEY_DIAGNOSTIC_PUSH
#if HEDLEY_HAS_WARNING("-Wvla")
#pragma clang diagnostic ignored "-Wvla"
#endif
#if HEDLEY_HAS_WARNING("-Wpadded")
#pragma clang diagnostic ignored "-Wpadded"
#endif
#include "../munit/munit.h"
HEDLEY_DIAGNOSTIC_POP

HEDLEY_BEGIN_C_DECLS

MunitSuite* simde_tests_x86_get_suite(void);

HEDLEY_END_C_DECLS
