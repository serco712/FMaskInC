/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * integralImage.c
 *
 * Code generation for function 'integralImage'
 *
 */

/* Include files */
#include "integralImage.h"
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"
#include "useConstantDim.h"

/* Function Definitions */
void integralImage(const emxArray_real_T *b_I, emxArray_real_T *intImage)
{
  emxArray_real_T *r;
  const double *I_data;
  double *intImage_data;
  double *r1;
  int i;
  int i2;
  int i3;
  I_data = b_I->data;
  if ((b_I->size[0] != 0) && (b_I->size[1] != 0)) {
    int i1;
    int loop_ub;
    i = intImage->size[0] * intImage->size[1];
    intImage->size[0] = (int)((unsigned int)b_I->size[0] + 1U);
    intImage->size[1] = (int)((unsigned int)b_I->size[1] + 1U);
    emxEnsureCapacity_real_T(intImage, i);
    intImage_data = intImage->data;
    loop_ub = (int)((unsigned int)b_I->size[0] + 1U) *
              (int)((unsigned int)b_I->size[1] + 1U);
    for (i = 0; i < loop_ub; i++) {
      intImage_data[i] = 0.0;
    }
    i = ((int)((unsigned int)b_I->size[0] + 1U) >= 2);
    i1 = ((int)((unsigned int)b_I->size[1] + 1U) >= 2);
    emxInit_real_T(&r, 2);
    i2 = r->size[0] * r->size[1];
    r->size[0] = b_I->size[0];
    r->size[1] = b_I->size[1];
    emxEnsureCapacity_real_T(r, i2);
    r1 = r->data;
    loop_ub = b_I->size[0] * b_I->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      r1[i2] = I_data[i2];
    }
    useConstantDim(r, 1);
    useConstantDim(r, 2);
    r1 = r->data;
    loop_ub = r->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      int b_loop_ub;
      b_loop_ub = r->size[0];
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        intImage_data[(i + i3) + intImage->size[0] * (i1 + i2)] =
            r1[i3 + r->size[0] * i2];
      }
    }
    emxFree_real_T(&r);
  } else {
    intImage->size[0] = 0;
    intImage->size[1] = 0;
  }
}

/* End of code generation (integralImage.c) */
