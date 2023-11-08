/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imdilate.c
 *
 * Code generation for function 'imdilate'
 *
 */

/* Include files */
#include "imdilate.h"
#include "Fmask_emxutil.h"
#include "Fmask_types.h"
#include "flip.h"
#include "morphop.h"
#include "padarray.h"
#include "strel.h"
#include "libmwmorphop_flat_tbb.h"
#include "libmwmorphop_ipp.h"
#include "libmwmorphop_nonflat_tbb.h"
#include <math.h>

/* Function Definitions */
void imdilate(const emxArray_uint8_T *A,
              const c_emxArray_images_internal_code *se_StrelArray,
              const emxArray_cell_wrap_14 *se_DecomposedStrelArray,
              emxArray_uint8_T *B)
{
  c_emxArray_images_internal_code *seq_StrelArray;
  c_images_internal_coder_strel_S *seq_StrelArray_data;
  cell_wrap_14 *seq_DecomposedStrelArray_data;
  emxArray_boolean_T *isEachStrelInSE2D;
  emxArray_boolean_T *nhood;
  emxArray_cell_wrap_14 *seq_DecomposedStrelArray;
  emxArray_real_T *allheight;
  emxArray_real_T *height;
  emxArray_uint8_T *Apad;
  emxArray_uint8_T *r;
  strel b_obj;
  strel obj;
  double asizeT[2];
  double pad_lr_data[2];
  double pad_ul_data[2];
  double *allheight_data;
  double *height_data;
  int b_i;
  int b_loop_ub_tmp;
  int i;
  int i1;
  int i2;
  int k;
  int loop_ub_tmp;
  int nd2;
  int sInd;
  int tmp_tmp;
  int vstride;
  signed char iv[3];
  const unsigned char *A_data;
  signed char libNameEnum;
  unsigned char *Apad_data;
  unsigned char *B_data;
  boolean_T exitg1;
  boolean_T pre_pad;
  boolean_T strel_is_all_flat;
  boolean_T *nhood_data;
  A_data = A->data;
  d_emxInit_images_internal_coder(&seq_StrelArray);
  emxInit_cell_wrap_14(&seq_DecomposedStrelArray);
  emxInit_boolean_T(&isEachStrelInSE2D, 2);
  strel_decompose(se_StrelArray, se_DecomposedStrelArray, seq_StrelArray,
                  seq_DecomposedStrelArray, isEachStrelInSE2D);
  seq_DecomposedStrelArray_data = seq_DecomposedStrelArray->data;
  seq_StrelArray_data = seq_StrelArray->data;
  emxFree_boolean_T(&isEachStrelInSE2D);
  strel_is_all_flat = true;
  sInd = 0;
  emxInitStruct_strel(&obj);
  exitg1 = false;
  while ((!exitg1) && (sInd <= seq_StrelArray->size[1] - 1)) {
    i = obj.StrelArray->size[0] * obj.StrelArray->size[1];
    obj.StrelArray->size[0] = 1;
    obj.StrelArray->size[1] = seq_StrelArray->size[1];
    d_emxEnsureCapacity_images_inte(obj.StrelArray, i);
    vstride = seq_StrelArray->size[1];
    for (i = 0; i < vstride; i++) {
      c_emxCopyStruct_images_internal(&obj.StrelArray->data[i],
                                      &seq_StrelArray_data[i]);
    }
    i = obj.DecomposedStrelArray->size[0] * obj.DecomposedStrelArray->size[1];
    obj.DecomposedStrelArray->size[0] = 1;
    obj.DecomposedStrelArray->size[1] = seq_DecomposedStrelArray->size[1];
    emxEnsureCapacity_cell_wrap_141(obj.DecomposedStrelArray, i);
    vstride = seq_DecomposedStrelArray->size[1];
    for (i = 0; i < vstride; i++) {
      emxCopyStruct_cell_wrap_14(&obj.DecomposedStrelArray->data[i],
                                 &seq_DecomposedStrelArray_data[i]);
    }
    strel_parenReference(&obj, (double)sInd + 1.0);
    if (obj.StrelArray->data[0].Flat) {
      sInd++;
    } else {
      strel_is_all_flat = false;
      exitg1 = true;
    }
  }
  i = seq_StrelArray->size[1];
  for (sInd = 0; sInd < i; sInd++) {
    i1 = obj.StrelArray->size[0] * obj.StrelArray->size[1];
    obj.StrelArray->size[0] = 1;
    vstride = seq_StrelArray->size[1];
    obj.StrelArray->size[1] = seq_StrelArray->size[1];
    d_emxEnsureCapacity_images_inte(obj.StrelArray, i1);
    for (i1 = 0; i1 < vstride; i1++) {
      c_emxCopyStruct_images_internal(&obj.StrelArray->data[i1],
                                      &seq_StrelArray_data[i1]);
    }
    i1 = obj.DecomposedStrelArray->size[0] * obj.DecomposedStrelArray->size[1];
    obj.DecomposedStrelArray->size[0] = 1;
    vstride = seq_DecomposedStrelArray->size[1];
    obj.DecomposedStrelArray->size[1] = seq_DecomposedStrelArray->size[1];
    emxEnsureCapacity_cell_wrap_141(obj.DecomposedStrelArray, i1);
    for (i1 = 0; i1 < vstride; i1++) {
      emxCopyStruct_cell_wrap_14(&obj.DecomposedStrelArray->data[i1],
                                 &seq_DecomposedStrelArray_data[i1]);
    }
    strel_parenReference(&obj, (double)sInd + 1.0);
  }
  if ((seq_StrelArray->size[1] != 1) &&
      (!strel_isdecompositionorthogonal(se_StrelArray,
                                        se_DecomposedStrelArray))) {
    pre_pad = true;
  } else {
    pre_pad = false;
  }
  if (strel_is_all_flat) {
    libNameEnum = 6;
  } else {
    libNameEnum = 7;
  }
  emxInit_uint8_T(&Apad);
  if (pre_pad) {
    int pad_lr_size[2];
    int pad_ul_size[2];
    strel_getpadsize(se_StrelArray, se_DecomposedStrelArray, pad_ul_data,
                     pad_ul_size, pad_lr_data, pad_lr_size);
    emxInit_uint8_T(&r);
    b_padarray(A, pad_ul_data, r);
    c_padarray(r, pad_lr_data, Apad);
    Apad_data = Apad->data;
    emxFree_uint8_T(&r);
  } else {
    i = Apad->size[0] * Apad->size[1];
    Apad->size[0] = A->size[0];
    Apad->size[1] = A->size[1];
    emxEnsureCapacity_uint8_T(Apad, i);
    Apad_data = Apad->data;
    vstride = A->size[0] * A->size[1];
    for (i = 0; i < vstride; i++) {
      Apad_data[i] = A_data[i];
    }
    pad_ul_data[0] = -1.0;
    pad_lr_data[0] = -1.0;
    pad_ul_data[1] = -1.0;
    pad_lr_data[1] = -1.0;
  }
  i = B->size[0] * B->size[1];
  B->size[0] = Apad->size[0];
  B->size[1] = Apad->size[1];
  emxEnsureCapacity_uint8_T(B, i);
  B_data = B->data;
  i = seq_StrelArray->size[1];
  emxInit_boolean_T(&nhood, 3);
  emxInit_real_T(&allheight, 3);
  emxInit_real_T(&height, 1);
  emxInitStruct_strel(&b_obj);
  for (sInd = 0; sInd < i; sInd++) {
    i1 = obj.StrelArray->size[0] * obj.StrelArray->size[1];
    obj.StrelArray->size[0] = 1;
    vstride = seq_StrelArray->size[1];
    obj.StrelArray->size[1] = seq_StrelArray->size[1];
    d_emxEnsureCapacity_images_inte(obj.StrelArray, i1);
    for (i1 = 0; i1 < vstride; i1++) {
      c_emxCopyStruct_images_internal(&obj.StrelArray->data[i1],
                                      &seq_StrelArray_data[i1]);
    }
    i1 = obj.DecomposedStrelArray->size[0] * obj.DecomposedStrelArray->size[1];
    obj.DecomposedStrelArray->size[0] = 1;
    vstride = seq_DecomposedStrelArray->size[1];
    obj.DecomposedStrelArray->size[1] = seq_DecomposedStrelArray->size[1];
    emxEnsureCapacity_cell_wrap_141(obj.DecomposedStrelArray, i1);
    for (i1 = 0; i1 < vstride; i1++) {
      emxCopyStruct_cell_wrap_14(&obj.DecomposedStrelArray->data[i1],
                                 &seq_DecomposedStrelArray_data[i1]);
    }
    strel_parenReference(&obj, (double)sInd + 1.0);
    i1 = b_obj.StrelArray->size[0] * b_obj.StrelArray->size[1];
    b_obj.StrelArray->size[0] = 1;
    vstride = seq_StrelArray->size[1];
    b_obj.StrelArray->size[1] = seq_StrelArray->size[1];
    d_emxEnsureCapacity_images_inte(b_obj.StrelArray, i1);
    for (i1 = 0; i1 < vstride; i1++) {
      c_emxCopyStruct_images_internal(&b_obj.StrelArray->data[i1],
                                      &seq_StrelArray_data[i1]);
    }
    i1 = b_obj.DecomposedStrelArray->size[0] *
         b_obj.DecomposedStrelArray->size[1];
    b_obj.DecomposedStrelArray->size[0] = 1;
    vstride = seq_DecomposedStrelArray->size[1];
    b_obj.DecomposedStrelArray->size[1] = seq_DecomposedStrelArray->size[1];
    emxEnsureCapacity_cell_wrap_141(b_obj.DecomposedStrelArray, i1);
    for (i1 = 0; i1 < vstride; i1++) {
      emxCopyStruct_cell_wrap_14(&b_obj.DecomposedStrelArray->data[i1],
                                 &seq_DecomposedStrelArray_data[i1]);
    }
    strel_parenReference(&b_obj, (double)sInd + 1.0);
    if (useIPP(obj.StrelArray->data[0].nhood,
               b_obj.StrelArray->data[0].height) &&
        strel_is_all_flat) {
      double nsizeT_data[3];
      double b_tmp;
      int n;
      int offset;
      boolean_T tmp;
      if (obj.StrelArray->data[0].nhood->size[0] == 0) {
        iv[0] = 0;
      } else {
        iv[0] =
            (signed char)(int)fmod(obj.StrelArray->data[0].nhood->size[0], 2.0);
      }
      if (obj.StrelArray->data[0].nhood->size[1] == 0) {
        iv[1] = 0;
      } else {
        iv[1] =
            (signed char)(int)fmod(obj.StrelArray->data[0].nhood->size[1], 2.0);
      }
      iv[2] = 1;
      tmp = false;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (iv[k] == 0) {
          tmp = true;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (tmp) {
        double d;
        double numColPad;
        b_tmp =
            ((double)obj.StrelArray->data[0].nhood->size[0] -
             2.0 * ceil((double)obj.StrelArray->data[0].nhood->size[0] / 2.0)) +
            1.0;
        numColPad =
            ((double)obj.StrelArray->data[0].nhood->size[1] -
             2.0 * ceil((double)obj.StrelArray->data[0].nhood->size[1] / 2.0)) +
            1.0;
        i1 = (int)((double)obj.StrelArray->data[0].nhood->size[0] + b_tmp);
        i2 = nhood->size[0] * nhood->size[1] * nhood->size[2];
        nhood->size[0] = i1;
        tmp_tmp =
            (int)((double)obj.StrelArray->data[0].nhood->size[1] + numColPad);
        nhood->size[1] = tmp_tmp;
        nhood->size[2] = 1;
        emxEnsureCapacity_boolean_T(nhood, i2);
        nhood_data = nhood->data;
        loop_ub_tmp = i1 * tmp_tmp;
        for (i2 = 0; i2 < loop_ub_tmp; i2++) {
          nhood_data[i2] = false;
        }
        i2 = allheight->size[0] * allheight->size[1] * allheight->size[2];
        allheight->size[0] = i1;
        allheight->size[1] = tmp_tmp;
        allheight->size[2] = 1;
        emxEnsureCapacity_real_T(allheight, i2);
        allheight_data = allheight->data;
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          allheight_data[i1] = 0.0;
        }
        d = fmod(b_tmp, 4.294967296E+9);
        if (d < 0.0) {
          i1 = -(int)(unsigned int)-d;
        } else {
          i1 = (int)(unsigned int)d;
        }
        offset = obj.StrelArray->data[0].nhood->size[0] + i1;
        if (b_tmp + 1.0 > offset) {
          i1 = 1;
        } else {
          i1 = (int)(b_tmp + 1.0);
        }
        d = fmod(numColPad, 4.294967296E+9);
        if (d < 0.0) {
          i2 = -(int)(unsigned int)-d;
        } else {
          i2 = (int)(unsigned int)d;
        }
        i2 += obj.StrelArray->data[0].nhood->size[1];
        if (numColPad + 1.0 > i2) {
          tmp_tmp = 1;
        } else {
          tmp_tmp = (int)(numColPad + 1.0);
        }
        vstride = obj.StrelArray->data[0].nhood->size[0];
        n = obj.StrelArray->data[0].nhood->size[1];
        for (k = 0; k < n; k++) {
          for (nd2 = 0; nd2 < vstride; nd2++) {
            nhood_data[((i1 + nd2) + offset * ((tmp_tmp + k) - 1)) - 1] =
                obj.StrelArray->data[0]
                    .nhood
                    ->data[nd2 + obj.StrelArray->data[0].nhood->size[0] * k];
          }
        }
        if (b_tmp + 1.0 > offset) {
          i1 = 1;
        } else {
          i1 = (int)(b_tmp + 1.0);
        }
        if (numColPad + 1.0 > i2) {
          i2 = 1;
        } else {
          i2 = (int)(numColPad + 1.0);
        }
        vstride = b_obj.StrelArray->data[0].height->size[0];
        n = b_obj.StrelArray->data[0].height->size[1];
        for (tmp_tmp = 0; tmp_tmp < n; tmp_tmp++) {
          for (k = 0; k < vstride; k++) {
            allheight_data[((i1 + k) + offset * ((i2 + tmp_tmp) - 1)) - 1] =
                b_obj.StrelArray->data[0].height->data
                    [k + b_obj.StrelArray->data[0].height->size[0] * tmp_tmp];
          }
        }
      } else {
        i1 = nhood->size[0] * nhood->size[1] * nhood->size[2];
        nhood->size[0] = obj.StrelArray->data[0].nhood->size[0];
        nhood->size[1] = obj.StrelArray->data[0].nhood->size[1];
        nhood->size[2] = 1;
        emxEnsureCapacity_boolean_T(nhood, i1);
        nhood_data = nhood->data;
        vstride = obj.StrelArray->data[0].nhood->size[0] *
                  obj.StrelArray->data[0].nhood->size[1];
        for (i1 = 0; i1 < vstride; i1++) {
          nhood_data[i1] = obj.StrelArray->data[0].nhood->data[i1];
        }
        i1 = allheight->size[0] * allheight->size[1] * allheight->size[2];
        allheight->size[0] = b_obj.StrelArray->data[0].height->size[0];
        allheight->size[1] = b_obj.StrelArray->data[0].height->size[1];
        allheight->size[2] = 1;
        emxEnsureCapacity_real_T(allheight, i1);
        allheight_data = allheight->data;
        vstride = b_obj.StrelArray->data[0].height->size[0] *
                  b_obj.StrelArray->data[0].height->size[1];
        for (i1 = 0; i1 < vstride; i1++) {
          allheight_data[i1] = b_obj.StrelArray->data[0].height->data[i1];
        }
      }
      tmp = ((allheight->size[0] != 0) && (allheight->size[1] != 0));
      if (tmp && (allheight->size[0] > 1)) {
        n = allheight->size[0] - 1;
        nd2 = allheight->size[0] >> 1;
        i1 = allheight->size[1] - 1;
        for (vstride = 0; vstride <= i1; vstride++) {
          offset = vstride * allheight->size[0];
          for (k = 0; k < nd2; k++) {
            tmp_tmp = offset + k;
            b_tmp = allheight_data[tmp_tmp];
            i2 = (offset + n) - k;
            allheight_data[tmp_tmp] = allheight_data[i2];
            allheight_data[i2] = b_tmp;
          }
        }
      }
      if (tmp && (allheight->size[1] > 1)) {
        vstride = allheight->size[0];
        n = allheight->size[1] - 1;
        nd2 = allheight->size[1] >> 1;
        i1 = allheight->size[0] - 1;
        for (b_i = 0; b_i <= i1; b_i++) {
          for (k = 0; k < nd2; k++) {
            tmp_tmp = b_i + k * vstride;
            b_tmp = allheight_data[tmp_tmp];
            i2 = b_i + (n - k) * vstride;
            allheight_data[tmp_tmp] = allheight_data[i2];
            allheight_data[i2] = b_tmp;
          }
        }
      }
      tmp = false;
      vstride = 1;
      exitg1 = false;
      while ((!exitg1) &&
             (vstride <= allheight->size[0] * allheight->size[1])) {
        if (allheight_data[vstride - 1] != 0.0) {
          tmp = true;
          exitg1 = true;
        } else {
          vstride++;
        }
      }
      if (tmp) {
        if ((nhood->size[0] != 0) && (nhood->size[1] != 0) &&
            (nhood->size[0] > 1)) {
          n = nhood->size[0] - 1;
          nd2 = nhood->size[0] >> 1;
          i1 = nhood->size[1] - 1;
          for (vstride = 0; vstride <= i1; vstride++) {
            offset = vstride * nhood->size[0];
            for (k = 0; k < nd2; k++) {
              tmp_tmp = offset + k;
              tmp = nhood_data[tmp_tmp];
              i2 = (offset + n) - k;
              nhood_data[tmp_tmp] = nhood_data[i2];
              nhood_data[i2] = tmp;
            }
          }
        }
        flip(nhood);
        nhood_data = nhood->data;
      }
      asizeT[0] = Apad->size[0];
      nsizeT_data[0] = nhood->size[0];
      asizeT[1] = Apad->size[1];
      nsizeT_data[1] = nhood->size[1];
      dilate_uint8_ipp(&Apad_data[0], &asizeT[0], &nhood_data[0],
                       &nsizeT_data[0], &B_data[0]);
    } else {
      double b_tmp;
      int n;
      int offset;
      boolean_T tmp;
      i1 = nhood->size[0] * nhood->size[1] * nhood->size[2];
      nhood->size[0] = obj.StrelArray->data[0].nhood->size[0];
      nhood->size[1] = obj.StrelArray->data[0].nhood->size[1];
      nhood->size[2] = 1;
      emxEnsureCapacity_boolean_T(nhood, i1);
      nhood_data = nhood->data;
      loop_ub_tmp = obj.StrelArray->data[0].nhood->size[0] *
                    obj.StrelArray->data[0].nhood->size[1];
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        nhood_data[i1] = obj.StrelArray->data[0].nhood->data[i1];
      }
      i1 = allheight->size[0] * allheight->size[1] * allheight->size[2];
      allheight->size[0] = b_obj.StrelArray->data[0].height->size[0];
      allheight->size[1] = b_obj.StrelArray->data[0].height->size[1];
      allheight->size[2] = 1;
      emxEnsureCapacity_real_T(allheight, i1);
      allheight_data = allheight->data;
      b_loop_ub_tmp = b_obj.StrelArray->data[0].height->size[0] *
                      b_obj.StrelArray->data[0].height->size[1];
      for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
        allheight_data[i1] = b_obj.StrelArray->data[0].height->data[i1];
      }
      tmp = ((b_obj.StrelArray->data[0].height->size[0] != 0) &&
             (b_obj.StrelArray->data[0].height->size[1] != 0));
      if (tmp && (b_obj.StrelArray->data[0].height->size[0] > 1)) {
        n = b_obj.StrelArray->data[0].height->size[0] - 1;
        nd2 = b_obj.StrelArray->data[0].height->size[0] >> 1;
        i1 = b_obj.StrelArray->data[0].height->size[1] - 1;
        for (vstride = 0; vstride <= i1; vstride++) {
          offset = vstride * allheight->size[0];
          for (k = 0; k < nd2; k++) {
            tmp_tmp = offset + k;
            b_tmp = allheight_data[tmp_tmp];
            i2 = (offset + n) - k;
            allheight_data[tmp_tmp] = allheight_data[i2];
            allheight_data[i2] = b_tmp;
          }
        }
      }
      if (tmp && (allheight->size[1] > 1)) {
        vstride = allheight->size[0];
        n = allheight->size[1] - 1;
        nd2 = allheight->size[1] >> 1;
        i1 = allheight->size[0] - 1;
        for (b_i = 0; b_i <= i1; b_i++) {
          for (k = 0; k < nd2; k++) {
            tmp_tmp = b_i + k * vstride;
            b_tmp = allheight_data[tmp_tmp];
            i2 = b_i + (n - k) * vstride;
            allheight_data[tmp_tmp] = allheight_data[i2];
            allheight_data[i2] = b_tmp;
          }
        }
      }
      tmp = false;
      vstride = 1;
      exitg1 = false;
      while ((!exitg1) && (vstride <= b_loop_ub_tmp)) {
        if (allheight_data[vstride - 1] != 0.0) {
          tmp = true;
          exitg1 = true;
        } else {
          vstride++;
        }
      }
      if (tmp) {
        i1 = nhood->size[0] * nhood->size[1] * nhood->size[2];
        nhood->size[0] = obj.StrelArray->data[0].nhood->size[0];
        nhood->size[1] = obj.StrelArray->data[0].nhood->size[1];
        nhood->size[2] = 1;
        emxEnsureCapacity_boolean_T(nhood, i1);
        nhood_data = nhood->data;
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          nhood_data[i1] = obj.StrelArray->data[0].nhood->data[i1];
        }
        if ((obj.StrelArray->data[0].nhood->size[0] != 0) &&
            (obj.StrelArray->data[0].nhood->size[1] != 0) &&
            (obj.StrelArray->data[0].nhood->size[0] > 1)) {
          n = obj.StrelArray->data[0].nhood->size[0] - 1;
          nd2 = obj.StrelArray->data[0].nhood->size[0] >> 1;
          i1 = obj.StrelArray->data[0].nhood->size[1] - 1;
          for (vstride = 0; vstride <= i1; vstride++) {
            offset = vstride * nhood->size[0];
            for (k = 0; k < nd2; k++) {
              tmp_tmp = offset + k;
              tmp = nhood_data[tmp_tmp];
              i2 = (offset + n) - k;
              nhood_data[tmp_tmp] = nhood_data[i2];
              nhood_data[i2] = tmp;
            }
          }
        }
        flip(nhood);
        nhood_data = nhood->data;
      }
      offset = nhood->size[0] * nhood->size[1] - 1;
      vstride = 0;
      for (b_i = 0; b_i <= offset; b_i++) {
        if (nhood_data[b_i]) {
          vstride++;
        }
      }
      i1 = height->size[0];
      height->size[0] = vstride;
      emxEnsureCapacity_real_T(height, i1);
      height_data = height->data;
      vstride = 0;
      for (b_i = 0; b_i <= offset; b_i++) {
        if (nhood_data[b_i]) {
          height_data[vstride] = allheight_data[b_i];
          vstride++;
        }
      }
      if (libNameEnum == 7) {
        double nsizeT_data[3];
        asizeT[0] = Apad->size[0];
        nsizeT_data[0] = nhood->size[0];
        asizeT[1] = Apad->size[1];
        nsizeT_data[1] = nhood->size[1];
        dilate_nonflat_uint8_tbb(&Apad_data[0], &asizeT[0], 2.0, &nhood_data[0],
                                 &nsizeT_data[0], 2.0, &height_data[0],
                                 &B_data[0]);
      } else {
        double nsizeT_data[3];
        asizeT[0] = Apad->size[0];
        nsizeT_data[0] = nhood->size[0];
        asizeT[1] = Apad->size[1];
        nsizeT_data[1] = nhood->size[1];
        dilate_flat_uint8_tbb(&Apad_data[0], &asizeT[0], 2.0, &nhood_data[0],
                              &nsizeT_data[0], 2.0, &B_data[0]);
      }
    }
    i1 = Apad->size[0] * Apad->size[1];
    Apad->size[0] = B->size[0];
    Apad->size[1] = B->size[1];
    emxEnsureCapacity_uint8_T(Apad, i1);
    Apad_data = Apad->data;
    vstride = B->size[0] * B->size[1];
    for (i1 = 0; i1 < vstride; i1++) {
      Apad_data[i1] = B_data[i1];
    }
  }
  emxFreeStruct_strel(&b_obj);
  emxFreeStruct_strel(&obj);
  emxFree_cell_wrap_14(&seq_DecomposedStrelArray);
  c_emxFree_images_internal_coder(&seq_StrelArray);
  emxFree_real_T(&height);
  emxFree_real_T(&allheight);
  emxFree_boolean_T(&nhood);
  emxFree_uint8_T(&Apad);
  if (pre_pad) {
    asizeT[0] =
        ((((pad_ul_data[0] + 1.0) + (double)B->size[0]) - pad_ul_data[0]) -
         pad_lr_data[0]) -
        1.0;
    asizeT[1] =
        ((((pad_ul_data[1] + 1.0) + (double)B->size[1]) - pad_ul_data[1]) -
         pad_lr_data[1]) -
        1.0;
    if (pad_ul_data[0] + 1.0 > asizeT[0]) {
      i = -1;
      i1 = -1;
    } else {
      i = (int)(pad_ul_data[0] + 1.0) - 2;
      i1 = (int)asizeT[0] - 1;
    }
    if (pad_ul_data[1] + 1.0 > asizeT[1]) {
      i2 = 0;
      tmp_tmp = 0;
    } else {
      i2 = (int)(pad_ul_data[1] + 1.0) - 1;
      tmp_tmp = (int)asizeT[1];
    }
    loop_ub_tmp = tmp_tmp - i2;
    for (tmp_tmp = 0; tmp_tmp < loop_ub_tmp; tmp_tmp++) {
      b_loop_ub_tmp = i1 - i;
      for (k = 0; k < b_loop_ub_tmp; k++) {
        B_data[k + b_loop_ub_tmp * tmp_tmp] =
            B_data[((i + k) + B->size[0] * (i2 + tmp_tmp)) + 1];
      }
    }
    i2 = B->size[0] * B->size[1];
    B->size[0] = i1 - i;
    B->size[1] = loop_ub_tmp;
    emxEnsureCapacity_uint8_T(B, i2);
  }
}

/* End of code generation (imdilate.c) */
