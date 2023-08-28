/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 */

#if !defined(SIMDE_ARM_NEON_H)
#define SIMDE_ARM_NEON_H

#include "neon/types.h"

#include "neon/aba.h"
#include "neon/abal.h"
#include "neon/abal_high.h"
#include "neon/abd.h"
#include "neon/abdl.h"
#include "neon/abdl_high.h"
#include "neon/abs.h"
#include "neon/add.h"
#include "neon/addhn.h"
#include "neon/addhn_high.h"
#include "neon/addl.h"
#include "neon/addlv.h"
#include "neon/addl_high.h"
#include "neon/addv.h"
#include "neon/addw.h"
#include "neon/addw_high.h"
#include "neon/and.h"
#include "neon/bcax.h"
#include "neon/bic.h"
#include "neon/bsl.h"
#include "neon/cadd_rot270.h"
#include "neon/cadd_rot90.h"
#include "neon/cage.h"
#include "neon/cagt.h"
#include "neon/cale.h"
#include "neon/calt.h"
#include "neon/ceq.h"
#include "neon/ceqz.h"
#include "neon/cge.h"
#include "neon/cgez.h"
#include "neon/cgt.h"
#include "neon/cgtz.h"
#include "neon/cle.h"
#include "neon/clez.h"
#include "neon/cls.h"
#include "neon/clt.h"
#include "neon/cltz.h"
#include "neon/clz.h"
#include "neon/cmla.h"
#include "neon/cmla_lane.h"
#include "neon/cmla_rot180_lane.h"
#include "neon/cmla_rot270_lane.h"
#include "neon/cmla_rot90_lane.h"
#include "neon/cmla_rot90.h"
#include "neon/cmla_rot180.h"
#include "neon/cmla_rot270.h"
#include "neon/cnt.h"
#include "neon/cvt.h"
#include "neon/cvt_n.h"
#include "neon/cvtm.h"
#include "neon/cvtn.h"
#include "neon/cvtp.h"
#include "neon/combine.h"
#include "neon/copy_lane.h"
#include "neon/create.h"
#include "neon/div.h"
#include "neon/dot.h"
#include "neon/dot_lane.h"
#include "neon/dup_lane.h"
#include "neon/dup_n.h"
#include "neon/eor.h"
#include "neon/ext.h"
#include "neon/fma.h"
#include "neon/fma_lane.h"
#include "neon/fma_n.h"
#include "neon/fmlal.h"
#include "neon/fmlsl.h"
#include "neon/fms.h"
#include "neon/fms_lane.h"
#include "neon/fms_n.h"
#include "neon/get_high.h"
#include "neon/get_lane.h"
#include "neon/get_low.h"
#include "neon/hadd.h"
#include "neon/hsub.h"
#include "neon/ld1.h"
#include "neon/ld1_dup.h"
#include "neon/ld1_lane.h"
#include "neon/ld1_x2.h"
#include "neon/ld1_x3.h"
#include "neon/ld1_x4.h"
#include "neon/ld1q_x2.h"
#include "neon/ld1q_x3.h"
#include "neon/ld1q_x4.h"
#include "neon/ld2.h"
#include "neon/ld2_dup.h"
#include "neon/ld2_lane.h"
#include "neon/ld3.h"
#include "neon/ld3_dup.h"
#include "neon/ld3_lane.h"
#include "neon/ld4.h"
#include "neon/ld4_dup.h"
#include "neon/ld4_lane.h"
#include "neon/max.h"
#include "neon/maxnm.h"
#include "neon/maxnmv.h"
#include "neon/maxv.h"
#include "neon/min.h"
#include "neon/minnm.h"
#include "neon/minnmv.h"
#include "neon/minv.h"
#include "neon/mla.h"
#include "neon/mla_lane.h"
#include "neon/mla_n.h"
#include "neon/mlal.h"
#include "neon/mlal_high.h"
#include "neon/mlal_high_lane.h"
#include "neon/mlal_high_n.h"
#include "neon/mlal_lane.h"
#include "neon/mlal_n.h"
#include "neon/mls.h"
#include "neon/mls_lane.h"
#include "neon/mls_n.h"
#include "neon/mlsl.h"
#include "neon/mlsl_high.h"
#include "neon/mlsl_high_lane.h"
#include "neon/mlsl_high_n.h"
#include "neon/mlsl_lane.h"
#include "neon/mlsl_n.h"
#include "neon/mmlaq.h"
#include "neon/movl.h"
#include "neon/movl_high.h"
#include "neon/movn.h"
#include "neon/movn_high.h"
#include "neon/mul.h"
#include "neon/mul_lane.h"
#include "neon/mul_n.h"
#include "neon/mull.h"
#include "neon/mull_high.h"
#include "neon/mull_high_lane.h"
#include "neon/mull_high_n.h"
#include "neon/mull_lane.h"
#include "neon/mull_n.h"
#include "neon/mulx.h"
#include "neon/mulx_lane.h"
#include "neon/mulx_n.h"
#include "neon/mvn.h"
#include "neon/neg.h"
#include "neon/orn.h"
#include "neon/orr.h"
#include "neon/padal.h"
#include "neon/padd.h"
#include "neon/paddl.h"
#include "neon/pmax.h"
#include "neon/pmaxnm.h"
#include "neon/pmin.h"
#include "neon/pminnm.h"
#include "neon/qabs.h"
#include "neon/qadd.h"
#include "neon/qdmlal.h"
#include "neon/qdmlal_high.h"
#include "neon/qdmlal_high_lane.h"
#include "neon/qdmlal_high_n.h"
#include "neon/qdmlal_lane.h"
#include "neon/qdmlal_n.h"
#include "neon/qdmlsl.h"
#include "neon/qdmlsl_high.h"
#include "neon/qdmlsl_high_lane.h"
#include "neon/qdmlsl_high_n.h"
#include "neon/qdmlsl_lane.h"
#include "neon/qdmlsl_n.h"
#include "neon/qdmulh.h"
#include "neon/qdmulh_lane.h"
#include "neon/qdmulh_n.h"
#include "neon/qdmull.h"
#include "neon/qdmull_high.h"
#include "neon/qdmull_high_lane.h"
#include "neon/qdmull_high_n.h"
#include "neon/qdmull_lane.h"
#include "neon/qdmull_n.h"
#include "neon/qrdmlah.h"
#include "neon/qrdmulh.h"
#include "neon/qrdmulh_lane.h"
#include "neon/qrdmulh_n.h"
#include "neon/qrshl.h"
#include "neon/qrshrn_high_n.h"
#include "neon/qrshrn_n.h"
#include "neon/qrshrun_high_n.h"
#include "neon/qrshrun_n.h"
#include "neon/qmovn.h"
#include "neon/qmovn_high.h"
#include "neon/qmovun.h"
#include "neon/qmovun_high.h"
#include "neon/qneg.h"
#include "neon/qsub.h"
#include "neon/qshl.h"
#include "neon/qshl_n.h"
#include "neon/qshlu_n.h"
#include "neon/qshrn_high_n.h"
#include "neon/qshrn_n.h"
#include "neon/qshrun_n.h"
#include "neon/qtbl.h"
#include "neon/qtbx.h"
#include "neon/raddhn.h"
#include "neon/raddhn_high.h"
#include "neon/rbit.h"
#include "neon/recpe.h"
#include "neon/recps.h"
#include "neon/reinterpret.h"
#include "neon/rev16.h"
#include "neon/rev32.h"
#include "neon/rev64.h"
#include "neon/rhadd.h"
#include "neon/rnd.h"
#include "neon/rndm.h"
#include "neon/rndi.h"
#include "neon/rndn.h"
#include "neon/rndp.h"
#include "neon/rshl.h"
#include "neon/rshr_n.h"
#include "neon/rshrn_high_n.h"
#include "neon/rshrn_n.h"
#include "neon/rsqrte.h"
#include "neon/rsqrts.h"
#include "neon/rsra_n.h"
#include "neon/rsubhn.h"
#include "neon/rsubhn_high.h"
#include "neon/set_lane.h"
#include "neon/shl.h"
#include "neon/shl_n.h"
#include "neon/shll_n.h"
#include "neon/shr_n.h"
#include "neon/shrn_n.h"
#include "neon/sli_n.h"
#include "neon/sqadd.h"
#include "neon/sqrt.h"
#include "neon/sra_n.h"
#include "neon/sri_n.h"
#include "neon/st1.h"
#include "neon/st1_lane.h"
#include "neon/st1_x2.h"
#include "neon/st1_x3.h"
#include "neon/st1_x4.h"
#include "neon/st1q_x2.h"
#include "neon/st1q_x3.h"
#include "neon/st1q_x4.h"
#include "neon/st2.h"
#include "neon/st2_lane.h"
#include "neon/st3.h"
#include "neon/st3_lane.h"
#include "neon/st4.h"
#include "neon/st4_lane.h"
#include "neon/sub.h"
#include "neon/subhn.h"
#include "neon/subl.h"
#include "neon/subl_high.h"
#include "neon/subw.h"
#include "neon/subw_high.h"
#include "neon/tbl.h"
#include "neon/tbx.h"
#include "neon/trn.h"
#include "neon/trn1.h"
#include "neon/trn2.h"
#include "neon/tst.h"
#include "neon/uqadd.h"
#include "neon/uzp.h"
#include "neon/uzp1.h"
#include "neon/uzp2.h"
#include "neon/xar.h"
#include "neon/zip.h"
#include "neon/zip1.h"
#include "neon/zip2.h"

#endif /* SIMDE_ARM_NEON_H */
