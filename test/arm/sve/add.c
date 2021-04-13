#define SIMDE_TEST_ARM_SVE_INSN add

#include "test-sve.h"
#include "../../../simde/arm/sve/add.h"

#include "../../../simde/arm/sve/cmplt.h"
#include "../../../simde/arm/sve/dup_n.h"

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
  int32_t len = simde_test_codegen_random_i16() & ((1024 / sizeof(int8_t)) - 1);

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
  int32_t len = simde_test_codegen_random_i16() & ((1024 / sizeof(int8_t)) - 1);

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
  int32_t len = simde_test_codegen_random_i16() & ((1024 / sizeof(int16_t)) - 1);

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
  int32_t len = simde_test_codegen_random_i16() & ((1024 / sizeof(int16_t)) - 1);

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
  int32_t len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) - 1);

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
  int32_t len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) - 1);

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
  int32_t len = simde_test_codegen_random_i64() & ((1024 / sizeof(int64_t)) - 1);

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
  int32_t len = simde_test_codegen_random_i64() & ((1024 / sizeof(int64_t)) - 1);

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
  int32_t len = simde_test_codegen_random_i16() & ((1024 / sizeof(int8_t)) - 1);

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
  int32_t len = simde_test_codegen_random_i16() & ((1024 / sizeof(int8_t)) - 1);

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
  int32_t len = simde_test_codegen_random_i16() & ((1024 / sizeof(int16_t)) - 1);

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
  int32_t len = simde_test_codegen_random_i16() & ((1024 / sizeof(int16_t)) - 1);

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
  int32_t len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) - 1);

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
  int32_t len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) - 1);

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
  int32_t len = simde_test_codegen_random_i64() & ((1024 / sizeof(int64_t)) - 1);

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
  int32_t len = simde_test_codegen_random_i64() & ((1024 / sizeof(int64_t)) - 1);

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
  int32_t len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) - 1);

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf32(len, a, SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  simde_test_codegen_random_vf32(len, b, SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));

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
  int32_t len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) - 1);

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf32(len, a, SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  simde_test_codegen_random_vf32(len, b, SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));

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
  int32_t len = simde_test_codegen_random_i64() & ((1024 / sizeof(int64_t)) - 1);

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf64(len, a, SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  simde_test_codegen_random_vf64(len, b, SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));

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
  int32_t len = simde_test_codegen_random_i64() & ((1024 / sizeof(int64_t)) - 1);

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf64(len, a, SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  simde_test_codegen_random_vf64(len, b, SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));

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
SIMDE_TEST_FUNC_LIST_END

#include "test-sve-footer.h"
