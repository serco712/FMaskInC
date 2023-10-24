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
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"

/* Function Definitions */
void binary_expand_op_16(emxArray_int8_T *in1, const ObjTOABT *in2)
{
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
  signed char *in1_data;
  if (in2->SatuGreen->size[0] == 1) {
    loop_ub = in2->SatuBlue->size[0];
  } else {
    loop_ub = in2->SatuGreen->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_int8_T(in1, i);
  if (in2->SatuGreen->size[1] == 1) {
    b_loop_ub = in2->SatuBlue->size[1];
  } else {
    b_loop_ub = in2->SatuGreen->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_int8_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->SatuBlue->size[0] != 1);
  stride_0_1 = (in2->SatuBlue->size[1] != 1);
  stride_1_0 = (in2->SatuGreen->size[0] != 1);
  stride_1_1 = (in2->SatuGreen->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          (signed char)(in2->SatuBlue->data[i1 * stride_0_0 +
                                            in2->SatuBlue->size[0] * aux_0_1] +
                        in2->SatuGreen
                            ->data[i1 * stride_1_0 +
                                   in2->SatuGreen->size[0] * aux_1_1]);
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

/* End of code generation (Saturate.c) */
