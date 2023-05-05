#define SIMDE_TEST_ARM_SVE_INSN and

#include "test-sve.h"
#include "../../../simde/arm/sve/and.h"

#include "../../../simde/arm/sve/cmplt.h"
#include "../../../simde/arm/sve/dup.h"

static int
test_simde_svand_s8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1) };
  static const int8_t a[] =
    {  INT8_C(  80), -INT8_C( 110),  INT8_C(  40), -INT8_C( 102),  INT8_C( 100), -INT8_C(   4),  INT8_C(  10), -INT8_C(  18),
      -INT8_C(  22),  INT8_C( 108),  INT8_C(  81), -INT8_C(  87),  INT8_C(  68),  INT8_C(  55), -INT8_C(  67), -INT8_C( 109),
       INT8_C(  25),  INT8_C(  35),  INT8_C(   6),  INT8_C(  22), -INT8_C(  28), -INT8_C(  23), -INT8_C( 100), -INT8_C(   1),
      -INT8_C(  11), -INT8_C(   3),  INT8_C(  89), -INT8_C(  26), -INT8_C( 123), -INT8_C(  90), -INT8_C(  60), -INT8_C(  43),
       INT8_C(  56), -INT8_C(  20),  INT8_C( 111), -INT8_C( 100), -INT8_C(  24),  INT8_C( 121), -INT8_C( 118), -INT8_C(  46),
      -INT8_C(  27), -INT8_C(  36),  INT8_C( 123),  INT8_C(  41),  INT8_C(  19),  INT8_C(  56), -INT8_C(  67),  INT8_C(  44),
       INT8_C(  91), -INT8_C(  61),  INT8_C(  66),  INT8_C(  64), -INT8_C(  83), -INT8_C(  33),  INT8_C(  63), -INT8_C(  94),
      -INT8_C(  36), -INT8_C( 103), -INT8_C( 120),  INT8_C(  97),  INT8_C(  63),  INT8_C(  76),  INT8_C(  54),  INT8_C( 119),
       INT8_C(  56), -INT8_C(  90),  INT8_C(  20),  INT8_C(  32),  INT8_C(  31), -INT8_C(  98), -INT8_C(  14),  INT8_C(   5),
       INT8_C( 122),  INT8_C( 110),  INT8_C(  46), -INT8_C( 114), -INT8_C(  90), -INT8_C(  21), -INT8_C(  70),  INT8_C(   2),
      -INT8_C(  81), -INT8_C(   3),  INT8_C(  66),  INT8_C(  92), -INT8_C(  36), -INT8_C( 127), -INT8_C(   2), -INT8_C(  72),
       INT8_C(  26), -INT8_C( 122),  INT8_C(  25),  INT8_C(  89), -INT8_C(  46),  INT8_C(  79), -INT8_C(  47),  INT8_C(  10),
      -INT8_C(  11), -INT8_C(  27),  INT8_C(  42),  INT8_C(  21), -INT8_C( 125),  INT8_C(  28),  INT8_C(  26), -INT8_C(   2),
      -INT8_C( 118),  INT8_C(  72), -INT8_C( 116),  INT8_C(  49),  INT8_C(  52),  INT8_C(  70),  INT8_C(  51), -INT8_C(  29),
       INT8_C(  67),  INT8_C( 117),  INT8_C(  63),  INT8_C(  31), -INT8_C(  10),  INT8_C(  61), -INT8_C(  41),  INT8_C(  17),
      -INT8_C(  61), -INT8_C(  16),  INT8_C( 106), -INT8_C( 107),  INT8_C(  64),  INT8_C(  59), -INT8_C(  97),  INT8_C(  53),
       INT8_C(  32), -INT8_C(  55),  INT8_C(  74), -INT8_C(  92), -INT8_C(  27),  INT8_C( 100), -INT8_C(  94),  INT8_C( 112),
      -INT8_C(  83),  INT8_C(  46), -INT8_C(  95), -INT8_C(  31),  INT8_C( 116), -INT8_C(  44), -INT8_C(  60), -INT8_C(  72),
       INT8_C(  73),  INT8_C(   3), -INT8_C(  41),  INT8_C(  63),  INT8_C(  64), -INT8_C(  81),  INT8_C(  80),  INT8_C(   3),
      -INT8_C(  97), -INT8_C(  69), -INT8_C( 104), -INT8_C(  33), -INT8_C(  10),  INT8_C(  55),  INT8_C(  21),  INT8_C(  23),
       INT8_C(   0),  INT8_C(  95), -INT8_C(  69), -INT8_C(  27), -INT8_C(  60),  INT8_C(  93),  INT8_C(  85),  INT8_C( 113),
      -INT8_C( 117), -INT8_C(  10),  INT8_C(  82), -INT8_C(   1), -INT8_C(  54),  INT8_C(  22), -INT8_C(  73),  INT8_C(  19),
       INT8_C(  25), -INT8_C( 113),  INT8_C(  83),  INT8_C(  89),  INT8_C(  62), -INT8_C(  93),  INT8_C(  92), -INT8_C(  35),
       INT8_C(  94), -INT8_C(  12), -INT8_C(  67),  INT8_C(  85),  INT8_C(  43), -INT8_C(  46),  INT8_C( 108),  INT8_C(  43),
       INT8_C(  49),  INT8_C(  39),  INT8_C(  16), -INT8_C(  11), -INT8_C( 124),  INT8_C( 102),  INT8_C( 102),  INT8_C(  15),
       INT8_C(  92), -INT8_C(  72),  INT8_C(  14),  INT8_C(  39), -INT8_C(  50), -INT8_C(  58),  INT8_C(  58), -INT8_C(  25),
       INT8_C(  85), -INT8_C( 115),  INT8_C(  64), -INT8_C( 109),  INT8_C(  49), -INT8_C( 100),  INT8_C( 112), -INT8_C( 113),
      -INT8_C( 112),  INT8_C(  45), -INT8_C(  28), -INT8_C(  69), -INT8_C(   1),  INT8_C(  80), -INT8_C(  26),  INT8_C(  49),
       INT8_C( 119), -INT8_C(   9),  INT8_C(  38), -INT8_C(   5),  INT8_C(  93), -INT8_C( 115),  INT8_C(  10), -INT8_C(  71),
       INT8_C(  69),  INT8_C(  25), -INT8_C(  32),  INT8_C(  20), -INT8_C(  33),  INT8_C(  27), -INT8_C(   5),  INT8_C(  52),
      -INT8_C(  88),  INT8_C(  60), -INT8_C(  57), -INT8_C(  39), -INT8_C(  40),  INT8_C(  55),  INT8_C( 105),  INT8_C( 105),
       INT8_C( 101),  INT8_C(  77),  INT8_C(  36),  INT8_C( 100), -INT8_C(  98),  INT8_C(  11), -INT8_C( 107),  INT8_C(  21),
       INT8_C(   2), -INT8_C(  68),  INT8_C(  17),  INT8_C(  95),  INT8_C(  73),  INT8_C(  27),  INT8_C(  24), -INT8_C( 114),
       INT8_C(  52), -INT8_C(   7), -INT8_C(  94),  INT8_C(  19),  INT8_C(  20), -INT8_C(  98),  INT8_C(  71), -INT8_C(  68),
      -INT8_C(  38),  INT8_C(  14), -INT8_C( 106), -INT8_C(  78),  INT8_C(  70), -INT8_C(   1),  INT8_C(  27), -INT8_C(  85),
       INT8_C(  76),  INT8_C(  64),  INT8_C(  15), -INT8_C(  22),  INT8_C(  75), -INT8_C(  91),  INT8_C(   0),  INT8_C(  77),
       INT8_C(  97),  INT8_C(  17), -INT8_C(  84), -INT8_C(  86),  INT8_C(  44), -INT8_C(  60),  INT8_C(  56),  INT8_C(  97),
      -INT8_C(  67), -INT8_C(  37),  INT8_C( 116), -INT8_C(  47),  INT8_C( 121), -INT8_C(  68), -INT8_C( 114),  INT8_C(  83),
      -INT8_C(  54),  INT8_C(  36),  INT8_C(   5),  INT8_C(  16),  INT8_C(  35),  INT8_C(  33), -INT8_C(  69),  INT8_C( 111),
       INT8_C(  97), -INT8_C(  53),  INT8_C(  90), -INT8_C(  84),  INT8_C( 112),  INT8_C(  90), -INT8_C(   7), -INT8_C(  47),
       INT8_C( 107), -INT8_C(  91),  INT8_C( 123), -INT8_C( 105),  INT8_C( 105), -INT8_C(  77), -INT8_C(   8),  INT8_C(  39),
      -INT8_C( 114),  INT8_C( 109), -INT8_C(   8),  INT8_C(   7),  INT8_C(  41), -INT8_C( 122),  INT8_C(  90), -INT8_C(  13),
      -INT8_C(  86),  INT8_C(  96),  INT8_C(   4), -INT8_C(  51), -INT8_C( 127), -INT8_C(  65),  INT8_C(  61), -INT8_C(  30),
      -INT8_C( 118), -INT8_C( 105), -INT8_C( 114), -INT8_C(   6), -INT8_C(  15), -INT8_C( 121), -INT8_C(  53),  INT8_C(  92),
       INT8_C(  44),  INT8_C(  70), -INT8_C(  13), -INT8_C( 107), -INT8_C(   6), -INT8_C(  20), -INT8_C(  68), -INT8_C( 120),
       INT8_C(  89), -INT8_C(  75), -INT8_C( 112), -INT8_C( 126),  INT8_C(  59), -INT8_C(  22),  INT8_C( 117), -INT8_C(  26),
       INT8_C(  74),  INT8_C( 121), -INT8_C(  77), -INT8_C(  53),  INT8_C(  57), -INT8_C(  16), -INT8_C(  83), -INT8_C(  61),
      -INT8_C( 121),  INT8_C(  59), -INT8_C(  66),  INT8_C( 120), -INT8_C(  62), -INT8_C( 119), -INT8_C(  44), -INT8_C(  18),
      -INT8_C(  48), -INT8_C(  56), -INT8_C( 124), -INT8_C(  54), -INT8_C(  76),  INT8_C(  64),  INT8_C(  82),  INT8_C(  13),
      -INT8_C(  11), -INT8_C(  30), -INT8_C( 113),  INT8_C(  49), -INT8_C(  51),  INT8_C(   4),  INT8_C(  23),  INT8_C(  23),
       INT8_C( 126), -INT8_C(  54), -INT8_C(  29), -INT8_C(  73), -INT8_C(  69), -INT8_C( 112),  INT8_C( 122),  INT8_C(  66),
      -INT8_C(  52),  INT8_C(  56), -INT8_C(  69), -INT8_C( 114), -INT8_C(  62), -INT8_C( 113),  INT8_C( 125), -INT8_C( 110),
       INT8_C(  87),  INT8_C(   1),  INT8_C(  92),  INT8_C(  11),  INT8_C(  65), -INT8_C(  82),  INT8_C(  24),  INT8_C(  55),
      -INT8_C( 111), -INT8_C(  89),  INT8_C( 104),  INT8_C(  94), -INT8_C(  84),      INT8_MAX,  INT8_C( 117),  INT8_C(  42),
       INT8_C(  73),  INT8_C(  88), -INT8_C(  31),  INT8_C(   4), -INT8_C(  23),  INT8_C(  91),  INT8_C(  71), -INT8_C(  75),
      -INT8_C( 108),  INT8_C(   2),  INT8_C(  67),  INT8_C(  86), -INT8_C( 111), -INT8_C(  64), -INT8_C(  24), -INT8_C(  23),
      -INT8_C(  63) };
  static const int8_t b[] =
    {  INT8_C(   3),  INT8_C( 112),  INT8_C( 100),  INT8_C(  75),  INT8_C(  95), -INT8_C(  88),  INT8_C(  91), -INT8_C( 113),
      -INT8_C( 112),  INT8_C(  47), -INT8_C(  32),  INT8_C(  64), -INT8_C(  32),  INT8_C(  79), -INT8_C( 101),  INT8_C(  75),
       INT8_C(  31),  INT8_C(  37), -INT8_C(  65),  INT8_C(  39),  INT8_C(  28), -INT8_C(  14),  INT8_C(  30), -INT8_C(  64),
      -INT8_C(  74),  INT8_C(  58),  INT8_C(  98),  INT8_C(  36), -INT8_C(  12),  INT8_C( 104), -INT8_C(  64), -INT8_C(   8),
      -INT8_C(  39),  INT8_C(  36),  INT8_C(  67),  INT8_C(  56), -INT8_C(  51), -INT8_C(  98), -INT8_C(   57),  INT8_C(  93),
      -INT8_C(  51), -INT8_C(  89), -INT8_C(  99), -INT8_C(  83), -INT8_C(   9),  INT8_C(  57), -INT8_C(   8),  INT8_C(  22),
       INT8_C(  94), -INT8_C(  73),  INT8_C(  62),  INT8_C( 122), -INT8_C(  86),  INT8_C(  92),  INT8_C(  58),  INT8_C(  96),
      -INT8_C( 106), -INT8_C( 100), -INT8_C( 124), -INT8_C( 117),  INT8_C(   5),  INT8_C(  68), -INT8_C( 125), -INT8_C(  34),
       INT8_C( 104), -INT8_C(  58),  INT8_C(  22),  INT8_C(  53),  INT8_C( 100), -INT8_C(  35), -INT8_C( 109),  INT8_C(  49),
      -INT8_C( 124),  INT8_C(  48), -INT8_C(  34),  INT8_C( 123),  INT8_C( 105), -INT8_C(  42), -INT8_C( 110), -INT8_C(  57),
      -INT8_C( 114), -INT8_C(  48),  INT8_C(  65),  INT8_C(  56),  INT8_C(  44),  INT8_C( 124), -INT8_C( 104), -INT8_C(  61),
       INT8_C(  24),  INT8_C(  28),  INT8_C(  78),  INT8_C(  29),  INT8_C(  96), -INT8_C(  47), -INT8_C(   5), -INT8_C(  56),
      -INT8_C( 105),  INT8_C(  17), -INT8_C(   2), -INT8_C(   5), -INT8_C(  18), -INT8_C( 111),  INT8_C(  44),  INT8_C( 115),
      -INT8_C(  63),  INT8_C(  10), -INT8_C(  18),  INT8_C(  43), -INT8_C(  32),      INT8_MIN, -INT8_C(  14),  INT8_C( 110),
       INT8_C(  80),  INT8_C(  52), -INT8_C(  90),  INT8_C( 125), -INT8_C(  80),  INT8_C(  62),  INT8_C(  64), -INT8_C(  56),
       INT8_C(  90), -INT8_C( 114), -INT8_C(  26), -INT8_C(  70),  INT8_C(  95), -INT8_C(  31), -INT8_C( 125), -INT8_C(  10),
      -INT8_C(  13), -INT8_C( 127), -INT8_C(  15), -INT8_C(  31),  INT8_C(  18),  INT8_C(  29),  INT8_C(  84), -INT8_C(  45),
       INT8_C(  39),  INT8_C(  67), -INT8_C(   2),  INT8_C(   7), -INT8_C(  61), -INT8_C(  15),  INT8_C( 118),  INT8_C(  20),
       INT8_C(  37),  INT8_C(  28), -INT8_C( 111), -INT8_C(  43),  INT8_C(  91), -INT8_C(  47), -INT8_C(  99), -INT8_C(  75),
       INT8_C(  95), -INT8_C( 125),  INT8_C( 112), -INT8_C(  66),  INT8_C( 101), -INT8_C(  13), -INT8_C(  76),  INT8_C(  88),
       INT8_C( 116), -INT8_C(  91),  INT8_C(  57), -INT8_C( 122), -INT8_C(  62), -INT8_C( 114),  INT8_C(  89), -INT8_C(  23),
      -INT8_C(  47),  INT8_C(  88), -INT8_C(  16), -INT8_C( 108),  INT8_C(  73),  INT8_C( 102), -INT8_C(  88),  INT8_C( 110),
      -INT8_C( 125),  INT8_C(  57),  INT8_C(  67), -INT8_C(  34),  INT8_C(  10), -INT8_C(  32), -INT8_C( 109),  INT8_C( 105),
       INT8_C( 100),  INT8_C(   3),  INT8_C(  39), -INT8_C(  55), -INT8_C(  10), -INT8_C(  37),  INT8_C(  33),  INT8_C( 106),
           INT8_MIN,  INT8_C(  90), -INT8_C(  16),  INT8_C(  66), -INT8_C(  24),  INT8_C(  74),  INT8_C(  43), -INT8_C(  71),
      -INT8_C(  94),  INT8_C(  28),  INT8_C(  78), -INT8_C(  21), -INT8_C( 126), -INT8_C(  10),  INT8_C(  89),  INT8_C(   5),
       INT8_C(  48), -INT8_C( 100), -INT8_C(  29),  INT8_C(  58),  INT8_C( 124),  INT8_C( 119), -INT8_C(  92), -INT8_C(  32),
       INT8_C( 122), -INT8_C(  53), -INT8_C(  87),  INT8_C( 113), -INT8_C(  89), -INT8_C(  54), -INT8_C(  37),  INT8_C(  39),
       INT8_C(  37), -INT8_C(  52),  INT8_C( 106),  INT8_C(  13),  INT8_C(  22), -INT8_C( 107), -INT8_C(  57), -INT8_C(  72),
      -INT8_C(  79),  INT8_C(  21), -INT8_C(  93),  INT8_C(  52),  INT8_C(  11), -INT8_C(   4),  INT8_C(  57),  INT8_C(  59),
      -INT8_C( 104),  INT8_C(  29),  INT8_C( 118),  INT8_C(  20), -INT8_C( 108),  INT8_C(  26), -INT8_C(  11),  INT8_C(  14),
      -INT8_C(  27), -INT8_C(  98),      INT8_MAX, -INT8_C( 116),  INT8_C( 105),  INT8_C(  91), -INT8_C(  76), -INT8_C( 114),
       INT8_C(  39),  INT8_C(  30), -INT8_C( 101),  INT8_C(  61), -INT8_C(  77),  INT8_C(  98), -INT8_C(  11),  INT8_C( 101),
       INT8_C( 119), -INT8_C( 104), -INT8_C( 103), -INT8_C( 125), -INT8_C( 108), -INT8_C(  46), -INT8_C(  66),  INT8_C(  44),
      -INT8_C(  17),  INT8_C(  52),  INT8_C(  64), -INT8_C( 125),  INT8_C(  78),  INT8_C(  53), -INT8_C( 110),  INT8_C(  52),
      -INT8_C(  44),  INT8_C(  17), -INT8_C(  64),  INT8_C(  61),  INT8_C( 108),  INT8_C( 116), -INT8_C(  53), -INT8_C( 109),
      -INT8_C( 110),  INT8_C( 102), -INT8_C(  48),  INT8_C(  70), -INT8_C(  55), -INT8_C(  59), -INT8_C(  85),  INT8_C(  64),
       INT8_C(  93),  INT8_C(  68), -INT8_C(  61), -INT8_C(  15),  INT8_C(  22), -INT8_C( 126),  INT8_C(  29),  INT8_C(   6),
      -INT8_C(  74),  INT8_C(  94), -INT8_C( 119),  INT8_C(   5), -INT8_C( 109),  INT8_C(  27),  INT8_C(  57),  INT8_C( 103),
       INT8_C(  45), -INT8_C(   7), -INT8_C(  92), -INT8_C( 103),  INT8_C( 110),  INT8_C( 111),  INT8_C(  45),  INT8_C(   0),
      -INT8_C(  42), -INT8_C(   3),  INT8_C(  70), -INT8_C(  97), -INT8_C(  61), -INT8_C(  15), -INT8_C(  33),  INT8_C(  32),
       INT8_C(  53), -INT8_C(  93),  INT8_C(  18),  INT8_C(  76),  INT8_C(  37),  INT8_C(  47),  INT8_C(  82), -INT8_C(  37),
      -INT8_C( 115), -INT8_C(  37), -INT8_C(  32),  INT8_C(  33), -INT8_C(   9),  INT8_C(  25), -INT8_C( 120),  INT8_C(  36),
       INT8_C(  19),  INT8_C(  45), -INT8_C(  67), -INT8_C( 127), -INT8_C( 100), -INT8_C(  22), -INT8_C( 127),  INT8_C( 114),
      -INT8_C(  24), -INT8_C(  56),  INT8_C(  17), -INT8_C(  85), -INT8_C(  71), -INT8_C(  15), -INT8_C(  53), -INT8_C(  17),
      -INT8_C( 108), -INT8_C(  35),  INT8_C(  59), -INT8_C(  71),  INT8_C(  13), -INT8_C( 115), -INT8_C( 108), -INT8_C( 102),
       INT8_C( 104),  INT8_C( 117), -INT8_C(  69),  INT8_C(  95), -INT8_C( 114),  INT8_C(  68), -INT8_C( 125), -INT8_C(  95),
       INT8_C( 113),  INT8_C(  65),  INT8_C(  34),  INT8_C(  13),  INT8_C(  43), -INT8_C(  92),      INT8_MIN,  INT8_C(  19),
       INT8_C( 108), -INT8_C( 111), -INT8_C(  66),  INT8_C(  37), -INT8_C( 126), -INT8_C( 118),  INT8_C(  20),  INT8_C(  22),
       INT8_C( 103),  INT8_C(  79), -INT8_C(  49),  INT8_C( 116), -INT8_C(  36),  INT8_C( 100),  INT8_C(  15),  INT8_C(  69),
      -INT8_C(  39), -INT8_C(  54), -INT8_C(  92),  INT8_C( 103),  INT8_C(  14),  INT8_C(  40),  INT8_C(   9),      INT8_MAX,
       INT8_C( 105),  INT8_C(  43), -INT8_C( 115), -INT8_C( 108), -INT8_C(  49),  INT8_C(  13), -INT8_C(  88),  INT8_C(  59),
      -INT8_C(  98),  INT8_C( 102),  INT8_C(  97),  INT8_C(  33), -INT8_C(  16),  INT8_C( 117),  INT8_C(  55),  INT8_C(  88),
      -INT8_C(  59),  INT8_C(   7), -INT8_C(  52), -INT8_C(  95),  INT8_C( 107), -INT8_C(  37), -INT8_C(  26),  INT8_C(  68),
      -INT8_C(  90), -INT8_C( 117), -INT8_C(  85), -INT8_C(  76), -INT8_C(  77), -INT8_C(  76),  INT8_C(  52),  INT8_C(  28),
      -INT8_C(  32), -INT8_C(  63), -INT8_C(  80), -INT8_C(  81), -INT8_C(  50),  INT8_C(  88), -INT8_C(  21),  INT8_C( 108),
      -INT8_C(  65) };
  static const int8_t e[] =
    {  INT8_C(   0),  INT8_C(  16),  INT8_C(  32),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 114),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),
       INT8_C(   0),  INT8_C(  33),  INT8_C(   0),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  64),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  24), -INT8_C(  56),  INT8_C(  24),  INT8_C(   0),  INT8_C(  80),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  41),  INT8_C(   0),  INT8_C(  56),  INT8_C(   0),  INT8_C(   4),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  88),  INT8_C(  92),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 108), -INT8_C( 104),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  68),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  40), -INT8_C( 122),  INT8_C(  20),  INT8_C(  32),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  32),  INT8_C(  14),  INT8_C(  10),  INT8_C(   0), -INT8_C(  62),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 114), -INT8_C(  48),  INT8_C(  64),  INT8_C(  24),  INT8_C(   0),  INT8_C(   0), -INT8_C( 104),  INT8_C(   0),
       INT8_C(  24),  INT8_C(   0),  INT8_C(   8),  INT8_C(  25),  INT8_C(  64),  INT8_C(  65),  INT8_C(   0),  INT8_C(   8),
      -INT8_C( 107),  INT8_C(   1),  INT8_C(  42),  INT8_C(  17),  INT8_C(   0),  INT8_C(  16),  INT8_C(   8),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  32),  INT8_C(   0),  INT8_C(  50),  INT8_C(  98),
       INT8_C(   0),  INT8_C(  52),  INT8_C(   0),  INT8_C(  29), -INT8_C(  80),  INT8_C(  60),  INT8_C(  64),  INT8_C(   0),
       INT8_C(  66),  INT8_C(   0),  INT8_C(   0), -INT8_C( 112),  INT8_C(   0),  INT8_C(   0), -INT8_C( 125),  INT8_C(   0),
       INT8_C(  32),  INT8_C(   0),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  37),  INT8_C(   2), -INT8_C(  96),  INT8_C(   1),  INT8_C(   0), -INT8_C(  48),  INT8_C(   0),  INT8_C(  16),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  21),  INT8_C(  64), -INT8_C( 127),  INT8_C(   0),  INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  20),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 124), -INT8_C(  64),  INT8_C(  12),  INT8_C(   0),  INT8_C(  97),
      -INT8_C( 127),  INT8_C(   0),  INT8_C(   0), -INT8_C( 108),  INT8_C(  72),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  67),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  16),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  37),  INT8_C(  65),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  42),
       INT8_C(   0),  INT8_C(   2),  INT8_C(  16),  INT8_C(   0),      INT8_MIN,  INT8_C(  66),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  24),  INT8_C(  14),  INT8_C(  35),  INT8_C(   0),  INT8_C(   0),  INT8_C(  24),  INT8_C(   5),
       INT8_C(  16), -INT8_C( 116),  INT8_C(  64),  INT8_C(  18),  INT8_C(  48),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   9), -INT8_C(  96),  INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  33),
       INT8_C(  37), -INT8_C(  60),  INT8_C(   0),  INT8_C(   0),  INT8_C(  20),  INT8_C(   0),  INT8_C(   2), -INT8_C(  72),
       INT8_C(   1),  INT8_C(  17),  INT8_C(   0),  INT8_C(   0),  INT8_C(  11),  INT8_C(  24),  INT8_C(   0),  INT8_C(  48),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 112),  INT8_C(  18),  INT8_C(   0),  INT8_C(   8),
       INT8_C( 101),  INT8_C(   0),  INT8_C(  36),  INT8_C(   4),  INT8_C(   0),  INT8_C(  11),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   2),  INT8_C(   0),  INT8_C(  17),  INT8_C(  29),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),
       INT8_C(  52),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  44),
       INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  53),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  72),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   8),  INT8_C(   0),  INT8_C(  40),  INT8_C(  64),
       INT8_C(  29),  INT8_C(  64),  INT8_C(   0), -INT8_C(  47),  INT8_C(   0),  INT8_C(   0),  INT8_C(  12),  INT8_C(   2),
      -INT8_C( 126),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  55),  INT8_C(   0), -INT8_C( 120),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  66),  INT8_C(   0),  INT8_C(  66),  INT8_C(   0),  INT8_C(  65), -INT8_C(  79), -INT8_C(  40),  INT8_C(   0),
       INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1), -INT8_C( 127),  INT8_C(  25),  INT8_C(   8),  INT8_C(   0),
       INT8_C(   2),  INT8_C(   0),  INT8_C(   0),      INT8_MIN, -INT8_C( 112), -INT8_C( 126),  INT8_C(   0),  INT8_C(  80),
       INT8_C(   0),  INT8_C(  64),  INT8_C(   0), -INT8_C( 127), -INT8_C(  72),  INT8_C(   0), -INT8_C( 120),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  16),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(  20),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  77),  INT8_C(   0),  INT8_C(   0),  INT8_C(  64), -INT8_C( 127),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  34),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),
       INT8_C(   0),      INT8_MIN, -INT8_C( 124),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(  16),  INT8_C(   4),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  52),  INT8_C(   0),  INT8_C(   7),  INT8_C(   5),
       INT8_C(  88), -INT8_C(  54),  INT8_C(   0),  INT8_C(  39),  INT8_C(   0),  INT8_C(   0),  INT8_C(   8),  INT8_C(  66),
       INT8_C(   0),  INT8_C(  40), -INT8_C( 119),  INT8_C(   0), -INT8_C(  62),  INT8_C(   0),  INT8_C(   0),  INT8_C(  18),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  64),  INT8_C(   1),  INT8_C(  64),  INT8_C(   0),  INT8_C(  16),  INT8_C(  16),
      -INT8_C( 127),  INT8_C(   0),  INT8_C(  72),  INT8_C(   0),  INT8_C(  40),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   8), -INT8_C(  95),  INT8_C(   0), -INT8_C(  95),  INT8_C(  16),  INT8_C(   4),  INT8_C(  20),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(  64),  INT8_C(   0),  INT8_C( 104),
      -INT8_C( 127) };

  static int8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t
      rv,
      av = simde_svld1_s8(pg, &(a[i])),
      bv = simde_svld1_s8(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(INT8_C(0)));
    rv = simde_svand_s8_z(pv, av, bv);

    simde_svst1_s8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vi8(len, e, r);

  return 0;
#else
  int8_t p[1024], a[1024], b[1024], e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_s8(pg, &(a[i]));
    bv = simde_svld1_s8(pg, &(b[i]));

    ev = simde_svand_s8_z(pv, av, bv);

    simde_svst1_s8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_s8_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) };
  static const int8_t a[] =
    { -INT8_C(  11),  INT8_C( 117),  INT8_C(  63),  INT8_C(  41),  INT8_C( 122), -INT8_C(  13), -INT8_C(   6),  INT8_C( 122),
       INT8_C( 108), -INT8_C(  97),  INT8_C(  80), -INT8_C(  64),  INT8_C(  42),  INT8_C( 114), -INT8_C(  57),  INT8_C(  76),
       INT8_C(  58), -INT8_C(  66),  INT8_C(   2), -INT8_C(  52),  INT8_C(  91), -INT8_C(  92), -INT8_C(  86),  INT8_C( 100),
      -INT8_C(  61), -INT8_C( 107), -INT8_C(  20), -INT8_C(  55), -INT8_C(  69),  INT8_C(  40), -INT8_C(  91), -INT8_C(  80),
      -INT8_C(  98), -INT8_C(  28), -INT8_C(  39),  INT8_C(  24), -INT8_C(  41), -INT8_C(  45), -INT8_C( 110),  INT8_C(  67),
       INT8_C( 114), -INT8_C(  30),  INT8_C(   3), -INT8_C( 100),  INT8_C(  84), -INT8_C(  54), -INT8_C(  24), -INT8_C( 114),
      -INT8_C( 120), -INT8_C(  21),  INT8_C(  90), -INT8_C(  28), -INT8_C( 113),  INT8_C(   4),  INT8_C(  72),  INT8_C(  83),
      -INT8_C( 102),  INT8_C(  52),  INT8_C(  28),  INT8_C(  85),  INT8_C(  93), -INT8_C(  62),  INT8_C(   5), -INT8_C(   5),
      -INT8_C(  90), -INT8_C(  34),  INT8_C(  19),  INT8_C( 126), -INT8_C(  79), -INT8_C(  91), -INT8_C(  63),  INT8_C(  36),
      -INT8_C( 121), -INT8_C(  59), -INT8_C(  64), -INT8_C(  36), -INT8_C( 113), -INT8_C(  87),  INT8_C( 106),  INT8_C(  24),
      -INT8_C( 108), -INT8_C(  59), -INT8_C(   4),  INT8_C(  35), -INT8_C(  55),  INT8_C(  68),  INT8_C( 118),  INT8_C(  99),
       INT8_C( 121), -INT8_C( 109), -INT8_C(  72), -INT8_C(  42),  INT8_C(  85), -INT8_C(  67), -INT8_C(  47), -INT8_C(   5),
      -INT8_C( 101), -INT8_C(  28),  INT8_C( 121),  INT8_C(  77), -INT8_C( 119),  INT8_C(  59),  INT8_C( 113),  INT8_C(  16),
       INT8_C(   0),  INT8_C(  49), -INT8_C(  20), -INT8_C( 113), -INT8_C(  38),  INT8_C(  87), -INT8_C(  89),  INT8_C( 110),
       INT8_C(  28), -INT8_C(  93), -INT8_C( 110), -INT8_C(  27), -INT8_C(  24),  INT8_C(   8),  INT8_C(  73),  INT8_C(  97),
      -INT8_C( 101),  INT8_C(   1),  INT8_C(  55), -INT8_C(  16), -INT8_C(  65),  INT8_C(   8), -INT8_C(  20),  INT8_C(  90),
      -INT8_C(  20),  INT8_C( 101), -INT8_C(  89),  INT8_C( 117), -INT8_C(  96),  INT8_C(  24), -INT8_C( 123), -INT8_C(  96),
       INT8_C(  74),  INT8_C( 114),  INT8_C(  48),  INT8_C(  36), -INT8_C(  55), -INT8_C(  41), -INT8_C( 109), -INT8_C(  27),
       INT8_C( 123),  INT8_C(  37), -INT8_C(  54),  INT8_C(  99),  INT8_C(  45),  INT8_C(  19), -INT8_C(  60), -INT8_C(  55),
       INT8_C(  21), -INT8_C(   5), -INT8_C(  71), -INT8_C(  44),  INT8_C(   3), -INT8_C(  91),  INT8_C(  46), -INT8_C(  17),
       INT8_C(  11), -INT8_C(  42),  INT8_C( 100), -INT8_C(  85), -INT8_C(  18), -INT8_C(  23),  INT8_C(  76),  INT8_C(  56),
       INT8_C(  91),  INT8_C( 124),  INT8_C(  93),  INT8_C(  36),  INT8_C(  83), -INT8_C(  16),  INT8_C(   9), -INT8_C(  50),
       INT8_C(  21), -INT8_C(  44),  INT8_C(  49),  INT8_C(  66), -INT8_C(  25), -INT8_C(  11),  INT8_C(  11), -INT8_C(   4),
      -INT8_C(  16), -INT8_C(  59), -INT8_C(  48), -INT8_C(  13),  INT8_C( 106), -INT8_C(   1), -INT8_C(  30),  INT8_C( 117),
      -INT8_C(  43),  INT8_C(  70),  INT8_C(  33), -INT8_C(  61),  INT8_C(  48),  INT8_C( 109), -INT8_C(   4), -INT8_C( 117),
      -INT8_C(  23),  INT8_C(  89), -INT8_C(  80),  INT8_C(  60),  INT8_C(  73), -INT8_C(  71),  INT8_C(  11),  INT8_C(  94),
      -INT8_C( 115),  INT8_C(  60), -INT8_C(  96),  INT8_C( 117),  INT8_C(  50), -INT8_C(  84),  INT8_C( 113),  INT8_C(  34),
       INT8_C( 113),  INT8_C(  66),  INT8_C(  22), -INT8_C(  37),  INT8_C(  65), -INT8_C(   8),  INT8_C(  81),  INT8_C(  22),
       INT8_C(  63),  INT8_C( 114), -INT8_C(  39),  INT8_C( 111), -INT8_C(  33), -INT8_C(  43), -INT8_C(   6), -INT8_C(  56),
       INT8_C(  46), -INT8_C(  86),  INT8_C(   4),  INT8_C( 119),  INT8_C( 100),  INT8_C(  15), -INT8_C(  43), -INT8_C(  15),
       INT8_C(  76),  INT8_C( 118),  INT8_C( 102),  INT8_C( 126),  INT8_C(  34), -INT8_C(  40), -INT8_C(  96), -INT8_C( 109),
       INT8_C(  26), -INT8_C(  74),  INT8_C( 110),  INT8_C(  91), -INT8_C(  81), -INT8_C(  65),  INT8_C( 113), -INT8_C(  18),
       INT8_C(  49),  INT8_C(  74),  INT8_C(  93),  INT8_C(  16),  INT8_C(  32),  INT8_C(  87), -INT8_C(  40),  INT8_C(  78),
       INT8_C(   2), -INT8_C(  35), -INT8_C(  58),  INT8_C( 102), -INT8_C(  20), -INT8_C( 101),  INT8_C(  87),  INT8_C(  56),
       INT8_C(  17), -INT8_C(  66), -INT8_C(  74),  INT8_C(  51), -INT8_C( 106),  INT8_C(  87), -INT8_C(  58), -INT8_C(  80),
       INT8_C(  13),  INT8_C(  53),  INT8_C(  11), -INT8_C(  68), -INT8_C(  12),  INT8_C( 124), -INT8_C(  86),  INT8_C(  38),
      -INT8_C(  58),  INT8_C(   7),  INT8_C(  54), -INT8_C(  26),  INT8_C(  95),  INT8_C(  15),  INT8_C(  53),  INT8_C(  97),
      -INT8_C(  20), -INT8_C(   5), -INT8_C(  57), -INT8_C(  40), -INT8_C( 106),  INT8_C(  30),  INT8_C(  17), -INT8_C(  88),
      -INT8_C(  36), -INT8_C(  57), -INT8_C(  37),  INT8_C( 114),  INT8_C(  30), -INT8_C(  94),  INT8_C(  34),  INT8_C(  44),
      -INT8_C(  41),  INT8_C(  45), -INT8_C(  24), -INT8_C(  53), -INT8_C(  87), -INT8_C( 109), -INT8_C(  15),  INT8_C( 112),
      -INT8_C( 102),  INT8_C(  40),  INT8_C(  86), -INT8_C(   7),  INT8_C(  55), -INT8_C( 117),  INT8_C(  90),  INT8_C(  35),
      -INT8_C( 122),  INT8_C(  33), -INT8_C(   5),  INT8_C(  29),  INT8_C(  64),  INT8_C(  12), -INT8_C(  59),  INT8_C(  28),
      -INT8_C(  44), -INT8_C(  96), -INT8_C( 113), -INT8_C(  14),  INT8_C(  66), -INT8_C(  79),  INT8_C(  30),  INT8_C(  25),
      -INT8_C(  33),  INT8_C(   7), -INT8_C(  27), -INT8_C( 120), -INT8_C( 102), -INT8_C(  42), -INT8_C(   8),  INT8_C(  52),
      -INT8_C(   2),  INT8_C(  79),  INT8_C(  46),  INT8_C(  53), -INT8_C(  38), -INT8_C( 120),  INT8_C(  88),  INT8_C(  97),
      -INT8_C(  86),  INT8_C(  84),  INT8_C( 126), -INT8_C(  22),  INT8_C(  96),  INT8_C(  67),  INT8_C(   6),  INT8_C(  52),
      -INT8_C(  29), -INT8_C( 107),  INT8_C(  39),  INT8_C(  38),  INT8_C(  71),  INT8_C(  69),  INT8_C(  63),  INT8_C(  38),
       INT8_C(  76),  INT8_C(  36), -INT8_C(  82), -INT8_C(  26), -INT8_C(   5), -INT8_C(  89),  INT8_C(  27), -INT8_C(   7),
      -INT8_C(  10),  INT8_C(  73),  INT8_C(  47), -INT8_C(  48), -INT8_C(  47), -INT8_C( 121),  INT8_C(  49),  INT8_C( 123),
      -INT8_C(  37), -INT8_C(  81),  INT8_C( 101),  INT8_C(  60), -INT8_C(  14),  INT8_C( 108),  INT8_C( 112), -INT8_C(  42),
       INT8_C(   1), -INT8_C( 105), -INT8_C(   4),  INT8_C(  72), -INT8_C(  35),  INT8_C(  59),  INT8_C( 110),  INT8_C(  41),
       INT8_C(  96),  INT8_C(  29),  INT8_C(  16),  INT8_C(  91), -INT8_C(  60),  INT8_C(  43),  INT8_C(  84), -INT8_C(  70),
       INT8_C( 116), -INT8_C( 125), -INT8_C( 118),  INT8_C(  69),  INT8_C(  11), -INT8_C(  68), -INT8_C(  63), -INT8_C(  26),
       INT8_C( 107),  INT8_C(  38),  INT8_C(  34),  INT8_C(  94), -INT8_C( 110), -INT8_C( 109),  INT8_C(  52), -INT8_C( 108),
       INT8_C(  42),  INT8_C(  48), -INT8_C(  36),  INT8_C(   7),  INT8_C( 107),  INT8_C(  75),  INT8_C(  49), -INT8_C(  53),
       INT8_C( 104),  INT8_C(  65),  INT8_C(  38),  INT8_C(  44),  INT8_C( 108),  INT8_C( 123), -INT8_C(  26), -INT8_C(  32),
      -INT8_C(   2),  INT8_C( 112),  INT8_C(  37),  INT8_C(   9),  INT8_C(  44), -INT8_C(  26), -INT8_C(  16), -INT8_C( 104),
       INT8_C(  13),  INT8_C(  18), -INT8_C(  10), -INT8_C(  97), -INT8_C(  91),  INT8_C(  42),  INT8_C(  51), -INT8_C(  48),
       INT8_C(  90),  INT8_C(  16), -INT8_C(  41), -INT8_C(  59),  INT8_C(  91),  INT8_C(   8), -INT8_C( 111), -INT8_C(  61),
       INT8_C(  73), -INT8_C(  73), -INT8_C(  17), -INT8_C(  75),  INT8_C(  50), -INT8_C(  43), -INT8_C( 107),  INT8_C(  49),
       INT8_C(  69), -INT8_C(  69),  INT8_C(  58),  INT8_C( 114), -INT8_C(  95),  INT8_C(  42),  INT8_C(  10), -INT8_C(  82),
       INT8_C(  61),  INT8_C(   0),  INT8_C(  78), -INT8_C(  30),  INT8_C(  42), -INT8_C( 127), -INT8_C(  78), -INT8_C( 124),
      -INT8_C( 111), -INT8_C( 118),  INT8_C(  73), -INT8_C(  20), -INT8_C( 110), -INT8_C(  38), -INT8_C(  81), -INT8_C(  36),
      -INT8_C( 110), -INT8_C(  98), -INT8_C( 111), -INT8_C(  60),  INT8_C( 115),  INT8_C(  39), -INT8_C(  11), -INT8_C(  71),
      -INT8_C(  30),  INT8_C(  48),  INT8_C(  43), -INT8_C( 125),  INT8_C(  90),  INT8_C(  53),  INT8_C(  50), -INT8_C( 105),
       INT8_C(  53),      INT8_MIN,  INT8_C( 122),  INT8_C(  95),  INT8_C(   1),  INT8_C(  44), -INT8_C(  29), -INT8_C( 109),
      -INT8_C(  74),  INT8_C(  44),      INT8_MAX,  INT8_C(  73),  INT8_C(   7),  INT8_C(  47),  INT8_C(  37), -INT8_C( 103),
      -INT8_C(  51), -INT8_C(  74),  INT8_C(  93),  INT8_C(  65), -INT8_C(  35),  INT8_C(  83), -INT8_C(   6), -INT8_C(  65),
      -INT8_C( 125),  INT8_C(  37),  INT8_C(  67), -INT8_C(  35),  INT8_C(  90),  INT8_C( 117),  INT8_C( 117), -INT8_C( 113),
      -INT8_C(  11), -INT8_C(  17), -INT8_C(  18), -INT8_C(  10),  INT8_C(  27), -INT8_C(  47), -INT8_C( 119), -INT8_C(  46),
      -INT8_C(   3),  INT8_C(   9),  INT8_C(  27),  INT8_C(   4),  INT8_C(  56),  INT8_C(  64), -INT8_C(  99),  INT8_C(   5),
      -INT8_C(  10), -INT8_C(   5),  INT8_C(  70), -INT8_C(  44),  INT8_C(  78),  INT8_C(  64), -INT8_C( 109), -INT8_C(  47),
       INT8_C( 101), -INT8_C(  42), -INT8_C(  82), -INT8_C(  65),  INT8_C(  75),  INT8_C(  35),  INT8_C(  78),  INT8_C(  64),
       INT8_C(  18),  INT8_C(  60),  INT8_C(  55),  INT8_C(  46),  INT8_C(  13), -INT8_C(  64),  INT8_C(   0),  INT8_C(  11),
      -INT8_C(  55),  INT8_C(  27),  INT8_C(  15),  INT8_C(   1),  INT8_C(  91), -INT8_C(  83),  INT8_C(   7),  INT8_C(  81),
      -INT8_C(  88),  INT8_C(  77),  INT8_C(  37), -INT8_C(  10), -INT8_C( 114), -INT8_C(  71), -INT8_C(  57), -INT8_C(  13),
      -INT8_C( 113),  INT8_C( 117), -INT8_C(  77), -INT8_C(  37), -INT8_C( 103),  INT8_C(   1),  INT8_C(  27), -INT8_C(  85),
       INT8_C(  62),  INT8_C(  82), -INT8_C(  39),  INT8_C(  75),  INT8_C(  19), -INT8_C(  39),  INT8_C(  86), -INT8_C(  36),
      -INT8_C(  12),  INT8_C( 102), -INT8_C(  34),  INT8_C(  79),  INT8_C(  19), -INT8_C(  27), -INT8_C(  95), -INT8_C(  69),
       INT8_C(  50), -INT8_C(  58), -INT8_C(  79), -INT8_C(  64),      INT8_MAX,  INT8_C( 120), -INT8_C(  76),  INT8_C(  15),
      -INT8_C(  19),  INT8_C( 103), -INT8_C(  22), -INT8_C( 122),  INT8_C( 104),  INT8_C(   5),  INT8_C(  50), -INT8_C(  90),
       INT8_C(  88),  INT8_C(  11), -INT8_C(  14),  INT8_C( 107), -INT8_C(  27),  INT8_C(  72),  INT8_C(  71), -INT8_C(  39),
      -INT8_C(  82),  INT8_C(  37),  INT8_C(  41), -INT8_C(  63),  INT8_C(  10), -INT8_C(  54),  INT8_C( 124),  INT8_C(  61),
      -INT8_C( 112),  INT8_C(  45), -INT8_C(   3),  INT8_C(  16), -INT8_C(  91), -INT8_C(  79),  INT8_C(  31), -INT8_C( 109),
       INT8_C(  24),  INT8_C(   9),  INT8_C(  25), -INT8_C( 127),  INT8_C(  14),  INT8_C(  75),  INT8_C(  39),  INT8_C( 102),
       INT8_C(  87),  INT8_C(  25), -INT8_C(  47),  INT8_C(  60),  INT8_C(  98),  INT8_C(  25),  INT8_C(  21),  INT8_C(  16),
       INT8_C(  62),  INT8_C(  62), -INT8_C(  46),  INT8_C(  73),  INT8_C(   8),  INT8_C(  78), -INT8_C( 122), -INT8_C( 103),
       INT8_C( 124), -INT8_C( 125), -INT8_C(  87),  INT8_C(  33),  INT8_C(  53), -INT8_C(  56), -INT8_C(  76),  INT8_C(  77),
      -INT8_C(  47), -INT8_C(  50), -INT8_C(  50), -INT8_C(  33),  INT8_C(  25), -INT8_C(  10),  INT8_C(  70),  INT8_C( 112),
       INT8_C(  15),  INT8_C(  23), -INT8_C(  84),  INT8_C( 113),  INT8_C(  48), -INT8_C(  62), -INT8_C( 126),  INT8_C( 111),
       INT8_C(   0),  INT8_C(  84), -INT8_C(  72),  INT8_C(   9), -INT8_C(  94),  INT8_C(  62), -INT8_C(  94),  INT8_C(  30),
      -INT8_C(  63),  INT8_C(  75),  INT8_C(  64), -INT8_C(  10) };
  static const int8_t b[] =
    { -INT8_C( 117), -INT8_C(  32), -INT8_C(  74), -INT8_C(  60),  INT8_C(  15), -INT8_C(   4), -INT8_C(  25), -INT8_C(  63),
      -INT8_C(  34), -INT8_C(  30),  INT8_C(  36),  INT8_C( 121),  INT8_C(  92),  INT8_C(  25), -INT8_C( 122),  INT8_C(  45),
       INT8_C(   6),  INT8_C( 104),  INT8_C(  72), -INT8_C( 101),  INT8_C(  39),  INT8_C(  38), -INT8_C(  29),  INT8_C(   9),
       INT8_C(  20), -INT8_C(  65),  INT8_C( 114), -INT8_C( 109), -INT8_C(  41), -INT8_C(  82), -INT8_C( 119),  INT8_C(  99),
      -INT8_C( 114),  INT8_C(  64),  INT8_C(  39), -INT8_C(  98),  INT8_C(  60),  INT8_C(  14),  INT8_C(  95),  INT8_C(  26),
      -INT8_C(  16), -INT8_C( 125), -INT8_C( 109),  INT8_C(  77), -INT8_C( 100),  INT8_C(  25),  INT8_C( 122), -INT8_C(  94),
      -INT8_C( 127), -INT8_C(  62),  INT8_C(  61), -INT8_C(  88), -INT8_C(  23),  INT8_C(  32), -INT8_C(  78), -INT8_C(   3),
      -INT8_C(  33),  INT8_C(  36), -INT8_C( 111), -INT8_C(  73), -INT8_C(  45),  INT8_C(  26),  INT8_C(  26),  INT8_C(  97),
       INT8_C(  90),  INT8_C(  65), -INT8_C(   1), -INT8_C( 106),  INT8_C(  79),  INT8_C(  94), -INT8_C(  80),  INT8_C(  64),
      -INT8_C(  31),  INT8_C(  67), -INT8_C( 115),  INT8_C( 125),  INT8_C(  92),  INT8_C(   7),  INT8_C(  31), -INT8_C(  35),
      -INT8_C(  54),  INT8_C(  92), -INT8_C( 122), -INT8_C(  77),  INT8_C( 125),  INT8_C(  56), -INT8_C(  80),  INT8_C(  92),
       INT8_C(  92),  INT8_C(  65),  INT8_C(  19),  INT8_C(  47),  INT8_C(  92),  INT8_C(  45), -INT8_C( 111), -INT8_C(  74),
       INT8_C( 110), -INT8_C( 112),  INT8_C(  77), -INT8_C(  66), -INT8_C(  17), -INT8_C(   3), -INT8_C(   2), -INT8_C(  48),
       INT8_C(  65), -INT8_C( 117),  INT8_C(  78), -INT8_C(  99), -INT8_C( 110),  INT8_C( 109),  INT8_C( 123),  INT8_C(  92),
      -INT8_C(  54),  INT8_C(   1),  INT8_C(  15),  INT8_C(  71),  INT8_C(  57), -INT8_C(  64), -INT8_C(  93), -INT8_C( 107),
       INT8_C(   1), -INT8_C(  73), -INT8_C(  59),  INT8_C(  93), -INT8_C(  28),  INT8_C(  86),  INT8_C(  20),  INT8_C(  83),
      -INT8_C(  26),  INT8_C(  97),  INT8_C(  17), -INT8_C(  43),  INT8_C(  94),  INT8_C(  15), -INT8_C(  90), -INT8_C(  97),
      -INT8_C( 102), -INT8_C(  12),  INT8_C(  61),  INT8_C(  44),  INT8_C(  97), -INT8_C(  72), -INT8_C( 119),  INT8_C(  43),
      -INT8_C(  71), -INT8_C( 104),  INT8_C( 114), -INT8_C(  14),  INT8_C(  88),  INT8_C(  22), -INT8_C( 121),  INT8_C(  90),
      -INT8_C(  51),  INT8_C(  76), -INT8_C(  73), -INT8_C(  79), -INT8_C(  94), -INT8_C(  53),  INT8_C(   4), -INT8_C( 119),
       INT8_C(  44),  INT8_C(  21),  INT8_C(  94), -INT8_C( 117),  INT8_C(  36),  INT8_C(   4),  INT8_C(  42), -INT8_C(  66),
      -INT8_C(   8),  INT8_C( 103), -INT8_C(  21),  INT8_C(  90),  INT8_C(  31),  INT8_C( 116), -INT8_C( 123), -INT8_C(  40),
       INT8_C(  12), -INT8_C(   8), -INT8_C(  54),  INT8_C( 101),  INT8_C(  14),  INT8_C(  82), -INT8_C(  65), -INT8_C(  37),
      -INT8_C(  98),  INT8_C( 118), -INT8_C( 116),  INT8_C(  65),  INT8_C(  66), -INT8_C( 111), -INT8_C(  54),  INT8_C( 110),
      -INT8_C(  90),  INT8_C(  40), -INT8_C(   7), -INT8_C(  53),  INT8_C(  45),  INT8_C(  36), -INT8_C( 119),  INT8_C(  37),
      -INT8_C( 117),  INT8_C( 116),      INT8_MAX, -INT8_C(  85), -INT8_C(  24),  INT8_C(   5), -INT8_C( 125), -INT8_C(  11),
      -INT8_C(   3),  INT8_C(  78),  INT8_C(  90),  INT8_C(  11), -INT8_C(  96),  INT8_C(  25), -INT8_C(  26),  INT8_C(  62),
      -INT8_C( 113),  INT8_C( 114),      INT8_MAX, -INT8_C(  47),  INT8_C(   3),  INT8_C(  73),  INT8_C(  64), -INT8_C(  86),
       INT8_C( 114),  INT8_C(  57),  INT8_C( 117), -INT8_C(  97),  INT8_C(  93), -INT8_C(   2), -INT8_C(  60), -INT8_C(  23),
       INT8_C( 115),  INT8_C(  68), -INT8_C( 108),  INT8_C(  91),  INT8_C(  73),  INT8_C(  23),  INT8_C(  80),  INT8_C(  70),
       INT8_C( 101), -INT8_C(  86),  INT8_C(  81),  INT8_C(   5), -INT8_C(  61),  INT8_C(  55),  INT8_C(  68),  INT8_C(  83),
      -INT8_C(  87), -INT8_C(  61),  INT8_C(  36), -INT8_C(  83),  INT8_C(  13),  INT8_C( 100),  INT8_C(  87),      INT8_MAX,
      -INT8_C(  98), -INT8_C(  52),  INT8_C(  30), -INT8_C(   5), -INT8_C(  54), -INT8_C(  30), -INT8_C(  28),  INT8_C(  61),
       INT8_C(  38),  INT8_C( 120), -INT8_C( 103),  INT8_C( 111), -INT8_C( 112), -INT8_C(  23), -INT8_C(  75), -INT8_C(  11),
      -INT8_C( 108),  INT8_C(   6), -INT8_C(   5),  INT8_C(  87),  INT8_C(  61),  INT8_C(  63), -INT8_C(  86), -INT8_C(  25),
       INT8_C(   2), -INT8_C(  49), -INT8_C( 108),  INT8_C(  15),  INT8_C(  51), -INT8_C(  21), -INT8_C( 114), -INT8_C(  47),
      -INT8_C(  73), -INT8_C(  84), -INT8_C(  51), -INT8_C( 127), -INT8_C( 113), -INT8_C(  79), -INT8_C(  65), -INT8_C(  75),
       INT8_C(  42),  INT8_C(  88),  INT8_C(  37), -INT8_C(  70),  INT8_C(  65), -INT8_C(  38), -INT8_C(  81), -INT8_C(  43),
      -INT8_C(  31), -INT8_C(  86),  INT8_C(  45),  INT8_C(  30), -INT8_C(  23), -INT8_C(  41),  INT8_C(   5), -INT8_C(  20),
      -INT8_C(  90), -INT8_C( 103), -INT8_C(   5), -INT8_C(  38), -INT8_C( 124), -INT8_C( 118), -INT8_C(  85),  INT8_C(  59),
       INT8_C(  54),  INT8_C( 120), -INT8_C(  67), -INT8_C(  59),  INT8_C(  42),  INT8_C( 124),  INT8_C( 123),  INT8_C(  84),
      -INT8_C(  44), -INT8_C(  96),  INT8_C(  14),  INT8_C(  21),  INT8_C( 122), -INT8_C(  67), -INT8_C(  21),  INT8_C(  91),
       INT8_C( 104),  INT8_C(  24),  INT8_C( 122),  INT8_C(  81), -INT8_C(  17),      INT8_MAX,  INT8_C(  61), -INT8_C( 106),
       INT8_C(  25),  INT8_C(  57),  INT8_C( 112), -INT8_C(  99), -INT8_C(  61),  INT8_C(  27), -INT8_C(  39), -INT8_C(   7),
      -INT8_C( 108), -INT8_C( 106), -INT8_C(  65), -INT8_C(  66),  INT8_C(  18),  INT8_C(  58),  INT8_C(  18), -INT8_C(  26),
      -INT8_C(  38),  INT8_C(  32), -INT8_C(   5),  INT8_C(  84), -INT8_C(  35), -INT8_C(  26), -INT8_C(  80),  INT8_C(  69),
      -INT8_C(   2),  INT8_C(  42), -INT8_C( 105), -INT8_C(  18), -INT8_C(  87), -INT8_C(  44), -INT8_C( 124), -INT8_C(  62),
       INT8_C(  13), -INT8_C(  12),  INT8_C(  96), -INT8_C(  48),  INT8_C(  15),  INT8_C(  57), -INT8_C(  54), -INT8_C(  93),
      -INT8_C(  49), -INT8_C( 119),  INT8_C(  97), -INT8_C(  31), -INT8_C(  61),  INT8_C( 115), -INT8_C(  57), -INT8_C(  99),
      -INT8_C( 109), -INT8_C(  62), -INT8_C(  15),  INT8_C( 113), -INT8_C(  87), -INT8_C(  95), -INT8_C(  74), -INT8_C(  89),
      -INT8_C(  53),  INT8_C(  77), -INT8_C( 107),  INT8_C( 117),  INT8_C(  34),  INT8_C(  25),  INT8_C(  55),  INT8_C(  47),
       INT8_C(  13), -INT8_C( 105),  INT8_C(   0),  INT8_C(  29), -INT8_C(  48), -INT8_C(  54), -INT8_C(  64), -INT8_C(  97),
       INT8_C(  83),  INT8_C(  34),      INT8_MIN,  INT8_C(  22), -INT8_C( 107),  INT8_C(  71), -INT8_C(  77),  INT8_C(  41),
       INT8_C(  10), -INT8_C(  92), -INT8_C( 102), -INT8_C(  77),  INT8_C(  70),  INT8_C(  80),  INT8_C(  90),  INT8_C(  17),
      -INT8_C(  98), -INT8_C(  16), -INT8_C( 122), -INT8_C(  64),  INT8_C(   9), -INT8_C(  66), -INT8_C(  17),  INT8_C(  23),
       INT8_C(  85), -INT8_C(  17),  INT8_C(  52),  INT8_C(  38), -INT8_C(  71), -INT8_C(  12), -INT8_C(  59),  INT8_C(  12),
       INT8_C(  22),  INT8_C(  70),  INT8_C(  34), -INT8_C(  84), -INT8_C( 115), -INT8_C(  43), -INT8_C(  43), -INT8_C( 105),
       INT8_C( 122),  INT8_C( 111),  INT8_C(  74), -INT8_C(  64), -INT8_C(  65), -INT8_C(  91), -INT8_C(  47),  INT8_C(  93),
      -INT8_C( 107),  INT8_C(  88),  INT8_C(  29), -INT8_C(  98),  INT8_C(  22),  INT8_C(  13), -INT8_C(  75),  INT8_C( 107),
      -INT8_C(   4), -INT8_C(  23), -INT8_C( 111), -INT8_C(  74), -INT8_C(  34),  INT8_C(  87), -INT8_C(  62), -INT8_C(  12),
      -INT8_C(  99), -INT8_C(  27), -INT8_C(  96),  INT8_C(  42), -INT8_C(  70),  INT8_C( 117), -INT8_C(  62),  INT8_C(  52),
      -INT8_C(  28),  INT8_C(  12), -INT8_C(  12), -INT8_C(  92), -INT8_C(  79), -INT8_C(  58),  INT8_C(   1),  INT8_C(  70),
       INT8_C(  30),  INT8_C(  31), -INT8_C(  27),  INT8_C(  52),  INT8_C(  44), -INT8_C( 102), -INT8_C(  97),  INT8_C(  40),
      -INT8_C( 124),  INT8_C(  49), -INT8_C(  34),  INT8_C(  98), -INT8_C( 120), -INT8_C(  95),  INT8_C(  86),  INT8_C(  37),
      -INT8_C( 122), -INT8_C(   9),  INT8_C(  79),  INT8_C(  64),  INT8_C( 108),  INT8_C(  17),  INT8_C( 117),  INT8_C(  81),
       INT8_C(  30),  INT8_C( 105), -INT8_C(  11), -INT8_C(  49),  INT8_C(  47), -INT8_C(  10),  INT8_C(  22),  INT8_C(  77),
       INT8_C(  21), -INT8_C(   5), -INT8_C( 127),  INT8_C(  65), -INT8_C( 107),  INT8_C(  33),  INT8_C( 106),  INT8_C(  25),
       INT8_C(  82),  INT8_C(  72),  INT8_C( 123), -INT8_C(  38), -INT8_C(  23), -INT8_C(  46), -INT8_C(   1),  INT8_C( 111),
      -INT8_C(  55),  INT8_C(  78), -INT8_C(  80),  INT8_C(  53),  INT8_C(  96),  INT8_C(  37), -INT8_C( 122),  INT8_C( 126),
      -INT8_C( 114),  INT8_C( 123),  INT8_C(  77), -INT8_C(  66),  INT8_C( 114),  INT8_C(  99),  INT8_C(  11), -INT8_C( 121),
       INT8_C(  94), -INT8_C( 115), -INT8_C(  55), -INT8_C(  12), -INT8_C(  82),  INT8_C(  51),  INT8_C(  13),  INT8_C(   0),
       INT8_C( 123), -INT8_C( 119), -INT8_C(  38),  INT8_C( 101),  INT8_C(  91), -INT8_C(  39), -INT8_C(  44),  INT8_C(  36),
       INT8_C(  39), -INT8_C( 124),  INT8_C(  89), -INT8_C( 121), -INT8_C(  87), -INT8_C(  32),  INT8_C(   5),  INT8_C(  56),
       INT8_C(  91),  INT8_C(  83), -INT8_C(  10), -INT8_C(  51), -INT8_C(  74),  INT8_C(   1),  INT8_C(  85),  INT8_C(  21),
      -INT8_C( 114),  INT8_C(  30),  INT8_C(   9),  INT8_C(  60),  INT8_C(  81),  INT8_C(  22),  INT8_C(  60), -INT8_C(  52),
      -INT8_C(  97),  INT8_C(  22),  INT8_C(  49), -INT8_C(   6), -INT8_C(  17),  INT8_C(   6),  INT8_C(  30),  INT8_C(  23),
      -INT8_C( 118),  INT8_C( 120), -INT8_C(  98),  INT8_C(  52),  INT8_C(  88), -INT8_C(  92),  INT8_C( 108), -INT8_C(  77),
      -INT8_C(   9),  INT8_C(  98), -INT8_C( 127), -INT8_C(  83),  INT8_C(  99), -INT8_C(  42), -INT8_C(  62), -INT8_C(  14),
      -INT8_C(  12), -INT8_C(  53),  INT8_C(  46),  INT8_C(  69), -INT8_C(  30),  INT8_C( 107),  INT8_C(  17), -INT8_C( 127),
      -INT8_C( 127),  INT8_C(  67),  INT8_C( 124),  INT8_C( 113),  INT8_C(  73), -INT8_C( 102), -INT8_C( 120), -INT8_C(  45),
       INT8_C(  18),  INT8_C(  38),  INT8_C(   7),  INT8_C( 106), -INT8_C(  54),  INT8_C( 115),  INT8_C(  30), -INT8_C(  63),
      -INT8_C(  43), -INT8_C(  97),  INT8_C( 111),  INT8_C(  57),  INT8_C( 117),  INT8_C(  49),  INT8_C(  43),  INT8_C( 105),
      -INT8_C(   3),  INT8_C(  89), -INT8_C(  82), -INT8_C(  33), -INT8_C(  60), -INT8_C(  65),  INT8_C(  96),  INT8_C(  70),
       INT8_C(   2), -INT8_C(  36), -INT8_C(  73),  INT8_C(  75),  INT8_C( 119),  INT8_C(  63),  INT8_C(  31), -INT8_C( 119),
       INT8_C( 101),  INT8_C(  38), -INT8_C(  12),  INT8_C(  48), -INT8_C( 102),  INT8_C(  18), -INT8_C(  15),  INT8_C( 111),
      -INT8_C(  79),  INT8_C(  96), -INT8_C(  88),  INT8_C(  38), -INT8_C( 110), -INT8_C(  45), -INT8_C( 113), -INT8_C( 113),
       INT8_C(  45),  INT8_C(  61),  INT8_C( 110), -INT8_C(  15), -INT8_C(   4), -INT8_C(  50),  INT8_C(  55), -INT8_C(   1),
      -INT8_C(  85), -INT8_C(  18),  INT8_C(  74),  INT8_C(  34),  INT8_C(  45),  INT8_C( 105), -INT8_C(  85), -INT8_C( 109),
      -INT8_C( 112), -INT8_C(  97), -INT8_C(  61),  INT8_C(  42), -INT8_C(  79), -INT8_C(  76), -INT8_C( 103),  INT8_C(  98),
       INT8_C(  21),  INT8_C(  66), -INT8_C( 120), -INT8_C(  89),  INT8_C(  21),  INT8_C(  23),  INT8_C(  54),  INT8_C(  66),
       INT8_C(  84), -INT8_C(  92),  INT8_C(  52),  INT8_C(  81),  INT8_C( 114),  INT8_C( 107),  INT8_C(  80),  INT8_C(  29),
       INT8_C(  90), -INT8_C( 102),  INT8_C(  63), -INT8_C( 121) };
  static const int8_t e[] =
    { -INT8_C(  11),  INT8_C(  96),  INT8_C(  54),  INT8_C(  41),  INT8_C(  10), -INT8_C(  13), -INT8_C(   6),  INT8_C(  64),
       INT8_C( 108), -INT8_C(  97),  INT8_C(   0),  INT8_C(  64),  INT8_C(  42),  INT8_C(  16), -INT8_C(  57),  INT8_C(  12),
       INT8_C(   2),  INT8_C(  40),  INT8_C(   0), -INT8_C(  52),  INT8_C(  91), -INT8_C(  92), -INT8_C(  86),  INT8_C(   0),
      -INT8_C(  61), -INT8_C( 107),  INT8_C(  96), -INT8_C(  55), -INT8_C(  69),  INT8_C(  40), -INT8_C( 127),  INT8_C(  32),
      -INT8_C( 114),  INT8_C(  64), -INT8_C(  39),  INT8_C(  24), -INT8_C(  41),  INT8_C(   2), -INT8_C( 110),  INT8_C(  67),
       INT8_C( 112), -INT8_C( 126),  INT8_C(   3),  INT8_C(  12),  INT8_C(  20), -INT8_C(  54), -INT8_C(  24), -INT8_C( 126),
           INT8_MIN, -INT8_C(  62),  INT8_C(  90), -INT8_C(  96), -INT8_C( 113),  INT8_C(   4),  INT8_C(   0),  INT8_C(  83),
      -INT8_C( 102),  INT8_C(  52),  INT8_C(  28),  INT8_C(  21),  INT8_C(  81), -INT8_C(  62),  INT8_C(   0), -INT8_C(   5),
      -INT8_C(  90),  INT8_C(  64),  INT8_C(  19),  INT8_C( 126), -INT8_C(  79), -INT8_C(  91), -INT8_C(  63),  INT8_C(   0),
      -INT8_C( 121), -INT8_C(  59),      INT8_MIN,  INT8_C(  92), -INT8_C( 113), -INT8_C(  87),  INT8_C(  10),  INT8_C(  24),
      -INT8_C( 108), -INT8_C(  59), -INT8_C( 124),  INT8_C(  35),  INT8_C(  73),  INT8_C(   0),  INT8_C( 118),  INT8_C(  64),
       INT8_C(  88),  INT8_C(   1),  INT8_C(  16), -INT8_C(  42),  INT8_C(  84),  INT8_C(  45), -INT8_C( 111), -INT8_C(  78),
      -INT8_C( 101),      INT8_MIN,  INT8_C(  73),  INT8_C(  12), -INT8_C( 119),  INT8_C(  59),  INT8_C( 112),  INT8_C(  16),
       INT8_C(   0),  INT8_C(  49),  INT8_C(  76), -INT8_C( 113), -INT8_C(  38),  INT8_C(  69), -INT8_C(  89),  INT8_C(  76),
       INT8_C(   8), -INT8_C(  93),  INT8_C(   2), -INT8_C(  27),  INT8_C(  40),  INT8_C(   0),  INT8_C(  73),  INT8_C(   1),
      -INT8_C( 101),  INT8_C(   1),  INT8_C(  55), -INT8_C(  16), -INT8_C(  92),  INT8_C(   0),  INT8_C(   4),  INT8_C(  90),
      -INT8_C(  28),  INT8_C(  97),  INT8_C(   1),  INT8_C(  85),  INT8_C(   0),  INT8_C(   8), -INT8_C( 124),      INT8_MIN,
       INT8_C(  74),  INT8_C( 112),  INT8_C(  48),  INT8_C(  36), -INT8_C(  55), -INT8_C( 112), -INT8_C( 109), -INT8_C(  27),
       INT8_C(  57),  INT8_C(   0),  INT8_C(  66),  INT8_C(  98),  INT8_C(   8),  INT8_C(  18), -INT8_C(  60),  INT8_C(  72),
       INT8_C(  21),  INT8_C(  72), -INT8_C(  71), -INT8_C( 112),  INT8_C(   3), -INT8_C( 127),  INT8_C(   4), -INT8_C(  17),
       INT8_C(  11),  INT8_C(  20),  INT8_C(  68), -INT8_C(  85), -INT8_C(  18), -INT8_C(  23),  INT8_C(   8),  INT8_C(  56),
       INT8_C(  91),  INT8_C( 124),  INT8_C(  93),  INT8_C(  36),  INT8_C(  19), -INT8_C(  16),  INT8_C(   1), -INT8_C(  50),
       INT8_C(   4), -INT8_C(  44),  INT8_C(  49),  INT8_C(  66), -INT8_C(  25), -INT8_C(  11),  INT8_C(  11), -INT8_C(   4),
      -INT8_C( 112), -INT8_C(  59), -INT8_C(  48), -INT8_C(  13),  INT8_C( 106), -INT8_C( 111), -INT8_C(  62),  INT8_C( 100),
      -INT8_C( 124),  INT8_C(  70),  INT8_C(  33), -INT8_C(  61),  INT8_C(  32),  INT8_C(  36), -INT8_C( 120),  INT8_C(   1),
      -INT8_C( 119),  INT8_C(  80), -INT8_C(  80),  INT8_C(  60),  INT8_C(  73),  INT8_C(   1),  INT8_C(   3),  INT8_C(  84),
      -INT8_C( 115),  INT8_C(  12), -INT8_C(  96),  INT8_C( 117),  INT8_C(  50), -INT8_C(  84),  INT8_C( 113),  INT8_C(  34),
       INT8_C(   1),  INT8_C(  66),  INT8_C(  22), -INT8_C(  37),  INT8_C(  65), -INT8_C(   8),  INT8_C(  64),  INT8_C(  22),
       INT8_C(  50),  INT8_C(  48),  INT8_C(  81),  INT8_C(  15), -INT8_C(  33), -INT8_C(  43), -INT8_C(   6), -INT8_C(  56),
       INT8_C(  46),  INT8_C(   0),  INT8_C(   4),  INT8_C( 119),  INT8_C(  64),  INT8_C(  15), -INT8_C(  43),  INT8_C(  64),
       INT8_C(  76),  INT8_C( 118),  INT8_C(  64),  INT8_C( 126),  INT8_C(   2), -INT8_C(  40),  INT8_C(   0),  INT8_C(  19),
       INT8_C(   8), -INT8_C(  74),  INT8_C(  36),  INT8_C(  91),  INT8_C(  13),  INT8_C(  36),  INT8_C( 113), -INT8_C(  18),
       INT8_C(  16),  INT8_C(  72),  INT8_C(  93),  INT8_C(  16),  INT8_C(  32),  INT8_C(  66), -INT8_C(  40),  INT8_C(  12),
       INT8_C(   2), -INT8_C(  35), -INT8_C(  58),  INT8_C( 102), -INT8_C(  20), -INT8_C( 101),  INT8_C(  87),  INT8_C(  48),
       INT8_C(  16), -INT8_C(  66), -INT8_C(  74),  INT8_C(  19),  INT8_C(  20),  INT8_C(  23), -INT8_C(  58), -INT8_C(  80),
       INT8_C(  13),  INT8_C(  53),  INT8_C(   0),  INT8_C(  12), -INT8_C(  12),  INT8_C( 124), -INT8_C(  86),  INT8_C(   0),
      -INT8_C(  58),  INT8_C(   7),  INT8_C(  54), -INT8_C(  26),  INT8_C(  15),  INT8_C(  15),  INT8_C(  53),  INT8_C(  97),
      -INT8_C(  20), -INT8_C(   5),  INT8_C(   5), -INT8_C( 104),  INT8_C(   0),  INT8_C(  30),  INT8_C(  17), -INT8_C(  88),
      -INT8_C(  64), -INT8_C(  57),  INT8_C(   9),  INT8_C(  18),  INT8_C(  30), -INT8_C(  94),  INT8_C(   0),  INT8_C(  44),
      -INT8_C(  41),  INT8_C(   9), -INT8_C(  24), -INT8_C(  53),      INT8_MIN, -INT8_C( 109), -INT8_C(  15),  INT8_C(  48),
       INT8_C(  18),  INT8_C(  40),  INT8_C(  86), -INT8_C(  63),  INT8_C(  34), -INT8_C( 117),  INT8_C(  90),  INT8_C(  35),
      -INT8_C( 124),  INT8_C(  32), -INT8_C(   5),  INT8_C(  29),  INT8_C(  64),  INT8_C(  12), -INT8_C(  59),  INT8_C(  28),
       INT8_C(  64), -INT8_C(  96),  INT8_C(  10),  INT8_C(  80),  INT8_C(  66),  INT8_C(  49),  INT8_C(  30),  INT8_C(  16),
      -INT8_C(  33),  INT8_C(   7),  INT8_C(  96), -INT8_C( 120), -INT8_C( 126), -INT8_C(  42), -INT8_C(  40),  INT8_C(  48),
      -INT8_C( 108),  INT8_C(   6),  INT8_C(  46),  INT8_C(  53), -INT8_C(  38), -INT8_C( 120),  INT8_C(  16),  INT8_C(  97),
      -INT8_C(  86),  INT8_C(   0),  INT8_C( 126),  INT8_C(  64),  INT8_C(  64),  INT8_C(  66),  INT8_C(   6),  INT8_C(   4),
      -INT8_C(  30),  INT8_C(   0),  INT8_C(   7),  INT8_C(  38),  INT8_C(   1),  INT8_C(  68),  INT8_C(   4),  INT8_C(   2),
       INT8_C(  12),  INT8_C(  36), -INT8_C(  82), -INT8_C(  64), -INT8_C(   5),  INT8_C(  33),  INT8_C(  27), -INT8_C(  95),
      -INT8_C(  58),  INT8_C(   9),  INT8_C(  33), -INT8_C(  48), -INT8_C(  47), -INT8_C( 121),  INT8_C(  49),  INT8_C( 123),
      -INT8_C(  37), -INT8_C(  81),  INT8_C( 101),  INT8_C(  60), -INT8_C(  14),  INT8_C( 108),  INT8_C(  48), -INT8_C(  42),
       INT8_C(   1), -INT8_C( 105), -INT8_C(   4),  INT8_C(  64), -INT8_C(  35),  INT8_C(  59),  INT8_C(  38),  INT8_C(  41),
       INT8_C(   0),  INT8_C(  21),  INT8_C(   0),  INT8_C(  25), -INT8_C(  60),  INT8_C(  10),  INT8_C(  64), -INT8_C(  70),
       INT8_C(  80), -INT8_C( 125), -INT8_C( 118),  INT8_C(   4),  INT8_C(   1),  INT8_C(   4), -INT8_C(  63),  INT8_C(  32),
       INT8_C( 107),  INT8_C(  38),  INT8_C(  34),  INT8_C(  94),  INT8_C(   2),  INT8_C(  16),  INT8_C(  52),  INT8_C(  16),
       INT8_C(  42),  INT8_C(  48), -INT8_C(  36),  INT8_C(   7),  INT8_C( 107),  INT8_C(  10),  INT8_C(  49), -INT8_C(  53),
       INT8_C( 104),  INT8_C(  65),  INT8_C(  36),  INT8_C(  36),  INT8_C(  40),  INT8_C( 112), -INT8_C(  60), -INT8_C(  32),
       INT8_C(  22),  INT8_C( 112),  INT8_C(  37),  INT8_C(   8),  INT8_C(  12), -INT8_C(  26), -INT8_C(  48), -INT8_C( 112),
       INT8_C(   8),  INT8_C(   2), -INT8_C(  10), -INT8_C(  97), -INT8_C(  91),  INT8_C(  32),  INT8_C(  17),  INT8_C(  80),
       INT8_C(  90),  INT8_C(  16),  INT8_C(  21), -INT8_C(  59),  INT8_C(  18),  INT8_C(   8), -INT8_C( 111),  INT8_C(  67),
       INT8_C(  73), -INT8_C(  73), -INT8_C( 127), -INT8_C(  75),  INT8_C(  18),  INT8_C(  85), -INT8_C( 107),  INT8_C(  48),
       INT8_C(   5), -INT8_C(  95),  INT8_C(  32),  INT8_C(  34), -INT8_C(  96),  INT8_C(  32),  INT8_C(   2),  INT8_C(  36),
       INT8_C(  36),  INT8_C(   0),  INT8_C(  68), -INT8_C(  30),  INT8_C(  32), -INT8_C( 127), -INT8_C(  78),  INT8_C(   4),
      -INT8_C( 111),  INT8_C(  10),  INT8_C(  73),  INT8_C(  36),  INT8_C(   0), -INT8_C( 102), -INT8_C( 113), -INT8_C(  36),
      -INT8_C( 110), -INT8_C(  98), -INT8_C( 111), -INT8_C(  60),  INT8_C(   0),  INT8_C(  33), -INT8_C(  11),  INT8_C(  33),
      -INT8_C(  30),  INT8_C(  48),  INT8_C(  43), -INT8_C( 125),  INT8_C(  72),  INT8_C(  53),  INT8_C(  48), -INT8_C( 105),
       INT8_C(  53),      INT8_MIN,  INT8_C( 112),  INT8_C(  79),  INT8_C(   1),  INT8_C(  36),  INT8_C(   2), -INT8_C( 109),
       INT8_C(  20),  INT8_C(  44),  INT8_C(   1),  INT8_C(  65),  INT8_C(   7),  INT8_C(  33),  INT8_C(  32), -INT8_C( 103),
       INT8_C(  64),  INT8_C(   0),  INT8_C(  89),  INT8_C(  65), -INT8_C(  55),  INT8_C(  82), -INT8_C(   6),  INT8_C(  47),
      -INT8_C( 127),  INT8_C(  37),  INT8_C(   0), -INT8_C(  35),  INT8_C(  64),  INT8_C( 117),  INT8_C(   4), -INT8_C( 113),
      -INT8_C( 124),  INT8_C( 107), -INT8_C(  18), -INT8_C(  10),  INT8_C(  18), -INT8_C(  47), -INT8_C( 119), -INT8_C(  46),
      -INT8_C(   3),  INT8_C(   9),  INT8_C(   9),  INT8_C(   4),  INT8_C(  40),  INT8_C(   0),  INT8_C(  13),  INT8_C(   5),
      -INT8_C(  10), -INT8_C(   5),  INT8_C(  66),  INT8_C(  68),  INT8_C(  78),  INT8_C(  64), -INT8_C( 112),  INT8_C(   0),
       INT8_C( 101), -INT8_C(  42),  INT8_C(   8), -INT8_C( 121),  INT8_C(   9),  INT8_C(  32),  INT8_C(   4),  INT8_C(  64),
       INT8_C(  18),  INT8_C(  60),  INT8_C(  54),  INT8_C(  12),  INT8_C(  13), -INT8_C(  64),  INT8_C(   0),  INT8_C(  11),
      -INT8_C( 120),  INT8_C(  27),  INT8_C(  15),  INT8_C(   1),  INT8_C(  81),  INT8_C(   4),  INT8_C(   4),  INT8_C(  64),
      -INT8_C(  88),  INT8_C(   4),  INT8_C(  33), -INT8_C(  10), -INT8_C( 114), -INT8_C(  71), -INT8_C(  57),  INT8_C(  19),
      -INT8_C( 118),  INT8_C( 117), -INT8_C(  77),  INT8_C(  16),  INT8_C(  24),  INT8_C(   1),  INT8_C(  27), -INT8_C(  93),
       INT8_C(  62),  INT8_C(  82), -INT8_C( 127),  INT8_C(  75),  INT8_C(  19), -INT8_C(  48),  INT8_C(  66), -INT8_C(  36),
      -INT8_C(  12),  INT8_C(  66),  INT8_C(  14),  INT8_C(  79),  INT8_C(   2), -INT8_C(  27), -INT8_C(  95), -INT8_C(  69),
       INT8_C(  50), -INT8_C(  58),  INT8_C(  48),  INT8_C(  64),  INT8_C(  73),  INT8_C(  24), -INT8_C(  76),  INT8_C(   3),
       INT8_C(   0),  INT8_C(  38), -INT8_C(  22),  INT8_C(   2),  INT8_C(  72),  INT8_C(   1),  INT8_C(  50), -INT8_C(  90),
       INT8_C(  80),  INT8_C(  11), -INT8_C(  14),  INT8_C( 107),  INT8_C( 101),  INT8_C(  72),  INT8_C(  71),  INT8_C(  73),
      -INT8_C(  82),  INT8_C(   1),  INT8_C(  41), -INT8_C(  63),  INT8_C(  10), -INT8_C( 118),  INT8_C( 124),  INT8_C(  61),
       INT8_C(   0),  INT8_C(  45), -INT8_C(   3),  INT8_C(   0), -INT8_C(  91), -INT8_C(  79),  INT8_C(  31), -INT8_C( 109),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  16),  INT8_C(   0),  INT8_C(  14),  INT8_C(   2),  INT8_C(  33),  INT8_C( 102),
       INT8_C(  87),  INT8_C(  25), -INT8_C(  47),  INT8_C(  36),  INT8_C(   2),  INT8_C(  25),  INT8_C(   5),  INT8_C(   0),
       INT8_C(  44),  INT8_C(  60),  INT8_C(  66),  INT8_C(  65),  INT8_C(   8),  INT8_C(  78), -INT8_C( 122), -INT8_C( 103),
       INT8_C( 124), -INT8_C( 125), -INT8_C(  87),  INT8_C(  33),  INT8_C(  37),  INT8_C(  72), -INT8_C(  76),  INT8_C(  77),
      -INT8_C(  47), -INT8_C( 114), -INT8_C(  50),  INT8_C(  10),  INT8_C(  17), -INT8_C(  76),  INT8_C(   0),  INT8_C(  96),
       INT8_C(  15),  INT8_C(   2), -INT8_C( 120),  INT8_C(  33),  INT8_C(  48), -INT8_C(  62), -INT8_C( 126),  INT8_C(  66),
       INT8_C(   0),  INT8_C(  84),  INT8_C(  48),  INT8_C(   9), -INT8_C(  94),  INT8_C(  62),  INT8_C(   0),  INT8_C(  30),
      -INT8_C(  63),  INT8_C(  75),  INT8_C(   0), -INT8_C( 122) };

  static int8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t
      rv,
      av = simde_svld1_s8(pg, &(a[i])),
      bv = simde_svld1_s8(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(INT8_C(0)));
    rv = simde_svand_s8_m(pv, av, bv);

    simde_svst1_s8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vi8(len, e, r);

  return 0;
#else
  int8_t p[1024], a[1024], b[1024], e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_s8(pg, &(a[i]));
    bv = simde_svld1_s8(pg, &(b[i]));

    ev = simde_svand_s8_m(pv, av, bv);

    simde_svst1_s8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

/* the simde_svand_n_s8_m test needs finishing */
//static int
//test_simde_svand_n_s8_m (SIMDE_MUNIT_TEST_ARGS) {
//#if 0
//
//
//  static int8_t r[sizeof(e) / sizeof(e[0])];
//  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
//  int32_t i = 0;
//  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
//  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
//    simde_svint8_t
//      rv,
//      av = simde_svld1_s8(pg, &(a[i])),
//      bv = simde_svld1_s8(pg, &(b[i]));
//    simde_svbool_t pv;
//
//    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(INT8_C(0)));
//    rv = simde_svand_s8_m(pv, av, bv);
//
//    simde_svst1_s8(pg, &(r[i]), rv);
//
//    i += simde_svcntb();
//    pg = simde_svwhilelt_b8_s32(i, len);
//  }
//
//  simde_assert_equal_vi8(len, e, r);
//
//  return 0;
//#else
//  int8_t p[1024], a[1024], b, e[1024];
//  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));
//
//  fputc('\n', stdout);
//
//  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
//  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
//  b = simde_test_codegen_random_i8();
//
//  int32_t i = 0;
//  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
//  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
//    simde_svint8_t av, ev;
//    simde_svbool_t pv;
//
//    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
//    av = simde_svld1_s8(pg, &(a[i]));
//
//    ev = simde_svand_n_s8_m(pv, av, b);
//
//    simde_svst1_s8(pg, &(e[i]), ev);
//    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));
//
//    i += simde_svcntb();
//    pg = simde_svwhilelt_b8_s32(i, len);
//  }
//
//  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
//  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), a);
//  simde_test_codegen_write_1i8(1, b);
//  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), e);
//
//  return 1;
//#endif
//}

static int
test_simde_svand_s16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0) };
  static const int16_t a[] =
    {  INT16_C( 30444),  INT16_C(  4872), -INT16_C( 19789),  INT16_C( 32466),  INT16_C(  1593),  INT16_C(  2365), -INT16_C(   535), -INT16_C( 12482),
      -INT16_C( 11858),  INT16_C( 16121),  INT16_C( 18676), -INT16_C(  6322),  INT16_C( 24804), -INT16_C( 21092),  INT16_C( 19788),  INT16_C( 14436),
       INT16_C( 27843),  INT16_C( 30283),  INT16_C(  7454),  INT16_C( 22772),  INT16_C( 12579),  INT16_C(  3169), -INT16_C( 24786), -INT16_C(  8740),
      -INT16_C( 10896),  INT16_C( 25883),  INT16_C( 27165),  INT16_C(   588), -INT16_C(  5942),  INT16_C(  5807),  INT16_C(  4917), -INT16_C(  1970),
      -INT16_C( 26241), -INT16_C( 24978),  INT16_C( 25270), -INT16_C(  9482),  INT16_C( 22419), -INT16_C( 15898), -INT16_C( 15625),  INT16_C( 26526),
      -INT16_C( 17769), -INT16_C( 18996),  INT16_C(  6180), -INT16_C(  4425),  INT16_C( 26112),  INT16_C( 13573),  INT16_C( 21369), -INT16_C(  2003),
      -INT16_C( 25619), -INT16_C( 23658), -INT16_C( 29443), -INT16_C( 28547),  INT16_C( 25828), -INT16_C(  9390), -INT16_C(  4058), -INT16_C( 16830),
       INT16_C(  4010), -INT16_C( 12685),  INT16_C( 10791),  INT16_C( 10429), -INT16_C( 15728),  INT16_C(  2397), -INT16_C( 29931),  INT16_C(   513),
      -INT16_C( 26586),  INT16_C(  9382),  INT16_C(  8996),  INT16_C(  2228),  INT16_C(  1671), -INT16_C( 20765),  INT16_C(  9975), -INT16_C( 24212),
      -INT16_C(  8395),  INT16_C( 23664),  INT16_C( 11529), -INT16_C( 26236), -INT16_C(  7441),  INT16_C(  1186), -INT16_C( 23699), -INT16_C( 27897),
      -INT16_C( 21189),  INT16_C( 24759),  INT16_C( 27856),  INT16_C( 22632),  INT16_C( 19570),  INT16_C( 26886),  INT16_C( 29298), -INT16_C( 22773),
       INT16_C( 31569),  INT16_C( 23043), -INT16_C( 30552), -INT16_C( 26637), -INT16_C( 27286), -INT16_C( 10341), -INT16_C( 24008),  INT16_C( 29802),
       INT16_C(  8783),  INT16_C(  8404),  INT16_C( 15502),  INT16_C(   120),  INT16_C( 32392), -INT16_C(  1430),  INT16_C( 30192),  INT16_C( 16801),
      -INT16_C( 23056), -INT16_C( 26469), -INT16_C( 29139), -INT16_C( 26833), -INT16_C( 13789),  INT16_C( 23406), -INT16_C( 10131), -INT16_C( 17201),
      -INT16_C( 23558), -INT16_C( 30500),  INT16_C( 21728),  INT16_C( 26761), -INT16_C(  3118), -INT16_C( 15773),  INT16_C(  1128),  INT16_C( 22531),
      -INT16_C( 24919), -INT16_C( 10512),  INT16_C(  7980),  INT16_C( 20333), -INT16_C(  9239),  INT16_C( 22187),  INT16_C( 31412), -INT16_C( 20973),
      -INT16_C(  4322), -INT16_C(   457), -INT16_C( 16316),  INT16_C(  5734), -INT16_C( 13901),  INT16_C(  7129), -INT16_C(  9010),  INT16_C( 30579),
       INT16_C( 25467), -INT16_C( 22706), -INT16_C( 17534),  INT16_C( 27639), -INT16_C( 23913),  INT16_C( 19394), -INT16_C( 10980),  INT16_C( 15097),
       INT16_C( 12484),  INT16_C(  2104), -INT16_C( 24592), -INT16_C( 23777), -INT16_C(  1944),  INT16_C( 14014),  INT16_C( 12756),  INT16_C( 20398),
      -INT16_C(   876),  INT16_C(  5879), -INT16_C(  4425),  INT16_C( 20098),  INT16_C( 17552), -INT16_C( 21351), -INT16_C( 27879), -INT16_C(  8729),
       INT16_C(  8131), -INT16_C( 19226),  INT16_C(  1470),  INT16_C( 10071),  INT16_C(  5885), -INT16_C( 11939),  INT16_C(  2887), -INT16_C(  9183),
       INT16_C(  6151), -INT16_C( 16398),  INT16_C( 29702), -INT16_C( 27123), -INT16_C( 22600), -INT16_C( 11966),  INT16_C( 10554), -INT16_C(   593),
      -INT16_C( 27319),  INT16_C(  1969),  INT16_C(  2458), -INT16_C( 26834), -INT16_C( 29665),  INT16_C( 26216), -INT16_C( 30313), -INT16_C( 24766),
       INT16_C( 13729), -INT16_C( 22690),  INT16_C( 27561),  INT16_C( 25149), -INT16_C( 32750),  INT16_C( 19507), -INT16_C(  7511), -INT16_C(  3510),
      -INT16_C(  1161),  INT16_C(  4602),  INT16_C( 10244),  INT16_C(  9128),  INT16_C(  4532),  INT16_C( 19594), -INT16_C( 13158),  INT16_C( 15595),
       INT16_C( 18689), -INT16_C( 21533),  INT16_C(  8628), -INT16_C( 14579),  INT16_C( 16545),  INT16_C( 18963),  INT16_C( 23843), -INT16_C( 26051),
       INT16_C( 14169),  INT16_C( 23980),  INT16_C( 21599),  INT16_C(  5249),  INT16_C(  2917),  INT16_C(    96),  INT16_C( 19415), -INT16_C(  9924),
       INT16_C(  8084),  INT16_C( 18564), -INT16_C( 28352), -INT16_C(  7921),  INT16_C(  9169), -INT16_C(  3028),  INT16_C( 27008), -INT16_C(  9841),
       INT16_C( 15264), -INT16_C(   201), -INT16_C( 18289), -INT16_C(  2797),  INT16_C( 29635), -INT16_C( 25867),  INT16_C( 12734),  INT16_C( 21107),
      -INT16_C(  2224), -INT16_C( 28261), -INT16_C( 21880),  INT16_C( 23154), -INT16_C( 24883),  INT16_C( 20046), -INT16_C(  8953), -INT16_C( 22745),
       INT16_C( 24088), -INT16_C( 22361), -INT16_C( 17898), -INT16_C(  9827), -INT16_C( 28114), -INT16_C(  5004), -INT16_C(  6205),  INT16_C(  4927),
      -INT16_C(  9505),  INT16_C( 26532),  INT16_C(  6020),  INT16_C( 21185),  INT16_C(  4277), -INT16_C( 16992), -INT16_C( 14355),  INT16_C(  1636),
       INT16_C(  2854),  INT16_C( 15534),  INT16_C( 19398), -INT16_C(  3050), -INT16_C( 29987), -INT16_C( 24352),  INT16_C(  8049),  INT16_C( 20659),
       INT16_C( 22777),  INT16_C( 32440),  INT16_C( 31087),  INT16_C(  9424),  INT16_C( 28809),  INT16_C( 30689),  INT16_C( 17975),  INT16_C( 23933),
       INT16_C( 11089),  INT16_C(  6042), -INT16_C( 20362),  INT16_C( 21259), -INT16_C(  5062), -INT16_C( 21517), -INT16_C( 23029),  INT16_C(  1532),
      -INT16_C( 19202),  INT16_C( 28035),  INT16_C( 21293), -INT16_C( 18542),  INT16_C( 29635), -INT16_C(  1490), -INT16_C( 21575),  INT16_C(  2904),
      -INT16_C(  3370),  INT16_C( 19490),  INT16_C( 11938), -INT16_C(  9057), -INT16_C( 28134),  INT16_C(  9607), -INT16_C( 31944),  INT16_C( 14122),
      -INT16_C( 21193),  INT16_C( 26020),  INT16_C( 13824), -INT16_C( 15588),  INT16_C( 19114),  INT16_C( 25534),  INT16_C(  5877), -INT16_C( 13458),
      -INT16_C( 28408), -INT16_C( 21993), -INT16_C( 18753), -INT16_C(  9850),  INT16_C(  3400), -INT16_C( 32514),  INT16_C( 10641), -INT16_C( 14153),
       INT16_C( 23766), -INT16_C( 10451),  INT16_C( 18834),  INT16_C( 15514),  INT16_C( 22675), -INT16_C( 30560),  INT16_C(  3694),  INT16_C( 30291),
       INT16_C( 27295),  INT16_C( 24096), -INT16_C( 23008),  INT16_C( 26679),  INT16_C( 14004),  INT16_C( 17897), -INT16_C( 24481),  INT16_C( 13581),
       INT16_C( 15356), -INT16_C( 28916), -INT16_C( 22652),  INT16_C(  6347),  INT16_C( 27647),  INT16_C( 28320), -INT16_C(  2950),  INT16_C(  6628),
       INT16_C(  1374),  INT16_C( 32632), -INT16_C( 20565),  INT16_C( 24551), -INT16_C( 12059),  INT16_C( 17572), -INT16_C( 19855),  INT16_C( 28026),
      -INT16_C( 30995),  INT16_C( 29180), -INT16_C( 14291),  INT16_C( 11657),  INT16_C( 10803), -INT16_C( 21093),  INT16_C( 32542),  INT16_C( 31943),
       INT16_C( 16260),  INT16_C( 12539), -INT16_C(  7186), -INT16_C( 11121),  INT16_C( 13491),  INT16_C(  9240), -INT16_C( 27930), -INT16_C( 11374),
      -INT16_C( 29159),  INT16_C( 17988), -INT16_C( 12714), -INT16_C( 30093),  INT16_C(  3832),  INT16_C(  5687), -INT16_C(   370),  INT16_C(  4754),
      -INT16_C( 29123),  INT16_C( 11330), -INT16_C( 11663),  INT16_C(  9216),  INT16_C(  6150), -INT16_C(  5047), -INT16_C(  9301), -INT16_C( 15169),
       INT16_C(   873), -INT16_C( 16374),  INT16_C( 32465), -INT16_C( 14006), -INT16_C( 32372),  INT16_C(  6879),  INT16_C( 29312), -INT16_C( 17107),
       INT16_C( 28416),  INT16_C( 29161), -INT16_C(  5823),  INT16_C( 18325), -INT16_C(  8702), -INT16_C( 21197), -INT16_C(  3399),  INT16_C(  9073),
       INT16_C( 31734), -INT16_C( 14365),  INT16_C( 11769), -INT16_C( 31087),  INT16_C( 28846),  INT16_C( 11936), -INT16_C( 12830), -INT16_C(  7444),
      -INT16_C( 10947),  INT16_C( 32339), -INT16_C(  5697), -INT16_C( 15930), -INT16_C(  1593), -INT16_C( 32402), -INT16_C(  8212), -INT16_C(  7516),
      -INT16_C( 30886),  INT16_C( 21673),  INT16_C( 15028),  INT16_C( 25306),  INT16_C( 31403), -INT16_C( 29295),  INT16_C( 32072), -INT16_C( 31376),
      -INT16_C( 15534),  INT16_C(  4355), -INT16_C( 13908),  INT16_C( 29906),  INT16_C( 16579), -INT16_C( 20491), -INT16_C( 26337),  INT16_C( 31377),
       INT16_C( 14880), -INT16_C( 11058), -INT16_C( 22411),  INT16_C(  8246), -INT16_C( 14558),  INT16_C( 27309),  INT16_C(  7492), -INT16_C( 26641),
      -INT16_C(  3103), -INT16_C( 29272),  INT16_C( 31676),  INT16_C( 32513), -INT16_C(  2373), -INT16_C(  9426), -INT16_C( 16497), -INT16_C( 20651),
       INT16_C(  9210),  INT16_C( 28547), -INT16_C( 17717), -INT16_C(  4721),  INT16_C( 15489), -INT16_C( 14760),  INT16_C( 18266),  INT16_C( 15197),
       INT16_C(  1338), -INT16_C(  2104), -INT16_C( 13696),  INT16_C( 15478), -INT16_C( 23104),  INT16_C( 20503),  INT16_C( 27748),  INT16_C( 24319),
      -INT16_C( 31857),  INT16_C( 23245),  INT16_C( 23613), -INT16_C( 16825), -INT16_C( 24679), -INT16_C(  3196), -INT16_C(  7705),  INT16_C(  8494),
      -INT16_C(  2329),  INT16_C( 26392), -INT16_C( 28736), -INT16_C( 32349), -INT16_C( 17868), -INT16_C( 26415), -INT16_C( 12250), -INT16_C( 18953),
      -INT16_C( 15277), -INT16_C( 28657),  INT16_C( 22305), -INT16_C( 17841), -INT16_C( 11274), -INT16_C(  8787), -INT16_C(  9291), -INT16_C( 25345),
       INT16_C(  6097), -INT16_C( 28157), -INT16_C( 22618), -INT16_C(  9709), -INT16_C(  7071), -INT16_C( 30605),  INT16_C( 27316),  INT16_C(  2109),
       INT16_C( 19758),  INT16_C( 20376), -INT16_C(  6236), -INT16_C( 26103), -INT16_C( 18757),  INT16_C( 28792),  INT16_C( 30609),  INT16_C( 25356),
       INT16_C(  3982),  INT16_C( 13813),  INT16_C(  2230) };
  static const int16_t b[] =
    {  INT16_C(  5231),  INT16_C(  9499),  INT16_C( 11036),  INT16_C(  2109), -INT16_C(  8787), -INT16_C( 25944),  INT16_C( 20923), -INT16_C(  6731),
       INT16_C(  8082), -INT16_C( 17740),  INT16_C(  7571), -INT16_C( 16738), -INT16_C(  3586),  INT16_C( 22138), -INT16_C( 26287), -INT16_C( 16324),
       INT16_C( 22701), -INT16_C( 13851),  INT16_C(  9091),  INT16_C( 12497),  INT16_C( 30976), -INT16_C( 17462),  INT16_C( 32714),  INT16_C( 23713),
       INT16_C( 21919),  INT16_C( 12823), -INT16_C( 19086),  INT16_C( 28912),  INT16_C( 27302), -INT16_C(  2106),  INT16_C(   515), -INT16_C( 20297),
      -INT16_C( 25254), -INT16_C(  8839),  INT16_C( 19136), -INT16_C( 16370), -INT16_C( 10044), -INT16_C( 29060),  INT16_C(  7512), -INT16_C(  2069),
       INT16_C(   626), -INT16_C(  7127),  INT16_C(  6839),  INT16_C( 23892),  INT16_C(  6788), -INT16_C( 30635),  INT16_C(  3100),  INT16_C( 30520),
      -INT16_C( 19799),  INT16_C( 26964),  INT16_C( 25340), -INT16_C( 16342), -INT16_C( 22981), -INT16_C( 27825),  INT16_C( 15043),  INT16_C( 13706),
      -INT16_C( 19652), -INT16_C(  3303),  INT16_C( 28109),  INT16_C( 21072), -INT16_C( 23161), -INT16_C( 23590),  INT16_C(  4786),  INT16_C( 23322),
       INT16_C( 28612), -INT16_C( 15931), -INT16_C(  4143),  INT16_C(  3201), -INT16_C( 12139),  INT16_C( 22687),  INT16_C( 10506),  INT16_C( 18061),
      -INT16_C( 22819), -INT16_C( 21959), -INT16_C( 30189), -INT16_C( 25860), -INT16_C( 10705), -INT16_C(  7875),  INT16_C( 22761), -INT16_C( 21187),
       INT16_C(   711), -INT16_C( 26514), -INT16_C(  3855), -INT16_C( 31067),  INT16_C( 17600), -INT16_C( 13346),  INT16_C( 27502),  INT16_C( 19217),
       INT16_C( 19217),  INT16_C(  9461), -INT16_C(  3371),  INT16_C(  1214), -INT16_C(  1080), -INT16_C( 19994),  INT16_C(  9043),  INT16_C(  6751),
      -INT16_C( 13019),  INT16_C(  5811),  INT16_C( 22717),  INT16_C( 32412),  INT16_C( 31388),  INT16_C(  2633),  INT16_C( 23269), -INT16_C(  2475),
       INT16_C( 19365),  INT16_C( 31258), -INT16_C( 10179),  INT16_C(  1407),  INT16_C( 26067),  INT16_C( 10167),  INT16_C(  5768), -INT16_C( 21183),
      -INT16_C(  2845), -INT16_C( 24125),  INT16_C( 24396), -INT16_C(  5857),  INT16_C( 26841), -INT16_C( 16653),  INT16_C( 18882),  INT16_C( 26804),
      -INT16_C( 12652), -INT16_C( 11806),  INT16_C( 24998),  INT16_C( 31190), -INT16_C( 29242),  INT16_C( 20128), -INT16_C(  7517), -INT16_C( 30725),
      -INT16_C( 16682),  INT16_C(  9000),  INT16_C( 18205), -INT16_C(  2548), -INT16_C(    81),  INT16_C( 29108),  INT16_C( 26696), -INT16_C(  8999),
      -INT16_C( 17354), -INT16_C(  9043), -INT16_C( 31715), -INT16_C(  7082), -INT16_C(  2543), -INT16_C( 19150),  INT16_C( 11992), -INT16_C( 20676),
       INT16_C( 25836),  INT16_C(  2770), -INT16_C(  8533),  INT16_C( 23040), -INT16_C( 18979),  INT16_C(  9931), -INT16_C( 23267),  INT16_C( 21506),
      -INT16_C( 20383),  INT16_C( 32304), -INT16_C( 31180),  INT16_C( 17762), -INT16_C( 27267),  INT16_C( 22010),  INT16_C( 14019), -INT16_C( 20732),
      -INT16_C( 10598),  INT16_C( 17849), -INT16_C( 17740), -INT16_C( 28001),  INT16_C( 27503), -INT16_C( 29512), -INT16_C( 17904),  INT16_C( 29152),
       INT16_C(  4458), -INT16_C( 24849),  INT16_C( 21143),  INT16_C(  5348), -INT16_C(  8473), -INT16_C( 21910),  INT16_C( 28181), -INT16_C( 20647),
       INT16_C(  4933), -INT16_C(  1547), -INT16_C( 27443),  INT16_C( 15499),  INT16_C( 17407),  INT16_C(  4040), -INT16_C( 22018),  INT16_C( 26752),
       INT16_C( 28858),  INT16_C( 20743), -INT16_C(  5182), -INT16_C( 22170), -INT16_C( 12087), -INT16_C(  8621), -INT16_C( 21442), -INT16_C( 31858),
      -INT16_C( 31809), -INT16_C( 29571),  INT16_C(  2071),  INT16_C(  6088), -INT16_C( 28340),  INT16_C( 18982), -INT16_C( 22726), -INT16_C(  2894),
      -INT16_C( 18153), -INT16_C(  9915), -INT16_C( 21596),  INT16_C( 28290), -INT16_C( 10885), -INT16_C( 17844), -INT16_C(  9599),  INT16_C( 16701),
      -INT16_C( 17827),  INT16_C( 30157), -INT16_C( 26941),  INT16_C(  3980), -INT16_C( 19929),  INT16_C( 24921),  INT16_C(  2905),  INT16_C( 28757),
      -INT16_C( 25915),  INT16_C( 26953), -INT16_C( 13498), -INT16_C( 15913),  INT16_C(  9376),  INT16_C(  8827), -INT16_C( 17922),  INT16_C( 23651),
       INT16_C( 12403),  INT16_C( 14033),  INT16_C( 24006), -INT16_C(  4795), -INT16_C( 25073),  INT16_C( 26958), -INT16_C( 23638),  INT16_C( 28633),
       INT16_C(  9022), -INT16_C( 31528), -INT16_C( 20242), -INT16_C( 28859), -INT16_C( 15916), -INT16_C( 11599),  INT16_C(  5242), -INT16_C(  4818),
      -INT16_C(   188),  INT16_C(  2852),  INT16_C( 26972),  INT16_C( 27896),  INT16_C( 18184), -INT16_C( 19755), -INT16_C( 20758),  INT16_C( 10273),
      -INT16_C(  1583), -INT16_C( 16212), -INT16_C(  3415),  INT16_C( 32079),  INT16_C(   179),  INT16_C( 11600),  INT16_C( 32276),  INT16_C( 22554),
       INT16_C( 15998), -INT16_C(  9629),  INT16_C( 23720), -INT16_C( 20410),  INT16_C(  7075), -INT16_C( 29342), -INT16_C( 31798), -INT16_C( 25674),
       INT16_C( 25212),  INT16_C(  9819), -INT16_C( 21932),  INT16_C(  1955), -INT16_C(  3158), -INT16_C( 16844),  INT16_C( 20338), -INT16_C(  4073),
       INT16_C( 31373),  INT16_C( 13770),  INT16_C(  4566),  INT16_C( 31205),  INT16_C( 18220), -INT16_C(  2553), -INT16_C( 16950),  INT16_C( 18322),
      -INT16_C(  4833),  INT16_C( 29805),  INT16_C(  4248),  INT16_C( 17019), -INT16_C( 20476),  INT16_C( 30209),  INT16_C(  6399), -INT16_C( 29594),
       INT16_C( 12434),  INT16_C( 27074), -INT16_C( 22719),  INT16_C( 28386), -INT16_C(  5649), -INT16_C( 18076), -INT16_C(  2394), -INT16_C( 14848),
       INT16_C( 28132),  INT16_C( 31802), -INT16_C( 19074), -INT16_C( 32066), -INT16_C( 16539),  INT16_C( 25848),  INT16_C( 24279),  INT16_C( 27377),
      -INT16_C( 19570), -INT16_C( 12077), -INT16_C( 19110),  INT16_C( 18750), -INT16_C( 23905),  INT16_C( 17667),  INT16_C(   921),  INT16_C( 32011),
       INT16_C( 17777), -INT16_C(  4103), -INT16_C( 18437),  INT16_C( 24689),  INT16_C( 26999),  INT16_C( 20165), -INT16_C( 18745),  INT16_C( 21944),
      -INT16_C( 29847), -INT16_C( 15579),  INT16_C( 25409), -INT16_C(  8179),  INT16_C(  4102), -INT16_C( 24795),  INT16_C( 12563), -INT16_C( 31716),
       INT16_C(  5494),  INT16_C( 29043), -INT16_C(  6964),  INT16_C( 17362), -INT16_C( 26803),  INT16_C(  5266),  INT16_C( 19021), -INT16_C( 18838),
      -INT16_C( 28714),  INT16_C(  6009), -INT16_C( 30989), -INT16_C(  1545),  INT16_C(  7318), -INT16_C( 21864), -INT16_C( 19379), -INT16_C( 15314),
      -INT16_C( 23863), -INT16_C( 27339),  INT16_C(  1926), -INT16_C( 11047),  INT16_C( 27550), -INT16_C(  5144),  INT16_C( 21173), -INT16_C( 29791),
       INT16_C(  7138), -INT16_C( 10846), -INT16_C( 26207),  INT16_C( 14542),  INT16_C( 26294),  INT16_C(   994),  INT16_C(  4122), -INT16_C(  7225),
      -INT16_C(   590),  INT16_C( 14712),  INT16_C( 20740), -INT16_C( 23795), -INT16_C(  2628),  INT16_C( 29326),  INT16_C( 12360),  INT16_C( 11005),
      -INT16_C( 24501), -INT16_C(  4865), -INT16_C( 12999), -INT16_C(  4316),  INT16_C(  1587),  INT16_C( 19955), -INT16_C( 17897), -INT16_C( 14032),
      -INT16_C( 22345), -INT16_C( 17406),  INT16_C(  4090), -INT16_C( 18849), -INT16_C(  4859),  INT16_C( 19752),  INT16_C(  9757),  INT16_C( 26743),
       INT16_C( 30406), -INT16_C(   171),  INT16_C( 31043),  INT16_C( 30447), -INT16_C(  7552), -INT16_C( 26685), -INT16_C(  3172),  INT16_C( 21600),
       INT16_C( 25499), -INT16_C( 27376),  INT16_C( 28530),  INT16_C( 30540),  INT16_C( 29788),  INT16_C( 31428),  INT16_C( 15258),  INT16_C( 24802),
       INT16_C( 14257), -INT16_C(  2976),  INT16_C( 20401),  INT16_C( 12650),  INT16_C( 11569), -INT16_C( 12856),  INT16_C( 10272), -INT16_C( 17375),
       INT16_C( 12683), -INT16_C(   431), -INT16_C( 25184), -INT16_C(   651),  INT16_C( 14866), -INT16_C( 21385),  INT16_C( 22901),  INT16_C(  9997),
       INT16_C( 28049),  INT16_C( 16923), -INT16_C( 31044), -INT16_C(  4749),  INT16_C( 15283), -INT16_C( 11078), -INT16_C(  9117), -INT16_C(  4208),
      -INT16_C(  7923), -INT16_C( 20755),  INT16_C( 25215), -INT16_C( 28245),  INT16_C(  8860),  INT16_C(  4669),  INT16_C( 19067),  INT16_C(  3129),
       INT16_C( 21687),  INT16_C( 29518), -INT16_C( 15910), -INT16_C( 29088),  INT16_C(  7164),  INT16_C( 24674), -INT16_C(  3337),  INT16_C(  1103),
       INT16_C( 15571),  INT16_C( 21170),  INT16_C( 23966),  INT16_C( 15331),  INT16_C(  8575), -INT16_C(  1203), -INT16_C( 31125),  INT16_C(  8967),
       INT16_C( 22234), -INT16_C( 19050), -INT16_C(  2281),  INT16_C(  5187), -INT16_C( 23278),  INT16_C(  2420), -INT16_C( 15465),  INT16_C( 27149),
      -INT16_C( 16129), -INT16_C( 25155), -INT16_C( 24547), -INT16_C( 25128),  INT16_C(  9665),  INT16_C( 11672), -INT16_C( 24661), -INT16_C( 31152),
      -INT16_C(  6411),  INT16_C(  3387),  INT16_C( 32477), -INT16_C(  4319), -INT16_C( 27357), -INT16_C( 17672),  INT16_C(  1624),  INT16_C( 22308),
      -INT16_C(  7738), -INT16_C(  7180), -INT16_C( 12926),  INT16_C( 17280),  INT16_C(  6386), -INT16_C( 24976), -INT16_C( 16200), -INT16_C( 21212),
       INT16_C( 24487), -INT16_C( 31558), -INT16_C(  9251),  INT16_C(   116),  INT16_C( 27760), -INT16_C( 14150), -INT16_C(  8590),  INT16_C( 14367),
       INT16_C(  5312),  INT16_C( 16924), -INT16_C( 25375), -INT16_C( 11387), -INT16_C(  2379),  INT16_C( 28017), -INT16_C( 27210),  INT16_C( 23834),
      -INT16_C( 10764), -INT16_C( 11806),  INT16_C( 22192) };
  static const int16_t e[] =
    {  INT16_C(  5228),  INT16_C(   264),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1065),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C( 15024),  INT16_C(     0), -INT16_C( 23026),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2368),  INT16_C(     0),
       INT16_C( 18561),  INT16_C( 16449),  INT16_C(   258),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2112),  INT16_C(     0),  INT16_C( 23680),
       INT16_C(     0),  INT16_C(  8211),  INT16_C(  8208),  INT16_C(     0),  INT16_C( 26754),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 26278), -INT16_C( 25496),  INT16_C( 17024), -INT16_C( 16378),  INT16_C(     0), -INT16_C( 32668),  INT16_C(    80),  INT16_C(     0),
       INT16_C(     0), -INT16_C( 23544),  INT16_C(     0),  INT16_C( 19476),  INT16_C(   512),  INT16_C(     5),  INT16_C(    24),  INT16_C(     0),
      -INT16_C( 27991),  INT16_C(  8468),  INT16_C(   252), -INT16_C( 32728),  INT16_C(     0), -INT16_C( 27838),  INT16_C( 12290),  INT16_C( 13314),
       INT16_C(     0), -INT16_C( 15855),  INT16_C( 10245),  INT16_C(    16), -INT16_C( 32640),  INT16_C(     0),  INT16_C(     0),  INT16_C(   512),
       INT16_C(  2052),  INT16_C(   132),  INT16_C(  8960),  INT16_C(  2176),  INT16_C(     0),  INT16_C(  2179),  INT16_C(     0),  INT16_C(    12),
       INT16_C(     0),  INT16_C(  2096),  INT16_C(     0), -INT16_C( 26492),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 32507),
       INT16_C(     3),  INT16_C(    38),  INT16_C( 24784),  INT16_C(    32),  INT16_C(     0),  INT16_C(     0),  INT16_C( 25186),  INT16_C(     0),
       INT16_C( 19217),  INT16_C(     0), -INT16_C( 32640),  INT16_C(  1202), -INT16_C( 28344),  INT16_C(     0),  INT16_C(  8720),  INT16_C(  4170),
       INT16_C(     0),  INT16_C(   144),  INT16_C(     0),  INT16_C(    24),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(  6170),  INT16_C(     0),  INT16_C(  1327),  INT16_C( 16387),  INT16_C(   806),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 24350),  INT16_C(     0),  INT16_C(     0),  INT16_C( 26633),  INT16_C( 24784), -INT16_C( 32157),  INT16_C(     0),  INT16_C( 18432),
       INT16_C(     0), -INT16_C( 12064),  INT16_C(     0),  INT16_C( 18756), -INT16_C( 30272),  INT16_C( 18080),  INT16_C(     0), -INT16_C( 31213),
       INT16_C(     0),  INT16_C(     0),  INT16_C( 16388),  INT16_C(  5636),  INT16_C(     0),  INT16_C(  4496),  INT16_C(     0),  INT16_C( 21585),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24662),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1048),  INT16_C( 10808),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   512),  INT16_C(     0),  INT16_C(  9866),  INT16_C(  8468),  INT16_C( 17410),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 17410),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 29436),
       INT16_C(     0),  INT16_C(     0),  INT16_C(   180),  INT16_C(   535),  INT16_C(   621),  INT16_C(     0),  INT16_C(  2560),  INT16_C(     0),
       INT16_C(     0), -INT16_C( 24862),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(  4417),  INT16_C(   433),  INT16_C(   136),  INT16_C(  5130),  INT16_C(     0),  INT16_C(     0), -INT16_C( 30314),  INT16_C(  2048),
       INT16_C( 12448),  INT16_C(   262),  INT16_C( 27520),  INT16_C(     0),       INT16_MIN,  INT16_C(     0),  INT16_C(     0), -INT16_C( 32246),
       INT16_C(     0),  INT16_C(   120),  INT16_C(  2052),  INT16_C(   904),  INT16_C(  4356),  INT16_C(     0), -INT16_C( 31718),  INT16_C(     0),
       INT16_C(  2305), -INT16_C( 30399),  INT16_C(     0),  INT16_C( 17920),  INT16_C( 16417),  INT16_C(  2560),  INT16_C( 22529),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16121),  INT16_C(  8320),  INT16_C(  8232),  INT16_C( 10624),  INT16_C(     0),
       INT16_C( 12320),  INT16_C(     0),  INT16_C(     0), -INT16_C(  6911),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16977),
       INT16_C(  8976),  INT16_C(     0), -INT16_C( 24440),  INT16_C(  2624), -INT16_C( 32572),  INT16_C(     0),  INT16_C(  5122),  INT16_C(     0),
       INT16_C(     0),  INT16_C(  2084),  INT16_C(     0),  INT16_C( 18584),  INT16_C(   520), -INT16_C( 24492),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(  4736),  INT16_C(     0),  INT16_C(   177),  INT16_C(     0),  INT16_C( 17924),  INT16_C(     0),
       INT16_C(  2598),  INT16_C(     0),  INT16_C( 18560),  INT16_C(     0),  INT16_C(  2689),  INT16_C(     0),  INT16_C(   832),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1152),  INT16_C( 28808),  INT16_C(     0),  INT16_C( 17970),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 20737),  INT16_C( 17448),  INT16_C(     0), -INT16_C( 23542),  INT16_C(     0),
       INT16_C(     0),  INT16_C( 25601),  INT16_C(     0),  INT16_C(     0),  INT16_C( 12288),  INT16_C( 29184),  INT16_C(  2233),  INT16_C(  2112),
       INT16_C(     0),  INT16_C(     0),  INT16_C(  9728),  INT16_C( 19586), -INT16_C( 32758),  INT16_C(     0), -INT16_C( 32224),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 32228),  INT16_C(  2592),  INT16_C( 24760),  INT16_C(  5845),  INT16_C(     0),
      -INT16_C( 28408), -INT16_C( 32749), -INT16_C( 19430),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   401),  INT16_C( 18435),
       INT16_C(     0), -INT16_C( 14551),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2176),  INT16_C(  1606),  INT16_C(     0),
       INT16_C(  2569),  INT16_C( 16928),  INT16_C(     0),  INT16_C( 24581),  INT16_C(  4100),  INT16_C(     0),  INT16_C(  8211),  INT16_C(     0),
       INT16_C(  4468),  INT16_C(   256), -INT16_C( 23420),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1152),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(  6008), -INT16_C( 31069),  INT16_C( 23015),  INT16_C(     0),  INT16_C(   128), -INT16_C( 20415),  INT16_C(     0),
       INT16_C(     0),  INT16_C(  4404),  INT16_C(     0),  INT16_C(  1161),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(  4258), -INT16_C( 32352),  INT16_C(  4238),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 15486),
      -INT16_C( 29680),  INT16_C(    64),  INT16_C( 16388), -INT16_C( 32255),  INT16_C(     0),  INT16_C(     0),  INT16_C( 12296),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C( 16335),  INT16_C(     0),  INT16_C(     2),  INT16_C(     0), -INT16_C( 26109),  INT16_C(     0),
       INT16_C(     0), -INT16_C( 32766),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C( 28993),  INT16_C( 26945),  INT16_C( 18053),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C( 31488),  INT16_C( 11632),  INT16_C(     0),  INT16_C( 28684),  INT16_C( 10880),  INT16_C(  2434),  INT16_C(     0),
       INT16_C(     0),  INT16_C( 29760),  INT16_C( 18865),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  2080), -INT16_C( 24544),
       INT16_C(     0),  INT16_C( 21505),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 29679),  INT16_C( 22848),  INT16_C(  1280),
       INT16_C(     0),  INT16_C(     3), -INT16_C( 32596),  INT16_C( 25682),  INT16_C(     0), -INT16_C( 31568),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(  8309),  INT16_C(     0),  INT16_C(   512),  INT16_C(   557),  INT16_C(     0),  INT16_C(     0),
       INT16_C( 20641),  INT16_C(   264),  INT16_C( 16792),  INT16_C(  3584),  INT16_C(  4792),  INT16_C( 16418),  INT16_C(     0),  INT16_C(  1093),
       INT16_C(  8402),  INT16_C( 17026),  INT16_C(     0),  INT16_C( 10627),  INT16_C(     0), -INT16_C( 15800),  INT16_C(  1610),  INT16_C(  8965),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  5186),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 18957),
      -INT16_C( 32625),  INT16_C(     0),  INT16_C(    29), -INT16_C( 25536),  INT16_C(  1409),  INT16_C(     0), -INT16_C( 32349),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(  3776), -INT16_C( 32479),  INT16_C(     0), -INT16_C( 26416),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C( 32764),  INT16_C(     0),  INT16_C(     0),  INT16_C(  4338),  INT16_C(     0), -INT16_C( 16208), -INT16_C( 29660),
       INT16_C(  6017), -INT16_C( 32766),  INT16_C(     0),  INT16_C(     0),  INT16_C( 25696),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C( 31584),  INT16_C(     0), -INT16_C( 18767),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16648),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0) };

  static int16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t
      rv,
      av = simde_svld1_s16(pg, &(a[i])),
      bv = simde_svld1_s16(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(INT16_C(0)));
    rv = simde_svand_s16_z(pv, av, bv);

    simde_svst1_s16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vi16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(int16_t)], a[1024 / sizeof(int16_t)], b[1024 / sizeof(int16_t)], e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_s16(pg, &(a[i]));
    bv = simde_svld1_s16(pg, &(b[i]));

    ev = simde_svand_s16_z(pv, av, bv);

    simde_svst1_s16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_s16_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) };
  static const int16_t a[] =
    {  INT16_C( 28645), -INT16_C( 29907),  INT16_C( 10953),  INT16_C( 26254), -INT16_C( 15667),  INT16_C( 15755),  INT16_C( 12450),  INT16_C( 21144),
      -INT16_C(  2468),  INT16_C( 31196), -INT16_C(  7477),  INT16_C( 21434),  INT16_C( 23780),  INT16_C(  3964), -INT16_C(  8975), -INT16_C( 10733),
       INT16_C( 16459),  INT16_C(  5218), -INT16_C(  3989),  INT16_C( 14458),  INT16_C(  1459),  INT16_C( 21877),  INT16_C(  3381), -INT16_C( 27993),
      -INT16_C( 31997), -INT16_C( 12533), -INT16_C( 15003),  INT16_C( 18722), -INT16_C( 25055),  INT16_C(  4697),  INT16_C( 27770), -INT16_C( 14871),
       INT16_C( 19372),  INT16_C(  6105),  INT16_C( 21307), -INT16_C(  4529), -INT16_C( 15271), -INT16_C( 29116), -INT16_C(  5167), -INT16_C( 10976),
       INT16_C( 11119), -INT16_C( 11100), -INT16_C( 14608),  INT16_C(  4382),  INT16_C( 30565), -INT16_C(  8412),  INT16_C(  3555), -INT16_C( 28763),
       INT16_C( 32344), -INT16_C( 27737), -INT16_C(  2350),  INT16_C( 11138), -INT16_C( 14661), -INT16_C( 29511), -INT16_C(  9551),  INT16_C(  8289),
       INT16_C(  1285), -INT16_C(  2315),  INT16_C(  5068),  INT16_C( 12551),  INT16_C( 11146),  INT16_C( 27920), -INT16_C( 19144), -INT16_C( 28420),
      -INT16_C( 23756),  INT16_C(  1572), -INT16_C( 22886),  INT16_C( 21809), -INT16_C(  5524),  INT16_C(  7649),  INT16_C( 17348), -INT16_C( 13762),
       INT16_C( 13128),  INT16_C(  5312), -INT16_C( 14522), -INT16_C( 12219),  INT16_C( 22259),  INT16_C( 11069),  INT16_C( 14603),  INT16_C( 16316),
      -INT16_C(  7971),  INT16_C( 30533),  INT16_C( 30342), -INT16_C(  3380), -INT16_C( 21151),  INT16_C(  9487),  INT16_C( 19952),  INT16_C( 14831),
      -INT16_C( 20608), -INT16_C( 14771), -INT16_C( 27785),  INT16_C( 27286), -INT16_C( 11287), -INT16_C(  2923),  INT16_C( 20749), -INT16_C(  5580),
       INT16_C( 31025), -INT16_C( 18591),  INT16_C( 11760),  INT16_C( 20905), -INT16_C( 17958), -INT16_C( 13450),  INT16_C( 26118), -INT16_C( 30972),
       INT16_C( 20757), -INT16_C( 29619), -INT16_C(  6940), -INT16_C( 12810), -INT16_C( 29513), -INT16_C( 15166), -INT16_C(  2339),  INT16_C(  4014),
       INT16_C(  3951),  INT16_C( 24518),  INT16_C( 28732),  INT16_C(  6064),  INT16_C( 10025),  INT16_C( 12258), -INT16_C(  6515), -INT16_C( 23882),
       INT16_C(  1079),  INT16_C(  7215),  INT16_C(  9704), -INT16_C( 24599), -INT16_C( 21583), -INT16_C( 28828),  INT16_C(  4769),  INT16_C(  4510),
       INT16_C( 25634),  INT16_C( 24176),  INT16_C(  8660), -INT16_C(   651),  INT16_C( 22344), -INT16_C( 10963), -INT16_C(  7363),  INT16_C( 30071),
      -INT16_C( 22809), -INT16_C( 12399),  INT16_C( 31436),  INT16_C( 32111), -INT16_C( 11482), -INT16_C( 14580), -INT16_C( 21787),  INT16_C(  2008),
       INT16_C( 18703), -INT16_C(  7322), -INT16_C(  9366), -INT16_C( 19743),  INT16_C(  3635),  INT16_C( 28807), -INT16_C(   271), -INT16_C(  9755),
       INT16_C( 30373),  INT16_C( 29096),  INT16_C(  6129),  INT16_C(  6126), -INT16_C(  1046), -INT16_C( 12066), -INT16_C( 18523), -INT16_C( 19241),
       INT16_C( 15616),  INT16_C( 27288),  INT16_C( 31001),  INT16_C( 19484), -INT16_C( 23673),  INT16_C( 30908), -INT16_C( 23903),  INT16_C( 18001),
      -INT16_C(  1512),  INT16_C(  2487), -INT16_C( 23023), -INT16_C(   992), -INT16_C(    95),  INT16_C( 18124), -INT16_C( 23626), -INT16_C( 18693),
      -INT16_C( 27679), -INT16_C(  1504),  INT16_C( 15372), -INT16_C( 27834),  INT16_C(   735), -INT16_C( 32757),  INT16_C( 23972), -INT16_C( 16953),
       INT16_C( 32343),  INT16_C( 26822), -INT16_C(  6364), -INT16_C( 15004),  INT16_C( 12518), -INT16_C( 25588),  INT16_C(  2004), -INT16_C( 19118),
       INT16_C( 29338), -INT16_C( 22865), -INT16_C(  2642), -INT16_C( 29383),  INT16_C( 17655), -INT16_C( 25587), -INT16_C( 11103), -INT16_C(  1959),
       INT16_C(  8019),  INT16_C( 30561), -INT16_C( 15098), -INT16_C(  5059),  INT16_C( 18934), -INT16_C( 13688), -INT16_C(  9648), -INT16_C(  5505),
       INT16_C( 11852), -INT16_C(  1392), -INT16_C( 14045),  INT16_C(  6791), -INT16_C( 27379), -INT16_C( 20554),  INT16_C(  3945), -INT16_C( 17241),
       INT16_C(  2095),  INT16_C( 13620),  INT16_C( 29134), -INT16_C( 15326), -INT16_C( 21830),  INT16_C(  2702),  INT16_C(  3461), -INT16_C( 11788),
      -INT16_C( 31685),  INT16_C( 24268),  INT16_C( 21325),  INT16_C( 23160),  INT16_C( 12264),  INT16_C( 21001), -INT16_C( 20162),  INT16_C( 27918),
       INT16_C( 17081), -INT16_C( 30813), -INT16_C( 14925),  INT16_C( 27979), -INT16_C(  9873), -INT16_C(  2953),  INT16_C( 27622),  INT16_C(  8646),
      -INT16_C( 27921),  INT16_C( 15487), -INT16_C(  1819), -INT16_C( 12649), -INT16_C( 24537),  INT16_C( 25888),  INT16_C( 11857),  INT16_C(  3027),
       INT16_C( 30321),  INT16_C(  9362), -INT16_C(  8645), -INT16_C( 21870),  INT16_C(  2487), -INT16_C( 24929),  INT16_C( 25973),  INT16_C( 25791),
       INT16_C( 16375), -INT16_C(  9055),  INT16_C( 14391),  INT16_C( 24234), -INT16_C( 13608),  INT16_C( 10947), -INT16_C( 26887),  INT16_C( 27189),
      -INT16_C( 14580),  INT16_C( 18318),  INT16_C(  8357),  INT16_C( 24050), -INT16_C( 28374), -INT16_C( 24581), -INT16_C( 17674), -INT16_C(  4861),
      -INT16_C( 23303),  INT16_C( 12489),  INT16_C( 29916), -INT16_C( 19058),  INT16_C( 21054),  INT16_C( 14303),  INT16_C(  5352), -INT16_C(  2655),
       INT16_C( 12507), -INT16_C( 32452),  INT16_C( 11856),  INT16_C( 31454), -INT16_C(  9793), -INT16_C( 19175),  INT16_C(  7571), -INT16_C( 29278),
       INT16_C( 27841), -INT16_C( 24899),  INT16_C( 19680),  INT16_C(  7763),  INT16_C( 12958), -INT16_C( 31146), -INT16_C(  2234),  INT16_C(  8571),
      -INT16_C( 18393),  INT16_C( 30882), -INT16_C( 32538), -INT16_C( 22798),  INT16_C(  3161), -INT16_C(  4773), -INT16_C(   471), -INT16_C(  5510),
       INT16_C( 14186),  INT16_C( 19080), -INT16_C(  9341),  INT16_C(  8552), -INT16_C( 16883),  INT16_C( 21416),  INT16_C(  9142), -INT16_C(  8843),
       INT16_C(  6107), -INT16_C( 15787),  INT16_C( 18584), -INT16_C(  3736), -INT16_C( 15532),  INT16_C( 32222),  INT16_C( 22721),  INT16_C( 11111),
      -INT16_C(  3952),  INT16_C(  4981), -INT16_C(  8501), -INT16_C(  9931), -INT16_C(  8804),  INT16_C( 21036), -INT16_C( 24320), -INT16_C(  9168),
      -INT16_C( 31303),  INT16_C( 20894),  INT16_C(  1741),  INT16_C(  8514),  INT16_C(  8649), -INT16_C( 29794),  INT16_C(  1657),  INT16_C(  2486),
       INT16_C( 11510), -INT16_C( 16099),  INT16_C( 21002), -INT16_C( 22886), -INT16_C( 14545),  INT16_C( 12281),  INT16_C( 10600),  INT16_C(  8459),
      -INT16_C( 22098),  INT16_C( 31858), -INT16_C( 19025),  INT16_C( 31133),  INT16_C( 15574),  INT16_C( 20228), -INT16_C( 17854),  INT16_C( 14425),
       INT16_C( 30438), -INT16_C(  3847), -INT16_C( 27448), -INT16_C(  2153), -INT16_C( 28581), -INT16_C( 15578),  INT16_C( 12985),  INT16_C( 26597),
       INT16_C( 22491), -INT16_C( 29725), -INT16_C( 32500), -INT16_C(  7676),  INT16_C(  2237), -INT16_C(   206), -INT16_C( 29758), -INT16_C( 22217),
       INT16_C( 12289), -INT16_C( 13927),  INT16_C( 12484),  INT16_C(  8128), -INT16_C(  6464),  INT16_C( 31203), -INT16_C( 14312), -INT16_C(  2847),
      -INT16_C( 15329),  INT16_C( 11391), -INT16_C( 31931),  INT16_C(   526),  INT16_C( 16523),  INT16_C( 19713),  INT16_C( 14539), -INT16_C( 13066),
      -INT16_C( 28567),  INT16_C( 11669),  INT16_C( 21952), -INT16_C( 32435),  INT16_C( 12348),  INT16_C( 21754), -INT16_C(  9224),  INT16_C(  5960),
      -INT16_C( 14432), -INT16_C(  6845),  INT16_C( 21066), -INT16_C( 10776) };
  static const int16_t b[] =
    {  INT16_C(  2086), -INT16_C( 13873), -INT16_C( 23959),  INT16_C(  2461),  INT16_C(  1967), -INT16_C( 17131),  INT16_C( 31057), -INT16_C( 31288),
      -INT16_C( 27762), -INT16_C( 30599),  INT16_C( 10524), -INT16_C( 18520), -INT16_C( 11759), -INT16_C( 19389),  INT16_C(  4462), -INT16_C( 27292),
       INT16_C( 13081), -INT16_C( 32162), -INT16_C(   810), -INT16_C( 31348), -INT16_C( 24317),  INT16_C( 21570),  INT16_C(  2587), -INT16_C( 22055),
       INT16_C( 21149), -INT16_C( 18127), -INT16_C(  9860), -INT16_C( 29328), -INT16_C( 19284),  INT16_C(  6721), -INT16_C( 22843), -INT16_C(  8529),
       INT16_C(  3801), -INT16_C( 20639), -INT16_C(  4854),  INT16_C(  3380),  INT16_C( 30350), -INT16_C( 22175),  INT16_C( 14976),  INT16_C(  7506),
      -INT16_C( 31604),  INT16_C(  2263),  INT16_C( 18269),  INT16_C(  2453), -INT16_C( 10245), -INT16_C( 16348), -INT16_C( 11395),  INT16_C( 22175),
       INT16_C(   225), -INT16_C(  5370),  INT16_C( 15085),  INT16_C( 31736),  INT16_C( 22961),  INT16_C( 12581),  INT16_C( 30611),  INT16_C(  8271),
       INT16_C(  9979),  INT16_C( 22824), -INT16_C( 16787),  INT16_C( 26978), -INT16_C( 31083),  INT16_C(  4649), -INT16_C( 14246),  INT16_C( 15208),
       INT16_C( 28360), -INT16_C( 19161),  INT16_C(  8105),  INT16_C( 23089),  INT16_C( 22137),  INT16_C(  3211), -INT16_C(  9523), -INT16_C( 14036),
       INT16_C( 21760),  INT16_C( 28194), -INT16_C( 31725), -INT16_C( 22313),  INT16_C(    11),  INT16_C( 26042),  INT16_C(  8905), -INT16_C( 28256),
      -INT16_C( 14447),  INT16_C( 14919),  INT16_C( 30951),  INT16_C( 24724),  INT16_C(  8142), -INT16_C( 25748), -INT16_C( 26118), -INT16_C(  1436),
      -INT16_C( 30994),  INT16_C(   360),  INT16_C( 16139),  INT16_C(  5801),  INT16_C( 25408),  INT16_C(  2427),  INT16_C(  7045),  INT16_C(  5786),
      -INT16_C(  7709), -INT16_C( 13744), -INT16_C(  7079),  INT16_C( 10026), -INT16_C( 27132), -INT16_C(   317),  INT16_C( 10031),  INT16_C(  7672),
       INT16_C( 25006), -INT16_C( 18146), -INT16_C( 14432), -INT16_C(  7985),  INT16_C( 18986), -INT16_C( 20247), -INT16_C( 31643),  INT16_C( 18630),
       INT16_C(  5989), -INT16_C( 16622),  INT16_C( 15611), -INT16_C(    26), -INT16_C( 22061),  INT16_C(   765), -INT16_C(  2351),  INT16_C( 32544),
       INT16_C( 15959), -INT16_C(  2248),  INT16_C(  1798),  INT16_C( 12504), -INT16_C( 16047), -INT16_C( 18720), -INT16_C( 22715), -INT16_C( 21505),
       INT16_C(  4542), -INT16_C( 18070),  INT16_C( 20558),  INT16_C(  8633), -INT16_C( 18694), -INT16_C( 13533),  INT16_C( 17324),  INT16_C(   842),
      -INT16_C( 32126), -INT16_C( 30469), -INT16_C( 11383), -INT16_C(  9544), -INT16_C( 26220), -INT16_C(  9584), -INT16_C( 28864), -INT16_C(   379),
      -INT16_C(  4191), -INT16_C(  4169),  INT16_C( 28735),  INT16_C( 14608),  INT16_C( 13095), -INT16_C( 11516),  INT16_C( 20087), -INT16_C(  1577),
      -INT16_C( 11568),  INT16_C( 22913),  INT16_C( 14757),  INT16_C( 14643), -INT16_C( 15150),  INT16_C(  4627), -INT16_C( 26541), -INT16_C(  3056),
      -INT16_C( 14201), -INT16_C( 14365), -INT16_C(  3272),  INT16_C( 24320),  INT16_C(  1319), -INT16_C( 25037),  INT16_C(  2643),  INT16_C(  9367),
       INT16_C(  6364), -INT16_C( 32387), -INT16_C( 20143),  INT16_C(  9402), -INT16_C( 12683), -INT16_C( 14282),  INT16_C( 18278), -INT16_C(  4419),
      -INT16_C( 24561),  INT16_C( 18357), -INT16_C( 19052), -INT16_C( 17497), -INT16_C(  9542),  INT16_C(  3673), -INT16_C(  3868), -INT16_C( 16334),
      -INT16_C( 20728),  INT16_C( 22849), -INT16_C(  1184), -INT16_C( 10883), -INT16_C( 19255),  INT16_C( 12446),  INT16_C( 23547),  INT16_C(  2590),
      -INT16_C( 11269), -INT16_C( 28847), -INT16_C(  1912),  INT16_C( 17226), -INT16_C( 23598), -INT16_C( 18863), -INT16_C( 31853), -INT16_C( 25738),
      -INT16_C( 18638), -INT16_C( 27659),  INT16_C( 29363),  INT16_C( 31848),  INT16_C(  1574),  INT16_C(  8620), -INT16_C( 13727),  INT16_C( 23851),
       INT16_C( 32157),  INT16_C(  9964),  INT16_C( 14197),  INT16_C( 18537), -INT16_C( 17702),  INT16_C( 28414),  INT16_C( 30013),  INT16_C( 28425),
      -INT16_C(   468), -INT16_C(  8446),  INT16_C( 27505), -INT16_C( 26788),  INT16_C(  2161), -INT16_C( 11335), -INT16_C(  6957),  INT16_C( 28720),
       INT16_C(  7265), -INT16_C( 10346), -INT16_C(   173),  INT16_C( 11807),  INT16_C(  7609), -INT16_C(  2404), -INT16_C( 23150), -INT16_C( 16538),
       INT16_C( 26788),  INT16_C(  5534), -INT16_C(  1325),  INT16_C( 17836),  INT16_C( 25859), -INT16_C( 10728),  INT16_C( 18506), -INT16_C( 21690),
      -INT16_C(  8860), -INT16_C( 18302), -INT16_C( 24100), -INT16_C( 26906), -INT16_C( 32065),  INT16_C( 20876), -INT16_C(  3545), -INT16_C( 13552),
      -INT16_C( 20645),  INT16_C( 12000), -INT16_C( 29271), -INT16_C( 21389), -INT16_C( 29710),  INT16_C( 15490), -INT16_C( 13869),  INT16_C( 14568),
       INT16_C( 27302), -INT16_C( 32016), -INT16_C( 10740), -INT16_C( 13544), -INT16_C( 23208),  INT16_C( 32540),  INT16_C( 11671), -INT16_C(  3509),
       INT16_C( 11228), -INT16_C( 31455), -INT16_C( 27464), -INT16_C( 21710), -INT16_C( 19424), -INT16_C(  3097), -INT16_C( 12419),  INT16_C(  9003),
       INT16_C(  6970),  INT16_C( 18086), -INT16_C( 16655),  INT16_C( 18705),  INT16_C( 11619), -INT16_C(  1079),  INT16_C(  5210),  INT16_C( 14061),
       INT16_C(  3647), -INT16_C(  1860), -INT16_C(  4445), -INT16_C( 15453), -INT16_C( 30046),  INT16_C(  8374), -INT16_C(  7590), -INT16_C( 27581),
      -INT16_C(  5635), -INT16_C(  4134), -INT16_C(  5208),  INT16_C(  2872),  INT16_C(   280),  INT16_C( 29446), -INT16_C(  3051),  INT16_C( 21929),
       INT16_C( 25858), -INT16_C( 23219), -INT16_C(  4013), -INT16_C(  2456),  INT16_C(  8058), -INT16_C( 11242),  INT16_C( 22785), -INT16_C(   408),
       INT16_C( 16963), -INT16_C(  5139),  INT16_C(  9773),  INT16_C( 18166), -INT16_C(   729),  INT16_C( 15801),  INT16_C( 25329), -INT16_C(  3182),
      -INT16_C(  8248),  INT16_C(  7065),  INT16_C(   463),  INT16_C( 18705),  INT16_C( 10016),  INT16_C(  8478), -INT16_C( 31103), -INT16_C( 15328),
       INT16_C(  3529), -INT16_C(  2385), -INT16_C( 23245),  INT16_C( 23356), -INT16_C(  2654), -INT16_C( 27752),  INT16_C( 10840),  INT16_C(  8327),
       INT16_C(  8201), -INT16_C( 10181),  INT16_C( 19745),  INT16_C( 16929),  INT16_C( 16244), -INT16_C(  2717), -INT16_C( 31802), -INT16_C( 28743),
       INT16_C( 26769), -INT16_C( 15227), -INT16_C( 15858), -INT16_C( 20449), -INT16_C( 18505),  INT16_C(  3908), -INT16_C( 13343), -INT16_C(  5585),
       INT16_C( 27627),  INT16_C(  3266), -INT16_C(  6984),  INT16_C( 11342), -INT16_C( 19933), -INT16_C(  5854), -INT16_C(  9419), -INT16_C( 14728),
      -INT16_C(   444),  INT16_C( 21131), -INT16_C( 21824),  INT16_C( 30466),  INT16_C( 18018),  INT16_C( 17287), -INT16_C( 18927), -INT16_C(   978),
      -INT16_C(  4063), -INT16_C(  9975),  INT16_C( 22484), -INT16_C(  2042),  INT16_C( 10249),  INT16_C( 16353),  INT16_C( 23043),  INT16_C( 18181),
      -INT16_C( 28584),  INT16_C(  6297), -INT16_C( 25541), -INT16_C( 25201),  INT16_C(  5858), -INT16_C(  2848),  INT16_C(  3789), -INT16_C(  4368),
      -INT16_C(  1537), -INT16_C( 11320), -INT16_C( 12719),  INT16_C( 23243), -INT16_C( 21002), -INT16_C(  1639), -INT16_C( 24825),  INT16_C( 24385),
      -INT16_C(  9681),  INT16_C( 27255),  INT16_C(  1654),  INT16_C( 22791), -INT16_C(  6115), -INT16_C(  5555),  INT16_C( 15862), -INT16_C(  2600),
      -INT16_C( 24521), -INT16_C( 30519), -INT16_C( 27538),  INT16_C( 25826) };
  static const int16_t e[] =
    {  INT16_C(  2084), -INT16_C( 30451),  INT16_C(  8777),  INT16_C( 26254), -INT16_C( 15667),  INT16_C( 15755),  INT16_C( 12450),  INT16_C(   136),
      -INT16_C(  2468),  INT16_C( 31196), -INT16_C(  7477),  INT16_C( 21434),  INT16_C( 20480),  INT16_C(  3964),  INT16_C(  4192), -INT16_C( 10733),
       INT16_C( 16459),  INT16_C(    66), -INT16_C(  4030),  INT16_C(     8),  INT16_C(  1459),  INT16_C( 21877),  INT16_C(  2065), -INT16_C( 32639),
      -INT16_C( 31997), -INT16_C( 30463), -INT16_C( 16028),  INT16_C(  2336), -INT16_C( 25055),  INT16_C(  4697),  INT16_C(  9280), -INT16_C( 15191),
       INT16_C(  2696),  INT16_C(  1857),  INT16_C( 21307),  INT16_C(  3076),  INT16_C( 17416), -INT16_C( 30656), -INT16_C(  5167), -INT16_C( 10976),
       INT16_C( 11119),  INT16_C(   132), -INT16_C( 14608),  INT16_C(  4382),  INT16_C( 30565), -INT16_C( 16348),  INT16_C(   353),  INT16_C(  1669),
       INT16_C(    64), -INT16_C( 31994), -INT16_C(  2350),  INT16_C( 11136), -INT16_C( 14661),  INT16_C(    33),  INT16_C( 21137),  INT16_C(  8289),
       INT16_C(  1285),  INT16_C( 20512),  INT16_C(  4684),  INT16_C( 12551),  INT16_C( 11146),  INT16_C(     0), -INT16_C( 32744), -INT16_C( 28420),
      -INT16_C( 23756),  INT16_C(  1060),  INT16_C(  1672),  INT16_C( 20529),  INT16_C( 17000),  INT16_C(  7649),  INT16_C( 17092), -INT16_C( 13762),
       INT16_C(  4352),  INT16_C(  1024), -INT16_C( 14522), -INT16_C( 12219),  INT16_C( 22259),  INT16_C( 11069),  INT16_C( 14603),  INT16_C( 16316),
      -INT16_C( 16239),  INT16_C( 30533),  INT16_C( 30342),  INT16_C( 24708), -INT16_C( 21151),  INT16_C(   268),  INT16_C(  2544),  INT16_C( 14436),
      -INT16_C( 20608),  INT16_C(    72),  INT16_C(  4867),  INT16_C(   640),  INT16_C( 17216),  INT16_C(    17),  INT16_C(  4357),  INT16_C(   528),
       INT16_C( 31025), -INT16_C( 18591),  INT16_C( 11760),  INT16_C( 20905), -INT16_C( 28672), -INT16_C( 13450),  INT16_C(  9734),  INT16_C(  1280),
       INT16_C( 16644), -INT16_C( 30708), -INT16_C(  6940), -INT16_C( 12810), -INT16_C( 29513), -INT16_C( 32576), -INT16_C(  2339),  INT16_C(  4014),
       INT16_C(  3951),  INT16_C(  7938),  INT16_C( 28732),  INT16_C(  6064),  INT16_C( 10025),  INT16_C( 12258), -INT16_C(  6515), -INT16_C( 23882),
       INT16_C(  1047),  INT16_C(  7215),  INT16_C(  9704), -INT16_C( 24599), -INT16_C( 32495), -INT16_C( 31136),  INT16_C(  4769),  INT16_C(   414),
       INT16_C(    34),  INT16_C(  6240),  INT16_C(  8660),  INT16_C(  8497),  INT16_C(  5704), -INT16_C( 16095), -INT16_C(  7363),  INT16_C( 30071),
      -INT16_C( 32126), -INT16_C( 30575),  INT16_C( 31436),  INT16_C( 22568), -INT16_C( 28412), -INT16_C( 15872), -INT16_C( 21787),  INT16_C(  2008),
       INT16_C( 18689), -INT16_C(  7322),  INT16_C( 20522), -INT16_C( 19743),  INT16_C(  3635),  INT16_C( 28807),  INT16_C( 20081), -INT16_C(  9787),
       INT16_C( 21120),  INT16_C( 29096),  INT16_C(  4513),  INT16_C(  4386), -INT16_C(  1046),  INT16_C(  4114), -INT16_C( 28671), -INT16_C( 19241),
       INT16_C(  2048),  INT16_C( 27288),  INT16_C( 28952),  INT16_C( 19484),  INT16_C(   263),  INT16_C(  6192), -INT16_C( 23903),  INT16_C(  1041),
      -INT16_C(  1512),  INT16_C(  2487), -INT16_C( 24559), -INT16_C(   992), -INT16_C( 12767),  INT16_C( 18124), -INT16_C( 23626), -INT16_C( 22855),
      -INT16_C( 32767),  INT16_C( 16928),  INT16_C( 15372), -INT16_C( 27898),  INT16_C(   735),  INT16_C(     9),  INT16_C( 23972), -INT16_C( 16953),
       INT16_C( 32343),  INT16_C( 18496), -INT16_C(  6364), -INT16_C( 15004),  INT16_C( 12480),  INT16_C(  4108),  INT16_C(  2004), -INT16_C( 19118),
       INT16_C( 29338), -INT16_C( 22865), -INT16_C(  3960), -INT16_C( 29383),  INT16_C(   210), -INT16_C( 27647), -INT16_C( 11103), -INT16_C(  1959),
       INT16_C(  5906),  INT16_C(  4961),  INT16_C( 16386),  INT16_C( 27688),  INT16_C(    38),  INT16_C(   136), -INT16_C( 13760),  INT16_C( 18475),
       INT16_C( 11852), -INT16_C(  1392), -INT16_C( 14045),  INT16_C(  6791), -INT16_C( 27379), -INT16_C( 20554),  INT16_C(  3945), -INT16_C( 17241),
       INT16_C(  2095),  INT16_C(  5376),  INT16_C( 24896), -INT16_C( 15326),  INT16_C(  2096),  INT16_C(  2702),  INT16_C(  3461),  INT16_C( 20528),
       INT16_C(  1057),  INT16_C( 24268),  INT16_C( 21325),  INT16_C( 23160),  INT16_C(  3496),  INT16_C( 21000), -INT16_C( 24302),  INT16_C( 27918),
       INT16_C( 16544), -INT16_C( 30813), -INT16_C( 14925),  INT16_C( 17672), -INT16_C(  9873), -INT16_C( 11248),  INT16_C( 18498),  INT16_C(  8646),
      -INT16_C( 27921),  INT16_C( 14338), -INT16_C(  1819), -INT16_C( 31098), -INT16_C( 32729),  INT16_C( 16640),  INT16_C(  8705),  INT16_C(  3027),
       INT16_C( 30321),  INT16_C(  9344), -INT16_C( 29655), -INT16_C( 22510),  INT16_C(  2487),  INT16_C(  7298),  INT16_C( 25973),  INT16_C(  8360),
       INT16_C( 16375), -INT16_C( 32608),  INT16_C(  4100),  INT16_C( 24234), -INT16_C( 32680),  INT16_C( 10752), -INT16_C( 26887),  INT16_C( 25089),
      -INT16_C( 14580),  INT16_C( 18318),  INT16_C(   160),  INT16_C(  2354), -INT16_C( 28640), -INT16_C( 24581), -INT16_C( 17674), -INT16_C(  4861),
       INT16_C(    56),  INT16_C( 12489),  INT16_C( 13520),  INT16_C(   256),  INT16_C( 21054),  INT16_C( 13257),  INT16_C(  5192), -INT16_C(  2655),
       INT16_C(    27), -INT16_C( 32708),  INT16_C( 11776),  INT16_C( 17026), -INT16_C( 30558), -INT16_C( 19175),  INT16_C(  7571), -INT16_C( 31742),
       INT16_C( 26817), -INT16_C( 24899),  INT16_C( 18592),  INT16_C(  2576),  INT16_C(    24), -INT16_C( 31146), -INT16_C(  3068),  INT16_C(  8571),
      -INT16_C( 18393),  INT16_C( 30882), -INT16_C( 32538), -INT16_C( 22798),  INT16_C(  3160), -INT16_C(  4773), -INT16_C(   471), -INT16_C(  5510),
       INT16_C( 14186),  INT16_C( 19080), -INT16_C(  9341),  INT16_C(    96), -INT16_C( 17403),  INT16_C( 21416),  INT16_C(  9142), -INT16_C( 12016),
       INT16_C(  6107), -INT16_C( 15787),  INT16_C( 18584), -INT16_C(  3736), -INT16_C( 15532),  INT16_C( 32222),  INT16_C(   129),  INT16_C(    32),
       INT16_C(   128),  INT16_C(  4981), -INT16_C(  8501),  INT16_C( 22836), -INT16_C( 10880),  INT16_C( 21036),  INT16_C(  8192),  INT16_C(     0),
       INT16_C(     9),  INT16_C( 20506),  INT16_C(  1025),  INT16_C(     0),  INT16_C(  8512), -INT16_C( 29794),  INT16_C(   576),  INT16_C(  2480),
       INT16_C( 10384), -INT16_C( 16099),  INT16_C( 16906), -INT16_C( 24550), -INT16_C( 30937),  INT16_C(  3904),  INT16_C( 10600),  INT16_C(  8203),
      -INT16_C( 22098),  INT16_C( 31858), -INT16_C( 23384),  INT16_C( 10252),  INT16_C( 12290),  INT16_C( 18688), -INT16_C( 26112),  INT16_C( 14425),
       INT16_C( 30438),  INT16_C( 20617), -INT16_C( 27448),  INT16_C( 30466), -INT16_C( 28581),  INT16_C( 17158),  INT16_C( 12985),  INT16_C( 25636),
       INT16_C( 22491), -INT16_C( 29725),  INT16_C(   260), -INT16_C(  8188),  INT16_C(  2057),  INT16_C( 16160), -INT16_C( 29758), -INT16_C( 22217),
       INT16_C( 12289), -INT16_C( 13927),  INT16_C(  4096),  INT16_C(  7552), -INT16_C(  6464),  INT16_C( 31203),  INT16_C(  2056), -INT16_C(  2847),
      -INT16_C( 16353),  INT16_C(    72), -INT16_C( 31931),  INT16_C(   522),  INT16_C(   130),  INT16_C( 19713),  INT16_C( 14539),  INT16_C( 19520),
      -INT16_C( 28631),  INT16_C( 10261),  INT16_C( 21952),  INT16_C(   261),  INT16_C(  8220),  INT16_C( 16456), -INT16_C(  9224),  INT16_C(  5960),
      -INT16_C( 14432), -INT16_C( 32703),  INT16_C( 21066),  INT16_C( 17632) };

  static int16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t
      rv,
      av = simde_svld1_s16(pg, &(a[i])),
      bv = simde_svld1_s16(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(INT16_C(0)));
    rv = simde_svand_s16_m(pv, av, bv);

    simde_svst1_s16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vi16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(int16_t)], a[1024 / sizeof(int16_t)], b[1024 / sizeof(int16_t)], e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_s16(pg, &(a[i]));
    bv = simde_svld1_s16(pg, &(b[i]));

    ev = simde_svand_s16_m(pv, av, bv);

    simde_svst1_s16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_s32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) };
  static const int32_t a[] =
    { -INT32_C(   583110466), -INT32_C(   665809308),  INT32_C(  1652463429),  INT32_C(  1860658741), -INT32_C(  1137767689), -INT32_C(     3210331), -INT32_C(  1770792667),  INT32_C(  1917274804),
       INT32_C(   508593850),  INT32_C(  1509400596),  INT32_C(  1841001784), -INT32_C(   740514852),  INT32_C(  1385106349),  INT32_C(   860970766), -INT32_C(   322321096), -INT32_C(   916516593),
      -INT32_C(  1410814057), -INT32_C(  2029723825),  INT32_C(   821411924),  INT32_C(   268751203), -INT32_C(   345795620),  INT32_C(   723432690), -INT32_C(  2011699079), -INT32_C(  1873643783),
       INT32_C(  1966815781),  INT32_C(  1845247769),  INT32_C(  1654583807), -INT32_C(  1619811646),  INT32_C(   680187445),  INT32_C(    72591498), -INT32_C(  1987286384),  INT32_C(   102358753),
       INT32_C(   830166040), -INT32_C(  1818265452),  INT32_C(   754335081),  INT32_C(   348875231), -INT32_C(   918792897), -INT32_C(  1899130883), -INT32_C(   619226374),  INT32_C(  1373712696),
       INT32_C(   427974021),  INT32_C(  1051533781),  INT32_C(  1030398814),  INT32_C(  1263678732), -INT32_C(  2011918710),  INT32_C(   404152862),  INT32_C(  1962093884), -INT32_C(   456797090),
       INT32_C(   117262385), -INT32_C(   934958487),  INT32_C(  1493544781),  INT32_C(  1873041381),  INT32_C(    83343846), -INT32_C(   686027365), -INT32_C(  1723134149),  INT32_C(   360518115),
      -INT32_C(  1038386343),  INT32_C(  1938448421), -INT32_C(   171143152), -INT32_C(   849055257), -INT32_C(   976135126), -INT32_C(  1533219479), -INT32_C(   532748292),  INT32_C(  1375058936),
       INT32_C(  1544818742), -INT32_C(  2117099919),  INT32_C(   376871726),  INT32_C(   920902156), -INT32_C(  1594116810), -INT32_C(  1622894686),  INT32_C(  2004845183),  INT32_C(  1959359550),
      -INT32_C(   170861180), -INT32_C(  1435066501),  INT32_C(  1203825723), -INT32_C(    42032185), -INT32_C(    73565864), -INT32_C(  1868897775), -INT32_C(  1576593052),  INT32_C(   286773389),
       INT32_C(   688383917), -INT32_C(  1026327161),  INT32_C(   822711146), -INT32_C(  1892776138),  INT32_C(   311086081),  INT32_C(   312616110), -INT32_C(   894064323),  INT32_C(   668716154),
       INT32_C(   978379443), -INT32_C(   889445536), -INT32_C(   302315850), -INT32_C(  1904465523), -INT32_C(  1549793547),  INT32_C(  1739997738),  INT32_C(  1714514924), -INT32_C(   359855049),
       INT32_C(  1327881967), -INT32_C(  1206312703), -INT32_C(  1247472601),  INT32_C(   860037437),  INT32_C(  1373037607),  INT32_C(   314084390),  INT32_C(   779676151), -INT32_C(   468121867),
      -INT32_C(   449626396), -INT32_C(  2019734433), -INT32_C(  1640218016), -INT32_C(  1965981853), -INT32_C(  1965316253),  INT32_C(   731681588),  INT32_C(  1918506364), -INT32_C(    11111653),
       INT32_C(   283413169),  INT32_C(   932676310),  INT32_C(   685102020), -INT32_C(  1229805997), -INT32_C(  2126475699), -INT32_C(  1632772831),  INT32_C(   219154418),  INT32_C(   722232954),
      -INT32_C(   952373008),  INT32_C(   939447154), -INT32_C(   111160410), -INT32_C(   961539719), -INT32_C(  1052184417), -INT32_C(  1084230195),  INT32_C(  1993109500), -INT32_C(   962471723),
       INT32_C(   999152841),  INT32_C(  1450347439), -INT32_C(   682634914), -INT32_C(  2103574557), -INT32_C(  1119623696), -INT32_C(   696409382), -INT32_C(   414430959), -INT32_C(   340923102),
       INT32_C(  2032548554),  INT32_C(   600807877),  INT32_C(  1308237674),  INT32_C(   248551198),  INT32_C(  1472992125), -INT32_C(   953267786), -INT32_C(  1263633774),  INT32_C(   849304424),
       INT32_C(  1521206933), -INT32_C(   914523297), -INT32_C(  1206421606), -INT32_C(  1933056241), -INT32_C(  1327262726),  INT32_C(  1853362652), -INT32_C(   199022964),  INT32_C(   388416130),
      -INT32_C(   411905656), -INT32_C(   424546484),  INT32_C(  1990183015), -INT32_C(  1459460433), -INT32_C(   715463175), -INT32_C(  2092707081),  INT32_C(  2054645496), -INT32_C(  1315791575),
      -INT32_C(  1147599762),  INT32_C(  1520519923), -INT32_C(  1043316718), -INT32_C(  1620389210), -INT32_C(  1351301960), -INT32_C(  1892501354),  INT32_C(  1191815454), -INT32_C(  1258710202),
      -INT32_C(  1821404513), -INT32_C(   286453284), -INT32_C(   122700207),  INT32_C(  1217862032),  INT32_C(  1962347742), -INT32_C(   503109180),  INT32_C(   405409234) };
  static const int32_t b[] =
    {  INT32_C(  1692387797),  INT32_C(   773953457), -INT32_C(   437454366), -INT32_C(   758012738), -INT32_C(  1267088709),  INT32_C(    70285288), -INT32_C(  1667705572), -INT32_C(  2018037582),
      -INT32_C(  1410558215),  INT32_C(   265882925), -INT32_C(   973748730),  INT32_C(   630703722),  INT32_C(  1910050953), -INT32_C(  1535833465), -INT32_C(  1858073121),  INT32_C(   924383293),
      -INT32_C(  1126038386),  INT32_C(   416004882), -INT32_C(   337788799),  INT32_C(   269513863),  INT32_C(   209840773), -INT32_C(   743377164),  INT32_C(  1097134339),  INT32_C(  2004385001),
      -INT32_C(  1825351039), -INT32_C(  1750335723),  INT32_C(  1182960063), -INT32_C(  2108255235),  INT32_C(  1905252221), -INT32_C(   784056371),  INT32_C(   420653104), -INT32_C(  1517188572),
      -INT32_C(   113720092), -INT32_C(  2087656253),  INT32_C(  1791562605),  INT32_C(   602742950), -INT32_C(   980124425), -INT32_C(   325658437), -INT32_C(  1543133056),  INT32_C(   373986866),
       INT32_C(   504332891), -INT32_C(   744382362),  INT32_C(  1497263027), -INT32_C(  2105791605),  INT32_C(  1648824487),  INT32_C(  1749999080), -INT32_C(  1223928699),  INT32_C(  1171085034),
       INT32_C(  1063575001),  INT32_C(   806552957), -INT32_C(    74886800),  INT32_C(   595461500), -INT32_C(    41564907),  INT32_C(   677762211),  INT32_C(   316698920), -INT32_C(  1588023864),
       INT32_C(   132168842),  INT32_C(   842527681), -INT32_C(  1070743484), -INT32_C(   622613563),  INT32_C(   349661553),  INT32_C(  1698446397),  INT32_C(  1987517614),  INT32_C(  1410846666),
       INT32_C(  1297938315),  INT32_C(   796890091),  INT32_C(   435203156), -INT32_C(   906701992),  INT32_C(  2044578620), -INT32_C(  1226958584),  INT32_C(     2905654), -INT32_C(  1319877851),
       INT32_C(   637448250), -INT32_C(  1739227836), -INT32_C(  2119088855),  INT32_C(  1430955288),  INT32_C(  2043553649),  INT32_C(  1999613249),  INT32_C(   678910723), -INT32_C(   656815202),
      -INT32_C(  1057040516),  INT32_C(  2119717716), -INT32_C(  1325463144),  INT32_C(   537217711), -INT32_C(  1298541455), -INT32_C(  2077636479), -INT32_C(  1045651421), -INT32_C(   392591764),
      -INT32_C(  1297574051), -INT32_C(  2110783254), -INT32_C(  1204605175), -INT32_C(   338151303), -INT32_C(  1919061748),  INT32_C(  1544668985), -INT32_C(   753025433), -INT32_C(  1581533372),
       INT32_C(   961766222),  INT32_C(  1841005411),  INT32_C(   740683443),  INT32_C(   857210407), -INT32_C(  1446922897), -INT32_C(   486157700), -INT32_C(   726195312),  INT32_C(   678851290),
       INT32_C(   962709974),  INT32_C(    10886477),  INT32_C(   841796619),  INT32_C(   963003594),  INT32_C(  1977755641), -INT32_C(  1973884679), -INT32_C(   446820597),  INT32_C(  1477301378),
      -INT32_C(   342790242), -INT32_C(  1746192244), -INT32_C(   825616636),  INT32_C(  1409757275),  INT32_C(  1355410007), -INT32_C(   572906798), -INT32_C(  1279117007), -INT32_C(  1425289459),
      -INT32_C(   896099010), -INT32_C(   647855659), -INT32_C(   190370663), -INT32_C(  1287016868),  INT32_C(  1778586264),  INT32_C(  1715985972),  INT32_C(   605620503),  INT32_C(   399517145),
      -INT32_C(  1746770238), -INT32_C(  2123348760), -INT32_C(   864741520),  INT32_C(  1585430213),  INT32_C(    97026769),  INT32_C(  2003505248), -INT32_C(   224623335),  INT32_C(  1812622506),
      -INT32_C(  1174147886), -INT32_C(  1606716624),  INT32_C(  1332523402),  INT32_C(  1085139823), -INT32_C(   834242963), -INT32_C(  1622822522), -INT32_C(   527245002),  INT32_C(   541891661),
      -INT32_C(  1193652344),  INT32_C(  1280841410),  INT32_C(   916243655),  INT32_C(   477579695),  INT32_C(  1173011903), -INT32_C(  1511706514),  INT32_C(  1602582289), -INT32_C(  1686121965),
      -INT32_C(   464299743),  INT32_C(   909159279),  INT32_C(   510512239), -INT32_C(   717560810),  INT32_C(   253437345),  INT32_C(  1723072597), -INT32_C(  1966785929),  INT32_C(   757416972),
       INT32_C(   219248798), -INT32_C(  1841020381),  INT32_C(   615559438),  INT32_C(   922413717),  INT32_C(  1682248975), -INT32_C(  1932789227),  INT32_C(  1075220532),  INT32_C(  1936538581),
      -INT32_C(   696221773), -INT32_C(   815217471),  INT32_C(   183769205),  INT32_C(   306245122),  INT32_C(   410420739), -INT32_C(  1264303744), -INT32_C(  1477133614) };
  static const int32_t e[] =
    {  INT32_C(  1142833300),  INT32_C(           0),  INT32_C(  1617727808),  INT32_C(           0), -INT32_C(  1272380749),  INT32_C(           0), -INT32_C(  1810837244),  INT32_C(           0),
       INT32_C(   172000952),  INT32_C(   164691972),  INT32_C(  1169245184),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2143288040),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(   550879232),  INT32_C(   268455939),  INT32_C(   134316676),  INT32_C(           0),  INT32_C(      319489),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(  1115849151), -INT32_C(  2108521792),  INT32_C(   545969717),  INT32_C(     4204680),  INT32_C(   151005200),  INT32_C(    68258336),
       INT32_C(           0), -INT32_C(  2087690112),  INT32_C(           0),  INT32_C(    13181062), -INT32_C(  1055632329),  INT32_C(           0), -INT32_C(  2147153792),  INT32_C(           0),
       INT32_C(   402784257),  INT32_C(   312549444),  INT32_C(           0),  INT32_C(    38805768),  INT32_C(      262274),  INT32_C(           0),  INT32_C(   872416260),  INT32_C(  1153782858),
       INT32_C(   107235345),  INT32_C(       65641),  INT32_C(  1493238080),  INT32_C(   589563236),  INT32_C(           0),  INT32_C(      263299),  INT32_C(   272630056),  INT32_C(    22544832),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    80824352),  INT32_C(   605826089),  INT32_C(  1614152876),  INT32_C(           0),
       INT32_C(  1276383234),  INT32_C(           0),  INT32_C(   275810308),  INT32_C(           0),  INT32_C(   551125300),  INT32_C(           0),  INT32_C(           0),  INT32_C(   809517092),
       INT32_C(   634425344),  INT32_C(           0),  INT32_C(    25183273),  INT32_C(  1430954240),  INT32_C(  2039226704),  INT32_C(           0),  INT32_C(   537336064),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(     2097280),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1601633276),
       INT32_C(   151077454),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    33587236),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   169377840),  INT32_C(           0),  INT32_C(  1476677634),
       INT32_C(     8391312),  INT32_C(   394461316),  INT32_C(           0),  INT32_C(           0),  INT32_C(     4229701),  INT32_C(           0),  INT32_C(    16777520),  INT32_C(   721962504),
      -INT32_C(  1038970832),  INT32_C(           0), -INT32_C(   267976576), -INT32_C(  2113929128),  INT32_C(  1073746072),  INT32_C(   642241540),  INT32_C(           0),  INT32_C(           0),
       INT32_C(   327173312),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    88113360),  INT32_C(  1449721920),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2029780602),  INT32_C(           0),  INT32_C(   537663560),
       INT32_C(   411715200),  INT32_C(  1213731394),  INT32_C(   806634626),  INT32_C(   205996303),  INT32_C(    14848442),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2130549754),  INT32_C(           0),  INT32_C(    33554517),  INT32_C(           0),  INT32_C(   553649160),
       INT32_C(   152109070),  INT32_C(           0),  INT32_C(     9437186),  INT32_C(   376095364),  INT32_C(   608437256),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(        2048),  INT32_C(   276169730),  INT32_C(           0),  INT32_C(     2099410) };

  static int32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t
      rv,
      av = simde_svld1_s32(pg, &(a[i])),
      bv = simde_svld1_s32(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_svand_s32_z(pv, av, bv);

    simde_svst1_s32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vi32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)], a[1024 / sizeof(int32_t)], b[1024 / sizeof(int32_t)], e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_s32(pg, &(a[i]));
    bv = simde_svld1_s32(pg, &(b[i]));

    ev = simde_svand_s32_z(pv, av, bv);

    simde_svst1_s32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_s32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) };
  static const int32_t a[] =
    { -INT32_C(  1738970873),  INT32_C(  1774500896),  INT32_C(  1272809465),  INT32_C(   964019990),  INT32_C(  1329775430),  INT32_C(   285005747), -INT32_C(   169145567),  INT32_C(    48207611),
       INT32_C(   547043328), -INT32_C(   309698572), -INT32_C(    63412250),  INT32_C(  1949675054),  INT32_C(   616855665),  INT32_C(  1882505295), -INT32_C(   966385717), -INT32_C(  1228323402),
       INT32_C(  1909875837), -INT32_C(  1436655421), -INT32_C(   156854328), -INT32_C(  1234445243), -INT32_C(  1545982124), -INT32_C(  1173090321), -INT32_C(   461342162),  INT32_C(  1016744383),
       INT32_C(  1907192237), -INT32_C(  1726280751), -INT32_C(   409943646), -INT32_C(   241304675),  INT32_C(   429226026), -INT32_C(  1244419705), -INT32_C(   493202653),  INT32_C(  1243493533),
       INT32_C(  2008796069),  INT32_C(  2031146710),  INT32_C(   895525016), -INT32_C(   987234661), -INT32_C(    35734410), -INT32_C(  2001555099), -INT32_C(  1570092027),  INT32_C(   653035649),
       INT32_C(   698198099),  INT32_C(   379760254), -INT32_C(   364117170),  INT32_C(  2007986945), -INT32_C(  1804300753),  INT32_C(  1142695487), -INT32_C(   186218893),  INT32_C(  1629147918),
      -INT32_C(   108349317), -INT32_C(  1274008218),  INT32_C(   832461872), -INT32_C(    22524209),  INT32_C(   462560476), -INT32_C(  1251955134),  INT32_C(  1118389812), -INT32_C(  1801206759),
      -INT32_C(   493998724), -INT32_C(  1969840550), -INT32_C(   910477830),  INT32_C(  1606902659), -INT32_C(  1032169089),  INT32_C(   997710343),  INT32_C(   981279009),  INT32_C(  1640964325),
      -INT32_C(  1471980211), -INT32_C(   181216773), -INT32_C(  1849758194), -INT32_C(   772766383), -INT32_C(   443323426),  INT32_C(  1713375813),  INT32_C(   279026987),  INT32_C(   175206589),
      -INT32_C(   927812403), -INT32_C(  1665276530),  INT32_C(   607026131), -INT32_C(   554361344), -INT32_C(   809269111), -INT32_C(  1103764589),  INT32_C(  1037031040),  INT32_C(   323436614),
      -INT32_C(  2082735371), -INT32_C(  1306552097),  INT32_C(   332811539), -INT32_C(   168702868), -INT32_C(   406539180),  INT32_C(   396819095),  INT32_C(   391411152), -INT32_C(  1440047947),
       INT32_C(  1965885078), -INT32_C(  1306047074),  INT32_C(   113638810),  INT32_C(   519878601),  INT32_C(    50708587), -INT32_C(  1961186374), -INT32_C(   693997792), -INT32_C(  1585394677),
       INT32_C(  1897311954), -INT32_C(  1792852485),  INT32_C(    77391930),  INT32_C(   186816671),  INT32_C(   319694680), -INT32_C(   207738669), -INT32_C(  1563869033), -INT32_C(   549238260),
      -INT32_C(   212837896), -INT32_C(   779586666), -INT32_C(    69917605),  INT32_C(   352778172), -INT32_C(   249031650), -INT32_C(   723139012),  INT32_C(   309767686), -INT32_C(   252593416),
      -INT32_C(  1427947245),  INT32_C(   276524212),  INT32_C(  1292587152),  INT32_C(  1700925767),  INT32_C(  1633126949),  INT32_C(  1446329424), -INT32_C(   479679254),  INT32_C(  2043894374),
       INT32_C(  1344518043), -INT32_C(  1285513693),  INT32_C(   889220078), -INT32_C(  1583652228),  INT32_C(  1006826220),  INT32_C(   412235822),  INT32_C(  1258028004), -INT32_C(   255602859),
      -INT32_C(  1455364218),  INT32_C(  1952227461), -INT32_C(  2018943733), -INT32_C(  1406647105),  INT32_C(  1692937014),  INT32_C(  1199405923), -INT32_C(   879658890), -INT32_C(   843361209),
      -INT32_C(  1049166789), -INT32_C(  1472867428), -INT32_C(   282075600),  INT32_C(  1503352867), -INT32_C(   423721853),  INT32_C(  1965898751), -INT32_C(    79642957),  INT32_C(  1321794322),
      -INT32_C(  1810939913),  INT32_C(  1111245842),  INT32_C(  1160866594),  INT32_C(  1184878019),  INT32_C(  1345084753),  INT32_C(  1271224728),  INT32_C(   709231895), -INT32_C(   126349568),
       INT32_C(  1619822414), -INT32_C(   308098869), -INT32_C(   147598541), -INT32_C(   247606624), -INT32_C(   952014289), -INT32_C(   619575613),  INT32_C(   201677067), -INT32_C(  1241219736),
      -INT32_C(   820604924), -INT32_C(  1950566312),  INT32_C(   746778507), -INT32_C(   266485567), -INT32_C(   306749654),  INT32_C(  1908984421), -INT32_C(  1954689757),  INT32_C(  1312915786),
       INT32_C(  1763530513), -INT32_C(  1695229425), -INT32_C(  1949927479),  INT32_C(  1635509303), -INT32_C(  1471270077),  INT32_C(   538515453),  INT32_C(   799774436),  INT32_C(   679341079),
       INT32_C(  1385274179),  INT32_C(  1055688309),  INT32_C(   885634045), -INT32_C(   627751529),  INT32_C(  1971512184), -INT32_C(   543843078),  INT32_C(  1242447922),  INT32_C(  1869777708),
      -INT32_C(  1681849306), -INT32_C(  2015711862), -INT32_C(   138697888),  INT32_C(  1624330472),  INT32_C(   785732659),  INT32_C(   571304688), -INT32_C(   697558102), -INT32_C(   851058778),
       INT32_C(  1835534051),  INT32_C(   351552180), -INT32_C(   838029338),  INT32_C(   841997823),  INT32_C(   559940657) };
  static const int32_t b[] =
    {  INT32_C(   256831322), -INT32_C(  1972811937), -INT32_C(   697430285),  INT32_C(  1129907126), -INT32_C(  1187916817),  INT32_C(   397717721), -INT32_C(   138532155),  INT32_C(  2128641828),
      -INT32_C(   846385554),  INT32_C(  1750595189), -INT32_C(  1170291196), -INT32_C(  1191339831),  INT32_C(  1165111147), -INT32_C(  1537464609),  INT32_C(  1956321872),  INT32_C(   150109082),
       INT32_C(   534151082),  INT32_C(  2038967669), -INT32_C(  1120614669), -INT32_C(   898289314),  INT32_C(  1058006880),  INT32_C(  1591962381),  INT32_C(   533888645), -INT32_C(  1540831750),
      -INT32_C(  1161560508),  INT32_C(   523455275),  INT32_C(  1893492498), -INT32_C(   113618535),  INT32_C(  1178159417),  INT32_C(   983833780), -INT32_C(  1789298789), -INT32_C(  2143715012),
      -INT32_C(  1422197633),  INT32_C(  1523215944),  INT32_C(  1858774741),  INT32_C(   812123639),  INT32_C(    58171726),  INT32_C(  1480399805), -INT32_C(   823290222), -INT32_C(  1756420584),
       INT32_C(  1799522595), -INT32_C(   842724105), -INT32_C(  1438937166), -INT32_C(   472210540),  INT32_C(    48648516), -INT32_C(    10869907), -INT32_C(   775010119), -INT32_C(  1855382162),
      -INT32_C(  1627608154),  INT32_C(  1785446840), -INT32_C(   451631535), -INT32_C(  1899434166), -INT32_C(  1383027136), -INT32_C(  1951536175), -INT32_C(  1587774669),  INT32_C(  1043580312),
       INT32_C(   702295921),  INT32_C(  1116948465),  INT32_C(   942123246), -INT32_C(   674828137),  INT32_C(  1887786910),  INT32_C(  1979396674),  INT32_C(  1159092141), -INT32_C(  1903998691),
       INT32_C(  1790402681), -INT32_C(  1783870809), -INT32_C(  1982999566),  INT32_C(  1650562243),  INT32_C(   768796395), -INT32_C(   979186408),  INT32_C(  1091221540),  INT32_C(  2077199618),
      -INT32_C(  1780119827), -INT32_C(  1020620335),  INT32_C(   676198500),  INT32_C(  2005577356), -INT32_C(  1398514540),  INT32_C(  1299269161),  INT32_C(     9403390), -INT32_C(   159687160),
      -INT32_C(  1232379675),  INT32_C(  1450817009),  INT32_C(   964609709),  INT32_C(   145754228), -INT32_C(  1917561756), -INT32_C(  1713756774), -INT32_C(  1449563744), -INT32_C(  1382083128),
       INT32_C(  1734552181), -INT32_C(  1916936993),  INT32_C(   398867363), -INT32_C(  1491044541),  INT32_C(  1714738379), -INT32_C(  1694560518),  INT32_C(  1078171768),  INT32_C(   602792621),
      -INT32_C(   326479860), -INT32_C(   814135508), -INT32_C(   974700670), -INT32_C(  2106849354), -INT32_C(   706174757),  INT32_C(   644933550),  INT32_C(   761705343), -INT32_C(  1571794026),
      -INT32_C(   795944285), -INT32_C(  1549859039), -INT32_C(    43481529),  INT32_C(  1769985165),  INT32_C(   574515060), -INT32_C(   834032050), -INT32_C(   117723294), -INT32_C(  1499837693),
       INT32_C(  1182148901),  INT32_C(  2011764272),  INT32_C(   712331676), -INT32_C(  1718356955), -INT32_C(  1430531748), -INT32_C(   495451008), -INT32_C(  1210420300), -INT32_C(   480414530),
      -INT32_C(   836119395), -INT32_C(  2042293526), -INT32_C(  2001683869),  INT32_C(   186729391), -INT32_C(  1783243499), -INT32_C(  1787351327),  INT32_C(  1615614369),  INT32_C(  1665379013),
       INT32_C(  1748069758), -INT32_C(   470911361), -INT32_C(   529817807), -INT32_C(   135557662),  INT32_C(  1267507306),  INT32_C(  1893794766),  INT32_C(   449850708),  INT32_C(  1434260439),
       INT32_C(    12430976),  INT32_C(  1440984100),  INT32_C(   758468171),  INT32_C(  1160061147), -INT32_C(  1886277183),  INT32_C(   167735989),  INT32_C(  1998835615),  INT32_C(  1674354915),
       INT32_C(  1935903310), -INT32_C(  2117581258),  INT32_C(  1890516629), -INT32_C(   541666530),  INT32_C(   980371333),  INT32_C(  1480814265),  INT32_C(   567240510),  INT32_C(  1451531271),
       INT32_C(  1556736038), -INT32_C(  1008889554), -INT32_C(  1372288113), -INT32_C(   460461473), -INT32_C(   367068111), -INT32_C(  1455267477), -INT32_C(   792063288), -INT32_C(   735686994),
       INT32_C(  1697705782),  INT32_C(   271060352), -INT32_C(   138519400),  INT32_C(  2010860358), -INT32_C(  1285424824),  INT32_C(   593273947),  INT32_C(  1693656758), -INT32_C(  1422386828),
      -INT32_C(  1995413496),  INT32_C(   228145269), -INT32_C(   620406891), -INT32_C(   363601758),  INT32_C(   899527898),  INT32_C(   240712024), -INT32_C(  1804448737),  INT32_C(  1849666149),
      -INT32_C(  2013835502),  INT32_C(   479563911), -INT32_C(  1980196121),  INT32_C(  1416907642),  INT32_C(  1485378047),  INT32_C(   711385611), -INT32_C(  1816209106), -INT32_C(  1778254461),
      -INT32_C(   736233396),  INT32_C(  1878045320), -INT32_C(   939923380),  INT32_C(   857435443), -INT32_C(  1987336834), -INT32_C(  1246432889),  INT32_C(  1313370826), -INT32_C(  1125889424),
      -INT32_C(   879754942),  INT32_C(     3834292), -INT32_C(  1647889559),  INT32_C(   533783456),  INT32_C(   262691720) };
  static const int32_t e[] =
    {  INT32_C(   138963202),  INT32_C(  1774500896),  INT32_C(  1272809465),  INT32_C(    22086422),  INT32_C(  1329775430),  INT32_C(   285005747), -INT32_C(   169145567),  INT32_C(    48207611),
       INT32_C(     8988672),  INT32_C(  1744983668), -INT32_C(    63412250),  INT32_C(   808814600),  INT32_C(    71313505),  INT32_C(   538181711), -INT32_C(   966385717),  INT32_C(    12599698),
       INT32_C(  1909875837),  INT32_C(   671621185), -INT32_C(  1272674624), -INT32_C(  1234445243),  INT32_C(   587867968), -INT32_C(  1173090321),  INT32_C(    75528708),  INT32_C(  1016744383),
       INT32_C(  1907192237), -INT32_C(  1726280751),  INT32_C(  1620066562), -INT32_C(   250064487),  INT32_C(   429226026), -INT32_C(  1244419705), -INT32_C(  2145889533),  INT32_C(  1243493533),
       INT32_C(  2008796069),  INT32_C(  1476412992),  INT32_C(   895525016), -INT32_C(   987234661), -INT32_C(    35734410),  INT32_C(   137367845), -INT32_C(  2107112448),  INT32_C(   653035649),
       INT32_C(   698198099),  INT32_C(    75500662), -INT32_C(  1442315518),  INT32_C(  1669997312), -INT32_C(  1804300753),  INT32_C(  1142432301), -INT32_C(   186218893),  INT32_C(  1629147918),
      -INT32_C(  1735874526),  INT32_C(   536871200),  INT32_C(   832461872), -INT32_C(    22524209),  INT32_C(   462560476), -INT32_C(  1251955134),  INT32_C(      541232), -INT32_C(  1801206759),
      -INT32_C(   493998724),  INT32_C(    43124304), -INT32_C(   910477830),  INT32_C(  1606902659),  INT32_C(  1073762590),  INT32_C(   829624834),  INT32_C(     1311009),  INT32_C(  1640964325),
      -INT32_C(  1471980211), -INT32_C(  1793046365), -INT32_C(  2121481726),  INT32_C(  1080067137), -INT32_C(   443323426),  INT32_C(  1713375813),  INT32_C(   279026987),  INT32_C(   172032000),
      -INT32_C(   927812403), -INT32_C(  1665276530),  INT32_C(   607026131),  INT32_C(  1451232768), -INT32_C(  1937766272), -INT32_C(  1103764589),  INT32_C(     9392768),  INT32_C(   323436614),
      -INT32_C(  2082735371),  INT32_C(   303665361),  INT32_C(   332811539), -INT32_C(   168702868), -INT32_C(   406539180),  INT32_C(   293740690),  INT32_C(   391411152), -INT32_C(  1440047947),
       INT32_C(  1965885078), -INT32_C(  1306047074),  INT32_C(   113638810),  INT32_C(   519878601),  INT32_C(    33865803), -INT32_C(  1978004806), -INT32_C(   693997792),  INT32_C(   562085897),
       INT32_C(  1897311954), -INT32_C(  2061433560),  INT32_C(    75769858),  INT32_C(    35651734),  INT32_C(   319694680), -INT32_C(   207738669), -INT32_C(  1563869033), -INT32_C(   549238260),
      -INT32_C(   212837896), -INT32_C(  2121792768), -INT32_C(   113245117),  INT32_C(    17224844), -INT32_C(   249031650), -INT32_C(   723139012),  INT32_C(   309767686), -INT32_C(  1601172992),
       INT32_C(    39977217),  INT32_C(   276524212),  INT32_C(   134303888),  INT32_C(    16912389),  INT32_C(   538148868),  INT32_C(  1110443008), -INT32_C(   479679254),  INT32_C(  1632718886),
       INT32_C(  1075942553), -INT32_C(  1285513693),  INT32_C(   889220078),  INT32_C(    16859692),  INT32_C(   335597572),  INT32_C(   269625376),  INT32_C(  1078481312),  INT32_C(  1615039045),
      -INT32_C(  1455364218),  INT32_C(  1615601669), -INT32_C(  2144789247), -INT32_C(  1540881246),  INT32_C(  1082662946),  INT32_C(  1080099650),  INT32_C(   177219668),  INT32_C(  1161367623),
      -INT32_C(  1049166789),  INT32_C(     2195460), -INT32_C(   282075600),  INT32_C(  1090584579), -INT32_C(   423721853),  INT32_C(    19739317), -INT32_C(    79642957),  INT32_C(  1321794322),
      -INT32_C(  1810939913),  INT32_C(      541714),  INT32_C(  1160866594),  INT32_C(  1184878019),  INT32_C(   271336705),  INT32_C(  1271224728),  INT32_C(   709231895), -INT32_C(   126349568),
       INT32_C(  1619822414), -INT32_C(   308098869), -INT32_C(  1506770173), -INT32_C(   247606624), -INT32_C(   952014289), -INT32_C(   619575613),  INT32_C(        4104), -INT32_C(  1241219736),
      -INT32_C(   820604924), -INT32_C(  1950566312),  INT32_C(   746778507), -INT32_C(   266485567), -INT32_C(   306749654),  INT32_C(  1908984421),  INT32_C(     7406626),  INT32_C(  1312915786),
       INT32_C(  1763530513), -INT32_C(  1695229425), -INT32_C(  1962649727),  INT32_C(  1616109602), -INT32_C(  1471270077),  INT32_C(   538515453),  INT32_C(   799774436),  INT32_C(   675129349),
       INT32_C(    43059970),  INT32_C(  1055688309),  INT32_C(    13144805), -INT32_C(   627751529),  INT32_C(  1350566264),  INT32_C(   168067082),  INT32_C(  1242447922),  INT32_C(  1869777708),
      -INT32_C(  1878982652), -INT32_C(  2015711862), -INT32_C(   944136128),  INT32_C(   538001440),  INT32_C(   142672946),  INT32_C(   537157760), -INT32_C(   697558102), -INT32_C(  1941681632),
       INT32_C(  1835534051),  INT32_C(   351552180), -INT32_C(  1945885856),  INT32_C(   841997823),  INT32_C(   559940657) };

  static int32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t
      rv,
      av = simde_svld1_s32(pg, &(a[i])),
      bv = simde_svld1_s32(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_svand_s32_m(pv, av, bv);

    simde_svst1_s32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vi32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)], a[1024 / sizeof(int32_t)], b[1024 / sizeof(int32_t)], e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_s32(pg, &(a[i]));
    bv = simde_svld1_s32(pg, &(b[i]));

    ev = simde_svand_s32_m(pv, av, bv);

    simde_svst1_s32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_s64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1) };
  static const int64_t a[] =
    { -INT64_C( 8925838419461294379), -INT64_C( 5271654991467789110), -INT64_C( 7383068697981566709),  INT64_C( 6604975831066228343),
      -INT64_C(  427804377009348020), -INT64_C( 7974739665893640730),  INT64_C( 6810855405602395337),  INT64_C( 2745814621816243002),
       INT64_C( 2622151881865108538),  INT64_C( 7426179176232818167), -INT64_C( 4021477463122867733), -INT64_C( 1145422049518772453),
      -INT64_C( 8925363093939499840), -INT64_C( 1848989348251114158), -INT64_C( 7138230143432480358), -INT64_C( 2580655923662915448),
      -INT64_C( 7383092736437876361),  INT64_C( 3946244662842985441), -INT64_C( 1322284344225727351),  INT64_C( 6466424570460714949),
       INT64_C( 8485879642641504227), -INT64_C( 5385437450458739599), -INT64_C( 5484426744679063151),  INT64_C( 5609322849443778461),
      -INT64_C( 8146947831908321560), -INT64_C( 1628087168224509306),  INT64_C( 3107980234375309184), -INT64_C( 1258330558062414382),
      -INT64_C( 4583439312004513607),  INT64_C( 6836140836002135964),  INT64_C( 6105453385573252609), -INT64_C( 6731164101712517726),
      -INT64_C(  714985635316236263),  INT64_C( 6852729716721026524),  INT64_C( 8456820924148016519),  INT64_C( 2205272905265114126),
      -INT64_C( 3817498946852285772),  INT64_C( 4667874057952555017),  INT64_C( 7911880474287978116),  INT64_C( 6032008336837569169),
      -INT64_C( 5347066148428830959),  INT64_C( 8309393027917238615), -INT64_C( 3501663892817667942), -INT64_C( 2561391728831050623),
      -INT64_C( 7736154750938393022),  INT64_C( 4565793111378542841),  INT64_C( 4582869737611470732),  INT64_C( 6706937479131365227),
      -INT64_C( 7891451581553708886), -INT64_C( 6948536272067813458), -INT64_C( 3027542196343944450), -INT64_C( 2704096909281502207),
       INT64_C( 6933639839329928206), -INT64_C( 8499061556129909669),  INT64_C( 8884549254354728718), -INT64_C( 8815778168119535458),
       INT64_C(   64851006238517716), -INT64_C( 1572181932812363751),  INT64_C( 6262165909702604275),  INT64_C( 7062433177538952710),
      -INT64_C( 5990686269847884234), -INT64_C( 5030943239921710233),  INT64_C( 4972271125915930868),  INT64_C( 2989762276065683084),
      -INT64_C( 7263776008773998862), -INT64_C(  815700184748031699),  INT64_C( 8007578133184173213), -INT64_C( 7429805072578846009),
      -INT64_C(  559204142218876563), -INT64_C( 4123720379398349616), -INT64_C( 3548623173972761233), -INT64_C( 4619448217064944987),
       INT64_C( 2313336525114376534),  INT64_C( 1201253432576444091), -INT64_C( 5337009580735902438),  INT64_C( 4215057972356740972),
       INT64_C( 4203676487135256550),  INT64_C( 1598156626955552380),  INT64_C( 2151918734983794200), -INT64_C( 6288052287762080354),
       INT64_C(  716411599008438073), -INT64_C(  896968548731711366), -INT64_C( 8525321878936763167),  INT64_C( 2107622935233268437),
      -INT64_C( 3714125739670102562), -INT64_C( 3484431591889790250), -INT64_C( 8284353134245855340), -INT64_C( 5144407259758718054),
       INT64_C(  909613010990166145),  INT64_C( 5039355020948988211), -INT64_C(  331352806222704606),  INT64_C( 8102281323969350623),
       INT64_C( 7045848832382571909),  INT64_C(  773055529265235396),  INT64_C( 2962605812153024193),  INT64_C( 3473493209817192149),
       INT64_C( 2195702017872853225) };
  static const int64_t b[] =
    {  INT64_C( 2270105711361824402),  INT64_C( 6333938230282089181),  INT64_C( 4062945124733054997), -INT64_C( 8699262378023919177),
       INT64_C( 8923030122260829592), -INT64_C( 3493271886630940694),  INT64_C( 6206161084413649879), -INT64_C( 5686690521799780713),
       INT64_C( 7962429579403430758),  INT64_C( 4671113973445951818),  INT64_C( 8446862698241075012), -INT64_C(  276665066608999330),
       INT64_C( 1627069174398423201), -INT64_C( 7697234152485408637), -INT64_C(  330536706170596075),  INT64_C( 2452663550170327927),
       INT64_C( 1156823181601278764),  INT64_C( 3166639763549399052), -INT64_C( 7703538974691726465),  INT64_C( 5951132139270605555),
      -INT64_C( 4155600098651611466), -INT64_C(  377996173683502721),  INT64_C( 6571927683609321601),  INT64_C( 4049129152741103288),
       INT64_C( 5964402886153370436), -INT64_C( 9180964978840573919), -INT64_C( 7977189019943457656), -INT64_C( 4258820298588022230),
       INT64_C( 5926885758148436252),  INT64_C( 6480262944581888112), -INT64_C( 8314888038714372560), -INT64_C( 3966793121907799121),
      -INT64_C( 5979945510864767361), -INT64_C( 6609020955822067681), -INT64_C( 3024369290356878824), -INT64_C( 2465728084561215405),
      -INT64_C( 7738715273023357265), -INT64_C( 2767518312609630593), -INT64_C( 2280128122947615650),  INT64_C(  780995598871454107),
       INT64_C( 8155617545894191909), -INT64_C( 2529902046910041528),  INT64_C( 3291494241357870911),  INT64_C( 6522333987663678750),
       INT64_C( 6179540178822265695),  INT64_C( 6930831062446581461),  INT64_C( 7654107586856063097), -INT64_C( 5047014168538685849),
      -INT64_C( 2142363162504402206),  INT64_C( 6805894396919522290), -INT64_C( 2185475647719497484), -INT64_C( 2949168407880298753),
      -INT64_C( 2717064857353053092), -INT64_C( 2814079182774107986), -INT64_C(  189779016291886079), -INT64_C( 6260169176374650286),
      -INT64_C( 6969216032328915323), -INT64_C( 7450037250320812321), -INT64_C( 3784023720749386366), -INT64_C( 4520713265590578356),
      -INT64_C( 7806575764409723367), -INT64_C( 8800610901438243410), -INT64_C( 5698037161479834968),  INT64_C( 5499331872599703636),
      -INT64_C( 6400740997926059549),  INT64_C( 2118039232876151516),  INT64_C( 4526164810542246331), -INT64_C( 8455192021717607894),
      -INT64_C( 2648031920224338016), -INT64_C( 5665493188673327922), -INT64_C(  887031240005149048),  INT64_C( 4534274483016531643),
       INT64_C( 2942003235597585914),  INT64_C( 4029820819578064709),  INT64_C( 1812516735696944491),  INT64_C( 7905338466542254297),
      -INT64_C( 1443620667430367883), -INT64_C( 7228257402529356854), -INT64_C( 8194028263965762864), -INT64_C( 6895087806842551441),
      -INT64_C( 5054895926063155896), -INT64_C( 2191595977294282806), -INT64_C( 3927041727435611075), -INT64_C( 8581896885937404645),
      -INT64_C( 8766169003128891985), -INT64_C( 6106576055944836274), -INT64_C( 4279230356183428743), -INT64_C(  978141745155192668),
       INT64_C( 9190134010860397127), -INT64_C( 7526043709757060747), -INT64_C( 1162483634684679056),  INT64_C( 2415406983169698128),
       INT64_C( 8561814587792693025),  INT64_C( 4570001126704394166),  INT64_C( 3264608203817211412), -INT64_C( 9143355761131249376),
      -INT64_C( 6569444612726636451) };
  static const int64_t e[] =
    {  INT64_C(  288521873976235664),  INT64_C(                   0),  INT64_C( 1729965000228880385),  INT64_C(  216175548353093687),
       INT64_C( 8795565318920470536), -INT64_C( 9150187984362863134),  INT64_C( 6196958068942569665),  INT64_C(                   0),
       INT64_C( 2594074502075844642),  INT64_C( 4612530482087723330),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(  288371702654599296),  INT64_C(                   0), -INT64_C( 7464258430887788272),  INT64_C(                   0),
       INT64_C( 1155696689207052580),  INT64_C( 2504599614612113408),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C( 5746289487432761231),  INT64_C(                   0),  INT64_C(  581035821772310168),
       INT64_C(  198176046564258368),  INT64_C(                   0),  INT64_C(   72410023484990592), -INT64_C( 4287003532539719678),
       INT64_C( 4629702825444638744),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C( 6628502501720063975),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 2054397915405107202),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C( 5782868684595007552),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C( 1477778869025264194),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C( 4492340181618556684), -INT64_C( 3310125728346338303),
       INT64_C( 4614228777071805452),  INT64_C(                   0),  INT64_C( 8740431867200689152), -INT64_C( 9149062349735962606),
       INT64_C(   18089856890593412), -INT64_C( 8643493364607348711),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C( 9185011656572795376),  INT64_C(                   0),  INT64_C(        155172769952),  INT64_C(  599405580267945988),
      -INT64_C( 8997661882491600670),  INT64_C( 1451294879094964236),  INT64_C( 3314685481234481305),  INT64_C(                   0),
      -INT64_C( 2882219324607436512),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1235958891018194186),  INT64_C( 2897050824691707976),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(  884999864805952016), -INT64_C( 6914124928870399730),
       INT64_C(                   0), -INT64_C( 2196275501064908726), -INT64_C( 8538727816193096671),  INT64_C(  587370381653540881),
      -INT64_C( 8912546627842730610), -INT64_C( 8430732540737713594), -INT64_C( 8932871575821086448), -INT64_C( 5762249884958719872),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C( 6972029620308677889),  INT64_C(                   0),  INT64_C( 2957741563574310400),  INT64_C(                   0),
       INT64_C(  310924614358483017) };

  static int64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t
      rv,
      av = simde_svld1_s64(pg, &(a[i])),
      bv = simde_svld1_s64(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_svand_s64_z(pv, av, bv);

    simde_svst1_s64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vi64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)], a[1024 / sizeof(int64_t)], b[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_s64(pg, &(a[i]));
    bv = simde_svld1_s64(pg, &(b[i]));

    ev = simde_svand_s64_z(pv, av, bv);

    simde_svst1_s64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_s64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1) };
  static const int64_t a[] =
    {  INT64_C( 6093789237184769891),  INT64_C( 2709494545875294264), -INT64_C( 2162311783373907966), -INT64_C( 1383435725859522296),
       INT64_C(  186301019377781819),  INT64_C( 7443240056172140343), -INT64_C( 7219526853040953589), -INT64_C( 6447492846489805297),
      -INT64_C( 1513071262767262668), -INT64_C( 2765107035198383404), -INT64_C( 2291602338222720508),  INT64_C( 7495676655721598197),
       INT64_C( 4499490110427295186), -INT64_C( 2078666455146593664),  INT64_C( 8827809009067814609), -INT64_C( 3704808857133188103),
      -INT64_C( 2128861897253782580), -INT64_C( 3168186666834662587),  INT64_C( 2974337492380451654), -INT64_C( 3694661435338055437),
       INT64_C( 1381610913584516072), -INT64_C(  415947772530238110), -INT64_C( 7197582705372516156),  INT64_C( 5329801669125960748),
      -INT64_C( 3229151915286463923),  INT64_C( 7839486745270380316), -INT64_C( 3933473583327571677), -INT64_C( 9035087038626008334),
       INT64_C(  804963386266628070), -INT64_C(  411612245834046412),  INT64_C( 1918586393236843065),  INT64_C( 7555362879796319522),
       INT64_C( 8733864259663984698), -INT64_C(  999622400203681457),  INT64_C( 4218863599881938762),  INT64_C( 4605611240332589823),
      -INT64_C( 1971841522392847645), -INT64_C( 2136629714175199059), -INT64_C( 8330566893600234990),  INT64_C( 4908914114305062363),
      -INT64_C( 3379373021693442143),  INT64_C( 7026338139811095559), -INT64_C( 7796594384055904589),  INT64_C( 8252727369168837091),
       INT64_C(  653236360377398298), -INT64_C( 8315848499997882136), -INT64_C(  915189426658991615),  INT64_C( 7905433981443096434),
       INT64_C(  774261943705493170), -INT64_C( 7752426058757871869),  INT64_C( 4683631247737304571), -INT64_C( 6406307842138884520),
      -INT64_C( 9024338992935681129), -INT64_C( 2834513638581140350), -INT64_C( 1798092319952144643),  INT64_C( 6825111532239752730),
      -INT64_C( 5661066311500360850), -INT64_C( 7740720641333604642),  INT64_C( 8564557163356190821), -INT64_C( 8782515046807343367),
      -INT64_C( 1355333832136247984), -INT64_C( 3829119177463368015), -INT64_C( 6879642442237330508), -INT64_C( 7303009793682174969),
      -INT64_C( 5858820285966771532),  INT64_C( 5363455750699375167), -INT64_C( 3651046258151642098), -INT64_C( 1670673609285323283),
       INT64_C( 8167662970917939629),  INT64_C( 3501692893642706872), -INT64_C( 4665102687918558545),  INT64_C( 8073483819127549934),
      -INT64_C( 3651166860065720400), -INT64_C( 7199650594949469757),  INT64_C( 2321415609143916965), -INT64_C( 6650323567508312702),
       INT64_C(  497324790596947716),  INT64_C( 6470829013516091715), -INT64_C( 5454977136570867975), -INT64_C( 2248511328337948876),
       INT64_C( 8054651837606351230), -INT64_C( 6058066409489976608), -INT64_C(  490570453768225461),  INT64_C( 6300515922379615155),
       INT64_C( 2871571735241058366),  INT64_C( 3526222735891724433), -INT64_C( 7123323613273536923),  INT64_C( 8159004317797074185),
      -INT64_C( 4291450841810119933),  INT64_C( 4197907718365195308), -INT64_C( 3006846759341855043),  INT64_C( 1184996513659056590),
       INT64_C( 3259986007694199879), -INT64_C(  574349433131612679), -INT64_C( 4462251443635590034),  INT64_C(  465054658143177558),
      -INT64_C( 7733035034558279807), -INT64_C( 2650815412741935870),  INT64_C( 1336489075948377813),  INT64_C(  412899072030363636),
      -INT64_C(  366984028944450888), -INT64_C( 8544894521694467550) };
  static const int64_t b[] =
    { -INT64_C( 7777766858709836516),  INT64_C( 5645537935132901577), -INT64_C( 2169124669388867888),  INT64_C( 5253262240227263107),
       INT64_C( 5586556479585956531), -INT64_C( 1777273585971094225),  INT64_C( 1913708336167444241),  INT64_C( 5715821762793850590),
       INT64_C( 5923017611641271136), -INT64_C( 6780821730465565466), -INT64_C( 7692469533867647859),  INT64_C( 1229186593539949602),
       INT64_C(    7080969906835621), -INT64_C( 5976870302532078884),  INT64_C( 6344744176647756480),  INT64_C( 4888134709887282195),
      -INT64_C( 3346415365322453899),  INT64_C( 3631390531105164951),  INT64_C( 6427400033643607716), -INT64_C( 2142036199225800349),
       INT64_C(  830634257061859521), -INT64_C( 5606093070521875313), -INT64_C(  648870655452914594), -INT64_C( 3217755888048202744),
       INT64_C( 6488579627224255116),  INT64_C( 6238768579120713684), -INT64_C( 1588652594019294870), -INT64_C( 5406087399394514155),
       INT64_C( 7397093747092456066), -INT64_C(  369614506566352239), -INT64_C( 1816661688028964354),  INT64_C( 7111754324976150742),
      -INT64_C( 5079402699457337463), -INT64_C( 6421252738171876776), -INT64_C( 7083794123152040967),  INT64_C( 5672932190600281719),
       INT64_C( 1771862716981012916), -INT64_C( 1007710136237434698),  INT64_C( 5630184356107356607), -INT64_C( 4737681207856808659),
       INT64_C( 5449973017400289737),  INT64_C( 5112619697844036361),  INT64_C( 5502253186889265205),  INT64_C( 3059209005025853867),
       INT64_C( 5262269525649526567), -INT64_C( 7942592325810933511),  INT64_C( 3124082516124602863),  INT64_C( 4433042962718497017),
      -INT64_C( 8579637048640915099),  INT64_C( 7466632247236901553),  INT64_C( 3317691901506042975), -INT64_C( 6504590666171356313),
       INT64_C( 7520231509715563846), -INT64_C( 7830611638847445644),  INT64_C(   50239544648452432), -INT64_C( 8120771568868639897),
       INT64_C( 5047623492332460270), -INT64_C( 1806358420195737049),  INT64_C( 4893475304760827984), -INT64_C( 8201275233384372392),
       INT64_C( 9072289615665403087), -INT64_C( 1135533139056649535),  INT64_C( 2109307251416737830),  INT64_C( 3988479975068872746),
      -INT64_C( 8262767430290862975),  INT64_C( 1903653696628403674),  INT64_C( 3651401182495917258), -INT64_C( 2868698026778727790),
      -INT64_C( 6684463582153864733),  INT64_C( 1026407591332094256),  INT64_C( 5622263359700097741),  INT64_C( 4459540384158581684),
      -INT64_C( 4112586258752171391),  INT64_C( 6961483738230950730),  INT64_C( 4147317750331947651), -INT64_C( 3398484550760409537),
       INT64_C( 3753478616912675515), -INT64_C( 5978705343520046573), -INT64_C( 5307356409305940839), -INT64_C( 9192086783728313007),
      -INT64_C( 6555295390779733273), -INT64_C( 4484650471821424149),  INT64_C( 8988120713774805134),  INT64_C( 1809192720474508501),
      -INT64_C( 4590028020249793515),  INT64_C( 8693242414839011258), -INT64_C( 7930773263205104567), -INT64_C( 6084004009525703865),
       INT64_C( 2939054427259173939), -INT64_C( 9108337590766166218), -INT64_C( 7385651244511717581),  INT64_C( 2680384990282361840),
       INT64_C( 6464624947689784607), -INT64_C( 6679380921650921067),  INT64_C( 1807089315563586345), -INT64_C( 1669477802465811011),
      -INT64_C( 8154844679037975977), -INT64_C( 8502890240609136916),  INT64_C( 7002843034312544749), -INT64_C(  437159634054099139),
       INT64_C( 8893844621893067751),  INT64_C( 6953513242745948566) };
  static const int64_t e[] =
    {  INT64_C( 6093789237184769891),  INT64_C( 2709494545875294264), -INT64_C( 2162311783373907966),  INT64_C( 5243601774296170496),
       INT64_C(  186301019377781819),  INT64_C( 7440389709177558311), -INT64_C( 7219526853040953589), -INT64_C( 6447492846489805297),
      -INT64_C( 1513071262767262668), -INT64_C( 2765107035198383404), -INT64_C( 2291602338222720508),  INT64_C( 7495676655721598197),
       INT64_C( 4499490110427295186), -INT64_C( 2078666455146593664),  INT64_C( 8827809009067814609),  INT64_C( 4653349365947213841),
      -INT64_C( 4610559706102839228),  INT64_C( 1152994081588152837),  INT64_C( 2974337492380451654), -INT64_C( 3694661435338055437),
       INT64_C(  217300073623584960), -INT64_C(  415947772530238110), -INT64_C( 7774325105797853116),  INT64_C( 4706261615476020232),
       INT64_C( 5912118282214820364),  INT64_C( 4935948081038968596), -INT64_C( 3935732100470144734), -INT64_C( 9035087038626008334),
       INT64_C(  154179577517965954), -INT64_C(  411612245834046412),  INT64_C(  180179173086627896),  INT64_C( 7555362879796319522),
       INT64_C( 8733864259663984698), -INT64_C(  999622400203681457),  INT64_C( 1765492444675294024),  INT64_C( 4605611240332589823),
       INT64_C(   36741830450620576), -INT64_C( 2161410507813103452),  INT64_C(  874367397733335058),  INT64_C( 4908914114305062363),
      -INT64_C( 3379373021693442143),  INT64_C( 4648418532972306433),  INT64_C(   20527980883906609),  INT64_C( 8252727369168837091),
       INT64_C(  648590915125904386), -INT64_C( 9187296682389733144),  INT64_C( 2542449184280936449),  INT64_C( 7905433981443096434),
       INT64_C(  774261943705493170), -INT64_C( 7752426058757871869),  INT64_C( 4683631247737304571), -INT64_C( 6550476586343194048),
       INT64_C(   18324695154196742), -INT64_C( 2834513638581140350),  INT64_C(     673491680542800),  INT64_C( 1010257946876185090),
       INT64_C(    3591016317980782), -INT64_C( 7740720641333604642),  INT64_C( 4812387971326697536), -INT64_C( 8782515046807343367),
      -INT64_C( 1355333832136247984), -INT64_C( 3829119177463368015), -INT64_C( 6879642442237330508), -INT64_C( 7303009793682174969),
      -INT64_C( 5858820285966771532),  INT64_C(  750415114550904858),  INT64_C(    1231476714112010), -INT64_C( 4030701788567101312),
       INT64_C( 8167662970917939629),  INT64_C( 3501692893642706872), -INT64_C( 4665102687918558545),  INT64_C( 8073483819127549934),
      -INT64_C( 4304280072480058752), -INT64_C( 7199650594949469757),  INT64_C( 2321415609143916965), -INT64_C( 9181704660719762430),
       INT64_C(  497324790596947716),  INT64_C(  649925859213443075), -INT64_C( 5456107435062190951), -INT64_C( 9202220989230248688),
       INT64_C( 8054651837606351230), -INT64_C( 9096919265792261920),  INT64_C( 8660457272180256778),  INT64_C( 6300515922379615155),
       INT64_C(   20496293177092116),  INT64_C( 3505076906772009104), -INT64_C( 7989356429558643647),  INT64_C( 2382406480824893697),
       INT64_C(   18458747375603715),  INT64_C(     182587649887268), -INT64_C( 8070309517073316303),  INT64_C( 1184996513659056590),
       INT64_C( 3259986007694199879), -INT64_C(  574349433131612679),  INT64_C(    4503738064584744),  INT64_C(  465054658143177558),
      -INT64_C( 8897941230948711935), -INT64_C( 2650815412741935870),  INT64_C(    3387195927072965),  INT64_C(  120156280018980660),
      -INT64_C(  366984028944450888),  INT64_C(   29914621265070082) };

  static int64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t
      rv,
      av = simde_svld1_s64(pg, &(a[i])),
      bv = simde_svld1_s64(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_svand_s64_m(pv, av, bv);

    simde_svst1_s64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vi64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)], a[1024 / sizeof(int64_t)], b[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_s64(pg, &(a[i]));
    bv = simde_svld1_s64(pg, &(b[i]));

    ev = simde_svand_s64_m(pv, av, bv);

    simde_svst1_s64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_u8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1) };
  static const uint8_t a[] =
    { UINT8_C(186), UINT8_C( 92), UINT8_C( 76), UINT8_C( 16), UINT8_C( 87), UINT8_C(175), UINT8_C(167), UINT8_C(110),
      UINT8_C(  4), UINT8_C( 73), UINT8_C(168), UINT8_C(201), UINT8_C(130), UINT8_C( 72), UINT8_C(200), UINT8_C(240),
      UINT8_C(243), UINT8_C( 16), UINT8_C(251), UINT8_C( 64), UINT8_C(109), UINT8_C( 27), UINT8_C(131), UINT8_C(122),
      UINT8_C(167), UINT8_C(191), UINT8_C( 22), UINT8_C( 66), UINT8_C(109), UINT8_C( 80), UINT8_C(221), UINT8_C( 40),
      UINT8_C(173), UINT8_C( 41), UINT8_C( 56), UINT8_C(  4), UINT8_C(216), UINT8_C(223), UINT8_C(115), UINT8_C(220),
      UINT8_C( 40), UINT8_C( 27), UINT8_C(165), UINT8_C(170), UINT8_C( 99), UINT8_C(109), UINT8_C(154), UINT8_C( 86),
      UINT8_C(125), UINT8_C(149), UINT8_C(150), UINT8_C(235), UINT8_C(177), UINT8_C( 25), UINT8_C(101), UINT8_C( 88),
      UINT8_C(217), UINT8_C(123), UINT8_C(154), UINT8_C( 70), UINT8_C(204), UINT8_C(119), UINT8_C(110), UINT8_C(121),
      UINT8_C(160), UINT8_C(166), UINT8_C(125), UINT8_C(121), UINT8_C(133), UINT8_C(240), UINT8_C( 85), UINT8_C(174),
      UINT8_C( 11), UINT8_C(251), UINT8_C( 88), UINT8_C(110), UINT8_C(104), UINT8_C(243), UINT8_C(196), UINT8_C(230),
      UINT8_C(136), UINT8_C( 90), UINT8_C(209), UINT8_C( 57), UINT8_C(116), UINT8_C( 54), UINT8_C(146), UINT8_C( 77),
      UINT8_C(178), UINT8_C( 44), UINT8_C(147), UINT8_C(126), UINT8_C(164), UINT8_C(  2), UINT8_C(247), UINT8_C( 68),
      UINT8_C(168), UINT8_C(116), UINT8_C(189), UINT8_C( 46), UINT8_C(101), UINT8_C( 19), UINT8_C(220), UINT8_C(112),
      UINT8_C( 14), UINT8_C( 52), UINT8_C(223), UINT8_C(118), UINT8_C( 39), UINT8_C(163), UINT8_C( 92), UINT8_C(176),
      UINT8_C(254), UINT8_C( 45), UINT8_C(233), UINT8_C(114), UINT8_C(100), UINT8_C(123), UINT8_C(191), UINT8_C( 22),
      UINT8_C(168), UINT8_C( 82), UINT8_C(148), UINT8_C( 76), UINT8_C( 84), UINT8_C(139), UINT8_C(144), UINT8_C(253),
         UINT8_MAX, UINT8_C( 78), UINT8_C( 43), UINT8_C(100), UINT8_C( 97), UINT8_C(  7), UINT8_C(213), UINT8_C(111),
      UINT8_C( 59), UINT8_C(180), UINT8_C(229), UINT8_C( 99), UINT8_C( 87), UINT8_C( 66), UINT8_C( 19), UINT8_C( 85),
      UINT8_C(111), UINT8_C(252), UINT8_C(199), UINT8_C(211), UINT8_C(120), UINT8_C(134), UINT8_C(233), UINT8_C( 32),
      UINT8_C(217), UINT8_C(125), UINT8_C(108), UINT8_C( 45), UINT8_C(  8), UINT8_C(252), UINT8_C( 42), UINT8_C(  8),
      UINT8_C( 74), UINT8_C( 85), UINT8_C(108), UINT8_C(171), UINT8_C( 92), UINT8_C( 65), UINT8_C( 26), UINT8_C(152),
      UINT8_C(245), UINT8_C(  0), UINT8_C(251), UINT8_C( 77), UINT8_C( 66), UINT8_C( 14), UINT8_C(162), UINT8_C(177),
      UINT8_C( 10), UINT8_C(106), UINT8_C(133), UINT8_C(130), UINT8_C(240), UINT8_C(110), UINT8_C(162), UINT8_C(201),
      UINT8_C(236), UINT8_C( 14), UINT8_C(247), UINT8_C(244), UINT8_C( 11), UINT8_C( 33), UINT8_C(252), UINT8_C( 85),
      UINT8_C(119), UINT8_C(105), UINT8_C(  1), UINT8_C(211), UINT8_C(170), UINT8_C( 27), UINT8_C(107), UINT8_C(160),
      UINT8_C( 27), UINT8_C(102), UINT8_C(237), UINT8_C( 93), UINT8_C(116), UINT8_C(143), UINT8_C( 15), UINT8_C(127),
      UINT8_C(249), UINT8_C(148), UINT8_C(  1), UINT8_C(234), UINT8_C(  2), UINT8_C(164), UINT8_C(179), UINT8_C(238),
      UINT8_C(178), UINT8_C(170), UINT8_C(227), UINT8_C(189), UINT8_C(204), UINT8_C(223), UINT8_C( 19), UINT8_C( 67),
      UINT8_C( 72), UINT8_C( 20), UINT8_C( 22), UINT8_C(243), UINT8_C( 47), UINT8_C(130), UINT8_C(147), UINT8_C( 75),
      UINT8_C(232), UINT8_C(128), UINT8_C(168), UINT8_C( 93), UINT8_C( 15), UINT8_C(183), UINT8_C(220), UINT8_C(  9),
      UINT8_C( 75), UINT8_C(221), UINT8_C(243), UINT8_C( 78), UINT8_C(129), UINT8_C(166), UINT8_C( 60), UINT8_C( 52),
      UINT8_C( 81), UINT8_C( 31), UINT8_C(241), UINT8_C( 29),    UINT8_MAX, UINT8_C(  4), UINT8_C( 96), UINT8_C( 71),
      UINT8_C( 24), UINT8_C(118), UINT8_C( 58), UINT8_C( 72), UINT8_C(248), UINT8_C(205), UINT8_C(147), UINT8_C(225),
      UINT8_C( 77), UINT8_C( 59), UINT8_C( 62), UINT8_C( 93), UINT8_C(243), UINT8_C( 26), UINT8_C(102), UINT8_C( 62),
      UINT8_C(247), UINT8_C( 89), UINT8_C(140), UINT8_C(121),    UINT8_MAX, UINT8_C(201), UINT8_C(173), UINT8_C( 80),
      UINT8_C(232), UINT8_C(158), UINT8_C(109), UINT8_C(231), UINT8_C(163), UINT8_C(205), UINT8_C( 47), UINT8_C(187),
      UINT8_C( 68), UINT8_C(105), UINT8_C(  3), UINT8_C( 60), UINT8_C( 55), UINT8_C(150), UINT8_C( 29), UINT8_C(132),
      UINT8_C(210), UINT8_C( 91), UINT8_C(225), UINT8_C(197), UINT8_C(117), UINT8_C( 71), UINT8_C(  3), UINT8_C(109),
      UINT8_C(160), UINT8_C(144), UINT8_C(230), UINT8_C(160), UINT8_C( 89), UINT8_C(147), UINT8_C(240), UINT8_C( 65),
      UINT8_C( 49), UINT8_C( 94), UINT8_C( 41) };
  static const uint8_t b[] =
    { UINT8_C(170), UINT8_C( 86), UINT8_C(170), UINT8_C( 85), UINT8_C(250), UINT8_C(186), UINT8_C(189), UINT8_C( 36),
      UINT8_C(133), UINT8_C(224), UINT8_C(165), UINT8_C(236), UINT8_C(138), UINT8_C(201), UINT8_C(110), UINT8_C( 16),
      UINT8_C(167), UINT8_C( 40), UINT8_C(  0), UINT8_C(124), UINT8_C( 67), UINT8_C( 29), UINT8_C( 17), UINT8_C( 17),
      UINT8_C( 42), UINT8_C(212), UINT8_C(125), UINT8_C(200), UINT8_C(155), UINT8_C(233), UINT8_C(248), UINT8_C( 69),
      UINT8_C( 63), UINT8_C(162), UINT8_C(155), UINT8_C( 57), UINT8_C( 93), UINT8_C( 88), UINT8_C( 93), UINT8_C(226),
      UINT8_C( 57), UINT8_C(  2), UINT8_C(206), UINT8_C(195), UINT8_C(203), UINT8_C( 60), UINT8_C(211), UINT8_C(115),
      UINT8_C(101), UINT8_C(212), UINT8_C(239), UINT8_C(168), UINT8_C(241), UINT8_C(  1), UINT8_C(185), UINT8_C( 27),
      UINT8_C(213), UINT8_C( 54), UINT8_C(227), UINT8_C(112), UINT8_C( 31), UINT8_C(219), UINT8_C(182), UINT8_C( 94),
      UINT8_C(125), UINT8_C( 81), UINT8_C(152), UINT8_C(218), UINT8_C(169), UINT8_C(245), UINT8_C(189), UINT8_C(226),
      UINT8_C(248), UINT8_C(139), UINT8_C(166), UINT8_C(195), UINT8_C(200), UINT8_C(121), UINT8_C( 54), UINT8_C( 45),
      UINT8_C( 77), UINT8_C( 38), UINT8_C(213), UINT8_C( 62), UINT8_C( 39), UINT8_C(142), UINT8_C( 89), UINT8_C(252),
      UINT8_C(196), UINT8_C( 60), UINT8_C(108), UINT8_C(227), UINT8_C( 23), UINT8_C( 34), UINT8_C( 65), UINT8_C(149),
      UINT8_C(115), UINT8_C(217), UINT8_C(111), UINT8_C( 29), UINT8_C(207), UINT8_C( 44),    UINT8_MAX, UINT8_C(199),
      UINT8_C(184), UINT8_C(165), UINT8_C(138), UINT8_C(128), UINT8_C( 31), UINT8_C(193), UINT8_C(173), UINT8_C(108),
      UINT8_C(231), UINT8_C(130), UINT8_C(171), UINT8_C( 14), UINT8_C( 16), UINT8_C(  4), UINT8_C( 10), UINT8_C(212),
      UINT8_C( 65), UINT8_C(118), UINT8_C(183), UINT8_C( 88), UINT8_C(153), UINT8_C(248), UINT8_C(237), UINT8_C( 12),
      UINT8_C(210), UINT8_C( 93), UINT8_C( 41), UINT8_C(161), UINT8_C(137), UINT8_C( 41), UINT8_C(104), UINT8_C( 65),
      UINT8_C(206), UINT8_C(242), UINT8_C(193), UINT8_C(237), UINT8_C(179), UINT8_C(110), UINT8_C( 90), UINT8_C(154),
      UINT8_C(240), UINT8_C(  5), UINT8_C(168), UINT8_C(  0), UINT8_C(  9), UINT8_C(178), UINT8_C(212), UINT8_C( 74),
      UINT8_C( 41), UINT8_C(139), UINT8_C(163), UINT8_C(194), UINT8_C(132), UINT8_C(144), UINT8_C(206), UINT8_C( 86),
      UINT8_C(237), UINT8_C(248), UINT8_C(247), UINT8_C(119), UINT8_C( 33), UINT8_C( 95), UINT8_C(184), UINT8_C(239),
      UINT8_C( 81), UINT8_C(122), UINT8_C(221), UINT8_C(  5), UINT8_C(232), UINT8_C( 55), UINT8_C(159), UINT8_C(217),
      UINT8_C( 60), UINT8_C( 72), UINT8_C(217), UINT8_C( 69), UINT8_C(250), UINT8_C(174), UINT8_C(144), UINT8_C( 35),
      UINT8_C( 57), UINT8_C( 51), UINT8_C(229), UINT8_C(189), UINT8_C(195), UINT8_C(180), UINT8_C( 19), UINT8_C(177),
      UINT8_C(172), UINT8_C( 10), UINT8_C( 40), UINT8_C(205), UINT8_C(105), UINT8_C(224), UINT8_C(188), UINT8_C(187),
      UINT8_C( 90), UINT8_C(153), UINT8_C(192), UINT8_C( 67), UINT8_C(208), UINT8_C( 95), UINT8_C( 28), UINT8_C( 12),
      UINT8_C(167), UINT8_C(245), UINT8_C( 82), UINT8_C(162), UINT8_C(163), UINT8_C(226), UINT8_C(197), UINT8_C(221),
      UINT8_C( 21), UINT8_C(171), UINT8_C(154), UINT8_C(216), UINT8_C( 95), UINT8_C(174), UINT8_C(137), UINT8_C( 11),
      UINT8_C(184), UINT8_C(177), UINT8_C(216), UINT8_C( 34), UINT8_C(146), UINT8_C(148), UINT8_C(221), UINT8_C(236),
      UINT8_C( 46), UINT8_C(157), UINT8_C( 47), UINT8_C(254), UINT8_C(252), UINT8_C( 75), UINT8_C( 11), UINT8_C(164),
      UINT8_C( 65), UINT8_C( 93), UINT8_C( 70), UINT8_C(228), UINT8_C( 63), UINT8_C( 11), UINT8_C(193), UINT8_C( 84),
      UINT8_C(182), UINT8_C( 92), UINT8_C( 44), UINT8_C( 21), UINT8_C( 10), UINT8_C(182), UINT8_C( 32), UINT8_C(194),
      UINT8_C(103), UINT8_C(248), UINT8_C(228), UINT8_C(249), UINT8_C(141), UINT8_C(193), UINT8_C(230), UINT8_C(187),
      UINT8_C( 94), UINT8_C( 21), UINT8_C(185), UINT8_C( 91), UINT8_C( 97), UINT8_C(196),    UINT8_MAX, UINT8_C(162),
      UINT8_C( 33), UINT8_C( 69), UINT8_C(134), UINT8_C( 96), UINT8_C( 80), UINT8_C( 72), UINT8_C(180), UINT8_C(  7),
      UINT8_C(164), UINT8_C(225), UINT8_C( 28), UINT8_C(174), UINT8_C(151), UINT8_C( 61), UINT8_C(112), UINT8_C(254),
      UINT8_C( 53), UINT8_C( 85), UINT8_C(248), UINT8_C(194), UINT8_C( 22), UINT8_C(222), UINT8_C(125), UINT8_C(117),
      UINT8_C(243), UINT8_C( 55), UINT8_C(208), UINT8_C( 84), UINT8_C(251), UINT8_C(207), UINT8_C(246), UINT8_C( 29),
      UINT8_C( 20), UINT8_C(125), UINT8_C(125), UINT8_C(100), UINT8_C(197), UINT8_C( 50), UINT8_C(107), UINT8_C(105),
      UINT8_C( 19), UINT8_C(136), UINT8_C( 23) };
  static const uint8_t e[] =
    { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(170), UINT8_C(165), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(130), UINT8_C(  0), UINT8_C( 72), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0),
      UINT8_C( 34), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 24), UINT8_C(  0), UINT8_C( 88), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(146), UINT8_C( 82),
      UINT8_C(101), UINT8_C(148), UINT8_C(134), UINT8_C(168), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C( 24),
      UINT8_C(209), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 38), UINT8_C( 88),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 24), UINT8_C(  0), UINT8_C(129), UINT8_C(240), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  8), UINT8_C(139), UINT8_C(  0), UINT8_C(  0), UINT8_C( 72), UINT8_C(  0), UINT8_C(  4), UINT8_C( 36),
      UINT8_C(  8), UINT8_C(  2), UINT8_C(209), UINT8_C(  0), UINT8_C(  0), UINT8_C(  6), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(128), UINT8_C( 44), UINT8_C(  0), UINT8_C(  0), UINT8_C(  4), UINT8_C(  0), UINT8_C( 65), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 45), UINT8_C( 12), UINT8_C( 69), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(138), UINT8_C(  0), UINT8_C(  0), UINT8_C(129), UINT8_C( 12), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(169), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 82), UINT8_C(  0), UINT8_C( 72), UINT8_C( 16), UINT8_C(  0), UINT8_C(  0), UINT8_C( 12),
      UINT8_C(210), UINT8_C( 76), UINT8_C( 41), UINT8_C( 32), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C( 65),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 97), UINT8_C( 19), UINT8_C( 66), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 96), UINT8_C(  4), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  9), UINT8_C(  9), UINT8_C( 32), UINT8_C(  0), UINT8_C(  0), UINT8_C(144), UINT8_C( 10), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 80), UINT8_C(100), UINT8_C( 35), UINT8_C(  0), UINT8_C(  0), UINT8_C( 24), UINT8_C(136),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  5), UINT8_C(  0), UINT8_C(  6), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  8), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  1),
      UINT8_C( 40), UINT8_C(  0), UINT8_C(229), UINT8_C(180), UINT8_C(  3), UINT8_C( 32), UINT8_C( 16), UINT8_C(  0),
      UINT8_C( 36), UINT8_C(  8), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 40), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 65), UINT8_C( 80), UINT8_C(  0), UINT8_C(  0), UINT8_C( 12),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0), UINT8_C(204),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  3),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 16), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C( 72),
      UINT8_C( 40), UINT8_C(  0), UINT8_C(  0), UINT8_C( 92), UINT8_C( 12), UINT8_C(  3), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 93), UINT8_C(  0), UINT8_C( 68), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 16), UINT8_C( 28), UINT8_C(  0), UINT8_C( 21), UINT8_C( 10), UINT8_C(  4), UINT8_C(  0), UINT8_C( 66),
      UINT8_C(  0), UINT8_C(112), UINT8_C( 32), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 76), UINT8_C( 17), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(102), UINT8_C( 34),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(132), UINT8_C(  0), UINT8_C( 80), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(160), UINT8_C(  0), UINT8_C( 12), UINT8_C(166), UINT8_C(  0), UINT8_C(  0), UINT8_C( 32), UINT8_C(186),
      UINT8_C(  4), UINT8_C( 65), UINT8_C(  0), UINT8_C(  0), UINT8_C( 22), UINT8_C(  0), UINT8_C( 29), UINT8_C(  0),
      UINT8_C(210), UINT8_C( 19), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  2), UINT8_C( 13),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(100), UINT8_C(  0), UINT8_C(  0), UINT8_C( 18), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  1) };

  static uint8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t
      rv,
      av = simde_svld1_u8(pg, &(a[i])),
      bv = simde_svld1_u8(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(INT8_C(0)));
    rv = simde_svand_u8_z(pv, av, bv);

    simde_svst1_u8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vu8(len, e, r);

  return 0;
#else
  int8_t p[1024];
  uint8_t a[1024], b[1024], e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_u8(pg, &(a[i]));
    bv = simde_svld1_u8(pg, &(b[i]));

    ev = simde_svand_u8_z(pv, av, bv);

    simde_svst1_u8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_u8_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) };
  static const uint8_t a[] =
    { UINT8_C( 53), UINT8_C(128), UINT8_C(218), UINT8_C(105), UINT8_C( 64), UINT8_C( 21), UINT8_C( 96), UINT8_C(155),
      UINT8_C(163), UINT8_C( 30), UINT8_C(200), UINT8_C(105), UINT8_C(130), UINT8_C(106), UINT8_C( 69), UINT8_C( 14),
      UINT8_C( 49), UINT8_C( 22), UINT8_C(128), UINT8_C(  9), UINT8_C( 20), UINT8_C( 97), UINT8_C(148), UINT8_C( 16),
      UINT8_C(111), UINT8_C( 80),    UINT8_MAX, UINT8_C( 88), UINT8_C(183), UINT8_C(184), UINT8_C(222), UINT8_C(236),
      UINT8_C( 56), UINT8_C(184), UINT8_C( 85), UINT8_C(120), UINT8_C(205), UINT8_C(181), UINT8_C( 19), UINT8_C(112),
      UINT8_C(211), UINT8_C(219), UINT8_C(217), UINT8_C( 85), UINT8_C( 69), UINT8_C( 30), UINT8_C( 99), UINT8_C(119),
      UINT8_C( 52), UINT8_C(228), UINT8_C(128), UINT8_C( 72), UINT8_C( 69), UINT8_C( 20), UINT8_C( 88), UINT8_C(180),
      UINT8_C(100), UINT8_C( 87), UINT8_C( 12), UINT8_C( 27), UINT8_C( 15), UINT8_C(234), UINT8_C(  7), UINT8_C( 71),
      UINT8_C(162), UINT8_C( 92), UINT8_C(191), UINT8_C(111), UINT8_C( 17), UINT8_C(210), UINT8_C(223), UINT8_C(228),
      UINT8_C(173), UINT8_C(185), UINT8_C( 57), UINT8_C(243), UINT8_C(215), UINT8_C(156), UINT8_C(106), UINT8_C( 12),
      UINT8_C(128), UINT8_C(234), UINT8_C( 84), UINT8_C(198), UINT8_C(254), UINT8_C(173), UINT8_C(122), UINT8_C( 98),
      UINT8_C(  4), UINT8_C(135), UINT8_C(125), UINT8_C( 20), UINT8_C(113), UINT8_C(132), UINT8_C( 91), UINT8_C( 20),
      UINT8_C(224), UINT8_C( 27), UINT8_C(131), UINT8_C(241), UINT8_C(237), UINT8_C( 99), UINT8_C(213), UINT8_C(155),
      UINT8_C( 28), UINT8_C( 14), UINT8_C(142), UINT8_C(243), UINT8_C(170), UINT8_C(248),    UINT8_MAX, UINT8_C( 43),
      UINT8_C(226), UINT8_C( 84), UINT8_C(241), UINT8_C(224), UINT8_C(  1), UINT8_C(107), UINT8_C( 66), UINT8_C(  5),
      UINT8_C(242), UINT8_C(191), UINT8_C( 25), UINT8_C(100), UINT8_C( 67), UINT8_C(117), UINT8_C(120), UINT8_C( 35),
      UINT8_C(144), UINT8_C(251), UINT8_C( 20), UINT8_C(125), UINT8_C( 94), UINT8_C(233), UINT8_C( 24), UINT8_C(122),
      UINT8_C(247), UINT8_C(166), UINT8_C(110), UINT8_C(161), UINT8_C(158), UINT8_C(109), UINT8_C(204), UINT8_C(128),
      UINT8_C(193), UINT8_C(189), UINT8_C( 96), UINT8_C(194), UINT8_C( 41), UINT8_C(162), UINT8_C(200), UINT8_C( 27),
      UINT8_C( 97), UINT8_C(225), UINT8_C(127), UINT8_C(164), UINT8_C( 86), UINT8_C(247), UINT8_C(199), UINT8_C(230),
      UINT8_C(243), UINT8_C(219), UINT8_C(100), UINT8_C( 81), UINT8_C(196), UINT8_C(124), UINT8_C(204), UINT8_C(187),
      UINT8_C( 35), UINT8_C( 58), UINT8_C( 93), UINT8_C(193), UINT8_C(167), UINT8_C( 41), UINT8_C( 66), UINT8_C(105),
      UINT8_C(231), UINT8_C(162), UINT8_C( 43), UINT8_C( 16), UINT8_C( 69), UINT8_C(243), UINT8_C( 43), UINT8_C(166),
      UINT8_C(213), UINT8_C(171), UINT8_C( 75), UINT8_C( 43), UINT8_C(162), UINT8_C( 18), UINT8_C( 18), UINT8_C(149),
      UINT8_C(238), UINT8_C(118), UINT8_C(231), UINT8_C(178), UINT8_C(242), UINT8_C(179), UINT8_C(110), UINT8_C( 21),
      UINT8_C(237), UINT8_C(203), UINT8_C(215), UINT8_C(148), UINT8_C(244), UINT8_C( 25), UINT8_C(253), UINT8_C(219),
      UINT8_C(187), UINT8_C( 41), UINT8_C(235), UINT8_C(  0), UINT8_C( 28), UINT8_C( 23), UINT8_C(167), UINT8_C(241),
      UINT8_C(194), UINT8_C(242), UINT8_C( 29), UINT8_C(100), UINT8_C(  4), UINT8_C( 47), UINT8_C(250), UINT8_C(242),
      UINT8_C(165), UINT8_C(225), UINT8_C(165), UINT8_C(151), UINT8_C(148), UINT8_C( 19), UINT8_C(173), UINT8_C(129),
      UINT8_C(222), UINT8_C(132), UINT8_C( 21), UINT8_C(210), UINT8_C(157), UINT8_C( 19), UINT8_C(174), UINT8_C( 88),
      UINT8_C( 60), UINT8_C(153), UINT8_C( 89), UINT8_C( 88), UINT8_C(176), UINT8_C(  0), UINT8_C( 74), UINT8_C(114),
      UINT8_C(242), UINT8_C(103), UINT8_C(215), UINT8_C(246), UINT8_C(150), UINT8_C(209), UINT8_C(233), UINT8_C( 59),
      UINT8_C(178), UINT8_C(142), UINT8_C(210), UINT8_C( 70), UINT8_C(161), UINT8_C(127), UINT8_C(199), UINT8_C(127),
      UINT8_C(  3), UINT8_C(220), UINT8_C( 81), UINT8_C(160), UINT8_C(239),    UINT8_MAX, UINT8_C(249), UINT8_C( 43),
      UINT8_C(153), UINT8_C( 82), UINT8_C(132), UINT8_C( 73), UINT8_C( 82), UINT8_C(206), UINT8_C(188), UINT8_C( 68),
      UINT8_C( 53), UINT8_C(147), UINT8_C( 58), UINT8_C(203), UINT8_C(100), UINT8_C( 35), UINT8_C(  6), UINT8_C( 22),
      UINT8_C(177), UINT8_C(216), UINT8_C( 92), UINT8_C( 82), UINT8_C( 88), UINT8_C( 35), UINT8_C(209), UINT8_C( 91),
         UINT8_MAX, UINT8_C( 35), UINT8_C(252), UINT8_C(239), UINT8_C( 34), UINT8_C(245), UINT8_C( 26), UINT8_C(187),
      UINT8_C( 71), UINT8_C(158), UINT8_C(  5), UINT8_C(153), UINT8_C(108), UINT8_C(193), UINT8_C(221), UINT8_C(161),
      UINT8_C( 84), UINT8_C( 23), UINT8_C(108), UINT8_C(184), UINT8_C( 59), UINT8_C(114), UINT8_C(206), UINT8_C(236),
      UINT8_C( 75), UINT8_C( 42), UINT8_C( 63), UINT8_C(163), UINT8_C( 77), UINT8_C( 16), UINT8_C(254), UINT8_C( 76),
      UINT8_C( 51), UINT8_C(250), UINT8_C( 59), UINT8_C( 86), UINT8_C(239), UINT8_C( 86), UINT8_C( 17), UINT8_C( 54),
      UINT8_C(244), UINT8_C( 22), UINT8_C(207), UINT8_C( 97), UINT8_C(215), UINT8_C(172), UINT8_C(  2), UINT8_C( 43),
      UINT8_C(196), UINT8_C(111), UINT8_C(227),    UINT8_MAX, UINT8_C(225), UINT8_C(177), UINT8_C(235), UINT8_C( 44),
      UINT8_C(219), UINT8_C( 42), UINT8_C(207), UINT8_C( 40), UINT8_C( 59), UINT8_C(206), UINT8_C(117), UINT8_C(110),
      UINT8_C(200), UINT8_C(176), UINT8_C(196), UINT8_C(184), UINT8_C(  6), UINT8_C(214), UINT8_C(238), UINT8_C(251),
      UINT8_C(236), UINT8_C(190), UINT8_C( 92), UINT8_C(196), UINT8_C(106), UINT8_C( 94), UINT8_C(239), UINT8_C( 46),
      UINT8_C(205), UINT8_C(211), UINT8_C( 45), UINT8_C(175), UINT8_C(132), UINT8_C( 25), UINT8_C(219), UINT8_C( 96),
      UINT8_C( 67), UINT8_C(171), UINT8_C(136), UINT8_C(126), UINT8_C(121), UINT8_C(253), UINT8_C(237), UINT8_C( 65),
      UINT8_C(174), UINT8_C(177), UINT8_C(249), UINT8_C(180), UINT8_C(135), UINT8_C(232), UINT8_C(175), UINT8_C(116),
      UINT8_C(166), UINT8_C( 11), UINT8_C( 56), UINT8_C( 16), UINT8_C(106), UINT8_C( 39), UINT8_C( 63), UINT8_C( 55),
      UINT8_C(250), UINT8_C(108), UINT8_C(230), UINT8_C(127), UINT8_C(133), UINT8_C(194), UINT8_C(223), UINT8_C(201),
      UINT8_C(109), UINT8_C(103), UINT8_C( 71), UINT8_C(230), UINT8_C(101), UINT8_C( 52), UINT8_C( 39), UINT8_C( 19),
      UINT8_C(230), UINT8_C( 33), UINT8_C(199), UINT8_C(109), UINT8_C(  9), UINT8_C(119), UINT8_C(225), UINT8_C(175),
      UINT8_C(130), UINT8_C( 25), UINT8_C(191), UINT8_C(236), UINT8_C( 65), UINT8_C(254), UINT8_C( 36), UINT8_C( 59),
      UINT8_C(107), UINT8_C( 10), UINT8_C(186), UINT8_C(240), UINT8_C(204), UINT8_C(153), UINT8_C(185), UINT8_C( 57),
      UINT8_C(  1), UINT8_C(  1), UINT8_C( 31), UINT8_C(102), UINT8_C( 53), UINT8_C( 71), UINT8_C(121), UINT8_C( 27),
      UINT8_C(104), UINT8_C( 64), UINT8_C(137), UINT8_C(113), UINT8_C(183), UINT8_C(106), UINT8_C( 32), UINT8_C( 58),
      UINT8_C(132), UINT8_C(223), UINT8_C( 38), UINT8_C(197), UINT8_C(222), UINT8_C( 74), UINT8_C(  0), UINT8_C( 73),
      UINT8_C( 85), UINT8_C(187), UINT8_C( 57), UINT8_C( 33), UINT8_C( 84), UINT8_C(243), UINT8_C( 91), UINT8_C( 85),
      UINT8_C(244), UINT8_C(122), UINT8_C(187), UINT8_C( 41), UINT8_C(193), UINT8_C( 52), UINT8_C( 69), UINT8_C( 41),
      UINT8_C(117), UINT8_C(206), UINT8_C(154), UINT8_C( 44), UINT8_C( 56), UINT8_C(186), UINT8_C(102), UINT8_C(188),
      UINT8_C(154), UINT8_C(141), UINT8_C(129), UINT8_C(120), UINT8_C(215), UINT8_C(130), UINT8_C(193), UINT8_C( 44),
      UINT8_C( 61), UINT8_C(250), UINT8_C( 78), UINT8_C(145), UINT8_C(237), UINT8_C(169), UINT8_C(231), UINT8_C(225),
      UINT8_C( 35), UINT8_C(162), UINT8_C( 11) };
  static const uint8_t b[] =
    { UINT8_C(180), UINT8_C( 46), UINT8_C(174), UINT8_C(  3), UINT8_C(122), UINT8_C(244), UINT8_C( 87), UINT8_C(253),
      UINT8_C(176), UINT8_C( 97), UINT8_C( 29), UINT8_C( 75), UINT8_C(168), UINT8_C(243), UINT8_C(140), UINT8_C( 62),
      UINT8_C( 61), UINT8_C(181), UINT8_C(130), UINT8_C( 53), UINT8_C(218), UINT8_C(237), UINT8_C(  6), UINT8_C(132),
      UINT8_C(233), UINT8_C( 77), UINT8_C(241), UINT8_C(114), UINT8_C( 41), UINT8_C(218), UINT8_C( 32), UINT8_C(221),
      UINT8_C(  8), UINT8_C(206), UINT8_C(225), UINT8_C(130), UINT8_C(194), UINT8_C( 56), UINT8_C(128), UINT8_C(114),
      UINT8_C(154), UINT8_C(157), UINT8_C(190), UINT8_C( 66), UINT8_C(144), UINT8_C( 74), UINT8_C(128), UINT8_C(206),
         UINT8_MAX, UINT8_C(  3), UINT8_C(  3), UINT8_C(218), UINT8_C(240), UINT8_C(  9), UINT8_C( 94), UINT8_C(218),
      UINT8_C( 86), UINT8_C( 79), UINT8_C( 76), UINT8_C(128), UINT8_C( 41), UINT8_C(108), UINT8_C( 93), UINT8_C( 50),
      UINT8_C( 59), UINT8_C( 62), UINT8_C(180), UINT8_C(253), UINT8_C(119), UINT8_C( 52), UINT8_C(112), UINT8_C( 17),
      UINT8_C(209), UINT8_C( 46), UINT8_C( 83), UINT8_C( 98), UINT8_C(120), UINT8_C(211), UINT8_C( 48), UINT8_C(119),
      UINT8_C(214), UINT8_C( 51), UINT8_C( 81), UINT8_C(199), UINT8_C( 60), UINT8_C(175), UINT8_C(161), UINT8_C(147),
         UINT8_MAX, UINT8_C(237), UINT8_C( 19), UINT8_C( 40), UINT8_C( 89), UINT8_C(112), UINT8_C( 90), UINT8_C(148),
      UINT8_C(175), UINT8_C( 15), UINT8_C(146), UINT8_C( 38), UINT8_C( 67), UINT8_C(  2), UINT8_C( 55), UINT8_C( 21),
      UINT8_C( 48), UINT8_C(138), UINT8_C(119), UINT8_C(168), UINT8_C( 93), UINT8_C(167), UINT8_C( 31), UINT8_C( 52),
      UINT8_C(218), UINT8_C(113), UINT8_C(251), UINT8_C( 22), UINT8_C( 32), UINT8_C(156), UINT8_C(169), UINT8_C( 31),
      UINT8_C(137), UINT8_C(188), UINT8_C( 72), UINT8_C(226), UINT8_C( 45), UINT8_C(162), UINT8_C(119), UINT8_C(220),
      UINT8_C(177), UINT8_C(  9), UINT8_C(  2), UINT8_C(245), UINT8_C( 11), UINT8_C( 57), UINT8_C( 10), UINT8_C( 59),
      UINT8_C(195), UINT8_C(129), UINT8_C(227), UINT8_C( 32), UINT8_C( 40), UINT8_C(  2), UINT8_C( 84), UINT8_C(  2),
      UINT8_C(115), UINT8_C( 79), UINT8_C( 24), UINT8_C(148), UINT8_C(235), UINT8_C(194), UINT8_C(179), UINT8_C(116),
      UINT8_C(126), UINT8_C(251), UINT8_C( 87), UINT8_C(171), UINT8_C(158), UINT8_C(206), UINT8_C(135), UINT8_C( 79),
      UINT8_C(215), UINT8_C(137), UINT8_C( 68), UINT8_C(226), UINT8_C(194), UINT8_C( 78), UINT8_C( 29), UINT8_C(133),
      UINT8_C(207), UINT8_C(  0), UINT8_C(166), UINT8_C(247), UINT8_C(  2), UINT8_C(250), UINT8_C(249), UINT8_C(118),
      UINT8_C( 74), UINT8_C( 18), UINT8_C( 10), UINT8_C( 53), UINT8_C(212), UINT8_C(189), UINT8_C(170), UINT8_C( 82),
      UINT8_C(185), UINT8_C(  1), UINT8_C(254), UINT8_C( 87), UINT8_C(207), UINT8_C(133), UINT8_C(166), UINT8_C(166),
      UINT8_C( 15), UINT8_C(235), UINT8_C(136), UINT8_C(209), UINT8_C( 57), UINT8_C(165), UINT8_C( 87), UINT8_C(  9),
      UINT8_C(165), UINT8_C(253), UINT8_C(  0), UINT8_C(167), UINT8_C(247), UINT8_C(250), UINT8_C( 29), UINT8_C( 65),
      UINT8_C( 12), UINT8_C( 39), UINT8_C(119), UINT8_C(224), UINT8_C(229), UINT8_C( 33), UINT8_C( 50), UINT8_C(158),
      UINT8_C( 34), UINT8_C( 48), UINT8_C(245), UINT8_C(241), UINT8_C(182), UINT8_C(155), UINT8_C(151), UINT8_C(197),
      UINT8_C(134), UINT8_C( 31), UINT8_C(150), UINT8_C(192), UINT8_C(196), UINT8_C(237), UINT8_C(201), UINT8_C(105),
      UINT8_C(234), UINT8_C(201), UINT8_C( 16), UINT8_C(226), UINT8_C(195), UINT8_C( 46), UINT8_C( 35), UINT8_C(207),
      UINT8_C( 85), UINT8_C(154), UINT8_C(175), UINT8_C( 58), UINT8_C(187), UINT8_C(226), UINT8_C(216), UINT8_C(221),
      UINT8_C( 18), UINT8_C(205), UINT8_C(206), UINT8_C(200), UINT8_C(105), UINT8_C(101), UINT8_C(141), UINT8_C(239),
      UINT8_C(132), UINT8_C( 36), UINT8_C(175), UINT8_C( 72), UINT8_C( 17), UINT8_C(120), UINT8_C(177), UINT8_C(252),
      UINT8_C( 66), UINT8_C(194), UINT8_C(222), UINT8_C(  5), UINT8_C(240), UINT8_C(  1), UINT8_C(213), UINT8_C( 69),
      UINT8_C(156), UINT8_C(132), UINT8_C(128), UINT8_C( 87), UINT8_C(102), UINT8_C( 88), UINT8_C( 53), UINT8_C(121),
      UINT8_C( 38), UINT8_C(  3), UINT8_C( 65), UINT8_C(143), UINT8_C(105), UINT8_C(207), UINT8_C(126), UINT8_C(237),
      UINT8_C(243), UINT8_C( 46), UINT8_C( 54), UINT8_C(  4), UINT8_C(166), UINT8_C(231), UINT8_C(  0), UINT8_C(232),
      UINT8_C(169), UINT8_C(222), UINT8_C(238), UINT8_C(153), UINT8_C(224), UINT8_C(195), UINT8_C(223), UINT8_C(124),
      UINT8_C( 71), UINT8_C( 95), UINT8_C(211), UINT8_C(174), UINT8_C(183), UINT8_C(  8), UINT8_C( 39), UINT8_C(221),
      UINT8_C( 12), UINT8_C(104), UINT8_C(108), UINT8_C(117), UINT8_C( 55), UINT8_C(235), UINT8_C( 98), UINT8_C( 42),
      UINT8_C( 25), UINT8_C(152), UINT8_C( 47), UINT8_C(191), UINT8_C(128), UINT8_C( 47), UINT8_C(168), UINT8_C( 41),
      UINT8_C( 14), UINT8_C(150), UINT8_C(195), UINT8_C(238), UINT8_C( 89), UINT8_C(162), UINT8_C(106), UINT8_C(160),
      UINT8_C(  1), UINT8_C( 61), UINT8_C( 78), UINT8_C(184), UINT8_C( 70), UINT8_C(117), UINT8_C(150), UINT8_C( 82),
      UINT8_C(222), UINT8_C(  2), UINT8_C(199), UINT8_C( 21), UINT8_C(237), UINT8_C( 41), UINT8_C( 64), UINT8_C(  6),
      UINT8_C(194), UINT8_C(111), UINT8_C(198), UINT8_C( 66), UINT8_C(158), UINT8_C(110), UINT8_C(107), UINT8_C(172),
      UINT8_C(  4), UINT8_C( 46), UINT8_C(154), UINT8_C( 93), UINT8_C(208), UINT8_C(  4), UINT8_C(253), UINT8_C(209),
      UINT8_C( 66), UINT8_C( 76), UINT8_C(138), UINT8_C(136), UINT8_C(193), UINT8_C( 32), UINT8_C(218), UINT8_C(159),
      UINT8_C( 34), UINT8_C(161), UINT8_C(181), UINT8_C( 16), UINT8_C(202), UINT8_C(245), UINT8_C( 22), UINT8_C(140),
      UINT8_C(100), UINT8_C(220), UINT8_C(206), UINT8_C(  2), UINT8_C( 74), UINT8_C( 58), UINT8_C(175), UINT8_C( 78),
      UINT8_C(104), UINT8_C( 73), UINT8_C(171), UINT8_C( 57), UINT8_C( 78), UINT8_C(169), UINT8_C( 10), UINT8_C(144),
      UINT8_C(245), UINT8_C(148), UINT8_C( 24), UINT8_C(182), UINT8_C(180), UINT8_C(242), UINT8_C( 86), UINT8_C(215),
      UINT8_C(147), UINT8_C( 11), UINT8_C(231), UINT8_C( 93), UINT8_C(  0), UINT8_C(253), UINT8_C(234), UINT8_C(100),
      UINT8_C(218), UINT8_C(184), UINT8_C(102), UINT8_C( 36), UINT8_C(242), UINT8_C( 21), UINT8_C(115), UINT8_C( 91),
      UINT8_C( 95), UINT8_C( 30), UINT8_C(148), UINT8_C(173), UINT8_C(199), UINT8_C(158), UINT8_C( 61), UINT8_C(188),
      UINT8_C( 51), UINT8_C( 85), UINT8_C(115), UINT8_C(231), UINT8_C( 71), UINT8_C(201), UINT8_C(190), UINT8_C(218),
      UINT8_C(212), UINT8_C(165), UINT8_C( 55), UINT8_C(212), UINT8_C(163), UINT8_C( 33), UINT8_C( 56), UINT8_C(125),
      UINT8_C(218), UINT8_C(158), UINT8_C(161), UINT8_C(204), UINT8_C(180), UINT8_C( 20), UINT8_C( 39), UINT8_C( 19),
      UINT8_C( 51), UINT8_C(187), UINT8_C(192), UINT8_C(250), UINT8_C( 90), UINT8_C(253), UINT8_C(183), UINT8_C(141),
      UINT8_C( 82), UINT8_C( 42), UINT8_C(116), UINT8_C(153), UINT8_C(243), UINT8_C( 51), UINT8_C(115), UINT8_C(199),
      UINT8_C(216), UINT8_C(170), UINT8_C(155), UINT8_C(123), UINT8_C(204), UINT8_C(211), UINT8_C(248), UINT8_C(166),
      UINT8_C(113), UINT8_C(154), UINT8_C(114), UINT8_C( 37), UINT8_C(174), UINT8_C(154), UINT8_C( 56), UINT8_C(225),
      UINT8_C( 85), UINT8_C(248), UINT8_C(220), UINT8_C(175), UINT8_C(245), UINT8_C(147), UINT8_C( 60), UINT8_C( 71),
      UINT8_C(189), UINT8_C(177), UINT8_C(224), UINT8_C(176), UINT8_C(228), UINT8_C( 83), UINT8_C(119), UINT8_C(188),
      UINT8_C(254), UINT8_C( 18), UINT8_C( 56), UINT8_C(202), UINT8_C(229), UINT8_C( 48), UINT8_C(112), UINT8_C( 86),
      UINT8_C(202), UINT8_C(226), UINT8_C(124) };
  static const uint8_t e[] =
    { UINT8_C( 53), UINT8_C(128), UINT8_C(138), UINT8_C(  1), UINT8_C( 64), UINT8_C( 21), UINT8_C( 96), UINT8_C(153),
      UINT8_C(160), UINT8_C( 30), UINT8_C(200), UINT8_C(105), UINT8_C(128), UINT8_C(106), UINT8_C( 69), UINT8_C( 14),
      UINT8_C( 49), UINT8_C( 20), UINT8_C(128), UINT8_C(  1), UINT8_C( 20), UINT8_C( 97), UINT8_C(148), UINT8_C(  0),
      UINT8_C(105), UINT8_C( 80), UINT8_C(241), UINT8_C( 80), UINT8_C(183), UINT8_C(152), UINT8_C(222), UINT8_C(204),
      UINT8_C( 56), UINT8_C(184), UINT8_C( 85), UINT8_C(120), UINT8_C(192), UINT8_C(181), UINT8_C(  0), UINT8_C(112),
      UINT8_C(146), UINT8_C(219), UINT8_C(152), UINT8_C( 64), UINT8_C( 69), UINT8_C( 30), UINT8_C( 99), UINT8_C( 70),
      UINT8_C( 52), UINT8_C(  0), UINT8_C(  0), UINT8_C( 72), UINT8_C( 69), UINT8_C( 20), UINT8_C( 88), UINT8_C(144),
      UINT8_C(100), UINT8_C( 71), UINT8_C( 12), UINT8_C(  0), UINT8_C( 15), UINT8_C(104), UINT8_C(  5), UINT8_C( 71),
      UINT8_C( 34), UINT8_C( 28), UINT8_C(191), UINT8_C(111), UINT8_C( 17), UINT8_C(210), UINT8_C( 80), UINT8_C(  0),
      UINT8_C(173), UINT8_C(185), UINT8_C( 57), UINT8_C(243), UINT8_C( 80), UINT8_C(144), UINT8_C(106), UINT8_C( 12),
      UINT8_C(128), UINT8_C( 34), UINT8_C( 84), UINT8_C(198), UINT8_C(254), UINT8_C(173), UINT8_C(122), UINT8_C(  2),
      UINT8_C(  4), UINT8_C(133), UINT8_C(125), UINT8_C( 20), UINT8_C(113), UINT8_C(132), UINT8_C( 91), UINT8_C( 20),
      UINT8_C(160), UINT8_C( 11), UINT8_C(131), UINT8_C( 32), UINT8_C( 65), UINT8_C( 99), UINT8_C( 21), UINT8_C(155),
      UINT8_C( 16), UINT8_C( 14), UINT8_C(142), UINT8_C(243), UINT8_C(170), UINT8_C(160),    UINT8_MAX, UINT8_C( 32),
      UINT8_C(194), UINT8_C( 80), UINT8_C(241), UINT8_C(  0), UINT8_C(  0), UINT8_C(107), UINT8_C( 66), UINT8_C(  5),
      UINT8_C(128), UINT8_C(188), UINT8_C(  8), UINT8_C( 96), UINT8_C(  1), UINT8_C(117), UINT8_C(112), UINT8_C(  0),
      UINT8_C(144), UINT8_C(  9), UINT8_C(  0), UINT8_C(117), UINT8_C( 10), UINT8_C( 41), UINT8_C( 24), UINT8_C(122),
      UINT8_C(195), UINT8_C(128), UINT8_C( 98), UINT8_C(161), UINT8_C(158), UINT8_C(109), UINT8_C(204), UINT8_C(  0),
      UINT8_C( 65), UINT8_C( 13), UINT8_C(  0), UINT8_C(194), UINT8_C( 41), UINT8_C(162), UINT8_C(200), UINT8_C( 16),
      UINT8_C( 97), UINT8_C(225), UINT8_C(127), UINT8_C(164), UINT8_C( 86), UINT8_C(198), UINT8_C(135), UINT8_C(230),
      UINT8_C(211), UINT8_C(137), UINT8_C( 68), UINT8_C( 64), UINT8_C(196), UINT8_C(124), UINT8_C(204), UINT8_C(187),
      UINT8_C(  3), UINT8_C(  0), UINT8_C( 93), UINT8_C(193), UINT8_C(  2), UINT8_C( 41), UINT8_C( 64), UINT8_C(105),
      UINT8_C( 66), UINT8_C(  2), UINT8_C( 10), UINT8_C( 16), UINT8_C( 68), UINT8_C(177), UINT8_C( 43), UINT8_C(  2),
      UINT8_C(145), UINT8_C(  1), UINT8_C( 74), UINT8_C(  3), UINT8_C(162), UINT8_C(  0), UINT8_C(  2), UINT8_C(132),
      UINT8_C(238), UINT8_C( 98), UINT8_C(231), UINT8_C(178), UINT8_C( 48), UINT8_C(179), UINT8_C( 70), UINT8_C(  1),
      UINT8_C(237), UINT8_C(201), UINT8_C(215), UINT8_C(132), UINT8_C(244), UINT8_C( 25), UINT8_C(253), UINT8_C( 65),
      UINT8_C(187), UINT8_C( 41), UINT8_C( 99), UINT8_C(  0), UINT8_C(  4), UINT8_C(  1), UINT8_C( 34), UINT8_C(144),
      UINT8_C(194), UINT8_C( 48), UINT8_C( 29), UINT8_C( 96), UINT8_C(  4), UINT8_C( 47), UINT8_C(146), UINT8_C(192),
      UINT8_C(132), UINT8_C(225), UINT8_C(165), UINT8_C(128), UINT8_C(132), UINT8_C(  1), UINT8_C(173), UINT8_C(  1),
      UINT8_C(202), UINT8_C(128), UINT8_C( 16), UINT8_C(194), UINT8_C(129), UINT8_C(  2), UINT8_C(174), UINT8_C( 72),
      UINT8_C( 20), UINT8_C(152), UINT8_C(  9), UINT8_C( 24), UINT8_C(176), UINT8_C(  0), UINT8_C( 74), UINT8_C(114),
      UINT8_C(242), UINT8_C( 69), UINT8_C(198), UINT8_C(192), UINT8_C(  0), UINT8_C( 65), UINT8_C(137), UINT8_C( 43),
      UINT8_C(128), UINT8_C(142), UINT8_C(210), UINT8_C( 70), UINT8_C(161), UINT8_C(127), UINT8_C(199), UINT8_C(124),
      UINT8_C(  2), UINT8_C(192), UINT8_C( 80), UINT8_C(  0), UINT8_C(239), UINT8_C(  1), UINT8_C(209), UINT8_C( 43),
      UINT8_C(152), UINT8_C(  0), UINT8_C(128), UINT8_C( 65), UINT8_C( 82), UINT8_C(206), UINT8_C( 52), UINT8_C( 64),
      UINT8_C( 36), UINT8_C(  3), UINT8_C(  0), UINT8_C(139), UINT8_C( 96), UINT8_C(  3), UINT8_C(  6), UINT8_C( 22),
      UINT8_C(177), UINT8_C(216), UINT8_C( 20), UINT8_C( 82), UINT8_C( 88), UINT8_C( 35), UINT8_C(209), UINT8_C( 91),
      UINT8_C(169), UINT8_C(  2), UINT8_C(252), UINT8_C(137), UINT8_C( 32), UINT8_C(245), UINT8_C( 26), UINT8_C( 56),
      UINT8_C( 71), UINT8_C( 30), UINT8_C(  5), UINT8_C(153), UINT8_C(108), UINT8_C(193), UINT8_C(  5), UINT8_C(129),
      UINT8_C( 84), UINT8_C(  0), UINT8_C(108), UINT8_C( 48), UINT8_C( 59), UINT8_C(114), UINT8_C( 66), UINT8_C( 40),
      UINT8_C( 75), UINT8_C(  8), UINT8_C( 63), UINT8_C(163), UINT8_C(  0), UINT8_C( 16), UINT8_C(254), UINT8_C( 76),
      UINT8_C(  2), UINT8_C(146), UINT8_C( 59), UINT8_C( 70), UINT8_C( 73), UINT8_C( 86), UINT8_C( 17), UINT8_C( 54),
      UINT8_C(244), UINT8_C( 22), UINT8_C( 78), UINT8_C( 97), UINT8_C(215), UINT8_C(172), UINT8_C(  2), UINT8_C(  2),
      UINT8_C(196), UINT8_C(111), UINT8_C(227),    UINT8_MAX, UINT8_C(225), UINT8_C(177), UINT8_C( 64), UINT8_C(  4),
      UINT8_C(194), UINT8_C( 42), UINT8_C(198), UINT8_C( 40), UINT8_C( 59), UINT8_C(206), UINT8_C( 97), UINT8_C(110),
      UINT8_C(  0), UINT8_C( 32), UINT8_C(128), UINT8_C(184), UINT8_C(  0), UINT8_C(  4), UINT8_C(236), UINT8_C(209),
      UINT8_C(236), UINT8_C(190), UINT8_C(  8), UINT8_C(128), UINT8_C( 64), UINT8_C(  0), UINT8_C(239), UINT8_C( 14),
      UINT8_C(  0), UINT8_C(211), UINT8_C( 37), UINT8_C(175), UINT8_C(128), UINT8_C( 17), UINT8_C(219), UINT8_C( 96),
      UINT8_C( 64), UINT8_C(171), UINT8_C(136), UINT8_C(126), UINT8_C(121), UINT8_C(253), UINT8_C(173), UINT8_C( 65),
      UINT8_C(174), UINT8_C(177), UINT8_C(169), UINT8_C( 48), UINT8_C(135), UINT8_C(168), UINT8_C( 10), UINT8_C(116),
      UINT8_C(166), UINT8_C(  0), UINT8_C( 56), UINT8_C( 16), UINT8_C( 32), UINT8_C( 39), UINT8_C( 22), UINT8_C( 23),
      UINT8_C(146), UINT8_C(  8), UINT8_C(230), UINT8_C(127), UINT8_C(  0), UINT8_C(194), UINT8_C(202), UINT8_C(201),
      UINT8_C(109), UINT8_C( 32), UINT8_C( 70), UINT8_C( 36), UINT8_C(101), UINT8_C( 52), UINT8_C( 35), UINT8_C( 19),
      UINT8_C( 70), UINT8_C( 33), UINT8_C(199), UINT8_C( 45), UINT8_C(  1), UINT8_C( 22), UINT8_C(225), UINT8_C(172),
      UINT8_C(  2), UINT8_C( 25), UINT8_C( 51), UINT8_C(236), UINT8_C( 65), UINT8_C(254), UINT8_C( 36), UINT8_C( 26),
      UINT8_C(107), UINT8_C(  0), UINT8_C(186), UINT8_C(208), UINT8_C(128), UINT8_C(  1), UINT8_C(185), UINT8_C( 57),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C( 68), UINT8_C( 53), UINT8_C( 71), UINT8_C( 33), UINT8_C( 19),
      UINT8_C( 32), UINT8_C(  0), UINT8_C(128), UINT8_C(113), UINT8_C( 18), UINT8_C(106), UINT8_C( 32), UINT8_C( 58),
      UINT8_C(  0), UINT8_C( 10), UINT8_C( 36), UINT8_C(197), UINT8_C(222), UINT8_C( 74), UINT8_C(  0), UINT8_C( 73),
      UINT8_C( 85), UINT8_C(187), UINT8_C( 57), UINT8_C( 33), UINT8_C( 84), UINT8_C(243), UINT8_C( 88), UINT8_C(  4),
      UINT8_C(244), UINT8_C( 26), UINT8_C( 50), UINT8_C( 41), UINT8_C(128), UINT8_C( 52), UINT8_C( 69), UINT8_C( 41),
      UINT8_C(117), UINT8_C(206), UINT8_C(152), UINT8_C( 44), UINT8_C( 56), UINT8_C(146), UINT8_C( 36), UINT8_C(  4),
      UINT8_C(152), UINT8_C(141), UINT8_C(129), UINT8_C(120), UINT8_C(196), UINT8_C(130), UINT8_C( 65), UINT8_C( 44),
      UINT8_C( 60), UINT8_C( 18), UINT8_C(  8), UINT8_C(128), UINT8_C(237), UINT8_C( 32), UINT8_C( 96), UINT8_C(225),
      UINT8_C(  2), UINT8_C(162), UINT8_C(  8) };

  static uint8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t
      rv,
      av = simde_svld1_u8(pg, &(a[i])),
      bv = simde_svld1_u8(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(INT8_C(0)));
    rv = simde_svand_u8_m(pv, av, bv);

    simde_svst1_u8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vu8(len, e, r);

  return 0;
#else
  int8_t p[1024];
  uint8_t a[1024], b[1024], e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_u8(pg, &(a[i]));
    bv = simde_svld1_u8(pg, &(b[i]));

    ev = simde_svand_u8_m(pv, av, bv);

    simde_svst1_u8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_u16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) };
  static const uint16_t a[] =
    { UINT16_C(48100), UINT16_C(51403), UINT16_C(42270), UINT16_C(15498), UINT16_C(29479), UINT16_C(48081), UINT16_C( 6594), UINT16_C(23381),
      UINT16_C(21916), UINT16_C( 6169), UINT16_C(36167), UINT16_C(20144), UINT16_C(57458), UINT16_C(19199), UINT16_C(25257), UINT16_C(36158),
      UINT16_C( 2333), UINT16_C(15189), UINT16_C(57519), UINT16_C(54904), UINT16_C(18771), UINT16_C( 5521), UINT16_C(59235), UINT16_C(65392),
      UINT16_C(35132), UINT16_C(33559), UINT16_C(50966), UINT16_C(35025), UINT16_C(53415), UINT16_C(20690), UINT16_C( 4146), UINT16_C(20446),
      UINT16_C(13082), UINT16_C(51594), UINT16_C(  531), UINT16_C(26527), UINT16_C(12620), UINT16_C(44924), UINT16_C(60696), UINT16_C(21678),
      UINT16_C(50550), UINT16_C(36311), UINT16_C(43149), UINT16_C(13333), UINT16_C(59512), UINT16_C(43653), UINT16_C(25592), UINT16_C( 4857),
      UINT16_C(33686), UINT16_C(43739), UINT16_C(31622), UINT16_C(53777), UINT16_C(36268), UINT16_C(50305), UINT16_C(12154), UINT16_C(61720),
      UINT16_C(61428), UINT16_C(33150), UINT16_C(37783), UINT16_C( 4022), UINT16_C(15227), UINT16_C(29881), UINT16_C(45726), UINT16_C(13446),
      UINT16_C(25141), UINT16_C(48094), UINT16_C(61405), UINT16_C(35213), UINT16_C( 3709), UINT16_C(63309), UINT16_C(25917), UINT16_C(13032),
      UINT16_C(26196), UINT16_C(60339), UINT16_C(27130), UINT16_C(30202), UINT16_C(45988), UINT16_C(17129), UINT16_C(28773), UINT16_C(39543),
      UINT16_C(21970), UINT16_C(44886), UINT16_C(58181), UINT16_C(49720), UINT16_C(34290), UINT16_C(12217), UINT16_C(41706), UINT16_C(15969),
      UINT16_C( 5384), UINT16_C(  553), UINT16_C( 9086), UINT16_C( 9080), UINT16_C(25046), UINT16_C(15205), UINT16_C(56529), UINT16_C(41941),
      UINT16_C(11058), UINT16_C(30546), UINT16_C(35343), UINT16_C(  313), UINT16_C(61967), UINT16_C(63792), UINT16_C(37524), UINT16_C(40247),
      UINT16_C(24743), UINT16_C( 9631), UINT16_C( 6019), UINT16_C(22856), UINT16_C(44665), UINT16_C(19092), UINT16_C(27274), UINT16_C(48366),
      UINT16_C(16533), UINT16_C(42035), UINT16_C(27851), UINT16_C(55973), UINT16_C(54879), UINT16_C(62420), UINT16_C( 2920), UINT16_C( 3984),
      UINT16_C(12396), UINT16_C(61236), UINT16_C(32071), UINT16_C(49225), UINT16_C(56619), UINT16_C(46347), UINT16_C(63815), UINT16_C(56690),
      UINT16_C(42297), UINT16_C( 1153), UINT16_C(10002), UINT16_C(29151), UINT16_C(46077), UINT16_C(25956), UINT16_C(62910), UINT16_C(10868),
      UINT16_C(43045), UINT16_C(27674), UINT16_C(25381), UINT16_C(20525), UINT16_C(14400), UINT16_C(34822), UINT16_C(30769), UINT16_C(27237),
      UINT16_C(58909), UINT16_C(12143), UINT16_C(19981), UINT16_C( 2720), UINT16_C( 1281), UINT16_C(49007), UINT16_C(58362), UINT16_C( 8170),
      UINT16_C( 1164), UINT16_C(45451), UINT16_C(47207), UINT16_C(42754), UINT16_C( 2288), UINT16_C( 8495), UINT16_C(38016), UINT16_C(40332),
      UINT16_C(64379), UINT16_C(35021), UINT16_C(27977), UINT16_C(19091), UINT16_C(  626), UINT16_C(27657), UINT16_C(62438), UINT16_C(29323),
      UINT16_C( 6135), UINT16_C(24099), UINT16_C( 9679), UINT16_C(49158), UINT16_C(13613), UINT16_C(44513), UINT16_C(28106), UINT16_C(17739),
      UINT16_C( 6248), UINT16_C(45517), UINT16_C(24709), UINT16_C(63739), UINT16_C( 1379), UINT16_C(18788), UINT16_C(61688), UINT16_C(61627),
      UINT16_C(56839), UINT16_C(54862), UINT16_C(21508), UINT16_C(12694), UINT16_C(30858), UINT16_C(21727), UINT16_C(10981), UINT16_C(20121),
      UINT16_C(26178), UINT16_C(51199), UINT16_C(64455), UINT16_C(10943), UINT16_C( 9216), UINT16_C(63603), UINT16_C(11796), UINT16_C( 7144),
      UINT16_C(14092), UINT16_C( 4337), UINT16_C(34955), UINT16_C( 5442), UINT16_C( 8448), UINT16_C(58729), UINT16_C(  587), UINT16_C(36147),
      UINT16_C(13161), UINT16_C(12372), UINT16_C( 5166), UINT16_C(11866), UINT16_C(52536), UINT16_C(19494), UINT16_C( 4091), UINT16_C( 1895),
      UINT16_C(22598), UINT16_C(53528), UINT16_C(23264), UINT16_C(57575), UINT16_C(20603), UINT16_C(50886), UINT16_C(63827), UINT16_C(48211),
      UINT16_C(42796), UINT16_C(23276), UINT16_C(18107), UINT16_C(62344), UINT16_C(44819), UINT16_C( 3647), UINT16_C(42686), UINT16_C( 1045),
      UINT16_C(11775), UINT16_C(57301), UINT16_C(48263), UINT16_C(  704), UINT16_C(34317), UINT16_C(24776), UINT16_C( 7039), UINT16_C(44060),
      UINT16_C( 2243), UINT16_C(32262), UINT16_C(36686), UINT16_C(24946), UINT16_C(45374), UINT16_C(64623), UINT16_C(33880), UINT16_C(22272),
      UINT16_C(54706), UINT16_C(14646), UINT16_C(63122), UINT16_C(40764), UINT16_C( 1148), UINT16_C(64767), UINT16_C( 6944), UINT16_C(58280),
      UINT16_C(44579), UINT16_C(29025), UINT16_C(54077), UINT16_C(31698), UINT16_C(16773), UINT16_C(56695), UINT16_C(30661), UINT16_C(30516),
      UINT16_C(27213), UINT16_C(57265), UINT16_C(60769), UINT16_C(56702), UINT16_C(32241), UINT16_C( 4569), UINT16_C(33176), UINT16_C(48116),
      UINT16_C(22064), UINT16_C(27948), UINT16_C(65065), UINT16_C(44777), UINT16_C(24639), UINT16_C( 1163), UINT16_C(49112), UINT16_C( 9596),
      UINT16_C(11562), UINT16_C(35588), UINT16_C(33306), UINT16_C( 2920), UINT16_C(17151), UINT16_C(38685), UINT16_C( 4547), UINT16_C(62290),
      UINT16_C(32359), UINT16_C(37217), UINT16_C(19068), UINT16_C(47935), UINT16_C(52138), UINT16_C(33471), UINT16_C(15242), UINT16_C(46247),
      UINT16_C(43880), UINT16_C(33343), UINT16_C(43053), UINT16_C(11406), UINT16_C(44010), UINT16_C(44483), UINT16_C( 5564), UINT16_C( 9377),
      UINT16_C(  659), UINT16_C( 4021), UINT16_C(62540), UINT16_C(63178), UINT16_C(35519), UINT16_C(19065), UINT16_C( 8389), UINT16_C(12030),
      UINT16_C(16076), UINT16_C(63920), UINT16_C(16102), UINT16_C(53286), UINT16_C(59881), UINT16_C(42621), UINT16_C( 7935), UINT16_C(37578),
      UINT16_C(32544), UINT16_C(27810), UINT16_C(27763), UINT16_C(13155), UINT16_C(56566), UINT16_C(48253), UINT16_C(31740), UINT16_C(51434),
      UINT16_C(39609), UINT16_C(40898), UINT16_C(59609), UINT16_C(49775), UINT16_C(60881), UINT16_C(53352), UINT16_C(12811), UINT16_C(11363),
      UINT16_C( 1457), UINT16_C( 9624), UINT16_C(64369), UINT16_C(26712), UINT16_C(54743), UINT16_C(54308), UINT16_C( 3664), UINT16_C( 2716),
      UINT16_C(24232), UINT16_C(33193), UINT16_C( 6470), UINT16_C( 6212), UINT16_C(44038), UINT16_C( 4584), UINT16_C(19423), UINT16_C(36925),
      UINT16_C(54864), UINT16_C(49845), UINT16_C( 3537), UINT16_C(43306), UINT16_C(20194), UINT16_C(13181), UINT16_C( 6492), UINT16_C( 1085),
      UINT16_C(59000), UINT16_C(48774), UINT16_C(51967), UINT16_C( 1494), UINT16_C(49014), UINT16_C(21783), UINT16_C(21514), UINT16_C(23526),
      UINT16_C(39722), UINT16_C(64541), UINT16_C(18345), UINT16_C(35749), UINT16_C( 8853), UINT16_C(61886), UINT16_C(64315), UINT16_C(46069),
      UINT16_C(31714), UINT16_C(57714), UINT16_C(18501), UINT16_C(48359), UINT16_C(65031), UINT16_C( 4625), UINT16_C(63314), UINT16_C(32109),
      UINT16_C(35475), UINT16_C(15481), UINT16_C( 7889), UINT16_C(26311), UINT16_C(34368), UINT16_C(31575), UINT16_C(19585), UINT16_C(25391),
      UINT16_C(41416), UINT16_C( 3397), UINT16_C(11497), UINT16_C(61897), UINT16_C(56106), UINT16_C(31747), UINT16_C(28882), UINT16_C(26105),
      UINT16_C(29434), UINT16_C(52129), UINT16_C(27024), UINT16_C(53297), UINT16_C(35055), UINT16_C(28748), UINT16_C(31700), UINT16_C(40148),
      UINT16_C( 6428), UINT16_C( 1450), UINT16_C(29509), UINT16_C(28662), UINT16_C(63822), UINT16_C( 8683), UINT16_C(58729), UINT16_C(25478),
      UINT16_C(10327), UINT16_C(59438), UINT16_C(24465), UINT16_C(32952), UINT16_C( 1255), UINT16_C(48368), UINT16_C(50303), UINT16_C(39768),
      UINT16_C(  733), UINT16_C( 8865), UINT16_C(38774), UINT16_C(50321), UINT16_C(32145), UINT16_C(64229), UINT16_C(27746), UINT16_C(47454),
      UINT16_C(35988), UINT16_C( 9633), UINT16_C(23276), UINT16_C(54181), UINT16_C(38238), UINT16_C(56975), UINT16_C(59482), UINT16_C(14201),
      UINT16_C( 6890), UINT16_C(24666), UINT16_C(60338), UINT16_C(17189), UINT16_C( 2664), UINT16_C(51773), UINT16_C(39798), UINT16_C( 2692),
      UINT16_C( 9512), UINT16_C( 5167), UINT16_C(54399), UINT16_C(57063), UINT16_C(30570), UINT16_C(50364), UINT16_C(13663), UINT16_C(18939),
      UINT16_C(21840), UINT16_C(  682), UINT16_C(53057), UINT16_C(43333), UINT16_C(33497), UINT16_C(20596), UINT16_C(63518), UINT16_C(18010),
      UINT16_C(35357), UINT16_C(40282), UINT16_C(16734), UINT16_C(51323), UINT16_C(14264), UINT16_C( 6028), UINT16_C(34924), UINT16_C(48225),
      UINT16_C( 3037), UINT16_C( 7870), UINT16_C(  986), UINT16_C(46024), UINT16_C(15494), UINT16_C(41987), UINT16_C(24116), UINT16_C(20970),
      UINT16_C(17640), UINT16_C(18158), UINT16_C(27013), UINT16_C(15887), UINT16_C(39840), UINT16_C( 3413), UINT16_C(46627), UINT16_C(  457),
      UINT16_C(35009), UINT16_C(39711), UINT16_C(59275), UINT16_C( 4431), UINT16_C(21027) };
  static const uint16_t b[] =
    { UINT16_C(55664), UINT16_C(28990), UINT16_C(58823), UINT16_C(20755), UINT16_C(49634), UINT16_C(38398), UINT16_C(44089), UINT16_C(14601),
      UINT16_C( 6521), UINT16_C(11973), UINT16_C(25208), UINT16_C(10759), UINT16_C(14260), UINT16_C(42636), UINT16_C(34320), UINT16_C(32892),
      UINT16_C(47712), UINT16_C(10226), UINT16_C( 1440), UINT16_C(33400), UINT16_C(30406), UINT16_C(   23), UINT16_C( 8226), UINT16_C(39993),
      UINT16_C(65082), UINT16_C(45770), UINT16_C(53600), UINT16_C( 5596), UINT16_C(26632), UINT16_C( 6331), UINT16_C(14319), UINT16_C(20377),
      UINT16_C(35826), UINT16_C(37494), UINT16_C(61328), UINT16_C(22036), UINT16_C(11109), UINT16_C(34902), UINT16_C(36939), UINT16_C(34084),
      UINT16_C(61070), UINT16_C(61240), UINT16_C( 5312), UINT16_C(51204), UINT16_C(49021), UINT16_C(27873), UINT16_C(31479), UINT16_C(59835),
      UINT16_C(12549), UINT16_C(38267), UINT16_C(36640), UINT16_C(34539), UINT16_C(17082), UINT16_C( 1294), UINT16_C(13010), UINT16_C(24715),
      UINT16_C(49952), UINT16_C(57423), UINT16_C(21463), UINT16_C(21673), UINT16_C(35347), UINT16_C( 2752), UINT16_C(31492), UINT16_C( 2547),
      UINT16_C(28333), UINT16_C(52638), UINT16_C(35325), UINT16_C(46931), UINT16_C(25035), UINT16_C(40380), UINT16_C(18323), UINT16_C(46334),
      UINT16_C(19722), UINT16_C(58004), UINT16_C(15777), UINT16_C(46134), UINT16_C(63431), UINT16_C(52158), UINT16_C(45426), UINT16_C( 8148),
      UINT16_C(29215), UINT16_C( 7405), UINT16_C(16636), UINT16_C(51155), UINT16_C(36770), UINT16_C(13669), UINT16_C(25559), UINT16_C(57833),
      UINT16_C(32432), UINT16_C(20931), UINT16_C(64187), UINT16_C(33541), UINT16_C(50161), UINT16_C(25422), UINT16_C( 9076), UINT16_C(37763),
      UINT16_C(28821), UINT16_C(37295), UINT16_C(33456), UINT16_C(21081), UINT16_C(48658), UINT16_C(59784), UINT16_C(28961), UINT16_C(53706),
      UINT16_C(36591), UINT16_C(43811), UINT16_C(10376), UINT16_C(31022), UINT16_C(31980), UINT16_C(24796), UINT16_C(24479), UINT16_C(13812),
      UINT16_C(41935), UINT16_C(32966), UINT16_C( 7974), UINT16_C(14546), UINT16_C(23261), UINT16_C(65057), UINT16_C(60364), UINT16_C(48080),
      UINT16_C(62329), UINT16_C(  358), UINT16_C(37915), UINT16_C( 1914), UINT16_C(22289), UINT16_C(45160), UINT16_C(23734), UINT16_C(34533),
      UINT16_C(44287), UINT16_C( 9478), UINT16_C(55499), UINT16_C(43357), UINT16_C(32307), UINT16_C(65447), UINT16_C(30570), UINT16_C(58298),
      UINT16_C( 8554), UINT16_C(34533), UINT16_C(24501), UINT16_C(50829), UINT16_C(62902), UINT16_C(28023), UINT16_C(23633), UINT16_C(20979),
      UINT16_C(63752), UINT16_C(54390), UINT16_C(54481), UINT16_C( 1149), UINT16_C( 9298), UINT16_C(48131), UINT16_C(48796), UINT16_C( 1696),
      UINT16_C(34271), UINT16_C(38028), UINT16_C( 6884), UINT16_C(39771), UINT16_C(53775), UINT16_C(24840), UINT16_C(64302), UINT16_C(14258),
      UINT16_C(10484), UINT16_C(50443), UINT16_C(35068), UINT16_C(20426), UINT16_C(52652), UINT16_C(18443), UINT16_C(43915), UINT16_C(27215),
      UINT16_C(56112), UINT16_C( 5631), UINT16_C(23285), UINT16_C( 1456), UINT16_C(47148), UINT16_C(23142), UINT16_C( 6323), UINT16_C(42897),
      UINT16_C(40000), UINT16_C(15724), UINT16_C(13860), UINT16_C(53644), UINT16_C(38660), UINT16_C(36633), UINT16_C(26691), UINT16_C(29690),
      UINT16_C(63812), UINT16_C(14728), UINT16_C(14419), UINT16_C(32574), UINT16_C(42224), UINT16_C(41945), UINT16_C(27580), UINT16_C(64842),
      UINT16_C(46855), UINT16_C(11322), UINT16_C(50925), UINT16_C(61949), UINT16_C( 5725), UINT16_C(41089), UINT16_C(31615), UINT16_C(49940),
      UINT16_C(40052), UINT16_C(51196), UINT16_C(15317), UINT16_C(50502), UINT16_C( 8159), UINT16_C(40041), UINT16_C(45962), UINT16_C(37529),
      UINT16_C(54122), UINT16_C(22718), UINT16_C(48025), UINT16_C(63049), UINT16_C(51921), UINT16_C(20631), UINT16_C(43845), UINT16_C(47379),
      UINT16_C( 4167), UINT16_C( 7296), UINT16_C(50763), UINT16_C(10978), UINT16_C(19430), UINT16_C(28870), UINT16_C(24574), UINT16_C(26882),
      UINT16_C(49202), UINT16_C(52161), UINT16_C( 2683), UINT16_C(19906), UINT16_C(22997), UINT16_C( 6813), UINT16_C(45316), UINT16_C(19412),
      UINT16_C(21697), UINT16_C( 3176), UINT16_C(18971), UINT16_C(  310), UINT16_C(64917), UINT16_C(37745), UINT16_C(29788), UINT16_C(36860),
      UINT16_C(48436), UINT16_C(45146), UINT16_C( 7368), UINT16_C(40445), UINT16_C(39541), UINT16_C(31159), UINT16_C(35659), UINT16_C( 3269),
      UINT16_C(11744), UINT16_C(64280), UINT16_C(20343), UINT16_C( 3324), UINT16_C(27980), UINT16_C(43167), UINT16_C(40161), UINT16_C( 5687),
      UINT16_C(37465), UINT16_C( 8646), UINT16_C(50094), UINT16_C( 9406), UINT16_C(30301), UINT16_C(43421), UINT16_C(25089), UINT16_C(57781),
      UINT16_C(52879), UINT16_C( 1756), UINT16_C(55325), UINT16_C(26898), UINT16_C(45638), UINT16_C(10001), UINT16_C(18766), UINT16_C(42813),
      UINT16_C(  987), UINT16_C(35273), UINT16_C(34758), UINT16_C( 9389), UINT16_C(19453), UINT16_C(65485), UINT16_C(33453), UINT16_C(15840),
      UINT16_C(48464), UINT16_C(27971), UINT16_C(22165), UINT16_C(56278), UINT16_C(59400), UINT16_C(22019), UINT16_C(16433), UINT16_C( 3325),
      UINT16_C(50756), UINT16_C( 2709), UINT16_C(17230), UINT16_C(19246), UINT16_C(64398), UINT16_C(15178), UINT16_C(11134), UINT16_C(52856),
      UINT16_C(48360), UINT16_C(32060), UINT16_C( 4626), UINT16_C( 6745), UINT16_C(23802), UINT16_C(11120), UINT16_C(28060), UINT16_C(57399),
      UINT16_C(52532), UINT16_C(33515), UINT16_C( 6416), UINT16_C(40653), UINT16_C( 6165), UINT16_C(37849), UINT16_C(21059), UINT16_C(11105),
      UINT16_C(40206), UINT16_C( 8360), UINT16_C(  432), UINT16_C(43578), UINT16_C(43613), UINT16_C(64214), UINT16_C( 3351), UINT16_C(19418),
      UINT16_C(50650), UINT16_C(60109), UINT16_C(39903), UINT16_C(62600), UINT16_C(25267), UINT16_C(63111), UINT16_C(59572), UINT16_C(49697),
      UINT16_C(51590), UINT16_C(14050), UINT16_C( 7371), UINT16_C(10464), UINT16_C(46790), UINT16_C(56610), UINT16_C(64964), UINT16_C(40489),
      UINT16_C(63170), UINT16_C(41353), UINT16_C( 4497), UINT16_C(17557), UINT16_C( 7283), UINT16_C(10042), UINT16_C(23301), UINT16_C(35817),
      UINT16_C(52005), UINT16_C(61633), UINT16_C(41447), UINT16_C(44312), UINT16_C(15192), UINT16_C( 7307), UINT16_C(46136), UINT16_C(64186),
      UINT16_C(17322), UINT16_C(15516), UINT16_C(12629), UINT16_C(51328), UINT16_C(47950), UINT16_C(21488), UINT16_C(55574), UINT16_C(15326),
      UINT16_C(40869), UINT16_C(35883), UINT16_C(17472), UINT16_C(38970), UINT16_C(50559), UINT16_C(47028), UINT16_C(28537), UINT16_C( 9137),
      UINT16_C(19890), UINT16_C( 1887), UINT16_C(57471), UINT16_C(52688), UINT16_C(49307), UINT16_C(45344), UINT16_C(65177), UINT16_C(16109),
      UINT16_C( 6301), UINT16_C(56779), UINT16_C( 1372), UINT16_C(56182), UINT16_C(10954), UINT16_C(17298), UINT16_C(17561), UINT16_C(19558),
      UINT16_C(50833), UINT16_C( 4179), UINT16_C( 9126), UINT16_C(16861), UINT16_C(64995), UINT16_C(32242), UINT16_C(57339), UINT16_C(39099),
      UINT16_C(34552), UINT16_C(21622), UINT16_C(60555), UINT16_C(21808), UINT16_C(49686), UINT16_C(45208), UINT16_C(65286), UINT16_C(39164),
      UINT16_C(20421), UINT16_C(27560), UINT16_C(34419), UINT16_C(22188), UINT16_C(40579), UINT16_C(32723), UINT16_C(36734), UINT16_C(30231),
      UINT16_C(36117), UINT16_C(41418), UINT16_C(64121), UINT16_C(37110), UINT16_C(36797), UINT16_C(49984), UINT16_C(15502), UINT16_C(21339),
      UINT16_C( 1163), UINT16_C(65214), UINT16_C(27274), UINT16_C( 3413), UINT16_C(10248), UINT16_C(34444), UINT16_C(42167), UINT16_C(52732),
      UINT16_C(50993), UINT16_C(43886), UINT16_C(25793), UINT16_C(32315), UINT16_C(31731), UINT16_C(33090), UINT16_C(40375), UINT16_C(17108),
      UINT16_C(37537), UINT16_C(11073), UINT16_C(38652), UINT16_C( 1337), UINT16_C(50622), UINT16_C(30347), UINT16_C(34921), UINT16_C(39747),
      UINT16_C(45391), UINT16_C( 4166), UINT16_C(33045), UINT16_C( 2447), UINT16_C(53756), UINT16_C(45962), UINT16_C(24430), UINT16_C( 4341),
      UINT16_C(14065), UINT16_C(60987), UINT16_C(29900), UINT16_C(35827), UINT16_C(32314), UINT16_C(41729), UINT16_C(17414), UINT16_C(21822),
      UINT16_C(34037), UINT16_C( 2662), UINT16_C(62725), UINT16_C(  275), UINT16_C(40646), UINT16_C(13492), UINT16_C(43773), UINT16_C(60996),
      UINT16_C(32992), UINT16_C(44508), UINT16_C(53236), UINT16_C(11832), UINT16_C(14670), UINT16_C(21714), UINT16_C( 4221), UINT16_C(29354),
      UINT16_C( 4245), UINT16_C(39548), UINT16_C(36869), UINT16_C(52124), UINT16_C(20526), UINT16_C(11263), UINT16_C(17658), UINT16_C(56089),
      UINT16_C(63172), UINT16_C(47240), UINT16_C(49349), UINT16_C( 5095), UINT16_C(47609), UINT16_C(30312), UINT16_C( 4809), UINT16_C(24296),
      UINT16_C(25634), UINT16_C(10233), UINT16_C(38388), UINT16_C( 8946), UINT16_C(61925) };
  static const uint16_t e[] =
    { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 4098), UINT16_C(    0), UINT16_C(37328), UINT16_C( 2048), UINT16_C(    0),
      UINT16_C( 4376), UINT16_C(    0), UINT16_C(   64), UINT16_C( 2560), UINT16_C( 8240), UINT16_C(  652), UINT16_C(  512), UINT16_C(32828),
      UINT16_C(    0), UINT16_C( 9040), UINT16_C(  160), UINT16_C(33400), UINT16_C(16450), UINT16_C(   17), UINT16_C( 8226), UINT16_C(39984),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(  208), UINT16_C(16384), UINT16_C( 4242), UINT16_C( 4130), UINT16_C(20376),
      UINT16_C(    0), UINT16_C(32770), UINT16_C(  528), UINT16_C(17940), UINT16_C(    0), UINT16_C(34900), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(50182), UINT16_C(    0), UINT16_C(  128), UINT16_C(    4), UINT16_C(43128), UINT16_C(    0), UINT16_C(25328), UINT16_C(  185),
      UINT16_C(    0), UINT16_C(32859), UINT16_C( 2816), UINT16_C(33281), UINT16_C(    0), UINT16_C( 1024), UINT16_C(    0), UINT16_C(24584),
      UINT16_C(49952), UINT16_C(    0), UINT16_C(    0), UINT16_C( 1184), UINT16_C(    0), UINT16_C(  128), UINT16_C(12804), UINT16_C(  130),
      UINT16_C(    0), UINT16_C(35230), UINT16_C(    0), UINT16_C(    0), UINT16_C(   73), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(10656), UINT16_C(13362), UINT16_C(45956), UINT16_C(    0), UINT16_C(    0), UINT16_C( 6740),
      UINT16_C(20498), UINT16_C( 3140), UINT16_C(16452), UINT16_C(49680), UINT16_C(34210), UINT16_C( 9505), UINT16_C(    0), UINT16_C( 8289),
      UINT16_C( 5120), UINT16_C(    1), UINT16_C( 8762), UINT16_C(  768), UINT16_C(    0), UINT16_C( 9028), UINT16_C(    0), UINT16_C(33665),
      UINT16_C( 8208), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(45570), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(  167), UINT16_C(    0), UINT16_C(  128), UINT16_C(    0), UINT16_C(    0), UINT16_C(16532), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(32770), UINT16_C(    0), UINT16_C( 6272), UINT16_C(    0), UINT16_C(61952), UINT16_C( 2888), UINT16_C(    0),
      UINT16_C(12392), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(22534), UINT16_C(33888),
      UINT16_C(42041), UINT16_C(    0), UINT16_C(    2), UINT16_C( 8541), UINT16_C(    0), UINT16_C(25892), UINT16_C(    0), UINT16_C(    0),
      UINT16_C( 8224), UINT16_C( 1024), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(22545), UINT16_C(16481),
      UINT16_C(    0), UINT16_C( 1126), UINT16_C(17409), UINT16_C(    0), UINT16_C( 1024), UINT16_C(    0), UINT16_C(    0), UINT16_C( 1696),
      UINT16_C(    0), UINT16_C(    0), UINT16_C( 6244), UINT16_C(33538), UINT16_C(    0), UINT16_C(    0), UINT16_C(36864), UINT16_C(    0),
      UINT16_C(10352), UINT16_C(    0), UINT16_C( 2120), UINT16_C(19074), UINT16_C(   32), UINT16_C(18441), UINT16_C(41858), UINT16_C(25099),
      UINT16_C( 4912), UINT16_C(    0), UINT16_C(  197), UINT16_C(    0), UINT16_C(12332), UINT16_C(    0), UINT16_C( 2178), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(12620), UINT16_C( 8196), UINT16_C(53384), UINT16_C(    0), UINT16_C( 2304), UINT16_C(    0), UINT16_C(28858),
      UINT16_C(    0), UINT16_C( 4104), UINT16_C( 4096), UINT16_C(12566), UINT16_C( 8320), UINT16_C(    0), UINT16_C(10916), UINT16_C(19464),
      UINT16_C( 9730), UINT16_C(    0), UINT16_C(49861), UINT16_C( 8381), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(  768),
      UINT16_C(    0), UINT16_C(  240), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 9800), UINT16_C(    0), UINT16_C(16390), UINT16_C(    0), UINT16_C(  259),
      UINT16_C(    0), UINT16_C( 4096), UINT16_C(16960), UINT16_C( 8418), UINT16_C(16482), UINT16_C(    0), UINT16_C(22866), UINT16_C(10242),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(  571), UINT16_C(16768), UINT16_C( 2321), UINT16_C(    0), UINT16_C(    0), UINT16_C(   20),
      UINT16_C(    0), UINT16_C(    0), UINT16_C( 2051), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 4188), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(12290), UINT16_C( 3144), UINT16_C(    0), UINT16_C(    0), UINT16_C(30759), UINT16_C(32840), UINT16_C( 1024),
      UINT16_C(    0), UINT16_C(14608), UINT16_C(17938), UINT16_C(    0), UINT16_C( 1100), UINT16_C(    0), UINT16_C( 6176), UINT16_C(  544),
      UINT16_C(33281), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(16389), UINT16_C(35093), UINT16_C(25089), UINT16_C(    0),
      UINT16_C(    0), UINT16_C( 1680), UINT16_C(    0), UINT16_C(18706), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(  528), UINT16_C(    0), UINT16_C(34304), UINT16_C( 9385), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C( 2304), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(   80),
      UINT16_C(17988), UINT16_C(    0), UINT16_C(16972), UINT16_C(    0), UINT16_C(    0), UINT16_C(  522), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(   60), UINT16_C(    0), UINT16_C( 2056), UINT16_C( 2282), UINT16_C(    0), UINT16_C(    0), UINT16_C( 8225),
      UINT16_C(    0), UINT16_C(  673), UINT16_C( 4096), UINT16_C(    0), UINT16_C( 2069), UINT16_C(  601), UINT16_C(    0), UINT16_C(10848),
      UINT16_C( 7180), UINT16_C(    0), UINT16_C(  160), UINT16_C(32802), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(  714),
      UINT16_C(    0), UINT16_C(    0), UINT16_C( 2131), UINT16_C(    0), UINT16_C(16562), UINT16_C(46085), UINT16_C(26804), UINT16_C(    0),
      UINT16_C(34944), UINT16_C( 5826), UINT16_C( 2249), UINT16_C(   96), UINT16_C(42176), UINT16_C(53280), UINT16_C(12288), UINT16_C( 3105),
      UINT16_C(    0), UINT16_C(    0), UINT16_C( 4369), UINT16_C(    0), UINT16_C( 5203), UINT16_C( 1056), UINT16_C( 2560), UINT16_C(    0),
      UINT16_C(18976), UINT16_C(    0), UINT16_C(    0), UINT16_C( 2048), UINT16_C(10240), UINT16_C( 4232), UINT16_C(   24), UINT16_C(36920),
      UINT16_C(16896), UINT16_C(    0), UINT16_C(  337), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(   28),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(16448), UINT16_C(    0), UINT16_C(34166), UINT16_C(    0), UINT16_C(17416), UINT16_C(    0),
      UINT16_C( 2338), UINT16_C( 1053), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(45344), UINT16_C(64025), UINT16_C(    0),
      UINT16_C( 6272), UINT16_C(49474), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(  528), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(33856), UINT16_C(31058), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(32968), UINT16_C( 1092), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(  248),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(   16), UINT16_C(    0), UINT16_C(34947), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(29249), UINT16_C(  246), UINT16_C(35084), UINT16_C(  320), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    3), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(33920), UINT16_C(33847), UINT16_C(    0),
      UINT16_C(  529), UINT16_C( 8736), UINT16_C( 1088), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 3106), UINT16_C(   84),
      UINT16_C(    0), UINT16_C(    0), UINT16_C( 4844), UINT16_C(    0), UINT16_C(34078), UINT16_C(    0), UINT16_C(34888), UINT16_C( 4929),
      UINT16_C( 4170), UINT16_C(   66), UINT16_C(33040), UINT16_C(    0), UINT16_C(  104), UINT16_C(    0), UINT16_C(    0), UINT16_C(  132),
      UINT16_C(    0), UINT16_C( 1067), UINT16_C(    0), UINT16_C(35555), UINT16_C(30250), UINT16_C(    0), UINT16_C(    0), UINT16_C(16698),
      UINT16_C(    0), UINT16_C(  546), UINT16_C(    0), UINT16_C(    0), UINT16_C(33472), UINT16_C( 4148), UINT16_C(    0), UINT16_C(17984),
      UINT16_C(    0), UINT16_C(36184), UINT16_C(16724), UINT16_C(    0), UINT16_C(    0), UINT16_C( 5248), UINT16_C(  108), UINT16_C(    0),
      UINT16_C(  149), UINT16_C( 6716), UINT16_C(    0), UINT16_C(33672), UINT16_C(    0), UINT16_C( 8195), UINT16_C(17456), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(  136), UINT16_C(16517), UINT16_C(    0), UINT16_C(39328), UINT16_C(    0), UINT16_C(    0), UINT16_C(  200),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(34176), UINT16_C(   66), UINT16_C(    0) };

  static uint16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t
      rv,
      av = simde_svld1_u16(pg, &(a[i])),
      bv = simde_svld1_u16(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(INT16_C(0)));
    rv = simde_svand_u16_z(pv, av, bv);

    simde_svst1_u16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vu16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(int16_t)];
  uint16_t a[1024 / sizeof(int16_t)], b[1024 / sizeof(int16_t)], e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_u16(pg, &(a[i]));
    bv = simde_svld1_u16(pg, &(b[i]));

    ev = simde_svand_u16_z(pv, av, bv);

    simde_svst1_u16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_u16_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) };
  static const uint16_t a[] =
    { UINT16_C(56183), UINT16_C(58028), UINT16_C( 4969), UINT16_C(34416), UINT16_C( 3556), UINT16_C(21165), UINT16_C(32494), UINT16_C(63971),
      UINT16_C(61302), UINT16_C(42984), UINT16_C(60860), UINT16_C(58291), UINT16_C(27549), UINT16_C(25400), UINT16_C(52538), UINT16_C(45559),
      UINT16_C(41896), UINT16_C( 4499), UINT16_C(  950), UINT16_C(39831), UINT16_C(17681), UINT16_C(65517), UINT16_C(53443), UINT16_C(15096),
      UINT16_C(57792), UINT16_C(31969), UINT16_C(38094), UINT16_C(27488), UINT16_C(39167), UINT16_C(15054), UINT16_C(50533), UINT16_C( 3563),
      UINT16_C(32616), UINT16_C( 7711), UINT16_C(46722), UINT16_C(37817), UINT16_C(43003), UINT16_C(49042), UINT16_C(35703), UINT16_C(14329),
      UINT16_C(55916), UINT16_C(15028), UINT16_C( 5230), UINT16_C(28069), UINT16_C(29612), UINT16_C( 4519), UINT16_C(37688), UINT16_C(40990),
      UINT16_C(15634), UINT16_C(38078), UINT16_C(30964), UINT16_C(61224), UINT16_C(47647), UINT16_C(38574), UINT16_C(42821), UINT16_C(45518),
      UINT16_C(33409), UINT16_C(61419), UINT16_C(37014), UINT16_C(16989), UINT16_C( 1027), UINT16_C(15187), UINT16_C(29079), UINT16_C(43483),
      UINT16_C(39599), UINT16_C(41790), UINT16_C(26130), UINT16_C(12690), UINT16_C(16672), UINT16_C(26311), UINT16_C(38376), UINT16_C(27159),
      UINT16_C(  791), UINT16_C(44377), UINT16_C(46739), UINT16_C(38895), UINT16_C(17083), UINT16_C(21202), UINT16_C(44724), UINT16_C(25596),
      UINT16_C(14920), UINT16_C(23046), UINT16_C(39072), UINT16_C(49291), UINT16_C(21209), UINT16_C(49702), UINT16_C(16104), UINT16_C(65324),
      UINT16_C(34113), UINT16_C(54445), UINT16_C(39996), UINT16_C(63339), UINT16_C(16095), UINT16_C(37705), UINT16_C(17900), UINT16_C(13558),
      UINT16_C(64639), UINT16_C( 8078), UINT16_C( 6548), UINT16_C(28384), UINT16_C( 1643), UINT16_C(21296), UINT16_C(23620), UINT16_C(34131),
      UINT16_C(  225), UINT16_C( 7514), UINT16_C(50588), UINT16_C(31508), UINT16_C(24067), UINT16_C(61198), UINT16_C( 1187), UINT16_C( 8995),
      UINT16_C(45312), UINT16_C(38210), UINT16_C( 8906), UINT16_C(13827), UINT16_C(13097), UINT16_C(28041), UINT16_C(56463), UINT16_C(28915),
      UINT16_C(19932), UINT16_C(31118), UINT16_C(41490), UINT16_C( 5876), UINT16_C(  768), UINT16_C(41989), UINT16_C(10503), UINT16_C( 2247),
      UINT16_C( 2522), UINT16_C(42397), UINT16_C(41004), UINT16_C(21979), UINT16_C(25811), UINT16_C(25282), UINT16_C(46401), UINT16_C( 7634),
      UINT16_C(24578), UINT16_C( 5526), UINT16_C(35587), UINT16_C(  811), UINT16_C(12430), UINT16_C(38311), UINT16_C(28249), UINT16_C(13469),
      UINT16_C(14968), UINT16_C(42201), UINT16_C(46298), UINT16_C(44537), UINT16_C(47896), UINT16_C(22799), UINT16_C(57969), UINT16_C(29559),
      UINT16_C( 3394), UINT16_C(17800), UINT16_C(45976), UINT16_C( 9801), UINT16_C(61668), UINT16_C(15804), UINT16_C(22879), UINT16_C(55153),
      UINT16_C(19092), UINT16_C(28283), UINT16_C(29950), UINT16_C( 5916), UINT16_C(11055), UINT16_C(41072), UINT16_C(59149), UINT16_C(20500),
      UINT16_C(40181), UINT16_C(36245), UINT16_C(56912), UINT16_C(13492), UINT16_C(28879), UINT16_C(11889), UINT16_C(58313), UINT16_C(23813),
      UINT16_C(32813), UINT16_C(11468), UINT16_C(59636), UINT16_C( 9027), UINT16_C(45843), UINT16_C( 8644), UINT16_C(55451), UINT16_C(36977),
      UINT16_C( 1652), UINT16_C(50205), UINT16_C(53733), UINT16_C(46328), UINT16_C(27201), UINT16_C( 3042), UINT16_C(59213), UINT16_C(31336),
      UINT16_C(13415), UINT16_C(23462), UINT16_C(59676), UINT16_C(12414), UINT16_C(17053), UINT16_C(14417), UINT16_C(49690), UINT16_C(36808),
      UINT16_C(58824), UINT16_C(44371), UINT16_C(19639), UINT16_C(63585), UINT16_C(17334), UINT16_C(  771), UINT16_C(27690), UINT16_C(37245),
      UINT16_C( 9376), UINT16_C(48620), UINT16_C(27405), UINT16_C(43757), UINT16_C(16045), UINT16_C(51426), UINT16_C(43520), UINT16_C(51287),
      UINT16_C(43664), UINT16_C(18294), UINT16_C(55286), UINT16_C(44095), UINT16_C(17179), UINT16_C(17839), UINT16_C(11695), UINT16_C(20439),
      UINT16_C(50001), UINT16_C(24076), UINT16_C(63790), UINT16_C(56329), UINT16_C(60215), UINT16_C(14244), UINT16_C(64406), UINT16_C( 9728),
      UINT16_C(30373), UINT16_C(40045), UINT16_C(44109), UINT16_C(26696), UINT16_C(63727), UINT16_C(40622), UINT16_C(34085), UINT16_C(30446),
      UINT16_C(64072), UINT16_C(30676), UINT16_C(56820), UINT16_C(11091), UINT16_C(63433), UINT16_C(24419), UINT16_C(25586), UINT16_C(38789),
      UINT16_C(62169), UINT16_C( 9779), UINT16_C(31902), UINT16_C(36495), UINT16_C(15732), UINT16_C(39212), UINT16_C( 6850), UINT16_C( 2575),
      UINT16_C(58133), UINT16_C( 2433), UINT16_C(54465), UINT16_C(35380), UINT16_C(38859), UINT16_C(48617), UINT16_C(28410), UINT16_C(54101),
      UINT16_C(34912), UINT16_C(65274), UINT16_C(35076), UINT16_C(30860), UINT16_C(47558), UINT16_C(34833), UINT16_C( 8403), UINT16_C(59538),
      UINT16_C( 5124), UINT16_C(50673), UINT16_C( 9960), UINT16_C(46159), UINT16_C(14525), UINT16_C(47217), UINT16_C(50854), UINT16_C( 1675),
      UINT16_C(34127), UINT16_C(21252), UINT16_C(37134), UINT16_C(54476), UINT16_C(56650), UINT16_C( 7516), UINT16_C(61438), UINT16_C(  518),
      UINT16_C(63235), UINT16_C(60359), UINT16_C( 5661), UINT16_C(56223), UINT16_C( 4430), UINT16_C(62611), UINT16_C( 7895), UINT16_C( 9978),
      UINT16_C(65188), UINT16_C(45690), UINT16_C(18063), UINT16_C(55687), UINT16_C(58147), UINT16_C( 8695), UINT16_C(64978), UINT16_C(54563),
      UINT16_C(60148), UINT16_C( 4801), UINT16_C(24576), UINT16_C(20205), UINT16_C(32881), UINT16_C(18754), UINT16_C(15518), UINT16_C(17007),
      UINT16_C(59707), UINT16_C(51957), UINT16_C(31791), UINT16_C(21412) };
  static const uint16_t b[] =
    { UINT16_C( 5426), UINT16_C(22447), UINT16_C(32799), UINT16_C(18992), UINT16_C(20144), UINT16_C(18591), UINT16_C(65405), UINT16_C(58498),
      UINT16_C(38201), UINT16_C(58462), UINT16_C(10658), UINT16_C(44069), UINT16_C(12140), UINT16_C( 6701), UINT16_C(57375), UINT16_C(20814),
      UINT16_C(65013), UINT16_C( 5289), UINT16_C(55677), UINT16_C(11615), UINT16_C(65064), UINT16_C(42357), UINT16_C(63485), UINT16_C(13961),
      UINT16_C(59533), UINT16_C(12059), UINT16_C(16401), UINT16_C(32219), UINT16_C( 2159), UINT16_C(36504), UINT16_C(59112), UINT16_C(57056),
      UINT16_C(35299), UINT16_C(24818), UINT16_C(20834), UINT16_C(35469), UINT16_C(  591), UINT16_C(19759), UINT16_C(47610), UINT16_C(34691),
      UINT16_C(40609), UINT16_C(45750), UINT16_C(37342), UINT16_C(19760), UINT16_C(51353), UINT16_C(33500), UINT16_C(48302), UINT16_C(37216),
      UINT16_C(21061), UINT16_C(42993), UINT16_C(32420), UINT16_C(62258), UINT16_C(24960), UINT16_C(31296), UINT16_C(50202), UINT16_C(47873),
      UINT16_C(46946), UINT16_C(16750), UINT16_C(40520), UINT16_C(57998), UINT16_C(27238), UINT16_C( 5220), UINT16_C(50214), UINT16_C(27557),
      UINT16_C(38422), UINT16_C(47635), UINT16_C(17684), UINT16_C(38062), UINT16_C(61094), UINT16_C(49423), UINT16_C( 4274), UINT16_C( 5500),
      UINT16_C(60104), UINT16_C( 4182), UINT16_C(58504), UINT16_C(61170), UINT16_C(22095), UINT16_C(29954), UINT16_C(42778), UINT16_C(12769),
      UINT16_C(62525), UINT16_C(20971), UINT16_C(39225), UINT16_C(57318), UINT16_C(62856), UINT16_C(15008), UINT16_C( 7429), UINT16_C(52559),
      UINT16_C(42247), UINT16_C(37086), UINT16_C(53386), UINT16_C(55678), UINT16_C(33063), UINT16_C(16718), UINT16_C(12072), UINT16_C(26226),
      UINT16_C(24099), UINT16_C(23735), UINT16_C(40439), UINT16_C(32572), UINT16_C(56466), UINT16_C(39098), UINT16_C( 2553), UINT16_C(  357),
      UINT16_C(17327), UINT16_C(14737), UINT16_C( 3860), UINT16_C(15122), UINT16_C(24720), UINT16_C(47484), UINT16_C(61328), UINT16_C(45855),
      UINT16_C(54861), UINT16_C(17424), UINT16_C(19572), UINT16_C( 1732), UINT16_C(32296), UINT16_C( 8862), UINT16_C( 1159), UINT16_C(13859),
      UINT16_C(46151), UINT16_C(23407), UINT16_C(33219), UINT16_C(21654), UINT16_C( 5090), UINT16_C(29197), UINT16_C(11266), UINT16_C(20261),
      UINT16_C(13570), UINT16_C(30355), UINT16_C(22401), UINT16_C(43645), UINT16_C( 7125), UINT16_C(24012), UINT16_C(61215), UINT16_C(26515),
      UINT16_C(  931), UINT16_C(26306), UINT16_C(22916), UINT16_C(26298), UINT16_C(51052), UINT16_C(28376), UINT16_C(65267), UINT16_C(63165),
      UINT16_C(20531), UINT16_C(46444), UINT16_C(59816), UINT16_C(32095), UINT16_C(11013), UINT16_C( 9434), UINT16_C(28186), UINT16_C(48523),
      UINT16_C(20081), UINT16_C(62755), UINT16_C(56999), UINT16_C( 4956), UINT16_C(13477), UINT16_C(39297), UINT16_C(15922), UINT16_C(26255),
      UINT16_C(64398), UINT16_C(13851), UINT16_C(31461), UINT16_C(60084), UINT16_C(36517), UINT16_C(48910), UINT16_C(39676), UINT16_C(28028),
      UINT16_C(40936), UINT16_C(36707), UINT16_C(49021), UINT16_C( 9122), UINT16_C( 9203), UINT16_C( 9916), UINT16_C(19297), UINT16_C(61324),
      UINT16_C(42822), UINT16_C(11046), UINT16_C(55841), UINT16_C(50709), UINT16_C( 9320), UINT16_C(25989), UINT16_C(  446), UINT16_C(42706),
      UINT16_C(13728), UINT16_C( 7733), UINT16_C(55284), UINT16_C(59457), UINT16_C(65018), UINT16_C(23310), UINT16_C(39496), UINT16_C(36426),
      UINT16_C(28737), UINT16_C(25274), UINT16_C(53066), UINT16_C(45864), UINT16_C(44531), UINT16_C(45336), UINT16_C(60078), UINT16_C(20055),
      UINT16_C(35872), UINT16_C( 5228), UINT16_C(44387), UINT16_C(24060), UINT16_C( 2730), UINT16_C(62136), UINT16_C(  932), UINT16_C(58753),
      UINT16_C(15219), UINT16_C(48711), UINT16_C(28426), UINT16_C(65137), UINT16_C(35100), UINT16_C(51887), UINT16_C( 1907), UINT16_C(37657),
      UINT16_C(34195), UINT16_C(63400), UINT16_C(42035), UINT16_C(56660), UINT16_C( 3503), UINT16_C(21456), UINT16_C(20752), UINT16_C(33593),
      UINT16_C(32908), UINT16_C(38465), UINT16_C(45808), UINT16_C( 3220), UINT16_C(17467), UINT16_C(45015), UINT16_C(61515), UINT16_C(56898),
      UINT16_C(60021), UINT16_C(43221), UINT16_C(10895), UINT16_C(16006), UINT16_C(22071), UINT16_C(18321), UINT16_C(51879), UINT16_C(13258),
      UINT16_C( 3147), UINT16_C(15305), UINT16_C(24254), UINT16_C(64071), UINT16_C( 7842), UINT16_C(60841), UINT16_C(60174), UINT16_C(33995),
      UINT16_C(41430), UINT16_C(25900), UINT16_C(45771), UINT16_C(  675), UINT16_C(13320), UINT16_C(44873), UINT16_C( 5119), UINT16_C(19170),
      UINT16_C(44063), UINT16_C(56965), UINT16_C(52234), UINT16_C(44248), UINT16_C(33259), UINT16_C(63897), UINT16_C(25708), UINT16_C(17021),
      UINT16_C(43525), UINT16_C(53415), UINT16_C(19036), UINT16_C(26066), UINT16_C( 7039), UINT16_C(32276), UINT16_C(63279), UINT16_C(20168),
      UINT16_C(19875), UINT16_C(44332), UINT16_C( 1049), UINT16_C( 1113), UINT16_C(62085), UINT16_C(62206), UINT16_C(31574), UINT16_C(23604),
      UINT16_C(56357), UINT16_C(33324), UINT16_C(65318), UINT16_C(42471), UINT16_C(64282), UINT16_C(18723), UINT16_C(60402), UINT16_C(38296),
      UINT16_C(50232), UINT16_C(21058), UINT16_C(39881), UINT16_C(20054), UINT16_C(21645), UINT16_C(58432), UINT16_C(30160), UINT16_C(62784),
      UINT16_C(27729), UINT16_C(30583), UINT16_C(24171), UINT16_C(34333), UINT16_C(16474), UINT16_C(19663), UINT16_C(26412), UINT16_C(25826),
      UINT16_C( 9260), UINT16_C(62902), UINT16_C( 3520), UINT16_C(19779), UINT16_C(33889), UINT16_C(12593), UINT16_C(29177), UINT16_C(18983),
      UINT16_C(40670), UINT16_C(18881), UINT16_C(57085), UINT16_C(22479) };
  static const uint16_t e[] =
    { UINT16_C(56183), UINT16_C(17068), UINT16_C(    9), UINT16_C(  560), UINT16_C( 3556), UINT16_C(16525), UINT16_C(32494), UINT16_C(63971),
      UINT16_C(61302), UINT16_C(42984), UINT16_C(60860), UINT16_C(40993), UINT16_C(11020), UINT16_C(  552), UINT16_C(52538), UINT16_C( 4422),
      UINT16_C(41896), UINT16_C( 4225), UINT16_C(  950), UINT16_C(39831), UINT16_C(17408), UINT16_C(65517), UINT16_C(53443), UINT16_C(12936),
      UINT16_C(57792), UINT16_C(11265), UINT16_C(38094), UINT16_C(27488), UINT16_C(39167), UINT16_C(15054), UINT16_C(50533), UINT16_C( 3296),
      UINT16_C(32616), UINT16_C(   18), UINT16_C( 4098), UINT16_C(33417), UINT16_C(43003), UINT16_C(49042), UINT16_C(35186), UINT16_C(14329),
      UINT16_C(55916), UINT16_C(12980), UINT16_C( 4174), UINT16_C(19744), UINT16_C(29612), UINT16_C( 4519), UINT16_C(37688), UINT16_C(32768),
      UINT16_C(15634), UINT16_C(33968), UINT16_C(30964), UINT16_C(58144), UINT16_C(47647), UINT16_C( 4608), UINT16_C(42821), UINT16_C(45518),
      UINT16_C(33280), UINT16_C(61419), UINT16_C(37014), UINT16_C(16989), UINT16_C( 1027), UINT16_C(15187), UINT16_C(16390), UINT16_C(43483),
      UINT16_C(39599), UINT16_C(41790), UINT16_C(17424), UINT16_C( 4226), UINT16_C(16672), UINT16_C(16391), UINT16_C( 4256), UINT16_C(27159),
      UINT16_C(  512), UINT16_C(44377), UINT16_C(42112), UINT16_C(34530), UINT16_C(16907), UINT16_C(20482), UINT16_C(44724), UINT16_C( 8672),
      UINT16_C(14920), UINT16_C(23046), UINT16_C(38944), UINT16_C(49291), UINT16_C(21209), UINT16_C(  544), UINT16_C(16104), UINT16_C(52492),
      UINT16_C(34049), UINT16_C(37004), UINT16_C(39996), UINT16_C(53610), UINT16_C(16095), UINT16_C(37705), UINT16_C( 1320), UINT16_C( 9330),
      UINT16_C(64639), UINT16_C( 7302), UINT16_C( 6548), UINT16_C(28192), UINT16_C( 1643), UINT16_C( 4144), UINT16_C( 2112), UINT16_C(34131),
      UINT16_C(  225), UINT16_C( 7514), UINT16_C( 1300), UINT16_C(15120), UINT16_C(24067), UINT16_C(43276), UINT16_C( 1187), UINT16_C( 8995),
      UINT16_C(45312), UINT16_C(38210), UINT16_C(   64), UINT16_C(13827), UINT16_C(13097), UINT16_C( 8328), UINT16_C( 1159), UINT16_C(28915),
      UINT16_C(19932), UINT16_C(22798), UINT16_C(41490), UINT16_C( 5876), UINT16_C(  768), UINT16_C(41989), UINT16_C(10503), UINT16_C( 2053),
      UINT16_C( 2522), UINT16_C( 9361), UINT16_C(    0), UINT16_C(21979), UINT16_C(  209), UINT16_C(25282), UINT16_C(46401), UINT16_C( 7634),
      UINT16_C(24578), UINT16_C( 5526), UINT16_C(35587), UINT16_C(  811), UINT16_C(12430), UINT16_C(38311), UINT16_C(28241), UINT16_C(13469),
      UINT16_C(14968), UINT16_C(42056), UINT16_C(46298), UINT16_C(11609), UINT16_C(11008), UINT16_C(   10), UINT16_C(25104), UINT16_C(12547),
      UINT16_C( 3394), UINT16_C(17800), UINT16_C(45976), UINT16_C( 9801), UINT16_C(61668), UINT16_C( 6528), UINT16_C( 6162), UINT16_C(55153),
      UINT16_C(19092), UINT16_C(28283), UINT16_C(29950), UINT16_C(  532), UINT16_C(11055), UINT16_C(40960), UINT16_C(33292), UINT16_C(20500),
      UINT16_C(40181), UINT16_C(36097), UINT16_C(56912), UINT16_C( 8352), UINT16_C(28879), UINT16_C(11889), UINT16_C(58313), UINT16_C(23813),
      UINT16_C(32772), UINT16_C(10244), UINT16_C(51232), UINT16_C( 9027), UINT16_C(45843), UINT16_C( 8644), UINT16_C(  154), UINT16_C(32848),
      UINT16_C( 1056), UINT16_C( 1045), UINT16_C(53733), UINT16_C(41024), UINT16_C(27201), UINT16_C( 3042), UINT16_C(33352), UINT16_C( 2632),
      UINT16_C(13415), UINT16_C(17058), UINT16_C(51464), UINT16_C(12414), UINT16_C(  145), UINT16_C(14417), UINT16_C(49674), UINT16_C( 3648),
      UINT16_C(33792), UINT16_C( 1088), UINT16_C( 3107), UINT16_C(63585), UINT16_C(  674), UINT16_C(  512), UINT16_C(   32), UINT16_C(37245),
      UINT16_C( 8224), UINT16_C(48620), UINT16_C(27405), UINT16_C(43617), UINT16_C(16045), UINT16_C(51362), UINT16_C(43520), UINT16_C(32785),
      UINT16_C(32912), UINT16_C(18208), UINT16_C(33842), UINT16_C(35860), UINT16_C(  267), UINT16_C(17839), UINT16_C(11695), UINT16_C(  785),
      UINT16_C(32768), UINT16_C( 5632), UINT16_C(45088), UINT16_C( 3072), UINT16_C(16435), UINT16_C(14244), UINT16_C(61442), UINT16_C( 1536),
      UINT16_C(30373), UINT16_C(40045), UINT16_C(44109), UINT16_C(26696), UINT16_C(20519), UINT16_C( 1664), UINT16_C(34085), UINT16_C(13002),
      UINT16_C(64072), UINT16_C(13248), UINT16_C(56820), UINT16_C(10819), UINT16_C(63433), UINT16_C(24419), UINT16_C(25586), UINT16_C(33921),
      UINT16_C(41168), UINT16_C( 9779), UINT16_C(31902), UINT16_C(  643), UINT16_C(13312), UINT16_C(39212), UINT16_C( 6850), UINT16_C( 2575),
      UINT16_C(40981), UINT16_C( 2177), UINT16_C(54465), UINT16_C(35380), UINT16_C(38859), UINT16_C(47497), UINT16_C(28410), UINT16_C(16981),
      UINT16_C(34816), UINT16_C(53410), UINT16_C(35076), UINT16_C(24704), UINT16_C( 6470), UINT16_C(34833), UINT16_C( 8403), UINT16_C(59538),
      UINT16_C( 5124), UINT16_C(34080), UINT16_C( 9960), UINT16_C(46159), UINT16_C(12421), UINT16_C(47217), UINT16_C(16902), UINT16_C( 1024),
      UINT16_C(33797), UINT16_C(  516), UINT16_C(37126), UINT16_C(33988), UINT16_C(55562), UINT16_C( 7516), UINT16_C(60402), UINT16_C(  518),
      UINT16_C(63235), UINT16_C(16962), UINT16_C( 4617), UINT16_C(56223), UINT16_C( 4430), UINT16_C(58368), UINT16_C( 5328), UINT16_C( 9978),
      UINT16_C(27648), UINT16_C(45690), UINT16_C(17931), UINT16_C(32773), UINT16_C(16386), UINT16_C( 8695), UINT16_C(64978), UINT16_C(54563),
      UINT16_C( 8228), UINT16_C( 4801), UINT16_C(24576), UINT16_C(19521), UINT16_C(32865), UINT16_C(18754), UINT16_C(15518), UINT16_C(17007),
      UINT16_C(34842), UINT16_C(18625), UINT16_C(23597), UINT16_C(21380) };

  static uint16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t
      rv,
      av = simde_svld1_u16(pg, &(a[i])),
      bv = simde_svld1_u16(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(INT16_C(0)));
    rv = simde_svand_u16_m(pv, av, bv);

    simde_svst1_u16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vu16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(int16_t)];
  uint16_t a[1024 / sizeof(int16_t)], b[1024 / sizeof(int16_t)], e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_u16(pg, &(a[i]));
    bv = simde_svld1_u16(pg, &(b[i]));

    ev = simde_svand_u16_m(pv, av, bv);

    simde_svst1_u16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_u32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) };
  static const uint32_t a[] =
    { UINT32_C(1681095269), UINT32_C(1339152432), UINT32_C(1600031812), UINT32_C(3132162968), UINT32_C(2564636943), UINT32_C(4216327160), UINT32_C(4281498254), UINT32_C(3039581775),
      UINT32_C(  18440144), UINT32_C(2085677879), UINT32_C( 266055287), UINT32_C(3234434225), UINT32_C(3327698638), UINT32_C(1086433458), UINT32_C(1916793634), UINT32_C( 422013769),
      UINT32_C(  35274954), UINT32_C(2726193707), UINT32_C(3383843096), UINT32_C(3028974310), UINT32_C(3548045857), UINT32_C(2903718795), UINT32_C(1998541614), UINT32_C(2307933886),
      UINT32_C(2995497863), UINT32_C( 777324821), UINT32_C(1224148578), UINT32_C(2734457217), UINT32_C(4017452644), UINT32_C(3751577777), UINT32_C(2589375707), UINT32_C(2300831490),
      UINT32_C(2805771922), UINT32_C( 433426871), UINT32_C( 409128343), UINT32_C(2998558286), UINT32_C(2258710485), UINT32_C(2472951480), UINT32_C(4230855930), UINT32_C( 897994915),
      UINT32_C(3051209470), UINT32_C(3939480147), UINT32_C(3456315775), UINT32_C(1686158735), UINT32_C(2783650541), UINT32_C(1513640288), UINT32_C(2975229453), UINT32_C(3051805878),
      UINT32_C(4050305950), UINT32_C(4124850550), UINT32_C(4207140714), UINT32_C(2304656540), UINT32_C(3324922214), UINT32_C(2820695962), UINT32_C(2203678413), UINT32_C(4046995283),
      UINT32_C(2044961539), UINT32_C(1198440412), UINT32_C( 977351326), UINT32_C(3703873398), UINT32_C(2208494313), UINT32_C( 640402009), UINT32_C(2343207992), UINT32_C(3346916036),
      UINT32_C(1648386181), UINT32_C(3182013983), UINT32_C(1459088096), UINT32_C(1915927433), UINT32_C( 133616814), UINT32_C(3475906966), UINT32_C(1784338598), UINT32_C(1077008314),
      UINT32_C(1453486391), UINT32_C(   1264415), UINT32_C(3193310005), UINT32_C(1949403590), UINT32_C(4101777245), UINT32_C(4005800520), UINT32_C(1012407682), UINT32_C( 746359285),
      UINT32_C( 444800762), UINT32_C(2652542569), UINT32_C(1750954145), UINT32_C(1474072313), UINT32_C(4249573557), UINT32_C(2230062594), UINT32_C( 549536811), UINT32_C(3360505294),
      UINT32_C(3319976028), UINT32_C( 140835942), UINT32_C(1718665581), UINT32_C(  79514703), UINT32_C(2801862821), UINT32_C(1110240534), UINT32_C(   6483250), UINT32_C(2261298986),
      UINT32_C(3863784319), UINT32_C( 351187111), UINT32_C(3229310577), UINT32_C(1338259626), UINT32_C(1475855681), UINT32_C(3852018611), UINT32_C( 988150800), UINT32_C( 734113195),
      UINT32_C(   1117528), UINT32_C( 773128125), UINT32_C( 133074781), UINT32_C( 156742344), UINT32_C( 710954615), UINT32_C(2165308017), UINT32_C(2713449718), UINT32_C(4207705250),
      UINT32_C(1190845833), UINT32_C( 963907548), UINT32_C(1715561118), UINT32_C(2356123668), UINT32_C(1471598822), UINT32_C(3235432138), UINT32_C(1549898682), UINT32_C(2572627472),
      UINT32_C(3907014923), UINT32_C(4280374368), UINT32_C(3412419255), UINT32_C(3763852794), UINT32_C(1865879205), UINT32_C(2385448916), UINT32_C(3018559651), UINT32_C(3393995454),
      UINT32_C(4105317523), UINT32_C( 955503489), UINT32_C( 805525558), UINT32_C(3524352813), UINT32_C(1027688553), UINT32_C(4224413784), UINT32_C(3215898113), UINT32_C(2357852920),
      UINT32_C(2826976039), UINT32_C(1172337423), UINT32_C(4185252811), UINT32_C(2815133246), UINT32_C( 669257167), UINT32_C(2116202621), UINT32_C(1597952102), UINT32_C(4058761162),
      UINT32_C( 312044291), UINT32_C(2841082334), UINT32_C(2611137629), UINT32_C( 574844499), UINT32_C(4165543803), UINT32_C(1048013783), UINT32_C(  94221627), UINT32_C(2146928764),
      UINT32_C(3515977971), UINT32_C(1736108042), UINT32_C( 134356405), UINT32_C( 103433611), UINT32_C(1157526381), UINT32_C( 427980254), UINT32_C(2803769130), UINT32_C(2586187175),
      UINT32_C(2959849638), UINT32_C(1427629728), UINT32_C(2388465923), UINT32_C(3432286047), UINT32_C(3624964858), UINT32_C( 854692616), UINT32_C(1524175026), UINT32_C(3421765669),
      UINT32_C(1484480696), UINT32_C(1236177478), UINT32_C( 198642604), UINT32_C(2379705235), UINT32_C(  90630141), UINT32_C( 758667130), UINT32_C(2374439271), UINT32_C(3378019089),
      UINT32_C( 555930843), UINT32_C( 308990054), UINT32_C(1847411163), UINT32_C(2868704428), UINT32_C(1454334684), UINT32_C( 562292665), UINT32_C( 179178233), UINT32_C(1641285254),
      UINT32_C(1099167450), UINT32_C(2706632134), UINT32_C(3675287855), UINT32_C(1099238501), UINT32_C( 664286574), UINT32_C( 357047068), UINT32_C(2887841318), UINT32_C(3608016125),
      UINT32_C(2954399978), UINT32_C(2907794558), UINT32_C(1116234205), UINT32_C(3682864749), UINT32_C(1594039363), UINT32_C(1567968055), UINT32_C(1057592642), UINT32_C(1930827657),
      UINT32_C( 623062951), UINT32_C(2027058331), UINT32_C(1136286678), UINT32_C(2887728745), UINT32_C(2450203226), UINT32_C(2951708781), UINT32_C(2666461461), UINT32_C(3071345936),
      UINT32_C(3487380532), UINT32_C(2135404457), UINT32_C(1942094090), UINT32_C(2585780544) };
  static const uint32_t b[] =
    { UINT32_C(1091653393), UINT32_C( 320325188), UINT32_C(3778122021), UINT32_C(2245500465), UINT32_C(1471655660), UINT32_C(3991687637), UINT32_C(4242734545), UINT32_C(3097250727),
      UINT32_C(3740970394), UINT32_C(2582778227), UINT32_C(3564774306), UINT32_C(2908312001), UINT32_C(3557036287), UINT32_C( 868348258), UINT32_C(2502927342), UINT32_C(2303642606),
      UINT32_C(3949414520), UINT32_C(4236532057), UINT32_C(1053884029), UINT32_C(1340877135), UINT32_C(2602823737), UINT32_C(3503220193), UINT32_C(2003172744), UINT32_C(1073787848),
      UINT32_C(1428973563), UINT32_C(1045541057), UINT32_C(4269547951), UINT32_C(2202888266), UINT32_C( 975139161), UINT32_C(3725258070), UINT32_C(3008721131), UINT32_C( 536106275),
      UINT32_C(2121539773), UINT32_C(2143077840), UINT32_C( 813578470), UINT32_C(4206087073), UINT32_C(2452935228), UINT32_C(2876325824), UINT32_C(3529426607), UINT32_C(3656471068),
      UINT32_C(1129801074), UINT32_C( 281154346), UINT32_C(3963633739), UINT32_C(1223095308), UINT32_C(2262506438), UINT32_C( 154225754), UINT32_C( 786141202), UINT32_C(1426574818),
      UINT32_C(1570266674), UINT32_C(3178060401), UINT32_C(2812915355), UINT32_C(1760530594), UINT32_C(  99601067), UINT32_C( 688791574), UINT32_C(2472012208), UINT32_C(3924320182),
      UINT32_C( 793149629), UINT32_C(1978446810), UINT32_C(  52204897), UINT32_C(3496741925), UINT32_C(3990182870), UINT32_C( 739697531), UINT32_C(2210360781), UINT32_C(2322376652),
      UINT32_C(  28946983), UINT32_C(3346507110), UINT32_C(1623954234), UINT32_C(1982871455), UINT32_C( 224593554), UINT32_C(3057220073), UINT32_C(3006986470), UINT32_C(3325929119),
      UINT32_C(3217618521), UINT32_C(3582345115), UINT32_C(1916096978), UINT32_C( 451438216), UINT32_C(1428704108), UINT32_C(2852938180), UINT32_C(4183639642), UINT32_C(1170250476),
      UINT32_C( 721717392), UINT32_C(2567015367), UINT32_C(1695233756), UINT32_C( 142603164), UINT32_C(  39757630), UINT32_C(1672309257), UINT32_C(2623277744), UINT32_C( 904010917),
      UINT32_C(1801578148), UINT32_C(1308975729), UINT32_C( 900927640), UINT32_C(1111306756), UINT32_C(3812989914), UINT32_C(3041325573), UINT32_C(2706547452), UINT32_C(1675048127),
      UINT32_C(2362390554), UINT32_C( 853202074), UINT32_C(3899100644), UINT32_C(2569774527), UINT32_C(1182560320), UINT32_C(1593557602), UINT32_C( 603999589), UINT32_C(2626148225),
      UINT32_C(2837992975), UINT32_C( 266011178), UINT32_C(1324827535), UINT32_C( 686301928), UINT32_C(4100875410), UINT32_C(2354276903), UINT32_C( 967857079), UINT32_C( 970274602),
      UINT32_C(3101883790), UINT32_C(2395454975), UINT32_C(3906780928), UINT32_C(1947321569), UINT32_C(1349025577), UINT32_C(2715597801), UINT32_C( 953846798), UINT32_C(1366405059),
      UINT32_C(2869580716), UINT32_C( 289001745), UINT32_C(1928992144), UINT32_C(  65407962), UINT32_C(1951616650), UINT32_C( 404041482), UINT32_C(2119299003), UINT32_C(1255195294),
      UINT32_C( 670423574), UINT32_C(1010314923), UINT32_C( 497955395), UINT32_C(3357578301), UINT32_C(3963384802), UINT32_C(1560629666), UINT32_C(3738981952), UINT32_C( 774417432),
      UINT32_C( 827661702), UINT32_C(2389544523), UINT32_C(4272692160), UINT32_C(2462502063), UINT32_C(3799908928), UINT32_C(2470478675), UINT32_C(4067499225), UINT32_C(1310759368),
      UINT32_C(  25130678), UINT32_C(3297766660), UINT32_C(3099736840), UINT32_C(1212844040), UINT32_C(3710568586), UINT32_C( 628124236), UINT32_C(1310187910), UINT32_C( 815544442),
      UINT32_C(2989563054), UINT32_C( 292995337), UINT32_C(  80296444), UINT32_C(1280054209), UINT32_C( 673806300), UINT32_C(1749916385), UINT32_C(4139148667), UINT32_C(1260802973),
      UINT32_C(2029869167), UINT32_C( 361329433), UINT32_C(1847219116), UINT32_C(1119512166), UINT32_C(3211453405), UINT32_C(4180129917), UINT32_C(3136281885), UINT32_C(2667910448),
      UINT32_C(2249654893), UINT32_C( 580690293), UINT32_C(1519433460), UINT32_C(4204612124), UINT32_C(2881029933), UINT32_C(3701792959), UINT32_C(4002845629), UINT32_C( 378379176),
      UINT32_C( 329033117), UINT32_C( 976566342), UINT32_C( 194299374), UINT32_C(1006973199), UINT32_C(4175937081), UINT32_C(1540721566), UINT32_C(3343477534), UINT32_C(2766001927),
      UINT32_C(3266804092), UINT32_C(2700930226), UINT32_C(3232469169), UINT32_C(4227707074), UINT32_C( 217310318), UINT32_C(2389231728), UINT32_C( 995471668), UINT32_C(  81736328),
      UINT32_C(1590073260), UINT32_C( 905888387), UINT32_C( 368421459), UINT32_C(3373331034), UINT32_C(1205142487), UINT32_C(  13974988), UINT32_C(2000366575), UINT32_C( 159128157),
      UINT32_C( 895959729), UINT32_C(1483367941), UINT32_C(1785552656), UINT32_C( 691240274), UINT32_C(1282410880), UINT32_C( 894190918), UINT32_C(3467478896), UINT32_C(1406609826),
      UINT32_C(1887977323), UINT32_C(3049845413), UINT32_C(2753508690), UINT32_C( 869094322) };
  static const uint32_t e[] =
    { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(2156986896), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(   1576336), UINT32_C( 407896371), UINT32_C(         0), UINT32_C(2152267905), UINT32_C(         0), UINT32_C(  12689442), UINT32_C( 271557410), UINT32_C(         0),
      UINT32_C(  33701960), UINT32_C(         0), UINT32_C( 143677464), UINT32_C(  76032070), UINT32_C(         0), UINT32_C(2147623297), UINT32_C(1996837128), UINT32_C(       648),
      UINT32_C( 268968835), UINT32_C( 777060353), UINT32_C(1215561762), UINT32_C(         0), UINT32_C( 706048064), UINT32_C(3725101072), UINT32_C(2454991051), UINT32_C( 153109762),
      UINT32_C(         0), UINT32_C( 429162896), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(2204122752), UINT32_C(         0), UINT32_C( 293621760),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(3422552139), UINT32_C(1082176524), UINT32_C(         0), UINT32_C( 137379904), UINT32_C( 542244864), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(3041663088), UINT32_C(2726399498), UINT32_C( 139329664), UINT32_C(  70141986), UINT32_C( 671096850), UINT32_C(2203148416), UINT32_C(3777502994),
      UINT32_C(         0), UINT32_C(1164751832), UINT32_C(  33558528), UINT32_C(         0), UINT32_C(         0), UINT32_C( 604160601), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(1086554656), UINT32_C(1915761545), UINT32_C(  90309762), UINT32_C(2250776960), UINT32_C( 572184742), UINT32_C(1076987546),
      UINT32_C(         0), UINT32_C(         0), UINT32_C( 840171792), UINT32_C(         0), UINT32_C(1411908428), UINT32_C(2852134976), UINT32_C( 945292290), UINT32_C(  71338212),
      UINT32_C( 167774352), UINT32_C(         0), UINT32_C(         0), UINT32_C(   6062744), UINT32_C(   4849716), UINT32_C(         0), UINT32_C(   4194336), UINT32_C(         0),
      UINT32_C(1096859652), UINT32_C(         0), UINT32_C(         0), UINT32_C(   3997700), UINT32_C(2734753920), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(1182023744), UINT32_C(         0), UINT32_C( 536890368), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 138420936), UINT32_C(         0), UINT32_C(2147707425), UINT32_C( 565203126), UINT32_C( 952382498),
      UINT32_C(         0), UINT32_C( 138677724), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(2161672904), UINT32_C(         0), UINT32_C( 290532864),
      UINT32_C(         0), UINT32_C( 287395840), UINT32_C(         0), UINT32_C(   4587994), UINT32_C(1678970496), UINT32_C(         0), UINT32_C( 843153571), UINT32_C(         0),
      UINT32_C(         0), UINT32_C( 942670465), UINT32_C( 268570626), UINT32_C(3221229613), UINT32_C(         0), UINT32_C(1493258240), UINT32_C(2659980800), UINT32_C( 201893912),
      UINT32_C( 536877318), UINT32_C(  73400843), UINT32_C(4163109824), UINT32_C(2193785902), UINT32_C( 576979008), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(   1663490), UINT32_C(2147969284), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 611347012), UINT32_C(  68526338), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(  24297480), UINT32_C(         0), UINT32_C(  67633537), UINT32_C(         0), UINT32_C( 134222016), UINT32_C(2786460970), UINT32_C( 170267013),
      UINT32_C(         0), UINT32_C( 352412160), UINT32_C(         0), UINT32_C(         0), UINT32_C(2550170328), UINT32_C( 807505928), UINT32_C( 449384464), UINT32_C(2332295200),
      UINT32_C(   1245224), UINT32_C(         0), UINT32_C( 177210020), UINT32_C(2291485200), UINT32_C(  18876205), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C( 304091206), UINT32_C( 169099722), UINT32_C( 671363084), UINT32_C(         0), UINT32_C(         0), UINT32_C(  34081304), UINT32_C( 550766086),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(  76555374), UINT32_C(  71829520), UINT32_C(         0), UINT32_C(         0),
      UINT32_C( 268472488), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(1480745985), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 319881472),
      UINT32_C(1082668064), UINT32_C(         0), UINT32_C(         0), UINT32_C( 302858496) };

  static uint32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t
      rv,
      av = simde_svld1_u32(pg, &(a[i])),
      bv = simde_svld1_u32(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_svand_u32_z(pv, av, bv);

    simde_svst1_u32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vu32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)];
  uint32_t a[1024 / sizeof(int32_t)], b[1024 / sizeof(int32_t)], e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_u32(pg, &(a[i]));
    bv = simde_svld1_u32(pg, &(b[i]));

    ev = simde_svand_u32_z(pv, av, bv);

    simde_svst1_u32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_u32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0) };
  static const uint32_t a[] =
    { UINT32_C(1626678061), UINT32_C(1762783989), UINT32_C(1194811130), UINT32_C(1559250464), UINT32_C(2711552421), UINT32_C(4197561146), UINT32_C(2145765871), UINT32_C(1895296066),
      UINT32_C(  97578000), UINT32_C(3647922911), UINT32_C(1612752192), UINT32_C(2445021420), UINT32_C(1261591313), UINT32_C(4265960207), UINT32_C(1853696556), UINT32_C( 668890391),
      UINT32_C(1076670305), UINT32_C(3508116369), UINT32_C( 741488960), UINT32_C(1522396745), UINT32_C(1504046922), UINT32_C(2119691090), UINT32_C( 753783829), UINT32_C(2874395465),
      UINT32_C( 199983226), UINT32_C(1541211419), UINT32_C(2290618174), UINT32_C(1206011389), UINT32_C(2275444789), UINT32_C(2282157939), UINT32_C( 364245964), UINT32_C( 968886462),
      UINT32_C(2739186824), UINT32_C(4026474929), UINT32_C( 779585328), UINT32_C(  24468172), UINT32_C(1435047650), UINT32_C(3655175949), UINT32_C(1089442434), UINT32_C( 595177371),
      UINT32_C( 214416987), UINT32_C( 285001439), UINT32_C( 423523149), UINT32_C(2937828301), UINT32_C(3607405769), UINT32_C(3048268339), UINT32_C( 267755380), UINT32_C(2855497551),
      UINT32_C( 213383725), UINT32_C( 219984832), UINT32_C(4096154150), UINT32_C(3617800462), UINT32_C( 414099685), UINT32_C(4274872202), UINT32_C(1292813310), UINT32_C(1610105138),
      UINT32_C(4218138427), UINT32_C(2282260578), UINT32_C(4034670306), UINT32_C(1439178864), UINT32_C(1382971080), UINT32_C(3562027989), UINT32_C( 807493374), UINT32_C(3666811295),
      UINT32_C( 718666696), UINT32_C(1706286467), UINT32_C(2086022924), UINT32_C( 399580751), UINT32_C(1785282452), UINT32_C(2034154107), UINT32_C(3098173208), UINT32_C(1100102009),
      UINT32_C(3077335092), UINT32_C(1360863045), UINT32_C(2664264526), UINT32_C( 632659857), UINT32_C(1502552030), UINT32_C(4057189849), UINT32_C(2796125485), UINT32_C(3957800118),
      UINT32_C(3919729572), UINT32_C(3241918322), UINT32_C(3277785138), UINT32_C(2263422119), UINT32_C( 215971891), UINT32_C(1946071622), UINT32_C(3860440879), UINT32_C(2278621411),
      UINT32_C(3329323860), UINT32_C(1703390259), UINT32_C(1546249908), UINT32_C( 786567931), UINT32_C(3493577098), UINT32_C(2739091828), UINT32_C(3297336544), UINT32_C(2974505565),
      UINT32_C(  24624334), UINT32_C( 493289320), UINT32_C(3766063077), UINT32_C( 739204001), UINT32_C(2432453148), UINT32_C(1664368771), UINT32_C(4180131228), UINT32_C(3869930264),
      UINT32_C(2565284399), UINT32_C( 112545057), UINT32_C(2129080029), UINT32_C(2779444873), UINT32_C(3275138880), UINT32_C(2200333031), UINT32_C(1065176615), UINT32_C(4028966849),
      UINT32_C(1787300937), UINT32_C( 930168154), UINT32_C(4105525355), UINT32_C(2392481870), UINT32_C(3998339079), UINT32_C(1634826042), UINT32_C(2258759365), UINT32_C(1601685014),
      UINT32_C( 768278483), UINT32_C(2825141053), UINT32_C(3785169299), UINT32_C(2154772345), UINT32_C(1097777159), UINT32_C(4255309879), UINT32_C(3833807822), UINT32_C(3712285194),
      UINT32_C( 923406074), UINT32_C(3705630281), UINT32_C(  29195399), UINT32_C(3129027763), UINT32_C( 603713772), UINT32_C(2652937936), UINT32_C(3951273185), UINT32_C(2563295134),
      UINT32_C( 516936405), UINT32_C(3371872064), UINT32_C(3754538795), UINT32_C(3482929891), UINT32_C( 183670074), UINT32_C( 346624819), UINT32_C(1426074807), UINT32_C(3371092211),
      UINT32_C(3689332123), UINT32_C(2560876652), UINT32_C(2054646935), UINT32_C(4048097463), UINT32_C(3640408997), UINT32_C(  99460430), UINT32_C(3294358993), UINT32_C(1351371189),
      UINT32_C(1932292614), UINT32_C(3909865298), UINT32_C(4083384892), UINT32_C( 954510482), UINT32_C( 907075815), UINT32_C(1446772101), UINT32_C(2686097130), UINT32_C(3874531039),
      UINT32_C(1784224792), UINT32_C( 676553964), UINT32_C(2015082214), UINT32_C(1253113698), UINT32_C(1702937056), UINT32_C(2847718334), UINT32_C( 826922578), UINT32_C(2501327229),
      UINT32_C(1107325014), UINT32_C(3127530452), UINT32_C(1815315722), UINT32_C(1689707396), UINT32_C(1674196644), UINT32_C(1141671666), UINT32_C(3648345436), UINT32_C(3832515982),
      UINT32_C(3525734397), UINT32_C(3431764162), UINT32_C(2587475733), UINT32_C(1207889827), UINT32_C( 413845542), UINT32_C(2874979918), UINT32_C(2592395531), UINT32_C(1551823710),
      UINT32_C( 623813986), UINT32_C(1274133045), UINT32_C( 501557882), UINT32_C(1080353562), UINT32_C(4200075180), UINT32_C(3517297861), UINT32_C(3832228485), UINT32_C(2151737629),
      UINT32_C(3299176078), UINT32_C(2718930472), UINT32_C(3686790337), UINT32_C(2199594199), UINT32_C(4169036595), UINT32_C(2898862887), UINT32_C(1804612685), UINT32_C(2901135390),
      UINT32_C(1735430206), UINT32_C(3876159270), UINT32_C(1271056755), UINT32_C( 550428141), UINT32_C(1998081104), UINT32_C(3173311088), UINT32_C( 875082774), UINT32_C(3286307717),
      UINT32_C(3391771043), UINT32_C(1152464081), UINT32_C(3935270141), UINT32_C(2718588497), UINT32_C( 437854890), UINT32_C( 467156228), UINT32_C(2001666290), UINT32_C(3074043924),
      UINT32_C(1400989058) };
  static const uint32_t b[] =
    { UINT32_C( 918159404), UINT32_C(1069252434), UINT32_C(1024031592), UINT32_C(1968559048), UINT32_C( 247227070), UINT32_C(3512768145), UINT32_C(2275711056), UINT32_C(2109422929),
      UINT32_C(2427745854), UINT32_C(1573875701), UINT32_C(2996558314), UINT32_C(1797779628), UINT32_C(3833193554), UINT32_C(3400915578), UINT32_C(3276888434), UINT32_C(3577810327),
      UINT32_C(2019947907), UINT32_C(1322595684), UINT32_C(3120590862), UINT32_C(3005556576), UINT32_C(2241306379), UINT32_C(3947842681), UINT32_C(1034920358), UINT32_C( 823324846),
      UINT32_C(1235843045), UINT32_C(3130490540), UINT32_C(1333106671), UINT32_C(3389168318), UINT32_C(2991561017), UINT32_C(2359205862), UINT32_C(4006169920), UINT32_C( 572513085),
      UINT32_C(4285253714), UINT32_C( 901317190), UINT32_C(1468346009), UINT32_C(  35751881), UINT32_C( 129331489), UINT32_C(1351832336), UINT32_C(3711851680), UINT32_C(2315214135),
      UINT32_C(1804102181), UINT32_C(  94454380), UINT32_C( 962340464), UINT32_C(3460071085), UINT32_C(4292211183), UINT32_C(3830409284), UINT32_C(4223765956), UINT32_C( 260423914),
      UINT32_C(2524581162), UINT32_C(3231390543), UINT32_C(4026136385), UINT32_C(1690121589), UINT32_C(1784910630), UINT32_C(3226383099), UINT32_C( 700124991), UINT32_C(4181213391),
      UINT32_C(2643440462), UINT32_C( 274541262), UINT32_C(2550093602), UINT32_C(3019685004), UINT32_C(1260216143), UINT32_C(1359703058), UINT32_C(1266402939), UINT32_C(1430565639),
      UINT32_C( 905106534), UINT32_C( 541413630), UINT32_C( 867714215), UINT32_C(1357296640), UINT32_C( 630916115), UINT32_C(3950487152), UINT32_C(1932980844), UINT32_C( 214465445),
      UINT32_C(1296153423), UINT32_C(2993587723), UINT32_C(3404015306), UINT32_C(3977956570), UINT32_C(1075033552), UINT32_C(3358296667), UINT32_C( 557539964), UINT32_C( 741147869),
      UINT32_C(3396955839), UINT32_C(3195856884), UINT32_C(3884540173), UINT32_C(4258636589), UINT32_C(3023956057), UINT32_C(4001130866), UINT32_C(2819602635), UINT32_C(2077507004),
      UINT32_C(2688896427), UINT32_C(1113506101), UINT32_C(1344988962), UINT32_C(3830316939), UINT32_C(1503169511), UINT32_C(3209106932), UINT32_C(2305251021), UINT32_C(1057242003),
      UINT32_C(3185527176), UINT32_C( 738213130), UINT32_C(2960927269), UINT32_C( 278186537), UINT32_C(1231629397), UINT32_C( 235450433), UINT32_C(2593615622), UINT32_C( 853121962),
      UINT32_C(4008753380), UINT32_C( 438038773), UINT32_C(1137350426), UINT32_C(3058916961), UINT32_C(3439312011), UINT32_C(1926956908), UINT32_C( 537686646), UINT32_C(4065584398),
      UINT32_C(2481013661), UINT32_C(1303247923), UINT32_C(4119885971), UINT32_C(1638654934), UINT32_C( 187607967), UINT32_C( 696060338), UINT32_C(2303298171), UINT32_C( 226270319),
      UINT32_C( 312499679), UINT32_C(3965668697), UINT32_C(2632052677), UINT32_C(1912442322), UINT32_C(3934006072), UINT32_C(2954099252), UINT32_C(4080622980), UINT32_C(3640702457),
      UINT32_C(1810604050), UINT32_C(3008908270), UINT32_C( 223295802), UINT32_C(4269690310), UINT32_C(2917792632), UINT32_C(2036202741), UINT32_C(1399625305), UINT32_C(1579969868),
      UINT32_C(4224325389), UINT32_C(2645500514), UINT32_C( 581631579), UINT32_C(3290441803), UINT32_C( 410061091), UINT32_C(1603390982), UINT32_C(2964520548), UINT32_C(2014305899),
      UINT32_C(1484052982), UINT32_C(1458906107), UINT32_C(1836621601), UINT32_C(3945896392), UINT32_C(2818876066), UINT32_C(3557332336), UINT32_C(4270176915), UINT32_C(2406978713),
      UINT32_C(1760029549), UINT32_C( 801037582), UINT32_C(1151088508), UINT32_C(1915801040), UINT32_C(3743102063), UINT32_C(1572086729), UINT32_C(1985690077), UINT32_C( 973460173),
      UINT32_C(3416452541), UINT32_C(1190879434), UINT32_C(1737201559), UINT32_C(3571104613), UINT32_C(3098867183), UINT32_C(4111820824), UINT32_C(1852600737), UINT32_C(  27816259),
      UINT32_C( 684477022), UINT32_C(1114621866), UINT32_C(3299474015), UINT32_C(2761458613), UINT32_C(2421967992), UINT32_C(1434874548), UINT32_C( 650375907), UINT32_C(3257363299),
      UINT32_C(1626010805), UINT32_C( 446847419), UINT32_C( 148786003), UINT32_C(1202485199), UINT32_C(2027424195), UINT32_C(1590517371), UINT32_C(3011809616), UINT32_C(2994056444),
      UINT32_C(1527931040), UINT32_C( 225883321), UINT32_C(3457504511), UINT32_C(2400633547), UINT32_C(1174925003), UINT32_C(2628047948), UINT32_C(1649354853), UINT32_C(1947518420),
      UINT32_C(3738183205), UINT32_C(3656074970), UINT32_C(1722286490), UINT32_C(2398469827), UINT32_C(4174707884), UINT32_C( 915699920), UINT32_C(1972954016), UINT32_C(3454643368),
      UINT32_C(2897000914), UINT32_C(2592446463), UINT32_C(1526738328), UINT32_C(2548692459), UINT32_C(3247422961), UINT32_C(3606520629), UINT32_C(2940964615), UINT32_C( 226309179),
      UINT32_C(3988335086), UINT32_C(1502035904), UINT32_C(1488226156), UINT32_C(1844420220), UINT32_C(2435809115), UINT32_C(2842109602), UINT32_C(4049187510), UINT32_C(3573536486),
      UINT32_C(3217209599) };
  static const uint32_t e[] =
    { UINT32_C(1626678061), UINT32_C( 689009232), UINT32_C(1194811130), UINT32_C(1414545920), UINT32_C(  10223780), UINT32_C(3491795472), UINT32_C( 128223296), UINT32_C(1890790464),
      UINT32_C(   9462800), UINT32_C(1498309333), UINT32_C(1612752192), UINT32_C(2445021420), UINT32_C(1261591313), UINT32_C(4265960207), UINT32_C(1112606752), UINT32_C(  88081687),
      UINT32_C(1076670305), UINT32_C(1074860288), UINT32_C( 741488960), UINT32_C( 304424512), UINT32_C(  25530122), UINT32_C(1783056464), UINT32_C( 753783829), UINT32_C(2874395465),
      UINT32_C( 162070624), UINT32_C(1541211419), UINT32_C(2290618174), UINT32_C(1206011389), UINT32_C(2181072945), UINT32_C(2282157939), UINT32_C( 364245964), UINT32_C( 536873020),
      UINT32_C(2739186824), UINT32_C(4026474929), UINT32_C( 100992528), UINT32_C(   2163400), UINT32_C(1435047650), UINT32_C(1351680768), UINT32_C(1089442434), UINT32_C(  24710419),
      UINT32_C( 142617089), UINT32_C( 285001439), UINT32_C( 421274176), UINT32_C(2383950477), UINT32_C(3607404745), UINT32_C(2751488000), UINT32_C( 197233988), UINT32_C(2855497551),
      UINT32_C(  70387752), UINT32_C(   1577792), UINT32_C(3827323392), UINT32_C(3617800462), UINT32_C( 136478756), UINT32_C(4274872202), UINT32_C(1292813310), UINT32_C(1496858626),
      UINT32_C(2567676682), UINT32_C(    526402), UINT32_C(2424047138), UINT32_C(1439178864), UINT32_C(1108104776), UINT32_C(1342187536), UINT32_C( 807493374), UINT32_C(1342443783),
      UINT32_C( 718666696), UINT32_C(1706286467), UINT32_C(2086022924), UINT32_C( 281023488), UINT32_C( 537461776), UINT32_C(2034154107), UINT32_C(3098173208), UINT32_C(1100102009),
      UINT32_C(  88090628), UINT32_C(1360863045), UINT32_C(2328175178), UINT32_C( 621841552), UINT32_C(1073944016), UINT32_C(4057189849), UINT32_C(2796125485), UINT32_C( 673514644),
      UINT32_C(3919729572), UINT32_C(3241918322), UINT32_C(3272146944), UINT32_C(2263422119), UINT32_C( 215971891), UINT32_C(1652301890), UINT32_C(3860440879), UINT32_C(2278621411),
      UINT32_C(2151760128), UINT32_C(1074167857), UINT32_C(1546249908), UINT32_C( 786567931), UINT32_C(1343783298), UINT32_C(2739091828), UINT32_C(2147570880), UINT32_C(2974505565),
      UINT32_C(  22481032), UINT32_C( 201342216), UINT32_C(2692221477), UINT32_C( 739204001), UINT32_C(   6817812), UINT32_C(  33554433), UINT32_C(2550607108), UINT32_C( 579343112),
      UINT32_C(2565284399), UINT32_C(  34684961), UINT32_C(2129080029), UINT32_C(2751616513), UINT32_C(3224806400), UINT32_C(2200333031), UINT32_C(1065176615), UINT32_C(4026606848),
      UINT32_C(1787300937), UINT32_C(  86064146), UINT32_C(4105525355), UINT32_C(2392481870), UINT32_C(3998339079), UINT32_C( 561054002), UINT32_C(2258759365), UINT32_C( 225739782),
      UINT32_C( 768278483), UINT32_C(2823031065), UINT32_C(2155940225), UINT32_C(   7144784), UINT32_C(1080819712), UINT32_C(4255309879), UINT32_C(3758178692), UINT32_C(3640700936),
      UINT32_C( 587857938), UINT32_C(2421705288), UINT32_C(  17643522), UINT32_C(3120565378), UINT32_C( 603713772), UINT32_C(2652937936), UINT32_C(3951273185), UINT32_C( 403195148),
      UINT32_C( 449450501), UINT32_C(2292851264), UINT32_C(  42513931), UINT32_C(3288336451), UINT32_C( 183670074), UINT32_C( 343998978), UINT32_C( 268446756), UINT32_C(1208928355),
      UINT32_C(1482987922), UINT32_C(2560876652), UINT32_C(1752173569), UINT32_C(3774943360), UINT32_C(2281972384), UINT32_C(  99460430), UINT32_C(3294358993), UINT32_C(    262289),
      UINT32_C(1612997124), UINT32_C( 688573698), UINT32_C(4083384892), UINT32_C( 954510482), UINT32_C( 370155623), UINT32_C(1412440449), UINT32_C( 538579144), UINT32_C(3874531039),
      UINT32_C(1241517080), UINT32_C( 676553964), UINT32_C(1611372166), UINT32_C(1083226976), UINT32_C( 545309152), UINT32_C(2702452760), UINT32_C( 541609984), UINT32_C(  16789825),
      UINT32_C(     16470), UINT32_C(3127530452), UINT32_C(1143046154), UINT32_C(1689707396), UINT32_C(1674196644), UINT32_C(1141113520), UINT32_C(3648345436), UINT32_C(3832515982),
      UINT32_C(3525734397), UINT32_C( 142610562), UINT32_C(2587475733), UINT32_C(1202481027), UINT32_C( 413845542), UINT32_C(2874979918), UINT32_C(2592395531), UINT32_C( 276078684),
      UINT32_C( 623813986), UINT32_C( 158380081), UINT32_C( 501557882), UINT32_C(1080353562), UINT32_C(1107299976), UINT32_C(3517297861), UINT32_C(1615538181), UINT32_C(     49428),
      UINT32_C(3299176078), UINT32_C(2148206088), UINT32_C(1118306432), UINT32_C(2199594199), UINT32_C(4166283296), UINT32_C(2898862887), UINT32_C(1636835328), UINT32_C(2364112904),
      UINT32_C(1735430206), UINT32_C(2181109542), UINT32_C(1258293520), UINT32_C( 550428141), UINT32_C(1091046480), UINT32_C(2485396016), UINT32_C( 604537862), UINT32_C(3286307717),
      UINT32_C(3358065058), UINT32_C(1152464081), UINT32_C(3935270141), UINT32_C(2718588497), UINT32_C( 269033994), UINT32_C( 155198464), UINT32_C(2001666290), UINT32_C(3074043924),
      UINT32_C(1400989058) };

  static uint32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t
      rv,
      av = simde_svld1_u32(pg, &(a[i])),
      bv = simde_svld1_u32(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_svand_u32_m(pv, av, bv);

    simde_svst1_u32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vu32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)];
  uint32_t a[1024 / sizeof(int32_t)], b[1024 / sizeof(int32_t)], e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_u32(pg, &(a[i]));
    bv = simde_svld1_u32(pg, &(b[i]));

    ev = simde_svand_u32_m(pv, av, bv);

    simde_svst1_u32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_u64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1) };
  static const uint64_t a[] =
    { UINT64_C(11897122862462087975), UINT64_C( 2296171473860360793), UINT64_C( 8865473458257458354), UINT64_C(10066392223984415985),
      UINT64_C( 6417445852343627317), UINT64_C( 4124287387801740115), UINT64_C(13978003158988640861), UINT64_C( 9960339864598172491),
      UINT64_C( 2631232279211702314), UINT64_C(15467470505233158375), UINT64_C(10980147859861960400), UINT64_C( 5874243293399214757),
      UINT64_C( 7273313938488195834), UINT64_C( 9250247053992407312), UINT64_C(12526060910497806064), UINT64_C(10944924248739159148),
      UINT64_C( 8181443345481162920), UINT64_C(14318168991375973508), UINT64_C(14106919272089637904), UINT64_C( 4911521312768683764),
      UINT64_C( 7236145369605311642), UINT64_C(15054773517534389840), UINT64_C(13635401902629384224), UINT64_C( 7276543534512967707),
      UINT64_C(12126445954825872645), UINT64_C( 5602684841948602672), UINT64_C( 8157142993099597996), UINT64_C(  125015551593972366),
      UINT64_C( 1552105685966527369), UINT64_C(13946175891114907920), UINT64_C(15867142794359820141), UINT64_C(  714367551868787948),
      UINT64_C( 1010623804720467724), UINT64_C( 4441910225620634573), UINT64_C( 3552833529417030436), UINT64_C( 9158072535455728271),
      UINT64_C( 4962252621385564881), UINT64_C( 2490151937126115457), UINT64_C( 5772738144891080358), UINT64_C(  745476824361809509),
      UINT64_C(13850177714299455609), UINT64_C(14771982870848363743), UINT64_C(15870637223464965166), UINT64_C(10325922806100172298),
      UINT64_C(13678756829855688405), UINT64_C(13043720326315959824), UINT64_C(11205770137068485679), UINT64_C( 1740407350329489027),
      UINT64_C( 7848648642233411410), UINT64_C( 5774644008762705895), UINT64_C( 3499711073994852452), UINT64_C(17080729089339846575),
      UINT64_C( 2116139006505531031), UINT64_C( 1009562414142390928), UINT64_C( 2329651220425537655), UINT64_C(11856882763788590340),
      UINT64_C( 4802796199781771602), UINT64_C( 6390596741400572407), UINT64_C( 5584412171732562926), UINT64_C(18419574789131506158),
      UINT64_C( 2384142714716763426), UINT64_C(17120278949084137823), UINT64_C(15257012348906116133), UINT64_C( 4758172990687848284),
      UINT64_C( 2084652871220367266), UINT64_C( 5197984252483580214), UINT64_C(10790467725801451015), UINT64_C(11276071160667606297),
      UINT64_C(17658148770395296309), UINT64_C( 7238494464147876361), UINT64_C(13080722284469038010), UINT64_C(   86249869323216540),
      UINT64_C(18280395612638977277), UINT64_C(16225797826690014060), UINT64_C( 2889723868985195976), UINT64_C( 8237349200300214658),
      UINT64_C(12934021773274268813), UINT64_C(  992105030779447227), UINT64_C( 8708990766349981991), UINT64_C( 1836367538792340374),
      UINT64_C( 5067702468689439578), UINT64_C(11678096041578188991), UINT64_C(11958237952667452039), UINT64_C( 3202671562678320077),
      UINT64_C(16404398082857176279), UINT64_C( 5120302232199746289), UINT64_C( 7218910209417372794), UINT64_C(16172479078253583731) };
  static const uint64_t b[] =
    { UINT64_C(10565150879178933830), UINT64_C( 7429560120294616974), UINT64_C(11679900081139746720), UINT64_C(14157597032599743031),
      UINT64_C(15707115463907694249), UINT64_C( 5010488391150111889), UINT64_C( 8915457396507864539), UINT64_C( 9420869450647532923),
      UINT64_C( 8295883273648406780), UINT64_C( 9825761116277823857), UINT64_C(16413749716675745290), UINT64_C(11001055410762085967),
      UINT64_C(17144922836798838425), UINT64_C(12397953075346965721), UINT64_C( 6341565289472962231), UINT64_C( 1220241811298115002),
      UINT64_C(12189691471452753857), UINT64_C( 4993997819127737856), UINT64_C(14433303495713245676), UINT64_C(13459305427088952643),
      UINT64_C(15083999711381116381), UINT64_C(12620143627817157967), UINT64_C( 3522362384220194571), UINT64_C(16965819622071271615),
      UINT64_C(15828725025253911048), UINT64_C(16926177625779019122), UINT64_C( 4215901944486791524), UINT64_C( 2801067573057317605),
      UINT64_C(15507488239920314318), UINT64_C( 3355447575062572743), UINT64_C( 6714867563941041019), UINT64_C( 6173924394030604907),
      UINT64_C( 2297649826716692134), UINT64_C( 6614476000426651346), UINT64_C(13168385996226644714), UINT64_C(16536915737281695651),
      UINT64_C(16362371370739314075), UINT64_C( 1872454213024405697), UINT64_C( 8184794032996306325), UINT64_C( 6732346816271668553),
      UINT64_C(17454652744879070790), UINT64_C(11278015149586496315), UINT64_C( 9303050589363306204), UINT64_C( 1515312628644885992),
      UINT64_C(17652325727102392278), UINT64_C(17800162085093411940), UINT64_C( 9122529873043227615), UINT64_C(17389857330248065906),
      UINT64_C(14930825207088792198), UINT64_C( 6021946521295622783), UINT64_C( 7122166766048588739), UINT64_C(13021023827375882151),
      UINT64_C( 2230451279945247930), UINT64_C( 3567214216944823994), UINT64_C(10939351180157578366), UINT64_C( 2684723079172158048),
      UINT64_C( 1690608380269966777), UINT64_C(17801821653760814957), UINT64_C( 6285677042640197299), UINT64_C( 6572765753930781864),
      UINT64_C( 3373243132433105500), UINT64_C(10361117930880046425), UINT64_C( 1006956274974338987), UINT64_C( 7061176947486744066),
      UINT64_C( 3875606812063150809), UINT64_C(10478981222465261825), UINT64_C( 1041224370618605057), UINT64_C(14010892955786777098),
      UINT64_C( 8679321001439038306), UINT64_C( 5579046574246689525), UINT64_C(15382368657387790175), UINT64_C( 4423755135803730872),
      UINT64_C(15839141083267973600), UINT64_C( 4972294933080056936), UINT64_C(10620379464454943938), UINT64_C( 9038048927600166997),
      UINT64_C( 4475351894840436826), UINT64_C(13255207460025913801), UINT64_C( 2528393845734220969), UINT64_C( 4542936741284367344),
      UINT64_C( 5601521930390724776), UINT64_C( 5555172154665643884), UINT64_C(17691519246520048787), UINT64_C( 4564273526949009202),
      UINT64_C(15942877310713976430), UINT64_C(13770412457254009897), UINT64_C(  336826396563270577), UINT64_C( 3121966222621290364) };
  static const uint64_t e[] =
    { UINT64_C(                   0), UINT64_C(  511441682262174216), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(   74380333852164113), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 9224528899281588321), UINT64_C( 9241758366647211520), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C( 2380806887982514304), UINT64_C( 4901071457853508608), UINT64_C(13854550223457632256), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 9232731904565838912), UINT64_C( 3467949598031511552), UINT64_C( 6949671096963104795),
      UINT64_C( 9802304528896778240), UINT64_C( 5242361546722050352), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(  119382226047598696),
      UINT64_C( 1009479595632266756), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 5770275234356661380), UINT64_C(                   0),
      UINT64_C(13848887924337166400), UINT64_C(                   0), UINT64_C( 9230989662426272780), UINT64_C(  361704158379676680),
      UINT64_C(                   0), UINT64_C(13043691171717219328), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 5765170610596577895), UINT64_C( 2346657569396883520), UINT64_C(11818272301177139111),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 2594086616248094720),
      UINT64_C(  154869580160966928), UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 6563751957606207656),
      UINT64_C(                   0), UINT64_C(10196731043701064025), UINT64_C(  124211163440350241), UINT64_C(                   0),
      UINT64_C( 1497491528863613568), UINT64_C(                   0), UINT64_C(  302620820376784385), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 4928134587546102273), UINT64_C(                   0), UINT64_C(   81137122737922712),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(     572330238555328), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(  414507382361588105), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C( 4905572832686809096), UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 3193628902962729728),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 2328413822632332656) };

  static uint64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t
      rv,
      av = simde_svld1_u64(pg, &(a[i])),
      bv = simde_svld1_u64(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_svand_u64_z(pv, av, bv);

    simde_svst1_u64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vu64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)];
  uint64_t a[1024 / sizeof(int64_t)], b[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_u64(pg, &(a[i]));
    bv = simde_svld1_u64(pg, &(b[i]));

    ev = simde_svand_u64_z(pv, av, bv);

    simde_svst1_u64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svand_u64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1) };
  static const uint64_t a[] =
    { UINT64_C( 4120469612070481998), UINT64_C(  650191952202805669), UINT64_C(15301226378054953940), UINT64_C( 7627278196972780319),
      UINT64_C(10933200521000393017), UINT64_C( 6801376109697079096), UINT64_C( 3596688425298244035), UINT64_C( 5800907998597385980),
      UINT64_C(10924197086342797328), UINT64_C(  507311661480340514), UINT64_C(12738720393710056326), UINT64_C(17220999571841738645),
      UINT64_C( 8869430832179301919), UINT64_C(16484073344059508856), UINT64_C( 8883427121691418852), UINT64_C( 8572924417144262444),
      UINT64_C(17277791098155428595), UINT64_C(  384617003340263188), UINT64_C( 5022048051147952975), UINT64_C(17420566565661694453),
      UINT64_C(15463114554686158643), UINT64_C(  151327653981865203), UINT64_C(10578929808748033650), UINT64_C(11146585445203058625),
      UINT64_C(16568985961460198743), UINT64_C( 5320179252991703072), UINT64_C(13256244302559055305), UINT64_C(14754961663349675458),
      UINT64_C(  426952343844947988), UINT64_C(13920537357273654542), UINT64_C( 7595354477140771771), UINT64_C( 1888512399021170419),
      UINT64_C(   21124853639682912), UINT64_C(10280334570031555826), UINT64_C(16368798968819208473), UINT64_C( 8477323803126185349),
      UINT64_C(14163265379534357917), UINT64_C(11784329828447974442), UINT64_C(17797535715545041194), UINT64_C( 7481647531580016969),
      UINT64_C(13799456511911956459), UINT64_C(12909082934043684857), UINT64_C( 6878907674559088911), UINT64_C(  596042083156752147),
      UINT64_C(13291327288991169312), UINT64_C( 9633869716615016567), UINT64_C( 6656174327740071914), UINT64_C(14886788955977161842),
      UINT64_C( 2031959771489525434), UINT64_C(13341015387284466984), UINT64_C( 1726031656683907406), UINT64_C( 7471823272865639989),
      UINT64_C( 6223713199949100445), UINT64_C(10882976302205598592), UINT64_C( 1152679452718645826), UINT64_C( 9396097505310189137),
      UINT64_C(15590937820997633497), UINT64_C(12573820829439579038), UINT64_C( 2511765945502314225), UINT64_C( 5450065224283508283),
      UINT64_C( 2953149187527763659), UINT64_C( 4836461729289347588), UINT64_C( 9525933761364997182), UINT64_C(11778679769676403640),
      UINT64_C( 9106209702232377773), UINT64_C( 4501361022601162979), UINT64_C( 3066812193766803393), UINT64_C( 2832986793842062292),
      UINT64_C(13514103842490160787), UINT64_C( 5146603399683275053), UINT64_C( 1120235477972138735), UINT64_C( 4446474133776949012),
      UINT64_C(18354093524435800866), UINT64_C(18310957754231793232), UINT64_C( 7178151008493596242), UINT64_C( 9777779220681939402),
      UINT64_C( 2560077394379734201), UINT64_C(11307437275496428510), UINT64_C(   15418687027301252), UINT64_C( 9659136865440376608),
      UINT64_C(11896425296469986850), UINT64_C(12335779562822701386), UINT64_C( 4756000364145105866), UINT64_C(13488796115411629277),
      UINT64_C( 2580220467267780962), UINT64_C(12226404232403116249), UINT64_C(13666922800486099781), UINT64_C(12137932470408999197),
      UINT64_C(14183418436139426522) };
  static const uint64_t b[] =
    { UINT64_C(13214734057245219122), UINT64_C(  183551915486387027), UINT64_C(10332596207607161146), UINT64_C( 9133392729081233441),
      UINT64_C(10971373722350459886), UINT64_C(   18794803734620865), UINT64_C( 2231258726325631975), UINT64_C( 4579802728422374853),
      UINT64_C( 4013565394312384725), UINT64_C(10987861362825751734), UINT64_C(16650080651361394165), UINT64_C(11062677712244574965),
      UINT64_C( 1334305035730047190), UINT64_C(12293995429884853075), UINT64_C( 9958492958264958249), UINT64_C( 9805840183467256759),
      UINT64_C( 9445552756725434791), UINT64_C(15686922265554297940), UINT64_C(12889961820498186178), UINT64_C(12807185151439057794),
      UINT64_C( 4449496960448368652), UINT64_C( 3312390289419028078), UINT64_C(17723466028803169096), UINT64_C( 8346548240558662681),
      UINT64_C(13879089451720738934), UINT64_C( 2543643026666742452), UINT64_C( 5861817782960050672), UINT64_C(16022199339232559744),
      UINT64_C( 3234668063097686481), UINT64_C( 9780015838345806267), UINT64_C(18226423369499811689), UINT64_C( 9226818658702223046),
      UINT64_C(15991023485222930760), UINT64_C( 4063984985067173705), UINT64_C( 6540575299205615947), UINT64_C( 3341553167845861424),
      UINT64_C(15338373626234536925), UINT64_C(14345964257348374288), UINT64_C(16886900715884048491), UINT64_C( 6057104519190930170),
      UINT64_C(16684482947576036652), UINT64_C(14106081456640441984), UINT64_C(11417220593549005262), UINT64_C(10433589523869809663),
      UINT64_C(14936982352537526156), UINT64_C(13703483829888160016), UINT64_C(  873901791086374878), UINT64_C(13396323423760850933),
      UINT64_C( 1336274975889043564), UINT64_C(13990336466408658552), UINT64_C( 2067262350385507991), UINT64_C(17071561242179875331),
      UINT64_C(16619184699405240206), UINT64_C( 6787336708050329226), UINT64_C(15936183931007825380), UINT64_C( 9967022312753372644),
      UINT64_C(13282450303352568064), UINT64_C(18230948534195495900), UINT64_C(11062021240990008269), UINT64_C(10112076004450014158),
      UINT64_C(  733609750779555912), UINT64_C( 8721694207333192946), UINT64_C( 1225159708027916977), UINT64_C(10758872244879687223),
      UINT64_C(10005091375651703201), UINT64_C(16695862195045894030), UINT64_C(12611571509099353008), UINT64_C(12911470566840656203),
      UINT64_C(   84824520212494603), UINT64_C( 1369074912529728482), UINT64_C(16566221411786771649), UINT64_C( 2859975003892243179),
      UINT64_C( 8095775095433933541), UINT64_C( 4841237117357561019), UINT64_C( 3049890496747680980), UINT64_C( 7134221319757418941),
      UINT64_C( 9225929245782166539), UINT64_C(17109117917898576553), UINT64_C(  894720230886730496), UINT64_C( 8458296021907575424),
      UINT64_C(15850164014283627699), UINT64_C( 7039537850517787818), UINT64_C( 4376666214129208418), UINT64_C( 4430587150554801052),
      UINT64_C( 5603793656356375479), UINT64_C(11746163265754942273), UINT64_C( 5387733065761334222), UINT64_C( 5944133145586696117),
      UINT64_C( 2326390544994611800) };
  static const uint64_t e[] =
    { UINT64_C( 4120469612070481998), UINT64_C(    1145839834140929), UINT64_C( 9529827917778460944), UINT64_C( 7627278196972780319),
      UINT64_C(10376863365514402088), UINT64_C( 6801376109697079096), UINT64_C( 3596688425298244035), UINT64_C( 1189146087980174532),
      UINT64_C( 1698429174978465808), UINT64_C(  507311661480340514), UINT64_C(12738720393710056326), UINT64_C(17220999571841738645),
      UINT64_C( 1298167369879797782), UINT64_C(16484073344059508856), UINT64_C( 8883427121691418852), UINT64_C( 8572924417144262444),
      UINT64_C(17277791098155428595), UINT64_C(   77163863484900372), UINT64_C( 5022048051147952975), UINT64_C(17420566565661694453),
      UINT64_C(15463114554686158643), UINT64_C(  151327653981865203), UINT64_C(10578929808748033650), UINT64_C( 1337745454158840833),
      UINT64_C(16568985961460198743), UINT64_C( 5320179252991703072), UINT64_C(13256244302559055305), UINT64_C(14754961663349675458),
      UINT64_C(  351509903181088784), UINT64_C(13920537357273654542), UINT64_C( 7521013734037390121), UINT64_C(    1152310340241090),
      UINT64_C(   21124853639682912), UINT64_C(10280334570031555826), UINT64_C( 4755944713173356809), UINT64_C( 8477323803126185349),
      UINT64_C(14163265379534357917), UINT64_C( 9440134203852342272), UINT64_C(16309786257117069354), UINT64_C( 7481647531580016969),
      UINT64_C(13799456511911956459), UINT64_C( 9440184771302076032), UINT64_C( 2193824771030974734), UINT64_C(  596042083156752147),
      UINT64_C( 9817919820417866496), UINT64_C( 9633869716615016567), UINT64_C(  864753834978013130), UINT64_C( 9838198237515881584),
      UINT64_C( 2031959771489525434), UINT64_C(13341015387284466984), UINT64_C( 1490691637788026886), UINT64_C( 7471823272865639989),
      UINT64_C( 6223713199949100445), UINT64_C(10882976302205598592), UINT64_C(  948046041310183488), UINT64_C( 9385960001207698496),
      UINT64_C(10976435609664504064), UINT64_C(12394195383128294300), UINT64_C( 2511765945502314225), UINT64_C(  576466249863692810),
      UINT64_C(  588282744850767944), UINT64_C( 4836461729289347588), UINT64_C(     176201033322544), UINT64_C( 9315133188542321200),
      UINT64_C(  745628416014961057), UINT64_C( 4501361022601162979), UINT64_C( 3066812193766803393), UINT64_C( 2832986793842062292),
      UINT64_C(13514103842490160787), UINT64_C(  174628834907275552), UINT64_C(  397161304344824001), UINT64_C( 4446474133776949012),
      UINT64_C( 8075183381531005472), UINT64_C(18310957754231793232), UINT64_C( 7178151008493596242), UINT64_C(  216595429714841992),
      UINT64_C(     299894103526409), UINT64_C(11307437275496428510), UINT64_C(   15418687027301252), UINT64_C( 9659136865440376608),
      UINT64_C( 9299950824669056034), UINT64_C( 2391822759085871114), UINT64_C(        146030987330), UINT64_C(13488796115411629277),
      UINT64_C( 2580220467267780962), UINT64_C(12226404232403116249), UINT64_C(13666922800486099781), UINT64_C(   31675830488822037),
      UINT64_C(   18190095724126808) };

  static uint64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t
      rv,
      av = simde_svld1_u64(pg, &(a[i])),
      bv = simde_svld1_u64(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_svand_u64_m(pv, av, bv);

    simde_svst1_u64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vu64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)];
  uint64_t a[1024 / sizeof(int64_t)], b[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_u64(pg, &(a[i]));
    bv = simde_svld1_u64(pg, &(b[i]));

    ev = simde_svand_u64_m(pv, av, bv);

    simde_svst1_u64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), e);
  printf("Length: %d\n", len);

  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(svand_s8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_s8_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_s16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_s16_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_s32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_s32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_s64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_s64_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_u8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_u8_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_u16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_u16_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_u32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_u32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_u64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svand_u64_m)
SIMDE_TEST_FUNC_LIST_END

#include "test-sve-footer.h"
