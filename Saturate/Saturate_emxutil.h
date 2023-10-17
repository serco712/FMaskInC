/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Saturate_emxutil.h
 *
 * Code generation for function 'Saturate_emxutil'
 *
 */

#ifndef SATURATE_EMXUTIL_H
#define SATURATE_EMXUTIL_H

/* Include files */
#include "Saturate_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
                                        int oldNumel);

extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray,
                              int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (Saturate_emxutil.h) */