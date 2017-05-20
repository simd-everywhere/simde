/* Hedley - https://nemequ.github.io/hedley
 * Created by Evan Nemerson <evan@nemerson.com>
 *
 * To the extent possible under law, the author(s) have dedicated all
 * copyright and related and neighboring rights to this software to
 * the public domain worldwide. This software is distributed without
 * any warranty.
 *
 * For details, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 */

#if !defined(HEDLEY_VERSION) || (HEDLEY_VERSION < 2)
#if defined(HEDLEY_VERSION)
#  undef HEDLEY_VERSION
#endif
#define HEDLEY_VERSION 2

#if defined(HEDLEY_VERSION_ENCODE)
#  undef HEDLEY_VERSION_ENCODE
#endif
#define HEDLEY_VERSION_ENCODE(major,minor,revision) (((major) * 1000000) + ((minor) * 1000) + (revision))

#if defined(HEDLEY_VERSION_DECODE_MAJOR)
#  undef HEDLEY_VERSION_DECODE_MAJOR
#endif
#define HEDLEY_VERSION_DECODE_MAJOR(version) ((version) / 1000000)

#if defined(HEDLEY_VERSION_DECODE_MINOR)
#  undef HEDLEY_VERSION_DECODE_MINOR
#endif
#define HEDLEY_VERSION_DECODE_MINOR(version) (((version) % 1000000) / 1000)

#if defined(HEDLEY_VERSION_DECODE_REVISION)
#  undef HEDLEY_VERSION_DECODE_REVISION
#endif
#define HEDLEY_VERSION_DECODE_REVISION(version) ((version) % 1000)

#if defined(HEDLEY_GCC_VERSION_CHECK)
#  undef HEDLEY_GCC_VERSION_CHECK
#endif
#if !defined(__GNUC__)
#  define HEDLEY_GCC_VERSION_CHECK(major,minor,patch) 0
#else
#  if defined(__GNUC_PATCHLEVEL__)
#    define HEDLEY_GCC_VERSION_CHECK(major,minor,patch) (HEDLEY_VERSION_ENCODE(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__) >= HEDLEY_VERSION_ENCODE(major,minor,patch))
#  else
#    define HEDLEY_GCC_VERSION_CHECK(major,minor,patch) (HEDLEY_VERSION_ENCODE(__GNUC__, __GNUC_MINOR__, 0) >= HEDLEY_VERSION_ENCODE(major,minor,patch))
#  endif
#endif

#if defined(HEDLEY_GCC_NOT_CLANG_VERSION_CHECK)
#  undef HEDLEY_GCC_NOT_CLANG_VERSION_CHECK
#endif
#if defined(__clang__)
#  define HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch) 0
#else
#  define HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_MSVC_VERSION_CHECK)
#  undef HEDLEY_GCC_VERSION_CHECK
#endif
#if !defined(_MSC_VER)
#  define HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) 0
#elif defined(_MSC_VER) && (_MSC_VER >= 1400)
#  define HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_FULL_VER >= ((major * 1000000) + (minor * 10000) + (patch)))
#elif defined(_MSC_VER) && (_MSC_VER >= 1200)
#  define HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_FULL_VER >= ((major * 100000) + (minor * 1000) + (patch)))
#else
#  define HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_VER >= ((major * 100) + (minor)))
#endif

#if defined(HEDLEY_INTEL_VERSION_CHECK)
#  undef HEDLEY_INTEL_VERSION_CHECK
#endif
#if defined(__INTEL_COMPILER) && defined(__INTEL_COMPILER_UPDATE)
#  define HEDLEY_INTEL_VERSION_CHECK(major, minor, patch) ((__INTEL_COMPILER + __INTEL_COMPILER_UPDATE) >= (((major) * 100) + (minor)))
#elif defined(__INTEL_COMPILER)
#  define HEDLEY_INTEL_VERSION_CHECK(major,minor,patch) (__INTEL_COMPILER >= (((major) * 100) + (minor)))
#else
#  define HEDLEY_INTEL_VERSION_CHECK(major,minor,patch) 0
#endif

