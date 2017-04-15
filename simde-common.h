#if !defined(SIMDE_COMMON_H)
#define SIMDE_COMMON_H

#include "hedley.h"

#define SIMDE__CONCAT(a,b) a##b
#define SIMDE__XCONCAT(a,b) SIMDE__CONCAT(a,b)

#if defined(__GNUC__)
#  define SIMDE__ALIGN(alignment) __attribute__((aligned(alignment)))
#elif defined(_MSC_VER)
#  define SIMDE__ALIGN(alignment) __declspec(align(alignment))
#else
#  define SIMDE__ALIGN(alignment)
#endif

#if defined(__GNUC__)
#  define SIMDE__FUNCTION_ATTRIBUTES __attribute__((__always_inline__,__gnu_inline__)) static HEDLEY_INLINE
#else
#  define SIMDE__FUNCTION_ATTRIBUTES static HEDLEY_INLINE
#endif

#if !defined(SIMDE_PREFIX)
#  define SIMDE_PREFIX
#endif

#if !defined(SIMDE__TYPE)
#  define SIMDE__TYPE(name) SIMDE__XCONCAT(SIMDE_PREFIX, name)
#endif

#if !defined(SIMDE__SYMBOL)
#  define SIMDE__SYMBOL(name) SIMDE__XCONCAT(SIMDE_PREFIX, name)
#endif

#endif /* SIMDE_COMMON_H */
