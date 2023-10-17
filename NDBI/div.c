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
#include "NDBI_emxutil.h"
#include "NDBI_types.h"

/* Function Definitions */
void binary_expand_op(emxArray_real32_T *in1, const emxArray_real32_T *in2,
                      const emxArray_real32_T *in3)
{
  const float *in2_data;
  const float *in3_data;
  float *in1_data;
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
  stride_0_0_tmp = (in2->size[0] != 1);
  stride_0_1_tmp = (in2->size[1] != 1);
  stride_1_0_tmp = (in3->size[0] != 1);
  stride_1_1_tmp = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1_tmp = 0;
  aux_3_1_tmp = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      float f;
      float f1;
      f = in2_data[i1 * stride_0_0_tmp + in2->size[0] * aux_0_1];
      f1 = in3_data[i1 * stride_1_0_tmp + in3->size[0] * aux_1_1];
      in1_data[i1 + in1->size[0] * i] = (f - f1) / (f + f1);
    }
    aux_3_1_tmp += stride_1_1_tmp;
    aux_2_1_tmp += stride_0_1_tmp;
    aux_1_1 = aux_3_1_tmp;
    aux_0_1 = aux_2_1_tmp;
  }
}

/* End of code generation (div.c) */