#if defined(HEDLEY_PGI_VERSION_CHECK)
#  undef HEDLEY_PGI_VERSION_CHECK
#endif
#if defined(__PGI)
#  define HEDLEY_PGI_VERSION_CHECK(major,minor,patch) (HEDLEY_VERSION_ENCODE(__PGIC__, __PGIC_MINOR__, __PGIC_PATCHLEVEL__) >= HEDLEY_VERSION_ENCODE(major,minor,patch))
#else
#  define HEDLEY_PGI_VERSION_CHECK(major,minor,patch) 0
#endif

#if defined(HEDLEY_SUNPRO_VERSION_CHECK)
#  undef HEDLEY_SUNPRO_VERSION_CHECK
#endif
#if defined(__SUNPRO_C)
#  define HEDLEY_SUNPRO_VERSION_CHECK(major,minor,patch) \
    (__SUNPRO_C >= ((((major) > 5) || (((major) == 5) && ((minor) > 9))) ? \
                    (((major) * 0x1000) + (((minor + (6 * (minor / 10)))) * 0x10) + (revision)) : \
                    (((major) * 0x100) + ((minor) * 0x10) + (revision))))
#elif defined(__SUNPRO_CC)
#  define HEDLEY_SUNPRO_VERSION_CHECK(major,minor,patch) \
    (__SUNPRO_CC >= ((((major) > 5) || (((major) == 5) && ((minor) > 9))) ? \
                     (((major) * 0x1000) + (((minor + (6 * (minor / 10)))) * 0x10) + (revision)) : \
                     (((major) * 0x100) + ((minor) * 0x10) + (revision))))
#else
#  define HEDLEY_SUNPRO_VERSION_CHECK(major,minor,patch) 0
#endif

