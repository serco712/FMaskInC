/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DetectPotentialCloud.c
 *
 * Code generation for function 'DetectPotentialCloud'
 *
 */

/* Include files */
#include "DetectPotentialCloud.h"
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"
#include "ixfun.h"
#include "prctile.h"
#include "problSpectralVaribility.h"
#include <math.h>

/* Function Declarations */
static void binary_expand_op_25(emxArray_boolean_T *in1,
                                const emxArray_real32_T *in2, float in3);

static void binary_expand_op_26(emxArray_boolean_T *in1,
                                const emxArray_boolean_T *in2,
                                const emxArray_real32_T *in3, float in4,
                                const emxArray_uint8_T *in5,
                                const emxArray_real32_T *in6, float in7);

static void binary_expand_op_27(emxArray_real32_T *in1,
                                const emxArray_real32_T *in2,
                                const emxArray_real32_T *in3,
                                const emxArray_real32_T *in4);

static void binary_expand_op_28(emxArray_real32_T *in1,
                                const emxArray_real32_T *in2,
                                const emxArray_real32_T *in3);

static void binary_expand_op_31(emxArray_boolean_T *in1,
                                const emxArray_boolean_T *in2,
                                const emxArray_uint8_T *in3);

static void binary_expand_op_32(emxArray_boolean_T *in1,
                                const emxArray_boolean_T *in2,
                                const emxArray_uint8_T *in3);

static void binary_expand_op_33(emxArray_boolean_T *in1,
                                const emxArray_boolean_T *in2,
                                const emxArray_boolean_T *in3);

/* Function Definitions */
static void binary_expand_op_25(emxArray_boolean_T *in1,
                                const emxArray_real32_T *in2, float in3)
{
  emxArray_boolean_T *b_in1;
  const float *in2_data;
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
  boolean_T *b_in1_data;
  boolean_T *in1_data;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_boolean_T(&b_in1, 2);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          (in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] ||
           (in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1] <
            in3 - 3500.0F));
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_boolean_T(&b_in1);
}

static void binary_expand_op_26(emxArray_boolean_T *in1,
                                const emxArray_boolean_T *in2,
                                const emxArray_real32_T *in3, float in4,
                                const emxArray_uint8_T *in5,
                                const emxArray_real32_T *in6, float in7)
{
  const float *in3_data;
  const float *in6_data;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int aux_3_1;
  int aux_4_1_tmp;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  int stride_2_0_tmp;
  int stride_2_1_tmp;
  int stride_3_0;
  int stride_3_1;
  const unsigned char *in5_data;
  const boolean_T *in2_data;
  boolean_T *in1_data;
  in6_data = in6->data;
  in5_data = in5->data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in5->size[0] == 1) {
    i = in6->size[0];
  } else {
    i = in5->size[0];
  }
  if (i == 1) {
    if (in5->size[0] == 1) {
      i = in3->size[0];
    } else {
      i = in5->size[0];
    }
  }
  if (i == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = i;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  if (in5->size[1] == 1) {
    i = in6->size[1];
  } else {
    i = in5->size[1];
  }
  if (i == 1) {
    if (in5->size[1] == 1) {
      i = in3->size[1];
    } else {
      i = in5->size[1];
    }
  }
  if (i == 1) {
    b_loop_ub = in2->size[1];
  } else {
    b_loop_ub = i;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  stride_2_0_tmp = (in5->size[0] != 1);
  stride_2_1_tmp = (in5->size[1] != 1);
  stride_3_0 = (in6->size[0] != 1);
  stride_3_1 = (in6->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  aux_3_1 = 0;
  aux_4_1_tmp = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      int i2;
      i2 = in5_data[i1 * stride_2_0_tmp + in5->size[0] * aux_2_1];
      in1_data[i1 + in1->size[0] * i] =
          (in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] &&
           (((in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1] > in4) &&
             (i2 == 0)) ||
            ((in6_data[i1 * stride_3_0 + in6->size[0] * aux_3_1] > in7) &&
             (i2 == 1))));
    }
    aux_4_1_tmp += stride_2_1_tmp;
    aux_3_1 += stride_3_1;
    aux_2_1 = aux_4_1_tmp;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void binary_expand_op_27(emxArray_real32_T *in1,
                                const emxArray_real32_T *in2,
                                const emxArray_real32_T *in3,
                                const emxArray_real32_T *in4)
{
  emxArray_real32_T *r;
  const float *in2_data;
  const float *in3_data;
  const float *in4_data;
  float *in1_data;
  float *r1;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int aux_3_1;
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
  int stride_3_0;
  int stride_3_1;
  in4_data = in4->data;
  in3_data = in3->data;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real32_T(&r, 2);
  if (in4->size[0] == 1) {
    if (in3->size[0] == 1) {
      if (in2->size[0] == 1) {
        loop_ub = in1->size[0];
      } else {
        loop_ub = in2->size[0];
      }
    } else {
      loop_ub = in3->size[0];
    }
  } else {
    loop_ub = in4->size[0];
  }
  i = r->size[0] * r->size[1];
  r->size[0] = loop_ub;
  if (in4->size[1] == 1) {
    if (in3->size[1] == 1) {
      if (in2->size[1] == 1) {
        b_loop_ub = in1->size[1];
      } else {
        b_loop_ub = in2->size[1];
      }
    } else {
      b_loop_ub = in3->size[1];
    }
  } else {
    b_loop_ub = in4->size[1];
  }
  r->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(r, i);
  r1 = r->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  stride_2_0 = (in3->size[0] != 1);
  stride_2_1 = (in3->size[1] != 1);
  stride_3_0 = (in4->size[0] != 1);
  stride_3_1 = (in4->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  aux_3_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1[i1 + r->size[0] * i] =
          100.0F *
          (in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] *
               (1.0F - in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1]) *
               in3_data[i1 * stride_2_0 + in3->size[0] * aux_2_1] +
           in4_data[i1 * stride_3_0 + in4->size[0] * aux_3_1]);
    }
    aux_3_1 += stride_3_1;
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = r->size[0];
  in1->size[1] = r->size[1];
  emxEnsureCapacity_real32_T(in1, i);
  in1_data = in1->data;
  loop_ub = r->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = r->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = r1[i1 + r->size[0] * i];
    }
  }
  emxFree_real32_T(&r);
}

