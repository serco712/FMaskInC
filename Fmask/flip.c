/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * flip.c
 *
 * Code generation for function 'flip'
 *
 */

/* Include files */
#include "flip.h"
#include "Fmask_types.h"

/* Function Definitions */
void flip(emxArray_boolean_T *x)
{
  int b_i;
  int k;
  boolean_T *x_data;
  x_data = x->data;
  if ((x->size[0] != 0) && (x->size[1] != 0) && (x->size[1] > 1)) {
    int i;
    int n;
    int nd2;
    int vstride;
    vstride = x->size[0];
    n = x->size[1] - 1;
    nd2 = x->size[1] >> 1;
    i = vstride - 1;
    for (b_i = 0; b_i <= i; b_i++) {
      for (k = 0; k < nd2; k++) {
        int i1;
        int tmp_tmp;
        boolean_T tmp;
        tmp_tmp = b_i + k * vstride;
        tmp = x_data[tmp_tmp];
        i1 = b_i + (n - k) * vstride;
        x_data[tmp_tmp] = x_data[i1];
        x_data[i1] = tmp;
      }
    }
  }
}

/* End of code generation (flip.c) */
