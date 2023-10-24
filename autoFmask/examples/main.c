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
#include "autoFmask.h"
#include "autoFmask_emxAPI.h"
#include "autoFmask_terminate.h"
#include "autoFmask_types.h"

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);

static emxArray_char_T *argInit_1xUnbounded_char_T(void);

static void argInit_2x2_real_T(double result[4]);

static void argInit_ObjMeta(ObjMeta *result);

static void argInit_ObjTOABT(ObjTOABT *result);

static boolean_T argInit_boolean_T(void);

static char argInit_char_T(void);

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

static emxArray_char_T *argInit_1xUnbounded_char_T(void)
{
  emxArray_char_T *result;
  int idx0;
  int idx1;
  char *result_data;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_char_T(1, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 1; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result_data[idx1] = argInit_char_T();
    }
  }
  return result;
}

static void argInit_2x2_real_T(double result[4])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 4; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_real_T();
  }
}

static void argInit_ObjMeta(ObjMeta *result)
{
  double result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_1x2_real_T(result->Dim);
  result_tmp = argInit_real_T();
  result->Azi = result_tmp;
  result->BBox = result_tmp;
  result->Name = argInit_1xUnbounded_char_T();
  result->Sensor = argInit_1xUnbounded_char_T();
  argInit_2x2_real_T(result->Resolution);
  result->Zen = result_tmp;
  argInit_1x2_real_T(result->ZC);
  result->Output = argInit_1xUnbounded_char_T();
  result->UL[0] = result->Dim[0];
  result->UL[1] = result->Dim[1];
}

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

static char argInit_char_T(void)
{
  return '?';
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
  main_autoFmask();
  /* Terminate the application.
You do not need to do this more than one time. */
  autoFmask_terminate();
  return 0;
}

void main_autoFmask(void)
{
  ObjMeta data_meta;
  ObjTOABT data_toabt;
  emxArray_real32_T *water_occur;
  double cldpix_tmp;
  /* Initialize function 'autoFmask' input arguments. */
  /* Initialize function input argument 'data_meta'. */
  argInit_ObjMeta(&data_meta);
  /* Initialize function input argument 'data_toabt'. */
  argInit_ObjTOABT(&data_toabt);
  /* Initialize function input argument 'water_occur'. */
  water_occur = c_argInit_UnboundedxUnbounded_r();
  cldpix_tmp = argInit_real_T();
  /* Call the entry-point 'autoFmask'. */
  cldpix_tmp = autoFmask(&data_meta, &data_toabt, water_occur, cldpix_tmp,
                         cldpix_tmp, cldpix_tmp, cldpix_tmp);
  emxDestroyArray_real32_T(water_occur);
  emxDestroy_ObjTOABT(data_toabt);
  emxDestroy_ObjMeta(data_meta);
}

/* End of code generation (main.c) */
