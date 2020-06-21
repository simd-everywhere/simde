#if !defined(SIMDE_TESTS_H)
#define SIMDE_TESTS_H

#define SIMDE_NO_CHECK_IMMEDIATE_CONSTANT

#include "../simde/simde-common.h"

#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include <stdarg.h>

typedef enum SimdeTestVecPos {
  SIMDE_TEST_VEC_POS_FIRST  =  1,
  SIMDE_TEST_VEC_POS_MIDDLE =  0,
  SIMDE_TEST_VEC_POS_LAST   = -1
} SimdeTestVecPos;

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_VLA_
SIMDE_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION_
SIMDE_DIAGNOSTIC_DISABLE_PADDED_
SIMDE_DIAGNOSTIC_DISABLE_ZERO_AS_NULL_POINTER_CONSTANT_
SIMDE_DIAGNOSTIC_DISABLE_CAST_FUNCTION_TYPE_
SIMDE_DIAGNOSTIC_DISABLE_NON_CONSTANT_AGGREGATE_INITIALIZER_
SIMDE_DIAGNOSTIC_DISABLE_C99_EXTENSIONS_
SIMDE_DIAGNOSTIC_DISABLE_NO_EMMS_INSTRUCTION_
SIMDE_DIAGNOSTIC_DISABLE_CPP98_COMPAT_PEDANTIC_
SIMDE_DIAGNOSTIC_DISABLE_ANNEX_K_
SIMDE_DIAGNOSTIC_DISABLE_DISABLED_MACRO_EXPANSION_

#if \
    HEDLEY_HAS_BUILTIN(__builtin_abort) || \
    HEDLEY_GCC_VERSION_CHECK(3,4,6) || \
    HEDLEY_ARM_VERSION_CHECK(4,1,0)
  #define simde_abort() __builtin_abort()
#elif defined(SIMDE_HAVE_STDLIB_H)
  #define simde_abort() abort()
#endif

#define SIMDE_TEST_ASSERT_CONTINUE 0
#define SIMDE_TEST_ASSERT_TRAP 1
#define SIMDE_TEST_ASSERT_ABORT 2
#if !defined(SIMDE_TEST_ASSERT_FAILURE)
  #if defined(SIMDE_TEST_BARE)
    #define SIMDE_TEST_ASSERT_FAILURE SIMDE_TEST_ASSERT_CONTINUE
  #else
    #define SIMDE_TEST_ASSERT_FAILURE SIMDE_TEST_ASSERT_ABORT
  #endif
#endif

#if !defined(SIMDE_TEST_ASSERT_ABORT) && !defined(SIMDE_TEST_ASSERT_CONTINUE) && !defined(SIMDE_TEST_ASSERT_TRAP)
  #if defined(SIMDE_TEST_BARE)
    #define SIMDE_TEST_ASSERT_CONTINUE
  #else
    #define SIMDE_TEST_ASSERT_ABORT
  #endif
#endif

#if SIMDE_TEST_ASSERT_FAILURE == SIMDE_TEST_ASSERT_ABORT
  #define SIMDE_TEST_ASSERT_RETURN(value) ((void) 0)
#else
  #define SIMDE_TEST_ASSERT_RETURN(value) return value
#endif

#if defined(SIMDE_TEST_BARE)
  #define SIMDE_CODEGEN_FP stderr
#else
  #define SIMDE_CODEGEN_FP stdout
#endif

#if SIMDE_TEST_ASSERT_FAILURE == 2
  HEDLEY_NO_RETURN
#endif
HEDLEY_PRINTF_FORMAT(1, 2)
static void
simde_test_debug_printf_(const char* format, ...) {
  va_list ap;

  va_start(ap, format);
  vfprintf(stderr, format, ap);
  va_end(ap);
  fflush(stderr);

  /* Debug trap is great for local development where you can attach a
   * debugger, but processes exiting with a SIGTRAP seem to be rather
   * confusing for CI. */
  #if SIMDE_TEST_ASSERT_FAILURE == 1
    simde_trap();
  #elif SIMDE_TEST_ASSERT_FAILURE == 2
    simde_abort();
  #endif
}

HEDLEY_PRINTF_FORMAT(3, 4)
static void
simde_test_codegen_snprintf_(char* str, size_t size, const char* format, ...) {
  va_list ap;
  int w;

  va_start(ap, format);
  w = vsnprintf(str, size, format, ap);
  va_end(ap);

  if (w > HEDLEY_STATIC_CAST(int, size)) {
    simde_test_debug_printf_("Not enough space to write value (given %zu bytes, need %d bytes)\n", size, w + 1);
  }
}

