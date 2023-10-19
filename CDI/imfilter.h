/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imfilter.h
 *
 * Code generation for function 'imfilter'
 *
 */

#ifndef IMFILTER_H
#define IMFILTER_H

/* Include files */
#include "CDI_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void padImage(const emxArray_real_T *a_tmp, const double pad[2],
              emxArray_real_T *a);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (imfilter.h) */
