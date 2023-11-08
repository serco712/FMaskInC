/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * horzcatStructList.c
 *
 * Code generation for function 'horzcatStructList'
 *
 */

/* Include files */
#include "horzcatStructList.h"
#include "Fmask_emxutil.h"
#include "Fmask_types.h"

/* Function Definitions */
void horzcatStructList(const emxArray_struct_T *structure,
                       emxArray_real_T *result)
{
  const struct_T *structure_data;
  double *result_data;
  int i;
  int n;
  structure_data = structure->data;
  n = structure->size[0];
  i = result->size[0] * result->size[1];
  result->size[0] = 1;
  if (structure->size[0] == 0) {
    result->size[1] = 0;
  } else {
    result->size[1] = structure->size[0];
  }
  emxEnsureCapacity_real_T(result, i);
  result_data = result->data;
  for (i = 0; i < n; i++) {
    result_data[i] = structure_data[i].Area;
  }
}

/* End of code generation (horzcatStructList.c) */
