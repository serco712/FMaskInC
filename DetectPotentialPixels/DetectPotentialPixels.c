/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DetectPotentialPixels.c
 *
 * Code generation for function 'DetectPotentialPixels'
 *
 */

/* Include files */
#include "DetectPotentialPixels.h"
#include "emxutil.h"
#include "types.h"
#include "NormalizaCirrusDEM.h"
#include "colon.h"
#include "div.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void binary_expand_op(emxArray_boolean_T *in1,
                             const emxArray_real_T *in2);

static void binary_expand_op_11(emxArray_boolean_T *in1, const ObjTOABT *in2);

static void binary_expand_op_12(emxArray_boolean_T *in1,
                                const emxArray_real32_T *in2,
                                const emxArray_real32_T *in3,
                                const ObjTOABT *in4);

static void binary_expand_op_2(emxArray_boolean_T *in1, const ObjTOABT *in2);

static void binary_expand_op_3(emxArray_boolean_T *in1,
                               const emxArray_real32_T *in2,
                               const emxArray_boolean_T *in3);

static void binary_expand_op_4(emxArray_real32_T *in1, const ObjTOABT *in2);

static void binary_expand_op_5(emxArray_boolean_T *in1,
                               const emxArray_real32_T *in2);

static void binary_expand_op_7(emxArray_real32_T *in1, const ObjTOABT *in2,
                               const emxArray_real32_T *in3);

static void binary_expand_op_8(emxArray_real32_T *in1, const ObjTOABT *in2,
                               const emxArray_real32_T *in3);

static void binary_expand_op_9(emxArray_real32_T *in1, const ObjTOABT *in2,
                               const emxArray_real32_T *in3);

static double rt_roundd_snf(double u);

/* Function Definitions */
static void binary_expand_op(emxArray_boolean_T *in1,
                             const emxArray_real_T *in2)
{
  emxArray_boolean_T *b_in1;
  const double *in2_data;
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
          (in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] ||
           (in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1] > 100.0));
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

static void binary_expand_op_11(emxArray_boolean_T *in1, const ObjTOABT *in2)
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
                              in2->BandBT->size[0] * aux_1_1] < 2700.0F));
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

static void binary_expand_op_12(emxArray_boolean_T *in1,
                                const emxArray_real32_T *in2,
                                const emxArray_real32_T *in3,
                                const ObjTOABT *in4)
{
  const float *in2_data;
  const float *in3_data;
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
  in3_data = in3->data;
  in2_data = in2->data;
  if (in4->BandSWIR2->size[0] == 1) {
    if (in3->size[0] == 1) {
      loop_ub = in2->size[0];
    } else {
      loop_ub = in3->size[0];
    }
  } else {
    loop_ub = in4->BandSWIR2->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  if (in4->BandSWIR2->size[1] == 1) {
    if (in3->size[1] == 1) {
      b_loop_ub = in2->size[1];
    } else {
      b_loop_ub = in3->size[1];
    }
  } else {
    b_loop_ub = in4->BandSWIR2->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  stride_2_0 = (in4->BandSWIR2->size[0] != 1);
  stride_2_1 = (in4->BandSWIR2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          ((in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] < 0.8) &&
           (in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1] < 0.8) &&
           (in4->BandSWIR2->data[i1 * stride_2_0 +
                                 in4->BandSWIR2->size[0] * aux_2_1] > 300.0F));
    }
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void binary_expand_op_2(emxArray_boolean_T *in1, const ObjTOABT *in2)
{
  emxArray_boolean_T *b_in1;
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
  boolean_T *b_in1_data;
  boolean_T *in1_data;
  in1_data = in1->data;
  emxInit_boolean_T(&b_in1, 2);
  if (in2->BandSWIR1->size[0] == 1) {
    i = in2->BandNIR->size[0];
  } else {
    i = in2->BandSWIR1->size[0];
  }
  if (i == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = i;
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->BandSWIR1->size[1] == 1) {
    i1 = in2->BandNIR->size[1];
  } else {
    i1 = in2->BandSWIR1->size[1];
  }
  if (i1 == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = i1;
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->BandNIR->size[0] != 1);
  stride_1_1 = (in2->BandNIR->size[1] != 1);
  stride_2_0 = (in2->BandSWIR1->size[0] != 1);
  stride_2_1 = (in2->BandSWIR1->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          (in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] &&
           (in2->BandNIR
                    ->data[i1 * stride_1_0 + in2->BandNIR->size[0] * aux_1_1] /
                in2->BandSWIR1->data[i1 * stride_2_0 +
                                     in2->BandSWIR1->size[0] * aux_2_1] >
            0.75F));
    }
    aux_2_1 += stride_2_1;
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

static void binary_expand_op_3(emxArray_boolean_T *in1,
                               const emxArray_real32_T *in2,
                               const emxArray_boolean_T *in3)
{
  emxArray_boolean_T *b_in1;
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
  const boolean_T *in3_data;
  boolean_T *b_in1_data;
  boolean_T *in1_data;
  in3_data = in3->data;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_boolean_T(&b_in1, 2);
  if (in3->size[0] == 1) {
    i = in2->size[0];
  } else {
    i = in3->size[0];
  }
  if (i == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = i;
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in3->size[1] == 1) {
    i1 = in2->size[1];
  } else {
    i1 = in3->size[1];
  }
  if (i1 == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = i1;
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  stride_2_0 = (in3->size[0] != 1);
  stride_2_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          (in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] &&
           ((in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1] > 0.0F) ||
            in3_data[i1 * stride_2_0 + in3->size[0] * aux_2_1]));
    }
    aux_2_1 += stride_2_1;
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

