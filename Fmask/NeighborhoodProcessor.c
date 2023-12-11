/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: NeighborhoodProcessor.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 04-Dec-2023 17:32:24
 */

/* Include Files */
#include "NeighborhoodProcessor.h"
#include <float.h>
#include <math.h>

/* Function Declarations */
static double rt_remd(double u0, double u1);

/* Function Definitions */
/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_remd(double u0, double u1)
{
  double y;
  if ((u1 != 0.0) && (u1 != trunc(u1))) {
    double q;
    q = fabs(u0 / u1);
    if (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q) {
      y = 0.0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }
  return y;
}

/*
 * Arguments    : const int imSize[2]
 *                const bool nhConn[9]
 *                int loffsets[5]
 *                int linds[5]
 *                int soffsets[10]
 *                int interiorStart[2]
 *                int interiorEnd[2]
 * Return Type  : void
 */
void c_NeighborhoodProcessor_compute(const int imSize[2], const bool nhConn[9],
                                     int loffsets[5], int linds[5],
                                     int soffsets[10], int interiorStart[2],
                                     int interiorEnd[2])
{
  int i;
  int i1;
  int indx;
  int k;
  int pind;
  int pixelsPerImPage1_idx_1;
  bool bv[9];
  pixelsPerImPage1_idx_1 = imSize[0];
  interiorStart[0] = 2;
  interiorEnd[0] = imSize[0] - 1;
  interiorStart[1] = 2;
  interiorEnd[1] = imSize[1] - 1;
  i = 0;
  i1 = 0;
  for (indx = 0; indx < 9; indx++) {
    bv[indx] = nhConn[i1 + 3 * i];
    i++;
    if (i > 2) {
      i = 0;
      i1++;
    }
  }
  indx = bv[0];
  for (k = 0; k < 8; k++) {
    indx += bv[k + 1];
  }
  if (indx != 0) {
    int a[10];
    bool b;
    indx = 0;
    b = true;
    i = 0;
    for (pind = 0; pind < 9; pind++) {
      if (b) {
        b = false;
        i = pind % 3 * 3 + pind / 3;
      } else {
        i += 3;
        if (i > 8) {
          i -= 8;
        }
      }
      if (nhConn[i]) {
        int subs_idx_1_tmp;
        k = (int)rt_remd(((double)pind + 1.0) - 1.0, 3.0);
        subs_idx_1_tmp = (int)(((double)((pind - k) - 1) + 1.0) / 3.0);
        i1 = indx << 1;
        soffsets[i1] = k + 1;
        soffsets[i1 + 1] = subs_idx_1_tmp + 1;
        linds[indx] = (k + subs_idx_1_tmp * 3) + 1;
        loffsets[indx] = (k + subs_idx_1_tmp * pixelsPerImPage1_idx_1) + 1;
        indx++;
      }
    }
    for (i = 0; i < 5; i++) {
      loffsets[i] = (loffsets[i] - pixelsPerImPage1_idx_1) - 2;
    }
    for (i = 0; i < 10; i++) {
      a[i] = soffsets[i];
    }
    for (k = 0; k < 5; k++) {
      i = k << 1;
      soffsets[i] = a[i] - 2;
      soffsets[i + 1] = a[i + 1] - 2;
    }
  }
}

/*
 * File trailer for NeighborhoodProcessor.c
 *
 * [EOF]
 */
