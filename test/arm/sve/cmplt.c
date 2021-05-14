#define SIMDE_TEST_ARM_SVE_INSN cmplt

#include "test-sve.h"
#include "../../../simde/arm/sve/cmplt.h"
#include "../../../simde/arm/sve/dup.h"

static int
test_simde_svcmplt_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) };
  static const int8_t a[] =
    {  INT8_C(  54),  INT8_C(  10), -INT8_C( 112),  INT8_C(  90),  INT8_C(  89),  INT8_C( 123), -INT8_C(  83), -INT8_C(  50),
       INT8_C(  30), -INT8_C(  73),  INT8_C(  71), -INT8_C(  95),  INT8_C( 107),  INT8_C(  76), -INT8_C(  29), -INT8_C( 109),
       INT8_C(  33), -INT8_C(  20),  INT8_C(   3),  INT8_C( 110), -INT8_C(  87),  INT8_C(  68),  INT8_C(  72),  INT8_C(  73),
       INT8_C(   9),  INT8_C(   5),  INT8_C( 103), -INT8_C(  21),  INT8_C( 111),  INT8_C( 120), -INT8_C(   1), -INT8_C(  91),
      -INT8_C( 126), -INT8_C( 113),  INT8_C(   0), -INT8_C(  37),  INT8_C(  10), -INT8_C(  83), -INT8_C(  87),  INT8_C(  40),
       INT8_C( 100), -INT8_C(  16), -INT8_C(  54), -INT8_C(  49),  INT8_C(  61), -INT8_C(  83),  INT8_C(  98),  INT8_C(  94),
      -INT8_C( 103),  INT8_C( 102), -INT8_C(  51),  INT8_C(  66), -INT8_C(  86),  INT8_C(  21), -INT8_C( 117), -INT8_C(  77),
       INT8_C(  26), -INT8_C(  14), -INT8_C(  98), -INT8_C( 119),  INT8_C( 106), -INT8_C(  99),  INT8_C(  46), -INT8_C(  19),
       INT8_C(  45),  INT8_C(  46), -INT8_C(  56),  INT8_C(  55), -INT8_C(  37),  INT8_C( 114),  INT8_C(  96),  INT8_C(  63),
       INT8_C(  98),  INT8_C(  42),  INT8_C(  14), -INT8_C(  97), -INT8_C(  41),  INT8_C( 113), -INT8_C(   2),  INT8_C( 113),
      -INT8_C(  41), -INT8_C(  53), -INT8_C(  77), -INT8_C( 127), -INT8_C(  32),  INT8_C(  63),  INT8_C(  52), -INT8_C(   6),
       INT8_C(  49), -INT8_C(  46), -INT8_C( 125), -INT8_C( 100),  INT8_C( 111), -INT8_C(  79), -INT8_C( 119), -INT8_C( 100),
      -INT8_C(  32),  INT8_C(  81), -INT8_C(  44), -INT8_C(  69), -INT8_C(  61),  INT8_C(  52), -INT8_C(   5),  INT8_C(  38),
       INT8_C(  94),  INT8_C(   9), -INT8_C(  59),  INT8_C(  53),  INT8_C( 122), -INT8_C(  61), -INT8_C(  90),  INT8_C(  81),
      -INT8_C( 114),  INT8_C(  90), -INT8_C(  46),  INT8_C( 110), -INT8_C( 103),  INT8_C(   6),  INT8_C( 104), -INT8_C(  54),
      -INT8_C(  40), -INT8_C(  21),  INT8_C( 102),  INT8_C(  72), -INT8_C(  99), -INT8_C(  17), -INT8_C(  28),  INT8_C( 125),
       INT8_C(  65), -INT8_C(  72),  INT8_C(  56),  INT8_C(   4), -INT8_C(  20),  INT8_C(  51),  INT8_C(  42),  INT8_C(  74),
       INT8_C(  61), -INT8_C(  16),      INT8_MIN, -INT8_C(  73), -INT8_C(  77),  INT8_C(  38),  INT8_C(   9),  INT8_C(  66),
           INT8_MIN, -INT8_C(  37), -INT8_C(  80),  INT8_C(  25), -INT8_C(  30),  INT8_C(  25), -INT8_C(  28), -INT8_C(  70),
       INT8_C(   4),  INT8_C(  74),  INT8_C(   2), -INT8_C(  95),  INT8_C(  58), -INT8_C(  25),  INT8_C(  30),  INT8_C( 123),
      -INT8_C(  97),  INT8_C(  87),      INT8_MAX, -INT8_C( 116), -INT8_C( 118), -INT8_C(  86), -INT8_C(  42), -INT8_C(  57),
      -INT8_C( 102),  INT8_C(  86),      INT8_MAX,  INT8_C(  77),  INT8_C( 125), -INT8_C( 120), -INT8_C( 113), -INT8_C(   3),
       INT8_C(  99),  INT8_C(  64),  INT8_C(  23),  INT8_C(  69),  INT8_C(  89), -INT8_C(   5),  INT8_C(   0),  INT8_C(  93),
       INT8_C(  69),  INT8_C(   2), -INT8_C(   1),      INT8_MAX, -INT8_C(  23),  INT8_C(  29), -INT8_C(   6), -INT8_C( 119),
       INT8_C( 116),  INT8_C( 122),  INT8_C(  21), -INT8_C(   1),  INT8_C(  36), -INT8_C(  21), -INT8_C(  58), -INT8_C(  66),
       INT8_C(  66),  INT8_C(  69),  INT8_C(  11), -INT8_C(  65), -INT8_C(  51), -INT8_C( 101), -INT8_C(  68),  INT8_C(  49),
      -INT8_C(  37), -INT8_C(  45),  INT8_C( 118),  INT8_C(  52), -INT8_C(  50),  INT8_C( 118), -INT8_C( 111),  INT8_C(  20),
       INT8_C( 121), -INT8_C( 112), -INT8_C( 109),  INT8_C(  98), -INT8_C(  82), -INT8_C( 114), -INT8_C(  21),  INT8_C(  34),
       INT8_C(   8),  INT8_C(   0),  INT8_C(  33),  INT8_C(  44), -INT8_C(  20), -INT8_C(  24), -INT8_C(  22),  INT8_C(  46),
       INT8_C(  45), -INT8_C(  11), -INT8_C(  19), -INT8_C(   5), -INT8_C( 112), -INT8_C(  87),  INT8_C(  44),  INT8_C( 107),
       INT8_C( 125), -INT8_C(  94), -INT8_C(  97),  INT8_C(  75),  INT8_C(  25),  INT8_C(  49),  INT8_C(  95), -INT8_C( 110),
      -INT8_C(  63), -INT8_C(  13), -INT8_C(  12),  INT8_C( 111), -INT8_C( 127), -INT8_C(  32), -INT8_C( 110), -INT8_C( 119),
      -INT8_C(  32), -INT8_C(  77), -INT8_C(  75), -INT8_C(  52), -INT8_C( 101), -INT8_C(  97), -INT8_C(   6), -INT8_C(  55),
      -INT8_C( 108), -INT8_C(  25), -INT8_C(  60),  INT8_C(  37), -INT8_C( 111), -INT8_C(  16), -INT8_C( 112),  INT8_C(  14),
      -INT8_C( 110),  INT8_C(  48),  INT8_C(  89), -INT8_C(  85),  INT8_C(  97), -INT8_C(  71),  INT8_C(  61),  INT8_C(  34),
      -INT8_C(  84),  INT8_C(  50), -INT8_C( 110),  INT8_C(  45),  INT8_C(  18),  INT8_C(  36), -INT8_C(  74), -INT8_C(  14),
      -INT8_C(  41),  INT8_C( 107), -INT8_C(  65),  INT8_C( 115),  INT8_C(  10), -INT8_C(  71),  INT8_C(  60), -INT8_C(  98),
      -INT8_C(  95),  INT8_C(   0), -INT8_C(  61),  INT8_C(  50), -INT8_C(  16),  INT8_C(  84),  INT8_C(  64), -INT8_C( 126),
      -INT8_C( 124), -INT8_C( 103),  INT8_C(  46), -INT8_C(  27),  INT8_C(  82),  INT8_C( 107),  INT8_C(   7), -INT8_C(   2),
      -INT8_C(  99), -INT8_C( 103),  INT8_C(  43), -INT8_C(  81), -INT8_C(  67), -INT8_C(  31), -INT8_C(  94), -INT8_C( 107),
       INT8_C(  76),  INT8_C(  97),  INT8_C(   8),  INT8_C(  86),  INT8_C(  26),  INT8_C(  68), -INT8_C(  11), -INT8_C(  69),
       INT8_C(  68), -INT8_C(  72), -INT8_C(  19),  INT8_C(  52),  INT8_C(  12),  INT8_C(  45), -INT8_C(  74), -INT8_C( 112),
      -INT8_C(  57), -INT8_C(  28),  INT8_C( 117),  INT8_C(  25),  INT8_C(  80),  INT8_C( 125),  INT8_C(  24), -INT8_C(  19),
       INT8_C(  22),  INT8_C(  67), -INT8_C(  99), -INT8_C(  44),  INT8_C(  37),  INT8_C(  63),  INT8_C( 105),  INT8_C( 113),
      -INT8_C(  96),  INT8_C( 113), -INT8_C(  56), -INT8_C(  70), -INT8_C(  75), -INT8_C(  67),  INT8_C( 118), -INT8_C(   7),
       INT8_C( 117),  INT8_C(  99),  INT8_C(  45), -INT8_C( 126), -INT8_C( 111), -INT8_C(  29),  INT8_C(  18),  INT8_C(  88),
      -INT8_C(  56), -INT8_C( 120),  INT8_C( 113),  INT8_C(  24),  INT8_C(   5), -INT8_C( 119),  INT8_C(   5),  INT8_C(  27),
      -INT8_C(  51), -INT8_C(  94), -INT8_C(  17), -INT8_C(  14), -INT8_C(  31),  INT8_C(  88),  INT8_C(  99), -INT8_C( 127),
      -INT8_C(  55),  INT8_C(  43),  INT8_C(  60),  INT8_C( 126), -INT8_C(  24), -INT8_C(  78),  INT8_C( 119),  INT8_C(  94),
       INT8_C(  21), -INT8_C(  92), -INT8_C(  32), -INT8_C(  90), -INT8_C( 120), -INT8_C(  14), -INT8_C(   2),  INT8_C(  80),
       INT8_C( 122),  INT8_C( 112),  INT8_C( 104),      INT8_MAX, -INT8_C(   7),  INT8_C( 109), -INT8_C( 101), -INT8_C(  58),
       INT8_C(  16), -INT8_C( 118), -INT8_C(  72), -INT8_C(  15), -INT8_C(  29),  INT8_C(  28),  INT8_C( 115), -INT8_C(  84),
       INT8_C(  71), -INT8_C(  81),  INT8_C(  43),  INT8_C(  48),  INT8_C(  97), -INT8_C(  94), -INT8_C( 114),  INT8_C( 118),
       INT8_C(  71),  INT8_C( 110),  INT8_C(  29), -INT8_C(  49),  INT8_C(  96),  INT8_C(  27) };
  static const int8_t b[] =
    {  INT8_C(  31), -INT8_C(  37), -INT8_C( 117), -INT8_C( 121),  INT8_C(  90), -INT8_C( 123), -INT8_C(  12), -INT8_C(  11),
       INT8_C(  75),  INT8_C(   4),      INT8_MIN,  INT8_C(   4), -INT8_C(  10),  INT8_C(  99),  INT8_C(  32),  INT8_C( 105),
       INT8_C(  15),  INT8_C( 103),  INT8_C(  24),  INT8_C(  58), -INT8_C( 105),  INT8_C( 121), -INT8_C(  35),  INT8_C(  37),
      -INT8_C(  17),  INT8_C(  36), -INT8_C( 109),  INT8_C(  12), -INT8_C(  13), -INT8_C(  12),  INT8_C(  40),  INT8_C(  18),
      -INT8_C(  49), -INT8_C(  77), -INT8_C( 103),  INT8_C(  41),  INT8_C(  56), -INT8_C( 115),  INT8_C(  31), -INT8_C( 124),
      -INT8_C( 110), -INT8_C(  97), -INT8_C( 120), -INT8_C( 120),  INT8_C(   2), -INT8_C(  88), -INT8_C(  15),  INT8_C(  17),
       INT8_C(  15),  INT8_C(   9),  INT8_C(  76), -INT8_C(  89), -INT8_C( 126),  INT8_C(  41), -INT8_C(  52),  INT8_C( 113),
       INT8_C(  77),  INT8_C(  96),  INT8_C( 126),  INT8_C(  64),  INT8_C(  84), -INT8_C(  90),  INT8_C(  82),  INT8_C(  35),
       INT8_C(  89), -INT8_C(  21),  INT8_C(  76), -INT8_C( 110),  INT8_C( 120),  INT8_C( 107),  INT8_C(  22),  INT8_C(  10),
       INT8_C(  10), -INT8_C(  98), -INT8_C( 110),  INT8_C(  12),  INT8_C(  70), -INT8_C( 125),  INT8_C(  30),  INT8_C(  85),
      -INT8_C( 116),  INT8_C( 106), -INT8_C(   4),  INT8_C(  14), -INT8_C( 109), -INT8_C(  55),      INT8_MIN, -INT8_C(  32),
       INT8_C(  41), -INT8_C(   2),  INT8_C(  32),  INT8_C( 125), -INT8_C(  92),  INT8_C( 114), -INT8_C(  96), -INT8_C(   3),
       INT8_C(  93), -INT8_C(  20), -INT8_C( 113), -INT8_C(  43),  INT8_C(  88), -INT8_C(  91), -INT8_C(  32),  INT8_C(  98),
       INT8_C(  67),  INT8_C( 114),  INT8_C( 111), -INT8_C( 119), -INT8_C(  10), -INT8_C( 115), -INT8_C(  33), -INT8_C( 126),
      -INT8_C(   9), -INT8_C(  37), -INT8_C( 111), -INT8_C( 118), -INT8_C(  92),  INT8_C(  17),  INT8_C( 106), -INT8_C(  51),
       INT8_C(  15), -INT8_C( 118),  INT8_C(  74), -INT8_C(  77), -INT8_C(   4), -INT8_C(  22), -INT8_C(  80),  INT8_C(  89),
      -INT8_C(  41),  INT8_C(  64),  INT8_C(  46),  INT8_C(  47), -INT8_C(  27),  INT8_C(  14), -INT8_C( 111),  INT8_C(  41),
      -INT8_C( 127),  INT8_C(   0), -INT8_C(  78),  INT8_C( 119), -INT8_C( 115), -INT8_C( 111), -INT8_C(   7), -INT8_C( 124),
       INT8_C( 109), -INT8_C( 118),  INT8_C(  14),  INT8_C(  17), -INT8_C( 101),  INT8_C( 120), -INT8_C(  33), -INT8_C(  86),
       INT8_C(   2),  INT8_C(  41),  INT8_C(  93), -INT8_C(   2),  INT8_C(  20),  INT8_C(  14),  INT8_C(  87), -INT8_C(  21),
       INT8_C(  78), -INT8_C( 122),  INT8_C(  26),  INT8_C(  51), -INT8_C( 108), -INT8_C(  85),  INT8_C(  92),  INT8_C(  21),
      -INT8_C(  84),  INT8_C(  15), -INT8_C( 116),  INT8_C(  57), -INT8_C(  96), -INT8_C( 122), -INT8_C(  66),  INT8_C(  13),
       INT8_C(  16), -INT8_C(  52),  INT8_C(  31), -INT8_C(  84),  INT8_C(  69), -INT8_C(   2),  INT8_C(  86),  INT8_C(  71),
       INT8_C(  39), -INT8_C(  76),  INT8_C(  70),  INT8_C(  59), -INT8_C(  62), -INT8_C(  99),  INT8_C(  38),  INT8_C(  16),
       INT8_C(  35),  INT8_C(  64),  INT8_C(  67), -INT8_C(  72), -INT8_C(  20), -INT8_C(  96), -INT8_C(  51), -INT8_C( 104),
      -INT8_C(  81),  INT8_C(  90), -INT8_C(  47),  INT8_C(  79), -INT8_C(  32), -INT8_C( 113),  INT8_C(  93), -INT8_C(  16),
       INT8_C(  92),  INT8_C( 124), -INT8_C( 100), -INT8_C(  95),  INT8_C( 122), -INT8_C(  13), -INT8_C(  24), -INT8_C(  95),
      -INT8_C(  89),  INT8_C(  46), -INT8_C(  35),  INT8_C( 105), -INT8_C(  52),  INT8_C(   3),  INT8_C( 121), -INT8_C(  17),
       INT8_C(  68), -INT8_C(  68), -INT8_C(  89),  INT8_C(  48),  INT8_C(  92),  INT8_C( 117), -INT8_C(  56),  INT8_C(  11),
      -INT8_C(  49), -INT8_C( 103),  INT8_C(  91), -INT8_C(  81),  INT8_C(  41), -INT8_C(  72), -INT8_C(  97), -INT8_C( 123),
       INT8_C(  52),  INT8_C(  60),  INT8_C(  38), -INT8_C(  82),  INT8_C(  47),  INT8_C(  14),  INT8_C(  79), -INT8_C(  42),
       INT8_C(  61),  INT8_C(  44),  INT8_C(  63),  INT8_C(   9),  INT8_C(  48), -INT8_C(  72), -INT8_C(   8),  INT8_C( 116),
       INT8_C( 116), -INT8_C(  96), -INT8_C(  92), -INT8_C(  47),  INT8_C(  21),  INT8_C( 108), -INT8_C(  36), -INT8_C(  28),
       INT8_C(   5),  INT8_C(  55), -INT8_C( 109),  INT8_C(  46), -INT8_C(  17),  INT8_C(  50), -INT8_C(  77),  INT8_C(  35),
       INT8_C( 110), -INT8_C(  39), -INT8_C(  47), -INT8_C(  99), -INT8_C(  24),  INT8_C(  33),  INT8_C( 115),  INT8_C(  37),
       INT8_C(  77), -INT8_C(  78),  INT8_C(  46),  INT8_C( 125),  INT8_C( 106),  INT8_C(  38), -INT8_C(  15), -INT8_C(  33),
      -INT8_C(  58), -INT8_C( 107), -INT8_C(  80), -INT8_C(  37),  INT8_C(   1), -INT8_C( 116), -INT8_C(  65),  INT8_C(   7),
      -INT8_C(  60),  INT8_C(  82),  INT8_C(  53), -INT8_C(  77), -INT8_C( 123), -INT8_C(  23), -INT8_C(  41), -INT8_C(  13),
      -INT8_C(  62), -INT8_C(  88), -INT8_C( 111), -INT8_C(  86), -INT8_C(  55),  INT8_C(   4), -INT8_C(  49),  INT8_C(  23),
      -INT8_C(  73), -INT8_C(   3), -INT8_C( 108),  INT8_C(  33),  INT8_C(  36), -INT8_C( 122),  INT8_C(   0), -INT8_C(  22),
       INT8_C(  27), -INT8_C(  80), -INT8_C(  58),  INT8_C(  29),  INT8_C(  61), -INT8_C( 123),  INT8_C(  36),  INT8_C(   1),
      -INT8_C(  40),  INT8_C(  89), -INT8_C(  76),  INT8_C(  93),  INT8_C(  66), -INT8_C( 117),  INT8_C(  80),  INT8_C(   5),
       INT8_C(  52), -INT8_C(  31), -INT8_C(  81), -INT8_C(   3), -INT8_C(  26),      INT8_MAX,  INT8_C(  20), -INT8_C(  99),
       INT8_C( 124), -INT8_C(  87), -INT8_C(  66), -INT8_C(  96),  INT8_C(  47), -INT8_C(  65), -INT8_C( 117),  INT8_C(  74),
       INT8_C( 111),  INT8_C(  81),  INT8_C( 103), -INT8_C(  84), -INT8_C(  42), -INT8_C( 117), -INT8_C(  83), -INT8_C(  82),
      -INT8_C(  27),  INT8_C(  98),  INT8_C(  11),  INT8_C(  39), -INT8_C(  19),  INT8_C(  92),  INT8_C(  44),  INT8_C(  33),
       INT8_C(  61), -INT8_C(  36),  INT8_C(  31),  INT8_C(  35),  INT8_C(  91),  INT8_C(  51), -INT8_C(  64), -INT8_C(  41),
      -INT8_C(  36),      INT8_MAX,  INT8_C( 120),  INT8_C(  11),  INT8_C(  62),  INT8_C(   3),  INT8_C(  86), -INT8_C(  83),
       INT8_C(  84), -INT8_C(  67),  INT8_C(  90),  INT8_C(  42),  INT8_C(  73),  INT8_C(   7), -INT8_C(  39),  INT8_C(  46),
       INT8_C( 105), -INT8_C(  28),  INT8_C(  85),  INT8_C(  87),  INT8_C(  64), -INT8_C( 126),  INT8_C( 120),  INT8_C( 126),
       INT8_C(  94), -INT8_C( 105), -INT8_C(  95), -INT8_C(  71), -INT8_C(  53),  INT8_C(  98), -INT8_C( 112), -INT8_C(  89),
      -INT8_C(  31),  INT8_C(   8), -INT8_C(  77),  INT8_C(  31),  INT8_C(  11),  INT8_C(   9), -INT8_C(  52),  INT8_C(  95),
      -INT8_C(  58),  INT8_C(  38), -INT8_C( 118),  INT8_C(  15),  INT8_C(  46),  INT8_C(  99),  INT8_C(  61), -INT8_C( 105),
       INT8_C(  71), -INT8_C( 109), -INT8_C(  18), -INT8_C( 120),  INT8_C(  21),  INT8_C( 103) };
  static const int8_t e[] =
    {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) };

  static int8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svbool_t pv, ev;
    simde_svint8_t
      av = simde_svld1_s8(pg, &(a[i])),
      bv = simde_svld1_s8(pg, &(b[i]));

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    ev = simde_svcmplt_s8(pv, av, bv);

    simde_svst1_s8(pg, &(r[i]), simde_svdup_n_s8_z(ev, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vi8(len, e, r);

  return 0;
#else
  int8_t p[1024 / sizeof(int8_t)], a[1024 / sizeof(int8_t)], b[1024 / sizeof(int8_t)], e[1024 / sizeof(int8_t)];
  int32_t len = simde_test_codegen_random_i16() & ((sizeof(e) / sizeof(e[0])) -1);

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t av, bv;
    simde_svbool_t pv, ev;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_s8(pg, &(a[i]));
    bv = simde_svld1_s8(pg, &(b[i]));

    ev = simde_svcmplt_s8(pv, av, bv);

    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));
    simde_svst1_s8(pg, &(e[i]), simde_svdup_n_s8_z(ev, ~INT8_C(0)));

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
test_simde_svcmplt_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) };
  static const int16_t a[] =
    { -INT16_C( 28344), -INT16_C(  7466), -INT16_C( 12016),  INT16_C( 31636),  INT16_C(   325),  INT16_C( 25066), -INT16_C(  4481), -INT16_C(  1032),
      -INT16_C(  3515), -INT16_C( 24598),  INT16_C( 32589),  INT16_C(  7175),  INT16_C(  2746), -INT16_C( 29871), -INT16_C( 14448), -INT16_C(  9876),
       INT16_C( 16984),  INT16_C( 26811),  INT16_C( 20244),  INT16_C( 23012), -INT16_C( 12719), -INT16_C( 12102), -INT16_C( 19524),  INT16_C(   459),
      -INT16_C( 19035), -INT16_C(  3424), -INT16_C( 22476), -INT16_C(  4337),  INT16_C( 24754),  INT16_C( 17018), -INT16_C(  6617),  INT16_C( 32539),
      -INT16_C( 10455),  INT16_C( 15847), -INT16_C( 13530),  INT16_C( 30614),  INT16_C( 20634),  INT16_C( 22087),  INT16_C(  4867), -INT16_C( 22440),
      -INT16_C(  1848), -INT16_C(   613), -INT16_C( 21856),  INT16_C( 21228),  INT16_C( 26122),  INT16_C( 12693), -INT16_C( 20404),  INT16_C( 30128),
      -INT16_C( 26745), -INT16_C( 20814),  INT16_C( 18531), -INT16_C(   731),  INT16_C( 28057), -INT16_C( 25517), -INT16_C( 21632),  INT16_C( 18501),
      -INT16_C(  8028),  INT16_C( 17477),  INT16_C( 12682), -INT16_C( 27497),  INT16_C( 11415), -INT16_C(  6971),  INT16_C( 30172),  INT16_C( 25689),
       INT16_C(  3084),  INT16_C( 28434),  INT16_C( 14164), -INT16_C(  4756), -INT16_C( 16220),  INT16_C(  9354), -INT16_C( 12437),  INT16_C(  3949),
      -INT16_C( 19793),  INT16_C( 14676), -INT16_C(  5148),  INT16_C( 31693), -INT16_C( 28137), -INT16_C(  3233), -INT16_C( 18169),  INT16_C(  4951),
       INT16_C( 27077),  INT16_C(  6531), -INT16_C(  4191),  INT16_C( 17671), -INT16_C( 28241),  INT16_C(  7018), -INT16_C( 10400),  INT16_C(  3882),
       INT16_C( 32393),  INT16_C( 27976),  INT16_C(  5481), -INT16_C( 32535) };
  static const int16_t b[] =
    {  INT16_C( 18599), -INT16_C( 20876), -INT16_C( 13567), -INT16_C( 14655),  INT16_C( 17461), -INT16_C( 10528), -INT16_C(  6348), -INT16_C(  7397),
      -INT16_C( 31368), -INT16_C(  9986),  INT16_C( 10588), -INT16_C(  6425),  INT16_C( 12199),  INT16_C(  4435),  INT16_C( 15428), -INT16_C(  5231),
       INT16_C(  1413), -INT16_C( 31079),  INT16_C( 23249),  INT16_C(  1613),  INT16_C( 11679), -INT16_C( 11300), -INT16_C(  2284), -INT16_C( 29514),
      -INT16_C( 19075), -INT16_C(  9884),  INT16_C( 19422), -INT16_C( 31297),  INT16_C(  4986), -INT16_C( 16746),  INT16_C( 10319), -INT16_C( 11095),
       INT16_C( 16941), -INT16_C(   421), -INT16_C( 22372),  INT16_C( 15108), -INT16_C(  7979), -INT16_C(  5874), -INT16_C( 14888),  INT16_C( 21877),
      -INT16_C(  9862),  INT16_C( 22574), -INT16_C(  4572), -INT16_C( 24867),  INT16_C( 29697),  INT16_C( 20572),  INT16_C(  1436), -INT16_C( 14043),
      -INT16_C( 32697), -INT16_C(  7224), -INT16_C( 13272), -INT16_C(   737),  INT16_C( 11693), -INT16_C( 31258),  INT16_C( 23538),  INT16_C( 27866),
       INT16_C(  2100),  INT16_C( 22724), -INT16_C( 23818), -INT16_C(  2058),  INT16_C( 21014), -INT16_C( 19896),  INT16_C( 27991), -INT16_C( 24965),
       INT16_C( 17389),  INT16_C(  5505), -INT16_C( 24560), -INT16_C( 17134), -INT16_C(  1842), -INT16_C( 16318),  INT16_C(  7251), -INT16_C( 30931),
      -INT16_C(  3804),  INT16_C(  7135), -INT16_C( 10861), -INT16_C( 22254),  INT16_C( 23079),  INT16_C( 32347), -INT16_C( 10297), -INT16_C( 19428),
      -INT16_C( 25318),  INT16_C( 10953), -INT16_C(  9410),  INT16_C(  3303),  INT16_C( 10707),  INT16_C(  9932), -INT16_C(  1723),  INT16_C( 27309),
      -INT16_C( 29461),  INT16_C( 32389), -INT16_C( 26783), -INT16_C( 30680) };
  static const int16_t e[] =
    {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) };

  static int16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svbool_t pv, ev;
    simde_svint16_t
      av = simde_svld1_s16(pg, &(a[i])),
      bv = simde_svld1_s16(pg, &(b[i]));

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    ev = simde_svcmplt_s16(pv, av, bv);

    simde_svst1_s16(pg, &(r[i]), simde_svdup_n_s16_z(ev, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vi16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(int16_t)], a[1024 / sizeof(int16_t)], b[1024 / sizeof(int16_t)], e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_codegen_random_i16() & ((sizeof(e) / sizeof(e[0])) -1);

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t av, bv;
    simde_svbool_t pv, ev;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_s16(pg, &(a[i]));
    bv = simde_svld1_s16(pg, &(b[i]));

    ev = simde_svcmplt_s16(pv, av, bv);

    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));
    simde_svst1_s16(pg, &(e[i]), simde_svdup_n_s16_z(ev, ~INT16_C(0)));

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
test_simde_svcmplt_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) };
  static const int32_t a[] =
    {  INT32_C(    46683809), -INT32_C(  1115452356), -INT32_C(   461756592),  INT32_C(  1576242389),  INT32_C(  2016372030),  INT32_C(   747430481),  INT32_C(   793202128), -INT32_C(  1599720449),
      -INT32_C(   962367606),  INT32_C(  1283663611),  INT32_C(   590413133), -INT32_C(   947903351), -INT32_C(   633360247),  INT32_C(  1644612498),  INT32_C(   395398424),  INT32_C(   196622465),
      -INT32_C(  1563337817), -INT32_C(   823241599), -INT32_C(   621732015), -INT32_C(   861834685), -INT32_C(  1264132062), -INT32_C(  1021923925),  INT32_C(  2077992954), -INT32_C(  2038000673),
       INT32_C(  1864980462), -INT32_C(    63105109),  INT32_C(  2044079926), -INT32_C(  1018857567),  INT32_C(    41413719), -INT32_C(  1815704167),  INT32_C(   336568628),  INT32_C(   580556084),
      -INT32_C(  1735277587),  INT32_C(   295030491), -INT32_C(  1635030019),  INT32_C(   979488995),  INT32_C(  1430116540), -INT32_C(  1696005275), -INT32_C(   659621724),  INT32_C(  2063222925),
      -INT32_C(   418149620),  INT32_C(  1475913817), -INT32_C(   151682285),  INT32_C(   271669076), -INT32_C(  1788449233),  INT32_C(   355422065), -INT32_C(   722608825),  INT32_C(   827320101),
      -INT32_C(   887594382),  INT32_C(   488771850), -INT32_C(   401336172), -INT32_C(  1627830929),  INT32_C(   607346611), -INT32_C(   180788562),  INT32_C(  1707681343),  INT32_C(  2140542989),
      -INT32_C(  2075480198),  INT32_C(  1419931072), -INT32_C(   197282171), -INT32_C(  1366149381),  INT32_C(  1137886869),  INT32_C(  1748503336),  INT32_C(  1053622577), -INT32_C(  1799527654),
      -INT32_C(   770111726), -INT32_C(   114836620),  INT32_C(  1827497073),  INT32_C(   790266010),  INT32_C(  1853025350),  INT32_C(   685157111), -INT32_C(   983129173),  INT32_C(   425337607) };
  static const int32_t b[] =
    { -INT32_C(  1611893974), -INT32_C(  1617423570),  INT32_C(   285967991),  INT32_C(  1279272198),  INT32_C(   146453009),  INT32_C(   120623452),  INT32_C(  1003329076), -INT32_C(   480958535),
      -INT32_C(   930987622), -INT32_C(   882435244), -INT32_C(  1478724959), -INT32_C(  1460462441),  INT32_C(   716221902),  INT32_C(  1932648510),  INT32_C(   799997558), -INT32_C(  1089338587),
      -INT32_C(  1735944892),  INT32_C(  1365503664), -INT32_C(   134725792),  INT32_C(   698346331), -INT32_C(   682405992), -INT32_C(  1521842897), -INT32_C(  1445660541),  INT32_C(  1080616956),
       INT32_C(   752480380),  INT32_C(  1065172190), -INT32_C(   684296836), -INT32_C(   134097312),  INT32_C(  1439650853),  INT32_C(  1576671705),  INT32_C(   235327250),  INT32_C(   844000950),
       INT32_C(  1029580638), -INT32_C(   528688284), -INT32_C(  1330138544), -INT32_C(  1364674424), -INT32_C(   435980275), -INT32_C(  1555825263), -INT32_C(  2102310452),  INT32_C(   380895416),
      -INT32_C(  1957490137),  INT32_C(  1030475757),  INT32_C(   183313282), -INT32_C(   390555941), -INT32_C(  1613776114), -INT32_C(  2059201863),  INT32_C(   336131164),  INT32_C(   472562932),
      -INT32_C(  1129873713), -INT32_C(   805694643),  INT32_C(   299558710), -INT32_C(  1946512771),  INT32_C(   120310094),  INT32_C(   931950299),  INT32_C(  1464570978),  INT32_C(   544437841),
       INT32_C(  1104943860),  INT32_C(  1662113325),  INT32_C(   997583806), -INT32_C(   876122243),  INT32_C(   332591672), -INT32_C(  1035247776),  INT32_C(  1142527731),  INT32_C(     6589452),
      -INT32_C(   733855321), -INT32_C(   717729001), -INT32_C(  1156469442),  INT32_C(  1418188828),  INT32_C(   711416266), -INT32_C(  1393773896),  INT32_C(  1441793609),  INT32_C(   961959314) };
  static const int32_t e[] =
    {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) };

  static int32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svbool_t pv, ev;
    simde_svint32_t
      av = simde_svld1_s32(pg, &(a[i])),
      bv = simde_svld1_s32(pg, &(b[i]));

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    ev = simde_svcmplt_s32(pv, av, bv);

    simde_svst1_s32(pg, &(r[i]), simde_svdup_n_s32_z(ev, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vi32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)], a[1024 / sizeof(int32_t)], b[1024 / sizeof(int32_t)], e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) -1);

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t av, bv;
    simde_svbool_t pv, ev;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_s32(pg, &(a[i]));
    bv = simde_svld1_s32(pg, &(b[i]));

    ev = simde_svcmplt_s32(pv, av, bv);

    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));
    simde_svst1_s32(pg, &(e[i]), simde_svdup_n_s32_z(ev, ~INT32_C(0)));

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
test_simde_svcmplt_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0) };
  static const int64_t a[] =
    { -INT64_C( 8385271428064129702), -INT64_C( 2691043331897020548), -INT64_C( 7328162405211079502), -INT64_C( 8827554261572742103),
      -INT64_C( 8925194342084739193),  INT64_C( 7762265917864754054),  INT64_C(  815184387826040471), -INT64_C( 8475232422895630159),
      -INT64_C(  722751399495854228),  INT64_C( 2208044229737016448),  INT64_C( 4771322536163308619), -INT64_C(   37577373513767187),
       INT64_C( 7204190271942466966), -INT64_C( 6521703353978925608),  INT64_C( 7244331883512812213), -INT64_C( 4737278665005160273),
      -INT64_C(  382316538301794965),  INT64_C( 4938716574616538506),  INT64_C( 1370524084043733802), -INT64_C( 7808513701533361732),
      -INT64_C( 6023403825021229748), -INT64_C( 4201266251800919328),  INT64_C( 1075353514125180277),  INT64_C( 2630547316787003845),
      -INT64_C( 3041905617652260103), -INT64_C( 1649172388278740547), -INT64_C( 5434525407053184205),  INT64_C( 1507618577499457264),
       INT64_C( 3913619801832980101), -INT64_C( 4851033714923302063),  INT64_C( 1139646134831181869),  INT64_C( 1985177682003391068),
       INT64_C(  428657478974422083),  INT64_C( 6250282875867463544),  INT64_C( 3608865258622615527), -INT64_C(  763864046902841931),
       INT64_C( 6389099206626376689), -INT64_C( 3269024080151874526),  INT64_C(  945453937980871958), -INT64_C( 1260234949502908453),
      -INT64_C(  507993241525406790),  INT64_C( 8822524610068368562),  INT64_C( 1180369941931902972),  INT64_C( 3618395427090315851),
      -INT64_C( 4890698049752544430),  INT64_C( 5254233245420709132),  INT64_C( 2257989876338937872),  INT64_C( 7161461253647954615),
      -INT64_C(  274810907810648214),  INT64_C( 7108182498628897041), -INT64_C(  677231824154902106),  INT64_C(  749155133822468592),
      -INT64_C( 5934708995607564104),  INT64_C(  858973004553129782), -INT64_C( 9212922758583446544), -INT64_C( 8373344185494648032),
       INT64_C( 3252116764232993239), -INT64_C( 3722328603758285594),  INT64_C( 2037070672168737844), -INT64_C( 8806040655037085845),
      -INT64_C( 5109866130227724814), -INT64_C( 6778378765354021817),  INT64_C( 8381386962558708024), -INT64_C( 4060701134674514574),
       INT64_C(   74247521856167802), -INT64_C( 6871909843508982637),  INT64_C( 2700229802900850939),  INT64_C( 2589265947525459025),
      -INT64_C(  484849004242165878),  INT64_C( 8542375744502392964), -INT64_C( 2918626654920416859),  INT64_C( 4174534144388154401),
       INT64_C( 6623601909703729035),  INT64_C( 2890136143960466730), -INT64_C( 6083800650301204940),  INT64_C(  552645860647145411),
       INT64_C( 1582421440852404419),  INT64_C( 4932520278572547273), -INT64_C( 5214728611256404885),  INT64_C( 4512841553452603166),
       INT64_C( 5043413094090971646), -INT64_C(  622617648729835767),  INT64_C(  550722189816322809), -INT64_C( 6746883018576507227),
       INT64_C(  908750772756952794),  INT64_C( 3153506219262750015), -INT64_C( 2032042354070212389), -INT64_C( 8515918015344972405),
       INT64_C( 2568879053970889623),  INT64_C( 2812412535510125482),  INT64_C( 7459572715069644643), -INT64_C( 9124460061725915098),
       INT64_C( 7478722771721928642), -INT64_C( 3674572898673903475), -INT64_C( 3625973129979892374),  INT64_C( 7919581776108995452),
       INT64_C( 6081228144064529473),  INT64_C( 6758828766252607636), -INT64_C( 6084555305983395044),  INT64_C( 8407369702402306709),
       INT64_C( 3393698283727798270), -INT64_C( 8011909834046814594),  INT64_C( 6417597327150904117),  INT64_C( 1854433130054230292),
      -INT64_C( 8948381955550990843),  INT64_C( 3261104177609571900), -INT64_C( 8406636692234988489) };
  static const int64_t b[] =
    {  INT64_C( 4104908137810882242),  INT64_C(  596632168279168446),  INT64_C( 4020863447921671335), -INT64_C( 4642780220041831025),
      -INT64_C( 5484939088326990475),  INT64_C(  737673772273220201),  INT64_C( 9165236394533713402),  INT64_C( 6957805151382234066),
       INT64_C( 2964753666462526587),  INT64_C( 5986298036905483173),  INT64_C(  432202844616899984),  INT64_C( 1598044058810680545),
      -INT64_C( 4072474377948088687),  INT64_C(  284258337226283333), -INT64_C( 7000701873233379680), -INT64_C( 6721737816848814842),
       INT64_C( 3293943223716953550),  INT64_C(  774545927045940808), -INT64_C( 3794645775198371076),  INT64_C( 2744419885746274658),
      -INT64_C( 4506189555848312223), -INT64_C(  232150881909521837), -INT64_C( 4823624193579637378),  INT64_C(   21189372085894092),
      -INT64_C( 9183473861733555886), -INT64_C( 4251955199947765246), -INT64_C( 8520502919424331094), -INT64_C( 8344614606203850094),
       INT64_C( 4325958382119254618), -INT64_C(  794537569852439058), -INT64_C( 6181830298352156178),  INT64_C( 3923494942803813293),
      -INT64_C( 7061988707481499000),  INT64_C( 7370927457858370571), -INT64_C( 6084845786945666100),  INT64_C(   17457461654088235),
      -INT64_C( 3594786460965602097), -INT64_C( 8801600778945630468),  INT64_C( 6943415060486811058), -INT64_C( 4478082217978303134),
       INT64_C( 6355806526048869539),  INT64_C( 8685375250781460554),  INT64_C( 5343947468665581971), -INT64_C( 2583660768085634704),
       INT64_C(  742661559700055194),  INT64_C( 6056661732528298702),  INT64_C( 3006511988476818822),  INT64_C( 8569418650196172247),
       INT64_C( 8277259481766506004),  INT64_C(  498513626765126614),  INT64_C( 2750341810511677513),  INT64_C( 8889299069155325707),
       INT64_C( 6658059156761594448), -INT64_C( 3918449981862482920),  INT64_C( 5430204531366106087),  INT64_C(  257145752566010286),
       INT64_C( 2755179390529167450), -INT64_C(  787183193894735926), -INT64_C( 9008176906584269200),  INT64_C( 1859469599881834263),
      -INT64_C( 1351583313810504183), -INT64_C( 3789415859098223258),  INT64_C( 3566701482923037480),  INT64_C( 5368513133780146087),
       INT64_C( 1630760121374177936),  INT64_C( 5531250628166867356),  INT64_C( 6832462796396510855),  INT64_C( 2912215529223933408),
       INT64_C(  614035924109282494), -INT64_C( 8446851830394187689), -INT64_C( 5182520738490675201), -INT64_C( 2627213643420739382),
       INT64_C( 4360275973754218255),  INT64_C( 4714562111168479711),  INT64_C( 6853364369711405196),  INT64_C( 5177533429796959714),
      -INT64_C( 3183124698607049550), -INT64_C( 7833691563716343099),  INT64_C( 3292153641338159292),  INT64_C( 8036680940659699977),
       INT64_C( 6048856078459226666), -INT64_C( 8719349539739555996),  INT64_C( 1467759010703210213), -INT64_C( 4961596172061472008),
       INT64_C( 7497026651307977256), -INT64_C( 1098084417712986767),  INT64_C( 1938938323324148424),  INT64_C( 4996166665819340297),
       INT64_C( 7749012676436242205), -INT64_C(  547916122802397589),  INT64_C(  954679575932864003),  INT64_C( 2185368425187446514),
      -INT64_C( 4642987653556318420), -INT64_C( 6606329160598735063), -INT64_C( 4381429793102947040),  INT64_C(  231414036604049942),
       INT64_C( 7676589257051895412),  INT64_C( 8662134403440557552),  INT64_C( 2217970074359037746),  INT64_C( 3712211562622523818),
       INT64_C( 6237069203413445858), -INT64_C( 7416551830531386814),  INT64_C( 3045389374093897757), -INT64_C( 3967337132960548354),
      -INT64_C( 5361682200210379300), -INT64_C( 5058278383451930676), -INT64_C( 3549361181386970605) };
  static const int64_t e[] =
    {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0) };

  static int64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svbool_t pv, ev;
    simde_svint64_t
      av = simde_svld1_s64(pg, &(a[i])),
      bv = simde_svld1_s64(pg, &(b[i]));

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    ev = simde_svcmplt_s64(pv, av, bv);

    simde_svst1_s64(pg, &(r[i]), simde_svdup_n_s64_z(ev, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vi64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)], a[1024 / sizeof(int64_t)], b[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_codegen_random_i64() & ((sizeof(e) / sizeof(e[0])) -1);

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t av, bv;
    simde_svbool_t pv, ev;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_s64(pg, &(a[i]));
    bv = simde_svld1_s64(pg, &(b[i]));

    ev = simde_svcmplt_s64(pv, av, bv);

    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));
    simde_svst1_s64(pg, &(e[i]), simde_svdup_n_s64_z(ev, ~INT64_C(0)));

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
test_simde_svcmplt_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) };
  static const uint8_t a[] =
    { UINT8_C(185), UINT8_C(118), UINT8_C( 20), UINT8_C(106), UINT8_C( 87), UINT8_C(173), UINT8_C( 82), UINT8_C( 80),
      UINT8_C(134),    UINT8_MAX, UINT8_C(132), UINT8_C(145), UINT8_C(225), UINT8_C(141), UINT8_C( 39), UINT8_C(162),
      UINT8_C(126), UINT8_C( 55), UINT8_C( 68), UINT8_C( 49), UINT8_C(225), UINT8_C( 64), UINT8_C(179), UINT8_C(137),
      UINT8_C(218), UINT8_C( 66), UINT8_C(253), UINT8_C(184), UINT8_C(210), UINT8_C(252), UINT8_C(173), UINT8_C(139),
      UINT8_C(114), UINT8_C(194), UINT8_C(245), UINT8_C(202), UINT8_C(111), UINT8_C( 72), UINT8_C( 26), UINT8_C(245),
      UINT8_C( 71), UINT8_C(158), UINT8_C(135), UINT8_C( 40), UINT8_C( 43), UINT8_C(174), UINT8_C(203), UINT8_C(169),
      UINT8_C(229), UINT8_C( 15), UINT8_C(218), UINT8_C(198), UINT8_C( 79), UINT8_C(141), UINT8_C( 79), UINT8_C( 42),
      UINT8_C(207), UINT8_C( 77), UINT8_C(226), UINT8_C(161), UINT8_C( 73), UINT8_C(143), UINT8_C( 45), UINT8_C(188),
      UINT8_C( 81), UINT8_C( 34), UINT8_C(134), UINT8_C(193), UINT8_C(106), UINT8_C(160), UINT8_C(182), UINT8_C(177),
      UINT8_C( 62), UINT8_C( 61), UINT8_C(218), UINT8_C(105), UINT8_C(235), UINT8_C(165), UINT8_C( 18), UINT8_C(208),
      UINT8_C(180), UINT8_C(236), UINT8_C(151), UINT8_C(  4), UINT8_C(121), UINT8_C(230), UINT8_C( 46), UINT8_C( 72),
      UINT8_C( 51), UINT8_C( 16), UINT8_C(234), UINT8_C(125), UINT8_C(159), UINT8_C( 23), UINT8_C( 57), UINT8_C(241),
      UINT8_C( 57), UINT8_C(191), UINT8_C(178), UINT8_C(164), UINT8_C( 95), UINT8_C(104), UINT8_C( 85), UINT8_C(157),
      UINT8_C(166), UINT8_C( 47), UINT8_C(  6), UINT8_C(145), UINT8_C(212), UINT8_C( 24), UINT8_C( 98), UINT8_C(137),
      UINT8_C(  4), UINT8_C(249), UINT8_C(141), UINT8_C(125), UINT8_C(223), UINT8_C(187), UINT8_C(197), UINT8_C( 19),
      UINT8_C(203), UINT8_C(175), UINT8_C(144), UINT8_C(106), UINT8_C(198), UINT8_C(201), UINT8_C( 91), UINT8_C(  0),
      UINT8_C(136), UINT8_C( 13), UINT8_C(164), UINT8_C(231), UINT8_C(118), UINT8_C(249), UINT8_C(132), UINT8_C( 28),
      UINT8_C( 41), UINT8_C(138), UINT8_C(173), UINT8_C(253), UINT8_C(162), UINT8_C( 15), UINT8_C(134), UINT8_C(166),
      UINT8_C(  8), UINT8_C( 19), UINT8_C( 35), UINT8_C(232), UINT8_C(206), UINT8_C(232), UINT8_C(251), UINT8_C(153),
      UINT8_C(152), UINT8_C(139), UINT8_C(  4), UINT8_C( 94), UINT8_C( 84), UINT8_C( 95), UINT8_C( 94), UINT8_C(220),
      UINT8_C(109), UINT8_C(  2), UINT8_C(195), UINT8_C(227), UINT8_C(252), UINT8_C( 71),    UINT8_MAX, UINT8_C( 37),
      UINT8_C(209), UINT8_C(172), UINT8_C( 34), UINT8_C(115), UINT8_C(188), UINT8_C(169), UINT8_C( 25), UINT8_C(196),
      UINT8_C(188), UINT8_C( 60), UINT8_C(172), UINT8_C(139), UINT8_C( 36), UINT8_C(167), UINT8_C( 36), UINT8_C(188),
      UINT8_C( 50), UINT8_C( 40), UINT8_C( 27), UINT8_C(134), UINT8_C(136), UINT8_C(121), UINT8_C( 98), UINT8_C(245),
      UINT8_C(124), UINT8_C( 37), UINT8_C(216), UINT8_C(120), UINT8_C(108), UINT8_C(215), UINT8_C(157), UINT8_C( 61),
      UINT8_C(131), UINT8_C(191), UINT8_C(176), UINT8_C( 63), UINT8_C(104), UINT8_C(201), UINT8_C(  4), UINT8_C( 37),
      UINT8_C(  5), UINT8_C(176), UINT8_C(176), UINT8_C( 42), UINT8_C( 88), UINT8_C(212), UINT8_C(230), UINT8_C(138),
      UINT8_C(253), UINT8_C(  1), UINT8_C( 17), UINT8_C(133), UINT8_C(123), UINT8_C(115), UINT8_C(122), UINT8_C(247),
      UINT8_C(153), UINT8_C( 82), UINT8_C(111), UINT8_C(  5), UINT8_C( 41), UINT8_C( 12), UINT8_C( 67), UINT8_C(172),
      UINT8_C(203), UINT8_C(243), UINT8_C(236), UINT8_C( 52), UINT8_C(189), UINT8_C(240), UINT8_C( 89), UINT8_C(194),
      UINT8_C(160), UINT8_C(  9), UINT8_C(236), UINT8_C(248), UINT8_C(221), UINT8_C(211), UINT8_C(131), UINT8_C(218),
      UINT8_C(212), UINT8_C(148), UINT8_C( 95), UINT8_C( 79), UINT8_C(  7), UINT8_C(217), UINT8_C( 70), UINT8_C(160),
      UINT8_C( 43), UINT8_C(181), UINT8_C(166), UINT8_C( 84), UINT8_C(193), UINT8_C(233), UINT8_C(  1), UINT8_C(141),
      UINT8_C(220), UINT8_C(237), UINT8_C(193), UINT8_C(153), UINT8_C(221), UINT8_C( 26), UINT8_C( 92), UINT8_C(125),
      UINT8_C( 35), UINT8_C( 72), UINT8_C(118), UINT8_C(  0), UINT8_C( 27), UINT8_C(249), UINT8_C(219), UINT8_C(240),
      UINT8_C(141), UINT8_C( 58), UINT8_C( 63), UINT8_C(148), UINT8_C( 20), UINT8_C(134), UINT8_C( 53), UINT8_C( 63),
      UINT8_C( 59), UINT8_C(219), UINT8_C(148), UINT8_C(253), UINT8_C(196), UINT8_C(149), UINT8_C(138), UINT8_C(160),
      UINT8_C(130), UINT8_C( 75), UINT8_C( 58), UINT8_C( 95), UINT8_C(101), UINT8_C(150), UINT8_C(220), UINT8_C(136),
      UINT8_C(222), UINT8_C( 82), UINT8_C(136), UINT8_C(250), UINT8_C( 75), UINT8_C( 99), UINT8_C(234), UINT8_C(216),
      UINT8_C(158), UINT8_C( 41), UINT8_C(109), UINT8_C(178), UINT8_C(175), UINT8_C(162), UINT8_C(241), UINT8_C(235),
      UINT8_C(125), UINT8_C(133), UINT8_C(232), UINT8_C( 65), UINT8_C( 26), UINT8_C(114), UINT8_C(225), UINT8_C(156),
      UINT8_C(189), UINT8_C( 27), UINT8_C(251), UINT8_C( 34), UINT8_C(177), UINT8_C(216), UINT8_C(170), UINT8_C(144),
      UINT8_C( 42), UINT8_C( 50), UINT8_C(138), UINT8_C(118), UINT8_C(150), UINT8_C(116), UINT8_C( 78), UINT8_C( 52),
      UINT8_C(157), UINT8_C(187), UINT8_C(230), UINT8_C( 77), UINT8_C( 93), UINT8_C(215), UINT8_C( 56), UINT8_C(218),
      UINT8_C( 93), UINT8_C( 32), UINT8_C( 27), UINT8_C(119), UINT8_C(146), UINT8_C(253), UINT8_C( 20), UINT8_C( 79),
      UINT8_C( 24), UINT8_C( 15), UINT8_C(113), UINT8_C(202), UINT8_C(231), UINT8_C( 27), UINT8_C( 90), UINT8_C( 18),
      UINT8_C( 77), UINT8_C(228), UINT8_C(136), UINT8_C(227), UINT8_C( 88), UINT8_C(214), UINT8_C( 23), UINT8_C(245),
      UINT8_C(146), UINT8_C(253), UINT8_C( 66), UINT8_C(239), UINT8_C(213), UINT8_C(122), UINT8_C(202), UINT8_C( 50),
      UINT8_C(154), UINT8_C(229), UINT8_C(169), UINT8_C( 44), UINT8_C(226), UINT8_C(189), UINT8_C(123), UINT8_C(251),
      UINT8_C(205), UINT8_C(236), UINT8_C(197), UINT8_C(180), UINT8_C(  7), UINT8_C( 31), UINT8_C(198), UINT8_C( 85),
      UINT8_C(  3), UINT8_C( 78), UINT8_C( 56), UINT8_C( 91), UINT8_C( 37), UINT8_C( 80), UINT8_C( 80), UINT8_C(183),
      UINT8_C( 77), UINT8_C(147), UINT8_C(166), UINT8_C( 34), UINT8_C( 13), UINT8_C(112), UINT8_C( 84), UINT8_C(168),
      UINT8_C( 86), UINT8_C(254), UINT8_C(212), UINT8_C( 56), UINT8_C(187), UINT8_C( 80), UINT8_C( 51), UINT8_C(136),
      UINT8_C( 60), UINT8_C(248), UINT8_C( 61), UINT8_C( 68), UINT8_C( 23), UINT8_C(  3), UINT8_C(153), UINT8_C( 26),
      UINT8_C( 82), UINT8_C(209), UINT8_C(117), UINT8_C(119), UINT8_C( 33), UINT8_C(198), UINT8_C( 46), UINT8_C(111),
      UINT8_C( 89), UINT8_C(212), UINT8_C(145), UINT8_C(102), UINT8_C( 69), UINT8_C(230), UINT8_C( 14), UINT8_C(155),
      UINT8_C(228), UINT8_C(227), UINT8_C(211), UINT8_C(159), UINT8_C( 51), UINT8_C(  7), UINT8_C( 40), UINT8_C(111),
         UINT8_MAX, UINT8_C(101), UINT8_C(179), UINT8_C( 23), UINT8_C(104), UINT8_C( 76), UINT8_C( 49), UINT8_C(186),
      UINT8_C( 30), UINT8_C(167), UINT8_C( 49), UINT8_C( 63), UINT8_C(109), UINT8_C( 95), UINT8_C(174), UINT8_C(198),
      UINT8_C( 52), UINT8_C( 64), UINT8_C( 44), UINT8_C(121), UINT8_C( 38), UINT8_C( 59), UINT8_C( 20), UINT8_C( 10),
      UINT8_C( 30), UINT8_C(231), UINT8_C(169), UINT8_C( 81), UINT8_C(238), UINT8_C(209), UINT8_C(192), UINT8_C(238),
      UINT8_C( 54), UINT8_C(116), UINT8_C(  5), UINT8_C(159), UINT8_C(192), UINT8_C( 54), UINT8_C( 89), UINT8_C(222),
      UINT8_C(221), UINT8_C(139), UINT8_C( 30), UINT8_C( 74), UINT8_C(234), UINT8_C(204), UINT8_C( 16), UINT8_C( 30),
      UINT8_C( 12), UINT8_C( 61), UINT8_C(151), UINT8_C( 50), UINT8_C(120), UINT8_C(171), UINT8_C( 60), UINT8_C(150),
      UINT8_C(147), UINT8_C(230), UINT8_C(231), UINT8_C(129), UINT8_C(183), UINT8_C(167), UINT8_C(111), UINT8_C(238),
      UINT8_C( 27), UINT8_C(116), UINT8_C(141), UINT8_C(220), UINT8_C(171), UINT8_C(230), UINT8_C(186), UINT8_C(136),
      UINT8_C(113), UINT8_C(216), UINT8_C(211), UINT8_C( 92), UINT8_C(165), UINT8_C(227), UINT8_C(122), UINT8_C(177),
      UINT8_C( 32), UINT8_C( 18), UINT8_C(228), UINT8_C(152), UINT8_C(189), UINT8_C( 32), UINT8_C( 46), UINT8_C( 80),
      UINT8_C(  6), UINT8_C( 21), UINT8_C(210), UINT8_C(190), UINT8_C(189), UINT8_C( 65), UINT8_C(172), UINT8_C(216),
      UINT8_C(182), UINT8_C( 57), UINT8_C(180), UINT8_C( 97), UINT8_C( 31), UINT8_C(111), UINT8_C(233), UINT8_C(145),
      UINT8_C( 71), UINT8_C(188), UINT8_C(237), UINT8_C(236), UINT8_C(160), UINT8_C(103), UINT8_C(158), UINT8_C(192),
      UINT8_C(121), UINT8_C(130), UINT8_C( 89), UINT8_C( 55), UINT8_C(162), UINT8_C(135), UINT8_C(135), UINT8_C(169),
      UINT8_C(157), UINT8_C( 89), UINT8_C(103), UINT8_C( 90), UINT8_C(155), UINT8_C( 19), UINT8_C( 50), UINT8_C( 81),
      UINT8_C( 76), UINT8_C(231), UINT8_C(178), UINT8_C(107), UINT8_C( 86), UINT8_C(155), UINT8_C(252), UINT8_C(157),
      UINT8_C( 88), UINT8_C(233), UINT8_C(138), UINT8_C(248), UINT8_C( 81), UINT8_C( 40), UINT8_C(184), UINT8_C(202),
      UINT8_C(170), UINT8_C( 17), UINT8_C(  1), UINT8_C( 76), UINT8_C(153), UINT8_C(137), UINT8_C(245), UINT8_C( 54),
      UINT8_C(226), UINT8_C( 92), UINT8_C(144), UINT8_C(125), UINT8_C(111), UINT8_C(194), UINT8_C(206), UINT8_C(187),
      UINT8_C(169), UINT8_C(128), UINT8_C( 39),    UINT8_MAX, UINT8_C( 28), UINT8_C( 35), UINT8_C(157), UINT8_C(116),
      UINT8_C( 13), UINT8_C( 39), UINT8_C(108), UINT8_C( 94), UINT8_C( 79), UINT8_C( 36), UINT8_C( 40), UINT8_C(249),
      UINT8_C( 54), UINT8_C( 42), UINT8_C( 69), UINT8_C(207), UINT8_C(179), UINT8_C( 59), UINT8_C(  5), UINT8_C(149),
      UINT8_C(151), UINT8_C(149), UINT8_C( 19), UINT8_C(  7), UINT8_C( 87), UINT8_C(225), UINT8_C(194), UINT8_C(  1),
      UINT8_C( 98), UINT8_C(233), UINT8_C(  0), UINT8_C(126), UINT8_C( 13), UINT8_C(157), UINT8_C(242), UINT8_C( 26),
      UINT8_C(196), UINT8_C( 94), UINT8_C(120), UINT8_C( 19), UINT8_C(130), UINT8_C(160), UINT8_C( 12), UINT8_C(184),
      UINT8_C(202), UINT8_C( 82), UINT8_C(135), UINT8_C(125), UINT8_C(141), UINT8_C(140), UINT8_C( 19), UINT8_C( 36),
      UINT8_C( 33), UINT8_C( 38), UINT8_C( 43), UINT8_C(121), UINT8_C(  7), UINT8_C(238), UINT8_C(122), UINT8_C(105),
      UINT8_C(215), UINT8_C(122), UINT8_C(231), UINT8_C(228), UINT8_C( 24), UINT8_C(217), UINT8_C(254), UINT8_C(220),
      UINT8_C( 55), UINT8_C(118), UINT8_C(240), UINT8_C(186), UINT8_C( 23), UINT8_C(252), UINT8_C(114), UINT8_C(225),
      UINT8_C( 78), UINT8_C(250), UINT8_C( 95), UINT8_C(219), UINT8_C(134), UINT8_C(114), UINT8_C(  0), UINT8_C(168),
      UINT8_C(152), UINT8_C( 43), UINT8_C( 33), UINT8_C(159), UINT8_C( 25), UINT8_C(155), UINT8_C(  9), UINT8_C(241),
      UINT8_C( 21), UINT8_C(240), UINT8_C(213), UINT8_C( 45), UINT8_C(202), UINT8_C(212), UINT8_C( 10), UINT8_C(  1),
      UINT8_C( 74), UINT8_C(250), UINT8_C(187), UINT8_C( 97), UINT8_C(246), UINT8_C( 46), UINT8_C( 67), UINT8_C( 69),
      UINT8_C( 40), UINT8_C(162), UINT8_C( 32), UINT8_C(174), UINT8_C( 20), UINT8_C( 32), UINT8_C( 86), UINT8_C(172),
      UINT8_C( 76), UINT8_C(119), UINT8_C( 75), UINT8_C(101), UINT8_C( 18), UINT8_C( 84), UINT8_C( 86), UINT8_C( 40),
      UINT8_C( 69), UINT8_C( 44), UINT8_C( 85), UINT8_C( 15), UINT8_C(  0), UINT8_C( 95), UINT8_C( 16), UINT8_C( 74),
      UINT8_C( 89), UINT8_C(204), UINT8_C(172), UINT8_C( 80), UINT8_C(250), UINT8_C(239), UINT8_C(149), UINT8_C( 34),
      UINT8_C(145), UINT8_C(181), UINT8_C(208), UINT8_C(165), UINT8_C(214), UINT8_C( 39), UINT8_C( 81), UINT8_C( 34),
      UINT8_C(158), UINT8_C(156), UINT8_C(135), UINT8_C(177), UINT8_C(241), UINT8_C(222), UINT8_C(217), UINT8_C( 54),
      UINT8_C( 10), UINT8_C( 46), UINT8_C( 69), UINT8_C( 10), UINT8_C(142), UINT8_C( 85), UINT8_C( 84), UINT8_C(231),
      UINT8_C( 33), UINT8_C(  0), UINT8_C( 55), UINT8_C( 27), UINT8_C(239), UINT8_C(204), UINT8_C( 61), UINT8_C(128),
      UINT8_C(130), UINT8_C( 14), UINT8_C( 37), UINT8_C( 88), UINT8_C( 53), UINT8_C(118), UINT8_C(122), UINT8_C(211),
      UINT8_C( 19), UINT8_C(  1), UINT8_C(132), UINT8_C(  4), UINT8_C(223), UINT8_C( 93), UINT8_C( 58), UINT8_C(233),
      UINT8_C(140), UINT8_C(127), UINT8_C(243), UINT8_C( 26), UINT8_C(212), UINT8_C( 72), UINT8_C(  1), UINT8_C(246),
      UINT8_C( 72), UINT8_C( 57), UINT8_C( 17), UINT8_C( 56), UINT8_C(  5), UINT8_C( 79), UINT8_C(184), UINT8_C(135),
      UINT8_C( 93), UINT8_C(222), UINT8_C(223), UINT8_C(146), UINT8_C( 84), UINT8_C( 89), UINT8_C(101), UINT8_C(103),
      UINT8_C( 91), UINT8_C(234), UINT8_C(107), UINT8_C( 58), UINT8_C( 71), UINT8_C(165), UINT8_C( 36), UINT8_C(211),
      UINT8_C( 36), UINT8_C( 23), UINT8_C(237), UINT8_C(249), UINT8_C( 95), UINT8_C(239), UINT8_C(239), UINT8_C(168),
      UINT8_C( 40), UINT8_C(  0), UINT8_C(224), UINT8_C( 45), UINT8_C( 79), UINT8_C(152), UINT8_C(181), UINT8_C(172),
      UINT8_C(118), UINT8_C(148), UINT8_C( 62), UINT8_C(203), UINT8_C(238), UINT8_C(164), UINT8_C( 50), UINT8_C( 73),
      UINT8_C(142), UINT8_C(158), UINT8_C(131), UINT8_C(213), UINT8_C( 67), UINT8_C(167), UINT8_C(169), UINT8_C(104),
      UINT8_C(191), UINT8_C(150), UINT8_C( 97), UINT8_C( 30), UINT8_C(133), UINT8_C( 80), UINT8_C(198), UINT8_C(173),
      UINT8_C( 80), UINT8_C(166), UINT8_C(219), UINT8_C(160), UINT8_C( 63), UINT8_C(144), UINT8_C( 76), UINT8_C(181),
      UINT8_C( 36), UINT8_C(139), UINT8_C(128), UINT8_C( 18), UINT8_C( 47), UINT8_C(179), UINT8_C( 91), UINT8_C(189),
      UINT8_C( 81), UINT8_C(223), UINT8_C(146), UINT8_C(148), UINT8_C(134), UINT8_C( 59), UINT8_C(252), UINT8_C( 69),
      UINT8_C(210), UINT8_C( 93), UINT8_C(100), UINT8_C( 87), UINT8_C(173), UINT8_C( 42), UINT8_C(  5), UINT8_C(254),
      UINT8_C(209), UINT8_C(224), UINT8_C(158) };
  static const uint8_t b[] =
    { UINT8_C( 16), UINT8_C(112), UINT8_C(234), UINT8_C(197), UINT8_C(148), UINT8_C(117), UINT8_C( 70), UINT8_C(167),
      UINT8_C(164), UINT8_C(249), UINT8_C(  2), UINT8_C( 97), UINT8_C( 74), UINT8_C(225), UINT8_C(244), UINT8_C(222),
      UINT8_C(104), UINT8_C( 47), UINT8_C(219), UINT8_C(173), UINT8_C(  1), UINT8_C( 56), UINT8_C( 17), UINT8_C( 89),
      UINT8_C(230), UINT8_C( 60), UINT8_C( 94), UINT8_C(228), UINT8_C( 13), UINT8_C( 62), UINT8_C(130), UINT8_C( 29),
      UINT8_C(174), UINT8_C(108), UINT8_C(226), UINT8_C( 66), UINT8_C(226), UINT8_C( 40), UINT8_C(233), UINT8_C(134),
      UINT8_C( 33), UINT8_C(236), UINT8_C(232), UINT8_C(107), UINT8_C(205), UINT8_C(220), UINT8_C( 74), UINT8_C( 53),
      UINT8_C( 11), UINT8_C( 37), UINT8_C(227), UINT8_C( 13), UINT8_C( 93), UINT8_C(244), UINT8_C(102), UINT8_C( 67),
      UINT8_C( 48), UINT8_C(196), UINT8_C( 39), UINT8_C( 61), UINT8_C(  2), UINT8_C(169), UINT8_C( 90), UINT8_C(176),
      UINT8_C( 22), UINT8_C( 61), UINT8_C(242), UINT8_C(248), UINT8_C(101), UINT8_C(220), UINT8_C(126), UINT8_C(135),
      UINT8_C(200), UINT8_C(102), UINT8_C(242), UINT8_C(149), UINT8_C( 66), UINT8_C( 60), UINT8_C(203), UINT8_C( 78),
      UINT8_C( 97), UINT8_C(174), UINT8_C( 91), UINT8_C(191), UINT8_C(162), UINT8_C(193), UINT8_C(  2), UINT8_C(211),
      UINT8_C(133), UINT8_C( 42), UINT8_C( 16), UINT8_C(135), UINT8_C(211), UINT8_C(107), UINT8_C( 55), UINT8_C(233),
      UINT8_C(168), UINT8_C( 41), UINT8_C(225), UINT8_C( 13), UINT8_C(  5), UINT8_C( 96), UINT8_C(148), UINT8_C(205),
      UINT8_C(198), UINT8_C(135), UINT8_C( 99), UINT8_C(  9), UINT8_C(195), UINT8_C( 46), UINT8_C( 87), UINT8_C( 37),
      UINT8_C(220), UINT8_C(178), UINT8_C(228), UINT8_C(126), UINT8_C(115), UINT8_C(230), UINT8_C( 81), UINT8_C(248),
      UINT8_C( 16), UINT8_C( 98), UINT8_C(127), UINT8_C(228), UINT8_C(205), UINT8_C(182), UINT8_C(205), UINT8_C(117),
      UINT8_C(223), UINT8_C(175), UINT8_C(130), UINT8_C(229), UINT8_C( 15), UINT8_C( 23), UINT8_C(178), UINT8_C(213),
      UINT8_C(158), UINT8_C( 21), UINT8_C(222), UINT8_C( 97), UINT8_C( 67), UINT8_C( 53), UINT8_C(134), UINT8_C( 31),
      UINT8_C(231), UINT8_C(106), UINT8_C(158), UINT8_C( 90), UINT8_C( 81), UINT8_C(239), UINT8_C( 82), UINT8_C( 97),
      UINT8_C( 81), UINT8_C(209), UINT8_C( 69), UINT8_C( 30), UINT8_C(135), UINT8_C( 19), UINT8_C(147), UINT8_C(103),
      UINT8_C(194), UINT8_C( 22), UINT8_C( 76), UINT8_C(209), UINT8_C( 45), UINT8_C(254), UINT8_C(166), UINT8_C(203),
      UINT8_C( 20), UINT8_C(133), UINT8_C( 44), UINT8_C( 87), UINT8_C(186), UINT8_C(179), UINT8_C(119), UINT8_C(162),
      UINT8_C( 29), UINT8_C( 21), UINT8_C(252), UINT8_C(110), UINT8_C(  4), UINT8_C( 79), UINT8_C(208), UINT8_C( 86),
      UINT8_C( 32), UINT8_C( 21), UINT8_C(116), UINT8_C(168), UINT8_C( 40), UINT8_C(  8), UINT8_C( 15), UINT8_C(234),
      UINT8_C( 30), UINT8_C( 91), UINT8_C(187), UINT8_C( 75), UINT8_C( 89), UINT8_C( 98), UINT8_C( 22), UINT8_C(109),
      UINT8_C(231), UINT8_C( 66), UINT8_C(197), UINT8_C(161), UINT8_C(245), UINT8_C( 60), UINT8_C( 67), UINT8_C( 19),
      UINT8_C( 81), UINT8_C( 64), UINT8_C(129), UINT8_C( 85), UINT8_C(143), UINT8_C( 81), UINT8_C(171), UINT8_C(175),
      UINT8_C(103), UINT8_C( 32), UINT8_C( 87), UINT8_C(143), UINT8_C( 40), UINT8_C(102), UINT8_C(122), UINT8_C( 70),
      UINT8_C(193), UINT8_C( 53), UINT8_C(145), UINT8_C( 27), UINT8_C(151), UINT8_C(167), UINT8_C(136), UINT8_C(126),
      UINT8_C(233), UINT8_C( 77), UINT8_C( 32), UINT8_C(223), UINT8_C(137), UINT8_C( 99), UINT8_C(242), UINT8_C(218),
      UINT8_C(163), UINT8_C(115), UINT8_C( 48), UINT8_C( 50), UINT8_C(197), UINT8_C(219), UINT8_C(226), UINT8_C( 44),
      UINT8_C(251), UINT8_C( 57), UINT8_C(187), UINT8_C( 35), UINT8_C(160), UINT8_C( 53), UINT8_C(105), UINT8_C( 97),
      UINT8_C(107), UINT8_C(250), UINT8_C(124), UINT8_C(  2), UINT8_C(161), UINT8_C(  5), UINT8_C(129), UINT8_C(139),
      UINT8_C( 82), UINT8_C(161), UINT8_C(106), UINT8_C(220), UINT8_C(  4), UINT8_C( 92), UINT8_C(182), UINT8_C(168),
      UINT8_C(207), UINT8_C(230), UINT8_C(218), UINT8_C(148), UINT8_C(194), UINT8_C(188), UINT8_C(192), UINT8_C(189),
      UINT8_C(246), UINT8_C(124), UINT8_C(225), UINT8_C(150), UINT8_C(177), UINT8_C( 74), UINT8_C(247), UINT8_C( 28),
      UINT8_C( 69), UINT8_C(116), UINT8_C( 31), UINT8_C(230), UINT8_C(121), UINT8_C(160), UINT8_C(113), UINT8_C(203),
      UINT8_C( 65), UINT8_C(219), UINT8_C(167), UINT8_C( 69), UINT8_C( 55), UINT8_C( 94), UINT8_C(237), UINT8_C(  7),
      UINT8_C( 68), UINT8_C(200), UINT8_C(155), UINT8_C(  6), UINT8_C(132), UINT8_C( 92), UINT8_C(196), UINT8_C(122),
      UINT8_C(216), UINT8_C(165), UINT8_C( 16), UINT8_C(137), UINT8_C(239), UINT8_C(  8), UINT8_C(166), UINT8_C( 52),
      UINT8_C(124), UINT8_C(197), UINT8_C( 27), UINT8_C(245), UINT8_C(101), UINT8_C(140), UINT8_C(192), UINT8_C(166),
      UINT8_C(104), UINT8_C(104), UINT8_C(235), UINT8_C(159), UINT8_C(198), UINT8_C(217), UINT8_C(166), UINT8_C( 10),
      UINT8_C(161), UINT8_C( 66), UINT8_C( 17), UINT8_C( 37), UINT8_C(158), UINT8_C(213), UINT8_C(160), UINT8_C(118),
      UINT8_C(122), UINT8_C(176),    UINT8_MAX, UINT8_C(105), UINT8_C(184), UINT8_C(165), UINT8_C(158), UINT8_C( 52),
      UINT8_C(106), UINT8_C(185), UINT8_C( 41), UINT8_C(207), UINT8_C( 69), UINT8_C(234), UINT8_C(117), UINT8_C(173),
      UINT8_C( 82), UINT8_C( 97), UINT8_C( 77), UINT8_C( 24), UINT8_C( 58), UINT8_C(243), UINT8_C( 34), UINT8_C(219),
      UINT8_C( 53), UINT8_C( 51), UINT8_C(  0), UINT8_C(211), UINT8_C(  8), UINT8_C(160), UINT8_C( 73), UINT8_C(130),
      UINT8_C( 81), UINT8_C( 73), UINT8_C(236), UINT8_C(  9), UINT8_C(238), UINT8_C(138), UINT8_C( 62), UINT8_C( 89),
      UINT8_C( 67), UINT8_C(103), UINT8_C( 40), UINT8_C(136), UINT8_C( 81), UINT8_C(158), UINT8_C( 54), UINT8_C(163),
         UINT8_MAX, UINT8_C(131), UINT8_C(187), UINT8_C( 57), UINT8_C(118), UINT8_C(222), UINT8_C( 20), UINT8_C(172),
      UINT8_C( 17), UINT8_C( 20), UINT8_C(127), UINT8_C( 26), UINT8_C(181), UINT8_C(201), UINT8_C(156), UINT8_C(  6),
      UINT8_C( 18), UINT8_C(136), UINT8_C( 15), UINT8_C(  0), UINT8_C( 18), UINT8_C( 77), UINT8_C( 89), UINT8_C( 85),
      UINT8_C(181), UINT8_C(130), UINT8_C(222), UINT8_C(  6), UINT8_C( 32), UINT8_C( 20), UINT8_C(170), UINT8_C( 31),
      UINT8_C(151), UINT8_C(101), UINT8_C( 88), UINT8_C( 13), UINT8_C( 67), UINT8_C(108), UINT8_C(185), UINT8_C( 85),
      UINT8_C(128), UINT8_C( 57), UINT8_C(111), UINT8_C( 53), UINT8_C(  2), UINT8_C( 11), UINT8_C( 59), UINT8_C( 20),
      UINT8_C(148), UINT8_C( 75), UINT8_C( 20), UINT8_C(166), UINT8_C(152), UINT8_C(110), UINT8_C(252), UINT8_C( 77),
      UINT8_C(240), UINT8_C(218), UINT8_C( 84), UINT8_C( 16), UINT8_C(238), UINT8_C(254), UINT8_C( 47), UINT8_C(133),
      UINT8_C( 99), UINT8_C(135), UINT8_C(146), UINT8_C(167), UINT8_C(243), UINT8_C( 76), UINT8_C(252), UINT8_C(115),
      UINT8_C(133), UINT8_C(107), UINT8_C(169), UINT8_C(135), UINT8_C(118), UINT8_C(228), UINT8_C(155), UINT8_C( 10),
      UINT8_C( 47), UINT8_C(175), UINT8_C(177), UINT8_C(200), UINT8_C( 29), UINT8_C(173), UINT8_C( 21), UINT8_C( 13),
      UINT8_C(135), UINT8_C(105), UINT8_C( 29), UINT8_C(117), UINT8_C(103), UINT8_C( 76), UINT8_C(250), UINT8_C(203),
      UINT8_C(211), UINT8_C(140), UINT8_C(114), UINT8_C(198), UINT8_C(216), UINT8_C(110), UINT8_C( 58), UINT8_C( 93),
      UINT8_C(217), UINT8_C(227), UINT8_C(228), UINT8_C( 79), UINT8_C(199), UINT8_C(127), UINT8_C( 90), UINT8_C(247),
      UINT8_C( 47), UINT8_C( 11), UINT8_C(191), UINT8_C( 76), UINT8_C(184), UINT8_C(212), UINT8_C( 90), UINT8_C( 63),
      UINT8_C( 62), UINT8_C(119), UINT8_C(180), UINT8_C(165), UINT8_C(196), UINT8_C(174), UINT8_C(112), UINT8_C(151),
      UINT8_C( 58), UINT8_C(226), UINT8_C( 94), UINT8_C( 19), UINT8_C( 80), UINT8_C(152), UINT8_C(112), UINT8_C( 41),
      UINT8_C(123), UINT8_C( 85), UINT8_C(121), UINT8_C( 66), UINT8_C(212), UINT8_C(211), UINT8_C( 57), UINT8_C(  3),
      UINT8_C(222), UINT8_C(248), UINT8_C( 80), UINT8_C(150), UINT8_C(205), UINT8_C(170), UINT8_C(213), UINT8_C( 11),
      UINT8_C( 33), UINT8_C(137), UINT8_C(176), UINT8_C(229), UINT8_C( 55), UINT8_C( 33), UINT8_C(125), UINT8_C(113),
      UINT8_C(  3), UINT8_C(219), UINT8_C(132), UINT8_C( 84), UINT8_C(115), UINT8_C(245), UINT8_C(125), UINT8_C(238),
      UINT8_C( 74), UINT8_C(246), UINT8_C( 48), UINT8_C( 30), UINT8_C(201), UINT8_C(106), UINT8_C( 34), UINT8_C(167),
      UINT8_C( 98), UINT8_C(114), UINT8_C( 61), UINT8_C( 47), UINT8_C( 28), UINT8_C( 18), UINT8_C( 58), UINT8_C( 61),
      UINT8_C(155), UINT8_C(235), UINT8_C( 35), UINT8_C(210), UINT8_C( 12), UINT8_C(160), UINT8_C( 68), UINT8_C( 15),
      UINT8_C(123), UINT8_C(200), UINT8_C( 99), UINT8_C(238), UINT8_C(189), UINT8_C(225), UINT8_C(220), UINT8_C(  7),
      UINT8_C(215), UINT8_C( 12), UINT8_C( 38), UINT8_C(161), UINT8_C(118), UINT8_C( 72), UINT8_C( 72), UINT8_C(217),
      UINT8_C(186), UINT8_C(134), UINT8_C(  8), UINT8_C(214), UINT8_C(152), UINT8_C( 67), UINT8_C( 19), UINT8_C( 52),
      UINT8_C( 46), UINT8_C( 54), UINT8_C(  6), UINT8_C( 58), UINT8_C(214), UINT8_C( 74), UINT8_C( 73), UINT8_C( 81),
      UINT8_C( 19), UINT8_C(173), UINT8_C( 63), UINT8_C(208), UINT8_C(142), UINT8_C( 27), UINT8_C(216), UINT8_C(101),
      UINT8_C( 40), UINT8_C(254), UINT8_C(  6), UINT8_C(158), UINT8_C( 70), UINT8_C( 79), UINT8_C(119), UINT8_C(  0),
      UINT8_C(213), UINT8_C(128), UINT8_C(214), UINT8_C(109), UINT8_C(195), UINT8_C(233), UINT8_C(161), UINT8_C(241),
      UINT8_C( 32), UINT8_C(168), UINT8_C( 43), UINT8_C(246), UINT8_C(242), UINT8_C(116), UINT8_C( 72), UINT8_C(  5),
      UINT8_C( 33), UINT8_C(135), UINT8_C(214), UINT8_C(175), UINT8_C(163), UINT8_C(174), UINT8_C( 21), UINT8_C(203),
      UINT8_C(172), UINT8_C( 27), UINT8_C(105), UINT8_C(242), UINT8_C(106), UINT8_C(225), UINT8_C(242), UINT8_C( 63),
      UINT8_C( 97), UINT8_C(200), UINT8_C(173), UINT8_C( 36), UINT8_C(177), UINT8_C( 78), UINT8_C( 21), UINT8_C(209),
      UINT8_C(246), UINT8_C( 64), UINT8_C(200), UINT8_C(233), UINT8_C(180), UINT8_C( 16), UINT8_C(238), UINT8_C(214),
      UINT8_C(151), UINT8_C(196), UINT8_C(133), UINT8_C( 58), UINT8_C(114), UINT8_C(154), UINT8_C(  5), UINT8_C( 30),
      UINT8_C(182), UINT8_C(111), UINT8_C( 16), UINT8_C( 32), UINT8_C( 80), UINT8_C(  2), UINT8_C( 96), UINT8_C(177),
      UINT8_C(202), UINT8_C( 13), UINT8_C(213), UINT8_C(124), UINT8_C( 91), UINT8_C(234), UINT8_C( 77), UINT8_C( 82),
      UINT8_C( 42), UINT8_C( 21), UINT8_C( 59), UINT8_C(222), UINT8_C( 37), UINT8_C( 41), UINT8_C(180), UINT8_C(189),
      UINT8_C(238), UINT8_C( 58), UINT8_C(247), UINT8_C( 96), UINT8_C(212), UINT8_C(253), UINT8_C(127), UINT8_C(138),
      UINT8_C(108), UINT8_C(143), UINT8_C(171), UINT8_C(188), UINT8_C(146), UINT8_C( 11), UINT8_C(109), UINT8_C( 92),
      UINT8_C( 24), UINT8_C( 66), UINT8_C(216), UINT8_C(115), UINT8_C( 44), UINT8_C( 38), UINT8_C(197), UINT8_C( 86),
      UINT8_C( 59), UINT8_C(  0), UINT8_C( 52), UINT8_C( 97), UINT8_C( 42), UINT8_C(233), UINT8_C( 30), UINT8_C( 24),
      UINT8_C( 35), UINT8_C( 21), UINT8_C(120), UINT8_C(247), UINT8_C( 18), UINT8_C(247), UINT8_C(130), UINT8_C(126),
      UINT8_C(135), UINT8_C( 45), UINT8_C( 58), UINT8_C( 25), UINT8_C( 56), UINT8_C(167), UINT8_C(117), UINT8_C( 80),
      UINT8_C(233), UINT8_C( 78), UINT8_C(195), UINT8_C( 21), UINT8_C(116), UINT8_C(137), UINT8_C(107), UINT8_C(175),
      UINT8_C(137), UINT8_C(160), UINT8_C( 16), UINT8_C(179), UINT8_C(137), UINT8_C( 46), UINT8_C(203), UINT8_C(172),
      UINT8_C( 68), UINT8_C( 68), UINT8_C(163), UINT8_C( 86), UINT8_C( 59), UINT8_C( 37), UINT8_C(213), UINT8_C(194),
      UINT8_C( 82), UINT8_C( 15), UINT8_C(219), UINT8_C(138), UINT8_C(183), UINT8_C( 81), UINT8_C(218), UINT8_C(160),
      UINT8_C(159), UINT8_C(158), UINT8_C(182), UINT8_C( 19), UINT8_C( 39), UINT8_C( 33), UINT8_C(194), UINT8_C(176),
      UINT8_C(193), UINT8_C(211), UINT8_C(100), UINT8_C( 74), UINT8_C(  1), UINT8_C( 47), UINT8_C(246), UINT8_C( 69),
      UINT8_C(115), UINT8_C(154), UINT8_C(156), UINT8_C(175), UINT8_C(191), UINT8_C(113), UINT8_C(113), UINT8_C( 18),
      UINT8_C(128), UINT8_C( 77), UINT8_C(156), UINT8_C( 55), UINT8_C(158), UINT8_C(119), UINT8_C(216), UINT8_C( 61),
      UINT8_C( 21), UINT8_C(142), UINT8_C( 80), UINT8_C( 60), UINT8_C(175), UINT8_C( 18), UINT8_C(236), UINT8_C(113),
      UINT8_C(229), UINT8_C( 80), UINT8_C(187), UINT8_C(231), UINT8_C(128), UINT8_C(178), UINT8_C( 44), UINT8_C(243),
      UINT8_C( 76), UINT8_C(200), UINT8_C(162), UINT8_C( 11), UINT8_C( 57), UINT8_C( 20), UINT8_C( 29), UINT8_C(186),
      UINT8_C( 97), UINT8_C(186), UINT8_C(241),    UINT8_MAX, UINT8_C( 49), UINT8_C(201), UINT8_C( 60), UINT8_C( 70),
      UINT8_C( 87), UINT8_C(140), UINT8_C(130), UINT8_C(  7), UINT8_C(158), UINT8_C(110), UINT8_C(120), UINT8_C(132),
      UINT8_C(191), UINT8_C( 51), UINT8_C(107), UINT8_C( 63), UINT8_C(229), UINT8_C(151), UINT8_C( 50), UINT8_C( 49),
      UINT8_C( 96), UINT8_C(213), UINT8_C( 61), UINT8_C(153), UINT8_C(233), UINT8_C( 90), UINT8_C( 83), UINT8_C( 74),
      UINT8_C( 20), UINT8_C( 69), UINT8_C( 73), UINT8_C( 69), UINT8_C( 14), UINT8_C(133), UINT8_C(139), UINT8_C(102),
      UINT8_C( 17), UINT8_C( 13), UINT8_C(109), UINT8_C(175), UINT8_C(124), UINT8_C(229), UINT8_C( 51), UINT8_C( 59),
      UINT8_C( 24), UINT8_C(158), UINT8_C(122), UINT8_C(254), UINT8_C( 54), UINT8_C(172), UINT8_C( 47), UINT8_C(150),
      UINT8_C(129), UINT8_C(108), UINT8_C( 47), UINT8_C(106), UINT8_C(199), UINT8_C(131), UINT8_C(180), UINT8_C(219),
      UINT8_C(200), UINT8_C(253), UINT8_C( 33) };
  static const int8_t e[] =
    {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0) };

  static int8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svbool_t pv, ev;
    simde_svuint8_t
      av = simde_svld1_u8(pg, &(a[i])),
      bv = simde_svld1_u8(pg, &(b[i]));

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    ev = simde_svcmplt_u8(pv, av, bv);

    simde_svst1_s8(pg, &(r[i]), simde_svdup_n_s8_z(ev, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vi8(len, e, r);

  return 0;
#else
  int8_t p[1024 / sizeof(int8_t)], e[1024 / sizeof(int8_t)];
  uint8_t a[1024 / sizeof(uint8_t)], b[1024 / sizeof(uint8_t)];
  int32_t len = simde_test_codegen_random_i16() & ((sizeof(e) / sizeof(e[0])) -1);

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t av, bv;
    simde_svbool_t pv, ev;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_u8(pg, &(a[i]));
    bv = simde_svld1_u8(pg, &(b[i]));

    ev = simde_svcmplt_u8(pv, av, bv);

    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));
    simde_svst1_s8(pg, &(e[i]), simde_svdup_n_s8_z(ev, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svcmplt_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) };
  static const uint16_t a[] =
    { UINT16_C(10693), UINT16_C(59520), UINT16_C(51934), UINT16_C(31321), UINT16_C(11820), UINT16_C(54228), UINT16_C(18363), UINT16_C(20575),
      UINT16_C(15962), UINT16_C(52245), UINT16_C(25819), UINT16_C(48770), UINT16_C(23212), UINT16_C( 2562), UINT16_C(58108), UINT16_C(49408),
      UINT16_C(32779), UINT16_C(59817), UINT16_C(  586), UINT16_C(30308), UINT16_C(14384), UINT16_C(60489), UINT16_C(43392), UINT16_C(55868),
      UINT16_C(20967), UINT16_C(49830), UINT16_C(10422), UINT16_C(25217), UINT16_C(33666), UINT16_C(32364), UINT16_C(27749), UINT16_C(28735),
      UINT16_C(59628), UINT16_C(13914), UINT16_C(48875), UINT16_C( 7084), UINT16_C(63222), UINT16_C(30215), UINT16_C(17567), UINT16_C(34384),
      UINT16_C(63125), UINT16_C(19272), UINT16_C(51487), UINT16_C(41390), UINT16_C( 6733), UINT16_C(45600), UINT16_C(24455), UINT16_C(29475),
      UINT16_C(32072), UINT16_C(13226), UINT16_C(22075), UINT16_C(12622), UINT16_C(22092), UINT16_C(60328), UINT16_C(63642), UINT16_C(12145),
      UINT16_C(47855), UINT16_C( 3707), UINT16_C(10627), UINT16_C(53423), UINT16_C(53059), UINT16_C(51843), UINT16_C(42543), UINT16_C(30526),
      UINT16_C(59427), UINT16_C(24234), UINT16_C(63550), UINT16_C(35727), UINT16_C(14158), UINT16_C(59510), UINT16_C(59440), UINT16_C( 7960),
      UINT16_C(37794), UINT16_C( 9517), UINT16_C(56508), UINT16_C(65526), UINT16_C(31148), UINT16_C(56266), UINT16_C( 2079), UINT16_C(16978),
      UINT16_C(64752), UINT16_C(11936), UINT16_C(12276), UINT16_C(17337), UINT16_C(12391), UINT16_C(38699), UINT16_C(17176), UINT16_C(47798),
      UINT16_C(58326), UINT16_C(37599), UINT16_C(54719), UINT16_C(27538), UINT16_C(23630), UINT16_C(27974), UINT16_C(39012), UINT16_C(21679),
      UINT16_C(20372), UINT16_C(35202), UINT16_C(15487), UINT16_C(59084), UINT16_C(63340), UINT16_C(33917), UINT16_C(13115), UINT16_C( 4414),
      UINT16_C( 7446), UINT16_C(54692), UINT16_C(14067), UINT16_C(16705), UINT16_C(34706), UINT16_C(63151), UINT16_C(24096), UINT16_C(46154),
      UINT16_C(52398), UINT16_C(11581), UINT16_C( 2312), UINT16_C(29715), UINT16_C(36865), UINT16_C(15608), UINT16_C(14019), UINT16_C(55629),
      UINT16_C(61780), UINT16_C(18350), UINT16_C(61223), UINT16_C(47496), UINT16_C(14199), UINT16_C(38831), UINT16_C(63894), UINT16_C(17483),
      UINT16_C(35270), UINT16_C(52849), UINT16_C(33938), UINT16_C(37699), UINT16_C(15124), UINT16_C(55247), UINT16_C( 7538), UINT16_C(50864),
      UINT16_C(24078), UINT16_C(13837), UINT16_C(38222), UINT16_C(50671), UINT16_C(40909), UINT16_C(25436), UINT16_C(42904), UINT16_C(24231),
      UINT16_C( 6192), UINT16_C(49965), UINT16_C(28828), UINT16_C(45142), UINT16_C( 9899), UINT16_C( 7559), UINT16_C(14147), UINT16_C(20963),
      UINT16_C(61589), UINT16_C(58247), UINT16_C(30598), UINT16_C(21416), UINT16_C( 1046), UINT16_C(44726), UINT16_C(23980), UINT16_C(56333),
      UINT16_C(14965), UINT16_C( 4511), UINT16_C(63146), UINT16_C(21953), UINT16_C(18460), UINT16_C(24435), UINT16_C(22143), UINT16_C( 5296),
      UINT16_C(14407), UINT16_C(52728), UINT16_C(41135), UINT16_C(50464), UINT16_C(54949), UINT16_C(20851), UINT16_C(32819), UINT16_C(43053),
      UINT16_C(52666), UINT16_C(25785), UINT16_C(31427), UINT16_C(57274), UINT16_C(11714), UINT16_C(16702), UINT16_C(61059), UINT16_C(51797),
      UINT16_C(19750), UINT16_C(54679), UINT16_C(47086), UINT16_C(37786), UINT16_C( 3725), UINT16_C(49380), UINT16_C( 4494), UINT16_C(18792),
      UINT16_C( 8670), UINT16_C(41389), UINT16_C(26523), UINT16_C(23936), UINT16_C(48788), UINT16_C( 6302), UINT16_C(62637), UINT16_C(54242),
      UINT16_C(31297), UINT16_C(12201), UINT16_C(17201), UINT16_C(49090), UINT16_C(42577), UINT16_C(57471), UINT16_C(59576), UINT16_C(38441),
      UINT16_C(54793), UINT16_C(42296), UINT16_C(47166), UINT16_C(53762), UINT16_C(41335), UINT16_C( 9450), UINT16_C(52629), UINT16_C(55031),
      UINT16_C(41031), UINT16_C(30726), UINT16_C(51428), UINT16_C(13623), UINT16_C(46959), UINT16_C(10005), UINT16_C(16031), UINT16_C(43197),
      UINT16_C(62741), UINT16_C(21325), UINT16_C(20654), UINT16_C( 9509), UINT16_C( 4337), UINT16_C(34377), UINT16_C(16605), UINT16_C( 9308),
      UINT16_C(25313), UINT16_C(50588), UINT16_C(54315), UINT16_C(39674), UINT16_C( 4235), UINT16_C(10945), UINT16_C(32334), UINT16_C(25554),
      UINT16_C( 8308), UINT16_C( 8886), UINT16_C(56432), UINT16_C(24903), UINT16_C(37100), UINT16_C(51687), UINT16_C(17360), UINT16_C(45549),
      UINT16_C(35238), UINT16_C(53622), UINT16_C(29021), UINT16_C(59499), UINT16_C(11393), UINT16_C(53010), UINT16_C(58794), UINT16_C( 7731),
      UINT16_C(59653), UINT16_C(30016), UINT16_C(34757), UINT16_C(45526), UINT16_C(48407), UINT16_C(59514), UINT16_C(26368), UINT16_C(42649),
      UINT16_C( 4337), UINT16_C(20087), UINT16_C(57985), UINT16_C(  567), UINT16_C(18702), UINT16_C(47569), UINT16_C( 1070), UINT16_C(13271),
      UINT16_C( 6382), UINT16_C(45992), UINT16_C(32415), UINT16_C(46949), UINT16_C(57147), UINT16_C(15519), UINT16_C(14407), UINT16_C(14562),
      UINT16_C(23112), UINT16_C(51590), UINT16_C(48444), UINT16_C(19403), UINT16_C(40199), UINT16_C(13572), UINT16_C(56225), UINT16_C(36713),
      UINT16_C( 4595), UINT16_C(37699), UINT16_C(43152), UINT16_C(52042), UINT16_C(59783), UINT16_C(52743), UINT16_C(59937), UINT16_C(27142),
      UINT16_C(36164), UINT16_C(32819), UINT16_C(65354), UINT16_C(20939), UINT16_C(53148), UINT16_C(15751), UINT16_C(61611), UINT16_C(40653),
      UINT16_C( 4097), UINT16_C(37169), UINT16_C(31672), UINT16_C(16221), UINT16_C(25700), UINT16_C(34318), UINT16_C( 5198), UINT16_C(37616),
      UINT16_C( 9121), UINT16_C(60435), UINT16_C(56866), UINT16_C(48701), UINT16_C(50350), UINT16_C(23036), UINT16_C(51636), UINT16_C(46839),
      UINT16_C(10713), UINT16_C(37191), UINT16_C(42148), UINT16_C( 2512), UINT16_C(56841), UINT16_C(22415), UINT16_C(32755), UINT16_C(38122),
      UINT16_C(64930), UINT16_C(50560), UINT16_C(48859), UINT16_C(35203), UINT16_C(32642), UINT16_C(14306), UINT16_C(55880), UINT16_C( 8685),
      UINT16_C(13315), UINT16_C(42930), UINT16_C(33753), UINT16_C(58032), UINT16_C(16225), UINT16_C(21561), UINT16_C( 9150), UINT16_C(25065),
      UINT16_C(26912), UINT16_C(64550), UINT16_C(43303), UINT16_C(43653), UINT16_C(26665), UINT16_C(29153), UINT16_C(52802), UINT16_C(17811),
      UINT16_C(17666), UINT16_C(56300), UINT16_C(40392), UINT16_C(10941), UINT16_C(63452), UINT16_C(39806), UINT16_C(26394), UINT16_C(15356),
      UINT16_C( 8913), UINT16_C(63543), UINT16_C(48331), UINT16_C(62626), UINT16_C(33572), UINT16_C(26214), UINT16_C(63825), UINT16_C(21675),
      UINT16_C(38974), UINT16_C( 1839), UINT16_C(60725), UINT16_C( 4401), UINT16_C(45028), UINT16_C(65196), UINT16_C(43031), UINT16_C(59449),
      UINT16_C(28874), UINT16_C(38624), UINT16_C(33581), UINT16_C(20874), UINT16_C(61446), UINT16_C(22712), UINT16_C(25577), UINT16_C(10412),
      UINT16_C(56315), UINT16_C(12335), UINT16_C(24776), UINT16_C(44098), UINT16_C(60943), UINT16_C( 9899), UINT16_C(58519), UINT16_C(24846),
      UINT16_C(61269), UINT16_C(33527), UINT16_C(33394), UINT16_C(30931), UINT16_C(35698), UINT16_C(23760), UINT16_C(31983), UINT16_C(60036),
      UINT16_C(45912), UINT16_C( 8219), UINT16_C(23827), UINT16_C( 8909), UINT16_C(30795), UINT16_C(57929), UINT16_C(22364), UINT16_C(45380),
      UINT16_C(15174), UINT16_C(47155), UINT16_C( 1981), UINT16_C(12337), UINT16_C(  402), UINT16_C(33164), UINT16_C( 4222), UINT16_C(54892),
      UINT16_C(34755), UINT16_C(55030), UINT16_C(50148), UINT16_C(12280), UINT16_C(16699), UINT16_C(38930), UINT16_C(22169), UINT16_C(57161),
      UINT16_C(32145), UINT16_C(20376), UINT16_C(51588), UINT16_C( 5759), UINT16_C( 3018), UINT16_C(18584), UINT16_C( 1051), UINT16_C(56862),
      UINT16_C( 5515), UINT16_C(28596), UINT16_C(44248), UINT16_C( 5278), UINT16_C(45294), UINT16_C(34732) };
  static const uint16_t b[] =
    { UINT16_C(62726), UINT16_C(39014), UINT16_C(65138), UINT16_C(63207), UINT16_C(26311), UINT16_C(37389), UINT16_C(42353), UINT16_C(36058),
      UINT16_C(63913), UINT16_C(13418), UINT16_C( 7694), UINT16_C(59043), UINT16_C(16842), UINT16_C(47354), UINT16_C(42738), UINT16_C(63551),
      UINT16_C(42652), UINT16_C( 3728), UINT16_C(30628), UINT16_C(27653), UINT16_C( 4829), UINT16_C(20222), UINT16_C(55479), UINT16_C(24794),
      UINT16_C(17617), UINT16_C(57236), UINT16_C(14178), UINT16_C(11718), UINT16_C(49272), UINT16_C(27365), UINT16_C( 9575), UINT16_C(  867),
      UINT16_C(62411), UINT16_C(28433), UINT16_C( 5739), UINT16_C(18651), UINT16_C(55592), UINT16_C(57239), UINT16_C(29106), UINT16_C(33599),
      UINT16_C(54198), UINT16_C( 6243), UINT16_C(10506), UINT16_C(33605), UINT16_C(11241), UINT16_C(20717), UINT16_C(20560), UINT16_C( 6995),
      UINT16_C(25924), UINT16_C(44938), UINT16_C(26235), UINT16_C(42231), UINT16_C(36415), UINT16_C(61827), UINT16_C(49920), UINT16_C(46709),
      UINT16_C(55446), UINT16_C(41422), UINT16_C( 5121), UINT16_C(59940), UINT16_C( 4415), UINT16_C(36667), UINT16_C(36450), UINT16_C(42666),
      UINT16_C(13555), UINT16_C(28501), UINT16_C(19610), UINT16_C(55827), UINT16_C(38619), UINT16_C(56267), UINT16_C(16473), UINT16_C(61585),
      UINT16_C(24344), UINT16_C( 6545), UINT16_C(46451), UINT16_C(45572), UINT16_C(16326), UINT16_C(10305), UINT16_C(60365), UINT16_C(49614),
      UINT16_C( 8992), UINT16_C(47664), UINT16_C(17264), UINT16_C(19348), UINT16_C(24793), UINT16_C(13094), UINT16_C(47008), UINT16_C(47395),
      UINT16_C(46102), UINT16_C(35538), UINT16_C(54889), UINT16_C(12092), UINT16_C(32277), UINT16_C(58200), UINT16_C( 9833), UINT16_C(35236),
      UINT16_C(54346), UINT16_C(47684), UINT16_C(55319), UINT16_C(61445), UINT16_C(11064), UINT16_C(55587), UINT16_C(18146), UINT16_C(63634),
      UINT16_C(25850), UINT16_C(25474), UINT16_C(48955), UINT16_C(20627), UINT16_C(60221), UINT16_C(42547), UINT16_C(55057), UINT16_C(23344),
      UINT16_C(29867), UINT16_C(49685), UINT16_C( 6732), UINT16_C(34227), UINT16_C(54853), UINT16_C(10078), UINT16_C(61469), UINT16_C( 5920),
      UINT16_C(41556), UINT16_C(36731), UINT16_C( 3681), UINT16_C(40672), UINT16_C( 5113), UINT16_C( 2629), UINT16_C(30187), UINT16_C(38502),
      UINT16_C(31721), UINT16_C(13657), UINT16_C( 3222), UINT16_C(56250), UINT16_C( 6370), UINT16_C(65283), UINT16_C( 8968), UINT16_C(23831),
      UINT16_C(37573), UINT16_C(10220), UINT16_C(52384), UINT16_C(39365), UINT16_C( 2784), UINT16_C(52131), UINT16_C( 2431), UINT16_C(26721),
      UINT16_C(47749), UINT16_C( 7070), UINT16_C(22726), UINT16_C(43510), UINT16_C(63857), UINT16_C(31144), UINT16_C(48924), UINT16_C(58070),
      UINT16_C(50001), UINT16_C(61705), UINT16_C(52879), UINT16_C(28554), UINT16_C(11993), UINT16_C(22586), UINT16_C(39991), UINT16_C(48321),
      UINT16_C(24406), UINT16_C( 7639), UINT16_C(52919), UINT16_C(10438), UINT16_C(28359), UINT16_C(58530), UINT16_C(30766), UINT16_C(32710),
      UINT16_C(53051), UINT16_C(52081), UINT16_C(64413), UINT16_C(30266), UINT16_C(29993), UINT16_C(25039), UINT16_C(36881), UINT16_C(26397),
      UINT16_C(62959), UINT16_C(42628), UINT16_C(19139), UINT16_C(35535), UINT16_C(29113), UINT16_C(59246), UINT16_C(13545), UINT16_C( 9574),
      UINT16_C(55043), UINT16_C(41456), UINT16_C(10963), UINT16_C(64535), UINT16_C(59039), UINT16_C(45149), UINT16_C(31606), UINT16_C(25880),
      UINT16_C(40048), UINT16_C(13068), UINT16_C(56295), UINT16_C(41149), UINT16_C(11340), UINT16_C(13703), UINT16_C(60768), UINT16_C(25690),
      UINT16_C(19141), UINT16_C(38917), UINT16_C( 7285), UINT16_C( 5268), UINT16_C(61955), UINT16_C(31173), UINT16_C(56685), UINT16_C(56799),
      UINT16_C(60281), UINT16_C(24592), UINT16_C(52678), UINT16_C( 4608), UINT16_C(34809), UINT16_C(23111), UINT16_C(41589), UINT16_C(15038),
      UINT16_C(50156), UINT16_C(25042), UINT16_C(26335), UINT16_C(57974), UINT16_C(15192), UINT16_C(50524), UINT16_C(15128), UINT16_C(37282),
      UINT16_C(45606), UINT16_C(60658), UINT16_C(62080), UINT16_C(31230), UINT16_C(17786), UINT16_C(61395), UINT16_C(37351), UINT16_C(54313),
      UINT16_C(64340), UINT16_C(13365), UINT16_C(43873), UINT16_C(47638), UINT16_C(29414), UINT16_C(65151), UINT16_C( 8877), UINT16_C(54160),
      UINT16_C(33492), UINT16_C(21695), UINT16_C(48500), UINT16_C(61134), UINT16_C(41219), UINT16_C(60125), UINT16_C( 1587), UINT16_C(34750),
      UINT16_C(62465), UINT16_C(25531), UINT16_C(53919), UINT16_C(34333), UINT16_C(40004), UINT16_C(62084), UINT16_C( 5310), UINT16_C(37829),
      UINT16_C(34198), UINT16_C( 3047), UINT16_C(46402), UINT16_C(17913), UINT16_C(55127), UINT16_C(35376), UINT16_C(61149), UINT16_C(57105),
      UINT16_C(52706), UINT16_C(33346), UINT16_C(24479), UINT16_C(58120), UINT16_C(36091), UINT16_C(47829), UINT16_C(39841), UINT16_C(14157),
      UINT16_C(13344), UINT16_C(25154), UINT16_C(15594), UINT16_C(16808), UINT16_C(55315), UINT16_C(61643), UINT16_C(56518), UINT16_C(43471),
      UINT16_C( 4521), UINT16_C(18475), UINT16_C(13168), UINT16_C(27692), UINT16_C(  447), UINT16_C(24614), UINT16_C(29596), UINT16_C(48280),
      UINT16_C(55975), UINT16_C(37151), UINT16_C(50966), UINT16_C(10706), UINT16_C(40351), UINT16_C(25882), UINT16_C(59770), UINT16_C( 8974),
      UINT16_C(14843), UINT16_C(27500), UINT16_C(39020), UINT16_C(11479), UINT16_C(64921), UINT16_C(13964), UINT16_C( 9328), UINT16_C( 6386),
      UINT16_C( 4607), UINT16_C( 5545), UINT16_C(31960), UINT16_C(30527), UINT16_C(22809), UINT16_C(37853), UINT16_C(60226), UINT16_C(15799),
      UINT16_C( 8997), UINT16_C(37289), UINT16_C(32955), UINT16_C(21693), UINT16_C(19070), UINT16_C(61066), UINT16_C(32110), UINT16_C(27910),
      UINT16_C(45198), UINT16_C(26499), UINT16_C(49708), UINT16_C(17886), UINT16_C(47899), UINT16_C(24025), UINT16_C(37031), UINT16_C(52379),
      UINT16_C(17587), UINT16_C(28253), UINT16_C( 7108), UINT16_C(17090), UINT16_C(19813), UINT16_C(54065), UINT16_C(14282), UINT16_C(22593),
      UINT16_C(50407), UINT16_C( 5055), UINT16_C(40582), UINT16_C(41305), UINT16_C(12889), UINT16_C(  254), UINT16_C(39362), UINT16_C(30156),
      UINT16_C(10973), UINT16_C(41699), UINT16_C(42309), UINT16_C(43748), UINT16_C( 5618), UINT16_C(48253), UINT16_C(48717), UINT16_C(13333),
      UINT16_C(54402), UINT16_C( 2120), UINT16_C(41330), UINT16_C(52393), UINT16_C(43219), UINT16_C(38348), UINT16_C(39233), UINT16_C( 7946),
      UINT16_C(60867), UINT16_C( 2241), UINT16_C(42386), UINT16_C(34226), UINT16_C(12219), UINT16_C( 2113), UINT16_C(22254), UINT16_C(28732),
      UINT16_C(33835), UINT16_C(40313), UINT16_C( 8741), UINT16_C(63593), UINT16_C(14026), UINT16_C( 3213), UINT16_C(38863), UINT16_C(37419),
      UINT16_C(60548), UINT16_C( 6042), UINT16_C(19601), UINT16_C(19612), UINT16_C(56699), UINT16_C(26964), UINT16_C(37172), UINT16_C(24538),
      UINT16_C(21269), UINT16_C(15356), UINT16_C(26229), UINT16_C(16435), UINT16_C(49564), UINT16_C(27468), UINT16_C(30552), UINT16_C(56829),
      UINT16_C(38755), UINT16_C(62708), UINT16_C(37091), UINT16_C(24129), UINT16_C(38253), UINT16_C(41416), UINT16_C(41510), UINT16_C(15360),
      UINT16_C(65013), UINT16_C(27255), UINT16_C(43619), UINT16_C(65450), UINT16_C(63083), UINT16_C(50282), UINT16_C(26477), UINT16_C(53409),
      UINT16_C(38398), UINT16_C(57797), UINT16_C( 1573), UINT16_C(37439), UINT16_C( 1947), UINT16_C(49716), UINT16_C(13481), UINT16_C(40702),
      UINT16_C(30001), UINT16_C(37897), UINT16_C(45855), UINT16_C(35731), UINT16_C(64938), UINT16_C( 5967), UINT16_C(61540), UINT16_C(25320),
      UINT16_C(44421), UINT16_C(43587), UINT16_C(33715), UINT16_C(20028), UINT16_C(28810), UINT16_C(13328), UINT16_C( 3749), UINT16_C(54994),
      UINT16_C(56195), UINT16_C(41835), UINT16_C(65167), UINT16_C(14638), UINT16_C(32252), UINT16_C(24656) };
  static const int16_t e[] =
    {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) };

  static int16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svbool_t pv, ev;
    simde_svuint16_t
      av = simde_svld1_u16(pg, &(a[i])),
      bv = simde_svld1_u16(pg, &(b[i]));

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    ev = simde_svcmplt_u16(pv, av, bv);

    simde_svst1_s16(pg, &(r[i]), simde_svdup_n_s16_z(ev, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vi16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(uint16_t)], e[1024 / sizeof(uint16_t)];
  uint16_t a[1024 / sizeof(uint16_t)], b[1024 / sizeof(uint16_t)];
  int32_t len = simde_test_codegen_random_i16() & ((sizeof(e) / sizeof(e[0])) -1);

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t av, bv;
    simde_svbool_t pv, ev;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_u16(pg, &(a[i]));
    bv = simde_svld1_u16(pg, &(b[i]));

    ev = simde_svcmplt_u16(pv, av, bv);

    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));
    simde_svst1_s16(pg, &(e[i]), simde_svdup_n_s16_z(ev, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svcmplt_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0) };
  static const uint32_t a[] =
    { UINT32_C(3603872422), UINT32_C( 808234706), UINT32_C( 520601825), UINT32_C( 979411821), UINT32_C(1823659495), UINT32_C( 940171821), UINT32_C( 604491865), UINT32_C( 391263857),
      UINT32_C(3287097841), UINT32_C(2968721871), UINT32_C(1188035289), UINT32_C(2239836062), UINT32_C( 854668037), UINT32_C(1852504597), UINT32_C( 999453130), UINT32_C(2572346792),
      UINT32_C(3579592454), UINT32_C( 830820440), UINT32_C(3900200010), UINT32_C(2305751428), UINT32_C(1102798636), UINT32_C( 615458138), UINT32_C(1046495638), UINT32_C( 752333350),
      UINT32_C(1241593074), UINT32_C(3464267396), UINT32_C(1605891291), UINT32_C( 434644461), UINT32_C(3730482052), UINT32_C(1577257416), UINT32_C(1906139978), UINT32_C( 127759381),
      UINT32_C( 743612328) };
  static const uint32_t b[] =
    { UINT32_C(  16502309), UINT32_C(2942284482), UINT32_C(1539852247), UINT32_C(2990154474), UINT32_C(1964064043), UINT32_C(3051794080), UINT32_C(3418194978), UINT32_C(1224150819),
      UINT32_C(2672423645), UINT32_C(2068752548), UINT32_C(3671529200), UINT32_C(1670189368), UINT32_C(4007173710), UINT32_C(1856225100), UINT32_C(1715036227), UINT32_C(1286484335),
      UINT32_C(3370907427), UINT32_C(2420324768), UINT32_C(2271877711), UINT32_C(2045441835), UINT32_C(3781673877), UINT32_C(3310357378), UINT32_C(3677063531), UINT32_C(3727153594),
      UINT32_C(1906709457), UINT32_C(2617370956), UINT32_C( 790850308), UINT32_C(4171828835), UINT32_C(1406800081), UINT32_C(2266507803), UINT32_C(1851933619), UINT32_C(3981216028),
      UINT32_C(3915313820) };
  static const int32_t e[] =
    {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0) };

  static int32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svbool_t pv, ev;
    simde_svuint32_t
      av = simde_svld1_u32(pg, &(a[i])),
      bv = simde_svld1_u32(pg, &(b[i]));

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    ev = simde_svcmplt_u32(pv, av, bv);

    simde_svst1_s32(pg, &(r[i]), simde_svdup_n_s32_z(ev, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vi32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)], e[1024 / sizeof(int32_t)];
  uint32_t a[1024 / sizeof(int32_t)], b[1024 / sizeof(int32_t)];
  int32_t len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) -1);

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t av, bv;
    simde_svbool_t pv, ev;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_u32(pg, &(a[i]));
    bv = simde_svld1_u32(pg, &(b[i]));

    ev = simde_svcmplt_u32(pv, av, bv);

    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));
    simde_svst1_s32(pg, &(e[i]), simde_svdup_n_s32_z(ev, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svcmplt_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1) };
  static const uint64_t a[] =
    { UINT64_C(11916227837588595609), UINT64_C(  711979398422470116), UINT64_C( 7444396629704810646), UINT64_C( 1339748843932424856),
      UINT64_C( 9537722001996492193), UINT64_C(14298646445972962024), UINT64_C( 9318508280817785247), UINT64_C( 9701812313525004055),
      UINT64_C(14093058300098449520), UINT64_C( 5857378479525900884), UINT64_C(  943940583359772848), UINT64_C( 8583650915672540595),
      UINT64_C( 5400128172333685842), UINT64_C( 6976101869622729165), UINT64_C( 5409125067281402639), UINT64_C( 4888097681259605847),
      UINT64_C( 5088893277704314207), UINT64_C(10559698141907872891), UINT64_C(17042650773753136032), UINT64_C(14450962040410039896),
      UINT64_C(15654156470845308030), UINT64_C( 4124892198896665384), UINT64_C(15462252245498844434), UINT64_C( 9190908959335112539),
      UINT64_C(10222806550153963943), UINT64_C( 9550578387881943736), UINT64_C( 5449849164528417869), UINT64_C( 1377990897547853984),
      UINT64_C(  159868211831543364), UINT64_C( 3949620487504752857), UINT64_C( 6563613533882416090), UINT64_C(  423931834158294371),
      UINT64_C(14699440160784775857), UINT64_C(  753760508034044502), UINT64_C( 9076980969697998560), UINT64_C(13895344341474145040),
      UINT64_C(14043835982197589288), UINT64_C(13854892009103424268), UINT64_C( 1550172878280530924), UINT64_C( 2671969374686334789),
      UINT64_C(10912262075166216258), UINT64_C(15257943646286344479), UINT64_C(12920928955134450485), UINT64_C( 3913095857394103851),
      UINT64_C(15063507979106291179), UINT64_C( 3422613648140525765), UINT64_C(16270583741249313195), UINT64_C(15643631464171033584),
      UINT64_C( 1614640872401337829), UINT64_C( 8458959436361382203), UINT64_C( 8588745501590867355), UINT64_C( 8643661755703769901),
      UINT64_C(15697709499937604465), UINT64_C( 8786649172855921840), UINT64_C(  449792450568486463), UINT64_C( 9025237897403602998),
      UINT64_C( 8561372329190379097), UINT64_C(10380199352859680438), UINT64_C(  522018233135847007), UINT64_C(15038944634913972268),
      UINT64_C(14310917961027221086), UINT64_C(14580236031239031415), UINT64_C( 7932598446123560509), UINT64_C( 6190298800354420385),
      UINT64_C(13846056785262784593), UINT64_C( 2797544506219004317), UINT64_C(13131734645525042317), UINT64_C(10411678291639329586),
      UINT64_C(12065170931139606119), UINT64_C( 7181414938662926234), UINT64_C( 6566651955365731926) };
  static const uint64_t b[] =
    { UINT64_C(  946039211642122066), UINT64_C(14314741078333133560), UINT64_C( 3485490183964022820), UINT64_C( 6004913490053861840),
      UINT64_C(15159122780997605805), UINT64_C( 7929005277369867543), UINT64_C( 1504140997874504404), UINT64_C(16549710724831476569),
      UINT64_C(12531433729248759867), UINT64_C(  967984997433654453), UINT64_C(17916334852223588171), UINT64_C( 5635408392619208726),
      UINT64_C(13461625445667859599), UINT64_C(  382850748775055625), UINT64_C(13661449187728035071), UINT64_C( 8595471633690126824),
      UINT64_C(  318469126443740844), UINT64_C( 5615592146259617070), UINT64_C(11675445395125470115), UINT64_C(18360304121692361325),
      UINT64_C(  257860578929764245), UINT64_C( 1574811205261646656), UINT64_C(13239006523031537245), UINT64_C(15333024174860687481),
      UINT64_C(15138841978720254015), UINT64_C( 4277358468138009556), UINT64_C(11169504466776079105), UINT64_C( 2699960644255747685),
      UINT64_C(12181199968848698535), UINT64_C(12064100678993144915), UINT64_C( 3658317955045965575), UINT64_C(    4027897250982402),
      UINT64_C(16981180389118265131), UINT64_C(17005461232286472625), UINT64_C(16809361141897949767), UINT64_C(10906556574802713602),
      UINT64_C(10135986319123780903), UINT64_C(10928797377412515802), UINT64_C(11071520892967960277), UINT64_C( 9011791186711901709),
      UINT64_C(14000819228920031205), UINT64_C(16831125072247861421), UINT64_C( 4402913157885280233), UINT64_C( 5013568921898717120),
      UINT64_C( 7140828527741751150), UINT64_C(12573474864123386497), UINT64_C( 3287989932826501683), UINT64_C(10159231386364630872),
      UINT64_C(15258471868695445926), UINT64_C( 5190931925395054741), UINT64_C(15681900595884341256), UINT64_C( 7083755105758012836),
      UINT64_C(14029978569908629902), UINT64_C(  791829803028978847), UINT64_C(11148415647245838685), UINT64_C( 7143742368500238341),
      UINT64_C(  129471209472844508), UINT64_C( 7647589411553928981), UINT64_C(14261774945973018715), UINT64_C(15096534291855067464),
      UINT64_C(15343383219950765452), UINT64_C(12827392304258720908), UINT64_C(10822975970345176493), UINT64_C(17149202023056652344),
      UINT64_C(  688146384890353914), UINT64_C( 3636277942119790701), UINT64_C(11662020010101930484), UINT64_C(13391678616636394377),
      UINT64_C(16873860237964260260), UINT64_C( 7578753837086723702), UINT64_C( 2785619980461984925) };
  static const int64_t e[] =
    {  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) };

  static int64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svbool_t pv, ev;
    simde_svuint64_t
      av = simde_svld1_u64(pg, &(a[i])),
      bv = simde_svld1_u64(pg, &(b[i]));

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    ev = simde_svcmplt_u64(pv, av, bv);

    simde_svst1_s64(pg, &(r[i]), simde_svdup_n_s64_z(ev, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vi64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  uint64_t a[1024 / sizeof(int64_t)], b[1024 / sizeof(int64_t)];
  int32_t len = simde_test_codegen_random_i64() & ((sizeof(e) / sizeof(e[0])) -1);

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, b));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t av, bv;
    simde_svbool_t pv, ev;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_u64(pg, &(a[i]));
    bv = simde_svld1_u64(pg, &(b[i]));

    ev = simde_svcmplt_u64(pv, av, bv);

    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));
    simde_svst1_s64(pg, &(e[i]), simde_svdup_n_s64_z(ev, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svcmplt_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) };
  static const simde_float32 a[] =
    { SIMDE_FLOAT32_C(   -91.01), SIMDE_FLOAT32_C(   330.29), SIMDE_FLOAT32_C(  -472.15), SIMDE_FLOAT32_C(  -113.20),
      SIMDE_FLOAT32_C(   444.83), SIMDE_FLOAT32_C(   564.94), SIMDE_FLOAT32_C(   263.04), SIMDE_FLOAT32_C(  -643.49),
      SIMDE_FLOAT32_C(  -399.55), SIMDE_FLOAT32_C(   827.07), SIMDE_FLOAT32_C(   860.22), SIMDE_FLOAT32_C(   929.73),
      SIMDE_FLOAT32_C(  -808.98), SIMDE_FLOAT32_C(  -704.70), SIMDE_FLOAT32_C(   358.61), SIMDE_FLOAT32_C(  -705.77),
      SIMDE_FLOAT32_C(   607.37), SIMDE_FLOAT32_C(   627.69), SIMDE_FLOAT32_C(  -326.02), SIMDE_FLOAT32_C(    54.58),
      SIMDE_FLOAT32_C(  -739.91), SIMDE_FLOAT32_C(   342.01), SIMDE_FLOAT32_C(  -844.35), SIMDE_FLOAT32_C(   727.20),
      SIMDE_FLOAT32_C(   536.80), SIMDE_FLOAT32_C(   574.40), SIMDE_FLOAT32_C(  -947.97), SIMDE_FLOAT32_C(  -537.36),
      SIMDE_FLOAT32_C(   712.97), SIMDE_FLOAT32_C(   926.59), SIMDE_FLOAT32_C(  -299.09), SIMDE_FLOAT32_C(  -378.04),
      SIMDE_FLOAT32_C(   256.89), SIMDE_FLOAT32_C(   228.76), SIMDE_FLOAT32_C(   508.76), SIMDE_FLOAT32_C(  -298.29),
      SIMDE_FLOAT32_C(  -206.31), SIMDE_FLOAT32_C(  -228.20), SIMDE_FLOAT32_C(    58.22), SIMDE_FLOAT32_C(   394.14),
      SIMDE_FLOAT32_C(  -401.13), SIMDE_FLOAT32_C(   -81.56), SIMDE_FLOAT32_C(   323.87), SIMDE_FLOAT32_C(  -210.11),
      SIMDE_FLOAT32_C(   213.75), SIMDE_FLOAT32_C(  -317.52), SIMDE_FLOAT32_C(    84.13), SIMDE_FLOAT32_C(  -178.88),
      SIMDE_FLOAT32_C(  -689.84), SIMDE_FLOAT32_C(   758.10), SIMDE_FLOAT32_C(   875.70), SIMDE_FLOAT32_C(  -429.74),
      SIMDE_FLOAT32_C(   100.11), SIMDE_FLOAT32_C(  -968.65), SIMDE_FLOAT32_C(  -702.55), SIMDE_FLOAT32_C(  -363.09),
      SIMDE_FLOAT32_C(   605.75), SIMDE_FLOAT32_C(  -650.51), SIMDE_FLOAT32_C(    99.56), SIMDE_FLOAT32_C(   318.72),
      SIMDE_FLOAT32_C(  -723.92), SIMDE_FLOAT32_C(   800.46), SIMDE_FLOAT32_C(   940.68), SIMDE_FLOAT32_C(   532.97),
      SIMDE_FLOAT32_C(    29.22), SIMDE_FLOAT32_C(   449.44), SIMDE_FLOAT32_C(  -765.32), SIMDE_FLOAT32_C(   822.91),
      SIMDE_FLOAT32_C(  -778.76), SIMDE_FLOAT32_C(   292.90), SIMDE_FLOAT32_C(   217.05), SIMDE_FLOAT32_C(  -179.89),
      SIMDE_FLOAT32_C(  -788.66), SIMDE_FLOAT32_C(  -459.08), SIMDE_FLOAT32_C(   610.01), SIMDE_FLOAT32_C(   425.09),
      SIMDE_FLOAT32_C(   223.39), SIMDE_FLOAT32_C(  -305.87), SIMDE_FLOAT32_C(  -753.79), SIMDE_FLOAT32_C(   533.56),
      SIMDE_FLOAT32_C(  -547.77), SIMDE_FLOAT32_C(  -878.09), SIMDE_FLOAT32_C(  -896.19), SIMDE_FLOAT32_C(   552.35),
      SIMDE_FLOAT32_C(  -846.74), SIMDE_FLOAT32_C(  -598.73), SIMDE_FLOAT32_C(  -810.74), SIMDE_FLOAT32_C(   759.01),
      SIMDE_FLOAT32_C(  -249.25), SIMDE_FLOAT32_C(   288.81), SIMDE_FLOAT32_C(    77.73), SIMDE_FLOAT32_C(    26.83),
      SIMDE_FLOAT32_C(    89.28), SIMDE_FLOAT32_C(    18.41), SIMDE_FLOAT32_C(  -440.20), SIMDE_FLOAT32_C(  -881.51),
      SIMDE_FLOAT32_C(  -532.14), SIMDE_FLOAT32_C(  -205.52), SIMDE_FLOAT32_C(   941.40), SIMDE_FLOAT32_C(  -310.90),
      SIMDE_FLOAT32_C(  -912.61), SIMDE_FLOAT32_C(   158.45), SIMDE_FLOAT32_C(   509.22), SIMDE_FLOAT32_C(  -701.27),
      SIMDE_FLOAT32_C(   699.37), SIMDE_FLOAT32_C(   119.22), SIMDE_FLOAT32_C(   723.82), SIMDE_FLOAT32_C(   -77.24),
      SIMDE_FLOAT32_C(   813.35), SIMDE_FLOAT32_C(   970.03), SIMDE_FLOAT32_C(  -543.68), SIMDE_FLOAT32_C(  -734.41),
      SIMDE_FLOAT32_C(  -908.06), SIMDE_FLOAT32_C(  -439.87), SIMDE_FLOAT32_C(   817.93), SIMDE_FLOAT32_C(  -754.80),
      SIMDE_FLOAT32_C(   -38.60), SIMDE_FLOAT32_C(  -992.81), SIMDE_FLOAT32_C(  -995.79), SIMDE_FLOAT32_C(   712.15),
      SIMDE_FLOAT32_C(   296.01), SIMDE_FLOAT32_C(    81.95), SIMDE_FLOAT32_C(  -261.02), SIMDE_FLOAT32_C(  -614.72),
      SIMDE_FLOAT32_C(  -899.64), SIMDE_FLOAT32_C(   298.79), SIMDE_FLOAT32_C(  -496.22), SIMDE_FLOAT32_C(  -431.78),
      SIMDE_FLOAT32_C(  -906.73), SIMDE_FLOAT32_C(  -554.82), SIMDE_FLOAT32_C(   257.32), SIMDE_FLOAT32_C(  -819.34),
      SIMDE_FLOAT32_C(   603.63), SIMDE_FLOAT32_C(  -233.46), SIMDE_FLOAT32_C(  -520.61), SIMDE_FLOAT32_C(   303.01),
      SIMDE_FLOAT32_C(   885.76), SIMDE_FLOAT32_C(  -796.79), SIMDE_FLOAT32_C(  -774.23), SIMDE_FLOAT32_C(   699.11),
      SIMDE_FLOAT32_C(  -826.76), SIMDE_FLOAT32_C(  -317.91), SIMDE_FLOAT32_C(   964.70), SIMDE_FLOAT32_C(  -734.82),
      SIMDE_FLOAT32_C(   242.22), SIMDE_FLOAT32_C(   782.63), SIMDE_FLOAT32_C(  -489.62), SIMDE_FLOAT32_C(  -796.38),
      SIMDE_FLOAT32_C(   789.82), SIMDE_FLOAT32_C(  -485.40), SIMDE_FLOAT32_C(   915.77), SIMDE_FLOAT32_C(    85.82),
      SIMDE_FLOAT32_C(   596.54), SIMDE_FLOAT32_C(  -345.25), SIMDE_FLOAT32_C(   471.11), SIMDE_FLOAT32_C(   696.90),
      SIMDE_FLOAT32_C(   953.54), SIMDE_FLOAT32_C(   974.88), SIMDE_FLOAT32_C(  -734.88), SIMDE_FLOAT32_C(  -953.19),
      SIMDE_FLOAT32_C(  -579.94), SIMDE_FLOAT32_C(   522.44), SIMDE_FLOAT32_C(  -772.53), SIMDE_FLOAT32_C(  -976.30),
      SIMDE_FLOAT32_C(  -711.02), SIMDE_FLOAT32_C(  -293.15), SIMDE_FLOAT32_C(   326.70), SIMDE_FLOAT32_C(  -825.27),
      SIMDE_FLOAT32_C(   -89.94), SIMDE_FLOAT32_C(   552.47), SIMDE_FLOAT32_C(   873.84), SIMDE_FLOAT32_C(    83.31),
      SIMDE_FLOAT32_C(  -765.44), SIMDE_FLOAT32_C(   838.54), SIMDE_FLOAT32_C(   348.49), SIMDE_FLOAT32_C(   476.79),
      SIMDE_FLOAT32_C(   621.17), SIMDE_FLOAT32_C(   858.87), SIMDE_FLOAT32_C(   680.40), SIMDE_FLOAT32_C(   410.98),
      SIMDE_FLOAT32_C(  -626.53), SIMDE_FLOAT32_C(   596.17), SIMDE_FLOAT32_C(  -503.19), SIMDE_FLOAT32_C(   970.01) };
  static const simde_float32 b[] =
    { SIMDE_FLOAT32_C(  -749.08), SIMDE_FLOAT32_C(   967.91), SIMDE_FLOAT32_C(   666.91), SIMDE_FLOAT32_C(  -795.54),
      SIMDE_FLOAT32_C(   942.80), SIMDE_FLOAT32_C(   932.03), SIMDE_FLOAT32_C(  -748.73), SIMDE_FLOAT32_C(  -637.14),
      SIMDE_FLOAT32_C(   454.47), SIMDE_FLOAT32_C(  -521.26), SIMDE_FLOAT32_C(  -613.44), SIMDE_FLOAT32_C(   743.45),
      SIMDE_FLOAT32_C(   185.59), SIMDE_FLOAT32_C(   713.26), SIMDE_FLOAT32_C(   918.18), SIMDE_FLOAT32_C(  -904.34),
      SIMDE_FLOAT32_C(   265.74), SIMDE_FLOAT32_C(   792.02), SIMDE_FLOAT32_C(   178.96), SIMDE_FLOAT32_C(   500.30),
      SIMDE_FLOAT32_C(   630.56), SIMDE_FLOAT32_C(  -472.55), SIMDE_FLOAT32_C(   -22.91), SIMDE_FLOAT32_C(   251.73),
      SIMDE_FLOAT32_C(  -613.68), SIMDE_FLOAT32_C(  -342.51), SIMDE_FLOAT32_C(  -337.29), SIMDE_FLOAT32_C(  -240.21),
      SIMDE_FLOAT32_C(  -746.34), SIMDE_FLOAT32_C(   159.52), SIMDE_FLOAT32_C(  -270.20), SIMDE_FLOAT32_C(  -495.41),
      SIMDE_FLOAT32_C(   127.44), SIMDE_FLOAT32_C(  -603.29), SIMDE_FLOAT32_C(  -290.95), SIMDE_FLOAT32_C(    70.23),
      SIMDE_FLOAT32_C(  -671.25), SIMDE_FLOAT32_C(   -39.68), SIMDE_FLOAT32_C(   433.09), SIMDE_FLOAT32_C(   783.22),
      SIMDE_FLOAT32_C(   439.06), SIMDE_FLOAT32_C(   819.65), SIMDE_FLOAT32_C(   526.66), SIMDE_FLOAT32_C(  -375.35),
      SIMDE_FLOAT32_C(   532.91), SIMDE_FLOAT32_C(   444.85), SIMDE_FLOAT32_C(  -279.69), SIMDE_FLOAT32_C(  -201.35),
      SIMDE_FLOAT32_C(   236.87), SIMDE_FLOAT32_C(   899.27), SIMDE_FLOAT32_C(  -701.05), SIMDE_FLOAT32_C(  -132.57),
      SIMDE_FLOAT32_C(  -573.28), SIMDE_FLOAT32_C(   276.04), SIMDE_FLOAT32_C(  -880.84), SIMDE_FLOAT32_C(  -186.96),
      SIMDE_FLOAT32_C(   933.53), SIMDE_FLOAT32_C(  -218.13), SIMDE_FLOAT32_C(   572.83), SIMDE_FLOAT32_C(  -812.80),
      SIMDE_FLOAT32_C(   941.40), SIMDE_FLOAT32_C(  -697.37), SIMDE_FLOAT32_C(  -308.22), SIMDE_FLOAT32_C(    68.83),
      SIMDE_FLOAT32_C(  -300.65), SIMDE_FLOAT32_C(   400.83), SIMDE_FLOAT32_C(  -860.93), SIMDE_FLOAT32_C(    28.09),
      SIMDE_FLOAT32_C(  -638.85), SIMDE_FLOAT32_C(   572.16), SIMDE_FLOAT32_C(  -188.69), SIMDE_FLOAT32_C(   800.21),
      SIMDE_FLOAT32_C(   391.81), SIMDE_FLOAT32_C(  -662.03), SIMDE_FLOAT32_C(  -575.14), SIMDE_FLOAT32_C(   -75.27),
      SIMDE_FLOAT32_C(   782.82), SIMDE_FLOAT32_C(   145.16), SIMDE_FLOAT32_C(   723.38), SIMDE_FLOAT32_C(    19.69),
      SIMDE_FLOAT32_C(    44.43), SIMDE_FLOAT32_C(  -977.67), SIMDE_FLOAT32_C(   887.12), SIMDE_FLOAT32_C(   471.15),
      SIMDE_FLOAT32_C(   298.38), SIMDE_FLOAT32_C(  -993.72), SIMDE_FLOAT32_C(  -715.81), SIMDE_FLOAT32_C(   231.91),
      SIMDE_FLOAT32_C(  -211.84), SIMDE_FLOAT32_C(   857.02), SIMDE_FLOAT32_C(   419.11), SIMDE_FLOAT32_C(  -270.45),
      SIMDE_FLOAT32_C(  -840.34), SIMDE_FLOAT32_C(  -889.11), SIMDE_FLOAT32_C(   798.39), SIMDE_FLOAT32_C(  -141.00),
      SIMDE_FLOAT32_C(   511.72), SIMDE_FLOAT32_C(   937.46), SIMDE_FLOAT32_C(   887.09), SIMDE_FLOAT32_C(   872.88),
      SIMDE_FLOAT32_C(   509.62), SIMDE_FLOAT32_C(  -301.60), SIMDE_FLOAT32_C(   673.08), SIMDE_FLOAT32_C(   -98.57),
      SIMDE_FLOAT32_C(    36.38), SIMDE_FLOAT32_C(  -902.06), SIMDE_FLOAT32_C(   826.16), SIMDE_FLOAT32_C(  -180.80),
      SIMDE_FLOAT32_C(   243.10), SIMDE_FLOAT32_C(   549.54), SIMDE_FLOAT32_C(   838.89), SIMDE_FLOAT32_C(  -712.47),
      SIMDE_FLOAT32_C(   571.87), SIMDE_FLOAT32_C(   726.01), SIMDE_FLOAT32_C(   758.68), SIMDE_FLOAT32_C(  -129.76),
      SIMDE_FLOAT32_C(   732.29), SIMDE_FLOAT32_C(  -957.12), SIMDE_FLOAT32_C(  -897.85), SIMDE_FLOAT32_C(  -479.55),
      SIMDE_FLOAT32_C(   899.90), SIMDE_FLOAT32_C(   521.26), SIMDE_FLOAT32_C(   250.00), SIMDE_FLOAT32_C(  -940.44),
      SIMDE_FLOAT32_C(   632.15), SIMDE_FLOAT32_C(    48.39), SIMDE_FLOAT32_C(   -81.44), SIMDE_FLOAT32_C(   143.88),
      SIMDE_FLOAT32_C(   -14.15), SIMDE_FLOAT32_C(  -194.35), SIMDE_FLOAT32_C(    16.75), SIMDE_FLOAT32_C(  -504.54),
      SIMDE_FLOAT32_C(   504.06), SIMDE_FLOAT32_C(  -310.16), SIMDE_FLOAT32_C(   396.89), SIMDE_FLOAT32_C(  -459.57),
      SIMDE_FLOAT32_C(  -212.22), SIMDE_FLOAT32_C(   223.05), SIMDE_FLOAT32_C(   359.63), SIMDE_FLOAT32_C(  -969.11),
      SIMDE_FLOAT32_C(  -227.41), SIMDE_FLOAT32_C(   198.52), SIMDE_FLOAT32_C(  -681.58), SIMDE_FLOAT32_C(  -655.54),
      SIMDE_FLOAT32_C(   -75.48), SIMDE_FLOAT32_C(  -922.89), SIMDE_FLOAT32_C(   214.70), SIMDE_FLOAT32_C(  -343.18),
      SIMDE_FLOAT32_C(  -880.02), SIMDE_FLOAT32_C(   316.85), SIMDE_FLOAT32_C(   177.26), SIMDE_FLOAT32_C(  -980.12),
      SIMDE_FLOAT32_C(  -161.89), SIMDE_FLOAT32_C(  -572.73), SIMDE_FLOAT32_C(  -920.56), SIMDE_FLOAT32_C(  -529.73),
      SIMDE_FLOAT32_C(   475.66), SIMDE_FLOAT32_C(    -2.01), SIMDE_FLOAT32_C(   614.15), SIMDE_FLOAT32_C(  -538.49),
      SIMDE_FLOAT32_C(   803.65), SIMDE_FLOAT32_C(  -369.10), SIMDE_FLOAT32_C(   -43.03), SIMDE_FLOAT32_C(   307.70),
      SIMDE_FLOAT32_C(   320.74), SIMDE_FLOAT32_C(  -646.14), SIMDE_FLOAT32_C(   848.14), SIMDE_FLOAT32_C(  -891.48),
      SIMDE_FLOAT32_C(   576.92), SIMDE_FLOAT32_C(   207.77), SIMDE_FLOAT32_C(  -860.59), SIMDE_FLOAT32_C(  -650.50),
      SIMDE_FLOAT32_C(  -593.72), SIMDE_FLOAT32_C(  -542.17), SIMDE_FLOAT32_C(  -306.04), SIMDE_FLOAT32_C(   330.81),
      SIMDE_FLOAT32_C(  -465.07), SIMDE_FLOAT32_C(   908.66), SIMDE_FLOAT32_C(   987.62), SIMDE_FLOAT32_C(  -345.09),
      SIMDE_FLOAT32_C(   225.51), SIMDE_FLOAT32_C(   164.89), SIMDE_FLOAT32_C(  -325.21), SIMDE_FLOAT32_C(  -936.37) };
  static const int32_t e[] =
    {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) };

  static int32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svbool_t pv, ev;
    simde_svfloat32_t
      av = simde_svld1_f32(pg, &(a[i])),
      bv = simde_svld1_f32(pg, &(b[i]));

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    ev = simde_svcmplt_f32(pv, av, bv);

    simde_svst1_s32(pg, &(r[i]), simde_svdup_n_s32_z(ev, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vi32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)], e[1024 / sizeof(int32_t)];
  simde_float32 a[1024 / sizeof(int32_t)], b[1024 / sizeof(int32_t)];
  int32_t len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) - 1);

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf32(len, a, SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  simde_test_codegen_random_vf32(len, b, SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svfloat32_t av, bv;
    simde_svbool_t pv, ev;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_f32(pg, &(a[i]));
    bv = simde_svld1_f32(pg, &(b[i]));

    ev = simde_svcmplt_f32(pv, av, bv);

    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));
    simde_svst1_s32(pg, &(e[i]), simde_svdup_n_s32_z(ev, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svcmplt_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) };
  static const simde_float64 a[] =
    { SIMDE_FLOAT64_C(   595.54), SIMDE_FLOAT64_C(  -852.85), SIMDE_FLOAT64_C(  -318.15), SIMDE_FLOAT64_C(  -743.45),
      SIMDE_FLOAT64_C(  -558.95), SIMDE_FLOAT64_C(   850.28), SIMDE_FLOAT64_C(    15.80), SIMDE_FLOAT64_C(   420.10),
      SIMDE_FLOAT64_C(   530.70), SIMDE_FLOAT64_C(   172.92), SIMDE_FLOAT64_C(   511.22), SIMDE_FLOAT64_C(   971.98),
      SIMDE_FLOAT64_C(  -942.14), SIMDE_FLOAT64_C(   698.17), SIMDE_FLOAT64_C(   647.48), SIMDE_FLOAT64_C(  -404.55),
      SIMDE_FLOAT64_C(   552.77), SIMDE_FLOAT64_C(   359.04), SIMDE_FLOAT64_C(   716.51), SIMDE_FLOAT64_C(  -464.91),
      SIMDE_FLOAT64_C(   331.18), SIMDE_FLOAT64_C(  -865.71), SIMDE_FLOAT64_C(   159.75), SIMDE_FLOAT64_C(  -429.02),
      SIMDE_FLOAT64_C(   226.26), SIMDE_FLOAT64_C(   -91.05), SIMDE_FLOAT64_C(   304.34), SIMDE_FLOAT64_C(   600.46),
      SIMDE_FLOAT64_C(  -510.32), SIMDE_FLOAT64_C(  -392.78), SIMDE_FLOAT64_C(  -138.41), SIMDE_FLOAT64_C(  -914.78),
      SIMDE_FLOAT64_C(  -245.63), SIMDE_FLOAT64_C(   543.44), SIMDE_FLOAT64_C(  -658.23), SIMDE_FLOAT64_C(   195.43),
      SIMDE_FLOAT64_C(   393.72), SIMDE_FLOAT64_C(   357.57), SIMDE_FLOAT64_C(  -384.47), SIMDE_FLOAT64_C(   -75.58),
      SIMDE_FLOAT64_C(  -469.51), SIMDE_FLOAT64_C(  -873.25), SIMDE_FLOAT64_C(  -103.60), SIMDE_FLOAT64_C(  -411.65),
      SIMDE_FLOAT64_C(   824.92), SIMDE_FLOAT64_C(  -456.12), SIMDE_FLOAT64_C(   183.81), SIMDE_FLOAT64_C(   377.69),
      SIMDE_FLOAT64_C(   902.92), SIMDE_FLOAT64_C(   -99.69), SIMDE_FLOAT64_C(   912.78), SIMDE_FLOAT64_C(   234.11),
      SIMDE_FLOAT64_C(    34.60), SIMDE_FLOAT64_C(    72.54), SIMDE_FLOAT64_C(   805.09), SIMDE_FLOAT64_C(  -739.14),
      SIMDE_FLOAT64_C(   981.49), SIMDE_FLOAT64_C(   109.43), SIMDE_FLOAT64_C(   861.33), SIMDE_FLOAT64_C(  -528.83),
      SIMDE_FLOAT64_C(   716.64), SIMDE_FLOAT64_C(  -277.08), SIMDE_FLOAT64_C(  -443.61), SIMDE_FLOAT64_C(  -528.99),
      SIMDE_FLOAT64_C(  -733.64), SIMDE_FLOAT64_C(  -101.84), SIMDE_FLOAT64_C(   666.44), SIMDE_FLOAT64_C(   660.08),
      SIMDE_FLOAT64_C(  -744.27), SIMDE_FLOAT64_C(  -718.03), SIMDE_FLOAT64_C(  -415.50), SIMDE_FLOAT64_C(  -213.78),
      SIMDE_FLOAT64_C(  -591.28), SIMDE_FLOAT64_C(   480.90), SIMDE_FLOAT64_C(   374.58), SIMDE_FLOAT64_C(  -766.36),
      SIMDE_FLOAT64_C(  -975.21), SIMDE_FLOAT64_C(  -441.62), SIMDE_FLOAT64_C(   611.33), SIMDE_FLOAT64_C(   927.71),
      SIMDE_FLOAT64_C(   458.70), SIMDE_FLOAT64_C(   524.11), SIMDE_FLOAT64_C(   161.82), SIMDE_FLOAT64_C(  -506.70) };
  static const simde_float64 b[] =
    { SIMDE_FLOAT64_C(  -403.35), SIMDE_FLOAT64_C(   -33.09), SIMDE_FLOAT64_C(  -245.84), SIMDE_FLOAT64_C(  -421.86),
      SIMDE_FLOAT64_C(  -923.67), SIMDE_FLOAT64_C(  -384.51), SIMDE_FLOAT64_C(    49.31), SIMDE_FLOAT64_C(   792.97),
      SIMDE_FLOAT64_C(   338.40), SIMDE_FLOAT64_C(   605.70), SIMDE_FLOAT64_C(  -736.01), SIMDE_FLOAT64_C(   604.77),
      SIMDE_FLOAT64_C(  -496.14), SIMDE_FLOAT64_C(   930.43), SIMDE_FLOAT64_C(   264.85), SIMDE_FLOAT64_C(  -240.41),
      SIMDE_FLOAT64_C(  -787.60), SIMDE_FLOAT64_C(   849.35), SIMDE_FLOAT64_C(   545.82), SIMDE_FLOAT64_C(  -378.89),
      SIMDE_FLOAT64_C(   330.25), SIMDE_FLOAT64_C(   -79.60), SIMDE_FLOAT64_C(  -145.25), SIMDE_FLOAT64_C(   355.04),
      SIMDE_FLOAT64_C(   478.78), SIMDE_FLOAT64_C(  -533.92), SIMDE_FLOAT64_C(   282.75), SIMDE_FLOAT64_C(   -62.52),
      SIMDE_FLOAT64_C(   990.20), SIMDE_FLOAT64_C(  -555.43), SIMDE_FLOAT64_C(   430.78), SIMDE_FLOAT64_C(  -413.15),
      SIMDE_FLOAT64_C(   411.48), SIMDE_FLOAT64_C(  -815.06), SIMDE_FLOAT64_C(   164.99), SIMDE_FLOAT64_C(   487.81),
      SIMDE_FLOAT64_C(  -199.58), SIMDE_FLOAT64_C(  -785.71), SIMDE_FLOAT64_C(   280.79), SIMDE_FLOAT64_C(  -861.17),
      SIMDE_FLOAT64_C(   820.00), SIMDE_FLOAT64_C(   544.78), SIMDE_FLOAT64_C(   743.59), SIMDE_FLOAT64_C(  -676.14),
      SIMDE_FLOAT64_C(   475.20), SIMDE_FLOAT64_C(     8.44), SIMDE_FLOAT64_C(    83.45), SIMDE_FLOAT64_C(   687.60),
      SIMDE_FLOAT64_C(  -142.20), SIMDE_FLOAT64_C(  -370.73), SIMDE_FLOAT64_C(  -691.29), SIMDE_FLOAT64_C(  -811.95),
      SIMDE_FLOAT64_C(   549.67), SIMDE_FLOAT64_C(   163.46), SIMDE_FLOAT64_C(   543.09), SIMDE_FLOAT64_C(    28.45),
      SIMDE_FLOAT64_C(   629.55), SIMDE_FLOAT64_C(  -174.15), SIMDE_FLOAT64_C(   965.93), SIMDE_FLOAT64_C(   619.75),
      SIMDE_FLOAT64_C(   270.42), SIMDE_FLOAT64_C(   396.70), SIMDE_FLOAT64_C(  -793.41), SIMDE_FLOAT64_C(  -318.10),
      SIMDE_FLOAT64_C(   581.64), SIMDE_FLOAT64_C(   371.58), SIMDE_FLOAT64_C(  -830.29), SIMDE_FLOAT64_C(  -617.94),
      SIMDE_FLOAT64_C(   585.87), SIMDE_FLOAT64_C(   450.50), SIMDE_FLOAT64_C(  -479.11), SIMDE_FLOAT64_C(   405.87),
      SIMDE_FLOAT64_C(    -4.72), SIMDE_FLOAT64_C(  -735.52), SIMDE_FLOAT64_C(   729.73), SIMDE_FLOAT64_C(  -529.52),
      SIMDE_FLOAT64_C(   272.93), SIMDE_FLOAT64_C(  -186.82), SIMDE_FLOAT64_C(  -841.92), SIMDE_FLOAT64_C(  -869.27),
      SIMDE_FLOAT64_C(   442.45), SIMDE_FLOAT64_C(  -533.21), SIMDE_FLOAT64_C(  -681.22), SIMDE_FLOAT64_C(    -7.88) };
  static const int64_t e[] =
    {  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) };

  static int64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svbool_t pv, ev;
    simde_svfloat64_t
      av = simde_svld1_f64(pg, &(a[i])),
      bv = simde_svld1_f64(pg, &(b[i]));

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    ev = simde_svcmplt_f64(pv, av, bv);

    simde_svst1_s64(pg, &(r[i]), simde_svdup_n_s64_z(ev, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vi64(len, e, r);

  return 0;
#else
  simde_float64 a[1024 / sizeof(int64_t)], b[1024 / sizeof(int64_t)];
  int64_t p[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_codegen_random_i64() & (sizeof(e) / sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf64(len, a, SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  simde_test_codegen_random_vf64(len, b, SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svfloat64_t av, bv;
    simde_svbool_t pv, ev;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_f64(pg, &(a[i]));
    bv = simde_svld1_f64(pg, &(b[i]));

    ev = simde_svcmplt_f64(pv, av, bv);

    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));
    simde_svst1_s64(pg, &(e[i]), simde_svdup_n_s64_z(ev, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), b);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(svcmplt_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(svcmplt_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(svcmplt_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(svcmplt_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(svcmplt_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(svcmplt_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(svcmplt_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(svcmplt_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(svcmplt_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(svcmplt_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-sve-footer.h"
