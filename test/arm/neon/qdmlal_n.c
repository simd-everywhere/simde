#define SIMDE_TEST_ARM_NEON_INSN qdmlal_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmlal_n.h"

static int
test_simde_vqdmlal_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t c;
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C( 705275087), -INT32_C( 127604877),  INT32_C( 965818803), -INT32_C( 877396080) },
       {  -INT16_C(      9923),  INT16_C(      4614), -INT16_C(      6282),  INT16_C(      3021) },
          -INT16_C(      9646),
       {  -INT32_C( 513840571), -INT32_C( 216618165),  INT32_C(1087011147), -INT32_C( 935677212) } },
     { {  -INT32_C( 199952352),  INT32_C( 215320872), -INT32_C( 731192087),  INT32_C( 378983641) },
       {  -INT16_C(      2857),  INT16_C(      5541),  INT16_C(      1348), -INT16_C(       145) },
          -INT16_C(      5488),
       {  -INT32_C( 168593920),  INT32_C( 154502856), -INT32_C( 745987735),  INT32_C( 380575161) } },
     { {   INT32_C( 345416712), -INT32_C( 190883663),  INT32_C( 531028224), -INT32_C( 971088060) },
       {   INT16_C(      6843),  INT16_C(      5246),  INT16_C(      3959), -INT16_C(      5365) },
          -INT16_C(      1224),
       {   INT32_C( 328665048), -INT32_C( 203725871),  INT32_C( 521336592), -INT32_C( 957954540) } },
     { {   INT32_C( 431788782),  INT32_C( 304549383),  INT32_C( 187075575),  INT32_C( 225465734) },
       {  -INT16_C(      1437), -INT16_C(      1082),  INT16_C(      8813), -INT16_C(      1659) },
           INT16_C(      7091),
       {   INT32_C( 411409248),  INT32_C( 289204459),  INT32_C( 312061541),  INT32_C( 201937796) } },
     { {  -INT32_C( 842968502), -INT32_C( 122274056), -INT32_C( 112994603),  INT32_C( 752609068) },
       {  -INT16_C(      4912), -INT16_C(      7400), -INT16_C(      1633),  INT16_C(      1737) },
          -INT16_C(      6069),
       {  -INT32_C( 783346646), -INT32_C(  32452856), -INT32_C(  93173249),  INT32_C( 731525362) } },
     { {   INT32_C( 631739237),  INT32_C( 980023855), -INT32_C( 761772772),  INT32_C( 225384826) },
       {  -INT16_C(      4239),  INT16_C(      4739),  INT16_C(      7055), -INT16_C(      1077) },
           INT16_C(      5831),
       {   INT32_C( 582304019),  INT32_C(1035290073), -INT32_C( 679497362),  INT32_C( 212824852) } },
     { {   INT32_C( 650751202),  INT32_C( 457968199), -INT32_C( 410210956), -INT32_C( 454399268) },
       {  -INT16_C(      4801), -INT16_C(      2204), -INT16_C(      2220),  INT16_C(      2537) },
          -INT16_C(      9442),
       {   INT32_C( 741413286),  INT32_C( 499588535), -INT32_C( 368288476), -INT32_C( 502307976) } },
     { {   INT32_C( 978331563),  INT32_C( 479187906), -INT32_C( 939479917), -INT32_C( 326678923) },
       {  -INT16_C(      7412), -INT16_C(       248), -INT16_C(      2162),  INT16_C(      8922) },
           INT16_C(      3247),
       {   INT32_C( 930198035),  INT32_C( 477577394), -INT32_C( 953519945), -INT32_C( 268739455) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    int16_t c = test_vec[i].c;
    simde_int32x4_t r = simde_vqdmlal_n_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlal_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t c;
    int64_t r[2];
  } test_vec[] = {
     { {  -INT64_C( 376165768222), -INT64_C( 197324743023) },
       {   INT32_C(       741465),  INT32_C(       968010) },
           INT32_C(        66342),
       {  -INT64_C( 277785226162), -INT64_C(  68885304183) } },
     { {   INT64_C( 251135060065),  INT64_C( 497199393432) },
       {  -INT32_C(       404762), -INT32_C(       230075) },
           INT32_C(       244631),
       {   INT64_C(  53100394421),  INT64_C( 384632438782) } },
     { {  -INT64_C( 988894543133),  INT64_C( 682999452113) },
       {   INT32_C(       260054),  INT32_C(       105828) },
           INT32_C(       331400),
       {  -INT64_C( 816530751933),  INT64_C( 753142250513) } },
     { {   INT64_C( 705468518678), -INT64_C( 195976812580) },
       {   INT32_C(       106637), -INT32_C(       254619) },
           INT32_C(       660228),
       {   INT64_C( 846277985150), -INT64_C( 532189998844) } },
     { {   INT64_C( 494136024340), -INT64_C( 606948135213) },
       {  -INT32_C(       691910), -INT32_C(       551857) },
           INT32_C(       155068),
       {   INT64_C( 279549824580), -INT64_C( 778098857765) } },
     { {   INT64_C( 154024385460),  INT64_C( 607600790766) },
       {   INT32_C(       674527), -INT32_C(       109728) },
           INT32_C(         6749),
       {   INT64_C( 163129150906),  INT64_C( 606119682222) } },
     { {  -INT64_C( 422189543539), -INT64_C( 471989869341) },
       {   INT32_C(       260659),  INT32_C(       621255) },
          -INT32_C(       195916),
       {  -INT64_C( 524324080827), -INT64_C( 715417458501) } },
     { {   INT64_C(  13880703167),  INT64_C( 146406296842) },
       {  -INT32_C(       403731), -INT32_C(       674292) },
           INT32_C(       504404),
       {  -INT64_C( 393406359481), -INT64_C( 533824867094) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    int32_t c = test_vec[i].c;
    simde_int64x2_t r = simde_vqdmlal_n_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_n_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
