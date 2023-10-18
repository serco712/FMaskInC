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
#include "DetectPotentialCloud.h"
#include "DetectPotentialCloud_emxAPI.h"
#include "DetectPotentialCloud_terminate.h"
#include "DetectPotentialCloud_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);

static emxArray_char_T *argInit_1xUnbounded_char_T(void);

static void argInit_2x2_real_T(double result[4]);

static GRIDobj argInit_GRIDobj(void);

static void argInit_ObjMeta(ObjMeta *result);

static void argInit_ObjTOABT(ObjTOABT *result);

static boolean_T argInit_boolean_T(void);

static char argInit_char_T(void);

static float argInit_real32_T(void);

static double argInit_real_T(void);

static unsigned char argInit_uint8_T(void);

static emxArray_boolean_T *c_argInit_UnboundedxUnbounded_b(void);

static emxArray_real32_T *c_argInit_UnboundedxUnbounded_r(void);

static emxArray_uint8_T *c_argInit_UnboundedxUnbounded_u(void);

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

static GRIDobj argInit_GRIDobj(void)
{
  GRIDobj result;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result.Z = c_argInit_UnboundedxUnbounded_r();
  return result;
}

static void argInit_ObjMeta(ObjMeta *result)
{
  double result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_1x2_real_T(result->Dim);
  result_tmp = argInit_real_T();
  result->Azi = result_tmp;
  result->Name = argInit_1xUnbounded_char_T();
  result->Sensor = argInit_1xUnbounded_char_T();
  argInit_2x2_real_T(result->Resolution);
  result->Zen = result_tmp;
  argInit_1x2_real_T(result->ZC);
  argInit_2x2_real_T(result->BBox);
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

static unsigned char argInit_uint8_T(void)
{
  return 0U;
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

static emxArray_uint8_T *c_argInit_UnboundedxUnbounded_u(void)
{
  emxArray_uint8_T *result;
  int idx0;
  int idx1;
  unsigned char *result_data;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_uint8_T(2, 2);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result_data[idx0 + result->size[0] * idx1] = argInit_uint8_T();
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
  main_DetectPotentialCloud();
  /* Terminate the application.
You do not need to do this more than one time. */
  DetectPotentialCloud_terminate();
  return 0;
}

void main_DetectPotentialCloud(void)
{
  GRIDobj dem;
  ObjMeta data_meta;
  ObjTOABT data_toabt;
  emxArray_boolean_T *idplcd;
  emxArray_boolean_T *idused;
  emxArray_boolean_T *mask;
  emxArray_real32_T *HOT;
  emxArray_real32_T *cldprob;
  emxArray_real32_T *ndbi;
  emxArray_real32_T *ndsi;
  emxArray_real32_T *ndvi;
  emxArray_real32_T *whiteness;
  emxArray_real32_T *wpt;
  emxArray_uint8_T *cloud;
  emxArray_uint8_T *water;
  double sum_clr;
  float t_temph;
  float t_templ;
  /* Initialize function 'DetectPotentialCloud' input arguments. */
  /* Initialize function input argument 'data_meta'. */
  argInit_ObjMeta(&data_meta);
  /* Initialize function input argument 'mask'. */
  mask = c_argInit_UnboundedxUnbounded_b();
  /* Initialize function input argument 'water'. */
  water = c_argInit_UnboundedxUnbounded_u();
  /* Initialize function input argument 'data_toabt'. */
  argInit_ObjTOABT(&data_toabt);
  /* Initialize function input argument 'dem'. */
  dem = argInit_GRIDobj();
  /* Initialize function input argument 'ndvi'. */
  ndvi = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'ndsi'. */
  ndsi = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'ndbi'. */
  ndbi = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'idplcd'. */
  idplcd = c_argInit_UnboundedxUnbounded_b();
  /* Initialize function input argument 'whiteness'. */
  whiteness = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'HOT'. */
  HOT = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'wpt'. */
  wpt = c_argInit_UnboundedxUnbounded_r();
  /* Initialize function input argument 'cldprob'. */
  cldprob = c_argInit_UnboundedxUnbounded_r();
  /* Call the entry-point 'DetectPotentialCloud'. */
  emxInitArray_uint8_T(&cloud, 2);
  emxInitArray_boolean_T(&idused, 2);
  DetectPotentialCloud(&data_meta, mask, water, &data_toabt, &dem, ndvi, ndsi,
                       ndbi, idplcd, whiteness, HOT, wpt, cldprob, &sum_clr,
                       cloud, idused, &t_templ, &t_temph);
  emxDestroyArray_real32_T(cldprob);
  emxDestroyArray_real32_T(wpt);
  emxDestroyArray_real32_T(HOT);
  emxDestroyArray_real32_T(whiteness);
  emxDestroyArray_boolean_T(idplcd);
  emxDestroyArray_real32_T(ndbi);
  emxDestroyArray_real32_T(ndsi);
  emxDestroyArray_real32_T(ndvi);
  emxDestroy_GRIDobj(dem);
  emxDestroy_ObjTOABT(data_toabt);
  emxDestroyArray_uint8_T(water);
  emxDestroyArray_boolean_T(mask);
  emxDestroy_ObjMeta(data_meta);
  emxDestroyArray_uint8_T(cloud);
  emxDestroyArray_boolean_T(idused);
}

/* End of code generation (main.c) */
