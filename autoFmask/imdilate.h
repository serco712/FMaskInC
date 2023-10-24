/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imdilate.h
 *
 * Code generation for function 'imdilate'
 *
 */

#ifndef IMDILATE_H
#define IMDILATE_H

/* Include files */
#include "autoFmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void imdilate(const emxArray_boolean_T *A,
              const c_emxArray_images_internal_code *se_StrelArray,
              const emxArray_cell_wrap_22 *se_DecomposedStrelArray,
              emxArray_boolean_T *B);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (imdilate.h) */
