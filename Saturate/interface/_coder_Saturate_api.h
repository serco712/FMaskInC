/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Saturate_api.h
 *
 * Code generation for function 'Saturate'
 *
 */

#ifndef _CODER_SATURATE_API_H
#define _CODER_SATURATE_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_boolean_T */
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /* typedef_emxArray_boolean_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void Saturate(emxArray_boolean_T *satu_blue, emxArray_boolean_T *satu_green,
              emxArray_boolean_T *satu_red, emxArray_boolean_T *satu_Bv);

void Saturate_api(const mxArray *const prhs[3], const mxArray **plhs);

void Saturate_atexit(void);

void Saturate_initialize(void);

void Saturate_terminate(void);

void Saturate_xil_shutdown(void);

void Saturate_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_Saturate_api.h) */
