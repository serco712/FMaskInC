/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: minOrMax.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 04-Dec-2023 17:32:24
 */

/* Include Files */
#include "minOrMax.h"

/* Function Definitions */
/*
 * Arguments    : const float x_data[]
 *                int x_size
 * Return Type  : float
 */
float fmaximum(const float x_data[], int x_size)
{
  float ex;
  int k;
  if (x_size <= 2) {
    if (x_size == 1) {
      ex = x_data[0];
    } else {
      float ex_tmp;
      ex_tmp = x_data[x_size - 1];
      if (x_data[0] < ex_tmp) {
        ex = ex_tmp;
      } else {
        ex = x_data[0];
      }
    }
  } else {
    ex = x_data[0];
    for (k = 2; k <= x_size; k++) {
      float ex_tmp;
      ex_tmp = x_data[k - 1];
      if (ex < ex_tmp) {
        ex = ex_tmp;
      }
    }
  }
  return ex;
}

double maximum(const double x_data[], int x_size, int *idx)
{
  double ex;
  int k;
  if (x_size <= 2) {
    if (x_size == 1) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[x_size - 1];
      if (x_data[0] < ex) {
        *idx = x_size;
      } else {
        ex = x_data[0];
        *idx = 1;
      }
    }
  } else {
    ex = x_data[0];
    *idx = 1;
    for (k = 2; k <= x_size; k++) {
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

double minimum(const double x_data[], int x_size, int *idx)
{
  double ex;
  int k;
  if (x_size <= 2) {
    if (x_size == 1) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[x_size - 1];
      if (x_data[0] > ex) {
        *idx = x_size;
      } else {
        ex = x_data[0];
        *idx = 1;
      }
    }
  } else {
    ex = x_data[0];
    *idx = 1;
    for (k = 2; k <= x_size; k++) {
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

/*
 * File trailer for minOrMax.c
 *
 * [EOF]
 */
