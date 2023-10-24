/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * padarray.c
 *
 * Code generation for function 'padarray'
 *
 */

/* Include files */
#include "padarray.h"
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"
#include "colon.h"
#include <math.h>

/* Function Definitions */
void b_padarray(const emxArray_boolean_T *varargin_1,
                const double varargin_2_data[], emxArray_boolean_T *b)
{
  int b_i;
  int i;
  int j;
  const boolean_T *varargin_1_data;
  boolean_T *b_data;
  varargin_1_data = varargin_1->data;
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    double sizeB_idx_0;
    double sizeB_idx_1;
    int loop_ub;
    sizeB_idx_0 = (double)varargin_1->size[0] + varargin_2_data[0];
    sizeB_idx_1 = (double)varargin_1->size[1] + varargin_2_data[1];
    i = b->size[0] * b->size[1];
    b->size[0] = (int)sizeB_idx_0;
    b->size[1] = (int)sizeB_idx_1;
    emxEnsureCapacity_boolean_T(b, i);
    b_data = b->data;
    loop_ub = (int)sizeB_idx_0 * (int)sizeB_idx_1;
    for (i = 0; i < loop_ub; i++) {
      b_data[i] = false;
    }
  } else {
    int i1;
    int loop_ub;
    i = b->size[0] * b->size[1];
    b->size[0] = (int)((double)varargin_1->size[0] + varargin_2_data[0]);
    loop_ub = (int)((double)varargin_1->size[1] + varargin_2_data[1]);
    b->size[1] = (int)((double)varargin_1->size[1] + varargin_2_data[1]);
    emxEnsureCapacity_boolean_T(b, i);
    b_data = b->data;
    i = varargin_1->size[1] + 1;
    for (j = i; j <= loop_ub; j++) {
      i1 = b->size[0];
      for (b_i = 0; b_i < i1; b_i++) {
        b_data[b_i + b->size[0] * (j - 1)] = false;
      }
    }
    i = varargin_1->size[1];
    loop_ub = varargin_1->size[0] + 1;
    for (j = 0; j < i; j++) {
      i1 = b->size[0];
      for (b_i = loop_ub; b_i <= i1; b_i++) {
        b_data[(b_i + b->size[0] * j) - 1] = false;
      }
    }
    i = varargin_1->size[1];
    loop_ub = varargin_1->size[0];
    for (j = 0; j < i; j++) {
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_data[b_i + b->size[0] * j] =
            varargin_1_data[b_i + varargin_1->size[0] * j];
      }
    }
  }
}

