/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stdfilt.c
 *
 * Code generation for function 'stdfilt'
 *
 */

/* Include files */
#include "stdfilt.h"
#include "CDI_emxutil.h"
#include "CDI_types.h"
#include "imfilter.h"
#include "unsafeSxfun.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"
#include <math.h>

/* Function Definitions */
void stdfilt(const emxArray_real32_T *varargin_1, emxArray_real_T *J)
{
  static const double b_kernel[7] = {0.14433756729740638, 0.14433756729740643,
                                     0.14433756729740643, 0.14433756729740643,
                                     0.14433756729740643, 0.14433756729740643,
                                     0.14433756729740643};
  static const double b_nonZeroKernel[7] = {
      0.14433756729740646, 0.14433756729740646, 0.14433756729740641,
      0.14433756729740641, 0.14433756729740641, 0.14433756729740641,
      0.14433756729740641};
  static const double c_kernel[7] = {0.14359544725045442, 0.14359544725045451,
                                     0.14359544725045451, 0.14359544725045451,
                                     0.14359544725045451, 0.14359544725045451,
                                     0.14359544725045451};
  static const double kernel[7] = {0.14433756729740646, 0.14433756729740646,
                                   0.14433756729740641, 0.14433756729740641,
                                   0.14433756729740641, 0.14433756729740641,
                                   0.14433756729740641};
  emxArray_real_T *a;
  emxArray_real_T *b_I;
  emxArray_real_T *conv1;
  double connDimsT[2];
  double outSizeT[2];
  double out_size_row[2];
  double padSizeT[2];
  double startT[2];
  double b_varargin_1;
  double *I_data;
  double *a_data;
  double *conv1_data;
  const float *varargin_1_data;
  int b_outSizeT_tmp;
  int i;
  int nx;
  int outSizeT_tmp;
  boolean_T conn[7];
  boolean_T b;
  boolean_T tooBig;
  varargin_1_data = varargin_1->data;
  emxInit_real_T(&b_I, 2);
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = varargin_1->size[0];
  b_I->size[1] = varargin_1->size[1];
  emxEnsureCapacity_real_T(b_I, i);
  I_data = b_I->data;
  nx = varargin_1->size[0] * varargin_1->size[1];
  for (i = 0; i < nx; i++) {
    I_data[i] = varargin_1_data[i];
  }
  emxInit_real_T(&conv1, 2);
  i = conv1->size[0] * conv1->size[1];
  conv1->size[0] = b_I->size[0];
  conv1->size[1] = b_I->size[1];
  emxEnsureCapacity_real_T(conv1, i);
  conv1_data = conv1->data;
  for (i = 0; i < nx; i++) {
    b_varargin_1 = I_data[i];
    conv1_data[i] = b_varargin_1 * b_varargin_1;
  }
  outSizeT_tmp = conv1->size[0];
  outSizeT[0] = conv1->size[0];
  connDimsT[0] = 3.0;
  b_outSizeT_tmp = conv1->size[1];
  outSizeT[1] = conv1->size[1];
  connDimsT[1] = 3.0;
  b = ((conv1->size[0] == 0) || (conv1->size[1] == 0));
  emxInit_real_T(&a, 2);
  if (!b) {
    int i1;
    padImage(conv1, connDimsT, a);
    a_data = a->data;
    out_size_row[0] = a->size[0];
    out_size_row[1] = conv1->size[1];
    tooBig = true;
    for (nx = 0; nx < 2; nx++) {
      if ((!tooBig) || (!(out_size_row[nx] > 65500.0))) {
        tooBig = false;
      }
    }
    i = conv1->size[0] * conv1->size[1];
    conv1->size[0] = a->size[0];
    i1 = (int)out_size_row[1];
    conv1->size[1] = i1;
    emxEnsureCapacity_real_T(conv1, i);
    conv1_data = conv1->data;
    if (!tooBig) {
      padSizeT[0] = a->size[0];
      connDimsT[0] = 1.0;
      padSizeT[1] = a->size[1];
      connDimsT[1] = 7.0;
      ippfilter_real64(&a_data[0], &conv1_data[0], &out_size_row[0], 2.0,
                       &padSizeT[0], &kernel[0], &connDimsT[0], false);
    } else {
      padSizeT[0] = a->size[0];
      padSizeT[1] = a->size[1];
      for (i = 0; i < 7; i++) {
        conn[i] = true;
      }
      connDimsT[0] = 1.0;
      startT[0] = 0.0;
      connDimsT[1] = 7.0;
      startT[1] = 3.0;
      imfilter_real64(&a_data[0], &conv1_data[0], 2.0, &out_size_row[0], 2.0,
                      &padSizeT[0], &b_nonZeroKernel[0], 7.0, &conn[0], 2.0,
                      &connDimsT[0], &startT[0], 2.0, true, false);
    }
    tooBig = true;
    for (nx = 0; nx < 2; nx++) {
      if ((!tooBig) || (!(outSizeT[nx] > 65500.0))) {
        tooBig = false;
      }
    }
    i = a->size[0] * a->size[1];
    a->size[0] = conv1->size[0];
    a->size[1] = conv1->size[1];
    emxEnsureCapacity_real_T(a, i);
    a_data = a->data;
    nx = conv1->size[0] * conv1->size[1];
    for (i = 0; i < nx; i++) {
      a_data[i] = conv1_data[i];
    }
    i = conv1->size[0] * conv1->size[1];
    conv1->size[0] = outSizeT_tmp;
    conv1->size[1] = i1;
    emxEnsureCapacity_real_T(conv1, i);
    conv1_data = conv1->data;
    if (!tooBig) {
      padSizeT[0] = a->size[0];
      connDimsT[0] = 7.0;
      padSizeT[1] = a->size[1];
      connDimsT[1] = 1.0;
      ippfilter_real64(&a_data[0], &conv1_data[0], &outSizeT[0], 2.0,
                       &padSizeT[0], &b_kernel[0], &connDimsT[0], false);
    } else {
      padSizeT[0] = a->size[0];
      padSizeT[1] = a->size[1];
      for (i = 0; i < 7; i++) {
        conn[i] = true;
      }
      connDimsT[0] = 7.0;
      startT[0] = 3.0;
      connDimsT[1] = 1.0;
      startT[1] = 0.0;
      imfilter_real64(&a_data[0], &conv1_data[0], 2.0, &outSizeT[0], 2.0,
                      &padSizeT[0], &b_kernel[0], 7.0, &conn[0], 2.0,
                      &connDimsT[0], &startT[0], 2.0, true, false);
    }
  }
  outSizeT[0] = outSizeT_tmp;
  connDimsT[0] = 3.0;
  outSizeT[1] = b_outSizeT_tmp;
  connDimsT[1] = 3.0;
  if (!b) {
    padImage(b_I, connDimsT, a);
    a_data = a->data;
    out_size_row[0] = a->size[0];
    out_size_row[1] = b_outSizeT_tmp;
    tooBig = true;
    for (nx = 0; nx < 2; nx++) {
      if ((!tooBig) || (!(out_size_row[nx] > 65500.0))) {
        tooBig = false;
      }
    }
    i = b_I->size[0] * b_I->size[1];
    b_I->size[0] = a->size[0];
    b_I->size[1] = b_outSizeT_tmp;
    emxEnsureCapacity_real_T(b_I, i);
    I_data = b_I->data;
    if (!tooBig) {
      double nonZeroKernel[7];
      padSizeT[0] = a->size[0];
      padSizeT[1] = a->size[1];
      for (nx = 0; nx < 7; nx++) {
        nonZeroKernel[nx] = 0.14359544725045451;
      }
      connDimsT[0] = 1.0;
      connDimsT[1] = 7.0;
      ippfilter_real64(&a_data[0], &I_data[0], &out_size_row[0], 2.0,
                       &padSizeT[0], &nonZeroKernel[0], &connDimsT[0], false);
    } else {
      double nonZeroKernel[7];
      padSizeT[0] = a->size[0];
      padSizeT[1] = a->size[1];
      for (nx = 0; nx < 7; nx++) {
        nonZeroKernel[nx] = 0.14359544725045451;
        conn[nx] = true;
      }
      connDimsT[0] = 1.0;
      startT[0] = 0.0;
      connDimsT[1] = 7.0;
      startT[1] = 3.0;
      imfilter_real64(&a_data[0], &I_data[0], 2.0, &out_size_row[0], 2.0,
                      &padSizeT[0], &nonZeroKernel[0], 7.0, &conn[0], 2.0,
                      &connDimsT[0], &startT[0], 2.0, true, false);
    }
    tooBig = true;
    for (nx = 0; nx < 2; nx++) {
      if ((!tooBig) || (!(outSizeT[nx] > 65500.0))) {
        tooBig = false;
      }
    }
    i = a->size[0] * a->size[1];
    a->size[0] = b_I->size[0];
    a->size[1] = b_I->size[1];
    emxEnsureCapacity_real_T(a, i);
    a_data = a->data;
    nx = b_I->size[0] * b_I->size[1];
    for (i = 0; i < nx; i++) {
      a_data[i] = I_data[i];
    }
    i = b_I->size[0] * b_I->size[1];
    b_I->size[0] = outSizeT_tmp;
    b_I->size[1] = b_outSizeT_tmp;
    emxEnsureCapacity_real_T(b_I, i);
    I_data = b_I->data;
    if (!tooBig) {
      padSizeT[0] = a->size[0];
      connDimsT[0] = 7.0;
      padSizeT[1] = a->size[1];
      connDimsT[1] = 1.0;
      ippfilter_real64(&a_data[0], &I_data[0], &outSizeT[0], 2.0, &padSizeT[0],
                       &c_kernel[0], &connDimsT[0], false);
    } else {
      padSizeT[0] = a->size[0];
      padSizeT[1] = a->size[1];
      for (i = 0; i < 7; i++) {
        conn[i] = true;
      }
      connDimsT[0] = 7.0;
      startT[0] = 3.0;
      connDimsT[1] = 1.0;
      startT[1] = 0.0;
      imfilter_real64(&a_data[0], &I_data[0], 2.0, &outSizeT[0], 2.0,
                      &padSizeT[0], &c_kernel[0], 7.0, &conn[0], 2.0,
                      &connDimsT[0], &startT[0], 2.0, true, false);
    }
  }
  emxFree_real_T(&a);
  if ((conv1->size[0] == b_I->size[0]) && (conv1->size[1] == b_I->size[1])) {
    i = J->size[0] * J->size[1];
    J->size[0] = conv1->size[0];
    J->size[1] = conv1->size[1];
    emxEnsureCapacity_real_T(J, i);
    a_data = J->data;
    nx = conv1->size[0] * conv1->size[1];
    for (i = 0; i < nx; i++) {
      b_varargin_1 = I_data[i];
      b_varargin_1 = conv1_data[i] - b_varargin_1 * b_varargin_1;
      a_data[i] = fmax(b_varargin_1, 0.0);
    }
  } else {
    binary_expand_op_3(J, conv1, b_I);
    a_data = J->data;
  }
  emxFree_real_T(&conv1);
  emxFree_real_T(&b_I);
  nx = J->size[0] * J->size[1];
  for (outSizeT_tmp = 0; outSizeT_tmp < nx; outSizeT_tmp++) {
    a_data[outSizeT_tmp] = sqrt(a_data[outSizeT_tmp]);
  }
}

/* End of code generation (stdfilt.c) */
