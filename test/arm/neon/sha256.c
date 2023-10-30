#define SIMDE_TEST_ARM_NEON_INSN sha256

#include "test-neon.h"
#include "../../../simde/arm/neon/sha256.h"

static int
test_simde_vsha256hq_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  2776773299),  UINT32_C(    11954421),  UINT32_C(    94607463),  UINT32_C(   158117465) },
      {  UINT32_C(  2975350592),  UINT32_C(  4250819618),  UINT32_C(  1653650423),  UINT32_C(   462628963) },
      {  UINT32_C(  3406144128),  UINT32_C(  3555073845),  UINT32_C(  1144142063),  UINT32_C(   151673863) },
      {  UINT32_C(  2964263258),  UINT32_C(  3525152563),  UINT32_C(   215038844),  UINT32_C(  2602039902) } },
    { {  UINT32_C(  3427040350),  UINT32_C(  2291453517),  UINT32_C(  3564356505),  UINT32_C(   186648948) },
      {  UINT32_C(  4076085442),  UINT32_C(  2105310588),  UINT32_C(   733048987),  UINT32_C(  3717562899) },
      {  UINT32_C(  3140596489),  UINT32_C(  2455840348),  UINT32_C(  3678713405),  UINT32_C(  3228277736) },
      {  UINT32_C(  2619394137),  UINT32_C(   543565634),  UINT32_C(    45750197),  UINT32_C(  2284677461) } },
    { {  UINT32_C(  3996435978),  UINT32_C(  2957295479),  UINT32_C(  3355762760),  UINT32_C(  1023952024) },
      {  UINT32_C(  1642479560),  UINT32_C(  2019526145),  UINT32_C(  1307749499),  UINT32_C(   974041435) },
      {  UINT32_C(  4163845886),  UINT32_C(   192302143),  UINT32_C(  1443361022),  UINT32_C(  3166490750) },
      {  UINT32_C(  2878545583),  UINT32_C(  1792897723),  UINT32_C(  3430692834),  UINT32_C(   183502970) } },
    { {  UINT32_C(  2677013786),  UINT32_C(  1872067926),  UINT32_C(  1287234855),  UINT32_C(  2039732733) },
      {  UINT32_C(  3270083922),  UINT32_C(  2776061888),  UINT32_C(  1080320084),  UINT32_C(  3479485442) },
      {  UINT32_C(  2364239940),  UINT32_C(  3184422784),  UINT32_C(  3358714623),  UINT32_C(  2152911107) },
      {  UINT32_C(  1417980546),  UINT32_C(   280323986),  UINT32_C(  3172348807),  UINT32_C(   849889835) } },
    { {  UINT32_C(  4196315990),  UINT32_C(  3123563792),  UINT32_C(  3032122629),  UINT32_C(  2102912901) },
      {  UINT32_C(   742835643),  UINT32_C(  2352031856),  UINT32_C(  4189920825),  UINT32_C(  3742374134) },
      {  UINT32_C(  3038276064),  UINT32_C(  4191811354),  UINT32_C(  3270711674),  UINT32_C(   110520370) },
      {  UINT32_C(  3511219807),  UINT32_C(  1869764564),  UINT32_C(  2406210231),  UINT32_C(    64198714) } },
    { {  UINT32_C(  1027506240),  UINT32_C(  2660942306),  UINT32_C(   489310806),  UINT32_C(  1837936011) },
      {  UINT32_C(   619981831),  UINT32_C(  1685652632),  UINT32_C(   838035782),  UINT32_C(   775392944) },
      {  UINT32_C(  1756910764),  UINT32_C(   682225197),  UINT32_C(  1391608357),  UINT32_C(  1379828005) },
      {  UINT32_C(  3245320743),  UINT32_C(   101749208),  UINT32_C(  2089605519),  UINT32_C(  3343810453) } },
    { {  UINT32_C(  3300677840),  UINT32_C(  1442299337),  UINT32_C(   199464086),  UINT32_C(  1356369378) },
      {  UINT32_C(   972612739),  UINT32_C(  2623826119),  UINT32_C(  1054573620),  UINT32_C(  1298143216) },
      {  UINT32_C(  2723287226),  UINT32_C(  2602419606),  UINT32_C(  3488240585),  UINT32_C(  1921818317) },
      {  UINT32_C(  2287328756),  UINT32_C(  1032523196),  UINT32_C(  2081297637),  UINT32_C(  3150590983) } },
    { {  UINT32_C(  1295056084),  UINT32_C(  3559767396),  UINT32_C(  1601077044),  UINT32_C(  2517940043) },
      {  UINT32_C(  3036918958),  UINT32_C(   300927086),  UINT32_C(   777455403),  UINT32_C(  2933385981) },
      {  UINT32_C(  2901199133),  UINT32_C(  3041655483),  UINT32_C(   421254258),  UINT32_C(  2699057251) },
      {  UINT32_C(   765546576),  UINT32_C(  2112225606),  UINT32_C(  4088877414),  UINT32_C(  3107927617) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vsha256hq_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsha256hq_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsha256h2q_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  3047885369),  UINT32_C(  2070684921),  UINT32_C(  4218701010),  UINT32_C(  1195545758) },
      {  UINT32_C(  1641276347),  UINT32_C(  3513764647),  UINT32_C(  1189814653),  UINT32_C(  3739695642) },
      {  UINT32_C(   816527584),  UINT32_C(  3376854681),  UINT32_C(  3595176252),  UINT32_C(  4088955315) },
      {  UINT32_C(  3086968248),  UINT32_C(  3882926365),  UINT32_C(  3498795138),  UINT32_C(  1186353702) } },
    { {  UINT32_C(  1138811359),  UINT32_C(  2016694937),  UINT32_C(  3447839985),  UINT32_C(  1991362880) },
      {  UINT32_C(   373022932),  UINT32_C(  1803106356),  UINT32_C(   581947890),  UINT32_C(  3385303890) },
      {  UINT32_C(  2607571948),  UINT32_C(   176527856),  UINT32_C(  2387765143),  UINT32_C(  2313587345) },
      {  UINT32_C(  3920095579),  UINT32_C(  2971443028),  UINT32_C(  2175189065),  UINT32_C(  1587428721) } },
    { {  UINT32_C(  2785765982),  UINT32_C(   219434744),  UINT32_C(  2317111877),  UINT32_C(  2738010620) },
      {  UINT32_C(  1128217590),  UINT32_C(  2603442180),  UINT32_C(   497003421),  UINT32_C(   717689748) },
      {  UINT32_C(   518916127),  UINT32_C(  3468116530),  UINT32_C(  1967563483),  UINT32_C(  2073005969) },
      {  UINT32_C(  1457504072),  UINT32_C(  2704016908),  UINT32_C(  2418038136),  UINT32_C(   771093407) } },
    { {  UINT32_C(  4015803738),  UINT32_C(  2028515158),  UINT32_C(  3034390023),  UINT32_C(  4272115630) },
      {  UINT32_C(  1607826323),  UINT32_C(   880790451),  UINT32_C(  3686260552),  UINT32_C(   228660779) },
      {  UINT32_C(  1110250126),  UINT32_C(   974631410),  UINT32_C(  4152360320),  UINT32_C(  2663535399) },
      {  UINT32_C(  2556915071),  UINT32_C(  4220008036),  UINT32_C(   254682203),  UINT32_C(   906022793) } },
    { {  UINT32_C(   735691535),  UINT32_C(  3685073910),  UINT32_C(   144325561),  UINT32_C(   311830855) },
      {  UINT32_C(  3721916008),  UINT32_C(   725813926),  UINT32_C(  3279196708),  UINT32_C(   918311704) },
      {  UINT32_C(   230078151),  UINT32_C(   736558870),  UINT32_C(  1628576461),  UINT32_C(   416070587) },
      {  UINT32_C(  3010843254),  UINT32_C(  1816724588),  UINT32_C(  1797974844),  UINT32_C(   339266173) } },
    { {  UINT32_C(  2074906527),  UINT32_C(  3583306285),  UINT32_C(   619537208),  UINT32_C(  1118058052) },
      {  UINT32_C(   727999614),  UINT32_C(  3726610954),  UINT32_C(  1687277060),  UINT32_C(    49425755) },
      {  UINT32_C(  1781645649),  UINT32_C(  3137186627),  UINT32_C(  2353706972),  UINT32_C(   674255235) },
      {  UINT32_C(   515648042),  UINT32_C(  1676657828),  UINT32_C(  3499706622),  UINT32_C(  1574180655) } },
    { {  UINT32_C(  1250305028),  UINT32_C(  3729131199),  UINT32_C(   571064339),  UINT32_C(  1411004467) },
      {  UINT32_C(   128813180),  UINT32_C(  1527135991),  UINT32_C(   481947415),  UINT32_C(   248349326) },
      {  UINT32_C(  2859785720),  UINT32_C(  4221805505),  UINT32_C(  2350554895),  UINT32_C(  3132660584) },
      {  UINT32_C(  3801263913),  UINT32_C(  1085805713),  UINT32_C(  4236250421),  UINT32_C(  1243457345) } },
    { {  UINT32_C(  3380122285),  UINT32_C(   794944179),  UINT32_C(  1568089682),  UINT32_C(   497261132) },
      {  UINT32_C(  2298591707),  UINT32_C(  1390264363),  UINT32_C(   867279222),  UINT32_C(   765459070) },
      {  UINT32_C(  1335741655),  UINT32_C(   895855911),  UINT32_C(  1571893265),  UINT32_C(  3787382854) },
      {  UINT32_C(  2426515505),  UINT32_C(  3558082144),  UINT32_C(   890562784),  UINT32_C(   387884112) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vsha256h2q_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsha256h2q_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsha256su0q_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  1991901028),  UINT32_C(   293943878),  UINT32_C(  3669686053),  UINT32_C(  4184749985) },
      {  UINT32_C(   154486195),  UINT32_C(   814804841),  UINT32_C(  2725091169),  UINT32_C(  2710321628) },
      {  UINT32_C(   926689473),  UINT32_C(  4272986090),  UINT32_C(  2884787173),  UINT32_C(   801519633) } },
    { {  UINT32_C(  3241970642),  UINT32_C(   571655791),  UINT32_C(  2618951986),  UINT32_C(  1184420799) },
      {  UINT32_C(  2277704392),  UINT32_C(  3743785159),  UINT32_C(  4223846506),  UINT32_C(  3466605716) },
      {  UINT32_C(   752501143),  UINT32_C(   386570401),  UINT32_C(  3737912232),  UINT32_C(  2279512939) } },
    { {  UINT32_C(   457200057),  UINT32_C(  1430589938),  UINT32_C(   326703891),  UINT32_C(  2689978531) },
      {  UINT32_C(    34694563),  UINT32_C(  1389787872),  UINT32_C(  1194286217),  UINT32_C(  3727042383) },
      {  UINT32_C(  3317632773),  UINT32_C(  3084003196),  UINT32_C(   987501747),  UINT32_C(  3213139870) } },
    { {  UINT32_C(  1257930686),  UINT32_C(   448581461),  UINT32_C(  3284351625),  UINT32_C(  3238587589) },
      {  UINT32_C(  1701255137),  UINT32_C(  2570395116),  UINT32_C(  4277739690),  UINT32_C(  1522454866) },
      {  UINT32_C(  3853657753),  UINT32_C(  3759825193),  UINT32_C(  1817556620),  UINT32_C(  3433521743) } },
    { {  UINT32_C(  1621131147),  UINT32_C(  3700905756),  UINT32_C(  1564377535),  UINT32_C(    95243095) },
      {  UINT32_C(  2793638470),  UINT32_C(  2668147886),  UINT32_C(   892382474),  UINT32_C(   752304805) },
      {  UINT32_C(  1485665011),  UINT32_C(  2986987927),  UINT32_C(  1504293974),  UINT32_C(  2159684435) } },
    { {  UINT32_C(  1408817926),  UINT32_C(   760635709),  UINT32_C(  4077388034),  UINT32_C(  1843022915) },
      {  UINT32_C(  2499208794),  UINT32_C(  1771559127),  UINT32_C(  3845859681),  UINT32_C(    32805393) },
      {  UINT32_C(  1001916086),  UINT32_C(  1226706461),  UINT32_C(   192423784),  UINT32_C(  2348540029) } },
    { {  UINT32_C(  4091976316),  UINT32_C(  3622714916),  UINT32_C(  1948665239),  UINT32_C(  3767171055) },
      {  UINT32_C(  3452540050),  UINT32_C(  2103123102),  UINT32_C(  3582931903),  UINT32_C(  1414867368) },
      {  UINT32_C(  3502360767),  UINT32_C(  2297927508),  UINT32_C(  3528583111),  UINT32_C(   965774008) } },
    { {  UINT32_C(  1502615895),  UINT32_C(  4189183975),  UINT32_C(  3189336951),  UINT32_C(  3309092636) },
      {  UINT32_C(  4271059759),  UINT32_C(  3359173109),  UINT32_C(  1861595397),  UINT32_C(  1535281278) },
      {  UINT32_C(    13418374),  UINT32_C(  2618609701),  UINT32_C(  3439610697),  UINT32_C(  1377926851) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vsha256su0q_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsha256su0q_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsha256su1q_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  1682580565),  UINT32_C(  2923018732),  UINT32_C(   723399897),  UINT32_C(  1695061483) },
      {  UINT32_C(  2339756367),  UINT32_C(  3305850835),  UINT32_C(  4057957514),  UINT32_C(  4270439906) },
      {  UINT32_C(   959260552),  UINT32_C(  3629098439),  UINT32_C(  3523020311),  UINT32_C(   508446783) },
      {  UINT32_C(  1297275304),  UINT32_C(  2369338866),  UINT32_C(  1637510768),  UINT32_C(  1469716199) } },
    { {  UINT32_C(   361273495),  UINT32_C(  2229818357),  UINT32_C(  1613197130),  UINT32_C(  1674560642) },
      {  UINT32_C(  1008170443),  UINT32_C(   887111238),  UINT32_C(  1830531549),  UINT32_C(  2156623428) },
      {  UINT32_C(  3747868595),  UINT32_C(  1117161314),  UINT32_C(   780667667),  UINT32_C(  3684634294) },
      {  UINT32_C(  1330194292),  UINT32_C(  1488934737),  UINT32_C(  2549768594),  UINT32_C(  2223529170) } },
    { {  UINT32_C(   411203759),  UINT32_C(  3940226371),  UINT32_C(  3124061076),  UINT32_C(  3297304474) },
      {  UINT32_C(  3919988989),  UINT32_C(  1342288167),  UINT32_C(  3679748772),  UINT32_C(   562966062) },
      {  UINT32_C(  3069043362),  UINT32_C(  1406407436),  UINT32_C(   134300827),  UINT32_C(  3696551214) },
      {  UINT32_C(  4083224359),  UINT32_C(  3023386752),  UINT32_C(  2182050145),  UINT32_C(  3069445134) } },
    { {  UINT32_C(  1442798158),  UINT32_C(  1970855185),  UINT32_C(    14020723),  UINT32_C(  1698491577) },
      {  UINT32_C(  3020623461),  UINT32_C(   449357765),  UINT32_C(  2952699815),  UINT32_C(  2062158929) },
      {  UINT32_C(  1171631043),  UINT32_C(  2918358370),  UINT32_C(  3894806577),  UINT32_C(  1846493476) },
      {  UINT32_C(   904708776),  UINT32_C(  1847899598),  UINT32_C(  1959552063),  UINT32_C(  2002259063) } },
    { {  UINT32_C(  2422772815),  UINT32_C(  2056735238),  UINT32_C(  1681158115),  UINT32_C(  3797961329) },
      {  UINT32_C(   276699130),  UINT32_C(   458159845),  UINT32_C(  3034354690),  UINT32_C(  2731879627) },
      {  UINT32_C(  3908912241),  UINT32_C(  3494236039),  UINT32_C(  2160253360),  UINT32_C(  4017382784) },
      {  UINT32_C(  3817204739),  UINT32_C(  3988755797),  UINT32_C(  1388513655),  UINT32_C(    60339055) } },
    { {  UINT32_C(   210577132),  UINT32_C(  1480732582),  UINT32_C(   455084323),  UINT32_C(  1450397297) },
      {  UINT32_C(  1409986146),  UINT32_C(  1421358503),  UINT32_C(  2210800179),  UINT32_C(  4294069654) },
      {  UINT32_C(  2073666654),  UINT32_C(  1669836070),  UINT32_C(  3201618896),  UINT32_C(  1265839756) },
      {  UINT32_C(  1426283031),  UINT32_C(  3465396725),  UINT32_C(  3782105008),  UINT32_C(   721744054) } },
    { {  UINT32_C(  4140944956),  UINT32_C(  4239200835),  UINT32_C(   342204673),  UINT32_C(  2432110838) },
      {  UINT32_C(  2760993965),  UINT32_C(  1717770329),  UINT32_C(  1605833460),  UINT32_C(  2010913693) },
      {  UINT32_C(  3524193214),  UINT32_C(  3149250700),  UINT32_C(   936323954),  UINT32_C(  3871800758) },
      {  UINT32_C(  3457127785),  UINT32_C(  4256711483),  UINT32_C(  3295418817),  UINT32_C(  2362174511) } },
    { {  UINT32_C(  1612981390),  UINT32_C(  3703007225),  UINT32_C(   667892838),  UINT32_C(  3735500124) },
      {  UINT32_C(   996497672),  UINT32_C(  2650982513),  UINT32_C(  2068231911),  UINT32_C(  2169901460) },
      {  UINT32_C(  1162322282),  UINT32_C(  3303878071),  UINT32_C(  2242394192),  UINT32_C(  1269307114) },
      {  UINT32_C(   422192494),  UINT32_C(  1639490948),  UINT32_C(  4282503987),  UINT32_C(  1784261000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vsha256su1q_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsha256su1q_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsha256hq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsha256h2q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsha256su0q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsha256su1q_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
