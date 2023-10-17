/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DetectPotentialPixels.h
 *
 * Code generation for function 'DetectPotentialPixels'
 *
 */

#ifndef DETECTPOTENTIALPIXELS_H
#define DETECTPOTENTIALPIXELS_H

/* Include files */
#include "DetectPotentialPixels_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void DetectPotentialPixels(
    const emxArray_boolean_T *mask, const ObjTOABT *data_toabt, double dem,
    const emxArray_real32_T *ndvi, const emxArray_real32_T *ndsi,
    const emxArray_boolean_T *satu_Bv, emxArray_boolean_T *idplcd,
    emxArray_real_T *BandCirrusNormal, emxArray_real32_T *whiteness,
    emxArray_real32_T *HOT);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (DetectPotentialPixels.h) */
