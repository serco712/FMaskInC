/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CDI.h
 *
 * Code generation for function 'CDI'
 *
 */

#ifndef CDI_H
#define CDI_H

/* Include files */
#include "CDI_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void CDI(const emxArray_real32_T *S2band7,
                const emxArray_real32_T *S2band8,
                const emxArray_real32_T *S2band8A, emxArray_real_T *cdi);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (CDI.h) */
