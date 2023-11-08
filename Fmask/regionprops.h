/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * regionprops.h
 *
 * Code generation for function 'regionprops'
 *
 */

#ifndef REGIONPROPS_H
#define REGIONPROPS_H

/* Include files */
#include "Fmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_regionprops(const emxArray_real_T *varargin_1,
                   b_emxArray_struct_T *outstats);

void regionprops(const emxArray_real_T *varargin_1,
                 emxArray_struct_T *outstats);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (regionprops.h) */
