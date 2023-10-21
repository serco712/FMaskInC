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
                 const emxArray_boolean_T *psnow,
                 const emxArray_real32_T *gswater, emxArray_uint8_T *water,
                 emxArray_uint8_T *waterAll)
{
  emxArray_boolean_T *water_gs;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  emxArray_int32_T *r;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  double b_r;
  const float *NDVI_data;
  const float *gswater_data;
  const float *nir_data;
  int b_i;
  int firstBlockLength;
  int hi;
  int i;
  int k;
  int lastBlockLength;
  int loop_ub;
  int loop_ub_tmp;
  int nblocks;
  int q;
  int qEnd;
  int *idx_data;
  int *iwork_data;
  int *r1;
  int *r4;
  unsigned char *waterAll_data;
  unsigned char *water_data;
  const boolean_T *mask_data;
  const boolean_T *psnow_data;
  boolean_T *water_gs_data;
  gswater_data = gswater->data;
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
  i = water->size[0] * water->size[1];
  water->size[0] = (int)dim[0];
  water->size[1] = (int)dim[1];
  emxEnsureCapacity_uint8_T(water, i);
  water_data = water->data;
  q = (int)dim[0] * (int)dim[1];
  for (i = 0; i < q; i++) {
    water_data[i] = 0U;
  }
  /*  Water msk */
  /*     %% Zhe's water test (works over thin cloud) */
  emxInit_boolean_T(&water_gs, 2);
  if ((NDVI->size[0] == nir->size[0]) && (NDVI->size[1] == nir->size[1]) &&
      (NDVI->size[0] == nir->size[0]) && (NDVI->size[1] == nir->size[1])) {
    i = water_gs->size[0] * water_gs->size[1];
    water_gs->size[0] = NDVI->size[0];
    water_gs->size[1] = NDVI->size[1];
    emxEnsureCapacity_boolean_T(water_gs, i);
    water_gs_data = water_gs->data;
    loop_ub = NDVI->size[0] * NDVI->size[1];
    for (i = 0; i < loop_ub; i++) {
      water_gs_data[i] = (((NDVI_data[i] < 0.01) && (nir_data[i] < 1100.0F)) ||
                          ((NDVI_data[i] < 0.1) && (NDVI_data[i] > 0.0F) &&
                           (nir_data[i] < 500.0F)));
    }
  } else {
    binary_expand_op(water_gs, NDVI, nir);
    water_gs_data = water_gs->data;
  }
  nblocks = water_gs->size[0] * water_gs->size[1] - 1;
  for (b_i = 0; b_i <= nblocks; b_i++) {
    if (water_gs_data[b_i]) {
      water_data[b_i] = 1U;
    }
  }
  /*  within observation. */
  nblocks = mask->size[0] * mask->size[1] - 1;
  firstBlockLength = 0;
  for (b_i = 0; b_i <= nblocks; b_i++) {
    if (!mask_data[b_i]) {
      firstBlockLength++;
    }
  }
  emxInit_int32_T(&r);
  i = r->size[0];
  r->size[0] = firstBlockLength;
  emxEnsureCapacity_int32_T(r, i);
  r1 = r->data;
  firstBlockLength = 0;
  for (b_i = 0; b_i <= nblocks; b_i++) {
    if (!mask_data[b_i]) {
      r1[firstBlockLength] = b_i;
      firstBlockLength++;
    }
  }
  loop_ub_tmp = r->size[0] - 1;
  for (i = 0; i <= loop_ub_tmp; i++) {
    water_data[r1[i]] = 0U;
  }
  /*  do not exclude snow over water because clouds may be like snow and */
  /*  will be excluded ... */
  i = waterAll->size[0] * waterAll->size[1];
  waterAll->size[0] = water->size[0];
  waterAll->size[1] = water->size[1];
  emxEnsureCapacity_uint8_T(waterAll, i);
  waterAll_data = waterAll->data;
  for (i = 0; i < q; i++) {
    waterAll_data[i] = water_data[i];
  }
  /*     %% the GSWO data to enhance water map. */
  if (q == 0) {
    b_r = 0.0;
  } else {
    if (q <= 1024) {
      firstBlockLength = q;
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = (int)((unsigned int)q >> 10);
      lastBlockLength = q - (nblocks << 10);
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
    for (qEnd = 2; qEnd <= nblocks; qEnd++) {
      double bsum;
      firstBlockLength = (qEnd - 1) << 10;
      bsum = water_data[firstBlockLength];
      if (qEnd == nblocks) {
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
  emxInit_int32_T(&r2);
  emxInit_int32_T(&idx);
  emxInit_int32_T(&iwork);
  emxInit_int32_T(&r3);
  if ((b_r > 0.0) && ((gswater->size[0] != 0) && (gswater->size[1] != 0))) {
    float y;
    loop_ub = gswater->size[0] * gswater->size[1];
    if (loop_ub == 0) {
      y = 0.0F;
    } else {
      if (loop_ub <= 1024) {
        firstBlockLength = loop_ub;
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        firstBlockLength = 1024;
        nblocks = (int)((unsigned int)loop_ub >> 10);
        lastBlockLength = loop_ub - (nblocks << 10);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }
      y = gswater_data[0];
      for (k = 2; k <= firstBlockLength; k++) {
        y += gswater_data[k - 1];
      }
      for (qEnd = 2; qEnd <= nblocks; qEnd++) {
        float b_bsum;
        firstBlockLength = (qEnd - 1) << 10;
        b_bsum = gswater_data[firstBlockLength];
        if (qEnd == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }
        for (k = 2; k <= hi; k++) {
          b_bsum += gswater_data[(firstBlockLength + k) - 1];
        }
        y += b_bsum;
      }
    }
    if (y > 0.0F) {
      /*  have water occurences. */
      /*  assume the water occurances are same in each whole scene. */
      /*  global surface water occurance (GSWO) */
      /*  low level to exclude the commssion errors as water. */
      /*  5% tolerances. */
      nblocks = q - 1;
      firstBlockLength = 0;
      for (b_i = 0; b_i <= nblocks; b_i++) {
        if (water_data[b_i] == 1) {
          firstBlockLength++;
        }
      }
      i = r2->size[0];
      r2->size[0] = firstBlockLength;
      emxEnsureCapacity_int32_T(r2, i);
      r4 = r2->data;
      firstBlockLength = 0;
      for (b_i = 0; b_i <= nblocks; b_i++) {
        if (water_data[b_i] == 1) {
          r4[firstBlockLength] = b_i;
          firstBlockLength++;
        }
      }
      if (r2->size[0] == 0) {
        y = rtNaNF;
      } else {
        int n;
        n = r2->size[0] + 1;
        i = idx->size[0];
        idx->size[0] = r2->size[0];
        emxEnsureCapacity_int32_T(idx, i);
        idx_data = idx->data;
        firstBlockLength = r2->size[0];
        for (i = 0; i < firstBlockLength; i++) {
          idx_data[i] = 0;
        }
        i = iwork->size[0];
        iwork->size[0] = r2->size[0];
        emxEnsureCapacity_int32_T(iwork, i);
        iwork_data = iwork->data;
        i = r2->size[0] - 1;
        for (k = 1; k <= i; k += 2) {
          y = gswater_data[r4[k]];
          if ((gswater_data[r4[k - 1]] <= y) || rtIsNaNF(y)) {
            idx_data[k - 1] = k;
            idx_data[k] = k + 1;
          } else {
            idx_data[k - 1] = k + 1;
            idx_data[k] = k;
          }
        }
        if ((r2->size[0] & 1) != 0) {
          idx_data[r2->size[0] - 1] = r2->size[0];
        }
        b_i = 2;
        while (b_i < n - 1) {
          firstBlockLength = b_i << 1;
          hi = 1;
          for (nblocks = b_i + 1; nblocks < n; nblocks = qEnd + b_i) {
            int kEnd;
            lastBlockLength = hi;
            q = nblocks - 1;
            qEnd = hi + firstBlockLength;
            if (qEnd > n) {
              qEnd = n;
            }
            k = 0;
            kEnd = qEnd - hi;
            while (k + 1 <= kEnd) {
              y = gswater_data[r4[idx_data[q] - 1]];
              i = idx_data[lastBlockLength - 1];
              if ((gswater_data[r4[i - 1]] <= y) || rtIsNaNF(y)) {
                iwork_data[k] = i;
                lastBlockLength++;
                if (lastBlockLength == nblocks) {
                  while (q + 1 < qEnd) {
                    k++;
                    iwork_data[k] = idx_data[q];
                    q++;
                  }
                }
              } else {
                iwork_data[k] = idx_data[q];
                q++;
                if (q + 1 == qEnd) {
                  while (lastBlockLength < nblocks) {
                    k++;
                    iwork_data[k] = idx_data[lastBlockLength - 1];
                    lastBlockLength++;
                  }
                }
              }
              k++;
            }
            for (k = 0; k < kEnd; k++) {
              idx_data[(hi + k) - 1] = iwork_data[k];
            }
            hi = qEnd;
          }
          b_i = firstBlockLength;
        }
        firstBlockLength = r2->size[0];
        while ((firstBlockLength > 0) &&
               rtIsNaNF(gswater_data[r4[idx_data[firstBlockLength - 1] - 1]])) {
          firstBlockLength--;
        }
        if (firstBlockLength < 1) {
          y = rtNaNF;
        } else if (firstBlockLength == 1) {
          y = gswater_data[r4[idx_data[0] - 1]];
        } else {
          b_r = 0.175 * (double)firstBlockLength;
          b_i = (int)rt_roundd_snf(b_r);
          if (b_i < 1) {
            y = gswater_data[r4[idx_data[0] - 1]];
          } else if (b_i >= firstBlockLength) {
            y = gswater_data[r4[idx_data[firstBlockLength - 1] - 1]];
          } else {
            b_r -= (double)b_i;
            y = (float)(0.5 - b_r) * gswater_data[r4[idx_data[b_i - 1] - 1]] +
                (float)(b_r + 0.5) * gswater_data[r4[idx_data[b_i] - 1]];
          }
        }
      }
      if (y - 5.0F > 0.0F) {
        /*  must be more than 0. */
        i = water_gs->size[0] * water_gs->size[1];
        water_gs->size[0] = gswater->size[0];
        water_gs->size[1] = gswater->size[1];
        emxEnsureCapacity_boolean_T(water_gs, i);
        water_gs_data = water_gs->data;
        for (i = 0; i < loop_ub; i++) {
          water_gs_data[i] = (gswater_data[i] > y - 5.0F);
        }
        hi = loop_ub - 1;
        for (b_i = 0; b_i <= hi; b_i++) {
          if (gswater_data[b_i] > y - 5.0F) {
            waterAll_data[b_i] = 1U;
          }
        }
        /*  extend water regions based on GSWO, but do not exclude snow/ice */
        /*  sometimes ice may be over water. Snow covered sea ice is determined
         */
        /*  using the potential snow/ice. */
        nblocks = psnow->size[0] * psnow->size[1] - 1;
        firstBlockLength = 0;
        for (b_i = 0; b_i <= nblocks; b_i++) {
          if (psnow_data[b_i]) {
            firstBlockLength++;
          }
        }
        i = r3->size[0];
        r3->size[0] = firstBlockLength;
        emxEnsureCapacity_int32_T(r3, i);
        r4 = r3->data;
        firstBlockLength = 0;
        for (b_i = 0; b_i <= nblocks; b_i++) {
          if (psnow_data[b_i]) {
            r4[firstBlockLength] = b_i;
            firstBlockLength++;
          }
        }
        loop_ub = r3->size[0];
        for (i = 0; i < loop_ub; i++) {
          water_gs_data[r4[i]] = false;
        }
        /*  remove out ice water. */
        for (b_i = 0; b_i <= hi; b_i++) {
          if (water_gs_data[b_i]) {
            water_data[b_i] = 1U;
          }
        }
        /*  extend water regions based on GSWO.  */
        /*  equal to the theshold because it may be 100%. */
        /*              water(psnow)=0; % remove out ice water. I think this
         * snow */
        /*              cannot be removed because there are sometimes ice clouds
         * over */
        /*              water. */
        for (i = 0; i <= loop_ub_tmp; i++) {
          water_data[r1[i]] = 0U;
        }
        for (i = 0; i <= loop_ub_tmp; i++) {
          waterAll_data[r1[i]] = 0U;
        }
      }
    }
    /*  note that 255 indicates no data in GSWO, that is ocean pixels or */
    /*  permenate snow/ice pixels (which can be identified as land pixels). */
  }
  emxFree_int32_T(&r3);
  emxFree_int32_T(&iwork);
  emxFree_int32_T(&idx);
  emxFree_int32_T(&r);
  emxFree_int32_T(&r2);
  emxFree_boolean_T(&water_gs);
}

/* End of code generation (DetectWater.c) */
