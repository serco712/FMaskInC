/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * types.h
 *
 */

#ifndef TYPES_H
#define TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_boolean_T */
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /* typedef_emxArray_boolean_T */

/* Type Definitions */
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T
struct emxArray_char_T {
  char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_char_T */
#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T
typedef struct emxArray_char_T emxArray_char_T;
#endif /* typedef_emxArray_char_T */

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T
struct emxArray_uint8_T {
  unsigned char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
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
  float *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real32_T */
#ifndef typedef_emxArray_real32_T
#define typedef_emxArray_real32_T
typedef struct emxArray_real32_T emxArray_real32_T;
#endif /* typedef_emxArray_real32_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

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

#ifndef typedef_ObjMeta
#define typedef_ObjMeta
typedef struct {
  emxArray_char_T *Name;
  emxArray_char_T *Sensor;
  double Resolution[4];
  double Dim[2];
  double UL[2];
  double Zen;
  double Azi;
  double ZC[2];
  double BBox[4];
  emxArray_char_T *Output;
} ObjMeta;
#endif /* typedef_ObjMeta */

#ifndef typedef_GRIDobj
#define typedef_GRIDobj
typedef struct {
  emxArray_real32_T *Z;
} GRIDobj;
#endif /* typedef_struct1_T */

#endif
/* End of code generation (DetectPotentialPixels_types.h) */
