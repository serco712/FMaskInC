/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * strel.c
 *
 * Code generation for function 'strel'
 *
 */

/* Include files */
#include "strel.h"
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"
#include "find.h"
#include <math.h>

/* Function Declarations */
static int div_s32(int numerator, int denominator);

static void
strel_decomposeImpl(const c_emxArray_images_internal_code *obj_StrelArray,
                    const emxArray_cell_wrap_22 *obj_DecomposedStrelArray,
                    c_emxArray_images_internal_code *seq_StrelArray,
                    emxArray_cell_wrap_22 *seq_DecomposedStrelArray);

/* Function Definitions */
static int div_s32(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int tempAbsQuotient;
    unsigned int u;
    if (numerator < 0) {
      tempAbsQuotient = ~(unsigned int)numerator + 1U;
    } else {
      tempAbsQuotient = (unsigned int)numerator;
    }
    if (denominator < 0) {
      u = ~(unsigned int)denominator + 1U;
    } else {
      u = (unsigned int)denominator;
    }
    tempAbsQuotient /= u;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int)tempAbsQuotient;
    } else {
      quotient = (int)tempAbsQuotient;
    }
  }
  return quotient;
}

static void
strel_decomposeImpl(const c_emxArray_images_internal_code *obj_StrelArray,
                    const emxArray_cell_wrap_22 *obj_DecomposedStrelArray,
                    c_emxArray_images_internal_code *seq_StrelArray,
                    emxArray_cell_wrap_22 *seq_DecomposedStrelArray)
{
  const c_images_internal_coder_strel_S *obj_StrelArray_data;
  c_images_internal_coder_strel_S *seq_StrelArray_data;
  const cell_wrap_22 *obj_DecomposedStrelArray_data;
  cell_wrap_22 *seq_DecomposedStrelArray_data;
  int i;
  int n;
  obj_DecomposedStrelArray_data = obj_DecomposedStrelArray->data;
  obj_StrelArray_data = obj_StrelArray->data;
  seq_StrelArray->size[0] = 1;
  seq_StrelArray->size[1] = 0;
  seq_DecomposedStrelArray->size[0] = 1;
  seq_DecomposedStrelArray->size[1] = 0;
  i = obj_DecomposedStrelArray_data[0].f1->size[1];
  if (obj_DecomposedStrelArray_data[0].f1->size[1] == 0) {
    i = seq_StrelArray->size[0] * seq_StrelArray->size[1];
    seq_StrelArray->size[0] = 1;
    seq_StrelArray->size[1] = 1;
    d_emxEnsureCapacity_images_inte(seq_StrelArray, i);
    seq_StrelArray_data = seq_StrelArray->data;
    c_emxCopyStruct_images_internal(&seq_StrelArray_data[0],
                                    &obj_StrelArray_data[0]);
    i = seq_DecomposedStrelArray->size[0] * seq_DecomposedStrelArray->size[1];
    seq_DecomposedStrelArray->size[0] = 1;
    seq_DecomposedStrelArray->size[1] = 1;
    emxEnsureCapacity_cell_wrap_221(seq_DecomposedStrelArray, i);
    seq_DecomposedStrelArray_data = seq_DecomposedStrelArray->data;
    seq_DecomposedStrelArray_data[0].f1->size[0] = 1;
    seq_DecomposedStrelArray_data[0].f1->size[1] = 0;
  } else {
    for (n = 0; n < i; n++) {
      int i1;
      int seq_StrelArray_tmp;
      seq_StrelArray_tmp = seq_StrelArray->size[1] + 1;
      i1 = seq_StrelArray->size[0] * seq_StrelArray->size[1];
      seq_StrelArray->size[0] = 1;
      seq_StrelArray->size[1]++;
      d_emxEnsureCapacity_images_inte(seq_StrelArray, i1);
      seq_StrelArray_data = seq_StrelArray->data;
      c_emxCopyStruct_images_internal(
          &seq_StrelArray_data[seq_StrelArray_tmp - 1],
          &obj_DecomposedStrelArray_data[0].f1->data[n]);
      i1 =
          seq_DecomposedStrelArray->size[0] * seq_DecomposedStrelArray->size[1];
      seq_DecomposedStrelArray->size[0] = 1;
      seq_DecomposedStrelArray->size[1]++;
      emxEnsureCapacity_cell_wrap_221(seq_DecomposedStrelArray, i1);
      seq_DecomposedStrelArray_data = seq_DecomposedStrelArray->data;
      i1 = seq_DecomposedStrelArray_data[seq_StrelArray_tmp - 1].f1->size[0] *
           seq_DecomposedStrelArray_data[seq_StrelArray_tmp - 1].f1->size[1];
      seq_DecomposedStrelArray_data[seq_StrelArray_tmp - 1].f1->size[0] = 1;
      d_emxEnsureCapacity_images_inte(
          seq_DecomposedStrelArray_data[seq_StrelArray_tmp - 1].f1, i1);
      seq_DecomposedStrelArray_data[seq_DecomposedStrelArray->size[1] - 1]
          .f1->size[1] = 0;
    }
  }
}