static void
simde_test_codegen_f32(size_t buf_len, char buf[HEDLEY_ARRAY_PARAM(buf_len)], simde_float32 value) {
  if (simde_math_isnan(value)) {
    simde_test_codegen_snprintf_(buf, buf_len, "           SIMDE_MATH_NANF");
  } else if (simde_math_isinf(value)) {
    simde_test_codegen_snprintf_(buf, buf_len, "%5cSIMDE_MATH_INFINITYF", value < 0 ? '-' : ' ');
  } else {
    simde_test_codegen_snprintf_(buf, buf_len, "SIMDE_FLOAT32_C(%9.2f)", HEDLEY_STATIC_CAST(double, value));
  }
}

static void
simde_test_codegen_f64(size_t buf_len, char buf[HEDLEY_ARRAY_PARAM(buf_len)], simde_float64 value) {
  if (simde_math_isnan(value)) {
    simde_test_codegen_snprintf_(buf, buf_len, "            SIMDE_MATH_NAN");
  } else if (simde_math_isinf(value)) {
    simde_test_codegen_snprintf_(buf, buf_len, "%7cSIMDE_MATH_INFINITY", value < 0 ? '-' : ' ');
  } else {
    simde_test_codegen_snprintf_(buf, buf_len, "SIMDE_FLOAT64_C(%9.2f)", HEDLEY_STATIC_CAST(double, value));
  }
}

static void
simde_test_codegen_i8(size_t buf_len, char buf[HEDLEY_ARRAY_PARAM(buf_len)], int8_t value) {
  if (value == INT8_MIN) {
    simde_test_codegen_snprintf_(buf, buf_len, "     INT8_MIN");
  } else if (value == INT8_MAX) {
    simde_test_codegen_snprintf_(buf, buf_len, "     INT8_MAX");
  } else {
    simde_test_codegen_snprintf_(buf, buf_len, "%cINT8_C(%4" PRId8 ")", (value < 0) ? '-' : ' ', HEDLEY_STATIC_CAST(int8_t, (value < 0) ? -value : value));
  }
}

static void
simde_test_codegen_i16(size_t buf_len, char buf[HEDLEY_ARRAY_PARAM(buf_len)], int16_t value) {
  if (value == INT16_MIN) {
    simde_test_codegen_snprintf_(buf, buf_len, "%15s", "INT16_MIN");
  } else if (value == INT16_MAX) {
    simde_test_codegen_snprintf_(buf, buf_len, "%15s", "INT16_MAX");
  } else {
    simde_test_codegen_snprintf_(buf, buf_len, "%cINT16_C(%6" PRId16 ")", (value < 0) ? '-' : ' ', HEDLEY_STATIC_CAST(int16_t, (value < 0) ? -value : value));
  }
}

static void
simde_test_codegen_i32(size_t buf_len, char buf[HEDLEY_ARRAY_PARAM(buf_len)], int32_t value) {
  if (value == INT32_MIN) {
    simde_test_codegen_snprintf_(buf, buf_len, "%20s", "INT32_MIN");
  } else if (value == INT32_MAX) {
    simde_test_codegen_snprintf_(buf, buf_len, "%20s", "INT32_MAX");
  } else {
    simde_test_codegen_snprintf_(buf, buf_len, "%cINT32_C(%12" PRId32 ")", (value < 0) ? '-' : ' ', HEDLEY_STATIC_CAST(int32_t, (value < 0) ? -value : value));
  }
}

static void
simde_test_codegen_i64(size_t buf_len, char buf[HEDLEY_ARRAY_PARAM(buf_len)], int64_t value) {
  if (value == INT64_MIN) {
    simde_test_codegen_snprintf_(buf, buf_len, "%29s", "INT64_MIN");
  } else if (value == INT64_MAX) {
    simde_test_codegen_snprintf_(buf, buf_len, "%29s", "INT64_MAX");
  } else {
    simde_test_codegen_snprintf_(buf, buf_len, "%cINT64_C(%20" PRId64 ")", (value < 0) ? '-' : ' ', HEDLEY_STATIC_CAST(int64_t, (value < 0) ? -value : value));
  }
}

