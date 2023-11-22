#define SIMDE_TEST_ARM_NEON_INSN sha1

#include "test-neon.h"
#include "../../../simde/arm/neon/sha1.h"

static int
test_simde_vsha1h_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint32_t r;
  } test_vec[] = {
    {    UINT32_C(  3879884345),
         UINT32_C(  2043712910) },
    {    UINT32_C(  3113757391),
         UINT32_C(  3999664819) },
    {    UINT32_C(   152809484),
         UINT32_C(    38202371) },
    {    UINT32_C(   569885049),
         UINT32_C(  1216213086) },
    {    UINT32_C(  2734022282),
         UINT32_C(  2830989218) },
    {    UINT32_C(  1128604498),
         UINT32_C(  2429634772) },
    {    UINT32_C(  1422585399),
         UINT32_C(  3576871821) },
    {    UINT32_C(  3008617904),
         UINT32_C(   752154476) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    uint32_t r = simde_vsha1h_u32(a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32_t a = simde_test_codegen_random_u32();
    simde_uint32_t r = simde_vsha1h_u32(a);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsha1cq_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b;
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  3895506722),  UINT32_C(  4257474071),  UINT32_C(  1571001026),  UINT32_C(  3177622005) },
         UINT32_C(    35761787),
      {  UINT32_C(  3819989231),  UINT32_C(  4084453664),  UINT32_C(  2054177816),  UINT32_C(  2575096804) },
      {  UINT32_C(  1040485288),  UINT32_C(  2857931842),  UINT32_C(  3089614975),  UINT32_C(  1382293994) } },
    { {  UINT32_C(  1386163730),  UINT32_C(   729623505),  UINT32_C(  4265503235),  UINT32_C(  1005250536) },
         UINT32_C(  3102321237),
      {  UINT32_C(  1200746772),  UINT32_C(  2211657183),  UINT32_C(   503851003),  UINT32_C(  3722515724) },
      {  UINT32_C(  1940571499),  UINT32_C(   841108180),  UINT32_C(  1688320218),  UINT32_C(   600314615) } },
    { {  UINT32_C(   905190815),  UINT32_C(  3854502930),  UINT32_C(  1423126145),  UINT32_C(   702363053) },
         UINT32_C(  1691279322),
      {  UINT32_C(  1763509627),  UINT32_C(  3361091022),  UINT32_C(    65257421),  UINT32_C(  4116207249) },
      {  UINT32_C(   254631948),  UINT32_C(  3234883843),  UINT32_C(  2734512358),  UINT32_C(   911259066) } },
    { {  UINT32_C(  1520923725),  UINT32_C(    69195493),  UINT32_C(  1975034769),  UINT32_C(  2076666377) },
         UINT32_C(  2998119308),
      {  UINT32_C(   776168632),  UINT32_C(  3315704800),  UINT32_C(  1521424049),  UINT32_C(  3501971159) },
      {  UINT32_C(   120979848),  UINT32_C(  4014228190),  UINT32_C(   395601190),  UINT32_C(   762286366) } },
    { {  UINT32_C(   910590281),  UINT32_C(  3869965328),  UINT32_C(  3392419901),  UINT32_C(  3484871733) },
         UINT32_C(  2097704285),
      {  UINT32_C(  1879322185),  UINT32_C(  1843210377),  UINT32_C(  2500371447),  UINT32_C(  4174187854) },
      {  UINT32_C(   863357684),  UINT32_C(  2512732802),  UINT32_C(  2516163464),  UINT32_C(  1615085376) } },
    { {  UINT32_C(   788398651),  UINT32_C(  2906803283),  UINT32_C(  1206035284),  UINT32_C(  1424451694) },
         UINT32_C(  4064077953),
      {  UINT32_C(  1157566790),  UINT32_C(  3022567661),  UINT32_C(  2934253961),  UINT32_C(   862319781) },
      {  UINT32_C(  2101690206),  UINT32_C(  3692730107),  UINT32_C(    70467183),  UINT32_C(   456710250) } },
    { {  UINT32_C(  3531021650),  UINT32_C(  3833521532),  UINT32_C(  1323171833),  UINT32_C(  4129169656) },
         UINT32_C(  2111289785),
      {  UINT32_C(   719485686),  UINT32_C(  3986654994),  UINT32_C(   831984332),  UINT32_C(  3554931822) },
      {  UINT32_C(  2612392050),  UINT32_C(  2883294714),  UINT32_C(  2951581963),  UINT32_C(  1400811840) } },
    { {  UINT32_C(  2797377815),  UINT32_C(  2719421633),  UINT32_C(  1054353568),  UINT32_C(  2870108851) },
         UINT32_C(   613209907),
      {  UINT32_C(  3127548287),  UINT32_C(  2904645084),  UINT32_C(  1336196063),  UINT32_C(  2606398120) },
      {  UINT32_C(  2349160910),  UINT32_C(    49395543),  UINT32_C(  4044737366),  UINT32_C(   946257302) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    uint32_t b = test_vec[i].b;
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vsha1cq_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32_t b = simde_test_codegen_random_u32();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsha1cq_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsha1mq_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b;
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  2776800370),  UINT32_C(  3403609805),  UINT32_C(  2173658313),  UINT32_C(   378250388) },
         UINT32_C(   389530095),
      {  UINT32_C(  3688297548),  UINT32_C(  4131497375),  UINT32_C(  1733636982),  UINT32_C(  3038650774) },
      {  UINT32_C(   352441978),  UINT32_C(  2652740264),  UINT32_C(  2602994858),  UINT32_C(   159156823) } },
    { {  UINT32_C(  1296374988),  UINT32_C(  1575906373),  UINT32_C(   645087163),  UINT32_C(  1702406998) },
         UINT32_C(   986307044),
      {  UINT32_C(  2856166880),  UINT32_C(  3067174549),  UINT32_C(  4069293301),  UINT32_C(   529831294) },
      {  UINT32_C(  3060469249),  UINT32_C(  2033765434),  UINT32_C(  2988019592),  UINT32_C(  1019826729) } },
    { {  UINT32_C(  1541239941),  UINT32_C(  1190471354),  UINT32_C(  3835637113),  UINT32_C(  3190356393) },
         UINT32_C(  4163856231),
      {  UINT32_C(   998472623),  UINT32_C(  4251312054),  UINT32_C(  3528957927),  UINT32_C(  2223261068) },
      {  UINT32_C(   610620965),  UINT32_C(  1841619540),  UINT32_C(  2487229847),  UINT32_C(  2777131102) } },
    { {  UINT32_C(   215768102),  UINT32_C(   160736116),  UINT32_C(  3442556907),  UINT32_C(   840504858) },
         UINT32_C(  1271500141),
      {  UINT32_C(  1503666106),  UINT32_C(  1904110988),  UINT32_C(  1666227787),  UINT32_C(  1140859399) },
      {  UINT32_C(  2513130725),  UINT32_C(  1306960733),  UINT32_C(  3157687095),  UINT32_C(  2457967192) } },
    { {  UINT32_C(  3855037482),  UINT32_C(  3146878481),  UINT32_C(  2017690631),  UINT32_C(  1224138407) },
         UINT32_C(   950721018),
      {  UINT32_C(  3285712429),  UINT32_C(  1141263117),  UINT32_C(  3454064560),  UINT32_C(   544204961) },
      {  UINT32_C(   853209667),  UINT32_C(  2698061625),  UINT32_C(  4032327615),  UINT32_C(  2341419746) } },
    { {  UINT32_C(  3363075212),  UINT32_C(  3250537441),  UINT32_C(  2847178075),  UINT32_C(   677150906) },
         UINT32_C(   418762463),
      {  UINT32_C(   196182216),  UINT32_C(   634304568),  UINT32_C(  3452922690),  UINT32_C(  4141590433) },
      {  UINT32_C(  3996903472),  UINT32_C(  2223350418),  UINT32_C(  1966671185),  UINT32_C(  4147939534) } },
    { {  UINT32_C(   162911490),  UINT32_C(  4065339133),  UINT32_C(  1563251037),  UINT32_C(  3566860385) },
         UINT32_C(  2862527662),
      {  UINT32_C(  2512155623),  UINT32_C(  3706217880),  UINT32_C(  4019495917),  UINT32_C(  4034906733) },
      {  UINT32_C(  2561641171),  UINT32_C(   986341067),  UINT32_C(  1564980832),  UINT32_C(  3536571988) } },
    { {  UINT32_C(  3377650873),  UINT32_C(  2915784188),  UINT32_C(  3587916694),  UINT32_C(   692839991) },
         UINT32_C(  1973177457),
      {  UINT32_C(  1161827945),  UINT32_C(  1074963440),  UINT32_C(  2392014423),  UINT32_C(  3224863588) },
      {  UINT32_C(  3163174908),  UINT32_C(  4210326126),  UINT32_C(   616982086),  UINT32_C(  1690357874) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    uint32_t b = test_vec[i].b;
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vsha1mq_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32_t b = simde_test_codegen_random_u32();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsha1mq_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsha1pq_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b;
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  2207019712),  UINT32_C(   756653381),  UINT32_C(  2120862016),  UINT32_C(   813639751) },
         UINT32_C(    44752043),
      {  UINT32_C(  1041798084),  UINT32_C(  2330573928),  UINT32_C(  1457477223),  UINT32_C(   910954022) },
      {  UINT32_C(  1412623068),  UINT32_C(   448303882),  UINT32_C(  2274186856),  UINT32_C(  1163415856) } },
    { {  UINT32_C(  1186147300),  UINT32_C(   768664730),  UINT32_C(   207655048),  UINT32_C(  4145700248) },
         UINT32_C(   875549471),
      {  UINT32_C(  4214964559),  UINT32_C(   183491405),  UINT32_C(  1368104838),  UINT32_C(  1133236394) },
      {  UINT32_C(  4206350275),  UINT32_C(    95412919),  UINT32_C(  2495759058),  UINT32_C(   924757664) } },
    { {  UINT32_C(  2826592684),  UINT32_C(  4041476520),  UINT32_C(   702221259),  UINT32_C(  3460996093) },
         UINT32_C(  3277440127),
      {  UINT32_C(   335678830),  UINT32_C(   213115700),  UINT32_C(  3820374690),  UINT32_C(  3190179054) },
      {  UINT32_C(   701622789),  UINT32_C(  2133654841),  UINT32_C(  1460847319),  UINT32_C(  1065838664) } },
    { {  UINT32_C(  2530519878),  UINT32_C(  2653433802),  UINT32_C(   666929542),  UINT32_C(  1584578383) },
         UINT32_C(  3581041028),
      {  UINT32_C(  1686532444),  UINT32_C(  4015849298),  UINT32_C(    66406682),  UINT32_C(  3984649039) },
      {  UINT32_C(  3765801242),  UINT32_C(  1488786067),  UINT32_C(  3126714276),  UINT32_C(  2131366701) } },
    { {  UINT32_C(  3412892052),  UINT32_C(  4181149242),  UINT32_C(  1608990093),  UINT32_C(  3101620895) },
         UINT32_C(  1897457729),
      {  UINT32_C(   733077318),  UINT32_C(  1625110064),  UINT32_C(  3783613372),  UINT32_C(  1557991049) },
      {  UINT32_C(  2602533560),  UINT32_C(   682169174),  UINT32_C(  3565454298),  UINT32_C(   169549522) } },
    { {  UINT32_C(   948954531),  UINT32_C(  1601253502),  UINT32_C(  3572175119),  UINT32_C(  2736211298) },
         UINT32_C(  3214200718),
      {  UINT32_C(  1042081814),  UINT32_C(  2197987524),  UINT32_C(   187715606),  UINT32_C(  3564004050) },
      {  UINT32_C(  3291460397),  UINT32_C(  1802771107),  UINT32_C(   710092968),  UINT32_C(  2383344647) } },
    { {  UINT32_C(  3995399407),  UINT32_C(  2231513885),  UINT32_C(  3757223983),  UINT32_C(  3053223424) },
         UINT32_C(   887305842),
      {  UINT32_C(  3989996163),  UINT32_C(   864669692),  UINT32_C(   764896785),  UINT32_C(   130456888) },
      {  UINT32_C(  2519208882),  UINT32_C(   589713336),  UINT32_C(  1100080807),  UINT32_C(   899175689) } },
    { {  UINT32_C(   383114926),  UINT32_C(  3581896037),  UINT32_C(  2158541791),  UINT32_C(  2456746737) },
         UINT32_C(   645397295),
      {  UINT32_C(  1101345173),  UINT32_C(   596753320),  UINT32_C(  1078414121),  UINT32_C(  2839874921) },
      {  UINT32_C(  1499728580),  UINT32_C(   678570888),  UINT32_C(  3134853944),  UINT32_C(  1118079412) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    uint32_t b = test_vec[i].b;
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vsha1pq_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32_t b = simde_test_codegen_random_u32();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsha1pq_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsha1su0q_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  1639477215),  UINT32_C(  1503534335),  UINT32_C(  3802489084),  UINT32_C(  1393091602) },
      {  UINT32_C(  1581080676),  UINT32_C(  2160116933),  UINT32_C(  3910255810),  UINT32_C(  2626209332) },
      {  UINT32_C(  2213548984),  UINT32_C(   521707405),  UINT32_C(  4066917143),  UINT32_C(  4226923376) },
      {  UINT32_C(    15539355),  UINT32_C(   361654112),  UINT32_C(  1324366735),  UINT32_C(   674864039) } },
    { {  UINT32_C(  3246980280),  UINT32_C(  1407905203),  UINT32_C(   886827610),  UINT32_C(    82223039) },
      {  UINT32_C(  1638075750),  UINT32_C(  3963064226),  UINT32_C(  2262754562),  UINT32_C(   269524775) },
      {  UINT32_C(   869682469),  UINT32_C(  3530234847),  UINT32_C(  1705670192),  UINT32_C(  3060739777) },
      {  UINT32_C(  3330628551),  UINT32_C(  2238147027),  UINT32_C(   819106060),  UINT32_C(  1589526236) } },
    { {  UINT32_C(   681398215),  UINT32_C(  2502977626),  UINT32_C(  3178230059),  UINT32_C(  1172456191) },
      {  UINT32_C(   603820520),  UINT32_C(  2400123041),  UINT32_C(   386037931),  UINT32_C(  1002245411) },
      {  UINT32_C(  1841546267),  UINT32_C(  3632586881),  UINT32_C(  1782591060),  UINT32_C(  2973458188) },
      {  UINT32_C(  4163992311),  UINT32_C(   139905572),  UINT32_C(  4107423383),  UINT32_C(  2077746514) } },
    { {  UINT32_C(  2337109650),  UINT32_C(   508032340),  UINT32_C(  1838213760),  UINT32_C(  2933526666) },
      {  UINT32_C(  1224612913),  UINT32_C(  1096895302),  UINT32_C(   730237227),  UINT32_C(  1217408119) },
      {  UINT32_C(  1317389908),  UINT32_C(  2906898080),  UINT32_C(  2897191125),  UINT32_C(  4248558391) },
      {  UINT32_C(  2824362566),  UINT32_C(   501111678),  UINT32_C(  2311149156),  UINT32_C(   310411515) } },
    { {  UINT32_C(  3320422976),  UINT32_C(  2384353519),  UINT32_C(  3226152024),  UINT32_C(   327735912) },
      {  UINT32_C(  2074506417),  UINT32_C(  1350983866),  UINT32_C(  3168652556),  UINT32_C(  2484321897) },
      {  UINT32_C(   448115260),  UINT32_C(  2177477463),  UINT32_C(  1784603484),  UINT32_C(  1626415373) },
      {  UINT32_C(   521616420),  UINT32_C(   475998672),  UINT32_C(  3518217141),  UINT32_C(   603954143) } },
    { {  UINT32_C(   470282423),  UINT32_C(  1022388131),  UINT32_C(  2077869580),  UINT32_C(  1643908798) },
      {  UINT32_C(  2086023443),  UINT32_C(  1676078157),  UINT32_C(   964361026),  UINT32_C(  3901418421) },
      {  UINT32_C(  2416977405),  UINT32_C(   424265648),  UINT32_C(   669996671),  UINT32_C(  2274794575) },
      {  UINT32_C(  4157477702),  UINT32_C(  1145417389),  UINT32_C(   543203680),  UINT32_C(  2240577212) } },
    { {  UINT32_C(  2384496054),  UINT32_C(   807212556),  UINT32_C(   240338228),  UINT32_C(  1064900740) },
      {  UINT32_C(  3688040651),  UINT32_C(  2978028723),  UINT32_C(   992862531),  UINT32_C(   905652747) },
      {  UINT32_C(  2060500276),  UINT32_C(  2225996878),  UINT32_C(  2805636952),  UINT32_C(   954297491) },
      {  UINT32_C(  4205018550),  UINT32_C(  2345274054),  UINT32_C(  1924846247),  UINT32_C(  3055118500) } },
    { {  UINT32_C(   355522969),  UINT32_C(  1852089228),  UINT32_C(  1347125821),  UINT32_C(  1337209214) },
      {  UINT32_C(  3758871113),  UINT32_C(   157466866),  UINT32_C(  2444468263),  UINT32_C(  1329114005) },
      {  UINT32_C(  3595434628),  UINT32_C(  3885991330),  UINT32_C(  3685516802),  UINT32_C(  2439860337) },
      {  UINT32_C(  2469830944),  UINT32_C(  3327072080),  UINT32_C(  1810683510),  UINT32_C(  3619398141) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vsha1su0q_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsha1su0q_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsha1su1q_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(   352530327),  UINT32_C(  1208138348),  UINT32_C(   175014867),  UINT32_C(  3012265375) },
      {  UINT32_C(  1779075971),  UINT32_C(   628075837),  UINT32_C(  4173215846),  UINT32_C(   781724174) },
      {  UINT32_C(  1624835412),  UINT32_C(  1635320853),  UINT32_C(  1240290234),  UINT32_C(  2795831703) } },
    { {  UINT32_C(  3782434394),  UINT32_C(   907745279),  UINT32_C(  2243145798),  UINT32_C(  3363157363) },
      {  UINT32_C(  1709219876),  UINT32_C(   122561333),  UINT32_C(  2297803310),  UINT32_C(  3281928142) },
      {  UINT32_C(  3430611679),  UINT32_C(  2111654819),  UINT32_C(  2354781968),  UINT32_C(   136224600) } },
    { {  UINT32_C(  1208847779),  UINT32_C(  4140666773),  UINT32_C(   899357672),  UINT32_C(  3614371951) },
      {  UINT32_C(  1668453767),  UINT32_C(  3043793228),  UINT32_C(  4096924362),  UINT32_C(  2331863280) },
      {  UINT32_C(  4207028703),  UINT32_C(   100608702),  UINT32_C(  2127357489),  UINT32_C(  1532605280) } },
    { {  UINT32_C(  1607412362),  UINT32_C(  3004425968),  UINT32_C(  1032803090),  UINT32_C(   527475604) },
      {  UINT32_C(  1634984349),  UINT32_C(   246987928),  UINT32_C(  3647624707),  UINT32_C(  1599621153) },
      {  UINT32_C(  2733583396),  UINT32_C(  3572720102),  UINT32_C(  3316528742),  UINT32_C(  2067734369) } },
    { {  UINT32_C(  2943556435),  UINT32_C(   391611315),  UINT32_C(  2422468025),  UINT32_C(  3364568288) },
      {  UINT32_C(   828208151),  UINT32_C(   629103257),  UINT32_C(  3510005035),  UINT32_C(  3333561771) },
      {  UINT32_C(   337150869),  UINT32_C(  2361646385),  UINT32_C(  2913198116),  UINT32_C(  3106373355) } },
    { {  UINT32_C(  1786982646),  UINT32_C(  3898692152),  UINT32_C(    33945852),  UINT32_C(  4242551193) },
      {  UINT32_C(  1404406905),  UINT32_C(  3933515625),  UINT32_C(   252155451),  UINT32_C(  1595790454) },
      {  UINT32_C(    32456511),  UINT32_C(  3469576199),  UINT32_C(  3123730708),  UINT32_C(  4196277581) } },
    { {  UINT32_C(    51890365),  UINT32_C(  3643091843),  UINT32_C(  1015415039),  UINT32_C(  1380598277) },
      {  UINT32_C(  3889147818),  UINT32_C(   757821060),  UINT32_C(  2935287421),  UINT32_C(   932700120) },
      {  UINT32_C(  1551453298),  UINT32_C(  4020472828),  UINT32_C(   371441230),  UINT32_C(   476454126) } },
    { {  UINT32_C(  2729808259),  UINT32_C(  2433737520),  UINT32_C(   557037430),  UINT32_C(   565759223) },
      {  UINT32_C(  3589950301),  UINT32_C(  1454470668),  UINT32_C(   595324087),  UINT32_C(  2277533768) },
      {  UINT32_C(  3892956959),  UINT32_C(  1692933903),  UINT32_C(  1307033213),  UINT32_C(  2472675281) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vsha1su1q_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsha1su1q_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsha1h_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsha1cq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsha1mq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsha1pq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsha1su0q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsha1su1q_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
