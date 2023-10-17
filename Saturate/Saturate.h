/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Saturate.h
 *
 * Code generation for function 'Saturate'
 *
 */

#ifndef SATURATE_H
#define SATURATE_H

/* Include files */
#include "Saturate_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Saturate(const emxArray_boolean_T *satu_blue,
                     const emxArray_boolean_T *satu_green,
                     const emxArray_boolean_T *satu_red,
                     emxArray_boolean_T *satu_Bv);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (Saturate.h) */
