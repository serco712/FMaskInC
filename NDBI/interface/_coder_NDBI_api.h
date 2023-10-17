/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_NDBI_api.h
 *
 * Code generation for function 'NDBI'
 *
 */

#ifndef _CODER_NDBI_API_H
#define _CODER_NDBI_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T
struct emxArray_real32_T {
  real32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real32_T */
#ifndef typedef_emxArray_real32_T
#define typedef_emxArray_real32_T
typedef struct emxArray_real32_T emxArray_real32_T;
#endif /* typedef_emxArray_real32_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void NDBI(emxArray_real32_T *nir, emxArray_real32_T *swir,
          emxArray_real32_T *ndbi);

void NDBI_api(const mxArray *const prhs[2], const mxArray **plhs);

void NDBI_atexit(void);

void NDBI_initialize(void);

void NDBI_terminate(void);

void NDBI_xil_shutdown(void);

void NDBI_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_NDBI_api.h) */
