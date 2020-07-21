#define SIMDE_TEST_ARM_NEON_INSN mull_n

#include "test-neon.h"
#include "../../../simde/arm/neon/mull_n.h"

static int
test_simde_vmull_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b;
    int32_t r[4];
  } test_vec[] = {
    { {  INT16_C( 13839),  INT16_C( 23928), -INT16_C( 18368), -INT16_C( 26754) },
       INT16_C( 10433),
      {  INT32_C(   144382287),  INT32_C(   249640824), -INT32_C(   191633344), -INT32_C(   279124482) } },
    { {  INT16_C( 15140), -INT16_C(  7541), -INT16_C( 10338),  INT16_C( 14722) },
      -INT16_C(  2838),
      { -INT32_C(    42967320),  INT32_C(    21401358),  INT32_C(    29339244), -INT32_C(    41781036) } },
    { {  INT16_C( 30889),  INT16_C( 11965),  INT16_C( 10828), -INT16_C( 28246) },
      -INT16_C(  4452),
      { -INT32_C(   137517828), -INT32_C(    53268180), -INT32_C(    48206256),  INT32_C(   125751192) } },
    { { -INT16_C( 21453), -INT16_C( 21724),  INT16_C( 25865), -INT16_C( 30877) },
       INT16_C(  9468),
      { -INT32_C(   203117004), -INT32_C(   205682832),  INT32_C(   244889820), -INT32_C(   292343436) } },
    { {  INT16_C(  8368),  INT16_C( 15200), -INT16_C(   509), -INT16_C( 31470) },
      -INT16_C(   969),
      { -INT32_C(     8108592), -INT32_C(    14728800),  INT32_C(      493221),  INT32_C(    30494430) } },
    { { -INT16_C(  7815),  INT16_C( 14196), -INT16_C( 16369), -INT16_C( 18079) },
      -INT16_C(   430),
      {  INT32_C(     3360450), -INT32_C(     6104280),  INT32_C(     7038670),  INT32_C(     7773970) } },
    { { -INT16_C( 31321), -INT16_C( 13142), -INT16_C( 19664), -INT16_C( 27855) },
       INT16_C( 11578),
      { -INT32_C(   362634538), -INT32_C(   152158076), -INT32_C(   227669792), -INT32_C(   322505190) } },
    { { -INT16_C(  5449),  INT16_C(  5965),  INT16_C( 20518),  INT16_C( 14358) },
       INT16_C( 19926),
      { -INT32_C(   108576774),  INT32_C(   118858590),  INT32_C(   408841668),  INT32_C(   286097508) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    int16_t b = test_vec[i].b;
    simde_int32x4_t r = simde_vmull_n_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    int16_t b = simde_test_codegen_random_i16();
    simde_int32x4_t r = simde_vmull_n_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b;
    int64_t r[2];
  } test_vec[] = {
    { { -INT32_C(   899636787),  INT32_C(   823949875) },
      -INT32_C(   936755039),
      {  INT64_C(  842739293492019693), -INT64_C(  771839197289670125) } },
    { {  INT32_C(   676491476),  INT32_C(   189564474) },
      -INT32_C(    38164631),
      { -INT64_C(   25818047556185356), -INT64_C(    7234658200919094) } },
    { { -INT32_C(   883789225), -INT32_C(   768140539) },
      -INT32_C(   274884676),
      {  INT64_C(  242940114766416100),  INT64_C(  211150063185480364) } },
    { { -INT32_C(  1289635567), -INT32_C(   847557639) },
      -INT32_C(   168440389),
      {  INT64_C(  217226716573715563),  INT64_C(  142762938413081571) } },
    { { -INT32_C(  1123990956),  INT32_C(  1085979369) },
       INT32_C(   839650349),
      { -INT64_C(  943759398478243644),  INT64_C(  911842956187649781) } },
    { { -INT32_C(   486194393), -INT32_C(   338451750) },
       INT32_C(  1419703387),
      { -INT64_C(  690251826482509091), -INT64_C(  480501095811077250) } },
    { { -INT32_C(    98428353),  INT32_C(  1005590503) },
       INT32_C(  1140388185),
      { -INT64_C(  112246530830209305),  INT64_C( 1146763528569407055) } },
    { { -INT32_C(   662457685), -INT32_C(   435449921) },
      -INT32_C(  1396043566),
      {  INT64_C(  924819788891504710),  INT64_C(  607907060527258286) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    int32_t b = test_vec[i].b;
    simde_int64x2_t r = simde_vmull_n_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    int32_t b = simde_test_codegen_random_i32();
    simde_int64x2_t r = simde_vmull_n_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(51213), UINT16_C(42159), UINT16_C(16985), UINT16_C(41215) },
      UINT16_C(47519),
      { UINT32_C(2433590547), UINT32_C(2003353521), UINT32_C( 807110215), UINT32_C(1958495585) } },
    { { UINT16_C( 7629), UINT16_C(55608), UINT16_C(36497), UINT16_C(36334) },
      UINT16_C(19590),
      { UINT32_C( 149452110), UINT32_C(1089360720), UINT32_C( 714976230), UINT32_C( 711783060) } },
    { { UINT16_C(25666), UINT16_C(13699), UINT16_C(51873), UINT16_C( 1864) },
      UINT16_C(33004),
      { UINT32_C( 847080664), UINT32_C( 452121796), UINT32_C(1712016492), UINT32_C(  61519456) } },
    { { UINT16_C(64206), UINT16_C(32072), UINT16_C(41374), UINT16_C(40383) },
      UINT16_C(24129),
      { UINT32_C(1549226574), UINT32_C( 773865288), UINT32_C( 998313246), UINT32_C( 974401407) } },
    { { UINT16_C( 3926), UINT16_C(36476), UINT16_C( 3560), UINT16_C(54813) },
      UINT16_C(41882),
      { UINT32_C( 164428732), UINT32_C(1527687832), UINT32_C( 149099920), UINT32_C(2295678066) } },
    { { UINT16_C(56354), UINT16_C(42248), UINT16_C(43281), UINT16_C(22896) },
      UINT16_C(23728),
      { UINT32_C(1337167712), UINT32_C(1002460544), UINT32_C(1026971568), UINT32_C( 543276288) } },
    { { UINT16_C(32473), UINT16_C( 8790), UINT16_C(62716), UINT16_C(48067) },
      UINT16_C( 1425),
      { UINT32_C(  46274025), UINT32_C(  12525750), UINT32_C(  89370300), UINT32_C(  68495475) } },
    { { UINT16_C(59162), UINT16_C(38420), UINT16_C(64630), UINT16_C(37795) },
      UINT16_C(15827),
      { UINT32_C( 936356974), UINT32_C( 608073340), UINT32_C(1022899010), UINT32_C( 598181465) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    uint16_t b = test_vec[i].b;
    simde_uint32x4_t r = simde_vmull_n_u16(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    uint16_t b = simde_test_codegen_random_u16();
    simde_uint32x4_t r = simde_vmull_n_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b;
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C(1324541274), UINT32_C( 832398216) },
      UINT32_C(4043693192),
      { UINT64_C( 5356038532196806608), UINT64_C( 3365962999072145472) } },
    { { UINT32_C( 612019424), UINT32_C( 590534729) },
      UINT32_C( 946752278),
      { UINT64_C(  579430783852247872), UINT64_C(  559090099918862662) } },
    { { UINT32_C(2626716765), UINT32_C(2899880274) },
      UINT32_C( 385534606),
      { UINT64_C( 1012690213067869590), UINT64_C( 1118004198883762044) } },
    { { UINT32_C(3058145069), UINT32_C(1420250483) },
      UINT32_C(1131946489),
      { UINT64_C( 3461656573707212741), UINT64_C( 1607647547732404187) } },
    { { UINT32_C( 275163898), UINT32_C(1397347574) },
      UINT32_C(2867845464),
      { UINT64_C(  789127536735858672), UINT64_C( 4007376901727304336) } },
    { { UINT32_C( 290899842), UINT32_C(3207025042) },
      UINT32_C(1551200232),
      { UINT64_C(  451243902399163344), UINT64_C( 4974737989180209744) } },
    { { UINT32_C(3048217788), UINT32_C( 955787326) },
      UINT32_C(3360186066),
      { UINT64_C(10242578937370942008), UINT64_C( 3211623254884599516) } },
    { { UINT32_C(2317062450), UINT32_C(3979610731) },
      UINT32_C(1694403538),
      { UINT64_C( 3926038813046948100), UINT64_C( 6743066502469166278) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    uint32_t b = test_vec[i].b;
    simde_uint64x2_t r = simde_vmull_n_u32(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    uint32_t b = simde_test_codegen_random_u32();
    simde_uint64x2_t r = simde_vmull_n_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_n_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
