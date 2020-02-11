#include "../../simde/x86/mmx.h"

#include "test-x86-internal.h"

#if !defined(SIMDE_TEST_X86_MMX)
#define SIMDE_TEST_X86_MMX

SIMDE_TEST_DEFINE_ASSERT_VEC_CLOSE(m64, f32)

#define simde_assert_m64_close(a, b, precision) \
  simde_assert_m64_f32_close_ex(__LINE__, __FILE__, a, b, precision)

#endif /* !defined(SIMDE_TEST_X86_MMX) */