void strel_decompose(const c_emxArray_images_internal_code *obj_StrelArray,
                     const emxArray_cell_wrap_22 *obj_DecomposedStrelArray,
                     c_emxArray_images_internal_code *seq_StrelArray,
                     emxArray_cell_wrap_22 *seq_DecomposedStrelArray,
                     emxArray_boolean_T *isEachStrelObj2D)
{
  const c_images_internal_coder_strel_S *obj_StrelArray_data;
  c_images_internal_coder_strel_S *seq_StrelArray_data;
  const cell_wrap_22 *obj_DecomposedStrelArray_data;
  cell_wrap_22 *seq_DecomposedStrelArray_data;
  int i;
  int n;
  boolean_T *isEachStrelObj2D_data;
  obj_DecomposedStrelArray_data = obj_DecomposedStrelArray->data;
  obj_StrelArray_data = obj_StrelArray->data;
  seq_StrelArray->size[0] = 1;
  seq_StrelArray->size[1] = 0;
  seq_DecomposedStrelArray->size[0] = 1;
  seq_DecomposedStrelArray->size[1] = 0;
  isEachStrelObj2D->size[0] = 1;
  isEachStrelObj2D->size[1] = 0;
  i = obj_DecomposedStrelArray_data[0].f1->size[1];
  if (obj_DecomposedStrelArray_data[0].f1->size[1] == 0) {
    i = seq_StrelArray->size[0] * seq_StrelArray->size[1];
    seq_StrelArray->size[0] = 1;
    seq_StrelArray->size[1] = 1;
    d_emxEnsureCapacity_images_inte(seq_StrelArray, i);
    seq_StrelArray_data = seq_StrelArray->data;
    c_emxCopyStruct_images_internal(&seq_StrelArray_data[0],
                                    &obj_StrelArray_data[0]);
    i = seq_DecomposedStrelArray->size[0] * seq_DecomposedStrelArray->size[1];
    seq_DecomposedStrelArray->size[0] = 1;
    seq_DecomposedStrelArray->size[1] = 1;
    emxEnsureCapacity_cell_wrap_221(seq_DecomposedStrelArray, i);
    seq_DecomposedStrelArray_data = seq_DecomposedStrelArray->data;
    seq_DecomposedStrelArray_data[0].f1->size[0] = 1;
    seq_DecomposedStrelArray_data[0].f1->size[1] = 0;
    i = isEachStrelObj2D->size[0] * isEachStrelObj2D->size[1];
    isEachStrelObj2D->size[1] = 1;
    emxEnsureCapacity_boolean_T(isEachStrelObj2D, i);
    isEachStrelObj2D_data = isEachStrelObj2D->data;
    isEachStrelObj2D_data[0] = true;
  } else {
    for (n = 0; n < i; n++) {
      int i1;
      int seq_StrelArray_tmp;
      seq_StrelArray_tmp = seq_StrelArray->size[1] + 1;
      i1 = seq_StrelArray->size[0] * seq_StrelArray->size[1];
      seq_StrelArray->size[0] = 1;
      seq_StrelArray->size[1]++;
      d_emxEnsureCapacity_images_inte(seq_StrelArray, i1);
      seq_StrelArray_data = seq_StrelArray->data;
      c_emxCopyStruct_images_internal(
          &seq_StrelArray_data[seq_StrelArray_tmp - 1],
          &obj_DecomposedStrelArray_data[0].f1->data[n]);
      i1 =
          seq_DecomposedStrelArray->size[0] * seq_DecomposedStrelArray->size[1];
      seq_DecomposedStrelArray->size[0] = 1;
      seq_DecomposedStrelArray->size[1]++;
      emxEnsureCapacity_cell_wrap_221(seq_DecomposedStrelArray, i1);
      seq_DecomposedStrelArray_data = seq_DecomposedStrelArray->data;
      i1 = seq_DecomposedStrelArray_data[seq_StrelArray_tmp - 1].f1->size[0] *
           seq_DecomposedStrelArray_data[seq_StrelArray_tmp - 1].f1->size[1];
      seq_DecomposedStrelArray_data[seq_StrelArray_tmp - 1].f1->size[0] = 1;
      d_emxEnsureCapacity_images_inte(
          seq_DecomposedStrelArray_data[seq_StrelArray_tmp - 1].f1, i1);
      seq_DecomposedStrelArray_data[seq_DecomposedStrelArray->size[1] - 1]
          .f1->size[1] = 0;
      i1 = isEachStrelObj2D->size[1];
      seq_StrelArray_tmp =
          isEachStrelObj2D->size[0] * isEachStrelObj2D->size[1];
      isEachStrelObj2D->size[1]++;
      emxEnsureCapacity_boolean_T(isEachStrelObj2D, seq_StrelArray_tmp);
      isEachStrelObj2D_data = isEachStrelObj2D->data;
      isEachStrelObj2D_data[i1] = true;
    }
  }
}

