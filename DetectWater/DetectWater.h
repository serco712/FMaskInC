/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DetectWater.h
 *
 * Code generation for function 'DetectWater'
 *
 */

#ifndef DETECTWATER_H
#define DETECTWATER_H

/* Include files */
#include "DetectWater_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void DetectWater(const double dim[2], const emxArray_boolean_T *mask,
                        const emxArray_real32_T *nir,
                        const emxArray_real32_T *NDVI,
                        const emxArray_boolean_T *psnow,
                        const emxArray_real32_T *gswater,
                        emxArray_uint8_T *water, emxArray_uint8_T *waterAll);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (DetectWater.h) */