static void binary_expand_op_4(emxArray_real32_T *in1, const ObjTOABT *in2)
{
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
  if (in2->BandRed->size[0] == 1) {
    loop_ub = in2->BandBlue->size[0];
  } else {
    loop_ub = in2->BandRed->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  if (in2->BandRed->size[1] == 1) {
    b_loop_ub = in2->BandBlue->size[1];
  } else {
    b_loop_ub = in2->BandRed->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->BandBlue->size[0] != 1);
  stride_0_1 = (in2->BandBlue->size[1] != 1);
  stride_1_0 = (in2->BandRed->size[0] != 1);
  stride_1_1 = (in2->BandRed->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          (in2->BandBlue
               ->data[i1 * stride_0_0 + in2->BandBlue->size[0] * aux_0_1] -
           0.5F * in2->BandRed->data[i1 * stride_1_0 +
                                     in2->BandRed->size[0] * aux_1_1]) -
          800.0F;
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void binary_expand_op_5(emxArray_boolean_T *in1,
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
           (in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1] < 0.7));
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

static void binary_expand_op_7(emxArray_real32_T *in1, const ObjTOABT *in2,
                               const emxArray_real32_T *in3)
{
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
  if (in3->size[0] == 1) {
    loop_ub = in2->BandRed->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  if (in3->size[1] == 1) {
    b_loop_ub = in2->BandRed->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->BandRed->size[0] != 1);
  stride_0_1 = (in2->BandRed->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          in2->BandRed
              ->data[i1 * stride_0_0 + in2->BandRed->size[0] * aux_0_1] -
          in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void binary_expand_op_8(emxArray_real32_T *in1, const ObjTOABT *in2,
                               const emxArray_real32_T *in3)
{
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
  if (in3->size[0] == 1) {
    loop_ub = in2->BandGreen->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  if (in3->size[1] == 1) {
    b_loop_ub = in2->BandGreen->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->BandGreen->size[0] != 1);
  stride_0_1 = (in2->BandGreen->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          in2->BandGreen
              ->data[i1 * stride_0_0 + in2->BandGreen->size[0] * aux_0_1] -
          in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void binary_expand_op_9(emxArray_real32_T *in1, const ObjTOABT *in2,
                               const emxArray_real32_T *in3)
{
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
  if (in3->size[0] == 1) {
    loop_ub = in2->BandBlue->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  if (in3->size[1] == 1) {
    b_loop_ub = in2->BandBlue->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->BandBlue->size[0] != 1);
  stride_0_1 = (in2->BandBlue->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          in2->BandBlue
              ->data[i1 * stride_0_0 + in2->BandBlue->size[0] * aux_0_1] -
          in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

void DetectPotentialPixels(const emxArray_boolean_T *mask,
                           const ObjTOABT *data_toabt, double dem,
                           const emxArray_real32_T *ndvi,
                           const emxArray_real32_T *ndsi,
                           const emxArray_boolean_T *satu_Bv,
                           emxArray_boolean_T *idplcd,
                           emxArray_real_T *BandCirrusNormal,
                           emxArray_real32_T *whiteness, emxArray_real32_T *HOT)
{
  emxArray_boolean_T *idclr;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  emxArray_int32_T *r4;
  emxArray_real32_T *r;
  emxArray_real32_T *r2;
  emxArray_real32_T *visimean;
  emxArray_real32_T *x;
  emxArray_real_T *dem_intvl;
  double *BandCirrusNormal_data;
  double *dem_intvl_data;
  const float *ndsi_data;
  const float *ndvi_data;
  float *r1;
  float *r3;
  float *visimean_data;
  float *whiteness_data;
  float *x_data;
  int b_i;
  int c_i;
  int i;
  int i1;
  int k;
  int loop_ub_tmp;
  int nj;
  int nx;
  int pEnd;
  int qEnd;
  int *idx_data;
  int *iwork_data;
  int *r5;
  const boolean_T *mask_data;
  const boolean_T *satu_Bv_data;
  boolean_T *idclr_data;
  boolean_T *idplcd_data;
  satu_Bv_data = satu_Bv->data;
  ndsi_data = ndsi->data;
  ndvi_data = ndvi->data;
  mask_data = mask->data;
  /*  DETECTPOTENTIALCLOUD detect potential cloud pixels (PCPs) */
  /*  Cirrus Probability  This is unavailable here because some high */
  /*  mountianus have high cirrus values. */
  /*  inputs: BandSWIR2 BandBT BandBlue BandGreen BandRed BandNIR BandSWIR1 */
  /*  BandCirrus */
  /*     %% Step 1: detect possible cloud pixels (PCPs) */
  /*  [Basic cloud test] */
  if (ndsi->size[0] == 1) {
    i = ndvi->size[0];
  } else {
    i = ndsi->size[0];
  }
  if (ndsi->size[1] == 1) {
    i1 = ndvi->size[1];
  } else {
    i1 = ndsi->size[1];
  }
  if ((ndsi->size[0] == ndvi->size[0]) && (ndsi->size[1] == ndvi->size[1]) &&
      (i == data_toabt->BandSWIR2->size[0]) &&
      (i1 == data_toabt->BandSWIR2->size[1])) {
    i = idplcd->size[0] * idplcd->size[1];
    idplcd->size[0] = ndsi->size[0];
    idplcd->size[1] = ndsi->size[1];
    emxEnsureCapacity_boolean_T(idplcd, i);
    idplcd_data = idplcd->data;
    nx = ndsi->size[0] * ndsi->size[1];
    for (i = 0; i < nx; i++) {
      idplcd_data[i] = ((ndsi_data[i] < 0.8) && (ndvi_data[i] < 0.8) &&
                        (data_toabt->BandSWIR2->data[i] > 300.0F));
    }
  } else {
    binary_expand_op_12(idplcd, ndsi, ndvi, data_toabt);
    idplcd_data = idplcd->data;
  }
  /*  memory. */
  /*  when have BT data. */
  if ((data_toabt->BandBT->size[0] != 0) &&
      (data_toabt->BandBT->size[1] != 0)) {
    if ((idplcd->size[0] == data_toabt->BandBT->size[0]) &&
        (idplcd->size[1] == data_toabt->BandBT->size[1])) {
      nx = idplcd->size[0] * idplcd->size[1];
      for (i = 0; i < nx; i++) {
        idplcd_data[i] =
            (idplcd_data[i] && (data_toabt->BandBT->data[i] < 2700.0F));
      }
    } else {
      binary_expand_op_11(idplcd, data_toabt);
      idplcd_data = idplcd->data;
    }
  }
  /*  [Whiteness test] */
  /*  visible bands flatness (sum(abs)/mean < 0.6 => brigt and dark cloud ) */
  emxInit_real32_T(&visimean, 2);
  if (data_toabt->BandBlue->size[0] == 1) {
    i = data_toabt->BandGreen->size[0];
  } else {
    i = data_toabt->BandBlue->size[0];
  }
  if (data_toabt->BandBlue->size[1] == 1) {
    i1 = data_toabt->BandGreen->size[1];
  } else {
    i1 = data_toabt->BandBlue->size[1];
  }
  if ((data_toabt->BandBlue->size[0] == data_toabt->BandGreen->size[0]) &&
      (data_toabt->BandBlue->size[1] == data_toabt->BandGreen->size[1]) &&
      (i == data_toabt->BandRed->size[0]) &&
      (i1 == data_toabt->BandRed->size[1])) {
    i = visimean->size[0] * visimean->size[1];
    visimean->size[0] = data_toabt->BandBlue->size[0];
    visimean->size[1] = data_toabt->BandBlue->size[1];
    emxEnsureCapacity_real32_T(visimean, i);
    visimean_data = visimean->data;
    nx = data_toabt->BandBlue->size[0] * data_toabt->BandBlue->size[1];
    for (i = 0; i < nx; i++) {
      visimean_data[i] =
          ((data_toabt->BandBlue->data[i] + data_toabt->BandGreen->data[i]) +
           data_toabt->BandRed->data[i]) /
          3.0F;
    }
  } else {
    binary_expand_op_10(visimean, data_toabt);
    visimean_data = visimean->data;
  }
  emxInit_real32_T(&x, 2);
  if ((data_toabt->BandBlue->size[0] == visimean->size[0]) &&
      (data_toabt->BandBlue->size[1] == visimean->size[1])) {
    i = x->size[0] * x->size[1];
    x->size[0] = data_toabt->BandBlue->size[0];
    x->size[1] = data_toabt->BandBlue->size[1];
    emxEnsureCapacity_real32_T(x, i);
    x_data = x->data;
    nx = data_toabt->BandBlue->size[0] * data_toabt->BandBlue->size[1];
    for (i = 0; i < nx; i++) {
      x_data[i] = data_toabt->BandBlue->data[i] - visimean_data[i];
    }
  } else {
    binary_expand_op_9(x, data_toabt, visimean);
    x_data = x->data;
  }
  nx = x->size[0] * x->size[1];
  i = whiteness->size[0] * whiteness->size[1];
  whiteness->size[0] = x->size[0];
  whiteness->size[1] = x->size[1];
  emxEnsureCapacity_real32_T(whiteness, i);
  whiteness_data = whiteness->data;
  for (k = 0; k < nx; k++) {
    whiteness_data[k] = fabsf(x_data[k]);
  }
  if ((data_toabt->BandGreen->size[0] == visimean->size[0]) &&
      (data_toabt->BandGreen->size[1] == visimean->size[1])) {
    i = x->size[0] * x->size[1];
    x->size[0] = data_toabt->BandGreen->size[0];
    x->size[1] = data_toabt->BandGreen->size[1];
    emxEnsureCapacity_real32_T(x, i);
    x_data = x->data;
    nx = data_toabt->BandGreen->size[0] * data_toabt->BandGreen->size[1];
    for (i = 0; i < nx; i++) {
      x_data[i] = data_toabt->BandGreen->data[i] - visimean_data[i];
    }
  } else {
    binary_expand_op_8(x, data_toabt, visimean);
    x_data = x->data;
  }
  nx = x->size[0] * x->size[1];
  emxInit_real32_T(&r, 2);
  i = r->size[0] * r->size[1];
  r->size[0] = x->size[0];
  r->size[1] = x->size[1];
  emxEnsureCapacity_real32_T(r, i);
  r1 = r->data;
  for (k = 0; k < nx; k++) {
    r1[k] = fabsf(x_data[k]);
  }
  if ((data_toabt->BandRed->size[0] == visimean->size[0]) &&
      (data_toabt->BandRed->size[1] == visimean->size[1])) {
    i = x->size[0] * x->size[1];
    x->size[0] = data_toabt->BandRed->size[0];
    x->size[1] = data_toabt->BandRed->size[1];
    emxEnsureCapacity_real32_T(x, i);
    x_data = x->data;
    nx = data_toabt->BandRed->size[0] * data_toabt->BandRed->size[1];
    for (i = 0; i < nx; i++) {
      x_data[i] = data_toabt->BandRed->data[i] - visimean_data[i];
    }
  } else {
    binary_expand_op_7(x, data_toabt, visimean);
    x_data = x->data;
  }
  nx = x->size[0] * x->size[1];
  emxInit_real32_T(&r2, 2);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = x->size[0];
  r2->size[1] = x->size[1];
  emxEnsureCapacity_real32_T(r2, i);
  r3 = r2->data;
  for (k = 0; k < nx; k++) {
    r3[k] = fabsf(x_data[k]);
  }
  emxFree_real32_T(&x);
  if (whiteness->size[0] == 1) {
    i = r->size[0];
  } else {
    i = whiteness->size[0];
  }
  if (whiteness->size[1] == 1) {
    i1 = r->size[1];
  } else {
    i1 = whiteness->size[1];
  }
  if (i == 1) {
    nx = r2->size[0];
  } else {
    nx = i;
  }
  if (i1 == 1) {
    loop_ub_tmp = r2->size[1];
  } else {
    loop_ub_tmp = i1;
  }
  if ((whiteness->size[0] == r->size[0]) &&
      (whiteness->size[1] == r->size[1]) && (i == r2->size[0]) &&
      (i1 == r2->size[1]) && (nx == visimean->size[0]) &&
      (loop_ub_tmp == visimean->size[1])) {
    nx = whiteness->size[0] * whiteness->size[1];
    for (i = 0; i < nx; i++) {
      whiteness_data[i] =
          ((whiteness_data[i] + r1[i]) + r3[i]) / visimean_data[i];
    }
  } else {
    binary_expand_op_6(whiteness, r, r2, visimean);
    whiteness_data = whiteness->data;
  }
  emxFree_real32_T(&r2);
  emxFree_real32_T(&r);
  emxFree_real32_T(&visimean);
  /*  update idplcd */
  emxInit_boolean_T(&idclr, 2);
  i = idclr->size[0] * idclr->size[1];
  idclr->size[0] = satu_Bv->size[0];
  idclr->size[1] = satu_Bv->size[1];
  emxEnsureCapacity_boolean_T(idclr, i);
  idclr_data = idclr->data;
  loop_ub_tmp = satu_Bv->size[0] * satu_Bv->size[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    idclr_data[i] = satu_Bv_data[i];
  }
  nj = loop_ub_tmp - 1;
  for (b_i = 0; b_i <= nj; b_i++) {
    if (idclr_data[b_i]) {
      whiteness_data[b_i] = 0.0F;
    }
  }
  /*  If one visible is saturated whiteness == 0 */
  if ((idplcd->size[0] == whiteness->size[0]) &&
      (idplcd->size[1] == whiteness->size[1])) {
    nx = idplcd->size[0] * idplcd->size[1];
    for (i = 0; i < nx; i++) {
      idplcd_data[i] = (idplcd_data[i] && (whiteness_data[i] < 0.7));
    }
  } else {
    binary_expand_op_5(idplcd, whiteness);
    idplcd_data = idplcd->data;
  }
  /*  [Haze test] */
  if ((data_toabt->BandBlue->size[0] == data_toabt->BandRed->size[0]) &&
      (data_toabt->BandBlue->size[1] == data_toabt->BandRed->size[1])) {
    i = HOT->size[0] * HOT->size[1];
    HOT->size[0] = data_toabt->BandBlue->size[0];
    HOT->size[1] = data_toabt->BandBlue->size[1];
    emxEnsureCapacity_real32_T(HOT, i);
    visimean_data = HOT->data;
    nx = data_toabt->BandBlue->size[0] * data_toabt->BandBlue->size[1];
    for (i = 0; i < nx; i++) {
      visimean_data[i] = (data_toabt->BandBlue->data[i] -
                          0.5F * data_toabt->BandRed->data[i]) -
                         800.0F;
    }
  } else {
    binary_expand_op_4(HOT, data_toabt);
    visimean_data = HOT->data;
  }
  /*  Haze test */
  if (HOT->size[0] == 1) {
    i = idclr->size[0];
  } else {
    i = HOT->size[0];
  }
  if (HOT->size[1] == 1) {
    i1 = idclr->size[1];
  } else {
    i1 = HOT->size[1];
  }
  if ((HOT->size[0] == idclr->size[0]) && (HOT->size[1] == idclr->size[1]) &&
      (idplcd->size[0] == i) && (idplcd->size[1] == i1)) {
    nx = idplcd->size[0] * idplcd->size[1];
    for (i = 0; i < nx; i++) {
      idplcd_data[i] =
          (idplcd_data[i] && ((visimean_data[i] > 0.0F) || idclr_data[i]));
    }
  } else {
    binary_expand_op_3(idplcd, HOT, idclr);
    idplcd_data = idplcd->data;
  }
  /*  need to find thick warm cloud */
  /*  [Ratio4/5>0.75 cloud test] */
  if (data_toabt->BandNIR->size[0] == 1) {
    i = data_toabt->BandSWIR1->size[0];
  } else {
    i = data_toabt->BandNIR->size[0];
  }
  if (data_toabt->BandNIR->size[1] == 1) {
    i1 = data_toabt->BandSWIR1->size[1];
  } else {
    i1 = data_toabt->BandNIR->size[1];
  }
  if ((data_toabt->BandNIR->size[0] == data_toabt->BandSWIR1->size[0]) &&
      (data_toabt->BandNIR->size[1] == data_toabt->BandSWIR1->size[1]) &&
      (idplcd->size[0] == i) && (idplcd->size[1] == i1)) {
    nx = idplcd->size[0] * idplcd->size[1];
    for (i = 0; i < nx; i++) {
      idplcd_data[i] = (idplcd_data[i] && (data_toabt->BandNIR->data[i] /
                                               data_toabt->BandSWIR1->data[i] >
                                           0.75F));
    }
  } else {
    binary_expand_op_2(idplcd, data_toabt);
    idplcd_data = idplcd->data;
  }
  BandCirrusNormal->size[0] = 0;
  BandCirrusNormal->size[1] = 0;
  /*  normalize Cirrus band [Cirrus test] from Landsat 8 and Sentinel 2 images
   */
  if ((data_toabt->BandCirrus->size[0] != 0) &&
      (data_toabt->BandCirrus->size[1] != 0)) {
    double a;
    double b_r;
    float cirrus_lowest;
    /* NORMALIZACIRRUSDEM normalize Cirrus band using most dark object at Cirrus
     */
    /* band based on DEMs. */
    i = BandCirrusNormal->size[0] * BandCirrusNormal->size[1];
    BandCirrusNormal->size[0] = data_toabt->BandCirrus->size[0];
    BandCirrusNormal->size[1] = data_toabt->BandCirrus->size[1];
    emxEnsureCapacity_real_T(BandCirrusNormal, i);
    BandCirrusNormal_data = BandCirrusNormal->data;
    loop_ub_tmp =
        data_toabt->BandCirrus->size[0] * data_toabt->BandCirrus->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      BandCirrusNormal_data[i] = 0.0;
    }
    if ((idplcd->size[0] == mask->size[0]) &&
        (idplcd->size[1] == mask->size[1])) {
      i = idclr->size[0] * idclr->size[1];
      idclr->size[0] = idplcd->size[0];
      idclr->size[1] = idplcd->size[1];
      emxEnsureCapacity_boolean_T(idclr, i);
      idclr_data = idclr->data;
      nx = idplcd->size[0] * idplcd->size[1];
      for (i = 0; i < nx; i++) {
        idclr_data[i] = ((!idplcd_data[i]) && mask_data[i]);
      }
    } else {
      binary_expand_op_1(idclr, idplcd, mask);
      idclr_data = idclr->data;
    }
    /*  clear sky pixels */
    nx = mask->size[0] * mask->size[1] - 1;
    pEnd = 0;
    for (b_i = 0; b_i <= nx; b_i++) {
      if (mask_data[b_i]) {
        pEnd++;
      }
    }
    if (pEnd == 0) {
      a = rtNaN;
    } else {
      nj = 0;
      for (b_i = 0; b_i <= nx; b_i++) {
        if (mask_data[b_i]) {
          nj++;
        }
      }
      while ((nj > 0) && rtIsNaN(dem)) {
        nj--;
      }
      if (nj < 1) {
        a = rtNaN;
      } else if (nj == 1) {
        a = dem;
      } else {
        b_r = 1.0E-5 * (double)nj;
        b_i = (int)rt_roundd_snf(b_r);
        if (b_i < 1) {
          a = dem;
        } else if (b_i >= nj) {
          a = dem;
        } else {
          b_r -= (double)b_i;
          a = (0.5 - b_r) * dem + (b_r + 0.5) * dem;
        }
      }
    }
    pEnd = 0;
    for (b_i = 0; b_i <= nx; b_i++) {
      if (mask_data[b_i]) {
        pEnd++;
      }
    }
    if (pEnd == 0) {
      b_r = rtNaN;
    } else {
      nj = 0;
      for (b_i = 0; b_i <= nx; b_i++) {
        if (mask_data[b_i]) {
          nj++;
        }
      }
      while ((nj > 0) && rtIsNaN(dem)) {
        nj--;
      }
      if (nj < 1) {
        b_r = rtNaN;
      } else if (nj == 1) {
        b_r = dem;
      } else {
        b_r = 0.99998999999999993 * (double)nj;
        b_i = (int)rt_roundd_snf(b_r);
        if (b_i >= nj) {
          b_r = dem;
        } else {
          b_r -= (double)b_i;
          b_r = (0.5 - b_r) * dem + (b_r + 0.5) * dem;
        }
      }
    }
    /*  further exclude errors in DEM. */
    emxInit_real_T(&dem_intvl, 2);
    dem_intvl_data = dem_intvl->data;
    if (rtIsNaN(a) || rtIsNaN(b_r)) {
      i = dem_intvl->size[0] * dem_intvl->size[1];
      dem_intvl->size[0] = 1;
      dem_intvl->size[1] = 1;
      emxEnsureCapacity_real_T(dem_intvl, i);
      dem_intvl_data = dem_intvl->data;
      dem_intvl_data[0] = rtNaN;
    } else if (b_r < a) {
      dem_intvl->size[0] = 1;
      dem_intvl->size[1] = 0;
    } else if ((rtIsInf(a) || rtIsInf(b_r)) && (a == b_r)) {
      i = dem_intvl->size[0] * dem_intvl->size[1];
      dem_intvl->size[0] = 1;
      dem_intvl->size[1] = 1;
      emxEnsureCapacity_real_T(dem_intvl, i);
      dem_intvl_data = dem_intvl->data;
      dem_intvl_data[0] = rtNaN;
    } else if (floor(a) == a) {
      i = dem_intvl->size[0] * dem_intvl->size[1];
      dem_intvl->size[0] = 1;
      nx = (int)((b_r - a) / 100.0);
      dem_intvl->size[1] = nx + 1;
      emxEnsureCapacity_real_T(dem_intvl, i);
      dem_intvl_data = dem_intvl->data;
      for (i = 0; i <= nx; i++) {
        dem_intvl_data[i] = a + 100.0 * (double)i;
      }
    } else {
      eml_float_colon(a, b_r, dem_intvl);
      dem_intvl_data = dem_intvl->data;
    }
    cirrus_lowest = 0.0F;
    i = dem_intvl->size[1];
    emxInit_int32_T(&r4);
    emxInit_int32_T(&idx);
    emxInit_int32_T(&iwork);
    for (b_i = 0; b_i < i; b_i++) {
      boolean_T ids_inter;
      /*  the dem intervals. */
      if (b_i + 1 == dem_intvl->size[1]) {
        ids_inter = (dem > dem_intvl_data[b_i] - 50.0);
      } else if (b_i + 1 == 1) {
        ids_inter = (dem < dem_intvl_data[0] + 50.0);
      } else {
        ids_inter = ((dem > dem_intvl_data[b_i] - 50.0) &&
                     (dem < dem_intvl_data[b_i] + 50.0));
      }
      /*  we think more than 50 pixels show meaningfull calculation. */
      /*  at the same time, cirrus TOA will be substracted from the */
      /*  previous lowest cirrus of clear pixels. */
      nx = idclr->size[0] * idclr->size[1];
      if (nx == 0) {
        nj = 0;
      } else {
        nj = (ids_inter && idclr_data[0]);
        for (k = 2; k <= nx; k++) {
          nj += (ids_inter && idclr_data[k - 1]);
        }
      }
      if (nj > 0) {
        nj = nx - 1;
        pEnd = 0;
        for (c_i = 0; c_i <= nj; c_i++) {
          if (ids_inter && idclr_data[c_i]) {
            pEnd++;
          }
        }
        i1 = r4->size[0];
        r4->size[0] = pEnd;
        emxEnsureCapacity_int32_T(r4, i1);
        r5 = r4->data;
        nx = 0;
        for (c_i = 0; c_i <= nj; c_i++) {
          if (ids_inter && idclr_data[c_i]) {
            r5[nx] = c_i;
            nx++;
          }
        }
        if (r4->size[0] == 0) {
          cirrus_lowest = rtNaNF;
        } else {
          int n;
          n = r4->size[0] + 1;
          i1 = idx->size[0];
          idx->size[0] = r4->size[0];
          emxEnsureCapacity_int32_T(idx, i1);
          idx_data = idx->data;
          nx = r4->size[0];
          for (i1 = 0; i1 < nx; i1++) {
            idx_data[i1] = 0;
          }
          i1 = iwork->size[0];
          iwork->size[0] = r4->size[0];
          emxEnsureCapacity_int32_T(iwork, i1);
          iwork_data = iwork->data;
          i1 = r4->size[0] - 1;
          for (k = 1; k <= i1; k += 2) {
            cirrus_lowest = data_toabt->BandCirrus->data[r5[k]];
            if ((data_toabt->BandCirrus->data[r5[k - 1]] <= cirrus_lowest) ||
                rtIsNaNF(cirrus_lowest)) {
              idx_data[k - 1] = k;
              idx_data[k] = k + 1;
            } else {
              idx_data[k - 1] = k + 1;
              idx_data[k] = k;
            }
          }
          if ((r4->size[0] & 1) != 0) {
            idx_data[r4->size[0] - 1] = r4->size[0];
          }
          c_i = 2;
          while (c_i < n - 1) {
            nx = c_i << 1;
            nj = 1;
            for (pEnd = c_i + 1; pEnd < n; pEnd = qEnd + c_i) {
              int kEnd;
              int p;
              int q;
              p = nj;
              q = pEnd - 1;
              qEnd = nj + nx;
              if (qEnd > n) {
                qEnd = n;
              }
              k = 0;
              kEnd = qEnd - nj;
              while (k + 1 <= kEnd) {
                cirrus_lowest =
                    data_toabt->BandCirrus->data[r5[idx_data[q] - 1]];
                i1 = idx_data[p - 1];
                if ((data_toabt->BandCirrus->data[r5[i1 - 1]] <=
                     cirrus_lowest) ||
                    rtIsNaNF(cirrus_lowest)) {
                  iwork_data[k] = i1;
                  p++;
                  if (p == pEnd) {
                    while (q + 1 < qEnd) {
                      k++;
                      iwork_data[k] = idx_data[q];
                      q++;
                    }
                  }
                } else {
                  iwork_data[k] = idx_data[q];
                  q++;
                  if (q + 1 == qEnd) {
                    while (p < pEnd) {
                      k++;
                      iwork_data[k] = idx_data[p - 1];
                      p++;
                    }
                  }
                }
                k++;
              }
              for (k = 0; k < kEnd; k++) {
                idx_data[(nj + k) - 1] = iwork_data[k];
              }
              nj = qEnd;
            }
            c_i = nx;
          }
          nj = r4->size[0];
          while ((nj > 0) &&
                 rtIsNaNF(
                     data_toabt->BandCirrus->data[r5[idx_data[nj - 1] - 1]])) {
            nj--;
          }
          if (nj < 1) {
            cirrus_lowest = rtNaNF;
          } else if (nj == 1) {
            cirrus_lowest = data_toabt->BandCirrus->data[r5[idx_data[0] - 1]];
          } else {
            b_r = 0.02 * (double)nj;
            c_i = (int)rt_roundd_snf(b_r);
            if (c_i < 1) {
              cirrus_lowest = data_toabt->BandCirrus->data[r5[idx_data[0] - 1]];
            } else if (c_i >= nj) {
              cirrus_lowest =
                  data_toabt->BandCirrus->data[r5[idx_data[nj - 1] - 1]];
            } else {
              b_r -= (double)c_i;
              cirrus_lowest =
                  (float)(0.5 - b_r) *
                      data_toabt->BandCirrus->data[r5[idx_data[c_i - 1] - 1]] +
                  (float)(b_r + 0.5) *
                      data_toabt->BandCirrus->data[r5[idx_data[c_i] - 1]];
            }
          }
        }
      }
      if (ids_inter) {
        BandCirrusNormal_data[0] =
            data_toabt->BandCirrus->data[0] - cirrus_lowest;
      }
    }
    emxFree_int32_T(&iwork);
    emxFree_int32_T(&idx);
    emxFree_int32_T(&r4);
    emxFree_real_T(&dem_intvl);
    /*  %          % when no DEMs, we also adjust the cirrus TOA to be around 0,
     */
    /*  %          % based on the full lowest cirrus value. */
    /*  %         cirrus_noml(~dem_have)=cirrus(~dem_have)-cirrus_lowest_al; */
    /*  the normalized cirrus value will be set as 0 when it is negative. */
    nj = loop_ub_tmp - 1;
    for (b_i = 0; b_i <= nj; b_i++) {
      if (BandCirrusNormal_data[b_i] < 0.0) {
        BandCirrusNormal_data[b_i] = 0.0;
      }
    }
    /*          BandCirrusNormal= data_toabt.BandCirrus; */
    if ((idplcd->size[0] == BandCirrusNormal->size[0]) &&
        (idplcd->size[1] == BandCirrusNormal->size[1])) {
      nx = idplcd->size[0] * idplcd->size[1];
      for (i = 0; i < nx; i++) {
        idplcd_data[i] = (idplcd_data[i] || (BandCirrusNormal_data[i] > 100.0));
      }
    } else {
      binary_expand_op(idplcd, BandCirrusNormal);
    }
    /*  When TOA at Cirrus band is more than 0.01, it may be cloudy. */
  }
  emxFree_boolean_T(&idclr);
}

/* End of code generation (DetectPotentialPixels.c) */
