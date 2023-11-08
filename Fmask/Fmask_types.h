/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Fmask_types.h
 *
 * Code generation for function 'Fmask'
 *
 */

#ifndef FMASK_TYPES_H
#define FMASK_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  double Area;
} struct_T;
#endif /* typedef_struct_T */

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

#ifndef struct_emxArray_int8_T
#define struct_emxArray_int8_T
struct emxArray_int8_T {
  signed char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int8_T */
#ifndef typedef_emxArray_int8_T
#define typedef_emxArray_int8_T
typedef struct emxArray_int8_T emxArray_int8_T;
#endif /* typedef_emxArray_int8_T */

#ifndef typedef_emxArray_struct_T
#define typedef_emxArray_struct_T
typedef struct {
  struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_struct_T;
#endif /* typedef_emxArray_struct_T */

#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct {
  emxArray_real_T *PixelList;
} b_struct_T;
#endif /* typedef_b_struct_T */

#ifndef typedef_b_emxArray_struct_T
#define typedef_b_emxArray_struct_T
typedef struct {
  b_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} b_emxArray_struct_T;
#endif /* typedef_b_emxArray_struct_T */

#ifndef typedef_c_images_internal_coder_strel_S
#define typedef_c_images_internal_coder_strel_S
typedef struct {
  emxArray_boolean_T *nhood;
  emxArray_real_T *height;
  boolean_T Flat;
} c_images_internal_coder_strel_S;
#endif /* typedef_c_images_internal_coder_strel_S */

#ifndef typedef_c_emxArray_images_internal_code
#define typedef_c_emxArray_images_internal_code
typedef struct {
  c_images_internal_coder_strel_S *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} c_emxArray_images_internal_code;
#endif /* typedef_c_emxArray_images_internal_code */

#ifndef typedef_cell_wrap_14
#define typedef_cell_wrap_14
typedef struct {
  c_emxArray_images_internal_code *f1;
} cell_wrap_14;
#endif /* typedef_cell_wrap_14 */

#ifndef typedef_emxArray_cell_wrap_14
#define typedef_emxArray_cell_wrap_14
typedef struct {
  cell_wrap_14 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_14;
#endif /* typedef_emxArray_cell_wrap_14 */

#ifndef typedef_d_emxArray_images_internal_code
#define typedef_d_emxArray_images_internal_code
typedef struct {
  c_images_internal_coder_strel_S data[1];
  int size[2];
} d_emxArray_images_internal_code;
#endif /* typedef_d_emxArray_images_internal_code */

#ifndef typedef_emxArray_cell_wrap_14_1x1
#define typedef_emxArray_cell_wrap_14_1x1
typedef struct {
  cell_wrap_14 data[1];
  int size[2];
} emxArray_cell_wrap_14_1x1;
#endif /* typedef_emxArray_cell_wrap_14_1x1 */

#ifndef typedef_strel
#define typedef_strel
typedef struct {
  c_emxArray_images_internal_code *StrelArray;
  emxArray_cell_wrap_14 *DecomposedStrelArray;
} strel;
#endif /* typedef_strel */

#ifndef struct_emxArray_uint32_T
#define struct_emxArray_uint32_T
struct emxArray_uint32_T {
  unsigned int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_uint32_T */
#ifndef typedef_emxArray_uint32_T
#define typedef_emxArray_uint32_T
typedef struct emxArray_uint32_T emxArray_uint32_T;
#endif /* typedef_emxArray_uint32_T */

#ifndef typedef_cell_wrap_30
#define typedef_cell_wrap_30
typedef struct {
  emxArray_real_T *f1;
} cell_wrap_30;
#endif /* typedef_cell_wrap_30 */

#ifndef typedef_emxArray_cell_wrap_30
#define typedef_emxArray_cell_wrap_30
typedef struct {
  cell_wrap_30 *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_30;
#endif /* typedef_emxArray_cell_wrap_30 */

#ifndef typedef_cell_wrap_23
#define typedef_cell_wrap_23
typedef struct {
  emxArray_real_T *f1;
} cell_wrap_23;
#endif /* typedef_cell_wrap_23 */

#ifndef struct_emxArray_boolean_T_0x0
#define struct_emxArray_boolean_T_0x0
struct emxArray_boolean_T_0x0 {
  int size[2];
};
#endif /* struct_emxArray_boolean_T_0x0 */
#ifndef typedef_emxArray_boolean_T_0x0
#define typedef_emxArray_boolean_T_0x0
typedef struct emxArray_boolean_T_0x0 emxArray_boolean_T_0x0;
#endif /* typedef_emxArray_boolean_T_0x0 */

#ifndef struct_emxArray_real_T_0
#define struct_emxArray_real_T_0
struct emxArray_real_T_0 {
  int size[1];
};
#endif /* struct_emxArray_real_T_0 */
#ifndef typedef_emxArray_real_T_0
#define typedef_emxArray_real_T_0
typedef struct emxArray_real_T_0 emxArray_real_T_0;
#endif /* typedef_emxArray_real_T_0 */

#ifndef struct_emxArray_real_T_1x0
#define struct_emxArray_real_T_1x0
struct emxArray_real_T_1x0 {
  int size[2];
};
#endif /* struct_emxArray_real_T_1x0 */
#ifndef typedef_emxArray_real_T_1x0
#define typedef_emxArray_real_T_1x0
typedef struct emxArray_real_T_1x0 emxArray_real_T_1x0;
#endif /* typedef_emxArray_real_T_1x0 */

#ifndef typedef_c_struct_T
#define typedef_c_struct_T
typedef struct {
  double Area;
  double Centroid[2];
  double BoundingBox[4];
  double MajorAxisLength;
  double MinorAxisLength;
  double Eccentricity;
  double Orientation;
  emxArray_boolean_T_0x0 Image;
  emxArray_boolean_T_0x0 FilledImage;
  double FilledArea;
  double EulerNumber;
  double Extrema[16];
  double EquivDiameter;
  double Extent;
  emxArray_real_T *PixelIdxList;
  emxArray_real_T *PixelList;
  double Perimeter;
  double Circularity;
  emxArray_real_T_0 PixelValues;
  double WeightedCentroid[2];
  double MeanIntensity;
  double MinIntensity;
  double MaxIntensity;
  emxArray_real_T_1x0 SubarrayIdx;
  double SubarrayIdxLengths[2];
} c_struct_T;
#endif /* typedef_c_struct_T */

#ifndef typedef_c_emxArray_struct_T
#define typedef_c_emxArray_struct_T
typedef struct {
  c_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} c_emxArray_struct_T;
#endif /* typedef_c_emxArray_struct_T */

#endif
/* End of code generation (Fmask_types.h) */
