#define SIMDE_TEST_ARM_NEON_INSN mlsl_high_n

#include "test-neon.h"
#include "../../../simde/arm/neon/mlsl_high_n.h"

static int
test_simde_vmlsl_high_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t c;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   100317860),  INT32_C(   201461218),  INT32_C(  1231037659),  INT32_C(  1308170785) },
      { -INT16_C( 28432),  INT16_C( 14329),  INT16_C( 10313), -INT16_C( 29168),  INT16_C( 15504),  INT16_C( 19565),  INT16_C( 26352), -INT16_C( 27408) },
      -INT16_C(  5344),
      {  INT32_C(   183171236),  INT32_C(   306016578),  INT32_C(  1371862747),  INT32_C(  1161702433) } },
    { { -INT32_C(  1661468006),  INT32_C(  1858130958),  INT32_C(   394846493),  INT32_C(   682064175) },
      { -INT16_C(  3920), -INT16_C( 16303), -INT16_C(  7810), -INT16_C(  5124), -INT16_C(  5075),  INT16_C(  7761),  INT16_C( 29313),  INT16_C(  6921) },
       INT16_C(   372),
      { -INT32_C(  1659580106),  INT32_C(  1855243866),  INT32_C(   383942057),  INT32_C(   679489563) } },
    { {  INT32_C(  2010481591),  INT32_C(  2052715505), -INT32_C(  1309439990),  INT32_C(    27370416) },
      {  INT16_C(  8035),  INT16_C( 24803),  INT16_C(  4106),  INT16_C( 23628), -INT16_C( 13010),  INT16_C( 14286),  INT16_C( 17128), -INT16_C( 24775) },
       INT16_C(  3781),
      {  INT32_C(  2059672401),  INT32_C(  1998700139), -INT32_C(  1374200958),  INT32_C(   121044691) } },
    { {  INT32_C(  1879160599),  INT32_C(   620235569),  INT32_C(  1573365948), -INT32_C(  1921242454) },
      { -INT16_C( 30838), -INT16_C( 10339), -INT16_C( 13085), -INT16_C( 20060), -INT16_C( 29437),  INT16_C( 15603), -INT16_C( 18132),  INT16_C( 17227) },
       INT16_C( 19568),
      { -INT32_C(  1839783481),  INT32_C(   314916065),  INT32_C(  1928172924),  INT32_C(  2036626906) } },
    { { -INT32_C(  1420254797), -INT32_C(  1940646715), -INT32_C(   289997198),  INT32_C(   678773131) },
      {  INT16_C( 22552), -INT16_C( 17164), -INT16_C(  2039), -INT16_C(   695),  INT16_C( 30260),  INT16_C( 32694),  INT16_C(  9913),  INT16_C( 28108) },
       INT16_C(  9415),
      { -INT32_C(  1705152697),  INT32_C(  2046506571), -INT32_C(   383328093),  INT32_C(   414136311) } },
    { {  INT32_C(  1815645208), -INT32_C(   831870440),  INT32_C(   235926937),  INT32_C(   308750110) },
      {  INT16_C( 28900),  INT16_C( 11530),  INT16_C( 16237),  INT16_C(  9123),  INT16_C( 23998), -INT16_C( 30135),  INT16_C(  4298), -INT16_C(  7506) },
      -INT16_C(  6244),
      {  INT32_C(  1965488720), -INT32_C(  1020033380),  INT32_C(   262763649),  INT32_C(   261882646) } },
    { { -INT32_C(  1181633457), -INT32_C(  1834014077), -INT32_C(  1598370503), -INT32_C(   368009505) },
      {  INT16_C( 32459),  INT16_C( 28457), -INT16_C(  6239), -INT16_C(  5172), -INT16_C( 27022),  INT16_C(  8443), -INT16_C( 26504), -INT16_C( 14585) },
      -INT16_C( 26292),
      { -INT32_C(  1892095881), -INT32_C(  1612030721),  INT32_C(  1999753625), -INT32_C(   751478325) } },
    { {  INT32_C(   818139009),  INT32_C(   486407266), -INT32_C(  1380262756), -INT32_C(   282360378) },
      { -INT16_C( 13068), -INT16_C( 16169),  INT16_C( 18871), -INT16_C( 19626), -INT16_C( 12439),  INT16_C( 29003), -INT16_C( 26730),  INT16_C(  5898) },
      -INT16_C( 12953),
      {  INT32_C(   657016642),  INT32_C(   862083125), -INT32_C(  1726496446), -INT32_C(   205963584) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    int16_t c = test_vec[i].c;
    simde_int32x4_t r = simde_vmlsl_high_n_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    int16_t c = simde_test_codegen_random_i16();
    simde_int32x4_t r = simde_vmlsl_high_n_s16(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_high_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t c;
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 6980184812559873721), -INT64_C( 5905598074115004653) },
      {  INT32_C(   821543641), -INT32_C(  1057005451), -INT32_C(   614951471), -INT32_C(   190201939) },
       INT32_C(  1832481672),
      { -INT64_C( 5853297512782934209), -INT64_C( 5557056506918642645) } },
    { {  INT64_C( 1741538740616846041),  INT64_C( 7949906644983756361) },
      { -INT32_C(   282111458), -INT32_C(  1798600729), -INT32_C(   829852602), -INT32_C(  1069825305) },
       INT32_C(  1571637020),
      {  INT64_C( 3045765811063372081), -INT64_C( 8815460374455004155) } },
    { {  INT64_C(  640703085361420663),  INT64_C( 8072603964836100090) },
      {  INT32_C(  1929761325),  INT32_C(   759270982),  INT32_C(  1827568720),  INT32_C(   986291139) },
      -INT32_C(  2063909004),
      {  INT64_C( 4412638621998175543), -INT64_C( 8338524946525935970) } },
    { { -INT64_C( 6949613779972989060), -INT64_C( 5888151497798019671) },
      { -INT32_C(   203650397), -INT32_C(   916469242), -INT32_C(   637261723), -INT32_C(   463536280) },
      -INT32_C(   178591009),
      { -INT64_C( 7063422994080637567), -INT64_C( 5970934909751326191) } },
    { { -INT64_C( 1914410832753202962),  INT64_C( 5210788199207843770) },
      { -INT32_C(  1626165446),  INT32_C(  1064900311), -INT32_C(   198977771), -INT32_C(  1326809662) },
      -INT32_C(   481853595),
      { -INT64_C( 2010288987034639707),  INT64_C( 4571460193692408880) } },
    { { -INT64_C( 5819956466487347932),  INT64_C( 1271714089608383436) },
      {  INT32_C(   894508831), -INT32_C(  1188465417),  INT32_C(  1466504178), -INT32_C(  1237667694) },
      -INT32_C(   745274522),
      { -INT64_C( 4727008266217395016),  INT64_C(  349311890567691168) } },
    { { -INT64_C( 7768012979059896481), -INT64_C( 1164189331399190397) },
      {  INT32_C(  1571291499), -INT32_C(  1481305836),  INT32_C(   660467649),  INT32_C(  1392177906) },
       INT32_C(   478051521),
      { -INT64_C( 8083750543235640610), -INT64_C( 1829722096865085423) } },
    { { -INT64_C( 9143619469993529098),  INT64_C(  582680641153332045) },
      { -INT32_C(   357577943), -INT32_C(  1391325765), -INT32_C(  1057026817),  INT32_C(  2145156489) },
      -INT32_C(  1208447698),
      {  INT64_C( 8025762979988105252),  INT64_C( 3174990062135144367) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    int32_t c = test_vec[i].c;
    simde_int64x2_t r = simde_vmlsl_high_n_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    int32_t c = simde_test_codegen_random_i32();
    simde_int64x2_t r = simde_vmlsl_high_n_s32(a, b, c);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_high_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[8];
    uint16_t c;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 825758691), UINT32_C(4209682438), UINT32_C(3909288128), UINT32_C(2278798028) },
      { UINT16_C(58815), UINT16_C(48692), UINT16_C(13554), UINT16_C(31615), UINT16_C(23473), UINT16_C(57338), UINT16_C(62184), UINT16_C(52374) },
      UINT16_C(52741),
      { UINT32_C(3882736494), UINT32_C(1185618980), UINT32_C( 629641784), UINT32_C(3811508190) } },
    { { UINT32_C(3883273469), UINT32_C( 166147590), UINT32_C(4089230111), UINT32_C(1876458298) },
      { UINT16_C(51770), UINT16_C(47523), UINT16_C(21573), UINT16_C(16148), UINT16_C(64820), UINT16_C(51761), UINT16_C(14281), UINT16_C(50841) },
      UINT16_C( 3907),
      { UINT32_C(3630021729), UINT32_C(4258884659), UINT32_C(4033434244), UINT32_C(1677822511) } },
    { { UINT32_C(2487634349), UINT32_C( 256402771), UINT32_C( 831160920), UINT32_C(2499527921) },
      { UINT16_C(16765), UINT16_C(37609), UINT16_C( 7552), UINT16_C(45711), UINT16_C(22759), UINT16_C(33001), UINT16_C(11294), UINT16_C(52112) },
      UINT16_C(54901),
      { UINT32_C(1238142490), UINT32_C(2739582166), UINT32_C( 211109026), UINT32_C(3933494305) } },
    { { UINT32_C(2805712991), UINT32_C(1646957783), UINT32_C(3223722949), UINT32_C(2567021744) },
      { UINT16_C(33334), UINT16_C(50614), UINT16_C(40244), UINT16_C( 7453), UINT16_C(15134), UINT16_C(44617), UINT16_C(48646), UINT16_C(25988) },
      UINT16_C(49031),
      { UINT32_C(2063677837), UINT32_C(3754308952), UINT32_C( 838560923), UINT32_C(1292804116) } },
    { { UINT32_C( 928210445), UINT32_C(3880917184), UINT32_C(3666543321), UINT32_C(1365033371) },
      { UINT16_C(36998), UINT16_C(41967), UINT16_C( 3501), UINT16_C(63198), UINT16_C(58555), UINT16_C(16309), UINT16_C(15433), UINT16_C(22270) },
      UINT16_C(21146),
      { UINT32_C(3984973711), UINT32_C(3536047070), UINT32_C(3340197103), UINT32_C( 894111951) } },
    { { UINT32_C(3765066637), UINT32_C(3454157634), UINT32_C(2056158750), UINT32_C(3188397263) },
      { UINT16_C(47287), UINT16_C(38347), UINT16_C(34479), UINT16_C(25721), UINT16_C(49861), UINT16_C(50336), UINT16_C(14873), UINT16_C(42518) },
      UINT16_C(32917),
      { UINT32_C(2123792100), UINT32_C(1797247522), UINT32_C(1566584209), UINT32_C(1788832257) } },
    { { UINT32_C(1774507910), UINT32_C( 854057636), UINT32_C(1732687452), UINT32_C(1075903861) },
      { UINT16_C(53138), UINT16_C( 3015), UINT16_C(35891), UINT16_C(54222), UINT16_C(59216), UINT16_C(26125), UINT16_C(41869), UINT16_C( 5351) },
      UINT16_C(43898),
      { UINT32_C(3470011238), UINT32_C(4002189682), UINT32_C(4189689386), UINT32_C( 841005663) } },
    { { UINT32_C(1686970237), UINT32_C(2551900497), UINT32_C(1905626961), UINT32_C(2537564368) },
      { UINT16_C(29491), UINT16_C(  291), UINT16_C(29766), UINT16_C(21480), UINT16_C(30426), UINT16_C(49654), UINT16_C(29066), UINT16_C( 1900) },
      UINT16_C(63888),
      { UINT32_C(4038081245), UINT32_C(3674573041), UINT32_C(  48658353), UINT32_C(2416177168) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    uint16_t c = test_vec[i].c;
    simde_uint32x4_t r = simde_vmlsl_high_n_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    uint16_t c = simde_test_codegen_random_u16();
    simde_uint32x4_t r = simde_vmlsl_high_n_u16(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_high_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[4];
    uint32_t c;
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 1086832581621834091), UINT64_C(11482044334635214245) },
      { UINT32_C(1410571884), UINT32_C(3905613553), UINT32_C( 475616431), UINT32_C(3323324763) },
      UINT32_C(1145895114),
      { UINT64_C(  541826037200815957), UINT64_C( 7673862726478306263) } },
    { { UINT64_C(14030553725883605292), UINT64_C(11436176211989040884) },
      { UINT32_C( 310804323), UINT32_C( 791601108), UINT32_C(2465613000), UINT32_C(1775649340) },
      UINT32_C(3912903075),
      { UINT64_C( 4382849036423630292), UINT64_C( 4488232449381320384) } },
    { { UINT64_C(12396172266523324851), UINT64_C( 1294732382133992833) },
      { UINT32_C(2000692655), UINT32_C(2785621609), UINT32_C( 454025336), UINT32_C(3171174665) },
      UINT32_C( 979742522),
      { UINT64_C(11951344338778787459), UINT64_C(16634541791853939319) } },
    { { UINT64_C( 7503612891432906172), UINT64_C(12116575526369958144) },
      { UINT32_C(1749954544), UINT32_C( 428104975), UINT32_C(3788933286), UINT32_C(4095425336) },
      UINT32_C(3543204264),
      { UINT64_C(12525392390175726284), UINT64_C(16052391086670677056) } },
    { { UINT64_C(12385097352044303153), UINT64_C( 5027883284593575534) },
      { UINT32_C(2757643006), UINT32_C( 193279187), UINT32_C( 402628719), UINT32_C(3538628769) },
      UINT32_C(4026738308),
      { UINT64_C(10763816865346035701), UINT64_C( 9225495336379944298) } },
    { { UINT64_C( 2281054422016189403), UINT64_C(10030293418009456015) },
      { UINT32_C(1704376310), UINT32_C(4185691480), UINT32_C(1238132677), UINT32_C(1765461902) },
      UINT32_C(2628965811),
      { UINT64_C(17472790018410834972), UINT64_C( 5388954437028423493) } },
    { { UINT64_C( 9142623655207590340), UINT64_C( 2467022389432095713) },
      { UINT32_C(4196186420), UINT32_C(2923685920), UINT32_C(1779924407), UINT32_C( 386386259) },
      UINT32_C(3916087842),
      { UINT64_C( 2172283325275830646), UINT64_C(  953899858246332635) } },
    { { UINT64_C( 2998114628764388322), UINT64_C(12772040937581565712) },
      { UINT32_C( 123699791), UINT32_C(1399944960), UINT32_C(1667921984), UINT32_C( 491574331) },
      UINT32_C(2128655136),
      { UINT64_C(17894428004785030114), UINT64_C(11725648713172651696) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    uint32_t c = test_vec[i].c;
    simde_uint64x2_t r = simde_vmlsl_high_n_u32(a, b, c);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    uint32_t c = simde_test_codegen_random_u32();
    simde_uint64x2_t r = simde_vmlsl_high_n_u32(a, b, c);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_n_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
