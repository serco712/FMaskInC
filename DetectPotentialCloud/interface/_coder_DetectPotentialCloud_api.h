/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_DetectPotentialCloud_api.h
 *
 * Code generation for function 'DetectPotentialCloud'
 *
 */

#ifndef _CODER_DETECTPOTENTIALCLOUD_API_H
#define _CODER_DETECTPOTENTIALCLOUD_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T
struct emxArray_char_T {
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_char_T */
#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T
typedef struct emxArray_char_T emxArray_char_T;
#endif /* typedef_emxArray_char_T */

#ifndef typedef_ObjMeta
#define typedef_ObjMeta
typedef struct {
  emxArray_char_T *Name;
  emxArray_char_T *Sensor;
  real_T Resolution[4];
  real_T Dim[2];
  real_T UL[2];
  real_T Zen;
  real_T Azi;
  real_T ZC[2];
  real_T BBox[4];
  emxArray_char_T *Output;
} ObjMeta;
#endif /* typedef_ObjMeta */

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

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T
struct emxArray_uint8_T {
  uint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_uint8_T */
#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T
typedef struct emxArray_uint8_T emxArray_uint8_T;
#endif /* typedef_emxArray_uint8_T */

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

#ifndef typedef_struct0_T
#define typedef_struct0_T
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
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  emxArray_real32_T *Z;
} struct1_T;
#endif /* typedef_struct1_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void DetectPotentialCloud(ObjMeta *data_meta, emxArray_boolean_T *mask,
                          emxArray_uint8_T *water, struct0_T *data_toabt,
                          struct1_T *dem, emxArray_real32_T *ndvi,
                          emxArray_real32_T *ndsi, emxArray_real32_T *ndbi,
                          emxArray_boolean_T *idplcd,
                          emxArray_real32_T *whiteness, emxArray_real32_T *HOT,
                          emxArray_real32_T *wpt, emxArray_real32_T *cldprob,
                          real_T *sum_clr, emxArray_uint8_T *cloud,
                          emxArray_boolean_T *idused, real32_T *t_templ,
                          real32_T *t_temph);

void DetectPotentialCloud_api(const mxArray *const prhs[13], int32_T nlhs,
                              const mxArray *plhs[5]);

void DetectPotentialCloud_atexit(void);

void DetectPotentialCloud_initialize(void);

void DetectPotentialCloud_terminate(void);

void DetectPotentialCloud_xil_shutdown(void);

void DetectPotentialCloud_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_DetectPotentialCloud_api.h) */
