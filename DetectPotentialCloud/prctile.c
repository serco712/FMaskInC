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
#include "DetectPotentialCloud_emxutil.h"
#include "DetectPotentialCloud_types.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static double rt_roundd_snf(double u);

/* Function Definitions */
static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

float b_prctile(const emxArray_real32_T *x)
{
  emxArray_int32_T *idx;
  const float *x_data;
  float y;
  int *idx_data;
  x_data = x->data;
  if (x->size[0] == 0) {
    y = rtNaNF;
  } else {
    int nj;
    emxInit_int32_T(&idx);
    sortIdx(x, idx);
    idx_data = idx->data;
    nj = x->size[0];
    while ((nj > 0) && rtIsNaNF(x_data[idx_data[nj - 1] - 1])) {
      nj--;
    }
    if (nj < 1) {
      y = rtNaNF;
    } else if (nj == 1) {
      y = x_data[idx_data[0] - 1];
    } else {
      double r;
      int i;
      r = 0.175 * (double)nj;
      i = (int)rt_roundd_snf(r);
      if (i < 1) {
        y = x_data[idx_data[0] - 1];
      } else if (i >= nj) {
        y = x_data[idx_data[nj - 1] - 1];
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
    y = rtNaNF;
  } else {
    int nj;
    emxInit_int32_T(&idx);
    sortIdx(x, idx);
    idx_data = idx->data;
    nj = x->size[0];
    while ((nj > 0) && rtIsNaNF(x_data[idx_data[nj - 1] - 1])) {
      nj--;
    }
    if (nj < 1) {
      y = rtNaNF;
    } else if (nj == 1) {
      y = x_data[idx_data[0] - 1];
    } else {
      double r;
      int i;
      r = 0.825 * (double)nj;
      i = (int)rt_roundd_snf(r);
      if (i >= nj) {
        y = x_data[idx_data[nj - 1] - 1];
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
