/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fcssm.h
 *
 * Code generation for function 'fcssm'
 *
 */

#ifndef FCSSM_H
#define FCSSM_H

/* Include files */
#include "Fmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double fcssm(double Sun_zen, double Sun_azi, double ptm,
             const emxArray_uint8_T *Water, emxArray_uint8_T *Snow,
             const emxArray_uint8_T *plcim, const emxArray_uint8_T *plsim,
             const double ijDim[2], const double resolu[4], double cldpix,
             double sdpix, double snpix);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (fcssm.h) */
