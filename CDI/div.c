/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * div.c
 *
 * Code generation for function 'div'
 *
 */

/* Include files */
#include "div.h"
#include "CDI_emxutil.h"
#include "CDI_types.h"

/* Function Definitions */
void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  double *b_in1_data;
  double *in1_data;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1_tmp;
  int aux_3_1_tmp;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0_tmp;
  int stride_0_1_tmp;
  int stride_1_0_tmp;
  int stride_1_1_tmp;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  if (in1->size[0] == 1) {
    i = in2->size[0];
  } else {
    i = in1->size[0];
  }
  if (i == 1) {
    if (in2->size[0] == 1) {
      loop_ub = in1->size[0];
    } else {
      loop_ub = in2->size[0];
    }
  } else {
    loop_ub = i;
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in1->size[1] == 1) {
    i1 = in2->size[1];
  } else {
    i1 = in1->size[1];
  }
  if (i1 == 1) {
    if (in2->size[1] == 1) {
      b_loop_ub = in1->size[1];
    } else {
      b_loop_ub = in2->size[1];
    }
  } else {
    b_loop_ub = i1;
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0_tmp = (in1->size[0] != 1);
  stride_0_1_tmp = (in1->size[1] != 1);
  stride_1_0_tmp = (in2->size[0] != 1);
  stride_1_1_tmp = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1_tmp = 0;
  aux_3_1_tmp = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      double b_in1_tmp;
      double in1_tmp;
      in1_tmp = in2_data[i1 * stride_1_0_tmp + in2->size[0] * aux_1_1];
      b_in1_tmp = in1_data[i1 * stride_0_0_tmp + in1->size[0] * aux_0_1];
      b_in1_data[i1 + b_in1->size[0] * i] =
          (b_in1_tmp - in1_tmp) / (in1_tmp + b_in1_tmp);
    }
    aux_3_1_tmp += stride_0_1_tmp;
    aux_2_1_tmp += stride_1_1_tmp;
    aux_1_1 = aux_2_1_tmp;
    aux_0_1 = aux_3_1_tmp;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(&b_in1);
}

/* End of code generation (div.c) */
