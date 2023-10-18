/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ObservMask.c
 *
 * Code generation for function 'ObservMask'
 *
 */

/* Include files */
#include "ObservMask.h"
#include "emxutil.h"
#include "types.h"

/* Function Definitions */
void ObservMask(const emxArray_real32_T *band, emxArray_boolean_T *obs_mask)
{
  const float *band_data;
  int i;
  int loop_ub;
  boolean_T *obs_mask_data;
  band_data = band->data;
  /* MASK Create the mask of obervation using the overlap of all bands. */
  /*  */
  /*  Syntax */
  /*  */
  /*      obs_mask= ObservMask( band ) */
  /*  */
  /*  Description */
  /*  */
  /*      Create the mask of obervation using the overlap of all bands, which */
  /*      have been calculated in LoadData. */
  /*  History */
  /*  */
  /*      1. Create this function. (22. September, 2017)  */
  /*  */
  /*  Input arguments */
  /*  */
  /*      band     Blue band. */
  /*  */
  /*  Output arguments */
  /*  */
  /*      obs_mask      Observation mask(outside). */
  /*  */
  /*  See also: Loaddata */
  /*  */
  /*          */
  /*  Author:  Shi Qiu (shi.qiu@ttu.edu) */
  /*  Date: 22. September, 2017  */
  i = obs_mask->size[0] * obs_mask->size[1];
  obs_mask->size[0] = band->size[0];
  obs_mask->size[1] = band->size[1];
  emxEnsureCapacity_boolean_T(obs_mask, i);
  obs_mask_data = obs_mask->data;
  loop_ub = band->size[0] * band->size[1];
  for (i = 0; i < loop_ub; i++) {
    obs_mask_data[i] = (band_data[i] > -9999.0F);
  }
  /*   */
  /*      obs_mask=band~=0; */
  /*       */
  /*      %% simulate Sentinel 2 scene by 100 km x 100 km. */
  /*      % spatial resolution is 30 m for each pixel. That means there will be
   */
  /*      % 3333 x 3333 30m pixels should be selected expanding from the centre.
   */
  /*      s2_pixels=[3333 3333]; */
  /*      s2_pixels_half=round(s2_pixels./2); */
  /*      obs_dim=size(obs_mask); */
  /*      pixel_centre=round(obs_dim./2); */
  /*       */
  /*      s2_mask=obs_mask.*0; */
  /*      r_start=pixel_centre(1)-s2_pixels_half(1); */
  /*      r_end=pixel_centre(1)+s2_pixels_half(1); */
  /*      c_start=pixel_centre(2)-s2_pixels_half(2); */
  /*      c_end=pixel_centre(2)+s2_pixels_half(2); */
  /*      s2_mask(r_start:r_end,c_start:c_end)=1; */
  /*      obs_mask=s2_mask&obs_mask; */
}

/* End of code generation (ObservMask.c) */
