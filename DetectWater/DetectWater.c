/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DetectWater.c
 *
 * Code generation for function 'DetectWater'
 *
 */

/* Include files */
#include "DetectWater.h"
#include "DetectWater_emxutil.h"
#include "DetectWater_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void binary_expand_op(emxArray_boolean_T *in1,
                             const emxArray_real32_T *in2,
                             const emxArray_real32_T *in3);

static double rt_roundd_snf(double u);

/* Function Definitions */
static void binary_expand_op(emxArray_boolean_T *in1,
                             const emxArray_real32_T *in2,
                             const emxArray_real32_T *in3)
{
  const float *in2_data;
  const float *in3_data;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1_tmp;
  int aux_3_1_tmp;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0_tmp;
  int stride_0_1_tmp;
  int stride_1_0_tmp;
  int stride_1_1_tmp;
  boolean_T *in1_data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  if (in3->size[1] == 1) {
    b_loop_ub = in2->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  stride_0_0_tmp = (in2->size[0] != 1);
  stride_0_1_tmp = (in2->size[1] != 1);
  stride_1_0_tmp = (in3->size[0] != 1);
  stride_1_1_tmp = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1_tmp = 0;
  aux_3_1_tmp = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      float f;
      float f1;
      f = in2_data[i1 * stride_0_0_tmp + in2->size[0] * aux_0_1];
      f1 = in3_data[i1 * stride_1_0_tmp + in3->size[0] * aux_1_1];
      in1_data[i1 + in1->size[0] * i] =
          (((f < 0.01) && (f1 < 1100.0F)) ||
           ((f < 0.1) && (f > 0.0F) && (f1 < 500.0F)));
    }
    aux_3_1_tmp += stride_1_1_tmp;
    aux_2_1_tmp += stride_0_1_tmp;
    aux_1_1 = aux_3_1_tmp;
    aux_0_1 = aux_2_1_tmp;
  }
}

static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

