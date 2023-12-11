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
#include "rtwtypes.h"
#include "space.h"

#ifdef __cplusplus
extern "C" {
#endif



/* Function Declarations */
double fcssm(double Sun_zen, double Sun_azi, double ptm,
             unsigned char Water[IMG_SIZE], unsigned char Snow[IMG_SIZE],
             unsigned char plcim[IMG_SIZE], unsigned char plsim[IMG_SIZE],
             const double ijDim[2], const double resolu[4], double cldpix,
             double sdpix, double snpix, struct tData *data);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (fcssm.h) */
