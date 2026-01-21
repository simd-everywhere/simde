#include <iostream>
#include <simde/x86/sse.h>

int main() {
  simde__m128 a = simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
  (void)a;
  std::cout << "SIMDe cmake install test works (C++)!" << std::endl;
  return 0;
}
