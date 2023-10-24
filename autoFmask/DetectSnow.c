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
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"

/* Function Definitions */
void binary_expand_op_14(emxArray_boolean_T *in1, const ObjTOABT *in2)
{
  emxArray_boolean_T *b_in1;
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
  in1_data = in1->data;
  emxInit_boolean_T(&b_in1, 2);
  if (in2->BandBT->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->BandBT->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->BandBT->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->BandBT->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->BandBT->size[0] != 1);
  stride_1_1 = (in2->BandBT->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          (in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] &&
           (in2->BandBT->data[i1 * stride_1_0 +
                              in2->BandBT->size[0] * aux_1_1] < 1000.0F));
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

void binary_expand_op_15(emxArray_boolean_T *in1, const emxArray_real32_T *in2,
                         const ObjTOABT *in3)
{
  const float *in2_data;
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
  in2_data = in2->data;
  if (in3->BandGreen->size[0] == 1) {
    if (in3->BandNIR->size[0] == 1) {
      loop_ub = in2->size[0];
    } else {
      loop_ub = in3->BandNIR->size[0];
    }
  } else {
    loop_ub = in3->BandGreen->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  if (in3->BandGreen->size[1] == 1) {
    if (in3->BandNIR->size[1] == 1) {
      b_loop_ub = in2->size[1];
    } else {
      b_loop_ub = in3->BandNIR->size[1];
    }
  } else {
    b_loop_ub = in3->BandGreen->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->BandNIR->size[0] != 1);
  stride_1_1 = (in3->BandNIR->size[1] != 1);
  stride_2_0 = (in3->BandGreen->size[0] != 1);
  stride_2_1 = (in3->BandGreen->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          ((in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] > 0.15) &&
           (in3->BandNIR->data[i1 * stride_1_0 +
                               in3->BandNIR->size[0] * aux_1_1] > 1100.0F) &&
           (in3->BandGreen->data[i1 * stride_2_0 +
                                 in3->BandGreen->size[0] * aux_2_1] > 1000.0F));
    }
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

/* End of code generation (DetectSnow.c) */
