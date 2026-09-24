#if defined(SIMDE_NO_TESTS)
#error "SIMDE_NO_TESTS is defined"
#endif
#include <simde/x86/sse2.h>
#include <stdio.h>

int main(void) {
  simde__m128i a = simde_mm_setzero_si128();
  (void)a;
  printf("SIMDe CMake test (C) working successfully.\n");
  return 0;
}
