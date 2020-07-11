#define SIMDE_TEST_ARM_NEON_INSN mull

#include "test-neon.h"
#include "../../../simde/arm/neon/mull.h"

static int
test_simde_vmull_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT8_C(  80), -INT8_C(  57),      INT8_MIN, -INT8_C(  68),  INT8_C(  13), -INT8_C(  44),  INT8_C(   8),  INT8_C(  65) },
      { -INT8_C(  55), -INT8_C(  20),  INT8_C(  56), -INT8_C(  54),  INT8_C( 110),  INT8_C(  55), -INT8_C(  97), -INT8_C(   8) },
      { -INT16_C(  4400),  INT16_C(  1140), -INT16_C(  7168),  INT16_C(  3672),  INT16_C(  1430), -INT16_C(  2420), -INT16_C(   776), -INT16_C(   520) } },
    { {  INT8_C(  90),  INT8_C(  52),  INT8_C(  32),  INT8_C(  61), -INT8_C( 126),  INT8_C(  97),  INT8_C(  42), -INT8_C(  90) },
      {  INT8_C( 100),  INT8_C(  38), -INT8_C( 122),  INT8_C( 112), -INT8_C(  57),  INT8_C(  19), -INT8_C(  61),  INT8_C(  23) },
      {  INT16_C(  9000),  INT16_C(  1976), -INT16_C(  3904),  INT16_C(  6832),  INT16_C(  7182),  INT16_C(  1843), -INT16_C(  2562), -INT16_C(  2070) } },
    { { -INT8_C(  38),  INT8_C(  68), -INT8_C(  44), -INT8_C(  24),  INT8_C(  24), -INT8_C(  36),  INT8_C(  41), -INT8_C(  31) },
      { -INT8_C(  56),  INT8_C(  97), -INT8_C(  85),  INT8_C(  55), -INT8_C( 104),  INT8_C(  74),  INT8_C(  47), -INT8_C(  14) },
      {  INT16_C(  2128),  INT16_C(  6596),  INT16_C(  3740), -INT16_C(  1320), -INT16_C(  2496), -INT16_C(  2664),  INT16_C(  1927),  INT16_C(   434) } },
    { {  INT8_C( 126),  INT8_C(  80),  INT8_C(  48),  INT8_C(   1), -INT8_C(  79),  INT8_C(  90), -INT8_C(  89),  INT8_C(  21) },
      {      INT8_MIN,  INT8_C(  46), -INT8_C( 123),  INT8_C(  72),  INT8_C(  65),  INT8_C(  73),  INT8_C(  95),  INT8_C(  28) },
      { -INT16_C( 16128),  INT16_C(  3680), -INT16_C(  5904),  INT16_C(    72), -INT16_C(  5135),  INT16_C(  6570), -INT16_C(  8455),  INT16_C(   588) } },
    { { -INT8_C( 115),  INT8_C(  51),  INT8_C(   4), -INT8_C(  91),  INT8_C(  16),  INT8_C(  45), -INT8_C( 122), -INT8_C(  40) },
      { -INT8_C( 114),  INT8_C(  49),  INT8_C(  15),  INT8_C(  38),  INT8_C( 123),  INT8_C(  63),  INT8_C(  25), -INT8_C(   7) },
      {  INT16_C( 13110),  INT16_C(  2499),  INT16_C(    60), -INT16_C(  3458),  INT16_C(  1968),  INT16_C(  2835), -INT16_C(  3050),  INT16_C(   280) } },
    { { -INT8_C( 113),  INT8_C(  73), -INT8_C(   6),  INT8_C(  64), -INT8_C(  93), -INT8_C(  94),  INT8_C(  86),  INT8_C(  36) },
      { -INT8_C(  48), -INT8_C(  37),  INT8_C( 108),  INT8_C(  17),  INT8_C(  36), -INT8_C(  53),  INT8_C(  45), -INT8_C(  79) },
      {  INT16_C(  5424), -INT16_C(  2701), -INT16_C(   648),  INT16_C(  1088), -INT16_C(  3348),  INT16_C(  4982),  INT16_C(  3870), -INT16_C(  2844) } },
    { { -INT8_C(   1),  INT8_C(  49),  INT8_C(  86),  INT8_C(  15),  INT8_C(  94), -INT8_C(  36), -INT8_C(  25), -INT8_C(  20) },
      {  INT8_C(  13), -INT8_C(   9),  INT8_C(  19), -INT8_C( 120),  INT8_C(  54),  INT8_C(  44), -INT8_C( 126), -INT8_C(  59) },
      { -INT16_C(    13), -INT16_C(   441),  INT16_C(  1634), -INT16_C(  1800),  INT16_C(  5076), -INT16_C(  1584),  INT16_C(  3150),  INT16_C(  1180) } },
    { {  INT8_C( 117),  INT8_C( 124),  INT8_C(   5),  INT8_C(  24),  INT8_C(  30),  INT8_C(  91),  INT8_C(  60), -INT8_C(  18) },
      {  INT8_C(  55), -INT8_C(  88),  INT8_C(   0),  INT8_C(  91),  INT8_C( 116),  INT8_C(  45),  INT8_C(  13),  INT8_C( 115) },
      {  INT16_C(  6435), -INT16_C( 10912),  INT16_C(     0),  INT16_C(  2184),  INT16_C(  3480),  INT16_C(  4095),  INT16_C(   780), -INT16_C(  2070) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int16x8_t r = simde_vmull_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmull_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT16_C( 11230),  INT16_C( 11512), -INT16_C( 32461), -INT16_C( 31562) },
      {  INT16_C( 29011), -INT16_C(  4051),  INT16_C( 24636), -INT16_C( 23193) },
      {  INT32_C(   325793530), -INT32_C(    46635112), -INT32_C(   799709196),  INT32_C(   732017466) } },
    { {  INT16_C( 17728),  INT16_C( 31395),  INT16_C(  5945),  INT16_C(  5959) },
      {  INT16_C(  2425), -INT16_C( 15905), -INT16_C( 10338),  INT16_C( 31939) },
      {  INT32_C(    42990400), -INT32_C(   499337475), -INT32_C(    61459410),  INT32_C(   190324501) } },
    { { -INT16_C( 17662),  INT16_C( 13993),  INT16_C( 24380), -INT16_C( 28486) },
      { -INT16_C(  6192),  INT16_C(  3200), -INT16_C(  6329), -INT16_C( 30542) },
      {  INT32_C(   109363104),  INT32_C(    44777600), -INT32_C(   154301020),  INT32_C(   870019412) } },
    { {  INT16_C( 21805),  INT16_C( 26114),  INT16_C( 18796), -INT16_C(  6787) },
      {  INT16_C( 23635), -INT16_C(  3674),  INT16_C( 27188),  INT16_C( 13933) },
      {  INT32_C(   515361175), -INT32_C(    95942836),  INT32_C(   511025648), -INT32_C(    94563271) } },
    { {  INT16_C(  5669),  INT16_C( 25196),  INT16_C(  9846),  INT16_C( 18162) },
      {  INT16_C( 29198),  INT16_C( 21843),  INT16_C(  1369), -INT16_C( 31011) },
      {  INT32_C(   165523462),  INT32_C(   550356228),  INT32_C(    13479174), -INT32_C(   563221782) } },
    { { -INT16_C(  8358), -INT16_C( 14612),  INT16_C( 26921),  INT16_C( 31916) },
      {  INT16_C( 21190), -INT16_C(  1427), -INT16_C(  9540), -INT16_C(  7632) },
      { -INT32_C(   177106020),  INT32_C(    20851324), -INT32_C(   256826340), -INT32_C(   243582912) } },
    { { -INT16_C( 25103),  INT16_C( 26436),  INT16_C( 14019), -INT16_C( 11859) },
      {  INT16_C(   168),  INT16_C(   295),  INT16_C(  1029),  INT16_C( 24456) },
      { -INT32_C(     4217304),  INT32_C(     7798620),  INT32_C(    14425551), -INT32_C(   290023704) } },
    { {  INT16_C( 29924),  INT16_C(  3366), -INT16_C( 11554), -INT16_C( 23415) },
      { -INT16_C(  2524), -INT16_C(  7778), -INT16_C( 12592), -INT16_C( 15933) },
      { -INT32_C(    75528176), -INT32_C(    26180748),  INT32_C(   145487968),  INT32_C(   373071195) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vmull_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmull_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(   930126813), -INT32_C(   560729004) },
      {  INT32_C(   166776726), -INT32_C(   422116933) },
      {  INT64_C(  155123504636954238),  INT64_C(  236693207412624732) } },
    { {  INT32_C(  1728012372),  INT32_C(   633898368) },
      { -INT32_C(  1137785715), -INT32_C(  1374263343) },
      { -INT64_C( 1966107792204865980), -INT64_C(  871143290329924224) } },
    { {  INT32_C(  1457882626),  INT32_C(   271874170) },
      {  INT32_C(    35267655),  INT32_C(  2045309221) },
      {  INT64_C(   51416101484262030),  INT64_C(  556066746852721570) } },
    { { -INT32_C(   757078191), -INT32_C(    84433043) },
      {  INT32_C(  1018635627), -INT32_C(  1897214580) },
      { -INT64_C(  771186817777310757),  INT64_C(  160187600213366940) } },
    { { -INT32_C(   823865517), -INT32_C(  1898047417) },
      {  INT32_C(  1636890684),  INT32_C(  1004173801) },
      { -INT64_C( 1348577789646143628), -INT64_C( 1905969489207122017) } },
    { { -INT32_C(   854738592), -INT32_C(   876084128) },
      { -INT32_C(  1241022678), -INT32_C(  1622806196) },
      {  INT64_C( 1060749976433789376),  INT64_C( 1421714751135657088) } },
    { {  INT32_C(   124594624),  INT32_C(  2123713602) },
      {  INT32_C(   786441796), -INT32_C(     9848161) },
      {  INT64_C(   97986419870504704), -INT64_C(   20914673470385922) } },
    { { -INT32_C(   724732300), -INT32_C(  1532979846) },
      {  INT32_C(  1616619284),  INT32_C(  1509925017) },
      { -INT64_C( 1171616211917673200), -INT64_C( 2314684620032207382) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vmull_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmull_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT8_C( 94), UINT8_C(152), UINT8_C( 27), UINT8_C(118), UINT8_C(190), UINT8_C(231), UINT8_C( 17), UINT8_C(211) },
      { UINT8_C( 99), UINT8_C(112), UINT8_C( 80), UINT8_C(144), UINT8_C(181), UINT8_C(106), UINT8_C( 70), UINT8_C( 39) },
      { UINT16_C( 9306), UINT16_C(17024), UINT16_C( 2160), UINT16_C(16992), UINT16_C(34390), UINT16_C(24486), UINT16_C( 1190), UINT16_C( 8229) } },
    { { UINT8_C(237), UINT8_C(190), UINT8_C( 61), UINT8_C( 90), UINT8_C( 53), UINT8_C( 74), UINT8_C(239), UINT8_C( 23) },
      { UINT8_C( 70), UINT8_C(227),    UINT8_MAX, UINT8_C(159), UINT8_C(184), UINT8_C(227), UINT8_C(105), UINT8_C( 22) },
      { UINT16_C(16590), UINT16_C(43130), UINT16_C(15555), UINT16_C(14310), UINT16_C( 9752), UINT16_C(16798), UINT16_C(25095), UINT16_C(  506) } },
    { { UINT8_C(123), UINT8_C(132), UINT8_C(141), UINT8_C( 57), UINT8_C(108), UINT8_C(158), UINT8_C( 12), UINT8_C(207) },
      { UINT8_C( 14), UINT8_C( 93), UINT8_C( 96), UINT8_C(196), UINT8_C(199), UINT8_C(166), UINT8_C(235), UINT8_C(180) },
      { UINT16_C( 1722), UINT16_C(12276), UINT16_C(13536), UINT16_C(11172), UINT16_C(21492), UINT16_C(26228), UINT16_C( 2820), UINT16_C(37260) } },
    { { UINT8_C(100), UINT8_C( 40), UINT8_C( 15), UINT8_C(154), UINT8_C(114), UINT8_C(254), UINT8_C(177), UINT8_C(185) },
      { UINT8_C(226), UINT8_C(177), UINT8_C( 88), UINT8_C(154), UINT8_C(148), UINT8_C(193), UINT8_C(176), UINT8_C( 16) },
      { UINT16_C(22600), UINT16_C( 7080), UINT16_C( 1320), UINT16_C(23716), UINT16_C(16872), UINT16_C(49022), UINT16_C(31152), UINT16_C( 2960) } },
    { { UINT8_C( 69), UINT8_C( 61), UINT8_C( 73), UINT8_C(177), UINT8_C(220), UINT8_C( 86), UINT8_C(129), UINT8_C(234) },
      { UINT8_C(179), UINT8_C(225), UINT8_C(174), UINT8_C(122), UINT8_C(135), UINT8_C(153), UINT8_C( 46), UINT8_C(236) },
      { UINT16_C(12351), UINT16_C(13725), UINT16_C(12702), UINT16_C(21594), UINT16_C(29700), UINT16_C(13158), UINT16_C( 5934), UINT16_C(55224) } },
    { { UINT8_C(194), UINT8_C( 61), UINT8_C(134), UINT8_C( 52), UINT8_C( 60), UINT8_C( 55), UINT8_C(237), UINT8_C( 30) },
      { UINT8_C(232), UINT8_C( 69), UINT8_C(184), UINT8_C(125), UINT8_C(  6), UINT8_C(104), UINT8_C(141), UINT8_C( 76) },
      { UINT16_C(45008), UINT16_C( 4209), UINT16_C(24656), UINT16_C( 6500), UINT16_C(  360), UINT16_C( 5720), UINT16_C(33417), UINT16_C( 2280) } },
    { { UINT8_C(166), UINT8_C(214), UINT8_C(253), UINT8_C(130), UINT8_C( 44), UINT8_C(126), UINT8_C(108), UINT8_C(223) },
      { UINT8_C( 95), UINT8_C( 27), UINT8_C( 89), UINT8_C(231), UINT8_C(180), UINT8_C(136), UINT8_C(211), UINT8_C(118) },
      { UINT16_C(15770), UINT16_C( 5778), UINT16_C(22517), UINT16_C(30030), UINT16_C( 7920), UINT16_C(17136), UINT16_C(22788), UINT16_C(26314) } },
    { { UINT8_C(197), UINT8_C( 89), UINT8_C(171), UINT8_C(  1), UINT8_C(144), UINT8_C(152), UINT8_C( 31), UINT8_C(121) },
      { UINT8_C(222), UINT8_C(215), UINT8_C(246), UINT8_C(228), UINT8_C( 64), UINT8_C(131), UINT8_C( 48), UINT8_C(230) },
      { UINT16_C(43734), UINT16_C(19135), UINT16_C(42066), UINT16_C(  228), UINT16_C( 9216), UINT16_C(19912), UINT16_C( 1488), UINT16_C(27830) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint16x8_t r = simde_vmull_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmull_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(65254), UINT16_C(49526), UINT16_C(58343), UINT16_C(28199) },
      { UINT16_C( 3568), UINT16_C(53134), UINT16_C(38079), UINT16_C(44979) },
      { UINT32_C( 232826272), UINT32_C(2631514484), UINT32_C(2221643097), UINT32_C(1268362821) } },
    { { UINT16_C(41279), UINT16_C(54255), UINT16_C(49218), UINT16_C(49274) },
      { UINT16_C(44771), UINT16_C(52368), UINT16_C(62625), UINT16_C(34586) },
      { UINT32_C(1848102109), UINT32_C(2841225840), UINT32_C(3082277250), UINT32_C(1704190564) } },
    { { UINT16_C(37107), UINT16_C(55881), UINT16_C(28787), UINT16_C(25416) },
      { UINT16_C(54910), UINT16_C(15666), UINT16_C(58986), UINT16_C(43500) },
      { UINT32_C(2037545370), UINT32_C( 875431746), UINT32_C(1698029982), UINT32_C(1105596000) } },
    { { UINT16_C(56455), UINT16_C(51581), UINT16_C(63388), UINT16_C(32649) },
      { UINT16_C( 6821), UINT16_C(17995), UINT16_C(25870), UINT16_C(  462) },
      { UINT32_C( 385079555), UINT32_C( 928200095), UINT32_C(1639847560), UINT32_C(  15083838) } },
    { { UINT16_C( 6133), UINT16_C(27099), UINT16_C( 9351), UINT16_C( 1484) },
      { UINT16_C(65530), UINT16_C(25923), UINT16_C(12261), UINT16_C(27662) },
      { UINT32_C( 401895490), UINT32_C( 702487377), UINT32_C( 114652611), UINT32_C(  41050408) } },
    { { UINT16_C(35595), UINT16_C(43062), UINT16_C(49027), UINT16_C(10279) },
      { UINT16_C(29657), UINT16_C(59503), UINT16_C(15832), UINT16_C(52969) },
      { UINT32_C(1055640915), UINT32_C(2562318186), UINT32_C( 776195464), UINT32_C( 544468351) } },
    { { UINT16_C(50516), UINT16_C(56119), UINT16_C( 1001), UINT16_C(58337) },
      { UINT16_C( 9218), UINT16_C(59208), UINT16_C(22355), UINT16_C(24404) },
      { UINT32_C( 465656488), UINT32_C(3322693752), UINT32_C(  22377355), UINT32_C(1423656148) } },
    { { UINT16_C(35554), UINT16_C(25863), UINT16_C(11849), UINT16_C( 9102) },
      { UINT16_C(64929), UINT16_C(31243), UINT16_C(62522), UINT16_C(36424) },
      { UINT32_C(2308485666), UINT32_C( 808037709), UINT32_C( 740823178), UINT32_C( 331531248) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vmull_u16(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmull_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C(1764671971), UINT32_C( 417693998) },
      { UINT32_C(3142976160), UINT32_C(3551123166) },
      { UINT64_C( 5546321935073211360), UINT64_C( 1483282832596957668) } },
    { { UINT32_C(1771619725), UINT32_C(3853953090) },
      { UINT32_C(4088780350), UINT32_C(1688137088) },
      { UINT64_C( 7243763919252403750), UINT64_C( 6506001146641201920) } },
    { { UINT32_C(3721252015), UINT32_C(4009079374) },
      { UINT32_C(2477411253), UINT32_C(2926007073) },
      { UINT64_C( 9219071617209924795), UINT64_C(11730594604542412302) } },
    { { UINT32_C(1528299288), UINT32_C(3863006887) },
      { UINT32_C( 618263972), UINT32_C(2441639906) },
      { UINT64_C(  944892388203651936), UINT64_C( 9432071772452032622) } },
    { { UINT32_C(2456704580), UINT32_C(3179307784) },
      { UINT32_C(3494980270), UINT32_C(2524887166) },
      { UINT64_C( 8586134036318636600), UINT64_C( 8027393420585500144) } },
    { { UINT32_C(1592891063), UINT32_C( 138686820) },
      { UINT32_C( 153886246), UINT32_C(3650794901) },
      { UINT64_C(  245124025972019498), UINT64_C(  506317135291904820) } },
    { { UINT32_C( 325781771), UINT32_C( 466742380) },
      { UINT32_C(2498437654), UINT32_C(2435541466) },
      { UINT64_C(  813945443653205234), UINT64_C( 1136770420429529080) } },
    { { UINT32_C(1676614911), UINT32_C(1953182798) },
      { UINT32_C(3883767890), UINT32_C(1489049677) },
      { UINT64_C( 6511583155237007790), UINT64_C( 2908386214483856246) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vmull_u32(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_u32)

SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