void strel_getpadsize(const c_emxArray_images_internal_code *obj_StrelArray,
                      const emxArray_cell_wrap_22 *obj_DecomposedStrelArray,
                      double pad_ul_data[], int pad_ul_size[2],
                      double pad_lr_data[], int pad_lr_size[2])
{
  c_emxArray_images_internal_code *seq_StrelArray;
  c_images_internal_coder_strel_S *seq_StrelArray_data;
  cell_wrap_29 *offsets_data;
  cell_wrap_30 subs[3];
  emxArray_boolean_T b_seq_StrelArray;
  emxArray_cell_wrap_22 *expl_temp;
  emxArray_cell_wrap_29 *offsets;
  emxArray_int32_T *idx;
  emxArray_int32_T *ii;
  emxArray_int32_T *varargout_6;
  emxArray_int32_T *vk;
  emxArray_real_T *a;
  emxArray_real_T *minval;
  emxArray_real_T *offsets_;
  double *a_data;
  double *offsets__data;
  int center[3];
  int b_idx;
  int c_seq_StrelArray;
  int cpsiz_idx_1;
  int i;
  int i1;
  int i2;
  int k;
  int nx;
  int sInd;
  int *idx_data;
  int *ii_data;
  int *varargout_6_data;
  d_emxInit_images_internal_coder(&seq_StrelArray);
  emxInit_cell_wrap_22(&expl_temp);
  strel_decomposeImpl(obj_StrelArray, obj_DecomposedStrelArray, seq_StrelArray,
                      expl_temp);
  seq_StrelArray_data = seq_StrelArray->data;
  emxFree_cell_wrap_22(&expl_temp);
  i = seq_StrelArray->size[1];
  emxInit_cell_wrap_29(&offsets);
  i1 = offsets->size[0] * offsets->size[1];
  offsets->size[0] = 1;
  offsets->size[1] = seq_StrelArray->size[1];
  emxEnsureCapacity_cell_wrap_29(offsets, i1);
  offsets_data = offsets->data;
  emxInit_int32_T(&idx, 1);
  emxInitMatrix_cell_wrap_30(subs);
  emxInit_real_T(&offsets_, 2);
  emxInit_int32_T(&ii, 1);
  emxInit_int32_T(&varargout_6, 1);
  emxInit_int32_T(&vk, 1);
  emxInit_real_T(&a, 2);
  if (i - 1 >= 0) {
    center[2] = 1;
  }
  for (sInd = 0; sInd < i; sInd++) {
    unsigned int size_nhood_idx_0;
    if (seq_StrelArray_data[sInd].nhood->size[0] == 1) {
      cpsiz_idx_1 = seq_StrelArray_data[sInd].nhood->size[0] *
                    seq_StrelArray_data[sInd].nhood->size[1];
      b_seq_StrelArray = *seq_StrelArray_data[sInd].nhood;
      c_seq_StrelArray = cpsiz_idx_1;
      b_seq_StrelArray.size = &c_seq_StrelArray;
      b_seq_StrelArray.numDimensions = 1;
      eml_find(&b_seq_StrelArray, ii);
      ii_data = ii->data;
      i1 = idx->size[0];
      idx->size[0] = ii->size[0];
      emxEnsureCapacity_int32_T(idx, i1);
      idx_data = idx->data;
      b_idx = ii->size[0];
      for (i1 = 0; i1 < b_idx; i1++) {
        idx_data[i1] = ii_data[i1];
      }
    } else {
      boolean_T exitg1;
      nx = seq_StrelArray_data[sInd].nhood->size[0] *
           seq_StrelArray_data[sInd].nhood->size[1];
      b_idx = 0;
      i1 = ii->size[0];
      ii->size[0] = nx;
      emxEnsureCapacity_int32_T(ii, i1);
      ii_data = ii->data;
      cpsiz_idx_1 = 0;
      exitg1 = false;
      while ((!exitg1) && (cpsiz_idx_1 <= nx - 1)) {
        if (seq_StrelArray_data[sInd].nhood->data[cpsiz_idx_1]) {
          b_idx++;
          ii_data[b_idx - 1] = cpsiz_idx_1 + 1;
          if (b_idx >= nx) {
            exitg1 = true;
          } else {
            cpsiz_idx_1++;
          }
        } else {
          cpsiz_idx_1++;
        }
      }
      if (nx == 1) {
        if (b_idx == 0) {
          ii->size[0] = 0;
        }
      } else {
        i1 = ii->size[0];
        if (b_idx < 1) {
          ii->size[0] = 0;
        } else {
          ii->size[0] = b_idx;
        }
        emxEnsureCapacity_int32_T(ii, i1);
        ii_data = ii->data;
      }
      i1 = idx->size[0];
      idx->size[0] = ii->size[0];
      emxEnsureCapacity_int32_T(idx, i1);
      idx_data = idx->data;
      b_idx = ii->size[0];
      for (i1 = 0; i1 < b_idx; i1++) {
        idx_data[i1] = ii_data[i1];
      }
    }
    size_nhood_idx_0 = (unsigned int)seq_StrelArray_data[sInd].nhood->size[0];
    center[0] = (int)floor(
        ((double)seq_StrelArray_data[sInd].nhood->size[0] + 1.0) / 2.0);
    center[1] = (int)floor(
        ((double)seq_StrelArray_data[sInd].nhood->size[1] + 1.0) / 2.0);
    cpsiz_idx_1 =
        (int)size_nhood_idx_0 * seq_StrelArray_data[sInd].nhood->size[1];
    i1 = ii->size[0];
    ii->size[0] = idx->size[0];
    emxEnsureCapacity_int32_T(ii, i1);
    ii_data = ii->data;
    b_idx = idx->size[0];
    for (i1 = 0; i1 < b_idx; i1++) {
      ii_data[i1] = idx_data[i1] - 1;
    }
    i1 = vk->size[0];
    vk->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(vk, i1);
    idx_data = vk->data;
    b_idx = ii->size[0];
    for (i1 = 0; i1 < b_idx; i1++) {
      idx_data[i1] = div_s32(ii_data[i1], cpsiz_idx_1);
    }
    i1 = varargout_6->size[0];
    varargout_6->size[0] = vk->size[0];
    emxEnsureCapacity_int32_T(varargout_6, i1);
    varargout_6_data = varargout_6->data;
    b_idx = vk->size[0];
    for (i1 = 0; i1 < b_idx; i1++) {
      varargout_6_data[i1] = idx_data[i1] + 1;
      ii_data[i1] -= idx_data[i1] * cpsiz_idx_1;
    }
    i1 = vk->size[0];
    vk->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(vk, i1);
    idx_data = vk->data;
    b_idx = ii->size[0];
    for (i1 = 0; i1 < b_idx; i1++) {
      i2 = div_s32(ii_data[i1], (int)size_nhood_idx_0);
      idx_data[i1] = i2;
      ii_data[i1] -= i2 * (int)size_nhood_idx_0;
    }
    i1 = subs[0].f1->size[0];
    subs[0].f1->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(subs[0].f1, i1);
    b_idx = ii->size[0];
    i1 = subs[1].f1->size[0];
    subs[1].f1->size[0] = vk->size[0];
    emxEnsureCapacity_real_T(subs[1].f1, i1);
    i1 = subs[2].f1->size[0];
    subs[2].f1->size[0] = varargout_6->size[0];
    emxEnsureCapacity_real_T(subs[2].f1, i1);
    for (i1 = 0; i1 < b_idx; i1++) {
      subs[0].f1->data[i1] = ii_data[i1] + 1;
      subs[1].f1->data[i1] = idx_data[i1] + 1;
      subs[2].f1->data[i1] = varargout_6_data[i1];
    }
    i1 = offsets_->size[0] * offsets_->size[1];
    offsets_->size[0] = subs[0].f1->size[0];
    offsets_->size[1] = 3;
    emxEnsureCapacity_real_T(offsets_, i1);
    offsets__data = offsets_->data;
    cpsiz_idx_1 = 1;
    for (nx = 0; nx < 3; nx++) {
      i1 = subs[nx].f1->size[0] - 1;
      for (b_idx = 0; b_idx <= i1; b_idx++) {
        offsets__data[(cpsiz_idx_1 + b_idx) - 1] = subs[nx].f1->data[b_idx];
      }
      if (subs[nx].f1->size[0] - 1 >= 0) {
        cpsiz_idx_1 += subs[nx].f1->size[0];
      }
    }
    i1 = a->size[0] * a->size[1];
    a->size[0] = idx->size[0];
    a->size[1] = 3;
    emxEnsureCapacity_real_T(a, i1);
    a_data = a->data;
    b_idx = idx->size[0] * 3;
    for (i1 = 0; i1 < b_idx; i1++) {
      a_data[i1] = offsets__data[i1];
    }
    i1 = offsets_->size[0] * offsets_->size[1];
    offsets_->size[0] = idx->size[0];
    offsets_->size[1] = 3;
    emxEnsureCapacity_real_T(offsets_, i1);
    offsets__data = offsets_->data;
    if (idx->size[0] != 0) {
      cpsiz_idx_1 = (a->size[0] != 1);
      for (k = 0; k < 3; k++) {
        i1 = offsets_->size[0] - 1;
        for (nx = 0; nx <= i1; nx++) {
          offsets__data[nx + offsets_->size[0] * k] =
              a_data[cpsiz_idx_1 * nx + a->size[0] * k] - (double)center[k];
        }
      }
    }
    b_idx = offsets_->size[0];
    i1 = offsets_data[sInd].f1->size[0] * offsets_data[sInd].f1->size[1];
    offsets_data[sInd].f1->size[0] = offsets_->size[0];
    offsets_data[sInd].f1->size[1] = 2;
    emxEnsureCapacity_real_T(offsets_data[sInd].f1, i1);
    for (i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < b_idx; i2++) {
        offsets_data[sInd].f1->data[i2 + offsets_data[sInd].f1->size[0] * i1] =
            offsets__data[i2 + offsets_->size[0] * i1];
      }
    }
  }
  emxFree_real_T(&a);
  emxFree_int32_T(&vk);
  emxFree_int32_T(&varargout_6);
  emxFree_int32_T(&ii);
  emxFree_real_T(&offsets_);
  emxFreeMatrix_cell_wrap_30(subs);
  emxFree_int32_T(&idx);
  c_emxFree_images_internal_coder(&seq_StrelArray);
  if (offsets->size[1] == 0) {
    pad_ul_size[0] = 1;
    pad_ul_size[1] = 2;
    pad_lr_size[0] = 1;
    pad_lr_size[1] = 2;
    pad_ul_data[0] = 0.0;
    pad_lr_data[0] = 0.0;
    pad_ul_data[1] = 0.0;
    pad_lr_data[1] = 0.0;
  } else {
    i = offsets->size[1];
    for (k = 0; k < i; k++) {
      boolean_T b;
      boolean_T empty_non_axis_sizes;
      b = ((offsets_data[k].f1->size[0] != 0) &&
           (offsets_data[k].f1->size[1] != 0));
      if (b) {
        cpsiz_idx_1 = offsets_data[k].f1->size[0];
      } else if ((offsets_data[k].f1->size[0] != 0) &&
                 (2 - offsets_data[k].f1->size[1] != 0)) {
        cpsiz_idx_1 = offsets_data[k].f1->size[0];
      } else {
        cpsiz_idx_1 = offsets_data[k].f1->size[0];
        if (offsets_data[k].f1->size[0] > cpsiz_idx_1) {
          cpsiz_idx_1 = offsets_data[k].f1->size[0];
        }
      }
      empty_non_axis_sizes = (cpsiz_idx_1 == 0);
      if (empty_non_axis_sizes || b) {
        b_idx = offsets_data[k].f1->size[1];
      } else {
        b_idx = 0;
      }
      if (empty_non_axis_sizes || ((offsets_data[k].f1->size[0] != 0) &&
                                   (2 - offsets_data[k].f1->size[1] != 0))) {
        nx = 2 - offsets_data[k].f1->size[1];
      } else {
        nx = 0;
      }
      for (i1 = 0; i1 < b_idx; i1++) {
        for (i2 = 0; i2 < cpsiz_idx_1; i2++) {
          offsets_data[k].f1->data[i2 + offsets_data[k].f1->size[0] * i1] =
              offsets_data[k].f1->data[i2 + cpsiz_idx_1 * i1];
        }
      }
      i1 = offsets_data[k].f1->size[0] * offsets_data[k].f1->size[1];
      offsets_data[k].f1->size[0] = cpsiz_idx_1;
      offsets_data[k].f1->size[1] = b_idx + nx;
      emxEnsureCapacity_real_T(offsets_data[k].f1, i1);
      for (i1 = 0; i1 < nx; i1++) {
        for (i2 = 0; i2 < cpsiz_idx_1; i2++) {
          offsets_data[k]
              .f1->data[i2 + offsets_data[k].f1->size[0] * (i1 + b_idx)] = 0.0;
        }
      }
    }
    pad_ul_size[0] = 1;
    pad_ul_size[1] = 2;
    pad_lr_size[0] = 1;
    pad_lr_size[1] = 2;
    pad_ul_data[0] = 0.0;
    pad_lr_data[0] = 0.0;
    pad_ul_data[1] = 0.0;
    pad_lr_data[1] = 0.0;
    i = offsets->size[1];
    emxInit_real_T(&minval, 2);
    for (k = 0; k < i; k++) {
      i1 = offsets_data[k].f1->size[0];
      i2 = offsets_data[k].f1->size[1];
      if ((offsets_data[k].f1->size[0] != 0) &&
          (offsets_data[k].f1->size[1] != 0)) {
        double varargin_2;
        cpsiz_idx_1 = minval->size[0] * minval->size[1];
        minval->size[0] = 1;
        minval->size[1] = offsets_data[k].f1->size[1];
        emxEnsureCapacity_real_T(minval, cpsiz_idx_1);
        offsets__data = minval->data;
        if (offsets_data[k].f1->size[1] >= 1) {
          for (nx = 0; nx < i2; nx++) {
            offsets__data[nx] =
                offsets_data[k].f1->data[offsets_data[k].f1->size[0] * nx];
            for (b_idx = 2; b_idx <= i1; b_idx++) {
              varargin_2 =
                  offsets_data[k]
                      .f1->data[(b_idx + offsets_data[k].f1->size[0] * nx) - 1];
              if (offsets__data[nx] > varargin_2) {
                offsets__data[nx] = varargin_2;
              }
            }
          }
        }
        pad_ul_size[0] = 1;
        pad_ul_size[1] = 2;
        varargin_2 = -offsets__data[0];
        pad_ul_data[0] += fmax(0.0, varargin_2);
        varargin_2 = -offsets__data[1];
        pad_ul_data[1] += fmax(0.0, varargin_2);
        cpsiz_idx_1 = offsets_data[k].f1->size[0];
        i1 = offsets_data[k].f1->size[1];
        i2 = minval->size[0] * minval->size[1];
        minval->size[0] = 1;
        minval->size[1] = offsets_data[k].f1->size[1];
        emxEnsureCapacity_real_T(minval, i2);
        offsets__data = minval->data;
        if (offsets_data[k].f1->size[1] >= 1) {
          for (nx = 0; nx < i1; nx++) {
            offsets__data[nx] =
                offsets_data[k].f1->data[offsets_data[k].f1->size[0] * nx];
            for (b_idx = 2; b_idx <= cpsiz_idx_1; b_idx++) {
              varargin_2 =
                  offsets_data[k]
                      .f1->data[(b_idx + offsets_data[k].f1->size[0] * nx) - 1];
              if (offsets__data[nx] < varargin_2) {
                offsets__data[nx] = varargin_2;
              }
            }
          }
        }
        pad_lr_size[0] = 1;
        pad_lr_size[1] = 2;
        varargin_2 = offsets__data[0];
        pad_lr_data[0] += fmax(0.0, varargin_2);
        varargin_2 = offsets__data[1];
        pad_lr_data[1] += fmax(0.0, varargin_2);
      }
    }
    emxFree_real_T(&minval);
  }
  emxFree_cell_wrap_29(&offsets);
}