static void
simde_test_codegen_u8(size_t buf_len, char buf[HEDLEY_ARRAY_PARAM(buf_len)], uint8_t value) {
  if (value == UINT8_MAX) {
    simde_test_codegen_snprintf_(buf, buf_len, "   UINT8_MAX");
  } else {
    simde_test_codegen_snprintf_(buf, buf_len, "UINT8_C(%3" PRIu8 ")", value);
  }
}

static void
simde_test_codegen_u16(size_t buf_len, char buf[HEDLEY_ARRAY_PARAM(buf_len)], uint16_t value) {
  if (value == UINT16_MAX) {
    simde_test_codegen_snprintf_(buf, buf_len, "%15s", "UINT16_MAX");
  } else {
    simde_test_codegen_snprintf_(buf, buf_len, "UINT16_C(%5" PRIu16 ")", value);
  }
}

static void
simde_test_codegen_u32(size_t buf_len, char buf[HEDLEY_ARRAY_PARAM(buf_len)], uint32_t value) {
  if (value == UINT32_MAX) {
    simde_test_codegen_snprintf_(buf, buf_len, "%20s", "UINT32_MAX");
  } else {
    simde_test_codegen_snprintf_(buf, buf_len, "UINT32_C(%10" PRIu32 ")", value);
  }
}

static void
simde_test_codegen_u64(size_t buf_len, char buf[HEDLEY_ARRAY_PARAM(buf_len)], uint64_t value) {
  if (value == UINT64_MAX) {
    simde_test_codegen_snprintf_(buf, buf_len, "%29s", "UINT64_MAX");
  } else {
    simde_test_codegen_snprintf_(buf, buf_len, "UINT64_C(%20" PRIu64 ")", value);
  }
}

static void
simde_test_codegen_write_indent(int indent) {
  for (int i = 0 ; i < indent ; i++) {
    fputs("  ", stdout);
  }
}

static int simde_test_codegen_rand(void) {
  /* Single-threaded programs are so nice */
  static int is_init = 0;
  if (HEDLEY_UNLIKELY(!is_init)) {
    FILE* fp = fopen("/dev/urandom", "r");
    if (fp == NULL)
      fp = fopen("/dev/random", "r");

    if (fp != NULL) {
      unsigned int seed;
      size_t nread = fread(&seed, sizeof(seed), 1, fp);
      fclose(fp);
      if (nread == 1) {
        srand(seed);
        is_init = 1;
      }
    }

    if (!is_init) {
      srand(HEDLEY_STATIC_CAST(unsigned int, time(NULL)));
      is_init = 1;
    }
  }

  return rand();
}

static void
simde_test_codegen_random_memory(size_t buf_len, uint8_t buf[HEDLEY_ARRAY_PARAM(buf_len)]) {
  for (size_t i = 0 ; i < buf_len ; i++) {
    buf[i] = HEDLEY_STATIC_CAST(uint8_t, simde_test_codegen_rand() & 0xff);
  }
}

static simde_float32
simde_test_codegen_random_f32(simde_float32 min, simde_float32 max) {
  simde_float32 v = (HEDLEY_STATIC_CAST(simde_float32, simde_test_codegen_rand()) / (HEDLEY_STATIC_CAST(simde_float32, RAND_MAX) / (max - min))) + min;
  return simde_math_roundf(v * SIMDE_FLOAT32_C(100.0)) / SIMDE_FLOAT32_C(100.0);
}

static simde_float64
simde_test_codegen_random_f64(simde_float64 min, simde_float64 max) {
  simde_float64 v = (HEDLEY_STATIC_CAST(simde_float64, simde_test_codegen_rand()) / (HEDLEY_STATIC_CAST(simde_float64, RAND_MAX) / (max - min))) + min;
  return simde_math_round(v * SIMDE_FLOAT64_C(100.0)) / SIMDE_FLOAT64_C(100.0);
}

static void
simde_test_codegen_random_vf32(size_t elem_count, simde_float32 values[HEDLEY_ARRAY_PARAM(elem_count)], simde_float32 min, simde_float32 max) {
  for (size_t i = 0 ; i < elem_count ; i++) {
    values[i] = simde_test_codegen_random_f32(min, max);
  }
}

static void
simde_test_codegen_random_vf64(size_t elem_count, simde_float64 values[HEDLEY_ARRAY_PARAM(elem_count)], simde_float64 min, simde_float64 max) {
  for (size_t i = 0 ; i < elem_count ; i++) {
    values[i] = simde_test_codegen_random_f64(min, max);
  }
}

