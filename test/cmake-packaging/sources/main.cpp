#include <iostream>
#include <simde/x86/sse2.h>

int main() {
  simde__m128i a = simde_mm_setzero_si128();
  (void)a;
  std::cout << "SIMDe CMake test (C++) working successfully." << std::endl;
  return 0;
}
