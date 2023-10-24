/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * permute.c
 *
 * Code generation for function 'permute'
 *
 */

/* Include files */
#include "permute.h"
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"

/* Function Definitions */
void permute(const emxArray_real32_T *a, emxArray_real32_T *b)
{
  const float *a_data;
  float *b_data;
  int b_k;
  int i;
  int k;
  int plast;
  int subsa_idx_1;
  boolean_T b_b;
  a_data = a->data;
  b_b = true;
  if ((a->size[0] != 0) && (a->size[1] != 0)) {
    boolean_T exitg1;
    plast = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (a->size[k] != 1) {
        if (plast > k + 1) {
          b_b = false;
          exitg1 = true;
        } else {
          plast = k + 1;
          k++;
        }
      } else {
        k++;
      }
    }
  }
  if (b_b) {
    i = b->size[0] * b->size[1];
    b->size[0] = a->size[0];
    b->size[1] = a->size[1];
    emxEnsureCapacity_real32_T(b, i);
    b_data = b->data;
    plast = a->size[0] * a->size[1];
    for (i = 0; i < plast; i++) {
      b_data[i] = a_data[i];
    }
  } else {
    i = b->size[0] * b->size[1];
    b->size[0] = a->size[0];
    b->size[1] = a->size[1];
    emxEnsureCapacity_real32_T(b, i);
    b_data = b->data;
    i = a->size[1];
    for (k = 0; k < i; k++) {
      plast = a->size[0];
      if (a->size[0] - 1 >= 0) {
        subsa_idx_1 = k + 1;
      }
      for (b_k = 0; b_k < plast; b_k++) {
        b_data[b_k + b->size[0] * (subsa_idx_1 - 1)] =
            a_data[b_k + a->size[0] * (subsa_idx_1 - 1)];
      }
    }
  }
}

/* End of code generation (permute.c) */
