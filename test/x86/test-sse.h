#include "../../simde/x86/sse.h"

#include "test-mmx.h"

#if !defined(SIMDE_TEST_X86_SSE)
#define SIMDE_TEST_X86_SSE

SIMDE_TEST_DEFINE_ASSERT_VEC_CLOSE(m128, f32)

#define simde_assert_m128_close(a, b, precision) \
  simde_assert_m128_f32_close_ex(__LINE__, __FILE__, a, b, precision)

#endif /* !defined(SIMDE_TEST_X86_SSE) */
