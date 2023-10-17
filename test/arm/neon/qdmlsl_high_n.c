#define SIMDE_TEST_ARM_NEON_INSN qdmlsl_high_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmlsl_high_n.h"

static int
test_simde_vqdmlsl_high_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t c;
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C(  655584482), -INT32_C(  721040519), -INT32_C(    4516362),  INT32_C(  510063637) },
       {  -INT16_C(       5717),  INT16_C(       6177),  INT16_C(        153), -INT16_C(       1588),
          -INT16_C(       6665),  INT16_C(       6259),  INT16_C(       3384),  INT16_C(       8410) },
          -INT16_C(       9983),
       {  -INT32_C(  788657872), -INT32_C(  596073325),  INT32_C(   63048582),  INT32_C(  677977697) } },
     { {   INT32_C(  443613837), -INT32_C(  161043501),  INT32_C(  110704618), -INT32_C(  962257269) },
       {   INT16_C(         59), -INT16_C(       1856),  INT16_C(       4217),  INT16_C(       3280),
          -INT16_C(       6369), -INT16_C(       8539),  INT16_C(       8599), -INT16_C(       1395) },
          -INT16_C(       6689),
       {   INT32_C(  358409355), -INT32_C(  275278243),  INT32_C(  225742040), -INT32_C(  980919579) } },
     { {  -INT32_C(  851285066),  INT32_C(  392036614), -INT32_C(  390856728), -INT32_C(  522161257) },
       {  -INT16_C(       1292), -INT16_C(       7545),  INT16_C(       2123),  INT16_C(        132),
           INT16_C(       4355),  INT16_C(       5159), -INT16_C(       3713),  INT16_C(       4367) },
          -INT16_C(       8562),
       {  -INT32_C(  776710046),  INT32_C(  480379330), -INT32_C(  454438140), -INT32_C(  447380749) } },
     { {   INT32_C(  528779912),  INT32_C(  848404208),  INT32_C(  109131611), -INT32_C(  774639392) },
       {  -INT16_C(       3475),  INT16_C(       3429),  INT16_C(       3780), -INT16_C(       9623),
          -INT16_C(       9851),  INT16_C(       5785), -INT16_C(       5027), -INT16_C(       2381) },
           INT16_C(       3357),
       {   INT32_C(  594919526),  INT32_C(  809563718),  INT32_C(  142882889), -INT32_C(  758653358) } },
     { {   INT32_C(  195157916), -INT32_C(  601064983),  INT32_C(  339151195),  INT32_C(  530998669) },
       {  -INT16_C(       4660), -INT16_C(       7367), -INT16_C(       3008),  INT16_C(        517),
           INT16_C(       2165),  INT16_C(       7141),  INT16_C(       5136), -INT16_C(       5170) },
          -INT16_C(       8388),
       {   INT32_C(  231477956), -INT32_C(  481267567),  INT32_C(  425312731),  INT32_C(  444266749) } },
     { {  -INT32_C(  300840527), -INT32_C(  869355563),  INT32_C(  235756236), -INT32_C(  556959564) },
       {  -INT16_C(       4759), -INT16_C(       2892), -INT16_C(       4998), -INT16_C(        970),
           INT16_C(       3072),  INT16_C(       8931), -INT16_C(       6658),  INT16_C(       3886) },
          -INT16_C(        558),
       {  -INT32_C(  297412175), -INT32_C(  859388567),  INT32_C(  228325908), -INT32_C(  552622788) } },
     { {   INT32_C(  889226968),  INT32_C(  577849988),  INT32_C(  511737493),  INT32_C(  820971206) },
       {   INT16_C(       2514), -INT16_C(       9068), -INT16_C(       8024), -INT16_C(       6544),
          -INT16_C(       9798), -INT16_C(       4286), -INT16_C(       8686),  INT16_C(       9288) },
           INT16_C(       8725),
       {   INT32_C( 1060202068),  INT32_C(  652640688),  INT32_C(  663308193),  INT32_C(  658895606) } },
     { {   INT32_C(  999975609),  INT32_C(   62995935),  INT32_C(  262692963),  INT32_C(  517089321) },
       {   INT16_C(       6627),  INT16_C(       7183), -INT16_C(       4468),  INT16_C(       2605),
          -INT16_C(       9265),  INT16_C(       3099), -INT16_C(       1349), -INT16_C(       6470) },
          -INT16_C(       6407),
       {   INT32_C(  881253899),  INT32_C(  102706521),  INT32_C(  245406877),  INT32_C(  434182741) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    int16_t c = test_vec[i].c;
    simde_int32x4_t r = simde_vqdmlsl_high_n_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlsl_high_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t c;
    int64_t r[2];
  } test_vec[] = {
     { {  -INT64_C(  924633394176), -INT64_C(  580110049271) },
       {   INT32_C(        794833),  INT32_C(        660637), -INT32_C(        707676),  INT32_C(        154834) },
           INT32_C(        120564),
       {  -INT64_C(  753992895648), -INT64_C(  617444862023) } },
     { {   INT64_C(  582717418070), -INT64_C(  391739747873) },
       {  -INT32_C(        520175), -INT32_C(        988116),  INT32_C(        599353), -INT32_C(        906696) },
          -INT32_C(        350146),
       {   INT64_C( 1002439529146), -INT64_C( 1026691703105) } },
     { {  -INT64_C(  123627170620), -INT64_C(  222977168930) },
       {  -INT32_C(        844801),  INT32_C(         71993),  INT32_C(        530543), -INT32_C(        733850) },
           INT32_C(        147888),
       {  -INT64_C(  280549056988), -INT64_C(    5921951330) } },
     { {   INT64_C(  863371662593),  INT64_C(  776848419902) },
       {  -INT32_C(        813235), -INT32_C(        882166),  INT32_C(        482897), -INT32_C(        956511) },
           INT32_C(        977218),
       {  -INT64_C(   80419618499),  INT64_C( 2646287952698) } },
     { {  -INT64_C(  255406064309), -INT64_C(  777654343951) },
       {   INT32_C(        140558), -INT32_C(        856574), -INT32_C(        425078), -INT32_C(        578417) },
          -INT32_C(        948359),
       {  -INT64_C( 1061659158313), -INT64_C( 1874748279357) } },
     { {  -INT64_C(  458810764855),  INT64_C(  711787430179) },
       {   INT32_C(        805923), -INT32_C(        468847),  INT32_C(        690525),  INT32_C(        713403) },
           INT32_C(        640126),
       {  -INT64_C( 1342856777155), -INT64_C(  201548187377) } },
     { {   INT64_C(  758182015630),  INT64_C(  506525147029) },
       {   INT32_C(        830864), -INT32_C(        705600), -INT32_C(        726060), -INT32_C(        605205) },
           INT32_C(        945162),
       {   INT64_C( 2130670659070),  INT64_C( 1650558683449) } },
     { {   INT64_C(  128332029081), -INT64_C(  342906652550) },
       {  -INT32_C(        664547), -INT32_C(        618870), -INT32_C(        428918), -INT32_C(        969644) },
           INT32_C(        907914),
       {   INT64_C(  907173343185),  INT64_C( 1417800072682) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    int32_t c = test_vec[i].c;
    simde_int64x2_t r = simde_vqdmlsl_high_n_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_high_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_high_n_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
