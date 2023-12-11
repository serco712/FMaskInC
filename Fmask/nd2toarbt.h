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
#include "rtwtypes.h"


#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void nd2toarbt(const double Lmax[9], const double Lmin[9],
               const double Qcalmax[9], const double Qcalmin[9],
               const double Refmax[7], const double Refmin[7],
               const double ijdim_ref[2],
               const double reso_ref[2], double ul[2],
               double zen, double Lnum, double doy, float *im_B1_data,
               float *im_B2_data, float *im_B3_data,
               float *im_B4_data, float *im_B5_data, float *im_B7_data,
               float *im_B9_data, double resolu[4], unsigned char *B1Satu_data,
               unsigned char *B2Satu_data, unsigned char *B3Satu_data, unsigned char *id_missing_data,
               float *TOAref_data);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (nd2toarbt.h) */
