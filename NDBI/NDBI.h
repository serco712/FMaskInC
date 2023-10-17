/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * NDBI.h
 *
 * Code generation for function 'NDBI'
 *
 */

#ifndef NDBI_H
#define NDBI_H

/* Include files */
#include "NDBI_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void NDBI(const emxArray_real32_T *nir, const emxArray_real32_T *swir,
                 emxArray_real32_T *ndbi);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (NDBI.h) */
