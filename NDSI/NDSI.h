/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NDSI.h
 *
 * Code generation for function 'NDSI'
 *
 */

#ifndef NDSI_H
#define NDSI_H

/* Include files */
#include "NDSI_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void NDSI(const emxArray_real32_T *green, const emxArray_real32_T *swir,
                 emxArray_real32_T *ndsi);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (NDSI.h) */
