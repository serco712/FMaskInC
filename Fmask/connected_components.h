/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 */

#ifndef CONNECTEDCOMPONENTS_H
#define CONNECTEDCOMPONENTS_H

/* Include Files */
#include "rtwtypes.h"

#define MAX_REGION 25

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void connected_components(const double L[100], const double num_el, const int width,
        int sizes[MAX_REGION], double orin_x[100], double orin_y[100]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for imfil.h
 *
 * [EOF]
 */