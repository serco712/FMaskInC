/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imfill.c
 *
 * Code generation for function 'imfill'
 *
 */

/* Include files */
#include "imfill.h"
#include "Fmask_emxutil.h"
#include "Fmask_types.h"
#include "padarray.h"
#include "libmwippreconstruct.h"

/* Function Definitions */
void imfill(emxArray_real32_T *varargin_1)
{
  emxArray_boolean_T *x;
  emxArray_int32_T *idx;
  emxArray_int32_T *r3;
  emxArray_real32_T *markerPad;
  emxArray_real32_T *maskPad;
  emxArray_real32_T *r;
  emxArray_real32_T *r2;
  float *markerPad_data;
  float *maskPad_data;
  float *r1;
  int b_nz;
  int i;
  int k;
  int vlen;
  int *idx_data;
  int *r4;
  boolean_T *x_data;
  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    double b_imSizeT_tmp;
    double imSizeT_tmp;
    int nz;
    imSizeT_tmp = (double)varargin_1->size[0] + 2.0;
    b_imSizeT_tmp = (double)varargin_1->size[1] + 2.0;
    emxInit_real32_T(&maskPad, 2);
    i = maskPad->size[0] * maskPad->size[1];
    maskPad->size[0] = (int)imSizeT_tmp;
    maskPad->size[1] = (int)b_imSizeT_tmp;
    emxEnsureCapacity_real32_T(maskPad, i);
    maskPad_data = maskPad->data;
    emxInit_real32_T(&markerPad, 2);
    i = markerPad->size[0] * markerPad->size[1];
    markerPad->size[0] = (int)imSizeT_tmp;
    markerPad->size[1] = (int)b_imSizeT_tmp;
    emxEnsureCapacity_real32_T(markerPad, i);
    markerPad_data = markerPad->data;
    emxInit_real32_T(&r, 2);
    padarray(varargin_1, r);
    r1 = r->data;
    nz = r->size[1];
    for (i = 0; i < nz; i++) {
      vlen = r->size[0];
      for (b_nz = 0; b_nz < vlen; b_nz++) {
        maskPad_data[b_nz + maskPad->size[0] * i] = r1[b_nz + r->size[0] * i];
      }
    }
    i = r->size[0] * r->size[1];
    r->size[0] = varargin_1->size[0];
    r->size[1] = varargin_1->size[1];
    emxEnsureCapacity_real32_T(r, i);
    r1 = r->data;
    nz = varargin_1->size[0] * varargin_1->size[1];
    for (i = 0; i < nz; i++) {
      r1[i] = 3.402823466E+38F;
    }
    emxInit_real32_T(&r2, 2);
    padarray(r, r2);
    r1 = r2->data;
    emxFree_real32_T(&r);
    nz = r2->size[1];
    for (i = 0; i < nz; i++) {
      vlen = r2->size[0];
      for (b_nz = 0; b_nz < vlen; b_nz++) {
        markerPad_data[b_nz + markerPad->size[0] * i] =
            r1[b_nz + r2->size[0] * i];
      }
    }
    emxFree_real32_T(&r2);
    if (markerPad->size[0] < markerPad->size[1]) {
      vlen = markerPad->size[1] - 2;
    } else {
      vlen = markerPad->size[0] - 2;
    }
    emxInit_int32_T(&idx, 2);
    i = idx->size[0] * idx->size[1];
    idx->size[0] = vlen;
    idx->size[1] = 2;
    emxEnsureCapacity_int32_T(idx, i);
    idx_data = idx->data;
    nz = vlen << 1;
    for (i = 0; i < nz; i++) {
      idx_data[i] = 0;
    }
    emxInit_int32_T(&r3, 2);
    r4 = r3->data;
    for (k = 0; k < 2; k++) {
      nz = markerPad->size[k];
      if (markerPad->size[k] - 1 < 2) {
        r3->size[0] = 1;
        r3->size[1] = 0;
      } else {
        i = r3->size[0] * r3->size[1];
        r3->size[0] = 1;
        r3->size[1] = markerPad->size[k] - 2;
        emxEnsureCapacity_int32_T(r3, i);
        r4 = r3->data;
        for (i = 0; i <= nz - 3; i++) {
          r4[i] = i + 2;
        }
      }
      if (markerPad->size[k] - 2 < 1) {
        nz = 0;
      } else {
        nz = markerPad->size[k] - 2;
      }
      for (i = 0; i < nz; i++) {
        idx_data[i + idx->size[0] * k] = r4[i];
      }
    }
    emxFree_int32_T(&r3);
    vlen = maskPad->size[0] * maskPad->size[1];
    for (i = 0; i < vlen; i++) {
      maskPad_data[i] = 1.0F - maskPad_data[i];
    }
    for (i = 0; i < vlen; i++) {
      markerPad_data[i] = 1.0F - markerPad_data[i];
    }
    double imSizeT[2];
    imSizeT[0] = markerPad->size[0];
    imSizeT[1] = markerPad->size[1];
    ippreconstruct_real32(&markerPad_data[0], &maskPad_data[0], &imSizeT[0],
                          1.0);
    emxFree_real32_T(&maskPad);
    nz = markerPad->size[0] * markerPad->size[1];
    for (i = 0; i < nz; i++) {
      markerPad_data[i] = 1.0F - markerPad_data[i];
    }
    emxInit_boolean_T(&x, 1);
    i = x->size[0];
    x->size[0] = idx->size[0];
    emxEnsureCapacity_boolean_T(x, i);
    x_data = x->data;
    nz = idx->size[0];
    for (i = 0; i < nz; i++) {
      x_data[i] = (idx_data[i] != 0);
    }
    vlen = x->size[0];
    if (x->size[0] == 0) {
      b_nz = 0;
    } else {
      b_nz = x_data[0];
      for (k = 2; k <= vlen; k++) {
        b_nz += x_data[k - 1];
      }
    }
    i = x->size[0];
    x->size[0] = idx->size[0];
    emxEnsureCapacity_boolean_T(x, i);
    x_data = x->data;
    nz = idx->size[0];
    for (i = 0; i < nz; i++) {
      x_data[i] = (idx_data[i + idx->size[0]] != 0);
    }
    vlen = x->size[0];
    if (x->size[0] == 0) {
      nz = 0;
    } else {
      nz = x_data[0];
      for (k = 2; k <= vlen; k++) {
        nz += x_data[k - 1];
      }
    }
    emxFree_boolean_T(&x);
    i = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = markerPad->size[0] - 2;
    varargin_1->size[1] = markerPad->size[1] - 2;
    emxEnsureCapacity_real32_T(varargin_1, i);
    maskPad_data = varargin_1->data;
    for (vlen = 0; vlen < b_nz; vlen++) {
      for (k = 0; k < nz; k++) {
        maskPad_data[vlen + varargin_1->size[0] * k] =
            markerPad_data[(idx_data[vlen] +
                            markerPad->size[0] *
                                (idx_data[k + idx->size[0]] - 1)) -
                           1];
      }
    }
    emxFree_int32_T(&idx);
    emxFree_real32_T(&markerPad);
  }
}

/* End of code generation (imfill.c) */
