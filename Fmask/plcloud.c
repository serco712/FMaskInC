/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * plcloud.c
 *
 * Code generation for function 'plcloud'
 *
 */

/* Include files */
#include "plcloud.h"
#include "Fmask_emxutil.h"
#include "Fmask_types.h"

/* Function Definitions */
void binary_expand_op(emxArray_boolean_T *in1, const emxArray_uint8_T *in2,
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
  const unsigned char *in2_data;
  const unsigned char *in3_data;
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
          ((in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] == 1) &&
           (in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1] == 0));
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

void binary_expand_op_1(emxArray_real32_T *in1, const emxArray_real32_T *in2)
{
  emxArray_real32_T *b_in1;
  const float *in2_data;
  float *b_in1_data;
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
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real32_T(&b_in1, 2);
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
  emxEnsureCapacity_real32_T(b_in1, i);
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
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] -
          in2_data[(i1 * stride_1_0 + in2->size[0] * aux_1_1) +
                   in2->size[0] * in2->size[1] * 4];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real32_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real32_T(&b_in1);
}

void binary_expand_op_10(emxArray_boolean_T *in1, const emxArray_boolean_T *in2,
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

void binary_expand_op_11(emxArray_boolean_T *in1, const emxArray_real32_T *in2,
                         const emxArray_real32_T *in3,
                         const emxArray_real32_T *in4,
                         const emxArray_real32_T *in5,
                         const emxArray_real32_T *in6)
{
  emxArray_boolean_T *b_in2;
  const float *in2_data;
  const float *in3_data;
  const float *in4_data;
  const float *in5_data;
  const float *in6_data;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int aux_3_1;
  int aux_4_1;
  int aux_5_1;
  int aux_6_1_tmp;
  int aux_7_1;
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
  int stride_5_0;
  int stride_5_1;
  int stride_7_0;
  int stride_7_1;
  boolean_T *b_in2_data;
  boolean_T *in1_data;
  in6_data = in6->data;
  in5_data = in5->data;
  in4_data = in4->data;
  in3_data = in3->data;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_boolean_T(&b_in2, 2);
  if (in1->size[0] == 1) {
    i = in4->size[0];
  } else {
    i = in1->size[0];
  }
  if (in6->size[0] == 1) {
    if (in4->size[0] == 1) {
      if (i == 1) {
        if (in5->size[0] == 1) {
          if (in4->size[0] == 1) {
            if (in3->size[0] == 1) {
              loop_ub = in2->size[0];
            } else {
              loop_ub = in3->size[0];
            }
          } else {
            loop_ub = in4->size[0];
          }
        } else {
          loop_ub = in5->size[0];
        }
      } else {
        loop_ub = i;
      }
    } else {
      loop_ub = in4->size[0];
    }
  } else {
    loop_ub = in6->size[0];
  }
  i = b_in2->size[0] * b_in2->size[1];
  b_in2->size[0] = loop_ub;
  if (in1->size[1] == 1) {
    i1 = in4->size[1];
  } else {
    i1 = in1->size[1];
  }
  if (in6->size[1] == 1) {
    if (in4->size[1] == 1) {
      if (i1 == 1) {
        if (in5->size[1] == 1) {
          if (in4->size[1] == 1) {
            if (in3->size[1] == 1) {
              b_loop_ub = in2->size[1];
            } else {
              b_loop_ub = in3->size[1];
            }
          } else {
            b_loop_ub = in4->size[1];
          }
        } else {
          b_loop_ub = in5->size[1];
        }
      } else {
        b_loop_ub = i1;
      }
    } else {
      b_loop_ub = in4->size[1];
    }
  } else {
    b_loop_ub = in6->size[1];
  }
  b_in2->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(b_in2, i);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  stride_2_0_tmp = (in4->size[0] != 1);
  stride_2_1_tmp = (in4->size[1] != 1);
  stride_3_0 = (in5->size[0] != 1);
  stride_3_1 = (in5->size[1] != 1);
  stride_5_0 = (in1->size[0] != 1);
  stride_5_1 = (in1->size[1] != 1);
  stride_7_0 = (in6->size[0] != 1);
  stride_7_1 = (in6->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  aux_3_1 = 0;
  aux_4_1 = 0;
  aux_5_1 = 0;
  aux_6_1_tmp = 0;
  aux_7_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      int in2_tmp;
      in2_tmp = i1 * stride_2_0_tmp;
      b_in2_data[i1 + b_in2->size[0] * i] =
          (((in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] < 0.8) &&
            (in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1] < 0.8) &&
            (in4_data[(in2_tmp + in4->size[0] * aux_2_1) +
                      in4->size[0] * in4->size[1] * 5] > 300.0F) &&
            (in5_data[i1 * stride_3_0 + in5->size[0] * aux_3_1] < 0.7) &&
            (((in4_data[in2_tmp + in4->size[0] * aux_4_1] -
               0.5F * in4_data[(in2_tmp + in4->size[0] * aux_4_1) +
                               in4->size[0] * in4->size[1] * 2]) -
                  800.0F >
              0.0F) ||
             in1_data[i1 * stride_5_0 + in1->size[0] * aux_5_1]) &&
            (in4_data[(in2_tmp + in4->size[0] * aux_6_1_tmp) +
                      in4->size[0] * in4->size[1] * 3] /
                 in4_data[(in2_tmp + in4->size[0] * aux_6_1_tmp) +
                          in4->size[0] * in4->size[1] * 4] >
             0.75F)) ||
           (in6_data[i1 * stride_7_0 + in6->size[0] * aux_7_1] > 0.25F));
    }
    aux_7_1 += stride_7_1;
    aux_6_1_tmp += stride_2_1_tmp;
    aux_5_1 += stride_5_1;
    aux_4_1 = aux_6_1_tmp;
    aux_3_1 += stride_3_1;
    aux_2_1 = aux_6_1_tmp;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in2->size[0];
  in1->size[1] = b_in2->size[1];
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in2->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in2->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in2_data[i1 + b_in2->size[0] * i];
    }
  }
  emxFree_boolean_T(&b_in2);
}

