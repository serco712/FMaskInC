/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imfilter.c
 *
 * Code generation for function 'imfilter'
 *
 */

/* Include files */
#include "imfilter.h"
#include "CDI_emxutil.h"
#include "CDI_types.h"
#include <math.h>

/* Function Definitions */
void padImage(const emxArray_real_T *a_tmp, const double pad[2],
              emxArray_real_T *a)
{
  emxArray_int32_T *idxA;
  emxArray_real_T *y;
  emxArray_uint32_T *dimNums;
  emxArray_uint32_T *idxDir;
  const double *a_tmp_data;
  double *a_data;
  int b_i;
  int i;
  int loop_ub_tmp;
  unsigned int *dimNums_data;
  int *idxA_data;
  unsigned int *idxDir_data;
  a_tmp_data = a_tmp->data;
  if ((a_tmp->size[0] == 0) || (a_tmp->size[1] == 0)) {
    double sizeB_idx_0;
    double sizeB_idx_1;
    sizeB_idx_0 = (double)a_tmp->size[0] + 2.0 * pad[0];
    sizeB_idx_1 = (double)a_tmp->size[1] + 2.0 * pad[1];
    i = a->size[0] * a->size[1];
    a->size[0] = (int)sizeB_idx_0;
    a->size[1] = (int)sizeB_idx_1;
    emxEnsureCapacity_real_T(a, i);
    a_data = a->data;
    loop_ub_tmp = (int)sizeB_idx_0 * (int)sizeB_idx_1;
    for (i = 0; i < loop_ub_tmp; i++) {
      a_data[i] = 0.0;
    }
  } else {
    double sizeB_idx_0;
    double sizeB_idx_1;
    int i1;
    unsigned int varargin_2;
    sizeB_idx_0 = a_tmp->size[0];
    sizeB_idx_1 = a_tmp->size[1];
    emxInit_int32_T(&idxA);
    i = idxA->size[0] * idxA->size[1];
    if ((unsigned int)a_tmp->size[0] + 6U < (unsigned int)a_tmp->size[1] + 6U) {
      idxA->size[0] = (int)((unsigned int)a_tmp->size[1] + 6U);
    } else {
      idxA->size[0] = (int)((unsigned int)a_tmp->size[0] + 6U);
    }
    idxA->size[1] = 2;
    emxEnsureCapacity_int32_T(idxA, i);
    idxA_data = idxA->data;
    emxInit_uint32_T(&idxDir);
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    i1 = a_tmp->size[0];
    idxDir->size[1] = i1;
    emxEnsureCapacity_uint32_T(idxDir, i);
    idxDir_data = idxDir->data;
    loop_ub_tmp = i1 - 1;
    for (i = 0; i <= loop_ub_tmp; i++) {
      idxDir_data[i] = (unsigned int)i + 1U;
    }
    emxInit_real_T(&y, 2);
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = i1;
    emxEnsureCapacity_real_T(y, i);
    a_data = y->data;
    for (i = 0; i <= loop_ub_tmp; i++) {
      a_data[i] = sizeB_idx_0 - (double)i;
    }
    emxInit_uint32_T(&dimNums);
    i = dimNums->size[0] * dimNums->size[1];
    dimNums->size[0] = 1;
    dimNums->size[1] = idxDir->size[1] + y->size[1];
    emxEnsureCapacity_uint32_T(dimNums, i);
    dimNums_data = dimNums->data;
    loop_ub_tmp = idxDir->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      dimNums_data[i] = idxDir_data[i];
    }
    loop_ub_tmp = y->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      sizeB_idx_0 = a_data[i];
      if (sizeB_idx_0 >= 0.0) {
        varargin_2 = (unsigned int)sizeB_idx_0;
      } else {
        varargin_2 = 0U;
      }
      dimNums_data[i + idxDir->size[1]] = varargin_2;
    }
    varargin_2 = (unsigned int)a_tmp->size[0] << 1;
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = (int)((((double)a_tmp->size[0] + 3.0) - 1.0) - -3.0) + 1;
    emxEnsureCapacity_uint32_T(idxDir, i);
    idxDir_data = idxDir->data;
    loop_ub_tmp = (int)((((double)a_tmp->size[0] + 3.0) - 1.0) - -3.0);
    for (i = 0; i <= loop_ub_tmp; i++) {
      sizeB_idx_0 = i + -3;
      if (varargin_2 == 0U) {
        if (i + -3 == 0) {
          sizeB_idx_0 = 0.0;
        }
      } else if (i + -3 == 0) {
        sizeB_idx_0 = 0.0;
      } else {
        sizeB_idx_0 = fmod(i + -3, varargin_2);
        if (sizeB_idx_0 == 0.0) {
          sizeB_idx_0 = 0.0;
        } else if (i + -3 < 0) {
          sizeB_idx_0 += (double)varargin_2;
        }
      }
      idxDir_data[i] = dimNums_data[(int)(sizeB_idx_0 + 1.0) - 1];
    }
    loop_ub_tmp = i1 + 6;
    for (i = 0; i < loop_ub_tmp; i++) {
      idxA_data[i] = (int)idxDir_data[i];
    }
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    i1 = a_tmp->size[1];
    idxDir->size[1] = i1;
    emxEnsureCapacity_uint32_T(idxDir, i);
    idxDir_data = idxDir->data;
    loop_ub_tmp = i1 - 1;
    for (i = 0; i <= loop_ub_tmp; i++) {
      idxDir_data[i] = (unsigned int)i + 1U;
    }
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = i1;
    emxEnsureCapacity_real_T(y, i);
    a_data = y->data;
    for (i = 0; i <= loop_ub_tmp; i++) {
      a_data[i] = sizeB_idx_1 - (double)i;
    }
    i = dimNums->size[0] * dimNums->size[1];
    dimNums->size[0] = 1;
    dimNums->size[1] = idxDir->size[1] + y->size[1];
    emxEnsureCapacity_uint32_T(dimNums, i);
    dimNums_data = dimNums->data;
    loop_ub_tmp = idxDir->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      dimNums_data[i] = idxDir_data[i];
    }
    loop_ub_tmp = y->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      sizeB_idx_0 = a_data[i];
      if (sizeB_idx_0 >= 0.0) {
        varargin_2 = (unsigned int)sizeB_idx_0;
      } else {
        varargin_2 = 0U;
      }
      dimNums_data[i + idxDir->size[1]] = varargin_2;
    }
    emxFree_real_T(&y);
    varargin_2 = (unsigned int)a_tmp->size[1] << 1;
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = (int)((((double)a_tmp->size[1] + 3.0) - 1.0) - -3.0) + 1;
    emxEnsureCapacity_uint32_T(idxDir, i);
    idxDir_data = idxDir->data;
    loop_ub_tmp = (int)((((double)a_tmp->size[1] + 3.0) - 1.0) - -3.0);
    for (i = 0; i <= loop_ub_tmp; i++) {
      sizeB_idx_0 = i + -3;
      if (varargin_2 == 0U) {
        if (i + -3 == 0) {
          sizeB_idx_0 = 0.0;
        }
      } else if (i + -3 == 0) {
        sizeB_idx_0 = 0.0;
      } else {
        sizeB_idx_0 = fmod(i + -3, varargin_2);
        if (sizeB_idx_0 == 0.0) {
          sizeB_idx_0 = 0.0;
        } else if (i + -3 < 0) {
          sizeB_idx_0 += (double)varargin_2;
        }
      }
      idxDir_data[i] = dimNums_data[(int)(sizeB_idx_0 + 1.0) - 1];
    }
    emxFree_uint32_T(&dimNums);
    loop_ub_tmp = i1 + 6;
    for (i = 0; i < loop_ub_tmp; i++) {
      idxA_data[i + idxA->size[0]] = (int)idxDir_data[i];
    }
    emxFree_uint32_T(&idxDir);
    i = a->size[0] * a->size[1];
    a->size[0] = (int)((double)a_tmp->size[0] + 2.0 * pad[0]);
    i1 = (int)((double)a_tmp->size[1] + 2.0 * pad[1]);
    a->size[1] = (int)((double)a_tmp->size[1] + 2.0 * pad[1]);
    emxEnsureCapacity_real_T(a, i);
    a_data = a->data;
    for (loop_ub_tmp = 0; loop_ub_tmp < i1; loop_ub_tmp++) {
      i = a->size[0];
      for (b_i = 0; b_i < i; b_i++) {
        a_data[b_i + a->size[0] * loop_ub_tmp] =
            a_tmp_data[(idxA_data[b_i] +
                        a_tmp->size[0] *
                            (idxA_data[loop_ub_tmp + idxA->size[0]] - 1)) -
                       1];
      }
    }
    emxFree_int32_T(&idxA);
  }
}

/* End of code generation (imfilter.c) */
