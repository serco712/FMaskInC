/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DetectAbsSnow.h
 *
 * Code generation for function 'DetectAbsSnow'
 *
 */

#ifndef DETECTABSSNOW_H
#define DETECTABSSNOW_H

/* Include files */
#include "autoFmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void DetectAbsSnow(const emxArray_real32_T *band_green,
                   const emxArray_boolean_T *band_green_statu,
                   const emxArray_real32_T *ndsi,
                   const emxArray_boolean_T *psnow, double resolution,
                   emxArray_boolean_T *abs_snow);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (DetectAbsSnow.h) */
