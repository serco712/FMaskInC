/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * autoFmask.h
 *
 * Code generation for function 'autoFmask'
 *
 */

#ifndef AUTOFMASK_H
#define AUTOFMASK_H

/* Include files */
#include "autoFmask_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern double autoFmask(const ObjMeta *data_meta, const ObjTOABT *data_toabt,
                        const emxArray_real32_T *water_occur, double cldpix,
                        double snpix, double cldprob, double tpw);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (autoFmask.h) */
