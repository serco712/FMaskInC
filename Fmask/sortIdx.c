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
#include "Fmask_emxutil.h"
#include "Fmask_types.h"

/* Function Declarations */
static void merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int np,
                  int nq, emxArray_int32_T *iwork, emxArray_real_T *xwork);

/* Function Definitions */
static void merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int np,
                  int nq, emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  double *x_data;
  double *xwork_data;
  int j;
  int *idx_data;
  int *iwork_data;
  xwork_data = xwork->data;
  iwork_data = iwork->data;
  x_data = x->data;
  idx_data = idx->data;
  if (nq != 0) {
    int iout;
    int n_tmp;
    int p;
    int q;
    n_tmp = np + nq;
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork_data[j] = idx_data[iout];
      xwork_data[j] = x_data[iout];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] <= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx_data[iout] = iwork_data[j - 1];
            x_data[iout] = xwork_data[j - 1];
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

void merge_block(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int n,
                 int preSortLevel, emxArray_int32_T *iwork,
                 emxArray_real_T *xwork)
{
  int bLen;
  int nPairs;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    int tailOffset;
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }
    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      merge(idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }
    bLen = tailOffset;
  }
  if (n > bLen) {
    merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

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
