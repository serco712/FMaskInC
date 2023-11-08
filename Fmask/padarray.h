/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * padarray.h
 *
 * Code generation for function 'padarray'
 *
 */

#ifndef PADARRAY_H
#define PADARRAY_H

/* Include files */
#include "Fmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_padarray(const emxArray_uint8_T *varargin_1,
                const double varargin_2_data[], emxArray_uint8_T *b);

void c_padarray(const emxArray_uint8_T *varargin_1,
                const double varargin_2_data[], emxArray_uint8_T *b);

void padarray(const emxArray_real32_T *varargin_1, emxArray_real32_T *b);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (padarray.h) */
