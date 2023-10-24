/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * useConstantDim.c
 *
 * Code generation for function 'useConstantDim'
 *
 */

/* Include files */
#include "useConstantDim.h"
#include "autoFmask_types.h"

/* Function Definitions */
void useConstantDim(emxArray_real_T *varargin_2, int varargin_3)
{
  double *varargin_2_data;
  int b_k;
  int k;
  int subsb_idx_1;
  varargin_2_data = varargin_2->data;
  if (varargin_3 == 1) {
    if ((varargin_2->size[0] != 0) && (varargin_2->size[1] != 0)) {
      int i;
      i = varargin_2->size[1];
      for (k = 0; k < i; k++) {
        int i1;
        i1 = varargin_2->size[0];
        if (i1 - 2 >= 0) {
          subsb_idx_1 = k + 1;
        }
        for (b_k = 0; b_k <= i1 - 2; b_k++) {
          varargin_2_data[(b_k + varargin_2->size[0] * (subsb_idx_1 - 1)) +
                          1] += varargin_2_data[b_k + varargin_2->size[0] * k];
        }
      }
    }
  } else if ((varargin_2->size[0] != 0) && (varargin_2->size[1] != 0)) {
    int i;
    i = varargin_2->size[1];
    for (k = 0; k <= i - 2; k++) {
      int i1;
      i1 = varargin_2->size[0];
      for (b_k = 0; b_k < i1; b_k++) {
        varargin_2_data[b_k + varargin_2->size[0] * (k + 1)] +=
            varargin_2_data[b_k + varargin_2->size[0] * k];
      }
    }
  }
}

/* End of code generation (useConstantDim.c) */
