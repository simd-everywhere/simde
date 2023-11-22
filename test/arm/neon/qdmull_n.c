#define SIMDE_TEST_ARM_NEON_INSN qdmull_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmull_n.h"

static int
test_simde_vqdmull_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[4];
    int16_t b;
    int32_t r[4];
  } test_vec[] = {
    { {   INT16_C( 6624), -INT16_C( 9205), -INT16_C( 5109), -INT16_C(  284) },
          INT16_C( 5819),
      {   INT32_C(   77090112), -INT32_C(  107127790), -INT32_C(   59458542), -INT32_C(    3305192) } },
    { {  -INT16_C( 6673), -INT16_C( 4381), -INT16_C( 3216),  INT16_C( 8408) },
          INT16_C( 8183),
      {  -INT32_C(  109210318), -INT32_C(   71699446), -INT32_C(   52633056),  INT32_C(  137605328) } },
    { {   INT16_C( 3114),  INT16_C( 6953),  INT16_C( 9387), -INT16_C( 2558) },
         -INT16_C( 8943),
      {  -INT32_C(   55697004), -INT32_C(  124361358), -INT32_C(  167895882),  INT32_C(   45752388) } },
    { {   INT16_C( 3872), -INT16_C( 8647),  INT16_C( 4643),  INT16_C( 6634) },
         -INT16_C( 7367),
      {  -INT32_C(   57050048),  INT32_C(  127404898), -INT32_C(   68409962), -INT32_C(   97745356) } },
    { {   INT16_C( 5569),  INT16_C( 8610),  INT16_C( 4174),  INT16_C( 1241) },
          INT16_C( 4261),
      {   INT32_C(   47459018),  INT32_C(   73374420),  INT32_C(   35570828),  INT32_C(   10575802) } },
    { {  -INT16_C( 4157),  INT16_C( 7246), -INT16_C( 8418),  INT16_C( 2893) },
         -INT16_C( 3990),
      {   INT32_C(   33172860), -INT32_C(   57823080),  INT32_C(   67175640), -INT32_C(   23086140) } },
    { {   INT16_C( 8394), -INT16_C( 4925),  INT16_C( 9425),  INT16_C( 6873) },
          INT16_C( 2131),
      {   INT32_C(   35775228), -INT32_C(   20990350),  INT32_C(   40169350),  INT32_C(   29292726) } },
    { {  -INT16_C( 7623), -INT16_C( 8682),  INT16_C( 9341), -INT16_C( 7120) },
          INT16_C( 6046),
      {  -INT32_C(   92177316), -INT32_C(  104982744),  INT32_C(  112951372), -INT32_C(   86095040) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    int16_t b = test_vec[i].b;
    simde_int32x4_t r = simde_vqdmull_n_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmull_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[2];
    int32_t b;
    int64_t r[2];
  } test_vec[] = {
    { {   INT32_C(  19666), -INT32_C( 932172) },
          INT32_C( 274385),
      {   INT64_C(   10792110820), -INT64_C(  511548028440) } },
    { {  -INT32_C(   6416), -INT32_C(  41797) },
          INT32_C( 498878),
      {  -INT64_C(    6401602496), -INT64_C(   41703207532) } },
    { {   INT32_C(  89019), -INT32_C( 240137) },
          INT32_C( 171421),
      {   INT64_C(   30519451998), -INT64_C(   82329049354) } },
    { {   INT32_C( 280588), -INT32_C(  63104) },
         -INT32_C( 831837),
      {  -INT64_C(  466806960312),  INT64_C(  104984484096) } },
    { {   INT32_C( 203110),  INT32_C( 487428) },
          INT32_C( 670677),
      {   INT64_C(  272442410940),  INT64_C(  653813497512) } },
    { {  -INT32_C(  25065), -INT32_C( 686529) },
         -INT32_C( 336578),
      {   INT64_C(   16872655140),  INT64_C(  462141115524) } },
    { {   INT32_C( 627469),  INT32_C( 977133) },
          INT32_C( 708625),
      {   INT64_C(  889280440250),  INT64_C( 1384841744250) } },
    { {   INT32_C( 758643), -INT32_C(  94691) },
         -INT32_C( 850570),
      {  -INT64_C( 1290557953020),  INT64_C(  161082647740) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    int32_t b = test_vec[i].b;
    simde_int64x2_t r = simde_vqdmull_n_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_n_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
