/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * prctile.c
 *
 * Code generation for function 'prctile'
 *
 */

/* Include files */
#include "prctile.h"
#include "Fmask_emxutil.h"
#include "Fmask_rtwutil.h"
#include "Fmask_types.h"
#include "sortIdx.h"

/* Function Definitions */
float b_prctile(const emxArray_real32_T *x)
{
  emxArray_int32_T *idx;
  const float *x_data;
  float y;
  int *idx_data;
  x_data = x->data;
  if (x->size[0] == 0) {
    y = 0.0F;
  } else {
    emxInit_int32_T(&idx, 1);
    sortIdx(x, idx);
    idx_data = idx->data;
    if (x->size[0] == 1) {
      y = x_data[idx_data[0] - 1];
    } else {
      double r;
      int i;
      r = 0.175 * (double)x->size[0];
      i = (int)rt_roundd(r);
      if (i < 1) {
        y = x_data[idx_data[0] - 1];
      } else if (i >= x->size[0]) {
        y = x_data[idx_data[x->size[0] - 1] - 1];
      } else {
        r -= (double)i;
        y = (float)(0.5 - r) * x_data[idx_data[i - 1] - 1] +
            (float)(r + 0.5) * x_data[idx_data[i] - 1];
      }
    }
    emxFree_int32_T(&idx);
  }
  return y;
}

float prctile(const emxArray_real32_T *x)
{
  emxArray_int32_T *idx;
  const float *x_data;
  float y;
  int *idx_data;
  x_data = x->data;
  if (x->size[0] == 0) {
    y = 0.0F;
  } else {
    emxInit_int32_T(&idx, 1);
    sortIdx(x, idx);
    idx_data = idx->data;
    if (x->size[0] == 1) {
      y = x_data[idx_data[0] - 1];
    } else {
      double r;
      int i;
      r = 0.825 * (double)x->size[0];
      i = (int)rt_roundd(r);
      if (i >= x->size[0]) {
        y = x_data[idx_data[x->size[0] - 1] - 1];
      } else {
        r -= (double)i;
        y = (float)(0.5 - r) * x_data[idx_data[i - 1] - 1] +
            (float)(r + 0.5) * x_data[idx_data[i] - 1];
      }
    }
    emxFree_int32_T(&idx);
  }
  return y;
}

/* End of code generation (prctile.c) */
