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
    simde__m128i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m128i_to_private(simde_mm_xxx_epi8(simde__m128i_from_private(a), simde__m128i_from_private(b)));

    printf("    { simde_mm_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
           a.i8[15], a.i8[14], a.i8[13], a.i8[12], a.i8[11], a.i8[10], a.i8[ 9], a.i8[ 8],
           a.i8[ 7], a.i8[ 6], a.i8[ 5], a.i8[ 4], a.i8[ 3], a.i8[ 2], a.i8[ 1], a.i8[ 0]);
    printf("      simde_mm_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
           b.i8[15], b.i8[14], b.i8[13], b.i8[12], b.i8[11], b.i8[10], b.i8[ 9], b.i8[ 8],
           b.i8[ 7], b.i8[ 6], b.i8[ 5], b.i8[ 4], b.i8[ 3], b.i8[ 2], b.i8[ 1], b.i8[ 0]);
    printf("      simde_mm_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")) },\n",
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
    simde__m128i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m128i_to_private(simde_mm_xxx_epi16(simde__m128i_from_private(a), simde__m128i_from_private(b)));

    printf("    { simde_mm_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	   "                         INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           a.i16[7], a.i16[6], a.i16[5], a.i16[4], a.i16[3], a.i16[2], a.i16[1], a.i16[0]);
    printf("      simde_mm_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	   "                         INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           b.i16[7], b.i16[6], b.i16[5], b.i16[4], b.i16[3], b.i16[2], b.i16[1], b.i16[0]);
    printf("      simde_mm_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	   "                         INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")) },\n",
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
    simde__m128i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m128i_to_private(simde_mm_xxx_epi32(simde__m128i_from_private(a), simde__m128i_from_private(b)));

    printf("    { simde_mm_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
  	   a.i32[3], a.i32[2], a.i32[1], a.i32[0]);
    printf("      simde_mm_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
  	   b.i32[3], b.i32[2], b.i32[1], b.i32[0]);
    printf("      simde_mm_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")) },\n",
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
    simde__m128i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m128i_to_private(simde_mm_xxx_epi64(simde__m128i_from_private(a), simde__m128i_from_private(b)));

    printf("    { simde_mm_set_epi64x(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n", a.i64[1], a.i64[0]);
    printf("      simde_mm_set_epi64x(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n", b.i64[1], b.i64[0]);
    printf("      simde_mm_set_epi64x(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")) },\n", r.i64[1], r.i64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_xxx_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
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
    simde__m128_private a, b, r;

    for (size_t j = 0 ; j < sizeof(simde__m128) / sizeof(simde_float32) ; j++) {
      a.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
      b.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
    }

    r = simde__m128_to_private(simde_mm_xxx_ps(simde__m128_from_private(a), simde__m128_from_private(b)));

    printf("    { simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	   9, a.f32[3], 9, a.f32[2], 9, a.f32[1], 9, a.f32[0]);
    printf("      simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	   9, b.f32[3], 9, b.f32[2], 9, b.f32[1], 9, b.f32[0]);
    printf("      simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)) },\n",
	   9, r.f32[3], 9, r.f32[2], 9, r.f32[1], 9, r.f32[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_xxx_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_close(r, test_vec[i].r, 1);
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
    simde__m128d_private a, b, r;

    for (size_t j = 0 ; j < sizeof(simde__m128) / sizeof(simde_float64) ; j++) {
      a.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
      b.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
    }

    r = simde__m128d_to_private(simde_mm_xxx_pd(simde__m128d_from_private(a), simde__m128d_from_private(b)));

    printf("    { simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, a.f64[1], 8, a.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, b.f64[1], 8, b.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n", 8, r.f64[1], 8, r.f64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_xxx_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmpxxx_sd(const MunitParameter params[], void* data) {
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
    simde__m128d_private a, b, r;

    for (size_t j = 0 ; j < sizeof(simde__m128) / sizeof(simde_float64) ; j++) {
      a.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
      b.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
    }

    r = simde__m128d_to_private(simde_mm_cmpxxx_sd(simde__m128d_from_private(a), simde__m128d_from_private(b)));

    printf("    { simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, a.f64[1], 8, a.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, b.f64[1], 8, b.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_F64_ALL_%s) },\n", 8, r.f64[1], r.f64[0] == 0.0 ? "UNSET" : "SET");
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_xxx_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
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
    simde__m128d_private a, b, r;

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
    simde_assert_m128d_close(r, test_vec[i].r, 1);
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
    simde__m64_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm_xxx_si64(a, b);

    printf("    { simde_mm_cvtsi64_m64(INT64_C(%20" PRId64 ")),\n", a.i64[0]);
    printf("      simde_mm_cvtsi64_m64(INT64_C(%20" PRId64 ")),\n", b.i64[0]);
    printf("      simde_mm_cvtsi64_m64(INT64_C(%20" PRId64 ")), },\n", r.i64[0]);
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
    simde__m128i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m128i_to_private(simde_mm_xxx_epi8(simde__m128i_from_private(a), simde__m128i_from_private(b)));

    printf("    { simde_mm_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
           a.i8[15], a.i8[14], a.i8[13], a.i8[12], a.i8[11], a.i8[10], a.i8[ 9], a.i8[ 8],
           a.i8[ 7], a.i8[ 6], a.i8[ 5], a.i8[ 4], a.i8[ 3], a.i8[ 2], a.i8[ 1], a.i8[ 0]);
    printf("      simde_mm_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
           b.i8[15], b.i8[14], b.i8[13], b.i8[12], b.i8[11], b.i8[10], b.i8[ 9], b.i8[ 8],
           b.i8[ 7], b.i8[ 6], b.i8[ 5], b.i8[ 4], b.i8[ 3], b.i8[ 2], b.i8[ 1], b.i8[ 0]);
    printf("      simde_mm_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                        INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")) },\n",
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
    simde__m128i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m128i_to_private(simde_mm_xxx_epi16(simde__m128i_from_private(a), simde__m128i_from_private(b)));

    printf("    { simde_mm_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	   "                         INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           a.i16[7], a.i16[6], a.i16[5], a.i16[4], a.i16[3], a.i16[2], a.i16[1], a.i16[0]);
    printf("      simde_mm_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	   "                         INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           b.i16[7], b.i16[6], b.i16[5], b.i16[4], b.i16[3], b.i16[2], b.i16[1], b.i16[0]);
    printf("      simde_mm_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	   "                         INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")) },\n",
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
    simde__m128i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m128i_to_private(simde_mm_xxx_epu8(simde__m128i_from_private(a), simde__m128i_from_private(b)));

    printf("    { simde_x_mm_set_epu8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                          UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                          UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                          UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ")),\n",
           a.u8[15], a.u8[14], a.u8[13], a.u8[12], a.u8[11], a.u8[10], a.u8[ 9], a.u8[ 8],
           a.u8[ 7], a.u8[ 6], a.u8[ 5], a.u8[ 4], a.u8[ 3], a.u8[ 2], a.u8[ 1], a.u8[ 0]);
    printf("      simde_x_mm_set_epu8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                          UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                          UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                          UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ")),\n",
           b.u8[15], b.u8[14], b.u8[13], b.u8[12], b.u8[11], b.u8[10], b.u8[ 9], b.u8[ 8],
           b.u8[ 7], b.u8[ 6], b.u8[ 5], b.u8[ 4], b.u8[ 3], b.u8[ 2], b.u8[ 1], b.u8[ 0]);
    printf("      simde_x_mm_set_epu8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                          UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                          UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                          UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ")) },\n",
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
    simde__m128i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m128i_to_private(simde_mm_xxx_epu16(simde__m128i_from_private(a), simde__m128i_from_private(b)));

    printf("    { simde_x_mm_set_epu16(UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "),\n"
	   "                           UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 ")),\n",
           a.u16[7], a.u16[6], a.u16[5], a.u16[4], a.u16[3], a.u16[2], a.u16[1], a.u16[0]);
    printf("      simde_x_mm_set_epu16(UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "),\n"
	   "                           UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 ")),\n",
           b.u16[7], b.u16[6], b.u16[5], b.u16[4], b.u16[3], b.u16[2], b.u16[1], b.u16[0]);
    printf("      simde_x_mm_set_epu16(UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "),\n"
	   "                           UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 ")) },\n",
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
    simde__m128i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m128i_to_private(simde_mm_xxx_epu32(simde__m128i_from_private(a), simde__m128i_from_private(b)));

    printf("    { simde_x_mm_set_epu32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")),\n",
  	   a.u32[3], a.u32[2], a.u32[1], a.u32[0]);
    printf("      simde_x_mm_set_epu32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")),\n",
  	   b.u32[3], b.u32[2], b.u32[1], b.u32[0]);
    printf("      simde_x_mm_set_epu32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")) },\n",
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
test_simde_mm_xxx_epu64(const MunitParameter params[], void* data) {
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
    simde__m128i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m128i_to_private(simde_mm_xxx_epu64(simde__m128i_from_private(a), simde__m128i_from_private(b)));

    printf("    { simde_x_mm_set_epu64x(UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 ")),\n", a.u64[1], a.u64[0]);
    printf("      simde_x_mm_set_epu64x(UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 ")),\n", b.u64[1], b.u64[0]);
    printf("      simde_x_mm_set_epu64x(UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 ")) },\n", r.u64[1], r.u64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_xxx_epu64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_u64(r, ==, test_vec[i].r);
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
    simde__m128i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m128i_to_private(simde_mm_xxx_epi64(simde__m128i_from_private(a), simde__m128i_from_private(b)));

    printf("    { simde_mm_set_epi64x(INT64_C(%19" PRId64 "), INT64_C(%19" PRId64 ")),\n", a.i64[1], a.i64[0]);
    printf("      simde_mm_set_epi64x(INT64_C(%19" PRId64 "), INT64_C(%19" PRId64 ")),\n", b.i64[1], b.i64[0]);
    printf("      simde_mm_set_epi64x(INT64_C(%19" PRId64 "), INT64_C(%19" PRId64 ")) },\n", r.i64[1], r.i64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm_xxx_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m128i_i64(r, ==, test_vec[i].r);
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
    simde__m64_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m64_to_private(simde_mm_xxx_pi8(simde__m64_from_private(a), simde__m64_from_private(b)));

    printf("    { simde_mm_set_pi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                       INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
           a.i8[ 7], a.i8[ 6], a.i8[ 5], a.i8[ 4], a.i8[ 3], a.i8[ 2], a.i8[ 1], a.i8[ 0]);
    printf("      simde_mm_set_pi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                       INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
           b.i8[ 7], b.i8[ 6], b.i8[ 5], b.i8[ 4], b.i8[ 3], b.i8[ 2], b.i8[ 1], b.i8[ 0]);
    printf("      simde_mm_set_pi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
	   "                       INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")) },\n",
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
test_simde_mm_xxx_pu8(const MunitParameter params[], void* data) {
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
    simde__m64_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m64_to_private(simde_mm_xxx_pu8(simde__m64_from_private(a), simde__m64_from_private(b)));

    printf("    { simde_x_mm_set_pu8(UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "),\n"
	         "                         UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 ")),\n",
           a.u8[ 7], a.u8[ 6], a.u8[ 5], a.u8[ 4], a.u8[ 3], a.u8[ 2], a.u8[ 1], a.u8[ 0]);
    printf("      simde_x_mm_set_pu8(UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "),\n"
	         "                         UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 ")),\n",
           b.u8[ 7], b.u8[ 6], b.u8[ 5], b.u8[ 4], b.u8[ 3], b.u8[ 2], b.u8[ 1], b.u8[ 0]);
    printf("      simde_x_mm_set_pu8(UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "),\n"
	         "                         UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 "), UINT8_C(%4" PRIu8 ")) },\n",
           r.u8[ 7], r.u8[ 6], r.u8[ 5], r.u8[ 4], r.u8[ 3], r.u8[ 2], r.u8[ 1], r.u8[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_xxx_pu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_u8(r, ==, test_vec[i].r);
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
    simde__m64_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m64_to_private(simde_mm_xxx_pi16(simde__m64_from_private(a), simde__m64_from_private(b)));

    printf("    { simde_mm_set_pi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           a.i16[3], a.i16[2], a.i16[1], a.i16[0]);
    printf("      simde_mm_set_pi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           b.i16[3], b.i16[2], b.i16[1], b.i16[0]);
    printf("      simde_mm_set_pi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")) },\n",
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
test_simde_mm_xxx_pu16(const MunitParameter params[], void* data) {
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
    simde__m64_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m64_to_private(simde_mm_xxx_pu16(simde__m64_from_private(a), simde__m64_from_private(b)));

    printf("    { simde_x_mm_set_pu16(UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 ")),\n",
           a.u16[3], a.u16[2], a.u16[1], a.u16[0]);
    printf("      simde_x_mm_set_pu16(UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 ")),\n",
           b.u16[3], b.u16[2], b.u16[1], b.u16[0]);
    printf("      simde_x_mm_set_pu16(UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 "), UINT16_C(%5" PRIu16 ")) },\n",
           r.u16[3], r.u16[2], r.u16[1], r.u16[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m64 r = simde_mm_xxx_pu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m64_u16(r, ==, test_vec[i].r);
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
    simde__m64_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m64_to_private(simde_mm_xxx_pi32(simde__m64_from_private(a), simde__m64_from_private(b)));

    printf("    { simde_mm_set_pi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
  	   a.i32[1], a.i32[0]);
    printf("      simde_mm_set_pi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
  	   b.i32[1], b.i32[0]);
    printf("      simde_mm_set_pi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")) },\n",
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
    simde__m256i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m256i_to_private(simde_mm256_xxx_epi8(simde__m256i_from_private(a), simde__m256i_from_private(b)));

    printf("    { simde_mm256_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
           a.i8[31], a.i8[30], a.i8[29], a.i8[28], a.i8[27], a.i8[26], a.i8[25], a.i8[24],
           a.i8[23], a.i8[22], a.i8[21], a.i8[20], a.i8[19], a.i8[18], a.i8[17], a.i8[16],
           a.i8[15], a.i8[14], a.i8[13], a.i8[12], a.i8[11], a.i8[10], a.i8[ 9], a.i8[ 8],
           a.i8[ 7], a.i8[ 6], a.i8[ 5], a.i8[ 4], a.i8[ 3], a.i8[ 2], a.i8[ 1], a.i8[ 0]);
    printf("      simde_mm256_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
           b.i8[31], b.i8[30], b.i8[29], b.i8[28], b.i8[27], b.i8[26], b.i8[25], b.i8[24],
           b.i8[23], b.i8[22], b.i8[21], b.i8[20], b.i8[19], b.i8[18], b.i8[17], b.i8[16],
           b.i8[15], b.i8[14], b.i8[13], b.i8[12], b.i8[11], b.i8[10], b.i8[ 9], b.i8[ 8],
           b.i8[ 7], b.i8[ 6], b.i8[ 5], b.i8[ 4], b.i8[ 3], b.i8[ 2], b.i8[ 1], b.i8[ 0]);
    printf("      simde_mm256_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")) },\n",
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
    simde__m256i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m256i_to_private(simde_mm256_xxx_epi16(simde__m256i_from_private(a), simde__m256i_from_private(b)));

    printf("    { simde_mm256_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           a.i16[15], a.i16[14], a.i16[13], a.i16[12], a.i16[11], a.i16[10], a.i16[ 9], a.i16[ 8],
           a.i16[ 7], a.i16[ 6], a.i16[ 5], a.i16[ 4], a.i16[ 3], a.i16[ 2], a.i16[ 1], a.i16[ 0]);
    printf("      simde_mm256_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           b.i16[15], b.i16[14], b.i16[13], b.i16[12], b.i16[11], b.i16[10], b.i16[ 9], b.i16[ 8],
           b.i16[ 7], b.i16[ 6], b.i16[ 5], b.i16[ 4], b.i16[ 3], b.i16[ 2], b.i16[ 1], b.i16[ 0]);
    printf("      simde_mm256_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")) },\n",
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
    simde__m256i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m256i_to_private(simde_mm256_xxx_epi32(simde__m256i_from_private(a), simde__m256i_from_private(b)));

    printf("    { simde_mm256_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           a.i32[7], a.i32[6], a.i32[5], a.i32[4], a.i32[3], a.i32[2], a.i32[1], a.i32[0]);
    printf("      simde_mm256_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           b.i32[7], b.i32[6], b.i32[5], b.i32[4], b.i32[3], b.i32[2], b.i32[1], b.i32[0]);
    printf("      simde_mm256_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")) },\n",
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
    simde__m256i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m256i_to_private(simde_mm256_xxx_epi64(simde__m256i_from_private(a), simde__m256i_from_private(b)));

    printf("    { simde_mm256_set_epi64x(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                             INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n",
           a.i64[3], a.i64[2], a.i64[1], a.i64[0]);
    printf("      simde_mm256_set_epi64x(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                             INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n",
           b.i64[3], b.i64[2], b.i64[1], b.i64[0]);
    printf("      simde_mm256_set_epi64x(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                             INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")) },\n",
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
    simde__m256i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m256i_to_private(simde_mm256_xxx_epu8(simde__m256i_from_private(a), simde__m256i_from_private(b)));

    printf("    { simde_x_mm256_set_epu8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ")),\n",
           a.u8[31], a.u8[30], a.u8[29], a.u8[28], a.u8[27], a.u8[26], a.u8[25], a.u8[24],
           a.u8[23], a.u8[22], a.u8[21], a.u8[20], a.u8[19], a.u8[18], a.u8[17], a.u8[16],
           a.u8[15], a.u8[14], a.u8[13], a.u8[12], a.u8[11], a.u8[10], a.u8[ 9], a.u8[ 8],
           a.u8[ 7], a.u8[ 6], a.u8[ 5], a.u8[ 4], a.u8[ 3], a.u8[ 2], a.u8[ 1], a.u8[ 0]);
    printf("      simde_x_mm256_set_epu8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ")),\n",
           b.u8[31], b.u8[30], b.u8[29], b.u8[28], b.u8[27], b.u8[26], b.u8[25], b.u8[24],
           b.u8[23], b.u8[22], b.u8[21], b.u8[20], b.u8[19], b.u8[18], b.u8[17], b.u8[16],
           b.u8[15], b.u8[14], b.u8[13], b.u8[12], b.u8[11], b.u8[10], b.u8[ 9], b.u8[ 8],
           b.u8[ 7], b.u8[ 6], b.u8[ 5], b.u8[ 4], b.u8[ 3], b.u8[ 2], b.u8[ 1], b.u8[ 0]);
    printf("      simde_x_mm256_set_epu8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
	   "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ")) },\n",
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
test_simde_mm256_xxx_epu16(const MunitParameter params[], void* data) {
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
    simde__m256i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m256i_to_private(simde_mm256_xxx_epu16(simde__m256i_from_private(a), simde__m256i_from_private(b)));

    printf("    { simde_x_mm256_set_epu16(UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 ")),\n",
           a.u16[15], a.u16[14], a.u16[13], a.u16[12], a.u16[11], a.u16[10], a.u16[ 9], a.u16[ 8],
           a.u16[ 7], a.u16[ 6], a.u16[ 5], a.u16[ 4], a.u16[ 3], a.u16[ 2], a.u16[ 1], a.u16[ 0]);
    printf("      simde_x_mm256_set_epu16(UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 ")),\n",
           b.u16[15], b.u16[14], b.u16[13], b.u16[12], b.u16[11], b.u16[10], b.u16[ 9], b.u16[ 8],
           b.u16[ 7], b.u16[ 6], b.u16[ 5], b.u16[ 4], b.u16[ 3], b.u16[ 2], b.u16[ 1], b.u16[ 0]);
    printf("      simde_x_mm256_set_epu16(UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 ")) },\n",
           r.u16[15], r.u16[14], r.u16[13], r.u16[12], r.u16[11], r.u16[10], r.u16[ 9], r.u16[ 8],
           r.u16[ 7], r.u16[ 6], r.u16[ 5], r.u16[ 4], r.u16[ 3], r.u16[ 2], r.u16[ 1], r.u16[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_xxx_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xxx_epu32(const MunitParameter params[], void* data) {
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
    simde__m256i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m256i_to_private(simde_mm256_xxx_epu32(simde__m256i_from_private(a), simde__m256i_from_private(b)));

    printf("    { simde_x_mm256_set_epu32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")),\n",
           a.u32[7], a.u32[6], a.u32[5], a.u32[4], a.u32[3], a.u32[2], a.u32[1], a.u32[0]);
    printf("      simde_x_mm256_set_epu32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")),\n",
           b.u32[7], b.u32[6], b.u32[5], b.u32[4], b.u32[3], b.u32[2], b.u32[1], b.u32[0]);
    printf("      simde_x_mm256_set_epu32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")) },\n",
           r.u32[7], r.u32[6], r.u32[5], r.u32[4], r.u32[3], r.u32[2], r.u32[1], r.u32[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_xxx_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xxx_epu64(const MunitParameter params[], void* data) {
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
    simde__m256i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m256i_to_private(simde_mm256_xxx_epi64(simde__m256i_from_private(a), simde__m256i_from_private(b)));

    printf("    { simde_x_mm256_set_epu64x(UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 "),\n"
           "                               UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 ")) },\n",
           a.u64[3], a.u64[2], a.u64[1], a.u64[0]);
    printf("      simde_x_mm256_set_epu64x(UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 "),\n"
           "                               UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 ")),\n",
           b.u64[3], b.u64[2], b.u64[1], b.u64[0]);
    printf("      simde_x_mm256_set_epu64x(UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 "),\n"
           "                               UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 ")) },\n",
           r.u64[3], r.u64[2], r.u64[1], r.u64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_xxx_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
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
    simde__m256_private a, b, r;

    for (size_t j = 0 ; j < sizeof(simde__m256) / sizeof(simde_float32) ; j++) {
      a.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
      b.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
    }

    r = simde__m256_to_private(simde_mm256_xxx_ps(simde__m256_from_private(a), simde__m256_from_private(b)));

    printf("    { simde_mm256_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	         9, a.f32[7], 9, a.f32[6], 9, a.f32[5], 9, a.f32[4],
	         9, a.f32[3], 9, a.f32[2], 9, a.f32[1], 9, a.f32[0]);
    printf("      simde_mm256_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	         9, b.f32[7], 9, b.f32[6], 9, b.f32[5], 9, b.f32[4],
	         9, b.f32[3], 9, b.f32[2], 9, b.f32[1], 9, b.f32[0]);
    printf("      simde_mm256_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)) },\n",
	         9, r.f32[7], 9, r.f32[6], 9, r.f32[5], 9, r.f32[4],
	         9, r.f32[3], 9, r.f32[2], 9, r.f32[1], 9, r.f32[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_xxx_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
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
    simde__m256d_private a, b, r;

    for (size_t j = 0 ; j < sizeof(simde__m256d) / sizeof(simde_float64) ; j++) {
      a.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
      b.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
    }

    r = simde__m256d_to_private(simde_mm256_xxx_pd(simde__m256d_from_private(a), simde__m256d_from_private(b)));

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
    simde_assert_m256d_close(r, test_vec[i].r, 1);
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
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_x3x_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128d a, b, c, r;

    for (size_t j = 0 ; j < sizeof(simde__m128) / sizeof(simde_float64) ; j++) {
      a.f64[j] = round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0;
      b.f64[j] = round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0;
      c.f64[j] = round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0;
    }

    r = simde_mm_x3x_pd(a, b, c);

    printf("    { simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, a.f64[1], 8, a.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, b.f64[1], 8, b.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, c.f64[1], 8, c.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n", 8, r.f64[1], 8, r.f64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_x3x_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_x3x_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d c;
    simde__m256d r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m256d a, b, c, r;

    for (size_t j = 0 ; j < sizeof(simde__m256d) / sizeof(simde_float64) ; j++) {
      a.f64[j] = round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0;
      b.f64[j] = round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0;
      c.f64[j] = round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0;
    }

    r = simde_mm256_x3x_pd(a, b, c);

    printf("    { simde_mm256_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, a.f64[3], 8, a.f64[2], 8, a.f64[1], 8, a.f64[0]);
    printf("      simde_mm256_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, b.f64[3], 8, b.f64[2], 8, b.f64[1], 8, b.f64[0]);
    printf("      simde_mm256_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, c.f64[3], 8, c.f64[2], 8, c.f64[1], 8, c.f64[0]);
    printf("      simde_mm256_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n",
           8, r.f64[3], 8, r.f64[2], 8, r.f64[1], 8, r.f64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_x3x_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_x3x_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 a, b, c, r;

    for (size_t j = 0 ; j < sizeof(simde__m128) / sizeof(simde_float32) ; j++) {
      a.f32[j] = (simde_float32) (round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0);
      b.f32[j] = (simde_float32) (round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0);
      c.f32[j] = (simde_float32) (round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0);
    }

    r = simde_mm_x3x_ps(a, b, c);

    printf("    { simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	   9, a.f32[3], 9, a.f32[2], 9, a.f32[1], 9, a.f32[0]);
    printf("      simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	   9, b.f32[3], 9, b.f32[2], 9, b.f32[1], 9, b.f32[0]);
    printf("      simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	   9, c.f32[3], 9, c.f32[2], 9, c.f32[1], 9, c.f32[0]);
    printf("      simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)) },\n",
	   9, r.f32[3], 9, r.f32[2], 9, r.f32[1], 9, r.f32[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_x3x_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_x3x_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 c;
    simde__m256 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m256 a, b, c, r;

    for (size_t j = 0 ; j < sizeof(simde__m256) / sizeof(simde_float32) ; j++) {
      a.f32[j] = (simde_float32) (round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0);
      b.f32[j] = (simde_float32) (round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0);
      c.f32[j] = (simde_float32) (round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0);
    }

    r = simde_mm256_x3x_ps(a, b, c);

    printf("    { simde_mm256_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	         9, a.f32[7], 9, a.f32[6], 9, a.f32[5], 9, a.f32[4],
	         9, a.f32[3], 9, a.f32[2], 9, a.f32[1], 9, a.f32[0]);
    printf("      simde_mm256_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	         9, b.f32[7], 9, b.f32[6], 9, b.f32[5], 9, b.f32[4],
	         9, b.f32[3], 9, b.f32[2], 9, b.f32[1], 9, b.f32[0]);
    printf("      simde_mm256_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	         9, c.f32[7], 9, c.f32[6], 9, c.f32[5], 9, c.f32[4],
	         9, c.f32[3], 9, c.f32[2], 9, c.f32[1], 9, c.f32[0]);
    printf("      simde_mm256_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)) },\n",
	         9, r.f32[7], 9, r.f32[6], 9, r.f32[5], 9, r.f32[4],
	         9, r.f32[3], 9, r.f32[2], 9, r.f32[1], 9, r.f32[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_x3x_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_x3x_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128d a, b, c, r;

    for (size_t j = 0 ; j < sizeof(simde__m128) / sizeof(simde_float64) ; j++) {
      a.f64[j] = round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0;
      b.f64[j] = round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0;
      c.f64[j] = round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0;
    }

    r = simde_mm_x3x_sd(a, b, c);

    printf("    { simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, a.f64[1], 8, a.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, b.f64[1], 8, b.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n", 8, c.f64[1], 8, c.f64[0]);
    printf("      simde_mm_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n", 8, r.f64[1], 8, r.f64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_x3x_sd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_x3x_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m128 a, b, c, r;

    for (size_t j = 0 ; j < sizeof(simde__m128) / sizeof(simde_float32) ; j++) {
      a.f32[j] = (simde_float32) (round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0);
      b.f32[j] = (simde_float32) (round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0);
      c.f32[j] = (simde_float32) (round(random_f64_range(-100.0, 100.0) * 10.0) / 10.0);
    }

    r = simde_mm_x3x_ss(a, b, c);

    printf("    { simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	   9, a.f32[3], 9, a.f32[2], 9, a.f32[1], 9, a.f32[0]);
    printf("      simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	   9, b.f32[3], 9, b.f32[2], 9, b.f32[1], 9, b.f32[0]);
    printf("      simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	   9, c.f32[3], 9, c.f32[2], 9, c.f32[1], 9, c.f32[0]);
    printf("      simde_mm_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)) },\n",
	   9, r.f32[3], 9, r.f32[2], 9, r.f32[1], 9, r.f32[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_x3x_ss(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_xxx_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m512i_to_private(simde_mm512_xxx_epi8(simde__m512i_from_private(a), simde__m512i_from_private(b)));

    printf("    { simde_mm512_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
           a.i8[63], a.i8[62], a.i8[61], a.i8[60], a.i8[59], a.i8[58], a.i8[57], a.i8[56],
           a.i8[55], a.i8[54], a.i8[53], a.i8[52], a.i8[51], a.i8[50], a.i8[49], a.i8[48],
           a.i8[47], a.i8[46], a.i8[45], a.i8[44], a.i8[43], a.i8[42], a.i8[41], a.i8[40],
           a.i8[39], a.i8[38], a.i8[37], a.i8[36], a.i8[35], a.i8[34], a.i8[33], a.i8[32],
           a.i8[31], a.i8[30], a.i8[29], a.i8[28], a.i8[27], a.i8[26], a.i8[25], a.i8[24],
           a.i8[23], a.i8[22], a.i8[21], a.i8[20], a.i8[19], a.i8[18], a.i8[17], a.i8[16],
           a.i8[15], a.i8[14], a.i8[13], a.i8[12], a.i8[11], a.i8[10], a.i8[ 9], a.i8[ 8],
           a.i8[ 7], a.i8[ 6], a.i8[ 5], a.i8[ 4], a.i8[ 3], a.i8[ 2], a.i8[ 1], a.i8[ 0]);
    printf("      simde_mm512_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")),\n",
           b.i8[63], b.i8[62], b.i8[61], b.i8[60], b.i8[59], b.i8[58], b.i8[57], b.i8[56],
           b.i8[55], b.i8[54], b.i8[53], b.i8[52], b.i8[51], b.i8[50], b.i8[49], b.i8[48],
           b.i8[47], b.i8[46], b.i8[45], b.i8[44], b.i8[43], b.i8[42], b.i8[41], b.i8[40],
           b.i8[39], b.i8[38], b.i8[37], b.i8[36], b.i8[35], b.i8[34], b.i8[33], b.i8[32],
           b.i8[31], b.i8[30], b.i8[29], b.i8[28], b.i8[27], b.i8[26], b.i8[25], b.i8[24],
           b.i8[23], b.i8[22], b.i8[21], b.i8[20], b.i8[19], b.i8[18], b.i8[17], b.i8[16],
           b.i8[15], b.i8[14], b.i8[13], b.i8[12], b.i8[11], b.i8[10], b.i8[ 9], b.i8[ 8],
           b.i8[ 7], b.i8[ 6], b.i8[ 5], b.i8[ 4], b.i8[ 3], b.i8[ 2], b.i8[ 1], b.i8[ 0]);
    printf("      simde_mm512_set_epi8(INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "),\n"
           "                           INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 "), INT8_C(%4" PRId8 ")) },\n",
           r.i8[63], r.i8[62], r.i8[61], r.i8[60], r.i8[59], r.i8[58], r.i8[57], r.i8[56],
           r.i8[55], r.i8[54], r.i8[53], r.i8[52], r.i8[51], r.i8[50], r.i8[49], r.i8[48],
           r.i8[47], r.i8[46], r.i8[45], r.i8[44], r.i8[43], r.i8[42], r.i8[41], r.i8[40],
           r.i8[39], r.i8[38], r.i8[37], r.i8[36], r.i8[35], r.i8[34], r.i8[33], r.i8[32],
           r.i8[31], r.i8[30], r.i8[29], r.i8[28], r.i8[27], r.i8[26], r.i8[25], r.i8[24],
           r.i8[23], r.i8[22], r.i8[21], r.i8[20], r.i8[19], r.i8[18], r.i8[17], r.i8[16],
           r.i8[15], r.i8[14], r.i8[13], r.i8[12], r.i8[11], r.i8[10], r.i8[ 9], r.i8[ 8],
           r.i8[ 7], r.i8[ 6], r.i8[ 5], r.i8[ 4], r.i8[ 3], r.i8[ 2], r.i8[ 1], r.i8[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_xxx_epi8(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_xxx_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m512i_to_private(simde_mm512_xxx_epi16(simde__m512i_from_private(a), simde__m512i_from_private(b)));

    printf("    { simde_mm512_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           a.i16[31], a.i16[30], a.i16[29], a.i16[28], a.i16[27], a.i16[26], a.i16[25], a.i16[24],
           a.i16[23], a.i16[22], a.i16[21], a.i16[20], a.i16[19], a.i16[18], a.i16[17], a.i16[16],
           a.i16[15], a.i16[14], a.i16[13], a.i16[12], a.i16[11], a.i16[10], a.i16[ 9], a.i16[ 8],
           a.i16[ 7], a.i16[ 6], a.i16[ 5], a.i16[ 4], a.i16[ 3], a.i16[ 2], a.i16[ 1], a.i16[ 0]);
    printf("      simde_mm512_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")),\n",
           b.i16[31], b.i16[30], b.i16[29], b.i16[28], b.i16[27], b.i16[26], b.i16[25], b.i16[24],
           b.i16[23], b.i16[22], b.i16[21], b.i16[20], b.i16[19], b.i16[18], b.i16[17], b.i16[16],
           b.i16[15], b.i16[14], b.i16[13], b.i16[12], b.i16[11], b.i16[10], b.i16[ 9], b.i16[ 8],
           b.i16[ 7], b.i16[ 6], b.i16[ 5], b.i16[ 4], b.i16[ 3], b.i16[ 2], b.i16[ 1], b.i16[ 0]);
    printf("      simde_mm512_set_epi16(INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "),\n"
	         "                            INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 "), INT16_C(%6" PRId16 ")) },\n",
           r.i16[31], r.i16[30], r.i16[29], r.i16[28], r.i16[27], r.i16[26], r.i16[25], r.i16[24],
           r.i16[23], r.i16[22], r.i16[21], r.i16[20], r.i16[19], r.i16[18], r.i16[17], r.i16[16],
           r.i16[15], r.i16[14], r.i16[13], r.i16[12], r.i16[11], r.i16[10], r.i16[ 9], r.i16[ 8],
           r.i16[ 7], r.i16[ 6], r.i16[ 5], r.i16[ 4], r.i16[ 3], r.i16[ 2], r.i16[ 1], r.i16[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_xxx_epi16(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_xxx_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m512i_to_private(simde_mm512_xxx_epi32(simde__m512i_from_private(a), simde__m512i_from_private(b)));

    printf("    { simde_mm512_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           a.i32[15], a.i32[14], a.i32[13], a.i32[12], a.i32[11], a.i32[10], a.i32[ 9], a.i32[ 8],
           a.i32[ 7], a.i32[ 6], a.i32[ 5], a.i32[ 4], a.i32[ 3], a.i32[ 2], a.i32[ 1], a.i32[ 0]);
    printf("      simde_mm512_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           b.i32[15], b.i32[14], b.i32[13], b.i32[12], b.i32[11], b.i32[10], b.i32[ 9], b.i32[ 8],
           b.i32[ 7], b.i32[ 6], b.i32[ 5], b.i32[ 4], b.i32[ 3], b.i32[ 2], b.i32[ 1], b.i32[ 0]);
    printf("      simde_mm512_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")) },\n",
           r.i32[15], r.i32[14], r.i32[13], r.i32[12], r.i32[11], r.i32[10], r.i32[ 9], r.i32[ 8],
           r.i32[ 7], r.i32[ 6], r.i32[ 5], r.i32[ 4], r.i32[ 3], r.i32[ 2], r.i32[ 1], r.i32[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_xxx_epi32(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_xxx_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i src;
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512i_private src, a, b, r;
    simde__mmask16 k;

    munit_rand_memory(sizeof(src), (uint8_t*) &src);
    munit_rand_memory(sizeof(k), (uint8_t*) &k);
    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(a), (uint8_t*) &b);
    k &= UINT16_C(0xffff);

    r = simde__m512i_to_private(simde_mm512_mask_xxx_epi32(simde__m512i_from_private(src), k, simde__m512i_from_private(a), simde__m512i_from_private(b)));

    printf("    { simde_mm512_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           src.i32[15], src.i32[14], src.i32[13], src.i32[12], src.i32[11], src.i32[10], src.i32[ 9], src.i32[ 8],
           src.i32[ 7], src.i32[ 6], src.i32[ 5], src.i32[ 4], src.i32[ 3], src.i32[ 2], src.i32[ 1], src.i32[ 0]);
    printf("      UINT16_C(%5" PRIu16 "),\n", HEDLEY_STATIC_CAST(uint16_t, k));
    printf("      simde_mm512_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           a.i32[15], a.i32[14], a.i32[13], a.i32[12], a.i32[11], a.i32[10], a.i32[ 9], a.i32[ 8],
           a.i32[ 7], a.i32[ 6], a.i32[ 5], a.i32[ 4], a.i32[ 3], a.i32[ 2], a.i32[ 1], a.i32[ 0]);
    printf("      simde_mm512_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           b.i32[15], b.i32[14], b.i32[13], b.i32[12], b.i32[11], b.i32[10], b.i32[ 9], b.i32[ 8],
           b.i32[ 7], b.i32[ 6], b.i32[ 5], b.i32[ 4], b.i32[ 3], b.i32[ 2], b.i32[ 1], b.i32[ 0]);
    printf("      simde_mm512_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")) },\n",
           r.i32[15], r.i32[14], r.i32[13], r.i32[12], r.i32[11], r.i32[10], r.i32[ 9], r.i32[ 8],
           r.i32[ 7], r.i32[ 6], r.i32[ 5], r.i32[ 4], r.i32[ 3], r.i32[ 2], r.i32[ 1], r.i32[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_xxx_epi32(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_xxx_epi32_mask(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__mmask16 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512i_private a, b;
    simde__mmask16 k, r;

    k = (simde__mmask16) munit_rand_int_range(0, UINT16_MAX);
    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm512_mask_xxx_epi32_mask(k, simde__m512i_from_private(a), simde__m512i_from_private(b));

    printf("    { UINT16_C(%5" PRIu16 "),\n", k);
    printf("      simde_mm512_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           a.i32[15], a.i32[14], a.i32[13], a.i32[12], a.i32[11], a.i32[10], a.i32[ 9], a.i32[ 8],
           a.i32[ 7], a.i32[ 6], a.i32[ 5], a.i32[ 4], a.i32[ 3], a.i32[ 2], a.i32[ 1], a.i32[ 0]);
    printf("      simde_mm512_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           b.i32[15], b.i32[14], b.i32[13], b.i32[12], b.i32[11], b.i32[10], b.i32[ 9], b.i32[ 8],
           b.i32[ 7], b.i32[ 6], b.i32[ 5], b.i32[ 4], b.i32[ 3], b.i32[ 2], b.i32[ 1], b.i32[ 0]);
    printf("      UINT16_C(%5" PRIu16 ") },\n", r);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask16 r = simde_mm512_mask_xxx_epi32_mask(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_mmask16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_xxx_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m512i_to_private(simde_mm512_xxx_epi64(simde__m512i_from_private(a), simde__m512i_from_private(b)));

    printf("    { simde_mm512_set_epi64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n",
           a.i64[7], a.i64[6], a.i64[5], a.i64[4],
           a.i64[3], a.i64[2], a.i64[1], a.i64[0]);
    printf("      simde_mm512_set_epi64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n",
           b.i64[7], b.i64[6], b.i64[5], b.i64[4],
           b.i64[3], b.i64[2], b.i64[1], b.i64[0]);
    printf("      simde_mm512_set_epi64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")) },\n",
           r.i64[7], r.i64[6], r.i64[5], r.i64[4],
           r.i64[3], r.i64[2], r.i64[1], r.i64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_xxx_epi64(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_xxx_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i src;
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512i_private src, a, b, r;
    simde__mmask8 k;

    munit_rand_memory(sizeof(src), (uint8_t*) &src);
    munit_rand_memory(sizeof(k), (uint8_t*) &k);
    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(a), (uint8_t*) &b);
    k &= UINT8_C(0xff);

    r = simde__m512i_to_private(simde_mm512_mask_xxx_epi64(simde__m512i_from_private(src), k, simde__m512i_from_private(a), simde__m512i_from_private(b)));

    printf("    { simde_mm512_set_epi64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n",
           src.i64[7], src.i64[6], src.i64[5], src.i64[4],
           src.i64[3], src.i64[2], src.i64[1], src.i64[0]);
    printf("      UINT8_C(%3" PRIu8 "),\n", HEDLEY_STATIC_CAST(uint8_t, k));
    printf("      simde_mm512_set_epi64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n",
           a.i64[7], a.i64[6], a.i64[5], a.i64[4],
           a.i64[3], a.i64[2], a.i64[1], a.i64[0]);
    printf("      simde_mm512_set_epi64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n",
           b.i64[7], b.i64[6], b.i64[5], b.i64[4],
           b.i64[3], b.i64[2], b.i64[1], b.i64[0]);
    printf("      simde_mm512_set_epi64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")) },\n",
           r.i64[7], r.i64[6], r.i64[5], r.i64[4],
           r.i64[3], r.i64[2], r.i64[1], r.i64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_xxx_epi64(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_xxx_epi64_mask(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i b;
    simde__mmask8 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512i_private a, b;
    simde__mmask8 k, r;

    k = (simde__mmask8) munit_rand_int_range(0, UINT8_MAX);
    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_mm512_mask_xxx_epi64_mask(k, simde__m512i_from_private(a), simde__m512i_from_private(b));

    printf("    { UINT8_C(%3" PRIu8 "),\n", k);
    printf("      simde_mm512_set_epi64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n",
           a.i64[7], a.i64[6], a.i64[5], a.i64[4],
           a.i64[3], a.i64[2], a.i64[1], a.i64[0]);
    printf("      simde_mm512_set_epi64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n",
           b.i64[7], b.i64[6], b.i64[5], b.i64[4],
           b.i64[3], b.i64[2], b.i64[1], b.i64[0]);
    printf("      UINT8_C(%3" PRIu8 ") },\n", r);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__mmask8 r = simde_mm512_mask_xxx_epi64_mask(test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_mmask8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_xxx_epu8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m512i_to_private(simde_mm512_xxx_epu8(simde__m512i_from_private(a), simde__m512i_from_private(b)));

    printf("    { simde_x_mm512_set_epu8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ")),\n",
           a.u8[63], a.u8[62], a.u8[61], a.u8[60], a.u8[59], a.u8[58], a.u8[57], a.u8[56],
           a.u8[55], a.u8[54], a.u8[53], a.u8[52], a.u8[51], a.u8[50], a.u8[49], a.u8[48],
           a.u8[47], a.u8[46], a.u8[45], a.u8[44], a.u8[43], a.u8[42], a.u8[41], a.u8[40],
           a.u8[39], a.u8[38], a.u8[37], a.u8[36], a.u8[35], a.u8[34], a.u8[33], a.u8[32],
           a.u8[31], a.u8[30], a.u8[29], a.u8[28], a.u8[27], a.u8[26], a.u8[25], a.u8[24],
           a.u8[23], a.u8[22], a.u8[21], a.u8[20], a.u8[19], a.u8[18], a.u8[17], a.u8[16],
           a.u8[15], a.u8[14], a.u8[13], a.u8[12], a.u8[11], a.u8[10], a.u8[ 9], a.u8[ 8],
           a.u8[ 7], a.u8[ 6], a.u8[ 5], a.u8[ 4], a.u8[ 3], a.u8[ 2], a.u8[ 1], a.u8[ 0]);
    printf("      simde_x_mm512_set_epu8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ")),\n",
           b.u8[63], b.u8[62], b.u8[61], b.u8[60], b.u8[59], b.u8[58], b.u8[57], b.u8[56],
           b.u8[55], b.u8[54], b.u8[53], b.u8[52], b.u8[51], b.u8[50], b.u8[49], b.u8[48],
           b.u8[47], b.u8[46], b.u8[45], b.u8[44], b.u8[43], b.u8[42], b.u8[41], b.u8[40],
           b.u8[39], b.u8[38], b.u8[37], b.u8[36], b.u8[35], b.u8[34], b.u8[33], b.u8[32],
           b.u8[31], b.u8[30], b.u8[29], b.u8[28], b.u8[27], b.u8[26], b.u8[25], b.u8[24],
           b.u8[23], b.u8[22], b.u8[21], b.u8[20], b.u8[19], b.u8[18], b.u8[17], b.u8[16],
           b.u8[15], b.u8[14], b.u8[13], b.u8[12], b.u8[11], b.u8[10], b.u8[ 9], b.u8[ 8],
           b.u8[ 7], b.u8[ 6], b.u8[ 5], b.u8[ 4], b.u8[ 3], b.u8[ 2], b.u8[ 1], b.u8[ 0]);
    printf("      simde_x_mm512_set_epu8(UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "),\n"
           "                             UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 "), UINT8_C(%3" PRIu8 ")) },\n",
           r.u8[63], r.u8[62], r.u8[61], r.u8[60], r.u8[59], r.u8[58], r.u8[57], r.u8[56],
           r.u8[55], r.u8[54], r.u8[53], r.u8[52], r.u8[51], r.u8[50], r.u8[49], r.u8[48],
           r.u8[47], r.u8[46], r.u8[45], r.u8[44], r.u8[43], r.u8[42], r.u8[41], r.u8[40],
           r.u8[39], r.u8[38], r.u8[37], r.u8[36], r.u8[35], r.u8[34], r.u8[33], r.u8[32],
           r.u8[31], r.u8[30], r.u8[29], r.u8[28], r.u8[27], r.u8[26], r.u8[25], r.u8[24],
           r.u8[23], r.u8[22], r.u8[21], r.u8[20], r.u8[19], r.u8[18], r.u8[17], r.u8[16],
           r.u8[15], r.u8[14], r.u8[13], r.u8[12], r.u8[11], r.u8[10], r.u8[ 9], r.u8[ 8],
           r.u8[ 7], r.u8[ 6], r.u8[ 5], r.u8[ 4], r.u8[ 3], r.u8[ 2], r.u8[ 1], r.u8[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_xxx_epu8(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_xxx_epu16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m512i_to_private(simde_mm512_xxx_epu16(simde__m512i_from_private(a), simde__m512i_from_private(b)));

    printf("    { simde_x_mm512_set_epu16(UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 ")),\n",
           a.u16[31], a.u16[30], a.u16[29], a.u16[28], a.u16[27], a.u16[26], a.u16[25], a.u16[24],
           a.u16[23], a.u16[22], a.u16[21], a.u16[20], a.u16[19], a.u16[18], a.u16[17], a.u16[16],
           a.u16[15], a.u16[14], a.u16[13], a.u16[12], a.u16[11], a.u16[10], a.u16[ 9], a.u16[ 8],
           a.u16[ 7], a.u16[ 6], a.u16[ 5], a.u16[ 4], a.u16[ 3], a.u16[ 2], a.u16[ 1], a.u16[ 0]);
    printf("      simde_x_mm512_set_epu16(UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 ")),\n",
           b.u16[31], b.u16[30], b.u16[29], b.u16[28], b.u16[27], b.u16[26], b.u16[25], b.u16[24],
           b.u16[23], b.u16[22], b.u16[21], b.u16[20], b.u16[19], b.u16[18], b.u16[17], b.u16[16],
           b.u16[15], b.u16[14], b.u16[13], b.u16[12], b.u16[11], b.u16[10], b.u16[ 9], b.u16[ 8],
           b.u16[ 7], b.u16[ 6], b.u16[ 5], b.u16[ 4], b.u16[ 3], b.u16[ 2], b.u16[ 1], b.u16[ 0]);
    printf("      simde_x_mm512_set_epu16(UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "),\n"
	         "                              UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 "), UINT16_C(%6" PRIu16 ")) },\n",
           r.u16[31], r.u16[30], r.u16[29], r.u16[28], r.u16[27], r.u16[26], r.u16[25], r.u16[24],
           r.u16[23], r.u16[22], r.u16[21], r.u16[20], r.u16[19], r.u16[18], r.u16[17], r.u16[16],
           r.u16[15], r.u16[14], r.u16[13], r.u16[12], r.u16[11], r.u16[10], r.u16[ 9], r.u16[ 8],
           r.u16[ 7], r.u16[ 6], r.u16[ 5], r.u16[ 4], r.u16[ 3], r.u16[ 2], r.u16[ 1], r.u16[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_xxx_epu16(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_xxx_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m512i_to_private(simde_mm512_xxx_epu32(simde__m512i_from_private(a), simde__m512i_from_private(b)));

    printf("    { simde_x_mm512_set_epu32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")),\n",
           a.u32[15], a.u32[14], a.u32[13], a.u32[12], a.u32[11], a.u32[10], a.u32[ 9], a.u32[ 8],
           a.u32[ 7], a.u32[ 6], a.u32[ 5], a.u32[ 4], a.u32[ 3], a.u32[ 2], a.u32[ 1], a.u32[ 0]);
    printf("      simde_x_mm512_set_epu32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")),\n",
           b.u32[15], b.u32[14], b.u32[13], b.u32[12], b.u32[11], b.u32[10], b.u32[ 9], b.u32[ 8],
           b.u32[ 7], b.u32[ 6], b.u32[ 5], b.u32[ 4], b.u32[ 3], b.u32[ 2], b.u32[ 1], b.u32[ 0]);
    printf("      simde_x_mm512_set_epu32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")) },\n",
           r.u32[15], r.u32[14], r.u32[13], r.u32[12], r.u32[11], r.u32[10], r.u32[ 9], r.u32[ 8],
           r.u32[ 7], r.u32[ 6], r.u32[ 5], r.u32[ 4], r.u32[ 3], r.u32[ 2], r.u32[ 1], r.u32[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_xxx_epu32(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_xxx_epu32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i src;
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512i_private src, a, b, r;
    simde__mmask16 k;

    munit_rand_memory(sizeof(src), (uint8_t*) &src);
    munit_rand_memory(sizeof(k), (uint8_t*) &k);
    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(a), (uint8_t*) &b);
    k &= UINT16_C(0xffff);

    r = simde__m512i_to_private(simde_mm512_mask_xxx_epu32(simde__m512i_from_private(src), k, simde__m512i_from_private(a), simde__m512i_from_private(b)));

    printf("    { simde_x_mm512_set_epu32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")),\n",
           src.u32[15], src.u32[14], src.u32[13], src.u32[12], src.u32[11], src.u32[10], src.u32[ 9], src.u32[ 8],
           src.u32[ 7], src.u32[ 6], src.u32[ 5], src.u32[ 4], src.u32[ 3], src.u32[ 2], src.u32[ 1], src.u32[ 0]);
    printf("      UINT16_C(%5" PRIu16 "),\n", HEDLEY_STATIC_CAST(uint16_t, k));
    printf("      simde_x_mm512_set_epu32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")),\n",
           a.u32[15], a.u32[14], a.u32[13], a.u32[12], a.u32[11], a.u32[10], a.u32[ 9], a.u32[ 8],
           a.u32[ 7], a.u32[ 6], a.u32[ 5], a.u32[ 4], a.u32[ 3], a.u32[ 2], a.u32[ 1], a.u32[ 0]);
    printf("      simde_x_mm512_set_epu32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")),\n",
           b.u32[15], b.u32[14], b.u32[13], b.u32[12], b.u32[11], b.u32[10], b.u32[ 9], b.u32[ 8],
           b.u32[ 7], b.u32[ 6], b.u32[ 5], b.u32[ 4], b.u32[ 3], b.u32[ 2], b.u32[ 1], b.u32[ 0]);
    printf("      simde_x_mm512_set_epu32(UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "),\n"
           "                              UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 "), UINT32_C(%10" PRIu32 ")) },\n",
           r.u32[15], r.u32[14], r.u32[13], r.u32[12], r.u32[11], r.u32[10], r.u32[ 9], r.u32[ 8],
           r.u32[ 7], r.u32[ 6], r.u32[ 5], r.u32[ 4], r.u32[ 3], r.u32[ 2], r.u32[ 1], r.u32[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_mask_xxx_epu32(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_u32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_xxx_epu64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512i a;
    simde__m512i b;
    simde__m512i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i_private a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde__m512i_to_private(simde_mm512_xxx_epu64(simde__m512i_from_private(a), simde__m512i_from_private(b)));

    printf("    { simde_x_mm512_set_epu64(UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 "),\n"
           "                              UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 "),\n",
           "                              UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 "),\n",
           "                              UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 ")) },\n",
           a.i64[7], a.i64[6], a.i64[5], a.i64[4],
           a.i64[3], a.i64[2], a.i64[1], a.i64[0]);
    printf("      simde_x_mm512_set_epu64(UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 "),\n"
           "                              UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 "),\n"
           "                              UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 "),\n"
           "                              UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 ")),\n",
           b.u64[7], b.u64[6], b.u64[5], b.u64[4],
           b.u64[3], b.u64[2], b.u64[1], b.u64[0]);
    printf("      simde_x_mm512_set_epu64(UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 "),\n"
           "                              UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 "),\n"
           "                              UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 "),\n"
           "                              UINT64_C(%20" PRIu64 "), UINT64_C(%20" PRIu64 ")) },\n",
           r.u64[7], r.u64[6], r.u64[5], r.u64[4],
           r.u64[3], r.u64[2], r.u64[1], r.u64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_xxx_epu64(test_vec[i].a, test_vec[i].b);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_xxx_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 a;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512_private a, b, r;

    for (size_t j = 0 ; j < sizeof(simde__m512) / sizeof(simde_float32) ; j++) {
      a.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
      b.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
    }

    r = simde__m512_to_private(simde_mm512_xxx_ps(simde__m512_from_private(a), simde__m512_from_private(b)));

    printf("    { simde_mm512_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	         9, a.f32[15], 9, a.f32[14], 9, a.f32[13], 9, a.f32[12],
	         9, a.f32[11], 9, a.f32[10], 9, a.f32[ 9], 9, a.f32[ 8],
	         9, a.f32[ 7], 9, a.f32[ 6], 9, a.f32[ 5], 9, a.f32[ 4],
	         9, a.f32[ 3], 9, a.f32[ 2], 9, a.f32[ 1], 9, a.f32[ 0]);
    printf("      simde_mm512_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	         9, b.f32[15], 9, b.f32[14], 9, b.f32[13], 9, b.f32[12],
	         9, b.f32[11], 9, b.f32[10], 9, b.f32[ 9], 9, b.f32[ 8],
	         9, b.f32[ 7], 9, b.f32[ 6], 9, b.f32[ 5], 9, b.f32[ 4],
	         9, b.f32[ 3], 9, b.f32[ 2], 9, b.f32[ 1], 9, b.f32[ 0]);
    printf("      simde_mm512_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)) },\n",
	         9, r.f32[15], 9, r.f32[14], 9, r.f32[13], 9, r.f32[12],
	         9, r.f32[11], 9, r.f32[10], 9, r.f32[ 9], 9, r.f32[ 8],
	         9, r.f32[ 7], 9, r.f32[ 6], 9, r.f32[ 5], 9, r.f32[ 4],
	         9, r.f32[ 3], 9, r.f32[ 2], 9, r.f32[ 1], 9, r.f32[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_xxx_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_xxx_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512 src;
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 b;
    simde__m512 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512_private src, a, b, r;
    simde__mmask16 k;

    for (size_t j = 0 ; j < sizeof(simde__m512) / sizeof(simde_float32) ; j++) {
      src.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
      a.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
      b.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
    }
    munit_rand_memory(sizeof(k), (uint8_t*) &k);
    k &= UINT16_C(0xffff);

    r = simde__m512_to_private(simde_mm512_mask_xxx_ps(simde__m512_from_private(src), k, simde__m512_from_private(a), simde__m512_from_private(b)));

    printf("    { simde_mm512_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	         9, src.f32[15], 9, src.f32[14], 9, src.f32[13], 9, src.f32[12],
	         9, src.f32[11], 9, src.f32[10], 9, src.f32[ 9], 9, src.f32[ 8],
	         9, src.f32[ 7], 9, src.f32[ 6], 9, src.f32[ 5], 9, src.f32[ 4],
	         9, src.f32[ 3], 9, src.f32[ 2], 9, src.f32[ 1], 9, src.f32[ 0]);
    printf("      UINT16_C(%5" PRIu16 "),\n", HEDLEY_STATIC_CAST(uint16_t, k));
    printf("      simde_mm512_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	         9, a.f32[15], 9, a.f32[14], 9, a.f32[13], 9, a.f32[12],
	         9, a.f32[11], 9, a.f32[10], 9, a.f32[ 9], 9, a.f32[ 8],
	         9, a.f32[ 7], 9, a.f32[ 6], 9, a.f32[ 5], 9, a.f32[ 4],
	         9, a.f32[ 3], 9, a.f32[ 2], 9, a.f32[ 1], 9, a.f32[ 0]);
    printf("      simde_mm512_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	         9, b.f32[15], 9, b.f32[14], 9, b.f32[13], 9, b.f32[12],
	         9, b.f32[11], 9, b.f32[10], 9, b.f32[ 9], 9, b.f32[ 8],
	         9, b.f32[ 7], 9, b.f32[ 6], 9, b.f32[ 5], 9, b.f32[ 4],
	         9, b.f32[ 3], 9, b.f32[ 2], 9, b.f32[ 1], 9, b.f32[ 0]);
    printf("      simde_mm512_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)) },\n",
	         9, r.f32[15], 9, r.f32[14], 9, r.f32[13], 9, r.f32[12],
	         9, r.f32[11], 9, r.f32[10], 9, r.f32[ 9], 9, r.f32[ 8],
	         9, r.f32[ 7], 9, r.f32[ 6], 9, r.f32[ 5], 9, r.f32[ 4],
	         9, r.f32[ 3], 9, r.f32[ 2], 9, r.f32[ 1], 9, r.f32[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_mask_xxx_ps(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_xxx_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d a;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512d_private a, b, r;

    for (size_t j = 0 ; j < sizeof(simde__m512d) / sizeof(simde_float64) ; j++) {
      a.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
      b.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
    }

    r = simde__m512d_to_private(simde_mm512_xxx_pd(simde__m512d_from_private(a), simde__m512d_from_private(b)));

    printf("    { simde_mm512_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, a.f64[7], 8, a.f64[6], 8, a.f64[5], 8, a.f64[4],
           8, a.f64[3], 8, a.f64[2], 8, a.f64[1], 8, a.f64[0]);
    printf("      simde_mm512_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, b.f64[7], 8, b.f64[6], 8, b.f64[5], 8, b.f64[4],
           8, b.f64[3], 8, b.f64[2], 8, b.f64[1], 8, b.f64[0]);
    printf("      simde_mm512_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n",
           8, r.f64[7], 8, r.f64[6], 8, r.f64[5], 8, r.f64[4],
           8, r.f64[3], 8, r.f64[2], 8, r.f64[1], 8, r.f64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_xxx_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_mask_xxx_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m512d src;
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d b;
    simde__m512d r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512d_private src, a, b, r;
    simde__mmask8 k;

    for (size_t j = 0 ; j < sizeof(simde__m512d) / sizeof(simde_float64) ; j++) {
      src.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
      a.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
      b.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
    }
    munit_rand_memory(sizeof(k), (uint8_t*) &k);
    k &= UINT8_C(0xff);

    r = simde__m512d_to_private(simde_mm512_mask_xxx_pd(simde__m512d_from_private(src), k, simde__m512d_from_private(a), simde__m512d_from_private(b)));

    printf("    { simde_mm512_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, src.f64[7], 8, src.f64[6], 8, src.f64[5], 8, src.f64[4],
           8, src.f64[3], 8, src.f64[2], 8, src.f64[1], 8, src.f64[0]);
    printf("      UINT8_C(%3" PRIu8 "),\n", HEDLEY_STATIC_CAST(uint8_t, k));
    printf("      simde_mm512_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, a.f64[7], 8, a.f64[6], 8, a.f64[5], 8, a.f64[4],
           8, a.f64[3], 8, a.f64[2], 8, a.f64[1], 8, a.f64[0]);
    printf("      simde_mm512_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, b.f64[7], 8, b.f64[6], 8, b.f64[5], 8, b.f64[4],
           8, b.f64[3], 8, b.f64[2], 8, b.f64[1], 8, b.f64[0]);
    printf("      simde_mm512_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n",
           8, r.f64[7], 8, r.f64[6], 8, r.f64[5], 8, r.f64[4],
           8, r.f64[3], 8, r.f64[2], 8, r.f64[1], 8, r.f64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_mask_xxx_pd(test_vec[i].src, test_vec[i].k, test_vec[i].a, test_vec[i].b);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

/* Not sure what the use case for these is. */

static MunitResult
test_simde_mm512_xxx_mov_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask16 k;
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512i_private a, r;
    simde__mmask16 k;

    munit_rand_memory(sizeof(k), (uint8_t*) &k);
    munit_rand_memory(sizeof(a), (uint8_t*) &a);

    r = simde__m512i_to_private(simde_mm512_xxx_mov_epi32(k, simde__m512i_from_private(a)));

    printf("    { UINT16_C(%5" PRIu16 "),\n", k);
    printf("      simde_mm512_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")),\n",
           a.i32[15], a.i32[14], a.i32[13], a.i32[12], a.i32[11], a.i32[10], a.i32[ 9], a.i32[ 8],
           a.i32[ 7], a.i32[ 6], a.i32[ 5], a.i32[ 4], a.i32[ 3], a.i32[ 2], a.i32[ 1], a.i32[ 0]);
    printf("      simde_mm512_set_epi32(INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "),\n"
           "                            INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 "), INT32_C(%11" PRId32 ")) },\n",
           r.i32[15], r.i32[14], r.i32[13], r.i32[12], r.i32[11], r.i32[10], r.i32[ 9], r.i32[ 8],
           r.i32[ 7], r.i32[ 6], r.i32[ 5], r.i32[ 4], r.i32[ 3], r.i32[ 2], r.i32[ 1], r.i32[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_xxx_mov_epi32(test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_xxx_mov_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512i_private a, r;
    simde__mmask8 k;

    munit_rand_memory(sizeof(k), (uint8_t*) &k);
    munit_rand_memory(sizeof(a), (uint8_t*) &a);

    r = simde__m512i_to_private(simde_mm512_xxx_mov_epi64(k, simde__m512i_from_private(a)));

    printf("    { UINT8_C(%3" PRIu8 "),\n", k);
    printf("      simde_mm512_set_epi64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")),\n",
           a.i64[7], a.i64[6], a.i64[5], a.i64[4],
           a.i64[3], a.i64[2], a.i64[1], a.i64[0]);
    printf("      simde_mm512_set_epi64(INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 "),\n"
           "                            INT64_C(%20" PRId64 "), INT64_C(%20" PRId64 ")) },\n",
           r.i64[7], r.i64[6], r.i64[5], r.i64[4],
           r.i64[3], r.i64[2], r.i64[1], r.i64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_xxx_mov_epi64(test_vec[i].k, test_vec[i].a);
    simde_assert_m512i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_xxx_mov_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask16 k;
    simde__m512 a;
    simde__m512 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512_private a, r;
    simde__mmask16 k;

    for (size_t j = 0 ; j < sizeof(simde__m512) / sizeof(simde_float32) ; j++) {
      a.f32[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
    }
    munit_rand_memory(sizeof(k), (uint8_t*) &k);

    r = simde__m512_to_private(simde_mm512_xxx_mov_ps(k, simde__m512_from_private(a)));

    printf("    { UINT16_C(%5" PRIu16 "),\n", k);
    printf("      simde_mm512_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)),\n",
	         9, a.f32[15], 9, a.f32[14], 9, a.f32[13], 9, a.f32[12],
	         9, a.f32[11], 9, a.f32[10], 9, a.f32[ 9], 9, a.f32[ 8],
	         9, a.f32[ 7], 9, a.f32[ 6], 9, a.f32[ 5], 9, a.f32[ 4],
	         9, a.f32[ 3], 9, a.f32[ 2], 9, a.f32[ 1], 9, a.f32[ 0]);
    printf("      simde_mm512_set_ps(SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f),\n"
           "                         SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f), SIMDE_FLOAT32_C(%*.2f)) },\n",
	         9, r.f32[15], 9, r.f32[14], 9, r.f32[13], 9, r.f32[12],
	         9, r.f32[11], 9, r.f32[10], 9, r.f32[ 9], 9, r.f32[ 8],
	         9, r.f32[ 7], 9, r.f32[ 6], 9, r.f32[ 5], 9, r.f32[ 4],
	         9, r.f32[ 3], 9, r.f32[ 2], 9, r.f32[ 1], 9, r.f32[ 0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512 r = simde_mm512_xxx_mov_ps(test_vec[i].k, test_vec[i].a);
    simde_assert_m512_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm512_xxx_mov_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__mmask8 k;
    simde__m512d a;
    simde__m512d r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde__m512d_private a, r;
    simde__mmask8 k;

    for (size_t j = 0 ; j < sizeof(simde__m512d) / sizeof(simde_float64) ; j++) {
      a.f64[j] = round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0;
    }
    munit_rand_memory(sizeof(k), (uint8_t*) &k);

    r = simde__m512d_to_private(simde_mm512_xxx_mov_pd(k, simde__m512d_from_private(a)));

    printf("    { UINT8_C(%3" PRIu8 "),\n", k);
    printf("      simde_mm512_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)),\n",
           8, a.f64[7], 8, a.f64[6], 8, a.f64[5], 8, a.f64[4],
           8, a.f64[3], 8, a.f64[2], 8, a.f64[1], 8, a.f64[0]);
    printf("      simde_mm512_set_pd(SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f),\n"
           "                         SIMDE_FLOAT64_C(%*.2f), SIMDE_FLOAT64_C(%*.2f)) },\n",
           8, r.f64[7], 8, r.f64[6], 8, r.f64[5], 8, r.f64[4],
           8, r.f64[3], 8, r.f64[2], 8, r.f64[1], 8, r.f64[0]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512d r = simde_mm512_xxx_mov_pd(test_vec[i].k, test_vec[i].a);
    simde_assert_m512d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}
