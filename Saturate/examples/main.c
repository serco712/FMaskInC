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
#include "Saturate.h"
#include "Saturate_emxAPI.h"
#include "Saturate_terminate.h"
#include "Saturate_types.h"

/* Function Declarations */
static boolean_T argInit_boolean_T(void);

static emxArray_boolean_T *c_argInit_UnboundedxUnbounded_b(void);

/* Function Definitions */
static boolean_T argInit_boolean_T(void)
{
  return false;
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

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_Saturate();
  /* Terminate the application.
You do not need to do this more than one time. */
  Saturate_terminate();
  return 0;
}

void main_Saturate(void)
{
  emxArray_boolean_T *satu_Bv;
  emxArray_boolean_T *satu_blue;
  emxArray_boolean_T *satu_green;
  emxArray_boolean_T *satu_red;
  /* Initialize function 'Saturate' input arguments. */
  /* Initialize function input argument 'satu_blue'. */
  satu_blue = c_argInit_UnboundedxUnbounded_b();
  /* Initialize function input argument 'satu_green'. */
  satu_green = c_argInit_UnboundedxUnbounded_b();
  /* Initialize function input argument 'satu_red'. */
  satu_red = c_argInit_UnboundedxUnbounded_b();
  /* Call the entry-point 'Saturate'. */
  emxInitArray_boolean_T(&satu_Bv, 2);
  Saturate(satu_blue, satu_green, satu_red, satu_Bv);
  emxDestroyArray_boolean_T(satu_red);
  emxDestroyArray_boolean_T(satu_green);
  emxDestroyArray_boolean_T(satu_blue);
  emxDestroyArray_boolean_T(satu_Bv);
}

/* End of code generation (main.c) */
