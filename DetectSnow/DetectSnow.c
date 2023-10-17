/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DetectSnow.c
 *
 * Code generation for function 'DetectSnow'
 *
 */

/* Include files */
#include "DetectSnow.h"
#include "DetectSnow_emxutil.h"
#include "DetectSnow_types.h"

/* Function Declarations */
static void binary_expand_op(emxArray_boolean_T *in1,
                             const emxArray_real32_T *in2);

static void binary_expand_op_1(emxArray_boolean_T *in1,
                               const emxArray_real32_T *in2,
                               const emxArray_real32_T *in3,
                               const emxArray_real32_T *in4);

/* Function Definitions */
static void binary_expand_op(emxArray_boolean_T *in1,
                             const emxArray_real32_T *in2)
{
  emxArray_boolean_T *b_in1;
  const float *in2_data;
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
  boolean_T *b_in1_data;
  boolean_T *in1_data;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_boolean_T(&b_in1, 2);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          (in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] &&
           (in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1] < 1000.0F));
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_boolean_T(&b_in1);
}

static void binary_expand_op_1(emxArray_boolean_T *in1,
                               const emxArray_real32_T *in2,
                               const emxArray_real32_T *in3,
                               const emxArray_real32_T *in4)
{
  const float *in2_data;
  const float *in3_data;
  const float *in4_data;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  int stride_2_0;
  int stride_2_1;
  boolean_T *in1_data;
  in4_data = in4->data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in4->size[0] == 1) {
    if (in3->size[0] == 1) {
      loop_ub = in2->size[0];
    } else {
      loop_ub = in3->size[0];
    }
  } else {
    loop_ub = in4->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  if (in4->size[1] == 1) {
    if (in3->size[1] == 1) {
      b_loop_ub = in2->size[1];
    } else {
      b_loop_ub = in3->size[1];
    }
  } else {
    b_loop_ub = in4->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  stride_2_0 = (in4->size[0] != 1);
  stride_2_1 = (in4->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          ((in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] > 0.15) &&
           (in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1] > 1100.0F) &&
           (in4_data[i1 * stride_2_0 + in4->size[0] * aux_2_1] > 1000.0F));
    }
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

void DetectSnow(const double dim[2], const emxArray_real32_T *band_green,
                const emxArray_real32_T *band_nir,
                const emxArray_real32_T *band_bt, const emxArray_real32_T *ndsi,
                emxArray_boolean_T *snow)
{
  const float *band_bt_data;
  const float *band_green_data;
  const float *band_nir_data;
  const float *ndsi_data;
  int i;
  int loop_ub;
  boolean_T *snow_data;
  (void)dim;
  ndsi_data = ndsi->data;
  band_bt_data = band_bt->data;
  band_nir_data = band_nir->data;
  band_green_data = band_green->data;
  /* DETECSNOW Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*  %     snow=zeros(dim,'uint8'); % Snow mask */
  /*  It takes every snow pixels including snow pixel under thin clouds or icy
   * clouds */
  if (ndsi->size[0] == 1) {
    i = band_nir->size[0];
  } else {
    i = ndsi->size[0];
  }
  if (ndsi->size[1] == 1) {
    loop_ub = band_nir->size[1];
  } else {
    loop_ub = ndsi->size[1];
  }
  if ((ndsi->size[0] == band_nir->size[0]) &&
      (ndsi->size[1] == band_nir->size[1]) && (i == band_green->size[0]) &&
      (loop_ub == band_green->size[1])) {
    i = snow->size[0] * snow->size[1];
    snow->size[0] = ndsi->size[0];
    snow->size[1] = ndsi->size[1];
    emxEnsureCapacity_boolean_T(snow, i);
    snow_data = snow->data;
    loop_ub = ndsi->size[0] * ndsi->size[1];
    for (i = 0; i < loop_ub; i++) {
      snow_data[i] = ((ndsi_data[i] > 0.15) && (band_nir_data[i] > 1100.0F) &&
                      (band_green_data[i] > 1000.0F));
    }
  } else {
    binary_expand_op_1(snow, ndsi, band_nir, band_green);
    snow_data = snow->data;
  }
  if ((band_bt->size[0] != 0) && (band_bt->size[1] != 0)) {
    if ((snow->size[0] == band_bt->size[0]) &&
        (snow->size[1] == band_bt->size[1])) {
      loop_ub = snow->size[0] * snow->size[1];
      for (i = 0; i < loop_ub; i++) {
        snow_data[i] = (snow_data[i] && (band_bt_data[i] < 1000.0F));
      }
    } else {
      binary_expand_op(snow, band_bt);
    }
  }
  /*      snow(ids_snow)=1; */
}

/* End of code generation (DetectSnow.c) */