static void binary_expand_op_28(emxArray_real32_T *in1,
                                const emxArray_real32_T *in2,
                                const emxArray_real32_T *in3)
{
  emxArray_real32_T *r;
  const float *in2_data;
  const float *in3_data;
  float *in1_data;
  float *r1;
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
  in3_data = in3->data;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real32_T(&r, 2);
  if (in3->size[0] == 1) {
    if (in2->size[0] == 1) {
      loop_ub = in1->size[0];
    } else {
      loop_ub = in2->size[0];
    }
  } else {
    loop_ub = in3->size[0];
  }
  i = r->size[0] * r->size[1];
  r->size[0] = loop_ub;
  if (in3->size[1] == 1) {
    if (in2->size[1] == 1) {
      b_loop_ub = in1->size[1];
    } else {
      b_loop_ub = in2->size[1];
    }
  } else {
    b_loop_ub = in3->size[1];
  }
  r->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(r, i);
  r1 = r->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  stride_2_0 = (in3->size[0] != 1);
  stride_2_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1[i1 + r->size[0] * i] =
          100.0F * (in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] *
                        in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1] +
                    in3_data[i1 * stride_2_0 + in3->size[0] * aux_2_1]);
    }
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = r->size[0];
  in1->size[1] = r->size[1];
  emxEnsureCapacity_real32_T(in1, i);
  in1_data = in1->data;
  loop_ub = r->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = r->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = r1[i1 + r->size[0] * i];
    }
  }
  emxFree_real32_T(&r);
}

static void binary_expand_op_31(emxArray_boolean_T *in1,
                                const emxArray_boolean_T *in2,
                                const emxArray_uint8_T *in3)
{
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
  const unsigned char *in3_data;
  const boolean_T *in2_data;
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
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          (in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] &&
           (in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1] == 1));
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void binary_expand_op_32(emxArray_boolean_T *in1,
                                const emxArray_boolean_T *in2,
                                const emxArray_uint8_T *in3)
{
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
  const unsigned char *in3_data;
  const boolean_T *in2_data;
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
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          (in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] &&
           (in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1] == 0));
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void binary_expand_op_33(emxArray_boolean_T *in1,
                                const emxArray_boolean_T *in2,
                                const emxArray_boolean_T *in3)
{
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
  const boolean_T *in2_data;
  const boolean_T *in3_data;
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
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          ((!in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1]) &&
           in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1]);
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