#if defined(HEDLEY_EMSCRIPTEN_VERSION_CHECK)
#  undef HEDLEY_EMSCRIPTEN_VERSION_CHECK
#endif
#if defined(__EMSCRIPTEN__)
#  define HEDLEY_EMSCRIPTEN_VERSION_CHECK(major,minor,patch) \
  (HEDLEY_VERSION_ENCODE(__EMSCRIPTEN_major__, __EMSCRIPTEN_minor__, __EMSCRIPTEN_tiny__) >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_EMSCRIPTEN_VERSION_CHECK(major,minor,patch) 0
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#  define HEDLEY_PRAGMA(value) _Pragma(#value)
#elif HEDLEY_GCC_VERSION_CHECK(3,0,0)
#  define HEDLEY_PRAGMA(value) _Pragma(#value)
#elif HEDLEY_MSVC_VERSION_CHECK(15,0,0)
#  define HEDLEY_PRAGMA(value) __pragma(value)
#else
#  define HEDLEY_PRAGMA(value)
#endif

#if defined(HEDLEY_CLANG_HAS_ATTRIBUTE)
#  undef HEDLEY_CLANG_HAS_ATTRIBUTE
#endif
#if defined(HEDLEY_CLANG_HAS_BUILTIN)
#  undef HEDLEY_CLANG_HAS_BUILTIN
#endif
#if defined(HEDLEY_CLANG_HAS_FEATURE)
#  undef HEDLEY_CLANG_HAS_FEATURE
#endif
#if defined(HEDLEY_CLANG_HAS_EXTENSION)
#  undef HEDLEY_CLANG_HAS_EXTENSION
#endif
#if defined(HEDLEY_CLANG_HAS_DECLSPEC_ATTRIBUTE)
#  undef HEDLEY_CLANG_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(HEDLEY_CLANG_HAS_WARNING)
#  undef HEDLEY_CLANG_HAS_WARNING
#endif
#if defined(__clang__) && defined(__has_attribute)
#  define HEDLEY_CLANG_HAS_ATTRIBUTE(attribute) __has_attribute(attribute)
#else
#  define HEDLEY_CLANG_HAS_ATTRIBUTE(attribute) 0
#endif
#if defined(__clang__) && defined(__has_builtin)
#  define HEDLEY_CLANG_HAS_BUILTIN(builtin) __has_builtin(builtin)
#else
#  define HEDLEY_CLANG_HAS_BUILTIN(builtin) 0
#endif
#if defined(__clang__) && defined(__has_feature)
#  define HEDLEY_CLANG_HAS_FEATURE(feature) __has_feature(feature)
#else
#  define HEDLEY_CLANG_HAS_FEATURE(feature) 0
#endif
#if defined(__clang__) && defined(__has_extension)
#  define HEDLEY_CLANG_HAS_EXTENSION(extension) __has_extension(extension)
#else
#  define HEDLEY_CLANG_HAS_EXTENSION(extension) 0
#endif
#if defined(__clang__) && defined(__has_declspec_attribute)
#  define HEDLEY_CLANG_HAS_DECLSPEC_ATTRIBUTE(attribute) __has_declspec_attribute(attribute)
#else
#  define HEDLEY_CLANG_HAS_DECLSPEC_ATTRIBUTE(attribute) 0
#endif
#if defined(__clang__) && defined(__has_warning)
#  define HEDLEY_CLANG_HAS_WARNING(warning) __has_warning(warning)
#else
#  define HEDLEY_CLANG_HAS_WARNING(warning) 0
#endif

#if defined(HEDLEY_GCC_HAS_ATTRIBUTE)
#  undef HEDLEY_GCC_HAS_ATTRIBUTE
#endif
#if defined(HEDLEY_GCC_HAS_BUILTIN)
#  undef HEDLEY_GCC_HAS_BUILTIN
#endif
#if defined(HEDLEY_GCC_HAS_FEATURE)
#  undef HEDLEY_GCC_HAS_FEATURE
#endif
#if defined(HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE)
#  undef HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(HEDLEY_GCC_HAS_WARNING)
#  undef HEDLEY_GCC_HAS_WARNING
#endif
#define HEDLEY_GCC_HAS_ATTRIBUTE(attribute,major,minor,patch) (HEDLEY_CLANG_HAS_ATTRIBUTE(attribute) || HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch))
#define HEDLEY_GCC_HAS_BUILTIN(builtin,major,minor,patch) (HEDLEY_CLANG_HAS_BUILTIN(builtin) || HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch))
#define HEDLEY_GCC_HAS_FEATURE(feature,major,minor,patch) (HEDLEY_CLANG_HAS_FEATURE(feature) || HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch))
#define HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) (HEDLEY_CLANG_HAS_DECLSPEC_ATTRIBUTE(attribute) || HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch))
#define HEDLEY_GCC_HAS_WARNING(warning,major,minor,patch) (HEDLEY_CLANG_HAS_WARNING(warning) || HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch))

#if defined(HEDLEY_DEPRECATED)
#  undef HEDLEY_DEPRECATED
#endif
#if defined(HEDLEY_DEPRECATED_FOR)
#  undef HEDLEY_DEPRECATED_FOR
#endif
#if defined(__cplusplus) && (__cplusplus >= 201402L)
#  define HEDLEY_DEPRECATED(since) [[deprecated("Since " #since)]]
#  define HEDLEY_DEPRECATED_FOR(since, replacement) [[deprecated("Since " #since "; use " #replacement)]]
#elif HEDLEY_CLANG_HAS_EXTENSION(attribute_deprecated_with_message) || HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(4,5,0)
#  define HEDLEY_DEPRECATED(since) __attribute__((__deprecated__("Since " #since)))
#  define HEDLEY_DEPRECATED_FOR(since, replacement) __attribute__((__deprecated__("Since " #since "; use " #replacement)))
#elif HEDLEY_GCC_HAS_ATTRIBUTE(deprcated,4,0,0)
#  define HEDLEY_DEPRECATED(since) __attribute__((__deprecated__))
#  define HEDLEY_DEPRECATED_FOR(since, replacement) __attribute__((__deprecated__))
#elif HEDLEY_MSVC_VERSION_CHECK(14,0,0)
#  define HEDLEY_DEPRECATED(since) __declspec(deprecated("Since " # since))
#  define HEDLEY_DEPRECATED_FOR(since, replacement) __declspec(deprecated("Since " #since "; use " #replacement))
#elif HEDLEY_MSVC_VERSION_CHECK(13,10,0)
#  define HEDLEY_DEPRECATED(since) _declspec(deprecated)
#  define HEDLEY_DEPRECATED_FOR(since, replacement) __declspec(deprecated)
#else
#  define HEDLEY_DEPRECATED(since)
#  define HEDLEY_DEPRECATED_FOR(since, replacement)
#endif

#if defined(HEDLEY_UNAVAILABLE)
#  undef HEDLEY_UNAVAILABLE
#endif
#if HEDLEY_GCC_HAS_ATTRIBUTE(warning,4,3,0)
#  define HEDLEY_UNAVAILABLE(available_since) __attribute__((warning("Not available until " #available_since)))
#else
#  define HEDLEY_UNAVAILABLE(available_since)
#endif

#if defined(HEDLEY_WARN_UNUSED_RESULT)
#  undef HEDLEY_WARN_UNUSED_RESULT
#endif
#if HEDLEY_GCC_HAS_ATTRIBUTE(warn_unused_result,3,4,0)
#  define HEDLEY_WARN_UNUSED_RESULT __attribute__((__warn_unused_result__))
#elif defined(_Check_return_)
#  define HEDLEY_WARN_UNUSED_RESULT _Check_return_
#else
#  define HEDLEY_WARN_UNUSED_RESULT
#endif

#if defined(HEDLEY_SENTINEL)
#  undef HEDLEY_SENTINEL
#endif
#if HEDLEY_GCC_HAS_ATTRIBUTE(sentinel,4,0,0)
#  define HEDLEY_SENTINEL(position) __attribute__((__sentinel__(position)))
#else
#  define HEDLEY_SENTINEL(position)
#endif

#if defined(HEDLEY_NO_RETURN)
#  undef HEDLEY_NO_RETURN
#endif
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#  define HEDLEY_NO_RETURN _Noreturn
#elif HEDLEY_GCC_HAS_ATTRIBUTE(noreturn,3,2,0)
#  define HEDLEY_NO_RETURN __attribute__((__noreturn__))
#elif HEDLEY_MSVC_VERSION_CHECK(13,10,0)
#  define HEDLEY_NO_RETURN __declspec(noreturn)
#else
#  define HEDLEY_NO_RETURN
#endif

#if defined(HEDLEY_UNREACHABLE)
#  undef HEDLEY_UNREACHABLE
#endif
#if defined(assert)
#  if HEDLEY_GCC_HAS_BUILTIN(__builtin_unreachable,4,5,0)
#    define HEDLEY_UNREACHABLE() do { assert(0); __builtin_unreachable(); } while(0)
#  elif HEDLEY_MSVC_VERSION_CHECK(13,10,0)
#    define HEDLEY_UNREACHABLE() do { assert(0); __assume(0); } while(0)
#  elif defined(EXIT_FAILURE)
#    define HEDLEY_UNREACHABLE() do { assert(0); abort(); } while(0)
#  else
#    define HEDLEY_UNREACHABLE() assert(0)
#  endif
#else
#  if HEDLEY_GCC_HAS_BUILTIN(__builtin_unreachable,4,5,0)
#    define HEDLEY_UNREACHABLE() __builtin_unreachable();
#  elif HEDLEY_MSVC_VERSION_CHECK(13,10,0)
#    define HEDLEY_UNREACHABLE() __assume(0);
#  elif defined(EXIT_FAILURE)
#    define HEDLEY_UNREACHABLE() abort();
#  else
#    define HEDLEY_UNREACHABLE() (0)
#  endif
#endif

#if defined(HEDLEY_NON_NULL)
#  undef HEDLEY_NON_NULL
#endif
#if HEDLEY_GCC_HAS_ATTRIBUTE(nonnull,3,3,0)
#  define HEDLEY_NON_NULL(...) __attribute__((__nonnull__(__VA_ARGS__)))
#else
#  define HEDLEY_NON_NULL(...)
#endif

#if defined(HEDLEY_PRINTF_FORMAT)
#  undef HEDLEY_PRINTF_FORMAT
#endif
#if HEDLEY_GCC_HAS_ATTRIBUTE(format,3,1,0)
#  if HEDLEY_GCC_VERSION_CHECK(4,4,0) && defined(__MINGW32__) && !defined(__USE_MINGW_ANSI_STDIO)
#    define HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(ms_printf, string, first_to_check)))
#  elif HEDLEY_GCC_VERSION_CHECK(4,4,0)
#    define HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(gnu_printf, string, first_to_check)))
#  elif defined(__MINGW32__)
#    define HEDLEY_PRINTF_FORMAT(string_idx,first_to_check)
#  else
#    define HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(printf, string, first_to_check)))
#  endif
#else
#  define HEDLEY_PRINTF_FORMAT(string_idx,first_to_check)
#endif

#if defined(HEDLEY_LIKELY)
#  undef HEDLEY_LIKELY
#endif
#if defined(HEDLEY_UNLIKELY)
#  undef HEDLEY_UNLIKELY
#endif
#if HEDLEY_GCC_HAS_BUILTIN(__builtin_expect,3,0,0)
#  define HEDLEY_LIKELY(expr) __builtin_expect(((expr) != 0), 1)
#  define HEDLEY_UNLIKELY(expr) __builtin_expect(((expr) != 0), 0)
#else
#  define HEDLEY_LIKELY(expr) ((expr) != 0)
#  define HEDLEY_UNLIKELY(expr) ((expr) != 0)
#endif

#if defined(HEDLEY_MALLOC)
#  undef HEDLEY_MALLOC
#endif
#if HEDLEY_GCC_HAS_ATTRIBUTE(malloc, 3, 1, 0)
#  define HEDLEY_MALLOC __attribute__((__malloc__))
#elif HEDLEY_MSVC_VERSION_CHECK(14, 0, 0)
#  define HEDLEY_MALLOC __declspec(restrict)
#else
#  define HEDLEY_MALLOC
#endif

#if defined(HEDLEY_PURE)
#  undef HEDLEY_PURE
#endif
#if HEDLEY_GCC_HAS_ATTRIBUTE(pure, 2, 96, 0)
#  define HEDLEY_PURE __attribute__((__pure__))
#elif HEDLEY_MSVC_VERSION_CHECK(14, 0, 0)
#  define HEDLEY_PURE __declspec(noalias)
#else
#  define HEDLEY_PURE
#endif

#if defined(HEDLEY_CONST)
#  undef HEDLEY_CONST
#endif
#if HEDLEY_GCC_HAS_ATTRIBUTE(const, 2, 5, 0)
#  define HEDLEY_CONST __attribute__((__const__))
#else
#  define HEDLEY_CONST HEDLEY_PURE
#endif

#if defined(HEDLEY_RESTRICT)
#  undef HEDLEY_RESTRICT
#endif
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#  define HEDLEY_RESTRICT restrict
#elif HEDLEY_GCC_VERSION_CHECK(3,1,0) || HEDLEY_MSVC_VERSION_CHECK(14,0,0)
#  define HEDLEY_RESTRICT __restrict
#elif HEDLEY_SUNPRO_VERSION_CHECK(5,8,0)
#  define HEDLEY_RESTRICT _Restrict
#endif

#if defined(HEDLEY_INLINE)
#  undef HEDLEY_INLINE
#endif
#if defined(HEDLEY_ALWAYS_INLINE)
#  undef HEDLEY_ALWAYS_INLINE
#endif
#if defined(HEDLEY_NEVER_INLINE)
#  undef HEDLEY_NEVER_INLINE
#endif
/* HEDLEY_INLINE */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#  define HEDLEY_INLINE inline
#elif defined(__GNUC_STDC_INLINE__)
#  define HEDLEY_INLINE __inline__
#elif HEDLEY_MSVC_VERSION_CHECK(12,0,0)
#  define HEDLEY_INLINE __inline
#else
#  define HEDLEY_INLINE
#endif
/* HEDLEY_ALWAYS_INLINE */
#if HEDLEY_GCC_HAS_ATTRIBUTE(always_inline,4,0,0)
#  define HEDLEY_ALWAYS_INLINE __attribute__((__always_inline__))
#elif HEDLEY_MSVC_VERSION_CHECK(12,0,0)
#  define HEDLEY_ALWAYS_INLINE __forceinline
#else
#  define HEDLEY_ALWAYS_INLINE HEDLEY_INLINE
#endif
/* HEDLEY_NEVER_INLINE */
#if HEDLEY_GCC_HAS_ATTRIBUTE(never_inline,4,0,0)
#  define HEDLEY_NEVER_INLINE __attribute__((__noinline__))
#elif HEDLEY_MSVC_VERSION_CHECK(13,10,0)
#  define HEDLEY_NEVER_INLINE __declspec(noinline)
#else
#  define HEDLEY_NEVER_INLINE HEDLEY_INLINE
#endif

#if defined(HEDLEY_PRIVATE)
#  undef HEDLEY_PRIVATE
#endif
#if defined(HEDLEY_PUBLIC)
#  undef HEDLEY_PUBLIC
#endif
#if defined(HEDLEY_IMPORT)
#  undef HEDLEY_IMPORT
#endif
#if defined(_WIN32) || defined(__CYGWIN__)
#  if HEDLEY_GCC_VERSION_CHECK(4,2,0)
#    define HEDLEY_PRIVATE __attribute__((visibility ("hidden")))
#  else
#    define HEDLEY_PRIVATE
#  endif
#  define HEDLEY_PUBLIC   __declspec(dllexport)
#  define HEDLEY_IMPORT   __declspec(dllimport)
#else
#  if HEDLEY_GCC_VERSION_CHECK(4,2,0)
#    define HEDLEY_PRIVATE __attribute__((visibility ("hidden")))
#    define HEDLEY_PUBLIC  __attribute__((visibility ("default")))
#  else
#    define HEDLEY_PRIVATE
#    define HEDLEY_PUBLIC
#  endif
#  define HEDLEY_IMPORT    extern
#endif

#if defined(HEDLEY_NO_THROW)
#  undef HEDLEY_NO_THROW
#endif
#if HEDLEY_GCC_HAS_ATTRIBUTE(nothrow,3,3,0)
#  define HEDLEY_NO_THROW __attribute__((__nothrow__))
#elif HEDLEY_MSVC_VERSION_CHECK(13,1,0)
#  define HEDLEY_NO_THROW __declspec(nothrow)
#else
#  define HEDLEY_NO_THROW
#endif

#if defined(HEDLEY_ARRAY_PARAM)
#  undef HEDLEY_ARRAY_PARAM
#endif
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) && !defined(__cplusplus) && !defined(__PGI)
#  define HEDLEY_ARRAY_PARAM(name) name
#else
#  define HEDLEY_ARRAY_PARAM(name)
#endif

