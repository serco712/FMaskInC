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
#include "types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void DetectPotentialCloud(
    const ObjMeta *data_meta, const emxArray_boolean_T *mask,
    const emxArray_uint8_T *water, const ObjTOABT *data_toabt,
    const GRIDobj *dem, const emxArray_real32_T *ndvi,
    const emxArray_real32_T *ndsi, const emxArray_real32_T *ndbi,
    const emxArray_boolean_T *idplcd, const emxArray_real32_T *whiteness,
    const emxArray_real32_T *HOT, const emxArray_real32_T *wpt,
    const emxArray_real32_T *cldprob, double *sum_clr, emxArray_uint8_T *cloud,
    emxArray_boolean_T *idused, float *t_templ, float *t_temph);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (DetectPotentialCloud.h) */
