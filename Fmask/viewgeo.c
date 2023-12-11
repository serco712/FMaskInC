/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: imfil.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Nov-2023 20:14:52
 */

/* Include Files */
#include "viewgeo.h"
#include "minOrMax.h"
#include <math.h>

/* Function Definitions */
/*
 * UNTITLED Summary of this function goes here
 *    Detailed explanation goes here
 *
 * Arguments    : const unsigned char a[128]
 *                double *A
 *                double *B
 *                double *C
 *                double *omiga_par
 *                double *omiga_per
 * Return Type  : void
 */
void viewgeo(const unsigned char test[100], double *A, double *B, double *C,
           double *omiga_par, double *omiga_per)
{
  double cols_data[100];
  double rows_data[100];
  int i_data[100];
  int b_iindx;
  int idx;
  int ii;
  int iindx;
  int jj;
  signed char j_data[100];
  bool x[100];
  bool exitg1;
  for (idx = 0; idx < 100; idx++) {
    x[idx] = (test[idx] == 1);
  }
  idx = 0;
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 10)) {
    bool guard1;
    guard1 = false;
    if (x[(jj + 10 * (ii - 1)) - 1]) {
      idx++;
      i_data[idx - 1] = ii;
      j_data[idx - 1] = (signed char)jj;
      if (idx >= 100) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      ii++;
      if (ii > 10) {
        ii = 1;
        jj++;
      }
    }
  }
  if (idx < 1) {
    ii = 0;
  } else {
    ii = idx;
  }
  for (idx = 0; idx < ii; idx++) {
    rows_data[idx] = i_data[idx];
    cols_data[idx] = j_data[idx];
  }
  double x_l;
  double x_ll;
  double x_u;
  double x_ur;
  double y_l;
  double y_lr;
  double y_u;
  double y_ul;
  int x_u_tmp;
  y_ul = minimum(rows_data, ii, &idx);
  y_lr = maximum(rows_data, ii, &jj);
  x_ll = minimum(cols_data, ii, &iindx);
  x_ur = maximum(cols_data, ii, &b_iindx);
  /*  get view angle geometry */
  /*  imput "x",j */
  /*  imput "y",i */
  /*  imput cloud height "h" */
  x_u_tmp = (int)cols_data[idx - 1];
  x_u = ((double)x_u_tmp + x_ur) / 2.0;
  jj = (int)cols_data[jj - 1];
  x_l = (x_ll + (double)jj) / 2.0;
  ii = (int)rows_data[b_iindx - 1];
  y_u = (y_ul + (double)ii) / 2.0;
  idx = (int)rows_data[iindx - 1];
  y_l = ((double)idx + y_lr) / 2.0;
  /*  get k of the upper left and right points */
  /*  get k of the lower left and right points */
  *omiga_par = atan(((y_ul - (double)ii) / ((double)x_u_tmp - x_ur) +
                     ((double)idx - y_lr) / (x_ll - (double)jj)) /
                    2.0);
  /*  get the angle of parallel lines k (in pi) */
  /*  AX(j)+BY(i)+C=0 */
  *A = y_u - y_l;
  *B = x_l - x_u;
  *C = y_l * x_u - x_l * y_u;
  *omiga_per = atan(*B / *A);
  /*  get the angle which is perpendicular to the trace line */
}

/*
 * File trailer for imfil.c
 *
 * [EOF]
 */