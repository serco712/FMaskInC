/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * integralBoxFilter.c
 *
 * Code generation for function 'integralBoxFilter'
 *
 */

/* Include files */
#include "integralBoxFilter.h"
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"

/* Function Definitions */
void integralBoxFilter(const emxArray_real_T *intA, const double varargin_1[2],
                       double varargin_3, emxArray_real_T *out)
{
  const double *intA_data;
  double filterSize_idx_0;
  double filterSize_idx_1;
  double *out_data;
  int eC;
  int i;
  int i1;
  int m;
  int n;
  intA_data = intA->data;
  filterSize_idx_0 = varargin_1[0];
  filterSize_idx_1 = varargin_1[1];
  i = (int)((double)intA->size[0] - varargin_1[0]);
  eC = out->size[0] * out->size[1];
  out->size[0] = (int)((double)intA->size[0] - varargin_1[0]);
  i1 = (int)((double)intA->size[1] - varargin_1[1]);
  out->size[1] = (int)((double)intA->size[1] - varargin_1[1]);
  emxEnsureCapacity_real_T(out, eC);
  out_data = out->data;
  for (n = 0; n < i1; n++) {
    eC = n + (int)filterSize_idx_1;
    for (m = 0; m < i; m++) {
      int eR;
      eR = m + (int)filterSize_idx_0;
      out_data[m + out->size[0] * n] =
          varargin_3 * (((intA_data[eR + intA->size[0] * eC] +
                          intA_data[m + intA->size[0] * n]) -
                         intA_data[m + intA->size[0] * eC]) -
                        intA_data[eR + intA->size[0] * n]);
    }
  }
}

/* End of code generation (integralBoxFilter.c) */
