/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NDVI.h
 *
 * Code generation for function 'NDVI'
 *
 */

#ifndef NDVI_H
#define NDVI_H

/* Include files */
#include "types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void NDVI(const emxArray_real32_T *red, const emxArray_real32_T *nir,
                 emxArray_real32_T *ndvi);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (NDVI.h) */
