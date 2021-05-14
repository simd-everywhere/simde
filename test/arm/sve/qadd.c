#define SIMDE_TEST_ARM_SVE_INSN qadd

#include "test-sve.h"
#include "../../../simde/arm/sve/qadd.h"

#include "../../../simde/arm/sve/cmplt.h"

static int
test_simde_svqadd_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t a[] =
    { -INT8_C(  48),  INT8_C(  27), -INT8_C(   1), -INT8_C(  73), -INT8_C(  50), -INT8_C( 124), -INT8_C( 101), -INT8_C(  86),
       INT8_C(   0),  INT8_C( 121), -INT8_C( 101), -INT8_C( 110), -INT8_C(  87), -INT8_C( 125), -INT8_C(  15), -INT8_C( 125),
      -INT8_C(  82),  INT8_C(  41),  INT8_C(  54),  INT8_C(  15),  INT8_C(  91), -INT8_C(  55), -INT8_C(  19), -INT8_C(  16),
      -INT8_C(  99), -INT8_C( 118), -INT8_C(  19),  INT8_C(   4),  INT8_C(  68), -INT8_C(  95), -INT8_C(  96),  INT8_C(  21),
      -INT8_C(  67), -INT8_C(  97), -INT8_C(  52), -INT8_C( 117),  INT8_C(  35),  INT8_C( 103),  INT8_C(  54),  INT8_C(  35),
      -INT8_C(  32), -INT8_C(  47), -INT8_C(  75), -INT8_C( 119),  INT8_C(  84), -INT8_C(  89),  INT8_C(  13),  INT8_C(   2),
      -INT8_C(  48),  INT8_C(  67),  INT8_C(  17),  INT8_C(  43),  INT8_C(  12), -INT8_C(   2),  INT8_C(  27), -INT8_C(  86),
      -INT8_C( 119),  INT8_C(   8), -INT8_C(  82), -INT8_C(  51), -INT8_C(  86),  INT8_C(  78), -INT8_C(  30),  INT8_C( 103),
      -INT8_C(  19), -INT8_C(  82), -INT8_C(  14),  INT8_C(  16),  INT8_C(  21),  INT8_C(  40),  INT8_C(  51), -INT8_C(  11),
      -INT8_C(   7), -INT8_C(  23),      INT8_MAX,  INT8_C(  77), -INT8_C( 112), -INT8_C( 116),  INT8_C(  79),  INT8_C(  96),
      -INT8_C(  49),  INT8_C(  97), -INT8_C( 117), -INT8_C(  36),  INT8_C(  95), -INT8_C(  89), -INT8_C( 122), -INT8_C(  24),
      -INT8_C(  81),  INT8_C(  52), -INT8_C(  74),  INT8_C(  89), -INT8_C( 125), -INT8_C( 104), -INT8_C(  64),  INT8_C( 112),
       INT8_C(  71), -INT8_C(  77), -INT8_C( 127),  INT8_C(  92), -INT8_C(  37), -INT8_C(  76),  INT8_C(  82), -INT8_C(  43),
      -INT8_C(  99), -INT8_C(  47),  INT8_C(  34),  INT8_C(  45),  INT8_C(  93),  INT8_C( 114), -INT8_C( 115),  INT8_C(  44),
      -INT8_C(  45),  INT8_C(  25),  INT8_C(   8),  INT8_C(  50), -INT8_C(  64), -INT8_C( 114),  INT8_C(  27),  INT8_C( 111),
      -INT8_C(  61), -INT8_C(  47), -INT8_C(  55),  INT8_C(  70),  INT8_C( 105), -INT8_C( 119), -INT8_C(  74), -INT8_C(  80),
       INT8_C(  60),  INT8_C(  55),  INT8_C(  13),  INT8_C(  24), -INT8_C(  20),  INT8_C(  95), -INT8_C(  19), -INT8_C( 119),
       INT8_C(  48),  INT8_C(  15), -INT8_C(  73), -INT8_C( 115), -INT8_C( 127),  INT8_C(  68), -INT8_C(  71),  INT8_C(  84),
       INT8_C(  93), -INT8_C(  62), -INT8_C( 121),  INT8_C(  29),  INT8_C(  80), -INT8_C(  94), -INT8_C( 115),  INT8_C(  19),
       INT8_C( 115),  INT8_C(  86),  INT8_C(  89), -INT8_C(  36), -INT8_C(  33),  INT8_C(  16), -INT8_C( 115),  INT8_C(  28),
       INT8_C(  71), -INT8_C( 102),  INT8_C(  52),  INT8_C(  51), -INT8_C(   7),  INT8_C(  33), -INT8_C(  67),  INT8_C(  41),
       INT8_C(  48),  INT8_C( 116), -INT8_C(  74), -INT8_C(  78), -INT8_C(  72),  INT8_C( 111),  INT8_C(   6),  INT8_C(  22),
       INT8_C(  49), -INT8_C( 115),  INT8_C(  51), -INT8_C( 126),  INT8_C(  47), -INT8_C(  64), -INT8_C( 107), -INT8_C(  94),
       INT8_C(  22), -INT8_C(  17),      INT8_MAX, -INT8_C(  10), -INT8_C(   1),  INT8_C(  12),  INT8_C(  18),  INT8_C(  70),
      -INT8_C(  90),  INT8_C(  70),  INT8_C( 122), -INT8_C(  97),  INT8_C( 103),  INT8_C(  55), -INT8_C(  56), -INT8_C( 105),
      -INT8_C(  85),  INT8_C( 126),  INT8_C(  73),  INT8_C(  99), -INT8_C(  19),  INT8_C(  80),  INT8_C( 121),  INT8_C(  31),
      -INT8_C(  35), -INT8_C(  83), -INT8_C(  95),  INT8_C(  13),  INT8_C( 109),  INT8_C(  54), -INT8_C(  81), -INT8_C( 124),
       INT8_C(  37),  INT8_C(  46),  INT8_C( 122),  INT8_C(  36),  INT8_C(  58), -INT8_C( 116),  INT8_C( 107), -INT8_C(  32),
      -INT8_C(  46), -INT8_C(  27),      INT8_MAX,  INT8_C(  57),  INT8_C(  28),  INT8_C(  71), -INT8_C(  48), -INT8_C(  57),
      -INT8_C(  59),  INT8_C(  26),  INT8_C(  42), -INT8_C(  77),  INT8_C( 106), -INT8_C(  92), -INT8_C(  46),  INT8_C(  71),
       INT8_C(  81),  INT8_C( 115),  INT8_C(  84), -INT8_C(  66), -INT8_C(  87),  INT8_C(   4),  INT8_C(  66), -INT8_C(  49),
       INT8_C(  50), -INT8_C(  68), -INT8_C(  13),  INT8_C( 109),  INT8_C(  72),  INT8_C(  94),  INT8_C(  77),  INT8_C(  26),
       INT8_C(  67), -INT8_C(  51),  INT8_C(  83),  INT8_C(  95),  INT8_C(  20),  INT8_C(  36),  INT8_C(  38), -INT8_C(  38),
       INT8_C(  62),  INT8_C(  81), -INT8_C( 115), -INT8_C(  88), -INT8_C(  11),  INT8_C(  95), -INT8_C(  17),  INT8_C(  70),
      -INT8_C(  46),  INT8_C(  68),  INT8_C(   4),  INT8_C( 123),  INT8_C(  72),  INT8_C(  71),  INT8_C(  74),  INT8_C( 122),
       INT8_C(   3),  INT8_C(  62), -INT8_C(  25),  INT8_C(  76), -INT8_C( 100),  INT8_C(  53),  INT8_C( 102), -INT8_C(  32),
       INT8_C(   2), -INT8_C(  70),  INT8_C(  63),  INT8_C(  22), -INT8_C(  34),  INT8_C( 102), -INT8_C(  16),  INT8_C(  28),
      -INT8_C(  73),  INT8_C( 125), -INT8_C(  60), -INT8_C(  84), -INT8_C(  36), -INT8_C(  77), -INT8_C(  14), -INT8_C(  82),
      -INT8_C(   9), -INT8_C(  10),  INT8_C(  42),  INT8_C(  63),  INT8_C(  61),  INT8_C( 116), -INT8_C(  70),  INT8_C(  65),
      -INT8_C(  78), -INT8_C(  95), -INT8_C( 115),  INT8_C(  79), -INT8_C(  42), -INT8_C(  13),  INT8_C(  47), -INT8_C(  40),
      -INT8_C(  83),  INT8_C( 110), -INT8_C(  17), -INT8_C( 117), -INT8_C(  44), -INT8_C(  33), -INT8_C(  89), -INT8_C( 117),
       INT8_C(  93),  INT8_C( 107),  INT8_C(  55),  INT8_C(  57),  INT8_C(  31),  INT8_C(  41), -INT8_C(  24),  INT8_C(  22),
       INT8_C(  32),  INT8_C(  18),  INT8_C(  86),  INT8_C(  93), -INT8_C( 122),  INT8_C(  16), -INT8_C(  98),  INT8_C(  57),
      -INT8_C(  79),  INT8_C(  43), -INT8_C( 120), -INT8_C( 120),  INT8_C(  31), -INT8_C(  73),  INT8_C(  96), -INT8_C(  52),
       INT8_C(  37),  INT8_C(  79),  INT8_C(  88), -INT8_C(   6),  INT8_C(  47), -INT8_C(   1), -INT8_C( 123), -INT8_C( 116),
       INT8_C( 107), -INT8_C(  67), -INT8_C(  59), -INT8_C( 118), -INT8_C(  26), -INT8_C(  83), -INT8_C(  96),  INT8_C(   6),
      -INT8_C(  65), -INT8_C(  10),  INT8_C( 100),  INT8_C(  70),  INT8_C(   6),  INT8_C(   2),      INT8_MAX, -INT8_C(  72),
       INT8_C(  46),  INT8_C(   7),  INT8_C(  64),  INT8_C(  77), -INT8_C(  66), -INT8_C(  96),  INT8_C(  25), -INT8_C(  29),
      -INT8_C(  16),  INT8_C( 113), -INT8_C(  35),  INT8_C(  31),  INT8_C( 113),  INT8_C(  99), -INT8_C(  85), -INT8_C(  36),
       INT8_C(  32),  INT8_C( 112),  INT8_C( 102),  INT8_C(   6),  INT8_C(  30),  INT8_C(   6),  INT8_C(  13), -INT8_C(  35),
      -INT8_C(   3),  INT8_C( 113),  INT8_C(  35),  INT8_C(   3),  INT8_C( 115), -INT8_C(  94), -INT8_C(  69), -INT8_C(  95),
      -INT8_C(  87), -INT8_C(   5), -INT8_C(  18),  INT8_C( 103), -INT8_C( 100),  INT8_C(   8),  INT8_C(  75), -INT8_C( 116),
       INT8_C( 121),  INT8_C(  40), -INT8_C(  85), -INT8_C(  22), -INT8_C( 117),  INT8_C(  86), -INT8_C(  58), -INT8_C(  85),
      -INT8_C(  58),  INT8_C(  44), -INT8_C(  78), -INT8_C(  28),  INT8_C(  51), -INT8_C(  65), -INT8_C(  62),  INT8_C(  48),
       INT8_C(  48), -INT8_C(  27),  INT8_C(  51), -INT8_C(  93), -INT8_C( 120), -INT8_C(  17),  INT8_C(  69),  INT8_C(  49),
      -INT8_C(  22),  INT8_C(  51), -INT8_C( 103), -INT8_C( 122),  INT8_C(  59), -INT8_C(  28),  INT8_C(  18), -INT8_C(  75),
       INT8_C(  12), -INT8_C(  67), -INT8_C(  97), -INT8_C( 104),  INT8_C(  19),  INT8_C( 102),  INT8_C(  67), -INT8_C(  38),
      -INT8_C( 110), -INT8_C(  11), -INT8_C(  66), -INT8_C(  59), -INT8_C(  76),      INT8_MIN, -INT8_C(  11), -INT8_C(  28),
       INT8_C( 102),  INT8_C(  41), -INT8_C( 120), -INT8_C(  18),  INT8_C(  24), -INT8_C(  51),  INT8_C(  31),  INT8_C(   2),
       INT8_C(   0), -INT8_C(  72), -INT8_C( 119),  INT8_C(  60), -INT8_C( 100), -INT8_C( 101), -INT8_C(  15), -INT8_C(  87),
       INT8_C(  89), -INT8_C( 112),  INT8_C(  65),  INT8_C( 108), -INT8_C(  10), -INT8_C( 124),  INT8_C(  70), -INT8_C( 119),
       INT8_C( 122),  INT8_C(   5),  INT8_C(  78),  INT8_C(  46), -INT8_C( 123),  INT8_C(  68),  INT8_C(  19), -INT8_C(  21),
       INT8_C( 109), -INT8_C( 101), -INT8_C(  39), -INT8_C( 123),  INT8_C( 104), -INT8_C(   7), -INT8_C( 121),  INT8_C( 104),
      -INT8_C(  79),  INT8_C(  16), -INT8_C(  92),  INT8_C(  78), -INT8_C(  84), -INT8_C( 107), -INT8_C(   9),  INT8_C(   5),
       INT8_C(  38),  INT8_C(  56),  INT8_C( 113),  INT8_C(  28), -INT8_C(  68), -INT8_C(  72), -INT8_C(  91),  INT8_C(  54),
      -INT8_C(  67), -INT8_C(  12),  INT8_C( 101),  INT8_C(  66),  INT8_C(  56),  INT8_C( 120),  INT8_C(  46), -INT8_C(  91),
       INT8_C(  19),  INT8_C(   7),  INT8_C(  42),  INT8_C( 123),  INT8_C(   0), -INT8_C(  79), -INT8_C(  29), -INT8_C(  78),
      -INT8_C(  62), -INT8_C( 120),  INT8_C(   0),  INT8_C( 110),  INT8_C(  29), -INT8_C(   9),  INT8_C( 115),  INT8_C(  67),
       INT8_C(  47), -INT8_C(  28),  INT8_C(  96), -INT8_C(  21), -INT8_C( 100),  INT8_C(   5),  INT8_C(  34),  INT8_C(  89),
      -INT8_C(   7), -INT8_C( 121), -INT8_C( 100),  INT8_C(  49), -INT8_C(   1), -INT8_C(  54), -INT8_C(  42),  INT8_C(  18),
      -INT8_C(  47),  INT8_C(   0), -INT8_C( 115), -INT8_C(  46), -INT8_C(  78),  INT8_C( 112), -INT8_C( 124),  INT8_C( 116),
      -INT8_C(   8), -INT8_C( 124), -INT8_C(  30),  INT8_C(  22),  INT8_C( 123),  INT8_C(  85),  INT8_C(  89), -INT8_C(  86),
       INT8_C(  57), -INT8_C(  71), -INT8_C( 107), -INT8_C(  42), -INT8_C(  65), -INT8_C(  73),  INT8_C(  47), -INT8_C(  72),
       INT8_C(  62), -INT8_C(  53), -INT8_C(  22),  INT8_C(  61), -INT8_C( 107), -INT8_C(  64),  INT8_C(  79),  INT8_C( 103),
      -INT8_C(  63), -INT8_C(  36),  INT8_C(  57),  INT8_C( 115),  INT8_C(  77), -INT8_C(  67), -INT8_C(  25),  INT8_C(  69),
       INT8_C(  65), -INT8_C(  55),  INT8_C(  91), -INT8_C(  68),  INT8_C(  30), -INT8_C(  75),  INT8_C( 102),  INT8_C(  87),
       INT8_C( 110), -INT8_C(   5),  INT8_C(  45),  INT8_C(  45), -INT8_C(  77),  INT8_C(  93), -INT8_C(  26) };
  static const int8_t b[] =
    {  INT8_C(  64),  INT8_C(  33), -INT8_C(   2), -INT8_C(  46),  INT8_C(   2), -INT8_C(  32),  INT8_C(  23), -INT8_C( 120),
       INT8_C( 102),  INT8_C(  55),  INT8_C(  17),  INT8_C(  88),  INT8_C( 101),  INT8_C(  30),  INT8_C(  18),  INT8_C(  94),
       INT8_C(  99),  INT8_C(  39),  INT8_C(  47), -INT8_C(  40), -INT8_C( 125),  INT8_C(  91),  INT8_C(   4),  INT8_C(  67),
      -INT8_C( 115),  INT8_C(  99),  INT8_C(  36),  INT8_C(  74), -INT8_C(  76), -INT8_C( 112),  INT8_C(  36), -INT8_C(  12),
      -INT8_C(  79),  INT8_C(  34), -INT8_C(  58), -INT8_C(  76),  INT8_C(   2), -INT8_C(  34),  INT8_C(  60),  INT8_C( 105),
       INT8_C(  21),  INT8_C(  77), -INT8_C(  63),  INT8_C( 123),  INT8_C( 108), -INT8_C(  45), -INT8_C(  39), -INT8_C(  49),
      -INT8_C(   5),  INT8_C(   9), -INT8_C(  89),  INT8_C( 126),  INT8_C( 100), -INT8_C(  85), -INT8_C(  63), -INT8_C(  15),
       INT8_C(  15), -INT8_C(  27),  INT8_C(  59), -INT8_C(  61),  INT8_C( 117),  INT8_C(  96), -INT8_C(  73),  INT8_C(  38),
      -INT8_C( 126),  INT8_C( 126), -INT8_C(  38), -INT8_C( 123),  INT8_C(  92),  INT8_C(  22), -INT8_C(  18),  INT8_C( 113),
       INT8_C( 100), -INT8_C(  81), -INT8_C(  20), -INT8_C(  48), -INT8_C( 125), -INT8_C(  58), -INT8_C(  97),  INT8_C( 126),
      -INT8_C(  49),  INT8_C(  71), -INT8_C(   4),  INT8_C(  51), -INT8_C(  14), -INT8_C(  67),  INT8_C(  37),  INT8_C(   1),
      -INT8_C(  94),  INT8_C(  96), -INT8_C(  60),  INT8_C(  23), -INT8_C(  64),  INT8_C( 124),  INT8_C(  61),  INT8_C(  67),
      -INT8_C(   6),  INT8_C(  24), -INT8_C(  56),  INT8_C(  86),  INT8_C(  46), -INT8_C(  74), -INT8_C(  57), -INT8_C( 110),
       INT8_C( 101), -INT8_C(  76),  INT8_C(  98), -INT8_C(  24),  INT8_C( 122),  INT8_C(   2),  INT8_C( 102),  INT8_C(  73),
       INT8_C(  73),  INT8_C(  98),  INT8_C( 124),  INT8_C(  59),  INT8_C(  31), -INT8_C(  95),  INT8_C(  61), -INT8_C(  63),
       INT8_C(   2),  INT8_C(   1), -INT8_C(  40), -INT8_C(  62),  INT8_C( 125),  INT8_C(  22),  INT8_C(   5),  INT8_C( 119),
       INT8_C(  46), -INT8_C(  51), -INT8_C(  51),  INT8_C(  92), -INT8_C( 125), -INT8_C( 107), -INT8_C(  17), -INT8_C(  23),
       INT8_C(  73),  INT8_C(  81), -INT8_C(  47), -INT8_C(  61),  INT8_C(  83),  INT8_C(  56),  INT8_C(  12), -INT8_C( 100),
      -INT8_C( 102), -INT8_C( 120), -INT8_C(  40), -INT8_C(  70),  INT8_C(  42),  INT8_C(  21),  INT8_C( 123),  INT8_C(  44),
       INT8_C(  22),  INT8_C(  84), -INT8_C(  18), -INT8_C( 108),  INT8_C( 106), -INT8_C(  12),  INT8_C(  11), -INT8_C( 104),
      -INT8_C(  63), -INT8_C(  39), -INT8_C(  12),  INT8_C(  69),  INT8_C( 110), -INT8_C(  29),  INT8_C(  46), -INT8_C(  73),
       INT8_C(  53), -INT8_C(   1),  INT8_C( 122), -INT8_C( 120),  INT8_C(  55), -INT8_C( 122),  INT8_C(  37), -INT8_C(  46),
       INT8_C(  14), -INT8_C(   3), -INT8_C( 116),  INT8_C(  56),  INT8_C(  18),  INT8_C(   7),  INT8_C( 100),  INT8_C(  40),
       INT8_C(  91),  INT8_C(  83), -INT8_C(  68), -INT8_C(  59),  INT8_C(  71), -INT8_C(  56),  INT8_C(  93),  INT8_C(   8),
      -INT8_C(  95),  INT8_C(  82),  INT8_C(  77),  INT8_C(  15),  INT8_C(  53),  INT8_C( 123), -INT8_C(  58),  INT8_C( 106),
       INT8_C( 123),  INT8_C(  64), -INT8_C(  13), -INT8_C(  78), -INT8_C(  58),  INT8_C(  24), -INT8_C( 124), -INT8_C(  44),
       INT8_C(  21),  INT8_C(  16),  INT8_C(  13),  INT8_C(  39),  INT8_C(  24),  INT8_C( 113),  INT8_C(  79),  INT8_C( 115),
      -INT8_C(  60),  INT8_C(  12),  INT8_C(  57),  INT8_C(  11), -INT8_C(  44), -INT8_C( 106),  INT8_C(  20),  INT8_C( 117),
      -INT8_C(  24),  INT8_C(  97), -INT8_C( 124),  INT8_C(  30), -INT8_C(  35),  INT8_C(  74), -INT8_C( 120),  INT8_C(  88),
      -INT8_C( 118),  INT8_C( 123),  INT8_C(  10),  INT8_C(  80), -INT8_C( 109), -INT8_C( 113),  INT8_C(  36), -INT8_C(  88),
      -INT8_C(  97),  INT8_C(  49), -INT8_C(  49), -INT8_C(  73), -INT8_C(  93),  INT8_C(  31),  INT8_C(  43),  INT8_C( 103),
       INT8_C(  43),  INT8_C( 100),  INT8_C( 115), -INT8_C(   1), -INT8_C(   6), -INT8_C( 121),  INT8_C( 116), -INT8_C(  29),
      -INT8_C(  24), -INT8_C(   8),  INT8_C(   1), -INT8_C(  59),  INT8_C(  66), -INT8_C( 119),  INT8_C(  29), -INT8_C(  52),
       INT8_C(   5),  INT8_C(  40),  INT8_C(  28), -INT8_C( 104), -INT8_C(  73),  INT8_C(  64),  INT8_C(  65),  INT8_C(  86),
       INT8_C( 114),  INT8_C(  16),  INT8_C(  14),  INT8_C(  21),  INT8_C(  47),  INT8_C(  57),  INT8_C( 124),  INT8_C(  90),
      -INT8_C(  99), -INT8_C(  17),  INT8_C(  89), -INT8_C( 105),  INT8_C( 118), -INT8_C(  51),  INT8_C( 122),  INT8_C(  95),
      -INT8_C(  59),  INT8_C( 123),  INT8_C(  36),  INT8_C(   7),  INT8_C(   5),  INT8_C(  66), -INT8_C(  45),  INT8_C(  10),
       INT8_C( 106), -INT8_C(  17), -INT8_C(  94),  INT8_C(  33),  INT8_C(  48), -INT8_C(  29),  INT8_C( 119), -INT8_C(  94),
      -INT8_C(  12), -INT8_C( 123), -INT8_C(  73),  INT8_C(  35), -INT8_C(  66),  INT8_C(  51),  INT8_C( 126),  INT8_C(  91),
       INT8_C(  35), -INT8_C(  41), -INT8_C(  13), -INT8_C( 103), -INT8_C(  91),  INT8_C( 109), -INT8_C(   8),  INT8_C( 106),
      -INT8_C(  23),  INT8_C(  29),  INT8_C( 114), -INT8_C(  18),  INT8_C(  95),  INT8_C(  69), -INT8_C(   8), -INT8_C(  55),
       INT8_C(  53), -INT8_C( 102), -INT8_C(  22),  INT8_C( 101),  INT8_C( 126),  INT8_C(  97),  INT8_C(   7),  INT8_C( 114),
      -INT8_C(  25), -INT8_C(  66), -INT8_C( 107), -INT8_C(  91), -INT8_C(  15),  INT8_C(  19),  INT8_C(   1),  INT8_C(  20),
      -INT8_C(  21), -INT8_C(  12), -INT8_C(  82), -INT8_C( 112),  INT8_C(  97), -INT8_C(  90), -INT8_C(   6),  INT8_C(  74),
      -INT8_C(  61),  INT8_C( 108),  INT8_C(  56),  INT8_C(  34), -INT8_C(  78),  INT8_C(  48), -INT8_C(  21), -INT8_C(  25),
      -INT8_C(  53), -INT8_C(  43),  INT8_C(  76),  INT8_C(  73),  INT8_C(  55),  INT8_C(  83), -INT8_C(  69),  INT8_C(  30),
       INT8_C(  17),  INT8_C(  80), -INT8_C(  61),  INT8_C(   2),  INT8_C( 100), -INT8_C(  60),  INT8_C(  23),  INT8_C(  79),
      -INT8_C(  72), -INT8_C(  59), -INT8_C(  33),  INT8_C(  26),  INT8_C( 107), -INT8_C(  39),  INT8_C( 100),  INT8_C(  47),
       INT8_C(  70), -INT8_C(  99),  INT8_C(  81), -INT8_C(   8), -INT8_C(  51),  INT8_C(  61), -INT8_C(  33), -INT8_C( 104),
       INT8_C(  18),  INT8_C(  43), -INT8_C(  31),  INT8_C(  73),  INT8_C( 126), -INT8_C( 100),  INT8_C( 103), -INT8_C( 113),
      -INT8_C(  19),  INT8_C(  43), -INT8_C( 111),  INT8_C(  81), -INT8_C(  17), -INT8_C(  88), -INT8_C(  96), -INT8_C(  88),
       INT8_C( 109),      INT8_MAX, -INT8_C(  62), -INT8_C(  39),  INT8_C(  88),  INT8_C(  38),  INT8_C(   8), -INT8_C(  98),
      -INT8_C(  61),  INT8_C(  89), -INT8_C( 106), -INT8_C( 111), -INT8_C( 106),  INT8_C( 117),  INT8_C(  41), -INT8_C(  87),
      -INT8_C(  96),  INT8_C(  11), -INT8_C(  14),  INT8_C(  30), -INT8_C(  89),  INT8_C(  90), -INT8_C(  83), -INT8_C( 108),
      -INT8_C( 123),  INT8_C(  63), -INT8_C(  27),  INT8_C( 116), -INT8_C(  25), -INT8_C( 123),  INT8_C(  28),  INT8_C(  85),
       INT8_C(   4), -INT8_C(  34),  INT8_C(  46),  INT8_C(  93),  INT8_C(   5),  INT8_C(  54), -INT8_C(   5), -INT8_C(  56),
      -INT8_C( 113), -INT8_C( 110),  INT8_C(  89),  INT8_C(  38),  INT8_C(   7), -INT8_C( 125), -INT8_C(  49), -INT8_C(  88),
      -INT8_C( 114), -INT8_C(  63), -INT8_C(  58),  INT8_C(  53),  INT8_C(  27),  INT8_C( 116), -INT8_C(  54), -INT8_C(  96),
      -INT8_C(  77), -INT8_C(  81),  INT8_C(  21), -INT8_C( 102),  INT8_C(  53),  INT8_C(  49), -INT8_C(  17),  INT8_C(  57),
       INT8_C(  16),  INT8_C(  29), -INT8_C( 106),  INT8_C(  21),  INT8_C(  83), -INT8_C( 110), -INT8_C(  35), -INT8_C(  29),
       INT8_C(  36),  INT8_C(  55),  INT8_C(   9),  INT8_C(  43), -INT8_C(  70), -INT8_C(  40), -INT8_C(  45),  INT8_C(  72),
      -INT8_C( 103), -INT8_C( 102),  INT8_C( 125), -INT8_C(  75),  INT8_C(  14),  INT8_C(  71),  INT8_C(  85), -INT8_C(  63),
      -INT8_C(   9),  INT8_C( 106),  INT8_C(  91),  INT8_C(  44), -INT8_C( 100),  INT8_C(  75),  INT8_C( 101), -INT8_C(  84),
       INT8_C( 104), -INT8_C(   4), -INT8_C(  63), -INT8_C(  68), -INT8_C( 114), -INT8_C(  98), -INT8_C(  97), -INT8_C(  78),
      -INT8_C(  43), -INT8_C(  88), -INT8_C(  35), -INT8_C( 113),      INT8_MIN, -INT8_C(  79), -INT8_C(  41),  INT8_C(  25),
       INT8_C(  75),  INT8_C(  85), -INT8_C(  50),  INT8_C(  89), -INT8_C( 100),  INT8_C(  36),  INT8_C(  26), -INT8_C( 109),
      -INT8_C( 114),  INT8_C( 117), -INT8_C(  65),  INT8_C(  42), -INT8_C(  64),  INT8_C(  37), -INT8_C(  42),  INT8_C(  41),
       INT8_C(  33), -INT8_C( 105), -INT8_C(  27), -INT8_C(  81),  INT8_C(  54), -INT8_C( 124),  INT8_C(  97),  INT8_C(  11),
       INT8_C(  44),  INT8_C(  62), -INT8_C( 101), -INT8_C(  84), -INT8_C(  17),  INT8_C( 114), -INT8_C(  59),  INT8_C(  58),
      -INT8_C(  57), -INT8_C( 108), -INT8_C( 109),  INT8_C( 100), -INT8_C(  72), -INT8_C(  83), -INT8_C(   9),  INT8_C(  70),
       INT8_C(  35), -INT8_C(  73),  INT8_C( 113), -INT8_C(  29), -INT8_C(  36),  INT8_C(  71),  INT8_C(  12), -INT8_C(   3),
      -INT8_C(  33), -INT8_C(  15), -INT8_C(  84),  INT8_C(  21),  INT8_C( 117),  INT8_C(  13),  INT8_C(  32), -INT8_C(  95),
       INT8_C(  75), -INT8_C(  69),  INT8_C(  77),  INT8_C(  59),  INT8_C(  46),  INT8_C(  19),  INT8_C( 117), -INT8_C(  11),
      -INT8_C(  89),  INT8_C(   9),  INT8_C(  89),  INT8_C(  95), -INT8_C(  74),  INT8_C(  81), -INT8_C(  91), -INT8_C(  39),
       INT8_C(   8),  INT8_C(  22), -INT8_C(  67), -INT8_C(  28),  INT8_C(  94), -INT8_C(  55), -INT8_C(  31),  INT8_C(  61),
      -INT8_C(  69), -INT8_C( 115),  INT8_C(  82),  INT8_C(  48), -INT8_C( 102),  INT8_C( 114), -INT8_C(  46), -INT8_C(  27),
       INT8_C(  46),  INT8_C(  31),  INT8_C(  32),  INT8_C(  92),  INT8_C(  50), -INT8_C( 106),  INT8_C(  81) };
  static const int8_t e[] =
    {  INT8_C(  16),  INT8_C(  60), -INT8_C(   3), -INT8_C( 119), -INT8_C(  48),      INT8_MIN, -INT8_C(  78),      INT8_MIN,
       INT8_C( 102),      INT8_MAX, -INT8_C(  84), -INT8_C(  22),  INT8_C(  14), -INT8_C(  95),  INT8_C(   3), -INT8_C(  31),
       INT8_C(  17),  INT8_C(  80),  INT8_C( 101), -INT8_C(  25), -INT8_C(  34),  INT8_C(  36), -INT8_C(  15),  INT8_C(  51),
           INT8_MIN, -INT8_C(  19),  INT8_C(  17),  INT8_C(  78), -INT8_C(   8),      INT8_MIN, -INT8_C(  60),  INT8_C(   9),
           INT8_MIN, -INT8_C(  63), -INT8_C( 110),      INT8_MIN,  INT8_C(  37),  INT8_C(  69),  INT8_C( 114),      INT8_MAX,
      -INT8_C(  11),  INT8_C(  30),      INT8_MIN,  INT8_C(   4),      INT8_MAX,      INT8_MIN, -INT8_C(  26), -INT8_C(  47),
      -INT8_C(  53),  INT8_C(  76), -INT8_C(  72),      INT8_MAX,  INT8_C( 112), -INT8_C(  87), -INT8_C(  36), -INT8_C( 101),
      -INT8_C( 104), -INT8_C(  19), -INT8_C(  23), -INT8_C( 112),  INT8_C(  31),      INT8_MAX, -INT8_C( 103),      INT8_MAX,
           INT8_MIN,  INT8_C(  44), -INT8_C(  52), -INT8_C( 107),  INT8_C( 113),  INT8_C(  62),  INT8_C(  33),  INT8_C( 102),
       INT8_C(  93), -INT8_C( 104),  INT8_C( 107),  INT8_C(  29),      INT8_MIN,      INT8_MIN, -INT8_C(  18),      INT8_MAX,
      -INT8_C(  98),      INT8_MAX, -INT8_C( 121),  INT8_C(  15),  INT8_C(  81),      INT8_MIN, -INT8_C(  85), -INT8_C(  23),
           INT8_MIN,      INT8_MAX,      INT8_MIN,  INT8_C( 112),      INT8_MIN,  INT8_C(  20), -INT8_C(   3),      INT8_MAX,
       INT8_C(  65), -INT8_C(  53),      INT8_MIN,      INT8_MAX,  INT8_C(   9),      INT8_MIN,  INT8_C(  25),      INT8_MIN,
       INT8_C(   2), -INT8_C( 123),      INT8_MAX,  INT8_C(  21),      INT8_MAX,  INT8_C( 116), -INT8_C(  13),  INT8_C( 117),
       INT8_C(  28),  INT8_C( 123),      INT8_MAX,  INT8_C( 109), -INT8_C(  33),      INT8_MIN,  INT8_C(  88),  INT8_C(  48),
      -INT8_C(  59), -INT8_C(  46), -INT8_C(  95),  INT8_C(   8),      INT8_MAX, -INT8_C(  97), -INT8_C(  69),  INT8_C(  39),
       INT8_C( 106),  INT8_C(   4), -INT8_C(  38),  INT8_C( 116),      INT8_MIN, -INT8_C(  12), -INT8_C(  36),      INT8_MIN,
       INT8_C( 121),  INT8_C(  96), -INT8_C( 120),      INT8_MIN, -INT8_C(  44),  INT8_C( 124), -INT8_C(  59), -INT8_C(  16),
      -INT8_C(   9),      INT8_MIN,      INT8_MIN, -INT8_C(  41),  INT8_C( 122), -INT8_C(  73),  INT8_C(   8),  INT8_C(  63),
           INT8_MAX,      INT8_MAX,  INT8_C(  71),      INT8_MIN,  INT8_C(  73),  INT8_C(   4), -INT8_C( 104), -INT8_C(  76),
       INT8_C(   8),      INT8_MIN,  INT8_C(  40),  INT8_C( 120),  INT8_C( 103),  INT8_C(   4), -INT8_C(  21), -INT8_C(  32),
       INT8_C( 101),  INT8_C( 115),  INT8_C(  48),      INT8_MIN, -INT8_C(  17), -INT8_C(  11),  INT8_C(  43), -INT8_C(  24),
       INT8_C(  63), -INT8_C( 118), -INT8_C(  65), -INT8_C(  70),  INT8_C(  65), -INT8_C(  57), -INT8_C(   7), -INT8_C(  54),
       INT8_C( 113),  INT8_C(  66),  INT8_C(  59), -INT8_C(  69),  INT8_C(  70), -INT8_C(  44),  INT8_C( 111),  INT8_C(  78),
           INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C(  82),      INT8_MAX,      INT8_MAX, -INT8_C( 114),  INT8_C(   1),
       INT8_C(  38),      INT8_MAX,  INT8_C(  60),  INT8_C(  21), -INT8_C(  77),  INT8_C( 104), -INT8_C(   3), -INT8_C(  13),
      -INT8_C(  14), -INT8_C(  67), -INT8_C(  82),  INT8_C(  52),      INT8_MAX,      INT8_MAX, -INT8_C(   2), -INT8_C(   9),
      -INT8_C(  23),  INT8_C(  58),      INT8_MAX,  INT8_C(  47),  INT8_C(  14),      INT8_MIN,      INT8_MAX,  INT8_C(  85),
      -INT8_C(  70),  INT8_C(  70),  INT8_C(   3),  INT8_C(  87), -INT8_C(   7),      INT8_MAX,      INT8_MIN,  INT8_C(  31),
           INT8_MIN,      INT8_MAX,  INT8_C(  52),  INT8_C(   3), -INT8_C(   3),      INT8_MIN, -INT8_C(  10), -INT8_C(  17),
      -INT8_C(  16),      INT8_MAX,  INT8_C(  35),      INT8_MIN,      INT8_MIN,  INT8_C(  35),  INT8_C( 109),  INT8_C(  54),
       INT8_C(  93),  INT8_C(  32),  INT8_C( 102),  INT8_C( 108),  INT8_C(  66), -INT8_C(  27),      INT8_MAX, -INT8_C(   3),
       INT8_C(  43), -INT8_C(  59),  INT8_C(  84),  INT8_C(  36),  INT8_C(  86), -INT8_C(  83),  INT8_C(  67), -INT8_C(  90),
       INT8_C(  67),  INT8_C( 121), -INT8_C(  87),      INT8_MIN, -INT8_C(  84),      INT8_MAX,  INT8_C(  48),      INT8_MAX,
       INT8_C(  68),  INT8_C(  84),  INT8_C(  18),      INT8_MAX,  INT8_C( 119),      INT8_MAX,      INT8_MAX,      INT8_MAX,
      -INT8_C(  96),  INT8_C(  45),  INT8_C(  64), -INT8_C(  29),  INT8_C(  18),  INT8_C(   2),      INT8_MAX,  INT8_C(  63),
      -INT8_C(  57),  INT8_C(  53),  INT8_C(  99),  INT8_C(  29), -INT8_C(  29),      INT8_MAX, -INT8_C(  61),  INT8_C(  38),
       INT8_C(  33),  INT8_C( 108),      INT8_MIN, -INT8_C(  51),  INT8_C(  12), -INT8_C( 106),  INT8_C( 105),      INT8_MIN,
      -INT8_C(  21),      INT8_MIN, -INT8_C(  31),  INT8_C(  98), -INT8_C(   5),      INT8_MAX,  INT8_C(  56),      INT8_MAX,
      -INT8_C(  43),      INT8_MIN,      INT8_MIN, -INT8_C(  24),      INT8_MIN,  INT8_C(  96),  INT8_C(  39),  INT8_C(  66),
      -INT8_C( 106),      INT8_MAX,  INT8_C(  97),      INT8_MIN,  INT8_C(  51),  INT8_C(  36), -INT8_C(  97),      INT8_MIN,
           INT8_MAX,  INT8_C(   5),  INT8_C(  33),      INT8_MAX,      INT8_MAX,      INT8_MAX, -INT8_C(  17),      INT8_MAX,
       INT8_C(   7), -INT8_C(  48), -INT8_C(  21),  INT8_C(   2),      INT8_MIN,  INT8_C(  35), -INT8_C(  97),  INT8_C(  77),
      -INT8_C( 100),  INT8_C(  31),      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,  INT8_C(  90),  INT8_C(  22),
      -INT8_C(  24),      INT8_MAX,      INT8_MAX,  INT8_C(  28), -INT8_C(  31),  INT8_C(  47),      INT8_MIN,      INT8_MIN,
       INT8_C(  54), -INT8_C( 110),  INT8_C(  17), -INT8_C(  45),  INT8_C(  29),  INT8_C(   0),      INT8_MIN,  INT8_C(  36),
      -INT8_C(  48),  INT8_C(  70),  INT8_C(  39),  INT8_C(  72),  INT8_C( 106), -INT8_C(  58),      INT8_MAX,  INT8_C(   7),
      -INT8_C(  26), -INT8_C(  52),  INT8_C(  31),  INT8_C( 103),  INT8_C(  41),      INT8_MIN,  INT8_C( 125),  INT8_C(  18),
       INT8_C(  54),  INT8_C(  14),  INT8_C(  46),  INT8_C(  23),  INT8_C(  62),      INT8_MAX, -INT8_C( 118),      INT8_MIN,
       INT8_C(  50),      INT8_MAX,  INT8_C(  71),  INT8_C(  79),      INT8_MAX, -INT8_C(  94),  INT8_C( 116),      INT8_MIN,
      -INT8_C(  22),      INT8_MAX, -INT8_C(  76),  INT8_C(  84),  INT8_C(  98),      INT8_MIN,      INT8_MIN,      INT8_MIN,
       INT8_C(  22),  INT8_C( 122), -INT8_C(  80),  INT8_C(  64), -INT8_C(  12),  INT8_C(  46),  INT8_C(  83),      INT8_MIN,
       INT8_C(  60),      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MAX, -INT8_C(  17),      INT8_MIN,
           INT8_MIN,  INT8_C(  55), -INT8_C(  92),  INT8_C(   2), -INT8_C(  38),  INT8_C(  25),      INT8_MIN, -INT8_C(  60),
      -INT8_C(  75),  INT8_C(  36),  INT8_C(  24),  INT8_C(  23),      INT8_MIN,      INT8_MIN,  INT8_C(  97),      INT8_MAX,
      -INT8_C(  18),  INT8_C(  17), -INT8_C(  57), -INT8_C(  29),  INT8_C(  64),  INT8_C(  26),  INT8_C(  13),      INT8_MIN,
      -INT8_C( 101),      INT8_MIN, -INT8_C(   8), -INT8_C(  66),  INT8_C(  26), -INT8_C(  23),  INT8_C(  18), -INT8_C( 126),
           INT8_MIN, -INT8_C(  74), -INT8_C( 124), -INT8_C(   6), -INT8_C(  49), -INT8_C(  12), -INT8_C(  65), -INT8_C( 124),
       INT8_C(  25), -INT8_C(  40), -INT8_C(  99), -INT8_C( 120),  INT8_C(  77), -INT8_C(   2),  INT8_C(  14),  INT8_C(  59),
       INT8_C(  16), -INT8_C(  43),      INT8_MIN,  INT8_C(  81), -INT8_C(  17),      INT8_MIN, -INT8_C(  50), -INT8_C( 116),
       INT8_C( 125), -INT8_C(  57),  INT8_C(  74),      INT8_MAX, -INT8_C(  80),      INT8_MIN,  INT8_C(  25), -INT8_C(  47),
       INT8_C(  19), -INT8_C(  97),      INT8_MAX, -INT8_C(  29), -INT8_C( 109),      INT8_MAX,  INT8_C( 104), -INT8_C(  84),
       INT8_C( 100),  INT8_C(   5),  INT8_C(  52), -INT8_C(  79),  INT8_C(   4),  INT8_C(  68), -INT8_C(  20),  INT8_C(  20),
       INT8_C(  25),  INT8_C(  12),      INT8_MIN,  INT8_C(  10),      INT8_MIN,      INT8_MIN, -INT8_C( 106), -INT8_C(  73),
      -INT8_C(   5), -INT8_C(  32),  INT8_C(  78), -INT8_C(  85),      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(  79),
       INT8_C(   8),  INT8_C(  73),  INT8_C(  51),      INT8_MAX, -INT8_C(  44),      INT8_MAX,  INT8_C(  72),      INT8_MIN,
      -INT8_C(  95),  INT8_C( 124), -INT8_C(  23),      INT8_MAX, -INT8_C(  64), -INT8_C(  42), -INT8_C(  71), -INT8_C(  37),
      -INT8_C(  29),      INT8_MIN, -INT8_C(  27),  INT8_C(  29),  INT8_C(  83),      INT8_MIN,      INT8_MAX,  INT8_C(  78),
       INT8_C(  91),  INT8_C(  34), -INT8_C(   5), -INT8_C( 105), -INT8_C( 117),  INT8_C( 119), -INT8_C(  25),      INT8_MAX,
      -INT8_C(  64),      INT8_MIN,      INT8_MIN,      INT8_MAX, -INT8_C(  73),      INT8_MIN, -INT8_C(  51),  INT8_C(  88),
      -INT8_C(  12), -INT8_C(  73), -INT8_C(   2), -INT8_C(  75), -INT8_C( 114),      INT8_MAX, -INT8_C( 112),  INT8_C( 113),
      -INT8_C(  41),      INT8_MIN, -INT8_C( 114),  INT8_C(  43),      INT8_MAX,  INT8_C(  98),  INT8_C( 121),      INT8_MIN,
           INT8_MAX,      INT8_MIN, -INT8_C(  30),  INT8_C(  17), -INT8_C(  19), -INT8_C(  54),      INT8_MAX, -INT8_C(  83),
      -INT8_C(  27), -INT8_C(  44),  INT8_C(  67),      INT8_MAX,      INT8_MIN,  INT8_C(  17), -INT8_C(  12),  INT8_C(  64),
      -INT8_C(  55), -INT8_C(  14), -INT8_C(  10),  INT8_C(  87),      INT8_MAX, -INT8_C( 122), -INT8_C(  56),      INT8_MAX,
      -INT8_C(   4),      INT8_MIN,      INT8_MAX, -INT8_C(  20), -INT8_C(  72),  INT8_C(  39),  INT8_C(  56),  INT8_C(  60),
           INT8_MAX,  INT8_C(  26),  INT8_C(  77),      INT8_MAX, -INT8_C(  27), -INT8_C(  13),  INT8_C(  55) };

  static int8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t
      rv,
      av = simde_svld1_s8(pg, &(a[i])),
      bv = simde_svld1_s8(pg, &(b[i]));

    rv = simde_svqadd_s8(av, bv);

    simde_svst1_s8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vi8(len, e, r);

  return 0;
#else
  int8_t a[1024], b[1024], e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t av, bv, ev;

    av = simde_svld1_s8(pg, &(a[i]));
    bv = simde_svld1_s8(pg, &(b[i]));

    ev = simde_svqadd_s8(av, bv);

    simde_svst1_s8(pg, &(e[i]), ev);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t a[] =
    { -INT16_C( 22553),  INT16_C( 25632),  INT16_C(  5952),  INT16_C( 21518), -INT16_C( 28694), -INT16_C( 10235),  INT16_C( 26111),  INT16_C(   416),
       INT16_C( 32716), -INT16_C(  4051), -INT16_C(  3177),  INT16_C( 17006),  INT16_C( 25455), -INT16_C( 21628),  INT16_C( 19318),  INT16_C( 23989),
      -INT16_C( 10510),  INT16_C( 13249), -INT16_C( 12307), -INT16_C( 10361), -INT16_C( 29601),  INT16_C( 24239),  INT16_C( 20466), -INT16_C( 16801),
      -INT16_C( 29490),  INT16_C( 26030),  INT16_C(  7296), -INT16_C(  4184),  INT16_C( 11391), -INT16_C(  2661),  INT16_C( 20600),  INT16_C( 27219),
       INT16_C(  5158),  INT16_C(  5277),  INT16_C(  9444),  INT16_C( 17387), -INT16_C( 25679), -INT16_C( 23647),  INT16_C(   234), -INT16_C( 18079),
       INT16_C(  3981),  INT16_C(  3358), -INT16_C( 14805), -INT16_C( 21764), -INT16_C( 26637),  INT16_C( 27552), -INT16_C(  3096),  INT16_C(  3797),
       INT16_C( 29447), -INT16_C(  5342),  INT16_C(  3735),  INT16_C( 18478), -INT16_C( 12375), -INT16_C( 27669),  INT16_C( 19664),  INT16_C( 23884),
       INT16_C( 27483), -INT16_C( 31126),  INT16_C( 26161),  INT16_C(  9265), -INT16_C( 11778), -INT16_C(  6513),  INT16_C( 26052), -INT16_C( 13324),
       INT16_C(  6104),  INT16_C( 28599), -INT16_C(  6875), -INT16_C( 12616), -INT16_C( 23627), -INT16_C( 31391), -INT16_C( 20752),  INT16_C( 19426),
       INT16_C( 19481),  INT16_C( 19154),  INT16_C(   946), -INT16_C( 20369), -INT16_C(   300), -INT16_C( 26474), -INT16_C( 29853),  INT16_C( 15203),
       INT16_C(  6818), -INT16_C( 14421),  INT16_C( 25344), -INT16_C( 19051), -INT16_C(  2554), -INT16_C(  2502),  INT16_C(  7332), -INT16_C( 17086),
       INT16_C(  5224),  INT16_C(  6664),  INT16_C( 30487), -INT16_C(  5173),  INT16_C( 24949), -INT16_C(  9853), -INT16_C(  6420), -INT16_C( 29164),
      -INT16_C( 16639),  INT16_C(   341), -INT16_C(  5598),  INT16_C( 10678), -INT16_C(  3871), -INT16_C( 31457),  INT16_C( 24844),  INT16_C( 29763),
       INT16_C( 19317), -INT16_C( 29554),  INT16_C( 22978),  INT16_C( 14199), -INT16_C(  1349), -INT16_C( 22768),  INT16_C(  9697), -INT16_C(  7626),
      -INT16_C( 29724),  INT16_C(  2019), -INT16_C( 26250),  INT16_C( 22320),  INT16_C( 20361), -INT16_C( 27172),  INT16_C(  8113),  INT16_C(  9737),
      -INT16_C( 26774),  INT16_C( 11443),  INT16_C( 10993), -INT16_C( 21404),  INT16_C( 29733),  INT16_C(  1619), -INT16_C( 30311),  INT16_C( 32488),
      -INT16_C( 13547), -INT16_C( 29819), -INT16_C( 19100), -INT16_C(  4638), -INT16_C( 16892), -INT16_C( 19070), -INT16_C( 29730),  INT16_C( 18652),
      -INT16_C( 28894),  INT16_C(  4981), -INT16_C(  9799), -INT16_C(  8513),  INT16_C(  4941), -INT16_C(  6172), -INT16_C( 13156), -INT16_C( 20123),
      -INT16_C(  5481), -INT16_C(  1220),  INT16_C(  7839), -INT16_C( 23576),  INT16_C( 27357), -INT16_C( 17575),  INT16_C( 13813),  INT16_C(  6147),
       INT16_C( 30916),  INT16_C( 32043), -INT16_C(  5295), -INT16_C( 24740),  INT16_C( 16638), -INT16_C( 25978), -INT16_C(  5363), -INT16_C( 23476),
      -INT16_C( 30507),  INT16_C( 29856), -INT16_C( 30553), -INT16_C( 31721),  INT16_C( 28915), -INT16_C(  6081),  INT16_C( 17061),  INT16_C( 26880),
       INT16_C( 11451),  INT16_C(  3303),  INT16_C( 17175),  INT16_C(  5547),  INT16_C( 12675), -INT16_C( 28497), -INT16_C(  1252), -INT16_C(  3787),
      -INT16_C( 10876),  INT16_C( 11109),  INT16_C( 32093),  INT16_C( 20655), -INT16_C(  4371), -INT16_C( 27847),  INT16_C( 14640), -INT16_C(  5124),
      -INT16_C(  7323),  INT16_C( 31992), -INT16_C( 23770), -INT16_C( 21871),  INT16_C( 16853), -INT16_C(  3782),  INT16_C( 28476), -INT16_C( 16157),
       INT16_C( 18500), -INT16_C( 23829), -INT16_C( 25915), -INT16_C( 19470),  INT16_C( 11144), -INT16_C( 18106),  INT16_C( 16997), -INT16_C( 13660),
      -INT16_C( 25562),  INT16_C( 19527), -INT16_C( 10176),  INT16_C(  5622),  INT16_C( 12569),  INT16_C( 22022), -INT16_C(  5728), -INT16_C(  6890),
       INT16_C(   562), -INT16_C(  2169),  INT16_C( 31132),  INT16_C(  9642), -INT16_C(  3931),  INT16_C(  2782), -INT16_C( 32205),  INT16_C( 22996),
       INT16_C(  6943),  INT16_C( 24485), -INT16_C( 25356),  INT16_C(  3444),  INT16_C( 31437),  INT16_C( 28003),  INT16_C( 31332), -INT16_C( 27054),
      -INT16_C(  9860),  INT16_C(  6285),  INT16_C( 14419), -INT16_C(  1987),  INT16_C(  6952),  INT16_C( 23298), -INT16_C( 10594), -INT16_C( 16972),
       INT16_C( 23282), -INT16_C(  6628), -INT16_C( 28426), -INT16_C( 15373),  INT16_C( 22282),  INT16_C( 28208), -INT16_C( 31791),  INT16_C( 19716),
      -INT16_C( 28068), -INT16_C( 20635), -INT16_C( 23606), -INT16_C(  3417), -INT16_C( 22082),  INT16_C( 23630),  INT16_C(   640),  INT16_C( 29209),
       INT16_C( 13660),  INT16_C( 21080),  INT16_C( 19397), -INT16_C( 12267),  INT16_C( 18082),  INT16_C( 29502),  INT16_C( 17353),  INT16_C(  9664),
       INT16_C(  9941), -INT16_C( 24619),  INT16_C( 31945), -INT16_C( 30831), -INT16_C(  8410), -INT16_C( 22812), -INT16_C(   542),  INT16_C( 15896),
       INT16_C( 28723), -INT16_C(  1903), -INT16_C( 22853),  INT16_C( 24264),  INT16_C(  2028), -INT16_C( 18991), -INT16_C( 28086),  INT16_C(  8155),
      -INT16_C( 20296), -INT16_C( 32322),  INT16_C( 20268),  INT16_C( 21000), -INT16_C(  5073),  INT16_C(  4600),  INT16_C(  4330),  INT16_C(  7503),
      -INT16_C(  8064),  INT16_C( 15381), -INT16_C(  8569),  INT16_C( 29594),  INT16_C( 27621),  INT16_C( 12073),  INT16_C(  1277), -INT16_C( 19122),
       INT16_C(  3252), -INT16_C(  8138),  INT16_C( 16219), -INT16_C( 30157),  INT16_C( 11051),  INT16_C(  5531), -INT16_C(  5316), -INT16_C( 17358),
       INT16_C( 18635),  INT16_C( 21240), -INT16_C( 28122),  INT16_C(  3014), -INT16_C(  4098), -INT16_C(  1222), -INT16_C( 30477), -INT16_C( 22607),
      -INT16_C(  6252), -INT16_C(  4217), -INT16_C( 17882),  INT16_C( 21114),  INT16_C(  5606),  INT16_C(  8807), -INT16_C( 26112), -INT16_C( 13090),
      -INT16_C( 10270),  INT16_C(  2078), -INT16_C(  7063),  INT16_C( 26387) };
  static const int16_t b[] =
    {  INT16_C(  6667),  INT16_C( 13223), -INT16_C( 11457), -INT16_C( 11201),  INT16_C( 27638),  INT16_C(  2839), -INT16_C( 23366), -INT16_C( 14231),
       INT16_C( 19394), -INT16_C( 26975),  INT16_C(  4586),  INT16_C(  8805),  INT16_C( 10545), -INT16_C(  5800),  INT16_C( 11847),  INT16_C( 21167),
       INT16_C( 22088), -INT16_C( 30842), -INT16_C( 15063),  INT16_C(  8027),  INT16_C( 29233), -INT16_C(  5334), -INT16_C( 27882), -INT16_C( 10061),
       INT16_C( 21982), -INT16_C( 13970), -INT16_C( 11162), -INT16_C( 26645),  INT16_C( 17661),  INT16_C( 17536),  INT16_C( 12146), -INT16_C( 17769),
       INT16_C(  7557), -INT16_C( 20927), -INT16_C( 25374),  INT16_C(  5069), -INT16_C(  2290),  INT16_C(  9470), -INT16_C( 19829),  INT16_C( 27133),
       INT16_C( 27399),  INT16_C( 27954),  INT16_C(  7743),  INT16_C( 15621), -INT16_C( 31390), -INT16_C( 11135),  INT16_C(  6325),  INT16_C( 14990),
      -INT16_C( 12491),  INT16_C(  6377), -INT16_C( 18837),  INT16_C( 31019),  INT16_C( 10926),  INT16_C( 14749), -INT16_C( 25892), -INT16_C(  7262),
      -INT16_C( 11002),  INT16_C( 17744),  INT16_C( 22003),  INT16_C( 21890),  INT16_C(  1243), -INT16_C( 28631), -INT16_C( 18660),  INT16_C( 21194),
      -INT16_C( 19578), -INT16_C(  3734), -INT16_C( 27286),  INT16_C(  6250),  INT16_C(  1983), -INT16_C( 25775), -INT16_C(  3166), -INT16_C( 22402),
      -INT16_C( 12344), -INT16_C( 17427),  INT16_C( 28708), -INT16_C(   240),  INT16_C( 14708), -INT16_C( 28529),  INT16_C( 23280),  INT16_C( 30434),
       INT16_C( 19469),  INT16_C( 30567), -INT16_C( 11806), -INT16_C( 24177), -INT16_C(  7975),  INT16_C( 31549), -INT16_C( 17452), -INT16_C( 25565),
       INT16_C(  4234), -INT16_C( 20648),  INT16_C( 26752), -INT16_C(  2898),  INT16_C( 16034), -INT16_C( 28027),  INT16_C( 26520), -INT16_C( 23287),
       INT16_C( 28852), -INT16_C( 27107), -INT16_C( 21438),  INT16_C(  6967),  INT16_C( 29837),  INT16_C( 24982), -INT16_C( 18128), -INT16_C( 17667),
       INT16_C( 21961),  INT16_C( 19049),  INT16_C(  6334),  INT16_C( 24638), -INT16_C( 15530), -INT16_C(  4366), -INT16_C(  1237), -INT16_C(  8301),
      -INT16_C( 20372), -INT16_C( 20875), -INT16_C( 21411), -INT16_C(  5431),  INT16_C( 24353),  INT16_C( 20811),  INT16_C( 18456), -INT16_C(  7925),
       INT16_C( 30110),  INT16_C( 23595),  INT16_C( 27277), -INT16_C(  7236), -INT16_C( 20947),  INT16_C( 22737),  INT16_C( 25770),  INT16_C(  5687),
      -INT16_C( 21483),  INT16_C( 29380), -INT16_C( 29351),  INT16_C( 31324), -INT16_C( 22548),  INT16_C(  1227), -INT16_C( 10513), -INT16_C( 29211),
       INT16_C(  4427), -INT16_C( 10007), -INT16_C( 23173), -INT16_C( 22341), -INT16_C( 29612), -INT16_C(   511),  INT16_C( 14577),  INT16_C(  1556),
      -INT16_C( 10011),  INT16_C( 15992), -INT16_C( 11163),  INT16_C( 20920), -INT16_C( 31877),  INT16_C( 27221),  INT16_C( 14937), -INT16_C( 23048),
      -INT16_C(  7861), -INT16_C( 14723),  INT16_C( 14727), -INT16_C(  9361),  INT16_C( 28869), -INT16_C( 18727), -INT16_C(  4696), -INT16_C( 29252),
       INT16_C( 13509),  INT16_C( 10955), -INT16_C( 31992), -INT16_C( 31877), -INT16_C( 12282),  INT16_C( 24814), -INT16_C(  6646),  INT16_C( 22021),
      -INT16_C( 32057),  INT16_C( 19996), -INT16_C( 29765), -INT16_C( 32471),  INT16_C(   763), -INT16_C( 23497), -INT16_C(  2833), -INT16_C( 19407),
      -INT16_C(   728),  INT16_C( 12766),  INT16_C( 22912), -INT16_C( 30796), -INT16_C( 24023),  INT16_C( 13543), -INT16_C(  4984),  INT16_C( 20618),
      -INT16_C( 22930),  INT16_C( 10910), -INT16_C( 14286),  INT16_C( 11691), -INT16_C(  7478), -INT16_C( 17711),  INT16_C(   982), -INT16_C(   146),
       INT16_C( 19712), -INT16_C( 32720), -INT16_C(  7002), -INT16_C( 12281), -INT16_C(  4473),  INT16_C(  3844), -INT16_C( 28966),  INT16_C( 18783),
      -INT16_C(   460),  INT16_C( 26227),  INT16_C(  7878), -INT16_C( 28524),  INT16_C( 25856), -INT16_C( 10422), -INT16_C( 18072),  INT16_C( 26838),
       INT16_C(  1542), -INT16_C( 21271), -INT16_C(  3862),  INT16_C( 29052), -INT16_C( 32545), -INT16_C( 18047), -INT16_C(  8178),  INT16_C( 17154),
       INT16_C( 30174), -INT16_C( 23383),  INT16_C( 15763), -INT16_C( 27595),  INT16_C( 32675),  INT16_C(  2923),  INT16_C( 16696),  INT16_C( 15988),
       INT16_C( 23879),  INT16_C( 12779),  INT16_C( 26445),  INT16_C( 11427),  INT16_C(  9448), -INT16_C(  2330), -INT16_C(  6140), -INT16_C(  7367),
      -INT16_C(  7330), -INT16_C(  3705), -INT16_C( 17376), -INT16_C( 15483), -INT16_C(  4036),  INT16_C( 29903),  INT16_C( 17201),  INT16_C( 30899),
      -INT16_C( 24928), -INT16_C(  4694),  INT16_C( 19717), -INT16_C(  4838),  INT16_C(   113),  INT16_C( 30180),  INT16_C(  7656),  INT16_C( 18008),
      -INT16_C(  8192),  INT16_C(  8504), -INT16_C( 16996), -INT16_C( 10012), -INT16_C( 19538), -INT16_C(  8371),  INT16_C(   246), -INT16_C( 27048),
       INT16_C(   670), -INT16_C( 23676), -INT16_C( 25009), -INT16_C( 16239),  INT16_C( 30110), -INT16_C( 31179), -INT16_C( 29038), -INT16_C( 27699),
       INT16_C(  1390),  INT16_C(  2740), -INT16_C( 26430),  INT16_C( 28899),  INT16_C( 12364),  INT16_C( 16976), -INT16_C( 22480), -INT16_C( 12583),
       INT16_C( 23978), -INT16_C(  1679),  INT16_C(   763), -INT16_C( 26183), -INT16_C(  4489),  INT16_C(  2591), -INT16_C(  4996), -INT16_C(  5475),
       INT16_C( 20977), -INT16_C( 19211), -INT16_C( 10007),  INT16_C( 13604),  INT16_C( 29704),  INT16_C( 14456),  INT16_C( 20764), -INT16_C( 14842),
       INT16_C( 30638), -INT16_C( 22081),  INT16_C( 30842), -INT16_C(  3774),  INT16_C( 24935), -INT16_C(  7173), -INT16_C( 26546),  INT16_C( 16334),
      -INT16_C( 15383), -INT16_C( 11277),  INT16_C(  6299), -INT16_C( 23800), -INT16_C( 32628), -INT16_C( 22053), -INT16_C(  7727),  INT16_C( 32623),
       INT16_C( 12120), -INT16_C( 11736),  INT16_C( 27303),  INT16_C(  3780), -INT16_C( 16436),  INT16_C(  6898), -INT16_C( 16296),  INT16_C( 16729),
       INT16_C( 19843),  INT16_C(  7700),  INT16_C(  7525), -INT16_C(  3647) };
  static const int16_t e[] =
    { -INT16_C( 15886),        INT16_MAX, -INT16_C(  5505),  INT16_C( 10317), -INT16_C(  1056), -INT16_C(  7396),  INT16_C(  2745), -INT16_C( 13815),
             INT16_MAX, -INT16_C( 31026),  INT16_C(  1409),  INT16_C( 25811),        INT16_MAX, -INT16_C( 27428),  INT16_C( 31165),        INT16_MAX,
       INT16_C( 11578), -INT16_C( 17593), -INT16_C( 27370), -INT16_C(  2334), -INT16_C(   368),  INT16_C( 18905), -INT16_C(  7416), -INT16_C( 26862),
      -INT16_C(  7508),  INT16_C( 12060), -INT16_C(  3866), -INT16_C( 30829),  INT16_C( 29052),  INT16_C( 14875),  INT16_C( 32746),  INT16_C(  9450),
       INT16_C( 12715), -INT16_C( 15650), -INT16_C( 15930),  INT16_C( 22456), -INT16_C( 27969), -INT16_C( 14177), -INT16_C( 19595),  INT16_C(  9054),
       INT16_C( 31380),  INT16_C( 31312), -INT16_C(  7062), -INT16_C(  6143),        INT16_MIN,  INT16_C( 16417),  INT16_C(  3229),  INT16_C( 18787),
       INT16_C( 16956),  INT16_C(  1035), -INT16_C( 15102),        INT16_MAX, -INT16_C(  1449), -INT16_C( 12920), -INT16_C(  6228),  INT16_C( 16622),
       INT16_C( 16481), -INT16_C( 13382),        INT16_MAX,  INT16_C( 31155), -INT16_C( 10535),        INT16_MIN,  INT16_C(  7392),  INT16_C(  7870),
      -INT16_C( 13474),  INT16_C( 24865),        INT16_MIN, -INT16_C(  6366), -INT16_C( 21644),        INT16_MIN, -INT16_C( 23918), -INT16_C(  2976),
       INT16_C(  7137),  INT16_C(  1727),  INT16_C( 29654), -INT16_C( 20609),  INT16_C( 14408),        INT16_MIN, -INT16_C(  6573),        INT16_MAX,
       INT16_C( 26287),  INT16_C( 16146),  INT16_C( 13538),        INT16_MIN, -INT16_C( 10529),  INT16_C( 29047), -INT16_C( 10120),        INT16_MIN,
       INT16_C(  9458), -INT16_C( 13984),        INT16_MAX, -INT16_C(  8071),        INT16_MAX,        INT16_MIN,  INT16_C( 20100),        INT16_MIN,
       INT16_C( 12213), -INT16_C( 26766), -INT16_C( 27036),  INT16_C( 17645),  INT16_C( 25966), -INT16_C(  6475),  INT16_C(  6716),  INT16_C( 12096),
             INT16_MAX, -INT16_C( 10505),  INT16_C( 29312),        INT16_MAX, -INT16_C( 16879), -INT16_C( 27134),  INT16_C(  8460), -INT16_C( 15927),
             INT16_MIN, -INT16_C( 18856),        INT16_MIN,  INT16_C( 16889),        INT16_MAX, -INT16_C(  6361),  INT16_C( 26569),  INT16_C(  1812),
       INT16_C(  3336),        INT16_MAX,        INT16_MAX, -INT16_C( 28640),  INT16_C(  8786),  INT16_C( 24356), -INT16_C(  4541),        INT16_MAX,
             INT16_MIN, -INT16_C(   439),        INT16_MIN,  INT16_C( 26686),        INT16_MIN, -INT16_C( 17843),        INT16_MIN, -INT16_C( 10559),
      -INT16_C( 24467), -INT16_C(  5026),        INT16_MIN, -INT16_C( 30854), -INT16_C( 24671), -INT16_C(  6683),  INT16_C(  1421), -INT16_C( 18567),
      -INT16_C( 15492),  INT16_C( 14772), -INT16_C(  3324), -INT16_C(  2656), -INT16_C(  4520),  INT16_C(  9646),  INT16_C( 28750), -INT16_C( 16901),
       INT16_C( 23055),  INT16_C( 17320),  INT16_C(  9432),        INT16_MIN,        INT16_MAX,        INT16_MIN, -INT16_C( 10059),        INT16_MIN,
      -INT16_C( 16998),        INT16_MAX,        INT16_MIN,        INT16_MIN,  INT16_C( 16633),  INT16_C( 18733),  INT16_C( 10415),        INT16_MAX,
      -INT16_C( 20606),  INT16_C( 23299), -INT16_C( 12590), -INT16_C( 26924),  INT16_C( 13438),        INT16_MIN, -INT16_C(  4085), -INT16_C( 23194),
      -INT16_C( 11604),  INT16_C( 23875),        INT16_MAX, -INT16_C( 10141), -INT16_C( 28394), -INT16_C( 14304),  INT16_C(  9656),  INT16_C( 15494),
      -INT16_C( 30253),        INT16_MAX,        INT16_MIN, -INT16_C( 10180),  INT16_C(  9375), -INT16_C( 21493),  INT16_C( 29458), -INT16_C( 16303),
             INT16_MAX,        INT16_MIN,        INT16_MIN, -INT16_C( 31751),  INT16_C(  6671), -INT16_C( 14262), -INT16_C( 11969),  INT16_C(  5123),
      -INT16_C( 26022),        INT16_MAX, -INT16_C(  2298), -INT16_C( 22902),        INT16_MAX,  INT16_C( 11600), -INT16_C( 23800),  INT16_C( 19948),
       INT16_C(  2104), -INT16_C( 23440),  INT16_C( 27270),        INT16_MAX,        INT16_MIN, -INT16_C( 15265),        INT16_MIN,        INT16_MAX,
             INT16_MAX,  INT16_C(  1102), -INT16_C(  9593), -INT16_C( 24151),        INT16_MAX,  INT16_C( 30926),        INT16_MAX, -INT16_C( 11066),
       INT16_C( 14019),  INT16_C( 19064),        INT16_MAX,  INT16_C(  9440),  INT16_C( 16400),  INT16_C( 20968), -INT16_C( 16734), -INT16_C( 24339),
       INT16_C( 15952), -INT16_C( 10333),        INT16_MIN, -INT16_C( 30856),  INT16_C( 18246),        INT16_MAX, -INT16_C( 14590),        INT16_MAX,
             INT16_MIN, -INT16_C( 25329), -INT16_C(  3889), -INT16_C(  8255), -INT16_C( 21969),        INT16_MAX,  INT16_C(  8296),        INT16_MAX,
       INT16_C(  5468),  INT16_C( 29584),  INT16_C(  2401), -INT16_C( 22279), -INT16_C(  1456),  INT16_C( 21131),  INT16_C( 17599), -INT16_C( 17384),
       INT16_C( 10611),        INT16_MIN,  INT16_C(  6936),        INT16_MIN,  INT16_C( 21700),        INT16_MIN, -INT16_C( 29580), -INT16_C( 11803),
       INT16_C( 30113),  INT16_C(   837),        INT16_MIN,        INT16_MAX,  INT16_C( 14392), -INT16_C(  2015),        INT16_MIN, -INT16_C(  4428),
       INT16_C(  3682),        INT16_MIN,  INT16_C( 21031), -INT16_C(  5183), -INT16_C(  9562),  INT16_C(  7191), -INT16_C(   666),  INT16_C(  2028),
       INT16_C( 12913), -INT16_C(  3830), -INT16_C( 18576),        INT16_MAX,        INT16_MAX,  INT16_C( 26529),  INT16_C( 22041),        INT16_MIN,
             INT16_MAX, -INT16_C( 30219),        INT16_MAX,        INT16_MIN,        INT16_MAX, -INT16_C(  1642), -INT16_C( 31862), -INT16_C(  1024),
       INT16_C(  3252),  INT16_C(  9963), -INT16_C( 21823), -INT16_C( 20786),        INT16_MIN, -INT16_C( 23275),        INT16_MIN,  INT16_C( 10016),
       INT16_C(  5868), -INT16_C( 15953),  INT16_C(  9421),  INT16_C( 24894), -INT16_C( 10830),  INT16_C( 15705),        INT16_MIN,  INT16_C(  3639),
       INT16_C(  9573),  INT16_C(  9778),  INT16_C(   462),  INT16_C( 22740) };

  static int16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t
      rv,
      av = simde_svld1_s16(pg, &(a[i])),
      bv = simde_svld1_s16(pg, &(b[i]));

    rv = simde_svqadd_s16(av, bv);

    simde_svst1_s16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vi16(len, e, r);

  return 0;
#else
  int16_t a[1024 / sizeof(int16_t)], b[1024 / sizeof(int16_t)], e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t av, bv, ev;

    av = simde_svld1_s16(pg, &(a[i]));
    bv = simde_svld1_s16(pg, &(b[i]));

    ev = simde_svqadd_s16(av, bv);

    simde_svst1_s16(pg, &(e[i]), ev);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t a[] =
    { -INT32_C(  1186472446),  INT32_C(   962008425),  INT32_C(   514852930),  INT32_C(   717414251), -INT32_C(  2022090472), -INT32_C(  1307514166), -INT32_C(  1938233208),  INT32_C(  1430536531),
      -INT32_C(  1995535329), -INT32_C(   457022047), -INT32_C(   654150802),  INT32_C(  1778697298), -INT32_C(   403604195), -INT32_C(   258407833),  INT32_C(  1031541482),  INT32_C(  1922220371),
      -INT32_C(   285499059),  INT32_C(  1959968262), -INT32_C(  2091985871), -INT32_C(  1242738024),  INT32_C(   916250319), -INT32_C(   886688032), -INT32_C(  1693932728), -INT32_C(  1324508316),
       INT32_C(  1117718844), -INT32_C(   122195257), -INT32_C(   545585850),  INT32_C(   647260247),  INT32_C(   660353350), -INT32_C(  1343061145), -INT32_C(  1974797786), -INT32_C(   784640107),
       INT32_C(   655678048), -INT32_C(  1826632884),  INT32_C(   661822160),  INT32_C(  1229784578), -INT32_C(  1636783817),  INT32_C(  1380803116), -INT32_C(   220424356),  INT32_C(  1338185711),
       INT32_C(  1048041458),  INT32_C(  1926338210),  INT32_C(   865682225), -INT32_C(  2122521014), -INT32_C(  1138692976), -INT32_C(  1425052338), -INT32_C(   190977275), -INT32_C(   180133885),
      -INT32_C(   634144200), -INT32_C(  2108881583), -INT32_C(  1833572792),  INT32_C(  1561604813),  INT32_C(  1830368286), -INT32_C(  1508366175),  INT32_C(   396014868),  INT32_C(  1292688917),
      -INT32_C(   383238248), -INT32_C(  1922337468),  INT32_C(   673128795),  INT32_C(  1904554835),  INT32_C(   165584743), -INT32_C(   609225017), -INT32_C(  1041085781), -INT32_C(  1072759256),
      -INT32_C(  2102774210),  INT32_C(   118429099), -INT32_C(  1993396426), -INT32_C(   889473694),  INT32_C(   466868564),  INT32_C(  2079818448), -INT32_C(   197334580),  INT32_C(   649415656),
       INT32_C(   766009217), -INT32_C(  1422608268),  INT32_C(  1228170215),  INT32_C(  1813196568), -INT32_C(   645339639),  INT32_C(   894730089),  INT32_C(  1344967016),  INT32_C(  1568071644),
      -INT32_C(  1299570882), -INT32_C(  1101152553),  INT32_C(   973574690), -INT32_C(   895018047),  INT32_C(  1789079297),  INT32_C(   379648174),  INT32_C(  1701300873), -INT32_C(   406659671),
      -INT32_C(   744927748),  INT32_C(   764540683),  INT32_C(  1248369033), -INT32_C(  1256910924), -INT32_C(   333400002),  INT32_C(   956481712),  INT32_C(   866019722),  INT32_C(  1125802311),
      -INT32_C(  1189629010),  INT32_C(   870820010), -INT32_C(   176271551), -INT32_C(  1666477218), -INT32_C(    58143925),  INT32_C(   355830411),  INT32_C(   994628852), -INT32_C(   478256587),
      -INT32_C(  1063480043),  INT32_C(  2146665278),  INT32_C(   813003218),  INT32_C(  1355554820),  INT32_C(  1984713963), -INT32_C(   745831969), -INT32_C(  1978739883),  INT32_C(  1248693301),
       INT32_C(  1611270690),  INT32_C(  1625292429),  INT32_C(  1955615855),  INT32_C(  1606704500), -INT32_C(  1865084751), -INT32_C(   412917615),  INT32_C(  1752265011),  INT32_C(   548659198),
       INT32_C(  1988148713),  INT32_C(   735469499),  INT32_C(   681535412),  INT32_C(  1971872708),  INT32_C(    67526003), -INT32_C(   236230210), -INT32_C(   648389157),  INT32_C(   637078844),
      -INT32_C(  2036631094), -INT32_C(  1934527784), -INT32_C(  1649061671),  INT32_C(   638729651) };
  static const int32_t b[] =
    { -INT32_C(  1505846500),  INT32_C(  2047862332), -INT32_C(  2122680118),  INT32_C(  1395053977),  INT32_C(    31110726), -INT32_C(  2051794057),  INT32_C(  1675877753),  INT32_C(  1476250682),
      -INT32_C(  1543685017), -INT32_C(   316797918),  INT32_C(   510564485), -INT32_C(  1267559314), -INT32_C(  1028305845), -INT32_C(   532190873), -INT32_C(  2126239162),  INT32_C(  1591230966),
      -INT32_C(  1610492547),  INT32_C(  1720524769),  INT32_C(   646314936), -INT32_C(   623183985), -INT32_C(  1415802813),  INT32_C(  1082909689),  INT32_C(    79810318), -INT32_C(  1906140911),
       INT32_C(  1328440430),  INT32_C(  1001831299),  INT32_C(  1180777398),  INT32_C(  1965046834), -INT32_C(   987710004), -INT32_C(  1375359840), -INT32_C(  1934375301), -INT32_C(   853863073),
      -INT32_C(    48412295), -INT32_C(  1153903867),  INT32_C(  1073846798), -INT32_C(  1565187370),  INT32_C(  2137511647), -INT32_C(    47288958), -INT32_C(  1819614925),  INT32_C(  1885382134),
      -INT32_C(   210928146),  INT32_C(  1588569424),  INT32_C(   362721343), -INT32_C(  1313385262), -INT32_C(  1406066902), -INT32_C(  1079418996),  INT32_C(   911356736), -INT32_C(   945376296),
      -INT32_C(  2118511824), -INT32_C(   119576135), -INT32_C(   334594534), -INT32_C(    56703534),  INT32_C(  1890111460),  INT32_C(  1848660270),  INT32_C(  1571062405),  INT32_C(  1713654581),
       INT32_C(   401071966),  INT32_C(  1645266504),  INT32_C(   374283844), -INT32_C(   938283549), -INT32_C(   365380932), -INT32_C(  1856477172),  INT32_C(   552533227), -INT32_C(  1501162681),
       INT32_C(   985492978),  INT32_C(  2023607604), -INT32_C(   812651285), -INT32_C(  1785224743),  INT32_C(  1753206620),  INT32_C(   603576120),  INT32_C(   457435091), -INT32_C(   322843910),
       INT32_C(  1797750327),  INT32_C(   937739340), -INT32_C(  1996065872),  INT32_C(  1881054484), -INT32_C(  1512530579),  INT32_C(  1204343156), -INT32_C(  1285420103),  INT32_C(   228598741),
      -INT32_C(   294074462),  INT32_C(   992304267), -INT32_C(   456905521),  INT32_C(   911532745), -INT32_C(   203739777), -INT32_C(  1220893698), -INT32_C(  2073322065),  INT32_C(  1653672896),
       INT32_C(  1565526738),  INT32_C(   915961446),  INT32_C(  1796889762), -INT32_C(  1113428418), -INT32_C(  1699709541), -INT32_C(   799938015),  INT32_C(  1213512839), -INT32_C(  1716853049),
       INT32_C(  1459026928),  INT32_C(   327978609),  INT32_C(   679388906), -INT32_C(  1327161323), -INT32_C(  1085631074),  INT32_C(   126852224),  INT32_C(   542106456), -INT32_C(  1178993975),
       INT32_C(  1712369909),  INT32_C(   695835710),  INT32_C(  1481766723), -INT32_C(  1240975592),  INT32_C(  1282757580),  INT32_C(  1196688623), -INT32_C(  1318607897), -INT32_C(  1838538339),
       INT32_C(   267942609),  INT32_C(  1513648407), -INT32_C(  2119005591), -INT32_C(  1925727551), -INT32_C(    52777971), -INT32_C(  1757139280),  INT32_C(  1867033553), -INT32_C(  1660832820),
       INT32_C(  1152252461), -INT32_C(   727784085),  INT32_C(   810897519),  INT32_C(   415140875), -INT32_C(   401237960), -INT32_C(  1753196090), -INT32_C(   788084732), -INT32_C(  1452406661),
       INT32_C(  1844255490),  INT32_C(  1883409409), -INT32_C(   408840228),  INT32_C(  1543528228) };
  static const int32_t e[] =
    {              INT32_MIN,              INT32_MAX, -INT32_C(  1607827188),  INT32_C(  2112468228), -INT32_C(  1990979746),              INT32_MIN, -INT32_C(   262355455),              INT32_MAX,
                   INT32_MIN, -INT32_C(   773819965), -INT32_C(   143586317),  INT32_C(   511137984), -INT32_C(  1431910040), -INT32_C(   790598706), -INT32_C(  1094697680),              INT32_MAX,
      -INT32_C(  1895991606),              INT32_MAX, -INT32_C(  1445670935), -INT32_C(  1865922009), -INT32_C(   499552494),  INT32_C(   196221657), -INT32_C(  1614122410),              INT32_MIN,
                   INT32_MAX,  INT32_C(   879636042),  INT32_C(   635191548),              INT32_MAX, -INT32_C(   327356654),              INT32_MIN,              INT32_MIN, -INT32_C(  1638503180),
       INT32_C(   607265753),              INT32_MIN,  INT32_C(  1735668958), -INT32_C(   335402792),  INT32_C(   500727830),  INT32_C(  1333514158), -INT32_C(  2040039281),              INT32_MAX,
       INT32_C(   837113312),              INT32_MAX,  INT32_C(  1228403568),              INT32_MIN,              INT32_MIN,              INT32_MIN,  INT32_C(   720379461), -INT32_C(  1125510181),
                   INT32_MIN,              INT32_MIN,              INT32_MIN,  INT32_C(  1504901279),              INT32_MAX,  INT32_C(   340294095),  INT32_C(  1967077273),              INT32_MAX,
       INT32_C(    17833718), -INT32_C(   277070964),  INT32_C(  1047412639),  INT32_C(   966271286), -INT32_C(   199796189),              INT32_MIN, -INT32_C(   488552554),              INT32_MIN,
      -INT32_C(  1117281232),  INT32_C(  2142036703),              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(   260100511),  INT32_C(   326571746),
                   INT32_MAX, -INT32_C(   484868928), -INT32_C(   767895657),              INT32_MAX,              INT32_MIN,  INT32_C(  2099073245),  INT32_C(    59546913),  INT32_C(  1796670385),
      -INT32_C(  1593645344), -INT32_C(   108848286),  INT32_C(   516669169),  INT32_C(    16514698),  INT32_C(  1585339520), -INT32_C(   841245524), -INT32_C(   372021192),  INT32_C(  1247013225),
       INT32_C(   820598990),  INT32_C(  1680502129),              INT32_MAX,              INT32_MIN, -INT32_C(  2033109543),  INT32_C(   156543697),  INT32_C(  2079532561), -INT32_C(   591050738),
       INT32_C(   269397918),  INT32_C(  1198798619),  INT32_C(   503117355),              INT32_MIN, -INT32_C(  1143774999),  INT32_C(   482682635),  INT32_C(  1536735308), -INT32_C(  1657250562),
       INT32_C(   648889866),              INT32_MAX,              INT32_MAX,  INT32_C(   114579228),              INT32_MAX,  INT32_C(   450856654),              INT32_MIN, -INT32_C(   589845038),
       INT32_C(  1879213299),              INT32_MAX, -INT32_C(   163389736), -INT32_C(   319023051), -INT32_C(  1917862722),              INT32_MIN,              INT32_MAX, -INT32_C(  1112173622),
                   INT32_MAX,  INT32_C(     7685414),  INT32_C(  1492432931),              INT32_MAX, -INT32_C(   333711957), -INT32_C(  1989426300), -INT32_C(  1436473889), -INT32_C(   815327817),
      -INT32_C(   192375604), -INT32_C(    51118375), -INT32_C(  2057901899),              INT32_MAX };

  static int32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t
      rv,
      av = simde_svld1_s32(pg, &(a[i])),
      bv = simde_svld1_s32(pg, &(b[i]));

    rv = simde_svqadd_s32(av, bv);

    simde_svst1_s32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vi32(len, e, r);

  return 0;
#else
  int32_t a[1024 / sizeof(int32_t)], b[1024 / sizeof(int32_t)], e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t av, bv, ev;

    av = simde_svld1_s32(pg, &(a[i]));
    bv = simde_svld1_s32(pg, &(b[i]));

    ev = simde_svqadd_s32(av, bv);

    simde_svst1_s32(pg, &(e[i]), ev);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t a[] =
    { -INT64_C( 3649955515008527391), -INT64_C( 4950394335674432839),  INT64_C( 7108651951699311817),  INT64_C( 9077670924797574111),
       INT64_C( 7226859768476789681), -INT64_C( 4375196483845074696),  INT64_C( 1555103295313229033),  INT64_C( 1615203909698127697),
      -INT64_C(  624067411299858362),  INT64_C( 5614806086684259885),  INT64_C( 4776653380997028352),  INT64_C( 5590825344433171227),
       INT64_C( 3789942946434853283), -INT64_C( 1694400297245598517),  INT64_C( 3140530730172349281),  INT64_C(  173461561907332372),
       INT64_C(  623533303733200747), -INT64_C( 6112876412698950823), -INT64_C( 4257709585374230354),  INT64_C( 4808235639216510040),
      -INT64_C(  922011305970999569), -INT64_C( 3723246406652826786),  INT64_C( 4403521964514890407),  INT64_C( 3684136101715704584),
      -INT64_C( 8098999142696626932), -INT64_C( 3033021318875852802), -INT64_C( 1225179318172421155), -INT64_C( 5783768014091586492),
      -INT64_C( 6088039116348974398),  INT64_C( 2505320007618509248),  INT64_C( 9149032105951752482),  INT64_C( 8370715829733868760),
       INT64_C( 3473376407166877915), -INT64_C( 3743929817026790749), -INT64_C( 6013205091780792364),  INT64_C( 3510645331881071505),
      -INT64_C( 6020490227322708015),  INT64_C( 5214498167043953126), -INT64_C( 7994201602530069874),  INT64_C( 6483649128404629110),
      -INT64_C( 8835766014326361172),  INT64_C( 2403923376626660767),  INT64_C(  807994354584236709),  INT64_C( 4875375944926628552),
      -INT64_C( 1105535503505538173), -INT64_C( 3025469856829686194), -INT64_C( 2255264268935264750), -INT64_C( 2479556666661500484),
       INT64_C( 3845414269269020188), -INT64_C( 3283940238340759451),  INT64_C( 6240067801730115744), -INT64_C( 4761360745052386891),
      -INT64_C(  510728014277186611), -INT64_C( 5081472042401792024), -INT64_C( 3038792713891613724), -INT64_C( 8560550433827553837),
      -INT64_C( 3726967404601975364), -INT64_C( 5190135983769332186),  INT64_C( 5176617790055213538),  INT64_C( 5246112526684175495),
       INT64_C( 6340469252769123148),  INT64_C( 4773690675295580597),  INT64_C(  482759814855030008), -INT64_C( 6076456098757709609),
      -INT64_C( 2833933894240484318), -INT64_C( 3968621453059800502),  INT64_C( 2565055399060582420),  INT64_C( 2045254332693602904),
       INT64_C( 6949929533368712567), -INT64_C( 8649173584787614882),  INT64_C( 7752016655183063846), -INT64_C( 4131062755960415340),
      -INT64_C( 7694166627043959870),  INT64_C( 6818937160457274023),  INT64_C(  100596990207835110), -INT64_C( 3560875004175284097),
       INT64_C( 8152604712028796502), -INT64_C( 8523575069458503904),  INT64_C( 7590791790110934760),  INT64_C( 8668247455818114928),
      -INT64_C( 1009322191276805437), -INT64_C( 6900358260763031023),  INT64_C( 1862605306739474566), -INT64_C( 6787239243349094092),
       INT64_C( 1194911852131177939),  INT64_C( 7210265058289704631), -INT64_C( 8681903983342385471), -INT64_C( 3584957685468161601),
       INT64_C( 5949263472195956352),  INT64_C( 1668814932050859237),  INT64_C( 7688212647090716120), -INT64_C( 4907155329625059555),
       INT64_C( 4946019326516418742),  INT64_C( 1120324521564857631),  INT64_C( 3477882902958181934),  INT64_C( 5364119847423200379),
      -INT64_C( 7698553407633904762), -INT64_C( 7932080963062189404), -INT64_C( 8221412298843347548), -INT64_C( 2028954793212170247),
       INT64_C( 6155279061846880864), -INT64_C( 5758103862259976925),  INT64_C( 2945440121470026049),  INT64_C( 4088579999244100733),
      -INT64_C( 7348052191324764928), -INT64_C( 7806365075058444562), -INT64_C( 2589070195529739847),  INT64_C( 6123614926238304234) };
  static const int64_t b[] =
    { -INT64_C( 4074600956565941962),  INT64_C( 2135670085392389398), -INT64_C( 2909397624492448497), -INT64_C( 7086826988666624156),
       INT64_C( 4964575572949930265), -INT64_C( 7112725815776697715),  INT64_C( 3515250604875058858),  INT64_C( 5303158092110014356),
       INT64_C( 2314089981429668779),  INT64_C( 3357882694117490542), -INT64_C( 1611471362472302682), -INT64_C( 2591966511725504882),
       INT64_C( 2885632786032848472), -INT64_C( 7600741431159531310),  INT64_C( 1847508884450222948),  INT64_C( 6651497810360764225),
      -INT64_C( 6328029347227172020),  INT64_C( 8300559691285418666),  INT64_C( 2795276203675433510), -INT64_C( 3767289128600166057),
      -INT64_C(  330452375337566486),  INT64_C( 1284590128187467601),  INT64_C( 2886117765066915841),  INT64_C( 8536357094079833389),
      -INT64_C( 7456378478431680455), -INT64_C( 2016825507525944569),  INT64_C( 9062605091404170444), -INT64_C( 4863992587881985923),
       INT64_C( 6685535738580612584),  INT64_C( 6317794413578665958), -INT64_C( 3683178894083262700), -INT64_C( 7692336538602632192),
       INT64_C( 4087733892902323721),  INT64_C( 7795078226618943563), -INT64_C( 2792032922908942043),  INT64_C( 8287075666430268864),
      -INT64_C( 7085415302979008991),  INT64_C( 9176261652653583508), -INT64_C( 7028934987714647358), -INT64_C( 8275913604246876086),
       INT64_C( 1783895511443503314), -INT64_C( 7408037830590188201), -INT64_C( 6700607094175488634), -INT64_C( 1480702302282642054),
       INT64_C( 8579867600858608757), -INT64_C(  543148355180030714), -INT64_C( 3496095863416181890), -INT64_C( 4219828524540374420),
       INT64_C( 6211537356256673692),  INT64_C( 3697641890405112806),  INT64_C( 8753175843528486229), -INT64_C(  905382582068236711),
      -INT64_C( 1975423279914078481), -INT64_C( 4168488884549924803),  INT64_C( 1351618340869648698),  INT64_C( 2189077277088399383),
       INT64_C( 3403581066070265944),  INT64_C( 4607824555805931706),  INT64_C( 7224979194311566201), -INT64_C( 9054993744363585784),
       INT64_C( 6945700328924361539),  INT64_C( 5247115566062012045), -INT64_C( 6299763333554087710), -INT64_C( 2708292199851727683),
      -INT64_C( 1877873120907410455), -INT64_C( 2517149370957726470),  INT64_C(  498384746255780769), -INT64_C( 1552237736936683005),
      -INT64_C(  875552134572440421),  INT64_C( 4305385833885356518),  INT64_C( 7829341280097127256), -INT64_C( 8566553557983587022),
      -INT64_C( 1806974788296665600), -INT64_C( 3639605085672593241), -INT64_C( 7699161524170982831), -INT64_C( 6115354298121965909),
      -INT64_C( 7178296947036086661),  INT64_C(  106498351291050296), -INT64_C( 6319144023265318827),  INT64_C( 8459839254078493970),
      -INT64_C( 3201405555290600703),  INT64_C( 2390561252742033531), -INT64_C( 2483692537402234654),  INT64_C( 3290443767137093947),
       INT64_C( 7601150307722304269), -INT64_C( 2804967446755869658),  INT64_C( 5499249262736305064), -INT64_C(  404148669206369525),
       INT64_C( 7142460784422062023),  INT64_C( 2083873000810394395), -INT64_C(  959017237177391790),  INT64_C( 2716953012712649421),
      -INT64_C( 8018946704661588202), -INT64_C( 4305847577172899155),  INT64_C( 9082872799364173363), -INT64_C( 2625900100597565942),
       INT64_C( 1174001769843157316), -INT64_C( 5970523535084163858),  INT64_C( 3417620947350801470), -INT64_C( 2978526891073886966),
      -INT64_C( 6124092038228944754), -INT64_C( 2094684394168306490), -INT64_C( 7724167545786091909),  INT64_C( 1895187010342381284),
       INT64_C( 9029169385290063335),  INT64_C(  272658580937529665), -INT64_C( 4863480946069628573), -INT64_C( 2630805919701473833) };
  static const int64_t e[] =
    { -INT64_C( 7724556471574469353), -INT64_C( 2814724250282043441),  INT64_C( 4199254327206863320),  INT64_C( 1990843936130949955),
                           INT64_MAX,                      INT64_MIN,  INT64_C( 5070353900188287891),  INT64_C( 6918362001808142053),
       INT64_C( 1690022570129810417),  INT64_C( 8972688780801750427),  INT64_C( 3165182018524725670),  INT64_C( 2998858832707666345),
       INT64_C( 6675575732467701755),                      INT64_MIN,  INT64_C( 4988039614622572229),  INT64_C( 6824959372268096597),
      -INT64_C( 5704496043493971273),  INT64_C( 2187683278586467843), -INT64_C( 1462433381698796844),  INT64_C( 1040946510616343983),
      -INT64_C( 1252463681308566055), -INT64_C( 2438656278465359185),  INT64_C( 7289639729581806248),                      INT64_MAX,
                           INT64_MIN, -INT64_C( 5049846826401797371),  INT64_C( 7837425773231749289),                      INT64_MIN,
       INT64_C(  597496622231638186),  INT64_C( 8823114421197175206),  INT64_C( 5465853211868489782),  INT64_C(  678379291131236568),
       INT64_C( 7561110300069201636),  INT64_C( 4051148409592152814), -INT64_C( 8805238014689734407),                      INT64_MAX,
                           INT64_MIN,                      INT64_MAX,                      INT64_MIN, -INT64_C( 1792264475842246976),
      -INT64_C( 7051870502882857858), -INT64_C( 5004114453963527434), -INT64_C( 5892612739591251925),  INT64_C( 3394673642643986498),
       INT64_C( 7474332097353070584), -INT64_C( 3568618212009716908), -INT64_C( 5751360132351446640), -INT64_C( 6699385191201874904),
                           INT64_MAX,  INT64_C(  413701652064353355),                      INT64_MAX, -INT64_C( 5666743327120623602),
      -INT64_C( 2486151294191265092),                      INT64_MIN, -INT64_C( 1687174373021965026), -INT64_C( 6371473156739154454),
      -INT64_C(  323386338531709420), -INT64_C(  582311427963400480),                      INT64_MAX, -INT64_C( 3808881217679410289),
                           INT64_MAX,                      INT64_MAX, -INT64_C( 5817003518699057702), -INT64_C( 8784748298609437292),
      -INT64_C( 4711807015147894773), -INT64_C( 6485770824017526972),  INT64_C( 3063440145316363189),  INT64_C(  493016595756919899),
       INT64_C( 6074377398796272146), -INT64_C( 4343787750902258364),                      INT64_MAX,                      INT64_MIN,
                           INT64_MIN,  INT64_C( 3179332074784680782), -INT64_C( 7598564533963147721),                      INT64_MIN,
       INT64_C(  974307764992709841), -INT64_C( 8417076718167453608),  INT64_C( 1271647766845615933),                      INT64_MAX,
      -INT64_C( 4210727746567406140), -INT64_C( 4509797008020997492), -INT64_C(  621087230662760088), -INT64_C( 3496795476212000145),
       INT64_C( 8796062159853482208),  INT64_C( 4405297611533834973), -INT64_C( 3182654720606080407), -INT64_C( 3989106354674531126),
                           INT64_MAX,  INT64_C( 3752687932861253632),  INT64_C( 6729195409913324330), -INT64_C( 2190202316912410134),
      -INT64_C( 3072927378145169460), -INT64_C( 3185523055608041524),                      INT64_MAX,  INT64_C( 2738219746825634437),
      -INT64_C( 6524551637790747446),                      INT64_MIN, -INT64_C( 4803791351492546078), -INT64_C( 5007481684286057213),
       INT64_C(   31187023617936110), -INT64_C( 7852788256428283415), -INT64_C( 4778727424316065860),  INT64_C( 5983767009586482017),
       INT64_C( 1681117193965298407), -INT64_C( 7533706494120914897), -INT64_C( 7452551141599368420),  INT64_C( 3492809006536830401) };

  static int64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t
      rv,
      av = simde_svld1_s64(pg, &(a[i])),
      bv = simde_svld1_s64(pg, &(b[i]));

    rv = simde_svqadd_s64(av, bv);

    simde_svst1_s64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vi64(len, e, r);

  return 0;
#else
  int64_t a[1024 / sizeof(int64_t)], b[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t av, bv, ev;

    av = simde_svld1_s64(pg, &(a[i]));
    bv = simde_svld1_s64(pg, &(b[i]));

    ev = simde_svqadd_s64(av, bv);

    simde_svst1_s64(pg, &(e[i]), ev);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const uint8_t a[] =
    { UINT8_C( 26), UINT8_C(167), UINT8_C(191), UINT8_C(199), UINT8_C(116), UINT8_C(220), UINT8_C( 52), UINT8_C(112),
      UINT8_C(172), UINT8_C( 36), UINT8_C(186), UINT8_C( 22), UINT8_C( 16), UINT8_C(187), UINT8_C(119), UINT8_C( 34),
      UINT8_C(138), UINT8_C(225), UINT8_C(119), UINT8_C(189), UINT8_C( 97), UINT8_C(101), UINT8_C(251), UINT8_C(186),
      UINT8_C(130), UINT8_C(119), UINT8_C(133), UINT8_C( 84), UINT8_C( 24), UINT8_C(197), UINT8_C(  0), UINT8_C( 50),
      UINT8_C(109), UINT8_C(191), UINT8_C(249), UINT8_C(225), UINT8_C(155), UINT8_C( 45), UINT8_C( 81), UINT8_C( 71),
      UINT8_C( 81), UINT8_C( 12), UINT8_C( 93), UINT8_C( 97), UINT8_C(199), UINT8_C(212), UINT8_C(131), UINT8_C( 81),
      UINT8_C(181), UINT8_C(250), UINT8_C( 14), UINT8_C( 23), UINT8_C( 96), UINT8_C( 10), UINT8_C(209), UINT8_C(226),
      UINT8_C(129), UINT8_C( 86), UINT8_C( 55), UINT8_C(153), UINT8_C( 28), UINT8_C( 55), UINT8_C(203), UINT8_C(137),
      UINT8_C(246), UINT8_C(196), UINT8_C(106), UINT8_C(145), UINT8_C(241), UINT8_C(187), UINT8_C(216), UINT8_C( 66),
      UINT8_C(199), UINT8_C( 53), UINT8_C(164), UINT8_C(142), UINT8_C(  9), UINT8_C( 39), UINT8_C(224), UINT8_C(190),
      UINT8_C( 34), UINT8_C(238), UINT8_C(213), UINT8_C(130), UINT8_C(248), UINT8_C(166), UINT8_C(100), UINT8_C(121),
      UINT8_C(253), UINT8_C(155), UINT8_C( 18), UINT8_C( 25), UINT8_C(210), UINT8_C(221), UINT8_C(162), UINT8_C(200),
      UINT8_C(161), UINT8_C( 12), UINT8_C( 89), UINT8_C(146), UINT8_C(199), UINT8_C( 49), UINT8_C(213), UINT8_C(143),
      UINT8_C(102), UINT8_C(121), UINT8_C( 29), UINT8_C(111), UINT8_C(160), UINT8_C(253), UINT8_C( 46), UINT8_C(194),
      UINT8_C(236), UINT8_C(  3), UINT8_C( 68), UINT8_C(228), UINT8_C(170), UINT8_C(169), UINT8_C( 94), UINT8_C(167),
      UINT8_C( 68), UINT8_C(112), UINT8_C(192), UINT8_C( 23), UINT8_C( 78), UINT8_C( 98), UINT8_C(223), UINT8_C(239),
      UINT8_C(110), UINT8_C( 57), UINT8_C(130), UINT8_C( 53), UINT8_C(106), UINT8_C( 87), UINT8_C(196), UINT8_C(209),
      UINT8_C(208), UINT8_C(226), UINT8_C( 64), UINT8_C(112), UINT8_C(223), UINT8_C(110), UINT8_C( 51), UINT8_C(203),
      UINT8_C(114), UINT8_C(119), UINT8_C(176), UINT8_C( 28), UINT8_C( 32), UINT8_C( 14), UINT8_C(195), UINT8_C(101),
      UINT8_C(126), UINT8_C(131), UINT8_C(124), UINT8_C(204), UINT8_C(229), UINT8_C( 91), UINT8_C(188), UINT8_C( 83),
      UINT8_C(148), UINT8_C( 62), UINT8_C(136),    UINT8_MAX, UINT8_C(149), UINT8_C( 77), UINT8_C(208), UINT8_C(101),
      UINT8_C( 47), UINT8_C( 16), UINT8_C(213), UINT8_C( 14), UINT8_C(127), UINT8_C(  8), UINT8_C(218), UINT8_C(241),
      UINT8_C(128), UINT8_C(138), UINT8_C( 13), UINT8_C(160), UINT8_C(152), UINT8_C(208), UINT8_C(  5), UINT8_C( 22),
      UINT8_C( 83), UINT8_C(129), UINT8_C(227), UINT8_C( 56), UINT8_C(221), UINT8_C(159), UINT8_C(139), UINT8_C(113),
      UINT8_C(221), UINT8_C( 19), UINT8_C(112), UINT8_C(114), UINT8_C( 96), UINT8_C( 64), UINT8_C(215), UINT8_C(143),
      UINT8_C( 81), UINT8_C(172), UINT8_C(158), UINT8_C(208), UINT8_C(181), UINT8_C(120), UINT8_C(193), UINT8_C( 53),
      UINT8_C(  2), UINT8_C(206), UINT8_C(213), UINT8_C(154), UINT8_C(158), UINT8_C(219), UINT8_C(176), UINT8_C(241),
      UINT8_C( 92), UINT8_C(147), UINT8_C( 41), UINT8_C( 57), UINT8_C( 50), UINT8_C(180), UINT8_C(171), UINT8_C( 15),
      UINT8_C(199), UINT8_C( 27), UINT8_C(129), UINT8_C( 40), UINT8_C( 92), UINT8_C( 88), UINT8_C(183), UINT8_C(173),
      UINT8_C(  5), UINT8_C( 85), UINT8_C(125), UINT8_C(186), UINT8_C(205), UINT8_C( 62), UINT8_C(239), UINT8_C(207),
      UINT8_C( 12), UINT8_C(196), UINT8_C(105), UINT8_C(170), UINT8_C(159), UINT8_C( 26), UINT8_C(155), UINT8_C(252),
      UINT8_C(173), UINT8_C(196), UINT8_C( 53), UINT8_C(224), UINT8_C(120), UINT8_C(224), UINT8_C(239), UINT8_C( 63),
      UINT8_C(252), UINT8_C(113), UINT8_C(103), UINT8_C( 88), UINT8_C(201), UINT8_C( 31), UINT8_C(  5), UINT8_C(206),
      UINT8_C(116), UINT8_C(130), UINT8_C(136), UINT8_C( 66), UINT8_C(192), UINT8_C(119), UINT8_C( 17), UINT8_C(204),
      UINT8_C( 60), UINT8_C(123), UINT8_C(118), UINT8_C(219), UINT8_C(149), UINT8_C( 17), UINT8_C(215), UINT8_C( 66),
      UINT8_C(213), UINT8_C( 13), UINT8_C( 34), UINT8_C( 77), UINT8_C(237), UINT8_C( 18), UINT8_C(140), UINT8_C(233),
      UINT8_C(131), UINT8_C(244), UINT8_C( 65), UINT8_C( 76), UINT8_C( 19), UINT8_C( 70), UINT8_C( 27), UINT8_C(135),
      UINT8_C(200), UINT8_C(163), UINT8_C(201), UINT8_C(136), UINT8_C( 27), UINT8_C(219), UINT8_C( 84), UINT8_C( 87),
      UINT8_C( 86), UINT8_C(202), UINT8_C( 50), UINT8_C(235), UINT8_C(219), UINT8_C( 10), UINT8_C( 45), UINT8_C(176),
      UINT8_C( 23), UINT8_C( 80), UINT8_C(253), UINT8_C(  4), UINT8_C( 98), UINT8_C(138), UINT8_C(238), UINT8_C(229),
      UINT8_C(126), UINT8_C( 47), UINT8_C( 49), UINT8_C(145), UINT8_C(118), UINT8_C( 76), UINT8_C( 24), UINT8_C( 62),
      UINT8_C(240), UINT8_C(226), UINT8_C(199), UINT8_C( 11), UINT8_C(189), UINT8_C( 27), UINT8_C( 98), UINT8_C( 19),
      UINT8_C(230), UINT8_C(148), UINT8_C(254), UINT8_C(193), UINT8_C(158), UINT8_C( 43), UINT8_C(114), UINT8_C(181),
      UINT8_C(123), UINT8_C(111), UINT8_C(186), UINT8_C(221), UINT8_C(249), UINT8_C(168), UINT8_C(194), UINT8_C(119),
      UINT8_C(215), UINT8_C(244), UINT8_C(  8), UINT8_C( 77), UINT8_C( 64), UINT8_C( 33), UINT8_C(140), UINT8_C( 48),
      UINT8_C(  3), UINT8_C( 83), UINT8_C( 59), UINT8_C(192), UINT8_C(110), UINT8_C(157), UINT8_C(211), UINT8_C( 84),
      UINT8_C( 50), UINT8_C(209), UINT8_C( 22), UINT8_C(208), UINT8_C(252), UINT8_C(136), UINT8_C(134), UINT8_C(120),
      UINT8_C(247), UINT8_C( 64), UINT8_C( 85), UINT8_C(241), UINT8_C(232), UINT8_C( 24), UINT8_C(104), UINT8_C(191),
      UINT8_C( 12), UINT8_C(113), UINT8_C( 13), UINT8_C( 76), UINT8_C(146), UINT8_C(153), UINT8_C(125), UINT8_C(149),
      UINT8_C(236), UINT8_C(184), UINT8_C( 85), UINT8_C( 90), UINT8_C( 86), UINT8_C( 40), UINT8_C(175), UINT8_C(136),
      UINT8_C(249), UINT8_C(197), UINT8_C( 88), UINT8_C(245), UINT8_C( 77), UINT8_C(222), UINT8_C(109), UINT8_C( 68),
      UINT8_C( 30), UINT8_C(195), UINT8_C( 53), UINT8_C(  6), UINT8_C(219), UINT8_C(158), UINT8_C(198), UINT8_C(231),
      UINT8_C( 15), UINT8_C(211), UINT8_C( 51), UINT8_C(161), UINT8_C(108), UINT8_C(176), UINT8_C( 54), UINT8_C( 88),
      UINT8_C(105), UINT8_C(139), UINT8_C(178), UINT8_C(191), UINT8_C(179), UINT8_C( 97), UINT8_C( 71), UINT8_C(172),
      UINT8_C( 38), UINT8_C(159), UINT8_C(161), UINT8_C(115), UINT8_C(126), UINT8_C( 15), UINT8_C(184), UINT8_C(156),
      UINT8_C(210), UINT8_C(237), UINT8_C(163), UINT8_C(173), UINT8_C(139), UINT8_C(105), UINT8_C(148), UINT8_C(154),
      UINT8_C( 60), UINT8_C(199), UINT8_C( 59), UINT8_C(168), UINT8_C(120), UINT8_C(113), UINT8_C(  0), UINT8_C(225),
      UINT8_C(252), UINT8_C(178), UINT8_C(160), UINT8_C(175), UINT8_C( 20), UINT8_C(231), UINT8_C( 91), UINT8_C( 58),
      UINT8_C(134), UINT8_C(253), UINT8_C(174), UINT8_C(  4), UINT8_C( 12), UINT8_C(102), UINT8_C(161), UINT8_C(222),
      UINT8_C( 83), UINT8_C( 68), UINT8_C(139), UINT8_C(223), UINT8_C(173), UINT8_C( 31), UINT8_C(121), UINT8_C(233),
      UINT8_C(230), UINT8_C(181), UINT8_C(145), UINT8_C( 94), UINT8_C( 38), UINT8_C(145), UINT8_C( 63), UINT8_C( 35),
      UINT8_C( 67), UINT8_C(223), UINT8_C(210), UINT8_C( 87), UINT8_C(198), UINT8_C( 46), UINT8_C(146), UINT8_C( 77),
      UINT8_C( 43), UINT8_C( 64), UINT8_C( 81), UINT8_C( 55), UINT8_C(166), UINT8_C(242), UINT8_C( 21), UINT8_C(249),
      UINT8_C( 54), UINT8_C(160), UINT8_C(216), UINT8_C(227), UINT8_C(191), UINT8_C( 82), UINT8_C(204), UINT8_C(165),
      UINT8_C(  7), UINT8_C( 93), UINT8_C(  4), UINT8_C( 45), UINT8_C(238), UINT8_C( 67), UINT8_C( 80), UINT8_C( 50),
      UINT8_C( 35), UINT8_C( 35), UINT8_C(137), UINT8_C(233), UINT8_C( 81), UINT8_C( 27), UINT8_C( 54), UINT8_C(124),
      UINT8_C( 91), UINT8_C(136), UINT8_C(179), UINT8_C(  1), UINT8_C(122), UINT8_C(200), UINT8_C(251), UINT8_C(177),
      UINT8_C(104), UINT8_C(211), UINT8_C(148), UINT8_C( 39), UINT8_C( 37), UINT8_C( 97), UINT8_C(204), UINT8_C( 44),
      UINT8_C(190), UINT8_C(208), UINT8_C( 90), UINT8_C(173), UINT8_C( 20), UINT8_C(170), UINT8_C(223), UINT8_C( 55),
      UINT8_C(205), UINT8_C(104), UINT8_C( 32), UINT8_C( 30), UINT8_C(132), UINT8_C( 87), UINT8_C(154), UINT8_C(223),
      UINT8_C(223), UINT8_C( 77), UINT8_C(225), UINT8_C( 89), UINT8_C( 21), UINT8_C(220), UINT8_C( 10), UINT8_C(125),
      UINT8_C(175), UINT8_C(159), UINT8_C(164), UINT8_C(213), UINT8_C(  0), UINT8_C(113), UINT8_C(  1), UINT8_C(190),
      UINT8_C( 65), UINT8_C( 91), UINT8_C(107), UINT8_C( 85), UINT8_C(  6), UINT8_C( 74), UINT8_C(140), UINT8_C(211),
      UINT8_C(179), UINT8_C(173), UINT8_C(242), UINT8_C( 55), UINT8_C(  4), UINT8_C(140), UINT8_C( 22), UINT8_C(227),
      UINT8_C(218), UINT8_C(247), UINT8_C( 60), UINT8_C(239), UINT8_C(211), UINT8_C( 71), UINT8_C(109), UINT8_C(131),
      UINT8_C(230), UINT8_C( 17), UINT8_C( 88), UINT8_C(230), UINT8_C(130), UINT8_C( 89), UINT8_C(164), UINT8_C(196),
      UINT8_C(181), UINT8_C( 16), UINT8_C( 25), UINT8_C(187), UINT8_C( 90), UINT8_C(166), UINT8_C(142), UINT8_C( 13),
      UINT8_C( 83), UINT8_C(128), UINT8_C( 68), UINT8_C( 87), UINT8_C( 13), UINT8_C( 91), UINT8_C( 58), UINT8_C(231),
      UINT8_C( 82), UINT8_C(118), UINT8_C(214), UINT8_C( 38), UINT8_C(189), UINT8_C( 67), UINT8_C(169), UINT8_C(163),
      UINT8_C( 85), UINT8_C(  1), UINT8_C(137), UINT8_C(215), UINT8_C( 90), UINT8_C( 46), UINT8_C(155), UINT8_C( 15),
      UINT8_C( 62), UINT8_C(181), UINT8_C(202), UINT8_C(152), UINT8_C( 91), UINT8_C( 89), UINT8_C(166), UINT8_C(174),
      UINT8_C(217), UINT8_C(234), UINT8_C(  5), UINT8_C(230), UINT8_C( 69), UINT8_C( 63), UINT8_C(205), UINT8_C(152),
      UINT8_C(181), UINT8_C(164), UINT8_C(190), UINT8_C(115), UINT8_C(231), UINT8_C(103), UINT8_C( 22), UINT8_C( 60),
      UINT8_C(104), UINT8_C(160), UINT8_C( 20), UINT8_C(194), UINT8_C(206), UINT8_C(175), UINT8_C(210), UINT8_C( 12),
      UINT8_C(100), UINT8_C(156), UINT8_C(164), UINT8_C(191), UINT8_C(245), UINT8_C( 74), UINT8_C(109), UINT8_C(207),
      UINT8_C( 53), UINT8_C(114), UINT8_C(181), UINT8_C(122), UINT8_C(177), UINT8_C(131), UINT8_C( 18), UINT8_C(103),
      UINT8_C( 39), UINT8_C(208), UINT8_C(218), UINT8_C( 14), UINT8_C( 55), UINT8_C(240), UINT8_C( 75), UINT8_C(159),
      UINT8_C(144), UINT8_C( 95), UINT8_C( 98), UINT8_C( 94), UINT8_C( 14), UINT8_C( 52), UINT8_C(106), UINT8_C(115),
      UINT8_C(208), UINT8_C( 15), UINT8_C( 50), UINT8_C(198), UINT8_C( 89), UINT8_C(160), UINT8_C(149), UINT8_C(142),
      UINT8_C( 18), UINT8_C( 74), UINT8_C(  9), UINT8_C(196), UINT8_C(205), UINT8_C( 27), UINT8_C( 43), UINT8_C(244),
      UINT8_C(236), UINT8_C(  5), UINT8_C(  3), UINT8_C( 35), UINT8_C(245), UINT8_C( 78), UINT8_C(195), UINT8_C(134),
      UINT8_C(173), UINT8_C( 37), UINT8_C(228), UINT8_C(187), UINT8_C( 89), UINT8_C( 79), UINT8_C( 46), UINT8_C( 41),
      UINT8_C( 94), UINT8_C( 97), UINT8_C(239), UINT8_C(183), UINT8_C(  1), UINT8_C(132), UINT8_C( 70), UINT8_C( 19),
      UINT8_C(207), UINT8_C( 79), UINT8_C(215), UINT8_C(156), UINT8_C(106), UINT8_C(  2), UINT8_C(145), UINT8_C( 86),
      UINT8_C(  7), UINT8_C(148), UINT8_C(122), UINT8_C(253), UINT8_C(226), UINT8_C( 61), UINT8_C(131), UINT8_C(143),
      UINT8_C( 98), UINT8_C(103), UINT8_C( 74), UINT8_C(187), UINT8_C(182), UINT8_C(121), UINT8_C(228), UINT8_C( 20),
      UINT8_C(218), UINT8_C(212), UINT8_C(204), UINT8_C(219), UINT8_C( 88), UINT8_C( 18), UINT8_C(238), UINT8_C( 39),
      UINT8_C( 97), UINT8_C(198), UINT8_C(196), UINT8_C(203), UINT8_C(200), UINT8_C( 85), UINT8_C( 34), UINT8_C(208),
      UINT8_C(233), UINT8_C(156), UINT8_C(205), UINT8_C(203), UINT8_C(217), UINT8_C( 80), UINT8_C( 90), UINT8_C( 59),
      UINT8_C(183), UINT8_C(164), UINT8_C(246), UINT8_C(110), UINT8_C( 29), UINT8_C(218), UINT8_C(130), UINT8_C(247),
      UINT8_C(174), UINT8_C( 78), UINT8_C(210), UINT8_C(  7), UINT8_C( 96), UINT8_C(193), UINT8_C( 46), UINT8_C(193),
      UINT8_C(135), UINT8_C(242), UINT8_C(141), UINT8_C( 79), UINT8_C( 71), UINT8_C(175), UINT8_C( 31), UINT8_C( 48),
      UINT8_C( 75), UINT8_C(236), UINT8_C(251), UINT8_C( 36), UINT8_C( 60), UINT8_C( 85), UINT8_C( 95), UINT8_C(244),
      UINT8_C(250), UINT8_C( 85), UINT8_C( 98), UINT8_C( 23), UINT8_C( 47), UINT8_C(228), UINT8_C( 15), UINT8_C(222),
      UINT8_C( 51), UINT8_C(225), UINT8_C(229), UINT8_C(147), UINT8_C(162), UINT8_C( 19), UINT8_C( 85), UINT8_C( 41),
      UINT8_C(  6), UINT8_C(226), UINT8_C(121), UINT8_C( 77), UINT8_C(145), UINT8_C(152), UINT8_C(126), UINT8_C(220),
      UINT8_C(133), UINT8_C(121), UINT8_C(  0), UINT8_C(193), UINT8_C(207), UINT8_C( 95), UINT8_C(181), UINT8_C(201),
      UINT8_C(180), UINT8_C( 23), UINT8_C(224), UINT8_C(227), UINT8_C(252), UINT8_C(239), UINT8_C(193), UINT8_C( 47),
      UINT8_C(209), UINT8_C(166), UINT8_C(194), UINT8_C(115), UINT8_C(186), UINT8_C( 23), UINT8_C(157), UINT8_C(192),
      UINT8_C(249), UINT8_C( 22), UINT8_C( 13), UINT8_C(138), UINT8_C(174), UINT8_C(139), UINT8_C(102), UINT8_C( 51),
      UINT8_C(  5), UINT8_C(102), UINT8_C(245), UINT8_C(212), UINT8_C(197), UINT8_C(170), UINT8_C(157), UINT8_C(121),
      UINT8_C(194), UINT8_C(125), UINT8_C( 93), UINT8_C(190), UINT8_C(109), UINT8_C( 30), UINT8_C(237), UINT8_C( 62),
      UINT8_C(197), UINT8_C(175), UINT8_C(177), UINT8_C(127), UINT8_C(199), UINT8_C( 78), UINT8_C( 63), UINT8_C(192),
      UINT8_C(100), UINT8_C( 76), UINT8_C( 75), UINT8_C( 19), UINT8_C(216), UINT8_C(177), UINT8_C( 70), UINT8_C(221),
      UINT8_C( 24), UINT8_C( 59), UINT8_C(177), UINT8_C(221), UINT8_C(230), UINT8_C( 78), UINT8_C( 87), UINT8_C(168),
      UINT8_C(203), UINT8_C(180), UINT8_C(102), UINT8_C( 56), UINT8_C(210), UINT8_C( 83), UINT8_C(118), UINT8_C(151),
      UINT8_C(  2), UINT8_C( 40), UINT8_C( 22), UINT8_C(201), UINT8_C(118), UINT8_C( 85), UINT8_C(138), UINT8_C(219),
      UINT8_C(162), UINT8_C(213), UINT8_C(238), UINT8_C(122), UINT8_C(134), UINT8_C( 52), UINT8_C( 87), UINT8_C(158),
      UINT8_C(112), UINT8_C(  8), UINT8_C(124), UINT8_C( 86), UINT8_C( 86), UINT8_C(211), UINT8_C(254), UINT8_C( 33),
      UINT8_C(135), UINT8_C(100), UINT8_C( 90), UINT8_C( 89), UINT8_C(183), UINT8_C(208), UINT8_C(241), UINT8_C(185),
      UINT8_C(248), UINT8_C(  7), UINT8_C(131), UINT8_C(111), UINT8_C( 93), UINT8_C( 13), UINT8_C( 74),    UINT8_MAX,
      UINT8_C(226), UINT8_C( 56), UINT8_C(121), UINT8_C(104), UINT8_C(108), UINT8_C(208), UINT8_C(  7), UINT8_C(220),
      UINT8_C(216), UINT8_C(131) };
  static const uint8_t b[] =
    { UINT8_C(124), UINT8_C(161), UINT8_C(181), UINT8_C( 17), UINT8_C(204), UINT8_C( 64), UINT8_C(136), UINT8_C( 48),
      UINT8_C( 68), UINT8_C(104), UINT8_C(  0), UINT8_C( 24), UINT8_C( 78), UINT8_C(172), UINT8_C(196), UINT8_C(184),
      UINT8_C(139), UINT8_C(158), UINT8_C(119), UINT8_C(155), UINT8_C(200), UINT8_C( 20), UINT8_C( 63), UINT8_C(155),
      UINT8_C(231), UINT8_C( 46), UINT8_C(232), UINT8_C(225), UINT8_C( 35), UINT8_C(167), UINT8_C( 11), UINT8_C(159),
      UINT8_C( 72), UINT8_C(192), UINT8_C(177), UINT8_C( 21), UINT8_C(  1), UINT8_C( 57), UINT8_C( 69), UINT8_C( 69),
      UINT8_C(161), UINT8_C( 69), UINT8_C( 94), UINT8_C(240), UINT8_C(241), UINT8_C( 34), UINT8_C(168), UINT8_C(125),
      UINT8_C(193), UINT8_C( 31), UINT8_C( 24), UINT8_C(137), UINT8_C( 51), UINT8_C( 87), UINT8_C( 36), UINT8_C( 26),
      UINT8_C(133), UINT8_C( 12), UINT8_C(252), UINT8_C(168), UINT8_C(179), UINT8_C(  7), UINT8_C( 72), UINT8_C(252),
      UINT8_C(199), UINT8_C(249), UINT8_C( 17), UINT8_C(200), UINT8_C( 50), UINT8_C( 86), UINT8_C( 14), UINT8_C(212),
      UINT8_C(155), UINT8_C(108), UINT8_C(196), UINT8_C(140), UINT8_C(142), UINT8_C(108), UINT8_C(  9), UINT8_C( 79),
      UINT8_C(139), UINT8_C( 33), UINT8_C(216), UINT8_C(191), UINT8_C(120), UINT8_C(252), UINT8_C(217), UINT8_C(254),
      UINT8_C(  8), UINT8_C(213), UINT8_C(166), UINT8_C(188), UINT8_C(220), UINT8_C(238), UINT8_C(184), UINT8_C(164),
      UINT8_C(231), UINT8_C(201), UINT8_C(108), UINT8_C( 26), UINT8_C( 31), UINT8_C(122), UINT8_C(238), UINT8_C(186),
      UINT8_C(230), UINT8_C(178), UINT8_C( 70), UINT8_C(117), UINT8_C( 30), UINT8_C( 80), UINT8_C(196), UINT8_C(169),
      UINT8_C(113), UINT8_C(157), UINT8_C(104), UINT8_C(234), UINT8_C(153), UINT8_C( 66), UINT8_C(232), UINT8_C(162),
      UINT8_C( 23), UINT8_C(142), UINT8_C( 94), UINT8_C(244), UINT8_C(125), UINT8_C( 22), UINT8_C(152), UINT8_C(100),
      UINT8_C(223), UINT8_C(  4), UINT8_C(126), UINT8_C(254), UINT8_C(127), UINT8_C(108), UINT8_C(184), UINT8_C(101),
      UINT8_C( 30), UINT8_C(254), UINT8_C(218), UINT8_C( 60), UINT8_C( 78), UINT8_C(159), UINT8_C(230), UINT8_C(192),
      UINT8_C( 60), UINT8_C( 78), UINT8_C(170), UINT8_C(213), UINT8_C(144), UINT8_C(146), UINT8_C(119), UINT8_C(168),
      UINT8_C( 32), UINT8_C(213), UINT8_C(156), UINT8_C(157), UINT8_C(235), UINT8_C( 52), UINT8_C(  2), UINT8_C(202),
      UINT8_C( 56), UINT8_C(128), UINT8_C(200), UINT8_C(183), UINT8_C(237), UINT8_C(128), UINT8_C( 29), UINT8_C( 11),
      UINT8_C(127), UINT8_C(247), UINT8_C( 72), UINT8_C(205), UINT8_C(150), UINT8_C( 46), UINT8_C(141), UINT8_C(210),
      UINT8_C(124), UINT8_C( 55), UINT8_C(168), UINT8_C( 13), UINT8_C(201), UINT8_C( 31), UINT8_C(181), UINT8_C(234),
      UINT8_C(245), UINT8_C( 81), UINT8_C(135), UINT8_C(224), UINT8_C(133), UINT8_C(137), UINT8_C(171), UINT8_C(189),
      UINT8_C( 10), UINT8_C(115), UINT8_C(117), UINT8_C(247), UINT8_C(244), UINT8_C(146), UINT8_C(  2), UINT8_C(115),
      UINT8_C(137), UINT8_C( 74), UINT8_C( 64), UINT8_C( 32), UINT8_C(120), UINT8_C(206), UINT8_C(242), UINT8_C(245),
      UINT8_C(  5), UINT8_C(154), UINT8_C(  2), UINT8_C(207), UINT8_C(186), UINT8_C(183), UINT8_C(185), UINT8_C(175),
      UINT8_C(  8), UINT8_C( 64), UINT8_C(143), UINT8_C(141), UINT8_C(202), UINT8_C( 58), UINT8_C( 74), UINT8_C(212),
      UINT8_C(174), UINT8_C(191), UINT8_C(203), UINT8_C(162), UINT8_C( 81), UINT8_C(205), UINT8_C( 21), UINT8_C(219),
      UINT8_C( 24), UINT8_C( 85), UINT8_C(251), UINT8_C(144), UINT8_C( 35), UINT8_C(237), UINT8_C(133), UINT8_C( 41),
      UINT8_C(136), UINT8_C(135), UINT8_C(248), UINT8_C( 66), UINT8_C( 62), UINT8_C(177), UINT8_C(241), UINT8_C( 70),
      UINT8_C(241), UINT8_C(128), UINT8_C(211), UINT8_C(187), UINT8_C(187), UINT8_C( 30), UINT8_C(143), UINT8_C(105),
      UINT8_C(221), UINT8_C( 90), UINT8_C( 11), UINT8_C( 47), UINT8_C( 40), UINT8_C( 32), UINT8_C( 10), UINT8_C( 64),
      UINT8_C(117), UINT8_C(  5), UINT8_C(208), UINT8_C(153), UINT8_C(242), UINT8_C( 86), UINT8_C(194), UINT8_C(122),
      UINT8_C(221), UINT8_C(186), UINT8_C(188), UINT8_C( 28), UINT8_C(107), UINT8_C(173), UINT8_C( 98), UINT8_C( 92),
      UINT8_C( 46), UINT8_C( 54), UINT8_C( 24), UINT8_C(233), UINT8_C( 84), UINT8_C(167), UINT8_C( 82), UINT8_C( 49),
      UINT8_C(  2), UINT8_C( 93), UINT8_C( 96), UINT8_C( 42), UINT8_C(125), UINT8_C(106), UINT8_C(106), UINT8_C(242),
      UINT8_C(111), UINT8_C( 58), UINT8_C(139), UINT8_C( 98), UINT8_C(144), UINT8_C( 77), UINT8_C(220), UINT8_C(110),
      UINT8_C(  7), UINT8_C(153), UINT8_C(138), UINT8_C(114), UINT8_C( 70), UINT8_C(236), UINT8_C(207), UINT8_C(116),
      UINT8_C( 34), UINT8_C(231), UINT8_C( 93), UINT8_C(118), UINT8_C(142), UINT8_C(175), UINT8_C(168), UINT8_C(144),
      UINT8_C( 12), UINT8_C(  8), UINT8_C(186), UINT8_C(137), UINT8_C(115), UINT8_C( 36), UINT8_C(124), UINT8_C(226),
      UINT8_C( 95), UINT8_C(  7), UINT8_C( 68), UINT8_C(239), UINT8_C( 85), UINT8_C( 33), UINT8_C( 93), UINT8_C( 92),
      UINT8_C(186), UINT8_C(231), UINT8_C(207), UINT8_C(  0), UINT8_C(212), UINT8_C(158), UINT8_C(117), UINT8_C(246),
      UINT8_C(133), UINT8_C(210), UINT8_C(109), UINT8_C( 19), UINT8_C(130), UINT8_C( 21), UINT8_C(164), UINT8_C(142),
      UINT8_C( 29), UINT8_C( 94), UINT8_C( 24), UINT8_C(144), UINT8_C(131), UINT8_C(148), UINT8_C(115), UINT8_C(226),
      UINT8_C(155), UINT8_C(183), UINT8_C(209), UINT8_C(240), UINT8_C(216), UINT8_C( 47), UINT8_C( 77), UINT8_C(146),
      UINT8_C( 22), UINT8_C( 28), UINT8_C(147), UINT8_C(234), UINT8_C(186), UINT8_C(  8), UINT8_C(225), UINT8_C( 63),
      UINT8_C(218), UINT8_C( 78), UINT8_C( 82), UINT8_C( 92), UINT8_C( 99), UINT8_C(246), UINT8_C(235), UINT8_C(128),
      UINT8_C( 85), UINT8_C(  3), UINT8_C( 17), UINT8_C(216), UINT8_C(151), UINT8_C(132), UINT8_C(186), UINT8_C( 50),
      UINT8_C( 59), UINT8_C(139), UINT8_C( 35), UINT8_C( 20), UINT8_C(186), UINT8_C(112), UINT8_C(166), UINT8_C(209),
      UINT8_C(140), UINT8_C( 57), UINT8_C(187), UINT8_C( 70), UINT8_C( 65), UINT8_C(156), UINT8_C(133), UINT8_C( 28),
      UINT8_C(234), UINT8_C(215), UINT8_C(120), UINT8_C( 77), UINT8_C(206), UINT8_C( 99), UINT8_C(206), UINT8_C( 35),
      UINT8_C(102), UINT8_C(223), UINT8_C(251), UINT8_C(253), UINT8_C( 99), UINT8_C(181), UINT8_C( 48), UINT8_C(158),
      UINT8_C( 64), UINT8_C( 83), UINT8_C(178), UINT8_C(251), UINT8_C(195), UINT8_C( 89), UINT8_C(204), UINT8_C( 79),
      UINT8_C(146), UINT8_C(135), UINT8_C(149), UINT8_C(212), UINT8_C( 36), UINT8_C( 26), UINT8_C(240), UINT8_C( 14),
      UINT8_C(241), UINT8_C(104), UINT8_C( 92), UINT8_C(191), UINT8_C(204), UINT8_C( 42), UINT8_C(226), UINT8_C( 50),
      UINT8_C(  9), UINT8_C(221), UINT8_C( 48), UINT8_C(108), UINT8_C(146), UINT8_C( 96), UINT8_C( 10), UINT8_C(211),
      UINT8_C(179), UINT8_C(189), UINT8_C(206), UINT8_C(118), UINT8_C( 22), UINT8_C(154), UINT8_C(197), UINT8_C(168),
      UINT8_C( 33), UINT8_C( 90), UINT8_C(124), UINT8_C( 69), UINT8_C(116), UINT8_C(108), UINT8_C( 84), UINT8_C(101),
      UINT8_C(213), UINT8_C(176), UINT8_C( 37), UINT8_C(161), UINT8_C(218), UINT8_C(  7), UINT8_C(211), UINT8_C(227),
      UINT8_C(229), UINT8_C(  3), UINT8_C( 79), UINT8_C(119), UINT8_C( 99), UINT8_C( 89), UINT8_C( 74), UINT8_C( 22),
      UINT8_C( 22), UINT8_C( 24), UINT8_C(140), UINT8_C( 44), UINT8_C(178), UINT8_C( 81), UINT8_C(213), UINT8_C(212),
      UINT8_C(171), UINT8_C( 81), UINT8_C( 25), UINT8_C( 31), UINT8_C(190), UINT8_C(109), UINT8_C(133), UINT8_C(147),
      UINT8_C( 29), UINT8_C(170), UINT8_C( 52), UINT8_C(247), UINT8_C(177), UINT8_C(  7), UINT8_C(218), UINT8_C(150),
      UINT8_C( 11), UINT8_C( 41), UINT8_C( 14), UINT8_C(110), UINT8_C(131), UINT8_C( 88), UINT8_C(133), UINT8_C(153),
      UINT8_C(113), UINT8_C( 17), UINT8_C(198), UINT8_C( 35), UINT8_C( 99), UINT8_C(155), UINT8_C(247), UINT8_C( 14),
      UINT8_C(236), UINT8_C( 17), UINT8_C( 46), UINT8_C(170), UINT8_C(126), UINT8_C(179), UINT8_C( 61), UINT8_C(156),
      UINT8_C( 93), UINT8_C(113), UINT8_C(147), UINT8_C( 14), UINT8_C(121), UINT8_C(110), UINT8_C(165), UINT8_C(132),
      UINT8_C(151), UINT8_C(179), UINT8_C(242), UINT8_C( 26), UINT8_C( 11), UINT8_C(119), UINT8_C(180), UINT8_C(124),
      UINT8_C(137), UINT8_C(122), UINT8_C(160), UINT8_C(236), UINT8_C( 21), UINT8_C(151), UINT8_C(250), UINT8_C(  1),
      UINT8_C(168), UINT8_C( 40), UINT8_C(172), UINT8_C( 39), UINT8_C(219), UINT8_C(233), UINT8_C(195), UINT8_C( 56),
      UINT8_C( 91), UINT8_C( 86), UINT8_C( 71), UINT8_C(212), UINT8_C(196), UINT8_C(236), UINT8_C( 88), UINT8_C( 92),
      UINT8_C(159), UINT8_C( 74), UINT8_C(118), UINT8_C(170), UINT8_C(194), UINT8_C( 42), UINT8_C( 39), UINT8_C( 75),
      UINT8_C(164), UINT8_C(199), UINT8_C( 55), UINT8_C(185), UINT8_C( 94), UINT8_C( 49), UINT8_C(187), UINT8_C(  7),
      UINT8_C( 90), UINT8_C(103), UINT8_C( 46), UINT8_C( 53), UINT8_C( 80), UINT8_C(241), UINT8_C(110), UINT8_C(171),
      UINT8_C( 71), UINT8_C(181), UINT8_C(127), UINT8_C( 12), UINT8_C(161), UINT8_C(215), UINT8_C(104), UINT8_C( 64),
      UINT8_C( 34), UINT8_C(222), UINT8_C(234), UINT8_C(228), UINT8_C(  9), UINT8_C( 17), UINT8_C( 47), UINT8_C(173),
      UINT8_C(216), UINT8_C(102), UINT8_C(103), UINT8_C( 55), UINT8_C(151), UINT8_C( 34), UINT8_C( 62), UINT8_C(241),
      UINT8_C(137), UINT8_C(108), UINT8_C( 39), UINT8_C(217), UINT8_C( 93), UINT8_C(149), UINT8_C(133), UINT8_C(164),
      UINT8_C( 74), UINT8_C(  4), UINT8_C(176), UINT8_C(235), UINT8_C(220), UINT8_C( 24), UINT8_C( 43), UINT8_C(254),
      UINT8_C(247), UINT8_C( 21), UINT8_C(226), UINT8_C(  0), UINT8_C( 39), UINT8_C( 17), UINT8_C(173),    UINT8_MAX,
      UINT8_C(119), UINT8_C( 20), UINT8_C( 54), UINT8_C( 14), UINT8_C( 54), UINT8_C(116), UINT8_C(  0), UINT8_C(191),
      UINT8_C(224), UINT8_C( 39), UINT8_C(153), UINT8_C( 61), UINT8_C(188), UINT8_C( 30), UINT8_C(226), UINT8_C(  6),
      UINT8_C( 34), UINT8_C(146), UINT8_C(241), UINT8_C(254), UINT8_C(171), UINT8_C( 28), UINT8_C(252), UINT8_C(162),
      UINT8_C( 49), UINT8_C(222), UINT8_C(162), UINT8_C( 88), UINT8_C(239), UINT8_C( 79), UINT8_C( 88), UINT8_C(102),
      UINT8_C(100), UINT8_C(142), UINT8_C(117), UINT8_C(154), UINT8_C(  3), UINT8_C(117), UINT8_C( 90), UINT8_C(227),
      UINT8_C(156), UINT8_C(243), UINT8_C( 33), UINT8_C( 88), UINT8_C( 17), UINT8_C(  3), UINT8_C( 94), UINT8_C( 51),
      UINT8_C(149), UINT8_C( 79), UINT8_C( 50), UINT8_C( 64), UINT8_C(107), UINT8_C( 46), UINT8_C(226), UINT8_C(156),
      UINT8_C( 13), UINT8_C(132), UINT8_C(245), UINT8_C(252), UINT8_C(212), UINT8_C( 77), UINT8_C( 99), UINT8_C( 56),
      UINT8_C(219), UINT8_C(216), UINT8_C(210), UINT8_C(222), UINT8_C( 77), UINT8_C( 44), UINT8_C(194), UINT8_C(233),
      UINT8_C( 31), UINT8_C(227), UINT8_C( 65), UINT8_C( 48), UINT8_C(230), UINT8_C(159), UINT8_C(100), UINT8_C(123),
      UINT8_C(238), UINT8_C(150), UINT8_C(188), UINT8_C( 89), UINT8_C(196), UINT8_C(158), UINT8_C(245), UINT8_C(209),
      UINT8_C( 35), UINT8_C(234), UINT8_C(206), UINT8_C(247), UINT8_C( 55), UINT8_C( 49), UINT8_C( 47), UINT8_C( 19),
      UINT8_C(  9), UINT8_C(  1), UINT8_C(241), UINT8_C( 86), UINT8_C( 46), UINT8_C(179), UINT8_C( 63), UINT8_C( 77),
      UINT8_C(150), UINT8_C(128), UINT8_C(126), UINT8_C(124), UINT8_C( 31), UINT8_C(226), UINT8_C(248), UINT8_C( 13),
      UINT8_C(120), UINT8_C(180), UINT8_C(102), UINT8_C( 60), UINT8_C( 82), UINT8_C( 91), UINT8_C( 14), UINT8_C(117),
      UINT8_C( 70), UINT8_C(220), UINT8_C(108), UINT8_C(125), UINT8_C( 13), UINT8_C(155), UINT8_C(144), UINT8_C( 22),
      UINT8_C(157), UINT8_C(130), UINT8_C(108), UINT8_C(203), UINT8_C( 53), UINT8_C(171), UINT8_C( 24), UINT8_C(204),
      UINT8_C( 43), UINT8_C(150), UINT8_C( 72), UINT8_C( 74), UINT8_C(120), UINT8_C( 64), UINT8_C( 87), UINT8_C(240),
      UINT8_C(244), UINT8_C(189), UINT8_C( 45), UINT8_C( 71), UINT8_C( 24), UINT8_C( 59), UINT8_C(188), UINT8_C( 94),
      UINT8_C( 23), UINT8_C( 41), UINT8_C(220), UINT8_C( 36), UINT8_C(196), UINT8_C(108), UINT8_C( 58), UINT8_C( 97),
      UINT8_C(238), UINT8_C(166), UINT8_C( 44), UINT8_C( 36), UINT8_C( 81), UINT8_C( 69), UINT8_C(240), UINT8_C(124),
      UINT8_C(219), UINT8_C( 56), UINT8_C(198), UINT8_C( 84), UINT8_C(121), UINT8_C( 29), UINT8_C( 68), UINT8_C(109),
      UINT8_C(218), UINT8_C(113), UINT8_C(180), UINT8_C(242), UINT8_C(172), UINT8_C(113), UINT8_C( 81), UINT8_C(195),
      UINT8_C(154), UINT8_C( 45), UINT8_C(231), UINT8_C( 94), UINT8_C(153), UINT8_C( 33), UINT8_C(192), UINT8_C(136),
      UINT8_C(199), UINT8_C(236), UINT8_C(172), UINT8_C( 24), UINT8_C( 49), UINT8_C(156), UINT8_C(148), UINT8_C( 13),
      UINT8_C(212), UINT8_C( 90), UINT8_C( 97), UINT8_C( 77), UINT8_C(119), UINT8_C(165), UINT8_C(187), UINT8_C( 81),
      UINT8_C( 23), UINT8_C(111), UINT8_C( 68), UINT8_C(195), UINT8_C(224), UINT8_C(149), UINT8_C(135), UINT8_C(122),
      UINT8_C(194), UINT8_C(110), UINT8_C(217), UINT8_C( 91), UINT8_C(144), UINT8_C(153), UINT8_C(227), UINT8_C( 87),
      UINT8_C(133), UINT8_C(143), UINT8_C(112), UINT8_C(183), UINT8_C( 43), UINT8_C(  4), UINT8_C(196), UINT8_C(  0),
      UINT8_C( 95), UINT8_C( 37), UINT8_C( 77), UINT8_C(214), UINT8_C(202), UINT8_C(  8), UINT8_C( 40), UINT8_C(225),
      UINT8_C(120), UINT8_C(108), UINT8_C(165), UINT8_C( 88), UINT8_C(  1), UINT8_C( 44), UINT8_C(211), UINT8_C(195),
      UINT8_C(154), UINT8_C(172), UINT8_C( 30), UINT8_C( 42), UINT8_C( 69), UINT8_C(  2), UINT8_C(130), UINT8_C(202),
      UINT8_C(145), UINT8_C(242), UINT8_C(129), UINT8_C(189), UINT8_C(246), UINT8_C( 69), UINT8_C(189), UINT8_C( 85),
      UINT8_C(106), UINT8_C( 10), UINT8_C( 44), UINT8_C( 53), UINT8_C( 19), UINT8_C( 84), UINT8_C( 22), UINT8_C(139),
      UINT8_C(192), UINT8_C(187), UINT8_C(227), UINT8_C(193), UINT8_C(231), UINT8_C(182), UINT8_C(132), UINT8_C(130),
      UINT8_C( 98), UINT8_C(162), UINT8_C(172), UINT8_C(167), UINT8_C(164), UINT8_C( 46), UINT8_C(114), UINT8_C( 54),
      UINT8_C( 32), UINT8_C(243), UINT8_C(243), UINT8_C( 23), UINT8_C( 57), UINT8_C(176), UINT8_C(108), UINT8_C(163),
      UINT8_C(186), UINT8_C(152), UINT8_C(216), UINT8_C(205), UINT8_C(236), UINT8_C(239), UINT8_C( 88), UINT8_C(172),
      UINT8_C(170), UINT8_C( 60), UINT8_C(109), UINT8_C(146), UINT8_C(242), UINT8_C(241), UINT8_C( 20), UINT8_C( 85),
      UINT8_C(148), UINT8_C(192), UINT8_C(252), UINT8_C( 56), UINT8_C(239), UINT8_C(110), UINT8_C(110), UINT8_C( 15),
      UINT8_C( 98), UINT8_C( 97), UINT8_C( 38), UINT8_C(155), UINT8_C( 17), UINT8_C(147), UINT8_C( 62), UINT8_C(204),
      UINT8_C( 43), UINT8_C( 23) };
  static const uint8_t e[] =
    { UINT8_C(150),    UINT8_MAX,    UINT8_MAX, UINT8_C(216),    UINT8_MAX,    UINT8_MAX, UINT8_C(188), UINT8_C(160),
      UINT8_C(240), UINT8_C(140), UINT8_C(186), UINT8_C( 46), UINT8_C( 94),    UINT8_MAX,    UINT8_MAX, UINT8_C(218),
         UINT8_MAX,    UINT8_MAX, UINT8_C(238),    UINT8_MAX,    UINT8_MAX, UINT8_C(121),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(165),    UINT8_MAX,    UINT8_MAX, UINT8_C( 59),    UINT8_MAX, UINT8_C( 11), UINT8_C(209),
      UINT8_C(181),    UINT8_MAX,    UINT8_MAX, UINT8_C(246), UINT8_C(156), UINT8_C(102), UINT8_C(150), UINT8_C(140),
      UINT8_C(242), UINT8_C( 81), UINT8_C(187),    UINT8_MAX,    UINT8_MAX, UINT8_C(246),    UINT8_MAX, UINT8_C(206),
         UINT8_MAX,    UINT8_MAX, UINT8_C( 38), UINT8_C(160), UINT8_C(147), UINT8_C( 97), UINT8_C(245), UINT8_C(252),
         UINT8_MAX, UINT8_C( 98),    UINT8_MAX,    UINT8_MAX, UINT8_C(207), UINT8_C( 62),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C(123),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(230),    UINT8_MAX,
         UINT8_MAX, UINT8_C(161),    UINT8_MAX,    UINT8_MAX, UINT8_C(151), UINT8_C(147), UINT8_C(233),    UINT8_MAX,
      UINT8_C(173),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C(184), UINT8_C(213),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(213), UINT8_C(197), UINT8_C(172), UINT8_C(230), UINT8_C(171),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C( 99), UINT8_C(228), UINT8_C(190),    UINT8_MAX, UINT8_C(242),    UINT8_MAX,
         UINT8_MAX, UINT8_C(160), UINT8_C(172),    UINT8_MAX,    UINT8_MAX, UINT8_C(235),    UINT8_MAX,    UINT8_MAX,
      UINT8_C( 91), UINT8_C(254),    UINT8_MAX,    UINT8_MAX, UINT8_C(203), UINT8_C(120),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C( 61),    UINT8_MAX,    UINT8_MAX, UINT8_C(233), UINT8_C(195),    UINT8_MAX,    UINT8_MAX,
      UINT8_C(238),    UINT8_MAX,    UINT8_MAX, UINT8_C(172),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(174), UINT8_C(197),    UINT8_MAX, UINT8_C(241), UINT8_C(176), UINT8_C(160),    UINT8_MAX,    UINT8_MAX,
      UINT8_C(158),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(143), UINT8_C(190),    UINT8_MAX,
      UINT8_C(204), UINT8_C(190),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(205), UINT8_C(237), UINT8_C(112),
      UINT8_C(174),    UINT8_MAX,    UINT8_MAX, UINT8_C(219),    UINT8_MAX, UINT8_C( 54),    UINT8_MAX,    UINT8_MAX,
      UINT8_C(252), UINT8_C(193), UINT8_C(181), UINT8_C(173),    UINT8_MAX, UINT8_C(239), UINT8_C(186),    UINT8_MAX,
         UINT8_MAX, UINT8_C(210),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(231), UINT8_C(134), UINT8_C(229),    UINT8_MAX,    UINT8_MAX, UINT8_C(210), UINT8_C(217),    UINT8_MAX,
      UINT8_C(218), UINT8_C(246), UINT8_C(222), UINT8_C(240),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(  7),    UINT8_MAX, UINT8_C(215),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(100), UINT8_C(211), UINT8_C(184), UINT8_C(198), UINT8_C(252), UINT8_C(238), UINT8_C(245), UINT8_C(227),
         UINT8_MAX, UINT8_C(218),    UINT8_MAX, UINT8_C(202), UINT8_C(173),    UINT8_MAX, UINT8_C(204),    UINT8_MAX,
      UINT8_C( 29), UINT8_C(170),    UINT8_MAX,    UINT8_MAX, UINT8_C(240),    UINT8_MAX,    UINT8_MAX, UINT8_C(248),
      UINT8_C(148),    UINT8_MAX,    UINT8_MAX, UINT8_C(236), UINT8_C(221), UINT8_C(203),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(254),    UINT8_MAX, UINT8_C(168),
         UINT8_MAX, UINT8_C(203), UINT8_C(114), UINT8_C(135), UINT8_C(241), UINT8_C( 63), UINT8_C( 15),    UINT8_MAX,
      UINT8_C(233), UINT8_C(135),    UINT8_MAX, UINT8_C(219),    UINT8_MAX, UINT8_C(205), UINT8_C(211),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(247),    UINT8_MAX, UINT8_C(190),    UINT8_MAX, UINT8_C(158),
         UINT8_MAX, UINT8_C( 67), UINT8_C( 58),    UINT8_MAX,    UINT8_MAX, UINT8_C(185), UINT8_C(222),    UINT8_MAX,
      UINT8_C(133),    UINT8_MAX, UINT8_C(161), UINT8_C(118), UINT8_C(144), UINT8_C(176), UINT8_C(133),    UINT8_MAX,
         UINT8_MAX, UINT8_C(221),    UINT8_MAX, UINT8_C(234), UINT8_C(171),    UINT8_MAX,    UINT8_MAX, UINT8_C(197),
      UINT8_C( 93),    UINT8_MAX, UINT8_C(188),    UINT8_MAX,    UINT8_MAX, UINT8_C(246), UINT8_C(252),    UINT8_MAX,
      UINT8_C( 57),    UINT8_MAX,    UINT8_MAX, UINT8_C(122), UINT8_C(240),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(138), UINT8_C( 55), UINT8_C(235),    UINT8_MAX, UINT8_C(233), UINT8_C(112), UINT8_C(148),    UINT8_MAX,
         UINT8_MAX, UINT8_C(233),    UINT8_MAX, UINT8_C(250),    UINT8_MAX, UINT8_C( 60), UINT8_C(191), UINT8_C(111),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(193),    UINT8_MAX, UINT8_C(201), UINT8_C(231),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(240),    UINT8_MAX, UINT8_C(189),    UINT8_MAX,    UINT8_MAX,
      UINT8_C(244),    UINT8_MAX, UINT8_C( 32), UINT8_C(221), UINT8_C(195), UINT8_C(181),    UINT8_MAX,    UINT8_MAX,
      UINT8_C(158),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(204),    UINT8_MAX, UINT8_C(230),
      UINT8_C( 72), UINT8_C(237), UINT8_C(169),    UINT8_MAX,    UINT8_MAX, UINT8_C(144),    UINT8_MAX, UINT8_C(183),
         UINT8_MAX, UINT8_C(142), UINT8_C(167),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C( 97), UINT8_C(116), UINT8_C( 30),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(199),
         UINT8_MAX,    UINT8_MAX, UINT8_C(120), UINT8_C(110),    UINT8_MAX, UINT8_C(152),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(254),    UINT8_MAX,    UINT8_MAX, UINT8_C(142),    UINT8_MAX, UINT8_C(242), UINT8_C( 96),
         UINT8_MAX,    UINT8_MAX, UINT8_C(173), UINT8_C( 83),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(117),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(207),    UINT8_MAX, UINT8_C(102), UINT8_C(246),
      UINT8_C(169), UINT8_C(222),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(186),    UINT8_MAX, UINT8_C(251),
      UINT8_C(184),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(162), UINT8_C( 41),    UINT8_MAX, UINT8_C(170),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(147),    UINT8_MAX, UINT8_C(204),
      UINT8_C( 69),    UINT8_MAX, UINT8_C(107),    UINT8_MAX,    UINT8_MAX, UINT8_C(209), UINT8_C( 10),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 42),    UINT8_MAX,    UINT8_MAX, UINT8_C(226),
      UINT8_C(167),    UINT8_MAX,    UINT8_MAX, UINT8_C( 73), UINT8_C(128), UINT8_C(210), UINT8_C(245),    UINT8_MAX,
         UINT8_MAX, UINT8_C(244), UINT8_C(176),    UINT8_MAX,    UINT8_MAX, UINT8_C( 38),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(184), UINT8_C(224), UINT8_C(213), UINT8_C(137), UINT8_C(234), UINT8_C(137), UINT8_C( 57),
      UINT8_C( 89), UINT8_C(247),    UINT8_MAX, UINT8_C(131),    UINT8_MAX, UINT8_C(127),    UINT8_MAX,    UINT8_MAX,
      UINT8_C(214), UINT8_C(145), UINT8_C(106), UINT8_C( 86),    UINT8_MAX,    UINT8_MAX, UINT8_C(154),    UINT8_MAX,
      UINT8_C( 83),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 89),    UINT8_MAX,    UINT8_MAX,
      UINT8_C( 18), UINT8_C(134), UINT8_C( 18), UINT8_C(155),    UINT8_MAX, UINT8_C(155), UINT8_C(213), UINT8_C(203),
      UINT8_C(148), UINT8_C( 52),    UINT8_MAX,    UINT8_MAX, UINT8_C(180), UINT8_C(182),    UINT8_MAX, UINT8_C(138),
         UINT8_MAX, UINT8_C(153), UINT8_C(225), UINT8_C(171), UINT8_C(248),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(197),    UINT8_MAX,    UINT8_MAX, UINT8_C( 53), UINT8_C(158), UINT8_C(207),    UINT8_MAX, UINT8_C(176),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(199), UINT8_C( 31),    UINT8_MAX,    UINT8_MAX, UINT8_C(179),
         UINT8_MAX, UINT8_C(226), UINT8_C(192),    UINT8_MAX, UINT8_C(153), UINT8_C(238),    UINT8_MAX, UINT8_C(224),
         UINT8_MAX, UINT8_C(117),    UINT8_MAX, UINT8_C(128), UINT8_C(240),    UINT8_MAX, UINT8_C(205), UINT8_C(181),
         UINT8_MAX, UINT8_C(245), UINT8_C(235),    UINT8_MAX, UINT8_C(196),    UINT8_MAX, UINT8_C( 89),    UINT8_MAX,
      UINT8_C(224), UINT8_C(165), UINT8_C(225),    UINT8_MAX, UINT8_C(200), UINT8_C(116), UINT8_C(179),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(240), UINT8_C( 98), UINT8_C(189), UINT8_C(209), UINT8_C(234),
         UINT8_MAX,    UINT8_MAX, UINT8_C(106),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(219),    UINT8_MAX,
         UINT8_MAX, UINT8_C(198), UINT8_C(215), UINT8_C(242),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(215), UINT8_C(238),    UINT8_MAX,    UINT8_MAX, UINT8_C( 99), UINT8_C(183), UINT8_C(189), UINT8_C(186),
         UINT8_MAX, UINT8_C(230), UINT8_C(171), UINT8_C(142), UINT8_C(164), UINT8_C(125), UINT8_C(120),    UINT8_MAX,
      UINT8_C(219), UINT8_C(226), UINT8_C(253),    UINT8_MAX,    UINT8_MAX, UINT8_C(216),    UINT8_MAX,    UINT8_MAX,
      UINT8_C(159), UINT8_C(  5),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 70), UINT8_C(198),    UINT8_MAX,
         UINT8_MAX, UINT8_C(202),    UINT8_MAX, UINT8_C(152), UINT8_C(130), UINT8_C(106),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(254), UINT8_C( 59), UINT8_C(244), UINT8_C(123), UINT8_C(179), UINT8_C(205),    UINT8_MAX,
         UINT8_MAX, UINT8_C(203),    UINT8_MAX, UINT8_C(176),    UINT8_MAX, UINT8_C(133), UINT8_C(248), UINT8_C( 66),
      UINT8_C(138),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(203),    UINT8_MAX, UINT8_C(174),
      UINT8_C(149),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(153), UINT8_C(197),    UINT8_MAX,
      UINT8_C(153),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(180), UINT8_C(248), UINT8_C(108),    UINT8_MAX,
      UINT8_C(195),    UINT8_MAX, UINT8_C(251), UINT8_C(102), UINT8_C( 72), UINT8_C(243), UINT8_C(169), UINT8_C(210),
         UINT8_MAX, UINT8_C(174), UINT8_C(148), UINT8_C(158), UINT8_C(121), UINT8_C( 98),    UINT8_MAX,    UINT8_MAX,
      UINT8_C(221), UINT8_C(147),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(237), UINT8_C(248), UINT8_C(198),
      UINT8_C(237),    UINT8_MAX, UINT8_C(219),    UINT8_MAX,    UINT8_MAX, UINT8_C( 71), UINT8_C(237),    UINT8_MAX,
         UINT8_MAX, UINT8_C(232), UINT8_C( 68), UINT8_C( 83),    UINT8_MAX, UINT8_C(237),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(187),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(237),    UINT8_MAX, UINT8_C(250),
      UINT8_C(129),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 56), UINT8_C(181), UINT8_C(117), UINT8_C( 38),
      UINT8_C(216), UINT8_C( 80),    UINT8_MAX, UINT8_C(242), UINT8_C(152), UINT8_C(181), UINT8_C(208), UINT8_C(163),
      UINT8_C(157),    UINT8_MAX, UINT8_C(248),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(156),
      UINT8_C(218),    UINT8_MAX, UINT8_C(176), UINT8_C(247),    UINT8_MAX, UINT8_C(212), UINT8_C(242), UINT8_C(137),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(101), UINT8_C(173),    UINT8_MAX, UINT8_C( 61),
      UINT8_C(254),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(253),    UINT8_MAX, UINT8_C( 58),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(144), UINT8_C(177),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(181), UINT8_C( 53),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(197), UINT8_C(119),    UINT8_MAX, UINT8_C( 43),    UINT8_MAX,    UINT8_MAX, UINT8_C(104),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C(185), UINT8_C(115), UINT8_C(152), UINT8_C(244),    UINT8_MAX, UINT8_C(172),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(120), UINT8_C(181), UINT8_C(114), UINT8_C(163),    UINT8_MAX,
         UINT8_MAX, UINT8_C(198),    UINT8_MAX,    UINT8_MAX, UINT8_C(219),    UINT8_MAX, UINT8_C( 96),    UINT8_MAX,
      UINT8_C(205),    UINT8_MAX,    UINT8_MAX, UINT8_C(241),    UINT8_MAX, UINT8_C( 52),    UINT8_MAX, UINT8_C(177),
      UINT8_C(205),    UINT8_MAX,    UINT8_MAX, UINT8_C(101), UINT8_C(194),    UINT8_MAX,    UINT8_MAX, UINT8_C(233),
         UINT8_MAX, UINT8_C(211), UINT8_C( 97),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(203), UINT8_C(134),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(169),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(206),    UINT8_MAX, UINT8_C(176),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(165), UINT8_C(125),    UINT8_MAX, UINT8_C(217), UINT8_C(143),    UINT8_MAX, UINT8_C( 51),
      UINT8_C(100), UINT8_C(139),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(178), UINT8_C(197),    UINT8_MAX,
         UINT8_MAX, UINT8_C(233),    UINT8_MAX,    UINT8_MAX, UINT8_C(110), UINT8_C( 74),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C(207), UINT8_C(169),    UINT8_MAX, UINT8_C( 80), UINT8_C(193),    UINT8_MAX,
      UINT8_C(245),    UINT8_MAX, UINT8_C(204), UINT8_C(208),    UINT8_MAX, UINT8_C(246),    UINT8_MAX,    UINT8_MAX,
      UINT8_C(130), UINT8_C( 69), UINT8_C(221),    UINT8_MAX, UINT8_C(249), UINT8_C(162), UINT8_C(109),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(249),    UINT8_MAX,    UINT8_MAX, UINT8_C(250),    UINT8_MAX,
      UINT8_C(100), UINT8_C(202), UINT8_C(194),    UINT8_MAX,    UINT8_MAX, UINT8_C(131), UINT8_C(252),    UINT8_MAX,
      UINT8_C(194),    UINT8_MAX,    UINT8_MAX, UINT8_C(145), UINT8_C(191), UINT8_C(228), UINT8_C(195),    UINT8_MAX,
         UINT8_MAX, UINT8_C(160),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(205),
         UINT8_MAX, UINT8_C(160), UINT8_C(199), UINT8_C(235),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(199),    UINT8_MAX, UINT8_C(167),    UINT8_MAX, UINT8_C(123), UINT8_C(184),    UINT8_MAX,
         UINT8_MAX, UINT8_C(153), UINT8_C(159),    UINT8_MAX, UINT8_C(125),    UINT8_MAX, UINT8_C( 69),    UINT8_MAX,
         UINT8_MAX, UINT8_C(154) };

  static uint8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t
      rv,
      av = simde_svld1_u8(pg, &(a[i])),
      bv = simde_svld1_u8(pg, &(b[i]));

    rv = simde_svqadd_u8(av, bv);

    simde_svst1_u8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vu8(len, e, r);

  return 0;
#else
  uint8_t a[1024], b[1024], e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t av, bv, ev;

    av = simde_svld1_u8(pg, &(a[i]));
    bv = simde_svld1_u8(pg, &(b[i]));

    ev = simde_svqadd_u8(av, bv);

    simde_svst1_u8(pg, &(e[i]), ev);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const uint16_t a[] =
    { UINT16_C(46386), UINT16_C(62082), UINT16_C(24561), UINT16_C(49348), UINT16_C(24955), UINT16_C(44730), UINT16_C(52632), UINT16_C(49639),
      UINT16_C(53668), UINT16_C(44312), UINT16_C(37117), UINT16_C(32729), UINT16_C(48509), UINT16_C(56345), UINT16_C(47249), UINT16_C(50203),
      UINT16_C(40301), UINT16_C(24246), UINT16_C(31485), UINT16_C(30750), UINT16_C(55772), UINT16_C(29735), UINT16_C( 3750), UINT16_C(18998),
      UINT16_C(20191), UINT16_C(56567), UINT16_C(53470), UINT16_C(23388), UINT16_C(30094), UINT16_C( 7991), UINT16_C(21293), UINT16_C(39907),
      UINT16_C(39664), UINT16_C(60921), UINT16_C( 6164), UINT16_C(61542), UINT16_C(36337), UINT16_C(38757), UINT16_C(39835), UINT16_C(31713),
      UINT16_C(55529), UINT16_C(51287), UINT16_C(45992), UINT16_C(13859), UINT16_C(23336), UINT16_C(22102), UINT16_C(14766), UINT16_C(40689),
      UINT16_C(60115), UINT16_C(59532), UINT16_C(61954), UINT16_C(62424), UINT16_C(15743), UINT16_C( 6794), UINT16_C(27608), UINT16_C(49813),
      UINT16_C(60739), UINT16_C(60554), UINT16_C(44448), UINT16_C(51490), UINT16_C(30728), UINT16_C(46623), UINT16_C( 4274), UINT16_C(34133),
      UINT16_C(57850), UINT16_C(64877), UINT16_C(18131), UINT16_C(21232), UINT16_C(31619), UINT16_C(23660), UINT16_C(  742), UINT16_C(10782),
      UINT16_C(43247), UINT16_C(36630), UINT16_C(14421), UINT16_C(24152), UINT16_C(30641), UINT16_C(25364), UINT16_C(27015), UINT16_C(33512),
      UINT16_C(22090), UINT16_C( 7551), UINT16_C(28572), UINT16_C( 8047), UINT16_C(56554), UINT16_C(53627), UINT16_C(39390), UINT16_C(52731),
      UINT16_C( 4417), UINT16_C(38748), UINT16_C(46409), UINT16_C(64245), UINT16_C( 2348), UINT16_C(46173), UINT16_C(18035), UINT16_C(48438),
      UINT16_C(46492), UINT16_C(14555), UINT16_C(18980), UINT16_C( 3927), UINT16_C(54054), UINT16_C( 1248), UINT16_C(56172), UINT16_C(44753),
      UINT16_C(12012), UINT16_C(13637), UINT16_C(15075), UINT16_C( 3888), UINT16_C(36163), UINT16_C(46787), UINT16_C(63955), UINT16_C(28532),
      UINT16_C(20398), UINT16_C(54183), UINT16_C(65433), UINT16_C(49378), UINT16_C(49874), UINT16_C(16068), UINT16_C(38557), UINT16_C(35308),
      UINT16_C(12740), UINT16_C(42942), UINT16_C(61035), UINT16_C(44982), UINT16_C(31356), UINT16_C(20325), UINT16_C(55667), UINT16_C( 8895),
      UINT16_C(26152), UINT16_C(49909), UINT16_C(55141), UINT16_C(14210), UINT16_C(18073), UINT16_C(13942), UINT16_C(25308), UINT16_C(41151),
      UINT16_C(32148), UINT16_C(65351), UINT16_C(65132), UINT16_C(59566), UINT16_C( 5240), UINT16_C(60215), UINT16_C(63213), UINT16_C( 5645),
      UINT16_C(  605), UINT16_C(49880), UINT16_C(23257), UINT16_C(29434), UINT16_C(28832), UINT16_C(32168), UINT16_C(26578), UINT16_C(26141),
      UINT16_C(26085), UINT16_C(20838), UINT16_C( 5219), UINT16_C(56121), UINT16_C(28712), UINT16_C( 5830), UINT16_C(54375), UINT16_C(50220),
      UINT16_C( 1238), UINT16_C(45190), UINT16_C(32862), UINT16_C(65058), UINT16_C(52208), UINT16_C(50043), UINT16_C(39218), UINT16_C( 5929),
      UINT16_C(36862), UINT16_C(24936), UINT16_C(41380), UINT16_C(52284), UINT16_C(  530), UINT16_C(31202), UINT16_C( 3798), UINT16_C(44349),
      UINT16_C(49938), UINT16_C(28765), UINT16_C(32580), UINT16_C(13423), UINT16_C(59978), UINT16_C(32247), UINT16_C( 8579), UINT16_C(33172),
      UINT16_C(64944), UINT16_C(21730), UINT16_C( 7838), UINT16_C(45089), UINT16_C(  801), UINT16_C(63273), UINT16_C(26130), UINT16_C( 9380),
      UINT16_C(  298), UINT16_C(28309), UINT16_C( 1153), UINT16_C(52130), UINT16_C(39662), UINT16_C(29256), UINT16_C(56763), UINT16_C(27635),
      UINT16_C(55002), UINT16_C(30912), UINT16_C(57844), UINT16_C( 5417), UINT16_C(21220), UINT16_C(62989), UINT16_C(45497), UINT16_C(58139),
      UINT16_C(45235), UINT16_C(13393), UINT16_C(62388), UINT16_C(41727), UINT16_C(18573), UINT16_C(18452), UINT16_C( 2085), UINT16_C(65460),
      UINT16_C(29918), UINT16_C(53879), UINT16_C(41045), UINT16_C(14824), UINT16_C(62963), UINT16_C(44080), UINT16_C(19366), UINT16_C(22927),
      UINT16_C(57595), UINT16_C(44941), UINT16_C(36307), UINT16_C(24913), UINT16_C(26325), UINT16_C(64169), UINT16_C(23918), UINT16_C(19705),
      UINT16_C(28881), UINT16_C( 9758), UINT16_C( 1553), UINT16_C( 1120), UINT16_C(37115), UINT16_C(41648), UINT16_C(16347), UINT16_C(55035),
      UINT16_C(35103), UINT16_C(62085), UINT16_C(54806), UINT16_C(60243), UINT16_C(64828), UINT16_C(43749), UINT16_C(56922), UINT16_C(11510),
      UINT16_C( 5454), UINT16_C(24402), UINT16_C(45595), UINT16_C( 5987), UINT16_C( 4930), UINT16_C( 7609), UINT16_C(46162), UINT16_C(29171),
      UINT16_C(30781), UINT16_C(21348), UINT16_C(46927), UINT16_C(35646), UINT16_C( 9140), UINT16_C( 3894), UINT16_C(11265), UINT16_C(20539),
      UINT16_C(36161), UINT16_C(23983), UINT16_C( 4928), UINT16_C(33396), UINT16_C(11558), UINT16_C(31136), UINT16_C(37857), UINT16_C( 8170),
      UINT16_C(19980), UINT16_C(23410), UINT16_C(45318), UINT16_C(47846), UINT16_C( 7380), UINT16_C(54985), UINT16_C( 1097), UINT16_C(35366),
      UINT16_C(54674), UINT16_C(53991), UINT16_C(23528), UINT16_C( 3924), UINT16_C(62600), UINT16_C(27272), UINT16_C(29320), UINT16_C(38025),
      UINT16_C(64449), UINT16_C(51183), UINT16_C(54700), UINT16_C(33153), UINT16_C(19442), UINT16_C(15191), UINT16_C(32079), UINT16_C(57797),
      UINT16_C(44370), UINT16_C(15283), UINT16_C( 2056), UINT16_C(37194), UINT16_C(54012), UINT16_C(34043), UINT16_C(33860), UINT16_C( 1304),
      UINT16_C( 1919), UINT16_C(11468), UINT16_C(20189), UINT16_C(53165), UINT16_C( 1177), UINT16_C(59402), UINT16_C(53121), UINT16_C(54218),
      UINT16_C(32124), UINT16_C(34062), UINT16_C(22661), UINT16_C(33302), UINT16_C( 4394), UINT16_C(28422), UINT16_C( 8085), UINT16_C( 5236),
      UINT16_C(16678), UINT16_C(  832), UINT16_C(60815), UINT16_C(10450), UINT16_C(56561), UINT16_C(29200), UINT16_C(55980), UINT16_C(10310),
      UINT16_C(21592), UINT16_C(56749), UINT16_C(50093), UINT16_C(55135), UINT16_C(26324), UINT16_C(26950), UINT16_C(48005), UINT16_C(43902),
      UINT16_C(48892), UINT16_C(35759), UINT16_C(33196), UINT16_C(40371), UINT16_C(50014), UINT16_C( 2576), UINT16_C(22174), UINT16_C(63026),
      UINT16_C(57514), UINT16_C(22483), UINT16_C(13219), UINT16_C(30767), UINT16_C(30105), UINT16_C( 7905), UINT16_C(24368) };
  static const uint16_t b[] =
    { UINT16_C(65524), UINT16_C(20739), UINT16_C(40274), UINT16_C(55694), UINT16_C(30346), UINT16_C(35276), UINT16_C(29254), UINT16_C(64443),
      UINT16_C(17975), UINT16_C(27589), UINT16_C(33730), UINT16_C(26987), UINT16_C(20711), UINT16_C( 9195), UINT16_C( 8309), UINT16_C(27083),
      UINT16_C(52767), UINT16_C(29370), UINT16_C(18539), UINT16_C(62795), UINT16_C( 6334), UINT16_C( 1406), UINT16_C(14986), UINT16_C(49664),
      UINT16_C(50560), UINT16_C(16941), UINT16_C(38984), UINT16_C(12203), UINT16_C(38633), UINT16_C(24146), UINT16_C( 7606), UINT16_C(54727),
      UINT16_C(33260), UINT16_C(22343), UINT16_C(37833), UINT16_C(34893), UINT16_C(52139), UINT16_C(13709), UINT16_C(36101), UINT16_C(34295),
      UINT16_C( 9554), UINT16_C(39623), UINT16_C(29373), UINT16_C(42697), UINT16_C( 7176), UINT16_C(48644), UINT16_C(52025), UINT16_C( 9620),
      UINT16_C(56140), UINT16_C( 5757), UINT16_C(51822), UINT16_C( 6558), UINT16_C(11157), UINT16_C(39759), UINT16_C(18104), UINT16_C( 2592),
      UINT16_C(59499), UINT16_C(10660), UINT16_C(27994), UINT16_C(25551), UINT16_C(54409), UINT16_C(49953), UINT16_C(46495), UINT16_C(60648),
      UINT16_C(26001), UINT16_C(65282), UINT16_C(41007), UINT16_C(50457), UINT16_C(26827), UINT16_C(33632), UINT16_C(32942), UINT16_C( 6797),
      UINT16_C(12648), UINT16_C(49987), UINT16_C( 4766), UINT16_C(10278), UINT16_C(18406), UINT16_C(34539), UINT16_C(54269), UINT16_C(36466),
      UINT16_C(29753), UINT16_C(26765), UINT16_C(42516), UINT16_C(57133), UINT16_C(36110), UINT16_C(48482), UINT16_C(61198), UINT16_C(30423),
      UINT16_C( 6688), UINT16_C(48697), UINT16_C(24364), UINT16_C( 5094), UINT16_C(53671), UINT16_C(42137), UINT16_C( 2981), UINT16_C(56882),
      UINT16_C(49023), UINT16_C(37702), UINT16_C(29798), UINT16_C(29810), UINT16_C(54273), UINT16_C( 3889), UINT16_C( 2243), UINT16_C(58246),
      UINT16_C(48930), UINT16_C(20385), UINT16_C(34847), UINT16_C(50786), UINT16_C(64345), UINT16_C(65130), UINT16_C(39942), UINT16_C(34268),
      UINT16_C( 9051), UINT16_C(49432), UINT16_C(35479), UINT16_C(38966), UINT16_C(26462), UINT16_C( 8616), UINT16_C(11888), UINT16_C(37380),
      UINT16_C(42477), UINT16_C( 3297), UINT16_C(17197), UINT16_C(34770), UINT16_C(15422), UINT16_C(17541), UINT16_C(25304), UINT16_C(13513),
      UINT16_C(57733), UINT16_C( 7413), UINT16_C(11115), UINT16_C(51636), UINT16_C(23699), UINT16_C( 1002), UINT16_C(61066), UINT16_C(30869),
      UINT16_C(30612), UINT16_C(49540), UINT16_C(22458), UINT16_C(63816), UINT16_C(52883), UINT16_C(27709), UINT16_C( 1840), UINT16_C(46496),
      UINT16_C(38376), UINT16_C(21713), UINT16_C(34241), UINT16_C(21533), UINT16_C( 2274), UINT16_C(27735), UINT16_C(60662), UINT16_C(35556),
      UINT16_C(26979), UINT16_C( 7756), UINT16_C(38080), UINT16_C(21271), UINT16_C(21602), UINT16_C(37567), UINT16_C(24411), UINT16_C(17479),
      UINT16_C( 6389), UINT16_C(46744), UINT16_C(46494), UINT16_C(32778), UINT16_C(25021), UINT16_C(46316), UINT16_C(53581), UINT16_C(45374),
      UINT16_C(35386), UINT16_C(64207), UINT16_C(58911), UINT16_C(33101), UINT16_C( 3386), UINT16_C(38420), UINT16_C(23404), UINT16_C(25050),
      UINT16_C(29300), UINT16_C( 4631), UINT16_C( 8487), UINT16_C(58770), UINT16_C(32386), UINT16_C(53401), UINT16_C(55119), UINT16_C(35201),
      UINT16_C(20578), UINT16_C(33155), UINT16_C(53558), UINT16_C(28674), UINT16_C( 5854), UINT16_C(18950), UINT16_C(57458), UINT16_C(59052),
      UINT16_C(50002), UINT16_C(31480), UINT16_C(35557), UINT16_C(26463), UINT16_C(63496), UINT16_C(22583), UINT16_C(47311), UINT16_C(12769),
      UINT16_C(25864), UINT16_C(16050), UINT16_C(46390), UINT16_C( 5295), UINT16_C(46539), UINT16_C(15710), UINT16_C( 2710), UINT16_C(59427),
      UINT16_C( 7118), UINT16_C(45922), UINT16_C(49573), UINT16_C(44570), UINT16_C(21177), UINT16_C(35078), UINT16_C(59146), UINT16_C( 5050),
      UINT16_C(27980), UINT16_C(33361), UINT16_C(   34), UINT16_C(60822), UINT16_C(62902), UINT16_C(19499), UINT16_C(20223), UINT16_C(52532),
      UINT16_C(38762), UINT16_C( 3968), UINT16_C(39768), UINT16_C( 4797), UINT16_C(50157), UINT16_C(63387), UINT16_C(21931), UINT16_C(63242),
      UINT16_C(23746), UINT16_C(58490), UINT16_C( 4188), UINT16_C( 4818), UINT16_C(64773), UINT16_C( 1374), UINT16_C(37707), UINT16_C(46546),
      UINT16_C(21290), UINT16_C(33477), UINT16_C(33518), UINT16_C(56212), UINT16_C(12102), UINT16_C(61906), UINT16_C(56709), UINT16_C(18408),
      UINT16_C(25145), UINT16_C(38188), UINT16_C(65139), UINT16_C(30888), UINT16_C( 1787), UINT16_C(18045), UINT16_C(20633), UINT16_C(50172),
      UINT16_C(49571), UINT16_C(37190), UINT16_C(55875), UINT16_C(35180), UINT16_C(15882), UINT16_C(36730), UINT16_C(25371), UINT16_C(21718),
      UINT16_C(  709), UINT16_C(14570), UINT16_C(37376), UINT16_C(64433), UINT16_C(11928), UINT16_C(12866), UINT16_C(15998), UINT16_C( 8693),
      UINT16_C(15359), UINT16_C(17074), UINT16_C( 7702), UINT16_C( 8396), UINT16_C(18013), UINT16_C(30895), UINT16_C(34217), UINT16_C(28621),
      UINT16_C(46984), UINT16_C(34983), UINT16_C(22601), UINT16_C(57732), UINT16_C(50823), UINT16_C( 1299), UINT16_C( 2308), UINT16_C(  807),
      UINT16_C(55620), UINT16_C(23109), UINT16_C( 4600), UINT16_C(21882), UINT16_C(10584), UINT16_C(  461), UINT16_C(39599), UINT16_C(14192),
      UINT16_C( 6225), UINT16_C(39615), UINT16_C(17264), UINT16_C(63356), UINT16_C(36617), UINT16_C( 3581), UINT16_C( 9368), UINT16_C(56592),
      UINT16_C(22269), UINT16_C(62775), UINT16_C(45671), UINT16_C(48970), UINT16_C( 6363), UINT16_C(35521), UINT16_C(12722), UINT16_C( 1217),
      UINT16_C(33097), UINT16_C(47774), UINT16_C( 6852), UINT16_C(52913), UINT16_C(44714), UINT16_C(17115), UINT16_C(60626), UINT16_C(53279),
      UINT16_C(22338), UINT16_C(43461), UINT16_C( 4105), UINT16_C(58473), UINT16_C(10792), UINT16_C(55919), UINT16_C(12379), UINT16_C(42462),
      UINT16_C(32177), UINT16_C(30303), UINT16_C( 4247), UINT16_C(16708), UINT16_C( 8127), UINT16_C(37252), UINT16_C(41739), UINT16_C(19809),
      UINT16_C(10234), UINT16_C( 1015), UINT16_C(24631), UINT16_C(24552), UINT16_C(22410), UINT16_C(58681), UINT16_C( 6279), UINT16_C(14730),
      UINT16_C(59797), UINT16_C(11439), UINT16_C(62458), UINT16_C(47470), UINT16_C(61970), UINT16_C( 7754), UINT16_C(44181) };
  static const uint16_t e[] =
    {      UINT16_MAX,      UINT16_MAX, UINT16_C(64835),      UINT16_MAX, UINT16_C(55301),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
           UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(59716),      UINT16_MAX,      UINT16_MAX, UINT16_C(55558),      UINT16_MAX,
           UINT16_MAX, UINT16_C(53616), UINT16_C(50024),      UINT16_MAX, UINT16_C(62106), UINT16_C(31141), UINT16_C(18736),      UINT16_MAX,
           UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(35591),      UINT16_MAX, UINT16_C(32137), UINT16_C(28899),      UINT16_MAX,
           UINT16_MAX,      UINT16_MAX, UINT16_C(43997),      UINT16_MAX,      UINT16_MAX, UINT16_C(52466),      UINT16_MAX,      UINT16_MAX,
      UINT16_C(65083),      UINT16_MAX,      UINT16_MAX, UINT16_C(56556), UINT16_C(30512),      UINT16_MAX,      UINT16_MAX, UINT16_C(50309),
           UINT16_MAX, UINT16_C(65289),      UINT16_MAX,      UINT16_MAX, UINT16_C(26900), UINT16_C(46553), UINT16_C(45712), UINT16_C(52405),
           UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(50769),      UINT16_MAX,
           UINT16_MAX,      UINT16_MAX, UINT16_C(59138),      UINT16_MAX, UINT16_C(58446), UINT16_C(57292), UINT16_C(33684), UINT16_C(17579),
      UINT16_C(55895),      UINT16_MAX, UINT16_C(19187), UINT16_C(34430), UINT16_C(49047), UINT16_C(59903),      UINT16_MAX,      UINT16_MAX,
      UINT16_C(51843), UINT16_C(34316),      UINT16_MAX, UINT16_C(65180),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
      UINT16_C(11105),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(56019),      UINT16_MAX, UINT16_C(21016),      UINT16_MAX,
           UINT16_MAX, UINT16_C(52257), UINT16_C(48778), UINT16_C(33737),      UINT16_MAX, UINT16_C( 5137), UINT16_C(58415),      UINT16_MAX,
      UINT16_C(60942), UINT16_C(34022), UINT16_C(49922), UINT16_C(54674),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(62800),
      UINT16_C(29449),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(24684), UINT16_C(50445),      UINT16_MAX,
      UINT16_C(55217), UINT16_C(46239),      UINT16_MAX,      UINT16_MAX, UINT16_C(46778), UINT16_C(37866),      UINT16_MAX, UINT16_C(22408),
           UINT16_MAX, UINT16_C(57322),      UINT16_MAX,      UINT16_MAX, UINT16_C(41772), UINT16_C(14944),      UINT16_MAX,      UINT16_MAX,
      UINT16_C(62760),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(58123),      UINT16_MAX, UINT16_C(65053), UINT16_C(52141),
      UINT16_C(38981),      UINT16_MAX, UINT16_C(57498), UINT16_C(50967), UINT16_C(31106), UINT16_C(59903),      UINT16_MAX, UINT16_C(61697),
      UINT16_C(53064), UINT16_C(28594), UINT16_C(43299),      UINT16_MAX, UINT16_C(50314), UINT16_C(43397),      UINT16_MAX,      UINT16_MAX,
      UINT16_C( 7627),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(51303),
           UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C( 3916),      UINT16_MAX, UINT16_C(27202),      UINT16_MAX,
           UINT16_MAX, UINT16_C(33396), UINT16_C(41067),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(63698),      UINT16_MAX,
           UINT16_MAX, UINT16_C(54885), UINT16_C(61396),      UINT16_MAX, UINT16_C( 6655),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
      UINT16_C(50300), UINT16_C(59789), UINT16_C(36710),      UINT16_MAX,      UINT16_MAX, UINT16_C(51839),      UINT16_MAX, UINT16_C(40404),
           UINT16_MAX, UINT16_C(46962),      UINT16_MAX, UINT16_C(10712),      UINT16_MAX,      UINT16_MAX, UINT16_C(48207),      UINT16_MAX,
      UINT16_C(52353), UINT16_C(59315),      UINT16_MAX,      UINT16_MAX, UINT16_C(39750), UINT16_C(53530), UINT16_C(61231),      UINT16_MAX,
      UINT16_C(57898),      UINT16_MAX, UINT16_C(41079),      UINT16_MAX,      UINT16_MAX, UINT16_C(63579), UINT16_C(39589),      UINT16_MAX,
           UINT16_MAX, UINT16_C(48909),      UINT16_MAX, UINT16_C(29710),      UINT16_MAX,      UINT16_MAX, UINT16_C(45849),      UINT16_MAX,
      UINT16_C(52627),      UINT16_MAX, UINT16_C( 5741), UINT16_C( 5938),      UINT16_MAX, UINT16_C(43022), UINT16_C(54054),      UINT16_MAX,
      UINT16_C(56393),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(29918),
      UINT16_C(30599), UINT16_C(62590),      UINT16_MAX, UINT16_C(36875), UINT16_C( 6717), UINT16_C(25654),      UINT16_MAX,      UINT16_MAX,
           UINT16_MAX, UINT16_C(58538),      UINT16_MAX,      UINT16_MAX, UINT16_C(25022), UINT16_C(40624), UINT16_C(36636), UINT16_C(42257),
      UINT16_C(36870), UINT16_C(38553), UINT16_C(42304),      UINT16_MAX, UINT16_C(23486), UINT16_C(44002), UINT16_C(53855), UINT16_C(16863),
      UINT16_C(35339), UINT16_C(40484), UINT16_C(53020), UINT16_C(56242), UINT16_C(25393),      UINT16_MAX, UINT16_C(35314), UINT16_C(63987),
           UINT16_MAX,      UINT16_MAX, UINT16_C(46129), UINT16_C(61656),      UINT16_MAX, UINT16_C(28571), UINT16_C(31628), UINT16_C(38832),
           UINT16_MAX,      UINT16_MAX, UINT16_C(59300), UINT16_C(55035), UINT16_C(30026), UINT16_C(15652),      UINT16_MAX,      UINT16_MAX,
      UINT16_C(50595), UINT16_C(54898), UINT16_C(19320),      UINT16_MAX,      UINT16_MAX, UINT16_C(37624), UINT16_C(43228), UINT16_C(57896),
      UINT16_C(24188),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C( 7540),      UINT16_MAX,      UINT16_MAX, UINT16_C(55435),
      UINT16_C(65221),      UINT16_MAX, UINT16_C(29513),      UINT16_MAX, UINT16_C(49108), UINT16_C(45537),      UINT16_MAX, UINT16_C(58515),
      UINT16_C(39016), UINT16_C(44293), UINT16_C(64920),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(52772),
      UINT16_C(53769),      UINT16_MAX, UINT16_C(54340),      UINT16_MAX, UINT16_C(34451), UINT16_C(64202),      UINT16_MAX, UINT16_C(63711),
      UINT16_C(59126), UINT16_C(36774), UINT16_C(57827), UINT16_C(64923),      UINT16_MAX, UINT16_C(61257), UINT16_C(28453),      UINT16_MAX,
           UINT16_MAX, UINT16_C(33922),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(15659),      UINT16_MAX };

  static uint16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t
      rv,
      av = simde_svld1_u16(pg, &(a[i])),
      bv = simde_svld1_u16(pg, &(b[i]));

    rv = simde_svqadd_u16(av, bv);

    simde_svst1_u16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vu16(len, e, r);

  return 0;
#else
  uint16_t a[1024 / sizeof(int16_t)], b[1024 / sizeof(int16_t)], e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t av, bv, ev;

    av = simde_svld1_u16(pg, &(a[i]));
    bv = simde_svld1_u16(pg, &(b[i]));

    ev = simde_svqadd_u16(av, bv);

    simde_svst1_u16(pg, &(e[i]), ev);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const uint32_t a[] =
    { UINT32_C(1405621338), UINT32_C(1942880608), UINT32_C(2548466464), UINT32_C( 694783822), UINT32_C(2550343720), UINT32_C(3423213199), UINT32_C(3847073955), UINT32_C(2932945236),
      UINT32_C(2768345413), UINT32_C(3138965403), UINT32_C(2689793874), UINT32_C(3066674062), UINT32_C(1934544100), UINT32_C(2235521250), UINT32_C(1567329288), UINT32_C(  34290877),
      UINT32_C(1890061781), UINT32_C( 791462108), UINT32_C(1305444031), UINT32_C( 503552314), UINT32_C(1217483109), UINT32_C(2999832745), UINT32_C( 437205085), UINT32_C(1243421300),
      UINT32_C(  79349031), UINT32_C(1161029253), UINT32_C(2677146213), UINT32_C(  29202075), UINT32_C(2437500647), UINT32_C(2067994142), UINT32_C(3281408591), UINT32_C(2483925868),
      UINT32_C(4254648440), UINT32_C( 323144622), UINT32_C(1773327821), UINT32_C(1382707051), UINT32_C(3705910205), UINT32_C( 408364745), UINT32_C(3856461176), UINT32_C( 410642848),
      UINT32_C(1612059057), UINT32_C(2842908892), UINT32_C(2551326253), UINT32_C(1407941781), UINT32_C(4180659759), UINT32_C(1829865205), UINT32_C( 340979060), UINT32_C(2284702679),
      UINT32_C(3102229468), UINT32_C(3378666651), UINT32_C( 392262786), UINT32_C( 543837425), UINT32_C( 270113051), UINT32_C(2491231008), UINT32_C(4020817944), UINT32_C(2021184923),
      UINT32_C(3023069208), UINT32_C(1048416956), UINT32_C(4166442503), UINT32_C(1176027179), UINT32_C(2052469338), UINT32_C(1963905885), UINT32_C(1063630499), UINT32_C(2763513228),
      UINT32_C(4200130365), UINT32_C(2167985530), UINT32_C(3749285556), UINT32_C(2837811535), UINT32_C( 539196355), UINT32_C(4069929294), UINT32_C(1932655591), UINT32_C( 353954008),
      UINT32_C(1225748687), UINT32_C(4207560774), UINT32_C( 634995670), UINT32_C(2563702485), UINT32_C(3350851961), UINT32_C( 179916578), UINT32_C( 578677322), UINT32_C(2721551826),
      UINT32_C(1290487558), UINT32_C(1699133071), UINT32_C(3465224185), UINT32_C(2523355421), UINT32_C(1834819659), UINT32_C(3111589743), UINT32_C(3571184897), UINT32_C(2423657098),
      UINT32_C(3906756953), UINT32_C( 290333207), UINT32_C(1591728449), UINT32_C(2113160754), UINT32_C(3588969062), UINT32_C(1787716201), UINT32_C(3795741015), UINT32_C(3581064316),
      UINT32_C( 767446806), UINT32_C(3007188081), UINT32_C( 386997989), UINT32_C(3415541348), UINT32_C(3248521304), UINT32_C( 975908834), UINT32_C( 337406616), UINT32_C( 887787038),
      UINT32_C(1331865821), UINT32_C(2567086260), UINT32_C( 598741950), UINT32_C(1911440665), UINT32_C(2821885637), UINT32_C(1457675965), UINT32_C(3865771720), UINT32_C(1780176012),
      UINT32_C(2964946428), UINT32_C(3695819549), UINT32_C(3909089998), UINT32_C(  89779519), UINT32_C( 967675003), UINT32_C(2995752938), UINT32_C( 429455757), UINT32_C(1250145102),
      UINT32_C(1325087792), UINT32_C(3324658935), UINT32_C(2125343038), UINT32_C(2441283350), UINT32_C(2110402707), UINT32_C(1278171583), UINT32_C(2707802195), UINT32_C(2901141883),
      UINT32_C( 502982181), UINT32_C(1776493611), UINT32_C(1676120397), UINT32_C( 754215576), UINT32_C(1504296858), UINT32_C(1806031128), UINT32_C( 470551457), UINT32_C( 432601332),
      UINT32_C( 154583774), UINT32_C( 863181286), UINT32_C(1133927082), UINT32_C(1601145797), UINT32_C(1656297546), UINT32_C(2462998257), UINT32_C(1571805801), UINT32_C(2977396690),
      UINT32_C( 549104954), UINT32_C(1901342151), UINT32_C(1303702152), UINT32_C(3215729525), UINT32_C( 757228860), UINT32_C( 767619268), UINT32_C(2643161034), UINT32_C( 541983462),
      UINT32_C(1983973551), UINT32_C(3202913590), UINT32_C(4111178879), UINT32_C(4239701952), UINT32_C(3777615389), UINT32_C(2433673670), UINT32_C(1060018520), UINT32_C(1264549019),
      UINT32_C(3133251716), UINT32_C(3044583733), UINT32_C( 111838022), UINT32_C(1476550203), UINT32_C(4214827829), UINT32_C(1837909781), UINT32_C(2091694817), UINT32_C(3150384182),
      UINT32_C(3799353772), UINT32_C(2023222834), UINT32_C(2893955441), UINT32_C(3557064863), UINT32_C(3251649964), UINT32_C(1714314373), UINT32_C(1306712855), UINT32_C(2466818791),
      UINT32_C(1702198835), UINT32_C(3722316908), UINT32_C(3985267789), UINT32_C(2311163613), UINT32_C(1363841484), UINT32_C(  95910126), UINT32_C( 978491731), UINT32_C(1993235267),
      UINT32_C(1172063193), UINT32_C(2636298832), UINT32_C(4085951510), UINT32_C( 125586491), UINT32_C(3411592925), UINT32_C(2463108927), UINT32_C(3972866984), UINT32_C(1466080126),
      UINT32_C( 781991646), UINT32_C( 265076472) };
  static const uint32_t b[] =
    { UINT32_C(2589550163), UINT32_C(1210084781), UINT32_C(  20696473), UINT32_C(   6537460), UINT32_C(3072482081), UINT32_C(2757611898), UINT32_C(2393133833), UINT32_C( 969434854),
      UINT32_C(2043879884), UINT32_C( 683799695), UINT32_C(3039427777), UINT32_C(3736440253), UINT32_C(1653987304), UINT32_C(2986800041), UINT32_C( 742435398), UINT32_C(3714451729),
      UINT32_C(3109501226), UINT32_C(4007729197), UINT32_C(3533966101), UINT32_C(2159040920), UINT32_C(3672262193), UINT32_C(2139941177), UINT32_C(2762722707), UINT32_C(   8524246),
      UINT32_C(2025511243), UINT32_C( 107453425), UINT32_C(1054346150), UINT32_C(2512292196), UINT32_C( 141533647), UINT32_C( 495451274), UINT32_C(2680304329), UINT32_C(2409579588),
      UINT32_C( 235362589), UINT32_C(2601873141), UINT32_C(3738889593), UINT32_C(1165203574), UINT32_C(3276661561), UINT32_C(2833372383), UINT32_C(1262985991), UINT32_C(  81454823),
      UINT32_C( 890429760), UINT32_C(3385861968), UINT32_C(2343021077), UINT32_C(2094078787), UINT32_C(3711966974), UINT32_C(4203028979), UINT32_C(2873478340), UINT32_C(4071563186),
      UINT32_C(1344782592), UINT32_C(4263180521), UINT32_C(3851010466), UINT32_C(3663878876), UINT32_C(1823974009), UINT32_C(2271624387), UINT32_C(3140659976), UINT32_C(3400393162),
      UINT32_C(2333857186), UINT32_C(1871263181), UINT32_C(3545568246), UINT32_C(3870144365), UINT32_C( 475161945), UINT32_C(2862856353), UINT32_C( 761648483), UINT32_C(1492652726),
      UINT32_C(3034846183), UINT32_C(1042574664), UINT32_C(3994122624), UINT32_C(2312421168), UINT32_C(3315935012), UINT32_C(1131366623), UINT32_C(3547386909), UINT32_C(3458951399),
      UINT32_C(3280146299), UINT32_C(4244809597), UINT32_C(1357583136), UINT32_C(4141465810), UINT32_C(3334242023), UINT32_C(3809029062), UINT32_C(3887495680), UINT32_C(1588978146),
      UINT32_C(1847671025), UINT32_C(4285211615), UINT32_C( 156194615), UINT32_C(4261423127), UINT32_C(1824832678), UINT32_C(3880767207), UINT32_C( 718144840), UINT32_C(3632825575),
      UINT32_C(2621876924), UINT32_C(  77312461), UINT32_C( 521071368), UINT32_C(3122466323), UINT32_C(2972115658), UINT32_C(4170806960), UINT32_C(1646421883), UINT32_C(2822417387),
      UINT32_C( 574914645), UINT32_C( 975691570), UINT32_C(3730453962), UINT32_C( 228095811), UINT32_C( 163495513), UINT32_C(2952877876), UINT32_C(2853315775), UINT32_C( 609373647),
      UINT32_C(4282816205), UINT32_C(1077570934), UINT32_C(3843986594), UINT32_C(1710405131), UINT32_C(2842603893), UINT32_C(3344527368), UINT32_C(1668443284), UINT32_C(2257044665),
      UINT32_C(3515272539), UINT32_C(3708928059), UINT32_C(1606627412), UINT32_C(1539618278), UINT32_C(1862611814), UINT32_C( 926310051), UINT32_C(2207951050), UINT32_C(3356107117),
      UINT32_C( 697929966), UINT32_C(2751965776), UINT32_C(3238251226), UINT32_C(3860646015), UINT32_C(2656379387), UINT32_C(1255508864), UINT32_C(2714660660), UINT32_C(2120865936),
      UINT32_C(3098018408), UINT32_C(2270998444), UINT32_C(4165492601), UINT32_C( 584999975), UINT32_C( 113259398), UINT32_C(4082144703), UINT32_C(2492734980), UINT32_C(1578368502),
      UINT32_C(2870393855), UINT32_C(3811734122), UINT32_C(4191910610), UINT32_C(1696381663), UINT32_C(2892750061), UINT32_C(1990179698), UINT32_C(3490395098), UINT32_C( 791617072),
      UINT32_C(1138443737), UINT32_C(2317749688), UINT32_C(1736638856), UINT32_C(2848759739), UINT32_C(3998562172), UINT32_C(3429168626), UINT32_C(1503489832), UINT32_C(1720241293),
      UINT32_C(3383321361), UINT32_C(4183019377), UINT32_C(2355156945), UINT32_C(4063571062), UINT32_C(1440779107), UINT32_C(2820818304), UINT32_C(1107410868), UINT32_C(2628291211),
      UINT32_C(1583764205), UINT32_C(4065835297), UINT32_C( 125810576), UINT32_C(1190769891), UINT32_C(3214727743), UINT32_C(3546856991), UINT32_C( 135620989), UINT32_C(3785670387),
      UINT32_C( 826214928), UINT32_C(1411684292), UINT32_C( 844866382), UINT32_C(2541245783), UINT32_C(1314264111), UINT32_C(1327611602), UINT32_C( 458700584), UINT32_C( 100465909),
      UINT32_C(3392551942), UINT32_C( 555702995), UINT32_C(1431534333), UINT32_C(4276931791), UINT32_C(3008119520), UINT32_C( 688025089), UINT32_C(2588170917), UINT32_C(1553940822),
      UINT32_C(1344787837), UINT32_C( 762398256), UINT32_C(2424489408), UINT32_C(1905159825), UINT32_C(2988759985), UINT32_C(4007339849), UINT32_C(3616022401), UINT32_C(3711117152),
      UINT32_C( 741169916), UINT32_C(1633329056) };
  static const uint32_t e[] =
    { UINT32_C(3995171501), UINT32_C(3152965389), UINT32_C(2569162937), UINT32_C( 701321282),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(3902380090),
                UINT32_MAX, UINT32_C(3822765098),           UINT32_MAX,           UINT32_MAX, UINT32_C(3588531404),           UINT32_MAX, UINT32_C(2309764686), UINT32_C(3748742606),
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(2662593234),           UINT32_MAX,           UINT32_MAX, UINT32_C(3199927792), UINT32_C(1251945546),
      UINT32_C(2104860274), UINT32_C(1268482678), UINT32_C(3731492363), UINT32_C(2541494271), UINT32_C(2579034294), UINT32_C(2563445416),           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX, UINT32_C(2925017763),           UINT32_MAX, UINT32_C(2547910625),           UINT32_MAX, UINT32_C(3241737128),           UINT32_MAX, UINT32_C( 492097671),
      UINT32_C(2502488817),           UINT32_MAX,           UINT32_MAX, UINT32_C(3502020568),           UINT32_MAX,           UINT32_MAX, UINT32_C(3214457400),           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX, UINT32_C(4243273252), UINT32_C(4207716301), UINT32_C(2094087060),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX, UINT32_C(2919680137),           UINT32_MAX,           UINT32_MAX, UINT32_C(2527631283),           UINT32_MAX, UINT32_C(1825278982), UINT32_C(4256165954),
                UINT32_MAX, UINT32_C(3210560194),           UINT32_MAX,           UINT32_MAX, UINT32_C(3855131367),           UINT32_MAX,           UINT32_MAX, UINT32_C(3812905407),
                UINT32_MAX,           UINT32_MAX, UINT32_C(1992578806),           UINT32_MAX,           UINT32_MAX, UINT32_C(3988945640),           UINT32_MAX,           UINT32_MAX,
      UINT32_C(3138158583),           UINT32_MAX, UINT32_C(3621418800),           UINT32_MAX, UINT32_C(3659652337),           UINT32_MAX, UINT32_C(4289329737),           UINT32_MAX,
                UINT32_MAX, UINT32_C( 367645668), UINT32_C(2112799817),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
      UINT32_C(1342361451), UINT32_C(3982879651), UINT32_C(4117451951), UINT32_C(3643637159), UINT32_C(3412016817), UINT32_C(3928786710), UINT32_C(3190722391), UINT32_C(1497160685),
                UINT32_MAX, UINT32_C(3644657194),           UINT32_MAX, UINT32_C(3621845796),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(4037220677),
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(1629397797), UINT32_C(2830286817), UINT32_C(3922062989), UINT32_C(2637406807),           UINT32_MAX,
      UINT32_C(2023017758),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(2533680447),           UINT32_MAX,           UINT32_MAX,
      UINT32_C(3601000589), UINT32_C(4047492055),           UINT32_MAX, UINT32_C(1339215551), UINT32_C(1617556256),           UINT32_MAX, UINT32_C(2963286437), UINT32_C(2010969834),
      UINT32_C(3024977629),           UINT32_MAX,           UINT32_MAX, UINT32_C(3297527460),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(3769013762),
      UINT32_C(1687548691), UINT32_C(4219091839), UINT32_C(3040341008),           UINT32_MAX,           UINT32_MAX, UINT32_C(4196787894), UINT32_C(4146650866), UINT32_C(2262224755),
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(2167429388), UINT32_C(3892840230),
                UINT32_MAX,           UINT32_MAX, UINT32_C( 237648598), UINT32_C(2667320094),           UINT32_MAX,           UINT32_MAX, UINT32_C(2227315806),           UINT32_MAX,
                UINT32_MAX, UINT32_C(3434907126), UINT32_C(3738821823),           UINT32_MAX,           UINT32_MAX, UINT32_C(3041925975), UINT32_C(1765413439), UINT32_C(2567284700),
                UINT32_MAX, UINT32_C(4278019903),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C( 783935215), UINT32_C(3566662648), UINT32_C(3547176089),
      UINT32_C(2516851030), UINT32_C(3398697088),           UINT32_MAX, UINT32_C(2030746316),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
      UINT32_C(1523161562), UINT32_C(1898405528) };

  static uint32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t
      rv,
      av = simde_svld1_u32(pg, &(a[i])),
      bv = simde_svld1_u32(pg, &(b[i]));

    rv = simde_svqadd_u32(av, bv);

    simde_svst1_u32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vu32(len, e, r);

  return 0;
#else
  uint32_t a[1024 / sizeof(int32_t)], b[1024 / sizeof(int32_t)], e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t av, bv, ev;

    av = simde_svld1_u32(pg, &(a[i]));
    bv = simde_svld1_u32(pg, &(b[i]));

    ev = simde_svqadd_u32(av, bv);

    simde_svst1_u32(pg, &(e[i]), ev);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const uint64_t a[] =
    { UINT64_C(12557278677678002985), UINT64_C( 2009120930914405922), UINT64_C(16222904160205021999), UINT64_C(16197508010881563462),
      UINT64_C(16990169103298748078), UINT64_C(13958152310202875587), UINT64_C(10067642235795599477), UINT64_C(11872922341808724782),
      UINT64_C(12477655881774839157), UINT64_C( 6889378140607977799), UINT64_C(10141241449739906028), UINT64_C(10980679839311268808),
      UINT64_C(17619207285007328236), UINT64_C(12962038978844740248), UINT64_C(14862055816187615317), UINT64_C(15305184166841987500),
      UINT64_C(15254586097475927058), UINT64_C( 4571216202631119351), UINT64_C(11683238991426180432), UINT64_C(12871524816354586852),
      UINT64_C( 7935945588232768019), UINT64_C(   58437602309339301), UINT64_C(15675194075094893297), UINT64_C(16463830729628252713),
      UINT64_C(13076014669950610577), UINT64_C( 3566590593339794382), UINT64_C( 8693251644308641237), UINT64_C( 2400907404859493020),
      UINT64_C(12208592129930986920), UINT64_C(11219778137949254212), UINT64_C(  812065683585486205), UINT64_C(16935163267229714003),
      UINT64_C( 1500562686594002766), UINT64_C( 2388117967685090243), UINT64_C(16614679059538741529), UINT64_C( 2587266128435350457),
      UINT64_C( 6981741184507808767), UINT64_C(16348081807514237979), UINT64_C(13335437773309201815), UINT64_C(12250526198407748362),
      UINT64_C(10026525079069413160), UINT64_C(12936354757148807131), UINT64_C(18064200824101139191), UINT64_C( 3035105102002742729),
      UINT64_C(15214871449118415147), UINT64_C(10517030592811921443), UINT64_C( 9861820780319986161), UINT64_C(13676053906230916511),
      UINT64_C(17473824505323895475), UINT64_C(16652382837956343790), UINT64_C( 8880435308094071542), UINT64_C(  551945306260650330),
      UINT64_C( 7809578747458420897), UINT64_C(12611783994765513513), UINT64_C(14773955719772622512), UINT64_C(12337436400599704540),
      UINT64_C( 4993502550307891809), UINT64_C(18408580367790653712), UINT64_C( 6663519304531369273), UINT64_C(17612948752795709879),
      UINT64_C( 1445690685340813486), UINT64_C( 1779017371556344929), UINT64_C( 9660007688016510003), UINT64_C( 1005909511435230062),
      UINT64_C( 5428781389859768637), UINT64_C(13642436302140552028), UINT64_C(13996484318280554471), UINT64_C( 8613055373676610843),
      UINT64_C(11724575475035103105), UINT64_C( 4938531645815632194), UINT64_C(10763103353932872007), UINT64_C( 6588933221580218814),
      UINT64_C( 8925989567451245046), UINT64_C( 3805489928813919278), UINT64_C(14040022434180025289), UINT64_C( 8396166000679839567),
      UINT64_C(17728860599182510933), UINT64_C(16820469757609332812), UINT64_C(13538388292255104539), UINT64_C( 2296671748296646124),
      UINT64_C( 7814790029081678005), UINT64_C( 6921773439525516294), UINT64_C( 3204700640064322642), UINT64_C( 9144689648123469567),
      UINT64_C( 5877882832239170822), UINT64_C(11387780796585031779), UINT64_C(16874942633642592706), UINT64_C( 4790593314895414836),
      UINT64_C( 5317902223054239280), UINT64_C(10096783162264863539), UINT64_C( 9608921636439817091), UINT64_C(15565845113358912645),
      UINT64_C(11214561654653349236), UINT64_C( 1349455420684211300), UINT64_C(10271542007935552181), UINT64_C( 9180118398561947366),
      UINT64_C( 4595215176048425666), UINT64_C(15037562155365687567), UINT64_C(17296462541531525233), UINT64_C( 8141070714472913263),
      UINT64_C( 6825592604732347295), UINT64_C(13775574808491992641), UINT64_C(15264742458844054237), UINT64_C(15617155543734310300),
      UINT64_C(17782757477466658076), UINT64_C( 5710140407779870257), UINT64_C( 6248478104343705472), UINT64_C( 7598798860179211618),
      UINT64_C(  314582175491344305), UINT64_C(12548929818626076516), UINT64_C(14720096105745505336), UINT64_C(17655761200927533390),
      UINT64_C(15887214562535856804), UINT64_C(17817885813844933992), UINT64_C( 8028565880716252981), UINT64_C( 6148840319745774619),
      UINT64_C(15149905094252409323), UINT64_C(18444965931519701315), UINT64_C( 3392909353569673861), UINT64_C( 2153815952604471773),
      UINT64_C( 4094264599531007893), UINT64_C( 7960732364923615921), UINT64_C(18400065549503830038), UINT64_C( 7105679439489263948),
      UINT64_C(10181850253387439136) };
  static const uint64_t b[] =
    { UINT64_C( 7993391265753255813), UINT64_C( 1319703642428995267), UINT64_C(16262648485458627679), UINT64_C( 7809905749528509904),
      UINT64_C( 5736104385642844202), UINT64_C( 4989179035634261682), UINT64_C( 7273129316150872939), UINT64_C( 7145049013441453525),
      UINT64_C( 7240708141855274401), UINT64_C(15398876308403342216), UINT64_C( 9858612351893461976), UINT64_C(12703365989505744560),
      UINT64_C(10121656561586526818), UINT64_C(12386215997176678052), UINT64_C( 5351656908972869384), UINT64_C( 6297579247719647398),
      UINT64_C( 4677518844916023897), UINT64_C(11053577932626650088), UINT64_C(  855570016271367674), UINT64_C(16820141484085875233),
      UINT64_C(11691960054260881255), UINT64_C(13635990116309504274), UINT64_C( 5382137084638302273), UINT64_C(18283996109869183299),
      UINT64_C( 4972046777004852132), UINT64_C( 7157385434499669459), UINT64_C( 1884962979872089781), UINT64_C(17996572495820261420),
      UINT64_C(15431398322385436846), UINT64_C(16805677016701276085), UINT64_C( 3052015572784464744), UINT64_C(11728973166694713463),
      UINT64_C( 2974814970975559022), UINT64_C(16201481371745564090), UINT64_C(  334808495366905468), UINT64_C(12635012859765494467),
      UINT64_C( 4634318941955611826), UINT64_C(  465284229269180446), UINT64_C(15218830891766879651), UINT64_C( 5523914098209260728),
      UINT64_C( 5730201816779704510), UINT64_C( 6675841775927866132), UINT64_C(  347552657710065391), UINT64_C(18207109080885845190),
      UINT64_C(17937491951578259566), UINT64_C( 2057648240279933561), UINT64_C(11795753009912945506), UINT64_C(14088578316210778186),
      UINT64_C(  264675034753320143), UINT64_C(16243291432598979363), UINT64_C(13789812557962250207), UINT64_C(16215996683371635441),
      UINT64_C(16148853544765910415), UINT64_C(17646118279501074819), UINT64_C(11913727132568678946), UINT64_C(17898421372345687409),
      UINT64_C(13547441447691745380), UINT64_C(17332282169782841983), UINT64_C(13289803950305261588), UINT64_C(13104523090299935355),
      UINT64_C(11208290811115990422), UINT64_C(   56498318425934091), UINT64_C(12245346958969426160), UINT64_C( 6960429544206314385),
      UINT64_C( 5984644300161380183), UINT64_C(16568730891236097284), UINT64_C( 9158930684467591236), UINT64_C( 7594469826926651705),
      UINT64_C( 5910105135217677161), UINT64_C( 7422267687734161190), UINT64_C( 7374632487791173353), UINT64_C( 2025157154099018142),
      UINT64_C(  432857797861701217), UINT64_C( 6668461551174894080), UINT64_C(17929827761987544385), UINT64_C( 7715723938976251204),
      UINT64_C(12798697640608587960), UINT64_C( 2535071267067117406), UINT64_C( 3537688476915884742), UINT64_C( 4257937409400422561),
      UINT64_C(12357157531537322267), UINT64_C( 8806413811767333681), UINT64_C(14639709436367259148), UINT64_C(12119624812590486130),
      UINT64_C(12085394713901008063), UINT64_C(16966169061697926213), UINT64_C( 3579253120655691190), UINT64_C( 8185108369013941089),
      UINT64_C( 4861976641292536924), UINT64_C(15722821815157666665), UINT64_C( 9776302306096781244), UINT64_C( 9848543538989945739),
      UINT64_C(14509424133694696218), UINT64_C(  145596531608688391), UINT64_C(12828267313224335450), UINT64_C(12011272331993251581),
      UINT64_C(16640829069369150407), UINT64_C(11454930137658753456), UINT64_C(11218508036578375126), UINT64_C(  276254754001428387),
      UINT64_C( 6648750852010644351), UINT64_C( 4899435278253577756), UINT64_C(16571542670749539519), UINT64_C(12813279918755790225),
      UINT64_C( 3785087569806556286), UINT64_C(16383131327707535787), UINT64_C( 2438483212658384303), UINT64_C( 6114973320626498808),
      UINT64_C(17007569397578984635), UINT64_C(16061913446287252447), UINT64_C( 6678739718941649150), UINT64_C( 1782689180850494866),
      UINT64_C( 2485127462097992782), UINT64_C(16184262378868015502), UINT64_C(11814099679613708853), UINT64_C( 3184266887979367355),
      UINT64_C(11270881551937379334), UINT64_C(15094926429992358072), UINT64_C(13984061703972383069), UINT64_C(17069498998707592665),
      UINT64_C(10291182365882818086), UINT64_C( 8907456090189933103), UINT64_C( 4564110590878484365), UINT64_C( 7055690617933148183),
      UINT64_C(17211747046769696632) };
  static const uint64_t e[] =
    {                     UINT64_MAX, UINT64_C( 3328824573343401189),                     UINT64_MAX,                     UINT64_MAX,
                          UINT64_MAX,                     UINT64_MAX, UINT64_C(17340771551946472416),                     UINT64_MAX,
                          UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,
                          UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,
                          UINT64_MAX, UINT64_C(15624794135257769439), UINT64_C(12538809007697548106),                     UINT64_MAX,
                          UINT64_MAX, UINT64_C(13694427718618843575),                     UINT64_MAX,                     UINT64_MAX,
      UINT64_C(18048061446955462709), UINT64_C(10723976027839463841), UINT64_C(10578214624180731018),                     UINT64_MAX,
                          UINT64_MAX,                     UINT64_MAX, UINT64_C( 3864081256369950949),                     UINT64_MAX,
      UINT64_C( 4475377657569561788),                     UINT64_MAX, UINT64_C(16949487554905646997), UINT64_C(15222278988200844924),
      UINT64_C(11616060126463420593), UINT64_C(16813366036783418425),                     UINT64_MAX, UINT64_C(17774440296617009090),
      UINT64_C(15756726895849117670),                     UINT64_MAX, UINT64_C(18411753481811204582),                     UINT64_MAX,
                          UINT64_MAX, UINT64_C(12574678833091855004),                     UINT64_MAX,                     UINT64_MAX,
      UINT64_C(17738499540077215618),                     UINT64_MAX,                     UINT64_MAX, UINT64_C(16767941989632285771),
                          UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,
                          UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,
      UINT64_C(12653981496456803908), UINT64_C( 1835515689982279020),                     UINT64_MAX, UINT64_C( 7966339055641544447),
      UINT64_C(11413425690021148820),                     UINT64_MAX,                     UINT64_MAX, UINT64_C(16207525200603262548),
      UINT64_C(17634680610252780266), UINT64_C(12360799333549793384), UINT64_C(18137735841724045360), UINT64_C( 8614090375679236956),
      UINT64_C( 9358847365312946263), UINT64_C(10473951479988813358),                     UINT64_MAX, UINT64_C(16111889939656090771),
                          UINT64_MAX,                     UINT64_MAX, UINT64_C(17076076769170989281), UINT64_C( 6554609157697068685),
                          UINT64_MAX, UINT64_C(15728187251292849975), UINT64_C(17844410076431581790),                     UINT64_MAX,
      UINT64_C(17963277546140178885),                     UINT64_MAX,                     UINT64_MAX, UINT64_C(12975701683909355925),
      UINT64_C(10179878864346776204),                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,
                          UINT64_MAX, UINT64_C( 1495051952292899691),                     UINT64_MAX,                     UINT64_MAX,
                          UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX, UINT64_C( 8417325468474341650),
      UINT64_C(13474343456742991646),                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,
                          UINT64_MAX,                     UINT64_MAX, UINT64_C( 8686961317002089775), UINT64_C(13713772180805710426),
      UINT64_C(17322151573070328940),                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,
      UINT64_C(18372342024633849586),                     UINT64_MAX,                     UINT64_MAX, UINT64_C( 9333107207725141974),
                          UINT64_MAX,                     UINT64_MAX, UINT64_C(17376971057542056930),                     UINT64_MAX,
      UINT64_C(14385446965413825979), UINT64_C(16868188455113549024),                     UINT64_MAX, UINT64_C(14161370057422412131),
                          UINT64_MAX };

  static uint64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t
      rv,
      av = simde_svld1_u64(pg, &(a[i])),
      bv = simde_svld1_u64(pg, &(b[i]));

    rv = simde_svqadd_u64(av, bv);

    simde_svst1_u64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vu64(len, e, r);

  return 0;
#else
  uint64_t a[1024 / sizeof(int64_t)], b[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t av, bv, ev;

    av = simde_svld1_u64(pg, &(a[i]));
    bv = simde_svld1_u64(pg, &(b[i]));

    ev = simde_svqadd_u64(av, bv);

    simde_svst1_u64(pg, &(e[i]), ev);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t a[] =
    { -INT8_C(  19), -INT8_C(  20),  INT8_C(  51),  INT8_C(   8),  INT8_C(  16),  INT8_C(  86),  INT8_C( 119), -INT8_C(  75),
           INT8_MIN, -INT8_C( 126), -INT8_C( 106),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 112), -INT8_C(  68),  INT8_C(  81),  INT8_C(  33),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 117),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  56),  INT8_C(  10),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   8),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  48),  INT8_C(  17), -INT8_C(  45),  INT8_C(  20),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 109),  INT8_C(  50), -INT8_C( 109), -INT8_C(  26),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  43), -INT8_C(  48), -INT8_C(  25),  INT8_C(  35),
       INT8_C(  10),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  99),  INT8_C(  32), -INT8_C(  28),  INT8_C(  96),
       INT8_C(  10),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  56),      INT8_MAX, -INT8_C( 106),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   8),  INT8_C(   5),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  10),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  32),  INT8_C(  11),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  80),  INT8_C(  11),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  32),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN, -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  65),  INT8_C(  57), -INT8_C(  36), -INT8_C( 120),
      -INT8_C(  48),  INT8_C(  11),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  32), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  18), -INT8_C(   9),  INT8_C(  50), -INT8_C( 120), -INT8_C(  10),  INT8_C(  37),  INT8_C(  25), -INT8_C(  25),
      -INT8_C(  10), -INT8_C(  94), -INT8_C(  56), -INT8_C(  75), -INT8_C(  36), -INT8_C(  92),  INT8_C(  61),  INT8_C( 123),
       INT8_C(  90),  INT8_C(  57),  INT8_C(  28), -INT8_C(  21),  INT8_C(  84), -INT8_C(  25), -INT8_C(  88),  INT8_C(   7),
      -INT8_C(  95),  INT8_C(   0), -INT8_C(  77),  INT8_C( 111),  INT8_C( 126),  INT8_C(  50),  INT8_C(  97),  INT8_C( 108),
       INT8_C(  41), -INT8_C( 109), -INT8_C(  12),  INT8_C(  31), -INT8_C(  71),  INT8_C(  14),  INT8_C(   6), -INT8_C(  81),
      -INT8_C(  37),  INT8_C(  90),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  36),  INT8_C(  35), -INT8_C(  72),  INT8_C(  48),  INT8_C(  10),  INT8_C(  97),  INT8_C(  55), -INT8_C(  85),
       INT8_C(  97), -INT8_C(  22),  INT8_C(  27), -INT8_C(  32),  INT8_C(  28),  INT8_C( 124),  INT8_C(  76),  INT8_C(  69),
       INT8_C(  16),  INT8_C(  65),  INT8_C( 100), -INT8_C(  55),  INT8_C(  79),  INT8_C( 106),  INT8_C( 120), -INT8_C(   1),
       INT8_C(  57), -INT8_C(  35), -INT8_C( 116), -INT8_C(  84),      INT8_MIN, -INT8_C( 109),  INT8_C( 121),  INT8_C(  92),
      -INT8_C(  73),  INT8_C(  49), -INT8_C( 116), -INT8_C(  63), -INT8_C( 110), -INT8_C(  61),  INT8_C( 109), -INT8_C(  12),
      -INT8_C(  82), -INT8_C( 120), -INT8_C(  44), -INT8_C(  54),  INT8_C(   4),  INT8_C(  32),  INT8_C(  16),  INT8_C(  20),
       INT8_C(  97),  INT8_C( 116), -INT8_C(  35), -INT8_C(  80), -INT8_C(  33),  INT8_C(  86), -INT8_C(  80),  INT8_C(  24),
       INT8_C(  80),  INT8_C(  11),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  80),  INT8_C(  11),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  32),  INT8_C(  11),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  48), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),      INT8_MIN, -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(  64), -INT8_C(  55), -INT8_C( 120),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_MIN, -INT8_C(  11), -INT8_C( 102),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 127),  INT8_C(  95), -INT8_C(  71),  INT8_C( 107),  INT8_C(  70),  INT8_C(  15), -INT8_C(  74), -INT8_C(  94),
       INT8_C(  66), -INT8_C(  79), -INT8_C(  35), -INT8_C(  52),  INT8_C(  93),  INT8_C(  48), -INT8_C( 119),  INT8_C(  68),
       INT8_C(  71), -INT8_C(   7), -INT8_C(   5), -INT8_C( 101),  INT8_C( 121),  INT8_C(  57),  INT8_C(  94), -INT8_C( 107),
      -INT8_C(  66),  INT8_C(  33),  INT8_C(  15), -INT8_C(   7), -INT8_C(  38), -INT8_C( 105),  INT8_C( 112),  INT8_C(  91),
      -INT8_C(  10),  INT8_C(  41), -INT8_C(  58),  INT8_C(  60),  INT8_C(  56),  INT8_C( 124), -INT8_C(  33),  INT8_C( 123),
       INT8_C(  46), -INT8_C(  68),  INT8_C(  71), -INT8_C( 117), -INT8_C(  19), -INT8_C(  48), -INT8_C(  49),  INT8_C(  52),
      -INT8_C(  55), -INT8_C(  53), -INT8_C(  48),  INT8_C(  67),  INT8_C(   4),  INT8_C(  46), -INT8_C(  40), -INT8_C(  62),
       INT8_C(  79), -INT8_C(  25), -INT8_C(  69),  INT8_C(  41),  INT8_C( 126),  INT8_C(  44), -INT8_C( 123),  INT8_C( 116),
       INT8_C(  85),  INT8_C(  75), -INT8_C(  79), -INT8_C( 114), -INT8_C(  56), -INT8_C( 112),  INT8_C(   9), -INT8_C(  10),
       INT8_C(  76),  INT8_C(  80), -INT8_C( 127),  INT8_C(  57),  INT8_C(  32),  INT8_C(  80),  INT8_C( 110), -INT8_C(  23),
       INT8_C(  27),  INT8_C(  62),  INT8_C(  44),  INT8_C(  31),  INT8_C( 108),  INT8_C(   4), -INT8_C(  30), -INT8_C(  69),
      -INT8_C(  20), -INT8_C(  99), -INT8_C(  27),  INT8_C( 106), -INT8_C(  55),  INT8_C( 106), -INT8_C(  33),  INT8_C(  31),
      -INT8_C(  75), -INT8_C( 112), -INT8_C(  83),  INT8_C( 125),  INT8_C(  32), -INT8_C(  74),  INT8_C( 115),  INT8_C( 108),
       INT8_C(   6), -INT8_C(  12), -INT8_C(  90),  INT8_C(  38),  INT8_C(  69),  INT8_C(  20),  INT8_C(  15),  INT8_C(  96),
       INT8_C(  82),  INT8_C(  60),      INT8_MIN, -INT8_C(  66),  INT8_C(  64),  INT8_C(  98),  INT8_C( 121),  INT8_C(  44),
      -INT8_C(   1),  INT8_C(  94), -INT8_C( 105), -INT8_C(  55), -INT8_C(  56),  INT8_C( 118), -INT8_C(  24),  INT8_C( 126),
       INT8_C(   6), -INT8_C( 107), -INT8_C(   5),  INT8_C(  38),  INT8_C(  75),  INT8_C( 111), -INT8_C( 110),  INT8_C(  81),
       INT8_C(  99),  INT8_C(  56),  INT8_C( 119), -INT8_C(  88),  INT8_C(  76), -INT8_C( 122),  INT8_C(   9), -INT8_C(  98),
      -INT8_C(  62), -INT8_C( 119),  INT8_C(  92),  INT8_C(   3), -INT8_C(  21), -INT8_C(  42),  INT8_C(  47), -INT8_C(  22),
       INT8_C(  52), -INT8_C(  58), -INT8_C(  77), -INT8_C(   3),  INT8_C(  60), -INT8_C( 101),  INT8_C( 123),  INT8_C(  66),
       INT8_C(  48),  INT8_C( 118),  INT8_C( 104),  INT8_C( 123), -INT8_C(  27), -INT8_C(   5), -INT8_C(  52),  INT8_C(  73),
       INT8_C(  51),  INT8_C(  67), -INT8_C(  15),      INT8_MIN, -INT8_C(  54), -INT8_C(   6),  INT8_C(  30), -INT8_C( 116),
      -INT8_C( 125),  INT8_C( 123), -INT8_C( 113),  INT8_C( 110),  INT8_C(  81), -INT8_C(  65),  INT8_C(  89), -INT8_C( 123),
      -INT8_C( 123),  INT8_C(  12), -INT8_C( 126), -INT8_C(  62), -INT8_C(  88), -INT8_C(   3),  INT8_C(   4), -INT8_C(  40),
       INT8_C( 116),  INT8_C( 109),  INT8_C(  84),  INT8_C(  89),  INT8_C( 104),  INT8_C(  32), -INT8_C(  94), -INT8_C( 101),
       INT8_C( 100), -INT8_C( 108),  INT8_C(  27),  INT8_C(  46), -INT8_C( 114),  INT8_C(  58), -INT8_C(  70),  INT8_C(  18),
      -INT8_C(  75),  INT8_C(  74),      INT8_MIN,  INT8_C(   6),  INT8_C(   9), -INT8_C(  39), -INT8_C( 117), -INT8_C( 114),
      -INT8_C(  26),  INT8_C(  14),  INT8_C(  80), -INT8_C( 114),  INT8_C(  11),  INT8_C(  85),  INT8_C( 102),      INT8_MAX,
      -INT8_C(  62), -INT8_C(  70), -INT8_C(  39),  INT8_C(  42), -INT8_C(  37),  INT8_C( 123), -INT8_C(  59),  INT8_C(  63),
       INT8_C(  15), -INT8_C(  31),  INT8_C( 109), -INT8_C(  98),  INT8_C(  27),  INT8_C(  39), -INT8_C(  80), -INT8_C(  48),
       INT8_C( 113),  INT8_C(  48), -INT8_C(  42),  INT8_C( 122),  INT8_C(  10),  INT8_C(  97),  INT8_C(   9), -INT8_C(  16),
       INT8_C( 111),  INT8_C(  89),  INT8_C( 126),  INT8_C( 123), -INT8_C(  82), -INT8_C(  28), -INT8_C(   6),  INT8_C( 112),
      -INT8_C(  97), -INT8_C(  45), -INT8_C( 102),  INT8_C( 122),  INT8_C(  79),  INT8_C(  96), -INT8_C(  71),  INT8_C(  94),
       INT8_C(  65),  INT8_C(  38), -INT8_C(   4),  INT8_C(  92),  INT8_C(  77), -INT8_C(  84),  INT8_C(  44), -INT8_C(  65),
      -INT8_C(  35),  INT8_C(   2),  INT8_C(  57), -INT8_C(  25),  INT8_C(  99),  INT8_C(  66), -INT8_C(  41), -INT8_C(  45),
      -INT8_C( 100),  INT8_C(  85),  INT8_C(  78),  INT8_C(  74),  INT8_C(  57),  INT8_C(  72), -INT8_C(  69), -INT8_C(  40),
       INT8_C(  28),  INT8_C(  85),  INT8_C(  82),  INT8_C( 107), -INT8_C(  75),  INT8_C(  11), -INT8_C(  55), -INT8_C(  10),
       INT8_C(  49), -INT8_C(  58),  INT8_C(  82),      INT8_MAX,  INT8_C( 114),  INT8_C( 126),  INT8_C(  62),  INT8_C(  79),
           INT8_MIN,  INT8_C( 119),  INT8_C(  54), -INT8_C(  28), -INT8_C(  70),  INT8_C(  13), -INT8_C(  73),  INT8_C(  86),
       INT8_C(  98),  INT8_C(   5), -INT8_C(  96), -INT8_C( 100),  INT8_C(  77),  INT8_C(  91),  INT8_C( 116),  INT8_C( 105),
      -INT8_C(  79), -INT8_C(  57), -INT8_C(  44),  INT8_C( 102), -INT8_C(  46), -INT8_C(  98),  INT8_C(  93),  INT8_C(   4),
       INT8_C( 100), -INT8_C(  81), -INT8_C( 125), -INT8_C(  42),  INT8_C(  46), -INT8_C(  63),  INT8_C(  38), -INT8_C(  82),
       INT8_C(  56),  INT8_C(  92), -INT8_C( 110), -INT8_C(  14),  INT8_C( 106),  INT8_C(  73),  INT8_C(  72), -INT8_C(  52),
       INT8_C(  78), -INT8_C(  23),  INT8_C( 104), -INT8_C( 100),  INT8_C(  68), -INT8_C(  35),  INT8_C(   5), -INT8_C(  11),
      -INT8_C(  92), -INT8_C(  38),  INT8_C(  92),  INT8_C( 118),  INT8_C( 120), -INT8_C(  71),  INT8_C( 122), -INT8_C(  36),
       INT8_C( 104), -INT8_C(   3), -INT8_C(  78), -INT8_C( 106), -INT8_C(  66), -INT8_C(  40),  INT8_C(  69), -INT8_C(   9),
       INT8_C(  53), -INT8_C(  41), -INT8_C(  23), -INT8_C(  97),  INT8_C(  33),  INT8_C(  50),  INT8_C( 107),  INT8_C( 111),
       INT8_C(  27), -INT8_C(  44),  INT8_C(  11),  INT8_C(  95), -INT8_C(  79),  INT8_C(  17),  INT8_C(  85),  INT8_C(  85),
      -INT8_C(  21), -INT8_C(  79), -INT8_C(  53),  INT8_C(  99),  INT8_C( 106),  INT8_C(  70),  INT8_C(  63), -INT8_C(  46),
       INT8_C(  67), -INT8_C(  15),  INT8_C( 105),  INT8_C(   2), -INT8_C(  54), -INT8_C(  82), -INT8_C(   7), -INT8_C(   1),
      -INT8_C( 123), -INT8_C(  30), -INT8_C(  98), -INT8_C(  90),  INT8_C(  20),  INT8_C(   9),  INT8_C(  22),  INT8_C(  47),
      -INT8_C(  35),  INT8_C(  33), -INT8_C( 113), -INT8_C( 114),  INT8_C(  50), -INT8_C(  28), -INT8_C(  29),  INT8_C(  29),
      -INT8_C( 107), -INT8_C(  81),      INT8_MIN, -INT8_C(   1), -INT8_C(  11), -INT8_C(  65), -INT8_C(  47),  INT8_C(  56),
      -INT8_C(  79),  INT8_C(  58),  INT8_C(  58),  INT8_C( 123), -INT8_C(  24),  INT8_C(  51),  INT8_C( 122),  INT8_C( 110),
       INT8_C(  22),  INT8_C(  24),  INT8_C(  20),  INT8_C(  42),  INT8_C(  33),  INT8_C(  42),  INT8_C(  90), -INT8_C(   1),
       INT8_C(  76), -INT8_C(  23), -INT8_C( 115),  INT8_C( 126), -INT8_C(  51),  INT8_C( 113), -INT8_C( 100),  INT8_C(  98),
       INT8_C(  32),  INT8_C(  28),  INT8_C(  97),  INT8_C(  21), -INT8_C(  36),  INT8_C(  50),  INT8_C(  77), -INT8_C( 115),
       INT8_C( 109), -INT8_C( 120),  INT8_C(   8),  INT8_C(  85), -INT8_C(  69), -INT8_C( 126), -INT8_C(  61) };
  static const int8_t b =  INT8_C( 119);
  static const int8_t e[] =
    {  INT8_C( 100),  INT8_C(  99),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  44),
      -INT8_C(   9), -INT8_C(   7),  INT8_C(  13),  INT8_C( 119),      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
       INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
       INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C(   7),  INT8_C(  51),      INT8_MAX,      INT8_MAX,
       INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
           INT8_MAX,      INT8_MAX, -INT8_C(   9),  INT8_C( 119),      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
           INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
       INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
       INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C(  71),      INT8_MAX,  INT8_C(  74),      INT8_MAX,
       INT8_C( 118),  INT8_C( 118),  INT8_C( 118),  INT8_C( 118),  INT8_C( 118),  INT8_C( 118),  INT8_C( 118),  INT8_C( 118),
       INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C(  10),      INT8_MAX,  INT8_C(  10),  INT8_C(  93),
       INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C(  76),  INT8_C(  71),  INT8_C(  94),      INT8_MAX,
           INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C(  20),      INT8_MAX,  INT8_C(  91),      INT8_MAX,
           INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
       INT8_C(  63),      INT8_MAX,  INT8_C(  13),  INT8_C( 119),      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
       INT8_C( 111),  INT8_C( 124), -INT8_C(   9),  INT8_C( 119),      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
           INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 121),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
           INT8_MAX,      INT8_MAX, -INT8_C(   9),  INT8_C( 119),      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
       INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
           INT8_MAX,      INT8_MAX, -INT8_C(   9),  INT8_C( 119),      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
           INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
       INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119), -INT8_C(   9),  INT8_C( 118),  INT8_C( 118),  INT8_C( 118),
       INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C(  54),      INT8_MAX,  INT8_C(  83), -INT8_C(   1),
       INT8_C(  71),      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
       INT8_C(  87),  INT8_C( 118),  INT8_C( 118),  INT8_C( 118),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
       INT8_C( 101),  INT8_C( 110),      INT8_MAX, -INT8_C(   1),  INT8_C( 109),      INT8_MAX,      INT8_MAX,  INT8_C(  94),
       INT8_C( 109),  INT8_C(  25),  INT8_C(  63),  INT8_C(  44),  INT8_C(  83),  INT8_C(  27),      INT8_MAX,      INT8_MAX,
           INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  98),      INT8_MAX,  INT8_C(  94),  INT8_C(  31),  INT8_C( 126),
       INT8_C(  24),  INT8_C( 119),  INT8_C(  42),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
           INT8_MAX,  INT8_C(  10),  INT8_C( 107),      INT8_MAX,  INT8_C(  48),      INT8_MAX,  INT8_C( 125),  INT8_C(  38),
       INT8_C(  82),      INT8_MAX,      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
       INT8_C(  83),      INT8_MAX,  INT8_C(  47),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  34),
           INT8_MAX,  INT8_C(  97),      INT8_MAX,  INT8_C(  87),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
           INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  64),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C( 118),
           INT8_MAX,  INT8_C(  84),  INT8_C(   3),  INT8_C(  35), -INT8_C(   9),  INT8_C(  10),      INT8_MAX,      INT8_MAX,
       INT8_C(  46),      INT8_MAX,  INT8_C(   3),  INT8_C(  56),  INT8_C(   9),  INT8_C(  58),      INT8_MAX,  INT8_C( 107),
       INT8_C(  37), -INT8_C(   1),  INT8_C(  75),  INT8_C(  65),  INT8_C( 123),      INT8_MAX,      INT8_MAX,      INT8_MAX,
           INT8_MAX,      INT8_MAX,  INT8_C(  84),  INT8_C(  39),  INT8_C(  86),      INT8_MAX,  INT8_C(  39),      INT8_MAX,
           INT8_MAX,      INT8_MAX, -INT8_C(   9),  INT8_C( 119),      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
           INT8_MAX,      INT8_MAX, -INT8_C(   9),  INT8_C( 119),      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
           INT8_MAX,      INT8_MAX, -INT8_C(   9),  INT8_C( 119),      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
       INT8_C(  71),  INT8_C( 118),  INT8_C( 118),  INT8_C( 118), -INT8_C(   9),  INT8_C( 118),  INT8_C( 118),  INT8_C( 118),
           INT8_MAX,  INT8_C(  64), -INT8_C(   1),  INT8_C( 119),      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
      -INT8_C(   9),  INT8_C( 108),  INT8_C(  17),  INT8_C( 119),      INT8_MAX,  INT8_C( 119),  INT8_C( 119),  INT8_C( 119),
      -INT8_C(   8),      INT8_MAX,  INT8_C(  48),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  45),  INT8_C(  25),
           INT8_MAX,  INT8_C(  40),  INT8_C(  84),  INT8_C(  67),      INT8_MAX,      INT8_MAX,  INT8_C(   0),      INT8_MAX,
           INT8_MAX,  INT8_C( 112),  INT8_C( 114),  INT8_C(  18),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  12),
       INT8_C(  53),      INT8_MAX,      INT8_MAX,  INT8_C( 112),  INT8_C(  81),  INT8_C(  14),      INT8_MAX,      INT8_MAX,
       INT8_C( 109),      INT8_MAX,  INT8_C(  61),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  86),      INT8_MAX,
           INT8_MAX,  INT8_C(  51),      INT8_MAX,  INT8_C(   2),  INT8_C( 100),  INT8_C(  71),  INT8_C(  70),      INT8_MAX,
       INT8_C(  64),  INT8_C(  66),  INT8_C(  71),      INT8_MAX,  INT8_C( 123),      INT8_MAX,  INT8_C(  79),  INT8_C(  57),
           INT8_MAX,  INT8_C(  94),  INT8_C(  50),      INT8_MAX,      INT8_MAX,      INT8_MAX, -INT8_C(   4),      INT8_MAX,
           INT8_MAX,      INT8_MAX,  INT8_C(  40),  INT8_C(   5),  INT8_C(  63),  INT8_C(   7),      INT8_MAX,  INT8_C( 109),
           INT8_MAX,      INT8_MAX, -INT8_C(   8),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  96),
           INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C( 123),  INT8_C(  89),  INT8_C(  50),
       INT8_C(  99),  INT8_C(  20),  INT8_C(  92),      INT8_MAX,  INT8_C(  64),      INT8_MAX,  INT8_C(  86),      INT8_MAX,
       INT8_C(  44),  INT8_C(   7),  INT8_C(  36),      INT8_MAX,      INT8_MAX,  INT8_C(  45),      INT8_MAX,      INT8_MAX,
       INT8_C( 125),  INT8_C( 107),  INT8_C(  29),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
           INT8_MAX,      INT8_MAX, -INT8_C(   9),  INT8_C(  53),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
       INT8_C( 118),      INT8_MAX,  INT8_C(  14),  INT8_C(  64),  INT8_C(  63),      INT8_MAX,  INT8_C(  95),      INT8_MAX,
       INT8_C( 125),  INT8_C(  12),  INT8_C( 114),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(   9),      INT8_MAX,
           INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  31),      INT8_MAX, -INT8_C(   3),      INT8_MAX,  INT8_C(  21),
       INT8_C(  57),  INT8_C(   0),      INT8_MAX,  INT8_C( 122),  INT8_C(  98),  INT8_C(  77),      INT8_MAX,  INT8_C(  97),
           INT8_MAX,  INT8_C(  61),  INT8_C(  42),  INT8_C( 116),      INT8_MAX,  INT8_C(  18),      INT8_MAX,      INT8_MAX,
           INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  92),  INT8_C( 114),  INT8_C(  67),      INT8_MAX,
           INT8_MAX,      INT8_MAX,  INT8_C( 104), -INT8_C(   9),  INT8_C(  65),  INT8_C( 113),      INT8_MAX,  INT8_C(   3),
      -INT8_C(   6),      INT8_MAX,  INT8_C(   6),      INT8_MAX,      INT8_MAX,  INT8_C(  54),      INT8_MAX, -INT8_C(   4),
      -INT8_C(   4),      INT8_MAX, -INT8_C(   7),  INT8_C(  57),  INT8_C(  31),  INT8_C( 116),  INT8_C( 123),  INT8_C(  79),
           INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  25),  INT8_C(  18),
           INT8_MAX,  INT8_C(  11),      INT8_MAX,      INT8_MAX,  INT8_C(   5),      INT8_MAX,  INT8_C(  49),      INT8_MAX,
       INT8_C(  44),      INT8_MAX, -INT8_C(   9),  INT8_C( 125),      INT8_MAX,  INT8_C(  80),  INT8_C(   2),  INT8_C(   5),
       INT8_C(  93),      INT8_MAX,      INT8_MAX,  INT8_C(   5),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
       INT8_C(  57),  INT8_C(  49),  INT8_C(  80),      INT8_MAX,  INT8_C(  82),      INT8_MAX,  INT8_C(  60),      INT8_MAX,
           INT8_MAX,  INT8_C(  88),      INT8_MAX,  INT8_C(  21),      INT8_MAX,      INT8_MAX,  INT8_C(  39),  INT8_C(  71),
           INT8_MAX,      INT8_MAX,  INT8_C(  77),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C( 103),
           INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  37),  INT8_C(  91),  INT8_C( 113),      INT8_MAX,
       INT8_C(  22),  INT8_C(  74),  INT8_C(  17),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  48),      INT8_MAX,
           INT8_MAX,      INT8_MAX,  INT8_C( 115),      INT8_MAX,      INT8_MAX,  INT8_C(  35),      INT8_MAX,  INT8_C(  54),
       INT8_C(  84),  INT8_C( 121),      INT8_MAX,  INT8_C(  94),      INT8_MAX,      INT8_MAX,  INT8_C(  78),  INT8_C(  74),
       INT8_C(  19),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  50),  INT8_C(  79),
           INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  44),      INT8_MAX,  INT8_C(  64),  INT8_C( 109),
           INT8_MAX,  INT8_C(  61),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
      -INT8_C(   9),      INT8_MAX,      INT8_MAX,  INT8_C(  91),  INT8_C(  49),      INT8_MAX,  INT8_C(  46),      INT8_MAX,
           INT8_MAX,  INT8_C( 124),  INT8_C(  23),  INT8_C(  19),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
       INT8_C(  40),  INT8_C(  62),  INT8_C(  75),      INT8_MAX,  INT8_C(  73),  INT8_C(  21),      INT8_MAX,  INT8_C( 123),
           INT8_MAX,  INT8_C(  38), -INT8_C(   6),  INT8_C(  77),      INT8_MAX,  INT8_C(  56),      INT8_MAX,  INT8_C(  37),
           INT8_MAX,      INT8_MAX,  INT8_C(   9),  INT8_C( 105),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  67),
           INT8_MAX,  INT8_C(  96),      INT8_MAX,  INT8_C(  19),      INT8_MAX,  INT8_C(  84),  INT8_C( 124),  INT8_C( 108),
       INT8_C(  27),  INT8_C(  81),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  48),      INT8_MAX,  INT8_C(  83),
           INT8_MAX,  INT8_C( 116),  INT8_C(  41),  INT8_C(  13),  INT8_C(  53),  INT8_C(  79),      INT8_MAX,  INT8_C( 110),
           INT8_MAX,  INT8_C(  78),  INT8_C(  96),  INT8_C(  22),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
           INT8_MAX,  INT8_C(  75),      INT8_MAX,      INT8_MAX,  INT8_C(  40),      INT8_MAX,      INT8_MAX,      INT8_MAX,
       INT8_C(  98),  INT8_C(  40),  INT8_C(  66),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  73),
           INT8_MAX,  INT8_C( 104),      INT8_MAX,  INT8_C( 121),  INT8_C(  65),  INT8_C(  37),  INT8_C( 112),  INT8_C( 118),
      -INT8_C(   4),  INT8_C(  89),  INT8_C(  21),  INT8_C(  29),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
       INT8_C(  84),      INT8_MAX,  INT8_C(   6),  INT8_C(   5),      INT8_MAX,  INT8_C(  91),  INT8_C(  90),      INT8_MAX,
       INT8_C(  12),  INT8_C(  38), -INT8_C(   9),  INT8_C( 118),  INT8_C( 108),  INT8_C(  54),  INT8_C(  72),      INT8_MAX,
       INT8_C(  40),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  95),      INT8_MAX,      INT8_MAX,      INT8_MAX,
           INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C( 118),
           INT8_MAX,  INT8_C(  96),  INT8_C(   4),      INT8_MAX,  INT8_C(  68),      INT8_MAX,  INT8_C(  19),      INT8_MAX,
           INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  83),      INT8_MAX,      INT8_MAX,  INT8_C(   4),
           INT8_MAX, -INT8_C(   1),      INT8_MAX,      INT8_MAX,  INT8_C(  50), -INT8_C(   7),  INT8_C(  58) };

  static int8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t
      rv,
      av = simde_svld1_s8(pg, &(a[i]));

    rv = simde_svqadd_n_s8(av, b);

    simde_svst1_s8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vi8(len, e, r);

  return 0;
#else
  int8_t a[1024], b, e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t av, ev;

    av = simde_svld1_s8(pg, &(a[i]));

    ev = simde_svqadd_n_s8(av, b);

    simde_svst1_s8(pg, &(e[i]), ev);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i8(1, b);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t a[] =
    { -INT16_C(  1733),  INT16_C( 30978), -INT16_C(  7950), -INT16_C(  9529), -INT16_C(  8990), -INT16_C(  4476),  INT16_C(  9276),  INT16_C( 25617),
       INT16_C( 20223), -INT16_C( 10347), -INT16_C( 31746), -INT16_C(  4772), -INT16_C(  4545), -INT16_C( 15555),  INT16_C( 28814), -INT16_C( 13582),
      -INT16_C(  2967),  INT16_C( 23363),  INT16_C(  2772), -INT16_C( 18634), -INT16_C( 17689),  INT16_C(  9125), -INT16_C( 18721), -INT16_C(  8569),
       INT16_C(  7172),  INT16_C(   693),  INT16_C(  4768), -INT16_C(  8209),  INT16_C( 11264), -INT16_C( 28766), -INT16_C( 27236),  INT16_C(  1369),
      -INT16_C( 25463),  INT16_C( 24161), -INT16_C( 26714), -INT16_C( 29419), -INT16_C( 17839),  INT16_C( 12464),  INT16_C( 14448),  INT16_C( 29711),
      -INT16_C( 15276), -INT16_C(  2954),  INT16_C( 26326), -INT16_C( 10284),  INT16_C( 30354),  INT16_C( 12134), -INT16_C( 16629), -INT16_C( 27340),
      -INT16_C( 27301),  INT16_C(   499),  INT16_C(  2092),  INT16_C( 32399),  INT16_C( 16322),  INT16_C( 12974), -INT16_C( 17033), -INT16_C( 13146),
       INT16_C(  7298),  INT16_C( 22720), -INT16_C( 27518),  INT16_C(  5423), -INT16_C( 27381),  INT16_C(  5700),  INT16_C( 30804), -INT16_C( 20565),
      -INT16_C( 25074),  INT16_C( 15025),  INT16_C( 16550),  INT16_C( 26808),  INT16_C( 26495), -INT16_C(  2150),  INT16_C( 16420), -INT16_C( 22845),
      -INT16_C( 31907), -INT16_C(  8193),  INT16_C( 11800),  INT16_C(  9204),  INT16_C( 14532),  INT16_C(  6201), -INT16_C(  6735), -INT16_C( 16440),
       INT16_C( 31107),  INT16_C( 11001), -INT16_C( 19783),  INT16_C( 14482),  INT16_C( 11545),  INT16_C( 15663), -INT16_C(  3475), -INT16_C( 13596),
      -INT16_C(  7306), -INT16_C( 29014), -INT16_C( 25071), -INT16_C( 10831), -INT16_C(  5417), -INT16_C( 30482), -INT16_C( 18737),  INT16_C( 21319),
       INT16_C( 16431), -INT16_C(  6019),  INT16_C(  4082),  INT16_C(  2848),  INT16_C( 20540), -INT16_C( 21943),  INT16_C( 11586), -INT16_C( 18316),
       INT16_C(  7696),  INT16_C(  8518), -INT16_C(  2115), -INT16_C( 27401), -INT16_C(  6686), -INT16_C( 20196),  INT16_C( 25499), -INT16_C( 13820),
      -INT16_C( 32349), -INT16_C( 26958), -INT16_C( 11631), -INT16_C( 12895), -INT16_C(  5598),  INT16_C( 25975), -INT16_C(  5097),  INT16_C( 10013),
       INT16_C( 25610), -INT16_C( 14519),  INT16_C( 16475),  INT16_C( 15707),  INT16_C( 30501), -INT16_C( 16145), -INT16_C(  3110),  INT16_C( 32394),
       INT16_C( 15477),  INT16_C(  1556), -INT16_C( 19186),  INT16_C( 12755),  INT16_C( 19360), -INT16_C( 18538), -INT16_C( 19657),  INT16_C( 16863),
       INT16_C( 10263),  INT16_C( 29449),  INT16_C( 25704), -INT16_C( 29264), -INT16_C( 24612), -INT16_C( 18867), -INT16_C( 10349),  INT16_C(  2100),
       INT16_C( 18451),  INT16_C(  8462), -INT16_C(  7682), -INT16_C( 25006), -INT16_C(  6100),  INT16_C( 25429),  INT16_C( 13468), -INT16_C( 19547),
      -INT16_C( 20900), -INT16_C( 15322), -INT16_C( 10478), -INT16_C(  4527), -INT16_C( 24970),  INT16_C(  2469), -INT16_C(  9867), -INT16_C( 30703),
       INT16_C(  7970),  INT16_C(  8362), -INT16_C(  1023),  INT16_C( 11710),  INT16_C(  5093), -INT16_C( 32367),  INT16_C( 13896), -INT16_C( 23500),
       INT16_C( 23524), -INT16_C(  2455), -INT16_C( 17870), -INT16_C( 22299), -INT16_C( 30119), -INT16_C( 12622), -INT16_C( 15517), -INT16_C( 31401),
       INT16_C(   483), -INT16_C(  7003),  INT16_C( 25597), -INT16_C(  7663), -INT16_C( 23945), -INT16_C( 16541), -INT16_C( 26408), -INT16_C( 17309),
      -INT16_C( 13069),  INT16_C(  9651), -INT16_C( 26489), -INT16_C(  7987),  INT16_C( 32546), -INT16_C( 31314),  INT16_C(  1347),  INT16_C(  9739),
      -INT16_C( 20474),  INT16_C(  1034),  INT16_C(  6932), -INT16_C( 29722),  INT16_C( 19134), -INT16_C( 27062), -INT16_C( 21022), -INT16_C( 10925),
       INT16_C(  1658),  INT16_C(   506), -INT16_C( 14434), -INT16_C( 16159), -INT16_C( 28857), -INT16_C( 30139),  INT16_C( 20629), -INT16_C( 25680),
      -INT16_C( 17919),  INT16_C(  5535), -INT16_C( 31019), -INT16_C( 27744), -INT16_C(  5424), -INT16_C( 19926),  INT16_C( 32151),  INT16_C(  4487),
      -INT16_C( 32381),  INT16_C(  8466), -INT16_C(  3256), -INT16_C( 28703),  INT16_C(  9859),  INT16_C(  6169), -INT16_C( 13961),  INT16_C( 30899),
       INT16_C( 21379),  INT16_C( 22925),  INT16_C( 11737), -INT16_C( 22036),  INT16_C(  5655), -INT16_C( 20901), -INT16_C(  7533),  INT16_C(  5824),
      -INT16_C( 11677), -INT16_C( 21705),  INT16_C(  6342),  INT16_C( 18747),  INT16_C( 21567), -INT16_C( 18847),  INT16_C(  5150), -INT16_C( 24274),
      -INT16_C( 17561),  INT16_C( 16634), -INT16_C(  6168), -INT16_C(    23),  INT16_C( 17661), -INT16_C( 28243),  INT16_C( 27942), -INT16_C( 30297),
      -INT16_C(  8384),  INT16_C(  1589),  INT16_C( 28919),  INT16_C( 13903), -INT16_C( 20284), -INT16_C(  7444),  INT16_C(  6852),  INT16_C( 11396),
       INT16_C( 32469), -INT16_C( 17044),  INT16_C( 22117),  INT16_C( 25532),  INT16_C( 27290), -INT16_C( 15884), -INT16_C( 25641),  INT16_C(  5962),
       INT16_C( 32634),  INT16_C( 29213),  INT16_C( 27887), -INT16_C( 19288), -INT16_C( 27364), -INT16_C(  7786),  INT16_C(  6831), -INT16_C( 31475),
       INT16_C( 31129), -INT16_C(   446), -INT16_C(    49),  INT16_C( 27233),  INT16_C( 21865),  INT16_C( 16427),  INT16_C( 30193),  INT16_C( 27480),
       INT16_C( 30197), -INT16_C(  6947), -INT16_C( 31006), -INT16_C(   360),  INT16_C( 12059), -INT16_C( 13601), -INT16_C(  5047), -INT16_C(  7601),
      -INT16_C( 28058),  INT16_C( 13793),  INT16_C( 17041), -INT16_C(  1377), -INT16_C( 13672), -INT16_C( 30406), -INT16_C( 28096),  INT16_C( 13812),
      -INT16_C( 11768), -INT16_C(  5607), -INT16_C( 19880),  INT16_C( 29672), -INT16_C( 14111),  INT16_C( 10813), -INT16_C( 29260),  INT16_C(  6669),
      -INT16_C(  4577), -INT16_C( 20400), -INT16_C(  4304), -INT16_C( 14166), -INT16_C(  6982), -INT16_C(  1455),  INT16_C( 18039),  INT16_C( 32559),
       INT16_C( 18456),  INT16_C( 28777),  INT16_C( 20986), -INT16_C(  9245),  INT16_C(  8217), -INT16_C( 12794),  INT16_C(  5037), -INT16_C( 13080),
       INT16_C( 14337),  INT16_C( 12668),  INT16_C(  9768), -INT16_C(  7430),  INT16_C( 19211), -INT16_C( 32036),  INT16_C(  2961), -INT16_C( 22271),
       INT16_C( 27219),  INT16_C( 19993), -INT16_C(   837), -INT16_C( 10967),  INT16_C( 12061), -INT16_C( 13661), -INT16_C( 29886),  INT16_C( 17303),
       INT16_C(  5060), -INT16_C(  5003),  INT16_C( 28474),  INT16_C( 17870), -INT16_C( 21830),  INT16_C( 19655), -INT16_C( 14155),  INT16_C(  2293),
       INT16_C(  3890), -INT16_C(  4778), -INT16_C( 32757),  INT16_C( 10434),  INT16_C( 26031), -INT16_C(  3341), -INT16_C( 29967), -INT16_C( 19147),
      -INT16_C( 21859), -INT16_C( 10335),  INT16_C( 28441), -INT16_C( 11236), -INT16_C(  7399), -INT16_C( 12768),  INT16_C(  5547), -INT16_C(  8746),
       INT16_C( 11556),  INT16_C( 12491), -INT16_C( 29267),  INT16_C( 23640),  INT16_C( 19443), -INT16_C(  7090), -INT16_C( 31531),  INT16_C( 29593),
       INT16_C( 14894),  INT16_C( 18506),  INT16_C( 26537), -INT16_C( 15844),  INT16_C( 15434), -INT16_C(  2416),  INT16_C( 26193),  INT16_C( 30419),
      -INT16_C( 24941),  INT16_C( 16550), -INT16_C(   468),  INT16_C(  8093), -INT16_C(  5302),  INT16_C(  7939), -INT16_C( 25489), -INT16_C( 24942),
      -INT16_C(  8746),  INT16_C( 32742),  INT16_C(   580) };
  static const int16_t b =  INT16_C(  9609);
  static const int16_t e[] =
    {  INT16_C(  7876),        INT16_MAX,  INT16_C(  1659),  INT16_C(    80),  INT16_C(   619),  INT16_C(  5133),  INT16_C( 18885),        INT16_MAX,
       INT16_C( 29832), -INT16_C(   738), -INT16_C( 22137),  INT16_C(  4837),  INT16_C(  5064), -INT16_C(  5946),        INT16_MAX, -INT16_C(  3973),
       INT16_C(  6642),        INT16_MAX,  INT16_C( 12381), -INT16_C(  9025), -INT16_C(  8080),  INT16_C( 18734), -INT16_C(  9112),  INT16_C(  1040),
       INT16_C( 16781),  INT16_C( 10302),  INT16_C( 14377),  INT16_C(  1400),  INT16_C( 20873), -INT16_C( 19157), -INT16_C( 17627),  INT16_C( 10978),
      -INT16_C( 15854),        INT16_MAX, -INT16_C( 17105), -INT16_C( 19810), -INT16_C(  8230),  INT16_C( 22073),  INT16_C( 24057),        INT16_MAX,
      -INT16_C(  5667),  INT16_C(  6655),        INT16_MAX, -INT16_C(   675),        INT16_MAX,  INT16_C( 21743), -INT16_C(  7020), -INT16_C( 17731),
      -INT16_C( 17692),  INT16_C( 10108),  INT16_C( 11701),        INT16_MAX,  INT16_C( 25931),  INT16_C( 22583), -INT16_C(  7424), -INT16_C(  3537),
       INT16_C( 16907),  INT16_C( 32329), -INT16_C( 17909),  INT16_C( 15032), -INT16_C( 17772),  INT16_C( 15309),        INT16_MAX, -INT16_C( 10956),
      -INT16_C( 15465),  INT16_C( 24634),  INT16_C( 26159),        INT16_MAX,        INT16_MAX,  INT16_C(  7459),  INT16_C( 26029), -INT16_C( 13236),
      -INT16_C( 22298),  INT16_C(  1416),  INT16_C( 21409),  INT16_C( 18813),  INT16_C( 24141),  INT16_C( 15810),  INT16_C(  2874), -INT16_C(  6831),
             INT16_MAX,  INT16_C( 20610), -INT16_C( 10174),  INT16_C( 24091),  INT16_C( 21154),  INT16_C( 25272),  INT16_C(  6134), -INT16_C(  3987),
       INT16_C(  2303), -INT16_C( 19405), -INT16_C( 15462), -INT16_C(  1222),  INT16_C(  4192), -INT16_C( 20873), -INT16_C(  9128),  INT16_C( 30928),
       INT16_C( 26040),  INT16_C(  3590),  INT16_C( 13691),  INT16_C( 12457),  INT16_C( 30149), -INT16_C( 12334),  INT16_C( 21195), -INT16_C(  8707),
       INT16_C( 17305),  INT16_C( 18127),  INT16_C(  7494), -INT16_C( 17792),  INT16_C(  2923), -INT16_C( 10587),        INT16_MAX, -INT16_C(  4211),
      -INT16_C( 22740), -INT16_C( 17349), -INT16_C(  2022), -INT16_C(  3286),  INT16_C(  4011),        INT16_MAX,  INT16_C(  4512),  INT16_C( 19622),
             INT16_MAX, -INT16_C(  4910),  INT16_C( 26084),  INT16_C( 25316),        INT16_MAX, -INT16_C(  6536),  INT16_C(  6499),        INT16_MAX,
       INT16_C( 25086),  INT16_C( 11165), -INT16_C(  9577),  INT16_C( 22364),  INT16_C( 28969), -INT16_C(  8929), -INT16_C( 10048),  INT16_C( 26472),
       INT16_C( 19872),        INT16_MAX,        INT16_MAX, -INT16_C( 19655), -INT16_C( 15003), -INT16_C(  9258), -INT16_C(   740),  INT16_C( 11709),
       INT16_C( 28060),  INT16_C( 18071),  INT16_C(  1927), -INT16_C( 15397),  INT16_C(  3509),        INT16_MAX,  INT16_C( 23077), -INT16_C(  9938),
      -INT16_C( 11291), -INT16_C(  5713), -INT16_C(   869),  INT16_C(  5082), -INT16_C( 15361),  INT16_C( 12078), -INT16_C(   258), -INT16_C( 21094),
       INT16_C( 17579),  INT16_C( 17971),  INT16_C(  8586),  INT16_C( 21319),  INT16_C( 14702), -INT16_C( 22758),  INT16_C( 23505), -INT16_C( 13891),
             INT16_MAX,  INT16_C(  7154), -INT16_C(  8261), -INT16_C( 12690), -INT16_C( 20510), -INT16_C(  3013), -INT16_C(  5908), -INT16_C( 21792),
       INT16_C( 10092),  INT16_C(  2606),        INT16_MAX,  INT16_C(  1946), -INT16_C( 14336), -INT16_C(  6932), -INT16_C( 16799), -INT16_C(  7700),
      -INT16_C(  3460),  INT16_C( 19260), -INT16_C( 16880),  INT16_C(  1622),        INT16_MAX, -INT16_C( 21705),  INT16_C( 10956),  INT16_C( 19348),
      -INT16_C( 10865),  INT16_C( 10643),  INT16_C( 16541), -INT16_C( 20113),  INT16_C( 28743), -INT16_C( 17453), -INT16_C( 11413), -INT16_C(  1316),
       INT16_C( 11267),  INT16_C( 10115), -INT16_C(  4825), -INT16_C(  6550), -INT16_C( 19248), -INT16_C( 20530),  INT16_C( 30238), -INT16_C( 16071),
      -INT16_C(  8310),  INT16_C( 15144), -INT16_C( 21410), -INT16_C( 18135),  INT16_C(  4185), -INT16_C( 10317),        INT16_MAX,  INT16_C( 14096),
      -INT16_C( 22772),  INT16_C( 18075),  INT16_C(  6353), -INT16_C( 19094),  INT16_C( 19468),  INT16_C( 15778), -INT16_C(  4352),        INT16_MAX,
       INT16_C( 30988),  INT16_C( 32534),  INT16_C( 21346), -INT16_C( 12427),  INT16_C( 15264), -INT16_C( 11292),  INT16_C(  2076),  INT16_C( 15433),
      -INT16_C(  2068), -INT16_C( 12096),  INT16_C( 15951),  INT16_C( 28356),  INT16_C( 31176), -INT16_C(  9238),  INT16_C( 14759), -INT16_C( 14665),
      -INT16_C(  7952),  INT16_C( 26243),  INT16_C(  3441),  INT16_C(  9586),  INT16_C( 27270), -INT16_C( 18634),        INT16_MAX, -INT16_C( 20688),
       INT16_C(  1225),  INT16_C( 11198),        INT16_MAX,  INT16_C( 23512), -INT16_C( 10675),  INT16_C(  2165),  INT16_C( 16461),  INT16_C( 21005),
             INT16_MAX, -INT16_C(  7435),  INT16_C( 31726),        INT16_MAX,        INT16_MAX, -INT16_C(  6275), -INT16_C( 16032),  INT16_C( 15571),
             INT16_MAX,        INT16_MAX,        INT16_MAX, -INT16_C(  9679), -INT16_C( 17755),  INT16_C(  1823),  INT16_C( 16440), -INT16_C( 21866),
             INT16_MAX,  INT16_C(  9163),  INT16_C(  9560),        INT16_MAX,  INT16_C( 31474),  INT16_C( 26036),        INT16_MAX,        INT16_MAX,
             INT16_MAX,  INT16_C(  2662), -INT16_C( 21397),  INT16_C(  9249),  INT16_C( 21668), -INT16_C(  3992),  INT16_C(  4562),  INT16_C(  2008),
      -INT16_C( 18449),  INT16_C( 23402),  INT16_C( 26650),  INT16_C(  8232), -INT16_C(  4063), -INT16_C( 20797), -INT16_C( 18487),  INT16_C( 23421),
      -INT16_C(  2159),  INT16_C(  4002), -INT16_C( 10271),        INT16_MAX, -INT16_C(  4502),  INT16_C( 20422), -INT16_C( 19651),  INT16_C( 16278),
       INT16_C(  5032), -INT16_C( 10791),  INT16_C(  5305), -INT16_C(  4557),  INT16_C(  2627),  INT16_C(  8154),  INT16_C( 27648),        INT16_MAX,
       INT16_C( 28065),        INT16_MAX,  INT16_C( 30595),  INT16_C(   364),  INT16_C( 17826), -INT16_C(  3185),  INT16_C( 14646), -INT16_C(  3471),
       INT16_C( 23946),  INT16_C( 22277),  INT16_C( 19377),  INT16_C(  2179),  INT16_C( 28820), -INT16_C( 22427),  INT16_C( 12570), -INT16_C( 12662),
             INT16_MAX,  INT16_C( 29602),  INT16_C(  8772), -INT16_C(  1358),  INT16_C( 21670), -INT16_C(  4052), -INT16_C( 20277),  INT16_C( 26912),
       INT16_C( 14669),  INT16_C(  4606),        INT16_MAX,  INT16_C( 27479), -INT16_C( 12221),  INT16_C( 29264), -INT16_C(  4546),  INT16_C( 11902),
       INT16_C( 13499),  INT16_C(  4831), -INT16_C( 23148),  INT16_C( 20043),        INT16_MAX,  INT16_C(  6268), -INT16_C( 20358), -INT16_C(  9538),
      -INT16_C( 12250), -INT16_C(   726),        INT16_MAX, -INT16_C(  1627),  INT16_C(  2210), -INT16_C(  3159),  INT16_C( 15156),  INT16_C(   863),
       INT16_C( 21165),  INT16_C( 22100), -INT16_C( 19658),        INT16_MAX,  INT16_C( 29052),  INT16_C(  2519), -INT16_C( 21922),        INT16_MAX,
       INT16_C( 24503),  INT16_C( 28115),        INT16_MAX, -INT16_C(  6235),  INT16_C( 25043),  INT16_C(  7193),        INT16_MAX,        INT16_MAX,
      -INT16_C( 15332),  INT16_C( 26159),  INT16_C(  9141),  INT16_C( 17702),  INT16_C(  4307),  INT16_C( 17548), -INT16_C( 15880), -INT16_C( 15333),
       INT16_C(   863),        INT16_MAX,  INT16_C( 10189) };

  static int16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t
      rv,
      av = simde_svld1_s16(pg, &(a[i]));

    rv = simde_svqadd_n_s16(av, b);

    simde_svst1_s16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vi16(len, e, r);

  return 0;
#else
  int16_t a[1024 / sizeof(int16_t)], b, e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i16();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t av, ev;

    av = simde_svld1_s16(pg, &(a[i]));

    ev = simde_svqadd_n_s16(av, b);

    simde_svst1_s16(pg, &(e[i]), ev);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i16(1, b);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t a[] =
    { -INT32_C(   702089489),  INT32_C(  1602159985), -INT32_C(   521013082), -INT32_C(   220970325),  INT32_C(  1943189197),  INT32_C(   878934055), -INT32_C(   262542203), -INT32_C(  1885641056),
      -INT32_C(   848969380),  INT32_C(  1831724230), -INT32_C(  2008211747),  INT32_C(   779821409), -INT32_C(     6205993),  INT32_C(  1261634757), -INT32_C(  1858368271),  INT32_C(  1327552243),
       INT32_C(  1578993047),  INT32_C(  1204505194), -INT32_C(   909174680),  INT32_C(   284641849),  INT32_C(  1561303191), -INT32_C(  1901575523), -INT32_C(  1038097457),  INT32_C(  1360084922),
       INT32_C(   783232708), -INT32_C(   512394632), -INT32_C(   878033518),  INT32_C(   668770959), -INT32_C(   679154886), -INT32_C(    43701202), -INT32_C(   910195697), -INT32_C(  2011443005),
       INT32_C(  2008468223), -INT32_C(   682087355),  INT32_C(    10683249), -INT32_C(   551059547), -INT32_C(  1732793494), -INT32_C(   409658153),  INT32_C(  1689277601),  INT32_C(   619498277),
      -INT32_C(   610557034),  INT32_C(  1085469903), -INT32_C(  1673505289),  INT32_C(  1065052372), -INT32_C(   338218477), -INT32_C(   254644913), -INT32_C(   430669119), -INT32_C(   469089970),
      -INT32_C(  1279285532), -INT32_C(  1846316646), -INT32_C(  1691536441), -INT32_C(  1344624485),  INT32_C(   714781403), -INT32_C(   535139297),  INT32_C(  1019703022), -INT32_C(  1826565713),
       INT32_C(   289857399),  INT32_C(   413284689),  INT32_C(   146001773),  INT32_C(  1404538488),  INT32_C(  1602048320), -INT32_C(  1405118531), -INT32_C(  1243085307),  INT32_C(  1330121176),
       INT32_C(   962695144),  INT32_C(   894501832),  INT32_C(  1262355923), -INT32_C(   744557165),  INT32_C(    70392647), -INT32_C(  1213173326),  INT32_C(  1349294456), -INT32_C(  1969244766),
       INT32_C(   214171716), -INT32_C(   683535100), -INT32_C(  1390247910), -INT32_C(  1132412811), -INT32_C(  1916685605), -INT32_C(  1673236188), -INT32_C(  1393774326), -INT32_C(  1439200410),
      -INT32_C(  1867056244),  INT32_C(   728234000), -INT32_C(   287798920),  INT32_C(   615143753),  INT32_C(   800156427), -INT32_C(   406063651),  INT32_C(   211072934), -INT32_C(   810103997),
      -INT32_C(   698389050), -INT32_C(   570309019), -INT32_C(  1731405233),  INT32_C(  1052538419), -INT32_C(  1083281950),  INT32_C(   161888610),  INT32_C(   873806577), -INT32_C(   888943611),
      -INT32_C(  1633525191),  INT32_C(  2004656936), -INT32_C(  1341175683), -INT32_C(  1578120257), -INT32_C(  1704960712), -INT32_C(  2019359082),  INT32_C(  1186707777), -INT32_C(  1106067835),
       INT32_C(  1214034976), -INT32_C(   708847273), -INT32_C(   528101855), -INT32_C(   780045159),  INT32_C(  1751966161),  INT32_C(   703533032),  INT32_C(  1299164104), -INT32_C(  1978957463),
      -INT32_C(  1915590603),  INT32_C(  1650627137), -INT32_C(    96213152),  INT32_C(   768328796), -INT32_C(  1902823514),  INT32_C(   263685447), -INT32_C(  1721948624), -INT32_C(   584882008),
       INT32_C(   292222672), -INT32_C(   394998648),  INT32_C(   283293620),  INT32_C(   557690491),  INT32_C(   749720549), -INT32_C(  2009307560),  INT32_C(   891394445), -INT32_C(   770554623),
      -INT32_C(  1008501445), -INT32_C(    39102647), -INT32_C(  1978823154),  INT32_C(   564874044),  INT32_C(  1984846622),  INT32_C(  1325304513),  INT32_C(   612572963), -INT32_C(  1611229596),
       INT32_C(  1549982227),  INT32_C(  1079643697), -INT32_C(   657823844), -INT32_C(   788957774), -INT32_C(  1840887856), -INT32_C(   186628911), -INT32_C(   937859996),  INT32_C(   224923642),
       INT32_C(   459918057),  INT32_C(  1952170968), -INT32_C(   582212309),  INT32_C(  1806583450),  INT32_C(  1610478733), -INT32_C(  1655448263),  INT32_C(   996502593),  INT32_C(  1699270012),
       INT32_C(  1887482520), -INT32_C(  1595548811), -INT32_C(  1686228736),  INT32_C(    84290679),  INT32_C(  1499726624),  INT32_C(   586594272), -INT32_C(  1604494300), -INT32_C(  1056594391),
      -INT32_C(   852326824),  INT32_C(  1651382113), -INT32_C(  1057100728),  INT32_C(   952435480), -INT32_C(   426628858),  INT32_C(    67668192),  INT32_C(   245655268),  INT32_C(  1691331084),
      -INT32_C(  1859059408),  INT32_C(  1643355928), -INT32_C(  1558056821), -INT32_C(   102963469), -INT32_C(   270504433), -INT32_C(   604706570),  INT32_C(  1525258318),  INT32_C(  1925101634),
      -INT32_C(   771428166),  INT32_C(   456390543), -INT32_C(   608283416),  INT32_C(  1238735418), -INT32_C(    12995320), -INT32_C(   321245795),  INT32_C(   138855365),  INT32_C(   897189243),
      -INT32_C(  2079817995),  INT32_C(  1587493750), -INT32_C(   902209904),  INT32_C(    18091768),  INT32_C(  1627409859),  INT32_C(  1062066810),  INT32_C(   407344029), -INT32_C(  1924218216),
      -INT32_C(  1240312256),  INT32_C(   555004305),  INT32_C(   149704207),  INT32_C(   537460828), -INT32_C(   947844787), -INT32_C(  2147037469), -INT32_C(    90681759),  INT32_C(  1351083536),
      -INT32_C(   838362820),  INT32_C(  1525619531), -INT32_C(   966599831),  INT32_C(   686189531),  INT32_C(  1475307380), -INT32_C(  1764231627),  INT32_C(  1418752068), -INT32_C(  1817962410),
      -INT32_C(    60707919),  INT32_C(   811028679),  INT32_C(   133609772), -INT32_C(  1724851163),  INT32_C(  2029068099),  INT32_C(  1494206485), -INT32_C(  1884446920),  INT32_C(  1763857079),
      -INT32_C(   999980035), -INT32_C(      672557), -INT32_C(  1693979786),  INT32_C(   187971528),  INT32_C(  1820599638),  INT32_C(   650482670), -INT32_C(   357207246), -INT32_C(  1034692667),
       INT32_C(   780646490), -INT32_C(   349340555),  INT32_C(   797324391), -INT32_C(  1036273045), -INT32_C(   835797024), -INT32_C(  2064321710),  INT32_C(   728672870), -INT32_C(   588332671),
      -INT32_C(   284527238),  INT32_C(  1490696177), -INT32_C(   678928276) };
  static const int32_t b = -INT32_C(   302586133);
  static const int32_t e[] =
    { -INT32_C(  1004675622),  INT32_C(  1299573852), -INT32_C(   823599215), -INT32_C(   523556458),  INT32_C(  1640603064),  INT32_C(   576347922), -INT32_C(   565128336),              INT32_MIN,
      -INT32_C(  1151555513),  INT32_C(  1529138097),              INT32_MIN,  INT32_C(   477235276), -INT32_C(   308792126),  INT32_C(   959048624),              INT32_MIN,  INT32_C(  1024966110),
       INT32_C(  1276406914),  INT32_C(   901919061), -INT32_C(  1211760813), -INT32_C(    17944284),  INT32_C(  1258717058),              INT32_MIN, -INT32_C(  1340683590),  INT32_C(  1057498789),
       INT32_C(   480646575), -INT32_C(   814980765), -INT32_C(  1180619651),  INT32_C(   366184826), -INT32_C(   981741019), -INT32_C(   346287335), -INT32_C(  1212781830),              INT32_MIN,
       INT32_C(  1705882090), -INT32_C(   984673488), -INT32_C(   291902884), -INT32_C(   853645680), -INT32_C(  2035379627), -INT32_C(   712244286),  INT32_C(  1386691468),  INT32_C(   316912144),
      -INT32_C(   913143167),  INT32_C(   782883770), -INT32_C(  1976091422),  INT32_C(   762466239), -INT32_C(   640804610), -INT32_C(   557231046), -INT32_C(   733255252), -INT32_C(   771676103),
      -INT32_C(  1581871665),              INT32_MIN, -INT32_C(  1994122574), -INT32_C(  1647210618),  INT32_C(   412195270), -INT32_C(   837725430),  INT32_C(   717116889), -INT32_C(  2129151846),
      -INT32_C(    12728734),  INT32_C(   110698556), -INT32_C(   156584360),  INT32_C(  1101952355),  INT32_C(  1299462187), -INT32_C(  1707704664), -INT32_C(  1545671440),  INT32_C(  1027535043),
       INT32_C(   660109011),  INT32_C(   591915699),  INT32_C(   959769790), -INT32_C(  1047143298), -INT32_C(   232193486), -INT32_C(  1515759459),  INT32_C(  1046708323),              INT32_MIN,
      -INT32_C(    88414417), -INT32_C(   986121233), -INT32_C(  1692834043), -INT32_C(  1434998944),              INT32_MIN, -INT32_C(  1975822321), -INT32_C(  1696360459), -INT32_C(  1741786543),
                   INT32_MIN,  INT32_C(   425647867), -INT32_C(   590385053),  INT32_C(   312557620),  INT32_C(   497570294), -INT32_C(   708649784), -INT32_C(    91513199), -INT32_C(  1112690130),
      -INT32_C(  1000975183), -INT32_C(   872895152), -INT32_C(  2033991366),  INT32_C(   749952286), -INT32_C(  1385868083), -INT32_C(   140697523),  INT32_C(   571220444), -INT32_C(  1191529744),
      -INT32_C(  1936111324),  INT32_C(  1702070803), -INT32_C(  1643761816), -INT32_C(  1880706390), -INT32_C(  2007546845),              INT32_MIN,  INT32_C(   884121644), -INT32_C(  1408653968),
       INT32_C(   911448843), -INT32_C(  1011433406), -INT32_C(   830687988), -INT32_C(  1082631292),  INT32_C(  1449380028),  INT32_C(   400946899),  INT32_C(   996577971),              INT32_MIN,
                   INT32_MIN,  INT32_C(  1348041004), -INT32_C(   398799285),  INT32_C(   465742663),              INT32_MIN, -INT32_C(    38900686), -INT32_C(  2024534757), -INT32_C(   887468141),
      -INT32_C(    10363461), -INT32_C(   697584781), -INT32_C(    19292513),  INT32_C(   255104358),  INT32_C(   447134416),              INT32_MIN,  INT32_C(   588808312), -INT32_C(  1073140756),
      -INT32_C(  1311087578), -INT32_C(   341688780),              INT32_MIN,  INT32_C(   262287911),  INT32_C(  1682260489),  INT32_C(  1022718380),  INT32_C(   309986830), -INT32_C(  1913815729),
       INT32_C(  1247396094),  INT32_C(   777057564), -INT32_C(   960409977), -INT32_C(  1091543907), -INT32_C(  2143473989), -INT32_C(   489215044), -INT32_C(  1240446129), -INT32_C(    77662491),
       INT32_C(   157331924),  INT32_C(  1649584835), -INT32_C(   884798442),  INT32_C(  1503997317),  INT32_C(  1307892600), -INT32_C(  1958034396),  INT32_C(   693916460),  INT32_C(  1396683879),
       INT32_C(  1584896387), -INT32_C(  1898134944), -INT32_C(  1988814869), -INT32_C(   218295454),  INT32_C(  1197140491),  INT32_C(   284008139), -INT32_C(  1907080433), -INT32_C(  1359180524),
      -INT32_C(  1154912957),  INT32_C(  1348795980), -INT32_C(  1359686861),  INT32_C(   649849347), -INT32_C(   729214991), -INT32_C(   234917941), -INT32_C(    56930865),  INT32_C(  1388744951),
                   INT32_MIN,  INT32_C(  1340769795), -INT32_C(  1860642954), -INT32_C(   405549602), -INT32_C(   573090566), -INT32_C(   907292703),  INT32_C(  1222672185),  INT32_C(  1622515501),
      -INT32_C(  1074014299),  INT32_C(   153804410), -INT32_C(   910869549),  INT32_C(   936149285), -INT32_C(   315581453), -INT32_C(   623831928), -INT32_C(   163730768),  INT32_C(   594603110),
                   INT32_MIN,  INT32_C(  1284907617), -INT32_C(  1204796037), -INT32_C(   284494365),  INT32_C(  1324823726),  INT32_C(   759480677),  INT32_C(   104757896),              INT32_MIN,
      -INT32_C(  1542898389),  INT32_C(   252418172), -INT32_C(   152881926),  INT32_C(   234874695), -INT32_C(  1250430920),              INT32_MIN, -INT32_C(   393267892),  INT32_C(  1048497403),
      -INT32_C(  1140948953),  INT32_C(  1223033398), -INT32_C(  1269185964),  INT32_C(   383603398),  INT32_C(  1172721247), -INT32_C(  2066817760),  INT32_C(  1116165935), -INT32_C(  2120548543),
      -INT32_C(   363294052),  INT32_C(   508442546), -INT32_C(   168976361), -INT32_C(  2027437296),  INT32_C(  1726481966),  INT32_C(  1191620352),              INT32_MIN,  INT32_C(  1461270946),
      -INT32_C(  1302566168), -INT32_C(   303258690), -INT32_C(  1996565919), -INT32_C(   114614605),  INT32_C(  1518013505),  INT32_C(   347896537), -INT32_C(   659793379), -INT32_C(  1337278800),
       INT32_C(   478060357), -INT32_C(   651926688),  INT32_C(   494738258), -INT32_C(  1338859178), -INT32_C(  1138383157),              INT32_MIN,  INT32_C(   426086737), -INT32_C(   890918804),
      -INT32_C(   587113371),  INT32_C(  1188110044), -INT32_C(   981514409) };

  static int32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t
      rv,
      av = simde_svld1_s32(pg, &(a[i]));

    rv = simde_svqadd_n_s32(av, b);

    simde_svst1_s32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vi32(len, e, r);

  return 0;
#else
  int32_t a[1024 / sizeof(int32_t)], b, e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i32();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t av, ev;

    av = simde_svld1_s32(pg, &(a[i]));

    ev = simde_svqadd_n_s32(av, b);

    simde_svst1_s32(pg, &(e[i]), ev);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i32(1, b);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t a[] =
    { -INT64_C(   16571552326054271), -INT64_C( 4737450331321785696),  INT64_C( 5971504166173258232),  INT64_C( 7947545942205388529),
       INT64_C( 5056136815560132073), -INT64_C( 2816548704857969372),  INT64_C( 7711657325356871245), -INT64_C( 8610626717622713051),
      -INT64_C( 2208488139076092819), -INT64_C( 7258406982245370996),  INT64_C( 2902943810391618659),  INT64_C( 4305928109334128025),
      -INT64_C( 2227690460584970890),  INT64_C( 8738269803016167770), -INT64_C( 9119330855220178106), -INT64_C( 2626025857583764603),
      -INT64_C( 2511280695506182927),  INT64_C( 5536270871070864452),  INT64_C( 5820065563544988508), -INT64_C( 1445319055217819727),
       INT64_C( 7452708768622706445),  INT64_C( 1809768362990040011),  INT64_C( 7628010044883055297), -INT64_C( 4645620582489030495),
      -INT64_C( 2595554360632035216),  INT64_C( 1406752913982536880), -INT64_C( 6512631653609774468), -INT64_C(  113495375473467652),
       INT64_C( 2984352156813999232),  INT64_C( 6750363547266783048), -INT64_C( 4132279389392843011),  INT64_C( 3520936058931112015),
       INT64_C( 4773299904359460252), -INT64_C( 1404969228836154559), -INT64_C( 7896616353871818023),  INT64_C( 6439950367574777214),
      -INT64_C( 8361587700600528967),  INT64_C( 3988550299302089343),  INT64_C( 6563509225129658432), -INT64_C( 8415000286832458207),
      -INT64_C( 3396783594595769080), -INT64_C(  605003286516430331), -INT64_C( 2803049070405651232), -INT64_C( 7749306769813822697),
      -INT64_C( 1389990613035338861),  INT64_C( 7853127162827633484),  INT64_C( 2229075137799026269),  INT64_C( 2956750136707360743),
      -INT64_C(  215677241318838737), -INT64_C( 7516792305672433482),  INT64_C(  331467698031417715),  INT64_C( 5477082062038540611),
      -INT64_C( 8638357281112518801), -INT64_C( 8033163769678258253),  INT64_C( 1257529923187978577), -INT64_C( 2544836789157565627),
       INT64_C( 2762143031141077243), -INT64_C( 1592418737693974726), -INT64_C( 2618900810664709688),  INT64_C( 8718947425818939830),
       INT64_C( 5806999290199342076),  INT64_C(  665562156659812795),  INT64_C( 1652898437426812030),  INT64_C( 1715088718831365847),
       INT64_C( 7609144580302574387),  INT64_C( 5409097811465355462), -INT64_C( 3601946255491551091), -INT64_C( 6363604464403596162),
       INT64_C( 1736852694082074114),  INT64_C( 6765304737687394250),  INT64_C( 1271226292176045024), -INT64_C( 5069547163060942967),
      -INT64_C( 1442695453863143793),  INT64_C( 2993034792301369691), -INT64_C( 6175380526401006680), -INT64_C( 2388230175110662549),
       INT64_C( 2733326296862901731),  INT64_C( 9171257204807856595),  INT64_C( 6230738789539137197),  INT64_C( 5776521200955564285),
       INT64_C( 8540587012834781592),  INT64_C( 6704127773068416947), -INT64_C( 4080361549730168034), -INT64_C( 4430911831941064764),
      -INT64_C( 3728793463720520153), -INT64_C( 3922811561544592767),  INT64_C( 2573017045898803747),  INT64_C( 3311508047638415368),
       INT64_C( 4869296931835680942),  INT64_C( 7817689618256816649), -INT64_C( 8485046121446879042),  INT64_C( 1876507275888006359),
       INT64_C( 4813912837919408585),  INT64_C(  293987722517168990),  INT64_C( 6183829854536953541),  INT64_C(  683207115194666741),
       INT64_C( 3438889537484708926), -INT64_C( 1589230649643389018),  INT64_C( 7506376275962892890), -INT64_C( 2677033063186604144),
       INT64_C( 8691677704792141472), -INT64_C( 4843806792064076102), -INT64_C( 8627558811049920663), -INT64_C( 1038868812422181601),
      -INT64_C( 6058746737179039840),  INT64_C( 1267289027007565944),  INT64_C(  632811725043607879), -INT64_C(  900058760058035905),
       INT64_C( 6835709858531435584), -INT64_C(  118555153569126751), -INT64_C( 5050497287067908105),  INT64_C( 5075218158303489320),
      -INT64_C( 4038228970436045647), -INT64_C(  977163490956399173), -INT64_C( 2385573312482529359), -INT64_C( 6073447169021890966),
       INT64_C( 4433854867873869212), -INT64_C( 5453262103736510364),  INT64_C( 5504177072259409358),  INT64_C( 2276414047580371953),
       INT64_C( 8457594147545602464), -INT64_C(  236395906128867839),  INT64_C( 5439190951463524172),  INT64_C( 5350502487901485214),
      -INT64_C( 8417848331825569369),  INT64_C( 8503718762951672537),  INT64_C(  397196815547859934) };
  static const int64_t b =  INT64_C( 6889685566727043720);
  static const int64_t e[] =
    {  INT64_C( 6873114014400989449),  INT64_C( 2152235235405258024),                      INT64_MAX,                      INT64_MAX,
                           INT64_MAX,  INT64_C( 4073136861869074348),                      INT64_MAX, -INT64_C( 1720941150895669331),
       INT64_C( 4681197427650950901), -INT64_C(  368721415518327276),                      INT64_MAX,                      INT64_MAX,
       INT64_C( 4661995106142072830),                      INT64_MAX, -INT64_C( 2229645288493134386),  INT64_C( 4263659709143279117),
       INT64_C( 4378404871220860793),                      INT64_MAX,                      INT64_MAX,  INT64_C( 5444366511509223993),
                           INT64_MAX,  INT64_C( 8699453929717083731),                      INT64_MAX,  INT64_C( 2244064984238013225),
       INT64_C( 4294131206095008504),  INT64_C( 8296438480709580600),  INT64_C(  377053913117269252),  INT64_C( 6776190191253576068),
                           INT64_MAX,                      INT64_MAX,  INT64_C( 2757406177334200709),                      INT64_MAX,
                           INT64_MAX,  INT64_C( 5484716337890889161), -INT64_C( 1006930787144774303),                      INT64_MAX,
      -INT64_C( 1471902133873485247),                      INT64_MAX,                      INT64_MAX, -INT64_C( 1525314720105414487),
       INT64_C( 3492901972131274640),  INT64_C( 6284682280210613389),  INT64_C( 4086636496321392488), -INT64_C(  859621203086778977),
       INT64_C( 5499694953691704859),                      INT64_MAX,  INT64_C( 9118760704526069989),                      INT64_MAX,
       INT64_C( 6674008325408204983), -INT64_C(  627106738945389762),  INT64_C( 7221153264758461435),                      INT64_MAX,
      -INT64_C( 1748671714385475081), -INT64_C( 1143478202951214533),  INT64_C( 8147215489915022297),  INT64_C( 4344848777569478093),
                           INT64_MAX,  INT64_C( 5297266829033068994),  INT64_C( 4270784756062334032),                      INT64_MAX,
                           INT64_MAX,  INT64_C( 7555247723386856515),  INT64_C( 8542584004153855750),  INT64_C( 8604774285558409567),
                           INT64_MAX,                      INT64_MAX,  INT64_C( 3287739311235492629),  INT64_C(  526081102323447558),
       INT64_C( 8626538260809117834),                      INT64_MAX,  INT64_C( 8160911858903088744),  INT64_C( 1820138403666100753),
       INT64_C( 5446990112863899927),                      INT64_MAX,  INT64_C(  714305040326037040),  INT64_C( 4501455391616381171),
                           INT64_MAX,                      INT64_MAX,                      INT64_MAX,                      INT64_MAX,
                           INT64_MAX,                      INT64_MAX,  INT64_C( 2809324016996875686),  INT64_C( 2458773734785978956),
       INT64_C( 3160892103006523567),  INT64_C( 2966874005182450953),                      INT64_MAX,                      INT64_MAX,
                           INT64_MAX,                      INT64_MAX, -INT64_C( 1595360554719835322),  INT64_C( 8766192842615050079),
                           INT64_MAX,  INT64_C( 7183673289244212710),                      INT64_MAX,  INT64_C( 7572892681921710461),
                           INT64_MAX,  INT64_C( 5300454917083654702),                      INT64_MAX,  INT64_C( 4212652503540439576),
                           INT64_MAX,  INT64_C( 2045878774662967618), -INT64_C( 1737873244322876943),  INT64_C( 5850816754304862119),
       INT64_C(  830938829548003880),  INT64_C( 8156974593734609664),  INT64_C( 7522497291770651599),  INT64_C( 5989626806669007815),
                           INT64_MAX,  INT64_C( 6771130413157916969),  INT64_C( 1839188279659135615),                      INT64_MAX,
       INT64_C( 2851456596290998073),  INT64_C( 5912522075770644547),  INT64_C( 4504112254244514361),  INT64_C(  816238397705152754),
                           INT64_MAX,  INT64_C( 1436423462990533356),                      INT64_MAX,  INT64_C( 9166099614307415673),
                           INT64_MAX,  INT64_C( 6653289660598175881),                      INT64_MAX,                      INT64_MAX,
      -INT64_C( 1528162765098525649),                      INT64_MAX,  INT64_C( 7286882382274903654) };

  static int64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t
      rv,
      av = simde_svld1_s64(pg, &(a[i]));

    rv = simde_svqadd_n_s64(av, b);

    simde_svst1_s64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vi64(len, e, r);

  return 0;
#else
  int64_t a[1024 / sizeof(int64_t)], b, e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i64();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t av, ev;

    av = simde_svld1_s64(pg, &(a[i]));

    ev = simde_svqadd_n_s64(av, b);

    simde_svst1_s64(pg, &(e[i]), ev);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i64(1, b);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const uint8_t a[] =
    { UINT8_C(116), UINT8_C(105), UINT8_C(182), UINT8_C( 83), UINT8_C(236), UINT8_C( 91), UINT8_C(139), UINT8_C( 83),
      UINT8_C(123), UINT8_C( 15), UINT8_C( 88), UINT8_C(212), UINT8_C(201), UINT8_C(126), UINT8_C(215), UINT8_C( 80),
      UINT8_C(229), UINT8_C( 36), UINT8_C(127), UINT8_C(109), UINT8_C(222), UINT8_C(101), UINT8_C(127), UINT8_C(100),
      UINT8_C(121), UINT8_C( 29), UINT8_C(195), UINT8_C(144), UINT8_C( 74), UINT8_C( 41), UINT8_C(208), UINT8_C(190),
      UINT8_C(146), UINT8_C(134), UINT8_C( 17), UINT8_C(126), UINT8_C(225), UINT8_C(157), UINT8_C(209), UINT8_C( 92),
      UINT8_C(172), UINT8_C( 41), UINT8_C( 48), UINT8_C(117), UINT8_C(168), UINT8_C(  7), UINT8_C(197), UINT8_C(141),
      UINT8_C( 44), UINT8_C( 68), UINT8_C(251), UINT8_C( 10), UINT8_C(170), UINT8_C(122), UINT8_C(110), UINT8_C( 35),
      UINT8_C(151), UINT8_C( 49), UINT8_C(179), UINT8_C(225), UINT8_C( 90), UINT8_C(131), UINT8_C(160), UINT8_C(236),
      UINT8_C(  9), UINT8_C(177), UINT8_C(107), UINT8_C(234), UINT8_C( 78), UINT8_C( 60), UINT8_C( 71), UINT8_C(250),
      UINT8_C(102), UINT8_C(119), UINT8_C(111), UINT8_C( 14), UINT8_C(127), UINT8_C( 53), UINT8_C(155), UINT8_C(171),
      UINT8_C(121), UINT8_C(150), UINT8_C(181), UINT8_C( 35), UINT8_C( 17), UINT8_C( 36), UINT8_C( 71), UINT8_C(168),
      UINT8_C( 85), UINT8_C(250), UINT8_C(138), UINT8_C(176), UINT8_C(126), UINT8_C( 42), UINT8_C(156), UINT8_C(135),
      UINT8_C(219), UINT8_C(  7), UINT8_C(114), UINT8_C( 42), UINT8_C( 68), UINT8_C(185), UINT8_C( 36), UINT8_C(170),
      UINT8_C( 48), UINT8_C(148), UINT8_C(184), UINT8_C(175), UINT8_C(201), UINT8_C( 83), UINT8_C( 90), UINT8_C( 66),
      UINT8_C(234), UINT8_C( 16), UINT8_C(102), UINT8_C(251), UINT8_C( 52), UINT8_C(173), UINT8_C(163), UINT8_C(137),
      UINT8_C(167), UINT8_C( 45), UINT8_C( 57), UINT8_C( 37), UINT8_C( 87), UINT8_C(214), UINT8_C(173), UINT8_C( 51),
      UINT8_C(221), UINT8_C( 31), UINT8_C( 93), UINT8_C( 33), UINT8_C(216), UINT8_C(129), UINT8_C(203), UINT8_C(  8),
      UINT8_C( 21), UINT8_C(131), UINT8_C(184), UINT8_C(222), UINT8_C(215), UINT8_C( 18), UINT8_C( 33), UINT8_C(193),
      UINT8_C( 34), UINT8_C(135), UINT8_C(188), UINT8_C( 86), UINT8_C( 52), UINT8_C( 95), UINT8_C(224), UINT8_C(219),
      UINT8_C(141), UINT8_C( 25), UINT8_C(  1), UINT8_C(228), UINT8_C(239), UINT8_C(174), UINT8_C( 23), UINT8_C(205),
      UINT8_C(205), UINT8_C(116), UINT8_C(238), UINT8_C(165), UINT8_C(246), UINT8_C(186), UINT8_C(173), UINT8_C( 11),
      UINT8_C( 61), UINT8_C(101), UINT8_C(234), UINT8_C( 20), UINT8_C(120), UINT8_C( 11), UINT8_C(213), UINT8_C(154),
      UINT8_C(146), UINT8_C(145), UINT8_C(241), UINT8_C(198), UINT8_C(241), UINT8_C(209), UINT8_C(161), UINT8_C(126),
      UINT8_C(234), UINT8_C(162), UINT8_C( 98), UINT8_C(218), UINT8_C( 80), UINT8_C(122), UINT8_C(167), UINT8_C( 29),
      UINT8_C(238), UINT8_C(149), UINT8_C(194), UINT8_C(228), UINT8_C( 79), UINT8_C(112), UINT8_C(240), UINT8_C(141),
      UINT8_C(213), UINT8_C(218), UINT8_C(161), UINT8_C( 77), UINT8_C(229), UINT8_C(119), UINT8_C(232), UINT8_C(119),
      UINT8_C(  8), UINT8_C(217), UINT8_C( 61), UINT8_C(249), UINT8_C(170), UINT8_C(222), UINT8_C(119), UINT8_C(148),
      UINT8_C(129), UINT8_C(218), UINT8_C(110), UINT8_C(209), UINT8_C( 84), UINT8_C( 21), UINT8_C(239), UINT8_C( 66),
      UINT8_C(171), UINT8_C(177), UINT8_C( 39), UINT8_C(250), UINT8_C( 33), UINT8_C( 23), UINT8_C(135), UINT8_C(247),
      UINT8_C(241), UINT8_C( 41), UINT8_C( 68), UINT8_C(214), UINT8_C(160), UINT8_C( 44), UINT8_C( 77), UINT8_C(168),
      UINT8_C(  5), UINT8_C(138), UINT8_C(162), UINT8_C(175), UINT8_C(104), UINT8_C( 25), UINT8_C( 68), UINT8_C(233),
      UINT8_C(243), UINT8_C(178), UINT8_C(187), UINT8_C( 71), UINT8_C(200), UINT8_C(170), UINT8_C(138), UINT8_C(115),
      UINT8_C( 91), UINT8_C(177), UINT8_C(109), UINT8_C(125), UINT8_C(200), UINT8_C(245), UINT8_C(116), UINT8_C(185),
      UINT8_C( 30), UINT8_C(184), UINT8_C(143), UINT8_C(190), UINT8_C(229), UINT8_C(220), UINT8_C(102), UINT8_C(234),
      UINT8_C(102), UINT8_C(  8), UINT8_C(154), UINT8_C(206), UINT8_C( 34), UINT8_C(222), UINT8_C(184), UINT8_C( 21),
      UINT8_C(144), UINT8_C(115), UINT8_C( 93), UINT8_C( 88), UINT8_C( 29), UINT8_C(231), UINT8_C(203), UINT8_C(120),
      UINT8_C(152), UINT8_C( 57), UINT8_C(245), UINT8_C( 96), UINT8_C( 46), UINT8_C(105), UINT8_C( 25), UINT8_C( 76),
      UINT8_C( 34), UINT8_C(168), UINT8_C( 10), UINT8_C(  7), UINT8_C(132), UINT8_C(112), UINT8_C(241), UINT8_C(234),
      UINT8_C(121), UINT8_C(139), UINT8_C(184), UINT8_C(155), UINT8_C(105), UINT8_C(112), UINT8_C(176), UINT8_C(250),
      UINT8_C(227), UINT8_C( 13), UINT8_C( 82), UINT8_C(  0), UINT8_C(244), UINT8_C( 30), UINT8_C(121), UINT8_C(140),
      UINT8_C( 87), UINT8_C(110), UINT8_C(236), UINT8_C(133), UINT8_C(216), UINT8_C(  5), UINT8_C(209), UINT8_C(250),
      UINT8_C(173), UINT8_C(219), UINT8_C(  1), UINT8_C( 49), UINT8_C( 75), UINT8_C(242), UINT8_C( 27), UINT8_C(196),
      UINT8_C(126), UINT8_C(212), UINT8_C( 95), UINT8_C(231), UINT8_C( 68), UINT8_C( 16), UINT8_C(225), UINT8_C( 40),
      UINT8_C( 29), UINT8_C( 52), UINT8_C( 40), UINT8_C( 18), UINT8_C( 82), UINT8_C(161), UINT8_C(158), UINT8_C(169),
      UINT8_C( 16), UINT8_C(139), UINT8_C( 46), UINT8_C(232), UINT8_C(144),    UINT8_MAX, UINT8_C(226), UINT8_C( 62),
      UINT8_C(218), UINT8_C(227), UINT8_C(111), UINT8_C( 37), UINT8_C(213), UINT8_C(139), UINT8_C(234), UINT8_C( 83),
      UINT8_C( 95), UINT8_C( 73), UINT8_C( 59), UINT8_C(163), UINT8_C( 89), UINT8_C( 28), UINT8_C(203), UINT8_C(119),
      UINT8_C( 80), UINT8_C(244), UINT8_C(137), UINT8_C(162), UINT8_C(149), UINT8_C( 39), UINT8_C( 75), UINT8_C(165),
      UINT8_C(178), UINT8_C(121), UINT8_C(141), UINT8_C( 67), UINT8_C(120), UINT8_C(111), UINT8_C(129), UINT8_C( 82),
      UINT8_C( 82), UINT8_C(240), UINT8_C(120), UINT8_C( 40), UINT8_C(123), UINT8_C( 98), UINT8_C(123), UINT8_C(218),
      UINT8_C(171), UINT8_C(182), UINT8_C(126), UINT8_C(  5), UINT8_C(211), UINT8_C( 73), UINT8_C(124), UINT8_C( 35),
      UINT8_C( 61), UINT8_C(  5), UINT8_C(198), UINT8_C(211), UINT8_C( 44), UINT8_C( 17), UINT8_C(120), UINT8_C(223),
      UINT8_C(139), UINT8_C(  6), UINT8_C( 34), UINT8_C(  3), UINT8_C(117), UINT8_C(163), UINT8_C( 86), UINT8_C(200),
      UINT8_C(147), UINT8_C(206), UINT8_C(240), UINT8_C( 15), UINT8_C( 48), UINT8_C(107), UINT8_C(233), UINT8_C(219),
      UINT8_C( 34), UINT8_C(103), UINT8_C(224), UINT8_C(245), UINT8_C(177), UINT8_C( 92), UINT8_C( 24), UINT8_C(238),
      UINT8_C( 97), UINT8_C(222), UINT8_C(193), UINT8_C(142), UINT8_C(240), UINT8_C( 58), UINT8_C(109), UINT8_C(123),
      UINT8_C( 64), UINT8_C(143), UINT8_C(126), UINT8_C(181), UINT8_C( 50), UINT8_C(212), UINT8_C(125), UINT8_C(197),
      UINT8_C(162), UINT8_C(109), UINT8_C(212), UINT8_C(210), UINT8_C(217), UINT8_C(190), UINT8_C(174), UINT8_C(251),
      UINT8_C( 37), UINT8_C(142), UINT8_C(240), UINT8_C(214), UINT8_C(235), UINT8_C(  8), UINT8_C(197), UINT8_C( 76),
      UINT8_C(231), UINT8_C(134), UINT8_C(218), UINT8_C(215), UINT8_C(192), UINT8_C( 71), UINT8_C( 82), UINT8_C(  0),
      UINT8_C(214), UINT8_C(208), UINT8_C(182), UINT8_C(  8), UINT8_C(165), UINT8_C( 51), UINT8_C(206), UINT8_C( 71),
      UINT8_C(161), UINT8_C(162), UINT8_C( 26), UINT8_C(122), UINT8_C( 96), UINT8_C(200), UINT8_C(117), UINT8_C(134),
      UINT8_C( 86), UINT8_C(101), UINT8_C( 92), UINT8_C( 65), UINT8_C(109), UINT8_C( 33), UINT8_C(142), UINT8_C( 84),
      UINT8_C(168), UINT8_C(104), UINT8_C( 43), UINT8_C(104), UINT8_C(176), UINT8_C(125), UINT8_C(105), UINT8_C(134),
      UINT8_C( 78), UINT8_C( 31), UINT8_C(143), UINT8_C(243), UINT8_C( 82), UINT8_C( 93), UINT8_C( 58), UINT8_C(243),
         UINT8_MAX, UINT8_C( 84), UINT8_C(109), UINT8_C( 96), UINT8_C( 28), UINT8_C(226), UINT8_C(230), UINT8_C(115),
      UINT8_C( 71), UINT8_C( 66), UINT8_C(180), UINT8_C(181), UINT8_C(100), UINT8_C( 66), UINT8_C(  9), UINT8_C( 12),
      UINT8_C(171), UINT8_C( 53), UINT8_C(116), UINT8_C( 91), UINT8_C(178), UINT8_C(221), UINT8_C(225), UINT8_C(  0),
      UINT8_C(252), UINT8_C(112), UINT8_C(243), UINT8_C( 79), UINT8_C(205), UINT8_C( 46), UINT8_C( 66), UINT8_C(205),
      UINT8_C(130), UINT8_C(176), UINT8_C( 45), UINT8_C(159), UINT8_C(146), UINT8_C( 19), UINT8_C( 18), UINT8_C(218),
      UINT8_C( 85), UINT8_C(198), UINT8_C(143), UINT8_C(185), UINT8_C(  9), UINT8_C(152), UINT8_C(197), UINT8_C(180),
      UINT8_C(205), UINT8_C( 58), UINT8_C( 15), UINT8_C(128), UINT8_C( 23), UINT8_C(240), UINT8_C(128), UINT8_C( 20),
      UINT8_C( 97), UINT8_C(116), UINT8_C( 99), UINT8_C( 46), UINT8_C(162), UINT8_C(165), UINT8_C(251), UINT8_C( 36),
      UINT8_C( 85), UINT8_C( 40), UINT8_C(195), UINT8_C(232), UINT8_C( 59), UINT8_C(213), UINT8_C(194), UINT8_C(145),
      UINT8_C(156), UINT8_C( 81), UINT8_C( 74), UINT8_C(165), UINT8_C(233), UINT8_C( 16), UINT8_C( 89), UINT8_C(183),
      UINT8_C( 74), UINT8_C(104), UINT8_C( 55), UINT8_C( 97), UINT8_C( 88), UINT8_C(183), UINT8_C(117), UINT8_C(185),
      UINT8_C( 43), UINT8_C(216), UINT8_C(232), UINT8_C(205), UINT8_C(126), UINT8_C(227), UINT8_C(242), UINT8_C(211),
      UINT8_C( 12), UINT8_C(181), UINT8_C(187), UINT8_C( 71), UINT8_C(139), UINT8_C(125), UINT8_C(216), UINT8_C( 39),
      UINT8_C(206), UINT8_C( 35), UINT8_C(204), UINT8_C(184), UINT8_C( 51), UINT8_C( 37), UINT8_C(111), UINT8_C(125),
      UINT8_C(141), UINT8_C(166), UINT8_C(222), UINT8_C(229), UINT8_C( 93), UINT8_C( 84), UINT8_C(159), UINT8_C(137),
      UINT8_C( 44), UINT8_C(135), UINT8_C( 86), UINT8_C(170), UINT8_C(106), UINT8_C( 72), UINT8_C(126), UINT8_C(118),
      UINT8_C(254), UINT8_C( 57), UINT8_C(190), UINT8_C(137), UINT8_C(183), UINT8_C(150), UINT8_C(176), UINT8_C(133),
      UINT8_C(185), UINT8_C(124), UINT8_C( 61), UINT8_C(236), UINT8_C(161), UINT8_C(172), UINT8_C(105), UINT8_C( 46),
      UINT8_C( 82), UINT8_C( 72), UINT8_C( 19), UINT8_C(176), UINT8_C(156), UINT8_C(178), UINT8_C( 57), UINT8_C(200),
      UINT8_C( 57), UINT8_C(143), UINT8_C(115), UINT8_C(164), UINT8_C(216), UINT8_C(241), UINT8_C( 26), UINT8_C(214),
      UINT8_C( 42), UINT8_C(216), UINT8_C( 95), UINT8_C(225), UINT8_C(111), UINT8_C( 15), UINT8_C(103), UINT8_C( 40),
      UINT8_C(139), UINT8_C(164), UINT8_C( 21), UINT8_C( 44), UINT8_C( 81), UINT8_C(126), UINT8_C( 90), UINT8_C(163),
      UINT8_C(198), UINT8_C(109), UINT8_C( 83), UINT8_C( 98), UINT8_C( 32), UINT8_C(140), UINT8_C( 43), UINT8_C( 89),
      UINT8_C( 28), UINT8_C(158), UINT8_C(253), UINT8_C(244), UINT8_C(143), UINT8_C( 24), UINT8_C(202), UINT8_C(185),
      UINT8_C(240), UINT8_C( 41), UINT8_C(155), UINT8_C( 95), UINT8_C( 56), UINT8_C(  2), UINT8_C(136), UINT8_C(195),
      UINT8_C(166), UINT8_C(157), UINT8_C(239), UINT8_C(247), UINT8_C( 27), UINT8_C( 73), UINT8_C(155), UINT8_C(226),
      UINT8_C(182), UINT8_C(238), UINT8_C( 68), UINT8_C(214), UINT8_C(123), UINT8_C(111), UINT8_C( 48), UINT8_C(151),
      UINT8_C( 13), UINT8_C( 45), UINT8_C(139), UINT8_C(156), UINT8_C( 69), UINT8_C( 85), UINT8_C( 86), UINT8_C( 54),
      UINT8_C(126), UINT8_C(241), UINT8_C(149), UINT8_C(182), UINT8_C(243), UINT8_C( 29), UINT8_C(121), UINT8_C(153),
      UINT8_C(186), UINT8_C(104), UINT8_C(145), UINT8_C(214), UINT8_C(177), UINT8_C( 44), UINT8_C(184), UINT8_C(103),
      UINT8_C( 26), UINT8_C(252), UINT8_C( 62), UINT8_C(149), UINT8_C(108), UINT8_C(110), UINT8_C( 44), UINT8_C(121),
      UINT8_C(155), UINT8_C(183), UINT8_C( 22), UINT8_C(225), UINT8_C( 12), UINT8_C(108), UINT8_C( 23), UINT8_C(138),
      UINT8_C( 93), UINT8_C(172), UINT8_C( 64), UINT8_C( 80), UINT8_C(202), UINT8_C(185), UINT8_C(233), UINT8_C(132),
      UINT8_C( 33), UINT8_C(122), UINT8_C( 90), UINT8_C(210), UINT8_C(166), UINT8_C( 18) };
  static const uint8_t b = UINT8_C(176);
  static const uint8_t e[] =
    {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(191),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(212),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(205),    UINT8_MAX,    UINT8_MAX, UINT8_C(250), UINT8_C(217),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C(193),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(217), UINT8_C(224),    UINT8_MAX,    UINT8_MAX, UINT8_C(183),    UINT8_MAX,    UINT8_MAX,
      UINT8_C(220), UINT8_C(244),    UINT8_MAX, UINT8_C(186),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(211),
         UINT8_MAX, UINT8_C(225),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(185),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(254), UINT8_C(236), UINT8_C(247),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(190),    UINT8_MAX, UINT8_C(229),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(211), UINT8_C(193), UINT8_C(212), UINT8_C(247),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(218),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(183),    UINT8_MAX, UINT8_C(218), UINT8_C(244),    UINT8_MAX, UINT8_C(212),    UINT8_MAX,
      UINT8_C(224),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(242),
         UINT8_MAX, UINT8_C(192),    UINT8_MAX,    UINT8_MAX, UINT8_C(228),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(221), UINT8_C(233), UINT8_C(213),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(227),
         UINT8_MAX, UINT8_C(207),    UINT8_MAX, UINT8_C(209),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(184),
      UINT8_C(197),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(194), UINT8_C(209),    UINT8_MAX,
      UINT8_C(210),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(228),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(201), UINT8_C(177),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(199),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(187),
      UINT8_C(237),    UINT8_MAX,    UINT8_MAX, UINT8_C(196),    UINT8_MAX, UINT8_C(187),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(205),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(253),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(184),    UINT8_MAX, UINT8_C(237),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(197),    UINT8_MAX, UINT8_C(242),
         UINT8_MAX,    UINT8_MAX, UINT8_C(215),    UINT8_MAX, UINT8_C(209), UINT8_C(199),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(217), UINT8_C(244),    UINT8_MAX,    UINT8_MAX, UINT8_C(220), UINT8_C(253),    UINT8_MAX,
      UINT8_C(181),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(201), UINT8_C(244),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(247),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(206),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(184),    UINT8_MAX,    UINT8_MAX, UINT8_C(210),    UINT8_MAX,    UINT8_MAX, UINT8_C(197),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(205),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(233),    UINT8_MAX,    UINT8_MAX, UINT8_C(222),    UINT8_MAX, UINT8_C(201), UINT8_C(252),
      UINT8_C(210),    UINT8_MAX, UINT8_C(186), UINT8_C(183),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(189),    UINT8_MAX, UINT8_C(176),    UINT8_MAX, UINT8_C(206),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(181),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C(177), UINT8_C(225), UINT8_C(251),    UINT8_MAX, UINT8_C(203),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(244), UINT8_C(192),    UINT8_MAX, UINT8_C(216),
      UINT8_C(205), UINT8_C(228), UINT8_C(216), UINT8_C(194),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(192),    UINT8_MAX, UINT8_C(222),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(238),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(213),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(249), UINT8_C(235),    UINT8_MAX,    UINT8_MAX, UINT8_C(204),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(215), UINT8_C(251),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(243),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(216),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(181),    UINT8_MAX, UINT8_C(249),    UINT8_MAX, UINT8_C(211),
      UINT8_C(237), UINT8_C(181),    UINT8_MAX,    UINT8_MAX, UINT8_C(220), UINT8_C(193),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(182), UINT8_C(210), UINT8_C(179),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(191), UINT8_C(224),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(210),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(200),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(234),    UINT8_MAX,    UINT8_MAX,
      UINT8_C(240),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(226),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(213),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(184),    UINT8_MAX, UINT8_C(252),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(247),    UINT8_MAX, UINT8_C(176),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(184),    UINT8_MAX, UINT8_C(227),    UINT8_MAX, UINT8_C(247),
         UINT8_MAX,    UINT8_MAX, UINT8_C(202),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(241),    UINT8_MAX, UINT8_C(209),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C(219),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(254), UINT8_C(207),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(234),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(204),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(247), UINT8_C(242),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(242), UINT8_C(185), UINT8_C(188),
         UINT8_MAX, UINT8_C(229),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(176),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(222), UINT8_C(242),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C(221),    UINT8_MAX,    UINT8_MAX, UINT8_C(195), UINT8_C(194),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(185),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(234), UINT8_C(191),    UINT8_MAX, UINT8_C(199),    UINT8_MAX,    UINT8_MAX, UINT8_C(196),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(222),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(212),
         UINT8_MAX, UINT8_C(216),    UINT8_MAX,    UINT8_MAX, UINT8_C(235),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C(250),    UINT8_MAX,    UINT8_MAX, UINT8_C(192),    UINT8_MAX,    UINT8_MAX,
      UINT8_C(250),    UINT8_MAX, UINT8_C(231),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(219),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(188),    UINT8_MAX,    UINT8_MAX, UINT8_C(247),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(215),
         UINT8_MAX, UINT8_C(211),    UINT8_MAX,    UINT8_MAX, UINT8_C(227), UINT8_C(213),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(220),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(248),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(233),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C(237),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(222),
         UINT8_MAX, UINT8_C(248), UINT8_C(195),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(233),    UINT8_MAX,
      UINT8_C(233),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(202),    UINT8_MAX,
      UINT8_C(218),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(191),    UINT8_MAX, UINT8_C(216),
         UINT8_MAX,    UINT8_MAX, UINT8_C(197), UINT8_C(220),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(208),    UINT8_MAX, UINT8_C(219),    UINT8_MAX,
      UINT8_C(204),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(200),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX, UINT8_C(217),    UINT8_MAX,    UINT8_MAX, UINT8_C(232), UINT8_C(178),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(203), UINT8_C(249),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C(244),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(224),    UINT8_MAX,
      UINT8_C(189), UINT8_C(221),    UINT8_MAX,    UINT8_MAX, UINT8_C(245),    UINT8_MAX,    UINT8_MAX, UINT8_C(230),
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(205),    UINT8_MAX,    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(220),    UINT8_MAX,    UINT8_MAX,
      UINT8_C(202),    UINT8_MAX, UINT8_C(238),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(220),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C(198),    UINT8_MAX, UINT8_C(188),    UINT8_MAX, UINT8_C(199),    UINT8_MAX,
         UINT8_MAX,    UINT8_MAX, UINT8_C(240),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
      UINT8_C(209),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(194) };

  static uint8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t
      rv,
      av = simde_svld1_u8(pg, &(a[i]));

    rv = simde_svqadd_n_u8(av, b);

    simde_svst1_u8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vu8(len, e, r);

  return 0;
#else
  uint8_t a[1024], b, e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t av, ev;

    av = simde_svld1_u8(pg, &(a[i]));

    ev = simde_svqadd_n_u8(av, b);

    simde_svst1_u8(pg, &(e[i]), ev);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u8(1, b);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const uint16_t a[] =
    { UINT16_C(43447), UINT16_C(36082), UINT16_C(56914), UINT16_C(32273), UINT16_C(61781), UINT16_C(20844), UINT16_C(17135), UINT16_C( 5771),
      UINT16_C(11747), UINT16_C(26720), UINT16_C(11290), UINT16_C(14140), UINT16_C(16187), UINT16_C(59275), UINT16_C(38352), UINT16_C(34567),
      UINT16_C(63806), UINT16_C(36883), UINT16_C( 9432), UINT16_C(11535), UINT16_C(31510), UINT16_C( 1406), UINT16_C( 2493), UINT16_C(40988),
      UINT16_C(31799), UINT16_C(20745), UINT16_C(17832), UINT16_C(58248), UINT16_C( 4997), UINT16_C(21963), UINT16_C(53929), UINT16_C(59356),
      UINT16_C(61644), UINT16_C(42104), UINT16_C(34580), UINT16_C(10961), UINT16_C(20226), UINT16_C(48944), UINT16_C(19544), UINT16_C(36703),
      UINT16_C(26824), UINT16_C(29152), UINT16_C(27054), UINT16_C(13140), UINT16_C( 8060), UINT16_C( 9608), UINT16_C(25842), UINT16_C(48653),
      UINT16_C(34132), UINT16_C(26978), UINT16_C(13068), UINT16_C( 3731), UINT16_C(50050), UINT16_C(56013), UINT16_C(11279), UINT16_C(55402),
      UINT16_C(19093), UINT16_C(17225), UINT16_C(40371), UINT16_C(12406), UINT16_C(65213), UINT16_C(44885), UINT16_C(25186), UINT16_C(46957),
      UINT16_C(53223), UINT16_C(62240), UINT16_C(45826), UINT16_C(33793), UINT16_C(52855), UINT16_C(34398), UINT16_C(51451), UINT16_C(36958),
      UINT16_C(42771), UINT16_C(50899), UINT16_C(18757), UINT16_C(  758), UINT16_C(19527), UINT16_C(43441), UINT16_C( 7854), UINT16_C(38496),
      UINT16_C(33005), UINT16_C(61321), UINT16_C(35636), UINT16_C(43891), UINT16_C(53593), UINT16_C(21553), UINT16_C(37018), UINT16_C(44516),
      UINT16_C(46903), UINT16_C(31859), UINT16_C(27136), UINT16_C(18302), UINT16_C(12214), UINT16_C(25841), UINT16_C(20813), UINT16_C(15098),
      UINT16_C(34002), UINT16_C( 1577), UINT16_C(39951), UINT16_C(26801), UINT16_C(57966), UINT16_C( 2237), UINT16_C(41330), UINT16_C(43701),
      UINT16_C(10329), UINT16_C(22822), UINT16_C(42386), UINT16_C(18593), UINT16_C(37588), UINT16_C( 8877), UINT16_C(42979), UINT16_C(46428),
      UINT16_C(34347), UINT16_C(15035), UINT16_C(27682), UINT16_C(37027), UINT16_C(24655), UINT16_C(49560), UINT16_C(19713), UINT16_C(23147),
      UINT16_C(37494), UINT16_C( 2228), UINT16_C(21815), UINT16_C( 2897), UINT16_C(65255), UINT16_C(51757), UINT16_C(35493), UINT16_C(53632),
      UINT16_C(15120), UINT16_C(12811), UINT16_C(44712), UINT16_C(63427), UINT16_C(23310), UINT16_C( 4280), UINT16_C( 9385), UINT16_C( 8042),
      UINT16_C( 7862), UINT16_C(60711), UINT16_C(30835), UINT16_C(23288), UINT16_C( 9846), UINT16_C( 7205), UINT16_C(42416), UINT16_C(49389),
      UINT16_C(63712), UINT16_C(35058), UINT16_C(46503), UINT16_C(46463), UINT16_C(14353), UINT16_C(47813), UINT16_C(12380), UINT16_C( 4825),
      UINT16_C(   78), UINT16_C(49919), UINT16_C(63353), UINT16_C(61212), UINT16_C(16669), UINT16_C(52491), UINT16_C(63718), UINT16_C(51085),
      UINT16_C(33009), UINT16_C(38991), UINT16_C(53045), UINT16_C(17997), UINT16_C( 4871), UINT16_C(25344), UINT16_C(55619), UINT16_C(37237),
      UINT16_C(29914), UINT16_C(21331), UINT16_C(28779), UINT16_C(35138), UINT16_C(20145), UINT16_C(38998), UINT16_C(58438), UINT16_C(14175),
      UINT16_C(44644), UINT16_C(39375), UINT16_C( 7549), UINT16_C(34016), UINT16_C(57392), UINT16_C(29671), UINT16_C(23738), UINT16_C(37892),
      UINT16_C(22736), UINT16_C(15591), UINT16_C(10696), UINT16_C(31173), UINT16_C( 7031), UINT16_C(48657), UINT16_C(28927), UINT16_C(25589),
      UINT16_C(50463), UINT16_C(40189), UINT16_C(56802), UINT16_C( 4641), UINT16_C( 2237), UINT16_C(30597), UINT16_C(35173), UINT16_C(13579),
      UINT16_C(62177), UINT16_C(43377), UINT16_C(13852), UINT16_C(37667), UINT16_C(13394), UINT16_C(20817), UINT16_C(18341), UINT16_C(50357),
      UINT16_C(45580), UINT16_C(61024), UINT16_C(33167), UINT16_C(19456), UINT16_C(34186), UINT16_C(61380), UINT16_C(53006), UINT16_C(61476),
      UINT16_C(38594), UINT16_C(56985), UINT16_C(48332), UINT16_C( 7793), UINT16_C(50161), UINT16_C(38512), UINT16_C( 9482), UINT16_C( 5722),
      UINT16_C(47831), UINT16_C(26116), UINT16_C( 1084), UINT16_C(50866), UINT16_C(30345), UINT16_C(38837), UINT16_C(55622), UINT16_C( 2183),
      UINT16_C( 8559), UINT16_C(15590), UINT16_C(22493), UINT16_C(52826), UINT16_C(51738), UINT16_C( 9316), UINT16_C(48879), UINT16_C(50746),
      UINT16_C(15993), UINT16_C(46380), UINT16_C(57154), UINT16_C(52091), UINT16_C(12373), UINT16_C(39779), UINT16_C(59913), UINT16_C(31139),
      UINT16_C(35083), UINT16_C(59829), UINT16_C( 4065), UINT16_C(64439), UINT16_C( 7386), UINT16_C(51488), UINT16_C(23258), UINT16_C(21392),
      UINT16_C(48281), UINT16_C(56072), UINT16_C(33691), UINT16_C(61863), UINT16_C( 2739), UINT16_C(48524), UINT16_C(12532), UINT16_C(   54),
      UINT16_C(60345), UINT16_C(39657), UINT16_C(41210), UINT16_C(54422), UINT16_C(46780), UINT16_C(38814), UINT16_C(11792), UINT16_C(43498),
      UINT16_C(62442), UINT16_C(34437), UINT16_C(11382), UINT16_C(10871), UINT16_C(  822), UINT16_C(10983), UINT16_C( 7475), UINT16_C(60714),
      UINT16_C( 4872), UINT16_C(  647), UINT16_C( 7604), UINT16_C(28887), UINT16_C(30163), UINT16_C(58375), UINT16_C(62115), UINT16_C(36237),
      UINT16_C( 4837), UINT16_C(23315), UINT16_C(35390), UINT16_C(29829), UINT16_C(27790), UINT16_C(49567), UINT16_C(51593), UINT16_C(37294),
      UINT16_C(14045), UINT16_C(37268), UINT16_C(27475), UINT16_C( 9985), UINT16_C( 2528), UINT16_C(33547), UINT16_C(39163), UINT16_C(57360),
      UINT16_C( 9387), UINT16_C(59707), UINT16_C(49582), UINT16_C(15454), UINT16_C(64813), UINT16_C(47102), UINT16_C(44230), UINT16_C(41800),
      UINT16_C(56546), UINT16_C(13876), UINT16_C(13895), UINT16_C(10077), UINT16_C(26687), UINT16_C(15018), UINT16_C(47872), UINT16_C(43802),
      UINT16_C(21983), UINT16_C(36245), UINT16_C(62230), UINT16_C(17610), UINT16_C(51440), UINT16_C(46843), UINT16_C(17268), UINT16_C(22362),
      UINT16_C(36384), UINT16_C(26509), UINT16_C(60100), UINT16_C(  911), UINT16_C(14674), UINT16_C(21053), UINT16_C(22516), UINT16_C(54270),
      UINT16_C(37805), UINT16_C(50017), UINT16_C(11142), UINT16_C(30215), UINT16_C(  755), UINT16_C(26412), UINT16_C(34374), UINT16_C(26302),
      UINT16_C(19221), UINT16_C(55757), UINT16_C(23605), UINT16_C(34781), UINT16_C( 6806), UINT16_C(35546), UINT16_C(55410), UINT16_C( 8030),
      UINT16_C(49003), UINT16_C(61922), UINT16_C(60138), UINT16_C(56679), UINT16_C(37868), UINT16_C(12868), UINT16_C(  794), UINT16_C(12184),
      UINT16_C(26190), UINT16_C(33800), UINT16_C(58818), UINT16_C(22539), UINT16_C(58624), UINT16_C(29411), UINT16_C(16829), UINT16_C(10385),
      UINT16_C(29440), UINT16_C(59929), UINT16_C(32861), UINT16_C(19143), UINT16_C( 2836), UINT16_C(11900), UINT16_C( 5390), UINT16_C(23901),
      UINT16_C(25979), UINT16_C(15841), UINT16_C(60491), UINT16_C(19350), UINT16_C(31186), UINT16_C(36797), UINT16_C(20154), UINT16_C(47800),
      UINT16_C(53697), UINT16_C( 8100), UINT16_C(27474), UINT16_C(26217), UINT16_C(58742), UINT16_C(34196), UINT16_C(61946), UINT16_C(30178),
      UINT16_C(50006), UINT16_C(41395), UINT16_C(18863), UINT16_C(33260), UINT16_C(43458), UINT16_C(31761), UINT16_C(51703), UINT16_C(47414),
      UINT16_C(55962), UINT16_C(60632), UINT16_C(16709), UINT16_C(47954), UINT16_C(58918), UINT16_C( 8512), UINT16_C( 8919), UINT16_C(11926),
      UINT16_C(18917), UINT16_C(38351), UINT16_C(48274), UINT16_C(21526), UINT16_C(10085), UINT16_C(24016), UINT16_C( 1776), UINT16_C(35606),
      UINT16_C(61152), UINT16_C( 9591), UINT16_C(51759), UINT16_C(21985), UINT16_C( 8624), UINT16_C(34934), UINT16_C( 3396), UINT16_C(10678),
      UINT16_C(34134), UINT16_C(59838), UINT16_C(54593), UINT16_C(42813) };
  static const uint16_t b = UINT16_C( 8940);
  static const uint16_t e[] =
    { UINT16_C(52387), UINT16_C(45022),      UINT16_MAX, UINT16_C(41213),      UINT16_MAX, UINT16_C(29784), UINT16_C(26075), UINT16_C(14711),
      UINT16_C(20687), UINT16_C(35660), UINT16_C(20230), UINT16_C(23080), UINT16_C(25127),      UINT16_MAX, UINT16_C(47292), UINT16_C(43507),
           UINT16_MAX, UINT16_C(45823), UINT16_C(18372), UINT16_C(20475), UINT16_C(40450), UINT16_C(10346), UINT16_C(11433), UINT16_C(49928),
      UINT16_C(40739), UINT16_C(29685), UINT16_C(26772),      UINT16_MAX, UINT16_C(13937), UINT16_C(30903), UINT16_C(62869),      UINT16_MAX,
           UINT16_MAX, UINT16_C(51044), UINT16_C(43520), UINT16_C(19901), UINT16_C(29166), UINT16_C(57884), UINT16_C(28484), UINT16_C(45643),
      UINT16_C(35764), UINT16_C(38092), UINT16_C(35994), UINT16_C(22080), UINT16_C(17000), UINT16_C(18548), UINT16_C(34782), UINT16_C(57593),
      UINT16_C(43072), UINT16_C(35918), UINT16_C(22008), UINT16_C(12671), UINT16_C(58990), UINT16_C(64953), UINT16_C(20219), UINT16_C(64342),
      UINT16_C(28033), UINT16_C(26165), UINT16_C(49311), UINT16_C(21346),      UINT16_MAX, UINT16_C(53825), UINT16_C(34126), UINT16_C(55897),
      UINT16_C(62163),      UINT16_MAX, UINT16_C(54766), UINT16_C(42733), UINT16_C(61795), UINT16_C(43338), UINT16_C(60391), UINT16_C(45898),
      UINT16_C(51711), UINT16_C(59839), UINT16_C(27697), UINT16_C( 9698), UINT16_C(28467), UINT16_C(52381), UINT16_C(16794), UINT16_C(47436),
      UINT16_C(41945),      UINT16_MAX, UINT16_C(44576), UINT16_C(52831), UINT16_C(62533), UINT16_C(30493), UINT16_C(45958), UINT16_C(53456),
      UINT16_C(55843), UINT16_C(40799), UINT16_C(36076), UINT16_C(27242), UINT16_C(21154), UINT16_C(34781), UINT16_C(29753), UINT16_C(24038),
      UINT16_C(42942), UINT16_C(10517), UINT16_C(48891), UINT16_C(35741),      UINT16_MAX, UINT16_C(11177), UINT16_C(50270), UINT16_C(52641),
      UINT16_C(19269), UINT16_C(31762), UINT16_C(51326), UINT16_C(27533), UINT16_C(46528), UINT16_C(17817), UINT16_C(51919), UINT16_C(55368),
      UINT16_C(43287), UINT16_C(23975), UINT16_C(36622), UINT16_C(45967), UINT16_C(33595), UINT16_C(58500), UINT16_C(28653), UINT16_C(32087),
      UINT16_C(46434), UINT16_C(11168), UINT16_C(30755), UINT16_C(11837),      UINT16_MAX, UINT16_C(60697), UINT16_C(44433), UINT16_C(62572),
      UINT16_C(24060), UINT16_C(21751), UINT16_C(53652),      UINT16_MAX, UINT16_C(32250), UINT16_C(13220), UINT16_C(18325), UINT16_C(16982),
      UINT16_C(16802),      UINT16_MAX, UINT16_C(39775), UINT16_C(32228), UINT16_C(18786), UINT16_C(16145), UINT16_C(51356), UINT16_C(58329),
           UINT16_MAX, UINT16_C(43998), UINT16_C(55443), UINT16_C(55403), UINT16_C(23293), UINT16_C(56753), UINT16_C(21320), UINT16_C(13765),
      UINT16_C( 9018), UINT16_C(58859),      UINT16_MAX,      UINT16_MAX, UINT16_C(25609), UINT16_C(61431),      UINT16_MAX, UINT16_C(60025),
      UINT16_C(41949), UINT16_C(47931), UINT16_C(61985), UINT16_C(26937), UINT16_C(13811), UINT16_C(34284), UINT16_C(64559), UINT16_C(46177),
      UINT16_C(38854), UINT16_C(30271), UINT16_C(37719), UINT16_C(44078), UINT16_C(29085), UINT16_C(47938),      UINT16_MAX, UINT16_C(23115),
      UINT16_C(53584), UINT16_C(48315), UINT16_C(16489), UINT16_C(42956),      UINT16_MAX, UINT16_C(38611), UINT16_C(32678), UINT16_C(46832),
      UINT16_C(31676), UINT16_C(24531), UINT16_C(19636), UINT16_C(40113), UINT16_C(15971), UINT16_C(57597), UINT16_C(37867), UINT16_C(34529),
      UINT16_C(59403), UINT16_C(49129),      UINT16_MAX, UINT16_C(13581), UINT16_C(11177), UINT16_C(39537), UINT16_C(44113), UINT16_C(22519),
           UINT16_MAX, UINT16_C(52317), UINT16_C(22792), UINT16_C(46607), UINT16_C(22334), UINT16_C(29757), UINT16_C(27281), UINT16_C(59297),
      UINT16_C(54520),      UINT16_MAX, UINT16_C(42107), UINT16_C(28396), UINT16_C(43126),      UINT16_MAX, UINT16_C(61946),      UINT16_MAX,
      UINT16_C(47534),      UINT16_MAX, UINT16_C(57272), UINT16_C(16733), UINT16_C(59101), UINT16_C(47452), UINT16_C(18422), UINT16_C(14662),
      UINT16_C(56771), UINT16_C(35056), UINT16_C(10024), UINT16_C(59806), UINT16_C(39285), UINT16_C(47777), UINT16_C(64562), UINT16_C(11123),
      UINT16_C(17499), UINT16_C(24530), UINT16_C(31433), UINT16_C(61766), UINT16_C(60678), UINT16_C(18256), UINT16_C(57819), UINT16_C(59686),
      UINT16_C(24933), UINT16_C(55320),      UINT16_MAX, UINT16_C(61031), UINT16_C(21313), UINT16_C(48719),      UINT16_MAX, UINT16_C(40079),
      UINT16_C(44023),      UINT16_MAX, UINT16_C(13005),      UINT16_MAX, UINT16_C(16326), UINT16_C(60428), UINT16_C(32198), UINT16_C(30332),
      UINT16_C(57221), UINT16_C(65012), UINT16_C(42631),      UINT16_MAX, UINT16_C(11679), UINT16_C(57464), UINT16_C(21472), UINT16_C( 8994),
           UINT16_MAX, UINT16_C(48597), UINT16_C(50150), UINT16_C(63362), UINT16_C(55720), UINT16_C(47754), UINT16_C(20732), UINT16_C(52438),
           UINT16_MAX, UINT16_C(43377), UINT16_C(20322), UINT16_C(19811), UINT16_C( 9762), UINT16_C(19923), UINT16_C(16415),      UINT16_MAX,
      UINT16_C(13812), UINT16_C( 9587), UINT16_C(16544), UINT16_C(37827), UINT16_C(39103),      UINT16_MAX,      UINT16_MAX, UINT16_C(45177),
      UINT16_C(13777), UINT16_C(32255), UINT16_C(44330), UINT16_C(38769), UINT16_C(36730), UINT16_C(58507), UINT16_C(60533), UINT16_C(46234),
      UINT16_C(22985), UINT16_C(46208), UINT16_C(36415), UINT16_C(18925), UINT16_C(11468), UINT16_C(42487), UINT16_C(48103),      UINT16_MAX,
      UINT16_C(18327),      UINT16_MAX, UINT16_C(58522), UINT16_C(24394),      UINT16_MAX, UINT16_C(56042), UINT16_C(53170), UINT16_C(50740),
      UINT16_C(65486), UINT16_C(22816), UINT16_C(22835), UINT16_C(19017), UINT16_C(35627), UINT16_C(23958), UINT16_C(56812), UINT16_C(52742),
      UINT16_C(30923), UINT16_C(45185),      UINT16_MAX, UINT16_C(26550), UINT16_C(60380), UINT16_C(55783), UINT16_C(26208), UINT16_C(31302),
      UINT16_C(45324), UINT16_C(35449),      UINT16_MAX, UINT16_C( 9851), UINT16_C(23614), UINT16_C(29993), UINT16_C(31456), UINT16_C(63210),
      UINT16_C(46745), UINT16_C(58957), UINT16_C(20082), UINT16_C(39155), UINT16_C( 9695), UINT16_C(35352), UINT16_C(43314), UINT16_C(35242),
      UINT16_C(28161), UINT16_C(64697), UINT16_C(32545), UINT16_C(43721), UINT16_C(15746), UINT16_C(44486), UINT16_C(64350), UINT16_C(16970),
      UINT16_C(57943),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(46808), UINT16_C(21808), UINT16_C( 9734), UINT16_C(21124),
      UINT16_C(35130), UINT16_C(42740),      UINT16_MAX, UINT16_C(31479),      UINT16_MAX, UINT16_C(38351), UINT16_C(25769), UINT16_C(19325),
      UINT16_C(38380),      UINT16_MAX, UINT16_C(41801), UINT16_C(28083), UINT16_C(11776), UINT16_C(20840), UINT16_C(14330), UINT16_C(32841),
      UINT16_C(34919), UINT16_C(24781),      UINT16_MAX, UINT16_C(28290), UINT16_C(40126), UINT16_C(45737), UINT16_C(29094), UINT16_C(56740),
      UINT16_C(62637), UINT16_C(17040), UINT16_C(36414), UINT16_C(35157),      UINT16_MAX, UINT16_C(43136),      UINT16_MAX, UINT16_C(39118),
      UINT16_C(58946), UINT16_C(50335), UINT16_C(27803), UINT16_C(42200), UINT16_C(52398), UINT16_C(40701), UINT16_C(60643), UINT16_C(56354),
      UINT16_C(64902),      UINT16_MAX, UINT16_C(25649), UINT16_C(56894),      UINT16_MAX, UINT16_C(17452), UINT16_C(17859), UINT16_C(20866),
      UINT16_C(27857), UINT16_C(47291), UINT16_C(57214), UINT16_C(30466), UINT16_C(19025), UINT16_C(32956), UINT16_C(10716), UINT16_C(44546),
           UINT16_MAX, UINT16_C(18531), UINT16_C(60699), UINT16_C(30925), UINT16_C(17564), UINT16_C(43874), UINT16_C(12336), UINT16_C(19618),
      UINT16_C(43074),      UINT16_MAX, UINT16_C(63533), UINT16_C(51753) };

  static uint16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t
      rv,
      av = simde_svld1_u16(pg, &(a[i]));

    rv = simde_svqadd_n_u16(av, b);

    simde_svst1_u16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vu16(len, e, r);

  return 0;
#else
  uint16_t a[1024 / sizeof(int16_t)], b, e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u16();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t av, ev;

    av = simde_svld1_u16(pg, &(a[i]));

    ev = simde_svqadd_n_u16(av, b);

    simde_svst1_u16(pg, &(e[i]), ev);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u16(1, b);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const uint32_t a[] =
    { UINT32_C(4247609450), UINT32_C(  37739268), UINT32_C(3252746025), UINT32_C(1178801714), UINT32_C( 827752125), UINT32_C(3654468009), UINT32_C(2616966726), UINT32_C( 334618281),
      UINT32_C(1108352574), UINT32_C( 591679481), UINT32_C(2044994631), UINT32_C(4173276987), UINT32_C(1311380901), UINT32_C( 472382678), UINT32_C(1689789371), UINT32_C(1064806657),
      UINT32_C(3246491848), UINT32_C( 518309591), UINT32_C( 630704362), UINT32_C(2485016303), UINT32_C(1122191468), UINT32_C(4284418628), UINT32_C( 778245933), UINT32_C(2288901056),
      UINT32_C( 977989475), UINT32_C(2673422005), UINT32_C(3871731959), UINT32_C(3011240775), UINT32_C(1878351403), UINT32_C(2523878504), UINT32_C( 751096427), UINT32_C( 280244909),
      UINT32_C(3595304481), UINT32_C( 611689517), UINT32_C(3674880660), UINT32_C(1217299741), UINT32_C(1287161059), UINT32_C(1155672024), UINT32_C(2809177849), UINT32_C(4189529304),
      UINT32_C(1355743779), UINT32_C( 997475750), UINT32_C(2635497087), UINT32_C(3890586884), UINT32_C(  20159785), UINT32_C(3192198596), UINT32_C(2489693628), UINT32_C(4253949146),
      UINT32_C(3310181663), UINT32_C( 570474914), UINT32_C(1136596799), UINT32_C(3844842684), UINT32_C( 115760706), UINT32_C( 818162804), UINT32_C(3150195169), UINT32_C(1706578502),
      UINT32_C(1378485680), UINT32_C( 108276678), UINT32_C(4266210114), UINT32_C( 451114200), UINT32_C(1193331155), UINT32_C(3614959093), UINT32_C(1418869518), UINT32_C(1052330894),
      UINT32_C( 395371600), UINT32_C(1360856335), UINT32_C( 273638968), UINT32_C(2922001115), UINT32_C(4059384827), UINT32_C(1053322288), UINT32_C( 898849447), UINT32_C(4134751397),
      UINT32_C(1057817648), UINT32_C(1099966985), UINT32_C(1800593296), UINT32_C( 219773969), UINT32_C(4160622279), UINT32_C( 574015098), UINT32_C(3327641888), UINT32_C(1186777877),
      UINT32_C(3632646607), UINT32_C(2199459571), UINT32_C( 133131253), UINT32_C(2937325800), UINT32_C(2443645463), UINT32_C(4172537304), UINT32_C(3149794214), UINT32_C(2768337622),
      UINT32_C( 914196291), UINT32_C(2461701789), UINT32_C(3935938818), UINT32_C(3365514673), UINT32_C(2539274431), UINT32_C(3280997661), UINT32_C(4001320472), UINT32_C( 210993353),
      UINT32_C(2755858439), UINT32_C(2839018919), UINT32_C(1469304998), UINT32_C(1025518718), UINT32_C(2329246317), UINT32_C(2689492359), UINT32_C(2089733555), UINT32_C(1435050573),
      UINT32_C(3657026610), UINT32_C(1870803145), UINT32_C(2143687937), UINT32_C(2948392514), UINT32_C(3896086880), UINT32_C(2861074422), UINT32_C(2720405076), UINT32_C(1811394360),
      UINT32_C(1145368699), UINT32_C( 582207265), UINT32_C( 513899228), UINT32_C(3251461472), UINT32_C(3853060079), UINT32_C(3817812366), UINT32_C(2156246599), UINT32_C(3790306405),
      UINT32_C(2368024428), UINT32_C(3551517174), UINT32_C(3018936403), UINT32_C(2641674158), UINT32_C(1417813446), UINT32_C(2520191566), UINT32_C( 756464840), UINT32_C(2769158456),
      UINT32_C( 657601584), UINT32_C(1627054605), UINT32_C(3759401778), UINT32_C(1887275178), UINT32_C(4106551461), UINT32_C(3666541586), UINT32_C(4043808953), UINT32_C(3516274337),
      UINT32_C(1475922250), UINT32_C(3719819947), UINT32_C(2294205150), UINT32_C(4177083218), UINT32_C(1307360827), UINT32_C(1931966138), UINT32_C(3076861718), UINT32_C(2408119109),
      UINT32_C(1877377476), UINT32_C(1364041075), UINT32_C(3134851943), UINT32_C(2192757574), UINT32_C(1271897745), UINT32_C( 717223700), UINT32_C(1809916966), UINT32_C(3841616159),
      UINT32_C(1582555370), UINT32_C(3836715133), UINT32_C(4070476203), UINT32_C(3983822940), UINT32_C(  37307374), UINT32_C(1613559866), UINT32_C(1003162908), UINT32_C(1629472119),
      UINT32_C( 582972325), UINT32_C(3204935443), UINT32_C(1437705720), UINT32_C(3829540342), UINT32_C(2749856616), UINT32_C(2399343475), UINT32_C(2563493665), UINT32_C( 989457044),
      UINT32_C(1901902173), UINT32_C( 540042024), UINT32_C(4285915401), UINT32_C(1860417542), UINT32_C(2802960947), UINT32_C(4281734622), UINT32_C(2023162340), UINT32_C(1236439276),
      UINT32_C(1908019017), UINT32_C(2073225842), UINT32_C(3514435531), UINT32_C(4081082047), UINT32_C( 110776616), UINT32_C(1241895014), UINT32_C(3200490706), UINT32_C(1980200237),
      UINT32_C(4159226500), UINT32_C(2020768428), UINT32_C(1095363969), UINT32_C(1932822859), UINT32_C(1098567387), UINT32_C(1888255902), UINT32_C(1227771676), UINT32_C(1237268164),
      UINT32_C(2755700728), UINT32_C(2736566817), UINT32_C(3940837023), UINT32_C(3395164399), UINT32_C(2215434470), UINT32_C(1945475159), UINT32_C(2881233895), UINT32_C(1374977113),
      UINT32_C(1173763107), UINT32_C(2263356135), UINT32_C(1752288376), UINT32_C(3392327652), UINT32_C(4266540711), UINT32_C(3178382294), UINT32_C(3228118631), UINT32_C(3457310122),
      UINT32_C(2031290514), UINT32_C(2483026714), UINT32_C(2885382343), UINT32_C(3866438975), UINT32_C(1122354028) };
  static const uint32_t b = UINT32_C(4077696055);
  static const uint32_t e[] =
    {           UINT32_MAX, UINT32_C(4115435323),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(4097855840),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(4193456761),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX, UINT32_C(4185972733),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX, UINT32_C(4210827308),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(4288689408),
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(4115003429),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(4188472671),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX };

  static uint32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t
      rv,
      av = simde_svld1_u32(pg, &(a[i]));

    rv = simde_svqadd_n_u32(av, b);

    simde_svst1_u32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vu32(len, e, r);

  return 0;
#else
  uint32_t a[1024 / sizeof(int32_t)], b, e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u32();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t av, ev;

    av = simde_svld1_u32(pg, &(a[i]));

    ev = simde_svqadd_n_u32(av, b);

    simde_svst1_u32(pg, &(e[i]), ev);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u32(1, b);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svqadd_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const uint64_t a[] =
    { UINT64_C(17501278882600856611), UINT64_C( 9691744544867369251), UINT64_C(17565028916636052828), UINT64_C( 1709523927352921913),
      UINT64_C( 6844619561352311454), UINT64_C(18235461513624199738), UINT64_C( 6664259975330832332), UINT64_C( 8291248779268809220),
      UINT64_C( 6573418317447243936), UINT64_C( 4952542838184614171), UINT64_C( 7356146630217444502), UINT64_C(15777076212366560171),
      UINT64_C(  365898682340831383), UINT64_C( 9710741494406707463), UINT64_C( 9471165502245081000), UINT64_C(15363174976526208801),
      UINT64_C(16020889195581925735), UINT64_C( 4184161342579349402), UINT64_C(14414814763479749040), UINT64_C( 7753042436483649156),
      UINT64_C( 7059130487737689665), UINT64_C( 2735372130314900520), UINT64_C( 8340588375705467471), UINT64_C( 8878511566815158982),
      UINT64_C( 3178848660646785781), UINT64_C( 6303311081823996639), UINT64_C(11851520241136707094), UINT64_C( 8333247547303702512),
      UINT64_C(11729147782033783190), UINT64_C(11580566127641013591), UINT64_C(  222679775471535509), UINT64_C(13961391023468742350),
      UINT64_C(10624591015997861644), UINT64_C( 7996046410073139662), UINT64_C( 9927334063438405038), UINT64_C(15162096875493323391),
      UINT64_C(12994316380699542917), UINT64_C(11512330882531477630), UINT64_C( 2226225857672816288), UINT64_C(15541696166273465111),
      UINT64_C(16542546511168885495), UINT64_C( 4811533948334874166), UINT64_C( 7089655697236698790), UINT64_C( 6082373378105092671),
      UINT64_C( 2777811603762053440), UINT64_C( 7946342916833527907), UINT64_C(12242778758795486778), UINT64_C( 6192909176326989376),
      UINT64_C( 5384486457211429795), UINT64_C( 6163060753429366353), UINT64_C(10489097184888896125), UINT64_C( 1248376078971358184),
      UINT64_C( 3131230828217258050), UINT64_C(15551998627278013283), UINT64_C( 6406457809566608646), UINT64_C( 8617822834830677530),
      UINT64_C(18301807111599832312), UINT64_C( 1444052449114145240), UINT64_C( 3585801088368625915), UINT64_C(13336655763561060457),
      UINT64_C(11683613735134147982), UINT64_C(16855811143473864650), UINT64_C( 1364616704903370407), UINT64_C( 9847901216769616175),
      UINT64_C( 9865087422456411515), UINT64_C( 4704655887172615028), UINT64_C(16527629769462750881), UINT64_C( 5628232706024607384),
      UINT64_C( 1511936929465355189), UINT64_C( 5121086069696453174), UINT64_C(11023104346590154846), UINT64_C(  224976910234144509),
      UINT64_C( 7189558296225166098), UINT64_C( 6537050710149905611), UINT64_C( 4029990737510550101), UINT64_C( 8252608137665190198),
      UINT64_C( 4137659540485570010), UINT64_C( 4070799840884989735), UINT64_C( 9952246356134194348), UINT64_C( 2839120772848297364),
      UINT64_C(11401313767560022930), UINT64_C(17533991394128094265), UINT64_C(17441023392694788908), UINT64_C( 4579682178738559003),
      UINT64_C(10515194125173636568), UINT64_C( 2059839306858409821), UINT64_C( 9239037213975277543), UINT64_C( 4732287503647120831),
      UINT64_C(13987474992297733172), UINT64_C(13202861753389927469), UINT64_C( 4346311726581208427), UINT64_C(16499875877319424336),
      UINT64_C( 3992596142250560321), UINT64_C( 3882258778209701465), UINT64_C( 6853168083163864162) };
  static const uint64_t b = UINT64_C(11721660977762247054);
  static const uint64_t e[] =
    {                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX, UINT64_C(13431184905115168967),
                          UINT64_MAX,                     UINT64_MAX, UINT64_C(18385920953093079386),                     UINT64_MAX,
      UINT64_C(18295079295209490990), UINT64_C(16674203815946861225),                     UINT64_MAX,                     UINT64_MAX,
      UINT64_C(12087559660103078437),                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,
                          UINT64_MAX, UINT64_C(15905822320341596456),                     UINT64_MAX,                     UINT64_MAX,
                          UINT64_MAX, UINT64_C(14457033108077147574),                     UINT64_MAX,                     UINT64_MAX,
      UINT64_C(14900509638409032835), UINT64_C(18024972059586243693),                     UINT64_MAX,                     UINT64_MAX,
                          UINT64_MAX,                     UINT64_MAX, UINT64_C(11944340753233782563),                     UINT64_MAX,
                          UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX,
                          UINT64_MAX,                     UINT64_MAX, UINT64_C(13947886835435063342),                     UINT64_MAX,
                          UINT64_MAX, UINT64_C(16533194926097121220),                     UINT64_MAX, UINT64_C(17804034355867339725),
      UINT64_C(14499472581524300494),                     UINT64_MAX,                     UINT64_MAX, UINT64_C(17914570154089236430),
      UINT64_C(17106147434973676849), UINT64_C(17884721731191613407),                     UINT64_MAX, UINT64_C(12970037056733605238),
      UINT64_C(14852891805979505104),                     UINT64_MAX, UINT64_C(18128118787328855700),                     UINT64_MAX,
                          UINT64_MAX, UINT64_C(13165713426876392294), UINT64_C(15307462066130872969),                     UINT64_MAX,
                          UINT64_MAX,                     UINT64_MAX, UINT64_C(13086277682665617461),                     UINT64_MAX,
                          UINT64_MAX, UINT64_C(16426316864934862082),                     UINT64_MAX, UINT64_C(17349893683786854438),
      UINT64_C(13233597907227602243), UINT64_C(16842747047458700228),                     UINT64_MAX, UINT64_C(11946637887996391563),
                          UINT64_MAX, UINT64_C(18258711687912152665), UINT64_C(15751651715272797155),                     UINT64_MAX,
      UINT64_C(15859320518247817064), UINT64_C(15792460818647236789),                     UINT64_MAX, UINT64_C(14560781750610544418),
                          UINT64_MAX,                     UINT64_MAX,                     UINT64_MAX, UINT64_C(16301343156500806057),
                          UINT64_MAX, UINT64_C(13781500284620656875),                     UINT64_MAX, UINT64_C(16453948481409367885),
                          UINT64_MAX,                     UINT64_MAX, UINT64_C(16067972704343455481),                     UINT64_MAX,
      UINT64_C(15714257120012807375), UINT64_C(15603919755971948519),                     UINT64_MAX };

  static uint64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t
      rv,
      av = simde_svld1_u64(pg, &(a[i]));

    rv = simde_svqadd_n_u64(av, b);

    simde_svst1_u64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vu64(len, e, r);

  return 0;
#else
  uint64_t a[1024 / sizeof(int64_t)], b, e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u64();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t av, ev;

    av = simde_svld1_u64(pg, &(a[i]));

    ev = simde_svqadd_n_u64(av, b);

    simde_svst1_u64(pg, &(e[i]), ev);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u64(1, b);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(svqadd_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-sve-footer.h"