#define SIMDE_TEST_CODEGEN_GENERATE_RANDOM_INT_FUNC_(T, symbol_identifier) \
  static T simde_test_codegen_random_##symbol_identifier(void) { \
    T r; \
    simde_test_codegen_random_memory(sizeof(r), HEDLEY_REINTERPRET_CAST(uint8_t*, &r)); \
    return r; \
  }

SIMDE_TEST_CODEGEN_GENERATE_RANDOM_INT_FUNC_(int8_t,    i8)
SIMDE_TEST_CODEGEN_GENERATE_RANDOM_INT_FUNC_(int16_t,  i16)
SIMDE_TEST_CODEGEN_GENERATE_RANDOM_INT_FUNC_(int32_t,  i32)
SIMDE_TEST_CODEGEN_GENERATE_RANDOM_INT_FUNC_(int64_t,  i64)
SIMDE_TEST_CODEGEN_GENERATE_RANDOM_INT_FUNC_(uint8_t,   u8)
SIMDE_TEST_CODEGEN_GENERATE_RANDOM_INT_FUNC_(uint16_t, u16)
SIMDE_TEST_CODEGEN_GENERATE_RANDOM_INT_FUNC_(uint32_t, u32)
SIMDE_TEST_CODEGEN_GENERATE_RANDOM_INT_FUNC_(uint64_t, u64)

#define SIMDE_TEST_CODEGEN_GENERATE_WRITE_VECTOR_FUNC_(T, symbol_identifier, elements_per_line) \
  static void \
  simde_test_codegen_write_v##symbol_identifier(int indent, size_t elem_count, T values[HEDLEY_ARRAY_PARAM(elem_count)], SimdeTestVecPos pos) { \
    switch (pos) { \
      case SIMDE_TEST_VEC_POS_FIRST: \
        simde_test_codegen_write_indent(indent); \
        indent++; \
        fputs("{ ", stdout); \
        break; \
      case SIMDE_TEST_VEC_POS_MIDDLE: \
      case SIMDE_TEST_VEC_POS_LAST: \
        indent++; \
        simde_test_codegen_write_indent(indent); \
        break; \
    } \
 \
    fputs("{ ", stdout); \
    for (size_t i = 0 ; i < elem_count ; i++) { \
      if (i != 0) { \
        fputc(',', stdout); \
        if ((i % elements_per_line) == 0) { \
          fputc('\n', stdout); \
          simde_test_codegen_write_indent(indent + 1); \
        } else { \
          fputc(' ', stdout); \
        } \
      } \
 \
      char buf[53]; \
      simde_test_codegen_##symbol_identifier(sizeof(buf), buf, values[i]); \
      fputs(buf, stdout); \
    } \
    fputs(" }", stdout); \
 \
    switch (pos) { \
      case SIMDE_TEST_VEC_POS_FIRST: \
      case SIMDE_TEST_VEC_POS_MIDDLE: \
        fputc(',', stdout); \
        break; \
      case SIMDE_TEST_VEC_POS_LAST: \
        fputs(" },", stdout); \
        break; \
    } \
 \
    fputc('\n', stdout); \
  }

SIMDE_TEST_CODEGEN_GENERATE_WRITE_VECTOR_FUNC_(simde_float32, f32, 4)
SIMDE_TEST_CODEGEN_GENERATE_WRITE_VECTOR_FUNC_(simde_float64, f64, 4)
SIMDE_TEST_CODEGEN_GENERATE_WRITE_VECTOR_FUNC_(int8_t, i8, 8)
SIMDE_TEST_CODEGEN_GENERATE_WRITE_VECTOR_FUNC_(int16_t, i16, 8)
SIMDE_TEST_CODEGEN_GENERATE_WRITE_VECTOR_FUNC_(int32_t, i32, 8)
SIMDE_TEST_CODEGEN_GENERATE_WRITE_VECTOR_FUNC_(int64_t, i64, 4)
SIMDE_TEST_CODEGEN_GENERATE_WRITE_VECTOR_FUNC_(uint8_t, u8, 8)
SIMDE_TEST_CODEGEN_GENERATE_WRITE_VECTOR_FUNC_(uint16_t, u16, 8)
SIMDE_TEST_CODEGEN_GENERATE_WRITE_VECTOR_FUNC_(uint32_t, u32, 8)
SIMDE_TEST_CODEGEN_GENERATE_WRITE_VECTOR_FUNC_(uint64_t, u64, 4)

