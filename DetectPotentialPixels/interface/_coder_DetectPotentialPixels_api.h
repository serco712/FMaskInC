/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_DetectPotentialPixels_api.h
 *
 * Code generation for function 'DetectPotentialPixels'
 *
 */

#ifndef _CODER_DETECTPOTENTIALPIXELS_API_H
#define _CODER_DETECTPOTENTIALPIXELS_API_H

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

#ifndef typedef_ObjTOABT
#define typedef_ObjTOABT
typedef struct {
  emxArray_real32_T *BandCA;
  emxArray_real32_T *BandBlue;
  emxArray_real32_T *BandGreen;
  emxArray_real32_T *BandRed;
  emxArray_real32_T *BandVRE1;
  emxArray_real32_T *BandVRE2;
  emxArray_real32_T *BandVRE3;
  emxArray_real32_T *BandNIR8;
  emxArray_real32_T *BandNIR;
  emxArray_real32_T *BandWV;
  emxArray_real32_T *BandCirrus;
  emxArray_real32_T *BandSWIR1;
  emxArray_real32_T *BandSWIR2;
  emxArray_real32_T *BandBT;
  emxArray_boolean_T *SatuBlue;
  emxArray_boolean_T *SatuGreen;
  emxArray_boolean_T *SatuRed;
} ObjTOABT;
#endif /* typedef_ObjTOABT */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void DetectPotentialPixels(emxArray_boolean_T *mask, ObjTOABT *data_toabt,
                           real_T dem, emxArray_real32_T *ndvi,
                           emxArray_real32_T *ndsi, emxArray_boolean_T *satu_Bv,
                           emxArray_boolean_T *idplcd,
                           emxArray_real_T *BandCirrusNormal,
                           emxArray_real32_T *whiteness,
                           emxArray_real32_T *HOT);

void DetectPotentialPixels_api(const mxArray *const prhs[6], int32_T nlhs,
                               const mxArray *plhs[4]);

void DetectPotentialPixels_atexit(void);

void DetectPotentialPixels_initialize(void);

void DetectPotentialPixels_terminate(void);

void DetectPotentialPixels_xil_shutdown(void);

void DetectPotentialPixels_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_DetectPotentialPixels_api.h) */
