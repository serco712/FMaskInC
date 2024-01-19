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

#include <stdio.h>

const double azi = 101.8895;
const double bbox[] = {41.3405, 39.3738, -5.2319, -2.296};
const double doy = 173;
const double Lnum = 7;
const double reso_ref[2] = {30, 30};
const double reso_thm[2] = {30, 30};
const double ul[] = {313200, 4576800};
const double zc[] = {30, 30};
const double zen = 39.7293;
const double ijdim_ref[2] = {10, 10};
const double ijdim_thm[2] = {10, 10};
const double Lmax[9] = {293.7, 300.9, 234.4, 241.1, 47.57, 17.04, 16.54, 0, 0};
const double Lmin[9] = {-6.2, -6.4, -5, -5.1, -1, 0, -0.35, 0, 0};
const double Qcalmax[9] = {255, 255, 255, 255, 255, 255, 255, 0, 0};
const double Qcalmin[9] = {1, 1, 1, 1, 1, 1, 1, 0, 0};
const double Refmax[7] = {0, 0, 0, 0, 0, 0, 0};
const double Refmin[7] = {0, 0, 0, 0, 0, 0, 0};

const char name[] = "LE07_L1TP_201032_20220622_20220719_02_T1";
const char sensor[] = "L_ETM_PLUS";
const float dim[] = {10, 10};

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */


  //uartInit();

  main_Fmask();
  return 0;
}

void main_Fmask(void)
{ 
  double cld_pct;
  /* Initialize function 'Fmask' input arguments. */
  /* Call the entry-point 'Fmask'. */

  cld_pct = Fmask(3, 3, 3, 22.5, Lnum, Lmax, Lmin, Qcalmax, Qcalmin, Refmax, Refmin, ijdim_ref, ijdim_thm,
          reso_ref, reso_thm, ul, zen, azi, zc, Lnum, doy);

  printf("Porcentaje de claridad es %.2f%%\n",cld_pct);
}

/* End of code generation (main.c) */
