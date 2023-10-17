/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DetectSnow.h
 *
 * Code generation for function 'DetectSnow'
 *
 */

#ifndef DETECTSNOW_H
#define DETECTSNOW_H

/* Include files */
#include "DetectSnow_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void DetectSnow(const double dim[2], const emxArray_real32_T *band_green,
                       const emxArray_real32_T *band_nir,
                       const emxArray_real32_T *band_bt,
                       const emxArray_real32_T *ndsi, emxArray_boolean_T *snow);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (DetectSnow.h) */
