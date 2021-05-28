#define SIMDE_TEST_ARM_NEON_INSN qdmulh_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmulh_n.h"

static int
test_simde_vqdmulhq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b;
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  4720), -INT16_C(  2937),  INT16_C( 31790), -INT16_C( 17234), -INT16_C( 16628), -INT16_C( 18870), -INT16_C(  2448),  INT16_C( 21521) },
       INT16_C( 16900),
      {  INT16_C(  2434), -INT16_C(  1515),  INT16_C( 16395), -INT16_C(  8889), -INT16_C(  8576), -INT16_C(  9733), -INT16_C(  1263),  INT16_C( 11099) } },
    { {  INT16_C( 31796),  INT16_C( 26069), -INT16_C( 20933),  INT16_C( 30373), -INT16_C(  5095),  INT16_C( 14326),  INT16_C( 26160), -INT16_C( 18359) },
       INT16_C( 30555),
      {  INT16_C( 29648),  INT16_C( 24308), -INT16_C( 19520),  INT16_C( 28321), -INT16_C(  4751),  INT16_C( 13358),  INT16_C( 24393), -INT16_C( 17120) } },
    { {  INT16_C(  2356),  INT16_C( 16436),  INT16_C( 32456),  INT16_C( 14839),  INT16_C(  2164),  INT16_C( 30861), -INT16_C( 16054),  INT16_C(  8180) },
       INT16_C( 12070),
      {  INT16_C(   867),  INT16_C(  6054),  INT16_C( 11955),  INT16_C(  5465),  INT16_C(   797),  INT16_C( 11367), -INT16_C(  5914),  INT16_C(  3013) } },
    { { -INT16_C( 13363), -INT16_C(  6490), -INT16_C( 25417), -INT16_C(  6370),  INT16_C( 26370),  INT16_C( 23967), -INT16_C( 11297),  INT16_C(  4967) },
       INT16_C( 12052),
      { -INT16_C(  4915), -INT16_C(  2388), -INT16_C(  9349), -INT16_C(  2343),  INT16_C(  9698),  INT16_C(  8815), -INT16_C(  4156),  INT16_C(  1826) } },
    { {  INT16_C(  2961),  INT16_C(  1384), -INT16_C(  2797),  INT16_C( 24189),  INT16_C( 29366), -INT16_C(  9091),  INT16_C( 19361),  INT16_C( 18343) },
       INT16_C( 24113),
      {  INT16_C(  2178),  INT16_C(  1018), -INT16_C(  2059),  INT16_C( 17799),  INT16_C( 21609), -INT16_C(  6690),  INT16_C( 14247),  INT16_C( 13498) } },
    { {  INT16_C( 20451), -INT16_C(  6586), -INT16_C(  6729), -INT16_C( 27069), -INT16_C( 21831), -INT16_C( 12887),  INT16_C( 15066),  INT16_C( 17112) },
      -INT16_C(  5313),
      { -INT16_C(  3316),  INT16_C(  1067),  INT16_C(  1091),  INT16_C(  4388),  INT16_C(  3539),  INT16_C(  2089), -INT16_C(  2443), -INT16_C(  2775) } },
    { { -INT16_C( 17352), -INT16_C(  4535), -INT16_C( 14546), -INT16_C( 12085),  INT16_C( 29202),  INT16_C( 17175), -INT16_C(  1071),  INT16_C(  6035) },
       INT16_C( 19169),
      { -INT16_C( 10151), -INT16_C(  2653), -INT16_C(  8510), -INT16_C(  7070),  INT16_C( 17082),  INT16_C( 10047), -INT16_C(   627),  INT16_C(  3530) } },
    { {  INT16_C(  9468), -INT16_C( 18976), -INT16_C( 30257), -INT16_C( 22142),  INT16_C( 23235),  INT16_C(   747),  INT16_C(  9030), -INT16_C( 28738) },
      -INT16_C(  4846),
      { -INT16_C(  1401),  INT16_C(  2806),  INT16_C(  4474),  INT16_C(  3274), -INT16_C(  3437), -INT16_C(   111), -INT16_C(  1336),  INT16_C(  4250) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    int16_t b = test_vec[i].b;
    simde_int16x8_t r = simde_vqdmulhq_n_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    int16_t b = simde_test_codegen_random_i16();
    simde_int16x8_t r = simde_vqdmulhq_n_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqdmulhq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  2139548107), -INT32_C(   680825287),  INT32_C(   263966920), -INT32_C(  1079092177) },
      -INT32_C(   126603836),
      { -INT32_C(   126136001),  INT32_C(    40137717), -INT32_C(    15562040),  INT32_C(    63617345) } },
    { {  INT32_C(  1824641013),  INT32_C(   262557231),  INT32_C(   748864865), -INT32_C(   391370321) },
       INT32_C(  1606358935),
      {  INT32_C(  1364866455),  INT32_C(   196397841),  INT32_C(   560165274), -INT32_C(   292752503) } },
    { {  INT32_C(   393181928), -INT32_C(  1680466474),  INT32_C(  1083394634),  INT32_C(  1236030490) },
       INT32_C(    72962722),
      {  INT32_C(    13358715), -INT32_C(    57095387),  INT32_C(    36809324),  INT32_C(    41995266) } },
    { { -INT32_C(   969868521), -INT32_C(  1129391068), -INT32_C(   602182156), -INT32_C(  1091335449) },
      -INT32_C(   228996696),
      {  INT32_C(   103421829),  INT32_C(   120432499),  INT32_C(    64213631),  INT32_C(   116374442) } },
    { {  INT32_C(   758311955), -INT32_C(   478683584),  INT32_C(  1223151664), -INT32_C(   267511861) },
      -INT32_C(   391332364),
      { -INT32_C(   138185923),  INT32_C(    87229711), -INT32_C(   222892888),  INT32_C(    48748240) } },
    { {  INT32_C(   314885930), -INT32_C(    86984878), -INT32_C(  1813239424),  INT32_C(  1438719765) },
       INT32_C(   775436541),
      {  INT32_C(   113702405), -INT32_C(    31409438), -INT32_C(   654744035),  INT32_C(   519508439) } },
    { { -INT32_C(   747233528),  INT32_C(   734233655),  INT32_C(  1813212993), -INT32_C(  1988176073) },
       INT32_C(   243486350),
      { -INT32_C(    84722957),  INT32_C(    83249003),  INT32_C(   205586018), -INT32_C(   225423712) } },
    { { -INT32_C(  1935577225), -INT32_C(  1931386226), -INT32_C(  1564861798),  INT32_C(  1886793785) },
      -INT32_C(   157599308),
      {  INT32_C(   142047941),  INT32_C(   141740372),  INT32_C(   114841915), -INT32_C(   138467828) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    int32_t b = test_vec[i].b;
    simde_int32x4_t r = simde_vqdmulhq_n_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    int32_t b = simde_test_codegen_random_i32();
    simde_int32x4_t r = simde_vqdmulhq_n_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulhq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulhq_n_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
