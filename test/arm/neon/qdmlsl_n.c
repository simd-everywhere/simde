#define SIMDE_TEST_ARM_NEON_INSN qdmlsl_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmlsl_n.h"

static int
test_simde_vqdmlsl_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t c;
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C(  935711740), -INT32_C(  174833550),  INT32_C(  106453999),  INT32_C(  245894372) },
       {   INT16_C(       1965),  INT16_C(       1506),  INT16_C(       2690),  INT16_C(       4335) },
          -INT16_C(       2827),
       {  -INT32_C(  924601630), -INT32_C(  166318626),  INT32_C(  121663259),  INT32_C(  270404462) } },
     { {  -INT32_C(  313218121),  INT32_C(  514593261),  INT32_C(  113708453), -INT32_C(  457187134) },
       {   INT16_C(       7234), -INT16_C(       2542),  INT16_C(       3459),  INT16_C(       1686) },
           INT16_C(       4704),
       {  -INT32_C(  381275593),  INT32_C(  538508397),  INT32_C(   81166181), -INT32_C(  473049022) } },
     { {   INT32_C(  759935558), -INT32_C(  626391621),  INT32_C(  615534132), -INT32_C(  892142678) },
       {   INT16_C(       6619), -INT16_C(       4481), -INT16_C(       3925), -INT16_C(       6032) },
          -INT16_C(       9956),
       {   INT32_C(  891733086), -INT32_C(  715617293),  INT32_C(  537379532), -INT32_C( 1012251862) } },
     { {   INT32_C(  818873993), -INT32_C(  234231128),  INT32_C(  355806293),  INT32_C(  207837591) },
       {  -INT16_C(       8958), -INT16_C(       2651), -INT16_C(       4422),  INT16_C(        715) },
          -INT16_C(        583),
       {   INT32_C(  808428965), -INT32_C(  237322194),  INT32_C(  350650241),  INT32_C(  208671281) } },
     { {   INT32_C(  189083357), -INT32_C(  239902463), -INT32_C(  710218023),  INT32_C(  840478160) },
       {  -INT16_C(       7670), -INT16_C(       3502),  INT16_C(       7539),  INT16_C(       9706) },
          -INT16_C(       5400),
       {   INT32_C(  106247357), -INT32_C(  277724063), -INT32_C(  628796823),  INT32_C(  945302960) } },
     { {  -INT32_C(  502897175), -INT32_C(  980374196), -INT32_C(   10005067), -INT32_C(  375058653) },
       {   INT16_C(       1640), -INT16_C(       4598),  INT16_C(       9885),  INT16_C(       8382) },
          -INT16_C(       8565),
       {  -INT32_C(  474803975), -INT32_C( 1059137936),  INT32_C(  159324983), -INT32_C(  231474993) } },
     { {   INT32_C(  229618807), -INT32_C(  935038912), -INT32_C(  116926710), -INT32_C(  488341902) },
       {  -INT16_C(        121), -INT16_C(        657),  INT16_C(       7582),  INT16_C(       8753) },
           INT16_C(       7378),
       {   INT32_C(  231404283), -INT32_C(  925344220), -INT32_C(  228806702), -INT32_C(  617501170) } },
     { {   INT32_C(  318577636),  INT32_C(  142621378),  INT32_C(  303755248), -INT32_C(  344132925) },
       {  -INT16_C(       9606), -INT16_C(       5322), -INT16_C(       1423), -INT16_C(       2335) },
          -INT16_C(       7502),
       {   INT32_C(  174449212),  INT32_C(   62770090),  INT32_C(  282404556), -INT32_C(  379167265) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    int16_t c = test_vec[i].c;
    simde_int32x4_t r = simde_vqdmlsl_n_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlsl_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t c;
    int64_t r[2];
  } test_vec[] = {
     { {  -INT64_C(  200123535528), -INT64_C(    4196102740) },
       {   INT32_C(        232016), -INT32_C(         55014) },
          -INT32_C(        379867),
       {  -INT64_C(   23853091784), -INT64_C(   45992109016) } },
     { {  -INT64_C(  769211607541), -INT64_C(  516930045720) },
       {   INT32_C(         82118), -INT32_C(        235106) },
           INT32_C(        231882),
       {  -INT64_C(  807294979693), -INT64_C(  407896346736) } },
     { {  -INT64_C(  356278515063), -INT64_C(  966670001608) },
       {   INT32_C(        495024), -INT32_C(         81655) },
          -INT32_C(        478421),
       {   INT64_C(  117381239145), -INT64_C( 1044800935118) } },
     { {   INT64_C(  323130192131), -INT64_C(  909576347809) },
       {  -INT32_C(        876218), -INT32_C(        242467) },
           INT32_C(        984152),
       {   INT64_C( 2047793586403), -INT64_C(  432327581841) } },
     { {  -INT64_C(  354762330196), -INT64_C(  733420261758) },
       {   INT32_C(        770483),  INT32_C(         57616) },
           INT32_C(        722037),
       {  -INT64_C( 1467396797938), -INT64_C(  816622029342) } },
     { {   INT64_C(  804115288272),  INT64_C(  931414127562) },
       {   INT32_C(        709174),  INT32_C(         19060) },
          -INT32_C(        631167),
       {   INT64_C( 1699329740388),  INT64_C(  955474213602) } },
     { {   INT64_C(  583614899765),  INT64_C(   20498852161) },
       {   INT32_C(         98775), -INT32_C(        624312) },
          -INT32_C(        609430),
       {   INT64_C(  704007796265), -INT64_C(  740450072159) } },
     { {   INT64_C(  509016843325), -INT64_C(  340472500451) },
       {  -INT32_C(        331014), -INT32_C(        715967) },
           INT32_C(        784785),
       {   INT64_C( 1028566487305),  INT64_C(  783287823739) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    int32_t c = test_vec[i].c;
    simde_int64x2_t r = simde_vqdmlsl_n_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_n_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
