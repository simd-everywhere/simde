#define SIMDE_TEST_ARM_SVE_INSN add

#include "test-sve.h"
#include "../../../simde/arm/sve/add.h"

#include "../../../simde/arm/sve/cmplt.h"

static int
test_simde_svadd_s8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) };
  static const int8_t a[] =
    { -INT8_C(  21), -INT8_C(  97),  INT8_C(  57),  INT8_C( 105),  INT8_C(  75),  INT8_C(   6),  INT8_C( 121),  INT8_C(   9),
      -INT8_C(   8),  INT8_C(  41),  INT8_C( 110),  INT8_C(   6),  INT8_C(  80),  INT8_C(  67), -INT8_C( 115),  INT8_C( 103),
      -INT8_C( 124), -INT8_C( 101),  INT8_C(  80),  INT8_C(  91),  INT8_C( 104), -INT8_C(   5),  INT8_C(   8),  INT8_C(  21),
       INT8_C(  33),  INT8_C(  51), -INT8_C(  32),  INT8_C( 119),  INT8_C(  63), -INT8_C(  53), -INT8_C(   8),  INT8_C(  42),
       INT8_C( 106),  INT8_C(  49), -INT8_C( 109), -INT8_C(  74),  INT8_C(  55),  INT8_C(  12), -INT8_C(  65),  INT8_C(  47),
       INT8_C(  54),  INT8_C(  46),  INT8_C(  54), -INT8_C( 122),  INT8_C( 113), -INT8_C(  61), -INT8_C(  19), -INT8_C(  11),
       INT8_C(  95),  INT8_C(  61),  INT8_C(  80), -INT8_C(  57),  INT8_C(  57),  INT8_C(  88), -INT8_C(  36),  INT8_C(  90),
      -INT8_C( 117), -INT8_C(  67), -INT8_C(  46), -INT8_C(  54), -INT8_C( 120), -INT8_C(  54), -INT8_C(  11), -INT8_C(  13),
      -INT8_C(   5), -INT8_C( 120), -INT8_C(  87),  INT8_C(  51), -INT8_C( 107),  INT8_C( 104),  INT8_C(  98), -INT8_C(  53),
      -INT8_C( 106), -INT8_C( 104),  INT8_C(  81),  INT8_C(   7),  INT8_C(  92),  INT8_C(  62), -INT8_C(   3), -INT8_C(  69),
       INT8_C( 124),  INT8_C(  77), -INT8_C( 126), -INT8_C(  75), -INT8_C(  90),  INT8_C(  95),  INT8_C(  15),  INT8_C(  49),
       INT8_C(  28), -INT8_C(  31), -INT8_C(   4), -INT8_C(  92), -INT8_C(  85), -INT8_C(  15), -INT8_C( 105), -INT8_C(  89),
       INT8_C( 121),  INT8_C(  64), -INT8_C(  38),  INT8_C(  14), -INT8_C(  87),  INT8_C(  60), -INT8_C(  39),  INT8_C(  63),
      -INT8_C(  43),  INT8_C(  42),  INT8_C(  71),  INT8_C(  49),  INT8_C( 105),  INT8_C(  68), -INT8_C(  20), -INT8_C(  27),
      -INT8_C( 111),  INT8_C( 110), -INT8_C( 102),  INT8_C(  55), -INT8_C(  51), -INT8_C(  87),  INT8_C( 105), -INT8_C(  23),
      -INT8_C( 117),  INT8_C( 101), -INT8_C( 114),  INT8_C(  54),  INT8_C(  86),  INT8_C(  37), -INT8_C(  35), -INT8_C(  49),
       INT8_C( 102), -INT8_C(  73), -INT8_C(  34),  INT8_C(  15), -INT8_C(  12), -INT8_C(  73),  INT8_C(  78), -INT8_C(  55),
      -INT8_C(  30), -INT8_C( 107), -INT8_C(   6),  INT8_C(  75), -INT8_C(  39), -INT8_C(  26),  INT8_C(  48),  INT8_C( 107),
       INT8_C(  84), -INT8_C(  54), -INT8_C(  94),  INT8_C(  34),  INT8_C( 115),  INT8_C(  11),  INT8_C(  11), -INT8_C(   2),
       INT8_C( 112), -INT8_C( 103),  INT8_C(  53), -INT8_C(  58), -INT8_C(  65),  INT8_C(  18), -INT8_C( 106),  INT8_C(  37),
      -INT8_C(  54),  INT8_C( 116),  INT8_C(  52), -INT8_C(  66),  INT8_C(  43), -INT8_C( 126), -INT8_C( 121),  INT8_C(  13),
       INT8_C(  24), -INT8_C( 127),  INT8_C(  88), -INT8_C(  15),  INT8_C( 103), -INT8_C( 120),  INT8_C(  92), -INT8_C(  69),
       INT8_C(  82), -INT8_C(   1), -INT8_C(  35), -INT8_C(  58),  INT8_C(  10), -INT8_C(  23), -INT8_C(  60),  INT8_C( 123),
      -INT8_C( 126), -INT8_C(   7),  INT8_C(  65),  INT8_C(  65),  INT8_C(  12), -INT8_C(  41),  INT8_C( 102), -INT8_C(  42),
       INT8_C(  75), -INT8_C( 102), -INT8_C( 108),  INT8_C( 119),  INT8_C(  29),  INT8_C(  27), -INT8_C( 124),  INT8_C(  53),
      -INT8_C( 100), -INT8_C(  35),  INT8_C(  38),  INT8_C(   3),  INT8_C( 101), -INT8_C( 125), -INT8_C(  66), -INT8_C(  72),
      -INT8_C( 126), -INT8_C( 100),  INT8_C( 126), -INT8_C( 116), -INT8_C( 123),  INT8_C(  66),  INT8_C(   7),  INT8_C(   7),
       INT8_C(  60),  INT8_C(  73),  INT8_C(  73),  INT8_C(  72),  INT8_C(  32), -INT8_C(  81),  INT8_C(  30),  INT8_C( 108),
       INT8_C(  74), -INT8_C(  78), -INT8_C(  29),  INT8_C( 103), -INT8_C(  51),  INT8_C( 103), -INT8_C( 100),  INT8_C( 105),
       INT8_C(  68), -INT8_C(  62),  INT8_C( 108), -INT8_C(  86),  INT8_C(  69),  INT8_C(  42),  INT8_C(  98), -INT8_C(  57),
      -INT8_C(  58), -INT8_C(  32),  INT8_C(  84),  INT8_C(  75),  INT8_C(  34),  INT8_C(  91),  INT8_C(  83),  INT8_C(  94),
      -INT8_C(  92), -INT8_C( 100), -INT8_C(  90), -INT8_C(  59),  INT8_C(  75), -INT8_C(  60),  INT8_C(  49), -INT8_C( 107),
       INT8_C( 118),  INT8_C(  20), -INT8_C(   4),  INT8_C(  67),  INT8_C( 123), -INT8_C( 104), -INT8_C(  84), -INT8_C(  64),
       INT8_C(  91),  INT8_C(  24),  INT8_C( 106), -INT8_C(  96),  INT8_C(  67), -INT8_C(  52),  INT8_C( 104),  INT8_C(   9),
      -INT8_C(  84), -INT8_C(  68),  INT8_C(  85), -INT8_C(  50),  INT8_C(  23), -INT8_C(  88),  INT8_C(  45), -INT8_C(  68),
       INT8_C(  68), -INT8_C(  45), -INT8_C( 127), -INT8_C( 113), -INT8_C( 104), -INT8_C(  78),  INT8_C(  37),  INT8_C(  14),
      -INT8_C(  58),  INT8_C(  33),  INT8_C(  82),  INT8_C(  65), -INT8_C(  70), -INT8_C(   2),  INT8_C(   1),  INT8_C(  21),
       INT8_C(  23),  INT8_C( 107), -INT8_C(  75),  INT8_C(  90),  INT8_C(  55),  INT8_C(  29),  INT8_C(  99), -INT8_C(  29),
      -INT8_C(  39), -INT8_C(  72), -INT8_C(  78), -INT8_C(  15),  INT8_C(  96), -INT8_C(  33), -INT8_C(  83), -INT8_C(  92),
      -INT8_C(  78),  INT8_C(  46),  INT8_C(  52),  INT8_C(  74), -INT8_C(  32),  INT8_C(  89),  INT8_C(  89), -INT8_C(  90),
       INT8_C( 122), -INT8_C(  85), -INT8_C(  25),  INT8_C(  52), -INT8_C(  87), -INT8_C(  23),  INT8_C(  73), -INT8_C(  64),
       INT8_C(  84), -INT8_C(   1),  INT8_C(  26), -INT8_C( 116),  INT8_C(  28),  INT8_C( 126),  INT8_C( 111), -INT8_C(  10),
       INT8_C(  54),  INT8_C(  33), -INT8_C(  25), -INT8_C( 105),  INT8_C(   0), -INT8_C( 108),  INT8_C(  59), -INT8_C(  77),
      -INT8_C(  62),  INT8_C( 111), -INT8_C(   3), -INT8_C(  94), -INT8_C(  56),  INT8_C(  86),  INT8_C(  72),  INT8_C(  67),
       INT8_C(   1),  INT8_C(  47),  INT8_C( 119), -INT8_C(  85),  INT8_C(  24), -INT8_C(  63),  INT8_C( 107),  INT8_C( 109),
      -INT8_C(  64), -INT8_C( 122), -INT8_C(   7), -INT8_C(  36),  INT8_C(   4),  INT8_C( 104), -INT8_C(  46),  INT8_C(  58),
      -INT8_C( 118), -INT8_C(  71), -INT8_C(  47), -INT8_C( 118),  INT8_C(  77),  INT8_C(  13),  INT8_C(  61),  INT8_C(  15),
       INT8_C( 124),  INT8_C(  59), -INT8_C(  79),  INT8_C(  69), -INT8_C( 111), -INT8_C(   7), -INT8_C( 120), -INT8_C( 109),
       INT8_C(  41), -INT8_C(   1),  INT8_C(  62),  INT8_C(  65), -INT8_C(  64), -INT8_C(  87), -INT8_C(  82),      INT8_MIN,
       INT8_C(  47), -INT8_C(  89),  INT8_C(  93),  INT8_C(  51),  INT8_C(  16),  INT8_C(  47),  INT8_C( 110), -INT8_C( 102),
      -INT8_C(  23),  INT8_C(  63),  INT8_C(  36),  INT8_C(  54),  INT8_C(  76),  INT8_C(  98),  INT8_C(  70), -INT8_C(  55),
      -INT8_C(  99), -INT8_C(   9),  INT8_C(  14),  INT8_C(  46), -INT8_C(  15), -INT8_C( 106), -INT8_C(  63),  INT8_C(  26),
      -INT8_C( 107), -INT8_C(   1),  INT8_C(  91),  INT8_C(  86), -INT8_C(  87),  INT8_C(  10), -INT8_C(  42), -INT8_C(  40),
      -INT8_C(  79),  INT8_C(  51),  INT8_C(  12), -INT8_C(  63),  INT8_C(  99),  INT8_C( 122),  INT8_C(  91),  INT8_C(  76),
      -INT8_C(  71),      INT8_MIN, -INT8_C( 126),  INT8_C(   6), -INT8_C(  30), -INT8_C(  56), -INT8_C(  49),      INT8_MAX,
      -INT8_C(  64), -INT8_C(  35), -INT8_C(  83), -INT8_C(  79),  INT8_C( 115),  INT8_C( 111), -INT8_C(  53),  INT8_C(   8),
       INT8_C( 110),  INT8_C(  38),  INT8_C(  94),  INT8_C(  23),  INT8_C(  48),  INT8_C(  53), -INT8_C(  16), -INT8_C(  30),
       INT8_C( 104), -INT8_C(   4), -INT8_C(  93), -INT8_C(  53),  INT8_C( 118), -INT8_C(   1),  INT8_C(  23),  INT8_C(  47),
           INT8_MAX, -INT8_C( 102),  INT8_C(  53),  INT8_C(  97),  INT8_C(  98),  INT8_C(   4), -INT8_C(  32),  INT8_C(  34),
      -INT8_C(  31), -INT8_C( 115), -INT8_C(  45),  INT8_C(  84), -INT8_C(   4), -INT8_C(  98),  INT8_C(  93),  INT8_C( 107),
      -INT8_C(  59), -INT8_C(  69), -INT8_C( 126), -INT8_C(  11), -INT8_C(  16),  INT8_C( 114), -INT8_C(  41),  INT8_C(  89),
       INT8_C( 110),  INT8_C( 123),  INT8_C(  36), -INT8_C(  28),  INT8_C( 122),  INT8_C(  60),  INT8_C(  20), -INT8_C(   7),
      -INT8_C(  42),  INT8_C(  73),  INT8_C(  90),  INT8_C(  56),  INT8_C(  78),  INT8_C(  58),  INT8_C(  91),  INT8_C(  47),
      -INT8_C(  57),  INT8_C(  46), -INT8_C( 124), -INT8_C(  60), -INT8_C(  51), -INT8_C(  31),  INT8_C(  47), -INT8_C( 110),
      -INT8_C( 100), -INT8_C(  79), -INT8_C( 121), -INT8_C( 115),  INT8_C(  36),  INT8_C(  95), -INT8_C(  26), -INT8_C( 110),
      -INT8_C(  38),  INT8_C(  10),  INT8_C( 119),  INT8_C(  84),  INT8_C(  70), -INT8_C( 117),  INT8_C(  77),  INT8_C(  28),
      -INT8_C(  44), -INT8_C(  89),  INT8_C(  85),  INT8_C(  34), -INT8_C(  31), -INT8_C(  80),  INT8_C(  82), -INT8_C(  88),
      -INT8_C(  34), -INT8_C(  42),  INT8_C( 108), -INT8_C(  85), -INT8_C(  73), -INT8_C( 101),  INT8_C(  61),  INT8_C(  83),
       INT8_C(  77), -INT8_C(  59), -INT8_C(  32),  INT8_C( 113),  INT8_C(  36), -INT8_C(  58),  INT8_C(   3), -INT8_C(   2),
      -INT8_C(  47),  INT8_C( 122),  INT8_C(  82),  INT8_C(  23),  INT8_C(   5), -INT8_C(  97),  INT8_C(  52), -INT8_C(  38),
       INT8_C(  70), -INT8_C( 119), -INT8_C(   4),  INT8_C(  39),  INT8_C(  57),  INT8_C(  78), -INT8_C(  49),  INT8_C(  23),
       INT8_C(  36),  INT8_C(  60), -INT8_C(  61), -INT8_C(  37), -INT8_C(  41),  INT8_C(   0),  INT8_C(  47),  INT8_C(  36),
      -INT8_C(  59),  INT8_C(  15), -INT8_C( 107), -INT8_C(  23), -INT8_C(  42), -INT8_C( 103), -INT8_C(  25), -INT8_C(  89),
       INT8_C(  19),  INT8_C(  57), -INT8_C(  66),  INT8_C(  25), -INT8_C(  40), -INT8_C(  14), -INT8_C(  13),  INT8_C(  30),
       INT8_C( 123), -INT8_C(  17),  INT8_C(  69), -INT8_C(  76),  INT8_C(  62),  INT8_C(  21), -INT8_C(  52),  INT8_C(  98),
       INT8_C(  81), -INT8_C( 113),  INT8_C(  62),  INT8_C(  40), -INT8_C( 113),  INT8_C( 109),  INT8_C(  77),  INT8_C(  85),
       INT8_C( 124), -INT8_C(  30),  INT8_C(  62),  INT8_C(  82),  INT8_C( 123),  INT8_C(  38), -INT8_C(   7), -INT8_C( 113),
       INT8_C(  95), -INT8_C(  72), -INT8_C(  88),  INT8_C(  56), -INT8_C(  86), -INT8_C( 101),  INT8_C(  86),  INT8_C(  38),
      -INT8_C( 118), -INT8_C( 100), -INT8_C(  38), -INT8_C(  56), -INT8_C(  79), -INT8_C(  90),  INT8_C(  43),  INT8_C(   2),
       INT8_C(  53),  INT8_C( 105),  INT8_C(  42), -INT8_C(  59), -INT8_C(  42),  INT8_C( 119),  INT8_C(  26),  INT8_C(  82),
       INT8_C(  90),  INT8_C(  88), -INT8_C(  91), -INT8_C(  43),  INT8_C( 126), -INT8_C(  98),  INT8_C( 100), -INT8_C(  34),
       INT8_C(  86),  INT8_C(  12),  INT8_C(  22),  INT8_C(   1), -INT8_C(  89),  INT8_C( 108),  INT8_C(  39),  INT8_C(  50),
       INT8_C(   8),  INT8_C(   1), -INT8_C(   6), -INT8_C(  71), -INT8_C(  88),  INT8_C(  37), -INT8_C(  69), -INT8_C(  35),
      -INT8_C( 114), -INT8_C(  26), -INT8_C(  94),  INT8_C( 100),  INT8_C(  93), -INT8_C(  68), -INT8_C(  73), -INT8_C(  73),
       INT8_C(  21),  INT8_C(  92), -INT8_C( 115), -INT8_C( 109), -INT8_C(   6), -INT8_C(  15),  INT8_C( 113),  INT8_C(  81),
      -INT8_C(   2), -INT8_C( 121),  INT8_C(  82), -INT8_C(  91), -INT8_C(  12),  INT8_C( 121), -INT8_C(  41), -INT8_C(   4),
       INT8_C( 122), -INT8_C(  46), -INT8_C(  74),  INT8_C(  34), -INT8_C(   9),  INT8_C( 113),  INT8_C(   0), -INT8_C( 122),
       INT8_C(  87), -INT8_C(  94), -INT8_C(  22), -INT8_C(  75),  INT8_C(  95), -INT8_C(  95),  INT8_C( 108),  INT8_C( 116),
      -INT8_C(   3), -INT8_C(   7),  INT8_C(   7), -INT8_C(   8), -INT8_C(  21),  INT8_C( 121),  INT8_C(  73), -INT8_C(  23),
       INT8_C(   0), -INT8_C( 101), -INT8_C( 114), -INT8_C(  12),  INT8_C(  20),  INT8_C( 102), -INT8_C(  15), -INT8_C( 114),
       INT8_C(  56), -INT8_C(  89), -INT8_C(  79),  INT8_C(  47),  INT8_C(  24), -INT8_C(  79), -INT8_C(  75),  INT8_C( 112),
       INT8_C(  83), -INT8_C(  96),  INT8_C(  37), -INT8_C(  78),  INT8_C(  65), -INT8_C( 111),  INT8_C(  38),  INT8_C(  63) };
  static const int8_t b[] =
    { -INT8_C( 117),  INT8_C(  46),  INT8_C(  55),  INT8_C( 118), -INT8_C(  89),      INT8_MIN,  INT8_C(  95), -INT8_C(  89),
       INT8_C(  27), -INT8_C(  19), -INT8_C( 100),  INT8_C(  47),  INT8_C(  83), -INT8_C( 115), -INT8_C(  67), -INT8_C( 117),
       INT8_C(  52),  INT8_C( 110), -INT8_C(  69),  INT8_C(  76),  INT8_C(  31),  INT8_C( 112), -INT8_C(  68),  INT8_C( 115),
       INT8_C(  16), -INT8_C(  31),  INT8_C(  37),  INT8_C(  82),  INT8_C( 115),  INT8_C(  76), -INT8_C( 111), -INT8_C(   2),
       INT8_C( 122), -INT8_C(  56),  INT8_C( 116),  INT8_C(  33),  INT8_C(  72), -INT8_C(  45), -INT8_C(  56),  INT8_C(  99),
      -INT8_C(  64),  INT8_C( 100), -INT8_C( 110),  INT8_C(  20), -INT8_C(  15),  INT8_C(  79), -INT8_C(  97),  INT8_C(  37),
      -INT8_C(  66),  INT8_C(  90),  INT8_C( 114), -INT8_C(  35), -INT8_C(  53),  INT8_C(  46),  INT8_C(  80), -INT8_C(  37),
       INT8_C(  16),  INT8_C( 118),  INT8_C(  45), -INT8_C( 125), -INT8_C(  62), -INT8_C(  66), -INT8_C( 127),  INT8_C(  60),
      -INT8_C( 122), -INT8_C(  11),  INT8_C(  93), -INT8_C(  50), -INT8_C(  56),  INT8_C(  37),  INT8_C(  49), -INT8_C( 120),
      -INT8_C( 118), -INT8_C(  61), -INT8_C( 100),  INT8_C( 123),  INT8_C(  19),  INT8_C(  60), -INT8_C(  95), -INT8_C(  47),
      -INT8_C( 106),  INT8_C(  19), -INT8_C(  82),  INT8_C(  97),  INT8_C(  65), -INT8_C(   1),  INT8_C(  61),  INT8_C(  81),
       INT8_C( 117),  INT8_C( 106), -INT8_C(  44),  INT8_C(  55),  INT8_C(  41),  INT8_C(  85),  INT8_C( 115), -INT8_C(  81),
       INT8_C(  74), -INT8_C(  48),  INT8_C( 126),  INT8_C(  18), -INT8_C(  11), -INT8_C(  81), -INT8_C( 101),      INT8_MAX,
       INT8_C( 115),  INT8_C(  55), -INT8_C(   5), -INT8_C( 122),  INT8_C( 115), -INT8_C( 100),  INT8_C(  87),  INT8_C(  10),
      -INT8_C(  81),  INT8_C(   5),  INT8_C( 107), -INT8_C(  16),  INT8_C(   4), -INT8_C(  88),  INT8_C(  66),  INT8_C( 121),
       INT8_C(  19),  INT8_C(  22), -INT8_C(  80),  INT8_C(  60),  INT8_C( 108),  INT8_C(  35), -INT8_C(  21), -INT8_C(  74),
      -INT8_C(  13),  INT8_C( 105), -INT8_C(  55), -INT8_C(  23),  INT8_C(  25),  INT8_C( 100),  INT8_C( 104), -INT8_C( 116),
      -INT8_C( 101),  INT8_C(  99),  INT8_C(  18),  INT8_C(  15), -INT8_C(   1),  INT8_C( 105),  INT8_C(  25), -INT8_C(  82),
       INT8_C( 110), -INT8_C( 124), -INT8_C(  97),  INT8_C( 115),  INT8_C(  45), -INT8_C(  31), -INT8_C(  20),  INT8_C(  64),
      -INT8_C(   9), -INT8_C(  99),  INT8_C( 124),  INT8_C(  99), -INT8_C(  64),  INT8_C( 103),  INT8_C(  26), -INT8_C(  76),
      -INT8_C(  47), -INT8_C(  29), -INT8_C(  99), -INT8_C(  22),  INT8_C(  71),  INT8_C(   5),  INT8_C( 118), -INT8_C(  30),
       INT8_C( 105), -INT8_C( 120), -INT8_C(  15),  INT8_C( 104), -INT8_C(  15),  INT8_C(  10),  INT8_C(  23),  INT8_C(  95),
      -INT8_C( 113), -INT8_C(  74), -INT8_C(  46), -INT8_C(  68), -INT8_C( 105), -INT8_C(  65), -INT8_C(   4), -INT8_C( 114),
       INT8_C(  92),  INT8_C( 120), -INT8_C(  14),  INT8_C(  28), -INT8_C(  33),  INT8_C(  12), -INT8_C(  48), -INT8_C(  80),
      -INT8_C(  17),  INT8_C( 109), -INT8_C( 102),  INT8_C(  54),  INT8_C( 115),  INT8_C(  16),  INT8_C(  24), -INT8_C(  36),
      -INT8_C( 104),  INT8_C(  10),  INT8_C(  68), -INT8_C( 119),  INT8_C(  20),  INT8_C(  91), -INT8_C(  23), -INT8_C(  93),
       INT8_C(  17), -INT8_C(  69),  INT8_C(  95), -INT8_C(  88),  INT8_C( 122),  INT8_C(  91),  INT8_C(  55), -INT8_C(  42),
      -INT8_C(  45),  INT8_C(  41), -INT8_C(  13), -INT8_C(  77),  INT8_C(  53), -INT8_C(  61),  INT8_C(  99),  INT8_C(  36),
       INT8_C(  49), -INT8_C(   2),  INT8_C(  90), -INT8_C(  92),  INT8_C(  14),  INT8_C( 114),      INT8_MIN, -INT8_C(  89),
       INT8_C( 124), -INT8_C(  60),  INT8_C(  48), -INT8_C( 111),  INT8_C(  32),  INT8_C(  25),  INT8_C(  52),  INT8_C(  49),
      -INT8_C(  43), -INT8_C( 108), -INT8_C(  38),  INT8_C(  79), -INT8_C(  17),  INT8_C(  17),  INT8_C(  38), -INT8_C(  61),
       INT8_C(  58),  INT8_C(  25),  INT8_C( 118),  INT8_C( 111), -INT8_C(  36), -INT8_C(  39), -INT8_C( 109),  INT8_C(  13),
      -INT8_C(  41), -INT8_C(  19), -INT8_C(  79), -INT8_C(  26),  INT8_C(  95),  INT8_C(  49), -INT8_C( 115), -INT8_C(  36),
      -INT8_C(  10), -INT8_C(  67),  INT8_C( 109),  INT8_C(  22), -INT8_C(  41), -INT8_C(  95),  INT8_C(  71), -INT8_C(  84),
       INT8_C(  53),  INT8_C(  33), -INT8_C(   5),  INT8_C(  37),  INT8_C(  50),  INT8_C(  33), -INT8_C(  24),  INT8_C( 108),
       INT8_C(  58),  INT8_C(  94), -INT8_C(  37),  INT8_C(  23),  INT8_C(  55),  INT8_C( 110),  INT8_C(  36),  INT8_C(  15),
       INT8_C(  91), -INT8_C(  42), -INT8_C(  11), -INT8_C(  69),  INT8_C(   7), -INT8_C( 126), -INT8_C( 105), -INT8_C(   3),
       INT8_C(  63),  INT8_C(   4),  INT8_C(  19),  INT8_C(  22), -INT8_C(  91),  INT8_C(  91), -INT8_C(  62), -INT8_C(  37),
       INT8_C( 124), -INT8_C(  66),  INT8_C(   0), -INT8_C(  81), -INT8_C(  33), -INT8_C(  24),  INT8_C(  27),  INT8_C(  26),
       INT8_C(  70), -INT8_C(   9),  INT8_C(  49),  INT8_C( 125),  INT8_C( 101),  INT8_C(  85), -INT8_C( 116), -INT8_C(  63),
       INT8_C(  43), -INT8_C( 127),  INT8_C( 124),  INT8_C(  51),  INT8_C(   3),  INT8_C(  19),  INT8_C(  48),  INT8_C(  67),
       INT8_C(  23),  INT8_C(  68),  INT8_C(  89), -INT8_C(  68), -INT8_C(  97),  INT8_C(  28), -INT8_C( 105),  INT8_C(  27),
      -INT8_C(  38), -INT8_C( 105), -INT8_C(  54), -INT8_C(  71),      INT8_MAX, -INT8_C(  26), -INT8_C(  45), -INT8_C(  59),
      -INT8_C(  35),  INT8_C(   4),  INT8_C(  67),  INT8_C(  66),  INT8_C(  90), -INT8_C(  49),  INT8_C(   3), -INT8_C( 123),
       INT8_C(  81),      INT8_MAX, -INT8_C(  72),  INT8_C(  84), -INT8_C( 110), -INT8_C(  23), -INT8_C( 105), -INT8_C(  87),
       INT8_C(  45), -INT8_C(  15),  INT8_C( 102), -INT8_C(  52),  INT8_C(  13), -INT8_C(   3), -INT8_C(  25), -INT8_C(  25),
      -INT8_C( 107), -INT8_C(  78), -INT8_C(  96),  INT8_C(  20), -INT8_C( 104),  INT8_C( 116), -INT8_C(  38),  INT8_C( 117),
       INT8_C( 120),  INT8_C(  29), -INT8_C(  73), -INT8_C(  46), -INT8_C(  20), -INT8_C(  69),  INT8_C(  88),  INT8_C(  61),
       INT8_C(  58),  INT8_C(  16), -INT8_C( 110), -INT8_C(  51), -INT8_C(   7),  INT8_C(  41),  INT8_C( 118),  INT8_C(  38),
       INT8_C(  26), -INT8_C(  36), -INT8_C(  14),  INT8_C(  39), -INT8_C(  38), -INT8_C(  38),  INT8_C(  14),  INT8_C( 111),
      -INT8_C( 116), -INT8_C(  81), -INT8_C( 125),  INT8_C(  36),  INT8_C(  35),  INT8_C(  93), -INT8_C( 103), -INT8_C( 101),
       INT8_C( 122),  INT8_C(  80),  INT8_C( 110),  INT8_C( 103),  INT8_C(  11), -INT8_C(  58), -INT8_C(  92),  INT8_C(  70),
      -INT8_C(  42),  INT8_C(  54),  INT8_C(  19), -INT8_C(  48),  INT8_C(  96), -INT8_C( 119), -INT8_C(  10),  INT8_C( 122),
       INT8_C( 102), -INT8_C(  23), -INT8_C(  94),  INT8_C(  64), -INT8_C(  61), -INT8_C(  80), -INT8_C(  81),  INT8_C(  79),
       INT8_C(  95),  INT8_C(  50),  INT8_C( 115), -INT8_C( 126), -INT8_C( 112),  INT8_C(  12),  INT8_C(  30),  INT8_C(  10),
       INT8_C(  92), -INT8_C( 116),  INT8_C( 113),  INT8_C( 104),  INT8_C(  82),  INT8_C(  22), -INT8_C(  82),  INT8_C(  40),
       INT8_C(  76), -INT8_C(  63), -INT8_C(   8), -INT8_C(  84),  INT8_C(  74), -INT8_C(  17),  INT8_C(  39), -INT8_C(  80),
      -INT8_C(  40), -INT8_C(  55), -INT8_C(  16), -INT8_C( 101),  INT8_C( 121), -INT8_C(  97), -INT8_C(  22), -INT8_C(  39),
      -INT8_C(  46),  INT8_C(  93),  INT8_C(  91),  INT8_C(  98),  INT8_C( 105),  INT8_C( 121),  INT8_C( 108), -INT8_C(  59),
       INT8_C(   5), -INT8_C(  34),  INT8_C(  45),  INT8_C(  87), -INT8_C(  12), -INT8_C(  37),      INT8_MIN,  INT8_C(  64),
      -INT8_C( 100),  INT8_C( 120), -INT8_C(  19), -INT8_C(  25),  INT8_C( 103),  INT8_C(  20), -INT8_C( 105),  INT8_C(  63),
      -INT8_C(  35), -INT8_C( 120), -INT8_C(  38),  INT8_C(  86),  INT8_C(  39), -INT8_C(  60),  INT8_C(  47), -INT8_C(   7),
       INT8_C(  33), -INT8_C( 117),  INT8_C(  91), -INT8_C( 118),  INT8_C(   4), -INT8_C(  56),  INT8_C(  80),  INT8_C(  10),
      -INT8_C(  90),  INT8_C( 125),  INT8_C(  97), -INT8_C( 102),  INT8_C(  89), -INT8_C(  31), -INT8_C(  38), -INT8_C(  11),
       INT8_C(  90), -INT8_C(  57), -INT8_C(  36), -INT8_C(  63), -INT8_C(  37),  INT8_C( 116),  INT8_C(   1), -INT8_C(  72),
      -INT8_C(   4), -INT8_C(  37),  INT8_C(  15),  INT8_C(  35), -INT8_C(  96),  INT8_C(  62),  INT8_C(  29), -INT8_C(  63),
      -INT8_C(  55),  INT8_C( 120),  INT8_C(  76), -INT8_C(  50),  INT8_C(  64), -INT8_C( 100), -INT8_C(  40), -INT8_C(  26),
       INT8_C(  25),  INT8_C(  57),      INT8_MIN,  INT8_C( 114),  INT8_C(  27),  INT8_C(  91),  INT8_C( 104),  INT8_C( 117),
       INT8_C(  34),  INT8_C(  68),  INT8_C(  54), -INT8_C(   2), -INT8_C(  72),  INT8_C(  55), -INT8_C(  74), -INT8_C(  76),
       INT8_C(  19), -INT8_C(  59), -INT8_C(  40), -INT8_C(  77),  INT8_C(   4), -INT8_C(  11),  INT8_C( 116), -INT8_C(  51),
       INT8_C( 109), -INT8_C(  64), -INT8_C( 101), -INT8_C(  82),  INT8_C(  92),  INT8_C( 115), -INT8_C( 108),  INT8_C( 118),
      -INT8_C(  83),  INT8_C(  21), -INT8_C(  24), -INT8_C(  56),  INT8_C( 112),  INT8_C(  80),  INT8_C(  61), -INT8_C( 110),
      -INT8_C( 107),  INT8_C( 115), -INT8_C( 112),  INT8_C(  77), -INT8_C(  85),  INT8_C(  71),  INT8_C(   2), -INT8_C(  66),
       INT8_C(  12), -INT8_C(  38),  INT8_C( 113),  INT8_C(  16), -INT8_C(  49), -INT8_C(  27), -INT8_C(  34),  INT8_C(  60),
      -INT8_C(  90),  INT8_C( 121), -INT8_C(  22),  INT8_C(   2), -INT8_C(  19),      INT8_MAX,  INT8_C( 120), -INT8_C( 102),
      -INT8_C( 108),  INT8_C(  97),  INT8_C(  98),  INT8_C(   4), -INT8_C(  79), -INT8_C(  97), -INT8_C( 106),  INT8_C(  70),
       INT8_C(  18),  INT8_C(  39), -INT8_C( 108), -INT8_C(  67),  INT8_C( 110), -INT8_C( 106),  INT8_C( 123),  INT8_C( 122),
       INT8_C( 112), -INT8_C(  20), -INT8_C( 117),  INT8_C(  63), -INT8_C(  46),  INT8_C( 105),  INT8_C( 123),  INT8_C( 120),
      -INT8_C(  30),  INT8_C( 102),  INT8_C( 122), -INT8_C(  49), -INT8_C(  27), -INT8_C(  13),  INT8_C( 105),  INT8_C( 121),
       INT8_C(  84), -INT8_C(  53),  INT8_C( 125),  INT8_C(   5),  INT8_C( 106),  INT8_C(  19),  INT8_C(  76),  INT8_C( 125),
       INT8_C(  58), -INT8_C(  32),  INT8_C(  58), -INT8_C(  88),  INT8_C( 118), -INT8_C(  74),  INT8_C(  35), -INT8_C(  26),
      -INT8_C(  94), -INT8_C(  82),  INT8_C(  37),  INT8_C( 116),  INT8_C(  23), -INT8_C(  96), -INT8_C(  20), -INT8_C(   7),
       INT8_C(   6),  INT8_C( 103), -INT8_C(  55), -INT8_C(  21),  INT8_C(  90),  INT8_C(  50),  INT8_C( 100), -INT8_C(  82),
      -INT8_C(   2), -INT8_C(  31), -INT8_C(  77),  INT8_C( 104), -INT8_C(  11), -INT8_C(   1), -INT8_C(  27),  INT8_C(  47),
      -INT8_C(  33),  INT8_C(  32), -INT8_C(  40),  INT8_C(  85), -INT8_C(  42), -INT8_C(   5),  INT8_C(  59),  INT8_C( 120),
      -INT8_C(  87),  INT8_C(  96), -INT8_C(  19), -INT8_C(  64),  INT8_C(   1), -INT8_C(  39), -INT8_C(  71),  INT8_C(   7),
       INT8_C(  64), -INT8_C( 126), -INT8_C(  13), -INT8_C( 102), -INT8_C(  75),  INT8_C(  87),  INT8_C(  72), -INT8_C(  77),
       INT8_C(  57), -INT8_C(   4),  INT8_C(  27),  INT8_C(  46), -INT8_C(   5),  INT8_C(   1),  INT8_C(  93), -INT8_C(  37),
       INT8_C(  33),  INT8_C(  53),  INT8_C(  48), -INT8_C(   9),  INT8_C(  48),  INT8_C( 108),  INT8_C( 111), -INT8_C(  39),
      -INT8_C(  52),  INT8_C(  92), -INT8_C( 103), -INT8_C(  51),  INT8_C(  54),  INT8_C(  83), -INT8_C(  43),  INT8_C( 118),
      -INT8_C(  43), -INT8_C(  56),  INT8_C(  17), -INT8_C( 118),  INT8_C(  31),  INT8_C(  89),  INT8_C(  61),  INT8_C(  88),
       INT8_C(  85),  INT8_C(  89), -INT8_C( 122),  INT8_C(  81),  INT8_C(  90), -INT8_C(  28),  INT8_C(  44),  INT8_C( 123) };
  static const int8_t e[] =
    {  INT8_C( 118), -INT8_C(  51),  INT8_C(   0), -INT8_C(  33), -INT8_C(  14), -INT8_C( 122), -INT8_C(  40), -INT8_C(  80),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  93),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 121),  INT8_C( 107),  INT8_C(   0), -INT8_C( 120),
       INT8_C(   0),  INT8_C(  20),  INT8_C(   5), -INT8_C(  55), -INT8_C(  78),  INT8_C(  23), -INT8_C( 119),  INT8_C(   0),
      -INT8_C(  28),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MAX,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  10),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  98),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  29), -INT8_C( 105), -INT8_C(  62),  INT8_C(   0),  INT8_C(   0), -INT8_C( 122),  INT8_C(   0),  INT8_C(  53),
      -INT8_C( 101),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(  74),  INT8_C(   0),  INT8_C( 118),  INT8_C(   0),
      -INT8_C( 127),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 115),  INT8_C(   0),  INT8_C(  83),
       INT8_C(   0),  INT8_C(  91), -INT8_C(  19), -INT8_C( 126),  INT8_C(   0),  INT8_C(   0), -INT8_C(  98), -INT8_C( 116),
       INT8_C(   0),  INT8_C(  96),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  94),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 111),  INT8_C(  75),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  86),
       INT8_C(   0),  INT8_C(  16),  INT8_C(  88),  INT8_C(  32), -INT8_C(  98),  INT8_C(   0),  INT8_C(   0), -INT8_C(  66),
       INT8_C(  72),  INT8_C(   0),  INT8_C(  66), -INT8_C(  73), -INT8_C(  36),  INT8_C(   0),  INT8_C(  67), -INT8_C(  17),
       INT8_C(  64),  INT8_C( 115),  INT8_C(   0),  INT8_C(   0), -INT8_C(  47),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C( 123),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  72), -INT8_C(  56), -INT8_C( 123),
       INT8_C(  89),  INT8_C(  32),  INT8_C(   0),  INT8_C(   0),  INT8_C(  13),  INT8_C(  27), -INT8_C(  74),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  90), -INT8_C(  40),  INT8_C(  79),  INT8_C(  73),  INT8_C(  25),
      -INT8_C(  62),  INT8_C(  78),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  20),  INT8_C(   0),  INT8_C(  62),
       INT8_C( 103),  INT8_C(  54), -INT8_C(  79),  INT8_C(  41),      INT8_MAX,  INT8_C( 121), -INT8_C(  80),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  88),  INT8_C( 114),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 127),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 110),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  31),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  88), -INT8_C(  64),  INT8_C(   9),
      -INT8_C(  34),  INT8_C( 113),  INT8_C(  51),  INT8_C(   0), -INT8_C(  21),  INT8_C(   0),  INT8_C(   0), -INT8_C( 122),
       INT8_C(   0),  INT8_C(   7),  INT8_C(  46),  INT8_C(   0), -INT8_C( 112),  INT8_C(  43), -INT8_C( 100),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  25),  INT8_C( 106), -INT8_C( 116),  INT8_C( 121), -INT8_C(  34), -INT8_C(  89),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  87), -INT8_C(  35),  INT8_C(   0), -INT8_C(   1), -INT8_C(  99),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  15),  INT8_C( 114),  INT8_C(   0),  INT8_C(   0),  INT8_C(  85),  INT8_C( 114), -INT8_C( 127),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  61),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  16),
      -INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 101),  INT8_C(  67), -INT8_C( 106),  INT8_C(   0),
      -INT8_C( 101),  INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 108),  INT8_C( 121),  INT8_C(  33),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  39), -INT8_C(  99),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   1), -INT8_C(  83),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 100),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  26),  INT8_C(   0),  INT8_C(   0), -INT8_C(  75),
      -INT8_C(  31), -INT8_C(  35),  INT8_C(  80), -INT8_C(  13),  INT8_C(   0), -INT8_C(  55),  INT8_C(  21),  INT8_C(   0),
       INT8_C( 126),  INT8_C(  49),  INT8_C(  92), -INT8_C(  90), -INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C(  29),
       INT8_C(  33), -INT8_C(   9),  INT8_C(   0),  INT8_C(   0), -INT8_C(  63),  INT8_C(   0), -INT8_C( 104),  INT8_C(  18),
       INT8_C(  86),  INT8_C(   0), -INT8_C(  56),  INT8_C( 112),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  66),
       INT8_C(  85),  INT8_C(   0), -INT8_C(  78),  INT8_C(   0),  INT8_C(  63),  INT8_C(   0), -INT8_C(  56),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C( 101), -INT8_C(  57),  INT8_C(   0), -INT8_C(  82), -INT8_C(  27),  INT8_C(   0),
      -INT8_C(  91),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  84),  INT8_C(   0),  INT8_C( 121),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  67),  INT8_C( 115),  INT8_C(   0), -INT8_C(  69), -INT8_C( 102),  INT8_C(   0),  INT8_C(  17),
       INT8_C(  16), -INT8_C(  72), -INT8_C(  79),  INT8_C(  80),  INT8_C(   0),  INT8_C(   0),  INT8_C(  14),  INT8_C(   0),
       INT8_C(   0),  INT8_C( 115),  INT8_C(   0), -INT8_C(  28),  INT8_C(  34),  INT8_C(  37),  INT8_C(  75),  INT8_C(   0),
       INT8_C(  82), -INT8_C(  82),  INT8_C(  47), -INT8_C(   1), -INT8_C(  86), -INT8_C(  86),  INT8_C(   2),  INT8_C(   0),
       INT8_C(   0),  INT8_C( 119),  INT8_C(   0),  INT8_C(   0),  INT8_C(  17),  INT8_C(   0),  INT8_C(   0),  INT8_C(  33),
       INT8_C(   0),  INT8_C( 107),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 124),
      -INT8_C(  12),  INT8_C(   0),  INT8_C(   0),  INT8_C(  23),  INT8_C(   0),  INT8_C(   0), -INT8_C(  32),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  15), -INT8_C(  48),  INT8_C(  14),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  79),  INT8_C(  90), -INT8_C(  22),  INT8_C(   9),  INT8_C(   0),  INT8_C(   9),
       INT8_C( 117),  INT8_C(   0), -INT8_C(  89),  INT8_C(  90),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  23),  INT8_C(  71),  INT8_C( 124), -INT8_C( 107), -INT8_C(   4),  INT8_C(  92),  INT8_C( 101),  INT8_C(  96),
       INT8_C(   0),  INT8_C(   0),  INT8_C( 110),  INT8_C(   0),  INT8_C(   9), -INT8_C( 109), -INT8_C(  52),  INT8_C(  82),
       INT8_C(   0),  INT8_C(  28), -INT8_C(  82),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(  10),  INT8_C(   0),
       INT8_C(  24), -INT8_C(  78), -INT8_C(  11), -INT8_C( 120),  INT8_C( 114),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  28),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  59), -INT8_C( 123),  INT8_C( 121),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  25),  INT8_C(  86), -INT8_C(  61),  INT8_C(   0),  INT8_C(  36),  INT8_C(  23),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  59),  INT8_C(   0),  INT8_C( 102), -INT8_C(  17),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),
       INT8_C(  81), -INT8_C(   9),  INT8_C(   0), -INT8_C(  61), -INT8_C(  53),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  26),  INT8_C(   0),  INT8_C(   0), -INT8_C(  85), -INT8_C(  16),  INT8_C(   0), -INT8_C(  35),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  51),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 122),  INT8_C( 110), -INT8_C( 104),
       INT8_C(  75),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   9), -INT8_C(  44), -INT8_C(  75),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  85),  INT8_C(  57),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  38),  INT8_C(   0),  INT8_C(   0), -INT8_C( 121),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  45),  INT8_C(   0),  INT8_C(  74),
      -INT8_C(  42),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  26), -INT8_C(  55),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  31), -INT8_C(  95),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   9),  INT8_C(  15), -INT8_C(  20),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 111), -INT8_C(  36), -INT8_C(   3), -INT8_C(  71), -INT8_C(  78),
      -INT8_C(  28),  INT8_C(  63),  INT8_C(  42), -INT8_C(  54),  INT8_C(   0), -INT8_C( 108), -INT8_C(  88),  INT8_C(   0),
      -INT8_C(  77),  INT8_C(  73), -INT8_C( 105), -INT8_C(  43),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 115),
      -INT8_C(  47),  INT8_C(  81),  INT8_C(   0), -INT8_C(  93),  INT8_C(  71),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 126),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  32),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  19),  INT8_C(  47),  INT8_C(   0), -INT8_C(  89), -INT8_C(  41), -INT8_C(  47),  INT8_C(  90),
       INT8_C(   0),  INT8_C( 104),  INT8_C(  47), -INT8_C(  74),  INT8_C(  43),  INT8_C(   0),  INT8_C(   0), -INT8_C(   4),
      -INT8_C(  27),  INT8_C(   0), -INT8_C(  96),  INT8_C(  44),  INT8_C(  64),  INT8_C(  12),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  46),  INT8_C(   0), -INT8_C(  23), -INT8_C(  68),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  49), -INT8_C(  92),  INT8_C(   0),  INT8_C( 119),  INT8_C( 124),  INT8_C(   0),  INT8_C(   0), -INT8_C(  98),
       INT8_C( 108),  INT8_C(   0),  INT8_C(   0), -INT8_C( 105),  INT8_C(   0), -INT8_C( 103),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  54),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0), -INT8_C(  49),
      -INT8_C( 108),  INT8_C(  56),  INT8_C(   0),  INT8_C( 125), -INT8_C(  12),  INT8_C(  84), -INT8_C( 121),  INT8_C(   0),
      -INT8_C(   8), -INT8_C(  70),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  12),  INT8_C(  19),  INT8_C(  43),
       INT8_C(  14),  INT8_C(   0),  INT8_C(   0), -INT8_C(  92),  INT8_C(   0),  INT8_C(  87),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C(  52),  INT8_C(  82),  INT8_C(   0), -INT8_C( 100),  INT8_C(   0),
       INT8_C(   0),  INT8_C( 124),  INT8_C( 101), -INT8_C(  24), -INT8_C(  48), -INT8_C(  20), -INT8_C(  84),  INT8_C(   0),
      -INT8_C(  89),  INT8_C(   0),  INT8_C(   0),  INT8_C( 101), -INT8_C(  11),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  84),  INT8_C(   0), -INT8_C(  68), -INT8_C(  84), -INT8_C(  56),  INT8_C(  72),  INT8_C(  57),
      -INT8_C( 112), -INT8_C(  98),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  55),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  46),  INT8_C(  55), -INT8_C(  17),  INT8_C(   0), -INT8_C(  27), -INT8_C(  72),  INT8_C(   0),
      -INT8_C(  52), -INT8_C(   9),  INT8_C(  39),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  58),  INT8_C(   4),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  71),  INT8_C(  55),  INT8_C(  10), -INT8_C(  14), -INT8_C(  56),
      -INT8_C(  88),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(  82), -INT8_C(  70) };

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
    rv = simde_svadd_s8_z(pv, av, bv);

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

    ev = simde_svadd_s8_z(pv, av, bv);

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
test_simde_svadd_s8_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) };
  static const int8_t a[] =
    {  INT8_C(  72), -INT8_C(  84), -INT8_C(  69),  INT8_C(  28), -INT8_C(  98),  INT8_C(  53), -INT8_C(  98),  INT8_C(  49),
      -INT8_C(  48),  INT8_C(  94),  INT8_C( 112),  INT8_C(  87), -INT8_C(  63), -INT8_C( 117),  INT8_C( 113),  INT8_C( 125),
       INT8_C(  20), -INT8_C(  49),  INT8_C(  44), -INT8_C( 101),  INT8_C(  84), -INT8_C(  60),  INT8_C(  57), -INT8_C(  89),
       INT8_C(  46), -INT8_C(  67),  INT8_C(   0),  INT8_C(  64),  INT8_C( 122), -INT8_C(  50),  INT8_C(  97), -INT8_C(  62),
       INT8_C( 122),  INT8_C(  28), -INT8_C(  34),  INT8_C(  24),  INT8_C(  81),  INT8_C( 124),  INT8_C(  73),  INT8_C(  34),
      -INT8_C(  38), -INT8_C(  71),  INT8_C( 121), -INT8_C( 100),  INT8_C(  68), -INT8_C(  22),  INT8_C(  25),  INT8_C(  88),
      -INT8_C(  70),  INT8_C(  69), -INT8_C(  13),  INT8_C(  14),  INT8_C(   9),  INT8_C(  44), -INT8_C(  75),  INT8_C(  55),
      -INT8_C(  23), -INT8_C(  74),  INT8_C( 120),  INT8_C(  99), -INT8_C( 124), -INT8_C(  39),  INT8_C(  37), -INT8_C(   1),
      -INT8_C(  11),  INT8_C(   3),  INT8_C(  23),  INT8_C(  71),      INT8_MIN,  INT8_C(  97),  INT8_C( 105),  INT8_C(  90),
       INT8_C(  26), -INT8_C(  30), -INT8_C(  10),  INT8_C(  95), -INT8_C(  52),  INT8_C(  15), -INT8_C(  73), -INT8_C( 122),
       INT8_C(  85), -INT8_C(  85), -INT8_C( 108),  INT8_C(  94), -INT8_C(  41),  INT8_C(  74), -INT8_C( 106), -INT8_C(  63),
       INT8_C(   0),  INT8_C(  14),  INT8_C(  36), -INT8_C( 124), -INT8_C(  25),  INT8_C(  74), -INT8_C( 125), -INT8_C(  36),
       INT8_C(  77), -INT8_C( 101),  INT8_C(  35), -INT8_C(  51), -INT8_C(   4), -INT8_C( 116),  INT8_C(  40),  INT8_C(  22),
       INT8_C( 110),  INT8_C(  30),  INT8_C( 117),  INT8_C(  59),  INT8_C(  46),  INT8_C(  45), -INT8_C(  63), -INT8_C( 125),
      -INT8_C(  40),  INT8_C(  86), -INT8_C(  31), -INT8_C(  81), -INT8_C(  96),  INT8_C( 119),  INT8_C( 112), -INT8_C(  96),
      -INT8_C( 123), -INT8_C( 107),  INT8_C(  36),  INT8_C( 108), -INT8_C(  33), -INT8_C(  88),  INT8_C(  73),  INT8_C(  44),
       INT8_C(  67),  INT8_C( 108), -INT8_C(   6),  INT8_C(  63), -INT8_C(   7),  INT8_C(  34),  INT8_C(  85),  INT8_C( 103),
       INT8_C(  64), -INT8_C(  53), -INT8_C(  94),  INT8_C( 110), -INT8_C(   8),  INT8_C( 100), -INT8_C(  15), -INT8_C(  48),
      -INT8_C(  70), -INT8_C(  45),      INT8_MAX,  INT8_C(  90),  INT8_C(  74), -INT8_C(  16), -INT8_C(   6), -INT8_C(  48),
      -INT8_C( 123),  INT8_C(  30),  INT8_C(  60),  INT8_C( 100), -INT8_C(  58), -INT8_C( 123), -INT8_C( 112),  INT8_C(   9),
      -INT8_C(  14), -INT8_C( 118),  INT8_C(  72), -INT8_C(  21), -INT8_C(  84), -INT8_C(  98),  INT8_C(  82), -INT8_C(  19),
       INT8_C( 105), -INT8_C(  11),  INT8_C(  91),  INT8_C(  97),  INT8_C(  89),  INT8_C(  77),  INT8_C(  49),  INT8_C(  19),
       INT8_C(  32), -INT8_C(  80),  INT8_C( 109),  INT8_C( 106), -INT8_C(  96),  INT8_C( 103),  INT8_C(  58),  INT8_C(  37),
      -INT8_C( 123),  INT8_C( 119), -INT8_C( 119),  INT8_C(  76), -INT8_C(   4),  INT8_C(  26),  INT8_C(  85), -INT8_C(  18),
      -INT8_C(  92), -INT8_C(  98), -INT8_C(  39),  INT8_C(  81),  INT8_C(  60),  INT8_C(  44),  INT8_C(  62), -INT8_C(  91),
       INT8_C(  33), -INT8_C( 103),  INT8_C(   6),  INT8_C( 122), -INT8_C(  26),  INT8_C(  55), -INT8_C( 115),  INT8_C(   6),
      -INT8_C(  25), -INT8_C(   6),  INT8_C( 113), -INT8_C( 120),  INT8_C(  97), -INT8_C(  85), -INT8_C(  83), -INT8_C(  26),
       INT8_C(  34),  INT8_C(  55),  INT8_C(  50),  INT8_C(  31),  INT8_C(  81), -INT8_C( 120),  INT8_C(  13), -INT8_C(  11),
       INT8_C(  38), -INT8_C(  25),  INT8_C(  70),  INT8_C(  98),  INT8_C(  19), -INT8_C( 124),  INT8_C(   7),  INT8_C(  52),
       INT8_C(  30),  INT8_C(  13), -INT8_C(  82),  INT8_C(   4),  INT8_C(  68),  INT8_C(  59),  INT8_C(  11),  INT8_C(  43),
       INT8_C(  53),  INT8_C( 124), -INT8_C(  77), -INT8_C( 106),  INT8_C(  39),  INT8_C(  97),  INT8_C( 124),  INT8_C(  74),
      -INT8_C( 104), -INT8_C(  81),  INT8_C( 105), -INT8_C(  23),  INT8_C(  55),  INT8_C( 118), -INT8_C(  34),  INT8_C(  93),
       INT8_C(  93),  INT8_C(  37), -INT8_C(  65),  INT8_C( 112), -INT8_C(  87), -INT8_C(  58), -INT8_C(  92), -INT8_C(  57),
      -INT8_C(  45),  INT8_C(  82), -INT8_C(  52),  INT8_C(  23), -INT8_C( 115), -INT8_C(  41),  INT8_C(  66), -INT8_C(  62),
       INT8_C(  83), -INT8_C(  10),  INT8_C(  88),  INT8_C( 122),  INT8_C(  87), -INT8_C(  43), -INT8_C(  60), -INT8_C(  17),
      -INT8_C( 124),  INT8_C(  45), -INT8_C(  40), -INT8_C(  69), -INT8_C(  92), -INT8_C(  74),  INT8_C(  24),  INT8_C(   1),
      -INT8_C(  37), -INT8_C(  41),  INT8_C( 114), -INT8_C( 123), -INT8_C(  99),  INT8_C(  22),  INT8_C(  76),  INT8_C( 112),
       INT8_C( 105),  INT8_C(  24), -INT8_C( 121), -INT8_C(  10), -INT8_C(  17), -INT8_C(  55), -INT8_C(  71),  INT8_C(  66),
      -INT8_C(  65),  INT8_C(  17), -INT8_C(  67),  INT8_C(  22), -INT8_C(  26), -INT8_C( 127),  INT8_C(   5),  INT8_C( 106),
      -INT8_C(  81), -INT8_C(  35),  INT8_C(  37),  INT8_C(  83), -INT8_C( 108),  INT8_C(  61),  INT8_C(  84),  INT8_C( 111),
       INT8_C(  20), -INT8_C(  58), -INT8_C(  12), -INT8_C(  79), -INT8_C(  35),  INT8_C(  65),  INT8_C(  33),  INT8_C(  70),
       INT8_C(  89), -INT8_C(  88),  INT8_C(  60),  INT8_C(  73),  INT8_C( 114), -INT8_C(  11), -INT8_C( 117),  INT8_C(  49),
       INT8_C(   7),  INT8_C(  72),  INT8_C(  72), -INT8_C(  19), -INT8_C(  54),  INT8_C(  77),  INT8_C(  88),  INT8_C( 121),
       INT8_C(  43),  INT8_C( 125), -INT8_C(  52), -INT8_C(  65), -INT8_C(  69),  INT8_C(  32),  INT8_C(  46), -INT8_C(  49),
      -INT8_C(  25),  INT8_C(  35), -INT8_C( 127), -INT8_C(  60),  INT8_C( 100), -INT8_C(  94),  INT8_C(  10), -INT8_C(  67),
       INT8_C(  75),  INT8_C(  70),  INT8_C(   6), -INT8_C(  67),  INT8_C(  60), -INT8_C( 110), -INT8_C(  18),  INT8_C(  67),
      -INT8_C(  38),  INT8_C(  54),  INT8_C(  48), -INT8_C(  92), -INT8_C( 124), -INT8_C( 120),  INT8_C(  29), -INT8_C(  81),
       INT8_C(   6), -INT8_C(  23),  INT8_C( 110), -INT8_C(  63),  INT8_C(  10), -INT8_C( 100), -INT8_C( 112), -INT8_C(  15),
      -INT8_C(  65),  INT8_C(  17), -INT8_C(  75),  INT8_C(  35), -INT8_C(  76), -INT8_C(  65), -INT8_C(  31), -INT8_C(   1),
       INT8_C(   5), -INT8_C(  25), -INT8_C(  68),  INT8_C(  65),  INT8_C( 121), -INT8_C(  86), -INT8_C( 124),  INT8_C(  84),
      -INT8_C(  31), -INT8_C(  75), -INT8_C(   8),  INT8_C( 101),  INT8_C(  61),  INT8_C(  22),  INT8_C(  20),  INT8_C(  67) };
  static const int8_t b[] =
    { -INT8_C(   1), -INT8_C( 126),  INT8_C(   4),  INT8_C(   9),  INT8_C(  30), -INT8_C( 107), -INT8_C(   6), -INT8_C(  34),
      -INT8_C(  90), -INT8_C(  81),  INT8_C(   1),  INT8_C(  90),  INT8_C( 110), -INT8_C(  30),  INT8_C(  89),  INT8_C( 116),
      -INT8_C(  54),  INT8_C(  21), -INT8_C(  75),  INT8_C(  67), -INT8_C(  64),  INT8_C(  58), -INT8_C( 105), -INT8_C(  95),
      -INT8_C(  17), -INT8_C( 112),  INT8_C(   6),  INT8_C(  44), -INT8_C(  90),  INT8_C(  26),  INT8_C( 112), -INT8_C(  91),
      -INT8_C( 100),  INT8_C( 116), -INT8_C(  81), -INT8_C(  70),  INT8_C(   9), -INT8_C(  87), -INT8_C( 104), -INT8_C(  80),
       INT8_C(  89), -INT8_C( 102),  INT8_C(  10), -INT8_C(  57),  INT8_C( 124),  INT8_C( 100),  INT8_C(  59),  INT8_C(  70),
       INT8_C( 121), -INT8_C(  15), -INT8_C( 118),  INT8_C(  57),  INT8_C(  43),  INT8_C(  33), -INT8_C(  38),  INT8_C(  26),
      -INT8_C(  79), -INT8_C(  32),  INT8_C(  70),  INT8_C(  87), -INT8_C(   6), -INT8_C(  74), -INT8_C(   3), -INT8_C( 106),
       INT8_C(  43), -INT8_C(  84),  INT8_C(  81),  INT8_C(  52),  INT8_C(  85), -INT8_C(  23), -INT8_C(  28), -INT8_C(  82),
      -INT8_C( 125), -INT8_C(  17),  INT8_C( 118),  INT8_C(   0),  INT8_C(  83), -INT8_C(  79),  INT8_C(  70), -INT8_C(  52),
      -INT8_C(  94), -INT8_C(  48),  INT8_C(   6), -INT8_C(  51), -INT8_C(  14), -INT8_C(  32), -INT8_C(  25), -INT8_C(  93),
      -INT8_C(  63),  INT8_C(  46), -INT8_C(   5), -INT8_C(  69), -INT8_C(  28), -INT8_C(   8),  INT8_C(  82),  INT8_C(  15),
      -INT8_C(  92), -INT8_C(  93),  INT8_C(  68), -INT8_C(   7), -INT8_C( 116),  INT8_C(  40), -INT8_C(  88),  INT8_C(  16),
       INT8_C(  23),  INT8_C(  30),  INT8_C(  16),  INT8_C( 106), -INT8_C(  49),  INT8_C(  86),  INT8_C(  55),  INT8_C( 114),
       INT8_C(  39),  INT8_C(  61),  INT8_C(  63),  INT8_C(  25),  INT8_C(  29),  INT8_C(  39), -INT8_C(  68), -INT8_C(  34),
       INT8_C(  85), -INT8_C(  73), -INT8_C( 102),  INT8_C(  57), -INT8_C(  81), -INT8_C(  20),  INT8_C(  73),  INT8_C(  83),
      -INT8_C( 113), -INT8_C( 115),  INT8_C(  77),  INT8_C(  27), -INT8_C(  75), -INT8_C(  11),  INT8_C(  43), -INT8_C(  51),
       INT8_C(  19),  INT8_C(  59),  INT8_C(  55), -INT8_C(  30), -INT8_C( 110),  INT8_C( 110),  INT8_C(  84), -INT8_C(  71),
      -INT8_C(  85), -INT8_C( 108), -INT8_C(  46), -INT8_C(  55), -INT8_C(  69), -INT8_C( 114), -INT8_C(  89),  INT8_C(  16),
       INT8_C(  70),  INT8_C(  65),  INT8_C(  73), -INT8_C(  11),  INT8_C(  45), -INT8_C( 110),  INT8_C(  73), -INT8_C(  68),
       INT8_C(  31), -INT8_C( 106), -INT8_C(  40), -INT8_C(  43), -INT8_C( 117),  INT8_C(   3), -INT8_C(  94), -INT8_C(  98),
       INT8_C(  63), -INT8_C(  39),      INT8_MIN, -INT8_C(  47),  INT8_C(  72), -INT8_C(  43), -INT8_C( 118), -INT8_C(  13),
       INT8_C( 105),  INT8_C(  92), -INT8_C(  68),  INT8_C(  36), -INT8_C(  22),  INT8_C( 100),  INT8_C(  52),  INT8_C(  48),
      -INT8_C(  91),  INT8_C( 125),  INT8_C(  38), -INT8_C(  45),  INT8_C(  16),  INT8_C( 111), -INT8_C( 113),  INT8_C(  47),
       INT8_C(   5),  INT8_C( 103),  INT8_C(   4), -INT8_C( 112),  INT8_C( 107), -INT8_C(  90),  INT8_C(  46), -INT8_C(  86),
           INT8_MIN, -INT8_C(  82),  INT8_C( 123), -INT8_C(  56), -INT8_C( 125),  INT8_C(   5), -INT8_C(  69), -INT8_C(  20),
       INT8_C(  97),  INT8_C( 120),  INT8_C(  16),  INT8_C(  75), -INT8_C(  36),  INT8_C(  68),  INT8_C( 124), -INT8_C( 127),
      -INT8_C(  62), -INT8_C(  94),  INT8_C(  84), -INT8_C(  46),  INT8_C(  17), -INT8_C(  28),  INT8_C(   1),  INT8_C(  22),
       INT8_C(  75),  INT8_C(   6), -INT8_C(  90), -INT8_C(  74), -INT8_C(  84), -INT8_C(  44),  INT8_C(  96),  INT8_C(  44),
      -INT8_C( 126), -INT8_C(  37), -INT8_C(  12),  INT8_C(   6), -INT8_C(  32), -INT8_C(  80), -INT8_C(  14),  INT8_C(  65),
       INT8_C(  40),  INT8_C(   3), -INT8_C( 115),  INT8_C(   4),  INT8_C(  71),  INT8_C(   9), -INT8_C( 123),  INT8_C(   9),
      -INT8_C(  85), -INT8_C(  38), -INT8_C(  37), -INT8_C(  68), -INT8_C(  66), -INT8_C(  35), -INT8_C(  46),  INT8_C(   9),
      -INT8_C(  29),  INT8_C( 120), -INT8_C(  64), -INT8_C( 113),  INT8_C(  76),  INT8_C(  32), -INT8_C(  68), -INT8_C(  50),
      -INT8_C(   4), -INT8_C(  80), -INT8_C(  44), -INT8_C(  36),  INT8_C(  96), -INT8_C(  57),  INT8_C(  30), -INT8_C( 120),
      -INT8_C(  54), -INT8_C(  85), -INT8_C( 116),  INT8_C(  17), -INT8_C(  76),  INT8_C(  18),  INT8_C(  27),  INT8_C(  95),
      -INT8_C(  20), -INT8_C(  10),  INT8_C(  27), -INT8_C(  86), -INT8_C(  45), -INT8_C(  19), -INT8_C(  77), -INT8_C(  74),
       INT8_C( 101),  INT8_C( 115),  INT8_C(  70), -INT8_C(  79), -INT8_C( 108),  INT8_C(   2),      INT8_MAX, -INT8_C( 112),
      -INT8_C(  78),  INT8_C(  84),  INT8_C( 108),  INT8_C(  19),  INT8_C(  27), -INT8_C( 118), -INT8_C( 101), -INT8_C(  27),
       INT8_C(  53),  INT8_C(  40), -INT8_C(  10), -INT8_C(  23),  INT8_C(  58),  INT8_C(  17),  INT8_C(  72),  INT8_C(  38),
       INT8_C(   8),  INT8_C(  99), -INT8_C(  48), -INT8_C(  37),  INT8_C(  80), -INT8_C( 125), -INT8_C( 110), -INT8_C(  75),
      -INT8_C(   9), -INT8_C(  40),  INT8_C( 102), -INT8_C( 117), -INT8_C(  38), -INT8_C(  26),  INT8_C(  27), -INT8_C( 116),
       INT8_C(  58), -INT8_C( 121), -INT8_C(  97),  INT8_C(  85),  INT8_C(  18),  INT8_C(  59),  INT8_C(  58),  INT8_C(  71),
       INT8_C(  99),  INT8_C(  48),  INT8_C(  49), -INT8_C(  99),  INT8_C(  66),  INT8_C( 121), -INT8_C(  61),  INT8_C(  74),
      -INT8_C(  35), -INT8_C( 109),  INT8_C(  37),  INT8_C(  45),  INT8_C(  22), -INT8_C(  73), -INT8_C(  29),  INT8_C(  13),
      -INT8_C( 113),  INT8_C(  73), -INT8_C( 104),  INT8_C( 105),  INT8_C(  47), -INT8_C(  77), -INT8_C(  10),  INT8_C( 105),
       INT8_C(  59), -INT8_C( 107), -INT8_C(  66),  INT8_C(  77), -INT8_C(  48), -INT8_C(   8), -INT8_C( 108),  INT8_C(  51),
       INT8_C(  41), -INT8_C(  59), -INT8_C(  48),  INT8_C( 107),  INT8_C(  63), -INT8_C( 109), -INT8_C(  75),  INT8_C(  28),
       INT8_C(  38), -INT8_C(  38),  INT8_C(  73),  INT8_C(  61), -INT8_C( 110),  INT8_C(  44),  INT8_C(  74),  INT8_C(  33),
       INT8_C( 118), -INT8_C(  29), -INT8_C( 117), -INT8_C(  91), -INT8_C( 106), -INT8_C( 127),  INT8_C(  15), -INT8_C(  47),
       INT8_C(  22), -INT8_C(  51),  INT8_C(  30), -INT8_C(  25), -INT8_C(  58), -INT8_C(  77),  INT8_C(  26), -INT8_C(  17),
       INT8_C( 120), -INT8_C(  21),  INT8_C(  90), -INT8_C(  73),  INT8_C( 126),  INT8_C(  15), -INT8_C(  45), -INT8_C(  91) };
  static const int8_t e[] =
    {  INT8_C(  72), -INT8_C(  84), -INT8_C(  69),  INT8_C(  28), -INT8_C(  68),  INT8_C(  53), -INT8_C( 104),  INT8_C(  15),
      -INT8_C(  48),  INT8_C(  94),  INT8_C( 112),  INT8_C(  87), -INT8_C(  63),  INT8_C( 109),  INT8_C( 113),  INT8_C( 125),
       INT8_C(  20), -INT8_C(  49), -INT8_C(  31), -INT8_C(  34),  INT8_C(  84), -INT8_C(  60), -INT8_C(  48),  INT8_C(  72),
       INT8_C(  29),  INT8_C(  77),  INT8_C(   6),  INT8_C(  64),  INT8_C( 122), -INT8_C(  24), -INT8_C(  47), -INT8_C(  62),
       INT8_C(  22),  INT8_C(  28), -INT8_C( 115), -INT8_C(  46),  INT8_C(  81),  INT8_C( 124),  INT8_C(  73), -INT8_C(  46),
       INT8_C(  51),  INT8_C(  83), -INT8_C( 125),  INT8_C(  99), -INT8_C(  64),  INT8_C(  78),  INT8_C(  25), -INT8_C(  98),
      -INT8_C(  70),  INT8_C(  54),  INT8_C( 125),  INT8_C(  14),  INT8_C(   9),  INT8_C(  77), -INT8_C(  75),  INT8_C(  81),
      -INT8_C( 102), -INT8_C(  74),  INT8_C( 120), -INT8_C(  70),  INT8_C( 126), -INT8_C(  39),  INT8_C(  37), -INT8_C( 107),
      -INT8_C(  11),  INT8_C(   3),  INT8_C(  23),  INT8_C( 123),      INT8_MIN,  INT8_C(  74),  INT8_C(  77),  INT8_C(  90),
       INT8_C(  26), -INT8_C(  30),  INT8_C( 108),  INT8_C(  95), -INT8_C(  52),  INT8_C(  15), -INT8_C(   3), -INT8_C( 122),
       INT8_C(  85),  INT8_C( 123), -INT8_C( 102),  INT8_C(  94), -INT8_C(  55),  INT8_C(  74), -INT8_C( 106), -INT8_C(  63),
      -INT8_C(  63),  INT8_C(  14),  INT8_C(  36), -INT8_C( 124), -INT8_C(  53),  INT8_C(  66), -INT8_C( 125), -INT8_C(  21),
      -INT8_C(  15), -INT8_C( 101),  INT8_C( 103), -INT8_C(  51), -INT8_C(   4), -INT8_C( 116),  INT8_C(  40),  INT8_C(  22),
      -INT8_C( 123),  INT8_C(  30),  INT8_C( 117),  INT8_C(  59),  INT8_C(  46), -INT8_C( 125), -INT8_C(   8), -INT8_C(  11),
      -INT8_C(   1),  INT8_C(  86),  INT8_C(  32), -INT8_C(  81), -INT8_C(  67), -INT8_C(  98),  INT8_C(  44), -INT8_C(  96),
      -INT8_C( 123),  INT8_C(  76), -INT8_C(  66), -INT8_C(  91), -INT8_C(  33), -INT8_C( 108), -INT8_C( 110),  INT8_C(  44),
       INT8_C(  67), -INT8_C(   7), -INT8_C(   6),  INT8_C(  63), -INT8_C(  82),  INT8_C(  34),      INT8_MIN,  INT8_C(  52),
       INT8_C(  83),  INT8_C(   6), -INT8_C(  39),  INT8_C( 110), -INT8_C( 118),  INT8_C( 100),  INT8_C(  69), -INT8_C(  48),
       INT8_C( 101), -INT8_C(  45),  INT8_C(  81),  INT8_C(  90),  INT8_C(  74), -INT8_C(  16), -INT8_C(  95), -INT8_C(  32),
      -INT8_C(  53),  INT8_C(  30),  INT8_C(  60),  INT8_C( 100), -INT8_C(  58), -INT8_C( 123), -INT8_C( 112),  INT8_C(   9),
       INT8_C(  17),  INT8_C(  32),  INT8_C(  32), -INT8_C(  64), -INT8_C(  84), -INT8_C(  98),  INT8_C(  82), -INT8_C( 117),
       INT8_C( 105), -INT8_C(  11), -INT8_C(  37),  INT8_C(  50),  INT8_C(  89),  INT8_C(  77),  INT8_C(  49),  INT8_C(  19),
      -INT8_C( 119), -INT8_C(  80),  INT8_C(  41),  INT8_C( 106), -INT8_C(  96),  INT8_C( 103),  INT8_C( 110),  INT8_C(  37),
       INT8_C(  42),  INT8_C( 119), -INT8_C( 119),  INT8_C(  31), -INT8_C(   4), -INT8_C( 119),  INT8_C(  85), -INT8_C(  18),
      -INT8_C(  87),  INT8_C(   5), -INT8_C(  35), -INT8_C(  31),  INT8_C(  60),  INT8_C(  44),  INT8_C(  62),  INT8_C(  79),
       INT8_C(  33), -INT8_C( 103), -INT8_C( 127),  INT8_C(  66),  INT8_C( 105),  INT8_C(  60),  INT8_C(  72), -INT8_C(  14),
      -INT8_C(  25), -INT8_C(   6), -INT8_C( 127), -INT8_C( 120),  INT8_C(  61), -INT8_C(  17), -INT8_C(  83), -INT8_C(  26),
      -INT8_C(  28), -INT8_C(  39),  INT8_C(  50), -INT8_C(  15),  INT8_C(  98), -INT8_C( 120),  INT8_C(  13), -INT8_C(  11),
       INT8_C(  38), -INT8_C(  19), -INT8_C(  20),  INT8_C(  24), -INT8_C(  65), -INT8_C( 124),  INT8_C(   7),  INT8_C(  52),
       INT8_C(  30), -INT8_C(  24), -INT8_C(  94),  INT8_C(   4),  INT8_C(  36), -INT8_C(  21), -INT8_C(   3),  INT8_C( 108),
       INT8_C(  53),  INT8_C( 124), -INT8_C(  77), -INT8_C( 102),  INT8_C( 110),  INT8_C(  97),  INT8_C( 124),  INT8_C(  83),
      -INT8_C( 104), -INT8_C(  81),  INT8_C(  68), -INT8_C(  91), -INT8_C(  11),  INT8_C(  83), -INT8_C(  34),  INT8_C( 102),
       INT8_C(  93), -INT8_C(  99),      INT8_MAX,  INT8_C( 112), -INT8_C(  87), -INT8_C(  26),  INT8_C(  96), -INT8_C( 107),
      -INT8_C(  49),  INT8_C(   2), -INT8_C(  96),  INT8_C(  23), -INT8_C( 115), -INT8_C(  41),  INT8_C(  66),  INT8_C(  74),
       INT8_C(  29), -INT8_C(  10),  INT8_C(  88), -INT8_C( 117),  INT8_C(  11), -INT8_C(  25), -INT8_C(  60),  INT8_C(  78),
       INT8_C( 112),  INT8_C(  35), -INT8_C(  13),  INT8_C( 101), -INT8_C(  92), -INT8_C(  93), -INT8_C(  53), -INT8_C(  73),
       INT8_C(  64), -INT8_C(  41),  INT8_C( 114),  INT8_C(  54),  INT8_C(  49),  INT8_C(  22),  INT8_C(  76),  INT8_C(   0),
       INT8_C(  27),  INT8_C(  24), -INT8_C(  13), -INT8_C(  10), -INT8_C(  17), -INT8_C(  55),  INT8_C(  84),  INT8_C(  39),
      -INT8_C(  65),  INT8_C(  17), -INT8_C(  77), -INT8_C(   1),  INT8_C(  32), -INT8_C( 110),  INT8_C(  77), -INT8_C( 112),
      -INT8_C(  73), -INT8_C(  35), -INT8_C(  11),  INT8_C(  46), -INT8_C(  28),  INT8_C(  61), -INT8_C(  26),  INT8_C(  36),
       INT8_C(  20), -INT8_C(  58),  INT8_C(  90), -INT8_C(  79), -INT8_C(  73),  INT8_C(  65),  INT8_C(  60),  INT8_C(  70),
       INT8_C(  89),  INT8_C(  47), -INT8_C(  37), -INT8_C(  98), -INT8_C( 124),  INT8_C(  48), -INT8_C(  59),  INT8_C( 120),
       INT8_C( 106),  INT8_C(  72),  INT8_C( 121), -INT8_C( 118),  INT8_C(  12),  INT8_C(  77),  INT8_C(  27),  INT8_C( 121),
       INT8_C(  43),  INT8_C( 125), -INT8_C(  52), -INT8_C(  65), -INT8_C(  47),  INT8_C(  32),  INT8_C(  46), -INT8_C(  36),
       INT8_C( 118),  INT8_C( 108), -INT8_C( 127), -INT8_C(  60), -INT8_C( 109),  INT8_C(  85),  INT8_C(   0),  INT8_C(  38),
      -INT8_C( 122),  INT8_C(  70),  INT8_C(   6), -INT8_C(  67),  INT8_C(  12), -INT8_C( 118), -INT8_C(  18),  INT8_C( 118),
      -INT8_C(  38), -INT8_C(   5),  INT8_C(   0),  INT8_C(  15), -INT8_C( 124),  INT8_C(  27),  INT8_C(  29), -INT8_C(  81),
       INT8_C(   6), -INT8_C(  61), -INT8_C(  73), -INT8_C(   2), -INT8_C( 100), -INT8_C(  56), -INT8_C( 112),  INT8_C(  18),
       INT8_C(  53), -INT8_C(  12),  INT8_C(  64),  INT8_C(  35),  INT8_C(  74), -INT8_C(  65), -INT8_C(  31), -INT8_C(   1),
       INT8_C(  27), -INT8_C(  76), -INT8_C(  68),  INT8_C(  40),  INT8_C(  63),  INT8_C(  93), -INT8_C(  98),  INT8_C(  67),
      -INT8_C(  31), -INT8_C(  75),  INT8_C(  82),  INT8_C( 101),  INT8_C(  61),  INT8_C(  37), -INT8_C(  25),  INT8_C(  67) };

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
    rv = simde_svadd_s8_m(pv, av, bv);

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

    ev = simde_svadd_s8_m(pv, av, bv);

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
test_simde_svadd_s16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) };
  static const int16_t a[] =
    { -INT16_C( 31580),  INT16_C( 24215), -INT16_C( 10959), -INT16_C( 22132), -INT16_C( 28644), -INT16_C( 21663),  INT16_C( 20835),  INT16_C( 13027),
       INT16_C( 30607), -INT16_C( 14574), -INT16_C( 24402), -INT16_C( 30042), -INT16_C( 27230), -INT16_C(  6845),  INT16_C( 25664), -INT16_C(  7041),
       INT16_C(  6121),  INT16_C(  6722), -INT16_C( 12564),  INT16_C(  2243),  INT16_C(  9567), -INT16_C( 15693), -INT16_C( 26762),  INT16_C(  1524),
       INT16_C(  1806), -INT16_C( 17204),  INT16_C( 29351),  INT16_C( 19014), -INT16_C( 30456),  INT16_C( 18479), -INT16_C( 20754), -INT16_C( 10452),
       INT16_C( 28613), -INT16_C( 19983), -INT16_C( 19395), -INT16_C( 25414),  INT16_C( 28121),  INT16_C( 20319),  INT16_C( 21252),  INT16_C(  4693),
       INT16_C(  8538),  INT16_C(   718),  INT16_C(  5268), -INT16_C( 25524),  INT16_C( 31646), -INT16_C( 29468),  INT16_C(  4137), -INT16_C(  4253),
       INT16_C( 21631), -INT16_C( 16992),  INT16_C( 23048), -INT16_C(  7591), -INT16_C( 18232), -INT16_C( 13263), -INT16_C( 31220),  INT16_C( 26335),
      -INT16_C( 21080),  INT16_C( 15464), -INT16_C( 19262),  INT16_C( 24792), -INT16_C( 17361),  INT16_C( 23020),  INT16_C( 20428),  INT16_C( 19528),
      -INT16_C(  5981), -INT16_C( 21751),  INT16_C( 25155),  INT16_C(  2957), -INT16_C( 16613),  INT16_C( 10199), -INT16_C( 18875), -INT16_C(  4723),
      -INT16_C(  2460),  INT16_C(  9769),  INT16_C(   426), -INT16_C(  9594),  INT16_C( 29373), -INT16_C( 30157),  INT16_C( 31681),  INT16_C( 25814),
      -INT16_C(  8349), -INT16_C( 23025), -INT16_C( 25279),  INT16_C( 23729), -INT16_C( 30372), -INT16_C( 24189),  INT16_C(  4415), -INT16_C( 23665),
      -INT16_C( 18425), -INT16_C( 20023),  INT16_C( 20410),  INT16_C( 30603), -INT16_C( 16703), -INT16_C( 32255), -INT16_C( 10439), -INT16_C( 25114),
      -INT16_C(  2378), -INT16_C(  1981), -INT16_C(  2669), -INT16_C(  4268), -INT16_C( 10114), -INT16_C( 17008),  INT16_C(  8169), -INT16_C(  3999),
       INT16_C( 10968), -INT16_C( 27999),  INT16_C( 11642),  INT16_C( 15113),  INT16_C(  3051),  INT16_C(  9662), -INT16_C( 23326), -INT16_C( 26174),
       INT16_C(  1434),  INT16_C( 11665), -INT16_C(  6662),  INT16_C( 30748), -INT16_C( 21059), -INT16_C( 22986), -INT16_C( 26676), -INT16_C( 23402),
       INT16_C( 14529),  INT16_C( 15158),  INT16_C( 16485),  INT16_C( 20599),  INT16_C( 13643),  INT16_C( 11637),  INT16_C( 14297),  INT16_C( 29894),
       INT16_C( 22333),  INT16_C( 14241), -INT16_C( 16835), -INT16_C(  1360), -INT16_C(  6549),  INT16_C( 14241),  INT16_C( 14205),  INT16_C( 16092),
       INT16_C(  4719), -INT16_C( 11142), -INT16_C(  3758), -INT16_C( 25307), -INT16_C( 26074), -INT16_C(    53), -INT16_C( 28206),  INT16_C(  3955),
       INT16_C(  5609),  INT16_C(  9798), -INT16_C(  2349),  INT16_C( 15904) };
  static const int16_t b[] =
    { -INT16_C( 15908),  INT16_C( 22901),  INT16_C( 20985),  INT16_C( 26776),  INT16_C(  4708), -INT16_C( 18883),  INT16_C( 25091),  INT16_C( 10580),
       INT16_C(  8188), -INT16_C( 12760), -INT16_C( 25424), -INT16_C( 26147),  INT16_C(  9393), -INT16_C( 31553), -INT16_C(  8166), -INT16_C(  2110),
       INT16_C( 14241), -INT16_C( 26032), -INT16_C(  6007), -INT16_C(  4861),  INT16_C( 16634), -INT16_C(   605), -INT16_C(  2142), -INT16_C( 25050),
       INT16_C( 20246), -INT16_C( 14483),  INT16_C( 19179), -INT16_C( 25504),  INT16_C(  8302), -INT16_C( 30432), -INT16_C(  7680), -INT16_C( 24192),
      -INT16_C( 12263), -INT16_C( 24004),  INT16_C( 16313), -INT16_C( 19569),  INT16_C( 13183),  INT16_C(  8625), -INT16_C( 10454),  INT16_C( 16831),
       INT16_C( 11302),  INT16_C(  4360),  INT16_C( 26743), -INT16_C(  6739), -INT16_C( 12920), -INT16_C( 30610), -INT16_C(  4433), -INT16_C( 14038),
       INT16_C( 26303),  INT16_C( 30827), -INT16_C(  1115),  INT16_C(  9259), -INT16_C(  9170),  INT16_C( 22597),  INT16_C(  1204), -INT16_C(  9575),
      -INT16_C( 24271), -INT16_C( 22292), -INT16_C( 26358), -INT16_C( 28019), -INT16_C(   921),  INT16_C(  5659),  INT16_C( 17898), -INT16_C( 22049),
       INT16_C( 19371),  INT16_C( 20513),  INT16_C( 19782),  INT16_C( 29812), -INT16_C( 18135), -INT16_C(  8756),  INT16_C( 26301), -INT16_C(  4424),
      -INT16_C( 23545),  INT16_C(  4502),  INT16_C(  9277), -INT16_C( 23388), -INT16_C( 16608),  INT16_C(  2747), -INT16_C( 26108), -INT16_C( 20556),
      -INT16_C( 10779),  INT16_C( 11263),  INT16_C( 29474),  INT16_C( 19615),  INT16_C( 27692), -INT16_C(  5847), -INT16_C(  7726), -INT16_C(  9768),
       INT16_C( 28293), -INT16_C( 15381), -INT16_C( 28782), -INT16_C( 19865),  INT16_C(  8782),  INT16_C( 21181),  INT16_C( 29117), -INT16_C( 24063),
       INT16_C(    70),  INT16_C( 27086),  INT16_C( 28019), -INT16_C( 24651), -INT16_C(  8487), -INT16_C( 21624),  INT16_C( 24768),  INT16_C( 17797),
       INT16_C( 28879),  INT16_C( 24840),  INT16_C( 28927),  INT16_C( 19732), -INT16_C( 11886),  INT16_C( 20383), -INT16_C( 24510), -INT16_C( 30478),
      -INT16_C( 16224),  INT16_C(  5105), -INT16_C( 22995),  INT16_C(  1970),  INT16_C( 14981),  INT16_C( 17842),  INT16_C( 14235),  INT16_C( 27274),
      -INT16_C( 27737), -INT16_C( 22837), -INT16_C(  8445), -INT16_C( 27149), -INT16_C( 27984), -INT16_C(  3355), -INT16_C( 10446), -INT16_C( 11653),
       INT16_C( 27799), -INT16_C( 15131), -INT16_C( 26861), -INT16_C( 26421),  INT16_C( 32466),  INT16_C( 28125),  INT16_C( 26549),  INT16_C( 24023),
      -INT16_C( 23814), -INT16_C(   765), -INT16_C(  2174),  INT16_C( 12947),  INT16_C( 30857), -INT16_C( 17371), -INT16_C( 24497), -INT16_C(  6514),
       INT16_C( 29708),  INT16_C(  8106),  INT16_C( 30219), -INT16_C(  8777) };
  static const int16_t e[] =
    {  INT16_C(     0),  INT16_C(     0),  INT16_C( 10026),  INT16_C(     0), -INT16_C( 23936),  INT16_C(     0), -INT16_C( 19610),  INT16_C(     0),
      -INT16_C( 26741),  INT16_C(     0),  INT16_C( 15710),  INT16_C(  9347),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C( 20362),  INT16_C(     0), -INT16_C( 18571), -INT16_C(  2618),  INT16_C( 26201), -INT16_C( 16298),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C( 17006), -INT16_C(  6490), -INT16_C( 22154),  INT16_C(     0), -INT16_C( 28434),  INT16_C(     0),
       INT16_C( 16350),  INT16_C( 21549),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 10798),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C( 32011), -INT16_C( 32263),  INT16_C( 18726),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C( 13835),  INT16_C(     0),  INT16_C(     0), -INT16_C( 27402),  INT16_C(  9334),  INT16_C(     0),  INT16_C(     0),
       INT16_C( 20185), -INT16_C(  6828),  INT16_C( 19916),  INT16_C(     0),  INT16_C(     0),  INT16_C( 28679), -INT16_C( 27210),  INT16_C(     0),
       INT16_C( 13390), -INT16_C(  1238), -INT16_C( 20599),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1443),  INT16_C(  7426), -INT16_C(  9147),
      -INT16_C( 26005),  INT16_C(     0),  INT16_C(     0),  INT16_C( 32554),  INT16_C( 12765), -INT16_C( 27410),  INT16_C(  5573),  INT16_C(  5258),
       INT16_C(     0),  INT16_C(     0),  INT16_C(  4195),  INT16_C(     0), -INT16_C(  2680),  INT16_C(     0),  INT16_C(     0),  INT16_C( 32103),
       INT16_C(     0),  INT16_C(     0), -INT16_C(  8372),  INT16_C(     0), -INT16_C(  7921),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16359),
      -INT16_C(  2308),  INT16_C( 25105),  INT16_C( 25350),  INT16_C(     0),  INT16_C(     0),  INT16_C( 26904), -INT16_C( 32599),  INT16_C(     0),
      -INT16_C( 25689), -INT16_C(  3159),  INT16_C(     0), -INT16_C( 30691),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 14790),  INT16_C( 16770),  INT16_C(     0),  INT16_C( 32718),  INT16_C(     0), -INT16_C(  5144), -INT16_C( 12441),  INT16_C(     0),
      -INT16_C( 13208), -INT16_C(  7679),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14341),  INT16_C(     0),  INT16_C(  3851),  INT16_C( 18241),
      -INT16_C( 15404),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 25917), -INT16_C( 23170), -INT16_C( 24782),  INT16_C(     0),
       INT16_C(     0), -INT16_C( 11907), -INT16_C(  5932),  INT16_C(     0),  INT16_C(     0), -INT16_C( 17424),  INT16_C(     0), -INT16_C(  2559),
       INT16_C(     0),  INT16_C( 17904),  INT16_C( 27870),  INT16_C(  7127) };

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
    rv = simde_svadd_s16_z(pv, av, bv);

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

    ev = simde_svadd_s16_z(pv, av, bv);

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
test_simde_svadd_s16_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) };
  static const int16_t a[] =
    {  INT16_C( 15418), -INT16_C( 17753), -INT16_C(  8529),  INT16_C( 24079), -INT16_C( 18828),  INT16_C( 26549),  INT16_C( 31424), -INT16_C( 22891),
       INT16_C( 29588), -INT16_C( 30473), -INT16_C( 10645), -INT16_C( 28187),  INT16_C(  9426),  INT16_C( 31813), -INT16_C(  3085),  INT16_C( 11582),
      -INT16_C(  6609), -INT16_C(  8473), -INT16_C(  2364),  INT16_C( 14396), -INT16_C(  3412),  INT16_C( 27807),  INT16_C( 13420),  INT16_C(    19),
       INT16_C(  2727),  INT16_C(  4744),  INT16_C( 28129), -INT16_C( 19548), -INT16_C(  5742), -INT16_C( 31441),  INT16_C( 28124),  INT16_C(  2994),
      -INT16_C( 26029),  INT16_C(  6377),  INT16_C(  9872),  INT16_C( 15696), -INT16_C(  4072), -INT16_C( 31575), -INT16_C( 17372), -INT16_C( 13180),
       INT16_C(  3527), -INT16_C( 22306), -INT16_C( 32134),  INT16_C(  3163), -INT16_C( 30100),  INT16_C( 18577),  INT16_C( 17655),  INT16_C( 19284),
       INT16_C( 15838),  INT16_C( 28259), -INT16_C( 19613),  INT16_C( 31659),  INT16_C( 21923), -INT16_C( 14081), -INT16_C( 31727), -INT16_C( 10092),
       INT16_C( 29329),  INT16_C(  2944), -INT16_C(  9227),  INT16_C( 24856), -INT16_C( 22171),  INT16_C( 23977), -INT16_C(   531), -INT16_C( 13400),
       INT16_C(  2875), -INT16_C( 25030), -INT16_C(  6722),  INT16_C( 25114),  INT16_C(  6458),  INT16_C( 19498), -INT16_C( 16739),  INT16_C( 11812),
      -INT16_C( 23248),  INT16_C(  9530),  INT16_C( 21120), -INT16_C(  6522),  INT16_C( 12539), -INT16_C(  5821), -INT16_C(  5331),  INT16_C( 26804),
      -INT16_C(  4362), -INT16_C( 19449),  INT16_C(  8660),  INT16_C(  3606),  INT16_C( 16442), -INT16_C( 10150),  INT16_C( 32766),  INT16_C( 12038),
       INT16_C( 16420), -INT16_C( 23468), -INT16_C(  9326), -INT16_C( 29046), -INT16_C( 13045),  INT16_C( 14455),  INT16_C( 11192), -INT16_C( 20831),
      -INT16_C( 22502), -INT16_C(  4509),  INT16_C( 31177),  INT16_C(  1020),  INT16_C( 22458), -INT16_C( 18213), -INT16_C(  7466), -INT16_C(  1305),
       INT16_C( 15394), -INT16_C( 19042),  INT16_C( 10519),  INT16_C(  8771), -INT16_C( 17674), -INT16_C( 20646), -INT16_C(  1051), -INT16_C(   163),
      -INT16_C( 16221),  INT16_C( 27885), -INT16_C(  5574), -INT16_C(  2960),  INT16_C( 19265),  INT16_C(  6060), -INT16_C( 27603),  INT16_C( 20497),
      -INT16_C( 20528), -INT16_C(  6395),  INT16_C( 18648), -INT16_C( 12535),  INT16_C( 25346), -INT16_C(  6274), -INT16_C(  9377),  INT16_C(   743),
      -INT16_C( 11108), -INT16_C( 10641), -INT16_C(  8258), -INT16_C(    54),  INT16_C( 30250),  INT16_C( 22550),  INT16_C(  9994), -INT16_C(  9560),
      -INT16_C( 21033), -INT16_C( 20543), -INT16_C( 13579), -INT16_C(  2178), -INT16_C(   978), -INT16_C( 29218), -INT16_C( 14888),  INT16_C( 29839),
      -INT16_C(   358),  INT16_C( 22602),  INT16_C(  5341),  INT16_C(  2136),  INT16_C( 28298), -INT16_C( 27296),  INT16_C(  2198),  INT16_C( 28015),
       INT16_C( 12725), -INT16_C( 21988), -INT16_C( 25605),  INT16_C( 10657),  INT16_C( 32663),  INT16_C( 28598),  INT16_C( 17989), -INT16_C(  8221),
       INT16_C( 11588),  INT16_C(  8759), -INT16_C( 28863), -INT16_C( 13270), -INT16_C( 29954), -INT16_C( 27551), -INT16_C( 12142),  INT16_C( 18177),
       INT16_C(  7425), -INT16_C(   527), -INT16_C( 27976),  INT16_C( 20518), -INT16_C(  8943),  INT16_C( 22207), -INT16_C( 23773),  INT16_C( 26421),
       INT16_C( 28112),  INT16_C(  4745), -INT16_C( 19460), -INT16_C(  1314),  INT16_C( 16189), -INT16_C( 12402), -INT16_C( 28913),  INT16_C(  4374),
       INT16_C(  1965),  INT16_C( 25870),  INT16_C( 13465), -INT16_C( 21579),  INT16_C( 29969),  INT16_C( 13313),  INT16_C( 14104), -INT16_C(  5988),
       INT16_C(  9636), -INT16_C( 24326), -INT16_C( 10023),  INT16_C(  5787),  INT16_C( 10519),  INT16_C( 10214), -INT16_C(   839),  INT16_C( 26168),
       INT16_C( 17924), -INT16_C( 25141), -INT16_C( 32390), -INT16_C( 29624),  INT16_C( 19190),  INT16_C(  3776),  INT16_C( 23681),  INT16_C(  9718),
      -INT16_C(  3710),  INT16_C( 23493),  INT16_C( 24777), -INT16_C(  7823),  INT16_C( 22410),  INT16_C( 17160),  INT16_C( 16468),  INT16_C( 22697),
       INT16_C( 29830),  INT16_C(   245),  INT16_C( 16117), -INT16_C(  5236),  INT16_C( 19848),  INT16_C(  2553), -INT16_C(  3927),  INT16_C( 11054),
      -INT16_C(  3103), -INT16_C( 21882), -INT16_C(  1964), -INT16_C(  8565), -INT16_C( 27825), -INT16_C( 23775), -INT16_C( 13613),  INT16_C( 23035),
      -INT16_C(  3778),  INT16_C( 13402), -INT16_C(  6609), -INT16_C( 18657),  INT16_C(  6451), -INT16_C(  8768), -INT16_C(  4599), -INT16_C(  5624),
      -INT16_C( 28703),  INT16_C( 13716),  INT16_C(  8327), -INT16_C( 10733) };
  static const int16_t b[] =
    {  INT16_C( 13491), -INT16_C( 30854),  INT16_C( 30206),  INT16_C( 15840),  INT16_C( 14950), -INT16_C( 27279), -INT16_C( 28639),  INT16_C( 21580),
       INT16_C(  3241), -INT16_C( 19919),  INT16_C( 15098), -INT16_C(  9060),  INT16_C( 12745),  INT16_C( 20497),  INT16_C(  9553),  INT16_C(  1062),
      -INT16_C( 24487),  INT16_C( 22667),  INT16_C( 27670),  INT16_C( 31893),  INT16_C(  1702), -INT16_C( 14574),  INT16_C( 24214),  INT16_C( 16412),
       INT16_C( 19819),  INT16_C( 26098), -INT16_C( 28793),  INT16_C( 20545),  INT16_C( 21440),  INT16_C(  4512), -INT16_C( 14472), -INT16_C( 12011),
      -INT16_C( 24217),  INT16_C( 32041), -INT16_C( 16883), -INT16_C( 19462),  INT16_C(  3268),  INT16_C( 23419), -INT16_C( 26774), -INT16_C( 10853),
      -INT16_C( 29212),  INT16_C( 27707),  INT16_C( 31772), -INT16_C(  9028),  INT16_C( 24015),  INT16_C( 18413),  INT16_C(   804), -INT16_C( 29927),
       INT16_C( 17060), -INT16_C( 20215),  INT16_C(   769), -INT16_C( 15004), -INT16_C(  8433),  INT16_C( 31008), -INT16_C( 17546),  INT16_C( 23375),
      -INT16_C( 30135),  INT16_C( 26055), -INT16_C( 31994), -INT16_C( 10686),  INT16_C( 12256),  INT16_C(  1053),  INT16_C( 13874), -INT16_C( 10608),
      -INT16_C( 26247),  INT16_C( 31367), -INT16_C(  4964), -INT16_C( 21697),  INT16_C( 24779),  INT16_C( 16932),  INT16_C( 29467),  INT16_C( 25757),
       INT16_C( 25853),  INT16_C(  1226),  INT16_C(  3303), -INT16_C( 14118), -INT16_C(  2245),  INT16_C( 28364),  INT16_C( 23598), -INT16_C( 22716),
      -INT16_C( 13067), -INT16_C( 28383),  INT16_C( 24760), -INT16_C( 31940),  INT16_C( 25024), -INT16_C(  9019),  INT16_C( 25300), -INT16_C( 11712),
       INT16_C(  2758), -INT16_C( 20778), -INT16_C( 20458),  INT16_C( 21110),  INT16_C( 17063), -INT16_C( 10816),  INT16_C(  1183), -INT16_C( 27524),
      -INT16_C( 25136), -INT16_C( 30682),  INT16_C( 25342), -INT16_C( 16884), -INT16_C( 11837), -INT16_C( 26470), -INT16_C(  9420), -INT16_C(  1430),
       INT16_C( 16613), -INT16_C(   856),  INT16_C(  7920), -INT16_C( 26802),  INT16_C(  3681),  INT16_C(   109), -INT16_C(  5870), -INT16_C(  7276),
      -INT16_C( 17785), -INT16_C( 31381),  INT16_C( 30493), -INT16_C(  8125), -INT16_C(  8631),  INT16_C( 32120), -INT16_C(  7495), -INT16_C( 24969),
       INT16_C(  8226),  INT16_C(  4762), -INT16_C(  6082), -INT16_C( 24662),  INT16_C(  6134),  INT16_C(  2463),  INT16_C( 13312), -INT16_C( 30740),
       INT16_C( 22510),  INT16_C(  2828),  INT16_C( 20687),  INT16_C(  6380),  INT16_C( 25646), -INT16_C(  6251),  INT16_C(  3143),  INT16_C( 27013),
       INT16_C(  8236),  INT16_C( 27516),  INT16_C(  9736), -INT16_C(   246), -INT16_C( 21955),  INT16_C( 15624), -INT16_C(  2850), -INT16_C( 13115),
      -INT16_C( 11957),  INT16_C(  6872), -INT16_C( 15327),  INT16_C( 20274), -INT16_C( 14552),  INT16_C( 28470), -INT16_C( 17196),  INT16_C(   217),
       INT16_C( 21980), -INT16_C(  7061),  INT16_C( 30331), -INT16_C( 18205), -INT16_C(  5344), -INT16_C(   267), -INT16_C( 17697),  INT16_C( 11210),
      -INT16_C( 23924), -INT16_C( 21179),  INT16_C( 30822), -INT16_C( 28675),  INT16_C( 13119),  INT16_C(  5118), -INT16_C( 10257), -INT16_C( 13548),
       INT16_C( 32556), -INT16_C( 22608), -INT16_C( 27659),  INT16_C(  5471),  INT16_C( 21887),  INT16_C( 24083), -INT16_C(  8689), -INT16_C( 25719),
      -INT16_C( 12416), -INT16_C(  6327),  INT16_C( 17991), -INT16_C( 31114),  INT16_C( 29817),  INT16_C( 27034), -INT16_C( 20916),  INT16_C( 30772),
      -INT16_C(  7123),  INT16_C(  8992),  INT16_C( 32632), -INT16_C(  2248),  INT16_C( 19668), -INT16_C(  7083), -INT16_C(  8406), -INT16_C( 21889),
      -INT16_C( 14162), -INT16_C(  2671),  INT16_C(  1806), -INT16_C( 30597),  INT16_C(  5500), -INT16_C( 14095),  INT16_C(  9667), -INT16_C(  3776),
       INT16_C( 24586), -INT16_C( 32236),  INT16_C( 19680), -INT16_C( 19335), -INT16_C( 12648), -INT16_C( 15720),  INT16_C(  6317),  INT16_C( 23405),
      -INT16_C(   288), -INT16_C(  4272), -INT16_C( 13306), -INT16_C( 32137),  INT16_C( 26849), -INT16_C( 23222), -INT16_C( 30067), -INT16_C( 26730),
      -INT16_C( 21781), -INT16_C( 13543), -INT16_C( 27914), -INT16_C( 28801),  INT16_C(  6241),  INT16_C(  3665), -INT16_C( 16848),  INT16_C(  4202),
      -INT16_C( 17731), -INT16_C( 15361),  INT16_C( 30342),  INT16_C( 26693), -INT16_C( 28706),  INT16_C( 27661), -INT16_C( 23783),  INT16_C(  1027),
       INT16_C(  7501),  INT16_C( 17359),  INT16_C( 20399),  INT16_C(  4306),  INT16_C(  9319), -INT16_C( 26849), -INT16_C( 30238), -INT16_C( 24665),
      -INT16_C( 22717), -INT16_C( 13726), -INT16_C( 22755), -INT16_C(   974) };
  static const int16_t e[] =
    {  INT16_C( 28909), -INT16_C( 17753),  INT16_C( 21677),  INT16_C( 24079), -INT16_C( 18828), -INT16_C(   730),  INT16_C(  2785), -INT16_C(  1311),
       INT16_C( 29588),  INT16_C( 15144), -INT16_C( 10645),  INT16_C( 28289),  INT16_C(  9426),  INT16_C( 31813), -INT16_C(  3085),  INT16_C( 11582),
      -INT16_C( 31096),  INT16_C( 14194), -INT16_C(  2364), -INT16_C( 19247), -INT16_C(  3412),  INT16_C( 27807),  INT16_C( 13420),  INT16_C( 16431),
       INT16_C( 22546),  INT16_C( 30842), -INT16_C(   664),  INT16_C(   997),  INT16_C( 15698), -INT16_C( 31441),  INT16_C( 13652),  INT16_C(  2994),
       INT16_C( 15290), -INT16_C( 27118),  INT16_C(  9872), -INT16_C(  3766), -INT16_C(   804), -INT16_C(  8156), -INT16_C( 17372), -INT16_C( 13180),
       INT16_C(  3527),  INT16_C(  5401), -INT16_C( 32134),  INT16_C(  3163), -INT16_C( 30100),  INT16_C( 18577),  INT16_C( 18459), -INT16_C( 10643),
       INT16_C( 15838),  INT16_C( 28259), -INT16_C( 19613),  INT16_C( 16655),  INT16_C( 13490),  INT16_C( 16927),  INT16_C( 16263),  INT16_C( 13283),
      -INT16_C(   806),  INT16_C( 28999),  INT16_C( 24315),  INT16_C( 24856), -INT16_C(  9915),  INT16_C( 25030),  INT16_C( 13343), -INT16_C( 24008),
      -INT16_C( 23372),  INT16_C(  6337), -INT16_C(  6722),  INT16_C(  3417),  INT16_C(  6458),  INT16_C( 19498), -INT16_C( 16739), -INT16_C( 27967),
       INT16_C(  2605),  INT16_C(  9530),  INT16_C( 24423), -INT16_C( 20640),  INT16_C( 10294), -INT16_C(  5821), -INT16_C(  5331),  INT16_C( 26804),
      -INT16_C(  4362),  INT16_C( 17704),  INT16_C(  8660),  INT16_C(  3606),  INT16_C( 16442), -INT16_C( 19169),  INT16_C( 32766),  INT16_C(   326),
       INT16_C( 19178),  INT16_C( 21290), -INT16_C(  9326), -INT16_C(  7936), -INT16_C( 13045),  INT16_C(  3639),  INT16_C( 12375), -INT16_C( 20831),
       INT16_C( 17898),  INT16_C( 30345),  INT16_C( 31177),  INT16_C(  1020),  INT16_C( 10621),  INT16_C( 20853), -INT16_C(  7466), -INT16_C(  2735),
       INT16_C( 15394), -INT16_C( 19898),  INT16_C( 10519),  INT16_C(  8771), -INT16_C( 17674), -INT16_C( 20646), -INT16_C(  6921), -INT16_C(  7439),
      -INT16_C( 16221),  INT16_C( 27885),  INT16_C( 24919), -INT16_C(  2960),  INT16_C( 19265),  INT16_C(  6060), -INT16_C( 27603),  INT16_C( 20497),
      -INT16_C( 20528), -INT16_C(  1633),  INT16_C( 18648),  INT16_C( 28339),  INT16_C( 25346), -INT16_C(  6274),  INT16_C(  3935),  INT16_C(   743),
       INT16_C( 11402), -INT16_C(  7813), -INT16_C(  8258),  INT16_C(  6326),  INT16_C( 30250),  INT16_C( 16299),  INT16_C( 13137), -INT16_C(  9560),
      -INT16_C( 21033), -INT16_C( 20543), -INT16_C( 13579), -INT16_C(  2424), -INT16_C(   978), -INT16_C( 29218), -INT16_C( 14888),  INT16_C( 29839),
      -INT16_C( 12315),  INT16_C( 29474),  INT16_C(  5341),  INT16_C(  2136),  INT16_C( 13746), -INT16_C( 27296),  INT16_C(  2198),  INT16_C( 28015),
       INT16_C( 12725), -INT16_C( 29049),  INT16_C(  4726), -INT16_C(  7548),  INT16_C( 32663),  INT16_C( 28598),  INT16_C(   292),  INT16_C(  2989),
      -INT16_C( 12336), -INT16_C( 12420), -INT16_C( 28863), -INT16_C( 13270), -INT16_C( 16835), -INT16_C( 27551), -INT16_C( 22399),  INT16_C(  4629),
       INT16_C(  7425), -INT16_C( 23135), -INT16_C( 27976),  INT16_C( 20518),  INT16_C( 12944), -INT16_C( 19246), -INT16_C( 32462),  INT16_C(   702),
       INT16_C( 28112),  INT16_C(  4745), -INT16_C(  1469), -INT16_C( 32428),  INT16_C( 16189),  INT16_C( 14632), -INT16_C( 28913),  INT16_C(  4374),
       INT16_C(  1965),  INT16_C( 25870), -INT16_C( 19439), -INT16_C( 23827),  INT16_C( 29969),  INT16_C( 13313),  INT16_C(  5698), -INT16_C( 27877),
      -INT16_C(  4526), -INT16_C( 26997), -INT16_C(  8217),  INT16_C(  5787),  INT16_C( 10519),  INT16_C( 10214), -INT16_C(   839),  INT16_C( 26168),
      -INT16_C( 23026), -INT16_C( 25141), -INT16_C( 32390), -INT16_C( 29624),  INT16_C(  6542), -INT16_C( 11944),  INT16_C( 29998),  INT16_C(  9718),
      -INT16_C(  3998),  INT16_C( 19221),  INT16_C( 24777),  INT16_C( 25576),  INT16_C( 22410), -INT16_C(  6062),  INT16_C( 16468),  INT16_C( 22697),
       INT16_C( 29830),  INT16_C(   245),  INT16_C( 16117), -INT16_C(  5236),  INT16_C( 26089),  INT16_C(  6218), -INT16_C( 20775),  INT16_C( 15256),
      -INT16_C(  3103),  INT16_C( 28293),  INT16_C( 28378),  INT16_C( 18128), -INT16_C( 27825),  INT16_C(  3886), -INT16_C( 13613),  INT16_C( 23035),
       INT16_C(  3723),  INT16_C( 13402), -INT16_C(  6609), -INT16_C( 18657),  INT16_C(  6451), -INT16_C(  8768),  INT16_C( 30699), -INT16_C(  5624),
       INT16_C( 14116), -INT16_C(    10), -INT16_C( 14428), -INT16_C( 11707) };

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
    rv = simde_svadd_s16_m(pv, av, bv);

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

    ev = simde_svadd_s16_m(pv, av, bv);

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
test_simde_svadd_s32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) };
  static const int32_t a[] =
    {  INT32_C(  1525843300), -INT32_C(    13112944),  INT32_C(    80369258), -INT32_C(   422090527),  INT32_C(  1929503224), -INT32_C(   499345841),  INT32_C(   636569342), -INT32_C(  1237538223),
      -INT32_C(  1089458641), -INT32_C(  2118236393),  INT32_C(  2139457950), -INT32_C(   362390287), -INT32_C(  1940035779), -INT32_C(    76637699),  INT32_C(   824270815),  INT32_C(   971463946),
      -INT32_C(  1560676469), -INT32_C(   601639106),  INT32_C(   844933184),  INT32_C(  1092403716),  INT32_C(   651065641), -INT32_C(   232637421), -INT32_C(  1507638372),  INT32_C(   736037536),
       INT32_C(  1087232001), -INT32_C(   803409776), -INT32_C(  1677559656),  INT32_C(  1675435578), -INT32_C(  1416975464), -INT32_C(  2070041368), -INT32_C(  1893023249), -INT32_C(   843445813),
       INT32_C(  1913489378),  INT32_C(   255994231), -INT32_C(   592755294), -INT32_C(    79656861),  INT32_C(   480692788),  INT32_C(  1705002102), -INT32_C(   789263867), -INT32_C(  1247957293),
      -INT32_C(  1406686667),  INT32_C(  1991994068),  INT32_C(   307390127),  INT32_C(   571380462), -INT32_C(   767642532), -INT32_C(    46670088),  INT32_C(  2093886376),  INT32_C(   238119897),
      -INT32_C(   356886250),  INT32_C(  1918924227), -INT32_C(   897273125), -INT32_C(  1578331579),  INT32_C(  1064577863), -INT32_C(  1304581367), -INT32_C(  1339159593), -INT32_C(  1933615242),
       INT32_C(  2071361976), -INT32_C(   890382609), -INT32_C(   829132151),  INT32_C(  1265598724), -INT32_C(  1249123412),  INT32_C(  1718077583),  INT32_C(  1226216915), -INT32_C(  1378429451),
       INT32_C(  1042893903), -INT32_C(  1408756189), -INT32_C(  1921344120), -INT32_C(   891754210),  INT32_C(  1551852493), -INT32_C(    20781269) };
  static const int32_t b[] =
    {  INT32_C(  1900599420), -INT32_C(    48292178), -INT32_C(  1925494678), -INT32_C(   415677602), -INT32_C(    25906208),  INT32_C(  1791511709), -INT32_C(   607762256), -INT32_C(  1411741649),
       INT32_C(   236790368), -INT32_C(  1442104256), -INT32_C(   499628412),  INT32_C(  1791586698), -INT32_C(  1033290459),  INT32_C(   975974794), -INT32_C(  1474956679), -INT32_C(   631967878),
       INT32_C(  1374253329),  INT32_C(   838661293), -INT32_C(   988597189), -INT32_C(   902832731), -INT32_C(  1534289894),  INT32_C(  1138669770),  INT32_C(   619508906), -INT32_C(   167821085),
       INT32_C(  1581705393),  INT32_C(   395264732),  INT32_C(   484221558), -INT32_C(  1696199553),  INT32_C(  1849586596), -INT32_C(   692970197), -INT32_C(   184902127), -INT32_C(  1880491554),
      -INT32_C(  1091751711), -INT32_C(   371884942), -INT32_C(  1643793890),  INT32_C(  1647897534), -INT32_C(  1965984162), -INT32_C(  1537178733), -INT32_C(     6727135),  INT32_C(   898531924),
       INT32_C(   636713906),  INT32_C(   353290743),  INT32_C(   968037243),  INT32_C(  1570499582), -INT32_C(   169382814),  INT32_C(   278546415), -INT32_C(   183553119),  INT32_C(  1747688885),
       INT32_C(   260906520),  INT32_C(  1646631911), -INT32_C(  1399072594),  INT32_C(   638138308), -INT32_C(  1826885469), -INT32_C(   643582665), -INT32_C(  1630620696),  INT32_C(  1762064720),
      -INT32_C(     8875240), -INT32_C(   597517010),  INT32_C(   982056310), -INT32_C(   664759756), -INT32_C(  1167361150),  INT32_C(   429067825),  INT32_C(   314008001),  INT32_C(  1937489243),
       INT32_C(  2121462608),  INT32_C(   123393169),  INT32_C(   104981458), -INT32_C(   136404619),  INT32_C(  1303464220),  INT32_C(   426198104) };
  static const int32_t e[] =
    { -INT32_C(   868524576), -INT32_C(    61405122), -INT32_C(  1845125420), -INT32_C(   837768129),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1645687424),
      -INT32_C(   852668273),  INT32_C(   734626647),  INT32_C(  1639829538),  INT32_C(  1429196411),  INT32_C(  1321641058),  INT32_C(   899337095),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(   186423140),  INT32_C(   237022187),  INT32_C(           0),  INT32_C(   189570985),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   568216451),
       INT32_C(           0), -INT32_C(   408145044), -INT32_C(  1193338098), -INT32_C(    20763975),  INT32_C(   432611132),  INT32_C(  1531955731),  INT32_C(           0),  INT32_C(  1571029929),
       INT32_C(           0), -INT32_C(   115890711),  INT32_C(           0),  INT32_C(  1568240673), -INT32_C(  1485291374),  INT32_C(   167823369), -INT32_C(   795991002), -INT32_C(   349425369),
       INT32_C(           0),  INT32_C(           0),  INT32_C(  1275427370),  INT32_C(  2141880044), -INT32_C(   937025346),  INT32_C(   231876327),  INT32_C(  1910333257),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1948164032),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(  1487899619),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  2147145408),  INT32_C(  1540224916),  INT32_C(   559059792),
      -INT32_C(  1130610785), -INT32_C(  1285363020),  INT32_C(           0), -INT32_C(  1028158829),  INT32_C(           0),  INT32_C(           0) };

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
    rv = simde_svadd_s32_z(pv, av, bv);

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

    ev = simde_svadd_s32_z(pv, av, bv);

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
test_simde_svadd_s32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0) };
  static const int32_t a[] =
    { -INT32_C(   839140647),  INT32_C(   878724879), -INT32_C(  1939075479),  INT32_C(  1057768591), -INT32_C(   796855666), -INT32_C(  1992015718),  INT32_C(   704397116),  INT32_C(  1017395298),
       INT32_C(    34185459),  INT32_C(  1362520807),  INT32_C(   148742776),  INT32_C(  1950869990),  INT32_C(  1984284635),  INT32_C(  1140820231),  INT32_C(   728562632),  INT32_C(   661066036),
      -INT32_C(  1742114639),  INT32_C(  1407803610), -INT32_C(   379861246), -INT32_C(  1940020560),  INT32_C(  1879220841), -INT32_C(   189595349),  INT32_C(   807346172), -INT32_C(   514357712),
      -INT32_C(   780500490), -INT32_C(   484154399), -INT32_C(   607355094), -INT32_C(  1972950495), -INT32_C(   117806644),  INT32_C(  1726786922), -INT32_C(    40432692), -INT32_C(  2015433071),
       INT32_C(  1347967087), -INT32_C(   432767812),  INT32_C(   482410747), -INT32_C(   140105686), -INT32_C(    68181871),  INT32_C(   442686285),  INT32_C(  1998060006),  INT32_C(  1476326887),
       INT32_C(   178739022), -INT32_C(   806298669),  INT32_C(   116110044),  INT32_C(  1828557530), -INT32_C(  2140672974), -INT32_C(  1382364729), -INT32_C(  1440435774), -INT32_C(   201251930),
       INT32_C(  1308534906),  INT32_C(  1612509060),  INT32_C(  2070284449), -INT32_C(   857250662),  INT32_C(   407654224), -INT32_C(   607787496),  INT32_C(  1048963735), -INT32_C(  2026732019),
      -INT32_C(  1294716626), -INT32_C(  1055723232), -INT32_C(  1824753159),  INT32_C(   761210077), -INT32_C(  1958368141),  INT32_C(   711330706),  INT32_C(    40430581), -INT32_C(  1601594767),
      -INT32_C(   346923573),  INT32_C(  1202480462), -INT32_C(  1143281186), -INT32_C(  2132264435),  INT32_C(  2013998822),  INT32_C(   782398009), -INT32_C(   818935203),  INT32_C(  1886370213),
       INT32_C(  1700577558),  INT32_C(    78383142), -INT32_C(    21002255), -INT32_C(  1484871487),  INT32_C(   253725398),  INT32_C(  1497219836),  INT32_C(  1898474956),  INT32_C(  1021482790),
       INT32_C(  2141273689),  INT32_C(   948194886), -INT32_C(  1774828587), -INT32_C(  1052920341),  INT32_C(  1003510847), -INT32_C(   342618850), -INT32_C(  1604534918), -INT32_C(  1378009516),
      -INT32_C(  1020428676), -INT32_C(  1577340468), -INT32_C(   533253644),  INT32_C(   631338214), -INT32_C(   278891823), -INT32_C(    86313601),  INT32_C(   110770098), -INT32_C(   223053963),
      -INT32_C(  1028267530), -INT32_C(  2040221550), -INT32_C(   932799519), -INT32_C(   504559600), -INT32_C(   103788934), -INT32_C(   168580285),  INT32_C(  1476103906), -INT32_C(    79057147),
       INT32_C(   582942352), -INT32_C(  1867963730), -INT32_C(   849866819), -INT32_C(  1850850025), -INT32_C(   695500909),  INT32_C(   214662698),  INT32_C(   308528908),  INT32_C(   118336886),
       INT32_C(  1512688555), -INT32_C(  1410673939), -INT32_C(   109559070),  INT32_C(   462104455), -INT32_C(   789506394), -INT32_C(  1579369068), -INT32_C(    88916092), -INT32_C(  1744715540),
       INT32_C(  2045913996), -INT32_C(   551232259), -INT32_C(  1512465122),  INT32_C(  1790993604),  INT32_C(   238727802), -INT32_C(   206629265),  INT32_C(  1122853461), -INT32_C(  1344606429),
       INT32_C(   388549658), -INT32_C(   956871256), -INT32_C(  1368665878), -INT32_C(  1374147532),  INT32_C(  1304187614), -INT32_C(  1119851416), -INT32_C(   234934834),  INT32_C(   916511004),
       INT32_C(  1297009061),  INT32_C(     1262870),  INT32_C(  1236172565), -INT32_C(  1980250453), -INT32_C(  2133413096), -INT32_C(   297986529),  INT32_C(  1625242947), -INT32_C(  1130987498),
       INT32_C(  1594483785),  INT32_C(  1046420777),  INT32_C(  1200033180), -INT32_C(   338657581),  INT32_C(  1366009394), -INT32_C(    12605252), -INT32_C(    60874779), -INT32_C(   390531425),
       INT32_C(    71811546),  INT32_C(  2051188446), -INT32_C(  2034120013),  INT32_C(  2054263112), -INT32_C(   204678089),  INT32_C(  1794313092), -INT32_C(   916041174),  INT32_C(   598810184),
      -INT32_C(  1104676641),  INT32_C(  1362651550),  INT32_C(  2094529075), -INT32_C(  1007269749), -INT32_C(  1447640540), -INT32_C(   132929074),  INT32_C(  1153595900),  INT32_C(  1986491287),
       INT32_C(   171216492),  INT32_C(   727477752), -INT32_C(   223923353), -INT32_C(  1598710148),  INT32_C(   776563808),  INT32_C(   287792149),  INT32_C(  1817635285), -INT32_C(   924598948),
       INT32_C(  1154684748), -INT32_C(   345034876), -INT32_C(   555870366),  INT32_C(   360682421),  INT32_C(   356829439), -INT32_C(    98145499), -INT32_C(  1335395244), -INT32_C(  2038871494),
      -INT32_C(   422949791), -INT32_C(   573490821),  INT32_C(    96251728),  INT32_C(  1109080899),  INT32_C(   676814595),  INT32_C(   505642698),  INT32_C(   885951226),  INT32_C(   901400532),
       INT32_C(   236684435),  INT32_C(   250408382), -INT32_C(   552294244), -INT32_C(   433967133),  INT32_C(  1477409166), -INT32_C(   227134729), -INT32_C(  1876540228),  INT32_C(   533062028),
       INT32_C(   590274917),  INT32_C(  1781668558), -INT32_C(  1521858878),  INT32_C(    59468917), -INT32_C(   581199131), -INT32_C(  1999646260), -INT32_C(  1592199915),  INT32_C(  1019338454),
      -INT32_C(  1923092545), -INT32_C(   872967927),  INT32_C(  1282425303), -INT32_C(  1823474771),  INT32_C(  1651550870), -INT32_C(  1846853765),  INT32_C(   187826996), -INT32_C(  1605897247),
      -INT32_C(   349329694),  INT32_C(   263595320),  INT32_C(   341583462), -INT32_C(  1196971230), -INT32_C(   786819242), -INT32_C(  1973287594), -INT32_C(   359295735),  INT32_C(  1804328072),
      -INT32_C(  1151944573),  INT32_C(  1154092509),  INT32_C(  1431840307),  INT32_C(   672006098),  INT32_C(  1828268054),  INT32_C(   922115117),  INT32_C(  2032241905), -INT32_C(   337335192),
       INT32_C(  1118190436),  INT32_C(  2072408392),  INT32_C(  1775361687) };
  static const int32_t b[] =
    { -INT32_C(   208544035),  INT32_C(   878676742), -INT32_C(   664119833),  INT32_C(  1246858209), -INT32_C(  1674234313), -INT32_C(  1176576911), -INT32_C(   466328499),  INT32_C(   525206850),
      -INT32_C(   367861788),  INT32_C(  1360949610), -INT32_C(  1473672762),  INT32_C(  1290959636),  INT32_C(   585639857),  INT32_C(  1356580355),  INT32_C(  1815416618), -INT32_C(   108297451),
      -INT32_C(   840721054), -INT32_C(   736230898), -INT32_C(  1619244917),  INT32_C(  1961586371), -INT32_C(  1718168682), -INT32_C(  1008045671), -INT32_C(  1792073856),  INT32_C(    76462754),
       INT32_C(  1708225111), -INT32_C(    12914572), -INT32_C(    73484744), -INT32_C(  1150318043), -INT32_C(   145488547), -INT32_C(   155566474), -INT32_C(     7542179), -INT32_C(    66839900),
       INT32_C(     6411660), -INT32_C(    33580091),  INT32_C(  2012782162), -INT32_C(  2060294360), -INT32_C(   495155604),  INT32_C(   584660933), -INT32_C(   987601631),  INT32_C(   213984895),
      -INT32_C(  1056168965),  INT32_C(   280890558), -INT32_C(   762857558), -INT32_C(  1957185250),  INT32_C(    91083840),  INT32_C(   740771339),  INT32_C(   737233323),  INT32_C(  1798812527),
      -INT32_C(  1809038378), -INT32_C(   106567089), -INT32_C(  1060426591),  INT32_C(   642458598),  INT32_C(    36419831), -INT32_C(  1439804673),  INT32_C(   198516636), -INT32_C(  1468658478),
      -INT32_C(  1623350704),  INT32_C(   781836941), -INT32_C(   185703410),  INT32_C(  2115647879), -INT32_C(   243251726),  INT32_C(   882618008), -INT32_C(  1606454834), -INT32_C(   850807171),
      -INT32_C(   445807016),  INT32_C(  1981023848), -INT32_C(   227868054),  INT32_C(   779126076),  INT32_C(  1663037899),  INT32_C(  1838660255), -INT32_C(  1458645461), -INT32_C(   445229172),
       INT32_C(  1170924509),  INT32_C(  1421598441),  INT32_C(   491136737),  INT32_C(  2001450668),  INT32_C(  1205496487),  INT32_C(  1354002724), -INT32_C(   721829305), -INT32_C(   155619559),
       INT32_C(  1010533203),  INT32_C(  1133573986), -INT32_C(   916400611),  INT32_C(   876653453),  INT32_C(   964368917), -INT32_C(   745983861),  INT32_C(   212304626),  INT32_C(  1157783794),
       INT32_C(  1166098147),  INT32_C(  1384649269),  INT32_C(  1964828904), -INT32_C(  1465230189),  INT32_C(    48375159),  INT32_C(  1221946197), -INT32_C(   531333906), -INT32_C(  1071294756),
      -INT32_C(   922376556), -INT32_C(  1591963976),  INT32_C(   169228406),  INT32_C(   196264084),  INT32_C(   990811366), -INT32_C(   293346560),  INT32_C(  1020188512), -INT32_C(  1023610066),
       INT32_C(  1384907417),  INT32_C(   116631696),  INT32_C(  1947208160), -INT32_C(  1333738550),  INT32_C(  1475055191), -INT32_C(   783978639),  INT32_C(  1947079494), -INT32_C(  1607005690),
      -INT32_C(  1661811956),  INT32_C(  1269032299), -INT32_C(  1195396114), -INT32_C(   832028810),  INT32_C(  1059411149),  INT32_C(   152071107), -INT32_C(  2055332226),  INT32_C(   891663657),
      -INT32_C(   472770696), -INT32_C(   366053892), -INT32_C(  1616646872), -INT32_C(    93517011),  INT32_C(   574198367),  INT32_C(  2083277565), -INT32_C(  1862161816), -INT32_C(   674814369),
       INT32_C(   968530237),  INT32_C(   908322830),  INT32_C(    47564501),  INT32_C(   838681298), -INT32_C(   766232875), -INT32_C(   380731264), -INT32_C(  1988473046), -INT32_C(  1302314635),
      -INT32_C(   387245350), -INT32_C(   685830398), -INT32_C(  1478822699),  INT32_C(   215602999), -INT32_C(  1898042099), -INT32_C(   680055379), -INT32_C(   228527748),  INT32_C(   228900915),
      -INT32_C(   587820838),  INT32_C(  1957893535),  INT32_C(  1075612937),  INT32_C(  1917646180), -INT32_C(   822072542), -INT32_C(   727287976), -INT32_C(  1681521048), -INT32_C(  1599509562),
      -INT32_C(  1703108613), -INT32_C(  1123143756),  INT32_C(   570305213),  INT32_C(  1100171807), -INT32_C(   854551691),  INT32_C(  1940043274), -INT32_C(  2112984900), -INT32_C(   836585517),
       INT32_C(   174628438), -INT32_C(  1949796402), -INT32_C(  1045641567), -INT32_C(  2046672880), -INT32_C(   564980781), -INT32_C(  2041449015),  INT32_C(   822632286),  INT32_C(  1828727575),
      -INT32_C(  1753716535), -INT32_C(  2128461601),  INT32_C(   373477126), -INT32_C(   493075441),  INT32_C(   566292567),  INT32_C(  1135022565), -INT32_C(  2005553295), -INT32_C(  1527417382),
      -INT32_C(  1120178723), -INT32_C(  1287758163),  INT32_C(  1019904045),  INT32_C(   471754436),  INT32_C(  1010687830),  INT32_C(  1635771632),  INT32_C(  1860826259),  INT32_C(  1192419177),
      -INT32_C(   100381364), -INT32_C(   659733845), -INT32_C(  2045478974),  INT32_C(   883045342),  INT32_C(    40951570),  INT32_C(  1466233027),  INT32_C(  1321553380),  INT32_C(  2039863084),
      -INT32_C(   797730524), -INT32_C(  1649925925),  INT32_C(  1982053784),  INT32_C(    44746480),  INT32_C(  1761876901), -INT32_C(   272603125), -INT32_C(   499284554), -INT32_C(  2141466020),
       INT32_C(  1179700843), -INT32_C(  2015102481), -INT32_C(  1493366858),  INT32_C(  1923655629), -INT32_C(   841241406), -INT32_C(   876766443),  INT32_C(  2091776544),  INT32_C(   956107213),
      -INT32_C(   964735529), -INT32_C(    62037434),  INT32_C(   916605545), -INT32_C(  1263973646),  INT32_C(   209880311),  INT32_C(  1087848224),  INT32_C(   113083449),  INT32_C(  1698675341),
       INT32_C(  1311489543), -INT32_C(  1974830816), -INT32_C(  1245647421),  INT32_C(   778725687),  INT32_C(   238742766),  INT32_C(  1682837803),  INT32_C(   594217878), -INT32_C(   846681403),
      -INT32_C(  2011450264), -INT32_C(   267229907), -INT32_C(  1968778414),  INT32_C(   716705852),  INT32_C(   658043900), -INT32_C(  1702131964),  INT32_C(  1488909970),  INT32_C(   136660640),
       INT32_C(   663830778), -INT32_C(   132602971), -INT32_C(  1283277194) };
  static const int32_t e[] =
    { -INT32_C(  1047684682),  INT32_C(  1757401621),  INT32_C(  1691771984),  INT32_C(  1057768591), -INT32_C(   796855666), -INT32_C(  1992015718),  INT32_C(   704397116),  INT32_C(  1542602148),
      -INT32_C(   333676329), -INT32_C(  1571496879), -INT32_C(  1324929986), -INT32_C(  1053137670),  INT32_C(  1984284635),  INT32_C(  1140820231),  INT32_C(   728562632),  INT32_C(   661066036),
       INT32_C(  1712131603),  INT32_C(   671572712), -INT32_C(   379861246), -INT32_C(  1940020560),  INT32_C(   161052159), -INT32_C(   189595349), -INT32_C(   984727684), -INT32_C(   514357712),
       INT32_C(   927724621), -INT32_C(   497068971), -INT32_C(   680839838),  INT32_C(  1171698758), -INT32_C(   263295191),  INT32_C(  1726786922), -INT32_C(    47974871), -INT32_C(  2082272971),
       INT32_C(  1354378747), -INT32_C(   432767812),  INT32_C(   482410747), -INT32_C(   140105686), -INT32_C(   563337475),  INT32_C(   442686285),  INT32_C(  1010458375),  INT32_C(  1690311782),
       INT32_C(   178739022), -INT32_C(   806298669),  INT32_C(   116110044), -INT32_C(   128627720), -INT32_C(  2140672974), -INT32_C(   641593390), -INT32_C(   703202451), -INT32_C(   201251930),
       INT32_C(  1308534906),  INT32_C(  1612509060),  INT32_C(  1009857858), -INT32_C(   857250662),  INT32_C(   407654224), -INT32_C(  2047592169),  INT32_C(  1048963735),  INT32_C(   799576799),
       INT32_C(  1376899966), -INT32_C(   273886291), -INT32_C(  1824753159),  INT32_C(   761210077),  INT32_C(  2093347429),  INT32_C(   711330706), -INT32_C(  1566024253), -INT32_C(  1601594767),
      -INT32_C(   792730589), -INT32_C(  1111462986), -INT32_C(  1371149240), -INT32_C(  1353138359),  INT32_C(  2013998822), -INT32_C(  1673909032),  INT32_C(  2017386632),  INT32_C(  1441141041),
      -INT32_C(  1423465229),  INT32_C(  1499981583), -INT32_C(    21002255),  INT32_C(   516579181),  INT32_C(  1459221885), -INT32_C(  1443744736),  INT32_C(  1176645651),  INT32_C(  1021482790),
       INT32_C(  2141273689),  INT32_C(   948194886),  INT32_C(  1603738098), -INT32_C(   176266888),  INT32_C(  1967879764), -INT32_C(   342618850), -INT32_C(  1392230292), -INT32_C(   220225722),
       INT32_C(   145669471), -INT32_C(  1577340468), -INT32_C(   533253644),  INT32_C(   631338214), -INT32_C(   278891823), -INT32_C(    86313601),  INT32_C(   110770098), -INT32_C(  1294348719),
      -INT32_C(  1950644086), -INT32_C(  2040221550), -INT32_C(   932799519), -INT32_C(   504559600), -INT32_C(   103788934), -INT32_C(   461926845), -INT32_C(  1798674878), -INT32_C(  1102667213),
       INT32_C(  1967849769), -INT32_C(  1867963730), -INT32_C(   849866819),  INT32_C(  1110378721), -INT32_C(   695500909), -INT32_C(   569315941),  INT32_C(   308528908), -INT32_C(  1488668804),
       INT32_C(  1512688555), -INT32_C(   141641640), -INT32_C(  1304955184),  INT32_C(   462104455), -INT32_C(   789506394), -INT32_C(  1579369068), -INT32_C(  2144248318), -INT32_C(  1744715540),
       INT32_C(  2045913996), -INT32_C(   917286151), -INT32_C(  1512465122),  INT32_C(  1790993604),  INT32_C(   812926169),  INT32_C(  1876648300), -INT32_C(   739308355), -INT32_C(  2019420798),
       INT32_C(  1357079895), -INT32_C(   956871256), -INT32_C(  1321101377), -INT32_C(   535466234),  INT32_C(  1304187614), -INT32_C(  1119851416), -INT32_C(   234934834), -INT32_C(   385803631),
       INT32_C(   909763711), -INT32_C(   684567528), -INT32_C(   242650134), -INT32_C(  1980250453),  INT32_C(   263512101), -INT32_C(   978041908),  INT32_C(  1396715199), -INT32_C(  1130987498),
       INT32_C(  1594483785),  INT32_C(  1046420777), -INT32_C(  2019321179),  INT32_C(  1578988599),  INT32_C(   543936852), -INT32_C(   739893228), -INT32_C(  1742395827), -INT32_C(   390531425),
       INT32_C(    71811546),  INT32_C(  2051188446), -INT32_C(  2034120013),  INT32_C(  2054263112), -INT32_C(   204678089),  INT32_C(  1794313092),  INT32_C(  1265941222), -INT32_C(   237775333),
      -INT32_C(   930048203),  INT32_C(  1362651550),  INT32_C(  2094529075), -INT32_C(  1007269749), -INT32_C(  2012621321),  INT32_C(  2120589207),  INT32_C(  1976228186),  INT32_C(  1986491287),
      -INT32_C(  1582500043), -INT32_C(  1400983849),  INT32_C(   149553773), -INT32_C(  1598710148),  INT32_C(   776563808),  INT32_C(   287792149),  INT32_C(  1817635285),  INT32_C(  1842950966),
       INT32_C(  1154684748), -INT32_C(  1632793039), -INT32_C(   555870366),  INT32_C(   360682421),  INT32_C(   356829439),  INT32_C(  1537626133), -INT32_C(  1335395244), -INT32_C(  2038871494),
      -INT32_C(   422949791), -INT32_C(  1233224666), -INT32_C(  1949227246),  INT32_C(  1109080899),  INT32_C(   676814595),  INT32_C(  1971875725),  INT32_C(   885951226), -INT32_C(  1353703680),
       INT32_C(   236684435),  INT32_C(   250408382), -INT32_C(   552294244), -INT32_C(   389220653), -INT32_C(  1055681229), -INT32_C(   499737854), -INT32_C(  1876540228),  INT32_C(   533062028),
       INT32_C(   590274917), -INT32_C(   233433923),  INT32_C(  1279741560),  INT32_C(  1983124546), -INT32_C(  1422440537),  INT32_C(  1418554593), -INT32_C(  1592199915),  INT32_C(  1975445667),
       INT32_C(  1407139222), -INT32_C(   872967927), -INT32_C(  2095936448),  INT32_C(  1207518879),  INT32_C(  1651550870), -INT32_C(  1846853765),  INT32_C(   300910445),  INT32_C(    92778094),
      -INT32_C(   349329694), -INT32_C(  1711235496), -INT32_C(   904063959), -INT32_C(   418245543), -INT32_C(   548076476), -INT32_C(  1973287594),  INT32_C(   234922143),  INT32_C(  1804328072),
      -INT32_C(  1151944573),  INT32_C(   886862602), -INT32_C(   536938107),  INT32_C(  1388711950), -INT32_C(  1808655342),  INT32_C(   922115117),  INT32_C(  2032241905), -INT32_C(   337335192),
       INT32_C(  1118190436),  INT32_C(  2072408392),  INT32_C(  1775361687) };

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
    rv = simde_svadd_s32_m(pv, av, bv);

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

    ev = simde_svadd_s32_m(pv, av, bv);

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
test_simde_svadd_s64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1) };
  static const int64_t a[] =
    {  INT64_C( 6186530343260918766), -INT64_C( 7087636093371708336), -INT64_C( 2690846841557009779),  INT64_C( 5112870185477631259),
       INT64_C( 8901908007799239331),  INT64_C( 1558109715775414395), -INT64_C( 1178352298896743746), -INT64_C( 1391022631278102253),
       INT64_C( 3526505105050355530),  INT64_C( 1380301974120092041), -INT64_C( 2362556041106938509), -INT64_C( 4867548483696240324),
      -INT64_C( 4131170590038846523),  INT64_C( 2403795950143856115), -INT64_C(  517739422806427355), -INT64_C( 2367220933372011272),
       INT64_C( 7819942723940079492), -INT64_C( 8957361285050900767) };
  static const int64_t b[] =
    { -INT64_C( 5693600271763760824), -INT64_C( 1127800496542090400), -INT64_C( 7387249504389385322), -INT64_C( 8757573560984653931),
      -INT64_C( 8116746364105594125),  INT64_C( 5286491159882527745), -INT64_C( 2708964354071982570),  INT64_C( 6685105915727613698),
      -INT64_C( 2815485514901663697),  INT64_C( 8202078959929063382),  INT64_C(  203127076486589617),  INT64_C( 1367697785071247158),
       INT64_C( 4181977513392603737), -INT64_C( 6619560334166044843),  INT64_C( 4523139086149116356),  INT64_C( 7638342539553867786),
       INT64_C( 2628031592586244570), -INT64_C( 7383097616041165325) };
  static const int64_t e[] =
    {  INT64_C(                   0), -INT64_C( 8215436589913798736),  INT64_C(                   0), -INT64_C( 3644703375507022672),
       INT64_C(  785161643693645206),  INT64_C(                   0), -INT64_C( 3887316652968726316),  INT64_C( 5294083284449511445),
       INT64_C(  711019590148691833),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(   50806923353757214),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C( 7998769757183227554),  INT64_C( 2106285172617485524) };

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
    rv = simde_svadd_s64_z(pv, av, bv);

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

    ev = simde_svadd_s64_z(pv, av, bv);

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
test_simde_svadd_s64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0) };
  static const int64_t a[] =
    { -INT64_C(  577829422127329733),  INT64_C( 3370440741211582870),  INT64_C( 8108910234889736382),  INT64_C( 4125716164716801025),
       INT64_C( 5725462407232525898), -INT64_C( 3185379650830540898), -INT64_C( 8040985201303163886),  INT64_C( 3968229741357068506),
      -INT64_C( 8171172461888142447),  INT64_C( 7706212395226240520), -INT64_C( 6988519247355701276),  INT64_C( 5358872030646680891),
       INT64_C( 4903344931639399309),  INT64_C( 1371156075509856324),  INT64_C( 8056527640641038698),  INT64_C( 6722174196817217094),
       INT64_C( 5803141060236074248), -INT64_C( 6385554252480255458), -INT64_C( 5187964863534143395), -INT64_C( 7775464152210368533),
      -INT64_C(  560028714606726179),  INT64_C( 8660605820125718347), -INT64_C( 7513962773717842289),  INT64_C( 5602877540966494369),
       INT64_C( 4985328632004581726), -INT64_C( 6040456171174922856), -INT64_C( 2213969738794715900),  INT64_C( 7103531229043988950),
      -INT64_C( 3122743605381706902),  INT64_C( 8649359297186592318), -INT64_C( 1006151974528764440),  INT64_C( 6011687478408845319),
       INT64_C( 1056200558361642648), -INT64_C( 3908436314174181418),  INT64_C( 6860665963884440103), -INT64_C( 3220118555908739565),
       INT64_C( 4448236359377159901), -INT64_C( 4816236316771015554),  INT64_C( 3020566346036419380),  INT64_C(  699031202755401124),
       INT64_C( 2891154464557128316),  INT64_C( 2731911397880932246), -INT64_C( 4464021474147964467),  INT64_C( 2604863615020446449),
      -INT64_C( 1980978768146670161) };
  static const int64_t b[] =
    { -INT64_C( 8510684281762215219),  INT64_C( 2432921470799484130),  INT64_C( 7671711241672222123),  INT64_C( 8175235796689976897),
       INT64_C( 7031828200765228368),  INT64_C( 2879811700534674086), -INT64_C( 2616606118369413749),  INT64_C(  614142905915503472),
       INT64_C( 7801549325214266468),  INT64_C( 6219534630132033197),  INT64_C( 3234230753359088238), -INT64_C( 7962428817102844482),
      -INT64_C( 1320759483916053383), -INT64_C( 7746079044976317090),  INT64_C( 2745364436987157552), -INT64_C( 7383056615951476020),
       INT64_C( 1647900439235592113), -INT64_C( 8490199702166244239),  INT64_C( 1399371844522854621), -INT64_C( 2908315844229723669),
       INT64_C( 8170556669215407253),  INT64_C( 4647493143393575834),  INT64_C( 8239601081563608830), -INT64_C( 8000889950046427910),
       INT64_C(   76069053174497436),  INT64_C( 5514504144007010275), -INT64_C(  547773398943462037), -INT64_C( 6928208574265367986),
      -INT64_C( 2650568525273647153),  INT64_C(  935247484020730977), -INT64_C( 4274651109794083657), -INT64_C( 6564021933429570235),
      -INT64_C( 3642548515510803809), -INT64_C(  654580779141327555), -INT64_C( 7909349760104142590), -INT64_C( 3272215654671168995),
      -INT64_C( 4747677459214143261),  INT64_C( 1200357797873424498), -INT64_C( 3940714902732647568), -INT64_C( 3669499204809840369),
      -INT64_C( 3818707953509368383), -INT64_C( 7570791603992944943),  INT64_C( 5471488976492918648), -INT64_C( 4863147644663584309),
      -INT64_C( 6178374804794532067) };
  static const int64_t e[] =
    { -INT64_C(  577829422127329733),  INT64_C( 5803362212011067000),  INT64_C( 8108910234889736382),  INT64_C( 4125716164716801025),
      -INT64_C( 5689453465711797350), -INT64_C(  305567950295866812), -INT64_C( 8040985201303163886),  INT64_C( 3968229741357068506),
      -INT64_C( 8171172461888142447),  INT64_C( 7706212395226240520), -INT64_C( 3754288493996613038), -INT64_C( 2603556786456163591),
       INT64_C( 4903344931639399309),  INT64_C( 1371156075509856324), -INT64_C( 7644851996081355366),  INT64_C( 6722174196817217094),
       INT64_C( 5803141060236074248),  INT64_C( 3570990119063051919), -INT64_C( 3788593019011288774),  INT64_C( 7762964077269459414),
       INT64_C( 7610527954608681074), -INT64_C( 5138645110190257435),  INT64_C(  725638307845766541),  INT64_C( 5602877540966494369),
       INT64_C( 5061397685179079162), -INT64_C( 6040456171174922856), -INT64_C( 2213969738794715900),  INT64_C( 7103531229043988950),
      -INT64_C( 3122743605381706902),  INT64_C( 8649359297186592318), -INT64_C( 1006151974528764440), -INT64_C(  552334455020724916),
      -INT64_C( 2586347957149161161), -INT64_C( 4563017093315508973),  INT64_C( 6860665963884440103), -INT64_C( 6492334210579908560),
      -INT64_C(  299441099836983360), -INT64_C( 3615878518897591056),  INT64_C( 3020566346036419380), -INT64_C( 2970468002054439245),
      -INT64_C(  927553488952240067),  INT64_C( 2731911397880932246),  INT64_C( 1007467502344954181),  INT64_C( 2604863615020446449),
      -INT64_C( 1980978768146670161) };

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
    rv = simde_svadd_s64_m(pv, av, bv);

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

    ev = simde_svadd_s64_m(pv, av, bv);

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
test_simde_svadd_u8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) };
  static const uint8_t a[] =
    { UINT8_C(242), UINT8_C(137), UINT8_C( 39), UINT8_C(233), UINT8_C( 29), UINT8_C( 17), UINT8_C( 51), UINT8_C(244),
      UINT8_C(226), UINT8_C(236), UINT8_C( 29), UINT8_C( 70), UINT8_C( 53), UINT8_C( 57), UINT8_C(108), UINT8_C(175),
      UINT8_C(115), UINT8_C(236), UINT8_C(  7), UINT8_C(175), UINT8_C(163), UINT8_C(215), UINT8_C(148), UINT8_C(123),
      UINT8_C(106), UINT8_C(180), UINT8_C( 81), UINT8_C(120), UINT8_C( 22) };
  static const uint8_t b[] =
    { UINT8_C( 13), UINT8_C(148), UINT8_C( 81), UINT8_C( 31), UINT8_C(223), UINT8_C( 11), UINT8_C(136), UINT8_C(205),
      UINT8_C(194), UINT8_C(234), UINT8_C(137), UINT8_C( 96), UINT8_C(203), UINT8_C(165), UINT8_C(233), UINT8_C( 88),
      UINT8_C(117), UINT8_C( 38), UINT8_C(165), UINT8_C( 82), UINT8_C(211), UINT8_C(139), UINT8_C(130), UINT8_C( 24),
      UINT8_C(118), UINT8_C(216), UINT8_C(101), UINT8_C( 71), UINT8_C( 67) };
  static const uint8_t e[] =
    { UINT8_C(  0), UINT8_C( 29), UINT8_C(120), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(187), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(166), UINT8_C(166), UINT8_C(  0), UINT8_C(222), UINT8_C( 85), UINT8_C(  0),
      UINT8_C(232), UINT8_C(  0), UINT8_C(172), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(147),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(182), UINT8_C(191), UINT8_C(  0) };

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
    rv = simde_svadd_u8_z(pv, av, bv);

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

    ev = simde_svadd_u8_z(pv, av, bv);

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
test_simde_svadd_u8_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) };
  static const uint8_t a[] =
    { UINT8_C( 24), UINT8_C(132), UINT8_C(140), UINT8_C(243), UINT8_C(131), UINT8_C(237), UINT8_C(104), UINT8_C(169),
      UINT8_C( 62), UINT8_C(161), UINT8_C(212), UINT8_C(178), UINT8_C(163), UINT8_C(144), UINT8_C(164), UINT8_C(251),
      UINT8_C( 35), UINT8_C(186), UINT8_C(110), UINT8_C(112), UINT8_C(235), UINT8_C(201), UINT8_C(198), UINT8_C(107),
      UINT8_C( 27), UINT8_C( 26), UINT8_C( 25), UINT8_C(167), UINT8_C(139), UINT8_C(184), UINT8_C( 70), UINT8_C(163),
      UINT8_C( 61), UINT8_C(210), UINT8_C(151), UINT8_C(192), UINT8_C(191),    UINT8_MAX, UINT8_C(106), UINT8_C(253),
      UINT8_C(160), UINT8_C( 62), UINT8_C(176), UINT8_C( 67), UINT8_C(207), UINT8_C( 84), UINT8_C( 62), UINT8_C(242),
      UINT8_C( 15), UINT8_C(173), UINT8_C( 98), UINT8_C(250), UINT8_C(118), UINT8_C( 40), UINT8_C(101), UINT8_C(145),
      UINT8_C( 66), UINT8_C(126), UINT8_C( 56), UINT8_C(206), UINT8_C( 55), UINT8_C(126), UINT8_C(113), UINT8_C(116),
      UINT8_C( 80), UINT8_C(  8), UINT8_C( 52), UINT8_C( 15), UINT8_C(  7), UINT8_C(158), UINT8_C( 12) };
  static const uint8_t b[] =
    { UINT8_C( 45), UINT8_C( 98), UINT8_C( 87), UINT8_C( 73), UINT8_C(159), UINT8_C(226), UINT8_C(131), UINT8_C(  2),
      UINT8_C(  0), UINT8_C(153), UINT8_C( 18), UINT8_C(  0), UINT8_C(171), UINT8_C( 52), UINT8_C( 67), UINT8_C(163),
      UINT8_C(102), UINT8_C( 88), UINT8_C(152), UINT8_C(210), UINT8_C(128), UINT8_C(222), UINT8_C( 38), UINT8_C(173),
      UINT8_C(145), UINT8_C( 75), UINT8_C( 20), UINT8_C(169), UINT8_C(206), UINT8_C(211), UINT8_C(117), UINT8_C(252),
      UINT8_C( 53), UINT8_C(204), UINT8_C( 69), UINT8_C(213), UINT8_C(174), UINT8_C(200), UINT8_C(215), UINT8_C(174),
      UINT8_C( 98), UINT8_C(233), UINT8_C(174), UINT8_C( 13), UINT8_C( 29), UINT8_C(241), UINT8_C(177), UINT8_C(131),
      UINT8_C( 74), UINT8_C( 73), UINT8_C( 86), UINT8_C(202), UINT8_C( 39), UINT8_C(124), UINT8_C(119), UINT8_C(184),
      UINT8_C(200), UINT8_C(139), UINT8_C( 97), UINT8_C(150), UINT8_C( 94), UINT8_C(214), UINT8_C(146), UINT8_C(148),
      UINT8_C(162), UINT8_C(215), UINT8_C(105), UINT8_C( 80), UINT8_C(160), UINT8_C( 64), UINT8_C(254) };
  static const uint8_t e[] =
    { UINT8_C( 24), UINT8_C(132), UINT8_C(140), UINT8_C( 60), UINT8_C( 34), UINT8_C(207), UINT8_C(235), UINT8_C(169),
      UINT8_C( 62), UINT8_C( 58), UINT8_C(230), UINT8_C(178), UINT8_C( 78), UINT8_C(196), UINT8_C(164), UINT8_C(158),
      UINT8_C(137), UINT8_C( 18), UINT8_C(  6), UINT8_C(112), UINT8_C(107), UINT8_C(201), UINT8_C(198), UINT8_C(107),
      UINT8_C( 27), UINT8_C( 26), UINT8_C( 45), UINT8_C(167), UINT8_C( 89), UINT8_C(184), UINT8_C(187), UINT8_C(159),
      UINT8_C( 61), UINT8_C(210), UINT8_C(220), UINT8_C(192), UINT8_C(109),    UINT8_MAX, UINT8_C( 65), UINT8_C(253),
      UINT8_C(  2), UINT8_C( 62), UINT8_C( 94), UINT8_C( 67), UINT8_C(236), UINT8_C( 84), UINT8_C( 62), UINT8_C(117),
      UINT8_C( 89), UINT8_C(246), UINT8_C( 98), UINT8_C(250), UINT8_C(118), UINT8_C( 40), UINT8_C(220), UINT8_C(145),
      UINT8_C( 66), UINT8_C(  9), UINT8_C( 56), UINT8_C(100), UINT8_C(149), UINT8_C(126), UINT8_C(  3), UINT8_C(116),
      UINT8_C( 80), UINT8_C(  8), UINT8_C( 52), UINT8_C( 15), UINT8_C(167), UINT8_C(222), UINT8_C( 12) };

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
    rv = simde_svadd_u8_m(pv, av, bv);

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

    ev = simde_svadd_u8_m(pv, av, bv);

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
test_simde_svadd_u16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) };
  static const uint16_t a[] =
    { UINT16_C(60577), UINT16_C( 9275), UINT16_C(38610), UINT16_C(23805), UINT16_C(16639), UINT16_C(26212), UINT16_C(39946), UINT16_C(28412),
      UINT16_C(46976), UINT16_C(54166), UINT16_C(31215), UINT16_C(20316), UINT16_C(58795), UINT16_C(31959), UINT16_C(55381), UINT16_C(63122),
      UINT16_C(52676), UINT16_C(38426), UINT16_C( 5987), UINT16_C(25330), UINT16_C(22103), UINT16_C(25033), UINT16_C(50674), UINT16_C(29391),
      UINT16_C(26236), UINT16_C(27462), UINT16_C(41695), UINT16_C(35515), UINT16_C(37511), UINT16_C(56326), UINT16_C(39018), UINT16_C(11986),
      UINT16_C(60517), UINT16_C(51396), UINT16_C(46596), UINT16_C(23339), UINT16_C(62476), UINT16_C(65213), UINT16_C(36025), UINT16_C(13681),
      UINT16_C(47090), UINT16_C(53665), UINT16_C(23641), UINT16_C(57436), UINT16_C(25326), UINT16_C(22972), UINT16_C(36603), UINT16_C(24711),
      UINT16_C(19578), UINT16_C(32297), UINT16_C(21506), UINT16_C( 4058), UINT16_C(38728), UINT16_C(  269), UINT16_C(32291), UINT16_C( 5686),
      UINT16_C(55093), UINT16_C(36583), UINT16_C(17203), UINT16_C( 8814), UINT16_C(10918), UINT16_C(41339), UINT16_C(  696), UINT16_C(13057),
      UINT16_C(10830), UINT16_C(20913), UINT16_C(35710), UINT16_C(50784), UINT16_C(27938), UINT16_C(18119), UINT16_C(65260), UINT16_C( 8540),
      UINT16_C(17365), UINT16_C( 2480), UINT16_C( 7815), UINT16_C(11563), UINT16_C(42569), UINT16_C(  462), UINT16_C(53160), UINT16_C(63284),
      UINT16_C(59130), UINT16_C(30792), UINT16_C(43121), UINT16_C(37951), UINT16_C( 1557), UINT16_C(  474), UINT16_C(13828), UINT16_C(55843),
      UINT16_C(54137), UINT16_C(  227), UINT16_C( 3825), UINT16_C(14893), UINT16_C(64436), UINT16_C(23612), UINT16_C(28875), UINT16_C(50515),
      UINT16_C(39766), UINT16_C(51261), UINT16_C(31811), UINT16_C(22876), UINT16_C(13955), UINT16_C(34650), UINT16_C(32108), UINT16_C(58721),
      UINT16_C(17488), UINT16_C(17126), UINT16_C( 4946), UINT16_C( 1660), UINT16_C(47119), UINT16_C(55907), UINT16_C(46633), UINT16_C(32671),
      UINT16_C(56402), UINT16_C(38215), UINT16_C(41817), UINT16_C(56558), UINT16_C(18905), UINT16_C(17763), UINT16_C(50630), UINT16_C( 5931),
      UINT16_C( 4361), UINT16_C(23641), UINT16_C(54564), UINT16_C(13154), UINT16_C(50574), UINT16_C(46861), UINT16_C(44156), UINT16_C(52790),
      UINT16_C(32393), UINT16_C(57955), UINT16_C(21025), UINT16_C(64446), UINT16_C( 8603), UINT16_C(24896), UINT16_C(27622), UINT16_C(61560),
      UINT16_C(53628), UINT16_C(41292), UINT16_C(44711), UINT16_C(13780), UINT16_C(57972), UINT16_C(61676), UINT16_C( 8846), UINT16_C( 6078),
      UINT16_C( 8608), UINT16_C(49913), UINT16_C(46963), UINT16_C( 3773), UINT16_C(64985), UINT16_C(49008), UINT16_C(59497), UINT16_C(58799),
      UINT16_C(64442), UINT16_C(24966), UINT16_C(23466), UINT16_C( 7830), UINT16_C(33341), UINT16_C(51982), UINT16_C(52388), UINT16_C(17891),
      UINT16_C(56557), UINT16_C(24839), UINT16_C(50324), UINT16_C(28015), UINT16_C(57281), UINT16_C(10796), UINT16_C(56520), UINT16_C(33296),
      UINT16_C(38615), UINT16_C(33251), UINT16_C(31217), UINT16_C(11935), UINT16_C(44539), UINT16_C(40954), UINT16_C(56697), UINT16_C(26596),
      UINT16_C(60345), UINT16_C(19912), UINT16_C(14255), UINT16_C(29114), UINT16_C(59159), UINT16_C(57243), UINT16_C(43971), UINT16_C(39521),
      UINT16_C(17474), UINT16_C(13084), UINT16_C(48061), UINT16_C(47202), UINT16_C(23657), UINT16_C(57943), UINT16_C(15417), UINT16_C(62025),
      UINT16_C( 4391), UINT16_C(55104), UINT16_C(64073), UINT16_C(24648), UINT16_C(58337), UINT16_C(42047), UINT16_C(41103), UINT16_C(53567),
      UINT16_C(23524), UINT16_C(41220), UINT16_C(26134), UINT16_C(32601), UINT16_C(45250), UINT16_C(64354), UINT16_C(44012), UINT16_C( 5358),
      UINT16_C(11965), UINT16_C( 1771), UINT16_C(13096), UINT16_C( 2662), UINT16_C(42262), UINT16_C(42414), UINT16_C(60741), UINT16_C(10614),
      UINT16_C(31560), UINT16_C(24522), UINT16_C( 9185), UINT16_C(42206), UINT16_C(16595), UINT16_C(49311), UINT16_C(36332), UINT16_C(43476),
      UINT16_C(49083), UINT16_C(58543), UINT16_C( 5618), UINT16_C( 2286), UINT16_C(40122), UINT16_C(65454), UINT16_C( 9354), UINT16_C(53800),
      UINT16_C(62111), UINT16_C(33073), UINT16_C( 4117), UINT16_C(59429), UINT16_C(50256), UINT16_C(15528), UINT16_C(31826), UINT16_C( 3557),
      UINT16_C(37947), UINT16_C(11761), UINT16_C(57257), UINT16_C(25398), UINT16_C(58492), UINT16_C( 1634), UINT16_C(35336), UINT16_C(43224) };
  static const uint16_t b[] =
    { UINT16_C( 8988), UINT16_C(11884), UINT16_C(42572), UINT16_C(32431), UINT16_C( 6091), UINT16_C(52765), UINT16_C(61990), UINT16_C(21731),
      UINT16_C(27969), UINT16_C(45685), UINT16_C(59952), UINT16_C(48788), UINT16_C(22355), UINT16_C(13648), UINT16_C(40305), UINT16_C(36350),
      UINT16_C(27585), UINT16_C( 3515), UINT16_C(27153), UINT16_C(56459), UINT16_C(43138), UINT16_C(43178), UINT16_C(36506), UINT16_C(56316),
      UINT16_C(29435), UINT16_C(11149), UINT16_C( 8796), UINT16_C(45289), UINT16_C(14969), UINT16_C(60133), UINT16_C(58327), UINT16_C(39031),
      UINT16_C(12878), UINT16_C(24485), UINT16_C(12444), UINT16_C( 7739), UINT16_C(59097), UINT16_C(29638), UINT16_C(50036), UINT16_C(28495),
      UINT16_C(56373), UINT16_C(37274), UINT16_C(33790), UINT16_C(30529), UINT16_C( 9917), UINT16_C(38241), UINT16_C(55306), UINT16_C(22573),
      UINT16_C(54026), UINT16_C(42936), UINT16_C(62211), UINT16_C(56517), UINT16_C(36057), UINT16_C(19792), UINT16_C(40783), UINT16_C(33980),
      UINT16_C(22139), UINT16_C(31253), UINT16_C(22490), UINT16_C(38897), UINT16_C(21373), UINT16_C(34604), UINT16_C(23083), UINT16_C(14048),
      UINT16_C(38957), UINT16_C(12509), UINT16_C(41611), UINT16_C(25869), UINT16_C(23854), UINT16_C(32178), UINT16_C(28668), UINT16_C(30465),
      UINT16_C( 6085), UINT16_C(40945), UINT16_C(58222), UINT16_C(60215), UINT16_C(25398), UINT16_C(24947), UINT16_C(21437), UINT16_C(60055),
      UINT16_C(29931), UINT16_C(30235), UINT16_C(10263), UINT16_C(17883), UINT16_C(36485), UINT16_C(33219), UINT16_C(50429), UINT16_C(49912),
      UINT16_C(60123), UINT16_C(18786), UINT16_C(39373), UINT16_C(  821), UINT16_C(43260), UINT16_C(47716), UINT16_C(64763), UINT16_C(59044),
      UINT16_C(49008), UINT16_C(34652), UINT16_C(14567), UINT16_C(27853), UINT16_C(37062), UINT16_C(50157), UINT16_C(58964), UINT16_C(12421),
      UINT16_C(59344), UINT16_C(40313), UINT16_C(44672), UINT16_C(32160), UINT16_C( 1110), UINT16_C(20791), UINT16_C(56064), UINT16_C(28983),
      UINT16_C(38043), UINT16_C(33528), UINT16_C(50636), UINT16_C(37615), UINT16_C(56405), UINT16_C(43605), UINT16_C(56002), UINT16_C(37594),
      UINT16_C(21442), UINT16_C(16943), UINT16_C(52994), UINT16_C(22719), UINT16_C(63188), UINT16_C(54442), UINT16_C(57810), UINT16_C(27973),
      UINT16_C(15989), UINT16_C(16879), UINT16_C(56835), UINT16_C(22995), UINT16_C(10427), UINT16_C(32003), UINT16_C(56579), UINT16_C(50448),
      UINT16_C(16176), UINT16_C(12807), UINT16_C(50959), UINT16_C(58251), UINT16_C(13757), UINT16_C(36791), UINT16_C(64790), UINT16_C(36092),
      UINT16_C(60475), UINT16_C(16077), UINT16_C(41418), UINT16_C(34199), UINT16_C(39625), UINT16_C(52227), UINT16_C( 4983), UINT16_C(43153),
      UINT16_C(39250), UINT16_C(25050), UINT16_C(25952), UINT16_C( 7492), UINT16_C(64666), UINT16_C(45485), UINT16_C(43513), UINT16_C(13373),
      UINT16_C( 2709), UINT16_C(24690), UINT16_C( 2731), UINT16_C(30181), UINT16_C(59556), UINT16_C( 7233), UINT16_C(54267), UINT16_C(20164),
      UINT16_C(40556), UINT16_C(52399), UINT16_C(62468), UINT16_C(40681), UINT16_C(38640), UINT16_C(59727), UINT16_C(35904), UINT16_C(54557),
      UINT16_C(36759), UINT16_C(16949), UINT16_C( 7065), UINT16_C(16055), UINT16_C(63747), UINT16_C(65370), UINT16_C( 7884), UINT16_C(14413),
      UINT16_C(64700), UINT16_C(49156), UINT16_C(60912), UINT16_C(57439), UINT16_C(44676), UINT16_C(50377), UINT16_C(58939), UINT16_C(53913),
      UINT16_C(53110), UINT16_C( 3860), UINT16_C(52458), UINT16_C(60749), UINT16_C(42949), UINT16_C(37356), UINT16_C(14789), UINT16_C(33481),
      UINT16_C(52534), UINT16_C( 9794), UINT16_C(41402), UINT16_C(15879), UINT16_C(53328), UINT16_C(35586), UINT16_C(40119), UINT16_C(11613),
      UINT16_C(29035), UINT16_C(21820), UINT16_C(35389), UINT16_C(  578), UINT16_C(12081), UINT16_C(63379), UINT16_C(23656), UINT16_C(40569),
      UINT16_C(47913), UINT16_C(58565), UINT16_C(52317), UINT16_C(44322), UINT16_C( 9628), UINT16_C(21304), UINT16_C(38337), UINT16_C(11392),
      UINT16_C(48390), UINT16_C(17537), UINT16_C(49991), UINT16_C(30790), UINT16_C(56050), UINT16_C(23407), UINT16_C(59446), UINT16_C(24825),
      UINT16_C(48804), UINT16_C(  324), UINT16_C(26250), UINT16_C(10158), UINT16_C(59019), UINT16_C(19578), UINT16_C(64379), UINT16_C(33144),
      UINT16_C(63928), UINT16_C(65477), UINT16_C( 3261), UINT16_C(44919), UINT16_C(59366), UINT16_C( 7178), UINT16_C( 1231), UINT16_C(29564) };
  static const uint16_t e[] =
    { UINT16_C(    0), UINT16_C(21159), UINT16_C(    0), UINT16_C(    0), UINT16_C(22730), UINT16_C(13441), UINT16_C(36400), UINT16_C(50143),
      UINT16_C( 9409), UINT16_C(    0), UINT16_C(25631), UINT16_C( 3568), UINT16_C(    0), UINT16_C(45607), UINT16_C(30150), UINT16_C(    0),
      UINT16_C(14725), UINT16_C(41941), UINT16_C(    0), UINT16_C(    0), UINT16_C(65241), UINT16_C( 2675), UINT16_C(    0), UINT16_C(20171),
      UINT16_C(    0), UINT16_C(38611), UINT16_C(    0), UINT16_C(15268), UINT16_C(52480), UINT16_C(50923), UINT16_C(    0), UINT16_C(    0),
      UINT16_C( 7859), UINT16_C(10345), UINT16_C(    0), UINT16_C(31078), UINT16_C(56037), UINT16_C(29315), UINT16_C(    0), UINT16_C(42176),
      UINT16_C(37927), UINT16_C(    0), UINT16_C(57431), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(47284),
      UINT16_C( 8068), UINT16_C(    0), UINT16_C(18181), UINT16_C(60575), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(39666),
      UINT16_C(11696), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(10407), UINT16_C(23779), UINT16_C(    0),
      UINT16_C(49787), UINT16_C(    0), UINT16_C(    0), UINT16_C(11117), UINT16_C(51792), UINT16_C(    0), UINT16_C(28392), UINT16_C(    0),
      UINT16_C(23450), UINT16_C(    0), UINT16_C(  501), UINT16_C( 6242), UINT16_C( 2431), UINT16_C(25409), UINT16_C(    0), UINT16_C(57803),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(38042), UINT16_C(33693), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(48724), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 5792), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(23238), UINT16_C(    0), UINT16_C(46378), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(49618), UINT16_C(    0), UINT16_C(48229), UINT16_C(    0), UINT16_C(37161), UINT16_C(61654),
      UINT16_C(28909), UINT16_C( 6207), UINT16_C(26917), UINT16_C(    0), UINT16_C(    0), UINT16_C(61368), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(25803), UINT16_C(    0), UINT16_C(    0), UINT16_C(35873), UINT16_C(48226), UINT16_C(    0), UINT16_C(    0), UINT16_C(15227),
      UINT16_C(    0), UINT16_C( 9298), UINT16_C(12324), UINT16_C(21905), UINT16_C(    0), UINT16_C(    0), UINT16_C(18665), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 6495), UINT16_C( 6193), UINT16_C(32931), UINT16_C(    0), UINT16_C(42170),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(37972), UINT16_C(39074), UINT16_C(    0), UINT16_C(    0), UINT16_C(36416),
      UINT16_C(38156), UINT16_C(50016), UINT16_C(49418), UINT16_C(15322), UINT16_C(32471), UINT16_C(31931), UINT16_C(30365), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(49529), UINT16_C(53055), UINT16_C(58196), UINT16_C(51301), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(52616), UINT16_C(17643), UINT16_C(35145), UINT16_C(27065), UINT16_C(    0),
      UINT16_C(31568), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(57077), UINT16_C(    0), UINT16_C(53934),
      UINT16_C(16638), UINT16_C(62240), UINT16_C(    0), UINT16_C(    0), UINT16_C( 2797), UINT16_C(    0), UINT16_C(    0), UINT16_C(50402),
      UINT16_C(57501), UINT16_C(    0), UINT16_C(50995), UINT16_C(19861), UINT16_C(35750), UINT16_C(13867), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(34404), UINT16_C(18595), UINT16_C(16971),
      UINT16_C(41000), UINT16_C(23591), UINT16_C(    0), UINT16_C( 3240), UINT16_C(54343), UINT16_C(40257), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(13937), UINT16_C(17551), UINT16_C(61502), UINT16_C(    0), UINT16_C(26223), UINT16_C(    0), UINT16_C( 9133), UINT16_C(    0),
      UINT16_C(31937), UINT16_C(    0), UINT16_C(    0), UINT16_C(33076), UINT16_C(30636), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(30367), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(11702), UINT16_C(60518), UINT16_C(    0), UINT16_C(52322), UINT16_C(    0), UINT16_C(    0), UINT16_C( 7252) };

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
    rv = simde_svadd_u16_z(pv, av, bv);

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

    ev = simde_svadd_u16_z(pv, av, bv);

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
test_simde_svadd_u16_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) };
  static const uint16_t a[] =
    { UINT16_C(53000), UINT16_C(42284), UINT16_C(24874), UINT16_C(45950), UINT16_C(10343), UINT16_C(64078), UINT16_C(43610), UINT16_C( 8560),
      UINT16_C(19410), UINT16_C(55711), UINT16_C(23801), UINT16_C(11583), UINT16_C(30959), UINT16_C(56677), UINT16_C(38572), UINT16_C(46329),
      UINT16_C( 9573), UINT16_C(36697), UINT16_C(55175), UINT16_C(60994), UINT16_C(36864), UINT16_C(23272), UINT16_C(22587), UINT16_C( 3451),
      UINT16_C( 7075), UINT16_C(40167), UINT16_C( 9847), UINT16_C(26314), UINT16_C(12190), UINT16_C(19011), UINT16_C(15813), UINT16_C(11006),
      UINT16_C(22626), UINT16_C(59833), UINT16_C(64303), UINT16_C(12248), UINT16_C(49291), UINT16_C(50826), UINT16_C( 1305), UINT16_C(48340),
      UINT16_C(47904), UINT16_C(38745), UINT16_C( 9185), UINT16_C(32766), UINT16_C(16722), UINT16_C( 6090), UINT16_C(51326), UINT16_C(57665),
      UINT16_C(64032), UINT16_C(20682), UINT16_C(41717), UINT16_C(32895), UINT16_C( 2403), UINT16_C(31815), UINT16_C( 6927), UINT16_C(12088),
      UINT16_C(37334), UINT16_C(47047), UINT16_C(50612), UINT16_C( 1590), UINT16_C(    6), UINT16_C(34077), UINT16_C(24265), UINT16_C(59750),
      UINT16_C(12376), UINT16_C(19769), UINT16_C(47571), UINT16_C(14030), UINT16_C( 5570), UINT16_C(53682), UINT16_C(59952), UINT16_C( 1537),
      UINT16_C(51324), UINT16_C(12477), UINT16_C(62349), UINT16_C(37687), UINT16_C(21748), UINT16_C(48408), UINT16_C(32435), UINT16_C( 2982),
      UINT16_C(57519), UINT16_C(33369), UINT16_C(10137), UINT16_C(23480), UINT16_C(27196), UINT16_C(27693), UINT16_C(11860), UINT16_C(53362),
      UINT16_C(12278), UINT16_C(33537), UINT16_C(14370), UINT16_C( 5654), UINT16_C(12172) };
  static const uint16_t b[] =
    { UINT16_C(22851), UINT16_C( 3153), UINT16_C(59397), UINT16_C(16547), UINT16_C(56316), UINT16_C(36688), UINT16_C(52098), UINT16_C(49824),
      UINT16_C(60099), UINT16_C(19674), UINT16_C(58675), UINT16_C(21558), UINT16_C(28314), UINT16_C(26495), UINT16_C(50746), UINT16_C(32180),
      UINT16_C( 1312), UINT16_C( 9609), UINT16_C(11501), UINT16_C(60005), UINT16_C(46600), UINT16_C(35449), UINT16_C( 6529), UINT16_C(17484),
      UINT16_C( 9732), UINT16_C(14225), UINT16_C(50955), UINT16_C(42379), UINT16_C( 2870), UINT16_C(28684), UINT16_C(49361), UINT16_C(61933),
      UINT16_C(30661), UINT16_C(45847), UINT16_C(31907), UINT16_C(43933), UINT16_C( 5682), UINT16_C(45877), UINT16_C(33072), UINT16_C(13560),
      UINT16_C(35240), UINT16_C(45931), UINT16_C(63312), UINT16_C(34393), UINT16_C(25858), UINT16_C(54262), UINT16_C(58406), UINT16_C(60357),
      UINT16_C(56411), UINT16_C(65182), UINT16_C(15192), UINT16_C(35754), UINT16_C(57170), UINT16_C(33342), UINT16_C(13921), UINT16_C( 2486),
      UINT16_C( 8639), UINT16_C( 4284), UINT16_C( 5400), UINT16_C( 6806), UINT16_C(36219), UINT16_C(41454), UINT16_C(45937), UINT16_C(52364),
      UINT16_C(11151), UINT16_C(59338), UINT16_C(29798), UINT16_C(47218), UINT16_C(45396), UINT16_C(46394), UINT16_C(61671), UINT16_C(42942),
      UINT16_C(31250), UINT16_C(10935), UINT16_C(19856), UINT16_C( 2885), UINT16_C(13274), UINT16_C(19372), UINT16_C(14566), UINT16_C(29975),
      UINT16_C(57955), UINT16_C(51804), UINT16_C(53078), UINT16_C(43650), UINT16_C(48512), UINT16_C(26463), UINT16_C( 7597), UINT16_C(48910),
      UINT16_C(50584), UINT16_C(10474), UINT16_C(12051), UINT16_C(60723), UINT16_C(57186) };
  static const uint16_t e[] =
    { UINT16_C(53000), UINT16_C(42284), UINT16_C(24874), UINT16_C(45950), UINT16_C( 1123), UINT16_C(35230), UINT16_C(30172), UINT16_C(58384),
      UINT16_C(19410), UINT16_C( 9849), UINT16_C(16940), UINT16_C(11583), UINT16_C(30959), UINT16_C(56677), UINT16_C(23782), UINT16_C(12973),
      UINT16_C( 9573), UINT16_C(36697), UINT16_C( 1140), UINT16_C(60994), UINT16_C(17928), UINT16_C(58721), UINT16_C(29116), UINT16_C( 3451),
      UINT16_C( 7075), UINT16_C(54392), UINT16_C(60802), UINT16_C( 3157), UINT16_C(12190), UINT16_C(19011), UINT16_C(15813), UINT16_C( 7403),
      UINT16_C(53287), UINT16_C(59833), UINT16_C(30674), UINT16_C(56181), UINT16_C(54973), UINT16_C(50826), UINT16_C(34377), UINT16_C(48340),
      UINT16_C(17608), UINT16_C(38745), UINT16_C( 6961), UINT16_C( 1623), UINT16_C(16722), UINT16_C( 6090), UINT16_C(44196), UINT16_C(57665),
      UINT16_C(54907), UINT16_C(20682), UINT16_C(56909), UINT16_C(32895), UINT16_C( 2403), UINT16_C(31815), UINT16_C( 6927), UINT16_C(12088),
      UINT16_C(45973), UINT16_C(51331), UINT16_C(50612), UINT16_C( 8396), UINT16_C(    6), UINT16_C(34077), UINT16_C( 4666), UINT16_C(46578),
      UINT16_C(23527), UINT16_C(13571), UINT16_C(11833), UINT16_C(14030), UINT16_C(50966), UINT16_C(53682), UINT16_C(56087), UINT16_C( 1537),
      UINT16_C(17038), UINT16_C(23412), UINT16_C(16669), UINT16_C(37687), UINT16_C(35022), UINT16_C(48408), UINT16_C(47001), UINT16_C(32957),
      UINT16_C(49938), UINT16_C(19637), UINT16_C(63215), UINT16_C( 1594), UINT16_C(27196), UINT16_C(27693), UINT16_C(11860), UINT16_C(36736),
      UINT16_C(62862), UINT16_C(44011), UINT16_C(26421), UINT16_C(  841), UINT16_C(12172) };

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
    rv = simde_svadd_u16_m(pv, av, bv);

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

    ev = simde_svadd_u16_m(pv, av, bv);

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
test_simde_svadd_u32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) };
  static const uint32_t a[] =
    { UINT32_C( 225603618), UINT32_C(2634496728), UINT32_C( 665283484), UINT32_C(1296986098), UINT32_C(2075574242), UINT32_C( 538237697), UINT32_C(1908626834), UINT32_C(1314414636),
      UINT32_C(2841430737), UINT32_C(2705810181), UINT32_C(3251236558), UINT32_C(1057888093), UINT32_C(3619341526), UINT32_C( 838389407), UINT32_C(1352907556), UINT32_C(3969907483),
      UINT32_C(3415669702), UINT32_C( 745332062), UINT32_C( 686634443), UINT32_C( 594017357), UINT32_C(1627070912), UINT32_C( 345109488), UINT32_C(3378787502), UINT32_C(4139123504),
      UINT32_C(1556172030), UINT32_C(4102630697), UINT32_C(2954655331), UINT32_C( 869499762), UINT32_C(2492714660), UINT32_C(1873290433), UINT32_C(2302217561), UINT32_C( 260042512),
      UINT32_C(1684750395), UINT32_C(3495490669), UINT32_C(3716183147), UINT32_C(2601538807), UINT32_C(3828392738), UINT32_C( 559143112), UINT32_C(4138372325), UINT32_C(3053791611),
      UINT32_C(3592056937), UINT32_C(3500634725), UINT32_C(3719112678), UINT32_C(2658778747), UINT32_C( 696428897), UINT32_C(1732957569), UINT32_C(3713922146), UINT32_C(2257871389),
      UINT32_C( 928886482), UINT32_C( 117900321), UINT32_C(2816849195), UINT32_C(3561315955), UINT32_C(2298398471), UINT32_C(4277094556), UINT32_C(1524386877), UINT32_C(2179035310),
      UINT32_C(1069039134), UINT32_C(1833418818), UINT32_C(3893636213), UINT32_C(2445040010), UINT32_C(3172579872), UINT32_C(1085999363), UINT32_C(  77240149), UINT32_C( 646281991),
      UINT32_C(4217716153), UINT32_C(1919528189), UINT32_C(1650097624), UINT32_C(4159903703), UINT32_C(3568569809), UINT32_C(1796501526), UINT32_C( 258977543), UINT32_C(3828741162),
      UINT32_C( 803183154), UINT32_C( 530729031), UINT32_C(2642607302), UINT32_C(3851711763), UINT32_C(2562279810), UINT32_C(3221540537), UINT32_C(2815390589), UINT32_C(2592801896),
      UINT32_C(3871959967), UINT32_C(2030398387), UINT32_C(2065074024), UINT32_C(2137041917), UINT32_C(2904038132), UINT32_C(1701649640), UINT32_C(4144774543), UINT32_C(3767638081),
      UINT32_C(3066452739), UINT32_C( 774950086), UINT32_C(1353336403), UINT32_C(3855616753), UINT32_C( 210954276), UINT32_C(2473656324), UINT32_C(2123071037), UINT32_C( 425663510),
      UINT32_C(1053762935), UINT32_C(1164771313), UINT32_C( 932517446), UINT32_C(1159554337), UINT32_C(1364373325), UINT32_C(3974480815), UINT32_C(1466658881), UINT32_C(  74500748),
      UINT32_C(3779215599), UINT32_C(2233904703), UINT32_C(3871194053), UINT32_C(1848367649), UINT32_C( 968916361), UINT32_C(2183505217) };
  static const uint32_t b[] =
    { UINT32_C(2428014534), UINT32_C(1849874788), UINT32_C(3247329166), UINT32_C(2014541224), UINT32_C(1123253709), UINT32_C(2218830145), UINT32_C(1907660690), UINT32_C(1812241830),
      UINT32_C(2449259564), UINT32_C( 620707477), UINT32_C( 921013645), UINT32_C(3501127683), UINT32_C(3054674293), UINT32_C(3711587147), UINT32_C(2421092330), UINT32_C(3120321420),
      UINT32_C(2773153807), UINT32_C(3301525815), UINT32_C(3657084630), UINT32_C( 464103590), UINT32_C(2513550410), UINT32_C(4185000719), UINT32_C(2274017786), UINT32_C( 591431188),
      UINT32_C(3066595967), UINT32_C(2843382227), UINT32_C(3850597695), UINT32_C(1728064541), UINT32_C(4160541160), UINT32_C(3622924253), UINT32_C(1147042608), UINT32_C(2154274305),
      UINT32_C(4214632488), UINT32_C(  27636161), UINT32_C(1139157030), UINT32_C(1034676052), UINT32_C(2503255992), UINT32_C(1181558038), UINT32_C(2727005088), UINT32_C(2451763818),
      UINT32_C(3817756962), UINT32_C( 820261642), UINT32_C(2943601499), UINT32_C(1793859250), UINT32_C(3690996166), UINT32_C(3877858630), UINT32_C(2726931768), UINT32_C(3241520031),
      UINT32_C( 245744388), UINT32_C(1363053046), UINT32_C( 100708948), UINT32_C(2524048848), UINT32_C(1416851726), UINT32_C( 373003998), UINT32_C(3820602435), UINT32_C(1956966000),
      UINT32_C(2810399153), UINT32_C( 670613971), UINT32_C(1143928947), UINT32_C(4091191269), UINT32_C(3997715728), UINT32_C( 654607331), UINT32_C(3087711560), UINT32_C(1546432171),
      UINT32_C(3406016504), UINT32_C(3841129329), UINT32_C(3643285748), UINT32_C(3486319551), UINT32_C( 884806992), UINT32_C(3764109976), UINT32_C( 731407743), UINT32_C( 193447187),
      UINT32_C(3856042868), UINT32_C(2060110214), UINT32_C(2840916713), UINT32_C(1182278133), UINT32_C(3464115766), UINT32_C(2008012280), UINT32_C(1302480698), UINT32_C(2170104332),
      UINT32_C( 996552629), UINT32_C(3803590904), UINT32_C( 411765283), UINT32_C(1633551147), UINT32_C( 825219129), UINT32_C(3886669485), UINT32_C( 842353446), UINT32_C( 716410485),
      UINT32_C(3060144829), UINT32_C(1838685258), UINT32_C(1367745318), UINT32_C(1622336550), UINT32_C(1787945405), UINT32_C(3864148672), UINT32_C(4212688774), UINT32_C(3525757973),
      UINT32_C( 814255334), UINT32_C(3466469544), UINT32_C(1780425795), UINT32_C(3318403336), UINT32_C(1915771826), UINT32_C( 475562646), UINT32_C( 504852745), UINT32_C( 602946877),
      UINT32_C(1901296073), UINT32_C(3711955353), UINT32_C( 507993621), UINT32_C(3806531887), UINT32_C(  39064428), UINT32_C(2652810645) };
  static const uint32_t e[] =
    { UINT32_C(         0), UINT32_C( 189404220), UINT32_C(         0), UINT32_C(         0), UINT32_C(3198827951), UINT32_C(         0), UINT32_C(3816287524), UINT32_C(3126656466),
      UINT32_C( 995723005), UINT32_C(         0), UINT32_C(4172250203), UINT32_C( 264048480), UINT32_C(2379048523), UINT32_C( 255009258), UINT32_C(3773999886), UINT32_C(2795261607),
      UINT32_C(         0), UINT32_C(4046857877), UINT32_C(         0), UINT32_C(         0), UINT32_C(4140621322), UINT32_C( 235142911), UINT32_C(1357837992), UINT32_C(         0),
      UINT32_C( 327800701), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(1201247390), UINT32_C(         0), UINT32_C(2414316817),
      UINT32_C(         0), UINT32_C(3523126830), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(1740701150), UINT32_C(         0), UINT32_C(1210588133),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 157670701), UINT32_C(         0), UINT32_C(         0), UINT32_C(2145886618), UINT32_C(1204424124),
      UINT32_C(1174630870), UINT32_C(         0), UINT32_C(2917558143), UINT32_C(         0), UINT32_C(         0), UINT32_C( 355131258), UINT32_C(1050022016), UINT32_C(         0),
      UINT32_C(3879438287), UINT32_C(         0), UINT32_C( 742597864), UINT32_C(         0), UINT32_C(         0), UINT32_C(1740606694), UINT32_C(         0), UINT32_C(2192714162),
      UINT32_C(3328765361), UINT32_C(1465690222), UINT32_C( 998416076), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 990385286), UINT32_C(4022188349),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(1188556719), UINT32_C(         0), UINT32_C(         0), UINT32_C( 934585521), UINT32_C(4117871287), UINT32_C(         0),
      UINT32_C( 573545300), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(3729257261), UINT32_C(1293351829), UINT32_C( 692160693), UINT32_C(         0),
      UINT32_C(1831630272), UINT32_C(         0), UINT32_C(         0), UINT32_C(1182986007), UINT32_C(         0), UINT32_C(2042837700), UINT32_C(2040792515), UINT32_C(         0),
      UINT32_C(         0), UINT32_C( 336273561), UINT32_C(2712943241), UINT32_C( 182990377), UINT32_C(3280145151), UINT32_C( 155076165), UINT32_C(1971511626), UINT32_C( 677447625),
      UINT32_C(         0), UINT32_C(1650892760), UINT32_C(  84220378), UINT32_C(         0), UINT32_C(1007980789), UINT32_C( 541348566) };

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
    rv = simde_svadd_u32_z(pv, av, bv);

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

    ev = simde_svadd_u32_z(pv, av, bv);

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
test_simde_svadd_u32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1) };
  static const uint32_t a[] =
    { UINT32_C( 925451156), UINT32_C(1193702020), UINT32_C(  32112220), UINT32_C(1258266447), UINT32_C(3841357683), UINT32_C(1138772879), UINT32_C( 233246600), UINT32_C(2250558193),
      UINT32_C(2461879566), UINT32_C( 467264447), UINT32_C( 823968737), UINT32_C(3598392162), UINT32_C( 582644114), UINT32_C(1147509436), UINT32_C(2605862057), UINT32_C( 622949911),
      UINT32_C(2193088195), UINT32_C(2728235457), UINT32_C(3067329108), UINT32_C(1754025941), UINT32_C(2106214080), UINT32_C(2327965664), UINT32_C(1394938684), UINT32_C(1282950793),
      UINT32_C(3855494948), UINT32_C( 344419520), UINT32_C(4224408358), UINT32_C(1784895402), UINT32_C(2129128862), UINT32_C( 419998173), UINT32_C(1181494716), UINT32_C(2542986355),
      UINT32_C(3564921107), UINT32_C(4092069069), UINT32_C( 166638431), UINT32_C(2842907147), UINT32_C( 472341311), UINT32_C(3224711172), UINT32_C(3506872669), UINT32_C(2573769093),
      UINT32_C(3345868282), UINT32_C(1220171241), UINT32_C( 340895753), UINT32_C( 985515258), UINT32_C( 592897055), UINT32_C(1927580692), UINT32_C(3007572525), UINT32_C(2102176643),
      UINT32_C(2034547088), UINT32_C( 398589454), UINT32_C(2703954599), UINT32_C(4141607127), UINT32_C(3776590541), UINT32_C(3948150462), UINT32_C(1822332648), UINT32_C(3538545218),
      UINT32_C(2991337123), UINT32_C(3553168684), UINT32_C(4151702816), UINT32_C(2867679453), UINT32_C(1082918786), UINT32_C(3995918085), UINT32_C(3092957814), UINT32_C(1485456309),
      UINT32_C(2651510385), UINT32_C(  74568932) };
  static const uint32_t b[] =
    { UINT32_C(3367447337), UINT32_C(2105189171), UINT32_C( 221261146), UINT32_C(3124261141), UINT32_C( 170245643), UINT32_C( 466410745), UINT32_C(1877303546), UINT32_C(3649593264),
      UINT32_C(3181461642), UINT32_C(1044061155), UINT32_C(1565223752), UINT32_C(3893920989), UINT32_C(1022508354), UINT32_C( 341294617), UINT32_C(3481484319), UINT32_C( 648547484),
      UINT32_C( 803490124), UINT32_C(2909609828), UINT32_C(1728756106), UINT32_C(2135892541), UINT32_C(2042315359), UINT32_C( 529339136), UINT32_C(3958247503), UINT32_C(1746048540),
      UINT32_C(1150875359), UINT32_C(2683372821), UINT32_C(4211604414), UINT32_C(2105234974), UINT32_C(2583049880), UINT32_C(2579006281), UINT32_C(2961483668), UINT32_C( 488216125),
      UINT32_C(2707534220), UINT32_C(1967215286), UINT32_C(1802520653), UINT32_C( 938077086), UINT32_C(1808850722), UINT32_C(4144269411), UINT32_C(1839696175), UINT32_C(2894774303),
      UINT32_C( 676195185), UINT32_C(2325581373), UINT32_C(1979059670), UINT32_C( 464314361), UINT32_C( 562461886), UINT32_C( 874023684), UINT32_C( 866238484), UINT32_C(4074711936),
      UINT32_C(1394224406), UINT32_C(2464004027), UINT32_C(3171406788), UINT32_C(1910027186), UINT32_C( 865230639), UINT32_C(4268207082), UINT32_C(3945859179), UINT32_C(1239224627),
      UINT32_C(4187813694), UINT32_C(1938520750), UINT32_C(   3183181), UINT32_C(1953564997), UINT32_C(1386742632), UINT32_C( 424677294), UINT32_C(1258651928), UINT32_C(3499483794),
      UINT32_C(2294952410), UINT32_C(4193998251) };
  static const uint32_t e[] =
    { UINT32_C( 925451156), UINT32_C(1193702020), UINT32_C( 253373366), UINT32_C(  87560292), UINT32_C(4011603326), UINT32_C(1138772879), UINT32_C( 233246600), UINT32_C(2250558193),
      UINT32_C(2461879566), UINT32_C( 467264447), UINT32_C(2389192489), UINT32_C(3197345855), UINT32_C(1605152468), UINT32_C(1147509436), UINT32_C(2605862057), UINT32_C(1271497395),
      UINT32_C(2996578319), UINT32_C(2728235457), UINT32_C(3067329108), UINT32_C(1754025941), UINT32_C(4148529439), UINT32_C(2327965664), UINT32_C(1394938684), UINT32_C(3028999333),
      UINT32_C(3855494948), UINT32_C( 344419520), UINT32_C(4224408358), UINT32_C(1784895402), UINT32_C(2129128862), UINT32_C( 419998173), UINT32_C(1181494716), UINT32_C(3031202480),
      UINT32_C(1977488031), UINT32_C(1764317059), UINT32_C(1969159084), UINT32_C(2842907147), UINT32_C( 472341311), UINT32_C(3224711172), UINT32_C(1051601548), UINT32_C(1173576100),
      UINT32_C(3345868282), UINT32_C(1220171241), UINT32_C( 340895753), UINT32_C(1449829619), UINT32_C( 592897055), UINT32_C(2801604376), UINT32_C(3873811009), UINT32_C(1881921283),
      UINT32_C(3428771494), UINT32_C( 398589454), UINT32_C(1580394091), UINT32_C(4141607127), UINT32_C( 346853884), UINT32_C(3921390248), UINT32_C(1473224531), UINT32_C(3538545218),
      UINT32_C(2991337123), UINT32_C(1196722138), UINT32_C(4151702816), UINT32_C(2867679453), UINT32_C(1082918786), UINT32_C(3995918085), UINT32_C(3092957814), UINT32_C(1485456309),
      UINT32_C(2651510385), UINT32_C(4268567183) };

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
    rv = simde_svadd_u32_m(pv, av, bv);

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

    ev = simde_svadd_u32_m(pv, av, bv);

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
test_simde_svadd_u64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1) };
  static const uint64_t a[] =
    { UINT64_C( 9864919644265682907), UINT64_C( 9857100339093995781), UINT64_C(12186612865632197616), UINT64_C( 8223520792087960600),
      UINT64_C(11103263784302565736), UINT64_C(10325040493072558905), UINT64_C( 2504605068071173956), UINT64_C( 7731378754957685570),
      UINT64_C(  930293297794653113), UINT64_C( 3776856461222414139), UINT64_C(15618782122289754261), UINT64_C( 2067711207240958530),
      UINT64_C(17867562837219191575), UINT64_C( 7962429945673794396), UINT64_C( 2169273615928642988), UINT64_C(16019326720366857169),
      UINT64_C( 7886575979291327679), UINT64_C( 3155679183082439555), UINT64_C( 8647060439679490054), UINT64_C( 4032969584090571602),
      UINT64_C(  231412566414508216), UINT64_C( 3319762230494359400), UINT64_C( 6350656045354876675), UINT64_C( 9449511663912996468),
      UINT64_C( 7110203024316618281), UINT64_C( 4163959620572351346), UINT64_C( 6789182944614537946), UINT64_C( 4260526273719871955),
      UINT64_C( 7107121048489061700), UINT64_C( 2308876865965517467), UINT64_C(14261274883899125153), UINT64_C(16586902163530396899),
      UINT64_C( 4558705659266536688), UINT64_C(12112179443843285168), UINT64_C( 3801352897933088777), UINT64_C(11014495891572204626),
      UINT64_C( 8597859622997983341), UINT64_C( 9704276969539855100), UINT64_C( 5774252434444705948), UINT64_C( 1415856125647342695),
      UINT64_C(15447194829962092321), UINT64_C(17139440490779430103), UINT64_C(  555348618913733990), UINT64_C( 4324225420390496842),
      UINT64_C( 8398232114233092059), UINT64_C( 5948873494036571728), UINT64_C(12874220581942618626), UINT64_C( 6394166425600245861),
      UINT64_C(13032179702743097803), UINT64_C( 5422584957519635457), UINT64_C(14296843463024309838), UINT64_C( 8659300228652206423),
      UINT64_C(15419687219616561892), UINT64_C( 9580285840635155040), UINT64_C(14997446876225790457), UINT64_C( 5751888833589569708),
      UINT64_C(14822635473206751754), UINT64_C( 8404396927339624423), UINT64_C( 3140680746731035724), UINT64_C( 1518370628607162968),
      UINT64_C( 2685174789080132104), UINT64_C( 8074643127291591200), UINT64_C( 2768530482650275265), UINT64_C( 5702960406002855941),
      UINT64_C(16215783037177501862), UINT64_C(17606693219464859074), UINT64_C( 6727428244094881127), UINT64_C(16799993701226792592),
      UINT64_C(13063773684098853545), UINT64_C(13280258031424948006), UINT64_C(12769475302706282881), UINT64_C(15977554541114008208),
      UINT64_C( 9818009239103703447), UINT64_C( 5864581514026605658), UINT64_C( 3134611562961719726), UINT64_C( 5481929355107895043),
      UINT64_C( 5200838358923107139), UINT64_C(16723367601705782771), UINT64_C(11776692712067514280), UINT64_C( 7584041049070857535),
      UINT64_C( 2269316323312801352), UINT64_C( 8029065771489653065), UINT64_C(11131247206855811895), UINT64_C( 9880841789576664207),
      UINT64_C(12839548584101621219), UINT64_C( 4748378448420213422), UINT64_C( 5312721138048669893), UINT64_C(17848078770670290919),
      UINT64_C( 6586011624753557579), UINT64_C(  185692384151051080), UINT64_C( 2833287808165260366), UINT64_C(13271828195491991331),
      UINT64_C(13005219710787925618), UINT64_C( 5813190555261619309), UINT64_C(14893027567624310342), UINT64_C( 8150730271638355704),
      UINT64_C(14523277961954691436) };
  static const uint64_t b[] =
    { UINT64_C( 9904336056805021741), UINT64_C(15623338082533682330), UINT64_C(  842221562232990584), UINT64_C(13456541887492485974),
      UINT64_C(10649393504830862101), UINT64_C(14049026634952608490), UINT64_C(10137288535534799510), UINT64_C( 2854245405398586709),
      UINT64_C(10416880527098734341), UINT64_C(12486414781587188540), UINT64_C(12787686763163253171), UINT64_C( 6776563226954107090),
      UINT64_C(16198863624869802903), UINT64_C(15608260411519303127), UINT64_C(13417411761137707560), UINT64_C(10374229726353934400),
      UINT64_C( 1775149706562524189), UINT64_C(16074650778350258454), UINT64_C( 5633606272208328331), UINT64_C(10801849034452028767),
      UINT64_C( 7173382417554060084), UINT64_C(13806264266948317698), UINT64_C(17575122262178331786), UINT64_C(16373455125232733997),
      UINT64_C(10202593288055722469), UINT64_C( 8388483075143054711), UINT64_C( 3054835812329692381), UINT64_C(14363960400436768708),
      UINT64_C(  770554873400373146), UINT64_C(13124086184398944453), UINT64_C(16780846676367060922), UINT64_C( 6044871632975802427),
      UINT64_C( 3602643774871166305), UINT64_C(10209663464719299617), UINT64_C(11402592415128016690), UINT64_C(12529469689970727381),
      UINT64_C(11752603385715644795), UINT64_C( 3294188493086849366), UINT64_C(17737358007207197478), UINT64_C(18038155105983127899),
      UINT64_C(17286499380385478591), UINT64_C(17806618101770978292), UINT64_C(13682964136198185163), UINT64_C(10233225973359470729),
      UINT64_C(15292171410123777455), UINT64_C(17005838625453330743), UINT64_C(12799437024794345857), UINT64_C( 7818457572338959396),
      UINT64_C( 4347921994389672098), UINT64_C( 8884271631544162621), UINT64_C(  333546614467470534), UINT64_C(13342607789910284802),
      UINT64_C(  650648975652413383), UINT64_C( 6350271817502379179), UINT64_C( 9131866816778829526), UINT64_C(17227226422632558914),
      UINT64_C(10023538188292345670), UINT64_C(  862808990574215694), UINT64_C( 7766594069895135438), UINT64_C(12845629996974540077),
      UINT64_C(14957543703789698599), UINT64_C(16401942805505623136), UINT64_C(  737735871539536297), UINT64_C(   79274626888172027),
      UINT64_C( 1887463142679239841), UINT64_C(12851107339237826657), UINT64_C( 8617286578185930415), UINT64_C( 4223804260365563329),
      UINT64_C(11864958908346705619), UINT64_C( 6136280551563876205), UINT64_C( 3308870758446574840), UINT64_C(10682651291056458094),
      UINT64_C( 1726227385732488204), UINT64_C( 8727332321445613090), UINT64_C(16644135960768872290), UINT64_C( 4032741651421906083),
      UINT64_C(  489339731717855497), UINT64_C( 8035806076400981898), UINT64_C(17242375648609923819), UINT64_C( 7809042064327456253),
      UINT64_C(16955464776134157923), UINT64_C(17491271799096613696), UINT64_C( 3542255054064319469), UINT64_C( 2928105864904145875),
      UINT64_C(16927832162251620766), UINT64_C( 5391642586970120921), UINT64_C(10977151104500115441), UINT64_C(  510437728728297511),
      UINT64_C( 2001553453369230641), UINT64_C(16536318380491931348), UINT64_C(15299398278597705972), UINT64_C(14015436861166592017),
      UINT64_C( 5672394208466339674), UINT64_C( 8519962227527169122), UINT64_C(13365700355504949244), UINT64_C( 7923436010177969570),
      UINT64_C( 6486242257476948794) };
  static const uint64_t e[] =
    { UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 3233318605870894958),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(10585624160356272279),
      UINT64_C(11347173824893387454), UINT64_C(16263271242809602679), UINT64_C( 9959724811743455816), UINT64_C( 8844274434195065620),
      UINT64_C(                   0), UINT64_C( 5123946283483545907), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(  783585887723146393), UINT64_C(14280666711887818385), UINT64_C(14834818618542600369),
      UINT64_C( 7404794983968568300), UINT64_C(17126026497442677098), UINT64_C(                   0), UINT64_C( 7376222715436178849),
      UINT64_C(17312796312372340750), UINT64_C(12552442695715406057), UINT64_C( 9844018756944230327), UINT64_C(  177742600447089047),
      UINT64_C( 7877675921889434846), UINT64_C(15432963050364461920), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C( 8161349434137702993), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 1007267157920918978),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(14557451393749967571),
      UINT64_C( 5243659450647317898), UINT64_C(                   0), UINT64_C( 7226913533027412867), UINT64_C(                   0),
      UINT64_C(17380101697132769901), UINT64_C(                   0), UINT64_C(14630390077491780372), UINT64_C(                   0),
      UINT64_C(16070336195268975275), UINT64_C(15930557658137534219), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 9267205917913840117), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(17642718492869830703), UINT64_C( 6029841859087662720), UINT64_C( 3506266354189811562), UINT64_C(                   0),
      UINT64_C(18103246179856741703), UINT64_C(12011056484993134115), UINT64_C(15344714822280811542), UINT64_C(                   0),
      UINT64_C( 6481988518736007548), UINT64_C(  969794509279272595), UINT64_C(16078346061152857721), UINT64_C( 8213461758460914686),
      UINT64_C(                   0), UINT64_C(14591913835472218748), UINT64_C( 1332003450021040400), UINT64_C(                   0),
      UINT64_C( 5690178090640962636), UINT64_C(                   0), UINT64_C(10572324286967886483), UINT64_C(15393083113398313788),
      UINT64_C(  778037025737407659), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(10140021035390334343), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(16722010764642982428), UINT64_C(18132686086762966338), UINT64_C( 8840520982949031732),
      UINT64_C(                   0), UINT64_C(14333152782788788431), UINT64_C( 9811983849419707970), UINT64_C(16074166281816325274),
      UINT64_C( 2562776145722088614) };

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
    rv = simde_svadd_u64_z(pv, av, bv);

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

    ev = simde_svadd_u64_z(pv, av, bv);

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
test_simde_svadd_u64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0) };
  static const uint64_t a[] =
    { UINT64_C( 6288789822871218078), UINT64_C(17154916021784781755), UINT64_C( 9999792570807748976), UINT64_C( 3880497143639265119),
      UINT64_C( 3337376729197457138), UINT64_C( 7316782545786139489), UINT64_C(16671997649927217527), UINT64_C( 2806137514732939301),
      UINT64_C( 9959551318695570069), UINT64_C( 8808391071981016291), UINT64_C( 5134292838729534674), UINT64_C(14694951145982643860),
      UINT64_C( 6850269137689906526), UINT64_C(13410722332905256863), UINT64_C(12333762986783304385), UINT64_C( 9233330456885407010),
      UINT64_C(11694185783216306030), UINT64_C(13254763263927025999), UINT64_C( 9046540175393031882), UINT64_C(14813175211596578545),
      UINT64_C(  113718853895756271), UINT64_C(  157673508509964419), UINT64_C( 9154250751128816178), UINT64_C(14454624992586031212),
      UINT64_C(15523994035809833406), UINT64_C(  531567509440080166), UINT64_C( 2114895982445740619) };
  static const uint64_t b[] =
    { UINT64_C( 8573630503263440407), UINT64_C(16190792396635524934), UINT64_C( 3671373956255707924), UINT64_C( 9354553028481076775),
      UINT64_C( 4149225870617693083), UINT64_C( 8581578729756697425), UINT64_C(15218436832011965655), UINT64_C(  358137778422832397),
      UINT64_C( 5968317347728261031), UINT64_C(13886744899690759645), UINT64_C( 5725185919296766965), UINT64_C(  125466761021095247),
      UINT64_C( 8652380924339282367), UINT64_C( 3611446260553784436), UINT64_C( 2343075570487844594), UINT64_C(14528496994774240067),
      UINT64_C( 2128968598365551224), UINT64_C(11936958708899791673), UINT64_C(  317607957973597047), UINT64_C( 5871921892438459049),
      UINT64_C(15943288743644170107), UINT64_C(14667375528027405364), UINT64_C( 7871584905909724791), UINT64_C(11234403133287423934),
      UINT64_C( 8225263136475729317), UINT64_C(17212165650451626685), UINT64_C( 3134052810281709900) };
  static const uint64_t e[] =
    { UINT64_C(14862420326134658485), UINT64_C(17154916021784781755), UINT64_C( 9999792570807748976), UINT64_C(13235050172120341894),
      UINT64_C( 7486602599815150221), UINT64_C(15898361275542836914), UINT64_C(13443690408229631566), UINT64_C( 3164275293155771698),
      UINT64_C(15927868666423831100), UINT64_C( 8808391071981016291), UINT64_C( 5134292838729534674), UINT64_C(14694951145982643860),
      UINT64_C(15502650062029188893), UINT64_C(13410722332905256863), UINT64_C(14676838557271148979), UINT64_C( 9233330456885407010),
      UINT64_C(13823154381581857254), UINT64_C( 6744977899117266056), UINT64_C( 9364148133366628929), UINT64_C(14813175211596578545),
      UINT64_C(16057007597539926378), UINT64_C(  157673508509964419), UINT64_C( 9154250751128816178), UINT64_C( 7242284052163903530),
      UINT64_C( 5302513098576011107), UINT64_C(  531567509440080166), UINT64_C( 2114895982445740619) };

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
    rv = simde_svadd_u64_m(pv, av, bv);

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

    ev = simde_svadd_u64_m(pv, av, bv);

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
test_simde_svadd_f32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0) };
  static const simde_float32 a[] =
    { SIMDE_FLOAT32_C(   570.54), SIMDE_FLOAT32_C(   320.87), SIMDE_FLOAT32_C(   703.29), SIMDE_FLOAT32_C(  -583.55),
      SIMDE_FLOAT32_C(   -40.68), SIMDE_FLOAT32_C(  -771.90), SIMDE_FLOAT32_C(  -624.45), SIMDE_FLOAT32_C(  -418.62),
      SIMDE_FLOAT32_C(  -342.79), SIMDE_FLOAT32_C(  -902.29), SIMDE_FLOAT32_C(   -40.10), SIMDE_FLOAT32_C(  -214.24),
      SIMDE_FLOAT32_C(   -66.44), SIMDE_FLOAT32_C(   766.13), SIMDE_FLOAT32_C(   189.56), SIMDE_FLOAT32_C(  -670.36),
      SIMDE_FLOAT32_C(  -300.11), SIMDE_FLOAT32_C(   405.33), SIMDE_FLOAT32_C(   434.25), SIMDE_FLOAT32_C(   830.27),
      SIMDE_FLOAT32_C(   -19.06), SIMDE_FLOAT32_C(   300.49), SIMDE_FLOAT32_C(  -841.78), SIMDE_FLOAT32_C(  -360.76),
      SIMDE_FLOAT32_C(  -995.84), SIMDE_FLOAT32_C(  -766.33), SIMDE_FLOAT32_C(   581.45), SIMDE_FLOAT32_C(  -828.44),
      SIMDE_FLOAT32_C(  -842.94), SIMDE_FLOAT32_C(  -687.68), SIMDE_FLOAT32_C(  -735.83), SIMDE_FLOAT32_C(   727.60),
      SIMDE_FLOAT32_C(   633.19), SIMDE_FLOAT32_C(   967.46), SIMDE_FLOAT32_C(  -855.96), SIMDE_FLOAT32_C(  -407.49),
      SIMDE_FLOAT32_C(  -804.44), SIMDE_FLOAT32_C(  -480.41), SIMDE_FLOAT32_C(   173.89), SIMDE_FLOAT32_C(  -147.23),
      SIMDE_FLOAT32_C(  -382.69), SIMDE_FLOAT32_C(  -866.21), SIMDE_FLOAT32_C(   638.54), SIMDE_FLOAT32_C(   550.86),
      SIMDE_FLOAT32_C(   899.92), SIMDE_FLOAT32_C(  -171.91), SIMDE_FLOAT32_C(   880.50), SIMDE_FLOAT32_C(  -400.19),
      SIMDE_FLOAT32_C(  -766.58), SIMDE_FLOAT32_C(   314.75), SIMDE_FLOAT32_C(  -569.92), SIMDE_FLOAT32_C(   214.35),
      SIMDE_FLOAT32_C(  -384.76), SIMDE_FLOAT32_C(  -411.70), SIMDE_FLOAT32_C(   853.60), SIMDE_FLOAT32_C(  -380.60),
      SIMDE_FLOAT32_C(  -178.03), SIMDE_FLOAT32_C(   435.05), SIMDE_FLOAT32_C(  -209.04), SIMDE_FLOAT32_C(   -20.97),
      SIMDE_FLOAT32_C(   747.37), SIMDE_FLOAT32_C(    55.13), SIMDE_FLOAT32_C(  -293.37), SIMDE_FLOAT32_C(   380.56),
      SIMDE_FLOAT32_C(    22.59), SIMDE_FLOAT32_C(  -149.32), SIMDE_FLOAT32_C(   973.08), SIMDE_FLOAT32_C(   218.15),
      SIMDE_FLOAT32_C(   370.27), SIMDE_FLOAT32_C(   146.97), SIMDE_FLOAT32_C(  -929.08), SIMDE_FLOAT32_C(   987.58),
      SIMDE_FLOAT32_C(   280.75), SIMDE_FLOAT32_C(   709.46), SIMDE_FLOAT32_C(   538.44), SIMDE_FLOAT32_C(   180.67),
      SIMDE_FLOAT32_C(  -462.45), SIMDE_FLOAT32_C(   418.94), SIMDE_FLOAT32_C(   780.48), SIMDE_FLOAT32_C(  -229.03),
      SIMDE_FLOAT32_C(  -266.31), SIMDE_FLOAT32_C(  -789.44), SIMDE_FLOAT32_C(   985.32), SIMDE_FLOAT32_C(   348.93),
      SIMDE_FLOAT32_C(  -201.14), SIMDE_FLOAT32_C(   838.92), SIMDE_FLOAT32_C(   968.33), SIMDE_FLOAT32_C(   620.83),
      SIMDE_FLOAT32_C(   273.97), SIMDE_FLOAT32_C(  -240.71), SIMDE_FLOAT32_C(  -400.14), SIMDE_FLOAT32_C(    21.34),
      SIMDE_FLOAT32_C(   814.42), SIMDE_FLOAT32_C(   306.49), SIMDE_FLOAT32_C(  -598.10), SIMDE_FLOAT32_C(  -162.99),
      SIMDE_FLOAT32_C(  -842.83), SIMDE_FLOAT32_C(  -625.02), SIMDE_FLOAT32_C(  -944.84), SIMDE_FLOAT32_C(   527.44),
      SIMDE_FLOAT32_C(   521.95), SIMDE_FLOAT32_C(  -873.92), SIMDE_FLOAT32_C(   515.01), SIMDE_FLOAT32_C(  -197.30),
      SIMDE_FLOAT32_C(   835.54), SIMDE_FLOAT32_C(    53.45), SIMDE_FLOAT32_C(   983.37), SIMDE_FLOAT32_C(  -626.91),
      SIMDE_FLOAT32_C(  -527.61), SIMDE_FLOAT32_C(   763.85), SIMDE_FLOAT32_C(   144.06), SIMDE_FLOAT32_C(   206.08),
      SIMDE_FLOAT32_C(   974.40), SIMDE_FLOAT32_C(   129.38), SIMDE_FLOAT32_C(  -444.99), SIMDE_FLOAT32_C(  -226.74),
      SIMDE_FLOAT32_C(   -31.70), SIMDE_FLOAT32_C(  -476.66), SIMDE_FLOAT32_C(  -605.91), SIMDE_FLOAT32_C(  -757.73),
      SIMDE_FLOAT32_C(   282.63), SIMDE_FLOAT32_C(    -6.06), SIMDE_FLOAT32_C(   263.61), SIMDE_FLOAT32_C(    97.05),
      SIMDE_FLOAT32_C(  -699.57), SIMDE_FLOAT32_C(   665.51), SIMDE_FLOAT32_C(   934.06), SIMDE_FLOAT32_C(  -542.40),
      SIMDE_FLOAT32_C(  -959.50), SIMDE_FLOAT32_C(   989.21), SIMDE_FLOAT32_C(   985.04), SIMDE_FLOAT32_C(   562.44),
      SIMDE_FLOAT32_C(  -884.70), SIMDE_FLOAT32_C(   500.05), SIMDE_FLOAT32_C(  -634.86), SIMDE_FLOAT32_C(   950.83),
      SIMDE_FLOAT32_C(  -446.50), SIMDE_FLOAT32_C(  -651.49), SIMDE_FLOAT32_C(  -676.07), SIMDE_FLOAT32_C(    25.89),
      SIMDE_FLOAT32_C(  -887.64), SIMDE_FLOAT32_C(   467.98), SIMDE_FLOAT32_C(  -768.03), SIMDE_FLOAT32_C(  -913.24),
      SIMDE_FLOAT32_C(  -402.63), SIMDE_FLOAT32_C(  -213.01), SIMDE_FLOAT32_C(  -139.98), SIMDE_FLOAT32_C(   565.67),
      SIMDE_FLOAT32_C(   310.33), SIMDE_FLOAT32_C(   254.11), SIMDE_FLOAT32_C(   807.94), SIMDE_FLOAT32_C(  -407.04),
      SIMDE_FLOAT32_C(  -751.94), SIMDE_FLOAT32_C(    71.54), SIMDE_FLOAT32_C(   690.00), SIMDE_FLOAT32_C(  -451.51),
      SIMDE_FLOAT32_C(  -262.94), SIMDE_FLOAT32_C(   624.06), SIMDE_FLOAT32_C(     6.09), SIMDE_FLOAT32_C(  -222.45),
      SIMDE_FLOAT32_C(   613.27), SIMDE_FLOAT32_C(    -8.87), SIMDE_FLOAT32_C(  -660.00), SIMDE_FLOAT32_C(   728.57),
      SIMDE_FLOAT32_C(  -508.82), SIMDE_FLOAT32_C(  -294.86), SIMDE_FLOAT32_C(   679.40), SIMDE_FLOAT32_C(    44.68),
      SIMDE_FLOAT32_C(    53.65), SIMDE_FLOAT32_C(  -996.67), SIMDE_FLOAT32_C(  -929.43), SIMDE_FLOAT32_C(   166.01),
      SIMDE_FLOAT32_C(   471.31), SIMDE_FLOAT32_C(  -697.46), SIMDE_FLOAT32_C(   252.78), SIMDE_FLOAT32_C(  -931.32),
      SIMDE_FLOAT32_C(    89.53), SIMDE_FLOAT32_C(  -887.20), SIMDE_FLOAT32_C(   634.35), SIMDE_FLOAT32_C(  -600.15),
      SIMDE_FLOAT32_C(   366.91), SIMDE_FLOAT32_C(   442.28), SIMDE_FLOAT32_C(    -7.19), SIMDE_FLOAT32_C(   614.97),
      SIMDE_FLOAT32_C(  -486.17), SIMDE_FLOAT32_C(  -317.18), SIMDE_FLOAT32_C(  -836.54), SIMDE_FLOAT32_C(   250.88),
      SIMDE_FLOAT32_C(  -693.13), SIMDE_FLOAT32_C(   169.55), SIMDE_FLOAT32_C(  -971.57), SIMDE_FLOAT32_C(   920.15),
      SIMDE_FLOAT32_C(  -839.32), SIMDE_FLOAT32_C(  -631.57), SIMDE_FLOAT32_C(   648.72), SIMDE_FLOAT32_C(  -348.14),
      SIMDE_FLOAT32_C(    73.57), SIMDE_FLOAT32_C(   328.12), SIMDE_FLOAT32_C(   696.53), SIMDE_FLOAT32_C(  -872.78),
      SIMDE_FLOAT32_C(   331.45), SIMDE_FLOAT32_C(   767.10), SIMDE_FLOAT32_C(   293.24), SIMDE_FLOAT32_C(  -197.24),
      SIMDE_FLOAT32_C(  -930.36), SIMDE_FLOAT32_C(  -453.98), SIMDE_FLOAT32_C(  -128.56), SIMDE_FLOAT32_C(   159.17),
      SIMDE_FLOAT32_C(  -341.18), SIMDE_FLOAT32_C(  -494.21), SIMDE_FLOAT32_C(   559.02), SIMDE_FLOAT32_C(  -974.27),
      SIMDE_FLOAT32_C(   948.07), SIMDE_FLOAT32_C(  -448.17), SIMDE_FLOAT32_C(   640.70), SIMDE_FLOAT32_C(  -538.11),
      SIMDE_FLOAT32_C(   234.65) };
  static const simde_float32 b[] =
    { SIMDE_FLOAT32_C(   804.16), SIMDE_FLOAT32_C(   712.78), SIMDE_FLOAT32_C(   541.52), SIMDE_FLOAT32_C(   -26.29),
      SIMDE_FLOAT32_C(   741.21), SIMDE_FLOAT32_C(   461.67), SIMDE_FLOAT32_C(   134.39), SIMDE_FLOAT32_C(  -890.36),
      SIMDE_FLOAT32_C(   110.39), SIMDE_FLOAT32_C(   786.24), SIMDE_FLOAT32_C(   183.21), SIMDE_FLOAT32_C(  -561.50),
      SIMDE_FLOAT32_C(   482.77), SIMDE_FLOAT32_C(   310.44), SIMDE_FLOAT32_C(   769.95), SIMDE_FLOAT32_C(   249.87),
      SIMDE_FLOAT32_C(  -396.32), SIMDE_FLOAT32_C(  -427.29), SIMDE_FLOAT32_C(   319.51), SIMDE_FLOAT32_C(   149.69),
      SIMDE_FLOAT32_C(   444.15), SIMDE_FLOAT32_C(  -521.32), SIMDE_FLOAT32_C(   808.51), SIMDE_FLOAT32_C(   949.94),
      SIMDE_FLOAT32_C(  -962.30), SIMDE_FLOAT32_C(   834.24), SIMDE_FLOAT32_C(   898.01), SIMDE_FLOAT32_C(  -410.47),
      SIMDE_FLOAT32_C(   474.93), SIMDE_FLOAT32_C(  -640.10), SIMDE_FLOAT32_C(   824.18), SIMDE_FLOAT32_C(   279.09),
      SIMDE_FLOAT32_C(  -927.33), SIMDE_FLOAT32_C(   365.70), SIMDE_FLOAT32_C(  -747.20), SIMDE_FLOAT32_C(   813.88),
      SIMDE_FLOAT32_C(  -172.63), SIMDE_FLOAT32_C(   387.19), SIMDE_FLOAT32_C(   923.52), SIMDE_FLOAT32_C(   937.76),
      SIMDE_FLOAT32_C(   173.43), SIMDE_FLOAT32_C(   106.74), SIMDE_FLOAT32_C(  -623.74), SIMDE_FLOAT32_C(  -343.80),
      SIMDE_FLOAT32_C(  -582.83), SIMDE_FLOAT32_C(  -853.79), SIMDE_FLOAT32_C(   906.08), SIMDE_FLOAT32_C(    20.85),
      SIMDE_FLOAT32_C(  -281.07), SIMDE_FLOAT32_C(   225.59), SIMDE_FLOAT32_C(  -829.46), SIMDE_FLOAT32_C(  -836.92),
      SIMDE_FLOAT32_C(   704.27), SIMDE_FLOAT32_C(   979.05), SIMDE_FLOAT32_C(  -886.98), SIMDE_FLOAT32_C(   741.97),
      SIMDE_FLOAT32_C(   813.28), SIMDE_FLOAT32_C(  -988.98), SIMDE_FLOAT32_C(  -668.50), SIMDE_FLOAT32_C(   288.22),
      SIMDE_FLOAT32_C(  -629.08), SIMDE_FLOAT32_C(  -844.32), SIMDE_FLOAT32_C(  -432.69), SIMDE_FLOAT32_C(  -556.40),
      SIMDE_FLOAT32_C(   521.39), SIMDE_FLOAT32_C(  -179.89), SIMDE_FLOAT32_C(  -742.52), SIMDE_FLOAT32_C(  -651.24),
      SIMDE_FLOAT32_C(  -792.70), SIMDE_FLOAT32_C(  -819.00), SIMDE_FLOAT32_C(  -713.48), SIMDE_FLOAT32_C(   380.73),
      SIMDE_FLOAT32_C(   287.74), SIMDE_FLOAT32_C(  -337.22), SIMDE_FLOAT32_C(  -963.07), SIMDE_FLOAT32_C(   704.92),
      SIMDE_FLOAT32_C(  -191.00), SIMDE_FLOAT32_C(   943.01), SIMDE_FLOAT32_C(  -274.23), SIMDE_FLOAT32_C(   527.92),
      SIMDE_FLOAT32_C(   168.60), SIMDE_FLOAT32_C(  -103.69), SIMDE_FLOAT32_C(   691.00), SIMDE_FLOAT32_C(  -127.13),
      SIMDE_FLOAT32_C(  -124.65), SIMDE_FLOAT32_C(   804.02), SIMDE_FLOAT32_C(  -385.16), SIMDE_FLOAT32_C(  -311.36),
      SIMDE_FLOAT32_C(   815.05), SIMDE_FLOAT32_C(   -53.66), SIMDE_FLOAT32_C(   976.86), SIMDE_FLOAT32_C(  -814.03),
      SIMDE_FLOAT32_C(   102.02), SIMDE_FLOAT32_C(  -455.83), SIMDE_FLOAT32_C(  -370.44), SIMDE_FLOAT32_C(  -376.59),
      SIMDE_FLOAT32_C(   364.28), SIMDE_FLOAT32_C(  -112.96), SIMDE_FLOAT32_C(   -27.83), SIMDE_FLOAT32_C(   571.58),
      SIMDE_FLOAT32_C(    68.05), SIMDE_FLOAT32_C(   258.69), SIMDE_FLOAT32_C(   -47.69), SIMDE_FLOAT32_C(  -644.21),
      SIMDE_FLOAT32_C(   921.48), SIMDE_FLOAT32_C(   -10.76), SIMDE_FLOAT32_C(  -939.30), SIMDE_FLOAT32_C(  -269.53),
      SIMDE_FLOAT32_C(   -67.75), SIMDE_FLOAT32_C(  -213.53), SIMDE_FLOAT32_C(  -741.60), SIMDE_FLOAT32_C(  -899.16),
      SIMDE_FLOAT32_C(   682.77), SIMDE_FLOAT32_C(   949.40), SIMDE_FLOAT32_C(   -26.29), SIMDE_FLOAT32_C(  -441.87),
      SIMDE_FLOAT32_C(   753.42), SIMDE_FLOAT32_C(   588.54), SIMDE_FLOAT32_C(   246.76), SIMDE_FLOAT32_C(   568.47),
      SIMDE_FLOAT32_C(  -465.12), SIMDE_FLOAT32_C(   223.62), SIMDE_FLOAT32_C(   754.44), SIMDE_FLOAT32_C(   636.91),
      SIMDE_FLOAT32_C(   767.79), SIMDE_FLOAT32_C(  -616.00), SIMDE_FLOAT32_C(  -739.68), SIMDE_FLOAT32_C(   132.07),
      SIMDE_FLOAT32_C(   271.04), SIMDE_FLOAT32_C(   232.49), SIMDE_FLOAT32_C(  -296.35), SIMDE_FLOAT32_C(  -660.91),
      SIMDE_FLOAT32_C(  -508.82), SIMDE_FLOAT32_C(   655.95), SIMDE_FLOAT32_C(  -305.13), SIMDE_FLOAT32_C(  -587.34),
      SIMDE_FLOAT32_C(  -354.81), SIMDE_FLOAT32_C(  -244.42), SIMDE_FLOAT32_C(   143.13), SIMDE_FLOAT32_C(   577.44),
      SIMDE_FLOAT32_C(   542.04), SIMDE_FLOAT32_C(   401.53), SIMDE_FLOAT32_C(   678.28), SIMDE_FLOAT32_C(   224.82),
      SIMDE_FLOAT32_C(   350.93), SIMDE_FLOAT32_C(  -348.01), SIMDE_FLOAT32_C(   782.94), SIMDE_FLOAT32_C(   104.35),
      SIMDE_FLOAT32_C(  -759.47), SIMDE_FLOAT32_C(    29.71), SIMDE_FLOAT32_C(  -327.17), SIMDE_FLOAT32_C(  -224.58),
      SIMDE_FLOAT32_C(  -746.67), SIMDE_FLOAT32_C(  -572.74), SIMDE_FLOAT32_C(  -587.68), SIMDE_FLOAT32_C(  -978.88),
      SIMDE_FLOAT32_C(  -188.74), SIMDE_FLOAT32_C(  -327.36), SIMDE_FLOAT32_C(   153.19), SIMDE_FLOAT32_C(  -917.69),
      SIMDE_FLOAT32_C(   905.13), SIMDE_FLOAT32_C(   856.83), SIMDE_FLOAT32_C(  -578.61), SIMDE_FLOAT32_C(  -603.68),
      SIMDE_FLOAT32_C(   512.79), SIMDE_FLOAT32_C(   116.27), SIMDE_FLOAT32_C(  -191.03), SIMDE_FLOAT32_C(  -842.03),
      SIMDE_FLOAT32_C(   871.84), SIMDE_FLOAT32_C(   952.11), SIMDE_FLOAT32_C(   735.41), SIMDE_FLOAT32_C(   413.89),
      SIMDE_FLOAT32_C(   353.63), SIMDE_FLOAT32_C(   413.69), SIMDE_FLOAT32_C(  -361.30), SIMDE_FLOAT32_C(  -295.44),
      SIMDE_FLOAT32_C(  -934.32), SIMDE_FLOAT32_C(  -578.35), SIMDE_FLOAT32_C(   808.92), SIMDE_FLOAT32_C(  -693.79),
      SIMDE_FLOAT32_C(   451.35), SIMDE_FLOAT32_C(  -518.26), SIMDE_FLOAT32_C(    81.63), SIMDE_FLOAT32_C(   704.68),
      SIMDE_FLOAT32_C(   -90.99), SIMDE_FLOAT32_C(   493.95), SIMDE_FLOAT32_C(   725.80), SIMDE_FLOAT32_C(   720.27),
      SIMDE_FLOAT32_C(  -833.41), SIMDE_FLOAT32_C(  -121.01), SIMDE_FLOAT32_C(   802.58), SIMDE_FLOAT32_C(  -928.27),
      SIMDE_FLOAT32_C(  -264.17), SIMDE_FLOAT32_C(  -776.03), SIMDE_FLOAT32_C(  -531.96), SIMDE_FLOAT32_C(  -751.39),
      SIMDE_FLOAT32_C(   340.24), SIMDE_FLOAT32_C(   277.02), SIMDE_FLOAT32_C(  -593.41), SIMDE_FLOAT32_C(   212.08),
      SIMDE_FLOAT32_C(   229.12), SIMDE_FLOAT32_C(  -858.01), SIMDE_FLOAT32_C(  -374.03), SIMDE_FLOAT32_C(  -417.24),
      SIMDE_FLOAT32_C(   555.68), SIMDE_FLOAT32_C(   264.68), SIMDE_FLOAT32_C(   287.32), SIMDE_FLOAT32_C(   621.36),
      SIMDE_FLOAT32_C(   686.32), SIMDE_FLOAT32_C(    96.24), SIMDE_FLOAT32_C(   927.57), SIMDE_FLOAT32_C(   137.68),
      SIMDE_FLOAT32_C(   577.98), SIMDE_FLOAT32_C(     9.20), SIMDE_FLOAT32_C(  -157.64), SIMDE_FLOAT32_C(  -513.01),
      SIMDE_FLOAT32_C(  -496.84) };
  static const simde_float32 e[] =
    { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1244.81), SIMDE_FLOAT32_C(  -609.84),
      SIMDE_FLOAT32_C(   700.53), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -490.06), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   143.11), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   416.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -21.96), SIMDE_FLOAT32_C(   753.76), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   425.09), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   589.18),
      SIMDE_FLOAT32_C( -1958.14), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1479.46), SIMDE_FLOAT32_C( -1238.91),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1327.78), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -294.14), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1603.16), SIMDE_FLOAT32_C(   406.39),
      SIMDE_FLOAT32_C(  -977.07), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1097.41), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -209.26), SIMDE_FLOAT32_C(  -759.47), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   207.06),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1025.70), SIMDE_FLOAT32_C(  1786.58), SIMDE_FLOAT32_C(  -379.34),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   540.34), SIMDE_FLOAT32_C( -1399.38), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   361.37),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -789.19), SIMDE_FLOAT32_C(  -726.06), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   543.98), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -672.03), SIMDE_FLOAT32_C( -1642.56), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   568.49), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   885.59),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -893.13), SIMDE_FLOAT32_C(  1676.32), SIMDE_FLOAT32_C(   221.80),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1642.94), SIMDE_FLOAT32_C(   583.17), SIMDE_FLOAT32_C(   309.47),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -294.37), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -149.34), SIMDE_FLOAT32_C(  -968.54), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -972.67), SIMDE_FLOAT32_C(  1099.02),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -615.23), SIMDE_FLOAT32_C(   467.32), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    42.69), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -896.44),
      SIMDE_FLOAT32_C(  -595.36), SIMDE_FLOAT32_C(   550.32), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  1657.17), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -471.28), SIMDE_FLOAT32_C(  -668.61),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   111.88), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -182.49), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   733.96),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -410.33),
      SIMDE_FLOAT32_C(  -688.46), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -98.47),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -939.99), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -801.31), SIMDE_FLOAT32_C(  -895.91), SIMDE_FLOAT32_C(  -532.94), SIMDE_FLOAT32_C(   603.33),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -89.75), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   642.96), SIMDE_FLOAT32_C(   670.02),
      SIMDE_FLOAT32_C(  -449.14), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1430.39),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   296.70), SIMDE_FLOAT32_C(   159.28), SIMDE_FLOAT32_C( -1140.14),
      SIMDE_FLOAT32_C(  1518.40), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1238.61), SIMDE_FLOAT32_C(   124.89),
      SIMDE_FLOAT32_C(     3.97), SIMDE_FLOAT32_C(  -178.59), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -797.35),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -44.56), SIMDE_FLOAT32_C(  -194.02), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   824.94), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -108.52), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -844.79), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    74.44), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   176.77), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -168.99), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   116.76), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   413.81), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   103.12), SIMDE_FLOAT32_C(  -660.70),
      SIMDE_FLOAT32_C(   560.57), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -80.79), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -374.68), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   158.76), SIMDE_FLOAT32_C(   780.53),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -397.97), SIMDE_FLOAT32_C(  1486.59), SIMDE_FLOAT32_C(  -836.59),
      SIMDE_FLOAT32_C(  1526.05), SIMDE_FLOAT32_C(  -438.97), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
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
    rv = simde_svadd_f32_z(pv, av, bv);

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

    ev = simde_svadd_f32_z(pv, av, bv);

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
test_simde_svadd_f32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1) };
  static const simde_float32 a[] =
    { SIMDE_FLOAT32_C(  -663.70), SIMDE_FLOAT32_C(    35.12), SIMDE_FLOAT32_C(   599.74), SIMDE_FLOAT32_C(  -118.37),
      SIMDE_FLOAT32_C(  -227.34), SIMDE_FLOAT32_C(   663.04), SIMDE_FLOAT32_C(   217.80), SIMDE_FLOAT32_C(  -118.38),
      SIMDE_FLOAT32_C(  -638.99), SIMDE_FLOAT32_C(  -930.05), SIMDE_FLOAT32_C(  -483.76), SIMDE_FLOAT32_C(   720.35),
      SIMDE_FLOAT32_C(   466.58), SIMDE_FLOAT32_C(  -206.72), SIMDE_FLOAT32_C(   810.08), SIMDE_FLOAT32_C(  -277.58),
      SIMDE_FLOAT32_C(    94.69), SIMDE_FLOAT32_C(   741.76), SIMDE_FLOAT32_C(    30.15), SIMDE_FLOAT32_C(  -755.01),
      SIMDE_FLOAT32_C(   134.31), SIMDE_FLOAT32_C(  -574.60), SIMDE_FLOAT32_C(  -686.22), SIMDE_FLOAT32_C(  -217.20),
      SIMDE_FLOAT32_C(  -647.51), SIMDE_FLOAT32_C(  -584.72), SIMDE_FLOAT32_C(   974.25), SIMDE_FLOAT32_C(  -864.07),
      SIMDE_FLOAT32_C(   220.34), SIMDE_FLOAT32_C(   590.35), SIMDE_FLOAT32_C(   357.96), SIMDE_FLOAT32_C(   556.64),
      SIMDE_FLOAT32_C(  -374.53), SIMDE_FLOAT32_C(   -42.30), SIMDE_FLOAT32_C(  -561.72), SIMDE_FLOAT32_C(   398.13),
      SIMDE_FLOAT32_C(  -379.26), SIMDE_FLOAT32_C(   656.08), SIMDE_FLOAT32_C(  -720.24), SIMDE_FLOAT32_C(   -18.26),
      SIMDE_FLOAT32_C(   726.03), SIMDE_FLOAT32_C(  -204.00), SIMDE_FLOAT32_C(  -297.91), SIMDE_FLOAT32_C(   192.62),
      SIMDE_FLOAT32_C(   589.28), SIMDE_FLOAT32_C(  -487.83), SIMDE_FLOAT32_C(   915.04), SIMDE_FLOAT32_C(  -316.03),
      SIMDE_FLOAT32_C(  -746.07), SIMDE_FLOAT32_C(   -54.81), SIMDE_FLOAT32_C(   -71.04), SIMDE_FLOAT32_C(   388.25),
      SIMDE_FLOAT32_C(   370.59), SIMDE_FLOAT32_C(   242.74), SIMDE_FLOAT32_C(  -828.95), SIMDE_FLOAT32_C(   723.08),
      SIMDE_FLOAT32_C(   658.02), SIMDE_FLOAT32_C(  -854.70), SIMDE_FLOAT32_C(   859.01), SIMDE_FLOAT32_C(  -121.64),
      SIMDE_FLOAT32_C(   735.66), SIMDE_FLOAT32_C(   216.97), SIMDE_FLOAT32_C(  -564.99), SIMDE_FLOAT32_C(  -638.87),
      SIMDE_FLOAT32_C(  -825.33), SIMDE_FLOAT32_C(  -126.71), SIMDE_FLOAT32_C(   759.26), SIMDE_FLOAT32_C(  -204.59),
      SIMDE_FLOAT32_C(  -470.63), SIMDE_FLOAT32_C(  -960.98), SIMDE_FLOAT32_C(   777.16), SIMDE_FLOAT32_C(  -744.60),
      SIMDE_FLOAT32_C(  -164.98), SIMDE_FLOAT32_C(  -520.75), SIMDE_FLOAT32_C(   448.02), SIMDE_FLOAT32_C(  -575.70),
      SIMDE_FLOAT32_C(    -8.58), SIMDE_FLOAT32_C(   363.06), SIMDE_FLOAT32_C(   108.27), SIMDE_FLOAT32_C(   245.35),
      SIMDE_FLOAT32_C(  -691.75), SIMDE_FLOAT32_C(  -962.76), SIMDE_FLOAT32_C(  -366.40), SIMDE_FLOAT32_C(   678.85),
      SIMDE_FLOAT32_C(   279.98), SIMDE_FLOAT32_C(  -195.35), SIMDE_FLOAT32_C(   401.93), SIMDE_FLOAT32_C(   -62.00),
      SIMDE_FLOAT32_C(   -50.05), SIMDE_FLOAT32_C(   260.94), SIMDE_FLOAT32_C(   816.36), SIMDE_FLOAT32_C(  -314.39),
      SIMDE_FLOAT32_C(  -522.09), SIMDE_FLOAT32_C(  -748.63), SIMDE_FLOAT32_C(    46.74), SIMDE_FLOAT32_C(  -347.41),
      SIMDE_FLOAT32_C(   124.66), SIMDE_FLOAT32_C(  -194.00), SIMDE_FLOAT32_C(   448.00), SIMDE_FLOAT32_C(   654.03),
      SIMDE_FLOAT32_C(  -154.98), SIMDE_FLOAT32_C(   225.16), SIMDE_FLOAT32_C(   909.43), SIMDE_FLOAT32_C(   680.04),
      SIMDE_FLOAT32_C(   704.41), SIMDE_FLOAT32_C(   357.46), SIMDE_FLOAT32_C(  -895.66), SIMDE_FLOAT32_C(  -304.17),
      SIMDE_FLOAT32_C(  -279.48), SIMDE_FLOAT32_C(   212.61), SIMDE_FLOAT32_C(   941.18), SIMDE_FLOAT32_C(    28.78),
      SIMDE_FLOAT32_C(   249.85), SIMDE_FLOAT32_C(  -425.21), SIMDE_FLOAT32_C(  -292.38), SIMDE_FLOAT32_C(  -470.17),
      SIMDE_FLOAT32_C(   379.44), SIMDE_FLOAT32_C(  -890.45), SIMDE_FLOAT32_C(   467.83), SIMDE_FLOAT32_C(  -670.61),
      SIMDE_FLOAT32_C(   370.49), SIMDE_FLOAT32_C(   284.19), SIMDE_FLOAT32_C(    15.00), SIMDE_FLOAT32_C(   848.40),
      SIMDE_FLOAT32_C(   535.57), SIMDE_FLOAT32_C(  -938.26), SIMDE_FLOAT32_C(  -499.01), SIMDE_FLOAT32_C(  -339.77),
      SIMDE_FLOAT32_C(  -132.27), SIMDE_FLOAT32_C(   948.99), SIMDE_FLOAT32_C(  -685.74), SIMDE_FLOAT32_C(   712.75),
      SIMDE_FLOAT32_C(   174.15), SIMDE_FLOAT32_C(  -776.31), SIMDE_FLOAT32_C(   392.79), SIMDE_FLOAT32_C(  -121.44),
      SIMDE_FLOAT32_C(   581.15), SIMDE_FLOAT32_C(   497.13), SIMDE_FLOAT32_C(   574.39), SIMDE_FLOAT32_C(  -698.33),
      SIMDE_FLOAT32_C(  -290.26), SIMDE_FLOAT32_C(   515.57), SIMDE_FLOAT32_C(   330.45), SIMDE_FLOAT32_C(   959.59),
      SIMDE_FLOAT32_C(  -909.64), SIMDE_FLOAT32_C(  -961.93), SIMDE_FLOAT32_C(  -510.59), SIMDE_FLOAT32_C(   469.79),
      SIMDE_FLOAT32_C(  -852.38), SIMDE_FLOAT32_C(   957.24), SIMDE_FLOAT32_C(   799.18), SIMDE_FLOAT32_C(   518.11),
      SIMDE_FLOAT32_C(   241.43), SIMDE_FLOAT32_C(  -185.82), SIMDE_FLOAT32_C(   366.51), SIMDE_FLOAT32_C(  -223.00),
      SIMDE_FLOAT32_C(  -124.08), SIMDE_FLOAT32_C(   867.50), SIMDE_FLOAT32_C(   437.23), SIMDE_FLOAT32_C(   743.65),
      SIMDE_FLOAT32_C(   816.49), SIMDE_FLOAT32_C(   751.48), SIMDE_FLOAT32_C(   456.40), SIMDE_FLOAT32_C(    -9.36),
      SIMDE_FLOAT32_C(   975.18), SIMDE_FLOAT32_C(  -150.81), SIMDE_FLOAT32_C(   869.20), SIMDE_FLOAT32_C(   556.33),
      SIMDE_FLOAT32_C(  -653.69), SIMDE_FLOAT32_C(   443.59), SIMDE_FLOAT32_C(   858.00), SIMDE_FLOAT32_C(    56.05),
      SIMDE_FLOAT32_C(   -40.84), SIMDE_FLOAT32_C(   188.44), SIMDE_FLOAT32_C(    15.64), SIMDE_FLOAT32_C(    49.51),
      SIMDE_FLOAT32_C(   226.51) };
  static const simde_float32 b[] =
    { SIMDE_FLOAT32_C(   505.06), SIMDE_FLOAT32_C(  -480.69), SIMDE_FLOAT32_C(   374.13), SIMDE_FLOAT32_C(   462.30),
      SIMDE_FLOAT32_C(  -681.51), SIMDE_FLOAT32_C(  -107.77), SIMDE_FLOAT32_C(  -296.27), SIMDE_FLOAT32_C(   132.67),
      SIMDE_FLOAT32_C(  -741.26), SIMDE_FLOAT32_C(   480.73), SIMDE_FLOAT32_C(  -991.41), SIMDE_FLOAT32_C(  -873.76),
      SIMDE_FLOAT32_C(   -82.04), SIMDE_FLOAT32_C(   752.25), SIMDE_FLOAT32_C(   942.74), SIMDE_FLOAT32_C(  -330.56),
      SIMDE_FLOAT32_C(   208.65), SIMDE_FLOAT32_C(   -66.62), SIMDE_FLOAT32_C(  -355.39), SIMDE_FLOAT32_C(  -942.17),
      SIMDE_FLOAT32_C(  -197.42), SIMDE_FLOAT32_C(  -799.06), SIMDE_FLOAT32_C(  -595.85), SIMDE_FLOAT32_C(  -753.83),
      SIMDE_FLOAT32_C(  -941.06), SIMDE_FLOAT32_C(   460.20), SIMDE_FLOAT32_C(   205.32), SIMDE_FLOAT32_C(   247.38),
      SIMDE_FLOAT32_C(  -524.16), SIMDE_FLOAT32_C(  -745.16), SIMDE_FLOAT32_C(  -526.11), SIMDE_FLOAT32_C(   980.90),
      SIMDE_FLOAT32_C(  -225.86), SIMDE_FLOAT32_C(   848.01), SIMDE_FLOAT32_C(   443.19), SIMDE_FLOAT32_C(    92.63),
      SIMDE_FLOAT32_C(  -259.75), SIMDE_FLOAT32_C(  -853.08), SIMDE_FLOAT32_C(  -774.70), SIMDE_FLOAT32_C(    -1.01),
      SIMDE_FLOAT32_C(   627.65), SIMDE_FLOAT32_C(  -766.11), SIMDE_FLOAT32_C(   125.23), SIMDE_FLOAT32_C(  -454.39),
      SIMDE_FLOAT32_C(   986.14), SIMDE_FLOAT32_C(    67.97), SIMDE_FLOAT32_C(   215.05), SIMDE_FLOAT32_C(   194.79),
      SIMDE_FLOAT32_C(  -998.65), SIMDE_FLOAT32_C(   859.66), SIMDE_FLOAT32_C(   252.62), SIMDE_FLOAT32_C(  -196.07),
      SIMDE_FLOAT32_C(  -939.40), SIMDE_FLOAT32_C(   656.77), SIMDE_FLOAT32_C(    50.09), SIMDE_FLOAT32_C(  -880.46),
      SIMDE_FLOAT32_C(   116.97), SIMDE_FLOAT32_C(  -744.59), SIMDE_FLOAT32_C(   366.92), SIMDE_FLOAT32_C(   592.81),
      SIMDE_FLOAT32_C(  -489.75), SIMDE_FLOAT32_C(   840.81), SIMDE_FLOAT32_C(   573.70), SIMDE_FLOAT32_C(   284.39),
      SIMDE_FLOAT32_C(   688.82), SIMDE_FLOAT32_C(    16.90), SIMDE_FLOAT32_C(  -622.98), SIMDE_FLOAT32_C(  -570.93),
      SIMDE_FLOAT32_C(   163.82), SIMDE_FLOAT32_C(  -397.68), SIMDE_FLOAT32_C(   428.05), SIMDE_FLOAT32_C(  -208.52),
      SIMDE_FLOAT32_C(  -163.78), SIMDE_FLOAT32_C(  -446.72), SIMDE_FLOAT32_C(   337.08), SIMDE_FLOAT32_C(  -177.64),
      SIMDE_FLOAT32_C(   621.25), SIMDE_FLOAT32_C(  -447.87), SIMDE_FLOAT32_C(  -982.86), SIMDE_FLOAT32_C(   622.60),
      SIMDE_FLOAT32_C(  -588.21), SIMDE_FLOAT32_C(   269.77), SIMDE_FLOAT32_C(  -573.48), SIMDE_FLOAT32_C(  -527.60),
      SIMDE_FLOAT32_C(   -73.47), SIMDE_FLOAT32_C(   476.61), SIMDE_FLOAT32_C(  -408.07), SIMDE_FLOAT32_C(  -956.50),
      SIMDE_FLOAT32_C(   732.03), SIMDE_FLOAT32_C(   958.85), SIMDE_FLOAT32_C(   636.31), SIMDE_FLOAT32_C(  -757.72),
      SIMDE_FLOAT32_C(   799.66), SIMDE_FLOAT32_C(   210.01), SIMDE_FLOAT32_C(   526.67), SIMDE_FLOAT32_C(   488.48),
      SIMDE_FLOAT32_C(  -773.09), SIMDE_FLOAT32_C(   903.69), SIMDE_FLOAT32_C(   917.54), SIMDE_FLOAT32_C(   390.73),
      SIMDE_FLOAT32_C(  -493.98), SIMDE_FLOAT32_C(   345.60), SIMDE_FLOAT32_C(  -817.79), SIMDE_FLOAT32_C(   342.23),
      SIMDE_FLOAT32_C(   898.88), SIMDE_FLOAT32_C(   519.29), SIMDE_FLOAT32_C(  -835.41), SIMDE_FLOAT32_C(   520.13),
      SIMDE_FLOAT32_C(  -928.58), SIMDE_FLOAT32_C(  -818.26), SIMDE_FLOAT32_C(   142.73), SIMDE_FLOAT32_C(  -516.78),
      SIMDE_FLOAT32_C(   451.50), SIMDE_FLOAT32_C(   569.25), SIMDE_FLOAT32_C(   -44.39), SIMDE_FLOAT32_C(  -621.97),
      SIMDE_FLOAT32_C(    45.87), SIMDE_FLOAT32_C(   547.55), SIMDE_FLOAT32_C(  -578.46), SIMDE_FLOAT32_C(  -222.10),
      SIMDE_FLOAT32_C(   506.40), SIMDE_FLOAT32_C(  -942.16), SIMDE_FLOAT32_C(    20.17), SIMDE_FLOAT32_C(   306.06),
      SIMDE_FLOAT32_C(   267.86), SIMDE_FLOAT32_C(  -453.16), SIMDE_FLOAT32_C(  -205.47), SIMDE_FLOAT32_C(   494.77),
      SIMDE_FLOAT32_C(  -549.46), SIMDE_FLOAT32_C(  -287.92), SIMDE_FLOAT32_C(  -114.50), SIMDE_FLOAT32_C(   -43.45),
      SIMDE_FLOAT32_C(  -942.33), SIMDE_FLOAT32_C(    67.71), SIMDE_FLOAT32_C(  -701.21), SIMDE_FLOAT32_C(   956.56),
      SIMDE_FLOAT32_C(  -413.00), SIMDE_FLOAT32_C(  -536.62), SIMDE_FLOAT32_C(   476.69), SIMDE_FLOAT32_C(  -341.57),
      SIMDE_FLOAT32_C(  -354.89), SIMDE_FLOAT32_C(  -380.58), SIMDE_FLOAT32_C(   141.64), SIMDE_FLOAT32_C(  -903.38),
      SIMDE_FLOAT32_C(  -811.33), SIMDE_FLOAT32_C(  -902.74), SIMDE_FLOAT32_C(  -525.35), SIMDE_FLOAT32_C(   234.54),
      SIMDE_FLOAT32_C(   644.81), SIMDE_FLOAT32_C(  -103.81), SIMDE_FLOAT32_C(  -987.56), SIMDE_FLOAT32_C(   151.21),
      SIMDE_FLOAT32_C(   -45.97), SIMDE_FLOAT32_C(    32.61), SIMDE_FLOAT32_C(  -542.73), SIMDE_FLOAT32_C(  -778.11),
      SIMDE_FLOAT32_C(   579.45), SIMDE_FLOAT32_C(   251.80), SIMDE_FLOAT32_C(   716.66), SIMDE_FLOAT32_C(  -970.01),
      SIMDE_FLOAT32_C(   963.87), SIMDE_FLOAT32_C(  -397.84), SIMDE_FLOAT32_C(   -13.46), SIMDE_FLOAT32_C(  -978.45),
      SIMDE_FLOAT32_C(   669.87), SIMDE_FLOAT32_C(   285.33), SIMDE_FLOAT32_C(   978.10), SIMDE_FLOAT32_C(  -743.13),
      SIMDE_FLOAT32_C(   748.70), SIMDE_FLOAT32_C(   454.79), SIMDE_FLOAT32_C(   -84.71), SIMDE_FLOAT32_C(  -606.18),
      SIMDE_FLOAT32_C(  -925.79), SIMDE_FLOAT32_C(  -943.06), SIMDE_FLOAT32_C(  -509.57), SIMDE_FLOAT32_C(  -737.11),
      SIMDE_FLOAT32_C(  -845.80) };
  static const simde_float32 e[] =
    { SIMDE_FLOAT32_C(  -663.70), SIMDE_FLOAT32_C(  -445.57), SIMDE_FLOAT32_C(   973.87), SIMDE_FLOAT32_C(   343.93),
      SIMDE_FLOAT32_C(  -227.34), SIMDE_FLOAT32_C(   663.04), SIMDE_FLOAT32_C(   217.80), SIMDE_FLOAT32_C(    14.29),
      SIMDE_FLOAT32_C( -1380.25), SIMDE_FLOAT32_C(  -449.32), SIMDE_FLOAT32_C(  -483.76), SIMDE_FLOAT32_C(   720.35),
      SIMDE_FLOAT32_C(   466.58), SIMDE_FLOAT32_C(  -206.72), SIMDE_FLOAT32_C(   810.08), SIMDE_FLOAT32_C(  -277.58),
      SIMDE_FLOAT32_C(   303.34), SIMDE_FLOAT32_C(   675.14), SIMDE_FLOAT32_C(    30.15), SIMDE_FLOAT32_C(  -755.01),
      SIMDE_FLOAT32_C(   -63.11), SIMDE_FLOAT32_C(  -574.60), SIMDE_FLOAT32_C(  -686.22), SIMDE_FLOAT32_C(  -217.20),
      SIMDE_FLOAT32_C(  -647.51), SIMDE_FLOAT32_C(  -584.72), SIMDE_FLOAT32_C(  1179.57), SIMDE_FLOAT32_C(  -616.69),
      SIMDE_FLOAT32_C(   220.34), SIMDE_FLOAT32_C(  -154.81), SIMDE_FLOAT32_C(  -168.15), SIMDE_FLOAT32_C(  1537.54),
      SIMDE_FLOAT32_C(  -374.53), SIMDE_FLOAT32_C(   -42.30), SIMDE_FLOAT32_C(  -561.72), SIMDE_FLOAT32_C(   490.76),
      SIMDE_FLOAT32_C(  -379.26), SIMDE_FLOAT32_C(   656.08), SIMDE_FLOAT32_C(  -720.24), SIMDE_FLOAT32_C(   -18.26),
      SIMDE_FLOAT32_C(   726.03), SIMDE_FLOAT32_C(  -970.11), SIMDE_FLOAT32_C(  -172.68), SIMDE_FLOAT32_C(   192.62),
      SIMDE_FLOAT32_C(  1575.42), SIMDE_FLOAT32_C(  -419.86), SIMDE_FLOAT32_C(   915.04), SIMDE_FLOAT32_C(  -316.03),
      SIMDE_FLOAT32_C(  -746.07), SIMDE_FLOAT32_C(   -54.81), SIMDE_FLOAT32_C(   181.58), SIMDE_FLOAT32_C(   192.18),
      SIMDE_FLOAT32_C(   370.59), SIMDE_FLOAT32_C(   242.74), SIMDE_FLOAT32_C(  -828.95), SIMDE_FLOAT32_C(   723.08),
      SIMDE_FLOAT32_C(   774.99), SIMDE_FLOAT32_C( -1599.29), SIMDE_FLOAT32_C(   859.01), SIMDE_FLOAT32_C(  -121.64),
      SIMDE_FLOAT32_C(   245.91), SIMDE_FLOAT32_C(   216.97), SIMDE_FLOAT32_C(     8.71), SIMDE_FLOAT32_C(  -354.48),
      SIMDE_FLOAT32_C(  -825.33), SIMDE_FLOAT32_C(  -126.71), SIMDE_FLOAT32_C(   759.26), SIMDE_FLOAT32_C(  -204.59),
      SIMDE_FLOAT32_C(  -470.63), SIMDE_FLOAT32_C( -1358.66), SIMDE_FLOAT32_C(  1205.21), SIMDE_FLOAT32_C(  -744.60),
      SIMDE_FLOAT32_C(  -164.98), SIMDE_FLOAT32_C(  -967.47), SIMDE_FLOAT32_C(   785.10), SIMDE_FLOAT32_C(  -753.34),
      SIMDE_FLOAT32_C(    -8.58), SIMDE_FLOAT32_C(   363.06), SIMDE_FLOAT32_C(  -874.59), SIMDE_FLOAT32_C(   245.35),
      SIMDE_FLOAT32_C( -1279.96), SIMDE_FLOAT32_C(  -692.99), SIMDE_FLOAT32_C(  -366.40), SIMDE_FLOAT32_C(   678.85),
      SIMDE_FLOAT32_C(   206.51), SIMDE_FLOAT32_C(  -195.35), SIMDE_FLOAT32_C(   401.93), SIMDE_FLOAT32_C(   -62.00),
      SIMDE_FLOAT32_C(   681.98), SIMDE_FLOAT32_C(  1219.79), SIMDE_FLOAT32_C(  1452.67), SIMDE_FLOAT32_C(  -314.39),
      SIMDE_FLOAT32_C(  -522.09), SIMDE_FLOAT32_C(  -538.62), SIMDE_FLOAT32_C(    46.74), SIMDE_FLOAT32_C(  -347.41),
      SIMDE_FLOAT32_C(  -648.43), SIMDE_FLOAT32_C(   709.69), SIMDE_FLOAT32_C(   448.00), SIMDE_FLOAT32_C(   654.03),
      SIMDE_FLOAT32_C(  -648.96), SIMDE_FLOAT32_C(   570.76), SIMDE_FLOAT32_C(   909.43), SIMDE_FLOAT32_C(   680.04),
      SIMDE_FLOAT32_C(   704.41), SIMDE_FLOAT32_C(   876.75), SIMDE_FLOAT32_C( -1731.07), SIMDE_FLOAT32_C(   215.96),
      SIMDE_FLOAT32_C( -1208.06), SIMDE_FLOAT32_C(  -605.65), SIMDE_FLOAT32_C(  1083.91), SIMDE_FLOAT32_C(  -488.00),
      SIMDE_FLOAT32_C(   701.35), SIMDE_FLOAT32_C(   144.04), SIMDE_FLOAT32_C(  -292.38), SIMDE_FLOAT32_C( -1092.14),
      SIMDE_FLOAT32_C(   425.31), SIMDE_FLOAT32_C(  -342.90), SIMDE_FLOAT32_C(   467.83), SIMDE_FLOAT32_C(  -892.71),
      SIMDE_FLOAT32_C(   370.49), SIMDE_FLOAT32_C(   284.19), SIMDE_FLOAT32_C(    35.17), SIMDE_FLOAT32_C(   848.40),
      SIMDE_FLOAT32_C(   803.43), SIMDE_FLOAT32_C(  -938.26), SIMDE_FLOAT32_C(  -499.01), SIMDE_FLOAT32_C(   155.00),
      SIMDE_FLOAT32_C(  -681.73), SIMDE_FLOAT32_C(   661.07), SIMDE_FLOAT32_C(  -800.24), SIMDE_FLOAT32_C(   669.30),
      SIMDE_FLOAT32_C(   174.15), SIMDE_FLOAT32_C(  -776.31), SIMDE_FLOAT32_C(  -308.42), SIMDE_FLOAT32_C(   835.12),
      SIMDE_FLOAT32_C(   168.15), SIMDE_FLOAT32_C(   497.13), SIMDE_FLOAT32_C(  1051.08), SIMDE_FLOAT32_C( -1039.90),
      SIMDE_FLOAT32_C(  -645.15), SIMDE_FLOAT32_C(   515.57), SIMDE_FLOAT32_C(   330.45), SIMDE_FLOAT32_C(    56.21),
      SIMDE_FLOAT32_C( -1720.97), SIMDE_FLOAT32_C( -1864.67), SIMDE_FLOAT32_C( -1035.94), SIMDE_FLOAT32_C(   704.33),
      SIMDE_FLOAT32_C(  -852.38), SIMDE_FLOAT32_C(   853.43), SIMDE_FLOAT32_C(   799.18), SIMDE_FLOAT32_C(   518.11),
      SIMDE_FLOAT32_C(   195.46), SIMDE_FLOAT32_C(  -153.21), SIMDE_FLOAT32_C(  -176.22), SIMDE_FLOAT32_C(  -223.00),
      SIMDE_FLOAT32_C(  -124.08), SIMDE_FLOAT32_C(   867.50), SIMDE_FLOAT32_C(  1153.89), SIMDE_FLOAT32_C(  -226.36),
      SIMDE_FLOAT32_C(   816.49), SIMDE_FLOAT32_C(   751.48), SIMDE_FLOAT32_C(   456.40), SIMDE_FLOAT32_C(    -9.36),
      SIMDE_FLOAT32_C(   975.18), SIMDE_FLOAT32_C(   134.52), SIMDE_FLOAT32_C(  1847.30), SIMDE_FLOAT32_C(  -186.80),
      SIMDE_FLOAT32_C(    95.01), SIMDE_FLOAT32_C(   443.59), SIMDE_FLOAT32_C(   858.00), SIMDE_FLOAT32_C(  -550.13),
      SIMDE_FLOAT32_C(   -40.84), SIMDE_FLOAT32_C(  -754.62), SIMDE_FLOAT32_C(  -493.93), SIMDE_FLOAT32_C(    49.51),
      SIMDE_FLOAT32_C(  -619.29) };

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
    rv = simde_svadd_f32_m(pv, av, bv);

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

    ev = simde_svadd_f32_m(pv, av, bv);

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
test_simde_svadd_f64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0) };
  static const simde_float64 a[] =
    { SIMDE_FLOAT64_C(   -64.06), SIMDE_FLOAT64_C(    31.58), SIMDE_FLOAT64_C(  -226.04), SIMDE_FLOAT64_C(   405.84),
      SIMDE_FLOAT64_C(   687.79), SIMDE_FLOAT64_C(  -264.95), SIMDE_FLOAT64_C(   939.27), SIMDE_FLOAT64_C(  -991.38),
      SIMDE_FLOAT64_C(  -986.92), SIMDE_FLOAT64_C(  -822.73), SIMDE_FLOAT64_C(    60.68), SIMDE_FLOAT64_C(  -437.61),
      SIMDE_FLOAT64_C(   592.86), SIMDE_FLOAT64_C(   925.29), SIMDE_FLOAT64_C(   123.93), SIMDE_FLOAT64_C(  -941.71),
      SIMDE_FLOAT64_C(  -988.36), SIMDE_FLOAT64_C(   763.53), SIMDE_FLOAT64_C(  -643.53), SIMDE_FLOAT64_C(   754.01),
      SIMDE_FLOAT64_C(   -34.98), SIMDE_FLOAT64_C(   178.76), SIMDE_FLOAT64_C(  -981.44), SIMDE_FLOAT64_C(   654.32),
      SIMDE_FLOAT64_C(  -406.43), SIMDE_FLOAT64_C(  -905.77), SIMDE_FLOAT64_C(  -773.50), SIMDE_FLOAT64_C(   418.62),
      SIMDE_FLOAT64_C(   125.75), SIMDE_FLOAT64_C(  -939.63), SIMDE_FLOAT64_C(   255.62), SIMDE_FLOAT64_C(  -938.31),
      SIMDE_FLOAT64_C(    91.95), SIMDE_FLOAT64_C(  -970.42), SIMDE_FLOAT64_C(   467.52), SIMDE_FLOAT64_C(  -220.26),
      SIMDE_FLOAT64_C(  -235.37), SIMDE_FLOAT64_C(   406.79), SIMDE_FLOAT64_C(  -211.64), SIMDE_FLOAT64_C(  -222.29),
      SIMDE_FLOAT64_C(   584.06), SIMDE_FLOAT64_C(   849.04), SIMDE_FLOAT64_C(   340.10), SIMDE_FLOAT64_C(   176.92),
      SIMDE_FLOAT64_C(   774.32), SIMDE_FLOAT64_C(  -535.97), SIMDE_FLOAT64_C(   235.21), SIMDE_FLOAT64_C(   785.97),
      SIMDE_FLOAT64_C(  -772.44), SIMDE_FLOAT64_C(   591.69), SIMDE_FLOAT64_C(   539.97), SIMDE_FLOAT64_C(   192.58),
      SIMDE_FLOAT64_C(  -229.56), SIMDE_FLOAT64_C(   558.54), SIMDE_FLOAT64_C(  -153.10), SIMDE_FLOAT64_C(   364.02),
      SIMDE_FLOAT64_C(   652.77) };
  static const simde_float64 b[] =
    { SIMDE_FLOAT64_C(    73.40), SIMDE_FLOAT64_C(  -217.36), SIMDE_FLOAT64_C(  -221.48), SIMDE_FLOAT64_C(   133.77),
      SIMDE_FLOAT64_C(  -961.75), SIMDE_FLOAT64_C(  -159.79), SIMDE_FLOAT64_C(  -774.28), SIMDE_FLOAT64_C(  -932.17),
      SIMDE_FLOAT64_C(  -692.27), SIMDE_FLOAT64_C(     5.46), SIMDE_FLOAT64_C(  -167.53), SIMDE_FLOAT64_C(   714.52),
      SIMDE_FLOAT64_C(   793.81), SIMDE_FLOAT64_C(   610.18), SIMDE_FLOAT64_C(   298.58), SIMDE_FLOAT64_C(   642.85),
      SIMDE_FLOAT64_C(   -49.72), SIMDE_FLOAT64_C(  -524.50), SIMDE_FLOAT64_C(   417.18), SIMDE_FLOAT64_C(   414.31),
      SIMDE_FLOAT64_C(   710.72), SIMDE_FLOAT64_C(   203.15), SIMDE_FLOAT64_C(   641.87), SIMDE_FLOAT64_C(   302.40),
      SIMDE_FLOAT64_C(  -256.88), SIMDE_FLOAT64_C(  -165.55), SIMDE_FLOAT64_C(  -927.15), SIMDE_FLOAT64_C(  -698.34),
      SIMDE_FLOAT64_C(   681.35), SIMDE_FLOAT64_C(   436.87), SIMDE_FLOAT64_C(   954.42), SIMDE_FLOAT64_C(  -245.25),
      SIMDE_FLOAT64_C(  -780.50), SIMDE_FLOAT64_C(  -267.06), SIMDE_FLOAT64_C(   888.53), SIMDE_FLOAT64_C(  -742.24),
      SIMDE_FLOAT64_C(   573.15), SIMDE_FLOAT64_C(  -885.75), SIMDE_FLOAT64_C(  -674.41), SIMDE_FLOAT64_C(   880.88),
      SIMDE_FLOAT64_C(   119.70), SIMDE_FLOAT64_C(   158.06), SIMDE_FLOAT64_C(   595.40), SIMDE_FLOAT64_C(   -86.48),
      SIMDE_FLOAT64_C(  -231.76), SIMDE_FLOAT64_C(  -106.02), SIMDE_FLOAT64_C(  -443.63), SIMDE_FLOAT64_C(   718.51),
      SIMDE_FLOAT64_C(   369.48), SIMDE_FLOAT64_C(   973.55), SIMDE_FLOAT64_C(   132.82), SIMDE_FLOAT64_C(    80.20),
      SIMDE_FLOAT64_C(   176.69), SIMDE_FLOAT64_C(  -225.31), SIMDE_FLOAT64_C(  -617.40), SIMDE_FLOAT64_C(   919.81),
      SIMDE_FLOAT64_C(   609.14) };
  static const simde_float64 e[] =
    { SIMDE_FLOAT64_C(     9.34), SIMDE_FLOAT64_C(  -185.78), SIMDE_FLOAT64_C(  -447.52), SIMDE_FLOAT64_C(   539.61),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -424.74), SIMDE_FLOAT64_C(   164.99), SIMDE_FLOAT64_C( -1923.55),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -817.27), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   276.91),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1535.47), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -298.86),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1168.32),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   381.91), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   956.72),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C( -1700.65), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -502.76), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C( -1183.56),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -478.96), SIMDE_FLOAT64_C(  -886.05), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1007.10), SIMDE_FLOAT64_C(   935.50), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -208.42), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  -402.96), SIMDE_FLOAT64_C(  1565.24), SIMDE_FLOAT64_C(   672.79), SIMDE_FLOAT64_C(   272.78),
      SIMDE_FLOAT64_C(   -52.87), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -770.50), SIMDE_FLOAT64_C(  1283.83),
      SIMDE_FLOAT64_C(     0.00) };

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
    rv = simde_svadd_f64_z(pv, av, bv);

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

    ev = simde_svadd_f64_z(pv, av, bv);

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
test_simde_svadd_f64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0) };
  static const simde_float64 a[] =
    { SIMDE_FLOAT64_C(  -120.40), SIMDE_FLOAT64_C(  -627.34), SIMDE_FLOAT64_C(  -149.90), SIMDE_FLOAT64_C(  -486.60),
      SIMDE_FLOAT64_C(   566.16), SIMDE_FLOAT64_C(   990.74), SIMDE_FLOAT64_C(   246.46), SIMDE_FLOAT64_C(   -79.15),
      SIMDE_FLOAT64_C(  -175.22), SIMDE_FLOAT64_C(   771.10), SIMDE_FLOAT64_C(  -582.35), SIMDE_FLOAT64_C(   579.32),
      SIMDE_FLOAT64_C(  -720.44), SIMDE_FLOAT64_C(  -715.64), SIMDE_FLOAT64_C(   796.54), SIMDE_FLOAT64_C(  -318.07),
      SIMDE_FLOAT64_C(  -622.24), SIMDE_FLOAT64_C(   162.14), SIMDE_FLOAT64_C(   104.64), SIMDE_FLOAT64_C(   234.38),
      SIMDE_FLOAT64_C(   484.37), SIMDE_FLOAT64_C(  -987.92), SIMDE_FLOAT64_C(  -394.43), SIMDE_FLOAT64_C(   682.07),
      SIMDE_FLOAT64_C(   972.48), SIMDE_FLOAT64_C(  -244.92), SIMDE_FLOAT64_C(   177.74), SIMDE_FLOAT64_C(  -306.17),
      SIMDE_FLOAT64_C(  -101.56), SIMDE_FLOAT64_C(   -76.70), SIMDE_FLOAT64_C(   -71.73), SIMDE_FLOAT64_C(   778.05),
      SIMDE_FLOAT64_C(   295.96), SIMDE_FLOAT64_C(   778.37), SIMDE_FLOAT64_C(  -708.56), SIMDE_FLOAT64_C(  -137.87),
      SIMDE_FLOAT64_C(   769.12), SIMDE_FLOAT64_C(   537.90), SIMDE_FLOAT64_C(   782.98), SIMDE_FLOAT64_C(  -406.10),
      SIMDE_FLOAT64_C(   309.01), SIMDE_FLOAT64_C(  -799.38), SIMDE_FLOAT64_C(  -826.78), SIMDE_FLOAT64_C(   588.57),
      SIMDE_FLOAT64_C(  -515.02), SIMDE_FLOAT64_C(   969.76), SIMDE_FLOAT64_C(  -729.50), SIMDE_FLOAT64_C(  -137.26),
      SIMDE_FLOAT64_C(   131.90), SIMDE_FLOAT64_C(   375.14), SIMDE_FLOAT64_C(  -902.88), SIMDE_FLOAT64_C(  -383.73),
      SIMDE_FLOAT64_C(   387.23), SIMDE_FLOAT64_C(  -297.31), SIMDE_FLOAT64_C(  -701.66), SIMDE_FLOAT64_C(   359.71),
      SIMDE_FLOAT64_C(   457.77), SIMDE_FLOAT64_C(   476.08), SIMDE_FLOAT64_C(  -946.47), SIMDE_FLOAT64_C(  -643.78),
      SIMDE_FLOAT64_C(  -600.62), SIMDE_FLOAT64_C(   -18.19) };
  static const simde_float64 b[] =
    { SIMDE_FLOAT64_C(  -865.74), SIMDE_FLOAT64_C(   695.35), SIMDE_FLOAT64_C(  -239.82), SIMDE_FLOAT64_C(  -574.29),
      SIMDE_FLOAT64_C(  -442.52), SIMDE_FLOAT64_C(  -470.70), SIMDE_FLOAT64_C(   963.61), SIMDE_FLOAT64_C(  -659.55),
      SIMDE_FLOAT64_C(   123.20), SIMDE_FLOAT64_C(   272.62), SIMDE_FLOAT64_C(  -458.93), SIMDE_FLOAT64_C(   296.42),
      SIMDE_FLOAT64_C(  -138.82), SIMDE_FLOAT64_C(    26.05), SIMDE_FLOAT64_C(   266.18), SIMDE_FLOAT64_C(   131.68),
      SIMDE_FLOAT64_C(   888.79), SIMDE_FLOAT64_C(  -601.92), SIMDE_FLOAT64_C(  -493.18), SIMDE_FLOAT64_C(   985.91),
      SIMDE_FLOAT64_C(    14.35), SIMDE_FLOAT64_C(   894.05), SIMDE_FLOAT64_C(  -311.39), SIMDE_FLOAT64_C(   312.69),
      SIMDE_FLOAT64_C(   253.76), SIMDE_FLOAT64_C(  -853.62), SIMDE_FLOAT64_C(  -211.23), SIMDE_FLOAT64_C(   307.29),
      SIMDE_FLOAT64_C(  -497.41), SIMDE_FLOAT64_C(   188.15), SIMDE_FLOAT64_C(  -710.91), SIMDE_FLOAT64_C(  -363.14),
      SIMDE_FLOAT64_C(  -116.50), SIMDE_FLOAT64_C(    49.27), SIMDE_FLOAT64_C(    62.56), SIMDE_FLOAT64_C(   440.98),
      SIMDE_FLOAT64_C(   578.57), SIMDE_FLOAT64_C(    26.17), SIMDE_FLOAT64_C(   781.43), SIMDE_FLOAT64_C(  -298.23),
      SIMDE_FLOAT64_C(  -701.21), SIMDE_FLOAT64_C(  -677.50), SIMDE_FLOAT64_C(   998.19), SIMDE_FLOAT64_C(   159.97),
      SIMDE_FLOAT64_C(   348.56), SIMDE_FLOAT64_C(   264.37), SIMDE_FLOAT64_C(  -708.35), SIMDE_FLOAT64_C(   237.35),
      SIMDE_FLOAT64_C(   662.45), SIMDE_FLOAT64_C(  -201.52), SIMDE_FLOAT64_C(   223.26), SIMDE_FLOAT64_C(  -323.20),
      SIMDE_FLOAT64_C(  -307.47), SIMDE_FLOAT64_C(   911.87), SIMDE_FLOAT64_C(   989.49), SIMDE_FLOAT64_C(   946.29),
      SIMDE_FLOAT64_C(  -941.76), SIMDE_FLOAT64_C(  -221.74), SIMDE_FLOAT64_C(   253.57), SIMDE_FLOAT64_C(  -439.16),
      SIMDE_FLOAT64_C(   966.41), SIMDE_FLOAT64_C(   542.67) };
  static const simde_float64 e[] =
    { SIMDE_FLOAT64_C(  -120.40), SIMDE_FLOAT64_C(  -627.34), SIMDE_FLOAT64_C(  -389.72), SIMDE_FLOAT64_C( -1060.89),
      SIMDE_FLOAT64_C(   566.16), SIMDE_FLOAT64_C(   990.74), SIMDE_FLOAT64_C(  1210.07), SIMDE_FLOAT64_C(   -79.15),
      SIMDE_FLOAT64_C(  -175.22), SIMDE_FLOAT64_C(  1043.72), SIMDE_FLOAT64_C( -1041.28), SIMDE_FLOAT64_C(   875.74),
      SIMDE_FLOAT64_C(  -720.44), SIMDE_FLOAT64_C(  -715.64), SIMDE_FLOAT64_C(   796.54), SIMDE_FLOAT64_C(  -186.39),
      SIMDE_FLOAT64_C(  -622.24), SIMDE_FLOAT64_C(  -439.78), SIMDE_FLOAT64_C(   104.64), SIMDE_FLOAT64_C(   234.38),
      SIMDE_FLOAT64_C(   484.37), SIMDE_FLOAT64_C(  -987.92), SIMDE_FLOAT64_C(  -394.43), SIMDE_FLOAT64_C(   682.07),
      SIMDE_FLOAT64_C(   972.48), SIMDE_FLOAT64_C(  -244.92), SIMDE_FLOAT64_C(   -33.49), SIMDE_FLOAT64_C(     1.12),
      SIMDE_FLOAT64_C(  -598.97), SIMDE_FLOAT64_C(   -76.70), SIMDE_FLOAT64_C(   -71.73), SIMDE_FLOAT64_C(   414.91),
      SIMDE_FLOAT64_C(   179.46), SIMDE_FLOAT64_C(   778.37), SIMDE_FLOAT64_C(  -646.00), SIMDE_FLOAT64_C(  -137.87),
      SIMDE_FLOAT64_C(  1347.69), SIMDE_FLOAT64_C(   537.90), SIMDE_FLOAT64_C(   782.98), SIMDE_FLOAT64_C(  -704.33),
      SIMDE_FLOAT64_C(   309.01), SIMDE_FLOAT64_C( -1476.88), SIMDE_FLOAT64_C(   171.41), SIMDE_FLOAT64_C(   588.57),
      SIMDE_FLOAT64_C(  -166.46), SIMDE_FLOAT64_C(   969.76), SIMDE_FLOAT64_C( -1437.85), SIMDE_FLOAT64_C(  -137.26),
      SIMDE_FLOAT64_C(   794.35), SIMDE_FLOAT64_C(   173.62), SIMDE_FLOAT64_C(  -679.62), SIMDE_FLOAT64_C(  -706.93),
      SIMDE_FLOAT64_C(   387.23), SIMDE_FLOAT64_C(   614.56), SIMDE_FLOAT64_C(   287.83), SIMDE_FLOAT64_C(   359.71),
      SIMDE_FLOAT64_C(   457.77), SIMDE_FLOAT64_C(   254.34), SIMDE_FLOAT64_C(  -946.47), SIMDE_FLOAT64_C(  -643.78),
      SIMDE_FLOAT64_C(  -600.62), SIMDE_FLOAT64_C(   -18.19) };

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
    rv = simde_svadd_f64_m(pv, av, bv);

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

    ev = simde_svadd_f64_m(pv, av, bv);

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
test_simde_svadd_n_s8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) };
  static const int8_t a[] =
    { -INT8_C(  38),  INT8_C(  58), -INT8_C( 125),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  16), -INT8_C(   1),      INT8_MAX,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  48), -INT8_C(   1),      INT8_MAX,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 112), -INT8_C(  89),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  32), -INT8_C( 125),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  56),  INT8_C(  19),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 103), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C( 112), -INT8_C(   1),      INT8_MAX,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 112), -INT8_C(  89),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  32), -INT8_C( 125),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  56),  INT8_C(  19),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 103), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C( 120),  INT8_C(  58), -INT8_C( 125),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  88),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  84),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   8),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  80), -INT8_C(  81),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  96),  INT8_C(   1),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 103), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 112), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  56),  INT8_C(   1),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  40),  INT8_C(   1),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  17), -INT8_C(  75), -INT8_C(  67), -INT8_C( 123),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  79),  INT8_C(  20), -INT8_C( 112),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 104), -INT8_C( 109), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  24),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  41), -INT8_C(  10),  INT8_C(  22),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  84),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  88),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  35), -INT8_C( 113),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  56),  INT8_C(   1),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  16), -INT8_C(  50), -INT8_C( 127),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  40),  INT8_C(   1),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 103), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  24), -INT8_C(  73), -INT8_C( 127),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  88), -INT8_C( 107), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  84), -INT8_C(  17),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  48), -INT8_C(  80), -INT8_C(  91),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 112), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C( 112),  INT8_C(   1),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  84), -INT8_C(  17),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  40), -INT8_C(  80), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  80), -INT8_C(  99), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  80), -INT8_C(  92), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_MIN, -INT8_C(  59), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  64),  INT8_C(  88),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  96),  INT8_C(  10),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  96),  INT8_C(  11),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_MIN, -INT8_C(  59), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  96), -INT8_C(  48), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 104), -INT8_C( 109), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  72),  INT8_C(  21),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C( 120),  INT8_C(  58), -INT8_C( 125),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  84), -INT8_C(  17),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  16), -INT8_C(  80), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  80), -INT8_C(  99), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  80), -INT8_C(  92), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  96),  INT8_C(   1),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  84), -INT8_C( 108), -INT8_C( 106),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 104), -INT8_C(  70), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 112),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  96), -INT8_C(  48), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C( 112),  INT8_C(   1),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 124),  INT8_C(  84), -INT8_C( 106),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   2),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   8),  INT8_C( 109), -INT8_C( 106),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 112),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 104), -INT8_C(  70), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C( 120), -INT8_C(  67), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_MIN,  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  80), -INT8_C(  92), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  39),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  80),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   8), -INT8_C(  70), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   8), -INT8_C(  79), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   8), -INT8_C(  70), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  16), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   8), -INT8_C(  70), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  16),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  61), -INT8_C( 106),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 104), -INT8_C(  70), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  64),  INT8_C(   2),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 120),  INT8_C( 119), -INT8_C( 106),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 104), -INT8_C(  70), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  80),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  80), -INT8_C(  92), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  16),  INT8_C(   2),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  40),  INT8_C( 123), -INT8_C( 106),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 104), -INT8_C(  70), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  80), -INT8_C(  92), -INT8_C( 114),  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  80),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  64),  INT8_C(  88),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  96),  INT8_C(  10),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  96),  INT8_C(  11),      INT8_MIN,  INT8_C(   0),  INT8_C(  85),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
           INT8_MIN, -INT8_C(  59), -INT8_C(  91),  INT8_C(   0),  INT8_C(  85) };
  static const int8_t b = -INT8_C( 116);
  static const int8_t e[] =
    {  INT8_C( 102),  INT8_C(   0),  INT8_C(  15),  INT8_C(   0), -INT8_C(  31), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
      -INT8_C( 100), -INT8_C( 117),  INT8_C(  11),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 117),  INT8_C(  11),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(  28),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  84),  INT8_C(   0), -INT8_C( 116), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  84), -INT8_C(  97),  INT8_C(  12),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),
      -INT8_C( 116),  INT8_C(  37),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),
       INT8_C(   0), -INT8_C( 117),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),
       INT8_C(   0),  INT8_C(  51),  INT8_C(  12),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),
      -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 115),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(  84), -INT8_C(  97),  INT8_C(  12), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),
       INT8_C(   0), -INT8_C(  58),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  12), -INT8_C( 116), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 116),  INT8_C(  12), -INT8_C( 116), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 116),  INT8_C(  12),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(  60),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(  44), -INT8_C( 115),  INT8_C(  12), -INT8_C( 116), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 116),  INT8_C(   0),  INT8_C(  26), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
      -INT8_C( 116),  INT8_C(   0),  INT8_C(  26), -INT8_C( 116), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
      -INT8_C(  60), -INT8_C( 115),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),
      -INT8_C(  76),  INT8_C(   0),  INT8_C(  12),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
       INT8_C( 123),  INT8_C(  65),  INT8_C(  73),  INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  28),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(  99),  INT8_C(   0),  INT8_C(   0), -INT8_C( 114), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  12), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  12),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  90),  INT8_C(  13), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
      -INT8_C( 115), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),
      -INT8_C(  76), -INT8_C( 115),  INT8_C(  12), -INT8_C( 116), -INT8_C(  31), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
      -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  92),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),
      -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(  52),  INT8_C(  33),  INT8_C(  26), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
      -INT8_C( 113),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
      -INT8_C( 112), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
       INT8_C(  56),  INT8_C(   0),  INT8_C(  12), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  49), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116), -INT8_C(  31), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
      -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),
      -INT8_C(   4), -INT8_C( 115),  INT8_C(  12),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  12),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  76),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  41),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),
       INT8_C(  60),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),
       INT8_C(   0),  INT8_C(  81),  INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(  76), -INT8_C(  28),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(  44),  INT8_C(   0),  INT8_C(  12), -INT8_C( 116), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(  44),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(   0),  INT8_C(  81),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 116), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),
      -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(  36),  INT8_C(  31),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  44), -INT8_C(  95),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  15),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(  56),  INT8_C(   0),  INT8_C(  12),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  41),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  60),  INT8_C(  48),  INT8_C(  26), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
      -INT8_C( 117), -INT8_C( 117),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
      -INT8_C(  20),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
       INT8_C(  28),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
       INT8_C(   0),  INT8_C(  92),  INT8_C(  49), -INT8_C( 116), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   4),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),
       INT8_C(   0), -INT8_C(  32),  INT8_C(  34),  INT8_C(   0), -INT8_C(  31), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
      -INT8_C( 116), -INT8_C( 114),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  28),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  36),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(  60),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
      -INT8_C(  77), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0),  INT8_C(  70),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C(  31),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
      -INT8_C( 124),  INT8_C(  70),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),
      -INT8_C( 116),  INT8_C( 124), -INT8_C( 117),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 117), -INT8_C( 117),
      -INT8_C( 124),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C(  31), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 100), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
      -INT8_C( 116), -INT8_C(  55),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),
       INT8_C(  36),  INT8_C(   0),  INT8_C(  49),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  12),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C(  31), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  36),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116),
      -INT8_C( 116), -INT8_C( 112), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),
      -INT8_C(  36),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(  26), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 114),  INT8_C(  12),  INT8_C(   0), -INT8_C(  31), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  76),  INT8_C(   7),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),
       INT8_C(  36),  INT8_C(   0),  INT8_C(  49), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
      -INT8_C( 116), -INT8_C( 112),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),
       INT8_C(   0),  INT8_C(  48),  INT8_C(   0), -INT8_C( 116),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C( 116),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  28),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116), -INT8_C( 116),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 116),
       INT8_C(  44),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(  12),  INT8_C(  81),  INT8_C(  49), -INT8_C( 116),  INT8_C(   0) };

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
    rv = simde_svadd_n_s8_z(pv, av, b);

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

    ev = simde_svadd_n_s8_z(pv, av, b);

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
test_simde_svadd_n_s8_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0) };
  static const int8_t a[] =
    {  INT8_C(  45), -INT8_C(  26), -INT8_C(  14),  INT8_C( 110),  INT8_C( 118), -INT8_C(  42), -INT8_C(  13), -INT8_C(  57),
      -INT8_C( 112), -INT8_C(  86), -INT8_C(  72),  INT8_C(  46), -INT8_C( 111), -INT8_C(  28), -INT8_C(   1), -INT8_C(  49),
       INT8_C(  45), -INT8_C(  19), -INT8_C(  37),  INT8_C(  69), -INT8_C(  84), -INT8_C(  64),  INT8_C(  90),  INT8_C(  31),
      -INT8_C( 121), -INT8_C(  86), -INT8_C( 103),  INT8_C(  28), -INT8_C( 115), -INT8_C(  68), -INT8_C( 119), -INT8_C(  70),
      -INT8_C(  94),  INT8_C( 123),  INT8_C(  40),  INT8_C(  24),  INT8_C(  81),  INT8_C(  27), -INT8_C(  33), -INT8_C(  31),
      -INT8_C(  59), -INT8_C( 105),  INT8_C(  15),  INT8_C(  87),  INT8_C( 124),  INT8_C(  15),  INT8_C(  38), -INT8_C(  87),
      -INT8_C(   4),  INT8_C(   1), -INT8_C(  17), -INT8_C(  88), -INT8_C(  63),  INT8_C(  73), -INT8_C(  56),  INT8_C(  73),
      -INT8_C(  13),  INT8_C(  97),  INT8_C( 101),      INT8_MIN,  INT8_C(  29), -INT8_C(  18),  INT8_C(  58), -INT8_C(  65),
       INT8_C( 105),  INT8_C(  98), -INT8_C(  40), -INT8_C(  70),  INT8_C( 125), -INT8_C(  73), -INT8_C( 100),  INT8_C(  67),
       INT8_C(  79), -INT8_C(  85), -INT8_C( 102), -INT8_C(  53), -INT8_C(  70), -INT8_C(  64),  INT8_C( 116), -INT8_C(  73),
      -INT8_C(  63),  INT8_C(  99),  INT8_C(  95), -INT8_C( 126), -INT8_C(  84),  INT8_C(  39), -INT8_C(  53), -INT8_C(  97),
      -INT8_C( 120),  INT8_C(  48),  INT8_C(  31), -INT8_C(  91),  INT8_C(  30),  INT8_C(  89),  INT8_C( 101), -INT8_C( 121),
      -INT8_C(  69),  INT8_C(  61),  INT8_C(  66),  INT8_C(  57), -INT8_C(  12), -INT8_C(  34),  INT8_C( 124),  INT8_C(  67),
      -INT8_C( 119),  INT8_C(  22),  INT8_C(  14),  INT8_C(  68), -INT8_C(  42), -INT8_C( 125), -INT8_C(   5), -INT8_C( 105),
      -INT8_C(  26),  INT8_C(  90),  INT8_C(  25), -INT8_C( 109), -INT8_C( 126), -INT8_C(  27),  INT8_C(  50),  INT8_C(  10),
       INT8_C(  21),  INT8_C(  82), -INT8_C(  80),  INT8_C(  52), -INT8_C(  85),  INT8_C(  21), -INT8_C(  69),  INT8_C( 103),
       INT8_C(  82), -INT8_C(   3), -INT8_C(  96),  INT8_C(  70), -INT8_C(  37),  INT8_C(  28), -INT8_C( 118),  INT8_C( 101),
       INT8_C(  50), -INT8_C( 104), -INT8_C(  87),  INT8_C(   8),  INT8_C(  27), -INT8_C(  92), -INT8_C(  97),  INT8_C(   2),
      -INT8_C(   2), -INT8_C(  72), -INT8_C( 107),      INT8_MIN, -INT8_C(  99), -INT8_C(  57), -INT8_C( 117), -INT8_C(  77),
       INT8_C(  25),  INT8_C(  59), -INT8_C(  25), -INT8_C(  59),  INT8_C(  80), -INT8_C(  94),  INT8_C(  44), -INT8_C(  94),
      -INT8_C(  96), -INT8_C(  52), -INT8_C(  24),  INT8_C( 123), -INT8_C(  24),  INT8_C( 114), -INT8_C(  32),  INT8_C(  26),
       INT8_C(  11), -INT8_C( 119),  INT8_C(  34),  INT8_C(  38),  INT8_C(  45), -INT8_C(  63),  INT8_C(  40),  INT8_C(  44),
       INT8_C( 121), -INT8_C(  67), -INT8_C(  84),  INT8_C(  23), -INT8_C( 123),  INT8_C(  55), -INT8_C(  54), -INT8_C(  98),
       INT8_C( 114), -INT8_C(  79),  INT8_C(  99), -INT8_C(  62),  INT8_C(  83), -INT8_C( 113),  INT8_C( 100), -INT8_C(  13),
       INT8_C(  91),  INT8_C(  77),  INT8_C( 111),  INT8_C(  67), -INT8_C(  65),  INT8_C(  79),  INT8_C(  93), -INT8_C(  54),
      -INT8_C(  39),      INT8_MAX, -INT8_C(  15),  INT8_C(   6),  INT8_C(  64),  INT8_C(  25),  INT8_C(  50), -INT8_C(  70),
      -INT8_C(  41), -INT8_C(  33), -INT8_C(  47),  INT8_C(  92),  INT8_C(  22), -INT8_C( 101), -INT8_C(   6), -INT8_C( 119),
       INT8_C(  76),  INT8_C(  94),  INT8_C(  75), -INT8_C(  97), -INT8_C(  19), -INT8_C(  80), -INT8_C( 109),  INT8_C(  73),
      -INT8_C(   3),  INT8_C(   2), -INT8_C( 116), -INT8_C(  68),  INT8_C(  81), -INT8_C(  22), -INT8_C( 121),  INT8_C(  42),
       INT8_C( 105),  INT8_C( 120),  INT8_C(  49), -INT8_C(  86), -INT8_C( 111),  INT8_C(  99),  INT8_C( 100),  INT8_C( 104),
       INT8_C(  66),  INT8_C(  53), -INT8_C(  60),  INT8_C(  89), -INT8_C(  48), -INT8_C(  65), -INT8_C(  30),  INT8_C(  28),
       INT8_C(  29),  INT8_C(  45), -INT8_C(  69),  INT8_C(  10), -INT8_C(  35),  INT8_C(  78),  INT8_C(  83), -INT8_C(  38),
       INT8_C(  80), -INT8_C(  32), -INT8_C( 105), -INT8_C(  94), -INT8_C(  54),  INT8_C(  30), -INT8_C(  52),  INT8_C(  51),
      -INT8_C( 106), -INT8_C(   3), -INT8_C(  35),  INT8_C(  39),  INT8_C(  97),  INT8_C(  65), -INT8_C( 112), -INT8_C(  93),
       INT8_C( 118),  INT8_C(  84), -INT8_C(   4),  INT8_C(  70),  INT8_C(  19), -INT8_C(  34),  INT8_C(  98),  INT8_C(  48),
       INT8_C(  12),  INT8_C(  30),  INT8_C(  59), -INT8_C(  23),  INT8_C( 108), -INT8_C( 114), -INT8_C(  60), -INT8_C(  67),
       INT8_C( 110),  INT8_C(  91),  INT8_C(  95),  INT8_C(  56),  INT8_C( 121),  INT8_C(  43),  INT8_C( 108),  INT8_C(  15),
       INT8_C(  41),  INT8_C(  73),  INT8_C(  54), -INT8_C( 118), -INT8_C( 117), -INT8_C(  58),  INT8_C(  45),  INT8_C(   1),
       INT8_C(  27),  INT8_C(  42),  INT8_C(  72),  INT8_C(  46),  INT8_C(   8), -INT8_C(  86),  INT8_C(  95),  INT8_C(  20),
      -INT8_C(  56), -INT8_C( 102), -INT8_C(   2),  INT8_C(  53),  INT8_C(  40), -INT8_C(  62), -INT8_C(  14), -INT8_C( 105),
       INT8_C(  29),  INT8_C(  81), -INT8_C(  49), -INT8_C( 106),  INT8_C( 124),  INT8_C(  59), -INT8_C(  91), -INT8_C(  91),
      -INT8_C( 123), -INT8_C(  37),  INT8_C(  47),  INT8_C(  16), -INT8_C(  94),  INT8_C(  93),  INT8_C(  17), -INT8_C(  67),
      -INT8_C( 121),  INT8_C(  89), -INT8_C(  21), -INT8_C( 113),  INT8_C(   4),  INT8_C(  74), -INT8_C(  92), -INT8_C(  52),
      -INT8_C(  28), -INT8_C(  94),  INT8_C(   1),  INT8_C(  13),  INT8_C( 100), -INT8_C(  13), -INT8_C(  92), -INT8_C( 127),
       INT8_C(  68),  INT8_C( 115),  INT8_C(  23), -INT8_C(  63), -INT8_C(  81), -INT8_C(  68),  INT8_C( 102),  INT8_C(  52),
      -INT8_C( 105), -INT8_C( 106),  INT8_C(  68),  INT8_C(  57), -INT8_C(  13),  INT8_C(  85), -INT8_C(  10),  INT8_C( 122),
      -INT8_C(  81), -INT8_C(  30),  INT8_C(   9), -INT8_C(  77),  INT8_C(  44), -INT8_C(  83),      INT8_MAX,  INT8_C(  17),
       INT8_C(  79), -INT8_C( 127),  INT8_C(  30), -INT8_C(  77),  INT8_C( 116), -INT8_C(  62),  INT8_C(  52), -INT8_C(  71),
       INT8_C(  53),  INT8_C(  75),  INT8_C( 122), -INT8_C(  28),  INT8_C(   7), -INT8_C(  32),  INT8_C(  24), -INT8_C(  97),
       INT8_C( 118),  INT8_C(  92), -INT8_C(  40),  INT8_C( 105), -INT8_C(  78), -INT8_C(  49), -INT8_C(  29),  INT8_C(  97),
      -INT8_C(  79), -INT8_C(  19),  INT8_C(  20), -INT8_C(  35), -INT8_C( 102), -INT8_C( 109), -INT8_C(  18), -INT8_C(  22),
       INT8_C(  20),  INT8_C(  12), -INT8_C(  99), -INT8_C( 119), -INT8_C(  50), -INT8_C(  46),  INT8_C(  66),  INT8_C(   4),
       INT8_C(  29), -INT8_C(  68), -INT8_C(  24),  INT8_C(  37), -INT8_C( 100),  INT8_C(   1), -INT8_C(  60),  INT8_C(  19),
       INT8_C(  93), -INT8_C( 100),  INT8_C( 124),  INT8_C(  15),  INT8_C( 107),  INT8_C(  96),  INT8_C( 112),  INT8_C(  28),
       INT8_C(  77), -INT8_C( 124), -INT8_C(   6), -INT8_C(  25),  INT8_C(  24), -INT8_C(  24), -INT8_C(  47),  INT8_C(  44),
      -INT8_C(  11),  INT8_C( 111), -INT8_C(  75), -INT8_C(  61),  INT8_C(  65), -INT8_C(   9), -INT8_C(  57),  INT8_C(  94),
      -INT8_C(  77), -INT8_C(  80), -INT8_C( 125),  INT8_C(  80), -INT8_C(  79),  INT8_C(  71),  INT8_C(  99),  INT8_C(  14),
      -INT8_C(  28), -INT8_C(  33),  INT8_C(  30),  INT8_C(  79),  INT8_C(  63), -INT8_C( 114),  INT8_C( 108), -INT8_C( 116),
       INT8_C(  19),  INT8_C( 102),  INT8_C( 116),  INT8_C(  43),  INT8_C(  78),  INT8_C(  69),  INT8_C(  87),  INT8_C(  67),
      -INT8_C(  76),  INT8_C(  13),  INT8_C(   7), -INT8_C(  11),  INT8_C(   4), -INT8_C(  50),  INT8_C(  84), -INT8_C(  72),
       INT8_C( 126), -INT8_C(  41),  INT8_C(   8),  INT8_C(  47),  INT8_C(  31),  INT8_C( 107),  INT8_C(  62),  INT8_C(   3),
       INT8_C(  74),  INT8_C(  92),  INT8_C(  82), -INT8_C( 118), -INT8_C(  22), -INT8_C(  66),  INT8_C(  22), -INT8_C(   3),
       INT8_C(  36), -INT8_C( 118),  INT8_C(  40),  INT8_C( 115), -INT8_C(  48),      INT8_MIN, -INT8_C(  74), -INT8_C( 124),
      -INT8_C( 115), -INT8_C(  67),  INT8_C( 122), -INT8_C( 111), -INT8_C( 116), -INT8_C(  50),  INT8_C(  73),  INT8_C(  10),
      -INT8_C(  91),  INT8_C(  81),  INT8_C(  58), -INT8_C(  60), -INT8_C(  68),  INT8_C( 120), -INT8_C(  57),  INT8_C(   7),
      -INT8_C(  44),  INT8_C(  26), -INT8_C( 111), -INT8_C(  66), -INT8_C(  40), -INT8_C(  89), -INT8_C(  68), -INT8_C(   3),
       INT8_C(  50), -INT8_C(  28),  INT8_C( 112),  INT8_C(   2),  INT8_C( 100),  INT8_C(  38), -INT8_C( 122), -INT8_C(  15),
      -INT8_C(  28),  INT8_C(   0), -INT8_C( 125),  INT8_C( 112), -INT8_C(  50), -INT8_C(  52),  INT8_C( 122),  INT8_C( 116),
       INT8_C(  30), -INT8_C(  76),  INT8_C(  56), -INT8_C(  38),  INT8_C(  44),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0),
       INT8_C(  26),  INT8_C( 114), -INT8_C(  65), -INT8_C(  14),  INT8_C(  26),  INT8_C( 123), -INT8_C(  17),  INT8_C(  76),
       INT8_C(  95),  INT8_C(  95),  INT8_C(  78), -INT8_C(  60), -INT8_C( 122), -INT8_C(  44), -INT8_C(  75),  INT8_C( 106),
      -INT8_C(  43),  INT8_C(  56), -INT8_C(  38), -INT8_C(  93),  INT8_C(   5),  INT8_C(  84),  INT8_C(  23),  INT8_C(  35),
       INT8_C(   9),  INT8_C(  80), -INT8_C(   3),  INT8_C(  53),  INT8_C(  80), -INT8_C(  33),  INT8_C(  54),  INT8_C( 106),
       INT8_C(  81), -INT8_C(  11),  INT8_C(  92),  INT8_C( 107),  INT8_C( 112),  INT8_C(  76), -INT8_C(  73), -INT8_C(  49),
      -INT8_C(  85),  INT8_C(   5), -INT8_C( 109),  INT8_C(  49), -INT8_C(  38),  INT8_C(  73), -INT8_C( 101), -INT8_C(  81),
      -INT8_C( 127),  INT8_C( 117),  INT8_C(  82), -INT8_C( 122), -INT8_C(  54),  INT8_C( 106), -INT8_C(  87), -INT8_C(  45),
      -INT8_C(  70), -INT8_C(  89),  INT8_C(   8),  INT8_C(  10), -INT8_C( 122),  INT8_C(  62),  INT8_C( 116), -INT8_C(  41),
       INT8_C(  51), -INT8_C(  48),  INT8_C(  67), -INT8_C(  93),  INT8_C(  28), -INT8_C(   6),  INT8_C( 115), -INT8_C(  56),
       INT8_C(   0),  INT8_C(   6), -INT8_C(   7), -INT8_C(  38),  INT8_C(  79), -INT8_C( 107), -INT8_C( 119), -INT8_C(  47),
       INT8_C(  10), -INT8_C(  37),  INT8_C(  87), -INT8_C(  44),  INT8_C(  69),  INT8_C(   1), -INT8_C(  89), -INT8_C(   1),
      -INT8_C(  88), -INT8_C(  80),  INT8_C(   9),  INT8_C(  46), -INT8_C(  18),  INT8_C( 125),  INT8_C(   5),  INT8_C(  34),
       INT8_C(  78),  INT8_C(  72), -INT8_C(  59),  INT8_C( 106),  INT8_C(  67),  INT8_C(  56),  INT8_C(  50),  INT8_C(  67),
       INT8_C(  63),  INT8_C(  44),  INT8_C(  29), -INT8_C( 114), -INT8_C(  63), -INT8_C(  90),  INT8_C(  95), -INT8_C(  53),
      -INT8_C( 127), -INT8_C(  73), -INT8_C(  96), -INT8_C(  57), -INT8_C(  72),  INT8_C(  71), -INT8_C(  58),  INT8_C(  96),
      -INT8_C(   9), -INT8_C(  48), -INT8_C( 114), -INT8_C(  26),  INT8_C(  77), -INT8_C( 109),  INT8_C(   8), -INT8_C( 101),
      -INT8_C(  36), -INT8_C(  51),  INT8_C(   6),  INT8_C(  31),  INT8_C(   6),  INT8_C(  56),  INT8_C(  98),  INT8_C(  69),
       INT8_C( 100),      INT8_MAX, -INT8_C(  45),  INT8_C(  37),  INT8_C(  37),  INT8_C(  51), -INT8_C(  15), -INT8_C(  90),
      -INT8_C(  22), -INT8_C( 111),  INT8_C( 109), -INT8_C(  94), -INT8_C(  40),  INT8_C(  52),  INT8_C(   2), -INT8_C(  48),
       INT8_C(   4), -INT8_C( 112), -INT8_C(  74),  INT8_C(  81),  INT8_C(  35), -INT8_C(  66), -INT8_C(  19), -INT8_C(   1),
      -INT8_C( 117), -INT8_C(  13),  INT8_C(  30), -INT8_C( 111),  INT8_C(  43),      INT8_MIN, -INT8_C(  42), -INT8_C( 112),
      -INT8_C(   1), -INT8_C(  86), -INT8_C(  75),  INT8_C(  36), -INT8_C(  35), -INT8_C(  90), -INT8_C(  53), -INT8_C(  57),
       INT8_C(  55),  INT8_C(  56),  INT8_C( 105),  INT8_C(  16),  INT8_C( 108),  INT8_C( 107), -INT8_C(  32),  INT8_C( 112),
      -INT8_C(   5), -INT8_C( 106), -INT8_C(  62),  INT8_C(  30),  INT8_C(  84), -INT8_C(  81),  INT8_C(  30), -INT8_C(  33),
      -INT8_C(  94),  INT8_C(  60),  INT8_C( 113), -INT8_C(  51), -INT8_C(  67),  INT8_C(  71),  INT8_C(  93), -INT8_C(  68),
      -INT8_C(  15),  INT8_C(  19), -INT8_C(  31), -INT8_C(  50), -INT8_C(  71), -INT8_C(  84), -INT8_C( 107), -INT8_C(  15),
      -INT8_C(  28), -INT8_C(   2),  INT8_C(   1),  INT8_C(  81),  INT8_C( 105), -INT8_C(  31), -INT8_C(  63),  INT8_C( 100),
       INT8_C( 119), -INT8_C( 125), -INT8_C( 125), -INT8_C(  53),  INT8_C(  50), -INT8_C(  95), -INT8_C(  86), -INT8_C(  44),
      -INT8_C(  35),  INT8_C(  27), -INT8_C(  94), -INT8_C( 102),  INT8_C(  99), -INT8_C(   1),  INT8_C(  87),  INT8_C(  84),
       INT8_C(  18),  INT8_C(  56),  INT8_C(  35), -INT8_C(  52), -INT8_C(  28), -INT8_C(  72), -INT8_C(  67), -INT8_C(  56),
      -INT8_C(  73), -INT8_C(  66),  INT8_C(  25),  INT8_C(  32), -INT8_C(  97), -INT8_C(  37), -INT8_C( 123),  INT8_C(  22),
       INT8_C(  94),  INT8_C(   8), -INT8_C(  31), -INT8_C( 111), -INT8_C(  87), -INT8_C( 117),  INT8_C( 101), -INT8_C( 122),
      -INT8_C(  89),  INT8_C(   7),  INT8_C(  33),  INT8_C(  10),  INT8_C(   7),  INT8_C( 120),  INT8_C(  94),  INT8_C(  25),
      -INT8_C(  80), -INT8_C( 127), -INT8_C(  27), -INT8_C( 108),  INT8_C(  58), -INT8_C(  94),  INT8_C(  92), -INT8_C(  15),
       INT8_C(  96),  INT8_C( 118),  INT8_C(  17), -INT8_C(   1),  INT8_C(  81), -INT8_C( 106),  INT8_C(  21), -INT8_C(  81),
      -INT8_C(  98), -INT8_C(  10),  INT8_C(  64),  INT8_C(  71), -INT8_C( 126), -INT8_C(  90), -INT8_C(  50),  INT8_C(  41),
      -INT8_C(  83), -INT8_C(  17),  INT8_C(  51), -INT8_C(  76),  INT8_C( 103), -INT8_C( 111), -INT8_C(  50),  INT8_C(  23),
       INT8_C(  19), -INT8_C(  77), -INT8_C(  85),  INT8_C(  77),  INT8_C(  86),  INT8_C(   7),  INT8_C(  62), -INT8_C(  74),
       INT8_C( 125),  INT8_C(  79), -INT8_C(  74), -INT8_C(  50), -INT8_C(  26), -INT8_C(  53),  INT8_C( 126), -INT8_C( 124),
      -INT8_C(  62), -INT8_C(  66), -INT8_C(  52),  INT8_C(  68),  INT8_C( 100), -INT8_C( 102),  INT8_C( 109),  INT8_C(  18),
      -INT8_C( 119), -INT8_C(  96), -INT8_C(  58), -INT8_C(  16),  INT8_C(  49), -INT8_C( 108),  INT8_C(   7),  INT8_C(  68),
       INT8_C(  72), -INT8_C(  78), -INT8_C( 111), -INT8_C(  98), -INT8_C(  71), -INT8_C(  49),  INT8_C(  84),  INT8_C(  55),
       INT8_C(  31),  INT8_C(  10),  INT8_C(   5),  INT8_C(   5), -INT8_C(  42), -INT8_C( 125), -INT8_C( 119), -INT8_C( 104),
       INT8_C(  66),  INT8_C(  85), -INT8_C(  36), -INT8_C(  90), -INT8_C(  17),  INT8_C(  73), -INT8_C(  72),  INT8_C( 120),
      -INT8_C(  23),      INT8_MAX,  INT8_C( 104),  INT8_C(  26),  INT8_C(  19),  INT8_C( 111),  INT8_C(  95),  INT8_C(  91),
       INT8_C(  33), -INT8_C(  16), -INT8_C(   7), -INT8_C(  37), -INT8_C(  64),  INT8_C(  78),  INT8_C(  18), -INT8_C(  33),
       INT8_C(  88),  INT8_C(  23), -INT8_C(  28),  INT8_C(  46), -INT8_C( 101),  INT8_C( 109), -INT8_C(  58), -INT8_C(  35),
      -INT8_C(  61), -INT8_C(  94), -INT8_C( 125), -INT8_C(  78), -INT8_C(  21),  INT8_C(  60),  INT8_C(  43), -INT8_C(  44),
      -INT8_C(  69), -INT8_C( 109), -INT8_C(  17), -INT8_C(  50),  INT8_C(   3),  INT8_C(  78),  INT8_C(  42),  INT8_C(  36),
       INT8_C(  62),  INT8_C(  35), -INT8_C(   1), -INT8_C(   2),  INT8_C( 113),  INT8_C(  17), -INT8_C(  35), -INT8_C(  54),
       INT8_C(  41), -INT8_C(  63) };
  static const int8_t b =  INT8_C(  26);
  static const int8_t e[] =
    {  INT8_C(  71), -INT8_C(  26),  INT8_C(  12), -INT8_C( 120),  INT8_C( 118), -INT8_C(  16),  INT8_C(  13), -INT8_C(  57),
      -INT8_C( 112), -INT8_C(  86), -INT8_C(  46),  INT8_C(  46), -INT8_C( 111), -INT8_C(   2),  INT8_C(  25), -INT8_C(  23),
       INT8_C(  71), -INT8_C(  19), -INT8_C(  37),  INT8_C(  69), -INT8_C(  84), -INT8_C(  64),  INT8_C(  90),  INT8_C(  57),
      -INT8_C(  95), -INT8_C(  60), -INT8_C( 103),  INT8_C(  54), -INT8_C(  89), -INT8_C(  42), -INT8_C( 119), -INT8_C(  44),
      -INT8_C(  68), -INT8_C( 107),  INT8_C(  40),  INT8_C(  50),  INT8_C( 107),  INT8_C(  27), -INT8_C(  33), -INT8_C(   5),
      -INT8_C(  59), -INT8_C(  79),  INT8_C(  41),  INT8_C( 113), -INT8_C( 106),  INT8_C(  41),  INT8_C(  38), -INT8_C(  61),
      -INT8_C(   4),  INT8_C(  27),  INT8_C(   9), -INT8_C(  88), -INT8_C(  63),  INT8_C(  73), -INT8_C(  56),  INT8_C(  73),
       INT8_C(  13),  INT8_C(  97),      INT8_MAX, -INT8_C( 102),  INT8_C(  55),  INT8_C(   8),  INT8_C(  58), -INT8_C(  65),
      -INT8_C( 125),  INT8_C(  98), -INT8_C(  40), -INT8_C(  70),  INT8_C( 125), -INT8_C(  73), -INT8_C( 100),  INT8_C(  93),
       INT8_C(  79), -INT8_C(  59), -INT8_C( 102), -INT8_C(  53), -INT8_C(  44), -INT8_C(  38), -INT8_C( 114), -INT8_C(  47),
      -INT8_C(  37),  INT8_C( 125),  INT8_C(  95), -INT8_C( 126), -INT8_C(  58),  INT8_C(  65), -INT8_C(  53), -INT8_C(  97),
      -INT8_C(  94),  INT8_C(  74),  INT8_C(  57), -INT8_C(  91),  INT8_C(  56),  INT8_C(  89),      INT8_MAX, -INT8_C( 121),
      -INT8_C(  43),  INT8_C(  87),  INT8_C(  66),  INT8_C(  83), -INT8_C(  12), -INT8_C(  34), -INT8_C( 106),  INT8_C(  93),
      -INT8_C( 119),  INT8_C(  22),  INT8_C(  40),  INT8_C(  68), -INT8_C(  16), -INT8_C(  99), -INT8_C(   5), -INT8_C(  79),
      -INT8_C(  26),  INT8_C(  90),  INT8_C(  51), -INT8_C(  83), -INT8_C( 100), -INT8_C(   1),  INT8_C(  50),  INT8_C(  36),
       INT8_C(  47),  INT8_C(  82), -INT8_C(  80),  INT8_C(  52), -INT8_C(  85),  INT8_C(  47), -INT8_C(  43), -INT8_C( 127),
       INT8_C( 108),  INT8_C(  23), -INT8_C(  70),  INT8_C(  96), -INT8_C(  37),  INT8_C(  28), -INT8_C(  92),      INT8_MAX,
       INT8_C(  50), -INT8_C(  78), -INT8_C(  61),  INT8_C(   8),  INT8_C(  27), -INT8_C(  66), -INT8_C(  71),  INT8_C(   2),
      -INT8_C(   2), -INT8_C(  46), -INT8_C(  81),      INT8_MIN, -INT8_C(  73), -INT8_C(  57), -INT8_C(  91), -INT8_C(  77),
       INT8_C(  25),  INT8_C(  85),  INT8_C(   1), -INT8_C(  59),  INT8_C( 106), -INT8_C(  94),  INT8_C(  70), -INT8_C(  94),
      -INT8_C(  96), -INT8_C(  52), -INT8_C(  24),  INT8_C( 123),  INT8_C(   2), -INT8_C( 116), -INT8_C(  32),  INT8_C(  26),
       INT8_C(  11), -INT8_C(  93),  INT8_C(  60),  INT8_C(  38),  INT8_C(  71), -INT8_C(  63),  INT8_C(  66),  INT8_C(  70),
       INT8_C( 121), -INT8_C(  67), -INT8_C(  58),  INT8_C(  49), -INT8_C( 123),  INT8_C(  81), -INT8_C(  54), -INT8_C(  72),
      -INT8_C( 116), -INT8_C(  53),  INT8_C( 125), -INT8_C(  62),  INT8_C(  83), -INT8_C(  87),  INT8_C( 100), -INT8_C(  13),
       INT8_C(  91),  INT8_C(  77), -INT8_C( 119),  INT8_C(  93), -INT8_C(  65),  INT8_C( 105),  INT8_C(  93), -INT8_C(  54),
      -INT8_C(  13), -INT8_C( 103),  INT8_C(  11),  INT8_C(   6),  INT8_C(  64),  INT8_C(  25),  INT8_C(  76), -INT8_C(  70),
      -INT8_C(  41), -INT8_C(   7), -INT8_C(  47),  INT8_C( 118),  INT8_C(  48), -INT8_C( 101),  INT8_C(  20), -INT8_C( 119),
       INT8_C( 102),  INT8_C(  94),  INT8_C(  75), -INT8_C(  97),  INT8_C(   7), -INT8_C(  54), -INT8_C( 109),  INT8_C(  73),
       INT8_C(  23),  INT8_C(  28), -INT8_C( 116), -INT8_C(  42),  INT8_C( 107), -INT8_C(  22), -INT8_C( 121),  INT8_C(  42),
       INT8_C( 105), -INT8_C( 110),  INT8_C(  49), -INT8_C(  86), -INT8_C(  85),  INT8_C(  99),  INT8_C( 126),  INT8_C( 104),
       INT8_C(  92),  INT8_C(  79), -INT8_C(  60),  INT8_C(  89), -INT8_C(  22), -INT8_C(  39), -INT8_C(   4),  INT8_C(  54),
       INT8_C(  55),  INT8_C(  71), -INT8_C(  43),  INT8_C(  36), -INT8_C(  35),  INT8_C(  78),  INT8_C( 109), -INT8_C(  38),
       INT8_C(  80), -INT8_C(  32), -INT8_C( 105), -INT8_C(  68), -INT8_C(  54),  INT8_C(  30), -INT8_C(  26),  INT8_C(  51),
      -INT8_C(  80), -INT8_C(   3), -INT8_C(   9),  INT8_C(  65),  INT8_C( 123),  INT8_C(  65), -INT8_C(  86), -INT8_C(  93),
       INT8_C( 118),  INT8_C( 110),  INT8_C(  22),  INT8_C(  70),  INT8_C(  45), -INT8_C(  34),  INT8_C(  98),  INT8_C(  74),
       INT8_C(  12),  INT8_C(  56),  INT8_C(  85),  INT8_C(   3),  INT8_C( 108), -INT8_C(  88), -INT8_C(  34), -INT8_C(  67),
      -INT8_C( 120),  INT8_C( 117),  INT8_C( 121),  INT8_C(  82), -INT8_C( 109),  INT8_C(  69),  INT8_C( 108),  INT8_C(  41),
       INT8_C(  41),  INT8_C(  99),  INT8_C(  54), -INT8_C(  92), -INT8_C( 117), -INT8_C(  58),  INT8_C(  45),  INT8_C(   1),
       INT8_C(  27),  INT8_C(  42),  INT8_C(  72),  INT8_C(  72),  INT8_C(  34), -INT8_C(  86),  INT8_C(  95),  INT8_C(  46),
      -INT8_C(  56), -INT8_C(  76), -INT8_C(   2),  INT8_C(  79),  INT8_C(  40), -INT8_C(  62),  INT8_C(  12), -INT8_C(  79),
       INT8_C(  55),  INT8_C( 107), -INT8_C(  23), -INT8_C(  80),  INT8_C( 124),  INT8_C(  85), -INT8_C(  65), -INT8_C(  65),
      -INT8_C( 123), -INT8_C(  11),  INT8_C(  47),  INT8_C(  42), -INT8_C(  68),  INT8_C( 119),  INT8_C(  43), -INT8_C(  41),
      -INT8_C(  95),  INT8_C(  89),  INT8_C(   5), -INT8_C( 113),  INT8_C(  30),  INT8_C( 100), -INT8_C(  66), -INT8_C(  52),
      -INT8_C(  28), -INT8_C(  94),  INT8_C(  27),  INT8_C(  39),  INT8_C( 100),  INT8_C(  13), -INT8_C(  92), -INT8_C( 127),
       INT8_C(  68), -INT8_C( 115),  INT8_C(  49), -INT8_C(  63), -INT8_C(  81), -INT8_C(  68),  INT8_C( 102),  INT8_C(  78),
      -INT8_C( 105), -INT8_C( 106),  INT8_C(  94),  INT8_C(  57),  INT8_C(  13),  INT8_C( 111), -INT8_C(  10),  INT8_C( 122),
      -INT8_C(  55), -INT8_C(   4),  INT8_C(  35), -INT8_C(  51),  INT8_C(  44), -INT8_C(  83),      INT8_MAX,  INT8_C(  43),
       INT8_C(  79), -INT8_C( 127),  INT8_C(  30), -INT8_C(  51), -INT8_C( 114), -INT8_C(  36),  INT8_C(  78), -INT8_C(  45),
       INT8_C(  53),  INT8_C(  75),  INT8_C( 122), -INT8_C(   2),  INT8_C(  33), -INT8_C(  32),  INT8_C(  50), -INT8_C(  71),
      -INT8_C( 112),  INT8_C(  92), -INT8_C(  40),  INT8_C( 105), -INT8_C(  52), -INT8_C(  49), -INT8_C(   3),  INT8_C( 123),
      -INT8_C(  53), -INT8_C(  19),  INT8_C(  46), -INT8_C(  35), -INT8_C(  76), -INT8_C(  83), -INT8_C(  18), -INT8_C(  22),
       INT8_C(  20),  INT8_C(  38), -INT8_C(  73), -INT8_C(  93), -INT8_C(  50), -INT8_C(  20),  INT8_C(  92),  INT8_C(  30),
       INT8_C(  55), -INT8_C(  42),  INT8_C(   2),  INT8_C(  63), -INT8_C( 100),  INT8_C(   1), -INT8_C(  34),  INT8_C(  45),
       INT8_C( 119), -INT8_C(  74),  INT8_C( 124),  INT8_C(  41), -INT8_C( 123),  INT8_C(  96),  INT8_C( 112),  INT8_C(  54),
       INT8_C( 103), -INT8_C(  98),  INT8_C(  20), -INT8_C(  25),  INT8_C(  50), -INT8_C(  24), -INT8_C(  21),  INT8_C(  70),
       INT8_C(  15),  INT8_C( 111), -INT8_C(  49), -INT8_C(  35),  INT8_C(  91), -INT8_C(   9), -INT8_C(  31),  INT8_C( 120),
      -INT8_C(  77), -INT8_C(  80), -INT8_C(  99),  INT8_C(  80), -INT8_C(  53),  INT8_C(  71),  INT8_C(  99),  INT8_C(  14),
      -INT8_C(   2), -INT8_C(  33),  INT8_C(  56),  INT8_C( 105),  INT8_C(  89), -INT8_C( 114),  INT8_C( 108), -INT8_C( 116),
       INT8_C(  19),  INT8_C( 102),  INT8_C( 116),  INT8_C(  69),  INT8_C(  78),  INT8_C(  95),  INT8_C( 113),  INT8_C(  67),
      -INT8_C(  76),  INT8_C(  13),  INT8_C(  33), -INT8_C(  11),  INT8_C(  30), -INT8_C(  24),  INT8_C(  84), -INT8_C(  46),
      -INT8_C( 104), -INT8_C(  15),  INT8_C(   8),  INT8_C(  73),  INT8_C(  57),  INT8_C( 107),  INT8_C(  62),  INT8_C(  29),
       INT8_C(  74),  INT8_C( 118),  INT8_C(  82), -INT8_C( 118), -INT8_C(  22), -INT8_C(  40),  INT8_C(  22), -INT8_C(   3),
       INT8_C(  62), -INT8_C(  92),  INT8_C(  66),  INT8_C( 115), -INT8_C(  22), -INT8_C( 102), -INT8_C(  74), -INT8_C(  98),
      -INT8_C(  89), -INT8_C(  67),  INT8_C( 122), -INT8_C(  85), -INT8_C(  90), -INT8_C(  50),  INT8_C(  73),  INT8_C(  36),
      -INT8_C(  91),  INT8_C(  81),  INT8_C(  58), -INT8_C(  34), -INT8_C(  68),  INT8_C( 120), -INT8_C(  31),  INT8_C(  33),
      -INT8_C(  44),  INT8_C(  52), -INT8_C(  85), -INT8_C(  66), -INT8_C(  40), -INT8_C(  89), -INT8_C(  68), -INT8_C(   3),
       INT8_C(  76), -INT8_C(  28),  INT8_C( 112),  INT8_C(   2),  INT8_C( 100),  INT8_C(  38), -INT8_C( 122),  INT8_C(  11),
      -INT8_C(  28),  INT8_C(  26), -INT8_C(  99),  INT8_C( 112), -INT8_C(  24), -INT8_C(  26), -INT8_C( 108),  INT8_C( 116),
       INT8_C(  30), -INT8_C(  50),  INT8_C(  56), -INT8_C(  12),  INT8_C(  44),  INT8_C(  26), -INT8_C(   5),  INT8_C(  26),
       INT8_C(  52), -INT8_C( 116), -INT8_C(  39),  INT8_C(  12),  INT8_C(  52),  INT8_C( 123),  INT8_C(   9),  INT8_C( 102),
       INT8_C( 121),  INT8_C(  95),  INT8_C( 104), -INT8_C(  34), -INT8_C( 122), -INT8_C(  44), -INT8_C(  49), -INT8_C( 124),
      -INT8_C(  17),  INT8_C(  56), -INT8_C(  12), -INT8_C(  67),  INT8_C(   5),  INT8_C(  84),  INT8_C(  49),  INT8_C(  35),
       INT8_C(   9),  INT8_C( 106),  INT8_C(  23),  INT8_C(  79),  INT8_C( 106), -INT8_C(   7),  INT8_C(  54),  INT8_C( 106),
       INT8_C(  81), -INT8_C(  11),  INT8_C( 118), -INT8_C( 123),  INT8_C( 112),  INT8_C( 102), -INT8_C(  47), -INT8_C(  23),
      -INT8_C(  59),  INT8_C(   5), -INT8_C( 109),  INT8_C(  49), -INT8_C(  12),  INT8_C(  99), -INT8_C(  75), -INT8_C(  55),
      -INT8_C( 127), -INT8_C( 113),  INT8_C(  82), -INT8_C( 122), -INT8_C(  54),  INT8_C( 106), -INT8_C(  87), -INT8_C(  45),
      -INT8_C(  70), -INT8_C(  89),  INT8_C(   8),  INT8_C(  36), -INT8_C( 122),  INT8_C(  62), -INT8_C( 114), -INT8_C(  41),
       INT8_C(  51), -INT8_C(  22),  INT8_C(  67), -INT8_C(  67),  INT8_C(  28),  INT8_C(  20),  INT8_C( 115), -INT8_C(  56),
       INT8_C(   0),  INT8_C(  32),  INT8_C(  19), -INT8_C(  38),  INT8_C( 105), -INT8_C(  81), -INT8_C(  93), -INT8_C(  21),
       INT8_C(  10), -INT8_C(  37),  INT8_C( 113), -INT8_C(  44),  INT8_C(  69),  INT8_C(   1), -INT8_C(  63),  INT8_C(  25),
      -INT8_C(  62), -INT8_C(  80),  INT8_C(   9),  INT8_C(  72),  INT8_C(   8),  INT8_C( 125),  INT8_C(  31),  INT8_C(  60),
       INT8_C( 104),  INT8_C(  72), -INT8_C(  33),  INT8_C( 106),  INT8_C(  93),  INT8_C(  82),  INT8_C(  76),  INT8_C(  67),
       INT8_C(  89),  INT8_C(  44),  INT8_C(  29), -INT8_C( 114), -INT8_C(  37), -INT8_C(  64),  INT8_C(  95), -INT8_C(  53),
      -INT8_C( 127), -INT8_C(  47), -INT8_C(  70), -INT8_C(  31), -INT8_C(  72),  INT8_C(  97), -INT8_C(  58),  INT8_C( 122),
       INT8_C(  17), -INT8_C(  22), -INT8_C( 114), -INT8_C(  26),  INT8_C( 103), -INT8_C( 109),  INT8_C(   8), -INT8_C( 101),
      -INT8_C(  36), -INT8_C(  25),  INT8_C(  32),  INT8_C(  31),  INT8_C(  32),  INT8_C(  56),  INT8_C( 124),  INT8_C(  95),
       INT8_C( 100), -INT8_C( 103), -INT8_C(  45),  INT8_C(  37),  INT8_C(  63),  INT8_C(  51),  INT8_C(  11), -INT8_C(  64),
      -INT8_C(  22), -INT8_C(  85),  INT8_C( 109), -INT8_C(  94), -INT8_C(  40),  INT8_C(  78),  INT8_C(   2), -INT8_C(  48),
       INT8_C(   4), -INT8_C( 112), -INT8_C(  48),  INT8_C( 107),  INT8_C(  61), -INT8_C(  40), -INT8_C(  19), -INT8_C(   1),
      -INT8_C(  91),  INT8_C(  13),  INT8_C(  56), -INT8_C(  85),  INT8_C(  43),      INT8_MIN, -INT8_C(  42), -INT8_C( 112),
       INT8_C(  25), -INT8_C(  86), -INT8_C(  49),  INT8_C(  36), -INT8_C(  35), -INT8_C(  90), -INT8_C(  53), -INT8_C(  31),
       INT8_C(  81),  INT8_C(  56), -INT8_C( 125),  INT8_C(  16), -INT8_C( 122), -INT8_C( 123), -INT8_C(  32),  INT8_C( 112),
      -INT8_C(   5), -INT8_C( 106), -INT8_C(  62),  INT8_C(  56),  INT8_C(  84), -INT8_C(  81),  INT8_C(  30), -INT8_C(   7),
      -INT8_C(  94),  INT8_C(  86), -INT8_C( 117), -INT8_C(  51), -INT8_C(  41),  INT8_C(  97),  INT8_C( 119), -INT8_C(  68),
      -INT8_C(  15),  INT8_C(  19), -INT8_C(   5), -INT8_C(  24), -INT8_C(  45), -INT8_C(  84), -INT8_C( 107), -INT8_C(  15),
      -INT8_C(   2), -INT8_C(   2),  INT8_C(  27),  INT8_C( 107), -INT8_C( 125), -INT8_C(   5), -INT8_C(  37),  INT8_C( 100),
       INT8_C( 119), -INT8_C(  99), -INT8_C(  99), -INT8_C(  53),  INT8_C(  50), -INT8_C(  69), -INT8_C(  60), -INT8_C(  44),
      -INT8_C(   9),  INT8_C(  53), -INT8_C(  68), -INT8_C( 102),  INT8_C( 125), -INT8_C(   1),  INT8_C( 113),  INT8_C( 110),
       INT8_C(  44),  INT8_C(  82),  INT8_C(  61), -INT8_C(  52), -INT8_C(   2), -INT8_C(  46), -INT8_C(  41), -INT8_C(  56),
      -INT8_C(  47), -INT8_C(  66),  INT8_C(  51),  INT8_C(  58), -INT8_C(  97), -INT8_C(  37), -INT8_C(  97),  INT8_C(  22),
       INT8_C(  94),  INT8_C(  34), -INT8_C(  31), -INT8_C( 111), -INT8_C(  61), -INT8_C( 117),      INT8_MAX, -INT8_C( 122),
      -INT8_C(  63),  INT8_C(   7),  INT8_C(  59),  INT8_C(  10),  INT8_C(   7),  INT8_C( 120),  INT8_C(  94),  INT8_C(  51),
      -INT8_C(  54), -INT8_C( 101), -INT8_C(  27), -INT8_C( 108),  INT8_C(  84), -INT8_C(  68),  INT8_C( 118),  INT8_C(  11),
       INT8_C( 122), -INT8_C( 112),  INT8_C(  17), -INT8_C(   1),  INT8_C( 107), -INT8_C( 106),  INT8_C(  21), -INT8_C(  81),
      -INT8_C(  72),  INT8_C(  16),  INT8_C(  64),  INT8_C(  97), -INT8_C( 100), -INT8_C(  64), -INT8_C(  24),  INT8_C(  67),
      -INT8_C(  57), -INT8_C(  17),  INT8_C(  77), -INT8_C(  76), -INT8_C( 127), -INT8_C(  85), -INT8_C(  50),  INT8_C(  23),
       INT8_C(  45), -INT8_C(  77), -INT8_C(  59),  INT8_C(  77),  INT8_C( 112),  INT8_C(  33),  INT8_C(  88), -INT8_C(  48),
       INT8_C( 125),  INT8_C(  79), -INT8_C(  48), -INT8_C(  50), -INT8_C(  26), -INT8_C(  53),  INT8_C( 126), -INT8_C(  98),
      -INT8_C(  36), -INT8_C(  66), -INT8_C(  52),  INT8_C(  94),  INT8_C( 100), -INT8_C( 102),  INT8_C( 109),  INT8_C(  18),
      -INT8_C(  93), -INT8_C(  96), -INT8_C(  32), -INT8_C(  16),  INT8_C(  49), -INT8_C(  82),  INT8_C(  33),  INT8_C(  94),
       INT8_C(  98), -INT8_C(  78), -INT8_C(  85), -INT8_C(  72), -INT8_C(  71), -INT8_C(  23),  INT8_C(  84),  INT8_C(  55),
       INT8_C(  57),  INT8_C(  10),  INT8_C(   5),  INT8_C(  31), -INT8_C(  42), -INT8_C( 125), -INT8_C(  93), -INT8_C( 104),
       INT8_C(  92),  INT8_C(  85), -INT8_C(  10), -INT8_C(  90), -INT8_C(  17),  INT8_C(  73), -INT8_C(  46), -INT8_C( 110),
      -INT8_C(  23),      INT8_MAX,  INT8_C( 104),  INT8_C(  26),  INT8_C(  45), -INT8_C( 119),  INT8_C( 121),  INT8_C( 117),
       INT8_C(  33),  INT8_C(  10), -INT8_C(   7), -INT8_C(  37), -INT8_C(  64),  INT8_C( 104),  INT8_C(  18), -INT8_C(   7),
       INT8_C( 114),  INT8_C(  49), -INT8_C(  28),  INT8_C(  46), -INT8_C(  75),  INT8_C( 109), -INT8_C(  58), -INT8_C(   9),
      -INT8_C(  61), -INT8_C(  94), -INT8_C( 125), -INT8_C(  78), -INT8_C(  21),  INT8_C(  86),  INT8_C(  43), -INT8_C(  18),
      -INT8_C(  43), -INT8_C( 109),  INT8_C(   9), -INT8_C(  50),  INT8_C(  29),  INT8_C( 104),  INT8_C(  42),  INT8_C(  36),
       INT8_C(  88),  INT8_C(  35), -INT8_C(   1),  INT8_C(  24), -INT8_C( 117),  INT8_C(  17), -INT8_C(   9), -INT8_C(  28),
       INT8_C(  41), -INT8_C(  63) };

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
    rv = simde_svadd_n_s8_m(pv, av, b);

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

    ev = simde_svadd_n_s8_m(pv, av, b);

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
test_simde_svadd_n_s16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) };
  static const int16_t a[] =
    { -INT16_C( 16703), -INT16_C( 29658), -INT16_C( 16700),  INT16_C( 14951), -INT16_C( 16814), -INT16_C(  8619), -INT16_C(  5200), -INT16_C( 11859),
       INT16_C( 31865),  INT16_C( 14083), -INT16_C( 12959), -INT16_C( 24268),  INT16_C(  8167), -INT16_C( 22111),  INT16_C( 16651), -INT16_C( 12964),
      -INT16_C( 32001), -INT16_C( 15527), -INT16_C( 16319), -INT16_C( 27651),  INT16_C( 21119),  INT16_C( 12145),  INT16_C(  7998), -INT16_C( 18688),
       INT16_C(   923), -INT16_C(   785),  INT16_C(  9168), -INT16_C( 18531),  INT16_C( 16194),  INT16_C( 19808), -INT16_C( 17024), -INT16_C( 32742),
       INT16_C( 29503), -INT16_C( 32701),  INT16_C( 16692), -INT16_C( 19693), -INT16_C( 31341), -INT16_C( 11806), -INT16_C(  7516),  INT16_C( 16265),
       INT16_C( 30949), -INT16_C( 19140), -INT16_C(  9829), -INT16_C(  8852), -INT16_C( 13032), -INT16_C( 26326),  INT16_C( 17802), -INT16_C( 14055),
       INT16_C( 23736), -INT16_C(  5046),  INT16_C( 23965),  INT16_C( 12703), -INT16_C( 32286), -INT16_C( 31230), -INT16_C( 29853),  INT16_C( 18630),
       INT16_C(   515), -INT16_C( 24835),  INT16_C( 27355), -INT16_C(  2949), -INT16_C( 22985), -INT16_C( 15987), -INT16_C( 22805), -INT16_C( 23670),
      -INT16_C( 11262), -INT16_C( 24432),  INT16_C( 12082),  INT16_C(  5329), -INT16_C( 11343),  INT16_C(  5275),  INT16_C( 24927),  INT16_C( 25181),
       INT16_C( 23139),  INT16_C( 15873),  INT16_C( 31940), -INT16_C(  1230), -INT16_C( 16606),  INT16_C(  3516),  INT16_C( 18277),  INT16_C( 26801),
       INT16_C( 16667),  INT16_C( 19720), -INT16_C(  9872),  INT16_C(  8546), -INT16_C(   596),  INT16_C(  2870), -INT16_C( 27810), -INT16_C( 16018),
       INT16_C( 28653), -INT16_C( 19713),  INT16_C( 13035),  INT16_C(  3757),  INT16_C( 27377),  INT16_C( 22299), -INT16_C( 13135), -INT16_C( 13121),
      -INT16_C( 14579),  INT16_C( 32282),  INT16_C( 31904),  INT16_C( 19615), -INT16_C( 10887), -INT16_C( 10408), -INT16_C( 14744),  INT16_C( 22168),
      -INT16_C( 26827),  INT16_C(  8200), -INT16_C( 18999), -INT16_C( 17618),  INT16_C( 18975), -INT16_C( 12270), -INT16_C( 12010),  INT16_C(  9373),
      -INT16_C( 18536),  INT16_C( 14498),  INT16_C( 16691), -INT16_C( 21372), -INT16_C(  9193),  INT16_C( 32643),  INT16_C(  7074), -INT16_C( 10283),
      -INT16_C(  8782),  INT16_C( 31992),  INT16_C(  9875), -INT16_C( 19913),  INT16_C( 18800), -INT16_C( 30845),  INT16_C(  8218), -INT16_C( 19797),
       INT16_C( 19927),  INT16_C(  2794),  INT16_C( 28302), -INT16_C( 23114),  INT16_C( 14667), -INT16_C(  4827), -INT16_C(  1452),  INT16_C(  1733),
      -INT16_C( 16936),  INT16_C( 27522), -INT16_C( 17949),  INT16_C( 21533), -INT16_C( 24574),  INT16_C(  7387), -INT16_C( 31040), -INT16_C( 26674),
      -INT16_C( 18221),  INT16_C( 24993),  INT16_C( 22311),  INT16_C( 29191),  INT16_C( 11408), -INT16_C(  7073),  INT16_C(  9254), -INT16_C(   277),
       INT16_C( 28129), -INT16_C( 14999), -INT16_C( 30937),  INT16_C( 10521), -INT16_C(  3033), -INT16_C(  6074),  INT16_C(  5242),  INT16_C( 19839),
       INT16_C(  8653), -INT16_C(  2898), -INT16_C( 19080),  INT16_C(  2406), -INT16_C( 14879),  INT16_C(  2285), -INT16_C( 10006), -INT16_C( 13562),
       INT16_C( 28742),  INT16_C( 28048), -INT16_C( 22025),  INT16_C(  7830), -INT16_C(  9059),  INT16_C(  5894), -INT16_C( 30991), -INT16_C( 16796),
       INT16_C(  5031),  INT16_C(  8114),  INT16_C(  6344), -INT16_C( 21976),  INT16_C(  5853), -INT16_C( 14414), -INT16_C( 18194),  INT16_C( 13459),
       INT16_C(  9000),  INT16_C(  8097),  INT16_C( 14541),  INT16_C( 27198),  INT16_C( 17428),  INT16_C(  1410), -INT16_C(  6454),  INT16_C( 29123),
       INT16_C( 30201), -INT16_C( 15727), -INT16_C( 18035),  INT16_C( 27500),  INT16_C(  7887), -INT16_C( 16846), -INT16_C( 14890), -INT16_C(    14),
      -INT16_C( 27415), -INT16_C( 18914),  INT16_C( 23756), -INT16_C(  8160), -INT16_C( 23903),  INT16_C( 27622), -INT16_C( 22135), -INT16_C( 32035),
       INT16_C( 28191), -INT16_C( 21436), -INT16_C( 20441), -INT16_C(  2281),  INT16_C( 19150), -INT16_C( 23115), -INT16_C( 22769), -INT16_C(  1884),
      -INT16_C( 15813),  INT16_C(  1966), -INT16_C( 12513), -INT16_C( 16152), -INT16_C( 12687), -INT16_C(  1493),  INT16_C(  2167), -INT16_C( 27011),
      -INT16_C( 16010), -INT16_C( 25021),  INT16_C( 23154),  INT16_C( 16533),  INT16_C( 19108), -INT16_C( 19227), -INT16_C( 30223),  INT16_C( 11692),
       INT16_C( 23372),  INT16_C( 27444),  INT16_C(  7210), -INT16_C( 25813),  INT16_C( 22250),  INT16_C( 25238),  INT16_C(  4959), -INT16_C( 10760),
       INT16_C( 15316),  INT16_C( 18035),  INT16_C(  2198),  INT16_C( 14983),  INT16_C( 27730),  INT16_C( 17646), -INT16_C( 25610),  INT16_C( 17009),
      -INT16_C( 23050),  INT16_C(  8365), -INT16_C( 10046), -INT16_C( 21317),  INT16_C( 20782), -INT16_C( 29426),  INT16_C(  1892),  INT16_C( 14691),
      -INT16_C( 10686), -INT16_C( 10113),  INT16_C(  1759),  INT16_C( 12563),  INT16_C(   371),  INT16_C( 26997), -INT16_C(  6500), -INT16_C( 27989),
       INT16_C( 22668),  INT16_C( 20146),  INT16_C( 28208),  INT16_C( 24314),  INT16_C(  2495),  INT16_C(  9452),  INT16_C( 20240),  INT16_C( 21085),
      -INT16_C(  9179),  INT16_C(  1067),  INT16_C( 16099),  INT16_C( 22070), -INT16_C( 21697), -INT16_C(  9025),  INT16_C( 27282),  INT16_C(  7790),
       INT16_C(  8642), -INT16_C(  3476),  INT16_C( 26255),  INT16_C( 20048),  INT16_C( 15471),  INT16_C( 32626), -INT16_C( 12405), -INT16_C( 20014),
      -INT16_C(   596), -INT16_C( 28747), -INT16_C(  5317),  INT16_C( 31461), -INT16_C( 23401),  INT16_C( 10582), -INT16_C( 15090), -INT16_C( 12217),
      -INT16_C( 19482),  INT16_C( 30146),  INT16_C(  4633), -INT16_C( 30269),  INT16_C( 13903), -INT16_C(  9720), -INT16_C(  9723), -INT16_C( 20085),
       INT16_C( 16855),  INT16_C(  4672),  INT16_C(  9516), -INT16_C( 15475), -INT16_C(  7223), -INT16_C( 10260),  INT16_C( 13224), -INT16_C( 29017),
       INT16_C( 27110),  INT16_C(     3), -INT16_C( 14468), -INT16_C( 13431) };
  static const int16_t b = -INT16_C( 26104);
  static const int16_t e[] =
    {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 22618),  INT16_C( 30813), -INT16_C( 31304),  INT16_C( 27573),
       INT16_C(  5761),  INT16_C(     0),  INT16_C(     0),  INT16_C( 15164), -INT16_C( 17937),  INT16_C( 17321), -INT16_C(  9453),  INT16_C( 26468),
       INT16_C(     0),  INT16_C(     0),  INT16_C( 23113),  INT16_C( 11781),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 25181), -INT16_C( 26889), -INT16_C( 16936),  INT16_C(     0), -INT16_C(  9910),  INT16_C(     0),  INT16_C(     0),  INT16_C(  6690),
       INT16_C(  3399),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  9839),
       INT16_C(     0),  INT16_C( 20292),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(  2368), -INT16_C( 31150), -INT16_C(  2139),  INT16_C(     0),  INT16_C(     0),  INT16_C(  8202),  INT16_C(     0), -INT16_C(  7474),
      -INT16_C( 25589),  INT16_C( 14597),  INT16_C(  1251),  INT16_C(     0),  INT16_C(     0),  INT16_C( 23445),  INT16_C( 16627),  INT16_C( 15762),
       INT16_C( 28170),  INT16_C( 15000),  INT16_C(     0), -INT16_C( 20775),  INT16_C( 28089),  INT16_C(     0), -INT16_C(  1177),  INT16_C(     0),
      -INT16_C(  2965),  INT16_C(     0),  INT16_C(  5836),  INT16_C(     0),  INT16_C(     0), -INT16_C( 22588), -INT16_C(  7827),  INT16_C(   697),
      -INT16_C(  9437),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 26700), -INT16_C( 23234),  INT16_C(     0),  INT16_C( 23414),
       INT16_C(  2549),  INT16_C(     0), -INT16_C( 13069),  INT16_C(     0),  INT16_C(     0), -INT16_C(  3805),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 28545),  INT16_C(     0),  INT16_C( 24688), -INT16_C(  3936),
       INT16_C( 12605),  INT16_C(     0),  INT16_C( 20433),  INT16_C( 21814),  INT16_C(     0),  INT16_C(     0),  INT16_C( 27422), -INT16_C( 16731),
       INT16_C(     0), -INT16_C( 11606), -INT16_C(  9413),  INT16_C(     0),  INT16_C(     0),  INT16_C(  6539), -INT16_C( 19030),  INT16_C(     0),
       INT16_C( 30650),  INT16_C(  5888), -INT16_C( 16229),  INT16_C( 19519), -INT16_C(  7304),  INT16_C(  8587), -INT16_C( 17886),  INT16_C( 19635),
      -INT16_C(  6177),  INT16_C(     0),  INT16_C(  2198),  INT16_C(     0), -INT16_C( 11437),  INT16_C(     0), -INT16_C( 27556), -INT16_C( 24371),
       INT16_C(     0),  INT16_C(     0),  INT16_C( 21483), -INT16_C(  4571),  INT16_C(     0), -INT16_C( 18717),  INT16_C(     0),  INT16_C( 12758),
       INT16_C( 21211), -INT16_C(  1111), -INT16_C(  3793),  INT16_C(     0), -INT16_C( 14696),  INT16_C(     0), -INT16_C( 16850), -INT16_C( 26381),
       INT16_C(  2025),  INT16_C(     0),  INT16_C(  8495),  INT16_C(     0), -INT16_C( 29137), -INT16_C( 32178),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 17451), -INT16_C( 29002),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24553), -INT16_C( 23819),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 18274),  INT16_C( 30373),  INT16_C(     0),  INT16_C(  8441),  INT16_C(     0),
       INT16_C(     0), -INT16_C( 17990),  INT16_C(     0),  INT16_C( 17456),  INT16_C(     0),  INT16_C(     0),  INT16_C( 21238), -INT16_C( 12645),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  8676), -INT16_C( 24694),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C( 23705),  INT16_C(     0),  INT16_C(  1396),  INT16_C(     0),  INT16_C( 22586),  INT16_C( 24542),  INT16_C(     0),
       INT16_C( 12017),  INT16_C( 20518), -INT16_C(  2348),  INT16_C( 31272),  INT16_C( 15529),  INT16_C(     0),  INT16_C( 17297),  INT16_C(  7397),
       INT16_C(     0),  INT16_C( 17996),  INT16_C( 18991),  INT16_C(     0), -INT16_C(  6954),  INT16_C(     0),  INT16_C(     0), -INT16_C( 27988),
       INT16_C(     0), -INT16_C( 24138),  INT16_C( 26919),  INT16_C(     0),  INT16_C( 26745), -INT16_C( 27597), -INT16_C( 23937),  INT16_C( 12421),
       INT16_C( 23422),  INT16_C( 14411),  INT16_C(     0), -INT16_C(  9571),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(  2732),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C( 10788), -INT16_C(  8069), -INT16_C( 23906), -INT16_C( 11121),  INT16_C(  1626), -INT16_C(  8458),  INT16_C(     0),  INT16_C(     0),
       INT16_C( 16382),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  5322),  INT16_C( 10006),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C( 29319),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   893),  INT16_C(     0),  INT16_C( 11443),
      -INT16_C(  3436),  INT16_C(     0),  INT16_C(  2104), -INT16_C(  1790), -INT16_C( 23609), -INT16_C( 16652), -INT16_C(  5864), -INT16_C(  5019),
       INT16_C( 30253), -INT16_C( 25037), -INT16_C( 10005),  INT16_C(     0),  INT16_C( 17735),  INT16_C( 30407),  INT16_C(     0), -INT16_C( 18314),
      -INT16_C( 17462),  INT16_C(     0),  INT16_C(   151), -INT16_C(  6056), -INT16_C( 10633),  INT16_C(  6522),  INT16_C( 27027),  INT16_C( 19418),
      -INT16_C( 26700),  INT16_C( 10685),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 15522),  INT16_C( 24342),  INT16_C(     0),
       INT16_C( 19950),  INT16_C(  4042), -INT16_C( 21471),  INT16_C(     0),  INT16_C(     0),  INT16_C( 29712),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C( 16588),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 12880),  INT16_C(     0),
       INT16_C(  1006), -INT16_C( 26101),  INT16_C( 24964),  INT16_C(     0) };

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
    rv = simde_svadd_n_s16_z(pv, av, b);

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

    ev = simde_svadd_n_s16_z(pv, av, b);

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
test_simde_svadd_n_s16_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0) };
  static const int16_t a[] =
    {  INT16_C( 20026),  INT16_C(  5968),  INT16_C(  4999),  INT16_C( 25962), -INT16_C(  6202),  INT16_C( 29426), -INT16_C( 26446),  INT16_C( 12548),
       INT16_C( 21578),  INT16_C( 19972),  INT16_C( 10660), -INT16_C( 14026), -INT16_C( 18601), -INT16_C( 21366),  INT16_C( 24990), -INT16_C(  9987),
       INT16_C( 20143),  INT16_C( 14320),  INT16_C( 23137),  INT16_C( 10140), -INT16_C( 29119), -INT16_C(  3175), -INT16_C( 25306),  INT16_C( 28708),
       INT16_C( 10737), -INT16_C( 26946), -INT16_C(  2990), -INT16_C( 21921), -INT16_C(  5717),  INT16_C( 18774),  INT16_C( 21322), -INT16_C(  1502),
       INT16_C(  4769),  INT16_C(   561), -INT16_C( 12948), -INT16_C( 21207), -INT16_C( 15781), -INT16_C( 32351), -INT16_C( 15009),  INT16_C( 20977),
      -INT16_C( 20498),  INT16_C( 16871),  INT16_C( 18083),  INT16_C( 20203),  INT16_C( 16687),  INT16_C( 31383), -INT16_C( 18028),  INT16_C( 13940),
      -INT16_C( 23093),  INT16_C( 14136),  INT16_C( 25202), -INT16_C( 12827), -INT16_C( 31196), -INT16_C( 31666),  INT16_C( 16203),  INT16_C( 15061),
      -INT16_C( 17170), -INT16_C( 28293),  INT16_C( 26114),  INT16_C( 12767),  INT16_C( 30375),  INT16_C( 15275),  INT16_C(  7984), -INT16_C(  1167),
      -INT16_C( 21820),  INT16_C( 13875),  INT16_C(  6156),  INT16_C( 12291),  INT16_C( 20894), -INT16_C(  5708), -INT16_C( 30320),  INT16_C( 32291),
      -INT16_C( 25019),  INT16_C( 18191), -INT16_C(  4604), -INT16_C( 21639),  INT16_C(  9317), -INT16_C( 27161),  INT16_C( 22596),  INT16_C(  2192),
      -INT16_C( 15614),  INT16_C(  3647),  INT16_C( 17115),  INT16_C( 31039), -INT16_C(  3180),  INT16_C(  9315), -INT16_C( 31107), -INT16_C( 15709),
      -INT16_C( 19931),  INT16_C( 10506), -INT16_C( 31839),  INT16_C(  1749), -INT16_C( 17241), -INT16_C(  5221),  INT16_C( 11028),  INT16_C(  6132),
       INT16_C( 13295), -INT16_C( 13787),  INT16_C( 25717),  INT16_C(  2372), -INT16_C( 22696), -INT16_C( 10962), -INT16_C( 11987),  INT16_C( 21143),
      -INT16_C( 24189),  INT16_C(  9340),  INT16_C( 20772), -INT16_C( 13270), -INT16_C( 15091),  INT16_C(  8631), -INT16_C( 21519), -INT16_C(  8136),
       INT16_C( 24286),  INT16_C( 21674), -INT16_C(  4414),  INT16_C(  6749), -INT16_C( 29803), -INT16_C( 15377), -INT16_C( 30884), -INT16_C(  8171),
      -INT16_C( 28376),  INT16_C( 19716),  INT16_C( 12258), -INT16_C(  4327), -INT16_C( 12044), -INT16_C(  6895),  INT16_C( 18812),  INT16_C( 23237),
       INT16_C( 28839),  INT16_C( 27310),  INT16_C(  3166), -INT16_C(  2940),  INT16_C( 29847), -INT16_C(  2889), -INT16_C( 13061),  INT16_C(  9172),
      -INT16_C( 10146),  INT16_C( 16496), -INT16_C( 30457), -INT16_C(   976),  INT16_C( 16730), -INT16_C( 10527), -INT16_C( 22646),  INT16_C( 12848),
      -INT16_C(  8425),  INT16_C( 30108),  INT16_C(  8427), -INT16_C( 32151),  INT16_C(  8340), -INT16_C( 28810),  INT16_C( 19181),  INT16_C( 19379),
       INT16_C(  8995),  INT16_C( 10891), -INT16_C( 17491),  INT16_C(  1830),  INT16_C(  2300), -INT16_C( 30755),  INT16_C(  3503), -INT16_C( 14663),
       INT16_C( 21996), -INT16_C( 10437), -INT16_C( 23179),  INT16_C(  2650), -INT16_C( 12091), -INT16_C( 19815),  INT16_C( 19483),  INT16_C( 16125),
      -INT16_C( 30352),  INT16_C(  7528), -INT16_C( 28860),  INT16_C( 16676),  INT16_C(   407),  INT16_C( 18120), -INT16_C( 32498), -INT16_C(  1268),
       INT16_C( 18390),  INT16_C( 19410),  INT16_C( 11500), -INT16_C( 19883), -INT16_C(  4099),  INT16_C(  6244),  INT16_C( 25147), -INT16_C( 21674),
      -INT16_C( 16661),  INT16_C( 12232), -INT16_C(  5043), -INT16_C(  7056),  INT16_C( 14573), -INT16_C(   982),  INT16_C( 14009), -INT16_C( 28681),
      -INT16_C( 13954),  INT16_C( 27355),  INT16_C( 12534), -INT16_C(  3300), -INT16_C( 32481),  INT16_C( 23307),  INT16_C( 25059), -INT16_C( 12794),
      -INT16_C( 12513),  INT16_C( 28157),  INT16_C( 28347), -INT16_C( 22191),  INT16_C( 31910),  INT16_C( 24741), -INT16_C( 25422),  INT16_C( 12527),
      -INT16_C( 13723),  INT16_C( 23451), -INT16_C( 18437),  INT16_C(  6734),  INT16_C( 22840),  INT16_C(  7029),  INT16_C( 31930), -INT16_C(  9495),
      -INT16_C(  6325),  INT16_C(  1607), -INT16_C( 26539), -INT16_C(  1105),  INT16_C( 21524), -INT16_C( 14501),  INT16_C( 19440),  INT16_C( 22263),
      -INT16_C( 28139),  INT16_C(  4273),  INT16_C(    74), -INT16_C( 32213), -INT16_C( 24487),  INT16_C(  5278), -INT16_C( 30948),  INT16_C( 26606),
       INT16_C( 13678), -INT16_C( 15506),  INT16_C(  7629), -INT16_C(  7489),  INT16_C(  6770),  INT16_C( 25257), -INT16_C( 24475),  INT16_C( 31672),
       INT16_C( 27187),  INT16_C( 32139), -INT16_C( 18838), -INT16_C( 15361), -INT16_C( 25257),  INT16_C( 29655), -INT16_C( 15067), -INT16_C( 27685),
       INT16_C( 18938), -INT16_C( 14249),  INT16_C(  5734), -INT16_C( 10070),  INT16_C( 21296), -INT16_C( 27077), -INT16_C(  3085),  INT16_C(  9745),
      -INT16_C( 25507), -INT16_C( 14429), -INT16_C( 23725), -INT16_C( 21877),  INT16_C( 25152),  INT16_C( 25885), -INT16_C(  2008),  INT16_C(  8953),
       INT16_C( 20545), -INT16_C( 22294), -INT16_C( 27546), -INT16_C( 27008), -INT16_C( 17433), -INT16_C(  9428),  INT16_C( 15791),  INT16_C(  3073),
      -INT16_C( 23078),  INT16_C( 11732),  INT16_C( 24392), -INT16_C( 30505), -INT16_C(  2879), -INT16_C(  5650), -INT16_C(  6163),  INT16_C( 11788),
      -INT16_C(  2505), -INT16_C( 25130),  INT16_C( 22411),  INT16_C( 29235),  INT16_C( 24594), -INT16_C( 16051),  INT16_C( 20381),  INT16_C( 30670),
      -INT16_C( 23820),  INT16_C( 15524),  INT16_C( 31489), -INT16_C( 15676), -INT16_C( 19856),  INT16_C( 23980), -INT16_C( 18279), -INT16_C( 12149),
       INT16_C( 25262),  INT16_C( 14701), -INT16_C( 24135), -INT16_C( 13396), -INT16_C(  1791), -INT16_C( 24947),  INT16_C( 23368),  INT16_C( 15382),
      -INT16_C( 17667), -INT16_C(   392),  INT16_C( 15670), -INT16_C( 22848),  INT16_C( 27887), -INT16_C( 30461), -INT16_C( 29148), -INT16_C( 11431),
      -INT16_C( 14352), -INT16_C( 22260), -INT16_C( 18328),  INT16_C( 26997),  INT16_C(   690), -INT16_C(  1529),  INT16_C(  7517),  INT16_C( 23095),
      -INT16_C( 20520),  INT16_C(  3672),  INT16_C(  6380), -INT16_C(  9036), -INT16_C( 18555), -INT16_C( 22171), -INT16_C( 16827),  INT16_C( 13948),
      -INT16_C( 30331), -INT16_C(  4641) };
  static const int16_t b =  INT16_C(  7729);
  static const int16_t e[] =
    {  INT16_C( 20026),  INT16_C( 13697),  INT16_C( 12728), -INT16_C( 31845),  INT16_C(  1527), -INT16_C( 28381), -INT16_C( 26446),  INT16_C( 12548),
       INT16_C( 29307),  INT16_C( 27701),  INT16_C( 10660), -INT16_C(  6297), -INT16_C( 18601), -INT16_C( 13637),  INT16_C( 32719), -INT16_C(  9987),
       INT16_C( 27872),  INT16_C( 14320),  INT16_C( 30866),  INT16_C( 10140), -INT16_C( 29119), -INT16_C(  3175), -INT16_C( 25306), -INT16_C( 29099),
       INT16_C( 18466), -INT16_C( 26946),  INT16_C(  4739), -INT16_C( 14192), -INT16_C(  5717),  INT16_C( 18774),  INT16_C( 21322),  INT16_C(  6227),
       INT16_C( 12498),  INT16_C(   561), -INT16_C(  5219), -INT16_C( 21207), -INT16_C(  8052), -INT16_C( 24622), -INT16_C(  7280),  INT16_C( 20977),
      -INT16_C( 12769),  INT16_C( 24600),  INT16_C( 25812),  INT16_C( 27932),  INT16_C( 16687),  INT16_C( 31383), -INT16_C( 18028),  INT16_C( 21669),
      -INT16_C( 15364),  INT16_C( 14136),  INT16_C( 25202), -INT16_C( 12827), -INT16_C( 23467), -INT16_C( 31666),  INT16_C( 23932),  INT16_C( 22790),
      -INT16_C( 17170), -INT16_C( 20564),  INT16_C( 26114),  INT16_C( 12767), -INT16_C( 27432),  INT16_C( 23004),  INT16_C( 15713),  INT16_C(  6562),
      -INT16_C( 14091),  INT16_C( 21604),  INT16_C(  6156),  INT16_C( 12291),  INT16_C( 20894),  INT16_C(  2021), -INT16_C( 30320), -INT16_C( 25516),
      -INT16_C( 25019),  INT16_C( 25920), -INT16_C(  4604), -INT16_C( 13910),  INT16_C( 17046), -INT16_C( 19432),  INT16_C( 22596),  INT16_C(  2192),
      -INT16_C(  7885),  INT16_C(  3647),  INT16_C( 24844), -INT16_C( 26768), -INT16_C(  3180),  INT16_C(  9315), -INT16_C( 23378), -INT16_C( 15709),
      -INT16_C( 19931),  INT16_C( 10506), -INT16_C( 31839),  INT16_C(  1749), -INT16_C(  9512),  INT16_C(  2508),  INT16_C( 18757),  INT16_C( 13861),
       INT16_C( 21024), -INT16_C(  6058), -INT16_C( 32090),  INT16_C( 10101), -INT16_C( 22696), -INT16_C( 10962), -INT16_C(  4258),  INT16_C( 21143),
      -INT16_C( 24189),  INT16_C( 17069),  INT16_C( 28501), -INT16_C(  5541), -INT16_C( 15091),  INT16_C( 16360), -INT16_C( 21519), -INT16_C(  8136),
       INT16_C( 24286),  INT16_C( 29403), -INT16_C(  4414),  INT16_C(  6749), -INT16_C( 29803), -INT16_C(  7648), -INT16_C( 30884), -INT16_C(   442),
      -INT16_C( 28376),  INT16_C( 19716),  INT16_C( 19987), -INT16_C(  4327), -INT16_C( 12044), -INT16_C(  6895),  INT16_C( 18812),  INT16_C( 23237),
       INT16_C( 28839), -INT16_C( 30497),  INT16_C(  3166), -INT16_C(  2940), -INT16_C( 27960), -INT16_C(  2889), -INT16_C(  5332),  INT16_C( 16901),
      -INT16_C( 10146),  INT16_C( 16496), -INT16_C( 22728), -INT16_C(   976),  INT16_C( 16730), -INT16_C(  2798), -INT16_C( 22646),  INT16_C( 20577),
      -INT16_C(   696),  INT16_C( 30108),  INT16_C(  8427), -INT16_C( 32151),  INT16_C(  8340), -INT16_C( 28810),  INT16_C( 19181),  INT16_C( 19379),
       INT16_C(  8995),  INT16_C( 18620), -INT16_C(  9762),  INT16_C(  9559),  INT16_C(  2300), -INT16_C( 30755),  INT16_C( 11232), -INT16_C( 14663),
       INT16_C( 29725), -INT16_C( 10437), -INT16_C( 23179),  INT16_C(  2650), -INT16_C(  4362), -INT16_C( 19815),  INT16_C( 27212),  INT16_C( 16125),
      -INT16_C( 30352),  INT16_C( 15257), -INT16_C( 28860),  INT16_C( 24405),  INT16_C(   407),  INT16_C( 25849), -INT16_C( 32498),  INT16_C(  6461),
       INT16_C( 26119),  INT16_C( 19410),  INT16_C( 19229), -INT16_C( 12154),  INT16_C(  3630),  INT16_C(  6244), -INT16_C( 32660), -INT16_C( 13945),
      -INT16_C( 16661),  INT16_C( 12232),  INT16_C(  2686),  INT16_C(   673),  INT16_C( 14573), -INT16_C(   982),  INT16_C( 14009), -INT16_C( 28681),
      -INT16_C( 13954),  INT16_C( 27355),  INT16_C( 12534), -INT16_C(  3300), -INT16_C( 32481),  INT16_C( 31036),  INT16_C( 25059), -INT16_C(  5065),
      -INT16_C(  4784),  INT16_C( 28157), -INT16_C( 29460), -INT16_C( 14462), -INT16_C( 25897),  INT16_C( 24741), -INT16_C( 17693),  INT16_C( 20256),
      -INT16_C( 13723),  INT16_C( 31180), -INT16_C( 10708),  INT16_C(  6734),  INT16_C( 30569),  INT16_C( 14758), -INT16_C( 25877), -INT16_C(  1766),
      -INT16_C(  6325),  INT16_C(  9336), -INT16_C( 26539), -INT16_C(  1105),  INT16_C( 21524), -INT16_C(  6772),  INT16_C( 19440),  INT16_C( 22263),
      -INT16_C( 28139),  INT16_C(  4273),  INT16_C(    74), -INT16_C( 32213), -INT16_C( 24487),  INT16_C( 13007), -INT16_C( 30948), -INT16_C( 31201),
       INT16_C( 21407), -INT16_C(  7777),  INT16_C( 15358),  INT16_C(   240),  INT16_C(  6770),  INT16_C( 25257), -INT16_C( 24475),  INT16_C( 31672),
       INT16_C( 27187),  INT16_C( 32139), -INT16_C( 18838), -INT16_C(  7632), -INT16_C( 25257),  INT16_C( 29655), -INT16_C(  7338), -INT16_C( 19956),
       INT16_C( 18938), -INT16_C( 14249),  INT16_C( 13463), -INT16_C( 10070),  INT16_C( 29025), -INT16_C( 27077),  INT16_C(  4644),  INT16_C(  9745),
      -INT16_C( 25507), -INT16_C( 14429), -INT16_C( 23725), -INT16_C( 14148), -INT16_C( 32655), -INT16_C( 31922), -INT16_C(  2008),  INT16_C(  8953),
       INT16_C( 28274), -INT16_C( 14565), -INT16_C( 27546), -INT16_C( 27008), -INT16_C( 17433), -INT16_C(  1699),  INT16_C( 15791),  INT16_C( 10802),
      -INT16_C( 15349),  INT16_C( 19461),  INT16_C( 24392), -INT16_C( 30505),  INT16_C(  4850), -INT16_C(  5650), -INT16_C(  6163),  INT16_C( 19517),
      -INT16_C(  2505), -INT16_C( 17401),  INT16_C( 22411), -INT16_C( 28572),  INT16_C( 32323), -INT16_C( 16051),  INT16_C( 28110),  INT16_C( 30670),
      -INT16_C( 16091),  INT16_C( 15524),  INT16_C( 31489), -INT16_C( 15676), -INT16_C( 19856),  INT16_C( 23980), -INT16_C( 10550), -INT16_C( 12149),
       INT16_C( 25262),  INT16_C( 14701), -INT16_C( 24135), -INT16_C( 13396), -INT16_C(  1791), -INT16_C( 17218),  INT16_C( 31097),  INT16_C( 15382),
      -INT16_C(  9938),  INT16_C(  7337),  INT16_C( 23399), -INT16_C( 22848),  INT16_C( 27887), -INT16_C( 30461), -INT16_C( 21419), -INT16_C(  3702),
      -INT16_C( 14352), -INT16_C( 14531), -INT16_C( 18328), -INT16_C( 30810),  INT16_C(   690), -INT16_C(  1529),  INT16_C( 15246),  INT16_C( 30824),
      -INT16_C( 12791),  INT16_C(  3672),  INT16_C(  6380), -INT16_C(  9036), -INT16_C( 18555), -INT16_C( 22171), -INT16_C( 16827),  INT16_C( 21677),
      -INT16_C( 22602), -INT16_C(  4641) };

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
    rv = simde_svadd_n_s16_m(pv, av, b);

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

    ev = simde_svadd_n_s16_m(pv, av, b);

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
test_simde_svadd_n_s32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0) };
  static const int32_t a[] =
    {  INT32_C(  1045540740),  INT32_C(   828923461),  INT32_C(  1865265613),  INT32_C(   289679535), -INT32_C(  1040907955),  INT32_C(    26836747), -INT32_C(  1670716809),  INT32_C(   575350942),
       INT32_C(   476093911), -INT32_C(   934426373),  INT32_C(   674790009), -INT32_C(   264667997), -INT32_C(  1984876675),  INT32_C(   646597294), -INT32_C(   893193172), -INT32_C(   202633700),
      -INT32_C(  1508881237), -INT32_C(  1922081516),  INT32_C(  2075568088), -INT32_C(  1603539165), -INT32_C(   852943586), -INT32_C(  1795967897), -INT32_C(   983648856),  INT32_C(  1857571779),
      -INT32_C(  1407858537), -INT32_C(    29785050),  INT32_C(  1316613931), -INT32_C(    34675489),  INT32_C(  1774852097),  INT32_C(  1962786252),  INT32_C(   909728627),  INT32_C(  1051062950),
      -INT32_C(   521487686),  INT32_C(  1776165694), -INT32_C(   222865645),  INT32_C(  1039115580), -INT32_C(  1985561923), -INT32_C(   352410761), -INT32_C(  1524549633), -INT32_C(   454834647),
      -INT32_C(  1094398592),  INT32_C(    69706737),  INT32_C(   922148602),  INT32_C(  1098179971),  INT32_C(   399121055), -INT32_C(  1123956546),  INT32_C(   694297088),  INT32_C(  1745700584),
       INT32_C(    69653011),  INT32_C(  1862815093), -INT32_C(  1348010453), -INT32_C(  2081416476), -INT32_C(   224740812), -INT32_C(  2085643133), -INT32_C(  1481895234),  INT32_C(  1796192856),
       INT32_C(    24131212), -INT32_C(  1351583613),  INT32_C(  1532892791),  INT32_C(  1709067824), -INT32_C(  1957201656), -INT32_C(   754055403),  INT32_C(  1903868697),  INT32_C(    31230581),
       INT32_C(  1124224192),  INT32_C(  1022522053), -INT32_C(  1181265783), -INT32_C(  1491176034),  INT32_C(    53638894), -INT32_C(  1764277891),  INT32_C(  1896305148), -INT32_C(  1686969381),
      -INT32_C(   169905104),  INT32_C(  1865535974), -INT32_C(  1071003614),  INT32_C(   744965949),  INT32_C(   976198333), -INT32_C(   674232613),  INT32_C(   860411736), -INT32_C(   338707781),
       INT32_C(   350268974), -INT32_C(  1585180289),  INT32_C(   375565785), -INT32_C(  1304245772),  INT32_C(  1055683171), -INT32_C(   803881608),  INT32_C(  1325686164),  INT32_C(  1161483031),
       INT32_C(     5905025),  INT32_C(    77782571),  INT32_C(  2132477067),  INT32_C(   825318861),  INT32_C(  1215241935),  INT32_C(  1863878107), -INT32_C(    88138526),  INT32_C(  1883240943),
       INT32_C(  1064409364),  INT32_C(    38015863), -INT32_C(   461218025), -INT32_C(  1944734788), -INT32_C(  1395358255), -INT32_C(   333648886), -INT32_C(   119088375), -INT32_C(   395761964),
       INT32_C(   925424319),  INT32_C(    70872301), -INT32_C(  2014790709),  INT32_C(  1075052143), -INT32_C(  1913788541), -INT32_C(   579270188), -INT32_C(  1193975580),  INT32_C(  1168195206),
       INT32_C(    92064024),  INT32_C(      636469), -INT32_C(   527961487),  INT32_C(  1931582448),  INT32_C(  1442844290), -INT32_C(    80512745),  INT32_C(  1605568985),  INT32_C(  1621447751),
       INT32_C(  1382359325),  INT32_C(  1230139351),  INT32_C(  1361697377), -INT32_C(   138130827),  INT32_C(  1867433048),  INT32_C(   392855869), -INT32_C(   764010870), -INT32_C(  1875764366),
       INT32_C(   350394173),  INT32_C(  1734161670), -INT32_C(  2068281585),  INT32_C(   712735953),  INT32_C(  2124007744), -INT32_C(   711654325), -INT32_C(  1800991966),  INT32_C(  1680136487),
       INT32_C(  2004354929),  INT32_C(  1272960572),  INT32_C(   785356637),  INT32_C(  1415072276),  INT32_C(  1607660052),  INT32_C(   406087670), -INT32_C(  1699947405),  INT32_C(   654234037),
       INT32_C(   345929432), -INT32_C(  1453359796),  INT32_C(   685256212), -INT32_C(  1937952648),  INT32_C(   418074402),  INT32_C(   707797175), -INT32_C(  1312498180), -INT32_C(  2032614738),
      -INT32_C(  2053474760),  INT32_C(   120519155), -INT32_C(  1624242649),  INT32_C(  1496100151), -INT32_C(  1284368388),  INT32_C(   870162999),  INT32_C(   770023807), -INT32_C(  1665942173),
       INT32_C(   639716659),  INT32_C(  1831685958), -INT32_C(  1928503978),  INT32_C(   132528394), -INT32_C(  2001053616),  INT32_C(  2059114747), -INT32_C(  1649893319), -INT32_C(  1875289251),
      -INT32_C(   273261911), -INT32_C(    10623831),  INT32_C(  1284270657), -INT32_C(   212634717), -INT32_C(   965014069), -INT32_C(   549374043),  INT32_C(   897378775), -INT32_C(   305810108),
      -INT32_C(  1193444337), -INT32_C(  1581761952),  INT32_C(  1206731940), -INT32_C(  2093334345), -INT32_C(   213273010), -INT32_C(   992834835), -INT32_C(  1191621005),  INT32_C(   312852227),
      -INT32_C(  1681161669),  INT32_C(  1614578620),  INT32_C(  2141661895), -INT32_C(  1207770518), -INT32_C(  2052306024),  INT32_C(  1229553366), -INT32_C(   805223475),  INT32_C(  1038329602),
      -INT32_C(   422007255), -INT32_C(   129625039), -INT32_C(  1451758018),  INT32_C(  1751218640), -INT32_C(  1678963259),  INT32_C(  1508128396),  INT32_C(  2066343545), -INT32_C(  1229452147),
      -INT32_C(   342060870), -INT32_C(   471538779), -INT32_C(  1584636975), -INT32_C(  1710625067), -INT32_C(  2026506501), -INT32_C(  1495262932), -INT32_C(  1943991553), -INT32_C(   784082410),
       INT32_C(   264036202), -INT32_C(  1812750142), -INT32_C(   785088516),  INT32_C(  1768635757),  INT32_C(  1626382387), -INT32_C(  1190735431), -INT32_C(   247126053),  INT32_C(  1824688129),
       INT32_C(   712736616),  INT32_C(   465464863),  INT32_C(  1542255342),  INT32_C(  1673811760), -INT32_C(  1312573961),  INT32_C(  1634388358), -INT32_C(   229462031), -INT32_C(  1604446920),
      -INT32_C(  1278551404),  INT32_C(   919570504) };
  static const int32_t b =  INT32_C(   536538891);
  static const int32_t e[] =
    {  INT32_C(           0),  INT32_C(  1365462352), -INT32_C(  1893162792),  INT32_C(           0),  INT32_C(           0),  INT32_C(   563375638),  INT32_C(           0),  INT32_C(  1111889833),
       INT32_C(  1012632802), -INT32_C(   397887482),  INT32_C(           0),  INT32_C(   271870894), -INT32_C(  1448337784),  INT32_C(  1183136185), -INT32_C(   356654281),  INT32_C(   333905191),
      -INT32_C(   972342346),  INT32_C(           0), -INT32_C(  1682860317), -INT32_C(  1067000274),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(   871319646),  INT32_C(   506753841),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1446267518),  INT32_C(           0),
       INT32_C(           0), -INT32_C(  1982262711),  INT32_C(   313673246),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(    81704244),
       INT32_C(           0),  INT32_C(           0),  INT32_C(  1458687493),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1230835979), -INT32_C(  2012727821),
       INT32_C(   606191902), -INT32_C(  1895613312),  INT32_C(           0), -INT32_C(  1544877585),  INT32_C(           0), -INT32_C(  1549104242), -INT32_C(   945356343),  INT32_C(           0),
       INT32_C(           0), -INT32_C(   815044722),  INT32_C(  2069431682), -INT32_C(  2049360581),  INT32_C(           0), -INT32_C(   217516512), -INT32_C(  1854559708),  INT32_C(           0),
       INT32_C(  1660763083),  INT32_C(  1559060944),  INT32_C(           0), -INT32_C(   954637143),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1512737224), -INT32_C(   137693722),  INT32_C(  1396950627),  INT32_C(           0),
       INT32_C(   886807865), -INT32_C(  1048641398),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1592222062),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1698021922),
       INT32_C(   542443916),  INT32_C(   614321462), -INT32_C(  1625951338),  INT32_C(  1361857752),  INT32_C(           0), -INT32_C(  1894550298),  INT32_C(   448400365),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1408195897),  INT32_C(           0),  INT32_C(   202890005),  INT32_C(   417450516),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1377249650), -INT32_C(    42731297),  INT32_C(           0),  INT32_C(  1704734097),
       INT32_C(   628602915),  INT32_C(           0),  INT32_C(     8577404), -INT32_C(  1826845957),  INT32_C(           0),  INT32_C(           0),  INT32_C(  2142107876), -INT32_C(  2136980654),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   398408064),  INT32_C(           0),  INT32_C(           0), -INT32_C(   227471979),  INT32_C(           0),
       INT32_C(           0), -INT32_C(  2024266735),  INT32_C(           0),  INT32_C(  1249274844), -INT32_C(  1634420661), -INT32_C(   175115434),  INT32_C(           0), -INT32_C(  2078291918),
       INT32_C(           0),  INT32_C(  1809499463),  INT32_C(  1321895528),  INT32_C(  1951611167),  INT32_C(  2144198943),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1190772928),
       INT32_C(   882468323), -INT32_C(   916820905),  INT32_C(  1221795103),  INT32_C(           0),  INT32_C(   954613293),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1496075847),
       INT32_C(           0),  INT32_C(           0), -INT32_C(  1087703758),  INT32_C(  2032639042),  INT32_C(           0),  INT32_C(  1406701890),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1699313658),  INT32_C(           0), -INT32_C(  1338750360),
       INT32_C(   263276980),  INT32_C(           0),  INT32_C(  1820809548),  INT32_C(           0),  INT32_C(           0), -INT32_C(    12835152),  INT32_C(           0),  INT32_C(   230728783),
       INT32_C(           0),  INT32_C(           0),  INT32_C(  1743270831), -INT32_C(  1556795454),  INT32_C(   323265881), -INT32_C(   456295944),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(  1144622778), -INT32_C(  2143849785),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1574868493),
       INT32_C(           0),  INT32_C(           0), -INT32_C(   915219127),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1692084860),  INT32_C(           0),
       INT32_C(   194478021),  INT32_C(           0), -INT32_C(  1048098084), -INT32_C(  1174086176), -INT32_C(  1489967610),  INT32_C(           0),  INT32_C(           0), -INT32_C(   247543519),
       INT32_C(   800575093),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1989792648), -INT32_C(  2132046018),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(  1249275507),  INT32_C(           0),  INT32_C(  2078794233),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   307076860), -INT32_C(  1067908029),
      -INT32_C(   742012513),  INT32_C(           0) };

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
    rv = simde_svadd_n_s32_z(pv, av, b);

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

    ev = simde_svadd_n_s32_z(pv, av, b);

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
test_simde_svadd_n_s32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) };
  static const int32_t a[] =
    {  INT32_C(   690600000),  INT32_C(   350376562), -INT32_C(   735630887), -INT32_C(  1169159675),  INT32_C(   752911486), -INT32_C(  1551276821),  INT32_C(  1326768045), -INT32_C(    17844802),
      -INT32_C(   551020435),  INT32_C(  1140001386),  INT32_C(   957880884), -INT32_C(  1561106396), -INT32_C(   674245396), -INT32_C(   444901320), -INT32_C(   181039305), -INT32_C(  1309399996),
      -INT32_C(  1500505028),  INT32_C(  1525252902), -INT32_C(  1030487651),  INT32_C(  1432651625), -INT32_C(  1808977061), -INT32_C(  1032214389),  INT32_C(  2075700791),  INT32_C(   237808850),
      -INT32_C(   290145080), -INT32_C(   599155137),  INT32_C(   161406367), -INT32_C(  1067580572), -INT32_C(  1034646730),  INT32_C(  1787088179),  INT32_C(  1323646076), -INT32_C(  1336077848),
       INT32_C(   211751373),  INT32_C(  1340729519),  INT32_C(   693667781), -INT32_C(  1041647990),  INT32_C(  1971535170), -INT32_C(  2015361269),  INT32_C(   752207172), -INT32_C(  1529007401),
      -INT32_C(   206472124),  INT32_C(   692230756), -INT32_C(  1403872735), -INT32_C(  1821557679), -INT32_C(  2079788935),  INT32_C(   990636279), -INT32_C(  2056724050),  INT32_C(  1462322451),
       INT32_C(   625728193), -INT32_C(  1773236876),  INT32_C(  2034409512),  INT32_C(  1443672028), -INT32_C(  1764092769), -INT32_C(  1412241667), -INT32_C(   634373433),  INT32_C(  1077041535),
      -INT32_C(  1469743820),  INT32_C(   842969866),  INT32_C(   816545875), -INT32_C(   830032081), -INT32_C(   916102964),  INT32_C(   225720134), -INT32_C(   253189007),  INT32_C(   825236221),
      -INT32_C(  1579510377), -INT32_C(  1680598968), -INT32_C(   926187623),  INT32_C(    60248375), -INT32_C(   120783694), -INT32_C(  1543094221), -INT32_C(   510333212), -INT32_C(  1626094584),
      -INT32_C(  1589580455), -INT32_C(  1640229883), -INT32_C(   882440044),  INT32_C(   198114905),  INT32_C(   755276538), -INT32_C(  1093596454),  INT32_C(    10446328), -INT32_C(  2103463383),
      -INT32_C(  1524375649), -INT32_C(  2008850444), -INT32_C(  1051481497), -INT32_C(  1563680344), -INT32_C(  1781542725), -INT32_C(   766271270),  INT32_C(   785576453),  INT32_C(  1152414117),
       INT32_C(  1172951889), -INT32_C(  1697829581), -INT32_C(  2141511465), -INT32_C(    64870335), -INT32_C(   745409800), -INT32_C(  1733958510),  INT32_C(  2076604630),  INT32_C(   985692137),
       INT32_C(  2105518410), -INT32_C(  1374139178), -INT32_C(  1389464724), -INT32_C(  1800843109), -INT32_C(   714655166), -INT32_C(   177402850),  INT32_C(  1852846980), -INT32_C(   173526870),
      -INT32_C(  1334695718), -INT32_C(   513897868), -INT32_C(  1718711042),  INT32_C(   523057373), -INT32_C(  1846242190),  INT32_C(   629563809),  INT32_C(  1066661525),  INT32_C(    20200487),
      -INT32_C(   659445916),  INT32_C(   800657457),  INT32_C(  2043234460), -INT32_C(   224790912),  INT32_C(   746818955), -INT32_C(  2075063825),  INT32_C(   667149568), -INT32_C(  2060912607),
      -INT32_C(   799155809), -INT32_C(  2046814231), -INT32_C(   536884897),  INT32_C(  1255250111),  INT32_C(   360076582),  INT32_C(  1587136606), -INT32_C(   830120787), -INT32_C(   212619948),
       INT32_C(  1891938439),  INT32_C(   653706439),  INT32_C(  1275459213), -INT32_C(  1265117298), -INT32_C(  1966535380), -INT32_C(  2098634027),  INT32_C(   324038335), -INT32_C(  1559780580),
       INT32_C(   454282068),  INT32_C(   474090127), -INT32_C(  1905768704),  INT32_C(  1245970206), -INT32_C(   489354227),  INT32_C(   778419823),  INT32_C(  1212265772), -INT32_C(  1377089447),
      -INT32_C(  1563885805),  INT32_C(   163449353),  INT32_C(  1888954194),  INT32_C(   867949094),  INT32_C(  1444319463),  INT32_C(  2055502670), -INT32_C(  1983658704),  INT32_C(   557231630),
      -INT32_C(  1228603475),  INT32_C(  1539277321), -INT32_C(   791914583),  INT32_C(   402884401),  INT32_C(  1701714199), -INT32_C(   975179116), -INT32_C(   967925064), -INT32_C(    18381487),
      -INT32_C(  1917473916), -INT32_C(   672566226), -INT32_C(    39340597),  INT32_C(  1393929020),  INT32_C(  1505264836),  INT32_C(   773756790), -INT32_C(  1946915782),  INT32_C(  1971969265),
      -INT32_C(  1258078585),  INT32_C(  2123230387), -INT32_C(   579128159), -INT32_C(  1540320801), -INT32_C(  1946294251), -INT32_C(  1178985601),  INT32_C(  2034544263),  INT32_C(   317640330),
      -INT32_C(  1077415668),  INT32_C(  2118014173),  INT32_C(  1750841737),  INT32_C(  1594657610), -INT32_C(   202700429), -INT32_C(  1397971676), -INT32_C(   567938733), -INT32_C(   873458753),
      -INT32_C(   494160123), -INT32_C(  1788753652), -INT32_C(   839009150), -INT32_C(  1154741688),  INT32_C(   950933267),  INT32_C(   283401148),  INT32_C(   200149324),  INT32_C(   567729692),
      -INT32_C(  1593548395), -INT32_C(  1388944086),  INT32_C(  1769616417),  INT32_C(  1361421886),  INT32_C(  2055852990),  INT32_C(  2055892270), -INT32_C(  1819969418), -INT32_C(   323724202),
      -INT32_C(   393365315),  INT32_C(  1066779677),  INT32_C(   916983800),  INT32_C(  1938279861), -INT32_C(   806481503), -INT32_C(   179668866),  INT32_C(  1200148465), -INT32_C(   382518229),
       INT32_C(   315736565),  INT32_C(  2102486661),  INT32_C(   716438133),  INT32_C(  1755200199), -INT32_C(   902263733), -INT32_C(   171998716),  INT32_C(  2101167953),  INT32_C(  2019979395),
      -INT32_C(  1232390351),  INT32_C(   305388701), -INT32_C(  1640175914),  INT32_C(  1812388385),  INT32_C(  1798717030),  INT32_C(   308344256), -INT32_C(  1064329924),  INT32_C(  1060697358),
      -INT32_C(   906575060),  INT32_C(  1994074528),  INT32_C(   823400208),  INT32_C(  1486691314),  INT32_C(   449041497),  INT32_C(   103556297), -INT32_C(   809059391), -INT32_C(   602931536),
       INT32_C(  1654982082),  INT32_C(  1054375982), -INT32_C(  1989153385),  INT32_C(  1642204424), -INT32_C(  1434737183), -INT32_C(  1951356983),  INT32_C(   307918434),  INT32_C(   938371445),
      -INT32_C(  1650879634), -INT32_C(  1411682029),  INT32_C(  1714703198),  INT32_C(   969414232) };
  static const int32_t b =  INT32_C(  1615896735);
  static const int32_t e[] =
    { -INT32_C(  1988470561),  INT32_C(  1966273297),  INT32_C(   880265848), -INT32_C(  1169159675), -INT32_C(  1926159075), -INT32_C(  1551276821),  INT32_C(  1326768045),  INT32_C(  1598051933),
      -INT32_C(   551020435),  INT32_C(  1140001386),  INT32_C(   957880884), -INT32_C(  1561106396),  INT32_C(   941651339),  INT32_C(  1170995415), -INT32_C(   181039305),  INT32_C(   306496739),
       INT32_C(   115391707),  INT32_C(  1525252902), -INT32_C(  1030487651),  INT32_C(  1432651625), -INT32_C(  1808977061),  INT32_C(   583682346), -INT32_C(   603369770),  INT32_C(   237808850),
      -INT32_C(   290145080), -INT32_C(   599155137),  INT32_C(  1777303102), -INT32_C(  1067580572),  INT32_C(   581250005),  INT32_C(  1787088179), -INT32_C(  1355424485),  INT32_C(   279818887),
       INT32_C(   211751373), -INT32_C(  1338341042),  INT32_C(   693667781),  INT32_C(   574248745), -INT32_C(   707535391), -INT32_C(   399464534),  INT32_C(   752207172), -INT32_C(  1529007401),
       INT32_C(  1409424611),  INT32_C(   692230756), -INT32_C(  1403872735), -INT32_C(  1821557679), -INT32_C(  2079788935),  INT32_C(   990636279), -INT32_C(   440827315),  INT32_C(  1462322451),
      -INT32_C(  2053342368), -INT32_C(   157340141), -INT32_C(   644661049), -INT32_C(  1235398533), -INT32_C(  1764092769), -INT32_C(  1412241667),  INT32_C(   981523302), -INT32_C(  1602029026),
      -INT32_C(  1469743820),  INT32_C(   842969866),  INT32_C(   816545875),  INT32_C(   785864654), -INT32_C(   916102964),  INT32_C(  1841616869),  INT32_C(  1362707728),  INT32_C(   825236221),
       INT32_C(    36386358), -INT32_C(  1680598968),  INT32_C(   689709112),  INT32_C(    60248375), -INT32_C(   120783694),  INT32_C(    72802514),  INT32_C(  1105563523), -INT32_C(  1626094584),
       INT32_C(    26316280), -INT32_C(    24333148),  INT32_C(   733456691),  INT32_C(   198114905), -INT32_C(  1923794023),  INT32_C(   522300281),  INT32_C(    10446328), -INT32_C(  2103463383),
       INT32_C(    91521086), -INT32_C(   392953709),  INT32_C(   564415238),  INT32_C(    52216391), -INT32_C(   165645990), -INT32_C(   766271270),  INT32_C(   785576453),  INT32_C(  1152414117),
      -INT32_C(  1506118672), -INT32_C(  1697829581), -INT32_C(   525614730), -INT32_C(    64870335),  INT32_C(   870486935), -INT32_C(  1733958510), -INT32_C(   602465931), -INT32_C(  1693378424),
      -INT32_C(   573552151),  INT32_C(   241757557),  INT32_C(   226432011), -INT32_C(   184946374), -INT32_C(   714655166),  INT32_C(  1438493885),  INT32_C(  1852846980),  INT32_C(  1442369865),
       INT32_C(   281201017),  INT32_C(  1101998867), -INT32_C(  1718711042),  INT32_C(   523057373), -INT32_C(  1846242190), -INT32_C(  2049506752), -INT32_C(  1612409036),  INT32_C(    20200487),
       INT32_C(   956450819),  INT32_C(   800657457), -INT32_C(   635836101),  INT32_C(  1391105823), -INT32_C(  1932251606), -INT32_C(  2075063825),  INT32_C(   667149568), -INT32_C(  2060912607),
      -INT32_C(   799155809), -INT32_C(   430917496),  INT32_C(  1079011838), -INT32_C(  1423820450),  INT32_C(  1975973317), -INT32_C(  1091933955), -INT32_C(   830120787),  INT32_C(  1403276787),
      -INT32_C(   787132122), -INT32_C(  2025364122), -INT32_C(  1403611348),  INT32_C(   350779437), -INT32_C(  1966535380), -INT32_C(   482737292),  INT32_C(   324038335), -INT32_C(  1559780580),
       INT32_C(  2070178803),  INT32_C(   474090127), -INT32_C(   289871969), -INT32_C(  1433100355),  INT32_C(  1126542508),  INT32_C(   778419823), -INT32_C(  1466804789), -INT32_C(  1377089447),
       INT32_C(    52010930),  INT32_C(   163449353), -INT32_C(   790116367),  INT32_C(   867949094),  INT32_C(  1444319463), -INT32_C(   623567891), -INT32_C(  1983658704),  INT32_C(   557231630),
       INT32_C(   387293260), -INT32_C(  1139793240),  INT32_C(   823982152),  INT32_C(  2018781136),  INT32_C(  1701714199), -INT32_C(   975179116),  INT32_C(   647971671),  INT32_C(  1597515248),
      -INT32_C(  1917473916), -INT32_C(   672566226), -INT32_C(    39340597),  INT32_C(  1393929020),  INT32_C(  1505264836), -INT32_C(  1905313771), -INT32_C(   331019047),  INT32_C(  1971969265),
      -INT32_C(  1258078585),  INT32_C(  2123230387),  INT32_C(  1036768576),  INT32_C(    75575934), -INT32_C(   330397516), -INT32_C(  1178985601),  INT32_C(  2034544263),  INT32_C(  1933537065),
       INT32_C(   538481067),  INT32_C(  2118014173),  INT32_C(  1750841737), -INT32_C(  1084412951),  INT32_C(  1413196306),  INT32_C(   217925059), -INT32_C(   567938733), -INT32_C(   873458753),
      -INT32_C(   494160123), -INT32_C(   172856917),  INT32_C(   776887585),  INT32_C(   461155047),  INT32_C(   950933267),  INT32_C(  1899297883),  INT32_C(  1816046059), -INT32_C(  2111340869),
       INT32_C(    22348340), -INT32_C(  1388944086), -INT32_C(   909454144),  INT32_C(  1361421886),  INT32_C(  2055852990),  INT32_C(  2055892270), -INT32_C(   204072683), -INT32_C(   323724202),
      -INT32_C(   393365315),  INT32_C(  1066779677), -INT32_C(  1762086761), -INT32_C(   740790700), -INT32_C(   806481503), -INT32_C(   179668866),  INT32_C(  1200148465), -INT32_C(   382518229),
       INT32_C(   315736565),  INT32_C(  2102486661),  INT32_C(   716438133), -INT32_C(   923870362),  INT32_C(   713633002),  INT32_C(  1443898019), -INT32_C(   577902608),  INT32_C(  2019979395),
      -INT32_C(  1232390351),  INT32_C(  1921285436), -INT32_C(  1640175914), -INT32_C(   866682176), -INT32_C(   880353531),  INT32_C(   308344256),  INT32_C(   551566811), -INT32_C(  1618373203),
       INT32_C(   709321675),  INT32_C(  1994074528), -INT32_C(  1855670353),  INT32_C(  1486691314),  INT32_C(   449041497),  INT32_C(  1719453032),  INT32_C(   806837344), -INT32_C(   602931536),
       INT32_C(  1654982082), -INT32_C(  1624694579), -INT32_C(   373256650),  INT32_C(  1642204424),  INT32_C(   181159552), -INT32_C(  1951356983),  INT32_C(   307918434), -INT32_C(  1740699116),
      -INT32_C(    34982899),  INT32_C(   204214706), -INT32_C(   964367363), -INT32_C(  1709656329) };

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
    rv = simde_svadd_n_s32_m(pv, av, b);

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

    ev = simde_svadd_n_s32_m(pv, av, b);

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
test_simde_svadd_n_s64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0) };
  static const int64_t a[] =
    { -INT64_C( 3041370264042532993), -INT64_C( 1550911017691325879), -INT64_C( 6358913015238569448), -INT64_C( 4818221310792475399),
      -INT64_C( 7206502320785166004),  INT64_C( 7549885999855911223),  INT64_C( 8240710430538981224), -INT64_C( 1929364075383137474),
       INT64_C( 6909377421440306422), -INT64_C(  359440712271593909),  INT64_C( 5029690684080203233), -INT64_C( 6059880593254961047),
       INT64_C( 5282395799092982726),  INT64_C( 7954457060897491668), -INT64_C( 8477579754721438707), -INT64_C( 2655309497990636858),
      -INT64_C( 4347072123868931738), -INT64_C( 8746397874668269149), -INT64_C( 4373571391872931935), -INT64_C( 5549450362689234675),
      -INT64_C( 9065813260026657155), -INT64_C( 8551683785921242541), -INT64_C( 1406924222478095176), -INT64_C( 7390114394957564045),
      -INT64_C( 7263966137681541424), -INT64_C( 1440948245765823601),  INT64_C( 6372623045804248229),  INT64_C( 6379217518885043922),
       INT64_C( 5977184641592364303), -INT64_C( 5098698114004854243), -INT64_C( 3795497672257905131),  INT64_C(  147845778226375468),
       INT64_C( 7774142381612996046), -INT64_C( 8325474047773332057), -INT64_C( 8170415510294907944),  INT64_C( 7150396335710164293),
      -INT64_C( 8494113378980817564), -INT64_C( 6014633353418515579),  INT64_C( 3340854990577929837),  INT64_C( 6009952474715627374),
      -INT64_C( 5069604899813696456),  INT64_C( 1333413647614274048), -INT64_C( 8763373651238977974), -INT64_C( 6547967309077886498),
       INT64_C( 5493095549794002766),  INT64_C( 8504943631463935823),  INT64_C(  377751683975473312),  INT64_C(  713524477061941717),
       INT64_C( 6607279880579819033),  INT64_C( 1393677665395790517), -INT64_C( 2203656544287260609),  INT64_C( 5302717186104770003),
      -INT64_C( 7127402807569800529), -INT64_C(  307980093291076302),  INT64_C( 7044699156193051862), -INT64_C( 7025185586005678839),
      -INT64_C( 4454500314735103832),  INT64_C( 6380229042240990420), -INT64_C( 4497409685284262747), -INT64_C( 5517055727807855390),
       INT64_C(  863972285068134571),  INT64_C( 3096268198695953694),  INT64_C( 1337273525993353748), -INT64_C( 5821375293295458185),
       INT64_C(  746727739920906778),  INT64_C( 3818387420448815181), -INT64_C( 4244767658030900266),  INT64_C( 7406589927511095830),
      -INT64_C( 1662368552663403528),  INT64_C( 1396318457367861516),  INT64_C(  443095418026877203), -INT64_C( 1955149461388759510),
      -INT64_C( 5395110416159828580), -INT64_C( 6440074265631728816),  INT64_C( 1412211538886375843),  INT64_C( 4498366650114554268),
       INT64_C( 4421294506150082301),  INT64_C( 2570547684935679346),  INT64_C( 9088633355321652260),  INT64_C( 1218633901497887496),
       INT64_C( 7626022394355146667),  INT64_C( 3527192674994987087),  INT64_C(   85673918945208783),  INT64_C( 6282123096709936906),
       INT64_C( 5067893149304612340), -INT64_C( 5863112913898257563),  INT64_C( 5309057039360581810), -INT64_C( 2104422449983039033),
      -INT64_C( 1893726812038645125), -INT64_C( 8470715818528289052),  INT64_C( 2837798142554263768), -INT64_C( 2806757012659320773),
      -INT64_C( 2340740427569964768), -INT64_C( 6038179400575165486), -INT64_C( 8688811146091468316), -INT64_C( 8420115659770231315),
       INT64_C( 5148088764247732374),  INT64_C(  795207660217635722), -INT64_C( 2422168101659357810),  INT64_C( 7400909318132470719),
       INT64_C( 1836177336873574591),  INT64_C( 2282903424124480636),  INT64_C( 8583118406943440205),  INT64_C( 6171435167205377903),
      -INT64_C( 8944425907787293385),  INT64_C( 2459481982345041264), -INT64_C( 1873076918121587758),  INT64_C( 3508527282046476997),
      -INT64_C( 5768595183558575512), -INT64_C( 4673661172431448021), -INT64_C( 4086653812745861908), -INT64_C( 6838766363022823699),
       INT64_C( 1079177136437136652),  INT64_C( 7549494759103834649),  INT64_C( 5079520904800374709),  INT64_C( 9177848354513461380),
      -INT64_C( 8700175552515248815),  INT64_C( 4058679510953709935), -INT64_C( 5115405049674129566), -INT64_C( 4322940574740631794),
      -INT64_C(   56510977688351935),  INT64_C( 8811078369529218444), -INT64_C( 5527262937700026787), -INT64_C( 2981886985562177178),
       INT64_C( 6886213641843414785),  INT64_C( 1447262655460833923), -INT64_C( 1710257890395796757) };
  static const int64_t b = -INT64_C( 1934068016765491977);
  static const int64_t e[] =
    { -INT64_C( 4975438280808024970), -INT64_C( 3484979034456817856), -INT64_C( 8292981032004061425),  INT64_C(                   0),
      -INT64_C( 9140570337550657981),  INT64_C( 5615817983090419246),  INT64_C( 6306642413773489247), -INT64_C( 3863432092148629451),
       INT64_C(                   0), -INT64_C( 2293508729037085886),  INT64_C(                   0), -INT64_C( 7993948610020453024),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C( 8035096302222620932), -INT64_C( 4589377514756128835),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 7483518379454726652),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C( 3340992239243587153),  INT64_C(                   0),
      -INT64_C( 9198034154447033401),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 4445149502119551945),
       INT64_C( 4043116624826872326),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 1786222238539116509),
       INT64_C( 5840074364847504069),  INT64_C(                   0),  INT64_C( 8342260546649151695),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1406786973812437860),  INT64_C(                   0),
      -INT64_C( 7003672916579188433), -INT64_C(  600654369151217929),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C( 3559027533028510789),  INT64_C( 6570875614698443846),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C( 2242048110056568279),  INT64_C( 5110631139427559885),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C( 4446161025475498443),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(  596794490772138229),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(  537749559397630461),  INT64_C(                   0), -INT64_C( 3889217478154251487),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(  521856477879116134),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(  636479668170187369),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C( 5691954377589654690),  INT64_C( 1593124658229495110),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C( 3374989022595089833), -INT64_C( 4038490466748531010),
       INT64_C(                   0),  INT64_C( 8041960238415770587),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C( 4274808444335456745),  INT64_C(                   0),  INT64_C( 7823864910852591323),  INT64_C(                   0),
       INT64_C( 3214020747482240397),  INT64_C(                   0), -INT64_C( 4356236118424849787),  INT64_C( 5466841301366978742),
      -INT64_C(   97890679891917386),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C( 7568250149156766254),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1574459265280985020),
      -INT64_C( 7702663200324067489), -INT64_C( 6607729189196939998), -INT64_C( 6020721829511353885),  INT64_C(                   0),
      -INT64_C(  854890880328355325),  INT64_C( 5615426742338342672),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C( 2124611494188217958), -INT64_C( 7049473066439621543), -INT64_C( 6257008591506123771),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 4915955002327669155),
       INT64_C( 4952145625077922808), -INT64_C(  486805361304658054),  INT64_C(                   0) };

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
    rv = simde_svadd_n_s64_z(pv, av, b);

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

    ev = simde_svadd_n_s64_z(pv, av, b);

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
test_simde_svadd_n_s64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0) };
  static const int64_t a[] =
    {  INT64_C( 4385304339233299824), -INT64_C( 7908739297284643427), -INT64_C(  135170003126576401),  INT64_C( 4711793048360029825),
      -INT64_C( 5273988832202826108),  INT64_C( 8016936750219983916), -INT64_C( 1976031974139454469),  INT64_C( 7230950177662253640),
      -INT64_C( 5067738642656033316),  INT64_C( 3076426040913448642),  INT64_C( 5587930322407672645),  INT64_C(  202872154979936139),
       INT64_C( 5875969972638369860), -INT64_C( 2140823231214128143), -INT64_C( 1810140996931286641),  INT64_C( 5397038616445863870),
       INT64_C( 8343665438476787434),  INT64_C( 3466046172241878426),  INT64_C( 8658353602534155239), -INT64_C( 8701444188167963923),
      -INT64_C( 7271402439964599775),  INT64_C( 8140516402996161063),  INT64_C( 5891511386838842768), -INT64_C( 9117392993223631276),
       INT64_C( 7600171004545235165), -INT64_C( 3900353425640960795), -INT64_C( 4567541260967767577),  INT64_C( 4743743293382320627),
       INT64_C( 1895057995644008865), -INT64_C( 8149431033234162203), -INT64_C( 4457026722585773319), -INT64_C( 6701942282086066345),
      -INT64_C( 7263230098759410460),  INT64_C( 2054944505823083343),  INT64_C( 3039268750516903323),  INT64_C( 1378350175300699005),
      -INT64_C( 4084941369273178625),  INT64_C( 4997098560491948314), -INT64_C(   99960444152653153),  INT64_C( 7161739787110220321),
       INT64_C(  612603824327659330),  INT64_C( 2260982385485430384),  INT64_C( 1223060377765548154),  INT64_C( 6086829378826696368),
       INT64_C( 7514413175145402450), -INT64_C( 6310419189861216564), -INT64_C( 2453727130368606477),  INT64_C( 7456107297152061970),
      -INT64_C( 2135850716401006597), -INT64_C( 5380504398681088386), -INT64_C( 6439433249418119271), -INT64_C(  407781375206517541),
       INT64_C( 7765411844045274828),  INT64_C( 2854556000346174247), -INT64_C( 7449921637523311518),  INT64_C( 8583262390966576932),
       INT64_C( 8734201868279417565),  INT64_C( 2073907326152232465),  INT64_C( 7533024937856119860), -INT64_C( 3514873748596780523),
      -INT64_C( 4503932027697196622),  INT64_C( 1437819122911141919), -INT64_C( 3924447596465813795),  INT64_C( 7954415482051368097),
      -INT64_C( 1313660423673545389),  INT64_C( 3081511412892575184), -INT64_C(  486436762637580095), -INT64_C( 2444628264668575256),
       INT64_C( 5091782778800932333), -INT64_C( 1566486134207909942),  INT64_C( 5463604544856428162),  INT64_C( 4310228856493530984),
       INT64_C( 2540769443852039047) };
  static const int64_t b =  INT64_C( 5966763865864937505);
  static const int64_t e[] =
    {  INT64_C( 4385304339233299824), -INT64_C( 7908739297284643427),  INT64_C( 5831593862738361104),  INT64_C( 4711793048360029825),
       INT64_C(  692775033662111397), -INT64_C( 4463043457624630195),  INT64_C( 3990731891725483036),  INT64_C( 7230950177662253640),
       INT64_C(  899025223208904189),  INT64_C( 3076426040913448642), -INT64_C( 6892049885436941466),  INT64_C( 6169636020844873644),
      -INT64_C( 6604010235206244251),  INT64_C( 3825940634650809362), -INT64_C( 1810140996931286641),  INT64_C( 5397038616445863870),
       INT64_C( 8343665438476787434),  INT64_C( 3466046172241878426),  INT64_C( 8658353602534155239), -INT64_C( 2734680322303026418),
      -INT64_C( 1304638574099662270),  INT64_C( 8140516402996161063), -INT64_C( 6588468821005771343), -INT64_C( 3150629127358693771),
       INT64_C( 7600171004545235165), -INT64_C( 3900353425640960795), -INT64_C( 4567541260967767577), -INT64_C( 7736236914462293484),
       INT64_C( 7861821861508946370), -INT64_C( 8149431033234162203),  INT64_C( 1509737143279164186), -INT64_C( 6701942282086066345),
      -INT64_C( 1296466232894472955),  INT64_C( 2054944505823083343),  INT64_C( 9006032616381840828),  INT64_C( 7345114041165636510),
       INT64_C( 1881822496591758880), -INT64_C( 7482881647352665797),  INT64_C( 5866803421712284352),  INT64_C( 7161739787110220321),
       INT64_C( 6579367690192596835),  INT64_C( 8227746251350367889),  INT64_C( 1223060377765548154),  INT64_C( 6086829378826696368),
      -INT64_C( 4965567032699211661), -INT64_C( 6310419189861216564), -INT64_C( 2453727130368606477), -INT64_C( 5023872910692552141),
      -INT64_C( 2135850716401006597),  INT64_C(  586259467183849119), -INT64_C(  472669383553181766),  INT64_C( 5558982490658419964),
       INT64_C( 7765411844045274828),  INT64_C( 8821319866211111752), -INT64_C( 1483157771658374013),  INT64_C( 8583262390966576932),
      -INT64_C( 3745778339565196546),  INT64_C( 2073907326152232465),  INT64_C( 7533024937856119860), -INT64_C( 3514873748596780523),
       INT64_C( 1462831838167740883),  INT64_C( 7404582988776079424),  INT64_C( 2042316269399123710), -INT64_C( 4525564725793246014),
      -INT64_C( 1313660423673545389),  INT64_C( 3081511412892575184), -INT64_C(  486436762637580095), -INT64_C( 2444628264668575256),
      -INT64_C( 7388197429043681778), -INT64_C( 1566486134207909942), -INT64_C( 7016375662988185949),  INT64_C( 4310228856493530984),
       INT64_C( 2540769443852039047) };

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
    rv = simde_svadd_n_s64_m(pv, av, b);

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

    ev = simde_svadd_n_s64_m(pv, av, b);

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
test_simde_svadd_n_u8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) };
  static const uint8_t a[] =
    { UINT8_C( 80), UINT8_C( 56), UINT8_C(191), UINT8_C(251), UINT8_C( 16), UINT8_C(170), UINT8_C( 99), UINT8_C(206),
      UINT8_C(171), UINT8_C( 15), UINT8_C(  1), UINT8_C(163), UINT8_C( 65), UINT8_C( 91), UINT8_C( 62), UINT8_C( 72),
      UINT8_C(  4), UINT8_C( 46), UINT8_C(174), UINT8_C(101), UINT8_C(218), UINT8_C( 98), UINT8_C( 43), UINT8_C( 11),
      UINT8_C( 44), UINT8_C(244), UINT8_C(160), UINT8_C(165), UINT8_C( 84), UINT8_C( 62), UINT8_C(120), UINT8_C(164),
      UINT8_C(118), UINT8_C( 55), UINT8_C(159), UINT8_C(135), UINT8_C(226), UINT8_C(  2), UINT8_C( 85), UINT8_C(141),
      UINT8_C( 17), UINT8_C( 87), UINT8_C( 48), UINT8_C( 83), UINT8_C(178), UINT8_C(110), UINT8_C(155), UINT8_C(182),
      UINT8_C(156), UINT8_C( 73), UINT8_C( 28), UINT8_C(119), UINT8_C(171), UINT8_C( 71), UINT8_C(130), UINT8_C(215),
      UINT8_C( 59), UINT8_C( 34), UINT8_C(124), UINT8_C(143), UINT8_C( 97), UINT8_C(244), UINT8_C( 51), UINT8_C(215),
      UINT8_C( 44), UINT8_C(210), UINT8_C( 94), UINT8_C( 14), UINT8_C(212), UINT8_C(180), UINT8_C(155), UINT8_C(230),
      UINT8_C( 11), UINT8_C(203), UINT8_C( 57), UINT8_C(189), UINT8_C( 57), UINT8_C(212), UINT8_C(116), UINT8_C(214),
      UINT8_C( 29), UINT8_C(144), UINT8_C( 77), UINT8_C(200), UINT8_C(215), UINT8_C(207), UINT8_C(159), UINT8_C( 18),
      UINT8_C(242), UINT8_C( 27), UINT8_C(161), UINT8_C( 83), UINT8_C( 16), UINT8_C(212), UINT8_C( 42), UINT8_C( 60),
      UINT8_C(166), UINT8_C(137), UINT8_C( 74), UINT8_C(122), UINT8_C( 61), UINT8_C(229), UINT8_C( 96), UINT8_C( 72),
      UINT8_C(176), UINT8_C(153), UINT8_C(  5), UINT8_C(233), UINT8_C(109), UINT8_C(121), UINT8_C(191), UINT8_C(138),
      UINT8_C(  9), UINT8_C( 12), UINT8_C( 82), UINT8_C(224), UINT8_C(220), UINT8_C(241), UINT8_C(242), UINT8_C(206),
      UINT8_C( 13), UINT8_C(147), UINT8_C( 33), UINT8_C( 29), UINT8_C(103), UINT8_C( 75), UINT8_C( 89), UINT8_C( 13),
      UINT8_C(212), UINT8_C(163), UINT8_C(136), UINT8_C( 17), UINT8_C(136), UINT8_C(232), UINT8_C( 89), UINT8_C( 56),
      UINT8_C(130), UINT8_C( 95), UINT8_C( 33), UINT8_C(239), UINT8_C(216), UINT8_C(225), UINT8_C(122), UINT8_C(226),
      UINT8_C(237), UINT8_C(204), UINT8_C(194), UINT8_C(201), UINT8_C(190), UINT8_C(181), UINT8_C(151), UINT8_C(203),
      UINT8_C( 72), UINT8_C(184), UINT8_C(232), UINT8_C(176), UINT8_C(  4), UINT8_C( 65), UINT8_C(189), UINT8_C(216),
      UINT8_C(228), UINT8_C( 69), UINT8_C(234), UINT8_C(108), UINT8_C( 46), UINT8_C( 67), UINT8_C(164), UINT8_C(176),
      UINT8_C(162), UINT8_C(197), UINT8_C(159), UINT8_C(123), UINT8_C(166), UINT8_C( 25), UINT8_C( 93), UINT8_C(148),
      UINT8_C(230), UINT8_C( 31), UINT8_C( 93), UINT8_C(164), UINT8_C(212), UINT8_C(245), UINT8_C(111), UINT8_C( 29),
      UINT8_C(173), UINT8_C( 87), UINT8_C(205), UINT8_C(177), UINT8_C(152), UINT8_C(138), UINT8_C(138), UINT8_C(124),
      UINT8_C(208), UINT8_C(116), UINT8_C(232), UINT8_C(254), UINT8_C(183), UINT8_C(140), UINT8_C(174), UINT8_C( 90),
      UINT8_C( 81), UINT8_C( 77), UINT8_C(213), UINT8_C(248), UINT8_C(103), UINT8_C( 50), UINT8_C(140), UINT8_C( 77),
      UINT8_C( 81), UINT8_C(233), UINT8_C(241), UINT8_C( 38), UINT8_C(222), UINT8_C( 96), UINT8_C( 67), UINT8_C(140),
      UINT8_C(183), UINT8_C( 16), UINT8_C( 61), UINT8_C( 79), UINT8_C(154), UINT8_C(199), UINT8_C(203), UINT8_C(106),
      UINT8_C( 59), UINT8_C(179), UINT8_C(104), UINT8_C(243), UINT8_C( 63), UINT8_C( 22), UINT8_C( 77), UINT8_C(144),
      UINT8_C(100), UINT8_C( 34), UINT8_C(136), UINT8_C(203), UINT8_C( 84), UINT8_C( 20), UINT8_C( 24), UINT8_C(165),
      UINT8_C(254), UINT8_C(  9), UINT8_C(203), UINT8_C(220), UINT8_C(105), UINT8_C( 14), UINT8_C(104), UINT8_C( 32),
      UINT8_C( 30), UINT8_C(166), UINT8_C(111), UINT8_C(185), UINT8_C(109), UINT8_C( 58), UINT8_C( 35), UINT8_C(169),
      UINT8_C(237), UINT8_C(140), UINT8_C(156), UINT8_C( 44), UINT8_C(162), UINT8_C(233), UINT8_C(188), UINT8_C(  6),
      UINT8_C( 11), UINT8_C( 69), UINT8_C(209), UINT8_C( 95), UINT8_C( 89), UINT8_C(233), UINT8_C(  4), UINT8_C( 87),
      UINT8_C(242), UINT8_C(208), UINT8_C( 52), UINT8_C( 91), UINT8_C(222), UINT8_C(156), UINT8_C(123), UINT8_C(253),
      UINT8_C( 66), UINT8_C(234), UINT8_C(182), UINT8_C(176), UINT8_C( 36), UINT8_C(217), UINT8_C( 89), UINT8_C( 17),
      UINT8_C(101), UINT8_C(245), UINT8_C( 61), UINT8_C(  8), UINT8_C(222), UINT8_C(250), UINT8_C( 14), UINT8_C(233),
      UINT8_C( 63), UINT8_C(224), UINT8_C( 72), UINT8_C(152), UINT8_C(201), UINT8_C( 76), UINT8_C(240), UINT8_C(188),
      UINT8_C( 28), UINT8_C( 36), UINT8_C( 23), UINT8_C(251), UINT8_C(192), UINT8_C(147), UINT8_C(248), UINT8_C(  3),
      UINT8_C(125), UINT8_C(174), UINT8_C(179), UINT8_C(162), UINT8_C(135), UINT8_C( 12), UINT8_C(179), UINT8_C(237),
      UINT8_C(  1), UINT8_C(241), UINT8_C(245), UINT8_C(223), UINT8_C(235), UINT8_C(  3), UINT8_C(200), UINT8_C( 42),
      UINT8_C(227), UINT8_C( 16), UINT8_C(194), UINT8_C(173), UINT8_C( 92), UINT8_C(178), UINT8_C(105), UINT8_C(121),
      UINT8_C(214), UINT8_C(128), UINT8_C(116), UINT8_C(151), UINT8_C( 19), UINT8_C(108), UINT8_C(154), UINT8_C(145),
      UINT8_C( 26), UINT8_C( 77), UINT8_C( 51), UINT8_C(161), UINT8_C( 89), UINT8_C(230), UINT8_C(142), UINT8_C( 90),
      UINT8_C(215), UINT8_C(131), UINT8_C( 57), UINT8_C(194), UINT8_C(135), UINT8_C(  1), UINT8_C(236), UINT8_C(106),
      UINT8_C( 17), UINT8_C(175), UINT8_C( 23), UINT8_C(109), UINT8_C( 97), UINT8_C(128), UINT8_C(230), UINT8_C( 56),
      UINT8_C(  1), UINT8_C( 90), UINT8_C(207), UINT8_C( 20), UINT8_C(198), UINT8_C(105), UINT8_C(165), UINT8_C(224),
      UINT8_C(182), UINT8_C(216), UINT8_C(130), UINT8_C( 15), UINT8_C(191), UINT8_C( 16), UINT8_C(105), UINT8_C(150),
      UINT8_C(148), UINT8_C(162), UINT8_C( 89), UINT8_C( 27), UINT8_C(163), UINT8_C( 69), UINT8_C(133), UINT8_C(180),
      UINT8_C(244), UINT8_C(157), UINT8_C( 33), UINT8_C( 86), UINT8_C( 29), UINT8_C(  8), UINT8_C(142), UINT8_C( 30),
      UINT8_C( 98), UINT8_C( 93), UINT8_C( 51), UINT8_C( 41), UINT8_C(198), UINT8_C(216), UINT8_C(  9), UINT8_C(124),
      UINT8_C(177), UINT8_C(139), UINT8_C(139), UINT8_C(112), UINT8_C(156), UINT8_C(244), UINT8_C(  6), UINT8_C( 48),
      UINT8_C(150), UINT8_C( 95), UINT8_C( 75), UINT8_C( 57), UINT8_C(165), UINT8_C(208), UINT8_C(237), UINT8_C(153),
      UINT8_C(109), UINT8_C( 14), UINT8_C(239), UINT8_C(139), UINT8_C( 22), UINT8_C(125), UINT8_C(169), UINT8_C(121),
      UINT8_C(218), UINT8_C(220), UINT8_C(162), UINT8_C(160), UINT8_C(181), UINT8_C(171), UINT8_C( 28), UINT8_C(102),
      UINT8_C( 55), UINT8_C(167), UINT8_C(214), UINT8_C(211), UINT8_C(155), UINT8_C(220), UINT8_C(  3), UINT8_C( 49),
      UINT8_C( 60), UINT8_C( 78), UINT8_C(106), UINT8_C(225), UINT8_C( 30), UINT8_C( 87), UINT8_C(122), UINT8_C(140),
      UINT8_C(102), UINT8_C(106), UINT8_C( 23), UINT8_C(124), UINT8_C(231), UINT8_C(192), UINT8_C(245), UINT8_C(194),
      UINT8_C(157), UINT8_C(151), UINT8_C( 98), UINT8_C( 82), UINT8_C( 67), UINT8_C(127), UINT8_C(184), UINT8_C(122),
      UINT8_C( 38), UINT8_C(142), UINT8_C( 77), UINT8_C(194), UINT8_C(106), UINT8_C( 80), UINT8_C(243), UINT8_C(166),
      UINT8_C(158), UINT8_C( 94), UINT8_C(135), UINT8_C(188), UINT8_C(181), UINT8_C(  2), UINT8_C( 72), UINT8_C( 27),
      UINT8_C(108), UINT8_C( 95), UINT8_C(152), UINT8_C( 83), UINT8_C( 32), UINT8_C(141), UINT8_C( 21), UINT8_C(189),
      UINT8_C( 37), UINT8_C(120), UINT8_C( 15), UINT8_C(104), UINT8_C(247), UINT8_C(199), UINT8_C(226), UINT8_C( 29),
      UINT8_C( 85), UINT8_C( 47), UINT8_C(223), UINT8_C(191), UINT8_C(127), UINT8_C(211), UINT8_C(102), UINT8_C( 29),
      UINT8_C( 49), UINT8_C(237), UINT8_C(217), UINT8_C(230), UINT8_C(239), UINT8_C( 34), UINT8_C(  2), UINT8_C( 91),
      UINT8_C(129), UINT8_C(154), UINT8_C(175), UINT8_C(161), UINT8_C( 39), UINT8_C(196), UINT8_C( 94), UINT8_C( 76),
      UINT8_C( 60), UINT8_C(109), UINT8_C(180), UINT8_C( 51), UINT8_C( 52), UINT8_C(150), UINT8_C( 81), UINT8_C(137),
      UINT8_C(197), UINT8_C( 48), UINT8_C( 73), UINT8_C( 68), UINT8_C(  3), UINT8_C(175), UINT8_C( 97), UINT8_C( 52),
      UINT8_C(156), UINT8_C( 59), UINT8_C( 27), UINT8_C(140), UINT8_C( 93), UINT8_C( 29), UINT8_C(231), UINT8_C(222),
      UINT8_C(183), UINT8_C(150), UINT8_C(128), UINT8_C(222), UINT8_C( 91), UINT8_C(222), UINT8_C( 43), UINT8_C(151),
      UINT8_C( 76), UINT8_C(223), UINT8_C(203), UINT8_C(128), UINT8_C(118), UINT8_C( 28), UINT8_C( 10), UINT8_C( 59),
      UINT8_C( 76), UINT8_C( 83), UINT8_C(128), UINT8_C( 80), UINT8_C(  2), UINT8_C(225), UINT8_C(132), UINT8_C(158),
      UINT8_C( 28), UINT8_C(159), UINT8_C( 42), UINT8_C(121), UINT8_C(188), UINT8_C( 18), UINT8_C( 88), UINT8_C(115),
      UINT8_C(168), UINT8_C(216), UINT8_C( 82), UINT8_C(  3), UINT8_C(182), UINT8_C(125), UINT8_C(155), UINT8_C(  2),
      UINT8_C( 92), UINT8_C(102), UINT8_C(131), UINT8_C(210), UINT8_C(130), UINT8_C(141), UINT8_C( 14), UINT8_C(206),
      UINT8_C(224), UINT8_C(142), UINT8_C( 30), UINT8_C(226), UINT8_C(111), UINT8_C(163), UINT8_C(128), UINT8_C(140),
      UINT8_C( 66), UINT8_C(171), UINT8_C(  5),    UINT8_MAX, UINT8_C(189), UINT8_C( 93), UINT8_C(114), UINT8_C(101),
      UINT8_C( 53), UINT8_C(196), UINT8_C(105), UINT8_C(236), UINT8_C( 65), UINT8_C(  4), UINT8_C(238), UINT8_C(158),
      UINT8_C(106), UINT8_C(113), UINT8_C(112), UINT8_C(236), UINT8_C(254), UINT8_C(126), UINT8_C(186), UINT8_C(222),
      UINT8_C( 12), UINT8_C(217), UINT8_C(192), UINT8_C(124), UINT8_C(124), UINT8_C( 65), UINT8_C(  8), UINT8_C(190),
      UINT8_C(236), UINT8_C( 13), UINT8_C(189), UINT8_C(169), UINT8_C(107), UINT8_C( 48), UINT8_C( 14), UINT8_C(160),
      UINT8_C(244), UINT8_C(119), UINT8_C(140), UINT8_C( 54), UINT8_C(123), UINT8_C(123), UINT8_C(212), UINT8_C(229),
      UINT8_C(236), UINT8_C( 68), UINT8_C(209), UINT8_C(235), UINT8_C(195), UINT8_C(140), UINT8_C(201), UINT8_C(207),
      UINT8_C(101), UINT8_C(138), UINT8_C( 75), UINT8_C(225), UINT8_C(203), UINT8_C( 83), UINT8_C(159), UINT8_C(183),
      UINT8_C( 97), UINT8_C( 93), UINT8_C( 96), UINT8_C(204), UINT8_C(141), UINT8_C(110), UINT8_C(108), UINT8_C(129),
      UINT8_C(230), UINT8_C(249), UINT8_C(183), UINT8_C( 97), UINT8_C(116), UINT8_C(139), UINT8_C( 71), UINT8_C( 96),
      UINT8_C(208), UINT8_C( 24), UINT8_C( 75), UINT8_C(147), UINT8_C(164), UINT8_C( 21), UINT8_C( 98), UINT8_C(  9),
      UINT8_C(159), UINT8_C(174), UINT8_C(234), UINT8_C(106), UINT8_C(  1), UINT8_C(138), UINT8_C( 33), UINT8_C( 98),
      UINT8_C(231), UINT8_C(129), UINT8_C( 46), UINT8_C(116), UINT8_C(239), UINT8_C(155), UINT8_C(245), UINT8_C(213),
      UINT8_C(148), UINT8_C(173), UINT8_C( 55), UINT8_C(  8), UINT8_C( 56), UINT8_C(126), UINT8_C(104), UINT8_C(  8),
      UINT8_C(150), UINT8_C(180), UINT8_C(155), UINT8_C( 59), UINT8_C(201), UINT8_C(254), UINT8_C( 68), UINT8_C(104),
      UINT8_C(172), UINT8_C( 47), UINT8_C(210), UINT8_C(173), UINT8_C(185), UINT8_C(243), UINT8_C( 16), UINT8_C(160),
      UINT8_C(116), UINT8_C( 62), UINT8_C( 20), UINT8_C( 99), UINT8_C(217), UINT8_C(  9), UINT8_C( 57), UINT8_C(109),
      UINT8_C(182), UINT8_C(112), UINT8_C(117), UINT8_C(239), UINT8_C(238), UINT8_C(222), UINT8_C(247), UINT8_C(132),
      UINT8_C(146), UINT8_C(147), UINT8_C(191), UINT8_C( 91), UINT8_C(145), UINT8_C(  4), UINT8_C(195), UINT8_C( 61),
      UINT8_C( 51), UINT8_C(149), UINT8_C(234), UINT8_C(236), UINT8_C(136), UINT8_C(250), UINT8_C(140), UINT8_C(252),
      UINT8_C( 57), UINT8_C(160), UINT8_C( 95), UINT8_C( 18), UINT8_C(169), UINT8_C(152), UINT8_C(128), UINT8_C( 96),
      UINT8_C(  8), UINT8_C(245), UINT8_C( 79), UINT8_C(246), UINT8_C(211), UINT8_C( 70), UINT8_C(123), UINT8_C(101),
      UINT8_C(217), UINT8_C( 58), UINT8_C(192), UINT8_C(106), UINT8_C( 62), UINT8_C(131), UINT8_C(167), UINT8_C(113),
      UINT8_C( 24), UINT8_C(146), UINT8_C( 93), UINT8_C(160), UINT8_C(140), UINT8_C(233), UINT8_C(156), UINT8_C(197),
      UINT8_C(137), UINT8_C(252), UINT8_C(216), UINT8_C( 51), UINT8_C(148), UINT8_C( 88), UINT8_C(147), UINT8_C(157),
      UINT8_C( 77), UINT8_C(226), UINT8_C(147), UINT8_C( 33), UINT8_C( 40), UINT8_C( 14), UINT8_C(134), UINT8_C(  2),
      UINT8_C( 73), UINT8_C( 71), UINT8_C(108), UINT8_C(135), UINT8_C(202), UINT8_C( 20), UINT8_C(249), UINT8_C(227),
      UINT8_C(166), UINT8_C( 86), UINT8_C(131), UINT8_C( 50), UINT8_C( 64), UINT8_C( 32), UINT8_C(248), UINT8_C(201),
      UINT8_C( 28), UINT8_C(208), UINT8_C(252), UINT8_C(176), UINT8_C( 40), UINT8_C(143), UINT8_C( 77), UINT8_C(117),
      UINT8_C(113), UINT8_C(225), UINT8_C(150), UINT8_C(154), UINT8_C(239), UINT8_C( 29), UINT8_C(156), UINT8_C( 56),
      UINT8_C(100), UINT8_C(  8), UINT8_C(192), UINT8_C( 46), UINT8_C( 28), UINT8_C(185), UINT8_C( 17), UINT8_C(194),
      UINT8_C( 15), UINT8_C(149), UINT8_C(245), UINT8_C( 79), UINT8_C(181), UINT8_C(237), UINT8_C( 25), UINT8_C(209),
      UINT8_C(189), UINT8_C( 21), UINT8_C(129), UINT8_C(229), UINT8_C(165), UINT8_C(207), UINT8_C( 90), UINT8_C( 22),
      UINT8_C(176), UINT8_C(241), UINT8_C(176), UINT8_C(159), UINT8_C( 14), UINT8_C( 76), UINT8_C(216), UINT8_C(114),
      UINT8_C( 85), UINT8_C(152), UINT8_C(160), UINT8_C(113), UINT8_C( 81), UINT8_C(178), UINT8_C( 52), UINT8_C( 96),
      UINT8_C( 71), UINT8_C( 41), UINT8_C(176), UINT8_C(252), UINT8_C( 22), UINT8_C(201), UINT8_C(205), UINT8_C(211),
      UINT8_C(222), UINT8_C( 78), UINT8_C(184), UINT8_C(131), UINT8_C( 29), UINT8_C( 18), UINT8_C(154), UINT8_C(205),
      UINT8_C(  3), UINT8_C( 74), UINT8_C(109), UINT8_C( 17), UINT8_C(151), UINT8_C( 69), UINT8_C(131), UINT8_C(236),
      UINT8_C(221), UINT8_C( 36), UINT8_C( 93), UINT8_C( 46), UINT8_C(214), UINT8_C(145), UINT8_C(142), UINT8_C( 29),
      UINT8_C(186), UINT8_C( 62), UINT8_C( 25), UINT8_C(208), UINT8_C(  7), UINT8_C(230), UINT8_C(163), UINT8_C(230),
      UINT8_C( 52), UINT8_C( 91), UINT8_C(105), UINT8_C( 82), UINT8_C(110), UINT8_C(  3), UINT8_C( 31), UINT8_C(113),
      UINT8_C( 78), UINT8_C(140), UINT8_C(131), UINT8_C(229), UINT8_C(209), UINT8_C(  6), UINT8_C(209), UINT8_C(174),
      UINT8_C( 42), UINT8_C( 46), UINT8_C(220), UINT8_C(  0), UINT8_C(192), UINT8_C(107), UINT8_C( 29), UINT8_C(122),
      UINT8_C(169), UINT8_C( 54), UINT8_C( 75), UINT8_C(177), UINT8_C( 28), UINT8_C(238), UINT8_C(151), UINT8_C( 81),
      UINT8_C( 74), UINT8_C(  0), UINT8_C(163), UINT8_C(184), UINT8_C(  4), UINT8_C(194), UINT8_C( 41), UINT8_C( 82),
      UINT8_C( 79), UINT8_C(172), UINT8_C( 55), UINT8_C( 32), UINT8_C(179), UINT8_C(  8), UINT8_C(207), UINT8_C(221),
      UINT8_C( 54), UINT8_C(171), UINT8_C(222), UINT8_C(246), UINT8_C( 22), UINT8_C(251), UINT8_C(113), UINT8_C(192),
      UINT8_C( 50), UINT8_C(188), UINT8_C(113), UINT8_C( 78), UINT8_C(170), UINT8_C(  8), UINT8_C(159), UINT8_C(244),
      UINT8_C(  8), UINT8_C( 66), UINT8_C(172), UINT8_C( 12), UINT8_C(  5), UINT8_C(214), UINT8_C( 94), UINT8_C( 84),
      UINT8_C(130), UINT8_C(149), UINT8_C(116), UINT8_C( 53), UINT8_C(157), UINT8_C( 67), UINT8_C( 19), UINT8_C(212) };
  static const uint8_t b = UINT8_C( 79);
  static const uint8_t e[] =
    { UINT8_C(  0), UINT8_C(  0), UINT8_C( 14), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(178), UINT8_C( 29),
      UINT8_C(  0), UINT8_C( 94), UINT8_C(  0), UINT8_C(242), UINT8_C(144), UINT8_C(170), UINT8_C(141), UINT8_C(  0),
      UINT8_C( 83), UINT8_C(125), UINT8_C(253), UINT8_C(180), UINT8_C( 41), UINT8_C(  0), UINT8_C(122), UINT8_C( 90),
      UINT8_C(  0), UINT8_C( 67), UINT8_C(239), UINT8_C(  0), UINT8_C(163), UINT8_C(141), UINT8_C(  0), UINT8_C(243),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(214), UINT8_C(  0), UINT8_C( 81), UINT8_C(  0), UINT8_C(220),
      UINT8_C(  0), UINT8_C(166), UINT8_C(  0), UINT8_C(162), UINT8_C(  0), UINT8_C(  0), UINT8_C(234), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(250), UINT8_C(150), UINT8_C(209), UINT8_C(  0),
      UINT8_C(138), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 67), UINT8_C(  0), UINT8_C( 38),
      UINT8_C(123), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(234), UINT8_C(  0),
      UINT8_C( 90), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(136), UINT8_C(  0), UINT8_C(195), UINT8_C( 37),
      UINT8_C(108), UINT8_C(223), UINT8_C(156), UINT8_C(  0), UINT8_C( 38), UINT8_C(  0), UINT8_C(  0), UINT8_C( 97),
      UINT8_C( 65), UINT8_C(106), UINT8_C(240), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(121), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(216), UINT8_C(153), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(175), UINT8_C(151),
         UINT8_MAX, UINT8_C(232), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(200), UINT8_C( 14), UINT8_C(217),
      UINT8_C( 88), UINT8_C(  0), UINT8_C(161), UINT8_C( 47), UINT8_C( 43), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 92), UINT8_C(226), UINT8_C(112), UINT8_C(108), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 35), UINT8_C(242), UINT8_C(215), UINT8_C( 96), UINT8_C(  0), UINT8_C(  0), UINT8_C(168), UINT8_C(135),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(112), UINT8_C(  0), UINT8_C(  0), UINT8_C( 48), UINT8_C(201), UINT8_C( 49),
      UINT8_C(  0), UINT8_C( 27), UINT8_C(  0), UINT8_C( 24), UINT8_C( 13), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  7), UINT8_C(  0), UINT8_C(  0), UINT8_C( 83), UINT8_C(  0), UINT8_C( 12), UINT8_C( 39),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 57), UINT8_C(  0), UINT8_C(  0), UINT8_C(146), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(241), UINT8_C( 20), UINT8_C(238), UINT8_C(  0), UINT8_C(245), UINT8_C(  0), UINT8_C(172), UINT8_C(227),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(243), UINT8_C( 35), UINT8_C( 68), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 28), UINT8_C(  0), UINT8_C(231), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 31), UINT8_C(195), UINT8_C(  0), UINT8_C( 77), UINT8_C(  6), UINT8_C(  0), UINT8_C(  0), UINT8_C(169),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 36), UINT8_C( 71), UINT8_C(182), UINT8_C(129), UINT8_C(  0), UINT8_C(156),
      UINT8_C(160), UINT8_C( 56), UINT8_C(  0), UINT8_C(117), UINT8_C(  0), UINT8_C(175), UINT8_C(146), UINT8_C(219),
      UINT8_C(  0), UINT8_C( 95), UINT8_C(140), UINT8_C(158), UINT8_C(233), UINT8_C( 22), UINT8_C( 26), UINT8_C(  0),
      UINT8_C(138), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(142), UINT8_C(101), UINT8_C(  0), UINT8_C(223),
      UINT8_C(  0), UINT8_C(113), UINT8_C(215), UINT8_C( 26), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 77), UINT8_C( 88), UINT8_C( 26), UINT8_C(  0), UINT8_C(  0), UINT8_C( 93), UINT8_C(183), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(245), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(114), UINT8_C(248),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(123), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 32), UINT8_C(  0), UINT8_C(  0), UINT8_C( 56), UINT8_C( 83), UINT8_C(  0),
      UINT8_C( 65), UINT8_C( 31), UINT8_C(  0), UINT8_C(170), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 76),
      UINT8_C(145), UINT8_C(  0), UINT8_C(  5),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(168), UINT8_C( 96),
      UINT8_C(180), UINT8_C(  0), UINT8_C(  0), UINT8_C( 87), UINT8_C(  0), UINT8_C( 73), UINT8_C( 93), UINT8_C(  0),
      UINT8_C(142), UINT8_C(  0), UINT8_C(151), UINT8_C(  0), UINT8_C(  0), UINT8_C(155), UINT8_C(  0), UINT8_C( 11),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(102), UINT8_C(  0), UINT8_C(  0), UINT8_C(226), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(253), UINT8_C(  2), UINT8_C(241), UINT8_C(  0), UINT8_C( 91), UINT8_C(  0), UINT8_C( 60),
      UINT8_C( 80), UINT8_C( 64), UINT8_C( 68), UINT8_C(  0), UINT8_C( 58), UINT8_C(  0), UINT8_C( 23), UINT8_C(121),
      UINT8_C( 50), UINT8_C( 95), UINT8_C( 17), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(184), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(207), UINT8_C(195), UINT8_C(230), UINT8_C( 98), UINT8_C(187), UINT8_C(233), UINT8_C(224),
      UINT8_C(105), UINT8_C(156), UINT8_C(130), UINT8_C(240), UINT8_C(  0), UINT8_C( 53), UINT8_C(221), UINT8_C(  0),
      UINT8_C( 38), UINT8_C(210), UINT8_C(  0), UINT8_C(  0), UINT8_C(214), UINT8_C( 80), UINT8_C(  0), UINT8_C(185),
      UINT8_C( 96), UINT8_C(254), UINT8_C(102), UINT8_C(188), UINT8_C(176), UINT8_C(207), UINT8_C( 53), UINT8_C(  0),
      UINT8_C( 80), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 47),
      UINT8_C(  5), UINT8_C( 39), UINT8_C(209), UINT8_C(  0), UINT8_C(  0), UINT8_C( 95), UINT8_C(184), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(241), UINT8_C(168), UINT8_C(  0), UINT8_C(242), UINT8_C(148), UINT8_C(212), UINT8_C(  0),
      UINT8_C( 67), UINT8_C(236), UINT8_C(112), UINT8_C(165), UINT8_C(108), UINT8_C( 87), UINT8_C(221), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 88), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(218), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 85), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(136), UINT8_C(244), UINT8_C( 31), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(188), UINT8_C(  0), UINT8_C( 62), UINT8_C(  0), UINT8_C(101), UINT8_C(204), UINT8_C(248), UINT8_C(200),
      UINT8_C( 41), UINT8_C(  0), UINT8_C(241), UINT8_C(  0), UINT8_C(  4), UINT8_C(250), UINT8_C(107), UINT8_C(181),
      UINT8_C(  0), UINT8_C(246), UINT8_C( 37), UINT8_C(  0), UINT8_C(234), UINT8_C( 43), UINT8_C(  0), UINT8_C(128),
      UINT8_C(139), UINT8_C(  0), UINT8_C(185), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(201), UINT8_C(219),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 54), UINT8_C( 15), UINT8_C( 68), UINT8_C( 17),
      UINT8_C(236), UINT8_C(230), UINT8_C(  0), UINT8_C(  0), UINT8_C(146), UINT8_C(206), UINT8_C(  7), UINT8_C(201),
      UINT8_C(  0), UINT8_C(221), UINT8_C(156), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(237), UINT8_C(173), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 81), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(231), UINT8_C(162), UINT8_C(  0), UINT8_C(  0), UINT8_C(100), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(199), UINT8_C(  0), UINT8_C(183), UINT8_C( 70), UINT8_C(  0), UINT8_C( 49), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(126), UINT8_C( 46), UINT8_C( 14), UINT8_C(206), UINT8_C( 34), UINT8_C(181), UINT8_C(108),
      UINT8_C(128), UINT8_C(  0), UINT8_C( 40), UINT8_C( 53), UINT8_C( 62), UINT8_C(113), UINT8_C(  0), UINT8_C(170),
      UINT8_C(  0), UINT8_C(233), UINT8_C(254), UINT8_C(  0), UINT8_C(  0), UINT8_C( 19), UINT8_C(173), UINT8_C(  0),
      UINT8_C(139), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(229), UINT8_C(160), UINT8_C(216),
      UINT8_C(  0), UINT8_C(127), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131),
      UINT8_C(  0), UINT8_C(138), UINT8_C(106), UINT8_C(  0), UINT8_C(172), UINT8_C(108), UINT8_C( 54), UINT8_C(  0),
      UINT8_C(  6), UINT8_C(229), UINT8_C(207), UINT8_C( 45), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(230),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(207), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(138),
      UINT8_C(155), UINT8_C(162), UINT8_C(207), UINT8_C(159), UINT8_C(  0), UINT8_C( 48), UINT8_C(211), UINT8_C(  0),
      UINT8_C(107), UINT8_C(238), UINT8_C(  0), UINT8_C(  0), UINT8_C( 11), UINT8_C(  0), UINT8_C(167), UINT8_C(  0),
      UINT8_C(247), UINT8_C(  0), UINT8_C(161), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(234), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(210), UINT8_C( 33), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 29),
      UINT8_C( 47), UINT8_C(221), UINT8_C(109), UINT8_C( 49), UINT8_C(190), UINT8_C(242), UINT8_C(  0), UINT8_C(219),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 84), UINT8_C( 78), UINT8_C( 12), UINT8_C(172), UINT8_C(193), UINT8_C(  0),
      UINT8_C(132), UINT8_C( 19), UINT8_C(  0), UINT8_C( 59), UINT8_C(144), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(192), UINT8_C(191), UINT8_C(  0), UINT8_C(  0), UINT8_C(205), UINT8_C(  0), UINT8_C( 45),
      UINT8_C( 91), UINT8_C(  0), UINT8_C( 15), UINT8_C(203), UINT8_C(203), UINT8_C(  0), UINT8_C(  0), UINT8_C( 13),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 12), UINT8_C(  0), UINT8_C(186), UINT8_C(127), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(198), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 35), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 32), UINT8_C(  0), UINT8_C(  0), UINT8_C(219), UINT8_C( 24), UINT8_C(  0),
      UINT8_C(180), UINT8_C(217), UINT8_C(  0), UINT8_C( 48), UINT8_C( 26), UINT8_C(162), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(176), UINT8_C(  0), UINT8_C(  0), UINT8_C( 27), UINT8_C(220), UINT8_C(189), UINT8_C(  0), UINT8_C(208),
      UINT8_C( 53), UINT8_C(  0), UINT8_C(  0), UINT8_C(176), UINT8_C(  0), UINT8_C(218), UINT8_C(  0), UINT8_C(175),
      UINT8_C(  0), UINT8_C(103), UINT8_C(154), UINT8_C(226), UINT8_C(243), UINT8_C(100), UINT8_C(177), UINT8_C( 88),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 80), UINT8_C(217), UINT8_C(112), UINT8_C(  0),
      UINT8_C( 54), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(227), UINT8_C(  0), UINT8_C(134), UINT8_C(  0), UINT8_C(135), UINT8_C(205), UINT8_C(183), UINT8_C( 87),
      UINT8_C(229), UINT8_C(  0), UINT8_C(234), UINT8_C(  0), UINT8_C( 24), UINT8_C(  0), UINT8_C(147), UINT8_C(  0),
      UINT8_C(251), UINT8_C(126), UINT8_C( 33), UINT8_C(  0), UINT8_C(  8), UINT8_C(  0), UINT8_C( 95), UINT8_C(  0),
      UINT8_C(195), UINT8_C(141), UINT8_C(  0), UINT8_C(178), UINT8_C(  0), UINT8_C(  0), UINT8_C(136), UINT8_C(188),
      UINT8_C(  0), UINT8_C(191), UINT8_C(196), UINT8_C(  0), UINT8_C( 61), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(226), UINT8_C( 14), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(140),
      UINT8_C(  0), UINT8_C(228), UINT8_C( 57), UINT8_C( 59), UINT8_C(  0), UINT8_C( 73), UINT8_C(  0), UINT8_C( 75),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(175),
      UINT8_C( 87), UINT8_C( 68), UINT8_C(158), UINT8_C( 69), UINT8_C(  0), UINT8_C(  0), UINT8_C(202), UINT8_C(180),
      UINT8_C( 40), UINT8_C(  0), UINT8_C( 15), UINT8_C(185), UINT8_C(141), UINT8_C(  0), UINT8_C(246), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(239), UINT8_C(219), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 75), UINT8_C( 39), UINT8_C(130), UINT8_C(  0), UINT8_C(167), UINT8_C(226), UINT8_C(236),
      UINT8_C(156), UINT8_C( 49), UINT8_C(  0), UINT8_C(112), UINT8_C(119), UINT8_C(  0), UINT8_C(  0), UINT8_C( 81),
      UINT8_C(152), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 25), UINT8_C( 99), UINT8_C( 72), UINT8_C( 50),
      UINT8_C(  0), UINT8_C(165), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(111), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(107), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(119), UINT8_C(222), UINT8_C(156), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 48), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(108), UINT8_C(235), UINT8_C(135),
      UINT8_C(179), UINT8_C( 87), UINT8_C(  0), UINT8_C(  0), UINT8_C(107), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C( 94), UINT8_C(  0), UINT8_C(  0), UINT8_C(158), UINT8_C(  0), UINT8_C( 60), UINT8_C(  0), UINT8_C( 32),
      UINT8_C(  0), UINT8_C(100), UINT8_C(  0), UINT8_C( 52), UINT8_C(  0), UINT8_C( 30), UINT8_C(  0), UINT8_C(101),
         UINT8_MAX, UINT8_C( 64),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 39), UINT8_C(193),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(192), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(150), UINT8_C(120), UINT8_C(  0), UINT8_C( 75), UINT8_C(101), UINT8_C(  0), UINT8_C( 28), UINT8_C( 34),
      UINT8_C( 45), UINT8_C(157), UINT8_C(  7), UINT8_C(  0), UINT8_C(108), UINT8_C(  0), UINT8_C(233), UINT8_C( 28),
      UINT8_C( 82), UINT8_C(  0), UINT8_C(188), UINT8_C( 96), UINT8_C(230), UINT8_C(148), UINT8_C(210), UINT8_C( 59),
      UINT8_C( 44), UINT8_C(  0), UINT8_C(172), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  9), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 86), UINT8_C( 53), UINT8_C(  0), UINT8_C( 53),
      UINT8_C(131), UINT8_C(170), UINT8_C(  0), UINT8_C(161), UINT8_C(189), UINT8_C( 82), UINT8_C(  0), UINT8_C(192),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(210), UINT8_C(  0), UINT8_C( 32), UINT8_C( 85), UINT8_C( 32), UINT8_C(  0),
      UINT8_C(121), UINT8_C(125), UINT8_C(  0), UINT8_C(  0), UINT8_C( 15), UINT8_C(186), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(248), UINT8_C(133), UINT8_C(154), UINT8_C(  0), UINT8_C(107), UINT8_C( 61), UINT8_C(230), UINT8_C(160),
      UINT8_C(153), UINT8_C( 79), UINT8_C(  0), UINT8_C(  7), UINT8_C( 83), UINT8_C( 17), UINT8_C(  0), UINT8_C(161),
      UINT8_C(158), UINT8_C(251), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 87), UINT8_C( 30), UINT8_C(  0),
      UINT8_C(133), UINT8_C(250), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 74), UINT8_C(192), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 11), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 87), UINT8_C(238), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(145), UINT8_C(251), UINT8_C( 91), UINT8_C( 84), UINT8_C( 37), UINT8_C(173), UINT8_C(  0),
      UINT8_C(209), UINT8_C(  0), UINT8_C(195), UINT8_C(  0), UINT8_C(236), UINT8_C(  0), UINT8_C(  0), UINT8_C( 35) };

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
    rv = simde_svadd_n_u8_z(pv, av, b);

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

    ev = simde_svadd_n_u8_z(pv, av, b);

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
test_simde_svadd_n_u8_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0) };
  static const uint8_t a[] =
    { UINT8_C(248), UINT8_C(103), UINT8_C(173), UINT8_C( 53), UINT8_C(135), UINT8_C( 55), UINT8_C(124), UINT8_C(169),
      UINT8_C(175), UINT8_C(116), UINT8_C(211), UINT8_C(167), UINT8_C( 66), UINT8_C( 38), UINT8_C( 96), UINT8_C(206),
      UINT8_C(209), UINT8_C( 27), UINT8_C( 99), UINT8_C(105), UINT8_C(115), UINT8_C(124), UINT8_C(114), UINT8_C(132),
      UINT8_C( 65), UINT8_C(121), UINT8_C(205), UINT8_C(175), UINT8_C(112), UINT8_C(229), UINT8_C( 35), UINT8_C(105),
      UINT8_C( 77), UINT8_C(208), UINT8_C(158), UINT8_C(212), UINT8_C(  7), UINT8_C( 27), UINT8_C(126), UINT8_C(183),
      UINT8_C(143), UINT8_C( 81), UINT8_C( 94), UINT8_C(209), UINT8_C(119), UINT8_C(190), UINT8_C(159), UINT8_C( 73),
      UINT8_C(218), UINT8_C(  2), UINT8_C(178), UINT8_C( 77), UINT8_C(127), UINT8_C( 36), UINT8_C(209), UINT8_C(192),
      UINT8_C(157), UINT8_C(158), UINT8_C(111), UINT8_C( 14), UINT8_C(132), UINT8_C(146), UINT8_C(119), UINT8_C(209),
      UINT8_C( 98), UINT8_C( 21), UINT8_C(165), UINT8_C(106), UINT8_C( 48), UINT8_C( 35), UINT8_C( 33), UINT8_C(191),
      UINT8_C(117), UINT8_C(127), UINT8_C(144), UINT8_C(236), UINT8_C( 61), UINT8_C( 48), UINT8_C( 53), UINT8_C( 23),
      UINT8_C( 50), UINT8_C(232), UINT8_C(100), UINT8_C(177), UINT8_C( 12), UINT8_C( 54), UINT8_C(113), UINT8_C(170),
      UINT8_C(212), UINT8_C(225), UINT8_C(184), UINT8_C( 88), UINT8_C(115), UINT8_C( 47), UINT8_C( 41), UINT8_C(214),
      UINT8_C( 68), UINT8_C(207), UINT8_C( 64), UINT8_C(117), UINT8_C(242), UINT8_C( 97), UINT8_C( 52), UINT8_C(103),
      UINT8_C(224), UINT8_C(197), UINT8_C( 84), UINT8_C( 29), UINT8_C(245), UINT8_C(137), UINT8_C( 53), UINT8_C( 39),
      UINT8_C(113), UINT8_C(153), UINT8_C(217), UINT8_C(126), UINT8_C(207), UINT8_C( 74), UINT8_C( 40), UINT8_C(164),
      UINT8_C( 43), UINT8_C(224), UINT8_C(252), UINT8_C(159), UINT8_C( 15), UINT8_C( 38), UINT8_C(117), UINT8_C( 83),
      UINT8_C(245), UINT8_C(181), UINT8_C(200), UINT8_C(231), UINT8_C( 22), UINT8_C(253), UINT8_C( 79), UINT8_C(246),
      UINT8_C(194), UINT8_C(163), UINT8_C( 19), UINT8_C(183), UINT8_C( 44), UINT8_C( 72), UINT8_C(222), UINT8_C(158),
      UINT8_C(226), UINT8_C(183), UINT8_C( 28), UINT8_C(177), UINT8_C(  2), UINT8_C( 68), UINT8_C( 85), UINT8_C( 45),
      UINT8_C( 36), UINT8_C( 82), UINT8_C(204), UINT8_C( 51), UINT8_C(120), UINT8_C( 65), UINT8_C(134), UINT8_C(109),
      UINT8_C(246), UINT8_C( 79), UINT8_C( 84), UINT8_C( 12), UINT8_C( 76), UINT8_C(163), UINT8_C(  2), UINT8_C( 14),
      UINT8_C( 70), UINT8_C( 22), UINT8_C(197), UINT8_C(115), UINT8_C( 94), UINT8_C(163), UINT8_C( 17), UINT8_C( 64),
      UINT8_C( 91), UINT8_C( 45), UINT8_C(242), UINT8_C( 93), UINT8_C(113), UINT8_C( 71), UINT8_C(138), UINT8_C(149),
      UINT8_C(153), UINT8_C( 87), UINT8_C(200), UINT8_C( 17), UINT8_C(152), UINT8_C( 78), UINT8_C(126), UINT8_C(143),
      UINT8_C(157), UINT8_C(211), UINT8_C(155), UINT8_C(233), UINT8_C(118), UINT8_C(158), UINT8_C(247), UINT8_C(189),
      UINT8_C(180), UINT8_C(188), UINT8_C( 48), UINT8_C( 18), UINT8_C( 96), UINT8_C( 65), UINT8_C( 83), UINT8_C(187),
      UINT8_C(110), UINT8_C( 69), UINT8_C( 24), UINT8_C(223), UINT8_C(140), UINT8_C(162), UINT8_C(116), UINT8_C( 38),
      UINT8_C(249), UINT8_C( 60), UINT8_C( 55), UINT8_C(146), UINT8_C(138), UINT8_C(182), UINT8_C( 33), UINT8_C( 40),
      UINT8_C(137), UINT8_C(188), UINT8_C( 17),    UINT8_MAX, UINT8_C( 90), UINT8_C(  9), UINT8_C(188), UINT8_C( 14),
      UINT8_C(197), UINT8_C(236), UINT8_C( 33), UINT8_C( 37), UINT8_C( 45), UINT8_C(116), UINT8_C(224), UINT8_C(155),
      UINT8_C(185), UINT8_C(248), UINT8_C(122), UINT8_C( 69), UINT8_C(155), UINT8_C(238), UINT8_C(107), UINT8_C(148),
      UINT8_C( 42), UINT8_C(163), UINT8_C( 38), UINT8_C(181), UINT8_C( 89), UINT8_C( 71), UINT8_C(221), UINT8_C(226),
      UINT8_C(  4), UINT8_C(238), UINT8_C(225), UINT8_C( 94), UINT8_C(247), UINT8_C(158), UINT8_C(109), UINT8_C(189),
      UINT8_C(138), UINT8_C(142), UINT8_C(226), UINT8_C(184), UINT8_C(  2), UINT8_C(195), UINT8_C( 83), UINT8_C(187),
      UINT8_C(187), UINT8_C(206), UINT8_C(  0), UINT8_C( 86), UINT8_C(188), UINT8_C(108), UINT8_C(235), UINT8_C(231),
      UINT8_C( 15), UINT8_C( 17), UINT8_C(156), UINT8_C(104), UINT8_C( 89), UINT8_C(121), UINT8_C( 74), UINT8_C( 93),
      UINT8_C(103), UINT8_C( 43), UINT8_C(187), UINT8_C( 95), UINT8_C(201), UINT8_C( 40), UINT8_C( 28), UINT8_C( 84),
      UINT8_C(182), UINT8_C(254), UINT8_C( 12), UINT8_C(184), UINT8_C(193), UINT8_C( 95), UINT8_C(115), UINT8_C(125),
      UINT8_C( 45), UINT8_C(116), UINT8_C(211), UINT8_C(234), UINT8_C(224), UINT8_C(190), UINT8_C(209), UINT8_C(239),
      UINT8_C(208), UINT8_C(109), UINT8_C( 87), UINT8_C( 41), UINT8_C(230), UINT8_C(161), UINT8_C(134), UINT8_C( 77),
      UINT8_C(204), UINT8_C( 65), UINT8_C(172), UINT8_C(150), UINT8_C(106), UINT8_C(200), UINT8_C(234), UINT8_C( 32),
      UINT8_C(199), UINT8_C(246), UINT8_C(217), UINT8_C(136), UINT8_C( 85), UINT8_C( 76), UINT8_C(  5), UINT8_C(131),
      UINT8_C(192), UINT8_C(217), UINT8_C(109), UINT8_C(160), UINT8_C(151), UINT8_C( 62), UINT8_C(143), UINT8_C(103),
      UINT8_C(171), UINT8_C(230), UINT8_C(144), UINT8_C(145), UINT8_C(135), UINT8_C( 22), UINT8_C(222), UINT8_C( 84),
      UINT8_C( 88), UINT8_C(139), UINT8_C(234), UINT8_C(194), UINT8_C( 83), UINT8_C(212), UINT8_C(226), UINT8_C( 26),
      UINT8_C(202), UINT8_C(187), UINT8_C(163), UINT8_C( 31), UINT8_C(  8), UINT8_C(168), UINT8_C(162), UINT8_C(200),
      UINT8_C(129), UINT8_C( 15), UINT8_C(105), UINT8_C( 25), UINT8_C( 77), UINT8_C(248), UINT8_C(128), UINT8_C(248),
      UINT8_C(223), UINT8_C( 17), UINT8_C(137), UINT8_C(102), UINT8_C( 39), UINT8_C(104), UINT8_C(186), UINT8_C(127),
      UINT8_C(243), UINT8_C(164), UINT8_C( 65), UINT8_C( 70), UINT8_C(120), UINT8_C( 36), UINT8_C( 97), UINT8_C( 66),
      UINT8_C(223), UINT8_C(  4), UINT8_C( 98), UINT8_C(231), UINT8_C(172), UINT8_C(  4), UINT8_C(176), UINT8_C( 46),
      UINT8_C( 20), UINT8_C( 25), UINT8_C( 71), UINT8_C( 97), UINT8_C( 17), UINT8_C(199), UINT8_C( 90), UINT8_C(240),
      UINT8_C(216), UINT8_C(227), UINT8_C( 87), UINT8_C(  0), UINT8_C( 75), UINT8_C( 17), UINT8_C(127), UINT8_C( 62),
      UINT8_C(182), UINT8_C(193), UINT8_C(133), UINT8_C( 46), UINT8_C(229), UINT8_C(230), UINT8_C(113), UINT8_C(196),
      UINT8_C(234), UINT8_C(211), UINT8_C(172), UINT8_C(150), UINT8_C(215), UINT8_C( 92), UINT8_C(196), UINT8_C(235),
      UINT8_C(117), UINT8_C( 11), UINT8_C( 77), UINT8_C(134), UINT8_C(211), UINT8_C(167), UINT8_C(119), UINT8_C(171),
      UINT8_C(138), UINT8_C(206), UINT8_C(171), UINT8_C(214), UINT8_C(223), UINT8_C( 43), UINT8_C( 20), UINT8_C(149),
      UINT8_C(236), UINT8_C(153), UINT8_C(196), UINT8_C(209), UINT8_C(127), UINT8_C( 53), UINT8_C(149), UINT8_C(105),
      UINT8_C(  8), UINT8_C( 65), UINT8_C(  0), UINT8_C(223), UINT8_C(157), UINT8_C(196), UINT8_C(203), UINT8_C( 18),
      UINT8_C(208), UINT8_C( 24), UINT8_C(153), UINT8_C(163), UINT8_C(191), UINT8_C( 16), UINT8_C( 78), UINT8_C( 73),
      UINT8_C(222), UINT8_C(250), UINT8_C( 31), UINT8_C(189), UINT8_C( 37), UINT8_C( 52), UINT8_C( 83), UINT8_C( 17),
      UINT8_C(205), UINT8_C( 23), UINT8_C(226), UINT8_C( 77), UINT8_C( 76), UINT8_C(119), UINT8_C(182), UINT8_C( 84),
      UINT8_C(185), UINT8_C(182), UINT8_C( 51), UINT8_C( 86), UINT8_C(123), UINT8_C(254), UINT8_C(105), UINT8_C( 75),
      UINT8_C( 22), UINT8_C(  2), UINT8_C(238), UINT8_C(213), UINT8_C( 18), UINT8_C( 60), UINT8_C( 31), UINT8_C(240),
      UINT8_C( 54), UINT8_C( 62), UINT8_C(173), UINT8_C( 91), UINT8_C(114), UINT8_C(  0), UINT8_C(108), UINT8_C( 64),
      UINT8_C( 23), UINT8_C( 78), UINT8_C(141), UINT8_C( 99), UINT8_C(198), UINT8_C( 67), UINT8_C(183), UINT8_C(127),
      UINT8_C(250), UINT8_C(235), UINT8_C(213), UINT8_C(117), UINT8_C(233), UINT8_C( 62), UINT8_C(192), UINT8_C(  0),
      UINT8_C( 64), UINT8_C(174), UINT8_C(213), UINT8_C( 82), UINT8_C(234), UINT8_C(244), UINT8_C( 66), UINT8_C( 33),
      UINT8_C( 51), UINT8_C(240), UINT8_C(124), UINT8_C(165), UINT8_C(240), UINT8_C(233), UINT8_C(229), UINT8_C(  8),
      UINT8_C( 55), UINT8_C(114), UINT8_C(107), UINT8_C(253), UINT8_C(182), UINT8_C( 35), UINT8_C(124), UINT8_C(176),
      UINT8_C( 14), UINT8_C( 82), UINT8_C( 37), UINT8_C(247), UINT8_C(144), UINT8_C(229), UINT8_C(247), UINT8_C(209),
      UINT8_C(147), UINT8_C(205), UINT8_C( 35), UINT8_C(125), UINT8_C(193), UINT8_C(102), UINT8_C(158), UINT8_C(244),
      UINT8_C( 86), UINT8_C( 27), UINT8_C(154), UINT8_C( 70), UINT8_C(  4), UINT8_C(127), UINT8_C( 78), UINT8_C( 59),
      UINT8_C(242), UINT8_C(186), UINT8_C( 57), UINT8_C(168), UINT8_C(221), UINT8_C(181), UINT8_C( 88), UINT8_C(235),
      UINT8_C(  7), UINT8_C(125), UINT8_C(226), UINT8_C(152), UINT8_C( 98), UINT8_C(218), UINT8_C(105), UINT8_C(245),
      UINT8_C(167), UINT8_C(140), UINT8_C(114), UINT8_C(104), UINT8_C(242), UINT8_C( 17), UINT8_C( 93), UINT8_C( 72),
      UINT8_C( 44), UINT8_C(247), UINT8_C(143), UINT8_C( 48), UINT8_C(118), UINT8_C(221), UINT8_C(107), UINT8_C(104),
      UINT8_C(151), UINT8_C(164), UINT8_C( 16), UINT8_C(116), UINT8_C( 90), UINT8_C(104), UINT8_C( 95), UINT8_C( 97),
      UINT8_C(229), UINT8_C( 66), UINT8_C(249), UINT8_C( 71), UINT8_C( 28), UINT8_C( 98), UINT8_C( 60), UINT8_C(195),
      UINT8_C(239), UINT8_C(175), UINT8_C( 43), UINT8_C(225), UINT8_C(192), UINT8_C(136), UINT8_C( 42), UINT8_C(236),
      UINT8_C(127), UINT8_C(185), UINT8_C( 28), UINT8_C(246), UINT8_C(150), UINT8_C(135), UINT8_C( 94), UINT8_C( 46),
      UINT8_C( 44), UINT8_C(111), UINT8_C(162), UINT8_C(134), UINT8_C(215), UINT8_C(  2), UINT8_C(231), UINT8_C(189),
      UINT8_C( 68), UINT8_C(225), UINT8_C(  4), UINT8_C( 96), UINT8_C( 67), UINT8_C( 65), UINT8_C( 35), UINT8_C( 50),
      UINT8_C(240), UINT8_C( 78), UINT8_C( 20), UINT8_C(176), UINT8_C(215), UINT8_C( 62), UINT8_C(156), UINT8_C( 86),
      UINT8_C(247), UINT8_C(184), UINT8_C( 76), UINT8_C(141), UINT8_C( 63), UINT8_C(171), UINT8_C(187), UINT8_C(107),
      UINT8_C( 26), UINT8_C( 94), UINT8_C(241), UINT8_C(241), UINT8_C( 96), UINT8_C(217), UINT8_C(174), UINT8_C(164),
      UINT8_C(186), UINT8_C(179), UINT8_C(  4), UINT8_C(253), UINT8_C(244), UINT8_C( 39), UINT8_C( 48), UINT8_C(228),
      UINT8_C(117), UINT8_C( 68), UINT8_C(148), UINT8_C( 76), UINT8_C(130), UINT8_C( 48), UINT8_C(163), UINT8_C(121),
      UINT8_C(232), UINT8_C(239), UINT8_C(  6), UINT8_C( 39), UINT8_C(154), UINT8_C(194), UINT8_C(147), UINT8_C(180),
      UINT8_C( 32), UINT8_C(132), UINT8_C(166), UINT8_C(128), UINT8_C( 93), UINT8_C( 84), UINT8_C( 36), UINT8_C( 23),
      UINT8_C(  7), UINT8_C( 40), UINT8_C( 21), UINT8_C(251), UINT8_C( 79), UINT8_C( 69), UINT8_C(223), UINT8_C(196),
      UINT8_C(137), UINT8_C(115), UINT8_C( 17), UINT8_C( 11), UINT8_C(163), UINT8_C(180), UINT8_C(132), UINT8_C(139),
      UINT8_C(163), UINT8_C(138), UINT8_C(179), UINT8_C( 62), UINT8_C( 76), UINT8_C( 70), UINT8_C(242), UINT8_C(108),
      UINT8_C(202), UINT8_C(152), UINT8_C(236), UINT8_C( 40), UINT8_C(237), UINT8_C( 16), UINT8_C( 63), UINT8_C(244),
      UINT8_C( 56), UINT8_C( 84), UINT8_C(240), UINT8_C(135), UINT8_C(153), UINT8_C(207), UINT8_C( 76), UINT8_C( 34),
      UINT8_C( 67), UINT8_C( 93), UINT8_C( 45), UINT8_C(230), UINT8_C( 17), UINT8_C(177), UINT8_C(114), UINT8_C(180),
      UINT8_C( 60), UINT8_C( 37), UINT8_C(242), UINT8_C(136), UINT8_C(107), UINT8_C(229), UINT8_C(245), UINT8_C( 53),
      UINT8_C(125), UINT8_C(225), UINT8_C( 93), UINT8_C(106), UINT8_C(242), UINT8_C(157), UINT8_C( 95), UINT8_C( 42),
      UINT8_C(241), UINT8_C( 79), UINT8_C(178), UINT8_C(139), UINT8_C( 30), UINT8_C(254), UINT8_C(173), UINT8_C( 97),
      UINT8_C( 91), UINT8_C(219), UINT8_C( 72), UINT8_C(108), UINT8_C(140), UINT8_C(186), UINT8_C( 32), UINT8_C(200),
      UINT8_C(223), UINT8_C( 19), UINT8_C( 81), UINT8_C( 74), UINT8_C(248), UINT8_C( 70), UINT8_C(127), UINT8_C(117),
      UINT8_C( 39), UINT8_C(221), UINT8_C(224), UINT8_C( 25), UINT8_C(122), UINT8_C( 63), UINT8_C( 68), UINT8_C(107),
      UINT8_C(142), UINT8_C(246), UINT8_C(246), UINT8_C(172), UINT8_C(244), UINT8_C(164), UINT8_C( 14), UINT8_C( 79),
      UINT8_C(127), UINT8_C( 86), UINT8_C(187), UINT8_C( 11), UINT8_C( 16), UINT8_C(219), UINT8_C(212), UINT8_C(239),
      UINT8_C(238), UINT8_C( 37), UINT8_C( 57), UINT8_C(230), UINT8_C(107), UINT8_C(184), UINT8_C( 92), UINT8_C(146),
      UINT8_C(149), UINT8_C( 60), UINT8_C(172) };
  static const uint8_t b = UINT8_C(106);
  static const uint8_t e[] =
    { UINT8_C( 98), UINT8_C(209), UINT8_C( 23), UINT8_C( 53), UINT8_C(135), UINT8_C(161), UINT8_C(230), UINT8_C(169),
      UINT8_C( 25), UINT8_C(222), UINT8_C(211), UINT8_C( 17), UINT8_C(172), UINT8_C( 38), UINT8_C(202), UINT8_C( 56),
      UINT8_C(209), UINT8_C(133), UINT8_C(205), UINT8_C(105), UINT8_C(115), UINT8_C(124), UINT8_C(220), UINT8_C(132),
      UINT8_C(171), UINT8_C(227), UINT8_C( 55), UINT8_C(175), UINT8_C(112), UINT8_C( 79), UINT8_C( 35), UINT8_C(211),
      UINT8_C(183), UINT8_C( 58), UINT8_C(158), UINT8_C( 62), UINT8_C(113), UINT8_C( 27), UINT8_C(126), UINT8_C( 33),
      UINT8_C(249), UINT8_C( 81), UINT8_C( 94), UINT8_C(209), UINT8_C(225), UINT8_C(190), UINT8_C(159), UINT8_C(179),
      UINT8_C(218), UINT8_C(108), UINT8_C(178), UINT8_C( 77), UINT8_C(127), UINT8_C(142), UINT8_C( 59), UINT8_C(192),
      UINT8_C(  7), UINT8_C(158), UINT8_C(111), UINT8_C(120), UINT8_C(132), UINT8_C(146), UINT8_C(225), UINT8_C(209),
      UINT8_C( 98), UINT8_C(127), UINT8_C( 15), UINT8_C(106), UINT8_C(154), UINT8_C(141), UINT8_C(139), UINT8_C( 41),
      UINT8_C(117), UINT8_C(127), UINT8_C(250), UINT8_C(236), UINT8_C( 61), UINT8_C(154), UINT8_C(159), UINT8_C( 23),
      UINT8_C(156), UINT8_C(232), UINT8_C(206), UINT8_C( 27), UINT8_C(118), UINT8_C(160), UINT8_C(219), UINT8_C(170),
      UINT8_C( 62), UINT8_C( 75), UINT8_C(184), UINT8_C( 88), UINT8_C(115), UINT8_C(153), UINT8_C( 41), UINT8_C( 64),
      UINT8_C(174), UINT8_C(207), UINT8_C(170), UINT8_C(117), UINT8_C( 92), UINT8_C(203), UINT8_C(158), UINT8_C(103),
      UINT8_C( 74), UINT8_C( 47), UINT8_C( 84), UINT8_C( 29), UINT8_C(245), UINT8_C(137), UINT8_C( 53), UINT8_C(145),
      UINT8_C(113), UINT8_C(153), UINT8_C( 67), UINT8_C(126), UINT8_C( 57), UINT8_C( 74), UINT8_C(146), UINT8_C( 14),
      UINT8_C(149), UINT8_C(224), UINT8_C(102), UINT8_C(159), UINT8_C(121), UINT8_C( 38), UINT8_C(223), UINT8_C( 83),
      UINT8_C(245), UINT8_C( 31), UINT8_C( 50), UINT8_C(231), UINT8_C( 22), UINT8_C(103), UINT8_C( 79), UINT8_C( 96),
      UINT8_C(194), UINT8_C( 13), UINT8_C( 19), UINT8_C( 33), UINT8_C( 44), UINT8_C( 72), UINT8_C(222), UINT8_C(  8),
      UINT8_C( 76), UINT8_C(183), UINT8_C(134), UINT8_C(177), UINT8_C(  2), UINT8_C(174), UINT8_C( 85), UINT8_C( 45),
      UINT8_C(142), UINT8_C( 82), UINT8_C(204), UINT8_C(157), UINT8_C(120), UINT8_C( 65), UINT8_C(240), UINT8_C(109),
      UINT8_C(246), UINT8_C(185), UINT8_C(190), UINT8_C( 12), UINT8_C( 76), UINT8_C(163), UINT8_C(  2), UINT8_C( 14),
      UINT8_C(176), UINT8_C( 22), UINT8_C( 47), UINT8_C(221), UINT8_C(200), UINT8_C(163), UINT8_C( 17), UINT8_C(170),
      UINT8_C( 91), UINT8_C( 45), UINT8_C( 92), UINT8_C( 93), UINT8_C(219), UINT8_C( 71), UINT8_C(244),    UINT8_MAX,
      UINT8_C(153), UINT8_C(193), UINT8_C(200), UINT8_C(123), UINT8_C(152), UINT8_C(184), UINT8_C(126), UINT8_C(143),
      UINT8_C(  7), UINT8_C( 61), UINT8_C(  5), UINT8_C( 83), UINT8_C(224), UINT8_C(  8), UINT8_C( 97), UINT8_C(189),
      UINT8_C(180), UINT8_C( 38), UINT8_C( 48), UINT8_C( 18), UINT8_C(202), UINT8_C(171), UINT8_C(189), UINT8_C( 37),
      UINT8_C(216), UINT8_C(175), UINT8_C( 24), UINT8_C( 73), UINT8_C(246), UINT8_C( 12), UINT8_C(116), UINT8_C(144),
      UINT8_C( 99), UINT8_C( 60), UINT8_C( 55), UINT8_C(252), UINT8_C(138), UINT8_C(182), UINT8_C( 33), UINT8_C(146),
      UINT8_C(137), UINT8_C( 38), UINT8_C( 17), UINT8_C(105), UINT8_C(196), UINT8_C(115), UINT8_C(188), UINT8_C(120),
      UINT8_C(197), UINT8_C(236), UINT8_C( 33), UINT8_C( 37), UINT8_C( 45), UINT8_C(222), UINT8_C(224), UINT8_C(  5),
      UINT8_C(185), UINT8_C(248), UINT8_C(122), UINT8_C(175), UINT8_C(155), UINT8_C(238), UINT8_C(213), UINT8_C(254),
      UINT8_C( 42), UINT8_C(163), UINT8_C(144), UINT8_C(181), UINT8_C(195), UINT8_C(177), UINT8_C( 71), UINT8_C( 76),
      UINT8_C(110), UINT8_C( 88), UINT8_C(225), UINT8_C( 94), UINT8_C( 97), UINT8_C(  8), UINT8_C(109), UINT8_C(189),
      UINT8_C(138), UINT8_C(142), UINT8_C(226), UINT8_C(184), UINT8_C(108), UINT8_C(195), UINT8_C(189), UINT8_C( 37),
      UINT8_C( 37), UINT8_C(206), UINT8_C(106), UINT8_C(192), UINT8_C(188), UINT8_C(108), UINT8_C( 85), UINT8_C( 81),
      UINT8_C(121), UINT8_C(123), UINT8_C(156), UINT8_C(104), UINT8_C( 89), UINT8_C(121), UINT8_C(180), UINT8_C( 93),
      UINT8_C(103), UINT8_C( 43), UINT8_C( 37), UINT8_C( 95), UINT8_C( 51), UINT8_C(146), UINT8_C( 28), UINT8_C( 84),
      UINT8_C(182), UINT8_C(104), UINT8_C( 12), UINT8_C(184), UINT8_C( 43), UINT8_C( 95), UINT8_C(115), UINT8_C(231),
      UINT8_C( 45), UINT8_C(222), UINT8_C( 61), UINT8_C( 84), UINT8_C(224), UINT8_C(190), UINT8_C( 59), UINT8_C( 89),
      UINT8_C( 58), UINT8_C(215), UINT8_C( 87), UINT8_C( 41), UINT8_C( 80), UINT8_C(161), UINT8_C(134), UINT8_C( 77),
      UINT8_C(204), UINT8_C(171), UINT8_C(172), UINT8_C(150), UINT8_C(212), UINT8_C(200), UINT8_C(234), UINT8_C( 32),
      UINT8_C( 49), UINT8_C( 96), UINT8_C(217), UINT8_C(242), UINT8_C(191), UINT8_C( 76), UINT8_C(  5), UINT8_C(237),
      UINT8_C( 42), UINT8_C( 67), UINT8_C(215), UINT8_C(160), UINT8_C(151), UINT8_C( 62), UINT8_C(143), UINT8_C(103),
      UINT8_C( 21), UINT8_C(230), UINT8_C(144), UINT8_C(251), UINT8_C(135), UINT8_C(128), UINT8_C( 72), UINT8_C(190),
      UINT8_C(194), UINT8_C(245), UINT8_C(234), UINT8_C( 44), UINT8_C( 83), UINT8_C( 62), UINT8_C( 76), UINT8_C( 26),
      UINT8_C(202), UINT8_C( 37), UINT8_C( 13), UINT8_C(137), UINT8_C(114), UINT8_C(168), UINT8_C( 12), UINT8_C( 50),
      UINT8_C(129), UINT8_C( 15), UINT8_C(105), UINT8_C( 25), UINT8_C( 77), UINT8_C(248), UINT8_C(234), UINT8_C(248),
      UINT8_C( 73), UINT8_C( 17), UINT8_C(137), UINT8_C(208), UINT8_C( 39), UINT8_C(210), UINT8_C( 36), UINT8_C(233),
      UINT8_C( 93), UINT8_C( 14), UINT8_C(171), UINT8_C(176), UINT8_C(120), UINT8_C(142), UINT8_C(203), UINT8_C( 66),
      UINT8_C(223), UINT8_C(110), UINT8_C( 98), UINT8_C(231), UINT8_C( 22), UINT8_C(  4), UINT8_C(176), UINT8_C( 46),
      UINT8_C(126), UINT8_C( 25), UINT8_C( 71), UINT8_C( 97), UINT8_C(123), UINT8_C(199), UINT8_C( 90), UINT8_C(240),
      UINT8_C(216), UINT8_C(227), UINT8_C(193), UINT8_C(  0), UINT8_C( 75), UINT8_C(123), UINT8_C(127), UINT8_C(168),
      UINT8_C(182), UINT8_C( 43), UINT8_C(239), UINT8_C( 46), UINT8_C(229), UINT8_C( 80), UINT8_C(219), UINT8_C( 46),
      UINT8_C(234), UINT8_C(211), UINT8_C(172), UINT8_C(150), UINT8_C( 65), UINT8_C( 92), UINT8_C(196), UINT8_C(235),
      UINT8_C(223), UINT8_C(117), UINT8_C( 77), UINT8_C(134), UINT8_C( 61), UINT8_C( 17), UINT8_C(119), UINT8_C(171),
      UINT8_C(138), UINT8_C(206), UINT8_C(171), UINT8_C(214), UINT8_C( 73), UINT8_C( 43), UINT8_C( 20),    UINT8_MAX,
      UINT8_C(236), UINT8_C(153), UINT8_C(196), UINT8_C(209), UINT8_C(233), UINT8_C( 53), UINT8_C(149), UINT8_C(105),
      UINT8_C(114), UINT8_C( 65), UINT8_C(106), UINT8_C(223), UINT8_C(  7), UINT8_C(196), UINT8_C(203), UINT8_C( 18),
      UINT8_C(208), UINT8_C(130), UINT8_C(  3), UINT8_C(163), UINT8_C( 41), UINT8_C(122), UINT8_C( 78), UINT8_C(179),
      UINT8_C( 72), UINT8_C(250), UINT8_C( 31), UINT8_C(189), UINT8_C(143), UINT8_C( 52), UINT8_C( 83), UINT8_C(123),
      UINT8_C( 55), UINT8_C(129), UINT8_C(226), UINT8_C(183), UINT8_C(182), UINT8_C(119), UINT8_C( 32), UINT8_C(190),
      UINT8_C( 35), UINT8_C( 32), UINT8_C(157), UINT8_C( 86), UINT8_C(123), UINT8_C(254), UINT8_C(211), UINT8_C( 75),
      UINT8_C( 22), UINT8_C(  2), UINT8_C( 88), UINT8_C( 63), UINT8_C( 18), UINT8_C(166), UINT8_C( 31), UINT8_C(240),
      UINT8_C( 54), UINT8_C( 62), UINT8_C( 23), UINT8_C( 91), UINT8_C(220), UINT8_C(106), UINT8_C(214), UINT8_C( 64),
      UINT8_C( 23), UINT8_C( 78), UINT8_C(247), UINT8_C( 99), UINT8_C(198), UINT8_C(173), UINT8_C( 33), UINT8_C(127),
      UINT8_C(250), UINT8_C( 85), UINT8_C( 63), UINT8_C(223), UINT8_C( 83), UINT8_C(168), UINT8_C( 42), UINT8_C(  0),
      UINT8_C( 64), UINT8_C( 24), UINT8_C( 63), UINT8_C( 82), UINT8_C( 84), UINT8_C( 94), UINT8_C( 66), UINT8_C( 33),
      UINT8_C( 51), UINT8_C(240), UINT8_C(124), UINT8_C( 15), UINT8_C( 90), UINT8_C(233), UINT8_C(229), UINT8_C(  8),
      UINT8_C( 55), UINT8_C(114), UINT8_C(213), UINT8_C(103), UINT8_C( 32), UINT8_C(141), UINT8_C(230), UINT8_C(176),
      UINT8_C( 14), UINT8_C(188), UINT8_C(143), UINT8_C(247), UINT8_C(144), UINT8_C( 79), UINT8_C(247), UINT8_C(209),
      UINT8_C(147), UINT8_C( 55), UINT8_C(141), UINT8_C(231), UINT8_C( 43), UINT8_C(102), UINT8_C(  8), UINT8_C(244),
      UINT8_C( 86), UINT8_C(133), UINT8_C(154), UINT8_C( 70), UINT8_C(  4), UINT8_C(127), UINT8_C( 78), UINT8_C( 59),
      UINT8_C(242), UINT8_C(186), UINT8_C( 57), UINT8_C( 18), UINT8_C( 71), UINT8_C(181), UINT8_C( 88), UINT8_C( 85),
      UINT8_C(113), UINT8_C(231), UINT8_C(226), UINT8_C(152), UINT8_C( 98), UINT8_C(218), UINT8_C(105), UINT8_C( 95),
      UINT8_C(167), UINT8_C(140), UINT8_C(114), UINT8_C(104), UINT8_C(242), UINT8_C(123), UINT8_C( 93), UINT8_C(178),
      UINT8_C(150), UINT8_C(247), UINT8_C(249), UINT8_C(154), UINT8_C(118), UINT8_C(221), UINT8_C(107), UINT8_C(210),
      UINT8_C(151), UINT8_C(164), UINT8_C(122), UINT8_C(222), UINT8_C( 90), UINT8_C(210), UINT8_C(201), UINT8_C(203),
      UINT8_C( 79), UINT8_C( 66), UINT8_C( 99), UINT8_C(177), UINT8_C( 28), UINT8_C( 98), UINT8_C(166), UINT8_C( 45),
      UINT8_C( 89), UINT8_C( 25), UINT8_C(149), UINT8_C( 75), UINT8_C( 42), UINT8_C(242), UINT8_C(148), UINT8_C(236),
      UINT8_C(233), UINT8_C(185), UINT8_C( 28), UINT8_C(246), UINT8_C(  0), UINT8_C(135), UINT8_C( 94), UINT8_C(152),
      UINT8_C(150), UINT8_C(217), UINT8_C( 12), UINT8_C(240), UINT8_C( 65), UINT8_C(108), UINT8_C( 81), UINT8_C(189),
      UINT8_C(174), UINT8_C( 75), UINT8_C(  4), UINT8_C( 96), UINT8_C( 67), UINT8_C(171), UINT8_C(141), UINT8_C(156),
      UINT8_C(240), UINT8_C( 78), UINT8_C(126), UINT8_C( 26), UINT8_C(215), UINT8_C( 62), UINT8_C(156), UINT8_C( 86),
      UINT8_C( 97), UINT8_C( 34), UINT8_C( 76), UINT8_C(141), UINT8_C(169), UINT8_C(171), UINT8_C(187), UINT8_C(213),
      UINT8_C( 26), UINT8_C( 94), UINT8_C(241), UINT8_C( 91), UINT8_C(202), UINT8_C(217), UINT8_C( 24), UINT8_C( 14),
      UINT8_C(186), UINT8_C(179), UINT8_C(110), UINT8_C(253), UINT8_C( 94), UINT8_C(145), UINT8_C(154), UINT8_C(228),
      UINT8_C(223), UINT8_C( 68), UINT8_C(148), UINT8_C( 76), UINT8_C(236), UINT8_C( 48), UINT8_C(163), UINT8_C(121),
      UINT8_C( 82), UINT8_C( 89), UINT8_C(112), UINT8_C(145), UINT8_C(154), UINT8_C( 44), UINT8_C(147), UINT8_C(180),
      UINT8_C(138), UINT8_C(238), UINT8_C(166), UINT8_C(234), UINT8_C( 93), UINT8_C(190), UINT8_C( 36), UINT8_C( 23),
      UINT8_C(  7), UINT8_C( 40), UINT8_C( 21), UINT8_C(101), UINT8_C(185), UINT8_C( 69), UINT8_C( 73), UINT8_C( 46),
      UINT8_C(243), UINT8_C(221), UINT8_C(123), UINT8_C( 11), UINT8_C(163), UINT8_C(180), UINT8_C(238), UINT8_C(139),
      UINT8_C( 13), UINT8_C(244), UINT8_C( 29), UINT8_C(168), UINT8_C( 76), UINT8_C( 70), UINT8_C(242), UINT8_C(108),
      UINT8_C(202), UINT8_C(152), UINT8_C(236), UINT8_C( 40), UINT8_C( 87), UINT8_C(122), UINT8_C(169), UINT8_C(244),
      UINT8_C(162), UINT8_C( 84), UINT8_C( 90), UINT8_C(241), UINT8_C(153), UINT8_C( 57), UINT8_C(182), UINT8_C( 34),
      UINT8_C( 67), UINT8_C( 93), UINT8_C(151), UINT8_C( 80), UINT8_C(123), UINT8_C(177), UINT8_C(220), UINT8_C(180),
      UINT8_C(166), UINT8_C( 37), UINT8_C( 92), UINT8_C(136), UINT8_C(213), UINT8_C( 79), UINT8_C(245), UINT8_C(159),
      UINT8_C(125), UINT8_C( 75), UINT8_C( 93), UINT8_C(106), UINT8_C(242), UINT8_C(  7), UINT8_C( 95), UINT8_C(148),
      UINT8_C(241), UINT8_C(185), UINT8_C( 28), UINT8_C(139), UINT8_C( 30), UINT8_C(254), UINT8_C(173), UINT8_C(203),
      UINT8_C(197), UINT8_C(219), UINT8_C( 72), UINT8_C(108), UINT8_C(140), UINT8_C(186), UINT8_C( 32), UINT8_C(200),
      UINT8_C( 73), UINT8_C( 19), UINT8_C(187), UINT8_C( 74), UINT8_C(248), UINT8_C( 70), UINT8_C(127), UINT8_C(117),
      UINT8_C(145), UINT8_C(221), UINT8_C(224), UINT8_C(131), UINT8_C(122), UINT8_C( 63), UINT8_C(174), UINT8_C(107),
      UINT8_C(142), UINT8_C(246), UINT8_C( 96), UINT8_C(172), UINT8_C(244), UINT8_C(164), UINT8_C( 14), UINT8_C(185),
      UINT8_C(127), UINT8_C(192), UINT8_C( 37), UINT8_C(117), UINT8_C(122), UINT8_C(219), UINT8_C(212), UINT8_C(239),
      UINT8_C(238), UINT8_C(143), UINT8_C(163), UINT8_C( 80), UINT8_C(213), UINT8_C( 34), UINT8_C(198), UINT8_C(146),
      UINT8_C(149), UINT8_C(166), UINT8_C(172) };

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
    rv = simde_svadd_n_u8_m(pv, av, b);

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

    ev = simde_svadd_n_u8_m(pv, av, b);

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
test_simde_svadd_n_u16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1) };
  static const uint16_t a[] =
    { UINT16_C(22303), UINT16_C(22690), UINT16_C( 8862), UINT16_C( 2123), UINT16_C(19988), UINT16_C(60741), UINT16_C(  240), UINT16_C(49707),
      UINT16_C(28264), UINT16_C( 2947), UINT16_C(32732), UINT16_C(63431), UINT16_C(16680), UINT16_C(35971), UINT16_C(57334), UINT16_C( 5419),
      UINT16_C(52790), UINT16_C(54637), UINT16_C(47344), UINT16_C( 1245), UINT16_C( 8710), UINT16_C(63218), UINT16_C( 7458), UINT16_C(35768),
      UINT16_C(15243), UINT16_C(26774), UINT16_C(23995), UINT16_C(58207), UINT16_C(58014), UINT16_C(38000), UINT16_C(39874), UINT16_C(63657),
      UINT16_C( 5737), UINT16_C(22989), UINT16_C(43726), UINT16_C(54366), UINT16_C(20685), UINT16_C(61387), UINT16_C(33645), UINT16_C(63610),
      UINT16_C( 4287), UINT16_C(31328), UINT16_C(49261), UINT16_C( 3165), UINT16_C(52642), UINT16_C(25760), UINT16_C(19049), UINT16_C(53853),
      UINT16_C(10848), UINT16_C(12076), UINT16_C(35541), UINT16_C(41475), UINT16_C(52954), UINT16_C(18321), UINT16_C( 3154), UINT16_C( 4415),
      UINT16_C(40988), UINT16_C(35467), UINT16_C(59488), UINT16_C(  662), UINT16_C(14006), UINT16_C( 8039), UINT16_C(50304), UINT16_C(57841),
      UINT16_C( 7662), UINT16_C(49936), UINT16_C( 5031), UINT16_C(33125), UINT16_C(63458), UINT16_C(13512), UINT16_C( 2051), UINT16_C( 8005),
      UINT16_C(53416), UINT16_C( 2217), UINT16_C(16312), UINT16_C(28170), UINT16_C(29046), UINT16_C(63117), UINT16_C(32565), UINT16_C( 9431),
      UINT16_C(59292), UINT16_C(17639), UINT16_C(19963), UINT16_C(56773), UINT16_C(36420), UINT16_C(18193), UINT16_C(22166), UINT16_C(15974),
      UINT16_C( 4134), UINT16_C(56902), UINT16_C(20559), UINT16_C(50509), UINT16_C(56002), UINT16_C(63420), UINT16_C(37721), UINT16_C(63003),
      UINT16_C(  891), UINT16_C(30266), UINT16_C(65360), UINT16_C(37971), UINT16_C(25741), UINT16_C( 9179), UINT16_C(16826), UINT16_C(57441),
      UINT16_C(42833), UINT16_C(41406), UINT16_C( 3064), UINT16_C(47718), UINT16_C( 8934), UINT16_C(16305), UINT16_C(52662), UINT16_C(12597),
      UINT16_C(28624), UINT16_C( 8359), UINT16_C(64111), UINT16_C(64692), UINT16_C(36702), UINT16_C( 6176), UINT16_C(33232), UINT16_C( 8952),
      UINT16_C(46633), UINT16_C( 8643), UINT16_C(10690), UINT16_C(43227), UINT16_C(35916), UINT16_C(  743), UINT16_C( 7513), UINT16_C(10547),
      UINT16_C(55948), UINT16_C(64329), UINT16_C(64980), UINT16_C(13048), UINT16_C( 6284), UINT16_C(23882), UINT16_C(17049), UINT16_C(49791),
      UINT16_C(17144), UINT16_C(47843), UINT16_C(48747), UINT16_C(46946), UINT16_C(19019), UINT16_C(42169), UINT16_C(60519), UINT16_C(62414),
      UINT16_C( 6086), UINT16_C(39663), UINT16_C(59157), UINT16_C(41420), UINT16_C( 5887), UINT16_C(39166), UINT16_C(32088), UINT16_C(20827),
      UINT16_C(16063), UINT16_C(11019), UINT16_C(28413), UINT16_C(18658), UINT16_C(40120), UINT16_C( 8172), UINT16_C(47752), UINT16_C(20242),
      UINT16_C(  466), UINT16_C(59369), UINT16_C(46824), UINT16_C(59272), UINT16_C(34764), UINT16_C( 9600), UINT16_C(56068), UINT16_C(50294),
      UINT16_C(33049), UINT16_C( 5871), UINT16_C(53743), UINT16_C(42846), UINT16_C(19309), UINT16_C(63174), UINT16_C(55557), UINT16_C(55109),
      UINT16_C(11994), UINT16_C(50110), UINT16_C(18404), UINT16_C(45482), UINT16_C(10958), UINT16_C(53974), UINT16_C(19461), UINT16_C( 8086),
      UINT16_C(34253), UINT16_C(48437), UINT16_C(37975), UINT16_C(50276), UINT16_C(11231), UINT16_C(58554), UINT16_C(65284), UINT16_C(57020),
      UINT16_C(31278), UINT16_C( 4769), UINT16_C(19649), UINT16_C(36803), UINT16_C(39286), UINT16_C(31842), UINT16_C(63717), UINT16_C(45979),
      UINT16_C(53374), UINT16_C(54640), UINT16_C(54372), UINT16_C(17305), UINT16_C(21759), UINT16_C(  808), UINT16_C(58451), UINT16_C(33250),
      UINT16_C(33630), UINT16_C( 8340), UINT16_C(22479), UINT16_C(18095), UINT16_C( 4593), UINT16_C(54978), UINT16_C(23818), UINT16_C(34953),
      UINT16_C(63789), UINT16_C(37469), UINT16_C(63182), UINT16_C(52693), UINT16_C(64842), UINT16_C(40657), UINT16_C(46049), UINT16_C(16415),
      UINT16_C(45878), UINT16_C( 1632), UINT16_C( 3851), UINT16_C(64588), UINT16_C( 3617), UINT16_C(11218), UINT16_C(23659), UINT16_C(39091),
      UINT16_C( 4181), UINT16_C( 9002), UINT16_C(    6), UINT16_C(20977), UINT16_C(49917), UINT16_C(57327), UINT16_C( 3701), UINT16_C(43807),
      UINT16_C(32706), UINT16_C(52657), UINT16_C(64910), UINT16_C(45001), UINT16_C(39691), UINT16_C(30426), UINT16_C(36343), UINT16_C(19727),
      UINT16_C(14749), UINT16_C(42096), UINT16_C(24889), UINT16_C(14325), UINT16_C(58403), UINT16_C(38934), UINT16_C(13810), UINT16_C(46148),
      UINT16_C(62900), UINT16_C(17025), UINT16_C(19187), UINT16_C(65266), UINT16_C(52454), UINT16_C(56693), UINT16_C(33882), UINT16_C(63274),
      UINT16_C(39869), UINT16_C(63387), UINT16_C(37116), UINT16_C( 8238), UINT16_C(17524), UINT16_C(26552), UINT16_C(64633), UINT16_C(11547),
      UINT16_C(40434), UINT16_C(58735), UINT16_C(25063), UINT16_C(52707), UINT16_C(22574), UINT16_C(34987), UINT16_C(54748), UINT16_C(39551),
      UINT16_C( 7024), UINT16_C(28049), UINT16_C(49067), UINT16_C( 8333), UINT16_C(17667), UINT16_C(31879), UINT16_C(41538), UINT16_C(13481),
      UINT16_C( 6207), UINT16_C(10009), UINT16_C(64634), UINT16_C(43252), UINT16_C(40789), UINT16_C(12592), UINT16_C(44917), UINT16_C(58827),
      UINT16_C(23754), UINT16_C(30290), UINT16_C(57115), UINT16_C( 7830), UINT16_C( 7461), UINT16_C(26522), UINT16_C(17343), UINT16_C(65435),
      UINT16_C(46172), UINT16_C(54822), UINT16_C( 6832), UINT16_C( 1406), UINT16_C(44730), UINT16_C(12087), UINT16_C(  605), UINT16_C(10260),
      UINT16_C(26463), UINT16_C(31390), UINT16_C(13382), UINT16_C(27545), UINT16_C(13137), UINT16_C( 4306), UINT16_C(28023), UINT16_C(54031),
      UINT16_C(13601), UINT16_C(53929), UINT16_C(10064), UINT16_C( 2775), UINT16_C( 3797), UINT16_C(12857), UINT16_C(19729), UINT16_C(28762),
      UINT16_C(63668), UINT16_C(64490), UINT16_C(33580), UINT16_C(32102), UINT16_C(14775), UINT16_C(11918), UINT16_C(40358), UINT16_C(51201),
      UINT16_C(43731), UINT16_C( 9114), UINT16_C(29137), UINT16_C(42541), UINT16_C(26240), UINT16_C(37336), UINT16_C(13235), UINT16_C(26625),
      UINT16_C(60203), UINT16_C(22627), UINT16_C(51567), UINT16_C( 9941), UINT16_C(25346), UINT16_C(43348), UINT16_C(21761), UINT16_C(54385),
      UINT16_C( 3071), UINT16_C(53495), UINT16_C( 9340), UINT16_C(64630), UINT16_C(20106), UINT16_C(15757), UINT16_C(36481), UINT16_C(44453),
      UINT16_C( 2170), UINT16_C(59653), UINT16_C(56018), UINT16_C(54287), UINT16_C(25406), UINT16_C(16253), UINT16_C(61112), UINT16_C(46867),
      UINT16_C( 2809), UINT16_C(30343), UINT16_C(64814), UINT16_C(47218), UINT16_C(   75), UINT16_C(52725), UINT16_C(39822), UINT16_C( 2170),
      UINT16_C(32675), UINT16_C(30193), UINT16_C(   89), UINT16_C(38730), UINT16_C(51043), UINT16_C( 7126), UINT16_C(59830), UINT16_C(45010),
      UINT16_C(23027), UINT16_C( 8485), UINT16_C(38998), UINT16_C(41689), UINT16_C(53144), UINT16_C( 9839), UINT16_C(59754), UINT16_C( 3375),
      UINT16_C( 8296), UINT16_C(49539), UINT16_C(52513), UINT16_C(33881), UINT16_C(12180), UINT16_C(19104), UINT16_C(29209), UINT16_C( 3322),
      UINT16_C( 8140), UINT16_C( 8750), UINT16_C( 1975), UINT16_C(20420), UINT16_C(13270), UINT16_C(16502), UINT16_C(42268), UINT16_C(33870),
      UINT16_C(53701), UINT16_C(58950), UINT16_C(40862), UINT16_C(12907), UINT16_C( 3022), UINT16_C(59261), UINT16_C(30589), UINT16_C(18932),
      UINT16_C( 8854), UINT16_C(20076), UINT16_C(12329), UINT16_C(  157), UINT16_C( 4964), UINT16_C(32832), UINT16_C(36536), UINT16_C(32261),
      UINT16_C(19295), UINT16_C(64868), UINT16_C(53226), UINT16_C(47152), UINT16_C(44506), UINT16_C(22688), UINT16_C(37924), UINT16_C(47777),
      UINT16_C( 3510), UINT16_C(57096), UINT16_C(42558), UINT16_C(41695), UINT16_C( 8377), UINT16_C(29218), UINT16_C(10158), UINT16_C( 3824),
      UINT16_C(21618), UINT16_C(23563), UINT16_C(15140), UINT16_C(65045), UINT16_C(46568), UINT16_C( 3158), UINT16_C(63561), UINT16_C(65479),
      UINT16_C(52997), UINT16_C(17374), UINT16_C(48757), UINT16_C(12261), UINT16_C( 2270), UINT16_C(36001), UINT16_C(37167), UINT16_C(41626),
      UINT16_C(42725) };
  static const uint16_t b = UINT16_C( 7085);
  static const uint16_t e[] =
    { UINT16_C(    0), UINT16_C(    0), UINT16_C(15947), UINT16_C( 9208), UINT16_C(27073), UINT16_C(    0), UINT16_C( 7325), UINT16_C(56792),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(39817), UINT16_C(    0), UINT16_C(23765), UINT16_C(    0), UINT16_C(64419), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(61722), UINT16_C(    0), UINT16_C( 8330), UINT16_C(    0), UINT16_C(    0), UINT16_C(14543), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(31080), UINT16_C(65292), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(50811), UINT16_C(61451), UINT16_C(27770), UINT16_C( 2936), UINT16_C(40730), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(38413), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(32845), UINT16_C(    0), UINT16_C(60938),
      UINT16_C(    0), UINT16_C(19161), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(10239), UINT16_C(11500),
      UINT16_C(48073), UINT16_C(    0), UINT16_C( 1037), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(57389), UINT16_C(64926),
      UINT16_C(    0), UINT16_C(57021), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(60501), UINT16_C( 9302), UINT16_C(    0), UINT16_C(    0), UINT16_C(36131), UINT16_C(    0), UINT16_C(    0), UINT16_C(16516),
      UINT16_C(  841), UINT16_C(24724), UINT16_C(    0), UINT16_C(63858), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(63987), UINT16_C(27644), UINT16_C(57594), UINT16_C(63087), UINT16_C( 4969), UINT16_C(44806), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(37351), UINT16_C( 6909), UINT16_C(45056), UINT16_C(32826), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(49918), UINT16_C(    0), UINT16_C(10149), UINT16_C(    0), UINT16_C(16019), UINT16_C(23390), UINT16_C(59747), UINT16_C(19682),
      UINT16_C(35709), UINT16_C(    0), UINT16_C( 5660), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(16037),
      UINT16_C(    0), UINT16_C(15728), UINT16_C(    0), UINT16_C(50312), UINT16_C(43001), UINT16_C(    0), UINT16_C(    0), UINT16_C(17632),
      UINT16_C(63033), UINT16_C( 5878), UINT16_C(    0), UINT16_C(20133), UINT16_C(    0), UINT16_C(30967), UINT16_C(24134), UINT16_C(56876),
      UINT16_C(24229), UINT16_C(54928), UINT16_C(55832), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 2068), UINT16_C( 3963),
      UINT16_C(    0), UINT16_C(46748), UINT16_C(  706), UINT16_C(    0), UINT16_C(12972), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(35498), UINT16_C(25743), UINT16_C(    0), UINT16_C(15257), UINT16_C(54837), UINT16_C(27327),
      UINT16_C(    0), UINT16_C(  918), UINT16_C(53909), UINT16_C(    0), UINT16_C(    0), UINT16_C(16685), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(40134), UINT16_C(12956), UINT16_C(60828), UINT16_C(49931), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(62194),
      UINT16_C(19079), UINT16_C(57195), UINT16_C(25489), UINT16_C(52567), UINT16_C(18043), UINT16_C(    0), UINT16_C(26546), UINT16_C(15171),
      UINT16_C(    0), UINT16_C(55522), UINT16_C(45060), UINT16_C(    0), UINT16_C(18316), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(38363), UINT16_C(11854), UINT16_C(    0), UINT16_C(    0), UINT16_C(46371), UINT16_C(38927), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(61725), UINT16_C(    0), UINT16_C(    0), UINT16_C(28844), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(15425), UINT16_C(    0), UINT16_C(    0), UINT16_C(11678), UINT16_C(62063), UINT16_C(    0), UINT16_C(42038),
      UINT16_C(    0), UINT16_C(44554), UINT16_C( 4731), UINT16_C(59778), UINT16_C( 6391), UINT16_C(    0), UINT16_C(53134), UINT16_C(    0),
      UINT16_C(52963), UINT16_C(    0), UINT16_C(10936), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(46176),
      UINT16_C(    0), UINT16_C(16087), UINT16_C( 7091), UINT16_C(    0), UINT16_C(57002), UINT16_C(64412), UINT16_C(10786), UINT16_C(50892),
      UINT16_C(    0), UINT16_C(59742), UINT16_C( 6459), UINT16_C(52086), UINT16_C(    0), UINT16_C(37511), UINT16_C(    0), UINT16_C(26812),
      UINT16_C(    0), UINT16_C(49181), UINT16_C(31974), UINT16_C(    0), UINT16_C(65488), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C( 4449), UINT16_C(    0), UINT16_C(    0), UINT16_C( 6815), UINT16_C(59539), UINT16_C(    0), UINT16_C(40967), UINT16_C(    0),
      UINT16_C(    0), UINT16_C( 4936), UINT16_C(44201), UINT16_C(15323), UINT16_C(    0), UINT16_C(33637), UINT16_C( 6182), UINT16_C(18632),
      UINT16_C(    0), UINT16_C(  284), UINT16_C(    0), UINT16_C(    0), UINT16_C(29659), UINT16_C(42072), UINT16_C(61833), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(35134), UINT16_C(    0), UINT16_C(    0), UINT16_C(24752), UINT16_C(    0), UINT16_C(48623), UINT16_C(20566),
      UINT16_C(13292), UINT16_C(    0), UINT16_C(    0), UINT16_C(50337), UINT16_C(47874), UINT16_C(    0), UINT16_C(52002), UINT16_C(  376),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(64200), UINT16_C(    0), UINT16_C(    0), UINT16_C(33607), UINT16_C(24428), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(19172), UINT16_C( 7690), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(20467), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(20686), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(10882), UINT16_C(    0), UINT16_C(    0), UINT16_C(35847),
      UINT16_C( 5217), UINT16_C( 6039), UINT16_C(40665), UINT16_C(39187), UINT16_C(21860), UINT16_C(    0), UINT16_C(47443), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(16199), UINT16_C(    0), UINT16_C(49626), UINT16_C(33325), UINT16_C(    0), UINT16_C(20320), UINT16_C(33710),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(58652), UINT16_C(17026), UINT16_C(    0), UINT16_C(    0), UINT16_C(28846), UINT16_C(61470),
      UINT16_C(    0), UINT16_C(60580), UINT16_C(    0), UINT16_C( 6179), UINT16_C(27191), UINT16_C(22842), UINT16_C(43566), UINT16_C(    0),
      UINT16_C( 9255), UINT16_C(    0), UINT16_C(63103), UINT16_C(    0), UINT16_C(    0), UINT16_C(23338), UINT16_C( 2661), UINT16_C(    0),
      UINT16_C( 9894), UINT16_C(37428), UINT16_C(    0), UINT16_C(54303), UINT16_C( 7160), UINT16_C(59810), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(14211), UINT16_C(    0), UINT16_C(52095),
      UINT16_C(    0), UINT16_C(15570), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 1303), UINT16_C(10460),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(15835), UINT16_C( 9060), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(40955),
      UINT16_C(60786), UINT16_C(  499), UINT16_C(47947), UINT16_C(19992), UINT16_C(    0), UINT16_C(  810), UINT16_C(37674), UINT16_C(    0),
      UINT16_C(15939), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(39917), UINT16_C(    0), UINT16_C(39346),
      UINT16_C(    0), UINT16_C( 6417), UINT16_C(60311), UINT16_C(54237), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(10595), UINT16_C(    0), UINT16_C(49643), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(17243), UINT16_C(    0),
      UINT16_C(28703), UINT16_C(30648), UINT16_C(22225), UINT16_C(    0), UINT16_C(    0), UINT16_C(10243), UINT16_C( 5110), UINT16_C( 7028),
      UINT16_C(    0), UINT16_C(24459), UINT16_C(    0), UINT16_C(19346), UINT16_C(    0), UINT16_C(43086), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(49810) };

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
    rv = simde_svadd_n_u16_z(pv, av, b);

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

    ev = simde_svadd_n_u16_z(pv, av, b);

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
test_simde_svadd_n_u16_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1) };
  static const uint16_t a[] =
    { UINT16_C(40761), UINT16_C( 9429), UINT16_C(48934), UINT16_C(20121), UINT16_C(19194), UINT16_C(46483), UINT16_C(56379), UINT16_C(28463),
      UINT16_C(18301), UINT16_C(58743), UINT16_C(17621), UINT16_C(32077), UINT16_C(55968), UINT16_C(26602), UINT16_C(13010), UINT16_C( 3006),
      UINT16_C(37842), UINT16_C(63535), UINT16_C(51539), UINT16_C(19782), UINT16_C(55571), UINT16_C(19970), UINT16_C(12725), UINT16_C(12989),
      UINT16_C(13432), UINT16_C(19991), UINT16_C(25720), UINT16_C( 6603), UINT16_C(46398), UINT16_C( 4224), UINT16_C(16104), UINT16_C(47643),
      UINT16_C(19409), UINT16_C( 9394), UINT16_C(63508), UINT16_C(10098), UINT16_C(29905), UINT16_C(34421), UINT16_C(12966), UINT16_C( 7865),
      UINT16_C(53351), UINT16_C(57196), UINT16_C(14133), UINT16_C(29688), UINT16_C(30957), UINT16_C(54660), UINT16_C(40886), UINT16_C(34959),
      UINT16_C(16874), UINT16_C(65196), UINT16_C( 7737), UINT16_C( 2597), UINT16_C(39571), UINT16_C(14736), UINT16_C(18893), UINT16_C(13399),
      UINT16_C(50202), UINT16_C(20243), UINT16_C( 3323), UINT16_C(59586), UINT16_C(18052), UINT16_C(15293), UINT16_C(19686), UINT16_C(53443),
      UINT16_C(28557), UINT16_C(50895), UINT16_C(62606), UINT16_C( 8656), UINT16_C(24975), UINT16_C(23642), UINT16_C(45482), UINT16_C(50320),
      UINT16_C(41845), UINT16_C(28947), UINT16_C(54959), UINT16_C(13401), UINT16_C( 5916), UINT16_C(  623), UINT16_C(12899), UINT16_C(61907),
      UINT16_C(41633), UINT16_C(12215), UINT16_C(34966), UINT16_C( 9552), UINT16_C(43753), UINT16_C(37761), UINT16_C( 4444), UINT16_C(53592),
      UINT16_C(27573), UINT16_C(25666), UINT16_C(40001), UINT16_C(24216), UINT16_C( 1971), UINT16_C( 5728), UINT16_C(13113), UINT16_C(56071),
      UINT16_C(49109), UINT16_C(27658), UINT16_C(23367), UINT16_C(12433), UINT16_C( 4869), UINT16_C(25027), UINT16_C( 6948), UINT16_C(55603),
      UINT16_C(30087), UINT16_C(51262), UINT16_C(54801), UINT16_C(50214), UINT16_C(34782), UINT16_C( 6107), UINT16_C(58042), UINT16_C(37106),
      UINT16_C(64929), UINT16_C(59644), UINT16_C(36184), UINT16_C(23832), UINT16_C(56480), UINT16_C(50623), UINT16_C(62199), UINT16_C(32414),
      UINT16_C(56423), UINT16_C(31047), UINT16_C(28083), UINT16_C(37181), UINT16_C( 6388), UINT16_C(44968), UINT16_C(39931), UINT16_C(39999),
      UINT16_C(15256), UINT16_C(61573), UINT16_C(40392), UINT16_C(26957), UINT16_C( 3193), UINT16_C(28974), UINT16_C(52478), UINT16_C(26351),
      UINT16_C(13993), UINT16_C(23775), UINT16_C( 7332), UINT16_C(39149), UINT16_C(38197), UINT16_C(12359), UINT16_C(34352), UINT16_C(51404),
      UINT16_C(20929), UINT16_C(35512), UINT16_C( 1775), UINT16_C(26867), UINT16_C( 8466), UINT16_C( 4569), UINT16_C(51693), UINT16_C(38519),
      UINT16_C(22271), UINT16_C(41970), UINT16_C(57202), UINT16_C(42812), UINT16_C(33653), UINT16_C(42455), UINT16_C(41994), UINT16_C(52078),
      UINT16_C( 9973), UINT16_C(58453), UINT16_C(18476), UINT16_C(16205), UINT16_C( 9833), UINT16_C(22352), UINT16_C(51183), UINT16_C(61421),
      UINT16_C(57373), UINT16_C(36754), UINT16_C(52927), UINT16_C(13367), UINT16_C( 3666), UINT16_C(23770), UINT16_C(18610), UINT16_C(43047),
      UINT16_C(32110), UINT16_C(39820), UINT16_C(55749), UINT16_C(12250), UINT16_C(10752), UINT16_C(61318), UINT16_C(29681), UINT16_C( 3806),
      UINT16_C(29011), UINT16_C( 5021), UINT16_C(54335), UINT16_C(37191), UINT16_C( 8675), UINT16_C(38381), UINT16_C( 5481), UINT16_C(55357),
      UINT16_C(51858), UINT16_C(22387), UINT16_C(19875), UINT16_C(41862), UINT16_C( 3191), UINT16_C(26771), UINT16_C(29056), UINT16_C(54134),
      UINT16_C( 5090), UINT16_C( 8934), UINT16_C(12008), UINT16_C(52147), UINT16_C(41295), UINT16_C(47456), UINT16_C(40630), UINT16_C(18577),
      UINT16_C( 1128), UINT16_C( 2975), UINT16_C( 9809), UINT16_C(51375), UINT16_C(16946), UINT16_C(45616), UINT16_C(42675), UINT16_C(38534),
      UINT16_C(27833), UINT16_C(41400), UINT16_C(27546), UINT16_C(60012), UINT16_C(52492), UINT16_C(49827), UINT16_C(13419), UINT16_C(54026),
      UINT16_C(43576), UINT16_C(35294), UINT16_C(36304), UINT16_C(  593), UINT16_C(33231), UINT16_C(33717), UINT16_C(15143), UINT16_C(57369),
      UINT16_C(53671), UINT16_C(17026), UINT16_C(60988), UINT16_C(18732), UINT16_C(53179), UINT16_C( 9739), UINT16_C( 5635), UINT16_C(15353),
      UINT16_C(55488), UINT16_C(37060), UINT16_C( 5477), UINT16_C(13714), UINT16_C(18326), UINT16_C(48568), UINT16_C(53634), UINT16_C(10909),
      UINT16_C( 8098), UINT16_C(56940), UINT16_C(38926), UINT16_C(51495), UINT16_C(13159), UINT16_C(27376), UINT16_C(59721), UINT16_C( 2469),
      UINT16_C(27073), UINT16_C(10137), UINT16_C(11134), UINT16_C( 5212), UINT16_C( 5235), UINT16_C(62929), UINT16_C(28389), UINT16_C(34591),
      UINT16_C(35726), UINT16_C(40037), UINT16_C(36131), UINT16_C(35429), UINT16_C(21952), UINT16_C( 2548), UINT16_C(39231), UINT16_C(   18),
      UINT16_C(43778), UINT16_C(32807), UINT16_C(33750), UINT16_C(18836), UINT16_C(26007), UINT16_C(31807), UINT16_C(24276), UINT16_C(25091),
      UINT16_C(27114), UINT16_C( 3582), UINT16_C(25590), UINT16_C(46744), UINT16_C(36025), UINT16_C(63679), UINT16_C(53542), UINT16_C(10488),
      UINT16_C( 8316), UINT16_C(21161), UINT16_C(15779), UINT16_C(15260), UINT16_C(56227), UINT16_C(30647), UINT16_C(47929), UINT16_C( 9177),
      UINT16_C(55076), UINT16_C( 6705), UINT16_C(51514), UINT16_C(62416), UINT16_C(36693), UINT16_C(31723), UINT16_C(58464), UINT16_C(56484),
      UINT16_C(19716), UINT16_C(42798), UINT16_C(51850), UINT16_C(11746), UINT16_C(39589), UINT16_C(57252), UINT16_C(32085), UINT16_C(30978),
      UINT16_C(13140), UINT16_C(36755), UINT16_C(25596), UINT16_C(21122), UINT16_C(28402), UINT16_C(21197), UINT16_C(29010), UINT16_C(22062),
      UINT16_C(23742), UINT16_C(18941), UINT16_C(57383), UINT16_C(52342), UINT16_C( 7034), UINT16_C(53163), UINT16_C(44696), UINT16_C(60744),
      UINT16_C(56289), UINT16_C(56956), UINT16_C(65086), UINT16_C(12336), UINT16_C(64876), UINT16_C(48770), UINT16_C(45167), UINT16_C(11540),
      UINT16_C( 4620), UINT16_C(13174), UINT16_C(60914), UINT16_C(27648), UINT16_C(43784), UINT16_C(41019), UINT16_C(33625), UINT16_C(15245),
      UINT16_C( 2398), UINT16_C(39961), UINT16_C(18696), UINT16_C(29900), UINT16_C(20038), UINT16_C(46387), UINT16_C(18430), UINT16_C( 2787),
      UINT16_C(22873), UINT16_C(19262), UINT16_C(15942), UINT16_C(20151), UINT16_C(62185), UINT16_C(17391), UINT16_C(31861), UINT16_C(54142),
      UINT16_C(38790), UINT16_C(36463), UINT16_C(15328), UINT16_C( 9730), UINT16_C(13705), UINT16_C(34780), UINT16_C(49021), UINT16_C(54930),
      UINT16_C(53272), UINT16_C(24354), UINT16_C(55566), UINT16_C(63405), UINT16_C(40140), UINT16_C(16698), UINT16_C(47129), UINT16_C(40725),
      UINT16_C(33871), UINT16_C(12077) };
  static const uint16_t b = UINT16_C(62736);
  static const uint16_t e[] =
    { UINT16_C(40761), UINT16_C( 6629), UINT16_C(48934), UINT16_C(20121), UINT16_C(19194), UINT16_C(43683), UINT16_C(56379), UINT16_C(28463),
      UINT16_C(18301), UINT16_C(55943), UINT16_C(14821), UINT16_C(29277), UINT16_C(55968), UINT16_C(26602), UINT16_C(10210), UINT16_C(  206),
      UINT16_C(35042), UINT16_C(63535), UINT16_C(51539), UINT16_C(19782), UINT16_C(52771), UINT16_C(17170), UINT16_C(12725), UINT16_C(12989),
      UINT16_C(10632), UINT16_C(19991), UINT16_C(22920), UINT16_C( 6603), UINT16_C(46398), UINT16_C( 4224), UINT16_C(13304), UINT16_C(47643),
      UINT16_C(16609), UINT16_C( 9394), UINT16_C(60708), UINT16_C( 7298), UINT16_C(27105), UINT16_C(34421), UINT16_C(12966), UINT16_C( 7865),
      UINT16_C(53351), UINT16_C(57196), UINT16_C(11333), UINT16_C(26888), UINT16_C(30957), UINT16_C(51860), UINT16_C(40886), UINT16_C(32159),
      UINT16_C(14074), UINT16_C(65196), UINT16_C( 7737), UINT16_C(65333), UINT16_C(39571), UINT16_C(11936), UINT16_C(16093), UINT16_C(10599),
      UINT16_C(47402), UINT16_C(17443), UINT16_C( 3323), UINT16_C(56786), UINT16_C(18052), UINT16_C(15293), UINT16_C(16886), UINT16_C(50643),
      UINT16_C(28557), UINT16_C(48095), UINT16_C(59806), UINT16_C( 8656), UINT16_C(22175), UINT16_C(20842), UINT16_C(42682), UINT16_C(50320),
      UINT16_C(39045), UINT16_C(26147), UINT16_C(54959), UINT16_C(10601), UINT16_C( 5916), UINT16_C(63359), UINT16_C(10099), UINT16_C(61907),
      UINT16_C(38833), UINT16_C(12215), UINT16_C(34966), UINT16_C( 9552), UINT16_C(43753), UINT16_C(37761), UINT16_C( 1644), UINT16_C(53592),
      UINT16_C(27573), UINT16_C(22866), UINT16_C(40001), UINT16_C(21416), UINT16_C(64707), UINT16_C( 5728), UINT16_C(10313), UINT16_C(56071),
      UINT16_C(46309), UINT16_C(27658), UINT16_C(20567), UINT16_C(12433), UINT16_C( 4869), UINT16_C(22227), UINT16_C( 4148), UINT16_C(55603),
      UINT16_C(27287), UINT16_C(51262), UINT16_C(52001), UINT16_C(50214), UINT16_C(31982), UINT16_C( 6107), UINT16_C(58042), UINT16_C(37106),
      UINT16_C(62129), UINT16_C(59644), UINT16_C(33384), UINT16_C(21032), UINT16_C(53680), UINT16_C(47823), UINT16_C(59399), UINT16_C(32414),
      UINT16_C(53623), UINT16_C(28247), UINT16_C(28083), UINT16_C(37181), UINT16_C( 3588), UINT16_C(44968), UINT16_C(37131), UINT16_C(39999),
      UINT16_C(15256), UINT16_C(61573), UINT16_C(37592), UINT16_C(26957), UINT16_C( 3193), UINT16_C(28974), UINT16_C(49678), UINT16_C(26351),
      UINT16_C(11193), UINT16_C(23775), UINT16_C( 7332), UINT16_C(39149), UINT16_C(35397), UINT16_C( 9559), UINT16_C(34352), UINT16_C(51404),
      UINT16_C(20929), UINT16_C(32712), UINT16_C(64511), UINT16_C(26867), UINT16_C( 8466), UINT16_C( 1769), UINT16_C(51693), UINT16_C(38519),
      UINT16_C(22271), UINT16_C(39170), UINT16_C(54402), UINT16_C(42812), UINT16_C(33653), UINT16_C(42455), UINT16_C(39194), UINT16_C(52078),
      UINT16_C( 7173), UINT16_C(58453), UINT16_C(18476), UINT16_C(13405), UINT16_C( 9833), UINT16_C(22352), UINT16_C(48383), UINT16_C(61421),
      UINT16_C(54573), UINT16_C(36754), UINT16_C(50127), UINT16_C(13367), UINT16_C( 3666), UINT16_C(20970), UINT16_C(18610), UINT16_C(43047),
      UINT16_C(32110), UINT16_C(37020), UINT16_C(55749), UINT16_C( 9450), UINT16_C(10752), UINT16_C(61318), UINT16_C(29681), UINT16_C( 1006),
      UINT16_C(29011), UINT16_C( 5021), UINT16_C(51535), UINT16_C(37191), UINT16_C( 8675), UINT16_C(35581), UINT16_C( 2681), UINT16_C(52557),
      UINT16_C(49058), UINT16_C(22387), UINT16_C(19875), UINT16_C(39062), UINT16_C(  391), UINT16_C(26771), UINT16_C(29056), UINT16_C(51334),
      UINT16_C( 5090), UINT16_C( 8934), UINT16_C(12008), UINT16_C(49347), UINT16_C(41295), UINT16_C(47456), UINT16_C(40630), UINT16_C(18577),
      UINT16_C( 1128), UINT16_C(  175), UINT16_C( 9809), UINT16_C(48575), UINT16_C(14146), UINT16_C(42816), UINT16_C(42675), UINT16_C(35734),
      UINT16_C(25033), UINT16_C(38600), UINT16_C(27546), UINT16_C(57212), UINT16_C(49692), UINT16_C(47027), UINT16_C(10619), UINT16_C(51226),
      UINT16_C(43576), UINT16_C(35294), UINT16_C(36304), UINT16_C(  593), UINT16_C(33231), UINT16_C(30917), UINT16_C(15143), UINT16_C(57369),
      UINT16_C(50871), UINT16_C(17026), UINT16_C(60988), UINT16_C(15932), UINT16_C(53179), UINT16_C( 9739), UINT16_C( 5635), UINT16_C(12553),
      UINT16_C(55488), UINT16_C(34260), UINT16_C( 2677), UINT16_C(13714), UINT16_C(15526), UINT16_C(45768), UINT16_C(50834), UINT16_C(10909),
      UINT16_C( 8098), UINT16_C(54140), UINT16_C(36126), UINT16_C(48695), UINT16_C(10359), UINT16_C(24576), UINT16_C(59721), UINT16_C(65205),
      UINT16_C(27073), UINT16_C(10137), UINT16_C( 8334), UINT16_C( 2412), UINT16_C( 2435), UINT16_C(62929), UINT16_C(25589), UINT16_C(31791),
      UINT16_C(32926), UINT16_C(40037), UINT16_C(33331), UINT16_C(32629), UINT16_C(21952), UINT16_C(65284), UINT16_C(36431), UINT16_C(   18),
      UINT16_C(40978), UINT16_C(30007), UINT16_C(30950), UINT16_C(16036), UINT16_C(23207), UINT16_C(29007), UINT16_C(24276), UINT16_C(25091),
      UINT16_C(24314), UINT16_C(  782), UINT16_C(22790), UINT16_C(43944), UINT16_C(33225), UINT16_C(60879), UINT16_C(50742), UINT16_C( 7688),
      UINT16_C( 5516), UINT16_C(21161), UINT16_C(15779), UINT16_C(15260), UINT16_C(53427), UINT16_C(27847), UINT16_C(47929), UINT16_C( 6377),
      UINT16_C(55076), UINT16_C( 6705), UINT16_C(48714), UINT16_C(62416), UINT16_C(33893), UINT16_C(31723), UINT16_C(55664), UINT16_C(56484),
      UINT16_C(19716), UINT16_C(42798), UINT16_C(51850), UINT16_C(11746), UINT16_C(36789), UINT16_C(54452), UINT16_C(29285), UINT16_C(30978),
      UINT16_C(10340), UINT16_C(36755), UINT16_C(25596), UINT16_C(18322), UINT16_C(28402), UINT16_C(21197), UINT16_C(26210), UINT16_C(22062),
      UINT16_C(23742), UINT16_C(18941), UINT16_C(57383), UINT16_C(52342), UINT16_C( 7034), UINT16_C(53163), UINT16_C(44696), UINT16_C(57944),
      UINT16_C(53489), UINT16_C(54156), UINT16_C(65086), UINT16_C(12336), UINT16_C(62076), UINT16_C(45970), UINT16_C(45167), UINT16_C( 8740),
      UINT16_C( 4620), UINT16_C(10374), UINT16_C(58114), UINT16_C(24848), UINT16_C(43784), UINT16_C(38219), UINT16_C(33625), UINT16_C(15245),
      UINT16_C( 2398), UINT16_C(37161), UINT16_C(18696), UINT16_C(29900), UINT16_C(17238), UINT16_C(46387), UINT16_C(18430), UINT16_C(65523),
      UINT16_C(22873), UINT16_C(16462), UINT16_C(13142), UINT16_C(20151), UINT16_C(59385), UINT16_C(17391), UINT16_C(29061), UINT16_C(54142),
      UINT16_C(38790), UINT16_C(33663), UINT16_C(15328), UINT16_C( 6930), UINT16_C(13705), UINT16_C(34780), UINT16_C(46221), UINT16_C(52130),
      UINT16_C(53272), UINT16_C(21554), UINT16_C(52766), UINT16_C(60605), UINT16_C(37340), UINT16_C(13898), UINT16_C(47129), UINT16_C(40725),
      UINT16_C(33871), UINT16_C( 9277) };

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
    rv = simde_svadd_n_u16_m(pv, av, b);

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

    ev = simde_svadd_n_u16_m(pv, av, b);

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
test_simde_svadd_n_u32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) };
  static const uint32_t a[] =
    { UINT32_C( 586132468), UINT32_C(2243686403), UINT32_C(4087901619), UINT32_C(3790866542), UINT32_C( 369707795), UINT32_C(3843797636), UINT32_C(4045968955), UINT32_C( 208339479),
      UINT32_C(2972605357), UINT32_C(4265011531), UINT32_C(3321028182), UINT32_C(4188464870), UINT32_C(3054481201), UINT32_C(2644192097), UINT32_C(3633234881), UINT32_C(1944386245),
      UINT32_C(2686718549), UINT32_C(1386109692), UINT32_C( 504860728), UINT32_C(2820128119), UINT32_C(3462276716), UINT32_C( 309066065), UINT32_C(2196502973), UINT32_C(1224069107),
      UINT32_C(3739752930), UINT32_C(2872084339), UINT32_C(2395555863), UINT32_C(1916264453), UINT32_C(1480627463), UINT32_C(1282124687), UINT32_C(2563659428), UINT32_C( 132170789),
      UINT32_C(1374013917), UINT32_C(1744574032), UINT32_C(1677117022), UINT32_C(2916429222), UINT32_C(1359353282), UINT32_C(1704817088), UINT32_C(3976031431), UINT32_C( 234151216),
      UINT32_C(4133411238), UINT32_C(1298029551), UINT32_C(3350287393), UINT32_C(1131775617), UINT32_C(1553300380), UINT32_C(3015783148), UINT32_C(3466575518), UINT32_C(1121751964),
      UINT32_C(1547254381), UINT32_C(3064633237), UINT32_C(1820220395), UINT32_C(2108683233), UINT32_C(1524253806), UINT32_C( 353213303), UINT32_C(4142181466), UINT32_C(2906177600),
      UINT32_C(2416538106), UINT32_C(4081496840), UINT32_C(4032807950), UINT32_C( 627904439), UINT32_C(3397338963), UINT32_C(1038126307), UINT32_C(2033435705), UINT32_C(2116447108),
      UINT32_C(3842912221), UINT32_C(4057552355), UINT32_C(3521198105), UINT32_C(2616610631), UINT32_C(2036692630), UINT32_C(1001800962), UINT32_C(2377443593), UINT32_C( 839703125),
      UINT32_C(3977714186), UINT32_C(2313089135), UINT32_C(1884995625), UINT32_C(2768982031), UINT32_C(3374281158), UINT32_C(3221542326), UINT32_C( 340638143), UINT32_C(2638633363),
      UINT32_C(3817495924), UINT32_C(2003593550), UINT32_C( 954713641), UINT32_C(3722310423), UINT32_C( 447151204), UINT32_C(2447027154), UINT32_C(4154796132), UINT32_C(4120243073),
      UINT32_C(2530811720), UINT32_C(2970437000), UINT32_C( 602535180), UINT32_C(1275119592), UINT32_C(2506532803), UINT32_C(3055960402), UINT32_C(3937258345), UINT32_C(4292887222),
      UINT32_C(3935680866), UINT32_C( 178037758), UINT32_C(2150466968), UINT32_C( 281816652), UINT32_C( 665137877), UINT32_C(3705523315), UINT32_C(1321699991), UINT32_C( 793618381),
      UINT32_C(1578754656), UINT32_C( 493467013), UINT32_C(2275251771), UINT32_C(2576837060), UINT32_C( 264256924), UINT32_C(2699861257), UINT32_C(4126061352), UINT32_C(3122936666),
      UINT32_C(2736274718), UINT32_C( 784433651), UINT32_C(3702873624), UINT32_C(1685474760), UINT32_C(2473801354), UINT32_C(4231225300), UINT32_C(1827742226), UINT32_C(2066093405),
      UINT32_C(1159675730), UINT32_C(3631472832), UINT32_C( 112535870), UINT32_C(   6957942), UINT32_C( 898883169), UINT32_C(1345439293), UINT32_C(1186734824), UINT32_C(2327962423),
      UINT32_C(3805274146), UINT32_C(4290462656), UINT32_C(3792007276), UINT32_C(4242698395), UINT32_C(2335339854), UINT32_C( 618357563), UINT32_C(3177879686), UINT32_C(2638687099),
      UINT32_C(3430881036), UINT32_C(3335207514), UINT32_C(1168691626), UINT32_C(2403502657), UINT32_C( 974812415), UINT32_C(1566504663), UINT32_C( 152815758), UINT32_C(  10904308),
      UINT32_C(3553371513), UINT32_C( 177838176), UINT32_C(2857386345), UINT32_C(3392770763), UINT32_C(3708113670), UINT32_C(3610993481), UINT32_C( 551573036), UINT32_C( 840992440),
      UINT32_C( 201714860), UINT32_C(3977682820), UINT32_C(2895603424), UINT32_C(4269199608), UINT32_C(1843165988), UINT32_C( 189077471), UINT32_C( 623584621), UINT32_C(1482116012),
      UINT32_C(3160694071), UINT32_C(3702094588), UINT32_C(3649585633), UINT32_C( 903413521), UINT32_C(1503900794), UINT32_C( 946137291), UINT32_C(3109916429), UINT32_C( 303150554),
      UINT32_C( 248411410), UINT32_C(3521804272), UINT32_C(3400168376), UINT32_C(3976168050), UINT32_C(  21406262), UINT32_C(2553916042), UINT32_C( 340891450), UINT32_C(1579574092),
      UINT32_C(3362583768), UINT32_C( 614028908), UINT32_C(1005470921), UINT32_C(4247318214), UINT32_C( 469659280), UINT32_C(1387477016), UINT32_C( 459736271), UINT32_C(1081707879),
      UINT32_C(3993560450), UINT32_C(  85107259), UINT32_C(2889875942), UINT32_C(2141808879), UINT32_C(4019890390), UINT32_C(2940292576), UINT32_C(3117066322), UINT32_C(3103343414),
      UINT32_C(1671823912), UINT32_C(2322118820), UINT32_C(2822154681), UINT32_C(3894992913) };
  static const uint32_t b = UINT32_C(1244504361);
  static const uint32_t e[] =
    { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 793334701), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(1214548596), UINT32_C(         0), UINT32_C(         0), UINT32_C(   4018266), UINT32_C(         0), UINT32_C( 582771946), UINT32_C(3188890606),
      UINT32_C(         0), UINT32_C(2630614053), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(1553570426), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(3640060224), UINT32_C(         0), UINT32_C(2725131824), UINT32_C(2526629048), UINT32_C(3808163789), UINT32_C(1376675150),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(2949321449), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(1082948303), UINT32_C(2542533912), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 416112583), UINT32_C(         0),
      UINT32_C(2791758742), UINT32_C(         0), UINT32_C(         0), UINT32_C(3353187594), UINT32_C(2768758167), UINT32_C(         0), UINT32_C(1091718531), UINT32_C(4150681961),
      UINT32_C(         0), UINT32_C(1031033905), UINT32_C(         0), UINT32_C(         0), UINT32_C( 346876028), UINT32_C(2282630668), UINT32_C(3277940066), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(1007089420), UINT32_C(         0), UINT32_C(3861114992), UINT32_C(         0), UINT32_C(         0), UINT32_C(3621947954), UINT32_C(         0),
      UINT32_C( 927251251), UINT32_C(         0), UINT32_C(         0), UINT32_C(4013486392), UINT32_C(         0), UINT32_C(         0), UINT32_C(1585142504), UINT32_C(         0),
      UINT32_C( 767032989), UINT32_C(3248097911), UINT32_C(2199218002), UINT32_C(         0), UINT32_C(1691655565), UINT32_C(3691531515), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(4214941361), UINT32_C(1847039541), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(1242424287),
      UINT32_C( 885217931), UINT32_C(         0), UINT32_C(3394971329), UINT32_C(1526321013), UINT32_C(1909642238), UINT32_C( 655060380), UINT32_C(2566204352), UINT32_C(         0),
      UINT32_C(2823259017), UINT32_C(1737971374), UINT32_C(3519756132), UINT32_C(3821341421), UINT32_C(1508761285), UINT32_C(         0), UINT32_C(         0), UINT32_C(  72473731),
      UINT32_C(         0), UINT32_C(2028938012), UINT32_C( 652410689), UINT32_C(         0), UINT32_C(         0), UINT32_C(1180762365), UINT32_C(3072246587), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(1357040231), UINT32_C(1251462303), UINT32_C(2143387530), UINT32_C(2589943654), UINT32_C(         0), UINT32_C(3572466784),
      UINT32_C(         0), UINT32_C(1239999721), UINT32_C(         0), UINT32_C(1192235460), UINT32_C(3579844215), UINT32_C(1862861924), UINT32_C( 127416751), UINT32_C(3883191460),
      UINT32_C(         0), UINT32_C( 284744579), UINT32_C(         0), UINT32_C(         0), UINT32_C(2219316776), UINT32_C(2811009024), UINT32_C(1397320119), UINT32_C(1255408669),
      UINT32_C(         0), UINT32_C(1422342537), UINT32_C(4101890706), UINT32_C(         0), UINT32_C( 657650735), UINT32_C(         0), UINT32_C(1796077397), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(1868088982), UINT32_C(         0),
      UINT32_C( 110231136), UINT32_C( 651631653), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(  59453494), UINT32_C(1547654915),
      UINT32_C(1492915771), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C( 312120833), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(1714163641), UINT32_C(2631981377), UINT32_C(1704240632), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 969427455), UINT32_C(4184796937), UINT32_C(  66603387), UINT32_C(         0),
      UINT32_C(2916328273), UINT32_C(3566623181), UINT32_C(4066659042), UINT32_C( 844529978) };

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
    rv = simde_svadd_n_u32_z(pv, av, b);

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

    ev = simde_svadd_n_u32_z(pv, av, b);

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
test_simde_svadd_n_u32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1


  static const int32_t p[] =
    {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) };
  static const uint32_t a[] =
    { UINT32_C(1971262628), UINT32_C(1354979719), UINT32_C(1561111420), UINT32_C(2419816243), UINT32_C(3099457050), UINT32_C(1974788622), UINT32_C(3494335759), UINT32_C( 739037832),
      UINT32_C(1856080871), UINT32_C(1623155940), UINT32_C(1136577296), UINT32_C(1574172995), UINT32_C(4246114799), UINT32_C(2205338227), UINT32_C(2807282207), UINT32_C(1943297932),
      UINT32_C(3470947818), UINT32_C(3928924634), UINT32_C(2939022444), UINT32_C(3557622245), UINT32_C(  97657746), UINT32_C( 210257133), UINT32_C(2343885822), UINT32_C( 620660794),
      UINT32_C(3623018749), UINT32_C(4005634433), UINT32_C(4087213837), UINT32_C(2194123504), UINT32_C(3129448909), UINT32_C(3704033502), UINT32_C( 644316139), UINT32_C(   4875779),
      UINT32_C(3369614662), UINT32_C(1807128926), UINT32_C(2019447688), UINT32_C(3422168830), UINT32_C(2642838207), UINT32_C(2105167250), UINT32_C(3416515016), UINT32_C(2395729479),
      UINT32_C(2304156459), UINT32_C(3321105469), UINT32_C(1564365663), UINT32_C( 942225529), UINT32_C(1289138106), UINT32_C(3301593340), UINT32_C(2039442737), UINT32_C(2248628827),
      UINT32_C( 990862846), UINT32_C(3355444329), UINT32_C(3492167255), UINT32_C( 822628215), UINT32_C(4202618622), UINT32_C(1623083054), UINT32_C( 299453877), UINT32_C(2778194087),
      UINT32_C(2799740733), UINT32_C(  40821163), UINT32_C(2530382879), UINT32_C(3788036835), UINT32_C(3889907385), UINT32_C(1128765838), UINT32_C(2387878118), UINT32_C(1026812928),
      UINT32_C(1055069331), UINT32_C( 339759861), UINT32_C(3400209126), UINT32_C(2779476972), UINT32_C(1200457657), UINT32_C( 126538784), UINT32_C(4120240117), UINT32_C(1580452043),
      UINT32_C(3516667612), UINT32_C(1340529768), UINT32_C(3659108846), UINT32_C(3179332612), UINT32_C(1812204875), UINT32_C(3597897441), UINT32_C( 952895597), UINT32_C(2912354256),
      UINT32_C(2122199573), UINT32_C(4241318926), UINT32_C(4191676149), UINT32_C(4139145130), UINT32_C(1164098148), UINT32_C(3055342921), UINT32_C(2918181085), UINT32_C(4233790951),
      UINT32_C(3329939896), UINT32_C( 868435773), UINT32_C(3626801709), UINT32_C(1439622129), UINT32_C(3868864669), UINT32_C(3801986565), UINT32_C(2240777374), UINT32_C(3380800017),
      UINT32_C(   9501891), UINT32_C(1899189060), UINT32_C(3729350893), UINT32_C(3761444675), UINT32_C(1288162631), UINT32_C( 573465732), UINT32_C(  27836144), UINT32_C(1808476840),
      UINT32_C(1785420582), UINT32_C(2614927278), UINT32_C(1115235839), UINT32_C(2216864829), UINT32_C(4258392441), UINT32_C(1025572685), UINT32_C(1698678973), UINT32_C( 416287474),
      UINT32_C( 327367781), UINT32_C(3668860891), UINT32_C(3239847812), UINT32_C(1279672019), UINT32_C(1967789864), UINT32_C(3568527894), UINT32_C( 607777330), UINT32_C(1631324924),
      UINT32_C( 561299270), UINT32_C(2751144478), UINT32_C( 476321609), UINT32_C(2104011349), UINT32_C(3639849665), UINT32_C(1319937564), UINT32_C(2490557848), UINT32_C( 905293807),
      UINT32_C(2371250542), UINT32_C(3559936395), UINT32_C(3203437672), UINT32_C(   3889215), UINT32_C( 668478987), UINT32_C(1819706580), UINT32_C(1493231722), UINT32_C( 110097815),
      UINT32_C(3918783838), UINT32_C(2680013623), UINT32_C(2522721623), UINT32_C( 295147782), UINT32_C(2620944327), UINT32_C(1577627380), UINT32_C( 783747479), UINT32_C(1563707134),
      UINT32_C(1665582892), UINT32_C(3791783050), UINT32_C(3078119601), UINT32_C(3234336761), UINT32_C(1935409535), UINT32_C(1188128175), UINT32_C(1819641966), UINT32_C(4224297423),
      UINT32_C(4217245809), UINT32_C(3319619604), UINT32_C(3111999168), UINT32_C(3833218405), UINT32_C(4132951622), UINT32_C(2839291963), UINT32_C(2148970929), UINT32_C(3430670171),
      UINT32_C(  63429103), UINT32_C(4207519033), UINT32_C(1622361851), UINT32_C(3527749003), UINT32_C(1070111748), UINT32_C(1994982597), UINT32_C( 301399990), UINT32_C(3470619102),
      UINT32_C(2211554378), UINT32_C(1149082185), UINT32_C(1822765536), UINT32_C(1648290398), UINT32_C(1268909702), UINT32_C(3233909514), UINT32_C(1758574474), UINT32_C(1916186152),
      UINT32_C(2633369683), UINT32_C(2212590498), UINT32_C(  66029220), UINT32_C(4133825904), UINT32_C(1027737395), UINT32_C( 486409106), UINT32_C(3817197499), UINT32_C(3512122238),
      UINT32_C(1718439107), UINT32_C(1693011647), UINT32_C(1147656404), UINT32_C( 943442949), UINT32_C(1718975956), UINT32_C( 998470528), UINT32_C(3240036419), UINT32_C(2274522563),
      UINT32_C(2163081153), UINT32_C( 585422414), UINT32_C(3009891246), UINT32_C(3974865432), UINT32_C(2672975903), UINT32_C( 400283092), UINT32_C(2715351773), UINT32_C( 807955055),
      UINT32_C(3081770345), UINT32_C(2581239275), UINT32_C(4165747168), UINT32_C(  48510947), UINT32_C(1805727639), UINT32_C(3934419980), UINT32_C(3851115126), UINT32_C( 773174212),
      UINT32_C(3018180296), UINT32_C( 994885467), UINT32_C(3811874816), UINT32_C(1726290127), UINT32_C(1557301071), UINT32_C(2051429379), UINT32_C(1935659439), UINT32_C(1285649796),
      UINT32_C(2533328699), UINT32_C(1204898630), UINT32_C(2989098467), UINT32_C(1830293534), UINT32_C(2596924055) };
  static const uint32_t b = UINT32_C(3145090041);
  static const uint32_t e[] =
    { UINT32_C(1971262628), UINT32_C(1354979719), UINT32_C(1561111420), UINT32_C(2419816243), UINT32_C(3099457050), UINT32_C(1974788622), UINT32_C(3494335759), UINT32_C(3884127873),
      UINT32_C( 706203616), UINT32_C( 473278685), UINT32_C(1136577296), UINT32_C( 424295740), UINT32_C(4246114799), UINT32_C(2205338227), UINT32_C(2807282207), UINT32_C(1943297932),
      UINT32_C(3470947818), UINT32_C(2779047379), UINT32_C(2939022444), UINT32_C(3557622245), UINT32_C(3242747787), UINT32_C( 210257133), UINT32_C(2343885822), UINT32_C( 620660794),
      UINT32_C(3623018749), UINT32_C(2855757178), UINT32_C(4087213837), UINT32_C(1044246249), UINT32_C(1979571654), UINT32_C(2554156247), UINT32_C(3789406180), UINT32_C(   4875779),
      UINT32_C(2219737407), UINT32_C( 657251671), UINT32_C( 869570433), UINT32_C(3422168830), UINT32_C(2642838207), UINT32_C(2105167250), UINT32_C(2266637761), UINT32_C(2395729479),
      UINT32_C(2304156459), UINT32_C(3321105469), UINT32_C(1564365663), UINT32_C(4087315570), UINT32_C( 139260851), UINT32_C(3301593340), UINT32_C( 889565482), UINT32_C(1098751572),
      UINT32_C( 990862846), UINT32_C(2205567074), UINT32_C(3492167255), UINT32_C(3967718256), UINT32_C(3052741367), UINT32_C( 473205799), UINT32_C( 299453877), UINT32_C(2778194087),
      UINT32_C(2799740733), UINT32_C(3185911204), UINT32_C(2530382879), UINT32_C(3788036835), UINT32_C(3889907385), UINT32_C(4273855879), UINT32_C(1238000863), UINT32_C(1026812928),
      UINT32_C(1055069331), UINT32_C( 339759861), UINT32_C(3400209126), UINT32_C(2779476972), UINT32_C(  50580402), UINT32_C( 126538784), UINT32_C(4120240117), UINT32_C( 430574788),
      UINT32_C(2366790357), UINT32_C(1340529768), UINT32_C(3659108846), UINT32_C(3179332612), UINT32_C( 662327620), UINT32_C(3597897441), UINT32_C(4097985638), UINT32_C(1762477001),
      UINT32_C(2122199573), UINT32_C(4241318926), UINT32_C(3041798894), UINT32_C(4139145130), UINT32_C(1164098148), UINT32_C(1905465666), UINT32_C(1768303830), UINT32_C(4233790951),
      UINT32_C(3329939896), UINT32_C(4013525814), UINT32_C(3626801709), UINT32_C( 289744874), UINT32_C(3868864669), UINT32_C(3801986565), UINT32_C(1090900119), UINT32_C(3380800017),
      UINT32_C(   9501891), UINT32_C(1899189060), UINT32_C(3729350893), UINT32_C(3761444675), UINT32_C(1288162631), UINT32_C(3718555773), UINT32_C(3172926185), UINT32_C( 658599585),
      UINT32_C(1785420582), UINT32_C(2614927278), UINT32_C(1115235839), UINT32_C(2216864829), UINT32_C(3108515186), UINT32_C(4170662726), UINT32_C(1698678973), UINT32_C( 416287474),
      UINT32_C( 327367781), UINT32_C(3668860891), UINT32_C(2089970557), UINT32_C( 129794764), UINT32_C(1967789864), UINT32_C(2418650639), UINT32_C( 607777330), UINT32_C(1631324924),
      UINT32_C( 561299270), UINT32_C(2751144478), UINT32_C(3621411650), UINT32_C(2104011349), UINT32_C(2489972410), UINT32_C(1319937564), UINT32_C(1340680593), UINT32_C(4050383848),
      UINT32_C(2371250542), UINT32_C(3559936395), UINT32_C(2053560417), UINT32_C(   3889215), UINT32_C( 668478987), UINT32_C(1819706580), UINT32_C(1493231722), UINT32_C( 110097815),
      UINT32_C(3918783838), UINT32_C(2680013623), UINT32_C(2522721623), UINT32_C( 295147782), UINT32_C(1471067072), UINT32_C(1577627380), UINT32_C( 783747479), UINT32_C(1563707134),
      UINT32_C( 515705637), UINT32_C(3791783050), UINT32_C(3078119601), UINT32_C(2084459506), UINT32_C(1935409535), UINT32_C(  38250920), UINT32_C(1819641966), UINT32_C(3074420168),
      UINT32_C(4217245809), UINT32_C(2169742349), UINT32_C(1962121913), UINT32_C(2683341150), UINT32_C(4132951622), UINT32_C(1689414708), UINT32_C(2148970929), UINT32_C(3430670171),
      UINT32_C(3208519144), UINT32_C(3057641778), UINT32_C(1622361851), UINT32_C(3527749003), UINT32_C(4215201789), UINT32_C( 845105342), UINT32_C(3446490031), UINT32_C(3470619102),
      UINT32_C(2211554378), UINT32_C(4294172226), UINT32_C(1822765536), UINT32_C(1648290398), UINT32_C(1268909702), UINT32_C(3233909514), UINT32_C( 608697219), UINT32_C(1916186152),
      UINT32_C(2633369683), UINT32_C(1062713243), UINT32_C(3211119261), UINT32_C(4133825904), UINT32_C(1027737395), UINT32_C( 486409106), UINT32_C(3817197499), UINT32_C(2362244983),
      UINT32_C( 568561852), UINT32_C( 543134392), UINT32_C(4292746445), UINT32_C(4088532990), UINT32_C(1718975956), UINT32_C( 998470528), UINT32_C(2090159164), UINT32_C(1124645308),
      UINT32_C(2163081153), UINT32_C( 585422414), UINT32_C(1860013991), UINT32_C(2824988177), UINT32_C(1523098648), UINT32_C(3545373133), UINT32_C(2715351773), UINT32_C( 807955055),
      UINT32_C(1931893090), UINT32_C(1431362020), UINT32_C(3015869913), UINT32_C(3193600988), UINT32_C(1805727639), UINT32_C(2784542725), UINT32_C(3851115126), UINT32_C(3918264253),
      UINT32_C(1868303041), UINT32_C( 994885467), UINT32_C(2661997561), UINT32_C(1726290127), UINT32_C(1557301071), UINT32_C( 901552124), UINT32_C( 785782184), UINT32_C( 135772541),
      UINT32_C(2533328699), UINT32_C(  55021375), UINT32_C(2989098467), UINT32_C( 680416279), UINT32_C(2596924055) };

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
    rv = simde_svadd_n_u32_m(pv, av, b);

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

    ev = simde_svadd_n_u32_m(pv, av, b);

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
test_simde_svadd_n_u64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1) };
  static const uint64_t a[] =
    { UINT64_C(10738340022827992081), UINT64_C( 6780065340013559460), UINT64_C( 6822115933512146782), UINT64_C(16105084255952540531),
      UINT64_C( 7599033572685088133), UINT64_C(16739495578312566894), UINT64_C( 5650741940179293377), UINT64_C( 8842597922407658762),
      UINT64_C( 9217689831668900029), UINT64_C(15648246287855220152), UINT64_C( 8411406246596768658), UINT64_C( 7491179060942107526),
      UINT64_C(15669100770860028388), UINT64_C( 3619280706160222794), UINT64_C(17876293744301383735), UINT64_C( 5323091368131977933),
      UINT64_C(16696727960102554044), UINT64_C( 5433174123268919444), UINT64_C( 3246534988810421668), UINT64_C(12255285172125401956),
      UINT64_C(10867815933549171021), UINT64_C( 4858593033044237069), UINT64_C(13889777848104344117), UINT64_C( 4144047143898408938),
      UINT64_C( 6090826330602211821), UINT64_C(13255469749425819922), UINT64_C(11482224893786606909), UINT64_C( 7897618846557135733),
      UINT64_C(14312127029311290627), UINT64_C( 3849851968133993524), UINT64_C( 4326596704008583608), UINT64_C( 9292956268926632715),
      UINT64_C( 7813015521100190963), UINT64_C(  552130000743228540), UINT64_C(12271041930836866888), UINT64_C( 1225027608139655170),
      UINT64_C(12620535534376831617), UINT64_C( 2333652782233634827), UINT64_C( 6381173330844571204), UINT64_C( 8111783302523241315),
      UINT64_C( 9044441306287917986), UINT64_C(13298629921910270103), UINT64_C(11294229866521345551), UINT64_C( 1030672771821966573),
      UINT64_C( 6695277893689505531), UINT64_C(  737563375781527823), UINT64_C(17288241458019555351), UINT64_C(12987002233580947905),
      UINT64_C(10786415249815838351), UINT64_C(17136853913049857228), UINT64_C( 3395760771781509422), UINT64_C(10710007440576670772),
      UINT64_C(11083248513741079221), UINT64_C( 7843919521359456279), UINT64_C( 8579845764868217204), UINT64_C(13349237763126619560),
      UINT64_C(16009948983018662855), UINT64_C( 3915500282138300332), UINT64_C( 6303397559618106047), UINT64_C(12418192069716467608),
      UINT64_C(13337249824555158130), UINT64_C( 5257663985022657277), UINT64_C(15128372049011740652), UINT64_C(12769328091351676837),
      UINT64_C(16344972501843605006), UINT64_C( 6824527328054442211), UINT64_C( 7760242872346542246), UINT64_C(17425037063265525731),
      UINT64_C(11630513866316561568), UINT64_C( 5056067527550765146), UINT64_C(17507136687709758403), UINT64_C(13100098393363180279),
      UINT64_C( 1585726369956551074), UINT64_C(10705071506798546601), UINT64_C( 9669530277094733360), UINT64_C(14827588486162367996),
      UINT64_C( 5393111826058510343), UINT64_C(17915922709289941821), UINT64_C(14911253243676377050), UINT64_C( 9558790694061953198),
      UINT64_C( 4652533988974908581), UINT64_C( 2565908611763938778), UINT64_C(16956188096851661743), UINT64_C( 8848847406662692811),
      UINT64_C( 1045769922908591168), UINT64_C( 8134429747006525815), UINT64_C(13206316535937921055), UINT64_C(13169032693272284017) };
  static const uint64_t b = UINT64_C( 2529300029554732753);
  static const uint64_t e[] =
    { UINT64_C(                   0), UINT64_C( 9309365369568292213), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(10128333602239820886), UINT64_C(  822051534157748031), UINT64_C( 8180041969734026130), UINT64_C(11371897951962391515),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(10940706276151501411), UINT64_C(10020479090496840279),
      UINT64_C(18198400800414761141), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(  779283915947735181), UINT64_C(                   0), UINT64_C( 5775835018365154421), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 7387893062598969822), UINT64_C(                   0), UINT64_C( 6673347173453141691),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(14011524923341339662), UINT64_C(10426918876111868486),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 6855896733563316361), UINT64_C(                   0),
      UINT64_C(10342315550654923716), UINT64_C( 3081430030297961293), UINT64_C(14800341960391599641), UINT64_C(                   0),
      UINT64_C(15149835563931564370), UINT64_C( 4862952811788367580), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(11573741335842650739), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C( 9224577923244238284), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(15516302263135680658),
      UINT64_C(13315715279370571104), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(13239307470131403525),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(11109145794422949957), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 8832697589172838800), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 7786964014577390030), UINT64_C(17657672078566473405), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C( 9353827357609174964), UINT64_C(                   0), UINT64_C( 1507593019110706868),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C( 1589692643554939540), UINT64_C(15629398422917913032),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(12198830306649466113), UINT64_C(17356888515717100749),
      UINT64_C( 7922411855613243096), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C( 7181834018529641334), UINT64_C(                   0), UINT64_C( 1038744052696842880), UINT64_C(11378147436217425564),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(15698332722827016770) };

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
    rv = simde_svadd_n_u64_z(pv, av, b);

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

    ev = simde_svadd_n_u64_z(pv, av, b);

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
test_simde_svadd_n_u64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0) };
  static const uint64_t a[] =
    { UINT64_C(13874573297778879213), UINT64_C(17357856934632602546), UINT64_C( 5105038458500431786), UINT64_C(  457788374144895382),
      UINT64_C(12319292178208560463), UINT64_C(17473992150327019941), UINT64_C( 8289708396955639894), UINT64_C(17572656127374672062),
      UINT64_C(14831233350427557170), UINT64_C( 8440833248369379305), UINT64_C(17532025397501837565), UINT64_C( 6925597442218627460),
      UINT64_C( 5754295637512898023), UINT64_C( 1439079393740732516), UINT64_C(17945503613814976995), UINT64_C( 7519672730810243021),
      UINT64_C(11977413656330036611), UINT64_C( 4517991528595568778), UINT64_C(12376562331144331603), UINT64_C(11898794038656427064),
      UINT64_C( 8417164937600604391), UINT64_C( 7860970592723597694), UINT64_C(  572512196772654440), UINT64_C( 9269501609090586588),
      UINT64_C( 8636067868207297146), UINT64_C( 2160154100230057330), UINT64_C(  336736605679333589), UINT64_C(14557504606474235372),
      UINT64_C(11116862077060165591), UINT64_C(15404318432399169525), UINT64_C( 7745388163576179537), UINT64_C(18207199131350433682),
      UINT64_C(15521959455578970790), UINT64_C(  179942438025138346), UINT64_C(12708868010303813747), UINT64_C(17120502456444407671),
      UINT64_C( 2437051545615623193), UINT64_C( 1110782289422013366), UINT64_C( 6129787076054541635), UINT64_C(18150502531131876528),
      UINT64_C( 8901022463672360941), UINT64_C(16124659751830311195), UINT64_C(15592958517353433138), UINT64_C(14903452270678988789),
      UINT64_C(12579319646793157202), UINT64_C(17547479633839354890), UINT64_C(  933485466924336627), UINT64_C(14370625176824234943),
      UINT64_C( 7188431483141267585), UINT64_C( 5015196145677838309), UINT64_C(14156313381633563731), UINT64_C(10544283600409614615),
      UINT64_C( 9812895690792514418), UINT64_C( 1740297958725662607), UINT64_C(17522652771915040611), UINT64_C(15345123349382598737),
      UINT64_C(10607048062547303175), UINT64_C(10224467657847235078), UINT64_C(12605612044586411554), UINT64_C( 5541403660733411505),
      UINT64_C( 6644545951349835680), UINT64_C( 7512861001715788685), UINT64_C(  755855256199706737), UINT64_C( 3699713222989680326),
      UINT64_C(  521869428264423308), UINT64_C(16385785883350951608), UINT64_C(16761886684377959226), UINT64_C( 5585391252233501629),
      UINT64_C( 2242069578516486811), UINT64_C( 1596671049978469332), UINT64_C(14364310221175315022), UINT64_C( 3607835852632771331),
      UINT64_C( 9402219347101303029), UINT64_C( 7652442716093585471), UINT64_C( 2926268991672081611), UINT64_C( 4991955757377041533),
      UINT64_C( 3633874878523936317), UINT64_C(17454685689308133046), UINT64_C(14243024455307040093), UINT64_C(15036710544056358168),
      UINT64_C( 2581172186773213102), UINT64_C(18337022303137964129), UINT64_C(13569954413946028357), UINT64_C(17951860810601212862),
      UINT64_C( 7543929630535376161), UINT64_C( 1958057406142391949), UINT64_C(10596119813089176491), UINT64_C( 2624196720227266854),
      UINT64_C(18325820274138875362), UINT64_C( 6412097473282327050), UINT64_C(14225663546119201796), UINT64_C( 3894946638807322598),
      UINT64_C( 3393024872914403494), UINT64_C(11509525659186643892), UINT64_C(18236450480387023536), UINT64_C(10646215865879907123),
      UINT64_C(  290976203935571636), UINT64_C(15366035799588346116), UINT64_C(14886430433765341058), UINT64_C( 2739335855596732036),
      UINT64_C( 8450452128538865649), UINT64_C( 5628466870648941602), UINT64_C(18407760320533119244), UINT64_C(14958271711075683070),
      UINT64_C(13909745267006084643), UINT64_C( 9087460798133444099), UINT64_C( 9575104186859980390), UINT64_C(16794638544566243685),
      UINT64_C( 9043938863486935841), UINT64_C( 1627324140607015588), UINT64_C(13437290301940546416), UINT64_C( 1862538582275485226),
      UINT64_C( 9379692756120262451), UINT64_C( 5957187957828450534), UINT64_C(12031861718390449129), UINT64_C( 4198039879199160112),
      UINT64_C( 6784132397075537094), UINT64_C(15546602855312179084), UINT64_C(18043126320586950724), UINT64_C( 3623256311164238854),
      UINT64_C(15012745256025600128), UINT64_C( 3494792128251186107), UINT64_C(12378801795956249862), UINT64_C(15199368717985770834) };
  static const uint64_t b = UINT64_C(10291061742275133587);
  static const uint64_t e[] =
    { UINT64_C(13874573297778879213), UINT64_C( 9202174603198184517), UINT64_C(15396100200775565373), UINT64_C(  457788374144895382),
      UINT64_C(12319292178208560463), UINT64_C( 9318309818892601912), UINT64_C( 8289708396955639894), UINT64_C( 9416973795940254033),
      UINT64_C(14831233350427557170), UINT64_C(  285150916934961276), UINT64_C( 9376343066067419536), UINT64_C(17216659184493761047),
      UINT64_C( 5754295637512898023), UINT64_C(11730141136015866103), UINT64_C(17945503613814976995), UINT64_C( 7519672730810243021),
      UINT64_C( 3821731324895618582), UINT64_C(14809053270870702365), UINT64_C(12376562331144331603), UINT64_C(11898794038656427064),
      UINT64_C( 8417164937600604391), UINT64_C( 7860970592723597694), UINT64_C(10863573939047788027), UINT64_C( 9269501609090586588),
      UINT64_C(  480385536772879117), UINT64_C(12451215842505190917), UINT64_C(10627798347954467176), UINT64_C(14557504606474235372),
      UINT64_C(11116862077060165591), UINT64_C(15404318432399169525), UINT64_C( 7745388163576179537), UINT64_C(18207199131350433682),
      UINT64_C(15521959455578970790), UINT64_C(  179942438025138346), UINT64_C(12708868010303813747), UINT64_C(17120502456444407671),
      UINT64_C( 2437051545615623193), UINT64_C(11401844031697146953), UINT64_C(16420848818329675222), UINT64_C( 9994820199697458499),
      UINT64_C( 8901022463672360941), UINT64_C(16124659751830311195), UINT64_C(15592958517353433138), UINT64_C(14903452270678988789),
      UINT64_C(12579319646793157202), UINT64_C(17547479633839354890), UINT64_C(11224547209199470214), UINT64_C( 6214942845389816914),
      UINT64_C(17479493225416401172), UINT64_C(15306257887952971896), UINT64_C( 6000631050199145702), UINT64_C(10544283600409614615),
      UINT64_C( 9812895690792514418), UINT64_C( 1740297958725662607), UINT64_C( 9366970440480622582), UINT64_C( 7189441017948180708),
      UINT64_C( 2451365731112885146), UINT64_C(10224467657847235078), UINT64_C( 4449929713151993525), UINT64_C( 5541403660733411505),
      UINT64_C(16935607693624969267), UINT64_C( 7512861001715788685), UINT64_C(  755855256199706737), UINT64_C(13990774965264813913),
      UINT64_C(10812931170539556895), UINT64_C( 8230103551916533579), UINT64_C(16761886684377959226), UINT64_C(15876452994508635216),
      UINT64_C( 2242069578516486811), UINT64_C( 1596671049978469332), UINT64_C( 6208627889740896993), UINT64_C( 3607835852632771331),
      UINT64_C( 1246537015666885000), UINT64_C(17943504458368719058), UINT64_C(13217330733947215198), UINT64_C( 4991955757377041533),
      UINT64_C( 3633874878523936317), UINT64_C(17454685689308133046), UINT64_C(14243024455307040093), UINT64_C( 6881028212621940139),
      UINT64_C(12872233929048346689), UINT64_C(18337022303137964129), UINT64_C( 5414272082511610328), UINT64_C(17951860810601212862),
      UINT64_C( 7543929630535376161), UINT64_C( 1958057406142391949), UINT64_C( 2440437481654758462), UINT64_C( 2624196720227266854),
      UINT64_C(10170137942704457333), UINT64_C(16703159215557460637), UINT64_C(14225663546119201796), UINT64_C(14186008381082456185),
      UINT64_C(13684086615189537081), UINT64_C(11509525659186643892), UINT64_C(18236450480387023536), UINT64_C( 2490533534445489094),
      UINT64_C(  290976203935571636), UINT64_C( 7210353468153928087), UINT64_C( 6730748102330923029), UINT64_C( 2739335855596732036),
      UINT64_C( 8450452128538865649), UINT64_C(15919528612924075189), UINT64_C(10252077989098701215), UINT64_C( 6802589379641265041),
      UINT64_C( 5754062935571666614), UINT64_C(  931778466699026070), UINT64_C( 9575104186859980390), UINT64_C(16794638544566243685),
      UINT64_C( 9043938863486935841), UINT64_C(11918385882882149175), UINT64_C(13437290301940546416), UINT64_C(12153600324550618813),
      UINT64_C( 9379692756120262451), UINT64_C(16248249700103584121), UINT64_C( 3876179386956031100), UINT64_C( 4198039879199160112),
      UINT64_C(17075194139350670681), UINT64_C(15546602855312179084), UINT64_C( 9887443989152532695), UINT64_C( 3623256311164238854),
      UINT64_C(15012745256025600128), UINT64_C(13785853870526319694), UINT64_C(12378801795956249862), UINT64_C(15199368717985770834) };

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
    rv = simde_svadd_n_u64_m(pv, av, b);

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

    ev = simde_svadd_n_u64_m(pv, av, b);

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
test_simde_svadd_n_f32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) };
  static const simde_float32 a[] =
    { SIMDE_FLOAT32_C(    22.40), SIMDE_FLOAT32_C(  -650.28), SIMDE_FLOAT32_C(  -629.80), SIMDE_FLOAT32_C(  -779.73),
      SIMDE_FLOAT32_C(  -816.53), SIMDE_FLOAT32_C(   479.41), SIMDE_FLOAT32_C(   530.90), SIMDE_FLOAT32_C(  -489.84),
      SIMDE_FLOAT32_C(  -596.91), SIMDE_FLOAT32_C(  -567.85), SIMDE_FLOAT32_C(    -2.49), SIMDE_FLOAT32_C(   623.58),
      SIMDE_FLOAT32_C(     5.37), SIMDE_FLOAT32_C(  -196.00), SIMDE_FLOAT32_C(   111.39), SIMDE_FLOAT32_C(    49.57),
      SIMDE_FLOAT32_C(  -871.65), SIMDE_FLOAT32_C(   396.44), SIMDE_FLOAT32_C(   129.00), SIMDE_FLOAT32_C(    54.68),
      SIMDE_FLOAT32_C(  -702.68), SIMDE_FLOAT32_C(  -764.69), SIMDE_FLOAT32_C(   938.92), SIMDE_FLOAT32_C(   736.37),
      SIMDE_FLOAT32_C(   -23.42), SIMDE_FLOAT32_C(  -845.78), SIMDE_FLOAT32_C(  -324.63), SIMDE_FLOAT32_C(   131.23),
      SIMDE_FLOAT32_C(   771.45), SIMDE_FLOAT32_C(   220.71), SIMDE_FLOAT32_C(  -575.48), SIMDE_FLOAT32_C(  -206.15),
      SIMDE_FLOAT32_C(   570.43), SIMDE_FLOAT32_C(  -205.28), SIMDE_FLOAT32_C(    14.12), SIMDE_FLOAT32_C(   753.90),
      SIMDE_FLOAT32_C(  -725.88), SIMDE_FLOAT32_C(  -454.97), SIMDE_FLOAT32_C(  -735.94), SIMDE_FLOAT32_C(  -322.78),
      SIMDE_FLOAT32_C(   -22.83), SIMDE_FLOAT32_C(   261.58), SIMDE_FLOAT32_C(  -699.21), SIMDE_FLOAT32_C(   982.55),
      SIMDE_FLOAT32_C(  -934.43), SIMDE_FLOAT32_C(   412.19), SIMDE_FLOAT32_C(    32.11), SIMDE_FLOAT32_C(  -806.08),
      SIMDE_FLOAT32_C(  -191.37), SIMDE_FLOAT32_C(  -838.89), SIMDE_FLOAT32_C(   248.60), SIMDE_FLOAT32_C(   105.95),
      SIMDE_FLOAT32_C(  -603.57), SIMDE_FLOAT32_C(   187.52), SIMDE_FLOAT32_C(  -157.68), SIMDE_FLOAT32_C(   373.01),
      SIMDE_FLOAT32_C(   341.75), SIMDE_FLOAT32_C(   517.69), SIMDE_FLOAT32_C(  -495.76), SIMDE_FLOAT32_C(   113.20),
      SIMDE_FLOAT32_C(  -261.60), SIMDE_FLOAT32_C(   -71.25), SIMDE_FLOAT32_C(   907.05), SIMDE_FLOAT32_C(  -691.17),
      SIMDE_FLOAT32_C(   723.47), SIMDE_FLOAT32_C(   -78.83), SIMDE_FLOAT32_C(  -937.26), SIMDE_FLOAT32_C(   997.59),
      SIMDE_FLOAT32_C(   466.20), SIMDE_FLOAT32_C(  -673.20), SIMDE_FLOAT32_C(  -325.19), SIMDE_FLOAT32_C(  -556.63),
      SIMDE_FLOAT32_C(   588.38), SIMDE_FLOAT32_C(   -24.40), SIMDE_FLOAT32_C(  -574.08), SIMDE_FLOAT32_C(   653.95),
      SIMDE_FLOAT32_C(  -612.22), SIMDE_FLOAT32_C(   458.03), SIMDE_FLOAT32_C(   847.87), SIMDE_FLOAT32_C(   196.41),
      SIMDE_FLOAT32_C(   619.14), SIMDE_FLOAT32_C(    96.47), SIMDE_FLOAT32_C(  -697.64), SIMDE_FLOAT32_C(  -984.43),
      SIMDE_FLOAT32_C(  -716.00), SIMDE_FLOAT32_C(   144.68), SIMDE_FLOAT32_C(   388.58), SIMDE_FLOAT32_C(   625.74),
      SIMDE_FLOAT32_C(  -337.63), SIMDE_FLOAT32_C(   892.81), SIMDE_FLOAT32_C(  -261.06), SIMDE_FLOAT32_C(   400.77),
      SIMDE_FLOAT32_C(  -178.44), SIMDE_FLOAT32_C(  -354.01), SIMDE_FLOAT32_C(   709.60), SIMDE_FLOAT32_C(  -454.97),
      SIMDE_FLOAT32_C(   567.16), SIMDE_FLOAT32_C(   772.34), SIMDE_FLOAT32_C(  -457.38), SIMDE_FLOAT32_C(    33.36),
      SIMDE_FLOAT32_C(  -900.86), SIMDE_FLOAT32_C(   217.43), SIMDE_FLOAT32_C(   476.73), SIMDE_FLOAT32_C(   687.51),
      SIMDE_FLOAT32_C(  -806.97), SIMDE_FLOAT32_C(   902.65), SIMDE_FLOAT32_C(   341.46), SIMDE_FLOAT32_C(  -419.19),
      SIMDE_FLOAT32_C(   360.68), SIMDE_FLOAT32_C(   189.33), SIMDE_FLOAT32_C(   777.22), SIMDE_FLOAT32_C(   -20.18),
      SIMDE_FLOAT32_C(  -714.19), SIMDE_FLOAT32_C(  -920.42), SIMDE_FLOAT32_C(    -4.61), SIMDE_FLOAT32_C(  -430.20),
      SIMDE_FLOAT32_C(   224.26), SIMDE_FLOAT32_C(  -616.03), SIMDE_FLOAT32_C(  -804.46), SIMDE_FLOAT32_C(   886.63),
      SIMDE_FLOAT32_C(  -723.22), SIMDE_FLOAT32_C(   -65.52), SIMDE_FLOAT32_C(   287.39), SIMDE_FLOAT32_C(    98.34),
      SIMDE_FLOAT32_C(   580.47), SIMDE_FLOAT32_C(    -3.01), SIMDE_FLOAT32_C(   643.37), SIMDE_FLOAT32_C(   147.63),
      SIMDE_FLOAT32_C(  -230.67), SIMDE_FLOAT32_C(  -814.00), SIMDE_FLOAT32_C(  -819.01), SIMDE_FLOAT32_C(  -131.54),
      SIMDE_FLOAT32_C(   403.43), SIMDE_FLOAT32_C(   657.72), SIMDE_FLOAT32_C(  -444.02), SIMDE_FLOAT32_C(   596.46),
      SIMDE_FLOAT32_C(   560.36), SIMDE_FLOAT32_C(   897.44), SIMDE_FLOAT32_C(  -822.73), SIMDE_FLOAT32_C(   -78.96),
      SIMDE_FLOAT32_C(    86.77), SIMDE_FLOAT32_C(   954.49), SIMDE_FLOAT32_C(   900.86), SIMDE_FLOAT32_C(   372.58),
      SIMDE_FLOAT32_C(  -965.92), SIMDE_FLOAT32_C(  -103.75), SIMDE_FLOAT32_C(   942.38), SIMDE_FLOAT32_C(   258.34),
      SIMDE_FLOAT32_C(   280.22), SIMDE_FLOAT32_C(  -862.08) };
  static const simde_float32 b = SIMDE_FLOAT32_C(   144.96);
  static const simde_float32 e[] =
    { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -484.84), SIMDE_FLOAT32_C(  -634.77),
      SIMDE_FLOAT32_C(  -671.57), SIMDE_FLOAT32_C(   624.37), SIMDE_FLOAT32_C(   675.86), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -451.95), SIMDE_FLOAT32_C(  -422.89), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   150.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   194.53),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   273.96), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   881.33),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -179.67), SIMDE_FLOAT32_C(   276.19),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   159.08), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -580.92), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -590.98), SIMDE_FLOAT32_C(  -177.82),
      SIMDE_FLOAT32_C(   122.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -554.25), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -789.47), SIMDE_FLOAT32_C(   557.15), SIMDE_FLOAT32_C(   177.07), SIMDE_FLOAT32_C(  -661.12),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   393.56), SIMDE_FLOAT32_C(   250.91),
      SIMDE_FLOAT32_C(  -458.61), SIMDE_FLOAT32_C(   332.48), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   517.97),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -350.80), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    73.71), SIMDE_FLOAT32_C(  1052.01), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(   611.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -411.67),
      SIMDE_FLOAT32_C(   733.34), SIMDE_FLOAT32_C(   120.56), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   992.83), SIMDE_FLOAT32_C(   341.37),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   241.43), SIMDE_FLOAT32_C(  -552.68), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -571.04), SIMDE_FLOAT32_C(   289.64), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   770.70),
      SIMDE_FLOAT32_C(  -192.67), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   545.73),
      SIMDE_FLOAT32_C(   -33.48), SIMDE_FLOAT32_C(  -209.05), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -310.01),
      SIMDE_FLOAT32_C(   712.12), SIMDE_FLOAT32_C(   917.30), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   178.32),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   362.39), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1047.61), SIMDE_FLOAT32_C(   486.42), SIMDE_FLOAT32_C(  -274.23),
      SIMDE_FLOAT32_C(   505.64), SIMDE_FLOAT32_C(   334.29), SIMDE_FLOAT32_C(   922.18), SIMDE_FLOAT32_C(   124.78),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -285.24),
      SIMDE_FLOAT32_C(   369.22), SIMDE_FLOAT32_C(  -471.07), SIMDE_FLOAT32_C(  -659.50), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   432.35), SIMDE_FLOAT32_C(   243.30),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   788.33), SIMDE_FLOAT32_C(   292.59),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -669.04), SIMDE_FLOAT32_C(  -674.05), SIMDE_FLOAT32_C(    13.42),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1099.45), SIMDE_FLOAT32_C(  1045.82), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -820.96), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   403.30),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -717.12) };

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
    rv = simde_svadd_n_f32_z(pv, av, b);

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

    ev = simde_svadd_n_f32_z(pv, av, b);

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
test_simde_svadd_n_f32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) };
  static const simde_float32 a[] =
    { SIMDE_FLOAT32_C(   794.89), SIMDE_FLOAT32_C(  -962.67), SIMDE_FLOAT32_C(  -950.01), SIMDE_FLOAT32_C(   497.52),
      SIMDE_FLOAT32_C(  -992.94), SIMDE_FLOAT32_C(   125.39), SIMDE_FLOAT32_C(  -116.49), SIMDE_FLOAT32_C(   718.28),
      SIMDE_FLOAT32_C(  -383.64), SIMDE_FLOAT32_C(  -362.50), SIMDE_FLOAT32_C(  -817.24), SIMDE_FLOAT32_C(  -615.61),
      SIMDE_FLOAT32_C(  -983.13), SIMDE_FLOAT32_C(   446.88), SIMDE_FLOAT32_C(  -562.02), SIMDE_FLOAT32_C(    78.78),
      SIMDE_FLOAT32_C(  -357.68), SIMDE_FLOAT32_C(   708.96), SIMDE_FLOAT32_C(  -635.94), SIMDE_FLOAT32_C(   354.73),
      SIMDE_FLOAT32_C(   -36.72), SIMDE_FLOAT32_C(   514.18), SIMDE_FLOAT32_C(  -777.98), SIMDE_FLOAT32_C(    93.03),
      SIMDE_FLOAT32_C(  -873.72), SIMDE_FLOAT32_C(   115.54), SIMDE_FLOAT32_C(  -132.06), SIMDE_FLOAT32_C(   149.47),
      SIMDE_FLOAT32_C(   774.90), SIMDE_FLOAT32_C(   568.38), SIMDE_FLOAT32_C(   -50.85), SIMDE_FLOAT32_C(   569.78),
      SIMDE_FLOAT32_C(   605.71), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(    67.30), SIMDE_FLOAT32_C(   612.77),
      SIMDE_FLOAT32_C(  -875.47), SIMDE_FLOAT32_C(   950.81), SIMDE_FLOAT32_C(   331.05), SIMDE_FLOAT32_C(  -259.11),
      SIMDE_FLOAT32_C(  -411.69), SIMDE_FLOAT32_C(   513.80), SIMDE_FLOAT32_C(   125.28), SIMDE_FLOAT32_C(  -394.82),
      SIMDE_FLOAT32_C(   -39.32), SIMDE_FLOAT32_C(   563.25), SIMDE_FLOAT32_C(   683.96), SIMDE_FLOAT32_C(   603.00),
      SIMDE_FLOAT32_C(   272.21), SIMDE_FLOAT32_C(  -951.98), SIMDE_FLOAT32_C(   -42.27), SIMDE_FLOAT32_C(  -764.51),
      SIMDE_FLOAT32_C(   562.21), SIMDE_FLOAT32_C(   179.75), SIMDE_FLOAT32_C(   328.52), SIMDE_FLOAT32_C(   688.48),
      SIMDE_FLOAT32_C(  -704.70), SIMDE_FLOAT32_C(  -803.54), SIMDE_FLOAT32_C(  -162.04), SIMDE_FLOAT32_C(  -929.80),
      SIMDE_FLOAT32_C(   764.84), SIMDE_FLOAT32_C(   787.11), SIMDE_FLOAT32_C(   639.98), SIMDE_FLOAT32_C(   370.55),
      SIMDE_FLOAT32_C(  -213.76), SIMDE_FLOAT32_C(  -292.72), SIMDE_FLOAT32_C(   -16.68), SIMDE_FLOAT32_C(   -89.23),
      SIMDE_FLOAT32_C(  -341.91), SIMDE_FLOAT32_C(  -685.63), SIMDE_FLOAT32_C(   651.66), SIMDE_FLOAT32_C(   246.40),
      SIMDE_FLOAT32_C(   828.17), SIMDE_FLOAT32_C(  -223.06), SIMDE_FLOAT32_C(   851.57), SIMDE_FLOAT32_C(  -211.15),
      SIMDE_FLOAT32_C(  -659.81), SIMDE_FLOAT32_C(   535.53), SIMDE_FLOAT32_C(  -608.15), SIMDE_FLOAT32_C(   612.40),
      SIMDE_FLOAT32_C(   583.55), SIMDE_FLOAT32_C(   349.59), SIMDE_FLOAT32_C(   847.88), SIMDE_FLOAT32_C(   145.76),
      SIMDE_FLOAT32_C(  -470.66), SIMDE_FLOAT32_C(   176.40), SIMDE_FLOAT32_C(  -165.76), SIMDE_FLOAT32_C(  -175.36),
      SIMDE_FLOAT32_C(   372.86), SIMDE_FLOAT32_C(   672.20), SIMDE_FLOAT32_C(  -105.16), SIMDE_FLOAT32_C(   137.70),
      SIMDE_FLOAT32_C(   459.31), SIMDE_FLOAT32_C(  -465.19), SIMDE_FLOAT32_C(  -491.75), SIMDE_FLOAT32_C(  -754.45),
      SIMDE_FLOAT32_C(   242.09), SIMDE_FLOAT32_C(   491.57), SIMDE_FLOAT32_C(   156.33), SIMDE_FLOAT32_C(   900.18),
      SIMDE_FLOAT32_C(   805.94), SIMDE_FLOAT32_C(  -192.01), SIMDE_FLOAT32_C(   146.57), SIMDE_FLOAT32_C(   634.11),
      SIMDE_FLOAT32_C(   584.92), SIMDE_FLOAT32_C(    -1.86), SIMDE_FLOAT32_C(  -577.03), SIMDE_FLOAT32_C(   925.11),
      SIMDE_FLOAT32_C(  -466.33), SIMDE_FLOAT32_C(  -185.18), SIMDE_FLOAT32_C(   537.51), SIMDE_FLOAT32_C(  -882.78),
      SIMDE_FLOAT32_C(  -835.59), SIMDE_FLOAT32_C(   385.39), SIMDE_FLOAT32_C(   262.98), SIMDE_FLOAT32_C(  -306.25),
      SIMDE_FLOAT32_C(  -438.21), SIMDE_FLOAT32_C(  -902.78), SIMDE_FLOAT32_C(   518.39), SIMDE_FLOAT32_C(   934.65),
      SIMDE_FLOAT32_C(   769.42), SIMDE_FLOAT32_C(  -586.78), SIMDE_FLOAT32_C(    72.35), SIMDE_FLOAT32_C(   228.73),
      SIMDE_FLOAT32_C(   -51.96), SIMDE_FLOAT32_C(   580.59), SIMDE_FLOAT32_C(   474.28), SIMDE_FLOAT32_C(  -809.87),
      SIMDE_FLOAT32_C(    72.16), SIMDE_FLOAT32_C(  -369.39), SIMDE_FLOAT32_C(  -909.70), SIMDE_FLOAT32_C(  -121.89),
      SIMDE_FLOAT32_C(   438.59), SIMDE_FLOAT32_C(   236.88), SIMDE_FLOAT32_C(  -487.78), SIMDE_FLOAT32_C(    23.51),
      SIMDE_FLOAT32_C(  -764.98), SIMDE_FLOAT32_C(   -64.81), SIMDE_FLOAT32_C(   -51.37), SIMDE_FLOAT32_C(  -231.31),
      SIMDE_FLOAT32_C(   750.01), SIMDE_FLOAT32_C(  -513.87), SIMDE_FLOAT32_C(  -114.08), SIMDE_FLOAT32_C(   914.41),
      SIMDE_FLOAT32_C(   871.53), SIMDE_FLOAT32_C(  -851.10), SIMDE_FLOAT32_C(  -391.84), SIMDE_FLOAT32_C(  -566.68),
      SIMDE_FLOAT32_C(  -753.88), SIMDE_FLOAT32_C(  -873.45), SIMDE_FLOAT32_C(  -632.03), SIMDE_FLOAT32_C(  -984.46),
      SIMDE_FLOAT32_C(  -460.23), SIMDE_FLOAT32_C(   440.32), SIMDE_FLOAT32_C(   244.27), SIMDE_FLOAT32_C(   487.81),
      SIMDE_FLOAT32_C(    20.91), SIMDE_FLOAT32_C(  -281.45), SIMDE_FLOAT32_C(   677.93), SIMDE_FLOAT32_C(  -906.93),
      SIMDE_FLOAT32_C(   349.15), SIMDE_FLOAT32_C(   768.24), SIMDE_FLOAT32_C(   -28.82), SIMDE_FLOAT32_C(  -212.26),
      SIMDE_FLOAT32_C(     5.11), SIMDE_FLOAT32_C(   483.40), SIMDE_FLOAT32_C(   811.26), SIMDE_FLOAT32_C(   240.13),
      SIMDE_FLOAT32_C(  -581.41), SIMDE_FLOAT32_C(  -240.12), SIMDE_FLOAT32_C(  -991.17), SIMDE_FLOAT32_C(  -831.40),
      SIMDE_FLOAT32_C(   246.02), SIMDE_FLOAT32_C(  -105.25), SIMDE_FLOAT32_C(  -916.99), SIMDE_FLOAT32_C(   117.55),
      SIMDE_FLOAT32_C(    43.64), SIMDE_FLOAT32_C(  -308.83), SIMDE_FLOAT32_C(   550.87), SIMDE_FLOAT32_C(   289.76),
      SIMDE_FLOAT32_C(  -182.29), SIMDE_FLOAT32_C(   918.84), SIMDE_FLOAT32_C(   305.30), SIMDE_FLOAT32_C(   357.48),
      SIMDE_FLOAT32_C(   359.15), SIMDE_FLOAT32_C(  -450.43), SIMDE_FLOAT32_C(  -154.71), SIMDE_FLOAT32_C(  -619.94) };
  static const simde_float32 b = SIMDE_FLOAT32_C(   268.11);
  static const simde_float32 e[] =
    { SIMDE_FLOAT32_C(  1063.00), SIMDE_FLOAT32_C(  -694.56), SIMDE_FLOAT32_C(  -681.90), SIMDE_FLOAT32_C(   497.52),
      SIMDE_FLOAT32_C(  -724.83), SIMDE_FLOAT32_C(   393.50), SIMDE_FLOAT32_C(   151.62), SIMDE_FLOAT32_C(   986.39),
      SIMDE_FLOAT32_C(  -115.53), SIMDE_FLOAT32_C(   -94.39), SIMDE_FLOAT32_C(  -549.13), SIMDE_FLOAT32_C(  -615.61),
      SIMDE_FLOAT32_C(  -715.02), SIMDE_FLOAT32_C(   446.88), SIMDE_FLOAT32_C(  -562.02), SIMDE_FLOAT32_C(    78.78),
      SIMDE_FLOAT32_C(  -357.68), SIMDE_FLOAT32_C(   977.07), SIMDE_FLOAT32_C(  -635.94), SIMDE_FLOAT32_C(   354.73),
      SIMDE_FLOAT32_C(   231.39), SIMDE_FLOAT32_C(   514.18), SIMDE_FLOAT32_C(  -777.98), SIMDE_FLOAT32_C(    93.03),
      SIMDE_FLOAT32_C(  -605.61), SIMDE_FLOAT32_C(   383.65), SIMDE_FLOAT32_C(   136.05), SIMDE_FLOAT32_C(   149.47),
      SIMDE_FLOAT32_C(   774.90), SIMDE_FLOAT32_C(   836.49), SIMDE_FLOAT32_C(   -50.85), SIMDE_FLOAT32_C(   837.89),
      SIMDE_FLOAT32_C(   605.71), SIMDE_FLOAT32_C(    -0.86), SIMDE_FLOAT32_C(   335.41), SIMDE_FLOAT32_C(   612.77),
      SIMDE_FLOAT32_C(  -607.36), SIMDE_FLOAT32_C(  1218.92), SIMDE_FLOAT32_C(   599.16), SIMDE_FLOAT32_C(  -259.11),
      SIMDE_FLOAT32_C(  -411.69), SIMDE_FLOAT32_C(   781.91), SIMDE_FLOAT32_C(   393.39), SIMDE_FLOAT32_C(  -126.71),
      SIMDE_FLOAT32_C(   -39.32), SIMDE_FLOAT32_C(   563.25), SIMDE_FLOAT32_C(   683.96), SIMDE_FLOAT32_C(   871.11),
      SIMDE_FLOAT32_C(   540.32), SIMDE_FLOAT32_C(  -683.87), SIMDE_FLOAT32_C(   -42.27), SIMDE_FLOAT32_C(  -496.40),
      SIMDE_FLOAT32_C(   830.32), SIMDE_FLOAT32_C(   447.86), SIMDE_FLOAT32_C(   596.63), SIMDE_FLOAT32_C(   688.48),
      SIMDE_FLOAT32_C(  -704.70), SIMDE_FLOAT32_C(  -803.54), SIMDE_FLOAT32_C(  -162.04), SIMDE_FLOAT32_C(  -929.80),
      SIMDE_FLOAT32_C(  1032.95), SIMDE_FLOAT32_C(  1055.22), SIMDE_FLOAT32_C(   908.09), SIMDE_FLOAT32_C(   638.66),
      SIMDE_FLOAT32_C(  -213.76), SIMDE_FLOAT32_C(  -292.72), SIMDE_FLOAT32_C(   251.43), SIMDE_FLOAT32_C(   -89.23),
      SIMDE_FLOAT32_C(   -73.80), SIMDE_FLOAT32_C(  -685.63), SIMDE_FLOAT32_C(   651.66), SIMDE_FLOAT32_C(   246.40),
      SIMDE_FLOAT32_C(  1096.28), SIMDE_FLOAT32_C(    45.05), SIMDE_FLOAT32_C(   851.57), SIMDE_FLOAT32_C(    56.96),
      SIMDE_FLOAT32_C(  -659.81), SIMDE_FLOAT32_C(   803.64), SIMDE_FLOAT32_C(  -608.15), SIMDE_FLOAT32_C(   612.40),
      SIMDE_FLOAT32_C(   851.66), SIMDE_FLOAT32_C(   349.59), SIMDE_FLOAT32_C(  1115.99), SIMDE_FLOAT32_C(   145.76),
      SIMDE_FLOAT32_C(  -470.66), SIMDE_FLOAT32_C(   176.40), SIMDE_FLOAT32_C(   102.35), SIMDE_FLOAT32_C(  -175.36),
      SIMDE_FLOAT32_C(   372.86), SIMDE_FLOAT32_C(   940.31), SIMDE_FLOAT32_C(  -105.16), SIMDE_FLOAT32_C(   405.81),
      SIMDE_FLOAT32_C(   727.42), SIMDE_FLOAT32_C(  -465.19), SIMDE_FLOAT32_C(  -223.64), SIMDE_FLOAT32_C(  -754.45),
      SIMDE_FLOAT32_C(   510.20), SIMDE_FLOAT32_C(   491.57), SIMDE_FLOAT32_C(   424.44), SIMDE_FLOAT32_C(   900.18),
      SIMDE_FLOAT32_C(  1074.05), SIMDE_FLOAT32_C(    76.10), SIMDE_FLOAT32_C(   146.57), SIMDE_FLOAT32_C(   634.11),
      SIMDE_FLOAT32_C(   853.03), SIMDE_FLOAT32_C(   266.25), SIMDE_FLOAT32_C(  -308.92), SIMDE_FLOAT32_C(  1193.22),
      SIMDE_FLOAT32_C(  -466.33), SIMDE_FLOAT32_C(  -185.18), SIMDE_FLOAT32_C(   805.62), SIMDE_FLOAT32_C(  -882.78),
      SIMDE_FLOAT32_C(  -567.48), SIMDE_FLOAT32_C(   653.50), SIMDE_FLOAT32_C(   262.98), SIMDE_FLOAT32_C(   -38.14),
      SIMDE_FLOAT32_C(  -438.21), SIMDE_FLOAT32_C(  -902.78), SIMDE_FLOAT32_C(   518.39), SIMDE_FLOAT32_C(   934.65),
      SIMDE_FLOAT32_C(  1037.53), SIMDE_FLOAT32_C(  -586.78), SIMDE_FLOAT32_C(    72.35), SIMDE_FLOAT32_C(   496.84),
      SIMDE_FLOAT32_C(   -51.96), SIMDE_FLOAT32_C(   848.70), SIMDE_FLOAT32_C(   742.39), SIMDE_FLOAT32_C(  -809.87),
      SIMDE_FLOAT32_C(   340.27), SIMDE_FLOAT32_C(  -369.39), SIMDE_FLOAT32_C(  -909.70), SIMDE_FLOAT32_C(   146.22),
      SIMDE_FLOAT32_C(   438.59), SIMDE_FLOAT32_C(   504.99), SIMDE_FLOAT32_C(  -219.67), SIMDE_FLOAT32_C(    23.51),
      SIMDE_FLOAT32_C(  -764.98), SIMDE_FLOAT32_C(   -64.81), SIMDE_FLOAT32_C(   216.74), SIMDE_FLOAT32_C(    36.80),
      SIMDE_FLOAT32_C(  1018.12), SIMDE_FLOAT32_C(  -513.87), SIMDE_FLOAT32_C(   154.03), SIMDE_FLOAT32_C(   914.41),
      SIMDE_FLOAT32_C(   871.53), SIMDE_FLOAT32_C(  -582.99), SIMDE_FLOAT32_C(  -123.73), SIMDE_FLOAT32_C(  -566.68),
      SIMDE_FLOAT32_C(  -753.88), SIMDE_FLOAT32_C(  -605.34), SIMDE_FLOAT32_C(  -632.03), SIMDE_FLOAT32_C(  -716.35),
      SIMDE_FLOAT32_C(  -460.23), SIMDE_FLOAT32_C(   708.43), SIMDE_FLOAT32_C(   244.27), SIMDE_FLOAT32_C(   487.81),
      SIMDE_FLOAT32_C(   289.02), SIMDE_FLOAT32_C(   -13.34), SIMDE_FLOAT32_C(   677.93), SIMDE_FLOAT32_C(  -906.93),
      SIMDE_FLOAT32_C(   349.15), SIMDE_FLOAT32_C(  1036.35), SIMDE_FLOAT32_C(   -28.82), SIMDE_FLOAT32_C(    55.85),
      SIMDE_FLOAT32_C(     5.11), SIMDE_FLOAT32_C(   483.40), SIMDE_FLOAT32_C(  1079.37), SIMDE_FLOAT32_C(   240.13),
      SIMDE_FLOAT32_C(  -313.30), SIMDE_FLOAT32_C(  -240.12), SIMDE_FLOAT32_C(  -991.17), SIMDE_FLOAT32_C(  -563.29),
      SIMDE_FLOAT32_C(   514.13), SIMDE_FLOAT32_C(   162.86), SIMDE_FLOAT32_C(  -916.99), SIMDE_FLOAT32_C(   385.66),
      SIMDE_FLOAT32_C(   311.75), SIMDE_FLOAT32_C(   -40.72), SIMDE_FLOAT32_C(   818.98), SIMDE_FLOAT32_C(   289.76),
      SIMDE_FLOAT32_C(  -182.29), SIMDE_FLOAT32_C(   918.84), SIMDE_FLOAT32_C(   305.30), SIMDE_FLOAT32_C(   357.48),
      SIMDE_FLOAT32_C(   359.15), SIMDE_FLOAT32_C(  -450.43), SIMDE_FLOAT32_C(   113.40), SIMDE_FLOAT32_C(  -619.94) };

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
    rv = simde_svadd_n_f32_m(pv, av, b);

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

    ev = simde_svadd_n_f32_m(pv, av, b);

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
test_simde_svadd_n_f64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1) };
  static const simde_float64 a[] =
    { SIMDE_FLOAT64_C(   530.20), SIMDE_FLOAT64_C(   909.18), SIMDE_FLOAT64_C(   110.70), SIMDE_FLOAT64_C(  -353.67),
      SIMDE_FLOAT64_C(  -963.42), SIMDE_FLOAT64_C(   465.68), SIMDE_FLOAT64_C(   790.66), SIMDE_FLOAT64_C(   969.70),
      SIMDE_FLOAT64_C(   981.06), SIMDE_FLOAT64_C(   264.73), SIMDE_FLOAT64_C(  -932.21), SIMDE_FLOAT64_C(    50.62),
      SIMDE_FLOAT64_C(   257.25), SIMDE_FLOAT64_C(  -884.42), SIMDE_FLOAT64_C(   447.89), SIMDE_FLOAT64_C(  -850.53),
      SIMDE_FLOAT64_C(  -132.51), SIMDE_FLOAT64_C(   909.82), SIMDE_FLOAT64_C(   281.05), SIMDE_FLOAT64_C(  -553.94),
      SIMDE_FLOAT64_C(  -806.12), SIMDE_FLOAT64_C(   969.99), SIMDE_FLOAT64_C(  -879.80), SIMDE_FLOAT64_C(   920.90),
      SIMDE_FLOAT64_C(  -550.94), SIMDE_FLOAT64_C(   875.87), SIMDE_FLOAT64_C(  -227.48), SIMDE_FLOAT64_C(    90.68),
      SIMDE_FLOAT64_C(   757.31), SIMDE_FLOAT64_C(  -358.48), SIMDE_FLOAT64_C(   706.99), SIMDE_FLOAT64_C(   287.51),
      SIMDE_FLOAT64_C(  -449.30), SIMDE_FLOAT64_C(  -182.31), SIMDE_FLOAT64_C(   933.84), SIMDE_FLOAT64_C(  -412.71),
      SIMDE_FLOAT64_C(  -716.63), SIMDE_FLOAT64_C(   724.50), SIMDE_FLOAT64_C(  -443.02), SIMDE_FLOAT64_C(  -735.57),
      SIMDE_FLOAT64_C(   -10.77), SIMDE_FLOAT64_C(  -375.23), SIMDE_FLOAT64_C(   315.05), SIMDE_FLOAT64_C(  -753.52),
      SIMDE_FLOAT64_C(  -259.64), SIMDE_FLOAT64_C(  -237.06), SIMDE_FLOAT64_C(  -604.06), SIMDE_FLOAT64_C(   607.84),
      SIMDE_FLOAT64_C(  -327.24), SIMDE_FLOAT64_C(   676.99), SIMDE_FLOAT64_C(  -946.10), SIMDE_FLOAT64_C(  -133.37),
      SIMDE_FLOAT64_C(   646.98), SIMDE_FLOAT64_C(  -825.90), SIMDE_FLOAT64_C(  -212.47), SIMDE_FLOAT64_C(  -903.96),
      SIMDE_FLOAT64_C(  -950.04), SIMDE_FLOAT64_C(   560.06), SIMDE_FLOAT64_C(   186.72), SIMDE_FLOAT64_C(   807.27),
      SIMDE_FLOAT64_C(  -798.43), SIMDE_FLOAT64_C(  -106.29), SIMDE_FLOAT64_C(    94.78), SIMDE_FLOAT64_C(  -247.72),
      SIMDE_FLOAT64_C(   711.40), SIMDE_FLOAT64_C(    28.62), SIMDE_FLOAT64_C(   339.56), SIMDE_FLOAT64_C(   994.77),
      SIMDE_FLOAT64_C(  -246.88), SIMDE_FLOAT64_C(   896.55), SIMDE_FLOAT64_C(  -740.80), SIMDE_FLOAT64_C(   742.35),
      SIMDE_FLOAT64_C(  -478.68), SIMDE_FLOAT64_C(   574.24), SIMDE_FLOAT64_C(   988.82), SIMDE_FLOAT64_C(   261.68),
      SIMDE_FLOAT64_C(  -662.82), SIMDE_FLOAT64_C(  -615.23), SIMDE_FLOAT64_C(  -130.48), SIMDE_FLOAT64_C(     9.94),
      SIMDE_FLOAT64_C(  -938.25), SIMDE_FLOAT64_C(   -76.58), SIMDE_FLOAT64_C(   876.58), SIMDE_FLOAT64_C(   708.73),
      SIMDE_FLOAT64_C(    97.51), SIMDE_FLOAT64_C(  -335.89), SIMDE_FLOAT64_C(   804.77), SIMDE_FLOAT64_C(   147.48),
      SIMDE_FLOAT64_C(  -775.83), SIMDE_FLOAT64_C(    -8.51), SIMDE_FLOAT64_C(   -45.25), SIMDE_FLOAT64_C(  -574.26),
      SIMDE_FLOAT64_C(   885.20), SIMDE_FLOAT64_C(  -950.47), SIMDE_FLOAT64_C(   178.02), SIMDE_FLOAT64_C(   596.60),
      SIMDE_FLOAT64_C(    78.15), SIMDE_FLOAT64_C(  -482.42), SIMDE_FLOAT64_C(   591.37), SIMDE_FLOAT64_C(   831.27),
      SIMDE_FLOAT64_C(  -585.87), SIMDE_FLOAT64_C(   850.56), SIMDE_FLOAT64_C(   573.61), SIMDE_FLOAT64_C(   -64.55),
      SIMDE_FLOAT64_C(   424.81), SIMDE_FLOAT64_C(   562.44), SIMDE_FLOAT64_C(  -802.87), SIMDE_FLOAT64_C(   761.99) };
  static const simde_float64 b = SIMDE_FLOAT64_C(   947.20);
  static const simde_float64 e[] =
    { SIMDE_FLOAT64_C(  1477.40), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1057.90), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   -16.22), SIMDE_FLOAT64_C(  1412.88), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1916.90),
      SIMDE_FLOAT64_C(  1928.26), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  1204.45), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1857.02), SIMDE_FLOAT64_C(  1228.25), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   141.08), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   396.26), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   719.72), SIMDE_FLOAT64_C(  1037.88),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1654.19), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   497.90), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1881.04), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   230.57), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   571.97), SIMDE_FLOAT64_C(  1262.25), SIMDE_FLOAT64_C(   193.68),
      SIMDE_FLOAT64_C(   687.56), SIMDE_FLOAT64_C(   710.14), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   619.96), SIMDE_FLOAT64_C(  1624.19), SIMDE_FLOAT64_C(     1.10), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  1594.18), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   734.73), SIMDE_FLOAT64_C(    43.24),
      SIMDE_FLOAT64_C(    -2.84), SIMDE_FLOAT64_C(  1507.26), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1754.47),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   840.91), SIMDE_FLOAT64_C(  1041.98), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  1658.60), SIMDE_FLOAT64_C(   975.82), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(   700.32), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1689.55),
      SIMDE_FLOAT64_C(   468.52), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   816.72), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   870.62), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  1044.71), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1094.68),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   372.94),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -3.27), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1543.80),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1538.57), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  1520.81), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  1372.01), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   144.33), SIMDE_FLOAT64_C(  1709.19) };

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
    rv = simde_svadd_n_f64_z(pv, av, b);

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

    ev = simde_svadd_n_f64_z(pv, av, b);

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
test_simde_svadd_n_f64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1) };
  static const simde_float64 a[] =
    { SIMDE_FLOAT64_C(  -472.33), SIMDE_FLOAT64_C(  -730.51), SIMDE_FLOAT64_C(   672.00), SIMDE_FLOAT64_C(   364.85),
      SIMDE_FLOAT64_C(  -246.69), SIMDE_FLOAT64_C(  -256.46), SIMDE_FLOAT64_C(   778.81), SIMDE_FLOAT64_C(  -675.92),
      SIMDE_FLOAT64_C(   541.43), SIMDE_FLOAT64_C(   724.84), SIMDE_FLOAT64_C(   301.02), SIMDE_FLOAT64_C(   620.68),
      SIMDE_FLOAT64_C(   116.77), SIMDE_FLOAT64_C(  -947.06), SIMDE_FLOAT64_C(  -585.06), SIMDE_FLOAT64_C(   653.72),
      SIMDE_FLOAT64_C(    38.87), SIMDE_FLOAT64_C(   856.61), SIMDE_FLOAT64_C(   172.82), SIMDE_FLOAT64_C(   815.04),
      SIMDE_FLOAT64_C(  -546.82), SIMDE_FLOAT64_C(  -495.48), SIMDE_FLOAT64_C(   118.21), SIMDE_FLOAT64_C(   990.18),
      SIMDE_FLOAT64_C(   656.25), SIMDE_FLOAT64_C(  -811.95), SIMDE_FLOAT64_C(  -327.54), SIMDE_FLOAT64_C(   706.62),
      SIMDE_FLOAT64_C(   657.61), SIMDE_FLOAT64_C(  -415.78), SIMDE_FLOAT64_C(   259.81), SIMDE_FLOAT64_C(  -814.73),
      SIMDE_FLOAT64_C(  -146.29), SIMDE_FLOAT64_C(   -68.19), SIMDE_FLOAT64_C(   550.13), SIMDE_FLOAT64_C(   607.02),
      SIMDE_FLOAT64_C(   675.35), SIMDE_FLOAT64_C(   328.93), SIMDE_FLOAT64_C(   931.10), SIMDE_FLOAT64_C(   216.78),
      SIMDE_FLOAT64_C(    53.77), SIMDE_FLOAT64_C(   232.12), SIMDE_FLOAT64_C(  -162.54), SIMDE_FLOAT64_C(  -829.46),
      SIMDE_FLOAT64_C(   285.06), SIMDE_FLOAT64_C(   252.39), SIMDE_FLOAT64_C(   824.26), SIMDE_FLOAT64_C(  -676.07),
      SIMDE_FLOAT64_C(   109.00), SIMDE_FLOAT64_C(    -2.92), SIMDE_FLOAT64_C(  -861.03), SIMDE_FLOAT64_C(   562.19),
      SIMDE_FLOAT64_C(   501.60), SIMDE_FLOAT64_C(   257.18), SIMDE_FLOAT64_C(   552.37), SIMDE_FLOAT64_C(   157.85),
      SIMDE_FLOAT64_C(   445.23), SIMDE_FLOAT64_C(  -775.17), SIMDE_FLOAT64_C(  -135.54), SIMDE_FLOAT64_C(   102.84),
      SIMDE_FLOAT64_C(  -190.95), SIMDE_FLOAT64_C(  -875.73), SIMDE_FLOAT64_C(   288.11), SIMDE_FLOAT64_C(   662.76),
      SIMDE_FLOAT64_C(    56.08), SIMDE_FLOAT64_C(  -161.77), SIMDE_FLOAT64_C(   269.79), SIMDE_FLOAT64_C(  -268.57),
      SIMDE_FLOAT64_C(  -832.84), SIMDE_FLOAT64_C(   200.88), SIMDE_FLOAT64_C(   948.20), SIMDE_FLOAT64_C(   220.93),
      SIMDE_FLOAT64_C(  -567.00), SIMDE_FLOAT64_C(  -214.34), SIMDE_FLOAT64_C(   391.47), SIMDE_FLOAT64_C(   718.06),
      SIMDE_FLOAT64_C(  -961.95), SIMDE_FLOAT64_C(   215.73), SIMDE_FLOAT64_C(  -958.01), SIMDE_FLOAT64_C(   147.06),
      SIMDE_FLOAT64_C(  -787.19), SIMDE_FLOAT64_C(  -819.03), SIMDE_FLOAT64_C(  -290.76), SIMDE_FLOAT64_C(   714.41),
      SIMDE_FLOAT64_C(   438.15), SIMDE_FLOAT64_C(  -738.39), SIMDE_FLOAT64_C(  -127.74), SIMDE_FLOAT64_C(  -116.62),
      SIMDE_FLOAT64_C(  -513.57), SIMDE_FLOAT64_C(   736.72), SIMDE_FLOAT64_C(   986.22), SIMDE_FLOAT64_C(   295.48),
      SIMDE_FLOAT64_C(   860.99), SIMDE_FLOAT64_C(   274.33), SIMDE_FLOAT64_C(   -41.75), SIMDE_FLOAT64_C(   -82.93),
      SIMDE_FLOAT64_C(  -887.44), SIMDE_FLOAT64_C(  -771.97) };
  static const simde_float64 b = SIMDE_FLOAT64_C(   648.49);
  static const simde_float64 e[] =
    { SIMDE_FLOAT64_C(  -472.33), SIMDE_FLOAT64_C(   -82.02), SIMDE_FLOAT64_C(  1320.49), SIMDE_FLOAT64_C(   364.85),
      SIMDE_FLOAT64_C(  -246.69), SIMDE_FLOAT64_C(   392.03), SIMDE_FLOAT64_C(   778.81), SIMDE_FLOAT64_C(  -675.92),
      SIMDE_FLOAT64_C(  1189.92), SIMDE_FLOAT64_C(   724.84), SIMDE_FLOAT64_C(   949.51), SIMDE_FLOAT64_C(  1269.17),
      SIMDE_FLOAT64_C(   116.77), SIMDE_FLOAT64_C(  -947.06), SIMDE_FLOAT64_C(  -585.06), SIMDE_FLOAT64_C(  1302.21),
      SIMDE_FLOAT64_C(    38.87), SIMDE_FLOAT64_C(   856.61), SIMDE_FLOAT64_C(   821.31), SIMDE_FLOAT64_C(  1463.53),
      SIMDE_FLOAT64_C(  -546.82), SIMDE_FLOAT64_C(   153.01), SIMDE_FLOAT64_C(   766.70), SIMDE_FLOAT64_C(  1638.67),
      SIMDE_FLOAT64_C(   656.25), SIMDE_FLOAT64_C(  -811.95), SIMDE_FLOAT64_C(  -327.54), SIMDE_FLOAT64_C(  1355.11),
      SIMDE_FLOAT64_C(  1306.10), SIMDE_FLOAT64_C(   232.71), SIMDE_FLOAT64_C(   259.81), SIMDE_FLOAT64_C(  -166.24),
      SIMDE_FLOAT64_C(  -146.29), SIMDE_FLOAT64_C(   580.30), SIMDE_FLOAT64_C(   550.13), SIMDE_FLOAT64_C(   607.02),
      SIMDE_FLOAT64_C(  1323.84), SIMDE_FLOAT64_C(   977.42), SIMDE_FLOAT64_C(  1579.59), SIMDE_FLOAT64_C(   865.27),
      SIMDE_FLOAT64_C(   702.26), SIMDE_FLOAT64_C(   880.61), SIMDE_FLOAT64_C(   485.95), SIMDE_FLOAT64_C(  -829.46),
      SIMDE_FLOAT64_C(   285.06), SIMDE_FLOAT64_C(   900.88), SIMDE_FLOAT64_C(  1472.75), SIMDE_FLOAT64_C(  -676.07),
      SIMDE_FLOAT64_C(   109.00), SIMDE_FLOAT64_C(    -2.92), SIMDE_FLOAT64_C(  -212.54), SIMDE_FLOAT64_C(  1210.68),
      SIMDE_FLOAT64_C(  1150.09), SIMDE_FLOAT64_C(   905.67), SIMDE_FLOAT64_C(   552.37), SIMDE_FLOAT64_C(   806.34),
      SIMDE_FLOAT64_C(  1093.72), SIMDE_FLOAT64_C(  -775.17), SIMDE_FLOAT64_C(   512.95), SIMDE_FLOAT64_C(   102.84),
      SIMDE_FLOAT64_C(   457.54), SIMDE_FLOAT64_C(  -227.24), SIMDE_FLOAT64_C(   288.11), SIMDE_FLOAT64_C(   662.76),
      SIMDE_FLOAT64_C(    56.08), SIMDE_FLOAT64_C(  -161.77), SIMDE_FLOAT64_C(   918.28), SIMDE_FLOAT64_C(   379.92),
      SIMDE_FLOAT64_C(  -184.35), SIMDE_FLOAT64_C(   849.37), SIMDE_FLOAT64_C(  1596.69), SIMDE_FLOAT64_C(   869.42),
      SIMDE_FLOAT64_C(    81.49), SIMDE_FLOAT64_C(   434.15), SIMDE_FLOAT64_C(  1039.96), SIMDE_FLOAT64_C(   718.06),
      SIMDE_FLOAT64_C(  -313.46), SIMDE_FLOAT64_C(   215.73), SIMDE_FLOAT64_C(  -309.52), SIMDE_FLOAT64_C(   147.06),
      SIMDE_FLOAT64_C(  -787.19), SIMDE_FLOAT64_C(  -170.54), SIMDE_FLOAT64_C(  -290.76), SIMDE_FLOAT64_C(  1362.90),
      SIMDE_FLOAT64_C(   438.15), SIMDE_FLOAT64_C(  -738.39), SIMDE_FLOAT64_C(   520.75), SIMDE_FLOAT64_C(  -116.62),
      SIMDE_FLOAT64_C(  -513.57), SIMDE_FLOAT64_C(  1385.21), SIMDE_FLOAT64_C(  1634.71), SIMDE_FLOAT64_C(   943.97),
      SIMDE_FLOAT64_C(   860.99), SIMDE_FLOAT64_C(   922.82), SIMDE_FLOAT64_C(   -41.75), SIMDE_FLOAT64_C(   -82.93),
      SIMDE_FLOAT64_C(  -887.44), SIMDE_FLOAT64_C(  -123.48) };

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
    rv = simde_svadd_n_f64_m(pv, av, b);

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

    ev = simde_svadd_n_f64_m(pv, av, b);

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
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_s8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_s8_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_s16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_s16_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_s32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_s32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_s64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_s64_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_u8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_u8_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_u16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_u16_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_u32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_u32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_u64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_u64_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_f32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_f32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_f64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_f64_m)

SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_s8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_s8_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_s16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_s16_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_s32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_s32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_s64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_s64_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_u8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_u8_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_u16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_u16_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_u32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_u32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_u64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_u64_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_f32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_f32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_f64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svadd_n_f64_m)
SIMDE_TEST_FUNC_LIST_END

#include "test-sve-footer.h"