boolean_T strel_isdecompositionorthogonal(
    const c_emxArray_images_internal_code *obj_StrelArray,
    const emxArray_cell_wrap_22 *obj_DecomposedStrelArray)
{
  c_emxArray_images_internal_code *seq_StrelArray;
  c_images_internal_coder_strel_S *seq_StrelArray_data;
  emxArray_boolean_T *x;
  emxArray_cell_wrap_22 *expl_temp;
  emxArray_uint32_T *P;
  int nz[3];
  int i;
  int sInd;
  int vlen;
  int xpageoffset;
  unsigned int *P_data;
  boolean_T b_x_data[3];
  boolean_T TF;
  boolean_T exitg1;
  boolean_T *x_data;
  d_emxInit_images_internal_coder(&seq_StrelArray);
  emxInit_cell_wrap_22(&expl_temp);
  strel_decomposeImpl(obj_StrelArray, obj_DecomposedStrelArray, seq_StrelArray,
                      expl_temp);
  seq_StrelArray_data = seq_StrelArray->data;
  emxFree_cell_wrap_22(&expl_temp);
  emxInit_uint32_T(&P);
  vlen = P->size[0] * P->size[1];
  P->size[0] = seq_StrelArray->size[1];
  P->size[1] = 3;
  emxEnsureCapacity_uint32_T(P, vlen);
  P_data = P->data;
  xpageoffset = seq_StrelArray->size[1] * 3;
  for (vlen = 0; vlen < xpageoffset; vlen++) {
    P_data[vlen] = 1U;
  }
  vlen = seq_StrelArray->size[1];
  for (sInd = 0; sInd < vlen; sInd++) {
    P_data[sInd] = (unsigned int)seq_StrelArray_data[sInd].nhood->size[0];
    P_data[sInd + P->size[0]] =
        (unsigned int)seq_StrelArray_data[sInd].nhood->size[1];
    P_data[sInd + P->size[0] * 2] = 1U;
  }
  c_emxFree_images_internal_coder(&seq_StrelArray);
  vlen = P->size[0] * 3 - 1;
  for (i = 0; i <= vlen; i++) {
    if ((int)P_data[i] == 0) {
      P_data[i] = 1U;
    }
  }
  emxInit_boolean_T(&x, 2);
  vlen = x->size[0] * x->size[1];
  x->size[0] = P->size[0];
  x->size[1] = 3;
  emxEnsureCapacity_boolean_T(x, vlen);
  x_data = x->data;
  for (vlen = 0; vlen < xpageoffset; vlen++) {
    x_data[vlen] = ((int)P_data[vlen] != 1);
  }
  emxFree_uint32_T(&P);
  vlen = x->size[0];
  if (x->size[0] == 0) {
    nz[0] = 0;
    nz[1] = 0;
    nz[2] = 0;
  } else {
    for (i = 0; i < 3; i++) {
      xpageoffset = i * x->size[0];
      nz[i] = x_data[xpageoffset];
      for (sInd = 2; sInd <= vlen; sInd++) {
        nz[i] += x_data[(xpageoffset + sInd) - 1];
      }
    }
  }
  emxFree_boolean_T(&x);
  b_x_data[0] = (nz[0] == 1);
  b_x_data[1] = (nz[1] == 1);
  b_x_data[2] = (nz[2] == 1);
  TF = false;
  sInd = 0;
  exitg1 = false;
  while ((!exitg1) && (sInd <= 2)) {
    if (b_x_data[sInd]) {
      TF = true;
      exitg1 = true;
    } else {
      sInd++;
    }
  }
  return TF;
}