#define SIMDE_TEST_CODEGEN_WRITE_SCALAR_FUNC_(T, symbol_identifier) \
  static void \
  simde_test_codegen_write_##symbol_identifier(int indent, T value, SimdeTestVecPos pos) { \
    switch (pos) { \
      case SIMDE_TEST_VEC_POS_FIRST: \
        simde_test_codegen_write_indent(indent); \
        indent++; \
        fputs("{ ", stdout); \
        break; \
      case SIMDE_TEST_VEC_POS_MIDDLE: \
      case SIMDE_TEST_VEC_POS_LAST: \
        indent++; \
        simde_test_codegen_write_indent(indent); \
        break; \
    } \
 \
    { \
      char buf[53]; \
      simde_test_codegen_##symbol_identifier(sizeof(buf), buf, value); \
      fputs(buf, stdout); \
    } \
 \
    switch (pos) { \
      case SIMDE_TEST_VEC_POS_FIRST: \
      case SIMDE_TEST_VEC_POS_MIDDLE: \
        fputc(',', stdout); \
        break; \
      case SIMDE_TEST_VEC_POS_LAST: \
        fputs(" },", stdout); \
        break; \
    } \
 \
    fputc('\n', stdout); \
  }

SIMDE_TEST_CODEGEN_WRITE_SCALAR_FUNC_(int8_t,    i8)
SIMDE_TEST_CODEGEN_WRITE_SCALAR_FUNC_(int16_t,  i16)
SIMDE_TEST_CODEGEN_WRITE_SCALAR_FUNC_(int32_t,  i32)
SIMDE_TEST_CODEGEN_WRITE_SCALAR_FUNC_(int64_t,  i64)
SIMDE_TEST_CODEGEN_WRITE_SCALAR_FUNC_(uint8_t,   u8)
SIMDE_TEST_CODEGEN_WRITE_SCALAR_FUNC_(uint16_t, u16)
SIMDE_TEST_CODEGEN_WRITE_SCALAR_FUNC_(uint32_t, u32)
SIMDE_TEST_CODEGEN_WRITE_SCALAR_FUNC_(uint64_t, u64)
SIMDE_TEST_CODEGEN_WRITE_SCALAR_FUNC_(simde_float32, f32)
SIMDE_TEST_CODEGEN_WRITE_SCALAR_FUNC_(simde_float64, f64)

static int
simde_test_equal_f32(simde_float32 a, simde_float32 b, simde_float32 slop) {
  if (simde_math_isnan(a)) {
    return simde_math_isnan(b);
  } else if (simde_math_isinf(a)) {
    return !((a < b) || (a > b));
  } else {
    return ((b > (a - slop)) && (b < (a + slop)));
  }
}

static int
simde_test_equal_f64(simde_float64 a, simde_float64 b, simde_float64 slop) {
  if (simde_math_isnan(a)) {
    return simde_math_isnan(b);
  } else if (simde_math_isinf(a)) {
    return !((a < b) || (a > b));
  } else {
    return ((b > (a - slop)) && (b < (a + slop)));
  }
}

static int
simde_assert_equal_vf32_(
    size_t vec_len, simde_float32 const a[HEDLEY_ARRAY_PARAM(vec_len)], simde_float32 const b[HEDLEY_ARRAY_PARAM(vec_len)], simde_float32 slop,
    const char* filename, int line, const char* astr, const char* bstr) {
  for (size_t i = 0 ; i < vec_len ; i++) {
    if (HEDLEY_UNLIKELY(!simde_test_equal_f32(a[i], b[i], slop))) {
      simde_test_debug_printf_("%s:%d: assertion failed: %s[%zu] ~= %s[%zu] (%f ~= %f)\n",
              filename, line, astr, i, bstr, i, HEDLEY_STATIC_CAST(double, a[i]), HEDLEY_STATIC_CAST(double, b[i]));
      SIMDE_TEST_ASSERT_RETURN(1);
    }
  }
  return 0;
}
#define simde_assert_equal_vf32(vec_len, a, b, precision) simde_assert_equal_vf32_(vec_len, a, b, 1e-##precision##f, __FILE__, __LINE__, #a, #b)

static int
simde_assert_equal_f32_(simde_float32 a, simde_float32 b, simde_float32 slop,
    const char* filename, int line, const char* astr, const char* bstr) {
  if (HEDLEY_UNLIKELY(!simde_test_equal_f32(a, b, slop))) {
    simde_test_debug_printf_("%s:%d: assertion failed: %s ~= %s (%f ~= %f)\n",
        filename, line, astr, bstr, HEDLEY_STATIC_CAST(double, a), HEDLEY_STATIC_CAST(double, b));
    SIMDE_TEST_ASSERT_RETURN(1);
  }
  return 0;
}
#define simde_assert_equal_f32(a, b, precision) simde_assert_equal_f32_(a, b, 1e-##precision##f, __FILE__, __LINE__, #a, #b)

