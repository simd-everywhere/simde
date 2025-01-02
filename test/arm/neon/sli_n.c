#define SIMDE_TEST_ARM_NEON_INSN sli_n

#include <test/arm/neon/test-neon.h>
#include <simde/arm/neon/sli_n.h>

static int
test_simde_vsli_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r0[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r7[8];
  } test_vec[] = {
    { { -INT8_C(  101),  INT8_C(   26),  INT8_C(    9),  INT8_C(   26),  INT8_C(   49), -INT8_C(   61),  INT8_C(  126),  INT8_C(   21)  },
      { -INT8_C(   44), -INT8_C(  122),  INT8_C(   93),  INT8_C(   94),  INT8_C(   54), -INT8_C(   71), -INT8_C(   21),  INT8_C(   56)  },
      { -INT8_C(   44), -INT8_C(  122),  INT8_C(   93),  INT8_C(   94),  INT8_C(   54), -INT8_C(   71), -INT8_C(   21),  INT8_C(   56)  },
      { -INT8_C(   93),  INT8_C(   50), -INT8_C(   23), -INT8_C(   14), -INT8_C(   79), -INT8_C(   53),  INT8_C(   94), -INT8_C(   59)  },
      { -INT8_C(  101), -INT8_C(   38), -INT8_C(   87), -INT8_C(   38), -INT8_C(   47),  INT8_C(   35),  INT8_C(  126),  INT8_C(   21)  },
      {  INT8_C(   27),  INT8_C(   26), -INT8_C(  119),  INT8_C(   26),  INT8_C(   49), -INT8_C(   61), -INT8_C(    2),  INT8_C(   21)  } },
    { { -INT8_C(   52), -INT8_C(   65),  INT8_C(    2),  INT8_C(    9),  INT8_C(  115), -INT8_C(  114),  INT8_C(   25),  INT8_C(   51)  },
      {  INT8_C(   36), -INT8_C(   93),  INT8_C(  125), -INT8_C(   57), -INT8_C(   97),  INT8_C(   56),  INT8_C(    7), -INT8_C(   86)  },
      {  INT8_C(   36), -INT8_C(   93),  INT8_C(  125), -INT8_C(   57), -INT8_C(   97),  INT8_C(   56),  INT8_C(    7), -INT8_C(   86)  },
      {  INT8_C(   36),  INT8_C(   31), -INT8_C(   22),  INT8_C(   57), -INT8_C(    5), -INT8_C(   58),  INT8_C(   57),  INT8_C(   83)  },
      { -INT8_C(  116),       INT8_MAX, -INT8_C(   94), -INT8_C(   23), -INT8_C(   13),  INT8_C(   14), -INT8_C(    7),  INT8_C(   83)  },
      {  INT8_C(   76), -INT8_C(   65), -INT8_C(  126), -INT8_C(  119), -INT8_C(   13),  INT8_C(   14), -INT8_C(  103),  INT8_C(   51)  } },
    { {  INT8_C(    6), -INT8_C(   75), -INT8_C(  113), -INT8_C(  102),  INT8_C(   91),  INT8_C(  107), -INT8_C(   19), -INT8_C(   49)  },
      {  INT8_C(  125),  INT8_C(   24), -INT8_C(  117), -INT8_C(   52),  INT8_C(   56), -INT8_C(   96), -INT8_C(   78), -INT8_C(  125)  },
      {  INT8_C(  125),  INT8_C(   24), -INT8_C(  117), -INT8_C(   52),  INT8_C(   56), -INT8_C(   96), -INT8_C(   78), -INT8_C(  125)  },
      { -INT8_C(   18), -INT8_C(   59),  INT8_C(   95),  INT8_C(   98), -INT8_C(   61),  INT8_C(    3), -INT8_C(  107),  INT8_C(   31)  },
      { -INT8_C(   90),  INT8_C(   21),  INT8_C(  111), -INT8_C(  102),  INT8_C(   27),  INT8_C(   11),  INT8_C(   77),  INT8_C(  111)  },
      { -INT8_C(  122),  INT8_C(   53), -INT8_C(  113),  INT8_C(   26),  INT8_C(   91),  INT8_C(  107),  INT8_C(  109), -INT8_C(   49)  } },
    { {  INT8_C(   75), -INT8_C(   25),  INT8_C(   53),  INT8_C(   41), -INT8_C(   91), -INT8_C(   47),  INT8_C(   11),  INT8_C(  120)  },
      {  INT8_C(   26), -INT8_C(  111), -INT8_C(   51), -INT8_C(   50), -INT8_C(  100),  INT8_C(   21), -INT8_C(  106), -INT8_C(   93)  },
      {  INT8_C(   26), -INT8_C(  111), -INT8_C(   51), -INT8_C(   50), -INT8_C(  100),  INT8_C(   21), -INT8_C(  106), -INT8_C(   93)  },
      { -INT8_C(   45), -INT8_C(  113),  INT8_C(  109),  INT8_C(  113), -INT8_C(   27), -INT8_C(   87), -INT8_C(   77),  INT8_C(   24)  },
      {  INT8_C(   75),  INT8_C(   39), -INT8_C(   75), -INT8_C(   55), -INT8_C(  123), -INT8_C(   79), -INT8_C(   53),  INT8_C(  120)  },
      {  INT8_C(   75), -INT8_C(   25), -INT8_C(   75),  INT8_C(   41),  INT8_C(   37), -INT8_C(   47),  INT8_C(   11), -INT8_C(    8)  } },
    { { -INT8_C(   87), -INT8_C(   95), -INT8_C(    8), -INT8_C(   55), -INT8_C(  109), -INT8_C(   83), -INT8_C(   16), -INT8_C(   60)  },
      {  INT8_C(   67), -INT8_C(  113),  INT8_C(   90), -INT8_C(  126), -INT8_C(   75), -INT8_C(   92),  INT8_C(   62),  INT8_C(  117)  },
      {  INT8_C(   67), -INT8_C(  113),  INT8_C(   90), -INT8_C(  126), -INT8_C(   75), -INT8_C(   92),  INT8_C(   62),  INT8_C(  117)  },
      {  INT8_C(   25),  INT8_C(  121), -INT8_C(   48),  INT8_C(   17), -INT8_C(   85),  INT8_C(   37), -INT8_C(   16), -INT8_C(   84)  },
      {  INT8_C(  105), -INT8_C(   31),  INT8_C(   88),  INT8_C(   73), -INT8_C(   77), -INT8_C(  115), -INT8_C(   48), -INT8_C(   92)  },
      { -INT8_C(   87), -INT8_C(   95),  INT8_C(  120),  INT8_C(   73), -INT8_C(  109),  INT8_C(   45),  INT8_C(  112), -INT8_C(   60)  } },
    { {  INT8_C(  123),  INT8_C(   75), -INT8_C(   20), -INT8_C(   51),  INT8_C(  120),  INT8_C(   69),  INT8_C(   48),  INT8_C(   75)  },
      { -INT8_C(   63), -INT8_C(  101), -INT8_C(  127),  INT8_C(   26), -INT8_C(   50), -INT8_C(   85),  INT8_C(   50), -INT8_C(   88)  },
      { -INT8_C(   63), -INT8_C(  101), -INT8_C(  127),  INT8_C(   26), -INT8_C(   50), -INT8_C(   85),  INT8_C(   50), -INT8_C(   88)  },
      {  INT8_C(   11), -INT8_C(   37),  INT8_C(   12), -INT8_C(   43),  INT8_C(  112),  INT8_C(   93), -INT8_C(  112),  INT8_C(   67)  },
      {  INT8_C(   59),  INT8_C(  107),  INT8_C(   44),  INT8_C(   77), -INT8_C(   40),  INT8_C(  101),  INT8_C(   80),  INT8_C(   11)  },
      { -INT8_C(    5), -INT8_C(   53), -INT8_C(   20),  INT8_C(   77),  INT8_C(  120), -INT8_C(   59),  INT8_C(   48),  INT8_C(   75)  } },
    { { -INT8_C(   23), -INT8_C(   99), -INT8_C(  123), -INT8_C(  103),  INT8_C(   63), -INT8_C(   97), -INT8_C(   22),  INT8_C(  117)  },
      { -INT8_C(   75), -INT8_C(  111),  INT8_C(   98), -INT8_C(   17), -INT8_C(    5),  INT8_C(  109),  INT8_C(   78),  INT8_C(   52)  },
      { -INT8_C(   75), -INT8_C(  111),  INT8_C(   98), -INT8_C(   17), -INT8_C(    5),  INT8_C(  109),  INT8_C(   78),  INT8_C(   52)  },
      { -INT8_C(   87), -INT8_C(  115),  INT8_C(   21),  INT8_C(  121), -INT8_C(   33),  INT8_C(  111),  INT8_C(  114), -INT8_C(   91)  },
      { -INT8_C(   87),  INT8_C(   61),  INT8_C(   69), -INT8_C(    7),       INT8_MAX, -INT8_C(   65), -INT8_C(   54), -INT8_C(  107)  },
      { -INT8_C(   23), -INT8_C(   99),  INT8_C(    5), -INT8_C(  103), -INT8_C(   65), -INT8_C(   97),  INT8_C(  106),  INT8_C(  117)  } },
    { {  INT8_C(   98),  INT8_C(   62),  INT8_C(  126), -INT8_C(   74), -INT8_C(   10),  INT8_C(  124),  INT8_C(   96), -INT8_C(   61)  },
      { -INT8_C(  110),  INT8_C(  111),  INT8_C(   80),  INT8_C(  107),  INT8_C(  102),  INT8_C(    8),  INT8_C(   75), -INT8_C(   51)  },
      { -INT8_C(  110),  INT8_C(  111),  INT8_C(   80),  INT8_C(  107),  INT8_C(  102),  INT8_C(    8),  INT8_C(   75), -INT8_C(   51)  },
      { -INT8_C(  110),  INT8_C(  126), -INT8_C(  122),  INT8_C(   94),  INT8_C(   54),  INT8_C(   68),  INT8_C(   88),  INT8_C(  107)  },
      {  INT8_C(   66), -INT8_C(    2),  INT8_C(   30),  INT8_C(  118), -INT8_C(   42),  INT8_C(   28),  INT8_C(   96), -INT8_C(   93)  },
      {  INT8_C(   98), -INT8_C(   66),  INT8_C(  126), -INT8_C(   74),  INT8_C(  118),  INT8_C(  124), -INT8_C(   32), -INT8_C(   61)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);

    simde_int8x8_t r0 = simde_vsli_n_s8(a, b, 0);
    simde_int8x8_t r3 = simde_vsli_n_s8(a, b, 3);
    simde_int8x8_t r5 = simde_vsli_n_s8(a, b, 5);
    simde_int8x8_t r7 = simde_vsli_n_s8(a, b, 7);

    simde_test_arm_neon_assert_equal_i8x8(r0, simde_vld1_s8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i8x8(r3, simde_vld1_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x8(r5, simde_vld1_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x8(r7, simde_vld1_s8(test_vec[i].r7));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r0 = simde_vsli_n_s8(a, b, 0);
    simde_int8x8_t r3 = simde_vsli_n_s8(a, b, 3);
    simde_int8x8_t r5 = simde_vsli_n_s8(a, b, 5);
    simde_int8x8_t r7 = simde_vsli_n_s8(a, b, 7);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r0[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r15[4];
  } test_vec[] = {
    { {  INT16_C(  2651),  INT16_C( 27627),  INT16_C( 22991),  INT16_C( 30968) },
      {  INT16_C( 25414), -INT16_C( 21444), -INT16_C( 30442),  INT16_C( 30264) },
      {  INT16_C( 25414), -INT16_C( 21444), -INT16_C( 30442),  INT16_C( 30264) },
      {  INT16_C(  6707),  INT16_C( 25059),  INT16_C( 18615), -INT16_C( 20032) },
      { -INT16_C( 11877),  INT16_C(  3883),  INT16_C( 17807), -INT16_C( 29128) },
      {  INT16_C(  6747), -INT16_C(  3093),  INT16_C( 22991), -INT16_C(  7944) },
      { -INT16_C( 13733), -INT16_C( 29717), -INT16_C(  9777),  INT16_C(  6392) },
      {  INT16_C(  2651),  INT16_C( 27627),  INT16_C( 22991),  INT16_C( 30968) } },
    { { -INT16_C(  1399),  INT16_C( 19741), -INT16_C( 31117),  INT16_C( 19132) },
      { -INT16_C(  3798),  INT16_C( 30592),  INT16_C(  4195), -INT16_C( 16885) },
      { -INT16_C(  3798),  INT16_C( 30592),  INT16_C(  4195), -INT16_C( 16885) },
      { -INT16_C( 30383), -INT16_C( 17403), -INT16_C( 31973), -INT16_C(  4004) },
      {  INT16_C( 19081), -INT16_C(  8163),  INT16_C(  6387), -INT16_C( 32004) },
      { -INT16_C( 21879),  INT16_C(   285), -INT16_C( 29069),  INT16_C( 11964) },
      {  INT16_C( 23177),  INT16_C(  3357),  INT16_C( 26227),  INT16_C( 27324) },
      {  INT16_C( 31369),  INT16_C( 19741), -INT16_C( 31117), -INT16_C( 13636) } },
    { { -INT16_C(  2534), -INT16_C(  5846),  INT16_C(  8783), -INT16_C( 27038) },
      { -INT16_C( 24955), -INT16_C( 25790),  INT16_C( 31271), -INT16_C( 20207) },
      { -INT16_C( 24955), -INT16_C( 25790),  INT16_C( 31271), -INT16_C( 20207) },
      { -INT16_C(  3030), -INT16_C(  9710), -INT16_C( 11969), -INT16_C( 30582) },
      { -INT16_C( 24230), -INT16_C( 12118), -INT16_C( 30257),  INT16_C( 17506) },
      {  INT16_C(  5658),  INT16_C(  2346), -INT16_C( 25009),  INT16_C( 18018) },
      { -INT16_C( 18918),  INT16_C( 18730), -INT16_C(  7601),  INT16_C( 13922) },
      { -INT16_C(  2534),  INT16_C( 26922), -INT16_C( 23985), -INT16_C( 27038) } },
    { {  INT16_C( 12148), -INT16_C(  5890), -INT16_C( 17739), -INT16_C(  8398) },
      { -INT16_C( 19796),  INT16_C(  3926),  INT16_C( 25026), -INT16_C(  8754) },
      { -INT16_C( 19796),  INT16_C(  3926),  INT16_C( 25026), -INT16_C(  8754) },
      { -INT16_C( 27292),  INT16_C( 31414),  INT16_C(  3605), -INT16_C(  4494) },
      { -INT16_C( 21708), -INT16_C( 10818),  INT16_C( 28853),  INT16_C( 29618) },
      { -INT16_C( 19596),  INT16_C( 22782),  INT16_C(  2741),  INT16_C( 15154) },
      { -INT16_C( 28812), -INT16_C( 14082),  INT16_C( 23221), -INT16_C(  8398) },
      {  INT16_C( 12148),  INT16_C( 26878),  INT16_C( 15029),  INT16_C( 24370) } },
    { { -INT16_C(  1960), -INT16_C( 22586),  INT16_C( 10266), -INT16_C( 24515) },
      {  INT16_C( 32711), -INT16_C(  4549),  INT16_C( 19961),  INT16_C( 28319) },
      {  INT16_C( 32711), -INT16_C(  4549),  INT16_C( 19961),  INT16_C( 28319) },
      { -INT16_C(   456),  INT16_C( 29150),  INT16_C( 28618),  INT16_C( 29949) },
      { -INT16_C(  3624), -INT16_C( 28986),  INT16_C( 32346), -INT16_C( 22531) },
      {  INT16_C(  7256), -INT16_C(  4154), -INT16_C(  7142),  INT16_C( 31805) },
      { -INT16_C(  1960),  INT16_C( 26566),  INT16_C( 10266), -INT16_C(  8131) },
      { -INT16_C(  1960), -INT16_C( 22586), -INT16_C( 22502), -INT16_C( 24515) } },
    { { -INT16_C( 25220),  INT16_C( 12630), -INT16_C( 30632),  INT16_C(  1040) },
      {  INT16_C( 26170), -INT16_C(   749), -INT16_C(  7736),  INT16_C(  8410) },
      {  INT16_C( 26170), -INT16_C(   749), -INT16_C(  7736),  INT16_C(  8410) },
      {  INT16_C( 12756), -INT16_C(  5986),  INT16_C(  3648),  INT16_C(  1744) },
      { -INT16_C( 28996),  INT16_C( 17622),  INT16_C( 29208),  INT16_C( 13968) },
      { -INT16_C(  5764),  INT16_C( 19798),  INT16_C(  8280),  INT16_C( 26640) },
      {  INT16_C( 23932),  INT16_C( 29014),  INT16_C(  2136),  INT16_C( 17424) },
      {  INT16_C(  7548), -INT16_C( 20138),  INT16_C(  2136),  INT16_C(  1040) } },
    { { -INT16_C( 24359), -INT16_C(  2873),  INT16_C(  1481), -INT16_C( 28524) },
      { -INT16_C( 12412),  INT16_C( 32382),  INT16_C(  7708), -INT16_C( 26388) },
      { -INT16_C( 12412),  INT16_C( 32382),  INT16_C(  7708), -INT16_C( 26388) },
      {  INT16_C( 31777), -INT16_C(  3081), -INT16_C(  3871), -INT16_C( 14492) },
      { -INT16_C(  7911), -INT16_C( 24697), -INT16_C( 30967),  INT16_C( 15124) },
      {  INT16_C(  4313), -INT16_C(  1849),  INT16_C( 29129), -INT16_C( 20332) },
      { -INT16_C( 32551), -INT16_C( 11065), -INT16_C( 31287), -INT16_C( 28524) },
      {  INT16_C(  8409),  INT16_C( 29895),  INT16_C(  1481),  INT16_C(  4244) } },
    { {  INT16_C( 17083),  INT16_C(  5065), -INT16_C(  9782),  INT16_C(  1047) },
      {  INT16_C( 11072),  INT16_C(  2049), -INT16_C(  9460), -INT16_C(  6616) },
      {  INT16_C( 11072),  INT16_C(  2049), -INT16_C(  9460), -INT16_C(  6616) },
      {  INT16_C( 23043),  INT16_C( 16393), -INT16_C( 10142),  INT16_C( 12615) },
      { -INT16_C( 12229),  INT16_C(    73), -INT16_C( 15606), -INT16_C( 30185) },
      {  INT16_C(   699),  INT16_C(  1993),  INT16_C( 12746), -INT16_C( 24553) },
      {  INT16_C(   699),  INT16_C( 13257), -INT16_C( 26166),  INT16_C(  1047) },
      {  INT16_C( 17083), -INT16_C( 27703),  INT16_C( 22986),  INT16_C(  1047) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);

    simde_int16x4_t r0 = simde_vsli_n_s16(a, b, 0);
    simde_int16x4_t r3 = simde_vsli_n_s16(a, b, 3);
    simde_int16x4_t r6 = simde_vsli_n_s16(a, b, 6);
    simde_int16x4_t r10 = simde_vsli_n_s16(a, b, 10);
    simde_int16x4_t r13 = simde_vsli_n_s16(a, b, 13);
    simde_int16x4_t r15 = simde_vsli_n_s16(a, b, 15);

    simde_test_arm_neon_assert_equal_i16x4(r0, simde_vld1_s16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x4(r6, simde_vld1_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x4(r10, simde_vld1_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x4(r13, simde_vld1_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x4(r15, simde_vld1_s16(test_vec[i].r15));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r0 = simde_vsli_n_s16(a, b, 0);
    simde_int16x4_t r3 = simde_vsli_n_s16(a, b, 3);
    simde_int16x4_t r6 = simde_vsli_n_s16(a, b, 6);
    simde_int16x4_t r10 = simde_vsli_n_s16(a, b, 10);
    simde_int16x4_t r13 = simde_vsli_n_s16(a, b, 13);
    simde_int16x4_t r15 = simde_vsli_n_s16(a, b, 15);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r0[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r31[2];
  } test_vec[] = {
    { {  INT32_C(  1909526748), -INT32_C(  2075901045) },
      {  INT32_C(  1329752665),  INT32_C(  1432189339) },
      {  INT32_C(  1329752665),  INT32_C(  1432189339) },
      { -INT32_C(   795175332),  INT32_C(  1465804491) },
      {  INT32_C(  1296773340), -INT32_C(  1355586677) },
      {  INT32_C(  1388908764), -INT32_C(   857980021) },
      {  INT32_C(  1708200156),  INT32_C(  1816413067) },
      { -INT32_C(   237956900), -INT32_C(  2075901045) } },
    { { -INT32_C(  1171938026),  INT32_C(  1703417334) },
      { -INT32_C(  1951100506),  INT32_C(   991307615) },
      { -INT32_C(  1951100506),  INT32_C(   991307615) },
      { -INT32_C(   316380778), -INT32_C(   980822026) },
      { -INT32_C(  1842035434), -INT32_C(   991169034) },
      { -INT32_C(  1925864170),  INT32_C(   989337078) },
      { -INT32_C(  1708808938),  INT32_C(  2106070518) },
      {  INT32_C(   975545622), -INT32_C(   444066314) } },
    { { -INT32_C(  1028790217), -INT32_C(  2075659989) },
      { -INT32_C(   153908901),  INT32_C(   424357891) },
      { -INT32_C(   153908901),  INT32_C(   424357891) },
      { -INT32_C(  1260235017),  INT32_C(  1389101291) },
      {  INT32_C(  1898670135),  INT32_C(  1711305003) },
      {  INT32_C(  1256056887), -INT32_C(  2145390293) },
      {  INT32_C(  1856890935),  INT32_C(   206041387) },
      { -INT32_C(  1028790217), -INT32_C(  2075659989) } },
    { { -INT32_C(   858558250),  INT32_C(   741432453) },
      {  INT32_C(  1287120365),  INT32_C(  1149816077) },
      {  INT32_C(  1287120365),  INT32_C(  1149816077) },
      {  INT32_C(   771324758),  INT32_C(   573784901) },
      { -INT32_C(    54677290),  INT32_C(   430029957) },
      {  INT32_C(   795570390),  INT32_C(  1751735429) },
      { -INT32_C(  1261211434),  INT32_C(   875650181) },
      { -INT32_C(   858558250), -INT32_C(  1406051195) } },
    { { -INT32_C(   519621195), -INT32_C(  2107290074) },
      { -INT32_C(   629655081),  INT32_C(  1072940137) },
      { -INT32_C(   629655081),  INT32_C(  1072940137) },
      { -INT32_C(  1643219467), -INT32_C(    51307930) },
      {  INT32_C(   121304501),  INT32_C(  2022518310) },
      { -INT32_C(   826329675),  INT32_C(   592268838) },
      {  INT32_C(  1560753589), -INT32_C(  1503310298) },
      { -INT32_C(   519621195), -INT32_C(  2107290074) } },
    { { -INT32_C(  1173633228),  INT32_C(   283524387) },
      {  INT32_C(   794598690),  INT32_C(   544531562) },
      {  INT32_C(   794598690),  INT32_C(   544531562) },
      { -INT32_C(   685291340),  INT32_C(   490281635) },
      { -INT32_C(  1817950412), -INT32_C(  1668457181) },
      { -INT32_C(   384579788),  INT32_C(   592854307) },
      { -INT32_C(  1978939596), -INT32_C(  1461306077) },
      {  INT32_C(   973850420),  INT32_C(   283524387) } },
    { {  INT32_C(  1073838873), -INT32_C(  1597872439) },
      {  INT32_C(   159070879),  INT32_C(   860385022) },
      {  INT32_C(   159070879),  INT32_C(   860385022) },
      {  INT32_C(  1590601689), -INT32_C(   769933431) },
      {  INT32_C(  1733557017),  INT32_C(   232769225) },
      { -INT32_C(   721847527),  INT32_C(  2012374729) },
      {  INT32_C(  2080471833), -INT32_C(   121477431) },
      { -INT32_C(  1073644775),  INT32_C(   549611209) } },
    { {  INT32_C(  1491948597), -INT32_C(  1284975727) },
      { -INT32_C(   622606992), -INT32_C(  1007003735) },
      { -INT32_C(   622606992), -INT32_C(  1007003735) },
      { -INT32_C(  1192141771), -INT32_C(    23729583) },
      {  INT32_C(  2024674357),  INT32_C(  1257583505) },
      {  INT32_C(   730158133), -INT32_C(  1119300719) },
      { -INT32_C(  1058188235), -INT32_C(  1486302319) },
      {  INT32_C(  1491948597), -INT32_C(  1284975727) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);

    simde_int32x2_t r0 = simde_vsli_n_s32(a, b, 0);
    simde_int32x2_t r6 = simde_vsli_n_s32(a, b, 6);
    simde_int32x2_t r13 = simde_vsli_n_s32(a, b, 13);
    simde_int32x2_t r19 = simde_vsli_n_s32(a, b, 19);
    simde_int32x2_t r26 = simde_vsli_n_s32(a, b, 26);
    simde_int32x2_t r31 = simde_vsli_n_s32(a, b, 31);

    simde_test_arm_neon_assert_equal_i32x2(r0, simde_vld1_s32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i32x2(r6, simde_vld1_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x2(r13, simde_vld1_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x2(r19, simde_vld1_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x2(r26, simde_vld1_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x2(r31, simde_vld1_s32(test_vec[i].r31));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r0 = simde_vsli_n_s32(a, b, 0);
    simde_int32x2_t r6 = simde_vsli_n_s32(a, b, 6);
    simde_int32x2_t r13 = simde_vsli_n_s32(a, b, 13);
    simde_int32x2_t r19 = simde_vsli_n_s32(a, b, 19);
    simde_int32x2_t r26 = simde_vsli_n_s32(a, b, 26);
    simde_int32x2_t r31 = simde_vsli_n_s32(a, b, 31);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r0[1];
    int64_t r13[1];
    int64_t r26[1];
    int64_t r39[1];
    int64_t r52[1];
    int64_t r63[1];
  } test_vec[] = {
    { {  INT64_C( 6511967064408534046) },
      { -INT64_C( 9043287907392305807) },
      { -INT64_C( 9043287907392305807) },
      { -INT64_C(  490337340209877986) },
      {  INT64_C( 4546717069388622878) },
      {  INT64_C( 2729947231533476894) },
      {  INT64_C( 6277779883785268254) },
      { -INT64_C( 2711404972446241762) } },
    { { -INT64_C( 3478704709806457214) },
      { -INT64_C( 8701403731567860542) },
      { -INT64_C( 8701403731567860542) },
      { -INT64_C( 3680268190206108030) },
      { -INT64_C( 6777197727068324222) },
      {  INT64_C( 5895882061704724098) },
      {  INT64_C( 5487962148288200322) },
      {  INT64_C( 5744667327048318594) } },
    { { -INT64_C(  830361613242049644) },
      {  INT64_C( 1138348084824818875) },
      {  INT64_C( 1138348084824818875) },
      { -INT64_C( 8704990412116886636) },
      {  INT64_C( 3831132899593575316) },
      {  INT64_C( 6729043610996988820) },
      {  INT64_C( 5456663466567162772) },
      { -INT64_C(  830361613242049644) } },
    { {  INT64_C( 4072976403923225911) },
      {  INT64_C( 2644443731753970114) },
      {  INT64_C( 2644443731753970114) },
      {  INT64_C( 6805507993509580087) },
      {  INT64_C( 4660892080227503415) },
      { -INT64_C( 2732311178219598537) },
      { -INT64_C( 7195029863757755081) },
      {  INT64_C( 4072976403923225911) } },
    { { -INT64_C(  448744510357026738) },
      { -INT64_C( 1072402373768150911) },
      { -INT64_C( 1072402373768150911) },
      { -INT64_C( 4470066822945691570) },
      { -INT64_C( 2000427257641613234) },
      { -INT64_C( 6791357049775896498) },
      {  INT64_C(  582579804310816846) },
      { -INT64_C(  448744510357026738) } },
    { {  INT64_C( 7136566732569150300) },
      {  INT64_C(    3167357582098006) },
      {  INT64_C(    3167357582098006) },
      {  INT64_C( 7500249238837314396) },
      { -INT64_C( 4062744971199413412) },
      { -INT64_C( 4080495313106271396) },
      { -INT64_C( 1915668518445546660) },
      {  INT64_C( 7136566732569150300) } },
    { { -INT64_C( 8232132562708770935) },
      {  INT64_C( 8124980900826711063) },
      {  INT64_C( 8124980900826711063) },
      {  INT64_C( 3990921628354801545) },
      {  INT64_C( 5999480869240262537) },
      {  INT64_C( 5621067984187510665) },
      {  INT64_C( 4715716365981405065) },
      { -INT64_C( 8232132562708770935) } },
    { { -INT64_C( 1350432727383250626) },
      { -INT64_C( 7296712028971544309) },
      { -INT64_C( 7296712028971544309) },
      { -INT64_C( 7214142515943741122) },
      {  INT64_C( 5112521554311407934) },
      {  INT64_C( 7667525248635529534) },
      {  INT64_C( 1203108261335820606) },
      { -INT64_C( 1350432727383250626) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);

    simde_int64x1_t r0 = simde_vsli_n_s64(a, b, 0);
    simde_int64x1_t r13 = simde_vsli_n_s64(a, b, 13);
    simde_int64x1_t r26 = simde_vsli_n_s64(a, b, 26);
    simde_int64x1_t r39 = simde_vsli_n_s64(a, b, 39);
    simde_int64x1_t r52 = simde_vsli_n_s64(a, b, 52);
    simde_int64x1_t r63 = simde_vsli_n_s64(a, b, 63);

    simde_test_arm_neon_assert_equal_i64x1(r0, simde_vld1_s64(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i64x1(r13, simde_vld1_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x1(r26, simde_vld1_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x1(r39, simde_vld1_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x1(r52, simde_vld1_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x1(r63, simde_vld1_s64(test_vec[i].r63));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r0 = simde_vsli_n_s64(a, b, 0);
    simde_int64x1_t r13 = simde_vsli_n_s64(a, b, 13);
    simde_int64x1_t r26 = simde_vsli_n_s64(a, b, 26);
    simde_int64x1_t r39 = simde_vsli_n_s64(a, b, 39);
    simde_int64x1_t r52 = simde_vsli_n_s64(a, b, 52);
    simde_int64x1_t r63 = simde_vsli_n_s64(a, b, 63);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r0[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r7[8];
  } test_vec[] = {
    { {  UINT8_C(   194),  UINT8_C(   153),  UINT8_C(   182),  UINT8_C(    53),  UINT8_C(    45),  UINT8_C(   214),  UINT8_C(   136),  UINT8_C(   217)  },
      {  UINT8_C(    51),  UINT8_C(     2),  UINT8_C(    97),  UINT8_C(   189),  UINT8_C(   250),  UINT8_C(    77),  UINT8_C(    65),  UINT8_C(    28)  },
      {  UINT8_C(    51),  UINT8_C(     2),  UINT8_C(    97),  UINT8_C(   189),  UINT8_C(   250),  UINT8_C(    77),  UINT8_C(    65),  UINT8_C(    28)  },
      {  UINT8_C(   154),  UINT8_C(    17),  UINT8_C(    14),  UINT8_C(   237),  UINT8_C(   213),  UINT8_C(   110),  UINT8_C(     8),  UINT8_C(   225)  },
      {  UINT8_C(    98),  UINT8_C(    89),  UINT8_C(    54),  UINT8_C(   181),  UINT8_C(    77),  UINT8_C(   182),  UINT8_C(    40),  UINT8_C(   153)  },
      {  UINT8_C(   194),  UINT8_C(    25),  UINT8_C(   182),  UINT8_C(   181),  UINT8_C(    45),  UINT8_C(   214),  UINT8_C(   136),  UINT8_C(    89)  } },
    { {  UINT8_C(   149),  UINT8_C(   148),  UINT8_C(   192),  UINT8_C(    18),  UINT8_C(   191),  UINT8_C(   120),  UINT8_C(   160),  UINT8_C(   251)  },
      {  UINT8_C(   243),  UINT8_C(   246),  UINT8_C(   159),  UINT8_C(   234),  UINT8_C(    49),  UINT8_C(   191),  UINT8_C(   110),  UINT8_C(   189)  },
      {  UINT8_C(   243),  UINT8_C(   246),  UINT8_C(   159),  UINT8_C(   234),  UINT8_C(    49),  UINT8_C(   191),  UINT8_C(   110),  UINT8_C(   189)  },
      {  UINT8_C(   157),  UINT8_C(   180),  UINT8_C(   248),  UINT8_C(    82),  UINT8_C(   143),  UINT8_C(   248),  UINT8_C(   112),  UINT8_C(   235)  },
      {  UINT8_C(   117),  UINT8_C(   212),  UINT8_C(   224),  UINT8_C(    82),  UINT8_C(    63),  UINT8_C(   248),  UINT8_C(   192),  UINT8_C(   187)  },
      {  UINT8_C(   149),  UINT8_C(    20),  UINT8_C(   192),  UINT8_C(    18),  UINT8_C(   191),  UINT8_C(   248),  UINT8_C(    32),  UINT8_C(   251)  } },
    { {  UINT8_C(    16),  UINT8_C(    99),  UINT8_C(     9),  UINT8_C(   145),  UINT8_C(   219),  UINT8_C(    91),  UINT8_C(   218),  UINT8_C(    77)  },
      {  UINT8_C(   145),  UINT8_C(    92),  UINT8_C(     7),  UINT8_C(    26),  UINT8_C(   192),  UINT8_C(    34),  UINT8_C(     2),  UINT8_C(   133)  },
      {  UINT8_C(   145),  UINT8_C(    92),  UINT8_C(     7),  UINT8_C(    26),  UINT8_C(   192),  UINT8_C(    34),  UINT8_C(     2),  UINT8_C(   133)  },
      {  UINT8_C(   136),  UINT8_C(   227),  UINT8_C(    57),  UINT8_C(   209),  UINT8_C(     3),  UINT8_C(    19),  UINT8_C(    18),  UINT8_C(    45)  },
      {  UINT8_C(    48),  UINT8_C(   131),  UINT8_C(   233),  UINT8_C(    81),  UINT8_C(    27),  UINT8_C(    91),  UINT8_C(    90),  UINT8_C(   173)  },
      {  UINT8_C(   144),  UINT8_C(    99),  UINT8_C(   137),  UINT8_C(    17),  UINT8_C(    91),  UINT8_C(    91),  UINT8_C(    90),  UINT8_C(   205)  } },
    { {  UINT8_C(   102),  UINT8_C(   103),  UINT8_C(     7),  UINT8_C(    20),  UINT8_C(   115),  UINT8_C(   205),  UINT8_C(    70),  UINT8_C(   133)  },
      {  UINT8_C(    41),  UINT8_C(    89),  UINT8_C(   182),  UINT8_C(   231),  UINT8_C(   117),  UINT8_C(    92),  UINT8_C(   234),  UINT8_C(   177)  },
      {  UINT8_C(    41),  UINT8_C(    89),  UINT8_C(   182),  UINT8_C(   231),  UINT8_C(   117),  UINT8_C(    92),  UINT8_C(   234),  UINT8_C(   177)  },
      {  UINT8_C(    78),  UINT8_C(   207),  UINT8_C(   183),  UINT8_C(    60),  UINT8_C(   171),  UINT8_C(   229),  UINT8_C(    86),  UINT8_C(   141)  },
      {  UINT8_C(    38),  UINT8_C(    39),  UINT8_C(   199),  UINT8_C(   244),  UINT8_C(   179),  UINT8_C(   141),  UINT8_C(    70),  UINT8_C(    37)  },
      {  UINT8_C(   230),  UINT8_C(   231),  UINT8_C(     7),  UINT8_C(   148),  UINT8_C(   243),  UINT8_C(    77),  UINT8_C(    70),  UINT8_C(   133)  } },
    { {  UINT8_C(    51),  UINT8_C(    28),  UINT8_C(    95),  UINT8_C(    70),  UINT8_C(    30),  UINT8_C(   241),  UINT8_C(     5),  UINT8_C(   134)  },
      {  UINT8_C(    85),  UINT8_C(   174),  UINT8_C(   194),  UINT8_C(   192),  UINT8_C(   222),  UINT8_C(   190),  UINT8_C(   203),  UINT8_C(    97)  },
      {  UINT8_C(    85),  UINT8_C(   174),  UINT8_C(   194),  UINT8_C(   192),  UINT8_C(   222),  UINT8_C(   190),  UINT8_C(   203),  UINT8_C(    97)  },
      {  UINT8_C(   171),  UINT8_C(   116),  UINT8_C(    23),  UINT8_C(     6),  UINT8_C(   246),  UINT8_C(   241),  UINT8_C(    93),  UINT8_C(    14)  },
      {  UINT8_C(   179),  UINT8_C(   220),  UINT8_C(    95),  UINT8_C(     6),  UINT8_C(   222),  UINT8_C(   209),  UINT8_C(   101),  UINT8_C(    38)  },
      {  UINT8_C(   179),  UINT8_C(    28),  UINT8_C(    95),  UINT8_C(    70),  UINT8_C(    30),  UINT8_C(   113),  UINT8_C(   133),  UINT8_C(   134)  } },
    { {  UINT8_C(   167),  UINT8_C(   158),  UINT8_C(   137),  UINT8_C(    37),  UINT8_C(   155),  UINT8_C(   179),  UINT8_C(   172),  UINT8_C(   255)  },
      {  UINT8_C(    33),  UINT8_C(   236),  UINT8_C(   241),  UINT8_C(   226),  UINT8_C(   155),  UINT8_C(   240),  UINT8_C(    33),  UINT8_C(    64)  },
      {  UINT8_C(    33),  UINT8_C(   236),  UINT8_C(   241),  UINT8_C(   226),  UINT8_C(   155),  UINT8_C(   240),  UINT8_C(    33),  UINT8_C(    64)  },
      {  UINT8_C(    15),  UINT8_C(   102),  UINT8_C(   137),  UINT8_C(    21),  UINT8_C(   219),  UINT8_C(   131),  UINT8_C(    12),  UINT8_C(     7)  },
      {  UINT8_C(    39),  UINT8_C(   158),  UINT8_C(    41),  UINT8_C(    69),  UINT8_C(   123),  UINT8_C(    19),  UINT8_C(    44),  UINT8_C(    31)  },
      {  UINT8_C(   167),  UINT8_C(    30),  UINT8_C(   137),  UINT8_C(    37),  UINT8_C(   155),  UINT8_C(    51),  UINT8_C(   172),  UINT8_C(   127)  } },
    { {  UINT8_C(     5),  UINT8_C(    77),  UINT8_C(    86),  UINT8_C(   188),  UINT8_C(    22),  UINT8_C(   139),  UINT8_C(   165),  UINT8_C(    74)  },
      {  UINT8_C(    27),  UINT8_C(   100),  UINT8_C(    63),  UINT8_C(   133),  UINT8_C(   173),  UINT8_C(   182),  UINT8_C(    69),  UINT8_C(   152)  },
      {  UINT8_C(    27),  UINT8_C(   100),  UINT8_C(    63),  UINT8_C(   133),  UINT8_C(   173),  UINT8_C(   182),  UINT8_C(    69),  UINT8_C(   152)  },
      {  UINT8_C(   221),  UINT8_C(    37),  UINT8_C(   254),  UINT8_C(    44),  UINT8_C(   110),  UINT8_C(   179),  UINT8_C(    45),  UINT8_C(   194)  },
      {  UINT8_C(   101),  UINT8_C(   141),  UINT8_C(   246),  UINT8_C(   188),  UINT8_C(   182),  UINT8_C(   203),  UINT8_C(   165),  UINT8_C(    10)  },
      {  UINT8_C(   133),  UINT8_C(    77),  UINT8_C(   214),  UINT8_C(   188),  UINT8_C(   150),  UINT8_C(    11),  UINT8_C(   165),  UINT8_C(    74)  } },
    { {  UINT8_C(   250),  UINT8_C(   205),  UINT8_C(   140),  UINT8_C(   192),  UINT8_C(    13),  UINT8_C(    95),  UINT8_C(    19),  UINT8_C(    34)  },
      {  UINT8_C(   170),  UINT8_C(    18),  UINT8_C(   194),  UINT8_C(   134),  UINT8_C(   116),  UINT8_C(   119),  UINT8_C(   217),  UINT8_C(     7)  },
      {  UINT8_C(   170),  UINT8_C(    18),  UINT8_C(   194),  UINT8_C(   134),  UINT8_C(   116),  UINT8_C(   119),  UINT8_C(   217),  UINT8_C(     7)  },
      {  UINT8_C(    82),  UINT8_C(   149),  UINT8_C(    20),  UINT8_C(    48),  UINT8_C(   165),  UINT8_C(   191),  UINT8_C(   203),  UINT8_C(    58)  },
      {  UINT8_C(    90),  UINT8_C(    77),  UINT8_C(    76),  UINT8_C(   192),  UINT8_C(   141),        UINT8_MAX,  UINT8_C(    51),  UINT8_C(   226)  },
      {  UINT8_C(   122),  UINT8_C(    77),  UINT8_C(    12),  UINT8_C(    64),  UINT8_C(    13),  UINT8_C(   223),  UINT8_C(   147),  UINT8_C(   162)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);

    simde_uint8x8_t r0 = simde_vsli_n_u8(a, b, 0);
    simde_uint8x8_t r3 = simde_vsli_n_u8(a, b, 3);
    simde_uint8x8_t r5 = simde_vsli_n_u8(a, b, 5);
    simde_uint8x8_t r7 = simde_vsli_n_u8(a, b, 7);

    simde_test_arm_neon_assert_equal_u8x8(r0, simde_vld1_u8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u8x8(r3, simde_vld1_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x8(r5, simde_vld1_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x8(r7, simde_vld1_u8(test_vec[i].r7));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r0 = simde_vsli_n_u8(a, b, 0);
    simde_uint8x8_t r3 = simde_vsli_n_u8(a, b, 3);
    simde_uint8x8_t r5 = simde_vsli_n_u8(a, b, 5);
    simde_uint8x8_t r7 = simde_vsli_n_u8(a, b, 7);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r15[4];
  } test_vec[] = {
    { {  UINT16_C(  15391),  UINT16_C(   8013),  UINT16_C(   1254),  UINT16_C(  45654)  },
      {  UINT16_C(  35066),  UINT16_C(  48548),  UINT16_C(  14346),  UINT16_C(   1393)  },
      {  UINT16_C(  18391),  UINT16_C(  60709),  UINT16_C(  49238),  UINT16_C(  11150)  },
      {  UINT16_C(  16031),  UINT16_C(  26893),  UINT16_C(    678),  UINT16_C(  23638)  },
      {  UINT16_C(  59423),  UINT16_C(  37709),  UINT16_C(  10470),  UINT16_C(  50774)  },
      {  UINT16_C(  23583),  UINT16_C(  40781),  UINT16_C(  17638),  UINT16_C(  12886)  },
      {  UINT16_C(  15391),  UINT16_C(   8013),  UINT16_C(   1254),  UINT16_C(  45654)  } },
    { {  UINT16_C(  23736),  UINT16_C(   7291),  UINT16_C(  61578),  UINT16_C(   8940)  },
      {  UINT16_C(  15242),  UINT16_C(  20311),  UINT16_C(  19232),  UINT16_C(   4411)  },
      {  UINT16_C(  56400),  UINT16_C(  31419),  UINT16_C(  22786),  UINT16_C(  35292)  },
      {  UINT16_C(  58040),  UINT16_C(  54779),  UINT16_C(  51210),  UINT16_C(  20204)  },
      {  UINT16_C(  10424),  UINT16_C(  23675),  UINT16_C(  32906),  UINT16_C(  61164)  },
      {  UINT16_C(  23736),  UINT16_C(  64635),  UINT16_C(   4234),  UINT16_C(  25324)  },
      {  UINT16_C(  23736),  UINT16_C(  40059),  UINT16_C(  28810),  UINT16_C(  41708)  } },
    { {  UINT16_C(  47025),  UINT16_C(  52193),  UINT16_C(  31710),  UINT16_C(  14843)  },
      {  UINT16_C(  54022),  UINT16_C(  30364),  UINT16_C(  65371),  UINT16_C(  28567)  },
      {  UINT16_C(  38961),  UINT16_C(  46305),  UINT16_C(  64222),  UINT16_C(  31931)  },
      {  UINT16_C(  49585),  UINT16_C(  42785),  UINT16_C(  55006),  UINT16_C(  58875)  },
      {  UINT16_C(   7089),  UINT16_C(  29665),  UINT16_C(  28638),  UINT16_C(  24059)  },
      {  UINT16_C(  55217),  UINT16_C(  35809),  UINT16_C(  31710),  UINT16_C(  63995)  },
      {  UINT16_C(  14257),  UINT16_C(  19425),  UINT16_C(  64478),  UINT16_C(  47611)  } },
    { {  UINT16_C(  54568),  UINT16_C(  15862),  UINT16_C(  52509),  UINT16_C(  47425)  },
      {  UINT16_C(   1779),  UINT16_C(  31523),  UINT16_C(  16426),  UINT16_C(  60116)  },
      {  UINT16_C(  14232),  UINT16_C(  55582),  UINT16_C(    341),  UINT16_C(  22177)  },
      {  UINT16_C(  48360),  UINT16_C(  51446),  UINT16_C(   2717),  UINT16_C(  46337)  },
      {  UINT16_C(  52520),  UINT16_C(  36342),  UINT16_C(  43293),  UINT16_C(  20801)  },
      {  UINT16_C(  29992),  UINT16_C(  32246),  UINT16_C(  19741),  UINT16_C(  39233)  },
      {  UINT16_C(  54568),  UINT16_C(  48630),  UINT16_C(  19741),  UINT16_C(  14657)  } },
    { {  UINT16_C(  19021),  UINT16_C(   2955),  UINT16_C(  23434),  UINT16_C(  24652)  },
      {  UINT16_C(  64304),  UINT16_C(  33123),  UINT16_C(  28656),  UINT16_C(   7738)  },
      {  UINT16_C(  55685),  UINT16_C(   2843),  UINT16_C(  32642),  UINT16_C(  61908)  },
      {  UINT16_C(  52237),  UINT16_C(  22731),  UINT16_C(  64522),  UINT16_C(  36492)  },
      {  UINT16_C(  49741),  UINT16_C(  36747),  UINT16_C(  50058),  UINT16_C(  59468)  },
      {  UINT16_C(   2637),  UINT16_C(  27531),  UINT16_C(   7050),  UINT16_C(  16460)  },
      {  UINT16_C(  19021),  UINT16_C(  35723),  UINT16_C(  23434),  UINT16_C(  24652)  } },
    { {  UINT16_C(  35638),  UINT16_C(  64110),  UINT16_C(  55906),  UINT16_C(  20848)  },
      {  UINT16_C(  27670),  UINT16_C(  29508),  UINT16_C(  17746),  UINT16_C(  25076)  },
      {  UINT16_C(  24758),  UINT16_C(  39462),  UINT16_C(  10898),  UINT16_C(   4000)  },
      {  UINT16_C(   1462),  UINT16_C(  53550),  UINT16_C(  21666),  UINT16_C(  32048)  },
      {  UINT16_C(  23350),  UINT16_C(   4718),  UINT16_C(  19042),  UINT16_C(  53616)  },
      {  UINT16_C(  52022),  UINT16_C(  39534),  UINT16_C(  23138),  UINT16_C(  37232)  },
      {  UINT16_C(   2870),  UINT16_C(  31342),  UINT16_C(  23138),  UINT16_C(  20848)  } },
    { {  UINT16_C(  23800),  UINT16_C(  37832),  UINT16_C(  34512),  UINT16_C(  33446)  },
      {  UINT16_C(  19904),  UINT16_C(  51885),  UINT16_C(  10602),  UINT16_C(  42147)  },
      {  UINT16_C(  28160),  UINT16_C(  21864),  UINT16_C(  19280),  UINT16_C(   9502)  },
      {  UINT16_C(  28728),  UINT16_C(  43848),  UINT16_C(  23184),  UINT16_C(  10470)  },
      {  UINT16_C(    248),  UINT16_C(  47048),  UINT16_C(  43728),  UINT16_C(  36518)  },
      {  UINT16_C(   7416),  UINT16_C(  46024),  UINT16_C(  18128),  UINT16_C(  25254)  },
      {  UINT16_C(  23800),  UINT16_C(  37832),  UINT16_C(   1744),  UINT16_C(  33446)  } },
    { {  UINT16_C(  32311),  UINT16_C(  55845),  UINT16_C(  55299),  UINT16_C(  15525)  },
      {  UINT16_C(  16152),  UINT16_C(  36439),  UINT16_C(  64155),  UINT16_C(  41506)  },
      {  UINT16_C(  63687),  UINT16_C(  29373),  UINT16_C(  54491),  UINT16_C(   4373)  },
      {  UINT16_C(  50743),  UINT16_C(  38373),  UINT16_C(  42691),  UINT16_C(  34981)  },
      {  UINT16_C(  25143),  UINT16_C(  24101),  UINT16_C(  27651),  UINT16_C(  34981)  },
      {  UINT16_C(   7735),  UINT16_C(  64037),  UINT16_C(  30723),  UINT16_C(  23717)  },
      {  UINT16_C(  32311),  UINT16_C(  55845),  UINT16_C(  55299),  UINT16_C(  15525)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);

    simde_uint16x4_t r3 = simde_vsli_n_u16(a, b, 3);
    simde_uint16x4_t r6 = simde_vsli_n_u16(a, b, 6);
    simde_uint16x4_t r10 = simde_vsli_n_u16(a, b, 10);
    simde_uint16x4_t r13 = simde_vsli_n_u16(a, b, 13);
    simde_uint16x4_t r15 = simde_vsli_n_u16(a, b, 15);

    simde_test_arm_neon_assert_equal_u16x4(r3, simde_vld1_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x4(r6, simde_vld1_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r15, simde_vld1_u16(test_vec[i].r15));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r3 = simde_vsli_n_u16(a, b, 3);
    simde_uint16x4_t r6 = simde_vsli_n_u16(a, b, 6);
    simde_uint16x4_t r10 = simde_vsli_n_u16(a, b, 10);
    simde_uint16x4_t r13 = simde_vsli_n_u16(a, b, 13);
    simde_uint16x4_t r15 = simde_vsli_n_u16(a, b, 15);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r0[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r31[2];
  } test_vec[] = {
    { { UINT32_C(3817254805), UINT32_C(2538561500) },
      { UINT32_C(2907341763), UINT32_C(  54590683) },
      { UINT32_C(2907341763), UINT32_C(  54590683) },
      { UINT32_C(1386279125), UINT32_C(3493803740) },
      { UINT32_C(1350070165), UINT32_C( 530284508) },
      { UINT32_C( 505327509), UINT32_C(3873398748) },
      { UINT32_C( 260485013), UINT32_C(1867472860) },
      { UINT32_C(3817254805), UINT32_C(2538561500) } },
    { { UINT32_C(2557869169), UINT32_C(2753497045) },
      { UINT32_C(1302346433), UINT32_C(1197991346) },
      { UINT32_C(1302346433), UINT32_C(1197991346) },
      { UINT32_C(1745793137), UINT32_C(3657002133) },
      { UINT32_C( 123223153), UINT32_C(4239804373) },
      { UINT32_C(3591240817), UINT32_C( 764872661) },
      { UINT32_C(  74841201), UINT32_C(3357476821) },
      { UINT32_C(2557869169), UINT32_C( 606013397) } },
    { { UINT32_C(1898638741), UINT32_C( 268990797) },
      { UINT32_C(3619574524), UINT32_C(3218800206) },
      { UINT32_C(3619574524), UINT32_C(3218800206) },
      { UINT32_C(4019502869), UINT32_C(4139750285) },
      { UINT32_C(3395259797), UINT32_C(1607063885) },
      { UINT32_C(2548231573), UINT32_C(4067457357) },
      { UINT32_C(4046122389), UINT32_C( 940079437) },
      { UINT32_C(1898638741), UINT32_C( 268990797) } },
    { { UINT32_C(3478606074), UINT32_C( 426997335) },
      { UINT32_C(1650856880), UINT32_C(2393558521) },
      { UINT32_C(1650856880), UINT32_C(2393558521) },
      { UINT32_C(2575625274), UINT32_C(2863890007) },
      { UINT32_C(3262517498), UINT32_C(1505703511) },
      { UINT32_C(2642891002), UINT32_C(1875605079) },
      { UINT32_C(3277279482), UINT32_C(3849549399) },
      { UINT32_C(1331122426), UINT32_C(2574480983) } },
    { { UINT32_C( 134206650), UINT32_C(1243088718) },
      { UINT32_C(2804078169), UINT32_C(3479633108) },
      { UINT32_C(2804078169), UINT32_C(3479633108) },
      { UINT32_C(3367343738), UINT32_C(3653186830) },
      { UINT32_C(1523266746), UINT32_C(3751446350) },
      { UINT32_C(2999964858), UINT32_C(3869247310) },
      { UINT32_C(1744819386), UINT32_C(1377306446) },
      { UINT32_C(2281690298), UINT32_C(1243088718) } },
    { { UINT32_C(2761866572), UINT32_C(3837596212) },
      { UINT32_C( 507978533), UINT32_C(2863460848) },
      { UINT32_C( 507978533), UINT32_C(2863460848) },
      { UINT32_C(2445855052), UINT32_C(2872867892) },
      { UINT32_C(3831807308), UINT32_C(2654868020) },
      { UINT32_C( 422493516), UINT32_C(2407862836) },
      { UINT32_C(2493431116), UINT32_C(3233616436) },
      { UINT32_C(2761866572), UINT32_C(1690112564) } },
    { { UINT32_C( 330476485), UINT32_C( 190761650) },
      { UINT32_C(1957855392), UINT32_C(3376617596) },
      { UINT32_C(1957855392), UINT32_C(3376617596) },
      { UINT32_C( 748693509), UINT32_C(1355161394) },
      { UINT32_C(1343491013), UINT32_C(1661962930) },
      { UINT32_C(  84061125), UINT32_C(3286682290) },
      { UINT32_C(2209524677), UINT32_C(4083075762) },
      { UINT32_C( 330476485), UINT32_C( 190761650) } },
    { { UINT32_C( 174973654), UINT32_C( 435038964) },
      { UINT32_C(1027093837), UINT32_C(3974620198) },
      { UINT32_C(1027093837), UINT32_C(3974620198) },
      { UINT32_C(1309496150), UINT32_C( 972622260) },
      { UINT32_C( 111780566), UINT32_C(4236561140) },
      { UINT32_C(2859328214), UINT32_C( 557198068) },
      { UINT32_C( 913171158), UINT32_C(2582522612) },
      { UINT32_C(2322457302), UINT32_C( 435038964) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);

    simde_uint32x2_t r0 = simde_vsli_n_u32(a, b, 0);
    simde_uint32x2_t r6 = simde_vsli_n_u32(a, b, 6);
    simde_uint32x2_t r13 = simde_vsli_n_u32(a, b, 13);
    simde_uint32x2_t r19 = simde_vsli_n_u32(a, b, 19);
    simde_uint32x2_t r26 = simde_vsli_n_u32(a, b, 26);
    simde_uint32x2_t r31 = simde_vsli_n_u32(a, b, 31);

    simde_test_arm_neon_assert_equal_u32x2(r0, simde_vld1_u32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u32x2(r6, simde_vld1_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x2(r13, simde_vld1_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x2(r19, simde_vld1_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x2(r26, simde_vld1_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x2(r31, simde_vld1_u32(test_vec[i].r31));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r0 = simde_vsli_n_u32(a, b, 0);
    simde_uint32x2_t r6 = simde_vsli_n_u32(a, b, 6);
    simde_uint32x2_t r13 = simde_vsli_n_u32(a, b, 13);
    simde_uint32x2_t r19 = simde_vsli_n_u32(a, b, 19);
    simde_uint32x2_t r26 = simde_vsli_n_u32(a, b, 26);
    simde_uint32x2_t r31 = simde_vsli_n_u32(a, b, 31);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r0[1];
    uint64_t r13[1];
    uint64_t r26[1];
    uint64_t r39[1];
    uint64_t r52[1];
    uint64_t r63[1];
  } test_vec[] = {
    { { UINT64_C(18343259907600131392) },
      { UINT64_C( 8278853807148295019) },
      { UINT64_C( 8278853807148295019) },
      { UINT64_C(10139173202521056576) },
      { UINT64_C(12865055212136277312) },
      { UINT64_C( 4283404500995908928) },
      { UINT64_C( 3940748299269285184) },
      { UINT64_C(18343259907600131392) } },
    { { UINT64_C( 8095305309804679016) },
      { UINT64_C( 5887261420508919171) },
      { UINT64_C( 5887261420508919171) },
      { UINT64_C( 8656548132297928552) },
      { UINT64_C( 5158080445136359272) },
      { UINT64_C(11951077633891880808) },
      { UINT64_C( 6356915853639667560) },
      { UINT64_C(17318677346659454824) } },
    { { UINT64_C(11680050685844446822) },
      { UINT64_C( 6548842929392553412) },
      { UINT64_C( 6548842929392553412) },
      { UINT64_C( 4989511236421459558) },
      { UINT64_C(14537925497881419366) },
      { UINT64_C( 2505938968937291366) },
      { UINT64_C(15872901938926378598) },
      { UINT64_C( 2456678648989671014) } },
    { { UINT64_C(17344362090335641593) },
      { UINT64_C( 2784501928755068482) },
      { UINT64_C( 2784501928755068482) },
      { UINT64_C(10464125256515215353) },
      { UINT64_C(   94390844327796729) },
      { UINT64_C(16933289877082284025) },
      { UINT64_C(16439138565234171897) },
      { UINT64_C( 8120990053480865785) } },
    { { UINT64_C(11043203236788958311) },
      { UINT64_C(12191221861036164835) },
      { UINT64_C(12191221861036164835) },
      { UINT64_C(18263814618459436135) },
      { UINT64_C(14074916635248948327) },
      { UINT64_C( 9566615195778806887) },
      { UINT64_C( 7940223093530686567) },
      { UINT64_C(11043203236788958311) } },
    { { UINT64_C( 3848500645836055819) },
      { UINT64_C( 3351572881984732829) },
      { UINT64_C( 3351572881984732829) },
      { UINT64_C( 7329867539118531851) },
      { UINT64_C( 2122920534427264267) },
      { UINT64_C(14132100959029650699) },
      { UINT64_C(16850392770054677771) },
      { UINT64_C(13071872682690831627) } },
    { { UINT64_C(18126723625083847201) },
      { UINT64_C(10371227559987812501) },
      { UINT64_C(10371227559987812501) },
      { UINT64_C(13839711987674817057) },
      { UINT64_C( 1231526013239673377) },
      { UINT64_C(16738835935865455137) },
      { UINT64_C( 9898647105877951009) },
      { UINT64_C(18126723625083847201) } },
    { { UINT64_C( 1552738534182869605) },
      { UINT64_C( 7179852996240610733) },
      { UINT64_C( 7179852996240610733) },
      { UINT64_C( 9135638217032579685) },
      { UINT64_C(  707566891237366373) },
      { UINT64_C( 4110333972029364837) },
      { UINT64_C( 6547230520936749669) },
      { UINT64_C(10776110571037645413) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);

    simde_uint64x1_t r0 = simde_vsli_n_u64(a, b, 0);
    simde_uint64x1_t r13 = simde_vsli_n_u64(a, b, 13);
    simde_uint64x1_t r26 = simde_vsli_n_u64(a, b, 26);
    simde_uint64x1_t r39 = simde_vsli_n_u64(a, b, 39);
    simde_uint64x1_t r52 = simde_vsli_n_u64(a, b, 52);
    simde_uint64x1_t r63 = simde_vsli_n_u64(a, b, 63);

    simde_test_arm_neon_assert_equal_u64x1(r0, simde_vld1_u64(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u64x1(r13, simde_vld1_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x1(r26, simde_vld1_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x1(r39, simde_vld1_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x1(r52, simde_vld1_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x1(r63, simde_vld1_u64(test_vec[i].r63));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t r0 = simde_vsli_n_u64(a, b, 0);
    simde_uint64x1_t r13 = simde_vsli_n_u64(a, b, 13);
    simde_uint64x1_t r26 = simde_vsli_n_u64(a, b, 26);
    simde_uint64x1_t r39 = simde_vsli_n_u64(a, b, 39);
    simde_uint64x1_t r52 = simde_vsli_n_u64(a, b, 52);
    simde_uint64x1_t r63 = simde_vsli_n_u64(a, b, 63);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r0[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r7[16];
  } test_vec[] = {
    { {  INT8_C( 107),  INT8_C( 125), -INT8_C(  74),  INT8_C(  13), -INT8_C(  11),  INT8_C(  64),  INT8_C( 106), -INT8_C(  95), -INT8_C(   9), -INT8_C(  95),  INT8_C(  80),  INT8_C(  86),  INT8_C(  70),  INT8_C(  72),  INT8_C(  12),  INT8_C(  60)  },
      {  INT8_C(  59), -INT8_C(   7), -INT8_C( 115), -INT8_C(  18), -INT8_C( 104),  INT8_C( 105),  INT8_C(  23), -INT8_C(  72),  INT8_C(  48),  INT8_C(  16), -INT8_C(  56),  INT8_C(  12),  INT8_C( 111),  INT8_C(  13), -INT8_C( 111),  INT8_C(  21)  },
      {  INT8_C(  59), -INT8_C(   7), -INT8_C( 115), -INT8_C(  18), -INT8_C( 104),  INT8_C( 105),  INT8_C(  23), -INT8_C(  72),  INT8_C(  48),  INT8_C(  16), -INT8_C(  56),  INT8_C(  12),  INT8_C( 111),  INT8_C(  13), -INT8_C( 111),  INT8_C(  21)  },
      { -INT8_C(  37), -INT8_C(  51),  INT8_C( 110),  INT8_C( 117), -INT8_C(  59),  INT8_C(  72), -INT8_C(  70), -INT8_C(  63), -INT8_C( 121), -INT8_C( 127),  INT8_C(  64),  INT8_C( 102),  INT8_C( 126),  INT8_C( 104), -INT8_C( 116), -INT8_C(  84)  },
      {  INT8_C( 107),  INT8_C(  61), -INT8_C(  74), -INT8_C(  51),  INT8_C(  21),  INT8_C(  32), -INT8_C(  22),  INT8_C(   1),  INT8_C(  23),  INT8_C(   1),  INT8_C(  16), -INT8_C( 106), -INT8_C(  26), -INT8_C(  88),  INT8_C(  44), -INT8_C(  68)  },
      { -INT8_C(  21), -INT8_C(   3), -INT8_C(  74),  INT8_C(  13),  INT8_C( 117), -INT8_C(  64), -INT8_C(  22),  INT8_C(  33),  INT8_C( 119),  INT8_C(  33),  INT8_C(  80),  INT8_C(  86), -INT8_C(  58), -INT8_C(  56), -INT8_C( 116), -INT8_C(  68)  } },
    { { -INT8_C(  83),  INT8_C(  48), -INT8_C(  92),  INT8_C(  37), -INT8_C(  62), -INT8_C(  48),  INT8_C( 120), -INT8_C(  43), -INT8_C(  96),  INT8_C( 105),  INT8_C( 127),  INT8_C(  63),  INT8_C( 110),  INT8_C( 120),  INT8_C(  10), -INT8_C(  86)  },
      {  INT8_C(  27), -INT8_C(  20), -INT8_C(  50), -INT8_C(  62),  INT8_C(   1),  INT8_C( 119),  INT8_C(  75), -INT8_C(  28),  INT8_C(  42),  INT8_C(  27),  INT8_C( 107),  INT8_C(   0), -INT8_C( 101),  INT8_C(  64),  INT8_C( 104), -INT8_C(  83)  },
      {  INT8_C(  27), -INT8_C(  20), -INT8_C(  50), -INT8_C(  62),  INT8_C(   1),  INT8_C( 119),  INT8_C(  75), -INT8_C(  28),  INT8_C(  42),  INT8_C(  27),  INT8_C( 107),  INT8_C(   0), -INT8_C( 101),  INT8_C(  64),  INT8_C( 104), -INT8_C(  83)  },
      { -INT8_C(  35),  INT8_C(  96),  INT8_C( 116),  INT8_C(  21),  INT8_C(  10), -INT8_C(  72),  INT8_C(  88),  INT8_C(  37),  INT8_C(  80), -INT8_C(  39),  INT8_C(  95),  INT8_C(   7), -INT8_C(  34),  INT8_C(   0),  INT8_C(  66),  INT8_C( 106)  },
      {  INT8_C( 109), -INT8_C( 112), -INT8_C(  60),  INT8_C(  69),  INT8_C(  34), -INT8_C(  16),  INT8_C( 120), -INT8_C( 107),  INT8_C(  64),  INT8_C( 105),       INT8_MAX,  INT8_C(  31),  INT8_C( 110),  INT8_C(  24),  INT8_C(  10), -INT8_C(  86)  },
      { -INT8_C(  83),  INT8_C(  48),  INT8_C(  36),  INT8_C(  37), -INT8_C(  62), -INT8_C(  48), -INT8_C(   8),  INT8_C(  85),  INT8_C(  32), -INT8_C(  23), -INT8_C(   1),  INT8_C(  63), -INT8_C(  18),  INT8_C( 120),  INT8_C(  10), -INT8_C(  86)  } },
    { { -INT8_C(  19), -INT8_C(  90),  INT8_C(  10), -INT8_C( 113), -INT8_C( 120), -INT8_C(  94),  INT8_C(  87),  INT8_C( 114), -INT8_C(  45), -INT8_C(  75),  INT8_C( 120), -INT8_C(  16),  INT8_C(  46),  INT8_C( 102), -INT8_C( 116), -INT8_C(  68)  },
      {  INT8_C(  92), -INT8_C(  76),  INT8_C(  70), -INT8_C(  37),  INT8_C( 123),  INT8_C(  52), -INT8_C(  87),  INT8_C(  95), -INT8_C(  94),  INT8_C(  15),  INT8_C(   0),  INT8_C(   4),  INT8_C( 101),  INT8_C(  63), -INT8_C(  71), -INT8_C(  97)  },
      {  INT8_C(  92), -INT8_C(  76),  INT8_C(  70), -INT8_C(  37),  INT8_C( 123),  INT8_C(  52), -INT8_C(  87),  INT8_C(  95), -INT8_C(  94),  INT8_C(  15),  INT8_C(   0),  INT8_C(   4),  INT8_C( 101),  INT8_C(  63), -INT8_C(  71), -INT8_C(  97)  },
      { -INT8_C(  27), -INT8_C(  90),  INT8_C(  50), -INT8_C(  33), -INT8_C(  40), -INT8_C(  94),  INT8_C(  79), -INT8_C(   6),  INT8_C(  19),  INT8_C( 125),  INT8_C(   0),  INT8_C(  32),  INT8_C(  46), -INT8_C(   2), -INT8_C(  52), -INT8_C(   4)  },
      { -INT8_C( 115), -INT8_C( 122), -INT8_C(  54),  INT8_C( 111),  INT8_C( 104), -INT8_C( 126),  INT8_C(  55), -INT8_C(  14),  INT8_C(  83), -INT8_C(  11),  INT8_C(  24), -INT8_C( 112), -INT8_C(  82), -INT8_C(  26),  INT8_C(  44), -INT8_C(   4)  },
      {  INT8_C( 109),  INT8_C(  38),  INT8_C(  10), -INT8_C( 113), -INT8_C( 120),  INT8_C(  34), -INT8_C(  41), -INT8_C(  14),  INT8_C(  83), -INT8_C(  75),  INT8_C( 120),  INT8_C( 112), -INT8_C(  82), -INT8_C(  26), -INT8_C( 116), -INT8_C(  68)  } },
    { { -INT8_C(  15),  INT8_C(  19),  INT8_C(  64), -INT8_C( 114),  INT8_C(  42), -INT8_C( 125),  INT8_C(  89), -INT8_C(  12), -INT8_C(   7), -INT8_C(  83),  INT8_C(  70), -INT8_C( 105),  INT8_C(  44), -INT8_C(  31),  INT8_C( 103),  INT8_C(  51)  },
      {  INT8_C(  67),  INT8_C(   4), -INT8_C(  27), -INT8_C(  70),  INT8_C(  87),  INT8_C(  38), -INT8_C(  25), -INT8_C(  12),  INT8_C(  35), -INT8_C(  20),  INT8_C( 122),  INT8_C(  53),  INT8_C(  17),  INT8_C(  11), -INT8_C(  80), -INT8_C(  18)  },
      {  INT8_C(  67),  INT8_C(   4), -INT8_C(  27), -INT8_C(  70),  INT8_C(  87),  INT8_C(  38), -INT8_C(  25), -INT8_C(  12),  INT8_C(  35), -INT8_C(  20),  INT8_C( 122),  INT8_C(  53),  INT8_C(  17),  INT8_C(  11), -INT8_C(  80), -INT8_C(  18)  },
      {  INT8_C(  25),  INT8_C(  35),  INT8_C(  40), -INT8_C(  42), -INT8_C(  70),  INT8_C(  51),  INT8_C(  57), -INT8_C(  92),  INT8_C(  25),  INT8_C( 101), -INT8_C(  42), -INT8_C(  81), -INT8_C( 116),  INT8_C(  89), -INT8_C( 121),  INT8_C( 115)  },
      {  INT8_C( 113), -INT8_C( 109), -INT8_C(  96),  INT8_C(  78), -INT8_C(  22), -INT8_C(  61), -INT8_C(   7), -INT8_C( 108),  INT8_C( 121), -INT8_C( 115),  INT8_C(  70), -INT8_C(  73),  INT8_C(  44),  INT8_C(  97),  INT8_C(   7), -INT8_C(  45)  },
      { -INT8_C(  15),  INT8_C(  19), -INT8_C(  64),  INT8_C(  14), -INT8_C(  86),  INT8_C(   3), -INT8_C(  39),  INT8_C( 116), -INT8_C(   7),  INT8_C(  45),  INT8_C(  70), -INT8_C( 105), -INT8_C(  84), -INT8_C(  31),  INT8_C( 103),  INT8_C(  51)  } },
    { { -INT8_C( 117),  INT8_C(  28),  INT8_C(  31),  INT8_C(  18),  INT8_C(  49),  INT8_C(  30),  INT8_C( 101), -INT8_C(  25), -INT8_C(  21),  INT8_C(  14),  INT8_C(   3), -INT8_C(  42), -INT8_C(   6),  INT8_C( 126), -INT8_C(  36), -INT8_C(  27)  },
      {  INT8_C( 105),  INT8_C(   0), -INT8_C(  61), -INT8_C(  49),  INT8_C(  81),  INT8_C(  27), -INT8_C(  36),  INT8_C(  79),  INT8_C(  94),  INT8_C(  43), -INT8_C(  22),  INT8_C(  34),  INT8_C(  55),  INT8_C(  20), -INT8_C(   6),  INT8_C(  19)  },
      {  INT8_C( 105),  INT8_C(   0), -INT8_C(  61), -INT8_C(  49),  INT8_C(  81),  INT8_C(  27), -INT8_C(  36),  INT8_C(  79),  INT8_C(  94),  INT8_C(  43), -INT8_C(  22),  INT8_C(  34),  INT8_C(  55),  INT8_C(  20), -INT8_C(   6),  INT8_C(  19)  },
      {  INT8_C(  75),  INT8_C(   4),  INT8_C(  31),  INT8_C( 122), -INT8_C( 119), -INT8_C(  34), -INT8_C(  27),       INT8_MAX, -INT8_C(  13),  INT8_C(  94),  INT8_C(  83),  INT8_C(  22), -INT8_C(  70), -INT8_C(  90), -INT8_C(  44), -INT8_C(  99)  },
      {  INT8_C(  43),  INT8_C(  28),       INT8_MAX, -INT8_C(  14),  INT8_C(  49),  INT8_C( 126), -INT8_C( 123), -INT8_C(  25), -INT8_C(  53),  INT8_C( 110),  INT8_C(  67),  INT8_C(  86), -INT8_C(   6), -INT8_C(  98),  INT8_C(  92),  INT8_C( 101)  },
      { -INT8_C( 117),  INT8_C(  28), -INT8_C(  97), -INT8_C( 110), -INT8_C(  79), -INT8_C(  98),  INT8_C( 101), -INT8_C(  25),  INT8_C( 107), -INT8_C( 114),  INT8_C(   3),  INT8_C(  86), -INT8_C(   6),  INT8_C( 126),  INT8_C(  92), -INT8_C(  27)  } },
    { {  INT8_C(  32),  INT8_C(   1), -INT8_C(  82),  INT8_C(   9), -INT8_C(  16),  INT8_C( 104),  INT8_C(  15), -INT8_C( 123), -INT8_C( 124), -INT8_C( 120),  INT8_C(  24),  INT8_C(   2),  INT8_C(  70),  INT8_C( 107), -INT8_C(  20), -INT8_C(  87)  },
      { -INT8_C(  91), -INT8_C(   3),  INT8_C(  66), -INT8_C(  82), -INT8_C(  60), -INT8_C(  88),  INT8_C( 118),  INT8_C(  92),  INT8_C(  44), -INT8_C( 110), -INT8_C(  62),  INT8_C(   8),  INT8_C(  15),  INT8_C(  24),  INT8_C(  15),  INT8_C(  22)  },
      { -INT8_C(  91), -INT8_C(   3),  INT8_C(  66), -INT8_C(  82), -INT8_C(  60), -INT8_C(  88),  INT8_C( 118),  INT8_C(  92),  INT8_C(  44), -INT8_C( 110), -INT8_C(  62),  INT8_C(   8),  INT8_C(  15),  INT8_C(  24),  INT8_C(  15),  INT8_C(  22)  },
      {  INT8_C(  40), -INT8_C(  23),  INT8_C(  22),  INT8_C( 113),  INT8_C(  32),  INT8_C(  64), -INT8_C(  73), -INT8_C(  27),  INT8_C( 100), -INT8_C( 112),  INT8_C(  16),  INT8_C(  66),  INT8_C( 126), -INT8_C(  61),  INT8_C( 124), -INT8_C(  79)  },
      { -INT8_C(  96), -INT8_C(  95),  INT8_C(  78), -INT8_C(  55), -INT8_C( 112),  INT8_C(   8), -INT8_C(  49), -INT8_C( 123), -INT8_C( 124),  INT8_C(  72),  INT8_C(  88),  INT8_C(   2), -INT8_C(  26),  INT8_C(  11), -INT8_C(  20), -INT8_C(  55)  },
      { -INT8_C(  96), -INT8_C( 127),  INT8_C(  46),  INT8_C(   9),  INT8_C( 112),  INT8_C( 104),  INT8_C(  15),  INT8_C(   5),  INT8_C(   4),  INT8_C(   8),  INT8_C(  24),  INT8_C(   2), -INT8_C(  58),  INT8_C( 107), -INT8_C(  20),  INT8_C(  41)  } },
    { {  INT8_C( 116),  INT8_C(  19),  INT8_C(  48),  INT8_C(  76), -INT8_C(  11), -INT8_C(  16),  INT8_C(  66),  INT8_C(  14), -INT8_C(  56), -INT8_C(  32),  INT8_C(  85), -INT8_C(  52),  INT8_C(  90),  INT8_C( 115), -INT8_C(  81), -INT8_C( 128)  },
      {  INT8_C(  38), -INT8_C( 126), -INT8_C(  53),  INT8_C( 117),  INT8_C(  74), -INT8_C(  43),  INT8_C(  93),  INT8_C(  63),  INT8_C(  26),  INT8_C(   0),  INT8_C(  22), -INT8_C(   5), -INT8_C(  88), -INT8_C( 126), -INT8_C(  54), -INT8_C(  25)  },
      {  INT8_C(  38), -INT8_C( 126), -INT8_C(  53),  INT8_C( 117),  INT8_C(  74), -INT8_C(  43),  INT8_C(  93),  INT8_C(  63),  INT8_C(  26),  INT8_C(   0),  INT8_C(  22), -INT8_C(   5), -INT8_C(  88), -INT8_C( 126), -INT8_C(  54), -INT8_C(  25)  },
      {  INT8_C(  52),  INT8_C(  19),  INT8_C(  88), -INT8_C(  84),  INT8_C(  85), -INT8_C(  88), -INT8_C(  22), -INT8_C(   2), -INT8_C(  48),  INT8_C(   0), -INT8_C(  75), -INT8_C(  36),  INT8_C(  66),  INT8_C(  19),  INT8_C(  87),  INT8_C(  56)  },
      { -INT8_C(  44),  INT8_C(  83),  INT8_C( 112), -INT8_C(  84),  INT8_C(  85), -INT8_C(  80), -INT8_C(  94), -INT8_C(  18),  INT8_C(  72),  INT8_C(   0), -INT8_C(  43),  INT8_C( 108),  INT8_C(  26),  INT8_C(  83),  INT8_C(  79), -INT8_C(  32)  },
      {  INT8_C( 116),  INT8_C(  19), -INT8_C(  80), -INT8_C(  52),  INT8_C( 117), -INT8_C(  16), -INT8_C(  62), -INT8_C( 114),  INT8_C(  72),  INT8_C(  96),  INT8_C(  85), -INT8_C(  52),  INT8_C(  90),  INT8_C( 115),  INT8_C(  47),       INT8_MIN  } },
    { { -INT8_C(  22), -INT8_C(  17),  INT8_C(  28),  INT8_C(  50), -INT8_C( 115), -INT8_C(  92),  INT8_C( 125), -INT8_C(  70), -INT8_C(  83), -INT8_C(  95),  INT8_C(  82),  INT8_C( 105), -INT8_C( 105),  INT8_C( 108),  INT8_C(  59), -INT8_C( 115)  },
      { -INT8_C(  23), -INT8_C(  45), -INT8_C(  89), -INT8_C( 112), -INT8_C(  31), -INT8_C(  92),  INT8_C(  60),  INT8_C(  70), -INT8_C(   8),  INT8_C( 108),  INT8_C( 110),  INT8_C(  82),  INT8_C(  62), -INT8_C( 116),  INT8_C(  65), -INT8_C(  36)  },
      { -INT8_C(  23), -INT8_C(  45), -INT8_C(  89), -INT8_C( 112), -INT8_C(  31), -INT8_C(  92),  INT8_C(  60),  INT8_C(  70), -INT8_C(   8),  INT8_C( 108),  INT8_C( 110),  INT8_C(  82),  INT8_C(  62), -INT8_C( 116),  INT8_C(  65), -INT8_C(  36)  },
      {  INT8_C(  74), -INT8_C(  97),  INT8_C(  60), -INT8_C( 126),  INT8_C(  13),  INT8_C(  36), -INT8_C(  27),  INT8_C(  50), -INT8_C(  59),  INT8_C(  97),  INT8_C( 114), -INT8_C( 111), -INT8_C(   9),  INT8_C( 100),  INT8_C(  11), -INT8_C(  27)  },
      {  INT8_C(  42),  INT8_C( 111), -INT8_C(   4),  INT8_C(  18),  INT8_C(  45), -INT8_C( 124), -INT8_C(  99), -INT8_C(  38),  INT8_C(  13), -INT8_C( 127), -INT8_C(  46),  INT8_C(  73), -INT8_C(  41), -INT8_C( 116),  INT8_C(  59), -INT8_C( 115)  },
      { -INT8_C(  22), -INT8_C(  17), -INT8_C( 100),  INT8_C(  50), -INT8_C( 115),  INT8_C(  36),  INT8_C( 125),  INT8_C(  58),  INT8_C(  45),  INT8_C(  33),  INT8_C(  82),  INT8_C( 105),  INT8_C(  23),  INT8_C( 108), -INT8_C(  69),  INT8_C(  13)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);

    simde_int8x16_t r0 = simde_vsliq_n_s8(a, b, 0);
    simde_int8x16_t r3 = simde_vsliq_n_s8(a, b, 3);
    simde_int8x16_t r5 = simde_vsliq_n_s8(a, b, 5);
    simde_int8x16_t r7 = simde_vsliq_n_s8(a, b, 7);

    simde_test_arm_neon_assert_equal_i8x16(r0, simde_vld1q_s8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i8x16(r3, simde_vld1q_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x16(r5, simde_vld1q_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x16(r7, simde_vld1q_s8(test_vec[i].r7));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r0 = simde_vsliq_n_s8(a, b, 0);
    simde_int8x16_t r3 = simde_vsliq_n_s8(a, b, 3);
    simde_int8x16_t r5 = simde_vsliq_n_s8(a, b, 5);
    simde_int8x16_t r7 = simde_vsliq_n_s8(a, b, 7);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r15[8];
  } test_vec[] = {
    { { -INT16_C(  29857),  INT16_C(   2406), -INT16_C(  11751),  INT16_C(  26063), -INT16_C(  23473), -INT16_C(  31823),  INT16_C(  16138), -INT16_C(  20066)  },
      { -INT16_C(   4911),  INT16_C(  31239), -INT16_C(  17957), -INT16_C(  32668), -INT16_C(  25285), -INT16_C(  17755),  INT16_C(  16852), -INT16_C(  29183)  },
      {  INT16_C(  26255), -INT16_C(  12226), -INT16_C(  12583),  INT16_C(    807), -INT16_C(   5665), -INT16_C(  10967),  INT16_C(   3746),  INT16_C(  28686)  },
      {  INT16_C(  13407), -INT16_C(  32282),  INT16_C(  30425),  INT16_C(   6415),  INT16_C(  20175), -INT16_C(  22159),  INT16_C(  29962), -INT16_C(  32674)  },
      {  INT16_C(  18271),  INT16_C(   7526),  INT16_C(  28185), -INT16_C(  28209), -INT16_C(   5041), -INT16_C(  26703),  INT16_C(  21258),  INT16_C(   1438)  },
      {  INT16_C(  11103), -INT16_C(   5786),  INT16_C(  29209), -INT16_C(  31281),  INT16_C(  25679), -INT16_C(  23631), -INT16_C(  24822),  INT16_C(  12702)  },
      { -INT16_C(  29857), -INT16_C(  30362), -INT16_C(  11751),  INT16_C(  26063), -INT16_C(  23473), -INT16_C(  31823),  INT16_C(  16138), -INT16_C(  20066)  } },
    { {  INT16_C(  22305),  INT16_C(   2996), -INT16_C(   8798),  INT16_C(  21771),  INT16_C(  20048), -INT16_C(  17424), -INT16_C(   7311), -INT16_C(  13384)  },
      {  INT16_C(   3899), -INT16_C(  13236),  INT16_C(  23899),  INT16_C(  10311),  INT16_C(    358), -INT16_C(  22886), -INT16_C(   4505), -INT16_C(  13942)  },
      {  INT16_C(  31193),  INT16_C(  25188), -INT16_C(   5414),  INT16_C(  16955),  INT16_C(   2864),  INT16_C(  13520),  INT16_C(  29497),  INT16_C(  19536)  },
      { -INT16_C(  12575),  INT16_C(   4916),  INT16_C(  22242),  INT16_C(   4555),  INT16_C(  22928), -INT16_C(  22864), -INT16_C(  26127),  INT16_C(  25272)  },
      { -INT16_C(   4319),  INT16_C(  13236),  INT16_C(  28066),  INT16_C(   7435), -INT16_C(  26032),  INT16_C(  27632), -INT16_C(  24719),  INT16_C(  11192)  },
      {  INT16_C(  30497), -INT16_C(  29772),  INT16_C(  32162), -INT16_C(   2805), -INT16_C(  12720),  INT16_C(  23536), -INT16_C(   7311),  INT16_C(  19384)  },
      { -INT16_C(  10463),  INT16_C(   2996), -INT16_C(   8798), -INT16_C(  10997),  INT16_C(  20048),  INT16_C(  15344), -INT16_C(   7311),  INT16_C(  19384)  } },
    { { -INT16_C(   1299), -INT16_C(  23418), -INT16_C(  31396),  INT16_C(  14574),  INT16_C(  20335),  INT16_C(  24078), -INT16_C(  16568), -INT16_C(  30262)  },
      { -INT16_C(   9023), -INT16_C(  23614), -INT16_C(  28517), -INT16_C(  32122),  INT16_C(   6327),  INT16_C(  32095), -INT16_C(   8933),  INT16_C(  26767)  },
      { -INT16_C(   6643),  INT16_C(   7702), -INT16_C(  31524),  INT16_C(   5174), -INT16_C(  14913), -INT16_C(   5378), -INT16_C(   5928),  INT16_C(  17530)  },
      {  INT16_C(  12397), -INT16_C(   3962),  INT16_C(   9948), -INT16_C(  24146),  INT16_C(  11759),  INT16_C(  22478),  INT16_C(  18120),  INT16_C(   9162)  },
      {  INT16_C(   1773),  INT16_C(   2182),  INT16_C(  27996),  INT16_C(   6382), -INT16_C(   8337),  INT16_C(  32270),  INT16_C(  28488),  INT16_C(  15818)  },
      {  INT16_C(  15085),  INT16_C(  17542),  INT16_C(  25948), -INT16_C(  10002), -INT16_C(   4241), -INT16_C(    498),  INT16_C(  32584), -INT16_C(   5686)  },
      { -INT16_C(   1299),  INT16_C(   9350), -INT16_C(  31396),  INT16_C(  14574), -INT16_C(  12433), -INT16_C(   8690), -INT16_C(  16568), -INT16_C(  30262)  } },
    { {  INT16_C(   7035), -INT16_C(  28128), -INT16_C(  27633), -INT16_C(   6964),  INT16_C(   3245),  INT16_C(  16127), -INT16_C(  23649),  INT16_C(  10659)  },
      { -INT16_C(   6328),  INT16_C(  13357), -INT16_C(   9860),  INT16_C(   5121),  INT16_C(   2322), -INT16_C(   9202), -INT16_C(   5031),  INT16_C(   2542)  },
      {  INT16_C(  14915), -INT16_C(  24216), -INT16_C(  13337), -INT16_C(  24564),  INT16_C(  18581), -INT16_C(   8073),  INT16_C(  25295),  INT16_C(  20339)  },
      { -INT16_C(  11717),  INT16_C(   2912),  INT16_C(  24335),  INT16_C(     76),  INT16_C(  17581),  INT16_C(    959),  INT16_C(   5727),  INT16_C(  31651)  },
      {  INT16_C(   9083), -INT16_C(  18912), -INT16_C(   4081),  INT16_C(   1228),  INT16_C(  18605),  INT16_C(  15103),  INT16_C(  26527), -INT16_C(  18013)  },
      {  INT16_C(   7035), -INT16_C(  19936), -INT16_C(  27633),  INT16_C(   9420),  INT16_C(  19629), -INT16_C(   8449),  INT16_C(   9119), -INT16_C(  13917)  },
      {  INT16_C(   7035), -INT16_C(  28128),  INT16_C(   5135), -INT16_C(   6964),  INT16_C(   3245),  INT16_C(  16127), -INT16_C(  23649),  INT16_C(  10659)  } },
    { { -INT16_C(  14045),  INT16_C(   6950),  INT16_C(  25104), -INT16_C(  22985), -INT16_C(    559), -INT16_C(  28091),  INT16_C(   4901),  INT16_C(  28381)  },
      { -INT16_C(  25976), -INT16_C(  15056),  INT16_C(  10123),  INT16_C(   5179),  INT16_C(   9318), -INT16_C(  26683), -INT16_C(  29282),  INT16_C(  29906)  },
      { -INT16_C(  11197),  INT16_C(  10630),  INT16_C(  15448), -INT16_C(  24097),  INT16_C(   9009), -INT16_C(  16851),  INT16_C(  27893), -INT16_C(  22891)  },
      { -INT16_C(  24029),  INT16_C(  19494), -INT16_C(   7472),  INT16_C(   3831),  INT16_C(   6545), -INT16_C(   3771),  INT16_C(  26533),  INT16_C(  13469)  },
      {  INT16_C(   8483), -INT16_C(  15578),  INT16_C(  11792), -INT16_C(   4553), -INT16_C(  26159),  INT16_C(   5701),  INT16_C(  31525),  INT16_C(  19165)  },
      {  INT16_C(   2339),  INT16_C(   6950),  INT16_C(  25104),  INT16_C(  26167), -INT16_C(   8751), -INT16_C(  19899), -INT16_C(  11483),  INT16_C(  20189)  },
      {  INT16_C(  18723),  INT16_C(   6950), -INT16_C(   7664), -INT16_C(  22985),  INT16_C(  32209), -INT16_C(  28091),  INT16_C(   4901),  INT16_C(  28381)  } },
    { { -INT16_C(   7004), -INT16_C(   1843), -INT16_C(  19583),  INT16_C(  21568),  INT16_C(  21139),  INT16_C(   8147),  INT16_C(  22889), -INT16_C(   8842)  },
      { -INT16_C(  14802), -INT16_C(  15206),  INT16_C(  30112),  INT16_C(   8024),  INT16_C(  23550),  INT16_C(  30909), -INT16_C(  13817),  INT16_C(  27018)  },
      {  INT16_C(  12660),  INT16_C(   9429), -INT16_C(  21247), -INT16_C(   1344), -INT16_C(   8205), -INT16_C(  14869),  INT16_C(  20537),  INT16_C(  19542)  },
      { -INT16_C(  29788),  INT16_C(   9869),  INT16_C(  26625), -INT16_C(  10752), -INT16_C(    109),  INT16_C(  12115), -INT16_C(  32279),  INT16_C(  25270)  },
      { -INT16_C(  18268),  INT16_C(  26829), -INT16_C(  31871),  INT16_C(  24640), -INT16_C(   1389), -INT16_C(   2093),  INT16_C(   7529),  INT16_C(  10614)  },
      { -INT16_C(  15196),  INT16_C(  22733),  INT16_C(   4993),  INT16_C(   5184), -INT16_C(  11629), -INT16_C(  16429), -INT16_C(   1687),  INT16_C(  23926)  },
      {  INT16_C(  25764),  INT16_C(  30925),  INT16_C(  13185),  INT16_C(  21568),  INT16_C(  21139), -INT16_C(  24621), -INT16_C(   9879),  INT16_C(  23926)  } },
    { {  INT16_C(  17169),  INT16_C(  24072), -INT16_C(  12994), -INT16_C(   8073), -INT16_C(  12777),  INT16_C(   1825), -INT16_C(   5150), -INT16_C(  31600)  },
      { -INT16_C(   7078),  INT16_C(  21725),  INT16_C(  27331), -INT16_C(   7935), -INT16_C(   9434),  INT16_C(  29126),  INT16_C(  21858), -INT16_C(   2211)  },
      {  INT16_C(   8913), -INT16_C(  22808),  INT16_C(  22046),  INT16_C(   2063), -INT16_C(   9929), -INT16_C(  29135), -INT16_C(  21742), -INT16_C(  17688)  },
      {  INT16_C(   5777),  INT16_C(  14152), -INT16_C(  20226),  INT16_C(  16503), -INT16_C(  13929),  INT16_C(  29089),  INT16_C(  22690), -INT16_C(  10416)  },
      {  INT16_C(  27409),  INT16_C(  30216),  INT16_C(   3390),  INT16_C(   1143), -INT16_C(  26089),  INT16_C(   6945), -INT16_C(  29726),  INT16_C(  29840)  },
      {  INT16_C(  17169), -INT16_C(  16888),  INT16_C(  27966),  INT16_C(   8311), -INT16_C(  12777), -INT16_C(  14559),  INT16_C(  19426), -INT16_C(  23408)  },
      {  INT16_C(  17169), -INT16_C(   8696), -INT16_C(  12994), -INT16_C(   8073),  INT16_C(  19991),  INT16_C(   1825),  INT16_C(  27618), -INT16_C(  31600)  } },
    { { -INT16_C(  23136), -INT16_C(  21049),  INT16_C(   4129), -INT16_C(   8019),  INT16_C(  25623),  INT16_C(   9637),  INT16_C(   8632),  INT16_C(  32502)  },
      { -INT16_C(   1800),  INT16_C(  21742),  INT16_C(  13572), -INT16_C(  19366), -INT16_C(   6353),  INT16_C(  26854),  INT16_C(    902),  INT16_C(  24083)  },
      { -INT16_C(  14400), -INT16_C(  22665), -INT16_C(  22495), -INT16_C(  23851),  INT16_C(  14719),  INT16_C(  18229),  INT16_C(   7216), -INT16_C(   3938)  },
      {  INT16_C(  15904),  INT16_C(  15239),  INT16_C(  16673),  INT16_C(   5805), -INT16_C(  13353),  INT16_C(  14757), -INT16_C(   7752), -INT16_C(  31498)  },
      { -INT16_C(   7776), -INT16_C(  17977),  INT16_C(   4129),  INT16_C(  26797), -INT16_C(  17385), -INT16_C(  26203),  INT16_C(   6584),  INT16_C(  20214)  },
      {  INT16_C(   1440), -INT16_C(  12857), -INT16_C(  28639),  INT16_C(  16557), -INT16_C(   7145), -INT16_C(  14939), -INT16_C(  15944),  INT16_C(  32502)  },
      {  INT16_C(   9632),  INT16_C(  11719),  INT16_C(   4129),  INT16_C(  24749), -INT16_C(   7145),  INT16_C(   9637),  INT16_C(   8632), -INT16_C(    266)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);

    simde_int16x8_t r3 = simde_vsliq_n_s16(a, b, 3);
    simde_int16x8_t r6 = simde_vsliq_n_s16(a, b, 6);
    simde_int16x8_t r10 = simde_vsliq_n_s16(a, b, 10);
    simde_int16x8_t r13 = simde_vsliq_n_s16(a, b, 13);
    simde_int16x8_t r15 = simde_vsliq_n_s16(a, b, 15);

    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r10, simde_vld1q_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x8(r13, simde_vld1q_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x8(r15, simde_vld1q_s16(test_vec[i].r15));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r3 = simde_vsliq_n_s16(a, b, 3);
    simde_int16x8_t r6 = simde_vsliq_n_s16(a, b, 6);
    simde_int16x8_t r10 = simde_vsliq_n_s16(a, b, 10);
    simde_int16x8_t r13 = simde_vsliq_n_s16(a, b, 13);
    simde_int16x8_t r15 = simde_vsliq_n_s16(a, b, 15);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r0[4];
    int32_t r6[4];
    int32_t r13[4];
    int32_t r19[4];
    int32_t r26[4];
    int32_t r31[4];
  } test_vec[] = {
    { { -INT32_C(  1784973200), -INT32_C(   455270145),  INT32_C(   857168175), -INT32_C(   247341020) },
      { -INT32_C(  1534615373),  INT32_C(   123345014), -INT32_C(   997515808), -INT32_C(   145904506) },
      { -INT32_C(  1534615373),  INT32_C(   123345014), -INT32_C(   997515808), -INT32_C(   145904506) },
      {  INT32_C(   568863984), -INT32_C(   695853633),  INT32_C(   583497775), -INT32_C(   747953756) },
      { -INT32_C(   199853968),  INT32_C(  1125040383),  INT32_C(  1673271599), -INT32_C(  1248804828) },
      {  INT32_C(    94074992), -INT32_C(  1011539713), -INT32_C(   284731089),  INT32_C(  1680990244) },
      { -INT32_C(   845449104), -INT32_C(   656596737), -INT32_C(  2095621841),  INT32_C(   423747620) },
      { -INT32_C(  1784973200),  INT32_C(  1692213503),  INT32_C(   857168175),  INT32_C(  1900142628) } },
    { {  INT32_C(   596437028),  INT32_C(   940009737), -INT32_C(   412410173), -INT32_C(  1311200002) },
      { -INT32_C(  1034526644),  INT32_C(  1489678456),  INT32_C(  1411143117),  INT32_C(   625699073) },
      { -INT32_C(  1034526644),  INT32_C(  1489678456),  INT32_C(  1411143117),  INT32_C(   625699073) },
      { -INT32_C(  1785195740),  INT32_C(   850140681),  INT32_C(   118846275),  INT32_C(  1390035070) },
      { -INT32_C(   871790556),  INT32_C(  1443825929), -INT32_C(  1967538493),  INT32_C(  1830825214) },
      {  INT32_C(    40167460), -INT32_C(  2084083447), -INT32_C(  1368711485),  INT32_C(  1208528126) },
      {  INT32_C(   864872484), -INT32_C(   536385271),  INT32_C(   929767107),  INT32_C(    98086142) },
      {  INT32_C(   596437028),  INT32_C(   940009737), -INT32_C(   412410173), -INT32_C(  1311200002) } },
    { {  INT32_C(  1514723153),  INT32_C(    76763201),  INT32_C(  1844182638), -INT32_C(   148978517) },
      { -INT32_C(  1665502172), -INT32_C(   218856412), -INT32_C(   632942375), -INT32_C(   889220743) },
      { -INT32_C(  1665502172), -INT32_C(   218856412), -INT32_C(   632942375), -INT32_C(   889220743) },
      {  INT32_C(   782043409), -INT32_C(  1121908479), -INT32_C(  1853606290), -INT32_C(  1075552661) },
      {  INT32_C(  1317312337), -INT32_C(  1870360511), -INT32_C(  1038401938), -INT32_C(   231791445) },
      { -INT32_C(  1591683247),  INT32_C(   555962433), -INT32_C(  2033451410), -INT32_C(  1949383509) },
      { -INT32_C(  1840720047), -INT32_C(  1869393855),  INT32_C(  1709964910), -INT32_C(   417413973) },
      {  INT32_C(  1514723153),  INT32_C(    76763201), -INT32_C(   303301010), -INT32_C(   148978517) } },
    { { -INT32_C(  1457174680),  INT32_C(   112048279),  INT32_C(  1634965942), -INT32_C(  2124836515) },
      {  INT32_C(   706548486),  INT32_C(  1880887703), -INT32_C(  1706401247),  INT32_C(  1550076403) },
      {  INT32_C(   706548486),  INT32_C(  1880887703), -INT32_C(  1706401247),  INT32_C(  1550076403) },
      { -INT32_C(  2025537112),  INT32_C(   117728727), -INT32_C(  1835497354),  INT32_C(   420642013) },
      { -INT32_C(  1570715800), -INT32_C(  2110588777),  INT32_C(  1279539638), -INT32_C(  1992396451) },
      { -INT32_C(  1741338776), -INT32_C(  1933723497),  INT32_C(   285972918),  INT32_C(  1335464285) },
      {  INT32_C(   421873512),  INT32_C(  1588443287), -INT32_C(  2056021578), -INT32_C(   849768099) },
      {  INT32_C(   690308968), -INT32_C(  2035435369), -INT32_C(   512517706), -INT32_C(  2124836515) } },
    { {  INT32_C(   671451536), -INT32_C(   131157183), -INT32_C(  1453743796),  INT32_C(   942322226) },
      {  INT32_C(  1550010309),  INT32_C(  2043445080), -INT32_C(   720169246), -INT32_C(   265193633) },
      {  INT32_C(  1550010309),  INT32_C(  2043445080), -INT32_C(   720169246), -INT32_C(   265193633) },
      {  INT32_C(   416411984),  INT32_C(  1931466241),  INT32_C(  1153808524),  INT32_C(   207476722) },
      {  INT32_C(  1761126800), -INT32_C(  1880419519),  INT32_C(  1658601804),  INT32_C(   787214898) },
      {  INT32_C(  1043171728), -INT32_C(    87641279), -INT32_C(  1223581364), -INT32_C(  1157975502) },
      {  INT32_C(   335907216),  INT32_C(  1613673281), -INT32_C(  1990614708),  INT32_C(  2083172914) },
      { -INT32_C(  1476032112),  INT32_C(  2016326465),  INT32_C(   693739852), -INT32_C(  1205161422) } },
    { {  INT32_C(  1108883201),  INT32_C(   909788906),  INT32_C(   434083047),  INT32_C(   206702918) },
      { -INT32_C(  1469532848),  INT32_C(   371275060), -INT32_C(  1410583477), -INT32_C(  1399120469) },
      { -INT32_C(  1469532848),  INT32_C(   371275060), -INT32_C(  1410583477), -INT32_C(  1399120469) },
      {  INT32_C(   439178241), -INT32_C(  2008199894), -INT32_C(    83029273),  INT32_C(   650603206) },
      {  INT32_C(   380245761),  INT32_C(   648447722), -INT32_C(  2037811993),  INT32_C(  1672833350) },
      { -INT32_C(  1434437887), -INT32_C(  1448982806), -INT32_C(  1570794265), -INT32_C(   312866490) },
      {  INT32_C(  1108883201), -INT32_C(   767932694),  INT32_C(   769627367), -INT32_C(  1403909818) },
      {  INT32_C(  1108883201),  INT32_C(   909788906), -INT32_C(  1713400601), -INT32_C(  1940780730) } },
    { {  INT32_C(  1055896404), -INT32_C(   529257991),  INT32_C(    83448765), -INT32_C(  1408218276) },
      {  INT32_C(   894728192), -INT32_C(   112495187),  INT32_C(  1436825513), -INT32_C(  1459536043) },
      {  INT32_C(   894728192), -INT32_C(   112495187),  INT32_C(  1436825513), -INT32_C(  1459536043) },
      {  INT32_C(  1428029460),  INT32_C(  1390242681),  INT32_C(  1762519677),  INT32_C(  1078973788) },
      { -INT32_C(  1895820460),  INT32_C(  1857399289), -INT32_C(  2030750787),  INT32_C(   669690716) },
      { -INT32_C(  1073237164), -INT32_C(  1385420295), -INT32_C(  1119267907), -INT32_C(    89633956) },
      {  INT32_C(    49263444), -INT32_C(  1267455495), -INT32_C(  1527163971),  INT32_C(  1410354012) },
      {  INT32_C(  1055896404), -INT32_C(   529257991), -INT32_C(  2064034883), -INT32_C(  1408218276) } },
    { { -INT32_C(   337055502), -INT32_C(   674538470),  INT32_C(   215729328),  INT32_C(   280619792) },
      {  INT32_C(   289738084),  INT32_C(   738890115),  INT32_C(   495038152), -INT32_C(   540572691) },
      {  INT32_C(   289738084),  INT32_C(   738890115),  INT32_C(   495038152), -INT32_C(   540572691) },
      {  INT32_C(  1363368242),  INT32_C(    44327130),  INT32_C(  1617670704), -INT32_C(   236913840) },
      { -INT32_C(  1582526222),  INT32_C(  1378909210),  INT32_C(   903414960), -INT32_C(   260199664) },
      {  INT32_C(  1797320946), -INT32_C(  1944364006),  INT32_C(  1984152752),  INT32_C(   527035152) },
      { -INT32_C(  1813450510),  INT32_C(   264985626),  INT32_C(   551273648), -INT32_C(  1262884080) },
      {  INT32_C(  1810428146), -INT32_C(   674538470),  INT32_C(   215729328), -INT32_C(  1866863856) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);

    simde_int32x4_t r0 = simde_vsliq_n_s32(a, b, 0);
    simde_int32x4_t r6 = simde_vsliq_n_s32(a, b, 6);
    simde_int32x4_t r13 = simde_vsliq_n_s32(a, b, 13);
    simde_int32x4_t r19 = simde_vsliq_n_s32(a, b, 19);
    simde_int32x4_t r26 = simde_vsliq_n_s32(a, b, 26);
    simde_int32x4_t r31 = simde_vsliq_n_s32(a, b, 31);

    simde_test_arm_neon_assert_equal_i32x4(r0, simde_vld1q_s32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r19, simde_vld1q_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x4(r26, simde_vld1q_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x4(r31, simde_vld1q_s32(test_vec[i].r31));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r0 = simde_vsliq_n_s32(a, b, 0);
    simde_int32x4_t r6 = simde_vsliq_n_s32(a, b, 6);
    simde_int32x4_t r13 = simde_vsliq_n_s32(a, b, 13);
    simde_int32x4_t r19 = simde_vsliq_n_s32(a, b, 19);
    simde_int32x4_t r26 = simde_vsliq_n_s32(a, b, 26);
    simde_int32x4_t r31 = simde_vsliq_n_s32(a, b, 31);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r0[2];
    int64_t r13[2];
    int64_t r26[2];
    int64_t r39[2];
    int64_t r52[2];
    int64_t r63[2];
  } test_vec[] = {
    { {  INT64_C( 8295995506420482328), -INT64_C( 2360511796702872245) },
      { -INT64_C( 2812947499142811275),  INT64_C( 4063032051912191200) },
      { -INT64_C( 2812947499142811275),  INT64_C( 4063032051912191200) },
      { -INT64_C( 3682564914679996136),  INT64_C( 6432260292639202635) },
      { -INT64_C( 7145220543372984040),  INT64_C( 9175242785830731083) },
      { -INT64_C( 2127745260314558184), -INT64_C( 6893199004186182325) },
      {  INT64_C( 1680207653813223704), -INT64_C( 3599001694229758645) },
      { -INT64_C(  927376530434293480),  INT64_C( 6862860240151903563) } },
    { {  INT64_C( 7436809796956377291), -INT64_C( 2900694867859694632) },
      { -INT64_C( 3847758624821771621),  INT64_C( 8072141193756007087) },
      { -INT64_C( 3847758624821771621),  INT64_C( 8072141193756007087) },
      {  INT64_C( 4646967429670596811), -INT64_C( 4596844999532479528) },
      { -INT64_C( 6122584274991656757), -INT64_C( 7549581728878388264) },
      {  INT64_C(  486755566098239691),  INT64_C( 5759356130399394776) },
      {  INT64_C( 3005267763623809227), -INT64_C( 6125272201056969768) },
      { -INT64_C( 1786562239898398517), -INT64_C( 2900694867859694632) } },
    { {  INT64_C( 8382436526817132754),  INT64_C(  376915241957835009) },
      { -INT64_C(  411690914050258796), -INT64_C( 4876888313748199364) },
      { -INT64_C(  411690914050258796), -INT64_C( 4876888313748199364) },
      {  INT64_C( 3182197589127889106),  INT64_C( 4178597429639610625) },
      {  INT64_C( 3313273984089440466), -INT64_C( 6086857197183844095) },
      {  INT64_C( 7179945189739446482), -INT64_C( 1984928093481746175) },
      { -INT64_C( 8555601671723302702), -INT64_C( 8950039586326462207) },
      {  INT64_C( 8382436526817132754),  INT64_C(  376915241957835009) } },
    { { -INT64_C( 1612289868456950897), -INT64_C( 7408553310546955585) },
      { -INT64_C( 7776203250057349424),  INT64_C( 4390946604609559881) },
      { -INT64_C( 7776203250057349424),  INT64_C( 4390946604609559881) },
      { -INT64_C( 6049737950724750449), -INT64_C(  516358772111101249) },
      {  INT64_C( 6948033720463491983), -INT64_C( 5706668254671539521) },
      { -INT64_C( 8359973486664776817), -INT64_C( 4976859650662206785) },
      {  INT64_C( 7858780147903202191), -INT64_C( 3125630064917613889) },
      {  INT64_C( 7611082168397824911), -INT64_C( 7408553310546955585) } },
    { {  INT64_C( 6132502559755573321), -INT64_C( 4569272421852419848) },
      {  INT64_C( 6309807025108528548),  INT64_C( 1564571839693981134) },
      {  INT64_C( 6309807025108528548),  INT64_C( 1564571839693981134) },
      {  INT64_C( 2162255154902243401), -INT64_C( 3514620455044921096) },
      {  INT64_C( 4319918197997803593),  INT64_C( 3596731332622772472) },
      {  INT64_C( 7914744387926988873),  INT64_C( 4972791411045787896) },
      { -INT64_C( 2717070708027451319),  INT64_C( 6694230246201190648) },
      {  INT64_C( 6132502559755573321),  INT64_C( 4654099615002355960) } },
    { {  INT64_C( 2088934806968016145), -INT64_C( 3495726612667073333) },
      {  INT64_C( 1639693205438683228), -INT64_C( 3007481218249700511) },
      {  INT64_C( 1639693205438683228), -INT64_C( 3007481218249700511) },
      {  INT64_C( 3137053293139434769),  INT64_C( 7563942574414380235) },
      {  INT64_C( 2426082720787930385),  INT64_C( 1204226012160294091) },
      {  INT64_C( 7326281424506920209), -INT64_C( 3988587647619990325) },
      { -INT64_C( 8805272691641213679), -INT64_C( 5324188061379494709) },
      {  INT64_C( 2088934806968016145), -INT64_C( 3495726612667073333) } },
    { { -INT64_C( 5069791020384875931), -INT64_C( 3895066755961864712) },
      {  INT64_C( 8838583758890450249), -INT64_C( 1811595485708273344) },
      {  INT64_C( 8838583758890450249), -INT64_C( 1811595485708273344) },
      {  INT64_C( 2207663520578349669),  INT64_C( 9038760414013824504) },
      {  INT64_C( 7370368342466398821),  INT64_C(  294599731088571896) },
      {  INT64_C( 1864108635882162789), -INT64_C( 3162476452025877000) },
      { -INT64_C( 3128739580988192155), -INT64_C( 7781673234382602760) },
      { -INT64_C( 5069791020384875931),  INT64_C( 5328305280892911096) } },
    { { -INT64_C( 3739091787702183563), -INT64_C( 3745059190122507824) },
      {  INT64_C( 8012192009766713757),  INT64_C( 4154376887750416704) },
      {  INT64_C( 8012192009766713757),  INT64_C( 4154376887750416704) },
      {  INT64_C( 2361529750334454133), -INT64_C( 1587351542709087792) },
      { -INT64_C( 4982818581467211403),  INT64_C( 1370734092381819344) },
      {  INT64_C( 3394815630727076213), -INT64_C( 5013456353680715312) },
      { -INT64_C( 7359985888108062347), -INT64_C( 7780284456246472240) },
      { -INT64_C( 3739091787702183563),  INT64_C( 5478312846732267984) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);

    simde_int64x2_t r0 = simde_vsliq_n_s64(a, b, 0);
    simde_int64x2_t r13 = simde_vsliq_n_s64(a, b, 13);
    simde_int64x2_t r26 = simde_vsliq_n_s64(a, b, 26);
    simde_int64x2_t r39 = simde_vsliq_n_s64(a, b, 39);
    simde_int64x2_t r52 = simde_vsliq_n_s64(a, b, 52);
    simde_int64x2_t r63 = simde_vsliq_n_s64(a, b, 63);

    simde_test_arm_neon_assert_equal_i64x2(r0, simde_vld1q_s64(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i64x2(r13, simde_vld1q_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x2(r26, simde_vld1q_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x2(r39, simde_vld1q_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x2(r52, simde_vld1q_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x2(r63, simde_vld1q_s64(test_vec[i].r63));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r0 = simde_vsliq_n_s64(a, b, 0);
    simde_int64x2_t r13 = simde_vsliq_n_s64(a, b, 13);
    simde_int64x2_t r26 = simde_vsliq_n_s64(a, b, 26);
    simde_int64x2_t r39 = simde_vsliq_n_s64(a, b, 39);
    simde_int64x2_t r52 = simde_vsliq_n_s64(a, b, 52);
    simde_int64x2_t r63 = simde_vsliq_n_s64(a, b, 63);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r0[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r7[16];
  } test_vec[] = {
    { {  UINT8_C(   244),  UINT8_C(    66),  UINT8_C(   116),  UINT8_C(    69),  UINT8_C(   184),  UINT8_C(   184),  UINT8_C(    36),  UINT8_C(   119),  UINT8_C(   145),  UINT8_C(    73),  UINT8_C(    68),  UINT8_C(   242),  UINT8_C(   252),  UINT8_C(   205),  UINT8_C(   128),  UINT8_C(    96)  },
      {  UINT8_C(   152),  UINT8_C(    85),  UINT8_C(   203),  UINT8_C(   155),  UINT8_C(    94),  UINT8_C(    94),  UINT8_C(   115),  UINT8_C(    52),  UINT8_C(   255),  UINT8_C(    54),  UINT8_C(   182),  UINT8_C(   141),  UINT8_C(    92),  UINT8_C(   173),  UINT8_C(   209),  UINT8_C(   117)  },
      {  UINT8_C(   152),  UINT8_C(    85),  UINT8_C(   203),  UINT8_C(   155),  UINT8_C(    94),  UINT8_C(    94),  UINT8_C(   115),  UINT8_C(    52),        UINT8_MAX,  UINT8_C(    54),  UINT8_C(   182),  UINT8_C(   141),  UINT8_C(    92),  UINT8_C(   173),  UINT8_C(   209),  UINT8_C(   117)  },
      {  UINT8_C(   196),  UINT8_C(   170),  UINT8_C(    92),  UINT8_C(   221),  UINT8_C(   240),  UINT8_C(   240),  UINT8_C(   156),  UINT8_C(   167),  UINT8_C(   249),  UINT8_C(   177),  UINT8_C(   180),  UINT8_C(   106),  UINT8_C(   228),  UINT8_C(   109),  UINT8_C(   136),  UINT8_C(   168)  },
      {  UINT8_C(    20),  UINT8_C(   162),  UINT8_C(   116),  UINT8_C(   101),  UINT8_C(   216),  UINT8_C(   216),  UINT8_C(   100),  UINT8_C(   151),  UINT8_C(   241),  UINT8_C(   201),  UINT8_C(   196),  UINT8_C(   178),  UINT8_C(   156),  UINT8_C(   173),  UINT8_C(    32),  UINT8_C(   160)  },
      {  UINT8_C(   116),  UINT8_C(   194),  UINT8_C(   244),  UINT8_C(   197),  UINT8_C(    56),  UINT8_C(    56),  UINT8_C(   164),  UINT8_C(   119),  UINT8_C(   145),  UINT8_C(    73),  UINT8_C(    68),  UINT8_C(   242),  UINT8_C(   124),  UINT8_C(   205),  UINT8_C(   128),  UINT8_C(   224)  } },
    { {  UINT8_C(   196),  UINT8_C(   145),  UINT8_C(   235),  UINT8_C(   187),  UINT8_C(   234),  UINT8_C(    71),  UINT8_C(   208),  UINT8_C(    39),  UINT8_C(   217),  UINT8_C(   216),  UINT8_C(   187),  UINT8_C(   169),  UINT8_C(    88),  UINT8_C(   246),  UINT8_C(   218),  UINT8_C(   150)  },
      {  UINT8_C(   139),  UINT8_C(   183),  UINT8_C(   107),  UINT8_C(   236),  UINT8_C(   111),  UINT8_C(   223),  UINT8_C(   146),  UINT8_C(   125),  UINT8_C(     1),  UINT8_C(   153),  UINT8_C(   203),  UINT8_C(     5),  UINT8_C(   159),  UINT8_C(    47),  UINT8_C(   104),  UINT8_C(   122)  },
      {  UINT8_C(   139),  UINT8_C(   183),  UINT8_C(   107),  UINT8_C(   236),  UINT8_C(   111),  UINT8_C(   223),  UINT8_C(   146),  UINT8_C(   125),  UINT8_C(     1),  UINT8_C(   153),  UINT8_C(   203),  UINT8_C(     5),  UINT8_C(   159),  UINT8_C(    47),  UINT8_C(   104),  UINT8_C(   122)  },
      {  UINT8_C(    92),  UINT8_C(   185),  UINT8_C(    91),  UINT8_C(    99),  UINT8_C(   122),        UINT8_MAX,  UINT8_C(   144),  UINT8_C(   239),  UINT8_C(     9),  UINT8_C(   200),  UINT8_C(    91),  UINT8_C(    41),  UINT8_C(   248),  UINT8_C(   126),  UINT8_C(    66),  UINT8_C(   214)  },
      {  UINT8_C(   100),  UINT8_C(   241),  UINT8_C(   107),  UINT8_C(   155),  UINT8_C(   234),  UINT8_C(   231),  UINT8_C(    80),  UINT8_C(   167),  UINT8_C(    57),  UINT8_C(    56),  UINT8_C(   123),  UINT8_C(   169),  UINT8_C(   248),  UINT8_C(   246),  UINT8_C(    26),  UINT8_C(    86)  },
      {  UINT8_C(   196),  UINT8_C(   145),  UINT8_C(   235),  UINT8_C(    59),  UINT8_C(   234),  UINT8_C(   199),  UINT8_C(    80),  UINT8_C(   167),  UINT8_C(   217),  UINT8_C(   216),  UINT8_C(   187),  UINT8_C(   169),  UINT8_C(   216),  UINT8_C(   246),  UINT8_C(    90),  UINT8_C(    22)  } },
    { {  UINT8_C(    99),  UINT8_C(   213),  UINT8_C(    98),  UINT8_C(   126),  UINT8_C(   100),  UINT8_C(   135),  UINT8_C(   177),  UINT8_C(   214),  UINT8_C(   144),  UINT8_C(    59),  UINT8_C(   153),  UINT8_C(     4),  UINT8_C(    22),  UINT8_C(    60),  UINT8_C(    89),  UINT8_C(    55)  },
      {  UINT8_C(   110),  UINT8_C(    86),  UINT8_C(   122),  UINT8_C(    11),  UINT8_C(    21),  UINT8_C(   130),  UINT8_C(   209),  UINT8_C(    56),  UINT8_C(   211),  UINT8_C(   181),  UINT8_C(     9),  UINT8_C(   238),  UINT8_C(   204),  UINT8_C(    88),  UINT8_C(   131),  UINT8_C(   141)  },
      {  UINT8_C(   110),  UINT8_C(    86),  UINT8_C(   122),  UINT8_C(    11),  UINT8_C(    21),  UINT8_C(   130),  UINT8_C(   209),  UINT8_C(    56),  UINT8_C(   211),  UINT8_C(   181),  UINT8_C(     9),  UINT8_C(   238),  UINT8_C(   204),  UINT8_C(    88),  UINT8_C(   131),  UINT8_C(   141)  },
      {  UINT8_C(   115),  UINT8_C(   181),  UINT8_C(   210),  UINT8_C(    94),  UINT8_C(   172),  UINT8_C(    23),  UINT8_C(   137),  UINT8_C(   198),  UINT8_C(   152),  UINT8_C(   171),  UINT8_C(    73),  UINT8_C(   116),  UINT8_C(   102),  UINT8_C(   196),  UINT8_C(    25),  UINT8_C(   111)  },
      {  UINT8_C(   195),  UINT8_C(   213),  UINT8_C(    66),  UINT8_C(   126),  UINT8_C(   164),  UINT8_C(    71),  UINT8_C(    49),  UINT8_C(    22),  UINT8_C(   112),  UINT8_C(   187),  UINT8_C(    57),  UINT8_C(   196),  UINT8_C(   150),  UINT8_C(    28),  UINT8_C(   121),  UINT8_C(   183)  },
      {  UINT8_C(    99),  UINT8_C(    85),  UINT8_C(    98),  UINT8_C(   254),  UINT8_C(   228),  UINT8_C(     7),  UINT8_C(   177),  UINT8_C(    86),  UINT8_C(   144),  UINT8_C(   187),  UINT8_C(   153),  UINT8_C(     4),  UINT8_C(    22),  UINT8_C(    60),  UINT8_C(   217),  UINT8_C(   183)  } },
    { {  UINT8_C(   180),  UINT8_C(   141),  UINT8_C(   233),  UINT8_C(   117),  UINT8_C(   209),  UINT8_C(    84),  UINT8_C(    61),  UINT8_C(   212),  UINT8_C(   173),  UINT8_C(    50),  UINT8_C(   112),  UINT8_C(    18),  UINT8_C(   188),  UINT8_C(    32),  UINT8_C(   189),  UINT8_C(   127)  },
      {  UINT8_C(   190),  UINT8_C(   224),  UINT8_C(   111),  UINT8_C(   107),  UINT8_C(    92),  UINT8_C(    61),  UINT8_C(   107),  UINT8_C(   194),  UINT8_C(   193),  UINT8_C(    92),  UINT8_C(   169),  UINT8_C(    27),  UINT8_C(   120),  UINT8_C(   102),  UINT8_C(   237),  UINT8_C(   120)  },
      {  UINT8_C(   190),  UINT8_C(   224),  UINT8_C(   111),  UINT8_C(   107),  UINT8_C(    92),  UINT8_C(    61),  UINT8_C(   107),  UINT8_C(   194),  UINT8_C(   193),  UINT8_C(    92),  UINT8_C(   169),  UINT8_C(    27),  UINT8_C(   120),  UINT8_C(   102),  UINT8_C(   237),  UINT8_C(   120)  },
      {  UINT8_C(   244),  UINT8_C(     5),  UINT8_C(   121),  UINT8_C(    93),  UINT8_C(   225),  UINT8_C(   236),  UINT8_C(    93),  UINT8_C(    20),  UINT8_C(    13),  UINT8_C(   226),  UINT8_C(    72),  UINT8_C(   218),  UINT8_C(   196),  UINT8_C(    48),  UINT8_C(   109),  UINT8_C(   199)  },
      {  UINT8_C(   212),  UINT8_C(    13),  UINT8_C(   233),  UINT8_C(   117),  UINT8_C(   145),  UINT8_C(   180),  UINT8_C(   125),  UINT8_C(    84),  UINT8_C(    45),  UINT8_C(   146),  UINT8_C(    48),  UINT8_C(   114),  UINT8_C(    28),  UINT8_C(   192),  UINT8_C(   189),  UINT8_C(    31)  },
      {  UINT8_C(    52),  UINT8_C(    13),  UINT8_C(   233),  UINT8_C(   245),  UINT8_C(    81),  UINT8_C(   212),  UINT8_C(   189),  UINT8_C(    84),  UINT8_C(   173),  UINT8_C(    50),  UINT8_C(   240),  UINT8_C(   146),  UINT8_C(    60),  UINT8_C(    32),  UINT8_C(   189),  UINT8_C(   127)  } },
    { {  UINT8_C(   183),  UINT8_C(    36),  UINT8_C(   213),  UINT8_C(   190),  UINT8_C(    11),  UINT8_C(   205),  UINT8_C(   129),  UINT8_C(    21),  UINT8_C(     4),  UINT8_C(   108),  UINT8_C(   248),  UINT8_C(   225),  UINT8_C(   169),  UINT8_C(    75),  UINT8_C(   175),  UINT8_C(    43)  },
      {  UINT8_C(   141),  UINT8_C(    83),  UINT8_C(    71),  UINT8_C(    14),  UINT8_C(    37),  UINT8_C(    24),  UINT8_C(   233),  UINT8_C(   220),  UINT8_C(    16),  UINT8_C(    80),  UINT8_C(   162),  UINT8_C(    85),  UINT8_C(    75),  UINT8_C(   254),  UINT8_C(   153),  UINT8_C(    29)  },
      {  UINT8_C(   141),  UINT8_C(    83),  UINT8_C(    71),  UINT8_C(    14),  UINT8_C(    37),  UINT8_C(    24),  UINT8_C(   233),  UINT8_C(   220),  UINT8_C(    16),  UINT8_C(    80),  UINT8_C(   162),  UINT8_C(    85),  UINT8_C(    75),  UINT8_C(   254),  UINT8_C(   153),  UINT8_C(    29)  },
      {  UINT8_C(   111),  UINT8_C(   156),  UINT8_C(    61),  UINT8_C(   118),  UINT8_C(    43),  UINT8_C(   197),  UINT8_C(    73),  UINT8_C(   229),  UINT8_C(   132),  UINT8_C(   132),  UINT8_C(    16),  UINT8_C(   169),  UINT8_C(    89),  UINT8_C(   243),  UINT8_C(   207),  UINT8_C(   235)  },
      {  UINT8_C(   183),  UINT8_C(   100),  UINT8_C(   245),  UINT8_C(   222),  UINT8_C(   171),  UINT8_C(    13),  UINT8_C(    33),  UINT8_C(   149),  UINT8_C(     4),  UINT8_C(    12),  UINT8_C(    88),  UINT8_C(   161),  UINT8_C(   105),  UINT8_C(   203),  UINT8_C(    47),  UINT8_C(   171)  },
      {  UINT8_C(   183),  UINT8_C(   164),  UINT8_C(   213),  UINT8_C(    62),  UINT8_C(   139),  UINT8_C(    77),  UINT8_C(   129),  UINT8_C(    21),  UINT8_C(     4),  UINT8_C(   108),  UINT8_C(   120),  UINT8_C(   225),  UINT8_C(   169),  UINT8_C(    75),  UINT8_C(   175),  UINT8_C(   171)  } },
    { {  UINT8_C(   234),  UINT8_C(   182),  UINT8_C(   103),  UINT8_C(   241),  UINT8_C(    11),  UINT8_C(   127),  UINT8_C(   118),  UINT8_C(    55),  UINT8_C(   177),  UINT8_C(   196),  UINT8_C(   189),  UINT8_C(   131),  UINT8_C(   254),  UINT8_C(   151),  UINT8_C(   156),  UINT8_C(    20)  },
      {  UINT8_C(    38),  UINT8_C(    43),  UINT8_C(   107),  UINT8_C(   172),  UINT8_C(   184),  UINT8_C(    43),  UINT8_C(   121),  UINT8_C(   218),  UINT8_C(    74),  UINT8_C(   188),  UINT8_C(     8),  UINT8_C(   190),  UINT8_C(   231),  UINT8_C(   164),  UINT8_C(   142),  UINT8_C(   233)  },
      {  UINT8_C(    38),  UINT8_C(    43),  UINT8_C(   107),  UINT8_C(   172),  UINT8_C(   184),  UINT8_C(    43),  UINT8_C(   121),  UINT8_C(   218),  UINT8_C(    74),  UINT8_C(   188),  UINT8_C(     8),  UINT8_C(   190),  UINT8_C(   231),  UINT8_C(   164),  UINT8_C(   142),  UINT8_C(   233)  },
      {  UINT8_C(    50),  UINT8_C(    94),  UINT8_C(    95),  UINT8_C(    97),  UINT8_C(   195),  UINT8_C(    95),  UINT8_C(   206),  UINT8_C(   215),  UINT8_C(    81),  UINT8_C(   228),  UINT8_C(    69),  UINT8_C(   243),  UINT8_C(    62),  UINT8_C(    39),  UINT8_C(   116),  UINT8_C(    76)  },
      {  UINT8_C(   202),  UINT8_C(   118),  UINT8_C(   103),  UINT8_C(   145),  UINT8_C(    11),  UINT8_C(   127),  UINT8_C(    54),  UINT8_C(    87),  UINT8_C(    81),  UINT8_C(   132),  UINT8_C(    29),  UINT8_C(   195),  UINT8_C(   254),  UINT8_C(   151),  UINT8_C(   220),  UINT8_C(    52)  },
      {  UINT8_C(   106),  UINT8_C(   182),  UINT8_C(   231),  UINT8_C(   113),  UINT8_C(    11),        UINT8_MAX,  UINT8_C(   246),  UINT8_C(    55),  UINT8_C(    49),  UINT8_C(    68),  UINT8_C(    61),  UINT8_C(     3),  UINT8_C(   254),  UINT8_C(    23),  UINT8_C(    28),  UINT8_C(   148)  } },
    { {  UINT8_C(    46),  UINT8_C(   219),  UINT8_C(    53),  UINT8_C(     4),  UINT8_C(   130),  UINT8_C(   212),  UINT8_C(    30),  UINT8_C(    85),  UINT8_C(   206),  UINT8_C(    67),  UINT8_C(    71),  UINT8_C(    68),  UINT8_C(   104),  UINT8_C(   195),  UINT8_C(    15),  UINT8_C(   107)  },
      {  UINT8_C(   125),  UINT8_C(   115),  UINT8_C(   253),  UINT8_C(   164),  UINT8_C(   131),  UINT8_C(    60),  UINT8_C(    54),  UINT8_C(    18),  UINT8_C(   160),  UINT8_C(    87),  UINT8_C(   144),  UINT8_C(    99),  UINT8_C(   146),  UINT8_C(   139),  UINT8_C(   180),  UINT8_C(    90)  },
      {  UINT8_C(   125),  UINT8_C(   115),  UINT8_C(   253),  UINT8_C(   164),  UINT8_C(   131),  UINT8_C(    60),  UINT8_C(    54),  UINT8_C(    18),  UINT8_C(   160),  UINT8_C(    87),  UINT8_C(   144),  UINT8_C(    99),  UINT8_C(   146),  UINT8_C(   139),  UINT8_C(   180),  UINT8_C(    90)  },
      {  UINT8_C(   238),  UINT8_C(   155),  UINT8_C(   237),  UINT8_C(    36),  UINT8_C(    26),  UINT8_C(   228),  UINT8_C(   182),  UINT8_C(   149),  UINT8_C(     6),  UINT8_C(   187),  UINT8_C(   135),  UINT8_C(    28),  UINT8_C(   144),  UINT8_C(    91),  UINT8_C(   167),  UINT8_C(   211)  },
      {  UINT8_C(   174),  UINT8_C(   123),  UINT8_C(   181),  UINT8_C(   132),  UINT8_C(    98),  UINT8_C(   148),  UINT8_C(   222),  UINT8_C(    85),  UINT8_C(    14),  UINT8_C(   227),  UINT8_C(     7),  UINT8_C(   100),  UINT8_C(    72),  UINT8_C(    99),  UINT8_C(   143),  UINT8_C(    75)  },
      {  UINT8_C(   174),  UINT8_C(   219),  UINT8_C(   181),  UINT8_C(     4),  UINT8_C(   130),  UINT8_C(    84),  UINT8_C(    30),  UINT8_C(    85),  UINT8_C(    78),  UINT8_C(   195),  UINT8_C(    71),  UINT8_C(   196),  UINT8_C(   104),  UINT8_C(   195),  UINT8_C(    15),  UINT8_C(   107)  } },
    { {  UINT8_C(   234),  UINT8_C(    41),  UINT8_C(     8),  UINT8_C(   239),  UINT8_C(   215),  UINT8_C(   216),  UINT8_C(   100),  UINT8_C(   174),  UINT8_C(    83),  UINT8_C(   100),  UINT8_C(   240),  UINT8_C(    31),  UINT8_C(    72),  UINT8_C(    42),  UINT8_C(   180),  UINT8_C(    12)  },
      {  UINT8_C(    87),  UINT8_C(   103),  UINT8_C(   201),  UINT8_C(   233),  UINT8_C(    29),  UINT8_C(   172),  UINT8_C(   138),  UINT8_C(    78),  UINT8_C(   179),  UINT8_C(    66),  UINT8_C(   163),  UINT8_C(   203),  UINT8_C(   132),  UINT8_C(    33),  UINT8_C(   173),  UINT8_C(    89)  },
      {  UINT8_C(    87),  UINT8_C(   103),  UINT8_C(   201),  UINT8_C(   233),  UINT8_C(    29),  UINT8_C(   172),  UINT8_C(   138),  UINT8_C(    78),  UINT8_C(   179),  UINT8_C(    66),  UINT8_C(   163),  UINT8_C(   203),  UINT8_C(   132),  UINT8_C(    33),  UINT8_C(   173),  UINT8_C(    89)  },
      {  UINT8_C(   186),  UINT8_C(    57),  UINT8_C(    72),  UINT8_C(    79),  UINT8_C(   239),  UINT8_C(    96),  UINT8_C(    84),  UINT8_C(   118),  UINT8_C(   155),  UINT8_C(    20),  UINT8_C(    24),  UINT8_C(    95),  UINT8_C(    32),  UINT8_C(    10),  UINT8_C(   108),  UINT8_C(   204)  },
      {  UINT8_C(   234),  UINT8_C(   233),  UINT8_C(    40),  UINT8_C(    47),  UINT8_C(   183),  UINT8_C(   152),  UINT8_C(    68),  UINT8_C(   206),  UINT8_C(   115),  UINT8_C(    68),  UINT8_C(   112),  UINT8_C(   127),  UINT8_C(   136),  UINT8_C(    42),  UINT8_C(   180),  UINT8_C(    44)  },
      {  UINT8_C(   234),  UINT8_C(   169),  UINT8_C(   136),  UINT8_C(   239),  UINT8_C(   215),  UINT8_C(    88),  UINT8_C(   100),  UINT8_C(    46),  UINT8_C(   211),  UINT8_C(   100),  UINT8_C(   240),  UINT8_C(   159),  UINT8_C(    72),  UINT8_C(   170),  UINT8_C(   180),  UINT8_C(   140)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);

    simde_uint8x16_t r0 = simde_vsliq_n_u8(a, b, 0);
    simde_uint8x16_t r3 = simde_vsliq_n_u8(a, b, 3);
    simde_uint8x16_t r5 = simde_vsliq_n_u8(a, b, 5);
    simde_uint8x16_t r7 = simde_vsliq_n_u8(a, b, 7);

    simde_test_arm_neon_assert_equal_u8x16(r0, simde_vld1q_u8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r7, simde_vld1q_u8(test_vec[i].r7));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r0 = simde_vsliq_n_u8(a, b, 0);
    simde_uint8x16_t r3 = simde_vsliq_n_u8(a, b, 3);
    simde_uint8x16_t r5 = simde_vsliq_n_u8(a, b, 5);
    simde_uint8x16_t r7 = simde_vsliq_n_u8(a, b, 7);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r15[8];
  } test_vec[] = {
    { {  UINT16_C(  54932),  UINT16_C(   2052),  UINT16_C(  30900),  UINT16_C(   7957),  UINT16_C(  53988),  UINT16_C(  54164),  UINT16_C(  41244),  UINT16_C(  57663)  },
      {  UINT16_C(  22926),  UINT16_C(  51202),  UINT16_C(   3783),  UINT16_C(  62722),  UINT16_C(  47770),  UINT16_C(  44849),  UINT16_C(  38117),  UINT16_C(  19359)  },
      {  UINT16_C(  52340),  UINT16_C(  16404),  UINT16_C(  30268),  UINT16_C(  43029),  UINT16_C(  54484),  UINT16_C(  31116),  UINT16_C(  42796),  UINT16_C(  23807)  },
      {  UINT16_C(  25492),  UINT16_C(    132),  UINT16_C(  45556),  UINT16_C(  16533),  UINT16_C(  42660),  UINT16_C(  52308),  UINT16_C(  14684),  UINT16_C(  59391)  },
      {  UINT16_C(  14996),  UINT16_C(   2052),  UINT16_C(   7348),  UINT16_C(   2837),  UINT16_C(  27364),  UINT16_C(  51092),  UINT16_C(  38172),  UINT16_C(  32063)  },
      {  UINT16_C(  54932),  UINT16_C(  18436),  UINT16_C(  63668),  UINT16_C(  24341),  UINT16_C(  21220),  UINT16_C(  13204),  UINT16_C(  41244),  UINT16_C(  57663)  },
      {  UINT16_C(  22164),  UINT16_C(   2052),  UINT16_C(  63668),  UINT16_C(   7957),  UINT16_C(  21220),  UINT16_C(  54164),  UINT16_C(  41244),  UINT16_C(  57663)  } },
    { {  UINT16_C(  55983),  UINT16_C(   3761),  UINT16_C(  17325),  UINT16_C(   1501),  UINT16_C(  20550),  UINT16_C(  44898),  UINT16_C(   2169),  UINT16_C(  48672)  },
      {  UINT16_C(  59886),  UINT16_C(  11886),  UINT16_C(  50059),  UINT16_C(  39013),  UINT16_C(   4828),  UINT16_C(  28010),  UINT16_C(   2847),  UINT16_C(  15306)  },
      {  UINT16_C(  20343),  UINT16_C(  29553),  UINT16_C(   7261),  UINT16_C(  49965),  UINT16_C(  38630),  UINT16_C(  27474),  UINT16_C(  22777),  UINT16_C(  56912)  },
      {  UINT16_C(  31663),  UINT16_C(  39857),  UINT16_C(  58093),  UINT16_C(   6493),  UINT16_C(  46854),  UINT16_C(  23202),  UINT16_C(  51193),  UINT16_C(  62112)  },
      {  UINT16_C(  47791),  UINT16_C(  47793),  UINT16_C(  12205),  UINT16_C(  38365),  UINT16_C(  28742),  UINT16_C(  43874),  UINT16_C(  31865),  UINT16_C(  10784)  },
      {  UINT16_C(  55983),  UINT16_C(  52913),  UINT16_C(  25517),  UINT16_C(  42461),  UINT16_C(  36934),  UINT16_C(  20322),  UINT16_C(  59513),  UINT16_C(  24096)  },
      {  UINT16_C(  23215),  UINT16_C(   3761),  UINT16_C(  50093),  UINT16_C(  34269),  UINT16_C(  20550),  UINT16_C(  12130),  UINT16_C(  34937),  UINT16_C(  15904)  } },
    { {  UINT16_C(  17536),  UINT16_C(  59891),  UINT16_C(  42463),  UINT16_C(   3164),  UINT16_C(  10034),  UINT16_C(  15752),  UINT16_C(  13926),  UINT16_C(  51179)  },
      {  UINT16_C(  16067),  UINT16_C(  15431),  UINT16_C(  15067),  UINT16_C(  39231),  UINT16_C(  52443),  UINT16_C(  53059),  UINT16_C(  35282),  UINT16_C(   4686)  },
      {  UINT16_C(  63000),  UINT16_C(  57915),  UINT16_C(  55007),  UINT16_C(  51708),  UINT16_C(  26330),  UINT16_C(  31256),  UINT16_C(  20118),  UINT16_C(  37491)  },
      {  UINT16_C(  45248),  UINT16_C(   4595),  UINT16_C(  46815),  UINT16_C(  20444),  UINT16_C(  14066),  UINT16_C(  53448),  UINT16_C(  29862),  UINT16_C(  37803)  },
      {  UINT16_C(   3200),  UINT16_C(   7667),  UINT16_C(  28127),  UINT16_C(  64604),  UINT16_C(  28466),  UINT16_C(   3464),  UINT16_C(  19046),  UINT16_C(  15339)  },
      {  UINT16_C(  25728),  UINT16_C(  59891),  UINT16_C(  26079),  UINT16_C(  60508),  UINT16_C(  26418),  UINT16_C(  32136),  UINT16_C(  22118),  UINT16_C(  51179)  },
      {  UINT16_C(  50304),  UINT16_C(  59891),  UINT16_C(  42463),  UINT16_C(  35932),  UINT16_C(  42802),  UINT16_C(  48520),  UINT16_C(  13926),  UINT16_C(  18411)  } },
    { {  UINT16_C(  55903),  UINT16_C(  22857),  UINT16_C(  39133),  UINT16_C(  33408),  UINT16_C(  16011),  UINT16_C(    990),  UINT16_C(  21485),  UINT16_C(  53727)  },
      {  UINT16_C(  10331),  UINT16_C(   5549),  UINT16_C(  17252),  UINT16_C(  48442),  UINT16_C(   3492),  UINT16_C(  61577),  UINT16_C(  18795),  UINT16_C(  38317)  },
      {  UINT16_C(  17119),  UINT16_C(  44393),  UINT16_C(   6949),  UINT16_C(  59856),  UINT16_C(  27939),  UINT16_C(  33870),  UINT16_C(  19293),  UINT16_C(  44399)  },
      {  UINT16_C(   5855),  UINT16_C(  27465),  UINT16_C(  55581),  UINT16_C(  20096),  UINT16_C(  26891),  UINT16_C(   8798),  UINT16_C(  23277),  UINT16_C(  27487)  },
      {  UINT16_C(  28255),  UINT16_C(  46409),  UINT16_C(  37085),  UINT16_C(  60032),  UINT16_C(  37515),  UINT16_C(  10206),  UINT16_C(  45037),  UINT16_C(  46559)  },
      {  UINT16_C(  31327),  UINT16_C(  47433),  UINT16_C(  39133),  UINT16_C(  17024),  UINT16_C(  40587),  UINT16_C(   9182),  UINT16_C(  29677),  UINT16_C(  45535)  },
      {  UINT16_C(  55903),  UINT16_C(  55625),  UINT16_C(   6365),  UINT16_C(    640),  UINT16_C(  16011),  UINT16_C(  33758),  UINT16_C(  54253),  UINT16_C(  53727)  } },
    { {  UINT16_C(  30910),  UINT16_C(  36057),  UINT16_C(  28028),  UINT16_C(  65285),  UINT16_C(  30944),  UINT16_C(  29925),  UINT16_C(  64087),  UINT16_C(  51797)  },
      {  UINT16_C(  21033),  UINT16_C(  43881),  UINT16_C(  63534),  UINT16_C(  35658),  UINT16_C(  41153),  UINT16_C(  27208),  UINT16_C(  27863),  UINT16_C(  40336)  },
      {  UINT16_C(  37198),  UINT16_C(  23369),  UINT16_C(  49524),  UINT16_C(  23125),  UINT16_C(   1544),  UINT16_C(  21061),  UINT16_C(  26303),  UINT16_C(  60549)  },
      {  UINT16_C(  35454),  UINT16_C(  55897),  UINT16_C(   3004),  UINT16_C(  53893),  UINT16_C(  12384),  UINT16_C(  37413),  UINT16_C(  13783),  UINT16_C(  25621)  },
      {  UINT16_C(  42174),  UINT16_C(  42201),  UINT16_C(  47484),  UINT16_C(  11013),  UINT16_C(   1248),  UINT16_C(   8421),  UINT16_C(  24151),  UINT16_C(  16981)  },
      {  UINT16_C(  14526),  UINT16_C(  11481),  UINT16_C(  52604),  UINT16_C(  24325),  UINT16_C(  14560),  UINT16_C(   5349),  UINT16_C(  64087),  UINT16_C(   2645)  },
      {  UINT16_C(  63678),  UINT16_C(  36057),  UINT16_C(  28028),  UINT16_C(  32517),  UINT16_C(  63712),  UINT16_C(  29925),  UINT16_C(  64087),  UINT16_C(  19029)  } },
    { {  UINT16_C(   2698),  UINT16_C(  52795),  UINT16_C(  47428),  UINT16_C(  57027),  UINT16_C(  39964),  UINT16_C(  36120),  UINT16_C(  60475),  UINT16_C(  45338)  },
      {  UINT16_C(  21185),  UINT16_C(   2661),  UINT16_C(  53801),  UINT16_C(  24352),  UINT16_C(  21787),  UINT16_C(  30325),  UINT16_C(  60200),  UINT16_C(  19373)  },
      {  UINT16_C(  38410),  UINT16_C(  21291),  UINT16_C(  37196),  UINT16_C(  63747),  UINT16_C(  43228),  UINT16_C(  45992),  UINT16_C(  22851),  UINT16_C(  23914)  },
      {  UINT16_C(  45130),  UINT16_C(  39291),  UINT16_C(  35396),  UINT16_C(  51203),  UINT16_C(  18140),  UINT16_C(  40280),  UINT16_C(  51771),  UINT16_C(  60250)  },
      {  UINT16_C(   1674),  UINT16_C(  38459),  UINT16_C(  42308),  UINT16_C(  33475),  UINT16_C(  27676),  UINT16_C(  54552),  UINT16_C(  41019),  UINT16_C(  46362)  },
      {  UINT16_C(  10890),  UINT16_C(  44603),  UINT16_C(  14660),  UINT16_C(   7875),  UINT16_C(  31772),  UINT16_C(  44312),  UINT16_C(   3131),  UINT16_C(  45338)  },
      {  UINT16_C(  35466),  UINT16_C(  52795),  UINT16_C(  47428),  UINT16_C(  24259),  UINT16_C(  39964),  UINT16_C(  36120),  UINT16_C(  27707),  UINT16_C(  45338)  } },
    { {  UINT16_C(  20622),  UINT16_C(  35405),  UINT16_C(  42684),  UINT16_C(  64877),  UINT16_C(  29368),  UINT16_C(  10266),  UINT16_C(  24647),  UINT16_C(  64280)  },
      {  UINT16_C(  31576),  UINT16_C(  19446),  UINT16_C(  44288),  UINT16_C(  56822),  UINT16_C(  32174),  UINT16_C(  17103),  UINT16_C(  18667),  UINT16_C(  20678)  },
      {  UINT16_C(  56006),  UINT16_C(  24501),  UINT16_C(  26628),  UINT16_C(  61365),  UINT16_C(  60784),  UINT16_C(   5754),  UINT16_C(  18271),  UINT16_C(  34352)  },
      {  UINT16_C(  54798),  UINT16_C(  64909),  UINT16_C(  16444),  UINT16_C(  32173),  UINT16_C(  27576),  UINT16_C(  46042),  UINT16_C(  15047),  UINT16_C(  12696)  },
      {  UINT16_C(  24718),  UINT16_C(  55885),  UINT16_C(    700),  UINT16_C(  55661),  UINT16_C(  47800),  UINT16_C(  15386),  UINT16_C(  44103),  UINT16_C(   6936)  },
      {  UINT16_C(   4238),  UINT16_C(  51789),  UINT16_C(   1724),  UINT16_C(  56685),  UINT16_C(  53944),  UINT16_C(  59418),  UINT16_C(  24647),  UINT16_C(  56088)  },
      {  UINT16_C(  20622),  UINT16_C(   2637),  UINT16_C(   9916),  UINT16_C(  32109),  UINT16_C(  29368),  UINT16_C(  43034),  UINT16_C(  57415),  UINT16_C(  31512)  } },
    { {  UINT16_C(  47232),  UINT16_C(    355),  UINT16_C(  64050),  UINT16_C(  59843),  UINT16_C(   9532),  UINT16_C(  42900),  UINT16_C(  36704),  UINT16_C(  46935)  },
      {  UINT16_C(  18854),  UINT16_C(  61891),  UINT16_C(  57306),  UINT16_C(  15820),  UINT16_C(  62408),  UINT16_C(  25140),  UINT16_C(   4068),  UINT16_C(  24825)  },
      {  UINT16_C(  19760),  UINT16_C(  36379),  UINT16_C(  65234),  UINT16_C(  61027),  UINT16_C(  40516),  UINT16_C(   4516),  UINT16_C(  32544),  UINT16_C(   1999)  },
      {  UINT16_C(  27008),  UINT16_C(  28899),  UINT16_C(  63154),  UINT16_C(  29443),  UINT16_C(  62012),  UINT16_C(  36116),  UINT16_C(  63776),  UINT16_C(  15959)  },
      {  UINT16_C(  39040),  UINT16_C(   3427),  UINT16_C(  27186),  UINT16_C(  12739),  UINT16_C(   8508),  UINT16_C(  54164),  UINT16_C(  37728),  UINT16_C(  59223)  },
      {  UINT16_C(  55424),  UINT16_C(  24931),  UINT16_C(  23090),  UINT16_C(  35267),  UINT16_C(   1340),  UINT16_C(  34708),  UINT16_C(  36704),  UINT16_C(  14167)  },
      {  UINT16_C(  14464),  UINT16_C(  33123),  UINT16_C(  31282),  UINT16_C(  27075),  UINT16_C(   9532),  UINT16_C(  10132),  UINT16_C(   3936),  UINT16_C(  46935)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);

    simde_uint16x8_t r3 = simde_vsliq_n_u16(a, b, 3);
    simde_uint16x8_t r6 = simde_vsliq_n_u16(a, b, 6);
    simde_uint16x8_t r10 = simde_vsliq_n_u16(a, b, 10);
    simde_uint16x8_t r13 = simde_vsliq_n_u16(a, b, 13);
    simde_uint16x8_t r15 = simde_vsliq_n_u16(a, b, 15);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r15, simde_vld1q_u16(test_vec[i].r15));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r3 = simde_vsliq_n_u16(a, b, 3);
    simde_uint16x8_t r6 = simde_vsliq_n_u16(a, b, 6);
    simde_uint16x8_t r10 = simde_vsliq_n_u16(a, b, 10);
    simde_uint16x8_t r13 = simde_vsliq_n_u16(a, b, 13);
    simde_uint16x8_t r15 = simde_vsliq_n_u16(a, b, 15);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r31[4];
  } test_vec[] = {
    { {  UINT32_C(3314104844),  UINT32_C( 896066203),  UINT32_C(1274783480),  UINT32_C(1259865211)  },
      {  UINT32_C(2546938802),  UINT32_C(2309454007),  UINT32_C(3677554301),  UINT32_C(1529066540)  },
      {  UINT32_C(4090293388),  UINT32_C(1776168411),  UINT32_C(3435241336),  UINT32_C(3370978107)  },
      {  UINT32_C(3866515980),  UINT32_C(4011254427),  UINT32_C(1624221432),  UINT32_C(1988461691)  },
      {  UINT32_C(2643540492),  UINT32_C(3317228187),  UINT32_C( 871081720),  UINT32_C(2707424379)  },
      {  UINT32_C(3381213708),  UINT32_C(3714638491),  UINT32_C(4160464632),  UINT32_C(3004695675)  },
      {  UINT32_C(1166621196),  UINT32_C(3043549851),  UINT32_C(3422267128),  UINT32_C(1259865211)  } },
    { {  UINT32_C(2519560084),  UINT32_C(4091206232),  UINT32_C(1216423209),  UINT32_C(2044064088)  },
      {  UINT32_C(3403746096),  UINT32_C( 188361982),  UINT32_C(1027264752),  UINT32_C( 342173962)  },
      {  UINT32_C(3091385364),  UINT32_C(3465232280),  UINT32_C(1320434729),  UINT32_C( 424297112)  },
      {  UINT32_C( 560336788),  UINT32_C(1168104024),  UINT32_C(1511916841),  UINT32_C(2770424152)  },
      {  UINT32_C(1501917076),  UINT32_C(1743968856),  UINT32_C(2273387817),  UINT32_C(1213591896)  },
      {  UINT32_C(3257757588),  UINT32_C(4225423960),  UINT32_C(3229689129),  UINT32_C( 701886808)  },
      {  UINT32_C( 372076436),  UINT32_C(1943722584),  UINT32_C(1216423209),  UINT32_C(2044064088)  } },
    { {  UINT32_C( 442898144),  UINT32_C(4213751943),  UINT32_C(3937589646),  UINT32_C(1647003042)  },
      {  UINT32_C(1900144466),  UINT32_C(2941186414),  UINT32_C( 465710967),  UINT32_C(3138196476)  },
      {  UINT32_C(1350161568),  UINT32_C(3552336775),  UINT32_C(4035698126),  UINT32_C(3276078882)  },
      {  UINT32_C(1021990624),  UINT32_C(3727540359),  UINT32_C(1173289358),  UINT32_C(2726266274)  },
      {  UINT32_C( 982914784),  UINT32_C(2339422343),  UINT32_C(2075842958),  UINT32_C(2682471842)  },
      {  UINT32_C(1248204512),  UINT32_C(3140010119),  UINT32_C(3736263054),  UINT32_C(4062922146)  },
      {  UINT32_C( 442898144),  UINT32_C(2066268295),  UINT32_C(3937589646),  UINT32_C(1647003042)  } },
    { {  UINT32_C(2089720617),  UINT32_C(1970686998),  UINT32_C( 778315975),  UINT32_C(2964826108)  },
      {  UINT32_C( 394207440),  UINT32_C(4261643434),  UINT32_C(2206406389),  UINT32_C(3380683517)  },
      {  UINT32_C(3754439721),  UINT32_C(2162240150),  UINT32_C(3771055431),  UINT32_C(1615380348)  },
      {  UINT32_C(3826916137),  UINT32_C(1888832534),  UINT32_C(1658759367),  UINT32_C( 610248700)  },
      {  UINT32_C( 109484841),  UINT32_C( 626412566),  UINT32_C(3081513159),  UINT32_C( 401582076)  },
      {  UINT32_C(1083087657),  UINT32_C(2843102230),  UINT32_C(3596888263),  UINT32_C(4105676796)  },
      {  UINT32_C(2089720617),  UINT32_C(1970686998),  UINT32_C(2925799623),  UINT32_C(2964826108)  } },
    { {  UINT32_C(4032337033),  UINT32_C(2722005257),  UINT32_C(3284061714),  UINT32_C(3943119414)  },
      {  UINT32_C(3606855119),  UINT32_C(4011542875),  UINT32_C(3628735594),  UINT32_C(1545447947)  },
      {  UINT32_C(3205460937),  UINT32_C(3335673545),  UINT32_C( 310844050),  UINT32_C( 124420854)  },
      {  UINT32_C(2277110921),  UINT32_C(1764450569),  UINT32_C(1133334034),  UINT32_C(3040967222)  },
      {  UINT32_C(4000879753),  UINT32_C(1256096009),  UINT32_C(3814116882),  UINT32_C(1348418102)  },
      {  UINT32_C(1012438153),  UINT32_C(1849590025),  UINT32_C(2881408530),  UINT32_C( 789002806)  },
      {  UINT32_C(4032337033),  UINT32_C(2722005257),  UINT32_C(1136578066),  UINT32_C(3943119414)  } },
    { {  UINT32_C(1857063657),  UINT32_C( 398218107),  UINT32_C(3397194281),  UINT32_C(2589095246)  },
      {  UINT32_C(  57471507),  UINT32_C(2562833446),  UINT32_C(3648520257),  UINT32_C(3804890585)  },
      {  UINT32_C(3678176489),  UINT32_C( 812583355),  UINT32_C(1577062505),  UINT32_C(2994828878)  },
      {  UINT32_C(2655152873),  UINT32_C( 931451771),  UINT32_C(    537129),  UINT32_C(1086010702)  },
      {  UINT32_C(2425916137),  UINT32_C(3778302843),  UINT32_C(  34411049),  UINT32_C( 785020238)  },
      {  UINT32_C(1320192745),  UINT32_C(2612810619),  UINT32_C( 108859945),  UINT32_C(1716680014)  },
      {  UINT32_C(4004547305),  UINT32_C( 398218107),  UINT32_C(3397194281),  UINT32_C(2589095246)  } },
    { {  UINT32_C(3089759757),  UINT32_C( 293828492),  UINT32_C(3325553807),  UINT32_C( 877656139)  },
      {  UINT32_C(1892709601),  UINT32_C(3829548036),  UINT32_C( 730099765),  UINT32_C(2664244870)  },
      {  UINT32_C( 874330189),  UINT32_C( 277938444),  UINT32_C(3776712015),  UINT32_C(3007947147)  },
      {  UINT32_C( 245120525),  UINT32_C(1216386956),  UINT32_C(2382802063),  UINT32_C(2765150283)  },
      {  UINT32_C(2802449933),  UINT32_C( 539195276),  UINT32_C(2175790223),  UINT32_C( 876083275)  },
      {  UINT32_C(2217344525),  UINT32_C( 293828492),  UINT32_C(3593989263),  UINT32_C( 407894091)  },
      {  UINT32_C(3089759757),  UINT32_C( 293828492),  UINT32_C(3325553807),  UINT32_C( 877656139)  } },
    { {  UINT32_C(3617356505),  UINT32_C(3366892416),  UINT32_C(2443525970),  UINT32_C(3678188135)  },
      {  UINT32_C(2074072819),  UINT32_C(1284524143),  UINT32_C(2431646596),  UINT32_C(4048530367)  },
      {  UINT32_C(3891641561),  UINT32_C( 605166528),  UINT32_C(1006559506),  UINT32_C(1407905767)  },
      {  UINT32_C(4208884441),  UINT32_C( 151909248),  UINT32_C(4285570898),  UINT32_C(4118278759)  },
      {  UINT32_C(3080485593),  UINT32_C(1132376960),  UINT32_C(3693428562),  UINT32_C(1576841831)  },
      {  UINT32_C(3483138777),  UINT32_C(3165565824),  UINT32_C( 296042322),  UINT32_C(4282167911)  },
      {  UINT32_C(3617356505),  UINT32_C(3366892416),  UINT32_C( 296042322),  UINT32_C(3678188135)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);

    simde_uint32x4_t r6 = simde_vsliq_n_u32(a, b, 6);
    simde_uint32x4_t r13 = simde_vsliq_n_u32(a, b, 13);
    simde_uint32x4_t r19 = simde_vsliq_n_u32(a, b, 19);
    simde_uint32x4_t r26 = simde_vsliq_n_u32(a, b, 26);
    simde_uint32x4_t r31 = simde_vsliq_n_u32(a, b, 31);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r31, simde_vld1q_u32(test_vec[i].r31));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r6 = simde_vsliq_n_u32(a, b, 6);
    simde_uint32x4_t r13 = simde_vsliq_n_u32(a, b, 13);
    simde_uint32x4_t r19 = simde_vsliq_n_u32(a, b, 19);
    simde_uint32x4_t r26 = simde_vsliq_n_u32(a, b, 26);
    simde_uint32x4_t r31 = simde_vsliq_n_u32(a, b, 31);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r13[2];
    uint64_t r26[2];
    uint64_t r39[2];
    uint64_t r52[2];
    uint64_t r63[2];
  } test_vec[] = {
    { {  UINT64_C( 3326354101924670590),  UINT64_C(15812941646549698216)  },
      {  UINT64_C(18151090002998169439),  UINT64_C( 1380667824062628123)  },
      {  UINT64_C(12972070462018022526),  UINT64_C( 2576697537094444712)  },
      {  UINT64_C(13955360284637015166),  UINT64_C( 5231003553959724712)  },
      {  UINT64_C( 7838427115654622334),  UINT64_C(  594630893316032168)  },
      {  UINT64_C(17724362110628146302),  UINT64_C( 1275322049397737128)  },
      {  UINT64_C(12549726138779446398),  UINT64_C(15812941646549698216)  } },
    { {  UINT64_C( 5869328896938516263),  UINT64_C( 2222189733952536719)  },
      {  UINT64_C(12411628851339405478),  UINT64_C(  942836641027284248)  },
      {  UINT64_C(16056959959070727975),  UINT64_C(12978740484919984271)  },
      {  UINT64_C(13330739158301581095),  UINT64_C(13255955676427108495)  },
      {  UINT64_C(  690267940543831847),  UINT64_C(15253283237737447567)  },
      {  UINT64_C( 9972108157473038119),  UINT64_C(15097981068604784783)  },
      {  UINT64_C( 5869328896938516263),  UINT64_C( 2222189733952536719)  } },
    { {  UINT64_C(15272376107936314541),  UINT64_C( 7392787741455680135)  },
      {  UINT64_C( 9420840874243141019),  UINT64_C( 6038106548576691917)  },
      {  UINT64_C(12797981472756823213),  UINT64_C( 8447984324952302215)  },
      {  UINT64_C( 8217653932499203245),  UINT64_C(12150569524748616327)  },
      {  UINT64_C( 6851890001671943341),  UINT64_C(17281269205359133319)  },
      {  UINT64_C(15686707273654400173),  UINT64_C( 7843147704192729735)  },
      {  UINT64_C(15272376107936314541),  UINT64_C(16616159778310455943)  } },
    { {  UINT64_C(17788547161097733072),  UINT64_C(10303315733532817032)  },
      {  UINT64_C( 9530739437947880088),  UINT64_C( 9539080515559423601)  },
      {  UINT64_C( 9196555730211242960),  UINT64_C( 3739687229137499784)  },
      {  UINT64_C( 1681744860744483792),  UINT64_C(13922618736527455880)  },
      {  UINT64_C(15582820183151182800),  UINT64_C(16320825774362506888)  },
      {  UINT64_C( 2994222385185653712),  UINT64_C(16653391208125216392)  },
      {  UINT64_C( 8565175124242957264),  UINT64_C(10303315733532817032)  } },
    { {  UINT64_C(11269734078394947120),  UINT64_C(11079511464515323691)  },
      {  UINT64_C( 4631258017608531081),  UINT64_C( 2950484057785924872)  },
      {  UINT64_C(12759864702248498736),  UINT64_C( 5130664822783936299)  },
      {  UINT64_C( 9559719181400167984),  UINT64_C( 8723228335687976747)  },
      {  UINT64_C( 6790941082614519344),  UINT64_C(16446728547236431659)  },
      {  UINT64_C(14453779014945887792),  UINT64_C(15024664738091878187)  },
      {  UINT64_C(11269734078394947120),  UINT64_C( 1856139427660547883)  } },
    { {  UINT64_C( 7998503011676121860),  UINT64_C(12436442786690204518)  },
      {  UINT64_C(10507257933463575756),  UINT64_C(  890983024616133747)  },
      {  UINT64_C( 2949143004844755716),  UINT64_C(12469028540094767974)  },
      {  UINT64_C(12591503202443651844),  UINT64_C( 6659864326580700006)  },
      {  UINT64_C(13848118176700230404),  UINT64_C(10586337451585012582)  },
      {  UINT64_C(14753902452731865860),  UINT64_C( 5131604191095260006)  },
      {  UINT64_C( 7998503011676121860),  UINT64_C(12436442786690204518)  } },
    { {  UINT64_C(10515578012670966780),  UINT64_C(17680525830101447828)  },
      {  UINT64_C(11288336922296194998),  UINT64_C(16689682725274606802)  },
      {  UINT64_C(  528025944447179772),  UINT64_C(13060555188091901076)  },
      {  UINT64_C( 9050423663222406140),  UINT64_C(  952473333433152660)  },
      {  UINT64_C( 3606217256912632828),  UINT64_C(18135548271896081556)  },
      {  UINT64_C( 8894282146817588220),  UINT64_C(14784711269702218900)  },
      {  UINT64_C( 1292205975816190972),  UINT64_C( 8457153793246672020)  } },
    { {  UINT64_C( 2303077286822012679),  UINT64_C(  138581218363046567)  },
      {  UINT64_C(18411670028825252116),  UINT64_C( 8225054175440624625)  },
      {  UINT64_C( 7821329487171323655),  UINT64_C(12134448022314433191)  },
      {  UINT64_C( 6788990914251187975),  UINT64_C(14341129652734655143)  },
      {  UINT64_C(16926931031184631559),  UINT64_C(13667854094844426919)  },
      {  UINT64_C( 1244731374389946119),  UINT64_C(13770977290413537959)  },
      {  UINT64_C( 2303077286822012679),  UINT64_C( 9361953255217822375)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);

    simde_uint64x2_t r13 = simde_vsliq_n_u64(a, b, 13);
    simde_uint64x2_t r26 = simde_vsliq_n_u64(a, b, 26);
    simde_uint64x2_t r39 = simde_vsliq_n_u64(a, b, 39);
    simde_uint64x2_t r52 = simde_vsliq_n_u64(a, b, 52);
    simde_uint64x2_t r63 = simde_vsliq_n_u64(a, b, 63);

    simde_test_arm_neon_assert_equal_u64x2(r13, simde_vld1q_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x2(r26, simde_vld1q_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x2(r39, simde_vld1q_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x2(r52, simde_vld1q_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x2(r63, simde_vld1q_u64(test_vec[i].r63));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r13 = simde_vsliq_n_u64(a, b, 13);
    simde_uint64x2_t r26 = simde_vsliq_n_u64(a, b, 26);
    simde_uint64x2_t r39 = simde_vsliq_n_u64(a, b, 39);
    simde_uint64x2_t r52 = simde_vsliq_n_u64(a, b, 52);
    simde_uint64x2_t r63 = simde_vsliq_n_u64(a, b, 63);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vslid_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a;
    int64_t b;
    int64_t r0;
    int64_t r13;
    int64_t r26;
    int64_t r39;
    int64_t r52;
    int64_t r63;
  } test_vec[] = {
    { -INT64_C( 4407049649672154289),
       INT64_C( 7685653594098796223),
       INT64_C( 7685653594098796223),
       INT64_C( 2136719286638998351),
      -INT64_C( 1955729803667041457),
       INT64_C( 8882048105861092175),
       INT64_C( 7779690941992407887),
      -INT64_C( 4407049649672154289) },
    {  INT64_C( 7285866699229672730),
      -INT64_C( 2905986655787820623),
      -INT64_C( 2905986655787820623),
       INT64_C( 8903914945204598042),
       INT64_C( 2445163668463072538),
      -INT64_C( 2383291881746418406),
      -INT64_C( 7269767296431770342),
      -INT64_C( 1937505337625103078) },
    {  INT64_C( 3846956399612097520),
       INT64_C( 7082777137927379624),
       INT64_C( 7082777137927379624),
       INT64_C( 7100202084554052592),
       INT64_C( 2271412260562498544),
      -INT64_C( 5355531513384700944),
      -INT64_C( 6160041972405144592),
       INT64_C( 3846956399612097520) },
    {  INT64_C(  312901578607213257),
      -INT64_C( 2170968181156342401),
      -INT64_C( 2170968181156342401),
      -INT64_C( 1910052976749184311),
      -INT64_C( 4315011023631631671),
      -INT64_C( 4608660351632098615),
       INT64_C( 6338717880028936905),
      -INT64_C( 8910470458247562551) },
    { -INT64_C(  771551171704575330),
      -INT64_C( 7860431950642236096),
      -INT64_C( 7860431950642236096),
       INT64_C( 4925021658846595742),
       INT64_C( 2748140068509264542),
       INT64_C( 7735671558584347294),
       INT64_C( 6055905863389096606),
       INT64_C( 8451820865150200478) },
    { -INT64_C( 7334995888055225124),
       INT64_C( 9062510049244591345),
       INT64_C( 9062510049244591345),
      -INT64_C( 8062573269252950820),
       INT64_C( 9190306233746486492),
       INT64_C( 5826101671574664412),
       INT64_C( 5698421433554990300),
      -INT64_C( 7334995888055225124) },
    {  INT64_C( 7993004429149292458),
      -INT64_C( 4544729177563676015),
      -INT64_C( 4544729177563676015),
      -INT64_C( 4891881855758751830),
      -INT64_C( 7968034278505101398),
       INT64_C( 8890467051426105258),
       INT64_C( 2962483645376448426),
      -INT64_C( 1230367607705483350) },
    {  INT64_C( 4469862545157550420),
      -INT64_C( 3083587873218123048),
      -INT64_C( 3083587873218123048),
      -INT64_C( 7159220494487842476),
      -INT64_C( 6134880521728003756),
      -INT64_C( 8010377282379026092),
      -INT64_C( 5942459793323036332),
       INT64_C( 4469862545157550420) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r0 = simde_vslid_n_s64(test_vec[i].a, test_vec[i].b, 0);
    int64_t r13 = simde_vslid_n_s64(test_vec[i].a, test_vec[i].b, 13);
    int64_t r26 = simde_vslid_n_s64(test_vec[i].a, test_vec[i].b, 26);
    int64_t r39 = simde_vslid_n_s64(test_vec[i].a, test_vec[i].b, 39);
    int64_t r52 = simde_vslid_n_s64(test_vec[i].a, test_vec[i].b, 52);
    int64_t r63 = simde_vslid_n_s64(test_vec[i].a, test_vec[i].b, 63);

    simde_assert_equal_i64(r0, test_vec[i].r0);
    simde_assert_equal_i64(r13, test_vec[i].r13);
    simde_assert_equal_i64(r26, test_vec[i].r26);
    simde_assert_equal_i64(r39, test_vec[i].r39);
    simde_assert_equal_i64(r52, test_vec[i].r52);
    simde_assert_equal_i64(r63, test_vec[i].r63);
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    int64_t r0 = simde_vslid_n_s64(a, b, 0);
    int64_t r13 = simde_vslid_n_s64(a, b, 13);
    int64_t r26 = simde_vslid_n_s64(a, b, 26);
    int64_t r39 = simde_vslid_n_s64(a, b, 39);
    int64_t r52 = simde_vslid_n_s64(a, b, 52);
    int64_t r63 = simde_vslid_n_s64(a, b, 63);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vslid_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a;
    uint64_t b;
    uint64_t r13;
    uint64_t r26;
    uint64_t r39;
    uint64_t r52;
    uint64_t r63;
  } test_vec[] = {
    { UINT64_C(16047323941614028429),
      UINT64_C( 5759110669390432380),
      UINT64_C(10310007171098576525),
      UINT64_C(10384376197257004685),
      UINT64_C(10872883682835072653),
      UINT64_C( 9782816859941668493),
      UINT64_C( 6823951904759252621) },
    { UINT64_C( 6252747629803370157),
      UINT64_C( 9603497943463504180),
      UINT64_C(14938422555498157741),
      UINT64_C(18304133725414782637),
      UINT64_C(12327647779556456109),
      UINT64_C(10612232069098010285),
      UINT64_C( 6252747629803370157) },
    { UINT64_C( 9127216911202849255),
      UINT64_C( 5473098671353457008),
      UINT64_C(10036216613309387239),
      UINT64_C(17994903780703801831),
      UINT64_C( 6319878951979127271),
      UINT64_C(10883620765877342695),
      UINT64_C( 9127216911202849255) },
    { UINT64_C(17366484507887084631),
      UINT64_C(13169929079093652159),
      UINT64_C(11499672881740637271),
      UINT64_C(16245006858353321047),
      UINT64_C( 4284435786980336727),
      UINT64_C(12390006919642686551),
      UINT64_C(17366484507887084631) },
    { UINT64_C(11977100683987906951),
      UINT64_C(15640438591829181941),
      UINT64_C(13835352351822492039),
      UINT64_C( 2410877258336039303),
      UINT64_C(11890341519974986119),
      UINT64_C( 6870018706549764487),
      UINT64_C(11977100683987906951) },
    { UINT64_C(16622456104105027770),
      UINT64_C(12751574988462635335),
      UINT64_C(15437360142427416762),
      UINT64_C(10423661486465624250),
      UINT64_C(  656579698565064890),
      UINT64_C(10700222594112825530),
      UINT64_C(16622456104105027770) },
    { UINT64_C( 6364346099977397255),
      UINT64_C( 5145566249440208637),
      UINT64_C( 1668506987863712775),
      UINT64_C(17818630034471756807),
      UINT64_C( 1131387083589133319),
      UINT64_C( 8057699559868703751),
      UINT64_C(15587718136832173063) },
    { UINT64_C(14133761816967247706),
      UINT64_C(14840253816082545319),
      UINT64_C( 7315815602266109786),
      UINT64_C(16136662355303987034),
      UINT64_C( 2169982941962172250),
      UINT64_C(12282782370117973850),
      UINT64_C(14133761816967247706) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r13 = simde_vslid_n_u64(test_vec[i].a, test_vec[i].b, 13);
    uint64_t r26 = simde_vslid_n_u64(test_vec[i].a, test_vec[i].b, 26);
    uint64_t r39 = simde_vslid_n_u64(test_vec[i].a, test_vec[i].b, 39);
    uint64_t r52 = simde_vslid_n_u64(test_vec[i].a, test_vec[i].b, 52);
    uint64_t r63 = simde_vslid_n_u64(test_vec[i].a, test_vec[i].b, 63);

    simde_assert_equal_u64(r13, test_vec[i].r13);
    simde_assert_equal_u64(r26, test_vec[i].r26);
    simde_assert_equal_u64(r39, test_vec[i].r39);
    simde_assert_equal_u64(r52, test_vec[i].r52);
    simde_assert_equal_u64(r63, test_vec[i].r63);
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = simde_test_codegen_random_u64();
    uint64_t r13 = simde_vslid_n_u64(a, b, 13);
    uint64_t r26 = simde_vslid_n_u64(a, b, 26);
    uint64_t r39 = simde_vslid_n_u64(a, b, 39);
    uint64_t r52 = simde_vslid_n_u64(a, b, 52);
    uint64_t r63 = simde_vslid_n_u64(a, b, 63);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a[8];
    simde_poly8_t b[8];
    simde_poly8_t r0[8];
    simde_poly8_t r3[8];
    simde_poly8_t r5[8];
    simde_poly8_t r7[8];
  } test_vec[] = {
    { {  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(    53),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   214),  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(   217)  },
      {  SIMDE_POLY8_C(    51),  SIMDE_POLY8_C(     2),  SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(   250),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(    65),  SIMDE_POLY8_C(    28)  },
      {  SIMDE_POLY8_C(    51),  SIMDE_POLY8_C(     2),  SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(   250),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(    65),  SIMDE_POLY8_C(    28)  },
      {  SIMDE_POLY8_C(   154),  SIMDE_POLY8_C(    17),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(   237),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(   110),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(   225)  },
      {  SIMDE_POLY8_C(    98),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(    40),  SIMDE_POLY8_C(   153)  },
      {  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(    25),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   214),  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(    89)  } },
    { {  SIMDE_POLY8_C(   149),  SIMDE_POLY8_C(   148),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   191),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(   160),  SIMDE_POLY8_C(   251)  },
      {  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(   159),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(   191),  SIMDE_POLY8_C(   110),  SIMDE_POLY8_C(   189)  },
      {  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(   159),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(   191),  SIMDE_POLY8_C(   110),  SIMDE_POLY8_C(   189)  },
      {  SIMDE_POLY8_C(   157),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(    82),  SIMDE_POLY8_C(   143),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(   112),  SIMDE_POLY8_C(   235)  },
      {  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(   212),  SIMDE_POLY8_C(   224),  SIMDE_POLY8_C(    82),  SIMDE_POLY8_C(    63),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   187)  },
      {  SIMDE_POLY8_C(   149),  SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   191),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   251)  } },
    { {  SIMDE_POLY8_C(    16),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(     9),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(   219),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(    77)  },
      {  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(    26),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(    34),  SIMDE_POLY8_C(     2),  SIMDE_POLY8_C(   133)  },
      {  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(    26),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(    34),  SIMDE_POLY8_C(     2),  SIMDE_POLY8_C(   133)  },
      {  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(   227),  SIMDE_POLY8_C(    57),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(    19),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(    45)  },
      {  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(    27),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(    90),  SIMDE_POLY8_C(   173)  },
      {  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   137),  SIMDE_POLY8_C(    17),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(    90),  SIMDE_POLY8_C(   205)  } },
    { {  SIMDE_POLY8_C(   102),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(    70),  SIMDE_POLY8_C(   133)  },
      {  SIMDE_POLY8_C(    41),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   177)  },
      {  SIMDE_POLY8_C(    41),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   177)  },
      {  SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(   207),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   229),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   141)  },
      {  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(   199),  SIMDE_POLY8_C(   244),  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(    70),  SIMDE_POLY8_C(    37)  },
      {  SIMDE_POLY8_C(   230),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(   148),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(    70),  SIMDE_POLY8_C(   133)  } },
    { {  SIMDE_POLY8_C(    51),  SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(    70),  SIMDE_POLY8_C(    30),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(     5),  SIMDE_POLY8_C(   134)  },
      {  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(    97)  },
      {  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(    97)  },
      {  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(    23),  SIMDE_POLY8_C(     6),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(    93),  SIMDE_POLY8_C(    14)  },
      {  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(   220),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(     6),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(    38)  },
      {  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(    70),  SIMDE_POLY8_C(    30),  SIMDE_POLY8_C(   113),  SIMDE_POLY8_C(   133),  SIMDE_POLY8_C(   134)  } },
    { {  SIMDE_POLY8_C(   167),  SIMDE_POLY8_C(   158),  SIMDE_POLY8_C(   137),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(   255)  },
      {  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   236),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(   226),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(    64)  },
      {  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   236),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(   226),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(    64)  },
      {  SIMDE_POLY8_C(    15),  SIMDE_POLY8_C(   102),  SIMDE_POLY8_C(   137),  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(   219),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(    12),  SIMDE_POLY8_C(     7)  },
      {  SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(   158),  SIMDE_POLY8_C(    41),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   123),  SIMDE_POLY8_C(    19),  SIMDE_POLY8_C(    44),  SIMDE_POLY8_C(    31)  },
      {  SIMDE_POLY8_C(   167),  SIMDE_POLY8_C(    30),  SIMDE_POLY8_C(   137),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(    51),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(   127)  } },
    { {  SIMDE_POLY8_C(     5),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   188),  SIMDE_POLY8_C(    22),  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(   165),  SIMDE_POLY8_C(    74)  },
      {  SIMDE_POLY8_C(    27),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(    63),  SIMDE_POLY8_C(   133),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   152)  },
      {  SIMDE_POLY8_C(    27),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(    63),  SIMDE_POLY8_C(   133),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   152)  },
      {  SIMDE_POLY8_C(   221),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(    44),  SIMDE_POLY8_C(   110),  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   194)  },
      {  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(   188),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(   165),  SIMDE_POLY8_C(    10)  },
      {  SIMDE_POLY8_C(   133),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(   214),  SIMDE_POLY8_C(   188),  SIMDE_POLY8_C(   150),  SIMDE_POLY8_C(    11),  SIMDE_POLY8_C(   165),  SIMDE_POLY8_C(    74)  } },
    { {  SIMDE_POLY8_C(   250),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(   140),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(    13),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(    19),  SIMDE_POLY8_C(    34)  },
      {  SIMDE_POLY8_C(   170),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   134),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   119),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(     7)  },
      {  SIMDE_POLY8_C(   170),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   134),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   119),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(     7)  },
      {  SIMDE_POLY8_C(    82),  SIMDE_POLY8_C(   149),  SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(   165),  SIMDE_POLY8_C(   191),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(    58)  },
      {  SIMDE_POLY8_C(    90),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(    76),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   141),        SIMDE_POLY8_C(UINT8_MAX),  SIMDE_POLY8_C(    51),  SIMDE_POLY8_C(   226)  },
      {  SIMDE_POLY8_C(   122),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(    12),  SIMDE_POLY8_C(    64),  SIMDE_POLY8_C(    13),  SIMDE_POLY8_C(   223),  SIMDE_POLY8_C(   147),  SIMDE_POLY8_C(   162)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8_t a = simde_vld1_p8(test_vec[i].a);
    simde_poly8x8_t b = simde_vld1_p8(test_vec[i].b);

    simde_poly8x8_t r0 = simde_vsli_n_p8(a, b, 0);
    simde_poly8x8_t r3 = simde_vsli_n_p8(a, b, 3);
    simde_poly8x8_t r5 = simde_vsli_n_p8(a, b, 5);
    simde_poly8x8_t r7 = simde_vsli_n_p8(a, b, 7);

    simde_test_arm_neon_assert_equal_p8x8(r0, simde_vld1_p8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_p8x8(r3, simde_vld1_p8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_p8x8(r5, simde_vld1_p8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_p8x8(r7, simde_vld1_p8(test_vec[i].r7));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x8_t a = simde_test_arm_neon_random_p8x8();
    simde_poly8x8_t b = simde_test_arm_neon_random_p8x8();
    simde_poly8x8_t r0 = simde_vsli_n_p8(a, b, 0);
    simde_poly8x8_t r3 = simde_vsli_n_p8(a, b, 3);
    simde_poly8x8_t r5 = simde_vsli_n_p8(a, b, 5);
    simde_poly8x8_t r7 = simde_vsli_n_p8(a, b, 7);

    simde_test_arm_neon_write_p8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a[4];
    simde_poly16_t b[4];
    simde_poly16_t r3[4];
    simde_poly16_t r6[4];
    simde_poly16_t r10[4];
    simde_poly16_t r13[4];
    simde_poly16_t r15[4];
  } test_vec[] = {
    { {  SIMDE_POLY16_C(  15391),  SIMDE_POLY16_C(   8013),  SIMDE_POLY16_C(   1254),  SIMDE_POLY16_C(  45654)  },
      {  SIMDE_POLY16_C(  35066),  SIMDE_POLY16_C(  48548),  SIMDE_POLY16_C(  14346),  SIMDE_POLY16_C(   1393)  },
      {  SIMDE_POLY16_C(  18391),  SIMDE_POLY16_C(  60709),  SIMDE_POLY16_C(  49238),  SIMDE_POLY16_C(  11150)  },
      {  SIMDE_POLY16_C(  16031),  SIMDE_POLY16_C(  26893),  SIMDE_POLY16_C(    678),  SIMDE_POLY16_C(  23638)  },
      {  SIMDE_POLY16_C(  59423),  SIMDE_POLY16_C(  37709),  SIMDE_POLY16_C(  10470),  SIMDE_POLY16_C(  50774)  },
      {  SIMDE_POLY16_C(  23583),  SIMDE_POLY16_C(  40781),  SIMDE_POLY16_C(  17638),  SIMDE_POLY16_C(  12886)  },
      {  SIMDE_POLY16_C(  15391),  SIMDE_POLY16_C(   8013),  SIMDE_POLY16_C(   1254),  SIMDE_POLY16_C(  45654)  } },
    { {  SIMDE_POLY16_C(  23736),  SIMDE_POLY16_C(   7291),  SIMDE_POLY16_C(  61578),  SIMDE_POLY16_C(   8940)  },
      {  SIMDE_POLY16_C(  15242),  SIMDE_POLY16_C(  20311),  SIMDE_POLY16_C(  19232),  SIMDE_POLY16_C(   4411)  },
      {  SIMDE_POLY16_C(  56400),  SIMDE_POLY16_C(  31419),  SIMDE_POLY16_C(  22786),  SIMDE_POLY16_C(  35292)  },
      {  SIMDE_POLY16_C(  58040),  SIMDE_POLY16_C(  54779),  SIMDE_POLY16_C(  51210),  SIMDE_POLY16_C(  20204)  },
      {  SIMDE_POLY16_C(  10424),  SIMDE_POLY16_C(  23675),  SIMDE_POLY16_C(  32906),  SIMDE_POLY16_C(  61164)  },
      {  SIMDE_POLY16_C(  23736),  SIMDE_POLY16_C(  64635),  SIMDE_POLY16_C(   4234),  SIMDE_POLY16_C(  25324)  },
      {  SIMDE_POLY16_C(  23736),  SIMDE_POLY16_C(  40059),  SIMDE_POLY16_C(  28810),  SIMDE_POLY16_C(  41708)  } },
    { {  SIMDE_POLY16_C(  47025),  SIMDE_POLY16_C(  52193),  SIMDE_POLY16_C(  31710),  SIMDE_POLY16_C(  14843)  },
      {  SIMDE_POLY16_C(  54022),  SIMDE_POLY16_C(  30364),  SIMDE_POLY16_C(  65371),  SIMDE_POLY16_C(  28567)  },
      {  SIMDE_POLY16_C(  38961),  SIMDE_POLY16_C(  46305),  SIMDE_POLY16_C(  64222),  SIMDE_POLY16_C(  31931)  },
      {  SIMDE_POLY16_C(  49585),  SIMDE_POLY16_C(  42785),  SIMDE_POLY16_C(  55006),  SIMDE_POLY16_C(  58875)  },
      {  SIMDE_POLY16_C(   7089),  SIMDE_POLY16_C(  29665),  SIMDE_POLY16_C(  28638),  SIMDE_POLY16_C(  24059)  },
      {  SIMDE_POLY16_C(  55217),  SIMDE_POLY16_C(  35809),  SIMDE_POLY16_C(  31710),  SIMDE_POLY16_C(  63995)  },
      {  SIMDE_POLY16_C(  14257),  SIMDE_POLY16_C(  19425),  SIMDE_POLY16_C(  64478),  SIMDE_POLY16_C(  47611)  } },
    { {  SIMDE_POLY16_C(  54568),  SIMDE_POLY16_C(  15862),  SIMDE_POLY16_C(  52509),  SIMDE_POLY16_C(  47425)  },
      {  SIMDE_POLY16_C(   1779),  SIMDE_POLY16_C(  31523),  SIMDE_POLY16_C(  16426),  SIMDE_POLY16_C(  60116)  },
      {  SIMDE_POLY16_C(  14232),  SIMDE_POLY16_C(  55582),  SIMDE_POLY16_C(    341),  SIMDE_POLY16_C(  22177)  },
      {  SIMDE_POLY16_C(  48360),  SIMDE_POLY16_C(  51446),  SIMDE_POLY16_C(   2717),  SIMDE_POLY16_C(  46337)  },
      {  SIMDE_POLY16_C(  52520),  SIMDE_POLY16_C(  36342),  SIMDE_POLY16_C(  43293),  SIMDE_POLY16_C(  20801)  },
      {  SIMDE_POLY16_C(  29992),  SIMDE_POLY16_C(  32246),  SIMDE_POLY16_C(  19741),  SIMDE_POLY16_C(  39233)  },
      {  SIMDE_POLY16_C(  54568),  SIMDE_POLY16_C(  48630),  SIMDE_POLY16_C(  19741),  SIMDE_POLY16_C(  14657)  } },
    { {  SIMDE_POLY16_C(  19021),  SIMDE_POLY16_C(   2955),  SIMDE_POLY16_C(  23434),  SIMDE_POLY16_C(  24652)  },
      {  SIMDE_POLY16_C(  64304),  SIMDE_POLY16_C(  33123),  SIMDE_POLY16_C(  28656),  SIMDE_POLY16_C(   7738)  },
      {  SIMDE_POLY16_C(  55685),  SIMDE_POLY16_C(   2843),  SIMDE_POLY16_C(  32642),  SIMDE_POLY16_C(  61908)  },
      {  SIMDE_POLY16_C(  52237),  SIMDE_POLY16_C(  22731),  SIMDE_POLY16_C(  64522),  SIMDE_POLY16_C(  36492)  },
      {  SIMDE_POLY16_C(  49741),  SIMDE_POLY16_C(  36747),  SIMDE_POLY16_C(  50058),  SIMDE_POLY16_C(  59468)  },
      {  SIMDE_POLY16_C(   2637),  SIMDE_POLY16_C(  27531),  SIMDE_POLY16_C(   7050),  SIMDE_POLY16_C(  16460)  },
      {  SIMDE_POLY16_C(  19021),  SIMDE_POLY16_C(  35723),  SIMDE_POLY16_C(  23434),  SIMDE_POLY16_C(  24652)  } },
    { {  SIMDE_POLY16_C(  35638),  SIMDE_POLY16_C(  64110),  SIMDE_POLY16_C(  55906),  SIMDE_POLY16_C(  20848)  },
      {  SIMDE_POLY16_C(  27670),  SIMDE_POLY16_C(  29508),  SIMDE_POLY16_C(  17746),  SIMDE_POLY16_C(  25076)  },
      {  SIMDE_POLY16_C(  24758),  SIMDE_POLY16_C(  39462),  SIMDE_POLY16_C(  10898),  SIMDE_POLY16_C(   4000)  },
      {  SIMDE_POLY16_C(   1462),  SIMDE_POLY16_C(  53550),  SIMDE_POLY16_C(  21666),  SIMDE_POLY16_C(  32048)  },
      {  SIMDE_POLY16_C(  23350),  SIMDE_POLY16_C(   4718),  SIMDE_POLY16_C(  19042),  SIMDE_POLY16_C(  53616)  },
      {  SIMDE_POLY16_C(  52022),  SIMDE_POLY16_C(  39534),  SIMDE_POLY16_C(  23138),  SIMDE_POLY16_C(  37232)  },
      {  SIMDE_POLY16_C(   2870),  SIMDE_POLY16_C(  31342),  SIMDE_POLY16_C(  23138),  SIMDE_POLY16_C(  20848)  } },
    { {  SIMDE_POLY16_C(  23800),  SIMDE_POLY16_C(  37832),  SIMDE_POLY16_C(  34512),  SIMDE_POLY16_C(  33446)  },
      {  SIMDE_POLY16_C(  19904),  SIMDE_POLY16_C(  51885),  SIMDE_POLY16_C(  10602),  SIMDE_POLY16_C(  42147)  },
      {  SIMDE_POLY16_C(  28160),  SIMDE_POLY16_C(  21864),  SIMDE_POLY16_C(  19280),  SIMDE_POLY16_C(   9502)  },
      {  SIMDE_POLY16_C(  28728),  SIMDE_POLY16_C(  43848),  SIMDE_POLY16_C(  23184),  SIMDE_POLY16_C(  10470)  },
      {  SIMDE_POLY16_C(    248),  SIMDE_POLY16_C(  47048),  SIMDE_POLY16_C(  43728),  SIMDE_POLY16_C(  36518)  },
      {  SIMDE_POLY16_C(   7416),  SIMDE_POLY16_C(  46024),  SIMDE_POLY16_C(  18128),  SIMDE_POLY16_C(  25254)  },
      {  SIMDE_POLY16_C(  23800),  SIMDE_POLY16_C(  37832),  SIMDE_POLY16_C(   1744),  SIMDE_POLY16_C(  33446)  } },
    { {  SIMDE_POLY16_C(  32311),  SIMDE_POLY16_C(  55845),  SIMDE_POLY16_C(  55299),  SIMDE_POLY16_C(  15525)  },
      {  SIMDE_POLY16_C(  16152),  SIMDE_POLY16_C(  36439),  SIMDE_POLY16_C(  64155),  SIMDE_POLY16_C(  41506)  },
      {  SIMDE_POLY16_C(  63687),  SIMDE_POLY16_C(  29373),  SIMDE_POLY16_C(  54491),  SIMDE_POLY16_C(   4373)  },
      {  SIMDE_POLY16_C(  50743),  SIMDE_POLY16_C(  38373),  SIMDE_POLY16_C(  42691),  SIMDE_POLY16_C(  34981)  },
      {  SIMDE_POLY16_C(  25143),  SIMDE_POLY16_C(  24101),  SIMDE_POLY16_C(  27651),  SIMDE_POLY16_C(  34981)  },
      {  SIMDE_POLY16_C(   7735),  SIMDE_POLY16_C(  64037),  SIMDE_POLY16_C(  30723),  SIMDE_POLY16_C(  23717)  },
      {  SIMDE_POLY16_C(  32311),  SIMDE_POLY16_C(  55845),  SIMDE_POLY16_C(  55299),  SIMDE_POLY16_C(  15525)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4_t a = simde_vld1_p16(test_vec[i].a);
    simde_poly16x4_t b = simde_vld1_p16(test_vec[i].b);

    simde_poly16x4_t r3 = simde_vsli_n_p16(a, b, 3);
    simde_poly16x4_t r6 = simde_vsli_n_p16(a, b, 6);
    simde_poly16x4_t r10 = simde_vsli_n_p16(a, b, 10);
    simde_poly16x4_t r13 = simde_vsli_n_p16(a, b, 13);
    simde_poly16x4_t r15 = simde_vsli_n_p16(a, b, 15);

    simde_test_arm_neon_assert_equal_p16x4(r3, simde_vld1_p16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_p16x4(r6, simde_vld1_p16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_p16x4(r10, simde_vld1_p16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_p16x4(r13, simde_vld1_p16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_p16x4(r15, simde_vld1_p16(test_vec[i].r15));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x4_t a = simde_test_arm_neon_random_p16x4();
    simde_poly16x4_t b = simde_test_arm_neon_random_p16x4();
    simde_poly16x4_t r3 = simde_vsli_n_p16(a, b, 3);
    simde_poly16x4_t r6 = simde_vsli_n_p16(a, b, 6);
    simde_poly16x4_t r10 = simde_vsli_n_p16(a, b, 10);
    simde_poly16x4_t r13 = simde_vsli_n_p16(a, b, 13);
    simde_poly16x4_t r15 = simde_vsli_n_p16(a, b, 15);

    simde_test_arm_neon_write_p16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly64_t a[1];
    simde_poly64_t b[1];
    simde_poly64_t r13[1];
    simde_poly64_t r26[1];
    simde_poly64_t r39[1];
    simde_poly64_t r52[1];
    simde_poly64_t r63[1];
  } test_vec[] = {
    { {  SIMDE_POLY64_C( 2367438358383478378)  },
      {  SIMDE_POLY64_C(10151069329549398822)  },
      {  SIMDE_POLY64_C(18084407459726018154)  },
      {  SIMDE_POLY64_C( 1664254114169931370)  },
      {  SIMDE_POLY64_C( 1425832543274714730)  },
      {  SIMDE_POLY64_C( 3632949853674587754)  },
      {  SIMDE_POLY64_C( 2367438358383478378)  } },
    { {  SIMDE_POLY64_C( 4289360236958653475)  },
      {  SIMDE_POLY64_C( 9003445777938185491)  },
      {  SIMDE_POLY64_C( 6145006178828188707)  },
      {  SIMDE_POLY64_C(17172783880833014819)  },
      {  SIMDE_POLY64_C( 4575245904564132899)  },
      {  SIMDE_POLY64_C(15075481344510991395)  },
      {  SIMDE_POLY64_C(13512732273813429283)  } },
    { {  SIMDE_POLY64_C( 4661840731346591672)  },
      {  SIMDE_POLY64_C(16008367045675390461)  },
      {  SIMDE_POLY64_C( 2639218171596226488)  },
      {  SIMDE_POLY64_C(  891207328682762168)  },
      {  SIMDE_POLY64_C(14306527482023272376)  },
      {  SIMDE_POLY64_C( 6904633345777098680)  },
      {  SIMDE_POLY64_C(13885212768201367480)  } },
    { {  SIMDE_POLY64_C(  560855986095228110)  },
      {  SIMDE_POLY64_C(12519105941898633195)  },
      {  SIMDE_POLY64_C(11065570282205701326)  },
      {  SIMDE_POLY64_C( 1851373620381320398)  },
      {  SIMDE_POLY64_C( 3229069440521569486)  },
      {  SIMDE_POLY64_C(18354578113836057806)  },
      {  SIMDE_POLY64_C( 9784228022950003918)  } },
    { {  SIMDE_POLY64_C(15210706800944352878)  },
      {  SIMDE_POLY64_C( 2343987333079752503)  },
      {  SIMDE_POLY64_C(17330395931398827630)  },
      {  SIMDE_POLY64_C( 4461078750471655022)  },
      {  SIMDE_POLY64_C( 2157113990720261742)  },
      {  SIMDE_POLY64_C(17543571407922269806)  },
      {  SIMDE_POLY64_C(15210706800944352878)  } },
    { {  SIMDE_POLY64_C( 3102245097986106578)  },
      {  SIMDE_POLY64_C(11620068368410445742)  },
      {  SIMDE_POLY64_C( 6400653677085181138)  },
      {  SIMDE_POLY64_C( 8508265199309464786)  },
      {  SIMDE_POLY64_C( 7909402293599511762)  },
      {  SIMDE_POLY64_C( 8857845421765600466)  },
      {  SIMDE_POLY64_C( 3102245097986106578)  } },
    { {  SIMDE_POLY64_C(17038098246975051983)  },
      {  SIMDE_POLY64_C(18292780545233057134)  },
      {  SIMDE_POLY64_C(11556115806516271311)  },
      {  SIMDE_POLY64_C(17456844777586120911)  },
      {  SIMDE_POLY64_C( 7312358247877793999)  },
      {  SIMDE_POLY64_C( 6260984338677455055)  },
      {  SIMDE_POLY64_C( 7814726210120276175)  } },
    { {  SIMDE_POLY64_C( 1351949120307680797)  },
      {  SIMDE_POLY64_C(15139404553755458091)  },
      {  SIMDE_POLY64_C( 4541696815397172765)  },
      {  SIMDE_POLY64_C(16944259135176136221)  },
      {  SIMDE_POLY64_C(14068424518630069789)  },
      {  SIMDE_POLY64_C(11723739062141933085)  },
      {  SIMDE_POLY64_C(10575321157162456605)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x1_t a = simde_vld1_p64(test_vec[i].a);
    simde_poly64x1_t b = simde_vld1_p64(test_vec[i].b);

    simde_poly64x1_t r13 = simde_vsli_n_p64(a, b, 13);
    simde_poly64x1_t r26 = simde_vsli_n_p64(a, b, 26);
    simde_poly64x1_t r39 = simde_vsli_n_p64(a, b, 39);
    simde_poly64x1_t r52 = simde_vsli_n_p64(a, b, 52);
    simde_poly64x1_t r63 = simde_vsli_n_p64(a, b, 63);

    simde_test_arm_neon_assert_equal_p64x1(r13, simde_vld1_p64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_p64x1(r26, simde_vld1_p64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_p64x1(r39, simde_vld1_p64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_p64x1(r52, simde_vld1_p64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_p64x1(r63, simde_vld1_p64(test_vec[i].r63));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x1_t a = simde_test_arm_neon_random_p64x1();
    simde_poly64x1_t b = simde_test_arm_neon_random_p64x1();
    simde_poly64x1_t r13 = simde_vsli_n_p64(a, b, 13);
    simde_poly64x1_t r26 = simde_vsli_n_p64(a, b, 26);
    simde_poly64x1_t r39 = simde_vsli_n_p64(a, b, 39);
    simde_poly64x1_t r52 = simde_vsli_n_p64(a, b, 52);
    simde_poly64x1_t r63 = simde_vsli_n_p64(a, b, 63);

    simde_test_arm_neon_write_p64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a[16];
    simde_poly8_t b[16];
    simde_poly8_t r0[16];
    simde_poly8_t r3[16];
    simde_poly8_t r5[16];
    simde_poly8_t r7[16];
  } test_vec[] = {
    { {  SIMDE_POLY8_C(   244),  SIMDE_POLY8_C(    66),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(   119),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    73),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(   242),  SIMDE_POLY8_C(   252),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(   128),  SIMDE_POLY8_C(    96)  },
      {  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(    52),  SIMDE_POLY8_C(   255),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(   117)  },
      {  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(    52),        SIMDE_POLY8_C(UINT8_MAX),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(   117)  },
      {  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   170),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   221),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(   156),  SIMDE_POLY8_C(   167),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   177),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   106),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(   109),  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(   168)  },
      {  SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(   162),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   151),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   178),  SIMDE_POLY8_C(   156),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   160)  },
      {  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   244),  SIMDE_POLY8_C(   197),  SIMDE_POLY8_C(    56),  SIMDE_POLY8_C(    56),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   119),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    73),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(   242),  SIMDE_POLY8_C(   124),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(   128),  SIMDE_POLY8_C(   224)  } },
    { {  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(    71),  SIMDE_POLY8_C(   208),  SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    88),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   150)  },
      {  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   236),  SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   223),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(     1),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(     5),  SIMDE_POLY8_C(   159),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(   104),  SIMDE_POLY8_C(   122)  },
      {  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   236),  SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   223),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(     1),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(     5),  SIMDE_POLY8_C(   159),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(   104),  SIMDE_POLY8_C(   122)  },
      {  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   185),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   122),        SIMDE_POLY8_C(UINT8_MAX),  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(   239),  SIMDE_POLY8_C(     9),  SIMDE_POLY8_C(   200),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(    41),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(   126),  SIMDE_POLY8_C(    66),  SIMDE_POLY8_C(   214)  },
      {  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(   167),  SIMDE_POLY8_C(    57),  SIMDE_POLY8_C(    56),  SIMDE_POLY8_C(   123),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(    26),  SIMDE_POLY8_C(    86)  },
      {  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(    59),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   199),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(   167),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(    90),  SIMDE_POLY8_C(    22)  } },
    { {  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(    98),  SIMDE_POLY8_C(   126),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   135),  SIMDE_POLY8_C(   177),  SIMDE_POLY8_C(   214),  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(    59),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(    22),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(    55)  },
      {  SIMDE_POLY8_C(   110),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   122),  SIMDE_POLY8_C(    11),  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(   130),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(    56),  SIMDE_POLY8_C(   211),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(     9),  SIMDE_POLY8_C(   238),  SIMDE_POLY8_C(   204),  SIMDE_POLY8_C(    88),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(   141)  },
      {  SIMDE_POLY8_C(   110),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   122),  SIMDE_POLY8_C(    11),  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(   130),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(    56),  SIMDE_POLY8_C(   211),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(     9),  SIMDE_POLY8_C(   238),  SIMDE_POLY8_C(   204),  SIMDE_POLY8_C(    88),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(   141)  },
      {  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(   210),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(    23),  SIMDE_POLY8_C(   137),  SIMDE_POLY8_C(   198),  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(    73),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   102),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(    25),  SIMDE_POLY8_C(   111)  },
      {  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(    66),  SIMDE_POLY8_C(   126),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(    71),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(    22),  SIMDE_POLY8_C(   112),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(    57),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   150),  SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   183)  },
      {  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(    98),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(   177),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(    22),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   183)  } },
    { {  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   212),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(    50),  SIMDE_POLY8_C(   112),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   188),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(   127)  },
      {  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   224),  SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   193),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    27),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(   102),  SIMDE_POLY8_C(   237),  SIMDE_POLY8_C(   120)  },
      {  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   224),  SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   193),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    27),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(   102),  SIMDE_POLY8_C(   237),  SIMDE_POLY8_C(   120)  },
      {  SIMDE_POLY8_C(   244),  SIMDE_POLY8_C(     5),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(    93),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   236),  SIMDE_POLY8_C(    93),  SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(    13),  SIMDE_POLY8_C(   226),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(   109),  SIMDE_POLY8_C(   199)  },
      {  SIMDE_POLY8_C(   212),  SIMDE_POLY8_C(    13),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(   114),  SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(    31)  },
      {  SIMDE_POLY8_C(    52),  SIMDE_POLY8_C(    13),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(   245),  SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   212),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(    50),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(   127)  } },
    { {  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(    11),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(   108),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   175),  SIMDE_POLY8_C(    43)  },
      {  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(    83),  SIMDE_POLY8_C(    71),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(    24),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(   220),  SIMDE_POLY8_C(    16),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(   162),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(    29)  },
      {  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(    83),  SIMDE_POLY8_C(    71),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(    24),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(   220),  SIMDE_POLY8_C(    16),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(   162),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(    29)  },
      {  SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   156),  SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(   197),  SIMDE_POLY8_C(    73),  SIMDE_POLY8_C(   229),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    16),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   207),  SIMDE_POLY8_C(   235)  },
      {  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   245),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(    13),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   149),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(    12),  SIMDE_POLY8_C(    88),  SIMDE_POLY8_C(   161),  SIMDE_POLY8_C(   105),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(   171)  },
      {  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(    62),  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(   108),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   175),  SIMDE_POLY8_C(   171)  } },
    { {  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(    11),  SIMDE_POLY8_C(   127),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(    55),  SIMDE_POLY8_C(   177),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(   151),  SIMDE_POLY8_C(   156),  SIMDE_POLY8_C(    20)  },
      {  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(    74),  SIMDE_POLY8_C(   188),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   142),  SIMDE_POLY8_C(   233)  },
      {  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(    74),  SIMDE_POLY8_C(   188),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   142),  SIMDE_POLY8_C(   233)  },
      {  SIMDE_POLY8_C(    50),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(   206),  SIMDE_POLY8_C(   215),  SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(    62),  SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(    76)  },
      {  SIMDE_POLY8_C(   202),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    11),  SIMDE_POLY8_C(   127),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    29),  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(   151),  SIMDE_POLY8_C(   220),  SIMDE_POLY8_C(    52)  },
      {  SIMDE_POLY8_C(   106),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(   113),  SIMDE_POLY8_C(    11),        SIMDE_POLY8_C(UINT8_MAX),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(    55),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(    23),  SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(   148)  } },
    { {  SIMDE_POLY8_C(    46),  SIMDE_POLY8_C(   219),  SIMDE_POLY8_C(    53),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(   130),  SIMDE_POLY8_C(   212),  SIMDE_POLY8_C(    30),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(   206),  SIMDE_POLY8_C(    67),  SIMDE_POLY8_C(    71),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(   104),  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(    15),  SIMDE_POLY8_C(   107)  },
      {  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(   253),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   160),  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(    90)  },
      {  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(   253),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   160),  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(    90)  },
      {  SIMDE_POLY8_C(   238),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   237),  SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(    26),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   149),  SIMDE_POLY8_C(     6),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(   135),  SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(   167),  SIMDE_POLY8_C(   211)  },
      {  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   123),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    98),  SIMDE_POLY8_C(   148),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(   227),  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   143),  SIMDE_POLY8_C(    75)  },
      {  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   219),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(   130),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(    30),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(    71),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   104),  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(    15),  SIMDE_POLY8_C(   107)  } },
    { {  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(    41),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(   239),  SIMDE_POLY8_C(   215),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(    83),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(    31),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(    42),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(    12)  },
      {  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(    29),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(   138),  SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(    66),  SIMDE_POLY8_C(   163),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(    89)  },
      {  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(    29),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(   138),  SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(    66),  SIMDE_POLY8_C(   163),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(    89)  },
      {  SIMDE_POLY8_C(   186),  SIMDE_POLY8_C(    57),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   239),  SIMDE_POLY8_C(    96),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(    24),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(    10),  SIMDE_POLY8_C(   108),  SIMDE_POLY8_C(   204)  },
      {  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(    40),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(   206),  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(   112),  SIMDE_POLY8_C(   127),  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(    42),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(    44)  },
      {  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(   239),  SIMDE_POLY8_C(   215),  SIMDE_POLY8_C(    88),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(    46),  SIMDE_POLY8_C(   211),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(   159),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(   170),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   140)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16_t a = simde_vld1q_p8(test_vec[i].a);
    simde_poly8x16_t b = simde_vld1q_p8(test_vec[i].b);

    simde_poly8x16_t r0 = simde_vsliq_n_p8(a, b, 0);
    simde_poly8x16_t r3 = simde_vsliq_n_p8(a, b, 3);
    simde_poly8x16_t r5 = simde_vsliq_n_p8(a, b, 5);
    simde_poly8x16_t r7 = simde_vsliq_n_p8(a, b, 7);

    simde_test_arm_neon_assert_equal_p8x16(r0, simde_vld1q_p8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_p8x16(r3, simde_vld1q_p8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_p8x16(r5, simde_vld1q_p8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_p8x16(r7, simde_vld1q_p8(test_vec[i].r7));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x16_t a = simde_test_arm_neon_random_p8x16();
    simde_poly8x16_t b = simde_test_arm_neon_random_p8x16();
    simde_poly8x16_t r0 = simde_vsliq_n_p8(a, b, 0);
    simde_poly8x16_t r3 = simde_vsliq_n_p8(a, b, 3);
    simde_poly8x16_t r5 = simde_vsliq_n_p8(a, b, 5);
    simde_poly8x16_t r7 = simde_vsliq_n_p8(a, b, 7);

    simde_test_arm_neon_write_p8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a[8];
    simde_poly16_t b[8];
    simde_poly16_t r3[8];
    simde_poly16_t r6[8];
    simde_poly16_t r10[8];
    simde_poly16_t r13[8];
    simde_poly16_t r15[8];
  } test_vec[] = {
    { {  SIMDE_POLY16_C(  54932),  SIMDE_POLY16_C(   2052),  SIMDE_POLY16_C(  30900),  SIMDE_POLY16_C(   7957),  SIMDE_POLY16_C(  53988),  SIMDE_POLY16_C(  54164),  SIMDE_POLY16_C(  41244),  SIMDE_POLY16_C(  57663)  },
      {  SIMDE_POLY16_C(  22926),  SIMDE_POLY16_C(  51202),  SIMDE_POLY16_C(   3783),  SIMDE_POLY16_C(  62722),  SIMDE_POLY16_C(  47770),  SIMDE_POLY16_C(  44849),  SIMDE_POLY16_C(  38117),  SIMDE_POLY16_C(  19359)  },
      {  SIMDE_POLY16_C(  52340),  SIMDE_POLY16_C(  16404),  SIMDE_POLY16_C(  30268),  SIMDE_POLY16_C(  43029),  SIMDE_POLY16_C(  54484),  SIMDE_POLY16_C(  31116),  SIMDE_POLY16_C(  42796),  SIMDE_POLY16_C(  23807)  },
      {  SIMDE_POLY16_C(  25492),  SIMDE_POLY16_C(    132),  SIMDE_POLY16_C(  45556),  SIMDE_POLY16_C(  16533),  SIMDE_POLY16_C(  42660),  SIMDE_POLY16_C(  52308),  SIMDE_POLY16_C(  14684),  SIMDE_POLY16_C(  59391)  },
      {  SIMDE_POLY16_C(  14996),  SIMDE_POLY16_C(   2052),  SIMDE_POLY16_C(   7348),  SIMDE_POLY16_C(   2837),  SIMDE_POLY16_C(  27364),  SIMDE_POLY16_C(  51092),  SIMDE_POLY16_C(  38172),  SIMDE_POLY16_C(  32063)  },
      {  SIMDE_POLY16_C(  54932),  SIMDE_POLY16_C(  18436),  SIMDE_POLY16_C(  63668),  SIMDE_POLY16_C(  24341),  SIMDE_POLY16_C(  21220),  SIMDE_POLY16_C(  13204),  SIMDE_POLY16_C(  41244),  SIMDE_POLY16_C(  57663)  },
      {  SIMDE_POLY16_C(  22164),  SIMDE_POLY16_C(   2052),  SIMDE_POLY16_C(  63668),  SIMDE_POLY16_C(   7957),  SIMDE_POLY16_C(  21220),  SIMDE_POLY16_C(  54164),  SIMDE_POLY16_C(  41244),  SIMDE_POLY16_C(  57663)  } },
    { {  SIMDE_POLY16_C(  55983),  SIMDE_POLY16_C(   3761),  SIMDE_POLY16_C(  17325),  SIMDE_POLY16_C(   1501),  SIMDE_POLY16_C(  20550),  SIMDE_POLY16_C(  44898),  SIMDE_POLY16_C(   2169),  SIMDE_POLY16_C(  48672)  },
      {  SIMDE_POLY16_C(  59886),  SIMDE_POLY16_C(  11886),  SIMDE_POLY16_C(  50059),  SIMDE_POLY16_C(  39013),  SIMDE_POLY16_C(   4828),  SIMDE_POLY16_C(  28010),  SIMDE_POLY16_C(   2847),  SIMDE_POLY16_C(  15306)  },
      {  SIMDE_POLY16_C(  20343),  SIMDE_POLY16_C(  29553),  SIMDE_POLY16_C(   7261),  SIMDE_POLY16_C(  49965),  SIMDE_POLY16_C(  38630),  SIMDE_POLY16_C(  27474),  SIMDE_POLY16_C(  22777),  SIMDE_POLY16_C(  56912)  },
      {  SIMDE_POLY16_C(  31663),  SIMDE_POLY16_C(  39857),  SIMDE_POLY16_C(  58093),  SIMDE_POLY16_C(   6493),  SIMDE_POLY16_C(  46854),  SIMDE_POLY16_C(  23202),  SIMDE_POLY16_C(  51193),  SIMDE_POLY16_C(  62112)  },
      {  SIMDE_POLY16_C(  47791),  SIMDE_POLY16_C(  47793),  SIMDE_POLY16_C(  12205),  SIMDE_POLY16_C(  38365),  SIMDE_POLY16_C(  28742),  SIMDE_POLY16_C(  43874),  SIMDE_POLY16_C(  31865),  SIMDE_POLY16_C(  10784)  },
      {  SIMDE_POLY16_C(  55983),  SIMDE_POLY16_C(  52913),  SIMDE_POLY16_C(  25517),  SIMDE_POLY16_C(  42461),  SIMDE_POLY16_C(  36934),  SIMDE_POLY16_C(  20322),  SIMDE_POLY16_C(  59513),  SIMDE_POLY16_C(  24096)  },
      {  SIMDE_POLY16_C(  23215),  SIMDE_POLY16_C(   3761),  SIMDE_POLY16_C(  50093),  SIMDE_POLY16_C(  34269),  SIMDE_POLY16_C(  20550),  SIMDE_POLY16_C(  12130),  SIMDE_POLY16_C(  34937),  SIMDE_POLY16_C(  15904)  } },
    { {  SIMDE_POLY16_C(  17536),  SIMDE_POLY16_C(  59891),  SIMDE_POLY16_C(  42463),  SIMDE_POLY16_C(   3164),  SIMDE_POLY16_C(  10034),  SIMDE_POLY16_C(  15752),  SIMDE_POLY16_C(  13926),  SIMDE_POLY16_C(  51179)  },
      {  SIMDE_POLY16_C(  16067),  SIMDE_POLY16_C(  15431),  SIMDE_POLY16_C(  15067),  SIMDE_POLY16_C(  39231),  SIMDE_POLY16_C(  52443),  SIMDE_POLY16_C(  53059),  SIMDE_POLY16_C(  35282),  SIMDE_POLY16_C(   4686)  },
      {  SIMDE_POLY16_C(  63000),  SIMDE_POLY16_C(  57915),  SIMDE_POLY16_C(  55007),  SIMDE_POLY16_C(  51708),  SIMDE_POLY16_C(  26330),  SIMDE_POLY16_C(  31256),  SIMDE_POLY16_C(  20118),  SIMDE_POLY16_C(  37491)  },
      {  SIMDE_POLY16_C(  45248),  SIMDE_POLY16_C(   4595),  SIMDE_POLY16_C(  46815),  SIMDE_POLY16_C(  20444),  SIMDE_POLY16_C(  14066),  SIMDE_POLY16_C(  53448),  SIMDE_POLY16_C(  29862),  SIMDE_POLY16_C(  37803)  },
      {  SIMDE_POLY16_C(   3200),  SIMDE_POLY16_C(   7667),  SIMDE_POLY16_C(  28127),  SIMDE_POLY16_C(  64604),  SIMDE_POLY16_C(  28466),  SIMDE_POLY16_C(   3464),  SIMDE_POLY16_C(  19046),  SIMDE_POLY16_C(  15339)  },
      {  SIMDE_POLY16_C(  25728),  SIMDE_POLY16_C(  59891),  SIMDE_POLY16_C(  26079),  SIMDE_POLY16_C(  60508),  SIMDE_POLY16_C(  26418),  SIMDE_POLY16_C(  32136),  SIMDE_POLY16_C(  22118),  SIMDE_POLY16_C(  51179)  },
      {  SIMDE_POLY16_C(  50304),  SIMDE_POLY16_C(  59891),  SIMDE_POLY16_C(  42463),  SIMDE_POLY16_C(  35932),  SIMDE_POLY16_C(  42802),  SIMDE_POLY16_C(  48520),  SIMDE_POLY16_C(  13926),  SIMDE_POLY16_C(  18411)  } },
    { {  SIMDE_POLY16_C(  55903),  SIMDE_POLY16_C(  22857),  SIMDE_POLY16_C(  39133),  SIMDE_POLY16_C(  33408),  SIMDE_POLY16_C(  16011),  SIMDE_POLY16_C(    990),  SIMDE_POLY16_C(  21485),  SIMDE_POLY16_C(  53727)  },
      {  SIMDE_POLY16_C(  10331),  SIMDE_POLY16_C(   5549),  SIMDE_POLY16_C(  17252),  SIMDE_POLY16_C(  48442),  SIMDE_POLY16_C(   3492),  SIMDE_POLY16_C(  61577),  SIMDE_POLY16_C(  18795),  SIMDE_POLY16_C(  38317)  },
      {  SIMDE_POLY16_C(  17119),  SIMDE_POLY16_C(  44393),  SIMDE_POLY16_C(   6949),  SIMDE_POLY16_C(  59856),  SIMDE_POLY16_C(  27939),  SIMDE_POLY16_C(  33870),  SIMDE_POLY16_C(  19293),  SIMDE_POLY16_C(  44399)  },
      {  SIMDE_POLY16_C(   5855),  SIMDE_POLY16_C(  27465),  SIMDE_POLY16_C(  55581),  SIMDE_POLY16_C(  20096),  SIMDE_POLY16_C(  26891),  SIMDE_POLY16_C(   8798),  SIMDE_POLY16_C(  23277),  SIMDE_POLY16_C(  27487)  },
      {  SIMDE_POLY16_C(  28255),  SIMDE_POLY16_C(  46409),  SIMDE_POLY16_C(  37085),  SIMDE_POLY16_C(  60032),  SIMDE_POLY16_C(  37515),  SIMDE_POLY16_C(  10206),  SIMDE_POLY16_C(  45037),  SIMDE_POLY16_C(  46559)  },
      {  SIMDE_POLY16_C(  31327),  SIMDE_POLY16_C(  47433),  SIMDE_POLY16_C(  39133),  SIMDE_POLY16_C(  17024),  SIMDE_POLY16_C(  40587),  SIMDE_POLY16_C(   9182),  SIMDE_POLY16_C(  29677),  SIMDE_POLY16_C(  45535)  },
      {  SIMDE_POLY16_C(  55903),  SIMDE_POLY16_C(  55625),  SIMDE_POLY16_C(   6365),  SIMDE_POLY16_C(    640),  SIMDE_POLY16_C(  16011),  SIMDE_POLY16_C(  33758),  SIMDE_POLY16_C(  54253),  SIMDE_POLY16_C(  53727)  } },
    { {  SIMDE_POLY16_C(  30910),  SIMDE_POLY16_C(  36057),  SIMDE_POLY16_C(  28028),  SIMDE_POLY16_C(  65285),  SIMDE_POLY16_C(  30944),  SIMDE_POLY16_C(  29925),  SIMDE_POLY16_C(  64087),  SIMDE_POLY16_C(  51797)  },
      {  SIMDE_POLY16_C(  21033),  SIMDE_POLY16_C(  43881),  SIMDE_POLY16_C(  63534),  SIMDE_POLY16_C(  35658),  SIMDE_POLY16_C(  41153),  SIMDE_POLY16_C(  27208),  SIMDE_POLY16_C(  27863),  SIMDE_POLY16_C(  40336)  },
      {  SIMDE_POLY16_C(  37198),  SIMDE_POLY16_C(  23369),  SIMDE_POLY16_C(  49524),  SIMDE_POLY16_C(  23125),  SIMDE_POLY16_C(   1544),  SIMDE_POLY16_C(  21061),  SIMDE_POLY16_C(  26303),  SIMDE_POLY16_C(  60549)  },
      {  SIMDE_POLY16_C(  35454),  SIMDE_POLY16_C(  55897),  SIMDE_POLY16_C(   3004),  SIMDE_POLY16_C(  53893),  SIMDE_POLY16_C(  12384),  SIMDE_POLY16_C(  37413),  SIMDE_POLY16_C(  13783),  SIMDE_POLY16_C(  25621)  },
      {  SIMDE_POLY16_C(  42174),  SIMDE_POLY16_C(  42201),  SIMDE_POLY16_C(  47484),  SIMDE_POLY16_C(  11013),  SIMDE_POLY16_C(   1248),  SIMDE_POLY16_C(   8421),  SIMDE_POLY16_C(  24151),  SIMDE_POLY16_C(  16981)  },
      {  SIMDE_POLY16_C(  14526),  SIMDE_POLY16_C(  11481),  SIMDE_POLY16_C(  52604),  SIMDE_POLY16_C(  24325),  SIMDE_POLY16_C(  14560),  SIMDE_POLY16_C(   5349),  SIMDE_POLY16_C(  64087),  SIMDE_POLY16_C(   2645)  },
      {  SIMDE_POLY16_C(  63678),  SIMDE_POLY16_C(  36057),  SIMDE_POLY16_C(  28028),  SIMDE_POLY16_C(  32517),  SIMDE_POLY16_C(  63712),  SIMDE_POLY16_C(  29925),  SIMDE_POLY16_C(  64087),  SIMDE_POLY16_C(  19029)  } },
    { {  SIMDE_POLY16_C(   2698),  SIMDE_POLY16_C(  52795),  SIMDE_POLY16_C(  47428),  SIMDE_POLY16_C(  57027),  SIMDE_POLY16_C(  39964),  SIMDE_POLY16_C(  36120),  SIMDE_POLY16_C(  60475),  SIMDE_POLY16_C(  45338)  },
      {  SIMDE_POLY16_C(  21185),  SIMDE_POLY16_C(   2661),  SIMDE_POLY16_C(  53801),  SIMDE_POLY16_C(  24352),  SIMDE_POLY16_C(  21787),  SIMDE_POLY16_C(  30325),  SIMDE_POLY16_C(  60200),  SIMDE_POLY16_C(  19373)  },
      {  SIMDE_POLY16_C(  38410),  SIMDE_POLY16_C(  21291),  SIMDE_POLY16_C(  37196),  SIMDE_POLY16_C(  63747),  SIMDE_POLY16_C(  43228),  SIMDE_POLY16_C(  45992),  SIMDE_POLY16_C(  22851),  SIMDE_POLY16_C(  23914)  },
      {  SIMDE_POLY16_C(  45130),  SIMDE_POLY16_C(  39291),  SIMDE_POLY16_C(  35396),  SIMDE_POLY16_C(  51203),  SIMDE_POLY16_C(  18140),  SIMDE_POLY16_C(  40280),  SIMDE_POLY16_C(  51771),  SIMDE_POLY16_C(  60250)  },
      {  SIMDE_POLY16_C(   1674),  SIMDE_POLY16_C(  38459),  SIMDE_POLY16_C(  42308),  SIMDE_POLY16_C(  33475),  SIMDE_POLY16_C(  27676),  SIMDE_POLY16_C(  54552),  SIMDE_POLY16_C(  41019),  SIMDE_POLY16_C(  46362)  },
      {  SIMDE_POLY16_C(  10890),  SIMDE_POLY16_C(  44603),  SIMDE_POLY16_C(  14660),  SIMDE_POLY16_C(   7875),  SIMDE_POLY16_C(  31772),  SIMDE_POLY16_C(  44312),  SIMDE_POLY16_C(   3131),  SIMDE_POLY16_C(  45338)  },
      {  SIMDE_POLY16_C(  35466),  SIMDE_POLY16_C(  52795),  SIMDE_POLY16_C(  47428),  SIMDE_POLY16_C(  24259),  SIMDE_POLY16_C(  39964),  SIMDE_POLY16_C(  36120),  SIMDE_POLY16_C(  27707),  SIMDE_POLY16_C(  45338)  } },
    { {  SIMDE_POLY16_C(  20622),  SIMDE_POLY16_C(  35405),  SIMDE_POLY16_C(  42684),  SIMDE_POLY16_C(  64877),  SIMDE_POLY16_C(  29368),  SIMDE_POLY16_C(  10266),  SIMDE_POLY16_C(  24647),  SIMDE_POLY16_C(  64280)  },
      {  SIMDE_POLY16_C(  31576),  SIMDE_POLY16_C(  19446),  SIMDE_POLY16_C(  44288),  SIMDE_POLY16_C(  56822),  SIMDE_POLY16_C(  32174),  SIMDE_POLY16_C(  17103),  SIMDE_POLY16_C(  18667),  SIMDE_POLY16_C(  20678)  },
      {  SIMDE_POLY16_C(  56006),  SIMDE_POLY16_C(  24501),  SIMDE_POLY16_C(  26628),  SIMDE_POLY16_C(  61365),  SIMDE_POLY16_C(  60784),  SIMDE_POLY16_C(   5754),  SIMDE_POLY16_C(  18271),  SIMDE_POLY16_C(  34352)  },
      {  SIMDE_POLY16_C(  54798),  SIMDE_POLY16_C(  64909),  SIMDE_POLY16_C(  16444),  SIMDE_POLY16_C(  32173),  SIMDE_POLY16_C(  27576),  SIMDE_POLY16_C(  46042),  SIMDE_POLY16_C(  15047),  SIMDE_POLY16_C(  12696)  },
      {  SIMDE_POLY16_C(  24718),  SIMDE_POLY16_C(  55885),  SIMDE_POLY16_C(    700),  SIMDE_POLY16_C(  55661),  SIMDE_POLY16_C(  47800),  SIMDE_POLY16_C(  15386),  SIMDE_POLY16_C(  44103),  SIMDE_POLY16_C(   6936)  },
      {  SIMDE_POLY16_C(   4238),  SIMDE_POLY16_C(  51789),  SIMDE_POLY16_C(   1724),  SIMDE_POLY16_C(  56685),  SIMDE_POLY16_C(  53944),  SIMDE_POLY16_C(  59418),  SIMDE_POLY16_C(  24647),  SIMDE_POLY16_C(  56088)  },
      {  SIMDE_POLY16_C(  20622),  SIMDE_POLY16_C(   2637),  SIMDE_POLY16_C(   9916),  SIMDE_POLY16_C(  32109),  SIMDE_POLY16_C(  29368),  SIMDE_POLY16_C(  43034),  SIMDE_POLY16_C(  57415),  SIMDE_POLY16_C(  31512)  } },
    { {  SIMDE_POLY16_C(  47232),  SIMDE_POLY16_C(    355),  SIMDE_POLY16_C(  64050),  SIMDE_POLY16_C(  59843),  SIMDE_POLY16_C(   9532),  SIMDE_POLY16_C(  42900),  SIMDE_POLY16_C(  36704),  SIMDE_POLY16_C(  46935)  },
      {  SIMDE_POLY16_C(  18854),  SIMDE_POLY16_C(  61891),  SIMDE_POLY16_C(  57306),  SIMDE_POLY16_C(  15820),  SIMDE_POLY16_C(  62408),  SIMDE_POLY16_C(  25140),  SIMDE_POLY16_C(   4068),  SIMDE_POLY16_C(  24825)  },
      {  SIMDE_POLY16_C(  19760),  SIMDE_POLY16_C(  36379),  SIMDE_POLY16_C(  65234),  SIMDE_POLY16_C(  61027),  SIMDE_POLY16_C(  40516),  SIMDE_POLY16_C(   4516),  SIMDE_POLY16_C(  32544),  SIMDE_POLY16_C(   1999)  },
      {  SIMDE_POLY16_C(  27008),  SIMDE_POLY16_C(  28899),  SIMDE_POLY16_C(  63154),  SIMDE_POLY16_C(  29443),  SIMDE_POLY16_C(  62012),  SIMDE_POLY16_C(  36116),  SIMDE_POLY16_C(  63776),  SIMDE_POLY16_C(  15959)  },
      {  SIMDE_POLY16_C(  39040),  SIMDE_POLY16_C(   3427),  SIMDE_POLY16_C(  27186),  SIMDE_POLY16_C(  12739),  SIMDE_POLY16_C(   8508),  SIMDE_POLY16_C(  54164),  SIMDE_POLY16_C(  37728),  SIMDE_POLY16_C(  59223)  },
      {  SIMDE_POLY16_C(  55424),  SIMDE_POLY16_C(  24931),  SIMDE_POLY16_C(  23090),  SIMDE_POLY16_C(  35267),  SIMDE_POLY16_C(   1340),  SIMDE_POLY16_C(  34708),  SIMDE_POLY16_C(  36704),  SIMDE_POLY16_C(  14167)  },
      {  SIMDE_POLY16_C(  14464),  SIMDE_POLY16_C(  33123),  SIMDE_POLY16_C(  31282),  SIMDE_POLY16_C(  27075),  SIMDE_POLY16_C(   9532),  SIMDE_POLY16_C(  10132),  SIMDE_POLY16_C(   3936),  SIMDE_POLY16_C(  46935)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8_t a = simde_vld1q_p16(test_vec[i].a);
    simde_poly16x8_t b = simde_vld1q_p16(test_vec[i].b);

    simde_poly16x8_t r3 = simde_vsliq_n_p16(a, b, 3);
    simde_poly16x8_t r6 = simde_vsliq_n_p16(a, b, 6);
    simde_poly16x8_t r10 = simde_vsliq_n_p16(a, b, 10);
    simde_poly16x8_t r13 = simde_vsliq_n_p16(a, b, 13);
    simde_poly16x8_t r15 = simde_vsliq_n_p16(a, b, 15);

    simde_test_arm_neon_assert_equal_p16x8(r3, simde_vld1q_p16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_p16x8(r6, simde_vld1q_p16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_p16x8(r10, simde_vld1q_p16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_p16x8(r13, simde_vld1q_p16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_p16x8(r15, simde_vld1q_p16(test_vec[i].r15));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x8_t a = simde_test_arm_neon_random_p16x8();
    simde_poly16x8_t b = simde_test_arm_neon_random_p16x8();
    simde_poly16x8_t r3 = simde_vsliq_n_p16(a, b, 3);
    simde_poly16x8_t r6 = simde_vsliq_n_p16(a, b, 6);
    simde_poly16x8_t r10 = simde_vsliq_n_p16(a, b, 10);
    simde_poly16x8_t r13 = simde_vsliq_n_p16(a, b, 13);
    simde_poly16x8_t r15 = simde_vsliq_n_p16(a, b, 15);

    simde_test_arm_neon_write_p16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly64_t a[2];
    simde_poly64_t b[2];
    simde_poly64_t r13[2];
    simde_poly64_t r26[2];
    simde_poly64_t r39[2];
    simde_poly64_t r52[2];
    simde_poly64_t r63[2];
  } test_vec[] = {
    { {  SIMDE_POLY64_C( 3326354101924670590),  SIMDE_POLY64_C(15812941646549698216)  },
      {  SIMDE_POLY64_C(18151090002998169439),  SIMDE_POLY64_C( 1380667824062628123)  },
      {  SIMDE_POLY64_C(12972070462018022526),  SIMDE_POLY64_C( 2576697537094444712)  },
      {  SIMDE_POLY64_C(13955360284637015166),  SIMDE_POLY64_C( 5231003553959724712)  },
      {  SIMDE_POLY64_C( 7838427115654622334),  SIMDE_POLY64_C(  594630893316032168)  },
      {  SIMDE_POLY64_C(17724362110628146302),  SIMDE_POLY64_C( 1275322049397737128)  },
      {  SIMDE_POLY64_C(12549726138779446398),  SIMDE_POLY64_C(15812941646549698216)  } },
    { {  SIMDE_POLY64_C( 5869328896938516263),  SIMDE_POLY64_C( 2222189733952536719)  },
      {  SIMDE_POLY64_C(12411628851339405478),  SIMDE_POLY64_C(  942836641027284248)  },
      {  SIMDE_POLY64_C(16056959959070727975),  SIMDE_POLY64_C(12978740484919984271)  },
      {  SIMDE_POLY64_C(13330739158301581095),  SIMDE_POLY64_C(13255955676427108495)  },
      {  SIMDE_POLY64_C(  690267940543831847),  SIMDE_POLY64_C(15253283237737447567)  },
      {  SIMDE_POLY64_C( 9972108157473038119),  SIMDE_POLY64_C(15097981068604784783)  },
      {  SIMDE_POLY64_C( 5869328896938516263),  SIMDE_POLY64_C( 2222189733952536719)  } },
    { {  SIMDE_POLY64_C(15272376107936314541),  SIMDE_POLY64_C( 7392787741455680135)  },
      {  SIMDE_POLY64_C( 9420840874243141019),  SIMDE_POLY64_C( 6038106548576691917)  },
      {  SIMDE_POLY64_C(12797981472756823213),  SIMDE_POLY64_C( 8447984324952302215)  },
      {  SIMDE_POLY64_C( 8217653932499203245),  SIMDE_POLY64_C(12150569524748616327)  },
      {  SIMDE_POLY64_C( 6851890001671943341),  SIMDE_POLY64_C(17281269205359133319)  },
      {  SIMDE_POLY64_C(15686707273654400173),  SIMDE_POLY64_C( 7843147704192729735)  },
      {  SIMDE_POLY64_C(15272376107936314541),  SIMDE_POLY64_C(16616159778310455943)  } },
    { {  SIMDE_POLY64_C(17788547161097733072),  SIMDE_POLY64_C(10303315733532817032)  },
      {  SIMDE_POLY64_C( 9530739437947880088),  SIMDE_POLY64_C( 9539080515559423601)  },
      {  SIMDE_POLY64_C( 9196555730211242960),  SIMDE_POLY64_C( 3739687229137499784)  },
      {  SIMDE_POLY64_C( 1681744860744483792),  SIMDE_POLY64_C(13922618736527455880)  },
      {  SIMDE_POLY64_C(15582820183151182800),  SIMDE_POLY64_C(16320825774362506888)  },
      {  SIMDE_POLY64_C( 2994222385185653712),  SIMDE_POLY64_C(16653391208125216392)  },
      {  SIMDE_POLY64_C( 8565175124242957264),  SIMDE_POLY64_C(10303315733532817032)  } },
    { {  SIMDE_POLY64_C(11269734078394947120),  SIMDE_POLY64_C(11079511464515323691)  },
      {  SIMDE_POLY64_C( 4631258017608531081),  SIMDE_POLY64_C( 2950484057785924872)  },
      {  SIMDE_POLY64_C(12759864702248498736),  SIMDE_POLY64_C( 5130664822783936299)  },
      {  SIMDE_POLY64_C( 9559719181400167984),  SIMDE_POLY64_C( 8723228335687976747)  },
      {  SIMDE_POLY64_C( 6790941082614519344),  SIMDE_POLY64_C(16446728547236431659)  },
      {  SIMDE_POLY64_C(14453779014945887792),  SIMDE_POLY64_C(15024664738091878187)  },
      {  SIMDE_POLY64_C(11269734078394947120),  SIMDE_POLY64_C( 1856139427660547883)  } },
    { {  SIMDE_POLY64_C( 7998503011676121860),  SIMDE_POLY64_C(12436442786690204518)  },
      {  SIMDE_POLY64_C(10507257933463575756),  SIMDE_POLY64_C(  890983024616133747)  },
      {  SIMDE_POLY64_C( 2949143004844755716),  SIMDE_POLY64_C(12469028540094767974)  },
      {  SIMDE_POLY64_C(12591503202443651844),  SIMDE_POLY64_C( 6659864326580700006)  },
      {  SIMDE_POLY64_C(13848118176700230404),  SIMDE_POLY64_C(10586337451585012582)  },
      {  SIMDE_POLY64_C(14753902452731865860),  SIMDE_POLY64_C( 5131604191095260006)  },
      {  SIMDE_POLY64_C( 7998503011676121860),  SIMDE_POLY64_C(12436442786690204518)  } },
    { {  SIMDE_POLY64_C(10515578012670966780),  SIMDE_POLY64_C(17680525830101447828)  },
      {  SIMDE_POLY64_C(11288336922296194998),  SIMDE_POLY64_C(16689682725274606802)  },
      {  SIMDE_POLY64_C(  528025944447179772),  SIMDE_POLY64_C(13060555188091901076)  },
      {  SIMDE_POLY64_C( 9050423663222406140),  SIMDE_POLY64_C(  952473333433152660)  },
      {  SIMDE_POLY64_C( 3606217256912632828),  SIMDE_POLY64_C(18135548271896081556)  },
      {  SIMDE_POLY64_C( 8894282146817588220),  SIMDE_POLY64_C(14784711269702218900)  },
      {  SIMDE_POLY64_C( 1292205975816190972),  SIMDE_POLY64_C( 8457153793246672020)  } },
    { {  SIMDE_POLY64_C( 2303077286822012679),  SIMDE_POLY64_C(  138581218363046567)  },
      {  SIMDE_POLY64_C(18411670028825252116),  SIMDE_POLY64_C( 8225054175440624625)  },
      {  SIMDE_POLY64_C( 7821329487171323655),  SIMDE_POLY64_C(12134448022314433191)  },
      {  SIMDE_POLY64_C( 6788990914251187975),  SIMDE_POLY64_C(14341129652734655143)  },
      {  SIMDE_POLY64_C(16926931031184631559),  SIMDE_POLY64_C(13667854094844426919)  },
      {  SIMDE_POLY64_C( 1244731374389946119),  SIMDE_POLY64_C(13770977290413537959)  },
      {  SIMDE_POLY64_C( 2303077286822012679),  SIMDE_POLY64_C( 9361953255217822375)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2_t a = simde_vld1q_p64(test_vec[i].a);
    simde_poly64x2_t b = simde_vld1q_p64(test_vec[i].b);

    simde_poly64x2_t r13 = simde_vsliq_n_p64(a, b, 13);
    simde_poly64x2_t r26 = simde_vsliq_n_p64(a, b, 26);
    simde_poly64x2_t r39 = simde_vsliq_n_p64(a, b, 39);
    simde_poly64x2_t r52 = simde_vsliq_n_p64(a, b, 52);
    simde_poly64x2_t r63 = simde_vsliq_n_p64(a, b, 63);

    simde_test_arm_neon_assert_equal_p64x2(r13, simde_vld1q_p64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_p64x2(r26, simde_vld1q_p64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_p64x2(r39, simde_vld1q_p64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_p64x2(r52, simde_vld1q_p64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_p64x2(r63, simde_vld1q_p64(test_vec[i].r63));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x2_t a = simde_test_arm_neon_random_p64x2();
    simde_poly64x2_t b = simde_test_arm_neon_random_p64x2();
    simde_poly64x2_t r13 = simde_vsliq_n_p64(a, b, 13);
    simde_poly64x2_t r26 = simde_vsliq_n_p64(a, b, 26);
    simde_poly64x2_t r39 = simde_vsliq_n_p64(a, b, 39);
    simde_poly64x2_t r52 = simde_vsliq_n_p64(a, b, 52);
    simde_poly64x2_t r63 = simde_vsliq_n_p64(a, b, 63);

    simde_test_arm_neon_write_p64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vslid_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vslid_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_p64)
SIMDE_TEST_FUNC_LIST_END

#include <test/arm/neon/test-neon-footer.h>
