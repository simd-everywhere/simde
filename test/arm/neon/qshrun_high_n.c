#define SIMDE_TEST_ARM_NEON_INSN qshrun_high_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qshrun_high_n.h"

static int
test_simde_vqshrun_high_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[8];
    uint8_t r[8];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r8[16];
  } test_vec[] = {
    { { -INT16_C(   27923), -INT16_C(   12199),  INT16_C(    4015), -INT16_C(    9015),
        -INT16_C(   14829), -INT16_C(   30768),  INT16_C(     531),  INT16_C(   10290) },
      {  UINT8_C(     172),  UINT8_C(     229),  UINT8_C(     170),  UINT8_C(     221),
         UINT8_C(      73),  UINT8_C(     185),  UINT8_C(     208),  UINT8_C(     193) },
      {  UINT8_C(     172),  UINT8_C(     229),  UINT8_C(     170),  UINT8_C(     221),
         UINT8_C(      73),  UINT8_C(     185),  UINT8_C(     208),  UINT8_C(     193),
         UINT8_C(       0),  UINT8_C(       0),          UINT8_MAX,  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),          UINT8_MAX,          UINT8_MAX },
      {  UINT8_C(     172),  UINT8_C(     229),  UINT8_C(     170),  UINT8_C(     221),
         UINT8_C(      73),  UINT8_C(     185),  UINT8_C(     208),  UINT8_C(     193),
         UINT8_C(       0),  UINT8_C(       0),          UINT8_MAX,  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(      66),          UINT8_MAX },
      {  UINT8_C(     172),  UINT8_C(     229),  UINT8_C(     170),  UINT8_C(     221),
         UINT8_C(      73),  UINT8_C(     185),  UINT8_C(     208),  UINT8_C(     193),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(     125),  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(      16),          UINT8_MAX },
      {  UINT8_C(     172),  UINT8_C(     229),  UINT8_C(     170),  UINT8_C(     221),
         UINT8_C(      73),  UINT8_C(     185),  UINT8_C(     208),  UINT8_C(     193),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(      62),  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       8),  UINT8_C(     160) },
      {  UINT8_C(     172),  UINT8_C(     229),  UINT8_C(     170),  UINT8_C(     221),
         UINT8_C(      73),  UINT8_C(     185),  UINT8_C(     208),  UINT8_C(     193),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(      15),  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       2),  UINT8_C(      40) } },
    { {  INT16_C(   14962),  INT16_C(   14828),  INT16_C(   21756), -INT16_C(   15564),
        -INT16_C(    4624), -INT16_C(   30580), -INT16_C(    3057), -INT16_C(    8780) },
      {  UINT8_C(     233),  UINT8_C(     105),  UINT8_C(      95),  UINT8_C(     239),
         UINT8_C(     114),  UINT8_C(       8),  UINT8_C(     131),  UINT8_C(     115) },
      {  UINT8_C(     233),  UINT8_C(     105),  UINT8_C(      95),  UINT8_C(     239),
         UINT8_C(     114),  UINT8_C(       8),  UINT8_C(     131),  UINT8_C(     115),
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0) },
      {  UINT8_C(     233),  UINT8_C(     105),  UINT8_C(      95),  UINT8_C(     239),
         UINT8_C(     114),  UINT8_C(       8),  UINT8_C(     131),  UINT8_C(     115),
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0) },
      {  UINT8_C(     233),  UINT8_C(     105),  UINT8_C(      95),  UINT8_C(     239),
         UINT8_C(     114),  UINT8_C(       8),  UINT8_C(     131),  UINT8_C(     115),
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0) },
      {  UINT8_C(     233),  UINT8_C(     105),  UINT8_C(      95),  UINT8_C(     239),
         UINT8_C(     114),  UINT8_C(       8),  UINT8_C(     131),  UINT8_C(     115),
         UINT8_C(     233),  UINT8_C(     231),          UINT8_MAX,  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0) },
      {  UINT8_C(     233),  UINT8_C(     105),  UINT8_C(      95),  UINT8_C(     239),
         UINT8_C(     114),  UINT8_C(       8),  UINT8_C(     131),  UINT8_C(     115),
         UINT8_C(      58),  UINT8_C(      57),  UINT8_C(      84),  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0) } },
    { {  INT16_C(    1448),  INT16_C(   23606), -INT16_C(   24732), -INT16_C(   20908),
        -INT16_C(   22280),  INT16_C(    5060),  INT16_C(    2624),  INT16_C(   25220) },
      {  UINT8_C(     210),  UINT8_C(     201),  UINT8_C(     221),  UINT8_C(     194),
         UINT8_C(     115),  UINT8_C(      33),  UINT8_C(      79),  UINT8_C(     226) },
      {  UINT8_C(     210),  UINT8_C(     201),  UINT8_C(     221),  UINT8_C(     194),
         UINT8_C(     115),  UINT8_C(      33),  UINT8_C(      79),  UINT8_C(     226),
                 UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),  UINT8_C(       0),
         UINT8_C(       0),          UINT8_MAX,          UINT8_MAX,          UINT8_MAX },
      {  UINT8_C(     210),  UINT8_C(     201),  UINT8_C(     221),  UINT8_C(     194),
         UINT8_C(     115),  UINT8_C(      33),  UINT8_C(      79),  UINT8_C(     226),
         UINT8_C(     181),          UINT8_MAX,  UINT8_C(       0),  UINT8_C(       0),
         UINT8_C(       0),          UINT8_MAX,          UINT8_MAX,          UINT8_MAX },
      {  UINT8_C(     210),  UINT8_C(     201),  UINT8_C(     221),  UINT8_C(     194),
         UINT8_C(     115),  UINT8_C(      33),  UINT8_C(      79),  UINT8_C(     226),
         UINT8_C(      45),          UINT8_MAX,  UINT8_C(       0),  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(     158),  UINT8_C(      82),          UINT8_MAX },
      {  UINT8_C(     210),  UINT8_C(     201),  UINT8_C(     221),  UINT8_C(     194),
         UINT8_C(     115),  UINT8_C(      33),  UINT8_C(      79),  UINT8_C(     226),
         UINT8_C(      22),          UINT8_MAX,  UINT8_C(       0),  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(      79),  UINT8_C(      41),          UINT8_MAX },
      {  UINT8_C(     210),  UINT8_C(     201),  UINT8_C(     221),  UINT8_C(     194),
         UINT8_C(     115),  UINT8_C(      33),  UINT8_C(      79),  UINT8_C(     226),
         UINT8_C(       5),  UINT8_C(      92),  UINT8_C(       0),  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(      19),  UINT8_C(      10),  UINT8_C(      98) } },
    { { -INT16_C(    8737),  INT16_C(   20706), -INT16_C(   13018), -INT16_C(   32167),
         INT16_C(   31623), -INT16_C(   13929),  INT16_C(   10418),  INT16_C(   13081) },
      {  UINT8_C(     217),  UINT8_C(     174),  UINT8_C(     171),  UINT8_C(     220),
         UINT8_C(     144),  UINT8_C(     221),  UINT8_C(      12),  UINT8_C(      90) },
      {  UINT8_C(     217),  UINT8_C(     174),  UINT8_C(     171),  UINT8_C(     220),
         UINT8_C(     144),  UINT8_C(     221),  UINT8_C(      12),  UINT8_C(      90),
         UINT8_C(       0),          UINT8_MAX,  UINT8_C(       0),  UINT8_C(       0),
                 UINT8_MAX,  UINT8_C(       0),          UINT8_MAX,          UINT8_MAX },
      {  UINT8_C(     217),  UINT8_C(     174),  UINT8_C(     171),  UINT8_C(     220),
         UINT8_C(     144),  UINT8_C(     221),  UINT8_C(      12),  UINT8_C(      90),
         UINT8_C(       0),          UINT8_MAX,  UINT8_C(       0),  UINT8_C(       0),
                 UINT8_MAX,  UINT8_C(       0),          UINT8_MAX,          UINT8_MAX },
      {  UINT8_C(     217),  UINT8_C(     174),  UINT8_C(     171),  UINT8_C(     220),
         UINT8_C(     144),  UINT8_C(     221),  UINT8_C(      12),  UINT8_C(      90),
         UINT8_C(       0),          UINT8_MAX,  UINT8_C(       0),  UINT8_C(       0),
                 UINT8_MAX,  UINT8_C(       0),          UINT8_MAX,          UINT8_MAX },
      {  UINT8_C(     217),  UINT8_C(     174),  UINT8_C(     171),  UINT8_C(     220),
         UINT8_C(     144),  UINT8_C(     221),  UINT8_C(      12),  UINT8_C(      90),
         UINT8_C(       0),          UINT8_MAX,  UINT8_C(       0),  UINT8_C(       0),
                 UINT8_MAX,  UINT8_C(       0),  UINT8_C(     162),  UINT8_C(     204) },
      {  UINT8_C(     217),  UINT8_C(     174),  UINT8_C(     171),  UINT8_C(     220),
         UINT8_C(     144),  UINT8_C(     221),  UINT8_C(      12),  UINT8_C(      90),
         UINT8_C(       0),  UINT8_C(      80),  UINT8_C(       0),  UINT8_C(       0),
         UINT8_C(     123),  UINT8_C(       0),  UINT8_C(      40),  UINT8_C(      51) } },
    { {  INT16_C(   31068),  INT16_C(     596),  INT16_C(   19992),  INT16_C(   18282),
         INT16_C(   13776),  INT16_C(   19602),  INT16_C(   20155), -INT16_C(   25900) },
      {  UINT8_C(     178),  UINT8_C(      95),  UINT8_C(     126),  UINT8_C(     243),
         UINT8_C(     161),  UINT8_C(     175),  UINT8_C(     219),  UINT8_C(     152) },
      {  UINT8_C(     178),  UINT8_C(      95),  UINT8_C(     126),  UINT8_C(     243),
         UINT8_C(     161),  UINT8_C(     175),  UINT8_C(     219),  UINT8_C(     152),
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,          UINT8_MAX,
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,  UINT8_C(       0) },
      {  UINT8_C(     178),  UINT8_C(      95),  UINT8_C(     126),  UINT8_C(     243),
         UINT8_C(     161),  UINT8_C(     175),  UINT8_C(     219),  UINT8_C(     152),
                 UINT8_MAX,  UINT8_C(      74),          UINT8_MAX,          UINT8_MAX,
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,  UINT8_C(       0) },
      {  UINT8_C(     178),  UINT8_C(      95),  UINT8_C(     126),  UINT8_C(     243),
         UINT8_C(     161),  UINT8_C(     175),  UINT8_C(     219),  UINT8_C(     152),
                 UINT8_MAX,  UINT8_C(      18),          UINT8_MAX,          UINT8_MAX,
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,  UINT8_C(       0) },
      {  UINT8_C(     178),  UINT8_C(      95),  UINT8_C(     126),  UINT8_C(     243),
         UINT8_C(     161),  UINT8_C(     175),  UINT8_C(     219),  UINT8_C(     152),
                 UINT8_MAX,  UINT8_C(       9),          UINT8_MAX,          UINT8_MAX,
         UINT8_C(     215),          UINT8_MAX,          UINT8_MAX,  UINT8_C(       0) },
      {  UINT8_C(     178),  UINT8_C(      95),  UINT8_C(     126),  UINT8_C(     243),
         UINT8_C(     161),  UINT8_C(     175),  UINT8_C(     219),  UINT8_C(     152),
         UINT8_C(     121),  UINT8_C(       2),  UINT8_C(      78),  UINT8_C(      71),
         UINT8_C(      53),  UINT8_C(      76),  UINT8_C(      78),  UINT8_C(       0) } },
    { {  INT16_C(   27010),  INT16_C(   20005), -INT16_C(   13816), -INT16_C(    4717),
        -INT16_C(   27086), -INT16_C(   22355), -INT16_C(     671),  INT16_C(   19704) },
      {  UINT8_C(      73),  UINT8_C(     252),  UINT8_C(     253),  UINT8_C(     140),
         UINT8_C(     145),  UINT8_C(     113),  UINT8_C(     226),  UINT8_C(     245) },
      {  UINT8_C(      73),  UINT8_C(     252),  UINT8_C(     253),  UINT8_C(     140),
         UINT8_C(     145),  UINT8_C(     113),  UINT8_C(     226),  UINT8_C(     245),
                 UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),          UINT8_MAX },
      {  UINT8_C(      73),  UINT8_C(     252),  UINT8_C(     253),  UINT8_C(     140),
         UINT8_C(     145),  UINT8_C(     113),  UINT8_C(     226),  UINT8_C(     245),
                 UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),          UINT8_MAX },
      {  UINT8_C(      73),  UINT8_C(     252),  UINT8_C(     253),  UINT8_C(     140),
         UINT8_C(     145),  UINT8_C(     113),  UINT8_C(     226),  UINT8_C(     245),
                 UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),          UINT8_MAX },
      {  UINT8_C(      73),  UINT8_C(     252),  UINT8_C(     253),  UINT8_C(     140),
         UINT8_C(     145),  UINT8_C(     113),  UINT8_C(     226),  UINT8_C(     245),
                 UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),          UINT8_MAX },
      {  UINT8_C(      73),  UINT8_C(     252),  UINT8_C(     253),  UINT8_C(     140),
         UINT8_C(     145),  UINT8_C(     113),  UINT8_C(     226),  UINT8_C(     245),
         UINT8_C(     105),  UINT8_C(      78),  UINT8_C(       0),  UINT8_C(       0),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),  UINT8_C(      76) } },
    { {  INT16_C(   26194),  INT16_C(   14842),  INT16_C(   30691), -INT16_C(    4617),
         INT16_C(   24685),  INT16_C(   28496),  INT16_C(   19706),  INT16_C(    1850) },
      {  UINT8_C(     210),  UINT8_C(     238),  UINT8_C(     207),  UINT8_C(      53),
         UINT8_C(     166),  UINT8_C(      38),  UINT8_C(     235),  UINT8_C(     214) },
      {  UINT8_C(     210),  UINT8_C(     238),  UINT8_C(     207),  UINT8_C(      53),
         UINT8_C(     166),  UINT8_C(      38),  UINT8_C(     235),  UINT8_C(     214),
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,          UINT8_MAX },
      {  UINT8_C(     210),  UINT8_C(     238),  UINT8_C(     207),  UINT8_C(      53),
         UINT8_C(     166),  UINT8_C(      38),  UINT8_C(     235),  UINT8_C(     214),
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,  UINT8_C(     231) },
      {  UINT8_C(     210),  UINT8_C(     238),  UINT8_C(     207),  UINT8_C(      53),
         UINT8_C(     166),  UINT8_C(      38),  UINT8_C(     235),  UINT8_C(     214),
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,  UINT8_C(      57) },
      {  UINT8_C(     210),  UINT8_C(     238),  UINT8_C(     207),  UINT8_C(      53),
         UINT8_C(     166),  UINT8_C(      38),  UINT8_C(     235),  UINT8_C(     214),
                 UINT8_MAX,  UINT8_C(     231),          UINT8_MAX,  UINT8_C(       0),
                 UINT8_MAX,          UINT8_MAX,          UINT8_MAX,  UINT8_C(      28) },
      {  UINT8_C(     210),  UINT8_C(     238),  UINT8_C(     207),  UINT8_C(      53),
         UINT8_C(     166),  UINT8_C(      38),  UINT8_C(     235),  UINT8_C(     214),
         UINT8_C(     102),  UINT8_C(      57),  UINT8_C(     119),  UINT8_C(       0),
         UINT8_C(      96),  UINT8_C(     111),  UINT8_C(      76),  UINT8_C(       7) } },
    { {  INT16_C(   17220),  INT16_C(   13719), -INT16_C(   24721),  INT16_C(    3112),
        -INT16_C(   21132), -INT16_C(    9302), -INT16_C(   29087),  INT16_C(    6300) },
      {  UINT8_C(     212),  UINT8_C(      29),  UINT8_C(      68),  UINT8_C(      96),
         UINT8_C(      10),  UINT8_C(      33),  UINT8_C(      80),  UINT8_C(     150) },
      {  UINT8_C(     212),  UINT8_C(      29),  UINT8_C(      68),  UINT8_C(      96),
         UINT8_C(      10),  UINT8_C(      33),  UINT8_C(      80),  UINT8_C(     150),
                 UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),          UINT8_MAX,
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),          UINT8_MAX },
      {  UINT8_C(     212),  UINT8_C(      29),  UINT8_C(      68),  UINT8_C(      96),
         UINT8_C(      10),  UINT8_C(      33),  UINT8_C(      80),  UINT8_C(     150),
                 UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),          UINT8_MAX,
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),          UINT8_MAX },
      {  UINT8_C(     212),  UINT8_C(      29),  UINT8_C(      68),  UINT8_C(      96),
         UINT8_C(      10),  UINT8_C(      33),  UINT8_C(      80),  UINT8_C(     150),
                 UINT8_MAX,          UINT8_MAX,  UINT8_C(       0),  UINT8_C(      97),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),  UINT8_C(     196) },
      {  UINT8_C(     212),  UINT8_C(      29),  UINT8_C(      68),  UINT8_C(      96),
         UINT8_C(      10),  UINT8_C(      33),  UINT8_C(      80),  UINT8_C(     150),
                 UINT8_MAX,  UINT8_C(     214),  UINT8_C(       0),  UINT8_C(      48),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),  UINT8_C(      98) },
      {  UINT8_C(     212),  UINT8_C(      29),  UINT8_C(      68),  UINT8_C(      96),
         UINT8_C(      10),  UINT8_C(      33),  UINT8_C(      80),  UINT8_C(     150),
         UINT8_C(      67),  UINT8_C(      53),  UINT8_C(       0),  UINT8_C(      12),
         UINT8_C(       0),  UINT8_C(       0),  UINT8_C(       0),  UINT8_C(      24) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_uint8x8_t r = simde_vld1_u8(test_vec[i].r);

    simde_uint8x16_t r1 = simde_vqshrun_high_n_s16(r, a, 1);
    simde_uint8x16_t r3 = simde_vqshrun_high_n_s16(r, a, 3);
    simde_uint8x16_t r5 = simde_vqshrun_high_n_s16(r, a, 5);
    simde_uint8x16_t r6 = simde_vqshrun_high_n_s16(r, a, 6);
    simde_uint8x16_t r8 = simde_vqshrun_high_n_s16(r, a, 8);

    simde_test_arm_neon_assert_equal_u8x16(r1, simde_vld1q_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r6, simde_vld1q_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x16(r8, simde_vld1q_u8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vqshrun_high_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    uint16_t r[4];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r16[8];
  } test_vec[] = {
    { { -INT32_C(  1423880354), -INT32_C(  1017212625),  INT32_C(   154830000), -INT32_C(  2145584507) },
      {  UINT16_C(       61268),  UINT16_C(       53256),  UINT16_C(       61506),  UINT16_C(       26010) },
      {  UINT16_C(       61268),  UINT16_C(       53256),  UINT16_C(       61506),  UINT16_C(       26010),
         UINT16_C(           0),  UINT16_C(           0),              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       61268),  UINT16_C(       53256),  UINT16_C(       61506),  UINT16_C(       26010),
         UINT16_C(           0),  UINT16_C(           0),              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       61268),  UINT16_C(       53256),  UINT16_C(       61506),  UINT16_C(       26010),
         UINT16_C(           0),  UINT16_C(           0),              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       61268),  UINT16_C(       53256),  UINT16_C(       61506),  UINT16_C(       26010),
         UINT16_C(           0),  UINT16_C(           0),  UINT16_C(       18900),  UINT16_C(           0) },
      {  UINT16_C(       61268),  UINT16_C(       53256),  UINT16_C(       61506),  UINT16_C(       26010),
         UINT16_C(           0),  UINT16_C(           0),  UINT16_C(        2362),  UINT16_C(           0) } },
    { {  INT32_C(  1201613060), -INT32_C(   991562061),  INT32_C(   463879337),  INT32_C(   292310165) },
      {  UINT16_C(       30484),  UINT16_C(       20434),  UINT16_C(       60813),  UINT16_C(       44018) },
      {  UINT16_C(       30484),  UINT16_C(       20434),  UINT16_C(       60813),  UINT16_C(       44018),
                     UINT16_MAX,  UINT16_C(           0),              UINT16_MAX,              UINT16_MAX },
      {  UINT16_C(       30484),  UINT16_C(       20434),  UINT16_C(       60813),  UINT16_C(       44018),
                     UINT16_MAX,  UINT16_C(           0),              UINT16_MAX,              UINT16_MAX },
      {  UINT16_C(       30484),  UINT16_C(       20434),  UINT16_C(       60813),  UINT16_C(       44018),
                     UINT16_MAX,  UINT16_C(           0),              UINT16_MAX,              UINT16_MAX },
      {  UINT16_C(       30484),  UINT16_C(       20434),  UINT16_C(       60813),  UINT16_C(       44018),
                     UINT16_MAX,  UINT16_C(           0),  UINT16_C(       56625),  UINT16_C(       35682) },
      {  UINT16_C(       30484),  UINT16_C(       20434),  UINT16_C(       60813),  UINT16_C(       44018),
         UINT16_C(       18335),  UINT16_C(           0),  UINT16_C(        7078),  UINT16_C(        4460) } },
    { {  INT32_C(   722861141),  INT32_C(  1540149532),  INT32_C(   561852205), -INT32_C(  1276065861) },
      {  UINT16_C(       43437),  UINT16_C(       14395),  UINT16_C(       47419),  UINT16_C(       55177) },
      {  UINT16_C(       43437),  UINT16_C(       14395),  UINT16_C(       47419),  UINT16_C(       55177),
                     UINT16_MAX,              UINT16_MAX,              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       43437),  UINT16_C(       14395),  UINT16_C(       47419),  UINT16_C(       55177),
                     UINT16_MAX,              UINT16_MAX,              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       43437),  UINT16_C(       14395),  UINT16_C(       47419),  UINT16_C(       55177),
                     UINT16_MAX,              UINT16_MAX,              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       43437),  UINT16_C(       14395),  UINT16_C(       47419),  UINT16_C(       55177),
                     UINT16_MAX,              UINT16_MAX,              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       43437),  UINT16_C(       14395),  UINT16_C(       47419),  UINT16_C(       55177),
         UINT16_C(       11029),  UINT16_C(       23500),  UINT16_C(        8573),  UINT16_C(           0) } },
    { {  INT32_C(   452362172), -INT32_C(  1480425989),  INT32_C(   482002715), -INT32_C(  1205613999) },
      {  UINT16_C(       41458),  UINT16_C(       57061),  UINT16_C(       51703),  UINT16_C(        6134) },
      {  UINT16_C(       41458),  UINT16_C(       57061),  UINT16_C(       51703),  UINT16_C(        6134),
                     UINT16_MAX,  UINT16_C(           0),              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       41458),  UINT16_C(       57061),  UINT16_C(       51703),  UINT16_C(        6134),
                     UINT16_MAX,  UINT16_C(           0),              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       41458),  UINT16_C(       57061),  UINT16_C(       51703),  UINT16_C(        6134),
                     UINT16_MAX,  UINT16_C(           0),              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       41458),  UINT16_C(       57061),  UINT16_C(       51703),  UINT16_C(        6134),
         UINT16_C(       55219),  UINT16_C(           0),  UINT16_C(       58838),  UINT16_C(           0) },
      {  UINT16_C(       41458),  UINT16_C(       57061),  UINT16_C(       51703),  UINT16_C(        6134),
         UINT16_C(        6902),  UINT16_C(           0),  UINT16_C(        7354),  UINT16_C(           0) } },
    { { -INT32_C(   425558702),  INT32_C(   320272840), -INT32_C(  1469659344), -INT32_C(  2110097515) },
      {  UINT16_C(        1325),  UINT16_C(       55612),  UINT16_C(        6754),  UINT16_C(       38552) },
      {  UINT16_C(        1325),  UINT16_C(       55612),  UINT16_C(        6754),  UINT16_C(       38552),
         UINT16_C(           0),              UINT16_MAX,  UINT16_C(           0),  UINT16_C(           0) },
      {  UINT16_C(        1325),  UINT16_C(       55612),  UINT16_C(        6754),  UINT16_C(       38552),
         UINT16_C(           0),              UINT16_MAX,  UINT16_C(           0),  UINT16_C(           0) },
      {  UINT16_C(        1325),  UINT16_C(       55612),  UINT16_C(        6754),  UINT16_C(       38552),
         UINT16_C(           0),              UINT16_MAX,  UINT16_C(           0),  UINT16_C(           0) },
      {  UINT16_C(        1325),  UINT16_C(       55612),  UINT16_C(        6754),  UINT16_C(       38552),
         UINT16_C(           0),  UINT16_C(       39095),  UINT16_C(           0),  UINT16_C(           0) },
      {  UINT16_C(        1325),  UINT16_C(       55612),  UINT16_C(        6754),  UINT16_C(       38552),
         UINT16_C(           0),  UINT16_C(        4886),  UINT16_C(           0),  UINT16_C(           0) } },
    { {  INT32_C(  1696923245),  INT32_C(    40606301), -INT32_C(  2140913163),  INT32_C(  2012741797) },
      {  UINT16_C(       61568),  UINT16_C(       37601),  UINT16_C(       34556),  UINT16_C(       40493) },
      {  UINT16_C(       61568),  UINT16_C(       37601),  UINT16_C(       34556),  UINT16_C(       40493),
                     UINT16_MAX,              UINT16_MAX,  UINT16_C(           0),              UINT16_MAX },
      {  UINT16_C(       61568),  UINT16_C(       37601),  UINT16_C(       34556),  UINT16_C(       40493),
                     UINT16_MAX,              UINT16_MAX,  UINT16_C(           0),              UINT16_MAX },
      {  UINT16_C(       61568),  UINT16_C(       37601),  UINT16_C(       34556),  UINT16_C(       40493),
                     UINT16_MAX,  UINT16_C(       39654),  UINT16_C(           0),              UINT16_MAX },
      {  UINT16_C(       61568),  UINT16_C(       37601),  UINT16_C(       34556),  UINT16_C(       40493),
                     UINT16_MAX,  UINT16_C(        4956),  UINT16_C(           0),              UINT16_MAX },
      {  UINT16_C(       61568),  UINT16_C(       37601),  UINT16_C(       34556),  UINT16_C(       40493),
         UINT16_C(       25892),  UINT16_C(         619),  UINT16_C(           0),  UINT16_C(       30712) } },
    { {  INT32_C(  1043201906),  INT32_C(  1513548295),  INT32_C(  1654197045),  INT32_C(   744906865) },
      {  UINT16_C(       50465),  UINT16_C(       20285),  UINT16_C(       50702),  UINT16_C(       52611) },
      {  UINT16_C(       50465),  UINT16_C(       20285),  UINT16_C(       50702),  UINT16_C(       52611),
                     UINT16_MAX,              UINT16_MAX,              UINT16_MAX,              UINT16_MAX },
      {  UINT16_C(       50465),  UINT16_C(       20285),  UINT16_C(       50702),  UINT16_C(       52611),
                     UINT16_MAX,              UINT16_MAX,              UINT16_MAX,              UINT16_MAX },
      {  UINT16_C(       50465),  UINT16_C(       20285),  UINT16_C(       50702),  UINT16_C(       52611),
                     UINT16_MAX,              UINT16_MAX,              UINT16_MAX,              UINT16_MAX },
      {  UINT16_C(       50465),  UINT16_C(       20285),  UINT16_C(       50702),  UINT16_C(       52611),
                     UINT16_MAX,              UINT16_MAX,              UINT16_MAX,              UINT16_MAX },
      {  UINT16_C(       50465),  UINT16_C(       20285),  UINT16_C(       50702),  UINT16_C(       52611),
         UINT16_C(       15917),  UINT16_C(       23094),  UINT16_C(       25241),  UINT16_C(       11366) } },
    { { -INT32_C(  1590072601),  INT32_C(  1015549386),  INT32_C(  1572486796), -INT32_C(   387713851) },
      {  UINT16_C(       59464),  UINT16_C(       35873),  UINT16_C(        2523),  UINT16_C(       17349) },
      {  UINT16_C(       59464),  UINT16_C(       35873),  UINT16_C(        2523),  UINT16_C(       17349),
         UINT16_C(           0),              UINT16_MAX,              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       59464),  UINT16_C(       35873),  UINT16_C(        2523),  UINT16_C(       17349),
         UINT16_C(           0),              UINT16_MAX,              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       59464),  UINT16_C(       35873),  UINT16_C(        2523),  UINT16_C(       17349),
         UINT16_C(           0),              UINT16_MAX,              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       59464),  UINT16_C(       35873),  UINT16_C(        2523),  UINT16_C(       17349),
         UINT16_C(           0),              UINT16_MAX,              UINT16_MAX,  UINT16_C(           0) },
      {  UINT16_C(       59464),  UINT16_C(       35873),  UINT16_C(        2523),  UINT16_C(       17349),
         UINT16_C(           0),  UINT16_C(       15496),  UINT16_C(       23994),  UINT16_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_uint16x4_t r = simde_vld1_u16(test_vec[i].r);

    simde_uint16x8_t r3 = simde_vqshrun_high_n_s32(r, a, 3);
    simde_uint16x8_t r6 = simde_vqshrun_high_n_s32(r, a, 6);
    simde_uint16x8_t r10 = simde_vqshrun_high_n_s32(r, a, 10);
    simde_uint16x8_t r13 = simde_vqshrun_high_n_s32(r, a, 13);
    simde_uint16x8_t r16 = simde_vqshrun_high_n_s32(r, a, 16);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r16, simde_vld1q_u16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vqshrun_high_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    uint32_t r[2];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r32[4];
  } test_vec[] = {
    { { -INT64_C( 8661333371872638057),  INT64_C( 4702173741634302617) },
      {  UINT32_C(           824009156),  UINT32_C(          1941755507) },
      {  UINT32_C(           824009156),  UINT32_C(          1941755507),  UINT32_C(                   0),                      UINT32_MAX },
      {  UINT32_C(           824009156),  UINT32_C(          1941755507),  UINT32_C(                   0),                      UINT32_MAX },
      {  UINT32_C(           824009156),  UINT32_C(          1941755507),  UINT32_C(                   0),                      UINT32_MAX },
      {  UINT32_C(           824009156),  UINT32_C(          1941755507),  UINT32_C(                   0),                      UINT32_MAX },
      {  UINT32_C(           824009156),  UINT32_C(          1941755507),  UINT32_C(                   0),  UINT32_C(          1094810138) } },
    { { -INT64_C( 1337128017129953868),  INT64_C( 7697472484161990285) },
      {  UINT32_C(           255363709),  UINT32_C(          1615318020) },
      {  UINT32_C(           255363709),  UINT32_C(          1615318020),  UINT32_C(                   0),                      UINT32_MAX },
      {  UINT32_C(           255363709),  UINT32_C(          1615318020),  UINT32_C(                   0),                      UINT32_MAX },
      {  UINT32_C(           255363709),  UINT32_C(          1615318020),  UINT32_C(                   0),                      UINT32_MAX },
      {  UINT32_C(           255363709),  UINT32_C(          1615318020),  UINT32_C(                   0),                      UINT32_MAX },
      {  UINT32_C(           255363709),  UINT32_C(          1615318020),  UINT32_C(                   0),  UINT32_C(          1792207472) } },
    { {  INT64_C( 8283505520990270920),  INT64_C( 5308747525096200803) },
      {  UINT32_C(          1032748878),  UINT32_C(          3066026980) },
      {  UINT32_C(          1032748878),  UINT32_C(          3066026980),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          1032748878),  UINT32_C(          3066026980),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          1032748878),  UINT32_C(          3066026980),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          1032748878),  UINT32_C(          3066026980),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          1032748878),  UINT32_C(          3066026980),  UINT32_C(          1928653922),  UINT32_C(          1236039103) } },
    { {  INT64_C( 6736309082474064431),  INT64_C( 1122465672456659060) },
      {  UINT32_C(          1357950162),  UINT32_C(           115358040) },
      {  UINT32_C(          1357950162),  UINT32_C(           115358040),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          1357950162),  UINT32_C(           115358040),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          1357950162),  UINT32_C(           115358040),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          1357950162),  UINT32_C(           115358040),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          1357950162),  UINT32_C(           115358040),  UINT32_C(          1568419179),  UINT32_C(           261344404) } },
    { {  INT64_C( 9038147839544486825),  INT64_C( 1511534382654244728) },
      {  UINT32_C(          3951712556),  UINT32_C(           492234895) },
      {  UINT32_C(          3951712556),  UINT32_C(           492234895),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          3951712556),  UINT32_C(           492234895),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          3951712556),  UINT32_C(           492234895),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          3951712556),  UINT32_C(           492234895),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          3951712556),  UINT32_C(           492234895),  UINT32_C(          2104357778),  UINT32_C(           351931523) } },
    { {  INT64_C( 4253399637706560964),  INT64_C( 2602091251160279190) },
      {  UINT32_C(          3647624306),  UINT32_C(          3351240594) },
      {  UINT32_C(          3647624306),  UINT32_C(          3351240594),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          3647624306),  UINT32_C(          3351240594),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          3647624306),  UINT32_C(          3351240594),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          3647624306),  UINT32_C(          3351240594),                      UINT32_MAX,                      UINT32_MAX },
      {  UINT32_C(          3647624306),  UINT32_C(          3351240594),  UINT32_C(           990321775),  UINT32_C(           605846580) } },
    { {  INT64_C( 7464877340503473617), -INT64_C( 3976993851836016246) },
      {  UINT32_C(          2491372178),  UINT32_C(          1756872662) },
      {  UINT32_C(          2491372178),  UINT32_C(          1756872662),                      UINT32_MAX,  UINT32_C(                   0) },
      {  UINT32_C(          2491372178),  UINT32_C(          1756872662),                      UINT32_MAX,  UINT32_C(                   0) },
      {  UINT32_C(          2491372178),  UINT32_C(          1756872662),                      UINT32_MAX,  UINT32_C(                   0) },
      {  UINT32_C(          2491372178),  UINT32_C(          1756872662),                      UINT32_MAX,  UINT32_C(                   0) },
      {  UINT32_C(          2491372178),  UINT32_C(          1756872662),  UINT32_C(          1738052195),  UINT32_C(                   0) } },
    { { -INT64_C( 2745095693133286991), -INT64_C( 7491422854933734474) },
      {  UINT32_C(          1653858402),  UINT32_C(           653580372) },
      {  UINT32_C(          1653858402),  UINT32_C(           653580372),  UINT32_C(                   0),  UINT32_C(                   0) },
      {  UINT32_C(          1653858402),  UINT32_C(           653580372),  UINT32_C(                   0),  UINT32_C(                   0) },
      {  UINT32_C(          1653858402),  UINT32_C(           653580372),  UINT32_C(                   0),  UINT32_C(                   0) },
      {  UINT32_C(          1653858402),  UINT32_C(           653580372),  UINT32_C(                   0),  UINT32_C(                   0) },
      {  UINT32_C(          1653858402),  UINT32_C(           653580372),  UINT32_C(                   0),  UINT32_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_uint32x2_t r = simde_vld1_u32(test_vec[i].r);

    simde_uint32x4_t r6 = simde_vqshrun_high_n_s64(r, a, 6);
    simde_uint32x4_t r13 = simde_vqshrun_high_n_s64(r, a, 13);
    simde_uint32x4_t r19 = simde_vqshrun_high_n_s64(r, a, 19);
    simde_uint32x4_t r26 = simde_vqshrun_high_n_s64(r, a, 26);
    simde_uint32x4_t r32 = simde_vqshrun_high_n_s64(r, a, 32);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r32, simde_vld1q_u32(test_vec[i].r32));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrun_high_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrun_high_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrun_high_n_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
