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
#include "DetectPotentialPixels.h"
#include "DetectPotentialPixels_emxAPI.h"
#include "DetectPotentialPixels_terminate.h"
#include "DetectPotentialPixels_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_ObjTOABT(ObjTOABT *result);

static boolean_T argInit_boolean_T(void);

static float argInit_real32_T(void);

static double argInit_real_T(void);

static emxArray_boolean_T *c_argInit_UnboundedxUnbounded_b(void);

static emxArray_real32_T *c_argInit_UnboundedxUnbounded_r(void);

/* Function Definitions */
static void argInit_ObjTOABT(ObjTOABT *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result->BandCA = c_argInit_UnboundedxUnbounded_r();
  result->BandBlue = c_argInit_UnboundedxUnbounded_r();
  result->BandGreen = c_argInit_UnboundedxUnbounded_r();
  result->BandRed = c_argInit_UnboundedxUnbounded_r();
  result->BandVRE1 = c_argInit_UnboundedxUnbounded_r();
  result->BandVRE2 = c_argInit_UnboundedxUnbounded_r();
  result->BandVRE3 = c_argInit_UnboundedxUnbounded_r();
  result->BandNIR8 = c_argInit_UnboundedxUnbounded_r();
  result->BandNIR = c_argInit_UnboundedxUnbounded_r();
  result->BandWV = c_argInit_UnboundedxUnbounded_r();
  result->BandCirrus = c_argInit_UnboundedxUnbounded_r();
  result->BandSWIR1 = c_argInit_UnboundedxUnbounded_r();
  result->BandSWIR2 = c_argInit_UnboundedxUnbounded_r();
  result->BandBT = c_argInit_UnboundedxUnbounded_r();
  result->SatuBlue = c_argInit_UnboundedxUnbounded_b();
  result->SatuGreen = c_argInit_UnboundedxUnbounded_b();
  result->SatuRed = c_argInit_UnboundedxUnbounded_b();
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
  main_DetectPotentialPixels();
  /* Terminate the application.
You do not need to do this more than one time. */
  DetectPotentialPixels_terminate();
  return 0;
}

void main_DetectPotentialPixels(void)
{
  ObjTOABT data_toabt;
  emxArray_boolean_T *idplcd;
  emxArray_boolean_T *mask;
  emxArray_boolean_T *satu_Bv;
  emxArray_real32_T *HOT;
  emxArray_real32_T *ndsi;
  emxArray_real32_T *ndvi;
  emxArray_real32_T *whiteness;
  emxArray_real_T *BandCirrusNormal;
  /* Initialize function 'DetectPotentialPixels' input arguments. */
  /* Initialize function input argument 'mask'. */
  mask = c_argInit_UnboundedxUnbounded_b();
  /* Initialize function input argument 'data_toabt'. */
  argInit_ObjTOABT(&data_toabt);
  /* Initialize function input argument 'ndvi'. */
  ndvi = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'ndsi'. */
  ndsi = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'satu_Bv'. */
  satu_Bv = c_argInit_UnboundedxUnbounded_b();
  /* Call the entry-point 'DetectPotentialPixels'. */
  emxInitArray_boolean_T(&idplcd, 2);
  emxInitArray_real_T(&BandCirrusNormal, 2);
  emxInitArray_real32_T(&whiteness, 2);
  emxInitArray_real32_T(&HOT, 2);
  DetectPotentialPixels(mask, &data_toabt, argInit_real_T(), ndvi, ndsi,
                        satu_Bv, idplcd, BandCirrusNormal, whiteness, HOT);
  emxDestroyArray_boolean_T(satu_Bv);
  emxDestroyArray_real32_T(ndsi);
  emxDestroyArray_real32_T(ndvi);
  emxDestroy_ObjTOABT(data_toabt);
  emxDestroyArray_boolean_T(mask);
  emxDestroyArray_boolean_T(idplcd);
  emxDestroyArray_real_T(BandCirrusNormal);
  emxDestroyArray_real32_T(whiteness);
  emxDestroyArray_real32_T(HOT);
}

/* End of code generation (main.c) */
