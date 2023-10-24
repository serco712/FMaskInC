/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * autoFmask_emxAPI.h
 *
 * Code generation for function 'autoFmask_emxAPI'
 *
 */

#ifndef AUTOFMASK_EMXAPI_H
#define AUTOFMASK_EMXAPI_H

/* Include files */
#include "autoFmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern emxArray_boolean_T *emxCreateND_boolean_T(int numDimensions,
                                                 const int *size);

extern emxArray_char_T *emxCreateND_char_T(int numDimensions, const int *size);

extern emxArray_real32_T *emxCreateND_real32_T(int numDimensions,
                                               const int *size);

extern emxArray_boolean_T *emxCreateWrapperND_boolean_T(boolean_T *data,
                                                        int numDimensions,
                                                        const int *size);

extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
                                                  const int *size);

extern emxArray_real32_T *
emxCreateWrapperND_real32_T(float *data, int numDimensions, const int *size);

extern emxArray_boolean_T *emxCreateWrapper_boolean_T(boolean_T *data, int rows,
                                                      int cols);

extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);

extern emxArray_real32_T *emxCreateWrapper_real32_T(float *data, int rows,
                                                    int cols);

extern emxArray_boolean_T *emxCreate_boolean_T(int rows, int cols);

extern emxArray_char_T *emxCreate_char_T(int rows, int cols);

extern emxArray_real32_T *emxCreate_real32_T(int rows, int cols);

extern void emxDestroyArray_boolean_T(emxArray_boolean_T *emxArray);

extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);

extern void emxDestroyArray_real32_T(emxArray_real32_T *emxArray);

extern void emxDestroy_ObjMeta(ObjMeta emxArray);

extern void emxDestroy_ObjTOABT(ObjTOABT emxArray);

extern void emxInitArray_real32_T(emxArray_real32_T **pEmxArray,
                                  int numDimensions);

extern void emxInit_ObjMeta(ObjMeta *pStruct);

extern void emxInit_ObjTOABT(ObjTOABT *pStruct);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (autoFmask_emxAPI.h) */
