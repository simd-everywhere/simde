#define SIMDE_TEST_MIPS_MSA_INSN addv

#include "test-msa.h"
#include "../../../simde/mips/msa/addv.h"

static int
test_simde_addv_b (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C( 116), -INT8_C(  28),  INT8_C(  38), -INT8_C(  19),  INT8_C(  23), -INT8_C(  59),  INT8_C(  57), -INT8_C(  37),
             INT8_MAX,  INT8_C(  18),  INT8_C(  39),  INT8_C( 113), -INT8_C(  93),  INT8_C(  38), -INT8_C(  44),  INT8_C(  71) },
      { -INT8_C(  60), -INT8_C(   1), -INT8_C(  16),  INT8_C(  42),  INT8_C(  50), -INT8_C(  68), -INT8_C(  61), -INT8_C(   9),
        -INT8_C(  74), -INT8_C(  49), -INT8_C( 110), -INT8_C( 120), -INT8_C(  35), -INT8_C(  56),  INT8_C(  16),  INT8_C( 105) },
      {  INT8_C(  80), -INT8_C(  29),  INT8_C(  22),  INT8_C(  23),  INT8_C(  73), -INT8_C( 127), -INT8_C(   4), -INT8_C(  46),
         INT8_C(  53), -INT8_C(  31), -INT8_C(  71), -INT8_C(   7),      INT8_MIN, -INT8_C(  18), -INT8_C(  28), -INT8_C(  80) } },
    { { -INT8_C(  84),  INT8_C(  54),  INT8_C(  86), -INT8_C(  61), -INT8_C(   5), -INT8_C( 113), -INT8_C(  97),  INT8_C( 123),
        -INT8_C(  94), -INT8_C(  58), -INT8_C(  20),  INT8_C(  69), -INT8_C(  19), -INT8_C(  64), -INT8_C( 116), -INT8_C(  79) },
      { -INT8_C(  65),  INT8_C( 124), -INT8_C(  37), -INT8_C(  14),  INT8_C(  56), -INT8_C(  97), -INT8_C(  23), -INT8_C(  17),
         INT8_C( 110),  INT8_C( 124),  INT8_C( 119),  INT8_C(  75),  INT8_C(  68), -INT8_C( 121), -INT8_C(  75), -INT8_C(  15) },
      {  INT8_C( 107), -INT8_C(  78),  INT8_C(  49), -INT8_C(  75),  INT8_C(  51),  INT8_C(  46), -INT8_C( 120),  INT8_C( 106),
         INT8_C(  16),  INT8_C(  66),  INT8_C(  99), -INT8_C( 112),  INT8_C(  49),  INT8_C(  71),  INT8_C(  65), -INT8_C(  94) } },
    { { -INT8_C(  67),  INT8_C(  11), -INT8_C(  76), -INT8_C(  72), -INT8_C( 101),  INT8_C(  83),  INT8_C(  51),  INT8_C(  61),
         INT8_C(  26),  INT8_C(  31), -INT8_C( 126),  INT8_C(   7), -INT8_C(  33),  INT8_C(  14), -INT8_C(  72), -INT8_C(  97) },
      { -INT8_C( 118), -INT8_C( 109), -INT8_C( 111), -INT8_C(  61),  INT8_C(  50),  INT8_C( 122), -INT8_C(  78), -INT8_C(  96),
        -INT8_C(  10),  INT8_C(  41), -INT8_C(  20),  INT8_C(  59), -INT8_C(  80), -INT8_C(  95),  INT8_C(  44),  INT8_C( 109) },
      {  INT8_C(  71), -INT8_C(  98),  INT8_C(  69),  INT8_C( 123), -INT8_C(  51), -INT8_C(  51), -INT8_C(  27), -INT8_C(  35),
         INT8_C(  16),  INT8_C(  72),  INT8_C( 110),  INT8_C(  66), -INT8_C( 113), -INT8_C(  81), -INT8_C(  28),  INT8_C(  12) } },
    { { -INT8_C(  84), -INT8_C(  32),  INT8_C(  37),  INT8_C(  71),  INT8_C(  52),  INT8_C(  89), -INT8_C( 124),  INT8_C(  78),
         INT8_C( 120),  INT8_C(   6),  INT8_C(  85),  INT8_C(  88),  INT8_C(  20),  INT8_C(  13), -INT8_C(   9), -INT8_C(  97) },
      { -INT8_C(  96), -INT8_C( 120),  INT8_C(  98), -INT8_C(  45),  INT8_C(   2),  INT8_C(  20),  INT8_C( 115), -INT8_C(   7),
         INT8_C(  61),  INT8_C(  95),  INT8_C(  52), -INT8_C(  19),  INT8_C(   0),  INT8_C(  96),  INT8_C(  90), -INT8_C(  83) },
      {  INT8_C(  76),  INT8_C( 104), -INT8_C( 121),  INT8_C(  26),  INT8_C(  54),  INT8_C( 109), -INT8_C(   9),  INT8_C(  71),
        -INT8_C(  75),  INT8_C( 101), -INT8_C( 119),  INT8_C(  69),  INT8_C(  20),  INT8_C( 109),  INT8_C(  81),  INT8_C(  76) } },
    { {  INT8_C(  64),      INT8_MAX, -INT8_C(  12),  INT8_C( 116), -INT8_C(  40),  INT8_C( 121), -INT8_C(  62),  INT8_C(  81),
             INT8_MAX,  INT8_C(  23), -INT8_C(  87), -INT8_C( 108),  INT8_C(  36), -INT8_C(  96),  INT8_C(  51), -INT8_C(  59) },
      {  INT8_C(  40), -INT8_C( 107), -INT8_C( 104),  INT8_C(  42), -INT8_C(  87),  INT8_C(  11),  INT8_C(  35), -INT8_C(  26),
         INT8_C( 107),  INT8_C(  87), -INT8_C(  45),  INT8_C( 107), -INT8_C(  73),  INT8_C(  45),  INT8_C(  24), -INT8_C(   8) },
      {  INT8_C( 104),  INT8_C(  20), -INT8_C( 116), -INT8_C(  98), -INT8_C( 127), -INT8_C( 124), -INT8_C(  27),  INT8_C(  55),
        -INT8_C(  22),  INT8_C( 110),  INT8_C( 124), -INT8_C(   1), -INT8_C(  37), -INT8_C(  51),  INT8_C(  75), -INT8_C(  67) } },
    { { -INT8_C(  84),  INT8_C(  13),  INT8_C( 108), -INT8_C( 123), -INT8_C( 122),  INT8_C(  47), -INT8_C(  42),  INT8_C(   5),
         INT8_C(  70),      INT8_MAX, -INT8_C( 103),  INT8_C( 107),  INT8_C(  31), -INT8_C(  52),  INT8_C(  48),  INT8_C(  71) },
      {  INT8_C(  97), -INT8_C(  56),  INT8_C( 113),  INT8_C(  10), -INT8_C(  45), -INT8_C( 107), -INT8_C(  16),  INT8_C(  62),
        -INT8_C(  20), -INT8_C(  61), -INT8_C(  86), -INT8_C(  92), -INT8_C(  16), -INT8_C(  62), -INT8_C( 100), -INT8_C(  99) },
      {  INT8_C(  13), -INT8_C(  43), -INT8_C(  35), -INT8_C( 113),  INT8_C(  89), -INT8_C(  60), -INT8_C(  58),  INT8_C(  67),
         INT8_C(  50),  INT8_C(  66),  INT8_C(  67),  INT8_C(  15),  INT8_C(  15), -INT8_C( 114), -INT8_C(  52), -INT8_C(  28) } },
    { { -INT8_C(  49),  INT8_C(   8),  INT8_C(  34),  INT8_C(  85),  INT8_C(  55), -INT8_C(   8),  INT8_C(  91),  INT8_C( 126),
         INT8_C( 119), -INT8_C(  12), -INT8_C(  23), -INT8_C( 106), -INT8_C(  63),  INT8_C(  25), -INT8_C(  35),  INT8_C(  34) },
      { -INT8_C(  31),  INT8_C(  78),  INT8_C(  45), -INT8_C(  76), -INT8_C(  29),  INT8_C(  29), -INT8_C(  13), -INT8_C(  48),
        -INT8_C(  31), -INT8_C(  99),  INT8_C( 116), -INT8_C(  47),  INT8_C(  95),  INT8_C(  16),  INT8_C( 110),  INT8_C(  47) },
      { -INT8_C(  80),  INT8_C(  86),  INT8_C(  79),  INT8_C(   9),  INT8_C(  26),  INT8_C(  21),  INT8_C(  78),  INT8_C(  78),
         INT8_C(  88), -INT8_C( 111),  INT8_C(  93),  INT8_C( 103),  INT8_C(  32),  INT8_C(  41),  INT8_C(  75),  INT8_C(  81) } },
    { {  INT8_C(  24), -INT8_C( 112), -INT8_C( 124),  INT8_C(  80), -INT8_C( 120), -INT8_C(  33), -INT8_C(  50), -INT8_C(   1),
        -INT8_C(  44), -INT8_C(  73), -INT8_C( 107), -INT8_C( 107), -INT8_C(  48),  INT8_C( 114), -INT8_C(  73), -INT8_C(  79) },
      { -INT8_C(  63), -INT8_C(  28),  INT8_C( 101), -INT8_C(  92),  INT8_C(   2),  INT8_C(  88),  INT8_C( 116), -INT8_C(  29),
        -INT8_C(  11), -INT8_C(  24), -INT8_C(  76),  INT8_C(  85), -INT8_C(   8),  INT8_C(  35), -INT8_C( 124),  INT8_C(  17) },
      { -INT8_C(  39),  INT8_C( 116), -INT8_C(  23), -INT8_C(  12), -INT8_C( 118),  INT8_C(  55),  INT8_C(  66), -INT8_C(  30),
        -INT8_C(  55), -INT8_C(  97),  INT8_C(  73), -INT8_C(  22), -INT8_C(  56), -INT8_C( 107),  INT8_C(  59), -INT8_C(  62) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v16i8 a = simde_msa_ld_b(test_vec[i].a, 0);
    simde_v16i8 b = simde_msa_ld_b(test_vec[i].b, 0);
    simde_v16i8 r = simde_msa_addv_b(a, b);

    simde_test_msa_v16i8_assert_equal(r, simde_msa_ld_b(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v16i8 a = simde_test_msa_v16i8_random();
    simde_v16i8 b = simde_test_msa_v16i8_random();
    simde_v16i8 r = simde_msa_addv_b(a, b);

    simde_test_msa_v16i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v16i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v16i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_addv_h (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 30997), -INT16_C(  1599), -INT16_C( 12412), -INT16_C(   899), -INT16_C(  5872), -INT16_C( 18922),  INT16_C(  5928), -INT16_C( 31405) },
      { -INT16_C( 20798),  INT16_C(  9201), -INT16_C( 20369), -INT16_C( 22053), -INT16_C( 10807), -INT16_C(  1995), -INT16_C( 18801),  INT16_C( 31602) },
      {  INT16_C( 13741),  INT16_C(  7602),  INT16_C( 32755), -INT16_C( 22952), -INT16_C( 16679), -INT16_C( 20917), -INT16_C( 12873),  INT16_C(   197) } },
    { {  INT16_C( 13372), -INT16_C( 16268), -INT16_C(  3837),  INT16_C(  5052), -INT16_C( 11301),  INT16_C(   969),  INT16_C(  7402), -INT16_C( 21368) },
      {  INT16_C( 31179),  INT16_C( 15056), -INT16_C( 21718), -INT16_C(  3101),  INT16_C(  6272),  INT16_C(  4332),  INT16_C( 24270),  INT16_C(  2955) },
      { -INT16_C( 20985), -INT16_C(  1212), -INT16_C( 25555),  INT16_C(  1951), -INT16_C(  5029),  INT16_C(  5301),  INT16_C( 31672), -INT16_C( 18413) } },
    { { -INT16_C(   110), -INT16_C( 27189), -INT16_C( 30480), -INT16_C( 13400),  INT16_C( 29019),  INT16_C( 17871),  INT16_C( 22414),  INT16_C( 23026) },
      { -INT16_C( 15663), -INT16_C(  1133),  INT16_C( 30317), -INT16_C(  4370), -INT16_C(  9586),  INT16_C( 23806), -INT16_C( 30407), -INT16_C( 13465) },
      { -INT16_C( 15773), -INT16_C( 28322), -INT16_C(   163), -INT16_C( 17770),  INT16_C( 19433), -INT16_C( 23859), -INT16_C(  7993),  INT16_C(  9561) } },
    { {  INT16_C( 13192),  INT16_C( 30817),  INT16_C(  2491),  INT16_C(  5700),  INT16_C(  4987),  INT16_C(  2395),  INT16_C( 19818),  INT16_C( 15202) },
      { -INT16_C(  2801),  INT16_C( 32054),  INT16_C(  9579), -INT16_C(  1685),  INT16_C( 27135),  INT16_C( 14421), -INT16_C( 16910),  INT16_C( 31236) },
      {  INT16_C( 10391), -INT16_C(  2665),  INT16_C( 12070),  INT16_C(  4015),  INT16_C( 32122),  INT16_C( 16816),  INT16_C(  2908), -INT16_C( 19098) } },
    { {  INT16_C( 26096), -INT16_C( 21518),  INT16_C( 13934), -INT16_C(  5695),  INT16_C(  7241), -INT16_C( 19214),  INT16_C( 21610),  INT16_C( 31215) },
      {  INT16_C(  9801), -INT16_C( 19210),  INT16_C( 24907),  INT16_C( 19117),  INT16_C(   970), -INT16_C( 17277), -INT16_C( 30784), -INT16_C( 20426) },
      { -INT16_C( 29639),  INT16_C( 24808), -INT16_C( 26695),  INT16_C( 13422),  INT16_C(  8211),  INT16_C( 29045), -INT16_C(  9174),  INT16_C( 10789) } },
    { {  INT16_C( 10732),  INT16_C( 23131),  INT16_C(  7263), -INT16_C( 22204),  INT16_C( 13880), -INT16_C( 23971),  INT16_C( 19595), -INT16_C( 11236) },
      {  INT16_C(  4722), -INT16_C( 17015),  INT16_C( 13940),  INT16_C( 15880), -INT16_C( 29895), -INT16_C(  1541),  INT16_C( 12562), -INT16_C(   343) },
      {  INT16_C( 15454),  INT16_C(  6116),  INT16_C( 21203), -INT16_C(  6324), -INT16_C( 16015), -INT16_C( 25512),  INT16_C( 32157), -INT16_C( 11579) } },
    { {  INT16_C(  1114), -INT16_C( 17832), -INT16_C( 25568),  INT16_C( 22883), -INT16_C( 16173),  INT16_C( 24315),  INT16_C(  5900),  INT16_C( 32562) },
      { -INT16_C( 17622), -INT16_C( 25028),  INT16_C( 17650),  INT16_C( 11228), -INT16_C( 10289), -INT16_C(  7899), -INT16_C( 12791),  INT16_C( 25567) },
      { -INT16_C( 16508),  INT16_C( 22676), -INT16_C(  7918), -INT16_C( 31425), -INT16_C( 26462),  INT16_C( 16416), -INT16_C(  6891), -INT16_C(  7407) } },
    { {  INT16_C( 14547), -INT16_C(  3299), -INT16_C( 32556), -INT16_C( 22708),  INT16_C( 18496),  INT16_C( 19717),  INT16_C( 14431), -INT16_C( 30260) },
      {  INT16_C(  2291), -INT16_C(  6873),  INT16_C(  1101),  INT16_C(  7185),  INT16_C( 14043), -INT16_C(  6914), -INT16_C(  8956), -INT16_C( 10424) },
      {  INT16_C( 16838), -INT16_C( 10172), -INT16_C( 31455), -INT16_C( 15523),  INT16_C( 32539),  INT16_C( 12803),  INT16_C(  5475),  INT16_C( 24852) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v8i16 a = simde_msa_ld_h(test_vec[i].a, 0);
    simde_v8i16 b = simde_msa_ld_h(test_vec[i].b, 0);
    simde_v8i16 r = simde_msa_addv_h(a, b);

    simde_test_msa_v8i16_assert_equal(r, simde_msa_ld_h(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v8i16 a = simde_test_msa_v8i16_random();
    simde_v8i16 b = simde_test_msa_v8i16_random();
    simde_v8i16 r = simde_msa_addv_h(a, b);

    simde_test_msa_v8i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v8i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v8i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_addv_w (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1971869139),  INT32_C(  1122487640), -INT32_C(   505886277),  INT32_C(   974474570) },
      {  INT32_C(   690202255), -INT32_C(   117222443), -INT32_C(   169288089),  INT32_C(   402966340) },
      { -INT32_C(  1632895902),  INT32_C(  1005265197), -INT32_C(   675174366),  INT32_C(  1377440910) } },
    { {  INT32_C(  1972210716),  INT32_C(   347567193), -INT32_C(  2013884611),  INT32_C(  1824590813) },
      { -INT32_C(  2036996943), -INT32_C(  1619027912), -INT32_C(  1147901833),  INT32_C(  1288935727) },
      { -INT32_C(    64786227), -INT32_C(  1271460719),  INT32_C(  1133180852), -INT32_C(  1181440756) } },
    { {  INT32_C(  2143379493),  INT32_C(   294877396), -INT32_C(   459699961),  INT32_C(  1162893972) },
      {  INT32_C(  2009916991), -INT32_C(   183088258), -INT32_C(   474895437),  INT32_C(  1764721732) },
      { -INT32_C(   141670812),  INT32_C(   111789138), -INT32_C(   934595398), -INT32_C(  1367351592) } },
    { { -INT32_C(  1175916315),  INT32_C(  1875606632), -INT32_C(  1705745403), -INT32_C(    35674946) },
      {  INT32_C(   158641034), -INT32_C(  1426158601),  INT32_C(  2056105782),  INT32_C(   434355252) },
      { -INT32_C(  1017275281),  INT32_C(   449448031),  INT32_C(   350360379),  INT32_C(   398680306) } },
    { {  INT32_C(   349359276),  INT32_C(  1300536648), -INT32_C(  1058547711),  INT32_C(   129877884) },
      {  INT32_C(  1762669170), -INT32_C(   216789315), -INT32_C(   227696194),  INT32_C(   168513630) },
      {  INT32_C(  2112028446),  INT32_C(  1083747333), -INT32_C(  1286243905),  INT32_C(   298391514) } },
    { {  INT32_C(  1679809820),  INT32_C(  2092082043), -INT32_C(   147023493), -INT32_C(   738264480) },
      { -INT32_C(   381940180), -INT32_C(   606318563),  INT32_C(  1355631090), -INT32_C(  1235560295) },
      {  INT32_C(  1297869640),  INT32_C(  1485763480),  INT32_C(  1208607597), -INT32_C(  1973824775) } },
    { {  INT32_C(   807041461), -INT32_C(  1750217700), -INT32_C(   963647130),  INT32_C(   261721571) },
      { -INT32_C(  1174874468),  INT32_C(   412406822), -INT32_C(  1217896163), -INT32_C(   294796487) },
      { -INT32_C(   367833007), -INT32_C(  1337810878),  INT32_C(  2113424003), -INT32_C(    33074916) } },
    { {  INT32_C(  1495238460), -INT32_C(  1158624172), -INT32_C(  1719631947), -INT32_C(  1448601075) },
      {  INT32_C(   375562736), -INT32_C(  1825573259), -INT32_C(  1874159785), -INT32_C(  1753303206) },
      {  INT32_C(  1870801196),  INT32_C(  1310769865),  INT32_C(   701175564),  INT32_C(  1093063015) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v4i32 a = simde_msa_ld_w(test_vec[i].a, 0);
    simde_v4i32 b = simde_msa_ld_w(test_vec[i].b, 0);
    simde_v4i32 r = simde_msa_addv_w(a, b);

    simde_test_msa_v4i32_assert_equal(r, simde_msa_ld_w(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v4i32 a = simde_test_msa_v4i32_random();
    simde_v4i32 b = simde_test_msa_v4i32_random();
    simde_v4i32 r = simde_msa_addv_w(a, b);

    simde_test_msa_v4i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v4i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v4i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_addv_d (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 2255424257447206206), -INT64_C( 2948062358972871328) },
      { -INT64_C( 4248552037686609919),  INT64_C( 5306879780364571828) },
      { -INT64_C( 1993127780239403713),  INT64_C( 2358817421391700500) } },
    { { -INT64_C( 2956287189448878735),  INT64_C( 1419576245091545589) },
      {  INT64_C( 8143797566728479185), -INT64_C( 7116490961181451800) },
      {  INT64_C( 5187510377279600450), -INT64_C( 5696914716089906211) } },
    { {  INT64_C( 3965262521739778491),  INT64_C( 8379166610506861091) },
      {  INT64_C( 5807311898159600488), -INT64_C(  587015805221005552) },
      { -INT64_C( 8674169653810172637),  INT64_C( 7792150805285855539) } },
    { { -INT64_C( 1868378377163353447),  INT64_C( 6093481261078881657) },
      {  INT64_C(  787586752934724407),  INT64_C( 5502309894810186280) },
      { -INT64_C( 1080791624228629040), -INT64_C( 6850952917820483679) } },
    { {  INT64_C( 3250817952196822131), -INT64_C( 3197596845596854178) },
      {  INT64_C( 5918680069209987358), -INT64_C(  103279827561780590) },
      {  INT64_C( 9169498021406809489), -INT64_C( 3300876673158634768) } },
    { {  INT64_C( 5726698497969010839), -INT64_C( 4901540797807410294) },
      {  INT64_C( 6904290686432210003),  INT64_C( 3668803785958131553) },
      { -INT64_C( 5815754889308330774), -INT64_C( 1232737011849278741) } },
    { { -INT64_C(  419408225646076179),  INT64_C( 6129990640158689465) },
      {  INT64_C( 4517854646707152518),  INT64_C( 8716739669333268011) },
      {  INT64_C( 4098446421061076339), -INT64_C( 3600013764217594140) } },
    { {  INT64_C( 2710467053366965555),  INT64_C( 6819452419944791371) },
      {  INT64_C( 5084954419002439285),  INT64_C(  269095370276781241) },
      {  INT64_C( 7795421472369404840),  INT64_C( 7088547790221572612) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v2i64 a = simde_msa_ld_d(test_vec[i].a, 0);
    simde_v2i64 b = simde_msa_ld_d(test_vec[i].b, 0);
    simde_v2i64 r = simde_msa_addv_d(a, b);

    simde_test_msa_v2i64_assert_equal(r, simde_msa_ld_d(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v2i64 a = simde_test_msa_v2i64_random();
    simde_v2i64 b = simde_test_msa_v2i64_random();
    simde_v2i64 r = simde_msa_addv_d(a, b);

    simde_test_msa_v2i64_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v2i64_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v2i64_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(addv_b)
SIMDE_TEST_FUNC_LIST_ENTRY(addv_h)
SIMDE_TEST_FUNC_LIST_ENTRY(addv_w)
SIMDE_TEST_FUNC_LIST_ENTRY(addv_d)
SIMDE_TEST_FUNC_LIST_END

#include "test-msa-footer.h"
