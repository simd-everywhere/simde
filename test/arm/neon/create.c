#define SIMDE_TEST_ARM_NEON_INSN create

/* N.B. CM: The comparisons are done at a whole vector (64-bit) level to
 * avoid endian problems due to the reversal of the order of the vector
 * elements with NEON on big-endian systems. */

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/create.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

static int
test_simde_vcreate_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t r[1];
  } test_vec[] = {
    { UINT64_C(14132917921477899950),
      { UINT64_C(14132917921477899950) } },
    { UINT64_C( 9768881841052706856),
      { UINT64_C( 9768881841052706856) } },
    { UINT64_C(16325103149125810475),
      { UINT64_C(16325103149125810475) } },
    { UINT64_C( 2241800239056659389),
      { UINT64_C( 2241800239056659389) } },
    { UINT64_C(16892050861247466928),
      { UINT64_C(16892050861247466928) } },
    { UINT64_C( 6292462352927236486),
      { UINT64_C( 6292462352927236486) } },
    { UINT64_C(13564512221404632202),
      { UINT64_C(13564512221404632202) } },
    { UINT64_C(13980988618246101366),
      { UINT64_C(13980988618246101366) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t r = simde_vcreate_s8(test_vec[i].a);
    simde_test_arm_neon_assert_equal_u64x1(simde_vreinterpret_u64_s8(r), simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_int8x8_t r = simde_vcreate_s8(a);
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, simde_vreinterpret_u64_s8(r), SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t r[1];
  } test_vec[] = {
    { UINT64_C(10194708065387003937),
      { UINT64_C(10194708065387003937) } },
    { UINT64_C( 4926405416270135894),
      { UINT64_C( 4926405416270135894) } },
    { UINT64_C(14233135747404150946),
      { UINT64_C(14233135747404150946) } },
    { UINT64_C(13467007090084057788),
      { UINT64_C(13467007090084057788) } },
    { UINT64_C( 5670577254878680876),
      { UINT64_C( 5670577254878680876) } },
    { UINT64_C(14291510562562377841),
      { UINT64_C(14291510562562377841) } },
    { UINT64_C( 4769192735922800093),
      { UINT64_C( 4769192735922800093) } },
    { UINT64_C(16679089722896895781),
      { UINT64_C(16679089722896895781) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t r = simde_vcreate_s16(test_vec[i].a);
    simde_test_arm_neon_assert_equal_u64x1(simde_vreinterpret_u64_s16(r), simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_int16x4_t r = simde_vcreate_s16(a);
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, simde_vreinterpret_u64_s16(r), SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t r[1];
  } test_vec[] = {
    { UINT64_C( 2439430255293500298),
      { UINT64_C( 2439430255293500298) } },
    { UINT64_C( 4265113451400979156),
      { UINT64_C( 4265113451400979156) } },
    { UINT64_C( 4220290061209471777),
      { UINT64_C( 4220290061209471777) } },
    { UINT64_C(15125839935251710912),
      { UINT64_C(15125839935251710912) } },
    { UINT64_C( 8203352478617372114),
      { UINT64_C( 8203352478617372114) } },
    { UINT64_C( 3629274651627509259),
      { UINT64_C( 3629274651627509259) } },
    { UINT64_C( 1873250436141407570),
      { UINT64_C( 1873250436141407570) } },
    { UINT64_C(12807094805541099426),
      { UINT64_C(12807094805541099426) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r = simde_vcreate_s32(test_vec[i].a);
    simde_test_arm_neon_assert_equal_u64x1(simde_vreinterpret_u64_s32(r), simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_int32x2_t r = simde_vcreate_s32(a);
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, simde_vreinterpret_u64_s32(r), SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    int64_t r[1];
  } test_vec[] = {
    { UINT64_C( 5395799976582993883),
      {  INT64_C( 5395799976582993883) } },
    { UINT64_C( 4567289535980575384),
      {  INT64_C( 4567289535980575384) } },
    { UINT64_C(16941982940099198756),
      { -INT64_C( 1504761133610352860) } },
    { UINT64_C(15415313526547754242),
      { -INT64_C( 3031430547161797374) } },
    { UINT64_C(10110945050363508873),
      { -INT64_C( 8335799023346042743) } },
    { UINT64_C( 3838853662046080100),
      {  INT64_C( 3838853662046080100) } },
    { UINT64_C(11762288014748589464),
      { -INT64_C( 6684456058960962152) } },
    { UINT64_C( 2091664278160892727),
      {  INT64_C( 2091664278160892727) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t r = simde_vcreate_s64(test_vec[i].a);
    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_int64x1_t r = simde_vcreate_s64(a);
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t r[1];
  } test_vec[] = {
    { UINT64_C( 9524461125136957834),
      { UINT64_C( 9524461125136957834) } },
    { UINT64_C( 5681877711578043306),
      { UINT64_C( 5681877711578043306) } },
    { UINT64_C( 2605432708141052716),
      { UINT64_C( 2605432708141052716) } },
    { UINT64_C( 3195240861471437814),
      { UINT64_C( 3195240861471437814) } },
    { UINT64_C( 9113757135495505160),
      { UINT64_C( 9113757135495505160) } },
    { UINT64_C(10096533119189207844),
      { UINT64_C(10096533119189207844) } },
    { UINT64_C( 6840162342001118346),
      { UINT64_C( 6840162342001118346) } },
    { UINT64_C(10188299615527616150),
      { UINT64_C(10188299615527616150) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t r = simde_vcreate_u8(test_vec[i].a);
    simde_test_arm_neon_assert_equal_u64x1(simde_vreinterpret_u64_u8(r), simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_uint8x8_t r = simde_vcreate_u8(a);
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, simde_vreinterpret_u64_u8(r), SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t r[1];
  } test_vec[] = {
    { UINT64_C(10724469750478909377),
      { UINT64_C(10724469750478909377) } },
    { UINT64_C( 2531916720399834289),
      { UINT64_C( 2531916720399834289) } },
    { UINT64_C(13290330643019436200),
      { UINT64_C(13290330643019436200) } },
    { UINT64_C( 5364678349457749890),
      { UINT64_C( 5364678349457749890) } },
    { UINT64_C(15337281361360988890),
      { UINT64_C(15337281361360988890) } },
    { UINT64_C(18072566328191100628),
      { UINT64_C(18072566328191100628) } },
    { UINT64_C(13203823162098677815),
      { UINT64_C(13203823162098677815) } },
    { UINT64_C(16911653288486692574),
      { UINT64_C(16911653288486692574) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t r = simde_vcreate_u16(test_vec[i].a);
    simde_test_arm_neon_assert_equal_u64x1(simde_vreinterpret_u64_u16(r), simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_uint16x4_t r = simde_vcreate_u16(a);
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, simde_vreinterpret_u64_u16(r), SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t r[1];
  } test_vec[] = {
    { UINT64_C(17456657123552764214),
      { UINT64_C(17456657123552764214) } },
    { UINT64_C( 7637277477721962941),
      { UINT64_C( 7637277477721962941) } },
    { UINT64_C( 5996866312583239863),
      { UINT64_C( 5996866312583239863) } },
    { UINT64_C(15243824492585726451),
      { UINT64_C(15243824492585726451) } },
    { UINT64_C(17486971808534147986),
      { UINT64_C(17486971808534147986) } },
    { UINT64_C( 3061556536935998637),
      { UINT64_C( 3061556536935998637) } },
    { UINT64_C(11395754859327227054),
      { UINT64_C(11395754859327227054) } },
    { UINT64_C(11600010461574602123),
      { UINT64_C(11600010461574602123) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t r = simde_vcreate_u32(test_vec[i].a);
    simde_test_arm_neon_assert_equal_u64x1(simde_vreinterpret_u64_u32(r), simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_uint32x2_t r = simde_vcreate_u32(a);
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, simde_vreinterpret_u64_u32(r), SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t r[1];
  } test_vec[] = {
    { UINT64_C( 9581747805669338544),
      { UINT64_C( 9581747805669338544) } },
    { UINT64_C( 2636195106661380572),
      { UINT64_C( 2636195106661380572) } },
    { UINT64_C(  338359284805175101),
      { UINT64_C(  338359284805175101) } },
    { UINT64_C(18243733878740660141),
      { UINT64_C(18243733878740660141) } },
    { UINT64_C(10003026585137609329),
      { UINT64_C(10003026585137609329) } },
    { UINT64_C(16155708883640647060),
      { UINT64_C(16155708883640647060) } },
    { UINT64_C( 4404981749918038306),
      { UINT64_C( 4404981749918038306) } },
    { UINT64_C( 7970543397987432786),
      { UINT64_C( 7970543397987432786) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t r = simde_vcreate_u64(test_vec[i].a);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_uint64x1_t r = simde_vcreate_u64(a);
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t r[1];
  } test_vec[] = {
    { UINT64_C(14121171741695809290),
      { UINT64_C(14121171741695809290) } },
    { UINT64_C(14036155041624243569),
      { UINT64_C(14036155041624243569) } },
    { UINT64_C( 4933549844381694689),
      { UINT64_C( 4933549844381694689) } },
    { UINT64_C( 4721956654897595679),
      { UINT64_C( 4721956654897595679) } },
    { UINT64_C( 4794791124775457096),
      { UINT64_C( 4794791124775457096) } },
    { UINT64_C(14142503323827870106),
      { UINT64_C(14142503323827870106) } },
    { UINT64_C(14093049577892322181),
      { UINT64_C(14093049577892322181) } },
    { UINT64_C( 4932300799177322332),
      { UINT64_C( 4932300799177322332) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t r = simde_vcreate_f32(test_vec[i].a);
    simde_test_arm_neon_assert_equal_u64x1(simde_vreinterpret_u64_f32(r), simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_float32x2_t a_ = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    simde_memcpy(&a, &a_, sizeof(a));
    simde_float32x2_t r = simde_vcreate_f32(a);
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, simde_vreinterpret_u64_f32(r), SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    simde_float64_t r[1];
  } test_vec[] = {
    { UINT64_C( 4647965680019345244),
      { SIMDE_FLOAT64_C(   540.52) } },
    { UINT64_C( 4647039803267827630),
      { SIMDE_FLOAT64_C(   473.63) } },
    { UINT64_C(13872857505826498150),
      { SIMDE_FLOAT64_C(  -713.30) } },
    { UINT64_C(13873545360300834816),
      { SIMDE_FLOAT64_C(  -791.50) } },
    { UINT64_C(13859231829969516626),
      { SIMDE_FLOAT64_C(   -87.53) } },
    { UINT64_C( 4646306736875356815),
      { SIMDE_FLOAT64_C(   431.96) } },
    { UINT64_C(13868860209313485947),
      { SIMDE_FLOAT64_C(  -385.43) } },
    { UINT64_C( 4651482094126833336),
      { SIMDE_FLOAT64_C(   940.29) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t r = simde_vcreate_f64(test_vec[i].a);
    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_float64x1_t a_ = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_memcpy(&a, &a_, sizeof(a));
    simde_float64x1_t r = simde_vcreate_f64(a);
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