void DetectWater(const double dim[2], const emxArray_boolean_T *mask,
                 const emxArray_real32_T *nir, const emxArray_real32_T *NDVI,
                 const emxArray_boolean_T *psnow, double slope, double gswater,
                 emxArray_uint8_T *water, emxArray_uint8_T *waterAll)
{
  emxArray_boolean_T *r;
  emxArray_int32_T *r2;
  double b_r;
  const float *NDVI_data;
  const float *nir_data;
  int b_loop_ub_tmp;
  int firstBlockLength;
  int hi;
  int ib;
  int k;
  int loop_ub_tmp;
  int nblocks;
  int *r3;
  unsigned char *waterAll_data;
  unsigned char *water_data;
  const boolean_T *mask_data;
  const boolean_T *psnow_data;
  boolean_T *r1;
  (void)slope;
  psnow_data = psnow->data;
  NDVI_data = NDVI->data;
  nir_data = nir->data;
  mask_data = mask->data;
  /* DETECTWATER Detect water by combining spectral-derived water and */
  /* GSWO-derived water togeter. */
  /*  */
  /*  Syntax */
  /*  */
  /*      water = DetectWater( dim, mask, nir, NDVI, psnow, slope, gswater) */
  /*  */
  /*  Description */
  /*  */
  /*      History: */
  /*      1. Create this function. (1. January, 2018) */
  /*      2. The sepctral-derived water may be incorrect, resulting in a 100% */
  /*      absolutely wrong low level GSWO (equal to 0). The GWSO will be used */
  /*      only when the low level GSWO is larger than 0. (9. March, 2018) */
  /*      3. Remove the coastline because of its frequent changes.  (6. May,
   * 2018) */
  /*      4. Add a water layer which does not snoe/ice because some clouds may
   */
  /*      be like snoe/ice. This will be used to exclude processing of cloud */
  /*      shadow over water. (17. March, 2020) */
  /*  */
  /*  Input arguments */
  /*  */
  /*      dim            Dim for data. */
  /*      mask           Mask for observations. */
  /*      nir            NIR. */
  /*      NDVI           NDVI. */
  /*      psnow          Potential snow. */
  /*      slope          Slope. */
  /*      gswater        GSWO. */
  /*  */
  /*  Output arguments */
  /*  */
  /*      water          Water map. */
  /*  */
  /*          */
  /*  Author:  Shi Qiu (shi.qiu@uconn.edu) */
  /*  Date: 17. March, 2020 */
  nblocks = water->size[0] * water->size[1];
  water->size[0] = (int)dim[0];
  water->size[1] = (int)dim[1];
  emxEnsureCapacity_uint8_T(water, nblocks);
  water_data = water->data;
  loop_ub_tmp = (int)dim[0] * (int)dim[1];
  for (nblocks = 0; nblocks < loop_ub_tmp; nblocks++) {
    water_data[nblocks] = 0U;
  }
  /*  Water msk */
  /*     %% Zhe's water test (works over thin cloud) */
  emxInit_boolean_T(&r, 2);
  if ((NDVI->size[0] == nir->size[0]) && (NDVI->size[1] == nir->size[1]) &&
      (NDVI->size[0] == nir->size[0]) && (NDVI->size[1] == nir->size[1])) {
    nblocks = r->size[0] * r->size[1];
    r->size[0] = NDVI->size[0];
    r->size[1] = NDVI->size[1];
    emxEnsureCapacity_boolean_T(r, nblocks);
    r1 = r->data;
    firstBlockLength = NDVI->size[0] * NDVI->size[1];
    for (nblocks = 0; nblocks < firstBlockLength; nblocks++) {
      r1[nblocks] =
          (((NDVI_data[nblocks] < 0.01) && (nir_data[nblocks] < 1100.0F)) ||
           ((NDVI_data[nblocks] < 0.1) && (NDVI_data[nblocks] > 0.0F) &&
            (nir_data[nblocks] < 500.0F)));
    }
  } else {
    binary_expand_op(r, NDVI, nir);
    r1 = r->data;
  }
  hi = r->size[0] * r->size[1] - 1;
  for (nblocks = 0; nblocks <= hi; nblocks++) {
    if (r1[nblocks]) {
      water_data[nblocks] = 1U;
    }
  }
  emxFree_boolean_T(&r);
  /*  within observation. */
  hi = mask->size[0] * mask->size[1] - 1;
  firstBlockLength = 0;
  for (nblocks = 0; nblocks <= hi; nblocks++) {
    if (!mask_data[nblocks]) {
      firstBlockLength++;
    }
  }
  emxInit_int32_T(&r2);
  nblocks = r2->size[0];
  r2->size[0] = firstBlockLength;
  emxEnsureCapacity_int32_T(r2, nblocks);
  r3 = r2->data;
  firstBlockLength = 0;
  for (nblocks = 0; nblocks <= hi; nblocks++) {
    if (!mask_data[nblocks]) {
      r3[firstBlockLength] = nblocks;
      firstBlockLength++;
    }
  }
  b_loop_ub_tmp = r2->size[0] - 1;
  for (nblocks = 0; nblocks <= b_loop_ub_tmp; nblocks++) {
    water_data[r3[nblocks]] = 0U;
  }
  /*  do not exclude snow over water because clouds may be like snow and */
  /*  will be excluded ... */
  nblocks = waterAll->size[0] * waterAll->size[1];
  waterAll->size[0] = water->size[0];
  waterAll->size[1] = water->size[1];
  emxEnsureCapacity_uint8_T(waterAll, nblocks);
  waterAll_data = waterAll->data;
  for (nblocks = 0; nblocks < loop_ub_tmp; nblocks++) {
    waterAll_data[nblocks] = water_data[nblocks];
  }
  /*     %% the GSWO data to enhance water map. */
  if (loop_ub_tmp == 0) {
    b_r = 0.0;
  } else {
    int lastBlockLength;
    if (loop_ub_tmp <= 1024) {
      firstBlockLength = loop_ub_tmp;
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = (int)((unsigned int)loop_ub_tmp >> 10);
      lastBlockLength = loop_ub_tmp - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    b_r = water_data[0];
    for (k = 2; k <= firstBlockLength; k++) {
      b_r += (double)water_data[k - 1];
    }
    for (ib = 2; ib <= nblocks; ib++) {
      double bsum;
      firstBlockLength = (ib - 1) << 10;
      bsum = water_data[firstBlockLength];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        bsum += (double)water_data[(firstBlockLength + k) - 1];
      }
      b_r += bsum;
    }
  }
  if (b_r > 0.0) {
    if (gswater > 0.0) {
      /*  have water occurences. */
      /*  assume the water occurances are same in each whole scene. */
      /*  global surface water occurance (GSWO) */
      /*  low level to exclude the commssion errors as water. */
      /*  5% tolerances. */
      hi = loop_ub_tmp - 1;
      firstBlockLength = 0;
      for (nblocks = 0; nblocks <= hi; nblocks++) {
        if (water_data[nblocks] == 1) {
          firstBlockLength++;
        }
      }
      if (firstBlockLength == 0) {
        b_r = rtNaN;
      } else {
        firstBlockLength = 0;
        for (nblocks = 0; nblocks <= hi; nblocks++) {
          if (water_data[nblocks] == 1) {
            firstBlockLength++;
          }
        }
        while ((firstBlockLength > 0) && rtIsNaN(gswater)) {
          firstBlockLength--;
        }
        if (firstBlockLength < 1) {
          b_r = rtNaN;
        } else if (firstBlockLength == 1) {
          b_r = gswater;
        } else {
          b_r = 0.175 * (double)firstBlockLength;
          nblocks = (int)rt_roundd_snf(b_r);
          if (nblocks < 1) {
            b_r = gswater;
          } else if (nblocks >= firstBlockLength) {
            b_r = gswater;
          } else {
            b_r -= (double)nblocks;
            b_r = (0.5 - b_r) * gswater + (b_r + 0.5) * gswater;
          }
        }
      }
      if (b_r - 5.0 > 0.0) {
        boolean_T b;
        /*  must be more than 0. */
        if (gswater > b_r - 5.0) {
          waterAll_data[0] = 1U;
        }
        /*  extend water regions based on GSWO, but do not exclude snow/ice */
        /*  sometimes ice may be over water. Snow covered sea ice is determined
         */
        /*  using the potential snow/ice. */
        b = (gswater > b_r - 5.0);
        hi = psnow->size[0] * psnow->size[1] - 1;
        for (nblocks = 0; nblocks <= hi; nblocks++) {
          b = ((!psnow_data[nblocks]) && b);
        }
        /*  remove out ice water. */
        if (b) {
          water_data[0] = 1U;
        }
        /*  extend water regions based on GSWO.  */
        /*  equal to the theshold because it may be 100%. */
        /*              water(psnow)=0; % remove out ice water. I think this
         * snow */
        /*              cannot be removed because there are sometimes ice clouds
         * over */
        /*              water. */
        for (nblocks = 0; nblocks <= b_loop_ub_tmp; nblocks++) {
          water_data[r3[nblocks]] = 0U;
        }
        for (nblocks = 0; nblocks <= b_loop_ub_tmp; nblocks++) {
          waterAll_data[r3[nblocks]] = 0U;
        }
      }
    }
    /*  note that 255 indicates no data in GSWO, that is ocean pixels or */
    /*  permenate snow/ice pixels (which can be identified as land pixels). */
  }
  emxFree_int32_T(&r2);
}

/* End of code generation (DetectWater.c) */