void binary_expand_op_12(emxArray_boolean_T *in1, const emxArray_boolean_T *in2,
                         const emxArray_boolean_T *in3)
{
  emxArray_boolean_T *b_in1;
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
  const boolean_T *in2_data;
  const boolean_T *in3_data;
  boolean_T *b_in1_data;
  boolean_T *in1_data;
  in3_data = in3->data;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_boolean_T(&b_in1, 2);
  if (in3->size[0] == 1) {
    if (in2->size[0] == 1) {
      loop_ub = in1->size[0];
    } else {
      loop_ub = in2->size[0];
    }
  } else {
    loop_ub = in3->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in3->size[1] == 1) {
    if (in2->size[1] == 1) {
      b_loop_ub = in1->size[1];
    } else {
      b_loop_ub = in2->size[1];
    }
  } else {
    b_loop_ub = in3->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(b_in1, i);
  b_in1_data = b_in1->data;
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
      b_in1_data[i1 + b_in1->size[0] * i] =
          ((in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
            in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1]) +
               in3_data[i1 * stride_2_0 + in3->size[0] * aux_2_1] >=
           1);
    }
    aux_2_1 += stride_2_1;
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

void binary_expand_op_14(emxArray_real32_T *in1, const emxArray_real32_T *in2,
                         const emxArray_real32_T *in3)
{
  const float *in2_data;
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
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  if (in3->size[1] == 1) {
    b_loop_ub = in2->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
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
          in2_data[(i1 * stride_0_0 + in2->size[0] * aux_0_1) +
                   in2->size[0] * in2->size[1] * 2] -
          in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

void binary_expand_op_15(emxArray_real32_T *in1, const emxArray_real32_T *in2,
                         const emxArray_real32_T *in3)
{
  const float *in2_data;
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
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  if (in3->size[1] == 1) {
    b_loop_ub = in2->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
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
          in2_data[(i1 * stride_0_0 + in2->size[0] * aux_0_1) +
                   in2->size[0] * in2->size[1]] -
          in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

void binary_expand_op_16(emxArray_real32_T *in1, const emxArray_real32_T *in2,
                         const emxArray_real32_T *in3)
{
  const float *in2_data;
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
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
  if (in3->size[1] == 1) {
    b_loop_ub = in2->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(in1, i);
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
          in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] -
          in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

void binary_expand_op_17(emxArray_boolean_T *in1, const emxArray_real32_T *in2,
                         const emxArray_real32_T *in3,
                         const emxArray_boolean_T *in4)
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
  const boolean_T *in4_data;
  boolean_T *in1_data;
  in4_data = in4->data;
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
      double d;
      float f;
      int i2;
      i2 = i1 * stride_0_0_tmp;
      d = in2_data[i2 + in2->size[0] * aux_0_1];
      f = in3_data[(i1 * stride_1_0_tmp + in3->size[0] * aux_1_1) +
                   in3->size[0] * in3->size[1] * 3];
      in1_data[i1 + in1->size[0] * i] =
          (((d < 0.01) && (f < 1100.0F)) ||
           ((d < 0.1) && in4_data[i2 + in4->size[0] * aux_2_1_tmp] &&
            (f < 500.0F)));
    }
    aux_3_1_tmp += stride_1_1_tmp;
    aux_2_1_tmp += stride_0_1_tmp;
    aux_1_1 = aux_3_1_tmp;
    aux_0_1 = aux_2_1_tmp;
  }
}

void binary_expand_op_18(emxArray_boolean_T *in1, const emxArray_real32_T *in2,
                         const emxArray_real32_T *in3)
{
  const float *in2_data;
  const float *in3_data;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1_tmp;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
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
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0_tmp = (in3->size[0] != 1);
  stride_1_1_tmp = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1_tmp = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      int i2;
      i2 = i1 * stride_1_0_tmp;
      in1_data[i1 + in1->size[0] * i] =
          ((in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] > 0.15) &&
           (in3_data[(i2 + in3->size[0] * aux_1_1) +
                     in3->size[0] * in3->size[1] * 3] > 1100.0F) &&
           (in3_data[(i2 + in3->size[0] * aux_2_1_tmp) +
                     in3->size[0] * in3->size[1]] > 1000.0F));
    }
    aux_2_1_tmp += stride_1_1_tmp;
    aux_1_1 = aux_2_1_tmp;
    aux_0_1 += stride_0_1;
  }
}

