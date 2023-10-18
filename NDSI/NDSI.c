/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NDSI.c
 *
 * Code generation for function 'NDSI'
 *
 */

/* Include files */
#include "NDSI.h"
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

void NDSI(const emxArray_real32_T *green, const emxArray_real32_T *swir,
          emxArray_real32_T *ndsi)
{
  emxArray_real32_T *y_tmp;
  const float *green_data;
  const float *swir_data;
  float *ndsi_data;
  float *y_tmp_data;
  int i;
  int loop_ub;
  boolean_T b;
  swir_data = swir->data;
  green_data = green->data;
  /* NDSI calculate Normalized Difference Snow Index (NDSI) using Green and */
  /*      SWIR bands. */
  /*  Syntax */
  /*  */
  /*      ndsi = NDSI(green,swir) */
  /*  */
  /*  Description */
  /*  */
  /*      This function calculates Normalized Difference Snow Index (NDSI)  */
  /*      using Green and SWIR bands (as following equation). This can be used
   */
  /*      to detect snow, as the atmosphere is transparent at both these  */
  /*      wavelengths, while snow is very reflective at 0.66 mm and not  */
  /*      reflective at 1.6mm. At visible wavelengths (e.g. 0.66 microns), snow
   */
  /*      cover is just as bright as clouds, and is therefore difficult to  */
  /*      distinguish from cloud cover. However, at 1.6 microns, snow cover  */
  /*      absorbs sunlight, and therefore appears much darker than clouds. */
  /*  */
  /*      NDSI=(Green-SWIR)/(Green+SWIR). */
  /*  */
  /*  Input arguments */
  /*  */
  /*      green       Green band */
  /*      swir        Short-wave infrared band */
  /*  */
  /*  Output arguments */
  /*  */
  /*      ndsi        Normalized Difference Snow Index */
  /*  */
  /*  Author: Shi Qiu (shi.qiu@ttu.edu) */
  /*  Date: 19. October, 2017 */
  /*  calculate NDSI */
  b = ((green->size[0] == swir->size[0]) && (green->size[1] == swir->size[1]));
  emxInit_real32_T(&y_tmp, 2);
  if (b) {
    i = y_tmp->size[0] * y_tmp->size[1];
    y_tmp->size[0] = green->size[0];
    y_tmp->size[1] = green->size[1];
    emxEnsureCapacity_real32_T(y_tmp, i);
    y_tmp_data = y_tmp->data;
    loop_ub = green->size[0] * green->size[1];
    for (i = 0; i < loop_ub; i++) {
      y_tmp_data[i] = green_data[i] + swir_data[i];
    }
  } else {
    plus(y_tmp, green, swir);
    y_tmp_data = y_tmp->data;
  }
  if (green->size[0] == 1) {
    loop_ub = swir->size[0];
  } else {
    loop_ub = green->size[0];
  }
  if (green->size[1] == 1) {
    i = swir->size[1];
  } else {
    i = green->size[1];
  }
  if (b && (loop_ub == y_tmp->size[0]) && (i == y_tmp->size[1])) {
    i = ndsi->size[0] * ndsi->size[1];
    ndsi->size[0] = green->size[0];
    ndsi->size[1] = green->size[1];
    emxEnsureCapacity_real32_T(ndsi, i);
    ndsi_data = ndsi->data;
    loop_ub = green->size[0] * green->size[1];
    for (i = 0; i < loop_ub; i++) {
      ndsi_data[i] = (green_data[i] - swir_data[i]) / y_tmp_data[i];
    }
  } else {
    binary_expand_op(ndsi, green, swir, y_tmp);
    ndsi_data = ndsi->data;
  }
  /*  fix unnormal pixels */
  loop_ub = y_tmp->size[0] * y_tmp->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    if (y_tmp_data[i] == 0.0F) {
      ndsi_data[i] = 0.01F;
    }
  }
  emxFree_real32_T(&y_tmp);
}

/* End of code generation (NDSI.c) */
