#include "test.h"

#include <math.h>

#if defined(SIMDE__ENABLE_DEBUG_ARRAY)
void debug_array_u8(const char* prefix, size_t nmemb, uint8_t v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " %3" PRIu8, v[i]);
  }
  fprintf(stderr, "\n");
}

void debug_array_u16(const char* prefix, size_t nmemb, uint16_t v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " %5" PRIu16, v[i]);
  }
  fprintf(stderr, "\n");
}

void debug_array_u32(const char* prefix, size_t nmemb, uint32_t v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " %10" PRIu32, v[i]);
  }
  fprintf(stderr, "\n");
}

void debug_array_u64(const char* prefix, size_t nmemb, uint64_t v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " %20" PRIu64, v[i]);
  }
  fprintf(stderr, "\n");
}

void debug_array_i8(const char* prefix, size_t nmemb, int8_t v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " %4" PRId8, v[i]);
  }
  fprintf(stderr, "\n");
}

void debug_array_i16(const char* prefix, size_t nmemb, int16_t v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " %6" PRId16, v[i]);
  }
  fprintf(stderr, "\n");
}

void debug_array_i32(const char* prefix, size_t nmemb, int32_t v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " %11" PRId32, v[i]);
  }
  fprintf(stderr, "\n");
}

void debug_array_i64(const char* prefix, size_t nmemb, int64_t v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " %21" PRId64, v[i]);
  }
  fprintf(stderr, "\n");
}

void debug_array_f32(const char* prefix, size_t nmemb, simde_float32 v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " %2.6f", v[i]);
  }
  fprintf(stderr, "\n");
}
#endif

void random_f32v(size_t nmemb, simde_float32 v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  for (size_t i = 0 ; i < nmemb ; i++) {
    do {
      munit_rand_memory(sizeof(v[i]), (uint8_t*) &(v[i]));
    } while (!isnormal(v[i]));
  }
}

simde_float64 random_f64_range(simde_float64 min, simde_float64 max) {
  const simde_float64 range = max - min;
  simde_float64 x = (simde_float64) munit_rand_uint32();
  x /= ((simde_float32) UINT32_MAX) / range;
  x += min;
  return x;
}

simde_float32 random_f32_range(simde_float32 min, simde_float32 max) {
  return (simde_float32) random_f64_range(min, max);
}

void random_f64v(size_t nmemb, simde_float64 v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  for (size_t i = 0 ; i < nmemb ; i++) {
    do {
      munit_rand_memory(sizeof(v[i]), (uint8_t*) &(v[i]));
    } while (!isnormal(v[i]));
  }
}
