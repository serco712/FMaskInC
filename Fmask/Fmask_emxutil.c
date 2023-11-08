/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Fmask_emxutil.c
 *
 * Code generation for function 'Fmask_emxutil'
 *
 */

/* Include files */
#include "Fmask_emxutil.h"
#include "Fmask_types.h"
#include <stdlib.h>
#include <string.h>

/* Function Definitions */
void c_emxCopyStruct_images_internal(c_images_internal_coder_strel_S *dst,
                                     const c_images_internal_coder_strel_S *src)
{
  emxCopy_boolean_T(&dst->nhood, &src->nhood);
  emxCopy_real_T(&dst->height, &src->height);
  dst->Flat = src->Flat;
}

void c_emxCopy_images_internal_coder(
    c_emxArray_images_internal_code **dst,
    c_emxArray_images_internal_code *const *src)
{
  int i;
  int numElDst;
  int numElSrc;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }
  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }
  d_emxEnsureCapacity_images_inte(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    c_emxCopyStruct_images_internal(&(*dst)->data[i], &(*src)->data[i]);
  }
}

void c_emxEnsureCapacity_images_inte(c_images_internal_coder_strel_S *data,
                                     const int size[2], int oldNumel)
{
  int newNumel;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = size[0] * size[1];
  if (oldNumel > newNumel) {
    c_emxTrim_images_internal_coder(data, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    c_emxExpand_images_internal_cod(data, oldNumel, newNumel);
  }
}

void c_emxExpand_images_internal_cod(c_images_internal_coder_strel_S *data,
                                     int fromIndex, int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    c_emxInitStruct_images_internal(data);
  }
}

void c_emxFreeStruct_images_internal(c_images_internal_coder_strel_S *pStruct)
{
  emxFree_boolean_T(&pStruct->nhood);
  emxFree_real_T(&pStruct->height);
}

void c_emxFree_images_internal_coder(
    c_emxArray_images_internal_code **pEmxArray)
{
  int i;
  if (*pEmxArray != (c_emxArray_images_internal_code *)NULL) {
    if ((*pEmxArray)->data != (c_images_internal_coder_strel_S *)NULL) {
      int numEl;
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        c_emxFreeStruct_images_internal(&(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (c_emxArray_images_internal_code *)NULL;
  }
}

void c_emxInitStruct_images_internal(c_images_internal_coder_strel_S *pStruct)
{
  emxInit_boolean_T(&pStruct->nhood, 3);
  emxInit_real_T(&pStruct->height, 3);
}

void c_emxInit_images_internal_coder(d_emxArray_images_internal_code *pEmxArray)
{
  pEmxArray->size[0] = 0;
  pEmxArray->size[1] = 0;
}

void c_emxTrim_images_internal_coder(c_images_internal_coder_strel_S *data,
                                     int fromIndex, int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    c_emxFreeStruct_images_internal(data);
  }
}

void d_emxEnsureCapacity_images_inte(c_emxArray_images_internal_code *emxArray,
                                     int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(c_images_internal_coder_strel_S));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(c_images_internal_coder_strel_S) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (c_images_internal_coder_strel_S *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    d_emxTrim_images_internal_coder(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    d_emxExpand_images_internal_cod(emxArray, oldNumel, newNumel);
  }
}

void d_emxExpand_images_internal_cod(c_emxArray_images_internal_code *emxArray,
                                     int fromIndex, int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    c_emxInitStruct_images_internal(&emxArray->data[i]);
  }
}

void d_emxFree_images_internal_coder(d_emxArray_images_internal_code *pEmxArray)
{
  int i;
  int numEl;
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= pEmxArray->size[i];
  }
  for (i = 0; i < numEl; i++) {
    c_emxFreeStruct_images_internal(&pEmxArray->data[i]);
  }
}

