/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Fmask.h
 *
 * Code generation for function 'Fmask'
 *
 */

#ifndef FMASK_H
#define FMASK_H

/* Include files */
#include "rtwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif



/* Function Declarations */
extern double
Fmask(double cldpix, double sdpix, double snpix, double cldprob, double num_Lst,
      const double Lmax[9], const double Lmin[9], const double Qcalmax[9],
      const double Qcalmin[9], const double Refmax[7], const double Refmin[7],
      const double ijdim_ref[2], const double ijdim_thm[2],
      const double reso_ref[2], const double reso_thm[2], const double ul[2],
      double zen, double azi, const double zc[2], double Lnum, double doy);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (Fmask.h) */
