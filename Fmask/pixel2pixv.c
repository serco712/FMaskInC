/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pixel2pixv.c
 *
 * Code generation for function 'pixel2pixv'
 *
 */

/* Include files */
#include "pixel2pixv.h"
#include "Fmask_emxutil.h"
#include "Fmask_types.h"
#include <math.h>

/* Function Definitions */
void pixel2pixv(const double jiul1[2], const double jiul2[2],
                const double resolu1[4], const double resolu2[4],
                const emxArray_real32_T *im2, const double jidim1[2],
                const double jidim2[2], emxArray_real32_T *outim)
{
  emxArray_int32_T *r;
  emxArray_int32_T *r2;
  emxArray_int32_T *r4;
  emxArray_int32_T *r6;
  emxArray_real_T *b_i;
  emxArray_real_T *j;
  double b_jiul1;
  double *i_data;
  double *j_data;
  const float *im2_data;
  float a;
  float *outim_data;
  int b_loop_ub_tmp;
  int i;
  int loop_ub;
  int loop_ub_tmp;
  int nx;
  int *r1;
  int *r3;
  int *r5;
  int *r7;
  im2_data = im2->data;
  /*  from stack images of different resolution and different projection  */
  /*  Improved version of lndpixel2pixv */
  /*  match image2 with image1 */
  /*  Input 1) jiul1 (upperleft corner of the pixel) of image 1 */
  /*  Input 2) jiul2 (upperleft corner of the pixel) of image 2 */
  /*  Input 3&4) j cols, i rows of image 1 */
  /*  Input 5&6) resolution of images 1&2 */
  /*  Input 7) image 2 data  */
  /*  Input 8&9) image 1 and 2 dimension */
  /*  output matched data = outim(f(i),f(j))=>im1(i,j) */
  /*  i.e. matchdata=pixel2pixv(ul1,ul2,res1,res2,data2,dim1,dim2); */
  emxInit_real_T(&j, 2);
  if (jidim1[0] < 1.0) {
    j->size[1] = 0;
  } else {
    i = j->size[0] * j->size[1];
    j->size[0] = 1;
    j->size[1] = (int)(jidim1[0] - 1.0) + 1;
    emxEnsureCapacity_real_T(j, i);
    j_data = j->data;
    loop_ub = (int)(jidim1[0] - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      j_data[i] = (double)i + 1.0;
    }
  }
  emxInit_real_T(&b_i, 2);
  if (jidim1[1] < 1.0) {
    b_i->size[1] = 0;
  } else {
    i = b_i->size[0] * b_i->size[1];
    b_i->size[0] = 1;
    b_i->size[1] = (int)(jidim1[1] - 1.0) + 1;
    emxEnsureCapacity_real_T(b_i, i);
    i_data = b_i->data;
    loop_ub = (int)(jidim1[1] - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      i_data[i] = (double)i + 1.0;
    }
  }
  /*  pixel to map */
  /*  from pixel to map */
  /*  Input jiUL (upperleft corner of the pixel) meters (x,y) */
  /*  resolution [x, y] */
  /*  output x, y of center of the pixel i,j */
  /*  i.e. [x,y]=lndpixel2maplndpixel2map(jiUL,j,i,resolu) */
  /*  map to pixel */
  /*  from map to pixel */
  /*  Input jiUL (upperleft corner of the pixel), and x meters, and y meters,
   * and */
  /*  resolution [x, y] */
  /*  output j cols, i rows */
  /*  i.e. [j,i]=lndmap2pixel(jiUL,x,y,resolu) */
  i = j->size[0] * j->size[1];
  j->size[0] = 1;
  emxEnsureCapacity_real_T(j, i);
  j_data = j->data;
  b_jiul1 = jiul1[0] + resolu1[0] / 2.0;
  loop_ub_tmp = j->size[1] - 1;
  for (i = 0; i <= loop_ub_tmp; i++) {
    j_data[i] =
        ((b_jiul1 + (j_data[i] - 1.0) * resolu1[0]) - jiul2[0]) / resolu2[0];
  }
  nx = j->size[1];
  for (loop_ub = 0; loop_ub < nx; loop_ub++) {
    j_data[loop_ub] = ceil(j_data[loop_ub]);
  }
  i = b_i->size[0] * b_i->size[1];
  b_i->size[0] = 1;
  emxEnsureCapacity_real_T(b_i, i);
  i_data = b_i->data;
  b_jiul1 = jiul1[1] - resolu1[1] / 2.0;
  b_loop_ub_tmp = b_i->size[1] - 1;
  for (i = 0; i <= b_loop_ub_tmp; i++) {
    i_data[i] =
        (jiul2[1] - (b_jiul1 + (1.0 - i_data[i]) * resolu1[1])) / resolu2[1];
  }
  nx = b_i->size[1];
  for (loop_ub = 0; loop_ub < nx; loop_ub++) {
    i_data[loop_ub] = ceil(i_data[loop_ub]);
  }
  /*  the first data is assume to be the filled value */
  a = im2_data[0];
  i = outim->size[0] * outim->size[1];
  outim->size[0] = (int)jidim1[1];
  outim->size[1] = (int)jidim1[0];
  emxEnsureCapacity_real32_T(outim, i);
  outim_data = outim->data;
  loop_ub = (int)jidim1[1] * (int)jidim1[0];
  for (i = 0; i < loop_ub; i++) {
    outim_data[i] = a;
  }
  /*  give filled data first */
  /*  matched data i,j exit in data2 */
  /* jexistv=j2(((j2 > 0)&(j2 <= jidim2(1)))); % exist i,j => data2 (f(i),f(j))
   */
  /* iexistv=i2(((i2 > 0)&(i2 <= jidim2(2)))); */
  nx = 0;
  for (loop_ub = 0; loop_ub <= loop_ub_tmp; loop_ub++) {
    b_jiul1 = j_data[loop_ub];
    if ((b_jiul1 > 0.0) && (b_jiul1 <= jidim2[0])) {
      nx++;
    }
  }
  emxInit_int32_T(&r, 2);
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = nx;
  emxEnsureCapacity_int32_T(r, i);
  r1 = r->data;
  nx = 0;
  for (loop_ub = 0; loop_ub <= loop_ub_tmp; loop_ub++) {
    b_jiul1 = j_data[loop_ub];
    if ((b_jiul1 > 0.0) && (b_jiul1 <= jidim2[0])) {
      r1[nx] = loop_ub;
      nx++;
    }
  }
  /*  exist i,j => data2 (f(i),f(j)) */
  nx = 0;
  for (loop_ub = 0; loop_ub <= b_loop_ub_tmp; loop_ub++) {
    b_jiul1 = i_data[loop_ub];
    if ((b_jiul1 > 0.0) && (b_jiul1 <= jidim2[1])) {
      nx++;
    }
  }
  emxInit_int32_T(&r2, 2);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = nx;
  emxEnsureCapacity_int32_T(r2, i);
  r3 = r2->data;
  nx = 0;
  for (loop_ub = 0; loop_ub <= b_loop_ub_tmp; loop_ub++) {
    b_jiul1 = i_data[loop_ub];
    if ((b_jiul1 > 0.0) && (b_jiul1 <= jidim2[1])) {
      r3[nx] = loop_ub;
      nx++;
    }
  }
  emxInit_int32_T(&r4, 1);
  i = r4->size[0];
  r4->size[0] = r2->size[1];
  emxEnsureCapacity_int32_T(r4, i);
  r5 = r4->data;
  loop_ub = r2->size[1];
  for (i = 0; i < loop_ub; i++) {
    r5[i] = r3[i];
  }
  emxInit_int32_T(&r6, 1);
  i = r6->size[0];
  r6->size[0] = r->size[1];
  emxEnsureCapacity_int32_T(r6, i);
  r7 = r6->data;
  loop_ub = r->size[1];
  for (i = 0; i < loop_ub; i++) {
    r7[i] = r1[i];
    nx = r2->size[1];
    for (loop_ub_tmp = 0; loop_ub_tmp < nx; loop_ub_tmp++) {
      outim_data[r5[loop_ub_tmp] + outim->size[0] * r7[i]] =
          im2_data[((int)i_data[r3[loop_ub_tmp]] +
                    im2->size[0] * ((int)j_data[r1[i]] - 1)) -
                   1];
    }
  }
  emxFree_int32_T(&r);
  emxFree_int32_T(&r2);
  emxFree_int32_T(&r6);
  emxFree_int32_T(&r4);
  emxFree_real_T(&b_i);
  emxFree_real_T(&j);
}

/* End of code generation (pixel2pixv.c) */
