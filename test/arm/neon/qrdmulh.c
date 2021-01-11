#define SIMDE_TEST_ARM_NEON_INSN qrdmulh

#include "test-neon.h"
#include "../../../simde/arm/neon/qrdmulh.h"

static int
test_simde_vqrdmulh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 24408),  INT16_C(  8011), -INT16_C( 30441), -INT16_C( 30215) },
      {  INT16_C(  4356),  INT16_C( 11308),  INT16_C(  3238), -INT16_C( 19917) },
      {  INT16_C(  3245),  INT16_C(  2765), -INT16_C(  3008),  INT16_C( 18365) } },
    { {  INT16_C( 11964),  INT16_C( 20417), -INT16_C(  7014),  INT16_C(  9797) },
      {  INT16_C(  3004),  INT16_C(  6963), -INT16_C( 19145), -INT16_C( 28864) },
      {  INT16_C(  1097),  INT16_C(  4338),  INT16_C(  4098), -INT16_C(  8630) } },
    { { -INT16_C( 29676),  INT16_C( 11183), -INT16_C( 22507),  INT16_C(  6580) },
      { -INT16_C(  7751),  INT16_C( 24645),  INT16_C( 30957), -INT16_C( 21998) },
      {  INT16_C(  7020),  INT16_C(  8411), -INT16_C( 21263), -INT16_C(  4417) } },
    { { -INT16_C( 11354),  INT16_C( 16889),  INT16_C( 16055),  INT16_C( 29799) },
      { -INT16_C( 26039), -INT16_C( 32625), -INT16_C( 12465),  INT16_C( 25360) },
      {  INT16_C(  9022), -INT16_C( 16815), -INT16_C(  6107),  INT16_C( 23062) } },
    { { -INT16_C( 16549),  INT16_C( 28814),  INT16_C( 17255),  INT16_C(  8329) },
      { -INT16_C( 12508),  INT16_C(  4480), -INT16_C( 28089), -INT16_C(  4421) },
      {  INT16_C(  6317),  INT16_C(  3939), -INT16_C( 14791), -INT16_C(  1124) } },
    { { -INT16_C( 19354),  INT16_C(  7471), -INT16_C( 26894),  INT16_C( 15249) },
      {  INT16_C(  8240), -INT16_C( 32580), -INT16_C( 13072),  INT16_C( 19427) },
      { -INT16_C(  4867), -INT16_C(  7428),  INT16_C( 10729),  INT16_C(  9041) } },
    { {  INT16_C( 29323), -INT16_C(  3396),  INT16_C( 17845), -INT16_C(  9966) },
      { -INT16_C( 27884),  INT16_C( 23786), -INT16_C( 23003), -INT16_C( 29878) },
      { -INT16_C( 24952), -INT16_C(  2465), -INT16_C( 12527),  INT16_C(  9087) } },
    { {  INT16_C( 31066),  INT16_C( 19881),  INT16_C( 14863),  INT16_C( 16264) },
      {  INT16_C( 17499),  INT16_C( 19391), -INT16_C( 23792), -INT16_C( 25706) },
      {  INT16_C( 16590),  INT16_C( 11765), -INT16_C( 10792), -INT16_C( 12759) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vqrdmulh_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vqrdmulh_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulh_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1899441268),  INT32_C(   839689240) },
      { -INT32_C(  1702480800), -INT32_C(  1555117258) },
      { -INT32_C(  1505837911), -INT32_C(   608067600) } },
    { { -INT32_C(   252180371), -INT32_C(    33985746) },
      {  INT32_C(  1179500889), -INT32_C(  1494958031) },
      { -INT32_C(   138509540),  INT32_C(    23658976) } },
    { {  INT32_C(    68623340),  INT32_C(   540419007) },
      { -INT32_C(  1900364456), -INT32_C(   181270136) },
      { -INT32_C(    60726589), -INT32_C(    45617030) } },
    { {  INT32_C(  1088760337), -INT32_C(   281157995) },
      { -INT32_C(   785020257),  INT32_C(   930552139) },
      { -INT32_C(   398000199), -INT32_C(   121831975) } },
    { { -INT32_C(   214135244),  INT32_C(   152269489) },
      { -INT32_C(  1214722513), -INT32_C(   391329065) },
      {  INT32_C(   121125440), -INT32_C(    27747581) } },
    { { -INT32_C(  1993829644),  INT32_C(   276325744) },
      {  INT32_C(  1004645872), -INT32_C(    93169466) },
      { -INT32_C(   932762735), -INT32_C(    11988507) } },
    { { -INT32_C(  1745965338),  INT32_C(  1352728865) },
      { -INT32_C(  1509410353), -INT32_C(   141577213) },
      {  INT32_C(  1227193585), -INT32_C(    89181393) } },
    { { -INT32_C(  1216301242),  INT32_C(   231209245) },
      {  INT32_C(  1833478310), -INT32_C(   429409792) },
      { -INT32_C(  1038453516), -INT32_C(    46232489) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vqrdmulh_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vqrdmulh_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(   362),  INT16_C( 17724),  INT16_C(  9860), -INT16_C( 26948),  INT16_C( 19934),  INT16_C( 20294),  INT16_C( 24470),  INT16_C( 32030) },
      { -INT16_C( 27709),  INT16_C(  4190),  INT16_C(  5967), -INT16_C( 18116), -INT16_C(  5194), -INT16_C( 32603),  INT16_C( 21823), -INT16_C( 22254) },
      { -INT16_C(   306),  INT16_C(  2266),  INT16_C(  1795),  INT16_C( 14898), -INT16_C(  3160), -INT16_C( 20192),  INT16_C( 16297), -INT16_C( 21753) } },
    { {  INT16_C( 20311), -INT16_C(  9233), -INT16_C( 21643),  INT16_C( 21361), -INT16_C( 18440), -INT16_C( 29022), -INT16_C( 16105), -INT16_C(  9716) },
      {  INT16_C( 27220), -INT16_C( 23318),  INT16_C(  9857),  INT16_C( 14173),  INT16_C(   785),  INT16_C( 20664), -INT16_C( 13736), -INT16_C( 20486) },
      {  INT16_C( 16872),  INT16_C(  6570), -INT16_C(  6510),  INT16_C(  9239), -INT16_C(   442), -INT16_C( 18302),  INT16_C(  6751),  INT16_C(  6074) } },
    { { -INT16_C(  5863), -INT16_C( 28790), -INT16_C(   876), -INT16_C( 29470), -INT16_C( 31309), -INT16_C( 13797),  INT16_C( 10054), -INT16_C( 25948) },
      { -INT16_C( 29039),  INT16_C(  4670), -INT16_C( 25420), -INT16_C( 14774),  INT16_C(   671), -INT16_C(  2282),  INT16_C(  4300), -INT16_C(  6489) },
      {  INT16_C(  5196), -INT16_C(  4103),  INT16_C(   680),  INT16_C( 13287), -INT16_C(   641),  INT16_C(   961),  INT16_C(  1319),  INT16_C(  5138) } },
    { {  INT16_C( 12793), -INT16_C( 29323),  INT16_C( 22317), -INT16_C(  7910),  INT16_C( 13788),  INT16_C(  8875),  INT16_C( 20572), -INT16_C(  4675) },
      { -INT16_C(  1058), -INT16_C( 27649),  INT16_C( 18839),  INT16_C( 13913),  INT16_C( 28491),  INT16_C(  6190), -INT16_C( 10880),  INT16_C( 31230) },
      { -INT16_C(   413),  INT16_C( 24742),  INT16_C( 12831), -INT16_C(  3359),  INT16_C( 11988),  INT16_C(  1677), -INT16_C(  6831), -INT16_C(  4456) } },
    { {  INT16_C( 29446),  INT16_C( 13319),  INT16_C(  8650), -INT16_C( 22763), -INT16_C( 16298), -INT16_C( 19767), -INT16_C( 31216), -INT16_C(  4193) },
      { -INT16_C( 24958),  INT16_C(  6530), -INT16_C(  9240),  INT16_C( 13136),  INT16_C( 32330), -INT16_C( 13749),  INT16_C( 18771),  INT16_C( 22852) },
      { -INT16_C( 22428),  INT16_C(  2654), -INT16_C(  2439), -INT16_C(  9125), -INT16_C( 16080),  INT16_C(  8294), -INT16_C( 17882), -INT16_C(  2924) } },
    { {  INT16_C( 19388), -INT16_C( 30835), -INT16_C( 23956), -INT16_C( 15826), -INT16_C(  2205),  INT16_C( 29556),  INT16_C(  4990),  INT16_C(    98) },
      { -INT16_C(  6991), -INT16_C( 26343),  INT16_C( 27071),  INT16_C(  2765),  INT16_C(  6375),  INT16_C( 15060),  INT16_C(  6242),  INT16_C(  7828) },
      { -INT16_C(  4136),  INT16_C( 24789), -INT16_C( 19791), -INT16_C(  1335), -INT16_C(   429),  INT16_C( 13584),  INT16_C(   951),  INT16_C(    23) } },
    { {  INT16_C(  8547), -INT16_C( 12379), -INT16_C( 11324),  INT16_C( 10129),  INT16_C(  1483),  INT16_C( 18842), -INT16_C(   744), -INT16_C( 13751) },
      {  INT16_C( 25313), -INT16_C( 24221),  INT16_C( 12492), -INT16_C( 19541),  INT16_C( 32585), -INT16_C( 21522), -INT16_C( 32104), -INT16_C(  1079) },
      {  INT16_C(  6602),  INT16_C(  9150), -INT16_C(  4317), -INT16_C(  6040),  INT16_C(  1475), -INT16_C( 12375),  INT16_C(   729),  INT16_C(   453) } },
    { {  INT16_C( 28579),  INT16_C( 26571),  INT16_C( 23618),  INT16_C(  3470),  INT16_C( 10594),  INT16_C( 31318), -INT16_C( 24794),  INT16_C(  1860) },
      { -INT16_C( 22526), -INT16_C( 12632),  INT16_C( 21464),  INT16_C(  8577),  INT16_C( 28627),  INT16_C( 27596), -INT16_C( 26895), -INT16_C( 27290) },
      { -INT16_C( 19646), -INT16_C( 10243),  INT16_C( 15470),  INT16_C(   908),  INT16_C(  9255),  INT16_C( 26375),  INT16_C( 20350), -INT16_C(  1549) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vqrdmulhq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vqrdmulhq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1138864092),  INT32_C(   288563958), -INT32_C(  1259870191), -INT32_C(   155258730) },
      {  INT32_C(  2111102674),  INT32_C(  1634858731), -INT32_C(   551689891), -INT32_C(   930088541) },
      { -INT32_C(  1119570355),  INT32_C(   219680977),  INT32_C(   323661439),  INT32_C(    67243523) } },
    { {  INT32_C(  1082436937), -INT32_C(   531515185),  INT32_C(   915749280), -INT32_C(    80981207) },
      {  INT32_C(   494403890),  INT32_C(  1417603831),  INT32_C(  1848876235), -INT32_C(   566836587) },
      {  INT32_C(   249203775), -INT32_C(   350865518),  INT32_C(   788414423),  INT32_C(    21375302) } },
    { {  INT32_C(  1042201455),  INT32_C(   320827507), -INT32_C(   766921559),  INT32_C(   969766151) },
      {  INT32_C(  1834370678), -INT32_C(    71117520),  INT32_C(   107607409),  INT32_C(   669294776) },
      {  INT32_C(   890243701), -INT32_C(    10624741), -INT32_C(    38429369),  INT32_C(   302241845) } },
    { { -INT32_C(   832175269),  INT32_C(   484541811),  INT32_C(  1089350201),  INT32_C(   377142175) },
      {  INT32_C(   830722049),  INT32_C(   372000165), -INT32_C(   216230341), -INT32_C(  1860566730) },
      { -INT32_C(   321914602),  INT32_C(    83935276), -INT32_C(   109686780), -INT32_C(   326753679) } },
    { {  INT32_C(  2002747396),  INT32_C(  1049837573),  INT32_C(   159351146),  INT32_C(  1042282812) },
      {  INT32_C(  1869587401),  INT32_C(   595959016),  INT32_C(  1746313778), -INT32_C(  1476841053) },
      {  INT32_C(  1743580820),  INT32_C(   291345719),  INT32_C(   129582873), -INT32_C(   716785922) } },
    { { -INT32_C(  1222747983),  INT32_C(    49656216),  INT32_C(  1846244402),  INT32_C(   934030189) },
      { -INT32_C(  1230627634), -INT32_C(   354800712),  INT32_C(  1884483789), -INT32_C(   753448159) },
      {  INT32_C(   700702638), -INT32_C(     8204049),  INT32_C(  1620136968), -INT32_C(   327706023) } },
    { {  INT32_C(   998913443),  INT32_C(   406683622),  INT32_C(  1636255988),  INT32_C(  1100493683) },
      {  INT32_C(   133709391),  INT32_C(   938594922), -INT32_C(   458734654),  INT32_C(   834125710) },
      {  INT32_C(    62195635),  INT32_C(   177748121), -INT32_C(   349528773),  INT32_C(   427453813) } },
    { { -INT32_C(   613662219), -INT32_C(  1259034176),  INT32_C(  1695972338), -INT32_C(    22565202) },
      {  INT32_C(  1459986413),  INT32_C(   865007473), -INT32_C(   921225670), -INT32_C(   335884554) },
      { -INT32_C(   417203876), -INT32_C(   507139587), -INT32_C(   727536740),  INT32_C(     3529388) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vqrdmulhq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vqrdmulhq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulh_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
