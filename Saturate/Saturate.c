/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Saturate.c
 *
 * Code generation for function 'Saturate'
 *
 */

/* Include files */
#include "Saturate.h"
#include "emxutil.h"
#include "types.h"

/* Function Declarations */
static void binary_expand_op(emxArray_boolean_T *in1,
                             const emxArray_boolean_T *in2,
                             const emxArray_boolean_T *in3,
                             const emxArray_boolean_T *in4);

/* Function Definitions */
static void binary_expand_op(emxArray_boolean_T *in1,
                             const emxArray_boolean_T *in2,
                             const emxArray_boolean_T *in3,
                             const emxArray_boolean_T *in4)
{
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
  const boolean_T *in2_data;
  const boolean_T *in3_data;
  const boolean_T *in4_data;
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
          ((in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] +
            in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1]) +
               in4_data[i1 * stride_2_0 + in4->size[0] * aux_2_1] >=
           1);
    }
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

void Saturate(const emxArray_boolean_T *satu_blue,
              const emxArray_boolean_T *satu_green,
              const emxArray_boolean_T *satu_red, emxArray_boolean_T *satu_Bv)
{
  int i;
  int loop_ub;
  const boolean_T *satu_blue_data;
  const boolean_T *satu_green_data;
  const boolean_T *satu_red_data;
  boolean_T *satu_Bv_data;
  satu_red_data = satu_red->data;
  satu_green_data = satu_green->data;
  satu_blue_data = satu_blue->data;
  /* SATURE Summary of this function goes here */
  /*    Detailed explanation goes here */
  if (satu_blue->size[0] == 1) {
    i = satu_green->size[0];
  } else {
    i = satu_blue->size[0];
  }
  if (satu_blue->size[1] == 1) {
    loop_ub = satu_green->size[1];
  } else {
    loop_ub = satu_blue->size[1];
  }
  if ((satu_blue->size[0] == satu_green->size[0]) &&
      (satu_blue->size[1] == satu_green->size[1]) && (i == satu_red->size[0]) &&
      (loop_ub == satu_red->size[1])) {
    i = satu_Bv->size[0] * satu_Bv->size[1];
    satu_Bv->size[0] = satu_blue->size[0];
    satu_Bv->size[1] = satu_blue->size[1];
    emxEnsureCapacity_boolean_T(satu_Bv, i);
    satu_Bv_data = satu_Bv->data;
    loop_ub = satu_blue->size[0] * satu_blue->size[1];
    for (i = 0; i < loop_ub; i++) {
      satu_Bv_data[i] =
          ((satu_blue_data[i] + satu_green_data[i]) + satu_red_data[i] >= 1);
    }
  } else {
    binary_expand_op(satu_Bv, satu_blue, satu_green, satu_red);
  }
  /*  saturated pixes at any visible bands. */
}

/* End of code generation (Saturate.c) */
