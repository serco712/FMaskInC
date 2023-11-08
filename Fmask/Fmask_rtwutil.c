/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Fmask_rtwutil.c
 *
 * Code generation for function 'Fmask_rtwutil'
 *
 */

/* Include files */
#include "Fmask_rtwutil.h"
#include <math.h>

/* Function Definitions */
int div_s32(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int tempAbsQuotient;
    unsigned int u;
    if (numerator < 0) {
      tempAbsQuotient = ~(unsigned int)numerator + 1U;
    } else {
      tempAbsQuotient = (unsigned int)numerator;
    }
    if (denominator < 0) {
      u = ~(unsigned int)denominator + 1U;
    } else {
      u = (unsigned int)denominator;
    }
    tempAbsQuotient /= u;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int)tempAbsQuotient;
    } else {
      quotient = (int)tempAbsQuotient;
    }
  }
  return quotient;
}

double rt_roundd(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

/* End of code generation (Fmask_rtwutil.c) */
