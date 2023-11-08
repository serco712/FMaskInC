/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * strel.h
 *
 * Code generation for function 'strel'
 *
 */

#ifndef STREL_H
#define STREL_H

/* Include files */
#include "Fmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void strel_decompose(const c_emxArray_images_internal_code *obj_StrelArray,
                     const emxArray_cell_wrap_14 *obj_DecomposedStrelArray,
                     c_emxArray_images_internal_code *seq_StrelArray,
                     emxArray_cell_wrap_14 *seq_DecomposedStrelArray,
                     emxArray_boolean_T *isEachStrelObj2D);

void strel_getpadsize(const c_emxArray_images_internal_code *obj_StrelArray,
                      const emxArray_cell_wrap_14 *obj_DecomposedStrelArray,
                      double pad_ul_data[], int pad_ul_size[2],
                      double pad_lr_data[], int pad_lr_size[2]);

boolean_T strel_isdecompositionorthogonal(
    const c_emxArray_images_internal_code *obj_StrelArray,
    const emxArray_cell_wrap_14 *obj_DecomposedStrelArray);

void strel_parenReference(strel *obj, double idx);

void strel_strel(double varargin_2,
                 c_emxArray_images_internal_code *obj_StrelArray,
                 emxArray_cell_wrap_14 *obj_DecomposedStrelArray);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (strel.h) */
