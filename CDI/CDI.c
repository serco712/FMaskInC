/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CDI.c
 *
 * Code generation for function 'CDI'
 *
 */

/* Include files */
#include "CDI.h"
#include "CDI_emxutil.h"
#include "CDI_types.h"
#include "div.h"
#include "stdfilt.h"

/* Function Declarations */
static void binary_expand_op_1(emxArray_real_T *in1,
                               const emxArray_real32_T *in2,
                               const emxArray_real32_T *in3);

/* Function Definitions */
static void binary_expand_op_1(emxArray_real_T *in1,
                               const emxArray_real32_T *in2,
                               const emxArray_real32_T *in3)
{
  emxArray_real32_T *b_in2;
  const float *in2_data;
  const float *in3_data;
  float *b_in2_data;
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
  emxInit_real32_T(&b_in2, 2);
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = b_in2->size[0] * b_in2->size[1];
  b_in2->size[0] = loop_ub;
  if (in3->size[1] == 1) {
    b_loop_ub = in2->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  b_in2->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(b_in2, i);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in2_data[i1 + b_in2->size[0] * i] =
          in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] /
          in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  stdfilt(b_in2, in1);
  emxFree_real32_T(&b_in2);
}

void CDI(const emxArray_real32_T *S2band7, const emxArray_real32_T *S2band8,
         const emxArray_real32_T *S2band8A, emxArray_real_T *cdi)
{
  emxArray_real32_T *b_S2band8;
  emxArray_real_T *std_ratio_8A_8;
  emxArray_real_T *var_ratio_8A_8;
  double *cdi_data;
  double *std_ratio_8A_8_data;
  double *var_ratio_8A_8_data;
  const float *S2band7_data;
  const float *S2band8A_data;
  const float *S2band8_data;
  float *b_S2band8_data;
  int i;
  S2band8A_data = S2band8A->data;
  S2band8_data = S2band8->data;
  S2band7_data = S2band7->data;
  /* CDI This is used seprate bright surface from cloud by following David, */
  /* 2018 RSE */
  emxInit_real_T(&std_ratio_8A_8, 2);
  emxInit_real_T(&var_ratio_8A_8, 2);
  emxInit_real32_T(&b_S2band8, 2);
  if ((S2band7->size[0] != 0) && (S2band7->size[1] != 0) &&
      ((S2band8->size[0] != 0) && (S2band8->size[1] != 0))) {
    double varargin_1;
    int i1;
    int i2;
    int i3;
    int loop_ub;
    if ((S2band8->size[0] == S2band8A->size[0]) &&
        (S2band8->size[1] == S2band8A->size[1])) {
      i = b_S2band8->size[0] * b_S2band8->size[1];
      b_S2band8->size[0] = S2band8->size[0];
      b_S2band8->size[1] = S2band8->size[1];
      emxEnsureCapacity_real32_T(b_S2band8, i);
      b_S2band8_data = b_S2band8->data;
      loop_ub = S2band8->size[0] * S2band8->size[1];
      for (i = 0; i < loop_ub; i++) {
        b_S2band8_data[i] = S2band8_data[i] / S2band8A_data[i];
      }
      stdfilt(b_S2band8, std_ratio_8A_8);
      std_ratio_8A_8_data = std_ratio_8A_8->data;
    } else {
      binary_expand_op_1(std_ratio_8A_8, S2band8, S2band8A);
      std_ratio_8A_8_data = std_ratio_8A_8->data;
    }
    i = var_ratio_8A_8->size[0] * var_ratio_8A_8->size[1];
    var_ratio_8A_8->size[0] = std_ratio_8A_8->size[0];
    var_ratio_8A_8->size[1] = std_ratio_8A_8->size[1];
    emxEnsureCapacity_real_T(var_ratio_8A_8, i);
    var_ratio_8A_8_data = var_ratio_8A_8->data;
    loop_ub = std_ratio_8A_8->size[0] * std_ratio_8A_8->size[1];
    for (i = 0; i < loop_ub; i++) {
      varargin_1 = std_ratio_8A_8_data[i];
      var_ratio_8A_8_data[i] = varargin_1 * varargin_1;
    }
    if ((S2band7->size[0] == S2band8A->size[0]) &&
        (S2band7->size[1] == S2band8A->size[1])) {
      i = b_S2band8->size[0] * b_S2band8->size[1];
      b_S2band8->size[0] = S2band7->size[0];
      b_S2band8->size[1] = S2band7->size[1];
      emxEnsureCapacity_real32_T(b_S2band8, i);
      b_S2band8_data = b_S2band8->data;
      loop_ub = S2band7->size[0] * S2band7->size[1];
      for (i = 0; i < loop_ub; i++) {
        b_S2band8_data[i] = S2band7_data[i] / S2band8A_data[i];
      }
      stdfilt(b_S2band8, std_ratio_8A_8);
      std_ratio_8A_8_data = std_ratio_8A_8->data;
    } else {
      binary_expand_op_1(std_ratio_8A_8, S2band7, S2band8A);
      std_ratio_8A_8_data = std_ratio_8A_8->data;
    }
    i = cdi->size[0] * cdi->size[1];
    cdi->size[0] = std_ratio_8A_8->size[0];
    cdi->size[1] = std_ratio_8A_8->size[1];
    emxEnsureCapacity_real_T(cdi, i);
    cdi_data = cdi->data;
    loop_ub = std_ratio_8A_8->size[0] * std_ratio_8A_8->size[1];
    for (i = 0; i < loop_ub; i++) {
      varargin_1 = std_ratio_8A_8_data[i];
      cdi_data[i] = varargin_1 * varargin_1;
    }
    if (cdi->size[0] == 1) {
      i = var_ratio_8A_8->size[0];
    } else {
      i = cdi->size[0];
    }
    if (var_ratio_8A_8->size[0] == 1) {
      i1 = cdi->size[0];
    } else {
      i1 = var_ratio_8A_8->size[0];
    }
    if (cdi->size[1] == 1) {
      i2 = var_ratio_8A_8->size[1];
    } else {
      i2 = cdi->size[1];
    }
    if (var_ratio_8A_8->size[1] == 1) {
      i3 = cdi->size[1];
    } else {
      i3 = var_ratio_8A_8->size[1];
    }
    if ((cdi->size[0] == var_ratio_8A_8->size[0]) &&
        (cdi->size[1] == var_ratio_8A_8->size[1]) &&
        (var_ratio_8A_8->size[0] == cdi->size[0]) &&
        (var_ratio_8A_8->size[1] == cdi->size[1]) && (i == i1) && (i2 == i3)) {
      for (i = 0; i < loop_ub; i++) {
        cdi_data[i] = (cdi_data[i] - var_ratio_8A_8_data[i]) /
                      (var_ratio_8A_8_data[i] + cdi_data[i]);
      }
    } else {
      binary_expand_op(cdi, var_ratio_8A_8);
    }
    /*          dim = size(cdi); */
    /*          cdi = imresize(cdi,1/7,'box'); */
    /*          cdi = ordfilt2(cdi,1,ones(3,3)); */
    /*          cdi = imresize(cdi,dim,'nearest'); */
    /*          clear dim; */
    /*          h = fspecial('average', 21); */
    /*          cdi = filter2(h, cdi); */
  } else {
    cdi->size[0] = 0;
    cdi->size[1] = 0;
  }
  emxFree_real32_T(&b_S2band8);
  emxFree_real_T(&var_ratio_8A_8);
  emxFree_real_T(&std_ratio_8A_8);
}

/* End of code generation (CDI.c) */
