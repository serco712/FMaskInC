/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "find.h"
#include "Fmask_emxutil.h"
#include "Fmask_types.h"

/* Function Definitions */
void b_eml_find(const emxArray_boolean_T *x, emxArray_int32_T *i)
{
  int idx;
  int ii;
  int nx;
  int *i_data;
  const boolean_T *x_data;
  boolean_T exitg1;
  x_data = x->data;
  nx = x->size[1];
  idx = 0;
  ii = i->size[0];
  i->size[0] = x->size[1];
  emxEnsureCapacity_int32_T(i, ii);
  i_data = i->data;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (x->size[1] == 1) {
    if (idx == 0) {
      i->size[0] = 0;
    }
  } else {
    ii = i->size[0];
    if (idx < 1) {
      i->size[0] = 0;
    } else {
      i->size[0] = idx;
    }
    emxEnsureCapacity_int32_T(i, ii);
  }
}

void eml_find(const emxArray_boolean_T *x, emxArray_int32_T *i,
              emxArray_int32_T *j)
{
  int nx;
  int *i_data;
  int *j_data;
  const boolean_T *x_data;
  x_data = x->data;
  nx = x->size[0] * x->size[1];
  if (nx == 0) {
    i->size[0] = 0;
    j->size[0] = 0;
  } else {
    int idx;
    int ii;
    int jj;
    boolean_T exitg1;
    idx = 0;
    jj = i->size[0];
    i->size[0] = nx;
    emxEnsureCapacity_int32_T(i, jj);
    i_data = i->data;
    jj = j->size[0];
    j->size[0] = nx;
    emxEnsureCapacity_int32_T(j, jj);
    j_data = j->data;
    ii = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= x->size[1])) {
      boolean_T guard1;
      guard1 = false;
      if (x_data[(ii + x->size[0] * (jj - 1)) - 1]) {
        idx++;
        i_data[idx - 1] = ii;
        j_data[idx - 1] = jj;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        ii++;
        if (ii > x->size[0]) {
          ii = 1;
          jj++;
        }
      }
    }
    if (nx == 1) {
      if (idx == 0) {
        i->size[0] = 0;
        j->size[0] = 0;
      }
    } else {
      if (idx < 1) {
        jj = 0;
      } else {
        jj = idx;
      }
      ii = i->size[0];
      i->size[0] = jj;
      emxEnsureCapacity_int32_T(i, ii);
      ii = j->size[0];
      j->size[0] = jj;
      emxEnsureCapacity_int32_T(j, ii);
    }
  }
}

/* End of code generation (find.c) */
