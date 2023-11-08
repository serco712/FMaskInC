/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Fmask_terminate.c
 *
 * Code generation for function 'Fmask_terminate'
 *
 */

/* Include files */
#include "Fmask_terminate.h"
#include "Fmask_data.h"
#include "omp.h"

/* Function Definitions */
void Fmask_terminate(void)
{
  omp_destroy_nest_lock(&Fmask_nestLockGlobal);
  isInitialized_Fmask = false;
}

/* End of code generation (Fmask_terminate.c) */
