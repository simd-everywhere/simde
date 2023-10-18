#define SIMDE_TEST_ARM_NEON_INSN abdl_high

#include "test-neon.h"
#include "../../../simde/arm/neon/abdl_high.h"

static int
test_simde_vabdl_high_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int16_t r[8];
  } test_vec[] = {
    { {  INT8_C(    5),  INT8_C(   25), -INT8_C(   13),  INT8_C(  124),
        -INT8_C(  100),  INT8_C(    4), -INT8_C(  109), -INT8_C(   86),
         INT8_C(    3),  INT8_C(   17),  INT8_C(   57), -INT8_C(    9),
         INT8_C(   75),  INT8_C(   92), -INT8_C(   54), -INT8_C(  126) },
      {  INT8_C(   39), -INT8_C(    9), -INT8_C(   71), -INT8_C(   47),
        -INT8_C(   12), -INT8_C(   17), -INT8_C(   70), -INT8_C(  122),
         INT8_C(  117),  INT8_C(   86),  INT8_C(   28), -INT8_C(   69),
         INT8_C(  124),  INT8_C(   81),  INT8_C(    3),  INT8_C(   94) },
      {  INT16_C(  114),  INT16_C(   69),  INT16_C(   29),  INT16_C(   60),
         INT16_C(   49),  INT16_C(   11),  INT16_C(   57),  INT16_C(  220) } },
    { {  INT8_C(   28), -INT8_C(   68), -INT8_C(   50),  INT8_C(   88),
        -INT8_C(  106),  INT8_C(   12),  INT8_C(   60),  INT8_C(   30),
         INT8_C(  112),  INT8_C(   78),  INT8_C(  120),  INT8_C(   45),
         INT8_C(   94), -INT8_C(   32), -INT8_C(   77), -INT8_C(    8) },
      { -INT8_C(   98),  INT8_C(   81),  INT8_C(   62),  INT8_C(   32),
         INT8_C(  104),  INT8_C(   18), -INT8_C(   52),  INT8_C(   30),
         INT8_C(    9), -INT8_C(    2), -INT8_C(  123), -INT8_C(    4),
         INT8_C(    5),  INT8_C(  104),  INT8_C(   13), -INT8_C(   31) },
      {  INT16_C(  103),  INT16_C(   80),  INT16_C(  243),  INT16_C(   49),
         INT16_C(   89),  INT16_C(  136),  INT16_C(   90),  INT16_C(   23) } },
    { {  INT8_C(  119), -INT8_C(   43), -INT8_C(   14), -INT8_C(    9),
        -INT8_C(   69), -INT8_C(    5), -INT8_C(   69), -INT8_C(   41),
         INT8_C(   38),  INT8_C(   13),  INT8_C(   82),  INT8_C(  106),
        -INT8_C(  118), -INT8_C(   26), -INT8_C(   23), -INT8_C(   23) },
      {  INT8_C(   30),  INT8_C(   91), -INT8_C(  100),  INT8_C(   88),
         INT8_C(   37),  INT8_C(  122),  INT8_C(   96),  INT8_C(   24),
        -INT8_C(   64), -INT8_C(   19), -INT8_C(   33), -INT8_C(   74),
        -INT8_C(   93), -INT8_C(   64),  INT8_C(   75),  INT8_C(   81) },
      {  INT16_C(  102),  INT16_C(   32),  INT16_C(  115),  INT16_C(  180),
         INT16_C(   25),  INT16_C(   38),  INT16_C(   98),  INT16_C(  104) } },
    { {  INT8_C(   35),  INT8_C(  125),  INT8_C(   50), -INT8_C(   42),
        -INT8_C(   90), -INT8_C(   50), -INT8_C(   42),  INT8_C(  124),
         INT8_C(  125),  INT8_C(   79),  INT8_C(  108), -INT8_C(  102),
        -INT8_C(   67),  INT8_C(  111), -INT8_C(  128), -INT8_C(   86) },
      {  INT8_C(   52), -INT8_C(  104), -INT8_C(  112), -INT8_C(  112),
        -INT8_C(   12),  INT8_C(   42),  INT8_C(   69), -INT8_C(   87),
         INT8_C(    6),  INT8_C(   23), -INT8_C(   54), -INT8_C(  112),
         INT8_C(   96), -INT8_C(   59),  INT8_C(   44), -INT8_C(   77) },
      {  INT16_C(  119),  INT16_C(   56),  INT16_C(  162),  INT16_C(   10),
         INT16_C(  163),  INT16_C(  170),  INT16_C(  172),  INT16_C(    9) } },
    { {  INT8_C(   47), -INT8_C(  101),  INT8_C(   77), -INT8_C(   79),
        -INT8_C(   55), -INT8_C(  110), -INT8_C(   59), -INT8_C(   82),
         INT8_C(   18),  INT8_C(  120),  INT8_C(    8), -INT8_C(   20),
         INT8_C(  124), -INT8_C(   31), -INT8_C(   84),  INT8_C(    2) },
      { -INT8_C(  122),  INT8_C(  112),  INT8_C(   74), -INT8_C(   92),
        -INT8_C(   79), -INT8_C(  127), -INT8_C(  117), -INT8_C(   27),
        -INT8_C(  115), -INT8_C(   87), -INT8_C(    1), -INT8_C(   77),
         INT8_C(   63), -INT8_C(   74), -INT8_C(   59),  INT8_C(    1) },
      {  INT16_C(  133),  INT16_C(  207),  INT16_C(    9),  INT16_C(   57),
         INT16_C(   61),  INT16_C(   43),  INT16_C(   25),  INT16_C(    1) } },
    { {  INT8_C(    7), -INT8_C(   84),  INT8_C(   67),  INT8_C(    1),
         INT8_C(   58), -INT8_C(   90), -INT8_C(   26), -INT8_C(   90),
         INT8_C(   14),  INT8_C(   57), -INT8_C(   49),  INT8_C(   93),
         INT8_C(  119),  INT8_C(   27), -INT8_C(   90),  INT8_C(  107) },
      { -INT8_C(   97),  INT8_C(   82),  INT8_C(   84),  INT8_C(   62),
         INT8_C(  126), -INT8_C(   10),  INT8_C(   87),  INT8_C(   70),
        -INT8_C(   23),  INT8_C(    5), -INT8_C(   49), -INT8_C(   28),
        -INT8_C(   37), -INT8_C(   26), -INT8_C(   45),  INT8_C(   75) },
      {  INT16_C(   37),  INT16_C(   52),  INT16_C(    0),  INT16_C(  121),
         INT16_C(  156),  INT16_C(   53),  INT16_C(   45),  INT16_C(   32) } },
    { {  INT8_C(   56), -INT8_C(   12),  INT8_C(   78),  INT8_C(   19),
        -INT8_C(   99),  INT8_C(  116),  INT8_C(   27),  INT8_C(   60),
         INT8_C(    7),  INT8_C(   82),  INT8_C(   82),  INT8_C(   32),
         INT8_C(   65),  INT8_C(   86),  INT8_C(  116), -INT8_C(  105) },
      {  INT8_C(  104), -INT8_C(  124),  INT8_C(   29), -INT8_C(  107),
        -INT8_C(    8),  INT8_C(   24), -INT8_C(  120), -INT8_C(  118),
        -INT8_C(   64),  INT8_C(  120),  INT8_C(   16),  INT8_C(   33),
        -INT8_C(   65), -INT8_C(   26), -INT8_C(   77), -INT8_C(  107) },
      {  INT16_C(   71),  INT16_C(   38),  INT16_C(   66),  INT16_C(    1),
         INT16_C(  130),  INT16_C(  112),  INT16_C(  193),  INT16_C(    2) } },
    { { -INT8_C(   48), -INT8_C(   94), -INT8_C(   19),  INT8_C(   64),
        -INT8_C(   66), -INT8_C(   42), -INT8_C(   85), -INT8_C(   75),
         INT8_C(   63),  INT8_C(   76), -INT8_C(  116),  INT8_C(   86),
         INT8_C(   48), -INT8_C(   38), -INT8_C(   11), -INT8_C(   63) },
      {  INT8_C(   36), -INT8_C(   15),  INT8_C(   10),  INT8_C(  125),
         INT8_C(   25),  INT8_C(    7), -INT8_C(  113),  INT8_C(   18),
        -INT8_C(   78),  INT8_C(   19),  INT8_C(   10), -INT8_C(   39),
         INT8_C(   33), -INT8_C(  116), -INT8_C(   88), -INT8_C(  117) },
      {  INT16_C(  141),  INT16_C(   57),  INT16_C(  126),  INT16_C(  125),
         INT16_C(   15),  INT16_C(   78),  INT16_C(   77),  INT16_C(   54) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int16x8_t r = simde_vabdl_high_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int16x8_t r = simde_vabdl_high_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdl_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int32_t r[4];
  } test_vec[] = {
    { {  INT16_C(  29690), -INT16_C(  24168), -INT16_C(  27667),  INT16_C(   8070),
        -INT16_C(  21906),  INT16_C(   4540),  INT16_C(  29724),  INT16_C(  24943) },
      { -INT16_C(   1819),  INT16_C(   9889), -INT16_C(  26106),  INT16_C(   5615),
         INT16_C(  19638),  INT16_C(  27513),  INT16_C(   2962),  INT16_C(  21043) },
      {  INT32_C(  41544),  INT32_C(  22973),  INT32_C(  26762),  INT32_C(   3900) } },
    { {  INT16_C(  28652),  INT16_C(  18761),  INT16_C(   4451),  INT16_C(  10847),
        -INT16_C(   5071),  INT16_C(   3419), -INT16_C(  32086),  INT16_C(  21511) },
      { -INT16_C(  19278), -INT16_C(    305), -INT16_C(  22484),  INT16_C(   2209),
         INT16_C(   6312), -INT16_C(  26943),  INT16_C(   3625),  INT16_C(   2183) },
      {  INT32_C(  11383),  INT32_C(  30362),  INT32_C(  35711),  INT32_C(  19328) } },
    { {  INT16_C(  22486),  INT16_C(  29554), -INT16_C(  10737),  INT16_C(   3632),
         INT16_C(   2333),  INT16_C(  14499), -INT16_C(  22389), -INT16_C(  22353) },
      { -INT16_C(   8960), -INT16_C(  30270),  INT16_C(  19487),  INT16_C(  17272),
        -INT16_C(  12445), -INT16_C(  20518), -INT16_C(  28048),  INT16_C(  26583) },
      {  INT32_C(  14778),  INT32_C(  35017),  INT32_C(   5659),  INT32_C(  48936) } },
    { {  INT16_C(  14410),  INT16_C(   5324), -INT16_C(  23116), -INT16_C(  25881),
         INT16_C(   5142),  INT16_C(   5975), -INT16_C(  22642), -INT16_C(   9474) },
      {  INT16_C(  30417), -INT16_C(  24641), -INT16_C(  29549), -INT16_C(  17979),
         INT16_C(  29468),  INT16_C(  15706),  INT16_C(  29466), -INT16_C(   2986) },
      {  INT32_C(  24326),  INT32_C(   9731),  INT32_C(  52108),  INT32_C(   6488) } },
    { { -INT16_C(  17906),  INT16_C(  24882), -INT16_C(  18998), -INT16_C(  31125),
         INT16_C(  19250),  INT16_C(   6092),  INT16_C(   7400), -INT16_C(  20958) },
      {  INT16_C(   8828),  INT16_C(  31854), -INT16_C(  26593),  INT16_C(  29376),
         INT16_C(  13278), -INT16_C(  30888), -INT16_C(  10545), -INT16_C(  20911) },
      {  INT32_C(   5972),  INT32_C(  36980),  INT32_C(  17945),  INT32_C(     47) } },
    { { -INT16_C(  12386),  INT16_C(  10034),  INT16_C(  16722), -INT16_C(  30032),
         INT16_C(  32463), -INT16_C(  32041), -INT16_C(  25016), -INT16_C(   9365) },
      {  INT16_C(  11965), -INT16_C(  25381),  INT16_C(   9794),  INT16_C(   3483),
        -INT16_C(  18921),  INT16_C(  25033),  INT16_C(  15507),  INT16_C(  31746) },
      {  INT32_C(  51384),  INT32_C(  57074),  INT32_C(  40523),  INT32_C(  41111) } },
    { { -INT16_C(  32282),  INT16_C(  14736),  INT16_C(   6831), -INT16_C(  31451),
        -INT16_C(  32288),  INT16_C(   4220),  INT16_C(   3340),  INT16_C(  18843) },
      { -INT16_C(  25272),  INT16_C(    401), -INT16_C(  29291),  INT16_C(   1110),
        -INT16_C(  19746),  INT16_C(  27566), -INT16_C(  25524), -INT16_C(  20491) },
      {  INT32_C(  12542),  INT32_C(  23346),  INT32_C(  28864),  INT32_C(  39334) } },
    { { -INT16_C(  16675),  INT16_C(  13257),  INT16_C(  19538),  INT16_C(  11877),
        -INT16_C(  31293),  INT16_C(  15882), -INT16_C(  15409), -INT16_C(   7949) },
      { -INT16_C(  22845), -INT16_C(   6299), -INT16_C(  10856), -INT16_C(  31293),
        -INT16_C(  20761),  INT16_C(  17929), -INT16_C(   3424), -INT16_C(  27554) },
      {  INT32_C(  10532),  INT32_C(   2047),  INT32_C(  11985),  INT32_C(  19605) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vabdl_high_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int32x4_t r = simde_vabdl_high_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdl_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int64_t r[2];
  } test_vec[] = {
    { { -INT32_C(   787468699),  INT32_C(  1695271439), -INT32_C(   351095935), -INT32_C(  1545598394) },
      { -INT32_C(  1783679309), -INT32_C(   970531182),  INT32_C(   175616594),  INT32_C(  1309057832) },
      {  INT64_C(   526712529),  INT64_C(  2854656226) } },
    { {  INT32_C(  1080367040),  INT32_C(  1130061194), -INT32_C(   960325369), -INT32_C(   460539914) },
      { -INT32_C(  1121247508), -INT32_C(  1971610234),  INT32_C(  1201086722), -INT32_C(   864366830) },
      {  INT64_C(  2161412091),  INT64_C(   403826916) } },
    { { -INT32_C(  1575160001),  INT32_C(   282864985),  INT32_C(  1075615256), -INT32_C(   432396887) },
      {  INT32_C(  2109360031), -INT32_C(  1753323785),  INT32_C(  1229001961),  INT32_C(   202062281) },
      {  INT64_C(   153386705),  INT64_C(   634459168) } },
    { {  INT32_C(    68291402), -INT32_C(  1313041192),  INT32_C(   329338864),  INT32_C(   297630675) },
      {  INT32_C(   542845242), -INT32_C(  1361117108),  INT32_C(   171758027),  INT32_C(  1488836943) },
      {  INT64_C(   157580837),  INT64_C(  1191206268) } },
    { {  INT32_C(  1239184031),  INT32_C(   276088380),  INT32_C(   366348024), -INT32_C(   977026686) },
      { -INT32_C(  1788467255), -INT32_C(  1337699041),  INT32_C(  1941530698),  INT32_C(  1724505255) },
      {  INT64_C(  1575182674),  INT64_C(  2701531941) } },
    { { -INT32_C(   394449041), -INT32_C(  1496706648),  INT32_C(   461438308), -INT32_C(   462426104) },
      {  INT32_C(   316700335),  INT32_C(  2112040702), -INT32_C(   812534998),  INT32_C(   363376033) },
      {  INT64_C(  1273973306),  INT64_C(   825802137) } },
    { {  INT32_C(  1732933553), -INT32_C(   496211310),  INT32_C(   689320739), -INT32_C(  1431777230) },
      {  INT32_C(    34189302), -INT32_C(   778655550),  INT32_C(  1839840728),  INT32_C(  1359603307) },
      {  INT64_C(  1150519989),  INT64_C(  2791380537) } },
    { {  INT32_C(   543026096), -INT32_C(  2143144503),  INT32_C(   962996740), -INT32_C(   359161913) },
      {  INT32_C(  1590535608), -INT32_C(  2105115010),  INT32_C(  1494859055),  INT32_C(   292780821) },
      {  INT64_C(   531862315),  INT64_C(   651942734) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vabdl_high_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int64x2_t r = simde_vabdl_high_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdl_high_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint16_t r[8];
  } test_vec[] = {
    { {  UINT8_C(  227),  UINT8_C(  184),  UINT8_C(   17),  UINT8_C(   37),
         UINT8_C(   21),  UINT8_C(  160),  UINT8_C(  222),  UINT8_C(  160),
         UINT8_C(   79),  UINT8_C(  122),  UINT8_C(   82),  UINT8_C(  237),
         UINT8_C(   70),  UINT8_C(   55),  UINT8_C(  190),  UINT8_C(  188) },
      {  UINT8_C(   17),  UINT8_C(  235),  UINT8_C(   28),  UINT8_C(  202),
         UINT8_C(   74),  UINT8_C(  105),  UINT8_C(  129),  UINT8_C(   67),
         UINT8_C(   70),  UINT8_C(  191),  UINT8_C(   51),  UINT8_C(   88),
         UINT8_C(  234),  UINT8_C(  164),  UINT8_C(  168),  UINT8_C(   83) },
      {  UINT16_C(    9),  UINT16_C(   69),  UINT16_C(   31),  UINT16_C(  149),
         UINT16_C(  164),  UINT16_C(  109),  UINT16_C(   22),  UINT16_C(  105) } },
    { {  UINT8_C(  138),  UINT8_C(  229),  UINT8_C(  107),  UINT8_C(  243),
         UINT8_C(    0),  UINT8_C(  181),  UINT8_C(  227),  UINT8_C(   95),
         UINT8_C(    5),  UINT8_C(  124),  UINT8_C(   79),  UINT8_C(  131),
         UINT8_C(   38),  UINT8_C(  197),  UINT8_C(  101),  UINT8_C(  192) },
      {  UINT8_C(  176),  UINT8_C(  255),  UINT8_C(   71),  UINT8_C(   90),
         UINT8_C(  167),  UINT8_C(   36),  UINT8_C(  133),  UINT8_C(   99),
         UINT8_C(   56),  UINT8_C(  250),  UINT8_C(  193),  UINT8_C(    5),
         UINT8_C(   19),  UINT8_C(  123),  UINT8_C(  185),  UINT8_C(  128) },
      {  UINT16_C(   51),  UINT16_C(  126),  UINT16_C(  114),  UINT16_C(  126),
         UINT16_C(   19),  UINT16_C(   74),  UINT16_C(   84),  UINT16_C(   64) } },
    { {  UINT8_C(   55),  UINT8_C(  102),  UINT8_C(  236),  UINT8_C(    4),
         UINT8_C(  119),  UINT8_C(   65),  UINT8_C(   67),  UINT8_C(   67),
         UINT8_C(  225),  UINT8_C(   99),  UINT8_C(    7),  UINT8_C(   10),
         UINT8_C(   96),  UINT8_C(  114),  UINT8_C(  244),  UINT8_C(  218) },
      {  UINT8_C(   30),  UINT8_C(  137),  UINT8_C(  111),  UINT8_C(  227),
         UINT8_C(  232),  UINT8_C(  120),  UINT8_C(  229),  UINT8_C(  115),
         UINT8_C(  155),  UINT8_C(   50),  UINT8_C(  250),  UINT8_C(   70),
         UINT8_C(  200),  UINT8_C(   95),  UINT8_C(  184),  UINT8_C(  254) },
      {  UINT16_C(   70),  UINT16_C(   49),  UINT16_C(  243),  UINT16_C(   60),
         UINT16_C(  104),  UINT16_C(   19),  UINT16_C(   60),  UINT16_C(   36) } },
    { {  UINT8_C(  213),  UINT8_C(  223),  UINT8_C(  163),  UINT8_C(  143),
         UINT8_C(  214),  UINT8_C(  173),  UINT8_C(   75),  UINT8_C(   16),
         UINT8_C(  174),  UINT8_C(  196),  UINT8_C(  192),  UINT8_C(  153),
         UINT8_C(  123),  UINT8_C(   10),  UINT8_C(  161),  UINT8_C(  250) },
      {  UINT8_C(  255),  UINT8_C(   49),  UINT8_C(  201),  UINT8_C(  125),
         UINT8_C(  165),  UINT8_C(  241),  UINT8_C(  100),  UINT8_C(  249),
         UINT8_C(  133),  UINT8_C(   74),  UINT8_C(   34),  UINT8_C(  109),
         UINT8_C(  226),  UINT8_C(   60),  UINT8_C(  157),  UINT8_C(  118) },
      {  UINT16_C(   41),  UINT16_C(  122),  UINT16_C(  158),  UINT16_C(   44),
         UINT16_C(  103),  UINT16_C(   50),  UINT16_C(    4),  UINT16_C(  132) } },
    { {  UINT8_C(  100),  UINT8_C(   76),  UINT8_C(  199),  UINT8_C(  194),
         UINT8_C(  148),  UINT8_C(    6),  UINT8_C(  174),  UINT8_C(  180),
         UINT8_C(  217),  UINT8_C(  107),  UINT8_C(  111),  UINT8_C(  196),
         UINT8_C(  166),  UINT8_C(  234),  UINT8_C(  207),  UINT8_C(   98) },
      {  UINT8_C(  171),  UINT8_C(  231),  UINT8_C(  153),  UINT8_C(  116),
         UINT8_C(  140),  UINT8_C(  194),  UINT8_C(  233),  UINT8_C(  242),
         UINT8_C(   79),  UINT8_C(   37),  UINT8_C(   70),  UINT8_C(   26),
         UINT8_C(  105),  UINT8_C(   40),  UINT8_C(  135),  UINT8_C(  131) },
      {  UINT16_C(  138),  UINT16_C(   70),  UINT16_C(   41),  UINT16_C(  170),
         UINT16_C(   61),  UINT16_C(  194),  UINT16_C(   72),  UINT16_C(   33) } },
    { {  UINT8_C(   87),  UINT8_C(   46),  UINT8_C(   59),  UINT8_C(  163),
         UINT8_C(    6),  UINT8_C(  216),  UINT8_C(  223),  UINT8_C(  146),
         UINT8_C(  208),  UINT8_C(   83),  UINT8_C(   84),  UINT8_C(  233),
         UINT8_C(  193),  UINT8_C(   19),  UINT8_C(  196),  UINT8_C(    3) },
      {  UINT8_C(   18),  UINT8_C(   57),  UINT8_C(   85),  UINT8_C(   23),
         UINT8_C(  176),  UINT8_C(  178),  UINT8_C(   31),  UINT8_C(   46),
         UINT8_C(  189),  UINT8_C(  148),  UINT8_C(  249),  UINT8_C(  205),
         UINT8_C(   86),  UINT8_C(  240),  UINT8_C(  175),  UINT8_C(  171) },
      {  UINT16_C(   19),  UINT16_C(   65),  UINT16_C(  165),  UINT16_C(   28),
         UINT16_C(  107),  UINT16_C(  221),  UINT16_C(   21),  UINT16_C(  168) } },
    { {  UINT8_C(   34),  UINT8_C(  208),  UINT8_C(  154),  UINT8_C(  166),
         UINT8_C(   95),  UINT8_C(  255),  UINT8_C(  138),  UINT8_C(  144),
         UINT8_C(  185),  UINT8_C(  107),  UINT8_C(   94),  UINT8_C(  107),
         UINT8_C(    1),  UINT8_C(  117),  UINT8_C(    3),  UINT8_C(  144) },
      {  UINT8_C(   88),  UINT8_C(  134),  UINT8_C(   39),  UINT8_C(   53),
         UINT8_C(   61),  UINT8_C(   79),  UINT8_C(  253),  UINT8_C(  177),
         UINT8_C(  253),  UINT8_C(   17),  UINT8_C(    1),  UINT8_C(  101),
         UINT8_C(  210),  UINT8_C(  128),  UINT8_C(  255),  UINT8_C(   45) },
      {  UINT16_C(   68),  UINT16_C(   90),  UINT16_C(   93),  UINT16_C(    6),
         UINT16_C(  209),  UINT16_C(   11),  UINT16_C(  252),  UINT16_C(   99) } },
    { {  UINT8_C(  126),  UINT8_C(  225),  UINT8_C(  243),  UINT8_C(  203),
         UINT8_C(  180),  UINT8_C(  184),  UINT8_C(  187),  UINT8_C(   61),
         UINT8_C(  246),  UINT8_C(  189),  UINT8_C(  128),  UINT8_C(  135),
         UINT8_C(  167),  UINT8_C(   92),  UINT8_C(   40),  UINT8_C(  168) },
      {  UINT8_C(   25),  UINT8_C(  142),  UINT8_C(  132),  UINT8_C(   14),
         UINT8_C(   29),  UINT8_C(  204),  UINT8_C(   58),  UINT8_C(  229),
         UINT8_C(   65),  UINT8_C(  238),  UINT8_C(  210),  UINT8_C(   45),
         UINT8_C(  191),  UINT8_C(   63),  UINT8_C(  220),  UINT8_C(  200) },
      {  UINT16_C(  181),  UINT16_C(   49),  UINT16_C(   82),  UINT16_C(   90),
         UINT16_C(   24),  UINT16_C(   29),  UINT16_C(  180),  UINT16_C(   32) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint16x8_t r = simde_vabdl_high_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint16x8_t r = simde_vabdl_high_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdl_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT16_C(  11080),  UINT16_C(  28941),  UINT16_C(  54244),  UINT16_C(   2424),
         UINT16_C(   6185),  UINT16_C(  35176),  UINT16_C(   9035),  UINT16_C(   6428) },
      {  UINT16_C(  65511),  UINT16_C(  46505),  UINT16_C(  37008),  UINT16_C(   6083),
         UINT16_C(  57861),  UINT16_C(   8256),  UINT16_C(  49759),  UINT16_C(  43953) },
      {  UINT32_C(  51676),  UINT32_C(  26920),  UINT32_C(  40724),  UINT32_C(  37525) } },
    { {  UINT16_C(    610),  UINT16_C(  19991),  UINT16_C(  48540),  UINT16_C(  23933),
         UINT16_C(  17176),  UINT16_C(  27734),  UINT16_C(   2781),  UINT16_C(   9794) },
      {  UINT16_C(  14579),  UINT16_C(  50810),  UINT16_C(  25818),  UINT16_C(  54221),
         UINT16_C(  13934),  UINT16_C(  50029),  UINT16_C(  28040),  UINT16_C(  54984) },
      {  UINT32_C(   3242),  UINT32_C(  22295),  UINT32_C(  25259),  UINT32_C(  45190) } },
    { {  UINT16_C(  20635),  UINT16_C(  15524),  UINT16_C(  56681),  UINT16_C(  34063),
         UINT16_C(  12313),  UINT16_C(  34359),  UINT16_C(  22139),  UINT16_C(  62709) },
      {  UINT16_C(  48540),  UINT16_C(  49524),  UINT16_C(  26037),  UINT16_C(  33636),
         UINT16_C(   2174),  UINT16_C(  30778),  UINT16_C(  32366),  UINT16_C(  36639) },
      {  UINT32_C(  10139),  UINT32_C(   3581),  UINT32_C(  10227),  UINT32_C(  26070) } },
    { {  UINT16_C(   7906),  UINT16_C(  59201),  UINT16_C(  11503),  UINT16_C(  30882),
         UINT16_C(  36534),  UINT16_C(  53191),  UINT16_C(   2796),  UINT16_C(  42790) },
      {  UINT16_C(  17653),  UINT16_C(  53464),  UINT16_C(   5406),  UINT16_C(  42682),
         UINT16_C(  61443),  UINT16_C(  36702),  UINT16_C(  62252),  UINT16_C(  33301) },
      {  UINT32_C(  24909),  UINT32_C(  16489),  UINT32_C(  59456),  UINT32_C(   9489) } },
    { {  UINT16_C(    368),  UINT16_C(  28659),  UINT16_C(  17363),  UINT16_C(  52426),
         UINT16_C(  18831),  UINT16_C(  31144),  UINT16_C(  26653),  UINT16_C(   4962) },
      {  UINT16_C(  13272),  UINT16_C(  56638),  UINT16_C(  26816),  UINT16_C(   9319),
         UINT16_C(  33450),  UINT16_C(  46002),  UINT16_C(  46512),  UINT16_C(  11194) },
      {  UINT32_C(  14619),  UINT32_C(  14858),  UINT32_C(  19859),  UINT32_C(   6232) } },
    { {  UINT16_C(  24373),  UINT16_C(   3749),  UINT16_C(  30479),  UINT16_C(  53729),
         UINT16_C(  36062),  UINT16_C(   2091),  UINT16_C(  20756),  UINT16_C(  37273) },
      {  UINT16_C(  14682),  UINT16_C(  15683),  UINT16_C(  59327),  UINT16_C(  55116),
         UINT16_C(  48897),  UINT16_C(  34602),  UINT16_C(  26495),  UINT16_C(  13053) },
      {  UINT32_C(  12835),  UINT32_C(  32511),  UINT32_C(   5739),  UINT32_C(  24220) } },
    { {  UINT16_C(  61763),  UINT16_C(  15289),  UINT16_C(  14482),  UINT16_C(  35178),
         UINT16_C(  28312),  UINT16_C(  40394),  UINT16_C(  54355),  UINT16_C(   8397) },
      {  UINT16_C(  31322),  UINT16_C(  46229),  UINT16_C(  21846),  UINT16_C(   5486),
         UINT16_C(    783),  UINT16_C(  16002),  UINT16_C(  57330),  UINT16_C(  30354) },
      {  UINT32_C(  27529),  UINT32_C(  24392),  UINT32_C(   2975),  UINT32_C(  21957) } },
    { {  UINT16_C(  61340),  UINT16_C(  10896),  UINT16_C(  25008),  UINT16_C(  62657),
         UINT16_C(   6688),  UINT16_C(  40315),  UINT16_C(  60584),  UINT16_C(   9942) },
      {  UINT16_C(  49306),  UINT16_C(  62288),  UINT16_C(   5856),  UINT16_C(  51005),
         UINT16_C(  57343),  UINT16_C(  24018),  UINT16_C(  20003),  UINT16_C(  26261) },
      {  UINT32_C(  50655),  UINT32_C(  16297),  UINT32_C(  40581),  UINT32_C(  16319) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vabdl_high_u16(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint32x4_t r = simde_vabdl_high_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabdl_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint64_t r[2];
  } test_vec[] = {
    { {  UINT32_C(  4207167503),  UINT32_C(  4182969940),  UINT32_C(  4265939436),  UINT32_C(  3572856407) },
      {  UINT32_C(  1122616623),  UINT32_C(  1433619022),  UINT32_C(  3926591544),  UINT32_C(   238681857) },
      {  UINT64_C(   339347892),  UINT64_C(  3334174550) } },
    { {  UINT32_C(  3618013472),  UINT32_C(  2859644811),  UINT32_C(  3674865098),  UINT32_C(  2171453939) },
      {  UINT32_C(  3082235870),  UINT32_C(  3143735662),  UINT32_C(  1101178394),  UINT32_C(  1015750680) },
      {  UINT64_C(  2573686704),  UINT64_C(  1155703259) } },
    { {  UINT32_C(  2881588591),  UINT32_C(  1972897176),  UINT32_C(  1922891383),  UINT32_C(  4044065985) },
      {  UINT32_C(    27808731),  UINT32_C(  3506496718),  UINT32_C(   354305683),  UINT32_C(  1811920773) },
      {  UINT64_C(  1568585700),  UINT64_C(  2232145212) } },
    { {  UINT32_C(   796289424),  UINT32_C(  3657819838),  UINT32_C(   882914741),  UINT32_C(   590761261) },
      {  UINT32_C(   916488915),  UINT32_C(  3250147444),  UINT32_C(  4194695410),  UINT32_C(  2666509233) },
      {  UINT64_C(  3311780669),  UINT64_C(  2075747972) } },
    { {  UINT32_C(  1593704277),  UINT32_C(   353382449),  UINT32_C(   300269132),  UINT32_C(   466013123) },
      {  UINT32_C(  3161726502),  UINT32_C(  2871668464),  UINT32_C(  3932181037),  UINT32_C(   593185941) },
      {  UINT64_C(  3631911905),  UINT64_C(   127172818) } },
    { {  UINT32_C(  1353149015),  UINT32_C(  2743917811),  UINT32_C(  1661571991),  UINT32_C(  2186200682) },
      {  UINT32_C(   705050360),  UINT32_C(  1373863029),  UINT32_C(  3778121108),  UINT32_C(  4074917396) },
      {  UINT64_C(  2116549117),  UINT64_C(  1888716714) } },
    { {  UINT32_C(  3636552503),  UINT32_C(  2704297856),  UINT32_C(  2100074352),  UINT32_C(  3166585636) },
      {  UINT32_C(  1117640888),  UINT32_C(  3540546728),  UINT32_C(  3237396642),  UINT32_C(   564732391) },
      {  UINT64_C(  1137322290),  UINT64_C(  2601853245) } },
    { {  UINT32_C(  4050420069),  UINT32_C(   159811253),  UINT32_C(  3375491289),  UINT32_C(  3543754642) },
      {  UINT32_C(   719089014),  UINT32_C(  2621554727),  UINT32_C(  2869382109),  UINT32_C(   269948350) },
      {  UINT64_C(   506109180),  UINT64_C(  3273806292) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vabdl_high_u32(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint64x2_t r = simde_vabdl_high_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vabdl_high_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdl_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdl_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdl_high_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdl_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vabdl_high_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
