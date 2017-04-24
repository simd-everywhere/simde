#define define_test_cmp_m64_2xm64(func, rt)				\
  static MunitResult							\
  test_simde_##func(const MunitParameter params[], void* data) {	\
    (void) params;							\
    (void) data;							\
									\
    __m64 na, nb, nr;							\
    simde__m64 ea, eb, er;						\
									\
    munit_rand_memory(sizeof(na), (uint8_t*) &na);			\
    munit_rand_memory(sizeof(nb), (uint8_t*) &nb);			\
    memcpy(&ea, &na, sizeof(na));					\
    memcpy(&eb, &nb, sizeof(nb));					\
									\
    nr = _##func(na, nb);						\
    er = simde_##func(ea, eb);						\
									\
    simde_assert_m64_##rt(nr, ==, er);					\
									\
    _mm_empty();							\
    return MUNIT_OK;							\
  }
