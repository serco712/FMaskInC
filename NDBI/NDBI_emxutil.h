/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NDBI_emxutil.h
 *
 * Code generation for function 'NDBI_emxutil'
 *
 */

#ifndef NDBI_EMXUTIL_H
#define NDBI_EMXUTIL_H

/* Include files */
#include "NDBI_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_real32_T(emxArray_real32_T *emxArray,
                                       int oldNumel);

extern void emxFree_real32_T(emxArray_real32_T **pEmxArray);

extern void emxInit_real32_T(emxArray_real32_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (NDBI_emxutil.h) */
