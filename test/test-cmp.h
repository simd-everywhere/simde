/*
 * Binary operations on vector types
 */

#define define_test_cmp_VT_2xVT(T, func, CT)				\
  static MunitResult							\
  test_simde_##func(const MunitParameter params[], void* data) {	\
    (void) params;							\
    (void) data;							\
									\
    _##T na, nb, nr;							\
    simde_##T ea, eb, er;						\
									\
    munit_rand_memory(sizeof(na), (uint8_t*) &na);			\
    munit_rand_memory(sizeof(nb), (uint8_t*) &nb);			\
    memcpy(&ea, &na, sizeof(na));					\
    memcpy(&eb, &nb, sizeof(nb));					\
									\
    nr = _##func(na, nb);						\
    er = simde_##func(ea, eb);						\
									\
    simde_assert##T##_##CT(nr, ==, er);					\
									\
    _mm_empty();							\
    return MUNIT_OK;							\
  }

/* 32-bit floating point operands, no nan or inf */
#define define_test_cmp_f32_VT_2xVT(T, func)				\
  static MunitResult							\
  test_simde_##func(const MunitParameter params[], void* data) {	\
    (void) params;							\
    (void) data;							\
									\
    _##T na, nb, nr;							\
    simde_##T ea, eb, er;						\
									\
    random_f32v(sizeof(na) / sizeof(simde_float32), (float*) &na);	\
    random_f32v(sizeof(nb) / sizeof(simde_float32), (float*) &nb);	\
    memcpy(&ea, &na, sizeof(na));					\
    memcpy(&eb, &nb, sizeof(nb));					\
									\
    nr = _##func(na, nb);						\
    er = simde_##func(ea, eb);						\
									\
    /* We use u32 since some functions fill elements with ~0U or 0U */	\
    simde_assert##T##_u32(nr, ==, er);					\
									\
    _mm_empty();							\
    return MUNIT_OK;							\
  }

/* 64-bit floating point operands, no nan or inf */
#define define_test_cmp_f64_VT_2xVT(T, func)				\
  static MunitResult							\
  test_simde_##func(const MunitParameter params[], void* data) {	\
    (void) params;							\
    (void) data;							\
									\
    _##T na, nb, nr;							\
    simde_##T ea, eb, er;						\
									\
    random_f64v(sizeof(na) / sizeof(simde_float64), (simde_float64*) &na); \
    random_f64v(sizeof(nb) / sizeof(simde_float64), (simde_float64*) &nb); \
    memcpy(&ea, &na, sizeof(na));					\
    memcpy(&eb, &nb, sizeof(nb));					\
									\
    nr = _##func(na, nb);						\
    er = simde_##func(ea, eb);						\
									\
    /* We use u64 since some functions fill elements with ~0U or 0U */	\
    simde_assert##T##_f64(nr, ==, er);					\
									\
    _mm_empty();							\
    return MUNIT_OK;							\
  }

/* Operation on 2 vector types which returns a scalar */
#define define_test_cmp_s_2xVT(T, func, MCT, RT)			\
  static MunitResult							\
  test_simde_##func(const MunitParameter params[], void* data) {	\
    (void) params;							\
    (void) data;							\
									\
    _##T na, nb;							\
    simde_##T ea, eb;							\
    RT nr, er;								\
									\
    random_f32v(sizeof(na) / sizeof(simde_float32), (simde_float32*) &na); \
    random_f32v(sizeof(nb) / sizeof(simde_float32), (simde_float32*) &nb); \
    memcpy(&ea, &na, sizeof(na));					\
    memcpy(&eb, &nb, sizeof(nb));					\
									\
    nr = _##func(na, nb);						\
    er = simde_##func(ea, eb);						\
									\
    munit_assert_##MCT(nr, ==, er);					\
									\
    _mm_empty();							\
    return MUNIT_OK;							\
  }

#define define_test_cmp_VT_VT1_VT2(RT, VT1, VT2, func, CT)		\
  static MunitResult							\
  test_simde_##func(const MunitParameter params[], void* data) {	\
    (void) params;							\
    (void) data;							\
									\
    _##VT1 na;								\
    _##VT2 nb;								\
    _##RT nr;								\
    simde_##VT1 ea;							\
    simde_##VT2 eb;							\
    simde_##RT er;							\
									\
    munit_rand_memory(sizeof(na), (uint8_t*) &na);			\
    munit_rand_memory(sizeof(nb), (uint8_t*) &nb);			\
    memcpy(&ea, &na, sizeof(na));					\
    memcpy(&eb, &nb, sizeof(nb));					\
									\
    nr = _##func(na, nb);						\
    er = simde_##func(ea, eb);						\
    									\
    simde_assert##RT##_##CT(nr, ==, er);				\
									\
    _mm_empty();							\
    return MUNIT_OK;							\
  }

/*
 * Unary operations
 */

#define define_test_cmp_VT_VT(T, func, CT)				\
  static MunitResult							\
  test_simde_##func(const MunitParameter params[], void* data) {	\
    (void) params;							\
    (void) data;							\
									\
    _##T na, nr;							\
    simde_##T ea, er;							\
									\
    munit_rand_memory(sizeof(na), (uint8_t*) &na);			\
    memcpy(&ea, &na, sizeof(na));					\
									\
    nr = _##func(na);							\
    er = simde_##func(ea);						\
									\
    simde_assert##T##_##CT(nr, ==, er);					\
									\
    _mm_empty();							\
    return MUNIT_OK;							\
  }

/* 32-bit floating point operand, no nan or inf */
#define define_test_cmp_f32_VT_VT(T, func)				\
  static MunitResult							\
  test_simde_##func(const MunitParameter params[], void* data) {	\
    (void) params;							\
    (void) data;							\
									\
    _##T na, nr;							\
    simde_##T ea, er;							\
									\
    random_f32v(sizeof(na) / sizeof(simde_float32), (simde_float32*) &na); \
    memcpy(&ea, &na, sizeof(na));					\
									\
    nr = _##func(na);							\
    er = simde_##func(ea);						\
									\
    /* We use u32 since some functions fill elements with ~0U or 0U */	\
    simde_assert##T##_u32(nr, ==, er);					\
									\
    _mm_empty();							\
    return MUNIT_OK;							\
  }
