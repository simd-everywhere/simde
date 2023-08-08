#define SIMDE_TEST_ARM_NEON_INSN rshrn_high_n

#include "test-neon.h"
#include "../../../simde/arm/neon/rshrn_high_n.h"

static int
test_simde_vrshrn_high_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[8];
    int8_t r[8];
    int8_t r1[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r6[16];
    int8_t r8[16];
  } test_vec[] = {
    { {  -INT16_C(22001), -INT16_C(26905), -INT16_C( 9851),  INT16_C(17234),
         -INT16_C(24080),  INT16_C(18965),  INT16_C(27794),  INT16_C( 7768) },
      {  -INT8_C(   89),  INT8_C(   77),  INT8_C(   28),  INT8_C(   28),
          INT8_C(  123),  INT8_C(   20), -INT8_C(  111), -INT8_C(   85) },
      {  -INT8_C(   89),  INT8_C(   77),  INT8_C(   28),  INT8_C(   28),  INT8_C(  123),  INT8_C(   20), -INT8_C(  111), -INT8_C(   85),
          INT8_C(    8),  INT8_C(  116), -INT8_C(   61), -INT8_C(   87), -INT8_C(    8),  INT8_C(   11),  INT8_C(   73),  INT8_C(   44) },
      {  -INT8_C(   89),  INT8_C(   77),  INT8_C(   28),  INT8_C(   28),  INT8_C(  123),  INT8_C(   20), -INT8_C(  111), -INT8_C(   85),
          INT8_C(   66), -INT8_C(   35),  INT8_C(   49),  INT8_C(  106),  INT8_C(   62),  INT8_C(   67), -INT8_C(  110), -INT8_C(   53) },
      {  -INT8_C(   89),  INT8_C(   77),  INT8_C(   28),  INT8_C(   28),  INT8_C(  123),  INT8_C(   20), -INT8_C(  111), -INT8_C(   85),
          INT8_C(   80), -INT8_C(   73), -INT8_C(   52),  INT8_C(   27),  INT8_C(   16),  INT8_C(   81),  INT8_C(  101), -INT8_C(   13) },
      {  -INT8_C(   89),  INT8_C(   77),  INT8_C(   28),  INT8_C(   28),  INT8_C(  123),  INT8_C(   20), -INT8_C(  111), -INT8_C(   85),
         -INT8_C(   88),  INT8_C(   92),  INT8_C(  102),  INT8_C(   13), -INT8_C(  120),  INT8_C(   40), -INT8_C(   78),  INT8_C(  121) },
      {  -INT8_C(   89),  INT8_C(   77),  INT8_C(   28),  INT8_C(   28),  INT8_C(  123),  INT8_C(   20), -INT8_C(  111), -INT8_C(   85),
         -INT8_C(   86), -INT8_C(  105), -INT8_C(   38),  INT8_C(   67), -INT8_C(   94),  INT8_C(   74),  INT8_C(  109),  INT8_C(   30) } },
    { {   INT16_C(28383),  INT16_C( 4710),  INT16_C(12658),  INT16_C(17402),
          INT16_C(32513),  INT16_C( 6690), -INT16_C( 3459), -INT16_C(14763) },
      {   INT8_C(   11),  INT8_C(   29),  INT8_C(   25), -INT8_C(   61),
         -INT8_C(  106),  INT8_C(  124),  INT8_C(  119),  INT8_C(  108) },
      {   INT8_C(   11),  INT8_C(   29),  INT8_C(   25), -INT8_C(   61), -INT8_C(  106),  INT8_C(  124),  INT8_C(  119),  INT8_C(  108),
          INT8_C(  112),  INT8_C(   51), -INT8_C(   71), -INT8_C(    3), -INT8_C(  127),  INT8_C(   17),  INT8_C(   63),  INT8_C(   43) },
      {   INT8_C(   11),  INT8_C(   29),  INT8_C(   25), -INT8_C(   61), -INT8_C(  106),  INT8_C(  124),  INT8_C(  119),  INT8_C(  108),
         -INT8_C(   36),  INT8_C(   77),  INT8_C(   46),  INT8_C(  127), -INT8_C(   32),  INT8_C(   68),  INT8_C(   80), -INT8_C(   53) },
      {   INT8_C(   11),  INT8_C(   29),  INT8_C(   25), -INT8_C(   61), -INT8_C(  106),  INT8_C(  124),  INT8_C(  119),  INT8_C(  108),
          INT8_C(  119), -INT8_C(  109), -INT8_C(  116),  INT8_C(   32), -INT8_C(    8), -INT8_C(   47), -INT8_C(  108),  INT8_C(   51) },
      {   INT8_C(   11),  INT8_C(   29),  INT8_C(   25), -INT8_C(   61), -INT8_C(  106),  INT8_C(  124),  INT8_C(  119),  INT8_C(  108),
         -INT8_C(   69),  INT8_C(   74), -INT8_C(   58),  INT8_C(   16), -INT8_C(    4),  INT8_C(  105), -INT8_C(   54),  INT8_C(   25) },
      {   INT8_C(   11),  INT8_C(   29),  INT8_C(   25), -INT8_C(   61), -INT8_C(  106),  INT8_C(  124),  INT8_C(  119),  INT8_C(  108),
          INT8_C(  111),  INT8_C(   18),  INT8_C(   49),  INT8_C(   68),  INT8_C(  127),  INT8_C(   26), -INT8_C(   14), -INT8_C(   58) } },
    { {  -INT16_C(15297), -INT16_C(14816), -INT16_C(20211), -INT16_C( 4011),
          INT16_C( 8230), -INT16_C(24842),  INT16_C(24790), -INT16_C(23256) },
      {  -INT8_C(  115),  INT8_C(   82), -INT8_C(  121), -INT8_C(   15),
         -INT8_C(   58), -INT8_C(   37), -INT8_C(   46), -INT8_C(  103) },
      {  -INT8_C(  115),  INT8_C(   82), -INT8_C(  121), -INT8_C(   15), -INT8_C(   58), -INT8_C(   37), -INT8_C(   46), -INT8_C(  103),
          INT8_C(   32),  INT8_C(   16), -INT8_C(  121),  INT8_C(   43),  INT8_C(   19),  INT8_C(  123),  INT8_C(  107), -INT8_C(  108) },
      {  -INT8_C(  115),  INT8_C(   82), -INT8_C(  121), -INT8_C(   15), -INT8_C(   58), -INT8_C(   37), -INT8_C(   46), -INT8_C(  103),
         -INT8_C(  120), -INT8_C(   60),  INT8_C(   34),  INT8_C(   11),  INT8_C(    5), -INT8_C(   33),  INT8_C(   27), -INT8_C(   91) },
      {  -INT8_C(  115),  INT8_C(   82), -INT8_C(  121), -INT8_C(   15), -INT8_C(   58), -INT8_C(   37), -INT8_C(   46), -INT8_C(  103),
          INT8_C(   34),  INT8_C(   49), -INT8_C(  120), -INT8_C(  125),  INT8_C(    1), -INT8_C(    8),  INT8_C(    7),  INT8_C(   41) },
      {  -INT8_C(  115),  INT8_C(   82), -INT8_C(  121), -INT8_C(   15), -INT8_C(   58), -INT8_C(   37), -INT8_C(   46), -INT8_C(  103),
          INT8_C(   17),  INT8_C(   25), -INT8_C(   60), -INT8_C(   63), -INT8_C(  127),  INT8_C(  124), -INT8_C(  125), -INT8_C(  107) },
      {  -INT8_C(  115),  INT8_C(   82), -INT8_C(  121), -INT8_C(   15), -INT8_C(   58), -INT8_C(   37), -INT8_C(   46), -INT8_C(  103),
         -INT8_C(   60), -INT8_C(   58), -INT8_C(   79), -INT8_C(   16),  INT8_C(   32), -INT8_C(   97),  INT8_C(   97), -INT8_C(   91) } },
    { {   INT16_C(20309), -INT16_C( 4385), -INT16_C( 4332), -INT16_C(16724),
         -INT16_C( 7501), -INT16_C(18956), -INT16_C( 1383), -INT16_C(17787) },
      {  -INT8_C(   73), -INT8_C(   40), -INT8_C(  124), -INT8_C(   84),
         -INT8_C(  105),  INT8_C(   63), -INT8_C(   52),  INT8_C(  115) },
      {  -INT8_C(   73), -INT8_C(   40), -INT8_C(  124), -INT8_C(   84), -INT8_C(  105),  INT8_C(   63), -INT8_C(   52),  INT8_C(  115),
         -INT8_C(   85),  INT8_C(  112), -INT8_C(  118),  INT8_C(   86),  INT8_C(   90), -INT8_C(    6),  INT8_C(   77),  INT8_C(   67) },
      {  -INT8_C(   73), -INT8_C(   40), -INT8_C(  124), -INT8_C(   84), -INT8_C(  105),  INT8_C(   63), -INT8_C(   52),  INT8_C(  115),
         -INT8_C(   21), -INT8_C(   36), -INT8_C(   29), -INT8_C(   42),  INT8_C(   86), -INT8_C(   65),  INT8_C(   83),  INT8_C(   81) },
      {  -INT8_C(   73), -INT8_C(   40), -INT8_C(  124), -INT8_C(   84), -INT8_C(  105),  INT8_C(   63), -INT8_C(   52),  INT8_C(  115),
          INT8_C(  123),  INT8_C(  119),  INT8_C(  121), -INT8_C(   11),  INT8_C(   22), -INT8_C(   80), -INT8_C(   43), -INT8_C(   44) },
      {  -INT8_C(   73), -INT8_C(   40), -INT8_C(  124), -INT8_C(   84), -INT8_C(  105),  INT8_C(   63), -INT8_C(   52),  INT8_C(  115),
          INT8_C(   61), -INT8_C(   69), -INT8_C(   68), -INT8_C(    5), -INT8_C(  117), -INT8_C(   40), -INT8_C(   22), -INT8_C(   22) },
      {  -INT8_C(   73), -INT8_C(   40), -INT8_C(  124), -INT8_C(   84), -INT8_C(  105),  INT8_C(   63), -INT8_C(   52),  INT8_C(  115),
          INT8_C(   79), -INT8_C(   17), -INT8_C(   17), -INT8_C(   65), -INT8_C(   29), -INT8_C(   74), -INT8_C(    5), -INT8_C(   69) } },
    { {   INT16_C( 2688),  INT16_C(27188),  INT16_C( 9401), -INT16_C( 4812),
          INT16_C( 2024), -INT16_C(29524),  INT16_C( 9138), -INT16_C( 1721) },
      {  -INT8_C(   22),  INT8_C(  112),  INT8_C(   26),  INT8_C(    3),
         -INT8_C(   62),  INT8_C(  100),  INT8_C(   65), -INT8_C(  112) },
      {  -INT8_C(   22),  INT8_C(  112),  INT8_C(   26),  INT8_C(    3), -INT8_C(   62),  INT8_C(  100),  INT8_C(   65), -INT8_C(  112),
          INT8_C(   64),  INT8_C(   26),  INT8_C(   93), -INT8_C(  102), -INT8_C(   12),  INT8_C(   86), -INT8_C(   39), -INT8_C(   92) },
      {  -INT8_C(   22),  INT8_C(  112),  INT8_C(   26),  INT8_C(    3), -INT8_C(   62),  INT8_C(  100),  INT8_C(   65), -INT8_C(  112),
          INT8_C(   80),  INT8_C(   71), -INT8_C(  105), -INT8_C(   89), -INT8_C(    3), -INT8_C(  106),  INT8_C(  118),  INT8_C(   41) },
      {  -INT8_C(   22),  INT8_C(  112),  INT8_C(   26),  INT8_C(    3), -INT8_C(   62),  INT8_C(  100),  INT8_C(   65), -INT8_C(  112),
          INT8_C(   84),  INT8_C(   82),  INT8_C(   38),  INT8_C(  106),  INT8_C(   63),  INT8_C(  101),  INT8_C(   30), -INT8_C(   54) },
      {  -INT8_C(   22),  INT8_C(  112),  INT8_C(   26),  INT8_C(    3), -INT8_C(   62),  INT8_C(  100),  INT8_C(   65), -INT8_C(  112),
          INT8_C(   42), -INT8_C(   87), -INT8_C(  109), -INT8_C(   75),  INT8_C(   32),  INT8_C(   51), -INT8_C(  113), -INT8_C(   27) },
      {  -INT8_C(   22),  INT8_C(  112),  INT8_C(   26),  INT8_C(    3), -INT8_C(   62),  INT8_C(  100),  INT8_C(   65), -INT8_C(  112),
          INT8_C(   11),  INT8_C(  106),  INT8_C(   37), -INT8_C(   19),  INT8_C(    8), -INT8_C(  115),  INT8_C(   36), -INT8_C(    7) } },
    { {   INT16_C(13927), -INT16_C(10193),  INT16_C(23177), -INT16_C(27680),
         -INT16_C(21529),  INT16_C(23032), -INT16_C(14334),  INT16_C(22212) },
      {   INT8_C(  119), -INT8_C(   31),  INT8_C(   33),  INT8_C(   97),
          INT8_C(   32),  INT8_C(   27),  INT8_C(   89),  INT8_C(  101) },
      {   INT8_C(  119), -INT8_C(   31),  INT8_C(   33),  INT8_C(   97),  INT8_C(   32),  INT8_C(   27),  INT8_C(   89),  INT8_C(  101),
          INT8_C(   52),  INT8_C(   24),  INT8_C(   69), -INT8_C(   16), -INT8_C(   12), -INT8_C(    4),  INT8_C(    1),  INT8_C(   98) },
      {   INT8_C(  119), -INT8_C(   31),  INT8_C(   33),  INT8_C(   97),  INT8_C(   32),  INT8_C(   27),  INT8_C(   89),  INT8_C(  101),
         -INT8_C(   51),  INT8_C(    6),  INT8_C(   81),  INT8_C(  124),  INT8_C(  125),  INT8_C(   63),  INT8_C(    0), -INT8_C(   39) },
      {   INT8_C(  119), -INT8_C(   31),  INT8_C(   33),  INT8_C(   97),  INT8_C(   32),  INT8_C(   27),  INT8_C(   89),  INT8_C(  101),
         -INT8_C(   77), -INT8_C(   63), -INT8_C(   44), -INT8_C(   97),  INT8_C(   95), -INT8_C(   48),  INT8_C(   64), -INT8_C(   74) },
      {   INT8_C(  119), -INT8_C(   31),  INT8_C(   33),  INT8_C(   97),  INT8_C(   32),  INT8_C(   27),  INT8_C(   89),  INT8_C(  101),
         -INT8_C(   38),  INT8_C(   97),  INT8_C(  106),  INT8_C(   80), -INT8_C(   80),  INT8_C(  104),  INT8_C(   32),  INT8_C(   91) },
      {   INT8_C(  119), -INT8_C(   31),  INT8_C(   33),  INT8_C(   97),  INT8_C(   32),  INT8_C(   27),  INT8_C(   89),  INT8_C(  101),
          INT8_C(   54), -INT8_C(   40),  INT8_C(   91), -INT8_C(  108), -INT8_C(   84),  INT8_C(   90), -INT8_C(   56),  INT8_C(   87) } },
    { {   INT16_C(19797),  INT16_C(24848), -INT16_C(12237),  INT16_C( 8350),
         -INT16_C(23009),  INT16_C(32417),  INT16_C(15245),  INT16_C(14670) },
      {   INT8_C(   18), -INT8_C(   96),  INT8_C(  121), -INT8_C(  105),
         -INT8_C(   56),  INT8_C(   85), -INT8_C(   52),  INT8_C(    8) },
      {   INT8_C(   18), -INT8_C(   96),  INT8_C(  121), -INT8_C(  105), -INT8_C(   56),  INT8_C(   85), -INT8_C(   52),  INT8_C(    8),
         -INT8_C(   85), -INT8_C(  120),  INT8_C(   26),  INT8_C(   79),  INT8_C(   16),  INT8_C(   81), -INT8_C(   57), -INT8_C(   89) },
      {   INT8_C(   18), -INT8_C(   96),  INT8_C(  121), -INT8_C(  105), -INT8_C(   56),  INT8_C(   85), -INT8_C(   52),  INT8_C(    8),
         -INT8_C(   85),  INT8_C(   34),  INT8_C(    6),  INT8_C(   20), -INT8_C(   60), -INT8_C(   44),  INT8_C(  114),  INT8_C(   42) },
      {   INT8_C(   18), -INT8_C(   96),  INT8_C(  121), -INT8_C(  105), -INT8_C(   56),  INT8_C(   85), -INT8_C(   52),  INT8_C(    8),
          INT8_C(  107),  INT8_C(    9), -INT8_C(  126),  INT8_C(    5),  INT8_C(   49), -INT8_C(   11), -INT8_C(   36), -INT8_C(   54) },
      {   INT8_C(   18), -INT8_C(   96),  INT8_C(  121), -INT8_C(  105), -INT8_C(   56),  INT8_C(   85), -INT8_C(   52),  INT8_C(    8),
          INT8_C(   53), -INT8_C(  124),  INT8_C(   65), -INT8_C(  126), -INT8_C(  104), -INT8_C(    5), -INT8_C(   18), -INT8_C(   27) },
      {   INT8_C(   18), -INT8_C(   96),  INT8_C(  121), -INT8_C(  105), -INT8_C(   56),  INT8_C(   85), -INT8_C(   52),  INT8_C(    8),
          INT8_C(   77),  INT8_C(   97), -INT8_C(   48),  INT8_C(   33), -INT8_C(   90),  INT8_C(  127),  INT8_C(   60),  INT8_C(   57) } },
    { {   INT16_C(14702),  INT16_C(30102),  INT16_C(27970), -INT16_C(23274),
          INT16_C(21570), -INT16_C(20065), -INT16_C(30909),  INT16_C( 8657) },
      {  -INT8_C(   31), -INT8_C(  119), -INT8_C(   20),  INT8_C(   74),
          INT8_C(   10), -INT8_C(   56), -INT8_C(   52), -INT8_C(  114) },
      {  -INT8_C(   31), -INT8_C(  119), -INT8_C(   20),  INT8_C(   74),  INT8_C(   10), -INT8_C(   56), -INT8_C(   52), -INT8_C(  114),
         -INT8_C(   73), -INT8_C(   53), -INT8_C(   95), -INT8_C(  117),  INT8_C(   33), -INT8_C(   48), -INT8_C(   94), -INT8_C(   23) },
      {  -INT8_C(   31), -INT8_C(  119), -INT8_C(   20),  INT8_C(   74),  INT8_C(   10), -INT8_C(   56), -INT8_C(   52), -INT8_C(  114),
          INT8_C(   46), -INT8_C(   77), -INT8_C(   88), -INT8_C(   93), -INT8_C(  120),  INT8_C(   52), -INT8_C(   24),  INT8_C(   58) },
      {  -INT8_C(   31), -INT8_C(  119), -INT8_C(   20),  INT8_C(   74),  INT8_C(   10), -INT8_C(   56), -INT8_C(   52), -INT8_C(  114),
         -INT8_C(   53), -INT8_C(   83),  INT8_C(  106),  INT8_C(   41), -INT8_C(   94), -INT8_C(  115),  INT8_C(   58),  INT8_C(   15) },
      {  -INT8_C(   31), -INT8_C(  119), -INT8_C(   20),  INT8_C(   74),  INT8_C(   10), -INT8_C(   56), -INT8_C(   52), -INT8_C(  114),
         -INT8_C(   26), -INT8_C(   42), -INT8_C(   75), -INT8_C(  108),  INT8_C(   81), -INT8_C(   58),  INT8_C(   29), -INT8_C(  121) },
      {  -INT8_C(   31), -INT8_C(  119), -INT8_C(   20),  INT8_C(   74),  INT8_C(   10), -INT8_C(   56), -INT8_C(   52), -INT8_C(  114),
          INT8_C(   57),  INT8_C(  118),  INT8_C(  109), -INT8_C(   91),  INT8_C(   84), -INT8_C(   78), -INT8_C(  121),  INT8_C(   34) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x8_t r = simde_vld1_s8(test_vec[i].r);

    simde_int8x16_t r1 = simde_vrshrn_high_n_s16(r, a, 1);
    simde_int8x16_t r3 = simde_vrshrn_high_n_s16(r, a, 3);
    simde_int8x16_t r5 = simde_vrshrn_high_n_s16(r, a, 5);
    simde_int8x16_t r6 = simde_vrshrn_high_n_s16(r, a, 6);
    simde_int8x16_t r8 = simde_vrshrn_high_n_s16(r, a, 8);

    simde_test_arm_neon_assert_equal_i8x16(r1, simde_vld1q_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x16(r3, simde_vld1q_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x16(r5, simde_vld1q_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x16(r6, simde_vld1q_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x16(r8, simde_vld1q_s8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vrshrn_high_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t r[4];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r16[8];
  } test_vec[] = {
    { {  -INT32_C(   116519079), -INT32_C(   951911362),  INT32_C(   980070372), -INT32_C(   677594881) },
      {   INT16_C(       14937), -INT16_C(       18878), -INT16_C(       26791),  INT16_C(        3891) },
      {   INT16_C(   14937), -INT16_C(   18878), -INT16_C(   26791),  INT16_C(    3891),
         -INT16_C(   15893),  INT16_C(   24456),  INT16_C(   22013), -INT16_C(   26848) },
      {   INT16_C(   14937), -INT16_C(   18878), -INT16_C(   26791),  INT16_C(    3891),
          INT16_C(   14397),  INT16_C(    3057), -INT16_C(   21824),  INT16_C(   29412) },
      {   INT16_C(   14937), -INT16_C(   18878), -INT16_C(   26791),  INT16_C(    3891),
          INT16_C(   17284), -INT16_C(   12097), -INT16_C(   25940), -INT16_C(    6354) },
      {   INT16_C(   14937), -INT16_C(   18878), -INT16_C(   26791),  INT16_C(    3891),
         -INT16_C(   14224),  INT16_C(   14872), -INT16_C(   11435), -INT16_C(   17178) },
      {   INT16_C(   14937), -INT16_C(   18878), -INT16_C(   26791),  INT16_C(    3891),
         -INT16_C(    1778), -INT16_C(   14525),  INT16_C(   14955), -INT16_C(   10339) } },
    { {  -INT32_C(   632818833), -INT32_C(   456806704),  INT32_C(  1298096978), -INT32_C(  1734838840) },
      {  -INT16_C(       25001),  INT16_C(        7672), -INT16_C(       26306),  INT16_C(        7990) },
      {  -INT16_C(   25001),  INT16_C(    7672), -INT16_C(   26306),  INT16_C(    7990),
         -INT16_C(     402), -INT16_C(   18982), -INT16_C(    5014),  INT16_C(    3769) },
      {  -INT16_C(   25001),  INT16_C(    7672), -INT16_C(   26306),  INT16_C(    7990),
          INT16_C(    8142),  INT16_C(    5819),  INT16_C(   32141),  INT16_C(   25047) },
      {  -INT16_C(   25001),  INT16_C(    7672), -INT16_C(   26306),  INT16_C(    7990),
         -INT16_C(   28163),  INT16_C(   12652),  INT16_C(   22489),  INT16_C(    9757) },
      {  -INT16_C(   25001),  INT16_C(    7672), -INT16_C(   26306),  INT16_C(    7990),
         -INT16_C(   11712),  INT16_C(    9773),  INT16_C(   27387), -INT16_C(   15164) },
      {  -INT16_C(   25001),  INT16_C(    7672), -INT16_C(   26306),  INT16_C(    7990),
         -INT16_C(    9656), -INT16_C(    6970),  INT16_C(   19807), -INT16_C(   26472) } },
    { {  -INT32_C(   417041437),  INT32_C(   920932103), -INT32_C(   884177766),  INT32_C(   723147296) },
      {  -INT16_C(       28020),  INT16_C(        5578),  INT16_C(       21674), -INT16_C(       17090) },
      {  -INT16_C(   28020),  INT16_C(    5578),  INT16_C(   21674), -INT16_C(   17090),
         -INT16_C(   29060), -INT16_C(   30239), -INT16_C(   28525),  INT16_C(   19268) },
      {  -INT16_C(   28020),  INT16_C(    5578),  INT16_C(   21674), -INT16_C(   17090),
         -INT16_C(   28208), -INT16_C(   28356),  INT16_C(   12818),  INT16_C(   26985) },
      {  -INT16_C(   28020),  INT16_C(    5578),  INT16_C(   21674), -INT16_C(   17090),
         -INT16_C(   14051), -INT16_C(   18156), -INT16_C(   11487), -INT16_C(   14697) },
      {  -INT16_C(   28020),  INT16_C(    5578),  INT16_C(   21674), -INT16_C(   17090),
          INT16_C(   14628), -INT16_C(   18654),  INT16_C(   23140),  INT16_C(   22739) },
      {  -INT16_C(   28020),  INT16_C(    5578),  INT16_C(   21674), -INT16_C(   17090),
         -INT16_C(    6364),  INT16_C(   14052), -INT16_C(   13491),  INT16_C(   11034) } },
    { {  -INT32_C(  1420450770),  INT32_C(   924602372), -INT32_C(  1129829990),  INT32_C(  1792300063) },
      {  -INT16_C(       12913),  INT16_C(        1534),  INT16_C(       21877),  INT16_C(        1509) },
      {  -INT16_C(   12913),  INT16_C(    1534),  INT16_C(   21877),  INT16_C(    1509),
         -INT16_C(   19322), -INT16_C(   30207),  INT16_C(    1331), -INT16_C(   30076) },
      {  -INT16_C(   12913),  INT16_C(    1534),  INT16_C(   21877),  INT16_C(    1509),
          INT16_C(   22161),  INT16_C(   28992), -INT16_C(   24410),  INT16_C(   20816) },
      {  -INT16_C(   12913),  INT16_C(    1534),  INT16_C(   21877),  INT16_C(    1509),
         -INT16_C(   10903), -INT16_C(   14572),  INT16_C(   10762), -INT16_C(   19179) },
      {  -INT16_C(   12913),  INT16_C(    1534),  INT16_C(   21877),  INT16_C(    1509),
          INT16_C(   23213), -INT16_C(   18205), -INT16_C(    6847),  INT16_C(   22179) },
      {  -INT16_C(   12913),  INT16_C(    1534),  INT16_C(   21877),  INT16_C(    1509),
         -INT16_C(   21674),  INT16_C(   14108), -INT16_C(   17240),  INT16_C(   27348) } },
    { {   INT32_C(  2018419504), -INT32_C(   580211751), -INT32_C(  1658752744),  INT32_C(   265814774) },
      {  -INT16_C(        8728), -INT16_C(       18486),  INT16_C(       28115), -INT16_C(       19669) },
      {  -INT16_C(    8728), -INT16_C(   18486),  INT16_C(   28115), -INT16_C(   19669),
         -INT16_C(   11162),  INT16_C(   21883),  INT16_C(   11811),  INT16_C(      95) },
      {  -INT16_C(    8728), -INT16_C(   18486),  INT16_C(   28115), -INT16_C(   19669),
          INT16_C(   14989), -INT16_C(   21841), -INT16_C(   31292),  INT16_C(   24588) },
      {  -INT16_C(    8728), -INT16_C(   18486),  INT16_C(   28115), -INT16_C(   19669),
          INT16_C(    5033),  INT16_C(   23211),  INT16_C(   18524), -INT16_C(    2559) },
      {  -INT16_C(    8728), -INT16_C(   18486),  INT16_C(   28115), -INT16_C(   19669),
         -INT16_C(   15755), -INT16_C(    5291), -INT16_C(    5876),  INT16_C(   32448) },
      {  -INT16_C(    8728), -INT16_C(   18486),  INT16_C(   28115), -INT16_C(   19669),
          INT16_C(   30799), -INT16_C(    8853), -INT16_C(   25311),  INT16_C(    4056) } },
    { {   INT32_C(  1943103962),  INT32_C(   748733346), -INT32_C(   923904804), -INT32_C(  1357699688) },
      {   INT16_C(       30943),  INT16_C(        2829), -INT16_C(       32063),  INT16_C(       15491) },
      {   INT16_C(   30943),  INT16_C(    2829), -INT16_C(   32063),  INT16_C(   15491),
          INT16_C(   11579),  INT16_C(    6260), -INT16_C(   13668),  INT16_C(   25779) },
      {   INT16_C(   30943),  INT16_C(    2829), -INT16_C(   32063),  INT16_C(   15491),
          INT16_C(   17831), -INT16_C(   31985), -INT16_C(   18093),  INT16_C(   19606) },
      {   INT16_C(   30943),  INT16_C(    2829), -INT16_C(   32063),  INT16_C(   15491),
         -INT16_C(    2982),  INT16_C(   10289),  INT16_C(   15253), -INT16_C(   15159) },
      {   INT16_C(   30943),  INT16_C(    2829), -INT16_C(   32063),  INT16_C(   15491),
         -INT16_C(   24949),  INT16_C(   25862),  INT16_C(   18291),  INT16_C(   30873) },
      {   INT16_C(   30943),  INT16_C(    2829), -INT16_C(   32063),  INT16_C(   15491),
          INT16_C(   29649),  INT16_C(   11425), -INT16_C(   14098), -INT16_C(   20717) } },
    { {   INT32_C(  1223297293), -INT32_C(  1884479338), -INT32_C(  1576465096), -INT32_C(  1524045132) },
      {  -INT16_C(       15737), -INT16_C(       21460), -INT16_C(        5800),  INT16_C(       14325) },
      {  -INT16_C(   15737), -INT16_C(   21460), -INT16_C(    5800),  INT16_C(   14325),
          INT16_C(   16674), -INT16_C(   23533),  INT16_C(    8615),  INT16_C(    7511) },
      {  -INT16_C(   15737), -INT16_C(   21460), -INT16_C(    5800),  INT16_C(   14325),
         -INT16_C(   22492), -INT16_C(   19326),  INT16_C(    9269), -INT16_C(   23637) },
      {  -INT16_C(   15737), -INT16_C(   21460), -INT16_C(    5800),  INT16_C(   14325),
          INT16_C(   14978), -INT16_C(    5304), -INT16_C(   32189),  INT16_C(   19003) },
      {  -INT16_C(   15737), -INT16_C(   21460), -INT16_C(    5800),  INT16_C(   14325),
          INT16_C(   18256),  INT16_C(   32105),  INT16_C(    4168),  INT16_C(   10567) },
      {  -INT16_C(   15737), -INT16_C(   21460), -INT16_C(    5800),  INT16_C(   14325),
          INT16_C(   18666), -INT16_C(   28755), -INT16_C(   24055), -INT16_C(   23255) } },
    { {   INT32_C(  1605158937), -INT32_C(  1320407505), -INT32_C(   260976609),  INT32_C(  1816201139) },
      {   INT16_C(       23690), -INT16_C(       31570),  INT16_C(        7151), -INT16_C(        3763) },
      {   INT16_C(   23690), -INT16_C(   31570),  INT16_C(    7151), -INT16_C(    3763),
         -INT16_C(   26365), -INT16_C(   31290),  INT16_C(   14852),  INT16_C(    8438) },
      {   INT16_C(   23690), -INT16_C(   31570),  INT16_C(    7151), -INT16_C(    3763),
         -INT16_C(   19680),  INT16_C(   12473), -INT16_C(   14528),  INT16_C(    1055) },
      {   INT16_C(   23690), -INT16_C(   31570),  INT16_C(    7151), -INT16_C(    3763),
         -INT16_C(    5326),  INT16_C(   21260),  INT16_C(    7284),  INT16_C(    4162) },
      {   INT16_C(   23690), -INT16_C(   31570),  INT16_C(    7151), -INT16_C(    3763),
         -INT16_C(     666), -INT16_C(   30111), -INT16_C(   31857),  INT16_C(   25096) },
      {   INT16_C(   23690), -INT16_C(   31570),  INT16_C(    7151), -INT16_C(    3763),
          INT16_C(   24493), -INT16_C(   20148), -INT16_C(    3982),  INT16_C(   27713) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t r = simde_vld1_s16(test_vec[i].r);

    simde_int16x8_t r3 = simde_vrshrn_high_n_s32(r, a, 3);
    simde_int16x8_t r6 = simde_vrshrn_high_n_s32(r, a, 6);
    simde_int16x8_t r10 = simde_vrshrn_high_n_s32(r, a, 10);
    simde_int16x8_t r13 = simde_vrshrn_high_n_s32(r, a, 13);
    simde_int16x8_t r16 = simde_vrshrn_high_n_s32(r, a, 16);

    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r10, simde_vld1q_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x8(r13, simde_vld1q_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x8(r16, simde_vld1q_s16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vrshrn_high_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t r[2];
    int32_t r6[4];
    int32_t r13[4];
    int32_t r19[4];
    int32_t r26[4];
    int32_t r32[4];
  } test_vec[] = {
    { {  INT64_C(522827392458970780), -INT64_C(347963483864753187) },
      { -INT32_C(  1547342019), -INT32_C(  1066804527)  },
      { -INT32_C(  1547342019), -INT32_C(  1066804527), -INT32_C(   113675942),  INT32_C(   945142895)  },
      { -INT32_C(  1547342019), -INT32_C(  1066804527), -INT32_C(  1510837533),  INT32_C(  1215343481)  },
      { -INT32_C(  1547342019), -INT32_C(  1066804527),  INT32_C(   781699532),  INT32_C(  2032255662)  },
      { -INT32_C(  1547342019), -INT32_C(  1066804527), -INT32_C(   799199340), -INT32_C(   890092667)  },
      { -INT32_C(  1547342019), -INT32_C(  1066804527),  INT32_C(   121730238), -INT32_C(    81016562)  } },
    { { -INT64_C(7511569915281881734), -INT64_C(8609781473616875962) },
      { -INT32_C(   313650613), -INT32_C(   510439462)  },
      { -INT32_C(   313650613), -INT32_C(   510439462), -INT32_C(   686263530),  INT32_C(  1998409401)  },
      { -INT32_C(   313650613), -INT32_C(   510439462),  INT32_C(  1471033574),  INT32_C(  1257126557)  },
      { -INT32_C(   313650613), -INT32_C(   510439462),  INT32_C(   828291268),  INT32_C(  2100017386)  },
      { -INT32_C(   313650613), -INT32_C(   510439462), -INT32_C(   261964430),  INT32_C(   553277298)  },
      { -INT32_C(   313650613), -INT32_C(   510439462), -INT32_C(  1748923658), -INT32_C(  2004620962)  } },
    { { -INT64_C(5217461664724359317), -INT64_C(3833958958480156550) },
      {  INT32_C(   529357399),  INT32_C(   818474303)  },
      {  INT32_C(   529357399),  INT32_C(   818474303),  INT32_C(   158567326), -INT32_C(  1882098590)  },
      {  INT32_C(   529357399),  INT32_C(   818474303), -INT32_C(   770513129),  INT32_C(  1428136681)  },
      {  INT32_C(   529357399),  INT32_C(   818474303), -INT32_C(    79148132),  INT32_C(  1632927372)  },
      {  INT32_C(   529357399),  INT32_C(   818474303), -INT32_C(   436825961), -INT32_C(  1295865603)  },
      {  INT32_C(   529357399),  INT32_C(   818474303), -INT32_C(  1214784958), -INT32_C(   892663132)  } },
    { {  INT64_C(8016619778976487131), -INT64_C(5287942160034288787) },
      { -INT32_C(  1170965380),  INT32_C(  1968543732)  },
      { -INT32_C(  1170965380),  INT32_C(  1968543732), -INT32_C(   599454117),  INT32_C(  2098815150)  },
      { -INT32_C(  1170965380),  INT32_C(  1968543732),  INT32_C(   163088925), -INT32_C(  1527106879)  },
      { -INT32_C(  1170965380),  INT32_C(  1968543732),  INT32_C(   405201448), -INT32_C(  1366038325)  },
      { -INT32_C(  1170965380),  INT32_C(  1968543732), -INT32_C(   802140732), -INT32_C(  1487067182)  },
      { -INT32_C(  1170965380),  INT32_C(  1968543732),  INT32_C(  1866514743), -INT32_C(  1231194977)  } },
    { {  INT64_C(2478068447417743253), -INT64_C(4378779670994155852) },
      { -INT32_C(   675478319),  INT32_C(   575064699)  },
      { -INT32_C(   675478319),  INT32_C(   575064699),  INT32_C(  2122694878),  INT32_C(  1529005083)  },
      { -INT32_C(   675478319),  INT32_C(   575064699), -INT32_C(   251851902), -INT32_C(  1732885112)  },
      { -INT32_C(   675478319),  INT32_C(   575064699),  INT32_C(  2076439598),  INT32_C(  1851971862)  },
      { -INT32_C(   675478319),  INT32_C(   575064699), -INT32_C(  1728608280), -INT32_C(   824392270)  },
      { -INT32_C(   675478319),  INT32_C(   575064699),  INT32_C(   576970272), -INT32_C(  1019514089)  } },
    { {  INT64_C(1489761328527602322),  INT64_C(2076240676582230606) },
      {  INT32_C(  1924015755),  INT32_C(   117050398)  },
      {  INT32_C(  1924015755),  INT32_C(   117050398),  INT32_C(   604766666), -INT32_C(  1804625367)  },
      {  INT32_C(  1924015755),  INT32_C(   117050398), -INT32_C(  1874323452),  INT32_C(  1328078644)  },
      {  INT32_C(  1924015755),  INT32_C(   117050398), -INT32_C(  1774116768),  INT32_C(   154968957)  },
      {  INT32_C(  1924015755),  INT32_C(   117050398),  INT32_C(   724337217),  INT32_C(   873625927)  },
      {  INT32_C(  1924015755),  INT32_C(   117050398),  INT32_C(   346862089),  INT32_C(   483412453)  } },
    { {  INT64_C(1404410458338981322),  INT64_C(2196521666701930394) },
      { -INT32_C(  1579182798),  INT32_C(  1435747810)  },
      { -INT32_C(  1579182798),  INT32_C(  1435747810),  INT32_C(  2078313943),  INT32_C(  1171578558)  },
      { -INT32_C(  1579182798),  INT32_C(  1435747810), -INT32_C(  1091059428), -INT32_C(   427054659)  },
      { -INT32_C(  1579182798),  INT32_C(  1435747810), -INT32_C(  1359225084),  INT32_C(  1939484327)  },
      { -INT32_C(  1579182798),  INT32_C(  1435747810), -INT32_C(   547489858), -INT32_C(  1629014947)  },
      { -INT32_C(  1579182798),  INT32_C(  1435747810),  INT32_C(   326989791),  INT32_C(   511417553)  } },
    { {  INT64_C(467500832710821027),  INT64_C(1909358569727587315) },
      {  INT32_C(  2012855853), -INT32_C(   296579437)  },
      {  INT32_C(  2012855853), -INT32_C(   296579437),  INT32_C(   522696211),  INT32_C(    50714576)  },
      {  INT32_C(  2012855853), -INT32_C(   296579437),  INT32_C(   742281068),  INT32_C(  1007029168)  },
      {  INT32_C(  2012855853), -INT32_C(   296579437), -INT32_C(  1666123458), -INT32_C(   319809489)  },
      {  INT32_C(  2012855853), -INT32_C(   296579437), -INT32_C(  1623629326), -INT32_C(  1613111248)  },
      {  INT32_C(  2012855853), -INT32_C(   296579437),  INT32_C(   108848520),  INT32_C(   444557185)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t r = simde_vld1_s32(test_vec[i].r);

    simde_int32x4_t r6 = simde_vrshrn_high_n_s64(r, a, 6);
    simde_int32x4_t r13 = simde_vrshrn_high_n_s64(r, a, 13);
    simde_int32x4_t r19 = simde_vrshrn_high_n_s64(r, a, 19);
    simde_int32x4_t r26 = simde_vrshrn_high_n_s64(r, a, 26);
    simde_int32x4_t r32 = simde_vrshrn_high_n_s64(r, a, 32);

    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r19, simde_vld1q_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x4(r26, simde_vld1q_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x4(r32, simde_vld1q_s32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vrshrn_high_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[8];
    uint8_t r[8];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r8[16];
  } test_vec[] = {
    { {  UINT16_C(  4891),  UINT16_C( 61518),  UINT16_C( 56040),  UINT16_C( 56087),  UINT16_C( 50073),  UINT16_C( 24780),  UINT16_C( 61165),  UINT16_C(  6842) },
      {  UINT8_C(229),  UINT8_C(181),  UINT8_C(120),  UINT8_C(103),  UINT8_C(107),  UINT8_C( 74),  UINT8_C( 98),  UINT8_C( 43)  },
      {  UINT8_C(229),  UINT8_C(181),  UINT8_C(120),  UINT8_C(103),  UINT8_C(107),  UINT8_C( 74),  UINT8_C( 98),  UINT8_C( 43),  UINT8_C(142),  UINT8_C( 39),  UINT8_C(116),  UINT8_C(140),  UINT8_C(205),  UINT8_C(102),  UINT8_C(119),  UINT8_C( 93)  },
      {  UINT8_C(229),  UINT8_C(181),  UINT8_C(120),  UINT8_C(103),  UINT8_C(107),  UINT8_C( 74),  UINT8_C( 98),  UINT8_C( 43),  UINT8_C( 99),  UINT8_C( 10),  UINT8_C( 93),  UINT8_C( 99),  UINT8_C(115),  UINT8_C( 26),  UINT8_C(222),  UINT8_C( 87)  },
      {  UINT8_C(229),  UINT8_C(181),  UINT8_C(120),  UINT8_C(103),  UINT8_C(107),  UINT8_C( 74),  UINT8_C( 98),  UINT8_C( 43),  UINT8_C(153),  UINT8_C(130),  UINT8_C(215),  UINT8_C(217),  UINT8_C( 29),  UINT8_C(  6),  UINT8_C(119),  UINT8_C(214)  },
      {  UINT8_C(229),  UINT8_C(181),  UINT8_C(120),  UINT8_C(103),  UINT8_C(107),  UINT8_C( 74),  UINT8_C( 98),  UINT8_C( 43),  UINT8_C( 76),  UINT8_C(193),  UINT8_C(108),  UINT8_C(108),  UINT8_C( 14),  UINT8_C(131),  UINT8_C(188),  UINT8_C(107)  },
      {  UINT8_C(229),  UINT8_C(181),  UINT8_C(120),  UINT8_C(103),  UINT8_C(107),  UINT8_C( 74),  UINT8_C( 98),  UINT8_C( 43),  UINT8_C( 19),  UINT8_C(240),  UINT8_C(219),  UINT8_C(219),  UINT8_C(196),  UINT8_C( 97),  UINT8_C(239),  UINT8_C( 27)  } },
    { {  UINT16_C( 45300),  UINT16_C( 60746),  UINT16_C( 20949),  UINT16_C(  2061),  UINT16_C( 22701),  UINT16_C( 38253),  UINT16_C( 36627),  UINT16_C( 39372) },
      {  UINT8_C(176),  UINT8_C(169),  UINT8_C(166),  UINT8_C(123),  UINT8_C(155),  UINT8_C(136),  UINT8_C(139),  UINT8_C(225)  },
      {  UINT8_C(176),  UINT8_C(169),  UINT8_C(166),  UINT8_C(123),  UINT8_C(155),  UINT8_C(136),  UINT8_C(139),  UINT8_C(225),  UINT8_C(122),  UINT8_C(165),  UINT8_C(235),  UINT8_C(  7),  UINT8_C( 87),  UINT8_C(183),  UINT8_C(138),  UINT8_C(230)  },
      {  UINT8_C(176),  UINT8_C(169),  UINT8_C(166),  UINT8_C(123),  UINT8_C(155),  UINT8_C(136),  UINT8_C(139),  UINT8_C(225),  UINT8_C( 31),  UINT8_C(169),  UINT8_C( 59),  UINT8_C(  2),  UINT8_C( 22),  UINT8_C(174),  UINT8_C(226),  UINT8_C( 58)  },
      {  UINT8_C(176),  UINT8_C(169),  UINT8_C(166),  UINT8_C(123),  UINT8_C(155),  UINT8_C(136),  UINT8_C(139),  UINT8_C(225),  UINT8_C(136),  UINT8_C(106),  UINT8_C(143),  UINT8_C( 64),  UINT8_C(197),  UINT8_C(171),  UINT8_C(121),  UINT8_C(206)  },
      {  UINT8_C(176),  UINT8_C(169),  UINT8_C(166),  UINT8_C(123),  UINT8_C(155),  UINT8_C(136),  UINT8_C(139),  UINT8_C(225),  UINT8_C(196),  UINT8_C(181),  UINT8_C( 71),  UINT8_C( 32),  UINT8_C( 99),  UINT8_C( 86),  UINT8_C( 60),  UINT8_C(103)  },
      {  UINT8_C(176),  UINT8_C(169),  UINT8_C(166),  UINT8_C(123),  UINT8_C(155),  UINT8_C(136),  UINT8_C(139),  UINT8_C(225),  UINT8_C(177),  UINT8_C(237),  UINT8_C( 82),  UINT8_C(  8),  UINT8_C( 89),  UINT8_C(149),  UINT8_C(143),  UINT8_C(154)  } },
    { {  UINT16_C( 50411),  UINT16_C(  5375),  UINT16_C( 13061),  UINT16_C( 55963),  UINT16_C( 58746),  UINT16_C( 42849),  UINT16_C( 39459),  UINT16_C( 39900) },
      {  UINT8_C( 79),  UINT8_C( 19),  UINT8_C(207),  UINT8_C(136),  UINT8_C(181),  UINT8_C(169),  UINT8_C(171),  UINT8_C( 38)  },
      {  UINT8_C( 79),  UINT8_C( 19),  UINT8_C(207),  UINT8_C(136),  UINT8_C(181),  UINT8_C(169),  UINT8_C(171),  UINT8_C( 38),  UINT8_C(118),  UINT8_C(128),  UINT8_C(131),  UINT8_C( 78),  UINT8_C(189),  UINT8_C(177),  UINT8_C( 18),  UINT8_C(238)  },
      {  UINT8_C( 79),  UINT8_C( 19),  UINT8_C(207),  UINT8_C(136),  UINT8_C(181),  UINT8_C(169),  UINT8_C(171),  UINT8_C( 38),  UINT8_C(157),  UINT8_C(160),  UINT8_C( 97),  UINT8_C( 83),  UINT8_C(175),  UINT8_C(236),  UINT8_C( 68),  UINT8_C(124)  },
      {  UINT8_C( 79),  UINT8_C( 19),  UINT8_C(207),  UINT8_C(136),  UINT8_C(181),  UINT8_C(169),  UINT8_C(171),  UINT8_C( 38),  UINT8_C( 39),  UINT8_C(168),  UINT8_C(152),  UINT8_C(213),  UINT8_C( 44),  UINT8_C( 59),  UINT8_C(209),  UINT8_C(223)  },
      {  UINT8_C( 79),  UINT8_C( 19),  UINT8_C(207),  UINT8_C(136),  UINT8_C(181),  UINT8_C(169),  UINT8_C(171),  UINT8_C( 38),  UINT8_C( 20),  UINT8_C( 84),  UINT8_C(204),  UINT8_C(106),  UINT8_C(150),  UINT8_C(158),  UINT8_C(105),  UINT8_C(111)  },
      {  UINT8_C( 79),  UINT8_C( 19),  UINT8_C(207),  UINT8_C(136),  UINT8_C(181),  UINT8_C(169),  UINT8_C(171),  UINT8_C( 38),  UINT8_C(197),  UINT8_C( 21),  UINT8_C( 51),  UINT8_C(219),  UINT8_C(229),  UINT8_C(167),  UINT8_C(154),  UINT8_C(156)  } },
    { {  UINT16_C( 11077),  UINT16_C(  7355),  UINT16_C(  7596),  UINT16_C( 52604),  UINT16_C( 46540),  UINT16_C( 19909),  UINT16_C(  9197),  UINT16_C(  7039) },
      {  UINT8_C(216),  UINT8_C(149),  UINT8_C(149),  UINT8_C(244),  UINT8_C(247),  UINT8_C(224),  UINT8_C( 78),  UINT8_C( 18)  },
      {  UINT8_C(216),  UINT8_C(149),  UINT8_C(149),  UINT8_C(244),  UINT8_C(247),  UINT8_C(224),  UINT8_C( 78),  UINT8_C( 18),  UINT8_C(163),  UINT8_C( 94),  UINT8_C(214),  UINT8_C(190),  UINT8_C(230),  UINT8_C(227),  UINT8_C(247),  UINT8_C(192)  },
      {  UINT8_C(216),  UINT8_C(149),  UINT8_C(149),  UINT8_C(244),  UINT8_C(247),  UINT8_C(224),  UINT8_C( 78),  UINT8_C( 18),  UINT8_C(105),  UINT8_C(151),  UINT8_C(182),  UINT8_C(176),  UINT8_C(186),  UINT8_C(185),  UINT8_C(126),  UINT8_C(112)  },
      {  UINT8_C(216),  UINT8_C(149),  UINT8_C(149),  UINT8_C(244),  UINT8_C(247),  UINT8_C(224),  UINT8_C( 78),  UINT8_C( 18),  UINT8_C( 90),  UINT8_C(230),  UINT8_C(237),  UINT8_C(108),  UINT8_C(174),  UINT8_C(110),  UINT8_C( 31),  UINT8_C(220)  },
      {  UINT8_C(216),  UINT8_C(149),  UINT8_C(149),  UINT8_C(244),  UINT8_C(247),  UINT8_C(224),  UINT8_C( 78),  UINT8_C( 18),  UINT8_C(173),  UINT8_C(115),  UINT8_C(119),  UINT8_C( 54),  UINT8_C(215),  UINT8_C( 55),  UINT8_C(144),  UINT8_C(110)  },
      {  UINT8_C(216),  UINT8_C(149),  UINT8_C(149),  UINT8_C(244),  UINT8_C(247),  UINT8_C(224),  UINT8_C( 78),  UINT8_C( 18),  UINT8_C( 43),  UINT8_C( 29),  UINT8_C( 30),  UINT8_C(205),  UINT8_C(182),  UINT8_C( 78),  UINT8_C( 36),  UINT8_C( 27)  } },
    { {  UINT16_C( 58307),  UINT16_C( 29751),  UINT16_C( 64220),  UINT16_C( 37850),  UINT16_C( 11545),  UINT16_C( 37711),  UINT16_C( 37447),  UINT16_C( 29012) },
      {  UINT8_C(185),  UINT8_C(186),  UINT8_C(  7),  UINT8_C( 23),  UINT8_C(222),  UINT8_C(205),  UINT8_C( 62),  UINT8_C(213)  },
      {  UINT8_C(185),  UINT8_C(186),  UINT8_C(  7),  UINT8_C( 23),  UINT8_C(222),  UINT8_C(205),  UINT8_C( 62),  UINT8_C(213),  UINT8_C(226),  UINT8_C( 28),  UINT8_C(110),  UINT8_C(237),  UINT8_C(141),  UINT8_C(168),  UINT8_C( 36),  UINT8_C(170)  },
      {  UINT8_C(185),  UINT8_C(186),  UINT8_C(  7),  UINT8_C( 23),  UINT8_C(222),  UINT8_C(205),  UINT8_C( 62),  UINT8_C(213),  UINT8_C(120),  UINT8_C(135),  UINT8_C( 92),  UINT8_C(123),  UINT8_C(163),  UINT8_C(106),  UINT8_C( 73),  UINT8_C( 43)  },
      {  UINT8_C(185),  UINT8_C(186),  UINT8_C(  7),  UINT8_C( 23),  UINT8_C(222),  UINT8_C(205),  UINT8_C( 62),  UINT8_C(213),  UINT8_C( 30),  UINT8_C(162),  UINT8_C(215),  UINT8_C(159),  UINT8_C(105),  UINT8_C(154),  UINT8_C(146),  UINT8_C(139)  },
      {  UINT8_C(185),  UINT8_C(186),  UINT8_C(  7),  UINT8_C( 23),  UINT8_C(222),  UINT8_C(205),  UINT8_C( 62),  UINT8_C(213),  UINT8_C(143),  UINT8_C(209),  UINT8_C(235),  UINT8_C( 79),  UINT8_C(180),  UINT8_C( 77),  UINT8_C( 73),  UINT8_C(197)  },
      {  UINT8_C(185),  UINT8_C(186),  UINT8_C(  7),  UINT8_C( 23),  UINT8_C(222),  UINT8_C(205),  UINT8_C( 62),  UINT8_C(213),  UINT8_C(228),  UINT8_C(116),  UINT8_C(251),  UINT8_C(148),  UINT8_C( 45),  UINT8_C(147),  UINT8_C(146),  UINT8_C(113)  } },
    { {  UINT16_C( 27363),  UINT16_C(  2309),  UINT16_C( 25695),  UINT16_C( 21876),  UINT16_C( 35306),  UINT16_C( 36813),  UINT16_C( 39387),  UINT16_C( 17083) },
      {  UINT8_C( 57),  UINT8_C(244),  UINT8_C( 78),  UINT8_C( 15),  UINT8_C(175),  UINT8_C(168),  UINT8_C(108),  UINT8_C(  0)  },
      {  UINT8_C( 57),  UINT8_C(244),  UINT8_C( 78),  UINT8_C( 15),  UINT8_C(175),  UINT8_C(168),  UINT8_C(108),  UINT8_C(  0),  UINT8_C(114),  UINT8_C(131),  UINT8_C( 48),  UINT8_C(186),  UINT8_C(245),  UINT8_C(231),  UINT8_C(238),  UINT8_C( 94)  },
      {  UINT8_C( 57),  UINT8_C(244),  UINT8_C( 78),  UINT8_C( 15),  UINT8_C(175),  UINT8_C(168),  UINT8_C(108),  UINT8_C(  0),  UINT8_C( 92),  UINT8_C( 33),  UINT8_C(140),  UINT8_C(175),  UINT8_C( 61),  UINT8_C(250),  UINT8_C( 59),  UINT8_C( 87)  },
      {  UINT8_C( 57),  UINT8_C(244),  UINT8_C( 78),  UINT8_C( 15),  UINT8_C(175),  UINT8_C(168),  UINT8_C(108),  UINT8_C(  0),  UINT8_C( 87),  UINT8_C( 72),  UINT8_C( 35),  UINT8_C(172),  UINT8_C( 79),  UINT8_C(126),  UINT8_C(207),  UINT8_C( 22)  },
      {  UINT8_C( 57),  UINT8_C(244),  UINT8_C( 78),  UINT8_C( 15),  UINT8_C(175),  UINT8_C(168),  UINT8_C(108),  UINT8_C(  0),  UINT8_C(172),  UINT8_C( 36),  UINT8_C(145),  UINT8_C( 86),  UINT8_C( 40),  UINT8_C( 63),  UINT8_C(103),  UINT8_C( 11)  },
      {  UINT8_C( 57),  UINT8_C(244),  UINT8_C( 78),  UINT8_C( 15),  UINT8_C(175),  UINT8_C(168),  UINT8_C(108),  UINT8_C(  0),  UINT8_C(107),  UINT8_C(  9),  UINT8_C(100),  UINT8_C( 85),  UINT8_C(138),  UINT8_C(144),  UINT8_C(154),  UINT8_C( 67)  } },
    { {  UINT16_C( 25471),  UINT16_C( 24819),  UINT16_C( 29221),  UINT16_C( 12141),  UINT16_C( 38560),  UINT16_C( 48255),  UINT16_C( 11379),  UINT16_C( 48434) },
      {  UINT8_C( 89),  UINT8_C( 46),  UINT8_C( 14),  UINT8_C(127),  UINT8_C( 99),  UINT8_C( 59),  UINT8_C(123),  UINT8_C( 86)  },
      {  UINT8_C( 89),  UINT8_C( 46),  UINT8_C( 14),  UINT8_C(127),  UINT8_C( 99),  UINT8_C( 59),  UINT8_C(123),  UINT8_C( 86),  UINT8_C(192),  UINT8_C(122),  UINT8_C( 19),  UINT8_C(183),  UINT8_C( 80),  UINT8_C( 64),  UINT8_C( 58),  UINT8_C(153)  },
      {  UINT8_C( 89),  UINT8_C( 46),  UINT8_C( 14),  UINT8_C(127),  UINT8_C( 99),  UINT8_C( 59),  UINT8_C(123),  UINT8_C( 86),  UINT8_C(112),  UINT8_C( 30),  UINT8_C( 69),  UINT8_C(238),  UINT8_C(212),  UINT8_C(144),  UINT8_C(142),  UINT8_C(166)  },
      {  UINT8_C( 89),  UINT8_C( 46),  UINT8_C( 14),  UINT8_C(127),  UINT8_C( 99),  UINT8_C( 59),  UINT8_C(123),  UINT8_C( 86),  UINT8_C( 28),  UINT8_C(  8),  UINT8_C(145),  UINT8_C(123),  UINT8_C(181),  UINT8_C(228),  UINT8_C(100),  UINT8_C(234)  },
      {  UINT8_C( 89),  UINT8_C( 46),  UINT8_C( 14),  UINT8_C(127),  UINT8_C( 99),  UINT8_C( 59),  UINT8_C(123),  UINT8_C( 86),  UINT8_C(142),  UINT8_C(132),  UINT8_C(201),  UINT8_C(190),  UINT8_C( 91),  UINT8_C(242),  UINT8_C(178),  UINT8_C(245)  },
      {  UINT8_C( 89),  UINT8_C( 46),  UINT8_C( 14),  UINT8_C(127),  UINT8_C( 99),  UINT8_C( 59),  UINT8_C(123),  UINT8_C( 86),  UINT8_C( 99),  UINT8_C( 97),  UINT8_C(114),  UINT8_C( 47),  UINT8_C(151),  UINT8_C(188),  UINT8_C( 44),  UINT8_C(189)  } },
    { {  UINT16_C( 36224),  UINT16_C(  8314),  UINT16_C( 32940),  UINT16_C( 63808),  UINT16_C( 56263),  UINT16_C( 52379),  UINT16_C( 17081),  UINT16_C( 58652) },
      {  UINT8_C(222),  UINT8_C(131),  UINT8_C(103),  UINT8_C(113),  UINT8_C( 90),  UINT8_C( 24),  UINT8_C(198),  UINT8_C(117)  },
      {  UINT8_C(222),  UINT8_C(131),  UINT8_C(103),  UINT8_C(113),  UINT8_C( 90),  UINT8_C( 24),  UINT8_C(198),  UINT8_C(117),  UINT8_C(192),  UINT8_C( 61),  UINT8_C( 86),  UINT8_C(160),  UINT8_C(228),  UINT8_C( 78),  UINT8_C( 93),  UINT8_C(142)  },
      {  UINT8_C(222),  UINT8_C(131),  UINT8_C(103),  UINT8_C(113),  UINT8_C( 90),  UINT8_C( 24),  UINT8_C(198),  UINT8_C(117),  UINT8_C(176),  UINT8_C( 15),  UINT8_C( 22),  UINT8_C( 40),  UINT8_C(121),  UINT8_C(147),  UINT8_C( 87),  UINT8_C(164)  },
      {  UINT8_C(222),  UINT8_C(131),  UINT8_C(103),  UINT8_C(113),  UINT8_C( 90),  UINT8_C( 24),  UINT8_C(198),  UINT8_C(117),  UINT8_C(108),  UINT8_C(  4),  UINT8_C(  5),  UINT8_C(202),  UINT8_C(222),  UINT8_C(101),  UINT8_C( 22),  UINT8_C( 41)  },
      {  UINT8_C(222),  UINT8_C(131),  UINT8_C(103),  UINT8_C(113),  UINT8_C( 90),  UINT8_C( 24),  UINT8_C(198),  UINT8_C(117),  UINT8_C( 54),  UINT8_C(130),  UINT8_C(  3),  UINT8_C(229),  UINT8_C(111),  UINT8_C( 50),  UINT8_C( 11),  UINT8_C(148)  },
      {  UINT8_C(222),  UINT8_C(131),  UINT8_C(103),  UINT8_C(113),  UINT8_C( 90),  UINT8_C( 24),  UINT8_C(198),  UINT8_C(117),  UINT8_C(142),  UINT8_C( 32),  UINT8_C(129),  UINT8_C(249),  UINT8_C(220),  UINT8_C(205),  UINT8_C( 67),  UINT8_C(229)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x8_t r = simde_vld1_u8(test_vec[i].r);

    simde_uint8x16_t r1 = simde_vrshrn_high_n_u16(r, a, 1);
    simde_uint8x16_t r3 = simde_vrshrn_high_n_u16(r, a, 3);
    simde_uint8x16_t r5 = simde_vrshrn_high_n_u16(r, a, 5);
    simde_uint8x16_t r6 = simde_vrshrn_high_n_u16(r, a, 6);
    simde_uint8x16_t r8 = simde_vrshrn_high_n_u16(r, a, 8);

    simde_test_arm_neon_assert_equal_u8x16(r1, simde_vld1q_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r6, simde_vld1q_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x16(r8, simde_vld1q_u8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vrshrn_high_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[4];
    uint16_t r[4];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r16[8];
  } test_vec[] = {
    { {  UINT32_C(    87549657),  UINT32_C(  3197875600),  UINT32_C(  3423107810),  UINT32_C(  1562909874) },
      {  UINT16_C( 17400),  UINT16_C( 19521),  UINT16_C( 57287),  UINT16_C( 12301)  },
      {  UINT16_C( 17400),  UINT16_C( 19521),  UINT16_C( 57287),  UINT16_C( 12301),  UINT16_C( 64731),  UINT16_C( 30386),  UINT16_C(  3932),  UINT16_C(   918)  },
      {  UINT16_C( 17400),  UINT16_C( 19521),  UINT16_C( 57287),  UINT16_C( 12301),  UINT16_C( 57243),  UINT16_C( 28374),  UINT16_C(  8684),  UINT16_C( 41075)  },
      {  UINT16_C( 17400),  UINT16_C( 19521),  UINT16_C( 57287),  UINT16_C( 12301),  UINT16_C( 19962),  UINT16_C( 42733),  UINT16_C(   543),  UINT16_C( 18951)  },
      {  UINT16_C( 17400),  UINT16_C( 19521),  UINT16_C( 57287),  UINT16_C( 12301),  UINT16_C( 10687),  UINT16_C( 62686),  UINT16_C( 24644),  UINT16_C( 59713)  },
      {  UINT16_C( 17400),  UINT16_C( 19521),  UINT16_C( 57287),  UINT16_C( 12301),  UINT16_C(  1336),  UINT16_C( 48796),  UINT16_C( 52232),  UINT16_C( 23848)  } },
    { {  UINT32_C(  1133139453),  UINT32_C(   368185956),  UINT32_C(   458320166),  UINT32_C(  3496695836) },
      {  UINT16_C( 44607),  UINT16_C( 33562),  UINT16_C( 36745),  UINT16_C( 21906)  },
      {  UINT16_C( 44607),  UINT16_C( 33562),  UINT16_C( 36745),  UINT16_C( 21906),  UINT16_C( 19136),  UINT16_C( 16973),  UINT16_C( 11557),  UINT16_C( 27396)  },
      {  UINT16_C( 44607),  UINT16_C( 33562),  UINT16_C( 36745),  UINT16_C( 21906),  UINT16_C( 10584),  UINT16_C( 51274),  UINT16_C( 17829),  UINT16_C( 44384)  },
      {  UINT16_C( 44607),  UINT16_C( 33562),  UINT16_C( 36745),  UINT16_C( 21906),  UINT16_C( 58005),  UINT16_C( 31877),  UINT16_C( 54362),  UINT16_C(  6870)  },
      {  UINT16_C( 44607),  UINT16_C( 33562),  UINT16_C( 36745),  UINT16_C( 21906),  UINT16_C(  7251),  UINT16_C( 44945),  UINT16_C( 55947),  UINT16_C( 33627)  },
      {  UINT16_C( 44607),  UINT16_C( 33562),  UINT16_C( 36745),  UINT16_C( 21906),  UINT16_C( 17290),  UINT16_C(  5618),  UINT16_C(  6993),  UINT16_C( 53355)  } },
    { {  UINT32_C(   980851135),  UINT32_C(   793656310),  UINT32_C(  2985559125),  UINT32_C(   560062105) },
      {  UINT16_C( 38879),  UINT16_C(   213),  UINT16_C( 15569),  UINT16_C( 36173)  },
      {  UINT16_C( 38879),  UINT16_C(   213),  UINT16_C( 15569),  UINT16_C( 36173),  UINT16_C( 54072),  UINT16_C( 51071),  UINT16_C( 32907),  UINT16_C( 15315)  },
      {  UINT16_C( 38879),  UINT16_C(   213),  UINT16_C( 15569),  UINT16_C( 36173),  UINT16_C( 55911),  UINT16_C( 14576),  UINT16_C( 53265),  UINT16_C( 34682)  },
      {  UINT16_C( 38879),  UINT16_C(   213),  UINT16_C( 15569),  UINT16_C( 36173),  UINT16_C( 40358),  UINT16_C( 54159),  UINT16_C( 32001),  UINT16_C( 22648)  },
      {  UINT16_C( 38879),  UINT16_C(   213),  UINT16_C( 15569),  UINT16_C( 36173),  UINT16_C( 54197),  UINT16_C( 31346),  UINT16_C( 36768),  UINT16_C(  2831)  },
      {  UINT16_C( 38879),  UINT16_C(   213),  UINT16_C( 15569),  UINT16_C( 36173),  UINT16_C( 14967),  UINT16_C( 12110),  UINT16_C( 45556),  UINT16_C(  8546)  } },
    { {  UINT32_C(  1422970508),  UINT32_C(   343243953),  UINT32_C(   404026163),  UINT32_C(  4166559419) },
      {  UINT16_C( 14167),  UINT16_C(  4288),  UINT16_C( 34735),  UINT16_C( 50503)  },
      {  UINT16_C( 14167),  UINT16_C(  4288),  UINT16_C( 34735),  UINT16_C( 50503),  UINT16_C(  6610),  UINT16_C( 44950),  UINT16_C( 40550),  UINT16_C(  5335)  },
      {  UINT16_C( 14167),  UINT16_C(  4288),  UINT16_C( 34735),  UINT16_C( 50503),  UINT16_C( 17210),  UINT16_C( 54771),  UINT16_C( 21453),  UINT16_C( 25243)  },
      {  UINT16_C( 14167),  UINT16_C(  4288),  UINT16_C( 34735),  UINT16_C( 50503),  UINT16_C( 13364),  UINT16_C(  7519),  UINT16_C(  1341),  UINT16_C(  5674)  },
      {  UINT16_C( 14167),  UINT16_C(  4288),  UINT16_C( 34735),  UINT16_C( 50503),  UINT16_C( 42630),  UINT16_C( 41900),  UINT16_C( 49320),  UINT16_C( 49861)  },
      {  UINT16_C( 14167),  UINT16_C(  4288),  UINT16_C( 34735),  UINT16_C( 50503),  UINT16_C( 21713),  UINT16_C(  5237),  UINT16_C(  6165),  UINT16_C( 63577)  } },
    { {  UINT32_C(  1025494157),  UINT32_C(  1044321423),  UINT32_C(  3497459030),  UINT32_C(  4040193428) },
      {  UINT16_C( 33360),  UINT16_C( 17888),  UINT16_C( 49892),  UINT16_C( 38606)  },
      {  UINT16_C( 33360),  UINT16_C( 17888),  UINT16_C( 49892),  UINT16_C( 38606),  UINT16_C( 63890),  UINT16_C( 58002),  UINT16_C( 57259),  UINT16_C(  3763)  },
      {  UINT16_C( 33360),  UINT16_C( 17888),  UINT16_C( 49892),  UINT16_C( 38606),  UINT16_C( 32562),  UINT16_C( 64594),  UINT16_C( 56309),  UINT16_C( 16854)  },
      {  UINT16_C( 33360),  UINT16_C( 17888),  UINT16_C( 49892),  UINT16_C( 38606),  UINT16_C( 18419),  UINT16_C( 36805),  UINT16_C(  7615),  UINT16_C( 13341)  },
      {  UINT16_C( 33360),  UINT16_C( 17888),  UINT16_C( 49892),  UINT16_C( 38606),  UINT16_C( 59646),  UINT16_C( 61945),  UINT16_C( 33720),  UINT16_C( 34436)  },
      {  UINT16_C( 33360),  UINT16_C( 17888),  UINT16_C( 49892),  UINT16_C( 38606),  UINT16_C( 15648),  UINT16_C( 15935),  UINT16_C( 53367),  UINT16_C( 61648)  } },
    { {  UINT32_C(  3455883293),  UINT32_C(  3831475108),  UINT32_C(  1766784541),  UINT32_C(  3258319112) },
      {  UINT16_C( 59822),  UINT16_C( 57292),  UINT16_C(  5363),  UINT16_C( 23497)  },
      {  UINT16_C( 59822),  UINT16_C( 57292),  UINT16_C(  5363),  UINT16_C( 23497),  UINT16_C( 37636),  UINT16_C( 62837),  UINT16_C( 57284),  UINT16_C( 49185)  },
      {  UINT16_C( 59822),  UINT16_C( 57292),  UINT16_C(  5363),  UINT16_C( 23497),  UINT16_C( 62048),  UINT16_C( 32431),  UINT16_C( 15352),  UINT16_C( 55300)  },
      {  UINT16_C( 59822),  UINT16_C( 57292),  UINT16_C(  5363),  UINT16_C( 23497),  UINT16_C( 32550),  UINT16_C(  6123),  UINT16_C( 21440),  UINT16_C( 36224)  },
      {  UINT16_C( 59822),  UINT16_C( 57292),  UINT16_C(  5363),  UINT16_C( 23497),  UINT16_C( 28645),  UINT16_C(  8957),  UINT16_C( 19064),  UINT16_C(  4528)  },
      {  UINT16_C( 59822),  UINT16_C( 57292),  UINT16_C(  5363),  UINT16_C( 23497),  UINT16_C( 52733),  UINT16_C( 58464),  UINT16_C( 26959),  UINT16_C( 49718)  } },
    { {  UINT32_C(  2005456876),  UINT32_C(  2730066849),  UINT32_C(   749824633),  UINT32_C(  1930375946) },
      {  UINT16_C( 42802),  UINT16_C( 65518),  UINT16_C( 23836),  UINT16_C( 42117)  },
      {  UINT16_C( 42802),  UINT16_C( 65518),  UINT16_C( 23836),  UINT16_C( 42117),  UINT16_C(  6910),  UINT16_C( 12404),  UINT16_C( 11599),  UINT16_C( 58977)  },
      {  UINT16_C( 42802),  UINT16_C( 65518),  UINT16_C( 23836),  UINT16_C( 42117),  UINT16_C(  9056),  UINT16_C( 58895),  UINT16_C( 50602),  UINT16_C( 15564)  },
      {  UINT16_C( 42802),  UINT16_C( 65518),  UINT16_C( 23836),  UINT16_C( 42117),  UINT16_C( 57910),  UINT16_C( 44641),  UINT16_C( 11355),  UINT16_C( 50125)  },
      {  UINT16_C( 42802),  UINT16_C( 65518),  UINT16_C( 23836),  UINT16_C( 42117),  UINT16_C( 48199),  UINT16_C(  5580),  UINT16_C( 25995),  UINT16_C( 39034)  },
      {  UINT16_C( 42802),  UINT16_C( 65518),  UINT16_C( 23836),  UINT16_C( 42117),  UINT16_C( 30601),  UINT16_C( 41658),  UINT16_C( 11441),  UINT16_C( 29455)  } },
    { {  UINT32_C(   148880009),  UINT32_C(  3807681043),  UINT32_C(  3754381792),  UINT32_C(  3404112735) },
      {  UINT16_C(  2886),  UINT16_C( 62845),  UINT16_C( 16231),  UINT16_C( 11767)  },
      {  UINT16_C(  2886),  UINT16_C( 62845),  UINT16_C( 16231),  UINT16_C( 11767),  UINT16_C( 63313),  UINT16_C( 37698),  UINT16_C( 59964),  UINT16_C( 54380)  },
      {  UINT16_C(  2886),  UINT16_C( 62845),  UINT16_C( 16231),  UINT16_C( 11767),  UINT16_C( 32490),  UINT16_C( 53864),  UINT16_C(  7496),  UINT16_C( 39565)  },
      {  UINT16_C(  2886),  UINT16_C( 62845),  UINT16_C( 16231),  UINT16_C( 11767),  UINT16_C( 14319),  UINT16_C( 48423),  UINT16_C( 61908),  UINT16_C( 47529)  },
      {  UINT16_C(  2886),  UINT16_C( 62845),  UINT16_C( 16231),  UINT16_C( 11767),  UINT16_C( 18174),  UINT16_C(  6053),  UINT16_C( 65083),  UINT16_C( 22325)  },
      {  UINT16_C(  2886),  UINT16_C( 62845),  UINT16_C( 16231),  UINT16_C( 11767),  UINT16_C(  2272),  UINT16_C( 58101),  UINT16_C( 57287),  UINT16_C( 51943)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x4_t r = simde_vld1_u16(test_vec[i].r);

    simde_uint16x8_t r3 = simde_vrshrn_high_n_u32(r, a, 3);
    simde_uint16x8_t r6 = simde_vrshrn_high_n_u32(r, a, 6);
    simde_uint16x8_t r10 = simde_vrshrn_high_n_u32(r, a, 10);
    simde_uint16x8_t r13 = simde_vrshrn_high_n_u32(r, a, 13);
    simde_uint16x8_t r16 = simde_vrshrn_high_n_u32(r, a, 16);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r16, simde_vld1q_u16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vrshrn_high_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[2];
    uint32_t r[2];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r32[4];
  } test_vec[] = {
    { {  UINT64_C(12634522949072977421),  UINT64_C(15389710757421385289) },
      {  UINT32_C(  2551825828),  UINT32_C(  3348771475)  },
      {  UINT32_C(  2551825828),  UINT32_C(  3348771475),  UINT32_C(  3120041976),  UINT32_C(  2502979609)  },
      {  UINT32_C(  2551825828),  UINT32_C(  3348771475),  UINT32_C(  3178491936),  UINT32_C(  3811205344)  },
      {  UINT32_C(  2551825828),  UINT32_C(  3348771475),  UINT32_C(  3673542592),  UINT32_C(  1737271684)  },
      {  UINT32_C(  2551825828),  UINT32_C(  3348771475),  UINT32_C(  3585469344),  UINT32_C(  1691294035)  },
      {  UINT32_C(  2551825828),  UINT32_C(  3348771475),  UINT32_C(  2941704110),  UINT32_C(  3583196261)  } },
    { {  UINT64_C(17407805632220268990),  UINT64_C(13386670519694084117) },
      {  UINT32_C(   793383030),  UINT32_C(  2436206287)  },
      {  UINT32_C(   793383030),  UINT32_C(  2436206287),  UINT32_C(  4157481511),  UINT32_C(  2783853856)  },
      {  UINT32_C(   793383030),  UINT32_C(  2436206287),  UINT32_C(  2549062724),  UINT32_C(   256629882)  },
      {  UINT32_C(   793383030),  UINT32_C(  2436206287),  UINT32_C(  2657074801),  UINT32_C(  3762106226)  },
      {  UINT32_C(   793383030),  UINT32_C(  2436206287),  UINT32_C(  1698479997),  UINT32_C(  1908439647)  },
      {  UINT32_C(   793383030),  UINT32_C(  2436206287),  UINT32_C(  4053070590),  UINT32_C(  3116827113)  } },
    { {  UINT64_C(16343870392989174902),  UINT64_C(11733149172732130587) },
      {  UINT32_C(  3472215691),  UINT32_C(  1649027258)  },
      {  UINT32_C(  3472215691),  UINT32_C(  1649027258),  UINT32_C(   496276274),  UINT32_C(   132478932)  },
      {  UINT32_C(  3472215691),  UINT32_C(  1649027258),  UINT32_C(  3157993766),  UINT32_C(   672123632)  },
      {  UINT32_C(  3472215691),  UINT32_C(  1649027258),  UINT32_C(   586214565),  UINT32_C(  2426421036)  },
      {  UINT32_C(  3472215691),  UINT32_C(  1649027258),  UINT32_C(  3024478681),  UINT32_C(  3038855294)  },
      {  UINT32_C(  3472215691),  UINT32_C(  1649027258),  UINT32_C(  3805353863),  UINT32_C(  2731836674)  } },
    { {  UINT64_C(15512433260555789026),  UINT64_C(3577193402352101463) },
      {  UINT32_C(   713202166),  UINT32_C(   277356412)  },
      {  UINT32_C(   713202166),  UINT32_C(   277356412),  UINT32_C(  1925547916),  UINT32_C(  3378529697)  },
      {  UINT32_C(   713202166),  UINT32_C(   277356412),  UINT32_C(  3739585295),  UINT32_C(  4086481035)  },
      {  UINT32_C(   713202166),  UINT32_C(   277356412),  UINT32_C(  3883636268),  UINT32_C(  2546879234)  },
      {  UINT32_C(   713202166),  UINT32_C(   277356412),  UINT32_C(  3520001836),  UINT32_C(  1764727958)  },
      {  UINT32_C(   713202166),  UINT32_C(   277356412),  UINT32_C(  3611769821),  UINT32_C(   832880242)  } },
    { {  UINT64_C(15735521981218693814),  UINT64_C(1229963549765769063) },
      {  UINT32_C(  3643688801),  UINT32_C(  1421601170)  },
      {  UINT32_C(  3643688801),  UINT32_C(  1421601170),  UINT32_C(  2088210571),  UINT32_C(  1406787166)  },
      {  UINT32_C(  3643688801),  UINT32_C(  1421601170),  UINT32_C(  1861807905),  UINT32_C(  2863117245)  },
      {  UINT32_C(  3643688801),  UINT32_C(  1421601170),  UINT32_C(  4189840317),  UINT32_C(   917151439)  },
      {  UINT32_C(  3643688801),  UINT32_C(  1421601170),  UINT32_C(  2549315527),  UINT32_C(  1148015934)  },
      {  UINT32_C(  3643688801),  UINT32_C(  1421601170),  UINT32_C(  3663711711),  UINT32_C(   286373205)  } },
    { {  UINT64_C(1235418179107275598),  UINT64_C(288733723891023001) },
      {  UINT32_C(  3555891537),  UINT32_C(  2563891541)  },
      {  UINT32_C(  3555891537),  UINT32_C(  2563891541),  UINT32_C(   659226381),  UINT32_C(   723307762)  },
      {  UINT32_C(  3555891537),  UINT32_C(  2563891541),  UINT32_C(  2991494654),  UINT32_C(  1314273690)  },
      {  UINT32_C(  3555891537),  UINT32_C(  2563891541),  UINT32_C(  2731096664),  UINT32_C(   960059622)  },
      {  UINT32_C(  3555891537),  UINT32_C(  2563891541),  UINT32_C(  1229296245),  UINT32_C(     7500466)  },
      {  UINT32_C(  3555891537),  UINT32_C(  2563891541),  UINT32_C(   287643210),  UINT32_C(    67226059)  } },
    { {  UINT64_C(11340215631633226781),  UINT64_C(16474273799472454905) },
      {  UINT32_C(  4112139742),  UINT32_C(   917585359)  },
      {  UINT32_C(  4112139742),  UINT32_C(   917585359),  UINT32_C(   582963824),  UINT32_C(  4057485940)  },
      {  UINT32_C(  4112139742),  UINT32_C(   917585359),  UINT32_C(  1346731685),  UINT32_C(    98807973)  },
      {  UINT32_C(  4112139742),  UINT32_C(   917585359),  UINT32_C(   289478139),  UINT32_C(   202870467)  },
      {  UINT32_C(  4112139742),  UINT32_C(   917585359),  UINT32_C(  1478656556),  UINT32_C(   672673566)  },
      {  UINT32_C(  4112139742),  UINT32_C(   917585359),  UINT32_C(  2640349705),  UINT32_C(  3835715772)  } },
    { {  UINT64_C(11225533717002403351),  UINT64_C(16173979578999132471) },
      {  UINT32_C(   470831506),  UINT32_C(   534338189)  },
      {  UINT32_C(   470831506),  UINT32_C(   534338189),  UINT32_C(  3267388664),  UINT32_C(  4014647621)  },
      {  UINT32_C(   470831506),  UINT32_C(   534338189),  UINT32_C(  3682959562),  UINT32_C(   635344211)  },
      {  UINT32_C(   470831506),  UINT32_C(   534338189),  UINT32_C(   594417155),  UINT32_C(  2962717269)  },
      {  UINT32_C(   470831506),  UINT32_C(   534338189),  UINT32_C(  4064730156),  UINT32_C(   492908277)  },
      {  UINT32_C(   470831506),  UINT32_C(   534338189),  UINT32_C(  2613648241),  UINT32_C(  3765798076)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x2_t r = simde_vld1_u32(test_vec[i].r);

    simde_uint32x4_t r6 = simde_vrshrn_high_n_u64(r, a, 6);
    simde_uint32x4_t r13 = simde_vrshrn_high_n_u64(r, a, 13);
    simde_uint32x4_t r19 = simde_vrshrn_high_n_u64(r, a, 19);
    simde_uint32x4_t r26 = simde_vrshrn_high_n_u64(r, a, 26);
    simde_uint32x4_t r32 = simde_vrshrn_high_n_u64(r, a, 32);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r32, simde_vld1q_u32(test_vec[i].r32));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrn_high_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrn_high_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrn_high_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrn_high_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrn_high_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrn_high_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
