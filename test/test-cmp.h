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
    random_floatv(sizeof(na) / sizeof(float), (float*) &na);		\
    random_floatv(sizeof(nb) / sizeof(float), (float*) &nb);		\
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
    random_floatv(sizeof(na) / sizeof(float), (float*) &na);		\
    random_floatv(sizeof(nb) / sizeof(float), (float*) &nb);		\
    memcpy(&ea, &na, sizeof(na));					\
    memcpy(&eb, &nb, sizeof(nb));					\
									\
    nr = _##func(na, nb);						\
    er = simde_##func(ea, eb);						\
									\
    debug_array_f32("\na", sizeof(na) / sizeof(float), (float*) &na);	\
    debug_array_f32("b", sizeof(nb) / sizeof(float), (float*) &nb);	\
    debug_array_f32("r", sizeof(nb) / sizeof(float), (float*) &er);	\
    debug_array_f32("x", sizeof(nb) / sizeof(float), (float*) &nr);	\
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