double DetectPotentialCloud(
    const double data_meta_Dim[2], const emxArray_boolean_T *mask,
    const emxArray_uint8_T *water,
    const emxArray_real32_T *data_toabt_BandCirrus,
    const emxArray_real32_T *data_toabt_BandSWIR1,
    const emxArray_real32_T *data_toabt_BandBT,
    const emxArray_boolean_T *data_toabt_SatuGreen,
    const emxArray_boolean_T *data_toabt_SatuRed, const emxArray_real32_T *ndvi,
    const emxArray_real32_T *ndsi, const emxArray_real32_T *ndbi,
    const emxArray_boolean_T *idplcd, const emxArray_real32_T *whiteness,
    const emxArray_real32_T *HOT, double wpt, double cldprob,
    emxArray_boolean_T *cloud)
{
  emxArray_boolean_T *idclr;
  emxArray_boolean_T *idlnd;
  emxArray_boolean_T *idwt;
  emxArray_boolean_T *r2;
  emxArray_boolean_T *r3;
  emxArray_int32_T *r;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_real32_T *F_hot;
  emxArray_real32_T *b_data_toabt_BandBT;
  emxArray_real32_T *b_ndsi;
  emxArray_real32_T *b_ndvi;
  emxArray_real32_T *lprob_brightness;
  emxArray_real32_T *lprob_temp;
  emxArray_real32_T *prob_thin;
  emxArray_real32_T *varargin_1;
  emxArray_real32_T *varargin_2;
  emxArray_real32_T *wprob_brightness;
  emxArray_real32_T *wprob_temp;
  const float *HOT_data;
  const float *data_toabt_BandBT_data;
  const float *data_toabt_BandCirrus_data;
  const float *data_toabt_BandSWIR1_data;
  const float *ndbi_data;
  const float *ndsi_data;
  const float *ndvi_data;
  const float *whiteness_data;
  float t_templ;
  float *F_hot_data;
  float *b_ndsi_data;
  float *b_ndvi_data;
  float *lprob_brightness_data;
  float *lprob_temp_data;
  float *prob_thin_data;
  float *varargin_2_data;
  float *wprob_brightness_data;
  float *wprob_temp_data;
  int i;
  int k;
  int loop_ub;
  int nx;
  int vlen_tmp;
  int y;
  int *r1;
  const unsigned char *water_data;
  const boolean_T *data_toabt_SatuGreen_data;
  const boolean_T *data_toabt_SatuRed_data;
  const boolean_T *idplcd_data;
  const boolean_T *mask_data;
  boolean_T *cloud_data;
  boolean_T *idclr_data;
  boolean_T *idlnd_data;
  boolean_T *idwt_data;
  HOT_data = HOT->data;
  whiteness_data = whiteness->data;
  idplcd_data = idplcd->data;
  ndbi_data = ndbi->data;
  ndsi_data = ndsi->data;
  ndvi_data = ndvi->data;
  data_toabt_SatuRed_data = data_toabt_SatuRed->data;
  data_toabt_SatuGreen_data = data_toabt_SatuGreen->data;
  data_toabt_BandBT_data = data_toabt_BandBT->data;
  data_toabt_BandSWIR1_data = data_toabt_BandSWIR1->data;
  data_toabt_BandCirrus_data = data_toabt_BandCirrus->data;
  water_data = water->data;
  mask_data = mask->data;
  /* DETECTPOTENTIALCLOUD Detect potential clouds using scene-based method. */
  /*  */
  /*  Syntax */
  /*  */
  /*      [sum_clr,cloud,idlnd,t_templ,t_temph]= */
  /*      DetectPotentialCloud(data_meta,mask,water,data_toabt, dem, ndvi,ndsi,
   */
  /*      ndbi,idplcd,whiteness,HOT,wpt,cldprob) */
  /*  */
  /*  Description */
  /*  */
  /*      Several cloud probabilities are combinated together to capture cloud
   */
  /*      features of white, bright, cold, and/or high. */
  /*  */
  /*  Input arguments */
  /*  */
  /*      data_meta      Metadata including [row size, column size]. */
  /*      mask           Observation mask (outside). */
  /*      water          Water mask. */
  /*      data_toabt     TOA reflectance and BT. */
  /*      dem            DEM data. */
  /*      ndvi           NDVI. */
  /*      ndsi           NDSI. */
  /*      ndbi           NDBI. */
  /*      idplcd         Absolute clear sky pixels. */
  /*      whiteness      Whitness. */
  /*      HOT            Data derived from the HOT transform. */
  /*      wpt            Weight of thin probability (0.3 for Landsat 8 and  */
  /*                     0.5 for Sentinel 2). */
  /*      cldprob        Cloud probability threshold to segment clouds from */
  /*                     surface. */
  /*  */
  /*  Output arguments */
  /*  */
  /*      sum_clr        The total number of clear sky pixels. */
  /*      cloud          Potential clouds. */
  /*      idlnd          Clear sky land pixels. */
  /*      t_templ        Low level temperature (78.5 percentile). */
  /*      t_temph        High level temperature (81.5 percentile). */
  /*  */
  /*          */
  /*  Author:  Shi Qiu (shi.qiu@uconn.edu) */
  /*  Date: 20. January, 2018 */
  /*  inputs: BandCirrus BandBT BandSWIR1 SatuGreen SatuRed */
  i = cloud->size[0] * cloud->size[1];
  cloud->size[0] = (int)data_meta_Dim[0];
  cloud->size[1] = (int)data_meta_Dim[1];
  emxEnsureCapacity_boolean_T(cloud, i);
  cloud_data = cloud->data;
  loop_ub = (int)data_meta_Dim[0] * (int)data_meta_Dim[1];
  for (i = 0; i < loop_ub; i++) {
    cloud_data[i] = false;
  }
  /*  cloud mask */
  /*     %% Constants Parameters */
  /*  low percent */
  /*  high percent */
  /*     %% Step 2: calcualte cloud probability */
  /*  select clear sky pixels for land and water, respectively. */
  emxInit_boolean_T(&idclr, 2);
  if ((idplcd->size[0] == mask->size[0]) &&
      (idplcd->size[1] == mask->size[1])) {
    i = idclr->size[0] * idclr->size[1];
    idclr->size[0] = idplcd->size[0];
    idclr->size[1] = idplcd->size[1];
    emxEnsureCapacity_boolean_T(idclr, i);
    idclr_data = idclr->data;
    loop_ub = idplcd->size[0] * idplcd->size[1];
    for (i = 0; i < loop_ub; i++) {
      idclr_data[i] = ((!idplcd_data[i]) && mask_data[i]);
    }
  } else {
    binary_expand_op_33(idclr, idplcd, mask);
    idclr_data = idclr->data;
  }
  vlen_tmp = idclr->size[0] * idclr->size[1];
  if (vlen_tmp == 0) {
    y = 0;
  } else {
    y = idclr_data[0];
    for (k = 2; k <= vlen_tmp; k++) {
      y += idclr_data[k - 1];
    }
  }
  emxInit_boolean_T(&idlnd, 2);
  if ((idclr->size[0] == water->size[0]) &&
      (idclr->size[1] == water->size[1])) {
    i = idlnd->size[0] * idlnd->size[1];
    idlnd->size[0] = idclr->size[0];
    idlnd->size[1] = idclr->size[1];
    emxEnsureCapacity_boolean_T(idlnd, i);
    idlnd_data = idlnd->data;
    for (i = 0; i < vlen_tmp; i++) {
      idlnd_data[i] = (idclr_data[i] && (water_data[i] == 0));
    }
  } else {
    binary_expand_op_32(idlnd, idclr, water);
    idlnd_data = idlnd->data;
  }
  emxInit_boolean_T(&idwt, 2);
  if ((idclr->size[0] == water->size[0]) &&
      (idclr->size[1] == water->size[1])) {
    i = idwt->size[0] * idwt->size[1];
    idwt->size[0] = idclr->size[0];
    idwt->size[1] = idclr->size[1];
    emxEnsureCapacity_boolean_T(idwt, i);
    idwt_data = idwt->data;
    loop_ub = idclr->size[0] * idclr->size[1];
    for (i = 0; i < loop_ub; i++) {
      idwt_data[i] = (idclr_data[i] && (water_data[i] == 1));
    }
  } else {
    binary_expand_op_31(idwt, idclr, water);
    idwt_data = idwt->data;
  }
  /* &data(:,:,6)<=300; */
  t_templ = 0.0F;
  /*  99.9% TO 99.99% */
  vlen_tmp = idclr->size[0] * idclr->size[1];
  if (vlen_tmp == 0) {
    nx = 0;
  } else {
    nx = idclr_data[0];
    for (k = 2; k <= vlen_tmp; k++) {
      nx += idclr_data[k - 1];
    }
  }
  if (nx <= 40000) {
    /*  when potential cloud cover less than 0.1%, directly screen all PCPs out.
     */
    k = idplcd->size[0] * idplcd->size[1] - 1;
    for (i = 0; i <= k; i++) {
      if (idplcd_data[i]) {
        cloud_data[i] = true;
      }
    }
    /*  all cld */
    k = mask->size[0] * mask->size[1] - 1;
    for (i = 0; i <= k; i++) {
      if (!mask_data[i]) {
        cloud_data[i] = false;
      }
    }
  } else {
    float b_y;
    float t_wtemp;
    int b_i;
    int b_vlen_tmp;
    int loop_ub_tmp;
    boolean_T b;
    /* %%%%%%%%%% thin cloud prob for both water and land%%%%%%%%%%% */
    emxInit_real32_T(&prob_thin, 2);
    i = prob_thin->size[0] * prob_thin->size[1];
    prob_thin->size[0] = 1;
    prob_thin->size[1] = 1;
    emxEnsureCapacity_real32_T(prob_thin, i);
    prob_thin_data = prob_thin->data;
    prob_thin_data[0] = 0.0F;
    /*  there is no contribution from the new bands */
    if ((data_toabt_BandCirrus->size[0] != 0) &&
        (data_toabt_BandCirrus->size[1] != 0)) {
      /*  Landsat 4~7 */
      /* PROBCIRRUS */
      i = prob_thin->size[0] * prob_thin->size[1];
      prob_thin->size[0] = data_toabt_BandCirrus->size[0];
      prob_thin->size[1] = data_toabt_BandCirrus->size[1];
      emxEnsureCapacity_real32_T(prob_thin, i);
      prob_thin_data = prob_thin->data;
      nx = data_toabt_BandCirrus->size[0] * data_toabt_BandCirrus->size[1];
      for (i = 0; i < nx; i++) {
        prob_thin_data[i] = data_toabt_BandCirrus_data[i] / 400.0F;
      }
      /*      prob_thin(prob_thin>1)=1; */
      k = nx - 1;
      for (i = 0; i <= k; i++) {
        if (prob_thin_data[i] < 0.0F) {
          prob_thin_data[i] = 0.0F;
        }
      }
    }
    /* %%%%%%%%%%%%%%%%%%%%%cloud prob over water%%%%%%%%%%%%%%%%%%% */
    emxInit_real32_T(&wprob_temp, 2);
    i = wprob_temp->size[0] * wprob_temp->size[1];
    wprob_temp->size[0] = 1;
    wprob_temp->size[1] = 1;
    emxEnsureCapacity_real32_T(wprob_temp, i);
    wprob_temp_data = wprob_temp->data;
    wprob_temp_data[0] = 1.0F;
    b = ((data_toabt_BandBT->size[0] != 0) &&
         (data_toabt_BandBT->size[1] != 0));
    emxInit_real32_T(&b_data_toabt_BandBT, 1);
    if (b) {
      /* PROBTEMPERATURE calculate temperature probability for water. */
      /*  [temperature test (over water)] */
      /*  get clear water temperature */
      k = idwt->size[0] * idwt->size[1] - 1;
      loop_ub = 0;
      for (i = 0; i <= k; i++) {
        if (idwt_data[i]) {
          loop_ub++;
        }
      }
      emxInit_int32_T(&r, 1);
      i = r->size[0];
      r->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(r, i);
      r1 = r->data;
      nx = 0;
      for (i = 0; i <= k; i++) {
        if (idwt_data[i]) {
          r1[nx] = i;
          nx++;
        }
      }
      nx = data_toabt_BandBT->size[0] * data_toabt_BandBT->size[1];
      i = b_data_toabt_BandBT->size[0];
      b_data_toabt_BandBT->size[0] = r->size[0];
      emxEnsureCapacity_real32_T(b_data_toabt_BandBT, i);
      F_hot_data = b_data_toabt_BandBT->data;
      loop_ub = r->size[0];
      for (i = 0; i < loop_ub; i++) {
        F_hot_data[i] = data_toabt_BandBT_data[r1[i]];
      }
      emxFree_int32_T(&r);
      t_wtemp = b_prctile(b_data_toabt_BandBT);
      i = wprob_temp->size[0] * wprob_temp->size[1];
      wprob_temp->size[0] = data_toabt_BandBT->size[0];
      wprob_temp->size[1] = data_toabt_BandBT->size[1];
      emxEnsureCapacity_real32_T(wprob_temp, i);
      wprob_temp_data = wprob_temp->data;
      for (i = 0; i < nx; i++) {
        wprob_temp_data[i] = (t_wtemp - data_toabt_BandBT_data[i]) / 400.0F;
      }
      k = nx - 1;
      for (i = 0; i <= k; i++) {
        if (wprob_temp_data[i] < 0.0F) {
          wprob_temp_data[i] = 0.0F;
        }
      }
      /*     wTemp_prob(wTemp_prob > 1) = 1; */
    }
    /* PROBWBRIGHTNESS calculate brightness probability */
    /*  [Brightness test (over water)] */
    emxInit_real32_T(&wprob_brightness, 2);
    i = wprob_brightness->size[0] * wprob_brightness->size[1];
    wprob_brightness->size[0] = data_toabt_BandSWIR1->size[0];
    wprob_brightness->size[1] = data_toabt_BandSWIR1->size[1];
    emxEnsureCapacity_real32_T(wprob_brightness, i);
    wprob_brightness_data = wprob_brightness->data;
    nx = data_toabt_BandSWIR1->size[0] * data_toabt_BandSWIR1->size[1];
    for (i = 0; i < nx; i++) {
      wprob_brightness_data[i] = data_toabt_BandSWIR1_data[i] / 1100.0F;
    }
    nx--;
    for (i = 0; i <= nx; i++) {
      if (wprob_brightness_data[i] > 1.0F) {
        wprob_brightness_data[i] = 1.0F;
      }
    }
    for (i = 0; i <= nx; i++) {
      if (wprob_brightness_data[i] < 0.0F) {
        wprob_brightness_data[i] = 0.0F;
      }
    }
    /* %%%%%%%%%%%%%%%%%%%%%cloud prob over land%%%%%%%%%%%%%%%%%%%% */
    vlen_tmp = idlnd->size[0] * idlnd->size[1];
    if (vlen_tmp == 0) {
      nx = 0;
    } else {
      nx = idlnd_data[0];
      for (k = 2; k <= vlen_tmp; k++) {
        nx += idlnd_data[k - 1];
      }
    }
    b_vlen_tmp = mask->size[0] * mask->size[1];
    if (b_vlen_tmp == 0) {
      loop_ub = 0;
    } else {
      loop_ub = mask_data[0];
      for (k = 2; k <= b_vlen_tmp; k++) {
        loop_ub += mask_data[k - 1];
      }
    }
    if (100.0 * (double)nx / (double)loop_ub >= 0.1) {
      i = idclr->size[0] * idclr->size[1];
      idclr->size[0] = idlnd->size[0];
      idclr->size[1] = idlnd->size[1];
      emxEnsureCapacity_boolean_T(idclr, i);
      idclr_data = idclr->data;
      for (i = 0; i < vlen_tmp; i++) {
        idclr_data[i] = idlnd_data[i];
      }
    } else {
      /*  when having no enough clear land pixels, we used all PCPs to calculate
       * clear land basics. */
    }
    emxInit_real32_T(&lprob_temp, 2);
    i = lprob_temp->size[0] * lprob_temp->size[1];
    lprob_temp->size[0] = 1;
    lprob_temp->size[1] = 1;
    emxEnsureCapacity_real32_T(lprob_temp, i);
    lprob_temp_data = lprob_temp->data;
    lprob_temp_data[0] = 1.0F;
    emxInit_real32_T(&lprob_brightness, 2);
    i = lprob_brightness->size[0] * lprob_brightness->size[1];
    lprob_brightness->size[0] = 1;
    lprob_brightness->size[1] = 1;
    emxEnsureCapacity_real32_T(lprob_brightness, i);
    lprob_brightness_data = lprob_brightness->data;
    lprob_brightness_data[0] = 1.0F;
    emxInit_real32_T(&F_hot, 1);
    if (b) {
      /*  if have BT. normalize it using DEMs and use it to calcualte
       * temperature probability. */
      /* data_toabt.BandBT = NormalizeBT(
       * data_meta.Dim,dem,mask,data_toabt.BandBT,idused,l_pt,h_pt,data_meta.Resolution(1));
       */
      /* PROBTEMPERATURE calculate temperature probability for land
       * respectively. */
      /*  [Temperature test (over land)] */
      k = idclr->size[0] * idclr->size[1] - 1;
      loop_ub = 0;
      for (i = 0; i <= k; i++) {
        if (idclr_data[i]) {
          loop_ub++;
        }
      }
      i = F_hot->size[0];
      F_hot->size[0] = loop_ub;
      emxEnsureCapacity_real32_T(F_hot, i);
      F_hot_data = F_hot->data;
      nx = 0;
      for (i = 0; i <= k; i++) {
        if (idclr_data[i]) {
          F_hot_data[nx] = data_toabt_BandBT_data[i];
          nx++;
        }
      }
      /*  get clear temperature */
      /*  0.175 percentile background temperature (low) */
      t_templ = prctile(F_hot);
      /*  0.825 percentile background temperature (high) */
      t_wtemp = b_prctile(F_hot) + 400.0F;
      b_y = t_wtemp - (t_templ - 400.0F);
      i = lprob_temp->size[0] * lprob_temp->size[1];
      lprob_temp->size[0] = data_toabt_BandBT->size[0];
      lprob_temp->size[1] = data_toabt_BandBT->size[1];
      emxEnsureCapacity_real32_T(lprob_temp, i);
      lprob_temp_data = lprob_temp->data;
      nx = data_toabt_BandBT->size[0] * data_toabt_BandBT->size[1];
      for (i = 0; i < nx; i++) {
        lprob_temp_data[i] = (t_wtemp - data_toabt_BandBT_data[i]) / b_y;
      }
      /*  Temperature can have prob > 1 */
      k = nx - 1;
      for (i = 0; i <= k; i++) {
        if (lprob_temp_data[i] < 0.0F) {
          lprob_temp_data[i] = 0.0F;
        }
      }
      /*      prob_temp(prob_temp>1)=1; */
    } else {
      /*  if have no BT, use HOT probability instead of temperature probability.
       */
      /* PROBLBRIGHTNESS calculate brightness probability using HOT */
      k = idclr->size[0] * idclr->size[1] - 1;
      loop_ub = 0;
      for (i = 0; i <= k; i++) {
        if (idclr_data[i]) {
          loop_ub++;
        }
      }
      i = F_hot->size[0];
      F_hot->size[0] = loop_ub;
      emxEnsureCapacity_real32_T(F_hot, i);
      F_hot_data = F_hot->data;
      nx = 0;
      for (i = 0; i <= k; i++) {
        if (idclr_data[i]) {
          F_hot_data[nx] = HOT_data[i];
          nx++;
        }
      }
      /*  get clear HOTs */
      /*  0.175 percentile background HOT (low) */
      t_wtemp = prctile(F_hot) - 400.0F;
      /*  0.825 percentile background HOT (high) */
      b_y = (b_prctile(F_hot) + 400.0F) - t_wtemp;
      i = lprob_brightness->size[0] * lprob_brightness->size[1];
      lprob_brightness->size[0] = HOT->size[0];
      lprob_brightness->size[1] = HOT->size[1];
      emxEnsureCapacity_real32_T(lprob_brightness, i);
      lprob_brightness_data = lprob_brightness->data;
      nx = HOT->size[0] * HOT->size[1];
      for (i = 0; i < nx; i++) {
        lprob_brightness_data[i] = (HOT_data[i] - t_wtemp) / b_y;
      }
      nx--;
      for (i = 0; i <= nx; i++) {
        if (lprob_brightness_data[i] < 0.0F) {
          lprob_brightness_data[i] = 0.0F;
        }
      }
      for (i = 0; i <= nx; i++) {
        if (lprob_brightness_data[i] > 1.0F) {
          lprob_brightness_data[i] = 1.0F;
        }
      }
      /*  this cannot be higher 1 (maybe have commission errors from bright
       * surfaces). */
    }
    emxFree_real32_T(&F_hot);
    /*          clear idused; */
    emxInit_real32_T(&b_ndvi, 2);
    i = b_ndvi->size[0] * b_ndvi->size[1];
    b_ndvi->size[0] = ndvi->size[0];
    b_ndvi->size[1] = ndvi->size[1];
    emxEnsureCapacity_real32_T(b_ndvi, i);
    b_ndvi_data = b_ndvi->data;
    nx = ndvi->size[0] * ndvi->size[1];
    for (i = 0; i < nx; i++) {
      b_ndvi_data[i] = ndvi_data[i];
    }
    emxInit_real32_T(&b_ndsi, 2);
    i = b_ndsi->size[0] * b_ndsi->size[1];
    b_ndsi->size[0] = ndsi->size[0];
    b_ndsi->size[1] = ndsi->size[1];
    emxEnsureCapacity_real32_T(b_ndsi, i);
    b_ndsi_data = b_ndsi->data;
    loop_ub_tmp = ndsi->size[0] * ndsi->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      b_ndsi_data[i] = ndsi_data[i];
    }
    /* PROBLSPECTRALVARIBILITY  */
    /*  [varibility test over land] */
    emxInit_boolean_T(&r2, 2);
    if ((data_toabt_SatuGreen->size[0] == ndsi->size[0]) &&
        (data_toabt_SatuGreen->size[1] == ndsi->size[1])) {
      i = r2->size[0] * r2->size[1];
      r2->size[0] = data_toabt_SatuGreen->size[0];
      r2->size[1] = data_toabt_SatuGreen->size[1];
      emxEnsureCapacity_boolean_T(r2, i);
      idclr_data = r2->data;
      loop_ub = data_toabt_SatuGreen->size[0] * data_toabt_SatuGreen->size[1];
      for (i = 0; i < loop_ub; i++) {
        idclr_data[i] = (data_toabt_SatuGreen_data[i] && (ndsi_data[i] < 0.0F));
      }
    } else {
      binary_expand_op_30(r2, data_toabt_SatuGreen, ndsi);
      idclr_data = r2->data;
    }
    k = r2->size[0] * r2->size[1] - 1;
    for (i = 0; i <= k; i++) {
      if (idclr_data[i]) {
        b_ndsi_data[i] = 0.0F;
      }
    }
    emxFree_boolean_T(&r2);
    emxInit_boolean_T(&r3, 2);
    if ((data_toabt_SatuRed->size[0] == ndvi->size[0]) &&
        (data_toabt_SatuRed->size[1] == ndvi->size[1])) {
      i = r3->size[0] * r3->size[1];
      r3->size[0] = data_toabt_SatuRed->size[0];
      r3->size[1] = data_toabt_SatuRed->size[1];
      emxEnsureCapacity_boolean_T(r3, i);
      idclr_data = r3->data;
      loop_ub = data_toabt_SatuRed->size[0] * data_toabt_SatuRed->size[1];
      for (i = 0; i < loop_ub; i++) {
        idclr_data[i] = (data_toabt_SatuRed_data[i] && (ndvi_data[i] > 0.0F));
      }
    } else {
      binary_expand_op_29(r3, data_toabt_SatuRed, ndvi);
      idclr_data = r3->data;
    }
    k = r3->size[0] * r3->size[1] - 1;
    for (i = 0; i <= k; i++) {
      if (idclr_data[i]) {
        b_ndvi_data[i] = 0.0F;
      }
    }
    emxFree_boolean_T(&r3);
    emxInit_real32_T(&varargin_1, 2);
    i = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = b_ndsi->size[0];
    varargin_1->size[1] = b_ndsi->size[1];
    emxEnsureCapacity_real32_T(varargin_1, i);
    F_hot_data = varargin_1->data;
    for (k = 0; k < loop_ub_tmp; k++) {
      F_hot_data[k] = fabsf(b_ndsi_data[k]);
    }
    emxInit_real32_T(&varargin_2, 2);
    i = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = b_ndvi->size[0];
    varargin_2->size[1] = b_ndvi->size[1];
    emxEnsureCapacity_real32_T(varargin_2, i);
    varargin_2_data = varargin_2->data;
    for (k = 0; k < nx; k++) {
      varargin_2_data[k] = fabsf(b_ndvi_data[k]);
    }
    if ((varargin_1->size[0] == varargin_2->size[0]) &&
        (varargin_1->size[1] == varargin_2->size[1])) {
      i = b_ndvi->size[0] * b_ndvi->size[1];
      b_ndvi->size[0] = varargin_1->size[0];
      b_ndvi->size[1] = varargin_1->size[1];
      emxEnsureCapacity_real32_T(b_ndvi, i);
      b_ndvi_data = b_ndvi->data;
      loop_ub = varargin_1->size[0] * varargin_1->size[1];
      for (i = 0; i < loop_ub; i++) {
        t_wtemp = F_hot_data[i];
        b_y = varargin_2_data[i];
        b_ndvi_data[i] = fmaxf(t_wtemp, b_y);
      }
    } else {
      expand_max(varargin_1, varargin_2, b_ndvi);
      b_ndvi_data = b_ndvi->data;
    }
    emxFree_real32_T(&varargin_1);
    nx = ndbi->size[0] * ndbi->size[1];
    i = varargin_2->size[0] * varargin_2->size[1];
    varargin_2->size[0] = ndbi->size[0];
    varargin_2->size[1] = ndbi->size[1];
    emxEnsureCapacity_real32_T(varargin_2, i);
    varargin_2_data = varargin_2->data;
    for (k = 0; k < nx; k++) {
      varargin_2_data[k] = fabsf(ndbi_data[k]);
    }
    if ((b_ndvi->size[0] == varargin_2->size[0]) &&
        (b_ndvi->size[1] == varargin_2->size[1])) {
      i = b_ndsi->size[0] * b_ndsi->size[1];
      b_ndsi->size[0] = b_ndvi->size[0];
      b_ndsi->size[1] = b_ndvi->size[1];
      emxEnsureCapacity_real32_T(b_ndsi, i);
      b_ndsi_data = b_ndsi->data;
      loop_ub = b_ndvi->size[0] * b_ndvi->size[1];
      for (i = 0; i < loop_ub; i++) {
        t_wtemp = b_ndvi_data[i];
        b_y = varargin_2_data[i];
        b_ndsi_data[i] = fmaxf(t_wtemp, b_y);
      }
    } else {
      expand_max(b_ndvi, varargin_2, b_ndsi);
      b_ndsi_data = b_ndsi->data;
    }
    emxFree_real32_T(&varargin_2);
    if ((b_ndsi->size[0] == whiteness->size[0]) &&
        (b_ndsi->size[1] == whiteness->size[1])) {
      i = b_ndvi->size[0] * b_ndvi->size[1];
      b_ndvi->size[0] = b_ndsi->size[0];
      b_ndvi->size[1] = b_ndsi->size[1];
      emxEnsureCapacity_real32_T(b_ndvi, i);
      b_ndvi_data = b_ndvi->data;
      loop_ub = b_ndsi->size[0] * b_ndsi->size[1];
      for (i = 0; i < loop_ub; i++) {
        t_wtemp = b_ndsi_data[i];
        b_y = whiteness_data[i];
        b_ndvi_data[i] = fmaxf(t_wtemp, b_y);
      }
    } else {
      expand_max(b_ndsi, whiteness, b_ndvi);
      b_ndvi_data = b_ndvi->data;
    }
    emxFree_real32_T(&b_ndsi);
    /* %%%%%%%%%%%%%%%%%%%%%%%%%final clouds%%%%%%%%%%%%%%%%%%%%%%% */
    /*  [Final prob mask (water)] */
    nx = prob_thin->size[0] * prob_thin->size[1];
    for (i = 0; i < nx; i++) {
      prob_thin_data[i] *= (float)wpt;
    }
    /*  cloud over water probability */
    if (wprob_temp->size[0] == 1) {
      loop_ub_tmp = wprob_brightness->size[0];
    } else {
      loop_ub_tmp = wprob_temp->size[0];
    }
    if (wprob_temp->size[1] == 1) {
      b_i = wprob_brightness->size[1];
    } else {
      b_i = wprob_temp->size[1];
    }
    if ((wprob_temp->size[0] == wprob_brightness->size[0]) &&
        (wprob_temp->size[1] == wprob_brightness->size[1]) &&
        (loop_ub_tmp == prob_thin->size[0]) && (b_i == prob_thin->size[1])) {
      loop_ub = wprob_temp->size[0] * wprob_temp->size[1];
      for (i = 0; i < loop_ub; i++) {
        wprob_temp_data[i] =
            100.0F *
            (wprob_temp_data[i] * wprob_brightness_data[i] + prob_thin_data[i]);
      }
    } else {
      binary_expand_op_28(wprob_temp, wprob_brightness, prob_thin);
      wprob_temp_data = wprob_temp->data;
    }
    emxFree_real32_T(&wprob_brightness);
    /*  convert percentage */
    /*  Final prob mask (land) */
    /*  cloud over land probability */
    /*          clear lprob_temp lprob_vari lprob_brightness prob_thin wpt; */
    if (lprob_temp->size[0] == 1) {
      i = b_ndvi->size[0];
    } else {
      i = lprob_temp->size[0];
    }
    if (lprob_temp->size[1] == 1) {
      k = b_ndvi->size[1];
    } else {
      k = lprob_temp->size[1];
    }
    if (i == 1) {
      loop_ub_tmp = lprob_brightness->size[0];
    } else {
      loop_ub_tmp = i;
    }
    if (k == 1) {
      b_i = lprob_brightness->size[1];
    } else {
      b_i = k;
    }
    if ((lprob_temp->size[0] == b_ndvi->size[0]) &&
        (lprob_temp->size[1] == b_ndvi->size[1]) &&
        (i == lprob_brightness->size[0]) && (k == lprob_brightness->size[1]) &&
        (loop_ub_tmp == prob_thin->size[0]) && (b_i == prob_thin->size[1])) {
      loop_ub = lprob_temp->size[0] * lprob_temp->size[1];
      for (i = 0; i < loop_ub; i++) {
        lprob_temp_data[i] =
            100.0F * (lprob_temp_data[i] * (1.0F - b_ndvi_data[i]) *
                          lprob_brightness_data[i] +
                      prob_thin_data[i]);
      }
    } else {
      binary_expand_op_27(lprob_temp, b_ndvi, lprob_brightness, prob_thin);
      lprob_temp_data = lprob_temp->data;
    }
    emxFree_real32_T(&b_ndvi);
    emxFree_real32_T(&lprob_brightness);
    emxFree_real32_T(&prob_thin);
    /*  convert percentage */
    k = idwt->size[0] * idwt->size[1] - 1;
    loop_ub = 0;
    for (i = 0; i <= k; i++) {
      if (idwt_data[i]) {
        loop_ub++;
      }
    }
    emxInit_int32_T(&r4, 1);
    i = r4->size[0];
    r4->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r4, i);
    r1 = r4->data;
    nx = 0;
    for (i = 0; i <= k; i++) {
      if (idwt_data[i]) {
        r1[nx] = i;
        nx++;
      }
    }
    i = b_data_toabt_BandBT->size[0];
    b_data_toabt_BandBT->size[0] = r4->size[0];
    emxEnsureCapacity_real32_T(b_data_toabt_BandBT, i);
    F_hot_data = b_data_toabt_BandBT->data;
    loop_ub = r4->size[0];
    for (i = 0; i < loop_ub; i++) {
      F_hot_data[i] = wprob_temp_data[r1[i]];
    }
    emxFree_int32_T(&r4);
    t_wtemp = b_prctile(b_data_toabt_BandBT) + (float)cldprob;
    /*  dynamic threshold (water) */
    k = vlen_tmp - 1;
    loop_ub = 0;
    for (i = 0; i <= k; i++) {
      if (idlnd_data[i]) {
        loop_ub++;
      }
    }
    emxInit_int32_T(&r5, 1);
    i = r5->size[0];
    r5->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r5, i);
    r1 = r5->data;
    nx = 0;
    for (i = 0; i <= k; i++) {
      if (idlnd_data[i]) {
        r1[nx] = i;
        nx++;
      }
    }
    i = b_data_toabt_BandBT->size[0];
    b_data_toabt_BandBT->size[0] = r5->size[0];
    emxEnsureCapacity_real32_T(b_data_toabt_BandBT, i);
    F_hot_data = b_data_toabt_BandBT->data;
    loop_ub = r5->size[0];
    for (i = 0; i < loop_ub; i++) {
      F_hot_data[i] = lprob_temp_data[r1[i]];
    }
    emxFree_int32_T(&r5);
    b_y = b_prctile(b_data_toabt_BandBT) + (float)cldprob;
    emxFree_real32_T(&b_data_toabt_BandBT);
    /*  dynamic threshold (land) */
    /*  all potential clouds */
    /*  %         cloud(idclr==true)=-1; */
    /* %%%%%%%%%%%%%%%%%%%%%%%%%final clouds%%%%%%%%%%%%%%%%%%%%%%% */
    /*  final clouds */
    if (lprob_temp->size[0] == 1) {
      i = water->size[0];
    } else {
      i = lprob_temp->size[0];
    }
    if (wprob_temp->size[0] == 1) {
      k = water->size[0];
    } else {
      k = wprob_temp->size[0];
    }
    if (lprob_temp->size[1] == 1) {
      loop_ub = water->size[1];
    } else {
      loop_ub = lprob_temp->size[1];
    }
    if (wprob_temp->size[1] == 1) {
      nx = water->size[1];
    } else {
      nx = wprob_temp->size[1];
    }
    if (i == 1) {
      loop_ub_tmp = k;
    } else {
      loop_ub_tmp = i;
    }
    if (loop_ub == 1) {
      b_i = nx;
    } else {
      b_i = loop_ub;
    }
    if ((lprob_temp->size[0] == water->size[0]) &&
        (lprob_temp->size[1] == water->size[1]) &&
        (wprob_temp->size[0] == water->size[0]) &&
        (wprob_temp->size[1] == water->size[1]) && (i == k) &&
        (loop_ub == nx) && (idplcd->size[0] == loop_ub_tmp) &&
        (idplcd->size[1] == b_i)) {
      i = idclr->size[0] * idclr->size[1];
      idclr->size[0] = idplcd->size[0];
      idclr->size[1] = idplcd->size[1];
      emxEnsureCapacity_boolean_T(idclr, i);
      idclr_data = idclr->data;
      loop_ub = idplcd->size[0] * idplcd->size[1];
      for (i = 0; i < loop_ub; i++) {
        idclr_data[i] =
            (idplcd_data[i] &&
             (((lprob_temp_data[i] > b_y) && (water_data[i] == 0)) ||
              ((wprob_temp_data[i] > t_wtemp) && (water_data[i] == 1))));
      }
    } else {
      binary_expand_op_26(idclr, idplcd, lprob_temp, b_y, water, wprob_temp,
                          t_wtemp);
      idclr_data = idclr->data;
    }
    emxFree_real32_T(&lprob_temp);
    emxFree_real32_T(&wprob_temp);
    /* % cloud over land */
    /*  thin cloud over water */
    if (b) {
      /*  if have BT. */
      if ((idclr->size[0] == data_toabt_BandBT->size[0]) &&
          (idclr->size[1] == data_toabt_BandBT->size[1])) {
        loop_ub = idclr->size[0] * idclr->size[1];
        for (i = 0; i < loop_ub; i++) {
          idclr_data[i] = (idclr_data[i] ||
                           (data_toabt_BandBT_data[i] < t_templ - 3500.0F));
        }
      } else {
        binary_expand_op_25(idclr, data_toabt_BandBT, t_templ);
        idclr_data = idclr->data;
      }
      /*  extremly cold cloud */
    }
    k = idclr->size[0] * idclr->size[1] - 1;
    for (i = 0; i <= k; i++) {
      if (idclr_data[i]) {
        cloud_data[i] = true;
      }
    }
    k = b_vlen_tmp - 1;
    for (i = 0; i <= k; i++) {
      if (!mask_data[i]) {
        cloud_data[i] = false;
      }
    }
  }
  emxFree_boolean_T(&idwt);
  emxFree_boolean_T(&idlnd);
  emxFree_boolean_T(&idclr);
  return y;
}

/* End of code generation (DetectPotentialCloud.c) */