static int
simde_assert_equal_vf64_(
    size_t vec_len, simde_float64 const a[HEDLEY_ARRAY_PARAM(vec_len)], simde_float64 const b[HEDLEY_ARRAY_PARAM(vec_len)], simde_float64 slop,
    const char* filename, int line, const char* astr, const char* bstr) {
  for (size_t i = 0 ; i < vec_len ; i++) {
    if (HEDLEY_UNLIKELY(!simde_test_equal_f64(a[i], b[i], slop))) {
      simde_test_debug_printf_("%s:%d: assertion failed: %s[%zu] ~= %s[%zu] (%f ~= %f)\n",
              filename, line, astr, i, bstr, i, HEDLEY_STATIC_CAST(double, a[i]), HEDLEY_STATIC_CAST(double, b[i]));
      SIMDE_TEST_ASSERT_RETURN(1);
    }
  }
  return 0;
}
#define simde_assert_equal_vf64(vec_len, a, b, precision) simde_assert_equal_vf64_(vec_len, a, b, 1e-##precision, __FILE__, __LINE__, #a, #b)

static int
simde_assert_equal_f64_(simde_float64 a, simde_float64 b, simde_float64 slop,
    const char* filename, int line, const char* astr, const char* bstr) {
  if (HEDLEY_UNLIKELY(!simde_test_equal_f64(a, b, slop))) {
    simde_test_debug_printf_("%s:%d: assertion failed: %s ~= %s (%f ~= %f)\n",
        filename, line, astr, bstr, a, b);
    SIMDE_TEST_ASSERT_RETURN(1);
  }
  return 0;
}
#define simde_assert_equal_f64(a, b, precision) simde_assert_equal_f64_(a, b, 1e-##precision, __FILE__, __LINE__, #a, #b)

#define SIMDE_TEST_GENERATE_ASSERT_EQUAL_FUNC_(T, symbol_identifier, fmt) \
  static int \
  simde_assert_equal_v##symbol_identifier##_( \
      size_t vec_len, const T a[HEDLEY_ARRAY_PARAM(vec_len)], const T b[HEDLEY_ARRAY_PARAM(vec_len)], \
      const char* filename, int line, const char* astr, const char* bstr) { \
    for (size_t i = 0 ; i < vec_len ; i++) { \
      if (HEDLEY_UNLIKELY(a[i] != b[i])) { \
        simde_test_debug_printf_("%s:%d: assertion failed: %s[%zu] == %s[%zu] (%" fmt " == %" fmt ")\n", \
              filename, line, astr, i, bstr, i, a[i], b[i]); \
        SIMDE_TEST_ASSERT_RETURN(1); \
      } \
    } \
    return 0; \
  } \
  \
  static int \
  simde_assert_equal_##symbol_identifier##_(T a, T b, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    if (HEDLEY_UNLIKELY(a != b)) { \
      simde_test_debug_printf_("%s:%d: assertion failed: %s == %s (%" fmt " == %" fmt ")\n", \
            filename, line, astr, bstr, a, b); \
      SIMDE_TEST_ASSERT_RETURN(1); \
    } \
    return 0; \
  } \
  \
  static int \
  simde_assert_close_v##symbol_identifier##_( \
      size_t vec_len, const T a[HEDLEY_ARRAY_PARAM(vec_len)], const T b[HEDLEY_ARRAY_PARAM(vec_len)], const T slop, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    for (size_t i = 0 ; i < vec_len ; i++) { \
      if (((a[i] + slop) < b[i]) || ((a[i] - slop) > b[i])) { \
        simde_test_debug_printf_("%s:%d: assertion failed: %s[%zu] == %s[%zu] (%" fmt " == %" fmt ")\n", \
              filename, line, astr, i, bstr, i, a[i], b[i]); \
        SIMDE_TEST_ASSERT_RETURN(1); \
      } \
    } \
    return 0; \
  } \
  \
  static int \
  simde_assert_close_##symbol_identifier##_(T a, T b, T slop, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    if (((a + slop) < b) || ((a - slop) > b)) { \
      simde_test_debug_printf_("%s:%d: assertion failed: %s == %s +/- %" fmt " (%" fmt " == %" fmt ")\n", \
            filename, line, astr, bstr, slop, a, b); \
      SIMDE_TEST_ASSERT_RETURN(1); \
    } \
    return 0; \
  }