void binary_expand_op_2(emxArray_real32_T *in1, const emxArray_real32_T *in2)
{
  emxArray_real32_T *b_in1;
  const float *in2_data;
  float *b_in1_data;
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
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real32_T(&b_in1, 2);
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
  emxEnsureCapacity_real32_T(b_in1, i);
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
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] -
          in2_data[(i1 * stride_1_0 + in2->size[0] * aux_1_1) +
                   in2->size[0] * in2->size[1] * 3];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real32_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real32_T(&b_in1);
}

void binary_expand_op_3(emxArray_boolean_T *in1, const emxArray_boolean_T *in2,
                        const emxArray_real32_T *in3, float in4,
                        const emxArray_uint8_T *in5,
                        const emxArray_real32_T *in6, float in7)
{
  const float *in3_data;
  const float *in6_data;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int aux_3_1_tmp;
  int aux_4_1;
  int aux_5_1_tmp;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0_tmp;
  int stride_0_1_tmp;
  int stride_1_0;
  int stride_1_1;
  int stride_2_0_tmp;
  int stride_2_1_tmp;
  int stride_4_0;
  int stride_4_1;
  const unsigned char *in5_data;
  const boolean_T *in2_data;
  boolean_T *in1_data;
  in6_data = in6->data;
  in5_data = in5->data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in5->size[0] == 1) {
    if (in6->size[0] == 1) {
      i = in2->size[0];
    } else {
      i = in6->size[0];
    }
  } else {
    i = in5->size[0];
  }
  if (i == 1) {
    if (in5->size[0] == 1) {
      if (in3->size[0] == 1) {
        loop_ub = in2->size[0];
      } else {
        loop_ub = in3->size[0];
      }
    } else {
      loop_ub = in5->size[0];
    }
  } else {
    loop_ub = i;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  if (in5->size[1] == 1) {
    if (in6->size[1] == 1) {
      i = in2->size[1];
    } else {
      i = in6->size[1];
    }
  } else {
    i = in5->size[1];
  }
  if (i == 1) {
    if (in5->size[1] == 1) {
      if (in3->size[1] == 1) {
        b_loop_ub = in2->size[1];
      } else {
        b_loop_ub = in3->size[1];
      }
    } else {
      b_loop_ub = in5->size[1];
    }
  } else {
    b_loop_ub = i;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  stride_0_0_tmp = (in2->size[0] != 1);
  stride_0_1_tmp = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  stride_2_0_tmp = (in5->size[0] != 1);
  stride_2_1_tmp = (in5->size[1] != 1);
  stride_4_0 = (in6->size[0] != 1);
  stride_4_1 = (in6->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  aux_3_1_tmp = 0;
  aux_4_1 = 0;
  aux_5_1_tmp = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      int i2;
      boolean_T b;
      b = in2_data[i1 * stride_0_0_tmp + in2->size[0] * aux_0_1];
      i2 = in5_data[i1 * stride_2_0_tmp + in5->size[0] * aux_2_1];
      in1_data[i1 + in1->size[0] * i] =
          ((b && (in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1] > in4) &&
            (i2 == 0)) ||
           (b && (in6_data[i1 * stride_4_0 + in6->size[0] * aux_4_1] > in7) &&
            (i2 == 1)));
    }
    aux_5_1_tmp += stride_2_1_tmp;
    aux_4_1 += stride_4_1;
    aux_3_1_tmp += stride_0_1_tmp;
    aux_2_1 = aux_5_1_tmp;
    aux_1_1 += stride_1_1;
    aux_0_1 = aux_3_1_tmp;
  }
}

