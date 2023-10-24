/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unsafeSxfun.c
 *
 * Code generation for function 'unsafeSxfun'
 *
 */

/* Include files */
#include "unsafeSxfun.h"
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"
#include <math.h>

/* Function Definitions */
void binary_expand_op_22(emxArray_real_T *in1, const emxArray_real_T *in3)
{
  emxArray_real_T *b_in3;
  const double *in3_data;
  double varargin_1;
  double *b_in3_data;
  double *in1_data;
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
  in1_data = in1->data;
  emxInit_real_T(&b_in3, 2);
  if (in1->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  i = b_in3->size[0] * b_in3->size[1];
  b_in3->size[0] = loop_ub;
  if (in1->size[1] == 1) {
    b_loop_ub = in3->size[1];
  } else {
    b_loop_ub = in1->size[1];
  }
  b_in3->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(b_in3, i);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_0_1 = (in3->size[1] != 1);
  stride_1_0 = (in1->size[0] != 1);
  stride_1_1 = (in1->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1 = in1_data[i1 * stride_1_0 + in1->size[0] * aux_1_1];
      b_in3_data[i1 + b_in3->size[0] * i] =
          in3_data[i1 * stride_0_0 + in3->size[0] * aux_0_1] -
          varargin_1 * varargin_1;
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in3->size[0];
  in1->size[1] = b_in3->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in3->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      varargin_1 = b_in3_data[i1 + b_in3->size[0] * i];
      in1_data[i1 + in1->size[0] * i] = fmax(varargin_1, 0.0);
    }
  }
  emxFree_real_T(&b_in3);
}

void binary_expand_op_23(emxArray_real_T *in1, const emxArray_real_T *in3,
                         const emxArray_real_T *in4)
{
  emxArray_real_T *b_in3;
  const double *in3_data;
  const double *in4_data;
  double varargin_1;
  double *b_in3_data;
  double *in1_data;
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
  in4_data = in4->data;
  in3_data = in3->data;
  emxInit_real_T(&b_in3, 2);
  if (in4->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  i = b_in3->size[0] * b_in3->size[1];
  b_in3->size[0] = loop_ub;
  if (in4->size[1] == 1) {
    b_loop_ub = in3->size[1];
  } else {
    b_loop_ub = in4->size[1];
  }
  b_in3->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(b_in3, i);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_0_1 = (in3->size[1] != 1);
  stride_1_0 = (in4->size[0] != 1);
  stride_1_1 = (in4->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1 = in4_data[i1 * stride_1_0 + in4->size[0] * aux_1_1];
      b_in3_data[i1 + b_in3->size[0] * i] =
          in3_data[i1 * stride_0_0 + in3->size[0] * aux_0_1] -
          varargin_1 * varargin_1;
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in3->size[0];
  in1->size[1] = b_in3->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in3->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      varargin_1 = b_in3_data[i1 + b_in3->size[0] * i];
      in1_data[i1 + in1->size[0] * i] = fmax(varargin_1, 0.0);
    }
  }
  emxFree_real_T(&b_in3);
}

/* End of code generation (unsafeSxfun.c) */