static int
simde_assert_equal_i_(int a, int b, const char* filename, int line, const char* astr, const char* bstr) {
  if (HEDLEY_UNLIKELY(a != b)) {
    simde_test_debug_printf_("%s:%d: assertion failed: %s == %s (%d == %d)\n",
          filename, line, astr, bstr, a, b);
    SIMDE_TEST_ASSERT_RETURN(1);
  }
  return 0;
}

SIMDE_TEST_GENERATE_ASSERT_EQUAL_FUNC_(int8_t,    i8,  PRId8)
SIMDE_TEST_GENERATE_ASSERT_EQUAL_FUNC_(int16_t,  i16, PRId16)
SIMDE_TEST_GENERATE_ASSERT_EQUAL_FUNC_(int32_t,  i32, PRId32)
SIMDE_TEST_GENERATE_ASSERT_EQUAL_FUNC_(int64_t,  i64, PRId64)
SIMDE_TEST_GENERATE_ASSERT_EQUAL_FUNC_(uint8_t,   u8,  PRIu8)
SIMDE_TEST_GENERATE_ASSERT_EQUAL_FUNC_(uint16_t, u16, PRIu16)
SIMDE_TEST_GENERATE_ASSERT_EQUAL_FUNC_(uint32_t, u32, PRIu32)
SIMDE_TEST_GENERATE_ASSERT_EQUAL_FUNC_(uint64_t, u64, PRIu64)

#define simde_assert_equal_vi8(vec_len, a, b) do { if (simde_assert_equal_vi8_(vec_len, a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_vi16(vec_len, a, b) do { if (simde_assert_equal_vi16_(vec_len, a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_vi32(vec_len, a, b) do { if (simde_assert_equal_vi32_(vec_len, a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_vi64(vec_len, a, b) do { if (simde_assert_equal_vi64_(vec_len, a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_vu8(vec_len, a, b) do { if (simde_assert_equal_vu8_(vec_len, a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_vu16(vec_len, a, b) do { if (simde_assert_equal_vu16_(vec_len, a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_vu32(vec_len, a, b) do { if (simde_assert_equal_vu32_(vec_len, a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_vu64(vec_len, a, b) do { if (simde_assert_equal_vu64_(vec_len, a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)

#define simde_assert_equal_i8(a, b) do { if (simde_assert_equal_i8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_i16(a, b) do { if (simde_assert_equal_i16_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_i32(a, b) do { if (simde_assert_equal_i32_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_i64(a, b) do { if (simde_assert_equal_i64_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_u8(a, b) do { if (simde_assert_equal_u8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_u16(a, b) do { if (simde_assert_equal_u16_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_u32(a, b) do { if (simde_assert_equal_u32_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_u64(a, b) do { if (simde_assert_equal_u64_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_equal_i(a, b) do { if (simde_assert_equal_i_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)

#define simde_assert_close_vi8(vec_len, a, b, slop) do { if (simde_assert_close_vi8_(vec_len, a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_vi16(vec_len, a, b, slop) do { if (simde_assert_close_vi16_(vec_len, a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_vi32(vec_len, a, b, slop) do { if (simde_assert_close_vi32_(vec_len, a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_vi64(vec_len, a, b, slop) do { if (simde_assert_close_vi64_(vec_len, a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_vu8(vec_len, a, b, slop) do { if (simde_assert_close_vu8_(vec_len, a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_vu16(vec_len, a, b, slop) do { if (simde_assert_close_vu16_(vec_len, a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_vu32(vec_len, a, b, slop) do { if (simde_assert_close_vu32_(vec_len, a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_vu64(vec_len, a, b, slop) do { if (simde_assert_close_vu64_(vec_len, a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)

#define simde_assert_close_i8(a, b, slop) do { if (simde_assert_close_i8_(a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_i16(a, b, slop) do { if (simde_assert_close_i16_(a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_i32(a, b, slop) do { if (simde_assert_close_i32_(a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_i64(a, b, slop) do { if (simde_assert_close_i64_(a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_u8(a, b, slop) do { if (simde_assert_close_u8_(a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_u16(a, b, slop) do { if (simde_assert_close_u16_(a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_u32(a, b, slop) do { if (simde_assert_close_u32_(a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_u64(a, b, slop) do { if (simde_assert_close_u64_(a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_assert_close_i(a, b, slop) do { if (simde_assert_close_i_(a, b, slop, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)