void binary_expand_op_4(emxArray_boolean_T *in1, const emxArray_boolean_T *in2,
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

void binary_expand_op_5(emxArray_real32_T *in1, const emxArray_real32_T *in2)
{
  emxArray_real32_T *r;
  const float *in2_data;
  float *in1_data;
  float *r1;
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
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real32_T(&r, 2);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = r->size[0] * r->size[1];
  r->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }
  r->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(r, i);
  r1 = r->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1[i1 + r->size[0] * i] =
          100.0F * (1.0F - in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1]) +
          in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
    }
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

void binary_expand_op_6(emxArray_boolean_T *in1, const emxArray_boolean_T *in2,
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
          (in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] &&
           in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1]);
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

void binary_expand_op_7(emxArray_boolean_T *in1, const emxArray_boolean_T *in2,
                        const emxArray_real32_T *in3)
{
  const float *in3_data;
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
           (in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1] < 0.0F));
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

void binary_expand_op_8(emxArray_boolean_T *in1, const emxArray_boolean_T *in2,
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

void binary_expand_op_9(emxArray_real32_T *in1, const emxArray_real32_T *in2)
{
  emxArray_real32_T *r;
  const float *in2_data;
  float *in1_data;
  float *r1;
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
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real32_T(&r, 2);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = r->size[0] * r->size[1];
  r->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }
  r->size[1] = b_loop_ub;
  emxEnsureCapacity_real32_T(r, i);
  r1 = r->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1[i1 + r->size[0] * i] =
          100.0F * in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
          in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
    }
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

/* End of code generation (plcloud.c) */
