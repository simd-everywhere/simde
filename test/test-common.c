#include "test.h"

#include <math.h>

void debug_array_u8(const char* prefix, size_t nmemb, uint8_t v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " 0x%02hhx", v[i]);
  }
  fprintf(stderr, "\n");
}

void debug_array_u16(const char* prefix, size_t nmemb, uint16_t v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " 0x%04" PRIx16, v[i]);
  }
  fprintf(stderr, "\n");
}

void debug_array_u32(const char* prefix, size_t nmemb, uint32_t v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " 0x%08" PRIx32, v[i]);
  }
  fprintf(stderr, "\n");
}

void debug_array_u64(const char* prefix, size_t nmemb, uint64_t v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " 0x%08" PRIx64, v[i]);
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

void debug_array_f32(const char* prefix, size_t nmemb, float v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " %2.6f", v[i]);
  }
  fprintf(stderr, "\n");
}

void random_floatv(size_t nmemb, float v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  for (size_t i = 0 ; i < nmemb ; i++) {
    do {
      munit_rand_memory(sizeof(v[i]), (uint8_t*) &(v[i]));
    } while (!isnormal(v[i]));
  }
}

double random_double_range(double min, double max) {
  const double range = max - min;
  double x = (double) munit_rand_uint32();
  x /= ((float) UINT32_MAX) / range;
  x += min;
  return x;
}
