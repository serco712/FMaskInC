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
#include "DetectWater.h"
#include "DetectWater_emxAPI.h"
#include "DetectWater_terminate.h"
#include "DetectWater_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);

static boolean_T argInit_boolean_T(void);

static float argInit_real32_T(void);

static double argInit_real_T(void);

static emxArray_boolean_T *c_argInit_UnboundedxUnbounded_b(void);

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

static boolean_T argInit_boolean_T(void)
{
  return false;
}

static float argInit_real32_T(void)
{
  return 0.0F;
}

static double argInit_real_T(void)
{
  return 0.0;
}

static emxArray_boolean_T *c_argInit_UnboundedxUnbounded_b(void)
{
  emxArray_boolean_T *result;
  int idx0;
  int idx1;
  boolean_T *result_data;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_boolean_T(2, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result_data[idx0 + result->size[0] * idx1] = argInit_boolean_T();
    }
  }
  return result;
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
  main_DetectWater();
  /* Terminate the application.
You do not need to do this more than one time. */
  DetectWater_terminate();
  return 0;
}

void main_DetectWater(void)
{
  emxArray_boolean_T *mask;
  emxArray_boolean_T *psnow;
  emxArray_real32_T *NDVI;
  emxArray_real32_T *nir;
  emxArray_uint8_T *water;
  emxArray_uint8_T *waterAll;
  double dv[2];
  double slope_tmp;
  /* Initialize function 'DetectWater' input arguments. */
  /* Initialize function input argument 'dim'. */
  /* Initialize function input argument 'mask'. */
  mask = c_argInit_UnboundedxUnbounded_b();
  /* Initialize function input argument 'nir'. */
  nir = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'NDVI'. */
  NDVI = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'psnow'. */
  psnow = c_argInit_UnboundedxUnbounded_b();
  slope_tmp = argInit_real_T();
  /* Call the entry-point 'DetectWater'. */
  emxInitArray_uint8_T(&water, 2);
  emxInitArray_uint8_T(&waterAll, 2);
  argInit_1x2_real_T(dv);
  DetectWater(dv, mask, nir, NDVI, psnow, slope_tmp, slope_tmp, water,
              waterAll);
  emxDestroyArray_boolean_T(psnow);
  emxDestroyArray_real32_T(NDVI);
  emxDestroyArray_real32_T(nir);
  emxDestroyArray_boolean_T(mask);
  emxDestroyArray_uint8_T(water);
  emxDestroyArray_uint8_T(waterAll);
}

/* End of code generation (main.c) */