void d_emxInit_images_internal_coder(
    c_emxArray_images_internal_code **pEmxArray)
{
  c_emxArray_images_internal_code *emxArray;
  int i;
  *pEmxArray = (c_emxArray_images_internal_code *)malloc(
      sizeof(c_emxArray_images_internal_code));
  emxArray = *pEmxArray;
  emxArray->data = (c_images_internal_coder_strel_S *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void d_emxTrim_images_internal_coder(c_emxArray_images_internal_code *emxArray,
                                     int fromIndex, int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    c_emxFreeStruct_images_internal(&emxArray->data[i]);
  }
}

void emxCopyMatrix_real_T(double dst[2], const double src[2])
{
  int i;
  for (i = 0; i < 2; i++) {
    dst[i] = src[i];
  }
}

void emxCopyMatrix_real_T1(double dst[4], const double src[4])
{
  int i;
  for (i = 0; i < 4; i++) {
    dst[i] = src[i];
  }
}

void emxCopyMatrix_real_T2(double dst[16], const double src[16])
{
  memcpy(&dst[0], &src[0], 16U * sizeof(double));
}

void emxCopyStruct_cell_wrap_14(cell_wrap_14 *dst, const cell_wrap_14 *src)
{
  c_emxCopy_images_internal_coder(&dst->f1, &src->f1);
}

void emxCopyStruct_struct_T(c_struct_T *dst, const c_struct_T *src)
{
  dst->Area = src->Area;
  emxCopyMatrix_real_T(dst->Centroid, src->Centroid);
  emxCopyMatrix_real_T1(dst->BoundingBox, src->BoundingBox);
  dst->MajorAxisLength = src->MajorAxisLength;
  dst->MinorAxisLength = src->MinorAxisLength;
  dst->Eccentricity = src->Eccentricity;
  dst->Orientation = src->Orientation;
  emxCopy_boolean_T_0x0(&dst->Image, &src->Image);
  emxCopy_boolean_T_0x0(&dst->FilledImage, &src->FilledImage);
  dst->FilledArea = src->FilledArea;
  dst->EulerNumber = src->EulerNumber;
  emxCopyMatrix_real_T2(dst->Extrema, src->Extrema);
  dst->EquivDiameter = src->EquivDiameter;
  dst->Extent = src->Extent;
  emxCopy_real_T(&dst->PixelIdxList, &src->PixelIdxList);
  emxCopy_real_T(&dst->PixelList, &src->PixelList);
  dst->Perimeter = src->Perimeter;
  dst->Circularity = src->Circularity;
  emxCopy_real_T_0(&dst->PixelValues, &src->PixelValues);
  emxCopyMatrix_real_T(dst->WeightedCentroid, src->WeightedCentroid);
  dst->MeanIntensity = src->MeanIntensity;
  dst->MinIntensity = src->MinIntensity;
  dst->MaxIntensity = src->MaxIntensity;
  emxCopy_real_T_1x0(&dst->SubarrayIdx, &src->SubarrayIdx);
  emxCopyMatrix_real_T(dst->SubarrayIdxLengths, src->SubarrayIdxLengths);
}

void emxCopyStruct_struct_T1(b_struct_T *dst, const b_struct_T *src)
{
  emxCopy_real_T(&dst->PixelList, &src->PixelList);
}

void emxCopy_boolean_T(emxArray_boolean_T **dst, emxArray_boolean_T *const *src)
{
  int i;
  int numElDst;
  int numElSrc;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }
  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }
  emxEnsureCapacity_boolean_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

void emxCopy_boolean_T_0x0(emxArray_boolean_T_0x0 *dst,
                           const emxArray_boolean_T_0x0 *src)
{
  int i;
  for (i = 0; i < 2; i++) {
    dst->size[i] = src->size[i];
  }
}

void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src)
{
  int i;
  int numElDst;
  int numElSrc;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }
  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }
  emxEnsureCapacity_real_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

void emxCopy_real_T_0(emxArray_real_T_0 *dst, const emxArray_real_T_0 *src)
{
  dst->size[0] = src->size[0];
}

void emxCopy_real_T_1x0(emxArray_real_T_1x0 *dst,
                        const emxArray_real_T_1x0 *src)
{
  int i;
  for (i = 0; i < 2; i++) {
    dst->size[i] = src->size[i];
  }
}

void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(boolean_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_cell_wrap_14(cell_wrap_14 *data, const int size[2],
                                    int oldNumel)
{
  int newNumel;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = size[0] * size[1];
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_14_1x1(data, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_14_1x1(data, oldNumel, newNumel);
  }
}

void emxEnsureCapacity_cell_wrap_141(emxArray_cell_wrap_14 *emxArray,
                                     int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(cell_wrap_14));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(cell_wrap_14) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_14 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_14(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_14(emxArray, oldNumel, newNumel);
  }
}

void emxEnsureCapacity_cell_wrap_30(emxArray_cell_wrap_30 *emxArray,
                                    int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(cell_wrap_30));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(cell_wrap_30) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_30 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_30(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_30(emxArray, oldNumel, newNumel);
  }
}