void strel_parenReference(strel *obj, double idx)
{
  d_emxArray_images_internal_code strelArray;
  emxArray_cell_wrap_22_1x1 decomposedStrelArray;
  int i;
  int loop_ub;
  c_emxInit_images_internal_coder(&strelArray);
  i = strelArray.size[0] * strelArray.size[1];
  strelArray.size[0] = 1;
  strelArray.size[1] = 1;
  c_emxEnsureCapacity_images_inte(&strelArray.data[0], strelArray.size, i);
  c_emxCopyStruct_images_internal(&strelArray.data[0],
                                  &obj->StrelArray->data[(int)idx - 1]);
  emxInit_cell_wrap_22_1x1(&decomposedStrelArray);
  i = decomposedStrelArray.size[0] * decomposedStrelArray.size[1];
  decomposedStrelArray.size[0] = 1;
  decomposedStrelArray.size[1] = 1;
  emxEnsureCapacity_cell_wrap_22(&decomposedStrelArray.data[0],
                                 decomposedStrelArray.size, i);
  i = decomposedStrelArray.data[0].f1->size[0] *
      decomposedStrelArray.data[0].f1->size[1];
  decomposedStrelArray.data[0].f1->size[0] = 1;
  decomposedStrelArray.data[0].f1->size[1] =
      obj->DecomposedStrelArray->data[(int)idx - 1].f1->size[1];
  d_emxEnsureCapacity_images_inte(decomposedStrelArray.data[0].f1, i);
  loop_ub = obj->DecomposedStrelArray->data[(int)idx - 1].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    c_emxCopyStruct_images_internal(
        &decomposedStrelArray.data[0].f1->data[i],
        &obj->DecomposedStrelArray->data[(int)idx - 1].f1->data[i]);
  }
  i = obj->StrelArray->size[0] * obj->StrelArray->size[1];
  obj->StrelArray->size[0] = 1;
  obj->StrelArray->size[1] = 1;
  d_emxEnsureCapacity_images_inte(obj->StrelArray, i);
  c_emxCopyStruct_images_internal(&obj->StrelArray->data[0],
                                  &strelArray.data[0]);
  d_emxFree_images_internal_coder(&strelArray);
  i = obj->DecomposedStrelArray->size[0] * obj->DecomposedStrelArray->size[1];
  obj->DecomposedStrelArray->size[0] = 1;
  obj->DecomposedStrelArray->size[1] = 1;
  emxEnsureCapacity_cell_wrap_221(obj->DecomposedStrelArray, i);
  emxCopyStruct_cell_wrap_22(&obj->DecomposedStrelArray->data[0],
                             &decomposedStrelArray.data[0]);
  emxFree_cell_wrap_22_1x1(&decomposedStrelArray);
}

