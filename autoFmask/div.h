/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * div.h
 *
 * Code generation for function 'div'
 *
 */

#ifndef DIV_H
#define DIV_H

/* Include files */
#include "autoFmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void binary_expand_op_10(emxArray_real32_T *in1, const ObjTOABT *in2);

void binary_expand_op_17(emxArray_real32_T *in1, const ObjTOABT *in2,
                         const emxArray_real32_T *in3);

void binary_expand_op_19(emxArray_real32_T *in1, const ObjTOABT *in2,
                         const emxArray_real32_T *in3);

void binary_expand_op_6(emxArray_real32_T *in1, const emxArray_real32_T *in2,
                        const emxArray_real32_T *in3,
                        const emxArray_real32_T *in4);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (div.h) */
