#define SIMDE_TEST_ARM_SVE_INSN sub

#include "test-sve.h"
#include "../../../simde/arm/sve/sub.h"

#include "../../../simde/arm/sve/cmplt.h"

static int
test_simde_svsub_s8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) };
  static const int8_t a[] =
    {  INT8_C(  97),  INT8_C(  20),  INT8_C( 122), -INT8_C(  70), -INT8_C(  49), -INT8_C(  66), -INT8_C( 109),  INT8_C(  30),
      -INT8_C(  44), -INT8_C(  17),  INT8_C(  85),  INT8_C(  12),  INT8_C(   3), -INT8_C( 108), -INT8_C(  30), -INT8_C(  49),
       INT8_C( 123),  INT8_C(  18),  INT8_C(  57),  INT8_C(  49), -INT8_C(  34),  INT8_C(  67), -INT8_C( 115), -INT8_C(  41),
      -INT8_C(   4),  INT8_C( 107), -INT8_C(  85), -INT8_C(  66), -INT8_C(  66), -INT8_C(  35), -INT8_C(  25),  INT8_C(  32),
      -INT8_C(  14),  INT8_C(  98), -INT8_C(  38), -INT8_C(  63),  INT8_C(  32),  INT8_C( 110), -INT8_C(  33), -INT8_C(  12),
       INT8_C(  93),  INT8_C(  52),  INT8_C(   0),  INT8_C(  96), -INT8_C(  56), -INT8_C(  29),  INT8_C(  47),  INT8_C(  68),
      -INT8_C(  11),  INT8_C( 104),  INT8_C( 117), -INT8_C(  44), -INT8_C(  84),  INT8_C(   3), -INT8_C(  85), -INT8_C(  88),
       INT8_C( 110),  INT8_C(  86),  INT8_C( 102),  INT8_C(  44),  INT8_C(  51),  INT8_C(  78),  INT8_C(  76),  INT8_C(  37),
      -INT8_C(  80),  INT8_C(  39), -INT8_C(  26), -INT8_C(  48), -INT8_C( 107), -INT8_C(  59), -INT8_C(  59), -INT8_C(  14),
      -INT8_C(   7), -INT8_C(  59),  INT8_C(  82), -INT8_C(  62), -INT8_C(  88), -INT8_C( 126),  INT8_C(   6), -INT8_C(  98),
      -INT8_C(  22),  INT8_C( 123),  INT8_C( 114), -INT8_C( 106),  INT8_C( 126),  INT8_C(  29),  INT8_C(  62), -INT8_C(  20),
       INT8_C( 115), -INT8_C(  91),  INT8_C(  25), -INT8_C(  90), -INT8_C(  13),  INT8_C( 101), -INT8_C(  52), -INT8_C(  93),
      -INT8_C( 116), -INT8_C(  78),  INT8_C( 115),  INT8_C(  33),  INT8_C( 120),  INT8_C(  56),  INT8_C(  19),  INT8_C( 113),
      -INT8_C(   2),  INT8_C( 102),  INT8_C(  51), -INT8_C(  90), -INT8_C(  24),  INT8_C(  57),  INT8_C(  68), -INT8_C(  46),
      -INT8_C(  75), -INT8_C(  74),  INT8_C( 105),  INT8_C(  51), -INT8_C(  45), -INT8_C(  89),  INT8_C(  32),  INT8_C(  70),
       INT8_C(  76),  INT8_C(  57), -INT8_C(  19),  INT8_C(  63), -INT8_C(  98), -INT8_C(  71), -INT8_C(  30),  INT8_C(  43),
       INT8_C( 107),  INT8_C(  86),  INT8_C(  76), -INT8_C(  29), -INT8_C( 114),  INT8_C(  96),  INT8_C(  85), -INT8_C( 116),
      -INT8_C(  58), -INT8_C( 120),  INT8_C(  51), -INT8_C(  82), -INT8_C(  62),  INT8_C( 119),      INT8_MIN,  INT8_C( 119),
       INT8_C(  46), -INT8_C(  23), -INT8_C(  86),  INT8_C(   1), -INT8_C( 111), -INT8_C(  54),  INT8_C(  72), -INT8_C(  35),
       INT8_C(   3),  INT8_C(  53),  INT8_C(  29), -INT8_C(  94), -INT8_C(  18), -INT8_C(   1), -INT8_C(  51),  INT8_C(  89),
       INT8_C(  85),  INT8_C(  25),  INT8_C(  61), -INT8_C(  28),  INT8_C( 121), -INT8_C( 110),  INT8_C( 112),  INT8_C(  63),
       INT8_C(  26), -INT8_C(  93), -INT8_C(  19), -INT8_C(  36),  INT8_C(  27),  INT8_C( 110),  INT8_C(  83),  INT8_C(  73),
       INT8_C(  87), -INT8_C(   2),  INT8_C(  74), -INT8_C(  24), -INT8_C(  56), -INT8_C( 110), -INT8_C(  58), -INT8_C(  52),
      -INT8_C(  57), -INT8_C(  29),  INT8_C( 110), -INT8_C(  75), -INT8_C(  30),  INT8_C(  59),  INT8_C(  15),  INT8_C(  56),
       INT8_C(  84),  INT8_C(  76),  INT8_C(  28), -INT8_C(  50), -INT8_C(  34), -INT8_C( 116),  INT8_C(  13), -INT8_C(   8),
       INT8_C(  48), -INT8_C(   5), -INT8_C(  43),  INT8_C(  75),  INT8_C( 105),  INT8_C(  40), -INT8_C( 108), -INT8_C(  64),
       INT8_C(  38), -INT8_C(  34), -INT8_C(  87), -INT8_C(  17),  INT8_C( 113),  INT8_C( 111), -INT8_C(  69),  INT8_C(  56),
       INT8_C(  82),  INT8_C(  41), -INT8_C(  18),  INT8_C(  52),  INT8_C( 100), -INT8_C(   3),  INT8_C( 108), -INT8_C(  72),
       INT8_C(  73), -INT8_C( 120), -INT8_C( 122),  INT8_C(  39),  INT8_C(  21), -INT8_C( 108),  INT8_C(  31),  INT8_C(  69),
      -INT8_C( 113), -INT8_C(  12), -INT8_C( 112), -INT8_C(   8),  INT8_C(  29),  INT8_C(  36), -INT8_C(  72),  INT8_C(  67),
       INT8_C(   2),  INT8_C(  97),  INT8_C(  50),  INT8_C( 115), -INT8_C(  48), -INT8_C(  19), -INT8_C(  84),  INT8_C(  34),
       INT8_C(  22), -INT8_C( 102),  INT8_C(  87),  INT8_C( 122), -INT8_C( 105), -INT8_C(  61),  INT8_C(  51), -INT8_C(  32),
       INT8_C(  76), -INT8_C(  71),  INT8_C(   7),  INT8_C(  97),  INT8_C(  77),  INT8_C(  38), -INT8_C(  90), -INT8_C(  36),
       INT8_C(  27),  INT8_C(  54), -INT8_C(  44),  INT8_C(  56),  INT8_C(  90), -INT8_C( 115),  INT8_C( 123),  INT8_C(  92),
      -INT8_C(  18), -INT8_C(  82), -INT8_C(  48), -INT8_C(  65), -INT8_C( 101),  INT8_C( 124), -INT8_C(  31), -INT8_C(  78),
       INT8_C(  22),  INT8_C(  56),  INT8_C(  44), -INT8_C(  83), -INT8_C(   4),  INT8_C(  95), -INT8_C( 115),  INT8_C(  72),
       INT8_C(  25), -INT8_C( 108), -INT8_C(  87),  INT8_C( 102), -INT8_C(  70),  INT8_C(  79),  INT8_C(  67), -INT8_C(  43),
      -INT8_C( 123),  INT8_C(  23),  INT8_C(  13), -INT8_C(  33), -INT8_C(  92), -INT8_C( 119),  INT8_C(  59), -INT8_C( 109),
       INT8_C(  55),  INT8_C(  11),  INT8_C(  82), -INT8_C(  46), -INT8_C( 121),  INT8_C(  51), -INT8_C( 124), -INT8_C(  99),
       INT8_C( 108), -INT8_C(  79),  INT8_C(  74),  INT8_C( 104),  INT8_C(  16), -INT8_C(  41), -INT8_C(  80),  INT8_C(  41),
       INT8_C( 107),  INT8_C(  89), -INT8_C( 112),  INT8_C(  38), -INT8_C(  88), -INT8_C(  45), -INT8_C(   5),  INT8_C(  45),
      -INT8_C(  22),  INT8_C(   9),  INT8_C(  12), -INT8_C( 113), -INT8_C( 110),  INT8_C(  71),  INT8_C(  34), -INT8_C(  55),
       INT8_C(  83),  INT8_C( 116), -INT8_C( 101), -INT8_C(  38), -INT8_C(  89),  INT8_C(  32),  INT8_C( 120),  INT8_C(  19),
      -INT8_C(  47), -INT8_C(  62),  INT8_C( 123), -INT8_C(  31), -INT8_C( 102),  INT8_C(  43),  INT8_C(  11),  INT8_C(   5),
      -INT8_C( 124), -INT8_C( 101),  INT8_C(  43),  INT8_C(  44),  INT8_C( 110),  INT8_C(  39),  INT8_C(  89),  INT8_C(  88),
       INT8_C(  48),  INT8_C( 101), -INT8_C(  25), -INT8_C(  62), -INT8_C(  83),  INT8_C(   9), -INT8_C( 117),  INT8_C(   0),
       INT8_C( 125),  INT8_C(  38), -INT8_C(  38),  INT8_C(  37),  INT8_C(  70),  INT8_C(  82),  INT8_C(  56),  INT8_C(  23),
       INT8_C(  21), -INT8_C(  76), -INT8_C(   7), -INT8_C(  81), -INT8_C(  33),  INT8_C(   4), -INT8_C(  76),  INT8_C( 100),
      -INT8_C(  97), -INT8_C(  32), -INT8_C( 112),  INT8_C(  13),  INT8_C(   7), -INT8_C(  22),  INT8_C( 101),  INT8_C(  55),
       INT8_C(  79),  INT8_C(  77), -INT8_C(   7), -INT8_C(   4),  INT8_C(  86), -INT8_C( 124), -INT8_C(   4), -INT8_C(  44),
      -INT8_C(  86), -INT8_C(  41), -INT8_C(   7), -INT8_C(  15),  INT8_C(  41),  INT8_C(  49),  INT8_C(   8),  INT8_C(  62),
      -INT8_C(  27),  INT8_C(   1), -INT8_C(  19), -INT8_C(  59),  INT8_C(   5), -INT8_C(  94),  INT8_C(  41), -INT8_C(  92),
      -INT8_C( 126), -INT8_C(  71), -INT8_C(  79), -INT8_C( 119), -INT8_C(  93),  INT8_C(  23), -INT8_C(  64), -INT8_C(  13),
       INT8_C( 100), -INT8_C(  71), -INT8_C(  17), -INT8_C(  70),  INT8_C(  61), -INT8_C(  20), -INT8_C( 114), -INT8_C(  25),
      -INT8_C(  61), -INT8_C( 121), -INT8_C(  40), -INT8_C(  20), -INT8_C(  71), -INT8_C(  31),  INT8_C(  43), -INT8_C(  98),
      -INT8_C(  30),  INT8_C(  24),  INT8_C(  99), -INT8_C(  24), -INT8_C(  70), -INT8_C( 116), -INT8_C( 116),  INT8_C(  60),
       INT8_C(  70),  INT8_C(  62), -INT8_C(  59), -INT8_C(  23),  INT8_C(  85), -INT8_C( 123), -INT8_C(  36), -INT8_C(  71),
       INT8_C(  62), -INT8_C(  52),  INT8_C( 115),  INT8_C( 123), -INT8_C(  72),  INT8_C(   2),  INT8_C(  99),  INT8_C( 123),
      -INT8_C( 119),  INT8_C(  59),  INT8_C( 103),  INT8_C(  66),  INT8_C(  28), -INT8_C( 110), -INT8_C(  31), -INT8_C(   1),
      -INT8_C(  85),  INT8_C(  68), -INT8_C(  25),  INT8_C( 101), -INT8_C(  47),  INT8_C( 115), -INT8_C(  94),  INT8_C(  23),
      -INT8_C(  79),  INT8_C( 103),  INT8_C(   0),  INT8_C(   6), -INT8_C(  19), -INT8_C(  35), -INT8_C(  65),  INT8_C(  43),
      -INT8_C(  87),  INT8_C(  51), -INT8_C(  89),  INT8_C(  97),  INT8_C(  53),  INT8_C(  10), -INT8_C(  36), -INT8_C(  66),
       INT8_C(  69),  INT8_C(  67),  INT8_C(   1),  INT8_C(  98), -INT8_C(  42), -INT8_C(  30),  INT8_C(  97), -INT8_C( 127),
       INT8_C(  38),  INT8_C(  72), -INT8_C(  26), -INT8_C(   9), -INT8_C(  69), -INT8_C( 120),  INT8_C(  14),  INT8_C( 109),
      -INT8_C(  16),  INT8_C(  15),  INT8_C( 115), -INT8_C(  35), -INT8_C(  20),  INT8_C(  51),  INT8_C(   8), -INT8_C( 107),
       INT8_C( 102), -INT8_C(  81), -INT8_C(  10), -INT8_C( 101), -INT8_C(  71), -INT8_C(  46),  INT8_C(  89), -INT8_C(   1),
       INT8_C(  21),  INT8_C(  90),  INT8_C(  97), -INT8_C(  21),  INT8_C(  60), -INT8_C(  62),  INT8_C( 108),  INT8_C(  99),
       INT8_C(  10),  INT8_C(  83),  INT8_C(  90), -INT8_C(  59), -INT8_C(  37),  INT8_C( 105),  INT8_C(  50), -INT8_C(  53),
       INT8_C( 120), -INT8_C(  90), -INT8_C(  88),  INT8_C( 100), -INT8_C(  39), -INT8_C(  79), -INT8_C(   7),  INT8_C(  63),
       INT8_C(  96), -INT8_C(  17), -INT8_C(  38),  INT8_C(  26), -INT8_C(  63),  INT8_C(  51),  INT8_C(  25), -INT8_C(  42),
      -INT8_C( 114),  INT8_C( 122), -INT8_C(  62), -INT8_C(  54),  INT8_C(  60),  INT8_C(  46),  INT8_C(  45),  INT8_C(  70),
      -INT8_C( 127), -INT8_C( 120),  INT8_C(  11),  INT8_C(  93), -INT8_C(  15),  INT8_C(  62),  INT8_C(  40),  INT8_C( 105),
      -INT8_C(  28), -INT8_C(  47), -INT8_C(  51), -INT8_C(  67), -INT8_C( 126), -INT8_C(  58), -INT8_C(   4), -INT8_C(  30),
      -INT8_C(  75), -INT8_C(  42), -INT8_C(   4),  INT8_C( 118),  INT8_C(   9),  INT8_C(  21),  INT8_C(  76), -INT8_C( 105),
      -INT8_C( 113),  INT8_C(  14),  INT8_C(  98), -INT8_C(  53),  INT8_C(  61), -INT8_C( 113),  INT8_C(  17), -INT8_C(  66),
       INT8_C(  23),  INT8_C(  29),  INT8_C(  27),  INT8_C(   8),  INT8_C(  91),  INT8_C(  68),  INT8_C( 113),  INT8_C(  63),
       INT8_C(  21),  INT8_C(  62), -INT8_C(   4), -INT8_C( 105),  INT8_C(   4), -INT8_C(   8),  INT8_C( 121), -INT8_C(  71),
      -INT8_C(  50),  INT8_C( 118),  INT8_C(  47), -INT8_C(  41), -INT8_C( 117),  INT8_C( 124),  INT8_C( 111),  INT8_C(  27),
      -INT8_C( 118), -INT8_C(  47), -INT8_C(  26), -INT8_C(  57),  INT8_C(  96), -INT8_C(   8), -INT8_C( 122),  INT8_C( 120),
       INT8_C(  21), -INT8_C(  95),      INT8_MIN,  INT8_C( 112), -INT8_C(  27), -INT8_C(  14), -INT8_C(  81), -INT8_C(   6),
       INT8_C(  48), -INT8_C(  85), -INT8_C( 111),  INT8_C(  53), -INT8_C(  93),  INT8_C(  11), -INT8_C(  18),  INT8_C( 113),
      -INT8_C( 127),  INT8_C(  30),  INT8_C(  72),  INT8_C(  12), -INT8_C( 102), -INT8_C(  73),  INT8_C(  39),  INT8_C(  36),
      -INT8_C( 120),  INT8_C(  14), -INT8_C(  20), -INT8_C(  23),  INT8_C(   6),  INT8_C( 114),  INT8_C(  97),  INT8_C(  27),
       INT8_C(  19), -INT8_C(  31), -INT8_C( 117), -INT8_C(   7), -INT8_C(  45),  INT8_C(  58), -INT8_C(  13),  INT8_C(   4),
      -INT8_C(  27), -INT8_C( 123),  INT8_C(  57), -INT8_C( 120), -INT8_C( 112),  INT8_C(  39), -INT8_C(   7),  INT8_C(  17),
       INT8_C(  69),  INT8_C(  65),  INT8_C(  29), -INT8_C(  33), -INT8_C(   7),  INT8_C(  69),  INT8_C(   4), -INT8_C( 127),
       INT8_C(  83), -INT8_C(  16),  INT8_C( 106),  INT8_C(  89),  INT8_C(  98), -INT8_C(  53),  INT8_C( 116),  INT8_C( 117),
      -INT8_C(  83), -INT8_C(   1),  INT8_C( 110) };
  static const int8_t b[] =
    { -INT8_C(  18),  INT8_C(  28),  INT8_C(  18), -INT8_C(   3),  INT8_C(  93), -INT8_C(  61),  INT8_C(  64),  INT8_C(  73),
       INT8_C(  78),  INT8_C(  11),  INT8_C( 113),  INT8_C(  38),  INT8_C(  67), -INT8_C( 104),  INT8_C(  27), -INT8_C(  92),
      -INT8_C(  34), -INT8_C( 100), -INT8_C( 106),  INT8_C(  48),      INT8_MIN, -INT8_C(  43),  INT8_C(  62), -INT8_C(  50),
       INT8_C(  77), -INT8_C(   9), -INT8_C(  61),  INT8_C(  33), -INT8_C( 107),  INT8_C(  52), -INT8_C(  65), -INT8_C( 125),
       INT8_C(  80), -INT8_C(  47),      INT8_MIN, -INT8_C(  83), -INT8_C( 108), -INT8_C(  63), -INT8_C(  10), -INT8_C(  30),
      -INT8_C(  52),  INT8_C( 103),  INT8_C(   9),  INT8_C(  15),  INT8_C(   0),  INT8_C(  36), -INT8_C(  77), -INT8_C(  34),
      -INT8_C(  64),  INT8_C(  74),  INT8_C(  15),  INT8_C(  65),  INT8_C(  31),  INT8_C(  77),  INT8_C(  15),  INT8_C( 108),
       INT8_C(  68), -INT8_C(  46), -INT8_C( 114), -INT8_C(  39),  INT8_C(   6),  INT8_C(  77),  INT8_C(  93),  INT8_C(  86),
       INT8_C(  30), -INT8_C(  35),  INT8_C(   3), -INT8_C(  78), -INT8_C(  98), -INT8_C(   7), -INT8_C( 108),  INT8_C( 107),
       INT8_C(  97), -INT8_C(  99),  INT8_C( 122),  INT8_C(  97), -INT8_C(  62),  INT8_C(  46),  INT8_C(  63), -INT8_C( 126),
       INT8_C( 120),  INT8_C(  78), -INT8_C(  61), -INT8_C( 105), -INT8_C( 101), -INT8_C(  45),  INT8_C(   3), -INT8_C(  32),
      -INT8_C(  91), -INT8_C( 111), -INT8_C(  71), -INT8_C(  84), -INT8_C(  34),  INT8_C(  22),  INT8_C(   2), -INT8_C(   4),
      -INT8_C(  12),  INT8_C(   6), -INT8_C(  82), -INT8_C( 110), -INT8_C(   1),  INT8_C(  67), -INT8_C(   3),  INT8_C(  96),
      -INT8_C(  32),  INT8_C( 120), -INT8_C(  63), -INT8_C(  94), -INT8_C(  90),  INT8_C(   1),  INT8_C(  37),  INT8_C(  30),
       INT8_C(  79), -INT8_C(  24), -INT8_C(  75), -INT8_C(  21), -INT8_C(  69), -INT8_C(  72), -INT8_C(  53),  INT8_C(  97),
       INT8_C(  74), -INT8_C( 124),  INT8_C(  13),  INT8_C(  40), -INT8_C( 101),  INT8_C(  15),  INT8_C(  37), -INT8_C( 113),
       INT8_C(  21), -INT8_C(  45),  INT8_C(  33),  INT8_C(  21),  INT8_C(  22),  INT8_C(  31),  INT8_C( 117), -INT8_C(   9),
      -INT8_C( 105),  INT8_C(  55), -INT8_C( 103),  INT8_C(  61),  INT8_C(  56), -INT8_C(  66),  INT8_C(  91), -INT8_C( 121),
      -INT8_C(  89),  INT8_C(  16),  INT8_C( 114),  INT8_C(  98), -INT8_C(  56),  INT8_C(  61), -INT8_C(  61),  INT8_C(  18),
      -INT8_C(  62), -INT8_C(  48),  INT8_C(  59),  INT8_C(  93), -INT8_C(  32),  INT8_C(  96), -INT8_C(  20), -INT8_C(  11),
       INT8_C(  51),  INT8_C(  13),  INT8_C(  10),  INT8_C(  74),  INT8_C(  44),      INT8_MIN,  INT8_C(  65), -INT8_C(  61),
      -INT8_C(  73), -INT8_C(  38),  INT8_C(   0), -INT8_C(  17), -INT8_C( 103),  INT8_C(  91),  INT8_C( 118),  INT8_C(  64),
       INT8_C( 107), -INT8_C(  23), -INT8_C(  94),  INT8_C(  52),  INT8_C(  38),  INT8_C( 102),  INT8_C(  70), -INT8_C(  24),
       INT8_C(  54), -INT8_C( 127),  INT8_C(  69),  INT8_C(  22), -INT8_C(  31),  INT8_C(  49),  INT8_C(  12),  INT8_C(  21),
       INT8_C(  63),  INT8_C(  22),  INT8_C(  95),  INT8_C( 107), -INT8_C( 106), -INT8_C(  96),  INT8_C(  47),  INT8_C(  77),
       INT8_C( 122),  INT8_C(  47),  INT8_C(  60),  INT8_C(  19), -INT8_C( 117), -INT8_C(  77),  INT8_C(  83), -INT8_C(  10),
      -INT8_C( 100), -INT8_C(  10),  INT8_C(  42), -INT8_C(  62),  INT8_C(  92),  INT8_C( 113), -INT8_C(  85), -INT8_C( 110),
      -INT8_C(  14), -INT8_C(  16), -INT8_C(  87), -INT8_C(  44),  INT8_C(  34), -INT8_C(  75), -INT8_C(  23),  INT8_C(  97),
      -INT8_C(  53),  INT8_C(  72), -INT8_C(  52),  INT8_C(  98), -INT8_C(  24), -INT8_C(   5), -INT8_C(  81),  INT8_C(  98),
       INT8_C(  43), -INT8_C(  20),  INT8_C( 118), -INT8_C(  74), -INT8_C(  97), -INT8_C(  55), -INT8_C(  84),  INT8_C(  59),
      -INT8_C(  65), -INT8_C(  41), -INT8_C(   3),  INT8_C(  27),  INT8_C(  72), -INT8_C(  88), -INT8_C(  82),  INT8_C(  58),
      -INT8_C( 103),  INT8_C(  87),  INT8_C(  14), -INT8_C(  69),  INT8_C(  12), -INT8_C(   9),  INT8_C(  28), -INT8_C(  41),
       INT8_C(  63), -INT8_C(  24),  INT8_C(  57),  INT8_C(  39), -INT8_C(  28), -INT8_C(  23), -INT8_C( 118),  INT8_C(  15),
      -INT8_C(  43),  INT8_C(   0), -INT8_C(  59),  INT8_C( 116), -INT8_C(  55),  INT8_C( 113), -INT8_C(  81), -INT8_C( 119),
       INT8_C(  72), -INT8_C(  84), -INT8_C(  92), -INT8_C( 112),  INT8_C(  85),  INT8_C(  82), -INT8_C(  53), -INT8_C(  18),
      -INT8_C(  87), -INT8_C(  39), -INT8_C(  87), -INT8_C(  75), -INT8_C(  47), -INT8_C(  59), -INT8_C( 115),  INT8_C(  16),
      -INT8_C(  83), -INT8_C(  58),  INT8_C(  56), -INT8_C( 111), -INT8_C(  81), -INT8_C(  62), -INT8_C(  96), -INT8_C( 124),
      -INT8_C(  62),  INT8_C( 101), -INT8_C(   8), -INT8_C( 117), -INT8_C(  41), -INT8_C(  89),  INT8_C(  20),  INT8_C(  31),
       INT8_C(  84), -INT8_C(  71), -INT8_C(  80), -INT8_C(  87),  INT8_C(  11),  INT8_C( 123), -INT8_C( 105), -INT8_C(  75),
       INT8_C(  84),  INT8_C(  64),  INT8_C( 106),  INT8_C(  37),  INT8_C(   5), -INT8_C(   9),  INT8_C(  54), -INT8_C(  78),
      -INT8_C(  66),  INT8_C( 110),  INT8_C(  68),  INT8_C( 109),  INT8_C(  48), -INT8_C(  28), -INT8_C(  14), -INT8_C(  14),
       INT8_C(  74), -INT8_C(  22),  INT8_C( 125),  INT8_C(  33), -INT8_C( 110), -INT8_C( 110),  INT8_C(  64), -INT8_C(  26),
       INT8_C(  75), -INT8_C(  16), -INT8_C( 113),  INT8_C(  86),  INT8_C( 107),  INT8_C(  38),  INT8_C(  11), -INT8_C(  64),
       INT8_C( 102),  INT8_C( 118), -INT8_C(  27),  INT8_C( 107),  INT8_C( 109),  INT8_C(  27),  INT8_C(  29),  INT8_C(  43),
      -INT8_C( 119),  INT8_C(  97), -INT8_C( 103), -INT8_C(  71),  INT8_C(  70), -INT8_C( 117), -INT8_C(  85), -INT8_C( 112),
       INT8_C( 117),  INT8_C(  41), -INT8_C(  79),  INT8_C(   7), -INT8_C(  69), -INT8_C(  15), -INT8_C(  19),  INT8_C(   6),
      -INT8_C(  30),  INT8_C( 124),  INT8_C(  92),  INT8_C(  77), -INT8_C(  94),  INT8_C( 104),  INT8_C(  13),  INT8_C(   8),
      -INT8_C(  34), -INT8_C(  13),  INT8_C( 115),  INT8_C(  75),  INT8_C(  14), -INT8_C( 111),  INT8_C( 119), -INT8_C( 104),
      -INT8_C(  14),  INT8_C(  16),  INT8_C(  81),  INT8_C(  56), -INT8_C( 101), -INT8_C(   3), -INT8_C(  56),  INT8_C(  16),
       INT8_C(  38),  INT8_C( 121),  INT8_C(  24), -INT8_C(  31),  INT8_C( 107),  INT8_C(   5), -INT8_C(  25),  INT8_C(  77),
      -INT8_C( 126),  INT8_C(  67), -INT8_C( 102),  INT8_C(  36), -INT8_C(  85), -INT8_C(  88),  INT8_C(  45), -INT8_C( 119),
      -INT8_C( 101), -INT8_C(  96), -INT8_C(  43), -INT8_C(  87),  INT8_C(  49),  INT8_C(  76),  INT8_C(  65),  INT8_C(  36),
       INT8_C(  92), -INT8_C( 109),  INT8_C(  92), -INT8_C(   9), -INT8_C( 112),  INT8_C(  37),  INT8_C(   7), -INT8_C(  74),
      -INT8_C(  98),  INT8_C(  31), -INT8_C( 105),  INT8_C(   9),  INT8_C(  37),  INT8_C( 126),  INT8_C(  86), -INT8_C(  89),
      -INT8_C(  63), -INT8_C(  15), -INT8_C(  53),  INT8_C( 109), -INT8_C( 103), -INT8_C(   8), -INT8_C(  10),  INT8_C(  52),
      -INT8_C( 103), -INT8_C(  53), -INT8_C(  35), -INT8_C(  54),  INT8_C(  23),  INT8_C(  31), -INT8_C(  18),  INT8_C( 115),
      -INT8_C(  78),  INT8_C(  75),  INT8_C( 106),  INT8_C(  66),  INT8_C( 112),  INT8_C( 114), -INT8_C(   8),  INT8_C(  14),
      -INT8_C( 111), -INT8_C( 113),  INT8_C(  24), -INT8_C(  74),  INT8_C(  13),  INT8_C( 110),  INT8_C(  93), -INT8_C(  50),
       INT8_C(  95),  INT8_C(  41),  INT8_C(  59), -INT8_C(   8),  INT8_C(  33),  INT8_C(  50),  INT8_C(  44), -INT8_C(  70),
      -INT8_C(   3),  INT8_C(  10), -INT8_C( 123),  INT8_C(  21),  INT8_C(  41),  INT8_C( 115), -INT8_C( 120), -INT8_C(  37),
      -INT8_C(  66), -INT8_C(  13),  INT8_C(  29),  INT8_C(  46),  INT8_C( 101),  INT8_C(  21),  INT8_C(  61), -INT8_C(  10),
      -INT8_C(  92),  INT8_C(  85), -INT8_C(  83), -INT8_C(  79), -INT8_C(  61),  INT8_C(  10),      INT8_MAX,  INT8_C(  35),
       INT8_C(  51), -INT8_C(  69),  INT8_C(  27),  INT8_C(  85), -INT8_C(  19),  INT8_C(  72),  INT8_C(  15), -INT8_C(  22),
       INT8_C(  82), -INT8_C( 108), -INT8_C(   1),  INT8_C( 123),  INT8_C(   8), -INT8_C( 120),  INT8_C(  86), -INT8_C(  58),
       INT8_C( 123),  INT8_C( 115), -INT8_C(  11), -INT8_C(  32), -INT8_C( 120),  INT8_C(  50), -INT8_C(  42),  INT8_C(  44),
      -INT8_C( 121), -INT8_C( 125), -INT8_C(  35),  INT8_C(  74), -INT8_C( 114),  INT8_C(  92),  INT8_C( 109), -INT8_C(  63),
       INT8_C(  23), -INT8_C( 119),  INT8_C(  22),  INT8_C(   4), -INT8_C(  47),  INT8_C(  38), -INT8_C(  17),  INT8_C(  35),
      -INT8_C(  70), -INT8_C(  18), -INT8_C(  98), -INT8_C(  62),  INT8_C( 118), -INT8_C(  12), -INT8_C( 119), -INT8_C(  15),
       INT8_C( 103),  INT8_C( 126), -INT8_C(  47), -INT8_C(  17), -INT8_C(  80), -INT8_C(  88),  INT8_C(  27),  INT8_C(  55),
       INT8_C(  43), -INT8_C(   8), -INT8_C( 127), -INT8_C(  71),  INT8_C(  84), -INT8_C(  17),  INT8_C( 123),  INT8_C( 108),
       INT8_C( 120), -INT8_C( 111),  INT8_C( 112),  INT8_C(  73), -INT8_C(  73),  INT8_C(  95),  INT8_C( 108),  INT8_C( 114),
       INT8_C(  78),  INT8_C(  10),  INT8_C(  52), -INT8_C(  60), -INT8_C(   2), -INT8_C(  67), -INT8_C(  74),  INT8_C( 101),
       INT8_C(  59), -INT8_C( 121),  INT8_C(  84), -INT8_C(  21),  INT8_C(  47),  INT8_C( 111),  INT8_C(  34),  INT8_C(  91),
       INT8_C( 103), -INT8_C(  92),  INT8_C(  20), -INT8_C(  69), -INT8_C( 109), -INT8_C( 113),  INT8_C(  39),  INT8_C(  11),
       INT8_C(  33), -INT8_C( 104),  INT8_C(  84), -INT8_C(  40), -INT8_C(   9), -INT8_C(  64),  INT8_C(  74),  INT8_C(  69),
      -INT8_C(  54),      INT8_MAX,  INT8_C(  10), -INT8_C(  56),  INT8_C(  60), -INT8_C(  64),  INT8_C(  45),  INT8_C( 120),
       INT8_C(  71), -INT8_C( 127),  INT8_C(  99),  INT8_C( 119), -INT8_C(  16), -INT8_C( 122), -INT8_C(  46),  INT8_C(  87),
       INT8_C(  42), -INT8_C(  26),  INT8_C(  18), -INT8_C(  67),  INT8_C( 118),  INT8_C(  58), -INT8_C(  56), -INT8_C( 105),
      -INT8_C(  46),  INT8_C(  28),  INT8_C( 111), -INT8_C(  55), -INT8_C(  36), -INT8_C(  70),  INT8_C(  15), -INT8_C(  90),
       INT8_C(  57),  INT8_C(  25),  INT8_C( 110),  INT8_C( 117), -INT8_C(  39), -INT8_C( 101), -INT8_C(  19),  INT8_C(  32),
       INT8_C(  28),  INT8_C(  81), -INT8_C( 105),  INT8_C(  12), -INT8_C(  41),  INT8_C( 105),  INT8_C(  99),  INT8_C(   1),
       INT8_C(  80),  INT8_C( 117), -INT8_C(  66), -INT8_C(  58), -INT8_C(  81), -INT8_C( 122),  INT8_C(  93), -INT8_C( 127),
      -INT8_C(  94), -INT8_C(  52),  INT8_C(  75),  INT8_C( 126), -INT8_C( 122),  INT8_C(  90),  INT8_C(  36), -INT8_C(  65),
       INT8_C( 115), -INT8_C( 110),  INT8_C(  53),  INT8_C(  76),  INT8_C(  45),  INT8_C(  34),  INT8_C( 108),  INT8_C(  73),
       INT8_C( 115),  INT8_C(   4),  INT8_C(  85),  INT8_C(  74),  INT8_C( 109), -INT8_C(  72),  INT8_C(  75), -INT8_C(  67),
       INT8_C(  45),  INT8_C(   9), -INT8_C( 125), -INT8_C(  35), -INT8_C( 113), -INT8_C(  32),  INT8_C(  94),  INT8_C(  49),
      -INT8_C(  83), -INT8_C(  87), -INT8_C(  81),  INT8_C(  51),  INT8_C(   3), -INT8_C(  45), -INT8_C(  13),  INT8_C( 118),
       INT8_C( 101),  INT8_C(  40), -INT8_C(  62) };
  static const int8_t e[] =
    {  INT8_C(   0),  INT8_C(   0),  INT8_C( 104), -INT8_C(  67),  INT8_C( 114),  INT8_C(   0),  INT8_C(  83), -INT8_C(  43),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  28),  INT8_C(   0),  INT8_C(   0), -INT8_C(   4),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(  94),  INT8_C(   0),  INT8_C(   0),  INT8_C(   9),
      -INT8_C(  81),  INT8_C( 116), -INT8_C(  24), -INT8_C(  99),  INT8_C(  41),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  94),  INT8_C(   0),  INT8_C(  90),  INT8_C(  20),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  18),
      -INT8_C( 111),  INT8_C(   0), -INT8_C(   9),  INT8_C(  81),  INT8_C(   0),  INT8_C(   0),  INT8_C( 124),  INT8_C( 102),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  42), -INT8_C( 124), -INT8_C(  40),  INT8_C(  83),  INT8_C(   0),  INT8_C(   1), -INT8_C(  17),  INT8_C(   0),
      -INT8_C( 110),  INT8_C(  74), -INT8_C(  29),  INT8_C(  30),  INT8_C(   0),  INT8_C(   0),  INT8_C(  49), -INT8_C( 121),
       INT8_C(   0),  INT8_C(  40),  INT8_C(   0),  INT8_C(   0), -INT8_C(  26),  INT8_C(  84), -INT8_C(  57),  INT8_C(  28),
       INT8_C( 114),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  74),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  20),  INT8_C(  96), -INT8_C(   6),  INT8_C(   0),  INT8_C(  79), -INT8_C(  54),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  84),  INT8_C(   0), -INT8_C( 113),  INT8_C( 121), -INT8_C(  11),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C( 114),  INT8_C(   4),  INT8_C(   0),  INT8_C(  56),  INT8_C(  31),  INT8_C(   0),
       INT8_C( 102),  INT8_C(   0),  INT8_C(   0),  INT8_C(  72),  INT8_C(  24),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   2), -INT8_C(  75), -INT8_C(  32),  INT8_C(   0),  INT8_C(   3), -INT8_C(  86),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  43),  INT8_C(   0),  INT8_C(   0),  INT8_C(  65),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  47),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 118),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  97),  INT8_C(   0),  INT8_C(   0), -INT8_C( 123),  INT8_C(   0),
       INT8_C(   0),  INT8_C( 101), -INT8_C(  30),  INT8_C(  69),  INT8_C(   0), -INT8_C(  97), -INT8_C(  31),  INT8_C( 100),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  51), -INT8_C( 102),  INT8_C(  77),  INT8_C(   0),  INT8_C(   0),  INT8_C( 124),
       INT8_C(  99),  INT8_C(   0), -INT8_C(  19),  INT8_C(   0), -INT8_C( 126),  INT8_C(   0), -INT8_C(  35),  INT8_C(   9),
       INT8_C(   0),  INT8_C(  21), -INT8_C(  88), -INT8_C(  76),  INT8_C(   0),  INT8_C(  44),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  98),  INT8_C(   0), -INT8_C(  97),  INT8_C(   1),  INT8_C(  10),  INT8_C(   0),  INT8_C(  35),
       INT8_C(  21),  INT8_C(   0),  INT8_C(   0),  INT8_C(  99),  INT8_C(  72), -INT8_C(  20), -INT8_C(  34),  INT8_C(   0),
      -INT8_C(  74), -INT8_C(  52),  INT8_C(   0),  INT8_C(  56), -INT8_C(  34),  INT8_C( 117),  INT8_C(  65),  INT8_C(   0),
      -INT8_C( 118),  INT8_C(   0),      INT8_MAX,  INT8_C(  45),  INT8_C(  21), -INT8_C(   2),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  96),  INT8_C(   0),  INT8_C(  69),  INT8_C(   0),  INT8_C(  66),  INT8_C(   0),  INT8_C(   0),  INT8_C(  87),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  70), -INT8_C(  59),  INT8_C(  45), -INT8_C( 103),  INT8_C(   0), -INT8_C(  29),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  26),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   2), -INT8_C(  24),
       INT8_C( 125),  INT8_C(   0),  INT8_C(  73), -INT8_C(  65),  INT8_C(   0), -INT8_C(  52),  INT8_C(  23),  INT8_C(   9),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  50),  INT8_C(   0),  INT8_C(   0),  INT8_C(  61),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  54),  INT8_C(  15), -INT8_C(  60), -INT8_C( 111),  INT8_C(  28), -INT8_C(  52),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  70),  INT8_C(  42),  INT8_C(  22),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  95), -INT8_C( 125), -INT8_C(   8),  INT8_C(  43),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C( 108),  INT8_C(   0),  INT8_C(   0), -INT8_C(  43),  INT8_C(   0), -INT8_C( 115),  INT8_C(   0),  INT8_C(  81),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  51),  INT8_C(   0),  INT8_C(   0),  INT8_C( 116),
       INT8_C(   0),  INT8_C(  82),  INT8_C(   0),  INT8_C(   0),  INT8_C( 124),  INT8_C(   0),  INT8_C(   0), -INT8_C(  24),
       INT8_C(  24),  INT8_C(   0), -INT8_C(  32),  INT8_C(  67),  INT8_C(  11),  INT8_C(   0),  INT8_C( 122),  INT8_C(   0),
      -INT8_C(  83),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   9),  INT8_C(   0),
      -INT8_C(  96),  INT8_C(  31), -INT8_C( 113),  INT8_C( 110),  INT8_C(   0), -INT8_C(  75), -INT8_C(  30), -INT8_C(  29),
       INT8_C(   8), -INT8_C( 124),  INT8_C(  12),  INT8_C(   0),  INT8_C(  60),  INT8_C(   0),  INT8_C(   0),  INT8_C(  83),
       INT8_C(   0),  INT8_C(   0), -INT8_C( 106),  INT8_C( 118),  INT8_C(  45),  INT8_C(  16),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   5),  INT8_C(  58),  INT8_C(   0),  INT8_C( 115),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  14),  INT8_C(  24),  INT8_C(   0), -INT8_C(   6),
      -INT8_C( 101), -INT8_C(  86),  INT8_C( 126), -INT8_C(  40), -INT8_C(  92),  INT8_C(   0),  INT8_C(  43),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C( 122),  INT8_C( 100), -INT8_C(  47),  INT8_C( 115),  INT8_C(   0), -INT8_C(  52),
      -INT8_C(  83), -INT8_C(  48),  INT8_C(  63), -INT8_C(  43),  INT8_C( 108), -INT8_C(  19),  INT8_C(   0),  INT8_C(  39),
       INT8_C(  41), -INT8_C(  44), -INT8_C(  31),  INT8_C(  27),  INT8_C(   0),      INT8_MAX,  INT8_C(  21),  INT8_C(   0),
       INT8_C(  40),  INT8_C(   0),  INT8_C(   0), -INT8_C(  51),  INT8_C( 126), -INT8_C( 119), -INT8_C(  37),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  97),  INT8_C(  24),  INT8_C(  28), -INT8_C(  44),  INT8_C(   0), -INT8_C(  24),  INT8_C(   0),
       INT8_C(  38),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  71),  INT8_C(  61),
      -INT8_C(  58), -INT8_C( 102),  INT8_C(  88),  INT8_C(   0),  INT8_C(  24),  INT8_C(   0),  INT8_C(  56),  INT8_C(  64),
       INT8_C(   2), -INT8_C( 106),  INT8_C(   0),      INT8_MAX,  INT8_C(  32),  INT8_C(   0),  INT8_C(  53),  INT8_C( 106),
       INT8_C(  73),  INT8_C(   0), -INT8_C( 122),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 108),  INT8_C(   0),  INT8_C(   0), -INT8_C(  89), -INT8_C(  27),  INT8_C(   0), -INT8_C(  28),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  91),  INT8_C(   0), -INT8_C(  85),  INT8_C(   0),  INT8_C(   6), -INT8_C(  83),
       INT8_C(   0),  INT8_C(  18),  INT8_C(   0),  INT8_C(  74), -INT8_C(   5),  INT8_C(  96), -INT8_C(  75),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  58),  INT8_C(  98),  INT8_C(  80), -INT8_C(  88),  INT8_C(   0),  INT8_C(  26),  INT8_C(  60),
      -INT8_C(  13),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  56), -INT8_C( 126),  INT8_C(  53),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   6),  INT8_C(   0),  INT8_C( 114),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 102),  INT8_C(  82), -INT8_C( 105),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  25),  INT8_C(   0), -INT8_C(  77),  INT8_C(   0),  INT8_C(   0), -INT8_C(  89),
       INT8_C( 117),  INT8_C(   0),  INT8_C( 126),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(  50),  INT8_C( 105),
       INT8_C(   0),  INT8_C(  44),  INT8_C(   0),  INT8_C(  81),  INT8_C(  43),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   2), -INT8_C(  47),  INT8_C(   0), -INT8_C(  25),  INT8_C(   0), -INT8_C( 100),  INT8_C( 125),  INT8_C(  64),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C( 101),  INT8_C(   0), -INT8_C(  87),  INT8_C(   0),
       INT8_C(  17),  INT8_C(   0), -INT8_C(  41),  INT8_C(   0),  INT8_C(  41),  INT8_C(   0), -INT8_C(  34),  INT8_C(   8),
       INT8_C(  53),  INT8_C(   0),  INT8_C(  89),  INT8_C(  97),  INT8_C(   0),  INT8_C(   0), -INT8_C(  98),  INT8_C( 106),
       INT8_C(  22),  INT8_C(   0),  INT8_C(  82),  INT8_C(   0),  INT8_C(   0), -INT8_C(  49),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  51),  INT8_C( 126),  INT8_C(   0),  INT8_C(   0), -INT8_C(  13), -INT8_C( 127),  INT8_C( 114),  INT8_C(   4),
       INT8_C(   0),  INT8_C(   0),  INT8_C( 121),  INT8_C(   0),  INT8_C(  83),  INT8_C(  87),  INT8_C(   0), -INT8_C( 121),
       INT8_C(  78),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  13),  INT8_C(  70),  INT8_C(   0), -INT8_C(  57),  INT8_C(   0),
       INT8_C(  77),  INT8_C(   0),  INT8_C(  17),  INT8_C(  64),  INT8_C(  31),  INT8_C(   0),  INT8_C(  68),  INT8_C(   0),
      -INT8_C(  50), -INT8_C(  67),  INT8_C(   0),  INT8_C(  32),  INT8_C(   0),  INT8_C( 114),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  92), -INT8_C( 112),  INT8_C(  29),  INT8_C(   0),  INT8_C(  21),  INT8_C(  66),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  72), -INT8_C(  75),  INT8_C( 119),  INT8_C(   0), -INT8_C( 124),  INT8_C(  62),  INT8_C( 119), -INT8_C(  46),
      -INT8_C(  36),  INT8_C(   0),  INT8_C(  18), -INT8_C(   5),  INT8_C(  12),  INT8_C(   0), -INT8_C(  62), -INT8_C(  38),
       INT8_C(  20),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 117),  INT8_C( 112),
       INT8_C(  49),  INT8_C(   0), -INT8_C( 118),  INT8_C(  70), -INT8_C(  21),  INT8_C(   0), -INT8_C(  54), -INT8_C(  93),
      -INT8_C(  26),  INT8_C(  66),  INT8_C(   0),  INT8_C( 107),  INT8_C(   0),  INT8_C(  24),  INT8_C(   0),  INT8_C(  92),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  86), -INT8_C(  83), -INT8_C(  90),  INT8_C(  24),  INT8_C(   0), -INT8_C(  69),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  28),  INT8_C(   0),  INT8_C(  35),  INT8_C( 111), -INT8_C(  82),  INT8_C(   0),
       INT8_C(  24),  INT8_C(  56), -INT8_C( 102),  INT8_C(   2),  INT8_C( 106),  INT8_C( 101),  INT8_C(   0),  INT8_C(  80),
       INT8_C(   0),  INT8_C(  71),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(  72), -INT8_C(  41),  INT8_C(   0) };

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
    rv = simde_svsub_s8_z(pv, av, bv);

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

    ev = simde_svsub_s8_z(pv, av, bv);

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
test_simde_svsub_s8_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0) };
  static const int8_t a[] =
    { -INT8_C(  50),  INT8_C(  80), -INT8_C(  76), -INT8_C(   6),  INT8_C(  89), -INT8_C( 115),  INT8_C( 125), -INT8_C(  47),
      -INT8_C(   6), -INT8_C(  50),  INT8_C(  98), -INT8_C(  18),  INT8_C(   7),  INT8_C( 100), -INT8_C(  11), -INT8_C(   7),
      -INT8_C(  88), -INT8_C(  61),  INT8_C(  95),  INT8_C(  68),  INT8_C(  54), -INT8_C(  13), -INT8_C( 126), -INT8_C(  96),
       INT8_C( 108),  INT8_C(  48), -INT8_C(   8),  INT8_C(  39),  INT8_C( 105), -INT8_C(  28), -INT8_C(  47),  INT8_C(  55),
       INT8_C(  52), -INT8_C( 123),  INT8_C(  49), -INT8_C( 114),  INT8_C(  19), -INT8_C(  82),  INT8_C(  95),  INT8_C(  13),
       INT8_C( 124), -INT8_C(  62), -INT8_C(   4), -INT8_C( 125),  INT8_C(  38), -INT8_C(  15),  INT8_C( 125), -INT8_C(  50),
      -INT8_C(  75), -INT8_C(  36),  INT8_C(  18), -INT8_C(  21), -INT8_C(  48), -INT8_C( 108), -INT8_C( 117),  INT8_C(  60),
      -INT8_C(  59), -INT8_C( 125),  INT8_C( 100),  INT8_C(  46),  INT8_C( 103),  INT8_C(  53),  INT8_C( 101), -INT8_C( 100),
      -INT8_C(  70), -INT8_C( 106),  INT8_C(  42), -INT8_C(  51),  INT8_C(  68), -INT8_C( 119), -INT8_C(  37), -INT8_C(  64),
       INT8_C(  75), -INT8_C(  41),  INT8_C(  67),  INT8_C( 114), -INT8_C(  56), -INT8_C(  64),  INT8_C(  64),  INT8_C( 125),
      -INT8_C(  99),  INT8_C(  83),  INT8_C( 104),  INT8_C( 109), -INT8_C(  25), -INT8_C(  13), -INT8_C(  87), -INT8_C(  84),
       INT8_C( 118),  INT8_C(  13), -INT8_C(  38), -INT8_C(  34),  INT8_C(  66),  INT8_C(  63),  INT8_C( 122), -INT8_C(   3),
      -INT8_C(  43), -INT8_C(  92), -INT8_C(  54),  INT8_C(  25),  INT8_C(  45), -INT8_C(  91), -INT8_C(  39),  INT8_C( 121),
       INT8_C( 124),  INT8_C(  29), -INT8_C(  21),  INT8_C(  69), -INT8_C(  35),  INT8_C(  43), -INT8_C(  62),  INT8_C( 122),
       INT8_C( 126),  INT8_C(  43), -INT8_C(  25),  INT8_C( 102),  INT8_C(  30), -INT8_C( 111),  INT8_C(  18), -INT8_C( 107),
      -INT8_C(  98), -INT8_C(  19),  INT8_C( 115), -INT8_C(  31),  INT8_C(  44), -INT8_C(  19), -INT8_C(  34),  INT8_C(   2),
      -INT8_C( 111), -INT8_C(  88),  INT8_C(  27), -INT8_C(  66),  INT8_C(  78), -INT8_C(  11),  INT8_C(  55), -INT8_C(  54),
       INT8_C(  18),  INT8_C(  34),  INT8_C(  15), -INT8_C(  17),  INT8_C(  78), -INT8_C(  46),  INT8_C( 106), -INT8_C(  52),
      -INT8_C(   3),  INT8_C(  81),  INT8_C(  50),  INT8_C(  27), -INT8_C(  30),  INT8_C(  69), -INT8_C(  80), -INT8_C( 127),
       INT8_C(  50),  INT8_C(  35),  INT8_C(  98),  INT8_C(  94),  INT8_C(  16),  INT8_C(  64),  INT8_C(  96), -INT8_C(  95),
      -INT8_C(  24),  INT8_C( 124),  INT8_C(  96),  INT8_C(  54),  INT8_C( 113), -INT8_C( 105),  INT8_C(   1), -INT8_C( 125),
      -INT8_C(  70),  INT8_C(  16),  INT8_C( 114),  INT8_C(   8), -INT8_C(  30), -INT8_C(  36), -INT8_C(  44), -INT8_C(  33),
       INT8_C(  46),  INT8_C(   7), -INT8_C(   5),  INT8_C(  16),  INT8_C(  76), -INT8_C(  85), -INT8_C( 111),  INT8_C( 126),
      -INT8_C(  49), -INT8_C(  13), -INT8_C(  36), -INT8_C(  33),  INT8_C(  51),  INT8_C(  61), -INT8_C( 127),  INT8_C(  28),
      -INT8_C(  71), -INT8_C(  31),  INT8_C(  82),  INT8_C(  42),  INT8_C( 120),  INT8_C(  83), -INT8_C(  83),  INT8_C(  50),
       INT8_C( 100),  INT8_C(  31),  INT8_C(  58),  INT8_C(  70), -INT8_C(   4),  INT8_C(  15),  INT8_C(  38),  INT8_C(  42),
       INT8_C(  22),  INT8_C(  33),  INT8_C(  58),  INT8_C(  98), -INT8_C(  52), -INT8_C(  52), -INT8_C(  32), -INT8_C( 101),
      -INT8_C(  65), -INT8_C(  68),  INT8_C( 123), -INT8_C(  13), -INT8_C(   7), -INT8_C(   4),  INT8_C(  15), -INT8_C(  78),
      -INT8_C(  35),  INT8_C(  97), -INT8_C(  36),  INT8_C(  85), -INT8_C(  75), -INT8_C( 119), -INT8_C( 120),  INT8_C(  25),
      -INT8_C(  87), -INT8_C(  62),  INT8_C(  95), -INT8_C(  91), -INT8_C(  47), -INT8_C( 123), -INT8_C(  49), -INT8_C(  25),
      -INT8_C(  90),  INT8_C(   9),  INT8_C(  73),  INT8_C( 115), -INT8_C(  43),  INT8_C(  41),  INT8_C(  14), -INT8_C( 107),
      -INT8_C(  26), -INT8_C( 119), -INT8_C( 120), -INT8_C(  33), -INT8_C( 123), -INT8_C( 105), -INT8_C( 110),  INT8_C(  98),
      -INT8_C(   8),  INT8_C( 110), -INT8_C(  72), -INT8_C(  83), -INT8_C(   8),  INT8_C(  64), -INT8_C(  58), -INT8_C(  95),
       INT8_C(   2),  INT8_C(  38),  INT8_C(  70), -INT8_C(  44), -INT8_C(  85),  INT8_C(  21), -INT8_C(  69),  INT8_C(  82),
       INT8_C(  30),  INT8_C(   5), -INT8_C(  59), -INT8_C(  12),  INT8_C(  46), -INT8_C(  45), -INT8_C( 119),  INT8_C(  20),
       INT8_C(  93),  INT8_C(  17), -INT8_C(  12), -INT8_C(  30), -INT8_C(  88), -INT8_C( 122),  INT8_C(  69), -INT8_C(  96),
      -INT8_C(  12), -INT8_C(   3),  INT8_C(  78), -INT8_C(  20),  INT8_C(  61),  INT8_C(  20), -INT8_C( 115),  INT8_C(  63),
       INT8_C(  58), -INT8_C(  45),  INT8_C(  19), -INT8_C(  26), -INT8_C(  24), -INT8_C(  49),  INT8_C(  56),  INT8_C(   7),
      -INT8_C(  44), -INT8_C(   3), -INT8_C(   5),  INT8_C(   2), -INT8_C(  48), -INT8_C( 124),  INT8_C(  23),  INT8_C(  45),
      -INT8_C( 107),  INT8_C(  11),  INT8_C(  16),  INT8_C(  61), -INT8_C( 111),  INT8_C(  85), -INT8_C(  35), -INT8_C( 123),
       INT8_C(  82),  INT8_C(  43),  INT8_C( 114), -INT8_C( 113),  INT8_C(  64), -INT8_C(   1), -INT8_C(  50),  INT8_C( 122),
      -INT8_C(  45), -INT8_C(  30),  INT8_C(  96), -INT8_C(  69), -INT8_C(  79), -INT8_C( 104), -INT8_C(  62), -INT8_C( 123),
      -INT8_C( 107), -INT8_C(  67), -INT8_C( 121),  INT8_C( 102),  INT8_C(  65), -INT8_C(  98), -INT8_C( 109), -INT8_C(  42),
      -INT8_C(  87), -INT8_C(  93),  INT8_C(  19),  INT8_C(  58), -INT8_C(   8), -INT8_C(  15), -INT8_C(  64),  INT8_C(  74),
       INT8_C(  28),  INT8_C(  50), -INT8_C(  39),  INT8_C(  92),  INT8_C(  49), -INT8_C(  88), -INT8_C(  41),  INT8_C(   4),
      -INT8_C( 118),  INT8_C(  55), -INT8_C(  64),  INT8_C(  59), -INT8_C(  48), -INT8_C( 126), -INT8_C(  64),  INT8_C( 101),
       INT8_C(  64),  INT8_C(  71), -INT8_C(  53), -INT8_C( 127), -INT8_C(  26),  INT8_C(  95),  INT8_C(  88), -INT8_C( 113),
       INT8_C(   2),  INT8_C( 107), -INT8_C(  54), -INT8_C(   5),  INT8_C(  92), -INT8_C( 118),  INT8_C(  69),  INT8_C( 121),
      -INT8_C(  68),  INT8_C(  31), -INT8_C(  43), -INT8_C(  19), -INT8_C(  57), -INT8_C(  84), -INT8_C(  14),  INT8_C(  81),
      -INT8_C(  28), -INT8_C(  78), -INT8_C( 116), -INT8_C(  76),  INT8_C(  52),  INT8_C(  76),  INT8_C(  25),  INT8_C( 116),
      -INT8_C( 109), -INT8_C(  27), -INT8_C(  10),  INT8_C( 121),  INT8_C(  68),  INT8_C(  78),  INT8_C(   9),  INT8_C(  70),
      -INT8_C(  71), -INT8_C(  45),  INT8_C(  65),  INT8_C(  22),  INT8_C(  93), -INT8_C( 121), -INT8_C( 113),  INT8_C(  25),
      -INT8_C(  90),  INT8_C( 100),  INT8_C(   6),  INT8_C( 109),  INT8_C(  17), -INT8_C(   8), -INT8_C(  66), -INT8_C(  11),
      -INT8_C(  86),  INT8_C(  74), -INT8_C(  87), -INT8_C(  33), -INT8_C( 106), -INT8_C(  62),  INT8_C(  83),  INT8_C(  41),
      -INT8_C(  89),  INT8_C(  73), -INT8_C(  93), -INT8_C(  21), -INT8_C( 105), -INT8_C(  84),  INT8_C(  50),  INT8_C(  81),
           INT8_MAX,  INT8_C( 115),  INT8_C( 103), -INT8_C(  36), -INT8_C(   6), -INT8_C(  10), -INT8_C(  11), -INT8_C(  96),
       INT8_C(  90), -INT8_C(   5),  INT8_C(  13),  INT8_C( 107), -INT8_C(  12), -INT8_C(  53),  INT8_C(  96), -INT8_C(  98),
       INT8_C(  21),  INT8_C(   9),  INT8_C( 125), -INT8_C(  85), -INT8_C(  52), -INT8_C(  47), -INT8_C(  43),  INT8_C( 115),
       INT8_C(  26),  INT8_C( 120),  INT8_C(  95), -INT8_C(  78),  INT8_C(  36), -INT8_C( 111),  INT8_C(   3), -INT8_C(  93),
       INT8_C(   4),  INT8_C( 106),      INT8_MAX, -INT8_C(   1),  INT8_C(  96),  INT8_C( 116), -INT8_C(  97), -INT8_C(  70),
       INT8_C( 111), -INT8_C(  83),  INT8_C(  38),  INT8_C(  99),  INT8_C( 120), -INT8_C( 122),  INT8_C(   2), -INT8_C( 114),
      -INT8_C( 112),      INT8_MAX,  INT8_C(  57),  INT8_C(  92),  INT8_C(  80),  INT8_C(  14), -INT8_C(  49),  INT8_C( 107),
      -INT8_C( 122),  INT8_C(  46),  INT8_C(  29), -INT8_C(  86), -INT8_C(  65),  INT8_C(  32),  INT8_C(  77), -INT8_C(  60),
      -INT8_C( 118), -INT8_C(  52), -INT8_C(  61), -INT8_C(  22),  INT8_C(  64),  INT8_C(  98), -INT8_C(  92), -INT8_C(  80),
       INT8_C(  15), -INT8_C(  54),  INT8_C(  19), -INT8_C( 120),  INT8_C(  81),  INT8_C(  21),  INT8_C(  22), -INT8_C(  31),
      -INT8_C( 107),  INT8_C(  79),  INT8_C(  61), -INT8_C(  27),  INT8_C(  94),  INT8_C(  12),  INT8_C(  80), -INT8_C(  28),
       INT8_C(  59),  INT8_C( 109), -INT8_C( 113), -INT8_C(   6), -INT8_C( 115), -INT8_C(  36), -INT8_C(  66),  INT8_C(  23),
      -INT8_C(  87), -INT8_C( 127),  INT8_C(   1), -INT8_C(  23), -INT8_C(  28), -INT8_C(  90), -INT8_C( 103), -INT8_C(  13),
       INT8_C( 112), -INT8_C(  83),  INT8_C( 123), -INT8_C(  63), -INT8_C(  62), -INT8_C( 111), -INT8_C(  94),  INT8_C(  87),
      -INT8_C(  31), -INT8_C(  33),  INT8_C(  61),  INT8_C(  63), -INT8_C(  20), -INT8_C( 115),  INT8_C(  35),  INT8_C(  39),
      -INT8_C(   5), -INT8_C(  78),  INT8_C(  33), -INT8_C( 120), -INT8_C( 113), -INT8_C(  32), -INT8_C(  96),  INT8_C(  56),
       INT8_C(  97), -INT8_C(  95),  INT8_C(  33),  INT8_C(  69),  INT8_C(  71), -INT8_C(  69),  INT8_C(  57), -INT8_C(  72),
       INT8_C( 104), -INT8_C(  76),  INT8_C( 121),  INT8_C(  42),  INT8_C(  70),  INT8_C(  28), -INT8_C( 126),  INT8_C(  39),
      -INT8_C(   5), -INT8_C(  65),  INT8_C( 102), -INT8_C(  25),  INT8_C(  76), -INT8_C( 119),  INT8_C(  14),  INT8_C(  71),
       INT8_C(  60),  INT8_C(  48), -INT8_C(  48), -INT8_C(  53),  INT8_C(  16),  INT8_C( 112),  INT8_C(   3),  INT8_C( 113),
       INT8_C(  17),  INT8_C(  36), -INT8_C(  73),  INT8_C(  89), -INT8_C(  33), -INT8_C(  16),  INT8_C(  17),  INT8_C(  71),
      -INT8_C(  92), -INT8_C( 118),  INT8_C( 114), -INT8_C(  22), -INT8_C(  90), -INT8_C(  12),  INT8_C(  17), -INT8_C(  94),
      -INT8_C(  77),  INT8_C( 119), -INT8_C( 119), -INT8_C(   1),  INT8_C(   1), -INT8_C( 104),  INT8_C(  71),  INT8_C(  61),
      -INT8_C(  56),  INT8_C(  23),  INT8_C(   8), -INT8_C(  40), -INT8_C( 121),  INT8_C(  11),  INT8_C(  73), -INT8_C( 104),
       INT8_C(  47),  INT8_C(   0), -INT8_C(  15),  INT8_C(  15), -INT8_C(  16),  INT8_C(   2),  INT8_C(  86), -INT8_C( 107),
      -INT8_C( 115), -INT8_C(  56),      INT8_MAX,  INT8_C(  51), -INT8_C(  68), -INT8_C( 111), -INT8_C(  43),  INT8_C( 111),
       INT8_C(   8),  INT8_C(  95),  INT8_C( 111),  INT8_C(   9), -INT8_C(   9), -INT8_C(  74),  INT8_C(  70), -INT8_C(  65),
      -INT8_C(  51),  INT8_C(  78), -INT8_C( 105),  INT8_C(  84),  INT8_C(  89), -INT8_C(  32), -INT8_C(  20), -INT8_C( 119),
      -INT8_C(  31), -INT8_C(  34), -INT8_C( 104), -INT8_C(  47), -INT8_C(  32), -INT8_C(  18),  INT8_C( 102),  INT8_C( 109),
      -INT8_C(  73), -INT8_C(  26), -INT8_C(  95),  INT8_C( 115),  INT8_C( 119),  INT8_C( 118), -INT8_C(  29),      INT8_MAX,
      -INT8_C(  43),  INT8_C(  82), -INT8_C( 119), -INT8_C(  52),  INT8_C(   8), -INT8_C(  49), -INT8_C( 117), -INT8_C(  43),
       INT8_C(  30),  INT8_C(  34),  INT8_C(  41),  INT8_C( 119),  INT8_C(   3),  INT8_C(  21),  INT8_C(   0), -INT8_C(  28),
      -INT8_C(  13), -INT8_C( 104), -INT8_C(  75), -INT8_C(  44), -INT8_C( 121),  INT8_C(  28),  INT8_C(  65),  INT8_C(  62),
       INT8_C(   2), -INT8_C(  30), -INT8_C(  79),  INT8_C( 121),  INT8_C(  89), -INT8_C( 108), -INT8_C(   8),  INT8_C(  46),
      -INT8_C(  26), -INT8_C( 127), -INT8_C(   5), -INT8_C(  18),  INT8_C(  81), -INT8_C( 122), -INT8_C(  61),  INT8_C( 111),
      -INT8_C(  87), -INT8_C(  20), -INT8_C(  26), -INT8_C(  84),  INT8_C(   2), -INT8_C(  25), -INT8_C( 112), -INT8_C(  11),
           INT8_MAX,  INT8_C(  69), -INT8_C(  55),  INT8_C(   6),  INT8_C(  97),  INT8_C(  11),  INT8_C(  68),  INT8_C(  99),
      -INT8_C(  19), -INT8_C(  10), -INT8_C(  36),  INT8_C(  70), -INT8_C( 118), -INT8_C(  43),  INT8_C( 117),  INT8_C( 113),
       INT8_C(  86),  INT8_C( 112),  INT8_C(  95), -INT8_C(  89), -INT8_C(  10),  INT8_C(  35),  INT8_C(  22), -INT8_C(  97),
       INT8_C(  15), -INT8_C(   3),  INT8_C(  75),  INT8_C(  17), -INT8_C(  28), -INT8_C(  37),  INT8_C(   7),  INT8_C(  99),
       INT8_C(  33), -INT8_C(  48),  INT8_C( 106), -INT8_C( 126), -INT8_C(  37), -INT8_C(  82), -INT8_C(  26), -INT8_C(  55),
      -INT8_C(  92), -INT8_C(  62),  INT8_C(  15),  INT8_C(  47), -INT8_C( 105), -INT8_C( 124), -INT8_C(  96), -INT8_C(  18),
      -INT8_C(  12), -INT8_C(   1), -INT8_C( 107), -INT8_C(  21),  INT8_C(  34), -INT8_C(  84), -INT8_C( 118),  INT8_C(  50),
      -INT8_C(  87), -INT8_C(  42),  INT8_C(  67), -INT8_C( 115), -INT8_C(  79),  INT8_C(  74), -INT8_C(  16), -INT8_C(  46),
       INT8_C(  27),  INT8_C(  90),  INT8_C(  85), -INT8_C(  10),  INT8_C(   9),  INT8_C(  59), -INT8_C(  65), -INT8_C(  83),
      -INT8_C(   3), -INT8_C(  49), -INT8_C(  36), -INT8_C( 107),  INT8_C(  83),  INT8_C( 124), -INT8_C( 125),  INT8_C(  72),
       INT8_C( 124),  INT8_C(  24),  INT8_C(  51), -INT8_C(  98), -INT8_C(  60), -INT8_C(  67), -INT8_C(  48),  INT8_C( 109),
      -INT8_C( 109),  INT8_C(  20), -INT8_C(   6),  INT8_C(  69),  INT8_C(  94), -INT8_C(  21),  INT8_C(  23),  INT8_C( 121),
       INT8_C(  69),  INT8_C( 108),  INT8_C( 112),  INT8_C(  78), -INT8_C(  89),  INT8_C(  47), -INT8_C(   4), -INT8_C(  91),
      -INT8_C(   2), -INT8_C(  40),  INT8_C(  58),  INT8_C(  82),  INT8_C(  85), -INT8_C(  67), -INT8_C( 102), -INT8_C(  47),
      -INT8_C(  43), -INT8_C(  51),  INT8_C( 111), -INT8_C( 102), -INT8_C( 118),  INT8_C(  64),  INT8_C(   7),  INT8_C(  30),
       INT8_C(  84),  INT8_C(   2),  INT8_C(  99), -INT8_C(  78), -INT8_C(  19),  INT8_C( 122),  INT8_C(  44),  INT8_C(  50),
      -INT8_C(  25), -INT8_C( 100), -INT8_C( 127), -INT8_C( 114), -INT8_C(  53),  INT8_C( 125),  INT8_C(  51), -INT8_C(  54),
       INT8_C(  85),  INT8_C( 109),  INT8_C(  28), -INT8_C(  86),  INT8_C(  42), -INT8_C(  74),  INT8_C( 123),  INT8_C(   0),
      -INT8_C( 125), -INT8_C(  21), -INT8_C( 102),  INT8_C(  13),  INT8_C(  43), -INT8_C(  95),  INT8_C(  43),      INT8_MAX,
      -INT8_C(  93), -INT8_C( 114),  INT8_C(  49), -INT8_C( 112),  INT8_C(   9),  INT8_C(  93), -INT8_C(  61), -INT8_C(  16),
      -INT8_C(   7),  INT8_C(  68),  INT8_C( 126), -INT8_C(  59), -INT8_C(  63), -INT8_C(  78), -INT8_C( 113),  INT8_C(  22),
       INT8_C(  31), -INT8_C(  85), -INT8_C(  63),  INT8_C(  74),  INT8_C(  97),  INT8_C(  60),  INT8_C(  74), -INT8_C(  28),
       INT8_C(  39), -INT8_C(  28), -INT8_C(  15),  INT8_C(  82), -INT8_C( 123),  INT8_C(  29), -INT8_C(  47),  INT8_C(  41),
      -INT8_C(  85),  INT8_C(   3), -INT8_C(  71), -INT8_C(  76),  INT8_C(  96),  INT8_C( 124), -INT8_C(  92),  INT8_C(  90),
      -INT8_C(  64),  INT8_C(  35),  INT8_C(  31), -INT8_C( 127), -INT8_C(  43), -INT8_C(  82), -INT8_C( 104), -INT8_C(  12),
       INT8_C(  89),  INT8_C(  89),  INT8_C(  62), -INT8_C(  70), -INT8_C( 107), -INT8_C( 120), -INT8_C(  98), -INT8_C(  67),
       INT8_C( 108), -INT8_C( 113),  INT8_C(  15), -INT8_C(  14), -INT8_C(  84), -INT8_C(  31),  INT8_C(  27),  INT8_C(  88),
      -INT8_C(  28), -INT8_C(  44),  INT8_C(  12),  INT8_C(  68),  INT8_C(  81), -INT8_C(  79), -INT8_C(  98),  INT8_C(  17),
      -INT8_C(  44), -INT8_C(  67), -INT8_C( 109), -INT8_C(  87),  INT8_C( 107),  INT8_C(  43), -INT8_C(  99), -INT8_C(  60),
      -INT8_C( 124), -INT8_C(  36),  INT8_C( 126),  INT8_C(  25),  INT8_C( 100),  INT8_C(  28), -INT8_C(  42), -INT8_C(  47),
      -INT8_C(  84), -INT8_C(  26), -INT8_C(  61),  INT8_C(  88), -INT8_C(  57), -INT8_C(  34), -INT8_C(  80), -INT8_C(  85),
      -INT8_C(  78), -INT8_C(  67), -INT8_C(  17),  INT8_C(   3),  INT8_C( 110), -INT8_C( 114),  INT8_C(  21),  INT8_C(  66),
       INT8_C(  75), -INT8_C(  88), -INT8_C(  21), -INT8_C(  73), -INT8_C(  45), -INT8_C( 120),  INT8_C( 123),  INT8_C(  87),
       INT8_C( 100), -INT8_C(   6),  INT8_C( 112), -INT8_C(  55) };
  static const int8_t b[] =
    { -INT8_C( 108),  INT8_C(  72), -INT8_C(  39), -INT8_C(  85), -INT8_C( 113),  INT8_C( 115),  INT8_C( 109), -INT8_C(  68),
      -INT8_C(  48), -INT8_C( 120), -INT8_C(  80),  INT8_C(  11),  INT8_C(  84),  INT8_C(  79), -INT8_C(   7), -INT8_C(  36),
      -INT8_C(  34), -INT8_C(  22), -INT8_C(  45), -INT8_C(   6), -INT8_C(  16),  INT8_C(  11),  INT8_C(  98), -INT8_C(  98),
       INT8_C(  47), -INT8_C( 127),  INT8_C(  31), -INT8_C(  37),  INT8_C(  28), -INT8_C(   9), -INT8_C(  21), -INT8_C(  80),
       INT8_C(  63), -INT8_C(  59),  INT8_C(  91), -INT8_C(  49),  INT8_C(  56), -INT8_C(  55), -INT8_C( 117),  INT8_C(   9),
       INT8_C(  81),  INT8_C(  60),  INT8_C(  20), -INT8_C(  91), -INT8_C( 117),  INT8_C(  13), -INT8_C( 126),  INT8_C( 105),
      -INT8_C(   9),  INT8_C(  85),  INT8_C( 100), -INT8_C(  25),  INT8_C(  96), -INT8_C(  58), -INT8_C( 123), -INT8_C( 113),
       INT8_C(  72), -INT8_C(  92),  INT8_C( 106),  INT8_C( 100), -INT8_C( 101),  INT8_C(  86),  INT8_C(  20), -INT8_C(  37),
       INT8_C(  27),  INT8_C( 112), -INT8_C(  86),  INT8_C(  83),  INT8_C(  57),  INT8_C(  53),  INT8_C(  92), -INT8_C( 118),
       INT8_C( 113),  INT8_C( 113),  INT8_C(  48), -INT8_C(   3),  INT8_C( 126), -INT8_C(  78),  INT8_C( 102),  INT8_C( 118),
       INT8_C(   7), -INT8_C(  54),  INT8_C(  93),  INT8_C( 103), -INT8_C( 111), -INT8_C(  29), -INT8_C(   9), -INT8_C(  39),
      -INT8_C( 121),  INT8_C(  97),  INT8_C(  61),  INT8_C(  35), -INT8_C(  73),  INT8_C(  81), -INT8_C(   2), -INT8_C(  46),
      -INT8_C(  63), -INT8_C(  88),  INT8_C(  38), -INT8_C(   6), -INT8_C(  35), -INT8_C( 126), -INT8_C( 123),  INT8_C(  79),
      -INT8_C(  13), -INT8_C(  75),  INT8_C(  76),  INT8_C( 114),  INT8_C( 103), -INT8_C(  78), -INT8_C(  24),  INT8_C( 110),
       INT8_C( 125),  INT8_C(  69), -INT8_C(  43),  INT8_C(  14),  INT8_C(  40), -INT8_C(  52), -INT8_C(  25), -INT8_C(  80),
       INT8_C(  46),  INT8_C(  36), -INT8_C(  45), -INT8_C(  27),  INT8_C( 117), -INT8_C(  47), -INT8_C(  72),  INT8_C(  55),
       INT8_C( 121), -INT8_C(  34),  INT8_C(  49),  INT8_C(  86),  INT8_C(  96), -INT8_C(  74), -INT8_C(  91),  INT8_C(  84),
       INT8_C( 107), -INT8_C(  15), -INT8_C(  58), -INT8_C(  46), -INT8_C(  92), -INT8_C(  82),  INT8_C(  64),  INT8_C(  33),
      -INT8_C(  13),  INT8_C(  22),  INT8_C(  47),  INT8_C(  28), -INT8_C(  30),  INT8_C(  22), -INT8_C(  52),  INT8_C(  16),
       INT8_C(  58), -INT8_C(  97), -INT8_C(  10), -INT8_C(  81),  INT8_C( 112), -INT8_C(  82), -INT8_C(  26), -INT8_C(  23),
      -INT8_C( 116),  INT8_C(  24),  INT8_C(  63), -INT8_C(  20), -INT8_C(  50), -INT8_C(  27),  INT8_C(  64),  INT8_C(  58),
      -INT8_C(  42),  INT8_C(   6),  INT8_C(  12),  INT8_C( 122), -INT8_C(  76),  INT8_C(  77), -INT8_C( 101), -INT8_C(  88),
       INT8_C(  99), -INT8_C(  54), -INT8_C(  60),  INT8_C(  69), -INT8_C(  32), -INT8_C( 112),  INT8_C(  86),  INT8_C(  26),
       INT8_C(  47),  INT8_C(  76), -INT8_C(  54), -INT8_C(  97), -INT8_C(   6), -INT8_C(  80), -INT8_C( 120), -INT8_C( 122),
      -INT8_C(  56), -INT8_C(  57),  INT8_C( 114), -INT8_C( 105), -INT8_C(  84), -INT8_C(  77), -INT8_C(  47), -INT8_C( 125),
      -INT8_C(  71), -INT8_C(  35), -INT8_C(   3),  INT8_C( 110),  INT8_C(  42), -INT8_C( 103),  INT8_C(  22), -INT8_C( 115),
       INT8_C(  99), -INT8_C(  38), -INT8_C(  45),  INT8_C(  68),  INT8_C( 106),  INT8_C(  41),  INT8_C(  94), -INT8_C( 103),
       INT8_C( 117),  INT8_C(  40),  INT8_C(  56),  INT8_C( 111), -INT8_C(  39), -INT8_C(  64), -INT8_C(  11), -INT8_C(  95),
      -INT8_C( 121),  INT8_C( 103),  INT8_C(  56),  INT8_C(  52),  INT8_C(  26),  INT8_C(   9), -INT8_C(  73), -INT8_C(  44),
      -INT8_C(  25), -INT8_C(  76),  INT8_C(  66),  INT8_C(  17),  INT8_C(  77),  INT8_C(  88), -INT8_C(  97), -INT8_C(  79),
       INT8_C(  50),  INT8_C( 114), -INT8_C(  11), -INT8_C( 100), -INT8_C( 101),  INT8_C(  83),  INT8_C(  53),  INT8_C(  16),
       INT8_C( 124),  INT8_C( 109),      INT8_MAX,  INT8_C(  85),  INT8_C(  45),  INT8_C( 116), -INT8_C(  10), -INT8_C(  76),
      -INT8_C(  37),  INT8_C(  47), -INT8_C(  24), -INT8_C(  10),  INT8_C(  56), -INT8_C(  97), -INT8_C(  54),  INT8_C(  31),
       INT8_C(  84),  INT8_C(  12),  INT8_C(  49), -INT8_C(  95),  INT8_C( 100), -INT8_C(  48),  INT8_C(  82), -INT8_C( 106),
       INT8_C(  66),  INT8_C(  71),  INT8_C(  50), -INT8_C(  35), -INT8_C( 101),  INT8_C( 103), -INT8_C(  19),  INT8_C(  23),
      -INT8_C(  44),  INT8_C( 108),  INT8_C( 108),  INT8_C(   1), -INT8_C(  32),  INT8_C(  98), -INT8_C(  75), -INT8_C(  69),
      -INT8_C( 111), -INT8_C(  98), -INT8_C(  79), -INT8_C(  54),  INT8_C(  61),  INT8_C( 123), -INT8_C(  23), -INT8_C( 111),
      -INT8_C( 121),  INT8_C(  26),  INT8_C(  51), -INT8_C(  21), -INT8_C(  22), -INT8_C( 123), -INT8_C( 127),  INT8_C(  44),
      -INT8_C(  51), -INT8_C(  77),  INT8_C(   9),  INT8_C( 104),  INT8_C(  26), -INT8_C(  10),      INT8_MAX, -INT8_C(  18),
       INT8_C(  98), -INT8_C(  21), -INT8_C(  17),  INT8_C(  66),  INT8_C(  77), -INT8_C(  91), -INT8_C(   2), -INT8_C(  33),
       INT8_C(  67), -INT8_C(  81), -INT8_C(  87),      INT8_MIN,  INT8_C(  43), -INT8_C( 110),  INT8_C(  18), -INT8_C(  78),
      -INT8_C(  83),  INT8_C(  69), -INT8_C(  98), -INT8_C( 105), -INT8_C(  54),  INT8_C(  31), -INT8_C(  60), -INT8_C( 105),
      -INT8_C(  45), -INT8_C(  51), -INT8_C(   1), -INT8_C(  19), -INT8_C(  60),  INT8_C( 126), -INT8_C(  36),  INT8_C(  38),
       INT8_C( 105), -INT8_C(  53),  INT8_C( 105), -INT8_C(  73),  INT8_C( 112),  INT8_C( 103), -INT8_C( 106), -INT8_C(  77),
       INT8_C(  22),  INT8_C(  63),  INT8_C(  52),  INT8_C(  65), -INT8_C(  47),  INT8_C(  70), -INT8_C(  12),  INT8_C( 126),
      -INT8_C( 117), -INT8_C( 110),  INT8_C(  22),  INT8_C(  85), -INT8_C(  79), -INT8_C(  38), -INT8_C(  19), -INT8_C( 124),
      -INT8_C(  89), -INT8_C(  20),  INT8_C( 114),  INT8_C( 107),  INT8_C( 107),  INT8_C(  78), -INT8_C( 110), -INT8_C(  44),
       INT8_C(  25), -INT8_C(   5), -INT8_C( 117), -INT8_C( 118),  INT8_C(  98),  INT8_C(  33),  INT8_C(  61),  INT8_C( 120),
       INT8_C(  96),  INT8_C( 113), -INT8_C(  70),  INT8_C(  50), -INT8_C(  73), -INT8_C(  82), -INT8_C(  80),  INT8_C(  66),
       INT8_C(  64), -INT8_C(  58), -INT8_C( 104), -INT8_C(  15), -INT8_C(  96), -INT8_C( 123),  INT8_C( 118),  INT8_C(  72),
       INT8_C( 113), -INT8_C(  24), -INT8_C(  77), -INT8_C(  36),  INT8_C(  54),  INT8_C(  69), -INT8_C(  79),  INT8_C(  79),
       INT8_C(  64),  INT8_C(  60), -INT8_C(  39), -INT8_C(  94),  INT8_C(  94),  INT8_C(  23),  INT8_C(  27), -INT8_C(  66),
      -INT8_C( 120), -INT8_C(  43), -INT8_C(  16),  INT8_C(  64), -INT8_C( 125), -INT8_C(  95), -INT8_C( 126), -INT8_C(  61),
       INT8_C( 103),  INT8_C(  26), -INT8_C(  76),  INT8_C(   8), -INT8_C(  97),  INT8_C(  42),  INT8_C(  80),  INT8_C(  17),
       INT8_C(  18),  INT8_C(   3), -INT8_C(  19),  INT8_C(  72),  INT8_C(  73), -INT8_C(  98), -INT8_C( 104), -INT8_C( 119),
      -INT8_C(  37),  INT8_C( 113),  INT8_C(  44),  INT8_C(  57), -INT8_C( 120),  INT8_C(  71), -INT8_C(   9),  INT8_C(  17),
       INT8_C(  28), -INT8_C(  24),  INT8_C(  81), -INT8_C(  97), -INT8_C( 119), -INT8_C(  45),  INT8_C(  98), -INT8_C(  16),
      -INT8_C(  18),  INT8_C(  22), -INT8_C(   8), -INT8_C( 115),  INT8_C(  65),  INT8_C(  72), -INT8_C(  98),  INT8_C(  83),
       INT8_C(  76), -INT8_C( 116), -INT8_C( 100), -INT8_C( 107),  INT8_C(  42),  INT8_C(  52),  INT8_C(  30),  INT8_C(   5),
      -INT8_C(  91),  INT8_C(  74),  INT8_C(  62),  INT8_C(  46), -INT8_C( 111),  INT8_C(  54),  INT8_C(  63), -INT8_C(  83),
       INT8_C(  30), -INT8_C( 112),  INT8_C(  76), -INT8_C(  89),  INT8_C(  99), -INT8_C(  82), -INT8_C( 105),  INT8_C(  81),
      -INT8_C(  59), -INT8_C( 112), -INT8_C(  33),  INT8_C(   6), -INT8_C(  40),  INT8_C( 125),  INT8_C(  89),  INT8_C(  36),
       INT8_C(   9), -INT8_C(  11), -INT8_C(  71),  INT8_C(  52),  INT8_C(  41), -INT8_C(  40),  INT8_C(  57), -INT8_C(  49),
       INT8_C(  34),  INT8_C( 120), -INT8_C(   3), -INT8_C(  76), -INT8_C(  82),  INT8_C(  60),  INT8_C(  97), -INT8_C(  52),
      -INT8_C(  52), -INT8_C(  82),  INT8_C( 115),  INT8_C(  47),  INT8_C(  92),  INT8_C(  10), -INT8_C( 127),  INT8_C(  33),
      -INT8_C( 102),  INT8_C(  96),  INT8_C(  39),  INT8_C( 115), -INT8_C(  35), -INT8_C( 127), -INT8_C( 105), -INT8_C(  25),
       INT8_C( 118),  INT8_C(  81),  INT8_C(  27), -INT8_C(  96),  INT8_C(  41),  INT8_C(  84),  INT8_C( 111),  INT8_C(  75),
      -INT8_C(  52),  INT8_C( 108), -INT8_C(   1),  INT8_C( 122), -INT8_C(  88),  INT8_C(  97),  INT8_C(  70),  INT8_C( 116),
       INT8_C(  15), -INT8_C(  71), -INT8_C(  93),  INT8_C( 107), -INT8_C(  60),  INT8_C(  36), -INT8_C( 115),  INT8_C(  94),
      -INT8_C( 124), -INT8_C(  76), -INT8_C(  47),  INT8_C(  98),  INT8_C(  53),  INT8_C( 105),  INT8_C(  73), -INT8_C(  84),
      -INT8_C(  70),  INT8_C( 100),  INT8_C(  76), -INT8_C(  29), -INT8_C(  72), -INT8_C(  69),  INT8_C(  46), -INT8_C( 123),
       INT8_C(  39),  INT8_C(  46), -INT8_C(   1), -INT8_C(  49), -INT8_C( 113),  INT8_C(  70),  INT8_C(  67), -INT8_C(  98),
      -INT8_C(   1), -INT8_C(  26),  INT8_C(   9), -INT8_C(  61),  INT8_C(  11), -INT8_C( 106),  INT8_C(  34), -INT8_C( 113),
       INT8_C(  75), -INT8_C(  13), -INT8_C(  15),      INT8_MIN,  INT8_C(  92),  INT8_C(  58),  INT8_C(  44),  INT8_C(  22),
      -INT8_C(  98),  INT8_C( 120), -INT8_C(   7),  INT8_C(  87),  INT8_C(  51),  INT8_C(  40), -INT8_C(  36),  INT8_C(  90),
       INT8_C(  86), -INT8_C(  37),  INT8_C(  41), -INT8_C(  27),  INT8_C(  33),  INT8_C( 108), -INT8_C( 125),  INT8_C(  33),
       INT8_C(  83), -INT8_C( 116), -INT8_C(  28),  INT8_C(  94),  INT8_C(  35),  INT8_C(   6), -INT8_C(  19),  INT8_C( 110),
      -INT8_C(   6), -INT8_C(  33), -INT8_C(  18),  INT8_C(  86),  INT8_C(  25),  INT8_C(  27),  INT8_C( 109), -INT8_C(  72),
      -INT8_C( 109),  INT8_C( 102),  INT8_C(  15), -INT8_C(  57), -INT8_C( 114), -INT8_C(  21),  INT8_C(  33), -INT8_C(  28),
      -INT8_C(  58),  INT8_C(  75), -INT8_C(  55), -INT8_C(  24), -INT8_C(  73),  INT8_C(  76),  INT8_C(   9),  INT8_C(  10),
      -INT8_C(  39), -INT8_C(  19),  INT8_C( 104), -INT8_C(   4), -INT8_C(  12),  INT8_C(  86),  INT8_C( 106), -INT8_C(  18),
       INT8_C(  53),  INT8_C(  88),  INT8_C(  68),  INT8_C(  78),  INT8_C( 115), -INT8_C(  79),  INT8_C(   6),  INT8_C(   7),
       INT8_C(  24),  INT8_C(  21), -INT8_C(  50), -INT8_C(  90),  INT8_C(   0), -INT8_C(  17), -INT8_C( 117), -INT8_C(  57),
       INT8_C(  58),  INT8_C(  84), -INT8_C(  81), -INT8_C(  14), -INT8_C(  95), -INT8_C(  72), -INT8_C(   4),  INT8_C( 122),
      -INT8_C(  91),  INT8_C( 101),  INT8_C( 118), -INT8_C( 103), -INT8_C(  69), -INT8_C(  32), -INT8_C( 121), -INT8_C(  16),
       INT8_C(  56), -INT8_C(  52),  INT8_C(  62), -INT8_C(  84),  INT8_C( 125),  INT8_C(  69), -INT8_C(  77), -INT8_C( 107),
       INT8_C(  90), -INT8_C( 127),  INT8_C(  60),  INT8_C(  91),  INT8_C( 112), -INT8_C(  57),  INT8_C(  34), -INT8_C(  85),
       INT8_C(  27), -INT8_C(  47), -INT8_C(  99), -INT8_C(  68), -INT8_C( 119), -INT8_C( 103),  INT8_C(  54),  INT8_C(  46),
      -INT8_C(   2), -INT8_C(  84), -INT8_C(  56), -INT8_C(  71), -INT8_C( 116),  INT8_C(  79), -INT8_C(  87), -INT8_C(  59),
       INT8_C(  27), -INT8_C(  24),  INT8_C( 113), -INT8_C( 103),  INT8_C(  45),  INT8_C(  36),  INT8_C(  46), -INT8_C( 121),
      -INT8_C(  91),  INT8_C( 106), -INT8_C(  30),  INT8_C(  21),  INT8_C(  49),  INT8_C(   4), -INT8_C(  64),  INT8_C(  77),
      -INT8_C(  43),  INT8_C(  93),  INT8_C(   9),  INT8_C(  94), -INT8_C(   9),  INT8_C(  64), -INT8_C( 115), -INT8_C(  11),
      -INT8_C(  20),  INT8_C(  85), -INT8_C(  81),  INT8_C( 121), -INT8_C(  92),  INT8_C(  88),  INT8_C(  62), -INT8_C(  64),
       INT8_C(  64), -INT8_C(  81),  INT8_C(  89),  INT8_C( 109), -INT8_C(  45), -INT8_C( 121), -INT8_C(  11),  INT8_C( 120),
      -INT8_C(  14), -INT8_C(  41), -INT8_C( 115),  INT8_C(  35), -INT8_C(  36),  INT8_C(  78),  INT8_C( 112), -INT8_C(  79),
      -INT8_C(  85),  INT8_C( 122),  INT8_C(  16), -INT8_C(  94), -INT8_C(  70), -INT8_C(  99), -INT8_C( 104), -INT8_C(  90),
      -INT8_C(  14),  INT8_C(  71),  INT8_C(  31), -INT8_C( 106), -INT8_C(  97),  INT8_C(  93),  INT8_C(  86), -INT8_C(  32),
       INT8_C(  12), -INT8_C(  81),  INT8_C(  77), -INT8_C(  33),  INT8_C(  55),  INT8_C(  66),  INT8_C(  87),  INT8_C(  41),
       INT8_C(  26), -INT8_C(  27),  INT8_C(  76), -INT8_C(  10),  INT8_C(  51), -INT8_C(  67), -INT8_C(  89), -INT8_C(  34),
       INT8_C(  55), -INT8_C(  73), -INT8_C( 127), -INT8_C(  15),  INT8_C(  84),  INT8_C(  25), -INT8_C( 105),  INT8_C(  70),
       INT8_C(  96), -INT8_C(  73), -INT8_C(  35), -INT8_C(   1),  INT8_C(  20),  INT8_C(  51), -INT8_C(  33),  INT8_C(  33),
      -INT8_C(  29),  INT8_C(  45),  INT8_C(   0),  INT8_C(  26),  INT8_C( 111),  INT8_C(  88),  INT8_C(  67), -INT8_C( 119),
       INT8_C(  61), -INT8_C( 113),      INT8_MAX,  INT8_C( 112),  INT8_C(  76),  INT8_C(  39),  INT8_C(  78), -INT8_C( 125),
      -INT8_C(  34), -INT8_C(  49),  INT8_C( 116),  INT8_C(  51), -INT8_C(  24),  INT8_C(  12),  INT8_C( 121),  INT8_C(  72),
      -INT8_C(  61),  INT8_C(  86),  INT8_C(  72), -INT8_C(  41), -INT8_C( 118),  INT8_C(  39), -INT8_C(   8),  INT8_C( 109),
       INT8_C(  84), -INT8_C(   7), -INT8_C( 121), -INT8_C(  60),  INT8_C(  81), -INT8_C(  54),  INT8_C(  77), -INT8_C( 114),
       INT8_C(  89), -INT8_C(  51), -INT8_C(   2), -INT8_C(  90), -INT8_C(  12),  INT8_C(  76),  INT8_C(  41), -INT8_C(  46),
       INT8_C(  28), -INT8_C(  98),  INT8_C(   5),  INT8_C(   4), -INT8_C(  86),      INT8_MAX,  INT8_C(  77),  INT8_C( 109),
      -INT8_C(  43), -INT8_C( 107),  INT8_C(  68),  INT8_C(  95), -INT8_C(  68),  INT8_C(  61), -INT8_C(  52),  INT8_C(  17),
       INT8_C(  54),  INT8_C(  83), -INT8_C(  43), -INT8_C( 121),  INT8_C(  29),  INT8_C(  34),  INT8_C(  21),  INT8_C( 119),
      -INT8_C(  17),  INT8_C(  19),  INT8_C(  29), -INT8_C(  29),  INT8_C(  95),  INT8_C(  70), -INT8_C(  74),  INT8_C( 123),
      -INT8_C(  28), -INT8_C(  69),      INT8_MIN, -INT8_C( 114),  INT8_C(  58), -INT8_C(  51), -INT8_C(   5),  INT8_C(  16),
       INT8_C(  98),  INT8_C(  64),  INT8_C( 111),  INT8_C(  30),  INT8_C( 125),  INT8_C(  60),  INT8_C(  47), -INT8_C(  77),
      -INT8_C( 113),  INT8_C(   4),  INT8_C(  58), -INT8_C(  83),  INT8_C(  39),  INT8_C(  79),  INT8_C(  36),  INT8_C(  22),
       INT8_C(  98),  INT8_C(  65), -INT8_C(   6), -INT8_C(  63), -INT8_C( 121), -INT8_C(  80),  INT8_C(  61),  INT8_C( 108),
       INT8_C( 107), -INT8_C(  67), -INT8_C(   6), -INT8_C(  90), -INT8_C( 118), -INT8_C(  10), -INT8_C(  74), -INT8_C(  20),
       INT8_C(  54),  INT8_C(  37),  INT8_C(  10), -INT8_C(  77),  INT8_C(  97),  INT8_C(  58),  INT8_C( 102), -INT8_C(  15),
       INT8_C(  62), -INT8_C(  96), -INT8_C(  98),  INT8_C( 101), -INT8_C(  17), -INT8_C(  62),  INT8_C( 124),  INT8_C(  81),
       INT8_C(   3),  INT8_C( 118),  INT8_C(  18), -INT8_C( 118),  INT8_C(  38),  INT8_C(  79), -INT8_C(  10), -INT8_C( 111),
       INT8_C(  12), -INT8_C(  15),  INT8_C(  55), -INT8_C( 106), -INT8_C(  25), -INT8_C(  19), -INT8_C( 126),  INT8_C(  29),
       INT8_C(  19), -INT8_C( 115), -INT8_C(  48),  INT8_C( 116), -INT8_C(  57),  INT8_C(  54),  INT8_C( 101),  INT8_C(   5),
      -INT8_C(  42),  INT8_C(   3),  INT8_C( 107), -INT8_C(  59), -INT8_C(  59), -INT8_C(  25),  INT8_C(  22), -INT8_C(  56),
       INT8_C(  93),  INT8_C(  40),  INT8_C(  83), -INT8_C( 125),  INT8_C( 120),  INT8_C(  73),  INT8_C(  20), -INT8_C( 124),
       INT8_C(  58),  INT8_C(  76),  INT8_C(  27),  INT8_C(  33),  INT8_C(  57), -INT8_C(  99),  INT8_C(  62),  INT8_C(  76),
       INT8_C(  42),  INT8_C(  14), -INT8_C(  63), -INT8_C(  15) };
  static const int8_t e[] =
    {  INT8_C(  58),  INT8_C(  80), -INT8_C(  37),  INT8_C(  79), -INT8_C(  54),  INT8_C(  26),  INT8_C( 125),  INT8_C(  21),
       INT8_C(  42), -INT8_C(  50),  INT8_C(  98), -INT8_C(  18), -INT8_C(  77),  INT8_C( 100), -INT8_C(   4),  INT8_C(  29),
      -INT8_C(  54), -INT8_C(  61),  INT8_C(  95),  INT8_C(  74),  INT8_C(  70), -INT8_C(  24),  INT8_C(  32), -INT8_C(  96),
       INT8_C(  61), -INT8_C(  81), -INT8_C(   8),  INT8_C(  76),  INT8_C(  77), -INT8_C(  19), -INT8_C(  47),  INT8_C(  55),
      -INT8_C(  11), -INT8_C(  64),  INT8_C(  49), -INT8_C( 114), -INT8_C(  37), -INT8_C(  82), -INT8_C(  44),  INT8_C(   4),
       INT8_C( 124), -INT8_C(  62), -INT8_C(  24), -INT8_C(  34),  INT8_C(  38), -INT8_C(  15), -INT8_C(   5),  INT8_C( 101),
      -INT8_C(  66), -INT8_C( 121), -INT8_C(  82),  INT8_C(   4),  INT8_C( 112), -INT8_C( 108),  INT8_C(   6),  INT8_C(  60),
       INT8_C( 125), -INT8_C( 125),  INT8_C( 100), -INT8_C(  54), -INT8_C(  52),  INT8_C(  53),  INT8_C( 101), -INT8_C(  63),
      -INT8_C(  70), -INT8_C( 106),      INT8_MIN,  INT8_C( 122),  INT8_C(  11),  INT8_C(  84), -INT8_C(  37),  INT8_C(  54),
       INT8_C(  75), -INT8_C(  41),  INT8_C(  67),  INT8_C( 114),  INT8_C(  74), -INT8_C(  64),  INT8_C(  64),  INT8_C( 125),
      -INT8_C( 106), -INT8_C( 119),  INT8_C( 104),  INT8_C(   6), -INT8_C(  25),  INT8_C(  16), -INT8_C(  87), -INT8_C(  84),
       INT8_C( 118),  INT8_C(  13), -INT8_C(  99), -INT8_C(  34),  INT8_C(  66),  INT8_C(  63),  INT8_C( 124), -INT8_C(   3),
       INT8_C(  20), -INT8_C(  92), -INT8_C(  54),  INT8_C(  25),  INT8_C(  45),  INT8_C(  35),  INT8_C(  84),  INT8_C( 121),
      -INT8_C( 119),  INT8_C(  29), -INT8_C(  97), -INT8_C(  45), -INT8_C(  35),  INT8_C( 121), -INT8_C(  62),  INT8_C( 122),
       INT8_C( 126),  INT8_C(  43), -INT8_C(  25),  INT8_C( 102),  INT8_C(  30), -INT8_C( 111),  INT8_C(  18), -INT8_C( 107),
      -INT8_C(  98), -INT8_C(  19),  INT8_C( 115), -INT8_C(  31), -INT8_C(  73),  INT8_C(  28),  INT8_C(  38),  INT8_C(   2),
      -INT8_C( 111), -INT8_C(  54), -INT8_C(  22),  INT8_C( 104),  INT8_C(  78), -INT8_C(  11), -INT8_C( 110), -INT8_C(  54),
      -INT8_C(  89),  INT8_C(  34),  INT8_C(  73), -INT8_C(  17), -INT8_C(  86), -INT8_C(  46),  INT8_C(  42), -INT8_C(  52),
      -INT8_C(   3),  INT8_C(  59),  INT8_C(  50),  INT8_C(  27),  INT8_C(   0),  INT8_C(  47), -INT8_C(  28),  INT8_C( 113),
       INT8_C(  50), -INT8_C( 124),  INT8_C(  98), -INT8_C(  81), -INT8_C(  96), -INT8_C( 110),  INT8_C(  96), -INT8_C(  95),
       INT8_C(  92),  INT8_C( 100),  INT8_C(  33),  INT8_C(  54),  INT8_C( 113), -INT8_C(  78),  INT8_C(   1),  INT8_C(  73),
      -INT8_C(  28),  INT8_C(  16),  INT8_C( 114), -INT8_C( 114), -INT8_C(  30), -INT8_C( 113),  INT8_C(  57),  INT8_C(  55),
       INT8_C(  46),  INT8_C(   7),  INT8_C(  55), -INT8_C(  53),  INT8_C(  76),  INT8_C(  27),  INT8_C(  59),  INT8_C( 126),
      -INT8_C(  96), -INT8_C(  89),  INT8_C(  18),  INT8_C(  64),  INT8_C(  57),  INT8_C(  61), -INT8_C(   7), -INT8_C( 106),
      -INT8_C(  15),  INT8_C(  26), -INT8_C(  32), -INT8_C( 109),  INT8_C( 120),  INT8_C(  83), -INT8_C(  83),  INT8_C(  50),
      -INT8_C(  85),  INT8_C(  31),  INT8_C(  61),  INT8_C(  70), -INT8_C(   4),  INT8_C( 118),  INT8_C(  16),  INT8_C(  42),
       INT8_C(  22),  INT8_C(  71),  INT8_C(  58),  INT8_C(  98), -INT8_C(  52), -INT8_C(  52), -INT8_C( 126),  INT8_C(   2),
      -INT8_C(  65), -INT8_C( 108),  INT8_C( 123), -INT8_C(  13),  INT8_C(  32), -INT8_C(   4),  INT8_C(  26), -INT8_C(  78),
       INT8_C(  86),  INT8_C(  97), -INT8_C(  92),  INT8_C(  85), -INT8_C(  75), -INT8_C( 119), -INT8_C( 120),  INT8_C(  69),
      -INT8_C(  62), -INT8_C(  62),  INT8_C(  95), -INT8_C(  91), -INT8_C(  47),  INT8_C(  45),  INT8_C(  48), -INT8_C(  25),
      -INT8_C(  90), -INT8_C( 105),  INT8_C(  84), -INT8_C(  41), -INT8_C(  43), -INT8_C(  42), -INT8_C(  39), -INT8_C( 123),
      -INT8_C(  26), -INT8_C( 119),  INT8_C(   9), -INT8_C( 118), -INT8_C( 123), -INT8_C( 105), -INT8_C( 110),  INT8_C(  98),
      -INT8_C(   8),  INT8_C( 110), -INT8_C(  72), -INT8_C(  73), -INT8_C(  64),  INT8_C(  64), -INT8_C(   4), -INT8_C(  95),
      -INT8_C(  82),  INT8_C(  26),  INT8_C(  21),  INT8_C(  51),  INT8_C(  71),  INT8_C(  21), -INT8_C(  69), -INT8_C(  68),
      -INT8_C(  36), -INT8_C(  66), -INT8_C( 109), -INT8_C(  12),  INT8_C(  46), -INT8_C(  45), -INT8_C( 100), -INT8_C(   3),
       INT8_C(  93),  INT8_C(  17), -INT8_C( 120), -INT8_C(  31), -INT8_C(  88),  INT8_C(  36), -INT8_C( 112), -INT8_C(  27),
      -INT8_C(  12),  INT8_C(  95), -INT8_C(  99),  INT8_C(  34),  INT8_C(  61), -INT8_C( 103), -INT8_C( 115), -INT8_C(  82),
       INT8_C(  58), -INT8_C(  71), -INT8_C(  32), -INT8_C(   5), -INT8_C(   2),  INT8_C(  74), -INT8_C(  73), -INT8_C(  37),
      -INT8_C(  44), -INT8_C(   3), -INT8_C(  14), -INT8_C( 102), -INT8_C(  74), -INT8_C( 114), -INT8_C( 104),  INT8_C(  63),
       INT8_C(  51),  INT8_C(  11),  INT8_C(  33),  INT8_C(  61), -INT8_C( 111),  INT8_C(  85), -INT8_C(  35), -INT8_C( 123),
       INT8_C(  82),  INT8_C( 124), -INT8_C(  55),  INT8_C(  15),  INT8_C(  21),  INT8_C( 109), -INT8_C(  68), -INT8_C(  56),
       INT8_C(  38), -INT8_C(  30), -INT8_C(  62), -INT8_C(  69), -INT8_C(  25),  INT8_C( 121), -INT8_C(   2), -INT8_C( 123),
      -INT8_C( 107), -INT8_C(  16), -INT8_C( 121),  INT8_C( 102),  INT8_C(  65),  INT8_C(  32), -INT8_C( 109), -INT8_C(  42),
       INT8_C(  64), -INT8_C(  40), -INT8_C(  86), -INT8_C( 125), -INT8_C( 120), -INT8_C( 118),  INT8_C(  42),  INT8_C(  74),
       INT8_C(   6), -INT8_C(  13), -INT8_C(  91),  INT8_C(  27),  INT8_C(  96), -INT8_C(  88), -INT8_C(  29),  INT8_C(   4),
      -INT8_C(   1), -INT8_C(  91), -INT8_C(  64),  INT8_C(  59), -INT8_C(  48), -INT8_C( 126), -INT8_C(  45), -INT8_C(  31),
      -INT8_C( 103),  INT8_C(  91),  INT8_C(  89), -INT8_C( 127),  INT8_C( 123),  INT8_C(  17),  INT8_C(  88), -INT8_C( 113),
       INT8_C(   2),  INT8_C( 107), -INT8_C(  54), -INT8_C(   5),  INT8_C(  92), -INT8_C( 118),  INT8_C(   8),  INT8_C( 121),
      -INT8_C(  68), -INT8_C(  82),  INT8_C(  27), -INT8_C(  69),  INT8_C(  16), -INT8_C(  84),  INT8_C(  66),  INT8_C(  15),
      -INT8_C(  92), -INT8_C(  78), -INT8_C(  12), -INT8_C(  76),  INT8_C(  52), -INT8_C(  57), -INT8_C(  93),  INT8_C( 116),
      -INT8_C( 109), -INT8_C(   3), -INT8_C(  10), -INT8_C(  99),  INT8_C(  14),  INT8_C(   9),  INT8_C(   9),  INT8_C(  70),
       INT8_C( 121), -INT8_C( 105),  INT8_C( 104),  INT8_C(  22), -INT8_C(   1), -INT8_C( 121), -INT8_C( 113),  INT8_C(  91),
       INT8_C(  30), -INT8_C( 113),  INT8_C(  22),  INT8_C(  45),  INT8_C(  17), -INT8_C(   8), -INT8_C(  66),  INT8_C(  50),
       INT8_C(  67),  INT8_C(  74), -INT8_C(  11), -INT8_C(  41), -INT8_C(   9), -INT8_C( 104),  INT8_C(   3),  INT8_C(  41),
      -INT8_C( 107),  INT8_C(  73), -INT8_C(  93), -INT8_C(  21),  INT8_C(  78),  INT8_C(  14), -INT8_C( 102), -INT8_C(  56),
           INT8_MAX,  INT8_C( 115),  INT8_C(  59), -INT8_C(  93), -INT8_C(   6), -INT8_C(  81), -INT8_C(   2), -INT8_C( 113),
       INT8_C(  62), -INT8_C(   5), -INT8_C(  68), -INT8_C(  52),  INT8_C( 107), -INT8_C(  53), -INT8_C(   2), -INT8_C(  98),
       INT8_C(  21), -INT8_C(  13),  INT8_C( 125), -INT8_C(  85), -INT8_C( 117), -INT8_C(  47), -INT8_C(  43),  INT8_C( 115),
       INT8_C(  26), -INT8_C(  20), -INT8_C(  61), -INT8_C(  78),  INT8_C(  36), -INT8_C( 111),  INT8_C(   3), -INT8_C(  93),
       INT8_C(   4),  INT8_C(  32),      INT8_MAX, -INT8_C(  47), -INT8_C(  49),  INT8_C( 116),  INT8_C(  96),  INT8_C(  13),
       INT8_C(  81), -INT8_C(  83), -INT8_C(  38),  INT8_C(  99),  INT8_C( 120), -INT8_C( 122),  INT8_C( 107),  INT8_C(  61),
      -INT8_C( 112),      INT8_MAX,  INT8_C(  90),  INT8_C(  86),  INT8_C(  80),  INT8_C(  14), -INT8_C(  49),  INT8_C(  71),
       INT8_C( 125),  INT8_C(  57),  INT8_C(  29),  INT8_C( 118), -INT8_C(  65),  INT8_C(  32),  INT8_C(  77), -INT8_C(  11),
       INT8_C( 104),  INT8_C(  84), -INT8_C(  61),  INT8_C(  54), -INT8_C( 110),  INT8_C(  38), -INT8_C(  92), -INT8_C(  80),
       INT8_C(  15),  INT8_C(  28), -INT8_C(  96), -INT8_C( 120),  INT8_C(  81),  INT8_C(  11), -INT8_C( 107), -INT8_C(  31),
      -INT8_C(   5), -INT8_C(  17),  INT8_C(  22), -INT8_C(  27), -INT8_C( 127),  INT8_C(  12), -INT8_C(  71), -INT8_C(   3),
       INT8_C(  59),  INT8_C(  28),  INT8_C( 116), -INT8_C(   6), -INT8_C( 115), -INT8_C(  36),  INT8_C(  79),  INT8_C(  23),
      -INT8_C(  35),  INT8_C(  21),  INT8_C(   2), -INT8_C(  23),  INT8_C(  60), -INT8_C(  90),  INT8_C(  83),      INT8_MAX,
       INT8_C( 112), -INT8_C(  12),  INT8_C( 123), -INT8_C(  63), -INT8_C(  62), -INT8_C( 111), -INT8_C(  94),  INT8_C(  87),
       INT8_C(  93), -INT8_C(  33),  INT8_C(  61), -INT8_C(  35), -INT8_C(  73), -INT8_C( 115),  INT8_C(  35),  INT8_C( 123),
      -INT8_C(   5), -INT8_C(  78), -INT8_C(  43), -INT8_C( 120), -INT8_C( 113),  INT8_C(  37), -INT8_C(  96), -INT8_C(  77),
       INT8_C(  58),  INT8_C( 115),  INT8_C(  33),  INT8_C(  69), -INT8_C(  72), -INT8_C(  69),  INT8_C(  57), -INT8_C(  72),
       INT8_C( 104), -INT8_C(  76),  INT8_C( 121),  INT8_C( 103),  INT8_C(  70), -INT8_C( 122),  INT8_C(  96),  INT8_C(  39),
      -INT8_C(   5), -INT8_C(  65),  INT8_C( 117),  INT8_C( 103),  INT8_C(  76), -INT8_C( 119),  INT8_C(  14),  INT8_C(  71),
      -INT8_C(  98),  INT8_C(  48), -INT8_C(  48),  INT8_C( 116), -INT8_C(  35),  INT8_C( 112),  INT8_C(  39),  INT8_C( 113),
       INT8_C(  17),  INT8_C(  73), -INT8_C(  73),  INT8_C(  89), -INT8_C(  33), -INT8_C(  16),  INT8_C(  17),  INT8_C(  71),
       INT8_C(  81), -INT8_C(   2), -INT8_C( 114), -INT8_C( 116), -INT8_C(  90), -INT8_C(  18),  INT8_C(  36), -INT8_C(  94),
      -INT8_C(  71), -INT8_C( 104), -INT8_C( 119), -INT8_C(  87),  INT8_C(   1), -INT8_C( 104),  INT8_C(  71), -INT8_C( 123),
      -INT8_C(  56), -INT8_C(  79),  INT8_C(   8), -INT8_C(  40), -INT8_C(   7),  INT8_C(  32),  INT8_C(  73), -INT8_C( 104),
       INT8_C( 105), -INT8_C(  75), -INT8_C(  15),  INT8_C(  15), -INT8_C(  16), -INT8_C(  74),  INT8_C(  86), -INT8_C( 117),
      -INT8_C( 115), -INT8_C(  56),      INT8_MAX,  INT8_C(  55), -INT8_C(  56), -INT8_C( 111), -INT8_C(  43),  INT8_C( 111),
       INT8_C(   8),  INT8_C(  95),  INT8_C( 111),  INT8_C(   9), -INT8_C( 124), -INT8_C(  74),  INT8_C(  70), -INT8_C(  65),
      -INT8_C(  51),  INT8_C(  57), -INT8_C( 105),  INT8_C(  84),  INT8_C(  89), -INT8_C(  15), -INT8_C(  20), -INT8_C( 119),
      -INT8_C(  31), -INT8_C( 118), -INT8_C(  23), -INT8_C(  47),  INT8_C(  63),  INT8_C(  54),  INT8_C( 106), -INT8_C(  13),
       INT8_C(  18), -INT8_C(  26),  INT8_C(  43), -INT8_C(  38), -INT8_C(  68), -INT8_C( 106), -INT8_C(  29), -INT8_C( 113),
      -INT8_C(  43),  INT8_C(  82), -INT8_C( 119),  INT8_C(  32), -INT8_C( 117), -INT8_C(  49), -INT8_C( 117),  INT8_C(  64),
      -INT8_C(  60),  INT8_C(  34), -INT8_C(  19),  INT8_C( 119), -INT8_C( 109),  INT8_C(  21), -INT8_C(  34), -INT8_C(  28),
      -INT8_C(  40), -INT8_C( 104), -INT8_C(  75), -INT8_C(  44), -INT8_C( 121), -INT8_C( 125),  INT8_C(  65),  INT8_C(  62),
       INT8_C(   2),  INT8_C(  54), -INT8_C(  23), -INT8_C(  64), -INT8_C(  51),  INT8_C(  69),  INT8_C(  79),  INT8_C( 105),
      -INT8_C(  26), -INT8_C( 103), -INT8_C( 118), -INT8_C(  18),  INT8_C(  81),  INT8_C(  98), -INT8_C( 107), -INT8_C(  24),
      -INT8_C(  87), -INT8_C( 126), -INT8_C(  26), -INT8_C( 105), -INT8_C(  47), -INT8_C(  29), -INT8_C( 112), -INT8_C(  88),
           INT8_MAX,  INT8_C(  69), -INT8_C(  55),  INT8_C(   6),  INT8_C(  97),  INT8_C(  11),  INT8_C(  68),  INT8_C(  99),
      -INT8_C(  19), -INT8_C(  10), -INT8_C(  36), -INT8_C(  51), -INT8_C( 118),  INT8_C( 125),  INT8_C(  55),  INT8_C( 113),
       INT8_C(  22),  INT8_C( 112),  INT8_C(   6),  INT8_C(  58),  INT8_C(  35),  INT8_C(  35),  INT8_C(  33),  INT8_C(  39),
       INT8_C(  15),  INT8_C(  38), -INT8_C(  66),  INT8_C(  17),  INT8_C(   8), -INT8_C( 115),  INT8_C(   7), -INT8_C(  78),
       INT8_C( 118), -INT8_C(  48),  INT8_C( 106), -INT8_C( 126),  INT8_C(  33),  INT8_C(  17), -INT8_C(  26), -INT8_C(  55),
      -INT8_C(  92),  INT8_C( 123),  INT8_C(  15),  INT8_C(  47), -INT8_C( 105),  INT8_C(  39),  INT8_C(  74),  INT8_C(  14),
      -INT8_C(  24), -INT8_C(   1),  INT8_C(  72), -INT8_C(  21), -INT8_C(  21), -INT8_C(  84),  INT8_C(  51),  INT8_C(  50),
      -INT8_C( 113), -INT8_C(  15),  INT8_C(  67), -INT8_C( 105), -INT8_C(  79), -INT8_C( 115), -INT8_C(  16), -INT8_C(  46),
      -INT8_C(  28), -INT8_C(  93),  INT8_C(  85),  INT8_C(   5), -INT8_C(  75),  INT8_C(  34), -INT8_C(  65),  INT8_C( 103),
      -INT8_C(   3), -INT8_C(  49), -INT8_C(   1), -INT8_C( 106),  INT8_C(  63),  INT8_C( 124), -INT8_C(  92),  INT8_C(  72),
      -INT8_C( 103),  INT8_C(  24),  INT8_C(  51), -INT8_C(  98), -INT8_C(  60),  INT8_C( 101), -INT8_C(  48),  INT8_C( 109),
      -INT8_C( 109), -INT8_C( 123),  INT8_C( 123), -INT8_C(  43),  INT8_C(  94), -INT8_C(  21), -INT8_C(  55),  INT8_C( 121),
       INT8_C( 103), -INT8_C(  99),  INT8_C( 112),  INT8_C(  78), -INT8_C(  65),  INT8_C(  47), -INT8_C( 125), -INT8_C(  91),
      -INT8_C(   2), -INT8_C( 126), -INT8_C(  14),  INT8_C(  82), -INT8_C(  53), -INT8_C(  67), -INT8_C( 102),  INT8_C( 100),
      -INT8_C(  43), -INT8_C(  51), -INT8_C(  24), -INT8_C(  42),  INT8_C(  57),  INT8_C(  64), -INT8_C(  70), -INT8_C( 112),
      -INT8_C(   5),  INT8_C(   2),  INT8_C(  99),  INT8_C(  12), -INT8_C(  19),  INT8_C( 122),  INT8_C(   3),  INT8_C(  50),
      -INT8_C(  25), -INT8_C( 100), -INT8_C( 127), -INT8_C( 118), -INT8_C(  53),  INT8_C( 125), -INT8_C(  26), -INT8_C(  54),
           INT8_MIN, -INT8_C(  40),  INT8_C(  28),  INT8_C(  75),  INT8_C(  42),  INT8_C( 121),  INT8_C( 123),  INT8_C(   0),
       INT8_C(  77), -INT8_C(  21), -INT8_C( 102), -INT8_C( 122),  INT8_C(  43),      INT8_MAX,  INT8_C(  22),  INT8_C(   8),
      -INT8_C(  93),  INT8_C( 123),  INT8_C(  20), -INT8_C( 112),  INT8_C(   9),  INT8_C(  23),  INT8_C(  13), -INT8_C(  16),
       INT8_C(  21),  INT8_C(  68),  INT8_C( 126),  INT8_C(  55), -INT8_C(  63), -INT8_C(  27), -INT8_C( 113),  INT8_C(  22),
      -INT8_C(  67),  INT8_C( 107), -INT8_C(  63),  INT8_C(  44), -INT8_C(  28),  INT8_C(  60),  INT8_C(  74),  INT8_C(  49),
      -INT8_C( 104), -INT8_C(  28), -INT8_C(  15), -INT8_C(  91), -INT8_C( 123), -INT8_C(  50), -INT8_C(  83),  INT8_C(  41),
       INT8_C(  73), -INT8_C(  62), -INT8_C(  65), -INT8_C(  13),  INT8_C(  96),  INT8_C( 124),  INT8_C( 103),  INT8_C(  90),
      -INT8_C(  64),  INT8_C( 102),  INT8_C(  31), -INT8_C( 127),  INT8_C(  75), -INT8_C(  72), -INT8_C(  30),  INT8_C(   8),
       INT8_C(  89),  INT8_C(  52),  INT8_C(  62),  INT8_C(   7), -INT8_C( 107), -INT8_C( 120),  INT8_C(  56), -INT8_C(  52),
       INT8_C(  46), -INT8_C(  17),  INT8_C( 113), -INT8_C( 115), -INT8_C(  84),  INT8_C(  31), -INT8_C(  97),  INT8_C(  88),
      -INT8_C(  28),  INT8_C(  94), -INT8_C(   6), -INT8_C(  70),  INT8_C(  43),  INT8_C(  98), -INT8_C(  98),      INT8_MIN,
      -INT8_C(  56), -INT8_C(  67), -INT8_C( 109),  INT8_C(  19), -INT8_C( 124),  INT8_C(  62), -INT8_C(  99), -INT8_C(  60),
       INT8_C( 113),  INT8_C(  79),  INT8_C( 126), -INT8_C(  91),  INT8_C( 100), -INT8_C(  26),  INT8_C( 113), -INT8_C(  52),
      -INT8_C(  84), -INT8_C(  26),  INT8_C(  88), -INT8_C( 109), -INT8_C(  57), -INT8_C(   9), -INT8_C( 102), -INT8_C(  85),
      -INT8_C(  78), -INT8_C( 107), -INT8_C(  17),      INT8_MIN,  INT8_C( 110), -INT8_C( 114),  INT8_C(   1),  INT8_C(  66),
       INT8_C(  17),  INT8_C(  92), -INT8_C(  48), -INT8_C(  73), -INT8_C( 102), -INT8_C( 120),  INT8_C(  61),  INT8_C(  11),
       INT8_C(  58), -INT8_C(  20),  INT8_C( 112), -INT8_C(  55) };

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
    rv = simde_svsub_s8_m(pv, av, bv);

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

    ev = simde_svsub_s8_m(pv, av, bv);

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
test_simde_svsub_s16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) };
  static const int16_t a[] =
    { -INT16_C( 20651), -INT16_C( 32518), -INT16_C( 12458),  INT16_C(  2519),  INT16_C( 12869), -INT16_C( 13246), -INT16_C( 16446), -INT16_C( 28409),
       INT16_C( 22501), -INT16_C(  9975),  INT16_C( 31755), -INT16_C(  7895), -INT16_C( 27288), -INT16_C( 11471),  INT16_C(  5139),  INT16_C( 26634),
       INT16_C(  1476),  INT16_C(  6888), -INT16_C( 16172),  INT16_C(  6435),  INT16_C( 26354), -INT16_C( 19227), -INT16_C(  4827),  INT16_C(  2886),
       INT16_C( 20292),  INT16_C( 20708),  INT16_C(  3531),  INT16_C( 13105),  INT16_C( 25507), -INT16_C( 18938),  INT16_C(  4471),  INT16_C( 15135),
       INT16_C(  1814), -INT16_C(  5547),  INT16_C( 31175), -INT16_C( 17917), -INT16_C(  5921),  INT16_C(  1134), -INT16_C( 19243),  INT16_C(  6671),
      -INT16_C(  3069), -INT16_C( 12438), -INT16_C( 25855), -INT16_C( 23550),  INT16_C(  2558),  INT16_C( 30299),  INT16_C( 31258),  INT16_C( 12465),
       INT16_C(  1921),  INT16_C( 18714),  INT16_C(  7552),  INT16_C( 24323),  INT16_C( 28933), -INT16_C(  9373),  INT16_C( 29478),  INT16_C( 10741),
       INT16_C( 24423),  INT16_C( 26872), -INT16_C(  1030), -INT16_C(  1779),  INT16_C( 26628),  INT16_C(  7791),  INT16_C(  8418),  INT16_C( 25422),
       INT16_C( 26663), -INT16_C( 22612), -INT16_C( 20603), -INT16_C( 30202),  INT16_C( 27169),  INT16_C( 18277),  INT16_C( 23261),  INT16_C( 17520),
       INT16_C( 27065), -INT16_C( 19284), -INT16_C( 18076),  INT16_C( 26797),  INT16_C(  7201),  INT16_C(   902), -INT16_C( 11204),  INT16_C( 25703),
       INT16_C(  4924), -INT16_C( 16117),  INT16_C(  4803), -INT16_C(  7093), -INT16_C( 20100),  INT16_C( 22827), -INT16_C( 25845), -INT16_C( 14947),
       INT16_C( 18692),  INT16_C( 26745),  INT16_C(  9731),  INT16_C(  9424),  INT16_C( 22082),  INT16_C( 32296), -INT16_C( 28886),  INT16_C( 26338),
      -INT16_C(  4446),  INT16_C( 25895),  INT16_C( 29440),  INT16_C( 31817),  INT16_C( 29732),  INT16_C( 12245),  INT16_C( 29200),  INT16_C(  5364),
       INT16_C( 28091), -INT16_C( 16771),  INT16_C( 19859), -INT16_C( 10781),  INT16_C(  2980), -INT16_C( 12716),  INT16_C( 13978),  INT16_C( 15413),
       INT16_C( 23588),  INT16_C(  9378), -INT16_C(  5169), -INT16_C(  3168),  INT16_C( 30048),  INT16_C( 28707),  INT16_C(  6119), -INT16_C( 23676),
       INT16_C(   389),  INT16_C(  6241),  INT16_C( 17487), -INT16_C(  3090),  INT16_C( 16975), -INT16_C(  5695), -INT16_C(  2440), -INT16_C( 25306),
      -INT16_C( 14253),  INT16_C(  8897),  INT16_C( 25267),  INT16_C(  4886),  INT16_C( 14807), -INT16_C( 16509),  INT16_C(  2128), -INT16_C( 10910),
      -INT16_C( 15607),  INT16_C( 22766), -INT16_C(  9208),  INT16_C( 22347),  INT16_C(  3358), -INT16_C( 27071),  INT16_C( 26371),  INT16_C( 22067),
      -INT16_C(  2769), -INT16_C(  7559), -INT16_C( 28841),  INT16_C( 12022),  INT16_C( 31176),  INT16_C(  6381),  INT16_C( 20353), -INT16_C( 29714),
      -INT16_C(  9197),  INT16_C(  7139),  INT16_C( 12216), -INT16_C( 10638), -INT16_C( 19652),  INT16_C( 16236), -INT16_C( 24550),  INT16_C( 18838),
       INT16_C(  3989), -INT16_C(  5076),  INT16_C(  8862),  INT16_C( 26138),  INT16_C(  2203),  INT16_C(  7550),  INT16_C( 27735),  INT16_C( 27304),
      -INT16_C( 29880),  INT16_C(   133), -INT16_C(  1862), -INT16_C(  2346),  INT16_C( 17323), -INT16_C( 14794), -INT16_C( 13085),  INT16_C( 30735),
       INT16_C( 15323),  INT16_C( 31076),  INT16_C( 32349), -INT16_C(  1569),  INT16_C( 23942), -INT16_C(  8682), -INT16_C( 16694),  INT16_C(  4680),
      -INT16_C( 12727),  INT16_C(  1043), -INT16_C(  5690),  INT16_C( 29178),  INT16_C( 12332),  INT16_C(  3895),  INT16_C( 18428), -INT16_C( 10361),
      -INT16_C(  5246), -INT16_C(  8112),  INT16_C( 12138), -INT16_C(  3879), -INT16_C(  4211),  INT16_C( 22478),  INT16_C(  6061), -INT16_C(  2455),
       INT16_C( 31973), -INT16_C( 21510), -INT16_C(  2714), -INT16_C( 28132),  INT16_C( 21541),  INT16_C(  8866),  INT16_C( 10651),  INT16_C(  7673),
       INT16_C( 18965),  INT16_C( 32765), -INT16_C( 10631),  INT16_C(  1647),  INT16_C( 16069),  INT16_C( 29277), -INT16_C( 14507),  INT16_C( 14953),
       INT16_C( 25411), -INT16_C( 22043),  INT16_C(   344),  INT16_C( 32316), -INT16_C(  8619), -INT16_C(  3936), -INT16_C( 26361),  INT16_C(  7182),
       INT16_C(  3043),  INT16_C( 23963),  INT16_C(  3042), -INT16_C( 22685), -INT16_C( 16055), -INT16_C( 25062), -INT16_C( 31864), -INT16_C( 13352),
      -INT16_C( 16922),  INT16_C( 16245), -INT16_C( 20034),  INT16_C(  5309),  INT16_C( 23951), -INT16_C( 27132),  INT16_C(  4854), -INT16_C(  9549),
       INT16_C( 19998),  INT16_C(    55), -INT16_C( 26023), -INT16_C( 23897), -INT16_C( 16037), -INT16_C(  7360),  INT16_C(  6212),  INT16_C( 11183),
       INT16_C(  9429), -INT16_C( 27542),  INT16_C( 10197),  INT16_C( 25768), -INT16_C( 21372),  INT16_C( 31482), -INT16_C( 21057), -INT16_C(  8876),
      -INT16_C( 29700),  INT16_C( 21981), -INT16_C( 31706), -INT16_C( 32264),  INT16_C( 14406), -INT16_C( 30107),  INT16_C(  5201),  INT16_C(  9909),
       INT16_C(  7992),  INT16_C(  3514),  INT16_C( 25158), -INT16_C( 13711),  INT16_C( 27407), -INT16_C( 12731), -INT16_C( 26343),  INT16_C(  5547),
      -INT16_C( 30683),  INT16_C( 19306),  INT16_C( 25100),  INT16_C( 21196),  INT16_C( 12699), -INT16_C(  4899), -INT16_C( 28091),  INT16_C( 32018),
      -INT16_C( 12878), -INT16_C(  1910), -INT16_C(  1233),  INT16_C( 16067),  INT16_C(  2151), -INT16_C( 32756), -INT16_C( 18527), -INT16_C( 14699),
      -INT16_C(   193),  INT16_C( 19473), -INT16_C(  8606), -INT16_C(   610),  INT16_C( 31503),  INT16_C( 21993), -INT16_C(  1266), -INT16_C( 16174),
       INT16_C( 24008), -INT16_C(  1864),  INT16_C( 31576), -INT16_C( 16586),  INT16_C( 17283),  INT16_C(  9535), -INT16_C( 11014),  INT16_C( 15083),
      -INT16_C(   556),  INT16_C( 13958),  INT16_C(  9435), -INT16_C(  5581),  INT16_C(  7328), -INT16_C( 20929),  INT16_C(  4631), -INT16_C(  8082),
       INT16_C(  9839), -INT16_C( 14376),  INT16_C(  3746),  INT16_C(  9607), -INT16_C( 14767),  INT16_C( 19530),  INT16_C( 13979),  INT16_C( 28550),
       INT16_C(  3123),  INT16_C(  3749), -INT16_C( 10192), -INT16_C( 12040),  INT16_C( 14580),  INT16_C(  2942), -INT16_C(  5046), -INT16_C( 17941),
      -INT16_C( 15597), -INT16_C( 19072),  INT16_C(  2002),  INT16_C(  9178),  INT16_C(  9678),  INT16_C( 26991), -INT16_C(  2725), -INT16_C( 28968),
       INT16_C( 32001),  INT16_C( 12956), -INT16_C( 27563),  INT16_C( 18690), -INT16_C( 32308),  INT16_C(  5716),  INT16_C( 16493), -INT16_C( 32561),
       INT16_C( 20483), -INT16_C( 10955),  INT16_C(  4183),  INT16_C(  9721),  INT16_C( 26677), -INT16_C( 28530),  INT16_C( 26206),  INT16_C( 24350),
      -INT16_C( 17693),  INT16_C( 14481), -INT16_C( 27570),  INT16_C(  7041), -INT16_C( 10731), -INT16_C( 32207),  INT16_C(   278),  INT16_C(  6403),
       INT16_C( 14417), -INT16_C( 22289), -INT16_C(  6072),  INT16_C( 32206),  INT16_C( 23632), -INT16_C( 20979),  INT16_C( 11203), -INT16_C( 23026),
      -INT16_C( 24603),  INT16_C( 13535),  INT16_C( 24627),  INT16_C( 18511), -INT16_C( 32714),  INT16_C( 19659), -INT16_C( 12671), -INT16_C( 11674),
       INT16_C( 21766),  INT16_C( 20347),  INT16_C( 18749), -INT16_C( 29236), -INT16_C(  9563),  INT16_C( 26684),  INT16_C( 18949), -INT16_C(  5361),
      -INT16_C(  4375),  INT16_C(  7455),  INT16_C( 28238), -INT16_C( 31387),  INT16_C( 12526),  INT16_C( 28881),  INT16_C( 14334),  INT16_C(  1346),
      -INT16_C( 17012), -INT16_C( 13996),  INT16_C(  8198), -INT16_C( 21417), -INT16_C( 27654),  INT16_C(    20),  INT16_C(  9181), -INT16_C( 14613),
       INT16_C(  2577),  INT16_C( 24803),  INT16_C( 18808),  INT16_C( 26341), -INT16_C( 18823),  INT16_C( 30934),  INT16_C(  6638),  INT16_C( 31357),
      -INT16_C( 11818), -INT16_C(  8892), -INT16_C( 25615), -INT16_C(  4983), -INT16_C( 25298),  INT16_C(  3052), -INT16_C( 10303), -INT16_C( 11567),
      -INT16_C( 18975),  INT16_C( 22834),  INT16_C(  6142),  INT16_C( 30655), -INT16_C( 26930), -INT16_C( 17169),  INT16_C( 27823), -INT16_C( 31434),
       INT16_C( 31293),  INT16_C( 12130), -INT16_C(  5355),  INT16_C( 17179),  INT16_C(  1929),  INT16_C( 19022),  INT16_C(  8414), -INT16_C( 16612),
       INT16_C( 20437), -INT16_C( 11496), -INT16_C( 10394),  INT16_C( 13386),  INT16_C( 14957),  INT16_C(  7408),  INT16_C( 10150), -INT16_C(  7006),
       INT16_C(  1185), -INT16_C( 18669),  INT16_C( 12016),  INT16_C( 31226),  INT16_C( 18741),  INT16_C(  5059), -INT16_C(  8343),  INT16_C( 16082),
      -INT16_C(  5586), -INT16_C( 27375),  INT16_C( 23489),  INT16_C( 12233), -INT16_C( 17771),  INT16_C( 15435), -INT16_C(  4639), -INT16_C( 32224),
       INT16_C( 13298), -INT16_C(  7623),  INT16_C( 13409), -INT16_C( 27045),  INT16_C(  7805), -INT16_C(  6487),  INT16_C( 31741),  INT16_C( 11300),
       INT16_C( 13669),  INT16_C(  9921), -INT16_C( 30064),  INT16_C(  9813), -INT16_C( 24252),  INT16_C(  9570), -INT16_C( 32114), -INT16_C( 32600),
      -INT16_C(  7755),  INT16_C(  5730), -INT16_C( 17131), -INT16_C( 27988),  INT16_C( 21979), -INT16_C(  9864), -INT16_C( 25392),  INT16_C( 13573),
      -INT16_C( 14639),  INT16_C( 25179), -INT16_C( 20144), -INT16_C( 27256), -INT16_C(  5550), -INT16_C(  8006),  INT16_C( 25196),  INT16_C(  8545),
      -INT16_C( 15548),  INT16_C( 22839), -INT16_C(  7295),  INT16_C( 23788),  INT16_C( 25656),  INT16_C(  2101),  INT16_C( 14849), -INT16_C( 11715),
      -INT16_C( 26624),  INT16_C( 20788), -INT16_C( 17335), -INT16_C( 25626), -INT16_C( 24410),  INT16_C(  4732), -INT16_C(  8957),  INT16_C( 18227),
       INT16_C( 27296),  INT16_C(  8608), -INT16_C( 29619), -INT16_C( 31362), -INT16_C( 19471) };
  static const int16_t b[] =
    { -INT16_C(  1693), -INT16_C( 21441),  INT16_C(  9653),  INT16_C( 23624), -INT16_C( 15162), -INT16_C( 13970), -INT16_C( 23903),  INT16_C( 16656),
      -INT16_C( 20468),  INT16_C( 23139), -INT16_C(  7875),  INT16_C( 11999),  INT16_C( 28052), -INT16_C( 32224), -INT16_C(  7113), -INT16_C( 25999),
      -INT16_C( 20259), -INT16_C( 27833), -INT16_C( 28714), -INT16_C( 25361),  INT16_C( 23891), -INT16_C(  2971),  INT16_C( 30207),  INT16_C(  3125),
      -INT16_C( 26587),  INT16_C( 25190),  INT16_C( 17785),  INT16_C(  3728), -INT16_C( 20302), -INT16_C(  5488),  INT16_C(   405),  INT16_C( 29316),
      -INT16_C( 13390), -INT16_C( 30715), -INT16_C(  2982), -INT16_C( 21212), -INT16_C( 30382),  INT16_C( 20897), -INT16_C( 10242),  INT16_C(  9053),
      -INT16_C( 15505), -INT16_C(  5754),  INT16_C(  5641), -INT16_C( 17417), -INT16_C( 30777),  INT16_C( 23717),  INT16_C( 10889),  INT16_C( 15310),
      -INT16_C( 11019),  INT16_C( 20675), -INT16_C(  6200),  INT16_C(  6909), -INT16_C( 24720),  INT16_C( 28268), -INT16_C( 13962), -INT16_C(  6767),
       INT16_C(  6029), -INT16_C( 26930), -INT16_C( 15058), -INT16_C(  2735), -INT16_C(  2227), -INT16_C( 10671),  INT16_C(  7969),  INT16_C(  5649),
      -INT16_C( 11021), -INT16_C( 17306),  INT16_C( 25787),  INT16_C( 11222),  INT16_C( 16899),  INT16_C( 31129),  INT16_C( 10764), -INT16_C( 26274),
       INT16_C( 11586),  INT16_C( 28719), -INT16_C( 32526),  INT16_C( 16229), -INT16_C( 18825), -INT16_C( 26603),  INT16_C(  9941), -INT16_C( 13905),
       INT16_C(  5626), -INT16_C( 19067),  INT16_C( 23417),  INT16_C( 31968),  INT16_C( 31134), -INT16_C( 21771),  INT16_C( 21668), -INT16_C(  6589),
       INT16_C( 29313),  INT16_C( 29526), -INT16_C( 17422),  INT16_C( 27315), -INT16_C( 14223),  INT16_C( 17922), -INT16_C( 19985), -INT16_C(  5873),
      -INT16_C( 27449),  INT16_C( 16543),  INT16_C( 32752), -INT16_C( 28995), -INT16_C( 19719), -INT16_C( 25288),  INT16_C( 31494), -INT16_C( 30845),
      -INT16_C(  9747), -INT16_C(  8197), -INT16_C( 20844),  INT16_C(  1353),  INT16_C( 19574),  INT16_C( 25931),  INT16_C( 23549), -INT16_C( 15281),
      -INT16_C(  4369), -INT16_C(  8443), -INT16_C( 15763),  INT16_C( 26221), -INT16_C( 23180),  INT16_C( 31491), -INT16_C( 31200),  INT16_C(  3330),
      -INT16_C(   673), -INT16_C(  3091),  INT16_C( 13995),  INT16_C(  8952),  INT16_C( 17538), -INT16_C( 32633), -INT16_C( 10593), -INT16_C( 29116),
       INT16_C( 18884),  INT16_C( 12910), -INT16_C(  9461), -INT16_C( 32616), -INT16_C( 25471), -INT16_C( 24069), -INT16_C(   734), -INT16_C( 32081),
      -INT16_C( 25349), -INT16_C( 22923),  INT16_C( 28370),  INT16_C( 21960),  INT16_C( 20658),  INT16_C( 20949),  INT16_C(  6438), -INT16_C(  5153),
       INT16_C( 19811),  INT16_C( 28189), -INT16_C( 19159), -INT16_C( 21778), -INT16_C(  5807),  INT16_C( 29771), -INT16_C(  1305), -INT16_C(  7434),
       INT16_C( 27542),  INT16_C( 27016),  INT16_C( 20953), -INT16_C( 29762), -INT16_C( 27743), -INT16_C( 14372), -INT16_C( 17236),  INT16_C(  4018),
      -INT16_C( 12535),  INT16_C( 12926),  INT16_C( 27781), -INT16_C( 10532),  INT16_C( 10326),  INT16_C( 15690),  INT16_C( 16418), -INT16_C( 18145),
      -INT16_C( 22612), -INT16_C( 31454), -INT16_C(  7944), -INT16_C( 26351), -INT16_C(  4749),  INT16_C(  8033),  INT16_C(  5033), -INT16_C( 19665),
      -INT16_C( 21021),  INT16_C( 26853), -INT16_C( 15847),  INT16_C( 28478), -INT16_C( 30230),  INT16_C(  3244), -INT16_C( 13367),  INT16_C( 30149),
      -INT16_C(  6285),  INT16_C( 27643),  INT16_C(  3271),  INT16_C( 14853),  INT16_C( 26361), -INT16_C( 23718), -INT16_C( 30343),  INT16_C( 23638),
       INT16_C( 15158),  INT16_C( 20420),  INT16_C(  1021), -INT16_C(  6209),  INT16_C( 27532),  INT16_C( 22004), -INT16_C( 18121), -INT16_C( 21813),
      -INT16_C( 14687),  INT16_C( 26645),  INT16_C(  6866), -INT16_C( 13405), -INT16_C(   640), -INT16_C(  1426), -INT16_C( 15226), -INT16_C( 17322),
       INT16_C(  6912), -INT16_C(   757), -INT16_C( 13794), -INT16_C( 21787), -INT16_C(  9930),  INT16_C( 28159), -INT16_C( 13678),  INT16_C( 13079),
       INT16_C( 11408),  INT16_C( 25244),  INT16_C( 16199), -INT16_C( 14546), -INT16_C( 25540), -INT16_C( 15679),  INT16_C(  6241),  INT16_C( 24958),
      -INT16_C( 30413),  INT16_C( 20830),  INT16_C( 17236), -INT16_C( 29957), -INT16_C(  1508), -INT16_C( 20489),  INT16_C(  3781),  INT16_C( 21986),
       INT16_C( 32314), -INT16_C( 32328), -INT16_C(  6467), -INT16_C(  1719),  INT16_C(  2690), -INT16_C(  7237),  INT16_C( 14626),  INT16_C( 21828),
      -INT16_C( 23613),  INT16_C(  6054), -INT16_C( 24090),  INT16_C(   929), -INT16_C( 26468),  INT16_C( 25010), -INT16_C( 27482), -INT16_C(  8010),
       INT16_C( 28179), -INT16_C( 12190), -INT16_C( 21676), -INT16_C( 10294), -INT16_C( 31307), -INT16_C( 10054), -INT16_C(    65), -INT16_C( 32211),
      -INT16_C( 11102), -INT16_C( 30567),  INT16_C( 14965),  INT16_C(  4491),  INT16_C( 15826),  INT16_C( 30834),  INT16_C( 10706), -INT16_C(  6824),
      -INT16_C( 17769), -INT16_C(  4939),  INT16_C( 32613),  INT16_C(  7107),  INT16_C( 32005), -INT16_C( 15117),  INT16_C(  8316),  INT16_C(  7750),
      -INT16_C(  8204),  INT16_C( 27303),  INT16_C( 12825), -INT16_C(  5253), -INT16_C(  4496),  INT16_C( 16995), -INT16_C( 17641), -INT16_C( 20953),
      -INT16_C(  9098), -INT16_C(  9318),  INT16_C( 23900),  INT16_C( 25078), -INT16_C(  5669),  INT16_C( 22309),  INT16_C( 27402), -INT16_C(   394),
       INT16_C(  7498),  INT16_C( 25448), -INT16_C(  7089), -INT16_C( 16562), -INT16_C( 20014), -INT16_C(  5887),  INT16_C( 10348), -INT16_C(  7529),
       INT16_C( 12805),  INT16_C( 25022), -INT16_C( 19313),  INT16_C( 27330), -INT16_C(  6242), -INT16_C( 22334),  INT16_C( 14418), -INT16_C( 25434),
       INT16_C(  3925), -INT16_C( 23297),  INT16_C( 19955), -INT16_C( 15004),  INT16_C( 26110),  INT16_C( 27310),  INT16_C( 17806), -INT16_C( 27827),
       INT16_C(  2935),  INT16_C(  2036), -INT16_C( 18753),  INT16_C( 23921),  INT16_C( 13213), -INT16_C(  4347), -INT16_C( 21397), -INT16_C( 16245),
      -INT16_C( 30021), -INT16_C( 20891), -INT16_C( 13865), -INT16_C( 10893),  INT16_C(  8494), -INT16_C( 17345), -INT16_C( 29594), -INT16_C(  8625),
       INT16_C( 17303),  INT16_C( 22501),  INT16_C( 22265), -INT16_C( 26956), -INT16_C( 17782), -INT16_C(  2683),  INT16_C(  4198),  INT16_C(  8630),
       INT16_C(  7066),  INT16_C( 29135),  INT16_C( 17124),  INT16_C(  4678), -INT16_C( 31133), -INT16_C( 13873),  INT16_C(  7698), -INT16_C( 21849),
      -INT16_C( 29598),  INT16_C( 23297), -INT16_C( 18973),  INT16_C( 28146),  INT16_C( 30575), -INT16_C( 10910),  INT16_C(  6280),  INT16_C(  8950),
      -INT16_C( 15053),  INT16_C(  6036), -INT16_C(  9721),  INT16_C( 27178), -INT16_C(  1696),  INT16_C( 29492), -INT16_C(  9449),  INT16_C( 31005),
       INT16_C(  7784),  INT16_C( 19413), -INT16_C( 14381),  INT16_C( 17336),  INT16_C(  6718), -INT16_C( 14824),  INT16_C(  3891),  INT16_C( 26345),
       INT16_C( 32212), -INT16_C(  9090), -INT16_C( 22441), -INT16_C( 18362),  INT16_C( 31393), -INT16_C( 18389),  INT16_C( 18518), -INT16_C( 16846),
       INT16_C(  1894),  INT16_C( 14601), -INT16_C( 15922),  INT16_C(  3196), -INT16_C( 27173),  INT16_C(  3795), -INT16_C( 17244),  INT16_C( 30837),
      -INT16_C(  3271), -INT16_C( 28588), -INT16_C( 25701),  INT16_C( 15432),  INT16_C( 29461),  INT16_C( 27636),  INT16_C(  9915),  INT16_C(  8489),
       INT16_C( 12845), -INT16_C(  1189), -INT16_C( 10253), -INT16_C( 12536), -INT16_C(  9364),  INT16_C(  4317),  INT16_C( 21143), -INT16_C( 12151),
      -INT16_C(  8891), -INT16_C(  8096), -INT16_C( 22152), -INT16_C( 29156),  INT16_C(  4380), -INT16_C(  9991),  INT16_C(  9015),  INT16_C( 26105),
       INT16_C( 21589),  INT16_C( 18784),  INT16_C( 26668), -INT16_C( 26600), -INT16_C(  2749), -INT16_C(  9559),  INT16_C( 12872), -INT16_C( 29270),
       INT16_C(  2831), -INT16_C( 30610), -INT16_C( 30028), -INT16_C( 12266),  INT16_C(  3995), -INT16_C( 11352), -INT16_C( 24014), -INT16_C( 30664),
      -INT16_C( 26378),  INT16_C(  8913), -INT16_C(  5887),  INT16_C( 17595),  INT16_C( 25822),  INT16_C(  9759), -INT16_C( 13930), -INT16_C( 23116),
       INT16_C(  8916), -INT16_C( 30675),  INT16_C( 17324),  INT16_C( 18521),  INT16_C(   339), -INT16_C( 31461),  INT16_C( 21411), -INT16_C( 26099),
      -INT16_C(  8469), -INT16_C(  4932),  INT16_C( 30663), -INT16_C( 22991),  INT16_C( 20699),  INT16_C( 29132), -INT16_C( 32743), -INT16_C(  4585),
       INT16_C( 17570),  INT16_C( 20342), -INT16_C( 12408), -INT16_C(  9321), -INT16_C( 19759),  INT16_C( 29792),  INT16_C( 28165), -INT16_C(  4082),
      -INT16_C( 13492),  INT16_C(  5341),  INT16_C(  3650),  INT16_C(  7866), -INT16_C( 31138),  INT16_C( 30607), -INT16_C( 23033), -INT16_C( 22171),
      -INT16_C(  8981),  INT16_C( 29688), -INT16_C( 28757),  INT16_C( 31822), -INT16_C( 20927),  INT16_C( 18161), -INT16_C(   228),  INT16_C( 26935),
       INT16_C(  5322),  INT16_C(  3453),  INT16_C( 14114), -INT16_C( 32725), -INT16_C( 17731), -INT16_C( 15113),  INT16_C( 23905),  INT16_C( 19566),
       INT16_C( 26169), -INT16_C(  6977),  INT16_C(  3574),  INT16_C( 14177),  INT16_C( 21179), -INT16_C( 10114), -INT16_C( 19119),  INT16_C(  7233),
      -INT16_C( 16695), -INT16_C(  5335),  INT16_C( 21749), -INT16_C( 19861),  INT16_C( 25102),  INT16_C( 28535), -INT16_C(  6721), -INT16_C(  1861),
       INT16_C( 31307),  INT16_C( 16861),  INT16_C( 16007),  INT16_C( 17273), -INT16_C(  2160), -INT16_C(  7909),  INT16_C( 23724),  INT16_C( 30205),
       INT16_C(  9754),  INT16_C(  3936), -INT16_C( 13446), -INT16_C( 30271),  INT16_C( 14381) };
  static const int16_t e[] =
    { -INT16_C( 18958),  INT16_C(     0),  INT16_C(     0), -INT16_C( 21105),  INT16_C( 28031),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 10196),  INT16_C(     0),  INT16_C( 12252), -INT16_C( 12903),
       INT16_C( 21735),  INT16_C(     0),  INT16_C( 12542),  INT16_C(     0),  INT16_C(  2463), -INT16_C( 16256),  INT16_C( 30502), -INT16_C(   239),
       INT16_C(     0), -INT16_C(  4482), -INT16_C( 14254),  INT16_C(     0), -INT16_C( 19727), -INT16_C( 13450),  INT16_C(     0), -INT16_C( 14181),
       INT16_C(     0),  INT16_C(     0), -INT16_C( 31379),  INT16_C(     0),  INT16_C(     0), -INT16_C( 19763),  INT16_C(     0),  INT16_C(     0),
       INT16_C( 12436), -INT16_C(  6684),  INT16_C(     0), -INT16_C(  6133),  INT16_C(     0),  INT16_C(  6582),  INT16_C( 20369),  INT16_C(     0),
       INT16_C(     0), -INT16_C(  1961),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C( 18394), -INT16_C( 11734),  INT16_C( 14028),  INT16_C(   956),  INT16_C( 28855),  INT16_C(     0),  INT16_C(   449),  INT16_C( 19773),
       INT16_C(     0), -INT16_C(  5306),  INT16_C( 19146),  INT16_C( 24112),  INT16_C( 10270), -INT16_C( 12852),  INT16_C( 12497),  INT16_C(     0),
       INT16_C( 15479),  INT16_C( 17533),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 21145),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 20938),  INT16_C( 18023), -INT16_C(  8358),
      -INT16_C( 10621), -INT16_C(  2781),  INT16_C( 27153),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  8901),  INT16_C( 32211),
       INT16_C(     0),  INT16_C(  9352),  INT16_C(     0), -INT16_C(  4724),  INT16_C(     0),  INT16_C(     0), -INT16_C(  2294),  INT16_C(     0),
      -INT16_C( 27698),  INT16_C(     0), -INT16_C( 24833), -INT16_C( 12134), -INT16_C( 16594),  INT16_C( 26889),  INT16_C(     0),  INT16_C(     0),
       INT16_C( 27957),  INT16_C(     0),  INT16_C( 10594),  INT16_C(     0), -INT16_C( 12308), -INT16_C(  2784), -INT16_C( 28217),  INT16_C(     0),
       INT16_C(  1062),  INT16_C(     0),  INT16_C(  3492),  INT16_C(     0), -INT16_C(   563),  INT16_C(     0),  INT16_C(  8153),  INT16_C(  3810),
       INT16_C(     0), -INT16_C(  4013),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  7560),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C( 27958),  INT16_C(   387),  INT16_C(     0),  INT16_C( 17516),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 28553), -INT16_C( 23390),  INT16_C( 21658), -INT16_C( 22280),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 19124),  INT16_C(  8091),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  8123), -INT16_C(  8140),  INT16_C( 11317), -INT16_C( 20087),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24005),  INT16_C(     0), -INT16_C( 22827),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 29192),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11364), -INT16_C( 11926),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(  6442), -INT16_C( 26600),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 27613), -INT16_C( 16765),  INT16_C( 31537),
       INT16_C(     0), -INT16_C( 28532),  INT16_C( 11117),  INT16_C(  2330), -INT16_C( 31743),  INT16_C(   474),  INT16_C( 24182),  INT16_C( 19358),
      -INT16_C( 18876),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 10292),  INT16_C( 25877),  INT16_C( 24995),
       INT16_C( 12053),  INT16_C(     0),  INT16_C(     0),  INT16_C( 23434),  INT16_C(     0),  INT16_C(  1118),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C( 18249), -INT16_C( 15855),  INT16_C(     0),  INT16_C(     0),  INT16_C( 11743), -INT16_C( 32602), -INT16_C( 17776),
       INT16_C(     0),  INT16_C(  3133), -INT16_C( 14194),  INT16_C(     0), -INT16_C( 14547), -INT16_C(  4573),  INT16_C( 29891),  INT16_C( 30198),
       INT16_C(     0), -INT16_C( 16963), -INT16_C( 13567),  INT16_C(     0),  INT16_C( 21261),  INT16_C(     0), -INT16_C(  9772), -INT16_C( 31377),
       INT16_C(     0),  INT16_C(     0), -INT16_C(  1933),  INT16_C(     0),  INT16_C( 10431), -INT16_C( 32370), -INT16_C( 31842),  INT16_C(     0),
      -INT16_C( 18750), -INT16_C( 15352),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 20992),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  1420),  INT16_C(     0), -INT16_C(  5505),  INT16_C(     0),
       INT16_C( 25761),  INT16_C(  8453),  INT16_C(     0), -INT16_C( 20818), -INT16_C(  4598),  INT16_C(  2386),  INT16_C( 30877), -INT16_C(  2203),
      -INT16_C( 22479), -INT16_C(  7997),  INT16_C( 12275),  INT16_C( 26449),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(  7408),  INT16_C(     0), -INT16_C(  9011),  INT16_C(     0),  INT16_C( 10471),  INT16_C( 19607),  INT16_C(     0),
      -INT16_C(  7691), -INT16_C(  5975),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11614),  INT16_C(     0),
       INT16_C( 11203), -INT16_C( 26886), -INT16_C( 14647),  INT16_C(     0),  INT16_C(     0),  INT16_C( 31869),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(  4481),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 18782),  INT16_C(     0), -INT16_C( 13175),  INT16_C( 19745),
       INT16_C(     0), -INT16_C( 16412),  INT16_C( 22499),  INT16_C(     0),  INT16_C(     0),  INT16_C( 23877),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C( 24640),  INT16_C(     0), -INT16_C(  1147),  INT16_C(  6086),  INT16_C(     0),  INT16_C( 24548), -INT16_C(  9316),
       INT16_C(     0),  INT16_C( 23963),  INT16_C(     0),  INT16_C(     0),  INT16_C( 27460),  INT16_C(     0), -INT16_C(  6923),  INT16_C(     0),
       INT16_C(     0), -INT16_C( 16179),  INT16_C( 20849),  INT16_C(     0), -INT16_C(  1175),  INT16_C(     0),  INT16_C(     0), -INT16_C( 10712),
      -INT16_C( 15455),  INT16_C(     0),  INT16_C( 23156),  INT16_C(     0),  INT16_C(     0), -INT16_C( 17620),  INT16_C( 19926),  INT16_C( 15400),
      -INT16_C(  2640),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  9035),  INT16_C(  3837),  INT16_C(  9727), -INT16_C( 24602),
       INT16_C(  6633),  INT16_C( 23834),  INT16_C(  8309),  INT16_C(     0),  INT16_C(     0), -INT16_C(  6155),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C( 18468),  INT16_C(     0),  INT16_C(     0), -INT16_C( 27488), -INT16_C( 31189),  INT16_C(     0),
       INT16_C( 19872),  INT16_C(     0), -INT16_C( 30865),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C( 11597),  INT16_C( 18717), -INT16_C( 16935),  INT16_C(  1245),  INT16_C(  4419),  INT16_C(     0),
      -INT16_C( 29857), -INT16_C( 12807),  INT16_C( 18451), -INT16_C(  8881), -INT16_C( 18290),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C( 11468), -INT16_C( 32637), -INT16_C( 24576),  INT16_C(     0),  INT16_C(     0), -INT16_C( 24611), -INT16_C(  2377),  INT16_C(  5252),
       INT16_C( 32129),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 22549),  INT16_C(     0), -INT16_C( 23175),  INT16_C( 17703),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 30925),  INT16_C(     0), -INT16_C( 13699),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 23893),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C( 19179), -INT16_C( 27718), -INT16_C(  5135),  INT16_C(     0), -INT16_C( 26667),  INT16_C(     0),  INT16_C( 19093),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11319),  INT16_C(     0), -INT16_C( 24073),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 23156),  INT16_C( 17819),  INT16_C(     0),  INT16_C( 21554),  INT16_C(     0), -INT16_C( 14357),  INT16_C( 32732), -INT16_C( 28142),
       INT16_C(     0), -INT16_C( 12964),  INT16_C(  9759),  INT16_C( 30625), -INT16_C( 26593),  INT16_C(     0),  INT16_C(     0), -INT16_C( 32065),
       INT16_C( 22650), -INT16_C( 19767), -INT16_C(  1307), -INT16_C( 22009), -INT16_C(  3325), -INT16_C(  8591),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 13077),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 25826),  INT16_C(     0),  INT16_C(     0), -INT16_C(  5993),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C( 29044), -INT16_C( 21887),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  9854),
       INT16_C(  7605),  INT16_C(  3927),  INT16_C( 32194),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 32681),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C( 16173),  INT16_C(     0),  INT16_C( 31684) };

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
    rv = simde_svsub_s16_z(pv, av, bv);

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

    ev = simde_svsub_s16_z(pv, av, bv);

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
test_simde_svsub_s16_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) };
  static const int16_t a[] =
    {  INT16_C( 17804), -INT16_C( 26224),  INT16_C(  5372), -INT16_C( 29341),  INT16_C(  4003), -INT16_C( 26673), -INT16_C( 29073), -INT16_C( 28099),
       INT16_C( 30058),  INT16_C(  6974), -INT16_C( 31097),  INT16_C( 25925), -INT16_C(  6298), -INT16_C( 27298),  INT16_C(  5337),  INT16_C( 26081),
       INT16_C( 29018),  INT16_C( 22271),  INT16_C( 25222),  INT16_C( 10723), -INT16_C( 19855), -INT16_C(  8000), -INT16_C(   704), -INT16_C( 21902),
      -INT16_C( 20109), -INT16_C(  1339),  INT16_C(  2615), -INT16_C( 25248), -INT16_C( 16654), -INT16_C( 13518),  INT16_C(  5075),  INT16_C( 11568),
       INT16_C( 12165),  INT16_C(  2947),  INT16_C( 26257),  INT16_C(   820), -INT16_C(  2792),  INT16_C( 22755),  INT16_C( 22258),  INT16_C( 25858),
      -INT16_C( 14585),  INT16_C( 15968), -INT16_C( 16175), -INT16_C( 15397),  INT16_C(  3454),  INT16_C( 20878), -INT16_C( 16608), -INT16_C( 23170),
       INT16_C(   494), -INT16_C( 32592), -INT16_C(  6809),  INT16_C( 32643),  INT16_C( 26330), -INT16_C( 13097), -INT16_C(  9796), -INT16_C( 15566),
      -INT16_C( 28000),  INT16_C( 29185), -INT16_C(  9134), -INT16_C( 12235), -INT16_C( 15127),  INT16_C(  2594), -INT16_C( 24445),  INT16_C( 29103),
       INT16_C( 24738),  INT16_C(  2545),  INT16_C( 29765),  INT16_C(  8073),  INT16_C( 24795), -INT16_C( 26645),  INT16_C(  7482), -INT16_C(  9637),
       INT16_C( 23727),  INT16_C(   332), -INT16_C( 32199),  INT16_C(  8914), -INT16_C(  3002), -INT16_C( 14036), -INT16_C(  9068),  INT16_C( 13882),
       INT16_C( 11324), -INT16_C( 32448), -INT16_C( 13920),  INT16_C( 31648), -INT16_C( 29911),  INT16_C( 25363),  INT16_C( 28329),  INT16_C( 22590),
      -INT16_C( 30006),  INT16_C(   858),  INT16_C( 11276),  INT16_C( 21030),  INT16_C( 21024), -INT16_C( 19429),  INT16_C( 22062),  INT16_C( 27371),
       INT16_C( 11138),  INT16_C(  8939), -INT16_C( 29708),  INT16_C(  7582), -INT16_C( 20201), -INT16_C( 16255), -INT16_C( 16609), -INT16_C(  5864),
       INT16_C( 29257),  INT16_C( 22253),  INT16_C(  5022), -INT16_C( 16728), -INT16_C( 15259), -INT16_C( 27533),  INT16_C( 24090), -INT16_C( 25346),
      -INT16_C(  5495),  INT16_C( 32190),  INT16_C( 23669), -INT16_C( 29542),  INT16_C(  6925),  INT16_C( 11340),  INT16_C( 26074),  INT16_C(  9238),
       INT16_C(   983),  INT16_C( 30330),  INT16_C(  8726),  INT16_C( 31540), -INT16_C( 22554),  INT16_C(    15),  INT16_C(  3589), -INT16_C( 29028),
       INT16_C( 23544),  INT16_C( 27915), -INT16_C( 22857), -INT16_C( 14854),  INT16_C( 18113), -INT16_C( 25359),  INT16_C(  1963), -INT16_C( 31808),
       INT16_C( 14858),  INT16_C(  8441),  INT16_C( 11612),  INT16_C( 17308), -INT16_C( 21547), -INT16_C(  9661), -INT16_C(  8007), -INT16_C( 20119),
       INT16_C( 29755), -INT16_C(  3553),  INT16_C(  6426), -INT16_C(  9033), -INT16_C( 22177),  INT16_C(  2936),  INT16_C( 14512), -INT16_C( 17522),
      -INT16_C( 30862), -INT16_C( 12581),  INT16_C( 30644), -INT16_C( 30447),  INT16_C( 21795), -INT16_C(  9116), -INT16_C( 13003),  INT16_C( 28814),
      -INT16_C( 21183),  INT16_C( 23650),  INT16_C(  6854),  INT16_C(  9528), -INT16_C( 20285),  INT16_C( 29488), -INT16_C( 16664),  INT16_C( 23086),
       INT16_C(  2629), -INT16_C(  1496),  INT16_C( 14977), -INT16_C( 23421), -INT16_C(  6257), -INT16_C( 15231),  INT16_C(  4020), -INT16_C(  2508),
      -INT16_C( 26948), -INT16_C( 32174), -INT16_C( 30032),  INT16_C( 29607), -INT16_C( 10182),  INT16_C(  8935),  INT16_C(  5526), -INT16_C(  9092),
      -INT16_C( 23521), -INT16_C( 24106),  INT16_C( 23006),  INT16_C( 27973), -INT16_C( 14783), -INT16_C(  2767),  INT16_C( 26069), -INT16_C( 28181),
       INT16_C( 15868), -INT16_C( 21485), -INT16_C( 17465),  INT16_C(   288),  INT16_C(  1939),  INT16_C( 10531), -INT16_C( 24804),  INT16_C( 15365),
      -INT16_C(  9404),  INT16_C(  8925),  INT16_C(  8757),  INT16_C( 30352), -INT16_C( 15895), -INT16_C( 16789),  INT16_C( 22311),  INT16_C(  9040),
       INT16_C( 25492),  INT16_C( 23759), -INT16_C(  4322), -INT16_C( 20131), -INT16_C( 32266),  INT16_C(  5083), -INT16_C(  8160),  INT16_C( 25679),
       INT16_C( 11452), -INT16_C(  3705),  INT16_C(  5966),  INT16_C( 14183), -INT16_C( 11560), -INT16_C(    10),  INT16_C( 17961), -INT16_C( 16862),
      -INT16_C(  3415), -INT16_C( 14310),  INT16_C( 30689), -INT16_C( 10119),  INT16_C( 21752),  INT16_C(  6635),  INT16_C( 14901), -INT16_C(  3715),
       INT16_C(  1126), -INT16_C( 19230),  INT16_C( 18715), -INT16_C(  2836), -INT16_C(  7653),  INT16_C( 17907),  INT16_C(  5672), -INT16_C( 12029),
       INT16_C(  7432), -INT16_C(  5735),  INT16_C(  5012), -INT16_C( 29247), -INT16_C( 21401), -INT16_C( 25434),  INT16_C(  9190),  INT16_C( 19597),
       INT16_C( 28456),  INT16_C( 17153), -INT16_C(  4680), -INT16_C( 11209),  INT16_C( 11215), -INT16_C(  2279),  INT16_C(  7233),  INT16_C( 18888),
       INT16_C( 25145), -INT16_C( 13006), -INT16_C(  2955), -INT16_C(  9126),  INT16_C(   160), -INT16_C( 30855),  INT16_C(  1572),  INT16_C( 19667),
      -INT16_C( 11146),  INT16_C( 11919), -INT16_C( 14399), -INT16_C( 28670),  INT16_C(  7154),  INT16_C( 13191),  INT16_C( 20535),  INT16_C( 28796),
      -INT16_C( 20814),  INT16_C( 10046), -INT16_C( 26462),  INT16_C( 17155),  INT16_C( 31897), -INT16_C( 16950), -INT16_C( 25213), -INT16_C(  1783),
      -INT16_C( 26510),  INT16_C( 13095),  INT16_C( 10847),  INT16_C( 20932),  INT16_C( 19269),  INT16_C( 32132),  INT16_C(   155),  INT16_C( 19949),
       INT16_C( 11183),  INT16_C( 20852),  INT16_C( 30916),  INT16_C( 23956),  INT16_C( 24308),  INT16_C( 30490),  INT16_C(  9212),  INT16_C( 28272),
      -INT16_C( 26437),  INT16_C(  7073),  INT16_C( 26050),  INT16_C(  1900), -INT16_C(  3663),  INT16_C( 19588) };
  static const int16_t b[] =
    {  INT16_C( 14905), -INT16_C( 14048), -INT16_C( 10595), -INT16_C(  5646),  INT16_C( 16526),  INT16_C( 28457), -INT16_C(   981), -INT16_C(  1378),
       INT16_C( 18732),  INT16_C(  9064), -INT16_C( 21977), -INT16_C( 27487),  INT16_C(  4033), -INT16_C(  8522), -INT16_C(   601), -INT16_C(  7964),
       INT16_C(  1335), -INT16_C( 11095), -INT16_C( 25637),  INT16_C( 27069), -INT16_C(  6180),  INT16_C(  2009),  INT16_C( 30691),  INT16_C(  3841),
       INT16_C( 27072), -INT16_C(  6349), -INT16_C( 11244), -INT16_C( 10885),  INT16_C( 13027), -INT16_C( 29773), -INT16_C( 26577),  INT16_C( 26475),
       INT16_C(  5533),  INT16_C( 30779), -INT16_C(  1616), -INT16_C( 29470), -INT16_C( 17440), -INT16_C( 15468), -INT16_C( 27342), -INT16_C(  3374),
       INT16_C(  1535),  INT16_C(  5081),  INT16_C( 21978), -INT16_C( 16920), -INT16_C( 25721), -INT16_C( 18872), -INT16_C( 19405), -INT16_C( 12259),
       INT16_C( 22985),  INT16_C( 31049),  INT16_C( 11090),  INT16_C( 12806), -INT16_C( 25882),  INT16_C(  6389), -INT16_C( 14545),  INT16_C( 11786),
      -INT16_C(  7219), -INT16_C( 22719),  INT16_C( 10552), -INT16_C( 16540), -INT16_C( 21051), -INT16_C(  1930), -INT16_C( 27807),  INT16_C( 10953),
       INT16_C(  4844),  INT16_C( 16035), -INT16_C( 22211),  INT16_C(  9072),  INT16_C( 25923),  INT16_C( 29499),  INT16_C( 17709), -INT16_C(  1375),
      -INT16_C(  7384),  INT16_C( 24993),  INT16_C(  1292), -INT16_C( 12000), -INT16_C( 26958),  INT16_C(  5066), -INT16_C( 27862),  INT16_C(  5693),
      -INT16_C(  7771), -INT16_C(  7595), -INT16_C( 14966), -INT16_C( 12795),  INT16_C( 16427),  INT16_C( 22593), -INT16_C(  7547), -INT16_C( 21166),
      -INT16_C(  3131), -INT16_C( 11762),  INT16_C( 12280), -INT16_C( 21597),  INT16_C( 28101), -INT16_C(  4162), -INT16_C(  1024), -INT16_C( 23290),
       INT16_C( 23517),  INT16_C( 26503), -INT16_C( 29664),  INT16_C( 19253),  INT16_C( 30412),  INT16_C( 20899), -INT16_C(  2727),  INT16_C(  7935),
       INT16_C(  3560), -INT16_C(  7696), -INT16_C( 27588),  INT16_C(   652),  INT16_C( 18945),  INT16_C(   753), -INT16_C(  2234),  INT16_C(  9127),
       INT16_C( 12114),  INT16_C( 29579), -INT16_C( 16197), -INT16_C( 30530),  INT16_C( 25143), -INT16_C( 28455), -INT16_C( 10153),  INT16_C( 16558),
      -INT16_C( 24602),  INT16_C(  8737), -INT16_C( 21197),  INT16_C( 13348),  INT16_C(  5879),  INT16_C( 15926), -INT16_C(  8691),  INT16_C( 24673),
      -INT16_C(  5107), -INT16_C( 14125), -INT16_C( 28243), -INT16_C(  7088),  INT16_C( 10995),  INT16_C( 19316),  INT16_C(  8706), -INT16_C(  6005),
      -INT16_C( 21311), -INT16_C(  3061),  INT16_C( 12121),  INT16_C( 20521),  INT16_C( 24389),  INT16_C( 21390), -INT16_C(  4035),  INT16_C( 19123),
      -INT16_C( 31012), -INT16_C( 30445),  INT16_C( 25367),  INT16_C(  2925), -INT16_C(  7795), -INT16_C( 28586), -INT16_C(  7932), -INT16_C( 14984),
      -INT16_C( 31859), -INT16_C(  6470), -INT16_C(  7245), -INT16_C(  1994), -INT16_C( 15038), -INT16_C( 32693), -INT16_C(   331), -INT16_C( 28214),
      -INT16_C(  8828), -INT16_C( 25573), -INT16_C( 30655), -INT16_C( 12633), -INT16_C(   662),  INT16_C( 28254), -INT16_C( 10274),  INT16_C( 27443),
      -INT16_C(  4774),  INT16_C(  3409), -INT16_C( 30768),  INT16_C(  4870),  INT16_C( 20812),  INT16_C(   403),  INT16_C( 23888), -INT16_C( 11117),
      -INT16_C( 20933),  INT16_C( 31856),  INT16_C(  5942), -INT16_C( 24502), -INT16_C( 22252), -INT16_C(  3570),  INT16_C( 17024), -INT16_C(  9635),
      -INT16_C( 20945),  INT16_C(   232), -INT16_C(  4554), -INT16_C( 32237), -INT16_C( 22977), -INT16_C( 28796),  INT16_C(  5891),  INT16_C( 15972),
      -INT16_C( 11067), -INT16_C(  1094),  INT16_C(  1516),  INT16_C(   156), -INT16_C( 21842),  INT16_C( 12019),  INT16_C( 20716),  INT16_C(  7176),
      -INT16_C(  3841),  INT16_C( 13596),  INT16_C( 12254),  INT16_C(  7863),  INT16_C( 15317), -INT16_C( 10067),  INT16_C(  4434),  INT16_C(  5911),
      -INT16_C( 11802), -INT16_C( 11757), -INT16_C( 20522), -INT16_C( 31534), -INT16_C( 15015),  INT16_C( 18098), -INT16_C( 17642),  INT16_C(  5474),
       INT16_C( 32427), -INT16_C( 30134),  INT16_C(   429), -INT16_C( 32088),  INT16_C( 21821), -INT16_C( 28838),  INT16_C( 29031),  INT16_C( 19879),
      -INT16_C( 17853),  INT16_C(  6431), -INT16_C(  3735), -INT16_C( 15714),  INT16_C( 20663), -INT16_C( 13048),  INT16_C( 27147), -INT16_C( 18462),
       INT16_C( 11496), -INT16_C( 27327), -INT16_C(  5843),  INT16_C( 27159),  INT16_C( 29246), -INT16_C( 23046), -INT16_C( 24093),  INT16_C(  9970),
       INT16_C(  4443), -INT16_C( 15296), -INT16_C(  8701), -INT16_C( 17786), -INT16_C( 28882),  INT16_C( 14983),  INT16_C( 27129), -INT16_C(  7439),
       INT16_C( 12949), -INT16_C( 15753), -INT16_C( 28901),  INT16_C( 22829),  INT16_C(  9985), -INT16_C(  6913), -INT16_C(  3640),  INT16_C(  8971),
       INT16_C( 19203),  INT16_C(  1767),  INT16_C( 27945),  INT16_C( 22464),  INT16_C( 18428), -INT16_C(  2415), -INT16_C( 32080),  INT16_C( 17880),
       INT16_C( 20404), -INT16_C( 12537),  INT16_C( 13534), -INT16_C(  8407),  INT16_C( 10331),  INT16_C(  9156), -INT16_C( 12519),  INT16_C(  7238),
       INT16_C( 11546),  INT16_C( 17186), -INT16_C(  7525), -INT16_C( 26726),  INT16_C( 11305), -INT16_C(  9843),  INT16_C( 26030),  INT16_C( 25374),
       INT16_C(  9909), -INT16_C( 27854),  INT16_C( 23386), -INT16_C( 18829),  INT16_C( 14211), -INT16_C( 25127),  INT16_C(  8198),  INT16_C(  8377),
      -INT16_C(  9139), -INT16_C(  6045), -INT16_C(   578), -INT16_C(  6016),  INT16_C(  3369), -INT16_C( 10047), -INT16_C(  8077),  INT16_C( 10299),
       INT16_C( 27910),  INT16_C( 24763),  INT16_C( 11977),  INT16_C( 19478), -INT16_C(  3995),  INT16_C( 27625) };
  static const int16_t e[] =
    {  INT16_C( 17804), -INT16_C( 12176),  INT16_C(  5372), -INT16_C( 23695),  INT16_C(  4003),  INT16_C( 10406), -INT16_C( 28092), -INT16_C( 28099),
       INT16_C( 30058), -INT16_C(  2090), -INT16_C(  9120), -INT16_C( 12124), -INT16_C(  6298), -INT16_C( 27298),  INT16_C(  5938),  INT16_C( 26081),
       INT16_C( 29018),  INT16_C( 22271),  INT16_C( 25222), -INT16_C( 16346), -INT16_C( 19855), -INT16_C(  8000), -INT16_C( 31395), -INT16_C( 21902),
       INT16_C( 18355),  INT16_C(  5010),  INT16_C(  2615), -INT16_C( 14363), -INT16_C( 29681),  INT16_C( 16255),  INT16_C(  5075),  INT16_C( 11568),
       INT16_C(  6632), -INT16_C( 27832),  INT16_C( 27873),  INT16_C(   820),  INT16_C( 14648), -INT16_C( 27313), -INT16_C( 15936),  INT16_C( 25858),
      -INT16_C( 14585),  INT16_C( 15968),  INT16_C( 27383),  INT16_C(  1523),  INT16_C( 29175),  INT16_C( 20878), -INT16_C( 16608), -INT16_C( 10911),
      -INT16_C( 22491),  INT16_C(  1895), -INT16_C( 17899),  INT16_C( 19837),  INT16_C( 26330), -INT16_C( 19486),  INT16_C(  4749), -INT16_C( 27352),
      -INT16_C( 28000),  INT16_C( 29185), -INT16_C( 19686),  INT16_C(  4305),  INT16_C(  5924),  INT16_C(  4524),  INT16_C(  3362),  INT16_C( 29103),
       INT16_C( 24738),  INT16_C(  2545), -INT16_C( 13560), -INT16_C(   999),  INT16_C( 24795), -INT16_C( 26645), -INT16_C( 10227), -INT16_C(  9637),
       INT16_C( 23727), -INT16_C( 24661), -INT16_C( 32199),  INT16_C( 20914),  INT16_C( 23956), -INT16_C( 14036), -INT16_C(  9068),  INT16_C( 13882),
       INT16_C( 19095), -INT16_C( 32448), -INT16_C( 13920), -INT16_C( 21093),  INT16_C( 19198),  INT16_C(  2770),  INT16_C( 28329), -INT16_C( 21780),
      -INT16_C( 26875),  INT16_C( 12620),  INT16_C( 11276), -INT16_C( 22909),  INT16_C( 21024), -INT16_C( 19429),  INT16_C( 22062), -INT16_C( 14875),
      -INT16_C( 12379), -INT16_C( 17564), -INT16_C(    44),  INT16_C(  7582),  INT16_C( 14923),  INT16_C( 28382), -INT16_C( 13882), -INT16_C( 13799),
       INT16_C( 29257),  INT16_C( 22253),  INT16_C( 32610), -INT16_C( 17380),  INT16_C( 31332), -INT16_C( 27533),  INT16_C( 24090),  INT16_C( 31063),
      -INT16_C( 17609),  INT16_C(  2611),  INT16_C( 23669),  INT16_C(   988), -INT16_C( 18218),  INT16_C( 11340), -INT16_C( 29309), -INT16_C(  7320),
       INT16_C(   983),  INT16_C( 21593),  INT16_C( 29923),  INT16_C( 31540), -INT16_C( 28433),  INT16_C(    15),  INT16_C(  3589),  INT16_C( 11835),
       INT16_C( 28651),  INT16_C( 27915),  INT16_C(  5386), -INT16_C( 14854),  INT16_C( 18113),  INT16_C( 20861), -INT16_C(  6743), -INT16_C( 31808),
       INT16_C( 14858),  INT16_C( 11502), -INT16_C(   509), -INT16_C(  3213), -INT16_C( 21547), -INT16_C( 31051), -INT16_C(  8007), -INT16_C( 20119),
       INT16_C( 29755), -INT16_C(  3553), -INT16_C( 18941), -INT16_C(  9033), -INT16_C( 22177),  INT16_C(  2936),  INT16_C( 14512), -INT16_C(  2538),
       INT16_C(   997), -INT16_C(  6111),  INT16_C( 30644), -INT16_C( 30447), -INT16_C( 28703),  INT16_C( 23577), -INT16_C( 13003), -INT16_C(  8508),
      -INT16_C( 12355), -INT16_C( 16313),  INT16_C(  6854),  INT16_C( 22161), -INT16_C( 19623),  INT16_C( 29488), -INT16_C(  6390), -INT16_C(  4357),
       INT16_C(  2629), -INT16_C(  4905), -INT16_C( 19791), -INT16_C( 23421), -INT16_C(  6257), -INT16_C( 15634),  INT16_C(  4020), -INT16_C(  2508),
      -INT16_C( 26948),  INT16_C(  1506), -INT16_C( 30032), -INT16_C( 11427), -INT16_C( 10182),  INT16_C( 12505), -INT16_C( 11498), -INT16_C(  9092),
      -INT16_C( 23521), -INT16_C( 24338),  INT16_C( 23006),  INT16_C( 27973),  INT16_C(  8194), -INT16_C(  2767),  INT16_C( 20178),  INT16_C( 21383),
       INT16_C( 26935), -INT16_C( 20391), -INT16_C( 18981),  INT16_C(   288),  INT16_C( 23781),  INT16_C( 10531), -INT16_C( 24804),  INT16_C( 15365),
      -INT16_C(  9404),  INT16_C(  8925), -INT16_C(  3497),  INT16_C( 30352), -INT16_C( 31212), -INT16_C( 16789),  INT16_C( 17877),  INT16_C(  9040),
       INT16_C( 25492),  INT16_C( 23759),  INT16_C( 16200),  INT16_C( 11403), -INT16_C( 32266), -INT16_C( 13015), -INT16_C(  8160),  INT16_C( 25679),
       INT16_C( 11452), -INT16_C(  3705),  INT16_C(  5966), -INT16_C( 19265),  INT16_C( 32155),  INT16_C( 28828),  INT16_C( 17961),  INT16_C( 28795),
       INT16_C( 14438), -INT16_C( 14310),  INT16_C( 30689), -INT16_C( 10119),  INT16_C( 21752),  INT16_C( 19683), -INT16_C( 12246), -INT16_C(  3715),
       INT16_C(  1126),  INT16_C(  8097),  INT16_C( 18715), -INT16_C( 29995), -INT16_C(  7653),  INT16_C( 17907),  INT16_C( 29765), -INT16_C( 21999),
       INT16_C(  2989), -INT16_C(  5735),  INT16_C(  5012), -INT16_C( 29247), -INT16_C( 21401), -INT16_C( 25434), -INT16_C( 17939),  INT16_C( 19597),
       INT16_C( 28456), -INT16_C( 32630), -INT16_C(  4680), -INT16_C( 11209),  INT16_C( 11215),  INT16_C(  4634),  INT16_C(  7233),  INT16_C(  9917),
       INT16_C(  5942), -INT16_C( 13006), -INT16_C(  2955), -INT16_C( 31590), -INT16_C( 18268), -INT16_C( 30855), -INT16_C( 31884),  INT16_C( 19667),
      -INT16_C( 11146),  INT16_C( 11919), -INT16_C( 27933), -INT16_C( 20263), -INT16_C(  3177),  INT16_C( 13191), -INT16_C( 32482),  INT16_C( 21558),
      -INT16_C( 32360), -INT16_C(  7140), -INT16_C( 26462), -INT16_C( 21655),  INT16_C( 20592), -INT16_C( 16950),  INT16_C( 14293), -INT16_C(  1783),
       INT16_C( 29117),  INT16_C( 13095),  INT16_C( 10847), -INT16_C( 25775),  INT16_C(  5058), -INT16_C(  8277), -INT16_C(  8043),  INT16_C( 11572),
       INT16_C( 20322),  INT16_C( 20852),  INT16_C( 30916),  INT16_C( 29972),  INT16_C( 24308), -INT16_C( 24999),  INT16_C( 17289),  INT16_C( 28272),
       INT16_C( 11189),  INT16_C(  7073),  INT16_C( 26050),  INT16_C(  1900), -INT16_C(  3663),  INT16_C( 19588) };

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
    rv = simde_svsub_s16_m(pv, av, bv);

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

    ev = simde_svsub_s16_m(pv, av, bv);

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
test_simde_svsub_s32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1) };
  static const int32_t a[] =
    {  INT32_C(   626084644), -INT32_C(  2088264226), -INT32_C(   252590378), -INT32_C(  1832735052), -INT32_C(  1475748906), -INT32_C(  1274548958),  INT32_C(   517209199),  INT32_C(   228946409),
      -INT32_C(  1691158852),  INT32_C(  1780398739),  INT32_C(   878317696), -INT32_C(  1798955842),  INT32_C(   440258551),  INT32_C(   751715516),  INT32_C(   692756800), -INT32_C(   818417645),
       INT32_C(  2053794278), -INT32_C(  1545303773),  INT32_C(  1473789593),  INT32_C(  1391173211),  INT32_C(   711731310), -INT32_C(  1403635092), -INT32_C(   271146532),  INT32_C(  2008944017),
      -INT32_C(  1695471242),  INT32_C(  1262343602),  INT32_C(  1872893204),  INT32_C(   583110068),  INT32_C(   575418038),  INT32_C(  1154458472), -INT32_C(   718035644),  INT32_C(   676131506),
      -INT32_C(   842908133),  INT32_C(   655884307), -INT32_C(   912868843), -INT32_C(    34908089), -INT32_C(   299878266),  INT32_C(   523497435),  INT32_C(  1190422164),  INT32_C(  1936605272),
      -INT32_C(  1841286786),  INT32_C(  1186551857),  INT32_C(  1511018514),  INT32_C(   777517992),  INT32_C(   236746547), -INT32_C(    97693850),  INT32_C(   239083958), -INT32_C(   528306334),
       INT32_C(   292733664),  INT32_C(   760687643),  INT32_C(   612853628), -INT32_C(  1772953757), -INT32_C(  1113231786),  INT32_C(  1958204094),  INT32_C(  1451423988), -INT32_C(  2026503001),
      -INT32_C(   493311545),  INT32_C(  1359998933), -INT32_C(  1166698665), -INT32_C(   867121290), -INT32_C(   209062603), -INT32_C(  1134083640), -INT32_C(   535631303), -INT32_C(  1251522322),
      -INT32_C(   963117071),  INT32_C(  1159178222), -INT32_C(  1258320834), -INT32_C(  1988079533),  INT32_C(   226232901), -INT32_C(  2067143605), -INT32_C(  1134240818),  INT32_C(   359844644),
      -INT32_C(  1193539126), -INT32_C(   285281360), -INT32_C(   744292992), -INT32_C(  1822678195),  INT32_C(  2023807277), -INT32_C(  1946391875),  INT32_C(  1766285381), -INT32_C(   176178901),
       INT32_C(  1940741059), -INT32_C(   832394418), -INT32_C(   157154135),  INT32_C(  1418329639), -INT32_C(  1798559017), -INT32_C(   652228460),  INT32_C(  1396926248), -INT32_C(   481770976),
       INT32_C(  1800926749),  INT32_C(  1245362593), -INT32_C(   448668483), -INT32_C(  1304835366), -INT32_C(  2008676620), -INT32_C(   144546098), -INT32_C(   313874995), -INT32_C(  2066640025),
       INT32_C(   720316553), -INT32_C(  1636488735), -INT32_C(   528239099),  INT32_C(  1972551040), -INT32_C(  1845634877),  INT32_C(   193486654),  INT32_C(  1811534596), -INT32_C(   269497754),
      -INT32_C(   753278990),  INT32_C(   242322952), -INT32_C(   974195388),  INT32_C(  1966768306), -INT32_C(  1761200296), -INT32_C(  1683845225), -INT32_C(   939025566),  INT32_C(  1471673957),
      -INT32_C(   567619371), -INT32_C(  1544774561),  INT32_C(  1130945169), -INT32_C(  1296522662),  INT32_C(  1900658394), -INT32_C(  1358107571), -INT32_C(   310963321), -INT32_C(   549179894),
       INT32_C(  1589473279), -INT32_C(  1677612789), -INT32_C(   572560765), -INT32_C(   426731764), -INT32_C(  1554523819),  INT32_C(  1297245381), -INT32_C(  2126853513), -INT32_C(   144605448),
      -INT32_C(   128639251),  INT32_C(  1268013000), -INT32_C(   852921407),  INT32_C(  1622456586),  INT32_C(  1476594578), -INT32_C(   408595089),  INT32_C(   409526047),  INT32_C(  1259325789),
      -INT32_C(  1337760280),  INT32_C(  2113657020),  INT32_C(  1447699531),  INT32_C(  1891040989),  INT32_C(  2043197706),  INT32_C(   778071310), -INT32_C(  1454978740),  INT32_C(  2062833042),
       INT32_C(  1982478522),  INT32_C(  1542661648),  INT32_C(   682704458),  INT32_C(  1184393020),  INT32_C(   801136672),  INT32_C(   425533645),  INT32_C(  2093130729), -INT32_C(  1275676680),
      -INT32_C(    14081553), -INT32_C(  1856365241), -INT32_C(  1749480357), -INT32_C(  1797369485),  INT32_C(  2126749361), -INT32_C(  1466490690), -INT32_C(  1155245373),  INT32_C(     7215633),
      -INT32_C(  2097178565),  INT32_C(   269769141), -INT32_C(   643314331), -INT32_C(   798128865), -INT32_C(   498126813),  INT32_C(   327870032),  INT32_C(  1372499520),  INT32_C(    72433096),
      -INT32_C(  1970908971),  INT32_C(   261790378), -INT32_C(  2014822040), -INT32_C(   363375161), -INT32_C(   708008315), -INT32_C(   840411507), -INT32_C(   853559548), -INT32_C(   909020940),
       INT32_C(  1800624065),  INT32_C(  1518005746), -INT32_C(   169778386),  INT32_C(  1054881976),  INT32_C(  1813228767),  INT32_C(   121240579), -INT32_C(  1479255885), -INT32_C(  1972329015),
      -INT32_C(   269106179), -INT32_C(   565612624), -INT32_C(  1949029678),  INT32_C(  1103737954),  INT32_C(  1672338528), -INT32_C(  1955862568),  INT32_C(   137510719), -INT32_C(   493706523),
       INT32_C(   366053221), -INT32_C(   906749193), -INT32_C(  1504393148), -INT32_C(   588767876), -INT32_C(   767519238), -INT32_C(  1134646404), -INT32_C(   809201430), -INT32_C(  1733208269),
      -INT32_C(   709983522), -INT32_C(   526409060), -INT32_C(   427297942),  INT32_C(   197291793), -INT32_C(  2116222460), -INT32_C(  1740817491), -INT32_C(    10026548),  INT32_C(   932649304),
       INT32_C(   940328347),  INT32_C(  1360571367), -INT32_C(  1338531937),  INT32_C(   331086350), -INT32_C(  1433102084), -INT32_C(  1606233644),  INT32_C(   731883986),  INT32_C(  1583494850),
       INT32_C(  1670803068), -INT32_C(  1179275750),  INT32_C(  1550445646), -INT32_C(   479255322), -INT32_C(  1869806660), -INT32_C(  1489973292),  INT32_C(  1003671416), -INT32_C(  2103888890),
      -INT32_C(  1125830750),  INT32_C(   729127645),  INT32_C(  1837686407), -INT32_C(  1085212926), -INT32_C(   816849413),  INT32_C(   628523180),  INT32_C(  1432373327),  INT32_C(   534247804),
       INT32_C(    98286888), -INT32_C(   567193257) };
  static const int32_t b[] =
    {  INT32_C(  1992646528), -INT32_C(   500632349),  INT32_C(  1845118854),  INT32_C(  1206494589),  INT32_C(  1888860936), -INT32_C(   192372238), -INT32_C(   268503773),  INT32_C(    62261890),
       INT32_C(  1283029865), -INT32_C(   164650385),  INT32_C(  1717774825), -INT32_C(   676508210), -INT32_C(    95993336),  INT32_C(   133091556),  INT32_C(  1207364805),  INT32_C(  1598729462),
      -INT32_C(  1750285272),  INT32_C(  1334696806), -INT32_C(   743051004),  INT32_C(  1185571646), -INT32_C(  1992232539), -INT32_C(  2037371199),  INT32_C(   281970202),  INT32_C(  1534007347),
       INT32_C(  1123163100), -INT32_C(    74350346), -INT32_C(  1345435791),  INT32_C(  1341487274),  INT32_C(   735655273),  INT32_C(  2108778851),  INT32_C(   596475888),  INT32_C(  1954479256),
       INT32_C(   246902808),  INT32_C(  1627998448),  INT32_C(   957405071), -INT32_C(  1182202545), -INT32_C(  1645977030), -INT32_C(  1155885621), -INT32_C(  1377917163), -INT32_C(  1138664284),
      -INT32_C(  1110779699), -INT32_C(  1340091359), -INT32_C(    68538453),  INT32_C(  1874096949), -INT32_C(  1609721643),  INT32_C(  1113335597),  INT32_C(  1945057999),  INT32_C(  1680806295),
       INT32_C(   169998825),  INT32_C(  2042314957), -INT32_C(  1519082128), -INT32_C(   317446120), -INT32_C(   309517888),  INT32_C(   405858633), -INT32_C(  1148510428),  INT32_C(   438286896),
      -INT32_C(  2128330573), -INT32_C(   235217023), -INT32_C(  1667862908),  INT32_C(  1451862678),  INT32_C(   356718540),  INT32_C(   606958336), -INT32_C(  1008748397),  INT32_C(   635305586),
      -INT32_C(  1062862273),  INT32_C(  1722917089), -INT32_C(  1543354610), -INT32_C(  1107653391), -INT32_C(  1546502493),  INT32_C(  1154023345),  INT32_C(   688433079), -INT32_C(   447748698),
      -INT32_C(   911870489), -INT32_C(  1540401514), -INT32_C(  1907805795),  INT32_C(  1615610813),  INT32_C(   855907969), -INT32_C(   713569250),  INT32_C(   436174707),  INT32_C(  1291734629),
      -INT32_C(   652893373), -INT32_C(  1770109703),  INT32_C(   858113910), -INT32_C(  1936428790), -INT32_C(  1379952497), -INT32_C(   679266716),  INT32_C(   468812470),  INT32_C(   325578704),
      -INT32_C(  1930592877),  INT32_C(   925068225),  INT32_C(  1013663794),  INT32_C(  1221132217), -INT32_C(    67729513),  INT32_C(  1959950782), -INT32_C(   879770629),  INT32_C(  1189017267),
       INT32_C(   903007091),  INT32_C(  1751971126), -INT32_C(   156903619),  INT32_C(  1832873430), -INT32_C(  1285016075), -INT32_C(  1457046610), -INT32_C(  1317751042),  INT32_C(   553079468),
       INT32_C(  1414908446), -INT32_C(    37895745),  INT32_C(  1878221465), -INT32_C(   992136497),  INT32_C(   360138087),  INT32_C(  2143198848),  INT32_C(    19935828), -INT32_C(  1558108027),
      -INT32_C(  1309182222), -INT32_C(   793856969), -INT32_C(   431971818),  INT32_C(  1017781716), -INT32_C(   481222046),  INT32_C(   358748352), -INT32_C(   954822078), -INT32_C(  1402325062),
      -INT32_C(   463576403),  INT32_C(   766839830), -INT32_C(  2095843922),  INT32_C(  1958722834), -INT32_C(  1604906785),  INT32_C(  1672853792),  INT32_C(   103467852), -INT32_C(  1347185406),
       INT32_C(   227742199), -INT32_C(   868595683),  INT32_C(  1330597181), -INT32_C(   356250101),  INT32_C(  1066015518),  INT32_C(   564281301),  INT32_C(   203934730),  INT32_C(  1488706145),
       INT32_C(   157700075), -INT32_C(   707420009), -INT32_C(   115071762),  INT32_C(  1357113394), -INT32_C(   644911612), -INT32_C(  1191562835),  INT32_C(  1606689278), -INT32_C(   407338756),
       INT32_C(  1727012559), -INT32_C(  1405368898),  INT32_C(   463823081),  INT32_C(  1282181448), -INT32_C(  1541014537),  INT32_C(   727457581),  INT32_C(  1032462657),  INT32_C(  1881424545),
       INT32_C(   534123872), -INT32_C(   993324326), -INT32_C(  1159761550), -INT32_C(   251180038),  INT32_C(  1955933255), -INT32_C(  1918897588), -INT32_C(  1261819629), -INT32_C(   869994900),
      -INT32_C(   554960381),  INT32_C(  2124592908),  INT32_C(   574193960),  INT32_C(   336806093), -INT32_C(  1199003540), -INT32_C(  1387976806), -INT32_C(  1134489776),  INT32_C(    25789950),
      -INT32_C(  1931512704),  INT32_C(  1393262891), -INT32_C(   797621245), -INT32_C(   253458300), -INT32_C(   878089167), -INT32_C(   478548333), -INT32_C(    56567042), -INT32_C(   520279712),
      -INT32_C(   915612259),  INT32_C(  1629255518),  INT32_C(  1060213435),  INT32_C(  1261442330),  INT32_C(   337107329), -INT32_C(   973565753), -INT32_C(   893282198),  INT32_C(  1588248513),
      -INT32_C(    98101348),  INT32_C(  1247560846), -INT32_C(   259420714),  INT32_C(   607959459),  INT32_C(  1513706386),  INT32_C(  1293890019), -INT32_C(  1978080823),  INT32_C(  1021887136),
       INT32_C(  1748373721),  INT32_C(   716345940), -INT32_C(  1021691104), -INT32_C(  2014882059), -INT32_C(  1931403095),  INT32_C(   450494801), -INT32_C(  2103119134), -INT32_C(  1900114508),
      -INT32_C(   235473763), -INT32_C(  1491359609), -INT32_C(   664128029),  INT32_C(   895504780), -INT32_C(  1010679438),  INT32_C(   618568770),  INT32_C(  1118208654), -INT32_C(  1395629041),
      -INT32_C(   526530983),  INT32_C(  1384626286),  INT32_C(  2049634798), -INT32_C(  1263564222),  INT32_C(   242774476), -INT32_C(  1691134451), -INT32_C(   388048424), -INT32_C(  1751863746),
      -INT32_C(   478727563), -INT32_C(   667549974),  INT32_C(   827482351), -INT32_C(  1226439958), -INT32_C(  2117771661), -INT32_C(  1944258380),  INT32_C(   259324625),  INT32_C(   514197929),
       INT32_C(   620830011),  INT32_C(   184432411), -INT32_C(  2126753641), -INT32_C(   969399726),  INT32_C(   877133184), -INT32_C(   960470027),  INT32_C(   131478878),  INT32_C(  2032499774),
      -INT32_C(  1247926630), -INT32_C(   188703651) };
  static const int32_t e[] =
    {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1082176720),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(  1945049124),  INT32_C(           0),  INT32_C(           0),  INT32_C(   536251887),  INT32_C(   618623960),  INT32_C(           0),  INT32_C(  1877820189),
      -INT32_C(   490887746),  INT32_C(  1414966717),  INT32_C(           0),  INT32_C(   205601565), -INT32_C(  1591003447),  INT32_C(           0), -INT32_C(   553116734),  INT32_C(   474936670),
       INT32_C(           0),  INT32_C(           0), -INT32_C(  1076638301),  INT32_C(           0), -INT32_C(   160237235),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(  1870273914),  INT32_C(  1147294456),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(   730507087),  INT32_C(           0),  INT32_C(  1579556967), -INT32_C(  1096578957),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1705974041),  INT32_C(           0),
       INT32_C(   122734839), -INT32_C(  1281627314),  INT32_C(  2131935756), -INT32_C(  1455507637),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(   501164243),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(   563738867),  INT32_C(           0), -INT32_C(   880426142),  INT32_C(           0),  INT32_C(  1073800346), -INT32_C(  1822673897),  INT32_C(           0),
      -INT32_C(   281668637),  INT32_C(  1255120154),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1330110674), -INT32_C(  1467913530),
      -INT32_C(  1701332864),  INT32_C(           0),  INT32_C(           0), -INT32_C(   940208867), -INT32_C(   418606520),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(   563447670),  INT32_C(   320294368), -INT32_C(  1462332277),  INT32_C(  1768999713), -INT32_C(  1940947107), -INT32_C(  2104496880),  INT32_C(   565895634),  INT32_C(           0),
       INT32_C(           0),  INT32_C(   906507435), -INT32_C(   371335480),  INT32_C(           0), -INT32_C(   560618802),  INT32_C(           0), -INT32_C(  1165681658),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(  1442550443),  INT32_C(           0), -INT32_C(  2121338383),  INT32_C(           0), -INT32_C(   958961394), -INT32_C(  1265185312),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1980662918), -INT32_C(  1913086856),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    50382966),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(  2136608683),  INT32_C(           0),  INT32_C(  1978706687),  INT32_C(   410579060),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(  1495460355), -INT32_C(  1473890267),  INT32_C(  1562771293),  INT32_C(   533927595),  INT32_C(           0),  INT32_C(  1969634145),  INT32_C(           0), -INT32_C(  1824795498),
       INT32_C(           0), -INT32_C(  1346936750),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1060668072),  INT32_C(  1137866071),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   170816106),  INT32_C(           0),  INT32_C(   106574256),  INT32_C(           0),
       INT32_C(           0), -INT32_C(  1854823767), -INT32_C(  1217508291),  INT32_C(           0),  INT32_C(   700876727),  INT32_C(  1715846838),  INT32_C(           0),  INT32_C(    46643146),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   109916861),  INT32_C(           0), -INT32_C(   361863174),  INT32_C(           0), -INT32_C(   388741228),
      -INT32_C(  1578730972), -INT32_C(   111249772),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   734389768),
      -INT32_C(   171004831),  INT32_C(           0), -INT32_C(  1689608964),  INT32_C(   495778495),  INT32_C(           0),  INT32_C(  1045214709),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1426114183),  INT32_C(  1163883857), -INT32_C(  1585141205),  INT32_C(  1293917704),  INT32_C(           0),
      -INT32_C(   474509759),  INT32_C(   964950549),  INT32_C(           0), -INT32_C(   698212987),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1966688951),
       INT32_C(  1466859330),  INT32_C(           0),  INT32_C(   906800561),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1119932410), -INT32_C(   959608700),
      -INT32_C(  2145436665),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   744346791),  INT32_C(  1676880477),
      -INT32_C(  1746660761),  INT32_C(   544695234),  INT32_C(           0), -INT32_C(   115813200),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(  1346213518), -INT32_C(   378489606) };

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
    rv = simde_svsub_s32_z(pv, av, bv);

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

    ev = simde_svsub_s32_z(pv, av, bv);

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
test_simde_svsub_s32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0) };
  static const int32_t a[] =
    {  INT32_C(   950706109), -INT32_C(   816902628), -INT32_C(   306316961), -INT32_C(  1071503309),  INT32_C(   194938153),  INT32_C(    64761084), -INT32_C(   186754397), -INT32_C(   668323045),
      -INT32_C(   300886830),  INT32_C(  1102929890), -INT32_C(  1943110823), -INT32_C(   867413597), -INT32_C(   740824106), -INT32_C(  1160334569),  INT32_C(   699315214), -INT32_C(  1191061273),
      -INT32_C(  1884810835), -INT32_C(   892246671), -INT32_C(  2091450400),  INT32_C(   659596112), -INT32_C(  1510332530), -INT32_C(   379596581),  INT32_C(  1813122436), -INT32_C(  1843063835),
      -INT32_C(  1792881372),  INT32_C(   325055283),  INT32_C(  1134016242), -INT32_C(   412424359), -INT32_C(   376675314), -INT32_C(  1194136780), -INT32_C(   584784648),  INT32_C(   477121271),
       INT32_C(  1253151255),  INT32_C(  2002653573),  INT32_C(   549123527), -INT32_C(   368630564), -INT32_C(  1126919288),  INT32_C(  1987421822), -INT32_C(  2108450421), -INT32_C(    73481245),
      -INT32_C(   632991659),  INT32_C(   676504417),  INT32_C(  1950878872), -INT32_C(  1184936143),  INT32_C(  1618359266),  INT32_C(  1691806681),  INT32_C(  1759979908),  INT32_C(  1113818605),
       INT32_C(   907913429), -INT32_C(   463573172), -INT32_C(  1403410821), -INT32_C(   681133835), -INT32_C(  1002971925),  INT32_C(  1260981703),  INT32_C(   615714871),  INT32_C(  1801852565),
       INT32_C(   195134399),  INT32_C(  1861157106), -INT32_C(  1675999066), -INT32_C(   344752128),  INT32_C(   598780764), -INT32_C(   277882440),  INT32_C(  2115183337), -INT32_C(   118916551),
      -INT32_C(   268203011),  INT32_C(   828306059),  INT32_C(  1003321403),  INT32_C(  1428636153), -INT32_C(  1535518740), -INT32_C(  1718294352),  INT32_C(  1125623562),  INT32_C(   523960609),
       INT32_C(   386875020),  INT32_C(  1816685873), -INT32_C(   559474971),  INT32_C(  1127534167),  INT32_C(  1441246629), -INT32_C(  1611760747),  INT32_C(  1155728931), -INT32_C(  1822220793),
      -INT32_C(  1901432227), -INT32_C(   973409569),  INT32_C(  1604559112),  INT32_C(   362993520),  INT32_C(   426478212),  INT32_C(   683235589),  INT32_C(  1718459487),  INT32_C(   402247866),
       INT32_C(   581280579), -INT32_C(  1628987498), -INT32_C(  1308718271), -INT32_C(   406413214),  INT32_C(   805318954), -INT32_C(   363284085),  INT32_C(   273794389), -INT32_C(   651736426),
      -INT32_C(  2063872530), -INT32_C(  1390222484), -INT32_C(   799137682), -INT32_C(   340318783), -INT32_C(   518277034), -INT32_C(   942902159), -INT32_C(   807985863),  INT32_C(  1437138535),
       INT32_C(   953787595), -INT32_C(   169476985), -INT32_C(   574274532), -INT32_C(  1077314199), -INT32_C(  1499339723), -INT32_C(  1838322344), -INT32_C(   245283702),  INT32_C(   239536707),
       INT32_C(   893788334),  INT32_C(   959065116), -INT32_C(   652808336), -INT32_C(  1583816852),  INT32_C(   474495428),  INT32_C(   816756134),  INT32_C(  1025642746), -INT32_C(   934581990),
      -INT32_C(  1493331319),  INT32_C(   786376638), -INT32_C(  2096630506), -INT32_C(  1725653035),  INT32_C(  2142596313),  INT32_C(   481322018), -INT32_C(  1906716044), -INT32_C(  1000954821),
      -INT32_C(   194358474), -INT32_C(  1876801158),  INT32_C(   336800063), -INT32_C(  1565706039), -INT32_C(   970890588),  INT32_C(   987943366), -INT32_C(   557302877),  INT32_C(   379789024),
      -INT32_C(   351597199), -INT32_C(  1770246825),  INT32_C(   548048727),  INT32_C(  1824675783), -INT32_C(  2144148551),  INT32_C(  1488590261),  INT32_C(   808944464),  INT32_C(   323476129),
       INT32_C(  1056854759), -INT32_C(   690718081), -INT32_C(   772375030), -INT32_C(  1891780395),  INT32_C(  1359966364), -INT32_C(   710293115), -INT32_C(   301539252), -INT32_C(  1576972870),
       INT32_C(   518061983), -INT32_C(  2064272006),  INT32_C(   156625715),  INT32_C(  1083741092), -INT32_C(  2003720445), -INT32_C(  1117963664), -INT32_C(   710188261),  INT32_C(  1333243056),
       INT32_C(   627988651),  INT32_C(  1084842765), -INT32_C(   230031538), -INT32_C(  1791827566), -INT32_C(   115489912),  INT32_C(   431389438), -INT32_C(  1896980002), -INT32_C(  1193384435),
      -INT32_C(   874623810), -INT32_C(    49576017),  INT32_C(   418403718) };
  static const int32_t b[] =
    {  INT32_C(  1913713772),  INT32_C(  1433727220),  INT32_C(   744592137),  INT32_C(  2073706440),  INT32_C(  1229970923), -INT32_C(   172566530), -INT32_C(  2098388476), -INT32_C(  1485705669),
      -INT32_C(   702971422),  INT32_C(  2049674609), -INT32_C(   391738336), -INT32_C(  1218166324),  INT32_C(   469807902), -INT32_C(  1911441782),  INT32_C(   336658137), -INT32_C(   826506516),
       INT32_C(  1973802243), -INT32_C(  2081435549),  INT32_C(   694982237), -INT32_C(   169815849),  INT32_C(   219341187),  INT32_C(  1889215383),  INT32_C(   243641378),  INT32_C(   836583726),
       INT32_C(  2040955414), -INT32_C(  1342335406),  INT32_C(    64514348), -INT32_C(  1124550343),  INT32_C(   835259034),  INT32_C(  1352819758),  INT32_C(  1046357776),  INT32_C(  2121284456),
       INT32_C(   284694205), -INT32_C(   658508372), -INT32_C(  1747216290), -INT32_C(   346827695),  INT32_C(   203168990), -INT32_C(  1856192896),  INT32_C(  1305459685), -INT32_C(  1261682698),
       INT32_C(    46449750),  INT32_C(   400262073),  INT32_C(  1823389211),  INT32_C(  1767309706), -INT32_C(  1653246947),  INT32_C(   405721650), -INT32_C(  2090467699), -INT32_C(  1825099459),
      -INT32_C(  1365836811), -INT32_C(  1698336385), -INT32_C(  1308134617), -INT32_C(  1860477324),  INT32_C(    87003346), -INT32_C(   283288222), -INT32_C(  1720483237), -INT32_C(  1456690508),
       INT32_C(   626573990),  INT32_C(  1539251507),  INT32_C(    84788881), -INT32_C(   141088731),  INT32_C(   469550776),  INT32_C(  2131368227),  INT32_C(  1343782300), -INT32_C(   822524888),
       INT32_C(   989024519),  INT32_C(     9810543), -INT32_C(  1643797895), -INT32_C(  2087346998), -INT32_C(  2036428190),  INT32_C(  1191553195),  INT32_C(  1318526246),  INT32_C(  1746702689),
       INT32_C(  1369640930),  INT32_C(   978401473), -INT32_C(  1512548389),  INT32_C(  1445490419), -INT32_C(  1411594752), -INT32_C(  1779179153),  INT32_C(  1608747774), -INT32_C(    20381925),
      -INT32_C(   816878834),  INT32_C(  2114625955), -INT32_C(   349904136),  INT32_C(  1346456656), -INT32_C(  2097406701), -INT32_C(    65540098), -INT32_C(  1789068679),  INT32_C(   127083769),
       INT32_C(   852943503),  INT32_C(  2075254915),  INT32_C(   325572035),  INT32_C(   879011873), -INT32_C(   994680634), -INT32_C(   926823089), -INT32_C(  1067639353), -INT32_C(   792203199),
       INT32_C(  1443012307),  INT32_C(  1104327550), -INT32_C(  1437255288), -INT32_C(  1478575647),  INT32_C(  1751946521),  INT32_C(   707800418), -INT32_C(  1947562422),  INT32_C(  1364963966),
      -INT32_C(   827826864), -INT32_C(  1726973423), -INT32_C(  1807522381),  INT32_C(   926687774),  INT32_C(   429893815),  INT32_C(   524537813), -INT32_C(   592826787),  INT32_C(   808256992),
       INT32_C(  1946080610),  INT32_C(    34410063), -INT32_C(  1852354445),  INT32_C(   701027186),  INT32_C(  1346594683), -INT32_C(  1804630473), -INT32_C(  1804592716), -INT32_C(  2134598114),
      -INT32_C(  1007369357),  INT32_C(  1170538961), -INT32_C(   992584623), -INT32_C(  1427267793),  INT32_C(  1039806470),  INT32_C(  1808951735), -INT32_C(  1610595710),  INT32_C(  1411499232),
       INT32_C(  1494685063),  INT32_C(  1738464278),  INT32_C(  1747678265),  INT32_C(   437459219),  INT32_C(     5705033), -INT32_C(   110352009),  INT32_C(  1285188716), -INT32_C(  1197425872),
      -INT32_C(   435046448), -INT32_C(   850546796),  INT32_C(   926251299), -INT32_C(   615429998), -INT32_C(   841177002),  INT32_C(  1053182162), -INT32_C(   460693324), -INT32_C(   342086885),
       INT32_C(  1993453026), -INT32_C(  2143084708),  INT32_C(   716667288),  INT32_C(   386205889), -INT32_C(  2098929232), -INT32_C(   574575831),  INT32_C(   667044619),  INT32_C(  1477598838),
       INT32_C(  1758454796), -INT32_C(  1679289853),  INT32_C(  1304797067),  INT32_C(  1483000487), -INT32_C(   707114580), -INT32_C(     5006348),  INT32_C(  1546024422), -INT32_C(   541836845),
       INT32_C(   541623069),  INT32_C(   565915798),  INT32_C(  2003730640), -INT32_C(   154152118),  INT32_C(   281848348),  INT32_C(   722435909), -INT32_C(   947439884), -INT32_C(  1935197329),
       INT32_C(  1437396927), -INT32_C(   277453025),  INT32_C(   828892647) };
  static const int32_t e[] =
    {  INT32_C(   950706109),  INT32_C(  2044337448), -INT32_C(   306316961),  INT32_C(  1149757547),  INT32_C(   194938153),  INT32_C(   237327614),  INT32_C(  1911634079),  INT32_C(   817382624),
      -INT32_C(   300886830), -INT32_C(   946744719), -INT32_C(  1551372487),  INT32_C(   350752727), -INT32_C(  1210632008),  INT32_C(   751107213),  INT32_C(   699315214), -INT32_C(   364554757),
       INT32_C(   436354218), -INT32_C(   892246671), -INT32_C(  2091450400),  INT32_C(   659596112), -INT32_C(  1729673717), -INT32_C(   379596581),  INT32_C(  1813122436), -INT32_C(  1843063835),
       INT32_C(   461130510),  INT32_C(   325055283),  INT32_C(  1134016242),  INT32_C(   712125984), -INT32_C(  1211934348), -INT32_C(  1194136780), -INT32_C(  1631142424),  INT32_C(   477121271),
       INT32_C(  1253151255), -INT32_C(  1633805351), -INT32_C(  1998627479), -INT32_C(    21802869), -INT32_C(  1330088278),  INT32_C(  1987421822), -INT32_C(  2108450421),  INT32_C(  1188201453),
      -INT32_C(   679441409),  INT32_C(   276242344),  INT32_C(  1950878872), -INT32_C(  1184936143),  INT32_C(  1618359266),  INT32_C(  1691806681), -INT32_C(   444519689), -INT32_C(  1356049232),
       INT32_C(   907913429),  INT32_C(  1234763213), -INT32_C(    95276204),  INT32_C(  1179343489), -INT32_C(  1002971925),  INT32_C(  1260981703),  INT32_C(   615714871),  INT32_C(  1801852565),
       INT32_C(   195134399),  INT32_C(  1861157106), -INT32_C(  1760787947), -INT32_C(   203663397),  INT32_C(   129229988),  INT32_C(  1885716629),  INT32_C(   771401037), -INT32_C(   118916551),
      -INT32_C(  1257227530),  INT32_C(   818495516), -INT32_C(  1647847998), -INT32_C(   778984145), -INT32_C(  1535518740), -INT32_C(  1718294352), -INT32_C(   192902684), -INT32_C(  1222742080),
      -INT32_C(   982765910),  INT32_C(   838284400),  INT32_C(   953073418), -INT32_C(   317956252), -INT32_C(  1442125915),  INT32_C(   167418406),  INT32_C(  1155728931), -INT32_C(  1801838868),
      -INT32_C(  1901432227), -INT32_C(   973409569),  INT32_C(  1604559112), -INT32_C(   983463136), -INT32_C(  1771082383),  INT32_C(   683235589), -INT32_C(   787439130),  INT32_C(   275164097),
       INT32_C(   581280579), -INT32_C(  1628987498), -INT32_C(  1634290306), -INT32_C(  1285425087),  INT32_C(  1799999588),  INT32_C(   563539004),  INT32_C(  1341433742), -INT32_C(   651736426),
       INT32_C(   788082459),  INT32_C(  1800417262), -INT32_C(   799137682), -INT32_C(   340318783), -INT32_C(   518277034), -INT32_C(  1650702577), -INT32_C(   807985863),  INT32_C(    72174569),
       INT32_C(   953787595),  INT32_C(  1557496438),  INT32_C(  1233247849), -INT32_C(  1077314199), -INT32_C(  1929233538),  INT32_C(  1932107139),  INT32_C(   347543085),  INT32_C(   239536707),
       INT32_C(   893788334),  INT32_C(   959065116), -INT32_C(   652808336), -INT32_C(  1583816852), -INT32_C(   872099255), -INT32_C(  1673580689),  INT32_C(  1025642746),  INT32_C(  1200016124),
      -INT32_C(   485961962),  INT32_C(   786376638), -INT32_C(  1104045883), -INT32_C(   298385242),  INT32_C(  1102789843),  INT32_C(   481322018), -INT32_C(  1906716044),  INT32_C(  1882513243),
      -INT32_C(   194358474), -INT32_C(  1876801158),  INT32_C(   336800063), -INT32_C(  1565706039), -INT32_C(   976595621),  INT32_C(  1098295375), -INT32_C(   557302877),  INT32_C(  1577214896),
      -INT32_C(   351597199), -INT32_C(   919700029), -INT32_C(   378202572),  INT32_C(  1824675783), -INT32_C(  2144148551),  INT32_C(   435408099),  INT32_C(   808944464),  INT32_C(   323476129),
      -INT32_C(   936598267), -INT32_C(   690718081), -INT32_C(   772375030),  INT32_C(  2016981012),  INT32_C(  1359966364), -INT32_C(   135717284), -INT32_C(   301539252), -INT32_C(  1576972870),
       INT32_C(   518061983), -INT32_C(  2064272006), -INT32_C(  1148171352),  INT32_C(  1083741092), -INT32_C(  1296605865), -INT32_C(  1112957316), -INT32_C(   710188261),  INT32_C(  1333243056),
       INT32_C(    86365582),  INT32_C(  1084842765),  INT32_C(  2061205118), -INT32_C(  1637675448), -INT32_C(   115489912),  INT32_C(   431389438), -INT32_C(  1896980002), -INT32_C(  1193384435),
       INT32_C(  1982946559),  INT32_C(   227877008),  INT32_C(   418403718) };

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
    rv = simde_svsub_s32_m(pv, av, bv);

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

    ev = simde_svsub_s32_m(pv, av, bv);

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
test_simde_svsub_s64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1) };
  static const int64_t a[] =
    {  INT64_C( 6532652014770463393),  INT64_C( 8779382456279995988), -INT64_C( 2769458164604990502), -INT64_C( 5909295505566419543),
      -INT64_C( 7504489826095554790),  INT64_C( 3717329349477971784), -INT64_C( 7856325143341498202), -INT64_C( 1141815515988631954),
       INT64_C( 3165548828861346067), -INT64_C(  824758728635403519), -INT64_C( 2425175820351588642),  INT64_C( 6318690206167388138),
       INT64_C( 7692038665835257776), -INT64_C( 4354327843077617841), -INT64_C( 7253360897991006969), -INT64_C( 2428553802746712399),
      -INT64_C( 1802229753089689046),  INT64_C( 1936571007318081848), -INT64_C(  213948146146776645), -INT64_C( 7520379786578730346),
       INT64_C( 9057909030825694264),  INT64_C(  582787677160093930),  INT64_C( 2678651733285316836), -INT64_C( 7718452483337937187),
       INT64_C( 2261676958136077728),  INT64_C( 6675797516260015695),  INT64_C( 8327077187908541146), -INT64_C( 6500771217417602601),
      -INT64_C( 7925790798647710804),  INT64_C( 3081258536834899437), -INT64_C( 2452451861667229970),  INT64_C(   20223680866006173),
      -INT64_C( 5775614999038602492), -INT64_C( 3855970939194571007), -INT64_C( 3384379029601775580), -INT64_C(  698414242823202310),
       INT64_C( 1657066369180316046),  INT64_C( 1063945634847396637),  INT64_C( 5907106803371021044), -INT64_C( 5240802205172273573),
      -INT64_C( 5455540752123199201), -INT64_C( 8425548163247656423), -INT64_C( 1645029314590913662), -INT64_C( 2811236031725581540),
       INT64_C( 2542376588789154813), -INT64_C( 1717498298775440119), -INT64_C( 6198380746977911164), -INT64_C( 6176146283788553800),
      -INT64_C( 5396571651016075793), -INT64_C(   87680027007368581),  INT64_C( 3500434324813023837),  INT64_C( 6742991928702436156),
      -INT64_C( 3268925757059575487), -INT64_C( 3230071089506617677), -INT64_C( 8958133241299256315),  INT64_C( 8980458286976094420),
       INT64_C( 2015654850190767824),  INT64_C( 3191493193527569154),  INT64_C( 3349648266809116850), -INT64_C( 5233444554330216281),
      -INT64_C( 2987056620403504888), -INT64_C(  156051161343928957),  INT64_C( 9090643215018065824), -INT64_C( 5549630278296561316),
       INT64_C( 3761823665572993417), -INT64_C( 4914637636328652157), -INT64_C( 7888374473148743118),  INT64_C( 3590442748485166966),
       INT64_C( 2850713299338655402),  INT64_C( 5845039132416764998),  INT64_C( 2759546246323163779), -INT64_C( 7232468802795527992),
       INT64_C( 4313469833480384785),  INT64_C( 1468941560704782833),  INT64_C( 7305710084134124684), -INT64_C( 2970837789981693383),
       INT64_C( 3591734230029941671), -INT64_C( 4909304919111862984), -INT64_C(  188205857770001311),  INT64_C( 6242530798283995141),
      -INT64_C( 3667676581109486169),  INT64_C( 7073594809471425344), -INT64_C( 8943088390012657119), -INT64_C( 6988759824715609092),
       INT64_C(   35641497026491676), -INT64_C( 6026491904148957701),  INT64_C( 9132303346572639932),  INT64_C( 1591790447568226944),
       INT64_C( 4098633267967139105), -INT64_C( 6516266752069644198),  INT64_C( 1823847454766736207), -INT64_C( 4127926579121522266),
       INT64_C( 2214232540098035269), -INT64_C( 3573724502858404136), -INT64_C( 8617375231207586121), -INT64_C( 1741522372593649304),
      -INT64_C( 2576582336667092132), -INT64_C( 8331933271271259886),  INT64_C( 6104142126136426060),  INT64_C( 1857232085461425725),
       INT64_C( 7319043545836892081), -INT64_C( 9000068687524908872),  INT64_C( 8544568988136502611), -INT64_C( 2441765547116464570),
      -INT64_C( 8789859003366418869), -INT64_C( 6697084296905819562),  INT64_C( 8057634802349883682), -INT64_C( 8180348628096571538),
      -INT64_C( 8630251266596139802), -INT64_C( 6981102255318216917), -INT64_C( 1693973060212096283),  INT64_C( 7477660383935983860) };
  static const int64_t b[] =
    {  INT64_C( 6260434236223029055),  INT64_C(  806165106989865988), -INT64_C( 4267517956441819975), -INT64_C(  734138731018582554),
       INT64_C( 2191735804500022095), -INT64_C( 6294044436718429000), -INT64_C(  572006552130726077), -INT64_C(  539163494429042472),
      -INT64_C( 7904249616524362219), -INT64_C( 9157834287994753710), -INT64_C( 6829468281308711635), -INT64_C( 9199812340115051854),
       INT64_C( 2837266484482301938), -INT64_C( 8005341424760943317),  INT64_C( 4588895947245793861), -INT64_C( 8872393002981859598),
      -INT64_C( 5239745150056362420),  INT64_C( 4985772862231982141), -INT64_C(  322849559446093384),  INT64_C( 6482709620020748257),
       INT64_C( 3749180681783822276), -INT64_C( 1965534073890527629), -INT64_C( 1149914275625956346),  INT64_C( 6788431630188110798),
      -INT64_C( 1743818348100144991), -INT64_C( 5914330606818647588), -INT64_C( 7773274782094846432),  INT64_C( 9016669197051068970),
       INT64_C( 7111151405151735892),  INT64_C( 4456125039572027779), -INT64_C( 8879256395805060243),  INT64_C( 3415533756344710669),
      -INT64_C( 2152256216733615047),  INT64_C( 5695333767012191151),  INT64_C(  961034738842301815),  INT64_C( 4721845020459966078),
      -INT64_C( 3162896774343917863), -INT64_C( 9016582437318154323),  INT64_C( 2751041486955175967),  INT64_C( 6525723012514063431),
       INT64_C( 6952905482102345860), -INT64_C( 1773627945362973227), -INT64_C( 6342136589027133906),  INT64_C(  375072556949338712),
       INT64_C( 5343850217746646806),  INT64_C( 1510832219259344968), -INT64_C( 8409656248988139965), -INT64_C( 2529166160769564575),
       INT64_C(  585413799883150431),  INT64_C( 2009185803293969127),  INT64_C( 1498019392015748109),  INT64_C( 2876354059537035080),
       INT64_C( 4987765579163865200),  INT64_C( 7806978268448641124),  INT64_C( 7316227463546869185), -INT64_C( 3849630613523693915),
       INT64_C( 1049675890876387309),  INT64_C( 6579092312939996290),  INT64_C( 1457011716772592054), -INT64_C(  650185170795582506),
      -INT64_C( 6171388173621201501), -INT64_C(  329649782034553736),  INT64_C( 7662037574869728466), -INT64_C( 8308977580919564879),
       INT64_C( 4421184383379698313), -INT64_C( 7991149634287311144), -INT64_C( 6920581346883344393), -INT64_C( 5948400628738191363),
       INT64_C( 6340709283740404987),  INT64_C(   67991640294641056), -INT64_C( 1728394983992671371),  INT64_C( 7053271873660804113),
      -INT64_C( 7321689736351694451), -INT64_C( 2487979964495111826), -INT64_C( 7601720454943865682),  INT64_C( 2262969275684442272),
       INT64_C( 1838753615899822831),  INT64_C( 1706311658912185962), -INT64_C( 3303053658908659955), -INT64_C( 7983966649519115134),
       INT64_C( 6453376720001785802),  INT64_C( 3890504422801481597),  INT64_C( 7191670132874718920), -INT64_C( 5757382741507725595),
       INT64_C( 1176199900818674697),  INT64_C( 2247846347761155539), -INT64_C( 3465545294318732894),  INT64_C( 1307294077264813710),
      -INT64_C( 3483148397801944827),  INT64_C( 3914468739575947483), -INT64_C( 2112573789287322379),  INT64_C( 8942876136733804287),
       INT64_C( 6957990526189905603),  INT64_C( 5416111088994507359), -INT64_C( 8896621900140453039),  INT64_C( 2076906380317220575),
       INT64_C(  482567575987611854),  INT64_C( 8820337430196995526),  INT64_C( 5408445386645869318),  INT64_C( 1223979929794878342),
       INT64_C(  794908716072949851),  INT64_C( 3098072080187916634),  INT64_C( 5610011543425261091),  INT64_C( 5382128039334017886),
      -INT64_C( 8912530026821512191),  INT64_C( 3216984146614712407),  INT64_C( 8806954122281244965), -INT64_C( 8193230191089457902),
       INT64_C( 5011702565118974176), -INT64_C( 4480406955793279587),  INT64_C( 3987344995868511934),  INT64_C( 2046467378018545738) };
  static const int64_t e[] =
    {  INT64_C(                   0),  INT64_C( 7973217349290130000),  INT64_C( 1498059791836829473), -INT64_C( 5175156774547836989),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C( 7284318591210772125),  INT64_C(                   0),
      -INT64_C( 7376945628323843330),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 2928241527427111624),
       INT64_C(                   0),  INT64_C( 3651013581683325476),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C( 3049201854913900293),  INT64_C(  108901413299316739),  INT64_C( 4443654667110073013),
       INT64_C( 5308728349041871988),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 3939859960183503631),
       INT64_C(                   0), -INT64_C( 5856615950630888333),  INT64_C(                   0),  INT64_C( 2929303659240880045),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C( 3623358782304987445),  INT64_C( 8895439367502789458),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C( 4819963143524233909), -INT64_C( 8366216001544000656),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C( 6038297839484006555),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 3186308588674920252),
      -INT64_C( 2801473628957491993), -INT64_C( 3228330518034785087),  INT64_C( 2211275502010228801), -INT64_C( 3646980123018989225),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C( 2002414932797275728),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C( 2172383368863426116),  INT64_C(                   0),
       INT64_C(  965978959314380515), -INT64_C( 3387599119412427136),  INT64_C( 1892636550036524796),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(  173598620690624779),  INT64_C(                   0),  INT64_C( 2759347302623003563),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(  967793126265398725),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C( 5777047492122123942),  INT64_C(                   0),  INT64_C( 4161003397253219511),
      -INT64_C( 6811584503877472380),  INT64_C(                   0), -INT64_C( 3539313534631561250),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C( 3114847801138658644),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C( 3183090386669943747),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C( 1140558403792183021),  INT64_C(                   0), -INT64_C( 5848895432818178790),  INT64_C(                   0),
       INT64_C( 7581781665769083932),  INT64_C( 8016008582063959935),  INT64_C(                   0),  INT64_C( 5375941357854225063),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C( 3059149912654703986),  INT64_C( 1294473372241296204),  INT64_C(  695696739490556742),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C( 6348603305996726110),  INT64_C( 2934557444711241520),  INT64_C(                   0),
       INT64_C(  122671023455093322),  INT64_C(                   0), -INT64_C(  749319319931361283),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C( 2500695299524937330),  INT64_C(                   0),  INT64_C( 5431193005917438122) };

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
    rv = simde_svsub_s64_z(pv, av, bv);

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

    ev = simde_svsub_s64_z(pv, av, bv);

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
test_simde_svsub_s64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1) };
  static const int64_t a[] =
    { -INT64_C( 8294121167118735539),  INT64_C( 2307770508753316096), -INT64_C( 7321617021238448817),  INT64_C( 8333206487016340859),
      -INT64_C( 2832352024219059354),  INT64_C( 3948763965287108255),  INT64_C( 5438086452004154560), -INT64_C(  897057945737687309),
       INT64_C( 3687825304511323517), -INT64_C( 8217473044908606761),  INT64_C( 8084773311464769303),  INT64_C( 1040357427566514160),
       INT64_C( 3097227853971032372), -INT64_C( 7141058069350786422),  INT64_C( 2401180777183399780),  INT64_C( 2874158527127936068),
       INT64_C( 7067531928331569048),  INT64_C( 4604260854433185220),  INT64_C( 7008007964567038190), -INT64_C( 8761441989473935538),
       INT64_C(  547896828435191905), -INT64_C( 2261872498271234942),  INT64_C( 9015715177315744927), -INT64_C( 3488837883152870368),
       INT64_C( 1066124462254458496), -INT64_C( 1024279387565253386),  INT64_C( 3130226088432552388), -INT64_C( 2855617138734256352),
      -INT64_C(   40420206151244074), -INT64_C( 6357197132370748286),  INT64_C( 7039420064320877691), -INT64_C( 8040527621480453318),
      -INT64_C( 1243728603373238859), -INT64_C( 3185581675266202049), -INT64_C( 6151905618067626754), -INT64_C( 7836079876254953227),
      -INT64_C( 3096770556459928661),  INT64_C( 5971985668354066869),  INT64_C( 4197127548369451558), -INT64_C( 3660535748216849471),
       INT64_C( 5244699687245874269), -INT64_C( 6388014668646596428), -INT64_C( 2526945882478351760),  INT64_C( 6982460700131907832),
       INT64_C( 7570301065691974451),  INT64_C(  794263677953992156), -INT64_C( 5211317054933613899),  INT64_C(  858700819620440454),
       INT64_C( 4008734020447911554), -INT64_C( 7931513095244672441), -INT64_C( 2210406110263595811),  INT64_C( 6636991771415552824),
       INT64_C( 1667516933489356434),  INT64_C( 3509964729365412167),  INT64_C( 6831431936826414994),  INT64_C( 2268276601511622723),
      -INT64_C( 8476284383151780233), -INT64_C( 3427975726191781911), -INT64_C( 7134393017636668807),  INT64_C( 7813803581713836995),
      -INT64_C( 7633862306887861182), -INT64_C( 7460422653500474262), -INT64_C( 8975333484357208965), -INT64_C( 6844834405818356831),
       INT64_C( 3675840860100409024), -INT64_C( 7806618215754573839), -INT64_C( 5203390304267804282), -INT64_C( 6916595678058800125),
       INT64_C( 5765188472374372614), -INT64_C( 5363214104492188185), -INT64_C( 2974411147622745366),  INT64_C( 6692696862408312417),
      -INT64_C( 1867816273704063387),  INT64_C( 7561676257904391179),  INT64_C( 1232335588496632690), -INT64_C(  803272892139547864),
       INT64_C( 4613317921848428065), -INT64_C( 3087380943380681919), -INT64_C( 2659599111432859306), -INT64_C( 4824987305291191929),
      -INT64_C( 3409257287211171014), -INT64_C( 1439542654482306355), -INT64_C( 2677941572599668920), -INT64_C( 7147781734469193869),
       INT64_C( 6493552453295516349), -INT64_C( 6023687215340868123) };
  static const int64_t b[] =
    {  INT64_C( 4582571599147047273),  INT64_C( 3579433636678324980),  INT64_C( 7354578048263578194),  INT64_C( 7129469756477930418),
       INT64_C( 7631066399882274063),  INT64_C( 4030335625138024912), -INT64_C(  527749886314114685),  INT64_C( 8314832814218964489),
      -INT64_C( 7423338699345442275),  INT64_C( 1391124720544772145),  INT64_C( 7211115516232617173), -INT64_C( 5670372140144764042),
      -INT64_C( 7353182574132041580),  INT64_C( 7193372918912404015), -INT64_C( 6121921083860963766), -INT64_C( 3516515006981705491),
      -INT64_C( 1928349096634190276),  INT64_C( 3916858355324677482),  INT64_C( 6379601123599964583),  INT64_C( 2188762486639496790),
       INT64_C( 1665768556643650690), -INT64_C( 2085611668358773779),  INT64_C( 2668461736566188613),  INT64_C( 7950287020506931541),
       INT64_C(  317719378145974179),  INT64_C( 2929287971127195783),  INT64_C(  201220169771017685),  INT64_C( 4259437229211549889),
       INT64_C( 1063680226355823527),  INT64_C( 6807040793427156587), -INT64_C(  969174211450679076), -INT64_C(  279016099786209715),
       INT64_C(  726342462368033663),  INT64_C( 4108357480916575515),  INT64_C( 2324788502170043937),  INT64_C( 2262537233704018708),
      -INT64_C( 5153742375706287663), -INT64_C( 4128287219542797280), -INT64_C( 2640978799556593562),  INT64_C( 6196578724461502270),
       INT64_C( 9088897772249490636),  INT64_C( 5007915785603743508),  INT64_C( 3515860992732861992), -INT64_C( 8714169807843487945),
       INT64_C( 3030099111915410992), -INT64_C( 2181885470825052013),  INT64_C( 4979461726871238393),  INT64_C( 7416041231916018089),
      -INT64_C( 9067713144919040792),  INT64_C( 7540623846659132683), -INT64_C( 5028430539383408925),  INT64_C( 3689021261626620054),
       INT64_C( 3771583448157923301), -INT64_C( 2575884190931727256), -INT64_C( 7503553327170415852), -INT64_C( 1532185922200404930),
      -INT64_C( 5613149478904140100), -INT64_C( 4235694061424864414),  INT64_C( 5401724758551758430), -INT64_C( 6002014143315223868),
      -INT64_C( 1478961294855736451),  INT64_C( 3113534138213598143), -INT64_C( 6063391116738551932), -INT64_C( 4938713496487088421),
       INT64_C( 8364024213450918045),  INT64_C( 6626794890840070654), -INT64_C( 2464378283145592519),  INT64_C(  678951091717030259),
      -INT64_C( 1778848280622338521), -INT64_C( 8516965157300980325), -INT64_C( 1077637401520981973), -INT64_C(  564059561919335497),
       INT64_C( 4236802713839754492),  INT64_C( 5995551319017684826),  INT64_C(  838386776010776114),  INT64_C( 5695182516586955839),
       INT64_C( 6741608276728077750), -INT64_C( 1658384911368242304),  INT64_C( 5222269055080627481), -INT64_C( 5178750332240812161),
      -INT64_C( 2837377337340897729), -INT64_C(  327215886412699944), -INT64_C( 4085360487998877957),  INT64_C( 5207492714523371145),
      -INT64_C( 4160717001787289327),  INT64_C( 4444429691269661647) };
  static const int64_t e[] =
    { -INT64_C( 8294121167118735539),  INT64_C( 2307770508753316096),  INT64_C( 3770549004207524605),  INT64_C( 1203736730538410441),
       INT64_C( 7983325649608218199),  INT64_C( 3948763965287108255),  INT64_C( 5438086452004154560), -INT64_C(  897057945737687309),
      -INT64_C( 7335580069852785824),  INT64_C( 8838146308256172710),  INT64_C(  873657795232152130),  INT64_C( 6710729567711278202),
      -INT64_C( 7996333645606477664),  INT64_C( 4112313085446361179),  INT64_C( 8523101861044363546),  INT64_C( 6390673534109641559),
       INT64_C( 8995881024965759324),  INT64_C(  687402499108507738),  INT64_C( 7008007964567038190), -INT64_C( 8761441989473935538),
      -INT64_C( 1117871728208458785), -INT64_C(  176260829912461163),  INT64_C( 9015715177315744927), -INT64_C( 3488837883152870368),
       INT64_C( 1066124462254458496), -INT64_C( 1024279387565253386),  INT64_C( 3130226088432552388), -INT64_C( 2855617138734256352),
      -INT64_C(   40420206151244074), -INT64_C( 6357197132370748286),  INT64_C( 8008594275771556767), -INT64_C( 7761511521694243603),
      -INT64_C( 1243728603373238859), -INT64_C( 7293939156182777564), -INT64_C( 8476694120237670691),  INT64_C( 8348126963750579681),
       INT64_C( 2056971819246359002), -INT64_C( 8346471185812687467),  INT64_C( 6838106347926045120),  INT64_C( 8589629601031199875),
       INT64_C( 5244699687245874269),  INT64_C( 7050813619459211680), -INT64_C( 2526945882478351760), -INT64_C( 2750113565734155839),
       INT64_C( 7570301065691974451),  INT64_C( 2976149148779044169), -INT64_C( 5211317054933613899), -INT64_C( 6557340412295577635),
       INT64_C( 4008734020447911554), -INT64_C( 7931513095244672441), -INT64_C( 2210406110263595811),  INT64_C( 2947970509788932770),
       INT64_C( 1667516933489356434),  INT64_C( 6085848920297139423),  INT64_C( 6831431936826414994),  INT64_C( 3800462523712027653),
      -INT64_C( 8476284383151780233), -INT64_C( 3427975726191781911), -INT64_C( 7134393017636668807),  INT64_C( 7813803581713836995),
      -INT64_C( 6154901012032124731),  INT64_C( 7872787281995479211), -INT64_C( 2911942367618657033), -INT64_C( 1906120909331268410),
      -INT64_C( 4688183353350509021),  INT64_C( 4013330967114907123), -INT64_C( 2739012021122211763), -INT64_C( 6916595678058800125),
       INT64_C( 7544036752996711135),  INT64_C( 3153751052808792140), -INT64_C( 2974411147622745366),  INT64_C( 6692696862408312417),
      -INT64_C( 6104618987543817879),  INT64_C( 7561676257904391179),  INT64_C( 1232335588496632690), -INT64_C( 6498455408726503703),
       INT64_C( 4613317921848428065), -INT64_C( 1428996032012439615), -INT64_C( 7881868166513486787), -INT64_C( 4824987305291191929),
      -INT64_C(  571879949870273285), -INT64_C( 1439542654482306355),  INT64_C( 1407418915399209037),  INT64_C( 6091469624716986602),
       INT64_C( 6493552453295516349),  INT64_C( 7978627167099021846) };

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
    rv = simde_svsub_s64_m(pv, av, bv);

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

    ev = simde_svsub_s64_m(pv, av, bv);

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
test_simde_svsub_u8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) };
  static const uint8_t a[] =
    { UINT8_C(181), UINT8_C( 98), UINT8_C(188), UINT8_C(231), UINT8_C( 41), UINT8_C(139), UINT8_C(127), UINT8_C(179),
      UINT8_C( 23), UINT8_C( 45), UINT8_C(233), UINT8_C(213), UINT8_C(  8), UINT8_C(249), UINT8_C( 10), UINT8_C(110),
      UINT8_C(163), UINT8_C(  2), UINT8_C( 55), UINT8_C(121), UINT8_C( 53), UINT8_C( 63), UINT8_C(218), UINT8_C(106),
      UINT8_C(126), UINT8_C( 13), UINT8_C(118), UINT8_C(130), UINT8_C(254), UINT8_C(187), UINT8_C(223), UINT8_C(180),
      UINT8_C( 29), UINT8_C(156), UINT8_C(155), UINT8_C( 71), UINT8_C( 39), UINT8_C( 26), UINT8_C(250), UINT8_C( 62),
      UINT8_C( 71), UINT8_C(227), UINT8_C( 19), UINT8_C( 79), UINT8_C(221), UINT8_C( 30), UINT8_C(189), UINT8_C(128),
      UINT8_C( 32), UINT8_C(245), UINT8_C(249), UINT8_C( 85), UINT8_C( 52), UINT8_C(212), UINT8_C(191), UINT8_C(178),
      UINT8_C(225), UINT8_C( 53), UINT8_C( 52), UINT8_C(223), UINT8_C(241), UINT8_C( 20), UINT8_C(147), UINT8_C( 14),
      UINT8_C(176), UINT8_C( 46), UINT8_C( 85), UINT8_C(215), UINT8_C( 72), UINT8_C( 79), UINT8_C( 22), UINT8_C(143),
      UINT8_C( 51), UINT8_C( 41), UINT8_C(223), UINT8_C( 16), UINT8_C( 71), UINT8_C(156), UINT8_C(144), UINT8_C(103),
      UINT8_C(145), UINT8_C(138), UINT8_C(189), UINT8_C(197), UINT8_C( 94), UINT8_C(124), UINT8_C(119), UINT8_C( 63),
      UINT8_C(178), UINT8_C(172), UINT8_C( 30), UINT8_C(163), UINT8_C(192), UINT8_C(178), UINT8_C(177), UINT8_C(112),
      UINT8_C(224), UINT8_C(  7), UINT8_C( 71), UINT8_C( 41), UINT8_C( 86), UINT8_C( 93), UINT8_C(184), UINT8_C(137),
      UINT8_C(135), UINT8_C(151), UINT8_C(153), UINT8_C(206), UINT8_C( 52), UINT8_C( 42), UINT8_C( 54), UINT8_C(197),
      UINT8_C(180), UINT8_C(243), UINT8_C(139), UINT8_C( 18), UINT8_C(111), UINT8_C(  2), UINT8_C( 81), UINT8_C( 33),
      UINT8_C(174), UINT8_C(111), UINT8_C(196), UINT8_C(110), UINT8_C( 33), UINT8_C(118), UINT8_C(222), UINT8_C(  2),
      UINT8_C(125), UINT8_C( 38), UINT8_C( 43), UINT8_C(211), UINT8_C(131), UINT8_C(227), UINT8_C( 93), UINT8_C( 10),
      UINT8_C(123), UINT8_C(246), UINT8_C(217), UINT8_C(175), UINT8_C( 32), UINT8_C( 15), UINT8_C(116), UINT8_C(212),
      UINT8_C(  2),    UINT8_MAX, UINT8_C(230), UINT8_C(113), UINT8_C(  2), UINT8_C( 55), UINT8_C(147), UINT8_C(176),
      UINT8_C(167), UINT8_C( 87), UINT8_C( 31), UINT8_C(200), UINT8_C(205), UINT8_C(253), UINT8_C(202), UINT8_C( 74),
      UINT8_C( 35), UINT8_C(245), UINT8_C( 30), UINT8_C(167), UINT8_C(217), UINT8_C(123), UINT8_C(177), UINT8_C( 84),
      UINT8_C(113), UINT8_C(138), UINT8_C(  3), UINT8_C(146), UINT8_C(153), UINT8_C(119), UINT8_C(102), UINT8_C(155),
      UINT8_C(119), UINT8_C( 77), UINT8_C( 13), UINT8_C(121), UINT8_C(132), UINT8_C(160), UINT8_C( 41), UINT8_C( 43),
      UINT8_C(247), UINT8_C( 72), UINT8_C(244), UINT8_C(197), UINT8_C( 70), UINT8_C(190), UINT8_C( 15), UINT8_C(105),
      UINT8_C(180), UINT8_C( 45), UINT8_C( 16), UINT8_C(141), UINT8_C(168), UINT8_C(194), UINT8_C(225), UINT8_C( 26),
      UINT8_C( 76), UINT8_C(228), UINT8_C(172), UINT8_C(230), UINT8_C( 91), UINT8_C( 18), UINT8_C(129), UINT8_C(210),
      UINT8_C( 95), UINT8_C(142), UINT8_C( 75), UINT8_C(228), UINT8_C( 46), UINT8_C(117), UINT8_C( 15), UINT8_C( 38),
      UINT8_C(189), UINT8_C(  3), UINT8_C(235), UINT8_C(  3), UINT8_C(194), UINT8_C(250), UINT8_C(109), UINT8_C(118),
      UINT8_C( 40), UINT8_C(125), UINT8_C(  3), UINT8_C(208), UINT8_C( 63), UINT8_C(228), UINT8_C(234), UINT8_C(140),
      UINT8_C(200), UINT8_C(150), UINT8_C(114), UINT8_C( 35), UINT8_C(169), UINT8_C(243), UINT8_C(246), UINT8_C(  8),
      UINT8_C(130), UINT8_C( 65), UINT8_C(236), UINT8_C(176), UINT8_C(182), UINT8_C(252), UINT8_C(214), UINT8_C(116),
         UINT8_MAX, UINT8_C(193), UINT8_C(119), UINT8_C(193), UINT8_C(188), UINT8_C(228), UINT8_C( 55), UINT8_C(228),
      UINT8_C( 98), UINT8_C( 58), UINT8_C(180), UINT8_C(161), UINT8_C( 30), UINT8_C(159), UINT8_C( 45), UINT8_C(230),
      UINT8_C( 53), UINT8_C(159), UINT8_C( 10), UINT8_C(222), UINT8_C(147), UINT8_C(  0), UINT8_C(231), UINT8_C( 21),
      UINT8_C( 65), UINT8_C(211), UINT8_C(197), UINT8_C(248), UINT8_C(207), UINT8_C(156), UINT8_C(108), UINT8_C(207),
      UINT8_C( 93), UINT8_C(227), UINT8_C(144), UINT8_C( 25), UINT8_C(200), UINT8_C(200), UINT8_C(253), UINT8_C( 42),
      UINT8_C(  2), UINT8_C(178), UINT8_C(203), UINT8_C( 33), UINT8_C( 81), UINT8_C(249), UINT8_C(  7), UINT8_C(134),
      UINT8_C(152), UINT8_C( 17), UINT8_C(101), UINT8_C( 43), UINT8_C( 17), UINT8_C( 76), UINT8_C( 64), UINT8_C( 83),
      UINT8_C( 31), UINT8_C(  6), UINT8_C( 75), UINT8_C(239), UINT8_C(162), UINT8_C(183), UINT8_C(190),    UINT8_MAX,
      UINT8_C(154), UINT8_C( 78), UINT8_C( 25), UINT8_C( 98), UINT8_C( 22), UINT8_C( 22), UINT8_C(140), UINT8_C( 25),
      UINT8_C(200), UINT8_C( 88), UINT8_C( 58), UINT8_C( 25), UINT8_C( 81), UINT8_C( 65), UINT8_C(160), UINT8_C(233),
      UINT8_C( 83), UINT8_C(  5), UINT8_C( 21), UINT8_C(100), UINT8_C( 81), UINT8_C( 85), UINT8_C(183), UINT8_C(112),
      UINT8_C( 91), UINT8_C(  2), UINT8_C( 95), UINT8_C(253), UINT8_C(185), UINT8_C( 29), UINT8_C(253), UINT8_C( 84),
      UINT8_C(108), UINT8_C( 22), UINT8_C(182), UINT8_C(130), UINT8_C( 44), UINT8_C( 67), UINT8_C(155), UINT8_C(245),
      UINT8_C(155), UINT8_C(213), UINT8_C( 14), UINT8_C(236), UINT8_C( 23), UINT8_C(174), UINT8_C(213), UINT8_C(106),
      UINT8_C(179), UINT8_C(234), UINT8_C(206), UINT8_C(  4), UINT8_C( 64), UINT8_C(134), UINT8_C(117), UINT8_C(155),
      UINT8_C(136), UINT8_C(212), UINT8_C(153), UINT8_C( 66), UINT8_C(242), UINT8_C(150), UINT8_C(150), UINT8_C( 94),
      UINT8_C(172), UINT8_C( 76), UINT8_C(224), UINT8_C(216), UINT8_C(143), UINT8_C(124), UINT8_C(205), UINT8_C( 42),
      UINT8_C( 81), UINT8_C(220), UINT8_C( 22), UINT8_C(104), UINT8_C(138), UINT8_C(236), UINT8_C(210), UINT8_C( 62),
      UINT8_C(214), UINT8_C(161), UINT8_C( 66), UINT8_C( 22), UINT8_C( 39), UINT8_C(183), UINT8_C(178), UINT8_C(175),
      UINT8_C(140), UINT8_C( 75), UINT8_C(241), UINT8_C(126), UINT8_C(225), UINT8_C(135), UINT8_C(220), UINT8_C(141),
      UINT8_C(212), UINT8_C(188), UINT8_C(101), UINT8_C( 99), UINT8_C( 56), UINT8_C( 51), UINT8_C(142), UINT8_C(138),
      UINT8_C( 15), UINT8_C(164), UINT8_C(242), UINT8_C(153), UINT8_C(144), UINT8_C(197), UINT8_C(215), UINT8_C(103),
      UINT8_C(102), UINT8_C( 26), UINT8_C(125), UINT8_C(141), UINT8_C(209), UINT8_C( 47), UINT8_C( 60), UINT8_C( 93),
      UINT8_C(122), UINT8_C( 46), UINT8_C(219), UINT8_C( 91), UINT8_C(181), UINT8_C(183), UINT8_C(232), UINT8_C(137),
      UINT8_C(116), UINT8_C( 78), UINT8_C(237), UINT8_C(172), UINT8_C(129), UINT8_C(123), UINT8_C( 54), UINT8_C(144),
      UINT8_C( 31), UINT8_C( 41), UINT8_C( 41), UINT8_C(176), UINT8_C(238), UINT8_C(  1), UINT8_C( 23), UINT8_C( 84),
      UINT8_C( 27), UINT8_C(148), UINT8_C(225), UINT8_C(236), UINT8_C(196), UINT8_C( 29), UINT8_C( 74), UINT8_C( 62),
      UINT8_C( 75), UINT8_C( 37), UINT8_C(154), UINT8_C(  1), UINT8_C(221), UINT8_C(130), UINT8_C(138), UINT8_C( 81),
      UINT8_C(208), UINT8_C(119), UINT8_C(253), UINT8_C( 81), UINT8_C(242), UINT8_C( 52), UINT8_C(225), UINT8_C( 18),
      UINT8_C( 93), UINT8_C( 11), UINT8_C(194), UINT8_C( 75), UINT8_C( 12), UINT8_C(217), UINT8_C(159), UINT8_C( 39),
      UINT8_C(109), UINT8_C(128), UINT8_C( 19), UINT8_C( 49), UINT8_C(157), UINT8_C( 93), UINT8_C(112), UINT8_C(233),
      UINT8_C(131), UINT8_C( 10), UINT8_C(234), UINT8_C( 96), UINT8_C(140), UINT8_C(116), UINT8_C(177), UINT8_C( 93),
      UINT8_C(236), UINT8_C(174), UINT8_C(174), UINT8_C(222), UINT8_C(226), UINT8_C(144), UINT8_C(240), UINT8_C( 63),
      UINT8_C(155), UINT8_C(178), UINT8_C(138), UINT8_C(167), UINT8_C(139), UINT8_C( 41), UINT8_C(206), UINT8_C(249),
      UINT8_C(169), UINT8_C(225), UINT8_C( 42), UINT8_C( 71), UINT8_C( 63), UINT8_C(154), UINT8_C( 48), UINT8_C(194),
      UINT8_C(164), UINT8_C( 26), UINT8_C( 34), UINT8_C( 49), UINT8_C(142), UINT8_C(211), UINT8_C(142), UINT8_C(122),
      UINT8_C(129), UINT8_C( 60), UINT8_C( 89), UINT8_C(100), UINT8_C(204), UINT8_C( 73), UINT8_C(163), UINT8_C(103),
      UINT8_C(252), UINT8_C( 46), UINT8_C( 14), UINT8_C(135), UINT8_C( 87), UINT8_C(220), UINT8_C(128), UINT8_C(  1),
      UINT8_C(190), UINT8_C(171), UINT8_C( 72), UINT8_C(253), UINT8_C( 69), UINT8_C(120), UINT8_C(191), UINT8_C(234),
      UINT8_C(146), UINT8_C(225), UINT8_C( 27), UINT8_C( 32), UINT8_C(180), UINT8_C(169), UINT8_C(155), UINT8_C( 53),
      UINT8_C(229), UINT8_C(244), UINT8_C(153), UINT8_C(178), UINT8_C( 61), UINT8_C( 61), UINT8_C( 25), UINT8_C( 57),
      UINT8_C(107), UINT8_C( 40), UINT8_C(193), UINT8_C(194), UINT8_C(  4), UINT8_C( 65), UINT8_C(195), UINT8_C(194),
      UINT8_C(236), UINT8_C( 11), UINT8_C(191), UINT8_C( 50), UINT8_C(131), UINT8_C(126), UINT8_C( 28), UINT8_C( 21),
      UINT8_C( 95), UINT8_C( 55), UINT8_C( 54), UINT8_C( 19), UINT8_C(224), UINT8_C(209), UINT8_C( 73), UINT8_C(197),
      UINT8_C(197), UINT8_C(226), UINT8_C(119), UINT8_C(  2), UINT8_C( 31), UINT8_C(145), UINT8_C( 60), UINT8_C(138),
      UINT8_C(185), UINT8_C(253), UINT8_C( 77), UINT8_C(189), UINT8_C( 62), UINT8_C( 16), UINT8_C(128), UINT8_C( 43),
      UINT8_C( 28), UINT8_C( 63), UINT8_C( 93), UINT8_C(159), UINT8_C(190), UINT8_C(121), UINT8_C(181), UINT8_C( 29),
      UINT8_C(176), UINT8_C(235), UINT8_C( 49), UINT8_C(144), UINT8_C(188), UINT8_C(122), UINT8_C( 85), UINT8_C(129),
      UINT8_C( 92), UINT8_C(205), UINT8_C(131), UINT8_C(124), UINT8_C( 94), UINT8_C(191), UINT8_C(  6), UINT8_C( 23),
      UINT8_C(188), UINT8_C( 83), UINT8_C(212), UINT8_C(251), UINT8_C(100), UINT8_C( 84), UINT8_C( 38), UINT8_C(128),
      UINT8_C(148), UINT8_C(131), UINT8_C( 31), UINT8_C( 82), UINT8_C(252), UINT8_C(212), UINT8_C(111), UINT8_C(172),
      UINT8_C(191), UINT8_C(160), UINT8_C( 60), UINT8_C(123), UINT8_C( 26), UINT8_C(145), UINT8_C(252), UINT8_C(119),
      UINT8_C( 94), UINT8_C(128), UINT8_C(243), UINT8_C(188), UINT8_C( 63), UINT8_C(249), UINT8_C(211), UINT8_C(252),
      UINT8_C( 77), UINT8_C(168), UINT8_C(247), UINT8_C(177), UINT8_C(252), UINT8_C( 29), UINT8_C( 49), UINT8_C(144),
      UINT8_C(160), UINT8_C( 80), UINT8_C(226), UINT8_C(156), UINT8_C( 37), UINT8_C( 82), UINT8_C( 72), UINT8_C(228),
      UINT8_C(242), UINT8_C(132), UINT8_C( 96), UINT8_C( 13), UINT8_C( 21), UINT8_C( 92), UINT8_C(132), UINT8_C(116),
      UINT8_C(220), UINT8_C(119), UINT8_C( 48), UINT8_C( 28), UINT8_C(112), UINT8_C(  4), UINT8_C( 24), UINT8_C(189),
      UINT8_C(172), UINT8_C( 15), UINT8_C(110), UINT8_C(168), UINT8_C( 44), UINT8_C(159), UINT8_C( 57), UINT8_C(204),
      UINT8_C(240), UINT8_C( 27), UINT8_C(104), UINT8_C( 21), UINT8_C(109), UINT8_C(176), UINT8_C(249), UINT8_C( 96),
      UINT8_C( 52), UINT8_C( 89), UINT8_C(109), UINT8_C( 73), UINT8_C(182), UINT8_C(241), UINT8_C(189), UINT8_C(146),
      UINT8_C(104), UINT8_C(238), UINT8_C(174), UINT8_C(216), UINT8_C(242), UINT8_C(198), UINT8_C(150), UINT8_C(158),
      UINT8_C(213), UINT8_C(  4), UINT8_C( 70), UINT8_C(  1), UINT8_C(164), UINT8_C(127), UINT8_C(205), UINT8_C(148),
      UINT8_C(155), UINT8_C( 53), UINT8_C(169), UINT8_C(  8), UINT8_C(229), UINT8_C(162), UINT8_C(104), UINT8_C( 25),
      UINT8_C(252), UINT8_C(213), UINT8_C( 99), UINT8_C(178), UINT8_C(198), UINT8_C( 32), UINT8_C( 68), UINT8_C( 46),
      UINT8_C( 14), UINT8_C(243), UINT8_C(  7), UINT8_C(  0), UINT8_C(185), UINT8_C(157), UINT8_C(158), UINT8_C(143),
      UINT8_C(161), UINT8_C(229), UINT8_C(144), UINT8_C( 69), UINT8_C(100), UINT8_C( 94), UINT8_C(217),    UINT8_MAX,
      UINT8_C(147), UINT8_C(130), UINT8_C(  8), UINT8_C(121), UINT8_C( 37), UINT8_C(112), UINT8_C(146), UINT8_C( 33),
      UINT8_C( 70), UINT8_C(245), UINT8_C(211), UINT8_C( 12), UINT8_C( 22), UINT8_C( 23), UINT8_C( 59), UINT8_C( 36),
      UINT8_C( 10), UINT8_C( 66), UINT8_C( 37), UINT8_C(196), UINT8_C(223), UINT8_C(195), UINT8_C( 83), UINT8_C(128),
      UINT8_C(168), UINT8_C(227), UINT8_C(198), UINT8_C( 13), UINT8_C( 65), UINT8_C(159), UINT8_C( 12), UINT8_C(213),
      UINT8_C( 34), UINT8_C( 20), UINT8_C( 78), UINT8_C( 71), UINT8_C(133), UINT8_C(224), UINT8_C(104), UINT8_C(203) };
  static const uint8_t b[] =
    { UINT8_C( 16), UINT8_C( 27), UINT8_C( 89), UINT8_C(110), UINT8_C( 11), UINT8_C( 12), UINT8_C( 16), UINT8_C( 53),
      UINT8_C(129), UINT8_C(159), UINT8_C(158), UINT8_C( 46), UINT8_C( 41), UINT8_C(247), UINT8_C(  2), UINT8_C(127),
      UINT8_C(145), UINT8_C(176), UINT8_C( 61), UINT8_C( 73), UINT8_C(134), UINT8_C(106), UINT8_C(220), UINT8_C(150),
      UINT8_C( 95), UINT8_C(250), UINT8_C(143), UINT8_C(146), UINT8_C(184), UINT8_C(127), UINT8_C( 14), UINT8_C(200),
      UINT8_C(154), UINT8_C(104), UINT8_C( 54), UINT8_C(165), UINT8_C(116), UINT8_C( 70), UINT8_C(218), UINT8_C(245),
      UINT8_C(230), UINT8_C(121), UINT8_C( 35), UINT8_C( 15), UINT8_C(112), UINT8_C( 38), UINT8_C(143), UINT8_C(  1),
      UINT8_C(214), UINT8_C(204), UINT8_C( 74), UINT8_C( 92), UINT8_C( 54), UINT8_C( 39), UINT8_C(242), UINT8_C(150),
      UINT8_C( 33), UINT8_C(130), UINT8_C( 40), UINT8_C(218), UINT8_C(  1), UINT8_C( 54), UINT8_C(162), UINT8_C(155),
      UINT8_C(158), UINT8_C(217), UINT8_C( 64), UINT8_C( 19), UINT8_C( 31), UINT8_C( 26), UINT8_C(  8), UINT8_C(  5),
      UINT8_C(147), UINT8_C( 44), UINT8_C( 21), UINT8_C(  3), UINT8_C( 82), UINT8_C(164), UINT8_C(  4), UINT8_C( 40),
      UINT8_C(112), UINT8_C( 79), UINT8_C(132), UINT8_C(166), UINT8_C(118), UINT8_C(119), UINT8_C( 60), UINT8_C(151),
      UINT8_C(249), UINT8_C(100), UINT8_C(113), UINT8_C(250), UINT8_C(155), UINT8_C( 20), UINT8_C(149), UINT8_C( 57),
      UINT8_C(237), UINT8_C(213), UINT8_C( 76), UINT8_C( 12), UINT8_C(239), UINT8_C( 85), UINT8_C( 18), UINT8_C(131),
      UINT8_C(129), UINT8_C( 39), UINT8_C(134), UINT8_C(211), UINT8_C(203), UINT8_C(139), UINT8_C(251), UINT8_C( 59),
      UINT8_C(218), UINT8_C(127), UINT8_C(225), UINT8_C( 80), UINT8_C(246), UINT8_C( 30), UINT8_C(231), UINT8_C(239),
      UINT8_C(130), UINT8_C( 89), UINT8_C(233), UINT8_C( 29), UINT8_C(109), UINT8_C(126), UINT8_C( 87), UINT8_C( 90),
      UINT8_C( 83), UINT8_C(163), UINT8_C(102), UINT8_C( 67), UINT8_C(248), UINT8_C(120), UINT8_C(198), UINT8_C(121),
      UINT8_C(159), UINT8_C( 76), UINT8_C( 76), UINT8_C(106), UINT8_C(215), UINT8_C( 71), UINT8_C(165), UINT8_C(177),
      UINT8_C(199), UINT8_C(135), UINT8_C(  1), UINT8_C(189), UINT8_C(165), UINT8_C(233), UINT8_C(173), UINT8_C( 39),
      UINT8_C( 66), UINT8_C(150), UINT8_C( 69), UINT8_C(175), UINT8_C( 21), UINT8_C(156), UINT8_C(  9), UINT8_C(104),
      UINT8_C( 63), UINT8_C(111), UINT8_C(171), UINT8_C( 56), UINT8_C(232), UINT8_C(113), UINT8_C(177), UINT8_C(135),
      UINT8_C(190), UINT8_C(254), UINT8_C(242), UINT8_C(149), UINT8_C( 69), UINT8_C(151), UINT8_C( 71), UINT8_C( 12),
      UINT8_C( 30), UINT8_C( 72), UINT8_C(202), UINT8_C(195), UINT8_C( 49), UINT8_C(119), UINT8_C(235), UINT8_C(115),
      UINT8_C( 13), UINT8_C( 48), UINT8_C( 34), UINT8_C( 34), UINT8_C(204), UINT8_C( 43), UINT8_C(139), UINT8_C( 11),
      UINT8_C(155), UINT8_C( 54), UINT8_C( 67), UINT8_C(131), UINT8_C(168), UINT8_C(245), UINT8_C( 10), UINT8_C(102),
      UINT8_C(243), UINT8_C(252), UINT8_C(251), UINT8_C( 56), UINT8_C(148), UINT8_C( 66), UINT8_C( 69), UINT8_C(178),
      UINT8_C(139), UINT8_C( 15), UINT8_C(118), UINT8_C(188), UINT8_C(134), UINT8_C( 97), UINT8_C( 48), UINT8_C(147),
      UINT8_C(145), UINT8_C( 82), UINT8_C(182), UINT8_C( 93), UINT8_C(126), UINT8_C( 65), UINT8_C(104), UINT8_C( 25),
      UINT8_C(119), UINT8_C(172), UINT8_C(156), UINT8_C( 31), UINT8_C(161), UINT8_C(166), UINT8_C(133), UINT8_C(148),
      UINT8_C(163), UINT8_C(129), UINT8_C(204), UINT8_C( 55), UINT8_C(195), UINT8_C( 17), UINT8_C(233), UINT8_C( 78),
      UINT8_C( 32), UINT8_C( 95), UINT8_C( 11), UINT8_C(166), UINT8_C(192), UINT8_C( 59), UINT8_C( 58), UINT8_C( 81),
      UINT8_C(141), UINT8_C(240), UINT8_C(174), UINT8_C( 11), UINT8_C( 49), UINT8_C( 23), UINT8_C( 36), UINT8_C(168),
      UINT8_C(195), UINT8_C(192), UINT8_C(200), UINT8_C(100), UINT8_C(103), UINT8_C( 77), UINT8_C(248), UINT8_C( 10),
      UINT8_C(206), UINT8_C(196), UINT8_C( 65), UINT8_C(146), UINT8_C(214), UINT8_C( 42), UINT8_C(224), UINT8_C(246),
      UINT8_C(138), UINT8_C(235), UINT8_C(157), UINT8_C( 74), UINT8_C( 38), UINT8_C(215), UINT8_C(156), UINT8_C(180),
      UINT8_C(199), UINT8_C( 74), UINT8_C(191), UINT8_C(248), UINT8_C( 97), UINT8_C(228), UINT8_C(160), UINT8_C( 36),
      UINT8_C(164), UINT8_C(104), UINT8_C(136), UINT8_C( 11), UINT8_C(182), UINT8_C(128), UINT8_C( 21), UINT8_C(132),
      UINT8_C( 69), UINT8_C( 86), UINT8_C( 22), UINT8_C( 27), UINT8_C(129), UINT8_C(247), UINT8_C( 17), UINT8_C( 11),
      UINT8_C(226), UINT8_C(174), UINT8_C( 85), UINT8_C(  9), UINT8_C(133), UINT8_C(241), UINT8_C(189), UINT8_C( 76),
      UINT8_C( 60), UINT8_C(124), UINT8_C( 68), UINT8_C(157), UINT8_C( 96), UINT8_C(229), UINT8_C(194), UINT8_C(  5),
      UINT8_C( 77), UINT8_C( 74), UINT8_C( 16), UINT8_C(  3), UINT8_C(203), UINT8_C( 38), UINT8_C(136), UINT8_C( 16),
      UINT8_C(124), UINT8_C(158), UINT8_C( 43), UINT8_C(253), UINT8_C(149), UINT8_C( 60), UINT8_C(  8), UINT8_C(120),
      UINT8_C(235), UINT8_C( 94), UINT8_C(129), UINT8_C(112), UINT8_C( 79), UINT8_C( 62), UINT8_C(189), UINT8_C(139),
      UINT8_C(186), UINT8_C(  1), UINT8_C( 41), UINT8_C( 27), UINT8_C(230), UINT8_C(235), UINT8_C( 32), UINT8_C( 52),
      UINT8_C( 53), UINT8_C( 48), UINT8_C( 55), UINT8_C(  0), UINT8_C( 86), UINT8_C(191), UINT8_C( 16), UINT8_C(211),
      UINT8_C( 94), UINT8_C( 59), UINT8_C(208), UINT8_C(243), UINT8_C(120), UINT8_C(217), UINT8_C(107), UINT8_C( 99),
      UINT8_C( 55), UINT8_C(236), UINT8_C(211), UINT8_C(134), UINT8_C( 42), UINT8_C(144), UINT8_C( 18), UINT8_C(229),
      UINT8_C(146), UINT8_C( 59), UINT8_C(  0), UINT8_C(120), UINT8_C( 38), UINT8_C( 32), UINT8_C(172), UINT8_C( 91),
      UINT8_C( 80), UINT8_C(228), UINT8_C( 92), UINT8_C(167), UINT8_C(163), UINT8_C(108), UINT8_C(122), UINT8_C(  1),
      UINT8_C(168), UINT8_C( 74), UINT8_C(245), UINT8_C( 32), UINT8_C( 35), UINT8_C( 96), UINT8_C(131), UINT8_C( 90),
      UINT8_C( 77), UINT8_C( 86), UINT8_C(225), UINT8_C(119), UINT8_C(231), UINT8_C(243), UINT8_C( 92), UINT8_C(121),
      UINT8_C( 46), UINT8_C( 92), UINT8_C(241), UINT8_C( 84), UINT8_C(124), UINT8_C(158), UINT8_C(175), UINT8_C(205),
      UINT8_C(130), UINT8_C( 11), UINT8_C(116), UINT8_C( 37), UINT8_C(120), UINT8_C(238), UINT8_C( 39), UINT8_C( 32),
      UINT8_C( 56), UINT8_C( 28), UINT8_C( 64), UINT8_C( 92), UINT8_C(124), UINT8_C(195), UINT8_C(182), UINT8_C(201),
      UINT8_C( 25), UINT8_C(151), UINT8_C( 65), UINT8_C(  0), UINT8_C(138), UINT8_C(157), UINT8_C(121), UINT8_C(184),
      UINT8_C(250), UINT8_C(107), UINT8_C( 12), UINT8_C(118), UINT8_C(  9), UINT8_C(188), UINT8_C( 67), UINT8_C(139),
      UINT8_C(199), UINT8_C(183), UINT8_C(176), UINT8_C( 63), UINT8_C(165), UINT8_C(215), UINT8_C( 95), UINT8_C(222),
      UINT8_C(243), UINT8_C(159), UINT8_C( 58), UINT8_C(112), UINT8_C( 98), UINT8_C(240), UINT8_C( 57), UINT8_C(124),
      UINT8_C(136), UINT8_C(122), UINT8_C(124), UINT8_C( 18), UINT8_C( 24), UINT8_C(246), UINT8_C(203), UINT8_C( 18),
      UINT8_C( 97), UINT8_C(215), UINT8_C(136), UINT8_C(106), UINT8_C(147), UINT8_C(204), UINT8_C(245), UINT8_C( 91),
      UINT8_C(131), UINT8_C(165), UINT8_C(154), UINT8_C( 41), UINT8_C(125), UINT8_C(250), UINT8_C(  7), UINT8_C(112),
      UINT8_C(153), UINT8_C( 65), UINT8_C(224), UINT8_C(252), UINT8_C( 49), UINT8_C( 26), UINT8_C(120), UINT8_C(185),
      UINT8_C(148), UINT8_C(244), UINT8_C(204), UINT8_C(172), UINT8_C(234), UINT8_C(151), UINT8_C(190), UINT8_C( 75),
      UINT8_C(110), UINT8_C( 71), UINT8_C(181), UINT8_C(  2), UINT8_C( 19), UINT8_C(170), UINT8_C( 93), UINT8_C(150),
      UINT8_C( 80), UINT8_C(247), UINT8_C(191), UINT8_C(205), UINT8_C(241), UINT8_C(198), UINT8_C( 61), UINT8_C(139),
      UINT8_C(  7), UINT8_C( 30), UINT8_C(135), UINT8_C( 57), UINT8_C( 56),    UINT8_MAX, UINT8_C(242), UINT8_C(204),
      UINT8_C(243), UINT8_C(190), UINT8_C(121), UINT8_C(222), UINT8_C( 85), UINT8_C( 55), UINT8_C( 41), UINT8_C(196),
      UINT8_C(126), UINT8_C(223), UINT8_C(198), UINT8_C(145), UINT8_C(137), UINT8_C( 35), UINT8_C( 40), UINT8_C(217),
      UINT8_C( 26), UINT8_C(231), UINT8_C(166), UINT8_C( 12), UINT8_C(174), UINT8_C(228), UINT8_C(151), UINT8_C(181),
      UINT8_C(  2), UINT8_C( 30), UINT8_C(238), UINT8_C( 58), UINT8_C( 29), UINT8_C(225), UINT8_C(  6), UINT8_C( 16),
      UINT8_C(159), UINT8_C(127), UINT8_C(238), UINT8_C(245), UINT8_C(183), UINT8_C( 24), UINT8_C(185), UINT8_C( 53),
      UINT8_C(247), UINT8_C(127), UINT8_C(199), UINT8_C(128), UINT8_C(162), UINT8_C(239), UINT8_C( 90), UINT8_C(188),
      UINT8_C(214), UINT8_C(  0), UINT8_C(200), UINT8_C(132), UINT8_C(228), UINT8_C( 95), UINT8_C( 58), UINT8_C(230),
      UINT8_C(125), UINT8_C( 40), UINT8_C( 32), UINT8_C(154), UINT8_C(  9), UINT8_C( 39), UINT8_C(171), UINT8_C(169),
      UINT8_C(166), UINT8_C(153), UINT8_C(158), UINT8_C( 93), UINT8_C(177), UINT8_C( 87), UINT8_C(147), UINT8_C(168),
      UINT8_C(214), UINT8_C( 90), UINT8_C( 41), UINT8_C(120), UINT8_C( 73), UINT8_C(131), UINT8_C( 52), UINT8_C( 31),
      UINT8_C(131), UINT8_C(253), UINT8_C(164), UINT8_C(104), UINT8_C( 92), UINT8_C(222), UINT8_C( 78), UINT8_C(218),
      UINT8_C(  6), UINT8_C(111), UINT8_C(116), UINT8_C( 16), UINT8_C(150), UINT8_C( 31), UINT8_C(185), UINT8_C( 60),
      UINT8_C(185), UINT8_C( 87), UINT8_C(154), UINT8_C(106), UINT8_C(174), UINT8_C( 45), UINT8_C( 19), UINT8_C(132),
      UINT8_C(135), UINT8_C( 60), UINT8_C(252), UINT8_C(208), UINT8_C(191), UINT8_C( 48), UINT8_C(239), UINT8_C( 66),
      UINT8_C( 45), UINT8_C(147), UINT8_C(170), UINT8_C(138), UINT8_C(113), UINT8_C(249), UINT8_C(100), UINT8_C(120),
      UINT8_C(104), UINT8_C(216), UINT8_C(136), UINT8_C(254), UINT8_C(248), UINT8_C( 65), UINT8_C( 58), UINT8_C(177),
      UINT8_C(152), UINT8_C(212), UINT8_C( 27), UINT8_C( 70), UINT8_C(  1), UINT8_C( 46), UINT8_C(202), UINT8_C(136),
      UINT8_C(106), UINT8_C(198), UINT8_C( 88), UINT8_C( 41), UINT8_C(246), UINT8_C( 72), UINT8_C(108), UINT8_C( 36),
      UINT8_C(219), UINT8_C( 22), UINT8_C(174), UINT8_C( 77), UINT8_C( 15), UINT8_C( 18), UINT8_C(197), UINT8_C(119),
      UINT8_C(234), UINT8_C( 77), UINT8_C(117), UINT8_C(226), UINT8_C(142), UINT8_C(176), UINT8_C(147), UINT8_C( 38),
      UINT8_C(132), UINT8_C(175), UINT8_C(108), UINT8_C(134), UINT8_C(221), UINT8_C( 54), UINT8_C( 14), UINT8_C( 72),
      UINT8_C(252), UINT8_C(103), UINT8_C(113), UINT8_C(242), UINT8_C(175), UINT8_C(221), UINT8_C( 22), UINT8_C(138),
      UINT8_C(244), UINT8_C(196), UINT8_C(215), UINT8_C(  3), UINT8_C(214), UINT8_C(156), UINT8_C(123), UINT8_C(193),
      UINT8_C(233), UINT8_C(240), UINT8_C(163), UINT8_C(119), UINT8_C(160), UINT8_C( 55), UINT8_C(157), UINT8_C( 37),
      UINT8_C(230), UINT8_C(  9), UINT8_C(171), UINT8_C(195), UINT8_C( 63), UINT8_C(185), UINT8_C( 11), UINT8_C( 59),
      UINT8_C( 32), UINT8_C(125), UINT8_C( 46), UINT8_C(207), UINT8_C( 90), UINT8_C( 68), UINT8_C( 90), UINT8_C( 78),
      UINT8_C(  9), UINT8_C( 49), UINT8_C( 82), UINT8_C(223), UINT8_C(206), UINT8_C(205), UINT8_C(160), UINT8_C(183),
      UINT8_C(189), UINT8_C( 68), UINT8_C( 47), UINT8_C( 94), UINT8_C(123), UINT8_C(204), UINT8_C(131), UINT8_C( 97),
      UINT8_C(214), UINT8_C( 46), UINT8_C( 36), UINT8_C( 21), UINT8_C(231), UINT8_C( 48), UINT8_C( 81), UINT8_C(  8),
      UINT8_C(173), UINT8_C(127), UINT8_C(215), UINT8_C(  7), UINT8_C(195), UINT8_C( 49), UINT8_C( 86), UINT8_C(204),
      UINT8_C( 99), UINT8_C(168), UINT8_C(172), UINT8_C( 49), UINT8_C(117), UINT8_C( 76), UINT8_C(232), UINT8_C( 50),
      UINT8_C(144), UINT8_C( 23), UINT8_C(144), UINT8_C( 11), UINT8_C(228), UINT8_C( 19), UINT8_C(108), UINT8_C(186),
      UINT8_C( 65), UINT8_C(145), UINT8_C(207), UINT8_C( 41), UINT8_C(193), UINT8_C( 32), UINT8_C( 49), UINT8_C(110),
      UINT8_C(159), UINT8_C(  8), UINT8_C(117), UINT8_C( 99), UINT8_C( 58), UINT8_C(203), UINT8_C( 47), UINT8_C(157),
      UINT8_C(115), UINT8_C(219), UINT8_C(206), UINT8_C(232), UINT8_C( 40), UINT8_C(182), UINT8_C( 27), UINT8_C(184),
      UINT8_C(206), UINT8_C(171), UINT8_C(196), UINT8_C(178), UINT8_C(191), UINT8_C( 48), UINT8_C(108), UINT8_C(  0) };
  static const uint8_t e[] =
    { UINT8_C(165), UINT8_C( 71), UINT8_C( 99), UINT8_C(121), UINT8_C( 30), UINT8_C(  0), UINT8_C(  0), UINT8_C(126),
      UINT8_C(150), UINT8_C(  0), UINT8_C( 75), UINT8_C(167), UINT8_C(223), UINT8_C(  0), UINT8_C(  8), UINT8_C(239),
      UINT8_C( 18), UINT8_C( 82), UINT8_C(  0), UINT8_C( 48), UINT8_C(  0), UINT8_C(213), UINT8_C(254), UINT8_C(  0),
      UINT8_C( 31), UINT8_C( 19), UINT8_C(  0), UINT8_C(240), UINT8_C( 70), UINT8_C(  0), UINT8_C(209), UINT8_C(236),
      UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(162), UINT8_C(  0), UINT8_C(212), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 97), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C(  0), UINT8_C(248), UINT8_C(  0), UINT8_C(127),
      UINT8_C(  0), UINT8_C( 41), UINT8_C(175), UINT8_C(249), UINT8_C(  0), UINT8_C(  0), UINT8_C(205), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(179), UINT8_C(  0), UINT8_C(  5), UINT8_C(  0), UINT8_C(222), UINT8_C(  0), UINT8_C(115),
      UINT8_C(  0), UINT8_C( 85), UINT8_C(  0), UINT8_C(196), UINT8_C(  0), UINT8_C(  0), UINT8_C( 14), UINT8_C(  0),
      UINT8_C(160), UINT8_C(253), UINT8_C(  0), UINT8_C( 13), UINT8_C(245), UINT8_C(  0), UINT8_C(140), UINT8_C(  0),
      UINT8_C( 33), UINT8_C(  0), UINT8_C( 57), UINT8_C(  0), UINT8_C(232), UINT8_C(  0), UINT8_C(  0), UINT8_C(168),
      UINT8_C(  0), UINT8_C( 72), UINT8_C(173), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 28), UINT8_C( 55),
      UINT8_C(243), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(103), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  6), UINT8_C(  0), UINT8_C( 19), UINT8_C(251), UINT8_C(105), UINT8_C(159), UINT8_C( 59), UINT8_C(138),
      UINT8_C(218), UINT8_C(  0), UINT8_C(170), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 50),
      UINT8_C(  0), UINT8_C( 22), UINT8_C(219), UINT8_C(  0), UINT8_C(180), UINT8_C(248), UINT8_C(135), UINT8_C(168),
      UINT8_C( 42), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(107), UINT8_C(151), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(170), UINT8_C(141), UINT8_C( 69), UINT8_C(  0), UINT8_C(  0), UINT8_C(207), UINT8_C(  0),
      UINT8_C( 59), UINT8_C(120), UINT8_C(229), UINT8_C(180), UINT8_C(  0), UINT8_C( 78), UINT8_C(230), UINT8_C(  0),
      UINT8_C(101), UINT8_C(193), UINT8_C(  0), UINT8_C( 25), UINT8_C(  0), UINT8_C(  0), UINT8_C(193), UINT8_C(  0),
      UINT8_C(228), UINT8_C(134), UINT8_C(115), UINT8_C(111), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(140), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(224), UINT8_C(  0), UINT8_C(143),
      UINT8_C(  0), UINT8_C(  5), UINT8_C( 67), UINT8_C(  0), UINT8_C( 83), UINT8_C( 41), UINT8_C(  0), UINT8_C(184),
      UINT8_C(  0), UINT8_C( 24), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(132), UINT8_C(  0),
      UINT8_C( 25), UINT8_C(  0), UINT8_C(205), UINT8_C( 10), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(180),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 32),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(213), UINT8_C(  0), UINT8_C(168), UINT8_C(  0), UINT8_C(  0), UINT8_C(147),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(166), UINT8_C(  0), UINT8_C(185), UINT8_C(  5), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(209), UINT8_C(  0), UINT8_C(  0), UINT8_C(158), UINT8_C(  0), UINT8_C(  0), UINT8_C(248),
      UINT8_C( 37), UINT8_C(  0), UINT8_C(  0), UINT8_C(236), UINT8_C(230), UINT8_C(  0), UINT8_C( 13), UINT8_C(  0),
      UINT8_C( 98), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(246), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(114), UINT8_C(209), UINT8_C(201), UINT8_C(  0), UINT8_C(139), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(159), UINT8_C(122), UINT8_C(  0), UINT8_C(  0), UINT8_C(183), UINT8_C(  0), UINT8_C(  0), UINT8_C(220),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(201), UINT8_C(  0), UINT8_C(189), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(183), UINT8_C(  0), UINT8_C( 40), UINT8_C(174), UINT8_C(169), UINT8_C(  0), UINT8_C(208), UINT8_C( 27),
      UINT8_C(150), UINT8_C(  0), UINT8_C(209), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 94), UINT8_C( 74), UINT8_C(  0), UINT8_C( 22), UINT8_C(155), UINT8_C(121), UINT8_C(242), UINT8_C(  0),
      UINT8_C( 83), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(144), UINT8_C( 85), UINT8_C( 47), UINT8_C(  0),
      UINT8_C( 61), UINT8_C( 88), UINT8_C(246), UINT8_C(230), UINT8_C( 29), UINT8_C(  0), UINT8_C(  0), UINT8_C(179),
      UINT8_C( 94), UINT8_C(  0), UINT8_C(  0), UINT8_C(197), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(134), UINT8_C(  0), UINT8_C(  0), UINT8_C(217),
      UINT8_C(  0), UINT8_C(103), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(175), UINT8_C(  0),
      UINT8_C(112), UINT8_C(  0), UINT8_C(  0), UINT8_C(141), UINT8_C(106), UINT8_C(  0), UINT8_C(  0), UINT8_C(201),
      UINT8_C(  0), UINT8_C( 21), UINT8_C(141), UINT8_C(103), UINT8_C( 70), UINT8_C( 88), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(102), UINT8_C(165), UINT8_C(  0), UINT8_C(236), UINT8_C(193), UINT8_C(239), UINT8_C(197), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(175), UINT8_C(  0), UINT8_C( 17), UINT8_C(  0), UINT8_C(173), UINT8_C(  0), UINT8_C( 56),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(198), UINT8_C(  0), UINT8_C(200), UINT8_C(  0), UINT8_C(132), UINT8_C(  0),
      UINT8_C( 26), UINT8_C(  0), UINT8_C(224), UINT8_C( 96), UINT8_C(105), UINT8_C(  0), UINT8_C( 33), UINT8_C(207),
      UINT8_C(  1), UINT8_C(248), UINT8_C(186), UINT8_C(193), UINT8_C(  0), UINT8_C(128), UINT8_C( 88), UINT8_C( 61),
      UINT8_C( 46), UINT8_C(  0), UINT8_C( 77), UINT8_C(246), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 85),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 16), UINT8_C(  0), UINT8_C(  0), UINT8_C(148), UINT8_C(  0), UINT8_C( 20),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(149), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(141), UINT8_C(153), UINT8_C(126), UINT8_C(116), UINT8_C( 24), UINT8_C(215), UINT8_C(176), UINT8_C(  0),
      UINT8_C( 46), UINT8_C(  0), UINT8_C( 61), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(134), UINT8_C(148),
      UINT8_C(  0), UINT8_C(151), UINT8_C(154), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(111), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(225), UINT8_C(  0), UINT8_C(120), UINT8_C(191), UINT8_C(243), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 42), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(245), UINT8_C(  0), UINT8_C(124), UINT8_C(  0), UINT8_C( 45), UINT8_C( 17), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(171), UINT8_C( 30), UINT8_C(239), UINT8_C(197), UINT8_C(140), UINT8_C(  0), UINT8_C( 63),
      UINT8_C(111), UINT8_C(160), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(104), UINT8_C(236), UINT8_C(183),
      UINT8_C(  0), UINT8_C(102), UINT8_C( 40), UINT8_C(  0), UINT8_C(143), UINT8_C(223), UINT8_C(152), UINT8_C(183),
      UINT8_C(212), UINT8_C( 63), UINT8_C( 51), UINT8_C( 53), UINT8_C(108), UINT8_C(  0), UINT8_C(  0), UINT8_C( 48),
      UINT8_C(239), UINT8_C( 22), UINT8_C( 30), UINT8_C(180), UINT8_C(162), UINT8_C(221), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(103), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(147), UINT8_C(169),
      UINT8_C( 75), UINT8_C(187), UINT8_C(203), UINT8_C(218), UINT8_C(154), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 14), UINT8_C(  7), UINT8_C(155), UINT8_C( 62), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 83), UINT8_C( 57), UINT8_C(  0), UINT8_C(  0), UINT8_C(182),
      UINT8_C(  3), UINT8_C( 93), UINT8_C(  0), UINT8_C(  0), UINT8_C( 67), UINT8_C(  0), UINT8_C(123), UINT8_C(142),
      UINT8_C(226), UINT8_C( 71), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(248), UINT8_C(233), UINT8_C(  0),
      UINT8_C(188), UINT8_C(  0), UINT8_C( 90), UINT8_C(  0), UINT8_C( 40), UINT8_C(151), UINT8_C(185), UINT8_C(  0),
      UINT8_C(243), UINT8_C( 98), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(238), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(155), UINT8_C( 78), UINT8_C(  0), UINT8_C(125),
      UINT8_C(149), UINT8_C(  0), UINT8_C(  0), UINT8_C( 62), UINT8_C( 32), UINT8_C(226), UINT8_C(137), UINT8_C(220),
      UINT8_C(111), UINT8_C(227), UINT8_C(159), UINT8_C(  0), UINT8_C(  0), UINT8_C( 87), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(158), UINT8_C(  0), UINT8_C(182), UINT8_C( 47), UINT8_C(122), UINT8_C(182), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(136), UINT8_C( 78), UINT8_C(138), UINT8_C(214), UINT8_C( 14), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 85), UINT8_C(  0), UINT8_C( 50), UINT8_C( 50), UINT8_C( 81),
      UINT8_C( 22), UINT8_C(208), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 90), UINT8_C(  0), UINT8_C(225),
      UINT8_C(  0), UINT8_C(148), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(213), UINT8_C(  0), UINT8_C(135), UINT8_C(172), UINT8_C(159), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 42), UINT8_C(113), UINT8_C(  0), UINT8_C( 91), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(171), UINT8_C(  0), UINT8_C(  0), UINT8_C(  4), UINT8_C(  0), UINT8_C( 53), UINT8_C(251),
      UINT8_C( 39), UINT8_C(  0), UINT8_C( 33), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(216),
      UINT8_C(114), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(237), UINT8_C( 11), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(182), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(151), UINT8_C(  0), UINT8_C(  0), UINT8_C(190),
      UINT8_C(  0), UINT8_C(213), UINT8_C(244), UINT8_C(135), UINT8_C(  0), UINT8_C( 38), UINT8_C(118), UINT8_C( 44),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 42), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(184), UINT8_C( 75), UINT8_C(  0), UINT8_C(165), UINT8_C( 86), UINT8_C(  0), UINT8_C(190), UINT8_C(  0),
      UINT8_C(  7), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 59),
      UINT8_C(  0), UINT8_C( 80), UINT8_C(194), UINT8_C(134), UINT8_C(119), UINT8_C(  0), UINT8_C(  0), UINT8_C( 87),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  9), UINT8_C(152), UINT8_C(130), UINT8_C(  0), UINT8_C( 80),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 34), UINT8_C(214), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(222), UINT8_C(  0), UINT8_C(122), UINT8_C(170), UINT8_C(106), UINT8_C(214), UINT8_C(229), UINT8_C(  0),
      UINT8_C( 38), UINT8_C(  0), UINT8_C( 63), UINT8_C(  0), UINT8_C(223), UINT8_C(240), UINT8_C(243), UINT8_C(  0),
      UINT8_C( 97), UINT8_C(116), UINT8_C( 48), UINT8_C(249), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(195),
      UINT8_C(  0), UINT8_C( 61), UINT8_C(228), UINT8_C(  0), UINT8_C(  0), UINT8_C( 18), UINT8_C(241), UINT8_C(205),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(110), UINT8_C(  0), UINT8_C(  0), UINT8_C( 38), UINT8_C(103),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  4), UINT8_C(  0), UINT8_C(  0), UINT8_C(247), UINT8_C(  0), UINT8_C(182),
      UINT8_C(107), UINT8_C(  0), UINT8_C(176), UINT8_C(  0), UINT8_C(  0), UINT8_C(248), UINT8_C( 36), UINT8_C(227),
      UINT8_C(  0), UINT8_C(  8), UINT8_C(248), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(241), UINT8_C(  0),
      UINT8_C( 84), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(198), UINT8_C(  0), UINT8_C(252), UINT8_C(203) };

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
    rv = simde_svsub_u8_z(pv, av, bv);

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

    ev = simde_svsub_u8_z(pv, av, bv);

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
test_simde_svsub_u8_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1) };
  static const uint8_t a[] =
    { UINT8_C(155), UINT8_C( 89), UINT8_C( 25), UINT8_C(142), UINT8_C( 44), UINT8_C(227), UINT8_C(194), UINT8_C(122),
      UINT8_C( 33), UINT8_C(132), UINT8_C(120), UINT8_C(  7), UINT8_C(224), UINT8_C( 33), UINT8_C(154), UINT8_C(158),
      UINT8_C(216), UINT8_C( 14), UINT8_C(116), UINT8_C(137), UINT8_C(182), UINT8_C(138), UINT8_C( 18), UINT8_C( 94),
      UINT8_C(247), UINT8_C( 71), UINT8_C(219), UINT8_C( 58),    UINT8_MAX, UINT8_C(137), UINT8_C(205), UINT8_C(154),
      UINT8_C(226), UINT8_C(230), UINT8_C( 40), UINT8_C( 14), UINT8_C(202), UINT8_C(235), UINT8_C(137), UINT8_C(235),
      UINT8_C(111), UINT8_C(  1), UINT8_C(242), UINT8_C( 79), UINT8_C( 34), UINT8_C(140), UINT8_C(237), UINT8_C(250),
      UINT8_C(155), UINT8_C( 97), UINT8_C(132), UINT8_C( 81), UINT8_C(236), UINT8_C(150), UINT8_C(175), UINT8_C(227),
      UINT8_C(221), UINT8_C(139), UINT8_C( 29), UINT8_C(220), UINT8_C( 20), UINT8_C(234), UINT8_C(118), UINT8_C(246),
      UINT8_C(209), UINT8_C(159), UINT8_C(  4), UINT8_C(155), UINT8_C(138), UINT8_C(141), UINT8_C(134), UINT8_C(249),
      UINT8_C(142), UINT8_C(120), UINT8_C( 72), UINT8_C(176), UINT8_C(  4), UINT8_C( 53), UINT8_C(171), UINT8_C(159),
      UINT8_C(150), UINT8_C( 47), UINT8_C(241), UINT8_C(130), UINT8_C(197), UINT8_C(160), UINT8_C(102), UINT8_C(162),
      UINT8_C( 43), UINT8_C(131), UINT8_C(126), UINT8_C( 63), UINT8_C(110), UINT8_C(244), UINT8_C( 53), UINT8_C( 63),
      UINT8_C(147), UINT8_C( 58), UINT8_C(218), UINT8_C( 29), UINT8_C(199), UINT8_C( 96), UINT8_C( 22), UINT8_C( 86),
      UINT8_C(216), UINT8_C( 94), UINT8_C(  6), UINT8_C(220), UINT8_C(147), UINT8_C(177), UINT8_C(124), UINT8_C( 42),
      UINT8_C(224), UINT8_C(109), UINT8_C(172), UINT8_C(165), UINT8_C( 13), UINT8_C( 18), UINT8_C( 71), UINT8_C( 57),
      UINT8_C(150), UINT8_C(197), UINT8_C(120), UINT8_C(  4), UINT8_C(186), UINT8_C(174), UINT8_C( 67), UINT8_C( 77),
      UINT8_C(232), UINT8_C( 29), UINT8_C(107), UINT8_C(175), UINT8_C(125), UINT8_C(129), UINT8_C(  5), UINT8_C( 85),
      UINT8_C(224), UINT8_C( 12), UINT8_C( 49), UINT8_C(115), UINT8_C(189), UINT8_C(173), UINT8_C(157), UINT8_C(158),
      UINT8_C( 26), UINT8_C( 74), UINT8_C( 67), UINT8_C( 40), UINT8_C( 92), UINT8_C(139), UINT8_C( 97), UINT8_C(242),
      UINT8_C( 80), UINT8_C(217), UINT8_C(246), UINT8_C( 10), UINT8_C(135), UINT8_C( 57), UINT8_C( 88), UINT8_C(111),
      UINT8_C( 86), UINT8_C(195), UINT8_C( 31), UINT8_C(211), UINT8_C( 68), UINT8_C( 36), UINT8_C( 40), UINT8_C( 36),
      UINT8_C( 48), UINT8_C( 90), UINT8_C(152), UINT8_C(238), UINT8_C(  7), UINT8_C( 53), UINT8_C(140), UINT8_C( 34),
      UINT8_C(127), UINT8_C(207), UINT8_C( 74), UINT8_C(220), UINT8_C( 90), UINT8_C(171), UINT8_C(206), UINT8_C(171),
      UINT8_C(132), UINT8_C(197), UINT8_C(181), UINT8_C( 12), UINT8_C(254), UINT8_C( 13), UINT8_C(123), UINT8_C( 85),
      UINT8_C(208), UINT8_C(154), UINT8_C( 40), UINT8_C( 21), UINT8_C(191), UINT8_C( 81), UINT8_C( 57), UINT8_C(239),
      UINT8_C(171), UINT8_C(209), UINT8_C(221), UINT8_C(178), UINT8_C(  7), UINT8_C(105), UINT8_C(212), UINT8_C(134),
      UINT8_C( 57), UINT8_C( 30), UINT8_C( 98), UINT8_C(147), UINT8_C(201), UINT8_C( 49), UINT8_C( 62), UINT8_C( 78),
      UINT8_C(246), UINT8_C(244), UINT8_C( 90), UINT8_C(244), UINT8_C(  1), UINT8_C(213), UINT8_C( 73), UINT8_C(210),
      UINT8_C(112), UINT8_C(114), UINT8_C(231), UINT8_C( 47), UINT8_C(195), UINT8_C( 32), UINT8_C( 30), UINT8_C(110),
      UINT8_C(242), UINT8_C(252), UINT8_C( 32), UINT8_C(249), UINT8_C(101), UINT8_C(245), UINT8_C(127), UINT8_C(158),
      UINT8_C( 19), UINT8_C(226), UINT8_C( 50), UINT8_C(221), UINT8_C( 19), UINT8_C(112), UINT8_C( 43), UINT8_C(  9),
      UINT8_C(100), UINT8_C(133), UINT8_C(253), UINT8_C(102), UINT8_C( 90), UINT8_C( 71), UINT8_C( 56), UINT8_C(202),
      UINT8_C(185), UINT8_C( 31), UINT8_C(249), UINT8_C(124), UINT8_C( 63), UINT8_C( 24), UINT8_C(234), UINT8_C( 49),
      UINT8_C( 20), UINT8_C( 10), UINT8_C( 42), UINT8_C(121),    UINT8_MAX, UINT8_C(170), UINT8_C( 24), UINT8_C( 19),
      UINT8_C(140), UINT8_C( 74), UINT8_C(240), UINT8_C(159), UINT8_C(186), UINT8_C( 27), UINT8_C(168), UINT8_C( 31),
      UINT8_C(160), UINT8_C(165), UINT8_C(133), UINT8_C(250), UINT8_C(236), UINT8_C(189), UINT8_C(197), UINT8_C(165),
      UINT8_C(220), UINT8_C(190), UINT8_C( 33), UINT8_C( 27), UINT8_C(214), UINT8_C( 11), UINT8_C( 77), UINT8_C(234),
      UINT8_C( 22), UINT8_C(119), UINT8_C(100), UINT8_C( 21), UINT8_C( 33), UINT8_C(124), UINT8_C( 40), UINT8_C(173),
      UINT8_C(198), UINT8_C( 24), UINT8_C( 76), UINT8_C(128), UINT8_C( 51), UINT8_C(244), UINT8_C(159), UINT8_C(211),
      UINT8_C(154), UINT8_C( 36), UINT8_C(206), UINT8_C(134), UINT8_C(225), UINT8_C(147), UINT8_C( 44), UINT8_C(189),
      UINT8_C( 81), UINT8_C( 77), UINT8_C(217), UINT8_C( 40), UINT8_C( 89), UINT8_C( 38), UINT8_C( 18), UINT8_C(111),
      UINT8_C(157), UINT8_C(118), UINT8_C(132), UINT8_C(191), UINT8_C(242), UINT8_C(173), UINT8_C(108), UINT8_C(184),
      UINT8_C(197), UINT8_C(185), UINT8_C( 57), UINT8_C(249), UINT8_C(173), UINT8_C(216), UINT8_C(204), UINT8_C( 71),
      UINT8_C(253), UINT8_C(154), UINT8_C(206), UINT8_C(222), UINT8_C( 45), UINT8_C(250), UINT8_C(156), UINT8_C(127),
      UINT8_C( 71), UINT8_C(117), UINT8_C(167), UINT8_C(160), UINT8_C(155), UINT8_C(185), UINT8_C( 15), UINT8_C( 56),
      UINT8_C( 48), UINT8_C(148), UINT8_C(247), UINT8_C( 34), UINT8_C( 65), UINT8_C(100), UINT8_C(219), UINT8_C(  6),
      UINT8_C( 29), UINT8_C( 20),    UINT8_MAX, UINT8_C(202), UINT8_C(236), UINT8_C(204), UINT8_C( 18), UINT8_C(233),
      UINT8_C(102), UINT8_C(224), UINT8_C(200), UINT8_C(148), UINT8_C(218), UINT8_C(100), UINT8_C( 19), UINT8_C( 33),
      UINT8_C(217), UINT8_C(186), UINT8_C(194), UINT8_C(116), UINT8_C(115), UINT8_C(209), UINT8_C(172), UINT8_C(163),
      UINT8_C(101), UINT8_C(164), UINT8_C(198), UINT8_C(166), UINT8_C(  8), UINT8_C(161), UINT8_C(173), UINT8_C( 37),
      UINT8_C(181), UINT8_C(172), UINT8_C(239), UINT8_C(161), UINT8_C(120), UINT8_C(  1), UINT8_C(139), UINT8_C(223),
      UINT8_C(225), UINT8_C( 83), UINT8_C(115), UINT8_C(187), UINT8_C(183), UINT8_C(134), UINT8_C(221), UINT8_C(144),
      UINT8_C( 64), UINT8_C(159), UINT8_C(  4), UINT8_C(179), UINT8_C(112), UINT8_C(176), UINT8_C( 87), UINT8_C(214),
      UINT8_C( 84), UINT8_C( 29), UINT8_C(124), UINT8_C( 92), UINT8_C(190), UINT8_C( 41), UINT8_C(129), UINT8_C(115),
      UINT8_C(214), UINT8_C(113), UINT8_C( 20), UINT8_C( 78), UINT8_C(114), UINT8_C(159), UINT8_C( 45), UINT8_C( 84),
      UINT8_C(242), UINT8_C(160), UINT8_C( 15), UINT8_C(169), UINT8_C( 38), UINT8_C(236), UINT8_C( 57), UINT8_C(102),
      UINT8_C(139), UINT8_C( 61), UINT8_C( 26), UINT8_C(252), UINT8_C(238), UINT8_C(113), UINT8_C(210), UINT8_C( 66),
      UINT8_C(142), UINT8_C( 78), UINT8_C(159), UINT8_C( 76), UINT8_C(120), UINT8_C( 32), UINT8_C(191), UINT8_C( 78),
      UINT8_C(145), UINT8_C(211), UINT8_C(156), UINT8_C(  4), UINT8_C(115), UINT8_C(202), UINT8_C( 88), UINT8_C(101),
      UINT8_C(106), UINT8_C(103), UINT8_C( 15), UINT8_C(145), UINT8_C( 84), UINT8_C( 72), UINT8_C(247), UINT8_C(223),
      UINT8_C(134), UINT8_C( 17), UINT8_C(219), UINT8_C(116), UINT8_C(130), UINT8_C(173), UINT8_C(182), UINT8_C( 16),
      UINT8_C(252), UINT8_C( 85), UINT8_C( 92), UINT8_C(116), UINT8_C(118), UINT8_C( 27), UINT8_C(194), UINT8_C(  7),
      UINT8_C(239), UINT8_C( 94), UINT8_C( 11), UINT8_C( 98), UINT8_C( 40), UINT8_C( 99), UINT8_C(199), UINT8_C(147),
      UINT8_C(203), UINT8_C(214), UINT8_C( 36), UINT8_C( 31), UINT8_C( 31), UINT8_C( 27), UINT8_C(254), UINT8_C(165),
      UINT8_C( 45), UINT8_C(218), UINT8_C( 25), UINT8_C(175), UINT8_C(135), UINT8_C(207), UINT8_C(192), UINT8_C(131),
      UINT8_C( 37), UINT8_C( 28), UINT8_C(247), UINT8_C(155), UINT8_C( 56), UINT8_C(185), UINT8_C(162), UINT8_C( 39),
      UINT8_C( 24), UINT8_C(174), UINT8_C(137), UINT8_C( 64), UINT8_C( 17), UINT8_C( 80), UINT8_C(211), UINT8_C(220),
      UINT8_C( 39), UINT8_C(247), UINT8_C(251), UINT8_C( 70), UINT8_C( 19), UINT8_C(250), UINT8_C(235), UINT8_C( 64),
      UINT8_C(212), UINT8_C(  4), UINT8_C(239), UINT8_C( 91), UINT8_C(211), UINT8_C(175), UINT8_C(223), UINT8_C(248),
      UINT8_C(204), UINT8_C(214), UINT8_C(147), UINT8_C(  4), UINT8_C(144), UINT8_C( 54), UINT8_C( 43), UINT8_C(168),
      UINT8_C(228), UINT8_C(180), UINT8_C(232), UINT8_C(245), UINT8_C(  4), UINT8_C(188), UINT8_C(210), UINT8_C( 43),
      UINT8_C(179), UINT8_C(205), UINT8_C(113), UINT8_C(198), UINT8_C(199), UINT8_C( 92), UINT8_C(  6), UINT8_C(155),
      UINT8_C( 96), UINT8_C(246), UINT8_C(247), UINT8_C( 52), UINT8_C(165), UINT8_C(214), UINT8_C( 44), UINT8_C(113),
      UINT8_C(172), UINT8_C(192), UINT8_C(117), UINT8_C( 60), UINT8_C(246), UINT8_C(160), UINT8_C(228), UINT8_C(218),
      UINT8_C( 84), UINT8_C(205), UINT8_C(207), UINT8_C( 89), UINT8_C(137), UINT8_C(161), UINT8_C(132), UINT8_C( 60),
      UINT8_C(111), UINT8_C(246), UINT8_C(  3), UINT8_C( 54), UINT8_C( 82), UINT8_C(  9), UINT8_C(210), UINT8_C(179),
         UINT8_MAX, UINT8_C(201), UINT8_C(231), UINT8_C(165), UINT8_C(159), UINT8_C( 19), UINT8_C( 22), UINT8_C( 75),
      UINT8_C(211), UINT8_C(140), UINT8_C(136), UINT8_C(201), UINT8_C( 44), UINT8_C(108), UINT8_C(163), UINT8_C(129),
      UINT8_C( 57), UINT8_C(115), UINT8_C(218), UINT8_C(194), UINT8_C( 20), UINT8_C( 94),    UINT8_MAX, UINT8_C(131),
      UINT8_C( 84), UINT8_C(  2), UINT8_C(186), UINT8_C(167), UINT8_C( 11), UINT8_C(140), UINT8_C( 90), UINT8_C( 11),
      UINT8_C( 85), UINT8_C( 65), UINT8_C(176), UINT8_C(244), UINT8_C( 84), UINT8_C(198), UINT8_C( 63), UINT8_C( 40),
      UINT8_C( 82), UINT8_C(199), UINT8_C(241), UINT8_C(127), UINT8_C( 52), UINT8_C(149), UINT8_C(  0), UINT8_C(109),
      UINT8_C(  8), UINT8_C(218), UINT8_C( 48), UINT8_C( 28), UINT8_C( 56), UINT8_C( 47), UINT8_C(160), UINT8_C(141),
      UINT8_C( 49), UINT8_C( 90), UINT8_C( 52), UINT8_C( 60), UINT8_C(230), UINT8_C(142), UINT8_C( 71), UINT8_C( 59),
      UINT8_C(207), UINT8_C(247), UINT8_C( 47), UINT8_C( 35), UINT8_C(190), UINT8_C(110), UINT8_C( 75), UINT8_C( 16),
      UINT8_C( 54), UINT8_C( 61), UINT8_C(143), UINT8_C(106), UINT8_C(210), UINT8_C(143), UINT8_C(215), UINT8_C(218),
      UINT8_C(105), UINT8_C(  7), UINT8_C(246), UINT8_C(162), UINT8_C( 54), UINT8_C(150), UINT8_C( 47), UINT8_C(103),
      UINT8_C(240), UINT8_C( 99), UINT8_C(164), UINT8_C(214), UINT8_C(241), UINT8_C(235), UINT8_C( 17), UINT8_C(192),
      UINT8_C(227), UINT8_C( 64), UINT8_C(227), UINT8_C(161), UINT8_C(175), UINT8_C( 47), UINT8_C(177), UINT8_C(229),
      UINT8_C(108), UINT8_C( 65), UINT8_C( 79), UINT8_C( 62), UINT8_C(208), UINT8_C( 38), UINT8_C( 24), UINT8_C( 58),
      UINT8_C( 46), UINT8_C( 14), UINT8_C(220), UINT8_C(100), UINT8_C(165), UINT8_C( 11), UINT8_C(204), UINT8_C(149),
      UINT8_C(110), UINT8_C(112), UINT8_C(108), UINT8_C( 95), UINT8_C( 91), UINT8_C(125), UINT8_C( 31), UINT8_C( 62),
      UINT8_C(190), UINT8_C(  2), UINT8_C(223), UINT8_C(109), UINT8_C( 49), UINT8_C(145), UINT8_C( 82), UINT8_C(157),
      UINT8_C(210), UINT8_C(161), UINT8_C(219), UINT8_C(162), UINT8_C(199), UINT8_C(243), UINT8_C(220), UINT8_C(245),
      UINT8_C(  2), UINT8_C(184), UINT8_C( 90), UINT8_C(167), UINT8_C(195), UINT8_C( 38), UINT8_C( 60), UINT8_C( 49),
      UINT8_C(150), UINT8_C(168), UINT8_C(144), UINT8_C(241), UINT8_C( 38), UINT8_C(175), UINT8_C( 48), UINT8_C(228),
      UINT8_C(178), UINT8_C( 15), UINT8_C( 81), UINT8_C(227), UINT8_C(160), UINT8_C(163), UINT8_C(129), UINT8_C(114),
      UINT8_C( 68), UINT8_C( 92), UINT8_C( 21), UINT8_C( 11), UINT8_C( 80), UINT8_C(241), UINT8_C(  1), UINT8_C( 82),
      UINT8_C(170), UINT8_C( 91), UINT8_C(249), UINT8_C(109), UINT8_C(129), UINT8_C( 53), UINT8_C(159), UINT8_C( 23),
      UINT8_C(222), UINT8_C( 47), UINT8_C(  8), UINT8_C(  4), UINT8_C(223), UINT8_C( 56), UINT8_C(232), UINT8_C(145),
      UINT8_C( 72), UINT8_C( 57), UINT8_C(116), UINT8_C(232), UINT8_C(220), UINT8_C(245), UINT8_C( 91), UINT8_C( 32),
      UINT8_C( 82), UINT8_C(112), UINT8_C( 43), UINT8_C(162), UINT8_C( 97), UINT8_C( 44), UINT8_C(244), UINT8_C( 11),
      UINT8_C(135), UINT8_C(237), UINT8_C(121), UINT8_C(  8), UINT8_C( 34), UINT8_C( 24), UINT8_C( 31), UINT8_C(  0),
      UINT8_C( 71), UINT8_C( 40), UINT8_C(  4), UINT8_C( 38), UINT8_C( 96), UINT8_C(236), UINT8_C(183), UINT8_C(168),
      UINT8_C( 37), UINT8_C( 44), UINT8_C(145), UINT8_C(  1), UINT8_C( 33), UINT8_C(236), UINT8_C( 33), UINT8_C(115),
      UINT8_C( 92), UINT8_C( 77), UINT8_C( 21) };
  static const uint8_t b[] =
    { UINT8_C(175), UINT8_C(208), UINT8_C( 15), UINT8_C(197), UINT8_C(137), UINT8_C( 76), UINT8_C(  2), UINT8_C(168),
      UINT8_C(218), UINT8_C(111), UINT8_C( 80), UINT8_C(180), UINT8_C(115), UINT8_C( 23), UINT8_C(112), UINT8_C( 30),
      UINT8_C(143), UINT8_C( 51), UINT8_C(202), UINT8_C(232), UINT8_C(114), UINT8_C(104), UINT8_C(166), UINT8_C( 48),
      UINT8_C( 44), UINT8_C(127), UINT8_C(232), UINT8_C( 31), UINT8_C(112), UINT8_C( 68), UINT8_C(138), UINT8_C( 32),
      UINT8_C( 21), UINT8_C(153), UINT8_C(229), UINT8_C(158), UINT8_C(229), UINT8_C(232), UINT8_C( 70), UINT8_C(191),
      UINT8_C( 87), UINT8_C(150), UINT8_C(116), UINT8_C(202), UINT8_C(174), UINT8_C(228), UINT8_C(232), UINT8_C( 61),
      UINT8_C( 24), UINT8_C(178), UINT8_C( 37), UINT8_C(138), UINT8_C( 27), UINT8_C(203), UINT8_C(187), UINT8_C( 71),
      UINT8_C( 74), UINT8_C(163), UINT8_C(102), UINT8_C(187), UINT8_C(232), UINT8_C(241), UINT8_C(219), UINT8_C(253),
      UINT8_C(138), UINT8_C(192), UINT8_C(155), UINT8_C(112), UINT8_C(168), UINT8_C(226), UINT8_C( 47), UINT8_C(  0),
      UINT8_C(120), UINT8_C(163), UINT8_C(202), UINT8_C( 38), UINT8_C(136), UINT8_C(179), UINT8_C( 99), UINT8_C(160),
      UINT8_C(101), UINT8_C(136), UINT8_C( 42), UINT8_C(128), UINT8_C( 83), UINT8_C(229), UINT8_C(200), UINT8_C(158),
      UINT8_C(137), UINT8_C( 46), UINT8_C( 89), UINT8_C(113), UINT8_C( 31), UINT8_C( 52), UINT8_C(110), UINT8_C(170),
      UINT8_C(244), UINT8_C(  9), UINT8_C( 26), UINT8_C(157), UINT8_C(235), UINT8_C( 73), UINT8_C(157), UINT8_C(100),
      UINT8_C(237), UINT8_C(103), UINT8_C(138), UINT8_C(117), UINT8_C( 26), UINT8_C(238), UINT8_C( 21), UINT8_C(128),
      UINT8_C(118), UINT8_C( 63), UINT8_C(  0), UINT8_C(202), UINT8_C( 37), UINT8_C(200), UINT8_C(104), UINT8_C(174),
      UINT8_C(247), UINT8_C(193), UINT8_C( 31), UINT8_C( 22), UINT8_C(245), UINT8_C(141), UINT8_C(192), UINT8_C(233),
      UINT8_C(150), UINT8_C(218), UINT8_C(134), UINT8_C(130), UINT8_C( 36), UINT8_C( 35), UINT8_C(230), UINT8_C( 17),
      UINT8_C(139), UINT8_C(112), UINT8_C(134), UINT8_C(165), UINT8_C( 94), UINT8_C(155), UINT8_C( 37), UINT8_C(213),
      UINT8_C(218), UINT8_C( 38), UINT8_C(159),    UINT8_MAX, UINT8_C(238), UINT8_C(  7), UINT8_C(173), UINT8_C(229),
      UINT8_C(200), UINT8_C(204), UINT8_C(252), UINT8_C(189), UINT8_C( 89), UINT8_C(188), UINT8_C(166), UINT8_C(240),
      UINT8_C(151), UINT8_C( 45), UINT8_C(114), UINT8_C(187), UINT8_C( 80), UINT8_C( 88), UINT8_C(204), UINT8_C(219),
      UINT8_C(200), UINT8_C( 82), UINT8_C(129), UINT8_C( 39), UINT8_C(237), UINT8_C(166), UINT8_C(252), UINT8_C(199),
      UINT8_C(204), UINT8_C(155), UINT8_C(199), UINT8_C(187), UINT8_C(162), UINT8_C(116), UINT8_C(160), UINT8_C(106),
      UINT8_C( 65), UINT8_C(156), UINT8_C( 39), UINT8_C(154), UINT8_C( 89), UINT8_C(205), UINT8_C(138), UINT8_C(240),
      UINT8_C(250), UINT8_C(252), UINT8_C(171), UINT8_C( 75), UINT8_C( 84), UINT8_C(119), UINT8_C( 38), UINT8_C( 29),
      UINT8_C(201), UINT8_C(167), UINT8_C( 68), UINT8_C(182), UINT8_C( 78), UINT8_C( 64), UINT8_C(125), UINT8_C( 26),
      UINT8_C(219), UINT8_C( 68), UINT8_C(213), UINT8_C(125), UINT8_C(185), UINT8_C(118), UINT8_C(231), UINT8_C(250),
      UINT8_C( 18), UINT8_C( 14), UINT8_C(148), UINT8_C(107), UINT8_C(219), UINT8_C( 31), UINT8_C( 91), UINT8_C(214),
      UINT8_C( 27), UINT8_C(  6), UINT8_C( 33), UINT8_C(112), UINT8_C(125), UINT8_C( 71), UINT8_C(141), UINT8_C( 70),
      UINT8_C(239), UINT8_C(209), UINT8_C(252), UINT8_C( 61), UINT8_C( 17), UINT8_C(122), UINT8_C( 87), UINT8_C(236),
      UINT8_C(190), UINT8_C( 45), UINT8_C(105), UINT8_C(119), UINT8_C(163), UINT8_C( 80), UINT8_C(113), UINT8_C(181),
      UINT8_C( 94), UINT8_C(  6), UINT8_C( 33), UINT8_C( 57), UINT8_C( 37), UINT8_C(124), UINT8_C( 15), UINT8_C( 64),
      UINT8_C(131), UINT8_C( 48), UINT8_C(176), UINT8_C(  0), UINT8_C(120), UINT8_C( 61), UINT8_C( 71), UINT8_C(103),
      UINT8_C( 14), UINT8_C( 67), UINT8_C(164), UINT8_C( 31), UINT8_C(189), UINT8_C(251), UINT8_C( 11), UINT8_C(124),
      UINT8_C( 40), UINT8_C(116), UINT8_C(243), UINT8_C(203), UINT8_C(196), UINT8_C(101), UINT8_C(129), UINT8_C( 34),
      UINT8_C(107), UINT8_C(162), UINT8_C( 92), UINT8_C(144), UINT8_C( 30), UINT8_C(107), UINT8_C(208), UINT8_C(161),
      UINT8_C(156), UINT8_C(129), UINT8_C(162), UINT8_C( 20), UINT8_C(190), UINT8_C(233), UINT8_C(123), UINT8_C(205),
      UINT8_C( 44), UINT8_C( 31), UINT8_C(236), UINT8_C(234), UINT8_C( 26), UINT8_C(248), UINT8_C(102), UINT8_C( 67),
      UINT8_C(108), UINT8_C( 89), UINT8_C( 14), UINT8_C( 49), UINT8_C(190), UINT8_C(143), UINT8_C( 83), UINT8_C( 41),
      UINT8_C( 49), UINT8_C(175), UINT8_C(185), UINT8_C( 80), UINT8_C( 27), UINT8_C(138), UINT8_C(241), UINT8_C(183),
      UINT8_C( 11), UINT8_C(147), UINT8_C(203), UINT8_C(201), UINT8_C(124), UINT8_C( 70), UINT8_C(150), UINT8_C(169),
      UINT8_C(101), UINT8_C(131), UINT8_C(147), UINT8_C(127), UINT8_C(123), UINT8_C(249), UINT8_C(194), UINT8_C(231),
      UINT8_C( 82), UINT8_C(209), UINT8_C( 24), UINT8_C( 17), UINT8_C( 96), UINT8_C(108), UINT8_C( 58), UINT8_C(146),
      UINT8_C( 27), UINT8_C(244), UINT8_C(226), UINT8_C( 54), UINT8_C(126), UINT8_C(211), UINT8_C(237), UINT8_C(137),
      UINT8_C(103), UINT8_C(184), UINT8_C( 82), UINT8_C(227), UINT8_C(254), UINT8_C(233), UINT8_C(140), UINT8_C( 99),
      UINT8_C(108), UINT8_C( 31), UINT8_C(227), UINT8_C(231), UINT8_C( 24), UINT8_C(165), UINT8_C(206), UINT8_C(107),
      UINT8_C(118), UINT8_C(231), UINT8_C(124), UINT8_C(215), UINT8_C( 83), UINT8_C(182), UINT8_C(105), UINT8_C(110),
      UINT8_C(170), UINT8_C( 75), UINT8_C(165), UINT8_C( 40), UINT8_C( 30), UINT8_C(146), UINT8_C(177), UINT8_C(133),
      UINT8_C( 75), UINT8_C(  4), UINT8_C(105), UINT8_C( 73), UINT8_C(237), UINT8_C(245), UINT8_C(173), UINT8_C( 89),
      UINT8_C( 21), UINT8_C(144), UINT8_C( 64), UINT8_C( 45), UINT8_C( 53), UINT8_C( 14), UINT8_C(152), UINT8_C(172),
      UINT8_C(245), UINT8_C( 20), UINT8_C(131), UINT8_C( 72), UINT8_C(203), UINT8_C(236), UINT8_C(183), UINT8_C(117),
      UINT8_C( 55), UINT8_C( 92), UINT8_C(158), UINT8_C( 85), UINT8_C(238), UINT8_C( 79), UINT8_C(219), UINT8_C( 57),
      UINT8_C( 83), UINT8_C( 68), UINT8_C(131), UINT8_C( 64), UINT8_C( 57), UINT8_C( 48), UINT8_C(153), UINT8_C( 78),
      UINT8_C(192), UINT8_C(217), UINT8_C(124), UINT8_C(245), UINT8_C(232), UINT8_C( 20), UINT8_C(161), UINT8_C(221),
      UINT8_C( 41), UINT8_C( 36), UINT8_C( 38), UINT8_C(244), UINT8_C( 16), UINT8_C(221), UINT8_C(105), UINT8_C( 71),
      UINT8_C( 57), UINT8_C(  7), UINT8_C(157), UINT8_C( 39), UINT8_C( 87), UINT8_C(120), UINT8_C( 97), UINT8_C(170),
      UINT8_C(188), UINT8_C(228), UINT8_C(235), UINT8_C(245), UINT8_C( 20), UINT8_C(132), UINT8_C( 68), UINT8_C(212),
      UINT8_C( 94), UINT8_C(192), UINT8_C(201), UINT8_C( 70), UINT8_C(212), UINT8_C(107), UINT8_C( 35), UINT8_C(253),
      UINT8_C(143), UINT8_C( 73), UINT8_C(241), UINT8_C(160), UINT8_C( 38), UINT8_C( 91), UINT8_C(231), UINT8_C( 95),
      UINT8_C( 98), UINT8_C(132), UINT8_C(135), UINT8_C(185), UINT8_C(252), UINT8_C(232), UINT8_C(100), UINT8_C(184),
      UINT8_C(204), UINT8_C( 79), UINT8_C(174), UINT8_C(224), UINT8_C(211), UINT8_C(242), UINT8_C(180), UINT8_C( 49),
      UINT8_C(178), UINT8_C(125), UINT8_C(119), UINT8_C(134), UINT8_C(232), UINT8_C(155), UINT8_C(132), UINT8_C(120),
      UINT8_C(228), UINT8_C(117), UINT8_C( 24), UINT8_C( 11), UINT8_C(208),    UINT8_MAX, UINT8_C(106), UINT8_C( 51),
      UINT8_C(132), UINT8_C(241), UINT8_C(236), UINT8_C(128), UINT8_C(217), UINT8_C( 80), UINT8_C( 57), UINT8_C(165),
      UINT8_C(159), UINT8_C(231), UINT8_C(133), UINT8_C(115), UINT8_C(217), UINT8_C( 57), UINT8_C(164), UINT8_C(139),
      UINT8_C(183), UINT8_C( 28), UINT8_C( 17), UINT8_C(159), UINT8_C(183), UINT8_C(149), UINT8_C( 23), UINT8_C(155),
      UINT8_C( 11), UINT8_C( 47), UINT8_C(166), UINT8_C(219), UINT8_C( 47), UINT8_C( 17), UINT8_C( 14), UINT8_C(179),
      UINT8_C(  2), UINT8_C(251), UINT8_C( 51), UINT8_C(220), UINT8_C( 75), UINT8_C(108), UINT8_C(129), UINT8_C(235),
      UINT8_C( 83), UINT8_C(  7), UINT8_C( 94), UINT8_C( 44), UINT8_C( 64), UINT8_C(  2), UINT8_C(183), UINT8_C(247),
      UINT8_C( 30), UINT8_C(201), UINT8_C(151), UINT8_C(213), UINT8_C( 94), UINT8_C(174), UINT8_C(113), UINT8_C(105),
      UINT8_C(222), UINT8_C( 23), UINT8_C( 69), UINT8_C( 13), UINT8_C( 40), UINT8_C( 83), UINT8_C(192), UINT8_C( 43),
      UINT8_C( 78), UINT8_C(243), UINT8_C(  7), UINT8_C(154), UINT8_C( 96), UINT8_C(136), UINT8_C(133), UINT8_C(179),
      UINT8_C(143), UINT8_C(227), UINT8_C(224), UINT8_C(208), UINT8_C(229), UINT8_C(151), UINT8_C(199), UINT8_C(  4),
      UINT8_C( 96), UINT8_C( 94), UINT8_C(217), UINT8_C(191), UINT8_C( 13), UINT8_C( 74), UINT8_C( 40), UINT8_C(235),
      UINT8_C( 98), UINT8_C(109), UINT8_C(248), UINT8_C(138), UINT8_C(193), UINT8_C(184), UINT8_C(181), UINT8_C( 15),
      UINT8_C(171), UINT8_C(188), UINT8_C(169), UINT8_C( 11), UINT8_C( 69), UINT8_C( 46), UINT8_C(191), UINT8_C(212),
      UINT8_C( 17), UINT8_C(159), UINT8_C(164), UINT8_C(247), UINT8_C( 54), UINT8_C(108), UINT8_C(251), UINT8_C(151),
      UINT8_C(202), UINT8_C(212), UINT8_C( 86), UINT8_C(215), UINT8_C( 31), UINT8_C(126), UINT8_C(194), UINT8_C(129),
      UINT8_C(236), UINT8_C(186), UINT8_C( 11), UINT8_C(173), UINT8_C(114), UINT8_C(193), UINT8_C(188), UINT8_C( 30),
      UINT8_C(125), UINT8_C(102), UINT8_C( 41), UINT8_C(194), UINT8_C(148), UINT8_C(232), UINT8_C(151), UINT8_C(166),
      UINT8_C(135), UINT8_C( 59), UINT8_C(157), UINT8_C(190), UINT8_C(167), UINT8_C(152), UINT8_C( 85), UINT8_C(114),
      UINT8_C(108), UINT8_C(171), UINT8_C( 73), UINT8_C(139), UINT8_C( 41), UINT8_C( 12), UINT8_C( 12), UINT8_C( 21),
      UINT8_C(198), UINT8_C( 24), UINT8_C(194), UINT8_C( 57), UINT8_C(217), UINT8_C(127), UINT8_C( 87), UINT8_C( 86),
      UINT8_C(229), UINT8_C(128), UINT8_C( 25), UINT8_C(121), UINT8_C(105), UINT8_C(176), UINT8_C( 31), UINT8_C(240),
      UINT8_C(235), UINT8_C(188), UINT8_C(174), UINT8_C(147), UINT8_C( 84), UINT8_C(  3), UINT8_C(  5), UINT8_C(193),
      UINT8_C(174), UINT8_C( 78), UINT8_C( 76), UINT8_C(216), UINT8_C( 90), UINT8_C( 89), UINT8_C(237), UINT8_C( 33),
      UINT8_C(113), UINT8_C(176), UINT8_C( 90), UINT8_C( 74), UINT8_C( 47), UINT8_C(177), UINT8_C(160), UINT8_C( 20),
      UINT8_C( 49), UINT8_C(185), UINT8_C(141), UINT8_C(154), UINT8_C(105), UINT8_C(173), UINT8_C(139), UINT8_C( 85),
      UINT8_C(105), UINT8_C( 57), UINT8_C(232), UINT8_C(190), UINT8_C( 61), UINT8_C(237), UINT8_C(127), UINT8_C(235),
      UINT8_C( 59), UINT8_C(203), UINT8_C(195), UINT8_C(150), UINT8_C( 36), UINT8_C(177), UINT8_C(183), UINT8_C(149),
      UINT8_C( 97), UINT8_C( 17), UINT8_C(223), UINT8_C(144), UINT8_C(194), UINT8_C(128), UINT8_C(164), UINT8_C(243),
      UINT8_C( 57), UINT8_C( 49), UINT8_C(142), UINT8_C(163), UINT8_C(222), UINT8_C( 25), UINT8_C(248), UINT8_C( 72),
      UINT8_C( 82), UINT8_C(224), UINT8_C(  6), UINT8_C(143), UINT8_C(205), UINT8_C(133), UINT8_C(123), UINT8_C(  8),
      UINT8_C( 80), UINT8_C( 62), UINT8_C(158), UINT8_C(117), UINT8_C(239), UINT8_C( 85), UINT8_C( 10), UINT8_C( 80),
      UINT8_C(102), UINT8_C(234), UINT8_C(224), UINT8_C( 40), UINT8_C(106), UINT8_C(132), UINT8_C( 28), UINT8_C(163),
      UINT8_C(182), UINT8_C(170), UINT8_C( 70), UINT8_C(148), UINT8_C(195), UINT8_C( 62), UINT8_C(220), UINT8_C( 21),
      UINT8_C( 30), UINT8_C(226), UINT8_C(165), UINT8_C(235), UINT8_C(103), UINT8_C( 32), UINT8_C(244), UINT8_C(184),
      UINT8_C( 94), UINT8_C(146), UINT8_C( 45), UINT8_C( 78), UINT8_C(232), UINT8_C( 55), UINT8_C(158), UINT8_C( 78),
      UINT8_C( 33), UINT8_C(127), UINT8_C(119), UINT8_C(139), UINT8_C(  3), UINT8_C(147), UINT8_C( 47), UINT8_C(185),
      UINT8_C( 61), UINT8_C(117), UINT8_C( 78), UINT8_C(  0), UINT8_C(180), UINT8_C( 42), UINT8_C( 21), UINT8_C(210),
      UINT8_C( 13), UINT8_C(186), UINT8_C(190), UINT8_C(116), UINT8_C(218), UINT8_C(178), UINT8_C( 44), UINT8_C( 57),
      UINT8_C( 68), UINT8_C( 89), UINT8_C(135), UINT8_C( 44), UINT8_C(145), UINT8_C( 37), UINT8_C(123), UINT8_C(178),
      UINT8_C(164), UINT8_C(242), UINT8_C( 62), UINT8_C(168), UINT8_C(133), UINT8_C(109), UINT8_C( 97), UINT8_C(194),
      UINT8_C(226), UINT8_C(175), UINT8_C(194), UINT8_C(150), UINT8_C(218), UINT8_C(215), UINT8_C(105), UINT8_C(231),
      UINT8_C(146), UINT8_C( 39), UINT8_C( 91), UINT8_C(108), UINT8_C(217), UINT8_C(136), UINT8_C(165), UINT8_C( 29),
      UINT8_C(225), UINT8_C( 44), UINT8_C( 74) };
  static const uint8_t e[] =
    { UINT8_C(155), UINT8_C(137), UINT8_C( 25), UINT8_C(142), UINT8_C( 44), UINT8_C(227), UINT8_C(192), UINT8_C(122),
      UINT8_C( 71), UINT8_C( 21), UINT8_C( 40), UINT8_C(  7), UINT8_C(224), UINT8_C( 33), UINT8_C( 42), UINT8_C(158),
      UINT8_C( 73), UINT8_C( 14), UINT8_C(116), UINT8_C(137), UINT8_C( 68), UINT8_C( 34), UINT8_C( 18), UINT8_C( 46),
      UINT8_C(247), UINT8_C( 71), UINT8_C(219), UINT8_C( 27), UINT8_C(143), UINT8_C( 69), UINT8_C(205), UINT8_C(122),
      UINT8_C(226), UINT8_C(230), UINT8_C( 67), UINT8_C( 14), UINT8_C(202), UINT8_C(  3), UINT8_C( 67), UINT8_C(235),
      UINT8_C(111), UINT8_C(107), UINT8_C(126), UINT8_C(133), UINT8_C( 34), UINT8_C(140), UINT8_C(237), UINT8_C(189),
      UINT8_C(131), UINT8_C( 97), UINT8_C( 95), UINT8_C(199), UINT8_C(209), UINT8_C(203), UINT8_C(175), UINT8_C(227),
      UINT8_C(221), UINT8_C(139), UINT8_C( 29), UINT8_C( 33), UINT8_C( 20), UINT8_C(234), UINT8_C(118), UINT8_C(249),
      UINT8_C(209), UINT8_C(159), UINT8_C(105), UINT8_C( 43), UINT8_C(226), UINT8_C(171), UINT8_C(134), UINT8_C(249),
      UINT8_C(142), UINT8_C(213), UINT8_C( 72), UINT8_C(138), UINT8_C(  4), UINT8_C( 53), UINT8_C(171),    UINT8_MAX,
      UINT8_C( 49), UINT8_C(167), UINT8_C(199), UINT8_C(  2), UINT8_C(114), UINT8_C(160), UINT8_C(102), UINT8_C(  4),
      UINT8_C( 43), UINT8_C(131), UINT8_C( 37), UINT8_C(206), UINT8_C(110), UINT8_C(244), UINT8_C( 53), UINT8_C(149),
      UINT8_C(147), UINT8_C( 58), UINT8_C(192), UINT8_C( 29), UINT8_C(220), UINT8_C( 23), UINT8_C( 22), UINT8_C( 86),
      UINT8_C(216), UINT8_C(247), UINT8_C(  6), UINT8_C(220), UINT8_C(147), UINT8_C(177), UINT8_C(124), UINT8_C(170),
      UINT8_C(224), UINT8_C( 46), UINT8_C(172), UINT8_C(219), UINT8_C(232), UINT8_C( 18), UINT8_C(223), UINT8_C( 57),
      UINT8_C(159), UINT8_C(  4), UINT8_C(120), UINT8_C(238), UINT8_C(197), UINT8_C(174), UINT8_C(131), UINT8_C( 77),
      UINT8_C( 82), UINT8_C( 29), UINT8_C(107), UINT8_C(175), UINT8_C(125), UINT8_C( 94), UINT8_C( 31), UINT8_C( 85),
      UINT8_C(224), UINT8_C(156), UINT8_C(171), UINT8_C(115), UINT8_C(189), UINT8_C( 18), UINT8_C(157), UINT8_C(158),
      UINT8_C( 64), UINT8_C( 36), UINT8_C( 67), UINT8_C( 41), UINT8_C(110), UINT8_C(139), UINT8_C(180), UINT8_C( 13),
      UINT8_C(136), UINT8_C( 13), UINT8_C(246), UINT8_C( 77), UINT8_C(135), UINT8_C( 57), UINT8_C(178), UINT8_C(127),
      UINT8_C(191), UINT8_C(150), UINT8_C( 31), UINT8_C( 24), UINT8_C(244), UINT8_C( 36), UINT8_C( 40), UINT8_C( 73),
      UINT8_C( 48), UINT8_C(  8), UINT8_C(152), UINT8_C(238), UINT8_C( 26), UINT8_C(143), UINT8_C(140), UINT8_C( 91),
      UINT8_C(127), UINT8_C( 52), UINT8_C( 74), UINT8_C(220), UINT8_C(184), UINT8_C( 55), UINT8_C( 46), UINT8_C( 65),
      UINT8_C( 67), UINT8_C(197), UINT8_C(181), UINT8_C( 12), UINT8_C(254), UINT8_C( 64), UINT8_C(241), UINT8_C( 85),
      UINT8_C(214), UINT8_C(154), UINT8_C( 40), UINT8_C( 21), UINT8_C(191), UINT8_C( 81), UINT8_C( 57), UINT8_C(239),
      UINT8_C(171), UINT8_C( 42), UINT8_C(221), UINT8_C(178), UINT8_C(  7), UINT8_C( 41), UINT8_C( 87), UINT8_C(108),
      UINT8_C( 57), UINT8_C(218), UINT8_C(141), UINT8_C(147), UINT8_C( 16), UINT8_C(187), UINT8_C( 87), UINT8_C( 84),
      UINT8_C(228), UINT8_C(244), UINT8_C(198), UINT8_C(244), UINT8_C(  1), UINT8_C(182), UINT8_C(238), UINT8_C(252),
      UINT8_C( 85), UINT8_C(108), UINT8_C(231), UINT8_C(191), UINT8_C( 70), UINT8_C(217), UINT8_C(145), UINT8_C(110),
      UINT8_C(  3), UINT8_C(252), UINT8_C( 32), UINT8_C(188), UINT8_C(101), UINT8_C(123), UINT8_C( 40), UINT8_C(158),
      UINT8_C( 85), UINT8_C(181), UINT8_C(201), UINT8_C(221), UINT8_C( 19), UINT8_C( 32), UINT8_C( 43), UINT8_C(  9),
      UINT8_C(  6), UINT8_C(127), UINT8_C(220), UINT8_C( 45), UINT8_C( 90), UINT8_C( 71), UINT8_C( 41), UINT8_C(138),
      UINT8_C( 54), UINT8_C(239), UINT8_C( 73), UINT8_C(124), UINT8_C(199), UINT8_C( 24), UINT8_C(234), UINT8_C( 49),
      UINT8_C(  6), UINT8_C( 10), UINT8_C( 42), UINT8_C( 90),    UINT8_MAX, UINT8_C(175), UINT8_C( 24), UINT8_C(151),
      UINT8_C(140), UINT8_C(214), UINT8_C(240), UINT8_C(212), UINT8_C(246), UINT8_C( 27), UINT8_C(168), UINT8_C( 31),
      UINT8_C(160), UINT8_C(  3), UINT8_C(133), UINT8_C(106), UINT8_C(236), UINT8_C( 82), UINT8_C(245), UINT8_C(165),
      UINT8_C( 64), UINT8_C(190), UINT8_C(127), UINT8_C( 27), UINT8_C( 24), UINT8_C( 34), UINT8_C( 77), UINT8_C(234),
      UINT8_C( 22), UINT8_C(119), UINT8_C(100), UINT8_C( 21), UINT8_C( 33), UINT8_C(124), UINT8_C( 40), UINT8_C(106),
      UINT8_C(198), UINT8_C(191), UINT8_C( 62), UINT8_C( 79), UINT8_C( 51), UINT8_C(101), UINT8_C(159), UINT8_C(170),
      UINT8_C(105), UINT8_C( 36), UINT8_C(206), UINT8_C( 54), UINT8_C(198), UINT8_C(  9), UINT8_C( 59), UINT8_C(189),
      UINT8_C( 70), UINT8_C(186), UINT8_C( 14), UINT8_C( 40), UINT8_C(221), UINT8_C(224), UINT8_C(124), UINT8_C(198),
      UINT8_C(157), UINT8_C(243), UINT8_C(132), UINT8_C( 64), UINT8_C(119), UINT8_C(173), UINT8_C(108), UINT8_C(184),
      UINT8_C(197), UINT8_C(185), UINT8_C( 57), UINT8_C(249), UINT8_C( 77), UINT8_C(216), UINT8_C(146), UINT8_C( 71),
      UINT8_C(253), UINT8_C(154), UINT8_C(236), UINT8_C(168), UINT8_C(175), UINT8_C( 39), UINT8_C(156), UINT8_C(246),
      UINT8_C( 71), UINT8_C(189), UINT8_C(167), UINT8_C(189), UINT8_C(157), UINT8_C(208), UINT8_C( 15), UINT8_C(213),
      UINT8_C( 48), UINT8_C(148), UINT8_C( 20), UINT8_C( 34), UINT8_C( 41), UINT8_C(100), UINT8_C( 13), UINT8_C(  6),
      UINT8_C( 29), UINT8_C( 45), UINT8_C(131), UINT8_C(243), UINT8_C(153), UINT8_C( 22), UINT8_C( 18), UINT8_C(123),
      UINT8_C(188), UINT8_C(149), UINT8_C( 35), UINT8_C(148), UINT8_C(218), UINT8_C(210), UINT8_C( 19), UINT8_C(156),
      UINT8_C(217), UINT8_C(186), UINT8_C(194), UINT8_C(116), UINT8_C(134), UINT8_C(220), UINT8_C(172), UINT8_C(163),
      UINT8_C(101), UINT8_C( 20), UINT8_C(134), UINT8_C(166), UINT8_C(211), UINT8_C(161), UINT8_C(173), UINT8_C(121),
      UINT8_C(192), UINT8_C(152), UINT8_C(108), UINT8_C( 89), UINT8_C(173), UINT8_C( 21), UINT8_C(139), UINT8_C(223),
      UINT8_C(170), UINT8_C( 83), UINT8_C(213), UINT8_C(187), UINT8_C(201), UINT8_C( 55), UINT8_C(  2), UINT8_C(144),
      UINT8_C(237), UINT8_C(159), UINT8_C(  4), UINT8_C(115), UINT8_C( 55), UINT8_C(176), UINT8_C(190), UINT8_C(136),
      UINT8_C( 84), UINT8_C( 29), UINT8_C(124), UINT8_C(103), UINT8_C(214), UINT8_C( 41), UINT8_C(224), UINT8_C(115),
      UINT8_C(214), UINT8_C( 77), UINT8_C( 20), UINT8_C( 90), UINT8_C( 98), UINT8_C(159), UINT8_C( 45), UINT8_C( 84),
      UINT8_C(242), UINT8_C(153), UINT8_C(114), UINT8_C(169), UINT8_C( 38), UINT8_C(116), UINT8_C(216), UINT8_C(102),
      UINT8_C(207), UINT8_C( 89), UINT8_C( 47), UINT8_C(  7), UINT8_C(238), UINT8_C(237), UINT8_C(142), UINT8_C( 66),
      UINT8_C(142), UINT8_C(142), UINT8_C(159), UINT8_C(  6), UINT8_C(120), UINT8_C( 32), UINT8_C(191), UINT8_C( 78),
      UINT8_C(  2), UINT8_C(211), UINT8_C(156), UINT8_C(100), UINT8_C( 77), UINT8_C(202), UINT8_C(113), UINT8_C(101),
      UINT8_C(  8), UINT8_C(227), UINT8_C( 15), UINT8_C(145), UINT8_C( 84), UINT8_C( 72), UINT8_C(147), UINT8_C( 39),
      UINT8_C(134), UINT8_C(194), UINT8_C(219), UINT8_C(116), UINT8_C(175), UINT8_C(187), UINT8_C(  2), UINT8_C(223),
      UINT8_C(252), UINT8_C( 85), UINT8_C(229), UINT8_C(116), UINT8_C(118), UINT8_C(128), UINT8_C( 62), UINT8_C(  7),
      UINT8_C(239), UINT8_C(233), UINT8_C(243), UINT8_C( 87), UINT8_C( 40), UINT8_C(100), UINT8_C( 93), UINT8_C(147),
      UINT8_C(203), UINT8_C(214), UINT8_C( 56), UINT8_C( 31), UINT8_C( 31), UINT8_C( 27), UINT8_C(254), UINT8_C(165),
      UINT8_C( 45), UINT8_C(243), UINT8_C(148), UINT8_C( 60), UINT8_C(135), UINT8_C(150), UINT8_C( 28), UINT8_C(248),
      UINT8_C(110), UINT8_C( 28), UINT8_C(247), UINT8_C(155), UINT8_C(129), UINT8_C(185), UINT8_C(139), UINT8_C(140),
      UINT8_C( 24), UINT8_C(127), UINT8_C(227), UINT8_C( 64), UINT8_C(226), UINT8_C( 80), UINT8_C(197), UINT8_C(220),
      UINT8_C( 37), UINT8_C(247), UINT8_C(251), UINT8_C(106), UINT8_C(200), UINT8_C(142), UINT8_C(235), UINT8_C( 64),
      UINT8_C(212), UINT8_C(  4), UINT8_C(145), UINT8_C( 47), UINT8_C(147), UINT8_C(173), UINT8_C( 40), UINT8_C(  1),
      UINT8_C(174), UINT8_C( 13), UINT8_C(147), UINT8_C( 47), UINT8_C(144), UINT8_C( 54), UINT8_C( 43), UINT8_C(168),
      UINT8_C(  6), UINT8_C(180), UINT8_C(163), UINT8_C(232), UINT8_C(  4), UINT8_C(188), UINT8_C( 18), UINT8_C( 43),
      UINT8_C(101), UINT8_C(205), UINT8_C(113), UINT8_C(198), UINT8_C(103), UINT8_C(212), UINT8_C(  6), UINT8_C(155),
      UINT8_C(209), UINT8_C(246), UINT8_C( 23), UINT8_C(100), UINT8_C(192), UINT8_C(214), UINT8_C( 44), UINT8_C(109),
      UINT8_C(172), UINT8_C(192), UINT8_C(117), UINT8_C(125), UINT8_C(233), UINT8_C( 86), UINT8_C(188), UINT8_C(218),
      UINT8_C(242), UINT8_C( 96), UINT8_C(215), UINT8_C( 89), UINT8_C(137), UINT8_C(161), UINT8_C(132), UINT8_C( 45),
      UINT8_C(196), UINT8_C(246), UINT8_C(  3), UINT8_C( 54), UINT8_C( 13), UINT8_C(219), UINT8_C(210), UINT8_C(223),
         UINT8_MAX, UINT8_C(201), UINT8_C(231), UINT8_C(174), UINT8_C(105), UINT8_C( 19), UINT8_C( 22), UINT8_C( 75),
      UINT8_C(  9), UINT8_C(184), UINT8_C( 50), UINT8_C(242), UINT8_C( 44), UINT8_C(238), UINT8_C(225), UINT8_C(  0),
      UINT8_C( 57), UINT8_C(185), UINT8_C(218), UINT8_C(194), UINT8_C( 20), UINT8_C( 94),    UINT8_MAX, UINT8_C(101),
      UINT8_C(215), UINT8_C(  2), UINT8_C(186), UINT8_C(229), UINT8_C( 11), UINT8_C(140), UINT8_C( 90), UINT8_C( 11),
      UINT8_C(206), UINT8_C(  6), UINT8_C(176), UINT8_C(244), UINT8_C( 84), UINT8_C( 46), UINT8_C( 63), UINT8_C( 40),
      UINT8_C( 82), UINT8_C( 28), UINT8_C(168), UINT8_C(127), UINT8_C( 52), UINT8_C(149), UINT8_C(  0), UINT8_C( 88),
      UINT8_C(  8), UINT8_C(218), UINT8_C( 48), UINT8_C(227), UINT8_C( 95), UINT8_C( 47), UINT8_C(160), UINT8_C(141),
      UINT8_C( 76), UINT8_C(218), UINT8_C( 52), UINT8_C(195), UINT8_C(230), UINT8_C(222), UINT8_C( 71), UINT8_C( 75),
      UINT8_C(207), UINT8_C(247), UINT8_C(129), UINT8_C( 35), UINT8_C(106), UINT8_C(110), UINT8_C( 70), UINT8_C( 79),
      UINT8_C(136), UINT8_C( 61), UINT8_C(143), UINT8_C(106), UINT8_C(120), UINT8_C(143), UINT8_C(215), UINT8_C(185),
      UINT8_C(248), UINT8_C(  7), UINT8_C(156), UINT8_C(162), UINT8_C(  7), UINT8_C(150), UINT8_C(143), UINT8_C(103),
      UINT8_C(191), UINT8_C(170), UINT8_C(164), UINT8_C( 60), UINT8_C(241), UINT8_C(235), UINT8_C( 17), UINT8_C(107),
      UINT8_C(227), UINT8_C( 64), UINT8_C(227), UINT8_C(161), UINT8_C(175), UINT8_C( 66), UINT8_C( 50), UINT8_C(250),
      UINT8_C( 49), UINT8_C( 65), UINT8_C( 79), UINT8_C( 62), UINT8_C(208), UINT8_C( 38), UINT8_C( 24), UINT8_C( 58),
      UINT8_C(205), UINT8_C(253), UINT8_C(220), UINT8_C(100), UINT8_C(227), UINT8_C(139), UINT8_C( 40), UINT8_C(149),
      UINT8_C(110), UINT8_C(112), UINT8_C(222), UINT8_C(188), UINT8_C(125), UINT8_C(125), UINT8_C( 39), UINT8_C(246),
      UINT8_C(190), UINT8_C( 34), UINT8_C(223), UINT8_C(109), UINT8_C(100), UINT8_C(145), UINT8_C( 82), UINT8_C(149),
      UINT8_C(210), UINT8_C(161), UINT8_C( 61), UINT8_C( 45), UINT8_C(216), UINT8_C(243), UINT8_C(210), UINT8_C(245),
      UINT8_C(156), UINT8_C(206), UINT8_C(122), UINT8_C(127), UINT8_C( 89), UINT8_C(162), UINT8_C( 60), UINT8_C(142),
      UINT8_C(224), UINT8_C(254), UINT8_C( 74), UINT8_C(241), UINT8_C( 38), UINT8_C(113), UINT8_C( 48), UINT8_C(228),
      UINT8_C(178), UINT8_C( 45), UINT8_C(172), UINT8_C(227), UINT8_C( 57), UINT8_C(131), UINT8_C(141), UINT8_C(186),
      UINT8_C(230), UINT8_C(202), UINT8_C(232), UINT8_C(189), UINT8_C(104), UINT8_C(241), UINT8_C( 99), UINT8_C(  4),
      UINT8_C(170), UINT8_C(220), UINT8_C(130), UINT8_C(109), UINT8_C(129), UINT8_C(162), UINT8_C(112), UINT8_C( 23),
      UINT8_C(161), UINT8_C(186), UINT8_C(186), UINT8_C(  4), UINT8_C(223), UINT8_C( 56), UINT8_C(232), UINT8_C(191),
      UINT8_C( 59), UINT8_C(127), UINT8_C(116), UINT8_C(232), UINT8_C(220), UINT8_C( 67), UINT8_C( 91), UINT8_C( 32),
      UINT8_C( 14), UINT8_C( 23), UINT8_C(164), UINT8_C(118), UINT8_C( 97), UINT8_C(  7), UINT8_C(244), UINT8_C( 89),
      UINT8_C(135), UINT8_C(251), UINT8_C( 59), UINT8_C( 96), UINT8_C(157), UINT8_C(171), UINT8_C( 31), UINT8_C(  0),
      UINT8_C(101), UINT8_C(121), UINT8_C( 66), UINT8_C( 38), UINT8_C( 96), UINT8_C( 21), UINT8_C( 78), UINT8_C(193),
      UINT8_C( 37), UINT8_C(  5), UINT8_C( 54), UINT8_C(  1), UINT8_C( 72), UINT8_C(236), UINT8_C( 33), UINT8_C(115),
      UINT8_C( 92), UINT8_C( 77), UINT8_C(203) };

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
    rv = simde_svsub_u8_m(pv, av, bv);

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

    ev = simde_svsub_u8_m(pv, av, bv);

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
test_simde_svsub_u16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) };
  static const uint16_t a[] =
    { UINT16_C(11324), UINT16_C(49487), UINT16_C( 6017), UINT16_C(58627), UINT16_C(44653), UINT16_C(36213), UINT16_C(40092), UINT16_C( 5356),
      UINT16_C( 9811), UINT16_C( 6243), UINT16_C(37698), UINT16_C(56430), UINT16_C(60567), UINT16_C( 5879), UINT16_C(51025), UINT16_C(36134),
      UINT16_C(30196), UINT16_C(30030), UINT16_C(20877), UINT16_C(64090), UINT16_C(52992), UINT16_C(40071), UINT16_C(29803), UINT16_C(48817),
      UINT16_C( 5274), UINT16_C(56534), UINT16_C(17575), UINT16_C(16057), UINT16_C(45105), UINT16_C(33364), UINT16_C(31351), UINT16_C(27407),
      UINT16_C(24304), UINT16_C(32224), UINT16_C(15023), UINT16_C(44919), UINT16_C(65034), UINT16_C(30028), UINT16_C(64882), UINT16_C( 3380),
      UINT16_C( 2577), UINT16_C(47593), UINT16_C(41551), UINT16_C(33015), UINT16_C(19538), UINT16_C(51714), UINT16_C( 4550), UINT16_C(46645),
      UINT16_C( 5743), UINT16_C( 7987), UINT16_C(43600), UINT16_C(23246), UINT16_C( 6825), UINT16_C( 7120), UINT16_C( 1047), UINT16_C(10536),
      UINT16_C( 4622), UINT16_C(24034), UINT16_C(55732), UINT16_C( 2013), UINT16_C(57125), UINT16_C(60625), UINT16_C( 1777), UINT16_C(24738),
      UINT16_C(54812), UINT16_C(28031), UINT16_C(20096), UINT16_C(10695), UINT16_C(38760), UINT16_C(32837), UINT16_C(28059), UINT16_C(43689),
      UINT16_C(35711), UINT16_C(13319), UINT16_C(58724), UINT16_C(35387), UINT16_C( 3268), UINT16_C(46454), UINT16_C( 6162), UINT16_C(12054),
      UINT16_C(38382), UINT16_C(28572), UINT16_C(25571), UINT16_C(19608), UINT16_C(56827), UINT16_C(38604), UINT16_C(30027), UINT16_C(51776),
      UINT16_C(18432), UINT16_C(25854), UINT16_C(14637), UINT16_C(61934), UINT16_C(25669), UINT16_C(22695), UINT16_C(48509), UINT16_C(27527),
      UINT16_C( 9042), UINT16_C(14042), UINT16_C(29574), UINT16_C(33154), UINT16_C(20048), UINT16_C(39704), UINT16_C(22723), UINT16_C(50022),
      UINT16_C(25760), UINT16_C(52519), UINT16_C( 5790), UINT16_C(58303), UINT16_C(26234), UINT16_C(63291), UINT16_C(49699), UINT16_C(30051),
      UINT16_C(15845), UINT16_C(27819), UINT16_C(11696), UINT16_C(  493), UINT16_C( 1403), UINT16_C(16028), UINT16_C(  606), UINT16_C(65025),
      UINT16_C(10599), UINT16_C( 1484), UINT16_C(35647), UINT16_C(47592), UINT16_C( 9457), UINT16_C( 5297), UINT16_C( 5350), UINT16_C(52361),
      UINT16_C(13649), UINT16_C(  568), UINT16_C( 9570), UINT16_C(56835), UINT16_C(40747), UINT16_C(35100), UINT16_C( 7842), UINT16_C( 2439),
      UINT16_C(21319), UINT16_C(34318), UINT16_C(63198), UINT16_C(53055), UINT16_C(61466), UINT16_C(  483), UINT16_C(27908), UINT16_C(22221),
      UINT16_C( 1442), UINT16_C( 1112), UINT16_C(23338), UINT16_C(21986), UINT16_C(65530), UINT16_C(40158), UINT16_C(26141), UINT16_C(25765),
      UINT16_C(46009), UINT16_C(39146), UINT16_C(10666), UINT16_C(50279), UINT16_C(19226), UINT16_C( 7877), UINT16_C(37560), UINT16_C(23156),
      UINT16_C(52375), UINT16_C(49758), UINT16_C(16679), UINT16_C( 8727), UINT16_C(63040), UINT16_C(23998), UINT16_C(25692), UINT16_C( 5569),
      UINT16_C(43799), UINT16_C(49581), UINT16_C( 5588), UINT16_C(61062), UINT16_C(19296), UINT16_C( 6157), UINT16_C(33246), UINT16_C(30066),
      UINT16_C(53326), UINT16_C(30007), UINT16_C(20241), UINT16_C(20887), UINT16_C(22085), UINT16_C(41390), UINT16_C(28602), UINT16_C(53686),
      UINT16_C(25626), UINT16_C(61331), UINT16_C( 6521), UINT16_C(55773), UINT16_C(60004), UINT16_C(17137), UINT16_C(25452), UINT16_C(47800),
      UINT16_C(61235), UINT16_C(17711), UINT16_C(51006), UINT16_C(33686), UINT16_C(17693), UINT16_C(55076), UINT16_C(56244), UINT16_C(53160),
      UINT16_C(15167), UINT16_C(47294), UINT16_C(39764), UINT16_C(47505), UINT16_C(33414), UINT16_C(62203), UINT16_C(46053), UINT16_C( 6316),
      UINT16_C(56227), UINT16_C(57693), UINT16_C(62626), UINT16_C(48997), UINT16_C(35129), UINT16_C(60822), UINT16_C(16228), UINT16_C(41916),
      UINT16_C(31354), UINT16_C(53083), UINT16_C(60438), UINT16_C(40072), UINT16_C(33646), UINT16_C(21390), UINT16_C(14903), UINT16_C(55916),
      UINT16_C(51477), UINT16_C(47291), UINT16_C( 8381), UINT16_C(63095), UINT16_C( 3754), UINT16_C( 3812), UINT16_C(41037), UINT16_C(51122),
      UINT16_C( 3355), UINT16_C(12694), UINT16_C( 7930), UINT16_C(26829), UINT16_C(23458), UINT16_C(55740), UINT16_C(10389), UINT16_C(43699),
      UINT16_C(28401), UINT16_C(44898), UINT16_C(55951), UINT16_C(14757), UINT16_C(35304), UINT16_C(13639), UINT16_C(63786), UINT16_C(17916),
      UINT16_C(37639), UINT16_C(  374), UINT16_C(17329), UINT16_C(21353), UINT16_C( 9630), UINT16_C(13100), UINT16_C(57165), UINT16_C(16349),
      UINT16_C(16462), UINT16_C(56814), UINT16_C(37658), UINT16_C(  534), UINT16_C(23837), UINT16_C(18231), UINT16_C(13143), UINT16_C(24204),
      UINT16_C(  710), UINT16_C(30815), UINT16_C(51269), UINT16_C(58315), UINT16_C(63726), UINT16_C(15126), UINT16_C(62423), UINT16_C( 9594),
      UINT16_C(26675), UINT16_C(19714), UINT16_C( 6396), UINT16_C( 6479), UINT16_C(34422), UINT16_C(52576), UINT16_C(60602), UINT16_C(32811),
      UINT16_C(35566), UINT16_C(13304), UINT16_C(50258), UINT16_C(16406), UINT16_C(11452), UINT16_C(37756), UINT16_C(63007), UINT16_C(21433),
      UINT16_C(47967), UINT16_C(23456), UINT16_C(61652), UINT16_C(19060), UINT16_C(54390), UINT16_C(12311), UINT16_C(17088), UINT16_C(44721),
      UINT16_C(43468), UINT16_C( 7905), UINT16_C(63341), UINT16_C(10591), UINT16_C(56099), UINT16_C(17085), UINT16_C(30417), UINT16_C(12437),
      UINT16_C(13873), UINT16_C( 1419), UINT16_C(65318), UINT16_C(40015), UINT16_C(26323), UINT16_C(37837), UINT16_C(32424), UINT16_C(29761),
      UINT16_C( 8743), UINT16_C(38291), UINT16_C(61977), UINT16_C(15550), UINT16_C(31693), UINT16_C(40575), UINT16_C( 5361), UINT16_C( 9167),
      UINT16_C(23114), UINT16_C(28712), UINT16_C(30810) };
  static const uint16_t b[] =
    { UINT16_C(55383), UINT16_C(63790), UINT16_C(17997), UINT16_C(28576), UINT16_C(46256), UINT16_C(63801), UINT16_C(20049), UINT16_C(64171),
      UINT16_C(13890), UINT16_C(59689), UINT16_C( 8759), UINT16_C( 9669), UINT16_C(53431), UINT16_C(23004), UINT16_C(48081), UINT16_C(10385),
      UINT16_C(49043), UINT16_C(57378), UINT16_C(49669), UINT16_C(46415), UINT16_C(34935), UINT16_C(51374), UINT16_C(22999), UINT16_C( 6595),
      UINT16_C(60559), UINT16_C(50690), UINT16_C(51215), UINT16_C(50923), UINT16_C(51096), UINT16_C(26911), UINT16_C(45186), UINT16_C( 5522),
      UINT16_C(46191), UINT16_C(29941), UINT16_C(17526), UINT16_C(60713), UINT16_C(55245), UINT16_C(42166), UINT16_C(31024), UINT16_C(49341),
      UINT16_C(49253), UINT16_C(29830), UINT16_C(29320), UINT16_C( 8250), UINT16_C(23097), UINT16_C(48266), UINT16_C( 7178), UINT16_C(31441),
      UINT16_C(51152), UINT16_C(18158), UINT16_C( 6155), UINT16_C(55348), UINT16_C(60143), UINT16_C( 8316), UINT16_C(14947), UINT16_C(51424),
      UINT16_C(26362), UINT16_C(33341), UINT16_C(30680), UINT16_C( 4770), UINT16_C(11473), UINT16_C(56526), UINT16_C(40776), UINT16_C( 6230),
      UINT16_C(17510), UINT16_C(29279), UINT16_C(37724), UINT16_C(19530), UINT16_C(51069), UINT16_C(57452), UINT16_C(19457), UINT16_C(64424),
      UINT16_C(58802), UINT16_C(35709), UINT16_C( 8029), UINT16_C(11933), UINT16_C(27468), UINT16_C(37898), UINT16_C(24586), UINT16_C(29101),
      UINT16_C( 3237), UINT16_C(  483), UINT16_C(11679), UINT16_C( 7245), UINT16_C(47604), UINT16_C(62972), UINT16_C(41989), UINT16_C(47344),
      UINT16_C(28042), UINT16_C(59203), UINT16_C(57485), UINT16_C(55573), UINT16_C( 8267), UINT16_C(21869), UINT16_C( 6784), UINT16_C( 9670),
      UINT16_C(43302), UINT16_C(50471), UINT16_C(29911), UINT16_C(52193), UINT16_C(56622), UINT16_C(13249), UINT16_C(45442), UINT16_C( 3307),
      UINT16_C(11807), UINT16_C(44275), UINT16_C( 2062), UINT16_C(22917), UINT16_C(61992), UINT16_C(43439), UINT16_C(29965), UINT16_C(13262),
      UINT16_C(62751), UINT16_C(63225), UINT16_C(55914), UINT16_C(39105), UINT16_C(33464), UINT16_C(15051), UINT16_C(46900), UINT16_C(21318),
      UINT16_C(14821), UINT16_C(62719), UINT16_C(33857), UINT16_C(27213), UINT16_C(64630), UINT16_C(33555), UINT16_C(57714), UINT16_C(37303),
      UINT16_C(45271), UINT16_C(16775), UINT16_C(18570), UINT16_C(17113), UINT16_C(42187), UINT16_C(65404), UINT16_C(49755), UINT16_C(16722),
      UINT16_C(20987), UINT16_C(15669), UINT16_C(33493), UINT16_C(19367), UINT16_C(47743), UINT16_C(61903), UINT16_C(34459), UINT16_C(29314),
      UINT16_C( 2358), UINT16_C(49331), UINT16_C(35921), UINT16_C( 7171), UINT16_C(32561), UINT16_C(35867), UINT16_C(27970), UINT16_C(15821),
      UINT16_C(  702), UINT16_C(37754), UINT16_C( 8581), UINT16_C( 1247), UINT16_C(44763), UINT16_C(30709), UINT16_C(30516), UINT16_C(27369),
      UINT16_C(40320), UINT16_C(53546), UINT16_C(11561), UINT16_C(23278), UINT16_C( 2477), UINT16_C(61415), UINT16_C(46199), UINT16_C(13612),
      UINT16_C(42935), UINT16_C(15561), UINT16_C(43208), UINT16_C(42048), UINT16_C(13654), UINT16_C(35355), UINT16_C( 1196), UINT16_C(11508),
      UINT16_C( 7841), UINT16_C(52221), UINT16_C(60236), UINT16_C(63781), UINT16_C( 3317), UINT16_C(27880), UINT16_C( 5313), UINT16_C(30881),
      UINT16_C(27323), UINT16_C(33972), UINT16_C(62482), UINT16_C(26664), UINT16_C(17193), UINT16_C(54770), UINT16_C(58951), UINT16_C(59649),
      UINT16_C(65029), UINT16_C(20916), UINT16_C(55786), UINT16_C(57162), UINT16_C(13030), UINT16_C(42827), UINT16_C(60486), UINT16_C(  543),
      UINT16_C(54103), UINT16_C(27014), UINT16_C(44743), UINT16_C(61650), UINT16_C(50417), UINT16_C(14533), UINT16_C(50859), UINT16_C(45089),
      UINT16_C(54724), UINT16_C(44545), UINT16_C(19375), UINT16_C(38285), UINT16_C(55421), UINT16_C(49980), UINT16_C(23493), UINT16_C( 7365),
      UINT16_C(19246), UINT16_C(62853), UINT16_C(22521), UINT16_C(60133), UINT16_C(43548), UINT16_C(50979), UINT16_C(17520), UINT16_C(13431),
      UINT16_C(30746), UINT16_C(51683), UINT16_C(28867), UINT16_C(16478), UINT16_C(39497), UINT16_C( 3587), UINT16_C(51701), UINT16_C( 9002),
      UINT16_C(44820), UINT16_C( 3608), UINT16_C(64775), UINT16_C( 9208), UINT16_C( 7079), UINT16_C( 6122), UINT16_C(24928), UINT16_C(31307),
      UINT16_C(11993), UINT16_C(40003), UINT16_C(41375), UINT16_C(59612), UINT16_C(57147), UINT16_C(12534), UINT16_C( 8360), UINT16_C(48467),
      UINT16_C(27599), UINT16_C(54987), UINT16_C(50024), UINT16_C( 4089), UINT16_C(58335), UINT16_C(16166), UINT16_C(28996), UINT16_C( 7609),
      UINT16_C(64672), UINT16_C(16313), UINT16_C(38301), UINT16_C(55335), UINT16_C( 7541), UINT16_C( 7432), UINT16_C(23357), UINT16_C( 3290),
      UINT16_C(42438), UINT16_C(12003), UINT16_C(56425), UINT16_C(18493), UINT16_C(25536), UINT16_C( 1159), UINT16_C(16596), UINT16_C(29730),
      UINT16_C(56124), UINT16_C(55731), UINT16_C(55921), UINT16_C(59057), UINT16_C(47607), UINT16_C(13315), UINT16_C(56852), UINT16_C(55873),
      UINT16_C( 9347), UINT16_C(60424), UINT16_C(17664), UINT16_C(49204), UINT16_C(48040), UINT16_C(31941), UINT16_C(59387), UINT16_C(14321),
      UINT16_C(42178), UINT16_C(13072), UINT16_C(49535), UINT16_C(30233), UINT16_C( 7546), UINT16_C(36523), UINT16_C(60667), UINT16_C(32360),
      UINT16_C(28688), UINT16_C( 4203), UINT16_C(40885), UINT16_C(24017), UINT16_C(38491), UINT16_C(22234), UINT16_C(52093), UINT16_C(16270),
      UINT16_C(40559), UINT16_C(61043), UINT16_C(35936), UINT16_C(55909), UINT16_C( 4265), UINT16_C(42089), UINT16_C(53756), UINT16_C( 3107),
      UINT16_C(36418), UINT16_C(63260), UINT16_C(60717), UINT16_C(34901), UINT16_C(12163), UINT16_C(  223), UINT16_C(28154), UINT16_C(26944),
      UINT16_C(45835), UINT16_C(27480), UINT16_C(48447) };
  static const uint16_t e[] =
    { UINT16_C(    0), UINT16_C(    0), UINT16_C(53556), UINT16_C(30051), UINT16_C(63933), UINT16_C(37948), UINT16_C(20043), UINT16_C( 6721),
      UINT16_C(61457), UINT16_C(12090), UINT16_C(    0), UINT16_C(46761), UINT16_C( 7136), UINT16_C(    0), UINT16_C( 2944), UINT16_C(    0),
      UINT16_C(46689), UINT16_C(    0), UINT16_C(36744), UINT16_C(    0), UINT16_C(18057), UINT16_C(54233), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(10251), UINT16_C( 5844), UINT16_C(31896), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(21885),
      UINT16_C(43649), UINT16_C(    0), UINT16_C(    0), UINT16_C(49742), UINT16_C(    0), UINT16_C(53398), UINT16_C(33858), UINT16_C(19575),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(61977), UINT16_C(    0), UINT16_C(62908), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(55365), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(64340), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(25052), UINT16_C(62779), UINT16_C(    0), UINT16_C( 4099), UINT16_C(26537), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(47908), UINT16_C(    0), UINT16_C(53227), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(50695), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(47112), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(28089), UINT16_C(    0), UINT16_C(12363), UINT16_C( 9223), UINT16_C(41168), UINT16_C(53574), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(32187), UINT16_C(    0), UINT16_C( 6361), UINT16_C(17402), UINT16_C(  826), UINT16_C(41725), UINT16_C(17857),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(65199), UINT16_C(    0), UINT16_C(    0), UINT16_C(26455), UINT16_C(42817), UINT16_C(46715),
      UINT16_C(13953), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(18630), UINT16_C(30130), UINT16_C(    0), UINT16_C(26924), UINT16_C(    0), UINT16_C(    0), UINT16_C(19242), UINT16_C(    0),
      UINT16_C(61314), UINT16_C( 4301), UINT16_C( 1790), UINT16_C(20379), UINT16_C(10363), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(33914), UINT16_C(49329), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(35232), UINT16_C(23623), UINT16_C(    0),
      UINT16_C(  332), UINT16_C(18649), UINT16_C(29705), UINT16_C(33688), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(58443),
      UINT16_C(    0), UINT16_C(17317), UINT16_C(    0), UINT16_C(    0), UINT16_C(32969), UINT16_C(    0), UINT16_C(63707), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(49032), UINT16_C(39999), UINT16_C(42704), UINT16_C(    0), UINT16_C(61323),
      UINT16_C(12055), UINT16_C(61748), UINT16_C( 5118), UINT16_C(    0), UINT16_C(60563), UINT16_C(28119), UINT16_C(45029), UINT16_C(    0),
      UINT16_C(  864), UINT16_C(34020), UINT16_C(    0), UINT16_C(    0), UINT16_C( 5642), UINT16_C(    0), UINT16_C(    0), UINT16_C(18558),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(18768), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(27359), UINT16_C( 9575), UINT16_C(29109), UINT16_C(42811), UINT16_C(    0), UINT16_C(32037), UINT16_C(53687),
      UINT16_C(61742), UINT16_C(62331), UINT16_C(60756), UINT16_C(42060), UINT16_C(    0), UINT16_C(12249), UINT16_C(61294), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(20280), UINT16_C(60557), UINT16_C(    0), UINT16_C(48533), UINT16_C(    0), UINT16_C(60730), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(13148), UINT16_C(43251), UINT16_C(    0), UINT16_C(    0), UINT16_C(10842), UINT16_C(    0), UINT16_C(34551),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(45475), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(20731), UINT16_C(61144), UINT16_C(45050), UINT16_C(46617), UINT16_C(    0), UINT16_C(  225), UINT16_C(    0), UINT16_C(42120),
      UINT16_C(    0), UINT16_C( 9086), UINT16_C( 8691), UINT16_C(    0), UINT16_C(16379), UINT16_C(    0), UINT16_C(    0), UINT16_C(12392),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(14576), UINT16_C(20681), UINT16_C(    0), UINT16_C(    0), UINT16_C(55426), UINT16_C(    0),
      UINT16_C(10040), UINT16_C(10923), UINT16_C(32841), UINT16_C(    0), UINT16_C(16831), UINT16_C(62470), UINT16_C(    0), UINT16_C( 8740),
      UINT16_C(    0), UINT16_C(40501), UINT16_C(64893), UINT16_C(10735), UINT16_C(16296), UINT16_C(10799), UINT16_C(55322), UINT16_C(    0),
      UINT16_C(23808), UINT16_C(18812), UINT16_C(60380), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(45400),
      UINT16_C(36087), UINT16_C(    0), UINT16_C(16011), UINT16_C(    0), UINT16_C(52351), UINT16_C(39261), UINT16_C(    0), UINT16_C(42474),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(32738), UINT16_C(    0), UINT16_C( 5815), UINT16_C( 3620), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(10384), UINT16_C(12117), UINT16_C(    0), UINT16_C(    0), UINT16_C(41324), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C( 3702), UINT16_C(22456), UINT16_C(52110), UINT16_C(17608), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C( 5912), UINT16_C(    0), UINT16_C(49642), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(26654),
      UINT16_C(37861), UINT16_C(    0), UINT16_C( 1260), UINT16_C(    0), UINT16_C(    0), UINT16_C(40352), UINT16_C(42743), UINT16_C(47759),
      UINT16_C(42815), UINT16_C( 1232), UINT16_C(47899) };

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
    rv = simde_svsub_u16_z(pv, av, bv);

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

    ev = simde_svsub_u16_z(pv, av, bv);

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
test_simde_svsub_u16_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1) };
  static const uint16_t a[] =
    { UINT16_C(38915), UINT16_C(40419), UINT16_C(27715), UINT16_C(63615), UINT16_C(29269), UINT16_C(59992), UINT16_C(27472), UINT16_C( 1767),
      UINT16_C(19984), UINT16_C(17060), UINT16_C(40945), UINT16_C(58390), UINT16_C(49098), UINT16_C(17417), UINT16_C(33059), UINT16_C( 9778),
      UINT16_C( 5401), UINT16_C(24003), UINT16_C(17026), UINT16_C(55125), UINT16_C(44468), UINT16_C( 1473), UINT16_C(43033), UINT16_C(10507),
      UINT16_C(45046), UINT16_C(59499), UINT16_C(33102), UINT16_C( 6348), UINT16_C(54592), UINT16_C(25436), UINT16_C(36438), UINT16_C(28809),
      UINT16_C(19620), UINT16_C( 9933), UINT16_C( 8847), UINT16_C(17405), UINT16_C(48847), UINT16_C(59464), UINT16_C(21350), UINT16_C(23825),
      UINT16_C(31746), UINT16_C(20805), UINT16_C( 4605), UINT16_C(15721), UINT16_C(50919), UINT16_C(15776), UINT16_C(10580), UINT16_C(63661),
      UINT16_C(31350), UINT16_C( 1310), UINT16_C( 7068), UINT16_C(27720), UINT16_C(37337), UINT16_C(16468), UINT16_C(26340), UINT16_C(59293),
      UINT16_C(58082), UINT16_C(57400), UINT16_C(41459), UINT16_C(55837), UINT16_C(48743), UINT16_C(48152), UINT16_C(50663), UINT16_C(23988),
      UINT16_C(54080), UINT16_C(56418), UINT16_C(44014), UINT16_C(51272), UINT16_C(40252), UINT16_C( 8200), UINT16_C(42243), UINT16_C(58631),
      UINT16_C(16263), UINT16_C(31429), UINT16_C(58337), UINT16_C(18517), UINT16_C(28065), UINT16_C(34820), UINT16_C(47410), UINT16_C(29414),
      UINT16_C(18572), UINT16_C(31311), UINT16_C(38899), UINT16_C(12098), UINT16_C(18996), UINT16_C(14160), UINT16_C(22511), UINT16_C(30237),
      UINT16_C(58007), UINT16_C(30961), UINT16_C(18117), UINT16_C(26304), UINT16_C(50611), UINT16_C(58863), UINT16_C(54654), UINT16_C( 2648),
      UINT16_C(42781), UINT16_C( 4484), UINT16_C(51006), UINT16_C(29504), UINT16_C(36881), UINT16_C(  426), UINT16_C(51176), UINT16_C(32631),
      UINT16_C(26794), UINT16_C(28663), UINT16_C(47022), UINT16_C(25046), UINT16_C(50556), UINT16_C(64071), UINT16_C(40858), UINT16_C(46852),
      UINT16_C(35142), UINT16_C(33992), UINT16_C( 2384), UINT16_C(25079), UINT16_C(41625), UINT16_C(33122), UINT16_C(55913), UINT16_C( 4864),
      UINT16_C(63298), UINT16_C(61827), UINT16_C(22959), UINT16_C(11090), UINT16_C(39198), UINT16_C(47142), UINT16_C(10808), UINT16_C(32367),
      UINT16_C(14515), UINT16_C(  771), UINT16_C(64065), UINT16_C(55909), UINT16_C(51100), UINT16_C( 1628), UINT16_C(23713), UINT16_C(58393),
      UINT16_C(40020), UINT16_C(  981), UINT16_C(10229), UINT16_C( 4910), UINT16_C(21697), UINT16_C(63947), UINT16_C(15231), UINT16_C(12920),
      UINT16_C(31603), UINT16_C(46134), UINT16_C(39797), UINT16_C( 4750), UINT16_C(60002), UINT16_C( 1048), UINT16_C(12615), UINT16_C(39912),
      UINT16_C(48590), UINT16_C(50078), UINT16_C(52452), UINT16_C(42455), UINT16_C(41505), UINT16_C(41119), UINT16_C( 6109), UINT16_C(20690),
      UINT16_C( 2194), UINT16_C( 1796), UINT16_C(37795), UINT16_C( 1561), UINT16_C(12669), UINT16_C(50186), UINT16_C(62051), UINT16_C(12639),
      UINT16_C(64943), UINT16_C(37876), UINT16_C(52170), UINT16_C(60217), UINT16_C(55406), UINT16_C(19339), UINT16_C(24047), UINT16_C(33180),
      UINT16_C(41062), UINT16_C( 2440), UINT16_C(41523), UINT16_C(45327), UINT16_C( 6611), UINT16_C(13941), UINT16_C(54539), UINT16_C(47719),
      UINT16_C(23762), UINT16_C(40014), UINT16_C(34599), UINT16_C(38279), UINT16_C( 4703), UINT16_C(20193), UINT16_C(32112), UINT16_C(54991),
      UINT16_C(22301), UINT16_C(20959), UINT16_C(61433), UINT16_C(52482), UINT16_C(30472), UINT16_C( 5123), UINT16_C(27468), UINT16_C( 8142),
      UINT16_C( 7367), UINT16_C(61115), UINT16_C(17315), UINT16_C(  644), UINT16_C(25941), UINT16_C(50512), UINT16_C( 8162), UINT16_C(65435),
      UINT16_C(31607), UINT16_C(28752), UINT16_C(21098), UINT16_C(29245), UINT16_C(16842), UINT16_C( 5766), UINT16_C(21932), UINT16_C(29493),
      UINT16_C(61809), UINT16_C( 5473), UINT16_C(58676), UINT16_C(35095), UINT16_C(26698), UINT16_C(11343), UINT16_C(60039), UINT16_C(65068),
      UINT16_C(31845), UINT16_C(53103), UINT16_C(44239), UINT16_C(39234), UINT16_C(51437), UINT16_C(39343), UINT16_C(58653), UINT16_C(36620),
      UINT16_C(28374), UINT16_C( 2724), UINT16_C(47955), UINT16_C(40595), UINT16_C(57891), UINT16_C(43978), UINT16_C(63181), UINT16_C(12969),
      UINT16_C( 6259), UINT16_C(16898), UINT16_C(17605), UINT16_C(45787), UINT16_C(35340), UINT16_C(10828), UINT16_C(22639), UINT16_C(17849),
      UINT16_C(24006), UINT16_C( 6735), UINT16_C(58136), UINT16_C(15544), UINT16_C(33477), UINT16_C(37607), UINT16_C(36985), UINT16_C(60613),
      UINT16_C(51113), UINT16_C(28206), UINT16_C( 2315), UINT16_C( 5920), UINT16_C(27795), UINT16_C(  833), UINT16_C(64197), UINT16_C(35656),
      UINT16_C(38999), UINT16_C(28837), UINT16_C(23931), UINT16_C(16556), UINT16_C(37856), UINT16_C(22995), UINT16_C(38947), UINT16_C(52293),
      UINT16_C(29535), UINT16_C(27194), UINT16_C(23420), UINT16_C( 3969), UINT16_C(50119), UINT16_C(35858), UINT16_C(23485), UINT16_C( 5400),
      UINT16_C(48627), UINT16_C(28293), UINT16_C(12571), UINT16_C(64430), UINT16_C(33220), UINT16_C(59220), UINT16_C(39193), UINT16_C(30900),
      UINT16_C(60940), UINT16_C(35042), UINT16_C(25673), UINT16_C( 4503), UINT16_C(43559), UINT16_C(58525), UINT16_C(46341), UINT16_C(63737),
      UINT16_C(32371), UINT16_C(36454), UINT16_C( 5295), UINT16_C(29577), UINT16_C(56726), UINT16_C(44891), UINT16_C( 3958), UINT16_C(33320),
      UINT16_C( 2813), UINT16_C(18186), UINT16_C(41326), UINT16_C(38232), UINT16_C(62795), UINT16_C(20602), UINT16_C(29611), UINT16_C( 7752),
      UINT16_C(44786), UINT16_C(41388), UINT16_C(13763), UINT16_C(22805), UINT16_C(28690), UINT16_C(34824), UINT16_C(12415), UINT16_C(31754),
      UINT16_C( 5179), UINT16_C(43459), UINT16_C( 7093), UINT16_C(  319), UINT16_C(47377), UINT16_C(48209), UINT16_C(39468), UINT16_C( 7898),
      UINT16_C(34376), UINT16_C( 3008), UINT16_C(54715), UINT16_C(52580), UINT16_C(27973), UINT16_C(50261), UINT16_C(24477), UINT16_C(55360),
      UINT16_C( 1139), UINT16_C(10370), UINT16_C(49439), UINT16_C(12329), UINT16_C(31610), UINT16_C(42732), UINT16_C(50709), UINT16_C(24005),
      UINT16_C(34124), UINT16_C( 1897), UINT16_C(52570), UINT16_C(40916), UINT16_C(10554), UINT16_C(55395), UINT16_C(41864), UINT16_C(64432),
      UINT16_C(12967), UINT16_C(50980), UINT16_C(19955), UINT16_C(28151), UINT16_C(58568), UINT16_C(56596), UINT16_C(55722), UINT16_C(63291),
      UINT16_C(42078), UINT16_C(47358), UINT16_C(54129), UINT16_C(44119), UINT16_C(47868), UINT16_C(34180), UINT16_C(13405), UINT16_C( 1408),
      UINT16_C(42087), UINT16_C(23244), UINT16_C(50162), UINT16_C(47816), UINT16_C(56487), UINT16_C(21144), UINT16_C(54197), UINT16_C( 4937),
      UINT16_C(18295), UINT16_C(59595), UINT16_C( 8730), UINT16_C( 6036), UINT16_C( 6364), UINT16_C(14748), UINT16_C( 7245), UINT16_C(46142),
      UINT16_C( 2753), UINT16_C(45838), UINT16_C(54990), UINT16_C(30061), UINT16_C( 1458), UINT16_C(26567), UINT16_C( 4312), UINT16_C(20346),
      UINT16_C(17752), UINT16_C(29240), UINT16_C(52327), UINT16_C(17289), UINT16_C( 9701), UINT16_C(12925), UINT16_C(47938), UINT16_C(  998),
      UINT16_C(62662), UINT16_C(38070), UINT16_C( 9163), UINT16_C(32009), UINT16_C(53545), UINT16_C(  485), UINT16_C(24545), UINT16_C(14673),
      UINT16_C(35237), UINT16_C( 3244), UINT16_C(13653), UINT16_C(14928), UINT16_C(52571), UINT16_C(40300), UINT16_C(21128), UINT16_C(20128),
      UINT16_C(22087), UINT16_C( 4834), UINT16_C(60537), UINT16_C(41615), UINT16_C(29885), UINT16_C(40612), UINT16_C(62932), UINT16_C(31192),
      UINT16_C(33918), UINT16_C(54149), UINT16_C(54713), UINT16_C( 5134), UINT16_C(31394), UINT16_C(11185), UINT16_C(20941), UINT16_C( 5241),
      UINT16_C(23719), UINT16_C( 8486), UINT16_C(46408), UINT16_C( 1475), UINT16_C(26410), UINT16_C(65187), UINT16_C(31580), UINT16_C(55927),
      UINT16_C(64767), UINT16_C(47534), UINT16_C(48338), UINT16_C(29901), UINT16_C(32566), UINT16_C(  927), UINT16_C( 6608), UINT16_C(30743),
      UINT16_C(15733), UINT16_C(48537), UINT16_C(23795), UINT16_C( 7618), UINT16_C(26052), UINT16_C( 8219), UINT16_C(37601), UINT16_C(57595),
      UINT16_C(43406), UINT16_C(24729), UINT16_C(26469), UINT16_C(39893), UINT16_C(29926), UINT16_C(46751), UINT16_C(46733), UINT16_C(  558),
      UINT16_C(51188), UINT16_C(59327), UINT16_C(33060), UINT16_C(59396), UINT16_C( 8167), UINT16_C(51208), UINT16_C(  945), UINT16_C(16296),
      UINT16_C(17068), UINT16_C( 4512), UINT16_C(30121), UINT16_C(36781), UINT16_C(19689), UINT16_C(30533), UINT16_C(29698), UINT16_C(63097),
      UINT16_C(14651), UINT16_C(24541), UINT16_C(57786) };
  static const uint16_t b[] =
    { UINT16_C(18071), UINT16_C(23071), UINT16_C(37998), UINT16_C(58909), UINT16_C(37234), UINT16_C(25521), UINT16_C(32247), UINT16_C(60839),
      UINT16_C(59738), UINT16_C(62954), UINT16_C(54966), UINT16_C(21915), UINT16_C(20008), UINT16_C(23354), UINT16_C(40709), UINT16_C(40102),
      UINT16_C(50661), UINT16_C(21494), UINT16_C( 4953), UINT16_C(52281), UINT16_C(60325), UINT16_C(39983), UINT16_C(54888), UINT16_C(49801),
      UINT16_C(29631), UINT16_C(30391), UINT16_C(21321), UINT16_C(29387), UINT16_C( 1441), UINT16_C(42701), UINT16_C(29605), UINT16_C(35395),
      UINT16_C(14649), UINT16_C(37598), UINT16_C( 5965), UINT16_C(62046), UINT16_C(36098), UINT16_C(27278), UINT16_C( 5988), UINT16_C( 9004),
      UINT16_C(58507), UINT16_C(54425), UINT16_C(25911), UINT16_C(55366), UINT16_C( 4970), UINT16_C( 3967), UINT16_C(49799), UINT16_C(49306),
      UINT16_C(30971), UINT16_C(18514), UINT16_C(45455), UINT16_C(37434), UINT16_C(51262), UINT16_C(41724), UINT16_C(10720), UINT16_C(27590),
      UINT16_C(24333), UINT16_C(17471), UINT16_C(34500), UINT16_C(12060), UINT16_C(39833), UINT16_C( 8254), UINT16_C(55389), UINT16_C(23008),
      UINT16_C(13136), UINT16_C(57505), UINT16_C(56548), UINT16_C( 8818), UINT16_C(28324), UINT16_C(33989), UINT16_C(35735), UINT16_C(42223),
      UINT16_C(12266), UINT16_C(45032), UINT16_C( 1461), UINT16_C(20190), UINT16_C( 7328), UINT16_C(65135), UINT16_C(20469), UINT16_C(17751),
      UINT16_C(63618), UINT16_C(26149), UINT16_C(38868), UINT16_C(31113), UINT16_C(19974), UINT16_C(40445), UINT16_C(60889), UINT16_C(49986),
      UINT16_C(10780), UINT16_C(53618), UINT16_C(20527), UINT16_C(53279), UINT16_C(36461), UINT16_C(25294), UINT16_C( 9694), UINT16_C(24743),
      UINT16_C(52509), UINT16_C(62151), UINT16_C(20580), UINT16_C(27243), UINT16_C(26782), UINT16_C(30472), UINT16_C(19029), UINT16_C(28986),
      UINT16_C(44404), UINT16_C(42050), UINT16_C(25341), UINT16_C(27252), UINT16_C(17136), UINT16_C(52940), UINT16_C(29799), UINT16_C(33839),
      UINT16_C(63041), UINT16_C(42358), UINT16_C(57670), UINT16_C(58384), UINT16_C( 6218), UINT16_C(40795), UINT16_C(38242), UINT16_C(54801),
      UINT16_C(21314), UINT16_C(16506), UINT16_C(61109), UINT16_C(42666), UINT16_C(30512), UINT16_C(38772), UINT16_C(41963), UINT16_C(11292),
      UINT16_C(37529), UINT16_C(57297), UINT16_C(57716), UINT16_C(48835), UINT16_C( 7929), UINT16_C(23389), UINT16_C(28340), UINT16_C(63026),
      UINT16_C(44226), UINT16_C(30518), UINT16_C(57755), UINT16_C(51997), UINT16_C(37464), UINT16_C(17251), UINT16_C(32565), UINT16_C(53103),
      UINT16_C(16401), UINT16_C(34222), UINT16_C(29218), UINT16_C( 6979), UINT16_C(41360), UINT16_C(17527), UINT16_C(43279), UINT16_C(53563),
      UINT16_C(29013), UINT16_C(61513), UINT16_C(26194), UINT16_C(43708), UINT16_C( 8184), UINT16_C(12013), UINT16_C(23710), UINT16_C(45053),
      UINT16_C(43933), UINT16_C(48949), UINT16_C(30749), UINT16_C(44762), UINT16_C(20761), UINT16_C(10738), UINT16_C(11770), UINT16_C(20730),
      UINT16_C(17311), UINT16_C(61760), UINT16_C(64682), UINT16_C(41628), UINT16_C(35099), UINT16_C(47568), UINT16_C(52710), UINT16_C(33641),
      UINT16_C(40569), UINT16_C(38466), UINT16_C( 7190), UINT16_C(12356), UINT16_C(14190), UINT16_C(26713), UINT16_C(21348), UINT16_C(  952),
      UINT16_C(63895), UINT16_C(16885), UINT16_C(37365), UINT16_C( 4579), UINT16_C(46106), UINT16_C(  202), UINT16_C(13185), UINT16_C(64131),
      UINT16_C(50641), UINT16_C(59537), UINT16_C(54754), UINT16_C(20504), UINT16_C(28940), UINT16_C(29112), UINT16_C(29124), UINT16_C(23412),
      UINT16_C(26986), UINT16_C(24476), UINT16_C(33018), UINT16_C( 5488), UINT16_C(15156), UINT16_C(46357), UINT16_C(39278), UINT16_C(16560),
      UINT16_C(16734), UINT16_C(16424), UINT16_C(16406), UINT16_C( 9104), UINT16_C(18865), UINT16_C(30100), UINT16_C( 2234), UINT16_C( 9425),
      UINT16_C(28018), UINT16_C(27779), UINT16_C(62701), UINT16_C( 8577), UINT16_C(38703), UINT16_C(40407), UINT16_C(34608), UINT16_C(36573),
      UINT16_C( 1480), UINT16_C(57039), UINT16_C(24389), UINT16_C(62977), UINT16_C(38312), UINT16_C(25196), UINT16_C(15774), UINT16_C( 4230),
      UINT16_C( 2730), UINT16_C(39036), UINT16_C(65278), UINT16_C(11705), UINT16_C(37013), UINT16_C(50634), UINT16_C(43031), UINT16_C(57171),
      UINT16_C( 8877), UINT16_C(62398), UINT16_C(49026), UINT16_C(10985), UINT16_C(21845), UINT16_C(62349), UINT16_C( 5010), UINT16_C(15619),
      UINT16_C(32541), UINT16_C( 7125), UINT16_C(36477), UINT16_C( 4680), UINT16_C( 4895), UINT16_C(14039), UINT16_C(11195), UINT16_C(26646),
      UINT16_C(54349), UINT16_C(53083), UINT16_C(17811), UINT16_C(59642), UINT16_C(34714), UINT16_C(11739), UINT16_C(56986), UINT16_C(47210),
      UINT16_C(16222), UINT16_C(56275), UINT16_C( 7373), UINT16_C(60654), UINT16_C(50479), UINT16_C(59939), UINT16_C(14832), UINT16_C(15954),
      UINT16_C(44557), UINT16_C(40973), UINT16_C( 2035), UINT16_C(36233), UINT16_C(25742), UINT16_C(10682), UINT16_C( 9283), UINT16_C(41441),
      UINT16_C(46179), UINT16_C(12668), UINT16_C(27344), UINT16_C(65309), UINT16_C(16432), UINT16_C( 8425), UINT16_C(15481), UINT16_C(34398),
      UINT16_C(27882), UINT16_C(56615), UINT16_C(45171), UINT16_C(  618), UINT16_C( 9492), UINT16_C(22315), UINT16_C( 3145), UINT16_C(44536),
      UINT16_C(30144), UINT16_C(37342), UINT16_C(64479), UINT16_C( 3984), UINT16_C(31292), UINT16_C(46384), UINT16_C(36534), UINT16_C(41020),
      UINT16_C(25594), UINT16_C(28285), UINT16_C(59155), UINT16_C(10096), UINT16_C(39692), UINT16_C(22143), UINT16_C(30631), UINT16_C(26371),
      UINT16_C(57836), UINT16_C(52472), UINT16_C(35292), UINT16_C( 6363), UINT16_C( 2819), UINT16_C(47566), UINT16_C( 2714), UINT16_C(37977),
      UINT16_C(54893), UINT16_C(32770), UINT16_C(29373), UINT16_C(51879), UINT16_C( 9741), UINT16_C(46112), UINT16_C( 9118), UINT16_C(35356),
      UINT16_C( 5124), UINT16_C(57430), UINT16_C(12957), UINT16_C(41209), UINT16_C(51005), UINT16_C(55129), UINT16_C(45777), UINT16_C(15980),
      UINT16_C(28296), UINT16_C(18110), UINT16_C(26081), UINT16_C(60944), UINT16_C(12428), UINT16_C(10915), UINT16_C(48979), UINT16_C(22452),
      UINT16_C( 3027), UINT16_C(28983), UINT16_C(12349), UINT16_C(31249), UINT16_C(27639), UINT16_C(51282), UINT16_C(48669), UINT16_C(42502),
      UINT16_C(50220), UINT16_C( 3564), UINT16_C(64554), UINT16_C(46844), UINT16_C(40748), UINT16_C(32736), UINT16_C(37982), UINT16_C(12758),
      UINT16_C( 3487), UINT16_C(56482), UINT16_C(46142), UINT16_C(13655), UINT16_C(43295), UINT16_C(15614), UINT16_C( 1127), UINT16_C(37858),
      UINT16_C(52937), UINT16_C(62369), UINT16_C(40394), UINT16_C(63145), UINT16_C(35132), UINT16_C(39541), UINT16_C(19229), UINT16_C(48587),
      UINT16_C(28249), UINT16_C(38809), UINT16_C(61474), UINT16_C(16844), UINT16_C(51865), UINT16_C(  125), UINT16_C(24783), UINT16_C(39060),
      UINT16_C(13614), UINT16_C(63883), UINT16_C(13522), UINT16_C( 3823), UINT16_C(26045), UINT16_C(55976), UINT16_C(29616), UINT16_C( 2455),
      UINT16_C(12769), UINT16_C(  928), UINT16_C(27937), UINT16_C(47940), UINT16_C(49719), UINT16_C( 1723), UINT16_C(20258), UINT16_C(20638),
      UINT16_C(10628), UINT16_C(22089), UINT16_C(14685), UINT16_C( 6756), UINT16_C( 3230), UINT16_C(20213), UINT16_C(35968), UINT16_C(24920),
      UINT16_C(63677), UINT16_C(57189), UINT16_C(43365), UINT16_C(40346), UINT16_C(21867), UINT16_C(36259), UINT16_C(17061), UINT16_C(10718),
      UINT16_C(10091), UINT16_C(51584), UINT16_C(58464), UINT16_C(65251), UINT16_C(55537), UINT16_C(29005), UINT16_C(42341), UINT16_C( 8914),
      UINT16_C(14237), UINT16_C(  769), UINT16_C(39905), UINT16_C(19616), UINT16_C(17393), UINT16_C(38618), UINT16_C(47237), UINT16_C(61887),
      UINT16_C(16351), UINT16_C(16570), UINT16_C(40228), UINT16_C( 5438), UINT16_C(35702), UINT16_C(56198), UINT16_C(22576), UINT16_C(52989),
      UINT16_C(65424), UINT16_C(29137), UINT16_C(29082), UINT16_C(35773), UINT16_C(38836), UINT16_C(14881), UINT16_C(57679), UINT16_C(12075),
      UINT16_C(58656), UINT16_C(17519), UINT16_C(44418), UINT16_C(63577), UINT16_C(57145), UINT16_C(27091), UINT16_C(53560), UINT16_C(51255),
      UINT16_C( 2256), UINT16_C(27193), UINT16_C(63097), UINT16_C(12022), UINT16_C( 6030), UINT16_C(56680), UINT16_C(37880), UINT16_C( 6412),
      UINT16_C(31608), UINT16_C(64093), UINT16_C(46889), UINT16_C(25331), UINT16_C(50838), UINT16_C(52939), UINT16_C(  919), UINT16_C(26518),
      UINT16_C(53003), UINT16_C(34258), UINT16_C(51398), UINT16_C(21683), UINT16_C( 7135), UINT16_C(55345), UINT16_C(16046), UINT16_C( 9969),
      UINT16_C(20153), UINT16_C(57888), UINT16_C( 4869) };
  static const uint16_t e[] =
    { UINT16_C(38915), UINT16_C(40419), UINT16_C(55253), UINT16_C(63615), UINT16_C(57571), UINT16_C(59992), UINT16_C(60761), UINT16_C( 1767),
      UINT16_C(25782), UINT16_C(17060), UINT16_C(40945), UINT16_C(36475), UINT16_C(49098), UINT16_C(59599), UINT16_C(33059), UINT16_C(35212),
      UINT16_C( 5401), UINT16_C( 2509), UINT16_C(12073), UINT16_C( 2844), UINT16_C(44468), UINT16_C(27026), UINT16_C(53681), UINT16_C(26242),
      UINT16_C(45046), UINT16_C(59499), UINT16_C(33102), UINT16_C( 6348), UINT16_C(53151), UINT16_C(25436), UINT16_C( 6833), UINT16_C(58950),
      UINT16_C( 4971), UINT16_C( 9933), UINT16_C( 2882), UINT16_C(17405), UINT16_C(12749), UINT16_C(59464), UINT16_C(21350), UINT16_C(23825),
      UINT16_C(31746), UINT16_C(20805), UINT16_C(44230), UINT16_C(25891), UINT16_C(50919), UINT16_C(15776), UINT16_C(26317), UINT16_C(14355),
      UINT16_C(31350), UINT16_C(48332), UINT16_C(27149), UINT16_C(55822), UINT16_C(37337), UINT16_C(40280), UINT16_C(26340), UINT16_C(59293),
      UINT16_C(33749), UINT16_C(39929), UINT16_C(41459), UINT16_C(55837), UINT16_C( 8910), UINT16_C(39898), UINT16_C(60810), UINT16_C(  980),
      UINT16_C(54080), UINT16_C(56418), UINT16_C(53002), UINT16_C(42454), UINT16_C(40252), UINT16_C(39747), UINT16_C(42243), UINT16_C(16408),
      UINT16_C( 3997), UINT16_C(51933), UINT16_C(58337), UINT16_C(18517), UINT16_C(20737), UINT16_C(34820), UINT16_C(47410), UINT16_C(29414),
      UINT16_C(20490), UINT16_C( 5162), UINT16_C(   31), UINT16_C(12098), UINT16_C(64558), UINT16_C(39251), UINT16_C(27158), UINT16_C(30237),
      UINT16_C(47227), UINT16_C(42879), UINT16_C(18117), UINT16_C(26304), UINT16_C(14150), UINT16_C(58863), UINT16_C(44960), UINT16_C( 2648),
      UINT16_C(55808), UINT16_C( 4484), UINT16_C(30426), UINT16_C( 2261), UINT16_C(36881), UINT16_C(  426), UINT16_C(32147), UINT16_C(32631),
      UINT16_C(26794), UINT16_C(52149), UINT16_C(47022), UINT16_C(63330), UINT16_C(33420), UINT16_C(64071), UINT16_C(11059), UINT16_C(46852),
      UINT16_C(37637), UINT16_C(33992), UINT16_C( 2384), UINT16_C(32231), UINT16_C(41625), UINT16_C(33122), UINT16_C(55913), UINT16_C( 4864),
      UINT16_C(41984), UINT16_C(61827), UINT16_C(27386), UINT16_C(11090), UINT16_C( 8686), UINT16_C( 8370), UINT16_C(10808), UINT16_C(32367),
      UINT16_C(14515), UINT16_C( 9010), UINT16_C(64065), UINT16_C(55909), UINT16_C(43171), UINT16_C(43775), UINT16_C(23713), UINT16_C(58393),
      UINT16_C(61330), UINT16_C(35999), UINT16_C(10229), UINT16_C( 4910), UINT16_C(21697), UINT16_C(46696), UINT16_C(15231), UINT16_C(25353),
      UINT16_C(31603), UINT16_C(46134), UINT16_C(10579), UINT16_C( 4750), UINT16_C(18642), UINT16_C(49057), UINT16_C(34872), UINT16_C(51885),
      UINT16_C(19577), UINT16_C(50078), UINT16_C(52452), UINT16_C(64283), UINT16_C(41505), UINT16_C(41119), UINT16_C( 6109), UINT16_C(41173),
      UINT16_C(23797), UINT16_C( 1796), UINT16_C(37795), UINT16_C( 1561), UINT16_C(57444), UINT16_C(39448), UINT16_C(62051), UINT16_C(12639),
      UINT16_C(64943), UINT16_C(41652), UINT16_C(52170), UINT16_C(60217), UINT16_C(55406), UINT16_C(19339), UINT16_C(36873), UINT16_C(33180),
      UINT16_C(41062), UINT16_C( 2440), UINT16_C(34333), UINT16_C(32971), UINT16_C(57957), UINT16_C(13941), UINT16_C(54539), UINT16_C(47719),
      UINT16_C(23762), UINT16_C(23129), UINT16_C(62770), UINT16_C(33700), UINT16_C(24133), UINT16_C(20193), UINT16_C(32112), UINT16_C(54991),
      UINT16_C(37196), UINT16_C(26958), UINT16_C( 6679), UINT16_C(31978), UINT16_C( 1532), UINT16_C(41547), UINT16_C(27468), UINT16_C( 8142),
      UINT16_C(45917), UINT16_C(61115), UINT16_C(49833), UINT16_C(  644), UINT16_C(10785), UINT16_C(50512), UINT16_C(34420), UINT16_C(48875),
      UINT16_C(14873), UINT16_C(12328), UINT16_C( 4692), UINT16_C(20141), UINT16_C(63513), UINT16_C(41202), UINT16_C(19698), UINT16_C(29493),
      UINT16_C(33791), UINT16_C(43230), UINT16_C(58676), UINT16_C(35095), UINT16_C(26698), UINT16_C(11343), UINT16_C(25431), UINT16_C(65068),
      UINT16_C(30365), UINT16_C(53103), UINT16_C(19850), UINT16_C(39234), UINT16_C(51437), UINT16_C(39343), UINT16_C(58653), UINT16_C(32390),
      UINT16_C(28374), UINT16_C(29224), UINT16_C(48213), UINT16_C(40595), UINT16_C(57891), UINT16_C(58880), UINT16_C(20150), UINT16_C(21334),
      UINT16_C( 6259), UINT16_C(16898), UINT16_C(34115), UINT16_C(45787), UINT16_C(13495), UINT16_C(14015), UINT16_C(22639), UINT16_C(17849),
      UINT16_C(24006), UINT16_C(65146), UINT16_C(21659), UINT16_C(15544), UINT16_C(28582), UINT16_C(23568), UINT16_C(25790), UINT16_C(60613),
      UINT16_C(62300), UINT16_C(28206), UINT16_C(50040), UINT16_C( 5920), UINT16_C(27795), UINT16_C(54630), UINT16_C( 7211), UINT16_C(53982),
      UINT16_C(22777), UINT16_C(28837), UINT16_C(16558), UINT16_C(21438), UINT16_C(37856), UINT16_C(28592), UINT16_C(24115), UINT16_C(36339),
      UINT16_C(50514), UINT16_C(51757), UINT16_C(21385), UINT16_C(33272), UINT16_C(50119), UINT16_C(35858), UINT16_C(14202), UINT16_C(29495),
      UINT16_C( 2448), UINT16_C(28293), UINT16_C(12571), UINT16_C(64657), UINT16_C(16788), UINT16_C(59220), UINT16_C(23712), UINT16_C(62038),
      UINT16_C(60940), UINT16_C(35042), UINT16_C(25673), UINT16_C( 4503), UINT16_C(34067), UINT16_C(58525), UINT16_C(43196), UINT16_C(63737),
      UINT16_C( 2227), UINT16_C(64648), UINT16_C( 5295), UINT16_C(29577), UINT16_C(25434), UINT16_C(64043), UINT16_C( 3958), UINT16_C(57836),
      UINT16_C( 2813), UINT16_C(18186), UINT16_C(47707), UINT16_C(28136), UINT16_C(62795), UINT16_C(63995), UINT16_C(64516), UINT16_C( 7752),
      UINT16_C(44786), UINT16_C(41388), UINT16_C(13763), UINT16_C(22805), UINT16_C(25871), UINT16_C(34824), UINT16_C( 9701), UINT16_C(31754),
      UINT16_C( 5179), UINT16_C(43459), UINT16_C( 7093), UINT16_C(  319), UINT16_C(37636), UINT16_C( 2097), UINT16_C(30350), UINT16_C(38078),
      UINT16_C(34376), UINT16_C( 3008), UINT16_C(54715), UINT16_C(11371), UINT16_C(27973), UINT16_C(60668), UINT16_C(24477), UINT16_C(55360),
      UINT16_C( 1139), UINT16_C(10370), UINT16_C(23358), UINT16_C(16921), UINT16_C(19182), UINT16_C(31817), UINT16_C(50709), UINT16_C(24005),
      UINT16_C(31097), UINT16_C(38450), UINT16_C(40221), UINT16_C( 9667), UINT16_C(10554), UINT16_C( 4113), UINT16_C(41864), UINT16_C(21930),
      UINT16_C(12967), UINT16_C(50980), UINT16_C(19955), UINT16_C(46843), UINT16_C(17820), UINT16_C(56596), UINT16_C(55722), UINT16_C(50533),
      UINT16_C(42078), UINT16_C(47358), UINT16_C( 7987), UINT16_C(30464), UINT16_C(47868), UINT16_C(18566), UINT16_C(13405), UINT16_C(29086),
      UINT16_C(54686), UINT16_C(23244), UINT16_C(50162), UINT16_C(47816), UINT16_C(21355), UINT16_C(47139), UINT16_C(54197), UINT16_C(21886),
      UINT16_C(18295), UINT16_C(20786), UINT16_C(12792), UINT16_C( 6036), UINT16_C(20035), UINT16_C(14748), UINT16_C(47998), UINT16_C(46142),
      UINT16_C( 2753), UINT16_C(47491), UINT16_C(41468), UINT16_C(26238), UINT16_C(40949), UINT16_C(26567), UINT16_C(40232), UINT16_C(17891),
      UINT16_C( 4983), UINT16_C(29240), UINT16_C(24390), UINT16_C(17289), UINT16_C( 9701), UINT16_C(12925), UINT16_C(47938), UINT16_C(  998),
      UINT16_C(62662), UINT16_C(15981), UINT16_C( 9163), UINT16_C(25253), UINT16_C(53545), UINT16_C(45808), UINT16_C(24545), UINT16_C(55289),
      UINT16_C(37096), UINT16_C( 3244), UINT16_C(13653), UINT16_C(14928), UINT16_C(30704), UINT16_C( 4041), UINT16_C( 4067), UINT16_C( 9410),
      UINT16_C(22087), UINT16_C(18786), UINT16_C( 2073), UINT16_C(41615), UINT16_C(29885), UINT16_C(11607), UINT16_C(62932), UINT16_C(31192),
      UINT16_C(19681), UINT16_C(53380), UINT16_C(54713), UINT16_C(51054), UINT16_C(14001), UINT16_C(11185), UINT16_C(39240), UINT16_C( 5241),
      UINT16_C( 7368), UINT16_C(57452), UINT16_C( 6180), UINT16_C(61573), UINT16_C(56244), UINT16_C(65187), UINT16_C(31580), UINT16_C(55927),
      UINT16_C(64879), UINT16_C(18397), UINT16_C(48338), UINT16_C(29901), UINT16_C(59266), UINT16_C(51582), UINT16_C(14465), UINT16_C(18668),
      UINT16_C(22613), UINT16_C(31018), UINT16_C(23795), UINT16_C( 7618), UINT16_C(34443), UINT16_C(46664), UINT16_C(37601), UINT16_C( 6340),
      UINT16_C(43406), UINT16_C(24729), UINT16_C(26469), UINT16_C(39893), UINT16_C(29926), UINT16_C(46751), UINT16_C(46733), UINT16_C(  558),
      UINT16_C(51188), UINT16_C(60770), UINT16_C(33060), UINT16_C(34065), UINT16_C( 8167), UINT16_C(63805), UINT16_C(   26), UINT16_C(55314),
      UINT16_C(29601), UINT16_C(35790), UINT16_C(30121), UINT16_C(15098), UINT16_C(19689), UINT16_C(40724), UINT16_C(13652), UINT16_C(53128),
      UINT16_C(14651), UINT16_C(32189), UINT16_C(52917) };

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
    rv = simde_svsub_u16_m(pv, av, bv);

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

    ev = simde_svsub_u16_m(pv, av, bv);

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
test_simde_svsub_u32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0) };
  static const uint32_t a[] =
    { UINT32_C(1841778736), UINT32_C(2581575430), UINT32_C(2962518756), UINT32_C(3387442945), UINT32_C(3802890136), UINT32_C( 677389464), UINT32_C(3660296918), UINT32_C(3215606671),
      UINT32_C(2569892243), UINT32_C( 221383721), UINT32_C(2143143806), UINT32_C(2789778702), UINT32_C(3179869221), UINT32_C(4024822040), UINT32_C( 734597531), UINT32_C(3907679316),
      UINT32_C( 243341285), UINT32_C(2703012899), UINT32_C(2300631419), UINT32_C(2754636159), UINT32_C(1969338461), UINT32_C(1029981857), UINT32_C(2892508759), UINT32_C(2274644642),
      UINT32_C(2375423338), UINT32_C(1143976649), UINT32_C( 181292939), UINT32_C( 363790008), UINT32_C(1485508534), UINT32_C(2912284502), UINT32_C(3210345757), UINT32_C(3108498767),
      UINT32_C(3427261699), UINT32_C( 437352079), UINT32_C(2116411333), UINT32_C(2475938781), UINT32_C( 971710179), UINT32_C( 736526350), UINT32_C(3454746749), UINT32_C( 814101037),
      UINT32_C(2667433231), UINT32_C( 163057219), UINT32_C(3397901805), UINT32_C(2489129649), UINT32_C(1204635961), UINT32_C(1198699465), UINT32_C( 554982899), UINT32_C(2656148111),
      UINT32_C(2872856168), UINT32_C(1236596060), UINT32_C(2199075794), UINT32_C(2400678230), UINT32_C(2211898554), UINT32_C(2345289880), UINT32_C( 900521638), UINT32_C(3788832377),
      UINT32_C(2844528716), UINT32_C(3639755013), UINT32_C(3529180796), UINT32_C( 828470135), UINT32_C(4021565271), UINT32_C( 645627776), UINT32_C(3596298077), UINT32_C(1924607781),
      UINT32_C(1159414848), UINT32_C(  18681221), UINT32_C(2329180435), UINT32_C(1136342508), UINT32_C(3979571309), UINT32_C(1276358383), UINT32_C(4213403349), UINT32_C(3731741342),
      UINT32_C(2737014814), UINT32_C(2846179733), UINT32_C(2788391354), UINT32_C( 468316078), UINT32_C(1309154399), UINT32_C(2694454218), UINT32_C( 681295242), UINT32_C(3053848728),
      UINT32_C( 626665872), UINT32_C( 617545578), UINT32_C( 650773112), UINT32_C(1346548977), UINT32_C(2610842320), UINT32_C(4030412902), UINT32_C(2383992566), UINT32_C(1849958110),
      UINT32_C(2996018759), UINT32_C( 366371485), UINT32_C(1430036836), UINT32_C( 631602773), UINT32_C( 784352200), UINT32_C(1897855867), UINT32_C(2952738513), UINT32_C(2619163732),
      UINT32_C(2152640994), UINT32_C(2006262803), UINT32_C( 449630661), UINT32_C( 406876495), UINT32_C( 793116852), UINT32_C(3449906684), UINT32_C(4034764955), UINT32_C(3347880676),
      UINT32_C(1581767243), UINT32_C(3302350078), UINT32_C(4259226030), UINT32_C(3323272722), UINT32_C( 469130271), UINT32_C(1558747073), UINT32_C( 474768695), UINT32_C(1273223168),
      UINT32_C(2980719282), UINT32_C(3027599110), UINT32_C( 867324705), UINT32_C(2449131378), UINT32_C(3836538915), UINT32_C(3191968903), UINT32_C(4208627194), UINT32_C( 407223654),
      UINT32_C(4006211559), UINT32_C(2426551919), UINT32_C(  79910034), UINT32_C(1066777884), UINT32_C( 874791341), UINT32_C(3488835029), UINT32_C(1489620466), UINT32_C(1920012171),
      UINT32_C(1835023102), UINT32_C( 201130873), UINT32_C(1930412375), UINT32_C( 749970558), UINT32_C(3126908901), UINT32_C( 780817212), UINT32_C(2894549793), UINT32_C(1629419618),
      UINT32_C(2882436914), UINT32_C(3652635778), UINT32_C( 189646221), UINT32_C(1312227433), UINT32_C( 319396055), UINT32_C( 205624299), UINT32_C(1236846822), UINT32_C(4088059840),
      UINT32_C(3634264150), UINT32_C(3518059844), UINT32_C(2229141018), UINT32_C(3587314942), UINT32_C(2565397420), UINT32_C(1436822126), UINT32_C(3013500402), UINT32_C(2326153268),
      UINT32_C(  90326208), UINT32_C(3033928601), UINT32_C( 272151314), UINT32_C(1961233096), UINT32_C(1410125542), UINT32_C(3953766904), UINT32_C(1117669134), UINT32_C(1355564175),
      UINT32_C( 576007816), UINT32_C(1406544705), UINT32_C(2808352479), UINT32_C(4263201304), UINT32_C( 290662424), UINT32_C(3892116697), UINT32_C(3542719044), UINT32_C(1713632734),
      UINT32_C(1686665251), UINT32_C(2209898148), UINT32_C(2234129516), UINT32_C(2122532198), UINT32_C(1183831661), UINT32_C( 388860883), UINT32_C(  65689125), UINT32_C(1852444235),
      UINT32_C( 718533254), UINT32_C(3182267217) };
  static const uint32_t b[] =
    { UINT32_C( 364294876), UINT32_C( 857973599), UINT32_C(2920684002), UINT32_C( 170889941), UINT32_C(  51292216), UINT32_C(2900645108), UINT32_C(1659775255), UINT32_C(3838029320),
      UINT32_C(3237575264), UINT32_C(4294122525), UINT32_C( 179177781), UINT32_C(3558137244), UINT32_C(2044207749), UINT32_C(2384837751), UINT32_C(3991933925), UINT32_C( 584168642),
      UINT32_C(1273154094), UINT32_C( 457954790), UINT32_C(2066151903), UINT32_C(1531919062), UINT32_C(3570673501), UINT32_C(3378706916), UINT32_C(3484898061), UINT32_C( 905021447),
      UINT32_C( 964744275), UINT32_C(2287324073), UINT32_C(2583919556), UINT32_C( 318067637), UINT32_C(1592183162), UINT32_C(3492301251), UINT32_C(2745163676), UINT32_C(3134754919),
      UINT32_C( 250894436), UINT32_C(3902163236), UINT32_C(2038667972), UINT32_C(1737259245), UINT32_C(  96891458), UINT32_C(1473638075), UINT32_C( 888829133), UINT32_C(1777324548),
      UINT32_C(1333257003), UINT32_C(4030139692), UINT32_C(2489957031), UINT32_C(1979512115), UINT32_C( 595247720), UINT32_C(2105233328), UINT32_C(3350296003), UINT32_C(1932566600),
      UINT32_C(2948769667), UINT32_C(1553988021), UINT32_C(3891333556), UINT32_C(1717366270), UINT32_C(1602934447), UINT32_C(3906733349), UINT32_C(3266284922), UINT32_C(2973098030),
      UINT32_C(1013053319), UINT32_C(2778267889), UINT32_C( 143428105), UINT32_C( 644802679), UINT32_C(3817207998), UINT32_C(2026594813), UINT32_C( 473594606), UINT32_C(3805179994),
      UINT32_C(1478373223), UINT32_C( 972928815), UINT32_C(3091302721), UINT32_C( 803123057), UINT32_C(2769445800), UINT32_C(3005078980), UINT32_C(2999933016), UINT32_C( 798268872),
      UINT32_C(4236817356), UINT32_C(2889188714), UINT32_C(2154067471), UINT32_C(3450880805), UINT32_C(1802748582), UINT32_C(4162752672), UINT32_C(2963992040), UINT32_C(1474314123),
      UINT32_C(1548970226), UINT32_C(4228417773), UINT32_C( 612199934), UINT32_C(1458646448), UINT32_C(2411816175), UINT32_C(3716669429), UINT32_C(1485714125), UINT32_C(1672441457),
      UINT32_C(3284075478), UINT32_C(2327890059), UINT32_C(3853401397), UINT32_C(1497079658), UINT32_C(4192861444), UINT32_C(2849403100), UINT32_C( 318858402), UINT32_C(2826351058),
      UINT32_C(1064056500), UINT32_C( 868822270), UINT32_C(3541596009), UINT32_C( 455889687), UINT32_C( 756290896), UINT32_C( 685173382), UINT32_C( 557635663), UINT32_C(1036694153),
      UINT32_C(3866900200), UINT32_C(3407431266), UINT32_C(3567137213), UINT32_C(3589261957), UINT32_C(1711408096), UINT32_C(1032772078), UINT32_C( 979290801), UINT32_C(1702307965),
      UINT32_C(3226268510), UINT32_C(4153107769), UINT32_C( 483076503), UINT32_C(3572612084), UINT32_C(2889544894), UINT32_C(2129250509), UINT32_C( 280512659), UINT32_C(3480563568),
      UINT32_C(1552924962), UINT32_C(3193117479), UINT32_C( 953818692), UINT32_C(2550975449), UINT32_C(2353284799), UINT32_C(2718576143), UINT32_C(3870474870), UINT32_C( 347416561),
      UINT32_C( 275793385), UINT32_C(2765013856), UINT32_C(3151866081), UINT32_C( 861137267), UINT32_C(1069520688), UINT32_C(1004653253), UINT32_C(2116195212), UINT32_C(2744309690),
      UINT32_C(2092106268), UINT32_C(2787213765), UINT32_C(2640444969), UINT32_C( 399553767), UINT32_C( 290885452), UINT32_C(3863820121), UINT32_C(2237951946), UINT32_C(1663628870),
      UINT32_C(3185564920), UINT32_C(2271412317), UINT32_C(3861169662), UINT32_C(3321754745), UINT32_C(3721876611), UINT32_C(1455629451), UINT32_C(3655018387), UINT32_C( 356254493),
      UINT32_C(1037180127), UINT32_C( 465843484), UINT32_C(1946282234), UINT32_C(1597636316), UINT32_C(3728478290), UINT32_C(3342139188), UINT32_C(1134628646), UINT32_C(4065910034),
      UINT32_C( 372189945), UINT32_C(1513223008), UINT32_C(3083743963), UINT32_C(2199259184), UINT32_C(1298223896), UINT32_C(2031392082), UINT32_C(3065820580), UINT32_C(2359825811),
      UINT32_C(2678249279), UINT32_C(2784678858), UINT32_C( 912050181), UINT32_C(3921245136), UINT32_C( 406198982), UINT32_C(1402030767), UINT32_C(2466860544), UINT32_C(2719986275),
      UINT32_C(1413661321), UINT32_C(2616802453) };
  static const uint32_t e[] =
    { UINT32_C(1477483860), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(3751597920), UINT32_C(2071711652), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C( 222228492), UINT32_C(1963966025), UINT32_C(         0), UINT32_C(         0), UINT32_C(1639984289), UINT32_C(1037630902), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(2245058109), UINT32_C(         0), UINT32_C(         0), UINT32_C(2693632256), UINT32_C(         0), UINT32_C(3702577994), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(3151619872), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(3714950547), UINT32_C( 465182081), UINT32_C(         0),
      UINT32_C(3176367263), UINT32_C( 830156139), UINT32_C(  77743361), UINT32_C( 738679536), UINT32_C( 874818721), UINT32_C(         0), UINT32_C(         0), UINT32_C(3331743785),
      UINT32_C(         0), UINT32_C( 427884823), UINT32_C(         0), UINT32_C( 509617534), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(2602709534), UINT32_C( 683311960), UINT32_C(         0), UINT32_C(         0), UINT32_C(1929204012), UINT32_C( 815734347),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(3385752691), UINT32_C(         0), UINT32_C(         0), UINT32_C(2914000259), UINT32_C(3122703471), UINT32_C(2414395083),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 333219451), UINT32_C(1210125509), UINT32_C(2566246699), UINT32_C(         0), UINT32_C(2933472470),
      UINT32_C(2795164754), UINT32_C(4251958315), UINT32_C( 634323883), UINT32_C(1312402569), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(3372662942), UINT32_C(         0), UINT32_C(  38573178), UINT32_C(4182869825), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 177516653),
      UINT32_C(4006910577), UINT32_C(         0), UINT32_C(1871602735), UINT32_C(3429490411), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(4087779970),
      UINT32_C(1088584494), UINT32_C(1137440533), UINT32_C(         0), UINT32_C(4245954104), UINT32_C(  36825956), UINT32_C(         0), UINT32_C(3477129292), UINT32_C(         0),
      UINT32_C(2009834339), UINT32_C(         0), UINT32_C( 692088817), UINT32_C(4028978061), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(3865882499),
      UINT32_C(         0), UINT32_C(3169458637), UINT32_C(         0), UINT32_C(3171486590), UINT32_C( 946994021), UINT32_C(1062718394), UINT32_C(3928114535), UINT32_C(         0),
      UINT32_C(2453286597), UINT32_C(         0), UINT32_C(3421058638), UINT32_C(2810769731), UINT32_C(2816473838), UINT32_C( 770258886), UINT32_C(1914112892), UINT32_C(1572595610),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 778354581), UINT32_C(3180077224),
      UINT32_C(         0), UINT32_C( 865422013), UINT32_C(1844168548), UINT32_C(         0), UINT32_C(  28510603), UINT32_C(         0), UINT32_C(3293862172), UINT32_C(2424430970),
      UINT32_C(         0), UINT32_C(1246647527), UINT32_C(2662938652), UINT32_C( 265560197), UINT32_C(3138488105), UINT32_C(         0), UINT32_C(         0), UINT32_C(1969898775),
      UINT32_C(         0), UINT32_C(2568085117), UINT32_C(         0), UINT32_C(         0), UINT32_C(1976614548), UINT32_C( 611627716), UINT32_C(4278007784), UINT32_C(         0),
      UINT32_C( 203817871), UINT32_C(4188288993), UINT32_C(4019575812), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(1322079335), UINT32_C(2496254358), UINT32_C(         0), UINT32_C(3281797412), UINT32_C(1893795877), UINT32_C(3427425256),
      UINT32_C(3599839229), UINT32_C(         0) };

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
    rv = simde_svsub_u32_z(pv, av, bv);

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

    ev = simde_svsub_u32_z(pv, av, bv);

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
test_simde_svsub_u32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) };
  static const uint32_t a[] =
    { UINT32_C(2256348303), UINT32_C(2491264142), UINT32_C( 699024004), UINT32_C(3590608679), UINT32_C(1212740300), UINT32_C(3271455966), UINT32_C( 398129246), UINT32_C(2539742983),
      UINT32_C( 421387915), UINT32_C( 246258314), UINT32_C(  70801629), UINT32_C(2094677167), UINT32_C( 230957871), UINT32_C(4124033687), UINT32_C(3255601595), UINT32_C(2069458416),
      UINT32_C(3583342411), UINT32_C(4007936529), UINT32_C(1257381018), UINT32_C(2277952856), UINT32_C(2274659056), UINT32_C( 142435149), UINT32_C(3721038317), UINT32_C(1113138423),
      UINT32_C(2887315099), UINT32_C(3415997488), UINT32_C(1880460568), UINT32_C(1257823066), UINT32_C(3000142949), UINT32_C(3719974896), UINT32_C(3485107672), UINT32_C(1142035369),
      UINT32_C( 854600193), UINT32_C(1056803622), UINT32_C(1940787737), UINT32_C(1388226285), UINT32_C( 587567155), UINT32_C(3070279647), UINT32_C(3985095236), UINT32_C(3476134350),
      UINT32_C(3909165763), UINT32_C(3324509869), UINT32_C(4248491280), UINT32_C(2941319292), UINT32_C(1741837704), UINT32_C(1495192084), UINT32_C(1514579340), UINT32_C(  19560510),
      UINT32_C(1206528922), UINT32_C( 974000426), UINT32_C(1664633063), UINT32_C(3356657728), UINT32_C(4046447837), UINT32_C(1112165814), UINT32_C( 832410099), UINT32_C(2738079497),
      UINT32_C( 485105138), UINT32_C( 374863919), UINT32_C(2155450176), UINT32_C(4098394903), UINT32_C( 635795311), UINT32_C(3093770437), UINT32_C(3404268737), UINT32_C(3194821835),
      UINT32_C(1775916858), UINT32_C(2424254800), UINT32_C(3608279232), UINT32_C(4073412995), UINT32_C(2518135249), UINT32_C(2723053281), UINT32_C(1315714947), UINT32_C(2383206740),
      UINT32_C(2163730224), UINT32_C(3641800216), UINT32_C(4054852206), UINT32_C(1289976955), UINT32_C( 249756205), UINT32_C(4222627960), UINT32_C(3158973544), UINT32_C( 625628917),
      UINT32_C(1453736253), UINT32_C( 623884215), UINT32_C(1410785241), UINT32_C(2292316507), UINT32_C(1805026291), UINT32_C( 476530356), UINT32_C(1473818978), UINT32_C(1165828615),
      UINT32_C( 446374755), UINT32_C(3007302362), UINT32_C(  84366761), UINT32_C(1099802702), UINT32_C(3769377836), UINT32_C(3455849322), UINT32_C(3424965828), UINT32_C(1494327798),
      UINT32_C(2658380996), UINT32_C( 525447798), UINT32_C(1428445447), UINT32_C( 764850689), UINT32_C(1074610902), UINT32_C( 437061974), UINT32_C(3555078877), UINT32_C(2553083859),
      UINT32_C( 423010211), UINT32_C(1480165457), UINT32_C(3803012577), UINT32_C(3843048207), UINT32_C(3693485446), UINT32_C(  83243815), UINT32_C( 970513765), UINT32_C(2026964180),
      UINT32_C(4119922596), UINT32_C(1884211855), UINT32_C( 928250664), UINT32_C(3307037503), UINT32_C(2812363648), UINT32_C(3702298486), UINT32_C(1226146932), UINT32_C( 750904968),
      UINT32_C(2099401453), UINT32_C(1173188637), UINT32_C(2860269675), UINT32_C( 611293603), UINT32_C(1405817052), UINT32_C( 472872872), UINT32_C(2221229307), UINT32_C( 397420074),
      UINT32_C(2526335609), UINT32_C(2933621314), UINT32_C(1717065666), UINT32_C(3448424689), UINT32_C(2149602776), UINT32_C(3365752781), UINT32_C(3175875219), UINT32_C(2731932969),
      UINT32_C( 305686991), UINT32_C(2931823595), UINT32_C(1528043626), UINT32_C(3106512608), UINT32_C(3224979955), UINT32_C( 747230873), UINT32_C(  48944601), UINT32_C(2728706002),
      UINT32_C( 347397160), UINT32_C(1505916143), UINT32_C(1840633484), UINT32_C(1730600564), UINT32_C(3223871271), UINT32_C( 267235638), UINT32_C(1494341510), UINT32_C(3204167062),
      UINT32_C(2161291153), UINT32_C(2950272035), UINT32_C(3726413418), UINT32_C(2487632492), UINT32_C(3629412002), UINT32_C(2783396127), UINT32_C(2935945240), UINT32_C(1047394733),
      UINT32_C(3418242984), UINT32_C(1048287188), UINT32_C(2451412774), UINT32_C(2082890714), UINT32_C(4032068561), UINT32_C(3583327164), UINT32_C(3766719539), UINT32_C( 907997325),
      UINT32_C(  67230768), UINT32_C(2571271283), UINT32_C(3995885332), UINT32_C(2473218754), UINT32_C(2323889869), UINT32_C( 744430073), UINT32_C( 973922989), UINT32_C(  57682643),
      UINT32_C(2030531078), UINT32_C(  34818542), UINT32_C(1810907049), UINT32_C(1610570385), UINT32_C( 300515864), UINT32_C(1211975835), UINT32_C(4253239594), UINT32_C(2030105459),
      UINT32_C(1425213285), UINT32_C(4199941713), UINT32_C(3596961605), UINT32_C(3124061345), UINT32_C(2194349799), UINT32_C(2446002534), UINT32_C(3331214930), UINT32_C(2805960513),
      UINT32_C(3891999382), UINT32_C(2111918392), UINT32_C( 978601880), UINT32_C(2465499563) };
  static const uint32_t b[] =
    { UINT32_C( 928166438), UINT32_C(3141206652), UINT32_C(1508938788), UINT32_C(1650232844), UINT32_C(2047107611), UINT32_C( 699648115), UINT32_C(3231548602), UINT32_C(2947629960),
      UINT32_C(1927676917), UINT32_C( 690823429), UINT32_C(3246530229), UINT32_C(3341016748), UINT32_C(3024234305), UINT32_C(2866673135), UINT32_C(  40532601), UINT32_C(2997951421),
      UINT32_C( 606377758), UINT32_C(1833783992), UINT32_C( 472830064), UINT32_C(4024717742), UINT32_C(1755522680), UINT32_C(2501017627), UINT32_C(3080158458), UINT32_C(3060418712),
      UINT32_C(2547683039), UINT32_C(1342449888), UINT32_C(2792174328), UINT32_C(4220932483), UINT32_C(2455976311), UINT32_C(3022484922), UINT32_C(2322382578), UINT32_C(3846231558),
      UINT32_C(1165761380), UINT32_C( 999653443), UINT32_C( 903938738), UINT32_C(3392239443), UINT32_C(1801295025), UINT32_C(4229923850), UINT32_C(1233554243), UINT32_C(3325019745),
      UINT32_C( 604744673), UINT32_C(3730808876), UINT32_C(4128522659), UINT32_C(1774273976), UINT32_C(3822329561), UINT32_C(3856659618), UINT32_C(3777979775), UINT32_C( 229072428),
      UINT32_C( 892514825), UINT32_C(4111765842), UINT32_C(2347509970), UINT32_C(1190440301), UINT32_C(1831520715), UINT32_C(1012074941), UINT32_C(2602402415), UINT32_C(3920151776),
      UINT32_C(3374307958), UINT32_C(1052652396), UINT32_C(3368659547), UINT32_C( 571391575), UINT32_C(1150302343), UINT32_C(2978014018), UINT32_C(1162649189), UINT32_C(3643733090),
      UINT32_C(1000492495), UINT32_C(3682164864), UINT32_C(1654866699), UINT32_C(2290463233), UINT32_C( 751572458), UINT32_C(1574784248), UINT32_C(1302473194), UINT32_C(3978743838),
      UINT32_C(2653472798), UINT32_C( 863674664), UINT32_C(3851820516), UINT32_C(3127712719), UINT32_C( 686176560), UINT32_C(1887814790), UINT32_C( 196945901), UINT32_C( 368632823),
      UINT32_C(3568574635), UINT32_C(2785488578), UINT32_C( 462200139), UINT32_C(3906337208), UINT32_C(3104881459), UINT32_C(1831441791), UINT32_C(3027822524), UINT32_C(1992913354),
      UINT32_C(1397390737), UINT32_C(4160377259), UINT32_C(2803009263), UINT32_C(2995840895), UINT32_C( 577478818), UINT32_C(4069496118), UINT32_C(1185286012), UINT32_C( 180121720),
      UINT32_C(2573010669), UINT32_C(1200641880), UINT32_C(1575920349), UINT32_C( 722435721), UINT32_C(1431141151), UINT32_C(2353519632), UINT32_C(1557327588), UINT32_C(1265012574),
      UINT32_C(3991192725), UINT32_C(4180964379), UINT32_C(2673222422), UINT32_C(3234555297), UINT32_C(4027914464), UINT32_C(3648806389), UINT32_C(2838843211), UINT32_C(1945410782),
      UINT32_C(2070010208), UINT32_C(1685361997), UINT32_C(1510197944), UINT32_C( 270192176), UINT32_C(3691065575), UINT32_C(3635772813), UINT32_C(2860640972), UINT32_C(3860755846),
      UINT32_C(2623700814), UINT32_C(3439384084), UINT32_C(3508994977), UINT32_C(3118547410), UINT32_C(4271235697), UINT32_C( 752241248), UINT32_C(3151451956), UINT32_C( 463599053),
      UINT32_C(2293695348), UINT32_C(2069215194), UINT32_C(2370600123), UINT32_C( 793128382), UINT32_C(1882118928), UINT32_C(1503396901), UINT32_C( 689206108), UINT32_C(3695490664),
      UINT32_C(2472934585), UINT32_C(1846459059), UINT32_C(4126890551), UINT32_C(2552512904), UINT32_C(1091064348), UINT32_C(3013321815), UINT32_C(2161946392), UINT32_C( 526196837),
      UINT32_C(3501376028), UINT32_C(3007234428), UINT32_C(2745711131), UINT32_C(2554056059), UINT32_C(1993949983), UINT32_C(   2716904), UINT32_C(2306868516), UINT32_C(1118362918),
      UINT32_C( 470965151), UINT32_C( 936333596), UINT32_C( 115046539), UINT32_C(1688081989), UINT32_C(1121679450), UINT32_C( 272762092), UINT32_C( 815448586), UINT32_C(1064452768),
      UINT32_C(3109782941), UINT32_C(1643195350), UINT32_C(3899116707), UINT32_C(1011615458), UINT32_C(1786652542), UINT32_C( 914079788), UINT32_C( 593892739), UINT32_C(4116895831),
      UINT32_C( 867090013), UINT32_C(2358550505), UINT32_C(1316289643), UINT32_C(2156576770), UINT32_C( 350882280), UINT32_C(1279944137), UINT32_C(3530535034), UINT32_C(3871855240),
      UINT32_C(2031711632), UINT32_C(2147855893), UINT32_C(2899212714), UINT32_C( 556554553), UINT32_C( 724899426), UINT32_C(4135092092), UINT32_C(3100174127), UINT32_C(1235128249),
      UINT32_C( 448968453), UINT32_C( 261801829), UINT32_C(2059102528), UINT32_C( 614197186), UINT32_C(2052051454), UINT32_C(2154874704), UINT32_C(1748515247), UINT32_C(3451049672),
      UINT32_C(4092032141), UINT32_C(2080539196), UINT32_C(2918629099), UINT32_C(2748420773) };
  static const uint32_t e[] =
    { UINT32_C(1328181865), UINT32_C(2491264142), UINT32_C( 699024004), UINT32_C(1940375835), UINT32_C(1212740300), UINT32_C(2571807851), UINT32_C( 398129246), UINT32_C(3887080319),
      UINT32_C(2788678294), UINT32_C(3850402181), UINT32_C(  70801629), UINT32_C(2094677167), UINT32_C( 230957871), UINT32_C(1257360552), UINT32_C(3215068994), UINT32_C(3366474291),
      UINT32_C(3583342411), UINT32_C(2174152537), UINT32_C(1257381018), UINT32_C(2277952856), UINT32_C( 519136376), UINT32_C(1936384818), UINT32_C(3721038317), UINT32_C(2347687007),
      UINT32_C(2887315099), UINT32_C(3415997488), UINT32_C(1880460568), UINT32_C(1331857879), UINT32_C(3000142949), UINT32_C(3719974896), UINT32_C(1162725094), UINT32_C(1590771107),
      UINT32_C( 854600193), UINT32_C(  57150179), UINT32_C(1940787737), UINT32_C(1388226285), UINT32_C(3081239426), UINT32_C(3135323093), UINT32_C(2751540993), UINT32_C( 151114605),
      UINT32_C(3304421090), UINT32_C(3324509869), UINT32_C( 119968621), UINT32_C(2941319292), UINT32_C(1741837704), UINT32_C(1933499762), UINT32_C(1514579340), UINT32_C(4085455378),
      UINT32_C(1206528922), UINT32_C(1157201880), UINT32_C(1664633063), UINT32_C(3356657728), UINT32_C(4046447837), UINT32_C(1112165814), UINT32_C( 832410099), UINT32_C(3112895017),
      UINT32_C( 485105138), UINT32_C(3617178819), UINT32_C(3081757925), UINT32_C(4098394903), UINT32_C(3780460264), UINT32_C( 115756419), UINT32_C(2241619548), UINT32_C(3194821835),
      UINT32_C( 775424363), UINT32_C(3037057232), UINT32_C(1953412533), UINT32_C(1782949762), UINT32_C(1766562791), UINT32_C(2723053281), UINT32_C(  13241753), UINT32_C(2383206740),
      UINT32_C(2163730224), UINT32_C(3641800216), UINT32_C( 203031690), UINT32_C(1289976955), UINT32_C( 249756205), UINT32_C(4222627960), UINT32_C(2962027643), UINT32_C( 625628917),
      UINT32_C(2180128914), UINT32_C( 623884215), UINT32_C(1410785241), UINT32_C(2292316507), UINT32_C(2995112128), UINT32_C( 476530356), UINT32_C(1473818978), UINT32_C(3467882557),
      UINT32_C(3343951314), UINT32_C(3141892399), UINT32_C(1576324794), UINT32_C(1099802702), UINT32_C(3769377836), UINT32_C(3455849322), UINT32_C(3424965828), UINT32_C(1314206078),
      UINT32_C(  85370327), UINT32_C(3619773214), UINT32_C(4147492394), UINT32_C( 764850689), UINT32_C(3938437047), UINT32_C(2378509638), UINT32_C(1997751289), UINT32_C(1288071285),
      UINT32_C( 726784782), UINT32_C(1594168374), UINT32_C(1129790155), UINT32_C(3843048207), UINT32_C(3960538278), UINT32_C( 729404722), UINT32_C(2426637850), UINT32_C(  81553398),
      UINT32_C(4119922596), UINT32_C( 198849858), UINT32_C(3713020016), UINT32_C(3307037503), UINT32_C(3416265369), UINT32_C(  66525673), UINT32_C(2660473256), UINT32_C( 750904968),
      UINT32_C(3770667935), UINT32_C(1173188637), UINT32_C(3646241994), UINT32_C(1787713489), UINT32_C(1405817052), UINT32_C( 472872872), UINT32_C(2221229307), UINT32_C(4228788317),
      UINT32_C( 232640261), UINT32_C(2933621314), UINT32_C(3641432839), UINT32_C(3448424689), UINT32_C( 267483848), UINT32_C(3365752781), UINT32_C(3175875219), UINT32_C(2731932969),
      UINT32_C(2127719702), UINT32_C(2931823595), UINT32_C(1528043626), UINT32_C( 553999704), UINT32_C(3224979955), UINT32_C(2028876354), UINT32_C(  48944601), UINT32_C(2728706002),
      UINT32_C(1140988428), UINT32_C(2793649011), UINT32_C(1840633484), UINT32_C(3471511801), UINT32_C(1229921288), UINT32_C( 267235638), UINT32_C(3482440290), UINT32_C(2085804144),
      UINT32_C(2161291153), UINT32_C(2013938439), UINT32_C(3726413418), UINT32_C( 799550503), UINT32_C(2507732552), UINT32_C(2510634035), UINT32_C(2935945240), UINT32_C(1047394733),
      UINT32_C(3418242984), UINT32_C(3700059134), UINT32_C(2451412774), UINT32_C(2082890714), UINT32_C(4032068561), UINT32_C(2669247376), UINT32_C(3172826800), UINT32_C( 907997325),
      UINT32_C(  67230768), UINT32_C(2571271283), UINT32_C(2679595689), UINT32_C( 316641984), UINT32_C(2323889869), UINT32_C(3759453232), UINT32_C(1738355251), UINT32_C( 480794699),
      UINT32_C(2030531078), UINT32_C(  34818542), UINT32_C(3206661631), UINT32_C(1054015832), UINT32_C( 300515864), UINT32_C(1371851039), UINT32_C(1153065467), UINT32_C(2030105459),
      UINT32_C(1425213285), UINT32_C(4199941713), UINT32_C(3596961605), UINT32_C(3124061345), UINT32_C(2194349799), UINT32_C( 291127830), UINT32_C(1582699683), UINT32_C(2805960513),
      UINT32_C(4094934537), UINT32_C(  31379196), UINT32_C(2354940077), UINT32_C(4012046086) };

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
    rv = simde_svsub_u32_m(pv, av, bv);

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

    ev = simde_svsub_u32_m(pv, av, bv);

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
test_simde_svsub_u64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0) };
  static const uint64_t a[] =
    { UINT64_C(18220276295772626815), UINT64_C(15359620768044762277), UINT64_C( 1577894645194303341), UINT64_C( 4181787673154710378),
      UINT64_C( 1787528227778463505), UINT64_C(10764434514367009751), UINT64_C( 7422308209965149723), UINT64_C( 4807029864814641089),
      UINT64_C(15677841748801121799), UINT64_C( 8030700248565637045), UINT64_C(17967776162530452470), UINT64_C( 6435410023948833500),
      UINT64_C(18047162055933518745), UINT64_C(10918777877350046149), UINT64_C( 2044603721082135341), UINT64_C(11088839750724539447),
      UINT64_C(16221306271644825309), UINT64_C( 7762659011618075778), UINT64_C( 6899849055230313572), UINT64_C( 4728441388736834308),
      UINT64_C(18266742456569877122), UINT64_C( 6926495530807753333), UINT64_C( 2713073667453349918), UINT64_C(15949435799366897585),
      UINT64_C(12759539128794397594), UINT64_C( 3086237933177746039), UINT64_C( 5817268218358716789), UINT64_C( 5106726474411795621),
      UINT64_C(14944471161937549943), UINT64_C(14255324726942681759), UINT64_C(  134569625648842223), UINT64_C( 8713585672444855546),
      UINT64_C( 6008242483109775162), UINT64_C(12209209913510896475), UINT64_C(15813852294853216793), UINT64_C(10651978869432744026),
      UINT64_C(16914823725992771253), UINT64_C(12145368786133105705), UINT64_C( 3930117296090891726), UINT64_C( 3456623186564680460),
      UINT64_C(14761487465769934178), UINT64_C( 4776697925934805010), UINT64_C(  581945102846486530), UINT64_C( 7723502971005019271),
      UINT64_C( 3599000758644426882), UINT64_C(16239451249954759336), UINT64_C( 5947798029409865862), UINT64_C(16206909547125930102),
      UINT64_C( 2782089317148083787), UINT64_C( 1394323188627959705), UINT64_C( 6921786245338437873), UINT64_C( 3410854275870319127),
      UINT64_C(16984540198393698832), UINT64_C( 9891239142973831076), UINT64_C( 1162023230710929877), UINT64_C(15693877885935157175),
      UINT64_C( 4427632829369115700), UINT64_C( 7581443370047690260), UINT64_C( 9841571150413986955), UINT64_C( 2876374039761459528),
      UINT64_C( 9379344834741817683), UINT64_C(15488552344067414262), UINT64_C(12338154766102830048), UINT64_C(11394852852460182791),
      UINT64_C(16638748867437515000), UINT64_C( 6588593062844241485), UINT64_C(13802484717830654333), UINT64_C(16685235117554813091),
      UINT64_C( 1982205943203305644), UINT64_C(14997587452308484427), UINT64_C( 1829373449126096876), UINT64_C(11915282137764863365),
      UINT64_C( 2996797958084733102), UINT64_C( 6402167500987910837), UINT64_C( 5534748877946391104), UINT64_C( 1881409996525262717),
      UINT64_C(15477513067362148037), UINT64_C(  953558936254921590), UINT64_C( 1537296029513365570), UINT64_C(17938023355907839593),
      UINT64_C( 3026250389987689991), UINT64_C(15634887769917808161), UINT64_C(13271323390261706111), UINT64_C( 7599963332716443981),
      UINT64_C(11087740755254579716), UINT64_C(12888599764740336495), UINT64_C( 4704000965551504959), UINT64_C( 6303976607388390832),
      UINT64_C( 1035526234786565708), UINT64_C(11943247582896317912), UINT64_C( 3451019002601834670), UINT64_C( 3169056255046231632),
      UINT64_C(14806515011634071501), UINT64_C( 3332547724063575859), UINT64_C( 4525473237031809822), UINT64_C(11269936796355596123),
      UINT64_C(15538690457852270306), UINT64_C( 3585340376488180755), UINT64_C(11767796180397822499), UINT64_C(17083917052573266091),
      UINT64_C(13193128683763933083), UINT64_C( 6568793870808287461), UINT64_C( 4649891388445227165), UINT64_C( 5036098241032775147),
      UINT64_C(17674828708072171759), UINT64_C( 4302652462913655587), UINT64_C(14475879672658797071), UINT64_C( 6772466536071208461),
      UINT64_C( 4562209216473825354), UINT64_C( 7252573672951201228), UINT64_C( 8870662374609700468), UINT64_C(14147264910139250826),
      UINT64_C( 5335199294626415790), UINT64_C( 7666635052816901548), UINT64_C(16360405751522159906), UINT64_C( 1868202657250491822),
      UINT64_C( 2899454476243176564), UINT64_C( 7995171697859359123), UINT64_C( 3762486486247583995), UINT64_C(13171704284990739014),
      UINT64_C( 3529666099486961495), UINT64_C(12506687145806210261), UINT64_C(16075661099193700189), UINT64_C( 1748060487923299658),
      UINT64_C(11950273915800775434), UINT64_C(11270635469438161162) };
  static const uint64_t b[] =
    { UINT64_C(13842609185293652133), UINT64_C( 2251770370132336996), UINT64_C( 7196185229959020111), UINT64_C(13081010851525187050),
      UINT64_C(13645137593387091430), UINT64_C( 1116223926928726565), UINT64_C(   78494236894305117), UINT64_C( 4898156477022619443),
      UINT64_C(10185240651304543044), UINT64_C(13179336090335295768), UINT64_C(17914335003960534915), UINT64_C(15377318350174343879),
      UINT64_C(11407278685790750808), UINT64_C( 2707609655549704580), UINT64_C( 4827960488333737027), UINT64_C(14597520379664088110),
      UINT64_C( 6141740907357668631), UINT64_C( 5753846657296019474), UINT64_C( 2558423873659312577), UINT64_C(14974599293768493460),
      UINT64_C( 5017475298634783356), UINT64_C( 6535799036215677783), UINT64_C(17835689813900528492), UINT64_C( 6523971891726477058),
      UINT64_C(17627168777917887784), UINT64_C(15496335925043566875), UINT64_C(14011189645308175894), UINT64_C( 7231943431453175333),
      UINT64_C( 7461443465230877947), UINT64_C(  448998695990191352), UINT64_C( 6292074254359819471), UINT64_C(14987901303896395103),
      UINT64_C( 1545001978208698044), UINT64_C( 9569220901555702743), UINT64_C(11218858357111868455), UINT64_C( 9355161441972653106),
      UINT64_C(  370976520569175027), UINT64_C( 8772616598810566277), UINT64_C( 7547051344085045988), UINT64_C( 2077639544084034447),
      UINT64_C(15974921369035759230), UINT64_C(18139044740746149616), UINT64_C(11549155861395705255), UINT64_C( 8435464168868721867),
      UINT64_C( 9105385155608001575), UINT64_C(17321823047505703761), UINT64_C( 2573830650864762631), UINT64_C(11255946230369856713),
      UINT64_C( 8966798983940560739), UINT64_C(12836745113558593772), UINT64_C(15150252122140505286), UINT64_C(16303251097316972334),
      UINT64_C(13890865779250060319), UINT64_C(13245680176504089205), UINT64_C( 5686380702813429007), UINT64_C( 7335573548732349804),
      UINT64_C( 6494883240685314445), UINT64_C( 4811899608583772191), UINT64_C( 2114234077230570730), UINT64_C(  607376244862372290),
      UINT64_C(12877634744756084086), UINT64_C( 7501178931752612260), UINT64_C( 8859928162670310182), UINT64_C( 5302126348901481746),
      UINT64_C( 3409607048133213708), UINT64_C(14083354843591152524), UINT64_C(13818890481110279316), UINT64_C( 4947169244099594380),
      UINT64_C( 3790118459344637150), UINT64_C( 6100321137311326279), UINT64_C( 6773808367788901269), UINT64_C(  804565631746461102),
      UINT64_C( 9839536434694131120), UINT64_C( 1424006635158621358), UINT64_C( 8685569882182738777), UINT64_C( 6547258221233325476),
      UINT64_C(  963558526137029013), UINT64_C( 4295378386806426635), UINT64_C(17070313056953102754), UINT64_C( 7005519425075757877),
      UINT64_C( 3916046083905088491), UINT64_C(13150892525248042083), UINT64_C(  901010022952265804), UINT64_C(14157104843955322699),
      UINT64_C(12353206958009856014), UINT64_C(15350082314032983612), UINT64_C( 8880795206969600090), UINT64_C( 6613547378699020587),
      UINT64_C( 8983840405130107067), UINT64_C( 7750925932294872625), UINT64_C( 1271946825911106299), UINT64_C(18279792313969752069),
      UINT64_C( 8607132358144967350), UINT64_C(  921199503631073100), UINT64_C( 5166997950776698556), UINT64_C( 6797419100463876629),
      UINT64_C( 5713033847001863562), UINT64_C(17880262747035040261), UINT64_C( 5648728034557778906), UINT64_C(14997263040475758106),
      UINT64_C( 4657822876368467025), UINT64_C(11427737560086433635), UINT64_C(11338971510048699349), UINT64_C( 5634988285024469532),
      UINT64_C( 2336600460491937011), UINT64_C( 1510489555101271188), UINT64_C(16981243297704095881), UINT64_C( 8848589786815793280),
      UINT64_C( 5274301976755597141), UINT64_C(15072869859507433946), UINT64_C( 5693262198166343751), UINT64_C( 2779171568390852751),
      UINT64_C( 2956167096124848392), UINT64_C( 9616151944167073627), UINT64_C( 7484312808702366143), UINT64_C( 5540852799710866158),
      UINT64_C(16339357998122605897), UINT64_C( 3637211350985606070), UINT64_C(11639726629629990217), UINT64_C( 6978122115058763591),
      UINT64_C(11946847976115789922), UINT64_C(10476237259472982206), UINT64_C(  683767322719167528), UINT64_C( 9635850677290065217),
      UINT64_C( 3089252105910727243), UINT64_C(12854328364401129610) };
  static const uint64_t e[] =
    { UINT64_C(                   0), UINT64_C(                   0), UINT64_C(12828453488944834846), UINT64_C( 9547520895339074944),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(   53441158569917555), UINT64_C( 9504835747484041237),
      UINT64_C(                   0), UINT64_C( 8211168221800341569), UINT64_C(15663387306457949930), UINT64_C(14938063444770002953),
      UINT64_C(10079565364287156678), UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 8200586168677892464),
      UINT64_C(13249267157935093766), UINT64_C(  390696494592075550), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(10252822646760092511), UINT64_C(16321527116668171904),
      UINT64_C( 7483027696706671996), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 2639989011955193732), UINT64_C(                   0), UINT64_C( 1296817427460090920),
      UINT64_C(                   0), UINT64_C( 3372752187322539428), UINT64_C(14829810025715397354), UINT64_C( 1378983642480646013),
      UINT64_C(17233310170443726564), UINT64_C(                   0), UINT64_C( 7479533315160332891), UINT64_C(                   0),
      UINT64_C(12940359676745976923), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(12262034406917074664), UINT64_C( 7004322148778917549), UINT64_C(                   0), UINT64_C( 5554347252262898409),
      UINT64_C( 3093674419143638513), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 7727337073183416225), UINT64_C( 2268997794899087238),
      UINT64_C(14948454163695285213), UINT64_C(                   0), UINT64_C( 3478226603432519866), UINT64_C( 6092726503558701045),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(18430338310429926633), UINT64_C(11738065873455218711),
      UINT64_C(16638831557568220110), UINT64_C( 8897266314997158148), UINT64_C(13502309155046747223), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 4978160865829289479), UINT64_C(15295923069473203943), UINT64_C(13780895849001488857),
      UINT64_C(                   0), UINT64_C(15104924623158046571), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 2483995244669766078), UINT64_C(                   0), UINT64_C(11889602562470672898),
      UINT64_C(                   0), UINT64_C(15985261524416904499), UINT64_C(14269949832291456485), UINT64_C(                   0),
      UINT64_C(10498429903366010257), UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 3336008014786031179),
      UINT64_C( 6199382653489104151), UINT64_C( 2411348220432502759), UINT64_C(17805219359964662882), UINT64_C(                   0),
      UINT64_C( 9825656610850406744), UINT64_C(                   0), UINT64_C( 6119068145840043593), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(13587800384431405442), UINT64_C(11757663952106079432), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(15941380448664252806), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(10626447887153318898), UINT64_C( 3177400176443356717), UINT64_C(11368093341748398075),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C( 5006840551830122283), UINT64_C( 4357960346873753053), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(10029562197080723189), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(10558953884342786057),
      UINT64_C(                   0), UINT64_C(                   0) };

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
    rv = simde_svsub_u64_z(pv, av, bv);

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

    ev = simde_svsub_u64_z(pv, av, bv);

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
test_simde_svsub_u64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1) };
  static const uint64_t a[] =
    { UINT64_C(12245120939214381232), UINT64_C(15535415442073809598), UINT64_C(10798251214148837876), UINT64_C(14983650918037709371),
      UINT64_C(12107264499740082879), UINT64_C(14624611673457488662), UINT64_C(  975358979344480943), UINT64_C(18445765779708616718),
      UINT64_C( 7753898205214650632), UINT64_C(14984460161304367444), UINT64_C( 9014601643974673210), UINT64_C( 4479857005957918956),
      UINT64_C( 4258377643565549143), UINT64_C( 6614758855708877533), UINT64_C(14522000880051982492), UINT64_C( 3505525473800434226),
      UINT64_C( 9208159892154406566), UINT64_C( 2527443563637911190), UINT64_C( 3422373967630859224), UINT64_C( 4174904559373087720),
      UINT64_C( 6356146710284586260), UINT64_C(15161689174048813503), UINT64_C( 3876479210155906975), UINT64_C(13061818398646100856),
      UINT64_C( 6687177619855314099), UINT64_C(11465051946770226513), UINT64_C( 2316830055000220580), UINT64_C(13240987537837333867),
      UINT64_C( 2122877454366026876), UINT64_C(14516935746921175254), UINT64_C( 2734214641272664616), UINT64_C(  628801405652704510),
      UINT64_C(12973348660294313248), UINT64_C( 2205920452609209007), UINT64_C( 4076567149969103026), UINT64_C(15533464559384446204),
      UINT64_C(17972404083264631768), UINT64_C(12057662278285063232), UINT64_C( 2320943860774356163), UINT64_C( 4249493016058359658),
      UINT64_C(14641583417560448494), UINT64_C( 3380890963957382990), UINT64_C( 1143739095351820186), UINT64_C(12784357885541910735),
      UINT64_C(  305149340868500454), UINT64_C( 3437428029063118362), UINT64_C( 1145546259091545905), UINT64_C( 2795235905726649941),
      UINT64_C(16843978065751552776), UINT64_C( 7914269559764158738), UINT64_C(16451976609029931778), UINT64_C( 5162470148400845375),
      UINT64_C( 2464249719371873402), UINT64_C(14229016108237103311), UINT64_C( 2582067701669673825), UINT64_C( 1400978582748123883),
      UINT64_C(  771397822696945026), UINT64_C( 8914748034761718831), UINT64_C(   94084205694991943), UINT64_C(13312530782161203219),
      UINT64_C(15661547711575497746), UINT64_C( 4688391220564290938), UINT64_C(15012955779729488960), UINT64_C( 3646011485252781227),
      UINT64_C( 6619404013249028952), UINT64_C( 7673853571018827589), UINT64_C( 5911848241418333309), UINT64_C( 2085673247825954974),
      UINT64_C(10298600166770241967), UINT64_C( 6500467627663350946), UINT64_C(12696105926966769720), UINT64_C(16071481408994829353),
      UINT64_C(14170393855046658000), UINT64_C(17901464097108554806), UINT64_C(14807845078765601726), UINT64_C( 2268621579715538796),
      UINT64_C( 8922158919681895147), UINT64_C(16576901573222752596), UINT64_C( 6301160313865036544), UINT64_C(15822111894915984422),
      UINT64_C(    6678075482360920), UINT64_C(11684343639484704282), UINT64_C( 4271023325473922563), UINT64_C(18352242865363433701),
      UINT64_C( 7762994446812747791) };
  static const uint64_t b[] =
    { UINT64_C( 7072715724766542562), UINT64_C(  691940785559428216), UINT64_C(17976965386512805951), UINT64_C(11393062225282801843),
      UINT64_C(17411014536683725764), UINT64_C(  196193297292164918), UINT64_C(  320705901527125940), UINT64_C( 7555133227419916928),
      UINT64_C(11225017999451097949), UINT64_C(16828267585589686725), UINT64_C( 5740072812876558163), UINT64_C( 6574240601704482096),
      UINT64_C(17109448938151338608), UINT64_C( 1317584088411257642), UINT64_C(12722209902269213295), UINT64_C(17113045802743503139),
      UINT64_C(15111602770907672226), UINT64_C(11150481856383692013), UINT64_C(17677587116749059107), UINT64_C( 4173592860196067200),
      UINT64_C(14824648073581669698), UINT64_C( 9776250893555657958), UINT64_C( 7815291183070610861), UINT64_C( 7071869815243770964),
      UINT64_C(14388729100729329410), UINT64_C( 1144060962796022260), UINT64_C(15880259122848729610), UINT64_C( 2455284372002622351),
      UINT64_C( 6538579488790568468), UINT64_C( 2688247772828899037), UINT64_C( 7999094289812151453), UINT64_C(14594532201948236360),
      UINT64_C( 2256441139873746575), UINT64_C( 3770547074062222099), UINT64_C( 3735836957529960072), UINT64_C(13233306512016602917),
      UINT64_C(17732640837884274357), UINT64_C(12163227675496051713), UINT64_C(11962943253953717733), UINT64_C( 8916891717739913440),
      UINT64_C( 7811925023730593167), UINT64_C(16989213889688538876), UINT64_C(11465531055423608566), UINT64_C( 6386498760711053407),
      UINT64_C(11073003054005163219), UINT64_C( 8553314810848456643), UINT64_C(10281166192285413200), UINT64_C(10361751110556079530),
      UINT64_C(10349124385915180905), UINT64_C( 2242242650987582504), UINT64_C(13850782268398701434), UINT64_C(12285257112404421427),
      UINT64_C(17218193509583965335), UINT64_C(15101331887715928995), UINT64_C(15102735171171566016), UINT64_C( 7099713482404187036),
      UINT64_C( 2972299365148145547), UINT64_C( 5417318573567431941), UINT64_C(17753110955172145391), UINT64_C(16911397436848807811),
      UINT64_C( 3981597896833988497), UINT64_C(18025025340276202831), UINT64_C( 9420095556787062378), UINT64_C( 8813125455446117894),
      UINT64_C( 6008595763923356153), UINT64_C( 2428657048115606959), UINT64_C( 2889797081837681816), UINT64_C( 7390648250091301677),
      UINT64_C(11798291879879057765), UINT64_C(15258497055515928809), UINT64_C( 8329834419588867662), UINT64_C( 7440818509426796143),
      UINT64_C(12813457581717574714), UINT64_C(10484681485096923251), UINT64_C(16100539577432992696), UINT64_C( 5560818620994222530),
      UINT64_C(17963818249908648659), UINT64_C( 7444776394336738685), UINT64_C(12710237793753060115), UINT64_C(17379002967049641935),
      UINT64_C( 8437733557288151706), UINT64_C(18126573877549449079), UINT64_C(10914721949389091801), UINT64_C( 2742876393317198848),
      UINT64_C(17131233894692396369) };
  static const uint64_t e[] =
    { UINT64_C(12245120939214381232), UINT64_C(15535415442073809598), UINT64_C(10798251214148837876), UINT64_C(14983650918037709371),
      UINT64_C(13142994036765908731), UINT64_C(14624611673457488662), UINT64_C(  975358979344480943), UINT64_C(10890632552288699790),
      UINT64_C(14975624279473104299), UINT64_C(14984460161304367444), UINT64_C( 3274528831098115047), UINT64_C(16352360477962988476),
      UINT64_C( 5595672779123762151), UINT64_C( 6614758855708877533), UINT64_C( 1799790977782769197), UINT64_C( 4839223744766482703),
      UINT64_C( 9208159892154406566), UINT64_C( 9823705780963770793), UINT64_C( 3422373967630859224), UINT64_C( 4174904559373087720),
      UINT64_C( 6356146710284586260), UINT64_C( 5385438280493155545), UINT64_C( 3876479210155906975), UINT64_C( 5989948583402329892),
      UINT64_C( 6687177619855314099), UINT64_C(10320990983974204253), UINT64_C( 4883315005861042586), UINT64_C(13240987537837333867),
      UINT64_C( 2122877454366026876), UINT64_C(14516935746921175254), UINT64_C( 2734214641272664616), UINT64_C(  628801405652704510),
      UINT64_C(10716907520420566673), UINT64_C( 2205920452609209007), UINT64_C(  340730192439142954), UINT64_C(15533464559384446204),
      UINT64_C(  239763245380357411), UINT64_C(18341178676498563135), UINT64_C( 2320943860774356163), UINT64_C(13779345372027997834),
      UINT64_C(14641583417560448494), UINT64_C( 4838421147978395730), UINT64_C( 8124952113637763236), UINT64_C(12784357885541910735),
      UINT64_C(  305149340868500454), UINT64_C( 3437428029063118362), UINT64_C( 9311124140515684321), UINT64_C(10880228868880122027),
      UINT64_C(16843978065751552776), UINT64_C( 7914269559764158738), UINT64_C( 2601194340631230344), UINT64_C(11323957109705975564),
      UINT64_C( 2464249719371873402), UINT64_C(17574428294230725932), UINT64_C( 5926076604207659425), UINT64_C(12748009174053488463),
      UINT64_C(  771397822696945026), UINT64_C( 8914748034761718831), UINT64_C(   94084205694991943), UINT64_C(13312530782161203219),
      UINT64_C(11679949814741509249), UINT64_C( 5110109953997639723), UINT64_C(15012955779729488960), UINT64_C( 3646011485252781227),
      UINT64_C( 6619404013249028952), UINT64_C( 7673853571018827589), UINT64_C( 3022051159580651493), UINT64_C( 2085673247825954974),
      UINT64_C(10298600166770241967), UINT64_C( 9688714645856973753), UINT64_C( 4366271507377902058), UINT64_C( 8630662899568033210),
      UINT64_C(14170393855046658000), UINT64_C(17901464097108554806), UINT64_C(14807845078765601726), UINT64_C( 2268621579715538796),
      UINT64_C( 8922158919681895147), UINT64_C(16576901573222752596), UINT64_C( 6301160313865036544), UINT64_C(15822111894915984422),
      UINT64_C(10015688591903760830), UINT64_C(12004513835644806819), UINT64_C( 4271023325473922563), UINT64_C(18352242865363433701),
      UINT64_C( 9078504625829903038) };

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
    rv = simde_svsub_u64_m(pv, av, bv);

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

    ev = simde_svsub_u64_m(pv, av, bv);

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
test_simde_svsub_f32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0) };
  static const simde_float32 a[] =
    { SIMDE_FLOAT32_C(   368.98), SIMDE_FLOAT32_C(   231.08), SIMDE_FLOAT32_C(  -336.87), SIMDE_FLOAT32_C(  -112.76),
      SIMDE_FLOAT32_C(   688.32), SIMDE_FLOAT32_C(  -228.49), SIMDE_FLOAT32_C(  -883.38), SIMDE_FLOAT32_C(   459.92),
      SIMDE_FLOAT32_C(  -172.09), SIMDE_FLOAT32_C(  -747.64), SIMDE_FLOAT32_C(  -781.34), SIMDE_FLOAT32_C(   823.69),
      SIMDE_FLOAT32_C(   551.58), SIMDE_FLOAT32_C(  -786.21), SIMDE_FLOAT32_C(   219.56), SIMDE_FLOAT32_C(  -644.19),
      SIMDE_FLOAT32_C(  -750.47), SIMDE_FLOAT32_C(   668.28), SIMDE_FLOAT32_C(  -878.48), SIMDE_FLOAT32_C(  -134.98),
      SIMDE_FLOAT32_C(   249.15), SIMDE_FLOAT32_C(   943.20), SIMDE_FLOAT32_C(    75.67), SIMDE_FLOAT32_C(  -405.21),
      SIMDE_FLOAT32_C(   107.64), SIMDE_FLOAT32_C(  -630.38), SIMDE_FLOAT32_C(  -464.30), SIMDE_FLOAT32_C(  -735.96),
      SIMDE_FLOAT32_C(  -558.27), SIMDE_FLOAT32_C(  -450.96), SIMDE_FLOAT32_C(  -489.53), SIMDE_FLOAT32_C(   810.71),
      SIMDE_FLOAT32_C(   780.12), SIMDE_FLOAT32_C(   173.60), SIMDE_FLOAT32_C(  -302.05), SIMDE_FLOAT32_C(   468.44),
      SIMDE_FLOAT32_C(   945.10), SIMDE_FLOAT32_C(  -185.43), SIMDE_FLOAT32_C(   -71.64), SIMDE_FLOAT32_C(  -226.98),
      SIMDE_FLOAT32_C(    66.93), SIMDE_FLOAT32_C(   147.02), SIMDE_FLOAT32_C(  -403.29), SIMDE_FLOAT32_C(  -381.49),
      SIMDE_FLOAT32_C(   360.82), SIMDE_FLOAT32_C(   816.27), SIMDE_FLOAT32_C(   -25.69), SIMDE_FLOAT32_C(   610.35),
      SIMDE_FLOAT32_C(   484.55), SIMDE_FLOAT32_C(    95.83), SIMDE_FLOAT32_C(  -524.63), SIMDE_FLOAT32_C(  -266.30),
      SIMDE_FLOAT32_C(    39.03), SIMDE_FLOAT32_C(   551.04), SIMDE_FLOAT32_C(   328.49), SIMDE_FLOAT32_C(  -853.33),
      SIMDE_FLOAT32_C(   920.65), SIMDE_FLOAT32_C(   864.19), SIMDE_FLOAT32_C(  -589.29), SIMDE_FLOAT32_C(  -637.62),
      SIMDE_FLOAT32_C(  -586.77), SIMDE_FLOAT32_C(   -78.82), SIMDE_FLOAT32_C(  -826.91), SIMDE_FLOAT32_C(  -806.65),
      SIMDE_FLOAT32_C(  -905.22), SIMDE_FLOAT32_C(  -128.96), SIMDE_FLOAT32_C(   661.78), SIMDE_FLOAT32_C(  -960.12),
      SIMDE_FLOAT32_C(   685.62), SIMDE_FLOAT32_C(  -409.85), SIMDE_FLOAT32_C(  -187.10), SIMDE_FLOAT32_C(  -247.45),
      SIMDE_FLOAT32_C(   737.17), SIMDE_FLOAT32_C(   409.61), SIMDE_FLOAT32_C(   371.06), SIMDE_FLOAT32_C(    97.99),
      SIMDE_FLOAT32_C(   225.88), SIMDE_FLOAT32_C(  -654.63), SIMDE_FLOAT32_C(  -291.67), SIMDE_FLOAT32_C(  -289.57),
      SIMDE_FLOAT32_C(   441.20), SIMDE_FLOAT32_C(   183.70), SIMDE_FLOAT32_C(   444.13), SIMDE_FLOAT32_C(  -519.76),
      SIMDE_FLOAT32_C(  -265.26), SIMDE_FLOAT32_C(  -227.38), SIMDE_FLOAT32_C(  -373.09), SIMDE_FLOAT32_C(  -344.61),
      SIMDE_FLOAT32_C(  -363.19), SIMDE_FLOAT32_C(    37.62), SIMDE_FLOAT32_C(    17.77), SIMDE_FLOAT32_C(    50.04),
      SIMDE_FLOAT32_C(   958.80), SIMDE_FLOAT32_C(   190.87), SIMDE_FLOAT32_C(   243.38), SIMDE_FLOAT32_C(  -946.42),
      SIMDE_FLOAT32_C(  -938.09), SIMDE_FLOAT32_C(   -94.83), SIMDE_FLOAT32_C(  -906.54), SIMDE_FLOAT32_C(   747.53),
      SIMDE_FLOAT32_C(   495.31), SIMDE_FLOAT32_C(   -93.64), SIMDE_FLOAT32_C(  -499.93), SIMDE_FLOAT32_C(   232.48),
      SIMDE_FLOAT32_C(  -684.03), SIMDE_FLOAT32_C(   871.13), SIMDE_FLOAT32_C(  -669.53), SIMDE_FLOAT32_C(   541.85),
      SIMDE_FLOAT32_C(  -783.50), SIMDE_FLOAT32_C(    38.81), SIMDE_FLOAT32_C(  -747.73), SIMDE_FLOAT32_C(   657.70),
      SIMDE_FLOAT32_C(  -777.49), SIMDE_FLOAT32_C(   696.40), SIMDE_FLOAT32_C(  -862.06), SIMDE_FLOAT32_C(   -42.75),
      SIMDE_FLOAT32_C(  -530.98), SIMDE_FLOAT32_C(  -235.16), SIMDE_FLOAT32_C(   612.64), SIMDE_FLOAT32_C(   105.83),
      SIMDE_FLOAT32_C(   802.46), SIMDE_FLOAT32_C(  -369.59), SIMDE_FLOAT32_C(  -844.13), SIMDE_FLOAT32_C(   761.26),
      SIMDE_FLOAT32_C(   821.28), SIMDE_FLOAT32_C(   399.25), SIMDE_FLOAT32_C(   814.84), SIMDE_FLOAT32_C(   883.19),
      SIMDE_FLOAT32_C(  -695.59), SIMDE_FLOAT32_C(   908.30), SIMDE_FLOAT32_C(   630.71), SIMDE_FLOAT32_C(   799.73),
      SIMDE_FLOAT32_C(  -185.34), SIMDE_FLOAT32_C(  -869.22), SIMDE_FLOAT32_C(    32.21), SIMDE_FLOAT32_C(   130.63),
      SIMDE_FLOAT32_C(  -998.09), SIMDE_FLOAT32_C(   362.68), SIMDE_FLOAT32_C(  -327.53), SIMDE_FLOAT32_C(  -781.59),
      SIMDE_FLOAT32_C(  -598.51), SIMDE_FLOAT32_C(   -75.25), SIMDE_FLOAT32_C(   876.11), SIMDE_FLOAT32_C(  -376.00),
      SIMDE_FLOAT32_C(  -378.85), SIMDE_FLOAT32_C(  -985.95), SIMDE_FLOAT32_C(   581.25), SIMDE_FLOAT32_C(    90.17),
      SIMDE_FLOAT32_C(  -221.11), SIMDE_FLOAT32_C(   193.88), SIMDE_FLOAT32_C(  -804.00), SIMDE_FLOAT32_C(  -418.64),
      SIMDE_FLOAT32_C(   824.29), SIMDE_FLOAT32_C(  -648.14), SIMDE_FLOAT32_C(  -657.38), SIMDE_FLOAT32_C(   645.57),
      SIMDE_FLOAT32_C(   751.11), SIMDE_FLOAT32_C(  -842.55), SIMDE_FLOAT32_C(   528.75), SIMDE_FLOAT32_C(  -944.47),
      SIMDE_FLOAT32_C(  -934.25), SIMDE_FLOAT32_C(   159.46), SIMDE_FLOAT32_C(   855.25), SIMDE_FLOAT32_C(  -119.59),
      SIMDE_FLOAT32_C(   290.25), SIMDE_FLOAT32_C(  -112.54), SIMDE_FLOAT32_C(  -988.96), SIMDE_FLOAT32_C(   292.16),
      SIMDE_FLOAT32_C(  -749.86), SIMDE_FLOAT32_C(  -316.48), SIMDE_FLOAT32_C(   510.57), SIMDE_FLOAT32_C(  -348.37),
      SIMDE_FLOAT32_C(   608.26), SIMDE_FLOAT32_C(   386.69), SIMDE_FLOAT32_C(   275.63), SIMDE_FLOAT32_C(  -770.59),
      SIMDE_FLOAT32_C(   400.74), SIMDE_FLOAT32_C(  -143.12), SIMDE_FLOAT32_C(   319.58), SIMDE_FLOAT32_C(  -820.37),
      SIMDE_FLOAT32_C(  -949.24), SIMDE_FLOAT32_C(   515.58), SIMDE_FLOAT32_C(  -239.01), SIMDE_FLOAT32_C(   875.05),
      SIMDE_FLOAT32_C(   867.44), SIMDE_FLOAT32_C(   103.60), SIMDE_FLOAT32_C(   520.62), SIMDE_FLOAT32_C(   618.55),
      SIMDE_FLOAT32_C(   261.06), SIMDE_FLOAT32_C(    49.37), SIMDE_FLOAT32_C(   674.08), SIMDE_FLOAT32_C(   326.81),
      SIMDE_FLOAT32_C(  -791.16), SIMDE_FLOAT32_C(   529.33), SIMDE_FLOAT32_C(  -792.77), SIMDE_FLOAT32_C(   499.08),
      SIMDE_FLOAT32_C(  -583.21), SIMDE_FLOAT32_C(  -781.73), SIMDE_FLOAT32_C(  -208.75), SIMDE_FLOAT32_C(  -333.06),
      SIMDE_FLOAT32_C(   -98.21), SIMDE_FLOAT32_C(  -698.18), SIMDE_FLOAT32_C(   318.57), SIMDE_FLOAT32_C(  -489.95),
      SIMDE_FLOAT32_C(   688.50), SIMDE_FLOAT32_C(  -405.80), SIMDE_FLOAT32_C(  -260.53), SIMDE_FLOAT32_C(    89.24),
      SIMDE_FLOAT32_C(   451.08), SIMDE_FLOAT32_C(  -940.95), SIMDE_FLOAT32_C(   268.87), SIMDE_FLOAT32_C(   501.84),
      SIMDE_FLOAT32_C(   574.63), SIMDE_FLOAT32_C(  -970.14), SIMDE_FLOAT32_C(   376.89), SIMDE_FLOAT32_C(   442.07),
      SIMDE_FLOAT32_C(   133.46), SIMDE_FLOAT32_C(  -102.49), SIMDE_FLOAT32_C(    60.62), SIMDE_FLOAT32_C(  -605.48),
      SIMDE_FLOAT32_C(   946.88), SIMDE_FLOAT32_C(  -265.30), SIMDE_FLOAT32_C(   721.33), SIMDE_FLOAT32_C(  -844.28),
      SIMDE_FLOAT32_C(  -735.97), SIMDE_FLOAT32_C(   928.55), SIMDE_FLOAT32_C(   654.80), SIMDE_FLOAT32_C(  -319.17),
      SIMDE_FLOAT32_C(  -853.18), SIMDE_FLOAT32_C(  -553.95), SIMDE_FLOAT32_C(   347.76), SIMDE_FLOAT32_C(    48.61),
      SIMDE_FLOAT32_C(  -252.13), SIMDE_FLOAT32_C(  -333.67), SIMDE_FLOAT32_C(   558.66), SIMDE_FLOAT32_C(  -563.63),
      SIMDE_FLOAT32_C(   260.53), SIMDE_FLOAT32_C(  -701.87), SIMDE_FLOAT32_C(   525.61), SIMDE_FLOAT32_C(  -288.39),
      SIMDE_FLOAT32_C(  -642.82) };
  static const simde_float32 b[] =
    { SIMDE_FLOAT32_C(  -205.51), SIMDE_FLOAT32_C(  -786.55), SIMDE_FLOAT32_C(   931.80), SIMDE_FLOAT32_C(  -175.65),
      SIMDE_FLOAT32_C(   590.34), SIMDE_FLOAT32_C(   373.87), SIMDE_FLOAT32_C(   957.81), SIMDE_FLOAT32_C(  -512.15),
      SIMDE_FLOAT32_C(  -565.51), SIMDE_FLOAT32_C(  -647.67), SIMDE_FLOAT32_C(  -565.27), SIMDE_FLOAT32_C(   169.19),
      SIMDE_FLOAT32_C(  -926.35), SIMDE_FLOAT32_C(  -409.55), SIMDE_FLOAT32_C(   433.22), SIMDE_FLOAT32_C(  -997.79),
      SIMDE_FLOAT32_C(  -754.75), SIMDE_FLOAT32_C(  -885.95), SIMDE_FLOAT32_C(  -850.97), SIMDE_FLOAT32_C(  -308.70),
      SIMDE_FLOAT32_C(   461.81), SIMDE_FLOAT32_C(   197.64), SIMDE_FLOAT32_C(   439.17), SIMDE_FLOAT32_C(  -871.86),
      SIMDE_FLOAT32_C(  -243.70), SIMDE_FLOAT32_C(   875.54), SIMDE_FLOAT32_C(   388.68), SIMDE_FLOAT32_C(    54.43),
      SIMDE_FLOAT32_C(   401.16), SIMDE_FLOAT32_C(  -899.71), SIMDE_FLOAT32_C(   411.61), SIMDE_FLOAT32_C(  -804.35),
      SIMDE_FLOAT32_C(  -686.27), SIMDE_FLOAT32_C(   343.41), SIMDE_FLOAT32_C(    19.99), SIMDE_FLOAT32_C(   904.07),
      SIMDE_FLOAT32_C(  -282.72), SIMDE_FLOAT32_C(   -22.20), SIMDE_FLOAT32_C(  -608.08), SIMDE_FLOAT32_C(   151.77),
      SIMDE_FLOAT32_C(   330.13), SIMDE_FLOAT32_C(  -173.35), SIMDE_FLOAT32_C(  -679.04), SIMDE_FLOAT32_C(   403.78),
      SIMDE_FLOAT32_C(   417.10), SIMDE_FLOAT32_C(   754.18), SIMDE_FLOAT32_C(   405.99), SIMDE_FLOAT32_C(   662.35),
      SIMDE_FLOAT32_C(   868.23), SIMDE_FLOAT32_C(   555.02), SIMDE_FLOAT32_C(  -646.34), SIMDE_FLOAT32_C(   330.04),
      SIMDE_FLOAT32_C(  -247.34), SIMDE_FLOAT32_C(   792.83), SIMDE_FLOAT32_C(   458.18), SIMDE_FLOAT32_C(   508.96),
      SIMDE_FLOAT32_C(   668.37), SIMDE_FLOAT32_C(  -153.14), SIMDE_FLOAT32_C(  -436.61), SIMDE_FLOAT32_C(    69.53),
      SIMDE_FLOAT32_C(   -52.85), SIMDE_FLOAT32_C(   975.00), SIMDE_FLOAT32_C(   265.18), SIMDE_FLOAT32_C(   260.88),
      SIMDE_FLOAT32_C(   318.41), SIMDE_FLOAT32_C(  -714.83), SIMDE_FLOAT32_C(   164.95), SIMDE_FLOAT32_C(  -964.31),
      SIMDE_FLOAT32_C(   262.97), SIMDE_FLOAT32_C(   556.87), SIMDE_FLOAT32_C(   187.45), SIMDE_FLOAT32_C(  -406.90),
      SIMDE_FLOAT32_C(  -616.48), SIMDE_FLOAT32_C(   508.41), SIMDE_FLOAT32_C(   996.88), SIMDE_FLOAT32_C(   800.62),
      SIMDE_FLOAT32_C(   262.59), SIMDE_FLOAT32_C(   402.86), SIMDE_FLOAT32_C(   462.97), SIMDE_FLOAT32_C(   130.82),
      SIMDE_FLOAT32_C(   -42.12), SIMDE_FLOAT32_C(   816.63), SIMDE_FLOAT32_C(  -539.14), SIMDE_FLOAT32_C(   710.53),
      SIMDE_FLOAT32_C(   609.46), SIMDE_FLOAT32_C(   919.05), SIMDE_FLOAT32_C(   219.49), SIMDE_FLOAT32_C(   277.83),
      SIMDE_FLOAT32_C(  -234.09), SIMDE_FLOAT32_C(   782.89), SIMDE_FLOAT32_C(  -652.64), SIMDE_FLOAT32_C(   713.05),
      SIMDE_FLOAT32_C(   757.89), SIMDE_FLOAT32_C(   612.54), SIMDE_FLOAT32_C(   -26.07), SIMDE_FLOAT32_C(    76.30),
      SIMDE_FLOAT32_C(   897.71), SIMDE_FLOAT32_C(  -861.11), SIMDE_FLOAT32_C(   111.99), SIMDE_FLOAT32_C(   160.68),
      SIMDE_FLOAT32_C(   695.76), SIMDE_FLOAT32_C(  -700.56), SIMDE_FLOAT32_C(   753.78), SIMDE_FLOAT32_C(  -920.72),
      SIMDE_FLOAT32_C(   807.85), SIMDE_FLOAT32_C(   750.65), SIMDE_FLOAT32_C(   879.91), SIMDE_FLOAT32_C(    70.44),
      SIMDE_FLOAT32_C(   153.51), SIMDE_FLOAT32_C(   342.88), SIMDE_FLOAT32_C(  -798.73), SIMDE_FLOAT32_C(  -888.61),
      SIMDE_FLOAT32_C(   159.51), SIMDE_FLOAT32_C(  -337.87), SIMDE_FLOAT32_C(   821.92), SIMDE_FLOAT32_C(  -231.03),
      SIMDE_FLOAT32_C(  -418.83), SIMDE_FLOAT32_C(    41.42), SIMDE_FLOAT32_C(  -953.20), SIMDE_FLOAT32_C(   347.08),
      SIMDE_FLOAT32_C(  -175.69), SIMDE_FLOAT32_C(  -605.84), SIMDE_FLOAT32_C(    60.13), SIMDE_FLOAT32_C(  -417.81),
      SIMDE_FLOAT32_C(  -993.30), SIMDE_FLOAT32_C(  -965.93), SIMDE_FLOAT32_C(   658.49), SIMDE_FLOAT32_C(   904.41),
      SIMDE_FLOAT32_C(  -827.04), SIMDE_FLOAT32_C(  -229.52), SIMDE_FLOAT32_C(    65.09), SIMDE_FLOAT32_C(   868.72),
      SIMDE_FLOAT32_C(    69.92), SIMDE_FLOAT32_C(  -181.14), SIMDE_FLOAT32_C(   948.00), SIMDE_FLOAT32_C(  -122.23),
      SIMDE_FLOAT32_C(  -430.49), SIMDE_FLOAT32_C(   827.91), SIMDE_FLOAT32_C(   948.22), SIMDE_FLOAT32_C(   723.03),
      SIMDE_FLOAT32_C(   170.79), SIMDE_FLOAT32_C(  -850.52), SIMDE_FLOAT32_C(   834.42), SIMDE_FLOAT32_C(  -669.70),
      SIMDE_FLOAT32_C(  -188.39), SIMDE_FLOAT32_C(   656.34), SIMDE_FLOAT32_C(    99.27), SIMDE_FLOAT32_C(   392.78),
      SIMDE_FLOAT32_C(  -302.24), SIMDE_FLOAT32_C(   146.07), SIMDE_FLOAT32_C(  -260.14), SIMDE_FLOAT32_C(   522.07),
      SIMDE_FLOAT32_C(   540.23), SIMDE_FLOAT32_C(   800.00), SIMDE_FLOAT32_C(  -895.74), SIMDE_FLOAT32_C(   546.93),
      SIMDE_FLOAT32_C(   834.06), SIMDE_FLOAT32_C(   762.75), SIMDE_FLOAT32_C(   451.34), SIMDE_FLOAT32_C(  -992.98),
      SIMDE_FLOAT32_C(  -466.77), SIMDE_FLOAT32_C(  -483.57), SIMDE_FLOAT32_C(   875.74), SIMDE_FLOAT32_C(   603.15),
      SIMDE_FLOAT32_C(   335.29), SIMDE_FLOAT32_C(   823.74), SIMDE_FLOAT32_C(  -519.08), SIMDE_FLOAT32_C(   904.81),
      SIMDE_FLOAT32_C(   651.65), SIMDE_FLOAT32_C(  -570.86), SIMDE_FLOAT32_C(   627.84), SIMDE_FLOAT32_C(  -177.56),
      SIMDE_FLOAT32_C(  -421.38), SIMDE_FLOAT32_C(   462.25), SIMDE_FLOAT32_C(   152.74), SIMDE_FLOAT32_C(   390.23),
      SIMDE_FLOAT32_C(   118.59), SIMDE_FLOAT32_C(  -747.98), SIMDE_FLOAT32_C(  -216.98), SIMDE_FLOAT32_C(   816.35),
      SIMDE_FLOAT32_C(   398.09), SIMDE_FLOAT32_C(   522.88), SIMDE_FLOAT32_C(   338.42), SIMDE_FLOAT32_C(   -61.68),
      SIMDE_FLOAT32_C(   322.88), SIMDE_FLOAT32_C(   442.68), SIMDE_FLOAT32_C(  -514.74), SIMDE_FLOAT32_C(   156.94),
      SIMDE_FLOAT32_C(   205.43), SIMDE_FLOAT32_C(   936.60), SIMDE_FLOAT32_C(   163.96), SIMDE_FLOAT32_C(   738.66),
      SIMDE_FLOAT32_C(  -546.97), SIMDE_FLOAT32_C(    39.70), SIMDE_FLOAT32_C(   341.81), SIMDE_FLOAT32_C(   788.33),
      SIMDE_FLOAT32_C(  -136.56), SIMDE_FLOAT32_C(   822.73), SIMDE_FLOAT32_C(   693.13), SIMDE_FLOAT32_C(  -484.90),
      SIMDE_FLOAT32_C(  -748.13), SIMDE_FLOAT32_C(   320.97), SIMDE_FLOAT32_C(   337.54), SIMDE_FLOAT32_C(  -169.50),
      SIMDE_FLOAT32_C(  -216.78), SIMDE_FLOAT32_C(  -509.72), SIMDE_FLOAT32_C(  -779.27), SIMDE_FLOAT32_C(   901.82),
      SIMDE_FLOAT32_C(  -257.70), SIMDE_FLOAT32_C(     3.75), SIMDE_FLOAT32_C(   718.17), SIMDE_FLOAT32_C(  -859.61),
      SIMDE_FLOAT32_C(  -473.37), SIMDE_FLOAT32_C(    56.59), SIMDE_FLOAT32_C(    78.71), SIMDE_FLOAT32_C(   849.50),
      SIMDE_FLOAT32_C(  -500.74), SIMDE_FLOAT32_C(   563.97), SIMDE_FLOAT32_C(     6.44), SIMDE_FLOAT32_C(   704.69),
      SIMDE_FLOAT32_C(   500.57), SIMDE_FLOAT32_C(  -829.59), SIMDE_FLOAT32_C(   443.35), SIMDE_FLOAT32_C(   953.60),
      SIMDE_FLOAT32_C(   210.11), SIMDE_FLOAT32_C(  -214.84), SIMDE_FLOAT32_C(   741.93), SIMDE_FLOAT32_C(  -926.45),
      SIMDE_FLOAT32_C(  -392.10), SIMDE_FLOAT32_C(   435.06), SIMDE_FLOAT32_C(  -411.35), SIMDE_FLOAT32_C(  -140.23),
      SIMDE_FLOAT32_C(  -243.97), SIMDE_FLOAT32_C(   926.19), SIMDE_FLOAT32_C(   690.27), SIMDE_FLOAT32_C(   539.25),
      SIMDE_FLOAT32_C(  -583.53), SIMDE_FLOAT32_C(   911.00), SIMDE_FLOAT32_C(   441.07), SIMDE_FLOAT32_C(   158.77),
      SIMDE_FLOAT32_C(   -85.26) };
  static const simde_float32 e[] =
    { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    62.89),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   654.50),
      SIMDE_FLOAT32_C(  1477.93), SIMDE_FLOAT32_C(  -376.66), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   173.72),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   745.56), SIMDE_FLOAT32_C(  -363.50), SIMDE_FLOAT32_C(   466.65),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1505.92), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -790.39),
      SIMDE_FLOAT32_C(  -959.43), SIMDE_FLOAT32_C(   448.75), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   536.44), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -263.20), SIMDE_FLOAT32_C(   320.37), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -431.68), SIMDE_FLOAT32_C(   -52.00),
      SIMDE_FLOAT32_C(  -383.68), SIMDE_FLOAT32_C(  -459.19), SIMDE_FLOAT32_C(   121.71), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   286.37), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1362.29),
      SIMDE_FLOAT32_C(   252.28), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C( -1223.63), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   496.83), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   422.65), SIMDE_FLOAT32_C(  -966.72), SIMDE_FLOAT32_C(  -374.55), SIMDE_FLOAT32_C(   159.45),
      SIMDE_FLOAT32_C(  1353.65), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -625.82), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1057.49), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   483.32), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   983.27), SIMDE_FLOAT32_C( -1230.29),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1146.43), SIMDE_FLOAT32_C(  -592.58), SIMDE_FLOAT32_C(  -622.44),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -745.27), SIMDE_FLOAT32_C(   670.41), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -421.67), SIMDE_FLOAT32_C(   269.45), SIMDE_FLOAT32_C( -1022.72),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1018.53), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -200.45), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1253.71), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C( -1491.88), SIMDE_FLOAT32_C(   120.48), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   471.41),
      SIMDE_FLOAT32_C(  -937.01), SIMDE_FLOAT32_C(  -304.07), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1034.27), SIMDE_FLOAT32_C( -1683.98), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -276.58), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   978.15), SIMDE_FLOAT32_C(   236.25), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1365.18), SIMDE_FLOAT32_C(   156.35), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   565.62), SIMDE_FLOAT32_C(   -68.99),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -915.79), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -567.60), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1275.75), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   775.27), SIMDE_FLOAT32_C(    41.69), SIMDE_FLOAT32_C(   293.70),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   481.98), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    47.81), SIMDE_FLOAT32_C(  -543.86), SIMDE_FLOAT32_C(  -940.71),
      SIMDE_FLOAT32_C(   284.06), SIMDE_FLOAT32_C( -1448.14), SIMDE_FLOAT32_C(   238.36), SIMDE_FLOAT32_C(    98.64),
      SIMDE_FLOAT32_C(   -82.95), SIMDE_FLOAT32_C( -1605.30), SIMDE_FLOAT32_C(    77.41), SIMDE_FLOAT32_C(    48.51),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   643.03), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   -45.04), SIMDE_FLOAT32_C(  -936.28), SIMDE_FLOAT32_C(  -469.88), SIMDE_FLOAT32_C(  -612.65),
      SIMDE_FLOAT32_C( -1401.51), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -117.27), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -75.56), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1160.82),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   536.56), SIMDE_FLOAT32_C( -1636.72),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -7.30), SIMDE_FLOAT32_C(  -577.43), SIMDE_FLOAT32_C(   936.73),
      SIMDE_FLOAT32_C(   544.56), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -887.23), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -411.85),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1604.46), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   649.92), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -320.45),
      SIMDE_FLOAT32_C(   905.28), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   708.78), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1361.45),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1026.73), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   634.20), SIMDE_FLOAT32_C(  -666.46), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1310.17),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   564.29), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1797.88),
      SIMDE_FLOAT32_C(  -946.08), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   759.11), SIMDE_FLOAT32_C(   188.84),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -131.61), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1612.87), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00) };

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
    rv = simde_svsub_f32_z(pv, av, bv);

    simde_svst1_f32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vf32(len, e, r, 1);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)];
  simde_float32 a[1024 / sizeof(simde_float32)], b[1024 / sizeof(simde_float32)], e[1024 / sizeof(simde_float32)];
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

    ev = simde_svsub_f32_z(pv, av, bv);

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
test_simde_svsub_f32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) };
  static const simde_float32 a[] =
    { SIMDE_FLOAT32_C(  -710.97), SIMDE_FLOAT32_C(   673.33), SIMDE_FLOAT32_C(   498.51), SIMDE_FLOAT32_C(  -573.37),
      SIMDE_FLOAT32_C(   488.93), SIMDE_FLOAT32_C(   881.51), SIMDE_FLOAT32_C(   199.23), SIMDE_FLOAT32_C(  -812.69),
      SIMDE_FLOAT32_C(   731.61), SIMDE_FLOAT32_C(   689.35), SIMDE_FLOAT32_C(   243.17), SIMDE_FLOAT32_C(   972.84),
      SIMDE_FLOAT32_C(   126.79), SIMDE_FLOAT32_C(  -218.93), SIMDE_FLOAT32_C(   496.75), SIMDE_FLOAT32_C(   753.83),
      SIMDE_FLOAT32_C(   534.54), SIMDE_FLOAT32_C(   104.22), SIMDE_FLOAT32_C(   825.12), SIMDE_FLOAT32_C(   692.81),
      SIMDE_FLOAT32_C(  -223.02), SIMDE_FLOAT32_C(   512.19), SIMDE_FLOAT32_C(  -491.16), SIMDE_FLOAT32_C(   806.81),
      SIMDE_FLOAT32_C(  -445.02), SIMDE_FLOAT32_C(   146.41), SIMDE_FLOAT32_C(  -980.84), SIMDE_FLOAT32_C(   914.85),
      SIMDE_FLOAT32_C(   497.25), SIMDE_FLOAT32_C(   286.20), SIMDE_FLOAT32_C(   461.33), SIMDE_FLOAT32_C(   786.28),
      SIMDE_FLOAT32_C(   -40.48), SIMDE_FLOAT32_C(   -40.16), SIMDE_FLOAT32_C(  -787.09), SIMDE_FLOAT32_C(  -551.55),
      SIMDE_FLOAT32_C(  -158.65), SIMDE_FLOAT32_C(   412.14), SIMDE_FLOAT32_C(  -364.24), SIMDE_FLOAT32_C(  -427.04),
      SIMDE_FLOAT32_C(   101.49), SIMDE_FLOAT32_C(   878.93), SIMDE_FLOAT32_C(  -454.19), SIMDE_FLOAT32_C(  -771.73),
      SIMDE_FLOAT32_C(  -340.00), SIMDE_FLOAT32_C(  -957.45), SIMDE_FLOAT32_C(   982.10), SIMDE_FLOAT32_C(  -805.46),
      SIMDE_FLOAT32_C(   146.78), SIMDE_FLOAT32_C(   807.22), SIMDE_FLOAT32_C(   887.35), SIMDE_FLOAT32_C(   923.76),
      SIMDE_FLOAT32_C(   319.41), SIMDE_FLOAT32_C(  -603.81), SIMDE_FLOAT32_C(   730.58), SIMDE_FLOAT32_C(   874.38),
      SIMDE_FLOAT32_C(   542.60), SIMDE_FLOAT32_C(   749.74), SIMDE_FLOAT32_C(   789.23), SIMDE_FLOAT32_C(    39.86),
      SIMDE_FLOAT32_C(    35.93), SIMDE_FLOAT32_C(   250.56), SIMDE_FLOAT32_C(  -173.87), SIMDE_FLOAT32_C(   995.45),
      SIMDE_FLOAT32_C(  -789.60), SIMDE_FLOAT32_C(    39.04), SIMDE_FLOAT32_C(  -556.10), SIMDE_FLOAT32_C(    51.76),
      SIMDE_FLOAT32_C(  -548.82), SIMDE_FLOAT32_C(    79.66), SIMDE_FLOAT32_C(   624.72), SIMDE_FLOAT32_C(   552.67),
      SIMDE_FLOAT32_C(   -41.41), SIMDE_FLOAT32_C(  -829.47), SIMDE_FLOAT32_C(   780.94), SIMDE_FLOAT32_C(   618.58),
      SIMDE_FLOAT32_C(  -786.92), SIMDE_FLOAT32_C(   763.04), SIMDE_FLOAT32_C(   813.12), SIMDE_FLOAT32_C(   359.86),
      SIMDE_FLOAT32_C(   570.26), SIMDE_FLOAT32_C(   700.47), SIMDE_FLOAT32_C(   283.62), SIMDE_FLOAT32_C(  -110.34),
      SIMDE_FLOAT32_C(  -903.33), SIMDE_FLOAT32_C(    14.19), SIMDE_FLOAT32_C(  -235.95), SIMDE_FLOAT32_C(   639.27),
      SIMDE_FLOAT32_C(  -236.07), SIMDE_FLOAT32_C(  -446.72), SIMDE_FLOAT32_C(  -320.87), SIMDE_FLOAT32_C(   799.86),
      SIMDE_FLOAT32_C(   803.84), SIMDE_FLOAT32_C(   505.26), SIMDE_FLOAT32_C(   795.31), SIMDE_FLOAT32_C(  -985.76),
      SIMDE_FLOAT32_C(  -455.70), SIMDE_FLOAT32_C(  -760.78), SIMDE_FLOAT32_C(    66.00), SIMDE_FLOAT32_C(    -4.52),
      SIMDE_FLOAT32_C(   318.88), SIMDE_FLOAT32_C(  -309.28), SIMDE_FLOAT32_C(  -451.85), SIMDE_FLOAT32_C(  -722.54),
      SIMDE_FLOAT32_C(  -138.75), SIMDE_FLOAT32_C(  -670.91), SIMDE_FLOAT32_C(   896.05), SIMDE_FLOAT32_C(    74.33),
      SIMDE_FLOAT32_C(  -907.87), SIMDE_FLOAT32_C(   709.17), SIMDE_FLOAT32_C(  -565.81), SIMDE_FLOAT32_C(   662.39),
      SIMDE_FLOAT32_C(   409.64), SIMDE_FLOAT32_C(   717.81), SIMDE_FLOAT32_C(  -447.95), SIMDE_FLOAT32_C(   506.31),
      SIMDE_FLOAT32_C(  -267.99), SIMDE_FLOAT32_C(   316.10), SIMDE_FLOAT32_C(   145.58), SIMDE_FLOAT32_C(   495.94),
      SIMDE_FLOAT32_C(   869.37), SIMDE_FLOAT32_C(   824.71), SIMDE_FLOAT32_C(   295.80), SIMDE_FLOAT32_C(   673.21),
      SIMDE_FLOAT32_C(   329.98), SIMDE_FLOAT32_C(    91.11), SIMDE_FLOAT32_C(   687.46), SIMDE_FLOAT32_C(   874.28),
      SIMDE_FLOAT32_C(   330.33), SIMDE_FLOAT32_C(  -246.54), SIMDE_FLOAT32_C(  -130.24), SIMDE_FLOAT32_C(  -350.79),
      SIMDE_FLOAT32_C(   444.18), SIMDE_FLOAT32_C(   417.92), SIMDE_FLOAT32_C(   -73.33), SIMDE_FLOAT32_C(  -694.57),
      SIMDE_FLOAT32_C(   747.01), SIMDE_FLOAT32_C(  -177.28), SIMDE_FLOAT32_C(   379.77), SIMDE_FLOAT32_C(   839.14),
      SIMDE_FLOAT32_C(  -468.11), SIMDE_FLOAT32_C(   813.96), SIMDE_FLOAT32_C(   501.53), SIMDE_FLOAT32_C(   941.53),
      SIMDE_FLOAT32_C(   531.77), SIMDE_FLOAT32_C(  -946.42), SIMDE_FLOAT32_C(   447.84), SIMDE_FLOAT32_C(  -736.22),
      SIMDE_FLOAT32_C(   369.68), SIMDE_FLOAT32_C(  -406.58), SIMDE_FLOAT32_C(   759.72), SIMDE_FLOAT32_C(   239.05),
      SIMDE_FLOAT32_C(  -581.86), SIMDE_FLOAT32_C(    55.51), SIMDE_FLOAT32_C(   -87.73), SIMDE_FLOAT32_C(   748.11),
      SIMDE_FLOAT32_C(  -853.37), SIMDE_FLOAT32_C(  -400.28), SIMDE_FLOAT32_C(   622.39), SIMDE_FLOAT32_C(   476.96),
      SIMDE_FLOAT32_C(   353.18), SIMDE_FLOAT32_C(  -507.84), SIMDE_FLOAT32_C(  -873.84), SIMDE_FLOAT32_C(  -202.64),
      SIMDE_FLOAT32_C(   910.07), SIMDE_FLOAT32_C(    52.83), SIMDE_FLOAT32_C(   102.80), SIMDE_FLOAT32_C(   657.08),
      SIMDE_FLOAT32_C(   875.55), SIMDE_FLOAT32_C(  -517.44), SIMDE_FLOAT32_C(   496.23), SIMDE_FLOAT32_C(  -592.57),
      SIMDE_FLOAT32_C(  -703.48), SIMDE_FLOAT32_C(    -2.25), SIMDE_FLOAT32_C(  -651.04), SIMDE_FLOAT32_C(   828.30),
      SIMDE_FLOAT32_C(    51.34), SIMDE_FLOAT32_C(   796.80), SIMDE_FLOAT32_C(  -907.93), SIMDE_FLOAT32_C(  -578.99),
      SIMDE_FLOAT32_C(  -609.77), SIMDE_FLOAT32_C(   851.79), SIMDE_FLOAT32_C(   660.07), SIMDE_FLOAT32_C(  -191.64),
      SIMDE_FLOAT32_C(   -92.70), SIMDE_FLOAT32_C(  -427.67), SIMDE_FLOAT32_C(  -443.52), SIMDE_FLOAT32_C(    53.93),
      SIMDE_FLOAT32_C(   172.05), SIMDE_FLOAT32_C(  -821.13), SIMDE_FLOAT32_C(  -469.11), SIMDE_FLOAT32_C(  -474.77),
      SIMDE_FLOAT32_C(  -328.97), SIMDE_FLOAT32_C(  -342.95), SIMDE_FLOAT32_C(   322.59), SIMDE_FLOAT32_C(  -418.90),
      SIMDE_FLOAT32_C(   709.88), SIMDE_FLOAT32_C(  -574.61), SIMDE_FLOAT32_C(  -761.81), SIMDE_FLOAT32_C(   585.43),
      SIMDE_FLOAT32_C(   -92.04), SIMDE_FLOAT32_C(   734.41), SIMDE_FLOAT32_C(   992.87), SIMDE_FLOAT32_C(   204.48),
      SIMDE_FLOAT32_C(  -267.83), SIMDE_FLOAT32_C(  -658.17), SIMDE_FLOAT32_C(    32.78), SIMDE_FLOAT32_C(   783.50),
      SIMDE_FLOAT32_C(  -861.37), SIMDE_FLOAT32_C(   124.85), SIMDE_FLOAT32_C(  -795.48), SIMDE_FLOAT32_C(  -471.14),
      SIMDE_FLOAT32_C(   -23.36), SIMDE_FLOAT32_C(   864.58), SIMDE_FLOAT32_C(   337.22), SIMDE_FLOAT32_C(   883.94),
      SIMDE_FLOAT32_C(  -563.09), SIMDE_FLOAT32_C(   893.70), SIMDE_FLOAT32_C(   -62.13), SIMDE_FLOAT32_C(   608.97),
      SIMDE_FLOAT32_C(  -927.43), SIMDE_FLOAT32_C(   468.76), SIMDE_FLOAT32_C(  -865.80), SIMDE_FLOAT32_C(  -256.40),
      SIMDE_FLOAT32_C(  -874.19), SIMDE_FLOAT32_C(   456.79), SIMDE_FLOAT32_C(   324.71), SIMDE_FLOAT32_C(   835.70),
      SIMDE_FLOAT32_C(   882.19), SIMDE_FLOAT32_C(   562.90), SIMDE_FLOAT32_C(   421.13), SIMDE_FLOAT32_C(  -209.86),
      SIMDE_FLOAT32_C(   297.31), SIMDE_FLOAT32_C(   414.00), SIMDE_FLOAT32_C(   994.62), SIMDE_FLOAT32_C(  -970.52),
      SIMDE_FLOAT32_C(   755.83), SIMDE_FLOAT32_C(    27.40), SIMDE_FLOAT32_C(   812.98), SIMDE_FLOAT32_C(   894.46),
      SIMDE_FLOAT32_C(  -847.75), SIMDE_FLOAT32_C(  -982.50), SIMDE_FLOAT32_C(  -576.68), SIMDE_FLOAT32_C(   128.89),
      SIMDE_FLOAT32_C(   882.08) };
  static const simde_float32 b[] =
    { SIMDE_FLOAT32_C(   760.54), SIMDE_FLOAT32_C(    12.83), SIMDE_FLOAT32_C(  -681.01), SIMDE_FLOAT32_C(   654.25),
      SIMDE_FLOAT32_C(   950.71), SIMDE_FLOAT32_C(   927.96), SIMDE_FLOAT32_C(   726.82), SIMDE_FLOAT32_C(   419.47),
      SIMDE_FLOAT32_C(  -937.84), SIMDE_FLOAT32_C(  -529.58), SIMDE_FLOAT32_C(   545.28), SIMDE_FLOAT32_C(   518.95),
      SIMDE_FLOAT32_C(   795.13), SIMDE_FLOAT32_C(   380.98), SIMDE_FLOAT32_C(   401.14), SIMDE_FLOAT32_C(   358.02),
      SIMDE_FLOAT32_C(  -197.89), SIMDE_FLOAT32_C(  -808.72), SIMDE_FLOAT32_C(  -344.67), SIMDE_FLOAT32_C(  -783.89),
      SIMDE_FLOAT32_C(  -814.10), SIMDE_FLOAT32_C(  -315.19), SIMDE_FLOAT32_C(   971.94), SIMDE_FLOAT32_C(   213.30),
      SIMDE_FLOAT32_C(  -502.21), SIMDE_FLOAT32_C(   866.40), SIMDE_FLOAT32_C(   365.54), SIMDE_FLOAT32_C(  -484.71),
      SIMDE_FLOAT32_C(  -710.28), SIMDE_FLOAT32_C(  -505.57), SIMDE_FLOAT32_C(  -602.64), SIMDE_FLOAT32_C(  -949.73),
      SIMDE_FLOAT32_C(   507.26), SIMDE_FLOAT32_C(  -283.64), SIMDE_FLOAT32_C(   704.51), SIMDE_FLOAT32_C(   457.97),
      SIMDE_FLOAT32_C(  -355.68), SIMDE_FLOAT32_C(   431.33), SIMDE_FLOAT32_C(  -122.56), SIMDE_FLOAT32_C(  -293.52),
      SIMDE_FLOAT32_C(   901.76), SIMDE_FLOAT32_C(  -577.28), SIMDE_FLOAT32_C(  -774.57), SIMDE_FLOAT32_C(   696.89),
      SIMDE_FLOAT32_C(   803.70), SIMDE_FLOAT32_C(   626.56), SIMDE_FLOAT32_C(    54.91), SIMDE_FLOAT32_C(  -394.18),
      SIMDE_FLOAT32_C(   817.84), SIMDE_FLOAT32_C(   710.24), SIMDE_FLOAT32_C(  -178.07), SIMDE_FLOAT32_C(  -996.26),
      SIMDE_FLOAT32_C(  -604.95), SIMDE_FLOAT32_C(  -206.13), SIMDE_FLOAT32_C(   217.04), SIMDE_FLOAT32_C(  -107.16),
      SIMDE_FLOAT32_C(  -339.73), SIMDE_FLOAT32_C(  -417.42), SIMDE_FLOAT32_C(   408.13), SIMDE_FLOAT32_C(   -50.01),
      SIMDE_FLOAT32_C(    77.02), SIMDE_FLOAT32_C(   805.49), SIMDE_FLOAT32_C(     0.26), SIMDE_FLOAT32_C(  -415.72),
      SIMDE_FLOAT32_C(  -478.15), SIMDE_FLOAT32_C(  -295.23), SIMDE_FLOAT32_C(  -957.75), SIMDE_FLOAT32_C(   166.17),
      SIMDE_FLOAT32_C(  -863.89), SIMDE_FLOAT32_C(   -80.31), SIMDE_FLOAT32_C(   872.64), SIMDE_FLOAT32_C(  -962.14),
      SIMDE_FLOAT32_C(   342.41), SIMDE_FLOAT32_C(  -901.93), SIMDE_FLOAT32_C(   734.75), SIMDE_FLOAT32_C(   146.12),
      SIMDE_FLOAT32_C(   724.63), SIMDE_FLOAT32_C(  -210.34), SIMDE_FLOAT32_C(   751.93), SIMDE_FLOAT32_C(   542.48),
      SIMDE_FLOAT32_C(  -500.10), SIMDE_FLOAT32_C(  -426.14), SIMDE_FLOAT32_C(   546.22), SIMDE_FLOAT32_C(  -105.05),
      SIMDE_FLOAT32_C(   367.73), SIMDE_FLOAT32_C(  -236.74), SIMDE_FLOAT32_C(   787.79), SIMDE_FLOAT32_C(  -972.00),
      SIMDE_FLOAT32_C(   345.84), SIMDE_FLOAT32_C(   195.92), SIMDE_FLOAT32_C(   -22.01), SIMDE_FLOAT32_C(  -577.14),
      SIMDE_FLOAT32_C(     1.41), SIMDE_FLOAT32_C(   978.25), SIMDE_FLOAT32_C(     7.14), SIMDE_FLOAT32_C(   523.27),
      SIMDE_FLOAT32_C(  -316.97), SIMDE_FLOAT32_C(    49.39), SIMDE_FLOAT32_C(  -310.57), SIMDE_FLOAT32_C(  -180.87),
      SIMDE_FLOAT32_C(   969.08), SIMDE_FLOAT32_C(  -437.92), SIMDE_FLOAT32_C(  -143.00), SIMDE_FLOAT32_C(   311.49),
      SIMDE_FLOAT32_C(  -339.85), SIMDE_FLOAT32_C(  -408.25), SIMDE_FLOAT32_C(  -542.39), SIMDE_FLOAT32_C(  -615.22),
      SIMDE_FLOAT32_C(   381.40), SIMDE_FLOAT32_C(  -790.46), SIMDE_FLOAT32_C(   927.26), SIMDE_FLOAT32_C(   881.30),
      SIMDE_FLOAT32_C(  -216.60), SIMDE_FLOAT32_C(   473.48), SIMDE_FLOAT32_C(  -223.74), SIMDE_FLOAT32_C(  -848.87),
      SIMDE_FLOAT32_C(  -763.26), SIMDE_FLOAT32_C(  -435.95), SIMDE_FLOAT32_C(  -820.87), SIMDE_FLOAT32_C(   582.58),
      SIMDE_FLOAT32_C(   759.97), SIMDE_FLOAT32_C(   157.13), SIMDE_FLOAT32_C(  -994.56), SIMDE_FLOAT32_C(  -238.61),
      SIMDE_FLOAT32_C(   135.38), SIMDE_FLOAT32_C(    12.58), SIMDE_FLOAT32_C(  -715.34), SIMDE_FLOAT32_C(   818.41),
      SIMDE_FLOAT32_C(  -938.04), SIMDE_FLOAT32_C(   -25.91), SIMDE_FLOAT32_C(  -362.46), SIMDE_FLOAT32_C(  -968.96),
      SIMDE_FLOAT32_C(   536.16), SIMDE_FLOAT32_C(   494.54), SIMDE_FLOAT32_C(   342.53), SIMDE_FLOAT32_C(  -803.69),
      SIMDE_FLOAT32_C(  -913.71), SIMDE_FLOAT32_C(   800.13), SIMDE_FLOAT32_C(  -418.91), SIMDE_FLOAT32_C(   467.69),
      SIMDE_FLOAT32_C(  -990.33), SIMDE_FLOAT32_C(  -491.65), SIMDE_FLOAT32_C(   349.00), SIMDE_FLOAT32_C(  -206.93),
      SIMDE_FLOAT32_C(   981.83), SIMDE_FLOAT32_C(  -874.75), SIMDE_FLOAT32_C(   -55.79), SIMDE_FLOAT32_C(  -781.44),
      SIMDE_FLOAT32_C(  -310.69), SIMDE_FLOAT32_C(   123.34), SIMDE_FLOAT32_C(   801.14), SIMDE_FLOAT32_C(  -550.72),
      SIMDE_FLOAT32_C(  -719.53), SIMDE_FLOAT32_C(   806.58), SIMDE_FLOAT32_C(   210.67), SIMDE_FLOAT32_C(   415.85),
      SIMDE_FLOAT32_C(  -180.84), SIMDE_FLOAT32_C(   495.33), SIMDE_FLOAT32_C(   234.26), SIMDE_FLOAT32_C(  -118.88),
      SIMDE_FLOAT32_C(  -530.59), SIMDE_FLOAT32_C(   871.81), SIMDE_FLOAT32_C(   -87.84), SIMDE_FLOAT32_C(  -994.42),
      SIMDE_FLOAT32_C(   366.35), SIMDE_FLOAT32_C(  -745.31), SIMDE_FLOAT32_C(  -798.11), SIMDE_FLOAT32_C(   452.63),
      SIMDE_FLOAT32_C(  -945.17), SIMDE_FLOAT32_C(  -217.02), SIMDE_FLOAT32_C(   -79.68), SIMDE_FLOAT32_C(  -935.50),
      SIMDE_FLOAT32_C(   291.33), SIMDE_FLOAT32_C(  -730.68), SIMDE_FLOAT32_C(  -142.42), SIMDE_FLOAT32_C(   273.15),
      SIMDE_FLOAT32_C(  -605.43), SIMDE_FLOAT32_C(   801.78), SIMDE_FLOAT32_C(   491.72), SIMDE_FLOAT32_C(    83.88),
      SIMDE_FLOAT32_C(   -74.88), SIMDE_FLOAT32_C(   292.86), SIMDE_FLOAT32_C(   533.16), SIMDE_FLOAT32_C(   205.59),
      SIMDE_FLOAT32_C(    99.44), SIMDE_FLOAT32_C(  -256.17), SIMDE_FLOAT32_C(  -378.55), SIMDE_FLOAT32_C(   918.60),
      SIMDE_FLOAT32_C(  -760.84), SIMDE_FLOAT32_C(   855.71), SIMDE_FLOAT32_C(  -200.27), SIMDE_FLOAT32_C(  -291.43),
      SIMDE_FLOAT32_C(   727.52), SIMDE_FLOAT32_C(   711.89), SIMDE_FLOAT32_C(  -285.85), SIMDE_FLOAT32_C(    93.87),
      SIMDE_FLOAT32_C(   966.58), SIMDE_FLOAT32_C(   -83.96), SIMDE_FLOAT32_C(  -453.50), SIMDE_FLOAT32_C(  -978.59),
      SIMDE_FLOAT32_C(   699.02), SIMDE_FLOAT32_C(   466.82), SIMDE_FLOAT32_C(  -914.09), SIMDE_FLOAT32_C(    -9.65),
      SIMDE_FLOAT32_C(   736.14), SIMDE_FLOAT32_C(   -56.51), SIMDE_FLOAT32_C(  -736.50), SIMDE_FLOAT32_C(  -869.28),
      SIMDE_FLOAT32_C(  -254.73), SIMDE_FLOAT32_C(   755.22), SIMDE_FLOAT32_C(   214.60), SIMDE_FLOAT32_C(   670.39),
      SIMDE_FLOAT32_C(    48.08), SIMDE_FLOAT32_C(  -252.24), SIMDE_FLOAT32_C(  -124.02), SIMDE_FLOAT32_C(  -852.47),
      SIMDE_FLOAT32_C(   491.59), SIMDE_FLOAT32_C(   497.43), SIMDE_FLOAT32_C(  -933.87), SIMDE_FLOAT32_C(   730.75),
      SIMDE_FLOAT32_C(   353.14), SIMDE_FLOAT32_C(  -134.14), SIMDE_FLOAT32_C(  -560.68), SIMDE_FLOAT32_C(    80.66),
      SIMDE_FLOAT32_C(  -422.25), SIMDE_FLOAT32_C(   153.47), SIMDE_FLOAT32_C(  -825.48), SIMDE_FLOAT32_C(  -455.67),
      SIMDE_FLOAT32_C(  -930.49), SIMDE_FLOAT32_C(  -278.98), SIMDE_FLOAT32_C(  -434.26), SIMDE_FLOAT32_C(   768.53),
      SIMDE_FLOAT32_C(  -812.15), SIMDE_FLOAT32_C(  -348.35), SIMDE_FLOAT32_C(  -241.12), SIMDE_FLOAT32_C(   923.99),
      SIMDE_FLOAT32_C(   595.14), SIMDE_FLOAT32_C(    22.38), SIMDE_FLOAT32_C(  -945.29), SIMDE_FLOAT32_C(  -659.59),
      SIMDE_FLOAT32_C(  -222.40), SIMDE_FLOAT32_C(   269.31), SIMDE_FLOAT32_C(  -989.20), SIMDE_FLOAT32_C(   825.68),
      SIMDE_FLOAT32_C(  -982.94) };
  static const simde_float32 e[] =
    { SIMDE_FLOAT32_C( -1471.51), SIMDE_FLOAT32_C(   673.33), SIMDE_FLOAT32_C(  1179.52), SIMDE_FLOAT32_C( -1227.62),
      SIMDE_FLOAT32_C(   488.93), SIMDE_FLOAT32_C(   881.51), SIMDE_FLOAT32_C(  -527.59), SIMDE_FLOAT32_C( -1232.16),
      SIMDE_FLOAT32_C(  1669.45), SIMDE_FLOAT32_C(  1218.93), SIMDE_FLOAT32_C(   243.17), SIMDE_FLOAT32_C(   453.89),
      SIMDE_FLOAT32_C(  -668.34), SIMDE_FLOAT32_C(  -218.93), SIMDE_FLOAT32_C(   496.75), SIMDE_FLOAT32_C(   395.81),
      SIMDE_FLOAT32_C(   534.54), SIMDE_FLOAT32_C(   104.22), SIMDE_FLOAT32_C(  1169.79), SIMDE_FLOAT32_C(  1476.70),
      SIMDE_FLOAT32_C(  -223.02), SIMDE_FLOAT32_C(   827.38), SIMDE_FLOAT32_C(  -491.16), SIMDE_FLOAT32_C(   593.51),
      SIMDE_FLOAT32_C(    57.19), SIMDE_FLOAT32_C(  -719.99), SIMDE_FLOAT32_C(  -980.84), SIMDE_FLOAT32_C(  1399.56),
      SIMDE_FLOAT32_C(  1207.53), SIMDE_FLOAT32_C(   286.20), SIMDE_FLOAT32_C(  1063.97), SIMDE_FLOAT32_C(  1736.01),
      SIMDE_FLOAT32_C(   -40.48), SIMDE_FLOAT32_C(   243.48), SIMDE_FLOAT32_C(  -787.09), SIMDE_FLOAT32_C( -1009.52),
      SIMDE_FLOAT32_C(   197.03), SIMDE_FLOAT32_C(   412.14), SIMDE_FLOAT32_C(  -364.24), SIMDE_FLOAT32_C(  -427.04),
      SIMDE_FLOAT32_C(   101.49), SIMDE_FLOAT32_C(  1456.21), SIMDE_FLOAT32_C(  -454.19), SIMDE_FLOAT32_C(  -771.73),
      SIMDE_FLOAT32_C(  -340.00), SIMDE_FLOAT32_C( -1584.01), SIMDE_FLOAT32_C(   982.10), SIMDE_FLOAT32_C(  -411.28),
      SIMDE_FLOAT32_C(   146.78), SIMDE_FLOAT32_C(   807.22), SIMDE_FLOAT32_C(   887.35), SIMDE_FLOAT32_C(   923.76),
      SIMDE_FLOAT32_C(   319.41), SIMDE_FLOAT32_C(  -397.68), SIMDE_FLOAT32_C(   513.54), SIMDE_FLOAT32_C(   981.54),
      SIMDE_FLOAT32_C(   542.60), SIMDE_FLOAT32_C(   749.74), SIMDE_FLOAT32_C(   789.23), SIMDE_FLOAT32_C(    39.86),
      SIMDE_FLOAT32_C(   -41.09), SIMDE_FLOAT32_C(   250.56), SIMDE_FLOAT32_C(  -174.13), SIMDE_FLOAT32_C(   995.45),
      SIMDE_FLOAT32_C(  -789.60), SIMDE_FLOAT32_C(    39.04), SIMDE_FLOAT32_C(   401.65), SIMDE_FLOAT32_C(  -114.41),
      SIMDE_FLOAT32_C(   315.07), SIMDE_FLOAT32_C(    79.66), SIMDE_FLOAT32_C(   624.72), SIMDE_FLOAT32_C(  1514.81),
      SIMDE_FLOAT32_C(  -383.82), SIMDE_FLOAT32_C(    72.46), SIMDE_FLOAT32_C(   780.94), SIMDE_FLOAT32_C(   618.58),
      SIMDE_FLOAT32_C(  -786.92), SIMDE_FLOAT32_C(   763.04), SIMDE_FLOAT32_C(   813.12), SIMDE_FLOAT32_C(  -182.62),
      SIMDE_FLOAT32_C(  1070.36), SIMDE_FLOAT32_C(  1126.61), SIMDE_FLOAT32_C(   283.62), SIMDE_FLOAT32_C(    -5.29),
      SIMDE_FLOAT32_C( -1271.06), SIMDE_FLOAT32_C(    14.19), SIMDE_FLOAT32_C(  -235.95), SIMDE_FLOAT32_C(   639.27),
      SIMDE_FLOAT32_C(  -236.07), SIMDE_FLOAT32_C(  -446.72), SIMDE_FLOAT32_C(  -320.87), SIMDE_FLOAT32_C(  1377.00),
      SIMDE_FLOAT32_C(   803.84), SIMDE_FLOAT32_C(  -472.99), SIMDE_FLOAT32_C(   795.31), SIMDE_FLOAT32_C(  -985.76),
      SIMDE_FLOAT32_C(  -138.73), SIMDE_FLOAT32_C(  -810.17), SIMDE_FLOAT32_C(   376.57), SIMDE_FLOAT32_C(   176.35),
      SIMDE_FLOAT32_C(  -650.20), SIMDE_FLOAT32_C(   128.64), SIMDE_FLOAT32_C(  -451.85), SIMDE_FLOAT32_C(  -722.54),
      SIMDE_FLOAT32_C(  -138.75), SIMDE_FLOAT32_C(  -670.91), SIMDE_FLOAT32_C(  1438.44), SIMDE_FLOAT32_C(    74.33),
      SIMDE_FLOAT32_C( -1289.27), SIMDE_FLOAT32_C(   709.17), SIMDE_FLOAT32_C( -1493.07), SIMDE_FLOAT32_C(  -218.91),
      SIMDE_FLOAT32_C(   626.24), SIMDE_FLOAT32_C(   717.81), SIMDE_FLOAT32_C(  -447.95), SIMDE_FLOAT32_C(   506.31),
      SIMDE_FLOAT32_C(  -267.99), SIMDE_FLOAT32_C(   752.05), SIMDE_FLOAT32_C(   145.58), SIMDE_FLOAT32_C(   495.94),
      SIMDE_FLOAT32_C(   109.40), SIMDE_FLOAT32_C(   667.58), SIMDE_FLOAT32_C(   295.80), SIMDE_FLOAT32_C(   911.82),
      SIMDE_FLOAT32_C(   194.60), SIMDE_FLOAT32_C(    78.53), SIMDE_FLOAT32_C(   687.46), SIMDE_FLOAT32_C(    55.87),
      SIMDE_FLOAT32_C(   330.33), SIMDE_FLOAT32_C(  -220.63), SIMDE_FLOAT32_C(   232.22), SIMDE_FLOAT32_C(   618.17),
      SIMDE_FLOAT32_C(   444.18), SIMDE_FLOAT32_C(   -76.62), SIMDE_FLOAT32_C(  -415.86), SIMDE_FLOAT32_C(   109.12),
      SIMDE_FLOAT32_C(   747.01), SIMDE_FLOAT32_C(  -977.41), SIMDE_FLOAT32_C(   798.68), SIMDE_FLOAT32_C(   839.14),
      SIMDE_FLOAT32_C(   522.22), SIMDE_FLOAT32_C(   813.96), SIMDE_FLOAT32_C(   501.53), SIMDE_FLOAT32_C(   941.53),
      SIMDE_FLOAT32_C(  -450.06), SIMDE_FLOAT32_C(   -71.67), SIMDE_FLOAT32_C(   447.84), SIMDE_FLOAT32_C(  -736.22),
      SIMDE_FLOAT32_C(   369.68), SIMDE_FLOAT32_C(  -406.58), SIMDE_FLOAT32_C(   759.72), SIMDE_FLOAT32_C(   789.77),
      SIMDE_FLOAT32_C(  -581.86), SIMDE_FLOAT32_C(    55.51), SIMDE_FLOAT32_C(   -87.73), SIMDE_FLOAT32_C(   332.26),
      SIMDE_FLOAT32_C(  -672.53), SIMDE_FLOAT32_C(  -400.28), SIMDE_FLOAT32_C(   622.39), SIMDE_FLOAT32_C(   476.96),
      SIMDE_FLOAT32_C(   883.77), SIMDE_FLOAT32_C(  -507.84), SIMDE_FLOAT32_C(  -873.84), SIMDE_FLOAT32_C(   791.78),
      SIMDE_FLOAT32_C(   910.07), SIMDE_FLOAT32_C(    52.83), SIMDE_FLOAT32_C(   102.80), SIMDE_FLOAT32_C(   657.08),
      SIMDE_FLOAT32_C(  1820.72), SIMDE_FLOAT32_C(  -517.44), SIMDE_FLOAT32_C(   496.23), SIMDE_FLOAT32_C(  -592.57),
      SIMDE_FLOAT32_C(  -994.81), SIMDE_FLOAT32_C(   728.43), SIMDE_FLOAT32_C(  -508.62), SIMDE_FLOAT32_C(   828.30),
      SIMDE_FLOAT32_C(   656.77), SIMDE_FLOAT32_C(    -4.98), SIMDE_FLOAT32_C(  -907.93), SIMDE_FLOAT32_C(  -578.99),
      SIMDE_FLOAT32_C(  -609.77), SIMDE_FLOAT32_C(   558.93), SIMDE_FLOAT32_C(   660.07), SIMDE_FLOAT32_C(  -397.23),
      SIMDE_FLOAT32_C(   -92.70), SIMDE_FLOAT32_C(  -171.50), SIMDE_FLOAT32_C(   -64.97), SIMDE_FLOAT32_C(  -864.67),
      SIMDE_FLOAT32_C(   932.89), SIMDE_FLOAT32_C(  -821.13), SIMDE_FLOAT32_C(  -268.84), SIMDE_FLOAT32_C(  -183.34),
      SIMDE_FLOAT32_C( -1056.49), SIMDE_FLOAT32_C( -1054.84), SIMDE_FLOAT32_C(   322.59), SIMDE_FLOAT32_C(  -512.77),
      SIMDE_FLOAT32_C(  -256.70), SIMDE_FLOAT32_C(  -490.65), SIMDE_FLOAT32_C(  -761.81), SIMDE_FLOAT32_C(   585.43),
      SIMDE_FLOAT32_C(   -92.04), SIMDE_FLOAT32_C(   734.41), SIMDE_FLOAT32_C(  1906.96), SIMDE_FLOAT32_C(   214.13),
      SIMDE_FLOAT32_C( -1003.97), SIMDE_FLOAT32_C(  -601.66), SIMDE_FLOAT32_C(    32.78), SIMDE_FLOAT32_C(  1652.78),
      SIMDE_FLOAT32_C(  -606.64), SIMDE_FLOAT32_C(   124.85), SIMDE_FLOAT32_C(  -795.48), SIMDE_FLOAT32_C(  -471.14),
      SIMDE_FLOAT32_C(   -23.36), SIMDE_FLOAT32_C(   864.58), SIMDE_FLOAT32_C(   461.24), SIMDE_FLOAT32_C(  1736.41),
      SIMDE_FLOAT32_C( -1054.68), SIMDE_FLOAT32_C(   396.27), SIMDE_FLOAT32_C(   -62.13), SIMDE_FLOAT32_C(  -121.78),
      SIMDE_FLOAT32_C(  -927.43), SIMDE_FLOAT32_C(   468.76), SIMDE_FLOAT32_C(  -305.12), SIMDE_FLOAT32_C(  -256.40),
      SIMDE_FLOAT32_C(  -874.19), SIMDE_FLOAT32_C(   303.32), SIMDE_FLOAT32_C(  1150.19), SIMDE_FLOAT32_C(   835.70),
      SIMDE_FLOAT32_C(  1812.68), SIMDE_FLOAT32_C(   841.88), SIMDE_FLOAT32_C(   855.39), SIMDE_FLOAT32_C(  -209.86),
      SIMDE_FLOAT32_C(   297.31), SIMDE_FLOAT32_C(   762.35), SIMDE_FLOAT32_C(  1235.74), SIMDE_FLOAT32_C( -1894.51),
      SIMDE_FLOAT32_C(   160.69), SIMDE_FLOAT32_C(    27.40), SIMDE_FLOAT32_C(   812.98), SIMDE_FLOAT32_C(   894.46),
      SIMDE_FLOAT32_C(  -625.35), SIMDE_FLOAT32_C( -1251.81), SIMDE_FLOAT32_C(  -576.68), SIMDE_FLOAT32_C(  -696.79),
      SIMDE_FLOAT32_C(   882.08) };

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
    rv = simde_svsub_f32_m(pv, av, bv);

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

    ev = simde_svsub_f32_m(pv, av, bv);

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
test_simde_svsub_f64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0) };
  static const simde_float64 a[] =
    { SIMDE_FLOAT64_C(  -389.98), SIMDE_FLOAT64_C(  -184.51), SIMDE_FLOAT64_C(  -786.15), SIMDE_FLOAT64_C(  -195.96),
      SIMDE_FLOAT64_C(  -376.55), SIMDE_FLOAT64_C(    -1.15), SIMDE_FLOAT64_C(  -613.20), SIMDE_FLOAT64_C(   -86.50),
      SIMDE_FLOAT64_C(   758.81), SIMDE_FLOAT64_C(  -944.59), SIMDE_FLOAT64_C(   247.75), SIMDE_FLOAT64_C(   386.22),
      SIMDE_FLOAT64_C(   817.79), SIMDE_FLOAT64_C(   218.54), SIMDE_FLOAT64_C(   -13.15), SIMDE_FLOAT64_C(  -166.74),
      SIMDE_FLOAT64_C(  -424.41), SIMDE_FLOAT64_C(  -647.24), SIMDE_FLOAT64_C(   613.87), SIMDE_FLOAT64_C(  -139.60),
      SIMDE_FLOAT64_C(  -768.25), SIMDE_FLOAT64_C(   -56.99), SIMDE_FLOAT64_C(  -278.69), SIMDE_FLOAT64_C(   -37.64),
      SIMDE_FLOAT64_C(    34.88), SIMDE_FLOAT64_C(   987.49), SIMDE_FLOAT64_C(   424.25), SIMDE_FLOAT64_C(   181.19),
      SIMDE_FLOAT64_C(   450.26), SIMDE_FLOAT64_C(    66.67), SIMDE_FLOAT64_C(   603.04), SIMDE_FLOAT64_C(  -939.71),
      SIMDE_FLOAT64_C(   882.15), SIMDE_FLOAT64_C(   816.89), SIMDE_FLOAT64_C(  -135.67), SIMDE_FLOAT64_C(  -494.40),
      SIMDE_FLOAT64_C(  -184.26), SIMDE_FLOAT64_C(   251.13), SIMDE_FLOAT64_C(   419.10), SIMDE_FLOAT64_C(  -425.45),
      SIMDE_FLOAT64_C(   306.54), SIMDE_FLOAT64_C(  -333.15), SIMDE_FLOAT64_C(   960.76), SIMDE_FLOAT64_C(   124.33),
      SIMDE_FLOAT64_C(   885.38), SIMDE_FLOAT64_C(   -52.39), SIMDE_FLOAT64_C(   957.59), SIMDE_FLOAT64_C(  -539.03),
      SIMDE_FLOAT64_C(   300.38), SIMDE_FLOAT64_C(   571.47), SIMDE_FLOAT64_C(   321.36), SIMDE_FLOAT64_C(   532.13),
      SIMDE_FLOAT64_C(  -485.52), SIMDE_FLOAT64_C(  -957.33), SIMDE_FLOAT64_C(  -505.51), SIMDE_FLOAT64_C(   549.36),
      SIMDE_FLOAT64_C(  -969.83), SIMDE_FLOAT64_C(   918.74), SIMDE_FLOAT64_C(  -269.45), SIMDE_FLOAT64_C(   480.43),
      SIMDE_FLOAT64_C(   -14.59), SIMDE_FLOAT64_C(  -666.41), SIMDE_FLOAT64_C(   540.72), SIMDE_FLOAT64_C(  -132.44),
      SIMDE_FLOAT64_C(  -849.52), SIMDE_FLOAT64_C(  -594.95), SIMDE_FLOAT64_C(   373.16), SIMDE_FLOAT64_C(   -33.78),
      SIMDE_FLOAT64_C(   656.18), SIMDE_FLOAT64_C(  -207.74), SIMDE_FLOAT64_C(   540.77), SIMDE_FLOAT64_C(   -37.29),
      SIMDE_FLOAT64_C(   459.11), SIMDE_FLOAT64_C(   501.53), SIMDE_FLOAT64_C(  -912.95), SIMDE_FLOAT64_C(   344.49),
      SIMDE_FLOAT64_C(  -550.85), SIMDE_FLOAT64_C(  -955.36), SIMDE_FLOAT64_C(   805.46), SIMDE_FLOAT64_C(   749.52),
      SIMDE_FLOAT64_C(   616.10), SIMDE_FLOAT64_C(   126.82), SIMDE_FLOAT64_C(   281.65), SIMDE_FLOAT64_C(  -869.42),
      SIMDE_FLOAT64_C(   169.50), SIMDE_FLOAT64_C(   776.14) };
  static const simde_float64 b[] =
    { SIMDE_FLOAT64_C(   679.95), SIMDE_FLOAT64_C(   199.67), SIMDE_FLOAT64_C(   694.88), SIMDE_FLOAT64_C(  -589.50),
      SIMDE_FLOAT64_C(  -319.90), SIMDE_FLOAT64_C(  -319.71), SIMDE_FLOAT64_C(  -255.92), SIMDE_FLOAT64_C(  -779.18),
      SIMDE_FLOAT64_C(   547.84), SIMDE_FLOAT64_C(  -105.44), SIMDE_FLOAT64_C(  -374.13), SIMDE_FLOAT64_C(   -79.00),
      SIMDE_FLOAT64_C(   860.78), SIMDE_FLOAT64_C(  -717.95), SIMDE_FLOAT64_C(   713.26), SIMDE_FLOAT64_C(   401.55),
      SIMDE_FLOAT64_C(   244.76), SIMDE_FLOAT64_C(   172.37), SIMDE_FLOAT64_C(   -96.92), SIMDE_FLOAT64_C(   331.81),
      SIMDE_FLOAT64_C(  -483.14), SIMDE_FLOAT64_C(   352.23), SIMDE_FLOAT64_C(   376.44), SIMDE_FLOAT64_C(  -677.68),
      SIMDE_FLOAT64_C(   101.75), SIMDE_FLOAT64_C(    -7.45), SIMDE_FLOAT64_C(   449.14), SIMDE_FLOAT64_C(  -616.59),
      SIMDE_FLOAT64_C(   123.13), SIMDE_FLOAT64_C(  -381.36), SIMDE_FLOAT64_C(  -840.45), SIMDE_FLOAT64_C(  -196.92),
      SIMDE_FLOAT64_C(   818.31), SIMDE_FLOAT64_C(   854.43), SIMDE_FLOAT64_C(   213.57), SIMDE_FLOAT64_C(  -501.59),
      SIMDE_FLOAT64_C(  -465.29), SIMDE_FLOAT64_C(   957.66), SIMDE_FLOAT64_C(  -280.77), SIMDE_FLOAT64_C(  -917.44),
      SIMDE_FLOAT64_C(  -147.78), SIMDE_FLOAT64_C(   345.10), SIMDE_FLOAT64_C(     3.56), SIMDE_FLOAT64_C(  -287.00),
      SIMDE_FLOAT64_C(   627.15), SIMDE_FLOAT64_C(  -283.18), SIMDE_FLOAT64_C(  -885.45), SIMDE_FLOAT64_C(  -128.09),
      SIMDE_FLOAT64_C(   889.19), SIMDE_FLOAT64_C(    17.63), SIMDE_FLOAT64_C(  -796.28), SIMDE_FLOAT64_C(  -593.95),
      SIMDE_FLOAT64_C(  -630.14), SIMDE_FLOAT64_C(   580.16), SIMDE_FLOAT64_C(  -271.63), SIMDE_FLOAT64_C(   471.61),
      SIMDE_FLOAT64_C(  -427.29), SIMDE_FLOAT64_C(  -822.49), SIMDE_FLOAT64_C(   855.02), SIMDE_FLOAT64_C(   695.84),
      SIMDE_FLOAT64_C(  -203.85), SIMDE_FLOAT64_C(  -985.44), SIMDE_FLOAT64_C(  -501.08), SIMDE_FLOAT64_C(  -385.54),
      SIMDE_FLOAT64_C(   868.99), SIMDE_FLOAT64_C(   712.49), SIMDE_FLOAT64_C(   112.87), SIMDE_FLOAT64_C(  -596.30),
      SIMDE_FLOAT64_C(   670.15), SIMDE_FLOAT64_C(   832.10), SIMDE_FLOAT64_C(  -513.74), SIMDE_FLOAT64_C(  -477.63),
      SIMDE_FLOAT64_C(   177.20), SIMDE_FLOAT64_C(   489.82), SIMDE_FLOAT64_C(   235.38), SIMDE_FLOAT64_C(  -195.65),
      SIMDE_FLOAT64_C(  -793.36), SIMDE_FLOAT64_C(   349.93), SIMDE_FLOAT64_C(   676.26), SIMDE_FLOAT64_C(  -904.17),
      SIMDE_FLOAT64_C(  -632.44), SIMDE_FLOAT64_C(   879.98), SIMDE_FLOAT64_C(  -498.12), SIMDE_FLOAT64_C(  -262.58),
      SIMDE_FLOAT64_C(   460.14), SIMDE_FLOAT64_C(   230.25) };
  static const simde_float64 e[] =
    { SIMDE_FLOAT64_C( -1069.93), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   393.54),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -357.28), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   210.97), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   465.22),
      SIMDE_FLOAT64_C(   -42.99), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -568.29),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   710.79), SIMDE_FLOAT64_C(  -471.41),
      SIMDE_FLOAT64_C(  -285.11), SIMDE_FLOAT64_C(  -409.22), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -24.89), SIMDE_FLOAT64_C(   797.78),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -742.79),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -349.24), SIMDE_FLOAT64_C(     7.19),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -706.53), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   411.33),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   230.79), SIMDE_FLOAT64_C(  1843.04), SIMDE_FLOAT64_C(  -410.94),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C( -1537.49), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    77.75),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1741.23), SIMDE_FLOAT64_C( -1124.47), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   319.03), SIMDE_FLOAT64_C(  1041.80), SIMDE_FLOAT64_C(   253.10),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C( -1307.44), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   562.52),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    11.71), SIMDE_FLOAT64_C( -1148.33), SIMDE_FLOAT64_C(   540.14),
      SIMDE_FLOAT64_C(   242.51), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   129.20), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  1248.54), SIMDE_FLOAT64_C(  -753.16), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -606.84),
      SIMDE_FLOAT64_C(  -290.64), SIMDE_FLOAT64_C(     0.00) };

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
    rv = simde_svsub_f64_z(pv, av, bv);

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

    ev = simde_svsub_f64_z(pv, av, bv);

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

static int
test_simde_svsub_f64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1) };
  static const simde_float64 a[] =
    { SIMDE_FLOAT64_C(  -779.94), SIMDE_FLOAT64_C(   462.44), SIMDE_FLOAT64_C(   139.62), SIMDE_FLOAT64_C(  -526.64),
      SIMDE_FLOAT64_C(   384.18), SIMDE_FLOAT64_C(   867.85), SIMDE_FLOAT64_C(   463.25), SIMDE_FLOAT64_C(  -277.93),
      SIMDE_FLOAT64_C(  -212.61), SIMDE_FLOAT64_C(   644.01), SIMDE_FLOAT64_C(  -557.99), SIMDE_FLOAT64_C(  -206.36),
      SIMDE_FLOAT64_C(  -791.24), SIMDE_FLOAT64_C(  -173.59), SIMDE_FLOAT64_C(  -493.71), SIMDE_FLOAT64_C(    83.92),
      SIMDE_FLOAT64_C(  -828.81), SIMDE_FLOAT64_C(  -243.43), SIMDE_FLOAT64_C(  -602.53), SIMDE_FLOAT64_C(  -745.64),
      SIMDE_FLOAT64_C(   702.95), SIMDE_FLOAT64_C(     9.55), SIMDE_FLOAT64_C(  -140.40), SIMDE_FLOAT64_C(   417.96),
      SIMDE_FLOAT64_C(  -679.75), SIMDE_FLOAT64_C(   709.45), SIMDE_FLOAT64_C(   143.65), SIMDE_FLOAT64_C(  -479.17),
      SIMDE_FLOAT64_C(  -634.71), SIMDE_FLOAT64_C(  -845.76), SIMDE_FLOAT64_C(   246.89), SIMDE_FLOAT64_C(  -414.65),
      SIMDE_FLOAT64_C(   616.69), SIMDE_FLOAT64_C(  -613.49), SIMDE_FLOAT64_C(    58.71), SIMDE_FLOAT64_C(     0.87),
      SIMDE_FLOAT64_C(  -745.64), SIMDE_FLOAT64_C(  -478.04), SIMDE_FLOAT64_C(   722.94), SIMDE_FLOAT64_C(    41.75),
      SIMDE_FLOAT64_C(  -834.03), SIMDE_FLOAT64_C(  -835.05), SIMDE_FLOAT64_C(   835.39), SIMDE_FLOAT64_C(  -625.27),
      SIMDE_FLOAT64_C(    -8.64), SIMDE_FLOAT64_C(  -658.32), SIMDE_FLOAT64_C(   458.65), SIMDE_FLOAT64_C(   162.55),
      SIMDE_FLOAT64_C(    98.25), SIMDE_FLOAT64_C(   856.12), SIMDE_FLOAT64_C(   416.91), SIMDE_FLOAT64_C(  -198.80),
      SIMDE_FLOAT64_C(  -134.33), SIMDE_FLOAT64_C(  -723.48), SIMDE_FLOAT64_C(  -780.84), SIMDE_FLOAT64_C(   185.91),
      SIMDE_FLOAT64_C(   985.97), SIMDE_FLOAT64_C(   362.81), SIMDE_FLOAT64_C(   706.74), SIMDE_FLOAT64_C(  -648.74),
      SIMDE_FLOAT64_C(   517.05), SIMDE_FLOAT64_C(   -46.37), SIMDE_FLOAT64_C(   -63.39), SIMDE_FLOAT64_C(   133.74),
      SIMDE_FLOAT64_C(   340.14), SIMDE_FLOAT64_C(   995.33), SIMDE_FLOAT64_C(  -865.39), SIMDE_FLOAT64_C(   594.49),
      SIMDE_FLOAT64_C(  -482.71), SIMDE_FLOAT64_C(   857.55), SIMDE_FLOAT64_C(  -363.76), SIMDE_FLOAT64_C(  -316.74),
      SIMDE_FLOAT64_C(  -977.51), SIMDE_FLOAT64_C(  -528.37), SIMDE_FLOAT64_C(    57.99), SIMDE_FLOAT64_C(    13.86),
      SIMDE_FLOAT64_C(  -186.69), SIMDE_FLOAT64_C(  -483.35), SIMDE_FLOAT64_C(  -823.59), SIMDE_FLOAT64_C(   911.56),
      SIMDE_FLOAT64_C(  -627.24), SIMDE_FLOAT64_C(   593.33), SIMDE_FLOAT64_C(  -287.24), SIMDE_FLOAT64_C(   238.43),
      SIMDE_FLOAT64_C(   869.84) };
  static const simde_float64 b[] =
    { SIMDE_FLOAT64_C(   -68.08), SIMDE_FLOAT64_C(  -575.65), SIMDE_FLOAT64_C(   855.81), SIMDE_FLOAT64_C(  -705.27),
      SIMDE_FLOAT64_C(  -868.91), SIMDE_FLOAT64_C(  -792.93), SIMDE_FLOAT64_C(   811.78), SIMDE_FLOAT64_C(    84.72),
      SIMDE_FLOAT64_C(   143.68), SIMDE_FLOAT64_C(   -54.49), SIMDE_FLOAT64_C(  -575.15), SIMDE_FLOAT64_C(   139.01),
      SIMDE_FLOAT64_C(    80.12), SIMDE_FLOAT64_C(  -980.66), SIMDE_FLOAT64_C(   656.30), SIMDE_FLOAT64_C(   -62.33),
      SIMDE_FLOAT64_C(  -344.42), SIMDE_FLOAT64_C(  -660.44), SIMDE_FLOAT64_C(   -39.84), SIMDE_FLOAT64_C(   127.21),
      SIMDE_FLOAT64_C(   397.56), SIMDE_FLOAT64_C(   974.02), SIMDE_FLOAT64_C(   940.52), SIMDE_FLOAT64_C(   914.20),
      SIMDE_FLOAT64_C(  -849.57), SIMDE_FLOAT64_C(   852.09), SIMDE_FLOAT64_C(  -713.04), SIMDE_FLOAT64_C(   743.76),
      SIMDE_FLOAT64_C(  -435.16), SIMDE_FLOAT64_C(   525.40), SIMDE_FLOAT64_C(   613.60), SIMDE_FLOAT64_C(   496.76),
      SIMDE_FLOAT64_C(   949.74), SIMDE_FLOAT64_C(   469.41), SIMDE_FLOAT64_C(   791.49), SIMDE_FLOAT64_C(  -919.17),
      SIMDE_FLOAT64_C(   676.48), SIMDE_FLOAT64_C(   603.26), SIMDE_FLOAT64_C(   165.55), SIMDE_FLOAT64_C(  -179.84),
      SIMDE_FLOAT64_C(  -451.22), SIMDE_FLOAT64_C(   590.40), SIMDE_FLOAT64_C(   959.17), SIMDE_FLOAT64_C(   628.90),
      SIMDE_FLOAT64_C(   609.74), SIMDE_FLOAT64_C(   615.47), SIMDE_FLOAT64_C(  -433.43), SIMDE_FLOAT64_C(  -734.68),
      SIMDE_FLOAT64_C(   955.04), SIMDE_FLOAT64_C(   526.74), SIMDE_FLOAT64_C(   392.54), SIMDE_FLOAT64_C(   352.59),
      SIMDE_FLOAT64_C(   500.76), SIMDE_FLOAT64_C(   333.06), SIMDE_FLOAT64_C(   266.79), SIMDE_FLOAT64_C(   651.19),
      SIMDE_FLOAT64_C(   185.15), SIMDE_FLOAT64_C(   553.76), SIMDE_FLOAT64_C(   394.95), SIMDE_FLOAT64_C(   749.99),
      SIMDE_FLOAT64_C(    79.15), SIMDE_FLOAT64_C(     8.55), SIMDE_FLOAT64_C(   246.75), SIMDE_FLOAT64_C(    28.89),
      SIMDE_FLOAT64_C(  -522.05), SIMDE_FLOAT64_C(    38.24), SIMDE_FLOAT64_C(   109.72), SIMDE_FLOAT64_C(  -845.57),
      SIMDE_FLOAT64_C(  -358.49), SIMDE_FLOAT64_C(  -724.73), SIMDE_FLOAT64_C(   -25.40), SIMDE_FLOAT64_C(   190.29),
      SIMDE_FLOAT64_C(   865.67), SIMDE_FLOAT64_C(   -66.23), SIMDE_FLOAT64_C(  -180.81), SIMDE_FLOAT64_C(   475.41),
      SIMDE_FLOAT64_C(  -450.76), SIMDE_FLOAT64_C(   385.76), SIMDE_FLOAT64_C(   740.73), SIMDE_FLOAT64_C(  -495.72),
      SIMDE_FLOAT64_C(   -87.50), SIMDE_FLOAT64_C(   133.26), SIMDE_FLOAT64_C(   856.87), SIMDE_FLOAT64_C(  -586.75),
      SIMDE_FLOAT64_C(  -533.68) };
  static const simde_float64 e[] =
    { SIMDE_FLOAT64_C(  -779.94), SIMDE_FLOAT64_C(   462.44), SIMDE_FLOAT64_C(  -716.19), SIMDE_FLOAT64_C(   178.63),
      SIMDE_FLOAT64_C(  1253.09), SIMDE_FLOAT64_C(   867.85), SIMDE_FLOAT64_C(  -348.53), SIMDE_FLOAT64_C(  -277.93),
      SIMDE_FLOAT64_C(  -356.29), SIMDE_FLOAT64_C(   698.50), SIMDE_FLOAT64_C(    17.16), SIMDE_FLOAT64_C(  -206.36),
      SIMDE_FLOAT64_C(  -791.24), SIMDE_FLOAT64_C(   807.07), SIMDE_FLOAT64_C(  -493.71), SIMDE_FLOAT64_C(   146.25),
      SIMDE_FLOAT64_C(  -484.39), SIMDE_FLOAT64_C(   417.01), SIMDE_FLOAT64_C(  -602.53), SIMDE_FLOAT64_C(  -872.85),
      SIMDE_FLOAT64_C(   305.39), SIMDE_FLOAT64_C(  -964.47), SIMDE_FLOAT64_C( -1080.92), SIMDE_FLOAT64_C(  -496.24),
      SIMDE_FLOAT64_C(  -679.75), SIMDE_FLOAT64_C(  -142.64), SIMDE_FLOAT64_C(   856.69), SIMDE_FLOAT64_C(  -479.17),
      SIMDE_FLOAT64_C(  -199.55), SIMDE_FLOAT64_C( -1371.16), SIMDE_FLOAT64_C(   246.89), SIMDE_FLOAT64_C(  -911.41),
      SIMDE_FLOAT64_C(   616.69), SIMDE_FLOAT64_C( -1082.90), SIMDE_FLOAT64_C(    58.71), SIMDE_FLOAT64_C(   920.04),
      SIMDE_FLOAT64_C(  -745.64), SIMDE_FLOAT64_C(  -478.04), SIMDE_FLOAT64_C(   722.94), SIMDE_FLOAT64_C(   221.59),
      SIMDE_FLOAT64_C(  -382.81), SIMDE_FLOAT64_C(  -835.05), SIMDE_FLOAT64_C(  -123.78), SIMDE_FLOAT64_C( -1254.17),
      SIMDE_FLOAT64_C(    -8.64), SIMDE_FLOAT64_C(  -658.32), SIMDE_FLOAT64_C(   892.08), SIMDE_FLOAT64_C(   897.23),
      SIMDE_FLOAT64_C(  -856.79), SIMDE_FLOAT64_C(   329.38), SIMDE_FLOAT64_C(   416.91), SIMDE_FLOAT64_C(  -198.80),
      SIMDE_FLOAT64_C(  -134.33), SIMDE_FLOAT64_C( -1056.54), SIMDE_FLOAT64_C(  -780.84), SIMDE_FLOAT64_C(  -465.28),
      SIMDE_FLOAT64_C(   800.82), SIMDE_FLOAT64_C(   362.81), SIMDE_FLOAT64_C(   706.74), SIMDE_FLOAT64_C(  -648.74),
      SIMDE_FLOAT64_C(   437.90), SIMDE_FLOAT64_C(   -46.37), SIMDE_FLOAT64_C(  -310.14), SIMDE_FLOAT64_C(   104.85),
      SIMDE_FLOAT64_C(   862.19), SIMDE_FLOAT64_C(   995.33), SIMDE_FLOAT64_C(  -975.11), SIMDE_FLOAT64_C(   594.49),
      SIMDE_FLOAT64_C(  -482.71), SIMDE_FLOAT64_C(   857.55), SIMDE_FLOAT64_C(  -363.76), SIMDE_FLOAT64_C(  -507.03),
      SIMDE_FLOAT64_C(  -977.51), SIMDE_FLOAT64_C(  -462.14), SIMDE_FLOAT64_C(    57.99), SIMDE_FLOAT64_C(  -461.55),
      SIMDE_FLOAT64_C(  -186.69), SIMDE_FLOAT64_C(  -483.35), SIMDE_FLOAT64_C(  -823.59), SIMDE_FLOAT64_C(   911.56),
      SIMDE_FLOAT64_C(  -627.24), SIMDE_FLOAT64_C(   593.33), SIMDE_FLOAT64_C( -1144.11), SIMDE_FLOAT64_C(   238.43),
      SIMDE_FLOAT64_C(  1403.52) };

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
    rv = simde_svsub_f64_m(pv, av, bv);

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

    ev = simde_svsub_f64_m(pv, av, bv);

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

static int
test_simde_svsub_n_s8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1) };
  static const int8_t a[] =
    {  INT8_C(  26),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  62), -INT8_C( 123), -INT8_C(  64),
      -INT8_C( 102), -INT8_C( 103), -INT8_C( 103), -INT8_C( 103), -INT8_C( 103),  INT8_C(  43), -INT8_C( 122),  INT8_C(  64),
      -INT8_C(  51), -INT8_C(  52), -INT8_C(  52), -INT8_C(  52), -INT8_C(  52), -INT8_C(  12),  INT8_C(  97),  INT8_C(  64),
       INT8_C(  31), -INT8_C( 123), -INT8_C(  21),  INT8_C(  81), -INT8_C(  72), -INT8_C(  14),  INT8_C( 125), -INT8_C(  64),
       INT8_C(  72), -INT8_C(  31),  INT8_C( 122),  INT8_C(  20), -INT8_C(  82), -INT8_C(  43), -INT8_C( 125), -INT8_C(  64),
      -INT8_C(  82),  INT8_C(  71), -INT8_C(  31),  INT8_C( 122),  INT8_C(  20),  INT8_C( 110), -INT8_C( 118), -INT8_C(  64),
       INT8_C(  20), -INT8_C(  82),  INT8_C(  71), -INT8_C(  31),  INT8_C( 122), -INT8_C(  36),  INT8_C( 110),  INT8_C(  64),
       INT8_C( 102),  INT8_C( 102),  INT8_C( 102),  INT8_C( 102),  INT8_C( 102), -INT8_C(  22),  INT8_C( 121), -INT8_C(  64),
      -INT8_C(  20),  INT8_C(  81), -INT8_C(  72),  INT8_C(  30), -INT8_C( 123),  INT8_C(  69), -INT8_C( 125),  INT8_C(  64),
       INT8_C(  82), -INT8_C(  72),  INT8_C(  30), -INT8_C( 123), -INT8_C(  21),  INT8_C(  43), -INT8_C( 125), -INT8_C(  64),
       INT8_C( 123),  INT8_C(  20), -INT8_C(  82),  INT8_C(  71), -INT8_C(  31),  INT8_C(  90),  INT8_C(  77),  INT8_C(  64),
      -INT8_C(  41), -INT8_C(  93),  INT8_C( 112),  INT8_C(  61),  INT8_C(  10), -INT8_C(  41), -INT8_C(  21),  INT8_C(  63),
      -INT8_C( 123), -INT8_C(  21),  INT8_C(  81), -INT8_C(  72),  INT8_C(  30),  INT8_C(  77), -INT8_C( 121), -INT8_C(  64),
       INT8_C( 113),  INT8_C(  61),  INT8_C(  10), -INT8_C(  41), -INT8_C(  93), -INT8_C(  32),  INT8_C( 125), -INT8_C(  64),
      -INT8_C(  20),  INT8_C(  81), -INT8_C(  72),  INT8_C(  30), -INT8_C( 123), -INT8_C( 105), -INT8_C( 122),  INT8_C(  64),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  32),  INT8_C(  68),  INT8_C(  64),
       INT8_C(  10), -INT8_C(  41), -INT8_C(  93),  INT8_C( 112),  INT8_C(  61),  INT8_C(  16), -INT8_C( 118), -INT8_C(  64),
       INT8_C( 102),  INT8_C( 102),  INT8_C( 102),  INT8_C( 102),  INT8_C( 102),  INT8_C(  24), -INT8_C( 118), -INT8_C(  64),
      -INT8_C( 123), -INT8_C(  21),  INT8_C(  81), -INT8_C(  72),  INT8_C(  30),  INT8_C(  27), -INT8_C( 118),  INT8_C(  64),
       INT8_C(  92), -INT8_C( 113), -INT8_C(  62), -INT8_C(  11),  INT8_C(  40), -INT8_C( 118), -INT8_C( 125), -INT8_C(  64),
       INT8_C(  72), -INT8_C(  31),  INT8_C( 122),  INT8_C(  20), -INT8_C(  82),  INT8_C(  71),  INT8_C(  33), -INT8_C(  64),
      -INT8_C(  61), -INT8_C(  11),  INT8_C(  40),  INT8_C(  92), -INT8_C( 113), -INT8_C( 110), -INT8_C( 124), -INT8_C(  64),
       INT8_C( 102),  INT8_C( 102),  INT8_C( 102),  INT8_C( 102),  INT8_C( 102), -INT8_C(  86),  INT8_C( 124),  INT8_C(  64),
      -INT8_C( 102), -INT8_C( 103), -INT8_C( 103), -INT8_C( 103), -INT8_C( 103),  INT8_C(  81),  INT8_C( 100),  INT8_C(  64),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 112),  INT8_C(  88),  INT8_C(  64),
       INT8_C(  41),  INT8_C(  92), -INT8_C( 113), -INT8_C(  62), -INT8_C(  11), -INT8_C(  64), -INT8_C( 118),  INT8_C(  64),
      -INT8_C(  61), -INT8_C(  11),  INT8_C(  40),  INT8_C(  92), -INT8_C( 113),  INT8_C(  14),  INT8_C( 122),  INT8_C(  64),
      -INT8_C( 102), -INT8_C( 103), -INT8_C( 103), -INT8_C( 103), -INT8_C( 103), -INT8_C(  39),  INT8_C( 104), -INT8_C(  64),
      -INT8_C(  61), -INT8_C(  11),  INT8_C(  40),  INT8_C(  92), -INT8_C( 113), -INT8_C(  54),  INT8_C(  96), -INT8_C(  64),
      -INT8_C(  92),  INT8_C( 112),  INT8_C(  61),  INT8_C(  10), -INT8_C(  41), -INT8_C( 101), -INT8_C( 122), -INT8_C(  64),
       INT8_C(  31), -INT8_C( 123), -INT8_C(  21),  INT8_C(  81), -INT8_C(  72),  INT8_C( 102), -INT8_C( 120), -INT8_C(  64),
      -INT8_C( 123), -INT8_C(  21),  INT8_C(  81), -INT8_C(  72),  INT8_C(  30),  INT8_C(  61),  INT8_C( 103),  INT8_C(  64),
      -INT8_C(  10),  INT8_C(  40),  INT8_C(  92), -INT8_C( 113), -INT8_C(  62), -INT8_C(  49), -INT8_C( 114),  INT8_C(  64),
       INT8_C(  41),  INT8_C(  92), -INT8_C( 113), -INT8_C(  62), -INT8_C(  11), -INT8_C(  84),  INT8_C( 118),  INT8_C(  64),
       INT8_C(  82), -INT8_C(  72),  INT8_C(  30), -INT8_C( 123), -INT8_C(  21),  INT8_C(  21), -INT8_C( 122),  INT8_C(  64),
       INT8_C(  82), -INT8_C(  72),  INT8_C(  30), -INT8_C( 123), -INT8_C(  21),  INT8_C(  69), -INT8_C( 124), -INT8_C(  64),
       INT8_C( 102),  INT8_C( 102),  INT8_C( 102),  INT8_C( 102),  INT8_C( 102),  INT8_C(  40),      INT8_MIN,  INT8_C(  64),
      -INT8_C( 113), -INT8_C(  62), -INT8_C(  11),  INT8_C(  40),  INT8_C(  92),  INT8_C(  47),  INT8_C(  71), -INT8_C(  64),
       INT8_C(  82), -INT8_C(  72),  INT8_C(  30), -INT8_C( 123), -INT8_C(  21), -INT8_C(  79),  INT8_C(  79), -INT8_C(  64),
       INT8_C(  72), -INT8_C(  31),  INT8_C( 122),  INT8_C(  20), -INT8_C(  82), -INT8_C(  73),  INT8_C(  96),  INT8_C(  64),
       INT8_C(  10), -INT8_C(  41), -INT8_C(  93),  INT8_C( 112),  INT8_C(  61),  INT8_C(  66),  INT8_C( 117),  INT8_C(  64),
       INT8_C( 113),  INT8_C(  61),  INT8_C(  10), -INT8_C(  41), -INT8_C(  93),  INT8_C(  26), -INT8_C( 113),  INT8_C(  64),
      -INT8_C( 123), -INT8_C(  21),  INT8_C(  81), -INT8_C(  72),  INT8_C(  30),  INT8_C(  11), -INT8_C( 117), -INT8_C(  64),
       INT8_C(  82), -INT8_C(  72),  INT8_C(  30), -INT8_C( 123), -INT8_C(  21), -INT8_C( 109), -INT8_C( 126),  INT8_C(  64),
      -INT8_C( 113), -INT8_C(  62), -INT8_C(  11),  INT8_C(  40),  INT8_C(  92),  INT8_C(  43),  INT8_C( 126), -INT8_C(  64),
       INT8_C( 102),  INT8_C( 102),  INT8_C( 102),  INT8_C( 102),  INT8_C( 102), -INT8_C(  52), -INT8_C( 118),  INT8_C(  64),
       INT8_C(  92), -INT8_C( 113), -INT8_C(  62), -INT8_C(  11),  INT8_C(  40), -INT8_C(  68),  INT8_C( 118), -INT8_C(  64),
      -INT8_C(  92),  INT8_C( 112),  INT8_C(  61),  INT8_C(  10), -INT8_C(  41), -INT8_C(  53),  INT8_C( 115), -INT8_C(  64),
      -INT8_C(  82),  INT8_C(  71), -INT8_C(  31),  INT8_C( 122),  INT8_C(  20), -INT8_C( 116), -INT8_C( 114), -INT8_C(  64),
       INT8_C(  41),  INT8_C(  92), -INT8_C( 113), -INT8_C(  62), -INT8_C(  11), -INT8_C( 126),      INT8_MIN, -INT8_C(  64),
       INT8_C(  31), -INT8_C( 123), -INT8_C(  21),  INT8_C(  81), -INT8_C(  72), -INT8_C(   2),  INT8_C(  76),  INT8_C(  64),
      -INT8_C(  72),  INT8_C(  30), -INT8_C( 123), -INT8_C(  21),  INT8_C(  81), -INT8_C(  72),  INT8_C(  43),  INT8_C(  64),
      -INT8_C(  82),  INT8_C(  71), -INT8_C(  31),  INT8_C( 122),  INT8_C(  20),  INT8_C(  86),  INT8_C( 103), -INT8_C(  64),
      -INT8_C( 102), -INT8_C( 103), -INT8_C( 103), -INT8_C( 103), -INT8_C( 103),  INT8_C(  53),  INT8_C( 126), -INT8_C(  64),
       INT8_C(  31), -INT8_C( 123), -INT8_C(  21),  INT8_C(  81), -INT8_C(  72), -INT8_C(  68), -INT8_C( 119), -INT8_C(  64),
       INT8_C(  20), -INT8_C(  82),  INT8_C(  71), -INT8_C(  31),  INT8_C( 122),  INT8_C( 124), -INT8_C( 116),  INT8_C(  64),
       INT8_C(  82), -INT8_C(  72),  INT8_C(  30), -INT8_C( 123), -INT8_C(  21), -INT8_C( 103), -INT8_C( 125), -INT8_C(  64),
       INT8_C( 113),  INT8_C(  61),  INT8_C(  10), -INT8_C(  41), -INT8_C(  93), -INT8_C( 118), -INT8_C( 126),  INT8_C(  64),
      -INT8_C(  92),  INT8_C( 112),  INT8_C(  61),  INT8_C(  10), -INT8_C(  41), -INT8_C(  13),  INT8_C( 113), -INT8_C(  64),
      -INT8_C(  10),  INT8_C(  40),  INT8_C(  92), -INT8_C( 113), -INT8_C(  62), -INT8_C(  51),  INT8_C( 109),  INT8_C(  64),
       INT8_C(  31), -INT8_C( 123), -INT8_C(  21),  INT8_C(  81), -INT8_C(  72),  INT8_C(  46), -INT8_C( 117),  INT8_C(  64),
      -INT8_C( 123), -INT8_C(  21),  INT8_C(  81), -INT8_C(  72),  INT8_C(  30),  INT8_C(  65), -INT8_C( 120),  INT8_C(  64),
      -INT8_C(  72), -INT8_C(  34),  INT8_C(  47), -INT8_C(  60),  INT8_C(   0),  INT8_C(   0),  INT8_C(  16), -INT8_C(  64),
      -INT8_C( 113), -INT8_C(  62),  INT8_C(  34), -INT8_C(  60),  INT8_C(  51),  INT8_C(  19),  INT8_C(  79),  INT8_C(  68),
       INT8_C(  41),  INT8_C(  92),  INT8_C(  77),  INT8_C(  66),  INT8_C(  51),  INT8_C(  51),  INT8_C(  71),  INT8_C(  68),
      -INT8_C( 123), -INT8_C(   5),  INT8_C(  98), -INT8_C(  60),  INT8_C(  92), -INT8_C(  65),  INT8_C(  16), -INT8_C(  60),
       INT8_C(  72),  INT8_C( 113),  INT8_C(  24), -INT8_C(  60), -INT8_C( 113), -INT8_C(  14),  INT8_C(  84),  INT8_C(  68),
       INT8_C( 123),  INT8_C(   4),  INT8_C(  37),  INT8_C(  68), -INT8_C(  41), -INT8_C(  93),  INT8_C(  63), -INT8_C(  61),
       INT8_C( 102),  INT8_C( 102), -INT8_C(  71), -INT8_C(  62), -INT8_C(  61), -INT8_C(  43), -INT8_C(  43), -INT8_C(  61),
      -INT8_C( 113), -INT8_C(  62), -INT8_C(  35), -INT8_C(  61),  INT8_C(  82), -INT8_C(  72),  INT8_C(  87),  INT8_C(  66),
      -INT8_C(  51),  INT8_C(  12),  INT8_C(  44),  INT8_C(  67),  INT8_C(  82),  INT8_C(  72),  INT8_C(  77), -INT8_C(  60),
       INT8_C(  20), -INT8_C( 114), -INT8_C(  22), -INT8_C(  61), -INT8_C( 113),  INT8_C(  98), -INT8_C(  19), -INT8_C(  61),
       INT8_C(  41),  INT8_C( 124), -INT8_C(  92), -INT8_C(  61), -INT8_C( 102),  INT8_C( 121), -INT8_C(  85), -INT8_C(  61),
      -INT8_C( 123),  INT8_C(  75), -INT8_C(  95),  INT8_C(  67),  INT8_C(  51),  INT8_C( 115), -INT8_C(  47), -INT8_C(  61),
       INT8_C(  82),  INT8_C( 120),  INT8_C(  49),  INT8_C(  68),  INT8_C(  10), -INT8_C(  89),  INT8_C(  15), -INT8_C(  60),
      -INT8_C(  41),  INT8_C( 115),  INT8_C(  62), -INT8_C(  60), -INT8_C( 123),  INT8_C(  91),  INT8_C(  18),  INT8_C(  68),
       INT8_C( 123),  INT8_C(  20), -INT8_C(  72), -INT8_C(  62),  INT8_C(  61), -INT8_C( 102),  INT8_C(  55),  INT8_C(  68),
      -INT8_C(  82),  INT8_C(  55),  INT8_C( 120),  INT8_C(  68), -INT8_C(  31),  INT8_C( 122),  INT8_C(  76),  INT8_C(  67),
       INT8_C(  61), -INT8_C(  22), -INT8_C( 123), -INT8_C(  61), -INT8_C(  31), -INT8_C( 118),  INT8_C(  36), -INT8_C(  60),
      -INT8_C(  72),  INT8_C(  30),  INT8_C(   3),  INT8_C(  66),  INT8_C(   0), -INT8_C(  32),  INT8_C(  67),  INT8_C(  68),
      -INT8_C(  82),  INT8_C(  87),  INT8_C(  87), -INT8_C(  60),  INT8_C(  51), -INT8_C(  77), -INT8_C(   7),  INT8_C(  66),
      -INT8_C(  72), -INT8_C(  34),  INT8_C(  70), -INT8_C(  60), -INT8_C(  20), -INT8_C( 111), -INT8_C(  21), -INT8_C(  61),
       INT8_C(  72), -INT8_C(  31), -INT8_C(  70), -INT8_C(  63),  INT8_C(  31),  INT8_C(  37),  INT8_C(  88),  INT8_C(  68),
       INT8_C(  41), -INT8_C( 100), -INT8_C(  88),  INT8_C(  67),  INT8_C(  41), -INT8_C(   4),  INT8_C(  92),  INT8_C(  68),
      -INT8_C(  61), -INT8_C(  59),  INT8_C(  12), -INT8_C(  60), -INT8_C(  51),  INT8_C( 108),  INT8_C(  95),  INT8_C(  68),
       INT8_C(  31), -INT8_C( 123),  INT8_C( 120), -INT8_C(  62),  INT8_C(  20),  INT8_C(  62),  INT8_C(  24),  INT8_C(  68),
      -INT8_C( 123), -INT8_C(  37),  INT8_C( 103), -INT8_C(  60),  INT8_C(  72),  INT8_C(  97), -INT8_C(  22),  INT8_C(  67),
       INT8_C(  51),  INT8_C( 115),  INT8_C(  88), -INT8_C(  60),  INT8_C(  51),  INT8_C(  51),      INT8_MIN, -INT8_C(  61),
       INT8_C(  41), -INT8_C( 116),  INT8_C(  90), -INT8_C(  60),  INT8_C(  31),  INT8_C( 101), -INT8_C(  28),  INT8_C(  67),
      -INT8_C(  31),  INT8_C(  90), -INT8_C(  94),  INT8_C(  67), -INT8_C(  51), -INT8_C(  20),  INT8_C(  80),  INT8_C(  68),
       INT8_C(  41), -INT8_C( 116),  INT8_C(  92),  INT8_C(  68), -INT8_C( 102), -INT8_C(  71),  INT8_C(  12),  INT8_C(  68),
      -INT8_C(  92), -INT8_C( 112), -INT8_C(  46),  INT8_C(  67),  INT8_C(  41), -INT8_C(  36),  INT8_C(  81), -INT8_C(  61),
      -INT8_C(  82), -INT8_C(  89), -INT8_C( 108),  INT8_C(  67),  INT8_C(   0),  INT8_C(   0), -INT8_C(  49),  INT8_C(  67),
      -INT8_C(  82), -INT8_C(  89),  INT8_C( 120),  INT8_C(  68),  INT8_C(  72), -INT8_C(  95),  INT8_C( 114), -INT8_C(  60),
       INT8_C(  31), -INT8_C(  11),  INT8_C(  60),  INT8_C(  68),  INT8_C(  51),  INT8_C(  51), -INT8_C(  37),  INT8_C(  65),
      -INT8_C(  72),  INT8_C(  62) };
  static const int8_t b = -INT8_C(  44);
  static const int8_t e[] =
    {  INT8_C(  70),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 106),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  58), -INT8_C(  59),  INT8_C(   0),  INT8_C(   0), -INT8_C(  59),  INT8_C(   0), -INT8_C(  78),  INT8_C( 108),
      -INT8_C(   7),  INT8_C(   0), -INT8_C(   8), -INT8_C(   8), -INT8_C(   8),  INT8_C(   0), -INT8_C( 115),  INT8_C( 108),
       INT8_C(  75), -INT8_C(  79),  INT8_C(  23),  INT8_C( 125), -INT8_C(  28),  INT8_C(   0), -INT8_C(  87), -INT8_C(  20),
       INT8_C(   0),  INT8_C(  13), -INT8_C(  90),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  20),
      -INT8_C(  38),  INT8_C( 115),  INT8_C(   0),  INT8_C(   0),  INT8_C(  64), -INT8_C( 102),  INT8_C(   0), -INT8_C(  20),
       INT8_C(  64), -INT8_C(  38),  INT8_C(   0),  INT8_C(  13),  INT8_C(   0),  INT8_C(   8),  INT8_C(   0),  INT8_C( 108),
      -INT8_C( 110), -INT8_C( 110), -INT8_C( 110),  INT8_C(   0), -INT8_C( 110),  INT8_C(   0), -INT8_C(  91),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 113),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  79),  INT8_C(   0),  INT8_C(  87),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  64), -INT8_C(  38),  INT8_C(   0),  INT8_C(   0), -INT8_C( 122),  INT8_C(   0),  INT8_C( 108),
       INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C( 105),  INT8_C(   0),  INT8_C(   0),  INT8_C(  23),  INT8_C(   0),
      -INT8_C(  79),  INT8_C(   0),  INT8_C( 125), -INT8_C(  28),  INT8_C(  74),  INT8_C( 121),  INT8_C(   0), -INT8_C(  20),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  54),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  24),  INT8_C(   0), -INT8_C(  28),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 108),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  44),  INT8_C(   0),  INT8_C(  44),  INT8_C(   0),  INT8_C( 112),  INT8_C(   0),
       INT8_C(  54),  INT8_C(   0),  INT8_C(   0), -INT8_C( 100),  INT8_C(   0),  INT8_C(   0), -INT8_C(  74),  INT8_C(   0),
      -INT8_C( 110),  INT8_C(   0), -INT8_C( 110), -INT8_C( 110), -INT8_C( 110),  INT8_C(   0), -INT8_C(  74), -INT8_C(  20),
       INT8_C(   0),  INT8_C(  23),  INT8_C( 125),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  69), -INT8_C(  18),  INT8_C(   0),  INT8_C(   0), -INT8_C(  74),  INT8_C(   0), -INT8_C(  20),
       INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 115),  INT8_C(   0), -INT8_C(  20),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 120),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  20),
       INT8_C(   0),  INT8_C(   0), -INT8_C( 110),  INT8_C(   0),  INT8_C(   0), -INT8_C(  42), -INT8_C(  88),  INT8_C( 108),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  59),  INT8_C(   0), -INT8_C(  59),  INT8_C( 125),  INT8_C(   0),  INT8_C( 108),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  44),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  85), -INT8_C( 120),  INT8_C(   0), -INT8_C(  18),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  17),  INT8_C(   0),  INT8_C(  84), -INT8_C( 120), -INT8_C(  69),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  58), -INT8_C(  59), -INT8_C(  59), -INT8_C(  59), -INT8_C(  59),  INT8_C(   5), -INT8_C( 108), -INT8_C(  20),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  69), -INT8_C(  10), -INT8_C( 116),  INT8_C(   0),
      -INT8_C(  48), -INT8_C( 100),  INT8_C(   0),  INT8_C(  54),  INT8_C(   0), -INT8_C(  57),  INT8_C(   0), -INT8_C(  20),
       INT8_C(  75), -INT8_C(  79),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  76), -INT8_C(  20),
       INT8_C(   0),  INT8_C(   0),  INT8_C( 125),  INT8_C(   0),  INT8_C(  74),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  34),  INT8_C(  84),  INT8_C(   0), -INT8_C(  69),  INT8_C(   0), -INT8_C(   5), -INT8_C(  70),  INT8_C( 108),
       INT8_C(  85),  INT8_C(   0), -INT8_C(  69), -INT8_C(  18),  INT8_C(  33), -INT8_C(  40),  INT8_C(   0),  INT8_C(   0),
       INT8_C( 126),  INT8_C(   0),  INT8_C(  74), -INT8_C(  79),  INT8_C(  23),  INT8_C(   0), -INT8_C(  78),  INT8_C(   0),
       INT8_C( 126),  INT8_C(   0),  INT8_C(   0), -INT8_C(  79),  INT8_C(  23),  INT8_C( 113), -INT8_C(  80), -INT8_C(  20),
       INT8_C(   0), -INT8_C( 110),  INT8_C(   0),  INT8_C(   0), -INT8_C( 110),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  18),  INT8_C(   0),  INT8_C(  84), -INT8_C( 120),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C( 126), -INT8_C(  28),  INT8_C(  74), -INT8_C(  79),  INT8_C(   0),  INT8_C(   0),  INT8_C( 123), -INT8_C(  20),
       INT8_C( 116),  INT8_C(   0), -INT8_C(  90),  INT8_C(  64), -INT8_C(  38),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C( 110),  INT8_C(   0),  INT8_C( 108),
      -INT8_C(  99),  INT8_C( 105),  INT8_C(   0),  INT8_C(   0), -INT8_C(  49),  INT8_C(  70),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  23),  INT8_C(   0), -INT8_C(  28),  INT8_C(   0),  INT8_C(  55),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  28),  INT8_C(  74),  INT8_C(   0),  INT8_C(   0), -INT8_C(  65),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  18),  INT8_C(   0),  INT8_C(  84), -INT8_C( 120),  INT8_C(  87),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 110),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  74),  INT8_C( 108),
       INT8_C(   0), -INT8_C(  69),  INT8_C(   0),  INT8_C(  33),  INT8_C(  84), -INT8_C(  24), -INT8_C(  94), -INT8_C(  20),
      -INT8_C(  48), -INT8_C( 100),  INT8_C( 105),  INT8_C(  54),  INT8_C(   0),  INT8_C(   0), -INT8_C(  97), -INT8_C(  20),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  90),  INT8_C(   0), -INT8_C(  72), -INT8_C(  70), -INT8_C(  20),
       INT8_C(   0), -INT8_C( 120), -INT8_C(  69), -INT8_C(  18),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 125), -INT8_C(  28),  INT8_C(  42),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  79),  INT8_C(  23),  INT8_C(   0), -INT8_C(  28),  INT8_C(  87),  INT8_C( 108),
       INT8_C(   0),  INT8_C( 115),  INT8_C(   0), -INT8_C(  90),  INT8_C(   0), -INT8_C( 126),  INT8_C(   0), -INT8_C(  20),
      -INT8_C(  58), -INT8_C(  59),  INT8_C(   0), -INT8_C(  59),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  23),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  75), -INT8_C(  20),
       INT8_C(   0), -INT8_C(  38),  INT8_C(   0),  INT8_C(  13),  INT8_C(   0), -INT8_C(  88),  INT8_C(   0),  INT8_C( 108),
       INT8_C( 126),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  59), -INT8_C(  81), -INT8_C(  20),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3), -INT8_C(  49),  INT8_C(   0), -INT8_C(  82),  INT8_C(   0),
      -INT8_C(  48), -INT8_C( 100),  INT8_C(   0),  INT8_C(  54),  INT8_C(   3),  INT8_C(  31),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  84),  INT8_C(   0), -INT8_C(  69),  INT8_C(   0),  INT8_C(   0), -INT8_C( 103),  INT8_C(   0),
       INT8_C(  75),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  28),  INT8_C(   0), -INT8_C(  73),  INT8_C( 108),
      -INT8_C(  79),  INT8_C(  23),  INT8_C( 125),  INT8_C(   0),  INT8_C(   0),  INT8_C( 109),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  28),  INT8_C(   0),  INT8_C(  91),  INT8_C(   0),  INT8_C(   0),  INT8_C(  44),  INT8_C(  60),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  18),  INT8_C(   0), -INT8_C(  16),  INT8_C(   0),  INT8_C(  63),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  95),  INT8_C(  95),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  79),  INT8_C(   0), -INT8_C( 114),  INT8_C(   0), -INT8_C( 120), -INT8_C(  21),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  99),  INT8_C(  68),  INT8_C(   0), -INT8_C(  69),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),
       INT8_C(   0),  INT8_C(  48),  INT8_C(  81),  INT8_C(   0),  INT8_C(   0), -INT8_C(  49),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 110),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   1),  INT8_C(   0),
      -INT8_C(  69),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  28), -INT8_C( 125),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 126),  INT8_C( 116),  INT8_C(   0), -INT8_C(  16),
       INT8_C(   0), -INT8_C(  70),  INT8_C(   0), -INT8_C(  17), -INT8_C(  69),  INT8_C(   0),  INT8_C(  25),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  48),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  41), -INT8_C(  17),
      -INT8_C(  79),  INT8_C(   0),  INT8_C(   0),  INT8_C( 111),  INT8_C(  95), -INT8_C(  97), -INT8_C(   3), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  92),  INT8_C(  93),  INT8_C( 112),  INT8_C(  54),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   3),  INT8_C(   0),  INT8_C( 106), -INT8_C(  16), -INT8_C(  79), -INT8_C( 121),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  64), -INT8_C(  28),  INT8_C(   0),  INT8_C( 105),  INT8_C(   0),  INT8_C(   0),  INT8_C( 112),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 112),  INT8_C(   0), -INT8_C(  90),  INT8_C( 120),  INT8_C( 111),
       INT8_C( 105),  INT8_C(  22),  INT8_C(   0), -INT8_C(  17),  INT8_C(  13), -INT8_C(  74),  INT8_C(  80), -INT8_C(  16),
       INT8_C(   0),  INT8_C(  74),  INT8_C(   0),  INT8_C(   0),  INT8_C(  44),  INT8_C(   0),  INT8_C(   0),  INT8_C( 112),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  37),  INT8_C(   0),
      -INT8_C(  28),  INT8_C(  10),  INT8_C(   0),  INT8_C(   0),  INT8_C(  24), -INT8_C(  67),  INT8_C(  23), -INT8_C(  17),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 124),  INT8_C( 112),
       INT8_C(  85), -INT8_C(  56), -INT8_C(  44),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 112),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  56), -INT8_C(  16), -INT8_C(   7),  INT8_C(   0), -INT8_C( 117),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  92),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  68),  INT8_C(   0),
      -INT8_C(  79),  INT8_C(   0),  INT8_C(   0), -INT8_C(  16),  INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C( 111),
       INT8_C(  95),  INT8_C(   0), -INT8_C( 124),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  84), -INT8_C(  17),
       INT8_C(  85), -INT8_C(  72),  INT8_C(   0),  INT8_C(   0),  INT8_C(  75),  INT8_C(   0),  INT8_C(  16),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 124),  INT8_C( 112),
       INT8_C(  85),  INT8_C(   0), -INT8_C( 120),  INT8_C(   0),  INT8_C(   0), -INT8_C(  27),  INT8_C(  56),  INT8_C(   0),
      -INT8_C(  48), -INT8_C(  68), -INT8_C(   2),  INT8_C(   0),  INT8_C(  85),  INT8_C(   8),  INT8_C( 125),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 111),
       INT8_C(   0), -INT8_C(  45),  INT8_C(   0),  INT8_C( 112),  INT8_C( 116),  INT8_C(   0), -INT8_C(  98),  INT8_C(   0),
       INT8_C(  75),  INT8_C(   0),  INT8_C( 104),  INT8_C( 112),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 109),
      -INT8_C(  28),  INT8_C( 106) };

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
    rv = simde_svsub_n_s8_z(pv, av, b);

    simde_svst1_s8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vi8(len, e, r);

  return 0;
#else
  int8_t p[1024], a[1024], b, e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(b), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_s8(pg, &(a[i]));

    ev = simde_svsub_n_s8_z(pv, av, b);

    simde_svst1_s8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i8(1, b);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_s8_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) };
  static const int8_t a[] =
    {  INT8_C(  59),  INT8_C(  67),  INT8_C(  98),  INT8_C( 102),  INT8_C(  23), -INT8_C(  78),  INT8_C( 100), -INT8_C(  35),
      -INT8_C(  58),  INT8_C(  24), -INT8_C(  71),  INT8_C(  24),  INT8_C(  35),  INT8_C(  62),  INT8_C(  78), -INT8_C(  59),
      -INT8_C( 127),  INT8_C( 103), -INT8_C(  90),  INT8_C(  70), -INT8_C(  80), -INT8_C(  67),  INT8_C(  43), -INT8_C(  18),
       INT8_C( 116),  INT8_C(  86), -INT8_C(  49),  INT8_C(  30),  INT8_C(  57), -INT8_C(  82), -INT8_C(  66),  INT8_C( 116),
      -INT8_C(  15),  INT8_C(  32), -INT8_C(  38),  INT8_C(   9), -INT8_C(  46),  INT8_C(  62), -INT8_C(  26), -INT8_C( 104),
       INT8_C(  86), -INT8_C(  97), -INT8_C(  79),  INT8_C( 122), -INT8_C(  35), -INT8_C(   1),  INT8_C(  63),  INT8_C(  94),
       INT8_C( 102), -INT8_C(  27), -INT8_C(  91),  INT8_C(  22), -INT8_C(  93), -INT8_C(  48),  INT8_C(   4),  INT8_C(  23),
       INT8_C(  38), -INT8_C(  44),  INT8_C(  53),  INT8_C(  95), -INT8_C( 126), -INT8_C(  13), -INT8_C(  45),  INT8_C( 116),
       INT8_C(  19), -INT8_C(  83),  INT8_C( 125), -INT8_C(  27), -INT8_C(  20),  INT8_C(  99),  INT8_C( 126),  INT8_C(  66),
       INT8_C(   2),  INT8_C(  47), -INT8_C(  68), -INT8_C(  32),  INT8_C(  46), -INT8_C(   4),  INT8_C(  62), -INT8_C( 108),
      -INT8_C(  31), -INT8_C(  29), -INT8_C(  85), -INT8_C( 124), -INT8_C(  77), -INT8_C(  81), -INT8_C( 101), -INT8_C(  38),
      -INT8_C( 125), -INT8_C(  47),  INT8_C(  57),  INT8_C(   6), -INT8_C(  60),  INT8_C(  13),  INT8_C( 122), -INT8_C(  40),
      -INT8_C(  70), -INT8_C(   9), -INT8_C(  67), -INT8_C(  90),  INT8_C(  90),  INT8_C(  59), -INT8_C(  23),  INT8_C(  92),
       INT8_C( 106), -INT8_C(  91),  INT8_C(  60), -INT8_C( 104), -INT8_C(  95),  INT8_C( 123),  INT8_C(  45), -INT8_C( 125),
       INT8_C(  94), -INT8_C(  40),  INT8_C(   7),  INT8_C(  18), -INT8_C( 121), -INT8_C(  93), -INT8_C(  20),  INT8_C(  11),
       INT8_C( 116),  INT8_C(  37),  INT8_C(  17),  INT8_C(  56),  INT8_C(  50), -INT8_C( 117),  INT8_C(  16), -INT8_C(  19),
      -INT8_C( 126), -INT8_C(  50), -INT8_C( 109), -INT8_C(  36),  INT8_C(   9),  INT8_C( 124),  INT8_C(  56),  INT8_C( 116),
       INT8_C(  34),  INT8_C( 117),  INT8_C(  12), -INT8_C(  61), -INT8_C(  16),  INT8_C(  57),  INT8_C(  70),  INT8_C(  78),
       INT8_C(  17),  INT8_C(  78),  INT8_C(  96), -INT8_C( 103), -INT8_C(  15),  INT8_C(  76), -INT8_C(  92),  INT8_C( 101),
       INT8_C( 114), -INT8_C(  75), -INT8_C(  99), -INT8_C(  92),  INT8_C(  64), -INT8_C(  82), -INT8_C( 111), -INT8_C(  62),
       INT8_C( 124),  INT8_C(  37), -INT8_C(  98), -INT8_C( 123), -INT8_C(  95), -INT8_C(  42), -INT8_C(   7), -INT8_C(  61),
       INT8_C(  75),  INT8_C(   6), -INT8_C( 121),  INT8_C(  59),  INT8_C(  63), -INT8_C(  51), -INT8_C( 118),  INT8_C(  81),
       INT8_C(  27), -INT8_C(  22), -INT8_C(  22),  INT8_C(  12),  INT8_C(  55), -INT8_C( 114),  INT8_C( 113), -INT8_C(  87),
       INT8_C(  67),  INT8_C(  15),  INT8_C(  77), -INT8_C( 125), -INT8_C(  67), -INT8_C(  33),  INT8_C(  69),  INT8_C(  57),
       INT8_C(   4), -INT8_C(  29), -INT8_C(  66), -INT8_C(  91), -INT8_C(  71), -INT8_C(  72),  INT8_C( 105),  INT8_C(   5),
      -INT8_C(  66), -INT8_C(  16),  INT8_C(  64), -INT8_C(   3), -INT8_C(  67), -INT8_C(  54),  INT8_C(  78), -INT8_C(  39),
      -INT8_C(  75),  INT8_C(  56), -INT8_C(  27), -INT8_C(  20), -INT8_C(  58),  INT8_C(  87), -INT8_C( 107),  INT8_C(   9),
       INT8_C( 102), -INT8_C(  30), -INT8_C( 116),  INT8_C(  35), -INT8_C(  63), -INT8_C(  47),  INT8_C(  92), -INT8_C(  59),
      -INT8_C(  76),  INT8_C(  26),  INT8_C( 107),  INT8_C( 110), -INT8_C(  46), -INT8_C(  44),  INT8_C( 115), -INT8_C( 112),
      -INT8_C(  60), -INT8_C(  77), -INT8_C( 114), -INT8_C( 127),  INT8_C( 126), -INT8_C(  36),  INT8_C(  90),  INT8_C(  51),
       INT8_C(  21),  INT8_C(  64),  INT8_C(  31), -INT8_C(  37), -INT8_C( 105), -INT8_C(  76), -INT8_C(  27), -INT8_C(   3),
      -INT8_C( 106),  INT8_C( 113),  INT8_C(  32),  INT8_C(  88),  INT8_C(  67),  INT8_C( 124),  INT8_C(  29), -INT8_C(   9),
      -INT8_C( 106), -INT8_C( 120),  INT8_C( 101),  INT8_C( 105),  INT8_C(  92), -INT8_C(  40), -INT8_C(   7),  INT8_C(  32),
      -INT8_C( 116), -INT8_C( 121), -INT8_C(  94),  INT8_C(  10),  INT8_C( 100), -INT8_C(   4),  INT8_C(  61),  INT8_C( 121),
       INT8_C(  60),  INT8_C(  92),  INT8_C(  84), -INT8_C(  45),  INT8_C(  16),  INT8_C(  57), -INT8_C(  48), -INT8_C(  90),
      -INT8_C(  85), -INT8_C(  16), -INT8_C(   2), -INT8_C(  18),  INT8_C( 108),  INT8_C(  28), -INT8_C(  27),  INT8_C(   3),
      -INT8_C(  92),  INT8_C(  75),  INT8_C( 108),  INT8_C(   1),  INT8_C(  35),  INT8_C( 101),  INT8_C(  33), -INT8_C(  81),
      -INT8_C(  19), -INT8_C(  61), -INT8_C(  71),  INT8_C(  81), -INT8_C(  64), -INT8_C(  10), -INT8_C(  54), -INT8_C(   4),
       INT8_C(  82),  INT8_C(  30), -INT8_C(  48),  INT8_C(  98),  INT8_C(  88), -INT8_C(  96),  INT8_C(   9),  INT8_C(   3),
      -INT8_C( 111),  INT8_C(   7), -INT8_C(  15), -INT8_C(   3),  INT8_C(  35), -INT8_C(  42),  INT8_C(   0), -INT8_C(  56),
       INT8_C(  33),  INT8_C( 108), -INT8_C(  55),  INT8_C(  69), -INT8_C(  46), -INT8_C(  22), -INT8_C(  12), -INT8_C(  65),
      -INT8_C(  82), -INT8_C(  82),  INT8_C(  16),  INT8_C( 110), -INT8_C(  92), -INT8_C(  38),  INT8_C( 106), -INT8_C(   9),
      -INT8_C(   8),  INT8_C(  58),  INT8_C(  89),  INT8_C(  80), -INT8_C(  37),  INT8_C(  98),  INT8_C(  83),  INT8_C( 108),
       INT8_C( 106),  INT8_C(  68),  INT8_C( 105), -INT8_C( 115),  INT8_C(  27),  INT8_C( 106),  INT8_C(  85),  INT8_C(  60),
      -INT8_C(  42),  INT8_C(  30), -INT8_C( 127), -INT8_C(  88),  INT8_C(   9),  INT8_C( 118),  INT8_C( 103), -INT8_C(  73),
       INT8_C(  36),  INT8_C( 119),  INT8_C(  37), -INT8_C(  56),  INT8_C(  81), -INT8_C( 113), -INT8_C(  65),  INT8_C(  74),
      -INT8_C(  54),  INT8_C(  25), -INT8_C( 102), -INT8_C(  91),  INT8_C( 123), -INT8_C(  18),  INT8_C(  17), -INT8_C(  27),
       INT8_C(  50),  INT8_C( 122),  INT8_C( 115),  INT8_C(  77), -INT8_C(  28), -INT8_C(  56), -INT8_C( 118), -INT8_C(  69),
      -INT8_C(  25),  INT8_C(  11),  INT8_C(  99), -INT8_C(  16), -INT8_C( 127), -INT8_C(  53), -INT8_C(  89), -INT8_C(  91),
       INT8_C(  66), -INT8_C(  52),  INT8_C( 110), -INT8_C( 108),  INT8_C(  91),  INT8_C(  45), -INT8_C(  34),  INT8_C(  37),
       INT8_C(  70),  INT8_C( 120), -INT8_C(  54), -INT8_C(  62),  INT8_C( 102), -INT8_C(  37), -INT8_C(  89), -INT8_C( 103),
       INT8_C(  86),  INT8_C(  26), -INT8_C(  26),  INT8_C(  58), -INT8_C(  29),  INT8_C( 112), -INT8_C(  11), -INT8_C(  54),
       INT8_C( 124),  INT8_C(  89), -INT8_C(  70), -INT8_C(   3),  INT8_C(  36),  INT8_C(  97), -INT8_C(  93),  INT8_C( 102),
       INT8_C(  45),  INT8_C(  17), -INT8_C(   6), -INT8_C( 120),  INT8_C(  62), -INT8_C(  40), -INT8_C(  82), -INT8_C( 123),
       INT8_C(  81),  INT8_C( 120),  INT8_C(  71), -INT8_C(  73),  INT8_C(  84), -INT8_C(  18),  INT8_C(  80), -INT8_C(  86),
       INT8_C(   9),  INT8_C(  55), -INT8_C(  28), -INT8_C(  20), -INT8_C(  89), -INT8_C(  38), -INT8_C(  74),  INT8_C(  35),
       INT8_C(  51),  INT8_C( 112),  INT8_C(  33),  INT8_C(  87), -INT8_C(  47), -INT8_C(  60), -INT8_C(  67), -INT8_C(   2),
      -INT8_C(  43), -INT8_C(  72), -INT8_C( 122),  INT8_C(  19), -INT8_C( 112),  INT8_C(  52), -INT8_C( 104), -INT8_C(  31),
      -INT8_C(  83), -INT8_C(  33), -INT8_C( 103),  INT8_C(   1), -INT8_C(  50), -INT8_C(  23), -INT8_C(  85), -INT8_C(  41),
       INT8_C(  32), -INT8_C( 113), -INT8_C(  61), -INT8_C(  56),  INT8_C( 105),  INT8_C( 121), -INT8_C(  21), -INT8_C( 100),
      -INT8_C(  23),  INT8_C(  12), -INT8_C(  13), -INT8_C(  70), -INT8_C(  48), -INT8_C(  79), -INT8_C(  72), -INT8_C(  91),
       INT8_C( 105),  INT8_C(  62), -INT8_C(  71), -INT8_C(   7),  INT8_C( 115),  INT8_C(  81), -INT8_C(  37),  INT8_C(  32),
       INT8_C(  49),  INT8_C( 116),  INT8_C(  33), -INT8_C(   1),  INT8_C(  93), -INT8_C(  52), -INT8_C(  42),  INT8_C( 126),
       INT8_C(  91), -INT8_C( 103),  INT8_C(  70), -INT8_C(  59),  INT8_C(  18),  INT8_C(  49),  INT8_C(  97), -INT8_C(   5),
       INT8_C(  62),  INT8_C(  85), -INT8_C(  75),  INT8_C(  14),  INT8_C(   6),  INT8_C( 109), -INT8_C(  76),  INT8_C( 111),
      -INT8_C(  85),  INT8_C( 109),  INT8_C( 104),  INT8_C(  30), -INT8_C(  66),  INT8_C(  67),  INT8_C(  62), -INT8_C(  17),
      -INT8_C(  73),  INT8_C(  95), -INT8_C(  18),  INT8_C(  21),  INT8_C(  43), -INT8_C(  60), -INT8_C( 109), -INT8_C( 121),
       INT8_C(  93), -INT8_C(  39),  INT8_C(  76),  INT8_C( 111),  INT8_C(  10), -INT8_C(  83),  INT8_C( 106),  INT8_C(  72),
       INT8_C(   2),  INT8_C(  31),  INT8_C(  87),  INT8_C(   8), -INT8_C( 116),  INT8_C(  11),  INT8_C( 119),  INT8_C(  56),
       INT8_C( 120), -INT8_C(  32),  INT8_C(  86),  INT8_C(  54),  INT8_C(  35), -INT8_C( 107),  INT8_C(  38), -INT8_C(  37),
      -INT8_C(  12),  INT8_C(  20), -INT8_C(  16),  INT8_C(  32), -INT8_C(  39), -INT8_C( 125), -INT8_C(  89),  INT8_C(  54),
       INT8_C(  92), -INT8_C(  13), -INT8_C(  90),  INT8_C( 102), -INT8_C(  96),  INT8_C(  16), -INT8_C(  81), -INT8_C(  93),
       INT8_C(  48),  INT8_C(   6), -INT8_C(  85), -INT8_C(  68),  INT8_C(  17),  INT8_C(  35), -INT8_C(  12), -INT8_C( 119),
       INT8_C(   3),  INT8_C(  75), -INT8_C(  65),  INT8_C(  38), -INT8_C(  32), -INT8_C(  27),  INT8_C(   1), -INT8_C(  44),
      -INT8_C(   6), -INT8_C(  15), -INT8_C(  12), -INT8_C(  45),  INT8_C( 116), -INT8_C( 101),  INT8_C(   9), -INT8_C(  48),
      -INT8_C( 114), -INT8_C(  81),  INT8_C(  55),  INT8_C(  47), -INT8_C(  64), -INT8_C(  26), -INT8_C(  46), -INT8_C(  16),
      -INT8_C(  20),  INT8_C( 125), -INT8_C(  84), -INT8_C(   3), -INT8_C(  96), -INT8_C(  95), -INT8_C( 122), -INT8_C(  93),
      -INT8_C(  20),  INT8_C(  69), -INT8_C(  54), -INT8_C(  52),  INT8_C(  43), -INT8_C(  53), -INT8_C(  96),  INT8_C(  37),
      -INT8_C(  67), -INT8_C( 107), -INT8_C(   8),  INT8_C(  49),  INT8_C(  48),  INT8_C(   1),  INT8_C(   2), -INT8_C(  65),
      -INT8_C(  79),  INT8_C(  57), -INT8_C(  18),  INT8_C( 113),  INT8_C(  31), -INT8_C(  64),  INT8_C(  97),  INT8_C(  11),
       INT8_C(  61),  INT8_C(  13),  INT8_C(   8), -INT8_C(  34), -INT8_C(  82), -INT8_C( 114), -INT8_C( 127), -INT8_C( 102),
      -INT8_C(  45),  INT8_C(  75),  INT8_C( 102), -INT8_C(   2),  INT8_C(  23),  INT8_C(   7),  INT8_C(  35), -INT8_C(  44),
      -INT8_C( 100),  INT8_C(  27),  INT8_C(   5), -INT8_C(  52),  INT8_C(  29),  INT8_C(   7), -INT8_C( 117), -INT8_C(  50),
       INT8_C(  64),  INT8_C( 121),  INT8_C(  63),  INT8_C(  95),  INT8_C(  57), -INT8_C(  96),  INT8_C( 106),  INT8_C( 119),
      -INT8_C(  83),  INT8_C( 114),  INT8_C(  85),  INT8_C(  92),  INT8_C(   0), -INT8_C(  42), -INT8_C(  10), -INT8_C(  44),
       INT8_C(  34),  INT8_C(  93), -INT8_C(  46),  INT8_C(  57),  INT8_C( 100), -INT8_C(  10),  INT8_C(  13),  INT8_C(   0),
       INT8_C(  17),  INT8_C(  18), -INT8_C(  52),  INT8_C(  46),  INT8_C(  26),  INT8_C(  88), -INT8_C(   4),  INT8_C(  90),
      -INT8_C(  47),  INT8_C(  59), -INT8_C(  70),  INT8_C(  11), -INT8_C(  37),  INT8_C(  36), -INT8_C( 126), -INT8_C( 119),
      -INT8_C( 105), -INT8_C(  41), -INT8_C(  27), -INT8_C( 105), -INT8_C(  83), -INT8_C(  37),  INT8_C( 107), -INT8_C(  49),
       INT8_C(  56),  INT8_C(  62),  INT8_C(   8), -INT8_C( 100),  INT8_C(  52),  INT8_C(  21), -INT8_C( 100),  INT8_C(  69),
       INT8_C(  40),  INT8_C( 105),  INT8_C( 116),  INT8_C(  66), -INT8_C(  63),  INT8_C( 112), -INT8_C( 100), -INT8_C( 110),
      -INT8_C(  84),  INT8_C(  86), -INT8_C(  99), -INT8_C( 121),  INT8_C( 123),  INT8_C(  31),  INT8_C(  16),  INT8_C(  18),
      -INT8_C(  10), -INT8_C(  11), -INT8_C(  87), -INT8_C(  92), -INT8_C(  47),  INT8_C(  21),  INT8_C( 115),  INT8_C(   9),
       INT8_C(  83),  INT8_C( 124), -INT8_C(  90), -INT8_C( 121), -INT8_C( 111),  INT8_C(  66), -INT8_C(  52), -INT8_C(  71),
      -INT8_C(  85),  INT8_C(  64), -INT8_C(   5),  INT8_C( 108), -INT8_C(  79), -INT8_C( 104), -INT8_C(   1),  INT8_C(  93),
      -INT8_C(  18), -INT8_C( 100), -INT8_C(  28),  INT8_C( 105), -INT8_C(  68), -INT8_C(  11),  INT8_C( 123), -INT8_C(  78),
      -INT8_C(  22),  INT8_C(  37),  INT8_C(  86), -INT8_C(  69),  INT8_C(  58), -INT8_C(  54), -INT8_C(  59), -INT8_C( 115),
       INT8_C(  70),  INT8_C( 107),  INT8_C(  20), -INT8_C(  41), -INT8_C(  83), -INT8_C(  32), -INT8_C( 111),  INT8_C(  89),
       INT8_C(  33), -INT8_C( 116), -INT8_C(  59), -INT8_C(  46),  INT8_C(  36), -INT8_C(  60),  INT8_C(  47),  INT8_C(  19),
       INT8_C(  97),  INT8_C(  19),  INT8_C( 124),  INT8_C(  29),  INT8_C(   8), -INT8_C(   8), -INT8_C(  49), -INT8_C(  13),
       INT8_C(  29),  INT8_C(  38), -INT8_C(  82),  INT8_C(  87), -INT8_C(  16),  INT8_C( 115), -INT8_C(  28),  INT8_C(  54),
      -INT8_C(  34), -INT8_C(   8),  INT8_C(  13), -INT8_C( 116), -INT8_C(  40), -INT8_C(  98), -INT8_C(  27), -INT8_C(   7),
       INT8_C(  43), -INT8_C(  86), -INT8_C(  53),  INT8_C(  79),  INT8_C( 111), -INT8_C(   6),  INT8_C(  98), -INT8_C(  48),
       INT8_C(  14), -INT8_C(  33), -INT8_C(  19),  INT8_C(  22), -INT8_C(  41), -INT8_C(  68),  INT8_C(   9), -INT8_C(  12),
      -INT8_C(  30), -INT8_C(  72),  INT8_C(  75), -INT8_C(  46),  INT8_C(  43),  INT8_C(  47),  INT8_C(   8),  INT8_C(  10),
       INT8_C(  39),  INT8_C(  22), -INT8_C( 106), -INT8_C(   1), -INT8_C(  76),  INT8_C( 123), -INT8_C(   7), -INT8_C(  33),
       INT8_C(  37), -INT8_C(  60),  INT8_C(  47), -INT8_C( 108), -INT8_C(  65), -INT8_C( 111),  INT8_C( 100), -INT8_C(  51),
       INT8_C( 112),  INT8_C(  81), -INT8_C(  29),  INT8_C(  71),  INT8_C(  14), -INT8_C(  19),  INT8_C(  59), -INT8_C(  16),
      -INT8_C(  91), -INT8_C( 122), -INT8_C(  61), -INT8_C(  48), -INT8_C(  75), -INT8_C(  53), -INT8_C(  38), -INT8_C(  36),
      -INT8_C(  31),  INT8_C( 112), -INT8_C(  36), -INT8_C( 106), -INT8_C(  21), -INT8_C(  43),  INT8_C( 117),  INT8_C(  17),
      -INT8_C( 103), -INT8_C(  92), -INT8_C(  91),  INT8_C(  88),  INT8_C(  54),  INT8_C(  10),  INT8_C(  37), -INT8_C(  90),
       INT8_C(  91),  INT8_C(   9), -INT8_C(  18),  INT8_C( 105), -INT8_C(  10),  INT8_C(  41),  INT8_C(  90), -INT8_C( 101),
      -INT8_C(  80),  INT8_C(  29),  INT8_C( 107),  INT8_C( 101), -INT8_C(  24),  INT8_C(  70),  INT8_C(  66), -INT8_C(  54),
      -INT8_C(  74),  INT8_C(  30),  INT8_C(  96), -INT8_C(  94), -INT8_C(  13), -INT8_C(  43), -INT8_C(  77), -INT8_C( 116),
       INT8_C( 122),  INT8_C(  88), -INT8_C(  27), -INT8_C(  80),  INT8_C(  98),  INT8_C(  10),  INT8_C(  86), -INT8_C(  66),
       INT8_C(  19),  INT8_C(  68),  INT8_C(  39),  INT8_C(   9),  INT8_C( 110), -INT8_C( 127), -INT8_C(  92),  INT8_C(  30),
      -INT8_C(  98),  INT8_C(  16), -INT8_C( 125), -INT8_C( 121),  INT8_C(  86), -INT8_C(  59),  INT8_C(  81),  INT8_C(  12),
      -INT8_C(  29), -INT8_C(  79), -INT8_C(  82), -INT8_C(  42), -INT8_C( 122),  INT8_C(  97),  INT8_C(  99),  INT8_C(   0),
      -INT8_C(  70),  INT8_C(  72), -INT8_C(  80),  INT8_C(  28),  INT8_C(  82),  INT8_C(   7), -INT8_C(  38),  INT8_C( 102),
       INT8_C(  75),  INT8_C(   2),  INT8_C( 111), -INT8_C(  71), -INT8_C( 125),  INT8_C(  20), -INT8_C(  41),  INT8_C(  34),
       INT8_C(  36),  INT8_C(  91), -INT8_C(  87),  INT8_C( 122),  INT8_C(  32), -INT8_C(   6), -INT8_C( 122),  INT8_C(   4),
      -INT8_C(  85),  INT8_C(  53), -INT8_C(  38),  INT8_C(  49), -INT8_C( 106),  INT8_C(  61),  INT8_C(  50),  INT8_C(  80),
      -INT8_C( 123), -INT8_C(  30),  INT8_C( 109), -INT8_C(  40), -INT8_C(  23),  INT8_C(  71),  INT8_C(  62),  INT8_C(  53),
       INT8_C(  73), -INT8_C(  83), -INT8_C(  18), -INT8_C(  51), -INT8_C(  63), -INT8_C(  58), -INT8_C(  17), -INT8_C(  27),
       INT8_C(  33), -INT8_C( 104),  INT8_C(  95),  INT8_C(  65), -INT8_C( 110), -INT8_C(  26),  INT8_C(  69),  INT8_C(  61),
       INT8_C(  27),  INT8_C(  32),  INT8_C( 110), -INT8_C(  79),  INT8_C(  93), -INT8_C(  96),  INT8_C(   2), -INT8_C(  29),
      -INT8_C( 125),  INT8_C( 111), -INT8_C(  69),  INT8_C( 108), -INT8_C(  74) };
  static const int8_t b =  INT8_C(  84);
  static const int8_t e[] =
    {  INT8_C(  59),  INT8_C(  67),  INT8_C(  98),  INT8_C(  18), -INT8_C(  61), -INT8_C(  78),  INT8_C( 100), -INT8_C(  35),
      -INT8_C(  58),  INT8_C(  24),  INT8_C( 101), -INT8_C(  60),  INT8_C(  35),  INT8_C(  62),  INT8_C(  78), -INT8_C(  59),
      -INT8_C( 127),  INT8_C( 103),  INT8_C(  82),  INT8_C(  70), -INT8_C(  80), -INT8_C(  67), -INT8_C(  41), -INT8_C( 102),
       INT8_C(  32),  INT8_C(  86),  INT8_C( 123), -INT8_C(  54), -INT8_C(  27), -INT8_C(  82), -INT8_C(  66),  INT8_C(  32),
      -INT8_C(  99), -INT8_C(  52), -INT8_C( 122),  INT8_C(   9),  INT8_C( 126), -INT8_C(  22), -INT8_C(  26),  INT8_C(  68),
       INT8_C(  86), -INT8_C(  97),  INT8_C(  93),  INT8_C(  38), -INT8_C(  35), -INT8_C(  85), -INT8_C(  21),  INT8_C(  10),
       INT8_C( 102), -INT8_C(  27),  INT8_C(  81),  INT8_C(  22),  INT8_C(  79),  INT8_C( 124), -INT8_C(  80), -INT8_C(  61),
       INT8_C(  38),      INT8_MIN, -INT8_C(  31),  INT8_C(  11), -INT8_C( 126), -INT8_C(  97), -INT8_C(  45),  INT8_C(  32),
       INT8_C(  19),  INT8_C(  89),  INT8_C( 125), -INT8_C( 111), -INT8_C( 104),  INT8_C(  15),  INT8_C(  42),  INT8_C(  66),
      -INT8_C(  82),  INT8_C(  47),  INT8_C( 104), -INT8_C(  32),  INT8_C(  46), -INT8_C(   4), -INT8_C(  22),  INT8_C(  64),
      -INT8_C( 115), -INT8_C( 113),  INT8_C(  87), -INT8_C( 124), -INT8_C(  77),  INT8_C(  91),  INT8_C(  71), -INT8_C(  38),
       INT8_C(  47), -INT8_C(  47), -INT8_C(  27),  INT8_C(   6), -INT8_C(  60),  INT8_C(  13),  INT8_C( 122), -INT8_C(  40),
       INT8_C( 102), -INT8_C(   9), -INT8_C(  67),  INT8_C(  82),  INT8_C(  90), -INT8_C(  25), -INT8_C( 107),  INT8_C(   8),
       INT8_C( 106), -INT8_C(  91),  INT8_C(  60),  INT8_C(  68),  INT8_C(  77),  INT8_C(  39),  INT8_C(  45), -INT8_C( 125),
       INT8_C(  10), -INT8_C(  40), -INT8_C(  77), -INT8_C(  66), -INT8_C( 121),  INT8_C(  79), -INT8_C(  20), -INT8_C(  73),
       INT8_C( 116),  INT8_C(  37),  INT8_C(  17),  INT8_C(  56),  INT8_C(  50), -INT8_C( 117), -INT8_C(  68), -INT8_C(  19),
       INT8_C(  46),  INT8_C( 122),  INT8_C(  63), -INT8_C( 120), -INT8_C(  75),  INT8_C(  40), -INT8_C(  28),  INT8_C( 116),
       INT8_C(  34),  INT8_C(  33), -INT8_C(  72),  INT8_C( 111), -INT8_C(  16), -INT8_C(  27),  INT8_C(  70),  INT8_C(  78),
       INT8_C(  17), -INT8_C(   6),  INT8_C(  12), -INT8_C( 103), -INT8_C(  99),  INT8_C(  76), -INT8_C(  92),  INT8_C(  17),
       INT8_C( 114), -INT8_C(  75),  INT8_C(  73), -INT8_C(  92),  INT8_C(  64), -INT8_C(  82), -INT8_C( 111), -INT8_C(  62),
       INT8_C( 124),  INT8_C(  37),  INT8_C(  74), -INT8_C( 123), -INT8_C(  95), -INT8_C(  42), -INT8_C(   7), -INT8_C(  61),
      -INT8_C(   9), -INT8_C(  78), -INT8_C( 121),  INT8_C(  59), -INT8_C(  21),  INT8_C( 121), -INT8_C( 118), -INT8_C(   3),
      -INT8_C(  57), -INT8_C(  22), -INT8_C( 106),  INT8_C(  12),  INT8_C(  55),  INT8_C(  58),  INT8_C(  29),  INT8_C(  85),
       INT8_C(  67), -INT8_C(  69), -INT8_C(   7), -INT8_C( 125), -INT8_C(  67), -INT8_C(  33), -INT8_C(  15),  INT8_C(  57),
      -INT8_C(  80), -INT8_C(  29),  INT8_C( 106),  INT8_C(  81),  INT8_C( 101),  INT8_C( 100),  INT8_C( 105), -INT8_C(  79),
       INT8_C( 106), -INT8_C(  16),  INT8_C(  64), -INT8_C(   3), -INT8_C(  67), -INT8_C(  54),  INT8_C(  78), -INT8_C( 123),
       INT8_C(  97),  INT8_C(  56), -INT8_C( 111), -INT8_C(  20),  INT8_C( 114),  INT8_C(   3),  INT8_C(  65), -INT8_C(  75),
       INT8_C(  18), -INT8_C( 114), -INT8_C( 116), -INT8_C(  49),  INT8_C( 109), -INT8_C(  47),  INT8_C(  92), -INT8_C(  59),
       INT8_C(  96), -INT8_C(  58),  INT8_C( 107),  INT8_C( 110), -INT8_C(  46), -INT8_C(  44),  INT8_C( 115), -INT8_C( 112),
       INT8_C( 112), -INT8_C(  77),  INT8_C(  58),  INT8_C(  45),  INT8_C(  42), -INT8_C( 120),  INT8_C(   6),  INT8_C(  51),
      -INT8_C(  63),  INT8_C(  64),  INT8_C(  31), -INT8_C( 121), -INT8_C( 105), -INT8_C(  76), -INT8_C( 111), -INT8_C(  87),
       INT8_C(  66),  INT8_C( 113),  INT8_C(  32),  INT8_C(   4),  INT8_C(  67),  INT8_C(  40),  INT8_C(  29), -INT8_C(  93),
      -INT8_C( 106), -INT8_C( 120),  INT8_C(  17),  INT8_C(  21),  INT8_C(  92), -INT8_C( 124), -INT8_C(  91),  INT8_C(  32),
      -INT8_C( 116), -INT8_C( 121),  INT8_C(  78), -INT8_C(  74),  INT8_C( 100), -INT8_C(   4), -INT8_C(  23),  INT8_C(  37),
      -INT8_C(  24),  INT8_C(  92),  INT8_C(   0), -INT8_C(  45),  INT8_C(  16),  INT8_C(  57),  INT8_C( 124), -INT8_C(  90),
      -INT8_C(  85), -INT8_C(  16), -INT8_C(   2), -INT8_C(  18),  INT8_C(  24),  INT8_C(  28), -INT8_C(  27),  INT8_C(   3),
       INT8_C(  80),  INT8_C(  75),  INT8_C(  24),  INT8_C(   1),  INT8_C(  35),  INT8_C(  17),  INT8_C(  33), -INT8_C(  81),
      -INT8_C(  19),  INT8_C( 111),  INT8_C( 101), -INT8_C(   3), -INT8_C(  64), -INT8_C(  94),  INT8_C( 118), -INT8_C(   4),
      -INT8_C(   2),  INT8_C(  30), -INT8_C(  48),  INT8_C(  98),  INT8_C(  88), -INT8_C(  96), -INT8_C(  75), -INT8_C(  81),
       INT8_C(  61), -INT8_C(  77), -INT8_C(  15), -INT8_C(  87),  INT8_C(  35), -INT8_C(  42), -INT8_C(  84),  INT8_C( 116),
       INT8_C(  33),  INT8_C(  24),  INT8_C( 117),  INT8_C(  69),  INT8_C( 126), -INT8_C( 106), -INT8_C(  12), -INT8_C(  65),
       INT8_C(  90), -INT8_C(  82), -INT8_C(  68),  INT8_C( 110),  INT8_C(  80), -INT8_C(  38),  INT8_C( 106), -INT8_C(  93),
      -INT8_C(   8),  INT8_C(  58),  INT8_C(  89), -INT8_C(   4), -INT8_C( 121),  INT8_C(  14), -INT8_C(   1),  INT8_C( 108),
       INT8_C(  22), -INT8_C(  16),  INT8_C( 105),  INT8_C(  57),  INT8_C(  27),  INT8_C( 106),  INT8_C(  85), -INT8_C(  24),
      -INT8_C( 126), -INT8_C(  54),  INT8_C(  45),  INT8_C(  84), -INT8_C(  75),  INT8_C( 118),  INT8_C(  19), -INT8_C(  73),
      -INT8_C(  48),  INT8_C(  35),  INT8_C(  37), -INT8_C(  56), -INT8_C(   3),  INT8_C(  59), -INT8_C(  65),  INT8_C(  74),
      -INT8_C(  54),  INT8_C(  25), -INT8_C( 102),  INT8_C(  81),  INT8_C(  39), -INT8_C(  18),  INT8_C(  17), -INT8_C(  27),
       INT8_C(  50),  INT8_C( 122),  INT8_C(  31),  INT8_C(  77), -INT8_C(  28), -INT8_C(  56),  INT8_C(  54), -INT8_C(  69),
      -INT8_C( 109), -INT8_C(  73),  INT8_C(  99), -INT8_C( 100), -INT8_C( 127),  INT8_C( 119),  INT8_C(  83),  INT8_C(  81),
      -INT8_C(  18), -INT8_C(  52),  INT8_C( 110),  INT8_C(  64),  INT8_C(   7),  INT8_C(  45), -INT8_C( 118), -INT8_C(  47),
       INT8_C(  70),  INT8_C( 120),  INT8_C( 118), -INT8_C(  62),  INT8_C( 102), -INT8_C( 121),  INT8_C(  83), -INT8_C( 103),
       INT8_C(  86), -INT8_C(  58), -INT8_C( 110), -INT8_C(  26), -INT8_C( 113),  INT8_C( 112), -INT8_C(  11),  INT8_C( 118),
       INT8_C( 124),  INT8_C(  89), -INT8_C(  70), -INT8_C(  87),  INT8_C(  36),  INT8_C(  97), -INT8_C(  93),  INT8_C(  18),
      -INT8_C(  39), -INT8_C(  67), -INT8_C(   6), -INT8_C( 120),  INT8_C(  62), -INT8_C(  40), -INT8_C(  82),  INT8_C(  49),
       INT8_C(  81),  INT8_C(  36), -INT8_C(  13),  INT8_C(  99),  INT8_C(   0), -INT8_C( 102), -INT8_C(   4), -INT8_C(  86),
       INT8_C(   9), -INT8_C(  29), -INT8_C(  28), -INT8_C(  20), -INT8_C(  89), -INT8_C(  38),  INT8_C(  98),  INT8_C(  35),
       INT8_C(  51),  INT8_C( 112), -INT8_C(  51),  INT8_C(  87), -INT8_C(  47), -INT8_C(  60),  INT8_C( 105), -INT8_C(  86),
      -INT8_C(  43),  INT8_C( 100), -INT8_C( 122),  INT8_C(  19),  INT8_C(  60),  INT8_C(  52),  INT8_C(  68), -INT8_C(  31),
      -INT8_C(  83), -INT8_C( 117),  INT8_C(  69),  INT8_C(   1), -INT8_C(  50), -INT8_C( 107),  INT8_C(  87), -INT8_C( 125),
       INT8_C(  32),  INT8_C(  59),  INT8_C( 111), -INT8_C(  56),  INT8_C(  21),  INT8_C( 121), -INT8_C( 105),  INT8_C(  72),
      -INT8_C(  23), -INT8_C(  72), -INT8_C(  13),  INT8_C( 102), -INT8_C(  48), -INT8_C(  79),  INT8_C( 100), -INT8_C(  91),
       INT8_C(  21), -INT8_C(  22), -INT8_C(  71), -INT8_C(  91),  INT8_C( 115),  INT8_C(  81), -INT8_C(  37), -INT8_C(  52),
      -INT8_C(  35),  INT8_C( 116), -INT8_C(  51), -INT8_C(   1),  INT8_C(   9),  INT8_C( 120), -INT8_C( 126),  INT8_C( 126),
       INT8_C(  91), -INT8_C( 103), -INT8_C(  14), -INT8_C(  59), -INT8_C(  66),  INT8_C(  49),  INT8_C(  97), -INT8_C(   5),
       INT8_C(  62),  INT8_C(  85),  INT8_C(  97),  INT8_C(  14),  INT8_C(   6),  INT8_C( 109), -INT8_C(  76),  INT8_C( 111),
      -INT8_C(  85),  INT8_C( 109),  INT8_C( 104),  INT8_C(  30), -INT8_C(  66),  INT8_C(  67), -INT8_C(  22), -INT8_C(  17),
      -INT8_C(  73),  INT8_C(  11), -INT8_C(  18),  INT8_C(  21),  INT8_C(  43),  INT8_C( 112), -INT8_C( 109),  INT8_C(  51),
       INT8_C(  93), -INT8_C(  39), -INT8_C(   8),  INT8_C(  27),  INT8_C(  10),  INT8_C(  89),  INT8_C(  22),  INT8_C(  72),
       INT8_C(   2), -INT8_C(  53),  INT8_C(  87),  INT8_C(   8),  INT8_C(  56), -INT8_C(  73),  INT8_C(  35), -INT8_C(  28),
       INT8_C(  36), -INT8_C( 116),  INT8_C(  86),  INT8_C(  54),  INT8_C(  35),  INT8_C(  65), -INT8_C(  46), -INT8_C( 121),
      -INT8_C(  96), -INT8_C(  64), -INT8_C(  16), -INT8_C(  52), -INT8_C( 123), -INT8_C( 125),  INT8_C(  83),  INT8_C(  54),
       INT8_C(   8), -INT8_C(  13),  INT8_C(  82),  INT8_C(  18), -INT8_C(  96), -INT8_C(  68), -INT8_C(  81), -INT8_C(  93),
       INT8_C(  48), -INT8_C(  78),  INT8_C(  87), -INT8_C(  68),  INT8_C(  17),  INT8_C(  35), -INT8_C(  12), -INT8_C( 119),
       INT8_C(   3),  INT8_C(  75),  INT8_C( 107), -INT8_C(  46), -INT8_C(  32), -INT8_C(  27),  INT8_C(   1),      INT8_MIN,
      -INT8_C(   6), -INT8_C(  15), -INT8_C(  96),      INT8_MAX,  INT8_C(  32), -INT8_C( 101),  INT8_C(   9), -INT8_C(  48),
       INT8_C(  58), -INT8_C(  81),  INT8_C(  55), -INT8_C(  37),  INT8_C( 108), -INT8_C( 110),  INT8_C( 126), -INT8_C(  16),
      -INT8_C(  20),  INT8_C( 125),  INT8_C(  88), -INT8_C(  87),  INT8_C(  76),  INT8_C(  77),  INT8_C(  50),  INT8_C(  79),
      -INT8_C( 104), -INT8_C(  15),  INT8_C( 118),  INT8_C( 120), -INT8_C(  41),  INT8_C( 119),  INT8_C(  76), -INT8_C(  47),
      -INT8_C(  67), -INT8_C( 107), -INT8_C(  92), -INT8_C(  35), -INT8_C(  36), -INT8_C(  83),  INT8_C(   2), -INT8_C(  65),
       INT8_C(  93),  INT8_C(  57), -INT8_C( 102),  INT8_C(  29), -INT8_C(  53), -INT8_C(  64),  INT8_C(  97),  INT8_C(  11),
      -INT8_C(  23), -INT8_C(  71),  INT8_C(   8), -INT8_C( 118), -INT8_C(  82),  INT8_C(  58),  INT8_C(  45), -INT8_C( 102),
      -INT8_C(  45),  INT8_C(  75),  INT8_C( 102), -INT8_C(   2), -INT8_C(  61), -INT8_C(  77),  INT8_C(  35), -INT8_C(  44),
      -INT8_C( 100), -INT8_C(  57), -INT8_C(  79),  INT8_C( 120), -INT8_C(  55),  INT8_C(   7),  INT8_C(  55),  INT8_C( 122),
      -INT8_C(  20),  INT8_C( 121), -INT8_C(  21),  INT8_C(  11), -INT8_C(  27),  INT8_C(  76),  INT8_C(  22),  INT8_C(  35),
      -INT8_C(  83),  INT8_C(  30),  INT8_C(  85),  INT8_C(   8), -INT8_C(  84), -INT8_C(  42), -INT8_C(  94), -INT8_C(  44),
       INT8_C(  34),  INT8_C(  93),  INT8_C( 126),  INT8_C(  57),  INT8_C(  16), -INT8_C(  94),  INT8_C(  13),  INT8_C(   0),
      -INT8_C(  67),  INT8_C(  18),  INT8_C( 120),  INT8_C(  46),  INT8_C(  26),  INT8_C(  88), -INT8_C(   4),  INT8_C(   6),
       INT8_C( 125), -INT8_C(  25),  INT8_C( 102), -INT8_C(  73), -INT8_C( 121),  INT8_C(  36), -INT8_C( 126),  INT8_C(  53),
      -INT8_C( 105), -INT8_C( 125), -INT8_C( 111), -INT8_C( 105),  INT8_C(  89), -INT8_C(  37),  INT8_C(  23), -INT8_C(  49),
       INT8_C(  56),  INT8_C(  62),  INT8_C(   8), -INT8_C( 100),  INT8_C(  52),  INT8_C(  21), -INT8_C( 100), -INT8_C(  15),
       INT8_C(  40),  INT8_C(  21),  INT8_C( 116), -INT8_C(  18), -INT8_C(  63),  INT8_C(  28),  INT8_C(  72), -INT8_C( 110),
      -INT8_C(  84),  INT8_C(  86),  INT8_C(  73), -INT8_C( 121),  INT8_C(  39),  INT8_C(  31),  INT8_C(  16),  INT8_C(  18),
      -INT8_C(  10), -INT8_C(  95), -INT8_C(  87), -INT8_C(  92),  INT8_C( 125),  INT8_C(  21),  INT8_C( 115),  INT8_C(   9),
      -INT8_C(   1),  INT8_C( 124), -INT8_C(  90),  INT8_C(  51), -INT8_C( 111), -INT8_C(  18),  INT8_C( 120),  INT8_C( 101),
       INT8_C(  87), -INT8_C(  20), -INT8_C(  89),  INT8_C(  24), -INT8_C(  79), -INT8_C( 104), -INT8_C(   1),  INT8_C(   9),
      -INT8_C( 102),  INT8_C(  72), -INT8_C(  28),  INT8_C( 105), -INT8_C(  68), -INT8_C(  11),  INT8_C( 123), -INT8_C(  78),
      -INT8_C( 106), -INT8_C(  47),  INT8_C(  86), -INT8_C(  69),  INT8_C(  58), -INT8_C(  54),  INT8_C( 113),  INT8_C(  57),
      -INT8_C(  14),  INT8_C( 107), -INT8_C(  64), -INT8_C(  41),  INT8_C(  89), -INT8_C(  32), -INT8_C( 111),  INT8_C(  89),
      -INT8_C(  51),  INT8_C(  56),  INT8_C( 113), -INT8_C(  46),  INT8_C(  36), -INT8_C(  60),  INT8_C(  47), -INT8_C(  65),
       INT8_C(  13),  INT8_C(  19),  INT8_C(  40), -INT8_C(  55),  INT8_C(   8), -INT8_C(   8), -INT8_C(  49), -INT8_C(  97),
      -INT8_C(  55), -INT8_C(  46), -INT8_C(  82),  INT8_C(  87), -INT8_C( 100),  INT8_C( 115), -INT8_C( 112), -INT8_C(  30),
      -INT8_C(  34), -INT8_C(   8), -INT8_C(  71),  INT8_C(  56), -INT8_C(  40),  INT8_C(  74), -INT8_C( 111), -INT8_C(   7),
      -INT8_C(  41),  INT8_C(  86),  INT8_C( 119), -INT8_C(   5),  INT8_C(  27), -INT8_C(  90),  INT8_C(  98),  INT8_C( 124),
       INT8_C(  14), -INT8_C( 117), -INT8_C( 103), -INT8_C(  62), -INT8_C(  41),  INT8_C( 104),  INT8_C(   9), -INT8_C(  12),
      -INT8_C( 114),  INT8_C( 100),  INT8_C(  75),  INT8_C( 126),  INT8_C(  43), -INT8_C(  37),  INT8_C(   8),  INT8_C(  10),
       INT8_C(  39), -INT8_C(  62), -INT8_C( 106), -INT8_C(   1),  INT8_C(  96),  INT8_C(  39), -INT8_C(  91), -INT8_C(  33),
      -INT8_C(  47), -INT8_C(  60), -INT8_C(  37),  INT8_C(  64), -INT8_C(  65),  INT8_C(  61),  INT8_C( 100), -INT8_C(  51),
       INT8_C(  28),  INT8_C(  81), -INT8_C( 113),  INT8_C(  71),  INT8_C(  14), -INT8_C(  19),  INT8_C(  59), -INT8_C( 100),
      -INT8_C(  91), -INT8_C( 122), -INT8_C(  61), -INT8_C(  48), -INT8_C(  75), -INT8_C(  53), -INT8_C( 122), -INT8_C(  36),
      -INT8_C(  31),  INT8_C(  28), -INT8_C( 120),  INT8_C(  66), -INT8_C(  21), -INT8_C( 127),  INT8_C( 117),  INT8_C(  17),
       INT8_C(  69),  INT8_C(  80),  INT8_C(  81),  INT8_C(   4), -INT8_C(  30),  INT8_C(  10),  INT8_C(  37),  INT8_C(  82),
       INT8_C(  91), -INT8_C(  75), -INT8_C( 102),  INT8_C( 105), -INT8_C(  10),  INT8_C(  41),  INT8_C(   6), -INT8_C( 101),
      -INT8_C(  80), -INT8_C(  55),  INT8_C(  23),  INT8_C(  17), -INT8_C( 108),  INT8_C(  70),  INT8_C(  66),  INT8_C( 118),
       INT8_C(  98), -INT8_C(  54),  INT8_C(  12), -INT8_C(  94), -INT8_C(  13), -INT8_C( 127),  INT8_C(  95), -INT8_C( 116),
       INT8_C(  38),  INT8_C(  88), -INT8_C(  27),  INT8_C(  92),  INT8_C(  14),  INT8_C(  10),  INT8_C(  86),  INT8_C( 106),
       INT8_C(  19),  INT8_C(  68), -INT8_C(  45),  INT8_C(   9),  INT8_C( 110),  INT8_C(  45),  INT8_C(  80), -INT8_C(  54),
      -INT8_C(  98), -INT8_C(  68),  INT8_C(  47), -INT8_C( 121),  INT8_C(  86),  INT8_C( 113),  INT8_C(  81),  INT8_C(  12),
      -INT8_C( 113), -INT8_C(  79),  INT8_C(  90), -INT8_C(  42),  INT8_C(  50),  INT8_C(  97),  INT8_C(  99), -INT8_C(  84),
       INT8_C( 102), -INT8_C(  12), -INT8_C(  80),  INT8_C(  28),  INT8_C(  82), -INT8_C(  77), -INT8_C( 122),  INT8_C( 102),
      -INT8_C(   9), -INT8_C(  82),  INT8_C(  27), -INT8_C(  71), -INT8_C( 125), -INT8_C(  64), -INT8_C(  41),  INT8_C(  34),
       INT8_C(  36),  INT8_C(  91),  INT8_C(  85),  INT8_C( 122), -INT8_C(  52), -INT8_C(  90), -INT8_C( 122), -INT8_C(  80),
       INT8_C(  87), -INT8_C(  31), -INT8_C( 122), -INT8_C(  35), -INT8_C( 106),  INT8_C(  61),  INT8_C(  50), -INT8_C(   4),
       INT8_C(  49), -INT8_C( 114),  INT8_C(  25), -INT8_C( 124), -INT8_C(  23), -INT8_C(  13),  INT8_C(  62),  INT8_C(  53),
       INT8_C(  73),  INT8_C(  89), -INT8_C( 102), -INT8_C(  51),  INT8_C( 109),  INT8_C( 114), -INT8_C( 101), -INT8_C( 111),
      -INT8_C(  51), -INT8_C( 104),  INT8_C(  95), -INT8_C(  19), -INT8_C( 110), -INT8_C( 110),  INT8_C(  69), -INT8_C(  23),
      -INT8_C(  57),  INT8_C(  32),  INT8_C(  26),  INT8_C(  93),  INT8_C(  93), -INT8_C(  96), -INT8_C(  82), -INT8_C(  29),
       INT8_C(  47),  INT8_C( 111), -INT8_C(  69),  INT8_C(  24),  INT8_C(  98) };

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
    rv = simde_svsub_n_s8_m(pv, av, b);

    simde_svst1_s8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vi8(len, e, r);

  return 0;
#else
  int8_t p[1024], a[1024], b, e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_s8(pg, &(a[i]));

    ev = simde_svsub_n_s8_m(pv, av, b);

    simde_svst1_s8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i8(1, b);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_s16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) };
  static const int16_t a[] =
    { -INT16_C(  5304), -INT16_C( 28699),  INT16_C( 12139),  INT16_C(   101), -INT16_C( 25954),  INT16_C( 21005), -INT16_C( 10305), -INT16_C( 27841),
      -INT16_C(  1047),  INT16_C( 26658), -INT16_C(  5880),  INT16_C( 25898),  INT16_C(  3419),  INT16_C(  5553), -INT16_C( 20873), -INT16_C( 16632),
      -INT16_C(  4711),  INT16_C(  1102), -INT16_C( 19683), -INT16_C( 17660),  INT16_C(  4429),  INT16_C(  3085),  INT16_C( 19945), -INT16_C( 11617),
      -INT16_C( 16056),  INT16_C( 20538),  INT16_C( 25770),  INT16_C(  1461),  INT16_C( 26481), -INT16_C(  5861),  INT16_C(  8981), -INT16_C( 20824),
      -INT16_C(  2287),  INT16_C( 11955), -INT16_C( 18518), -INT16_C(  1815), -INT16_C(  2103), -INT16_C( 19964), -INT16_C( 23484), -INT16_C( 29564),
      -INT16_C( 16539),  INT16_C(  4316), -INT16_C( 28125), -INT16_C( 27371),  INT16_C( 12537),  INT16_C(  3710),  INT16_C(  9812),  INT16_C( 26044),
       INT16_C( 28445), -INT16_C( 14189),  INT16_C( 31783), -INT16_C(  3904), -INT16_C( 15245), -INT16_C( 18526),  INT16_C(  9832), -INT16_C( 12733),
       INT16_C(  8421),  INT16_C(  2526), -INT16_C(  3150), -INT16_C( 21602),  INT16_C(  7204),  INT16_C( 30905),  INT16_C( 30018),  INT16_C( 24797),
       INT16_C( 28901),  INT16_C(  3112), -INT16_C(  5908),  INT16_C( 24828), -INT16_C( 24916),  INT16_C(  5399),  INT16_C( 23492), -INT16_C( 21789),
      -INT16_C( 16005),  INT16_C( 11699),  INT16_C( 20916), -INT16_C( 10024), -INT16_C( 28307), -INT16_C( 20656),  INT16_C( 11526), -INT16_C(  5361),
       INT16_C( 14237), -INT16_C( 29961), -INT16_C(  3297), -INT16_C( 13078),  INT16_C(   401),  INT16_C( 22241), -INT16_C( 15268), -INT16_C( 10496),
      -INT16_C( 19579),  INT16_C( 14596), -INT16_C(  9212),  INT16_C( 28946),  INT16_C( 25197),  INT16_C( 29728),  INT16_C( 12432),  INT16_C( 11615),
       INT16_C( 22375), -INT16_C( 30793), -INT16_C( 24246), -INT16_C(  9133),  INT16_C( 13475), -INT16_C(   206),  INT16_C( 13048),  INT16_C( 32215),
      -INT16_C(  9243), -INT16_C(  5706), -INT16_C( 14152),  INT16_C(  9562),  INT16_C( 31275), -INT16_C( 17511), -INT16_C(  1622),  INT16_C(  4840),
      -INT16_C( 24496), -INT16_C( 25959), -INT16_C(  5055), -INT16_C(  7050), -INT16_C( 22496),  INT16_C(  6372), -INT16_C( 17446), -INT16_C( 16491),
       INT16_C( 19350),  INT16_C( 20136),  INT16_C(   532),  INT16_C( 16244),  INT16_C(  3453),  INT16_C( 10234), -INT16_C(  7674),  INT16_C( 22073),
      -INT16_C( 11646), -INT16_C( 15119),  INT16_C( 26558), -INT16_C(  8536), -INT16_C( 29680), -INT16_C(  5386), -INT16_C( 29881), -INT16_C(  8534),
       INT16_C( 21207), -INT16_C(  5332), -INT16_C( 24491), -INT16_C( 11734),  INT16_C(  9390), -INT16_C( 19207),  INT16_C( 13062), -INT16_C( 30453),
      -INT16_C(  1019), -INT16_C( 15283), -INT16_C(  2717),  INT16_C( 29602), -INT16_C( 26238), -INT16_C( 13986),  INT16_C(  2084), -INT16_C(  1113),
      -INT16_C( 11174), -INT16_C( 20506),  INT16_C(  4212),  INT16_C(  8833),  INT16_C( 31540),  INT16_C( 15319), -INT16_C(  7506), -INT16_C( 19516),
       INT16_C(  4574),  INT16_C( 16759),  INT16_C(  6662), -INT16_C( 30539),  INT16_C(  5043), -INT16_C( 10414), -INT16_C(  1765),  INT16_C( 30163),
      -INT16_C( 17971),  INT16_C( 16933), -INT16_C( 22838), -INT16_C(   412),  INT16_C( 15137), -INT16_C( 12487), -INT16_C(   739), -INT16_C(  1149),
      -INT16_C(  1522),  INT16_C(  5437), -INT16_C(  3564), -INT16_C( 14435), -INT16_C(  4347),  INT16_C(  8351),  INT16_C( 29417), -INT16_C( 18795),
      -INT16_C( 17877), -INT16_C(  2568),  INT16_C( 23905), -INT16_C( 32012),  INT16_C( 11672), -INT16_C( 18862), -INT16_C( 10965),  INT16_C( 14769),
      -INT16_C(  4401), -INT16_C(  7090), -INT16_C(  4896), -INT16_C(  6741),  INT16_C( 19163), -INT16_C( 15355), -INT16_C( 25668), -INT16_C(  6021),
       INT16_C( 29525), -INT16_C( 18723), -INT16_C( 11824),  INT16_C( 26937), -INT16_C( 29697),  INT16_C( 10783), -INT16_C( 12192),  INT16_C( 12131),
      -INT16_C( 19777), -INT16_C( 24813), -INT16_C( 16482),  INT16_C( 31109), -INT16_C( 30199), -INT16_C( 14786), -INT16_C( 18139),  INT16_C( 31662),
      -INT16_C( 29908), -INT16_C(   719),  INT16_C( 27229),  INT16_C( 23654), -INT16_C( 31243),  INT16_C( 21894), -INT16_C(  5803),  INT16_C(  5253),
      -INT16_C( 26469),  INT16_C( 14772),  INT16_C( 14679),  INT16_C( 25011), -INT16_C(  3645), -INT16_C(  5849), -INT16_C( 10838), -INT16_C( 10652),
      -INT16_C( 27296), -INT16_C( 16941),  INT16_C( 14592), -INT16_C(  2791), -INT16_C( 24642),  INT16_C(  5195), -INT16_C( 12151),  INT16_C(  9256),
      -INT16_C(  9112), -INT16_C( 16290),  INT16_C(  4373), -INT16_C(  9951),  INT16_C( 18434), -INT16_C( 21310),  INT16_C(  9757),  INT16_C( 32130),
       INT16_C( 22203), -INT16_C( 17605),  INT16_C( 21647),  INT16_C( 20145), -INT16_C(   780),  INT16_C( 32098), -INT16_C( 30004),  INT16_C( 13473),
      -INT16_C(   153),  INT16_C( 31988),  INT16_C(  5392),  INT16_C(  4693),  INT16_C(  5981),  INT16_C( 31422),  INT16_C( 16701), -INT16_C(  1544),
       INT16_C( 13207),  INT16_C(  9908),  INT16_C( 25991),  INT16_C( 31604), -INT16_C( 10655),  INT16_C( 11768), -INT16_C( 26015), -INT16_C( 14238),
       INT16_C( 22169), -INT16_C( 21948), -INT16_C( 26004), -INT16_C( 13892),  INT16_C( 31665), -INT16_C(  4284),  INT16_C( 15548),  INT16_C( 21480),
      -INT16_C( 25489), -INT16_C(  2439), -INT16_C(  4606),  INT16_C( 25458),  INT16_C( 27332),  INT16_C(  9617), -INT16_C(  3324), -INT16_C( 24851),
       INT16_C( 12873), -INT16_C( 19128),  INT16_C(  1228),  INT16_C( 32127), -INT16_C( 15489),  INT16_C( 15212),  INT16_C( 21759),  INT16_C( 28302),
       INT16_C(  2289), -INT16_C(  3228), -INT16_C( 10506), -INT16_C( 17834), -INT16_C(  6335),  INT16_C( 17888), -INT16_C( 12838),  INT16_C(  9443),
       INT16_C( 11263), -INT16_C( 13351),  INT16_C( 22576), -INT16_C( 20663), -INT16_C( 19173),  INT16_C(  6891),  INT16_C( 30986), -INT16_C(  1144),
      -INT16_C(  4735),  INT16_C( 30702),  INT16_C( 17603),  INT16_C(  1074),  INT16_C(  4652),  INT16_C(  1610),  INT16_C( 11743), -INT16_C(  8406),
       INT16_C(  1113), -INT16_C( 30294), -INT16_C(  3236),  INT16_C( 30776),  INT16_C(  9129), -INT16_C( 19566),  INT16_C(  7069),  INT16_C(  7854),
      -INT16_C( 25592), -INT16_C( 13418), -INT16_C( 14112),  INT16_C(  3280),  INT16_C(  6874), -INT16_C( 18157),  INT16_C( 15687), -INT16_C( 24424),
       INT16_C( 17217), -INT16_C( 25047),  INT16_C( 25142), -INT16_C(  8426), -INT16_C( 22395),  INT16_C(  8850),  INT16_C( 16579), -INT16_C( 13503),
      -INT16_C( 10276), -INT16_C( 17001),  INT16_C( 26527),  INT16_C( 31177), -INT16_C(  9087), -INT16_C( 14286), -INT16_C( 13542),  INT16_C( 23401),
      -INT16_C( 28146),  INT16_C( 17657),  INT16_C(  4084),  INT16_C( 31268), -INT16_C( 18760),  INT16_C( 31644), -INT16_C(  8713), -INT16_C( 11449),
      -INT16_C(  8524),  INT16_C( 21392),  INT16_C( 23109), -INT16_C( 14644), -INT16_C(   202),  INT16_C( 20622), -INT16_C(  2102), -INT16_C( 10068),
      -INT16_C( 23158),  INT16_C( 32284),  INT16_C( 16565),  INT16_C( 28152), -INT16_C( 27145), -INT16_C(  4376),  INT16_C( 12146),  INT16_C( 10177),
       INT16_C( 21005),  INT16_C( 21114),  INT16_C( 18348), -INT16_C(  7656), -INT16_C( 22714),  INT16_C(  4147), -INT16_C(  8290),  INT16_C( 10472),
       INT16_C(  1156),  INT16_C( 14759), -INT16_C( 24763),  INT16_C( 15526), -INT16_C( 28876), -INT16_C( 22742), -INT16_C(  5186), -INT16_C( 13106),
       INT16_C( 18493), -INT16_C(  5858),  INT16_C( 14223), -INT16_C( 10804), -INT16_C(    34),  INT16_C( 31973), -INT16_C( 12834),  INT16_C( 25253),
       INT16_C( 19666),  INT16_C(  6044),  INT16_C( 17131),  INT16_C(  8275),  INT16_C( 32209), -INT16_C( 28473), -INT16_C( 27288), -INT16_C( 22948),
       INT16_C( 31453),  INT16_C( 28047),  INT16_C( 23473), -INT16_C( 28862),  INT16_C( 10330),  INT16_C( 14348), -INT16_C( 19979), -INT16_C( 14437),
       INT16_C( 14333), -INT16_C(  5922),  INT16_C( 12665),  INT16_C( 19208), -INT16_C( 12370),  INT16_C(  6107),  INT16_C( 14180),  INT16_C( 17085),
       INT16_C( 19633),  INT16_C( 25519), -INT16_C(  3672),  INT16_C(   754), -INT16_C(   487) };
  static const int16_t b = -INT16_C(   432);
  static const int16_t e[] =
    {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21437),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(   615),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 16200),
       INT16_C(     0),  INT16_C(  1534),  INT16_C(     0),  INT16_C(     0),  INT16_C(  4861),  INT16_C(  3517),  INT16_C(     0), -INT16_C( 11185),
      -INT16_C( 15624),  INT16_C(     0),  INT16_C( 26202),  INT16_C(     0),  INT16_C( 26913), -INT16_C(  5429),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(  1855),  INT16_C(     0), -INT16_C( 18086), -INT16_C(  1383),  INT16_C(     0), -INT16_C( 19532), -INT16_C( 23052), -INT16_C( 29132),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 12969),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C( 32215),  INT16_C(     0),  INT16_C(     0), -INT16_C( 18094),  INT16_C(     0), -INT16_C( 12301),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 21170),  INT16_C(     0),  INT16_C( 31337),  INT16_C(     0),  INT16_C( 25229),
       INT16_C( 29333),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 23924),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C( 21348),  INT16_C(     0), -INT16_C( 27875),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C( 14669),  INT16_C(     0), -INT16_C(  2865), -INT16_C( 12646),  INT16_C(     0),  INT16_C( 22673),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 19147),  INT16_C( 15028),  INT16_C(     0),  INT16_C(     0),  INT16_C( 25629),  INT16_C(     0),  INT16_C( 12864),  INT16_C( 12047),
       INT16_C( 22807),  INT16_C(     0), -INT16_C( 23814), -INT16_C(  8701),  INT16_C(     0),  INT16_C(   226),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(  5274),  INT16_C(     0),  INT16_C(     0),  INT16_C( 31707), -INT16_C( 17079),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 24064), -INT16_C( 25527), -INT16_C(  4623),  INT16_C(     0), -INT16_C( 22064),  INT16_C(     0), -INT16_C( 17014),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(   964),  INT16_C( 16676),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 22505),
       INT16_C(     0), -INT16_C( 14687),  INT16_C( 26990),  INT16_C(     0), -INT16_C( 29248), -INT16_C(  4954), -INT16_C( 29449), -INT16_C(  8102),
       INT16_C( 21639),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 30021),
       INT16_C(     0), -INT16_C( 14851),  INT16_C(     0),  INT16_C( 30034),  INT16_C(     0), -INT16_C( 13554),  INT16_C(  2516),  INT16_C(     0),
      -INT16_C( 10742), -INT16_C( 20074),  INT16_C(     0),  INT16_C(  9265),  INT16_C( 31972),  INT16_C( 15751), -INT16_C(  7074), -INT16_C( 19084),
       INT16_C(  5006),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  5475), -INT16_C(  9982),  INT16_C(     0),  INT16_C( 30595),
      -INT16_C( 17539),  INT16_C(     0), -INT16_C( 22406),  INT16_C(     0),  INT16_C(     0), -INT16_C( 12055),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(  1090),  INT16_C(  5869),  INT16_C(     0), -INT16_C( 14003),  INT16_C(     0),  INT16_C(     0),  INT16_C( 29849),  INT16_C(     0),
      -INT16_C( 17445),  INT16_C(     0),  INT16_C(     0), -INT16_C( 31580),  INT16_C(     0), -INT16_C( 18430),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(  3969), -INT16_C(  6658),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14923), -INT16_C( 25236), -INT16_C(  5589),
       INT16_C(     0), -INT16_C( 18291), -INT16_C( 11392),  INT16_C(     0),  INT16_C(     0),  INT16_C( 11215),  INT16_C(     0),  INT16_C( 12563),
      -INT16_C( 19345), -INT16_C( 24381),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14354),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 29476), -INT16_C(   287),  INT16_C(     0),  INT16_C( 24086), -INT16_C( 30811),  INT16_C(     0), -INT16_C(  5371),  INT16_C(  5685),
      -INT16_C( 26037),  INT16_C( 15204),  INT16_C( 15111),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 10406),  INT16_C(     0),
      -INT16_C( 26864),  INT16_C(     0),  INT16_C( 15024),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C( 15858),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 20878),  INT16_C(     0),  INT16_C(     0),
       INT16_C( 22635), -INT16_C( 17173),  INT16_C(     0),  INT16_C( 20577),  INT16_C(     0),  INT16_C( 32530),  INT16_C(     0),  INT16_C( 13905),
       INT16_C(     0),  INT16_C(     0),  INT16_C(  5824),  INT16_C(  5125),  INT16_C(  6413),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C( 10340),  INT16_C( 26423),  INT16_C(     0), -INT16_C( 10223),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C( 25572),  INT16_C(     0),  INT16_C( 32097),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21912),
      -INT16_C( 25057), -INT16_C(  2007),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 10049), -INT16_C(  2892),  INT16_C(     0),
       INT16_C( 13305),  INT16_C(     0),  INT16_C(  1660),  INT16_C( 32559),  INT16_C(     0),  INT16_C( 15644),  INT16_C(     0),  INT16_C( 28734),
       INT16_C(     0), -INT16_C(  2796), -INT16_C( 10074),  INT16_C(     0), -INT16_C(  5903),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C( 11695),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 31418),  INT16_C(     0),
      -INT16_C(  4303),  INT16_C( 31134),  INT16_C( 18035),  INT16_C(  1506),  INT16_C(  5084),  INT16_C(  2042),  INT16_C( 12175),  INT16_C(     0),
       INT16_C(  1545), -INT16_C( 29862), -INT16_C(  2804),  INT16_C( 31208),  INT16_C(  9561),  INT16_C(     0),  INT16_C(  7501),  INT16_C(     0),
      -INT16_C( 25160),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  7306),  INT16_C(     0),  INT16_C( 16119), -INT16_C( 23992),
       INT16_C( 17649), -INT16_C( 24615),  INT16_C(     0), -INT16_C(  7994), -INT16_C( 21963),  INT16_C(  9282),  INT16_C( 17011),  INT16_C(     0),
       INT16_C(     0), -INT16_C( 16569),  INT16_C(     0),  INT16_C(     0), -INT16_C(  8655),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C( 18089),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 32076),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(  8092),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21054),  INT16_C(     0), -INT16_C(  9636),
       INT16_C(     0),  INT16_C( 32716),  INT16_C( 16997),  INT16_C(     0), -INT16_C( 26713),  INT16_C(     0),  INT16_C(     0),  INT16_C( 10609),
       INT16_C( 21437),  INT16_C( 21546),  INT16_C(     0), -INT16_C(  7224),  INT16_C(     0),  INT16_C(     0), -INT16_C(  7858),  INT16_C( 10904),
       INT16_C(     0),  INT16_C(     0), -INT16_C( 24331),  INT16_C(     0), -INT16_C( 28444),  INT16_C(     0), -INT16_C(  4754),  INT16_C(     0),
       INT16_C(     0), -INT16_C(  5426),  INT16_C( 14655),  INT16_C(     0),  INT16_C(     0),  INT16_C( 32405), -INT16_C( 12402),  INT16_C(     0),
       INT16_C( 20098),  INT16_C(  6476),  INT16_C(     0),  INT16_C(  8707),  INT16_C(     0), -INT16_C( 28041),  INT16_C(     0), -INT16_C( 22516),
       INT16_C(     0),  INT16_C( 28479),  INT16_C( 23905),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 19547),  INT16_C(     0),
       INT16_C(     0), -INT16_C(  5490),  INT16_C(     0),  INT16_C( 19640), -INT16_C( 11938),  INT16_C(     0),  INT16_C( 14612),  INT16_C( 17517),
       INT16_C( 20065),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(    55) };

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
    rv = simde_svsub_n_s16_z(pv, av, b);

    simde_svst1_s16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vi16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(int16_t)], a[1024 / sizeof(int16_t)], b, e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i16();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_s16(pg, &(a[i]));

    ev = simde_svsub_n_s16_z(pv, av, b);

    simde_svst1_s16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i16(1, b);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_s16_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) };
  static const int16_t a[] =
    {  INT16_C( 23505), -INT16_C( 10587), -INT16_C(  8932), -INT16_C( 12956), -INT16_C( 19812), -INT16_C(  9727), -INT16_C( 15388), -INT16_C( 19537),
       INT16_C( 28249),  INT16_C( 18317),  INT16_C( 26610),  INT16_C( 31901),  INT16_C( 19673), -INT16_C( 28698), -INT16_C( 20380),  INT16_C( 13703),
       INT16_C( 11532),  INT16_C( 10251),  INT16_C( 28682), -INT16_C( 22539), -INT16_C(  2526),  INT16_C(  1921),  INT16_C( 12474),  INT16_C(  5050),
       INT16_C( 18334), -INT16_C( 28326), -INT16_C(  2130), -INT16_C( 30963), -INT16_C(  3261), -INT16_C( 22761), -INT16_C( 24924), -INT16_C( 20260),
      -INT16_C(  5941), -INT16_C( 10536), -INT16_C( 12968),  INT16_C( 31357), -INT16_C(   317),  INT16_C( 32129),  INT16_C( 15150), -INT16_C( 12911),
      -INT16_C(  5246),  INT16_C( 12382),  INT16_C( 27619),  INT16_C(  9912), -INT16_C( 12450),  INT16_C(   718), -INT16_C( 21907),  INT16_C( 14770),
      -INT16_C( 30062), -INT16_C(  5617), -INT16_C( 29609),  INT16_C(  7013), -INT16_C(  6518), -INT16_C( 18280),  INT16_C( 10530), -INT16_C( 23419),
      -INT16_C(  7403), -INT16_C(  1835), -INT16_C( 29362), -INT16_C( 21218), -INT16_C(  5028), -INT16_C( 13905),  INT16_C( 25239),  INT16_C( 10498),
       INT16_C(  4588),  INT16_C( 17428),  INT16_C( 31133),  INT16_C( 10079), -INT16_C(  2209), -INT16_C( 32288),  INT16_C( 25889),  INT16_C( 13862),
      -INT16_C(  1207), -INT16_C( 26834),  INT16_C( 19592), -INT16_C(  7100), -INT16_C(  3015), -INT16_C( 12115), -INT16_C( 20394),  INT16_C( 17145),
       INT16_C(  3521),  INT16_C( 24454), -INT16_C(  6778), -INT16_C(  6522),  INT16_C( 26333), -INT16_C(   409), -INT16_C( 29236),  INT16_C(  5428),
       INT16_C( 25224),  INT16_C(  4268), -INT16_C(  3666), -INT16_C(  6156), -INT16_C( 23835),  INT16_C( 15287), -INT16_C( 20142),  INT16_C(  4989),
       INT16_C(  1214),  INT16_C( 17778), -INT16_C(  1559), -INT16_C( 14805), -INT16_C( 28065),  INT16_C( 11204), -INT16_C(  2016), -INT16_C( 22464),
      -INT16_C(  4774),  INT16_C(  2489), -INT16_C( 21026), -INT16_C( 15376), -INT16_C( 22449), -INT16_C( 24066),  INT16_C( 31577),  INT16_C(  6069),
       INT16_C( 10111),  INT16_C( 26972), -INT16_C( 30944), -INT16_C( 32721), -INT16_C(  3046),  INT16_C( 15019), -INT16_C(  4884),  INT16_C( 18402),
      -INT16_C( 25639), -INT16_C( 18608),  INT16_C( 16457), -INT16_C( 26502),  INT16_C( 30952),  INT16_C( 16698), -INT16_C(  4109),  INT16_C( 29529),
      -INT16_C( 19178),  INT16_C( 14300),  INT16_C(  2877),  INT16_C( 22455),  INT16_C( 25343), -INT16_C(  4975),  INT16_C( 29518),  INT16_C( 10035),
      -INT16_C( 31985),  INT16_C( 22750),  INT16_C( 22723), -INT16_C( 21264),  INT16_C( 10960), -INT16_C( 15123),  INT16_C( 17945),  INT16_C( 12343),
       INT16_C(  5116),  INT16_C( 14695),  INT16_C(  7710),  INT16_C(  7824),  INT16_C(  8576), -INT16_C( 12534),  INT16_C( 15764), -INT16_C( 23562),
      -INT16_C( 10816), -INT16_C( 31749), -INT16_C(  5075), -INT16_C(   465),  INT16_C(  7446),  INT16_C( 12482), -INT16_C(  1693),  INT16_C( 24416),
      -INT16_C( 14580),  INT16_C( 10904),  INT16_C( 10469),  INT16_C( 25928),  INT16_C( 21065), -INT16_C(  8652),  INT16_C( 11151),  INT16_C( 20353),
       INT16_C( 32000),  INT16_C( 11731),  INT16_C(   617),  INT16_C( 32555), -INT16_C(  4833), -INT16_C( 31825),  INT16_C(  4070), -INT16_C(  3358),
       INT16_C( 31702), -INT16_C( 17635),  INT16_C( 26019), -INT16_C(  4831),  INT16_C( 21944),  INT16_C( 18379),  INT16_C( 19584), -INT16_C( 32617),
       INT16_C( 27337),  INT16_C( 12974), -INT16_C(  9876), -INT16_C( 29518),  INT16_C( 25031), -INT16_C( 21233), -INT16_C(  3727),  INT16_C( 18336),
      -INT16_C( 17044),  INT16_C(  4099),  INT16_C(  9250), -INT16_C(  9475), -INT16_C( 14215), -INT16_C(  1502), -INT16_C( 18156), -INT16_C(  8582),
       INT16_C( 10275), -INT16_C( 28912), -INT16_C( 15870), -INT16_C( 14053),  INT16_C( 10788), -INT16_C( 27274),  INT16_C(  5660), -INT16_C( 30500),
      -INT16_C(  8237), -INT16_C(  2408), -INT16_C( 27389),  INT16_C( 32208), -INT16_C(  3491),  INT16_C( 29303), -INT16_C(  3669), -INT16_C( 12720),
       INT16_C( 24602),  INT16_C(  7262),  INT16_C( 31011),  INT16_C( 18405),  INT16_C( 23460), -INT16_C( 16164), -INT16_C( 18318),  INT16_C( 17736),
      -INT16_C(  7784), -INT16_C( 25797),  INT16_C(  3190), -INT16_C( 11240), -INT16_C( 28674), -INT16_C( 21946), -INT16_C( 27007), -INT16_C( 25736),
      -INT16_C( 10506),  INT16_C(  6583), -INT16_C( 25520), -INT16_C(  2976),  INT16_C( 15607),  INT16_C( 27060), -INT16_C(   779), -INT16_C( 29265),
      -INT16_C(  5411),  INT16_C( 21544),  INT16_C( 16886), -INT16_C(  2776),  INT16_C( 28368),  INT16_C( 20895),  INT16_C(  5892), -INT16_C(  1300),
      -INT16_C( 23570),  INT16_C( 15892),  INT16_C( 29759),  INT16_C( 14130), -INT16_C(  6479), -INT16_C( 22880),  INT16_C( 20450), -INT16_C( 16333),
       INT16_C( 23354),  INT16_C( 12308),  INT16_C( 15516),  INT16_C( 27941), -INT16_C( 15190), -INT16_C( 20802), -INT16_C( 21540), -INT16_C( 13656),
      -INT16_C( 17330), -INT16_C( 29176),  INT16_C( 14897), -INT16_C(  7483),  INT16_C( 25888),  INT16_C(   648), -INT16_C( 17483), -INT16_C(  4158),
      -INT16_C( 10730), -INT16_C( 19681),  INT16_C( 17682), -INT16_C( 17376), -INT16_C(  8695), -INT16_C(  6806),  INT16_C(  5001), -INT16_C( 10065),
      -INT16_C( 18481),  INT16_C(   102),  INT16_C( 11249),  INT16_C(  4578),  INT16_C( 27280),  INT16_C( 17684), -INT16_C( 10715),  INT16_C( 15412),
       INT16_C( 21677), -INT16_C( 16401),  INT16_C(  3993), -INT16_C( 23940), -INT16_C(  6419),  INT16_C( 30600),  INT16_C( 14329), -INT16_C( 14001),
      -INT16_C( 18961), -INT16_C(  7991), -INT16_C( 21280),  INT16_C( 28914),  INT16_C(  1558),  INT16_C( 15542), -INT16_C(  5412), -INT16_C( 30344),
       INT16_C( 26430), -INT16_C( 10423), -INT16_C( 14986),  INT16_C( 25466),  INT16_C(   683), -INT16_C( 23078),  INT16_C( 10553),  INT16_C( 10350),
       INT16_C( 14302), -INT16_C( 16887), -INT16_C(  1053), -INT16_C(  1489), -INT16_C(  6911), -INT16_C(  8906), -INT16_C( 20785),  INT16_C(  3687),
      -INT16_C( 20459), -INT16_C( 29723),  INT16_C( 24437),  INT16_C(  8430), -INT16_C( 13983), -INT16_C( 25659),  INT16_C( 13298), -INT16_C( 11837),
      -INT16_C( 13205),  INT16_C( 20111), -INT16_C( 16697), -INT16_C( 14264),  INT16_C( 32419),  INT16_C( 29606),  INT16_C(  3372),  INT16_C( 16769),
       INT16_C( 26301),  INT16_C( 13004), -INT16_C( 17466),  INT16_C( 10066),  INT16_C(  6276),  INT16_C( 30402), -INT16_C( 31157), -INT16_C( 18873),
      -INT16_C( 10414),  INT16_C(  6661),  INT16_C( 19861),  INT16_C( 14818), -INT16_C( 30516), -INT16_C(  1876),  INT16_C( 11669),  INT16_C( 21050),
       INT16_C(  1683),  INT16_C( 22916), -INT16_C( 10303),  INT16_C( 17793),  INT16_C( 17391),  INT16_C( 15036),  INT16_C(   969),  INT16_C(  7409),
      -INT16_C(  2342),  INT16_C( 28726),  INT16_C(  6211),  INT16_C(  4009),  INT16_C( 21921),  INT16_C( 13832),  INT16_C( 17026),  INT16_C(  5513),
       INT16_C(  3400),  INT16_C(  2671), -INT16_C(  3868), -INT16_C( 11441),  INT16_C(  2867), -INT16_C(   754), -INT16_C(   241), -INT16_C(  5863),
       INT16_C( 20469),  INT16_C( 14425),  INT16_C(   615),  INT16_C(  2120),  INT16_C( 20567), -INT16_C(  9921), -INT16_C( 14190), -INT16_C(  9489),
       INT16_C( 24277), -INT16_C( 17692),  INT16_C( 13390), -INT16_C( 32371), -INT16_C( 25793),  INT16_C( 20094), -INT16_C( 26726), -INT16_C( 28872),
      -INT16_C( 28186),  INT16_C( 20168),  INT16_C(  4244), -INT16_C(  5290), -INT16_C( 27296), -INT16_C(  3387), -INT16_C( 19363),  INT16_C( 13260),
      -INT16_C( 20206),  INT16_C( 24813),  INT16_C( 31461),  INT16_C(  9441),  INT16_C( 24598), -INT16_C( 20365), -INT16_C( 21513), -INT16_C(  8640),
       INT16_C(  2108), -INT16_C( 12244), -INT16_C( 32232),  INT16_C( 30908), -INT16_C( 32488),  INT16_C( 30058),  INT16_C( 13877),  INT16_C( 18344),
      -INT16_C( 27161), -INT16_C( 13145), -INT16_C( 30704),  INT16_C(  9969),  INT16_C( 25832), -INT16_C(  7978),  INT16_C(  5647),  INT16_C( 19390),
      -INT16_C(  5602),  INT16_C( 13852), -INT16_C( 10132), -INT16_C( 31570),  INT16_C(  6233), -INT16_C( 28934), -INT16_C( 23985),  INT16_C( 14037),
       INT16_C( 31800),  INT16_C( 18435), -INT16_C(  3068), -INT16_C(  4754),  INT16_C( 17496),  INT16_C( 26573), -INT16_C( 29861),  INT16_C( 31154),
      -INT16_C( 12683), -INT16_C(  7760),  INT16_C( 24230), -INT16_C(   154),  INT16_C( 24695), -INT16_C( 14707),  INT16_C( 25090),  INT16_C( 15100),
      -INT16_C(    34), -INT16_C(  7294), -INT16_C(  3853),  INT16_C( 19408), -INT16_C( 25291), -INT16_C( 28494),  INT16_C( 25896), -INT16_C( 25335),
      -INT16_C( 18125), -INT16_C(  9602), -INT16_C(  7144), -INT16_C( 28711),  INT16_C( 26436),  INT16_C( 18261),  INT16_C( 20937), -INT16_C( 22399) };
  static const int16_t b =  INT16_C(  8238);
  static const int16_t e[] =
    {  INT16_C( 23505), -INT16_C( 18825), -INT16_C( 17170), -INT16_C( 12956), -INT16_C( 19812), -INT16_C( 17965), -INT16_C( 15388), -INT16_C( 27775),
       INT16_C( 20011),  INT16_C( 10079),  INT16_C( 18372),  INT16_C( 23663),  INT16_C( 19673),  INT16_C( 28600), -INT16_C( 28618),  INT16_C(  5465),
       INT16_C( 11532),  INT16_C( 10251),  INT16_C( 28682), -INT16_C( 30777), -INT16_C(  2526),  INT16_C(  1921),  INT16_C(  4236), -INT16_C(  3188),
       INT16_C( 18334),  INT16_C( 28972), -INT16_C( 10368), -INT16_C( 30963), -INT16_C( 11499), -INT16_C( 22761), -INT16_C( 24924), -INT16_C( 28498),
      -INT16_C( 14179), -INT16_C( 10536), -INT16_C( 12968),  INT16_C( 31357), -INT16_C(  8555),  INT16_C( 32129),  INT16_C( 15150), -INT16_C( 21149),
      -INT16_C( 13484),  INT16_C(  4144),  INT16_C( 19381),  INT16_C(  9912), -INT16_C( 20688), -INT16_C(  7520), -INT16_C( 30145),  INT16_C(  6532),
      -INT16_C( 30062), -INT16_C( 13855),  INT16_C( 27689),  INT16_C(  7013), -INT16_C( 14756), -INT16_C( 26518),  INT16_C(  2292), -INT16_C( 23419),
      -INT16_C(  7403), -INT16_C( 10073),  INT16_C( 27936), -INT16_C( 21218), -INT16_C( 13266), -INT16_C( 13905),  INT16_C( 25239),  INT16_C(  2260),
       INT16_C(  4588),  INT16_C( 17428),  INT16_C( 22895),  INT16_C(  1841), -INT16_C( 10447),  INT16_C( 25010),  INT16_C( 17651),  INT16_C(  5624),
      -INT16_C(  1207), -INT16_C( 26834),  INT16_C( 11354), -INT16_C( 15338), -INT16_C(  3015), -INT16_C( 12115), -INT16_C( 28632),  INT16_C(  8907),
      -INT16_C(  4717),  INT16_C( 24454), -INT16_C(  6778), -INT16_C( 14760),  INT16_C( 18095), -INT16_C(   409),  INT16_C( 28062), -INT16_C(  2810),
       INT16_C( 25224),  INT16_C(  4268), -INT16_C(  3666), -INT16_C( 14394), -INT16_C( 32073),  INT16_C(  7049), -INT16_C( 28380),  INT16_C(  4989),
       INT16_C(  1214),  INT16_C(  9540), -INT16_C(  9797), -INT16_C( 14805), -INT16_C( 28065),  INT16_C( 11204), -INT16_C( 10254), -INT16_C( 30702),
      -INT16_C( 13012),  INT16_C(  2489), -INT16_C( 29264), -INT16_C( 15376), -INT16_C( 30687), -INT16_C( 24066),  INT16_C( 31577),  INT16_C(  6069),
       INT16_C(  1873),  INT16_C( 18734),  INT16_C( 26354), -INT16_C( 32721), -INT16_C( 11284),  INT16_C( 15019), -INT16_C(  4884),  INT16_C( 18402),
       INT16_C( 31659), -INT16_C( 18608),  INT16_C(  8219),  INT16_C( 30796),  INT16_C( 22714),  INT16_C( 16698), -INT16_C( 12347),  INT16_C( 21291),
      -INT16_C( 27416),  INT16_C(  6062), -INT16_C(  5361),  INT16_C( 14217),  INT16_C( 17105), -INT16_C(  4975),  INT16_C( 21280),  INT16_C( 10035),
      -INT16_C( 31985),  INT16_C( 22750),  INT16_C( 14485), -INT16_C( 21264),  INT16_C( 10960), -INT16_C( 23361),  INT16_C( 17945),  INT16_C( 12343),
       INT16_C(  5116),  INT16_C(  6457), -INT16_C(   528), -INT16_C(   414),  INT16_C(  8576), -INT16_C( 20772),  INT16_C( 15764), -INT16_C( 23562),
      -INT16_C( 10816),  INT16_C( 25549), -INT16_C( 13313), -INT16_C(   465), -INT16_C(   792),  INT16_C(  4244), -INT16_C(  9931),  INT16_C( 24416),
      -INT16_C( 14580),  INT16_C( 10904),  INT16_C( 10469),  INT16_C( 17690),  INT16_C( 12827), -INT16_C( 16890),  INT16_C(  2913),  INT16_C( 20353),
       INT16_C( 32000),  INT16_C(  3493),  INT16_C(   617),  INT16_C( 32555), -INT16_C( 13071),  INT16_C( 25473),  INT16_C(  4070), -INT16_C(  3358),
       INT16_C( 31702), -INT16_C( 17635),  INT16_C( 17781), -INT16_C( 13069),  INT16_C( 21944),  INT16_C( 18379),  INT16_C( 19584), -INT16_C( 32617),
       INT16_C( 27337),  INT16_C(  4736), -INT16_C(  9876),  INT16_C( 27780),  INT16_C( 25031), -INT16_C( 21233), -INT16_C(  3727),  INT16_C( 10098),
      -INT16_C( 17044), -INT16_C(  4139),  INT16_C(  1012), -INT16_C(  9475), -INT16_C( 22453), -INT16_C(  9740), -INT16_C( 26394), -INT16_C(  8582),
       INT16_C(  2037),  INT16_C( 28386), -INT16_C( 24108), -INT16_C( 22291),  INT16_C(  2550),  INT16_C( 30024), -INT16_C(  2578),  INT16_C( 26798),
      -INT16_C(  8237), -INT16_C( 10646),  INT16_C( 29909),  INT16_C( 23970), -INT16_C( 11729),  INT16_C( 21065), -INT16_C(  3669), -INT16_C( 20958),
       INT16_C( 16364),  INT16_C(  7262),  INT16_C( 31011),  INT16_C( 18405),  INT16_C( 23460), -INT16_C( 16164), -INT16_C( 26556),  INT16_C( 17736),
      -INT16_C(  7784), -INT16_C( 25797),  INT16_C(  3190), -INT16_C( 11240), -INT16_C( 28674), -INT16_C( 30184), -INT16_C( 27007),  INT16_C( 31562),
      -INT16_C( 10506),  INT16_C(  6583), -INT16_C( 25520), -INT16_C(  2976),  INT16_C(  7369),  INT16_C( 18822), -INT16_C(  9017),  INT16_C( 28033),
      -INT16_C( 13649),  INT16_C( 21544),  INT16_C( 16886), -INT16_C(  2776),  INT16_C( 20130),  INT16_C( 20895),  INT16_C(  5892), -INT16_C(  1300),
      -INT16_C( 31808),  INT16_C(  7654),  INT16_C( 29759),  INT16_C(  5892), -INT16_C( 14717), -INT16_C( 31118),  INT16_C( 12212), -INT16_C( 24571),
       INT16_C( 23354),  INT16_C(  4070),  INT16_C(  7278),  INT16_C( 27941), -INT16_C( 23428), -INT16_C( 20802), -INT16_C( 21540), -INT16_C( 13656),
      -INT16_C( 25568), -INT16_C( 29176),  INT16_C(  6659), -INT16_C(  7483),  INT16_C( 25888),  INT16_C(   648), -INT16_C( 25721), -INT16_C(  4158),
      -INT16_C( 18968), -INT16_C( 19681),  INT16_C( 17682), -INT16_C( 25614), -INT16_C(  8695), -INT16_C(  6806),  INT16_C(  5001), -INT16_C( 10065),
      -INT16_C( 18481), -INT16_C(  8136),  INT16_C(  3011),  INT16_C(  4578),  INT16_C( 19042),  INT16_C(  9446), -INT16_C( 10715),  INT16_C(  7174),
       INT16_C( 13439), -INT16_C( 24639),  INT16_C(  3993), -INT16_C( 23940), -INT16_C( 14657),  INT16_C( 30600),  INT16_C( 14329), -INT16_C( 22239),
      -INT16_C( 27199), -INT16_C(  7991), -INT16_C( 21280),  INT16_C( 28914), -INT16_C(  6680),  INT16_C( 15542), -INT16_C(  5412), -INT16_C( 30344),
       INT16_C( 26430), -INT16_C( 10423), -INT16_C( 23224),  INT16_C( 17228),  INT16_C(   683), -INT16_C( 31316),  INT16_C(  2315),  INT16_C(  2112),
       INT16_C( 14302), -INT16_C( 16887), -INT16_C(  1053), -INT16_C(  1489), -INT16_C(  6911), -INT16_C( 17144), -INT16_C( 29023), -INT16_C(  4551),
      -INT16_C( 20459),  INT16_C( 27575),  INT16_C( 16199),  INT16_C(  8430), -INT16_C( 22221), -INT16_C( 25659),  INT16_C( 13298), -INT16_C( 11837),
      -INT16_C( 13205),  INT16_C( 20111), -INT16_C( 24935), -INT16_C( 22502),  INT16_C( 24181),  INT16_C( 21368),  INT16_C(  3372),  INT16_C( 16769),
       INT16_C( 26301),  INT16_C(  4766), -INT16_C( 25704),  INT16_C(  1828), -INT16_C(  1962),  INT16_C( 30402), -INT16_C( 31157), -INT16_C( 27111),
      -INT16_C( 18652),  INT16_C(  6661),  INT16_C( 11623),  INT16_C(  6580), -INT16_C( 30516), -INT16_C( 10114),  INT16_C(  3431),  INT16_C( 12812),
       INT16_C(  1683),  INT16_C( 22916), -INT16_C( 10303),  INT16_C(  9555),  INT16_C( 17391),  INT16_C( 15036), -INT16_C(  7269),  INT16_C(  7409),
      -INT16_C(  2342),  INT16_C( 28726), -INT16_C(  2027),  INT16_C(  4009),  INT16_C( 21921),  INT16_C(  5594),  INT16_C( 17026),  INT16_C(  5513),
      -INT16_C(  4838),  INT16_C(  2671), -INT16_C( 12106), -INT16_C( 11441),  INT16_C(  2867), -INT16_C(  8992), -INT16_C(  8479), -INT16_C( 14101),
       INT16_C( 12231),  INT16_C( 14425), -INT16_C(  7623),  INT16_C(  2120),  INT16_C( 12329), -INT16_C( 18159), -INT16_C( 22428), -INT16_C(  9489),
       INT16_C( 16039), -INT16_C( 25930),  INT16_C(  5152), -INT16_C( 32371), -INT16_C( 25793),  INT16_C( 11856), -INT16_C( 26726), -INT16_C( 28872),
      -INT16_C( 28186),  INT16_C( 11930), -INT16_C(  3994), -INT16_C( 13528),  INT16_C( 30002), -INT16_C( 11625), -INT16_C( 19363),  INT16_C(  5022),
      -INT16_C( 28444),  INT16_C( 24813),  INT16_C( 23223),  INT16_C(  9441),  INT16_C( 16360), -INT16_C( 28603), -INT16_C( 21513), -INT16_C( 16878),
       INT16_C(  2108), -INT16_C( 20482), -INT16_C( 32232),  INT16_C( 22670),  INT16_C( 24810),  INT16_C( 30058),  INT16_C( 13877),  INT16_C( 10106),
       INT16_C( 30137), -INT16_C( 21383),  INT16_C( 26594),  INT16_C(  9969),  INT16_C( 17594), -INT16_C( 16216),  INT16_C(  5647),  INT16_C( 19390),
      -INT16_C( 13840),  INT16_C(  5614), -INT16_C( 18370),  INT16_C( 25728),  INT16_C(  6233),  INT16_C( 28364), -INT16_C( 32223),  INT16_C( 14037),
       INT16_C( 31800),  INT16_C( 10197), -INT16_C( 11306), -INT16_C( 12992),  INT16_C( 17496),  INT16_C( 18335), -INT16_C( 29861),  INT16_C( 31154),
      -INT16_C( 20921), -INT16_C(  7760),  INT16_C( 15992), -INT16_C(   154),  INT16_C( 24695), -INT16_C( 14707),  INT16_C( 25090),  INT16_C( 15100),
      -INT16_C(    34), -INT16_C(  7294), -INT16_C(  3853),  INT16_C( 11170),  INT16_C( 32007),  INT16_C( 28804),  INT16_C( 17658),  INT16_C( 31963),
      -INT16_C( 18125), -INT16_C( 17840), -INT16_C(  7144), -INT16_C( 28711),  INT16_C( 18198),  INT16_C( 18261),  INT16_C( 12699), -INT16_C( 22399) };

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
    rv = simde_svsub_n_s16_m(pv, av, b);

    simde_svst1_s16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vi16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(int16_t)], a[1024 / sizeof(int16_t)], b, e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i16();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_s16(pg, &(a[i]));

    ev = simde_svsub_n_s16_m(pv, av, b);

    simde_svst1_s16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i16(1, b);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_s32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) };
  static const int32_t a[] =
    {  INT32_C(   354256396),  INT32_C(  1923075788), -INT32_C(  1887949867),  INT32_C(  1407268495),  INT32_C(   924770712), -INT32_C(   693799014), -INT32_C(  1689619945),  INT32_C(  1946065767),
      -INT32_C(   293070047), -INT32_C(  1084217111), -INT32_C(   498149293), -INT32_C(  1489686769), -INT32_C(  1411493104), -INT32_C(   494828597),  INT32_C(  1568590838), -INT32_C(  1999602586),
      -INT32_C(  2122950248), -INT32_C(   733948287), -INT32_C(  1095266385), -INT32_C(   815403842),  INT32_C(   192562240), -INT32_C(  1108476985),  INT32_C(   756706246), -INT32_C(  2135561240),
      -INT32_C(   989779132), -INT32_C(  1332133375), -INT32_C(  1888595759),  INT32_C(  2103366717), -INT32_C(   544679912), -INT32_C(  1700956717), -INT32_C(   909658143), -INT32_C(   431391582),
      -INT32_C(  1465169241),  INT32_C(  1566131596), -INT32_C(   756168811), -INT32_C(  1286648933), -INT32_C(   141306076),  INT32_C(   781267021), -INT32_C(  1963501337),  INT32_C(  2070954196),
       INT32_C(   388242570), -INT32_C(   160137887), -INT32_C(   523673276), -INT32_C(   778889043),  INT32_C(  1036527344),  INT32_C(  1047222870), -INT32_C(  2016910670),  INT32_C(   738343074),
      -INT32_C(  1253890476), -INT32_C(   391333725), -INT32_C(   959941351),  INT32_C(  2107071373), -INT32_C(   658874238),  INT32_C(  1813390778),  INT32_C(   703848071),  INT32_C(  1800861207),
      -INT32_C(  1071539940),  INT32_C(  1806224721), -INT32_C(   818843582),  INT32_C(  1296943563), -INT32_C(   484047063), -INT32_C(  1269875667),  INT32_C(   853426971),  INT32_C(  1436365881),
       INT32_C(   521518797), -INT32_C(   846545525), -INT32_C(   107103443), -INT32_C(  1387861372),  INT32_C(   512781553), -INT32_C(   992747351),  INT32_C(  1559671075), -INT32_C(  1296985115),
      -INT32_C(   573454510), -INT32_C(  1297392764), -INT32_C(  1683273705),  INT32_C(   592048434),  INT32_C(   121821534), -INT32_C(   590670407), -INT32_C(  1422343738), -INT32_C(  1503794604),
       INT32_C(   897855409), -INT32_C(  1578684534), -INT32_C(  1455582601), -INT32_C(   489912700),  INT32_C(   434703967), -INT32_C(   369773533), -INT32_C(   913035659), -INT32_C(   915344872),
      -INT32_C(  1409354719), -INT32_C(  1706170845), -INT32_C(    62682504),  INT32_C(  1876823824),  INT32_C(  1099482910), -INT32_C(   265585029), -INT32_C(   994394196), -INT32_C(   762500431),
       INT32_C(  1098812190), -INT32_C(   354694287),  INT32_C(  1709579861),  INT32_C(  1272235309),  INT32_C(   143482252), -INT32_C(  2013742885),  INT32_C(   692826743), -INT32_C(    84158244),
      -INT32_C(   717522589), -INT32_C(  1715530172),  INT32_C(  1660855604), -INT32_C(   139603094),  INT32_C(   201275952),  INT32_C(  1788016626), -INT32_C(  2037129814),  INT32_C(   411143861),
       INT32_C(  1290648584),  INT32_C(   132558035), -INT32_C(  1133910958), -INT32_C(   407693385),  INT32_C(  1156756049),  INT32_C(  1420723370),  INT32_C(   383402337), -INT32_C(   684762161),
      -INT32_C(   349955048),  INT32_C(   468847305), -INT32_C(  1495835410), -INT32_C(   997356685), -INT32_C(   418873283),  INT32_C(  1715189252), -INT32_C(   948168969), -INT32_C(  1986090127),
      -INT32_C(  1854618936), -INT32_C(  1146329140),  INT32_C(   912360387),  INT32_C(  1291513358),  INT32_C(  1932723054), -INT32_C(  1311150151), -INT32_C(   159885947), -INT32_C(   914352639),
      -INT32_C(  1520765735),  INT32_C(   509609563), -INT32_C(  1739275895),  INT32_C(   518279088),  INT32_C(   194058066),  INT32_C(   196897414), -INT32_C(  1056820032),  INT32_C(   613057099),
      -INT32_C(   758520714),  INT32_C(  1945119466), -INT32_C(  1693760021), -INT32_C(   423956588), -INT32_C(  1913566457),  INT32_C(  1989783222),  INT32_C(   758619106), -INT32_C(  1823358691),
      -INT32_C(  1889199195),  INT32_C(   805459525),  INT32_C(   801902235),  INT32_C(    68519677), -INT32_C(  2020473135), -INT32_C(  1745015884), -INT32_C(   473680698), -INT32_C(  1703536907),
       INT32_C(  1982454833), -INT32_C(   844747726),  INT32_C(   939291194), -INT32_C(   902032904), -INT32_C(   867054057), -INT32_C(  1084010503),  INT32_C(  2040670083),  INT32_C(  1846745149),
       INT32_C(   652492276), -INT32_C(  1544320151), -INT32_C(   153423875),  INT32_C(   415241728), -INT32_C(   572255772), -INT32_C(   459520160), -INT32_C(  1403175314),  INT32_C(  1260023895),
       INT32_C(   376635309), -INT32_C(  2017892982),  INT32_C(  1434293333), -INT32_C(  1888666198), -INT32_C(  1351855793),  INT32_C(   127076760), -INT32_C(  1632374713),  INT32_C(   250269025),
       INT32_C(  1445289164),  INT32_C(   383704769),  INT32_C(   493640562), -INT32_C(   391325287), -INT32_C(  1013508053),  INT32_C(  1774856993),  INT32_C(  2080865563),  INT32_C(   395047243),
       INT32_C(   258912333),  INT32_C(    19221646),  INT32_C(  1075745191), -INT32_C(  1775711637),  INT32_C(    72990946),  INT32_C(   107816171), -INT32_C(   326929247), -INT32_C(  1291579802),
       INT32_C(  1287811774),  INT32_C(  1699604670), -INT32_C(   458855559),  INT32_C(   410701365),  INT32_C(  2031932558), -INT32_C(  1719629320),  INT32_C(  1669727229), -INT32_C(   820540911),
      -INT32_C(  1172579844),  INT32_C(   991914433),  INT32_C(   169854420) };
  static const int32_t b = -INT32_C(   654985510);
  static const int32_t e[] =
    {  INT32_C(           0), -INT32_C(  1716905998), -INT32_C(  1232964357),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(   429231601),  INT32_C(   156836217),  INT32_C(           0),  INT32_C(           0),  INT32_C(   160156913),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(  1467964738), -INT32_C(    78962777), -INT32_C(   440280875),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1411691756), -INT32_C(  1480575730),
      -INT32_C(   334793622),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1536615069),  INT32_C(           0), -INT32_C(  1045971207),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(   810183731),  INT32_C(           0), -INT32_C(   101183301), -INT32_C(   631663423),  INT32_C(   513679434),  INT32_C(  1436252531),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(   494847623),  INT32_C(   131312234),  INT32_C(           0),  INT32_C(  1691512854),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(   598904966),  INT32_C(   263651785),  INT32_C(           0), -INT32_C(  1532910413),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1358833581), -INT32_C(  1839120579),
      -INT32_C(   416554430), -INT32_C(  1833757065),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   614890157),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(   547882067), -INT32_C(   732875862),  INT32_C(  1167767063),  INT32_C(           0),  INT32_C(           0), -INT32_C(   641999605),
       INT32_C(           0), -INT32_C(   642407254),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   848809094),
       INT32_C(           0), -INT32_C(   923699024),  INT32_C(           0),  INT32_C(   165072810),  INT32_C(  1089689477),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(   754369209),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1754468420),  INT32_C(           0),  INT32_C(           0), -INT32_C(   107514921),
       INT32_C(           0),  INT32_C(           0), -INT32_C(  1930401925),  INT32_C(  1927220819),  INT32_C(   798467762),  INT32_C(           0),  INT32_C(  1347812253),  INT32_C(           0),
       INT32_C(           0), -INT32_C(  1060544662),  INT32_C(           0),  INT32_C(           0),  INT32_C(   856261462), -INT32_C(  1851965160),  INT32_C(           0),  INT32_C(  1066129371),
       INT32_C(           0),  INT32_C(   787543545),  INT32_C(           0),  INT32_C(   247292125),  INT32_C(  1811741559),  INT32_C(  2075708880),  INT32_C(  1038387847), -INT32_C(    29776651),
       INT32_C(           0),  INT32_C(           0), -INT32_C(   840849900), -INT32_C(   342371175),  INT32_C(           0),  INT32_C(           0), -INT32_C(   293183459), -INT32_C(  1331104617),
       INT32_C(           0), -INT32_C(   491343630),  INT32_C(  1567345897),  INT32_C(  1946498868), -INT32_C(  1707258732), -INT32_C(   656164641),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(   865780225),  INT32_C(  1164595073),  INT32_C(           0),  INT32_C(  1173264598),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1268042609),
      -INT32_C(   103535204),  INT32_C(           0), -INT32_C(  1038774511),  INT32_C(           0), -INT32_C(  1258580947), -INT32_C(  1650198564),  INT32_C(  1413604616), -INT32_C(  1168373181),
      -INT32_C(  1234213685),  INT32_C(  1460445035),  INT32_C(           0),  INT32_C(   723505187),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(  1594276704), -INT32_C(   247047394),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(  1307477786), -INT32_C(   889334641),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   195465350),  INT32_C(           0),  INT32_C(  1915009405),
       INT32_C(           0), -INT32_C(  1362907472),  INT32_C(  2089278843), -INT32_C(  1233680688), -INT32_C(   696870283),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(  2100274674),  INT32_C(           0),  INT32_C(  1148626072),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1865124793), -INT32_C(  1559116223),  INT32_C(  1050032753),
       INT32_C(           0),  INT32_C(   674207156),  INT32_C(  1730730701), -INT32_C(  1120726127),  INT32_C(   727976456),  INT32_C(           0),  INT32_C(           0), -INT32_C(   636594292),
       INT32_C(  1942797284),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1065686875),  INT32_C(           0), -INT32_C(  1064643810), -INT32_C(  1970254557),  INT32_C(           0),
      -INT32_C(   517594334),  INT32_C(           0),  INT32_C(   824839930) };

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
    rv = simde_svsub_n_s32_z(pv, av, b);

    simde_svst1_s32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vi32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)], a[1024 / sizeof(int32_t)], b, e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i32();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_s32(pg, &(a[i]));

    ev = simde_svsub_n_s32_z(pv, av, b);

    simde_svst1_s32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i32(1, b);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_s32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1) };
  static const int32_t a[] =
    {  INT32_C(   536458025), -INT32_C(  1896146602),  INT32_C(    57509108), -INT32_C(  1093421719), -INT32_C(   282658389), -INT32_C(   809927715), -INT32_C(  1165112876),  INT32_C(   278604263),
       INT32_C(   858756573), -INT32_C(  1564333138),  INT32_C(   413544367), -INT32_C(  1864992283),  INT32_C(  1333853298),  INT32_C(  1277049207), -INT32_C(   385438974), -INT32_C(  1292262955),
      -INT32_C(   454744010),  INT32_C(    42444627), -INT32_C(  1139135017),  INT32_C(   407695782),  INT32_C(  1701301485),  INT32_C(   129074693),  INT32_C(   116438833), -INT32_C(  1883707048),
       INT32_C(  1702075922),  INT32_C(   476641861), -INT32_C(   841448921),  INT32_C(  1642407283), -INT32_C(   137998863),  INT32_C(    83785683), -INT32_C(  2046038226), -INT32_C(   367672360),
      -INT32_C(  1487894175), -INT32_C(  1413236605), -INT32_C(  1367827398), -INT32_C(  1307615551),  INT32_C(  2125059499),  INT32_C(  2055383116),  INT32_C(  1862307223), -INT32_C(  1302718895),
       INT32_C(   576301727), -INT32_C(  1664279198),  INT32_C(  2051688121),  INT32_C(  1328306596),  INT32_C(  2060310062),  INT32_C(   368332670),  INT32_C(   780465629), -INT32_C(  1428103669),
      -INT32_C(   355714424),  INT32_C(   277322327), -INT32_C(  2071277088),  INT32_C(  1507046955),  INT32_C(   181706892), -INT32_C(   870332177), -INT32_C(   923097923),  INT32_C(   192076674),
       INT32_C(  1828011797), -INT32_C(  1183023911),  INT32_C(  2034042446),  INT32_C(  1238503612), -INT32_C(  1621907792),  INT32_C(   745304943), -INT32_C(  1711970793),  INT32_C(  1453614913),
       INT32_C(  2143460006),  INT32_C(  1681407510),  INT32_C(    31290692),  INT32_C(   894087301), -INT32_C(   975856298),  INT32_C(   670187792), -INT32_C(   373168217), -INT32_C(   180394674),
       INT32_C(   376701695), -INT32_C(  2055557824), -INT32_C(  1467590622),  INT32_C(  1591595016),  INT32_C(  2116334189), -INT32_C(  1683679501),  INT32_C(  1266968317), -INT32_C(   884948020),
       INT32_C(   115455429), -INT32_C(  2071241630), -INT32_C(  1137962572),  INT32_C(  1310329569), -INT32_C(  1328791876),  INT32_C(  1363898964), -INT32_C(  1533161512),  INT32_C(  1483791762),
      -INT32_C(   195145326),  INT32_C(  1635379629), -INT32_C(   618813958),  INT32_C(  1814640815), -INT32_C(   887294346),  INT32_C(  1075603304), -INT32_C(   924468938),  INT32_C(   689984919),
       INT32_C(  1411284646),  INT32_C(  1639290727), -INT32_C(   331558084), -INT32_C(  2124913141), -INT32_C(  1001622436),  INT32_C(   285501915), -INT32_C(  1176901342), -INT32_C(   438044098),
      -INT32_C(   533134984), -INT32_C(   733876584), -INT32_C(   859799871),  INT32_C(  1078860004),  INT32_C(  1728354956),  INT32_C(   645400579),  INT32_C(   819942130), -INT32_C(  1005206964),
       INT32_C(  1537494723), -INT32_C(    30349763),  INT32_C(  1221324900), -INT32_C(  1786242807), -INT32_C(  1208120141), -INT32_C(  2032306796),  INT32_C(   330808519),  INT32_C(  1121504383),
       INT32_C(  1486781467), -INT32_C(   967389598), -INT32_C(   955375170), -INT32_C(   295856582), -INT32_C(  1213900254), -INT32_C(  1757576497), -INT32_C(  1112869826), -INT32_C(   603946303),
       INT32_C(  1630838527),  INT32_C(   707299948), -INT32_C(   420333908), -INT32_C(   271298611),  INT32_C(  2024176041),  INT32_C(   974120187), -INT32_C(  1711818024),  INT32_C(   997586748),
       INT32_C(    27109781), -INT32_C(   533936844), -INT32_C(   926540037),  INT32_C(   381197165),  INT32_C(   277765652),  INT32_C(   457875010), -INT32_C(  1800126120), -INT32_C(   825218503),
       INT32_C(   131100115),  INT32_C(   770178098), -INT32_C(  2013876710),  INT32_C(  1570614857),  INT32_C(  1332554508),  INT32_C(   560641993),  INT32_C(   850796281),  INT32_C(   469796424),
       INT32_C(   623104243), -INT32_C(   430830644),  INT32_C(    40716473),  INT32_C(    56560374), -INT32_C(    11350730),  INT32_C(  2099362948),  INT32_C(   598726618),  INT32_C(  1346351197),
       INT32_C(  1299538560),  INT32_C(   640927597),  INT32_C(   103325968), -INT32_C(   519468885), -INT32_C(   639542443), -INT32_C(   229178857),  INT32_C(   907347673),  INT32_C(   931550390),
       INT32_C(   612694966), -INT32_C(   766855230),  INT32_C(    81359704),  INT32_C(  1357243131),  INT32_C(  1428801086), -INT32_C(  1589149496),  INT32_C(  1037524103),  INT32_C(  1735679408),
       INT32_C(   462157912),  INT32_C(   149804464),  INT32_C(  1124910664), -INT32_C(   409734487), -INT32_C(  2126725704), -INT32_C(  1004370883), -INT32_C(  1862075680), -INT32_C(  1325894057),
       INT32_C(   533431151), -INT32_C(  1591232424),  INT32_C(   686044287), -INT32_C(   569411546),  INT32_C(  1918847797), -INT32_C(  1338539313), -INT32_C(   750700164),  INT32_C(   511916463),
       INT32_C(   339562172), -INT32_C(  2034932473), -INT32_C(  1079076199),  INT32_C(  1201519890), -INT32_C(   658899704), -INT32_C(    74911617), -INT32_C(   640759511), -INT32_C(  1091087870),
      -INT32_C(  1479395936),  INT32_C(   858622106),  INT32_C(   888331042), -INT32_C(  1585737832),  INT32_C(   192492684),  INT32_C(  1309016357), -INT32_C(   869804598), -INT32_C(   947249369),
      -INT32_C(   294691756),  INT32_C(   102866148),  INT32_C(   272241528),  INT32_C(   800175522),  INT32_C(   255470314), -INT32_C(   178437845),  INT32_C(  1036092694), -INT32_C(   133936220),
      -INT32_C(  1931054168), -INT32_C(  2003630320), -INT32_C(  1130836710),  INT32_C(  1844136579), -INT32_C(  1602476428),  INT32_C(  2106972519),  INT32_C(    45766494),  INT32_C(  1257946786),
       INT32_C(  1121443890),  INT32_C(    30042855), -INT32_C(  1161928137),  INT32_C(   556247468),  INT32_C(   918660047), -INT32_C(   609003907),  INT32_C(  1356754349),  INT32_C(  1587206188),
      -INT32_C(  1600097863),  INT32_C(   329411291),  INT32_C(  2043502796), -INT32_C(   644156151),  INT32_C(   353328024),  INT32_C(  1609679793),  INT32_C(  1555025712),  INT32_C(  1622821287),
      -INT32_C(  1778296133), -INT32_C(  1851153468),  INT32_C(   202012419),  INT32_C(    82158700), -INT32_C(  1340410369), -INT32_C(   401667144), -INT32_C(  2126135590), -INT32_C(  1008533752),
       INT32_C(   509207386), -INT32_C(  1985019002), -INT32_C(   426395270) };
  static const int32_t b = -INT32_C(  1228013776);
  static const int32_t e[] =
    {  INT32_C(   536458025), -INT32_C(   668132826),  INT32_C(  1285522884),  INT32_C(   134592057),  INT32_C(   945355387),  INT32_C(   418086061),  INT32_C(    62900900),  INT32_C(   278604263),
       INT32_C(   858756573), -INT32_C(   336319362),  INT32_C(  1641558143), -INT32_C(  1864992283),  INT32_C(  1333853298), -INT32_C(  1789904313),  INT32_C(   842574802), -INT32_C(  1292262955),
       INT32_C(   773269766),  INT32_C(    42444627),  INT32_C(    88878759),  INT32_C(  1635709558),  INT32_C(  1701301485),  INT32_C(   129074693),  INT32_C(   116438833), -INT32_C(  1883707048),
       INT32_C(  1702075922),  INT32_C(   476641861),  INT32_C(   386564855), -INT32_C(  1424546237), -INT32_C(   137998863),  INT32_C(    83785683), -INT32_C(   818024450), -INT32_C(   367672360),
      -INT32_C(   259880399), -INT32_C(   185222829), -INT32_C(  1367827398), -INT32_C(    79601775), -INT32_C(   941894021),  INT32_C(  2055383116), -INT32_C(  1204646297), -INT32_C(    74705119),
       INT32_C(   576301727), -INT32_C(   436265422),  INT32_C(  2051688121),  INT32_C(  1328306596),  INT32_C(  2060310062),  INT32_C(  1596346446),  INT32_C(  2008479405), -INT32_C(  1428103669),
       INT32_C(   872299352),  INT32_C(  1505336103), -INT32_C(   843263312), -INT32_C(  1559906565),  INT32_C(  1409720668),  INT32_C(   357681599), -INT32_C(   923097923),  INT32_C(  1420090450),
       INT32_C(  1828011797),  INT32_C(    44989865),  INT32_C(  2034042446),  INT32_C(  1238503612), -INT32_C(  1621907792),  INT32_C(   745304943), -INT32_C(   483957017),  INT32_C(  1453614913),
      -INT32_C(   923493514), -INT32_C(  1385546010),  INT32_C(    31290692),  INT32_C(  2122101077), -INT32_C(   975856298),  INT32_C(   670187792),  INT32_C(   854845559), -INT32_C(   180394674),
       INT32_C(  1604715471), -INT32_C(   827544048), -INT32_C(   239576846), -INT32_C(  1475358504),  INT32_C(  2116334189), -INT32_C(   455665725), -INT32_C(  1799985203),  INT32_C(   343065756),
       INT32_C(  1343469205), -INT32_C(   843227854), -INT32_C(  1137962572), -INT32_C(  1756623951), -INT32_C(  1328791876), -INT32_C(  1703054556), -INT32_C(   305147736), -INT32_C(  1583161758),
      -INT32_C(   195145326),  INT32_C(  1635379629), -INT32_C(   618813958), -INT32_C(  1252312705),  INT32_C(   340719430),  INT32_C(  1075603304), -INT32_C(   924468938),  INT32_C(  1917998695),
      -INT32_C(  1655668874), -INT32_C(  1427662793),  INT32_C(   896455692), -INT32_C(   896899365), -INT32_C(  1001622436),  INT32_C(  1513515691),  INT32_C(    51112434),  INT32_C(   789969678),
       INT32_C(   694878792), -INT32_C(   733876584), -INT32_C(   859799871),  INT32_C(  1078860004), -INT32_C(  1338598564),  INT32_C(  1873414355),  INT32_C(   819942130),  INT32_C(   222806812),
      -INT32_C(  1529458797), -INT32_C(    30349763), -INT32_C(  1845628620), -INT32_C(  1786242807),  INT32_C(    19893635), -INT32_C(   804293020),  INT32_C(  1558822295),  INT32_C(  1121504383),
      -INT32_C(  1580172053),  INT32_C(   260624178), -INT32_C(   955375170), -INT32_C(   295856582),  INT32_C(    14113522), -INT32_C(  1757576497), -INT32_C(  1112869826), -INT32_C(   603946303),
       INT32_C(  1630838527),  INT32_C(   707299948), -INT32_C(   420333908), -INT32_C(   271298611), -INT32_C(  1042777479), -INT32_C(  2092833333), -INT32_C(   483804248),  INT32_C(   997586748),
       INT32_C(    27109781), -INT32_C(   533936844), -INT32_C(   926540037),  INT32_C(   381197165),  INT32_C(  1505779428),  INT32_C(   457875010), -INT32_C(   572112344),  INT32_C(   402795273),
       INT32_C(   131100115),  INT32_C(  1998191874), -INT32_C(  2013876710),  INT32_C(  1570614857),  INT32_C(  1332554508),  INT32_C(   560641993),  INT32_C(   850796281),  INT32_C(   469796424),
       INT32_C(   623104243),  INT32_C(   797183132),  INT32_C(  1268730249),  INT32_C(  1284574150), -INT32_C(    11350730), -INT32_C(   967590572),  INT32_C(  1826740394),  INT32_C(  1346351197),
      -INT32_C(  1767414960),  INT32_C(  1868941373),  INT32_C(   103325968), -INT32_C(   519468885), -INT32_C(   639542443),  INT32_C(   998834919),  INT32_C(  2135361449),  INT32_C(   931550390),
       INT32_C(   612694966), -INT32_C(   766855230),  INT32_C(  1309373480), -INT32_C(  1709710389),  INT32_C(  1428801086), -INT32_C(   361135720),  INT32_C(  1037524103), -INT32_C(  1331274112),
       INT32_C(   462157912),  INT32_C(   149804464),  INT32_C(  1124910664),  INT32_C(   818279289), -INT32_C(   898711928), -INT32_C(  1004370883), -INT32_C(   634061904), -INT32_C(  1325894057),
       INT32_C(  1761444927), -INT32_C(   363218648),  INT32_C(  1914058063),  INT32_C(   658602230), -INT32_C(  1148105723), -INT32_C(   110525537), -INT32_C(   750700164),  INT32_C(  1739930239),
       INT32_C(   339562172), -INT32_C(  2034932473), -INT32_C(  1079076199), -INT32_C(  1865433630),  INT32_C(   569114072), -INT32_C(    74911617), -INT32_C(   640759511), -INT32_C(  1091087870),
      -INT32_C(  1479395936),  INT32_C(   858622106),  INT32_C(  2116344818), -INT32_C(   357724056),  INT32_C(  1420506460), -INT32_C(  1757937163), -INT32_C(   869804598),  INT32_C(   280764407),
       INT32_C(   933322020),  INT32_C(  1330879924),  INT32_C(   272241528),  INT32_C(   800175522),  INT32_C(   255470314),  INT32_C(  1049575931), -INT32_C(  2030860826),  INT32_C(  1094077556),
      -INT32_C(  1931054168), -INT32_C(  2003630320), -INT32_C(  1130836710),  INT32_C(  1844136579), -INT32_C(  1602476428),  INT32_C(  2106972519),  INT32_C(    45766494), -INT32_C(  1809006734),
       INT32_C(  1121443890),  INT32_C(  1258056631),  INT32_C(    66085639),  INT32_C(  1784261244),  INT32_C(   918660047), -INT32_C(   609003907), -INT32_C(  1710199171),  INT32_C(  1587206188),
      -INT32_C(  1600097863),  INT32_C(   329411291), -INT32_C(  1023450724),  INT32_C(   583857625),  INT32_C(   353328024),  INT32_C(  1609679793),  INT32_C(  1555025712), -INT32_C(  1444132233),
      -INT32_C(  1778296133), -INT32_C(  1851153468),  INT32_C(  1430026195),  INT32_C(    82158700), -INT32_C(  1340410369),  INT32_C(   826346632), -INT32_C(  2126135590),  INT32_C(   219480024),
       INT32_C(   509207386), -INT32_C(   757005226),  INT32_C(   801618506) };

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
    rv = simde_svsub_n_s32_m(pv, av, b);

    simde_svst1_s32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vi32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)], a[1024 / sizeof(int32_t)], b, e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i32();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_s32(pg, &(a[i]));

    ev = simde_svsub_n_s32_m(pv, av, b);

    simde_svst1_s32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i32(1, b);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_s64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0) };
  static const int64_t a[] =
    {  INT64_C( 8144021071395839776), -INT64_C( 7114043505720782304),  INT64_C( 4895131145159847862),  INT64_C( 8843495551538455074),
       INT64_C( 1386400547320730312), -INT64_C( 6860410591813102835),  INT64_C( 2249225848155340315), -INT64_C( 7489410517647595460),
       INT64_C( 1071189311151703511), -INT64_C( 8412999597638843212),  INT64_C( 4836781363178580995), -INT64_C( 4213986138926765797),
       INT64_C( 4502874539978385518), -INT64_C( 4545507799200843536),  INT64_C( 4004508331375880264), -INT64_C( 4450497251019363447),
       INT64_C( 2835207517115632528), -INT64_C( 7285854079341349530),  INT64_C(  877774784097264602), -INT64_C( 8431653325194964506),
       INT64_C( 4893439020209811082), -INT64_C( 4964010356853280975),  INT64_C( 7385024331231921645),  INT64_C( 5239267181616758577),
      -INT64_C( 8724895977899992629), -INT64_C( 8575656766702333600), -INT64_C( 4606771683897266390),  INT64_C( 1908576604132192885),
      -INT64_C( 2894499032069995015),  INT64_C( 3179565537321147901),  INT64_C(  294116677498902981), -INT64_C( 7348551188256194405),
       INT64_C( 7964542762025010489),  INT64_C( 8919422727262478490),  INT64_C( 2653715885999497280), -INT64_C(  640053487571432476),
       INT64_C( 6824976280399054807),  INT64_C( 2666626745447923407), -INT64_C( 7417489377582526110),  INT64_C(  543031405087366611),
       INT64_C( 3415144001451340099), -INT64_C( 8876393510321430587),  INT64_C( 7049962511292941704),  INT64_C( 8274093485153579932),
      -INT64_C( 1135507258831461459),  INT64_C( 3594834203257795133),  INT64_C( 7934855261090370095),  INT64_C( 4312774494134079800),
       INT64_C( 8019368537796137776),  INT64_C( 9174871819311572344),  INT64_C( 4486528639184978180), -INT64_C( 5029536123988902549),
       INT64_C( 8751724433872616659), -INT64_C(  570849993513286844),  INT64_C( 1509569720696590255), -INT64_C( 1453466307490178673),
      -INT64_C( 8271030827543893572),  INT64_C( 8040390711597716136),  INT64_C(  234214067859186563),  INT64_C( 5239359328504073393),
      -INT64_C( 5499109501971290406), -INT64_C( 8701266720724103153),  INT64_C( 3296621169325859655), -INT64_C( 6407023795445965760),
       INT64_C( 7426850680965045075), -INT64_C( 8298317422369808310) };
  static const int64_t b = -INT64_C( 5659569423882640918);
  static const int64_t e[] =
    { -INT64_C( 4643153578431070922), -INT64_C( 1454474081838141386),  INT64_C(                   0), -INT64_C( 3943679098288455624),
       INT64_C( 7045969971203371230),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 1829841093764954542),
       INT64_C( 6730758735034344429),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C( 8284300109848525180),  INT64_C(                   0), -INT64_C( 8782666318451030434),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C( 6537344207979905520), -INT64_C( 2772083901312323588),
      -INT64_C( 7893735629617099616),  INT64_C(  695559067029359943),  INT64_C(                   0), -INT64_C( 7547907468210152121),
       INT64_C(                   0), -INT64_C( 2916087342819692682),  INT64_C( 1052797739985374528),  INT64_C( 7568146028014833803),
       INT64_C( 2765070391812645903),  INT64_C( 8839134961203788819),  INT64_C( 5953686101381543899),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 5019515936311208442),
      -INT64_C( 5962198369427855891),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C( 9074713425333981017),  INT64_C(                   0), -INT64_C( 5737212138533968994), -INT64_C( 4513081164673330766),
       INT64_C( 4524062165051179459),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 8474400155692830898),
      -INT64_C( 4767806112030772922),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(  630033299893738369),
      -INT64_C( 4035450215954294039),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 4206103116392462245),
       INT64_C(                   0), -INT64_C( 4746783938229194562),  INT64_C( 5893783491741827481), -INT64_C( 7547815321322837305),
       INT64_C(  160459921911350512), -INT64_C( 3041697296841462235),  INT64_C( 8956190593208500573),  INT64_C(                   0),
      -INT64_C( 5360323968861865623),  INT64_C(                   0) };

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
    rv = simde_svsub_n_s64_z(pv, av, b);

    simde_svst1_s64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vi64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)], a[1024 / sizeof(int64_t)], b, e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i64();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_s64(pg, &(a[i]));

    ev = simde_svsub_n_s64_z(pv, av, b);

    simde_svst1_s64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i64(1, b);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_s64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0) };
  static const int64_t a[] =
    { -INT64_C( 2602867800748782860),  INT64_C( 5537286791435385740), -INT64_C( 1329852431515886609), -INT64_C( 7990308657436520595),
       INT64_C( 8872949912697580994),  INT64_C( 7949718104030452487), -INT64_C(  532443403358166675), -INT64_C( 2657581067241496335),
       INT64_C( 6843298074859948685), -INT64_C( 5669829324880661918),  INT64_C( 8673366115837028057), -INT64_C( 8119669064478580387),
       INT64_C( 2243922627943691631),  INT64_C( 2029523928023665205), -INT64_C( 1983872435161560457),  INT64_C( 1157613814382493056),
       INT64_C( 6196384776632802337), -INT64_C( 4115171513436537211), -INT64_C( 4328455933215284093),  INT64_C( 1543421805279332537),
      -INT64_C( 4474906511802154639),  INT64_C( 3460291380038448367), -INT64_C( 4623181386386519343), -INT64_C( 2199018374756230286),
       INT64_C( 5603699897635335878), -INT64_C( 8437052200050733813), -INT64_C( 4674607437999889317), -INT64_C( 8871070103066297967),
      -INT64_C( 5135710320630278898),  INT64_C( 3664621503115183767), -INT64_C( 9184330647574709635),  INT64_C( 6858812154657812717),
      -INT64_C( 7557455788398299718),  INT64_C( 7410608215339601869),  INT64_C(  841815918646487614),  INT64_C( 5700402184646439019),
       INT64_C( 4193647770247489434),  INT64_C( 2067634769811675747),  INT64_C(  669339378174845472),  INT64_C( 9154939415578410792),
      -INT64_C(  545133925675449913),  INT64_C( 2693703450818268774), -INT64_C( 3783114244390409256), -INT64_C( 1364427798016932436),
      -INT64_C( 2602076224047929003), -INT64_C(  789959393757157408), -INT64_C( 4136017381909893845),  INT64_C(  811324911398625583),
      -INT64_C( 3034905027463977839), -INT64_C( 6047274915294740479), -INT64_C( 7489182267181662672),  INT64_C( 7058882040307738678),
      -INT64_C( 4080744194821854061),  INT64_C(  898178798575753288),  INT64_C( 4284725370392342902),  INT64_C( 2666444969969411024),
      -INT64_C(  533944077265246198), -INT64_C( 1582108768932299740), -INT64_C( 7392025705069387223), -INT64_C( 5162749502935166558),
       INT64_C( 4056370061521717410),  INT64_C( 7996496577260162459), -INT64_C( 6699097842476334427),  INT64_C( 2305336668117811863),
       INT64_C( 4794289225836103483), -INT64_C( 6234025303395417911), -INT64_C( 5210346876626790131), -INT64_C(  504689315293590941),
      -INT64_C(  690228130269859710),  INT64_C( 1459026673856199825), -INT64_C( 2634372167044540518), -INT64_C( 1507657589151011490),
      -INT64_C( 4734269275578803159),  INT64_C( 7735094886995873852), -INT64_C( 6035222286726497558), -INT64_C( 2569343498720904957),
       INT64_C( 2819955866150792247), -INT64_C(  861098982621088049), -INT64_C( 3947240393399652035),  INT64_C( 1305636914832146575),
      -INT64_C( 7058098497337798151),  INT64_C( 8578314103120951055), -INT64_C( 8643466543578782852), -INT64_C( 4095486414256717508),
       INT64_C( 5091240450290655033), -INT64_C( 5917612050399369681),  INT64_C( 6652093867366606031),  INT64_C( 4383018394974362173),
       INT64_C( 7402207185444634427),  INT64_C( 5959019333732473043), -INT64_C( 2661510149916941676),  INT64_C( 6540276827970569092),
      -INT64_C( 4046336980247902150), -INT64_C( 1408643341447550819),  INT64_C( 9050459508574293536),  INT64_C( 8551428854357721395),
      -INT64_C( 7238478676115294001), -INT64_C(  743884668809750679),  INT64_C( 3473204390208425406), -INT64_C( 3638856830299260979),
      -INT64_C( 7908289980482361178), -INT64_C( 1568096905063039885) };
  static const int64_t b = -INT64_C( 7004113897277521490);
  static const int64_t e[] =
    {  INT64_C( 4401246096528738630),  INT64_C( 5537286791435385740),  INT64_C( 5674261465761634881), -INT64_C(  986194760158999105),
      -INT64_C( 2569680263734449132),  INT64_C( 7949718104030452487), -INT64_C(  532443403358166675), -INT64_C( 2657581067241496335),
       INT64_C( 6843298074859948685), -INT64_C( 5669829324880661918), -INT64_C( 2769264060595002069), -INT64_C( 8119669064478580387),
      -INT64_C( 9198707548488338495),  INT64_C( 9033637825301186695),  INT64_C( 5020241462115961033),  INT64_C( 8161727711660014546),
      -INT64_C( 5246245399799227789),  INT64_C( 2888942383840984279),  INT64_C( 2675657964062237397),  INT64_C( 8547535702556854027),
      -INT64_C( 4474906511802154639), -INT64_C( 7982338796393581759),  INT64_C( 2380932510891002147),  INT64_C( 4805095522521291204),
      -INT64_C( 5838930278796694248), -INT64_C( 1432938302773212323),  INT64_C( 2329506459277632173), -INT64_C( 8871070103066297967),
       INT64_C( 1868403576647242592),  INT64_C( 3664621503115183767), -INT64_C( 2180216750297188145),  INT64_C( 6858812154657812717),
      -INT64_C(  553341891120778228), -INT64_C( 4032021961092428257),  INT64_C( 7845929815924009104), -INT64_C( 5742227991785591107),
      -INT64_C( 7248982406184540692),  INT64_C( 9071748667089197237),  INT64_C(  669339378174845472), -INT64_C( 2287690760853619334),
      -INT64_C(  545133925675449913), -INT64_C( 8748926725613761352),  INT64_C( 3220999652887112234), -INT64_C( 1364427798016932436),
      -INT64_C( 2602076224047929003), -INT64_C(  789959393757157408), -INT64_C( 4136017381909893845),  INT64_C(  811324911398625583),
       INT64_C( 3969208869813543651), -INT64_C( 6047274915294740479), -INT64_C( 7489182267181662672), -INT64_C( 4383748136124291448),
      -INT64_C( 4080744194821854061),  INT64_C( 7902292695853274778),  INT64_C( 4284725370392342902), -INT64_C( 8776185206462619102),
      -INT64_C(  533944077265246198), -INT64_C( 1582108768932299740), -INT64_C(  387911807791865733), -INT64_C( 5162749502935166558),
       INT64_C( 4056370061521717410),  INT64_C( 7996496577260162459),  INT64_C(  305016054801187063),  INT64_C( 2305336668117811863),
      -INT64_C( 6648340950595926643), -INT64_C( 6234025303395417911), -INT64_C( 5210346876626790131), -INT64_C(  504689315293590941),
      -INT64_C(  690228130269859710),  INT64_C( 1459026673856199825),  INT64_C( 4369741730232980972),  INT64_C( 5496456308126510000),
       INT64_C( 2269844621698718331),  INT64_C( 7735094886995873852),  INT64_C(  968891610551023932),  INT64_C( 4434770398556616533),
       INT64_C( 2819955866150792247),  INT64_C( 6143014914656433441), -INT64_C( 3947240393399652035),  INT64_C( 1305636914832146575),
      -INT64_C( 7058098497337798151),  INT64_C( 8578314103120951055), -INT64_C( 8643466543578782852),  INT64_C( 2908627483020803982),
       INT64_C( 5091240450290655033), -INT64_C( 5917612050399369681), -INT64_C( 4790536309065424095), -INT64_C( 7059611781457667953),
       INT64_C( 7402207185444634427),  INT64_C( 5959019333732473043), -INT64_C( 2661510149916941676), -INT64_C( 4902353348461461034),
      -INT64_C( 4046336980247902150), -INT64_C( 1408643341447550819),  INT64_C( 9050459508574293536),  INT64_C( 8551428854357721395),
      -INT64_C(  234364778837772511),  INT64_C( 6260229228467770811), -INT64_C( 7969425786223604720), -INT64_C( 3638856830299260979),
      -INT64_C(  904176083204839688), -INT64_C( 1568096905063039885) };

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
    rv = simde_svsub_n_s64_m(pv, av, b);

    simde_svst1_s64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vi64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)], a[1024 / sizeof(int64_t)], b, e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i64();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_s64(pg, &(a[i]));

    ev = simde_svsub_n_s64_m(pv, av, b);

    simde_svst1_s64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i64(1, b);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_u8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) };
  static const uint8_t a[] =
    { UINT8_C( 12), UINT8_C(238), UINT8_C(183), UINT8_C(147), UINT8_C(201), UINT8_C(220), UINT8_C(176), UINT8_C(125),
      UINT8_C( 37), UINT8_C(136), UINT8_C(140), UINT8_C(  9), UINT8_C(160), UINT8_C( 89), UINT8_C(230), UINT8_C(164),
      UINT8_C(222), UINT8_C( 75), UINT8_C( 60), UINT8_C(118), UINT8_C( 34), UINT8_C(150), UINT8_C( 12), UINT8_C(220),
      UINT8_C(199), UINT8_C(144), UINT8_C(106), UINT8_C( 61), UINT8_C( 86), UINT8_C( 37), UINT8_C(101), UINT8_C( 99),
      UINT8_C( 19), UINT8_C( 28), UINT8_C(246), UINT8_C(220), UINT8_C(248), UINT8_C(166), UINT8_C( 90), UINT8_C( 30),
      UINT8_C( 46), UINT8_C(230), UINT8_C( 39), UINT8_C(207), UINT8_C( 63), UINT8_C( 13), UINT8_C(115), UINT8_C( 30),
      UINT8_C( 88), UINT8_C(175), UINT8_C(148), UINT8_C(122), UINT8_C( 69), UINT8_C(160), UINT8_C( 86), UINT8_C( 13),
      UINT8_C( 48), UINT8_C(192), UINT8_C( 74), UINT8_C(135), UINT8_C(229), UINT8_C(175), UINT8_C(234), UINT8_C(248),
      UINT8_C(204), UINT8_C(224), UINT8_C(213), UINT8_C(196), UINT8_C(134), UINT8_C( 47), UINT8_C(226), UINT8_C(180),
      UINT8_C( 21), UINT8_C(  9), UINT8_C(131), UINT8_C( 85), UINT8_C( 22), UINT8_C(246), UINT8_C(115), UINT8_C(110),
      UINT8_C(165), UINT8_C(  7), UINT8_C(232), UINT8_C(235), UINT8_C(168), UINT8_C( 63), UINT8_C(248), UINT8_C(216),
         UINT8_MAX, UINT8_C( 66), UINT8_C( 95), UINT8_C(229), UINT8_C(241), UINT8_C( 73), UINT8_C(221), UINT8_C(189),
      UINT8_C( 41), UINT8_C(178), UINT8_C(130), UINT8_C(175), UINT8_C(225), UINT8_C(100), UINT8_C(100), UINT8_C(247),
      UINT8_C(110), UINT8_C(231), UINT8_C( 76), UINT8_C(132), UINT8_C(222), UINT8_C(191), UINT8_C(243), UINT8_C(131),
      UINT8_C(198), UINT8_C(219), UINT8_C(110), UINT8_C(110), UINT8_C( 26), UINT8_C(102), UINT8_C( 71), UINT8_C( 26),
      UINT8_C(168), UINT8_C(166),    UINT8_MAX, UINT8_C(154), UINT8_C(240), UINT8_C(220), UINT8_C( 87), UINT8_C( 25),
      UINT8_C(143), UINT8_C(217), UINT8_C(201), UINT8_C(112), UINT8_C( 62), UINT8_C( 45), UINT8_C(103), UINT8_C(172),
      UINT8_C( 20), UINT8_C(179), UINT8_C( 48), UINT8_C(242), UINT8_C(114), UINT8_C( 35), UINT8_C(118), UINT8_C( 57),
         UINT8_MAX, UINT8_C(228), UINT8_C(167), UINT8_C( 25), UINT8_C( 75), UINT8_C(238), UINT8_C( 51), UINT8_C(243),
      UINT8_C(149), UINT8_C( 50), UINT8_C(141), UINT8_C(133), UINT8_C( 15), UINT8_C(229), UINT8_C(158), UINT8_C(158),
      UINT8_C(190), UINT8_C(103), UINT8_C( 14), UINT8_C(252), UINT8_C(148), UINT8_C(118), UINT8_C(168), UINT8_C(169),
      UINT8_C( 41), UINT8_C(217), UINT8_C(155), UINT8_C(156), UINT8_C(252), UINT8_C( 17), UINT8_C(213), UINT8_C(251),
      UINT8_C(246), UINT8_C(124), UINT8_C( 21), UINT8_C( 65), UINT8_C(107), UINT8_C( 72), UINT8_C( 52), UINT8_C(  0),
      UINT8_C(123), UINT8_C(194), UINT8_C(133), UINT8_C(138), UINT8_C(167), UINT8_C( 35), UINT8_C( 40), UINT8_C(101),
      UINT8_C(139), UINT8_C( 54), UINT8_C( 98), UINT8_C( 31), UINT8_C(172), UINT8_C( 10), UINT8_C(200), UINT8_C(214),
      UINT8_C(227), UINT8_C(100), UINT8_C(114), UINT8_C(224), UINT8_C(117), UINT8_C( 71), UINT8_C(219), UINT8_C(107),
      UINT8_C(195), UINT8_C(240), UINT8_C(172), UINT8_C( 46), UINT8_C( 57), UINT8_C(225), UINT8_C( 46), UINT8_C(180),
      UINT8_C(163), UINT8_C(179), UINT8_C( 62), UINT8_C( 74), UINT8_C(215), UINT8_C(102), UINT8_C(175), UINT8_C( 98),
      UINT8_C(156), UINT8_C( 17), UINT8_C(129), UINT8_C( 73), UINT8_C( 28), UINT8_C( 74), UINT8_C( 31),    UINT8_MAX,
      UINT8_C(174), UINT8_C(145), UINT8_C(223), UINT8_C( 35), UINT8_C(216), UINT8_C(187), UINT8_C(143), UINT8_C(155),
      UINT8_C(171), UINT8_C( 59), UINT8_C(202), UINT8_C(228), UINT8_C( 28), UINT8_C(248), UINT8_C(152), UINT8_C(191),
      UINT8_C(172), UINT8_C(214), UINT8_C(  9), UINT8_C(131), UINT8_C( 60), UINT8_C(185), UINT8_C(229), UINT8_C(217),
      UINT8_C(202), UINT8_C(102), UINT8_C( 34), UINT8_C(230), UINT8_C(176), UINT8_C( 65), UINT8_C(230), UINT8_C( 94),
      UINT8_C(210), UINT8_C(197), UINT8_C(130), UINT8_C(170), UINT8_C(128), UINT8_C( 17), UINT8_C( 69), UINT8_C( 44),
      UINT8_C( 76), UINT8_C( 15), UINT8_C( 16), UINT8_C(105), UINT8_C(  8), UINT8_C(169), UINT8_C( 40), UINT8_C(180),
      UINT8_C(127), UINT8_C( 50), UINT8_C( 55), UINT8_C(188), UINT8_C(235), UINT8_C( 28), UINT8_C(149), UINT8_C(181),
      UINT8_C(130), UINT8_C(183), UINT8_C(156), UINT8_C( 51), UINT8_C(248), UINT8_C(130), UINT8_C(145), UINT8_C(202),
      UINT8_C( 71), UINT8_C( 19), UINT8_C(116), UINT8_C(200), UINT8_C( 36), UINT8_C(185), UINT8_C(244), UINT8_C(113),
      UINT8_C(201), UINT8_C(  4), UINT8_C(218), UINT8_C(209), UINT8_C(173), UINT8_C(  2), UINT8_C(133), UINT8_C( 45),
      UINT8_C( 52), UINT8_C(188), UINT8_C(233), UINT8_C( 31), UINT8_C(216), UINT8_C(126), UINT8_C(213), UINT8_C( 90),
      UINT8_C( 53), UINT8_C(113), UINT8_C(141), UINT8_C( 45), UINT8_C(243), UINT8_C( 31), UINT8_C(247), UINT8_C( 58),
      UINT8_C( 50), UINT8_C(107), UINT8_C(  2), UINT8_C( 87), UINT8_C( 36), UINT8_C(246), UINT8_C(200), UINT8_C(237),
      UINT8_C(251), UINT8_C(162), UINT8_C(190), UINT8_C(168), UINT8_C(164), UINT8_C( 67), UINT8_C(213), UINT8_C(217),
         UINT8_MAX, UINT8_C(190), UINT8_C(248), UINT8_C(215), UINT8_C( 60), UINT8_C(205), UINT8_C( 50), UINT8_C(113),
      UINT8_C( 62), UINT8_C(191), UINT8_C(158), UINT8_C( 49), UINT8_C(222), UINT8_C(149), UINT8_C(108), UINT8_C( 17),
      UINT8_C(  0), UINT8_C(110), UINT8_C(104), UINT8_C( 37), UINT8_C(101), UINT8_C( 48), UINT8_C( 18), UINT8_C( 96),
      UINT8_C(210), UINT8_C(209), UINT8_C(  8), UINT8_C(118), UINT8_C( 20), UINT8_C(222), UINT8_C( 79), UINT8_C( 20),
      UINT8_C(156), UINT8_C( 72), UINT8_C(235), UINT8_C(217), UINT8_C( 21), UINT8_C( 29), UINT8_C( 74), UINT8_C( 84),
      UINT8_C(221), UINT8_C(233), UINT8_C(133), UINT8_C(187), UINT8_C(126), UINT8_C(241), UINT8_C(204), UINT8_C(127),
      UINT8_C( 96), UINT8_C( 52), UINT8_C(164), UINT8_C(197), UINT8_C(100), UINT8_C(182), UINT8_C( 37), UINT8_C( 54),
      UINT8_C(135), UINT8_C( 45), UINT8_C(173), UINT8_C(156), UINT8_C( 11), UINT8_C(252), UINT8_C(176), UINT8_C(168),
      UINT8_C( 68), UINT8_C(155), UINT8_C(129), UINT8_C( 90), UINT8_C(185), UINT8_C(203), UINT8_C(174), UINT8_C(150),
      UINT8_C(180), UINT8_C( 51), UINT8_C( 81), UINT8_C( 51), UINT8_C( 37), UINT8_C( 30), UINT8_C(178), UINT8_C(133),
      UINT8_C( 82), UINT8_C( 86), UINT8_C( 74), UINT8_C(183), UINT8_C( 12), UINT8_C(111), UINT8_C(237), UINT8_C(148),
      UINT8_C(156), UINT8_C(154), UINT8_C( 48), UINT8_C(168), UINT8_C(151), UINT8_C(224), UINT8_C( 80), UINT8_C(219),
      UINT8_C(123), UINT8_C(209), UINT8_C( 53), UINT8_C( 52), UINT8_C(156), UINT8_C(227), UINT8_C(202), UINT8_C( 81),
      UINT8_C( 23), UINT8_C( 28), UINT8_C(132), UINT8_C( 60), UINT8_C( 58), UINT8_C( 54), UINT8_C(193), UINT8_C(140),
      UINT8_C(140), UINT8_C( 11), UINT8_C( 67), UINT8_C(152), UINT8_C(122), UINT8_C( 49), UINT8_C( 44), UINT8_C( 22),
      UINT8_C(203), UINT8_C( 92), UINT8_C(190), UINT8_C( 98), UINT8_C( 60), UINT8_C( 14), UINT8_C( 62), UINT8_C(184),
      UINT8_C(223), UINT8_C(115), UINT8_C(236), UINT8_C(124), UINT8_C( 87), UINT8_C(183), UINT8_C(205), UINT8_C(110),
      UINT8_C(211), UINT8_C( 81), UINT8_C(170), UINT8_C( 13), UINT8_C(135), UINT8_C(107), UINT8_C(153), UINT8_C( 19),
      UINT8_C(118), UINT8_C(221), UINT8_C(171), UINT8_C(240), UINT8_C( 14), UINT8_C(216), UINT8_C(  6), UINT8_C(217),
      UINT8_C( 52), UINT8_C(197), UINT8_C( 60), UINT8_C(113), UINT8_C(211), UINT8_C(122), UINT8_C( 41), UINT8_C(179),
      UINT8_C(237), UINT8_C( 21), UINT8_C( 47), UINT8_C( 68), UINT8_C(204), UINT8_C(252), UINT8_C(178), UINT8_C(159),
      UINT8_C( 77), UINT8_C( 92), UINT8_C(172), UINT8_C(212), UINT8_C(199), UINT8_C( 70), UINT8_C(231), UINT8_C( 61),
      UINT8_C( 35), UINT8_C(146), UINT8_C( 45), UINT8_C( 49), UINT8_C(106), UINT8_C( 52), UINT8_C( 10), UINT8_C(159),
      UINT8_C(249), UINT8_C( 70), UINT8_C( 16), UINT8_C(204), UINT8_C(192), UINT8_C( 57), UINT8_C(127), UINT8_C(174),
      UINT8_C( 78), UINT8_C(174), UINT8_C(242), UINT8_C( 27), UINT8_C(170), UINT8_C(165), UINT8_C(186), UINT8_C(247),
      UINT8_C(  1), UINT8_C(103), UINT8_C(203), UINT8_C(201), UINT8_C(173), UINT8_C(178), UINT8_C(  6), UINT8_C(208),
      UINT8_C( 69), UINT8_C( 52), UINT8_C(  1), UINT8_C(175), UINT8_C(104), UINT8_C( 11), UINT8_C( 78), UINT8_C( 97),
      UINT8_C( 82), UINT8_C( 94), UINT8_C( 45), UINT8_C( 18), UINT8_C(151), UINT8_C(173), UINT8_C(192), UINT8_C(230),
      UINT8_C( 91), UINT8_C(179), UINT8_C(  1), UINT8_C(  6), UINT8_C( 88), UINT8_C(187), UINT8_C(253), UINT8_C( 89),
      UINT8_C( 34), UINT8_C(201), UINT8_C( 34), UINT8_C(207), UINT8_C(123), UINT8_C( 41), UINT8_C(159), UINT8_C(192),
      UINT8_C( 93), UINT8_C(160), UINT8_C(112), UINT8_C(197), UINT8_C(172), UINT8_C(190), UINT8_C( 38), UINT8_C(254),
      UINT8_C( 29), UINT8_C( 83), UINT8_C( 16), UINT8_C(180), UINT8_C(  0), UINT8_C(209), UINT8_C(154), UINT8_C( 92),
      UINT8_C(132), UINT8_C(155), UINT8_C( 98), UINT8_C(220), UINT8_C( 87), UINT8_C( 95), UINT8_C( 53), UINT8_C(121),
      UINT8_C( 40), UINT8_C( 88), UINT8_C( 73), UINT8_C(164), UINT8_C(129), UINT8_C(232), UINT8_C(100), UINT8_C(222),
      UINT8_C(137), UINT8_C(212), UINT8_C(163), UINT8_C( 53), UINT8_C(147), UINT8_C(201), UINT8_C( 51), UINT8_C(176),
      UINT8_C( 28), UINT8_C( 67), UINT8_C(100), UINT8_C( 29), UINT8_C( 20),    UINT8_MAX, UINT8_C(121), UINT8_C(152),
      UINT8_C(154), UINT8_C(219), UINT8_C(116), UINT8_C(241), UINT8_C( 58), UINT8_C(170), UINT8_C(107), UINT8_C( 99),
      UINT8_C(  2), UINT8_C(180), UINT8_C(  7), UINT8_C(131), UINT8_C(156), UINT8_C(107), UINT8_C( 97), UINT8_C( 37),
      UINT8_C( 64), UINT8_C(  4), UINT8_C( 90), UINT8_C(211), UINT8_C(205), UINT8_C(141), UINT8_C(131), UINT8_C(233),
      UINT8_C(209), UINT8_C(231), UINT8_C(  6), UINT8_C(229), UINT8_C(230), UINT8_C(127), UINT8_C(126), UINT8_C(129),
      UINT8_C( 90), UINT8_C(242), UINT8_C(114), UINT8_C(149), UINT8_C(156), UINT8_C(221), UINT8_C(248), UINT8_C(158),
      UINT8_C(145),    UINT8_MAX, UINT8_C( 33), UINT8_C( 46), UINT8_C(106), UINT8_C(130), UINT8_C( 83), UINT8_C(170),
      UINT8_C(134), UINT8_C(174), UINT8_C(125), UINT8_C( 83), UINT8_C( 59), UINT8_C(  0), UINT8_C( 61), UINT8_C( 12),
      UINT8_C(232), UINT8_C( 67), UINT8_C(242), UINT8_C(206), UINT8_C(195), UINT8_C(112), UINT8_C( 79), UINT8_C( 29),
      UINT8_C( 98), UINT8_C(194), UINT8_C(178),    UINT8_MAX, UINT8_C(159), UINT8_C(170), UINT8_C(157) };
  static const uint8_t b = UINT8_C(199);
  static const uint8_t e[] =
    { UINT8_C(  0), UINT8_C( 39), UINT8_C(240), UINT8_C(  0), UINT8_C(  0), UINT8_C( 21), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 94), UINT8_C(193), UINT8_C(197), UINT8_C(  0), UINT8_C(  0), UINT8_C(146), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 23), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 91), UINT8_C(  0), UINT8_C(  0), UINT8_C( 21),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(163), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(158), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 21), UINT8_C(  0), UINT8_C(  0), UINT8_C(147), UINT8_C( 87),
      UINT8_C(  0), UINT8_C( 31), UINT8_C( 96), UINT8_C(  0), UINT8_C(  0), UINT8_C( 70), UINT8_C(172), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(232), UINT8_C(205), UINT8_C(179), UINT8_C(  0), UINT8_C(217), UINT8_C(143), UINT8_C( 70),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C( 30), UINT8_C(  0), UINT8_C( 35), UINT8_C( 49),
      UINT8_C(  0), UINT8_C( 25), UINT8_C(  0), UINT8_C(253), UINT8_C(191), UINT8_C(  0), UINT8_C(  0), UINT8_C(237),
      UINT8_C( 78), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 47), UINT8_C(172), UINT8_C(  0),
      UINT8_C(222), UINT8_C(  0), UINT8_C( 33), UINT8_C( 36), UINT8_C(  0), UINT8_C(120), UINT8_C(  0), UINT8_C( 17),
      UINT8_C( 56), UINT8_C(  0), UINT8_C(152), UINT8_C( 30), UINT8_C( 42), UINT8_C(130), UINT8_C( 22), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(235), UINT8_C(187), UINT8_C(  0), UINT8_C(  0), UINT8_C(157), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(167), UINT8_C(  0), UINT8_C(  0), UINT8_C(189), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(188),
         UINT8_MAX, UINT8_C(  0), UINT8_C(167), UINT8_C(167), UINT8_C( 83), UINT8_C(  0), UINT8_C(128), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(223), UINT8_C(  0), UINT8_C(211), UINT8_C(  0), UINT8_C( 21), UINT8_C(144), UINT8_C(  0),
      UINT8_C(200), UINT8_C(  0), UINT8_C(  0), UINT8_C(169), UINT8_C(119), UINT8_C(102), UINT8_C(  0), UINT8_C(229),
      UINT8_C(  0), UINT8_C(236), UINT8_C(105), UINT8_C(  0), UINT8_C(171), UINT8_C( 92), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 56), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 39), UINT8_C(108), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(107), UINT8_C(  0), UINT8_C(  0), UINT8_C( 72), UINT8_C( 30), UINT8_C(215), UINT8_C(  0),
      UINT8_C(247), UINT8_C(160), UINT8_C(  0), UINT8_C( 53), UINT8_C(  0), UINT8_C(  0), UINT8_C(225), UINT8_C(226),
      UINT8_C(  0), UINT8_C( 18), UINT8_C(212), UINT8_C(213), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 78), UINT8_C(  0), UINT8_C(  0), UINT8_C(129), UINT8_C(109), UINT8_C(  0),
      UINT8_C(180), UINT8_C(251), UINT8_C(190), UINT8_C(  0), UINT8_C(224), UINT8_C(  0), UINT8_C( 97), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(111), UINT8_C(  0), UINT8_C( 88), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 28), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(164),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(114), UINT8_C( 26), UINT8_C(103), UINT8_C(  0),
      UINT8_C(220), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 16), UINT8_C(159), UINT8_C(232), UINT8_C(155),
      UINT8_C(213), UINT8_C( 74), UINT8_C(186), UINT8_C(  0), UINT8_C( 85), UINT8_C(131), UINT8_C( 88), UINT8_C( 56),
      UINT8_C(231), UINT8_C(202), UINT8_C( 24), UINT8_C(  0), UINT8_C( 17), UINT8_C(  0), UINT8_C(200), UINT8_C(212),
      UINT8_C(  0), UINT8_C(116), UINT8_C(  3), UINT8_C( 29), UINT8_C( 85), UINT8_C( 49), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 15), UINT8_C( 66), UINT8_C(188), UINT8_C(  0), UINT8_C(  0), UINT8_C( 30), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(122), UINT8_C( 31), UINT8_C(  0),
      UINT8_C( 11), UINT8_C(254), UINT8_C(  0), UINT8_C(  0), UINT8_C(185), UINT8_C(  0), UINT8_C(126), UINT8_C(101),
      UINT8_C(133), UINT8_C( 72), UINT8_C( 73), UINT8_C(162), UINT8_C(  0), UINT8_C(226), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(107), UINT8_C(  0), UINT8_C(245), UINT8_C( 36), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(108), UINT8_C(  0), UINT8_C(  0), UINT8_C(202), UINT8_C(  0),
      UINT8_C(128), UINT8_C(  0), UINT8_C(173), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 61), UINT8_C( 19), UINT8_C( 10), UINT8_C(230), UINT8_C( 59), UINT8_C(190), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 34), UINT8_C(  0), UINT8_C(  0), UINT8_C(183), UINT8_C( 14), UINT8_C(147),
      UINT8_C(  0), UINT8_C(170), UINT8_C(  0), UINT8_C(102), UINT8_C( 44), UINT8_C(  0), UINT8_C(  0), UINT8_C(115),
      UINT8_C(  0), UINT8_C(164), UINT8_C( 59), UINT8_C(  0), UINT8_C(  0), UINT8_C( 47), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 52), UINT8_C(219), UINT8_C(247), UINT8_C(225), UINT8_C(221), UINT8_C(124), UINT8_C( 14), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(247), UINT8_C(  0), UINT8_C(  0), UINT8_C(117), UINT8_C(  6), UINT8_C(107), UINT8_C(  0),
      UINT8_C(119), UINT8_C(  0), UINT8_C(215), UINT8_C(106), UINT8_C(  0), UINT8_C(206), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 57), UINT8_C(  0), UINT8_C(161), UINT8_C( 94), UINT8_C(158), UINT8_C(105), UINT8_C(  0), UINT8_C(153),
      UINT8_C( 11), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(213), UINT8_C(129), UINT8_C(  0), UINT8_C(  0), UINT8_C( 78), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(244), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(184),
      UINT8_C(  0), UINT8_C(109), UINT8_C(221), UINT8_C(  0), UINT8_C(157), UINT8_C(239), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(192), UINT8_C(102), UINT8_C(230), UINT8_C(213), UINT8_C( 68), UINT8_C(  0), UINT8_C(233), UINT8_C(  0),
      UINT8_C(125), UINT8_C(  0), UINT8_C(  0), UINT8_C(147), UINT8_C(242), UINT8_C(  4), UINT8_C(  0), UINT8_C(207),
      UINT8_C(237), UINT8_C(  0), UINT8_C(138), UINT8_C(108), UINT8_C( 94), UINT8_C( 87), UINT8_C(235), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(240), UINT8_C( 69), UINT8_C(168), UINT8_C(  0), UINT8_C(205),
      UINT8_C(  0), UINT8_C(211), UINT8_C(105), UINT8_C(  0), UINT8_C(208), UINT8_C(  0), UINT8_C(  0), UINT8_C( 20),
      UINT8_C(180), UINT8_C( 10), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 85), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(111), UINT8_C(  0), UINT8_C(197),
      UINT8_C(197), UINT8_C( 68), UINT8_C(  0), UINT8_C(209), UINT8_C(179), UINT8_C(  0), UINT8_C(  0), UINT8_C( 79),
      UINT8_C(  0), UINT8_C(149), UINT8_C(247), UINT8_C(155), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(241),
      UINT8_C(  0), UINT8_C(172), UINT8_C(  0), UINT8_C(  0), UINT8_C(144), UINT8_C(  0), UINT8_C(  6), UINT8_C(  0),
      UINT8_C( 12), UINT8_C(138), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(210), UINT8_C( 76),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 41), UINT8_C( 71), UINT8_C( 17), UINT8_C(  0), UINT8_C( 18),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(117), UINT8_C(170), UINT8_C( 12), UINT8_C(  0), UINT8_C(  0), UINT8_C(236),
      UINT8_C( 38), UINT8_C( 78), UINT8_C(  0), UINT8_C(125), UINT8_C(  5), UINT8_C( 53), UINT8_C(235), UINT8_C(216),
      UINT8_C(  0), UINT8_C(149), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(127), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(203), UINT8_C(102), UINT8_C(106), UINT8_C(163), UINT8_C(  0), UINT8_C( 67), UINT8_C(  0),
      UINT8_C( 50), UINT8_C(  0), UINT8_C( 73), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(184), UINT8_C(  0),
      UINT8_C(135), UINT8_C(231), UINT8_C( 43), UINT8_C( 84), UINT8_C(227), UINT8_C(  0), UINT8_C(  0), UINT8_C( 48),
      UINT8_C(  0), UINT8_C(160), UINT8_C(  0), UINT8_C(  0), UINT8_C(230), UINT8_C(235), UINT8_C(  0), UINT8_C(  9),
      UINT8_C(126), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 68), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(151), UINT8_C(  0), UINT8_C( 75), UINT8_C(208), UINT8_C(  0), UINT8_C(249), UINT8_C( 31),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 63), UINT8_C(145), UINT8_C(244), UINT8_C( 54), UINT8_C(146),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 91), UINT8_C(  8), UINT8_C(180), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(150), UINT8_C(217), UINT8_C(169), UINT8_C(  0), UINT8_C(229), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 86), UINT8_C(140), UINT8_C( 73), UINT8_C(237), UINT8_C( 57), UINT8_C(  0), UINT8_C(211), UINT8_C(  0),
      UINT8_C(189), UINT8_C(212), UINT8_C(155), UINT8_C(  0), UINT8_C(144), UINT8_C(152), UINT8_C(110), UINT8_C(178),
      UINT8_C( 97), UINT8_C(145), UINT8_C(130), UINT8_C(221), UINT8_C(  0), UINT8_C( 33), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(194), UINT8_C( 13), UINT8_C(  0), UINT8_C(110), UINT8_C(204), UINT8_C(  2), UINT8_C(108), UINT8_C(233),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(157), UINT8_C(  0), UINT8_C( 77), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 42), UINT8_C(115), UINT8_C(  0), UINT8_C(  0), UINT8_C(156),
      UINT8_C( 59), UINT8_C(237), UINT8_C(  0), UINT8_C(  0), UINT8_C(213), UINT8_C(  0), UINT8_C(  0), UINT8_C( 94),
      UINT8_C(121), UINT8_C( 61), UINT8_C(147), UINT8_C( 12), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 10), UINT8_C(  0), UINT8_C( 63), UINT8_C(  0), UINT8_C(  0), UINT8_C(184), UINT8_C(183), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 43), UINT8_C(  0), UINT8_C(  0), UINT8_C(213), UINT8_C( 22), UINT8_C( 49), UINT8_C(215),
      UINT8_C(202), UINT8_C( 56), UINT8_C(  0), UINT8_C(103), UINT8_C(163), UINT8_C(  0), UINT8_C(  0), UINT8_C(227),
      UINT8_C(191), UINT8_C(231), UINT8_C(182), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(118), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 43), UINT8_C(  7), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(216), UINT8_C(227), UINT8_C(  0) };

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
    rv = simde_svsub_n_u8_z(pv, av, b);

    simde_svst1_u8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vu8(len, e, r);

  return 0;
#else
  int8_t p[1024];
  uint8_t a[1024], b, e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_u8(pg, &(a[i]));

    ev = simde_svsub_n_u8_z(pv, av, b);

    simde_svst1_u8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u8(1, b);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_u8_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1) };
  static const uint8_t a[] =
    { UINT8_C( 19), UINT8_C(144), UINT8_C(202), UINT8_C(150), UINT8_C(250), UINT8_C(215), UINT8_C( 18), UINT8_C(109),
      UINT8_C(209), UINT8_C(110), UINT8_C( 69), UINT8_C(118), UINT8_C(184), UINT8_C(202), UINT8_C(228), UINT8_C(102),
      UINT8_C( 81), UINT8_C(122), UINT8_C(124), UINT8_C(122), UINT8_C(  2), UINT8_C(165), UINT8_C(246), UINT8_C(  1),
      UINT8_C(219), UINT8_C(150), UINT8_C( 66), UINT8_C(229), UINT8_C( 95), UINT8_C(243), UINT8_C(226), UINT8_C(114),
      UINT8_C(132), UINT8_C(172), UINT8_C(  9), UINT8_C(126), UINT8_C(131), UINT8_C( 27), UINT8_C(235), UINT8_C( 85),
      UINT8_C(137), UINT8_C( 49), UINT8_C(203), UINT8_C( 65), UINT8_C(251), UINT8_C(175), UINT8_C(168), UINT8_C( 76),
      UINT8_C( 41), UINT8_C( 36), UINT8_C(199), UINT8_C( 43), UINT8_C(201), UINT8_C(189), UINT8_C( 44), UINT8_C(164),
      UINT8_C( 84), UINT8_C(111), UINT8_C(137), UINT8_C(179), UINT8_C( 98), UINT8_C(107), UINT8_C( 38), UINT8_C(230),
      UINT8_C( 23), UINT8_C( 47), UINT8_C(101), UINT8_C(155), UINT8_C( 74), UINT8_C( 80), UINT8_C(240), UINT8_C(212),
      UINT8_C(129), UINT8_C(187), UINT8_C( 21), UINT8_C(124), UINT8_C(106), UINT8_C(189), UINT8_C(201), UINT8_C(147),
      UINT8_C(225), UINT8_C(144), UINT8_C(190), UINT8_C(171), UINT8_C( 77), UINT8_C(235), UINT8_C( 79), UINT8_C(161),
      UINT8_C( 90), UINT8_C(217), UINT8_C( 85), UINT8_C(188), UINT8_C( 68), UINT8_C(123), UINT8_C(163), UINT8_C( 92),
      UINT8_C(170), UINT8_C(  8), UINT8_C(247), UINT8_C(244), UINT8_C( 88), UINT8_C(231), UINT8_C(200), UINT8_C(218),
      UINT8_C(162), UINT8_C(222), UINT8_C( 86), UINT8_C( 12), UINT8_C(155), UINT8_C( 31), UINT8_C(159), UINT8_C(125),
      UINT8_C(175), UINT8_C( 93), UINT8_C( 40), UINT8_C(253), UINT8_C( 72), UINT8_C(119), UINT8_C(158), UINT8_C(162),
      UINT8_C( 80), UINT8_C(243), UINT8_C( 95), UINT8_C(149), UINT8_C(110), UINT8_C(  2), UINT8_C(241), UINT8_C( 24),
      UINT8_C( 10), UINT8_C(232), UINT8_C( 13), UINT8_C( 98), UINT8_C(207), UINT8_C(213), UINT8_C( 60), UINT8_C(113),
      UINT8_C(179), UINT8_C(147), UINT8_C(125), UINT8_C( 79), UINT8_C(178), UINT8_C( 28), UINT8_C(204), UINT8_C( 98),
      UINT8_C(121), UINT8_C(244), UINT8_C( 95), UINT8_C(194), UINT8_C(107), UINT8_C(253), UINT8_C(100), UINT8_C(188),
      UINT8_C(241), UINT8_C(195), UINT8_C( 81), UINT8_C( 95), UINT8_C(197), UINT8_C( 66), UINT8_C(120), UINT8_C(207),
      UINT8_C( 42), UINT8_C(133), UINT8_C( 50), UINT8_C(249), UINT8_C( 90), UINT8_C(110), UINT8_C(106), UINT8_C( 14),
      UINT8_C(  1), UINT8_C(231), UINT8_C( 93), UINT8_C(180), UINT8_C(  3), UINT8_C( 41), UINT8_C( 22), UINT8_C(124),
      UINT8_C( 29), UINT8_C(117), UINT8_C( 62), UINT8_C(136), UINT8_C(114), UINT8_C(163), UINT8_C( 68), UINT8_C( 99),
      UINT8_C(102), UINT8_C(149), UINT8_C(195), UINT8_C( 44), UINT8_C(215), UINT8_C( 59), UINT8_C(251), UINT8_C(  1),
      UINT8_C(192), UINT8_C( 45), UINT8_C(250), UINT8_C( 26), UINT8_C(156), UINT8_C(100), UINT8_C( 40), UINT8_C(157),
      UINT8_C( 75), UINT8_C(133), UINT8_C( 81), UINT8_C( 78), UINT8_C(174), UINT8_C(103), UINT8_C(203), UINT8_C(203),
      UINT8_C(220), UINT8_C(  9), UINT8_C( 84), UINT8_C( 79), UINT8_C(172), UINT8_C(152), UINT8_C(178), UINT8_C( 19),
      UINT8_C( 46), UINT8_C(117), UINT8_C( 63), UINT8_C(  5), UINT8_C(176), UINT8_C( 58), UINT8_C(  7), UINT8_C(112),
      UINT8_C(104), UINT8_C(  1), UINT8_C(139), UINT8_C(  4), UINT8_C(102), UINT8_C(179), UINT8_C(161), UINT8_C(177),
      UINT8_C( 57), UINT8_C(243), UINT8_C(  0), UINT8_C(231), UINT8_C( 90), UINT8_C(203), UINT8_C(179), UINT8_C( 55),
      UINT8_C(212), UINT8_C(  7), UINT8_C(134), UINT8_C(129), UINT8_C(159), UINT8_C( 56), UINT8_C(148), UINT8_C(205),
      UINT8_C(174), UINT8_C(211), UINT8_C(211), UINT8_C( 94), UINT8_C( 13), UINT8_C(218), UINT8_C(207), UINT8_C(117),
      UINT8_C(219), UINT8_C( 90), UINT8_C(121), UINT8_C( 65), UINT8_C( 13), UINT8_C( 27), UINT8_C(243), UINT8_C( 70),
      UINT8_C( 14), UINT8_C(243), UINT8_C( 46), UINT8_C(104), UINT8_C(190), UINT8_C(225), UINT8_C(159), UINT8_C(146),
      UINT8_C(232), UINT8_C( 37), UINT8_C( 19), UINT8_C(135), UINT8_C( 94), UINT8_C(167), UINT8_C( 85), UINT8_C( 12),
      UINT8_C(122), UINT8_C( 40), UINT8_C(106), UINT8_C(136), UINT8_C(  2), UINT8_C( 57), UINT8_C(253), UINT8_C(221),
      UINT8_C(147), UINT8_C(119), UINT8_C( 31), UINT8_C(161), UINT8_C(146), UINT8_C( 18), UINT8_C(231), UINT8_C(160),
      UINT8_C(  5), UINT8_C( 21), UINT8_C(  8), UINT8_C(195), UINT8_C(246), UINT8_C(168), UINT8_C( 85), UINT8_C(222),
      UINT8_C(205), UINT8_C(105), UINT8_C(102), UINT8_C( 43), UINT8_C( 16), UINT8_C(187), UINT8_C( 55), UINT8_C(139),
      UINT8_C(227), UINT8_C(162), UINT8_C( 19), UINT8_C(229), UINT8_C(219), UINT8_C( 16), UINT8_C(194), UINT8_C(111),
      UINT8_C(135), UINT8_C(225), UINT8_C( 16), UINT8_C( 25), UINT8_C(243), UINT8_C(247), UINT8_C(185), UINT8_C(248),
      UINT8_C( 13), UINT8_C(194), UINT8_C(187), UINT8_C(  3), UINT8_C(106), UINT8_C( 17), UINT8_C(226), UINT8_C( 55),
      UINT8_C(122), UINT8_C( 72), UINT8_C( 99), UINT8_C(138), UINT8_C(  3), UINT8_C(154), UINT8_C( 21), UINT8_C(230),
      UINT8_C( 60), UINT8_C( 40), UINT8_C(203), UINT8_C( 24), UINT8_C( 57), UINT8_C(141), UINT8_C(135), UINT8_C(192),
      UINT8_C(111), UINT8_C(151), UINT8_C(218), UINT8_C( 98), UINT8_C(142), UINT8_C(147), UINT8_C( 91), UINT8_C(155),
      UINT8_C( 85), UINT8_C( 22), UINT8_C(159), UINT8_C(191), UINT8_C( 39), UINT8_C(129), UINT8_C(247), UINT8_C(161),
      UINT8_C(201), UINT8_C( 90), UINT8_C( 44), UINT8_C(204), UINT8_C(244), UINT8_C( 65), UINT8_C(178), UINT8_C( 49),
      UINT8_C(106), UINT8_C(125), UINT8_C( 73), UINT8_C(163), UINT8_C( 10), UINT8_C(208), UINT8_C( 99), UINT8_C(121),
      UINT8_C(103), UINT8_C( 61), UINT8_C(220), UINT8_C(245), UINT8_C(209), UINT8_C( 55), UINT8_C(145), UINT8_C( 38),
      UINT8_C( 77), UINT8_C( 48), UINT8_C(230), UINT8_C(117), UINT8_C(177), UINT8_C(221), UINT8_C( 22), UINT8_C(122),
      UINT8_C( 55), UINT8_C( 66), UINT8_C( 70), UINT8_C( 43), UINT8_C(132), UINT8_C(248), UINT8_C( 92), UINT8_C(238),
      UINT8_C(117), UINT8_C(165), UINT8_C(145), UINT8_C(127), UINT8_C(117), UINT8_C(244), UINT8_C(249), UINT8_C(220),
      UINT8_C( 50), UINT8_C(213), UINT8_C(210), UINT8_C(  3), UINT8_C( 12), UINT8_C( 99), UINT8_C( 41), UINT8_C( 89),
      UINT8_C(147), UINT8_C( 15), UINT8_C(206), UINT8_C( 68), UINT8_C(236), UINT8_C(229), UINT8_C(190), UINT8_C( 35),
      UINT8_C( 39), UINT8_C(  4), UINT8_C( 79), UINT8_C(171), UINT8_C(252), UINT8_C(171), UINT8_C(153), UINT8_C(113),
      UINT8_C( 81), UINT8_C( 42), UINT8_C(240), UINT8_C(198), UINT8_C( 31), UINT8_C(233), UINT8_C(163), UINT8_C( 81),
      UINT8_C(190), UINT8_C(117), UINT8_C( 84), UINT8_C(202), UINT8_C(216), UINT8_C(125), UINT8_C( 36), UINT8_C(107),
      UINT8_C(141), UINT8_C(242), UINT8_C(175), UINT8_C(121), UINT8_C(215), UINT8_C(109), UINT8_C(157),    UINT8_MAX,
      UINT8_C(113), UINT8_C(236), UINT8_C(170), UINT8_C(109), UINT8_C(151), UINT8_C( 68), UINT8_C(222), UINT8_C(232),
      UINT8_C(110), UINT8_C(206), UINT8_C(175), UINT8_C(141), UINT8_C(184), UINT8_C( 82), UINT8_C(222), UINT8_C(118),
      UINT8_C(199), UINT8_C( 50), UINT8_C( 65), UINT8_C(159), UINT8_C(176), UINT8_C(101), UINT8_C( 10), UINT8_C( 61),
      UINT8_C( 87), UINT8_C(185), UINT8_C(182), UINT8_C( 47), UINT8_C( 38), UINT8_C( 83), UINT8_C( 46), UINT8_C(151),
      UINT8_C( 63), UINT8_C(216), UINT8_C(  4), UINT8_C(215), UINT8_C( 28), UINT8_C(226), UINT8_C(191), UINT8_C(139),
      UINT8_C(176), UINT8_C(110), UINT8_C( 24), UINT8_C(104), UINT8_C(192), UINT8_C(247), UINT8_C(223), UINT8_C(135),
      UINT8_C( 41), UINT8_C( 32), UINT8_C( 38), UINT8_C(217), UINT8_C(133), UINT8_C( 48), UINT8_C( 22), UINT8_C(220),
      UINT8_C(233), UINT8_C(205), UINT8_C( 11), UINT8_C( 15), UINT8_C( 32), UINT8_C( 57), UINT8_C(166), UINT8_C( 96),
      UINT8_C( 18), UINT8_C(170), UINT8_C( 55), UINT8_C( 46), UINT8_C(140), UINT8_C(246), UINT8_C(185), UINT8_C( 61),
      UINT8_C(101), UINT8_C(210), UINT8_C(165), UINT8_C( 37), UINT8_C(201), UINT8_C(132), UINT8_C(173), UINT8_C(242),
      UINT8_C(164), UINT8_C(211), UINT8_C(204), UINT8_C( 41), UINT8_C(  4), UINT8_C(226), UINT8_C(  6), UINT8_C(237),
      UINT8_C(175), UINT8_C( 17) };
  static const uint8_t b = UINT8_C(196);
  static const uint8_t e[] =
    { UINT8_C( 79), UINT8_C(204), UINT8_C(202), UINT8_C(210), UINT8_C(250), UINT8_C( 19), UINT8_C( 18), UINT8_C(109),
      UINT8_C( 13), UINT8_C(110), UINT8_C( 69), UINT8_C(118), UINT8_C(184), UINT8_C(202), UINT8_C(228), UINT8_C(102),
      UINT8_C(141), UINT8_C(182), UINT8_C(184), UINT8_C(122), UINT8_C(  2), UINT8_C(165), UINT8_C( 50), UINT8_C(  1),
      UINT8_C(219), UINT8_C(210), UINT8_C( 66), UINT8_C( 33), UINT8_C( 95), UINT8_C(243), UINT8_C(226), UINT8_C(174),
      UINT8_C(192), UINT8_C(232), UINT8_C( 69), UINT8_C(126), UINT8_C(131), UINT8_C( 27), UINT8_C( 39), UINT8_C(145),
      UINT8_C(137), UINT8_C( 49), UINT8_C(203), UINT8_C( 65), UINT8_C(251), UINT8_C(175), UINT8_C(228), UINT8_C( 76),
      UINT8_C( 41), UINT8_C( 36), UINT8_C(  3), UINT8_C( 43), UINT8_C(  5), UINT8_C(189), UINT8_C(104), UINT8_C(224),
      UINT8_C( 84), UINT8_C(171), UINT8_C(137), UINT8_C(179), UINT8_C( 98), UINT8_C(167), UINT8_C( 38), UINT8_C(230),
      UINT8_C( 23), UINT8_C( 47), UINT8_C(161), UINT8_C(155), UINT8_C( 74), UINT8_C( 80), UINT8_C(240), UINT8_C( 16),
      UINT8_C(129), UINT8_C(247), UINT8_C( 81), UINT8_C(184), UINT8_C(106), UINT8_C(189), UINT8_C(  5), UINT8_C(147),
      UINT8_C( 29), UINT8_C(144), UINT8_C(250), UINT8_C(171), UINT8_C( 77), UINT8_C( 39), UINT8_C( 79), UINT8_C(161),
      UINT8_C(150), UINT8_C( 21), UINT8_C(145), UINT8_C(248), UINT8_C( 68), UINT8_C(123), UINT8_C(223), UINT8_C(152),
      UINT8_C(170), UINT8_C(  8), UINT8_C(247), UINT8_C(244), UINT8_C( 88), UINT8_C( 35), UINT8_C(200), UINT8_C( 22),
      UINT8_C(222), UINT8_C( 26), UINT8_C( 86), UINT8_C( 72), UINT8_C(155), UINT8_C( 91), UINT8_C(159), UINT8_C(125),
      UINT8_C(235), UINT8_C( 93), UINT8_C( 40), UINT8_C(253), UINT8_C( 72), UINT8_C(179), UINT8_C(218), UINT8_C(222),
      UINT8_C(140), UINT8_C(243), UINT8_C( 95), UINT8_C(149), UINT8_C(170), UINT8_C(  2), UINT8_C( 45), UINT8_C( 84),
      UINT8_C( 10), UINT8_C(232), UINT8_C( 13), UINT8_C(158), UINT8_C( 11), UINT8_C(213), UINT8_C( 60), UINT8_C(113),
      UINT8_C(179), UINT8_C(147), UINT8_C(125), UINT8_C(139), UINT8_C(178), UINT8_C( 88), UINT8_C(  8), UINT8_C( 98),
      UINT8_C(121), UINT8_C(244), UINT8_C( 95), UINT8_C(194), UINT8_C(107), UINT8_C(253), UINT8_C(160), UINT8_C(248),
      UINT8_C( 45), UINT8_C(195), UINT8_C(141), UINT8_C( 95), UINT8_C(  1), UINT8_C( 66), UINT8_C(120), UINT8_C(207),
      UINT8_C(102), UINT8_C(133), UINT8_C(110), UINT8_C(249), UINT8_C(150), UINT8_C(110), UINT8_C(166), UINT8_C( 14),
      UINT8_C( 61), UINT8_C(231), UINT8_C(153), UINT8_C(240), UINT8_C(  3), UINT8_C(101), UINT8_C( 22), UINT8_C(124),
      UINT8_C( 89), UINT8_C(117), UINT8_C(122), UINT8_C(196), UINT8_C(174), UINT8_C(223), UINT8_C( 68), UINT8_C( 99),
      UINT8_C(162), UINT8_C(149), UINT8_C(195), UINT8_C(104), UINT8_C( 19), UINT8_C( 59), UINT8_C( 55), UINT8_C(  1),
      UINT8_C(252), UINT8_C( 45), UINT8_C(250), UINT8_C( 86), UINT8_C(216), UINT8_C(100), UINT8_C(100), UINT8_C(157),
      UINT8_C( 75), UINT8_C(133), UINT8_C( 81), UINT8_C( 78), UINT8_C(234), UINT8_C(103), UINT8_C(  7), UINT8_C(  7),
      UINT8_C( 24), UINT8_C(  9), UINT8_C(144), UINT8_C( 79), UINT8_C(232), UINT8_C(152), UINT8_C(238), UINT8_C( 79),
      UINT8_C( 46), UINT8_C(117), UINT8_C( 63), UINT8_C( 65), UINT8_C(176), UINT8_C( 58), UINT8_C( 67), UINT8_C(112),
      UINT8_C(104), UINT8_C(  1), UINT8_C(199), UINT8_C(  4), UINT8_C(102), UINT8_C(239), UINT8_C(221), UINT8_C(237),
      UINT8_C(117), UINT8_C( 47), UINT8_C( 60), UINT8_C( 35), UINT8_C( 90), UINT8_C(  7), UINT8_C(239), UINT8_C( 55),
      UINT8_C( 16), UINT8_C(  7), UINT8_C(134), UINT8_C(189), UINT8_C(159), UINT8_C(116), UINT8_C(208), UINT8_C(205),
      UINT8_C(234), UINT8_C( 15), UINT8_C( 15), UINT8_C( 94), UINT8_C( 73), UINT8_C( 22), UINT8_C( 11), UINT8_C(117),
      UINT8_C( 23), UINT8_C(150), UINT8_C(181), UINT8_C(125), UINT8_C( 13), UINT8_C( 27), UINT8_C(243), UINT8_C( 70),
      UINT8_C( 14), UINT8_C(243), UINT8_C( 46), UINT8_C(164), UINT8_C(250), UINT8_C( 29), UINT8_C(219), UINT8_C(206),
      UINT8_C( 36), UINT8_C( 37), UINT8_C( 19), UINT8_C(195), UINT8_C( 94), UINT8_C(227), UINT8_C(145), UINT8_C( 72),
      UINT8_C(182), UINT8_C(100), UINT8_C(106), UINT8_C(196), UINT8_C(  2), UINT8_C( 57), UINT8_C(253), UINT8_C( 25),
      UINT8_C(147), UINT8_C(119), UINT8_C( 91), UINT8_C(161), UINT8_C(146), UINT8_C( 78), UINT8_C( 35), UINT8_C(220),
      UINT8_C( 65), UINT8_C( 81), UINT8_C(  8),    UINT8_MAX, UINT8_C(246), UINT8_C(168), UINT8_C( 85), UINT8_C( 26),
      UINT8_C(205), UINT8_C(165), UINT8_C(102), UINT8_C( 43), UINT8_C( 76), UINT8_C(187), UINT8_C( 55), UINT8_C(199),
      UINT8_C(227), UINT8_C(222), UINT8_C( 19), UINT8_C(229), UINT8_C( 23), UINT8_C( 76), UINT8_C(194), UINT8_C(171),
      UINT8_C(195), UINT8_C( 29), UINT8_C( 16), UINT8_C( 25), UINT8_C(243), UINT8_C( 51), UINT8_C(245), UINT8_C(248),
      UINT8_C( 13), UINT8_C(194), UINT8_C(187), UINT8_C( 63), UINT8_C(106), UINT8_C( 77), UINT8_C(226), UINT8_C(115),
      UINT8_C(122), UINT8_C(132), UINT8_C(159), UINT8_C(198), UINT8_C(  3), UINT8_C(154), UINT8_C( 21), UINT8_C(230),
      UINT8_C(120), UINT8_C(100), UINT8_C(  7), UINT8_C( 84), UINT8_C( 57), UINT8_C(201), UINT8_C(195), UINT8_C(252),
      UINT8_C(111), UINT8_C(211), UINT8_C(218), UINT8_C(158), UINT8_C(202), UINT8_C(207), UINT8_C( 91), UINT8_C(215),
      UINT8_C( 85), UINT8_C( 22), UINT8_C(219), UINT8_C(251), UINT8_C( 99), UINT8_C(189), UINT8_C(247), UINT8_C(161),
      UINT8_C(  5), UINT8_C( 90), UINT8_C( 44), UINT8_C(  8), UINT8_C(244), UINT8_C( 65), UINT8_C(238), UINT8_C(109),
      UINT8_C(106), UINT8_C(125), UINT8_C(133), UINT8_C(163), UINT8_C( 70), UINT8_C(208), UINT8_C( 99), UINT8_C(121),
      UINT8_C(163), UINT8_C( 61), UINT8_C(220), UINT8_C(245), UINT8_C(209), UINT8_C( 55), UINT8_C(145), UINT8_C( 38),
      UINT8_C(137), UINT8_C(108), UINT8_C(230), UINT8_C(177), UINT8_C(237), UINT8_C(221), UINT8_C( 82), UINT8_C(122),
      UINT8_C( 55), UINT8_C( 66), UINT8_C(130), UINT8_C(103), UINT8_C(132), UINT8_C( 52), UINT8_C(152), UINT8_C(238),
      UINT8_C(117), UINT8_C(165), UINT8_C(205), UINT8_C(127), UINT8_C(117), UINT8_C(244), UINT8_C(249), UINT8_C(220),
      UINT8_C(110), UINT8_C(213), UINT8_C( 14), UINT8_C( 63), UINT8_C( 72), UINT8_C( 99), UINT8_C( 41), UINT8_C(149),
      UINT8_C(147), UINT8_C( 75), UINT8_C(206), UINT8_C(128), UINT8_C( 40), UINT8_C(229), UINT8_C(190), UINT8_C( 35),
      UINT8_C( 39), UINT8_C(  4), UINT8_C(139), UINT8_C(231), UINT8_C( 56), UINT8_C(171), UINT8_C(153), UINT8_C(173),
      UINT8_C(141), UINT8_C( 42), UINT8_C(240), UINT8_C(  2), UINT8_C( 31), UINT8_C(233), UINT8_C(223), UINT8_C( 81),
      UINT8_C(250), UINT8_C(117), UINT8_C( 84), UINT8_C(  6), UINT8_C(216), UINT8_C(185), UINT8_C( 36), UINT8_C(167),
      UINT8_C(141), UINT8_C( 46), UINT8_C(175), UINT8_C(181), UINT8_C(215), UINT8_C(169), UINT8_C(157), UINT8_C( 59),
      UINT8_C(173), UINT8_C( 40), UINT8_C(170), UINT8_C(169), UINT8_C(151), UINT8_C(128), UINT8_C( 26), UINT8_C( 36),
      UINT8_C(170), UINT8_C( 10), UINT8_C(235), UINT8_C(141), UINT8_C(244), UINT8_C( 82), UINT8_C(222), UINT8_C(178),
      UINT8_C(  3), UINT8_C( 50), UINT8_C( 65), UINT8_C(159), UINT8_C(236), UINT8_C(161), UINT8_C( 70), UINT8_C( 61),
      UINT8_C( 87), UINT8_C(185), UINT8_C(242), UINT8_C( 47), UINT8_C( 98), UINT8_C( 83), UINT8_C( 46), UINT8_C(211),
      UINT8_C( 63), UINT8_C(216), UINT8_C(  4), UINT8_C(215), UINT8_C( 28), UINT8_C( 30), UINT8_C(191), UINT8_C(139),
      UINT8_C(176), UINT8_C(170), UINT8_C( 24), UINT8_C(104), UINT8_C(192), UINT8_C( 51), UINT8_C(223), UINT8_C(135),
      UINT8_C( 41), UINT8_C( 32), UINT8_C( 98), UINT8_C(217), UINT8_C(193), UINT8_C(108), UINT8_C( 22), UINT8_C(220),
      UINT8_C(233), UINT8_C(205), UINT8_C( 71), UINT8_C( 75), UINT8_C( 32), UINT8_C(117), UINT8_C(226), UINT8_C( 96),
      UINT8_C( 18), UINT8_C(230), UINT8_C(115), UINT8_C( 46), UINT8_C(200), UINT8_C( 50), UINT8_C(185), UINT8_C( 61),
      UINT8_C(161), UINT8_C( 14), UINT8_C(225), UINT8_C( 37), UINT8_C(  5), UINT8_C(192), UINT8_C(233), UINT8_C( 46),
      UINT8_C(164), UINT8_C(211), UINT8_C(  8), UINT8_C( 41), UINT8_C(  4), UINT8_C(226), UINT8_C(  6), UINT8_C(237),
      UINT8_C(175), UINT8_C( 77) };

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
    rv = simde_svsub_n_u8_m(pv, av, b);

    simde_svst1_u8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vu8(len, e, r);

  return 0;
#else
  int8_t p[1024];
  uint8_t a[1024], b, e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_u8(pg, &(a[i]));

    ev = simde_svsub_n_u8_m(pv, av, b);

    simde_svst1_u8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u8(1, b);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_u16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) };
  static const uint16_t a[] =
    { UINT16_C(46583), UINT16_C(14044), UINT16_C(24634), UINT16_C(11759), UINT16_C(16912), UINT16_C(28693), UINT16_C(16840), UINT16_C(45485),
      UINT16_C(41311), UINT16_C( 8618), UINT16_C(29732), UINT16_C(20025), UINT16_C(60251), UINT16_C(21935), UINT16_C(61417), UINT16_C(57386),
      UINT16_C( 1700), UINT16_C(56854), UINT16_C( 1639), UINT16_C(30475), UINT16_C( 8264), UINT16_C( 4328), UINT16_C(38242), UINT16_C(49601),
      UINT16_C(27703), UINT16_C(23522), UINT16_C( 7136), UINT16_C(15273), UINT16_C(22534), UINT16_C(61584), UINT16_C(47943), UINT16_C(60368),
      UINT16_C(59329), UINT16_C(10442), UINT16_C(54765), UINT16_C(13728), UINT16_C(35062), UINT16_C(22598), UINT16_C( 1821), UINT16_C(21529),
      UINT16_C(64371), UINT16_C(21679), UINT16_C(22806), UINT16_C( 7311), UINT16_C( 8369), UINT16_C(63756), UINT16_C(56795), UINT16_C(40164),
      UINT16_C(44740), UINT16_C(45509), UINT16_C(25988), UINT16_C(31462), UINT16_C(11501), UINT16_C( 2770), UINT16_C(60212), UINT16_C(42847),
      UINT16_C( 3814), UINT16_C(64763), UINT16_C(35687), UINT16_C( 6424), UINT16_C( 9643), UINT16_C(34322), UINT16_C(62978), UINT16_C(50722),
      UINT16_C(59301), UINT16_C(10615), UINT16_C(23884), UINT16_C(14755), UINT16_C(30090), UINT16_C(48708), UINT16_C(41824), UINT16_C(18021),
      UINT16_C(25009), UINT16_C( 6466), UINT16_C(23276), UINT16_C(38706), UINT16_C(17535), UINT16_C(33053), UINT16_C(16186), UINT16_C(57159),
      UINT16_C(48679), UINT16_C(29448), UINT16_C(43804), UINT16_C(42669), UINT16_C(61728), UINT16_C(32868), UINT16_C(51604), UINT16_C(17862),
      UINT16_C( 2090), UINT16_C( 5726), UINT16_C(36963), UINT16_C(58029), UINT16_C(51924), UINT16_C( 3940), UINT16_C(43786), UINT16_C(12782),
      UINT16_C(63338), UINT16_C(34468), UINT16_C(20898), UINT16_C(49964), UINT16_C(36930), UINT16_C(54851), UINT16_C( 2649), UINT16_C(33820),
      UINT16_C(31250), UINT16_C(30106), UINT16_C(18443), UINT16_C(57176), UINT16_C(48146), UINT16_C( 7406), UINT16_C(56679), UINT16_C(53581),
      UINT16_C(62164), UINT16_C(30295), UINT16_C(33603), UINT16_C(34361), UINT16_C(32019), UINT16_C(27996), UINT16_C(30855), UINT16_C(39409),
      UINT16_C(35827), UINT16_C(65039), UINT16_C(26579), UINT16_C(59101), UINT16_C(52259), UINT16_C(35330), UINT16_C(20649), UINT16_C(32092),
      UINT16_C(45890), UINT16_C(34291), UINT16_C(11575), UINT16_C(18955), UINT16_C(26794), UINT16_C(12727), UINT16_C(43232), UINT16_C(54218),
      UINT16_C(55604), UINT16_C( 2001), UINT16_C(44864), UINT16_C(25581), UINT16_C(61563), UINT16_C( 9454), UINT16_C(19008), UINT16_C(33441),
      UINT16_C(38141), UINT16_C(13319), UINT16_C( 5057), UINT16_C(27519), UINT16_C(13947), UINT16_C(23452), UINT16_C(26591), UINT16_C( 4911),
      UINT16_C(   64), UINT16_C(33050), UINT16_C( 2223), UINT16_C(10980), UINT16_C(54008), UINT16_C(14414), UINT16_C(61212), UINT16_C( 6842),
      UINT16_C(49540), UINT16_C(17742), UINT16_C(52692), UINT16_C(20401), UINT16_C(19716), UINT16_C(58283), UINT16_C(55988), UINT16_C(62966),
      UINT16_C( 4314), UINT16_C(35446), UINT16_C(23064), UINT16_C( 4276), UINT16_C(  813), UINT16_C(18760), UINT16_C(  754), UINT16_C(30307),
      UINT16_C(45764), UINT16_C(39100), UINT16_C(28031), UINT16_C(33768), UINT16_C(37818), UINT16_C(28518), UINT16_C(23661), UINT16_C(18276),
      UINT16_C(55917), UINT16_C(34257), UINT16_C(34356), UINT16_C(24982), UINT16_C(56969), UINT16_C(31659), UINT16_C( 3809), UINT16_C(42482),
      UINT16_C(44736), UINT16_C(16445), UINT16_C( 9499), UINT16_C(54723), UINT16_C(10936), UINT16_C( 9540), UINT16_C(43142), UINT16_C(62317),
      UINT16_C(16002), UINT16_C(46969), UINT16_C( 4036), UINT16_C(19736), UINT16_C(50157), UINT16_C(52937), UINT16_C(48082), UINT16_C(37491),
      UINT16_C(45417), UINT16_C(34002), UINT16_C(38614), UINT16_C(36697), UINT16_C(40640), UINT16_C(18100), UINT16_C( 8518), UINT16_C(51514),
      UINT16_C(45920), UINT16_C( 9344), UINT16_C(39106), UINT16_C(44914), UINT16_C(15196), UINT16_C(11902), UINT16_C(61942), UINT16_C(24512),
      UINT16_C(37794), UINT16_C(31203), UINT16_C(15401), UINT16_C(59656), UINT16_C(48346), UINT16_C( 8495), UINT16_C(27102), UINT16_C(16106),
      UINT16_C(27164), UINT16_C(56930), UINT16_C(54274), UINT16_C(24206), UINT16_C( 3087), UINT16_C( 1420), UINT16_C(19965), UINT16_C(41060),
      UINT16_C(18400), UINT16_C( 2329), UINT16_C( 8580), UINT16_C(24306), UINT16_C( 8669), UINT16_C(47999), UINT16_C(27019), UINT16_C(43001),
      UINT16_C(23763), UINT16_C(54918), UINT16_C( 5168), UINT16_C(16436), UINT16_C(49440), UINT16_C( 7493), UINT16_C(43534), UINT16_C(61117),
      UINT16_C(55025), UINT16_C(30199), UINT16_C(59895), UINT16_C(54740), UINT16_C(21258), UINT16_C(38288), UINT16_C(35517), UINT16_C(36925),
      UINT16_C(50150), UINT16_C( 5734), UINT16_C(39895), UINT16_C(63318), UINT16_C(40028), UINT16_C(27156), UINT16_C(53830), UINT16_C(14168),
      UINT16_C(20392), UINT16_C(41133), UINT16_C(33080), UINT16_C(17013), UINT16_C( 1492), UINT16_C(37336), UINT16_C( 5519), UINT16_C(29986),
      UINT16_C(35032), UINT16_C(44940), UINT16_C(57891), UINT16_C(32678), UINT16_C(47742), UINT16_C(50409), UINT16_C(16780), UINT16_C(13820),
      UINT16_C(43408), UINT16_C(51413), UINT16_C(18986), UINT16_C(65035), UINT16_C(58191), UINT16_C(57232), UINT16_C(45816), UINT16_C(53332),
      UINT16_C(57402), UINT16_C(24191), UINT16_C( 9667), UINT16_C(16861), UINT16_C(51167), UINT16_C(27654), UINT16_C(  520), UINT16_C(39329),
      UINT16_C(30379), UINT16_C(54625), UINT16_C(27840), UINT16_C( 4051), UINT16_C(25423), UINT16_C(18414), UINT16_C(17173), UINT16_C(20503),
      UINT16_C(38435), UINT16_C(59054), UINT16_C(35771), UINT16_C(39720), UINT16_C(11858), UINT16_C(23303), UINT16_C(43056), UINT16_C(56308),
      UINT16_C(21790), UINT16_C(57008), UINT16_C(33730), UINT16_C( 4589), UINT16_C(56551), UINT16_C(64601), UINT16_C(28703), UINT16_C(16972),
      UINT16_C(64007), UINT16_C(49705), UINT16_C(20870), UINT16_C(55389), UINT16_C(25727), UINT16_C(44851), UINT16_C( 9996), UINT16_C(10890),
      UINT16_C(14973), UINT16_C(16136), UINT16_C(63165), UINT16_C(42064), UINT16_C(43474), UINT16_C(61857), UINT16_C(60698), UINT16_C( 8499),
      UINT16_C(23784), UINT16_C(28387), UINT16_C(16813), UINT16_C(11334), UINT16_C(31397), UINT16_C(45787), UINT16_C(26017), UINT16_C( 7900),
      UINT16_C(58783), UINT16_C(23901), UINT16_C(44763), UINT16_C(44289), UINT16_C(41559), UINT16_C(29086), UINT16_C(53648), UINT16_C(30866),
      UINT16_C(30254), UINT16_C(56294), UINT16_C(11447), UINT16_C(23560), UINT16_C(58278), UINT16_C(18446), UINT16_C(60233), UINT16_C(59494),
      UINT16_C(50384), UINT16_C(43845), UINT16_C(18290), UINT16_C(51544), UINT16_C(63209), UINT16_C(31035), UINT16_C(52679), UINT16_C(62961),
      UINT16_C(55107), UINT16_C(64209), UINT16_C(55556), UINT16_C(43607), UINT16_C(26044), UINT16_C( 1522), UINT16_C(22864), UINT16_C( 8430),
      UINT16_C(13085), UINT16_C(36811), UINT16_C( 9082), UINT16_C(25688), UINT16_C(37657), UINT16_C(57821), UINT16_C(53089), UINT16_C(42198),
      UINT16_C(42918), UINT16_C(43679), UINT16_C(63104), UINT16_C(15701), UINT16_C(18267), UINT16_C(44098), UINT16_C(12448), UINT16_C(48588),
      UINT16_C(39012), UINT16_C(56908), UINT16_C(42427), UINT16_C(54594), UINT16_C( 8248), UINT16_C(39350), UINT16_C(36079), UINT16_C(38206),
      UINT16_C(56628), UINT16_C(46144), UINT16_C(38355), UINT16_C(12017), UINT16_C(13532), UINT16_C(32218), UINT16_C(42852), UINT16_C(51258),
      UINT16_C(34623), UINT16_C(64167), UINT16_C(59692), UINT16_C(25807), UINT16_C(34057), UINT16_C(63742), UINT16_C(15378), UINT16_C(18062),
      UINT16_C(52761), UINT16_C(60666), UINT16_C(60515), UINT16_C(16154), UINT16_C(62752), UINT16_C(33980) };
  static const uint16_t b = UINT16_C(47781);
  static const uint16_t e[] =
    { UINT16_C(    0), UINT16_C(31799), UINT16_C(42389), UINT16_C(29514), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(26373), UINT16_C(47487), UINT16_C(    0), UINT16_C(12470), UINT16_C(39690), UINT16_C(13636), UINT16_C( 9605),
      UINT16_C(19455), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(26019), UINT16_C(    0), UINT16_C(55997), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(24891), UINT16_C(    0), UINT16_C(    0), UINT16_C(13803), UINT16_C(    0), UINT16_C(12587),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(52817), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(16590), UINT16_C(    0), UINT16_C(40561), UINT16_C(    0), UINT16_C(    0), UINT16_C(15975), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(62495), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(29256), UINT16_C(20525), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(24179), UINT16_C(    0), UINT16_C(52077), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(41639), UINT16_C(32510), UINT16_C(    0), UINT16_C(  927), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(33941), UINT16_C( 9378),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(61559), UINT16_C(60424), UINT16_C(13947), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(10248), UINT16_C(    0), UINT16_C(    0), UINT16_C(61541), UINT16_C(30537),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(38653), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(51575),
      UINT16_C(    0), UINT16_C(47861), UINT16_C(36198), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 8898), UINT16_C(    0),
      UINT16_C(14383), UINT16_C(48050), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(57164),
      UINT16_C(53582), UINT16_C(    0), UINT16_C(44334), UINT16_C(11320), UINT16_C(    0), UINT16_C(    0), UINT16_C(38404), UINT16_C(49847),
      UINT16_C(63645), UINT16_C(    0), UINT16_C(    0), UINT16_C(36710), UINT16_C(    0), UINT16_C(30482), UINT16_C(    0), UINT16_C( 6437),
      UINT16_C( 7823), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(27209), UINT16_C(36763), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(22812), UINT16_C(45274), UINT16_C(31702), UINT16_C(    0), UINT16_C(44346), UINT16_C(22666),
      UINT16_C(17819), UINT16_C(50805), UINT16_C(19978), UINT16_C(28735), UINT16_C( 6227), UINT16_C(32169), UINT16_C(    0), UINT16_C(24597),
      UINT16_C( 1759), UINT16_C(35497), UINT16_C( 4911), UINT16_C(38156), UINT16_C(    0), UINT16_C(10502), UINT16_C(    0), UINT16_C(15185),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(40819), UINT16_C(    0), UINT16_C(18568), UINT16_C(36515), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(56855), UINT16_C(45786), UINT16_C(    0), UINT16_C(55573), UINT16_C(    0), UINT16_C(    0), UINT16_C(36031),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(60237),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(27254), UINT16_C( 6942), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(14536),
      UINT16_C(33757), UINT16_C(    0), UINT16_C(21791), UINT16_C(37491), UINT16_C( 2376), UINT16_C( 5156), UINT16_C(    0), UINT16_C(55246),
      UINT16_C(63172), UINT16_C(51757), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(35855), UINT16_C(26273), UINT16_C(    0),
      UINT16_C(63675), UINT16_C(    0), UINT16_C(    0), UINT16_C(62669), UINT16_C(    0), UINT16_C(29657), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(48958), UINT16_C(    0), UINT16_C(11875), UINT16_C(    0), UINT16_C(26250), UINT16_C(44857), UINT16_C(33861),
      UINT16_C(44919), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(20842), UINT16_C(    0), UINT16_C(    0), UINT16_C(58815),
      UINT16_C(36155), UINT16_C(    0), UINT16_C(    0), UINT16_C(42061), UINT16_C(26424), UINT16_C(    0), UINT16_C(44774), UINT16_C(60756),
      UINT16_C(    0), UINT16_C( 7137), UINT16_C(    0), UINT16_C(    0), UINT16_C( 1659), UINT16_C(25248), UINT16_C(    0), UINT16_C(13336),
      UINT16_C( 7244), UINT16_C(47954), UINT16_C(12114), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(23489), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(44911), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(58888), UINT16_C(50835), UINT16_C(    0), UINT16_C(    0), UINT16_C(55091), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(62695), UINT16_C(10110), UINT16_C(50433), UINT16_C(65497), UINT16_C(    0), UINT16_C(34535), UINT16_C(31575),
      UINT16_C(61163), UINT16_C( 3632), UINT16_C(    0), UINT16_C(    0), UINT16_C(10410), UINT16_C( 9451), UINT16_C(    0), UINT16_C( 5551),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(27422), UINT16_C(    0), UINT16_C( 3386), UINT16_C(    0), UINT16_C(    0), UINT16_C(57084),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(21806), UINT16_C(43178), UINT16_C(36169), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(53526), UINT16_C(57475), UINT16_C(    0), UINT16_C(41058), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(39545), UINT16_C( 9227), UINT16_C(51485), UINT16_C(    0), UINT16_C( 8770), UINT16_C(    0), UINT16_C(46458), UINT16_C(34727),
      UINT16_C(    0), UINT16_C( 1924), UINT16_C(38625), UINT16_C(    0), UINT16_C(43482), UINT16_C(62606), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(32728), UINT16_C(    0), UINT16_C(15384), UINT16_C(59819), UINT16_C(    0), UINT16_C(14076), UINT16_C(12917), UINT16_C(26254),
      UINT16_C(41539), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(49152), UINT16_C(63542), UINT16_C(43772), UINT16_C(    0),
      UINT16_C(11002), UINT16_C(41656), UINT16_C(62518), UINT16_C(    0), UINT16_C(59314), UINT16_C(46841), UINT16_C(    0), UINT16_C(48621),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(10497), UINT16_C(    0), UINT16_C(12452), UINT16_C(    0),
      UINT16_C( 2603), UINT16_C(    0), UINT16_C(36045), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(15180),
      UINT16_C(    0), UINT16_C(    0), UINT16_C( 7775), UINT16_C(    0), UINT16_C(    0), UINT16_C(19277), UINT16_C(40619), UINT16_C(26185),
      UINT16_C(30840), UINT16_C(54566), UINT16_C(    0), UINT16_C(    0), UINT16_C(55412), UINT16_C(    0), UINT16_C( 5308), UINT16_C(    0),
      UINT16_C(60673), UINT16_C(61434), UINT16_C(15323), UINT16_C(    0), UINT16_C(36022), UINT16_C(    0), UINT16_C(30203), UINT16_C(  807),
      UINT16_C(    0), UINT16_C( 9127), UINT16_C(60182), UINT16_C( 6813), UINT16_C(    0), UINT16_C(57105), UINT16_C(53834), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(63899), UINT16_C(    0), UINT16_C(29772), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(52378), UINT16_C(16386), UINT16_C(    0), UINT16_C(43562), UINT16_C(    0), UINT16_C(15961), UINT16_C(33133), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(12734), UINT16_C(    0), UINT16_C(    0), UINT16_C(51735) };

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
    rv = simde_svsub_n_u16_z(pv, av, b);

    simde_svst1_u16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vu16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(int16_t)];
  uint16_t a[1024 / sizeof(int16_t)], b, e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u16();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_u16(pg, &(a[i]));

    ev = simde_svsub_n_u16_z(pv, av, b);

    simde_svst1_u16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u16(1, b);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_u16_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) };
  static const uint16_t a[] =
    { UINT16_C(12910), UINT16_C(26129), UINT16_C(11757), UINT16_C(23176), UINT16_C(10378), UINT16_C(58098), UINT16_C(62568), UINT16_C(54189),
      UINT16_C(12883), UINT16_C(60046), UINT16_C(10372), UINT16_C(57396), UINT16_C(43021), UINT16_C(27593), UINT16_C( 3710), UINT16_C(60536),
      UINT16_C(35136), UINT16_C(11858), UINT16_C(55991), UINT16_C(16776), UINT16_C(31235), UINT16_C(27427), UINT16_C(53358), UINT16_C(49727),
      UINT16_C(52483), UINT16_C(34732), UINT16_C(57590), UINT16_C(  872), UINT16_C(12680), UINT16_C( 1902), UINT16_C(59199), UINT16_C(33011),
      UINT16_C(18032), UINT16_C(10158), UINT16_C(13856), UINT16_C( 9065), UINT16_C(36016), UINT16_C( 7823), UINT16_C(52829), UINT16_C(24800),
      UINT16_C(35995), UINT16_C(37351), UINT16_C(20333), UINT16_C(62869), UINT16_C(  896), UINT16_C(49404), UINT16_C(61674), UINT16_C(23360),
      UINT16_C(60982), UINT16_C(22146), UINT16_C(60196), UINT16_C(54394), UINT16_C( 2424), UINT16_C(54770), UINT16_C(54231), UINT16_C(29237),
      UINT16_C( 7263), UINT16_C(52228), UINT16_C(39276), UINT16_C(60610), UINT16_C(48796), UINT16_C(34732), UINT16_C(60590), UINT16_C(58594),
      UINT16_C(25818), UINT16_C(65083), UINT16_C(46416), UINT16_C(51410), UINT16_C(50622), UINT16_C(38301), UINT16_C(53912), UINT16_C(63239),
      UINT16_C( 3054), UINT16_C(23236), UINT16_C(34468), UINT16_C(16711), UINT16_C(62276), UINT16_C(62408), UINT16_C(43744), UINT16_C(47831),
      UINT16_C( 4622), UINT16_C(24249), UINT16_C(35783), UINT16_C(34086), UINT16_C(50000), UINT16_C(59418), UINT16_C( 8853), UINT16_C(34016),
      UINT16_C(42029), UINT16_C(53982), UINT16_C( 9514), UINT16_C(28179), UINT16_C(56089), UINT16_C(63841), UINT16_C(14725), UINT16_C(37811),
      UINT16_C(27723), UINT16_C( 5106), UINT16_C( 6392), UINT16_C(18584), UINT16_C(46044), UINT16_C(28977), UINT16_C( 4565), UINT16_C(  757),
      UINT16_C(54453), UINT16_C(57300), UINT16_C(59385), UINT16_C( 4685), UINT16_C(44994), UINT16_C(18187), UINT16_C(49128), UINT16_C(13275),
      UINT16_C(52523), UINT16_C( 9030), UINT16_C(57317), UINT16_C(49516), UINT16_C(40338), UINT16_C(26419), UINT16_C(10414), UINT16_C(25449),
      UINT16_C(16124), UINT16_C(63042), UINT16_C(36645), UINT16_C(59400), UINT16_C( 5182), UINT16_C( 9775), UINT16_C( 2771), UINT16_C(65114),
      UINT16_C(41175), UINT16_C(48418), UINT16_C(36479), UINT16_C( 4478), UINT16_C(45355), UINT16_C(55672), UINT16_C(58074), UINT16_C(54844),
      UINT16_C(32288), UINT16_C(17868), UINT16_C(54541), UINT16_C(19501), UINT16_C(24041), UINT16_C(48242), UINT16_C(52327), UINT16_C(16314),
      UINT16_C(56429), UINT16_C(60668), UINT16_C(31338), UINT16_C(38398), UINT16_C(30252), UINT16_C( 1646), UINT16_C(43608), UINT16_C(30940),
      UINT16_C(43304), UINT16_C(14014), UINT16_C(60286), UINT16_C(26498), UINT16_C(62536), UINT16_C(45091), UINT16_C(56769), UINT16_C(12015),
      UINT16_C(60346), UINT16_C( 9242), UINT16_C( 6245), UINT16_C(37306), UINT16_C(10383), UINT16_C(59287), UINT16_C(29907), UINT16_C(64352),
      UINT16_C( 7709), UINT16_C(39729), UINT16_C(45833), UINT16_C(20994), UINT16_C( 9640), UINT16_C(26882), UINT16_C(61698), UINT16_C(48279),
      UINT16_C(45532), UINT16_C(16865), UINT16_C(39882), UINT16_C(22995), UINT16_C(27331), UINT16_C(38464), UINT16_C(41182), UINT16_C(64402),
      UINT16_C(50110), UINT16_C(51350), UINT16_C(39031), UINT16_C( 7962), UINT16_C( 7357), UINT16_C(49288), UINT16_C( 7949), UINT16_C(59772),
      UINT16_C(24016), UINT16_C(39466), UINT16_C(65016), UINT16_C(48371), UINT16_C(13416), UINT16_C(18002), UINT16_C(58580), UINT16_C(37698),
      UINT16_C(55464), UINT16_C( 8027), UINT16_C(30065), UINT16_C(11838), UINT16_C(50833), UINT16_C(40686), UINT16_C(27621), UINT16_C(46471),
      UINT16_C(45512), UINT16_C(49488), UINT16_C(17327), UINT16_C( 6013), UINT16_C(53111), UINT16_C(19549), UINT16_C(40884), UINT16_C(23775),
      UINT16_C(14968), UINT16_C(59771), UINT16_C(47535), UINT16_C(16407), UINT16_C( 1663), UINT16_C(25822), UINT16_C(25969), UINT16_C(14617),
      UINT16_C(26902), UINT16_C(50682), UINT16_C(30637), UINT16_C( 9436), UINT16_C(14919), UINT16_C(64368), UINT16_C(20441), UINT16_C(20823),
      UINT16_C(53897), UINT16_C(14394), UINT16_C(21131), UINT16_C( 2680), UINT16_C(22104), UINT16_C(51566), UINT16_C(34747), UINT16_C(53762),
      UINT16_C(65009), UINT16_C(40599), UINT16_C(29812), UINT16_C(48066), UINT16_C(13230), UINT16_C(34742), UINT16_C( 3458), UINT16_C( 3289),
      UINT16_C( 5087), UINT16_C(27204), UINT16_C(48485), UINT16_C(48500), UINT16_C(57875), UINT16_C(53126), UINT16_C(35178), UINT16_C(23457),
      UINT16_C(14470), UINT16_C(64249), UINT16_C(48044), UINT16_C(23222), UINT16_C(27886), UINT16_C(29154), UINT16_C(47994), UINT16_C(22909),
      UINT16_C(49614), UINT16_C(13508), UINT16_C(14462), UINT16_C(37617), UINT16_C(30747), UINT16_C(34145), UINT16_C(  513), UINT16_C(34784),
      UINT16_C(55610), UINT16_C(59265), UINT16_C(14228), UINT16_C(33601), UINT16_C( 9124), UINT16_C( 7924), UINT16_C(29150), UINT16_C(44407),
      UINT16_C(15154), UINT16_C(45537), UINT16_C(53876), UINT16_C(36675), UINT16_C(42058), UINT16_C(19220), UINT16_C(62630), UINT16_C(57554),
      UINT16_C(21709), UINT16_C(25031), UINT16_C( 2443), UINT16_C(12260), UINT16_C(55340), UINT16_C( 2893), UINT16_C(50505), UINT16_C(31928),
      UINT16_C(39168), UINT16_C(29741), UINT16_C(28779), UINT16_C(46595), UINT16_C( 5908), UINT16_C(47617), UINT16_C(54283), UINT16_C(55450),
      UINT16_C(25128), UINT16_C(45882), UINT16_C( 7787), UINT16_C(38883), UINT16_C(12535), UINT16_C(16546), UINT16_C(23285), UINT16_C(63164),
      UINT16_C(59891), UINT16_C(24426), UINT16_C(28249), UINT16_C(27925), UINT16_C( 5765), UINT16_C(37159), UINT16_C(49898), UINT16_C( 4713),
      UINT16_C(41764), UINT16_C(36806), UINT16_C(43458), UINT16_C(47398), UINT16_C(51673), UINT16_C(53241), UINT16_C(46627), UINT16_C( 6085),
      UINT16_C(12191), UINT16_C(63862), UINT16_C(35741), UINT16_C( 9062), UINT16_C(36513), UINT16_C(36020) };
  static const uint16_t b = UINT16_C(15317);
  static const uint16_t e[] =
    { UINT16_C(12910), UINT16_C(26129), UINT16_C(61976), UINT16_C( 7859), UINT16_C(10378), UINT16_C(42781), UINT16_C(62568), UINT16_C(38872),
      UINT16_C(63102), UINT16_C(60046), UINT16_C(60591), UINT16_C(57396), UINT16_C(43021), UINT16_C(12276), UINT16_C( 3710), UINT16_C(45219),
      UINT16_C(35136), UINT16_C(11858), UINT16_C(55991), UINT16_C( 1459), UINT16_C(15918), UINT16_C(27427), UINT16_C(53358), UINT16_C(49727),
      UINT16_C(52483), UINT16_C(34732), UINT16_C(42273), UINT16_C(51091), UINT16_C(62899), UINT16_C( 1902), UINT16_C(59199), UINT16_C(33011),
      UINT16_C( 2715), UINT16_C(10158), UINT16_C(64075), UINT16_C( 9065), UINT16_C(36016), UINT16_C( 7823), UINT16_C(37512), UINT16_C( 9483),
      UINT16_C(35995), UINT16_C(22034), UINT16_C(20333), UINT16_C(62869), UINT16_C(  896), UINT16_C(34087), UINT16_C(61674), UINT16_C( 8043),
      UINT16_C(60982), UINT16_C( 6829), UINT16_C(44879), UINT16_C(54394), UINT16_C(52643), UINT16_C(39453), UINT16_C(54231), UINT16_C(13920),
      UINT16_C(57482), UINT16_C(36911), UINT16_C(23959), UINT16_C(60610), UINT16_C(33479), UINT16_C(19415), UINT16_C(60590), UINT16_C(58594),
      UINT16_C(10501), UINT16_C(49766), UINT16_C(46416), UINT16_C(36093), UINT16_C(50622), UINT16_C(22984), UINT16_C(38595), UINT16_C(63239),
      UINT16_C( 3054), UINT16_C( 7919), UINT16_C(19151), UINT16_C(16711), UINT16_C(46959), UINT16_C(62408), UINT16_C(43744), UINT16_C(32514),
      UINT16_C(54841), UINT16_C( 8932), UINT16_C(20466), UINT16_C(34086), UINT16_C(50000), UINT16_C(59418), UINT16_C(59072), UINT16_C(18699),
      UINT16_C(42029), UINT16_C(53982), UINT16_C(59733), UINT16_C(28179), UINT16_C(40772), UINT16_C(48524), UINT16_C(64944), UINT16_C(37811),
      UINT16_C(27723), UINT16_C( 5106), UINT16_C(56611), UINT16_C(18584), UINT16_C(46044), UINT16_C(13660), UINT16_C( 4565), UINT16_C(50976),
      UINT16_C(39136), UINT16_C(57300), UINT16_C(44068), UINT16_C(54904), UINT16_C(29677), UINT16_C( 2870), UINT16_C(49128), UINT16_C(63494),
      UINT16_C(37206), UINT16_C(59249), UINT16_C(57317), UINT16_C(49516), UINT16_C(40338), UINT16_C(11102), UINT16_C(10414), UINT16_C(10132),
      UINT16_C(  807), UINT16_C(63042), UINT16_C(36645), UINT16_C(59400), UINT16_C(55401), UINT16_C( 9775), UINT16_C( 2771), UINT16_C(65114),
      UINT16_C(25858), UINT16_C(33101), UINT16_C(36479), UINT16_C( 4478), UINT16_C(45355), UINT16_C(55672), UINT16_C(42757), UINT16_C(54844),
      UINT16_C(32288), UINT16_C(17868), UINT16_C(54541), UINT16_C(19501), UINT16_C(24041), UINT16_C(32925), UINT16_C(52327), UINT16_C(16314),
      UINT16_C(41112), UINT16_C(60668), UINT16_C(31338), UINT16_C(23081), UINT16_C(14935), UINT16_C( 1646), UINT16_C(43608), UINT16_C(30940),
      UINT16_C(43304), UINT16_C(64233), UINT16_C(44969), UINT16_C(26498), UINT16_C(62536), UINT16_C(29774), UINT16_C(56769), UINT16_C(62234),
      UINT16_C(60346), UINT16_C(59461), UINT16_C(56464), UINT16_C(37306), UINT16_C(60602), UINT16_C(59287), UINT16_C(29907), UINT16_C(64352),
      UINT16_C( 7709), UINT16_C(24412), UINT16_C(30516), UINT16_C( 5677), UINT16_C( 9640), UINT16_C(26882), UINT16_C(61698), UINT16_C(32962),
      UINT16_C(45532), UINT16_C(16865), UINT16_C(39882), UINT16_C(22995), UINT16_C(12014), UINT16_C(38464), UINT16_C(41182), UINT16_C(64402),
      UINT16_C(34793), UINT16_C(51350), UINT16_C(23714), UINT16_C( 7962), UINT16_C(57576), UINT16_C(33971), UINT16_C(58168), UINT16_C(59772),
      UINT16_C(24016), UINT16_C(39466), UINT16_C(49699), UINT16_C(33054), UINT16_C(13416), UINT16_C( 2685), UINT16_C(43263), UINT16_C(22381),
      UINT16_C(55464), UINT16_C(58246), UINT16_C(14748), UINT16_C(62057), UINT16_C(50833), UINT16_C(40686), UINT16_C(27621), UINT16_C(46471),
      UINT16_C(30195), UINT16_C(34171), UINT16_C( 2010), UINT16_C( 6013), UINT16_C(37794), UINT16_C( 4232), UINT16_C(25567), UINT16_C(23775),
      UINT16_C(14968), UINT16_C(59771), UINT16_C(47535), UINT16_C( 1090), UINT16_C( 1663), UINT16_C(25822), UINT16_C(25969), UINT16_C(14617),
      UINT16_C(11585), UINT16_C(50682), UINT16_C(15320), UINT16_C( 9436), UINT16_C(14919), UINT16_C(64368), UINT16_C( 5124), UINT16_C(20823),
      UINT16_C(38580), UINT16_C(64613), UINT16_C(21131), UINT16_C( 2680), UINT16_C(22104), UINT16_C(36249), UINT16_C(34747), UINT16_C(53762),
      UINT16_C(65009), UINT16_C(25282), UINT16_C(14495), UINT16_C(32749), UINT16_C(13230), UINT16_C(19425), UINT16_C( 3458), UINT16_C(53508),
      UINT16_C(55306), UINT16_C(11887), UINT16_C(33168), UINT16_C(48500), UINT16_C(57875), UINT16_C(53126), UINT16_C(35178), UINT16_C( 8140),
      UINT16_C(14470), UINT16_C(64249), UINT16_C(48044), UINT16_C(23222), UINT16_C(27886), UINT16_C(29154), UINT16_C(32677), UINT16_C(22909),
      UINT16_C(49614), UINT16_C(63727), UINT16_C(14462), UINT16_C(37617), UINT16_C(30747), UINT16_C(18828), UINT16_C(  513), UINT16_C(34784),
      UINT16_C(55610), UINT16_C(43948), UINT16_C(14228), UINT16_C(18284), UINT16_C(59343), UINT16_C(58143), UINT16_C(13833), UINT16_C(29090),
      UINT16_C(65373), UINT16_C(45537), UINT16_C(53876), UINT16_C(36675), UINT16_C(42058), UINT16_C(19220), UINT16_C(47313), UINT16_C(42237),
      UINT16_C( 6392), UINT16_C(25031), UINT16_C( 2443), UINT16_C(12260), UINT16_C(40023), UINT16_C( 2893), UINT16_C(35188), UINT16_C(31928),
      UINT16_C(39168), UINT16_C(14424), UINT16_C(28779), UINT16_C(46595), UINT16_C(56127), UINT16_C(32300), UINT16_C(54283), UINT16_C(55450),
      UINT16_C( 9811), UINT16_C(45882), UINT16_C(58006), UINT16_C(38883), UINT16_C(12535), UINT16_C( 1229), UINT16_C( 7968), UINT16_C(47847),
      UINT16_C(59891), UINT16_C(24426), UINT16_C(28249), UINT16_C(27925), UINT16_C( 5765), UINT16_C(21842), UINT16_C(49898), UINT16_C( 4713),
      UINT16_C(41764), UINT16_C(21489), UINT16_C(28141), UINT16_C(47398), UINT16_C(36356), UINT16_C(37924), UINT16_C(31310), UINT16_C( 6085),
      UINT16_C(12191), UINT16_C(63862), UINT16_C(20424), UINT16_C( 9062), UINT16_C(36513), UINT16_C(20703) };

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
    rv = simde_svsub_n_u16_m(pv, av, b);

    simde_svst1_u16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vu16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(int16_t)];
  uint16_t a[1024 / sizeof(int16_t)], b, e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u16();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_u16(pg, &(a[i]));

    ev = simde_svsub_n_u16_m(pv, av, b);

    simde_svst1_u16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u16(1, b);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_u32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) };
  static const uint32_t a[] =
    { UINT32_C( 695955549), UINT32_C(1596966083), UINT32_C(2244892686), UINT32_C(2410377932), UINT32_C(1988239312), UINT32_C(3351676388), UINT32_C(2708569489), UINT32_C(3646489723),
      UINT32_C( 939709557), UINT32_C(2811703961), UINT32_C(1445815946), UINT32_C(2833701080), UINT32_C(3692980471), UINT32_C(2124670189), UINT32_C(3709801569), UINT32_C(2394323225),
      UINT32_C(3871782989), UINT32_C(1972264426), UINT32_C(2613820355), UINT32_C(2319692179), UINT32_C( 107372825), UINT32_C(2810448454), UINT32_C( 931439646), UINT32_C(1791310365),
      UINT32_C(3713108979), UINT32_C(2891112425), UINT32_C( 759701146), UINT32_C(3921120207), UINT32_C( 871309037), UINT32_C(1188721704), UINT32_C( 897474328), UINT32_C(2359247769),
      UINT32_C(3094016207), UINT32_C(1768209615), UINT32_C(2862001370), UINT32_C( 630410808), UINT32_C(2488828524), UINT32_C( 249180918), UINT32_C( 725833873), UINT32_C(1807213468),
      UINT32_C(2736988627), UINT32_C(3087828958), UINT32_C(1818403636), UINT32_C(1569846769), UINT32_C(1861347704), UINT32_C(2910702363), UINT32_C(3235430436), UINT32_C(1999343523),
      UINT32_C(2400865969), UINT32_C( 155657941), UINT32_C(3128273609), UINT32_C( 387384991), UINT32_C( 193333487), UINT32_C(4172809172), UINT32_C(1740148931), UINT32_C(3504268063),
      UINT32_C( 106952753), UINT32_C(3893405470), UINT32_C(4037182801), UINT32_C(2064169612), UINT32_C(2525400770), UINT32_C(1418608273), UINT32_C(4005250766), UINT32_C(1522440489),
      UINT32_C(2959154833), UINT32_C( 379089349), UINT32_C(2181446390), UINT32_C(3086880500), UINT32_C( 760054940), UINT32_C(2441272515), UINT32_C(1283407138), UINT32_C(1755725527),
      UINT32_C( 555222876), UINT32_C(1865920632), UINT32_C(3757129195), UINT32_C(3902205772), UINT32_C( 924247156), UINT32_C(3804797120), UINT32_C(2888714453), UINT32_C(3793081734),
      UINT32_C(1426271708), UINT32_C(3385080542), UINT32_C(3282613623), UINT32_C( 430718885), UINT32_C(3813720611), UINT32_C( 801445978), UINT32_C(3873240160), UINT32_C(2781409737),
      UINT32_C(4244294430), UINT32_C(2110111237), UINT32_C( 423652980), UINT32_C(3492998317), UINT32_C( 145982126), UINT32_C(4214782106), UINT32_C( 903943276), UINT32_C( 601598469),
      UINT32_C(2065749365), UINT32_C( 150529428), UINT32_C(   2177107), UINT32_C(3553645349), UINT32_C(1876722645), UINT32_C(1751782652), UINT32_C( 765348904), UINT32_C(1800436214),
      UINT32_C(3806752846), UINT32_C(2850741846), UINT32_C(1017776919), UINT32_C( 856652382), UINT32_C(4205046782), UINT32_C( 660737535), UINT32_C(1330905177), UINT32_C(3367740793),
      UINT32_C(1806344469), UINT32_C(2534774144), UINT32_C(4292067232), UINT32_C( 926081593), UINT32_C(3442595278), UINT32_C(1022727395), UINT32_C( 244074900), UINT32_C(  81151982),
      UINT32_C(1752137960), UINT32_C(3070198805), UINT32_C(2109067843), UINT32_C(2209671093), UINT32_C(2689656509), UINT32_C( 249316730), UINT32_C(2099013775), UINT32_C(2558653103),
      UINT32_C(2281763187), UINT32_C(3107848309), UINT32_C(2268525522), UINT32_C(2550852315), UINT32_C(1245207504), UINT32_C( 794367136), UINT32_C( 749565309), UINT32_C(3687067240),
      UINT32_C(2506343711), UINT32_C(2538513093), UINT32_C(1881113749), UINT32_C(1057499502), UINT32_C( 629751940), UINT32_C(3528778325), UINT32_C(3237871960), UINT32_C(1335608112),
      UINT32_C(1306853000), UINT32_C( 920924832), UINT32_C( 631636918), UINT32_C(2976165677), UINT32_C(1154936303), UINT32_C( 672541648), UINT32_C(1558713644), UINT32_C(1621918680),
      UINT32_C( 581800065), UINT32_C(2035847619), UINT32_C(3265199765), UINT32_C(2641560237), UINT32_C(3235990256) };
  static const uint32_t b = UINT32_C(1176034039);
  static const uint32_t e[] =
    { UINT32_C(3814888806), UINT32_C(         0), UINT32_C(         0), UINT32_C(1234343893), UINT32_C( 812205273), UINT32_C(2175642349), UINT32_C(1532535450), UINT32_C(2470455684),
      UINT32_C(4058642814), UINT32_C(1635669922), UINT32_C( 269781907), UINT32_C(1657667041), UINT32_C(         0), UINT32_C( 948636150), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(1143658140), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(2537074940), UINT32_C(         0), UINT32_C(         0), UINT32_C(2745086168), UINT32_C(         0), UINT32_C(  12687665), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(1685967331), UINT32_C(3749344065), UINT32_C(1312794485), UINT32_C(3368114175), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(1560954588), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(2059396397), UINT32_C(         0),
      UINT32_C(1224831930), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(3312266744), UINT32_C(2996775133), UINT32_C( 564114892), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(2861148762), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(2829216727), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(3498022606), UINT32_C(1005412351), UINT32_C(         0), UINT32_C(         0), UINT32_C(1265238476), UINT32_C( 107373099), UINT32_C( 579691488),
      UINT32_C(         0), UINT32_C( 689886593), UINT32_C(2581095156), UINT32_C(         0), UINT32_C(4043180413), UINT32_C(         0), UINT32_C(1712680414), UINT32_C(2617047695),
      UINT32_C( 250237669), UINT32_C(         0), UINT32_C(2106579584), UINT32_C(3549652142), UINT32_C(         0), UINT32_C(3920379235), UINT32_C(2697206121), UINT32_C(1605375698),
      UINT32_C(3068260391), UINT32_C( 934077198), UINT32_C(         0), UINT32_C(2316964278), UINT32_C(         0), UINT32_C(3038748067), UINT32_C(4022876533), UINT32_C(3720531726),
      UINT32_C(         0), UINT32_C(3269462685), UINT32_C(3121110364), UINT32_C(2377611310), UINT32_C( 700688606), UINT32_C(         0), UINT32_C(3884282161), UINT32_C( 624402175),
      UINT32_C(         0), UINT32_C(1674707807), UINT32_C(         0), UINT32_C(         0), UINT32_C(3029012743), UINT32_C(         0), UINT32_C(         0), UINT32_C(2191706754),
      UINT32_C( 630310430), UINT32_C(1358740105), UINT32_C(3116033193), UINT32_C(         0), UINT32_C(         0), UINT32_C(4141660652), UINT32_C(3363008157), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(1894164766), UINT32_C( 933033804), UINT32_C(         0), UINT32_C(1513622470), UINT32_C(         0), UINT32_C(         0), UINT32_C(1382619064),
      UINT32_C(         0), UINT32_C(1931814270), UINT32_C(         0), UINT32_C(1374818276), UINT32_C(  69173465), UINT32_C(         0), UINT32_C(3868498566), UINT32_C(2511033201),
      UINT32_C(1330309672), UINT32_C(         0), UINT32_C(         0), UINT32_C(4176432759), UINT32_C(         0), UINT32_C(2352744286), UINT32_C(         0), UINT32_C(         0),
      UINT32_C( 130818961), UINT32_C(4039858089), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 382679605), UINT32_C( 445884641),
      UINT32_C(         0), UINT32_C( 859813580), UINT32_C(2089165726), UINT32_C(1465526198), UINT32_C(2059956217) };

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
    rv = simde_svsub_n_u32_z(pv, av, b);

    simde_svst1_u32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vu32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)];
  uint32_t a[1024 / sizeof(int32_t)], b, e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u32();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_u32(pg, &(a[i]));

    ev = simde_svsub_n_u32_z(pv, av, b);

    simde_svst1_u32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u32(1, b);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_u32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) };
  static const uint32_t a[] =
    { UINT32_C(2423328502), UINT32_C(2432278898), UINT32_C( 121686655), UINT32_C( 507980204), UINT32_C(3735411869), UINT32_C(2972872284), UINT32_C(1078919467), UINT32_C(1940281213),
      UINT32_C(3624146790), UINT32_C( 929627576), UINT32_C(1933551815), UINT32_C(1855030993), UINT32_C(3192665954), UINT32_C(3496968101), UINT32_C(4245732992), UINT32_C(2087761430),
      UINT32_C(2236904653), UINT32_C( 968735857), UINT32_C( 917306468), UINT32_C(3835969154), UINT32_C( 446886261), UINT32_C(4041937520), UINT32_C(3874356176), UINT32_C(2137152946),
      UINT32_C(1124447954), UINT32_C(3615277682), UINT32_C(1074604478), UINT32_C(3693392231), UINT32_C( 318162594), UINT32_C(2835538392), UINT32_C(2408574941), UINT32_C( 521073229),
      UINT32_C( 459412392), UINT32_C(2482167765), UINT32_C(1876164360), UINT32_C(1397487536), UINT32_C(2523218366), UINT32_C(   4155427), UINT32_C(2760888151), UINT32_C(1774427585),
      UINT32_C(2256807601), UINT32_C( 219837957), UINT32_C( 645721461), UINT32_C(2742667237), UINT32_C( 725212680), UINT32_C(2653649222), UINT32_C( 155368008), UINT32_C( 158467672),
      UINT32_C( 831518508), UINT32_C(3812534637), UINT32_C(2081012375), UINT32_C(2300543617), UINT32_C(2813679712), UINT32_C( 424009937), UINT32_C(4079126427), UINT32_C(3120338317),
      UINT32_C(4192897932), UINT32_C(3436980277), UINT32_C(1665721826), UINT32_C(3371001703), UINT32_C(2440012479), UINT32_C( 497726594), UINT32_C(3373321531), UINT32_C(4001500258),
      UINT32_C(3454496152), UINT32_C(2023343253), UINT32_C( 299622825), UINT32_C( 131713096), UINT32_C(3986180202), UINT32_C( 923419644), UINT32_C(1912609552), UINT32_C(3210773287),
      UINT32_C(2240563184), UINT32_C(3053266187), UINT32_C(1321654534), UINT32_C( 207003553), UINT32_C(3824807655), UINT32_C(1092223793), UINT32_C(1186143006), UINT32_C(2382697374),
      UINT32_C(1712558683), UINT32_C(3189445047), UINT32_C(2332877290), UINT32_C(1737974400), UINT32_C(2185924689), UINT32_C(2999215508), UINT32_C( 519600000), UINT32_C(3870097035),
      UINT32_C(1196212112), UINT32_C(3120916688), UINT32_C(3393589833), UINT32_C(3308379508), UINT32_C(  38304878), UINT32_C(1639189729), UINT32_C( 243248515), UINT32_C(1005857707),
      UINT32_C(3145875946), UINT32_C(4067788969), UINT32_C( 247249818), UINT32_C( 131395225), UINT32_C(1258888298), UINT32_C(2880224552), UINT32_C( 364522346), UINT32_C(1079029334),
      UINT32_C(2566640623), UINT32_C(4119556443), UINT32_C(3305326380), UINT32_C(2681001781), UINT32_C( 468375027), UINT32_C(4257715859), UINT32_C( 387154369), UINT32_C( 525886255),
      UINT32_C(2444710710), UINT32_C(4052107972), UINT32_C(3216411274), UINT32_C(1432322913), UINT32_C(3950004568), UINT32_C(2716415968), UINT32_C(3904502968), UINT32_C(2517045599),
      UINT32_C( 690470500), UINT32_C(2333781505), UINT32_C(2571817016), UINT32_C(2901322067), UINT32_C(3549913075), UINT32_C(1333035158), UINT32_C(3694603644), UINT32_C(2742173246),
      UINT32_C(4258044412), UINT32_C(2139678279), UINT32_C( 169464758), UINT32_C(1874200444), UINT32_C(4248980838), UINT32_C(1246541774), UINT32_C( 589726692), UINT32_C(3183909057),
      UINT32_C(2042335794), UINT32_C( 788087672), UINT32_C(2469925398), UINT32_C(2147675673), UINT32_C( 175981884), UINT32_C(3763653116), UINT32_C( 218331980), UINT32_C(1170917651),
      UINT32_C(3552544091), UINT32_C(3741497545), UINT32_C(3815914186), UINT32_C(1701016873), UINT32_C(3060785338), UINT32_C(4120298409), UINT32_C(1375902270), UINT32_C(3214396771),
      UINT32_C( 462575186), UINT32_C(3640366094), UINT32_C(4173098447), UINT32_C(2623348706), UINT32_C(2840775680), UINT32_C(3466586511), UINT32_C(3860898179), UINT32_C(3248863086),
      UINT32_C( 484194318), UINT32_C(2616580044), UINT32_C( 663990597), UINT32_C(3502567632), UINT32_C(1283069628), UINT32_C(2182748671), UINT32_C( 694762170), UINT32_C(4293529329),
      UINT32_C( 320652870), UINT32_C(3819835806), UINT32_C(2450145986), UINT32_C(4016295474), UINT32_C(3829128677), UINT32_C(2959562230), UINT32_C(2161758351), UINT32_C( 629195742),
      UINT32_C( 674798730), UINT32_C(1863050925), UINT32_C(1526797608), UINT32_C(3377095908), UINT32_C( 934118721), UINT32_C(1776817370), UINT32_C(3286876644), UINT32_C( 266889605),
      UINT32_C(2989957125), UINT32_C( 790708742), UINT32_C( 998908759), UINT32_C(3372536967), UINT32_C( 855683673), UINT32_C(2879187142), UINT32_C( 795772330), UINT32_C(4097726191),
      UINT32_C(2091349366), UINT32_C( 246139063), UINT32_C(1934243307), UINT32_C(1648119305), UINT32_C(3348446208), UINT32_C(3480367397), UINT32_C(2801721527), UINT32_C(2895789110),
      UINT32_C(1747468721), UINT32_C(4118205450), UINT32_C( 325632009), UINT32_C( 259367951), UINT32_C( 114691041), UINT32_C(4090841148), UINT32_C(1587139368), UINT32_C(3221894159),
      UINT32_C(2133341045), UINT32_C( 276143623), UINT32_C(1847844191), UINT32_C(1669175682), UINT32_C(3764999332), UINT32_C(3319021212), UINT32_C( 539192593), UINT32_C( 400567969),
      UINT32_C(1754663009), UINT32_C(  91753382), UINT32_C(1802738921) };
  static const uint32_t b = UINT32_C(  60553648);
  static const uint32_t e[] =
    { UINT32_C(2362774854), UINT32_C(2432278898), UINT32_C( 121686655), UINT32_C( 507980204), UINT32_C(3735411869), UINT32_C(2912318636), UINT32_C(1018365819), UINT32_C(1879727565),
      UINT32_C(3624146790), UINT32_C( 869073928), UINT32_C(1933551815), UINT32_C(1855030993), UINT32_C(3132112306), UINT32_C(3496968101), UINT32_C(4185179344), UINT32_C(2087761430),
      UINT32_C(2236904653), UINT32_C( 968735857), UINT32_C( 856752820), UINT32_C(3775415506), UINT32_C( 386332613), UINT32_C(3981383872), UINT32_C(3813802528), UINT32_C(2076599298),
      UINT32_C(1063894306), UINT32_C(3554724034), UINT32_C(1014050830), UINT32_C(3632838583), UINT32_C( 318162594), UINT32_C(2835538392), UINT32_C(2348021293), UINT32_C( 460519581),
      UINT32_C( 398858744), UINT32_C(2482167765), UINT32_C(1815610712), UINT32_C(1336933888), UINT32_C(2462664718), UINT32_C(4238569075), UINT32_C(2760888151), UINT32_C(1713873937),
      UINT32_C(2196253953), UINT32_C( 219837957), UINT32_C( 645721461), UINT32_C(2682113589), UINT32_C( 664659032), UINT32_C(2593095574), UINT32_C(  94814360), UINT32_C( 158467672),
      UINT32_C( 770964860), UINT32_C(3812534637), UINT32_C(2020458727), UINT32_C(2239989969), UINT32_C(2753126064), UINT32_C( 363456289), UINT32_C(4079126427), UINT32_C(3120338317),
      UINT32_C(4192897932), UINT32_C(3376426629), UINT32_C(1605168178), UINT32_C(3371001703), UINT32_C(2440012479), UINT32_C( 497726594), UINT32_C(3373321531), UINT32_C(3940946610),
      UINT32_C(3454496152), UINT32_C(2023343253), UINT32_C( 239069177), UINT32_C(  71159448), UINT32_C(3986180202), UINT32_C( 923419644), UINT32_C(1912609552), UINT32_C(3150219639),
      UINT32_C(2180009536), UINT32_C(2992712539), UINT32_C(1261100886), UINT32_C( 146449905), UINT32_C(3824807655), UINT32_C(1092223793), UINT32_C(1186143006), UINT32_C(2382697374),
      UINT32_C(1652005035), UINT32_C(3189445047), UINT32_C(2272323642), UINT32_C(1677420752), UINT32_C(2125371041), UINT32_C(2938661860), UINT32_C( 459046352), UINT32_C(3870097035),
      UINT32_C(1135658464), UINT32_C(3120916688), UINT32_C(3333036185), UINT32_C(3308379508), UINT32_C(4272718526), UINT32_C(1639189729), UINT32_C( 182694867), UINT32_C( 945304059),
      UINT32_C(3085322298), UINT32_C(4067788969), UINT32_C( 247249818), UINT32_C(  70841577), UINT32_C(1198334650), UINT32_C(2819670904), UINT32_C( 303968698), UINT32_C(1079029334),
      UINT32_C(2506086975), UINT32_C(4059002795), UINT32_C(3244772732), UINT32_C(2681001781), UINT32_C( 468375027), UINT32_C(4257715859), UINT32_C( 326600721), UINT32_C( 465332607),
      UINT32_C(2384157062), UINT32_C(3991554324), UINT32_C(3216411274), UINT32_C(1371769265), UINT32_C(3950004568), UINT32_C(2716415968), UINT32_C(3904502968), UINT32_C(2517045599),
      UINT32_C( 690470500), UINT32_C(2333781505), UINT32_C(2511263368), UINT32_C(2840768419), UINT32_C(3549913075), UINT32_C(1272481510), UINT32_C(3694603644), UINT32_C(2742173246),
      UINT32_C(4258044412), UINT32_C(2139678279), UINT32_C( 169464758), UINT32_C(1874200444), UINT32_C(4248980838), UINT32_C(1185988126), UINT32_C( 529173044), UINT32_C(3123355409),
      UINT32_C(2042335794), UINT32_C( 727534024), UINT32_C(2409371750), UINT32_C(2147675673), UINT32_C( 115428236), UINT32_C(3703099468), UINT32_C( 157778332), UINT32_C(1170917651),
      UINT32_C(3491990443), UINT32_C(3741497545), UINT32_C(3815914186), UINT32_C(1701016873), UINT32_C(3060785338), UINT32_C(4120298409), UINT32_C(1375902270), UINT32_C(3214396771),
      UINT32_C( 462575186), UINT32_C(3579812446), UINT32_C(4112544799), UINT32_C(2623348706), UINT32_C(2840775680), UINT32_C(3466586511), UINT32_C(3800344531), UINT32_C(3188309438),
      UINT32_C( 484194318), UINT32_C(2556026396), UINT32_C( 663990597), UINT32_C(3502567632), UINT32_C(1222515980), UINT32_C(2122195023), UINT32_C( 694762170), UINT32_C(4232975681),
      UINT32_C( 260099222), UINT32_C(3819835806), UINT32_C(2389592338), UINT32_C(3955741826), UINT32_C(3768575029), UINT32_C(2959562230), UINT32_C(2161758351), UINT32_C( 568642094),
      UINT32_C( 614245082), UINT32_C(1863050925), UINT32_C(1526797608), UINT32_C(3316542260), UINT32_C( 934118721), UINT32_C(1776817370), UINT32_C(3286876644), UINT32_C( 206335957),
      UINT32_C(2989957125), UINT32_C( 790708742), UINT32_C( 938355111), UINT32_C(3372536967), UINT32_C( 795130025), UINT32_C(2879187142), UINT32_C( 795772330), UINT32_C(4037172543),
      UINT32_C(2030795718), UINT32_C( 246139063), UINT32_C(1934243307), UINT32_C(1648119305), UINT32_C(3348446208), UINT32_C(3480367397), UINT32_C(2741167879), UINT32_C(2835235462),
      UINT32_C(1747468721), UINT32_C(4057651802), UINT32_C( 265078361), UINT32_C( 198814303), UINT32_C(  54137393), UINT32_C(4090841148), UINT32_C(1587139368), UINT32_C(3161340511),
      UINT32_C(2072787397), UINT32_C( 215589975), UINT32_C(1847844191), UINT32_C(1608622034), UINT32_C(3764999332), UINT32_C(3258467564), UINT32_C( 539192593), UINT32_C( 400567969),
      UINT32_C(1694109361), UINT32_C(  91753382), UINT32_C(1742185273) };

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
    rv = simde_svsub_n_u32_m(pv, av, b);

    simde_svst1_u32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vu32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)];
  uint32_t a[1024 / sizeof(int32_t)], b, e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u32();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_u32(pg, &(a[i]));

    ev = simde_svsub_n_u32_m(pv, av, b);

    simde_svst1_u32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u32(1, b);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_u64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0) };
  static const uint64_t a[] =
    { UINT64_C(11259559028299137926), UINT64_C( 6780525287651880143), UINT64_C( 6632710156976157071), UINT64_C(  966931997870825586),
      UINT64_C( 9737381321220537150), UINT64_C(18410339725296610636), UINT64_C(13778779882706382364), UINT64_C(13638194343250379952),
      UINT64_C(10418062077162824532), UINT64_C(17005643663867389329), UINT64_C(14080784694891709532), UINT64_C( 9547419213710923331),
      UINT64_C(13273838899166298722), UINT64_C( 8072625452612183627), UINT64_C( 1339119189483966398), UINT64_C( 3588336248069328664),
      UINT64_C(14984616721776074262), UINT64_C( 2771950624293236467), UINT64_C( 3072171907189543361), UINT64_C(16148571029616358940),
      UINT64_C(17505511539059061405), UINT64_C(10326034650878303167), UINT64_C(17095595814251611394), UINT64_C(10224283791226614072),
      UINT64_C(15121010648113086694), UINT64_C( 4960792240054653306), UINT64_C(17386877233302992779), UINT64_C(18142705010557002313),
      UINT64_C(10356512321867708118), UINT64_C( 9372466877891654026), UINT64_C( 5499221710188014247), UINT64_C(17463918235014808907),
      UINT64_C( 9252808122842103235), UINT64_C(10934282430710628420), UINT64_C( 1231815616277028297), UINT64_C(12654216564576525966),
      UINT64_C( 5585007834875524619), UINT64_C(17849815011041070895), UINT64_C( 9781215826815463397), UINT64_C(  582316740045778809),
      UINT64_C(13445931592883739459), UINT64_C( 5800514736120013658), UINT64_C(11006720653284623168), UINT64_C(   67292026772517097),
      UINT64_C(16065156276321843628), UINT64_C(11368463548937587721), UINT64_C( 7268692680317976872), UINT64_C(11043736601464921221),
      UINT64_C( 9193750603997745204), UINT64_C(  759340193159576719), UINT64_C( 8743792500857200248), UINT64_C( 1338413372420170508),
      UINT64_C(13079684934212936591), UINT64_C(12053930785059731292), UINT64_C(15417496946077309321), UINT64_C( 4649791455585284502),
      UINT64_C( 1126122776626090692), UINT64_C(17661030231723295042), UINT64_C( 4453048098376233774), UINT64_C(13693821366261946904),
      UINT64_C( 6651052601765351563), UINT64_C( 6767755958732823178), UINT64_C(15887891087697927577), UINT64_C(17614616531330019258),
      UINT64_C(17255400569501260800), UINT64_C(14169961782133015577), UINT64_C(15262559610616477998), UINT64_C( 2669783716356126128),
      UINT64_C(15450643871557434902), UINT64_C( 5902463338064794107), UINT64_C( 2209035884458929596), UINT64_C( 4742645733154828423),
      UINT64_C(13985409429566919042), UINT64_C(13037025887028524152), UINT64_C(14505023759666786239), UINT64_C( 5246209534035657570),
      UINT64_C( 3090206782216768088) };
  static const uint64_t b = UINT64_C( 4949996049781626502);
  static const uint64_t e[] =
    { UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 1682714107194530569), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(13460343675514984134), UINT64_C( 8828783832924755862), UINT64_C( 8688198293468753450),
      UINT64_C(                   0), UINT64_C(12055647614085762827), UINT64_C( 9130788645110083030), UINT64_C(                   0),
      UINT64_C( 8323842849384672220), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(17085084271997253778),
      UINT64_C(10034620671994447760), UINT64_C(16268698648221161581), UINT64_C(                   0), UINT64_C(11198574979834732438),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(10171014598331460192), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(13192708960775375811),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(  549225660406387745), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(14728563640204953411), UINT64_C(                   0),
      UINT64_C(  635011785093898117), UINT64_C(12899818961259444393), UINT64_C( 4831219777033836895), UINT64_C(                   0),
      UINT64_C( 8495935543102112957), UINT64_C(  850518686338387156), UINT64_C( 6056724603502996666), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 3793796451075573746), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(17949796122304158888), UINT64_C( 8743825316480320402),
      UINT64_C( 1701056551983725061), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 9219965732351389075), UINT64_C(10312563560834851496), UINT64_C(16166531740284051242),
      UINT64_C(10500647821775808400), UINT64_C(  952467288283167605), UINT64_C(15705783908386854710), UINT64_C(18239393757082753537),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 9555027709885159737), UINT64_C(  296213484254031068),
      UINT64_C(                   0) };

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
    rv = simde_svsub_n_u64_z(pv, av, b);

    simde_svst1_u64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vu64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)];
  uint64_t a[1024 / sizeof(int64_t)], b, e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u64();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_u64(pg, &(a[i]));

    ev = simde_svsub_n_u64_z(pv, av, b);

    simde_svst1_u64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u64(1, b);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_u64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1) };
  static const uint64_t a[] =
    { UINT64_C( 8501431062812306052), UINT64_C( 7841066585143856980), UINT64_C(12503787968468883828), UINT64_C(12740474624915887193),
      UINT64_C(12638226849160574317), UINT64_C(10970614918816076879), UINT64_C( 6711468468839359373), UINT64_C(14924237995039793217),
      UINT64_C( 8272025249285874369), UINT64_C( 8138995059317370423), UINT64_C( 9910181181312621095), UINT64_C(10401929546469622825),
      UINT64_C( 8488011227097537077), UINT64_C(13563369375411474663), UINT64_C( 5976117454154702878), UINT64_C( 3248002396279662003),
      UINT64_C( 2379397285814911058), UINT64_C(13309022667012822369), UINT64_C(13672942807145159237), UINT64_C( 2888870968011300338),
      UINT64_C( 5796060076669705492), UINT64_C(14187739050722876051), UINT64_C(   97937965811106452), UINT64_C(  328204153881599119),
      UINT64_C(10943677844862158496), UINT64_C(12924952834293835035), UINT64_C( 1349862190799229098), UINT64_C( 5349438161035962184),
      UINT64_C( 7847443535104675660), UINT64_C(18280222294603705054), UINT64_C(17765137769496510966), UINT64_C( 5984838635905483289),
      UINT64_C( 9131200665578891259), UINT64_C( 1982757176136679221), UINT64_C(14397760270050212652), UINT64_C( 7240549502842306080),
      UINT64_C(16041375097859088000), UINT64_C( 8099981508902983976), UINT64_C( 4222996678594722853), UINT64_C( 4604328909123692055),
      UINT64_C( 2847118288379483899), UINT64_C(17856171988863018776), UINT64_C( 5200924405605734361), UINT64_C( 7388909914494177163),
      UINT64_C(   30272751693130308), UINT64_C(10897632190730723444), UINT64_C(17922558967998449473), UINT64_C( 8437999890671501895),
      UINT64_C( 2638868247674954678), UINT64_C( 7446884669241031684), UINT64_C(16289962522027090861), UINT64_C(15545208892934083605),
      UINT64_C(11287451785825252561), UINT64_C( 7034823503108771346), UINT64_C( 2312189438454364569), UINT64_C( 3015197711900519392),
      UINT64_C( 8487965210129878678), UINT64_C( 8751706700180760926), UINT64_C( 6697913106924761031), UINT64_C( 1364930967828781423),
      UINT64_C( 5286114269946027139), UINT64_C( 2274265413596219958), UINT64_C( 8184980071022411199), UINT64_C(12379035454664209214),
      UINT64_C( 5763743417264901319), UINT64_C(16676816399160924408), UINT64_C( 9486190797492674610), UINT64_C(15095793318572646315),
      UINT64_C(17833269358437273876) };
  static const uint64_t b = UINT64_C(14504115230018673405);
  static const uint64_t e[] =
    { UINT64_C( 8501431062812306052), UINT64_C( 7841066585143856980), UINT64_C(12503787968468883828), UINT64_C(12740474624915887193),
      UINT64_C(12638226849160574317), UINT64_C(10970614918816076879), UINT64_C(10654097312530237584), UINT64_C(  420122765021119812),
      UINT64_C( 8272025249285874369), UINT64_C(12081623903008248634), UINT64_C( 9910181181312621095), UINT64_C(10401929546469622825),
      UINT64_C( 8488011227097537077), UINT64_C(13563369375411474663), UINT64_C( 9918746297845581089), UINT64_C( 3248002396279662003),
      UINT64_C( 2379397285814911058), UINT64_C(13309022667012822369), UINT64_C(17615571650836037448), UINT64_C( 2888870968011300338),
      UINT64_C( 5796060076669705492), UINT64_C(18130367894413754262), UINT64_C( 4040566809501984663), UINT64_C( 4270832997572477330),
      UINT64_C(14886306688553036707), UINT64_C(12924952834293835035), UINT64_C( 1349862190799229098), UINT64_C( 9292067004726840395),
      UINT64_C(11790072378795553871), UINT64_C( 3776107064585031649), UINT64_C( 3261022539477837561), UINT64_C( 5984838635905483289),
      UINT64_C( 9131200665578891259), UINT64_C( 1982757176136679221), UINT64_C(14397760270050212652), UINT64_C( 7240549502842306080),
      UINT64_C(16041375097859088000), UINT64_C(12042610352593862187), UINT64_C( 4222996678594722853), UINT64_C( 8546957752814570266),
      UINT64_C( 6789747132070362110), UINT64_C( 3352056758844345371), UINT64_C( 5200924405605734361), UINT64_C(11331538758185055374),
      UINT64_C(   30272751693130308), UINT64_C(14840261034421601655), UINT64_C(17922558967998449473), UINT64_C(12380628734362380106),
      UINT64_C( 2638868247674954678), UINT64_C( 7446884669241031684), UINT64_C(16289962522027090861), UINT64_C( 1041093662915410200),
      UINT64_C(15230080629516130772), UINT64_C( 7034823503108771346), UINT64_C( 2312189438454364569), UINT64_C( 3015197711900519392),
      UINT64_C(12430594053820756889), UINT64_C( 8751706700180760926), UINT64_C( 6697913106924761031), UINT64_C( 5307559811519659634),
      UINT64_C( 5286114269946027139), UINT64_C( 2274265413596219958), UINT64_C(12127608914713289410), UINT64_C(12379035454664209214),
      UINT64_C( 9706372260955779530), UINT64_C(16676816399160924408), UINT64_C(13428819641183552821), UINT64_C(15095793318572646315),
      UINT64_C( 3329154128418600471) };

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
    rv = simde_svsub_n_u64_m(pv, av, b);

    simde_svst1_u64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vu64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)];
  uint64_t a[1024 / sizeof(int64_t)], b, e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u64();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_u64(pg, &(a[i]));

    ev = simde_svsub_n_u64_m(pv, av, b);

    simde_svst1_u64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u64(1, b);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_f32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) };
  static const simde_float32 a[] =
    { SIMDE_FLOAT32_C(  -674.47), SIMDE_FLOAT32_C(  -823.08), SIMDE_FLOAT32_C(   469.93), SIMDE_FLOAT32_C(  -755.58),
      SIMDE_FLOAT32_C(  -990.26), SIMDE_FLOAT32_C(  -884.66), SIMDE_FLOAT32_C(  -121.17), SIMDE_FLOAT32_C(  -727.85),
      SIMDE_FLOAT32_C(  -240.33), SIMDE_FLOAT32_C(   897.37), SIMDE_FLOAT32_C(   643.78), SIMDE_FLOAT32_C(   629.55),
      SIMDE_FLOAT32_C(   478.43), SIMDE_FLOAT32_C(   205.43), SIMDE_FLOAT32_C(   468.40), SIMDE_FLOAT32_C(  -597.37),
      SIMDE_FLOAT32_C(   159.04), SIMDE_FLOAT32_C(   634.31), SIMDE_FLOAT32_C(    74.81), SIMDE_FLOAT32_C(   789.35),
      SIMDE_FLOAT32_C(   463.03), SIMDE_FLOAT32_C(   689.50), SIMDE_FLOAT32_C(   934.85), SIMDE_FLOAT32_C(    60.29),
      SIMDE_FLOAT32_C(  -568.45), SIMDE_FLOAT32_C(  -715.38), SIMDE_FLOAT32_C(  -694.23), SIMDE_FLOAT32_C(  -447.88),
      SIMDE_FLOAT32_C(  -636.90), SIMDE_FLOAT32_C(   356.86), SIMDE_FLOAT32_C(   926.40), SIMDE_FLOAT32_C(  -311.37),
      SIMDE_FLOAT32_C(   533.79), SIMDE_FLOAT32_C(   396.32), SIMDE_FLOAT32_C(   -66.95), SIMDE_FLOAT32_C(   543.53),
      SIMDE_FLOAT32_C(   511.66), SIMDE_FLOAT32_C(   811.88), SIMDE_FLOAT32_C(   815.67), SIMDE_FLOAT32_C(  -728.67),
      SIMDE_FLOAT32_C(   709.26), SIMDE_FLOAT32_C(   459.45), SIMDE_FLOAT32_C(   900.88), SIMDE_FLOAT32_C(   187.69),
      SIMDE_FLOAT32_C(  -335.11), SIMDE_FLOAT32_C(   369.28), SIMDE_FLOAT32_C(   590.32), SIMDE_FLOAT32_C(   823.92),
      SIMDE_FLOAT32_C(     3.59), SIMDE_FLOAT32_C(  -334.87), SIMDE_FLOAT32_C(   613.28), SIMDE_FLOAT32_C(  -533.39),
      SIMDE_FLOAT32_C(  -645.37), SIMDE_FLOAT32_C(   548.13), SIMDE_FLOAT32_C(   526.91), SIMDE_FLOAT32_C(  -213.82),
      SIMDE_FLOAT32_C(   832.75), SIMDE_FLOAT32_C(   832.68), SIMDE_FLOAT32_C(   338.29), SIMDE_FLOAT32_C(  -804.15),
      SIMDE_FLOAT32_C(   189.54), SIMDE_FLOAT32_C(   264.69), SIMDE_FLOAT32_C(  -115.52), SIMDE_FLOAT32_C(  -276.67),
      SIMDE_FLOAT32_C(  -338.98), SIMDE_FLOAT32_C(   817.53), SIMDE_FLOAT32_C(  -733.15), SIMDE_FLOAT32_C(  -827.32),
      SIMDE_FLOAT32_C(   629.42), SIMDE_FLOAT32_C(  -917.47), SIMDE_FLOAT32_C(  -556.00), SIMDE_FLOAT32_C(   338.67),
      SIMDE_FLOAT32_C(   541.98), SIMDE_FLOAT32_C(  -655.12), SIMDE_FLOAT32_C(  -473.64), SIMDE_FLOAT32_C(  -793.13),
      SIMDE_FLOAT32_C(   714.16), SIMDE_FLOAT32_C(  -883.32), SIMDE_FLOAT32_C(  -969.21), SIMDE_FLOAT32_C(  -282.26),
      SIMDE_FLOAT32_C(  -218.18), SIMDE_FLOAT32_C(   644.07), SIMDE_FLOAT32_C(   184.36), SIMDE_FLOAT32_C(   136.45),
      SIMDE_FLOAT32_C(   192.20), SIMDE_FLOAT32_C(  -288.74), SIMDE_FLOAT32_C(   922.62), SIMDE_FLOAT32_C(    24.95),
      SIMDE_FLOAT32_C(  -456.05), SIMDE_FLOAT32_C(   260.92), SIMDE_FLOAT32_C(   220.81), SIMDE_FLOAT32_C(   733.49),
      SIMDE_FLOAT32_C(  -474.39), SIMDE_FLOAT32_C(  -894.71), SIMDE_FLOAT32_C(  -543.18), SIMDE_FLOAT32_C(   186.63),
      SIMDE_FLOAT32_C(   922.82), SIMDE_FLOAT32_C(  -276.33), SIMDE_FLOAT32_C(   359.30), SIMDE_FLOAT32_C(   552.24),
      SIMDE_FLOAT32_C(  -193.80), SIMDE_FLOAT32_C(   803.31), SIMDE_FLOAT32_C(  -109.09), SIMDE_FLOAT32_C(  -651.82),
      SIMDE_FLOAT32_C(  -851.81), SIMDE_FLOAT32_C(   417.28), SIMDE_FLOAT32_C(  -444.96), SIMDE_FLOAT32_C(   862.35),
      SIMDE_FLOAT32_C(   533.96), SIMDE_FLOAT32_C(  -414.17), SIMDE_FLOAT32_C(  -419.91), SIMDE_FLOAT32_C(  -684.22),
      SIMDE_FLOAT32_C(  -770.10), SIMDE_FLOAT32_C(   764.45), SIMDE_FLOAT32_C(   452.22), SIMDE_FLOAT32_C(   422.10),
      SIMDE_FLOAT32_C(  -524.29), SIMDE_FLOAT32_C(   374.84), SIMDE_FLOAT32_C(  -552.94), SIMDE_FLOAT32_C(    19.66),
      SIMDE_FLOAT32_C(  -364.24), SIMDE_FLOAT32_C(   667.86), SIMDE_FLOAT32_C(  -246.86), SIMDE_FLOAT32_C(   161.37),
      SIMDE_FLOAT32_C(   773.15), SIMDE_FLOAT32_C(   209.96), SIMDE_FLOAT32_C(  -652.00), SIMDE_FLOAT32_C(   695.97),
      SIMDE_FLOAT32_C(   933.63), SIMDE_FLOAT32_C(   707.30), SIMDE_FLOAT32_C(   248.21), SIMDE_FLOAT32_C(  -260.18),
      SIMDE_FLOAT32_C(   510.61), SIMDE_FLOAT32_C(  -860.87), SIMDE_FLOAT32_C(    88.00), SIMDE_FLOAT32_C(   658.80),
      SIMDE_FLOAT32_C(   556.40), SIMDE_FLOAT32_C(   643.04), SIMDE_FLOAT32_C(   521.14), SIMDE_FLOAT32_C(    90.36),
      SIMDE_FLOAT32_C(  -771.12), SIMDE_FLOAT32_C(  -898.77), SIMDE_FLOAT32_C(   406.14), SIMDE_FLOAT32_C(  -541.22),
      SIMDE_FLOAT32_C(   865.68), SIMDE_FLOAT32_C(  -141.64), SIMDE_FLOAT32_C(   880.88), SIMDE_FLOAT32_C(  -658.61),
      SIMDE_FLOAT32_C(  -766.80), SIMDE_FLOAT32_C(  -672.06), SIMDE_FLOAT32_C(   361.05), SIMDE_FLOAT32_C(  -131.04),
      SIMDE_FLOAT32_C(   995.81), SIMDE_FLOAT32_C(  -885.81), SIMDE_FLOAT32_C(  -969.67), SIMDE_FLOAT32_C(   768.96),
      SIMDE_FLOAT32_C(   324.15), SIMDE_FLOAT32_C(  -621.67), SIMDE_FLOAT32_C(   464.93), SIMDE_FLOAT32_C(   257.78),
      SIMDE_FLOAT32_C(  -914.37), SIMDE_FLOAT32_C(  -286.86), SIMDE_FLOAT32_C(   997.60), SIMDE_FLOAT32_C(   596.24),
      SIMDE_FLOAT32_C(  -147.73), SIMDE_FLOAT32_C(    85.60), SIMDE_FLOAT32_C(   255.04), SIMDE_FLOAT32_C(  -591.33),
      SIMDE_FLOAT32_C(  -271.36), SIMDE_FLOAT32_C(  -223.82), SIMDE_FLOAT32_C(   499.03) };
  static const simde_float32 b = SIMDE_FLOAT32_C(   -42.48);
  static const simde_float32 e[] =
    { SIMDE_FLOAT32_C(  -631.99), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -713.10),
      SIMDE_FLOAT32_C(  -947.78), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -78.69), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   247.91), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   201.52), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   505.51), SIMDE_FLOAT32_C(   731.98), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   102.77),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -594.42), SIMDE_FLOAT32_C(   399.34), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   438.80), SIMDE_FLOAT32_C(   -24.47), SIMDE_FLOAT32_C(   586.01),
      SIMDE_FLOAT32_C(   554.14), SIMDE_FLOAT32_C(   854.36), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -686.19),
      SIMDE_FLOAT32_C(   751.74), SIMDE_FLOAT32_C(   501.93), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   230.17),
      SIMDE_FLOAT32_C(  -292.63), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   632.80), SIMDE_FLOAT32_C(   866.40),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -292.39), SIMDE_FLOAT32_C(   655.76), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -602.89), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   569.39), SIMDE_FLOAT32_C(  -171.34),
      SIMDE_FLOAT32_C(   875.23), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   380.77), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   232.02), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -234.19),
      SIMDE_FLOAT32_C(  -296.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -690.67), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   671.90), SIMDE_FLOAT32_C(  -874.99), SIMDE_FLOAT32_C(  -513.52), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -612.64), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   756.64), SIMDE_FLOAT32_C(  -840.84), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -239.78),
      SIMDE_FLOAT32_C(  -175.70), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   226.84), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   234.68), SIMDE_FLOAT32_C(  -246.26), SIMDE_FLOAT32_C(   965.10), SIMDE_FLOAT32_C(    67.43),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   263.29), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -431.91), SIMDE_FLOAT32_C(  -852.23), SIMDE_FLOAT32_C(  -500.70), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   965.30), SIMDE_FLOAT32_C(  -233.85), SIMDE_FLOAT32_C(   401.78), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -151.32), SIMDE_FLOAT32_C(   845.79), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -809.33), SIMDE_FLOAT32_C(   459.76), SIMDE_FLOAT32_C(  -402.48), SIMDE_FLOAT32_C(   904.83),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -371.69), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   806.93), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   464.58),
      SIMDE_FLOAT32_C(  -481.81), SIMDE_FLOAT32_C(   417.32), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    62.14),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   710.34), SIMDE_FLOAT32_C(  -204.38), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   252.44), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   738.45),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   290.69), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   130.48), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   598.88), SIMDE_FLOAT32_C(   685.52), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   132.84),
      SIMDE_FLOAT32_C(  -728.64), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -99.16), SIMDE_FLOAT32_C(   923.36), SIMDE_FLOAT32_C(  -616.13),
      SIMDE_FLOAT32_C(  -724.32), SIMDE_FLOAT32_C(  -629.58), SIMDE_FLOAT32_C(   403.53), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  1038.29), SIMDE_FLOAT32_C(  -843.33), SIMDE_FLOAT32_C(  -927.19), SIMDE_FLOAT32_C(   811.44),
      SIMDE_FLOAT32_C(   366.63), SIMDE_FLOAT32_C(  -579.19), SIMDE_FLOAT32_C(   507.41), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -244.38), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   638.72),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -548.85),
      SIMDE_FLOAT32_C(  -228.88), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) };

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
    rv = simde_svsub_n_f32_z(pv, av, b);

    simde_svst1_f32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vf32(len, e, r, 1);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)];
  simde_float32 a[1024 / sizeof(simde_float32)], b, e[1024 / sizeof(simde_float32)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf32(HEDLEY_STATIC_CAST(size_t, len), a, SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_codegen_random_f32(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svfloat32_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_f32(pg, &(a[i]));

    ev = simde_svsub_n_f32_z(pv, av, b);

    simde_svst1_f32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1f32(1, b);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_f32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1) };
  static const simde_float32 a[] =
    { SIMDE_FLOAT32_C(   -25.23), SIMDE_FLOAT32_C(  -620.22), SIMDE_FLOAT32_C(   286.55), SIMDE_FLOAT32_C(  -102.00),
      SIMDE_FLOAT32_C(   965.08), SIMDE_FLOAT32_C(  -524.47), SIMDE_FLOAT32_C(   636.75), SIMDE_FLOAT32_C(  -402.05),
      SIMDE_FLOAT32_C(  -826.25), SIMDE_FLOAT32_C(  -703.04), SIMDE_FLOAT32_C(  -326.13), SIMDE_FLOAT32_C(   244.18),
      SIMDE_FLOAT32_C(   720.03), SIMDE_FLOAT32_C(   667.71), SIMDE_FLOAT32_C(   -93.26), SIMDE_FLOAT32_C(   417.01),
      SIMDE_FLOAT32_C(  -656.61), SIMDE_FLOAT32_C(  -154.03), SIMDE_FLOAT32_C(    66.09), SIMDE_FLOAT32_C(  -356.91),
      SIMDE_FLOAT32_C(  -953.04), SIMDE_FLOAT32_C(   478.31), SIMDE_FLOAT32_C(  -492.61), SIMDE_FLOAT32_C(  -378.98),
      SIMDE_FLOAT32_C(  -166.32), SIMDE_FLOAT32_C(  -239.34), SIMDE_FLOAT32_C(   382.39), SIMDE_FLOAT32_C(   130.81),
      SIMDE_FLOAT32_C(   587.15), SIMDE_FLOAT32_C(   939.13), SIMDE_FLOAT32_C(   567.81), SIMDE_FLOAT32_C(  -438.08),
      SIMDE_FLOAT32_C(  -681.09), SIMDE_FLOAT32_C(  -145.64), SIMDE_FLOAT32_C(   459.93), SIMDE_FLOAT32_C(  -716.02),
      SIMDE_FLOAT32_C(   329.89), SIMDE_FLOAT32_C(    96.68), SIMDE_FLOAT32_C(  -118.07), SIMDE_FLOAT32_C(   503.63),
      SIMDE_FLOAT32_C(   393.64), SIMDE_FLOAT32_C(   555.80), SIMDE_FLOAT32_C(  -252.19), SIMDE_FLOAT32_C(   113.67),
      SIMDE_FLOAT32_C(   223.51), SIMDE_FLOAT32_C(   654.55), SIMDE_FLOAT32_C(  -469.32), SIMDE_FLOAT32_C(   566.91),
      SIMDE_FLOAT32_C(  -499.48), SIMDE_FLOAT32_C(   596.77), SIMDE_FLOAT32_C(  -790.00), SIMDE_FLOAT32_C(  -452.51),
      SIMDE_FLOAT32_C(    75.08), SIMDE_FLOAT32_C(  -282.61), SIMDE_FLOAT32_C(   168.51), SIMDE_FLOAT32_C(   908.77),
      SIMDE_FLOAT32_C(   478.05), SIMDE_FLOAT32_C(  -449.10), SIMDE_FLOAT32_C(    39.57), SIMDE_FLOAT32_C(    65.20),
      SIMDE_FLOAT32_C(  -509.96), SIMDE_FLOAT32_C(  -392.62), SIMDE_FLOAT32_C(   627.12), SIMDE_FLOAT32_C(  -191.06),
      SIMDE_FLOAT32_C(   461.74), SIMDE_FLOAT32_C(    87.05), SIMDE_FLOAT32_C(    92.93), SIMDE_FLOAT32_C(  -208.37),
      SIMDE_FLOAT32_C(  -816.27), SIMDE_FLOAT32_C(   974.86), SIMDE_FLOAT32_C(  -704.74), SIMDE_FLOAT32_C(   577.36),
      SIMDE_FLOAT32_C(   530.66), SIMDE_FLOAT32_C(    43.07), SIMDE_FLOAT32_C(  -308.97), SIMDE_FLOAT32_C(  -245.82),
      SIMDE_FLOAT32_C(  -302.37), SIMDE_FLOAT32_C(   221.71), SIMDE_FLOAT32_C(  -678.92), SIMDE_FLOAT32_C(   198.15),
      SIMDE_FLOAT32_C(  -181.52), SIMDE_FLOAT32_C(  -468.92), SIMDE_FLOAT32_C(   745.64), SIMDE_FLOAT32_C(   893.57),
      SIMDE_FLOAT32_C(   248.47), SIMDE_FLOAT32_C(   -85.85), SIMDE_FLOAT32_C(   802.33), SIMDE_FLOAT32_C(  -273.47),
      SIMDE_FLOAT32_C(   465.05), SIMDE_FLOAT32_C(  -158.09), SIMDE_FLOAT32_C(   791.73), SIMDE_FLOAT32_C(   955.08),
      SIMDE_FLOAT32_C(   449.29), SIMDE_FLOAT32_C(   418.85), SIMDE_FLOAT32_C(  -235.97), SIMDE_FLOAT32_C(   -88.97),
      SIMDE_FLOAT32_C(  -494.10), SIMDE_FLOAT32_C(   856.96), SIMDE_FLOAT32_C(   702.66), SIMDE_FLOAT32_C(  -310.38),
      SIMDE_FLOAT32_C(   831.81), SIMDE_FLOAT32_C(   997.92), SIMDE_FLOAT32_C(  -733.02), SIMDE_FLOAT32_C(   362.48),
      SIMDE_FLOAT32_C(    40.99), SIMDE_FLOAT32_C(   -41.99), SIMDE_FLOAT32_C(  -883.34), SIMDE_FLOAT32_C(   738.62),
      SIMDE_FLOAT32_C(  -820.28), SIMDE_FLOAT32_C(  -562.26), SIMDE_FLOAT32_C(   -63.23), SIMDE_FLOAT32_C(    -1.79),
      SIMDE_FLOAT32_C(   -31.18), SIMDE_FLOAT32_C(  -317.60), SIMDE_FLOAT32_C(  -108.22), SIMDE_FLOAT32_C(  -782.70),
      SIMDE_FLOAT32_C(   596.55), SIMDE_FLOAT32_C(  -305.89), SIMDE_FLOAT32_C(   -56.18), SIMDE_FLOAT32_C(    61.60),
      SIMDE_FLOAT32_C(   536.02), SIMDE_FLOAT32_C(  -264.45), SIMDE_FLOAT32_C(    16.68), SIMDE_FLOAT32_C(   -14.69),
      SIMDE_FLOAT32_C(  -845.60), SIMDE_FLOAT32_C(   780.71), SIMDE_FLOAT32_C(   896.34), SIMDE_FLOAT32_C(  -339.70),
      SIMDE_FLOAT32_C(   637.67), SIMDE_FLOAT32_C(   599.00), SIMDE_FLOAT32_C(   349.92), SIMDE_FLOAT32_C(   469.48),
      SIMDE_FLOAT32_C(   596.91), SIMDE_FLOAT32_C(   616.90), SIMDE_FLOAT32_C(  -168.04), SIMDE_FLOAT32_C(  -362.10),
      SIMDE_FLOAT32_C(  -425.08), SIMDE_FLOAT32_C(   -51.39), SIMDE_FLOAT32_C(  -623.48), SIMDE_FLOAT32_C(  -245.36),
      SIMDE_FLOAT32_C(   386.35), SIMDE_FLOAT32_C(   313.28), SIMDE_FLOAT32_C(   752.85), SIMDE_FLOAT32_C(  -644.83),
      SIMDE_FLOAT32_C(   995.69), SIMDE_FLOAT32_C(  -355.37), SIMDE_FLOAT32_C(  -427.53), SIMDE_FLOAT32_C(   592.24),
      SIMDE_FLOAT32_C(   338.74), SIMDE_FLOAT32_C(   516.29), SIMDE_FLOAT32_C(  -346.16), SIMDE_FLOAT32_C(  -125.24),
      SIMDE_FLOAT32_C(  -748.16), SIMDE_FLOAT32_C(   670.52), SIMDE_FLOAT32_C(   860.07), SIMDE_FLOAT32_C(  -593.76),
      SIMDE_FLOAT32_C(   451.23), SIMDE_FLOAT32_C(   756.41), SIMDE_FLOAT32_C(    66.54), SIMDE_FLOAT32_C(    88.90),
      SIMDE_FLOAT32_C(   355.41), SIMDE_FLOAT32_C(  -583.54), SIMDE_FLOAT32_C(  -441.62), SIMDE_FLOAT32_C(   -47.68),
      SIMDE_FLOAT32_C(  -966.64), SIMDE_FLOAT32_C(   390.33), SIMDE_FLOAT32_C(   590.22), SIMDE_FLOAT32_C(  -391.72),
      SIMDE_FLOAT32_C(  -661.05), SIMDE_FLOAT32_C(   966.74), SIMDE_FLOAT32_C(   362.92), SIMDE_FLOAT32_C(   725.30),
      SIMDE_FLOAT32_C(   280.02), SIMDE_FLOAT32_C(   115.77), SIMDE_FLOAT32_C(  -919.52), SIMDE_FLOAT32_C(   275.71),
      SIMDE_FLOAT32_C(   760.40), SIMDE_FLOAT32_C(  -347.05), SIMDE_FLOAT32_C(  -132.06), SIMDE_FLOAT32_C(    99.14),
      SIMDE_FLOAT32_C(  -830.76), SIMDE_FLOAT32_C(   521.78), SIMDE_FLOAT32_C(   973.91), SIMDE_FLOAT32_C(  -578.92),
      SIMDE_FLOAT32_C(   192.30), SIMDE_FLOAT32_C(   833.98), SIMDE_FLOAT32_C(  -172.67), SIMDE_FLOAT32_C(  -356.47),
      SIMDE_FLOAT32_C(   590.39), SIMDE_FLOAT32_C(   893.86), SIMDE_FLOAT32_C(   732.43), SIMDE_FLOAT32_C(   -54.20),
      SIMDE_FLOAT32_C(  -689.68), SIMDE_FLOAT32_C(  -709.20), SIMDE_FLOAT32_C(   898.12), SIMDE_FLOAT32_C(  -656.32),
      SIMDE_FLOAT32_C(   681.14), SIMDE_FLOAT32_C(   488.34), SIMDE_FLOAT32_C(   -48.04), SIMDE_FLOAT32_C(  -979.91),
      SIMDE_FLOAT32_C(   455.07), SIMDE_FLOAT32_C(  -685.12), SIMDE_FLOAT32_C(   745.39), SIMDE_FLOAT32_C(  -264.91),
      SIMDE_FLOAT32_C(   430.65), SIMDE_FLOAT32_C(   825.86) };
  static const simde_float32 b = SIMDE_FLOAT32_C(  -989.20);
  static const simde_float32 e[] =
    { SIMDE_FLOAT32_C(   -25.23), SIMDE_FLOAT32_C(   368.98), SIMDE_FLOAT32_C(  1275.75), SIMDE_FLOAT32_C(   887.20),
      SIMDE_FLOAT32_C(  1954.28), SIMDE_FLOAT32_C(   464.73), SIMDE_FLOAT32_C(  1625.95), SIMDE_FLOAT32_C(  -402.05),
      SIMDE_FLOAT32_C(   162.95), SIMDE_FLOAT32_C(  -703.04), SIMDE_FLOAT32_C(  -326.13), SIMDE_FLOAT32_C(   244.18),
      SIMDE_FLOAT32_C(  1709.23), SIMDE_FLOAT32_C(  1656.91), SIMDE_FLOAT32_C(   895.94), SIMDE_FLOAT32_C(  1406.21),
      SIMDE_FLOAT32_C(   332.59), SIMDE_FLOAT32_C(  -154.03), SIMDE_FLOAT32_C(    66.09), SIMDE_FLOAT32_C(   632.29),
      SIMDE_FLOAT32_C(  -953.04), SIMDE_FLOAT32_C(   478.31), SIMDE_FLOAT32_C(   496.59), SIMDE_FLOAT32_C(  -378.98),
      SIMDE_FLOAT32_C(   822.88), SIMDE_FLOAT32_C(   749.86), SIMDE_FLOAT32_C(  1371.59), SIMDE_FLOAT32_C(   130.81),
      SIMDE_FLOAT32_C(  1576.35), SIMDE_FLOAT32_C(  1928.33), SIMDE_FLOAT32_C(   567.81), SIMDE_FLOAT32_C(  -438.08),
      SIMDE_FLOAT32_C(  -681.09), SIMDE_FLOAT32_C(  -145.64), SIMDE_FLOAT32_C(   459.93), SIMDE_FLOAT32_C(  -716.02),
      SIMDE_FLOAT32_C(  1319.09), SIMDE_FLOAT32_C(  1085.88), SIMDE_FLOAT32_C(   871.13), SIMDE_FLOAT32_C(   503.63),
      SIMDE_FLOAT32_C(   393.64), SIMDE_FLOAT32_C(   555.80), SIMDE_FLOAT32_C(  -252.19), SIMDE_FLOAT32_C(   113.67),
      SIMDE_FLOAT32_C(  1212.71), SIMDE_FLOAT32_C(  1643.75), SIMDE_FLOAT32_C(  -469.32), SIMDE_FLOAT32_C(   566.91),
      SIMDE_FLOAT32_C(  -499.48), SIMDE_FLOAT32_C(  1585.97), SIMDE_FLOAT32_C(  -790.00), SIMDE_FLOAT32_C(   536.69),
      SIMDE_FLOAT32_C(  1064.28), SIMDE_FLOAT32_C(   706.59), SIMDE_FLOAT32_C(   168.51), SIMDE_FLOAT32_C(  1897.97),
      SIMDE_FLOAT32_C(  1467.25), SIMDE_FLOAT32_C(   540.10), SIMDE_FLOAT32_C(  1028.77), SIMDE_FLOAT32_C(  1054.40),
      SIMDE_FLOAT32_C(  -509.96), SIMDE_FLOAT32_C(  -392.62), SIMDE_FLOAT32_C(  1616.32), SIMDE_FLOAT32_C(   798.14),
      SIMDE_FLOAT32_C(   461.74), SIMDE_FLOAT32_C(  1076.25), SIMDE_FLOAT32_C(    92.93), SIMDE_FLOAT32_C(  -208.37),
      SIMDE_FLOAT32_C(  -816.27), SIMDE_FLOAT32_C(  1964.06), SIMDE_FLOAT32_C(   284.46), SIMDE_FLOAT32_C(  1566.56),
      SIMDE_FLOAT32_C(   530.66), SIMDE_FLOAT32_C(    43.07), SIMDE_FLOAT32_C(  -308.97), SIMDE_FLOAT32_C(  -245.82),
      SIMDE_FLOAT32_C(   686.83), SIMDE_FLOAT32_C(  1210.91), SIMDE_FLOAT32_C(  -678.92), SIMDE_FLOAT32_C(  1187.35),
      SIMDE_FLOAT32_C(  -181.52), SIMDE_FLOAT32_C(   520.28), SIMDE_FLOAT32_C(   745.64), SIMDE_FLOAT32_C(   893.57),
      SIMDE_FLOAT32_C(  1237.67), SIMDE_FLOAT32_C(   -85.85), SIMDE_FLOAT32_C(  1791.53), SIMDE_FLOAT32_C(   715.73),
      SIMDE_FLOAT32_C(   465.05), SIMDE_FLOAT32_C(  -158.09), SIMDE_FLOAT32_C(  1780.93), SIMDE_FLOAT32_C(   955.08),
      SIMDE_FLOAT32_C(   449.29), SIMDE_FLOAT32_C(  1408.05), SIMDE_FLOAT32_C(  -235.97), SIMDE_FLOAT32_C(   -88.97),
      SIMDE_FLOAT32_C(  -494.10), SIMDE_FLOAT32_C(  1846.16), SIMDE_FLOAT32_C(   702.66), SIMDE_FLOAT32_C(  -310.38),
      SIMDE_FLOAT32_C(   831.81), SIMDE_FLOAT32_C(  1987.12), SIMDE_FLOAT32_C(  -733.02), SIMDE_FLOAT32_C(  1351.68),
      SIMDE_FLOAT32_C(  1030.19), SIMDE_FLOAT32_C(   947.21), SIMDE_FLOAT32_C(   105.86), SIMDE_FLOAT32_C(   738.62),
      SIMDE_FLOAT32_C(  -820.28), SIMDE_FLOAT32_C(   426.94), SIMDE_FLOAT32_C(   -63.23), SIMDE_FLOAT32_C(    -1.79),
      SIMDE_FLOAT32_C(   958.02), SIMDE_FLOAT32_C(   671.60), SIMDE_FLOAT32_C(  -108.22), SIMDE_FLOAT32_C(  -782.70),
      SIMDE_FLOAT32_C(  1585.75), SIMDE_FLOAT32_C(  -305.89), SIMDE_FLOAT32_C(   -56.18), SIMDE_FLOAT32_C(  1050.80),
      SIMDE_FLOAT32_C(  1525.22), SIMDE_FLOAT32_C(  -264.45), SIMDE_FLOAT32_C(  1005.88), SIMDE_FLOAT32_C(   -14.69),
      SIMDE_FLOAT32_C(   143.60), SIMDE_FLOAT32_C(   780.71), SIMDE_FLOAT32_C(  1885.54), SIMDE_FLOAT32_C(  -339.70),
      SIMDE_FLOAT32_C(  1626.87), SIMDE_FLOAT32_C(   599.00), SIMDE_FLOAT32_C(  1339.12), SIMDE_FLOAT32_C(  1458.68),
      SIMDE_FLOAT32_C(  1586.11), SIMDE_FLOAT32_C(  1606.10), SIMDE_FLOAT32_C(   821.16), SIMDE_FLOAT32_C(   627.10),
      SIMDE_FLOAT32_C(  -425.08), SIMDE_FLOAT32_C(   937.81), SIMDE_FLOAT32_C(  -623.48), SIMDE_FLOAT32_C(   743.84),
      SIMDE_FLOAT32_C(   386.35), SIMDE_FLOAT32_C(   313.28), SIMDE_FLOAT32_C(  1742.05), SIMDE_FLOAT32_C(  -644.83),
      SIMDE_FLOAT32_C(   995.69), SIMDE_FLOAT32_C(   633.83), SIMDE_FLOAT32_C(  -427.53), SIMDE_FLOAT32_C(   592.24),
      SIMDE_FLOAT32_C(  1327.94), SIMDE_FLOAT32_C(   516.29), SIMDE_FLOAT32_C(  -346.16), SIMDE_FLOAT32_C(   863.96),
      SIMDE_FLOAT32_C(   241.04), SIMDE_FLOAT32_C(  1659.72), SIMDE_FLOAT32_C(  1849.27), SIMDE_FLOAT32_C(  -593.76),
      SIMDE_FLOAT32_C(   451.23), SIMDE_FLOAT32_C(   756.41), SIMDE_FLOAT32_C(  1055.74), SIMDE_FLOAT32_C(    88.90),
      SIMDE_FLOAT32_C(  1344.61), SIMDE_FLOAT32_C(   405.66), SIMDE_FLOAT32_C(   547.58), SIMDE_FLOAT32_C(   941.52),
      SIMDE_FLOAT32_C(    22.56), SIMDE_FLOAT32_C(   390.33), SIMDE_FLOAT32_C(   590.22), SIMDE_FLOAT32_C(   597.48),
      SIMDE_FLOAT32_C(  -661.05), SIMDE_FLOAT32_C(   966.74), SIMDE_FLOAT32_C(   362.92), SIMDE_FLOAT32_C(   725.30),
      SIMDE_FLOAT32_C(   280.02), SIMDE_FLOAT32_C(  1104.97), SIMDE_FLOAT32_C(  -919.52), SIMDE_FLOAT32_C(  1264.91),
      SIMDE_FLOAT32_C(   760.40), SIMDE_FLOAT32_C(   642.15), SIMDE_FLOAT32_C(  -132.06), SIMDE_FLOAT32_C(    99.14),
      SIMDE_FLOAT32_C(   158.44), SIMDE_FLOAT32_C(   521.78), SIMDE_FLOAT32_C(  1963.11), SIMDE_FLOAT32_C(   410.28),
      SIMDE_FLOAT32_C(   192.30), SIMDE_FLOAT32_C(  1823.18), SIMDE_FLOAT32_C(   816.53), SIMDE_FLOAT32_C(  -356.47),
      SIMDE_FLOAT32_C(   590.39), SIMDE_FLOAT32_C(  1883.06), SIMDE_FLOAT32_C(   732.43), SIMDE_FLOAT32_C(   935.00),
      SIMDE_FLOAT32_C(   299.52), SIMDE_FLOAT32_C(  -709.20), SIMDE_FLOAT32_C(   898.12), SIMDE_FLOAT32_C(   332.88),
      SIMDE_FLOAT32_C(   681.14), SIMDE_FLOAT32_C(   488.34), SIMDE_FLOAT32_C(   -48.04), SIMDE_FLOAT32_C(  -979.91),
      SIMDE_FLOAT32_C(  1444.27), SIMDE_FLOAT32_C(  -685.12), SIMDE_FLOAT32_C(  1734.59), SIMDE_FLOAT32_C(  -264.91),
      SIMDE_FLOAT32_C(   430.65), SIMDE_FLOAT32_C(  1815.06) };

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
    rv = simde_svsub_n_f32_m(pv, av, b);

    simde_svst1_f32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vf32(len, e, r, 1);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)];
  simde_float32 a[1024 / sizeof(int32_t)], b, e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf32(HEDLEY_STATIC_CAST(size_t, len), a, SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_codegen_random_f32(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svfloat32_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_f32(pg, &(a[i]));

    ev = simde_svsub_n_f32_m(pv, av, b);

    simde_svst1_f32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1f32(1, b);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_f64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0) };
  static const simde_float64 a[] =
    { SIMDE_FLOAT64_C(  -578.13), SIMDE_FLOAT64_C(   301.00), SIMDE_FLOAT64_C(  -715.10), SIMDE_FLOAT64_C(  -482.58),
      SIMDE_FLOAT64_C(  -155.51), SIMDE_FLOAT64_C(  -519.84), SIMDE_FLOAT64_C(   826.06), SIMDE_FLOAT64_C(   642.24),
      SIMDE_FLOAT64_C(   515.57), SIMDE_FLOAT64_C(   624.29), SIMDE_FLOAT64_C(  -594.06), SIMDE_FLOAT64_C(   504.11),
      SIMDE_FLOAT64_C(   243.64), SIMDE_FLOAT64_C(  -627.30), SIMDE_FLOAT64_C(  -822.60), SIMDE_FLOAT64_C(  -193.46),
      SIMDE_FLOAT64_C(   435.25), SIMDE_FLOAT64_C(    94.35), SIMDE_FLOAT64_C(  -209.69), SIMDE_FLOAT64_C(  -167.04),
      SIMDE_FLOAT64_C(  -218.47), SIMDE_FLOAT64_C(  -152.97), SIMDE_FLOAT64_C(  -745.54), SIMDE_FLOAT64_C(  -788.51),
      SIMDE_FLOAT64_C(  -649.81), SIMDE_FLOAT64_C(   428.73), SIMDE_FLOAT64_C(  -485.80), SIMDE_FLOAT64_C(  -275.97),
      SIMDE_FLOAT64_C(   291.85), SIMDE_FLOAT64_C(  -124.19), SIMDE_FLOAT64_C(  -699.85), SIMDE_FLOAT64_C(   713.72),
      SIMDE_FLOAT64_C(  -823.19), SIMDE_FLOAT64_C(  -414.96), SIMDE_FLOAT64_C(  -768.86), SIMDE_FLOAT64_C(    21.30),
      SIMDE_FLOAT64_C(    65.20), SIMDE_FLOAT64_C(  -942.79), SIMDE_FLOAT64_C(  -336.45), SIMDE_FLOAT64_C(  -419.23),
      SIMDE_FLOAT64_C(   681.50), SIMDE_FLOAT64_C(    69.48), SIMDE_FLOAT64_C(  -915.12), SIMDE_FLOAT64_C(   -74.86),
      SIMDE_FLOAT64_C(   442.18), SIMDE_FLOAT64_C(  -737.72), SIMDE_FLOAT64_C(   731.68), SIMDE_FLOAT64_C(  -122.57),
      SIMDE_FLOAT64_C(   356.62), SIMDE_FLOAT64_C(  -478.01), SIMDE_FLOAT64_C(   710.40), SIMDE_FLOAT64_C(  -861.84),
      SIMDE_FLOAT64_C(   369.02), SIMDE_FLOAT64_C(   964.86), SIMDE_FLOAT64_C(  -650.35), SIMDE_FLOAT64_C(   719.21),
      SIMDE_FLOAT64_C(   393.59), SIMDE_FLOAT64_C(  -136.15), SIMDE_FLOAT64_C(  -556.76), SIMDE_FLOAT64_C(  -314.56),
      SIMDE_FLOAT64_C(   739.66), SIMDE_FLOAT64_C(  -256.62), SIMDE_FLOAT64_C(  -600.84), SIMDE_FLOAT64_C(   916.47),
      SIMDE_FLOAT64_C(   328.43), SIMDE_FLOAT64_C(  -369.69), SIMDE_FLOAT64_C(   -62.23), SIMDE_FLOAT64_C(  -606.37),
      SIMDE_FLOAT64_C(  -312.48), SIMDE_FLOAT64_C(   601.32), SIMDE_FLOAT64_C(   -25.60), SIMDE_FLOAT64_C(  -630.98),
      SIMDE_FLOAT64_C(  -329.20), SIMDE_FLOAT64_C(    59.28), SIMDE_FLOAT64_C(   294.16), SIMDE_FLOAT64_C(  -887.02),
      SIMDE_FLOAT64_C(   321.56), SIMDE_FLOAT64_C(    25.84), SIMDE_FLOAT64_C(    -9.59), SIMDE_FLOAT64_C(  -321.82),
      SIMDE_FLOAT64_C(   547.83), SIMDE_FLOAT64_C(  -299.19), SIMDE_FLOAT64_C(  -183.66), SIMDE_FLOAT64_C(   -83.15),
      SIMDE_FLOAT64_C(  -334.33) };
  static const simde_float64 b = SIMDE_FLOAT64_C(   165.99);
  static const simde_float64 e[] =
    { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -685.83), SIMDE_FLOAT64_C(   660.07), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   349.58), SIMDE_FLOAT64_C(   458.30), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   338.12),
      SIMDE_FLOAT64_C(    77.65), SIMDE_FLOAT64_C(  -793.29), SIMDE_FLOAT64_C(  -988.59), SIMDE_FLOAT64_C(  -359.45),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -71.64), SIMDE_FLOAT64_C(  -375.68), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  -384.46), SIMDE_FLOAT64_C(  -318.96), SIMDE_FLOAT64_C(  -911.53), SIMDE_FLOAT64_C(  -954.50),
      SIMDE_FLOAT64_C(  -815.80), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -651.79), SIMDE_FLOAT64_C(  -441.96),
      SIMDE_FLOAT64_C(   125.86), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   547.73),
      SIMDE_FLOAT64_C(  -989.18), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -934.85), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  -100.79), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -585.22),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -240.85),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -288.56),
      SIMDE_FLOAT64_C(   190.63), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C( -1027.83),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -816.34), SIMDE_FLOAT64_C(   553.22),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -302.14), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -480.55),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -766.83), SIMDE_FLOAT64_C(   750.48),
      SIMDE_FLOAT64_C(   162.44), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -228.22), SIMDE_FLOAT64_C(  -772.36),
      SIMDE_FLOAT64_C(  -478.47), SIMDE_FLOAT64_C(   435.33), SIMDE_FLOAT64_C(  -191.59), SIMDE_FLOAT64_C(  -796.97),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -465.18), SIMDE_FLOAT64_C(  -349.65), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00) };

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
    rv = simde_svsub_n_f64_z(pv, av, b);

    simde_svst1_f64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vf64(len, e, r, 1);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)];
  simde_float64 a[1024 / sizeof(int64_t)], b, e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf64(HEDLEY_STATIC_CAST(size_t, len), a, SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svfloat64_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_f64(pg, &(a[i]));

    ev = simde_svsub_n_f64_z(pv, av, b);

    simde_svst1_f64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1f64(1, b);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svsub_n_f64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1) };
  static const simde_float64 a[] =
    { SIMDE_FLOAT64_C(  -564.53), SIMDE_FLOAT64_C(   663.84), SIMDE_FLOAT64_C(   103.13), SIMDE_FLOAT64_C(  -321.33),
      SIMDE_FLOAT64_C(   571.92), SIMDE_FLOAT64_C(   335.28), SIMDE_FLOAT64_C(  -116.42), SIMDE_FLOAT64_C(  -566.52),
      SIMDE_FLOAT64_C(  -465.38), SIMDE_FLOAT64_C(  -310.82), SIMDE_FLOAT64_C(  -985.18), SIMDE_FLOAT64_C(   557.42),
      SIMDE_FLOAT64_C(  -978.25), SIMDE_FLOAT64_C(  -913.50), SIMDE_FLOAT64_C(  -490.80), SIMDE_FLOAT64_C(  -714.15),
      SIMDE_FLOAT64_C(  -409.30), SIMDE_FLOAT64_C(   910.46), SIMDE_FLOAT64_C(    35.85), SIMDE_FLOAT64_C(  -638.14),
      SIMDE_FLOAT64_C(  -383.95), SIMDE_FLOAT64_C(  -238.34), SIMDE_FLOAT64_C(  -307.49), SIMDE_FLOAT64_C(   942.53),
      SIMDE_FLOAT64_C(  -985.93), SIMDE_FLOAT64_C(  -291.92), SIMDE_FLOAT64_C(   270.44), SIMDE_FLOAT64_C(  -217.57),
      SIMDE_FLOAT64_C(   774.57), SIMDE_FLOAT64_C(   411.22), SIMDE_FLOAT64_C(   121.97), SIMDE_FLOAT64_C(  -789.96),
      SIMDE_FLOAT64_C(    75.06), SIMDE_FLOAT64_C(  -774.90), SIMDE_FLOAT64_C(  -111.29), SIMDE_FLOAT64_C(  -353.02),
      SIMDE_FLOAT64_C(   560.38), SIMDE_FLOAT64_C(   772.29), SIMDE_FLOAT64_C(    80.46), SIMDE_FLOAT64_C(  -905.00),
      SIMDE_FLOAT64_C(  -538.53), SIMDE_FLOAT64_C(    95.28), SIMDE_FLOAT64_C(   652.42), SIMDE_FLOAT64_C(  -516.78),
      SIMDE_FLOAT64_C(   181.78), SIMDE_FLOAT64_C(  -838.39), SIMDE_FLOAT64_C(  -230.93), SIMDE_FLOAT64_C(   772.48),
      SIMDE_FLOAT64_C(  -927.93), SIMDE_FLOAT64_C(   804.91), SIMDE_FLOAT64_C(  -865.66), SIMDE_FLOAT64_C(  -311.88),
      SIMDE_FLOAT64_C(  -433.42), SIMDE_FLOAT64_C(  -173.14), SIMDE_FLOAT64_C(  -369.35), SIMDE_FLOAT64_C(  -419.35),
      SIMDE_FLOAT64_C(   534.94), SIMDE_FLOAT64_C(   901.09), SIMDE_FLOAT64_C(   363.07), SIMDE_FLOAT64_C(   309.51),
      SIMDE_FLOAT64_C(   312.31), SIMDE_FLOAT64_C(  -514.96), SIMDE_FLOAT64_C(   519.54), SIMDE_FLOAT64_C(  -612.64),
      SIMDE_FLOAT64_C(  -289.86), SIMDE_FLOAT64_C(  -591.75), SIMDE_FLOAT64_C(    34.34), SIMDE_FLOAT64_C(  -729.48),
      SIMDE_FLOAT64_C(  -819.46), SIMDE_FLOAT64_C(  -885.20), SIMDE_FLOAT64_C(  -634.49) };
  static const simde_float64 b = SIMDE_FLOAT64_C(  -357.99);
  static const simde_float64 e[] =
    { SIMDE_FLOAT64_C(  -206.54), SIMDE_FLOAT64_C(   663.84), SIMDE_FLOAT64_C(   103.13), SIMDE_FLOAT64_C(    36.66),
      SIMDE_FLOAT64_C(   571.92), SIMDE_FLOAT64_C(   335.28), SIMDE_FLOAT64_C(  -116.42), SIMDE_FLOAT64_C(  -566.52),
      SIMDE_FLOAT64_C(  -107.39), SIMDE_FLOAT64_C(  -310.82), SIMDE_FLOAT64_C(  -985.18), SIMDE_FLOAT64_C(   557.42),
      SIMDE_FLOAT64_C(  -620.26), SIMDE_FLOAT64_C(  -913.50), SIMDE_FLOAT64_C(  -132.81), SIMDE_FLOAT64_C(  -356.16),
      SIMDE_FLOAT64_C(   -51.31), SIMDE_FLOAT64_C(   910.46), SIMDE_FLOAT64_C(   393.84), SIMDE_FLOAT64_C(  -280.15),
      SIMDE_FLOAT64_C(   -25.96), SIMDE_FLOAT64_C(   119.65), SIMDE_FLOAT64_C(  -307.49), SIMDE_FLOAT64_C(   942.53),
      SIMDE_FLOAT64_C(  -985.93), SIMDE_FLOAT64_C(  -291.92), SIMDE_FLOAT64_C(   628.43), SIMDE_FLOAT64_C(   140.42),
      SIMDE_FLOAT64_C(  1132.56), SIMDE_FLOAT64_C(   411.22), SIMDE_FLOAT64_C(   479.96), SIMDE_FLOAT64_C(  -431.97),
      SIMDE_FLOAT64_C(   433.05), SIMDE_FLOAT64_C(  -416.91), SIMDE_FLOAT64_C(  -111.29), SIMDE_FLOAT64_C(  -353.02),
      SIMDE_FLOAT64_C(   918.37), SIMDE_FLOAT64_C(  1130.28), SIMDE_FLOAT64_C(   438.45), SIMDE_FLOAT64_C(  -547.01),
      SIMDE_FLOAT64_C(  -180.54), SIMDE_FLOAT64_C(   453.27), SIMDE_FLOAT64_C(   652.42), SIMDE_FLOAT64_C(  -516.78),
      SIMDE_FLOAT64_C(   539.77), SIMDE_FLOAT64_C(  -838.39), SIMDE_FLOAT64_C(  -230.93), SIMDE_FLOAT64_C(   772.48),
      SIMDE_FLOAT64_C(  -927.93), SIMDE_FLOAT64_C(   804.91), SIMDE_FLOAT64_C(  -507.67), SIMDE_FLOAT64_C(    46.11),
      SIMDE_FLOAT64_C(   -75.43), SIMDE_FLOAT64_C(  -173.14), SIMDE_FLOAT64_C(   -11.36), SIMDE_FLOAT64_C(  -419.35),
      SIMDE_FLOAT64_C(   534.94), SIMDE_FLOAT64_C(   901.09), SIMDE_FLOAT64_C(   721.06), SIMDE_FLOAT64_C(   667.50),
      SIMDE_FLOAT64_C(   670.30), SIMDE_FLOAT64_C(  -514.96), SIMDE_FLOAT64_C(   877.53), SIMDE_FLOAT64_C(  -612.64),
      SIMDE_FLOAT64_C(  -289.86), SIMDE_FLOAT64_C(  -233.76), SIMDE_FLOAT64_C(    34.34), SIMDE_FLOAT64_C(  -371.49),
      SIMDE_FLOAT64_C(  -819.46), SIMDE_FLOAT64_C(  -885.20), SIMDE_FLOAT64_C(  -276.50) };

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
    rv = simde_svsub_n_f64_m(pv, av, b);

    simde_svst1_f64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vf64(len, e, r, 1);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)];
  simde_float64 a[1024 / sizeof(int64_t)], b, e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf64(HEDLEY_STATIC_CAST(size_t, len), a, SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svfloat64_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_f64(pg, &(a[i]));

    ev = simde_svsub_n_f64_m(pv, av, b);

    simde_svst1_f64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1f64(1, b);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_s8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_s8_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_s16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_s16_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_s32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_s32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_s64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_s64_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_u8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_u8_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_u16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_u16_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_u32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_u32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_u64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_u64_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_f32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_f32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_f64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_f64_m)

SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_s8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_s8_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_s16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_s16_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_s32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_s32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_s64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_s64_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_u8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_u8_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_u16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_u16_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_u32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_u32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_u64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_u64_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_f32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_f32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_f64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svsub_n_f64_m)
SIMDE_TEST_FUNC_LIST_END

#include "test-sve-footer.h"
