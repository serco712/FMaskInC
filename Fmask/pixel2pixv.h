/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pixel2pixv.h
 *
 * Code generation for function 'pixel2pixv'
 *
 */

#ifndef PIXEL2PIXV_H
#define PIXEL2PIXV_H

/* Include files */
#include "Fmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void pixel2pixv(const double jiul1[2], const double jiul2[2],
                const double resolu1[4], const double resolu2[4],
                const emxArray_real32_T *im2, const double jidim1[2],
                const double jidim2[2], emxArray_real32_T *outim);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (pixel2pixv.h) */
