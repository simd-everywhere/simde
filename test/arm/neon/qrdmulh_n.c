#define SIMDE_TEST_ARM_NEON_INSN qrdmulh_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qrdmulh_n.h"

static int
test_simde_vqrdmulh_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b;
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 18176), -INT16_C( 30703),  INT16_C( 10850),  INT16_C( 27817) },
       INT16_C( 18000),
      { -INT16_C(  9984), -INT16_C( 16866),  INT16_C(  5960),  INT16_C( 15280) } },
    { { -INT16_C(  2714), -INT16_C(  3736),  INT16_C( 28840), -INT16_C( 15962) },
      -INT16_C( 25764),
      {  INT16_C(  2134),  INT16_C(  2937), -INT16_C( 22676),  INT16_C( 12550) } },
    { {  INT16_C( 22294),  INT16_C( 23953), -INT16_C( 23491),  INT16_C(  1951) },
       INT16_C( 12290),
      {  INT16_C(  8362),  INT16_C(  8984), -INT16_C(  8811),  INT16_C(   732) } },
    { {  INT16_C(   808),  INT16_C( 15082),  INT16_C( 19595),  INT16_C( 13412) },
      -INT16_C( 19272),
      { -INT16_C(   475), -INT16_C(  8870), -INT16_C( 11525), -INT16_C(  7888) } },
    { {  INT16_C(  8059), -INT16_C(  7254),  INT16_C( 21008), -INT16_C( 18861) },
      -INT16_C( 20716),
      { -INT16_C(  5095),  INT16_C(  4586), -INT16_C( 13281),  INT16_C( 11924) } },
    { {  INT16_C( 10833), -INT16_C(  7674),  INT16_C( 17544),  INT16_C( 10119) },
      -INT16_C( 30389),
      { -INT16_C( 10047),  INT16_C(  7117), -INT16_C( 16270), -INT16_C(  9384) } },
    { {  INT16_C( 29527),  INT16_C( 16780),  INT16_C(  6061),  INT16_C(  4493) },
       INT16_C( 17996),
      {  INT16_C( 16216),  INT16_C(  9215),  INT16_C(  3329),  INT16_C(  2468) } },
    { { -INT16_C( 14394),  INT16_C( 28773),  INT16_C( 30122), -INT16_C(   574) },
      -INT16_C( 10708),
      {  INT16_C(  4704), -INT16_C(  9403), -INT16_C(  9843),  INT16_C(   188) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    int16_t b = test_vec[i].b;
    simde_int16x4_t r = simde_vqrdmulh_n_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    int16_t b = simde_test_codegen_random_i16();
    simde_int16x4_t r = simde_vqrdmulh_n_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulh_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(   544357201), -INT32_C(  1702801489) },
      -INT32_C(   246487516),
      {  INT32_C(    62481153),  INT32_C(   195447034) } },
    { {  INT32_C(   906206034),  INT32_C(   993962082) },
       INT32_C(  1984742686),
      {  INT32_C(   837531778),  INT32_C(   918637483) } },
    { { -INT32_C(   521306617), -INT32_C(    54329012) },
       INT32_C(  1960530373),
      { -INT32_C(   475923278), -INT32_C(    49599296) } },
    { { -INT32_C(   988848992), -INT32_C(  1783210685) },
       INT32_C(  1523301112),
      { -INT32_C(   701432474), -INT32_C(  1264906870) } },
    { { -INT32_C(  2120939166), -INT32_C(   705175090) },
      -INT32_C(  1397300128),
      {  INT32_C(  1380028468),  INT32_C(   458835272) } },
    { { -INT32_C(  1415022106),  INT32_C(  1797293258) },
       INT32_C(   590360544),
      { -INT32_C(   389000969),  INT32_C(   494090386) } },
    { { -INT32_C(  2068257140),  INT32_C(    64979872) },
       INT32_C(  1535407245),
      { -INT32_C(  1478761899),  INT32_C(    46459290) } },
    { { -INT32_C(  1238271146),  INT32_C(  1164109663) },
       INT32_C(   737217376),
      { -INT32_C(   425090550),  INT32_C(   399631388) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    int32_t b = test_vec[i].b;
    simde_int32x2_t r = simde_vqrdmulh_n_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    int32_t b = simde_test_codegen_random_i32();
    simde_int32x2_t r = simde_vqrdmulh_n_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b;
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  1031),  INT16_C( 19322), -INT16_C( 26994), -INT16_C(  9878),  INT16_C( 10242),  INT16_C( 17924), -INT16_C( 30389), -INT16_C( 31196) },
      -INT16_C( 26280),
      {  INT16_C(   827), -INT16_C( 15496),  INT16_C( 21649),  INT16_C(  7922), -INT16_C(  8214), -INT16_C( 14375),  INT16_C( 24372),  INT16_C( 25019) } },
    { { -INT16_C( 19624),  INT16_C( 22844),  INT16_C( 16624), -INT16_C( 26808),  INT16_C( 20694), -INT16_C( 32011), -INT16_C(  4479), -INT16_C(   899) },
       INT16_C(  3130),
      { -INT16_C(  1874),  INT16_C(  2182),  INT16_C(  1588), -INT16_C(  2561),  INT16_C(  1977), -INT16_C(  3058), -INT16_C(   428), -INT16_C(    86) } },
    { { -INT16_C( 23406), -INT16_C( 27419), -INT16_C(  5684),  INT16_C(  6106), -INT16_C(   142), -INT16_C( 13411), -INT16_C(  2664), -INT16_C( 11138) },
       INT16_C( 28494),
      { -INT16_C( 20353), -INT16_C( 23843), -INT16_C(  4943),  INT16_C(  5310), -INT16_C(   123), -INT16_C( 11662), -INT16_C(  2317), -INT16_C(  9685) } },
    { { -INT16_C( 27115), -INT16_C(  5370), -INT16_C(   794),  INT16_C( 26733), -INT16_C(  5142),  INT16_C(  9316), -INT16_C(  2313), -INT16_C(  9016) },
      -INT16_C( 27510),
      {  INT16_C( 22764),  INT16_C(  4508),  INT16_C(   667), -INT16_C( 22443),  INT16_C(  4317), -INT16_C(  7821),  INT16_C(  1942),  INT16_C(  7569) } },
    { {  INT16_C( 25798),  INT16_C( 14507),  INT16_C( 18531), -INT16_C(  1021), -INT16_C( 32194), -INT16_C( 29488), -INT16_C(  6671), -INT16_C(  2269) },
       INT16_C(  2513),
      {  INT16_C(  1978),  INT16_C(  1113),  INT16_C(  1421), -INT16_C(    78), -INT16_C(  2469), -INT16_C(  2261), -INT16_C(   512), -INT16_C(   174) } },
    { {  INT16_C( 16115), -INT16_C(  8591), -INT16_C( 10967),  INT16_C(  8194), -INT16_C( 13365),  INT16_C( 22013), -INT16_C( 15521),  INT16_C(  3002) },
       INT16_C(  7675),
      {  INT16_C(  3774), -INT16_C(  2012), -INT16_C(  2569),  INT16_C(  1919), -INT16_C(  3130),  INT16_C(  5156), -INT16_C(  3635),  INT16_C(   703) } },
    { { -INT16_C(   173), -INT16_C( 28391), -INT16_C(  5503),  INT16_C( 29214),  INT16_C( 16847), -INT16_C( 24471),  INT16_C( 23882), -INT16_C( 17185) },
       INT16_C(  2107),
      { -INT16_C(    11), -INT16_C(  1826), -INT16_C(   354),  INT16_C(  1878),  INT16_C(  1083), -INT16_C(  1573),  INT16_C(  1536), -INT16_C(  1105) } },
    { {  INT16_C( 15761),  INT16_C( 23849),  INT16_C(  9736),  INT16_C( 26802),  INT16_C( 27881), -INT16_C(  7053), -INT16_C( 14710), -INT16_C( 23581) },
       INT16_C( 25688),
      {  INT16_C( 12356),  INT16_C( 18696),  INT16_C(  7632),  INT16_C( 21011),  INT16_C( 21857), -INT16_C(  5529), -INT16_C( 11532), -INT16_C( 18486) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    int16_t b = test_vec[i].b;
    simde_int16x8_t r = simde_vqrdmulhq_n_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    int16_t b = simde_test_codegen_random_i16();
    simde_int16x8_t r = simde_vqrdmulhq_n_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b;
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1155602282), -INT32_C(   998396914), -INT32_C(   467948871), -INT32_C(   835337376) },
       INT32_C(   781379465),
      { -INT32_C(   420475329), -INT32_C(   363274872), -INT32_C(   170267019), -INT32_C(   303944327) } },
    { { -INT32_C(  1502344877),  INT32_C(   774603804),  INT32_C(  1942974173),  INT32_C(  1697574230) },
       INT32_C(  1395239833),
      { -INT32_C(   976087253),  INT32_C(   503267200),  INT32_C(  1262368150),  INT32_C(  1102929555) } },
    { { -INT32_C(  1237892010), -INT32_C(  1870369785), -INT32_C(  1497491885),  INT32_C(   994849311) },
      -INT32_C(  1804961865),
      {  INT32_C(  1040449306),  INT32_C(  1572047423),  INT32_C(  1258643226), -INT32_C(   836171707) } },
    { {  INT32_C(  1007106533), -INT32_C(  1063176921),  INT32_C(   907266784),  INT32_C(   367806990) },
       INT32_C(   161837238),
      {  INT32_C(    75896894), -INT32_C(    80122434),  INT32_C(    68372837),  INT32_C(    27718426) } },
    { { -INT32_C(  1498455161),  INT32_C(  1289944213),  INT32_C(  1507871859), -INT32_C(  1399462011) },
      -INT32_C(    43174372),
      {  INT32_C(    30125892), -INT32_C(    25933856), -INT32_C(    30315211),  INT32_C(    28135671) } },
    { {  INT32_C(   238256128), -INT32_C(  2128404277),  INT32_C(   395036816), -INT32_C(  1061275093) },
      -INT32_C(  1441947594),
      { -INT32_C(   159979263),  INT32_C(  1429136575), -INT32_C(   265251094),  INT32_C(   712602896) } },
    { {  INT32_C(  1896082924), -INT32_C(   249653035), -INT32_C(   823227442), -INT32_C(   690216437) },
      -INT32_C(   765919422),
      { -INT32_C(   676255085),  INT32_C(    89041008),  INT32_C(   293611496),  INT32_C(   246171921) } },
    { { -INT32_C(   219487289),  INT32_C(  1420994589),  INT32_C(   889110344), -INT32_C(  2103115347) },
       INT32_C(  1735639961),
      { -INT32_C(   177394091),  INT32_C(  1148476728),  INT32_C(   718597063), -INT32_C(  1699780598) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    int32_t b = test_vec[i].b;
    simde_int32x4_t r = simde_vqrdmulhq_n_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    int32_t b = simde_test_codegen_random_i32();
    simde_int32x4_t r = simde_vqrdmulhq_n_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulh_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulh_n_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhq_n_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
