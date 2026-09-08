// Simplified version of
// https://github.com/simd-everywhere/simde/blob/59b52d0b74eeb8417b1ec512ffe804177257fbf2/test/arm/neon/qrshrn_n.c#L690

#include <arm_neon.h>
#include <stdarg.h>
#include <stdio.h>

static void simde_test_debug_printf_(const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  vfprintf(stdout, format, ap);
  va_end(ap);
  fflush(stdout);
}

static int simde_assert_equal_u16_(uint16_t a, uint16_t b, const char *filename,
                                   int line, const char *astr,
                                   const char *bstr) {
  if ((!!(a != b))) {
    simde_test_debug_printf_("%s:%d: assertion failed: %s == %s (%"
                             "hu"
                             " == %"
                             "hu"
                             ")\n",
                             filename, line, astr, bstr, a, b);
    return 1;
  }
  return 0;
}

static int test_simde_vqrshrnh_n_u16(void) {
  static const struct {
    uint16_t a;
    uint8_t r1;
    uint8_t r3;
    uint8_t r5;
    uint8_t r7;
    uint8_t r8;
  } test_vec[] = {{UINT16_C(32767), UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX,
                   UINT8_C(128)},
                  {UINT16_C(29541), UINT8_MAX, UINT8_MAX, UINT8_MAX,
                   UINT8_C(231), UINT8_C(115)},
                  {UINT16_C(12766), UINT8_MAX, UINT8_MAX, UINT8_MAX,
                   UINT8_C(100), UINT8_C(50)},
                  {UINT16_C(5687), UINT8_MAX, UINT8_MAX, UINT8_C(178),
                   UINT8_C(44), UINT8_C(22)}};

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    uint16_t r1 = vqrshrnh_n_u16(test_vec[i].a, 1);
    uint16_t r3 = vqrshrnh_n_u16(test_vec[i].a, 3);
    uint16_t r5 = vqrshrnh_n_u16(test_vec[i].a, 5);
    uint16_t r7 = vqrshrnh_n_u16(test_vec[i].a, 7);
    uint16_t r8 = vqrshrnh_n_u16(test_vec[i].a, 8);

    do {
      if (simde_assert_equal_u16_(r1, test_vec[i].r1,
                                  "../test/arm/neon/qrshrn_n.c", 77, "r1",
                                  "test_vec[i].r1")) {
        return 1;
      }
    } while (0);
    do {
      if (simde_assert_equal_u16_(r3, test_vec[i].r3,
                                  "../test/arm/neon/qrshrn_n.c", 78, "r3",
                                  "test_vec[i].r3")) {
        return 1;
      }
    } while (0);
    do {
      if (simde_assert_equal_u16_(r5, test_vec[i].r5,
                                  "../test/arm/neon/qrshrn_n.c", 79, "r5",
                                  "test_vec[i].r5")) {
        return 1;
      }
    } while (0);
    do {
      if (simde_assert_equal_u16_(r7, test_vec[i].r7,
                                  "../test/arm/neon/qrshrn_n.c", 80, "r7",
                                  "test_vec[i].r7")) {
        return 1;
      }
    } while (0);
    do {
      if (simde_assert_equal_u16_(r8, test_vec[i].r8,
                                  "../test/arm/neon/qrshrn_n.c", 81, "r8",
                                  "test_vec[i].r8")) {
        return 1;
      }
    } while (0);
  }

  return 0;
}

static const struct {
  int (*func)(void);
  const char *name;
} test_suite_tests[] = {
    {test_simde_vqrshrnh_n_u16, "vqrshrnh_n_u16"},
};

int main(void) {
  int retval = 0;

  fprintf(stdout, "1..%zu\n",
          (sizeof(test_suite_tests) / sizeof(test_suite_tests[0])));
  for (size_t i = 0;
       i < (sizeof(test_suite_tests) / sizeof(test_suite_tests[0])); i++) {
    int res = test_suite_tests[i].func();
    if (res != 0) {
      retval = 1;
      fprintf(stdout,
              "not ok %zu "
              "vqrshrnh_n_u16"
              "/%s\n",
              i + 1, test_suite_tests[i].name);
    } else {
      fprintf(stdout,
              "ok %zu "
              "vqrshrnh_n_u16"
              "/%s\n",
              i + 1, test_suite_tests[i].name);
    }
  }

  return retval;
}
