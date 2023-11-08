/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ismember.h
 *
 * Code generation for function 'ismember'
 *
 */

#ifndef ISMEMBER_H
#define ISMEMBER_H

/* Include files */
#include "Fmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void isMember(const emxArray_real_T *a, const emxArray_real_T *s,
              emxArray_boolean_T *tf);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (ismember.h) */