#if defined(HEDLEY_BEGIN_C_DECLS)
#  undef HEDLEY_BEGIN_C_DECLS
#endif
#if defined(HEDLEY_END_C_DECLS)
#  undef HEDLEY_END_C_DECLS
#endif
#if defined(HEDLEY_C_DECL)
#  undef HEDLEY_C_DECL
#endif
#if defined(__cplusplus)
#  define HEDLEY_BEGIN_C_DECLS extern "C" {
#  define HEDLEY_END_C_DECLS }
#  define HEDLEY_C_DECL extern "C"
#else
#  define HEDLEY_BEGIN_C_DECLS
#  define HEDLEY_END_C_DECLS
#  define HEDLEY_C_DECL
#endif

#if defined(HEDLEY_STATIC_ASSERT)
#  undef HEDLEY_STATIC_ASSERT
#endif
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#  define HEDLEY_STATIC_ASSERT(expr, message) _Static_assert(expr, message)
#elif defined(__cplusplus) && __cplusplus >= 201103L
#  define HEDLEY_STATIC_ASSERT(expr, message) static_assert(expr, message)
#elif HEDLEY_GCC_HAS_FEATURE(c_static_assert,4,6,0)
#  define HEDLEY_STATIC_ASSERT(expr, message) _Static_assert(expr, message)
#elif HEDLEY_MSVC_VERSION_CHECK(16,0,0)
#  define HEDLEY_STATIC_ASSERT(expr, message) static_assert(expr, message)
#else
#  define HEDLEY_STATIC_ASSERT(expr, message)
#endif

