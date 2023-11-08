/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort.c
 *
 * Code generation for function 'sort'
 *
 */

/* Include files */
#include "sort.h"
#include "Fmask_emxutil.h"
#include "Fmask_types.h"
#include "sortIdx.h"

/* Function Definitions */
void sort(emxArray_real_T *x, emxArray_int32_T *idx)
{
  emxArray_int32_T *iidx;
  emxArray_int32_T *iwork;
  emxArray_real_T *vwork;
  emxArray_real_T *xwork;
  double *vwork_data;
  double *x_data;
  double *xwork_data;
  int b;
  int b_b;
  int b_i;
  int b_j;
  int dim;
  int i;
  int j;
  int k;
  int offset;
  int vlen;
  int vstride;
  int *idx_data;
  int *iidx_data;
  int *iwork_data;
  x_data = x->data;
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }
  if (dim + 2 <= 1) {
    i = x->size[0];
  } else {
    i = 1;
  }
  vlen = i - 1;
  emxInit_real_T(&vwork, 1);
  offset = vwork->size[0];
  vwork->size[0] = i;
  emxEnsureCapacity_real_T(vwork, offset);
  vwork_data = vwork->data;
  i = idx->size[0];
  idx->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(idx, i);
  idx_data = idx->data;
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x->size[0];
  }
  emxInit_int32_T(&iidx, 1);
  emxInit_int32_T(&iwork, 1);
  emxInit_real_T(&xwork, 1);
  for (b_i = 0; b_i < 1; b_i++) {
    for (j = 0; j < vstride; j++) {
      int nBlocks;
      for (k = 0; k <= vlen; k++) {
        vwork_data[k] = x_data[j + k * vstride];
      }
      nBlocks = vwork->size[0];
      i = iidx->size[0];
      iidx->size[0] = vwork->size[0];
      emxEnsureCapacity_int32_T(iidx, i);
      iidx_data = iidx->data;
      for (i = 0; i < nBlocks; i++) {
        iidx_data[i] = 0;
      }
      nBlocks = vwork->size[0];
      if (vwork->size[0] != 0) {
        double x4[4];
        int idx4[4];
        int i2;
        int i3;
        int i4;
        x4[0] = 0.0;
        idx4[0] = 0;
        x4[1] = 0.0;
        idx4[1] = 0;
        x4[2] = 0.0;
        idx4[2] = 0;
        x4[3] = 0.0;
        idx4[3] = 0;
        i = iwork->size[0];
        iwork->size[0] = vwork->size[0];
        emxEnsureCapacity_int32_T(iwork, i);
        iwork_data = iwork->data;
        i = xwork->size[0];
        xwork->size[0] = vwork->size[0];
        emxEnsureCapacity_real_T(xwork, i);
        xwork_data = xwork->data;
        dim = 0;
        for (k = 0; k < nBlocks; k++) {
          iwork_data[k] = 0;
          xwork_data[k] = 0.0;
          dim++;
          idx4[dim - 1] = k + 1;
          x4[dim - 1] = vwork_data[k];
          if (dim == 4) {
            double d;
            double d1;
            if (x4[0] <= x4[1]) {
              dim = 1;
              i2 = 2;
            } else {
              dim = 2;
              i2 = 1;
            }
            if (x4[2] <= x4[3]) {
              i3 = 3;
              i4 = 4;
            } else {
              i3 = 4;
              i4 = 3;
            }
            d = x4[i3 - 1];
            d1 = x4[dim - 1];
            if (d1 <= d) {
              d1 = x4[i2 - 1];
              if (d1 <= d) {
                i = dim;
                offset = i2;
                dim = i3;
                i2 = i4;
              } else if (d1 <= x4[i4 - 1]) {
                i = dim;
                offset = i3;
                dim = i2;
                i2 = i4;
              } else {
                i = dim;
                offset = i3;
                dim = i4;
              }
            } else {
              d = x4[i4 - 1];
              if (d1 <= d) {
                if (x4[i2 - 1] <= d) {
                  i = i3;
                  offset = dim;
                  dim = i2;
                  i2 = i4;
                } else {
                  i = i3;
                  offset = dim;
                  dim = i4;
                }
              } else {
                i = i3;
                offset = i4;
              }
            }
            iidx_data[k - 3] = idx4[i - 1];
            iidx_data[k - 2] = idx4[offset - 1];
            iidx_data[k - 1] = idx4[dim - 1];
            iidx_data[k] = idx4[i2 - 1];
            vwork_data[k - 3] = x4[i - 1];
            vwork_data[k - 2] = x4[offset - 1];
            vwork_data[k - 1] = x4[dim - 1];
            vwork_data[k] = x4[i2 - 1];
            dim = 0;
          }
        }
        if (dim > 0) {
          signed char perm[4];
          perm[1] = 0;
          perm[2] = 0;
          perm[3] = 0;
          if (dim == 1) {
            perm[0] = 1;
          } else if (dim == 2) {
            if (x4[0] <= x4[1]) {
              perm[0] = 1;
              perm[1] = 2;
            } else {
              perm[0] = 2;
              perm[1] = 1;
            }
          } else if (x4[0] <= x4[1]) {
            if (x4[1] <= x4[2]) {
              perm[0] = 1;
              perm[1] = 2;
              perm[2] = 3;
            } else if (x4[0] <= x4[2]) {
              perm[0] = 1;
              perm[1] = 3;
              perm[2] = 2;
            } else {
              perm[0] = 3;
              perm[1] = 1;
              perm[2] = 2;
            }
          } else if (x4[0] <= x4[2]) {
            perm[0] = 2;
            perm[1] = 1;
            perm[2] = 3;
          } else if (x4[1] <= x4[2]) {
            perm[0] = 2;
            perm[1] = 3;
            perm[2] = 1;
          } else {
            perm[0] = 3;
            perm[1] = 2;
            perm[2] = 1;
          }
          i = (unsigned char)dim;
          for (k = 0; k < i; k++) {
            i2 = (nBlocks - dim) + k;
            offset = perm[k];
            iidx_data[i2] = idx4[offset - 1];
            vwork_data[i2] = x4[offset - 1];
          }
        }
        dim = 2;
        if (vwork->size[0] > 1) {
          if (vwork->size[0] >= 256) {
            nBlocks = vwork->size[0] >> 8;
            for (b = 0; b < nBlocks; b++) {
              double b_xwork[256];
              int b_iwork[256];
              offset = (b << 8) - 1;
              for (b_b = 0; b_b < 6; b_b++) {
                int bLen;
                int bLen2;
                bLen = 1 << (b_b + 2);
                bLen2 = bLen << 1;
                i = 256 >> (b_b + 3);
                for (k = 0; k < i; k++) {
                  i3 = (offset + k * bLen2) + 1;
                  for (b_j = 0; b_j < bLen2; b_j++) {
                    dim = i3 + b_j;
                    b_iwork[b_j] = iidx_data[dim];
                    b_xwork[b_j] = vwork_data[dim];
                  }
                  i4 = 0;
                  i2 = bLen;
                  dim = i3 - 1;
                  int exitg1;
                  do {
                    exitg1 = 0;
                    dim++;
                    if (b_xwork[i4] <= b_xwork[i2]) {
                      iidx_data[dim] = b_iwork[i4];
                      vwork_data[dim] = b_xwork[i4];
                      if (i4 + 1 < bLen) {
                        i4++;
                      } else {
                        exitg1 = 1;
                      }
                    } else {
                      iidx_data[dim] = b_iwork[i2];
                      vwork_data[dim] = b_xwork[i2];
                      if (i2 + 1 < bLen2) {
                        i2++;
                      } else {
                        dim -= i4;
                        for (b_j = i4 + 1; b_j <= bLen; b_j++) {
                          i2 = dim + b_j;
                          iidx_data[i2] = b_iwork[b_j - 1];
                          vwork_data[i2] = b_xwork[b_j - 1];
                        }
                        exitg1 = 1;
                      }
                    }
                  } while (exitg1 == 0);
                }
              }
            }
            dim = nBlocks << 8;
            i2 = vwork->size[0] - dim;
            if (i2 > 0) {
              merge_block(iidx, vwork, dim, i2, 2, iwork, xwork);
            }
            dim = 8;
          }
          merge_block(iidx, vwork, 0, vwork->size[0], dim, iwork, xwork);
          vwork_data = vwork->data;
          iidx_data = iidx->data;
        }
      }
      for (k = 0; k <= vlen; k++) {
        i = j + k * vstride;
        x_data[i] = vwork_data[k];
        idx_data[i] = iidx_data[k];
      }
    }
  }
  emxFree_real_T(&xwork);
  emxFree_int32_T(&iwork);
  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
}

/* End of code generation (sort.c) */
