/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NDVI.c
 *
 * Code generation for function 'NDVI'
 *
 */

/* Include files */
#include "NDVI.h"
#include "emxutil.h"
#include "types.h"
#include "div.h"

/* Function Declarations */
static void plus(emxArray_real32_T *in1, const emxArray_real32_T *in2,
                 const emxArray_real32_T *in3);

/* Function Definitions */
static void plus(emxArray_real32_T *in1, const emxArray_real32_T *in2,
                 const emxArray_real32_T *in3)
{
  const float *in2_data;
  const float *in3_data;
  float *in1_data;
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  if (in3->size[1] == 1) {
    b_loop_ub = in2->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] +
          in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

void NDVI(const emxArray_real32_T *red, const emxArray_real32_T *nir,
          emxArray_real32_T *ndvi)
{
  emxArray_real32_T *y_tmp;
  const float *nir_data;
  const float *red_data;
  float *ndvi_data;
  float *y_tmp_data;
  int i;
  int loop_ub;
  boolean_T b;
  nir_data = nir->data;
  red_data = red->data;
  /* NDVI Calculate Normalized Difference Vegetation Index (NDVI) using NIR and
   */
  /*      Red bands. */
  /*  */
  /*  Syntax */
  /*  */
  /*      ndvi = NDVI(red,nir) */
  /*  */
  /*  Description */
  /*  */
  /*      This function calculates Normalized Difference Vegetation Index (NDVI)
   */
  /*      using NIR and Red bands (as following equation). This range is between
   */
  /*      -1 and 1. */
  /*      NDVI=(NIR-Red)/(NIR+Red). */
  /*  */
  /*  Input arguments */
  /*  */
  /*      red         Red band */
  /*      nir         Near-infrared band */
  /*  */
  /*  Output arguments */
  /*  */
  /*      ndvi        Normalized Difference Vegetation Index */
  /*  */
  /*  Author: Shi Qiu (shi.qiu@ttu.edu) */
  /*  Date: 19. October, 2017 */
  /*  calculate NDVI */
  b = ((nir->size[0] == red->size[0]) && (nir->size[1] == red->size[1]));
  emxInit_real32_T(&y_tmp, 2);
  if (b) {
    i = y_tmp->size[0] * y_tmp->size[1];
    y_tmp->size[0] = nir->size[0];
    y_tmp->size[1] = nir->size[1];
    emxEnsureCapacity_real32_T(y_tmp, i);
    y_tmp_data = y_tmp->data;
    loop_ub = nir->size[0] * nir->size[1];
    for (i = 0; i < loop_ub; i++) {
      y_tmp_data[i] = nir_data[i] + red_data[i];
    }
  } else {
    plus(y_tmp, nir, red);
    y_tmp_data = y_tmp->data;
  }
  if (nir->size[0] == 1) {
    loop_ub = red->size[0];
  } else {
    loop_ub = nir->size[0];
  }
  if (nir->size[1] == 1) {
    i = red->size[1];
  } else {
    i = nir->size[1];
  }
  if (b && (loop_ub == y_tmp->size[0]) && (i == y_tmp->size[1])) {
    i = ndvi->size[0] * ndvi->size[1];
    ndvi->size[0] = nir->size[0];
    ndvi->size[1] = nir->size[1];
    emxEnsureCapacity_real32_T(ndvi, i);
    ndvi_data = ndvi->data;
    loop_ub = nir->size[0] * nir->size[1];
    for (i = 0; i < loop_ub; i++) {
      ndvi_data[i] = (nir_data[i] - red_data[i]) / y_tmp_data[i];
    }
  } else {
    binary_expand_op(ndvi, nir, red, y_tmp);
    ndvi_data = ndvi->data;
  }
  /*  fix unnormal pixels */
  loop_ub = y_tmp->size[0] * y_tmp->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    if (y_tmp_data[i] == 0.0F) {
      ndvi_data[i] = 0.01F;
    }
  }
  emxFree_real32_T(&y_tmp);
}

/* End of code generation (NDVI.c) */