/* Since each test is compiled in 4 different versions (C/C++ and
 * native/emul), we need to be able to generate different symbols
 * depending on preprocessor macros. */
#if defined(SIMDE_NO_NATIVE)
  #if defined(__cplusplus)
    #define SIMDE_TEST_GENERATE_VARIANT_SYMBOL_CURRENT(name) HEDLEY_CONCAT(name,_emul_cpp)
    #define SIMDE_TEST_GENERATE_VARIANT_NAME_CURRENT(name) #name "/emul/cpp"
  #else
    #define SIMDE_TEST_GENERATE_VARIANT_SYMBOL_CURRENT(name) HEDLEY_CONCAT(name,_emul_c)
    #define SIMDE_TEST_GENERATE_VARIANT_NAME_CURRENT(name) #name "/emul/c"
  #endif
#else
  #if defined(__cplusplus)
    #define SIMDE_TEST_GENERATE_VARIANT_SYMBOL_CURRENT(name) HEDLEY_CONCAT(name,_native_cpp)
    #define SIMDE_TEST_GENERATE_VARIANT_NAME_CURRENT(name) #name "/native/cpp"
  #else
    #define SIMDE_TEST_GENERATE_VARIANT_SYMBOL_CURRENT(name) HEDLEY_CONCAT(name,_native_c)
    #define SIMDE_TEST_GENERATE_VARIANT_NAME_CURRENT(name) #name "/native/c"
  #endif
#endif

/* The bare version basically assumes you just want to run a single
 * test suite.  It doesn't use munit, or any other dependencies so
 * it's easy to use with creduce. */
#if defined(SIMDE_TEST_BARE)
  typedef int (* SimdeTestFunc)(void);
  #define SIMDE_TEST_FUNC_LIST_BEGIN static SimdeTestFunc test_suite_tests[] = {
  #define SIMDE_TEST_FUNC_LIST_ENTRY(name) test_simde_##name,
  #define SIMDE_TEST_FUNC_LIST_END };
  #define SIMDE_MUNIT_TEST_ARGS void
#else
  HEDLEY_DIAGNOSTIC_PUSH
  SIMDE_DIAGNOSTIC_DISABLE_CPP98_COMPAT_PEDANTIC_
  SIMDE_DIAGNOSTIC_DISABLE_OLD_STYLE_CAST_
  SIMDE_DIAGNOSTIC_DISABLE_VARIADIC_MACROS_
  #include "munit/munit.h"
  HEDLEY_DIAGNOSTIC_POP

  #if \
      HEDLEY_HAS_ATTRIBUTE(unused) || \
      HEDLEY_GCC_VERSION_CHECK(3,1,0)
    #define SIMDE_MUNIT_TEST_ARGS __attribute__((__unused__)) const MunitParameter params[], __attribute__((__unused__)) void* data
  #else
    /* Compilers other than emscripten are fine with casting away
     * arguments. */
    #define SIMDE_MUNIT_TEST_ARGS void
  #endif

  #define SIMDE_TEST_FUNC_LIST_BEGIN static MunitTest test_suite_tests[] = {
  #if defined(__cplusplus)
    #define SIMDE_TEST_FUNC_LIST_ENTRY(name) { \
        const_cast<char*>("/" SIMDE_TEST_GENERATE_VARIANT_NAME_CURRENT(name)), \
        HEDLEY_REINTERPRET_CAST(MunitTestFunc, test_simde_##name), \
        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  #else
    #define SIMDE_TEST_FUNC_LIST_ENTRY(name) { \
        (char*) "/" SIMDE_TEST_GENERATE_VARIANT_NAME_CURRENT(name), \
        HEDLEY_REINTERPRET_CAST(MunitTestFunc, test_simde_##name), \
        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  #endif
  #define SIMDE_TEST_FUNC_LIST_END { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } };

  #define SIMDE_TEST_SUITE_DECLARE_GETTERS(name) \
    HEDLEY_C_DECL MunitSuite* HEDLEY_CONCAT(name, _native_c)(void); \
    HEDLEY_C_DECL MunitSuite* HEDLEY_CONCAT(name, _emul_c)(void); \
    HEDLEY_C_DECL MunitSuite* HEDLEY_CONCAT(name, _native_cpp)(void); \
    HEDLEY_C_DECL MunitSuite* HEDLEY_CONCAT(name, _emul_cpp)(void);
#endif

#endif /* !defined(SIMDE_TESTS_H) */
