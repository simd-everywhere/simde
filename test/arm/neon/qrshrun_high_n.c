#define SIMDE_TEST_ARM_NEON_INSN qrshrun_high_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qrshrun_high_n.h"

static int
test_simde_vqrshrun_high_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    uint8_t r[8];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r8[16];
  } test_vec[] = {
    { { -INT16_C(  26901),  INT16_C(  24912), -INT16_C(  23060),  INT16_C(  11637),  INT16_C(  29762), -INT16_C(  28735),  INT16_C(  31144), -INT16_C(  31799) },
      {  UINT8_C( 154),  UINT8_C(  89),  UINT8_C( 202),  UINT8_C( 149),  UINT8_C( 247),  UINT8_C( 250),  UINT8_C( 171),  UINT8_C( 107)  },
      {  UINT8_C( 154),  UINT8_C(  89),  UINT8_C( 202),  UINT8_C( 149),  UINT8_C( 247),  UINT8_C( 250),  UINT8_C( 171),  UINT8_C( 107),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0)  },
      {  UINT8_C( 154),  UINT8_C(  89),  UINT8_C( 202),  UINT8_C( 149),  UINT8_C( 247),  UINT8_C( 250),  UINT8_C( 171),  UINT8_C( 107),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0)  },
      {  UINT8_C( 154),  UINT8_C(  89),  UINT8_C( 202),  UINT8_C( 149),  UINT8_C( 247),  UINT8_C( 250),  UINT8_C( 171),  UINT8_C( 107),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0)  },
      {  UINT8_C( 154),  UINT8_C(  89),  UINT8_C( 202),  UINT8_C( 149),  UINT8_C( 247),  UINT8_C( 250),  UINT8_C( 171),  UINT8_C( 107),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),  UINT8_C( 182),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0)  },
      {  UINT8_C( 154),  UINT8_C(  89),  UINT8_C( 202),  UINT8_C( 149),  UINT8_C( 247),  UINT8_C( 250),  UINT8_C( 171),  UINT8_C( 107),  UINT8_C(   0),  UINT8_C(  97),  UINT8_C(   0),  UINT8_C(  45),  UINT8_C( 116),  UINT8_C(   0),  UINT8_C( 122),  UINT8_C(   0)  } },
    { {  INT16_C(  24401), -INT16_C(   2085),  INT16_C(  30663),  INT16_C(  29805),  INT16_C(   4918), -INT16_C(  25820), -INT16_C(   9103),  INT16_C(  17542) },
      {  UINT8_C( 245),  UINT8_C( 174),  UINT8_C(  88),  UINT8_C(  87),  UINT8_C(  50),  UINT8_C(  88),  UINT8_C(  33),  UINT8_C(  18)  },
      {  UINT8_C( 245),  UINT8_C( 174),  UINT8_C(  88),  UINT8_C(  87),  UINT8_C(  50),  UINT8_C(  88),  UINT8_C(  33),  UINT8_C(  18),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),  UINT8_C(   0),      UINT8_MAX  },
      {  UINT8_C( 245),  UINT8_C( 174),  UINT8_C(  88),  UINT8_C(  87),  UINT8_C(  50),  UINT8_C(  88),  UINT8_C(  33),  UINT8_C(  18),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),  UINT8_C(   0),      UINT8_MAX  },
      {  UINT8_C( 245),  UINT8_C( 174),  UINT8_C(  88),  UINT8_C(  87),  UINT8_C(  50),  UINT8_C(  88),  UINT8_C(  33),  UINT8_C(  18),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,  UINT8_C( 154),  UINT8_C(   0),  UINT8_C(   0),      UINT8_MAX  },
      {  UINT8_C( 245),  UINT8_C( 174),  UINT8_C(  88),  UINT8_C(  87),  UINT8_C(  50),  UINT8_C(  88),  UINT8_C(  33),  UINT8_C(  18),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,  UINT8_C(  77),  UINT8_C(   0),  UINT8_C(   0),      UINT8_MAX  },
      {  UINT8_C( 245),  UINT8_C( 174),  UINT8_C(  88),  UINT8_C(  87),  UINT8_C(  50),  UINT8_C(  88),  UINT8_C(  33),  UINT8_C(  18),  UINT8_C(  95),  UINT8_C(   0),  UINT8_C( 120),  UINT8_C( 116),  UINT8_C(  19),  UINT8_C(   0),  UINT8_C(   0),  UINT8_C(  69)  } },
    { {  INT16_C(   1440),  INT16_C(  15455),  INT16_C(  29476),  INT16_C(   6151), -INT16_C(  10272),  INT16_C(   6729), -INT16_C(  10868), -INT16_C(  27237) },
      {  UINT8_C( 218),  UINT8_C(  81),  UINT8_C(  95),  UINT8_C( 255),  UINT8_C( 146),  UINT8_C( 139),  UINT8_C( 110),  UINT8_C( 243)  },
      {  UINT8_C( 218),  UINT8_C(  81),  UINT8_C(  95),      UINT8_MAX,  UINT8_C( 146),  UINT8_C( 139),  UINT8_C( 110),  UINT8_C( 243),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),  UINT8_C(   0)  },
      {  UINT8_C( 218),  UINT8_C(  81),  UINT8_C(  95),      UINT8_MAX,  UINT8_C( 146),  UINT8_C( 139),  UINT8_C( 110),  UINT8_C( 243),  UINT8_C( 180),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),  UINT8_C(   0)  },
      {  UINT8_C( 218),  UINT8_C(  81),  UINT8_C(  95),      UINT8_MAX,  UINT8_C( 146),  UINT8_C( 139),  UINT8_C( 110),  UINT8_C( 243),  UINT8_C(  45),      UINT8_MAX,      UINT8_MAX,  UINT8_C( 192),  UINT8_C(   0),  UINT8_C( 210),  UINT8_C(   0),  UINT8_C(   0)  },
      {  UINT8_C( 218),  UINT8_C(  81),  UINT8_C(  95),      UINT8_MAX,  UINT8_C( 146),  UINT8_C( 139),  UINT8_C( 110),  UINT8_C( 243),  UINT8_C(  23),  UINT8_C( 241),      UINT8_MAX,  UINT8_C(  96),  UINT8_C(   0),  UINT8_C( 105),  UINT8_C(   0),  UINT8_C(   0)  },
      {  UINT8_C( 218),  UINT8_C(  81),  UINT8_C(  95),      UINT8_MAX,  UINT8_C( 146),  UINT8_C( 139),  UINT8_C( 110),  UINT8_C( 243),  UINT8_C(   6),  UINT8_C(  60),  UINT8_C( 115),  UINT8_C(  24),  UINT8_C(   0),  UINT8_C(  26),  UINT8_C(   0),  UINT8_C(   0)  } },
    { { -INT16_C(  26011),  INT16_C(  29256), -INT16_C(   4522),  INT16_C(  13968),  INT16_C(  12300),  INT16_C(   2638), -INT16_C(  10285),  INT16_C(   1479) },
      {  UINT8_C(  46),  UINT8_C( 201),  UINT8_C( 162),  UINT8_C(   0),  UINT8_C(  40),  UINT8_C(  76),  UINT8_C( 118),  UINT8_C( 177)  },
      {  UINT8_C(  46),  UINT8_C( 201),  UINT8_C( 162),  UINT8_C(   0),  UINT8_C(  40),  UINT8_C(  76),  UINT8_C( 118),  UINT8_C( 177),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX  },
      {  UINT8_C(  46),  UINT8_C( 201),  UINT8_C( 162),  UINT8_C(   0),  UINT8_C(  40),  UINT8_C(  76),  UINT8_C( 118),  UINT8_C( 177),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),  UINT8_C( 185)  },
      {  UINT8_C(  46),  UINT8_C( 201),  UINT8_C( 162),  UINT8_C(   0),  UINT8_C(  40),  UINT8_C(  76),  UINT8_C( 118),  UINT8_C( 177),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,  UINT8_C(  82),  UINT8_C(   0),  UINT8_C(  46)  },
      {  UINT8_C(  46),  UINT8_C( 201),  UINT8_C( 162),  UINT8_C(   0),  UINT8_C(  40),  UINT8_C(  76),  UINT8_C( 118),  UINT8_C( 177),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),  UINT8_C( 218),  UINT8_C( 192),  UINT8_C(  41),  UINT8_C(   0),  UINT8_C(  23)  },
      {  UINT8_C(  46),  UINT8_C( 201),  UINT8_C( 162),  UINT8_C(   0),  UINT8_C(  40),  UINT8_C(  76),  UINT8_C( 118),  UINT8_C( 177),  UINT8_C(   0),  UINT8_C( 114),  UINT8_C(   0),  UINT8_C(  55),  UINT8_C(  48),  UINT8_C(  10),  UINT8_C(   0),  UINT8_C(   6)  } },
    { { -INT16_C(  22025), -INT16_C(   8648),  INT16_C(  27418), -INT16_C(   6829),  INT16_C(  15803), -INT16_C(   8520),  INT16_C(   7722),  INT16_C(  12519) },
      {  UINT8_C(  62),  UINT8_C( 106),  UINT8_C( 236),  UINT8_C( 116),  UINT8_C( 113),  UINT8_C( 139),  UINT8_C( 132),  UINT8_C(  27)  },
      {  UINT8_C(  62),  UINT8_C( 106),  UINT8_C( 236),  UINT8_C( 116),  UINT8_C( 113),  UINT8_C( 139),  UINT8_C( 132),  UINT8_C(  27),  UINT8_C(   0),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  62),  UINT8_C( 106),  UINT8_C( 236),  UINT8_C( 116),  UINT8_C( 113),  UINT8_C( 139),  UINT8_C( 132),  UINT8_C(  27),  UINT8_C(   0),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  62),  UINT8_C( 106),  UINT8_C( 236),  UINT8_C( 116),  UINT8_C( 113),  UINT8_C( 139),  UINT8_C( 132),  UINT8_C(  27),  UINT8_C(   0),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),  UINT8_C( 241),      UINT8_MAX  },
      {  UINT8_C(  62),  UINT8_C( 106),  UINT8_C( 236),  UINT8_C( 116),  UINT8_C( 113),  UINT8_C( 139),  UINT8_C( 132),  UINT8_C(  27),  UINT8_C(   0),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),  UINT8_C( 247),  UINT8_C(   0),  UINT8_C( 121),  UINT8_C( 196)  },
      {  UINT8_C(  62),  UINT8_C( 106),  UINT8_C( 236),  UINT8_C( 116),  UINT8_C( 113),  UINT8_C( 139),  UINT8_C( 132),  UINT8_C(  27),  UINT8_C(   0),  UINT8_C(   0),  UINT8_C( 107),  UINT8_C(   0),  UINT8_C(  62),  UINT8_C(   0),  UINT8_C(  30),  UINT8_C(  49)  } },
    { {  INT16_C(   2745),  INT16_C(  14738), -INT16_C(   5721), -INT16_C(  30689),  INT16_C(   3405),  INT16_C(   8929),  INT16_C(     58), -INT16_C(   3352) },
      {  UINT8_C( 107),  UINT8_C( 100),  UINT8_C( 114),  UINT8_C(   2),  UINT8_C( 187),  UINT8_C( 235),  UINT8_C( 199),  UINT8_C(  76)  },
      {  UINT8_C( 107),  UINT8_C( 100),  UINT8_C( 114),  UINT8_C(   2),  UINT8_C( 187),  UINT8_C( 235),  UINT8_C( 199),  UINT8_C(  76),      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,  UINT8_C(  29),  UINT8_C(   0)  },
      {  UINT8_C( 107),  UINT8_C( 100),  UINT8_C( 114),  UINT8_C(   2),  UINT8_C( 187),  UINT8_C( 235),  UINT8_C( 199),  UINT8_C(  76),      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,  UINT8_C(   7),  UINT8_C(   0)  },
      {  UINT8_C( 107),  UINT8_C( 100),  UINT8_C( 114),  UINT8_C(   2),  UINT8_C( 187),  UINT8_C( 235),  UINT8_C( 199),  UINT8_C(  76),  UINT8_C(  86),      UINT8_MAX,  UINT8_C(   0),  UINT8_C(   0),  UINT8_C( 106),      UINT8_MAX,  UINT8_C(   2),  UINT8_C(   0)  },
      {  UINT8_C( 107),  UINT8_C( 100),  UINT8_C( 114),  UINT8_C(   2),  UINT8_C( 187),  UINT8_C( 235),  UINT8_C( 199),  UINT8_C(  76),  UINT8_C(  43),  UINT8_C( 230),  UINT8_C(   0),  UINT8_C(   0),  UINT8_C(  53),  UINT8_C( 140),  UINT8_C(   1),  UINT8_C(   0)  },
      {  UINT8_C( 107),  UINT8_C( 100),  UINT8_C( 114),  UINT8_C(   2),  UINT8_C( 187),  UINT8_C( 235),  UINT8_C( 199),  UINT8_C(  76),  UINT8_C(  11),  UINT8_C(  58),  UINT8_C(   0),  UINT8_C(   0),  UINT8_C(  13),  UINT8_C(  35),  UINT8_C(   0),  UINT8_C(   0)  } },
    { { -INT16_C(   6193),  INT16_C(   8857),  INT16_C(  26831), -INT16_C(   2865),  INT16_C(   7898),  INT16_C(  31948), -INT16_C(  25650), -INT16_C(  24171) },
      {  UINT8_C( 124),  UINT8_C(  47),  UINT8_C(   3),  UINT8_C( 133),  UINT8_C( 190),  UINT8_C( 204),  UINT8_C(  29),  UINT8_C( 234)  },
      {  UINT8_C( 124),  UINT8_C(  47),  UINT8_C(   3),  UINT8_C( 133),  UINT8_C( 190),  UINT8_C( 204),  UINT8_C(  29),  UINT8_C( 234),  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),  UINT8_C(   0)  },
      {  UINT8_C( 124),  UINT8_C(  47),  UINT8_C(   3),  UINT8_C( 133),  UINT8_C( 190),  UINT8_C( 204),  UINT8_C(  29),  UINT8_C( 234),  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),  UINT8_C(   0)  },
      {  UINT8_C( 124),  UINT8_C(  47),  UINT8_C(   3),  UINT8_C( 133),  UINT8_C( 190),  UINT8_C( 204),  UINT8_C(  29),  UINT8_C( 234),  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX,  UINT8_C(   0),  UINT8_C( 247),      UINT8_MAX,  UINT8_C(   0),  UINT8_C(   0)  },
      {  UINT8_C( 124),  UINT8_C(  47),  UINT8_C(   3),  UINT8_C( 133),  UINT8_C( 190),  UINT8_C( 204),  UINT8_C(  29),  UINT8_C( 234),  UINT8_C(   0),  UINT8_C( 138),      UINT8_MAX,  UINT8_C(   0),  UINT8_C( 123),      UINT8_MAX,  UINT8_C(   0),  UINT8_C(   0)  },
      {  UINT8_C( 124),  UINT8_C(  47),  UINT8_C(   3),  UINT8_C( 133),  UINT8_C( 190),  UINT8_C( 204),  UINT8_C(  29),  UINT8_C( 234),  UINT8_C(   0),  UINT8_C(  35),  UINT8_C( 105),  UINT8_C(   0),  UINT8_C(  31),  UINT8_C( 125),  UINT8_C(   0),  UINT8_C(   0)  } },
    { { -INT16_C(   1239), -INT16_C(   3301),  INT16_C(   3917), -INT16_C(  12085),  INT16_C(  14863), -INT16_C(   5705),  INT16_C(   9730),  INT16_C(   6678) },
      {  UINT8_C(  31),  UINT8_C(  43),  UINT8_C(  45),  UINT8_C( 150),  UINT8_C( 141),  UINT8_C( 252),  UINT8_C( 112),  UINT8_C( 129)  },
      {  UINT8_C(  31),  UINT8_C(  43),  UINT8_C(  45),  UINT8_C( 150),  UINT8_C( 141),  UINT8_C( 252),  UINT8_C( 112),  UINT8_C( 129),  UINT8_C(   0),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  31),  UINT8_C(  43),  UINT8_C(  45),  UINT8_C( 150),  UINT8_C( 141),  UINT8_C( 252),  UINT8_C( 112),  UINT8_C( 129),  UINT8_C(   0),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  31),  UINT8_C(  43),  UINT8_C(  45),  UINT8_C( 150),  UINT8_C( 141),  UINT8_C( 252),  UINT8_C( 112),  UINT8_C( 129),  UINT8_C(   0),  UINT8_C(   0),  UINT8_C( 122),  UINT8_C(   0),      UINT8_MAX,  UINT8_C(   0),      UINT8_MAX,  UINT8_C( 209)  },
      {  UINT8_C(  31),  UINT8_C(  43),  UINT8_C(  45),  UINT8_C( 150),  UINT8_C( 141),  UINT8_C( 252),  UINT8_C( 112),  UINT8_C( 129),  UINT8_C(   0),  UINT8_C(   0),  UINT8_C(  61),  UINT8_C(   0),  UINT8_C( 232),  UINT8_C(   0),  UINT8_C( 152),  UINT8_C( 104)  },
      {  UINT8_C(  31),  UINT8_C(  43),  UINT8_C(  45),  UINT8_C( 150),  UINT8_C( 141),  UINT8_C( 252),  UINT8_C( 112),  UINT8_C( 129),  UINT8_C(   0),  UINT8_C(   0),  UINT8_C(  15),  UINT8_C(   0),  UINT8_C(  58),  UINT8_C(   0),  UINT8_C(  38),  UINT8_C(  26)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_uint8x8_t r = simde_vld1_u8(test_vec[i].r);

    simde_uint8x16_t r1 = simde_vqrshrun_high_n_s16(r, a, 1);
    simde_uint8x16_t r3 = simde_vqrshrun_high_n_s16(r, a, 3);
    simde_uint8x16_t r5 = simde_vqrshrun_high_n_s16(r, a, 5);
    simde_uint8x16_t r6 = simde_vqrshrun_high_n_s16(r, a, 6);
    simde_uint8x16_t r8 = simde_vqrshrun_high_n_s16(r, a, 8);

    simde_test_arm_neon_assert_equal_u8x16(r1, simde_vld1q_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r6, simde_vld1q_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x16(r8, simde_vld1q_u8(test_vec[i].r8));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_uint8x8_t r = simde_test_arm_neon_random_u8x8();
    simde_uint8x16_t r1 = simde_vqrshrun_high_n_s16(r, a, 1);
    simde_uint8x16_t r3 = simde_vqrshrun_high_n_s16(r, a, 3);
    simde_uint8x16_t r5 = simde_vqrshrun_high_n_s16(r, a, 5);
    simde_uint8x16_t r6 = simde_vqrshrun_high_n_s16(r, a, 6);
    simde_uint8x16_t r8 = simde_vqrshrun_high_n_s16(r, a, 8);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r8, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshrun_high_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    uint16_t r[4];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r16[8];
  } test_vec[] = {
    { { -INT32_C(1363234875), -INT32_C( 417022877), -INT32_C( 258303598),  INT32_C(1951319462) },
      {  UINT16_C(  15475),  UINT16_C(  43243),  UINT16_C(  52233),  UINT16_C(  36093)  },
      {  UINT16_C(  15475),  UINT16_C(  43243),  UINT16_C(  52233),  UINT16_C(  36093),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),         UINT16_MAX  },
      {  UINT16_C(  15475),  UINT16_C(  43243),  UINT16_C(  52233),  UINT16_C(  36093),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),         UINT16_MAX  },
      {  UINT16_C(  15475),  UINT16_C(  43243),  UINT16_C(  52233),  UINT16_C(  36093),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),         UINT16_MAX  },
      {  UINT16_C(  15475),  UINT16_C(  43243),  UINT16_C(  52233),  UINT16_C(  36093),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),         UINT16_MAX  },
      {  UINT16_C(  15475),  UINT16_C(  43243),  UINT16_C(  52233),  UINT16_C(  36093),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(  29775)  } },
    { { -INT32_C(1053233509), -INT32_C(1268107216), -INT32_C(2036943405), -INT32_C( 350219836) },
      {  UINT16_C(  36487),  UINT16_C(  65004),  UINT16_C(  33777),  UINT16_C(  51946)  },
      {  UINT16_C(  36487),  UINT16_C(  65004),  UINT16_C(  33777),  UINT16_C(  51946),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(  36487),  UINT16_C(  65004),  UINT16_C(  33777),  UINT16_C(  51946),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(  36487),  UINT16_C(  65004),  UINT16_C(  33777),  UINT16_C(  51946),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(  36487),  UINT16_C(  65004),  UINT16_C(  33777),  UINT16_C(  51946),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(  36487),  UINT16_C(  65004),  UINT16_C(  33777),  UINT16_C(  51946),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0)  } },
    { { -INT32_C( 786909360), -INT32_C(1579932703),  INT32_C(1606062187),  INT32_C( 838808178) },
      {  UINT16_C(  52851),  UINT16_C(  16940),  UINT16_C(  39624),  UINT16_C(  45766)  },
      {  UINT16_C(  52851),  UINT16_C(  16940),  UINT16_C(  39624),  UINT16_C(  45766),  UINT16_C(      0),  UINT16_C(      0),         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  52851),  UINT16_C(  16940),  UINT16_C(  39624),  UINT16_C(  45766),  UINT16_C(      0),  UINT16_C(      0),         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  52851),  UINT16_C(  16940),  UINT16_C(  39624),  UINT16_C(  45766),  UINT16_C(      0),  UINT16_C(      0),         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  52851),  UINT16_C(  16940),  UINT16_C(  39624),  UINT16_C(  45766),  UINT16_C(      0),  UINT16_C(      0),         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  52851),  UINT16_C(  16940),  UINT16_C(  39624),  UINT16_C(  45766),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(  24507),  UINT16_C(  12799)  } },
    { { -INT32_C(2051899715),  INT32_C(1170898446),  INT32_C(1151727967),  INT32_C(2128278906) },
      {  UINT16_C(  25343),  UINT16_C(  36824),  UINT16_C(  54187),  UINT16_C(  53942)  },
      {  UINT16_C(  25343),  UINT16_C(  36824),  UINT16_C(  54187),  UINT16_C(  53942),  UINT16_C(      0),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  25343),  UINT16_C(  36824),  UINT16_C(  54187),  UINT16_C(  53942),  UINT16_C(      0),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  25343),  UINT16_C(  36824),  UINT16_C(  54187),  UINT16_C(  53942),  UINT16_C(      0),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  25343),  UINT16_C(  36824),  UINT16_C(  54187),  UINT16_C(  53942),  UINT16_C(      0),         UINT16_MAX,         UINT16_MAX,         UINT16_MAX  },
      {  UINT16_C(  25343),  UINT16_C(  36824),  UINT16_C(  54187),  UINT16_C(  53942),  UINT16_C(      0),  UINT16_C(  17866),  UINT16_C(  17574),  UINT16_C(  32475)  } },
    { {  INT32_C(2121284719),  INT32_C( 132979968), -INT32_C(1351241229), -INT32_C(1056295181) },
      {  UINT16_C(  48579),  UINT16_C(  61937),  UINT16_C(  45916),  UINT16_C(  45509)  },
      {  UINT16_C(  48579),  UINT16_C(  61937),  UINT16_C(  45916),  UINT16_C(  45509),         UINT16_MAX,         UINT16_MAX,  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(  48579),  UINT16_C(  61937),  UINT16_C(  45916),  UINT16_C(  45509),         UINT16_MAX,         UINT16_MAX,  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(  48579),  UINT16_C(  61937),  UINT16_C(  45916),  UINT16_C(  45509),         UINT16_MAX,         UINT16_MAX,  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(  48579),  UINT16_C(  61937),  UINT16_C(  45916),  UINT16_C(  45509),         UINT16_MAX,  UINT16_C(  16233),  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(  48579),  UINT16_C(  61937),  UINT16_C(  45916),  UINT16_C(  45509),  UINT16_C(  32368),  UINT16_C(   2029),  UINT16_C(      0),  UINT16_C(      0)  } },
    { { -INT32_C(1284406174), -INT32_C(1229648600), -INT32_C(2034326506), -INT32_C(1122523652) },
      {  UINT16_C(   4801),  UINT16_C(   9858),  UINT16_C(  54817),  UINT16_C(  11429)  },
      {  UINT16_C(   4801),  UINT16_C(   9858),  UINT16_C(  54817),  UINT16_C(  11429),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(   4801),  UINT16_C(   9858),  UINT16_C(  54817),  UINT16_C(  11429),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(   4801),  UINT16_C(   9858),  UINT16_C(  54817),  UINT16_C(  11429),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(   4801),  UINT16_C(   9858),  UINT16_C(  54817),  UINT16_C(  11429),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(   4801),  UINT16_C(   9858),  UINT16_C(  54817),  UINT16_C(  11429),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0),  UINT16_C(      0)  } },
    { { -INT32_C(1887739279),  INT32_C(2111374391),  INT32_C( 588014740), -INT32_C(1460994965) },
      {  UINT16_C(   1614),  UINT16_C(  44820),  UINT16_C(   9628),  UINT16_C(  56371)  },
      {  UINT16_C(   1614),  UINT16_C(  44820),  UINT16_C(   9628),  UINT16_C(  56371),  UINT16_C(      0),         UINT16_MAX,         UINT16_MAX,  UINT16_C(      0)  },
      {  UINT16_C(   1614),  UINT16_C(  44820),  UINT16_C(   9628),  UINT16_C(  56371),  UINT16_C(      0),         UINT16_MAX,         UINT16_MAX,  UINT16_C(      0)  },
      {  UINT16_C(   1614),  UINT16_C(  44820),  UINT16_C(   9628),  UINT16_C(  56371),  UINT16_C(      0),         UINT16_MAX,         UINT16_MAX,  UINT16_C(      0)  },
      {  UINT16_C(   1614),  UINT16_C(  44820),  UINT16_C(   9628),  UINT16_C(  56371),  UINT16_C(      0),         UINT16_MAX,         UINT16_MAX,  UINT16_C(      0)  },
      {  UINT16_C(   1614),  UINT16_C(  44820),  UINT16_C(   9628),  UINT16_C(  56371),  UINT16_C(      0),  UINT16_C(  32217),  UINT16_C(   8972),  UINT16_C(      0)  } },
    { { -INT32_C(1056644303),  INT32_C(1476868805), -INT32_C(2146154485), -INT32_C( 936697718) },
      {  UINT16_C(  41652),  UINT16_C(  63603),  UINT16_C(  12915),  UINT16_C(  44147)  },
      {  UINT16_C(  41652),  UINT16_C(  63603),  UINT16_C(  12915),  UINT16_C(  44147),  UINT16_C(      0),         UINT16_MAX,  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(  41652),  UINT16_C(  63603),  UINT16_C(  12915),  UINT16_C(  44147),  UINT16_C(      0),         UINT16_MAX,  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(  41652),  UINT16_C(  63603),  UINT16_C(  12915),  UINT16_C(  44147),  UINT16_C(      0),         UINT16_MAX,  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(  41652),  UINT16_C(  63603),  UINT16_C(  12915),  UINT16_C(  44147),  UINT16_C(      0),         UINT16_MAX,  UINT16_C(      0),  UINT16_C(      0)  },
      {  UINT16_C(  41652),  UINT16_C(  63603),  UINT16_C(  12915),  UINT16_C(  44147),  UINT16_C(      0),  UINT16_C(  22535),  UINT16_C(      0),  UINT16_C(      0)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_uint16x4_t r = simde_vld1_u16(test_vec[i].r);

    simde_uint16x8_t r3 = simde_vqrshrun_high_n_s32(r, a, 3);
    simde_uint16x8_t r6 = simde_vqrshrun_high_n_s32(r, a, 6);
    simde_uint16x8_t r10 = simde_vqrshrun_high_n_s32(r, a, 10);
    simde_uint16x8_t r13 = simde_vqrshrun_high_n_s32(r, a, 13);
    simde_uint16x8_t r16 = simde_vqrshrun_high_n_s32(r, a, 16);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r16, simde_vld1q_u16(test_vec[i].r16));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_uint16x4_t r = simde_test_arm_neon_random_u16x4();
    simde_uint16x8_t r3 = simde_vqrshrun_high_n_s32(r, a, 3);
    simde_uint16x8_t r6 = simde_vqrshrun_high_n_s32(r, a, 6);
    simde_uint16x8_t r10 = simde_vqrshrun_high_n_s32(r, a, 10);
    simde_uint16x8_t r13 = simde_vqrshrun_high_n_s32(r, a, 13);
    simde_uint16x8_t r16 = simde_vqrshrun_high_n_s32(r, a, 16);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshrun_high_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    uint32_t r[2];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r32[4];
  } test_vec[] = {
    { {  INT64_C(6922806263380053875), -INT64_C(8099866424266803793) },
      {  UINT32_C(  760640094),  UINT32_C(  594382363)  },
      {  UINT32_C(  760640094),  UINT32_C(  594382363),             UINT32_MAX,  UINT32_C(          0)  },
      {  UINT32_C(  760640094),  UINT32_C(  594382363),             UINT32_MAX,  UINT32_C(          0)  },
      {  UINT32_C(  760640094),  UINT32_C(  594382363),             UINT32_MAX,  UINT32_C(          0)  },
      {  UINT32_C(  760640094),  UINT32_C(  594382363),             UINT32_MAX,  UINT32_C(          0)  },
      {  UINT32_C(  760640094),  UINT32_C(  594382363),  UINT32_C( 1611841438),  UINT32_C(          0)  } },
    { { -INT64_C(2271711873451389669),  INT64_C(7783093147260015164) },
      {  UINT32_C( 2062287409),  UINT32_C(  405592575)  },
      {  UINT32_C( 2062287409),  UINT32_C(  405592575),  UINT32_C(          0),             UINT32_MAX  },
      {  UINT32_C( 2062287409),  UINT32_C(  405592575),  UINT32_C(          0),             UINT32_MAX  },
      {  UINT32_C( 2062287409),  UINT32_C(  405592575),  UINT32_C(          0),             UINT32_MAX  },
      {  UINT32_C( 2062287409),  UINT32_C(  405592575),  UINT32_C(          0),             UINT32_MAX  },
      {  UINT32_C( 2062287409),  UINT32_C(  405592575),  UINT32_C(          0),  UINT32_C( 1812142587)  } },
    { {  INT64_C(8517667088258568146),  INT64_C(270917303239280145) },
      {  UINT32_C( 3262654376),  UINT32_C( 2356467133)  },
      {  UINT32_C( 3262654376),  UINT32_C( 2356467133),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 3262654376),  UINT32_C( 2356467133),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 3262654376),  UINT32_C( 2356467133),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 3262654376),  UINT32_C( 2356467133),             UINT32_MAX,  UINT32_C( 4036982406)  },
      {  UINT32_C( 3262654376),  UINT32_C( 2356467133),  UINT32_C( 1983173911),  UINT32_C(   63077850)  } },
    { {  INT64_C(4853728554929975710), -INT64_C(4081064942288582998) },
      {  UINT32_C( 4281591674),  UINT32_C( 1973792079)  },
      {  UINT32_C( 4281591674),  UINT32_C( 1973792079),             UINT32_MAX,  UINT32_C(          0)  },
      {  UINT32_C( 4281591674),  UINT32_C( 1973792079),             UINT32_MAX,  UINT32_C(          0)  },
      {  UINT32_C( 4281591674),  UINT32_C( 1973792079),             UINT32_MAX,  UINT32_C(          0)  },
      {  UINT32_C( 4281591674),  UINT32_C( 1973792079),             UINT32_MAX,  UINT32_C(          0)  },
      {  UINT32_C( 4281591674),  UINT32_C( 1973792079),  UINT32_C( 1130096744),  UINT32_C(          0)  } },
    { {  INT64_C(3014540358851394141),  INT64_C(5706656414358883996) },
      {  UINT32_C( 4260730317),  UINT32_C( 4070936592)  },
      {  UINT32_C( 4260730317),  UINT32_C( 4070936592),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 4260730317),  UINT32_C( 4070936592),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 4260730317),  UINT32_C( 4070936592),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 4260730317),  UINT32_C( 4070936592),             UINT32_MAX,             UINT32_MAX  },
      {  UINT32_C( 4260730317),  UINT32_C( 4070936592),  UINT32_C(  701877372),  UINT32_C( 1328684486)  } },
    { { -INT64_C(7138003406927655947), -INT64_C(3703770648631034745) },
      {  UINT32_C( 2372538698),  UINT32_C( 2756569415)  },
      {  UINT32_C( 2372538698),  UINT32_C( 2756569415),  UINT32_C(          0),  UINT32_C(          0)  },
      {  UINT32_C( 2372538698),  UINT32_C( 2756569415),  UINT32_C(          0),  UINT32_C(          0)  },
      {  UINT32_C( 2372538698),  UINT32_C( 2756569415),  UINT32_C(          0),  UINT32_C(          0)  },
      {  UINT32_C( 2372538698),  UINT32_C( 2756569415),  UINT32_C(          0),  UINT32_C(          0)  },
      {  UINT32_C( 2372538698),  UINT32_C( 2756569415),  UINT32_C(          0),  UINT32_C(          0)  } },
    { {  INT64_C(6877059253522308642), -INT64_C(4587225836650138282) },
      {  UINT32_C(  271301593),  UINT32_C( 3580377968)  },
      {  UINT32_C(  271301593),  UINT32_C( 3580377968),             UINT32_MAX,  UINT32_C(          0)  },
      {  UINT32_C(  271301593),  UINT32_C( 3580377968),             UINT32_MAX,  UINT32_C(          0)  },
      {  UINT32_C(  271301593),  UINT32_C( 3580377968),             UINT32_MAX,  UINT32_C(          0)  },
      {  UINT32_C(  271301593),  UINT32_C( 3580377968),             UINT32_MAX,  UINT32_C(          0)  },
      {  UINT32_C(  271301593),  UINT32_C( 3580377968),  UINT32_C( 1601190132),  UINT32_C(          0)  } },
    { { -INT64_C(4940186427400519059),  INT64_C(3197242908979989750) },
      {  UINT32_C( 3107228164),  UINT32_C( 2643418518)  },
      {  UINT32_C( 3107228164),  UINT32_C( 2643418518),  UINT32_C(          0),             UINT32_MAX  },
      {  UINT32_C( 3107228164),  UINT32_C( 2643418518),  UINT32_C(          0),             UINT32_MAX  },
      {  UINT32_C( 3107228164),  UINT32_C( 2643418518),  UINT32_C(          0),             UINT32_MAX  },
      {  UINT32_C( 3107228164),  UINT32_C( 2643418518),  UINT32_C(          0),             UINT32_MAX  },
      {  UINT32_C( 3107228164),  UINT32_C( 2643418518),  UINT32_C(          0),  UINT32_C(  744416124)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_uint32x2_t r = simde_vld1_u32(test_vec[i].r);

    simde_uint32x4_t r6 = simde_vqrshrun_high_n_s64(r, a, 6);
    simde_uint32x4_t r13 = simde_vqrshrun_high_n_s64(r, a, 13);
    simde_uint32x4_t r19 = simde_vqrshrun_high_n_s64(r, a, 19);
    simde_uint32x4_t r26 = simde_vqrshrun_high_n_s64(r, a, 26);
    simde_uint32x4_t r32 = simde_vqrshrun_high_n_s64(r, a, 32);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r32, simde_vld1q_u32(test_vec[i].r32));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_uint32x2_t r = simde_test_arm_neon_random_u32x2();
    simde_uint32x4_t r6 = simde_vqrshrun_high_n_s64(r, a, 6);
    simde_uint32x4_t r13 = simde_vqrshrun_high_n_s64(r, a, 13);
    simde_uint32x4_t r19 = simde_vqrshrun_high_n_s64(r, a, 19);
    simde_uint32x4_t r26 = simde_vqrshrun_high_n_s64(r, a, 26);
    simde_uint32x4_t r32 = simde_vqrshrun_high_n_s64(r, a, 32);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrun_high_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrun_high_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrun_high_n_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
