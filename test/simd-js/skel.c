/* These are just some skeletons I've been using to speed up the
   process of creating new tests. */

static MunitResult
test_simde_em_int32x4_binary(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_int32x4 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_em_int32x4 a, b, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    munit_rand_memory(sizeof(b), (uint8_t*) &b);

    r = simde_em_int32x4_binary(a, b);

    printf("    { simde_em_int32x4_set(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)),\n",
  	   a.v[0], a.v[1], a.v[2], a.v[3]);
    printf("      simde_em_int32x4_set(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)),\n",
  	   b.v[0], b.v[1], b.v[2], b.v[3]);
    printf("      simde_em_int32x4_set(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)) },\n",
  	   r.v[0], r.v[1], r.v[2], r.v[3]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_binary(test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_unary(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_em_int32x4 a, r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);

    r = simde_em_int32x4_unary(a);

    printf("    { simde_em_int32x4_set(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)),\n",
  	   a.v[0], a.v[1], a.v[2], a.v[3]);
    printf("      simde_em_int32x4_set(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)) },\n",
  	   r.v[0], r.v[1], r.v[2], r.v[3]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_unary(test_vec[i].a);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_compare(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    simde_em_int32x4 b;
    simde_em_bool32x4 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_em_int32x4 a, b;
    simde_em_bool32x4 r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    for (size_t j = 0 ; j < (sizeof(b.v) / sizeof(b.v[0])) ; j++)
      b.v[j] = munit_rand_int_range(0, 1) ? ((int32_t) munit_rand_uint32()) : a.v[j];

    r = simde_em_int32x4_compare(a, b);

    printf("    { simde_em_int32x4_set(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)),\n",
  	   a.v[0], a.v[1], a.v[2], a.v[3]);
    printf("      simde_em_int32x4_set(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)),\n",
  	   b.v[0], b.v[1], b.v[2], b.v[3]);
    printf("      simde_x_em_bool32x4_set(%d, %d, %d, %d) },\n",
  	   r.v[0] != 0, r.v[1] != 0, r.v[2] != 0, r.v[3] != 0);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_bool32x4 r = simde_em_int32x4_compare(test_vec[i].a, test_vec[i].b);
    simde_assert_bool32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_int32x4_scalar(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_int32x4 a;
    int b;
    simde_em_int32x4 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_em_int32x4 a, r;
    int b;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    b = munit_rand_int_range(0, (sizeof(a.v[0]) * CHAR_BIT) - 1);

    r = simde_em_int32x4_scalar(a, b);

    printf("    { simde_em_int32x4_set(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)), %d,\n",
  	   a.v[0], a.v[1], a.v[2], a.v[3], b);
    printf("      simde_em_int32x4_set(INT32_C(%11d), INT32_C(%11d), INT32_C(%11d), INT32_C(%11d)) },\n",
  	   r.v[0], r.v[1], r.v[2], r.v[3]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_int32x4 r = simde_em_int32x4_scalar(test_vec[i].a, test_vec[i].b);
    simde_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_binary(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 b;
    simde_em_float32x4 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_em_float32x4 a, b, r;

    for (size_t j = 0 ; j < sizeof(a.v) / sizeof(a.v[0]) ; j++) {
      a.v[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
      b.v[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
    }

    r = simde_em_float32x4_binary(a, b);

    printf("    { simde_em_float32x4_set(SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f)),\n",
  	   a.v[0], a.v[1], a.v[2], a.v[3]);
    printf("      simde_em_float32x4_set(SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f)),\n",
  	   b.v[0], b.v[1], b.v[2], b.v[3]);
    printf("      simde_em_float32x4_set(SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f)) },\n",
  	   r.v[0], r.v[1], r.v[2], r.v[3]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_binary(test_vec[i].a, test_vec[i].b);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_unary(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_em_float32x4 a, r;

    for (size_t j = 0 ; j < sizeof(a.v) / sizeof(a.v[0]) ; j++) {
      a.v[j] = (simde_float32) (round(random_f64_range(-1000.0, 1000.0) * 100.0) / 100.0);
    }

    r = simde_em_float32x4_unary(a);

    printf("    { simde_em_float32x4_set(SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f)),\n",
  	   a.v[0], a.v[1], a.v[2], a.v[3]);
    printf("      simde_em_float32x4_set(SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f)) },\n",
  	   r.v[0], r.v[1], r.v[2], r.v[3]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_unary(test_vec[i].a);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_compare(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    simde_em_float32x4 b;
    simde_em_bool32x4 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_em_float32x4 a, b;
    simde_em_bool32x4 r;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    for (size_t j = 0 ; j < (sizeof(b.v) / sizeof(b.v[0])) ; j++)
      b.v[j] = munit_rand_int_range(0, 1) ? ((int32_t) munit_rand_uint32()) : a.v[j];

    r = simde_em_float32x4_compare(a, b);

    printf("    { simde_em_float32x4_set(SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f)),\n",
  	   a.v[0], a.v[1], a.v[2], a.v[3]);
    printf("      simde_em_float32x4_set(SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f)),\n",
  	   b.v[0], b.v[1], b.v[2], b.v[3]);
    printf("      simde_x_em_bool32x4_set(%d, %d, %d, %d) },\n",
  	   r.v[0] != 0, r.v[1] != 0, r.v[2] != 0, r.v[3] != 0);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_bool32x4 r = simde_em_float32x4_compare(test_vec[i].a, test_vec[i].b);
    simde_assert_bool32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_em_float32x4_scalar(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_em_float32x4 a;
    int b;
    simde_em_float32x4 r;
  } test_vec[8] = {

  };

  printf("\n");
  for (size_t i = 0 ; i < (sizeof(test_vec) / (sizeof(test_vec[0]))) ; i++) {
    simde_em_float32x4 a, r;
    int b;

    munit_rand_memory(sizeof(a), (uint8_t*) &a);
    b = munit_rand_int_range(0, (sizeof(a.v[0]) * CHAR_BIT) - 1);

    r = simde_em_float32x4_scalar(a, b);

    printf("    { simde_em_float32x4_set(SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f)), %d,\n",
  	   a.v[0], a.v[1], a.v[2], a.v[3], b);
    printf("      simde_em_float32x4_set(SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f), SIMDE_FLOAT32_C(%7.2f)) },\n",
  	   r.v[0], r.v[1], r.v[2], r.v[3]);
  }
  return MUNIT_FAIL;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_em_float32x4 r = simde_em_float32x4_scalar(test_vec[i].a, test_vec[i].b);
    simde_assert_float32x4_equal(2, r, test_vec[i].r);
  }

  return MUNIT_OK;
}