void padarray(const emxArray_real_T *varargin_1, const double varargin_2[2],
              emxArray_real_T *b)
{
  emxArray_int32_T *idxA;
  emxArray_real_T *y;
  emxArray_uint32_T *dimNums;
  emxArray_uint32_T *idxDir;
  const double *varargin_1_data;
  double *b_data;
  int b_i;
  int i;
  int j;
  unsigned int *dimNums_data;
  int *idxA_data;
  unsigned int *idxDir_data;
  varargin_1_data = varargin_1->data;
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    double sizeB_idx_0;
    double sizeB_idx_1;
    int loop_ub_tmp;
    sizeB_idx_0 = (double)varargin_1->size[0] + 2.0 * varargin_2[0];
    sizeB_idx_1 = (double)varargin_1->size[1] + 2.0 * varargin_2[1];
    i = b->size[0] * b->size[1];
    b->size[0] = (int)sizeB_idx_0;
    b->size[1] = (int)sizeB_idx_1;
    emxEnsureCapacity_real_T(b, i);
    b_data = b->data;
    loop_ub_tmp = (int)sizeB_idx_0 * (int)sizeB_idx_1;
    for (i = 0; i < loop_ub_tmp; i++) {
      b_data[i] = 0.0;
    }
  } else {
    double sizeB_idx_0;
    double sizeB_idx_1;
    double varargin_1_idx_0_tmp;
    double varargin_1_idx_1_tmp;
    double varargout_1;
    unsigned int b_varargin_2;
    int loop_ub_tmp;
    sizeB_idx_0 = varargin_1->size[0];
    sizeB_idx_1 = varargin_1->size[1];
    varargin_1_idx_0_tmp = 2.0 * varargin_2[0] + (double)varargin_1->size[0];
    varargin_1_idx_1_tmp = 2.0 * varargin_2[1] + (double)varargin_1->size[1];
    emxInit_int32_T(&idxA, 2);
    i = idxA->size[0] * idxA->size[1];
    if (varargin_1_idx_0_tmp < varargin_1_idx_1_tmp) {
      idxA->size[0] = (int)varargin_1_idx_1_tmp;
    } else {
      idxA->size[0] = (int)varargin_1_idx_0_tmp;
    }
    idxA->size[1] = 2;
    emxEnsureCapacity_int32_T(idxA, i);
    idxA_data = idxA->data;
    emxInit_real_T(&y, 2);
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = varargin_1->size[0];
    emxEnsureCapacity_real_T(y, i);
    b_data = y->data;
    loop_ub_tmp = varargin_1->size[0] - 1;
    for (i = 0; i <= loop_ub_tmp; i++) {
      b_data[i] = (double)i + 1.0;
    }
    emxInit_uint32_T(&idxDir);
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = varargin_1->size[0];
    emxEnsureCapacity_uint32_T(idxDir, i);
    idxDir_data = idxDir->data;
    for (i = 0; i <= loop_ub_tmp; i++) {
      idxDir_data[i] = (unsigned int)sizeB_idx_0 - (unsigned int)i;
    }
    emxInit_uint32_T(&dimNums);
    i = dimNums->size[0] * dimNums->size[1];
    dimNums->size[0] = 1;
    dimNums->size[1] = y->size[1] + idxDir->size[1];
    emxEnsureCapacity_uint32_T(dimNums, i);
    dimNums_data = dimNums->data;
    loop_ub_tmp = y->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      dimNums_data[i] = (unsigned int)b_data[i];
    }
    loop_ub_tmp = idxDir->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      dimNums_data[i + y->size[1]] = idxDir_data[i];
    }
    sizeB_idx_0 = ((double)varargin_1->size[0] + varargin_2[0]) - 1.0;
    if (sizeB_idx_0 < -varargin_2[0]) {
      y->size[0] = 1;
      y->size[1] = 0;
    } else if (floor(-varargin_2[0]) == -varargin_2[0]) {
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      loop_ub_tmp = (int)(sizeB_idx_0 - (-varargin_2[0]));
      y->size[1] = loop_ub_tmp + 1;
      emxEnsureCapacity_real_T(y, i);
      b_data = y->data;
      for (i = 0; i <= loop_ub_tmp; i++) {
        b_data[i] = -varargin_2[0] + (double)i;
      }
    } else {
      eml_float_colon(-varargin_2[0], sizeB_idx_0, y);
      b_data = y->data;
    }
    b_varargin_2 = (unsigned int)varargin_1->size[0] << 1;
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = y->size[1];
    emxEnsureCapacity_uint32_T(idxDir, i);
    idxDir_data = idxDir->data;
    loop_ub_tmp = y->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      sizeB_idx_0 = b_data[i];
      varargout_1 = sizeB_idx_0;
      if (b_varargin_2 == 0U) {
        if (sizeB_idx_0 == 0.0) {
          varargout_1 = 0.0;
        }
      } else if (sizeB_idx_0 == 0.0) {
        varargout_1 = 0.0;
      } else {
        varargout_1 = fmod(sizeB_idx_0, b_varargin_2);
        if (varargout_1 == 0.0) {
          varargout_1 = 0.0;
        } else if (sizeB_idx_0 < 0.0) {
          varargout_1 += (double)b_varargin_2;
        }
      }
      idxDir_data[i] = dimNums_data[(int)(varargout_1 + 1.0) - 1];
    }
    loop_ub_tmp = y->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      idxA_data[i] = (int)idxDir_data[i];
    }
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = varargin_1->size[1];
    emxEnsureCapacity_real_T(y, i);
    b_data = y->data;
    loop_ub_tmp = varargin_1->size[1] - 1;
    for (i = 0; i <= loop_ub_tmp; i++) {
      b_data[i] = (double)i + 1.0;
    }
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = varargin_1->size[1];
    emxEnsureCapacity_uint32_T(idxDir, i);
    idxDir_data = idxDir->data;
    for (i = 0; i <= loop_ub_tmp; i++) {
      idxDir_data[i] = (unsigned int)sizeB_idx_1 - (unsigned int)i;
    }
    i = dimNums->size[0] * dimNums->size[1];
    dimNums->size[0] = 1;
    dimNums->size[1] = y->size[1] + idxDir->size[1];
    emxEnsureCapacity_uint32_T(dimNums, i);
    dimNums_data = dimNums->data;
    loop_ub_tmp = y->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      dimNums_data[i] = (unsigned int)b_data[i];
    }
    loop_ub_tmp = idxDir->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      dimNums_data[i + y->size[1]] = idxDir_data[i];
    }
    sizeB_idx_0 = ((double)varargin_1->size[1] + varargin_2[1]) - 1.0;
    if (sizeB_idx_0 < -varargin_2[1]) {
      y->size[0] = 1;
      y->size[1] = 0;
    } else if (floor(-varargin_2[1]) == -varargin_2[1]) {
      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      loop_ub_tmp = (int)(sizeB_idx_0 - (-varargin_2[1]));
      y->size[1] = loop_ub_tmp + 1;
      emxEnsureCapacity_real_T(y, i);
      b_data = y->data;
      for (i = 0; i <= loop_ub_tmp; i++) {
        b_data[i] = -varargin_2[1] + (double)i;
      }
    } else {
      eml_float_colon(-varargin_2[1], sizeB_idx_0, y);
      b_data = y->data;
    }
    b_varargin_2 = (unsigned int)varargin_1->size[1] << 1;
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = y->size[1];
    emxEnsureCapacity_uint32_T(idxDir, i);
    idxDir_data = idxDir->data;
    loop_ub_tmp = y->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      sizeB_idx_0 = b_data[i];
      varargout_1 = sizeB_idx_0;
      if (b_varargin_2 == 0U) {
        if (sizeB_idx_0 == 0.0) {
          varargout_1 = 0.0;
        }
      } else if (sizeB_idx_0 == 0.0) {
        varargout_1 = 0.0;
      } else {
        varargout_1 = fmod(sizeB_idx_0, b_varargin_2);
        if (varargout_1 == 0.0) {
          varargout_1 = 0.0;
        } else if (sizeB_idx_0 < 0.0) {
          varargout_1 += (double)b_varargin_2;
        }
      }
      idxDir_data[i] = dimNums_data[(int)(varargout_1 + 1.0) - 1];
    }
    emxFree_uint32_T(&dimNums);
    loop_ub_tmp = y->size[1];
    emxFree_real_T(&y);
    for (i = 0; i < loop_ub_tmp; i++) {
      idxA_data[i + idxA->size[0]] = (int)idxDir_data[i];
    }
    emxFree_uint32_T(&idxDir);
    i = b->size[0] * b->size[1];
    b->size[0] = (int)varargin_1_idx_0_tmp;
    loop_ub_tmp = (int)varargin_1_idx_1_tmp;
    b->size[1] = (int)varargin_1_idx_1_tmp;
    emxEnsureCapacity_real_T(b, i);
    b_data = b->data;
    for (j = 0; j < loop_ub_tmp; j++) {
      i = b->size[0];
      for (b_i = 0; b_i < i; b_i++) {
        b_data[b_i + b->size[0] * j] =
            varargin_1_data[(idxA_data[b_i] +
                             varargin_1->size[0] *
                                 (idxA_data[j + idxA->size[0]] - 1)) -
                            1];
      }
    }
    emxFree_int32_T(&idxA);
  }
}

/* End of code generation (padarray.c) */
