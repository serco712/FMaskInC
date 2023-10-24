/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DetectAbsSnow.c
 *
 * Code generation for function 'DetectAbsSnow'
 *
 */

/* Include files */
#include "DetectAbsSnow.h"
#include "autoFmask_emxutil.h"
#include "autoFmask_rtwutil.h"
#include "autoFmask_types.h"
#include "imfilter.h"
#include "integralBoxFilter.h"
#include "integralImage.h"
#include "padarray.h"
#include "permute.h"
#include "unsafeSxfun.h"
#include <math.h>

/* Function Declarations */
static void binary_expand_op_21(emxArray_real32_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real32_T *in3, int in4, int in5);

static void binary_expand_op_24(emxArray_boolean_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_boolean_T *in3,
                                const emxArray_boolean_T *in4);

/* Function Definitions */
static void binary_expand_op_21(emxArray_real32_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real32_T *in3, int in4, int in5)
{
  const double *in2_data;
  const float *in3_data;
  float *in1_data;
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  in3_data = in3->data;
  in2_data = in2->data;
  i = (in5 - in4) + 1;
  if (i == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = i;
  }
  i1 = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(in1, i1);
  if (in3->size[1] == 1) {
    b_loop_ub = in2->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  i1 = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(in1, i1);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (i != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          (float)in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] *
          (1.0F - in3_data[(in4 + i1 * stride_1_0) + in3->size[0] * aux_1_1]);
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void binary_expand_op_24(emxArray_boolean_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_boolean_T *in3,
                                const emxArray_boolean_T *in4)
{
  const double *in2_data;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  int stride_2_0;
  int stride_2_1;
  const boolean_T *in3_data;
  const boolean_T *in4_data;
  boolean_T *in1_data;
  in4_data = in4->data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in4->size[0] == 1) {
    if (in3->size[0] == 1) {
      loop_ub = in2->size[0];
    } else {
      loop_ub = in3->size[0];
    }
  } else {
    loop_ub = in4->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  if (in4->size[1] == 1) {
    if (in3->size[1] == 1) {
      b_loop_ub = in2->size[1];
    } else {
      b_loop_ub = in3->size[1];
    }
  } else {
    b_loop_ub = in4->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  stride_2_0 = (in4->size[0] != 1);
  stride_2_1 = (in4->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          ((in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] < 9.0) &&
           in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1] &&
           (!in4_data[i1 * stride_2_0 + in4->size[0] * aux_2_1]));
    }
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

void DetectAbsSnow(const emxArray_real32_T *band_green,
                   const emxArray_boolean_T *band_green_statu,
                   const emxArray_real32_T *ndsi,
                   const emxArray_boolean_T *psnow, double resolution,
                   emxArray_boolean_T *abs_snow)
{
  emxArray_real32_T *B2;
  emxArray_real32_T *B3;
  emxArray_real32_T *r;
  emxArray_real_T *b_I;
  emxArray_real_T *b_h;
  emxArray_real_T *conv1;
  emxArray_real_T *h;
  emxArray_real_T *intI;
  emxArray_real_T *scsi;
  double *I_data;
  double *conv1_data;
  double *h_data;
  double *scsi_data;
  const float *ndsi_data;
  float *B2_data;
  float *B3_data;
  int i1;
  int i_row;
  int ib;
  int k;
  int lastBlockLength;
  int ncolsB;
  int nz;
  const boolean_T *band_green_statu_data;
  const boolean_T *psnow_data;
  boolean_T *abs_snow_data;
  psnow_data = psnow->data;
  ndsi_data = ndsi->data;
  band_green_statu_data = band_green_statu->data;
  /* DETECTABSSNOW Select absolute snow/ice pixels using spectral-contextual */
  /*      features. */
  /*  */
  /*  Syntax */
  /*  */
  /*      abs_snow = */
  /*      DetectAbsSnow(band_green,band_green_statu,ndsi,psnow,resolution) */
  /*  */
  /*  Description */
  /*  */
  /*      A spectral-contextual snow index (SCSI) is used to select 100% */
  /*      snow/ice pixels. SCSI10 is computed here, of which 10 indicates 10 */
  /*      kilometers-by-10 kilometers window size, that 333-by-333 pixels for */
  /*      Landsat 30 meters image and 501-by-501 pixels for Sentinel-2 20 */
  /*      meters image (Fmask runs at this 20 meters). That window size is */
  /*      large enough to capture the various contexts for clouds, but still */
  /*      give us soomth variations for pure snow/ice. */
  /*  */
  /*  Input arguments */
  /*  */
  /*      band_green           Green band. */
  /*      band_green_statu     Statured pixels at green band. */
  /*      psnow                Potential snow/ice. */
  /*      resolution           Spatial resolution of input image. */
  /*  */
  /*  Output arguments */
  /*  */
  /*      abs_snow             Absolute snow/ice. */
  /*  */
  /*  Example */
  /*  */
  /*      abs_snow = */
  /*      DetectAbsSnow(band_green,band_green_statu,ndsi,psnow,resolution) */
  /*  */
  /*          */
  /*  Author:  Shi Qiu (shi.qiu@uconn.edu) */
  /*  Date: 21. January, 2018 */
  /*  which is equal to 51*51 % when have snow/ice pixels. */
  ncolsB = psnow->size[0] * psnow->size[1];
  if (ncolsB == 0) {
    nz = 0;
  } else {
    nz = psnow_data[0];
    for (k = 2; k <= ncolsB; k++) {
      nz += psnow_data[k - 1];
    }
  }
  if (nz > 110889) {
    double radius;
    double win_size;
    int row_nums[5];
    int b_loop_ub_tmp;
    int i;
    int loop_ub;
    int loop_ub_tmp;
    int num_per_row;
    int size_row;
    /*  sometimes Nan will appear in this green band. */
    emxInit_real32_T(&B2, 2);
    permute(band_green, B2);
    B2_data = B2->data;
    ncolsB = B2->size[1];
    emxInit_real32_T(&r, 1);
    for (nz = 0; nz < ncolsB; nz++) {
      loop_ub = B2->size[0];
      ib = r->size[0];
      r->size[0] = B2->size[0];
      emxEnsureCapacity_real32_T(r, ib);
      B3_data = r->data;
      for (ib = 0; ib < loop_ub; ib++) {
        B3_data[ib] = B2_data[ib + B2->size[0] * nz];
      }
      loop_ub = r->size[0];
      for (ib = 0; ib < loop_ub; ib++) {
        B2_data[ib + B2->size[0] * nz] = B3_data[ib];
      }
    }
    emxFree_real32_T(&r);
    emxInit_real32_T(&B3, 2);
    permute(B2, B3);
    B3_data = B3->data;
    /*  window size is 10 km. */
    radius = trunc(5000.0 / resolution);
    win_size = 2.0 * radius + 1.0;
    /*  compute SCSI. */
    /*  clip to small arrays (16 smalls); */
    /*  5 cippes */
    size_row = B3->size[0];
    num_per_row = (int)rt_roundd((double)B3->size[0] / 5.0);
    row_nums[0] = num_per_row;
    row_nums[1] = num_per_row;
    row_nums[2] = num_per_row;
    row_nums[3] = num_per_row;
    /*  the last one */
    row_nums[4] = B3->size[0] - (num_per_row << 2);
    emxInit_real_T(&scsi, 2);
    ib = scsi->size[0] * scsi->size[1];
    scsi->size[0] = B3->size[0];
    scsi->size[1] = B3->size[1];
    emxEnsureCapacity_real_T(scsi, ib);
    scsi_data = scsi->data;
    loop_ub_tmp = B3->size[0] * B3->size[1];
    for (ib = 0; ib < loop_ub_tmp; ib++) {
      scsi_data[ib] = 0.0;
    }
    /*  the first clip */
    b_loop_ub_tmp = (int)win_size * (int)win_size;
    loop_ub = B3->size[1];
    emxInit_real_T(&h, 2);
    emxInit_real_T(&b_I, 2);
    emxInit_real_T(&conv1, 2);
    emxInit_real_T(&intI, 2);
    emxInit_real_T(&b_h, 2);
    for (i_row = 0; i_row < 5; i_row++) {
      double row_ed;
      double row_ed_exp;
      double row_ed_small;
      double row_st;
      double row_st_exp;
      double row_st_small;
      int b_loop_ub;
      nz = i_row + 1;
      row_ed = num_per_row;
      for (k = 2; k <= nz; k++) {
        row_ed += (double)row_nums[k - 1];
      }
      nz = row_nums[i_row];
      row_st = (row_ed - (double)nz) + 1.0;
      row_st_exp = row_st - radius;
      row_ed_exp = row_ed + radius;
      row_st_small = radius + 1.0;
      row_ed_small = radius + (double)nz;
      /*  the first clip */
      if (row_st_exp < 1.0) {
        row_st_exp = 1.0;
        row_st_small = 1.0;
        row_ed_small = nz;
        /*  no the first exp */
      }
      /*  the last clip */
      if (row_ed_exp > size_row) {
        row_ed_exp = size_row;
        /*                  row_ed_small = radius + row_nums(i_row); */
      }
      if (row_st_exp > row_ed_exp) {
        ib = 0;
        ncolsB = 0;
        i = 0;
        i1 = 0;
      } else {
        ib = (int)row_st_exp - 1;
        ncolsB = (int)row_ed_exp;
        i = (int)row_st_exp - 1;
        i1 = (int)row_ed_exp;
      }
      lastBlockLength = h->size[0] * h->size[1];
      h->size[0] = (int)win_size;
      h->size[1] = (int)win_size;
      emxEnsureCapacity_real_T(h, lastBlockLength);
      h_data = h->data;
      for (lastBlockLength = 0; lastBlockLength < b_loop_ub_tmp;
           lastBlockLength++) {
        h_data[lastBlockLength] = 1.0;
      }
      b_loop_ub = ncolsB - ib;
      ncolsB = b_I->size[0] * b_I->size[1];
      b_I->size[0] = b_loop_ub;
      b_I->size[1] = B3->size[1];
      emxEnsureCapacity_real_T(b_I, ncolsB);
      I_data = b_I->data;
      for (ncolsB = 0; ncolsB < loop_ub; ncolsB++) {
        for (lastBlockLength = 0; lastBlockLength < b_loop_ub;
             lastBlockLength++) {
          I_data[lastBlockLength + b_I->size[0] * ncolsB] =
              B3_data[(ib + lastBlockLength) + B3->size[0] * ncolsB];
        }
      }
      row_ed_exp = (double)h->size[0] * (double)h->size[0];
      if (row_ed_exp > 250.0) {
        double b_hsize[2];
        double hsize[2];
        hsize[0] = h->size[0];
        hsize[1] = h->size[0];
        row_st_exp = ((double)h->size[0] - 1.0) / 2.0;
        b_hsize[0] = row_st_exp;
        b_hsize[1] = row_st_exp;
        ib = h->size[0] * h->size[1];
        h->size[0] = b_I->size[0];
        h->size[1] = b_I->size[1];
        emxEnsureCapacity_real_T(h, ib);
        h_data = h->data;
        nz = b_I->size[0] * b_I->size[1] - 1;
        for (ib = 0; ib <= nz; ib++) {
          h_data[ib] = I_data[ib];
        }
        padarray(h, b_hsize, b_I);
        I_data = b_I->data;
        integralImage(b_I, intI);
        ib = b_h->size[0] * b_h->size[1];
        b_h->size[0] = b_I->size[0];
        b_h->size[1] = b_I->size[1];
        emxEnsureCapacity_real_T(b_h, ib);
        h_data = b_h->data;
        nz = b_I->size[0] * b_I->size[1];
        for (ib = 0; ib < nz; ib++) {
          row_st_exp = I_data[ib];
          h_data[ib] = row_st_exp * row_st_exp;
        }
        integralImage(b_h, h);
        integralBoxFilter(h, hsize, 1.0 / (row_ed_exp - 1.0), conv1);
        conv1_data = conv1->data;
        integralBoxFilter(intI, hsize,
                          1.0 / sqrt(row_ed_exp * (row_ed_exp - 1.0)), h);
        if ((conv1->size[0] == h->size[0]) && (conv1->size[1] == h->size[1])) {
          nz = conv1->size[0] * conv1->size[1];
          ib = h->size[0] * h->size[1];
          h->size[0] = conv1->size[0];
          h->size[1] = conv1->size[1];
          emxEnsureCapacity_real_T(h, ib);
          h_data = h->data;
          for (ib = 0; ib < nz; ib++) {
            row_st_exp = h_data[ib];
            row_st_exp = conv1_data[ib] - row_st_exp * row_st_exp;
            h_data[ib] = fmax(row_st_exp, 0.0);
          }
        } else {
          binary_expand_op_22(h, conv1);
          h_data = h->data;
        }
        nz = h->size[0] * h->size[1];
        for (k = 0; k < nz; k++) {
          h_data[k] = sqrt(h_data[k]);
        }
      } else {
        if (b_loop_ub_tmp == 0) {
          row_ed_exp = 0.0;
        } else {
          if (b_loop_ub_tmp <= 1024) {
            nz = b_loop_ub_tmp;
            lastBlockLength = 0;
            ncolsB = 1;
          } else {
            nz = 1024;
            ncolsB = (int)((unsigned int)b_loop_ub_tmp >> 10);
            lastBlockLength = b_loop_ub_tmp - (ncolsB << 10);
            if (lastBlockLength > 0) {
              ncolsB++;
            } else {
              lastBlockLength = 1024;
            }
          }
          row_ed_exp = 1.0;
          for (k = 2; k <= nz; k++) {
            row_ed_exp++;
          }
          for (ib = 2; ib <= ncolsB; ib++) {
            row_st_exp = 1.0;
            if (ib == ncolsB) {
              nz = lastBlockLength;
            } else {
              nz = 1024;
            }
            for (k = 2; k <= nz; k++) {
              row_st_exp++;
            }
            row_ed_exp += row_st_exp;
          }
        }
        if (row_ed_exp != 1.0) {
          ib = conv1->size[0] * conv1->size[1];
          conv1->size[0] = b_I->size[0];
          conv1->size[1] = b_I->size[1];
          emxEnsureCapacity_real_T(conv1, ib);
          conv1_data = conv1->data;
          nz = b_I->size[0] * b_I->size[1];
          for (ib = 0; ib < nz; ib++) {
            row_st_exp = I_data[ib];
            conv1_data[ib] = row_st_exp * row_st_exp;
          }
          ib = b_h->size[0] * b_h->size[1];
          b_h->size[0] = h->size[0];
          b_h->size[1] = h->size[1];
          emxEnsureCapacity_real_T(b_h, ib);
          h_data = b_h->data;
          for (ib = 0; ib < b_loop_ub_tmp; ib++) {
            h_data[ib] = 1.0 / (row_ed_exp - 1.0);
          }
          imfilter(conv1, b_h);
          conv1_data = conv1->data;
          row_st_exp = sqrt(row_ed_exp * (row_ed_exp - 1.0));
          ib = b_h->size[0] * b_h->size[1];
          b_h->size[0] = h->size[0];
          b_h->size[1] = h->size[1];
          emxEnsureCapacity_real_T(b_h, ib);
          h_data = b_h->data;
          for (ib = 0; ib < b_loop_ub_tmp; ib++) {
            h_data[ib] = 1.0 / row_st_exp;
          }
          imfilter(b_I, b_h);
          I_data = b_I->data;
          if ((conv1->size[0] == b_I->size[0]) &&
              (conv1->size[1] == b_I->size[1])) {
            ib = h->size[0] * h->size[1];
            h->size[0] = conv1->size[0];
            h->size[1] = conv1->size[1];
            emxEnsureCapacity_real_T(h, ib);
            h_data = h->data;
            nz = conv1->size[0] * conv1->size[1];
            for (ib = 0; ib < nz; ib++) {
              row_st_exp = I_data[ib];
              row_st_exp = conv1_data[ib] - row_st_exp * row_st_exp;
              h_data[ib] = fmax(row_st_exp, 0.0);
            }
          } else {
            binary_expand_op_23(h, conv1, b_I);
            h_data = h->data;
          }
          nz = h->size[0] * h->size[1];
          for (k = 0; k < nz; k++) {
            h_data[k] = sqrt(h_data[k]);
          }
        } else {
          ib = h->size[0] * h->size[1];
          h->size[0] = b_I->size[0];
          h->size[1] = b_I->size[1];
          emxEnsureCapacity_real_T(h, ib);
          h_data = h->data;
          nz = b_I->size[0] * b_I->size[1];
          for (ib = 0; ib < nz; ib++) {
            h_data[ib] = 0.0;
          }
        }
      }
      if ((h->size[0] == b_loop_ub) && (h->size[1] == ndsi->size[1])) {
        ib = B2->size[0] * B2->size[1];
        B2->size[0] = h->size[0];
        B2->size[1] = h->size[1];
        emxEnsureCapacity_real32_T(B2, ib);
        B2_data = B2->data;
        b_loop_ub = h->size[1];
        for (ib = 0; ib < b_loop_ub; ib++) {
          nz = h->size[0];
          for (ncolsB = 0; ncolsB < nz; ncolsB++) {
            B2_data[ncolsB + B2->size[0] * ib] =
                (float)h_data[ncolsB + h->size[0] * ib] *
                (1.0F - ndsi_data[(i + ncolsB) + ndsi->size[0] * ib]);
          }
        }
      } else {
        binary_expand_op_21(B2, h, ndsi, i, i1 - 1);
        B2_data = B2->data;
      }
      if (row_st_small > row_ed_small) {
        ib = 0;
        ncolsB = 0;
      } else {
        ib = (int)row_st_small - 1;
        ncolsB = (int)row_ed_small;
      }
      if (row_st > row_ed) {
        i = 1;
      } else {
        i = (int)row_st;
      }
      b_loop_ub = B2->size[1];
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        nz = ncolsB - ib;
        for (lastBlockLength = 0; lastBlockLength < nz; lastBlockLength++) {
          scsi_data[((i + lastBlockLength) + scsi->size[0] * i1) - 1] =
              B2_data[(ib + lastBlockLength) + B2->size[0] * i1];
        }
      }
    }
    emxFree_real_T(&b_h);
    emxFree_real_T(&intI);
    emxFree_real_T(&conv1);
    emxFree_real_T(&b_I);
    emxFree_real_T(&h);
    emxFree_real32_T(&B3);
    emxFree_real32_T(&B2);
    /*  scsi=stdfilt(band_green_filled,true(win_size)).*(1-ndsi); */
    /*  only get snow/ice pixels from all potential snow/ice pixels, and  */
    /*  do not select the saturated pixels which may be cloud! */
    if (scsi->size[0] == 1) {
      i = psnow->size[0];
    } else {
      i = scsi->size[0];
    }
    if (scsi->size[1] == 1) {
      i1 = psnow->size[1];
    } else {
      i1 = scsi->size[1];
    }
    if ((scsi->size[0] == psnow->size[0]) &&
        (scsi->size[1] == psnow->size[1]) && (i == band_green_statu->size[0]) &&
        (i1 == band_green_statu->size[1])) {
      ib = abs_snow->size[0] * abs_snow->size[1];
      abs_snow->size[0] = scsi->size[0];
      abs_snow->size[1] = scsi->size[1];
      emxEnsureCapacity_boolean_T(abs_snow, ib);
      abs_snow_data = abs_snow->data;
      for (ib = 0; ib < loop_ub_tmp; ib++) {
        abs_snow_data[ib] = ((scsi_data[ib] < 9.0) && psnow_data[ib] &&
                             (!band_green_statu_data[ib]));
      }
    } else {
      binary_expand_op_24(abs_snow, scsi, psnow, band_green_statu);
    }
    emxFree_real_T(&scsi);
  } else {
    abs_snow->size[0] = 0;
    abs_snow->size[1] = 0;
  }
}

/* End of code generation (DetectAbsSnow.c) */
