#define SIMDE_TEST_ARM_NEON_INSN mull_high_n

#include "test-neon.h"
#include "../../../simde/arm/neon/mull_high_n.h"

static int
test_simde_vmull_high_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b;
    int32_t r[4];
  } test_vec[] = {
    { { -INT16_C(   25453), -INT16_C(   19709),  INT16_C(    1285), -INT16_C(   24707),
        -INT16_C(    5239),  INT16_C(   29164), -INT16_C(    9515), -INT16_C(   22416) },
        -INT16_C(    8423),
      {  INT32_C(44128097), -INT32_C(245648372),  INT32_C(80144845),  INT32_C(188809968) } },
    { {  INT16_C(   10007),  INT16_C(   18982), -INT16_C(   22644),  INT16_C(    7687),
         INT16_C(   16896), -INT16_C(   29454), -INT16_C(    8001), -INT16_C(   23410) },
         INT16_C(   17740),
      {  INT32_C(299735040), -INT32_C(522513960), -INT32_C(141937740), -INT32_C(415293400) } },
    { { -INT16_C(   21048), -INT16_C(   19345), -INT16_C(   27170),  INT16_C(   21667),
         INT16_C(   26123), -INT16_C(   27863),  INT16_C(   19649),  INT16_C(   16928) },
         INT16_C(   21067),
      {  INT32_C(550333241), -INT32_C(586989821),  INT32_C(413945483),  INT32_C(356622176) } },
    { {  INT16_C(   13572), -INT16_C(    2077),  INT16_C(   10157), -INT16_C(    2177),
        -INT16_C(   17259), -INT16_C(    3005), -INT16_C(   25638),  INT16_C(   21271) },
        -INT16_C(   13999),
      {  INT32_C(241608741),  INT32_C(42066995),  INT32_C(358906362), -INT32_C(297772729) } },
    { { -INT16_C(   11624), -INT16_C(    2591),  INT16_C(   13795), -INT16_C(    4057),
         INT16_C(   21714), -INT16_C(   31494),  INT16_C(   28371),  INT16_C(    1332) },
        -INT16_C(   30673),
      { -INT32_C(666033522),  INT32_C(966015462), -INT32_C(870223683), -INT32_C(40856436) } },
    { {  INT16_C(   28741),  INT16_C(   16209), -INT16_C(   20935),  INT16_C(   20184),
        -INT16_C(   11928), -INT16_C(   16326), -INT16_C(   23349),  INT16_C(   24897) },
         INT16_C(   15797),
      { -INT32_C(188426616), -INT32_C(257901822), -INT32_C(368844153),  INT32_C(393297909) } },
    { { -INT16_C(   29906), -INT16_C(   24694),  INT16_C(    1839),  INT16_C(   24129),
        -INT16_C(   25360),  INT16_C(   25223), -INT16_C(   30267), -INT16_C(    4942) },
        -INT16_C(    8598),
      {  INT32_C(218045280), -INT32_C(216867354),  INT32_C(260235666),  INT32_C(42491316) } },
    { {  INT16_C(   26598),  INT16_C(    7471), -INT16_C(   17262),  INT16_C(   22839),
        -INT16_C(   25862),  INT16_C(    7224),  INT16_C(    5041),  INT16_C(    4645) },
        -INT16_C(    2986),
      {  INT32_C(77223932), -INT32_C(21570864), -INT32_C(15052426), -INT32_C(13869970) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    int16_t b = test_vec[i].b;
    simde_int32x4_t r = simde_vmull_high_n_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16_t b = simde_test_codegen_random_i16();
    simde_int32x4_t r = simde_vmull_high_n_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b;
    int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1657139909), -INT32_C(  1389304209),  INT32_C(  1047762334),  INT32_C(  1790798392) },
         INT32_C(   489421889),
      {  INT64_C(512797820729328926),  INT64_C(876455931830802488) } },
    { {  INT32_C(   486878254),  INT32_C(    49532478), -INT32_C(  1576808326), -INT32_C(   884005559) },
        -INT32_C(  1109918113),
      {  INT64_C(1750128121756608838),  INT64_C(981173781926790167) } },
    { { -INT32_C(   216433783),  INT32_C(  1246379921),  INT32_C(   987786658), -INT32_C(  1505705557) },
         INT32_C(  1743031722),
      {  INT64_C(1721743479462365076), -INT64_C(2624492549842679154) } },
    { {  INT32_C(  1496473436),  INT32_C(   961659992), -INT32_C(  1499979947),  INT32_C(  1809784541) },
        -INT32_C(  1455172801),
      {  INT64_C(2182730020919821547), -INT64_C(2633549239733469341) } },
    { {  INT32_C(   289778219), -INT32_C(  1834356522),  INT32_C(  2034009107),  INT32_C(   886695945) },
         INT32_C(  2085444554),
      {  INT64_C(4241813214979553278),  INT64_C(1849155229554133530) } },
    { {  INT32_C(  1616099160),  INT32_C(   799522573),  INT32_C(   358864420),  INT32_C(   918823187) },
        -INT32_C(  1168104946),
      { -INT64_C(419191303945421320), -INT64_C(1073281909234182902) } },
    { {  INT32_C(  1601739088), -INT32_C(  1851276641), -INT32_C(  1184760606), -INT32_C(  1716827656) },
        -INT32_C(   206131987),
      {  INT64_C(244217057834104122),  INT64_C(353893096067832472) } },
    { { -INT32_C(  1237976973),  INT32_C(  1909594574), -INT32_C(  1459478225), -INT32_C(    61582454) },
        -INT32_C(  1016948914),
      {  INT64_C(1484214795920397650),  INT64_C(62626209716754956) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    int32_t b = test_vec[i].b;
    simde_int64x2_t r = simde_vmull_high_n_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32_t b = simde_test_codegen_random_i32();
    simde_int64x2_t r = simde_vmull_high_n_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b;
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT16_C(       46650),  UINT16_C(       42358),  UINT16_C(       36672),  UINT16_C(       63989),
         UINT16_C(       65053),  UINT16_C(       12336),  UINT16_C(       14119),  UINT16_C(       46836) },
         UINT16_C(       61375),
      {  UINT32_C(  3992627875),  UINT32_C(   757122000),  UINT32_C(   866553625),  UINT32_C(  2874559500) } },
    { {  UINT16_C(       14252),  UINT16_C(       16355),  UINT16_C(       33890),  UINT16_C(       62126),
         UINT16_C(       28657),  UINT16_C(        6872),  UINT16_C(       51900),  UINT16_C(       28124) },
         UINT16_C(       18812),
      {  UINT32_C(   539095484),  UINT32_C(   129276064),  UINT32_C(   976342800),  UINT32_C(   529068688) } },
    { {  UINT16_C(        7175),  UINT16_C(       34258),  UINT16_C(       10821),  UINT16_C(       51351),
         UINT16_C(       16450),  UINT16_C(       44009),  UINT16_C(       64021),  UINT16_C(       11309) },
         UINT16_C(        3799),
      {  UINT32_C(    62493550),  UINT32_C(   167190191),  UINT32_C(   243215779),  UINT32_C(    42962891) } },
    { {  UINT16_C(       16804),  UINT16_C(       28181),  UINT16_C(       14293),  UINT16_C(       28269),
         UINT16_C(       56164),  UINT16_C(        7343),  UINT16_C(        7775),  UINT16_C(       56454) },
         UINT16_C(       26567),
      {  UINT32_C(  1492108988),  UINT32_C(   195081481),  UINT32_C(   206558425),  UINT32_C(  1499813418) } },
    { {  UINT16_C(       41985),  UINT16_C(       54481),  UINT16_C(       53336),  UINT16_C(       37192),
         UINT16_C(       48076),  UINT16_C(       25521),  UINT16_C(       26040),  UINT16_C(        4838) },
         UINT16_C(       35268),
      {  UINT32_C(  1695544368),  UINT32_C(   900074628),  UINT32_C(   918378720),  UINT32_C(   170626584) } },
    { {  UINT16_C(       19509),  UINT16_C(         452),  UINT16_C(       20477),  UINT16_C(       43573),
         UINT16_C(       49542),  UINT16_C(        7484),  UINT16_C(       54459),  UINT16_C(       62362) },
         UINT16_C(       16912),
      {  UINT32_C(   837854304),  UINT32_C(   126569408),  UINT32_C(   921010608),  UINT32_C(  1054666144) } },
    { {  UINT16_C(       56323),  UINT16_C(       25829),  UINT16_C(        1953),  UINT16_C(       56326),
         UINT16_C(       31185),  UINT16_C(       28383),  UINT16_C(       57951),  UINT16_C(       36744) },
         UINT16_C(       58337),
      {  UINT32_C(  1819239345),  UINT32_C(  1655779071),  UINT32_C(  3380687487),  UINT32_C(  2143534728) } },
    { {  UINT16_C(       22844),  UINT16_C(       31839),  UINT16_C(       44043),  UINT16_C(       54996),
         UINT16_C(       42687),  UINT16_C(       61570),  UINT16_C(       26809),  UINT16_C(       20954) },
         UINT16_C(       58806),
      {  UINT32_C(  2510251722),  UINT32_C(  3620685420),  UINT32_C(  1576530054),  UINT32_C(  1232220924) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    uint16_t b = test_vec[i].b;
    simde_uint32x4_t r = simde_vmull_high_n_u16(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16_t b = simde_test_codegen_random_u16();
    simde_uint32x4_t r = simde_vmull_high_n_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b;
    uint64_t r[2];
  } test_vec[] = {
    { {  UINT32_C(  2590625852),  UINT32_C(    80871496),  UINT32_C(  2893924497),  UINT32_C(   584185259) },
         UINT32_C(  2442925674),
      {  UINT64_C(7069642452338835978),  UINT64_C(1427121167583439566) } },
    { {  UINT32_C(  3242278110),  UINT32_C(  1848307562),  UINT32_C(  2938474463),  UINT32_C(  4202285662) },
         UINT32_C(  2792577413),
      {  UINT64_C(8205917414051104219),  UINT64_C(11735208022674952406) } },
    { {  UINT32_C(  3803886467),  UINT32_C(  2692809053),  UINT32_C(  2376261238),  UINT32_C(  1634321394) },
         UINT32_C(    87437959),
      {  UINT64_C(207775432701533242),  UINT64_C(142901727041394846) } },
    { {  UINT32_C(  2675411682),  UINT32_C(   599361915),  UINT32_C(  2858712765),  UINT32_C(  2586675911) },
         UINT32_C(   650124172),
      {  UINT64_C(1858518269331455580),  UINT64_C(1681660534871220692) } },
    { {  UINT32_C(   701440763),  UINT32_C(  2830681634),  UINT32_C(   470887626),  UINT32_C(  2731964041) },
         UINT32_C(   245792830),
      {  UINT64_C(115740802206521580),  UINT64_C(671497173095626030) } },
    { {  UINT32_C(   557635788),  UINT32_C(  1227075009),  UINT32_C(   531571180),  UINT32_C(  4103185339) },
         UINT32_C(    22778205),
      {  UINT64_C(12108237310131900),  UINT64_C(93463196804736495) } },
    { {  UINT32_C(   142696828),  UINT32_C(  3941257446),  UINT32_C(   923042975),  UINT32_C(   834214307) },
         UINT32_C(   705348906),
      {  UINT64_C(651067352607235350),  UINT64_C(588412148811998142) } },
    { {  UINT32_C(  2915309731),  UINT32_C(  1444882426),  UINT32_C(  3056415468),  UINT32_C(  2306969611) },
         UINT32_C(  3613856069),
      {  UINT64_C(11045445588417275292),  UINT64_C(8337056129710919159) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    uint32_t b = test_vec[i].b;
    simde_uint64x2_t r = simde_vmull_high_n_u32(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32_t b = simde_test_codegen_random_u32();
    simde_uint64x2_t r = simde_vmull_high_n_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_n_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
