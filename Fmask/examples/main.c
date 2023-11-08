/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include "Fmask.h"
#include "Fmask_emxAPI.h"
#include "Fmask_terminate.h"
#include "Fmask_types.h"

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);

static void argInit_1x7_real_T(double result[7]);

static void argInit_1x9_real_T(double result[9]);

static float argInit_real32_T(void);

static double argInit_real_T(void);

static emxArray_real32_T *c_argInit_UnboundedxUnbounded_r(void);

/* Function Definitions */
static void argInit_1x2_real_T(double result[2])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x7_real_T(double result[7])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 7; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x9_real_T(double result[9])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 9; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static float argInit_real32_T(void)
{
  return 0.0F;
}

static double argInit_real_T(void)
{
  return 0.0;
}

static emxArray_real32_T *c_argInit_UnboundedxUnbounded_r(void)
{
  emxArray_real32_T *result;
  float *result_data;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real32_T(2, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result_data[idx0 + result->size[0] * idx1] = argInit_real32_T();
    }
  }
  return result;
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_Fmask();
  /* Terminate the application.
You do not need to do this more than one time. */
  Fmask_terminate();
  return 0;
}

void main_Fmask(void)
{
  emxArray_real32_T *im_B1;
  emxArray_real32_T *im_B10;
  emxArray_real32_T *im_B11;
  emxArray_real32_T *im_B2;
  emxArray_real32_T *im_B3;
  emxArray_real32_T *im_B4;
  emxArray_real32_T *im_B5;
  emxArray_real32_T *im_B6;
  emxArray_real32_T *im_B7;
  emxArray_real32_T *im_B9;
  double Lmax_tmp[9];
  double Refmax_tmp[7];
  double ijdim_ref_tmp[2];
  double reso_ref_tmp[2];
  double cldpix_tmp;
  /* Initialize function 'Fmask' input arguments. */
  cldpix_tmp = argInit_real_T();
  /* Initialize function input argument 'Lmax'. */
  argInit_1x9_real_T(Lmax_tmp);
  /* Initialize function input argument 'Lmin'. */
  /* Initialize function input argument 'Qcalmax'. */
  /* Initialize function input argument 'Qcalmin'. */
  /* Initialize function input argument 'Refmax'. */
  argInit_1x7_real_T(Refmax_tmp);
  /* Initialize function input argument 'Refmin'. */
  /* Initialize function input argument 'ijdim_ref'. */
  argInit_1x2_real_T(ijdim_ref_tmp);
  /* Initialize function input argument 'ijdim_thm'. */
  /* Initialize function input argument 'reso_ref'. */
  argInit_1x2_real_T(reso_ref_tmp);
  /* Initialize function input argument 'reso_thm'. */
  /* Initialize function input argument 'ul'. */
  /* Initialize function input argument 'zc'. */
  /* Initialize function input argument 'im_B1'. */
  im_B1 = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'im_B2'. */
  im_B2 = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'im_B3'. */
  im_B3 = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'im_B4'. */
  im_B4 = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'im_B5'. */
  im_B5 = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'im_B6'. */
  im_B6 = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'im_B7'. */
  im_B7 = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'im_B9'. */
  im_B9 = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'im_B10'. */
  im_B10 = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'im_B11'. */
  im_B11 = c_argInit_UnboundedxUnbounded_r();
  /* Call the entry-point 'Fmask'. */
  cldpix_tmp = Fmask(cldpix_tmp, cldpix_tmp, cldpix_tmp, cldpix_tmp, cldpix_tmp,
                     Lmax_tmp, Lmax_tmp, Lmax_tmp, Lmax_tmp, Refmax_tmp,
                     Refmax_tmp, ijdim_ref_tmp, ijdim_ref_tmp, reso_ref_tmp,
                     reso_ref_tmp, ijdim_ref_tmp, cldpix_tmp, cldpix_tmp,
                     reso_ref_tmp, cldpix_tmp, cldpix_tmp, im_B1, im_B2, im_B3,
                     im_B4, im_B5, im_B6, im_B7, im_B9, im_B10, im_B11);
  emxDestroyArray_real32_T(im_B11);
  emxDestroyArray_real32_T(im_B10);
  emxDestroyArray_real32_T(im_B9);
  emxDestroyArray_real32_T(im_B7);
  emxDestroyArray_real32_T(im_B6);
  emxDestroyArray_real32_T(im_B5);
  emxDestroyArray_real32_T(im_B4);
  emxDestroyArray_real32_T(im_B3);
  emxDestroyArray_real32_T(im_B2);
  emxDestroyArray_real32_T(im_B1);
}

/* End of code generation (main.c) */
