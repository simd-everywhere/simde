#define SIMDE_TEST_ARM_NEON_INSN xar

#include "test-neon.h"
#include "../../../simde/arm/neon/xar.h"

static int
test_simde_vxarq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    const int d;
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 9628751354834048685), UINT64_C( 8180658770852743132) },
      { UINT64_C( 6556036980534015424), UINT64_C(14990450312212940349) },
       INT32_C(          35),
      { UINT64_C( 5696917660486037846), UINT64_C(13796918454511593949) } },
    { { UINT64_C( 5668014874756249515), UINT64_C(  729526124475789151) },
      { UINT64_C(14095419800660744837), UINT64_C(14507759190850905284) },
       INT32_C(          34),
      { UINT64_C(15080157442065893943), UINT64_C(16108006867498862990) } },
    { { UINT64_C( 5630183606601120164), UINT64_C(18195313650575098170) },
      { UINT64_C(16275818577938816698), UINT64_C(11997865393854755901) },
       INT32_C(          53),
      { UINT64_C(16854532388623545727), UINT64_C( 1311379854409087696) } },
    { { UINT64_C( 7608765659193592989), UINT64_C(18066512299323431297) },
      { UINT64_C(14975742874696259704), UINT64_C( 2347535955255448705) },
       INT32_C(          21),
      { UINT64_C(13449768505374542613), UINT64_C(11126150375912350312) } },
    { { UINT64_C(16105655838196272837), UINT64_C(11536733319309376493) },
      { UINT64_C(14209953324076101179), UINT64_C(10225385334056011524) },
       INT32_C(          43),
      { UINT64_C(13600661607205262885), UINT64_C(  257065404598697901) } },
    { { UINT64_C( 7306188323426555153), UINT64_C(12716042662030180224) },
      { UINT64_C( 4201114574175710042), UINT64_C(10355635361400960056) },
       INT32_C(          16),
      { UINT64_C(18323844141016129927), UINT64_C( 5456181106549397698) } },
    { { UINT64_C(16118643044838208372), UINT64_C( 4979017269977753697) },
      { UINT64_C( 1746068009845286496), UINT64_C( 1032510253178614498) },
       INT32_C(          23),
      { UINT64_C(14783674421345767640), UINT64_C( 5743504143686210256) } },
    { { UINT64_C(12556892124042998567), UINT64_C( 6631396255265414159) },
      { UINT64_C(14947479279354856379), UINT64_C( 2817248959148246355) },
       INT32_C(          20),
      { UINT64_C(17224516035592249680), UINT64_C(15678657244963807522) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r;
    SIMDE_CONSTIFY_64_(simde_vxarq_u64, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].d, a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    const int d = simde_math_abs(simde_test_codegen_random_i32() % 64);
    simde_uint64x2_t r;
    SIMDE_CONSTIFY_64_(simde_vxarq_u64, r, (HEDLEY_UNREACHABLE(), r), d, a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, d, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vxarq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
