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
#include "Fmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void nd2toarbt(const double Lmax[9], const double Lmin[9],
               const double Qcalmax[9], const double Qcalmin[9],
               const double Refmax[7], const double Refmin[7],
               const double ijdim_ref[2], const double ijdim_thm[2],
               const double reso_ref[2], const double reso_thm[2], double ul[2],
               double zen, double Lnum, double doy, emxArray_real32_T *im_B1,
               emxArray_real32_T *im_B2, emxArray_real32_T *im_B3,
               emxArray_real32_T *im_B4, emxArray_real32_T *im_B5,
               emxArray_real32_T *im_B6, emxArray_real32_T *im_B7,
               emxArray_real32_T *im_B9, emxArray_real32_T *im_B10,
               emxArray_real32_T *im_B11, emxArray_real32_T *im_th,
               emxArray_real32_T *TOAref, emxArray_boolean_T *B1Satu,
               emxArray_boolean_T *B2Satu, emxArray_boolean_T *B3Satu,
               double resolu[4]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (nd2toarbt.h) */
