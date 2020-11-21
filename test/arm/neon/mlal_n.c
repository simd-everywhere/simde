#define SIMDE_TEST_ARM_NEON_INSN mlal_n

#include "test-neon.h"
#include "../../../simde/arm/neon/mlal_n.h"

static int
test_simde_vmlal_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t c;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(    94316344), -INT32_C(  1570598978), -INT32_C(   731248258),  INT32_C(   989578608) },
      { -INT16_C( 18299), -INT16_C(  1428), -INT16_C(  6808), -INT16_C( 17488) },
       INT16_C( 11032),
      { -INT32_C(   107558224), -INT32_C(  1586352674), -INT32_C(   806354114),  INT32_C(   796650992) } },
    { { -INT32_C(  2048067768), -INT32_C(   223533997), -INT32_C(  1937675478),  INT32_C(  2023096077) },
      {  INT16_C(  1491), -INT16_C( 12739), -INT16_C( 15553), -INT16_C( 21370) },
      -INT16_C(  4419),
      { -INT32_C(  2054656497), -INT32_C(   167240356), -INT32_C(  1868946771),  INT32_C(  2117530107) } },
    { { -INT32_C(  1448448623), -INT32_C(  2053049704),  INT32_C(   631895160),  INT32_C(  1754321894) },
      { -INT16_C( 25249), -INT16_C(  2969),  INT16_C( 15125),  INT16_C( 21497) },
       INT16_C( 14601),
      { -INT32_C(  1817109272), -INT32_C(  2096400073),  INT32_C(   852735285),  INT32_C(  2068199591) } },
    { { -INT32_C(   739930090),  INT32_C(   675378814), -INT32_C(  1088693985),  INT32_C(   145986398) },
      { -INT16_C( 25928),  INT16_C( 18651),  INT16_C( 15106),  INT16_C( 27109) },
      -INT16_C(  1233),
      { -INT32_C(   707960866),  INT32_C(   652382131), -INT32_C(  1107319683),  INT32_C(   112561001) } },
    { { -INT32_C(  1370609244),  INT32_C(  1195271266),  INT32_C(  2025700407),  INT32_C(     5430501) },
      { -INT16_C( 20325),  INT16_C( 20371),  INT16_C( 19384), -INT16_C( 27415) },
      -INT16_C(  5229),
      { -INT32_C(  1264329819),  INT32_C(  1088751307),  INT32_C(  1924341471),  INT32_C(   148783536) } },
    { { -INT32_C(    28018481), -INT32_C(  1054344845), -INT32_C(   450524761), -INT32_C(  1918804528) },
      { -INT16_C( 31019),  INT16_C( 10089),  INT16_C(  1414),  INT16_C(  6616) },
      -INT16_C( 28588),
      {  INT32_C(   858752691), -INT32_C(  1342769177), -INT32_C(   490948193), -INT32_C(  2107942736) } },
    { { -INT32_C(   148619932),  INT32_C(  2087777064),  INT32_C(   427156466), -INT32_C(   895279963) },
      {  INT16_C( 29441), -INT16_C( 23769), -INT16_C(   767),  INT16_C( 27177) },
      -INT16_C( 20444),
      { -INT32_C(   750511736), -INT32_C(  1721256796),  INT32_C(   442837014), -INT32_C(  1450886551) } },
    { { -INT32_C(  1010172817), -INT32_C(  1325388147), -INT32_C(  1784338395),  INT32_C(   444176293) },
      {  INT16_C(  7856),  INT16_C( 21303),  INT16_C( 14568),  INT16_C(  4295) },
      -INT16_C( 14117),
      { -INT32_C(  1121075969), -INT32_C(  1626122598), -INT32_C(  1989994851),  INT32_C(   383543778) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    int16_t c = test_vec[i].c;
    simde_int32x4_t r = simde_vmlal_n_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    int16_t c = simde_test_codegen_random_i16();
    simde_int32x4_t r = simde_vmlal_n_s16(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t c;
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 2048296796130203316),  INT64_C( 8606392377422747921) },
      {  INT32_C(  1887333753), -INT32_C(  1563251834) },
       INT32_C(  1033152716),
      {  INT64_C( 3998200789040626464),  INT64_C( 6991314499333666777) } },
    { { -INT64_C( 5954789392489103048), -INT64_C( 6399417830918731431) },
      {  INT32_C(   941531327), -INT32_C(  1800889075) },
       INT32_C(   339114824),
      { -INT64_C( 5635502162243011600), -INT64_C( 7010126012630879231) } },
    { { -INT64_C( 6608823492868453597), -INT64_C( 3326159638695336940) },
      { -INT32_C(  1921513522), -INT32_C(  1245341784) },
       INT32_C(  2085187124),
      {  INT64_C( 7831205326174807291), -INT64_C( 5922930291671326156) } },
    { {  INT64_C( 6298532890838925545), -INT64_C( 4386138432066506336) },
      {  INT32_C(   949287273), -INT32_C(  1463481088) },
      -INT32_C(   664892508),
      {  INT64_C( 5667358895081474861), -INT64_C( 3413080821055617632) } },
    { {  INT64_C( 8281808724244604921),  INT64_C( 6709736759272036296) },
      {  INT32_C(  2099330580),  INT32_C(   951432503) },
       INT32_C(  1725987778),
      { -INT64_C( 6541516426403295455),  INT64_C( 8351897631041984630) } },
    { {  INT64_C( 1000243212586991110),  INT64_C( 3362300124960182136) },
      {  INT32_C(   613205520),  INT32_C(  1017228548) },
       INT32_C(   628381538),
      {  INT64_C( 1385570240354680870),  INT64_C( 4001507764449928960) } },
    { {  INT64_C( 8779708734924084434), -INT64_C( 5902523081149728675) },
      {  INT32_C(  1625079632), -INT32_C(  1987811195) },
       INT32_C(  2026186261),
      { -INT64_C( 6374321315396131230),  INT64_C( 8516545259788831046) } },
    { {  INT64_C( 2388922719029508477),  INT64_C( 4405963777843592946) },
      {  INT32_C(  2011904807),  INT32_C(  2144913658) },
       INT32_C(  1174953008),
      {  INT64_C( 4752816323823817933),  INT64_C( 6926136532210976210) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    int32_t c = test_vec[i].c;
    simde_int64x2_t r = simde_vmlal_n_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    int32_t c = simde_test_codegen_random_i32();
    simde_int64x2_t r = simde_vmlal_n_s32(a, b, c);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[4];
    uint16_t c;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(4290694786), UINT32_C(2504940295), UINT32_C(1991669123), UINT32_C( 700797043) },
      { UINT16_C(60017), UINT16_C(39015), UINT16_C(21029), UINT16_C( 7951) },
      UINT16_C(59162),
      { UINT32_C(3546453244), UINT32_C( 518178429), UINT32_C(3235786821), UINT32_C(1171194105) } },
    { { UINT32_C(2806270878), UINT32_C(1333118609), UINT32_C( 346717382), UINT32_C(3364498706) },
      { UINT16_C(64931), UINT16_C(26905), UINT16_C(35367), UINT16_C(36435) },
      UINT16_C(31010),
      { UINT32_C( 524813892), UINT32_C(2167442659), UINT32_C(1443448052), UINT32_C( 199380760) } },
    { { UINT32_C(4221055456), UINT32_C(1564882713), UINT32_C(1394857950), UINT32_C(3503286566) },
      { UINT16_C(57854), UINT16_C(35069), UINT16_C(41386), UINT16_C(50053) },
      UINT16_C(44042),
      { UINT32_C(2474094028), UINT32_C(3109391611), UINT32_C(3217580162), UINT32_C(1412753496) } },
    { { UINT32_C(1866095949), UINT32_C(1872763862), UINT32_C(1554430230), UINT32_C( 976454678) },
      { UINT16_C(22999), UINT16_C(42531), UINT16_C( 8489), UINT16_C( 9864) },
      UINT16_C(12969),
      { UINT32_C(2164369980), UINT32_C(2424348401), UINT32_C(1664524071), UINT32_C(1104380894) } },
    { { UINT32_C(3522506695), UINT32_C( 372196059), UINT32_C(1362167217), UINT32_C( 436946804) },
      { UINT16_C( 8611), UINT16_C(54942), UINT16_C(30043), UINT16_C(32559) },
      UINT16_C(22556),
      { UINT32_C(3716736411), UINT32_C(1611467811), UINT32_C(2039817125), UINT32_C(1171347608) } },
    { { UINT32_C(1249813664), UINT32_C(3413722838), UINT32_C(1175278615), UINT32_C(2605497962) },
      { UINT16_C(49167), UINT16_C( 6882), UINT16_C(34267), UINT16_C(31036) },
      UINT16_C(38747),
      { UINT32_C(3154887413), UINT32_C(3680379692), UINT32_C(2503022064), UINT32_C(3808049854) } },
    { { UINT32_C( 186026735), UINT32_C(1638905826), UINT32_C(2057798913), UINT32_C(1573830224) },
      { UINT16_C(14597), UINT16_C(20763), UINT16_C(10964), UINT16_C(46865) },
      UINT16_C(60485),
      { UINT32_C(1068926280), UINT32_C(2894755881), UINT32_C(2720956453), UINT32_C( 113492453) } },
    { { UINT32_C(2556854588), UINT32_C( 790779160), UINT32_C( 266732896), UINT32_C( 227862374) },
      { UINT16_C(58465), UINT16_C(12235), UINT16_C(53313), UINT16_C(23656) },
      UINT16_C(15649),
      { UINT32_C(3471773373), UINT32_C( 982244675), UINT32_C(1101028033), UINT32_C( 598055118) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    uint16_t c = test_vec[i].c;
    simde_uint32x4_t r = simde_vmlal_n_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    uint16_t c = simde_test_codegen_random_u16();
    simde_uint32x4_t r = simde_vmlal_n_u16(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[2];
    uint32_t c;
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(15112567586238305083), UINT64_C(10599289406992564070) },
      { UINT32_C(1475048791), UINT32_C(1617544317) },
      UINT32_C(1175038216),
      { UINT64_C(16845806286127901939), UINT64_C(12499965795541182542) } },
    { { UINT64_C(15419563916853419108), UINT64_C( 9527648644139300843) },
      { UINT32_C(2518176319), UINT32_C(1156383687) },
      UINT32_C(3483719623),
      { UINT64_C( 5745440099818075229), UINT64_C(13556165186258290844) } },
    { { UINT64_C(17943624365020392960), UINT64_C(12616964892059959770) },
      { UINT32_C(3056816503), UINT32_C(1800162211) },
      UINT32_C( 380582478),
      { UINT64_C(  660251090813875778), UINT64_C(13302075087124298628) } },
    { { UINT64_C( 5617672102965761169), UINT64_C(12910438021484509578) },
      { UINT32_C(  56771468), UINT32_C( 951752084) },
      UINT32_C( 799213281),
      { UINT64_C( 5663044614173227677), UINT64_C(13671090927236737182) } },
    { { UINT64_C(12277423533935907392), UINT64_C( 5482356641975719974) },
      { UINT32_C(3774824532), UINT32_C( 417620355) },
      UINT32_C(3612385014),
      { UINT64_C( 7466799030102719224), UINT64_C( 6990962153919079944) } },
    { { UINT64_C(17056904501791290276), UINT64_C(14001284910167759223) },
      { UINT32_C( 554591180), UINT32_C( 654380452) },
      UINT32_C(1698686318),
      { UINT64_C(17998980951340765516), UINT64_C(15112872030746814959) } },
    { { UINT64_C(14415252208582692739), UINT64_C( 5594961520471884688) },
      { UINT32_C(2769351641), UINT32_C(4207287894) },
      UINT32_C(2585970732),
      { UINT64_C( 3129970425115312335), UINT64_C(16474884875453803096) } },
    { { UINT64_C( 8311741593912566189), UINT64_C(  439083547831789183) },
      { UINT32_C( 341031995), UINT32_C(  96035759) },
      UINT32_C(2919268482),
      { UINT64_C( 9307305548269647779), UINT64_C(  719437712225437021) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    uint32_t c = test_vec[i].c;
    simde_uint64x2_t r = simde_vmlal_n_u32(a, b, c);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    uint32_t c = simde_test_codegen_random_u32();
    simde_uint64x2_t r = simde_vmlal_n_u32(a, b, c);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_n_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
