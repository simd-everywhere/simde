#define SIMDE_TEST_ARM_NEON_INSN mlal_high_n

#include "test-neon.h"
#include "../../../simde/arm/neon/mlal_high_n.h"

static int
test_simde_vmlal_high_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t c;
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1719676907),  INT32_C(  1079510229), -INT32_C(  1432285409), -INT32_C(    21529820) },
      { -INT16_C( 17280), -INT16_C(  8864),  INT16_C(  3218), -INT16_C(  2228), -INT16_C( 21096),  INT16_C( 12937),  INT16_C( 10928), -INT16_C( 14625) },
       INT16_C( 24314),
      {  INT32_C(  2062362245),  INT32_C(  1394060447), -INT32_C(  1166582017), -INT32_C(   377122070) } },
    { { -INT32_C(  1218195617), -INT32_C(  1312390640), -INT32_C(   483595732),  INT32_C(  1235201257) },
      {  INT16_C( 12937), -INT16_C( 10923), -INT16_C(  4823), -INT16_C( 19582),  INT16_C( 12831), -INT16_C(   291), -INT16_C(  9992),  INT16_C( 22365) },
      -INT16_C( 16217),
      { -INT32_C(  1426275944), -INT32_C(  1307671493), -INT32_C(   321555468),  INT32_C(   872508052) } },
    { { -INT32_C(   733825266), -INT32_C(  1799393688), -INT32_C(   264198063),  INT32_C(  1176685041) },
      {  INT16_C( 19614),  INT16_C(  8243),  INT16_C( 21503), -INT16_C(  9133),  INT16_C( 19281), -INT16_C( 20812),  INT16_C( 23715), -INT16_C( 20114) },
      -INT16_C( 20461),
      { -INT32_C(  1128333807), -INT32_C(  1373559356), -INT32_C(   749430678),  INT32_C(  1588237595) } },
    { {  INT32_C(  1159625862),  INT32_C(  1374514960), -INT32_C(  2112168352),  INT32_C(  1473165604) },
      { -INT16_C( 12839),  INT16_C( 11434), -INT16_C(   854),  INT16_C( 24184),  INT16_C(  7082),  INT16_C(  6586), -INT16_C( 12596),  INT16_C( 21193) },
      -INT16_C(  6070),
      {  INT32_C(  1116638122),  INT32_C(  1334537940), -INT32_C(  2035710632),  INT32_C(  1344524094) } },
    { { -INT32_C(  2074649961), -INT32_C(   966608981),  INT32_C(   142575162), -INT32_C(  1999218466) },
      { -INT16_C( 32635), -INT16_C(   636),  INT16_C( 12254), -INT16_C( 26344), -INT16_C(  7096),  INT16_C(  4455), -INT16_C( 20169), -INT16_C( 12551) },
       INT16_C( 20747),
      {  INT32_C(  2073096623), -INT32_C(   874181096), -INT32_C(   275871081),  INT32_C(  2035353233) } },
    { { -INT32_C(  1257719981), -INT32_C(    63159683),  INT32_C(   559159883),  INT32_C(   664918434) },
      {  INT16_C( 32726), -INT16_C(  4522), -INT16_C( 25064),  INT16_C( 32723),  INT16_C(  2735), -INT16_C( 22224),  INT16_C( 15576),  INT16_C( 11258) },
       INT16_C(   755),
      { -INT32_C(  1255655056), -INT32_C(    79938803),  INT32_C(   570919763),  INT32_C(   673418224) } },
    { {  INT32_C(   491090145), -INT32_C(  1070100372),  INT32_C(  1385879985),  INT32_C(  1456566272) },
      { -INT16_C(  5537),  INT16_C( 13044), -INT16_C( 23447), -INT16_C( 26052),  INT16_C(  5197),  INT16_C( 18390), -INT16_C( 14016),  INT16_C(  8521) },
      -INT16_C( 29127),
      {  INT32_C(   339717126), -INT32_C(  1605745902),  INT32_C(  1794124017),  INT32_C(  1208375105) } },
    { {  INT32_C(  1964942654), -INT32_C(    11612315), -INT32_C(   210743519), -INT32_C(  1696739419) },
      {  INT16_C( 17921),  INT16_C( 15678), -INT16_C( 29728), -INT16_C( 18863), -INT16_C( 28206),  INT16_C(  7039), -INT16_C( 18254), -INT16_C(  3926) },
      -INT16_C( 14243),
      { -INT32_C(  1928286584), -INT32_C(   111868792),  INT32_C(    49248203), -INT32_C(  1640821401) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    int16_t c = test_vec[i].c;
    simde_int32x4_t r = simde_vmlal_high_n_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    int16_t c = simde_test_codegen_random_i16();
    simde_int32x4_t r = simde_vmlal_high_n_s16(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_high_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t c;
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 4291535381239417990), -INT64_C( 1081830482065559540) },
      { -INT32_C(   270806764),  INT32_C(  1186812244),  INT32_C(   950188755),  INT32_C(  2024621553) },
      -INT32_C(  1031047151),
      {  INT64_C( 3311845972484430985), -INT64_C( 3169310766139405043) } },
    { { -INT64_C(  962002262106957296), -INT64_C( 3973372836824505384) },
      { -INT32_C(   485582833),  INT32_C(  1142665554),  INT32_C(   146589942),  INT32_C(  1372211008) },
       INT32_C(  1819199585),
      { -INT64_C(  695325900455383226), -INT64_C( 1477047140538473704) } },
    { {  INT64_C( 3230842040834987025), -INT64_C( 7137638842798657280) },
      { -INT32_C(  1428156748),  INT32_C(   397581526),  INT32_C(  1164475876),  INT32_C(  1454495301) },
      -INT32_C(  1572859670),
      {  INT64_C( 1399284898786666105),  INT64_C( 9021388231763483666) } },
    { {  INT64_C( 1252496332712449617),  INT64_C( 4045514914589987781) },
      {  INT32_C(   256890411), -INT32_C(  1722501293),  INT32_C(  2012153485),  INT32_C(  1729703702) },
       INT32_C(   230287173),
      {  INT64_C( 1715869470415197522),  INT64_C( 4443843490251202227) } },
    { { -INT64_C( 3465013667897140566),  INT64_C( 4005202978822098267) },
      { -INT32_C(  1697584883),  INT32_C(    85049327),  INT32_C(   879569903), -INT32_C(  1136581102) },
      -INT32_C(  1389600704),
      { -INT64_C( 4687264624323152278),  INT64_C( 5584596878314394075) } },
    { {  INT64_C(  364091329212060972),  INT64_C( 8899126662981788377) },
      { -INT32_C(  1149136180), -INT32_C(   806359363),  INT32_C(  1418473748), -INT32_C(  1123960687) },
      -INT32_C(   280658227),
      { -INT64_C(   34014997947663824),  INT64_C( 9214575476612910326) } },
    { { -INT64_C( 9096934840284720639), -INT64_C( 7943085493120646595) },
      {  INT32_C(  2137044075),  INT32_C(  1993600229),  INT32_C(  1899222436),  INT32_C(  1415608403) },
      -INT32_C(  1070639669),
      {  INT64_C( 7316426353188417293),  INT64_C( 8988052068567366414) } },
    { {  INT64_C(  562172821019685254),  INT64_C( 3073416771610907067) },
      { -INT32_C(  1985971739), -INT32_C(  1577331634),  INT32_C(   402021196),  INT32_C(   920069552) },
       INT32_C(  1241126934),
      {  INT64_C( 1061132155414178318),  INT64_C( 4215339873751420635) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    int32_t c = test_vec[i].c;
    simde_int64x2_t r = simde_vmlal_high_n_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    int32_t c = simde_test_codegen_random_i32();
    simde_int64x2_t r = simde_vmlal_high_n_s32(a, b, c);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_high_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[8];
    uint16_t c;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 290506582), UINT32_C(2654464088), UINT32_C(3335052769), UINT32_C(2773444951) },
      { UINT16_C(19005), UINT16_C(35143), UINT16_C(15782), UINT16_C(22177), UINT16_C(30818), UINT16_C(31117), UINT16_C(34705), UINT16_C(59330) },
      UINT16_C( 4942),
      { UINT32_C( 442809138), UINT32_C(2808244302), UINT32_C(3506564879), UINT32_C(3066653811) } },
    { { UINT32_C( 805021432), UINT32_C( 219012164), UINT32_C(4067845282), UINT32_C(1346155273) },
      { UINT16_C(57916), UINT16_C(56717), UINT16_C(61497), UINT16_C(50774), UINT16_C(59241), UINT16_C(11085), UINT16_C(39886), UINT16_C(50750) },
      UINT16_C(14913),
      { UINT32_C(1688482465), UINT32_C( 384322769), UINT32_C( 367697904), UINT32_C(2102990023) } },
    { { UINT32_C(  35030773), UINT32_C( 157727123), UINT32_C(3887886507), UINT32_C(1321924800) },
      { UINT16_C(  982), UINT16_C(11326), UINT16_C(42953), UINT16_C( 5651), UINT16_C(57810), UINT16_C( 4529), UINT16_C(62119), UINT16_C(40011) },
      UINT16_C(24952),
      { UINT32_C(1477505893), UINT32_C( 270734731), UINT32_C(1142912499), UINT32_C(2320279272) } },
    { { UINT32_C(  85592991), UINT32_C(3497379092), UINT32_C(2009675437), UINT32_C(3262816132) },
      { UINT16_C(17355), UINT16_C(56937), UINT16_C(15193), UINT16_C( 2751), UINT16_C(26188), UINT16_C(38908), UINT16_C(29954), UINT16_C(41465) },
      UINT16_C( 4992),
      { UINT32_C( 216323487), UINT32_C(3691607828), UINT32_C(2159205805), UINT32_C(3469809412) } },
    { { UINT32_C( 484021671), UINT32_C( 777160293), UINT32_C(2009978621), UINT32_C(  29005976) },
      { UINT16_C( 4982), UINT16_C(13629), UINT16_C(35101), UINT16_C( 6555), UINT16_C(40481), UINT16_C( 6798), UINT16_C( 3903), UINT16_C(58925) },
      UINT16_C( 1700),
      { UINT32_C( 552839371), UINT32_C( 788716893), UINT32_C(2016613721), UINT32_C( 129178476) } },
    { { UINT32_C(1435240707), UINT32_C(  86804792), UINT32_C(3130967040), UINT32_C(  63771846) },
      { UINT16_C(59978), UINT16_C(58764), UINT16_C(44292), UINT16_C(37507), UINT16_C(50119), UINT16_C(62881), UINT16_C(17833), UINT16_C(44283) },
      UINT16_C(34895),
      { UINT32_C(3184143212), UINT32_C(2281037287), UINT32_C(3753249575), UINT32_C(1609027131) } },
    { { UINT32_C( 772900610), UINT32_C( 720507532), UINT32_C(2587867340), UINT32_C(1216645563) },
      { UINT16_C(34926), UINT16_C(62197), UINT16_C(48411), UINT16_C(48309), UINT16_C(24242), UINT16_C(44290), UINT16_C(20747), UINT16_C( 3381) },
      UINT16_C(18392),
      { UINT32_C(1218759474), UINT32_C(1535089212), UINT32_C(2969446164), UINT32_C(1278828915) } },
    { { UINT32_C( 760833083), UINT32_C(3471189391), UINT32_C(1146593727), UINT32_C(3754739177) },
      { UINT16_C(59319), UINT16_C(27804), UINT16_C(20132), UINT16_C(42699), UINT16_C(55035), UINT16_C(12791), UINT16_C(53219), UINT16_C( 7800) },
      UINT16_C(53555),
      { UINT32_C(3708232508), UINT32_C(4156211396), UINT32_C(3996737272), UINT32_C(4172468177) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    uint16_t c = test_vec[i].c;
    simde_uint32x4_t r = simde_vmlal_high_n_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    uint16_t c = simde_test_codegen_random_u16();
    simde_uint32x4_t r = simde_vmlal_high_n_u16(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_high_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[4];
    uint32_t c;
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(16704896173277102667), UINT64_C( 4012254938249673978) },
      { UINT32_C(2625983185), UINT32_C(4017259000), UINT32_C( 717116850), UINT32_C(3204182387) },
      UINT32_C(1156641204),
      { UINT64_C(17534343070069790067), UINT64_C( 7718344312184947926) } },
    { { UINT64_C( 1975067578790101927), UINT64_C( 6965617715110352445) },
      { UINT32_C( 189733977), UINT32_C(3828682097), UINT32_C(2997039358), UINT32_C(3388445473) },
      UINT32_C(3580502870),
      { UINT64_C(12705975601612059387), UINT64_C(  651212382315808339) } },
    { { UINT64_C( 5784948386040959740), UINT64_C( 9259399800744374811) },
      { UINT32_C( 191214604), UINT32_C(  96274660), UINT32_C(4056855707), UINT32_C(3552983511) },
      UINT32_C(4094539531),
      { UINT64_C( 3949160376205861541), UINT64_C( 5360487165815496536) } },
    { { UINT64_C( 6235784844719445498), UINT64_C(11532659523971385588) },
      { UINT32_C(3752184132), UINT32_C(1439724670), UINT32_C(3089733293), UINT32_C(1202468429) },
      UINT32_C(3529306507),
      { UINT64_C(17140400660598883049), UINT64_C(15776539174903153091) } },
    { { UINT64_C(12239377433876882918), UINT64_C( 3413710588210702140) },
      { UINT32_C( 277098339), UINT32_C( 331918789), UINT32_C(1851422179), UINT32_C(1279375206) },
      UINT32_C(2317773468),
      { UINT64_C(16530554638429829690), UINT64_C( 6379012496294536548) } },
    { { UINT64_C(11107703973425119850), UINT64_C( 8781824336882926956) },
      { UINT32_C(3750537211), UINT32_C(2186143516), UINT32_C( 986615454), UINT32_C(1657075192) },
      UINT32_C(3758684407),
      { UINT64_C(14816080096080145628), UINT64_C(15010247022279858100) } },
    { { UINT64_C( 7471547321180434037), UINT64_C( 6011581158702288786) },
      { UINT32_C(4074093140), UINT32_C(1093510217), UINT32_C(2426728857), UINT32_C(1584442601) },
      UINT32_C(2386553819),
      { UINT64_C(13263066342531288920), UINT64_C( 9792938699105132005) } },
    { { UINT64_C(13065179458438623024), UINT64_C(13946484181116173636) },
      { UINT32_C( 436385921), UINT32_C(2477434538), UINT32_C( 787618643), UINT32_C( 918302982) },
      UINT32_C(2683941409),
      { UINT64_C(15179101748886711011), UINT64_C(16411155580514155274) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    uint32_t c = test_vec[i].c;
    simde_uint64x2_t r = simde_vmlal_high_n_u32(a, b, c);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    uint32_t c = simde_test_codegen_random_u32();
    simde_uint64x2_t r = simde_vmlal_high_n_u32(a, b, c);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_n_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
