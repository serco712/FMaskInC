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
#include "Fmask_emxutil.h"
#include "Fmask_types.h"

/* Function Definitions */
void b_padarray(const emxArray_uint8_T *varargin_1,
                const double varargin_2_data[], emxArray_uint8_T *b)
{
  int b_i;
  int i;
  int j;
  const unsigned char *varargin_1_data;
  unsigned char *b_data;
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
    emxEnsureCapacity_uint8_T(b, i);
    b_data = b->data;
    loop_ub = (int)sizeB_idx_0 * (int)sizeB_idx_1;
    for (i = 0; i < loop_ub; i++) {
      b_data[i] = 0U;
    }
  } else {
    int i1;
    int loop_ub;
    i = b->size[0] * b->size[1];
    b->size[0] = (int)((double)varargin_1->size[0] + varargin_2_data[0]);
    b->size[1] = (int)((double)varargin_1->size[1] + varargin_2_data[1]);
    emxEnsureCapacity_uint8_T(b, i);
    b_data = b->data;
    i = (int)varargin_2_data[1];
    for (j = 0; j < i; j++) {
      loop_ub = b->size[0];
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_data[b_i + b->size[0] * j] = 0U;
      }
    }
    loop_ub = i + 1;
    i1 = b->size[1];
    for (j = loop_ub; j <= i1; j++) {
      int i2;
      i2 = (int)varargin_2_data[0];
      for (b_i = 0; b_i < i2; b_i++) {
        b_data[b_i + b->size[0] * (j - 1)] = 0U;
      }
    }
    loop_ub = varargin_1->size[1];
    i1 = varargin_1->size[0];
    for (j = 0; j < loop_ub; j++) {
      for (b_i = 0; b_i < i1; b_i++) {
        b_data[(b_i + (int)varargin_2_data[0]) + b->size[0] * (j + i)] =
            varargin_1_data[b_i + varargin_1->size[0] * j];
      }
    }
  }
}

void c_padarray(const emxArray_uint8_T *varargin_1,
                const double varargin_2_data[], emxArray_uint8_T *b)
{
  int b_i;
  int i;
  int j;
  const unsigned char *varargin_1_data;
  unsigned char *b_data;
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
    emxEnsureCapacity_uint8_T(b, i);
    b_data = b->data;
    loop_ub = (int)sizeB_idx_0 * (int)sizeB_idx_1;
    for (i = 0; i < loop_ub; i++) {
      b_data[i] = 0U;
    }
  } else {
    int i1;
    int loop_ub;
    i = b->size[0] * b->size[1];
    b->size[0] = (int)((double)varargin_1->size[0] + varargin_2_data[0]);
    loop_ub = (int)((double)varargin_1->size[1] + varargin_2_data[1]);
    b->size[1] = (int)((double)varargin_1->size[1] + varargin_2_data[1]);
    emxEnsureCapacity_uint8_T(b, i);
    b_data = b->data;
    i = varargin_1->size[1] + 1;
    for (j = i; j <= loop_ub; j++) {
      i1 = b->size[0];
      for (b_i = 0; b_i < i1; b_i++) {
        b_data[b_i + b->size[0] * (j - 1)] = 0U;
      }
    }
    i = varargin_1->size[1];
    loop_ub = varargin_1->size[0] + 1;
    for (j = 0; j < i; j++) {
      i1 = b->size[0];
      for (b_i = loop_ub; b_i <= i1; b_i++) {
        b_data[(b_i + b->size[0] * j) - 1] = 0U;
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

void padarray(const emxArray_real32_T *varargin_1, emxArray_real32_T *b)
{
  const float *varargin_1_data;
  float *b_data;
  int b_i;
  int i;
  int j;
  varargin_1_data = varargin_1->data;
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    int loop_ub;
    i = b->size[0] * b->size[1];
    b->size[0] = (int)((unsigned int)varargin_1->size[0] + 2U);
    b->size[1] = (int)((unsigned int)varargin_1->size[1] + 2U);
    emxEnsureCapacity_real32_T(b, i);
    b_data = b->data;
    loop_ub = (int)((unsigned int)varargin_1->size[0] + 2U) *
              (int)((unsigned int)varargin_1->size[1] + 2U);
    for (i = 0; i < loop_ub; i++) {
      b_data[i] = -3.402823466E+38F;
    }
  } else {
    int i1;
    int loop_ub;
    i = b->size[0] * b->size[1];
    b->size[0] = (int)((unsigned int)varargin_1->size[0] + 2U);
    b->size[1] = (int)((unsigned int)varargin_1->size[1] + 2U);
    emxEnsureCapacity_real32_T(b, i);
    b_data = b->data;
    i = (int)((unsigned int)varargin_1->size[0] + 2U);
    for (b_i = 0; b_i < i; b_i++) {
      b_data[b_i] = -3.402823466E+38F;
    }
    i = varargin_1->size[1] + 2;
    loop_ub = b->size[1];
    for (j = i; j <= loop_ub; j++) {
      i1 = b->size[0];
      for (b_i = 0; b_i < i1; b_i++) {
        b_data[b_i + b->size[0] * (j - 1)] = -3.402823466E+38F;
      }
    }
    i = varargin_1->size[1];
    for (j = 0; j < i; j++) {
      b_data[b->size[0] * (j + 1)] = -3.402823466E+38F;
    }
    i = varargin_1->size[1];
    loop_ub = varargin_1->size[0] + 2;
    for (j = 0; j < i; j++) {
      i1 = b->size[0];
      for (b_i = loop_ub; b_i <= i1; b_i++) {
        b_data[(b_i + b->size[0] * (j + 1)) - 1] = -3.402823466E+38F;
      }
    }
    i = varargin_1->size[1];
    loop_ub = varargin_1->size[0];
    for (j = 0; j < i; j++) {
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_data[(b_i + b->size[0] * (j + 1)) + 1] =
            varargin_1_data[b_i + varargin_1->size[0] * j];
      }
    }
  }
}

/* End of code generation (padarray.c) */