void strel_strel(double varargin_2,
                 c_emxArray_images_internal_code *obj_StrelArray,
                 emxArray_cell_wrap_22 *obj_DecomposedStrelArray)
{
  c_emxArray_images_internal_code *tempStrelArray;
  c_images_internal_coder_strel_S expl_temp;
  c_images_internal_coder_strel_S *tempStrelArray_data;
  cell_wrap_22 *obj_DecomposedStrelArray_data;
  d_emxArray_images_internal_code strelArray;
  emxArray_cell_wrap_22_1x1 decomposedStrelArray;
  emxArray_int8_T *t0_height;
  int i;
  int k;
  int loop_ub_tmp;
  signed char *t0_height_data;
  d_emxInit_images_internal_coder(&tempStrelArray);
  tempStrelArray_data = tempStrelArray->data;
  tempStrelArray->size[0] = 1;
  tempStrelArray->size[1] = 0;
  c_emxInitStruct_images_internal(&expl_temp);
  i = expl_temp.nhood->size[0] * expl_temp.nhood->size[1] *
      expl_temp.nhood->size[2];
  expl_temp.nhood->size[0] = (int)varargin_2;
  expl_temp.nhood->size[1] = (int)varargin_2;
  expl_temp.nhood->size[2] = 1;
  emxEnsureCapacity_boolean_T(expl_temp.nhood, i);
  loop_ub_tmp = (int)varargin_2 * (int)varargin_2;
  for (i = 0; i < loop_ub_tmp; i++) {
    expl_temp.nhood->data[i] = true;
  }
  emxInit_int8_T(&t0_height, 3);
  i = t0_height->size[0] * t0_height->size[1] * t0_height->size[2];
  t0_height->size[0] = (int)varargin_2;
  t0_height->size[1] = (int)varargin_2;
  t0_height->size[2] = 1;
  emxEnsureCapacity_int8_T(t0_height, i);
  t0_height_data = t0_height->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    t0_height_data[i] = 0;
  }
  c_emxInit_images_internal_coder(&strelArray);
  i = strelArray.size[0] * strelArray.size[1];
  strelArray.size[0] = 1;
  strelArray.size[1] = 1;
  c_emxEnsureCapacity_images_inte(&strelArray.data[0], strelArray.size, i);
  i = strelArray.data[0].nhood->size[0] * strelArray.data[0].nhood->size[1] *
      strelArray.data[0].nhood->size[2];
  strelArray.data[0].nhood->size[0] = expl_temp.nhood->size[0];
  strelArray.data[0].nhood->size[1] = expl_temp.nhood->size[1];
  strelArray.data[0].nhood->size[2] = 1;
  emxEnsureCapacity_boolean_T(strelArray.data[0].nhood, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    strelArray.data[0].nhood->data[i] = true;
  }
  i = strelArray.data[0].height->size[0] * strelArray.data[0].height->size[1] *
      strelArray.data[0].height->size[2];
  strelArray.data[0].height->size[0] = t0_height->size[0];
  strelArray.data[0].height->size[1] = t0_height->size[1];
  strelArray.data[0].height->size[2] = 1;
  emxEnsureCapacity_real_T(strelArray.data[0].height, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    strelArray.data[0].height->data[i] = 0.0;
  }
  strelArray.data[0].Flat = true;
  if ((double)(int)varargin_2 * (double)(int)varargin_2 /
          ((double)(int)varargin_2 + (double)(int)varargin_2) >=
      2.0) {
    int b_varargin_2[2];
    b_varargin_2[0] = (int)varargin_2;
    b_varargin_2[1] = (int)varargin_2;
    expl_temp.Flat = true;
    for (k = 0; k < 2; k++) {
      int size_k[3];
      int b_tempStrelArray;
      size_k[0] = 1;
      size_k[1] = 1;
      size_k[k] = b_varargin_2[k];
      i = expl_temp.nhood->size[0] * expl_temp.nhood->size[1] *
          expl_temp.nhood->size[2];
      expl_temp.nhood->size[0] = size_k[0];
      expl_temp.nhood->size[1] = size_k[1];
      expl_temp.nhood->size[2] = 1;
      emxEnsureCapacity_boolean_T(expl_temp.nhood, i);
      loop_ub_tmp = size_k[0] * size_k[1];
      for (i = 0; i < loop_ub_tmp; i++) {
        expl_temp.nhood->data[i] = true;
      }
      i = t0_height->size[0] * t0_height->size[1] * t0_height->size[2];
      t0_height->size[0] = size_k[0];
      t0_height->size[1] = size_k[1];
      t0_height->size[2] = 1;
      emxEnsureCapacity_int8_T(t0_height, i);
      t0_height_data = t0_height->data;
      for (i = 0; i < loop_ub_tmp; i++) {
        t0_height_data[i] = 0;
      }
      b_tempStrelArray = tempStrelArray->size[1] + 1;
      i = tempStrelArray->size[0] * tempStrelArray->size[1];
      tempStrelArray->size[0] = 1;
      tempStrelArray->size[1]++;
      d_emxEnsureCapacity_images_inte(tempStrelArray, i);
      tempStrelArray_data = tempStrelArray->data;
      i = expl_temp.height->size[0] * expl_temp.height->size[1] *
          expl_temp.height->size[2];
      expl_temp.height->size[0] = t0_height->size[0];
      expl_temp.height->size[1] = t0_height->size[1];
      expl_temp.height->size[2] = 1;
      emxEnsureCapacity_real_T(expl_temp.height, i);
      for (i = 0; i < loop_ub_tmp; i++) {
        expl_temp.height->data[i] = 0.0;
      }
      c_emxCopyStruct_images_internal(
          &tempStrelArray_data[b_tempStrelArray - 1], &expl_temp);
    }
  }
  c_emxFreeStruct_images_internal(&expl_temp);
  emxFree_int8_T(&t0_height);
  emxInit_cell_wrap_22_1x1(&decomposedStrelArray);
  i = decomposedStrelArray.size[0] * decomposedStrelArray.size[1];
  decomposedStrelArray.size[0] = 1;
  decomposedStrelArray.size[1] = 1;
  emxEnsureCapacity_cell_wrap_22(&decomposedStrelArray.data[0],
                                 decomposedStrelArray.size, i);
  i = decomposedStrelArray.data[0].f1->size[0] *
      decomposedStrelArray.data[0].f1->size[1];
  decomposedStrelArray.data[0].f1->size[0] = 1;
  decomposedStrelArray.data[0].f1->size[1] = tempStrelArray->size[1];
  d_emxEnsureCapacity_images_inte(decomposedStrelArray.data[0].f1, i);
  loop_ub_tmp = tempStrelArray->size[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    c_emxCopyStruct_images_internal(&decomposedStrelArray.data[0].f1->data[i],
                                    &tempStrelArray_data[i]);
  }
  c_emxFree_images_internal_coder(&tempStrelArray);
  i = obj_StrelArray->size[0] * obj_StrelArray->size[1];
  obj_StrelArray->size[0] = 1;
  obj_StrelArray->size[1] = 1;
  d_emxEnsureCapacity_images_inte(obj_StrelArray, i);
  tempStrelArray_data = obj_StrelArray->data;
  c_emxCopyStruct_images_internal(&tempStrelArray_data[0], &strelArray.data[0]);
  d_emxFree_images_internal_coder(&strelArray);
  i = obj_DecomposedStrelArray->size[0] * obj_DecomposedStrelArray->size[1];
  obj_DecomposedStrelArray->size[0] = 1;
  obj_DecomposedStrelArray->size[1] = 1;
  emxEnsureCapacity_cell_wrap_221(obj_DecomposedStrelArray, i);
  obj_DecomposedStrelArray_data = obj_DecomposedStrelArray->data;
  emxCopyStruct_cell_wrap_22(&obj_DecomposedStrelArray_data[0],
                             &decomposedStrelArray.data[0]);
  emxFree_cell_wrap_22_1x1(&decomposedStrelArray);
}

/* End of code generation (strel.c) */
