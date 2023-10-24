/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * autoFmask_emxutil.c
 *
 * Code generation for function 'autoFmask_emxutil'
 *
 */

/* Include files */
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"
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

void emxCopyStruct_cell_wrap_22(cell_wrap_22 *dst, const cell_wrap_22 *src)
{
  c_emxCopy_images_internal_coder(&dst->f1, &src->f1);
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

void emxEnsureCapacity_cell_wrap_22(cell_wrap_22 *data, const int size[2],
                                    int oldNumel)
{
  int newNumel;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = size[0] * size[1];
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_22_1x1(data, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_22_1x1(data, oldNumel, newNumel);
  }
}

void emxEnsureCapacity_cell_wrap_221(emxArray_cell_wrap_22 *emxArray,
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
    newData = calloc((unsigned int)i, sizeof(cell_wrap_22));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(cell_wrap_22) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_22 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_22(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_22(emxArray, oldNumel, newNumel);
  }
}

void emxEnsureCapacity_cell_wrap_29(emxArray_cell_wrap_29 *emxArray,
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
    newData = calloc((unsigned int)i, sizeof(cell_wrap_29));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(cell_wrap_29) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_29 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_29(emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_29(emxArray, oldNumel, newNumel);
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

void emxExpand_cell_wrap_22(emxArray_cell_wrap_22 *emxArray, int fromIndex,
                            int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_22(&emxArray->data[i]);
  }
}

void emxExpand_cell_wrap_22_1x1(cell_wrap_22 *data, int fromIndex, int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_22(data);
  }
}

void emxExpand_cell_wrap_29(emxArray_cell_wrap_29 *emxArray, int fromIndex,
                            int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_29(&emxArray->data[i]);
  }
}

void emxFreeMatrix_cell_wrap_30(cell_wrap_30 pMatrix[3])
{
  int i;
  for (i = 0; i < 3; i++) {
    emxFreeStruct_cell_wrap_30(&pMatrix[i]);
  }
}

void emxFreeStruct_ObjMeta(ObjMeta *pStruct)
{
  emxFree_char_T(&pStruct->Name);
  emxFree_char_T(&pStruct->Sensor);
  emxFree_char_T(&pStruct->Output);
}

void emxFreeStruct_ObjTOABT(ObjTOABT *pStruct)
{
  emxFree_real32_T(&pStruct->BandCA);
  emxFree_real32_T(&pStruct->BandBlue);
  emxFree_real32_T(&pStruct->BandGreen);
  emxFree_real32_T(&pStruct->BandRed);
  emxFree_real32_T(&pStruct->BandVRE1);
  emxFree_real32_T(&pStruct->BandVRE2);
  emxFree_real32_T(&pStruct->BandVRE3);
  emxFree_real32_T(&pStruct->BandNIR8);
  emxFree_real32_T(&pStruct->BandNIR);
  emxFree_real32_T(&pStruct->BandWV);
  emxFree_real32_T(&pStruct->BandCirrus);
  emxFree_real32_T(&pStruct->BandSWIR1);
  emxFree_real32_T(&pStruct->BandSWIR2);
  emxFree_real32_T(&pStruct->BandBT);
  emxFree_boolean_T(&pStruct->SatuBlue);
  emxFree_boolean_T(&pStruct->SatuGreen);
  emxFree_boolean_T(&pStruct->SatuRed);
}

void emxFreeStruct_cell_wrap_22(cell_wrap_22 *pStruct)
{
  c_emxFree_images_internal_coder(&pStruct->f1);
}

void emxFreeStruct_cell_wrap_29(cell_wrap_29 *pStruct)
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
  emxFree_cell_wrap_22(&pStruct->DecomposedStrelArray);
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

void emxFree_cell_wrap_22(emxArray_cell_wrap_22 **pEmxArray)
{
  int i;
  if (*pEmxArray != (emxArray_cell_wrap_22 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_22 *)NULL) {
      int numEl;
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_22(&(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_22 *)NULL;
  }
}

void emxFree_cell_wrap_22_1x1(emxArray_cell_wrap_22_1x1 *pEmxArray)
{
  int i;
  int numEl;
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= pEmxArray->size[i];
  }
  for (i = 0; i < numEl; i++) {
    emxFreeStruct_cell_wrap_22(&pEmxArray->data[i]);
  }
}

