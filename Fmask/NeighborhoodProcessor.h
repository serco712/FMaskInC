/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: NeighborhoodProcessor.h
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 04-Dec-2023 17:32:24
 */

#ifndef NEIGHBORHOODPROCESSOR_H
#define NEIGHBORHOODPROCESSOR_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void c_NeighborhoodProcessor_compute(const int imSize[2], const bool nhConn[9],
                                     int loffsets[5], int linds[5],
                                     int soffsets[10], int interiorStart[2],
                                     int interiorEnd[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for NeighborhoodProcessor.h
 *
 * [EOF]
 */
