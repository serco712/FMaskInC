/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortIdx.c
 *
 * Code generation for function 'sortIdx'
 *
 */

/* Include files */
#include "sortIdx.h"
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"

/* Function Definitions */
void sortIdx(const emxArray_real32_T *x, emxArray_int32_T *idx)
{
  emxArray_int32_T *iwork;
  const float *x_data;
  int b_i;
  int i;
  int k;
  int n;
  int pEnd;
  int qEnd;
  int *idx_data;
  int *iwork_data;
  x_data = x->data;
  n = x->size[0] + 1;
  i = idx->size[0];
  idx->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(idx, i);
  idx_data = idx->data;
  b_i = x->size[0];
  for (i = 0; i < b_i; i++) {
    idx_data[i] = 0;
  }
  emxInit_int32_T(&iwork, 1);
  i = iwork->size[0];
  iwork->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(iwork, i);
  iwork_data = iwork->data;
  i = x->size[0] - 1;
  for (k = 1; k <= i; k += 2) {
    if (x_data[k - 1] <= x_data[k]) {
      idx_data[k - 1] = k;
      idx_data[k] = k + 1;
    } else {
      idx_data[k - 1] = k + 1;
      idx_data[k] = k;
    }
  }
  if ((x->size[0] & 1) != 0) {
    idx_data[x->size[0] - 1] = x->size[0];
  }
  b_i = 2;
  while (b_i < n - 1) {
    int i2;
    int j;
    i2 = b_i << 1;
    j = 1;
    for (pEnd = b_i + 1; pEnd < n; pEnd = qEnd + b_i) {
      int kEnd;
      int p;
      int q;
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > n) {
        qEnd = n;
      }
      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        int i1;
        i = idx_data[p - 1];
        i1 = idx_data[q - 1];
        if (x_data[i - 1] <= x_data[i1 - 1]) {
          iwork_data[k] = i;
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork_data[k] = idx_data[q - 1];
              q++;
            }
          }
        } else {
          iwork_data[k] = i1;
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork_data[k] = idx_data[p - 1];
              p++;
            }
          }
        }
        k++;
      }
      for (k = 0; k < kEnd; k++) {
        idx_data[(j + k) - 1] = iwork_data[k];
      }
      j = qEnd;
    }
    b_i = i2;
  }
  emxFree_int32_T(&iwork);
}

/* End of code generation (sortIdx.c) */
