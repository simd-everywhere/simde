#define SIMDE_TEST_ARM_SVE_INSN sel

#include "test-sve.h"
#include "../../../simde/arm/sve/sel.h"

#include "../../../simde/arm/sve/cmplt.h"
#include "../../../simde/arm/sve/dup.h"

static int
test_simde_x_svsel_s8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) };
  static const int8_t a[] =
    {  INT8_C(  88),  INT8_C(  61),  INT8_C( 108),  INT8_C(  80), -INT8_C(  81),  INT8_C(  52), -INT8_C(  35),  INT8_C( 118),
      -INT8_C( 104), -INT8_C(   9),  INT8_C(  93),  INT8_C( 121), -INT8_C(  10),  INT8_C( 124),  INT8_C(   0),  INT8_C( 114),
      -INT8_C(  89),  INT8_C( 123), -INT8_C(  34),  INT8_C(  88), -INT8_C(  70), -INT8_C(  65),  INT8_C(  44),  INT8_C(  63),
      -INT8_C(  83), -INT8_C(  59),  INT8_C(   0), -INT8_C(  32), -INT8_C(  95),  INT8_C(  15),  INT8_C(  96), -INT8_C(   6),
       INT8_C(  76), -INT8_C(  52),  INT8_C(  74), -INT8_C(   5),  INT8_C(   0),  INT8_C(  40),  INT8_C( 113), -INT8_C( 103),
       INT8_C(  31), -INT8_C(  50),  INT8_C(  18),  INT8_C(  22),  INT8_C(  74),  INT8_C(  18), -INT8_C( 120), -INT8_C(  14),
      -INT8_C( 114),  INT8_C( 102),  INT8_C(  74),  INT8_C(  72),  INT8_C(  37),  INT8_C( 118), -INT8_C( 121), -INT8_C(  46),
       INT8_C(  59), -INT8_C( 120), -INT8_C(  77), -INT8_C(  35), -INT8_C( 105),  INT8_C(  19), -INT8_C(  41), -INT8_C(  28),
      -INT8_C(  33),  INT8_C(  33), -INT8_C(  33), -INT8_C(  33),  INT8_C(  73),  INT8_C(  81),  INT8_C( 120),  INT8_C( 105),
       INT8_C(  31), -INT8_C( 117),      INT8_MAX,  INT8_C( 106), -INT8_C(  99),  INT8_C(   7),  INT8_C(  92),  INT8_C(  43),
       INT8_C( 109), -INT8_C(  90),  INT8_C( 115), -INT8_C( 110),  INT8_C(  28), -INT8_C(   5),  INT8_C( 101),  INT8_C(  87),
      -INT8_C( 125),  INT8_C(  24),  INT8_C(  52),  INT8_C(  26),  INT8_C(  43),  INT8_C(  11), -INT8_C(   2),  INT8_C(  10),
       INT8_C(  45), -INT8_C(  34), -INT8_C(  23),  INT8_C( 118),  INT8_C(  47),  INT8_C(  98), -INT8_C(  33),  INT8_C(  78),
      -INT8_C(  19),  INT8_C(  94), -INT8_C(  72), -INT8_C( 118),  INT8_C( 101),  INT8_C(  20), -INT8_C(  74), -INT8_C(  46),
      -INT8_C(  70),  INT8_C(  41),  INT8_C( 101), -INT8_C(  42),  INT8_C(  36), -INT8_C(  54),  INT8_C(  46), -INT8_C(  89),
      -INT8_C(  30),  INT8_C(  98), -INT8_C(  62),  INT8_C(  13),  INT8_C( 110), -INT8_C(  64),  INT8_C(  23), -INT8_C( 101),
      -INT8_C(  98),  INT8_C(   0),  INT8_C(  17), -INT8_C(  51),  INT8_C(  98), -INT8_C(  15),  INT8_C(  28),  INT8_C(  79),
       INT8_C(  79), -INT8_C(  44), -INT8_C(  38), -INT8_C(  75), -INT8_C(  23), -INT8_C( 112), -INT8_C( 121), -INT8_C(  93),
      -INT8_C(  71), -INT8_C(  20),  INT8_C( 122), -INT8_C(  34), -INT8_C(  74), -INT8_C(  88), -INT8_C( 123), -INT8_C( 104),
       INT8_C(  10),  INT8_C(  71), -INT8_C(  91),  INT8_C( 120),  INT8_C(   8), -INT8_C(  68),  INT8_C(  19), -INT8_C(  90),
      -INT8_C(  67),  INT8_C(  37),  INT8_C( 116),  INT8_C(  31),  INT8_C(  22), -INT8_C( 112),  INT8_C( 111),  INT8_C( 101),
       INT8_C( 100),  INT8_C(  73),  INT8_C(  26),  INT8_C(  77), -INT8_C(  39), -INT8_C(  94), -INT8_C(  15), -INT8_C( 110),
      -INT8_C( 114),  INT8_C( 107),  INT8_C( 112),  INT8_C(  69),  INT8_C(  19), -INT8_C(  10), -INT8_C(  35),  INT8_C(  29),
       INT8_C(  61), -INT8_C( 125), -INT8_C( 106),  INT8_C(  69),  INT8_C(  63), -INT8_C(  87), -INT8_C(  20), -INT8_C(   4),
      -INT8_C(  50),  INT8_C(  96),  INT8_C(  28), -INT8_C(  28), -INT8_C(  16), -INT8_C( 117),  INT8_C(  74),  INT8_C(  84),
      -INT8_C(  44),  INT8_C( 100), -INT8_C(  94), -INT8_C(  83),  INT8_C(   6), -INT8_C( 109),  INT8_C(  63), -INT8_C( 107),
      -INT8_C(   2), -INT8_C(  80), -INT8_C(  38),  INT8_C(  17), -INT8_C(  90), -INT8_C(  73),  INT8_C(  46), -INT8_C(  29),
       INT8_C(  58), -INT8_C(  60),  INT8_C(  41),  INT8_C( 122),  INT8_C( 110),  INT8_C(  21),  INT8_C( 118),  INT8_C(  60),
       INT8_C( 117), -INT8_C( 110),  INT8_C(  33),  INT8_C( 101),  INT8_C(  29),  INT8_C( 107), -INT8_C(  71), -INT8_C(  15),
      -INT8_C(  49),  INT8_C(  91), -INT8_C(  98), -INT8_C(  42), -INT8_C(  18), -INT8_C(  34),  INT8_C( 107), -INT8_C(  20),
      -INT8_C( 114),  INT8_C(  69), -INT8_C(   3),  INT8_C(  52), -INT8_C(   4),  INT8_C(  44),  INT8_C(  23),  INT8_C(  55),
      -INT8_C(  16),  INT8_C(  64), -INT8_C(  79),  INT8_C(  94),  INT8_C(  85),  INT8_C(  39), -INT8_C( 101), -INT8_C(  54),
      -INT8_C(  70), -INT8_C(  68),  INT8_C(  47), -INT8_C(  41),  INT8_C(  39), -INT8_C(  23), -INT8_C(  55), -INT8_C(  10),
       INT8_C(  68),  INT8_C( 103), -INT8_C(  52),  INT8_C(  51),  INT8_C(  69),  INT8_C(  55),  INT8_C(  31), -INT8_C(  45),
       INT8_C( 124),  INT8_C(  29),  INT8_C(   7),  INT8_C( 121),  INT8_C(  73),  INT8_C(  31), -INT8_C(  80),  INT8_C(  57),
       INT8_C(  95),  INT8_C(  97), -INT8_C( 104), -INT8_C(  75), -INT8_C( 120),  INT8_C(  51),      INT8_MAX,  INT8_C(  66),
      -INT8_C(  17), -INT8_C(  81),  INT8_C(  26),  INT8_C(  22), -INT8_C( 104), -INT8_C(  29),  INT8_C(  12), -INT8_C(  36),
       INT8_C(  74), -INT8_C(  39),  INT8_C(  15), -INT8_C( 112),  INT8_C(  16),  INT8_C(  47),  INT8_C(  99), -INT8_C( 115),
       INT8_C(  76),  INT8_C( 107),  INT8_C(   6), -INT8_C( 107), -INT8_C( 118), -INT8_C(  74), -INT8_C(  50), -INT8_C(  23),
       INT8_C(  23),  INT8_C( 102), -INT8_C(  98), -INT8_C(  97), -INT8_C( 103),  INT8_C(  30), -INT8_C(  30), -INT8_C( 120),
      -INT8_C(  51), -INT8_C(   4), -INT8_C(  98),  INT8_C( 101), -INT8_C(  33), -INT8_C(  85),  INT8_C(  65),  INT8_C(  41),
      -INT8_C( 124),  INT8_C(  81), -INT8_C(  71), -INT8_C( 108),      INT8_MIN,  INT8_C(  29),  INT8_C(  33), -INT8_C(  52),
      -INT8_C( 120),  INT8_C(  39),  INT8_C(  97),  INT8_C(  18), -INT8_C(  35),  INT8_C(  47), -INT8_C(   5), -INT8_C(  12),
      -INT8_C( 106), -INT8_C( 102), -INT8_C( 108),  INT8_C(  47), -INT8_C(  72),  INT8_C( 118), -INT8_C(  72), -INT8_C( 123),
       INT8_C( 114),  INT8_C(  86), -INT8_C(  22),  INT8_C(  81),  INT8_C(   1),  INT8_C(  43),  INT8_C( 122), -INT8_C( 123),
       INT8_C( 124),  INT8_C(  52),  INT8_C(  26), -INT8_C(   4),  INT8_C(  81),  INT8_C(  59), -INT8_C(  56), -INT8_C(  39),
       INT8_C(  99),  INT8_C(  41), -INT8_C(  21),  INT8_C(  64),  INT8_C(  89), -INT8_C(  26),  INT8_C(  53), -INT8_C(  17),
           INT8_MIN, -INT8_C(  55),  INT8_C(  30),  INT8_C(  56),  INT8_C(  63), -INT8_C(  42), -INT8_C(  67), -INT8_C(  79),
       INT8_C(  45), -INT8_C(  89),  INT8_C(   2),  INT8_C(  46), -INT8_C(  45),  INT8_C( 124), -INT8_C(  76),  INT8_C(  79),
      -INT8_C(  80), -INT8_C(  50),  INT8_C(  76),  INT8_C(   1),  INT8_C(   9),  INT8_C(  20), -INT8_C(  38),  INT8_C( 108),
       INT8_C(  62), -INT8_C(  59), -INT8_C(  83), -INT8_C( 105), -INT8_C(  84), -INT8_C(  30), -INT8_C( 122),  INT8_C(  44),
      -INT8_C(  85), -INT8_C(  92),  INT8_C( 101), -INT8_C(  22),  INT8_C( 123),  INT8_C(  34), -INT8_C( 101), -INT8_C(  88),
      -INT8_C(  54), -INT8_C(  99), -INT8_C(  42), -INT8_C(  99),  INT8_C(  25), -INT8_C( 118), -INT8_C(  20), -INT8_C(  54),
       INT8_C(  88),  INT8_C(  56), -INT8_C(  53),  INT8_C(  98),  INT8_C(  77), -INT8_C(  90), -INT8_C(  50), -INT8_C( 117),
       INT8_C( 107),  INT8_C( 123),  INT8_C(  34),  INT8_C(  23),  INT8_C(  93), -INT8_C(  88),  INT8_C(  68),  INT8_C(   8),
       INT8_C(  76), -INT8_C(  87), -INT8_C(  14), -INT8_C(  57), -INT8_C(  53), -INT8_C( 115),  INT8_C( 111), -INT8_C( 107),
       INT8_C(  42),  INT8_C(  70),  INT8_C(  50),  INT8_C(  68), -INT8_C(  48),  INT8_C(  31),  INT8_C(  14),  INT8_C(  41),
       INT8_C(  87), -INT8_C(  39), -INT8_C( 117), -INT8_C(  92),      INT8_MAX,  INT8_C(  89),  INT8_C(  47), -INT8_C(  21),
      -INT8_C(  43),  INT8_C(  81),  INT8_C(   2),  INT8_C(  50), -INT8_C(   7),  INT8_C(  70),  INT8_C(  59),  INT8_C(  70),
      -INT8_C(  17),  INT8_C(  45),  INT8_C(  13), -INT8_C(  69), -INT8_C(  69),  INT8_C( 125),  INT8_C(  80), -INT8_C(  27),
      -INT8_C(  61), -INT8_C( 125),  INT8_C(  41), -INT8_C( 109), -INT8_C(  94),  INT8_C(  55), -INT8_C(  68), -INT8_C(   7),
       INT8_C(  17),  INT8_C(  71), -INT8_C(  98), -INT8_C( 112), -INT8_C(  95), -INT8_C(  51),  INT8_C( 123),  INT8_C( 118),
       INT8_C(  31),  INT8_C( 126), -INT8_C(  88),  INT8_C(  24), -INT8_C(  60), -INT8_C(  29),  INT8_C(  94), -INT8_C(  76),
       INT8_C(  17),  INT8_C( 108),  INT8_C( 111), -INT8_C(  52), -INT8_C(  23), -INT8_C(  65), -INT8_C(  79), -INT8_C(  84),
       INT8_C(  66), -INT8_C(  37),  INT8_C(  63), -INT8_C(  28),  INT8_C(  18), -INT8_C(   4), -INT8_C(  34),  INT8_C(  35),
       INT8_C(  67),  INT8_C( 124), -INT8_C(  76), -INT8_C(  28),  INT8_C(  73),  INT8_C(  47),  INT8_C(  90),  INT8_C( 104),
      -INT8_C(  83),  INT8_C(   3), -INT8_C( 127),  INT8_C( 114), -INT8_C(  26), -INT8_C(  33),  INT8_C(  38), -INT8_C(   9),
       INT8_C(  75), -INT8_C( 107), -INT8_C(  61),  INT8_C(  52),  INT8_C(  84),  INT8_C( 117), -INT8_C(  32) };
  static const int8_t e[] =
    {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  80),  INT8_C(   0),  INT8_C(  52), -INT8_C(  35),  INT8_C(   0),
      -INT8_C( 104),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  10),  INT8_C(   0),  INT8_C(   0),  INT8_C( 114),
      -INT8_C(  89),  INT8_C(   0), -INT8_C(  34),  INT8_C(  88),  INT8_C(   0), -INT8_C(  65),  INT8_C(  44),  INT8_C(   0),
      -INT8_C(  83), -INT8_C(  59),  INT8_C(   0), -INT8_C(  32),  INT8_C(   0),  INT8_C(  15),  INT8_C(  96), -INT8_C(   6),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  74), -INT8_C(   5),  INT8_C(   0),  INT8_C(  40),  INT8_C( 113), -INT8_C( 103),
       INT8_C(  31),  INT8_C(   0),  INT8_C(   0),  INT8_C(  22),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  14),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  74),  INT8_C(  72),  INT8_C(   0),  INT8_C(   0), -INT8_C( 121), -INT8_C(  46),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  77),  INT8_C(   0),  INT8_C(   0),  INT8_C(  19),  INT8_C(   0), -INT8_C(  28),
       INT8_C(   0),  INT8_C(  33),  INT8_C(   0), -INT8_C(  33),  INT8_C(   0),  INT8_C(   0),  INT8_C( 120),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 117),  INT8_C(   0),  INT8_C(   0), -INT8_C(  99),  INT8_C(   7),  INT8_C(   0),  INT8_C(   0),
       INT8_C( 109), -INT8_C(  90),  INT8_C( 115), -INT8_C( 110),  INT8_C(   0), -INT8_C(   5),  INT8_C( 101),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  52),  INT8_C(  26),  INT8_C(  43),  INT8_C(  11),  INT8_C(   0),  INT8_C(  10),
       INT8_C(  45),  INT8_C(   0), -INT8_C(  23),  INT8_C(   0),  INT8_C(  47),  INT8_C(  98),  INT8_C(   0),  INT8_C(  78),
      -INT8_C(  19),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  20), -INT8_C(  74), -INT8_C(  46),
      -INT8_C(  70),  INT8_C(  41),  INT8_C(   0), -INT8_C(  42),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  89),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 110),  INT8_C(   0),  INT8_C(   0), -INT8_C( 101),
      -INT8_C(  98),  INT8_C(   0),  INT8_C(  17),  INT8_C(   0),  INT8_C(  98),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  79),  INT8_C(   0), -INT8_C(  38), -INT8_C(  75),  INT8_C(   0), -INT8_C( 112),  INT8_C(   0), -INT8_C(  93),
       INT8_C(   0), -INT8_C(  20),  INT8_C( 122), -INT8_C(  34), -INT8_C(  74),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   8), -INT8_C(  68),  INT8_C(  19), -INT8_C(  90),
      -INT8_C(  67),  INT8_C(  37),  INT8_C(   0),  INT8_C(  31),  INT8_C(  22),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C( 100),  INT8_C(   0),  INT8_C(  26),  INT8_C(  77),  INT8_C(   0),  INT8_C(   0), -INT8_C(  15),  INT8_C(   0),
      -INT8_C( 114),  INT8_C(   0),  INT8_C(   0),  INT8_C(  69),  INT8_C(  19),  INT8_C(   0), -INT8_C(  35),  INT8_C(  29),
       INT8_C(  61),  INT8_C(   0), -INT8_C( 106),  INT8_C(   0),  INT8_C(  63), -INT8_C(  87),  INT8_C(   0), -INT8_C(   4),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  28), -INT8_C(  28),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C( 100),  INT8_C(   0), -INT8_C(  83),  INT8_C(   0), -INT8_C( 109),  INT8_C(  63),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  80), -INT8_C(  38),  INT8_C(  17),  INT8_C(   0), -INT8_C(  73),  INT8_C(  46), -INT8_C(  29),
       INT8_C(  58),  INT8_C(   0),  INT8_C(   0),  INT8_C( 122),  INT8_C( 110),  INT8_C(  21),  INT8_C(   0),  INT8_C(   0),
       INT8_C( 117),  INT8_C(   0),  INT8_C(  33),  INT8_C(   0),  INT8_C(   0),  INT8_C( 107),  INT8_C(   0), -INT8_C(  15),
      -INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  69),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  44),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  16),  INT8_C(  64), -INT8_C(  79),  INT8_C(  94),  INT8_C(   0),  INT8_C(   0), -INT8_C( 101), -INT8_C(  54),
       INT8_C(   0), -INT8_C(  68),  INT8_C(  47), -INT8_C(  41),  INT8_C(  39),  INT8_C(   0),  INT8_C(   0), -INT8_C(  10),
       INT8_C(   0),  INT8_C( 103), -INT8_C(  52),  INT8_C(   0),  INT8_C(   0),  INT8_C(  55),  INT8_C(  31),  INT8_C(   0),
       INT8_C( 124),  INT8_C(  29),  INT8_C(   0),  INT8_C( 121),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  95),  INT8_C(  97),  INT8_C(   0),  INT8_C(   0), -INT8_C( 120),  INT8_C(  51),      INT8_MAX,  INT8_C(   0),
      -INT8_C(  17),  INT8_C(   0),  INT8_C(  26),  INT8_C(   0), -INT8_C( 104),  INT8_C(   0),  INT8_C(  12), -INT8_C(  36),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  47),  INT8_C(   0), -INT8_C( 115),
       INT8_C(   0),  INT8_C( 107),  INT8_C(   6), -INT8_C( 107),  INT8_C(   0), -INT8_C(  74),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  23),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  30), -INT8_C(  30), -INT8_C( 120),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  98),  INT8_C( 101), -INT8_C(  33), -INT8_C(  85),  INT8_C(  65),  INT8_C(  41),
       INT8_C(   0),  INT8_C(  81),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  33), -INT8_C(  52),
       INT8_C(   0),  INT8_C(  39),  INT8_C(  97),  INT8_C(   0),  INT8_C(   0),  INT8_C(  47),  INT8_C(   0), -INT8_C(  12),
      -INT8_C( 106),  INT8_C(   0),  INT8_C(   0),  INT8_C(  47),  INT8_C(   0),  INT8_C( 118), -INT8_C(  72),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  43),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   4),  INT8_C(  81),  INT8_C(   0), -INT8_C(  56), -INT8_C(  39),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  89),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),
           INT8_MIN, -INT8_C(  55),  INT8_C(  30),  INT8_C(  56),  INT8_C(  63),  INT8_C(   0),  INT8_C(   0), -INT8_C(  79),
       INT8_C(  45),  INT8_C(   0),  INT8_C(   2),  INT8_C(  46), -INT8_C(  45),  INT8_C(   0), -INT8_C(  76),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   9),  INT8_C(  20),  INT8_C(   0),  INT8_C( 108),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  84), -INT8_C(  30), -INT8_C( 122),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C( 101), -INT8_C(  22),  INT8_C(   0),  INT8_C(  34), -INT8_C( 101),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  42),  INT8_C(   0),  INT8_C(  25), -INT8_C( 118), -INT8_C(  20), -INT8_C(  54),
       INT8_C(   0),  INT8_C(  56),  INT8_C(   0),  INT8_C(   0),  INT8_C(  77),  INT8_C(   0), -INT8_C(  50), -INT8_C( 117),
       INT8_C(   0),  INT8_C( 123),  INT8_C(  34),  INT8_C(   0),  INT8_C(  93), -INT8_C(  88),  INT8_C(   0),  INT8_C(   8),
       INT8_C(  76), -INT8_C(  87),  INT8_C(   0),  INT8_C(   0), -INT8_C(  53), -INT8_C( 115),  INT8_C( 111), -INT8_C( 107),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  31),  INT8_C(  14),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  92),  INT8_C(   0),  INT8_C(   0),  INT8_C(  47), -INT8_C(  21),
       INT8_C(   0),  INT8_C(  81),  INT8_C(   2),  INT8_C(  50),  INT8_C(   0),  INT8_C(  70),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  17),  INT8_C(  45),  INT8_C(   0), -INT8_C(  69), -INT8_C(  69),  INT8_C( 125),  INT8_C(  80),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 125),  INT8_C(   0),  INT8_C(   0), -INT8_C(  94),  INT8_C(   0), -INT8_C(  68), -INT8_C(   7),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  98), -INT8_C( 112),  INT8_C(   0), -INT8_C(  51),  INT8_C(   0),  INT8_C( 118),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  29),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  17),  INT8_C( 108),  INT8_C(   0),  INT8_C(   0), -INT8_C(  23), -INT8_C(  65), -INT8_C(  79),  INT8_C(   0),
       INT8_C(  66), -INT8_C(  37),  INT8_C(  63),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  67),  INT8_C(   0), -INT8_C(  76),  INT8_C(   0),  INT8_C(  73),  INT8_C(   0),  INT8_C(  90),  INT8_C( 104),
      -INT8_C(  83),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  26),  INT8_C(   0),  INT8_C(   0), -INT8_C(   9),
       INT8_C(   0), -INT8_C( 107), -INT8_C(  61),  INT8_C(  52),  INT8_C(  84),  INT8_C( 117), -INT8_C(  32) };

  static int8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t
      rv,
      av = simde_svld1_s8(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(INT8_C(0)));
    rv = simde_x_svsel_s8_z(pv, av);

    simde_svst1_s8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vi8(len, e, r);

  return 0;
#else
  int8_t p[1024], a[1024], e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_s8(pg, &(a[i]));

    ev = simde_x_svsel_s8_z(pv, av);

    simde_svst1_s8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsel_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) };
  static const int8_t a[] =
    { -INT8_C( 103),  INT8_C( 119),  INT8_C(   7), -INT8_C(  24), -INT8_C(  22), -INT8_C(  47),  INT8_C(  27),  INT8_C( 102),
       INT8_C(   0), -INT8_C(  21), -INT8_C(  63), -INT8_C(  52), -INT8_C(  69), -INT8_C(  76),  INT8_C(  89),  INT8_C(  67),
      -INT8_C(  25),  INT8_C(  56),  INT8_C( 111),  INT8_C(  88),  INT8_C( 106), -INT8_C(  39), -INT8_C( 122),  INT8_C(  15),
      -INT8_C( 104), -INT8_C(  75),  INT8_C( 100), -INT8_C(  93),  INT8_C(  37), -INT8_C(   6),  INT8_C( 124), -INT8_C(  66),
       INT8_C( 113), -INT8_C( 125), -INT8_C(  89),  INT8_C(  92),  INT8_C(  85), -INT8_C(  62), -INT8_C(  62),  INT8_C(  85),
      -INT8_C(  83), -INT8_C( 125),  INT8_C(  33),  INT8_C( 104),  INT8_C(  55),  INT8_C( 122), -INT8_C(  85),  INT8_C(  30),
      -INT8_C(  78),  INT8_C(  26),  INT8_C( 119),  INT8_C(  28), -INT8_C(  12), -INT8_C(   3),  INT8_C(  43), -INT8_C( 116),
      -INT8_C(  78), -INT8_C( 112),  INT8_C(  47), -INT8_C(  41), -INT8_C( 118), -INT8_C(  85), -INT8_C( 106), -INT8_C(   4),
       INT8_C(  46),  INT8_C(  61),  INT8_C(  88), -INT8_C( 125), -INT8_C(   1),  INT8_C(  26), -INT8_C(  40), -INT8_C(  83),
      -INT8_C(  99), -INT8_C(   6),  INT8_C(  21), -INT8_C(  44),  INT8_C( 116), -INT8_C(  63), -INT8_C(  14),  INT8_C(  39),
      -INT8_C(  37),  INT8_C( 105),  INT8_C(  67), -INT8_C(  49),  INT8_C( 103),  INT8_C( 111),  INT8_C(  91),  INT8_C(  25),
      -INT8_C(   1), -INT8_C( 118), -INT8_C(  15), -INT8_C( 119),  INT8_C(  53), -INT8_C( 121), -INT8_C( 123),  INT8_C( 100),
      -INT8_C(  60), -INT8_C(  35), -INT8_C(  25), -INT8_C(  61), -INT8_C(   9), -INT8_C(  64),  INT8_C( 112), -INT8_C( 108),
      -INT8_C(  70), -INT8_C( 122),  INT8_C( 104),  INT8_C(  46),  INT8_C(  71),  INT8_C(  91),  INT8_C(  85),  INT8_C(  34),
      -INT8_C(  60), -INT8_C( 103), -INT8_C(  14),  INT8_C(  43),  INT8_C(   8),  INT8_C(  77),  INT8_C(  69),  INT8_C(   7),
      -INT8_C(  40),  INT8_C(  54), -INT8_C( 112),  INT8_C(  13), -INT8_C(  67),  INT8_C(  22),  INT8_C( 113), -INT8_C( 127),
      -INT8_C(  13),  INT8_C(  89),  INT8_C(  68), -INT8_C(  21),  INT8_C(  25), -INT8_C(  75),      INT8_MAX, -INT8_C(  45),
       INT8_C(  59), -INT8_C(  24),  INT8_C(   1), -INT8_C( 126),  INT8_C(  67),  INT8_C(  87), -INT8_C(  92),  INT8_C(   7),
      -INT8_C(  16), -INT8_C( 106),  INT8_C(  51), -INT8_C(   8), -INT8_C(  28),  INT8_C( 120), -INT8_C(   1), -INT8_C(  68),
      -INT8_C(  82), -INT8_C( 113), -INT8_C(  55),  INT8_C( 107), -INT8_C(  91),  INT8_C(  59), -INT8_C(  20), -INT8_C( 103),
      -INT8_C( 108),  INT8_C(  48), -INT8_C( 124), -INT8_C(  83), -INT8_C(  27),  INT8_C(   3),      INT8_MIN,  INT8_C(  32),
      -INT8_C(  21), -INT8_C( 127), -INT8_C(  94),  INT8_C(  46), -INT8_C(  40),  INT8_C(  71),  INT8_C(  54), -INT8_C(  56),
      -INT8_C(  35),  INT8_C( 105), -INT8_C(  64), -INT8_C(  63), -INT8_C(  31), -INT8_C(  65),  INT8_C( 125), -INT8_C( 113),
       INT8_C(  79),  INT8_C(  71), -INT8_C(   6), -INT8_C(  12), -INT8_C( 126), -INT8_C(  26), -INT8_C( 115),  INT8_C(  22),
       INT8_C(  22),  INT8_C(  17), -INT8_C(  61), -INT8_C(   4),  INT8_C(  21),  INT8_C(  67),  INT8_C(  28),  INT8_C(   0),
      -INT8_C(  60), -INT8_C(  65),  INT8_C(  47), -INT8_C(  99),  INT8_C(   6),  INT8_C( 101),  INT8_C( 101), -INT8_C(  29),
      -INT8_C(  50),  INT8_C(  38), -INT8_C(  91), -INT8_C(  81), -INT8_C(  27),  INT8_C(  34),  INT8_C(  62),  INT8_C(  52),
       INT8_C( 105),  INT8_C(  56),  INT8_C(  41), -INT8_C(  21),  INT8_C(  30), -INT8_C(  74),  INT8_C(   1),  INT8_C(  52),
      -INT8_C(  56), -INT8_C(  60),  INT8_C(  48), -INT8_C(  35),  INT8_C(   7),  INT8_C(  77), -INT8_C(  35), -INT8_C(  52),
       INT8_C(  12),  INT8_C(  12),  INT8_C( 105),  INT8_C(  18),  INT8_C( 113), -INT8_C(  50), -INT8_C(  11),  INT8_C(  63),
      -INT8_C(  12), -INT8_C( 102), -INT8_C(  18), -INT8_C(  38), -INT8_C(  67),  INT8_C(  44),  INT8_C(  14),  INT8_C(  38),
       INT8_C( 100),  INT8_C(  55),  INT8_C(  18), -INT8_C( 126), -INT8_C(  18),  INT8_C(  19), -INT8_C(  73), -INT8_C(  74),
      -INT8_C(  40), -INT8_C(  25), -INT8_C( 109), -INT8_C(  33),  INT8_C(  52),  INT8_C( 112), -INT8_C(  85),  INT8_C(  64),
       INT8_C( 125),  INT8_C(  20),  INT8_C(  82), -INT8_C(  18), -INT8_C(  29),  INT8_C(  72),  INT8_C(  46), -INT8_C(  41),
      -INT8_C(  30),  INT8_C(  28), -INT8_C(  79), -INT8_C(  97),  INT8_C(  73), -INT8_C(  64), -INT8_C(  58), -INT8_C(  83),
      -INT8_C(   9), -INT8_C(  40),  INT8_C(  48), -INT8_C(  27), -INT8_C(  21), -INT8_C(  25), -INT8_C( 101), -INT8_C(  61),
      -INT8_C(  50),  INT8_C(  46), -INT8_C(  93),  INT8_C(   3), -INT8_C(  97),  INT8_C(  78),  INT8_C(  67),  INT8_C(  28),
       INT8_C(  99), -INT8_C( 106),  INT8_C(  10),  INT8_C(  70), -INT8_C(  34),  INT8_C(  56),  INT8_C(  29), -INT8_C(  64),
       INT8_C(  85), -INT8_C(  49),  INT8_C(  96), -INT8_C(  98), -INT8_C( 113),  INT8_C(  38),  INT8_C(  75), -INT8_C( 122),
      -INT8_C(   2),  INT8_C( 123),  INT8_C( 108), -INT8_C(  23),  INT8_C(  98),  INT8_C(   7), -INT8_C(  83),  INT8_C(  49),
       INT8_C(  54),  INT8_C(  80),  INT8_C(  52), -INT8_C(  43), -INT8_C(  98),  INT8_C( 119), -INT8_C(  15),  INT8_C(   1),
       INT8_C(  13), -INT8_C(   5),  INT8_C(  71), -INT8_C(  21),  INT8_C(  52),  INT8_C( 101), -INT8_C(  84), -INT8_C( 119),
       INT8_C(  52),  INT8_C(  12),  INT8_C(  39), -INT8_C(  61),  INT8_C(  50),  INT8_C( 114),  INT8_C(  73),  INT8_C(  48),
      -INT8_C(  18), -INT8_C(  75),  INT8_C(  25),  INT8_C(  80), -INT8_C(  67), -INT8_C(  58), -INT8_C( 127), -INT8_C(  13),
       INT8_C(  22), -INT8_C(  75), -INT8_C(  56), -INT8_C(  75),  INT8_C(  45), -INT8_C(  71), -INT8_C(  74),  INT8_C(  58),
      -INT8_C(  76), -INT8_C(   2),  INT8_C(  38), -INT8_C(  24),  INT8_C(  99), -INT8_C(  46),  INT8_C( 113), -INT8_C( 105),
      -INT8_C(  34), -INT8_C( 104),  INT8_C(  90),  INT8_C(  16),  INT8_C(  11), -INT8_C(  93),  INT8_C(  64), -INT8_C(   7),
       INT8_C(  89),  INT8_C(  89),  INT8_C(  73),  INT8_C(  22),  INT8_C(  32), -INT8_C(  53),  INT8_C(   9),  INT8_C(  54),
           INT8_MIN, -INT8_C(  47), -INT8_C(  21), -INT8_C(  83), -INT8_C( 118), -INT8_C(  94), -INT8_C(  24),  INT8_C(  62),
      -INT8_C(  96),  INT8_C(  14),  INT8_C(  39),  INT8_C(   3), -INT8_C(  32), -INT8_C( 104), -INT8_C( 102), -INT8_C(  66),
       INT8_C(  49), -INT8_C(  12), -INT8_C(  50),  INT8_C(  60), -INT8_C( 105),  INT8_C(  14),  INT8_C(  53), -INT8_C(  16),
       INT8_C( 103),  INT8_C( 126),  INT8_C(   6), -INT8_C( 121),  INT8_C(  73),  INT8_C(  15), -INT8_C(  66), -INT8_C(  54),
      -INT8_C(  32), -INT8_C(  87),  INT8_C( 119),  INT8_C( 106),  INT8_C(  75),  INT8_C(  95), -INT8_C(  87), -INT8_C(  21),
       INT8_C( 109), -INT8_C(  48), -INT8_C(  18),  INT8_C(  77),  INT8_C( 104), -INT8_C( 120),  INT8_C(  11), -INT8_C( 103),
       INT8_C( 124), -INT8_C(  39), -INT8_C(  43),  INT8_C(  20), -INT8_C(  25),  INT8_C(  10),  INT8_C(   4),  INT8_C(  79),
      -INT8_C( 119),  INT8_C(  11), -INT8_C(  42), -INT8_C(  46),  INT8_C(  26), -INT8_C( 108), -INT8_C( 100), -INT8_C(   5),
       INT8_C(  62),  INT8_C(  20),  INT8_C( 101), -INT8_C( 119),  INT8_C( 115),  INT8_C(  14),  INT8_C( 117), -INT8_C(  31),
      -INT8_C(  34),  INT8_C(  99),  INT8_C(  46),  INT8_C(  71), -INT8_C(  20),  INT8_C(  58), -INT8_C(  32),  INT8_C( 104),
       INT8_C(  19), -INT8_C(  74),  INT8_C( 124), -INT8_C(   5), -INT8_C(  64), -INT8_C( 127),  INT8_C(  74),  INT8_C(  73),
      -INT8_C( 116),  INT8_C(  32),  INT8_C(  28), -INT8_C(  90), -INT8_C(  75), -INT8_C(  72), -INT8_C(  95), -INT8_C(  13),
      -INT8_C(  52),  INT8_C(   7),  INT8_C( 124),  INT8_C(  64),  INT8_C(  21), -INT8_C(  15),  INT8_C(  33), -INT8_C(  12),
       INT8_C(  85),  INT8_C(  79),  INT8_C(  59),  INT8_C(  65), -INT8_C( 119),  INT8_C(  27), -INT8_C(  87), -INT8_C(  99),
      -INT8_C(  47),  INT8_C(  38), -INT8_C( 104), -INT8_C( 110), -INT8_C(  89), -INT8_C(  30), -INT8_C(  37),  INT8_C(  51),
       INT8_C(   2), -INT8_C(   9), -INT8_C(  39), -INT8_C(  73), -INT8_C(  80),  INT8_C( 123), -INT8_C(  86),  INT8_C( 124),
      -INT8_C( 126),  INT8_C(  39), -INT8_C(  68), -INT8_C( 105),  INT8_C(  24), -INT8_C(  35), -INT8_C( 117),  INT8_C( 109),
       INT8_C(  45), -INT8_C(  58), -INT8_C(  82), -INT8_C(  74), -INT8_C(  30),  INT8_C(  88),  INT8_C(  83), -INT8_C(  77),
       INT8_C( 126), -INT8_C(  21),  INT8_C(  69),  INT8_C(  37), -INT8_C(  51),  INT8_C(  33),  INT8_C(  88), -INT8_C(  48),
       INT8_C(  24),  INT8_C(  49), -INT8_C( 121), -INT8_C(  56), -INT8_C(  84),  INT8_C(  50),  INT8_C(  69),  INT8_C(  46),
       INT8_C(  89),  INT8_C(   1), -INT8_C(  58),  INT8_C( 113), -INT8_C(  33),  INT8_C(  81), -INT8_C(  33),  INT8_C(  12),
       INT8_C(  24), -INT8_C( 115), -INT8_C(  62), -INT8_C(   6), -INT8_C(  27),  INT8_C(  22), -INT8_C(  83),  INT8_C(  99),
       INT8_C(   1), -INT8_C(  13), -INT8_C( 120), -INT8_C(  49),  INT8_C(  20), -INT8_C(  32), -INT8_C(  97),  INT8_C(  44),
       INT8_C(  18),  INT8_C(  38), -INT8_C(  11), -INT8_C(  66),  INT8_C(  88),  INT8_C(  58), -INT8_C(  19), -INT8_C(  79),
       INT8_C(  59), -INT8_C(  77),  INT8_C(  35),  INT8_C(  26),  INT8_C(   4),  INT8_C(   2),  INT8_C(  38),  INT8_C(  28),
      -INT8_C( 113), -INT8_C(  23),  INT8_C(  22),  INT8_C( 117), -INT8_C(   1), -INT8_C(  60), -INT8_C(  40),  INT8_C(   0),
      -INT8_C(  73),  INT8_C(  97), -INT8_C(  49), -INT8_C(  53),  INT8_C(  65),  INT8_C( 110), -INT8_C(   9),  INT8_C(  83),
      -INT8_C( 107), -INT8_C(  20),  INT8_C(  18), -INT8_C(  19),  INT8_C(  38), -INT8_C(   1), -INT8_C(  97),  INT8_C(  98),
      -INT8_C(  78), -INT8_C(  62),  INT8_C( 124), -INT8_C(  74), -INT8_C(  60), -INT8_C(  93), -INT8_C(  45),  INT8_C(  83),
      -INT8_C( 116), -INT8_C(  23), -INT8_C(  56), -INT8_C( 117), -INT8_C(  83), -INT8_C(  95), -INT8_C( 117),  INT8_C( 100),
       INT8_C(   2),  INT8_C(  91),  INT8_C(  47),  INT8_C(  67), -INT8_C(  55),  INT8_C(  39), -INT8_C( 105),  INT8_C(  94),
       INT8_C(  19), -INT8_C(  87),  INT8_C(  76),  INT8_C(  58), -INT8_C(  88), -INT8_C(  21), -INT8_C( 100),  INT8_C(  90),
      -INT8_C(  83),  INT8_C(  24),  INT8_C(  16),  INT8_C( 113), -INT8_C(  69), -INT8_C(  29), -INT8_C(  60),  INT8_C(  71),
      -INT8_C(  51), -INT8_C( 115), -INT8_C(  46),  INT8_C( 122),  INT8_C(  46),  INT8_C(  94), -INT8_C(  33),  INT8_C(  48),
      -INT8_C(  71),  INT8_C(  14),  INT8_C( 115), -INT8_C( 126),  INT8_C(  53),  INT8_C(  10), -INT8_C(  31),  INT8_C(  73),
      -INT8_C(  77),  INT8_C(  45), -INT8_C( 125),  INT8_C(  91),  INT8_C(  24),  INT8_C(  31), -INT8_C(  75), -INT8_C(  59),
       INT8_C(  55), -INT8_C(  58),  INT8_C(  54), -INT8_C(  13), -INT8_C(  87), -INT8_C(   6),  INT8_C(  58),  INT8_C( 118),
      -INT8_C( 121),  INT8_C(  13), -INT8_C(  15), -INT8_C(  75),  INT8_C( 107), -INT8_C(  48), -INT8_C(  27) };
  static const int8_t b[] =
    {  INT8_C( 117), -INT8_C(  77),  INT8_C(  27),  INT8_C( 114),  INT8_C( 108), -INT8_C( 120),  INT8_C(  18), -INT8_C(  28),
       INT8_C( 121), -INT8_C(  62),  INT8_C(  79),  INT8_C(  41),  INT8_C(  38),  INT8_C(   6), -INT8_C(  94), -INT8_C(  72),
       INT8_C(  19), -INT8_C(  71),  INT8_C(  12),  INT8_C(  50), -INT8_C( 114),  INT8_C(  79), -INT8_C(  24),  INT8_C(  63),
       INT8_C(   4),  INT8_C(  24),  INT8_C(  20),  INT8_C(  97), -INT8_C(  75),  INT8_C(   7),  INT8_C(  63),  INT8_C(  42),
      -INT8_C(  70),  INT8_C(  90), -INT8_C(  99),  INT8_C(  38), -INT8_C(  30), -INT8_C(  81),  INT8_C(  10),  INT8_C(  91),
       INT8_C( 113),  INT8_C(  90), -INT8_C( 123), -INT8_C( 105),  INT8_C(  96),  INT8_C(  39),  INT8_C(  80),  INT8_C( 115),
      -INT8_C(  32),  INT8_C(  92), -INT8_C(  91),  INT8_C( 111), -INT8_C(  85), -INT8_C( 115), -INT8_C(  82), -INT8_C(  81),
      -INT8_C(  91), -INT8_C(  61),  INT8_C(  17),  INT8_C(  90), -INT8_C(  54),  INT8_C(  80), -INT8_C( 123), -INT8_C( 123),
      -INT8_C(  86),  INT8_C(  34), -INT8_C(  85), -INT8_C( 116), -INT8_C(  47), -INT8_C(  74), -INT8_C(  25),  INT8_C(  66),
       INT8_C(  16),  INT8_C( 108), -INT8_C(  39),  INT8_C( 112), -INT8_C( 108),  INT8_C(  41), -INT8_C(  29),  INT8_C( 116),
      -INT8_C( 123), -INT8_C( 120), -INT8_C(  29),  INT8_C(  49),  INT8_C(  21), -INT8_C( 110), -INT8_C(  32), -INT8_C(  70),
       INT8_C(  85), -INT8_C(  15),  INT8_C(  20),  INT8_C(  31),  INT8_C(  65), -INT8_C( 103), -INT8_C(  92), -INT8_C(  21),
      -INT8_C(  69),  INT8_C(  80),  INT8_C( 119), -INT8_C( 116),  INT8_C(   6),  INT8_C(  95), -INT8_C(  50),  INT8_C(  22),
      -INT8_C(  53), -INT8_C(  88), -INT8_C( 122),  INT8_C(  95), -INT8_C(  47),  INT8_C( 105), -INT8_C(  44),  INT8_C(  87),
      -INT8_C(  15), -INT8_C(  73), -INT8_C( 120),  INT8_C(   6),  INT8_C(  73),  INT8_C( 104), -INT8_C(  64), -INT8_C(  98),
       INT8_C(  90), -INT8_C(  44), -INT8_C(  66), -INT8_C( 101),  INT8_C( 110),  INT8_C(  98), -INT8_C( 121),  INT8_C(  41),
      -INT8_C(  78), -INT8_C(   2), -INT8_C(  74), -INT8_C(  72),  INT8_C(  93), -INT8_C( 124), -INT8_C(  50),  INT8_C(  41),
       INT8_C(  44),  INT8_C(  84), -INT8_C( 120), -INT8_C(   2), -INT8_C(  67),  INT8_C(  92),  INT8_C(  85), -INT8_C(  82),
       INT8_C(  20), -INT8_C(  35), -INT8_C(  76),  INT8_C(  93),  INT8_C(  69),  INT8_C( 116), -INT8_C(   4), -INT8_C(  97),
       INT8_C(  73), -INT8_C(  70),  INT8_C(  59), -INT8_C(  73),  INT8_C(  28), -INT8_C(  62), -INT8_C(  32), -INT8_C(  49),
      -INT8_C(  64), -INT8_C( 106), -INT8_C( 121),  INT8_C(  30),  INT8_C(  27),  INT8_C(  86),  INT8_C(  71),  INT8_C(  71),
      -INT8_C(  86), -INT8_C(  49),  INT8_C(  69),  INT8_C( 104),  INT8_C(  44), -INT8_C( 102),  INT8_C(  22),  INT8_C(  64),
       INT8_C( 119), -INT8_C(  53), -INT8_C(  99), -INT8_C(  67),  INT8_C(  63), -INT8_C( 103),  INT8_C(  92), -INT8_C( 120),
       INT8_C(  83), -INT8_C( 105),  INT8_C(  63),  INT8_C( 112),  INT8_C(  89),  INT8_C(  32),  INT8_C(  63),  INT8_C(  26),
      -INT8_C(  74), -INT8_C(  58),  INT8_C(  56), -INT8_C(  47),  INT8_C(  28),      INT8_MAX,  INT8_C(  25), -INT8_C(  57),
       INT8_C(  78),  INT8_C(  94),  INT8_C(  47),  INT8_C( 122), -INT8_C(   7),  INT8_C(  69), -INT8_C(  70),  INT8_C( 112),
       INT8_C(  16),  INT8_C(  88),  INT8_C(  45),  INT8_C(  80), -INT8_C(  15), -INT8_C( 118), -INT8_C(  40),  INT8_C(  69),
       INT8_C(  33),  INT8_C(  24), -INT8_C(  75),  INT8_C( 123),  INT8_C(  56), -INT8_C(  12), -INT8_C( 107), -INT8_C(  18),
      -INT8_C(  70), -INT8_C(  51), -INT8_C(  64), -INT8_C(  41),  INT8_C(  76), -INT8_C(  39), -INT8_C(  98), -INT8_C( 102),
       INT8_C(  55), -INT8_C(  51),  INT8_C(  21),  INT8_C(  48),  INT8_C(  18), -INT8_C(  49), -INT8_C(  95),  INT8_C(  35),
       INT8_C(  39), -INT8_C(  50),  INT8_C( 115),  INT8_C(  25),  INT8_C(  88),  INT8_C(  75),  INT8_C(  94),  INT8_C( 122),
       INT8_C(  99),  INT8_C(  19), -INT8_C(  11), -INT8_C( 101),  INT8_C(   7), -INT8_C( 118), -INT8_C( 118), -INT8_C(  63),
       INT8_C(  87),  INT8_C(  74), -INT8_C( 104), -INT8_C(  93),  INT8_C(  35),  INT8_C(  54),  INT8_C(  61),  INT8_C(  90),
       INT8_C(   3),  INT8_C(  82), -INT8_C( 117),  INT8_C(  22),  INT8_C(  34),  INT8_C(  44),  INT8_C(  57),  INT8_C(  73),
      -INT8_C(   6), -INT8_C(  84),  INT8_C(  98),  INT8_C(  83), -INT8_C(   9), -INT8_C(  64), -INT8_C(  51),  INT8_C(  91),
      -INT8_C(  45), -INT8_C(  62), -INT8_C(  10), -INT8_C(  38),  INT8_C(  76),      INT8_MIN, -INT8_C( 100), -INT8_C(  93),
      -INT8_C(  54),  INT8_C(  52),  INT8_C(  70), -INT8_C(  19),  INT8_C( 107), -INT8_C( 125),  INT8_C(  72),  INT8_C( 110),
      -INT8_C(  42), -INT8_C(  45), -INT8_C( 124), -INT8_C(   8), -INT8_C(   1), -INT8_C(  67),  INT8_C(  65), -INT8_C(   7),
       INT8_C( 105), -INT8_C(  92),  INT8_C(  76),  INT8_C(  97),  INT8_C( 100),  INT8_C(  25), -INT8_C(  68),  INT8_C(  56),
      -INT8_C(  37), -INT8_C(  78),  INT8_C(  18),  INT8_C(  39),  INT8_C(  51), -INT8_C(  82), -INT8_C(  54), -INT8_C(   3),
      -INT8_C(  29),  INT8_C(  16), -INT8_C(  21),  INT8_C(  78), -INT8_C( 108),  INT8_C(  51), -INT8_C(  68),  INT8_C( 106),
       INT8_C(   6),  INT8_C(  65),  INT8_C(  98),  INT8_C(   5), -INT8_C(   2), -INT8_C(  93), -INT8_C(   2),  INT8_C( 104),
       INT8_C(  71),  INT8_C(  75), -INT8_C(  55), -INT8_C(  84),  INT8_C( 100), -INT8_C( 123), -INT8_C(  28),  INT8_C(  64),
       INT8_C(  55), -INT8_C(  10),  INT8_C( 103),  INT8_C( 106), -INT8_C(  91),  INT8_C(  50),  INT8_C( 104), -INT8_C( 120),
       INT8_C(  66),  INT8_C(  83), -INT8_C(  42), -INT8_C(  42), -INT8_C( 122), -INT8_C( 110),  INT8_C(  64), -INT8_C( 116),
      -INT8_C(  45), -INT8_C(  94), -INT8_C( 111), -INT8_C(  46),  INT8_C(  70), -INT8_C( 113),  INT8_C(  58), -INT8_C( 115),
      -INT8_C(  38),  INT8_C(   3),  INT8_C(  57),  INT8_C(  63), -INT8_C( 120),  INT8_C(  29),      INT8_MAX, -INT8_C(  65),
       INT8_C(  20), -INT8_C(  26),  INT8_C(  42), -INT8_C(  71),  INT8_C(  24), -INT8_C( 110),  INT8_C(  65),  INT8_C(  91),
      -INT8_C(  27),  INT8_C(  23),  INT8_C(  49),  INT8_C( 107), -INT8_C(  87),  INT8_C( 114), -INT8_C(   9),  INT8_C( 125),
       INT8_C(  20), -INT8_C( 120),  INT8_C(  79),  INT8_C(  90),  INT8_C(  23), -INT8_C( 119), -INT8_C(  24), -INT8_C(  14),
      -INT8_C( 116),  INT8_C(  33),  INT8_C(  49),  INT8_C(  20),  INT8_C(  63), -INT8_C(  80), -INT8_C(  45),  INT8_C(  83),
      -INT8_C( 106), -INT8_C(   3),  INT8_C(  12), -INT8_C(  81), -INT8_C( 113),  INT8_C(  77),  INT8_C(  10),  INT8_C( 116),
       INT8_C( 100),  INT8_C(  59), -INT8_C(  33),  INT8_C(  13), -INT8_C(  83), -INT8_C(  42), -INT8_C( 118), -INT8_C(  62),
       INT8_C(  94), -INT8_C(  39),  INT8_C(  28),  INT8_C( 118),  INT8_C(  98),  INT8_C(   4),  INT8_C( 104), -INT8_C(  18),
       INT8_C(  38), -INT8_C( 103),  INT8_C(   2),  INT8_C( 101),  INT8_C(  73), -INT8_C(  42), -INT8_C(  72), -INT8_C(  33),
      -INT8_C(  45), -INT8_C(  60), -INT8_C( 114),  INT8_C(  99),  INT8_C(  17), -INT8_C( 104), -INT8_C(  41),  INT8_C( 117),
      -INT8_C(  44), -INT8_C(  73), -INT8_C( 126), -INT8_C( 127), -INT8_C( 115),  INT8_C(  13),  INT8_C(  67), -INT8_C(  20),
      -INT8_C(  26),  INT8_C(  96),  INT8_C(  98),  INT8_C(  73),  INT8_C( 100), -INT8_C(  54),  INT8_C(  55), -INT8_C( 118),
       INT8_C(  99),  INT8_C(  58), -INT8_C(  17), -INT8_C(  84),  INT8_C(  16), -INT8_C(  89), -INT8_C( 117), -INT8_C(  29),
       INT8_C( 107),  INT8_C(  26),  INT8_C(  70),  INT8_C( 124), -INT8_C(  78),  INT8_C(  30), -INT8_C(  15), -INT8_C( 122),
      -INT8_C(  43),  INT8_C( 116),  INT8_C(   8),  INT8_C(  98), -INT8_C( 127),  INT8_C(  75),  INT8_C(  78),  INT8_C( 103),
      -INT8_C(  85), -INT8_C(  80), -INT8_C(  80),  INT8_C(  16),  INT8_C( 122), -INT8_C(  24), -INT8_C( 102), -INT8_C(  35),
       INT8_C(  34), -INT8_C( 118), -INT8_C( 119),  INT8_C(  50),  INT8_C(  49),  INT8_C(  21),  INT8_C(  21), -INT8_C(  99),
       INT8_C(  47),  INT8_C(  92),  INT8_C(  25), -INT8_C(  31),  INT8_C( 122),  INT8_C(  11),  INT8_C( 104),  INT8_C(  79),
           INT8_MAX,  INT8_C( 112), -INT8_C(  79),  INT8_C(   0), -INT8_C(  69),  INT8_C(   0),  INT8_C( 103),  INT8_C( 103),
      -INT8_C(  80),  INT8_C(  24),  INT8_C( 119),  INT8_C(  43),  INT8_C(   0),  INT8_C(  17),  INT8_C(   8),  INT8_C(  34),
      -INT8_C( 101), -INT8_C( 110),  INT8_C(  84), -INT8_C(  51), -INT8_C(  89),  INT8_C( 105),  INT8_C( 106), -INT8_C(  42),
      -INT8_C(  59), -INT8_C( 125), -INT8_C(  73),  INT8_C(  63), -INT8_C( 114),  INT8_C(  31), -INT8_C( 114),  INT8_C(  13),
      -INT8_C( 113),  INT8_C(  64),  INT8_C(  13),  INT8_C(  75),  INT8_C(  64),  INT8_C( 117), -INT8_C(  78), -INT8_C(  16),
      -INT8_C( 115),  INT8_C(  41),  INT8_C(  27), -INT8_C( 115),  INT8_C(  58),  INT8_C(  36), -INT8_C(  81), -INT8_C(  42),
      -INT8_C(  74),  INT8_C(   3), -INT8_C(  93),  INT8_C(  93),  INT8_C( 108),  INT8_C(  13),  INT8_C(  51),  INT8_C(  50),
      -INT8_C( 112), -INT8_C(  22),  INT8_C( 113),  INT8_C(  31),  INT8_C(  10),  INT8_C(   0),  INT8_C(  44), -INT8_C( 103),
       INT8_C(  64),  INT8_C(  58), -INT8_C(  28),      INT8_MIN, -INT8_C(  81), -INT8_C( 106),  INT8_C( 112),  INT8_C(  60),
      -INT8_C(  65), -INT8_C( 116), -INT8_C(  55), -INT8_C(   6), -INT8_C(  80),  INT8_C( 120), -INT8_C(  48),  INT8_C( 102),
       INT8_C( 123),  INT8_C( 115), -INT8_C(  61), -INT8_C(  25),      INT8_MIN, -INT8_C(  10),  INT8_C(  25),  INT8_C(  16),
      -INT8_C(  32), -INT8_C( 117),  INT8_C(  47), -INT8_C(  22), -INT8_C( 117),  INT8_C(  92), -INT8_C( 124), -INT8_C(  53),
      -INT8_C( 106),  INT8_C( 104),  INT8_C(  75),  INT8_C(  69), -INT8_C(   1), -INT8_C(  69), -INT8_C( 127), -INT8_C(  66),
       INT8_C(  71),  INT8_C(  74), -INT8_C(  72), -INT8_C(   9), -INT8_C(  62), -INT8_C( 120),  INT8_C(  93),  INT8_C(  61),
      -INT8_C(   5),  INT8_C(  32),  INT8_C(  36),  INT8_C( 123),  INT8_C(  22),  INT8_C(  62), -INT8_C( 116), -INT8_C(   9),
      -INT8_C(  55), -INT8_C(  69), -INT8_C(  31),  INT8_C(  84),  INT8_C(  23),  INT8_C( 101),  INT8_C(  31), -INT8_C(  83),
      -INT8_C(  50),  INT8_C( 106), -INT8_C(  14), -INT8_C(  51),  INT8_C(  37),  INT8_C( 115), -INT8_C( 117),  INT8_C( 109),
      -INT8_C(  67),  INT8_C(  68),  INT8_C( 100),      INT8_MAX, -INT8_C(  52), -INT8_C(  62), -INT8_C(  68), -INT8_C(  56),
      -INT8_C(  30), -INT8_C(  31),  INT8_C(  67), -INT8_C(   7),  INT8_C(  31), -INT8_C(  49), -INT8_C(  16), -INT8_C(  24),
      -INT8_C( 117), -INT8_C(  47),  INT8_C(  60), -INT8_C(  94),  INT8_C(  55),  INT8_C(  91),  INT8_C(  80),  INT8_C(   5),
      -INT8_C(  59),  INT8_C(  66), -INT8_C(  46), -INT8_C(  22), -INT8_C(  74),  INT8_C(  93),  INT8_C(  87),  INT8_C( 115),
      -INT8_C(  95), -INT8_C(  68), -INT8_C(  13),  INT8_C( 110),  INT8_C( 126), -INT8_C(  81),  INT8_C(  54) };
  static const int8_t e[] =
    { -INT8_C( 103),  INT8_C( 119),  INT8_C(  27), -INT8_C(  24), -INT8_C(  22), -INT8_C( 120),  INT8_C(  18),  INT8_C( 102),
       INT8_C(   0), -INT8_C(  21), -INT8_C(  63),  INT8_C(  41), -INT8_C(  69),  INT8_C(   6), -INT8_C(  94),  INT8_C(  67),
      -INT8_C(  25), -INT8_C(  71),  INT8_C( 111),  INT8_C(  50),  INT8_C( 106),  INT8_C(  79), -INT8_C( 122),  INT8_C(  63),
      -INT8_C( 104), -INT8_C(  75),  INT8_C(  20),  INT8_C(  97),  INT8_C(  37), -INT8_C(   6),  INT8_C(  63),  INT8_C(  42),
       INT8_C( 113), -INT8_C( 125), -INT8_C(  89),  INT8_C(  38),  INT8_C(  85), -INT8_C(  81), -INT8_C(  62),  INT8_C(  85),
      -INT8_C(  83), -INT8_C( 125), -INT8_C( 123),  INT8_C( 104),  INT8_C(  55),  INT8_C(  39), -INT8_C(  85),  INT8_C(  30),
      -INT8_C(  78),  INT8_C(  26),  INT8_C( 119),  INT8_C( 111), -INT8_C(  12), -INT8_C( 115),  INT8_C(  43), -INT8_C(  81),
      -INT8_C(  91), -INT8_C( 112),  INT8_C(  47), -INT8_C(  41), -INT8_C( 118),  INT8_C(  80), -INT8_C( 123), -INT8_C( 123),
       INT8_C(  46),  INT8_C(  61), -INT8_C(  85), -INT8_C( 125), -INT8_C(  47), -INT8_C(  74), -INT8_C(  25),  INT8_C(  66),
       INT8_C(  16),  INT8_C( 108),  INT8_C(  21), -INT8_C(  44),  INT8_C( 116), -INT8_C(  63), -INT8_C(  29),  INT8_C( 116),
      -INT8_C( 123), -INT8_C( 120), -INT8_C(  29), -INT8_C(  49),  INT8_C( 103),  INT8_C( 111), -INT8_C(  32),  INT8_C(  25),
      -INT8_C(   1), -INT8_C( 118),  INT8_C(  20),  INT8_C(  31),  INT8_C(  65), -INT8_C( 103), -INT8_C( 123),  INT8_C( 100),
      -INT8_C(  69), -INT8_C(  35),  INT8_C( 119), -INT8_C(  61),  INT8_C(   6), -INT8_C(  64),  INT8_C( 112),  INT8_C(  22),
      -INT8_C(  70), -INT8_C(  88), -INT8_C( 122),  INT8_C(  46), -INT8_C(  47),  INT8_C( 105),  INT8_C(  85),  INT8_C(  87),
      -INT8_C(  15), -INT8_C(  73), -INT8_C( 120),  INT8_C(  43),  INT8_C(   8),  INT8_C( 104),  INT8_C(  69),  INT8_C(   7),
       INT8_C(  90), -INT8_C(  44), -INT8_C( 112), -INT8_C( 101),  INT8_C( 110),  INT8_C(  98), -INT8_C( 121), -INT8_C( 127),
      -INT8_C(  78), -INT8_C(   2), -INT8_C(  74), -INT8_C(  21),  INT8_C(  25), -INT8_C(  75), -INT8_C(  50), -INT8_C(  45),
       INT8_C(  44),  INT8_C(  84), -INT8_C( 120), -INT8_C(   2),  INT8_C(  67),  INT8_C(  87), -INT8_C(  92), -INT8_C(  82),
      -INT8_C(  16), -INT8_C( 106), -INT8_C(  76), -INT8_C(   8),  INT8_C(  69),  INT8_C( 120), -INT8_C(   4), -INT8_C(  68),
      -INT8_C(  82), -INT8_C(  70),  INT8_C(  59), -INT8_C(  73), -INT8_C(  91), -INT8_C(  62), -INT8_C(  32), -INT8_C( 103),
      -INT8_C(  64), -INT8_C( 106), -INT8_C( 124),  INT8_C(  30),  INT8_C(  27),  INT8_C(   3),      INT8_MIN,  INT8_C(  32),
      -INT8_C(  86), -INT8_C( 127),  INT8_C(  69),  INT8_C(  46), -INT8_C(  40),  INT8_C(  71),  INT8_C(  54), -INT8_C(  56),
      -INT8_C(  35), -INT8_C(  53), -INT8_C(  64), -INT8_C(  63), -INT8_C(  31), -INT8_C(  65),  INT8_C( 125), -INT8_C( 113),
       INT8_C(  83),  INT8_C(  71), -INT8_C(   6), -INT8_C(  12), -INT8_C( 126), -INT8_C(  26),  INT8_C(  63),  INT8_C(  26),
      -INT8_C(  74), -INT8_C(  58),  INT8_C(  56), -INT8_C(  47),  INT8_C(  21),  INT8_C(  67),  INT8_C(  25),  INT8_C(   0),
      -INT8_C(  60),  INT8_C(  94),  INT8_C(  47),  INT8_C( 122), -INT8_C(   7),  INT8_C( 101), -INT8_C(  70), -INT8_C(  29),
      -INT8_C(  50),  INT8_C(  38), -INT8_C(  91), -INT8_C(  81), -INT8_C(  27), -INT8_C( 118), -INT8_C(  40),  INT8_C(  52),
       INT8_C( 105),  INT8_C(  56), -INT8_C(  75), -INT8_C(  21),  INT8_C(  30), -INT8_C(  74),  INT8_C(   1),  INT8_C(  52),
      -INT8_C(  56), -INT8_C(  60), -INT8_C(  64), -INT8_C(  35),  INT8_C(  76),  INT8_C(  77), -INT8_C(  35), -INT8_C(  52),
       INT8_C(  12), -INT8_C(  51),  INT8_C(  21),  INT8_C(  48),  INT8_C( 113), -INT8_C(  49), -INT8_C(  95),  INT8_C(  63),
      -INT8_C(  12), -INT8_C( 102),  INT8_C( 115), -INT8_C(  38),  INT8_C(  88),  INT8_C(  75),  INT8_C(  94),  INT8_C(  38),
       INT8_C(  99),  INT8_C(  55), -INT8_C(  11), -INT8_C( 126),  INT8_C(   7), -INT8_C( 118), -INT8_C(  73), -INT8_C(  63),
      -INT8_C(  40),  INT8_C(  74), -INT8_C( 109), -INT8_C(  33),  INT8_C(  52),  INT8_C(  54), -INT8_C(  85),  INT8_C(  64),
       INT8_C( 125),  INT8_C(  82),  INT8_C(  82), -INT8_C(  18),  INT8_C(  34),  INT8_C(  44),  INT8_C(  57),  INT8_C(  73),
      -INT8_C(  30), -INT8_C(  84), -INT8_C(  79),  INT8_C(  83),  INT8_C(  73), -INT8_C(  64), -INT8_C(  51),  INT8_C(  91),
      -INT8_C(   9), -INT8_C(  40), -INT8_C(  10), -INT8_C(  38), -INT8_C(  21), -INT8_C(  25), -INT8_C( 100), -INT8_C(  93),
      -INT8_C(  54),  INT8_C(  46),  INT8_C(  70),  INT8_C(   3),  INT8_C( 107),  INT8_C(  78),  INT8_C(  67),  INT8_C(  28),
       INT8_C(  99), -INT8_C( 106), -INT8_C( 124), -INT8_C(   8), -INT8_C(  34), -INT8_C(  67),  INT8_C(  65), -INT8_C(  64),
       INT8_C(  85), -INT8_C(  92),  INT8_C(  96), -INT8_C(  98), -INT8_C( 113),  INT8_C(  38),  INT8_C(  75),  INT8_C(  56),
      -INT8_C(  37),  INT8_C( 123),  INT8_C(  18), -INT8_C(  23),  INT8_C(  98),  INT8_C(   7), -INT8_C(  83),  INT8_C(  49),
       INT8_C(  54),  INT8_C(  16),  INT8_C(  52), -INT8_C(  43), -INT8_C(  98),  INT8_C(  51), -INT8_C(  68),  INT8_C(   1),
       INT8_C(  13), -INT8_C(   5),  INT8_C(  71),  INT8_C(   5), -INT8_C(   2), -INT8_C(  93), -INT8_C(   2), -INT8_C( 119),
       INT8_C(  52),  INT8_C(  12),  INT8_C(  39), -INT8_C(  84),  INT8_C( 100),  INT8_C( 114),  INT8_C(  73),  INT8_C(  48),
       INT8_C(  55), -INT8_C(  10),  INT8_C(  25),  INT8_C( 106), -INT8_C(  67), -INT8_C(  58), -INT8_C( 127), -INT8_C( 120),
       INT8_C(  22), -INT8_C(  75), -INT8_C(  56), -INT8_C(  42),  INT8_C(  45), -INT8_C( 110),  INT8_C(  64), -INT8_C( 116),
      -INT8_C(  76), -INT8_C(   2),  INT8_C(  38), -INT8_C(  24),  INT8_C(  70), -INT8_C(  46),  INT8_C( 113), -INT8_C( 105),
      -INT8_C(  34),  INT8_C(   3),  INT8_C(  57),  INT8_C(  63),  INT8_C(  11), -INT8_C(  93),  INT8_C(  64), -INT8_C(  65),
       INT8_C(  89), -INT8_C(  26),  INT8_C(  42), -INT8_C(  71),  INT8_C(  24), -INT8_C( 110),  INT8_C(   9),  INT8_C(  54),
           INT8_MIN,  INT8_C(  23),  INT8_C(  49), -INT8_C(  83), -INT8_C(  87),  INT8_C( 114), -INT8_C(  24),  INT8_C( 125),
       INT8_C(  20),  INT8_C(  14),  INT8_C(  79),  INT8_C(  90), -INT8_C(  32), -INT8_C( 104), -INT8_C(  24), -INT8_C(  14),
      -INT8_C( 116),  INT8_C(  33),  INT8_C(  49),  INT8_C(  20),  INT8_C(  63), -INT8_C(  80),  INT8_C(  53), -INT8_C(  16),
       INT8_C( 103),  INT8_C( 126),  INT8_C(  12), -INT8_C( 121), -INT8_C( 113),  INT8_C(  15),  INT8_C(  10),  INT8_C( 116),
       INT8_C( 100),  INT8_C(  59),  INT8_C( 119),  INT8_C( 106),  INT8_C(  75), -INT8_C(  42), -INT8_C(  87), -INT8_C(  21),
       INT8_C(  94), -INT8_C(  48),  INT8_C(  28),  INT8_C( 118),  INT8_C( 104), -INT8_C( 120),  INT8_C( 104), -INT8_C(  18),
       INT8_C( 124), -INT8_C(  39),  INT8_C(   2),  INT8_C( 101),  INT8_C(  73),  INT8_C(  10), -INT8_C(  72),  INT8_C(  79),
      -INT8_C( 119),  INT8_C(  11), -INT8_C(  42), -INT8_C(  46),  INT8_C(  17), -INT8_C( 108), -INT8_C( 100), -INT8_C(   5),
      -INT8_C(  44),  INT8_C(  20), -INT8_C( 126), -INT8_C( 127), -INT8_C( 115),  INT8_C(  13),  INT8_C( 117), -INT8_C(  20),
      -INT8_C(  26),  INT8_C(  96),  INT8_C(  98),  INT8_C(  71), -INT8_C(  20),  INT8_C(  58), -INT8_C(  32),  INT8_C( 104),
       INT8_C(  99),  INT8_C(  58),  INT8_C( 124), -INT8_C(   5), -INT8_C(  64), -INT8_C(  89), -INT8_C( 117),  INT8_C(  73),
      -INT8_C( 116),  INT8_C(  32),  INT8_C(  28),  INT8_C( 124), -INT8_C(  75), -INT8_C(  72), -INT8_C(  95), -INT8_C( 122),
      -INT8_C(  43),  INT8_C(   7),  INT8_C( 124),  INT8_C(  98),  INT8_C(  21), -INT8_C(  15),  INT8_C(  78), -INT8_C(  12),
       INT8_C(  85),  INT8_C(  79),  INT8_C(  59),  INT8_C(  65),  INT8_C( 122),  INT8_C(  27), -INT8_C( 102), -INT8_C(  99),
      -INT8_C(  47), -INT8_C( 118), -INT8_C( 119), -INT8_C( 110),  INT8_C(  49), -INT8_C(  30),  INT8_C(  21), -INT8_C(  99),
       INT8_C(   2), -INT8_C(   9),  INT8_C(  25), -INT8_C(  73),  INT8_C( 122),  INT8_C( 123),  INT8_C( 104),  INT8_C(  79),
      -INT8_C( 126),  INT8_C(  39), -INT8_C(  68),  INT8_C(   0), -INT8_C(  69), -INT8_C(  35),  INT8_C( 103),  INT8_C( 103),
       INT8_C(  45),  INT8_C(  24), -INT8_C(  82),  INT8_C(  43), -INT8_C(  30),  INT8_C(  88),  INT8_C(   8),  INT8_C(  34),
      -INT8_C( 101), -INT8_C(  21),  INT8_C(  69), -INT8_C(  51), -INT8_C(  89),  INT8_C( 105),  INT8_C( 106), -INT8_C(  42),
       INT8_C(  24), -INT8_C( 125), -INT8_C(  73),  INT8_C(  63), -INT8_C( 114),  INT8_C(  31),  INT8_C(  69),  INT8_C(  46),
      -INT8_C( 113),  INT8_C(  64),  INT8_C(  13),  INT8_C(  75),  INT8_C(  64),  INT8_C(  81), -INT8_C(  78),  INT8_C(  12),
       INT8_C(  24),  INT8_C(  41),  INT8_C(  27), -INT8_C( 115), -INT8_C(  27),  INT8_C(  36), -INT8_C(  83),  INT8_C(  99),
       INT8_C(   1), -INT8_C(  13), -INT8_C(  93),  INT8_C(  93),  INT8_C(  20), -INT8_C(  32), -INT8_C(  97),  INT8_C(  44),
      -INT8_C( 112),  INT8_C(  38), -INT8_C(  11),  INT8_C(  31),  INT8_C(  88),  INT8_C(   0),  INT8_C(  44), -INT8_C(  79),
       INT8_C(  59),  INT8_C(  58), -INT8_C(  28),  INT8_C(  26),  INT8_C(   4),  INT8_C(   2),  INT8_C(  38),  INT8_C(  28),
      -INT8_C( 113), -INT8_C(  23), -INT8_C(  55),  INT8_C( 117), -INT8_C(   1), -INT8_C(  60), -INT8_C(  40),  INT8_C(   0),
      -INT8_C(  73),  INT8_C(  97), -INT8_C(  49), -INT8_C(  25),  INT8_C(  65),  INT8_C( 110), -INT8_C(   9),  INT8_C(  83),
      -INT8_C(  32), -INT8_C(  20),  INT8_C(  47), -INT8_C(  22), -INT8_C( 117),  INT8_C(  92), -INT8_C(  97),  INT8_C(  98),
      -INT8_C(  78),  INT8_C( 104),  INT8_C( 124), -INT8_C(  74), -INT8_C(  60), -INT8_C(  69), -INT8_C( 127),  INT8_C(  83),
      -INT8_C( 116),  INT8_C(  74), -INT8_C(  72), -INT8_C( 117), -INT8_C(  62), -INT8_C(  95),  INT8_C(  93),  INT8_C( 100),
       INT8_C(   2),  INT8_C(  32),  INT8_C(  36),  INT8_C( 123), -INT8_C(  55),  INT8_C(  62), -INT8_C( 116), -INT8_C(   9),
       INT8_C(  19), -INT8_C(  69), -INT8_C(  31),  INT8_C(  84), -INT8_C(  88),  INT8_C( 101),  INT8_C(  31), -INT8_C(  83),
      -INT8_C(  50),  INT8_C(  24), -INT8_C(  14), -INT8_C(  51), -INT8_C(  69), -INT8_C(  29), -INT8_C(  60),  INT8_C(  71),
      -INT8_C(  67), -INT8_C( 115),  INT8_C( 100),      INT8_MAX,  INT8_C(  46),  INT8_C(  94), -INT8_C(  68), -INT8_C(  56),
      -INT8_C(  30), -INT8_C(  31),  INT8_C( 115), -INT8_C(   7),  INT8_C(  31),  INT8_C(  10), -INT8_C(  16), -INT8_C(  24),
      -INT8_C(  77), -INT8_C(  47),  INT8_C(  60),  INT8_C(  91),  INT8_C(  24),  INT8_C(  91),  INT8_C(  80), -INT8_C(  59),
      -INT8_C(  59),  INT8_C(  66),  INT8_C(  54), -INT8_C(  13), -INT8_C(  87), -INT8_C(   6),  INT8_C(  58),  INT8_C( 118),
      -INT8_C( 121),  INT8_C(  13), -INT8_C(  13),  INT8_C( 110),  INT8_C( 107), -INT8_C(  81), -INT8_C(  27) };

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
    rv = simde_svsel_s8(pv, av, bv);

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

    ev = simde_svsel_s8(pv, av, bv);

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
test_simde_x_svsel_s16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) };
  static const int16_t a[] =
    { -INT16_C( 32446),  INT16_C(  1308), -INT16_C( 13152),  INT16_C( 20426), -INT16_C(   283),  INT16_C(  3999), -INT16_C( 27642),  INT16_C( 12351),
       INT16_C( 22996), -INT16_C(  7117), -INT16_C( 31363),  INT16_C(  4849),  INT16_C(  5988),  INT16_C(   917),  INT16_C( 30347), -INT16_C( 13002),
       INT16_C( 21240), -INT16_C( 26413), -INT16_C( 25314),  INT16_C(  1255), -INT16_C( 31077), -INT16_C( 24045),  INT16_C( 21275), -INT16_C(  4142),
       INT16_C(  1452),  INT16_C( 10707), -INT16_C( 14966), -INT16_C(  4548), -INT16_C( 11812),  INT16_C( 26609),  INT16_C( 10055),  INT16_C( 16181),
       INT16_C(  2170), -INT16_C( 26409), -INT16_C( 16475),  INT16_C( 16540), -INT16_C( 20411),  INT16_C( 24802), -INT16_C( 19453), -INT16_C( 20656),
       INT16_C(  9145),  INT16_C( 17368),  INT16_C(  5352), -INT16_C( 15055),  INT16_C(  8933),  INT16_C( 11564),  INT16_C( 24906), -INT16_C( 15252),
       INT16_C( 17513),  INT16_C(  3676), -INT16_C(  1789),  INT16_C( 18511),  INT16_C( 12713), -INT16_C( 21335), -INT16_C(  1562), -INT16_C( 24741),
       INT16_C( 13084),  INT16_C(  1507),  INT16_C(  5192),  INT16_C( 11722), -INT16_C(  2505), -INT16_C( 32422), -INT16_C( 14504), -INT16_C( 16059),
      -INT16_C( 24309),  INT16_C(  3792),  INT16_C(  8090),  INT16_C( 17238), -INT16_C(   176),  INT16_C( 14063),  INT16_C( 19192),  INT16_C(  5590),
      -INT16_C( 18050), -INT16_C( 14822), -INT16_C(  6963),  INT16_C(  1267),  INT16_C( 20186),  INT16_C( 12933), -INT16_C( 13803),  INT16_C(  8436),
      -INT16_C( 15252),  INT16_C(  1582), -INT16_C( 31517),  INT16_C( 13130),  INT16_C( 14724),  INT16_C( 31850),  INT16_C( 16516),  INT16_C(   657),
      -INT16_C( 21511), -INT16_C( 14648), -INT16_C( 17521),  INT16_C( 27339),  INT16_C( 20489),  INT16_C(  7836), -INT16_C( 28645), -INT16_C( 30914),
       INT16_C( 27732),  INT16_C( 14221), -INT16_C( 10255),  INT16_C( 30059), -INT16_C( 10991), -INT16_C( 27151), -INT16_C( 31979),  INT16_C(  3735),
       INT16_C( 24366), -INT16_C( 16684), -INT16_C( 24806),  INT16_C(  9256), -INT16_C( 15120),  INT16_C(  2882), -INT16_C( 32427), -INT16_C( 22126),
       INT16_C(  8173), -INT16_C(  8479),  INT16_C( 19703),  INT16_C(  2131),  INT16_C( 17697),  INT16_C( 13981),  INT16_C( 13512), -INT16_C(  2492),
       INT16_C(  6291), -INT16_C( 21068), -INT16_C(  9032), -INT16_C( 22319),  INT16_C(  5281), -INT16_C(  2381),  INT16_C( 17813), -INT16_C( 32097),
      -INT16_C( 32668),  INT16_C( 23393), -INT16_C( 19252), -INT16_C(  4765),  INT16_C(   249), -INT16_C( 16093),  INT16_C( 26420), -INT16_C( 14408),
       INT16_C( 27776),  INT16_C( 14453),  INT16_C( 17993), -INT16_C(  5408), -INT16_C( 27814), -INT16_C(  4128),  INT16_C( 32728),  INT16_C( 15474),
      -INT16_C( 11520), -INT16_C( 13160), -INT16_C(  1145), -INT16_C( 32326), -INT16_C(  8708),  INT16_C( 12354), -INT16_C(  1467), -INT16_C( 14856),
       INT16_C( 28007), -INT16_C( 20227), -INT16_C(  8781),  INT16_C(  3738),  INT16_C( 31344),  INT16_C( 18685),  INT16_C( 28665), -INT16_C(  1660),
       INT16_C(  7234), -INT16_C( 13626), -INT16_C( 32744),  INT16_C(  5195), -INT16_C( 29347), -INT16_C( 23996),  INT16_C( 15496), -INT16_C(  4249),
       INT16_C( 25769),  INT16_C( 23967),  INT16_C( 14657), -INT16_C( 20117),  INT16_C( 26803), -INT16_C( 21255),  INT16_C( 32472),  INT16_C(  6822),
       INT16_C( 27802), -INT16_C( 19740),  INT16_C( 12268),  INT16_C( 18886),  INT16_C(  3005),  INT16_C( 17900),  INT16_C( 21319), -INT16_C(  3788),
      -INT16_C( 11336), -INT16_C(  1714), -INT16_C( 18164), -INT16_C( 16469), -INT16_C( 23519), -INT16_C(  1685),  INT16_C(  4386), -INT16_C( 17132),
      -INT16_C(  1923),  INT16_C( 26991),  INT16_C( 13864), -INT16_C(  6733), -INT16_C( 24767), -INT16_C( 30678),  INT16_C( 24306), -INT16_C( 21895),
      -INT16_C( 14543),  INT16_C( 15780),  INT16_C( 20352), -INT16_C( 23812),  INT16_C( 26611),  INT16_C(  5787), -INT16_C( 20615), -INT16_C(  2349),
       INT16_C( 17064), -INT16_C( 12192),  INT16_C(  4984), -INT16_C( 17995), -INT16_C(  8270), -INT16_C( 23486), -INT16_C( 17603),  INT16_C( 28239),
      -INT16_C(  3197),  INT16_C(   939), -INT16_C( 22718),  INT16_C( 13733),  INT16_C( 16654), -INT16_C( 30901),  INT16_C(  7920), -INT16_C( 26498),
      -INT16_C(  8607), -INT16_C(  9880),  INT16_C(  7665), -INT16_C( 23661), -INT16_C( 10756),  INT16_C( 14663), -INT16_C( 26992),  INT16_C(  5031),
       INT16_C( 21129), -INT16_C( 13545), -INT16_C( 17159),  INT16_C(  2049),  INT16_C( 19709), -INT16_C(  4465),  INT16_C(  3435), -INT16_C( 13178),
      -INT16_C(  4117), -INT16_C(  9051),  INT16_C( 14348),  INT16_C(  2431), -INT16_C( 14579), -INT16_C( 25022), -INT16_C(  5539), -INT16_C(  6223),
      -INT16_C( 14276),  INT16_C( 14002), -INT16_C( 19579), -INT16_C( 32194), -INT16_C( 13056),  INT16_C( 27504), -INT16_C(  2085), -INT16_C( 14793),
      -INT16_C(  8986), -INT16_C(  3421),  INT16_C(  8725),  INT16_C(  8955),  INT16_C( 16105),  INT16_C( 18368),  INT16_C( 29224),  INT16_C( 25646),
      -INT16_C(  8134), -INT16_C( 16486), -INT16_C( 10092), -INT16_C( 27582), -INT16_C( 19802), -INT16_C( 32257),  INT16_C( 13993), -INT16_C( 28857),
      -INT16_C(  5614),  INT16_C( 10114),  INT16_C( 32013), -INT16_C(  2486),  INT16_C(  2747), -INT16_C(  7363),  INT16_C( 27516), -INT16_C( 18616),
      -INT16_C(  7604), -INT16_C(  8074), -INT16_C( 18245),  INT16_C( 24948),  INT16_C( 29547),  INT16_C(  5346),  INT16_C( 10665), -INT16_C( 17500),
       INT16_C(  9748),  INT16_C(  8675),  INT16_C( 11683),  INT16_C( 24343),  INT16_C( 21815), -INT16_C( 19390), -INT16_C( 30016),  INT16_C(  3179),
      -INT16_C(  7827),  INT16_C( 10476),  INT16_C( 24730),  INT16_C(  1417),  INT16_C( 27603),  INT16_C( 31769), -INT16_C( 17004), -INT16_C( 22472),
       INT16_C(  7139), -INT16_C( 30775), -INT16_C(  7864),  INT16_C( 32742),  INT16_C( 10294), -INT16_C(  2509), -INT16_C( 24909),  INT16_C(  8195),
      -INT16_C(  4224),  INT16_C(  6728), -INT16_C( 11952),  INT16_C(  8991),  INT16_C( 14396), -INT16_C( 12128), -INT16_C(  9994), -INT16_C(  9863),
       INT16_C( 17139),  INT16_C( 15200),  INT16_C( 17955),  INT16_C( 22970), -INT16_C(  4497),  INT16_C(  8784),  INT16_C( 21388),  INT16_C(  3138),
      -INT16_C( 30142), -INT16_C( 28122),  INT16_C( 17755), -INT16_C( 26698),  INT16_C( 22142),  INT16_C( 29799), -INT16_C(  8146),  INT16_C(  8525),
      -INT16_C( 20957),  INT16_C( 18012),  INT16_C(  5876),  INT16_C( 25504), -INT16_C(  4092), -INT16_C( 28283), -INT16_C( 14525), -INT16_C( 31331),
      -INT16_C( 15279), -INT16_C( 21480), -INT16_C( 12791), -INT16_C( 30909), -INT16_C( 21724),  INT16_C( 21243),  INT16_C( 18827), -INT16_C( 20877),
      -INT16_C( 12297), -INT16_C(  5131), -INT16_C( 27163), -INT16_C(  5553), -INT16_C( 11131), -INT16_C( 14213),  INT16_C(  6300), -INT16_C(  4787),
       INT16_C( 26076), -INT16_C(  6502), -INT16_C(  8909),  INT16_C( 22381),  INT16_C( 27016),  INT16_C(  5289),  INT16_C(  7346), -INT16_C( 22078),
      -INT16_C( 18453), -INT16_C( 11884), -INT16_C(  7348), -INT16_C( 11845),  INT16_C( 14008),  INT16_C( 21657), -INT16_C(  6322),  INT16_C( 11073),
      -INT16_C(  9396), -INT16_C( 32751),  INT16_C( 32441),  INT16_C( 16855), -INT16_C( 32281), -INT16_C( 26283),  INT16_C(  6301), -INT16_C( 30398),
      -INT16_C( 10289),  INT16_C(  7258),  INT16_C(  5562),  INT16_C( 29421), -INT16_C( 30901), -INT16_C( 26170),  INT16_C(  2158), -INT16_C( 17724),
      -INT16_C( 10781), -INT16_C( 25542),  INT16_C(  4692),  INT16_C( 15326),  INT16_C( 13203),  INT16_C( 12501),  INT16_C(  5963),  INT16_C(  7097),
       INT16_C(  5102), -INT16_C( 22217),  INT16_C(  9256),  INT16_C( 29467), -INT16_C(  7509),  INT16_C(  6413), -INT16_C( 11798), -INT16_C( 12844),
       INT16_C(  3751), -INT16_C(  1174),  INT16_C( 18464), -INT16_C( 19658),  INT16_C(  2939), -INT16_C( 14364), -INT16_C( 25309),  INT16_C(  4578),
       INT16_C(  6577), -INT16_C(  9798), -INT16_C( 10691), -INT16_C(  5811),  INT16_C( 23224), -INT16_C( 24062), -INT16_C( 10709), -INT16_C( 11665),
      -INT16_C(  9755),  INT16_C(  1485),  INT16_C(  1057), -INT16_C( 25159), -INT16_C( 25329),  INT16_C( 12900),  INT16_C( 17978), -INT16_C(  5308) };
  static const int16_t e[] =
    { -INT16_C( 32446),  INT16_C(  1308),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 30347), -INT16_C( 13002),
       INT16_C( 21240),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1255),  INT16_C(     0), -INT16_C( 24045),  INT16_C(     0),  INT16_C(     0),
       INT16_C(  1452),  INT16_C(     0), -INT16_C( 14966),  INT16_C(     0),  INT16_C(     0),  INT16_C( 26609),  INT16_C( 10055),  INT16_C(     0),
       INT16_C(     0), -INT16_C( 26409),  INT16_C(     0),  INT16_C( 16540),  INT16_C(     0),  INT16_C( 24802), -INT16_C( 19453), -INT16_C( 20656),
       INT16_C(     0),  INT16_C(     0),  INT16_C(  5352), -INT16_C( 15055),  INT16_C(     0),  INT16_C( 11564),  INT16_C(     0), -INT16_C( 15252),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 18511),  INT16_C( 12713), -INT16_C( 21335), -INT16_C(  1562),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(  5192),  INT16_C(     0),  INT16_C(     0), -INT16_C( 32422),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 24309),  INT16_C(  3792),  INT16_C(     0),  INT16_C( 17238),  INT16_C(     0),  INT16_C( 14063),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1267),  INT16_C(     0),  INT16_C( 12933), -INT16_C( 13803),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C( 31517),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16516),  INT16_C(     0),
       INT16_C(     0), -INT16_C( 14648),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 28645),  INT16_C(     0),
       INT16_C(     0),  INT16_C( 14221), -INT16_C( 10255),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  9256), -INT16_C( 15120),  INT16_C(     0), -INT16_C( 32427), -INT16_C( 22126),
       INT16_C(  8173),  INT16_C(     0),  INT16_C( 19703),  INT16_C(     0),  INT16_C( 17697),  INT16_C( 13981),  INT16_C(     0),  INT16_C(     0),
       INT16_C(  6291), -INT16_C( 21068),  INT16_C(     0),  INT16_C(     0),  INT16_C(  5281), -INT16_C(  2381),  INT16_C(     0), -INT16_C( 32097),
       INT16_C(     0),  INT16_C( 23393),  INT16_C(     0),  INT16_C(     0),  INT16_C(   249), -INT16_C( 16093),  INT16_C( 26420), -INT16_C( 14408),
       INT16_C( 27776),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  4128),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(  1145), -INT16_C( 32326),  INT16_C(     0),  INT16_C( 12354), -INT16_C(  1467),  INT16_C(     0),
       INT16_C(     0), -INT16_C( 20227),  INT16_C(     0),  INT16_C(  3738),  INT16_C( 31344),  INT16_C( 18685),  INT16_C( 28665), -INT16_C(  1660),
       INT16_C(  7234),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  4249),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 20117),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  6822),
       INT16_C( 27802), -INT16_C( 19740),  INT16_C( 12268),  INT16_C( 18886),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21319),  INT16_C(     0),
      -INT16_C( 11336),  INT16_C(     0), -INT16_C( 18164),  INT16_C(     0), -INT16_C( 23519), -INT16_C(  1685),  INT16_C(  4386),  INT16_C(     0),
      -INT16_C(  1923),  INT16_C(     0),  INT16_C(     0), -INT16_C(  6733), -INT16_C( 24767), -INT16_C( 30678),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 23812),  INT16_C(     0),  INT16_C(     0), -INT16_C( 20615),  INT16_C(     0),
       INT16_C( 17064), -INT16_C( 12192),  INT16_C(  4984), -INT16_C( 17995),  INT16_C(     0),  INT16_C(     0), -INT16_C( 17603),  INT16_C(     0),
       INT16_C(     0),  INT16_C(   939), -INT16_C( 22718),  INT16_C( 13733),  INT16_C( 16654),  INT16_C(     0),  INT16_C(  7920), -INT16_C( 26498),
       INT16_C(     0),  INT16_C(     0),  INT16_C(  7665),  INT16_C(     0), -INT16_C( 10756),  INT16_C(     0),  INT16_C(     0),  INT16_C(  5031),
       INT16_C( 21129), -INT16_C( 13545),  INT16_C(     0),  INT16_C(     0),  INT16_C( 19709),  INT16_C(     0),  INT16_C(  3435),  INT16_C(     0),
      -INT16_C(  4117), -INT16_C(  9051),  INT16_C( 14348),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  5539), -INT16_C(  6223),
       INT16_C(     0),  INT16_C( 14002),  INT16_C(     0),  INT16_C(     0), -INT16_C( 13056),  INT16_C(     0), -INT16_C(  2085),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(  8725),  INT16_C(  8955),  INT16_C( 16105),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(  8134), -INT16_C( 16486),  INT16_C(     0), -INT16_C( 27582), -INT16_C( 19802),  INT16_C(     0),  INT16_C( 13993), -INT16_C( 28857),
      -INT16_C(  5614),  INT16_C( 10114),  INT16_C(     0), -INT16_C(  2486),  INT16_C(  2747), -INT16_C(  7363),  INT16_C(     0), -INT16_C( 18616),
      -INT16_C(  7604),  INT16_C(     0), -INT16_C( 18245),  INT16_C( 24948),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 17500),
       INT16_C(  9748),  INT16_C(  8675),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21815), -INT16_C( 19390),  INT16_C(     0),  INT16_C(  3179),
      -INT16_C(  7827),  INT16_C( 10476),  INT16_C( 24730),  INT16_C(     0),  INT16_C(     0),  INT16_C( 31769),  INT16_C(     0),  INT16_C(     0),
       INT16_C(  7139),  INT16_C(     0), -INT16_C(  7864),  INT16_C(     0),  INT16_C( 10294),  INT16_C(     0), -INT16_C( 24909),  INT16_C(     0),
       INT16_C(     0),  INT16_C(  6728),  INT16_C(     0),  INT16_C(  8991),  INT16_C( 14396),  INT16_C(     0), -INT16_C(  9994), -INT16_C(  9863),
       INT16_C(     0),  INT16_C( 15200),  INT16_C(     0),  INT16_C( 22970),  INT16_C(     0),  INT16_C(  8784),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 30142), -INT16_C( 28122),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  8146),  INT16_C(  8525),
      -INT16_C( 20957),  INT16_C( 18012),  INT16_C(  5876),  INT16_C( 25504),  INT16_C(     0), -INT16_C( 28283),  INT16_C(     0), -INT16_C( 31331),
       INT16_C(     0),  INT16_C(     0), -INT16_C( 12791), -INT16_C( 30909),  INT16_C(     0),  INT16_C( 21243),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 12297), -INT16_C(  5131),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14213),  INT16_C(     0), -INT16_C(  4787),
       INT16_C(     0),  INT16_C(     0), -INT16_C(  8909),  INT16_C(     0),  INT16_C( 27016),  INT16_C(  5289),  INT16_C(  7346),  INT16_C(     0),
      -INT16_C( 18453),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11845),  INT16_C( 14008),  INT16_C( 21657),  INT16_C(     0),  INT16_C( 11073),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 32281),  INT16_C(     0),  INT16_C(     0), -INT16_C( 30398),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 30901),  INT16_C(     0),  INT16_C(  2158), -INT16_C( 17724),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  7097),
       INT16_C(     0), -INT16_C( 22217),  INT16_C(     0),  INT16_C( 29467),  INT16_C(     0),  INT16_C(  6413), -INT16_C( 11798),  INT16_C(     0),
       INT16_C(  3751),  INT16_C(     0),  INT16_C( 18464), -INT16_C( 19658),  INT16_C(     0),  INT16_C(     0), -INT16_C( 25309),  INT16_C(  4578),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  5811),  INT16_C( 23224), -INT16_C( 24062), -INT16_C( 10709),  INT16_C(     0),
      -INT16_C(  9755),  INT16_C(  1485),  INT16_C(     0),  INT16_C(     0), -INT16_C( 25329),  INT16_C( 12900),  INT16_C( 17978),  INT16_C(     0) };

  static int16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t
      rv,
      av = simde_svld1_s16(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(INT16_C(0)));
    rv = simde_x_svsel_s16_z(pv, av);

    simde_svst1_s16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vi16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(int16_t)], a[1024 / sizeof(int16_t)], e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_s16(pg, &(a[i]));

    ev = simde_x_svsel_s16_z(pv, av);

    simde_svst1_s16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsel_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) };
  static const int16_t a[] =
    { -INT16_C(  3940), -INT16_C( 17972), -INT16_C( 28147),  INT16_C(   865), -INT16_C( 14813), -INT16_C(  8805),  INT16_C( 23710), -INT16_C( 24594),
       INT16_C( 24512), -INT16_C( 23631), -INT16_C( 12820), -INT16_C( 23024),  INT16_C( 20905), -INT16_C( 30792),  INT16_C( 11418),  INT16_C( 14000),
       INT16_C( 32028),  INT16_C( 10735),  INT16_C( 20495),  INT16_C( 12845), -INT16_C( 14314), -INT16_C( 19441), -INT16_C(   731), -INT16_C(  6829),
       INT16_C(  1117),  INT16_C( 18825), -INT16_C( 26158),  INT16_C( 31728), -INT16_C( 22294), -INT16_C( 31741), -INT16_C( 19500), -INT16_C(  3910),
      -INT16_C( 22224),  INT16_C( 16153),  INT16_C( 18169),  INT16_C(  4209), -INT16_C( 32753),  INT16_C( 13508),  INT16_C(  6270), -INT16_C(  9447),
      -INT16_C( 24036), -INT16_C(  4572),  INT16_C(  5179),  INT16_C(  9578),  INT16_C( 28092), -INT16_C( 28503),  INT16_C( 25376),  INT16_C( 20864),
      -INT16_C( 26100),  INT16_C(  1680),  INT16_C(   736), -INT16_C(  4330), -INT16_C(  9598),  INT16_C(    35),  INT16_C( 15858),  INT16_C(  4059),
       INT16_C(   223),  INT16_C(  7165),  INT16_C( 26388), -INT16_C( 11968), -INT16_C(  5420), -INT16_C(  2719), -INT16_C(  7603),  INT16_C( 23110),
      -INT16_C( 10628),  INT16_C( 23648),  INT16_C( 30424),  INT16_C( 23372),  INT16_C( 28496),  INT16_C( 17243),  INT16_C( 14252), -INT16_C( 29614),
       INT16_C( 20279),  INT16_C( 19367), -INT16_C(  6217), -INT16_C( 29924),  INT16_C( 32465),  INT16_C(  8064), -INT16_C( 14752), -INT16_C(  9095),
      -INT16_C(  9827),  INT16_C( 30008), -INT16_C( 31665), -INT16_C( 24624),  INT16_C( 11508), -INT16_C( 24350),  INT16_C( 13411), -INT16_C( 26068),
      -INT16_C( 11388),  INT16_C( 15333),  INT16_C(   699), -INT16_C( 29498),  INT16_C( 18304), -INT16_C(  8021),  INT16_C(  9229), -INT16_C( 21828),
      -INT16_C(  2819),  INT16_C( 19488), -INT16_C(  3975),  INT16_C( 28140), -INT16_C( 12772),  INT16_C( 32525),  INT16_C( 14851), -INT16_C( 30951),
      -INT16_C(   243), -INT16_C( 14142), -INT16_C( 30719), -INT16_C( 32427),  INT16_C(   207), -INT16_C(  8863),  INT16_C(  7461),  INT16_C(  8839),
      -INT16_C( 22767), -INT16_C( 30097),  INT16_C( 23448), -INT16_C( 19209),  INT16_C(  1321),  INT16_C( 11316),  INT16_C( 19775),  INT16_C( 19635),
       INT16_C( 30028),  INT16_C( 19733),  INT16_C( 27390), -INT16_C( 12850),  INT16_C( 12138), -INT16_C( 28758),  INT16_C( 12876),  INT16_C( 24242),
       INT16_C(  8665),  INT16_C( 29160), -INT16_C(  8068), -INT16_C( 23258),  INT16_C( 23269),  INT16_C(  9426), -INT16_C( 31321), -INT16_C(  2960),
      -INT16_C( 31237), -INT16_C(  1727),  INT16_C(  4335),  INT16_C( 23238),  INT16_C( 28991), -INT16_C( 29463), -INT16_C( 25693),  INT16_C( 31978),
      -INT16_C( 11588),  INT16_C( 14574),  INT16_C(  5298), -INT16_C( 26658), -INT16_C( 20370),  INT16_C(  5563),  INT16_C( 11317),  INT16_C( 12297),
       INT16_C( 19377), -INT16_C( 24279), -INT16_C(  4005), -INT16_C( 25861), -INT16_C(  7071),  INT16_C(  1062),  INT16_C(  4224),  INT16_C( 15488),
       INT16_C( 28387), -INT16_C( 27275),  INT16_C( 21378), -INT16_C(  4051), -INT16_C(  6141),  INT16_C( 14342),  INT16_C(  3860), -INT16_C( 14743),
      -INT16_C( 28070), -INT16_C( 19097),  INT16_C( 25218), -INT16_C(  7344),  INT16_C( 30278), -INT16_C( 14617),  INT16_C( 26759),  INT16_C( 27139),
       INT16_C( 30934),  INT16_C( 23039),  INT16_C( 11467), -INT16_C( 12727),  INT16_C( 20245),  INT16_C( 10502),  INT16_C( 28511), -INT16_C( 17937),
       INT16_C( 22018), -INT16_C( 31633), -INT16_C( 16456), -INT16_C(   152),  INT16_C( 20277), -INT16_C( 17211), -INT16_C( 14153), -INT16_C( 29146),
       INT16_C(  9792),  INT16_C(  3047),  INT16_C( 12370),  INT16_C( 26585), -INT16_C(  8064), -INT16_C(  8303), -INT16_C( 32689),  INT16_C( 20888),
       INT16_C(  2007), -INT16_C( 28714),  INT16_C( 16070), -INT16_C(   882),  INT16_C( 21645),  INT16_C( 17848), -INT16_C(  8420),  INT16_C( 24019),
      -INT16_C( 17915),  INT16_C( 22376),  INT16_C( 17130),  INT16_C( 27327),  INT16_C( 20514),  INT16_C( 29001), -INT16_C(  7472), -INT16_C( 22589),
      -INT16_C( 26135), -INT16_C( 20425), -INT16_C( 14889),  INT16_C( 25772),  INT16_C( 25625),  INT16_C( 13993),  INT16_C( 31811),  INT16_C( 18579),
      -INT16_C(  1226),  INT16_C(  8608),  INT16_C( 24381),  INT16_C( 24459), -INT16_C( 10833),  INT16_C( 32721), -INT16_C( 27465), -INT16_C( 24537),
       INT16_C( 24109),  INT16_C(  1104), -INT16_C(   989),  INT16_C( 15720),  INT16_C(  4705), -INT16_C( 23437),  INT16_C(  1678), -INT16_C( 14867),
      -INT16_C( 29439),  INT16_C( 16358),  INT16_C( 29164), -INT16_C( 25698),  INT16_C( 28486), -INT16_C(   742),  INT16_C( 16643),  INT16_C( 12446),
      -INT16_C(  4449), -INT16_C( 15564), -INT16_C( 25109),  INT16_C( 19456),  INT16_C( 29615),  INT16_C( 15856), -INT16_C(  8839),  INT16_C( 31234),
      -INT16_C(  6038),  INT16_C( 22201),  INT16_C( 22618), -INT16_C( 24335),  INT16_C(  3271), -INT16_C( 13410),  INT16_C( 15437), -INT16_C(  4613),
       INT16_C( 12330),  INT16_C(  5552), -INT16_C( 20275),  INT16_C( 31841),  INT16_C( 21027), -INT16_C( 25415), -INT16_C( 17361), -INT16_C( 26090),
      -INT16_C( 12124), -INT16_C(   272), -INT16_C(  7640), -INT16_C(  4193),  INT16_C( 15854),  INT16_C( 15290), -INT16_C( 18823), -INT16_C( 23768),
      -INT16_C( 10010), -INT16_C( 19527),  INT16_C(  6792), -INT16_C( 21713), -INT16_C(  6036), -INT16_C( 25529),  INT16_C( 24228),  INT16_C( 18742),
       INT16_C(  9774),  INT16_C( 22087), -INT16_C(  6648), -INT16_C(  2491),  INT16_C(    35), -INT16_C( 25550),  INT16_C( 23222), -INT16_C( 25536),
      -INT16_C(  1741), -INT16_C( 17585),  INT16_C( 32275), -INT16_C( 32665) };
  static const int16_t b[] =
    { -INT16_C( 16239),  INT16_C(  8259),  INT16_C( 27697),  INT16_C( 23472), -INT16_C( 12489), -INT16_C( 32472), -INT16_C( 20268),  INT16_C( 21463),
       INT16_C( 16968),  INT16_C( 24588), -INT16_C( 31288), -INT16_C( 16432),  INT16_C(  2046),  INT16_C(  6258),  INT16_C( 15277),  INT16_C( 16105),
       INT16_C( 11516),  INT16_C( 11614),  INT16_C(  3737), -INT16_C( 12152), -INT16_C( 20259), -INT16_C( 19886),  INT16_C( 10592), -INT16_C( 22523),
       INT16_C(  4715),  INT16_C( 13064), -INT16_C(  9833), -INT16_C( 27150),  INT16_C( 25824), -INT16_C( 29266), -INT16_C( 26721), -INT16_C( 25653),
       INT16_C( 10692),  INT16_C( 24008),  INT16_C( 20535),  INT16_C(  5421),  INT16_C( 32512),  INT16_C( 24775), -INT16_C( 13144),  INT16_C(  4872),
       INT16_C(  4574),  INT16_C( 30278),  INT16_C( 14570), -INT16_C( 13813), -INT16_C( 18020),  INT16_C( 15447),  INT16_C(  8785),  INT16_C(  5591),
      -INT16_C( 24501), -INT16_C( 32142), -INT16_C( 24592), -INT16_C(  3689),  INT16_C( 24095), -INT16_C( 14511),  INT16_C( 23083),  INT16_C(  2523),
       INT16_C(  8555),  INT16_C( 21887), -INT16_C( 29862), -INT16_C(  2529),  INT16_C( 30276), -INT16_C( 27342),  INT16_C(  2712), -INT16_C(  7254),
       INT16_C(  7338), -INT16_C( 26011), -INT16_C(   580), -INT16_C(  9333), -INT16_C(  8869), -INT16_C( 31070),  INT16_C( 32055), -INT16_C( 23920),
       INT16_C(  3999), -INT16_C(  1545),  INT16_C(  5786), -INT16_C(  8209),  INT16_C(  8844),  INT16_C(  9332),  INT16_C(  7980), -INT16_C( 10745),
       INT16_C( 27707), -INT16_C(  2192), -INT16_C(   919), -INT16_C( 14894),  INT16_C( 30169),  INT16_C(  4171), -INT16_C(  9230), -INT16_C( 28238),
      -INT16_C( 22037), -INT16_C( 31350),  INT16_C( 31423),  INT16_C( 19300), -INT16_C(  9828), -INT16_C( 14225),  INT16_C( 30456),  INT16_C( 13214),
       INT16_C(  3810),  INT16_C( 19499), -INT16_C(   758), -INT16_C(  7407),  INT16_C( 23666),  INT16_C( 26099), -INT16_C( 23240),  INT16_C(  9206),
      -INT16_C( 32434),  INT16_C(  3496),  INT16_C(  3579), -INT16_C( 26792), -INT16_C( 14362), -INT16_C(  8609), -INT16_C(   707),  INT16_C(  8209),
       INT16_C( 15371),  INT16_C(  5740),  INT16_C( 32058), -INT16_C( 21255), -INT16_C(  4647),  INT16_C(  4369),  INT16_C(  2194), -INT16_C(  7884),
      -INT16_C(  8823), -INT16_C( 31506),  INT16_C( 18410), -INT16_C( 12261),  INT16_C( 31246),  INT16_C( 19630), -INT16_C( 16521), -INT16_C( 32148),
      -INT16_C(  9988),  INT16_C( 13976), -INT16_C( 28075),  INT16_C( 12002), -INT16_C(  2945),  INT16_C(  4416),  INT16_C( 29948), -INT16_C( 31246),
      -INT16_C(  7855),  INT16_C( 15113),  INT16_C(  9256),  INT16_C( 13835), -INT16_C( 18018),  INT16_C(  5506), -INT16_C(  4487),  INT16_C( 30103),
       INT16_C( 12486),  INT16_C(  7083), -INT16_C( 29246),  INT16_C( 16714), -INT16_C( 30079),  INT16_C( 32082),  INT16_C( 17918),  INT16_C( 20482),
       INT16_C(  2854),  INT16_C( 20107), -INT16_C( 26833), -INT16_C( 12924),  INT16_C(  1872), -INT16_C( 13854),  INT16_C( 31477), -INT16_C( 17346),
      -INT16_C(  5718),  INT16_C( 27863),  INT16_C(  8567), -INT16_C(  1875), -INT16_C(    85), -INT16_C( 21898),  INT16_C( 30788),  INT16_C( 27386),
      -INT16_C( 31356), -INT16_C( 19528),  INT16_C( 15644),  INT16_C( 28033),  INT16_C( 25412),  INT16_C( 14646),  INT16_C( 30173), -INT16_C( 30731),
      -INT16_C( 12962), -INT16_C( 10765), -INT16_C( 24338), -INT16_C( 25906),  INT16_C( 17568), -INT16_C(  7100),  INT16_C( 16060),  INT16_C( 16463),
       INT16_C(  1987), -INT16_C(  7948),  INT16_C( 30020), -INT16_C( 30643), -INT16_C( 31784), -INT16_C( 18750), -INT16_C( 18440),  INT16_C( 22333),
       INT16_C( 12676),  INT16_C( 29484), -INT16_C(  1327),  INT16_C( 28941),  INT16_C( 20798), -INT16_C(  1194), -INT16_C( 23153),  INT16_C( 21051),
       INT16_C( 12204), -INT16_C(  3790),  INT16_C( 32676),  INT16_C( 32121),  INT16_C( 15107), -INT16_C(  1229),  INT16_C( 28915),  INT16_C( 30546),
       INT16_C( 32673),  INT16_C( 29674), -INT16_C(  2183), -INT16_C( 18204),  INT16_C( 14920), -INT16_C( 10317), -INT16_C(  4385), -INT16_C( 29654),
       INT16_C( 23582), -INT16_C( 15747), -INT16_C(  2340), -INT16_C(  8385),  INT16_C( 29234),  INT16_C(  9690),  INT16_C( 11747), -INT16_C( 31588),
      -INT16_C( 30804),  INT16_C(  9719), -INT16_C(  9090), -INT16_C( 14371), -INT16_C( 28650), -INT16_C(  2402), -INT16_C( 14209), -INT16_C( 25214),
      -INT16_C(   219),  INT16_C(   351), -INT16_C( 24587),  INT16_C( 10208), -INT16_C( 17903), -INT16_C(  2996), -INT16_C(  5657), -INT16_C( 27783),
       INT16_C( 28784), -INT16_C(  4423), -INT16_C( 27060),  INT16_C( 25525),  INT16_C( 21543), -INT16_C( 22951), -INT16_C(  9444),  INT16_C( 16707),
      -INT16_C( 23846), -INT16_C( 12478),  INT16_C(  8769),  INT16_C( 21495),  INT16_C( 17373), -INT16_C( 15289), -INT16_C( 16340), -INT16_C( 25512),
       INT16_C(  4401),  INT16_C( 32139),  INT16_C( 16551), -INT16_C( 12576),  INT16_C( 14740), -INT16_C( 20108), -INT16_C( 18668), -INT16_C(  4366),
       INT16_C( 13658), -INT16_C( 25666), -INT16_C( 19113),  INT16_C( 13550),  INT16_C( 14072),  INT16_C(  9721),  INT16_C( 20982),  INT16_C( 10177),
       INT16_C( 19554),  INT16_C(  2469), -INT16_C( 31347),  INT16_C(  8664),  INT16_C( 19647), -INT16_C( 11310), -INT16_C( 15100),  INT16_C( 24258),
      -INT16_C( 32518),  INT16_C( 20985), -INT16_C(  6091),  INT16_C( 11654),  INT16_C( 32542),  INT16_C(  5202),  INT16_C(  5328),  INT16_C( 12860),
      -INT16_C(  7840), -INT16_C(  4805),  INT16_C(  4966),  INT16_C(  9487), -INT16_C(  7840),  INT16_C( 25849), -INT16_C( 17498), -INT16_C( 24382),
      -INT16_C( 17605),  INT16_C( 28914),  INT16_C( 30883), -INT16_C( 15971) };
  static const int16_t e[] =
    { -INT16_C( 16239), -INT16_C( 17972),  INT16_C( 27697),  INT16_C(   865), -INT16_C( 14813), -INT16_C( 32472),  INT16_C( 23710), -INT16_C( 24594),
       INT16_C( 24512),  INT16_C( 24588), -INT16_C( 12820), -INT16_C( 23024),  INT16_C( 20905), -INT16_C( 30792),  INT16_C( 11418),  INT16_C( 16105),
       INT16_C( 32028),  INT16_C( 10735),  INT16_C(  3737),  INT16_C( 12845), -INT16_C( 14314), -INT16_C( 19886), -INT16_C(   731), -INT16_C( 22523),
       INT16_C(  1117),  INT16_C( 18825), -INT16_C( 26158), -INT16_C( 27150), -INT16_C( 22294), -INT16_C( 29266), -INT16_C( 19500), -INT16_C( 25653),
      -INT16_C( 22224),  INT16_C( 16153),  INT16_C( 20535),  INT16_C(  4209), -INT16_C( 32753),  INT16_C( 13508),  INT16_C(  6270), -INT16_C(  9447),
       INT16_C(  4574),  INT16_C( 30278),  INT16_C( 14570),  INT16_C(  9578), -INT16_C( 18020),  INT16_C( 15447),  INT16_C( 25376),  INT16_C(  5591),
      -INT16_C( 26100), -INT16_C( 32142),  INT16_C(   736), -INT16_C(  3689), -INT16_C(  9598), -INT16_C( 14511),  INT16_C( 23083),  INT16_C(  4059),
       INT16_C(  8555),  INT16_C(  7165),  INT16_C( 26388), -INT16_C(  2529), -INT16_C(  5420), -INT16_C( 27342),  INT16_C(  2712),  INT16_C( 23110),
       INT16_C(  7338),  INT16_C( 23648), -INT16_C(   580), -INT16_C(  9333), -INT16_C(  8869),  INT16_C( 17243),  INT16_C( 32055), -INT16_C( 29614),
       INT16_C(  3999),  INT16_C( 19367),  INT16_C(  5786), -INT16_C(  8209),  INT16_C(  8844),  INT16_C(  8064),  INT16_C(  7980), -INT16_C(  9095),
      -INT16_C(  9827), -INT16_C(  2192), -INT16_C(   919), -INT16_C( 24624),  INT16_C( 30169), -INT16_C( 24350), -INT16_C(  9230), -INT16_C( 28238),
      -INT16_C( 22037),  INT16_C( 15333),  INT16_C(   699),  INT16_C( 19300),  INT16_C( 18304), -INT16_C(  8021),  INT16_C(  9229),  INT16_C( 13214),
      -INT16_C(  2819),  INT16_C( 19499), -INT16_C(  3975),  INT16_C( 28140), -INT16_C( 12772),  INT16_C( 32525),  INT16_C( 14851),  INT16_C(  9206),
      -INT16_C( 32434), -INT16_C( 14142),  INT16_C(  3579), -INT16_C( 32427), -INT16_C( 14362), -INT16_C(  8609), -INT16_C(   707),  INT16_C(  8209),
      -INT16_C( 22767),  INT16_C(  5740),  INT16_C( 32058), -INT16_C( 19209),  INT16_C(  1321),  INT16_C(  4369),  INT16_C( 19775),  INT16_C( 19635),
      -INT16_C(  8823),  INT16_C( 19733),  INT16_C( 27390), -INT16_C( 12850),  INT16_C( 31246), -INT16_C( 28758),  INT16_C( 12876),  INT16_C( 24242),
      -INT16_C(  9988),  INT16_C( 29160), -INT16_C( 28075),  INT16_C( 12002), -INT16_C(  2945),  INT16_C(  4416), -INT16_C( 31321), -INT16_C( 31246),
      -INT16_C( 31237), -INT16_C(  1727),  INT16_C(  4335),  INT16_C( 23238), -INT16_C( 18018),  INT16_C(  5506), -INT16_C( 25693),  INT16_C( 31978),
       INT16_C( 12486),  INT16_C(  7083), -INT16_C( 29246),  INT16_C( 16714), -INT16_C( 20370),  INT16_C( 32082),  INT16_C( 17918),  INT16_C( 12297),
       INT16_C( 19377),  INT16_C( 20107), -INT16_C(  4005), -INT16_C( 25861), -INT16_C(  7071), -INT16_C( 13854),  INT16_C(  4224), -INT16_C( 17346),
       INT16_C( 28387),  INT16_C( 27863),  INT16_C( 21378), -INT16_C(  1875), -INT16_C(    85), -INT16_C( 21898),  INT16_C( 30788), -INT16_C( 14743),
      -INT16_C( 28070), -INT16_C( 19097),  INT16_C( 15644), -INT16_C(  7344),  INT16_C( 25412),  INT16_C( 14646),  INT16_C( 26759),  INT16_C( 27139),
      -INT16_C( 12962),  INT16_C( 23039), -INT16_C( 24338), -INT16_C( 12727),  INT16_C( 17568),  INT16_C( 10502),  INT16_C( 16060), -INT16_C( 17937),
       INT16_C( 22018), -INT16_C( 31633),  INT16_C( 30020), -INT16_C(   152), -INT16_C( 31784), -INT16_C( 18750), -INT16_C( 18440), -INT16_C( 29146),
       INT16_C( 12676),  INT16_C(  3047), -INT16_C(  1327),  INT16_C( 28941),  INT16_C( 20798), -INT16_C(  1194), -INT16_C( 32689),  INT16_C( 20888),
       INT16_C(  2007), -INT16_C( 28714),  INT16_C( 16070), -INT16_C(   882),  INT16_C( 21645),  INT16_C( 17848),  INT16_C( 28915),  INT16_C( 30546),
      -INT16_C( 17915),  INT16_C( 22376),  INT16_C( 17130),  INT16_C( 27327),  INT16_C( 20514), -INT16_C( 10317), -INT16_C(  4385), -INT16_C( 22589),
      -INT16_C( 26135), -INT16_C( 15747), -INT16_C( 14889),  INT16_C( 25772),  INT16_C( 29234),  INT16_C(  9690),  INT16_C( 31811), -INT16_C( 31588),
      -INT16_C(  1226),  INT16_C(  9719),  INT16_C( 24381), -INT16_C( 14371), -INT16_C( 28650),  INT16_C( 32721), -INT16_C( 27465), -INT16_C( 24537),
      -INT16_C(   219),  INT16_C(  1104), -INT16_C( 24587),  INT16_C( 15720),  INT16_C(  4705), -INT16_C( 23437), -INT16_C(  5657), -INT16_C( 14867),
       INT16_C( 28784), -INT16_C(  4423),  INT16_C( 29164), -INT16_C( 25698),  INT16_C( 28486), -INT16_C(   742), -INT16_C(  9444),  INT16_C( 12446),
      -INT16_C(  4449), -INT16_C( 12478),  INT16_C(  8769),  INT16_C( 21495),  INT16_C( 17373),  INT16_C( 15856), -INT16_C(  8839),  INT16_C( 31234),
      -INT16_C(  6038),  INT16_C( 32139),  INT16_C( 16551), -INT16_C( 24335),  INT16_C(  3271), -INT16_C( 13410), -INT16_C( 18668), -INT16_C(  4366),
       INT16_C( 12330),  INT16_C(  5552), -INT16_C( 20275),  INT16_C( 31841),  INT16_C( 14072), -INT16_C( 25415), -INT16_C( 17361),  INT16_C( 10177),
      -INT16_C( 12124),  INT16_C(  2469), -INT16_C( 31347), -INT16_C(  4193),  INT16_C( 15854), -INT16_C( 11310), -INT16_C( 18823), -INT16_C( 23768),
      -INT16_C( 32518), -INT16_C( 19527),  INT16_C(  6792),  INT16_C( 11654),  INT16_C( 32542), -INT16_C( 25529),  INT16_C( 24228),  INT16_C( 18742),
      -INT16_C(  7840),  INT16_C( 22087), -INT16_C(  6648), -INT16_C(  2491), -INT16_C(  7840),  INT16_C( 25849), -INT16_C( 17498), -INT16_C( 24382),
      -INT16_C( 17605), -INT16_C( 17585),  INT16_C( 30883), -INT16_C( 15971) };

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
    rv = simde_svsel_s16(pv, av, bv);

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

    ev = simde_svsel_s16(pv, av, bv);

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
test_simde_x_svsel_s32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) };
  static const int32_t a[] =
    {  INT32_C(  2139017585),  INT32_C(   143566312), -INT32_C(   461315474), -INT32_C(  1288487944),  INT32_C(    69104401), -INT32_C(  1683554227),  INT32_C(  1720799101),  INT32_C(   338658978),
       INT32_C(  1083419991), -INT32_C(  1052237486), -INT32_C(    73021181),  INT32_C(   363780100), -INT32_C(  1726362292),  INT32_C(  1245036749), -INT32_C(  1313815025), -INT32_C(  1530535859),
      -INT32_C(   521906035),  INT32_C(  2090937721), -INT32_C(    92780810),  INT32_C(  1796154911), -INT32_C(  1073469197), -INT32_C(   150259224),  INT32_C(  1302903552),  INT32_C(   703688347),
       INT32_C(  1074386630), -INT32_C(   105076221),  INT32_C(   267597040),  INT32_C(  1316618843),  INT32_C(   303005482), -INT32_C(  1207362888),  INT32_C(  1896198613), -INT32_C(   426051809),
      -INT32_C(   802774067),  INT32_C(  1036640845),  INT32_C(  1917697047), -INT32_C(   390019138), -INT32_C(      340154), -INT32_C(  1078524951), -INT32_C(   735003212), -INT32_C(  2118464844),
      -INT32_C(  1169039251), -INT32_C(   638117182), -INT32_C(  1807006506),  INT32_C(  1383861260), -INT32_C(   984516901),  INT32_C(   763627897),  INT32_C(  2046932166), -INT32_C(   335824002),
       INT32_C(  1587891355),  INT32_C(  1010277478), -INT32_C(   305101855),  INT32_C(  1782533263),  INT32_C(   992973250),  INT32_C(  1617474458), -INT32_C(   438670745), -INT32_C(  1043278555),
      -INT32_C(  2027981535), -INT32_C(   205302254),  INT32_C(  1759548377), -INT32_C(  1579999265),  INT32_C(  1255932592),  INT32_C(   497697974), -INT32_C(   737966930),  INT32_C(  2056639321),
       INT32_C(  1526838345), -INT32_C(   464600054),  INT32_C(   910962263), -INT32_C(    19456179), -INT32_C(   666324190), -INT32_C(  1493830664), -INT32_C(   780470153),  INT32_C(   357240780),
      -INT32_C(   831500861),  INT32_C(  1773321745),  INT32_C(   966786796),  INT32_C(  1077376798),  INT32_C(   572031018), -INT32_C(   355922573), -INT32_C(   759479546),  INT32_C(   384239443),
       INT32_C(  1709463380),  INT32_C(    30316053), -INT32_C(  1288016235),  INT32_C(   267612901),  INT32_C(  1697778674),  INT32_C(   508558104), -INT32_C(  1846539458),  INT32_C(  1722341138),
       INT32_C(  1137413166), -INT32_C(  1203463645), -INT32_C(   311722232), -INT32_C(   469999887), -INT32_C(  2125975959),  INT32_C(  1755354921), -INT32_C(  1258712926), -INT32_C(  1776639640),
       INT32_C(  1373300270), -INT32_C(  2012668288), -INT32_C(  1904905059),  INT32_C(   997290450), -INT32_C(   910378592), -INT32_C(   214868911),  INT32_C(  1437084653), -INT32_C(    85212468),
       INT32_C(   676054440), -INT32_C(  2119150364), -INT32_C(  1710217784),  INT32_C(   936739223), -INT32_C(  1946119621), -INT32_C(   612420882),  INT32_C(   691021661), -INT32_C(  1843127062),
      -INT32_C(   977571871), -INT32_C(  1941476412),  INT32_C(   673666961),  INT32_C(   325057752),  INT32_C(  2107596686), -INT32_C(   296214639),  INT32_C(   806914374), -INT32_C(  2034025307),
       INT32_C(  1867284139),  INT32_C(  2063373289), -INT32_C(  1029561366), -INT32_C(  1361706721), -INT32_C(   232032927), -INT32_C(   605977708), -INT32_C(  1324615412), -INT32_C(   533148107),
       INT32_C(   911246412),  INT32_C(    28331031), -INT32_C(  1899801745), -INT32_C(  1254319788), -INT32_C(  1549244657), -INT32_C(   142702101), -INT32_C(  1213625726), -INT32_C(  1516773032),
       INT32_C(  2094786405), -INT32_C(  1568830669),  INT32_C(   858865886), -INT32_C(   370643494), -INT32_C(  1064529707), -INT32_C(  1682502887), -INT32_C(   313368427), -INT32_C(  1500321215),
       INT32_C(    86142417), -INT32_C(   676880391), -INT32_C(  1173694240),  INT32_C(   463729478), -INT32_C(  1646579837), -INT32_C(   818376134),  INT32_C(   884837363),  INT32_C(  1188777845),
      -INT32_C(  1236533827),  INT32_C(  2106454941),  INT32_C(   288856267),  INT32_C(   237820555),  INT32_C(  1152059145), -INT32_C(  1928076134), -INT32_C(   457060241), -INT32_C(   584410080),
       INT32_C(   932411034),  INT32_C(   884220009),  INT32_C(  1128721336), -INT32_C(   833457467),  INT32_C(   336788858),  INT32_C(  1352738529),  INT32_C(   372531958), -INT32_C(  1712103425),
       INT32_C(  1053853397),  INT32_C(  1601340583),  INT32_C(   883144815), -INT32_C(  1526532821), -INT32_C(   726067726),  INT32_C(   824465979), -INT32_C(  1152886340), -INT32_C(  1923859528),
       INT32_C(  1774920898),  INT32_C(   398998952),  INT32_C(   558590966),  INT32_C(  1405505120), -INT32_C(  1641578653), -INT32_C(  1781576743),  INT32_C(  1548818340),  INT32_C(   367633747),
       INT32_C(  1920906442), -INT32_C(   393591054),  INT32_C(   302634418), -INT32_C(  2040148189),  INT32_C(   656706638),  INT32_C(  2092758232),  INT32_C(  1591282955),  INT32_C(  2104738483),
       INT32_C(  1777332599), -INT32_C(   363759304),  INT32_C(  1929140815),  INT32_C(  2012832297), -INT32_C(   962716178),  INT32_C(   490953233) };
  static const int32_t e[] =
    {  INT32_C(           0),  INT32_C(           0), -INT32_C(   461315474),  INT32_C(           0),  INT32_C(    69104401), -INT32_C(  1683554227),  INT32_C(           0),  INT32_C(           0),
       INT32_C(  1083419991), -INT32_C(  1052237486), -INT32_C(    73021181),  INT32_C(           0), -INT32_C(  1726362292),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(  2090937721),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1073469197), -INT32_C(   150259224),  INT32_C(  1302903552),  INT32_C(           0),
       INT32_C(  1074386630), -INT32_C(   105076221),  INT32_C(   267597040),  INT32_C(  1316618843),  INT32_C(           0), -INT32_C(  1207362888),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(   802774067),  INT32_C(           0),  INT32_C(  1917697047), -INT32_C(   390019138),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(  1169039251),  INT32_C(           0), -INT32_C(  1807006506),  INT32_C(           0), -INT32_C(   984516901),  INT32_C(           0),  INT32_C(  2046932166),  INT32_C(           0),
       INT32_C(           0),  INT32_C(  1010277478), -INT32_C(   305101855),  INT32_C(  1782533263),  INT32_C(   992973250),  INT32_C(  1617474458),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(  2027981535),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   497697974), -INT32_C(   737966930),  INT32_C(           0),
       INT32_C(  1526838345), -INT32_C(   464600054),  INT32_C(   910962263), -INT32_C(    19456179), -INT32_C(   666324190),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1077376798),  INT32_C(   572031018),  INT32_C(           0), -INT32_C(   759479546),  INT32_C(           0),
       INT32_C(  1709463380),  INT32_C(    30316053), -INT32_C(  1288016235),  INT32_C(           0),  INT32_C(           0),  INT32_C(   508558104),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1755354921), -INT32_C(  1258712926),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(  1904905059),  INT32_C(   997290450),  INT32_C(           0), -INT32_C(   214868911),  INT32_C(           0),  INT32_C(           0),
       INT32_C(   676054440),  INT32_C(           0),  INT32_C(           0),  INT32_C(   936739223),  INT32_C(           0), -INT32_C(   612420882),  INT32_C(   691021661), -INT32_C(  1843127062),
       INT32_C(           0), -INT32_C(  1941476412),  INT32_C(           0),  INT32_C(   325057752),  INT32_C(           0),  INT32_C(           0),  INT32_C(   806914374),  INT32_C(           0),
       INT32_C(  1867284139),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1361706721),  INT32_C(           0), -INT32_C(   605977708),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(    28331031), -INT32_C(  1899801745), -INT32_C(  1254319788), -INT32_C(  1549244657), -INT32_C(   142702101),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(   858865886), -INT32_C(   370643494), -INT32_C(  1064529707), -INT32_C(  1682502887), -INT32_C(   313368427), -INT32_C(  1500321215),
       INT32_C(           0),  INT32_C(           0), -INT32_C(  1173694240),  INT32_C(           0), -INT32_C(  1646579837), -INT32_C(   818376134),  INT32_C(           0),  INT32_C(  1188777845),
      -INT32_C(  1236533827),  INT32_C(  2106454941),  INT32_C(   288856267),  INT32_C(   237820555),  INT32_C(  1152059145),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(   932411034),  INT32_C(   884220009),  INT32_C(  1128721336),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   372531958), -INT32_C(  1712103425),
       INT32_C(  1053853397),  INT32_C(           0),  INT32_C(   883144815),  INT32_C(           0),  INT32_C(           0),  INT32_C(   824465979),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(   558590966),  INT32_C(  1405505120),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(  1920906442), -INT32_C(   393591054),  INT32_C(   302634418), -INT32_C(  2040148189),  INT32_C(   656706638),  INT32_C(  2092758232),  INT32_C(  1591282955),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(  1929140815),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) };

  static int32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t
      rv,
      av = simde_svld1_s32(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_x_svsel_s32_z(pv, av);

    simde_svst1_s32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vi32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)], a[1024 / sizeof(int32_t)], e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_s32(pg, &(a[i]));

    ev = simde_x_svsel_s32_z(pv, av);

    simde_svst1_s32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsel_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) };
  static const int32_t a[] =
    { -INT32_C(  1284658627), -INT32_C(  1420328799), -INT32_C(   902743243), -INT32_C(    93127177),  INT32_C(  1424607996),  INT32_C(   160206046), -INT32_C(  1916011770),  INT32_C(  1289539087),
       INT32_C(   452938104), -INT32_C(    20621367), -INT32_C(  1983318126), -INT32_C(   259769356), -INT32_C(   465277691),  INT32_C(    15585786), -INT32_C(   611469108), -INT32_C(    14128762),
       INT32_C(  2065246130),  INT32_C(   276487806), -INT32_C(   895860011), -INT32_C(  2084954499), -INT32_C(  2056781941), -INT32_C(  1668918064), -INT32_C(  1820847347),  INT32_C(   798138493),
       INT32_C(  1185655751),  INT32_C(  1599481226), -INT32_C(   450236313), -INT32_C(  1704401906), -INT32_C(  1289760797),  INT32_C(   810525987),  INT32_C(   918865849),  INT32_C(   795170407),
      -INT32_C(  1938485246), -INT32_C(  1645491403), -INT32_C(   897444420), -INT32_C(   597366023), -INT32_C(   594574151), -INT32_C(   502407639),  INT32_C(   219730342),  INT32_C(   691830311),
      -INT32_C(   994725490),  INT32_C(   962699645), -INT32_C(  1358699594), -INT32_C(  2037684019),  INT32_C(   358750956), -INT32_C(  1627885576),  INT32_C(  1756106816),  INT32_C(   496101518),
       INT32_C(   400639898), -INT32_C(  1638907160), -INT32_C(   229813467), -INT32_C(  1485252421), -INT32_C(   356656398), -INT32_C(  1970686646),  INT32_C(  1425159621), -INT32_C(  1217297379),
      -INT32_C(  1278324021), -INT32_C(  1185866092),  INT32_C(   766221938),  INT32_C(  1758798710),  INT32_C(  1196593917),  INT32_C(   215145287),  INT32_C(   778093584),  INT32_C(   333828424),
      -INT32_C(  1211714525),  INT32_C(  1148196818),  INT32_C(   728898485),  INT32_C(  1016284990),  INT32_C(   545515225), -INT32_C(   768846399),  INT32_C(  1644203290), -INT32_C(  2106137250),
       INT32_C(  1815690393),  INT32_C(   162572884),  INT32_C(    70591173),  INT32_C(  1111541865),  INT32_C(  1885520814),  INT32_C(   860000025),  INT32_C(  2056602140), -INT32_C(  1040446681),
      -INT32_C(  1674758584), -INT32_C(  1515856416),  INT32_C(  1772739072),  INT32_C(  1370286499), -INT32_C(   960426323), -INT32_C(  1174862947),  INT32_C(  1832160837), -INT32_C(   500289382),
       INT32_C(  1182686054),  INT32_C(   954999608), -INT32_C(  1583180290),  INT32_C(   754077311), -INT32_C(    84757412), -INT32_C(    38540361),  INT32_C(   325773177),  INT32_C(  2130024472),
       INT32_C(   734360563), -INT32_C(  1788563049), -INT32_C(   986315194), -INT32_C(  1326372780), -INT32_C(  1800739876),  INT32_C(  1217486542),  INT32_C(  1566309189), -INT32_C(  2032381549),
       INT32_C(  1538367940), -INT32_C(  1729096366),  INT32_C(  1868441115),  INT32_C(   723537743),  INT32_C(    29346355),  INT32_C(  1850298408), -INT32_C(   557079221), -INT32_C(  1167808522),
      -INT32_C(  1709828536),  INT32_C(  1194526251),  INT32_C(  2092339501),  INT32_C(   329766624), -INT32_C(   921344095),  INT32_C(    53960375), -INT32_C(   102694141), -INT32_C(   206289238),
      -INT32_C(  2020750756), -INT32_C(    36781872),  INT32_C(   846824785), -INT32_C(    62578341),  INT32_C(  1069963912), -INT32_C(  1136460359), -INT32_C(  1414126592), -INT32_C(   962696598),
       INT32_C(    72166196),  INT32_C(  1023548652), -INT32_C(    59802719),  INT32_C(   620344732), -INT32_C(   932921585), -INT32_C(  1115314500),  INT32_C(   879246282), -INT32_C(   637925723),
       INT32_C(   501041201),  INT32_C(    89907044), -INT32_C(   150877605), -INT32_C(  1893926273),  INT32_C(  1985446073), -INT32_C(   248259546), -INT32_C(  1138386153), -INT32_C(   761978719) };
  static const int32_t b[] =
    { -INT32_C(  1745896352),  INT32_C(    42872712),  INT32_C(  1249442644), -INT32_C(  2017388834), -INT32_C(   788935643), -INT32_C(  1411703447), -INT32_C(   863100604),  INT32_C(  1213345000),
       INT32_C(  1910522344), -INT32_C(   999068048),  INT32_C(  1192225641),  INT32_C(   651153409),  INT32_C(   100059292),  INT32_C(   716296678), -INT32_C(   621330446),  INT32_C(  1411598699),
      -INT32_C(    87751798), -INT32_C(   625002383),  INT32_C(   606195235),  INT32_C(   977989790), -INT32_C(  1623179079),  INT32_C(    80343313), -INT32_C(  1663123408), -INT32_C(  1812987639),
       INT32_C(  1972286724),  INT32_C(   273632749), -INT32_C(  1187745509),  INT32_C(   452165217), -INT32_C(   809946178),  INT32_C(  1439925028),  INT32_C(  1307685443), -INT32_C(  1193221709),
      -INT32_C(  2094174570), -INT32_C(   694977093),  INT32_C(  1334822894),  INT32_C(    57312069), -INT32_C(   606985290), -INT32_C(   365910362),  INT32_C(   188162392), -INT32_C(  1732045054),
       INT32_C(  1092350342),  INT32_C(  1545121390), -INT32_C(  1163155595), -INT32_C(   507701974), -INT32_C(   541290695), -INT32_C(  1916146635),  INT32_C(   261685261), -INT32_C(  1633199080),
      -INT32_C(  1142963635), -INT32_C(   451414160), -INT32_C(   912276577),  INT32_C(   296377560),  INT32_C(   569468651),  INT32_C(  1605286482), -INT32_C(   747747397), -INT32_C(   244247132),
       INT32_C(  1202540759), -INT32_C(   416496568),  INT32_C(  1622199175),  INT32_C(   326196007),  INT32_C(   338977473), -INT32_C(   663494115), -INT32_C(   827596246), -INT32_C(   809558793),
      -INT32_C(  1273598868), -INT32_C(  1197784271),  INT32_C(   907561998),  INT32_C(  1749650087),  INT32_C(   159153644), -INT32_C(  1981681569), -INT32_C(   917009198),  INT32_C(   362289064),
      -INT32_C(  1261850749),  INT32_C(     7169522),  INT32_C(  1479968177), -INT32_C(    54493425),  INT32_C(  1543847420), -INT32_C(     1710291),  INT32_C(   482884979), -INT32_C(   684629676),
       INT32_C(    42793488),  INT32_C(   268630367), -INT32_C(  1905772162), -INT32_C(  1249236552), -INT32_C(  1827565722), -INT32_C(   359467402), -INT32_C(  2029626829), -INT32_C(   882952261),
      -INT32_C(  1848775887),  INT32_C(  1654771940), -INT32_C(  1041233399), -INT32_C(  1720288717), -INT32_C(  2144565494), -INT32_C(  1318404482), -INT32_C(   734433256), -INT32_C(   643852121),
       INT32_C(  1735028099),  INT32_C(  1187580733),  INT32_C(  1208465941),  INT32_C(  1054965300), -INT32_C(  2084631291), -INT32_C(   466277941),  INT32_C(  1102605978), -INT32_C(  1994762490),
       INT32_C(    32539844), -INT32_C(  1522026096), -INT32_C(  1460777101), -INT32_C(   756625459), -INT32_C(  1470716451),  INT32_C(  1770818511), -INT32_C(     5618439),  INT32_C(  1619576220),
      -INT32_C(   647858103), -INT32_C(  1518360271), -INT32_C(   984781320),  INT32_C(   429404988), -INT32_C(  1463619879),  INT32_C(  1913736825),  INT32_C(   795982739), -INT32_C(   896534144),
      -INT32_C(  1566314127), -INT32_C(  1824054629), -INT32_C(   866544497), -INT32_C(  1578765880),  INT32_C(  1481222111), -INT32_C(  1983227146), -INT32_C(  1766311147), -INT32_C(  1520416972),
      -INT32_C(   733543623), -INT32_C(  1251504346), -INT32_C(   343818205), -INT32_C(  1869846607),  INT32_C(    82367758),  INT32_C(  1166914095),  INT32_C(   568018413), -INT32_C(   960087155),
       INT32_C(  1687817790), -INT32_C(  1072037475),  INT32_C(  1940691906),  INT32_C(   285489154),  INT32_C(  1024846862), -INT32_C(  1937595489),  INT32_C(  1974361576), -INT32_C(   683969384) };
  static const int32_t e[] =
    { -INT32_C(  1284658627),  INT32_C(    42872712),  INT32_C(  1249442644), -INT32_C(  2017388834),  INT32_C(  1424607996), -INT32_C(  1411703447), -INT32_C(  1916011770),  INT32_C(  1213345000),
       INT32_C(   452938104), -INT32_C(    20621367), -INT32_C(  1983318126), -INT32_C(   259769356), -INT32_C(   465277691),  INT32_C(   716296678), -INT32_C(   611469108),  INT32_C(  1411598699),
      -INT32_C(    87751798),  INT32_C(   276487806),  INT32_C(   606195235), -INT32_C(  2084954499), -INT32_C(  1623179079),  INT32_C(    80343313), -INT32_C(  1820847347), -INT32_C(  1812987639),
       INT32_C(  1185655751),  INT32_C(  1599481226), -INT32_C(  1187745509), -INT32_C(  1704401906), -INT32_C(   809946178),  INT32_C(  1439925028),  INT32_C(   918865849), -INT32_C(  1193221709),
      -INT32_C(  2094174570), -INT32_C(   694977093), -INT32_C(   897444420),  INT32_C(    57312069), -INT32_C(   594574151), -INT32_C(   502407639),  INT32_C(   188162392), -INT32_C(  1732045054),
      -INT32_C(   994725490),  INT32_C(  1545121390), -INT32_C(  1163155595), -INT32_C(   507701974),  INT32_C(   358750956), -INT32_C(  1627885576),  INT32_C(  1756106816),  INT32_C(   496101518),
      -INT32_C(  1142963635), -INT32_C(   451414160), -INT32_C(   912276577), -INT32_C(  1485252421),  INT32_C(   569468651),  INT32_C(  1605286482),  INT32_C(  1425159621), -INT32_C(  1217297379),
       INT32_C(  1202540759), -INT32_C(   416496568),  INT32_C(   766221938),  INT32_C(  1758798710),  INT32_C(   338977473),  INT32_C(   215145287), -INT32_C(   827596246),  INT32_C(   333828424),
      -INT32_C(  1273598868),  INT32_C(  1148196818),  INT32_C(   907561998),  INT32_C(  1016284990),  INT32_C(   545515225), -INT32_C(   768846399), -INT32_C(   917009198), -INT32_C(  2106137250),
       INT32_C(  1815690393),  INT32_C(     7169522),  INT32_C(    70591173), -INT32_C(    54493425),  INT32_C(  1543847420),  INT32_C(   860000025),  INT32_C(  2056602140), -INT32_C(  1040446681),
       INT32_C(    42793488), -INT32_C(  1515856416),  INT32_C(  1772739072), -INT32_C(  1249236552), -INT32_C(  1827565722), -INT32_C(   359467402), -INT32_C(  2029626829), -INT32_C(   500289382),
       INT32_C(  1182686054),  INT32_C(   954999608), -INT32_C(  1041233399), -INT32_C(  1720288717), -INT32_C(  2144565494), -INT32_C(    38540361), -INT32_C(   734433256), -INT32_C(   643852121),
       INT32_C(   734360563),  INT32_C(  1187580733),  INT32_C(  1208465941),  INT32_C(  1054965300), -INT32_C(  1800739876),  INT32_C(  1217486542),  INT32_C(  1102605978), -INT32_C(  1994762490),
       INT32_C(    32539844), -INT32_C(  1729096366),  INT32_C(  1868441115), -INT32_C(   756625459),  INT32_C(    29346355),  INT32_C(  1850298408), -INT32_C(   557079221),  INT32_C(  1619576220),
      -INT32_C(   647858103),  INT32_C(  1194526251), -INT32_C(   984781320),  INT32_C(   429404988), -INT32_C(   921344095),  INT32_C(    53960375),  INT32_C(   795982739), -INT32_C(   896534144),
      -INT32_C(  2020750756), -INT32_C(  1824054629),  INT32_C(   846824785), -INT32_C(    62578341),  INT32_C(  1069963912), -INT32_C(  1983227146), -INT32_C(  1766311147), -INT32_C(   962696598),
      -INT32_C(   733543623),  INT32_C(  1023548652), -INT32_C(    59802719), -INT32_C(  1869846607), -INT32_C(   932921585),  INT32_C(  1166914095),  INT32_C(   568018413), -INT32_C(   960087155),
       INT32_C(   501041201),  INT32_C(    89907044), -INT32_C(   150877605),  INT32_C(   285489154),  INT32_C(  1985446073), -INT32_C(   248259546),  INT32_C(  1974361576), -INT32_C(   761978719) };

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
    rv = simde_svsel_s32(pv, av, bv);

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

    ev = simde_svsel_s32(pv, av, bv);

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
test_simde_x_svsel_s64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1) };
  static const int64_t a[] =
    {  INT64_C(  648045876917458049),  INT64_C( 7717974134688129675),  INT64_C(  475328727797423530),  INT64_C( 8176279556997154821),
       INT64_C( 2855584098227079502), -INT64_C( 3948041558374064587), -INT64_C( 3019939733453399013),  INT64_C( 8857806597628965260),
       INT64_C( 5209736863280202121), -INT64_C( 4109173284915712494), -INT64_C(  645159981660281244), -INT64_C( 7006369475721964513),
      -INT64_C( 7080485947522689183),  INT64_C( 8966604287565025277),  INT64_C( 6021238160903718445), -INT64_C( 4376264762072366448),
       INT64_C( 1469286286383056698),  INT64_C( 2762727443276837316),  INT64_C( 6195631219418204275),  INT64_C( 3923830430385215823),
       INT64_C( 7237670119025650502), -INT64_C( 3481679038232186993),  INT64_C(  628660863086587039),  INT64_C( 4052727232231748364),
       INT64_C( 2944235508321303256),  INT64_C( 5936129909187419189),  INT64_C( 6380315667223468234),  INT64_C( 5282053246014211107),
       INT64_C( 2204968213752767193),  INT64_C( 8196569633100089786),  INT64_C(  688065469788485353),  INT64_C( 7313401094810299843),
      -INT64_C( 7398445663151308723), -INT64_C(  228902844508011591),  INT64_C(  733168948290373437),  INT64_C(  187951295951162026),
      -INT64_C( 7245012094075571460),  INT64_C( 9123957775896705678),  INT64_C( 4028132921610194838), -INT64_C( 2391963486685158121),
       INT64_C( 2231583713433027963),  INT64_C( 6513998110849562023), -INT64_C( 1445622680908331219), -INT64_C( 2161299668133781950),
      -INT64_C( 8126121111902504309), -INT64_C( 8842010444815664596), -INT64_C( 2259347279280438811),  INT64_C( 7914519867464834445),
       INT64_C( 8734383261327365567),  INT64_C( 8186053782151998909), -INT64_C( 7731607403238795211),  INT64_C( 8898372596283258413),
      -INT64_C( 8774884775419574669), -INT64_C( 8430116906557791739),  INT64_C( 3146347068354604302),  INT64_C(  359927955347681992),
       INT64_C( 9083757667562037439), -INT64_C( 1260425287811749216), -INT64_C( 5015129879146667970),  INT64_C( 1834438782367932896),
      -INT64_C( 2930805178634257828), -INT64_C( 5680920999096327589), -INT64_C( 4982014891424732112), -INT64_C( 5591324119818102028),
       INT64_C( 1506976038746786266),  INT64_C( 4062378838289528636), -INT64_C( 7766114919952790107), -INT64_C( 2352767946467351471),
      -INT64_C(  566931581144276653), -INT64_C( 8155727650792967790), -INT64_C( 5437737679946175403),  INT64_C(  760744088086211754),
      -INT64_C( 1492598745721241707),  INT64_C( 5558100515755520170),  INT64_C( 2349133491674951554),  INT64_C( 4538042558983435320),
      -INT64_C(  855164640969158180),  INT64_C( 9155724574317913801),  INT64_C( 6228757686492942809),  INT64_C( 8780400369676402675),
       INT64_C(  833396015073552977), -INT64_C( 7208894375771957129),  INT64_C( 5377679860551080237),  INT64_C( 8624887131282007706),
      -INT64_C( 6234773875950723029),  INT64_C( 5699324168246216378), -INT64_C(  573017774405057686), -INT64_C( 2323890718278356190),
       INT64_C( 3322747729033875777), -INT64_C( 5368920453099603701),  INT64_C( 8438765294414403526),  INT64_C( 8001344221426306167),
       INT64_C( 2878079561355122253),  INT64_C( 2610067287416609591), -INT64_C( 6147021845166510103),  INT64_C( 4057145039184555697),
       INT64_C( 7312131850887573302), -INT64_C( 8501072470753161596),  INT64_C( 7254587285004766927), -INT64_C( 7491297751062117658) };
  static const int64_t e[] =
    {  INT64_C(                   0),  INT64_C( 7717974134688129675),  INT64_C(  475328727797423530),  INT64_C(                   0),
       INT64_C( 2855584098227079502), -INT64_C( 3948041558374064587),  INT64_C(                   0),  INT64_C( 8857806597628965260),
       INT64_C( 5209736863280202121),  INT64_C(                   0), -INT64_C(  645159981660281244),  INT64_C(                   0),
      -INT64_C( 7080485947522689183),  INT64_C( 8966604287565025277),  INT64_C(                   0), -INT64_C( 4376264762072366448),
       INT64_C(                   0),  INT64_C( 2762727443276837316),  INT64_C( 6195631219418204275),  INT64_C( 3923830430385215823),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 4052727232231748364),
       INT64_C(                   0),  INT64_C( 5936129909187419189),  INT64_C( 6380315667223468234),  INT64_C(                   0),
       INT64_C( 2204968213752767193),  INT64_C( 8196569633100089786),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(  228902844508011591),  INT64_C(  733168948290373437),  INT64_C(                   0),
      -INT64_C( 7245012094075571460),  INT64_C( 9123957775896705678),  INT64_C( 4028132921610194838), -INT64_C( 2391963486685158121),
       INT64_C(                   0),  INT64_C( 6513998110849562023),  INT64_C(                   0), -INT64_C( 2161299668133781950),
      -INT64_C( 8126121111902504309), -INT64_C( 8842010444815664596), -INT64_C( 2259347279280438811),  INT64_C(                   0),
       INT64_C( 8734383261327365567),  INT64_C( 8186053782151998909), -INT64_C( 7731607403238795211),  INT64_C( 8898372596283258413),
      -INT64_C( 8774884775419574669),  INT64_C(                   0),  INT64_C( 3146347068354604302),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C( 1260425287811749216), -INT64_C( 5015129879146667970),  INT64_C( 1834438782367932896),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 5591324119818102028),
       INT64_C(                   0),  INT64_C( 4062378838289528636), -INT64_C( 7766114919952790107), -INT64_C( 2352767946467351471),
       INT64_C(                   0), -INT64_C( 8155727650792967790),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C( 1492598745721241707),  INT64_C( 5558100515755520170),  INT64_C( 2349133491674951554),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C( 9155724574317913801),  INT64_C(                   0),  INT64_C( 8780400369676402675),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C( 6234773875950723029),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C( 5368920453099603701),  INT64_C( 8438765294414403526),  INT64_C(                   0),
       INT64_C( 2878079561355122253),  INT64_C( 2610067287416609591),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C( 7312131850887573302), -INT64_C( 8501072470753161596),  INT64_C( 7254587285004766927), -INT64_C( 7491297751062117658) };

  static int64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t
      rv,
      av = simde_svld1_s64(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_x_svsel_s64_z(pv, av);

    simde_svst1_s64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vi64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)], a[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_s64(pg, &(a[i]));

    ev = simde_x_svsel_s64_z(pv, av);

    simde_svst1_s64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsel_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1) };
  static const int64_t a[] =
    { -INT64_C( 8632981581385828011),  INT64_C( 4757707696996997109), -INT64_C( 9099564684331159749), -INT64_C( 3826010787564854341),
       INT64_C( 6468784678014543936),  INT64_C( 7766677668128451476),  INT64_C( 2150950830562248759), -INT64_C( 4442598161519658215),
       INT64_C( 3845728427202045088),  INT64_C( 2291068770014863408), -INT64_C( 7383000126614681078), -INT64_C( 5417972102606660725),
      -INT64_C( 4379442142922551709), -INT64_C( 9133318228659669960), -INT64_C( 7939152324475373895), -INT64_C( 2550324397925795373),
      -INT64_C( 6516116651910343365),  INT64_C( 6774826323392443918),  INT64_C( 4418428616645800890), -INT64_C( 7514607423191715998),
      -INT64_C( 4672491547581311211), -INT64_C( 6146769244852589393),  INT64_C( 1505534551419144508), -INT64_C( 2477641941455599446),
      -INT64_C( 6004275778024438724),  INT64_C( 8362254563352309618), -INT64_C( 2611525720075438341), -INT64_C( 8021615359018553593),
       INT64_C(  444776176695446915), -INT64_C( 2754384524381508583), -INT64_C( 1731555028830330389), -INT64_C( 2532318931268936970),
      -INT64_C( 7274570681069840014), -INT64_C( 3140218499387001676),  INT64_C( 3340521076826435988), -INT64_C( 1515085825254550588),
      -INT64_C( 7940695115533691474),  INT64_C(   12541494961617263), -INT64_C( 3682309483960983937),  INT64_C( 7081033778380496866),
      -INT64_C( 7015097288258079689), -INT64_C( 3061565566705285097), -INT64_C( 6263256081035888832),  INT64_C( 1650086438307691984),
      -INT64_C( 1204202900148291204), -INT64_C( 6718536789332443241), -INT64_C( 8043710681303003411),  INT64_C( 2878921298075280125),
      -INT64_C( 8918502831555469964), -INT64_C( 7971313462583055013),  INT64_C( 5175659936130354051),  INT64_C( 6401611666305640453),
       INT64_C( 2424871487151581492), -INT64_C( 3476428940395014003), -INT64_C( 5756754077286266999), -INT64_C( 8427581432194383922),
       INT64_C( 2073716930357538784),  INT64_C( 7892011772503958890),  INT64_C( 5579781266586310933), -INT64_C( 1765961879408029796),
      -INT64_C( 1772917981218788678), -INT64_C( 3077324410095488263), -INT64_C( 8752177526034101058),  INT64_C( 5819204416526977747),
      -INT64_C( 7239818277040861663),  INT64_C(  524322226350662833), -INT64_C( 5566220586062652848),  INT64_C( 5854482913177647449),
      -INT64_C( 8585982022752610149),  INT64_C( 7416090574664061338),  INT64_C( 6389025673882644506),  INT64_C( 2169194071108040345),
       INT64_C( 1999374484848183903),  INT64_C( 1297576521149429893), -INT64_C( 7317587428203912934), -INT64_C( 6949760934262621717),
      -INT64_C( 6763399362957153912),  INT64_C( 2834802717170147917),  INT64_C(  178652046067589599), -INT64_C( 2068279934157988500),
       INT64_C(  191138779332551143),  INT64_C(  172999509906285617), -INT64_C( 4172482413246306560),  INT64_C( 8032660904240974139),
      -INT64_C( 6514708152725510945),  INT64_C( 9017694630684385279), -INT64_C( 6912554401994110736),  INT64_C( 2462817272435475510),
      -INT64_C( 4887444923966054124),  INT64_C( 5343524641545523245), -INT64_C( 6984619674779206645),  INT64_C(  832755776389728297),
      -INT64_C( 4493255886225849044), -INT64_C( 7893802417908841521), -INT64_C( 3001344940283066543),  INT64_C( 7809189253593871964),
      -INT64_C( 9121203549545041387), -INT64_C( 4930001875921873284),  INT64_C(  696033384089360421), -INT64_C( 3372707131267617916),
      -INT64_C(  224365791372736849), -INT64_C( 3467608254589203014), -INT64_C( 6277373408470543060), -INT64_C( 6142452512337346763),
      -INT64_C( 2764385401571689691),  INT64_C( 7130849909158093179),  INT64_C( 1513242324169889331),  INT64_C( 3603661507680169308),
       INT64_C( 8645919508467748355),  INT64_C(  843177913516620315),  INT64_C( 7574600526615277352), -INT64_C( 1292599150226889520),
       INT64_C( 8882239074489984721), -INT64_C( 7283869315960610553), -INT64_C( 9086925184394113682),  INT64_C( 4233222471691445733),
      -INT64_C( 2004580269058174893), -INT64_C( 1712865966083016147), -INT64_C( 8994735608959869445),  INT64_C( 5444591328011979500),
       INT64_C( 1126794783679747810),  INT64_C( 1119963732176234023),  INT64_C( 2443175539381038534) };
  static const int64_t b[] =
    {  INT64_C( 7558618454380371454), -INT64_C( 2239817606574535208), -INT64_C( 2137895420650243480),  INT64_C( 3970362019527388312),
      -INT64_C( 7402516176979024276), -INT64_C( 5537315056505079417), -INT64_C( 6913257389855056709), -INT64_C( 6086257283150663655),
       INT64_C( 2289740215512112747), -INT64_C( 7241068158949826940), -INT64_C( 6803858732627830037),  INT64_C( 8030054495544393606),
       INT64_C( 5030911942326023962), -INT64_C( 5603719527204112191),  INT64_C( 6924628408741987313), -INT64_C( 6743130501983957769),
       INT64_C( 3140177078206597005),  INT64_C( 3519289601611835486), -INT64_C( 6033483514288505846), -INT64_C( 8288571651790444082),
      -INT64_C( 3264987183590978022), -INT64_C( 8176619906142798825), -INT64_C( 4634847295266738356), -INT64_C( 8958767519362558688),
       INT64_C(  983113988898850654), -INT64_C( 5167904294696608715), -INT64_C( 8013479955550062055),  INT64_C( 5667600842546536636),
      -INT64_C( 7068745511001346077),  INT64_C( 5658101361264708193),  INT64_C( 7014395614567415383),  INT64_C( 5134716436778125315),
      -INT64_C( 8511513951230467108),  INT64_C( 3230731117348206417),  INT64_C( 6062211586942316059), -INT64_C( 5764172306577840555),
       INT64_C( 8836016465891304174), -INT64_C( 1292578362513820147), -INT64_C( 6437386248407612668),  INT64_C( 7780357021989139061),
      -INT64_C( 3375693370905989757),  INT64_C(  205128183160449047), -INT64_C( 3838192416979450170),  INT64_C(  133432876129787122),
      -INT64_C( 7814073571706250246), -INT64_C( 3819803429052792067),  INT64_C( 5186630905793434843),  INT64_C( 1457355496237698746),
      -INT64_C( 5045332595209738260), -INT64_C( 6309066106129319774), -INT64_C( 6151402586741648891), -INT64_C( 3093942256531253279),
      -INT64_C( 1911433608002936317), -INT64_C( 2006355972610839119), -INT64_C( 5410265903923330992), -INT64_C( 1516376175127049161),
       INT64_C( 2074228049685656225), -INT64_C( 6767569582277569200),  INT64_C( 7587101039910867651),  INT64_C( 6515158046623725976),
      -INT64_C( 8631703702564105041),  INT64_C( 6364091592209846876), -INT64_C( 7369797741206162402),  INT64_C( 7873844379521728817),
      -INT64_C( 1776742020282874984), -INT64_C(  541020356583485552), -INT64_C( 3119585366818395364), -INT64_C( 1554018596156355005),
       INT64_C( 4970304603862726279), -INT64_C( 7713568329483841504), -INT64_C( 9166683150251639983),  INT64_C( 1401165445448435765),
       INT64_C( 6620326892612758247), -INT64_C( 9098035201017755216),  INT64_C(  738942001171820164), -INT64_C( 7321161175019699257),
       INT64_C( 6756268795724467244), -INT64_C( 1796580685750331041), -INT64_C( 8245551304338274382),  INT64_C( 5835334864246678189),
      -INT64_C( 6423122322009869869),  INT64_C( 6403915977598591637),  INT64_C( 2171140128500582350),  INT64_C( 1875320743269433746),
      -INT64_C( 3415850317515145301), -INT64_C( 2028969396327100711), -INT64_C( 5134217758510696913),  INT64_C( 7204480366314143385),
      -INT64_C( 1927561477844789965), -INT64_C( 2398945600186611780),  INT64_C( 6831747076456328433), -INT64_C( 1903268160262423173),
      -INT64_C( 7655676427151086640),  INT64_C( 5847672741526119834),  INT64_C( 6803593110395331912), -INT64_C( 5329120765108114572),
      -INT64_C( 8394053357415473644),  INT64_C( 5489038044127619194),  INT64_C( 4675515745820054688), -INT64_C( 5761104907052092305),
       INT64_C( 7875704980150001616), -INT64_C( 4947076531147497464), -INT64_C( 1939607274557296376), -INT64_C( 4764167471257453675),
      -INT64_C( 6393199833108283419),  INT64_C(  846688833259146986), -INT64_C( 5397858684244066372),  INT64_C( 9014739256088154480),
       INT64_C( 5516518542177376328),  INT64_C(  592242369874706731),  INT64_C( 9000250393618946065), -INT64_C( 2326404326654095711),
      -INT64_C( 3226453474002137973), -INT64_C( 5914288864658093417),  INT64_C( 1790960914021623377),  INT64_C( 3677760460252361875),
      -INT64_C( 4787508756476800749),  INT64_C( 1958377309562048740),  INT64_C( 7296205029125983411), -INT64_C( 5989055669094870521),
       INT64_C( 4705970637597311594),  INT64_C( 3417088059500523399),  INT64_C( 4553590266985571579) };
  static const int64_t e[] =
    { -INT64_C( 8632981581385828011), -INT64_C( 2239817606574535208), -INT64_C( 9099564684331159749), -INT64_C( 3826010787564854341),
      -INT64_C( 7402516176979024276), -INT64_C( 5537315056505079417), -INT64_C( 6913257389855056709), -INT64_C( 4442598161519658215),
       INT64_C( 3845728427202045088), -INT64_C( 7241068158949826940), -INT64_C( 7383000126614681078), -INT64_C( 5417972102606660725),
      -INT64_C( 4379442142922551709), -INT64_C( 9133318228659669960),  INT64_C( 6924628408741987313), -INT64_C( 2550324397925795373),
      -INT64_C( 6516116651910343365),  INT64_C( 3519289601611835486), -INT64_C( 6033483514288505846), -INT64_C( 8288571651790444082),
      -INT64_C( 3264987183590978022), -INT64_C( 8176619906142798825), -INT64_C( 4634847295266738356), -INT64_C( 8958767519362558688),
       INT64_C(  983113988898850654),  INT64_C( 8362254563352309618), -INT64_C( 2611525720075438341),  INT64_C( 5667600842546536636),
      -INT64_C( 7068745511001346077), -INT64_C( 2754384524381508583),  INT64_C( 7014395614567415383), -INT64_C( 2532318931268936970),
      -INT64_C( 8511513951230467108), -INT64_C( 3140218499387001676),  INT64_C( 6062211586942316059), -INT64_C( 5764172306577840555),
      -INT64_C( 7940695115533691474), -INT64_C( 1292578362513820147), -INT64_C( 3682309483960983937),  INT64_C( 7081033778380496866),
      -INT64_C( 7015097288258079689), -INT64_C( 3061565566705285097), -INT64_C( 6263256081035888832),  INT64_C( 1650086438307691984),
      -INT64_C( 7814073571706250246), -INT64_C( 3819803429052792067),  INT64_C( 5186630905793434843),  INT64_C( 1457355496237698746),
      -INT64_C( 5045332595209738260), -INT64_C( 7971313462583055013), -INT64_C( 6151402586741648891),  INT64_C( 6401611666305640453),
       INT64_C( 2424871487151581492), -INT64_C( 3476428940395014003), -INT64_C( 5410265903923330992), -INT64_C( 8427581432194383922),
       INT64_C( 2074228049685656225), -INT64_C( 6767569582277569200),  INT64_C( 5579781266586310933),  INT64_C( 6515158046623725976),
      -INT64_C( 8631703702564105041), -INT64_C( 3077324410095488263), -INT64_C( 8752177526034101058),  INT64_C( 5819204416526977747),
      -INT64_C( 1776742020282874984),  INT64_C(  524322226350662833), -INT64_C( 3119585366818395364),  INT64_C( 5854482913177647449),
       INT64_C( 4970304603862726279),  INT64_C( 7416090574664061338), -INT64_C( 9166683150251639983),  INT64_C( 1401165445448435765),
       INT64_C( 1999374484848183903), -INT64_C( 9098035201017755216),  INT64_C(  738942001171820164), -INT64_C( 6949760934262621717),
       INT64_C( 6756268795724467244), -INT64_C( 1796580685750331041), -INT64_C( 8245551304338274382), -INT64_C( 2068279934157988500),
      -INT64_C( 6423122322009869869),  INT64_C( 6403915977598591637),  INT64_C( 2171140128500582350),  INT64_C( 1875320743269433746),
      -INT64_C( 6514708152725510945),  INT64_C( 9017694630684385279), -INT64_C( 5134217758510696913),  INT64_C( 7204480366314143385),
      -INT64_C( 1927561477844789965),  INT64_C( 5343524641545523245), -INT64_C( 6984619674779206645), -INT64_C( 1903268160262423173),
      -INT64_C( 4493255886225849044),  INT64_C( 5847672741526119834), -INT64_C( 3001344940283066543), -INT64_C( 5329120765108114572),
      -INT64_C( 8394053357415473644),  INT64_C( 5489038044127619194),  INT64_C( 4675515745820054688), -INT64_C( 3372707131267617916),
      -INT64_C(  224365791372736849), -INT64_C( 4947076531147497464), -INT64_C( 1939607274557296376), -INT64_C( 4764167471257453675),
      -INT64_C( 2764385401571689691),  INT64_C(  846688833259146986),  INT64_C( 1513242324169889331),  INT64_C( 9014739256088154480),
       INT64_C( 8645919508467748355),  INT64_C(  843177913516620315),  INT64_C( 7574600526615277352), -INT64_C( 1292599150226889520),
      -INT64_C( 3226453474002137973), -INT64_C( 7283869315960610553),  INT64_C( 1790960914021623377),  INT64_C( 3677760460252361875),
      -INT64_C( 2004580269058174893),  INT64_C( 1958377309562048740),  INT64_C( 7296205029125983411),  INT64_C( 5444591328011979500),
       INT64_C( 1126794783679747810),  INT64_C( 3417088059500523399),  INT64_C( 2443175539381038534) };

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
    rv = simde_svsel_s64(pv, av, bv);

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

    ev = simde_svsel_s64(pv, av, bv);

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
test_simde_x_svsel_u8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0) };
  static const uint8_t a[] =
    { UINT8_C(102), UINT8_C(160), UINT8_C( 95), UINT8_C(103), UINT8_C(249), UINT8_C(162), UINT8_C(179), UINT8_C( 73),
      UINT8_C(148), UINT8_C( 50), UINT8_C( 99), UINT8_C(204), UINT8_C( 37), UINT8_C( 35), UINT8_C(233), UINT8_C(213),
      UINT8_C(200), UINT8_C(105), UINT8_C( 91), UINT8_C(233), UINT8_C(161), UINT8_C(  5), UINT8_C(113), UINT8_C(243),
      UINT8_C(249), UINT8_C(141), UINT8_C(199), UINT8_C(122), UINT8_C( 18), UINT8_C( 82), UINT8_C( 36), UINT8_C(120),
      UINT8_C(242), UINT8_C(131), UINT8_C(223), UINT8_C(235), UINT8_C( 37), UINT8_C(147), UINT8_C( 52), UINT8_C(185),
      UINT8_C(197), UINT8_C(152), UINT8_C(133), UINT8_C(235), UINT8_C(187), UINT8_C(110), UINT8_C(192), UINT8_C(132),
      UINT8_C(216), UINT8_C( 27), UINT8_C(109), UINT8_C(121), UINT8_C( 32), UINT8_C(222), UINT8_C(108), UINT8_C( 25),
      UINT8_C(107), UINT8_C( 51), UINT8_C(147), UINT8_C(125), UINT8_C(134), UINT8_C(183), UINT8_C(246), UINT8_C(120),
      UINT8_C( 58), UINT8_C(213), UINT8_C(100), UINT8_C( 95), UINT8_C(104), UINT8_C(152), UINT8_C( 24), UINT8_C( 46),
      UINT8_C( 48), UINT8_C(157), UINT8_C( 25), UINT8_C(236), UINT8_C( 11), UINT8_C(217), UINT8_C(112), UINT8_C(227),
      UINT8_C(244), UINT8_C(221), UINT8_C( 93), UINT8_C( 20), UINT8_C(187), UINT8_C(201), UINT8_C( 45), UINT8_C( 39),
      UINT8_C(253), UINT8_C(192), UINT8_C(164), UINT8_C(131), UINT8_C(119), UINT8_C(154), UINT8_C(251), UINT8_C(177),
      UINT8_C(112), UINT8_C( 95), UINT8_C( 16), UINT8_C(216), UINT8_C(248), UINT8_C( 40), UINT8_C(  6), UINT8_C( 40),
      UINT8_C(197), UINT8_C( 31), UINT8_C( 20), UINT8_C(208), UINT8_C(248), UINT8_C(132), UINT8_C(180), UINT8_C(236),
      UINT8_C( 97), UINT8_C( 17), UINT8_C(  0), UINT8_C( 29), UINT8_C(218), UINT8_C( 45), UINT8_C( 68), UINT8_C(215),
      UINT8_C(237), UINT8_C(232), UINT8_C( 90), UINT8_C(100), UINT8_C(131), UINT8_C( 86), UINT8_C( 21), UINT8_C(243),
      UINT8_C(181), UINT8_C( 37), UINT8_C(203), UINT8_C(173), UINT8_C( 77), UINT8_C(210), UINT8_C(214), UINT8_C( 18),
      UINT8_C(241), UINT8_C(234), UINT8_C(227), UINT8_C(234), UINT8_C(111), UINT8_C(151), UINT8_C(214), UINT8_C(208),
      UINT8_C(168), UINT8_C(215), UINT8_C(237), UINT8_C(130), UINT8_C(  4), UINT8_C( 49), UINT8_C( 90), UINT8_C(242),
      UINT8_C( 26), UINT8_C(180), UINT8_C( 86), UINT8_C(157), UINT8_C( 10), UINT8_C(108), UINT8_C(144), UINT8_C(192),
      UINT8_C(145), UINT8_C( 91), UINT8_C(109), UINT8_C(223), UINT8_C( 45), UINT8_C( 67), UINT8_C(241), UINT8_C( 31),
      UINT8_C( 46), UINT8_C(212), UINT8_C(  9), UINT8_C(157), UINT8_C(107), UINT8_C(223), UINT8_C(109), UINT8_C( 19),
      UINT8_C(182), UINT8_C( 91), UINT8_C(150), UINT8_C(187), UINT8_C(140), UINT8_C(240), UINT8_C(173), UINT8_C(166),
      UINT8_C(164), UINT8_C(  3), UINT8_C( 67), UINT8_C(175), UINT8_C(111), UINT8_C(211), UINT8_C(111), UINT8_C(  1),
      UINT8_C( 47), UINT8_C(220), UINT8_C(224), UINT8_C( 92), UINT8_C( 32), UINT8_C(209), UINT8_C(123), UINT8_C( 78),
      UINT8_C(166), UINT8_C(132), UINT8_C(235), UINT8_C( 17), UINT8_C(100), UINT8_C( 88), UINT8_C( 37), UINT8_C( 26),
      UINT8_C(179), UINT8_C(187), UINT8_C(213), UINT8_C( 64), UINT8_C(171), UINT8_C(130), UINT8_C(230), UINT8_C( 79),
      UINT8_C(134), UINT8_C( 42), UINT8_C(254), UINT8_C(245), UINT8_C(253), UINT8_C(109), UINT8_C(246), UINT8_C( 44),
      UINT8_C( 74), UINT8_C(214), UINT8_C(137), UINT8_C(106), UINT8_C(168), UINT8_C(  4), UINT8_C(184), UINT8_C( 78),
      UINT8_C(137), UINT8_C(163), UINT8_C( 95), UINT8_C(237), UINT8_C(251), UINT8_C(132), UINT8_C(  7), UINT8_C(175),
      UINT8_C( 63), UINT8_C(221), UINT8_C(239), UINT8_C(234), UINT8_C( 95), UINT8_C(213), UINT8_C( 58), UINT8_C(229),
         UINT8_MAX, UINT8_C( 56), UINT8_C(219), UINT8_C(253), UINT8_C(166), UINT8_C(209), UINT8_C( 41), UINT8_C(240),
      UINT8_C(168), UINT8_C(178), UINT8_C( 90), UINT8_C( 80), UINT8_C(183), UINT8_C( 18), UINT8_C(158), UINT8_C( 64),
      UINT8_C(181), UINT8_C(253), UINT8_C( 45), UINT8_C(176), UINT8_C(130), UINT8_C( 52), UINT8_C( 95), UINT8_C(193),
      UINT8_C( 17), UINT8_C( 78), UINT8_C(172), UINT8_C(113), UINT8_C( 36), UINT8_C(230), UINT8_C( 86), UINT8_C( 35),
      UINT8_C( 30), UINT8_C( 49), UINT8_C( 32), UINT8_C(196), UINT8_C(  3), UINT8_C( 74), UINT8_C(180), UINT8_C(171),
      UINT8_C(252), UINT8_C( 14), UINT8_C(251), UINT8_C(179), UINT8_C( 32), UINT8_C(153), UINT8_C(243), UINT8_C(213),
      UINT8_C(150), UINT8_C( 32), UINT8_C(134), UINT8_C( 24), UINT8_C( 85), UINT8_C(229), UINT8_C(218), UINT8_C(102),
      UINT8_C( 52), UINT8_C(134), UINT8_C(215), UINT8_C( 88), UINT8_C(108), UINT8_C( 46), UINT8_C(123), UINT8_C(138),
      UINT8_C( 95), UINT8_C(156), UINT8_C( 79), UINT8_C( 98), UINT8_C(230), UINT8_C(  3), UINT8_C( 13), UINT8_C(226),
      UINT8_C( 18), UINT8_C(  8), UINT8_C(150), UINT8_C( 50), UINT8_C(161), UINT8_C(137), UINT8_C(  8), UINT8_C( 56),
      UINT8_C(170), UINT8_C(142), UINT8_C( 80),    UINT8_MAX, UINT8_C(115), UINT8_C( 42), UINT8_C(101), UINT8_C(167),
      UINT8_C(176), UINT8_C( 61),    UINT8_MAX, UINT8_C( 28), UINT8_C(107), UINT8_C(123), UINT8_C(167), UINT8_C(202),
      UINT8_C( 23), UINT8_C(246), UINT8_C( 45), UINT8_C(253), UINT8_C(249), UINT8_C( 58), UINT8_C(223), UINT8_C( 11),
      UINT8_C( 67), UINT8_C(117), UINT8_C( 62), UINT8_C(228),    UINT8_MAX, UINT8_C( 70), UINT8_C( 28), UINT8_C(169),
      UINT8_C(212), UINT8_C(109), UINT8_C(168), UINT8_C( 71), UINT8_C(151), UINT8_C( 13), UINT8_C(239), UINT8_C( 72),
      UINT8_C( 74), UINT8_C(238), UINT8_C(100), UINT8_C(181), UINT8_C(105), UINT8_C( 11), UINT8_C(128), UINT8_C(128),
      UINT8_C(  1), UINT8_C(173), UINT8_C(125), UINT8_C(251), UINT8_C(231), UINT8_C( 93), UINT8_C(  6), UINT8_C( 42),
      UINT8_C(210), UINT8_C( 68), UINT8_C( 15), UINT8_C(209), UINT8_C(138), UINT8_C( 43), UINT8_C(122), UINT8_C( 94),
      UINT8_C(152), UINT8_C( 34), UINT8_C(166), UINT8_C( 48), UINT8_C( 48), UINT8_C(149), UINT8_C(120), UINT8_C(122),
      UINT8_C(131), UINT8_C(220), UINT8_C( 48), UINT8_C(237), UINT8_C(232), UINT8_C(176), UINT8_C(109), UINT8_C(233),
      UINT8_C( 93), UINT8_C(235), UINT8_C(228), UINT8_C( 68), UINT8_C( 72), UINT8_C(235), UINT8_C(111), UINT8_C( 26),
      UINT8_C( 47), UINT8_C(126), UINT8_C(236), UINT8_C(186), UINT8_C(169), UINT8_C(102), UINT8_C( 24), UINT8_C( 66),
      UINT8_C(137), UINT8_C(190), UINT8_C(114), UINT8_C(185), UINT8_C( 83), UINT8_C(234), UINT8_C( 51), UINT8_C(215),
      UINT8_C(198), UINT8_C( 99), UINT8_C(196), UINT8_C(174), UINT8_C( 19), UINT8_C( 49), UINT8_C(152), UINT8_C(112),
      UINT8_C( 28), UINT8_C(124), UINT8_C(181), UINT8_C(100), UINT8_C(103), UINT8_C( 36), UINT8_C(127), UINT8_C(151),
      UINT8_C(162), UINT8_C(107), UINT8_C( 81), UINT8_C( 75), UINT8_C(209), UINT8_C(105), UINT8_C(141), UINT8_C( 90),
      UINT8_C( 40),    UINT8_MAX, UINT8_C( 19), UINT8_C(123), UINT8_C(233), UINT8_C( 71), UINT8_C( 82), UINT8_C(176),
      UINT8_C(170), UINT8_C( 22), UINT8_C( 94), UINT8_C(190), UINT8_C( 72), UINT8_C(246), UINT8_C( 46), UINT8_C(100),
      UINT8_C(115), UINT8_C(227), UINT8_C(201), UINT8_C(218), UINT8_C(  7), UINT8_C( 72), UINT8_C(113), UINT8_C(169),
      UINT8_C(179), UINT8_C(194), UINT8_C(245), UINT8_C(132), UINT8_C( 44), UINT8_C(130), UINT8_C(223), UINT8_C( 84),
      UINT8_C(130), UINT8_C(242), UINT8_C(207), UINT8_C(107), UINT8_C( 57), UINT8_C( 34), UINT8_C( 27), UINT8_C(228),
      UINT8_C( 56), UINT8_C(122), UINT8_C(162), UINT8_C(128), UINT8_C(112), UINT8_C(208), UINT8_C(229), UINT8_C(227),
      UINT8_C(180), UINT8_C(174), UINT8_C(190), UINT8_C(187), UINT8_C(246), UINT8_C( 47), UINT8_C(101), UINT8_C(169),
      UINT8_C(242), UINT8_C( 90), UINT8_C( 45), UINT8_C( 30), UINT8_C(220), UINT8_C( 12), UINT8_C(114), UINT8_C( 94),
         UINT8_MAX, UINT8_C( 65), UINT8_C(202), UINT8_C( 56), UINT8_C( 99), UINT8_C(229), UINT8_C( 28), UINT8_C(156),
      UINT8_C( 95), UINT8_C(190), UINT8_C( 28), UINT8_C(208), UINT8_C(143), UINT8_C(  1), UINT8_C(179), UINT8_C( 67),
      UINT8_C(175), UINT8_C(113), UINT8_C(254), UINT8_C(165), UINT8_C(161), UINT8_C( 99), UINT8_C( 78), UINT8_C(147),
      UINT8_C(189), UINT8_C(124), UINT8_C(177), UINT8_C(154), UINT8_C(136), UINT8_C( 35), UINT8_C(248), UINT8_C(135),
      UINT8_C(100), UINT8_C(194), UINT8_C(192), UINT8_C(200), UINT8_C(168), UINT8_C(220), UINT8_C(100), UINT8_C(  7),
      UINT8_C(155), UINT8_C(128), UINT8_C(215), UINT8_C( 42), UINT8_C(130), UINT8_C(139), UINT8_C(109), UINT8_C( 49),
      UINT8_C(252), UINT8_C(107), UINT8_C(215), UINT8_C(157), UINT8_C(207), UINT8_C( 37), UINT8_C( 48), UINT8_C(140),
      UINT8_C(161), UINT8_C(225), UINT8_C( 38), UINT8_C( 42), UINT8_C(  4), UINT8_C( 31), UINT8_C(177), UINT8_C(105),
      UINT8_C(225), UINT8_C(113), UINT8_C( 49), UINT8_C(137), UINT8_C( 78), UINT8_C(149), UINT8_C(145), UINT8_C(233),
      UINT8_C( 21), UINT8_C(104), UINT8_C( 19), UINT8_C(151), UINT8_C(243), UINT8_C(128), UINT8_C(201), UINT8_C(240),
      UINT8_C(235), UINT8_C(160), UINT8_C(141), UINT8_C(186), UINT8_C(197), UINT8_C(190), UINT8_C( 71), UINT8_C(103),
      UINT8_C(159), UINT8_C(109), UINT8_C(145), UINT8_C(164), UINT8_C(140), UINT8_C( 66), UINT8_C( 13), UINT8_C(110),
      UINT8_C(180), UINT8_C( 62), UINT8_C(247), UINT8_C(  2), UINT8_C(211), UINT8_C(136), UINT8_C(235), UINT8_C(232),
      UINT8_C(241), UINT8_C(254), UINT8_C(128), UINT8_C(228), UINT8_C(126), UINT8_C( 73), UINT8_C(212), UINT8_C(105),
      UINT8_C(233), UINT8_C( 98), UINT8_C( 36), UINT8_C(174), UINT8_C( 32), UINT8_C(107), UINT8_C( 21), UINT8_C(191),
      UINT8_C(216), UINT8_C(166), UINT8_C( 99), UINT8_C(101), UINT8_C(233), UINT8_C(112), UINT8_C(211), UINT8_C(157),
      UINT8_C(174), UINT8_C(202), UINT8_C(159), UINT8_C(129), UINT8_C( 83), UINT8_C(138), UINT8_C(106), UINT8_C( 68),
      UINT8_C(136), UINT8_C(234), UINT8_C( 40), UINT8_C(  6), UINT8_C( 51), UINT8_C(253), UINT8_C(111), UINT8_C( 28),
      UINT8_C( 95), UINT8_C(147), UINT8_C(202), UINT8_C(127), UINT8_C(254), UINT8_C(224), UINT8_C( 62), UINT8_C(215),
      UINT8_C(134), UINT8_C(162), UINT8_C( 60), UINT8_C(111), UINT8_C( 18), UINT8_C( 15), UINT8_C( 12), UINT8_C(193),
      UINT8_C(217), UINT8_C(171), UINT8_C( 66), UINT8_C( 44), UINT8_C( 53), UINT8_C(172), UINT8_C(112), UINT8_C(189),
      UINT8_C(150), UINT8_C(153), UINT8_C(195), UINT8_C(201), UINT8_C(150), UINT8_C( 51), UINT8_C(229), UINT8_C(245),
      UINT8_C(198), UINT8_C(176), UINT8_C(116), UINT8_C(197), UINT8_C(144), UINT8_C(178), UINT8_C(156), UINT8_C( 22),
      UINT8_C( 84), UINT8_C(216), UINT8_C(134), UINT8_C(103), UINT8_C(231), UINT8_C(146), UINT8_C( 40), UINT8_C(192),
      UINT8_C( 62), UINT8_C(106), UINT8_C(237), UINT8_C(115), UINT8_C( 23), UINT8_C( 93), UINT8_C( 49), UINT8_C(173),
      UINT8_C(246), UINT8_C(244), UINT8_C(119), UINT8_C(140), UINT8_C( 39), UINT8_C( 92), UINT8_C(129), UINT8_C(238),
      UINT8_C( 12), UINT8_C(245), UINT8_C(179), UINT8_C(156), UINT8_C(168), UINT8_C( 79), UINT8_C(179), UINT8_C(252),
      UINT8_C( 39), UINT8_C( 57), UINT8_C( 99), UINT8_C( 14), UINT8_C(203), UINT8_C(139), UINT8_C(206), UINT8_C(  9),
      UINT8_C(246), UINT8_C(187), UINT8_C(125), UINT8_C( 13), UINT8_C( 25), UINT8_C(174), UINT8_C(186), UINT8_C( 15),
      UINT8_C(162), UINT8_C( 49), UINT8_C(156), UINT8_C(202), UINT8_C(142), UINT8_C( 29), UINT8_C(184), UINT8_C(154),
      UINT8_C( 19), UINT8_C(107), UINT8_C( 55), UINT8_C(187), UINT8_C(186), UINT8_C(234), UINT8_C(183), UINT8_C(225),
      UINT8_C( 35), UINT8_C( 27), UINT8_C(239), UINT8_C(238), UINT8_C(166), UINT8_C(189), UINT8_C(248), UINT8_C(156),
      UINT8_C(121), UINT8_C(117), UINT8_C(169), UINT8_C(146), UINT8_C( 35), UINT8_C(100), UINT8_C(161), UINT8_C(197),
      UINT8_C(149), UINT8_C( 61), UINT8_C(143), UINT8_C( 35), UINT8_C( 91), UINT8_C( 71), UINT8_C(190), UINT8_C(110),
      UINT8_C(178), UINT8_C(245), UINT8_C( 41), UINT8_C(108), UINT8_C(223), UINT8_C(224), UINT8_C( 77), UINT8_C(  2),
      UINT8_C(251), UINT8_C( 60), UINT8_C(240), UINT8_C(162), UINT8_C(250), UINT8_C(232), UINT8_C( 62), UINT8_C(115),
      UINT8_C( 93), UINT8_C(232), UINT8_C(  5), UINT8_C(128), UINT8_C( 76), UINT8_C(166), UINT8_C( 70), UINT8_C(225),
      UINT8_C(228), UINT8_C(213), UINT8_C(  5), UINT8_C( 63), UINT8_C( 29), UINT8_C(195), UINT8_C(173), UINT8_C(207),
      UINT8_C(184), UINT8_C(214), UINT8_C( 60) };
  static const uint8_t e[] =
    { UINT8_C(  0), UINT8_C(160), UINT8_C(  0), UINT8_C(103), UINT8_C(249), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 50), UINT8_C( 99), UINT8_C(204), UINT8_C(  0), UINT8_C( 35), UINT8_C(233), UINT8_C(213),
      UINT8_C(200), UINT8_C(  0), UINT8_C( 91), UINT8_C(  0), UINT8_C(161), UINT8_C(  5), UINT8_C(  0), UINT8_C(243),
      UINT8_C(  0), UINT8_C(141), UINT8_C(  0), UINT8_C(122), UINT8_C( 18), UINT8_C( 82), UINT8_C( 36), UINT8_C(120),
      UINT8_C(242), UINT8_C(  0), UINT8_C(  0), UINT8_C(235), UINT8_C( 37), UINT8_C(147), UINT8_C(  0), UINT8_C(185),
      UINT8_C(  0), UINT8_C(152), UINT8_C(133), UINT8_C(235), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(132),
      UINT8_C(216), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 32), UINT8_C(222), UINT8_C(108), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(147), UINT8_C(125), UINT8_C(  0), UINT8_C(183), UINT8_C(246), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(100), UINT8_C(  0), UINT8_C(104), UINT8_C(  0), UINT8_C(  0), UINT8_C( 46),
      UINT8_C( 48), UINT8_C(157), UINT8_C(  0), UINT8_C(236), UINT8_C(  0), UINT8_C(217), UINT8_C(112), UINT8_C(227),
      UINT8_C(244), UINT8_C(221), UINT8_C(  0), UINT8_C( 20), UINT8_C(  0), UINT8_C(201), UINT8_C(  0), UINT8_C( 39),
      UINT8_C(253), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(177),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 16), UINT8_C(216), UINT8_C(  0), UINT8_C( 40), UINT8_C(  6), UINT8_C( 40),
      UINT8_C(197), UINT8_C( 31), UINT8_C( 20), UINT8_C(208), UINT8_C(248), UINT8_C(132), UINT8_C(180), UINT8_C(236),
      UINT8_C( 97), UINT8_C( 17), UINT8_C(  0), UINT8_C(  0), UINT8_C(218), UINT8_C( 45), UINT8_C( 68), UINT8_C(215),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 90), UINT8_C(100), UINT8_C(  0), UINT8_C( 86), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(181), UINT8_C( 37), UINT8_C(  0), UINT8_C(  0), UINT8_C( 77), UINT8_C(  0), UINT8_C(214), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(234), UINT8_C(  0), UINT8_C(234), UINT8_C(111), UINT8_C(151), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(237), UINT8_C(130), UINT8_C(  4), UINT8_C(  0), UINT8_C( 90), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 86), UINT8_C(  0), UINT8_C(  0), UINT8_C(108), UINT8_C(144), UINT8_C(192),
      UINT8_C(145), UINT8_C(  0), UINT8_C(109), UINT8_C(  0), UINT8_C(  0), UINT8_C( 67), UINT8_C(241), UINT8_C(  0),
      UINT8_C( 46), UINT8_C(212), UINT8_C(  0), UINT8_C(  0), UINT8_C(107), UINT8_C(223), UINT8_C(109), UINT8_C( 19),
      UINT8_C(182), UINT8_C(  0), UINT8_C(150), UINT8_C(187), UINT8_C(140), UINT8_C(240), UINT8_C(173), UINT8_C(166),
      UINT8_C(164), UINT8_C(  3), UINT8_C(  0), UINT8_C(175), UINT8_C(111), UINT8_C(  0), UINT8_C(111), UINT8_C(  0),
      UINT8_C( 47), UINT8_C(  0), UINT8_C(224), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(123), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(132), UINT8_C(235), UINT8_C( 17), UINT8_C(  0), UINT8_C(  0), UINT8_C( 37), UINT8_C(  0),
      UINT8_C(179), UINT8_C(187), UINT8_C(213), UINT8_C(  0), UINT8_C(  0), UINT8_C(130), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 42), UINT8_C(254), UINT8_C(  0), UINT8_C(253), UINT8_C(  0), UINT8_C(  0), UINT8_C( 44),
      UINT8_C( 74), UINT8_C(214), UINT8_C(137), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 78),
      UINT8_C(  0), UINT8_C(163), UINT8_C( 95), UINT8_C(237), UINT8_C(  0), UINT8_C(132), UINT8_C(  7), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(221), UINT8_C(  0), UINT8_C(234), UINT8_C(  0), UINT8_C(213), UINT8_C( 58), UINT8_C(229),
      UINT8_C(  0), UINT8_C( 56), UINT8_C(219), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 41), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 80), UINT8_C(  0), UINT8_C( 18), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 45), UINT8_C(176), UINT8_C(130), UINT8_C( 52), UINT8_C( 95), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(172), UINT8_C(113), UINT8_C( 36), UINT8_C(230), UINT8_C( 86), UINT8_C( 35),
      UINT8_C( 30), UINT8_C(  0), UINT8_C( 32), UINT8_C(196), UINT8_C(  3), UINT8_C(  0), UINT8_C(180), UINT8_C(171),
      UINT8_C(252), UINT8_C(  0), UINT8_C(251), UINT8_C(  0), UINT8_C( 32), UINT8_C(153), UINT8_C(243), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 32), UINT8_C(134), UINT8_C( 24), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(102),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 46), UINT8_C(123), UINT8_C(138),
      UINT8_C(  0), UINT8_C(156), UINT8_C(  0), UINT8_C( 98), UINT8_C(  0), UINT8_C(  0), UINT8_C( 13), UINT8_C(226),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(150), UINT8_C( 50), UINT8_C(  0), UINT8_C(137), UINT8_C(  8), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(115), UINT8_C( 42), UINT8_C(101), UINT8_C(  0),
      UINT8_C(176), UINT8_C(  0), UINT8_C(  0), UINT8_C( 28), UINT8_C(107), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(246), UINT8_C(  0), UINT8_C(253), UINT8_C(249), UINT8_C( 58), UINT8_C(  0), UINT8_C( 11),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 70), UINT8_C( 28), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(151), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(238), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128),
      UINT8_C(  1), UINT8_C(173), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 93), UINT8_C(  0), UINT8_C( 42),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 15), UINT8_C(  0), UINT8_C(  0), UINT8_C( 43), UINT8_C(  0), UINT8_C( 94),
      UINT8_C(152), UINT8_C( 34), UINT8_C(166), UINT8_C( 48), UINT8_C(  0), UINT8_C(  0), UINT8_C(120), UINT8_C(122),
      UINT8_C(  0), UINT8_C(220), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(235), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 47), UINT8_C(126), UINT8_C(236), UINT8_C(  0), UINT8_C(169), UINT8_C(102), UINT8_C( 24), UINT8_C( 66),
      UINT8_C(137), UINT8_C(190), UINT8_C(  0), UINT8_C(185), UINT8_C( 83), UINT8_C(234), UINT8_C( 51), UINT8_C(  0),
      UINT8_C(198), UINT8_C( 99), UINT8_C(196), UINT8_C(174), UINT8_C(  0), UINT8_C( 49), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(181), UINT8_C(  0), UINT8_C(  0), UINT8_C( 36), UINT8_C(  0), UINT8_C(151),
      UINT8_C(162), UINT8_C(107), UINT8_C(  0), UINT8_C(  0), UINT8_C(209), UINT8_C(105), UINT8_C(141), UINT8_C( 90),
      UINT8_C( 40),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(233), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(170), UINT8_C( 22), UINT8_C(  0), UINT8_C(190), UINT8_C( 72), UINT8_C(  0), UINT8_C( 46), UINT8_C(100),
      UINT8_C(115), UINT8_C(227), UINT8_C(201), UINT8_C(218), UINT8_C(  0), UINT8_C(  0), UINT8_C(113), UINT8_C(169),
      UINT8_C(179), UINT8_C(194), UINT8_C(  0), UINT8_C(132), UINT8_C( 44), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(130), UINT8_C(242), UINT8_C(207), UINT8_C(107), UINT8_C( 57), UINT8_C(  0), UINT8_C(  0), UINT8_C(228),
      UINT8_C( 56), UINT8_C(122), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(227),
      UINT8_C(  0), UINT8_C(174), UINT8_C(190), UINT8_C(  0), UINT8_C(246), UINT8_C( 47), UINT8_C(  0), UINT8_C(169),
      UINT8_C(242), UINT8_C( 90), UINT8_C( 45), UINT8_C(  0), UINT8_C(220), UINT8_C( 12), UINT8_C(114), UINT8_C(  0),
         UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C( 56), UINT8_C( 99), UINT8_C(  0), UINT8_C(  0), UINT8_C(156),
      UINT8_C( 95), UINT8_C(190), UINT8_C(  0), UINT8_C(208), UINT8_C(  0), UINT8_C(  0), UINT8_C(179), UINT8_C(  0),
      UINT8_C(175), UINT8_C(113), UINT8_C(  0), UINT8_C(165), UINT8_C(161), UINT8_C( 99), UINT8_C( 78), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(177), UINT8_C(154), UINT8_C(136), UINT8_C( 35), UINT8_C(  0), UINT8_C(135),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(200), UINT8_C(168), UINT8_C(  0), UINT8_C(  0), UINT8_C(  7),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(107), UINT8_C(  0), UINT8_C(157), UINT8_C(  0), UINT8_C( 37), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(161), UINT8_C(225), UINT8_C(  0), UINT8_C( 42), UINT8_C(  0), UINT8_C(  0), UINT8_C(177), UINT8_C(105),
      UINT8_C(225), UINT8_C(113), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(145), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(151), UINT8_C(243), UINT8_C(  0), UINT8_C(  0), UINT8_C(240),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(141), UINT8_C(  0), UINT8_C(  0), UINT8_C(190), UINT8_C( 71), UINT8_C(103),
      UINT8_C(159), UINT8_C(109), UINT8_C(145), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 13), UINT8_C(110),
      UINT8_C(  0), UINT8_C( 62), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(232),
      UINT8_C(241), UINT8_C(254), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 73), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(233), UINT8_C( 98), UINT8_C(  0), UINT8_C(  0), UINT8_C( 32), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(216), UINT8_C(166), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(174), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 83), UINT8_C(138), UINT8_C(106), UINT8_C(  0),
      UINT8_C(136), UINT8_C(  0), UINT8_C( 40), UINT8_C(  6), UINT8_C( 51), UINT8_C(253), UINT8_C(111), UINT8_C( 28),
      UINT8_C( 95), UINT8_C(  0), UINT8_C(202), UINT8_C(127), UINT8_C(  0), UINT8_C(224), UINT8_C( 62), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(111), UINT8_C(  0), UINT8_C(  0), UINT8_C( 12), UINT8_C(  0),
      UINT8_C(217), UINT8_C(  0), UINT8_C(  0), UINT8_C( 44), UINT8_C(  0), UINT8_C(172), UINT8_C(  0), UINT8_C(189),
      UINT8_C(150), UINT8_C(153), UINT8_C(  0), UINT8_C(201), UINT8_C(150), UINT8_C(  0), UINT8_C(  0), UINT8_C(245),
      UINT8_C(198), UINT8_C(176), UINT8_C(  0), UINT8_C(  0), UINT8_C(144), UINT8_C(178), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(216), UINT8_C(134), UINT8_C(103), UINT8_C(  0), UINT8_C(  0), UINT8_C( 40), UINT8_C(  0),
      UINT8_C( 62), UINT8_C(  0), UINT8_C(  0), UINT8_C(115), UINT8_C( 23), UINT8_C(  0), UINT8_C(  0), UINT8_C(173),
      UINT8_C(246), UINT8_C(244), UINT8_C(  0), UINT8_C(140), UINT8_C(  0), UINT8_C( 92), UINT8_C(  0), UINT8_C(238),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(156), UINT8_C(  0), UINT8_C( 79), UINT8_C(179), UINT8_C(  0),
      UINT8_C( 39), UINT8_C( 57), UINT8_C( 99), UINT8_C( 14), UINT8_C(203), UINT8_C(139), UINT8_C(  0), UINT8_C(  9),
      UINT8_C(246), UINT8_C(  0), UINT8_C(  0), UINT8_C( 13), UINT8_C(  0), UINT8_C(174), UINT8_C(186), UINT8_C(  0),
      UINT8_C(162), UINT8_C(  0), UINT8_C(156), UINT8_C(202), UINT8_C(142), UINT8_C(  0), UINT8_C(184), UINT8_C(154),
      UINT8_C(  0), UINT8_C(107), UINT8_C( 55), UINT8_C(187), UINT8_C(186), UINT8_C(234), UINT8_C(183), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 27), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(248), UINT8_C(  0),
      UINT8_C(121), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(100), UINT8_C(  0), UINT8_C(197),
      UINT8_C(149), UINT8_C(  0), UINT8_C(143), UINT8_C(  0), UINT8_C(  0), UINT8_C( 71), UINT8_C(  0), UINT8_C(110),
      UINT8_C(178), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(223), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(162), UINT8_C(250), UINT8_C(  0), UINT8_C( 62), UINT8_C(  0),
      UINT8_C( 93), UINT8_C(  0), UINT8_C(  5), UINT8_C(128), UINT8_C( 76), UINT8_C(166), UINT8_C( 70), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(213), UINT8_C(  5), UINT8_C( 63), UINT8_C(  0), UINT8_C(195), UINT8_C(173), UINT8_C(207),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) };

  static uint8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t
      rv,
      av = simde_svld1_u8(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(INT8_C(0)));
    rv = simde_x_svsel_u8_z(pv, av);

    simde_svst1_u8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vu8(len, e, r);

  return 0;
#else
  int8_t p[1024];
  uint8_t a[1024], e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_u8(pg, &(a[i]));

    ev = simde_x_svsel_u8_z(pv, av);

    simde_svst1_u8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsel_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) };
  static const uint8_t a[] =
    { UINT8_C(127), UINT8_C(227), UINT8_C( 12), UINT8_C( 57), UINT8_C(117), UINT8_C( 20), UINT8_C(202), UINT8_C(201),
      UINT8_C( 99), UINT8_C( 98), UINT8_C(191), UINT8_C( 77), UINT8_C(197), UINT8_C(217), UINT8_C( 47), UINT8_C(  7),
      UINT8_C(226), UINT8_C(247), UINT8_C(192), UINT8_C( 66), UINT8_C(  7), UINT8_C(178), UINT8_C( 90), UINT8_C(131),
      UINT8_C(168), UINT8_C(221), UINT8_C( 33), UINT8_C(202), UINT8_C( 78), UINT8_C(158), UINT8_C( 81), UINT8_C(205),
      UINT8_C(129), UINT8_C( 93), UINT8_C(  6), UINT8_C(246), UINT8_C(114), UINT8_C(208), UINT8_C(192), UINT8_C(213),
      UINT8_C( 51), UINT8_C(127), UINT8_C( 34), UINT8_C(248), UINT8_C( 89), UINT8_C( 81),    UINT8_MAX, UINT8_C( 59),
      UINT8_C( 73), UINT8_C(192), UINT8_C(126), UINT8_C( 80), UINT8_C(114), UINT8_C(216), UINT8_C(211), UINT8_C( 26),
      UINT8_C(181), UINT8_C(244), UINT8_C(228), UINT8_C(  4), UINT8_C(146), UINT8_C( 53), UINT8_C(209), UINT8_C( 20),
      UINT8_C(147), UINT8_C(216), UINT8_C( 10), UINT8_C(  5), UINT8_C(168), UINT8_C(202), UINT8_C(218), UINT8_C(219),
      UINT8_C( 74), UINT8_C(253), UINT8_C(212), UINT8_C(163), UINT8_C( 78), UINT8_C(211), UINT8_C(222), UINT8_C(151),
      UINT8_C(147), UINT8_C( 92), UINT8_C(232), UINT8_C(  6), UINT8_C( 53), UINT8_C(187), UINT8_C( 32), UINT8_C(234),
      UINT8_C(176), UINT8_C(  5), UINT8_C(238), UINT8_C( 66), UINT8_C( 58), UINT8_C(192), UINT8_C( 86), UINT8_C(205),
      UINT8_C(152), UINT8_C( 97), UINT8_C(210), UINT8_C( 64), UINT8_C( 43), UINT8_C(173), UINT8_C( 28), UINT8_C(117),
      UINT8_C(170), UINT8_C(240), UINT8_C( 24), UINT8_C(248), UINT8_C(195), UINT8_C(247), UINT8_C(144), UINT8_C( 87),
      UINT8_C( 83), UINT8_C(120), UINT8_C( 93), UINT8_C(136), UINT8_C( 51), UINT8_C(125), UINT8_C(115), UINT8_C(227),
      UINT8_C(130), UINT8_C( 97), UINT8_C( 38), UINT8_C(189), UINT8_C( 33), UINT8_C(124), UINT8_C(138), UINT8_C(185),
      UINT8_C(221), UINT8_C( 93), UINT8_C(250), UINT8_C(  9), UINT8_C( 10), UINT8_C( 22), UINT8_C(126), UINT8_C(180),
      UINT8_C(  6), UINT8_C(151), UINT8_C(172), UINT8_C(201), UINT8_C(142), UINT8_C( 60), UINT8_C( 32), UINT8_C(225),
      UINT8_C(180), UINT8_C(125), UINT8_C(106), UINT8_C(232), UINT8_C(251), UINT8_C(221), UINT8_C(203), UINT8_C(125),
      UINT8_C( 62), UINT8_C(241), UINT8_C( 58), UINT8_C( 96), UINT8_C(110), UINT8_C(197), UINT8_C( 25), UINT8_C( 75),
      UINT8_C( 34), UINT8_C( 19), UINT8_C( 84), UINT8_C( 44), UINT8_C( 41), UINT8_C(211), UINT8_C(224), UINT8_C( 47),
      UINT8_C(106), UINT8_C(140), UINT8_C(249), UINT8_C(248), UINT8_C(201), UINT8_C( 25), UINT8_C(217), UINT8_C(125),
      UINT8_C(151), UINT8_C( 67), UINT8_C(101), UINT8_C(146), UINT8_C( 32), UINT8_C( 49), UINT8_C( 15), UINT8_C( 95),
      UINT8_C( 34), UINT8_C( 74), UINT8_C(191), UINT8_C(144), UINT8_C( 15), UINT8_C(216), UINT8_C(220), UINT8_C( 49),
      UINT8_C(236), UINT8_C( 48), UINT8_C( 93), UINT8_C( 21), UINT8_C(  3), UINT8_C( 61), UINT8_C( 69), UINT8_C(109),
      UINT8_C(201), UINT8_C( 62), UINT8_C(101), UINT8_C(146), UINT8_C( 87), UINT8_C( 63), UINT8_C( 16), UINT8_C(238),
      UINT8_C(130), UINT8_C(117), UINT8_C(128), UINT8_C(163), UINT8_C(166), UINT8_C(144), UINT8_C(  2), UINT8_C(201),
      UINT8_C(218), UINT8_C(193), UINT8_C( 89), UINT8_C(233), UINT8_C(153), UINT8_C( 53), UINT8_C( 26), UINT8_C(133),
      UINT8_C(102), UINT8_C(119), UINT8_C(155), UINT8_C(105), UINT8_C(180), UINT8_C(224), UINT8_C(215), UINT8_C(125),
      UINT8_C( 30), UINT8_C( 60), UINT8_C( 16), UINT8_C(117), UINT8_C(123), UINT8_C( 32), UINT8_C(100), UINT8_C(254),
      UINT8_C(149), UINT8_C(228), UINT8_C(161), UINT8_C( 60), UINT8_C(116), UINT8_C(163), UINT8_C(  5), UINT8_C( 78),
      UINT8_C(100), UINT8_C( 94), UINT8_C( 55), UINT8_C(253), UINT8_C(148), UINT8_C( 81), UINT8_C(131), UINT8_C(250),
      UINT8_C(200), UINT8_C( 30), UINT8_C( 99), UINT8_C(124), UINT8_C(254), UINT8_C( 58), UINT8_C(250), UINT8_C( 28),
      UINT8_C(119), UINT8_C( 10), UINT8_C(145), UINT8_C(242), UINT8_C( 42), UINT8_C(245), UINT8_C(240), UINT8_C(191),
      UINT8_C(218), UINT8_C(145), UINT8_C(251), UINT8_C( 78), UINT8_C( 52), UINT8_C(  0), UINT8_C(157), UINT8_C(152),
      UINT8_C( 95), UINT8_C(212), UINT8_C(150), UINT8_C(243), UINT8_C( 38), UINT8_C( 25), UINT8_C(237), UINT8_C(238),
      UINT8_C( 55), UINT8_C( 80), UINT8_C(107), UINT8_C( 53), UINT8_C(139), UINT8_C(101), UINT8_C( 81), UINT8_C(  2),
      UINT8_C(111), UINT8_C(226), UINT8_C(244), UINT8_C(153), UINT8_C(216), UINT8_C(229), UINT8_C( 88), UINT8_C(178),
      UINT8_C(118), UINT8_C( 84), UINT8_C(  0), UINT8_C(171), UINT8_C( 84), UINT8_C(157), UINT8_C( 67), UINT8_C(179),
      UINT8_C(114), UINT8_C(217), UINT8_C(166), UINT8_C(152), UINT8_C(242), UINT8_C(147), UINT8_C(134), UINT8_C( 41),
      UINT8_C(228), UINT8_C(241), UINT8_C( 94), UINT8_C(111), UINT8_C( 86), UINT8_C(175), UINT8_C(113), UINT8_C(197),
      UINT8_C(146), UINT8_C(101), UINT8_C( 94), UINT8_C(106), UINT8_C( 74), UINT8_C(183), UINT8_C( 28), UINT8_C(193),
      UINT8_C( 11), UINT8_C( 28), UINT8_C(108), UINT8_C( 95), UINT8_C(186), UINT8_C(175), UINT8_C( 19), UINT8_C( 44),
      UINT8_C(137), UINT8_C(185), UINT8_C(196), UINT8_C(123), UINT8_C( 77), UINT8_C( 74), UINT8_C(165), UINT8_C( 49),
      UINT8_C( 60), UINT8_C(  3), UINT8_C(160), UINT8_C(146), UINT8_C(179), UINT8_C( 17), UINT8_C( 88), UINT8_C( 69),
      UINT8_C(118), UINT8_C(182), UINT8_C(175), UINT8_C(193), UINT8_C(109), UINT8_C(203), UINT8_C(130), UINT8_C(120),
      UINT8_C(231), UINT8_C(238), UINT8_C(216), UINT8_C(161), UINT8_C(157), UINT8_C(235), UINT8_C(205), UINT8_C( 38),
      UINT8_C(164), UINT8_C(145), UINT8_C(162), UINT8_C(241), UINT8_C(220), UINT8_C( 71), UINT8_C( 34), UINT8_C( 24),
      UINT8_C( 74), UINT8_C(194), UINT8_C(170), UINT8_C(253), UINT8_C(211), UINT8_C(  2), UINT8_C( 66), UINT8_C( 74),
      UINT8_C(185), UINT8_C(241), UINT8_C( 11), UINT8_C( 38), UINT8_C(188), UINT8_C(141), UINT8_C(159), UINT8_C(164),
      UINT8_C(123), UINT8_C(119), UINT8_C( 69), UINT8_C( 24), UINT8_C( 98), UINT8_C( 19), UINT8_C( 63), UINT8_C(  6),
      UINT8_C(164), UINT8_C(225), UINT8_C(248), UINT8_C(128), UINT8_C( 40), UINT8_C( 26), UINT8_C(152), UINT8_C(114),
      UINT8_C(221), UINT8_C( 67), UINT8_C(112), UINT8_C(176), UINT8_C( 69), UINT8_C(178), UINT8_C(250), UINT8_C(254),
      UINT8_C(164), UINT8_C(  5), UINT8_C( 37), UINT8_C( 96), UINT8_C(146), UINT8_C(196), UINT8_C(  4), UINT8_C( 13),
      UINT8_C( 59), UINT8_C( 74), UINT8_C( 38), UINT8_C(157), UINT8_C( 93), UINT8_C(101), UINT8_C(163), UINT8_C(  1),
      UINT8_C( 70), UINT8_C(155), UINT8_C(130), UINT8_C(110), UINT8_C(182), UINT8_C( 26), UINT8_C(224), UINT8_C(147),
      UINT8_C( 93), UINT8_C( 80), UINT8_C( 67), UINT8_C(163), UINT8_C(  3), UINT8_C( 62), UINT8_C(161), UINT8_C(167),
      UINT8_C( 67), UINT8_C(198), UINT8_C(  7), UINT8_C(214), UINT8_C(138), UINT8_C( 12), UINT8_C(227), UINT8_C(197),
      UINT8_C( 86), UINT8_C(  9), UINT8_C( 98), UINT8_C(179), UINT8_C(110), UINT8_C(  6), UINT8_C(180), UINT8_C(180),
      UINT8_C(161), UINT8_C( 54), UINT8_C( 34), UINT8_C( 87), UINT8_C( 81), UINT8_C(  3), UINT8_C(234), UINT8_C(174),
      UINT8_C( 83), UINT8_C( 46), UINT8_C( 81), UINT8_C( 86), UINT8_C(108), UINT8_C(243), UINT8_C(253), UINT8_C(175),
      UINT8_C(185), UINT8_C(  5), UINT8_C(133), UINT8_C( 68), UINT8_C( 17), UINT8_C(105), UINT8_C(  9), UINT8_C(103),
      UINT8_C(114), UINT8_C(108), UINT8_C( 26), UINT8_C(225), UINT8_C(114), UINT8_C(206), UINT8_C(149), UINT8_C( 19),
      UINT8_C(  5), UINT8_C(184), UINT8_C(107), UINT8_C( 86), UINT8_C(187), UINT8_C( 85), UINT8_C(  4), UINT8_C( 14),
      UINT8_C(131), UINT8_C( 86), UINT8_C(101), UINT8_C(239), UINT8_C( 73), UINT8_C( 98), UINT8_C(159), UINT8_C(  2),
      UINT8_C(103), UINT8_C( 36), UINT8_C( 70), UINT8_C(120), UINT8_C(141), UINT8_C( 80), UINT8_C(223), UINT8_C(  0),
      UINT8_C(188), UINT8_C(249), UINT8_C(225), UINT8_C( 46), UINT8_C(200), UINT8_C(118), UINT8_C( 65), UINT8_C(205),
      UINT8_C( 46), UINT8_C(172), UINT8_C( 35), UINT8_C(233), UINT8_C(  2), UINT8_C( 39), UINT8_C(248), UINT8_C(133),
      UINT8_C(125), UINT8_C( 93), UINT8_C(117), UINT8_C(198), UINT8_C(191), UINT8_C( 20), UINT8_C(201), UINT8_C( 39),
      UINT8_C( 56), UINT8_C( 15), UINT8_C(159), UINT8_C(198), UINT8_C( 95), UINT8_C(127), UINT8_C(198), UINT8_C( 27),
      UINT8_C(120), UINT8_C(167), UINT8_C( 73), UINT8_C( 64), UINT8_C( 29), UINT8_C(139), UINT8_C( 13), UINT8_C( 76),
      UINT8_C( 55), UINT8_C( 48), UINT8_C( 53), UINT8_C( 57), UINT8_C( 88), UINT8_C( 45), UINT8_C(191), UINT8_C(213),
      UINT8_C(138), UINT8_C( 52), UINT8_C(156), UINT8_C( 74), UINT8_C( 72), UINT8_C(101), UINT8_C(113), UINT8_C(128),
      UINT8_C(116), UINT8_C( 16), UINT8_C( 70), UINT8_C(212), UINT8_C(143), UINT8_C( 12), UINT8_C(239), UINT8_C(  8),
      UINT8_C(179), UINT8_C( 57), UINT8_C( 72), UINT8_C(209), UINT8_C(196), UINT8_C( 86), UINT8_C( 29), UINT8_C(251),
      UINT8_C(134), UINT8_C( 82), UINT8_C( 53), UINT8_C(222), UINT8_C(128), UINT8_C(244), UINT8_C(180), UINT8_C( 10),
      UINT8_C( 40), UINT8_C( 80), UINT8_C( 84), UINT8_C(112), UINT8_C(181), UINT8_C(197), UINT8_C(240), UINT8_C( 41),
      UINT8_C(214), UINT8_C( 55), UINT8_C(253), UINT8_C(101), UINT8_C( 67), UINT8_C(237), UINT8_C(109), UINT8_C(247),
      UINT8_C( 38), UINT8_C(182), UINT8_C(200), UINT8_C(234), UINT8_C( 12), UINT8_C(229), UINT8_C(229), UINT8_C(146),
      UINT8_C( 55), UINT8_C( 26), UINT8_C(113), UINT8_C(183), UINT8_C( 14), UINT8_C( 37), UINT8_C(194), UINT8_C( 54),
      UINT8_C(117), UINT8_C( 22), UINT8_C(166), UINT8_C( 42), UINT8_C(220), UINT8_C(151), UINT8_C( 83), UINT8_C(178),
      UINT8_C(206), UINT8_C( 81), UINT8_C( 23), UINT8_C( 17), UINT8_C( 62), UINT8_C(133), UINT8_C(  8), UINT8_C(100),
      UINT8_C( 59), UINT8_C(208), UINT8_C( 78), UINT8_C( 71), UINT8_C(181), UINT8_C( 51), UINT8_C(217), UINT8_C(237),
      UINT8_C( 78), UINT8_C( 74), UINT8_C(164), UINT8_C( 92), UINT8_C(111), UINT8_C(102), UINT8_C(147), UINT8_C(228),
      UINT8_C(125), UINT8_C( 57), UINT8_C( 14), UINT8_C( 89), UINT8_C(208), UINT8_C( 98), UINT8_C( 11), UINT8_C(158),
      UINT8_C(179), UINT8_C( 34), UINT8_C(176), UINT8_C(241), UINT8_C(167), UINT8_C(184), UINT8_C( 85), UINT8_C(226),
      UINT8_C(137), UINT8_C(163), UINT8_C( 41), UINT8_C( 62), UINT8_C(214), UINT8_C(  3), UINT8_C( 43), UINT8_C( 36),
      UINT8_C( 77), UINT8_C(208), UINT8_C(129), UINT8_C(189), UINT8_C( 54), UINT8_C( 20), UINT8_C(161), UINT8_C(179),
      UINT8_C( 77), UINT8_C(176), UINT8_C( 12), UINT8_C( 30), UINT8_C( 18), UINT8_C( 23), UINT8_C(188), UINT8_C(197),
      UINT8_C( 58), UINT8_C(108), UINT8_C(182), UINT8_C(225), UINT8_C( 37), UINT8_C( 11), UINT8_C(196), UINT8_C(174),
      UINT8_C(174), UINT8_C(237), UINT8_C(236), UINT8_C(132), UINT8_C(240), UINT8_C( 24), UINT8_C(169), UINT8_C( 62),
      UINT8_C(232), UINT8_C( 42), UINT8_C(251), UINT8_C( 30), UINT8_C( 62), UINT8_C(156), UINT8_C(210), UINT8_C(139),
      UINT8_C( 76), UINT8_C(222), UINT8_C(169), UINT8_C( 94), UINT8_C(246), UINT8_C(102), UINT8_C( 35), UINT8_C( 48),
      UINT8_C(210), UINT8_C(217), UINT8_C( 17), UINT8_C(247), UINT8_C(228), UINT8_C(213), UINT8_C(165), UINT8_C(146),
      UINT8_C(195), UINT8_C(146), UINT8_C( 23), UINT8_C(179), UINT8_C(170), UINT8_C(192), UINT8_C(241), UINT8_C(146),
      UINT8_C(234), UINT8_C(236), UINT8_C(176), UINT8_C( 40), UINT8_C(137), UINT8_C(130), UINT8_C(179), UINT8_C(213),
      UINT8_C( 97), UINT8_C( 93), UINT8_C( 52), UINT8_C( 87), UINT8_C(195), UINT8_C( 87), UINT8_C(135), UINT8_C(149),
      UINT8_C( 49), UINT8_C(152), UINT8_C(141), UINT8_C( 21), UINT8_C(110), UINT8_C( 50), UINT8_C(168), UINT8_C( 49),
      UINT8_C(196), UINT8_C(191), UINT8_C(228), UINT8_C(110), UINT8_C(127), UINT8_C(214), UINT8_C(  0), UINT8_C(105),
      UINT8_C(194), UINT8_C(177), UINT8_C(145), UINT8_C( 75), UINT8_C( 51), UINT8_C( 68), UINT8_C( 33), UINT8_C(148),
      UINT8_C(161), UINT8_C( 85), UINT8_C(235), UINT8_C(100), UINT8_C(172), UINT8_C(114), UINT8_C(250), UINT8_C(221),
      UINT8_C( 11), UINT8_C(135), UINT8_C(243), UINT8_C(121), UINT8_C(185), UINT8_C(155), UINT8_C(170), UINT8_C(126),
      UINT8_C( 90), UINT8_C(142), UINT8_C(236), UINT8_C(217), UINT8_C(100), UINT8_C(237), UINT8_C( 66), UINT8_C( 39),
      UINT8_C(158), UINT8_C(211), UINT8_C(114), UINT8_C(209), UINT8_C( 23), UINT8_C(147), UINT8_C(102), UINT8_C(185),
      UINT8_C(232), UINT8_C( 81), UINT8_C( 29), UINT8_C(149), UINT8_C(196), UINT8_C( 23), UINT8_C(114), UINT8_C(207),
      UINT8_C(158), UINT8_C(101), UINT8_C( 72), UINT8_C( 88), UINT8_C(  0), UINT8_C(242), UINT8_C(214), UINT8_C( 90),
      UINT8_C(128), UINT8_C(194), UINT8_C( 51), UINT8_C(229), UINT8_C(175), UINT8_C(117), UINT8_C( 12), UINT8_C( 77),
      UINT8_C( 72), UINT8_C(126), UINT8_C( 31), UINT8_C( 96), UINT8_C( 18), UINT8_C(133), UINT8_C( 25), UINT8_C(250),
      UINT8_C(214), UINT8_C( 54), UINT8_C(143), UINT8_C(154), UINT8_C( 78), UINT8_C(  2), UINT8_C(105), UINT8_C(236),
      UINT8_C(103), UINT8_C(177), UINT8_C( 68), UINT8_C(104), UINT8_C(163), UINT8_C( 26), UINT8_C(194), UINT8_C( 36),
      UINT8_C(221), UINT8_C(246), UINT8_C(  9), UINT8_C(140), UINT8_C(107), UINT8_C( 21), UINT8_C(218), UINT8_C(180),
      UINT8_C(147), UINT8_C(249), UINT8_C( 20), UINT8_C(165), UINT8_C(126), UINT8_C( 45), UINT8_C(160), UINT8_C( 84),
      UINT8_C( 99), UINT8_C( 47), UINT8_C(239), UINT8_C(177), UINT8_C( 49), UINT8_C( 88), UINT8_C(158), UINT8_C(153),
      UINT8_C( 10), UINT8_C(226), UINT8_C(  1), UINT8_C(173), UINT8_C(253), UINT8_C(195), UINT8_C(209), UINT8_C(218),
      UINT8_C(185), UINT8_C(218), UINT8_C(102), UINT8_C( 37), UINT8_C(239), UINT8_C( 64), UINT8_C(217), UINT8_C(131),
      UINT8_C( 57), UINT8_C(237), UINT8_C( 40), UINT8_C(183), UINT8_C( 26), UINT8_C(200), UINT8_C( 12), UINT8_C(125),
      UINT8_C(248), UINT8_C(251), UINT8_C( 47), UINT8_C( 41), UINT8_C( 83), UINT8_C(205), UINT8_C(194), UINT8_C( 93),
      UINT8_C(175), UINT8_C(195), UINT8_C( 11), UINT8_C(172), UINT8_C(135), UINT8_C(220), UINT8_C(134), UINT8_C( 64),
      UINT8_C(183), UINT8_C(237), UINT8_C(101), UINT8_C(166), UINT8_C( 45), UINT8_C( 62), UINT8_C( 41), UINT8_C(103),
      UINT8_C( 43), UINT8_C( 82), UINT8_C( 30), UINT8_C( 69), UINT8_C( 26), UINT8_C( 42), UINT8_C(195), UINT8_C( 18),
      UINT8_C( 37), UINT8_C(242), UINT8_C( 60), UINT8_C(121), UINT8_C(191), UINT8_C(254), UINT8_C(214), UINT8_C(110),
      UINT8_C(194), UINT8_C(225), UINT8_C( 27), UINT8_C( 73), UINT8_C(190), UINT8_C(161), UINT8_C(137), UINT8_C(117),
      UINT8_C(142), UINT8_C(239), UINT8_C( 27), UINT8_C(188), UINT8_C( 45) };
  static const uint8_t b[] =
    { UINT8_C( 98), UINT8_C(244), UINT8_C(110), UINT8_C( 97), UINT8_C(213), UINT8_C(239), UINT8_C( 33), UINT8_C(152),
      UINT8_C(139), UINT8_C( 43), UINT8_C( 24), UINT8_C(201), UINT8_C(190), UINT8_C( 14), UINT8_C(149), UINT8_C( 64),
      UINT8_C( 31), UINT8_C( 29), UINT8_C(239), UINT8_C(117), UINT8_C(200), UINT8_C(248), UINT8_C( 98), UINT8_C(180),
      UINT8_C(159), UINT8_C(  0), UINT8_C( 13), UINT8_C(167), UINT8_C( 99), UINT8_C(247), UINT8_C(  3), UINT8_C(197),
      UINT8_C(235), UINT8_C(114), UINT8_C( 38), UINT8_C(193), UINT8_C( 97), UINT8_C( 72), UINT8_C( 89), UINT8_C(237),
      UINT8_C(115), UINT8_C(113), UINT8_C(182), UINT8_C( 49), UINT8_C(127), UINT8_C( 75), UINT8_C(113), UINT8_C(158),
      UINT8_C(104), UINT8_C( 96), UINT8_C( 19), UINT8_C( 48), UINT8_C( 88), UINT8_C(117), UINT8_C(228), UINT8_C(247),
      UINT8_C(118), UINT8_C(241), UINT8_C(159), UINT8_C(217), UINT8_C(232), UINT8_C(162), UINT8_C(158), UINT8_C(212),
      UINT8_C( 20), UINT8_C(197), UINT8_C(149), UINT8_C(118), UINT8_C( 13), UINT8_C(238), UINT8_C( 99), UINT8_C(128),
      UINT8_C( 95), UINT8_C( 25), UINT8_C(177), UINT8_C(223), UINT8_C(100), UINT8_C( 34), UINT8_C(125), UINT8_C(204),
      UINT8_C(130), UINT8_C(145), UINT8_C(252), UINT8_C(219), UINT8_C(  6), UINT8_C(224), UINT8_C(210), UINT8_C(124),
      UINT8_C(210), UINT8_C(113), UINT8_C( 85), UINT8_C(186), UINT8_C( 20), UINT8_C(244), UINT8_C(142), UINT8_C( 40),
      UINT8_C(185), UINT8_C( 35), UINT8_C(158), UINT8_C(198), UINT8_C( 17), UINT8_C(  1), UINT8_C( 70), UINT8_C(113),
      UINT8_C( 26), UINT8_C(247), UINT8_C( 80), UINT8_C(126), UINT8_C( 25), UINT8_C(205), UINT8_C( 74), UINT8_C(155),
      UINT8_C( 94), UINT8_C( 70), UINT8_C(118), UINT8_C(101), UINT8_C( 39), UINT8_C( 73), UINT8_C(225), UINT8_C(249),
      UINT8_C(186), UINT8_C( 55), UINT8_C(179), UINT8_C(206), UINT8_C( 43), UINT8_C( 66), UINT8_C(247), UINT8_C(228),
      UINT8_C(101), UINT8_C(149), UINT8_C(170), UINT8_C(119), UINT8_C(151), UINT8_C(240), UINT8_C(232), UINT8_C(177),
      UINT8_C(231), UINT8_C( 56), UINT8_C( 48), UINT8_C(  0), UINT8_C(  5), UINT8_C(122), UINT8_C(155), UINT8_C(100),
      UINT8_C(193), UINT8_C( 18), UINT8_C(201), UINT8_C(232), UINT8_C( 91), UINT8_C(170), UINT8_C(225), UINT8_C( 21),
      UINT8_C(225), UINT8_C(148), UINT8_C(228), UINT8_C( 12), UINT8_C(214), UINT8_C(219), UINT8_C(240), UINT8_C( 60),
      UINT8_C(112), UINT8_C(154), UINT8_C(179), UINT8_C(  7), UINT8_C(138), UINT8_C(155), UINT8_C(185), UINT8_C(113),
      UINT8_C(211), UINT8_C(233), UINT8_C(113), UINT8_C(216), UINT8_C( 99), UINT8_C( 13), UINT8_C( 60), UINT8_C( 36),
      UINT8_C( 31), UINT8_C(  5), UINT8_C( 12), UINT8_C(122), UINT8_C(176), UINT8_C(237), UINT8_C(143), UINT8_C(145),
      UINT8_C(130), UINT8_C(115), UINT8_C(158), UINT8_C( 88), UINT8_C( 78), UINT8_C(142), UINT8_C(148), UINT8_C(191),
      UINT8_C( 41), UINT8_C( 71), UINT8_C(198), UINT8_C(179), UINT8_C(226), UINT8_C(127), UINT8_C( 37), UINT8_C(181),
      UINT8_C(104), UINT8_C(150), UINT8_C(142), UINT8_C(204), UINT8_C(163), UINT8_C(202), UINT8_C(240), UINT8_C(194),
      UINT8_C(208), UINT8_C(253), UINT8_C( 60), UINT8_C(128), UINT8_C(234), UINT8_C(204), UINT8_C( 17), UINT8_C(108),
      UINT8_C( 63), UINT8_C(175), UINT8_C(197), UINT8_C(142), UINT8_C( 62), UINT8_C( 89), UINT8_C( 77), UINT8_C(103),
      UINT8_C(161), UINT8_C( 19), UINT8_C( 26), UINT8_C(131), UINT8_C(147), UINT8_C( 63), UINT8_C( 57), UINT8_C(251),
      UINT8_C(214), UINT8_C(199), UINT8_C(199), UINT8_C(121), UINT8_C(145), UINT8_C(184), UINT8_C( 60), UINT8_C( 97),
      UINT8_C(181), UINT8_C(120), UINT8_C(225), UINT8_C(159), UINT8_C( 68), UINT8_C(243), UINT8_C( 12), UINT8_C(132),
      UINT8_C(162), UINT8_C(209), UINT8_C( 18), UINT8_C(224), UINT8_C( 42), UINT8_C( 95), UINT8_C( 71), UINT8_C(203),
      UINT8_C(114), UINT8_C( 98), UINT8_C( 79), UINT8_C(  5), UINT8_C(161), UINT8_C(136), UINT8_C(  1), UINT8_C(119),
      UINT8_C( 79), UINT8_C(200), UINT8_C(241), UINT8_C(224), UINT8_C(128), UINT8_C( 45), UINT8_C( 66), UINT8_C( 53),
      UINT8_C(165), UINT8_C( 35), UINT8_C(213), UINT8_C(234), UINT8_C( 22), UINT8_C(225), UINT8_C(110), UINT8_C(185),
      UINT8_C(178), UINT8_C(128), UINT8_C(153), UINT8_C(220), UINT8_C(223), UINT8_C(225), UINT8_C(168), UINT8_C( 81),
      UINT8_C( 67), UINT8_C(247), UINT8_C( 87), UINT8_C(228), UINT8_C(127), UINT8_C( 88), UINT8_C( 92), UINT8_C(206),
      UINT8_C( 32), UINT8_C( 77), UINT8_C(174), UINT8_C(161), UINT8_C(122), UINT8_C(240), UINT8_C(214), UINT8_C( 31),
      UINT8_C( 20), UINT8_C(171), UINT8_C(  9), UINT8_C( 42), UINT8_C(140), UINT8_C(119), UINT8_C(227), UINT8_C( 62),
      UINT8_C(247), UINT8_C(125), UINT8_C( 27), UINT8_C(214), UINT8_C( 94), UINT8_C(195), UINT8_C( 40), UINT8_C(161),
      UINT8_C(186), UINT8_C(127), UINT8_C(133), UINT8_C( 57), UINT8_C(215), UINT8_C(225), UINT8_C(  7), UINT8_C(247),
      UINT8_C( 46), UINT8_C(181), UINT8_C(152), UINT8_C(168), UINT8_C(166), UINT8_C(111), UINT8_C(200), UINT8_C(186),
      UINT8_C( 26), UINT8_C(209), UINT8_C(228), UINT8_C(167), UINT8_C( 73), UINT8_C(200), UINT8_C(229), UINT8_C( 64),
      UINT8_C( 69), UINT8_C(  0), UINT8_C( 23), UINT8_C(163), UINT8_C(195), UINT8_C( 63), UINT8_C( 68), UINT8_C(125),
      UINT8_C(190), UINT8_C(201), UINT8_C(182), UINT8_C(149), UINT8_C(171), UINT8_C(189), UINT8_C(140), UINT8_C(217),
      UINT8_C(115), UINT8_C( 37), UINT8_C(130), UINT8_C( 25), UINT8_C(148), UINT8_C( 74), UINT8_C(211), UINT8_C(174),
      UINT8_C( 27), UINT8_C(183), UINT8_C( 85), UINT8_C(100), UINT8_C(127), UINT8_C( 59), UINT8_C(165), UINT8_C(196),
      UINT8_C( 59), UINT8_C(188), UINT8_C(103),    UINT8_MAX, UINT8_C(251), UINT8_C(171), UINT8_C(124), UINT8_C(185),
      UINT8_C(117), UINT8_C( 51), UINT8_C( 78), UINT8_C( 32), UINT8_C(240), UINT8_C(218), UINT8_C(249), UINT8_C( 99),
         UINT8_MAX, UINT8_C(123), UINT8_C(124), UINT8_C(147), UINT8_C(197), UINT8_C( 79), UINT8_C( 66), UINT8_C(225),
      UINT8_C(  7), UINT8_C(151), UINT8_C( 69), UINT8_C(134), UINT8_C(210), UINT8_C(234), UINT8_C( 75), UINT8_C( 14),
      UINT8_C(166), UINT8_C(178), UINT8_C( 13), UINT8_C(161), UINT8_C( 94), UINT8_C(137), UINT8_C( 90), UINT8_C(211),
      UINT8_C(188), UINT8_C(168), UINT8_C(243), UINT8_C(173), UINT8_C(131), UINT8_C(236), UINT8_C( 16), UINT8_C(130),
      UINT8_C(104), UINT8_C(141), UINT8_C( 22), UINT8_C( 45), UINT8_C(220), UINT8_C( 88), UINT8_C( 14), UINT8_C(227),
      UINT8_C(239), UINT8_C( 84), UINT8_C(106), UINT8_C(194), UINT8_C( 62), UINT8_C(181), UINT8_C(208), UINT8_C(229),
      UINT8_C(103), UINT8_C(221), UINT8_C(134), UINT8_C(197), UINT8_C(102), UINT8_C(225), UINT8_C(152), UINT8_C( 35),
      UINT8_C(137), UINT8_C(139), UINT8_C(208), UINT8_C( 12), UINT8_C(120), UINT8_C(224), UINT8_C(143), UINT8_C(224),
      UINT8_C(109), UINT8_C(165), UINT8_C( 13), UINT8_C( 74), UINT8_C(253), UINT8_C( 28), UINT8_C( 45), UINT8_C(236),
      UINT8_C(112), UINT8_C(151), UINT8_C(174), UINT8_C(174), UINT8_C( 76), UINT8_C(126), UINT8_C(147), UINT8_C(180),
      UINT8_C( 91), UINT8_C( 26), UINT8_C(121), UINT8_C(194), UINT8_C(251), UINT8_C( 18), UINT8_C(229), UINT8_C(132),
      UINT8_C(157), UINT8_C(181), UINT8_C(145), UINT8_C( 21), UINT8_C(149), UINT8_C( 32), UINT8_C(245), UINT8_C(  3),
      UINT8_C(197), UINT8_C(  3), UINT8_C( 77), UINT8_C(194), UINT8_C( 31), UINT8_C(122), UINT8_C(174), UINT8_C(143),
      UINT8_C( 18), UINT8_C( 93), UINT8_C( 61), UINT8_C( 94), UINT8_C(219), UINT8_C(209), UINT8_C( 18), UINT8_C( 55),
      UINT8_C(235), UINT8_C(140), UINT8_C(249), UINT8_C(230), UINT8_C(158), UINT8_C(222), UINT8_C(106), UINT8_C( 59),
      UINT8_C(147), UINT8_C(251), UINT8_C( 81), UINT8_C( 40), UINT8_C( 27), UINT8_C( 70), UINT8_C( 43), UINT8_C(224),
      UINT8_C( 73), UINT8_C(120), UINT8_C(162), UINT8_C(104), UINT8_C(243), UINT8_C( 81), UINT8_C(247), UINT8_C(  5),
      UINT8_C(174), UINT8_C( 53), UINT8_C( 99), UINT8_C(137), UINT8_C(  6), UINT8_C(118), UINT8_C(192), UINT8_C(241),
      UINT8_C(  2), UINT8_C(185), UINT8_C(215), UINT8_C(160), UINT8_C(151), UINT8_C( 65), UINT8_C(219), UINT8_C( 42),
      UINT8_C( 61), UINT8_C( 44), UINT8_C( 83), UINT8_C( 88), UINT8_C(115), UINT8_C(126), UINT8_C( 57), UINT8_C(188),
      UINT8_C(247), UINT8_C(219), UINT8_C( 37), UINT8_C(234), UINT8_C( 44), UINT8_C( 28), UINT8_C(239), UINT8_C(218),
      UINT8_C( 81), UINT8_C( 82), UINT8_C(100), UINT8_C( 87), UINT8_C(200), UINT8_C( 36), UINT8_C( 72), UINT8_C(202),
      UINT8_C(222), UINT8_C( 31), UINT8_C(106), UINT8_C(117), UINT8_C( 97), UINT8_C( 70), UINT8_C(160), UINT8_C(158),
      UINT8_C(114), UINT8_C(243), UINT8_C(246), UINT8_C(229), UINT8_C(113), UINT8_C( 47), UINT8_C(162), UINT8_C(104),
      UINT8_C( 11), UINT8_C(199), UINT8_C( 82), UINT8_C( 55), UINT8_C(227), UINT8_C( 65), UINT8_C( 18), UINT8_C( 53),
      UINT8_C(148), UINT8_C(118), UINT8_C(140), UINT8_C( 92), UINT8_C(154), UINT8_C(213), UINT8_C( 39), UINT8_C(120),
      UINT8_C(244), UINT8_C(145), UINT8_C(238), UINT8_C( 85), UINT8_C(215), UINT8_C(142), UINT8_C(243), UINT8_C( 74),
      UINT8_C(129), UINT8_C(234), UINT8_C( 47), UINT8_C(242), UINT8_C( 25), UINT8_C(209), UINT8_C( 91), UINT8_C( 36),
      UINT8_C(152), UINT8_C(173), UINT8_C( 92), UINT8_C(124), UINT8_C(239), UINT8_C(110), UINT8_C(177), UINT8_C(131),
      UINT8_C(228), UINT8_C( 61), UINT8_C(223), UINT8_C(126), UINT8_C( 18), UINT8_C(  6), UINT8_C(247), UINT8_C(  7),
      UINT8_C(152), UINT8_C(229), UINT8_C( 92), UINT8_C(111), UINT8_C(115), UINT8_C( 80), UINT8_C(185), UINT8_C(244),
      UINT8_C( 58), UINT8_C(233), UINT8_C(230), UINT8_C( 83), UINT8_C(186), UINT8_C( 65), UINT8_C(120), UINT8_C( 83),
      UINT8_C(239), UINT8_C(212), UINT8_C(207), UINT8_C(222), UINT8_C( 66), UINT8_C(128), UINT8_C( 97), UINT8_C( 38),
      UINT8_C(189), UINT8_C( 64), UINT8_C(164), UINT8_C(208), UINT8_C( 71), UINT8_C(155), UINT8_C(215), UINT8_C(223),
      UINT8_C(128), UINT8_C( 51), UINT8_C( 78), UINT8_C(243), UINT8_C(131), UINT8_C(  8), UINT8_C(231), UINT8_C(189),
      UINT8_C(241), UINT8_C(206), UINT8_C( 17), UINT8_C(171), UINT8_C( 15), UINT8_C(137), UINT8_C(254), UINT8_C(254),
      UINT8_C( 93), UINT8_C(205), UINT8_C(220), UINT8_C(159), UINT8_C( 77), UINT8_C( 61), UINT8_C(197), UINT8_C( 11),
      UINT8_C(126), UINT8_C(105), UINT8_C(219), UINT8_C(197), UINT8_C(  5), UINT8_C(178), UINT8_C(164), UINT8_C(133),
      UINT8_C(229), UINT8_C(242), UINT8_C(121), UINT8_C(105), UINT8_C(250), UINT8_C( 96), UINT8_C( 38), UINT8_C(235),
      UINT8_C( 46), UINT8_C( 55), UINT8_C(151), UINT8_C( 62), UINT8_C(192), UINT8_C(149), UINT8_C( 60), UINT8_C( 29),
      UINT8_C( 99), UINT8_C( 25), UINT8_C(188), UINT8_C(176), UINT8_C( 86), UINT8_C(129), UINT8_C(187), UINT8_C(212),
      UINT8_C(235), UINT8_C(150), UINT8_C(153), UINT8_C(240), UINT8_C( 72), UINT8_C( 61), UINT8_C(117), UINT8_C( 46),
      UINT8_C( 48), UINT8_C(238), UINT8_C(151), UINT8_C( 42), UINT8_C( 79), UINT8_C(189), UINT8_C( 22), UINT8_C(125),
      UINT8_C(245), UINT8_C(173), UINT8_C(187), UINT8_C(181), UINT8_C( 66), UINT8_C(248), UINT8_C(211), UINT8_C(165),
      UINT8_C( 17), UINT8_C(143), UINT8_C( 86), UINT8_C(103), UINT8_C( 17), UINT8_C( 17), UINT8_C( 60), UINT8_C(252),
      UINT8_C(168), UINT8_C(213), UINT8_C(236), UINT8_C(240), UINT8_C( 19), UINT8_C( 97), UINT8_C( 30), UINT8_C( 67),
      UINT8_C( 80), UINT8_C(181), UINT8_C(109), UINT8_C(159), UINT8_C(115), UINT8_C(131), UINT8_C( 28), UINT8_C(104),
      UINT8_C( 48), UINT8_C(216), UINT8_C( 29), UINT8_C(115), UINT8_C(208), UINT8_C(240), UINT8_C( 24), UINT8_C(225),
      UINT8_C(128), UINT8_C(110), UINT8_C( 72), UINT8_C(145), UINT8_C(128), UINT8_C(132), UINT8_C(141), UINT8_C( 40),
      UINT8_C( 90), UINT8_C(121), UINT8_C( 24), UINT8_C(109), UINT8_C(218), UINT8_C( 55), UINT8_C(176), UINT8_C( 42),
      UINT8_C(236), UINT8_C( 29), UINT8_C(201), UINT8_C( 95), UINT8_C(161), UINT8_C(230), UINT8_C(199), UINT8_C(209),
      UINT8_C(190), UINT8_C(229), UINT8_C( 68), UINT8_C(142), UINT8_C(213), UINT8_C( 93), UINT8_C(111), UINT8_C( 85),
      UINT8_C(203), UINT8_C(183), UINT8_C(230), UINT8_C( 75), UINT8_C( 60), UINT8_C(115), UINT8_C(115), UINT8_C(150),
      UINT8_C(236), UINT8_C(140), UINT8_C(  3), UINT8_C(199), UINT8_C(195), UINT8_C(179), UINT8_C(241), UINT8_C(175),
      UINT8_C(208), UINT8_C(187), UINT8_C( 15), UINT8_C(113), UINT8_C(161), UINT8_C(214), UINT8_C( 67), UINT8_C( 95),
      UINT8_C(187), UINT8_C(135), UINT8_C(237), UINT8_C(145), UINT8_C(228), UINT8_C( 92), UINT8_C(230), UINT8_C(176),
      UINT8_C( 19), UINT8_C(205), UINT8_C(251), UINT8_C( 79), UINT8_C( 64), UINT8_C(111), UINT8_C(229), UINT8_C( 45),
      UINT8_C(251), UINT8_C(232), UINT8_C(244), UINT8_C(190), UINT8_C(155), UINT8_C(229), UINT8_C(109), UINT8_C(108),
      UINT8_C(160), UINT8_C(124), UINT8_C(221), UINT8_C( 65), UINT8_C( 83), UINT8_C( 32), UINT8_C(160), UINT8_C( 14),
      UINT8_C(168), UINT8_C(141), UINT8_C(159), UINT8_C(140), UINT8_C(233), UINT8_C(134), UINT8_C( 60), UINT8_C(253),
      UINT8_C( 83), UINT8_C( 56), UINT8_C( 76), UINT8_C(147), UINT8_C(167), UINT8_C( 50), UINT8_C(192), UINT8_C(162),
      UINT8_C( 26), UINT8_C(180), UINT8_C( 96), UINT8_C(182), UINT8_C(154), UINT8_C(205), UINT8_C( 34), UINT8_C( 58),
      UINT8_C( 74),    UINT8_MAX, UINT8_C(124), UINT8_C(157), UINT8_C( 32), UINT8_C( 28), UINT8_C(171), UINT8_C(200),
      UINT8_C(170), UINT8_C( 75), UINT8_C( 84), UINT8_C(147), UINT8_C(209), UINT8_C(145), UINT8_C(144), UINT8_C( 36),
      UINT8_C(201), UINT8_C(221), UINT8_C(183), UINT8_C(112), UINT8_C( 15), UINT8_C(120), UINT8_C( 18), UINT8_C( 41),
      UINT8_C( 44), UINT8_C(114), UINT8_C(223), UINT8_C(198), UINT8_C( 63), UINT8_C(  1), UINT8_C(  1), UINT8_C(137),
      UINT8_C(  1), UINT8_C(125), UINT8_C( 38), UINT8_C( 33), UINT8_C(153), UINT8_C(210), UINT8_C(233), UINT8_C( 67),
      UINT8_C( 29), UINT8_C( 61), UINT8_C(215), UINT8_C(238), UINT8_C(206), UINT8_C(103), UINT8_C( 18), UINT8_C(151),
      UINT8_C( 68), UINT8_C(201), UINT8_C(  7), UINT8_C( 83), UINT8_C( 65), UINT8_C( 25), UINT8_C(125), UINT8_C(110),
      UINT8_C(139), UINT8_C( 92), UINT8_C( 52), UINT8_C(203), UINT8_C( 94), UINT8_C( 53), UINT8_C( 84), UINT8_C( 95),
      UINT8_C(178), UINT8_C(123), UINT8_C(128), UINT8_C( 76), UINT8_C( 77), UINT8_C(105), UINT8_C(143), UINT8_C(106),
      UINT8_C(166), UINT8_C(102), UINT8_C( 88), UINT8_C(117), UINT8_C(206), UINT8_C(106), UINT8_C( 12), UINT8_C( 18),
      UINT8_C( 51), UINT8_C( 20), UINT8_C(102), UINT8_C(117), UINT8_C( 45), UINT8_C(227), UINT8_C(227), UINT8_C(185),
      UINT8_C( 63), UINT8_C( 23), UINT8_C(132), UINT8_C(157), UINT8_C( 77) };
  static const uint8_t e[] =
    { UINT8_C(127), UINT8_C(227), UINT8_C(110), UINT8_C( 97), UINT8_C(213), UINT8_C( 20), UINT8_C( 33), UINT8_C(201),
      UINT8_C(139), UINT8_C( 43), UINT8_C(191), UINT8_C( 77), UINT8_C(190), UINT8_C(217), UINT8_C(149), UINT8_C(  7),
      UINT8_C(226), UINT8_C( 29), UINT8_C(239), UINT8_C(117), UINT8_C(200), UINT8_C(178), UINT8_C( 98), UINT8_C(131),
      UINT8_C(168), UINT8_C(221), UINT8_C( 13), UINT8_C(202), UINT8_C( 99), UINT8_C(247), UINT8_C( 81), UINT8_C(205),
      UINT8_C(235), UINT8_C(114), UINT8_C(  6), UINT8_C(193), UINT8_C( 97), UINT8_C( 72), UINT8_C( 89), UINT8_C(237),
      UINT8_C( 51), UINT8_C(127), UINT8_C(182), UINT8_C(248), UINT8_C(127), UINT8_C( 81),    UINT8_MAX, UINT8_C(158),
      UINT8_C( 73), UINT8_C(192), UINT8_C(126), UINT8_C( 80), UINT8_C( 88), UINT8_C(216), UINT8_C(211), UINT8_C(247),
      UINT8_C(118), UINT8_C(241), UINT8_C(228), UINT8_C(217), UINT8_C(232), UINT8_C( 53), UINT8_C(158), UINT8_C(212),
      UINT8_C( 20), UINT8_C(197), UINT8_C( 10), UINT8_C(118), UINT8_C( 13), UINT8_C(202), UINT8_C( 99), UINT8_C(128),
      UINT8_C( 74), UINT8_C( 25), UINT8_C(177), UINT8_C(163), UINT8_C( 78), UINT8_C(211), UINT8_C(222), UINT8_C(151),
      UINT8_C(130), UINT8_C(145), UINT8_C(252), UINT8_C(219), UINT8_C(  6), UINT8_C(224), UINT8_C( 32), UINT8_C(124),
      UINT8_C(210), UINT8_C(113), UINT8_C(238), UINT8_C( 66), UINT8_C( 20), UINT8_C(192), UINT8_C(142), UINT8_C( 40),
      UINT8_C(152), UINT8_C( 97), UINT8_C(158), UINT8_C(198), UINT8_C( 43), UINT8_C(  1), UINT8_C( 70), UINT8_C(113),
      UINT8_C(170), UINT8_C(247), UINT8_C( 80), UINT8_C(248), UINT8_C( 25), UINT8_C(247), UINT8_C( 74), UINT8_C(155),
      UINT8_C( 94), UINT8_C(120), UINT8_C( 93), UINT8_C(101), UINT8_C( 51), UINT8_C( 73), UINT8_C(115), UINT8_C(227),
      UINT8_C(186), UINT8_C( 55), UINT8_C( 38), UINT8_C(206), UINT8_C( 43), UINT8_C(124), UINT8_C(247), UINT8_C(185),
      UINT8_C(101), UINT8_C(149), UINT8_C(170), UINT8_C(119), UINT8_C( 10), UINT8_C(240), UINT8_C(232), UINT8_C(177),
      UINT8_C(  6), UINT8_C(151), UINT8_C( 48), UINT8_C(201), UINT8_C(  5), UINT8_C(122), UINT8_C(155), UINT8_C(100),
      UINT8_C(193), UINT8_C(125), UINT8_C(106), UINT8_C(232), UINT8_C( 91), UINT8_C(170), UINT8_C(203), UINT8_C( 21),
      UINT8_C(225), UINT8_C(148), UINT8_C( 58), UINT8_C( 12), UINT8_C(110), UINT8_C(219), UINT8_C(240), UINT8_C( 60),
      UINT8_C( 34), UINT8_C(154), UINT8_C(179), UINT8_C( 44), UINT8_C( 41), UINT8_C(211), UINT8_C(185), UINT8_C( 47),
      UINT8_C(211), UINT8_C(233), UINT8_C(249), UINT8_C(248), UINT8_C( 99), UINT8_C( 13), UINT8_C( 60), UINT8_C( 36),
      UINT8_C(151), UINT8_C( 67), UINT8_C( 12), UINT8_C(146), UINT8_C(176), UINT8_C(237), UINT8_C(143), UINT8_C( 95),
      UINT8_C( 34), UINT8_C(115), UINT8_C(158), UINT8_C( 88), UINT8_C( 15), UINT8_C(142), UINT8_C(220), UINT8_C( 49),
      UINT8_C(236), UINT8_C( 71), UINT8_C(198), UINT8_C( 21), UINT8_C(226), UINT8_C(127), UINT8_C( 69), UINT8_C(109),
      UINT8_C(104), UINT8_C(150), UINT8_C(142), UINT8_C(146), UINT8_C(163), UINT8_C( 63), UINT8_C(240), UINT8_C(194),
      UINT8_C(130), UINT8_C(117), UINT8_C( 60), UINT8_C(163), UINT8_C(166), UINT8_C(144), UINT8_C( 17), UINT8_C(108),
      UINT8_C( 63), UINT8_C(175), UINT8_C( 89), UINT8_C(233), UINT8_C(153), UINT8_C( 89), UINT8_C( 77), UINT8_C(133),
      UINT8_C(102), UINT8_C(119), UINT8_C( 26), UINT8_C(105), UINT8_C(180), UINT8_C( 63), UINT8_C( 57), UINT8_C(251),
      UINT8_C(214), UINT8_C( 60), UINT8_C(199), UINT8_C(117), UINT8_C(145), UINT8_C(184), UINT8_C( 60), UINT8_C( 97),
      UINT8_C(149), UINT8_C(228), UINT8_C(161), UINT8_C( 60), UINT8_C( 68), UINT8_C(243), UINT8_C( 12), UINT8_C(132),
      UINT8_C(100), UINT8_C( 94), UINT8_C( 18), UINT8_C(253), UINT8_C( 42), UINT8_C( 95), UINT8_C( 71), UINT8_C(250),
      UINT8_C(200), UINT8_C( 30), UINT8_C( 79), UINT8_C(124), UINT8_C(254), UINT8_C( 58), UINT8_C(  1), UINT8_C(119),
      UINT8_C( 79), UINT8_C(200), UINT8_C(241), UINT8_C(242), UINT8_C( 42), UINT8_C( 45), UINT8_C(240), UINT8_C(191),
      UINT8_C(218), UINT8_C(145), UINT8_C(213), UINT8_C(234), UINT8_C( 52), UINT8_C(225), UINT8_C(110), UINT8_C(152),
      UINT8_C(178), UINT8_C(128), UINT8_C(153), UINT8_C(220), UINT8_C( 38), UINT8_C( 25), UINT8_C(168), UINT8_C(238),
      UINT8_C( 67), UINT8_C(247), UINT8_C(107), UINT8_C(228), UINT8_C(127), UINT8_C(101), UINT8_C( 92), UINT8_C(  2),
      UINT8_C( 32), UINT8_C(226), UINT8_C(174), UINT8_C(153), UINT8_C(216), UINT8_C(240), UINT8_C(214), UINT8_C(178),
      UINT8_C(118), UINT8_C( 84), UINT8_C(  0), UINT8_C(171), UINT8_C(140), UINT8_C(157), UINT8_C( 67), UINT8_C( 62),
      UINT8_C(247), UINT8_C(217), UINT8_C(166), UINT8_C(214), UINT8_C( 94), UINT8_C(147), UINT8_C(134), UINT8_C( 41),
      UINT8_C(186), UINT8_C(127), UINT8_C(133), UINT8_C( 57), UINT8_C(215), UINT8_C(175), UINT8_C(113), UINT8_C(247),
      UINT8_C( 46), UINT8_C(181), UINT8_C(152), UINT8_C(106), UINT8_C( 74), UINT8_C(111), UINT8_C(200), UINT8_C(193),
      UINT8_C( 26), UINT8_C(209), UINT8_C(108), UINT8_C(167), UINT8_C( 73), UINT8_C(200), UINT8_C( 19), UINT8_C( 64),
      UINT8_C(137), UINT8_C(  0), UINT8_C(196), UINT8_C(163), UINT8_C( 77), UINT8_C( 63), UINT8_C( 68), UINT8_C( 49),
      UINT8_C( 60), UINT8_C(201), UINT8_C(182), UINT8_C(146), UINT8_C(179), UINT8_C(189), UINT8_C(140), UINT8_C( 69),
      UINT8_C(118), UINT8_C( 37), UINT8_C(175), UINT8_C( 25), UINT8_C(109), UINT8_C( 74), UINT8_C(211), UINT8_C(120),
      UINT8_C( 27), UINT8_C(238), UINT8_C( 85), UINT8_C(100), UINT8_C(157), UINT8_C(235), UINT8_C(205), UINT8_C(196),
      UINT8_C( 59), UINT8_C(188), UINT8_C(162), UINT8_C(241), UINT8_C(220), UINT8_C( 71), UINT8_C( 34), UINT8_C(185),
      UINT8_C( 74), UINT8_C( 51), UINT8_C( 78), UINT8_C(253), UINT8_C(240), UINT8_C(218), UINT8_C(249), UINT8_C( 99),
      UINT8_C(185), UINT8_C(241), UINT8_C( 11), UINT8_C(147), UINT8_C(188), UINT8_C(141), UINT8_C(159), UINT8_C(164),
      UINT8_C(  7), UINT8_C(119), UINT8_C( 69), UINT8_C( 24), UINT8_C( 98), UINT8_C(234), UINT8_C( 75), UINT8_C(  6),
      UINT8_C(164), UINT8_C(178), UINT8_C(248), UINT8_C(161), UINT8_C( 40), UINT8_C( 26), UINT8_C(152), UINT8_C(114),
      UINT8_C(221), UINT8_C( 67), UINT8_C(243), UINT8_C(173), UINT8_C(131), UINT8_C(236), UINT8_C( 16), UINT8_C(254),
      UINT8_C(104), UINT8_C(  5), UINT8_C( 37), UINT8_C( 45), UINT8_C(146), UINT8_C(196), UINT8_C( 14), UINT8_C( 13),
      UINT8_C( 59), UINT8_C( 84), UINT8_C( 38), UINT8_C(194), UINT8_C( 93), UINT8_C(181), UINT8_C(208), UINT8_C(229),
      UINT8_C(103), UINT8_C(155), UINT8_C(134), UINT8_C(110), UINT8_C(102), UINT8_C( 26), UINT8_C(224), UINT8_C( 35),
      UINT8_C( 93), UINT8_C( 80), UINT8_C(208), UINT8_C( 12), UINT8_C(120), UINT8_C( 62), UINT8_C(143), UINT8_C(224),
      UINT8_C( 67), UINT8_C(165), UINT8_C( 13), UINT8_C( 74), UINT8_C(138), UINT8_C( 28), UINT8_C( 45), UINT8_C(197),
      UINT8_C( 86), UINT8_C(  9), UINT8_C(174), UINT8_C(174), UINT8_C( 76), UINT8_C(126), UINT8_C(147), UINT8_C(180),
      UINT8_C( 91), UINT8_C( 54), UINT8_C(121), UINT8_C( 87), UINT8_C( 81), UINT8_C(  3), UINT8_C(234), UINT8_C(174),
      UINT8_C(157), UINT8_C(181), UINT8_C( 81), UINT8_C( 21), UINT8_C(108), UINT8_C(243), UINT8_C(253), UINT8_C(  3),
      UINT8_C(185), UINT8_C(  3), UINT8_C(133), UINT8_C( 68), UINT8_C( 17), UINT8_C(105), UINT8_C(174), UINT8_C(143),
      UINT8_C(114), UINT8_C(108), UINT8_C( 26), UINT8_C(225), UINT8_C(114), UINT8_C(206), UINT8_C(149), UINT8_C( 55),
      UINT8_C(235), UINT8_C(184), UINT8_C(107), UINT8_C(230), UINT8_C(158), UINT8_C( 85), UINT8_C(  4), UINT8_C( 14),
      UINT8_C(131), UINT8_C(251), UINT8_C(101), UINT8_C(239), UINT8_C( 27), UINT8_C( 98), UINT8_C( 43), UINT8_C(224),
      UINT8_C(103), UINT8_C( 36), UINT8_C( 70), UINT8_C(104), UINT8_C(243), UINT8_C( 81), UINT8_C(223), UINT8_C(  5),
      UINT8_C(188), UINT8_C( 53), UINT8_C(225), UINT8_C( 46), UINT8_C(200), UINT8_C(118), UINT8_C( 65), UINT8_C(241),
      UINT8_C(  2), UINT8_C(172), UINT8_C(215), UINT8_C(160), UINT8_C(151), UINT8_C( 65), UINT8_C(219), UINT8_C( 42),
      UINT8_C( 61), UINT8_C( 93), UINT8_C(117), UINT8_C(198), UINT8_C(191), UINT8_C(126), UINT8_C(201), UINT8_C( 39),
      UINT8_C( 56), UINT8_C( 15), UINT8_C(159), UINT8_C(234), UINT8_C( 44), UINT8_C(127), UINT8_C(239), UINT8_C( 27),
      UINT8_C(120), UINT8_C( 82), UINT8_C( 73), UINT8_C( 64), UINT8_C(200), UINT8_C(139), UINT8_C( 72), UINT8_C( 76),
      UINT8_C(222), UINT8_C( 31), UINT8_C(106), UINT8_C( 57), UINT8_C( 88), UINT8_C( 70), UINT8_C(191), UINT8_C(158),
      UINT8_C(114), UINT8_C( 52), UINT8_C(156), UINT8_C( 74), UINT8_C( 72), UINT8_C(101), UINT8_C(162), UINT8_C(128),
      UINT8_C( 11), UINT8_C(199), UINT8_C( 70), UINT8_C( 55), UINT8_C(143), UINT8_C( 65), UINT8_C( 18), UINT8_C( 53),
      UINT8_C(148), UINT8_C(118), UINT8_C( 72), UINT8_C(209), UINT8_C(196), UINT8_C( 86), UINT8_C( 39), UINT8_C(251),
      UINT8_C(244), UINT8_C(145), UINT8_C(238), UINT8_C(222), UINT8_C(215), UINT8_C(142), UINT8_C(180), UINT8_C( 74),
      UINT8_C( 40), UINT8_C( 80), UINT8_C( 47), UINT8_C(242), UINT8_C( 25), UINT8_C(209), UINT8_C(240), UINT8_C( 36),
      UINT8_C(214), UINT8_C( 55), UINT8_C(253), UINT8_C(124), UINT8_C( 67), UINT8_C(110), UINT8_C(109), UINT8_C(131),
      UINT8_C(228), UINT8_C( 61), UINT8_C(200), UINT8_C(234), UINT8_C( 18), UINT8_C(  6), UINT8_C(229), UINT8_C(146),
      UINT8_C( 55), UINT8_C( 26), UINT8_C(113), UINT8_C(183), UINT8_C( 14), UINT8_C( 37), UINT8_C(185), UINT8_C( 54),
      UINT8_C( 58), UINT8_C( 22), UINT8_C(166), UINT8_C( 42), UINT8_C(220), UINT8_C(151), UINT8_C(120), UINT8_C(178),
      UINT8_C(239), UINT8_C(212), UINT8_C( 23), UINT8_C(222), UINT8_C( 66), UINT8_C(128), UINT8_C( 97), UINT8_C( 38),
      UINT8_C( 59), UINT8_C( 64), UINT8_C(164), UINT8_C(208), UINT8_C( 71), UINT8_C( 51), UINT8_C(215), UINT8_C(237),
      UINT8_C( 78), UINT8_C( 74), UINT8_C(164), UINT8_C( 92), UINT8_C(111), UINT8_C(  8), UINT8_C(231), UINT8_C(189),
      UINT8_C(125), UINT8_C(206), UINT8_C( 14), UINT8_C(171), UINT8_C(208), UINT8_C(137), UINT8_C( 11), UINT8_C(158),
      UINT8_C( 93), UINT8_C( 34), UINT8_C(176), UINT8_C(159), UINT8_C( 77), UINT8_C( 61), UINT8_C( 85), UINT8_C(226),
      UINT8_C(126), UINT8_C(163), UINT8_C(219), UINT8_C( 62), UINT8_C(214), UINT8_C(178), UINT8_C(164), UINT8_C( 36),
      UINT8_C(229), UINT8_C(208), UINT8_C(129), UINT8_C(189), UINT8_C( 54), UINT8_C( 20), UINT8_C( 38), UINT8_C(179),
      UINT8_C( 77), UINT8_C(176), UINT8_C( 12), UINT8_C( 30), UINT8_C( 18), UINT8_C( 23), UINT8_C(188), UINT8_C(197),
      UINT8_C( 58), UINT8_C(108), UINT8_C(188), UINT8_C(225), UINT8_C( 37), UINT8_C( 11), UINT8_C(196), UINT8_C(212),
      UINT8_C(174), UINT8_C(237), UINT8_C(236), UINT8_C(132), UINT8_C(240), UINT8_C( 24), UINT8_C(169), UINT8_C( 46),
      UINT8_C(232), UINT8_C(238), UINT8_C(251), UINT8_C( 30), UINT8_C( 62), UINT8_C(189), UINT8_C( 22), UINT8_C(139),
      UINT8_C( 76), UINT8_C(173), UINT8_C(169), UINT8_C( 94), UINT8_C( 66), UINT8_C(248), UINT8_C( 35), UINT8_C( 48),
      UINT8_C(210), UINT8_C(143), UINT8_C( 86), UINT8_C(247), UINT8_C( 17), UINT8_C( 17), UINT8_C(165), UINT8_C(252),
      UINT8_C(195), UINT8_C(213), UINT8_C( 23), UINT8_C(179), UINT8_C( 19), UINT8_C( 97), UINT8_C(241), UINT8_C(146),
      UINT8_C(234), UINT8_C(236), UINT8_C(176), UINT8_C( 40), UINT8_C(137), UINT8_C(130), UINT8_C( 28), UINT8_C(213),
      UINT8_C( 48), UINT8_C(216), UINT8_C( 52), UINT8_C(115), UINT8_C(208), UINT8_C( 87), UINT8_C( 24), UINT8_C(225),
      UINT8_C( 49), UINT8_C(110), UINT8_C( 72), UINT8_C( 21), UINT8_C(110), UINT8_C( 50), UINT8_C(168), UINT8_C( 40),
      UINT8_C( 90), UINT8_C(191), UINT8_C(228), UINT8_C(109), UINT8_C(218), UINT8_C(214), UINT8_C(176), UINT8_C(105),
      UINT8_C(236), UINT8_C(177), UINT8_C(201), UINT8_C( 95), UINT8_C( 51), UINT8_C( 68), UINT8_C( 33), UINT8_C(148),
      UINT8_C(161), UINT8_C( 85), UINT8_C( 68), UINT8_C(142), UINT8_C(213), UINT8_C( 93), UINT8_C(250), UINT8_C(221),
      UINT8_C( 11), UINT8_C(135), UINT8_C(243), UINT8_C( 75), UINT8_C(185), UINT8_C(155), UINT8_C(115), UINT8_C(126),
      UINT8_C(236), UINT8_C(140), UINT8_C(236), UINT8_C(199), UINT8_C(100), UINT8_C(179), UINT8_C(241), UINT8_C(175),
      UINT8_C(158), UINT8_C(187), UINT8_C( 15), UINT8_C(113), UINT8_C( 23), UINT8_C(214), UINT8_C( 67), UINT8_C(185),
      UINT8_C(232), UINT8_C(135), UINT8_C(237), UINT8_C(145), UINT8_C(228), UINT8_C( 23), UINT8_C(230), UINT8_C(207),
      UINT8_C(158), UINT8_C(101), UINT8_C( 72), UINT8_C( 79), UINT8_C( 64), UINT8_C(111), UINT8_C(229), UINT8_C( 90),
      UINT8_C(251), UINT8_C(232), UINT8_C(244), UINT8_C(190), UINT8_C(155), UINT8_C(229), UINT8_C(109), UINT8_C(108),
      UINT8_C(160), UINT8_C(126), UINT8_C(221), UINT8_C( 65), UINT8_C( 83), UINT8_C( 32), UINT8_C(160), UINT8_C(250),
      UINT8_C(214), UINT8_C(141), UINT8_C(159), UINT8_C(154), UINT8_C(233), UINT8_C(134), UINT8_C( 60), UINT8_C(253),
      UINT8_C( 83), UINT8_C( 56), UINT8_C( 68), UINT8_C(104), UINT8_C(167), UINT8_C( 26), UINT8_C(192), UINT8_C(162),
      UINT8_C( 26), UINT8_C(246), UINT8_C( 96), UINT8_C(182), UINT8_C(107), UINT8_C( 21), UINT8_C(218), UINT8_C( 58),
      UINT8_C( 74), UINT8_C(249), UINT8_C( 20), UINT8_C(157), UINT8_C( 32), UINT8_C( 45), UINT8_C(171), UINT8_C( 84),
      UINT8_C(170), UINT8_C( 47), UINT8_C( 84), UINT8_C(177), UINT8_C( 49), UINT8_C( 88), UINT8_C(158), UINT8_C(153),
      UINT8_C( 10), UINT8_C(221), UINT8_C(  1), UINT8_C(173), UINT8_C( 15), UINT8_C(120), UINT8_C( 18), UINT8_C(218),
      UINT8_C(185), UINT8_C(218), UINT8_C(223), UINT8_C(198), UINT8_C( 63), UINT8_C( 64), UINT8_C(217), UINT8_C(131),
      UINT8_C(  1), UINT8_C(125), UINT8_C( 40), UINT8_C(183), UINT8_C(153), UINT8_C(210), UINT8_C( 12), UINT8_C( 67),
      UINT8_C(248), UINT8_C( 61), UINT8_C(215), UINT8_C( 41), UINT8_C( 83), UINT8_C(205), UINT8_C(194), UINT8_C( 93),
      UINT8_C( 68), UINT8_C(201), UINT8_C( 11), UINT8_C(172), UINT8_C( 65), UINT8_C(220), UINT8_C(125), UINT8_C( 64),
      UINT8_C(183), UINT8_C( 92), UINT8_C( 52), UINT8_C(166), UINT8_C( 45), UINT8_C( 62), UINT8_C( 84), UINT8_C( 95),
      UINT8_C( 43), UINT8_C(123), UINT8_C(128), UINT8_C( 69), UINT8_C( 26), UINT8_C( 42), UINT8_C(143), UINT8_C( 18),
      UINT8_C( 37), UINT8_C(102), UINT8_C( 88), UINT8_C(121), UINT8_C(206), UINT8_C(254), UINT8_C( 12), UINT8_C(110),
      UINT8_C(194), UINT8_C(225), UINT8_C(102), UINT8_C(117), UINT8_C(190), UINT8_C(161), UINT8_C(137), UINT8_C(185),
      UINT8_C(142), UINT8_C(239), UINT8_C( 27), UINT8_C(188), UINT8_C( 77) };

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
    rv = simde_svsel_u8(pv, av, bv);

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

    ev = simde_svsel_u8(pv, av, bv);

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
test_simde_x_svsel_u16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) };
  static const uint16_t a[] =
    { UINT16_C( 4546), UINT16_C(49366), UINT16_C(53406), UINT16_C(32472), UINT16_C( 3239), UINT16_C(44690), UINT16_C(22473), UINT16_C(15584),
      UINT16_C(26219), UINT16_C(55444), UINT16_C(21704), UINT16_C(15935), UINT16_C(24905), UINT16_C(59885), UINT16_C( 8604), UINT16_C(24121),
      UINT16_C( 3890), UINT16_C(53278), UINT16_C(63199), UINT16_C(34382), UINT16_C(57602), UINT16_C(52277), UINT16_C( 5432), UINT16_C(41736),
      UINT16_C(40059), UINT16_C(17275), UINT16_C(48113), UINT16_C(14977), UINT16_C(28188), UINT16_C(47139), UINT16_C(23951), UINT16_C(49430),
      UINT16_C(13676), UINT16_C(19601), UINT16_C(57387), UINT16_C(11986), UINT16_C( 1985), UINT16_C(63994), UINT16_C(  540), UINT16_C(39068),
      UINT16_C( 6302), UINT16_C(36827), UINT16_C(24019), UINT16_C(61386), UINT16_C(60875), UINT16_C(23463), UINT16_C(48458), UINT16_C(46876),
      UINT16_C(44786), UINT16_C( 7683), UINT16_C(54670), UINT16_C(20300), UINT16_C(18141), UINT16_C(63816), UINT16_C(58440), UINT16_C(59025),
      UINT16_C(28156), UINT16_C(53110), UINT16_C(16586), UINT16_C(38334), UINT16_C(25901), UINT16_C(30960), UINT16_C( 3363), UINT16_C( 5423),
      UINT16_C(12987), UINT16_C(18739), UINT16_C(32519), UINT16_C(58520), UINT16_C(57541), UINT16_C( 3550), UINT16_C(28612), UINT16_C(49652),
      UINT16_C(27356), UINT16_C(42640), UINT16_C(20394), UINT16_C(55100), UINT16_C(11444), UINT16_C(55119), UINT16_C(32313), UINT16_C(62701),
      UINT16_C( 8368), UINT16_C(47165), UINT16_C(54688), UINT16_C(26012), UINT16_C(31413), UINT16_C(31347), UINT16_C(26602), UINT16_C(50747),
      UINT16_C(52177), UINT16_C(31597), UINT16_C(43290), UINT16_C(53074), UINT16_C(41685), UINT16_C( 4006), UINT16_C(37664), UINT16_C(53507),
      UINT16_C(16820), UINT16_C(21641), UINT16_C( 9494), UINT16_C(52409), UINT16_C(11424), UINT16_C(35398), UINT16_C(33171), UINT16_C(25680),
      UINT16_C(48460), UINT16_C(26591), UINT16_C(12902), UINT16_C(15414), UINT16_C(56532), UINT16_C(62539), UINT16_C(20080), UINT16_C( 9413),
      UINT16_C(20111), UINT16_C(42616), UINT16_C(12660), UINT16_C( 5234), UINT16_C(47198), UINT16_C(61854), UINT16_C(60985), UINT16_C(34134),
      UINT16_C(13740), UINT16_C( 4844), UINT16_C( 8807), UINT16_C(15182), UINT16_C(39423), UINT16_C(28464), UINT16_C(62952), UINT16_C(30611),
      UINT16_C( 2884), UINT16_C(47133), UINT16_C(36668), UINT16_C(39628), UINT16_C(27207), UINT16_C(32908), UINT16_C(57944), UINT16_C( 1030),
      UINT16_C(61975), UINT16_C(32535), UINT16_C(25877), UINT16_C( 5306), UINT16_C(60159), UINT16_C(59267), UINT16_C( 5856), UINT16_C( 9310),
      UINT16_C(31777), UINT16_C(24028), UINT16_C(43019), UINT16_C(21496), UINT16_C(33810), UINT16_C(27347), UINT16_C(55654), UINT16_C(32111),
      UINT16_C(34508), UINT16_C(57852), UINT16_C(47083), UINT16_C(60149), UINT16_C(30881), UINT16_C(33233), UINT16_C(12430), UINT16_C(44965),
      UINT16_C(33196), UINT16_C(46860), UINT16_C( 1065), UINT16_C(15114), UINT16_C(56968), UINT16_C(61094), UINT16_C( 5559), UINT16_C(33644),
      UINT16_C(26779), UINT16_C(34404), UINT16_C(22815), UINT16_C(49521), UINT16_C(17105), UINT16_C(24386), UINT16_C(59506), UINT16_C( 7694),
      UINT16_C( 7017), UINT16_C(37846), UINT16_C(57375), UINT16_C(43214), UINT16_C(29886), UINT16_C(30358), UINT16_C(  649), UINT16_C( 9465),
      UINT16_C(24171), UINT16_C(35499), UINT16_C( 7351), UINT16_C(35147), UINT16_C(36446), UINT16_C(53736), UINT16_C(63350), UINT16_C(57327),
      UINT16_C(50450), UINT16_C(12658), UINT16_C(16806), UINT16_C(25817), UINT16_C(28853), UINT16_C(16346), UINT16_C(54386), UINT16_C(56675),
      UINT16_C( 3634), UINT16_C(59752), UINT16_C(45866), UINT16_C(35186), UINT16_C(23361), UINT16_C(46938), UINT16_C(18770), UINT16_C(25751),
      UINT16_C( 2319), UINT16_C(46485), UINT16_C(28490), UINT16_C(   25), UINT16_C(62687), UINT16_C(20799), UINT16_C(41672), UINT16_C(64047),
      UINT16_C(38833), UINT16_C(56291), UINT16_C(22090), UINT16_C(35940), UINT16_C(48817), UINT16_C(  835), UINT16_C(55816), UINT16_C( 5991),
      UINT16_C(64740), UINT16_C(11980), UINT16_C(58731), UINT16_C(18990), UINT16_C(28121), UINT16_C(41372), UINT16_C(51984), UINT16_C(49563),
      UINT16_C(32610), UINT16_C(44188), UINT16_C(  469), UINT16_C(34360), UINT16_C(31935), UINT16_C(51081), UINT16_C(61526), UINT16_C(15070),
      UINT16_C(43756), UINT16_C(22633), UINT16_C(38800), UINT16_C(27042), UINT16_C(15877), UINT16_C( 5387), UINT16_C(42505), UINT16_C(27606),
      UINT16_C(29221), UINT16_C(64024), UINT16_C(20595), UINT16_C(13184), UINT16_C( 2508), UINT16_C( 9210), UINT16_C(55801), UINT16_C(58973),
      UINT16_C(50819), UINT16_C( 4926), UINT16_C(57438), UINT16_C(25469), UINT16_C(34847), UINT16_C(10360), UINT16_C(20014), UINT16_C(21652),
      UINT16_C(44224), UINT16_C(13390), UINT16_C(53244), UINT16_C(51559), UINT16_C(25048), UINT16_C(53996), UINT16_C(18746), UINT16_C(48824),
      UINT16_C(62992), UINT16_C(28369), UINT16_C(20182), UINT16_C(62929), UINT16_C(18902), UINT16_C( 1310), UINT16_C(45719), UINT16_C(22361),
      UINT16_C(42846), UINT16_C(23179), UINT16_C(62070), UINT16_C(20259), UINT16_C( 3924), UINT16_C(36385), UINT16_C(55641), UINT16_C(26956),
      UINT16_C( 7887), UINT16_C(42455), UINT16_C(43116), UINT16_C(17307), UINT16_C(47601), UINT16_C(34888), UINT16_C(41323), UINT16_C(51679),
      UINT16_C(27464), UINT16_C(48931), UINT16_C(18269), UINT16_C(45326), UINT16_C(12118), UINT16_C(44864), UINT16_C(35848), UINT16_C(55064),
      UINT16_C(61354), UINT16_C( 6012), UINT16_C( 6039), UINT16_C(34906), UINT16_C(41680), UINT16_C(15120), UINT16_C(61507), UINT16_C(35588),
      UINT16_C(10331), UINT16_C(47178), UINT16_C(22639), UINT16_C(50538), UINT16_C(43655), UINT16_C(36725), UINT16_C(36150), UINT16_C(57702),
      UINT16_C(58237), UINT16_C( 5368), UINT16_C(21242), UINT16_C(52125), UINT16_C(44532), UINT16_C(14086), UINT16_C( 2973), UINT16_C(63682),
      UINT16_C( 3379), UINT16_C(41649), UINT16_C( 7013), UINT16_C(60775), UINT16_C(56517), UINT16_C(64380), UINT16_C(58218), UINT16_C(59356),
      UINT16_C(54470), UINT16_C(49403), UINT16_C(38950), UINT16_C( 6795), UINT16_C(37446), UINT16_C(58193), UINT16_C( 5277), UINT16_C(53468),
      UINT16_C(36129), UINT16_C(34418), UINT16_C(55720), UINT16_C(28019), UINT16_C(61622), UINT16_C( 8296), UINT16_C(17875), UINT16_C(39175),
      UINT16_C(  537), UINT16_C(16473), UINT16_C(58779), UINT16_C(57690), UINT16_C(44151), UINT16_C( 5316), UINT16_C(41152), UINT16_C(57828),
      UINT16_C(22061), UINT16_C(54631), UINT16_C(56111), UINT16_C(58690), UINT16_C(43979), UINT16_C(40453), UINT16_C( 3312), UINT16_C( 2359),
      UINT16_C(36879), UINT16_C(43593), UINT16_C(42101), UINT16_C(60555), UINT16_C(20304), UINT16_C( 4096), UINT16_C(58608), UINT16_C( 7665),
      UINT16_C(22586), UINT16_C(27379), UINT16_C(13619), UINT16_C(65103), UINT16_C(21984), UINT16_C(53404), UINT16_C(54113), UINT16_C(28890),
      UINT16_C( 9060), UINT16_C(55578), UINT16_C(42439), UINT16_C( 6086), UINT16_C(50933), UINT16_C(58663), UINT16_C( 6315), UINT16_C(58626),
      UINT16_C(62833), UINT16_C(42063), UINT16_C(40747), UINT16_C( 2979), UINT16_C(16372), UINT16_C(21980), UINT16_C(46611), UINT16_C(30662),
      UINT16_C(57561), UINT16_C(41296), UINT16_C( 5766), UINT16_C(31672), UINT16_C(57565), UINT16_C(34912), UINT16_C(25336), UINT16_C(26989),
      UINT16_C(48472), UINT16_C(33550), UINT16_C(45404), UINT16_C(20622), UINT16_C(27376), UINT16_C(  933), UINT16_C(27424), UINT16_C(64122),
      UINT16_C(52044), UINT16_C(53915), UINT16_C(21473), UINT16_C(48717), UINT16_C(44339), UINT16_C(11334), UINT16_C(46095), UINT16_C(26517),
      UINT16_C(41841), UINT16_C(52714), UINT16_C(31060), UINT16_C(17693), UINT16_C(49891), UINT16_C( 1096), UINT16_C(49966), UINT16_C(31486),
      UINT16_C(39310), UINT16_C(28492), UINT16_C(39404), UINT16_C( 8238), UINT16_C(29766), UINT16_C(21836), UINT16_C(57640), UINT16_C(39357),
      UINT16_C(42885), UINT16_C(55654), UINT16_C(33568), UINT16_C( 1054), UINT16_C(26438), UINT16_C(29704), UINT16_C( 1578), UINT16_C(47342),
      UINT16_C(15007), UINT16_C(35623), UINT16_C(21971), UINT16_C( 6571), UINT16_C(63434), UINT16_C(62062), UINT16_C(11225), UINT16_C(24204),
      UINT16_C(62163), UINT16_C(62263), UINT16_C(22134), UINT16_C(48375), UINT16_C(65469), UINT16_C(59184), UINT16_C( 7685), UINT16_C(42143),
      UINT16_C(50776), UINT16_C(11056), UINT16_C(56092), UINT16_C(58948), UINT16_C(45779), UINT16_C(44248), UINT16_C(25822), UINT16_C(45322),
      UINT16_C(16727), UINT16_C(52644), UINT16_C(40087), UINT16_C(21641), UINT16_C(47515), UINT16_C(41275), UINT16_C(56023), UINT16_C(12101),
      UINT16_C(30113), UINT16_C(48474), UINT16_C(40529), UINT16_C( 9379), UINT16_C(31568), UINT16_C(11984), UINT16_C(56032), UINT16_C(14303),
      UINT16_C(33819), UINT16_C(45828), UINT16_C(36128), UINT16_C(47879), UINT16_C(17222), UINT16_C( 7516) };
  static const uint16_t e[] =
    { UINT16_C( 4546), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 3239), UINT16_C(44690), UINT16_C(22473), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(21704), UINT16_C(15935), UINT16_C(24905), UINT16_C(    0), UINT16_C( 8604), UINT16_C(24121),
      UINT16_C(    0), UINT16_C(53278), UINT16_C(63199), UINT16_C(34382), UINT16_C(57602), UINT16_C(52277), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(40059), UINT16_C(17275), UINT16_C(48113), UINT16_C(14977), UINT16_C(    0), UINT16_C(47139), UINT16_C(    0), UINT16_C(49430),
      UINT16_C(13676), UINT16_C(19601), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C( 6302), UINT16_C(36827), UINT16_C(24019), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(48458), UINT16_C(46876),
      UINT16_C(44786), UINT16_C( 7683), UINT16_C(    0), UINT16_C(20300), UINT16_C(18141), UINT16_C(63816), UINT16_C(    0), UINT16_C(59025),
      UINT16_C(28156), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(25901), UINT16_C(30960), UINT16_C( 3363), UINT16_C(    0),
      UINT16_C(12987), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(57541), UINT16_C( 3550), UINT16_C(28612), UINT16_C(49652),
      UINT16_C(27356), UINT16_C(42640), UINT16_C(20394), UINT16_C(55100), UINT16_C(11444), UINT16_C(55119), UINT16_C(32313), UINT16_C(    0),
      UINT16_C( 8368), UINT16_C(47165), UINT16_C(54688), UINT16_C(    0), UINT16_C(31413), UINT16_C(31347), UINT16_C(26602), UINT16_C(50747),
      UINT16_C(52177), UINT16_C(    0), UINT16_C(43290), UINT16_C(    0), UINT16_C(41685), UINT16_C( 4006), UINT16_C(37664), UINT16_C(53507),
      UINT16_C(16820), UINT16_C(21641), UINT16_C( 9494), UINT16_C(    0), UINT16_C(11424), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(48460), UINT16_C(    0), UINT16_C(    0), UINT16_C(15414), UINT16_C(56532), UINT16_C(    0), UINT16_C(20080), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(42616), UINT16_C(    0), UINT16_C( 5234), UINT16_C(    0), UINT16_C(61854), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C( 4844), UINT16_C( 8807), UINT16_C(15182), UINT16_C(    0), UINT16_C(28464), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(47133), UINT16_C(    0), UINT16_C(39628), UINT16_C(    0), UINT16_C(32908), UINT16_C(    0), UINT16_C( 1030),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(25877), UINT16_C(    0), UINT16_C(60159), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(31777), UINT16_C(    0), UINT16_C(    0), UINT16_C(21496), UINT16_C(    0), UINT16_C(    0), UINT16_C(55654), UINT16_C(32111),
      UINT16_C(34508), UINT16_C(57852), UINT16_C(47083), UINT16_C(60149), UINT16_C(    0), UINT16_C(33233), UINT16_C(12430), UINT16_C(    0),
      UINT16_C(33196), UINT16_C(46860), UINT16_C( 1065), UINT16_C(15114), UINT16_C(    0), UINT16_C(    0), UINT16_C( 5559), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(49521), UINT16_C(17105), UINT16_C(    0), UINT16_C(    0), UINT16_C( 7694),
      UINT16_C( 7017), UINT16_C(    0), UINT16_C(    0), UINT16_C(43214), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 9465),
      UINT16_C(24171), UINT16_C(35499), UINT16_C( 7351), UINT16_C(35147), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(25817), UINT16_C(28853), UINT16_C(    0), UINT16_C(54386), UINT16_C(56675),
      UINT16_C( 3634), UINT16_C(    0), UINT16_C(45866), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(18770), UINT16_C(25751),
      UINT16_C(    0), UINT16_C(46485), UINT16_C(28490), UINT16_C(   25), UINT16_C(    0), UINT16_C(    0), UINT16_C(41672), UINT16_C(64047),
      UINT16_C(38833), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(48817), UINT16_C(  835), UINT16_C(55816), UINT16_C( 5991),
      UINT16_C(64740), UINT16_C(    0), UINT16_C(    0), UINT16_C(18990), UINT16_C(28121), UINT16_C(    0), UINT16_C(    0), UINT16_C(49563),
      UINT16_C(    0), UINT16_C(44188), UINT16_C(  469), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(61526), UINT16_C(15070),
      UINT16_C(    0), UINT16_C(22633), UINT16_C(38800), UINT16_C(    0), UINT16_C(    0), UINT16_C( 5387), UINT16_C(    0), UINT16_C(27606),
      UINT16_C(    0), UINT16_C(64024), UINT16_C(20595), UINT16_C(13184), UINT16_C(    0), UINT16_C( 9210), UINT16_C(55801), UINT16_C(58973),
      UINT16_C(50819), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(21652),
      UINT16_C(    0), UINT16_C(13390), UINT16_C(53244), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(48824),
      UINT16_C(62992), UINT16_C(28369), UINT16_C(20182), UINT16_C(62929), UINT16_C(    0), UINT16_C(    0), UINT16_C(45719), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(23179), UINT16_C(62070), UINT16_C(20259), UINT16_C(    0), UINT16_C(    0), UINT16_C(55641), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(42455), UINT16_C(    0), UINT16_C(17307), UINT16_C(    0), UINT16_C(34888), UINT16_C(    0), UINT16_C(51679),
      UINT16_C(    0), UINT16_C(48931), UINT16_C(18269), UINT16_C(45326), UINT16_C(12118), UINT16_C(    0), UINT16_C(35848), UINT16_C(55064),
      UINT16_C(61354), UINT16_C( 6012), UINT16_C(    0), UINT16_C(34906), UINT16_C(41680), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(58237), UINT16_C( 5368), UINT16_C(21242), UINT16_C(52125), UINT16_C(44532), UINT16_C(    0), UINT16_C( 2973), UINT16_C(63682),
      UINT16_C( 3379), UINT16_C(    0), UINT16_C( 7013), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(58218), UINT16_C(59356),
      UINT16_C(54470), UINT16_C(    0), UINT16_C(38950), UINT16_C(    0), UINT16_C(    0), UINT16_C(58193), UINT16_C( 5277), UINT16_C(    0),
      UINT16_C(36129), UINT16_C(34418), UINT16_C(    0), UINT16_C(    0), UINT16_C(61622), UINT16_C( 8296), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(58779), UINT16_C(    0), UINT16_C(44151), UINT16_C( 5316), UINT16_C(41152), UINT16_C(    0),
      UINT16_C(22061), UINT16_C(54631), UINT16_C(    0), UINT16_C(58690), UINT16_C(43979), UINT16_C(    0), UINT16_C( 3312), UINT16_C( 2359),
      UINT16_C(    0), UINT16_C(43593), UINT16_C(    0), UINT16_C(60555), UINT16_C(20304), UINT16_C( 4096), UINT16_C(58608), UINT16_C(    0),
      UINT16_C(22586), UINT16_C(27379), UINT16_C(13619), UINT16_C(65103), UINT16_C(    0), UINT16_C(53404), UINT16_C(54113), UINT16_C(28890),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(58663), UINT16_C( 6315), UINT16_C(58626),
      UINT16_C(62833), UINT16_C(42063), UINT16_C(    0), UINT16_C( 2979), UINT16_C(16372), UINT16_C(21980), UINT16_C(    0), UINT16_C(30662),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(57565), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(20622), UINT16_C(27376), UINT16_C(  933), UINT16_C(    0), UINT16_C(64122),
      UINT16_C(52044), UINT16_C(53915), UINT16_C(    0), UINT16_C(48717), UINT16_C(44339), UINT16_C(    0), UINT16_C(46095), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(17693), UINT16_C(49891), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(39404), UINT16_C(    0), UINT16_C(    0), UINT16_C(21836), UINT16_C(57640), UINT16_C(39357),
      UINT16_C(    0), UINT16_C(55654), UINT16_C(33568), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 1578), UINT16_C(    0),
      UINT16_C(15007), UINT16_C(35623), UINT16_C(21971), UINT16_C( 6571), UINT16_C(63434), UINT16_C(    0), UINT16_C(    0), UINT16_C(24204),
      UINT16_C(62163), UINT16_C(62263), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(59184), UINT16_C(    0), UINT16_C(42143),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(56092), UINT16_C(    0), UINT16_C(45779), UINT16_C(    0), UINT16_C(25822), UINT16_C(    0),
      UINT16_C(16727), UINT16_C(52644), UINT16_C(    0), UINT16_C(21641), UINT16_C(47515), UINT16_C(41275), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(14303),
      UINT16_C(33819), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 7516) };

  static uint16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t
      rv,
      av = simde_svld1_u16(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(INT16_C(0)));
    rv = simde_x_svsel_u16_z(pv, av);

    simde_svst1_u16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vu16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(int16_t)];
  uint16_t a[1024 / sizeof(int16_t)], e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_u16(pg, &(a[i]));

    ev = simde_x_svsel_u16_z(pv, av);

    simde_svst1_u16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsel_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) };
  static const uint16_t a[] =
    { UINT16_C(59508), UINT16_C(64672), UINT16_C(37215), UINT16_C(55383), UINT16_C(40646), UINT16_C(50216), UINT16_C(20030), UINT16_C(19711),
      UINT16_C( 6288), UINT16_C(10077), UINT16_C(48551), UINT16_C(44665), UINT16_C( 7037), UINT16_C(52878), UINT16_C(10558), UINT16_C(45723),
      UINT16_C(15121), UINT16_C(29103), UINT16_C( 1740), UINT16_C(37449), UINT16_C(29092), UINT16_C(57942), UINT16_C(21951), UINT16_C(20270),
      UINT16_C(35694), UINT16_C( 5494), UINT16_C(61256), UINT16_C(50884), UINT16_C(21002), UINT16_C(18580), UINT16_C(12155), UINT16_C(36347),
      UINT16_C(43626), UINT16_C(14078), UINT16_C(18352), UINT16_C(21704), UINT16_C( 8120), UINT16_C(30518), UINT16_C(25716), UINT16_C(58055),
      UINT16_C(15855), UINT16_C(14584), UINT16_C(48173), UINT16_C(14334), UINT16_C(37390), UINT16_C(35200), UINT16_C(31682), UINT16_C(11286),
      UINT16_C( 5157), UINT16_C(54627), UINT16_C(11099), UINT16_C( 4905), UINT16_C(24394), UINT16_C(49035), UINT16_C(21187), UINT16_C(45729),
      UINT16_C(39311), UINT16_C(48362), UINT16_C(59477), UINT16_C(25588), UINT16_C(29819), UINT16_C(15853), UINT16_C( 1007), UINT16_C( 5225),
      UINT16_C(52248), UINT16_C(29673), UINT16_C( 4856), UINT16_C(17031), UINT16_C( 4721), UINT16_C(13313), UINT16_C(41828), UINT16_C(62438),
      UINT16_C(53564), UINT16_C(37552), UINT16_C(42169), UINT16_C(13557), UINT16_C(57880), UINT16_C( 1905), UINT16_C(56294), UINT16_C(65051),
      UINT16_C( 1191), UINT16_C(40817), UINT16_C(63510), UINT16_C(34786), UINT16_C(58122), UINT16_C(28347), UINT16_C(41350), UINT16_C(50018),
      UINT16_C( 4722), UINT16_C(11349), UINT16_C(19126), UINT16_C(52832), UINT16_C(53805), UINT16_C( 5077), UINT16_C(61613), UINT16_C(21521),
      UINT16_C(33524), UINT16_C( 2804), UINT16_C(54907), UINT16_C(34193), UINT16_C(19641), UINT16_C(16628), UINT16_C(22253), UINT16_C(24579),
      UINT16_C(22632), UINT16_C( 7820), UINT16_C(60578), UINT16_C(53228), UINT16_C(49598), UINT16_C(27618), UINT16_C(62385), UINT16_C(42432),
      UINT16_C(46198), UINT16_C(61871), UINT16_C(16522), UINT16_C(17270), UINT16_C(27276), UINT16_C(31107), UINT16_C(34496), UINT16_C(10457),
      UINT16_C(26078), UINT16_C(33094), UINT16_C(12882), UINT16_C( 4176), UINT16_C(13299), UINT16_C(42108), UINT16_C(15398), UINT16_C(40009),
      UINT16_C(63728), UINT16_C(31373), UINT16_C( 1080), UINT16_C(50365), UINT16_C(16750), UINT16_C(12094), UINT16_C( 6087), UINT16_C(42583),
      UINT16_C(40573), UINT16_C(53031), UINT16_C(30672), UINT16_C(50399), UINT16_C(23466), UINT16_C(53608), UINT16_C(45719), UINT16_C(34669),
      UINT16_C(64426), UINT16_C(58113), UINT16_C(49151), UINT16_C(28071), UINT16_C(58624), UINT16_C(51100), UINT16_C(62717), UINT16_C(31341),
      UINT16_C(38034), UINT16_C(25161), UINT16_C(10252), UINT16_C(46630), UINT16_C(36740), UINT16_C( 7047), UINT16_C(62785), UINT16_C(60323),
      UINT16_C(42224), UINT16_C(61390), UINT16_C(30307), UINT16_C(25436), UINT16_C(63835), UINT16_C(22571), UINT16_C(39149), UINT16_C(32722),
      UINT16_C( 6957), UINT16_C(14817), UINT16_C( 2116), UINT16_C(51439), UINT16_C(30615), UINT16_C(55523), UINT16_C(34412), UINT16_C(23747),
      UINT16_C(37419), UINT16_C(36427), UINT16_C(42760), UINT16_C(25586), UINT16_C( 7584), UINT16_C(36284), UINT16_C(36533), UINT16_C(57868),
      UINT16_C(61098), UINT16_C(60955), UINT16_C( 3062), UINT16_C(36278), UINT16_C(39298), UINT16_C(61029), UINT16_C(10272), UINT16_C(19274),
      UINT16_C(38330), UINT16_C(49881), UINT16_C(52028), UINT16_C(56614), UINT16_C(58088), UINT16_C(40554), UINT16_C(30576), UINT16_C( 6784),
      UINT16_C(40037), UINT16_C(23304), UINT16_C(48807), UINT16_C(10728), UINT16_C(19800), UINT16_C(30743), UINT16_C(24949), UINT16_C(12483),
      UINT16_C(40182), UINT16_C(13042), UINT16_C( 6248), UINT16_C(20495), UINT16_C(31482), UINT16_C(27630), UINT16_C(28657), UINT16_C(22149),
      UINT16_C(36363), UINT16_C(45745), UINT16_C(39244), UINT16_C(42203), UINT16_C(62182), UINT16_C(23324), UINT16_C(57171), UINT16_C(18827),
      UINT16_C(32380), UINT16_C(58491), UINT16_C(35734), UINT16_C(37172), UINT16_C( 8965), UINT16_C(63228), UINT16_C(33170), UINT16_C(40268),
      UINT16_C(64783), UINT16_C(23631), UINT16_C(10902), UINT16_C(31744), UINT16_C( 7452), UINT16_C(28631), UINT16_C(25596), UINT16_C(30904),
      UINT16_C(13281), UINT16_C(30556), UINT16_C(37310), UINT16_C(49928), UINT16_C( 1204), UINT16_C(18105), UINT16_C( 1414), UINT16_C(38371),
      UINT16_C(12802), UINT16_C(39153), UINT16_C(62044), UINT16_C(30740), UINT16_C(60431), UINT16_C( 3047), UINT16_C(40783), UINT16_C(12420),
      UINT16_C(57554), UINT16_C(37287), UINT16_C(45169), UINT16_C( 9556), UINT16_C( 3764), UINT16_C(14955), UINT16_C(19987), UINT16_C( 5840),
      UINT16_C(49536), UINT16_C(56494), UINT16_C(50099), UINT16_C(49748), UINT16_C(15279), UINT16_C(65230), UINT16_C(21210), UINT16_C(44334),
      UINT16_C(54578), UINT16_C(42046), UINT16_C(37509), UINT16_C(15049), UINT16_C(13728), UINT16_C(46196), UINT16_C(17539), UINT16_C( 1226),
      UINT16_C(30726), UINT16_C(47584), UINT16_C(13627), UINT16_C(60028), UINT16_C(19056), UINT16_C(19432), UINT16_C( 5788), UINT16_C(52984),
      UINT16_C(14060), UINT16_C(29042), UINT16_C(15560), UINT16_C(27051), UINT16_C( 8305), UINT16_C(62493), UINT16_C(59236), UINT16_C(27384),
      UINT16_C(55647), UINT16_C(39716), UINT16_C(40974), UINT16_C(32389), UINT16_C(28394), UINT16_C(34505), UINT16_C(49540), UINT16_C(28756),
      UINT16_C(51191), UINT16_C(49378), UINT16_C(36099), UINT16_C(29737), UINT16_C(18093), UINT16_C( 4712), UINT16_C(24877), UINT16_C(35964),
      UINT16_C(41018), UINT16_C(18471), UINT16_C(44352), UINT16_C(10950), UINT16_C(36891), UINT16_C(40880), UINT16_C( 1361), UINT16_C(18704),
      UINT16_C(62156), UINT16_C(53001), UINT16_C(12927), UINT16_C(11587), UINT16_C(43896), UINT16_C(42303), UINT16_C(47884), UINT16_C(17969),
      UINT16_C(22876), UINT16_C(40078), UINT16_C(21766), UINT16_C( 8647), UINT16_C(30693), UINT16_C(14016), UINT16_C(53372), UINT16_C(18559),
      UINT16_C(35010), UINT16_C(16919), UINT16_C(23226), UINT16_C(12911), UINT16_C(44550), UINT16_C( 4823), UINT16_C( 2409), UINT16_C(50521),
      UINT16_C(59234), UINT16_C(26722), UINT16_C(10556), UINT16_C( 8585), UINT16_C(18848), UINT16_C( 7512), UINT16_C(55066), UINT16_C(56421),
      UINT16_C(32096), UINT16_C( 6686), UINT16_C(36311), UINT16_C(56653), UINT16_C( 9275), UINT16_C(42480), UINT16_C(18733), UINT16_C(36714),
      UINT16_C(52272), UINT16_C(28151), UINT16_C(33013), UINT16_C(38542), UINT16_C(59082), UINT16_C(58547), UINT16_C( 6334), UINT16_C( 7872),
      UINT16_C(57237), UINT16_C(27960), UINT16_C(34156), UINT16_C(43082), UINT16_C(15018), UINT16_C(55117), UINT16_C(46979), UINT16_C(46183),
      UINT16_C(24196), UINT16_C(31009), UINT16_C(45023), UINT16_C(43279), UINT16_C(49814), UINT16_C(21645), UINT16_C(19931), UINT16_C(28786),
      UINT16_C(43564), UINT16_C(39389), UINT16_C(10288), UINT16_C(55873), UINT16_C(36450), UINT16_C(59057), UINT16_C( 6213), UINT16_C(51610),
      UINT16_C(47991), UINT16_C(22083), UINT16_C(21098), UINT16_C(  255), UINT16_C(35861), UINT16_C(61524), UINT16_C(50905), UINT16_C( 1632),
      UINT16_C(15985), UINT16_C(41375), UINT16_C(57446), UINT16_C(51323), UINT16_C(11374), UINT16_C(45998), UINT16_C(18501) };
  static const uint16_t b[] =
    { UINT16_C(64032), UINT16_C(35201), UINT16_C(58553), UINT16_C(11385), UINT16_C(12396), UINT16_C(18597), UINT16_C(18495), UINT16_C(48518),
      UINT16_C(38797), UINT16_C(31470), UINT16_C(  339), UINT16_C(59640), UINT16_C( 1988), UINT16_C(64488), UINT16_C(24034), UINT16_C(  624),
      UINT16_C(61783), UINT16_C( 4492), UINT16_C( 1493), UINT16_C(16957), UINT16_C(57909), UINT16_C(30090), UINT16_C( 4138), UINT16_C(46898),
      UINT16_C( 8360), UINT16_C(64305), UINT16_C(10786), UINT16_C(59107), UINT16_C(52017), UINT16_C( 5345), UINT16_C(21032), UINT16_C(32534),
      UINT16_C(41539), UINT16_C( 6544), UINT16_C(52648), UINT16_C(56667), UINT16_C(58800), UINT16_C(55890), UINT16_C(34038), UINT16_C(40594),
      UINT16_C(50085), UINT16_C(51097), UINT16_C(31981), UINT16_C( 8109), UINT16_C(36423), UINT16_C(28467), UINT16_C(18912), UINT16_C( 9454),
      UINT16_C(32748), UINT16_C(37949), UINT16_C(38988), UINT16_C(64625), UINT16_C(50301), UINT16_C(29655), UINT16_C(26952), UINT16_C(60689),
      UINT16_C(43564), UINT16_C( 6836), UINT16_C(24870), UINT16_C(27961), UINT16_C(27888), UINT16_C(53468), UINT16_C(52149), UINT16_C(41460),
      UINT16_C(12618), UINT16_C(38453), UINT16_C(42953), UINT16_C(18323), UINT16_C(27243), UINT16_C(46010), UINT16_C(52435), UINT16_C(65441),
      UINT16_C(21878), UINT16_C(40217), UINT16_C(21175), UINT16_C(42762), UINT16_C(59326), UINT16_C(29815), UINT16_C(27826), UINT16_C(64533),
      UINT16_C(19357), UINT16_C(26514), UINT16_C( 9714), UINT16_C(23982), UINT16_C(26767), UINT16_C(25104), UINT16_C(45364), UINT16_C(43874),
      UINT16_C(31495), UINT16_C(48712), UINT16_C(21198), UINT16_C(35941), UINT16_C(56377), UINT16_C(60160), UINT16_C( 5704), UINT16_C(59111),
      UINT16_C(31329), UINT16_C(21325), UINT16_C(64415), UINT16_C(12208), UINT16_C(49251), UINT16_C(39057), UINT16_C(62322), UINT16_C(31043),
      UINT16_C(35695), UINT16_C(15671), UINT16_C(40157), UINT16_C( 6089), UINT16_C(51832), UINT16_C(49410), UINT16_C(60128), UINT16_C(16807),
      UINT16_C(62564), UINT16_C(  916), UINT16_C(17647), UINT16_C(21042), UINT16_C(50180), UINT16_C(30442), UINT16_C(11703), UINT16_C( 9967),
      UINT16_C( 9912), UINT16_C(38499), UINT16_C(11714), UINT16_C(15277), UINT16_C(45047), UINT16_C(55292), UINT16_C(41881), UINT16_C(64792),
      UINT16_C(44183), UINT16_C(34305), UINT16_C(13296), UINT16_C(62680), UINT16_C(50167), UINT16_C(44907), UINT16_C(23280), UINT16_C(43477),
      UINT16_C(14721), UINT16_C(17215), UINT16_C(60518), UINT16_C(23934), UINT16_C(31387), UINT16_C(13620), UINT16_C(19485), UINT16_C(46130),
      UINT16_C(13304), UINT16_C(59450), UINT16_C( 4967), UINT16_C(24284), UINT16_C(18390), UINT16_C(50701), UINT16_C(58274), UINT16_C( 9071),
      UINT16_C(44572), UINT16_C(33382), UINT16_C(58778), UINT16_C(14047), UINT16_C( 4959), UINT16_C(32107), UINT16_C(40287), UINT16_C(22321),
      UINT16_C(27857), UINT16_C(14399), UINT16_C( 7039), UINT16_C(21910), UINT16_C(42083), UINT16_C( 1307), UINT16_C(35719), UINT16_C(41768),
      UINT16_C(36409), UINT16_C(54309), UINT16_C( 1139), UINT16_C(54026), UINT16_C(29975), UINT16_C(30288), UINT16_C(33042), UINT16_C(58317),
      UINT16_C( 3309), UINT16_C(27675), UINT16_C(45607), UINT16_C(35521), UINT16_C(56662), UINT16_C(56719), UINT16_C(46952), UINT16_C(41344),
      UINT16_C(42310), UINT16_C(47477), UINT16_C(32681), UINT16_C(49292), UINT16_C(56564), UINT16_C( 1846), UINT16_C(  862), UINT16_C(19434),
      UINT16_C( 1551), UINT16_C(14008), UINT16_C(31160), UINT16_C( 3777), UINT16_C(20566), UINT16_C(48875), UINT16_C(27400), UINT16_C(20064),
      UINT16_C(54544), UINT16_C(47367), UINT16_C(37973), UINT16_C(18809), UINT16_C(44912), UINT16_C(52816), UINT16_C(15282), UINT16_C(49434),
      UINT16_C(53825), UINT16_C(63991), UINT16_C(47179), UINT16_C(41479), UINT16_C(61961), UINT16_C( 4448), UINT16_C(49245), UINT16_C(27999),
      UINT16_C(26262), UINT16_C(60198), UINT16_C(40954), UINT16_C(27444), UINT16_C(34126), UINT16_C(   57), UINT16_C(21440), UINT16_C(  449),
      UINT16_C(47141), UINT16_C(29178), UINT16_C(  369), UINT16_C(31251), UINT16_C(29683), UINT16_C(20619), UINT16_C(59956), UINT16_C(51901),
      UINT16_C(58192), UINT16_C(19381), UINT16_C(59778), UINT16_C(53430), UINT16_C(61294), UINT16_C(11984), UINT16_C(37187), UINT16_C(26671),
      UINT16_C(10569), UINT16_C(47833), UINT16_C(60458), UINT16_C( 7476), UINT16_C(48992), UINT16_C(37997), UINT16_C(10921), UINT16_C(64094),
      UINT16_C( 4877), UINT16_C(36677), UINT16_C(64508), UINT16_C(27487), UINT16_C(12266), UINT16_C(11673), UINT16_C(51648), UINT16_C( 2710),
      UINT16_C(28658), UINT16_C( 7620), UINT16_C(63836), UINT16_C(48186), UINT16_C(43192), UINT16_C(25168), UINT16_C(44754), UINT16_C(57436),
      UINT16_C(41409), UINT16_C(48495), UINT16_C(53148), UINT16_C(34344), UINT16_C(49918), UINT16_C(49076), UINT16_C(19083), UINT16_C(32201),
      UINT16_C(36281), UINT16_C( 5530), UINT16_C(54662), UINT16_C(16337), UINT16_C( 8573), UINT16_C(20385), UINT16_C(64975), UINT16_C(36911),
      UINT16_C(40862), UINT16_C(14926), UINT16_C(30318), UINT16_C(27840), UINT16_C(29752), UINT16_C(49963), UINT16_C(62654), UINT16_C(30785),
      UINT16_C(56194), UINT16_C( 2189), UINT16_C(24496), UINT16_C(11591), UINT16_C(59520), UINT16_C(20605), UINT16_C(44261), UINT16_C(33760),
      UINT16_C(11851), UINT16_C(47549), UINT16_C(32421), UINT16_C(56614), UINT16_C(20978), UINT16_C(45473), UINT16_C(57926), UINT16_C(51241),
      UINT16_C(46781), UINT16_C(28368), UINT16_C( 6165), UINT16_C(38555), UINT16_C( 6144), UINT16_C(59110), UINT16_C(50885), UINT16_C( 4201),
      UINT16_C(10229), UINT16_C(39626), UINT16_C(61605), UINT16_C(38775), UINT16_C( 6209), UINT16_C(34632), UINT16_C(29178), UINT16_C(47183),
      UINT16_C( 8232), UINT16_C(15654), UINT16_C(49464), UINT16_C(14547), UINT16_C(47578), UINT16_C(40734), UINT16_C(34944), UINT16_C(30127),
      UINT16_C(31151), UINT16_C(21519), UINT16_C(34409), UINT16_C(44011), UINT16_C(13471), UINT16_C(39218), UINT16_C(33445), UINT16_C(52561),
      UINT16_C(30626), UINT16_C(55819), UINT16_C(56889), UINT16_C( 4882), UINT16_C(12696), UINT16_C( 6322), UINT16_C(25017), UINT16_C(26765),
      UINT16_C(40155), UINT16_C(17596), UINT16_C(42786), UINT16_C(49647), UINT16_C( 8923), UINT16_C(33115), UINT16_C(44196), UINT16_C(17998),
      UINT16_C(22820), UINT16_C(23840), UINT16_C(12856), UINT16_C(53360), UINT16_C( 8803), UINT16_C( 7400), UINT16_C(30083), UINT16_C(24196),
      UINT16_C(16401), UINT16_C(13219), UINT16_C(37608), UINT16_C(50165), UINT16_C(20660), UINT16_C(22596), UINT16_C(37884), UINT16_C( 8350),
      UINT16_C(48876), UINT16_C( 9341), UINT16_C(60913), UINT16_C(21748), UINT16_C(56335), UINT16_C(37745), UINT16_C(62801), UINT16_C(25329),
      UINT16_C(37942), UINT16_C( 7830), UINT16_C(35623), UINT16_C(56289), UINT16_C( 9947), UINT16_C(55092), UINT16_C(53945), UINT16_C(42488),
      UINT16_C(30097), UINT16_C(33482), UINT16_C(48739), UINT16_C(29398), UINT16_C(18331), UINT16_C(60421), UINT16_C(63293), UINT16_C(29519),
      UINT16_C(58763), UINT16_C(45713), UINT16_C(29296), UINT16_C(19342), UINT16_C(49816), UINT16_C(20770), UINT16_C( 6804), UINT16_C( 9719),
      UINT16_C(49552), UINT16_C(62375), UINT16_C(32383), UINT16_C( 6757), UINT16_C(27589), UINT16_C(  519), UINT16_C(22114) };
  static const uint16_t e[] =
    { UINT16_C(64032), UINT16_C(35201), UINT16_C(58553), UINT16_C(55383), UINT16_C(40646), UINT16_C(50216), UINT16_C(20030), UINT16_C(19711),
      UINT16_C(38797), UINT16_C(31470), UINT16_C(48551), UINT16_C(44665), UINT16_C( 7037), UINT16_C(64488), UINT16_C(24034), UINT16_C(  624),
      UINT16_C(15121), UINT16_C(29103), UINT16_C( 1740), UINT16_C(37449), UINT16_C(57909), UINT16_C(30090), UINT16_C(21951), UINT16_C(46898),
      UINT16_C(35694), UINT16_C( 5494), UINT16_C(10786), UINT16_C(59107), UINT16_C(52017), UINT16_C(18580), UINT16_C(21032), UINT16_C(36347),
      UINT16_C(43626), UINT16_C(14078), UINT16_C(18352), UINT16_C(21704), UINT16_C( 8120), UINT16_C(55890), UINT16_C(25716), UINT16_C(58055),
      UINT16_C(15855), UINT16_C(51097), UINT16_C(48173), UINT16_C( 8109), UINT16_C(37390), UINT16_C(35200), UINT16_C(18912), UINT16_C( 9454),
      UINT16_C( 5157), UINT16_C(54627), UINT16_C(38988), UINT16_C(64625), UINT16_C(50301), UINT16_C(29655), UINT16_C(26952), UINT16_C(45729),
      UINT16_C(43564), UINT16_C(48362), UINT16_C(24870), UINT16_C(27961), UINT16_C(27888), UINT16_C(53468), UINT16_C( 1007), UINT16_C( 5225),
      UINT16_C(52248), UINT16_C(29673), UINT16_C( 4856), UINT16_C(18323), UINT16_C( 4721), UINT16_C(13313), UINT16_C(41828), UINT16_C(62438),
      UINT16_C(21878), UINT16_C(37552), UINT16_C(21175), UINT16_C(13557), UINT16_C(59326), UINT16_C( 1905), UINT16_C(56294), UINT16_C(64533),
      UINT16_C(19357), UINT16_C(40817), UINT16_C( 9714), UINT16_C(23982), UINT16_C(26767), UINT16_C(25104), UINT16_C(41350), UINT16_C(50018),
      UINT16_C( 4722), UINT16_C(11349), UINT16_C(19126), UINT16_C(35941), UINT16_C(56377), UINT16_C( 5077), UINT16_C(61613), UINT16_C(59111),
      UINT16_C(33524), UINT16_C(21325), UINT16_C(54907), UINT16_C(12208), UINT16_C(49251), UINT16_C(39057), UINT16_C(62322), UINT16_C(31043),
      UINT16_C(22632), UINT16_C( 7820), UINT16_C(60578), UINT16_C( 6089), UINT16_C(51832), UINT16_C(27618), UINT16_C(62385), UINT16_C(42432),
      UINT16_C(62564), UINT16_C(61871), UINT16_C(17647), UINT16_C(21042), UINT16_C(27276), UINT16_C(31107), UINT16_C(11703), UINT16_C(10457),
      UINT16_C( 9912), UINT16_C(38499), UINT16_C(12882), UINT16_C( 4176), UINT16_C(13299), UINT16_C(55292), UINT16_C(41881), UINT16_C(64792),
      UINT16_C(44183), UINT16_C(34305), UINT16_C(13296), UINT16_C(62680), UINT16_C(50167), UINT16_C(44907), UINT16_C( 6087), UINT16_C(43477),
      UINT16_C(14721), UINT16_C(53031), UINT16_C(60518), UINT16_C(50399), UINT16_C(31387), UINT16_C(13620), UINT16_C(19485), UINT16_C(46130),
      UINT16_C(13304), UINT16_C(59450), UINT16_C(49151), UINT16_C(24284), UINT16_C(18390), UINT16_C(51100), UINT16_C(58274), UINT16_C( 9071),
      UINT16_C(44572), UINT16_C(25161), UINT16_C(58778), UINT16_C(14047), UINT16_C(36740), UINT16_C(32107), UINT16_C(40287), UINT16_C(22321),
      UINT16_C(42224), UINT16_C(14399), UINT16_C(30307), UINT16_C(21910), UINT16_C(63835), UINT16_C( 1307), UINT16_C(35719), UINT16_C(32722),
      UINT16_C( 6957), UINT16_C(54309), UINT16_C( 1139), UINT16_C(51439), UINT16_C(29975), UINT16_C(55523), UINT16_C(34412), UINT16_C(23747),
      UINT16_C(37419), UINT16_C(27675), UINT16_C(45607), UINT16_C(25586), UINT16_C(56662), UINT16_C(36284), UINT16_C(46952), UINT16_C(41344),
      UINT16_C(42310), UINT16_C(47477), UINT16_C( 3062), UINT16_C(49292), UINT16_C(56564), UINT16_C( 1846), UINT16_C(10272), UINT16_C(19434),
      UINT16_C(38330), UINT16_C(14008), UINT16_C(31160), UINT16_C(56614), UINT16_C(58088), UINT16_C(48875), UINT16_C(27400), UINT16_C(20064),
      UINT16_C(54544), UINT16_C(23304), UINT16_C(48807), UINT16_C(10728), UINT16_C(44912), UINT16_C(30743), UINT16_C(24949), UINT16_C(49434),
      UINT16_C(53825), UINT16_C(63991), UINT16_C( 6248), UINT16_C(20495), UINT16_C(61961), UINT16_C( 4448), UINT16_C(28657), UINT16_C(22149),
      UINT16_C(36363), UINT16_C(45745), UINT16_C(40954), UINT16_C(27444), UINT16_C(34126), UINT16_C(23324), UINT16_C(21440), UINT16_C(18827),
      UINT16_C(32380), UINT16_C(29178), UINT16_C(35734), UINT16_C(37172), UINT16_C( 8965), UINT16_C(63228), UINT16_C(59956), UINT16_C(40268),
      UINT16_C(58192), UINT16_C(19381), UINT16_C(59778), UINT16_C(53430), UINT16_C( 7452), UINT16_C(28631), UINT16_C(37187), UINT16_C(26671),
      UINT16_C(13281), UINT16_C(30556), UINT16_C(60458), UINT16_C(49928), UINT16_C( 1204), UINT16_C(37997), UINT16_C( 1414), UINT16_C(38371),
      UINT16_C( 4877), UINT16_C(36677), UINT16_C(64508), UINT16_C(27487), UINT16_C(60431), UINT16_C(11673), UINT16_C(51648), UINT16_C(12420),
      UINT16_C(28658), UINT16_C(37287), UINT16_C(45169), UINT16_C( 9556), UINT16_C(43192), UINT16_C(25168), UINT16_C(44754), UINT16_C(57436),
      UINT16_C(49536), UINT16_C(48495), UINT16_C(50099), UINT16_C(49748), UINT16_C(15279), UINT16_C(49076), UINT16_C(21210), UINT16_C(44334),
      UINT16_C(36281), UINT16_C( 5530), UINT16_C(37509), UINT16_C(16337), UINT16_C(13728), UINT16_C(20385), UINT16_C(17539), UINT16_C( 1226),
      UINT16_C(30726), UINT16_C(14926), UINT16_C(13627), UINT16_C(27840), UINT16_C(29752), UINT16_C(19432), UINT16_C(62654), UINT16_C(52984),
      UINT16_C(14060), UINT16_C(29042), UINT16_C(24496), UINT16_C(11591), UINT16_C( 8305), UINT16_C(62493), UINT16_C(59236), UINT16_C(27384),
      UINT16_C(55647), UINT16_C(47549), UINT16_C(32421), UINT16_C(56614), UINT16_C(28394), UINT16_C(34505), UINT16_C(57926), UINT16_C(51241),
      UINT16_C(51191), UINT16_C(28368), UINT16_C(36099), UINT16_C(38555), UINT16_C( 6144), UINT16_C( 4712), UINT16_C(50885), UINT16_C( 4201),
      UINT16_C(41018), UINT16_C(18471), UINT16_C(44352), UINT16_C(10950), UINT16_C(36891), UINT16_C(34632), UINT16_C(29178), UINT16_C(18704),
      UINT16_C( 8232), UINT16_C(15654), UINT16_C(49464), UINT16_C(11587), UINT16_C(43896), UINT16_C(40734), UINT16_C(34944), UINT16_C(30127),
      UINT16_C(31151), UINT16_C(40078), UINT16_C(21766), UINT16_C( 8647), UINT16_C(30693), UINT16_C(39218), UINT16_C(33445), UINT16_C(18559),
      UINT16_C(35010), UINT16_C(16919), UINT16_C(23226), UINT16_C( 4882), UINT16_C(12696), UINT16_C( 6322), UINT16_C( 2409), UINT16_C(26765),
      UINT16_C(40155), UINT16_C(17596), UINT16_C(10556), UINT16_C( 8585), UINT16_C(18848), UINT16_C(33115), UINT16_C(44196), UINT16_C(17998),
      UINT16_C(22820), UINT16_C( 6686), UINT16_C(36311), UINT16_C(53360), UINT16_C( 8803), UINT16_C( 7400), UINT16_C(18733), UINT16_C(36714),
      UINT16_C(16401), UINT16_C(13219), UINT16_C(33013), UINT16_C(38542), UINT16_C(59082), UINT16_C(22596), UINT16_C( 6334), UINT16_C( 8350),
      UINT16_C(57237), UINT16_C(27960), UINT16_C(60913), UINT16_C(21748), UINT16_C(56335), UINT16_C(37745), UINT16_C(46979), UINT16_C(25329),
      UINT16_C(24196), UINT16_C( 7830), UINT16_C(45023), UINT16_C(56289), UINT16_C(49814), UINT16_C(21645), UINT16_C(53945), UINT16_C(42488),
      UINT16_C(43564), UINT16_C(33482), UINT16_C(10288), UINT16_C(55873), UINT16_C(18331), UINT16_C(60421), UINT16_C(63293), UINT16_C(51610),
      UINT16_C(47991), UINT16_C(22083), UINT16_C(21098), UINT16_C(19342), UINT16_C(35861), UINT16_C(20770), UINT16_C(50905), UINT16_C( 9719),
      UINT16_C(49552), UINT16_C(41375), UINT16_C(57446), UINT16_C(51323), UINT16_C(11374), UINT16_C(45998), UINT16_C(18501) };

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
    rv = simde_svsel_u16(pv, av, bv);

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

    ev = simde_svsel_u16(pv, av, bv);

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
test_simde_x_svsel_u32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0) };
  static const uint32_t a[] =
    { UINT32_C( 668613441), UINT32_C( 918699407), UINT32_C(1144232705), UINT32_C( 365275576), UINT32_C(2443268066), UINT32_C(3019962674), UINT32_C(1889138671), UINT32_C(2195576641),
      UINT32_C(2712320018), UINT32_C(4141313269), UINT32_C(3208317703), UINT32_C(2547253428), UINT32_C(2166912591), UINT32_C(1580607855), UINT32_C(1641008928), UINT32_C(3101928614),
      UINT32_C(1499041124), UINT32_C(  22032890), UINT32_C(4039215932), UINT32_C(3666318731), UINT32_C(2052829195), UINT32_C(4191785433), UINT32_C( 123381857), UINT32_C(3116383572),
      UINT32_C(3306297803), UINT32_C(2261148234), UINT32_C(2021099501), UINT32_C( 676527645), UINT32_C(2275651246), UINT32_C(2692774975), UINT32_C(2024331812), UINT32_C(3811665944),
      UINT32_C(3433579649), UINT32_C(2488430246), UINT32_C( 319605238), UINT32_C(1983602632), UINT32_C(1291771405), UINT32_C(2129493594), UINT32_C(1912051033), UINT32_C(2119444733),
      UINT32_C( 323681388), UINT32_C(1621597546), UINT32_C( 779334502), UINT32_C( 530951954), UINT32_C(3899433869), UINT32_C(2053527841), UINT32_C(3958070766), UINT32_C(4066983814),
      UINT32_C(2785391675), UINT32_C(3070667857), UINT32_C(1927707232), UINT32_C(3063057193), UINT32_C(1335819822), UINT32_C(1170867543), UINT32_C(3895506274), UINT32_C( 819698165),
      UINT32_C(2664882253), UINT32_C(3981893005), UINT32_C(2153725015), UINT32_C(4114018759), UINT32_C(1178916335), UINT32_C(1015746266), UINT32_C(3106257860), UINT32_C(2733178965),
      UINT32_C(1833025760), UINT32_C(4099577757), UINT32_C(2591341267), UINT32_C(2609883819), UINT32_C(1507971967), UINT32_C(2794876386), UINT32_C(2103425832), UINT32_C(2602584251),
      UINT32_C(2768855304), UINT32_C(3415827448), UINT32_C(3378842909), UINT32_C( 929363128), UINT32_C(2844870087), UINT32_C(3679397810), UINT32_C(2639834850), UINT32_C(4281891063),
      UINT32_C(3517268441), UINT32_C(3265019557), UINT32_C(  76218700), UINT32_C(3174821877), UINT32_C(3882273845), UINT32_C(3586307827), UINT32_C(1534204772), UINT32_C(1834724243),
      UINT32_C(2436759788), UINT32_C(2320816958), UINT32_C(3532578780), UINT32_C(  76532431), UINT32_C(2330719638), UINT32_C( 274706091), UINT32_C(1550570185), UINT32_C(1774831229),
      UINT32_C( 100337862), UINT32_C(3213840355), UINT32_C(4254146094), UINT32_C(2114003176), UINT32_C(3238587670), UINT32_C(1691445403), UINT32_C(3082829114), UINT32_C(3391130115),
      UINT32_C(1976507282), UINT32_C(2570346090), UINT32_C(1687602812), UINT32_C(4242774246), UINT32_C( 549383045), UINT32_C(2374274899), UINT32_C(3494134988), UINT32_C(1620731342),
      UINT32_C(3956631936), UINT32_C(1149504199), UINT32_C(3064470224), UINT32_C( 934513586), UINT32_C(3394728311), UINT32_C(3445152512), UINT32_C(4003306528), UINT32_C(2186229505),
      UINT32_C(1735206048), UINT32_C(4272681262), UINT32_C(3199554571), UINT32_C(1458923743), UINT32_C(3642838489), UINT32_C(1218869544), UINT32_C( 389497621), UINT32_C( 446269050),
      UINT32_C(3649177258), UINT32_C(  47656439), UINT32_C(1640008833), UINT32_C(3451369204), UINT32_C( 732420099), UINT32_C(1735675217), UINT32_C( 192850833), UINT32_C(3676706609),
      UINT32_C( 347383837), UINT32_C(1461095637), UINT32_C( 230217496), UINT32_C(2430234509), UINT32_C(2579202376), UINT32_C(1610624975), UINT32_C( 191594202), UINT32_C(3001520533),
      UINT32_C( 264674105), UINT32_C(1080483111), UINT32_C(1095573172) };
  static const uint32_t e[] =
    { UINT32_C( 668613441), UINT32_C(         0), UINT32_C(1144232705), UINT32_C(         0), UINT32_C(2443268066), UINT32_C(         0), UINT32_C(1889138671), UINT32_C(         0),
      UINT32_C(2712320018), UINT32_C(4141313269), UINT32_C(         0), UINT32_C(2547253428), UINT32_C(2166912591), UINT32_C(1580607855), UINT32_C(1641008928), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(2052829195), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(2021099501), UINT32_C(         0), UINT32_C(         0), UINT32_C(2692774975), UINT32_C(         0), UINT32_C(3811665944),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(1983602632), UINT32_C(         0), UINT32_C(         0), UINT32_C(1912051033), UINT32_C(2119444733),
      UINT32_C( 323681388), UINT32_C(1621597546), UINT32_C(         0), UINT32_C( 530951954), UINT32_C(         0), UINT32_C(         0), UINT32_C(3958070766), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(3070667857), UINT32_C(         0), UINT32_C(3063057193), UINT32_C(1335819822), UINT32_C(         0), UINT32_C(3895506274), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(3981893005), UINT32_C(2153725015), UINT32_C(         0), UINT32_C(1178916335), UINT32_C(1015746266), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(1507971967), UINT32_C(2794876386), UINT32_C(2103425832), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(3415827448), UINT32_C(         0), UINT32_C(         0), UINT32_C(2844870087), UINT32_C(3679397810), UINT32_C(2639834850), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(3265019557), UINT32_C(  76218700), UINT32_C(         0), UINT32_C(3882273845), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(2436759788), UINT32_C(2320816958), UINT32_C(3532578780), UINT32_C(         0), UINT32_C(         0), UINT32_C( 274706091), UINT32_C(         0), UINT32_C(1774831229),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(4254146094), UINT32_C(         0), UINT32_C(         0), UINT32_C(1691445403), UINT32_C(3082829114), UINT32_C(3391130115),
      UINT32_C(1976507282), UINT32_C(2570346090), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(3494134988), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(1149504199), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(4003306528), UINT32_C(2186229505),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(3199554571), UINT32_C(1458923743), UINT32_C(3642838489), UINT32_C(1218869544), UINT32_C( 389497621), UINT32_C( 446269050),
      UINT32_C(3649177258), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C( 347383837), UINT32_C(         0), UINT32_C( 230217496), UINT32_C(2430234509), UINT32_C(2579202376), UINT32_C(         0), UINT32_C( 191594202), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(1080483111), UINT32_C(         0) };

  static uint32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t
      rv,
      av = simde_svld1_u32(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_x_svsel_u32_z(pv, av);

    simde_svst1_u32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vu32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)];
  uint32_t a[1024 / sizeof(int32_t)], e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_u32(pg, &(a[i]));

    ev = simde_x_svsel_u32_z(pv, av);

    simde_svst1_u32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsel_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1) };
  static const uint32_t a[] =
    { UINT32_C(3373236512), UINT32_C( 311052208), UINT32_C(1774448506), UINT32_C(2756492807), UINT32_C(4181662750), UINT32_C(4137248572), UINT32_C(4106678114), UINT32_C(2551453560),
      UINT32_C(1214391448), UINT32_C(3847941227), UINT32_C(3813547740), UINT32_C(4219968220), UINT32_C(4092905398), UINT32_C(2448002606), UINT32_C(4119179133), UINT32_C(1586404038),
      UINT32_C( 698806462), UINT32_C(3087991260), UINT32_C(4221328671), UINT32_C(2935366648), UINT32_C( 430042090), UINT32_C(4138371705), UINT32_C(4293668665), UINT32_C(2271050441),
      UINT32_C(1186006122), UINT32_C( 620740613), UINT32_C( 354392861), UINT32_C(2848200382), UINT32_C(2059560193), UINT32_C( 695233776), UINT32_C(1697209499), UINT32_C(1089242838),
      UINT32_C(2408029578), UINT32_C(2075362909), UINT32_C(3750810401), UINT32_C(3934803177), UINT32_C(2858699450), UINT32_C(1389614262), UINT32_C( 129498161), UINT32_C( 222864259),
      UINT32_C(2661142337), UINT32_C(1981370453), UINT32_C( 206940707), UINT32_C(3103186686), UINT32_C(3747764776), UINT32_C(1613837871), UINT32_C(3043485746), UINT32_C(3435376523),
      UINT32_C(3547029630), UINT32_C(3561587888), UINT32_C( 769695534), UINT32_C(2783303549), UINT32_C(1619281969), UINT32_C(2965419390), UINT32_C( 694560925), UINT32_C(1458907607),
      UINT32_C( 959013001), UINT32_C( 319648741), UINT32_C(2403397138), UINT32_C(4130612933), UINT32_C(3965172078), UINT32_C( 211556206), UINT32_C( 389349951), UINT32_C(3027053099),
      UINT32_C(1894684299), UINT32_C( 461634313), UINT32_C(2930427113), UINT32_C(1487265770), UINT32_C( 105184408), UINT32_C(1393745939), UINT32_C( 241846243), UINT32_C(4257470322),
      UINT32_C(2003677549), UINT32_C(2526212268), UINT32_C(2655272372), UINT32_C(3036080412), UINT32_C(4189731557), UINT32_C(4266446107), UINT32_C(2248979988), UINT32_C(4202942349),
      UINT32_C( 762441856), UINT32_C(2512585953), UINT32_C(1563690817), UINT32_C(3591449329), UINT32_C(2161101669), UINT32_C(2910722968), UINT32_C(1580436177), UINT32_C(3663312730),
      UINT32_C(2282212007), UINT32_C( 253676238), UINT32_C(3278656210), UINT32_C(3784932732), UINT32_C(3781257545), UINT32_C(1452203908), UINT32_C(3300180586), UINT32_C( 547229049),
      UINT32_C(2796136152), UINT32_C(1119274864), UINT32_C(2500141593), UINT32_C(3916930976), UINT32_C(2362103816), UINT32_C( 585259448), UINT32_C(2498139931), UINT32_C(2092205220),
      UINT32_C(2602786090), UINT32_C(1037949220), UINT32_C(2614354939), UINT32_C(2323925634), UINT32_C(3658895138), UINT32_C(3288136104), UINT32_C( 878174864), UINT32_C(2444299111),
      UINT32_C(2368525417), UINT32_C(2831878829), UINT32_C(1866768109), UINT32_C( 184142056), UINT32_C(3219459863), UINT32_C(2558714120), UINT32_C( 734910916), UINT32_C(1320976101),
      UINT32_C(4292602194), UINT32_C(3769083635), UINT32_C( 743435076), UINT32_C(3409397940), UINT32_C(1619729495), UINT32_C(3254259197), UINT32_C(3438069223), UINT32_C(2501552451),
      UINT32_C(2241131922), UINT32_C(3764731036), UINT32_C(3675108391), UINT32_C(1403471100), UINT32_C(1572024928), UINT32_C( 639609919), UINT32_C(3052538737), UINT32_C(1179258036),
      UINT32_C(2664161026), UINT32_C(1115566107), UINT32_C(3760098276), UINT32_C( 791987663), UINT32_C( 915269623), UINT32_C(  90025107), UINT32_C(1824149431), UINT32_C(1588724828),
      UINT32_C(4277960419), UINT32_C(2470541998), UINT32_C(3581107974), UINT32_C( 453355300), UINT32_C( 575771279), UINT32_C(4113018430), UINT32_C(1516364286), UINT32_C(3384284390),
      UINT32_C(1086895250), UINT32_C( 886245678), UINT32_C(2349483880), UINT32_C(2108100590), UINT32_C(3751868577), UINT32_C(2782185383), UINT32_C(2415867561), UINT32_C(3696801610),
      UINT32_C(2568757355), UINT32_C(2446258217), UINT32_C( 622712887), UINT32_C(2292434151), UINT32_C(1684489149), UINT32_C(3003726602), UINT32_C(3141666929), UINT32_C( 714578879),
      UINT32_C(3854808251), UINT32_C(3681980836), UINT32_C(1342215273), UINT32_C( 366519128), UINT32_C(4051255270), UINT32_C(3970204283), UINT32_C(1235806090), UINT32_C(1030963074),
      UINT32_C(2535602163), UINT32_C( 846371272), UINT32_C(2239918893), UINT32_C(4254817046), UINT32_C( 367924378), UINT32_C( 553816727), UINT32_C(4218137209), UINT32_C(3711557353),
      UINT32_C(3732167445), UINT32_C( 554756084), UINT32_C(1890030170), UINT32_C(2288861933), UINT32_C(3986512726), UINT32_C(1729077230), UINT32_C( 862157385), UINT32_C(1846582360),
      UINT32_C(3964437751), UINT32_C(3305987179), UINT32_C(3694572782), UINT32_C(1298441206), UINT32_C(3980001791), UINT32_C(3931392417), UINT32_C( 471709635), UINT32_C(1267346771),
      UINT32_C( 490198706), UINT32_C( 551765042), UINT32_C(4026276345), UINT32_C(3141296316), UINT32_C(  61372258), UINT32_C(2230189504), UINT32_C( 144706484), UINT32_C(3931318840),
      UINT32_C( 839420416), UINT32_C(3344100302), UINT32_C(3233238788), UINT32_C( 293401519), UINT32_C( 722740330), UINT32_C(3601793569), UINT32_C(1172197133), UINT32_C(2033201529),
      UINT32_C(2309699771), UINT32_C( 659684643), UINT32_C(4242999372) };
  static const uint32_t b[] =
    { UINT32_C(2832522612), UINT32_C(2554974658), UINT32_C(  43092909), UINT32_C( 152108098), UINT32_C(3597745546), UINT32_C(2591193198), UINT32_C(2601740335), UINT32_C(3601946465),
      UINT32_C(4135487028), UINT32_C(  76531799), UINT32_C(2500206675), UINT32_C(2795378460), UINT32_C(3262910292), UINT32_C(3059543943), UINT32_C(3092344919), UINT32_C(4220388295),
      UINT32_C(3773894025), UINT32_C( 686129365), UINT32_C(3183340448), UINT32_C(1449351938), UINT32_C(4044939370), UINT32_C( 648508879), UINT32_C(2900294117), UINT32_C(2242342396),
      UINT32_C(1332058234), UINT32_C(3111602713), UINT32_C( 947270710), UINT32_C(4186954383), UINT32_C(2313856954), UINT32_C(  28283164), UINT32_C(2259520906), UINT32_C(1946899706),
      UINT32_C( 113471981), UINT32_C(4055841467), UINT32_C(4247402094), UINT32_C(3405166864), UINT32_C(2102648928), UINT32_C(4236116594), UINT32_C(2323852431), UINT32_C(1845399168),
      UINT32_C(3144925951), UINT32_C(1806447612), UINT32_C(2036913769), UINT32_C(4030947215), UINT32_C(2976749119), UINT32_C( 665775000), UINT32_C(2561749271), UINT32_C(3204821183),
      UINT32_C(1853520242), UINT32_C( 366552748), UINT32_C(2358133501), UINT32_C(3766276513), UINT32_C(4287818087), UINT32_C(3961929941), UINT32_C( 814012529), UINT32_C(4210002568),
      UINT32_C(2942855427), UINT32_C(2378449552), UINT32_C( 622416516), UINT32_C(2315621923), UINT32_C(1418303359), UINT32_C(1212264407), UINT32_C( 259638663), UINT32_C(1376348239),
      UINT32_C(1644262098), UINT32_C( 955237812), UINT32_C( 979175447), UINT32_C( 516186782), UINT32_C(3513929210), UINT32_C(2216342525), UINT32_C(3365180281), UINT32_C(3441139195),
      UINT32_C(3274644495), UINT32_C(4193984226), UINT32_C(3308541991), UINT32_C(3051616443), UINT32_C(1132877382), UINT32_C(2194120713), UINT32_C( 793467699), UINT32_C( 150759161),
      UINT32_C(1691102338), UINT32_C(1902036810), UINT32_C(3677852192), UINT32_C(3499104906), UINT32_C(2048071280), UINT32_C(3942439863), UINT32_C( 790185782), UINT32_C( 808982189),
      UINT32_C(2358510658), UINT32_C(3959354059), UINT32_C( 264648068), UINT32_C(3235862095), UINT32_C( 607843181), UINT32_C(  68040398), UINT32_C( 724838526), UINT32_C(2153475134),
      UINT32_C( 990703728), UINT32_C(1730611938), UINT32_C(2406935871), UINT32_C(2974766404), UINT32_C( 383093064), UINT32_C(1025237951), UINT32_C(1231638283), UINT32_C( 734643387),
      UINT32_C(2540099252), UINT32_C( 553553376), UINT32_C(3215946875), UINT32_C( 309395145), UINT32_C(1177044359), UINT32_C( 881083176), UINT32_C(1300098450), UINT32_C(1719158705),
      UINT32_C(4261273373), UINT32_C(3877501804), UINT32_C( 950455407), UINT32_C(1363809994), UINT32_C(2224583515), UINT32_C(1236802742), UINT32_C(3130406153), UINT32_C(2569015164),
      UINT32_C(1519853038), UINT32_C(2269295640), UINT32_C(1270933633), UINT32_C(1520241407), UINT32_C( 886977917), UINT32_C(1518179921), UINT32_C(1209275340), UINT32_C( 283260194),
      UINT32_C(1802205522), UINT32_C(2935139629), UINT32_C(2499457685), UINT32_C( 988780477), UINT32_C( 493800908), UINT32_C( 813165412), UINT32_C( 561548287), UINT32_C( 322067136),
      UINT32_C(  25075155), UINT32_C(3752816714), UINT32_C(3765741859), UINT32_C( 203055936), UINT32_C(2485750064), UINT32_C(1942265972), UINT32_C(3969203500), UINT32_C(1811924887),
      UINT32_C(2926345572), UINT32_C( 294460398), UINT32_C(  99680709), UINT32_C(2500987748), UINT32_C( 153697172), UINT32_C( 142405340), UINT32_C(3270775083), UINT32_C(1009644760),
      UINT32_C(1609210225), UINT32_C(2054191285), UINT32_C(3732889977), UINT32_C(  24351085), UINT32_C(2836045005), UINT32_C(3048310666), UINT32_C(1903732120), UINT32_C( 195929497),
      UINT32_C(4100626495), UINT32_C(2305743632), UINT32_C(2842160444), UINT32_C(1286331007), UINT32_C(  32879991), UINT32_C(3585582652), UINT32_C(3846582091), UINT32_C( 334558164),
      UINT32_C(2600950411), UINT32_C(1915057461), UINT32_C(3793456227), UINT32_C(3727607399), UINT32_C(3101631356), UINT32_C( 344823497), UINT32_C(2600063941), UINT32_C(1387129287),
      UINT32_C(2045687108), UINT32_C(2380993322), UINT32_C( 107939743), UINT32_C(1239719373), UINT32_C(2298660032), UINT32_C( 547262298), UINT32_C( 716871523), UINT32_C(3313264513),
      UINT32_C(1195272732), UINT32_C( 500443773), UINT32_C(4263724081), UINT32_C(2722629857), UINT32_C( 640371404), UINT32_C(1011272153), UINT32_C(3798335585), UINT32_C(2225595240),
      UINT32_C(3419137357), UINT32_C(1088987151), UINT32_C(3309243364), UINT32_C(3748103955), UINT32_C(2852557777), UINT32_C(3186052188), UINT32_C(3047116109), UINT32_C(2117682736),
      UINT32_C( 994641196), UINT32_C(2306617765), UINT32_C(1347337020), UINT32_C( 321893954), UINT32_C(2780640585), UINT32_C(3479413890), UINT32_C( 579076850), UINT32_C(1973468489),
      UINT32_C(1739647426), UINT32_C(1475357722), UINT32_C( 698826727), UINT32_C(1044174581), UINT32_C(2397305356), UINT32_C(2422032030), UINT32_C(2461262153), UINT32_C(1627870110),
      UINT32_C(1472771901), UINT32_C(3417225700), UINT32_C(3992278520) };
  static const uint32_t e[] =
    { UINT32_C(2832522612), UINT32_C( 311052208), UINT32_C(  43092909), UINT32_C(2756492807), UINT32_C(3597745546), UINT32_C(4137248572), UINT32_C(2601740335), UINT32_C(3601946465),
      UINT32_C(1214391448), UINT32_C(  76531799), UINT32_C(3813547740), UINT32_C(2795378460), UINT32_C(4092905398), UINT32_C(2448002606), UINT32_C(3092344919), UINT32_C(4220388295),
      UINT32_C( 698806462), UINT32_C( 686129365), UINT32_C(3183340448), UINT32_C(1449351938), UINT32_C(4044939370), UINT32_C(4138371705), UINT32_C(2900294117), UINT32_C(2242342396),
      UINT32_C(1332058234), UINT32_C(3111602713), UINT32_C( 947270710), UINT32_C(2848200382), UINT32_C(2059560193), UINT32_C(  28283164), UINT32_C(2259520906), UINT32_C(1089242838),
      UINT32_C( 113471981), UINT32_C(4055841467), UINT32_C(3750810401), UINT32_C(3405166864), UINT32_C(2102648928), UINT32_C(4236116594), UINT32_C( 129498161), UINT32_C(1845399168),
      UINT32_C(2661142337), UINT32_C(1981370453), UINT32_C(2036913769), UINT32_C(3103186686), UINT32_C(2976749119), UINT32_C(1613837871), UINT32_C(2561749271), UINT32_C(3204821183),
      UINT32_C(1853520242), UINT32_C(3561587888), UINT32_C( 769695534), UINT32_C(3766276513), UINT32_C(4287818087), UINT32_C(3961929941), UINT32_C( 814012529), UINT32_C(1458907607),
      UINT32_C( 959013001), UINT32_C( 319648741), UINT32_C( 622416516), UINT32_C(2315621923), UINT32_C(3965172078), UINT32_C(1212264407), UINT32_C( 259638663), UINT32_C(1376348239),
      UINT32_C(1894684299), UINT32_C( 461634313), UINT32_C(2930427113), UINT32_C( 516186782), UINT32_C(3513929210), UINT32_C(1393745939), UINT32_C(3365180281), UINT32_C(4257470322),
      UINT32_C(3274644495), UINT32_C(4193984226), UINT32_C(2655272372), UINT32_C(3051616443), UINT32_C(4189731557), UINT32_C(2194120713), UINT32_C(2248979988), UINT32_C(4202942349),
      UINT32_C( 762441856), UINT32_C(2512585953), UINT32_C(1563690817), UINT32_C(3591449329), UINT32_C(2161101669), UINT32_C(2910722968), UINT32_C( 790185782), UINT32_C(3663312730),
      UINT32_C(2282212007), UINT32_C(3959354059), UINT32_C(3278656210), UINT32_C(3235862095), UINT32_C( 607843181), UINT32_C(  68040398), UINT32_C( 724838526), UINT32_C(2153475134),
      UINT32_C( 990703728), UINT32_C(1730611938), UINT32_C(2406935871), UINT32_C(3916930976), UINT32_C(2362103816), UINT32_C(1025237951), UINT32_C(1231638283), UINT32_C( 734643387),
      UINT32_C(2602786090), UINT32_C( 553553376), UINT32_C(2614354939), UINT32_C(2323925634), UINT32_C(3658895138), UINT32_C( 881083176), UINT32_C(1300098450), UINT32_C(1719158705),
      UINT32_C(2368525417), UINT32_C(3877501804), UINT32_C(1866768109), UINT32_C( 184142056), UINT32_C(3219459863), UINT32_C(2558714120), UINT32_C( 734910916), UINT32_C(2569015164),
      UINT32_C(4292602194), UINT32_C(2269295640), UINT32_C( 743435076), UINT32_C(3409397940), UINT32_C(1619729495), UINT32_C(1518179921), UINT32_C(1209275340), UINT32_C(2501552451),
      UINT32_C(1802205522), UINT32_C(3764731036), UINT32_C(2499457685), UINT32_C(1403471100), UINT32_C(1572024928), UINT32_C( 639609919), UINT32_C( 561548287), UINT32_C( 322067136),
      UINT32_C(2664161026), UINT32_C(3752816714), UINT32_C(3760098276), UINT32_C( 791987663), UINT32_C( 915269623), UINT32_C(  90025107), UINT32_C(3969203500), UINT32_C(1588724828),
      UINT32_C(4277960419), UINT32_C(2470541998), UINT32_C(3581107974), UINT32_C(2500987748), UINT32_C( 575771279), UINT32_C( 142405340), UINT32_C(1516364286), UINT32_C(1009644760),
      UINT32_C(1086895250), UINT32_C(2054191285), UINT32_C(2349483880), UINT32_C(2108100590), UINT32_C(3751868577), UINT32_C(2782185383), UINT32_C(2415867561), UINT32_C( 195929497),
      UINT32_C(2568757355), UINT32_C(2446258217), UINT32_C( 622712887), UINT32_C(1286331007), UINT32_C(  32879991), UINT32_C(3003726602), UINT32_C(3141666929), UINT32_C( 714578879),
      UINT32_C(3854808251), UINT32_C(3681980836), UINT32_C(3793456227), UINT32_C(3727607399), UINT32_C(3101631356), UINT32_C(3970204283), UINT32_C(1235806090), UINT32_C(1030963074),
      UINT32_C(2045687108), UINT32_C(2380993322), UINT32_C(2239918893), UINT32_C(4254817046), UINT32_C(2298660032), UINT32_C( 553816727), UINT32_C(4218137209), UINT32_C(3711557353),
      UINT32_C(3732167445), UINT32_C( 500443773), UINT32_C(4263724081), UINT32_C(2722629857), UINT32_C(3986512726), UINT32_C(1729077230), UINT32_C( 862157385), UINT32_C(1846582360),
      UINT32_C(3964437751), UINT32_C(3305987179), UINT32_C(3309243364), UINT32_C(3748103955), UINT32_C(3980001791), UINT32_C(3186052188), UINT32_C( 471709635), UINT32_C(1267346771),
      UINT32_C( 994641196), UINT32_C( 551765042), UINT32_C(4026276345), UINT32_C( 321893954), UINT32_C(2780640585), UINT32_C(3479413890), UINT32_C( 579076850), UINT32_C(3931318840),
      UINT32_C(1739647426), UINT32_C(1475357722), UINT32_C(3233238788), UINT32_C( 293401519), UINT32_C( 722740330), UINT32_C(3601793569), UINT32_C(1172197133), UINT32_C(1627870110),
      UINT32_C(1472771901), UINT32_C( 659684643), UINT32_C(4242999372) };

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
    rv = simde_svsel_u32(pv, av, bv);

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

    ev = simde_svsel_u32(pv, av, bv);

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
test_simde_x_svsel_u64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) };
  static const uint64_t a[] =
    { UINT64_C( 3990284006355194071), UINT64_C( 8421130759311142913), UINT64_C( 9559091245813112790), UINT64_C(13235387575090727290),
      UINT64_C(13707733217288021723), UINT64_C(14563118318257510103), UINT64_C( 9768575928644687413), UINT64_C(15876403653769459645),
      UINT64_C( 1743487073205132215), UINT64_C(13254331752563796786), UINT64_C(17132629973585312814), UINT64_C( 8118265792405661643),
      UINT64_C(15624137908349602170), UINT64_C(11041399577700635137), UINT64_C( 2037763732080491818), UINT64_C( 3181954433041421055),
      UINT64_C( 2709404612114779419), UINT64_C(12633690443694511951), UINT64_C(13712705222504687583), UINT64_C(16429587501036221987),
      UINT64_C(17794916918111890091), UINT64_C( 6703893361539980501), UINT64_C( 9631190120531890731), UINT64_C( 7547853466699963922),
      UINT64_C( 8638796488991269958), UINT64_C(14025012532831425735), UINT64_C( 2293550526369640940), UINT64_C(15030686284533870194),
      UINT64_C(13850435798060355101), UINT64_C(14812242287677212469), UINT64_C(  145787068069198808), UINT64_C(15454604296031698718),
      UINT64_C(  959210476147193750), UINT64_C(15313198592581784788), UINT64_C(12481374039089782692), UINT64_C(14361645168310249662),
      UINT64_C( 9578213786101670919), UINT64_C(15189442177634321914), UINT64_C(  186965651234391388), UINT64_C(14311534442122506148),
      UINT64_C(10655958276910740140), UINT64_C( 3771295026882616150), UINT64_C( 4404722303814819033), UINT64_C( 1021101478155295398),
      UINT64_C(13316101079174926497), UINT64_C( 9543852919749367398), UINT64_C(17277709542022549999), UINT64_C( 2939584502274840667),
      UINT64_C(16747249298908984913), UINT64_C( 3004632376570980228), UINT64_C( 8170506182510924842), UINT64_C( 9943941624292620368),
      UINT64_C( 1412343094241419568), UINT64_C( 9489634555204845645), UINT64_C( 3156560287054127944), UINT64_C( 2869922123663801618),
      UINT64_C(  289763881119125603), UINT64_C( 9443551695084406578), UINT64_C( 8189425797038081439), UINT64_C( 1137880922725329324),
      UINT64_C( 5069372114482602656), UINT64_C(13982797382024291918), UINT64_C( 5167566778963651813), UINT64_C(11693231404135117451),
      UINT64_C(11291178812055308119), UINT64_C( 5268702916887544633), UINT64_C(14411875314459105822), UINT64_C(17824197981843221431),
      UINT64_C(16318815965244708237), UINT64_C(17096892133748415896), UINT64_C(14896965388748640950), UINT64_C(10244249896706620307),
      UINT64_C( 4162418566008245304), UINT64_C( 1385834751997510015), UINT64_C( 2031338426766713163), UINT64_C(15280002819500783742),
      UINT64_C(15555283960110348037), UINT64_C(15630130144065426553), UINT64_C( 3668018841469579330), UINT64_C(13011954509959738915),
      UINT64_C( 4136057906482858038), UINT64_C( 3365588517723802446), UINT64_C( 9137487373766619113), UINT64_C( 8465025946930216982),
      UINT64_C( 6706256836900934680), UINT64_C(   76540409802203381), UINT64_C(18353414126046152924), UINT64_C(15681600702864683500),
      UINT64_C(  179512921803564049), UINT64_C( 9222512923067528930), UINT64_C(17573162328100608762), UINT64_C(17435615451670356828),
      UINT64_C( 5580960955351804003), UINT64_C( 4929265975888992069), UINT64_C(16490501270128697055), UINT64_C( 2052508626182142378),
      UINT64_C( 6942861891719761057), UINT64_C(14404113492104225367), UINT64_C(13635640809644428238), UINT64_C(15588580322869460352),
      UINT64_C( 4236267541672288847), UINT64_C(10560871598328058849), UINT64_C( 5015643037979196875), UINT64_C(17685868444865454690),
      UINT64_C( 8417555991920334261), UINT64_C( 4076545376956296253), UINT64_C(  149658516843821833) };
  static const uint64_t e[] =
    { UINT64_C(                   0), UINT64_C( 8421130759311142913), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(13707733217288021723), UINT64_C(14563118318257510103), UINT64_C(                   0), UINT64_C(15876403653769459645),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(11041399577700635137), UINT64_C(                   0), UINT64_C( 3181954433041421055),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 9631190120531890731), UINT64_C( 7547853466699963922),
      UINT64_C(                   0), UINT64_C(14025012532831425735), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(13850435798060355101), UINT64_C(14812242287677212469), UINT64_C(  145787068069198808), UINT64_C(                   0),
      UINT64_C(  959210476147193750), UINT64_C(                   0), UINT64_C(12481374039089782692), UINT64_C(14361645168310249662),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 3771295026882616150), UINT64_C(                   0), UINT64_C( 1021101478155295398),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(17277709542022549999), UINT64_C(                   0),
      UINT64_C(16747249298908984913), UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 9943941624292620368),
      UINT64_C(                   0), UINT64_C( 9489634555204845645), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 5167566778963651813), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 5268702916887544633), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 1385834751997510015), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(15555283960110348037), UINT64_C(15630130144065426553), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 9137487373766619113), UINT64_C( 8465025946930216982),
      UINT64_C( 6706256836900934680), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(15681600702864683500),
      UINT64_C(  179512921803564049), UINT64_C( 9222512923067528930), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 4929265975888992069), UINT64_C(                   0), UINT64_C( 2052508626182142378),
      UINT64_C(                   0), UINT64_C(14404113492104225367), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(10560871598328058849), UINT64_C(                   0), UINT64_C(17685868444865454690),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0) };

  static uint64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t
      rv,
      av = simde_svld1_u64(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_x_svsel_u64_z(pv, av);

    simde_svst1_u64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vu64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)];
  uint64_t a[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_u64(pg, &(a[i]));

    ev = simde_x_svsel_u64_z(pv, av);

    simde_svst1_u64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsel_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0) };
  static const uint64_t a[] =
    { UINT64_C( 8743439831172825698), UINT64_C(13480983336872016282), UINT64_C(17589964038186505008), UINT64_C(14498003536034681602),
      UINT64_C(14677445801734390019), UINT64_C( 3090115827806299964), UINT64_C(   65904722506605534), UINT64_C(16403852430803836534),
      UINT64_C( 1327939388823901041), UINT64_C(14687394992339133104), UINT64_C( 8429801709886364414), UINT64_C(11100518937720387914),
      UINT64_C(11597519937668392458), UINT64_C( 4973133175481576268), UINT64_C(13432617493474690552), UINT64_C(13617742547222051639),
      UINT64_C( 3361531273303308310), UINT64_C(  451603574802608313), UINT64_C(18112183321101108784), UINT64_C( 5084379466757324577),
      UINT64_C( 8259868594897955728), UINT64_C(11742773683191678946), UINT64_C( 8934188766378259260), UINT64_C( 4635011814219733212),
      UINT64_C( 8229574675801480713), UINT64_C(11127647418464773977), UINT64_C( 3035592508594434123), UINT64_C( 6260153344731803375),
      UINT64_C( 4550974171967492902), UINT64_C( 3381773283669740278), UINT64_C( 1197943346645141800), UINT64_C( 9440829450912585057),
      UINT64_C( 7009959932346309923), UINT64_C(17509050642267984619), UINT64_C( 2548482970258820909), UINT64_C(14032888364501372637),
      UINT64_C( 4953699389694277618), UINT64_C( 5053617233206605157), UINT64_C( 8053547270225038045), UINT64_C( 6656715431873188864),
      UINT64_C(11888511530452003935), UINT64_C(18108682855777570799), UINT64_C(15457020040827298689), UINT64_C(17489965081293040882),
      UINT64_C(15917313095461663490), UINT64_C( 3660919286444374710), UINT64_C(13313142730160236821), UINT64_C( 1043371717396018932),
      UINT64_C( 9370078551259161920), UINT64_C( 3878201947355213294), UINT64_C(15351893583382714509), UINT64_C( 3256621419066105879),
      UINT64_C(11766326604565479676), UINT64_C( 5883131322158981200), UINT64_C(13682692845144950060), UINT64_C( 1435541170613665745),
      UINT64_C(18079743216837150353), UINT64_C( 7843879941575420870), UINT64_C(   87638981528354772), UINT64_C(13385730708727601050),
      UINT64_C(10058481653707153394), UINT64_C(16554933233147773202), UINT64_C( 3215736789937370991), UINT64_C(18271279660968730798),
      UINT64_C( 9912194592602165055), UINT64_C(  227037693267911729), UINT64_C(14667734829880280784), UINT64_C( 5380731780085214115),
      UINT64_C(12088749324629853890), UINT64_C(  583232885304630913), UINT64_C(11708789482838539157), UINT64_C( 1565561979791286372),
      UINT64_C( 7305140844159240004), UINT64_C(17145647266442922416), UINT64_C(13470298737676868686), UINT64_C( 9486238052266885437),
      UINT64_C(13201350159813702890), UINT64_C(10389400004616761320), UINT64_C( 2881405367149841900), UINT64_C(17569207386604250383),
      UINT64_C(10813132459013705809), UINT64_C( 3132259312866930341), UINT64_C( 3739229197142152914), UINT64_C( 5371200036069874831),
      UINT64_C(16765407464490421349), UINT64_C( 6398005963677270368), UINT64_C( 3528001455767500958), UINT64_C( 3664050814676662422),
      UINT64_C(10217241684992162975), UINT64_C( 9245881114179705456), UINT64_C(17582396400103220271), UINT64_C(13452072984630249904),
      UINT64_C( 6094610424800277721), UINT64_C(16601564240994353153), UINT64_C(10327238690026792958), UINT64_C(  817327683431880065),
      UINT64_C( 6694782654519309231), UINT64_C(14628998690472211302), UINT64_C(17634260450993027915), UINT64_C( 3498425549675611471) };
  static const uint64_t b[] =
    { UINT64_C(10860199373221100477), UINT64_C( 5455859126829494810), UINT64_C( 5026940001016879901), UINT64_C(18245425971760634727),
      UINT64_C( 4657561101175945281), UINT64_C( 1797260588568535213), UINT64_C( 8130094681030902081), UINT64_C( 6106988931716107650),
      UINT64_C(12447951566934049882), UINT64_C(10877675610559360994), UINT64_C( 9331167053272520709), UINT64_C( 7613901484429913155),
      UINT64_C(17128219672645798407), UINT64_C( 5747647870476617176), UINT64_C( 2402913246561298392), UINT64_C(11961880154109090696),
      UINT64_C( 7792740919940082220), UINT64_C( 9799372848351604581), UINT64_C(13854117226637843268), UINT64_C(  619061179735063121),
      UINT64_C(  667488928441320515), UINT64_C( 9190358354184691028), UINT64_C(17296607212384413714), UINT64_C(18195800033014604191),
      UINT64_C( 9036779593764422843), UINT64_C(16910748148937335284), UINT64_C(15312868983308505332), UINT64_C(10832515938454037406),
      UINT64_C( 3692492368108660631), UINT64_C(13709539776433143680), UINT64_C( 5794958109538612578), UINT64_C( 2713414987625839158),
      UINT64_C( 8905064500309695523), UINT64_C( 7740584990858278883), UINT64_C(14379269651530169738), UINT64_C( 6186678364604478759),
      UINT64_C(14452417226020995355), UINT64_C(  339988207979816003), UINT64_C( 5689961842626115998), UINT64_C( 7533077749913865732),
      UINT64_C(15081447452156314015), UINT64_C( 4824153050918535797), UINT64_C(  433303250489389966), UINT64_C( 9577686246591497781),
      UINT64_C(17250569407664056583), UINT64_C(16716746471396705047), UINT64_C(  723847902394084867), UINT64_C( 1445503805940320165),
      UINT64_C( 9604224642691176672), UINT64_C(18073576385309320851), UINT64_C(12937165032201875115), UINT64_C( 7814673944194913874),
      UINT64_C(13787505469407239524), UINT64_C( 9162148842167834422), UINT64_C( 9488109362703443692), UINT64_C(11211804963491736223),
      UINT64_C(11844120049431174770), UINT64_C( 8335872120304175451), UINT64_C(15407123521245850909), UINT64_C( 8922923922811302659),
      UINT64_C( 6920194266997866999), UINT64_C(17112620647823956354), UINT64_C(  357204944421120234), UINT64_C( 9602539234938255039),
      UINT64_C( 6321633124630027604), UINT64_C( 8181875623067666893), UINT64_C(10577697493449098949), UINT64_C( 8039379549329951101),
      UINT64_C( 4334577682634865914), UINT64_C( 3009923407545010380), UINT64_C( 6670319089546712875), UINT64_C( 9462055712682732484),
      UINT64_C( 7431356769635604597), UINT64_C(10129018188478544643), UINT64_C(    4815022161822167), UINT64_C(16722760915243464967),
      UINT64_C(16522000465715357510), UINT64_C( 6618001737712927978), UINT64_C( 9554987482270949726), UINT64_C(17291332897056520859),
      UINT64_C(11409053489495590030), UINT64_C(16067929224960909853), UINT64_C(14565225240112663841), UINT64_C(17015954395161507469),
      UINT64_C( 3235469156725683604), UINT64_C(12732461815629205332), UINT64_C(14614305297730054871), UINT64_C( 1076963363105319336),
      UINT64_C( 6220662965269843737), UINT64_C(14000245296096485643), UINT64_C(12902699731117447431), UINT64_C( 5605480924913930050),
      UINT64_C( 7445516010200047867), UINT64_C( 7032453671648591594), UINT64_C( 4369536152863400421), UINT64_C(  163468825972989124),
      UINT64_C( 7900812940159203810), UINT64_C(15532312523025131217), UINT64_C(12426393342429311804), UINT64_C( 1211723587478842310) };
  static const uint64_t e[] =
    { UINT64_C( 8743439831172825698), UINT64_C(13480983336872016282), UINT64_C(17589964038186505008), UINT64_C(18245425971760634727),
      UINT64_C( 4657561101175945281), UINT64_C( 1797260588568535213), UINT64_C( 8130094681030902081), UINT64_C(16403852430803836534),
      UINT64_C(12447951566934049882), UINT64_C(10877675610559360994), UINT64_C( 9331167053272520709), UINT64_C( 7613901484429913155),
      UINT64_C(11597519937668392458), UINT64_C( 5747647870476617176), UINT64_C(13432617493474690552), UINT64_C(11961880154109090696),
      UINT64_C( 7792740919940082220), UINT64_C(  451603574802608313), UINT64_C(13854117226637843268), UINT64_C(  619061179735063121),
      UINT64_C(  667488928441320515), UINT64_C(11742773683191678946), UINT64_C(17296607212384413714), UINT64_C(18195800033014604191),
      UINT64_C( 9036779593764422843), UINT64_C(16910748148937335284), UINT64_C( 3035592508594434123), UINT64_C( 6260153344731803375),
      UINT64_C( 4550974171967492902), UINT64_C( 3381773283669740278), UINT64_C( 5794958109538612578), UINT64_C( 2713414987625839158),
      UINT64_C( 8905064500309695523), UINT64_C(17509050642267984619), UINT64_C(14379269651530169738), UINT64_C( 6186678364604478759),
      UINT64_C(14452417226020995355), UINT64_C( 5053617233206605157), UINT64_C( 8053547270225038045), UINT64_C( 7533077749913865732),
      UINT64_C(15081447452156314015), UINT64_C( 4824153050918535797), UINT64_C(  433303250489389966), UINT64_C( 9577686246591497781),
      UINT64_C(15917313095461663490), UINT64_C( 3660919286444374710), UINT64_C(13313142730160236821), UINT64_C( 1043371717396018932),
      UINT64_C( 9370078551259161920), UINT64_C( 3878201947355213294), UINT64_C(15351893583382714509), UINT64_C( 3256621419066105879),
      UINT64_C(13787505469407239524), UINT64_C( 5883131322158981200), UINT64_C( 9488109362703443692), UINT64_C(11211804963491736223),
      UINT64_C(11844120049431174770), UINT64_C( 7843879941575420870), UINT64_C(15407123521245850909), UINT64_C( 8922923922811302659),
      UINT64_C( 6920194266997866999), UINT64_C(16554933233147773202), UINT64_C( 3215736789937370991), UINT64_C( 9602539234938255039),
      UINT64_C( 9912194592602165055), UINT64_C( 8181875623067666893), UINT64_C(14667734829880280784), UINT64_C( 8039379549329951101),
      UINT64_C(12088749324629853890), UINT64_C( 3009923407545010380), UINT64_C(11708789482838539157), UINT64_C( 9462055712682732484),
      UINT64_C( 7305140844159240004), UINT64_C(17145647266442922416), UINT64_C(    4815022161822167), UINT64_C( 9486238052266885437),
      UINT64_C(16522000465715357510), UINT64_C( 6618001737712927978), UINT64_C( 2881405367149841900), UINT64_C(17569207386604250383),
      UINT64_C(10813132459013705809), UINT64_C( 3132259312866930341), UINT64_C(14565225240112663841), UINT64_C( 5371200036069874831),
      UINT64_C(16765407464490421349), UINT64_C(12732461815629205332), UINT64_C(14614305297730054871), UINT64_C( 3664050814676662422),
      UINT64_C(10217241684992162975), UINT64_C( 9245881114179705456), UINT64_C(12902699731117447431), UINT64_C( 5605480924913930050),
      UINT64_C( 6094610424800277721), UINT64_C(16601564240994353153), UINT64_C( 4369536152863400421), UINT64_C(  817327683431880065),
      UINT64_C( 7900812940159203810), UINT64_C(14628998690472211302), UINT64_C(17634260450993027915), UINT64_C( 1211723587478842310) };

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
    rv = simde_svsel_u64(pv, av, bv);

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

    ev = simde_svsel_u64(pv, av, bv);

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
test_simde_x_svsel_f32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1) };
  static const simde_float32 a[] =
    { SIMDE_FLOAT32_C(  -882.90), SIMDE_FLOAT32_C(  -266.63), SIMDE_FLOAT32_C(   -75.12), SIMDE_FLOAT32_C(  -146.35),
      SIMDE_FLOAT32_C(   549.02), SIMDE_FLOAT32_C(  -256.80), SIMDE_FLOAT32_C(   427.26), SIMDE_FLOAT32_C(   549.77),
      SIMDE_FLOAT32_C(   253.23), SIMDE_FLOAT32_C(   -36.00), SIMDE_FLOAT32_C(   206.96), SIMDE_FLOAT32_C(  -873.55),
      SIMDE_FLOAT32_C(  -855.12), SIMDE_FLOAT32_C(   181.20), SIMDE_FLOAT32_C(  -987.95), SIMDE_FLOAT32_C(  -688.84),
      SIMDE_FLOAT32_C(   978.10), SIMDE_FLOAT32_C(   125.12), SIMDE_FLOAT32_C(    -2.36), SIMDE_FLOAT32_C(   170.72),
      SIMDE_FLOAT32_C(  -109.68), SIMDE_FLOAT32_C(   787.60), SIMDE_FLOAT32_C(   386.76), SIMDE_FLOAT32_C(  -317.86),
      SIMDE_FLOAT32_C(  -560.16), SIMDE_FLOAT32_C(   525.61), SIMDE_FLOAT32_C(   811.92), SIMDE_FLOAT32_C(  -864.45),
      SIMDE_FLOAT32_C(  -550.97), SIMDE_FLOAT32_C(  -297.84), SIMDE_FLOAT32_C(   259.94), SIMDE_FLOAT32_C(  -433.87),
      SIMDE_FLOAT32_C(   435.54), SIMDE_FLOAT32_C(  -815.17), SIMDE_FLOAT32_C(   419.78), SIMDE_FLOAT32_C(   -15.45),
      SIMDE_FLOAT32_C(   -71.98), SIMDE_FLOAT32_C(  -152.96), SIMDE_FLOAT32_C(  -465.68), SIMDE_FLOAT32_C(  -818.75),
      SIMDE_FLOAT32_C(   811.04), SIMDE_FLOAT32_C(   741.29), SIMDE_FLOAT32_C(  -692.30), SIMDE_FLOAT32_C(   955.92),
      SIMDE_FLOAT32_C(   -77.51), SIMDE_FLOAT32_C(  -680.24), SIMDE_FLOAT32_C(  -732.92), SIMDE_FLOAT32_C(   -99.41),
      SIMDE_FLOAT32_C(   444.88), SIMDE_FLOAT32_C(   264.71), SIMDE_FLOAT32_C(  -928.69), SIMDE_FLOAT32_C(  -664.80),
      SIMDE_FLOAT32_C(    52.31), SIMDE_FLOAT32_C(   458.08), SIMDE_FLOAT32_C(    17.34), SIMDE_FLOAT32_C(   492.15),
      SIMDE_FLOAT32_C(   -16.31), SIMDE_FLOAT32_C(  -170.74), SIMDE_FLOAT32_C(   627.70), SIMDE_FLOAT32_C(   432.72),
      SIMDE_FLOAT32_C(   531.42), SIMDE_FLOAT32_C(  -112.36), SIMDE_FLOAT32_C(   998.85), SIMDE_FLOAT32_C(   -33.04),
      SIMDE_FLOAT32_C(    72.47), SIMDE_FLOAT32_C(   418.63), SIMDE_FLOAT32_C(   951.52), SIMDE_FLOAT32_C(  -999.51),
      SIMDE_FLOAT32_C(  -734.33), SIMDE_FLOAT32_C(  -514.16), SIMDE_FLOAT32_C(  -818.26), SIMDE_FLOAT32_C(  -923.29),
      SIMDE_FLOAT32_C(  -772.88), SIMDE_FLOAT32_C(  -510.56), SIMDE_FLOAT32_C(  -967.37), SIMDE_FLOAT32_C(   149.61),
      SIMDE_FLOAT32_C(  -190.80), SIMDE_FLOAT32_C(  -700.30), SIMDE_FLOAT32_C(  -949.80), SIMDE_FLOAT32_C(  -745.93),
      SIMDE_FLOAT32_C(   564.41), SIMDE_FLOAT32_C(  -878.49), SIMDE_FLOAT32_C(  -410.73), SIMDE_FLOAT32_C(  -383.28),
      SIMDE_FLOAT32_C(   579.59), SIMDE_FLOAT32_C(   606.61), SIMDE_FLOAT32_C(  -891.13), SIMDE_FLOAT32_C(  -436.72),
      SIMDE_FLOAT32_C(  -564.13), SIMDE_FLOAT32_C(   736.56), SIMDE_FLOAT32_C(   996.00), SIMDE_FLOAT32_C(   967.30),
      SIMDE_FLOAT32_C(  -375.79), SIMDE_FLOAT32_C(   994.86), SIMDE_FLOAT32_C(   -65.74), SIMDE_FLOAT32_C(   696.67),
      SIMDE_FLOAT32_C(   413.49), SIMDE_FLOAT32_C(  -114.23), SIMDE_FLOAT32_C(   697.16), SIMDE_FLOAT32_C(   679.16),
      SIMDE_FLOAT32_C(   371.61), SIMDE_FLOAT32_C(   878.90), SIMDE_FLOAT32_C(   755.87), SIMDE_FLOAT32_C(   598.73),
      SIMDE_FLOAT32_C(  -631.66), SIMDE_FLOAT32_C(   788.50), SIMDE_FLOAT32_C(  -251.65), SIMDE_FLOAT32_C(   177.54),
      SIMDE_FLOAT32_C(  -911.80), SIMDE_FLOAT32_C(  -201.45), SIMDE_FLOAT32_C(   431.61), SIMDE_FLOAT32_C(   652.61),
      SIMDE_FLOAT32_C(   -79.93), SIMDE_FLOAT32_C(  -979.11), SIMDE_FLOAT32_C(  -730.66), SIMDE_FLOAT32_C(  -500.34),
      SIMDE_FLOAT32_C(   627.50), SIMDE_FLOAT32_C(  -621.80), SIMDE_FLOAT32_C(    62.94), SIMDE_FLOAT32_C(  -936.63),
      SIMDE_FLOAT32_C(  -885.23), SIMDE_FLOAT32_C(    58.94), SIMDE_FLOAT32_C(  -969.33), SIMDE_FLOAT32_C(  -261.03),
      SIMDE_FLOAT32_C(    53.80), SIMDE_FLOAT32_C(   -35.07), SIMDE_FLOAT32_C(  -564.35), SIMDE_FLOAT32_C(  -532.72),
      SIMDE_FLOAT32_C(   850.70), SIMDE_FLOAT32_C(  -867.19), SIMDE_FLOAT32_C(  -853.56), SIMDE_FLOAT32_C(   222.31),
      SIMDE_FLOAT32_C(  -988.29), SIMDE_FLOAT32_C(   902.31), SIMDE_FLOAT32_C(  -178.95), SIMDE_FLOAT32_C(  -619.95),
      SIMDE_FLOAT32_C(   690.81), SIMDE_FLOAT32_C(   569.40), SIMDE_FLOAT32_C(   557.58), SIMDE_FLOAT32_C(   779.01),
      SIMDE_FLOAT32_C(  -632.05), SIMDE_FLOAT32_C(   -10.80), SIMDE_FLOAT32_C(   431.63), SIMDE_FLOAT32_C(   288.01),
      SIMDE_FLOAT32_C(    10.08), SIMDE_FLOAT32_C(   700.96), SIMDE_FLOAT32_C(   787.67), SIMDE_FLOAT32_C(  -362.42),
      SIMDE_FLOAT32_C(  -920.84), SIMDE_FLOAT32_C(  -149.39), SIMDE_FLOAT32_C(  -299.05), SIMDE_FLOAT32_C(  -806.07),
      SIMDE_FLOAT32_C(   909.55), SIMDE_FLOAT32_C(  -268.38), SIMDE_FLOAT32_C(   -67.10), SIMDE_FLOAT32_C(   -36.65),
      SIMDE_FLOAT32_C(   696.55), SIMDE_FLOAT32_C(   368.55), SIMDE_FLOAT32_C(   430.63), SIMDE_FLOAT32_C(   547.25),
      SIMDE_FLOAT32_C(   501.36), SIMDE_FLOAT32_C(   577.08) };
  static const simde_float32 e[] =
    { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -75.12), SIMDE_FLOAT32_C(  -146.35),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -256.80), SIMDE_FLOAT32_C(   427.26), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   253.23), SIMDE_FLOAT32_C(   -36.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   181.20), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -550.97), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   435.54), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   -71.98), SIMDE_FLOAT32_C(  -152.96), SIMDE_FLOAT32_C(  -465.68), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   811.04), SIMDE_FLOAT32_C(   741.29), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   955.92),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -732.92), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -928.69), SIMDE_FLOAT32_C(  -664.80),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    17.34), SIMDE_FLOAT32_C(   492.15),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -170.74), SIMDE_FLOAT32_C(   627.70), SIMDE_FLOAT32_C(   432.72),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   418.63), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -734.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -818.26), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -510.56), SIMDE_FLOAT32_C(  -967.37), SIMDE_FLOAT32_C(   149.61),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -745.93),
      SIMDE_FLOAT32_C(   564.41), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   579.59), SIMDE_FLOAT32_C(   606.61), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -436.72),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   736.56), SIMDE_FLOAT32_C(   996.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   697.16), SIMDE_FLOAT32_C(   679.16),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   878.90), SIMDE_FLOAT32_C(   755.87), SIMDE_FLOAT32_C(   598.73),
      SIMDE_FLOAT32_C(  -631.66), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -251.65), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -201.45), SIMDE_FLOAT32_C(   431.61), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -979.11), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   627.50), SIMDE_FLOAT32_C(  -621.80), SIMDE_FLOAT32_C(    62.94), SIMDE_FLOAT32_C(  -936.63),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -261.03),
      SIMDE_FLOAT32_C(    53.80), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -564.35), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   222.31),
      SIMDE_FLOAT32_C(  -988.29), SIMDE_FLOAT32_C(   902.31), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(    10.08), SIMDE_FLOAT32_C(   700.96), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -362.42),
      SIMDE_FLOAT32_C(  -920.84), SIMDE_FLOAT32_C(  -149.39), SIMDE_FLOAT32_C(  -299.05), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -268.38), SIMDE_FLOAT32_C(   -67.10), SIMDE_FLOAT32_C(   -36.65),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   368.55), SIMDE_FLOAT32_C(   430.63), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   577.08) };

  static simde_float32 r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svfloat32_t
      rv,
      av = simde_svld1_f32(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_x_svsel_f32_z(pv, av);

    simde_svst1_f32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vf32(len, e, r, 1);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)];
  simde_float32 a[1024 / sizeof(simde_float32)], e[1024 / sizeof(simde_float32)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf32(HEDLEY_STATIC_CAST(size_t, len), a, SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svfloat32_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_f32(pg, &(a[i]));

    ev = simde_x_svsel_f32_z(pv, av);

    simde_svst1_f32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsel_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1) };
  static const simde_float32 a[] =
    { SIMDE_FLOAT32_C(  -735.75), SIMDE_FLOAT32_C(  -985.02), SIMDE_FLOAT32_C(   136.17), SIMDE_FLOAT32_C(   622.07),
      SIMDE_FLOAT32_C(   -92.13), SIMDE_FLOAT32_C(  -516.63), SIMDE_FLOAT32_C(   499.91), SIMDE_FLOAT32_C(  -300.63),
      SIMDE_FLOAT32_C(   165.71), SIMDE_FLOAT32_C(   827.11), SIMDE_FLOAT32_C(  -631.40), SIMDE_FLOAT32_C(   387.60),
      SIMDE_FLOAT32_C(    71.89), SIMDE_FLOAT32_C(  -922.07), SIMDE_FLOAT32_C(   887.96), SIMDE_FLOAT32_C(  -920.89),
      SIMDE_FLOAT32_C(   529.68), SIMDE_FLOAT32_C(   608.40), SIMDE_FLOAT32_C(   256.92), SIMDE_FLOAT32_C(  -120.39),
      SIMDE_FLOAT32_C(  -263.14), SIMDE_FLOAT32_C(  -248.03), SIMDE_FLOAT32_C(  -393.16), SIMDE_FLOAT32_C(   -47.82),
      SIMDE_FLOAT32_C(  -199.62), SIMDE_FLOAT32_C(   415.22), SIMDE_FLOAT32_C(  -934.15), SIMDE_FLOAT32_C(  -599.91),
      SIMDE_FLOAT32_C(  -908.46), SIMDE_FLOAT32_C(   186.06), SIMDE_FLOAT32_C(  -125.08), SIMDE_FLOAT32_C(  -644.20),
      SIMDE_FLOAT32_C(   201.05), SIMDE_FLOAT32_C(  -988.91), SIMDE_FLOAT32_C(   977.87), SIMDE_FLOAT32_C(  -891.09),
      SIMDE_FLOAT32_C(  -505.53), SIMDE_FLOAT32_C(   477.78), SIMDE_FLOAT32_C(  -191.72), SIMDE_FLOAT32_C(   660.18),
      SIMDE_FLOAT32_C(   304.89), SIMDE_FLOAT32_C(   176.87), SIMDE_FLOAT32_C(    47.77), SIMDE_FLOAT32_C(  -623.22),
      SIMDE_FLOAT32_C(   254.81), SIMDE_FLOAT32_C(   -64.26), SIMDE_FLOAT32_C(  -544.11), SIMDE_FLOAT32_C(  -215.51),
      SIMDE_FLOAT32_C(  -455.86), SIMDE_FLOAT32_C(   712.82), SIMDE_FLOAT32_C(   664.10), SIMDE_FLOAT32_C(   281.00),
      SIMDE_FLOAT32_C(  -535.22), SIMDE_FLOAT32_C(  -729.06), SIMDE_FLOAT32_C(  -766.82), SIMDE_FLOAT32_C(   265.16),
      SIMDE_FLOAT32_C(   686.16), SIMDE_FLOAT32_C(  -700.97), SIMDE_FLOAT32_C(   665.25), SIMDE_FLOAT32_C(   777.70),
      SIMDE_FLOAT32_C(   485.09), SIMDE_FLOAT32_C(  -459.83), SIMDE_FLOAT32_C(  -866.50), SIMDE_FLOAT32_C(  -313.86),
      SIMDE_FLOAT32_C(  -448.74), SIMDE_FLOAT32_C(  -888.63), SIMDE_FLOAT32_C(  -204.95), SIMDE_FLOAT32_C(    45.73),
      SIMDE_FLOAT32_C(   589.15), SIMDE_FLOAT32_C(   603.33), SIMDE_FLOAT32_C(  -294.09), SIMDE_FLOAT32_C(  -105.96),
      SIMDE_FLOAT32_C(  -219.80), SIMDE_FLOAT32_C(   753.68), SIMDE_FLOAT32_C(   270.83), SIMDE_FLOAT32_C(  -964.99),
      SIMDE_FLOAT32_C(  -310.58), SIMDE_FLOAT32_C(   726.72), SIMDE_FLOAT32_C(  -180.50), SIMDE_FLOAT32_C(   233.56),
      SIMDE_FLOAT32_C(   439.54), SIMDE_FLOAT32_C(  -516.40), SIMDE_FLOAT32_C(  -485.44), SIMDE_FLOAT32_C(   904.32),
      SIMDE_FLOAT32_C(  -245.46), SIMDE_FLOAT32_C(  -252.26), SIMDE_FLOAT32_C(   169.48), SIMDE_FLOAT32_C(  -559.29),
      SIMDE_FLOAT32_C(    46.77), SIMDE_FLOAT32_C(  -165.26), SIMDE_FLOAT32_C(  -781.59), SIMDE_FLOAT32_C(  -468.14),
      SIMDE_FLOAT32_C(   374.91), SIMDE_FLOAT32_C(  -648.09), SIMDE_FLOAT32_C(   218.00), SIMDE_FLOAT32_C(   926.17),
      SIMDE_FLOAT32_C(  -536.72), SIMDE_FLOAT32_C(  -986.95), SIMDE_FLOAT32_C(   -28.10), SIMDE_FLOAT32_C(  -947.57),
      SIMDE_FLOAT32_C(   616.38), SIMDE_FLOAT32_C(   677.81), SIMDE_FLOAT32_C(   -53.52), SIMDE_FLOAT32_C(  -603.42),
      SIMDE_FLOAT32_C(   431.49), SIMDE_FLOAT32_C(  -782.70), SIMDE_FLOAT32_C(  -568.41), SIMDE_FLOAT32_C(  -879.09),
      SIMDE_FLOAT32_C(   944.03), SIMDE_FLOAT32_C(   251.09), SIMDE_FLOAT32_C(   354.47), SIMDE_FLOAT32_C(   383.56),
      SIMDE_FLOAT32_C(   734.69), SIMDE_FLOAT32_C(   869.03), SIMDE_FLOAT32_C(   287.88), SIMDE_FLOAT32_C(  -510.76),
      SIMDE_FLOAT32_C(  -383.23), SIMDE_FLOAT32_C(  -542.63), SIMDE_FLOAT32_C(   -70.06), SIMDE_FLOAT32_C(   663.54),
      SIMDE_FLOAT32_C(   292.10), SIMDE_FLOAT32_C(   148.35), SIMDE_FLOAT32_C(  -804.60), SIMDE_FLOAT32_C(  -332.99),
      SIMDE_FLOAT32_C(   500.26), SIMDE_FLOAT32_C(   413.40), SIMDE_FLOAT32_C(  -406.82), SIMDE_FLOAT32_C(   963.55),
      SIMDE_FLOAT32_C(   426.45), SIMDE_FLOAT32_C(   565.08), SIMDE_FLOAT32_C(  -984.02), SIMDE_FLOAT32_C(    42.83),
      SIMDE_FLOAT32_C(   242.89), SIMDE_FLOAT32_C(   -37.54), SIMDE_FLOAT32_C(   439.41), SIMDE_FLOAT32_C(  -325.62),
      SIMDE_FLOAT32_C(   179.76), SIMDE_FLOAT32_C(   871.00), SIMDE_FLOAT32_C(  -204.72), SIMDE_FLOAT32_C(   123.79),
      SIMDE_FLOAT32_C(   122.09), SIMDE_FLOAT32_C(  -850.25), SIMDE_FLOAT32_C(  -492.65), SIMDE_FLOAT32_C(  -143.21),
      SIMDE_FLOAT32_C(  -981.21), SIMDE_FLOAT32_C(   795.23), SIMDE_FLOAT32_C(   346.02), SIMDE_FLOAT32_C(  -364.44),
      SIMDE_FLOAT32_C(  -747.40), SIMDE_FLOAT32_C(  -724.03), SIMDE_FLOAT32_C(  -700.90), SIMDE_FLOAT32_C(   544.70),
      SIMDE_FLOAT32_C(   424.32), SIMDE_FLOAT32_C(  -505.49), SIMDE_FLOAT32_C(  -788.29), SIMDE_FLOAT32_C(   -75.42),
      SIMDE_FLOAT32_C(   907.91), SIMDE_FLOAT32_C(  -195.11), SIMDE_FLOAT32_C(  -111.87), SIMDE_FLOAT32_C(   334.36),
      SIMDE_FLOAT32_C(  -630.03), SIMDE_FLOAT32_C(   -95.89), SIMDE_FLOAT32_C(  -622.81), SIMDE_FLOAT32_C(   612.85),
      SIMDE_FLOAT32_C(   866.56), SIMDE_FLOAT32_C(   816.60), SIMDE_FLOAT32_C(  -712.77), SIMDE_FLOAT32_C(    46.33),
      SIMDE_FLOAT32_C(   687.60), SIMDE_FLOAT32_C(    82.51), SIMDE_FLOAT32_C(  -829.89), SIMDE_FLOAT32_C(  -190.30),
      SIMDE_FLOAT32_C(   232.26), SIMDE_FLOAT32_C(  -322.54), SIMDE_FLOAT32_C(   666.49), SIMDE_FLOAT32_C(   251.05),
      SIMDE_FLOAT32_C(  -527.30), SIMDE_FLOAT32_C(    12.51), SIMDE_FLOAT32_C(   886.61), SIMDE_FLOAT32_C(  -274.70),
      SIMDE_FLOAT32_C(   288.47), SIMDE_FLOAT32_C(  -814.29), SIMDE_FLOAT32_C(  -730.00), SIMDE_FLOAT32_C(  -287.21),
      SIMDE_FLOAT32_C(  -319.78), SIMDE_FLOAT32_C(  -518.29), SIMDE_FLOAT32_C(   637.37), SIMDE_FLOAT32_C(  -411.87),
      SIMDE_FLOAT32_C(   286.60), SIMDE_FLOAT32_C(  -474.50), SIMDE_FLOAT32_C(   922.49), SIMDE_FLOAT32_C(   656.56),
      SIMDE_FLOAT32_C(   429.61), SIMDE_FLOAT32_C(  -700.32), SIMDE_FLOAT32_C(   269.42), SIMDE_FLOAT32_C(   296.17),
      SIMDE_FLOAT32_C(  -883.72), SIMDE_FLOAT32_C(   556.64), SIMDE_FLOAT32_C(  -657.50), SIMDE_FLOAT32_C(   803.89),
      SIMDE_FLOAT32_C(  -360.84), SIMDE_FLOAT32_C(  -487.39), SIMDE_FLOAT32_C(  -386.41), SIMDE_FLOAT32_C(   871.42),
      SIMDE_FLOAT32_C(   190.08), SIMDE_FLOAT32_C(  -719.93), SIMDE_FLOAT32_C(   122.47), SIMDE_FLOAT32_C(   662.78),
      SIMDE_FLOAT32_C(   292.58), SIMDE_FLOAT32_C(     9.08), SIMDE_FLOAT32_C(  -611.92), SIMDE_FLOAT32_C(  -418.94),
      SIMDE_FLOAT32_C(   194.79), SIMDE_FLOAT32_C(  -341.92), SIMDE_FLOAT32_C(   293.85), SIMDE_FLOAT32_C(   875.01),
      SIMDE_FLOAT32_C(   139.79) };
  static const simde_float32 b[] =
    { SIMDE_FLOAT32_C(   -68.78), SIMDE_FLOAT32_C(  -536.86), SIMDE_FLOAT32_C(  -573.62), SIMDE_FLOAT32_C(   456.73),
      SIMDE_FLOAT32_C(  -614.37), SIMDE_FLOAT32_C(  -917.05), SIMDE_FLOAT32_C(  -113.66), SIMDE_FLOAT32_C(  -314.69),
      SIMDE_FLOAT32_C(   352.36), SIMDE_FLOAT32_C(  -817.49), SIMDE_FLOAT32_C(  -198.41), SIMDE_FLOAT32_C(   -90.99),
      SIMDE_FLOAT32_C(  -474.99), SIMDE_FLOAT32_C(  -394.52), SIMDE_FLOAT32_C(   548.16), SIMDE_FLOAT32_C(    37.62),
      SIMDE_FLOAT32_C(   219.07), SIMDE_FLOAT32_C(   419.58), SIMDE_FLOAT32_C(  -772.30), SIMDE_FLOAT32_C(   499.14),
      SIMDE_FLOAT32_C(  -457.95), SIMDE_FLOAT32_C(   890.47), SIMDE_FLOAT32_C(  -208.28), SIMDE_FLOAT32_C(   551.13),
      SIMDE_FLOAT32_C(  -721.45), SIMDE_FLOAT32_C(   372.78), SIMDE_FLOAT32_C(  -254.08), SIMDE_FLOAT32_C(   -63.37),
      SIMDE_FLOAT32_C(  -333.37), SIMDE_FLOAT32_C(  -379.08), SIMDE_FLOAT32_C(  -923.59), SIMDE_FLOAT32_C(   597.85),
      SIMDE_FLOAT32_C(    84.06), SIMDE_FLOAT32_C(  -497.20), SIMDE_FLOAT32_C(    54.58), SIMDE_FLOAT32_C(   469.69),
      SIMDE_FLOAT32_C(  -414.25), SIMDE_FLOAT32_C(   940.92), SIMDE_FLOAT32_C(  -845.00), SIMDE_FLOAT32_C(   938.11),
      SIMDE_FLOAT32_C(  -876.58), SIMDE_FLOAT32_C(   -43.41), SIMDE_FLOAT32_C(  -152.89), SIMDE_FLOAT32_C(  -351.57),
      SIMDE_FLOAT32_C(   562.07), SIMDE_FLOAT32_C(  -604.72), SIMDE_FLOAT32_C(   686.05), SIMDE_FLOAT32_C(  -218.86),
      SIMDE_FLOAT32_C(   814.86), SIMDE_FLOAT32_C(   913.75), SIMDE_FLOAT32_C(  -719.71), SIMDE_FLOAT32_C(  -643.09),
      SIMDE_FLOAT32_C(   804.22), SIMDE_FLOAT32_C(    72.01), SIMDE_FLOAT32_C(   908.03), SIMDE_FLOAT32_C(  -917.23),
      SIMDE_FLOAT32_C(  -555.21), SIMDE_FLOAT32_C(  -346.05), SIMDE_FLOAT32_C(    19.40), SIMDE_FLOAT32_C(   111.42),
      SIMDE_FLOAT32_C(   274.87), SIMDE_FLOAT32_C(    95.82), SIMDE_FLOAT32_C(  -290.72), SIMDE_FLOAT32_C(  -641.07),
      SIMDE_FLOAT32_C(   598.61), SIMDE_FLOAT32_C(   763.86), SIMDE_FLOAT32_C(   828.62), SIMDE_FLOAT32_C(  -815.64),
      SIMDE_FLOAT32_C(   704.77), SIMDE_FLOAT32_C(   983.62), SIMDE_FLOAT32_C(  -877.53), SIMDE_FLOAT32_C(   828.20),
      SIMDE_FLOAT32_C(   -59.79), SIMDE_FLOAT32_C(   -30.42), SIMDE_FLOAT32_C(  -523.37), SIMDE_FLOAT32_C(  -497.71),
      SIMDE_FLOAT32_C(   364.86), SIMDE_FLOAT32_C(  -837.32), SIMDE_FLOAT32_C(   283.43), SIMDE_FLOAT32_C(   179.71),
      SIMDE_FLOAT32_C(  -923.57), SIMDE_FLOAT32_C(   563.72), SIMDE_FLOAT32_C(   536.62), SIMDE_FLOAT32_C(   880.65),
      SIMDE_FLOAT32_C(  -364.27), SIMDE_FLOAT32_C(   444.65), SIMDE_FLOAT32_C(   963.43), SIMDE_FLOAT32_C(    80.52),
      SIMDE_FLOAT32_C(  -901.40), SIMDE_FLOAT32_C(   -17.17), SIMDE_FLOAT32_C(  -808.06), SIMDE_FLOAT32_C(   373.47),
      SIMDE_FLOAT32_C(  -921.36), SIMDE_FLOAT32_C(   -98.78), SIMDE_FLOAT32_C(   732.41), SIMDE_FLOAT32_C(   677.26),
      SIMDE_FLOAT32_C(  -334.93), SIMDE_FLOAT32_C(   561.03), SIMDE_FLOAT32_C(   861.62), SIMDE_FLOAT32_C(  -630.15),
      SIMDE_FLOAT32_C(   544.65), SIMDE_FLOAT32_C(   984.08), SIMDE_FLOAT32_C(  -801.95), SIMDE_FLOAT32_C(  -515.14),
      SIMDE_FLOAT32_C(   -46.33), SIMDE_FLOAT32_C(  -325.32), SIMDE_FLOAT32_C(   -12.85), SIMDE_FLOAT32_C(  -681.48),
      SIMDE_FLOAT32_C(  -162.64), SIMDE_FLOAT32_C(  -729.41), SIMDE_FLOAT32_C(   498.24), SIMDE_FLOAT32_C(   -86.21),
      SIMDE_FLOAT32_C(   834.31), SIMDE_FLOAT32_C(    34.86), SIMDE_FLOAT32_C(  -205.56), SIMDE_FLOAT32_C(  -529.97),
      SIMDE_FLOAT32_C(  -520.49), SIMDE_FLOAT32_C(  -242.13), SIMDE_FLOAT32_C(   550.55), SIMDE_FLOAT32_C(  -421.89),
      SIMDE_FLOAT32_C(   740.69), SIMDE_FLOAT32_C(   742.50), SIMDE_FLOAT32_C(   951.58), SIMDE_FLOAT32_C(   819.34),
      SIMDE_FLOAT32_C(  -356.29), SIMDE_FLOAT32_C(   683.99), SIMDE_FLOAT32_C(   496.59), SIMDE_FLOAT32_C(   308.79),
      SIMDE_FLOAT32_C(   245.02), SIMDE_FLOAT32_C(   358.21), SIMDE_FLOAT32_C(   678.64), SIMDE_FLOAT32_C(  -210.33),
      SIMDE_FLOAT32_C(   342.29), SIMDE_FLOAT32_C(   876.68), SIMDE_FLOAT32_C(   274.53), SIMDE_FLOAT32_C(  -704.04),
      SIMDE_FLOAT32_C(  -448.64), SIMDE_FLOAT32_C(  -738.31), SIMDE_FLOAT32_C(  -385.52), SIMDE_FLOAT32_C(   388.72),
      SIMDE_FLOAT32_C(  -467.73), SIMDE_FLOAT32_C(  -887.28), SIMDE_FLOAT32_C(  -697.49), SIMDE_FLOAT32_C(  -633.42),
      SIMDE_FLOAT32_C(   147.57), SIMDE_FLOAT32_C(    96.95), SIMDE_FLOAT32_C(  -163.38), SIMDE_FLOAT32_C(   627.08),
      SIMDE_FLOAT32_C(   854.81), SIMDE_FLOAT32_C(  -612.83), SIMDE_FLOAT32_C(  -794.81), SIMDE_FLOAT32_C(   595.51),
      SIMDE_FLOAT32_C(  -870.33), SIMDE_FLOAT32_C(  -843.23), SIMDE_FLOAT32_C(   414.84), SIMDE_FLOAT32_C(  -226.62),
      SIMDE_FLOAT32_C(   840.76), SIMDE_FLOAT32_C(   -88.57), SIMDE_FLOAT32_C(  -917.83), SIMDE_FLOAT32_C(    85.78),
      SIMDE_FLOAT32_C(  -730.36), SIMDE_FLOAT32_C(   760.80), SIMDE_FLOAT32_C(   875.45), SIMDE_FLOAT32_C(   611.94),
      SIMDE_FLOAT32_C(   637.48), SIMDE_FLOAT32_C(   149.98), SIMDE_FLOAT32_C(   907.90), SIMDE_FLOAT32_C(  -811.16),
      SIMDE_FLOAT32_C(   411.67), SIMDE_FLOAT32_C(  -477.62), SIMDE_FLOAT32_C(   577.56), SIMDE_FLOAT32_C(   943.94),
      SIMDE_FLOAT32_C(  -364.90), SIMDE_FLOAT32_C(   880.07), SIMDE_FLOAT32_C(  -689.47), SIMDE_FLOAT32_C(   782.67),
      SIMDE_FLOAT32_C(   -22.98), SIMDE_FLOAT32_C(   147.14), SIMDE_FLOAT32_C(   409.75), SIMDE_FLOAT32_C(  -168.17),
      SIMDE_FLOAT32_C(   534.31), SIMDE_FLOAT32_C(   614.94), SIMDE_FLOAT32_C(  -572.66), SIMDE_FLOAT32_C(   663.98),
      SIMDE_FLOAT32_C(   771.71), SIMDE_FLOAT32_C(   842.18), SIMDE_FLOAT32_C(  -562.64), SIMDE_FLOAT32_C(   612.48),
      SIMDE_FLOAT32_C(  -246.39), SIMDE_FLOAT32_C(  -480.48), SIMDE_FLOAT32_C(  -301.75), SIMDE_FLOAT32_C(    23.26),
      SIMDE_FLOAT32_C(  -719.68), SIMDE_FLOAT32_C(  -426.30), SIMDE_FLOAT32_C(  -364.80), SIMDE_FLOAT32_C(   917.81),
      SIMDE_FLOAT32_C(   723.68), SIMDE_FLOAT32_C(  -456.91), SIMDE_FLOAT32_C(  -893.35), SIMDE_FLOAT32_C(   135.36),
      SIMDE_FLOAT32_C(    65.47), SIMDE_FLOAT32_C(   684.21), SIMDE_FLOAT32_C(    79.30), SIMDE_FLOAT32_C(   700.57),
      SIMDE_FLOAT32_C(   564.28), SIMDE_FLOAT32_C(   389.83), SIMDE_FLOAT32_C(   483.24), SIMDE_FLOAT32_C(  -458.70),
      SIMDE_FLOAT32_C(  -463.03), SIMDE_FLOAT32_C(  -107.01), SIMDE_FLOAT32_C(   373.13), SIMDE_FLOAT32_C(  -928.72),
      SIMDE_FLOAT32_C(  -492.06), SIMDE_FLOAT32_C(   800.47), SIMDE_FLOAT32_C(   735.26), SIMDE_FLOAT32_C(  -720.35),
      SIMDE_FLOAT32_C(   642.65) };
  static const simde_float32 e[] =
    { SIMDE_FLOAT32_C(   -68.78), SIMDE_FLOAT32_C(  -536.86), SIMDE_FLOAT32_C(   136.17), SIMDE_FLOAT32_C(   622.07),
      SIMDE_FLOAT32_C(   -92.13), SIMDE_FLOAT32_C(  -917.05), SIMDE_FLOAT32_C(  -113.66), SIMDE_FLOAT32_C(  -314.69),
      SIMDE_FLOAT32_C(   352.36), SIMDE_FLOAT32_C(  -817.49), SIMDE_FLOAT32_C(  -198.41), SIMDE_FLOAT32_C(   387.60),
      SIMDE_FLOAT32_C(  -474.99), SIMDE_FLOAT32_C(  -922.07), SIMDE_FLOAT32_C(   548.16), SIMDE_FLOAT32_C(    37.62),
      SIMDE_FLOAT32_C(   529.68), SIMDE_FLOAT32_C(   608.40), SIMDE_FLOAT32_C(  -772.30), SIMDE_FLOAT32_C(   499.14),
      SIMDE_FLOAT32_C(  -263.14), SIMDE_FLOAT32_C(  -248.03), SIMDE_FLOAT32_C(  -208.28), SIMDE_FLOAT32_C(   551.13),
      SIMDE_FLOAT32_C(  -199.62), SIMDE_FLOAT32_C(   372.78), SIMDE_FLOAT32_C(  -254.08), SIMDE_FLOAT32_C(  -599.91),
      SIMDE_FLOAT32_C(  -908.46), SIMDE_FLOAT32_C(   186.06), SIMDE_FLOAT32_C(  -923.59), SIMDE_FLOAT32_C(   597.85),
      SIMDE_FLOAT32_C(    84.06), SIMDE_FLOAT32_C(  -497.20), SIMDE_FLOAT32_C(   977.87), SIMDE_FLOAT32_C(  -891.09),
      SIMDE_FLOAT32_C(  -414.25), SIMDE_FLOAT32_C(   477.78), SIMDE_FLOAT32_C(  -845.00), SIMDE_FLOAT32_C(   660.18),
      SIMDE_FLOAT32_C(  -876.58), SIMDE_FLOAT32_C(   176.87), SIMDE_FLOAT32_C(    47.77), SIMDE_FLOAT32_C(  -623.22),
      SIMDE_FLOAT32_C(   562.07), SIMDE_FLOAT32_C(   -64.26), SIMDE_FLOAT32_C(  -544.11), SIMDE_FLOAT32_C(  -215.51),
      SIMDE_FLOAT32_C(  -455.86), SIMDE_FLOAT32_C(   913.75), SIMDE_FLOAT32_C(  -719.71), SIMDE_FLOAT32_C(   281.00),
      SIMDE_FLOAT32_C(  -535.22), SIMDE_FLOAT32_C(  -729.06), SIMDE_FLOAT32_C(  -766.82), SIMDE_FLOAT32_C(  -917.23),
      SIMDE_FLOAT32_C(  -555.21), SIMDE_FLOAT32_C(  -346.05), SIMDE_FLOAT32_C(    19.40), SIMDE_FLOAT32_C(   111.42),
      SIMDE_FLOAT32_C(   274.87), SIMDE_FLOAT32_C(    95.82), SIMDE_FLOAT32_C(  -866.50), SIMDE_FLOAT32_C(  -313.86),
      SIMDE_FLOAT32_C(  -448.74), SIMDE_FLOAT32_C(   763.86), SIMDE_FLOAT32_C(  -204.95), SIMDE_FLOAT32_C(  -815.64),
      SIMDE_FLOAT32_C(   704.77), SIMDE_FLOAT32_C(   603.33), SIMDE_FLOAT32_C(  -294.09), SIMDE_FLOAT32_C(   828.20),
      SIMDE_FLOAT32_C(  -219.80), SIMDE_FLOAT32_C(   -30.42), SIMDE_FLOAT32_C(   270.83), SIMDE_FLOAT32_C(  -497.71),
      SIMDE_FLOAT32_C(   364.86), SIMDE_FLOAT32_C(   726.72), SIMDE_FLOAT32_C(   283.43), SIMDE_FLOAT32_C(   233.56),
      SIMDE_FLOAT32_C(   439.54), SIMDE_FLOAT32_C(  -516.40), SIMDE_FLOAT32_C(   536.62), SIMDE_FLOAT32_C(   904.32),
      SIMDE_FLOAT32_C(  -245.46), SIMDE_FLOAT32_C(  -252.26), SIMDE_FLOAT32_C(   169.48), SIMDE_FLOAT32_C(    80.52),
      SIMDE_FLOAT32_C(  -901.40), SIMDE_FLOAT32_C(  -165.26), SIMDE_FLOAT32_C(  -781.59), SIMDE_FLOAT32_C(   373.47),
      SIMDE_FLOAT32_C(  -921.36), SIMDE_FLOAT32_C(   -98.78), SIMDE_FLOAT32_C(   218.00), SIMDE_FLOAT32_C(   677.26),
      SIMDE_FLOAT32_C(  -334.93), SIMDE_FLOAT32_C(   561.03), SIMDE_FLOAT32_C(   -28.10), SIMDE_FLOAT32_C(  -947.57),
      SIMDE_FLOAT32_C(   616.38), SIMDE_FLOAT32_C(   677.81), SIMDE_FLOAT32_C(  -801.95), SIMDE_FLOAT32_C(  -603.42),
      SIMDE_FLOAT32_C(   431.49), SIMDE_FLOAT32_C(  -782.70), SIMDE_FLOAT32_C(  -568.41), SIMDE_FLOAT32_C(  -681.48),
      SIMDE_FLOAT32_C(   944.03), SIMDE_FLOAT32_C(   251.09), SIMDE_FLOAT32_C(   354.47), SIMDE_FLOAT32_C(   -86.21),
      SIMDE_FLOAT32_C(   734.69), SIMDE_FLOAT32_C(    34.86), SIMDE_FLOAT32_C(  -205.56), SIMDE_FLOAT32_C(  -510.76),
      SIMDE_FLOAT32_C(  -383.23), SIMDE_FLOAT32_C(  -242.13), SIMDE_FLOAT32_C(   550.55), SIMDE_FLOAT32_C(   663.54),
      SIMDE_FLOAT32_C(   292.10), SIMDE_FLOAT32_C(   148.35), SIMDE_FLOAT32_C(  -804.60), SIMDE_FLOAT32_C(  -332.99),
      SIMDE_FLOAT32_C(  -356.29), SIMDE_FLOAT32_C(   683.99), SIMDE_FLOAT32_C(   496.59), SIMDE_FLOAT32_C(   308.79),
      SIMDE_FLOAT32_C(   245.02), SIMDE_FLOAT32_C(   358.21), SIMDE_FLOAT32_C(   678.64), SIMDE_FLOAT32_C(  -210.33),
      SIMDE_FLOAT32_C(   242.89), SIMDE_FLOAT32_C(   -37.54), SIMDE_FLOAT32_C(   274.53), SIMDE_FLOAT32_C(  -325.62),
      SIMDE_FLOAT32_C(   179.76), SIMDE_FLOAT32_C(   871.00), SIMDE_FLOAT32_C(  -385.52), SIMDE_FLOAT32_C(   123.79),
      SIMDE_FLOAT32_C(  -467.73), SIMDE_FLOAT32_C(  -887.28), SIMDE_FLOAT32_C(  -697.49), SIMDE_FLOAT32_C(  -143.21),
      SIMDE_FLOAT32_C(  -981.21), SIMDE_FLOAT32_C(   795.23), SIMDE_FLOAT32_C(  -163.38), SIMDE_FLOAT32_C(   627.08),
      SIMDE_FLOAT32_C(  -747.40), SIMDE_FLOAT32_C(  -612.83), SIMDE_FLOAT32_C(  -794.81), SIMDE_FLOAT32_C(   595.51),
      SIMDE_FLOAT32_C(   424.32), SIMDE_FLOAT32_C(  -843.23), SIMDE_FLOAT32_C(   414.84), SIMDE_FLOAT32_C(  -226.62),
      SIMDE_FLOAT32_C(   907.91), SIMDE_FLOAT32_C(  -195.11), SIMDE_FLOAT32_C(  -111.87), SIMDE_FLOAT32_C(   334.36),
      SIMDE_FLOAT32_C(  -730.36), SIMDE_FLOAT32_C(   -95.89), SIMDE_FLOAT32_C(   875.45), SIMDE_FLOAT32_C(   611.94),
      SIMDE_FLOAT32_C(   866.56), SIMDE_FLOAT32_C(   816.60), SIMDE_FLOAT32_C(  -712.77), SIMDE_FLOAT32_C(  -811.16),
      SIMDE_FLOAT32_C(   411.67), SIMDE_FLOAT32_C(  -477.62), SIMDE_FLOAT32_C(  -829.89), SIMDE_FLOAT32_C(   943.94),
      SIMDE_FLOAT32_C(   232.26), SIMDE_FLOAT32_C(   880.07), SIMDE_FLOAT32_C(   666.49), SIMDE_FLOAT32_C(   251.05),
      SIMDE_FLOAT32_C(   -22.98), SIMDE_FLOAT32_C(   147.14), SIMDE_FLOAT32_C(   409.75), SIMDE_FLOAT32_C(  -168.17),
      SIMDE_FLOAT32_C(   534.31), SIMDE_FLOAT32_C(  -814.29), SIMDE_FLOAT32_C(  -572.66), SIMDE_FLOAT32_C(   663.98),
      SIMDE_FLOAT32_C(   771.71), SIMDE_FLOAT32_C(   842.18), SIMDE_FLOAT32_C(  -562.64), SIMDE_FLOAT32_C(  -411.87),
      SIMDE_FLOAT32_C(   286.60), SIMDE_FLOAT32_C(  -480.48), SIMDE_FLOAT32_C(   922.49), SIMDE_FLOAT32_C(   656.56),
      SIMDE_FLOAT32_C(   429.61), SIMDE_FLOAT32_C(  -700.32), SIMDE_FLOAT32_C(   269.42), SIMDE_FLOAT32_C(   917.81),
      SIMDE_FLOAT32_C(   723.68), SIMDE_FLOAT32_C(   556.64), SIMDE_FLOAT32_C(  -893.35), SIMDE_FLOAT32_C(   803.89),
      SIMDE_FLOAT32_C(    65.47), SIMDE_FLOAT32_C(   684.21), SIMDE_FLOAT32_C(  -386.41), SIMDE_FLOAT32_C(   700.57),
      SIMDE_FLOAT32_C(   190.08), SIMDE_FLOAT32_C(   389.83), SIMDE_FLOAT32_C(   483.24), SIMDE_FLOAT32_C(   662.78),
      SIMDE_FLOAT32_C(  -463.03), SIMDE_FLOAT32_C(  -107.01), SIMDE_FLOAT32_C(  -611.92), SIMDE_FLOAT32_C(  -928.72),
      SIMDE_FLOAT32_C(   194.79), SIMDE_FLOAT32_C(  -341.92), SIMDE_FLOAT32_C(   735.26), SIMDE_FLOAT32_C(   875.01),
      SIMDE_FLOAT32_C(   139.79) };

  static simde_float32 r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svfloat32_t
      rv,
      av = simde_svld1_f32(pg, &(a[i])),
      bv = simde_svld1_f32(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_svsel_f32(pv, av, bv);

    simde_svst1_f32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vf32(len, e, r, 1);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)];
  simde_float32 a[1024 / sizeof(int32_t)], b[1024 / sizeof(int32_t)], e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf32(HEDLEY_STATIC_CAST(size_t, len), a, SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  simde_test_codegen_random_vf32(HEDLEY_STATIC_CAST(size_t, len), b, SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svfloat32_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_f32(pg, &(a[i]));
    bv = simde_svld1_f32(pg, &(b[i]));

    ev = simde_svsel_f32(pv, av, bv);

    simde_svst1_f32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_x_svsel_f64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) };
  static const simde_float64 a[] =
    { SIMDE_FLOAT64_C(   804.74), SIMDE_FLOAT64_C(    14.34), SIMDE_FLOAT64_C(   748.42), SIMDE_FLOAT64_C(  -349.22),
      SIMDE_FLOAT64_C(   636.24), SIMDE_FLOAT64_C(  -768.54), SIMDE_FLOAT64_C(   871.82), SIMDE_FLOAT64_C(   913.02),
      SIMDE_FLOAT64_C(   286.35), SIMDE_FLOAT64_C(   335.68), SIMDE_FLOAT64_C(   358.71), SIMDE_FLOAT64_C(  -658.65),
      SIMDE_FLOAT64_C(   -34.78), SIMDE_FLOAT64_C(   173.13), SIMDE_FLOAT64_C(   976.54), SIMDE_FLOAT64_C(  -690.38),
      SIMDE_FLOAT64_C(  -457.11), SIMDE_FLOAT64_C(  -447.26), SIMDE_FLOAT64_C(   912.85), SIMDE_FLOAT64_C(    -4.98),
      SIMDE_FLOAT64_C(  -883.64), SIMDE_FLOAT64_C(   576.51), SIMDE_FLOAT64_C(  -846.91), SIMDE_FLOAT64_C(   179.95),
      SIMDE_FLOAT64_C(  -899.24), SIMDE_FLOAT64_C(   312.41), SIMDE_FLOAT64_C(   -26.22), SIMDE_FLOAT64_C(  -404.13),
      SIMDE_FLOAT64_C(   -85.15), SIMDE_FLOAT64_C(   517.86), SIMDE_FLOAT64_C(   577.31), SIMDE_FLOAT64_C(  -280.41),
      SIMDE_FLOAT64_C(  -467.80), SIMDE_FLOAT64_C(   325.73), SIMDE_FLOAT64_C(   370.37), SIMDE_FLOAT64_C(  -831.56),
      SIMDE_FLOAT64_C(   557.19), SIMDE_FLOAT64_C(   242.19), SIMDE_FLOAT64_C(  -918.54), SIMDE_FLOAT64_C(  -156.45),
      SIMDE_FLOAT64_C(  -422.13), SIMDE_FLOAT64_C(   440.17), SIMDE_FLOAT64_C(   184.89), SIMDE_FLOAT64_C(   543.08),
      SIMDE_FLOAT64_C(  -386.70), SIMDE_FLOAT64_C(   161.44), SIMDE_FLOAT64_C(   852.70), SIMDE_FLOAT64_C(   156.19),
      SIMDE_FLOAT64_C(   714.17), SIMDE_FLOAT64_C(   765.55), SIMDE_FLOAT64_C(  -848.79), SIMDE_FLOAT64_C(   830.53),
      SIMDE_FLOAT64_C(   342.06), SIMDE_FLOAT64_C(  -695.70), SIMDE_FLOAT64_C(    10.48), SIMDE_FLOAT64_C(   442.82),
      SIMDE_FLOAT64_C(   616.72), SIMDE_FLOAT64_C(   984.26), SIMDE_FLOAT64_C(  -961.30), SIMDE_FLOAT64_C(  -468.43),
      SIMDE_FLOAT64_C(   502.12), SIMDE_FLOAT64_C(   616.01), SIMDE_FLOAT64_C(   251.16), SIMDE_FLOAT64_C(  -965.68),
      SIMDE_FLOAT64_C(   -58.26), SIMDE_FLOAT64_C(  -378.47), SIMDE_FLOAT64_C(  -797.24) };
  static const simde_float64 e[] =
    { SIMDE_FLOAT64_C(   804.74), SIMDE_FLOAT64_C(    14.34), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -349.22),
      SIMDE_FLOAT64_C(   636.24), SIMDE_FLOAT64_C(  -768.54), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   286.35), SIMDE_FLOAT64_C(   335.68), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   -34.78), SIMDE_FLOAT64_C(   173.13), SIMDE_FLOAT64_C(   976.54), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -447.26), SIMDE_FLOAT64_C(   912.85), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   576.51), SIMDE_FLOAT64_C(  -846.91), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   -85.15), SIMDE_FLOAT64_C(   517.86), SIMDE_FLOAT64_C(   577.31), SIMDE_FLOAT64_C(  -280.41),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   325.73), SIMDE_FLOAT64_C(   370.37), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   557.19), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  -422.13), SIMDE_FLOAT64_C(   440.17), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  -386.70), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   156.19),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   765.55), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   342.06), SIMDE_FLOAT64_C(  -695.70), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   442.82),
      SIMDE_FLOAT64_C(   616.72), SIMDE_FLOAT64_C(   984.26), SIMDE_FLOAT64_C(  -961.30), SIMDE_FLOAT64_C(  -468.43),
      SIMDE_FLOAT64_C(   502.12), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   251.16), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) };

  static simde_float64 r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svfloat64_t
      rv,
      av = simde_svld1_f64(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_x_svsel_f64_z(pv, av);

    simde_svst1_f64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vf64(len, e, r, 1);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)];
  simde_float64 a[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf64(HEDLEY_STATIC_CAST(size_t, len), a, SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svfloat64_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_f64(pg, &(a[i]));

    ev = simde_x_svsel_f64_z(pv, av);

    simde_svst1_f64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsel_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1) };
  static const simde_float64 a[] =
    { SIMDE_FLOAT64_C(   503.34), SIMDE_FLOAT64_C(  -710.32), SIMDE_FLOAT64_C(  -539.96), SIMDE_FLOAT64_C(  -271.13),
      SIMDE_FLOAT64_C(   286.21), SIMDE_FLOAT64_C(   413.45), SIMDE_FLOAT64_C(   901.45), SIMDE_FLOAT64_C(  -683.42),
      SIMDE_FLOAT64_C(   818.55), SIMDE_FLOAT64_C(   482.11), SIMDE_FLOAT64_C(   805.82), SIMDE_FLOAT64_C(   830.06),
      SIMDE_FLOAT64_C(   801.73), SIMDE_FLOAT64_C(  -233.39), SIMDE_FLOAT64_C(   681.18), SIMDE_FLOAT64_C(   886.50),
      SIMDE_FLOAT64_C(  -456.42), SIMDE_FLOAT64_C(   823.73), SIMDE_FLOAT64_C(  -614.64), SIMDE_FLOAT64_C(   480.61),
      SIMDE_FLOAT64_C(   107.84), SIMDE_FLOAT64_C(   877.09), SIMDE_FLOAT64_C(   494.09), SIMDE_FLOAT64_C(  -255.57),
      SIMDE_FLOAT64_C(    13.34), SIMDE_FLOAT64_C(  -789.04), SIMDE_FLOAT64_C(   345.69), SIMDE_FLOAT64_C(   553.48),
      SIMDE_FLOAT64_C(  -219.59), SIMDE_FLOAT64_C(   879.74), SIMDE_FLOAT64_C(  -374.27), SIMDE_FLOAT64_C(  -716.25),
      SIMDE_FLOAT64_C(  -830.58), SIMDE_FLOAT64_C(    85.76), SIMDE_FLOAT64_C(    12.63), SIMDE_FLOAT64_C(   455.63),
      SIMDE_FLOAT64_C(  -500.78), SIMDE_FLOAT64_C(   -85.92), SIMDE_FLOAT64_C(   772.21), SIMDE_FLOAT64_C(  -682.24),
      SIMDE_FLOAT64_C(  -603.81), SIMDE_FLOAT64_C(   578.03), SIMDE_FLOAT64_C(  -852.18), SIMDE_FLOAT64_C(  -802.08),
      SIMDE_FLOAT64_C(  -655.36), SIMDE_FLOAT64_C(   829.00), SIMDE_FLOAT64_C(  -915.58), SIMDE_FLOAT64_C(  -111.79),
      SIMDE_FLOAT64_C(   652.73), SIMDE_FLOAT64_C(  -530.22), SIMDE_FLOAT64_C(  -631.18), SIMDE_FLOAT64_C(  -239.43),
      SIMDE_FLOAT64_C(  -653.13), SIMDE_FLOAT64_C(   862.91), SIMDE_FLOAT64_C(   505.00), SIMDE_FLOAT64_C(   360.20),
      SIMDE_FLOAT64_C(  -926.13), SIMDE_FLOAT64_C(  -149.31), SIMDE_FLOAT64_C(   -86.32), SIMDE_FLOAT64_C(  -145.72),
      SIMDE_FLOAT64_C(  -269.57), SIMDE_FLOAT64_C(   539.41), SIMDE_FLOAT64_C(   138.03), SIMDE_FLOAT64_C(  -100.15),
      SIMDE_FLOAT64_C(  -374.82), SIMDE_FLOAT64_C(  -849.34), SIMDE_FLOAT64_C(  -644.52), SIMDE_FLOAT64_C(   124.39),
      SIMDE_FLOAT64_C(    64.74), SIMDE_FLOAT64_C(  -872.31), SIMDE_FLOAT64_C(   442.15), SIMDE_FLOAT64_C(   460.93),
      SIMDE_FLOAT64_C(   705.72), SIMDE_FLOAT64_C(   589.97), SIMDE_FLOAT64_C(   658.85), SIMDE_FLOAT64_C(  -949.64),
      SIMDE_FLOAT64_C(   418.97), SIMDE_FLOAT64_C(   743.26), SIMDE_FLOAT64_C(   -61.43), SIMDE_FLOAT64_C(    71.70),
      SIMDE_FLOAT64_C(  -786.96), SIMDE_FLOAT64_C(   307.39), SIMDE_FLOAT64_C(   832.27), SIMDE_FLOAT64_C(  -440.09),
      SIMDE_FLOAT64_C(   170.30), SIMDE_FLOAT64_C(   337.27), SIMDE_FLOAT64_C(   920.11), SIMDE_FLOAT64_C(   244.17),
      SIMDE_FLOAT64_C(  -812.04), SIMDE_FLOAT64_C(  -166.21), SIMDE_FLOAT64_C(  -901.55), SIMDE_FLOAT64_C(   -81.61),
      SIMDE_FLOAT64_C(  -626.79), SIMDE_FLOAT64_C(   236.48), SIMDE_FLOAT64_C(   818.24), SIMDE_FLOAT64_C(    -1.62),
      SIMDE_FLOAT64_C(   387.14), SIMDE_FLOAT64_C(  -826.28), SIMDE_FLOAT64_C(  -877.23), SIMDE_FLOAT64_C(  -548.12),
      SIMDE_FLOAT64_C(  -698.59), SIMDE_FLOAT64_C(   564.93), SIMDE_FLOAT64_C(   912.81), SIMDE_FLOAT64_C(  -992.87),
      SIMDE_FLOAT64_C(   154.90), SIMDE_FLOAT64_C(   571.65) };
  static const simde_float64 b[] =
    { SIMDE_FLOAT64_C(  -942.51), SIMDE_FLOAT64_C(  -426.13), SIMDE_FLOAT64_C(   314.92), SIMDE_FLOAT64_C(    -3.94),
      SIMDE_FLOAT64_C(   645.57), SIMDE_FLOAT64_C(   527.96), SIMDE_FLOAT64_C(  -696.56), SIMDE_FLOAT64_C(   477.84),
      SIMDE_FLOAT64_C(  -912.14), SIMDE_FLOAT64_C(   473.75), SIMDE_FLOAT64_C(  -184.89), SIMDE_FLOAT64_C(  -992.03),
      SIMDE_FLOAT64_C(  -282.09), SIMDE_FLOAT64_C(     3.06), SIMDE_FLOAT64_C(  -158.23), SIMDE_FLOAT64_C(  -183.64),
      SIMDE_FLOAT64_C(   921.45), SIMDE_FLOAT64_C(   214.97), SIMDE_FLOAT64_C(  -947.16), SIMDE_FLOAT64_C(   739.69),
      SIMDE_FLOAT64_C(  -786.65), SIMDE_FLOAT64_C(   439.99), SIMDE_FLOAT64_C(   913.41), SIMDE_FLOAT64_C(  -663.87),
      SIMDE_FLOAT64_C(   891.86), SIMDE_FLOAT64_C(  -785.18), SIMDE_FLOAT64_C(   901.06), SIMDE_FLOAT64_C(   804.67),
      SIMDE_FLOAT64_C(  -778.05), SIMDE_FLOAT64_C(    55.96), SIMDE_FLOAT64_C(   376.33), SIMDE_FLOAT64_C(  -720.56),
      SIMDE_FLOAT64_C(   629.82), SIMDE_FLOAT64_C(  -308.76), SIMDE_FLOAT64_C(   275.49), SIMDE_FLOAT64_C(   275.39),
      SIMDE_FLOAT64_C(  -780.80), SIMDE_FLOAT64_C(   578.94), SIMDE_FLOAT64_C(  -246.78), SIMDE_FLOAT64_C(  -692.94),
      SIMDE_FLOAT64_C(    52.69), SIMDE_FLOAT64_C(   568.33), SIMDE_FLOAT64_C(  -684.97), SIMDE_FLOAT64_C(   770.60),
      SIMDE_FLOAT64_C(  -428.60), SIMDE_FLOAT64_C(   156.80), SIMDE_FLOAT64_C(  -413.04), SIMDE_FLOAT64_C(  -507.15),
      SIMDE_FLOAT64_C(  -628.23), SIMDE_FLOAT64_C(  -360.20), SIMDE_FLOAT64_C(  -767.46), SIMDE_FLOAT64_C(  -414.87),
      SIMDE_FLOAT64_C(  -920.21), SIMDE_FLOAT64_C(  -854.05), SIMDE_FLOAT64_C(   -78.74), SIMDE_FLOAT64_C(   971.66),
      SIMDE_FLOAT64_C(  -639.22), SIMDE_FLOAT64_C(  -177.69), SIMDE_FLOAT64_C(   776.33), SIMDE_FLOAT64_C(  -417.27),
      SIMDE_FLOAT64_C(   878.27), SIMDE_FLOAT64_C(   152.66), SIMDE_FLOAT64_C(  -137.83), SIMDE_FLOAT64_C(   508.09),
      SIMDE_FLOAT64_C(   843.90), SIMDE_FLOAT64_C(  -862.34), SIMDE_FLOAT64_C(  -216.52), SIMDE_FLOAT64_C(  -936.90),
      SIMDE_FLOAT64_C(   716.60), SIMDE_FLOAT64_C(   536.70), SIMDE_FLOAT64_C(  -629.84), SIMDE_FLOAT64_C(  -230.71),
      SIMDE_FLOAT64_C(   105.04), SIMDE_FLOAT64_C(  -314.80), SIMDE_FLOAT64_C(  -460.11), SIMDE_FLOAT64_C(   676.43),
      SIMDE_FLOAT64_C(   842.00), SIMDE_FLOAT64_C(   126.85), SIMDE_FLOAT64_C(  -830.72), SIMDE_FLOAT64_C(  -786.23),
      SIMDE_FLOAT64_C(   766.65), SIMDE_FLOAT64_C(  -598.18), SIMDE_FLOAT64_C(  -201.10), SIMDE_FLOAT64_C(   846.44),
      SIMDE_FLOAT64_C(  -452.22), SIMDE_FLOAT64_C(   720.15), SIMDE_FLOAT64_C(   818.10), SIMDE_FLOAT64_C(   -91.45),
      SIMDE_FLOAT64_C(  -457.53), SIMDE_FLOAT64_C(   594.43), SIMDE_FLOAT64_C(   491.28), SIMDE_FLOAT64_C(  -579.27),
      SIMDE_FLOAT64_C(  -252.92), SIMDE_FLOAT64_C(  -646.55), SIMDE_FLOAT64_C(   928.83), SIMDE_FLOAT64_C(  -409.02),
      SIMDE_FLOAT64_C(  -508.89), SIMDE_FLOAT64_C(  -287.69), SIMDE_FLOAT64_C(  -345.92), SIMDE_FLOAT64_C(  -792.28),
      SIMDE_FLOAT64_C(  -750.99), SIMDE_FLOAT64_C(    24.25), SIMDE_FLOAT64_C(   -22.99), SIMDE_FLOAT64_C(   354.05),
      SIMDE_FLOAT64_C(   709.44), SIMDE_FLOAT64_C(   516.90) };
  static const simde_float64 e[] =
    { SIMDE_FLOAT64_C(   503.34), SIMDE_FLOAT64_C(  -426.13), SIMDE_FLOAT64_C(   314.92), SIMDE_FLOAT64_C(  -271.13),
      SIMDE_FLOAT64_C(   286.21), SIMDE_FLOAT64_C(   527.96), SIMDE_FLOAT64_C(   901.45), SIMDE_FLOAT64_C(   477.84),
      SIMDE_FLOAT64_C(  -912.14), SIMDE_FLOAT64_C(   473.75), SIMDE_FLOAT64_C(   805.82), SIMDE_FLOAT64_C(   830.06),
      SIMDE_FLOAT64_C(  -282.09), SIMDE_FLOAT64_C(     3.06), SIMDE_FLOAT64_C(   681.18), SIMDE_FLOAT64_C(  -183.64),
      SIMDE_FLOAT64_C(   921.45), SIMDE_FLOAT64_C(   823.73), SIMDE_FLOAT64_C(  -614.64), SIMDE_FLOAT64_C(   739.69),
      SIMDE_FLOAT64_C(   107.84), SIMDE_FLOAT64_C(   439.99), SIMDE_FLOAT64_C(   494.09), SIMDE_FLOAT64_C(  -663.87),
      SIMDE_FLOAT64_C(    13.34), SIMDE_FLOAT64_C(  -789.04), SIMDE_FLOAT64_C(   345.69), SIMDE_FLOAT64_C(   804.67),
      SIMDE_FLOAT64_C(  -778.05), SIMDE_FLOAT64_C(    55.96), SIMDE_FLOAT64_C(   376.33), SIMDE_FLOAT64_C(  -720.56),
      SIMDE_FLOAT64_C(   629.82), SIMDE_FLOAT64_C(    85.76), SIMDE_FLOAT64_C(    12.63), SIMDE_FLOAT64_C(   275.39),
      SIMDE_FLOAT64_C(  -500.78), SIMDE_FLOAT64_C(   578.94), SIMDE_FLOAT64_C(   772.21), SIMDE_FLOAT64_C(  -682.24),
      SIMDE_FLOAT64_C(  -603.81), SIMDE_FLOAT64_C(   568.33), SIMDE_FLOAT64_C(  -852.18), SIMDE_FLOAT64_C(  -802.08),
      SIMDE_FLOAT64_C(  -428.60), SIMDE_FLOAT64_C(   829.00), SIMDE_FLOAT64_C(  -413.04), SIMDE_FLOAT64_C(  -507.15),
      SIMDE_FLOAT64_C(  -628.23), SIMDE_FLOAT64_C(  -530.22), SIMDE_FLOAT64_C(  -631.18), SIMDE_FLOAT64_C(  -414.87),
      SIMDE_FLOAT64_C(  -653.13), SIMDE_FLOAT64_C(  -854.05), SIMDE_FLOAT64_C(   -78.74), SIMDE_FLOAT64_C(   971.66),
      SIMDE_FLOAT64_C(  -639.22), SIMDE_FLOAT64_C(  -177.69), SIMDE_FLOAT64_C(   -86.32), SIMDE_FLOAT64_C(  -417.27),
      SIMDE_FLOAT64_C(   878.27), SIMDE_FLOAT64_C(   152.66), SIMDE_FLOAT64_C(   138.03), SIMDE_FLOAT64_C(   508.09),
      SIMDE_FLOAT64_C(   843.90), SIMDE_FLOAT64_C(  -849.34), SIMDE_FLOAT64_C(  -644.52), SIMDE_FLOAT64_C(   124.39),
      SIMDE_FLOAT64_C(    64.74), SIMDE_FLOAT64_C(   536.70), SIMDE_FLOAT64_C(  -629.84), SIMDE_FLOAT64_C(  -230.71),
      SIMDE_FLOAT64_C(   705.72), SIMDE_FLOAT64_C(   589.97), SIMDE_FLOAT64_C(   658.85), SIMDE_FLOAT64_C(  -949.64),
      SIMDE_FLOAT64_C(   842.00), SIMDE_FLOAT64_C(   743.26), SIMDE_FLOAT64_C(  -830.72), SIMDE_FLOAT64_C(    71.70),
      SIMDE_FLOAT64_C(  -786.96), SIMDE_FLOAT64_C(  -598.18), SIMDE_FLOAT64_C(  -201.10), SIMDE_FLOAT64_C(  -440.09),
      SIMDE_FLOAT64_C(  -452.22), SIMDE_FLOAT64_C(   720.15), SIMDE_FLOAT64_C(   818.10), SIMDE_FLOAT64_C(   -91.45),
      SIMDE_FLOAT64_C(  -457.53), SIMDE_FLOAT64_C(   594.43), SIMDE_FLOAT64_C(   491.28), SIMDE_FLOAT64_C(  -579.27),
      SIMDE_FLOAT64_C(  -252.92), SIMDE_FLOAT64_C(  -646.55), SIMDE_FLOAT64_C(   928.83), SIMDE_FLOAT64_C(    -1.62),
      SIMDE_FLOAT64_C(  -508.89), SIMDE_FLOAT64_C(  -287.69), SIMDE_FLOAT64_C(  -345.92), SIMDE_FLOAT64_C(  -548.12),
      SIMDE_FLOAT64_C(  -750.99), SIMDE_FLOAT64_C(    24.25), SIMDE_FLOAT64_C(   -22.99), SIMDE_FLOAT64_C(  -992.87),
      SIMDE_FLOAT64_C(   154.90), SIMDE_FLOAT64_C(   571.65) };

  static simde_float64 r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svfloat64_t
      rv,
      av = simde_svld1_f64(pg, &(a[i])),
      bv = simde_svld1_f64(pg, &(b[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_svsel_f64(pv, av, bv);

    simde_svst1_f64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vf64(len, e, r, 1);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)];
  simde_float64 a[1024 / sizeof(int64_t)], b[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf64(HEDLEY_STATIC_CAST(size_t, len), a, SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  simde_test_codegen_random_vf64(HEDLEY_STATIC_CAST(size_t, len), b, SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svfloat64_t av, bv, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_f64(pg, &(a[i]));
    bv = simde_svld1_f64(pg, &(b[i]));

    ev = simde_svsel_f64(pv, av, bv);

    simde_svst1_f64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(x_svsel_s8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsel_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(x_svsel_s16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsel_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(x_svsel_s32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsel_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(x_svsel_s64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsel_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(x_svsel_u8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsel_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(x_svsel_u16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsel_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(x_svsel_u32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsel_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(x_svsel_u64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsel_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(x_svsel_f32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsel_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(x_svsel_f64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsel_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-sve-footer.h"
