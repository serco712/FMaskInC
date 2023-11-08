/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * morphop.c
 *
 * Code generation for function 'morphop'
 *
 */

/* Include files */
#include "morphop.h"
#include "Fmask_types.h"

/* Function Definitions */
boolean_T useIPP(const emxArray_boolean_T *nhood,
                 const emxArray_real_T *allheightIn)
{
  const double *allheightIn_data;
  int k;
  const boolean_T *nhood_data;
  boolean_T TF;
  allheightIn_data = allheightIn->data;
  nhood_data = nhood->data;
  TF = false;
  if ((nhood->size[0] != 0) && (nhood->size[1] != 0)) {
    int i;
    int n;
    boolean_T x[3];
    boolean_T b_y;
    boolean_T exitg1;
    boolean_T y;
    x[0] = (nhood->size[0] > 200);
    x[1] = (nhood->size[1] > 200);
    x[2] = false;
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (x[k]) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    n = 0;
    i = nhood->size[0] * nhood->size[1];
    for (k = 0; k < i; k++) {
      if (nhood_data[k]) {
        n++;
      }
    }
    b_y = false;
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (k <= allheightIn->size[0] * allheightIn->size[1])) {
      if (allheightIn_data[k - 1] != 0.0) {
        b_y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if ((!b_y) && (!y) && ((double)n / (double)i >= 0.05)) {
      TF = true;
    }
  }
  return TF;
}

/* End of code generation (morphop.c) */
