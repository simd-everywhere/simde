#include <simde/x86/sse.h>
#include <stdio.h>

int main(void) {
  simde__m128 a = simde_mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
  (void)a;
  printf("SIMDe cmake FetchContent test works!\n");
  return 0;
}
