/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DetectPotentialPixels.h
 *
 * Code generation for function 'DetectPotentialPixels'
 *
 */

#ifndef DETECTPOTENTIALPIXELS_H
#define DETECTPOTENTIALPIXELS_H

/* Include files */
#include "autoFmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void binary_expand_op_1(emxArray_boolean_T *in1, const ObjTOABT *in2);

void binary_expand_op_11(emxArray_boolean_T *in1, const ObjTOABT *in2);

void binary_expand_op_12(emxArray_boolean_T *in1, const emxArray_real32_T *in2,
                         const emxArray_real32_T *in3, const ObjTOABT *in4);

void binary_expand_op_2(emxArray_boolean_T *in1, const emxArray_real32_T *in2,
                        const emxArray_boolean_T *in3);

void binary_expand_op_3(emxArray_real32_T *in1, const ObjTOABT *in2);

void binary_expand_op_4(emxArray_boolean_T *in1, const emxArray_real32_T *in2);

void binary_expand_op_5(emxArray_boolean_T *in1, const emxArray_int8_T *in2,
                        const ObjTOABT *in3);

void binary_expand_op_7(emxArray_real32_T *in1, const ObjTOABT *in2,
                        const emxArray_real32_T *in3);

void binary_expand_op_8(emxArray_real32_T *in1, const ObjTOABT *in2,
                        const emxArray_real32_T *in3);

void binary_expand_op_9(emxArray_real32_T *in1, const ObjTOABT *in2,
                        const emxArray_real32_T *in3);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (DetectPotentialPixels.h) */
