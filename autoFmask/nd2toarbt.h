/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nd2toarbt.h
 *
 * Code generation for function 'nd2toarbt'
 *
 */

#ifndef ND2TOARBT_H
#define ND2TOARBT_H

/* Include files */
#include "autoFmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void nd2toarbt(emxArray_real32_T *im_B1, emxArray_real32_T *im_B2,
                      emxArray_real32_T *im_B3, emxArray_real32_T *im_B4,
                      emxArray_real32_T *im_B5, emxArray_real32_T *im_th,
                      emxArray_real32_T *im_B7, const float Lmax[7],
                      const float Lmin[7], const float Qcalmax[7],
                      const float Qcalmin[7], const float ijdim_ref[2],
                      float reso_ref, float reso_thm, double ul[2],
                      const double bbox[4], const double *zen,
                      const double *azi, const double *zc, double Lnum,
                      double doy, emxArray_real32_T *TOAref,
                      emxArray_boolean_T *B1Satu, emxArray_boolean_T *B2Satu,
                      emxArray_boolean_T *B3Satu, float resolu[2]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (nd2toarbt.h) */
