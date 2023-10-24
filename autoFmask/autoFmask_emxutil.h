/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * autoFmask_emxutil.h
 *
 * Code generation for function 'autoFmask_emxutil'
 *
 */

#ifndef AUTOFMASK_EMXUTIL_H
#define AUTOFMASK_EMXUTIL_H

/* Include files */
#include "autoFmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void
c_emxCopyStruct_images_internal(c_images_internal_coder_strel_S *dst,
                                const c_images_internal_coder_strel_S *src);

extern void
c_emxCopy_images_internal_coder(c_emxArray_images_internal_code **dst,
                                c_emxArray_images_internal_code *const *src);

extern void
c_emxEnsureCapacity_images_inte(c_images_internal_coder_strel_S *data,
                                const int size[2], int oldNumel);

extern void
c_emxExpand_images_internal_cod(c_images_internal_coder_strel_S *data,
                                int fromIndex, int toIndex);

extern void
c_emxFreeStruct_images_internal(c_images_internal_coder_strel_S *pStruct);

extern void
c_emxFree_images_internal_coder(c_emxArray_images_internal_code **pEmxArray);

extern void
c_emxInitStruct_images_internal(c_images_internal_coder_strel_S *pStruct);

extern void
c_emxInit_images_internal_coder(d_emxArray_images_internal_code *pEmxArray);

extern void
c_emxTrim_images_internal_coder(c_images_internal_coder_strel_S *data,
                                int fromIndex, int toIndex);

extern void
d_emxEnsureCapacity_images_inte(c_emxArray_images_internal_code *emxArray,
                                int oldNumel);

extern void
d_emxExpand_images_internal_cod(c_emxArray_images_internal_code *emxArray,
                                int fromIndex, int toIndex);

extern void
d_emxFree_images_internal_coder(d_emxArray_images_internal_code *pEmxArray);

extern void
d_emxInit_images_internal_coder(c_emxArray_images_internal_code **pEmxArray);

extern void
d_emxTrim_images_internal_coder(c_emxArray_images_internal_code *emxArray,
                                int fromIndex, int toIndex);

extern void emxCopyStruct_cell_wrap_22(cell_wrap_22 *dst,
                                       const cell_wrap_22 *src);

extern void emxCopy_boolean_T(emxArray_boolean_T **dst,
                              emxArray_boolean_T *const *src);

extern void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src);

extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_cell_wrap_22(cell_wrap_22 *data,
                                           const int size[2], int oldNumel);

extern void emxEnsureCapacity_cell_wrap_221(emxArray_cell_wrap_22 *emxArray,
                                            int oldNumel);

extern void emxEnsureCapacity_cell_wrap_29(emxArray_cell_wrap_29 *emxArray,
                                           int oldNumel);

extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_real32_T(emxArray_real32_T *emxArray,
                                       int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_uint32_T(emxArray_uint32_T *emxArray,
                                       int oldNumel);

extern void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel);

extern void emxExpand_cell_wrap_22(emxArray_cell_wrap_22 *emxArray,
                                   int fromIndex, int toIndex);

extern void emxExpand_cell_wrap_22_1x1(cell_wrap_22 *data, int fromIndex,
                                       int toIndex);

extern void emxExpand_cell_wrap_29(emxArray_cell_wrap_29 *emxArray,
                                   int fromIndex, int toIndex);

extern void emxFreeMatrix_cell_wrap_30(cell_wrap_30 pMatrix[3]);

extern void emxFreeStruct_ObjMeta(ObjMeta *pStruct);

extern void emxFreeStruct_ObjTOABT(ObjTOABT *pStruct);

extern void emxFreeStruct_cell_wrap_22(cell_wrap_22 *pStruct);

extern void emxFreeStruct_cell_wrap_29(cell_wrap_29 *pStruct);

extern void emxFreeStruct_cell_wrap_30(cell_wrap_30 *pStruct);

extern void emxFreeStruct_strel(strel *pStruct);

extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxFree_cell_wrap_22(emxArray_cell_wrap_22 **pEmxArray);

extern void emxFree_cell_wrap_22_1x1(emxArray_cell_wrap_22_1x1 *pEmxArray);

extern void emxFree_cell_wrap_29(emxArray_cell_wrap_29 **pEmxArray);

extern void emxFree_char_T(emxArray_char_T **pEmxArray);

extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);

extern void emxFree_int8_T(emxArray_int8_T **pEmxArray);

extern void emxFree_real32_T(emxArray_real32_T **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxFree_uint32_T(emxArray_uint32_T **pEmxArray);

extern void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);

extern void emxInitMatrix_cell_wrap_30(cell_wrap_30 pMatrix[3]);

extern void emxInitStruct_ObjMeta(ObjMeta *pStruct);

extern void emxInitStruct_ObjTOABT(ObjTOABT *pStruct);

extern void emxInitStruct_cell_wrap_22(cell_wrap_22 *pStruct);

extern void emxInitStruct_cell_wrap_29(cell_wrap_29 *pStruct);

extern void emxInitStruct_cell_wrap_30(cell_wrap_30 *pStruct);

extern void emxInitStruct_strel(strel *pStruct);

extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray,
                              int numDimensions);

extern void emxInit_cell_wrap_22(emxArray_cell_wrap_22 **pEmxArray);

extern void emxInit_cell_wrap_22_1x1(emxArray_cell_wrap_22_1x1 *pEmxArray);

extern void emxInit_cell_wrap_29(emxArray_cell_wrap_29 **pEmxArray);

extern void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions);

extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);

extern void emxInit_int8_T(emxArray_int8_T **pEmxArray, int numDimensions);

extern void emxInit_real32_T(emxArray_real32_T **pEmxArray, int numDimensions);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

extern void emxInit_uint32_T(emxArray_uint32_T **pEmxArray);

extern void emxInit_uint8_T(emxArray_uint8_T **pEmxArray);

extern void emxTrim_cell_wrap_22(emxArray_cell_wrap_22 *emxArray, int fromIndex,
                                 int toIndex);

extern void emxTrim_cell_wrap_22_1x1(cell_wrap_22 *data, int fromIndex,
                                     int toIndex);

extern void emxTrim_cell_wrap_29(emxArray_cell_wrap_29 *emxArray, int fromIndex,
                                 int toIndex);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (autoFmask_emxutil.h) */
