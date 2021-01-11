#define SIMDE_TEST_ARM_NEON_INSN addlv

#include "test-neon.h"
#include "../../../simde/arm/neon/addlv.h"

static int
test_simde_vaddlv_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int16_t r;
  } test_vec[] = {
    { { -INT8_C(  78),  INT8_C( 109),  INT8_C( 126),  INT8_C( 107), -INT8_C(  63), -INT8_C(  93), -INT8_C( 101),  INT8_C(   9) },
       INT16_C(    16) },
    { {  INT8_C(  77), -INT8_C(  96), -INT8_C(  92), -INT8_C(  35), -INT8_C(  11),  INT8_C(  95),  INT8_C(  28), -INT8_C(  74) },
      -INT16_C(   108) },
    { {  INT8_C(  20), -INT8_C(  83),  INT8_C(  94), -INT8_C( 114), -INT8_C(  15),  INT8_C(  30),  INT8_C( 119), -INT8_C(  22) },
       INT16_C(    29) },
    { { -INT8_C(  61),  INT8_C(  72),  INT8_C(  20),  INT8_C(  67),  INT8_C(  26), -INT8_C(   4), -INT8_C(  83), -INT8_C(  52) },
      -INT16_C(    15) },
    { {  INT8_C( 106),  INT8_C(  43),  INT8_C(  55),  INT8_C(  43), -INT8_C(  50), -INT8_C(  46),  INT8_C(  52),  INT8_C(  27) },
       INT16_C(   230) },
    { {  INT8_C( 115), -INT8_C(  40), -INT8_C(   8),  INT8_C( 104),  INT8_C(  56),  INT8_C(  20),  INT8_C(  30),  INT8_C(  76) },
       INT16_C(   353) },
    { { -INT8_C(  63),  INT8_C( 125), -INT8_C(  38), -INT8_C(  77), -INT8_C( 101),  INT8_C(  82), -INT8_C(  99),  INT8_C(  94) },
      -INT16_C(    77) },
    { { -INT8_C( 102), -INT8_C(  78), -INT8_C(  94), -INT8_C(  76), -INT8_C(  82),  INT8_C(  79),      INT8_MIN,  INT8_C(  24) },
      -INT16_C(   457) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    int16_t r = simde_vaddlv_s8(a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    int16_t r = simde_vaddlv_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddlv_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int32_t r;
  } test_vec[] = {
    { { -INT16_C( 19550),  INT16_C( 29884), -INT16_C(  7291), -INT16_C(  2131) },
       INT32_C(         912) },
    { {  INT16_C( 13054), -INT16_C(  2007), -INT16_C( 13158),  INT16_C( 16493) },
       INT32_C(       14382) },
    { { -INT16_C(  7107),  INT16_C( 30925),  INT16_C( 14119), -INT16_C( 31939) },
       INT32_C(        5998) },
    { {  INT16_C( 24111),  INT16_C( 13090),  INT16_C( 16713), -INT16_C(  4995) },
       INT32_C(       48919) },
    { {  INT16_C( 14836),  INT16_C( 31072),  INT16_C(  3612),  INT16_C(  7024) },
       INT32_C(       56544) },
    { { -INT16_C( 26048), -INT16_C(  9453), -INT16_C( 32410), -INT16_C( 23525) },
      -INT32_C(       91436) },
    { { -INT16_C(  6043), -INT16_C( 29668),  INT16_C( 22815),  INT16_C( 20239) },
       INT32_C(        7343) },
    { {  INT16_C( 12728),  INT16_C(   386),  INT16_C(   114),  INT16_C( 26605) },
       INT32_C(       39833) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    int32_t r = simde_vaddlv_s16(a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    int32_t r = simde_vaddlv_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddlv_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int64_t r;
  } test_vec[] = {
    { {  INT32_C(  1457540665), -INT32_C(  1670295204) },
      -INT64_C(           212754539) },
    { {  INT32_C(  1366787307),  INT32_C(  1794478853) },
       INT64_C(          3161266160) },
    { { -INT32_C(  1678306693),  INT32_C(   602539627) },
      -INT64_C(          1075767066) },
    { { -INT32_C(  1440388040), -INT32_C(  1508830612) },
      -INT64_C(          2949218652) },
    { { -INT32_C(  1124273568),  INT32_C(   777612611) },
      -INT64_C(           346660957) },
    { { -INT32_C(   142618383), -INT32_C(   547261085) },
      -INT64_C(           689879468) },
    { { -INT32_C(   226862969), -INT32_C(  1760140193) },
      -INT64_C(          1987003162) },
    { {  INT32_C(  1027685328), -INT32_C(  1360833715) },
      -INT64_C(           333148387) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    int64_t r = simde_vaddlv_s32(a);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    int64_t r = simde_vaddlv_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddlv_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint16_t r;
  } test_vec[] = {
    { { UINT8_C(107), UINT8_C( 47), UINT8_C(217), UINT8_C(215), UINT8_C(241), UINT8_C( 96), UINT8_C( 52), UINT8_C(181) },
      UINT16_C( 1156) },
    { { UINT8_C( 98), UINT8_C( 32), UINT8_C(246), UINT8_C( 32), UINT8_C(105), UINT8_C(238), UINT8_C(215), UINT8_C( 33) },
      UINT16_C(  999) },
    { { UINT8_C(133), UINT8_C(  3), UINT8_C(237), UINT8_C(178), UINT8_C( 19), UINT8_C(160), UINT8_C(131), UINT8_C( 32) },
      UINT16_C(  893) },
    { { UINT8_C( 15), UINT8_C(239), UINT8_C( 87), UINT8_C( 27), UINT8_C( 41), UINT8_C(191), UINT8_C( 83), UINT8_C(148) },
      UINT16_C(  831) },
    { { UINT8_C(238), UINT8_C( 44), UINT8_C(108), UINT8_C(224), UINT8_C(141), UINT8_C(160), UINT8_C(149), UINT8_C(239) },
      UINT16_C( 1303) },
    { { UINT8_C(193), UINT8_C(139), UINT8_C( 15), UINT8_C( 42), UINT8_C(122), UINT8_C(231), UINT8_C( 75),    UINT8_MAX },
      UINT16_C( 1072) },
    { { UINT8_C(234), UINT8_C( 56), UINT8_C(178), UINT8_C(253), UINT8_C(216), UINT8_C( 53), UINT8_C( 29), UINT8_C(231) },
      UINT16_C( 1250) },
    { { UINT8_C( 37), UINT8_C(116), UINT8_C(  3), UINT8_C( 78), UINT8_C( 52), UINT8_C( 86), UINT8_C(226), UINT8_C( 34) },
      UINT16_C(  632) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    uint16_t r = simde_vaddlv_u8(a);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    uint16_t r = simde_vaddlv_u8(a);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddlv_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint32_t r;
  } test_vec[] = {
    { { UINT16_C(19874), UINT16_C(36903), UINT16_C(35701), UINT16_C(56826) },
      UINT32_C(    149304) },
    { { UINT16_C(45372), UINT16_C(61062), UINT16_C(47626), UINT16_C(36771) },
      UINT32_C(    190831) },
    { { UINT16_C( 3731), UINT16_C(47398), UINT16_C(48710), UINT16_C(58267) },
      UINT32_C(    158106) },
    { { UINT16_C(53737), UINT16_C( 6609), UINT16_C(64523), UINT16_C(44340) },
      UINT32_C(    169209) },
    { { UINT16_C(23369), UINT16_C(48957), UINT16_C(14566), UINT16_C( 9116) },
      UINT32_C(     96008) },
    { { UINT16_C( 8937), UINT16_C(62225), UINT16_C(46300), UINT16_C(28802) },
      UINT32_C(    146264) },
    { { UINT16_C(43202), UINT16_C( 2345), UINT16_C(50534), UINT16_C(20460) },
      UINT32_C(    116541) },
    { { UINT16_C(48534), UINT16_C(41320), UINT16_C(40121), UINT16_C(  846) },
      UINT32_C(    130821) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    uint32_t r = simde_vaddlv_u16(a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    uint32_t r = simde_vaddlv_u16(a);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddlv_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint64_t r;
  } test_vec[] = {
    { { UINT32_C(3737292024), UINT32_C(2902548164) },
      UINT64_C(          6639840188) },
    { { UINT32_C(1570771584), UINT32_C(2311922375) },
      UINT64_C(          3882693959) },
    { { UINT32_C( 814937802), UINT32_C(1384087227) },
      UINT64_C(          2199025029) },
    { { UINT32_C(4126402364), UINT32_C(2096644740) },
      UINT64_C(          6223047104) },
    { { UINT32_C(2455419598), UINT32_C(2571066392) },
      UINT64_C(          5026485990) },
    { { UINT32_C( 905371502), UINT32_C(3418342145) },
      UINT64_C(          4323713647) },
    { { UINT32_C(1979404729), UINT32_C( 214399696) },
      UINT64_C(          2193804425) },
    { { UINT32_C(3842095713), UINT32_C(3395418876) },
      UINT64_C(          7237514589) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    uint64_t r = simde_vaddlv_u32(a);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    uint64_t r = simde_vaddlv_u32(a);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddlvq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int16_t r;
  } test_vec[] = {
    { {  INT8_C(  26),  INT8_C(  76),  INT8_C(  48), -INT8_C(  60),  INT8_C(   4),  INT8_C(  76),  INT8_C(   1),  INT8_C(  45),
         INT8_C( 109), -INT8_C(  21), -INT8_C( 125),  INT8_C(  90),      INT8_MAX,  INT8_C(  31), -INT8_C(  75),  INT8_C( 124) },
       INT16_C(   476) },
    { { -INT8_C(  32), -INT8_C(  51),  INT8_C( 109),  INT8_C(  25), -INT8_C(  97),  INT8_C( 120),  INT8_C(  95),  INT8_C(  30),
        -INT8_C(  66),  INT8_C(  10), -INT8_C(  97),  INT8_C(  92),  INT8_C( 119),  INT8_C( 111), -INT8_C(  40), -INT8_C( 111) },
       INT16_C(   217) },
    { { -INT8_C(  69),  INT8_C(   8),  INT8_C(  86), -INT8_C(  65),  INT8_C(  85),  INT8_C(  87), -INT8_C(  19), -INT8_C(  62),
         INT8_C(  66),  INT8_C( 112),  INT8_C(  29), -INT8_C(  63), -INT8_C( 113), -INT8_C(  46),  INT8_C(  62),  INT8_C( 112) },
       INT16_C(   210) },
    { { -INT8_C(  97), -INT8_C(  85), -INT8_C( 119),  INT8_C(  63),  INT8_C(  35), -INT8_C(  23),  INT8_C(  93), -INT8_C(  30),
        -INT8_C(  13), -INT8_C(   4),  INT8_C(  62),  INT8_C( 106),  INT8_C( 107),  INT8_C(  22), -INT8_C(   4),  INT8_C(  38) },
       INT16_C(   151) },
    { {  INT8_C(  30),  INT8_C(  82), -INT8_C(  26),  INT8_C( 115), -INT8_C(  87), -INT8_C(  45),  INT8_C(  54), -INT8_C(  21),
         INT8_C(  67),  INT8_C(  83), -INT8_C(  84), -INT8_C(  46),  INT8_C(  37), -INT8_C(  22),  INT8_C(  66), -INT8_C(  60) },
       INT16_C(   143) },
    { { -INT8_C( 107), -INT8_C(  52),  INT8_C(   3), -INT8_C(  71), -INT8_C(  75),  INT8_C(  96), -INT8_C( 101), -INT8_C(  88),
         INT8_C(  93), -INT8_C(  39),  INT8_C(  19), -INT8_C(  56), -INT8_C(  17),  INT8_C(  15), -INT8_C(  17),  INT8_C(  13) },
      -INT16_C(   384) },
    { {  INT8_C(  97), -INT8_C(  43), -INT8_C( 127),  INT8_C(  10), -INT8_C(  88), -INT8_C(  73), -INT8_C(  11), -INT8_C(  21),
         INT8_C(  10), -INT8_C(  95), -INT8_C(  67),  INT8_C(  47), -INT8_C( 116),  INT8_C(   0), -INT8_C(  13),  INT8_C(  33) },
      -INT16_C(   457) },
    { { -INT8_C(  52), -INT8_C(   9), -INT8_C(  38), -INT8_C( 127),  INT8_C(  87),  INT8_C( 117),  INT8_C(  41), -INT8_C(  76),
         INT8_C(  78),  INT8_C(  60),  INT8_C( 125),  INT8_C(  61),  INT8_C(  75),  INT8_C( 108),  INT8_C(  75), -INT8_C(  84) },
       INT16_C(   441) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    int16_t r = simde_vaddlvq_s8(a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    int16_t r = simde_vaddlvq_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddlvq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int32_t r;
  } test_vec[] = {
    { { -INT16_C( 13247), -INT16_C(  5706), -INT16_C( 21629), -INT16_C( 29228), -INT16_C( 28339), -INT16_C(  9796), -INT16_C( 20591),  INT16_C( 24058) },
      -INT32_C(      104478) },
    { { -INT16_C( 10842), -INT16_C(   290),  INT16_C(  2122), -INT16_C( 26190),  INT16_C( 12100), -INT16_C( 28458),  INT16_C(  8603), -INT16_C(  9156) },
      -INT32_C(       52111) },
    { { -INT16_C(  3091),  INT16_C( 28869), -INT16_C( 26210), -INT16_C(  5123), -INT16_C( 18133), -INT16_C( 17212), -INT16_C( 16535),  INT16_C(  3866) },
      -INT32_C(       53569) },
    { { -INT16_C(  1900), -INT16_C(  8691), -INT16_C( 16384),  INT16_C( 17783),  INT16_C( 20207), -INT16_C( 29739),  INT16_C(  4463),  INT16_C( 23911) },
       INT32_C(        9650) },
    { {  INT16_C( 11524), -INT16_C( 23603), -INT16_C( 13370), -INT16_C(  3698),  INT16_C( 21380), -INT16_C(  4690), -INT16_C( 14318), -INT16_C( 22787) },
      -INT32_C(       49562) },
    { {  INT16_C(  2752), -INT16_C( 15996), -INT16_C(   822), -INT16_C( 17914), -INT16_C(  9398), -INT16_C( 18107), -INT16_C( 21268), -INT16_C(  3818) },
      -INT32_C(       84571) },
    { { -INT16_C(  6951), -INT16_C( 24428),  INT16_C(  8879),  INT16_C( 13201),  INT16_C( 16245), -INT16_C( 30943),  INT16_C(  7687), -INT16_C( 14291) },
      -INT32_C(       30601) },
    { { -INT16_C( 19928), -INT16_C(  3191), -INT16_C( 28754), -INT16_C(  1875), -INT16_C(  3478),  INT16_C( 22193), -INT16_C( 14178),  INT16_C( 30791) },
      -INT32_C(       18420) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    int32_t r = simde_vaddlvq_s16(a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    int32_t r = simde_vaddlvq_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddlvq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int64_t r;
  } test_vec[] = {
    { {  INT32_C(  1528355756),  INT32_C(  1938729470), -INT32_C(   251940887), -INT32_C(   155703091) },
       INT64_C(          3059441248) },
    { { -INT32_C(  1997979174),  INT32_C(   981505744),  INT32_C(   647049864), -INT32_C(  1499539206) },
      -INT64_C(          1868962772) },
    { { -INT32_C(  1308510540),  INT32_C(  1227198304),  INT32_C(   205070399),  INT32_C(   587395657) },
       INT64_C(           711153820) },
    { {  INT32_C(    78441267),  INT32_C(   155069569),  INT32_C(  1479593822),  INT32_C(  1560202920) },
       INT64_C(          3273307578) },
    { { -INT32_C(   452001915), -INT32_C(   835832945), -INT32_C(  1646631084), -INT32_C(  1916740263) },
      -INT64_C(          4851206207) },
    { {  INT32_C(  1251044552), -INT32_C(   145502311),  INT32_C(  1196458911), -INT32_C(   677163438) },
       INT64_C(          1624837714) },
    { { -INT32_C(   574836402),  INT32_C(   950790884), -INT32_C(  1412070063),  INT32_C(   725128802) },
      -INT64_C(           310986779) },
    { { -INT32_C(  1686779646),  INT32_C(   932432024), -INT32_C(  1635851444),  INT32_C(  2138382641) },
      -INT64_C(           251816425) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    int64_t r = simde_vaddlvq_s32(a);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    int64_t r = simde_vaddlvq_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddlvq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint16_t r;
  } test_vec[] = {
    { { UINT8_C(210), UINT8_C( 49), UINT8_C( 92), UINT8_C(183), UINT8_C( 27), UINT8_C(  7), UINT8_C(239), UINT8_C(108),
        UINT8_C(141), UINT8_C(197), UINT8_C( 23), UINT8_C(239), UINT8_C( 91), UINT8_C( 79), UINT8_C( 26), UINT8_C( 93) },
      UINT16_C( 1804) },
    { { UINT8_C( 24), UINT8_C(143), UINT8_C(249), UINT8_C(177), UINT8_C( 88), UINT8_C(140), UINT8_C(232), UINT8_C(164),
        UINT8_C(111), UINT8_C(103), UINT8_C( 66), UINT8_C(160), UINT8_C(136), UINT8_C(183), UINT8_C( 32), UINT8_C( 91) },
      UINT16_C( 2099) },
    { { UINT8_C(232), UINT8_C(124), UINT8_C( 18), UINT8_C(  3), UINT8_C(132), UINT8_C(  1), UINT8_C(111), UINT8_C( 17),
        UINT8_C(198), UINT8_C(135), UINT8_C(  0), UINT8_C( 33), UINT8_C(214), UINT8_C( 27), UINT8_C(127), UINT8_C(239) },
      UINT16_C( 1611) },
    { { UINT8_C(170), UINT8_C(120), UINT8_C(160), UINT8_C(  2), UINT8_C(  4), UINT8_C(136), UINT8_C(166), UINT8_C(115),
        UINT8_C(239), UINT8_C(232), UINT8_C( 19), UINT8_C(120), UINT8_C(159), UINT8_C( 51), UINT8_C(211), UINT8_C(135) },
      UINT16_C( 2039) },
    { { UINT8_C(176), UINT8_C(229), UINT8_C(138), UINT8_C( 52), UINT8_C(230), UINT8_C(250), UINT8_C( 69), UINT8_C(173),
        UINT8_C(129), UINT8_C( 69), UINT8_C(206), UINT8_C( 87), UINT8_C( 96), UINT8_C( 77), UINT8_C( 70), UINT8_C( 11) },
      UINT16_C( 2062) },
    { { UINT8_C(197), UINT8_C(230), UINT8_C( 13), UINT8_C(201), UINT8_C(111), UINT8_C(180), UINT8_C( 60), UINT8_C( 94),
        UINT8_C(156), UINT8_C( 80), UINT8_C(214), UINT8_C( 60), UINT8_C(131), UINT8_C(169), UINT8_C(195), UINT8_C( 51) },
      UINT16_C( 2142) },
    { { UINT8_C(142), UINT8_C( 78), UINT8_C(103), UINT8_C(117), UINT8_C( 72), UINT8_C(172), UINT8_C( 34), UINT8_C(201),
        UINT8_C(242), UINT8_C(240), UINT8_C( 32), UINT8_C( 82), UINT8_C( 62), UINT8_C(103), UINT8_C( 93), UINT8_C(  3) },
      UINT16_C( 1776) },
    { { UINT8_C( 77), UINT8_C(107), UINT8_C(205), UINT8_C(188), UINT8_C( 31), UINT8_C(  9), UINT8_C( 27), UINT8_C(187),
        UINT8_C( 89), UINT8_C(241), UINT8_C(247), UINT8_C(221), UINT8_C(155), UINT8_C(187), UINT8_C( 16), UINT8_C( 41) },
      UINT16_C( 2028) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    uint16_t r = simde_vaddlvq_u8(a);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    uint16_t r = simde_vaddlvq_u8(a);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddlvq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint32_t r;
  } test_vec[] = {
    { { UINT16_C(30729), UINT16_C(20894), UINT16_C(49188), UINT16_C( 5658), UINT16_C(15025), UINT16_C(61289), UINT16_C(50849), UINT16_C(61426) },
      UINT32_C(    295058) },
    { { UINT16_C(48945), UINT16_C(20651), UINT16_C(50889), UINT16_C( 8716), UINT16_C(  952), UINT16_C(21503), UINT16_C( 4286), UINT16_C(51068) },
      UINT32_C(    207010) },
    { { UINT16_C( 7048), UINT16_C(44056), UINT16_C(13019), UINT16_C(36035), UINT16_C(11373), UINT16_C( 3707), UINT16_C(28402), UINT16_C( 9469) },
      UINT32_C(    153109) },
    { { UINT16_C(43309), UINT16_C(63092), UINT16_C(32879), UINT16_C(10009), UINT16_C( 6276), UINT16_C(17018), UINT16_C(63272), UINT16_C(45066) },
      UINT32_C(    280921) },
    { { UINT16_C( 8722), UINT16_C(60765), UINT16_C( 8277), UINT16_C(49786), UINT16_C(62796), UINT16_C(16080), UINT16_C(52835), UINT16_C(37218) },
      UINT32_C(    296479) },
    { { UINT16_C(55159), UINT16_C(59015), UINT16_C(41047), UINT16_C(56078), UINT16_C(35001), UINT16_C(57630), UINT16_C(10367), UINT16_C(37266) },
      UINT32_C(    351563) },
    { { UINT16_C(61258), UINT16_C(40831), UINT16_C(63759), UINT16_C(23393), UINT16_C(13038), UINT16_C(21145), UINT16_C(64512), UINT16_C(30691) },
      UINT32_C(    318627) },
    { { UINT16_C(27347), UINT16_C(10845), UINT16_C(27403), UINT16_C(50182), UINT16_C( 9460), UINT16_C(29605), UINT16_C(14156), UINT16_C(38405) },
      UINT32_C(    207403) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    uint32_t r = simde_vaddlvq_u16(a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    uint32_t r = simde_vaddlvq_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddlvq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint64_t r;
  } test_vec[] = {
    { { UINT32_C( 892765222), UINT32_C(1804638077), UINT32_C(3384617673), UINT32_C(4181762086) },
      UINT64_C(         10263783058) },
    { { UINT32_C( 371432971), UINT32_C(4258933001), UINT32_C(2574352205), UINT32_C(3710940855) },
      UINT64_C(         10915659032) },
    { { UINT32_C(1997760250), UINT32_C(3353519101), UINT32_C(4086341837), UINT32_C(1273811264) },
      UINT64_C(         10711432452) },
    { { UINT32_C(2019627119), UINT32_C(2272672569), UINT32_C(1914759099), UINT32_C(1464815709) },
      UINT64_C(          7671874496) },
    { { UINT32_C(3033424566), UINT32_C(3548098566), UINT32_C(2445740880), UINT32_C(1272755164) },
      UINT64_C(         10300019176) },
    { { UINT32_C(4257496771), UINT32_C( 881080953), UINT32_C(2124850209), UINT32_C(2882926325) },
      UINT64_C(         10146354258) },
    { { UINT32_C(1583326040), UINT32_C(2754796115), UINT32_C(3258317286), UINT32_C(1879970220) },
      UINT64_C(          9476409661) },
    { { UINT32_C(3379417679), UINT32_C( 771617036), UINT32_C(2326504597), UINT32_C(4063658138) },
      UINT64_C(         10541197450) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    uint64_t r = simde_vaddlvq_u32(a);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    uint64_t r = simde_vaddlvq_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vaddlv_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddlv_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddlv_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddlv_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddlv_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddlv_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddlvq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddlvq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddlvq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddlvq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddlvq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddlvq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