void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(int));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (int *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(signed char));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(signed char) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (signed char *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_real32_T(emxArray_real32_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(float));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(float) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (float *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(double) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (double *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_struct_T(emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_struct_T1(c_emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(c_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(c_struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (c_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_struct_T(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_struct_T(emxArray, oldNumel, newNumel);
  }
}

void emxEnsureCapacity_struct_T2(b_emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(b_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(b_struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (b_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_struct_T1(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_struct_T1(emxArray, oldNumel, newNumel);
  }
}

void emxEnsureCapacity_uint32_T(emxArray_uint32_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(unsigned int));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(unsigned int) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (unsigned int *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(unsigned char));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(unsigned char) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (unsigned char *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxExpand_cell_wrap_14(emxArray_cell_wrap_14 *emxArray, int fromIndex,
                            int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_14(&emxArray->data[i]);
  }
}

void emxExpand_cell_wrap_14_1x1(cell_wrap_14 *data, int fromIndex, int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_14(data);
  }
}

void emxExpand_cell_wrap_30(emxArray_cell_wrap_30 *emxArray, int fromIndex,
                            int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_30(&emxArray->data[i]);
  }
}

void emxExpand_struct_T(c_emxArray_struct_T *emxArray, int fromIndex,
                        int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T(&emxArray->data[i]);
  }
}

void emxExpand_struct_T1(b_emxArray_struct_T *emxArray, int fromIndex,
                         int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T1(&emxArray->data[i]);
  }
}

void emxFreeMatrix_cell_wrap_23(cell_wrap_23 pMatrix[3])
{
  int i;
  for (i = 0; i < 3; i++) {
    emxFreeStruct_cell_wrap_23(&pMatrix[i]);
  }
}

void emxFreeStruct_cell_wrap_14(cell_wrap_14 *pStruct)
{
  c_emxFree_images_internal_coder(&pStruct->f1);
}

void emxFreeStruct_cell_wrap_23(cell_wrap_23 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

void emxFreeStruct_cell_wrap_30(cell_wrap_30 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

void emxFreeStruct_strel(strel *pStruct)
{
  c_emxFree_images_internal_coder(&pStruct->StrelArray);
  emxFree_cell_wrap_14(&pStruct->DecomposedStrelArray);
}

void emxFreeStruct_struct_T(b_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->PixelList);
}

void emxFreeStruct_struct_T1(c_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->PixelIdxList);
  emxFree_real_T(&pStruct->PixelList);
}

void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

void emxFree_cell_wrap_14(emxArray_cell_wrap_14 **pEmxArray)
{
  int i;
  if (*pEmxArray != (emxArray_cell_wrap_14 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_14 *)NULL) {
      int numEl;
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_14(&(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_14 *)NULL;
  }
}

void emxFree_cell_wrap_14_1x1(emxArray_cell_wrap_14_1x1 *pEmxArray)
{
  int i;
  int numEl;
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= pEmxArray->size[i];
  }
  for (i = 0; i < numEl; i++) {
    emxFreeStruct_cell_wrap_14(&pEmxArray->data[i]);
  }
}

void emxFree_cell_wrap_30(emxArray_cell_wrap_30 **pEmxArray)
{
  int i;
  if (*pEmxArray != (emxArray_cell_wrap_30 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_30 *)NULL) {
      int numEl;
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_30(&(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_30 *)NULL;
  }
}

void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

void emxFree_int8_T(emxArray_int8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int8_T *)NULL) {
    if (((*pEmxArray)->data != (signed char *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int8_T *)NULL;
  }
}

void emxFree_real32_T(emxArray_real32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real32_T *)NULL) {
    if (((*pEmxArray)->data != (float *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real32_T *)NULL;
  }
}

void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (double *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

void emxFree_struct_T(emxArray_struct_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_struct_T *)NULL) {
    if (((*pEmxArray)->data != (struct_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_struct_T *)NULL;
  }
}

void emxFree_struct_T1(b_emxArray_struct_T **pEmxArray)
{
  int i;
  if (*pEmxArray != (b_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (b_struct_T *)NULL) {
      int numEl;
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T(&(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (b_emxArray_struct_T *)NULL;
  }
}

void emxFree_struct_T2(c_emxArray_struct_T **pEmxArray)
{
  int i;
  if (*pEmxArray != (c_emxArray_struct_T *)NULL) {
    if ((*pEmxArray)->data != (c_struct_T *)NULL) {
      int numEl;
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct_T1(&(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (c_emxArray_struct_T *)NULL;
  }
}

void emxFree_uint32_T(emxArray_uint32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint32_T *)NULL) {
    if (((*pEmxArray)->data != (unsigned int *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_uint32_T *)NULL;
  }
}

void emxFree_uint8_T(emxArray_uint8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T *)NULL) {
    if (((*pEmxArray)->data != (unsigned char *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_uint8_T *)NULL;
  }
}

void emxInitMatrix_cell_wrap_23(cell_wrap_23 pMatrix[3])
{
  int i;
  for (i = 0; i < 3; i++) {
    emxInitStruct_cell_wrap_23(&pMatrix[i]);
  }
}

void emxInitStruct_cell_wrap_14(cell_wrap_14 *pStruct)
{
  d_emxInit_images_internal_coder(&pStruct->f1);
}

void emxInitStruct_cell_wrap_23(cell_wrap_23 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 1);
}

void emxInitStruct_cell_wrap_30(cell_wrap_30 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 2);
}

void emxInitStruct_strel(strel *pStruct)
{
  d_emxInit_images_internal_coder(&pStruct->StrelArray);
  emxInit_cell_wrap_14(&pStruct->DecomposedStrelArray);
}

void emxInitStruct_struct_T(c_struct_T *pStruct)
{
  pStruct->Image.size[0] = 0;
  pStruct->Image.size[1] = 0;
  pStruct->FilledImage.size[0] = 0;
  pStruct->FilledImage.size[1] = 0;
  emxInit_real_T(&pStruct->PixelIdxList, 1);
  emxInit_real_T(&pStruct->PixelList, 2);
  pStruct->PixelValues.size[0] = 0;
  pStruct->SubarrayIdx.size[0] = 0;
  pStruct->SubarrayIdx.size[1] = 0;
}

void emxInitStruct_struct_T1(b_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->PixelList, 2);
}

void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions)
{
  emxArray_boolean_T *emxArray;
  int i;
  *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_14(emxArray_cell_wrap_14 **pEmxArray)
{
  emxArray_cell_wrap_14 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_14 *)malloc(sizeof(emxArray_cell_wrap_14));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_14 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_14_1x1(emxArray_cell_wrap_14_1x1 *pEmxArray)
{
  pEmxArray->size[0] = 0;
  pEmxArray->size[1] = 0;
}

void emxInit_cell_wrap_30(emxArray_cell_wrap_30 **pEmxArray)
{
  emxArray_cell_wrap_30 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_30 *)malloc(sizeof(emxArray_cell_wrap_30));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_30 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int8_T(emxArray_int8_T **pEmxArray, int numDimensions)
{
  emxArray_int8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int8_T *)malloc(sizeof(emxArray_int8_T));
  emxArray = *pEmxArray;
  emxArray->data = (signed char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_real32_T(emxArray_real32_T **pEmxArray, int numDimensions)
{
  emxArray_real32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real32_T *)malloc(sizeof(emxArray_real32_T));
  emxArray = *pEmxArray;
  emxArray->data = (float *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxArray_real_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (double *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_struct_T(emxArray_struct_T **pEmxArray)
{
  emxArray_struct_T *emxArray;
  *pEmxArray = (emxArray_struct_T *)malloc(sizeof(emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (struct_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int *)malloc(sizeof(int));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_struct_T1(b_emxArray_struct_T **pEmxArray)
{
  b_emxArray_struct_T *emxArray;
  *pEmxArray = (b_emxArray_struct_T *)malloc(sizeof(b_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (b_struct_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int *)malloc(sizeof(int));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_struct_T2(c_emxArray_struct_T **pEmxArray)
{
  c_emxArray_struct_T *emxArray;
  *pEmxArray = (c_emxArray_struct_T *)malloc(sizeof(c_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (c_struct_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int *)malloc(sizeof(int));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_uint32_T(emxArray_uint32_T **pEmxArray)
{
  emxArray_uint32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_uint32_T *)malloc(sizeof(emxArray_uint32_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned int *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_uint8_T(emxArray_uint8_T **pEmxArray)
{
  emxArray_uint8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_uint8_T *)malloc(sizeof(emxArray_uint8_T));
  emxArray = *pEmxArray;
  emxArray->data = (unsigned char *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxTrim_cell_wrap_14(emxArray_cell_wrap_14 *emxArray, int fromIndex,
                          int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_14(&emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_14_1x1(cell_wrap_14 *data, int fromIndex, int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_14(data);
  }
}

void emxTrim_cell_wrap_30(emxArray_cell_wrap_30 *emxArray, int fromIndex,
                          int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_30(&emxArray->data[i]);
  }
}

void emxTrim_struct_T(c_emxArray_struct_T *emxArray, int fromIndex, int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T1(&emxArray->data[i]);
  }
}

void emxTrim_struct_T1(b_emxArray_struct_T *emxArray, int fromIndex,
                       int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct_T(&emxArray->data[i]);
  }
}

/* End of code generation (Fmask_emxutil.c) */
