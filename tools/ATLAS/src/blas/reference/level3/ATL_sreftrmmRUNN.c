/* ---------------------------------------------------------------------
 *
 * -- Automatically Tuned Linear Algebra Software (ATLAS)
 *    (C) Copyright 2000 All Rights Reserved
 *
 * -- ATLAS routine -- Version 3.9.24 -- December 25, 2000
 *
 * Author         : Antoine P. Petitet
 * Originally developed at the University of Tennessee,
 * Innovative Computing Laboratory, Knoxville TN, 37996-1301, USA.
 *
 * ---------------------------------------------------------------------
 *
 * -- Copyright notice and Licensing terms:
 *
 *  Redistribution  and  use in  source and binary forms, with or without
 *  modification, are  permitted provided  that the following  conditions
 *  are met:
 *
 * 1. Redistributions  of  source  code  must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce  the above copyright
 *    notice,  this list of conditions, and the  following disclaimer in
 *    the documentation and/or other materials provided with the distri-
 *    bution.
 * 3. The name of the University,  the ATLAS group,  or the names of its
 *    contributors  may not be used to endorse or promote products deri-
 *    ved from this software without specific written permission.
 *
 * -- Disclaimer:
 *
 * THIS  SOFTWARE  IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE UNIVERSITY
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  INDIRECT, INCIDENTAL, SPE-
 * CIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO,  PROCUREMENT  OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEO-
 * RY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (IN-
 * CLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ---------------------------------------------------------------------
 */
/*
 * Include files
 */
#include "atlas_refmisc.h"
#include "atlas_reflvl3.h"
#include "atlas_reflevel3.h"

void ATL_sreftrmmRUNN
(
   const int                  M,
   const int                  N,
   const float                ALPHA,
   const float                * A,
   const int                  LDA,
   float                      * B,
   const int                  LDB
)
{
/*
 * Purpose
 * =======
 *
 * ATL_sreftrmmRUNN( ... )
 *
 * <=>
 *
 * ATL_sreftrmm
 * ( AtlasRight, AtlasUpper, AtlasNoTrans, AtlasNonUnit, ... )
 *
 * See ATL_sreftrmm for details.
 *
 * ---------------------------------------------------------------------
 */
/*
 * .. Local Variables ..
 */
   register float             t0;
   int                        i, iakj, ibij, ibik, j, jaj, jbj, jbk, k;
/* ..
 * .. Executable Statements ..
 *
 */
   for( j = N-1,     jaj  = (N-1)*LDA, jbj  = (N-1)*LDB;
        j >= 0; j--, jaj -= LDA,       jbj -= LDB )
   {
      t0 = ALPHA;
      t0 *= A[j+jaj];
      for( i = 0, ibij = jbj; i < M; i++, ibij += 1 ) { B[ibij] *= t0; }
      for( k = 0, iakj = jaj, jbk = 0; k < j; k++, iakj += 1, jbk += LDB )
      {
         t0 = ALPHA * A[iakj];
         for( i = 0, ibij = jbj, ibik = jbk; i < M; i++, ibij += 1, ibik += 1 )
         { B[ibij] += t0 * B[ibik]; }
      }
   }
/*
 * End of ATL_sreftrmmRUNN
 */
}
