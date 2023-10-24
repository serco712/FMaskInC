/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ixfun.c
 *
 * Code generation for function 'ixfun'
 *
 */

/* Include files */
#include "ixfun.h"
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"
#include <math.h>

/* Function Definitions */
void expand_max(const emxArray_real32_T *a, const emxArray_real32_T *b,
                emxArray_real32_T *c)
{
  const float *a_data;
  const float *b_data;
  float *c_data;
  int csz_idx_1_tmp;
  int i;
  int i1;
  int k;
  int u0;
  int u1;
  b_data = b->data;
  a_data = a->data;
  u0 = a->size[1];
  u1 = b->size[1];
  if (u0 <= u1) {
    u1 = u0;
  }
  if (b->size[1] == 1) {
    csz_idx_1_tmp = a->size[1];
  } else if (a->size[1] == 1) {
    csz_idx_1_tmp = b->size[1];
  } else {
    csz_idx_1_tmp = u1;
  }
  u0 = a->size[0];
  u1 = b->size[0];
  if (u0 <= u1) {
    u1 = u0;
  }
  if (b->size[0] == 1) {
    i = a->size[0];
  } else if (a->size[0] == 1) {
    i = b->size[0];
  } else {
    i = u1;
  }
  i1 = c->size[0] * c->size[1];
  c->size[0] = i;
  c->size[1] = csz_idx_1_tmp;
  emxEnsureCapacity_real32_T(c, i1);
  c_data = c->data;
  if ((i != 0) && (csz_idx_1_tmp != 0)) {
    boolean_T b1;
    boolean_T b2;
    boolean_T b3;
    boolean_T b_b;
    b_b = (a->size[1] != 1);
    b1 = (b->size[1] != 1);
    i = csz_idx_1_tmp - 1;
    b2 = (a->size[0] != 1);
    b3 = (b->size[0] != 1);
    for (csz_idx_1_tmp = 0; csz_idx_1_tmp <= i; csz_idx_1_tmp++) {
      u0 = b_b * csz_idx_1_tmp;
      u1 = b1 * csz_idx_1_tmp;
      i1 = c->size[0] - 1;
      for (k = 0; k <= i1; k++) {
        c_data[k + c->size[0] * csz_idx_1_tmp] = fmaxf(
            a_data[b2 * k + a->size[0] * u0], b_data[b3 * k + b->size[0] * u1]);
      }
    }
  }
}

/* End of code generation (ixfun.c) */
