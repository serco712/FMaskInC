/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: minOrMax.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 04-Dec-2023 17:32:24
 */

#ifndef MINORMAX_H
#define MINORMAX_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
float fmaximum(const float x_data[], int x_size);

double maximum(const double x_data[], int x_size, int *idx);

double minimum(const double x_data[], int x_size, int *idx);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for minOrMax.h
 *
 * [EOF]
 */
