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
#include "Fmask_emxutil.h"
#include "Fmask_types.h"

/* Function Definitions */
void binary_expand_op_13(emxArray_real32_T *in1, const emxArray_real32_T *in2,
                         const emxArray_real32_T *in3,
                         const emxArray_real32_T *in4)
{
  emxArray_real32_T *b_in1;
  const float *in2_data;
  const float *in3_data;
  const float *in4_data;
  float *b_in1_data;
  float *in1_data;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int aux_3_1;
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
  int stride_3_0;
  int stride_3_1;
  in4_data = in4->data;
  in3_data = in3->data;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real32_T(&b_in1, 2);
  if (in4->size[0] == 1) {
    if (in3->size[0] == 1) {
      if (in2->size[0] == 1) {
        loop_ub = in1->size[0];
      } else {
        loop_ub = in2->size[0];
      }
    } else {
      loop_ub = in3->size[0];
    }
  } else {
    loop_ub = in4->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in4->size[1] == 1) {
    if (in3->size[1] == 1) {
      if (in2->size[1] == 1) {
        b_loop_ub = in1->size[1];
      } else {
        b_loop_ub = in2->size[1];
      }
    } else {
      b_loop_ub = in3->size[1];
    }
  } else {
    b_loop_ub = in4->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  stride_2_0 = (in3->size[0] != 1);
  stride_2_1 = (in3->size[1] != 1);
  stride_3_0 = (in4->size[0] != 1);
  stride_3_1 = (in4->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  aux_3_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          ((in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
            in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1]) +
           in3_data[i1 * stride_2_0 + in3->size[0] * aux_2_1]) /
          in4_data[i1 * stride_3_0 + in4->size[0] * aux_3_1];
    }
    aux_3_1 += stride_3_1;
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real32_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real32_T(&b_in1);
}

/* End of code generation (div.c) */
