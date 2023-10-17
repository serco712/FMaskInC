/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_NDSI_api.h
 *
 * Code generation for function 'NDSI'
 *
 */

#ifndef _CODER_NDSI_API_H
#define _CODER_NDSI_API_H

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
void NDSI(emxArray_real32_T *green, emxArray_real32_T *swir,
          emxArray_real32_T *ndsi);

void NDSI_api(const mxArray *const prhs[2], const mxArray **plhs);

void NDSI_atexit(void);

void NDSI_initialize(void);

void NDSI_terminate(void);

void NDSI_xil_shutdown(void);

void NDSI_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_NDSI_api.h) */
