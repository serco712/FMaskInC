/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DetectPotentialCloud.h
 *
 * Code generation for function 'DetectPotentialCloud'
 *
 */

#ifndef DETECTPOTENTIALCLOUD_H
#define DETECTPOTENTIALCLOUD_H

/* Include files */
#include "autoFmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double DetectPotentialCloud(
    const double data_meta_Dim[2], const emxArray_boolean_T *mask,
    const emxArray_uint8_T *water,
    const emxArray_real32_T *data_toabt_BandCirrus,
    const emxArray_real32_T *data_toabt_BandSWIR1,
    const emxArray_real32_T *data_toabt_BandBT,
    const emxArray_boolean_T *data_toabt_SatuGreen,
    const emxArray_boolean_T *data_toabt_SatuRed, const emxArray_real32_T *ndvi,
    const emxArray_real32_T *ndsi, const emxArray_real32_T *ndbi,
    const emxArray_boolean_T *idplcd, const emxArray_real32_T *whiteness,
    const emxArray_real32_T *HOT, double wpt, double cldprob,
    emxArray_boolean_T *cloud);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (DetectPotentialCloud.h) */