#if defined(HEDLEY_DIAGNOSTIC_PUSH)
#  undef HEDLEY_DIAGNOSTIC_PUSH
#endif
#if defined(HEDLEY_DIAGNOSTIC_POP)
#  undef HEDLEY_DIAGNOSTIC_POP
#endif
#if defined(__clang__)
#  define HEDLEY_DIAGNOSTIC_PUSH _Pragma("clang diagnostic push")
#  define HEDLEY_DIAGNOSTIC_POP _Pragma("clang diagnostic pop")
#elif HEDLEY_INTEL_VERSION_CHECK(16,0,0)
#  define HEDLEY_DIAGNOSTIC_PUSH _Pragma("warning(push)")
#  define HEDLEY_DIAGNOSTIC_POP _Pragma("warning(pop)")
#elif HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(4,6,0)
#  define HEDLEY_DIAGNOSTIC_PUSH _Pragma("GCC diagnostic push")
#  define HEDLEY_DIAGNOSTIC_POP _Pragma("GCC diagnostic pop")
#elif HEDLEY_MSVC_VERSION_CHECK(15,0,0)
#  define HEDLEY_DIAGNOSTIC_PUSH __pragma(warning(push))
#  define HEDLEY_DIAGNOSTIC_POP __pragma(warning(pop))
#else
#  define HEDLEY_DIAGNOSTIC_PUSH
#  define HEDLEY_DIAGNOSTIC_POP
#endif

