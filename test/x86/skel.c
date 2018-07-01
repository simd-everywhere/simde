/* These are just some skeletons I've been using to speed up the
   process of creating new tests for SSE functions. */

static MunitResult
test_simde_mm_xxx_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_epi8(a, b);

    printf("    { simde_mm_set_epi8(INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd)),\n",
           a.i8[15], a.i8[14], a.i8[13], a.i8[12], a.i8[11], a.i8[10], a.i8[ 9], a.i8[ 8],
           a.i8[ 7], a.i8[ 6], a.i8[ 5], a.i8[ 4], a.i8[ 3], a.i8[ 2], a.i8[ 1], a.i8[ 0]);
    printf("      simde_mm_set_epi8(INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd)),\n",
           b.i8[15], b.i8[14], b.i8[13], b.i8[12], b.i8[11], b.i8[10], b.i8[ 9], b.i8[ 8],
           b.i8[ 7], b.i8[ 6], b.i8[ 5], b.i8[ 4], b.i8[ 3], b.i8[ 2], b.i8[ 1], b.i8[ 0]);
    printf("      simde_mm_set_epi8(INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd)) },\n",
           r.i8[15], r.i8[14], r.i8[13], r.i8[12], r.i8[11], r.i8[10], r.i8[ 9], r.i8[ 8],
           r.i8[ 7], r.i8[ 6], r.i8[ 5], r.i8[ 4], r.i8[ 3], r.i8[ 2], r.i8[ 1], r.i8[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_xxx_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_epi16(a, b);

    printf("    { simde_mm_set_epi16(INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	   "                         INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd)),\n",
           a.i16[7], a.i16[6], a.i16[5], a.i16[4], a.i16[3], a.i16[2], a.i16[1], a.i16[0]);
    printf("      simde_mm_set_epi16(INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	   "                         INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd)),\n",
           b.i16[7], b.i16[6], b.i16[5], b.i16[4], b.i16[3], b.i16[2], b.i16[1], b.i16[0]);
    printf("      simde_mm_set_epi16(INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	   "                         INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd)) },\n",
           r.i16[7], r.i16[6], r.i16[5], r.i16[4], r.i16[3], r.i16[2], r.i16[1], r.i16[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_xxx_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_epi32(a, b);

    printf("    { simde_mm_set_epi32(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)),\n",
  	   a.i32[3], a.i32[2], a.i32[1], a.i32[0]);
    printf("      simde_mm_set_epi32(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)),\n",
  	   b.i32[3], b.i32[2], b.i32[1], b.i32[0]);
    printf("      simde_mm_set_epi32(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)) },\n",
  	   r.i32[3], r.i32[2], r.i32[1], r.i32[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_xxx_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_epi64(a, b);

    printf("    { simde_mm_set_epi64x(INT64_C(%20ld), INT64_C(%20ld)),\n", a.i64[1], a.i64[0]);
    printf("      simde_mm_set_epi64x(INT64_C(%20ld), INT64_C(%20ld)),\n", b.i64[1], b.i64[0]);
    printf("      simde_mm_set_epi64x(INT64_C(%20ld), INT64_C(%20ld)) },\n", r.i64[1], r.i64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_xxx_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128d a, b, r;

    for (size_t j = 0 ; j < sizeof(simde__m128) / sizeof(simde_float64) ; j++) {
      a.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
      b.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
    }

    r = simde_mm_xxx_pd(a, b);

    printf("    { simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, a.f64[1], 8, a.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, b.f64[1], 8, b.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n", 8, r.f64[1], 8, r.f64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_xxx_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 a, b, r;

    for (size_t j = 0 ; j < sizeof(simde__m128) / sizeof(simde_float32) ; j++) {
      a.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
      b.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
    }

    r = simde_mm_xxx_ps(a, b);

    printf("    { simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	   8, a.f32[3], 8, a.f32[2], 8, a.f32[1], 8, a.f32[0]);
    printf("      simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	   8, b.f32[3], 8, b.f32[2], 8, b.f32[1], 8, b.f32[0]);
    printf("      simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)) },\n",
	   8, r.f32[3], 8, r.f32[2], 8, r.f32[1], 8, r.f32[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_xxx_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128d a, b, r;

    for (size_t j = 0 ; j < sizeof(simde__m128) / sizeof(simde_float64) ; j++) {
      a.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
      b.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
    }

    r = simde_mm_xxx_sd(a, b);

    printf("    { simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, a.f64[1], 8, a.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, b.f64[1], 8, b.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n", 8, r.f64[1], 8, r.f64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_xxx_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_si64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_si64(a, b);

    printf("    { simde_mm_cvtsi64_m64(INT64_C(%20ld)),\n", a.i64[0]);
    printf("      simde_mm_cvtsi64_m64(INT64_C(%20ld)),\n", b.i64[0]);
    printf("      simde_mm_cvtsi64_m64(INT64_C(%20ld)), },\n", r.i64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_xxx_si64(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_epi8(a, b);

    printf("    { simde_mm_set_epi8(INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd)),\n",
           a.i8[15], a.i8[14], a.i8[13], a.i8[12], a.i8[11], a.i8[10], a.i8[ 9], a.i8[ 8],
           a.i8[ 7], a.i8[ 6], a.i8[ 5], a.i8[ 4], a.i8[ 3], a.i8[ 2], a.i8[ 1], a.i8[ 0]);
    printf("      simde_mm_set_epi8(INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd)),\n",
           b.i8[15], b.i8[14], b.i8[13], b.i8[12], b.i8[11], b.i8[10], b.i8[ 9], b.i8[ 8],
           b.i8[ 7], b.i8[ 6], b.i8[ 5], b.i8[ 4], b.i8[ 3], b.i8[ 2], b.i8[ 1], b.i8[ 0]);
    printf("      simde_mm_set_epi8(INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                        INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd)) },\n",
           r.i8[15], r.i8[14], r.i8[13], r.i8[12], r.i8[11], r.i8[10], r.i8[ 9], r.i8[ 8],
           r.i8[ 7], r.i8[ 6], r.i8[ 5], r.i8[ 4], r.i8[ 3], r.i8[ 2], r.i8[ 1], r.i8[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_xxx_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_epi16(a, b);

    printf("    { simde_mm_set_epi16(INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	   "                         INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd)),\n",
           a.i16[7], a.i16[6], a.i16[5], a.i16[4], a.i16[3], a.i16[2], a.i16[1], a.i16[0]);
    printf("      simde_mm_set_epi16(INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	   "                         INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd)),\n",
           b.i16[7], b.i16[6], b.i16[5], b.i16[4], b.i16[3], b.i16[2], b.i16[1], b.i16[0]);
    printf("      simde_mm_set_epi16(INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	   "                         INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd)) },\n",
           r.i16[7], r.i16[6], r.i16[5], r.i16[4], r.i16[3], r.i16[2], r.i16[1], r.i16[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_xxx_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_epu8(a, b);

    printf("    { simde_x_mm_set_epu8(UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                          UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                          UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                          UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu)),\n",
           a.u8[15], a.u8[14], a.u8[13], a.u8[12], a.u8[11], a.u8[10], a.u8[ 9], a.u8[ 8],
           a.u8[ 7], a.u8[ 6], a.u8[ 5], a.u8[ 4], a.u8[ 3], a.u8[ 2], a.u8[ 1], a.u8[ 0]);
    printf("      simde_x_mm_set_epu8(UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                          UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                          UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                          UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu)),\n",
           b.u8[15], b.u8[14], b.u8[13], b.u8[12], b.u8[11], b.u8[10], b.u8[ 9], b.u8[ 8],
           b.u8[ 7], b.u8[ 6], b.u8[ 5], b.u8[ 4], b.u8[ 3], b.u8[ 2], b.u8[ 1], b.u8[ 0]);
    printf("      simde_x_mm_set_epu8(UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                          UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                          UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                          UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu)) },\n",
           r.u8[15], r.u8[14], r.u8[13], r.u8[12], r.u8[11], r.u8[10], r.u8[ 9], r.u8[ 8],
           r.u8[ 7], r.u8[ 6], r.u8[ 5], r.u8[ 4], r.u8[ 3], r.u8[ 2], r.u8[ 1], r.u8[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_xxx_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_epu16(a, b);

    printf("    { simde_x_mm_set_epu16(UINT16_C(%5hu), UINT16_C(%5hu), UINT16_C(%5hu), UINT16_C(%5hu),\n"
	   "                           UINT16_C(%5hu), UINT16_C(%5hu), UINT16_C(%5hu), UINT16_C(%5hu)),\n",
           a.u16[7], a.u16[6], a.u16[5], a.u16[4], a.u16[3], a.u16[2], a.u16[1], a.u16[0]);
    printf("      simde_x_mm_set_epu16(UINT16_C(%5hu), UINT16_C(%5hu), UINT16_C(%5hu), UINT16_C(%5hu),\n"
	   "                           UINT16_C(%5hu), UINT16_C(%5hu), UINT16_C(%5hu), UINT16_C(%5hu)),\n",
           b.u16[7], b.u16[6], b.u16[5], b.u16[4], b.u16[3], b.u16[2], b.u16[1], b.u16[0]);
    printf("      simde_x_mm_set_epu16(UINT16_C(%5hu), UINT16_C(%5hu), UINT16_C(%5hu), UINT16_C(%5hu),\n"
	   "                           UINT16_C(%5hu), UINT16_C(%5hu), UINT16_C(%5hu), UINT16_C(%5hu)) },\n",
           r.u16[7], r.u16[6], r.u16[5], r.u16[4], r.u16[3], r.u16[2], r.u16[1], r.u16[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_xxx_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_epu32(a, b);

    printf("    { simde_x_mm_set_epu32(UINT32_C(%10u), UINT32_C(%10u), UINT32_C(%10u), UINT32_C(%10u)),\n",
  	   a.u32[3], a.u32[2], a.u32[1], a.u32[0]);
    printf("      simde_x_mm_set_epu32(UINT32_C(%10u), UINT32_C(%10u), UINT32_C(%10u), UINT32_C(%10u)),\n",
  	   b.u32[3], b.u32[2], b.u32[1], b.u32[0]);
    printf("      simde_x_mm_set_epu32(UINT32_C(%10u), UINT32_C(%10u), UINT32_C(%10u), UINT32_C(%10u)) },\n",
  	   r.u32[3], r.u32[2], r.u32[1], r.u32[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_xxx_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m128i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_epu64(a, b);

    printf("    { simde_mm_set_epu64x(UINT64_C(%19ld), UINT64_C(%19ld)),\n", a.u64[1], a.u64[0]);
    printf("      simde_mm_set_epu64x(UINT64_C(%19ld), UINT64_C(%19ld)),\n", b.u64[1], b.u64[0]);
    printf("      simde_mm_set_epu64x(UINT64_C(%19ld), UINT64_C(%19ld)) },\n", r.u64[1], r.u64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_xxx_epu64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_pi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_pi8(a, b);

    printf("    { simde_mm_set_pi8(INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                       INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd)),\n",
           a.i8[ 7], a.i8[ 6], a.i8[ 5], a.i8[ 4], a.i8[ 3], a.i8[ 2], a.i8[ 1], a.i8[ 0]);
    printf("      simde_mm_set_pi8(INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                       INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd)),\n",
           b.i8[ 7], b.i8[ 6], b.i8[ 5], b.i8[ 4], b.i8[ 3], b.i8[ 2], b.i8[ 1], b.i8[ 0]);
    printf("      simde_mm_set_pi8(INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
	   "                       INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd)) },\n",
           r.i8[ 7], r.i8[ 6], r.i8[ 5], r.i8[ 4], r.i8[ 3], r.i8[ 2], r.i8[ 1], r.i8[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_xxx_pi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_pi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_pi16(a, b);

    printf("    { simde_mm_set_pi16(INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd)),\n",
           a.i16[3], a.i16[2], a.i16[1], a.i16[0]);
    printf("      simde_mm_set_pi16(INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd)),\n",
           b.i16[3], b.i16[2], b.i16[1], b.i16[0]);
    printf("      simde_mm_set_pi16(INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd)) },\n",
           r.i16[3], r.i16[2], r.i16[1], r.i16[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_xxx_pi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_xxx_pi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m64 a;
    simde__m64 b;
    simde__m64 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m64 a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_pi32(a, b);

    printf("    { simde_mm_set_pi32(INT32_C(%11d), INT32_C(%11d)),\n",
  	   a.i32[1], a.i32[0]);
    printf("      simde_mm_set_pi32(INT32_C(%11d), INT32_C(%11d)),\n",
  	   b.i32[1], b.i32[0]);
    printf("      simde_mm_set_pi32(INT32_C(%11d), INT32_C(%11d)) },\n",
  	   r.i32[1], r.i32[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_xxx_pi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xxx_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m256i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm256_xxx_epi8(a, b);

    printf("    { simde_mm256_set_epi8(INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd)),\n",
           a.i8[31], a.i8[30], a.i8[29], a.i8[28], a.i8[27], a.i8[26], a.i8[25], a.i8[24],
           a.i8[23], a.i8[22], a.i8[21], a.i8[20], a.i8[19], a.i8[18], a.i8[17], a.i8[16],
           a.i8[15], a.i8[14], a.i8[13], a.i8[12], a.i8[11], a.i8[10], a.i8[ 9], a.i8[ 8],
           a.i8[ 7], a.i8[ 6], a.i8[ 5], a.i8[ 4], a.i8[ 3], a.i8[ 2], a.i8[ 1], a.i8[ 0]);
    printf("      simde_mm256_set_epi8(INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd)),\n",
           b.i8[31], b.i8[30], b.i8[29], b.i8[28], b.i8[27], b.i8[26], b.i8[25], b.i8[24],
           b.i8[23], b.i8[22], b.i8[21], b.i8[20], b.i8[19], b.i8[18], b.i8[17], b.i8[16],
           b.i8[15], b.i8[14], b.i8[13], b.i8[12], b.i8[11], b.i8[10], b.i8[ 9], b.i8[ 8],
           b.i8[ 7], b.i8[ 6], b.i8[ 5], b.i8[ 4], b.i8[ 3], b.i8[ 2], b.i8[ 1], b.i8[ 0]);
    printf("      simde_mm256_set_epi8(INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd),\n"
           "                           INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd), INT8_C(%4hhd)) },\n",
           r.i8[31], r.i8[30], r.i8[29], r.i8[28], r.i8[27], r.i8[26], r.i8[25], r.i8[24],
           r.i8[23], r.i8[22], r.i8[21], r.i8[20], r.i8[19], r.i8[18], r.i8[17], r.i8[16],
           r.i8[15], r.i8[14], r.i8[13], r.i8[12], r.i8[11], r.i8[10], r.i8[ 9], r.i8[ 8],
           r.i8[ 7], r.i8[ 6], r.i8[ 5], r.i8[ 4], r.i8[ 3], r.i8[ 2], r.i8[ 1], r.i8[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_xxx_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xxx_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m256i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm256_xxx_epi16(a, b);

    printf("    { simde_mm256_set_epi16(INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	         "                            INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	         "                            INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	         "                            INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd)),\n",
           a.i16[15], a.i16[14], a.i16[13], a.i16[12], a.i16[11], a.i16[10], a.i16[ 9], a.i16[ 8],
           a.i16[ 7], a.i16[ 6], a.i16[ 5], a.i16[ 4], a.i16[ 3], a.i16[ 2], a.i16[ 1], a.i16[ 0]);
    printf("      simde_mm256_set_epi16(INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	         "                            INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	         "                            INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	         "                            INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd)),\n",
           b.i16[15], b.i16[14], b.i16[13], b.i16[12], b.i16[11], b.i16[10], b.i16[ 9], b.i16[ 8],
           b.i16[ 7], b.i16[ 6], b.i16[ 5], b.i16[ 4], b.i16[ 3], b.i16[ 2], b.i16[ 1], b.i16[ 0]);
    printf("      simde_mm256_set_epi16(INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	         "                            INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	         "                            INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd),\n"
	         "                            INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd), INT16_C(%6hd)) },\n",
           r.i16[15], r.i16[14], r.i16[13], r.i16[12], r.i16[11], r.i16[10], r.i16[ 9], r.i16[ 8],
           r.i16[ 7], r.i16[ 6], r.i16[ 5], r.i16[ 4], r.i16[ 3], r.i16[ 2], r.i16[ 1], r.i16[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_xxx_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xxx_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m256i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm256_xxx_epi32(a, b);

    printf("    { simde_mm256_set_epi32(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d),\n"
           "                            INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)),\n",
           a.i32[7], a.i32[6], a.i32[5], a.i32[4], a.i32[3], a.i32[2], a.i32[1], a.i32[0]);
    printf("      simde_mm256_set_epi32(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d),\n"
           "                            INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)),\n",
           b.i32[7], b.i32[6], b.i32[5], b.i32[4], b.i32[3], b.i32[2], b.i32[1], b.i32[0]);
    printf("      simde_mm256_set_epi32(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d),\n"
           "                            INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)) },\n",
           r.i32[7], r.i32[6], r.i32[5], r.i32[4], r.i32[3], r.i32[2], r.i32[1], r.i32[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_xxx_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xxx_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm256_xxx_epi64(a, b);

    printf("    { simde_mm256_set_epi64x(INT64_C(%20ld), INT64_C(%20ld),\n"
           "                             INT64_C(%20ld), INT64_C(%20ld)),\n",
           a.i64[3], a.i64[2], a.i64[1], a.i64[0]);
    printf("      simde_mm256_set_epi64x(INT64_C(%20ld), INT64_C(%20ld),\n"
           "                             INT64_C(%20ld), INT64_C(%20ld)),\n",
           b.i64[3], b.i64[2], b.i64[1], b.i64[0]);
    printf("      simde_mm256_set_epi64x(INT64_C(%20ld), INT64_C(%20ld),\n"
           "                             INT64_C(%20ld), INT64_C(%20ld)) },\n",
           r.i64[3], r.i64[2], r.i64[1], r.i64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_xxx_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xxx_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m256i a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm256_xxx_epu8(a, b);

    printf("    { simde_x_mm256_set_epu8(UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
           "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu)),\n",
           a.u8[31], a.u8[30], a.u8[29], a.u8[28], a.u8[27], a.u8[26], a.u8[25], a.u8[24],
           a.u8[23], a.u8[22], a.u8[21], a.u8[20], a.u8[19], a.u8[18], a.u8[17], a.u8[16],
           a.u8[15], a.u8[14], a.u8[13], a.u8[12], a.u8[11], a.u8[10], a.u8[ 9], a.u8[ 8],
           a.u8[ 7], a.u8[ 6], a.u8[ 5], a.u8[ 4], a.u8[ 3], a.u8[ 2], a.u8[ 1], a.u8[ 0]);
    printf("      simde_x_mm256_set_epu8(UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
           "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu)),\n",
           b.u8[31], b.u8[30], b.u8[29], b.u8[28], b.u8[27], b.u8[26], b.u8[25], b.u8[24],
           b.u8[23], b.u8[22], b.u8[21], b.u8[20], b.u8[19], b.u8[18], b.u8[17], b.u8[16],
           b.u8[15], b.u8[14], b.u8[13], b.u8[12], b.u8[11], b.u8[10], b.u8[ 9], b.u8[ 8],
           b.u8[ 7], b.u8[ 6], b.u8[ 5], b.u8[ 4], b.u8[ 3], b.u8[ 2], b.u8[ 1], b.u8[ 0]);
    printf("      simde_x_mm256_set_epu8(UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
           "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu),\n"
	   "                             UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu), UINT8_C(%3hhu)) },\n",
           r.u8[31], r.u8[30], r.u8[29], r.u8[28], r.u8[27], r.u8[26], r.u8[25], r.u8[24],
           r.u8[23], r.u8[22], r.u8[21], r.u8[20], r.u8[19], r.u8[18], r.u8[17], r.u8[16],
           r.u8[15], r.u8[14], r.u8[13], r.u8[12], r.u8[11], r.u8[10], r.u8[ 9], r.u8[ 8],
           r.u8[ 7], r.u8[ 6], r.u8[ 5], r.u8[ 4], r.u8[ 3], r.u8[ 2], r.u8[ 1], r.u8[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_xxx_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xxx_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m256 a, b, r;

    for (size_t j = 0 ; j < sizeof(simde__m256) / sizeof(simde_float32) ; j++) {
      a.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
      b.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
    }

    r = simde_mm256_xxx_ps(a, b);

    printf("    { simde_mm256_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	         8, a.f32[7], 8, a.f32[6], 8, a.f32[5], 8, a.f32[4],
	         8, a.f32[3], 8, a.f32[2], 8, a.f32[1], 8, a.f32[0]);
    printf("      simde_mm256_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	         8, b.f32[7], 8, b.f32[6], 8, b.f32[5], 8, b.f32[4],
	         8, b.f32[3], 8, b.f32[2], 8, b.f32[1], 8, b.f32[0]);
    printf("      simde_mm256_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)) },\n",
	         8, r.f32[7], 8, r.f32[6], 8, r.f32[5], 8, r.f32[4],
	         8, r.f32[3], 8, r.f32[2], 8, r.f32[1], 8, r.f32[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_xxx_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_f32_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xxx_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m256d a, b, r;

    for (size_t j = 0 ; j < sizeof(simde__m256) / sizeof(simde_float64) ; j++) {
      a.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
      b.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
    }

    r = simde_mm256_xxx_pd(a, b);

    printf("    { simde_mm256_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, a.f64[3], 8, a.f64[2], 8, a.f64[1], 8, a.f64[0]);
    printf("      simde_mm256_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, b.f64[3], 8, b.f64[2], 8, b.f64[1], 8, b.f64[0]);
    printf("      simde_mm256_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n",
           8, r.f64[3], 8, r.f64[2], 8, r.f64[1], 8, r.f64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_xxx_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xxx_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m256d a, b, r;

    for (size_t j = 0 ; j < sizeof(simde__m256) / sizeof(simde_float64) ; j++) {
      a.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
      b.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
    }

    r = simde_mm_xxx_sd(a, b);

    printf("    { simde_mm256_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, a.f64[3], 8, a.f64[2], 8, a.f64[1], 8, a.f64[0]);
    printf("      simde_mm256_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, b.f64[3], 8, b.f64[2], 8, b.f64[1], 8, b.f64[0]);
    printf("      simde_mm256_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n",
           8, r.f64[3], 8, r.f64[2], 8, r.f64[1], 8, r.f64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm_xxx_sd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}
