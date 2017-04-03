#if !defined(SIMDE_COMMON_H)
#define SIMDE_COMMON_H

#include "hedley.h"

#if defined(__GNUC__)
#  define SIMDE__ALIGN(alignment) __attribute__((aligned(alignment)))
#elif defined(_MSC_VER)
#  define SIMDE__ALIGN(alignment) __declspec(align(alignment))
#endif

#if defined(__GNUC__)
#  define SIMDE__FUNCTION_ATTRIBUTES __attribute__((__always_inline__,__gnu_inline__)) static HEDLEY_INLINE
#else
#  define SIMDE__FUNCTION_ATTRIBUTES static HEDLEY_INLINE
#endif

#endif /* SIMDE_COMMON_H */