#if defined(HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED)
#  undef HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED
#endif
#if HEDLEY_CLANG_HAS_WARNING("-Wdeprecated")
#  define HEDELY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("clang diagnostic ignored \"-Wdeprecated\"")
#elif HEDLEY_INTEL_VERSION_CHECK(16,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("warning(disable:1478)")
#elif HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(4,3,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("GCC diagnostic ignored \"-Wdeprecated\"")
#elif HEDLEY_MSVC_VERSION_CHECK(15,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED __pragma(warning(disable:4996))
#else
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED
#endif

#if defined(HEDLEY_ASSUME_ALIGNED)
#  undef HEDLEY_ASSUME_ALIGNED
#endif
#if HEDLEY_INTEL_VERSION_CHECK(9,0,0)
#  define HEDLEY_ASSUME_ALIGNED(ptr, align) __assume_aligned(ptr, align)
#elif HEDLEY_MSVC_VERSION_CHECK(13,10,0)
#  define HEDLEY_ASSUME_ALIGNED(ptr, align) __assume((((char*) ptr) - ((char*) 0)) % (align) == 0)
#elif HEDLEY_GCC_HAS_BUILTIN(__builtin_assume_aligned,4,7,0)
#  define HEDLEY_ASSUME_ALIGNED(ptr, align) (ptr = (__typeof__(ptr)) __builtin_assume_aligned((ptr), align))
#elif HEDLEY_CLANG_HAS_BUILTIN(__builtin_assume)
#  define HEDLEY_ASSUME_ALIGNED(ptr, align) __builtin_assume((((char*) ptr) - ((char*) 0)) % (align) == 0)
#elif HEDLEY_GCC_HAS_BUILTIN(__builtin_unreachable,4,5,0)
#  define HEDLEY_ASSUME_ALIGNED(ptr, align) ((((char*) ptr) - ((char*) 0)) % (align) == 0) ? (1) : (__builtin_unreachable(), 0)
#else
#  define HEDLEY_ASSUME_ALIGNED(ptr, align)
#endif

#endif /* !defined(HEDLEY_VERSION) || (HEDLEY_VERSION < X) */
