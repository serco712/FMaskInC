/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Fmask_initialize.c
 *
 * Code generation for function 'Fmask_initialize'
 *
 */

/* Include files */
#include "Fmask_initialize.h"
#include "CoderTimeAPI.h"
#include "Fmask_data.h"
#include "timeKeeper.h"
#include "omp.h"

/* Function Definitions */
void Fmask_initialize(void)
{
  omp_init_nest_lock(&Fmask_nestLockGlobal);
  c_CoderTimeAPI_callCoderClockGe();
  timeKeeper_init();
  isInitialized_Fmask = true;
}

/* End of code generation (Fmask_initialize.c) */
