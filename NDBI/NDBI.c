/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NDBI.c
 *
 * Code generation for function 'NDBI'
 *
 */

/* Include files */
#include "NDBI.h"
#include "emxutil.h"
#include "types.h"
#include "div.h"

/* Function Definitions */
void NDBI(const emxArray_real32_T *nir, const emxArray_real32_T *swir,
          emxArray_real32_T *ndbi)
{
  const float *nir_data;
  const float *swir_data;
  float *ndbi_data;
  int i;
  swir_data = swir->data;
  nir_data = nir->data;
  /* NDBI Calculate Normalized Difference Build-up Index (NDBI) using NIR and */
  /*      SWIR bands. */
  /*  Syntax */
  /*  */
  /*      ndbi = NDBI(swir,nir) */
  /*  */
  /*  Description */
  /*  */
  /*      This function calculates Normalized Difference Build-up Index (NDBI)
   */
  /*      using SWIR and NIR bands (as following equation). */
  /*  */
  /*  Input arguments */
  /*  */
  /*      swir        Short-wave infrared band */
  /*      nir         Near infrared band */
  /*  */
  /*  Output arguments */
  /*  */
  /*      ndbi        Normalized Difference Build-up Index */
  /*  */
  /*  Author: Shi Qiu (shi.qiu@ttu.edu) */
  /*  Date: 19. Dec., 2017 */
  /*  calculate NDBI */
  if ((swir->size[0] == nir->size[0]) && (swir->size[1] == nir->size[1]) &&
      (swir->size[0] == nir->size[0]) && (swir->size[1] == nir->size[1])) {
    int loop_ub;
    i = ndbi->size[0] * ndbi->size[1];
    ndbi->size[0] = swir->size[0];
    ndbi->size[1] = swir->size[1];
    emxEnsureCapacity_real32_T(ndbi, i);
    ndbi_data = ndbi->data;
    loop_ub = swir->size[0] * swir->size[1];
    for (i = 0; i < loop_ub; i++) {
      ndbi_data[i] =
          (swir_data[i] - nir_data[i]) / (swir_data[i] + nir_data[i]);
    }
  } else {
    binary_expand_op(ndbi, swir, nir);
  }
  /*  fix unnormal pixels */
  /*  not 0.01 any more because we will identify urban pixel using ndbi more
   * than 0. */
  /*      ndbi((nir+swir)==0)=0.0; */
}

/* End of code generation (NDBI.c) */
