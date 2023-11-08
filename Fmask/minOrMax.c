/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * minOrMax.c
 *
 * Code generation for function 'minOrMax'
 *
 */

/* Include files */
#include "minOrMax.h"
#include "Fmask_types.h"

/* Function Definitions */
double maximum(const emxArray_real_T *x, int *idx)
{
  const double *x_data;
  double ex;
  int k;
  int last;
  x_data = x->data;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[x->size[0] - 1];
      if (x_data[0] < ex) {
        *idx = x->size[0];
      } else {
        ex = x_data[0];
        *idx = 1;
      }
    }
  } else {
    ex = x_data[0];
    *idx = 1;
    for (k = 2; k <= last; k++) {
      double d;
      d = x_data[k - 1];
      if (ex < d) {
        ex = d;
        *idx = k;
      }
    }
  }
  return ex;
}

double minimum(const emxArray_real_T *x, int *idx)
{
  const double *x_data;
  double ex;
  int k;
  int last;
  x_data = x->data;
  last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[x->size[0] - 1];
      if (x_data[0] > ex) {
        *idx = x->size[0];
      } else {
        ex = x_data[0];
        *idx = 1;
      }
    }
  } else {
    ex = x_data[0];
    *idx = 1;
    for (k = 2; k <= last; k++) {
      double d;
      d = x_data[k - 1];
      if (ex > d) {
        ex = d;
        *idx = k;
      }
    }
  }
  return ex;
}

/* End of code generation (minOrMax.c) */
