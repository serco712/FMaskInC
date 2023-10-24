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
#include "autoFmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_padarray(const emxArray_boolean_T *varargin_1,
                const double varargin_2_data[], emxArray_boolean_T *b);

void padarray(const emxArray_real_T *varargin_1, const double varargin_2[2],
              emxArray_real_T *b);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (padarray.h) */