void emxFree_cell_wrap_29(emxArray_cell_wrap_29 **pEmxArray)
{
  int i;
  if (*pEmxArray != (emxArray_cell_wrap_29 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_29 *)NULL) {
      int numEl;
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_29(&(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        free((*pEmxArray)->data);
      }
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_29 *)NULL;
  }
}

void emxFree_char_T(emxArray_char_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T *)NULL) {
    if (((*pEmxArray)->data != (char *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T *)NULL;
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

void emxInitMatrix_cell_wrap_30(cell_wrap_30 pMatrix[3])
{
  int i;
  for (i = 0; i < 3; i++) {
    emxInitStruct_cell_wrap_30(&pMatrix[i]);
  }
}

void emxInitStruct_ObjMeta(ObjMeta *pStruct)
{
  emxInit_char_T(&pStruct->Name, 2);
  emxInit_char_T(&pStruct->Sensor, 2);
  emxInit_char_T(&pStruct->Output, 2);
}

void emxInitStruct_ObjTOABT(ObjTOABT *pStruct)
{
  emxInit_real32_T(&pStruct->BandCA, 2);
  emxInit_real32_T(&pStruct->BandBlue, 2);
  emxInit_real32_T(&pStruct->BandGreen, 2);
  emxInit_real32_T(&pStruct->BandRed, 2);
  emxInit_real32_T(&pStruct->BandVRE1, 2);
  emxInit_real32_T(&pStruct->BandVRE2, 2);
  emxInit_real32_T(&pStruct->BandVRE3, 2);
  emxInit_real32_T(&pStruct->BandNIR8, 2);
  emxInit_real32_T(&pStruct->BandNIR, 2);
  emxInit_real32_T(&pStruct->BandWV, 2);
  emxInit_real32_T(&pStruct->BandCirrus, 2);
  emxInit_real32_T(&pStruct->BandSWIR1, 2);
  emxInit_real32_T(&pStruct->BandSWIR2, 2);
  emxInit_real32_T(&pStruct->BandBT, 2);
  emxInit_boolean_T(&pStruct->SatuBlue, 2);
  emxInit_boolean_T(&pStruct->SatuGreen, 2);
  emxInit_boolean_T(&pStruct->SatuRed, 2);
}

void emxInitStruct_cell_wrap_22(cell_wrap_22 *pStruct)
{
  d_emxInit_images_internal_coder(&pStruct->f1);
}

void emxInitStruct_cell_wrap_29(cell_wrap_29 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 2);
}

void emxInitStruct_cell_wrap_30(cell_wrap_30 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 1);
}

void emxInitStruct_strel(strel *pStruct)
{
  d_emxInit_images_internal_coder(&pStruct->StrelArray);
  emxInit_cell_wrap_22(&pStruct->DecomposedStrelArray);
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

void emxInit_cell_wrap_22(emxArray_cell_wrap_22 **pEmxArray)
{
  emxArray_cell_wrap_22 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_22 *)malloc(sizeof(emxArray_cell_wrap_22));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_22 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cell_wrap_22_1x1(emxArray_cell_wrap_22_1x1 *pEmxArray)
{
  pEmxArray->size[0] = 0;
  pEmxArray->size[1] = 0;
}

void emxInit_cell_wrap_29(emxArray_cell_wrap_29 **pEmxArray)
{
  emxArray_cell_wrap_29 *emxArray;
  int i;
  *pEmxArray = (emxArray_cell_wrap_29 *)malloc(sizeof(emxArray_cell_wrap_29));
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_29 *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxArray_char_T *emxArray;
  int i;
  *pEmxArray = (emxArray_char_T *)malloc(sizeof(emxArray_char_T));
  emxArray = *pEmxArray;
  emxArray->data = (char *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
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

void emxTrim_cell_wrap_22(emxArray_cell_wrap_22 *emxArray, int fromIndex,
                          int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_22(&emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_22_1x1(cell_wrap_22 *data, int fromIndex, int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_22(data);
  }
}

void emxTrim_cell_wrap_29(emxArray_cell_wrap_29 *emxArray, int fromIndex,
                          int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_29(&emxArray->data[i]);
  }
}

/* End of code generation (autoFmask_emxutil.c) */
