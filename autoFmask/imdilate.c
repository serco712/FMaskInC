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
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"
#include "padarray.h"
#include "strel.h"
#include "libmwbwpackctbb.h"
#include "libmwbwunpackctbb.h"
#include "libmwmorphop_binary.h"
#include "libmwmorphop_binary_tbb.h"
#include "libmwmorphop_packed.h"
#include <math.h>

/* Function Definitions */
void imdilate(const emxArray_boolean_T *A,
              const c_emxArray_images_internal_code *se_StrelArray,
              const emxArray_cell_wrap_22 *se_DecomposedStrelArray,
              emxArray_boolean_T *B)
{
  c_emxArray_images_internal_code *seq_StrelArray;
  const c_images_internal_coder_strel_S *se_StrelArray_data;
  c_images_internal_coder_strel_S *seq_StrelArray_data;
  cell_wrap_22 *seq_DecomposedStrelArray_data;
  emxArray_boolean_T *Apad;
  emxArray_boolean_T *Apadpre;
  emxArray_boolean_T *isEachStrelInSE2D;
  emxArray_boolean_T *nhoodIn;
  emxArray_cell_wrap_22 *seq_DecomposedStrelArray;
  emxArray_real_T *allheightIn;
  emxArray_uint32_T *Apadpack;
  emxArray_uint32_T *Bpack;
  strel b_obj;
  strel obj;
  double bwpSize[2];
  double pad_lr_data[2];
  double pad_ul_data[2];
  double sizeB[2];
  double *allheightIn_data;
  int b_i;
  int i;
  int i1;
  int i2;
  int j;
  int k;
  int loop_ub_tmp;
  int n;
  int nd2;
  int numRows;
  int offset;
  int sInd;
  unsigned int *Apadpack_data;
  unsigned int *Bpack_data;
  signed char fcnNameEnum;
  signed char libNameEnum;
  const boolean_T *A_data;
  boolean_T exitg1;
  boolean_T pre_pack;
  boolean_T pre_pad;
  boolean_T strel_is_all_flat;
  boolean_T strel_is_single;
  boolean_T *Apad_data;
  boolean_T *Apadpre_data;
  boolean_T *nhoodIn_data;
  se_StrelArray_data = se_StrelArray->data;
  A_data = A->data;
  d_emxInit_images_internal_coder(&seq_StrelArray);
  emxInit_cell_wrap_22(&seq_DecomposedStrelArray);
  emxInit_boolean_T(&isEachStrelInSE2D, 2);
  strel_decompose(se_StrelArray, se_DecomposedStrelArray, seq_StrelArray,
                  seq_DecomposedStrelArray, isEachStrelInSE2D);
  seq_DecomposedStrelArray_data = seq_DecomposedStrelArray->data;
  seq_StrelArray_data = seq_StrelArray->data;
  emxFree_boolean_T(&isEachStrelInSE2D);
  strel_is_single = (seq_StrelArray->size[1] == 1);
  strel_is_all_flat = true;
  sInd = 0;
  emxInitStruct_strel(&obj);
  exitg1 = false;
  while ((!exitg1) && (sInd <= seq_StrelArray->size[1] - 1)) {
    i = obj.StrelArray->size[0] * obj.StrelArray->size[1];
    obj.StrelArray->size[0] = 1;
    obj.StrelArray->size[1] = seq_StrelArray->size[1];
    d_emxEnsureCapacity_images_inte(obj.StrelArray, i);
    offset = seq_StrelArray->size[1];
    for (i = 0; i < offset; i++) {
      c_emxCopyStruct_images_internal(&obj.StrelArray->data[i],
                                      &seq_StrelArray_data[i]);
    }
    i = obj.DecomposedStrelArray->size[0] * obj.DecomposedStrelArray->size[1];
    obj.DecomposedStrelArray->size[0] = 1;
    obj.DecomposedStrelArray->size[1] = seq_DecomposedStrelArray->size[1];
    emxEnsureCapacity_cell_wrap_221(obj.DecomposedStrelArray, i);
    offset = seq_DecomposedStrelArray->size[1];
    for (i = 0; i < offset; i++) {
      emxCopyStruct_cell_wrap_22(&obj.DecomposedStrelArray->data[i],
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
    offset = seq_StrelArray->size[1];
    obj.StrelArray->size[1] = seq_StrelArray->size[1];
    d_emxEnsureCapacity_images_inte(obj.StrelArray, i1);
    for (i1 = 0; i1 < offset; i1++) {
      c_emxCopyStruct_images_internal(&obj.StrelArray->data[i1],
                                      &seq_StrelArray_data[i1]);
    }
    i1 = obj.DecomposedStrelArray->size[0] * obj.DecomposedStrelArray->size[1];
    obj.DecomposedStrelArray->size[0] = 1;
    offset = seq_DecomposedStrelArray->size[1];
    obj.DecomposedStrelArray->size[1] = seq_DecomposedStrelArray->size[1];
    emxEnsureCapacity_cell_wrap_221(obj.DecomposedStrelArray, i1);
    for (i1 = 0; i1 < offset; i1++) {
      emxCopyStruct_cell_wrap_22(&obj.DecomposedStrelArray->data[i1],
                                 &seq_DecomposedStrelArray_data[i1]);
    }
    strel_parenReference(&obj, (double)sInd + 1.0);
  }
  pre_pack = !strel_is_single;
  if (pre_pack && (!strel_isdecompositionorthogonal(se_StrelArray,
                                                    se_DecomposedStrelArray))) {
    pre_pad = true;
  } else {
    pre_pad = false;
  }
  pre_pack = (pre_pack && strel_is_all_flat);
  if (pre_pack) {
    fcnNameEnum = -1;
    libNameEnum = 1;
  } else {
    if (strel_is_single) {
      strel_is_all_flat = false;
      if ((se_StrelArray_data[0].nhood->size[0] == 3) &&
          (se_StrelArray_data[0].nhood->size[1] == 3)) {
        strel_is_all_flat = true;
      }
      if (strel_is_all_flat) {
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 9)) {
          if (!se_StrelArray_data[0].nhood->data[k]) {
            strel_is_all_flat = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (strel_is_all_flat) {
        fcnNameEnum = 10;
      } else {
        fcnNameEnum = 11;
      }
    } else {
      fcnNameEnum = 12;
    }
    libNameEnum = 5;
  }
  emxInit_boolean_T(&Apad, 2);
  if (pre_pad) {
    int pad_lr_size[2];
    int pad_ul_size[2];
    strel_getpadsize(se_StrelArray, se_DecomposedStrelArray, pad_ul_data,
                     pad_ul_size, pad_lr_data, pad_lr_size);
    emxInit_boolean_T(&Apadpre, 2);
    if ((A->size[0] == 0) || (A->size[1] == 0)) {
      sizeB[0] = (double)A->size[0] + pad_ul_data[0];
      sizeB[1] = (double)A->size[1] + pad_ul_data[1];
      i = Apadpre->size[0] * Apadpre->size[1];
      Apadpre->size[0] = (int)sizeB[0];
      Apadpre->size[1] = (int)sizeB[1];
      emxEnsureCapacity_boolean_T(Apadpre, i);
      Apadpre_data = Apadpre->data;
      offset = (int)sizeB[0] * (int)sizeB[1];
      for (i = 0; i < offset; i++) {
        Apadpre_data[i] = false;
      }
    } else {
      i = Apadpre->size[0] * Apadpre->size[1];
      Apadpre->size[0] = (int)((double)A->size[0] + pad_ul_data[0]);
      Apadpre->size[1] = (int)((double)A->size[1] + pad_ul_data[1]);
      emxEnsureCapacity_boolean_T(Apadpre, i);
      Apadpre_data = Apadpre->data;
      i = (int)pad_ul_data[1];
      for (j = 0; j < i; j++) {
        i1 = Apadpre->size[0];
        for (b_i = 0; b_i < i1; b_i++) {
          Apadpre_data[b_i + Apadpre->size[0] * j] = false;
        }
      }
      i = (int)pad_ul_data[1] + 1;
      i1 = Apadpre->size[1];
      for (j = i; j <= i1; j++) {
        i2 = (int)pad_ul_data[0];
        for (b_i = 0; b_i < i2; b_i++) {
          Apadpre_data[b_i + Apadpre->size[0] * (j - 1)] = false;
        }
      }
      i = A->size[1];
      i1 = A->size[0];
      for (j = 0; j < i; j++) {
        for (b_i = 0; b_i < i1; b_i++) {
          Apadpre_data[(b_i + (int)pad_ul_data[0]) +
                       Apadpre->size[0] * (j + (int)pad_ul_data[1])] =
              A_data[b_i + A->size[0] * j];
        }
      }
    }
    b_padarray(Apadpre, pad_lr_data, Apad);
    Apad_data = Apad->data;
    emxFree_boolean_T(&Apadpre);
  } else {
    i = Apad->size[0] * Apad->size[1];
    Apad->size[0] = A->size[0];
    Apad->size[1] = A->size[1];
    emxEnsureCapacity_boolean_T(Apad, i);
    Apad_data = Apad->data;
    offset = A->size[0] * A->size[1];
    for (i = 0; i < offset; i++) {
      Apad_data[i] = A_data[i];
    }
    pad_ul_data[0] = -1.0;
    pad_lr_data[0] = -1.0;
    pad_ul_data[1] = -1.0;
    pad_lr_data[1] = -1.0;
  }
  emxInit_uint32_T(&Apadpack);
  Apadpack_data = Apadpack->data;
  if (pre_pack) {
    numRows = Apad->size[0];
    offset = (int)ceil((double)Apad->size[0] / 32.0);
    if ((Apad->size[0] == 0) || (Apad->size[1] == 0)) {
      i = Apadpack->size[0] * Apadpack->size[1];
      Apadpack->size[0] = offset;
      Apadpack->size[1] = Apad->size[1];
      emxEnsureCapacity_uint32_T(Apadpack, i);
      Apadpack_data = Apadpack->data;
      offset *= Apad->size[1];
      for (i = 0; i < offset; i++) {
        Apadpack_data[i] = 0U;
      }
    } else {
      i = Apadpack->size[0] * Apadpack->size[1];
      Apadpack->size[0] = offset;
      Apadpack->size[1] = Apad->size[1];
      emxEnsureCapacity_uint32_T(Apadpack, i);
      Apadpack_data = Apadpack->data;
      sizeB[0] = Apad->size[0];
      sizeB[1] = Apad->size[1];
      bwpSize[0] = offset;
      bwpSize[1] = Apad->size[1];
      bwPackingtbb(&Apad_data[0], &sizeB[0], &Apadpack_data[0], &bwpSize[0],
                   true);
    }
    Apad->size[0] = 0;
    Apad->size[1] = 0;
  } else {
    numRows = -1;
    Apadpack->size[0] = 0;
    Apadpack->size[1] = 0;
  }
  emxInit_uint32_T(&Bpack);
  i = Bpack->size[0] * Bpack->size[1];
  Bpack->size[0] = Apadpack->size[0];
  Bpack->size[1] = Apadpack->size[1];
  emxEnsureCapacity_uint32_T(Bpack, i);
  Bpack_data = Bpack->data;
  i = B->size[0] * B->size[1];
  B->size[0] = Apad->size[0];
  B->size[1] = Apad->size[1];
  emxEnsureCapacity_boolean_T(B, i);
  Apadpre_data = B->data;
  i = seq_StrelArray->size[1];
  emxInit_boolean_T(&nhoodIn, 3);
  emxInit_real_T(&allheightIn, 3);
  emxInitStruct_strel(&b_obj);
  for (sInd = 0; sInd < i; sInd++) {
    double tmp;
    int tmp_tmp;
    i1 = obj.StrelArray->size[0] * obj.StrelArray->size[1];
    obj.StrelArray->size[0] = 1;
    offset = seq_StrelArray->size[1];
    obj.StrelArray->size[1] = seq_StrelArray->size[1];
    d_emxEnsureCapacity_images_inte(obj.StrelArray, i1);
    for (i1 = 0; i1 < offset; i1++) {
      c_emxCopyStruct_images_internal(&obj.StrelArray->data[i1],
                                      &seq_StrelArray_data[i1]);
    }
    i1 = obj.DecomposedStrelArray->size[0] * obj.DecomposedStrelArray->size[1];
    obj.DecomposedStrelArray->size[0] = 1;
    offset = seq_DecomposedStrelArray->size[1];
    obj.DecomposedStrelArray->size[1] = seq_DecomposedStrelArray->size[1];
    emxEnsureCapacity_cell_wrap_221(obj.DecomposedStrelArray, i1);
    for (i1 = 0; i1 < offset; i1++) {
      emxCopyStruct_cell_wrap_22(&obj.DecomposedStrelArray->data[i1],
                                 &seq_DecomposedStrelArray_data[i1]);
    }
    strel_parenReference(&obj, (double)sInd + 1.0);
    i1 = nhoodIn->size[0] * nhoodIn->size[1] * nhoodIn->size[2];
    nhoodIn->size[0] = obj.StrelArray->data[0].nhood->size[0];
    nhoodIn->size[1] = obj.StrelArray->data[0].nhood->size[1];
    nhoodIn->size[2] = 1;
    emxEnsureCapacity_boolean_T(nhoodIn, i1);
    nhoodIn_data = nhoodIn->data;
    offset = obj.StrelArray->data[0].nhood->size[0] *
             obj.StrelArray->data[0].nhood->size[1];
    for (i1 = 0; i1 < offset; i1++) {
      nhoodIn_data[i1] = obj.StrelArray->data[0].nhood->data[i1];
    }
    i1 = b_obj.StrelArray->size[0] * b_obj.StrelArray->size[1];
    b_obj.StrelArray->size[0] = 1;
    offset = seq_StrelArray->size[1];
    b_obj.StrelArray->size[1] = seq_StrelArray->size[1];
    d_emxEnsureCapacity_images_inte(b_obj.StrelArray, i1);
    for (i1 = 0; i1 < offset; i1++) {
      c_emxCopyStruct_images_internal(&b_obj.StrelArray->data[i1],
                                      &seq_StrelArray_data[i1]);
    }
    i1 = b_obj.DecomposedStrelArray->size[0] *
         b_obj.DecomposedStrelArray->size[1];
    b_obj.DecomposedStrelArray->size[0] = 1;
    offset = seq_DecomposedStrelArray->size[1];
    b_obj.DecomposedStrelArray->size[1] = seq_DecomposedStrelArray->size[1];
    emxEnsureCapacity_cell_wrap_221(b_obj.DecomposedStrelArray, i1);
    for (i1 = 0; i1 < offset; i1++) {
      emxCopyStruct_cell_wrap_22(&b_obj.DecomposedStrelArray->data[i1],
                                 &seq_DecomposedStrelArray_data[i1]);
    }
    strel_parenReference(&b_obj, (double)sInd + 1.0);
    i1 = allheightIn->size[0] * allheightIn->size[1] * allheightIn->size[2];
    allheightIn->size[0] = b_obj.StrelArray->data[0].height->size[0];
    allheightIn->size[1] = b_obj.StrelArray->data[0].height->size[1];
    allheightIn->size[2] = 1;
    emxEnsureCapacity_real_T(allheightIn, i1);
    allheightIn_data = allheightIn->data;
    loop_ub_tmp = b_obj.StrelArray->data[0].height->size[0] *
                  b_obj.StrelArray->data[0].height->size[1];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      allheightIn_data[i1] = b_obj.StrelArray->data[0].height->data[i1];
    }
    if (b_obj.StrelArray->data[0].height->size[0] > 1) {
      n = b_obj.StrelArray->data[0].height->size[0] - 1;
      nd2 = b_obj.StrelArray->data[0].height->size[0] >> 1;
      i1 = b_obj.StrelArray->data[0].height->size[1] - 1;
      for (j = 0; j <= i1; j++) {
        offset = j * allheightIn->size[0];
        for (k = 0; k < nd2; k++) {
          tmp_tmp = offset + k;
          tmp = allheightIn_data[tmp_tmp];
          i2 = (offset + n) - k;
          allheightIn_data[tmp_tmp] = allheightIn_data[i2];
          allheightIn_data[i2] = tmp;
        }
      }
    }
    if (allheightIn->size[1] > 1) {
      offset = allheightIn->size[0];
      n = allheightIn->size[1] - 1;
      nd2 = allheightIn->size[1] >> 1;
      i1 = allheightIn->size[0] - 1;
      for (b_i = 0; b_i <= i1; b_i++) {
        for (k = 0; k < nd2; k++) {
          tmp_tmp = b_i + k * offset;
          tmp = allheightIn_data[tmp_tmp];
          i2 = b_i + (n - k) * offset;
          allheightIn_data[tmp_tmp] = allheightIn_data[i2];
          allheightIn_data[i2] = tmp;
        }
      }
    }
    strel_is_all_flat = false;
    offset = 1;
    exitg1 = false;
    while ((!exitg1) && (offset <= loop_ub_tmp)) {
      if (allheightIn_data[offset - 1] != 0.0) {
        strel_is_all_flat = true;
        exitg1 = true;
      } else {
        offset++;
      }
    }
    if (strel_is_all_flat) {
      if (obj.StrelArray->data[0].nhood->size[0] > 1) {
        n = obj.StrelArray->data[0].nhood->size[0] - 1;
        nd2 = obj.StrelArray->data[0].nhood->size[0] >> 1;
        i1 = obj.StrelArray->data[0].nhood->size[1] - 1;
        for (j = 0; j <= i1; j++) {
          offset = j * nhoodIn->size[0];
          for (k = 0; k < nd2; k++) {
            tmp_tmp = offset + k;
            strel_is_all_flat = nhoodIn_data[tmp_tmp];
            i2 = (offset + n) - k;
            nhoodIn_data[tmp_tmp] = nhoodIn_data[i2];
            nhoodIn_data[i2] = strel_is_all_flat;
          }
        }
      }
      if (nhoodIn->size[1] > 1) {
        offset = nhoodIn->size[0];
        n = nhoodIn->size[1] - 1;
        nd2 = nhoodIn->size[1] >> 1;
        i1 = nhoodIn->size[0] - 1;
        for (b_i = 0; b_i <= i1; b_i++) {
          for (k = 0; k < nd2; k++) {
            tmp_tmp = b_i + k * offset;
            strel_is_all_flat = nhoodIn_data[tmp_tmp];
            i2 = b_i + (n - k) * offset;
            nhoodIn_data[tmp_tmp] = nhoodIn_data[i2];
            nhoodIn_data[i2] = strel_is_all_flat;
          }
        }
      }
    }
    if (pre_pack) {
      double nsizeT_data[3];
      sizeB[0] = Apadpack->size[0];
      nsizeT_data[0] = nhoodIn->size[0];
      sizeB[1] = Apadpack->size[1];
      nsizeT_data[1] = nhoodIn->size[1];
      dilate_packed_uint32(&Apadpack_data[0], &sizeB[0], 2.0, &nhoodIn_data[0],
                           &nsizeT_data[0], 2.0, &Bpack_data[0], true);
      i1 = Apadpack->size[0] * Apadpack->size[1];
      Apadpack->size[0] = Bpack->size[0];
      Apadpack->size[1] = Bpack->size[1];
      emxEnsureCapacity_uint32_T(Apadpack, i1);
      Apadpack_data = Apadpack->data;
      offset = Bpack->size[0] * Bpack->size[1];
      for (i1 = 0; i1 < offset; i1++) {
        Apadpack_data[i1] = Bpack_data[i1];
      }
    } else {
      if (libNameEnum == 5) {
        if (fcnNameEnum == 10) {
          double nsizeT_data[3];
          sizeB[0] = Apad->size[0];
          nsizeT_data[0] = nhoodIn->size[0];
          sizeB[1] = Apad->size[1];
          nsizeT_data[1] = nhoodIn->size[1];
          dilate_binary_ones33_tbb(&Apad_data[0], &sizeB[0], 2.0,
                                   &nhoodIn_data[0], &nsizeT_data[0], 2.0,
                                   &Apadpre_data[0]);
        } else if (fcnNameEnum == 11) {
          double nsizeT_data[3];
          sizeB[0] = Apad->size[0];
          nsizeT_data[0] = nhoodIn->size[0];
          sizeB[1] = Apad->size[1];
          nsizeT_data[1] = nhoodIn->size[1];
          dilate_binary_twod_tbb(&Apad_data[0], &sizeB[0], 2.0,
                                 &nhoodIn_data[0], &nsizeT_data[0], 2.0,
                                 &Apadpre_data[0]);
        } else if (fcnNameEnum == 12) {
          double nsizeT_data[3];
          sizeB[0] = Apad->size[0];
          nsizeT_data[0] = nhoodIn->size[0];
          sizeB[1] = Apad->size[1];
          nsizeT_data[1] = nhoodIn->size[1];
          dilate_binary_tbb(&Apad_data[0], &sizeB[0], 2.0, &nhoodIn_data[0],
                            &nsizeT_data[0], 2.0, &Apadpre_data[0]);
        }
      } else if (fcnNameEnum == 10) {
        double nsizeT_data[3];
        sizeB[0] = Apad->size[0];
        nsizeT_data[0] = nhoodIn->size[0];
        sizeB[1] = Apad->size[1];
        nsizeT_data[1] = nhoodIn->size[1];
        dilate_binary_ones33_tbb(&Apad_data[0], &sizeB[0], 2.0,
                                 &nhoodIn_data[0], &nsizeT_data[0], 2.0,
                                 &Apadpre_data[0]);
      } else if (fcnNameEnum == 11) {
        double nsizeT_data[3];
        sizeB[0] = Apad->size[0];
        nsizeT_data[0] = nhoodIn->size[0];
        sizeB[1] = Apad->size[1];
        nsizeT_data[1] = nhoodIn->size[1];
        dilate_binary_twod_tbb(&Apad_data[0], &sizeB[0], 2.0, &nhoodIn_data[0],
                               &nsizeT_data[0], 2.0, &Apadpre_data[0]);
      } else if (fcnNameEnum == 12) {
        double nsizeT_data[3];
        sizeB[0] = Apad->size[0];
        nsizeT_data[0] = nhoodIn->size[0];
        sizeB[1] = Apad->size[1];
        nsizeT_data[1] = nhoodIn->size[1];
        dilate_binary_tbb(&Apad_data[0], &sizeB[0], 2.0, &nhoodIn_data[0],
                          &nsizeT_data[0], 2.0, &Apadpre_data[0]);
      }
      i1 = Apad->size[0] * Apad->size[1];
      Apad->size[0] = B->size[0];
      Apad->size[1] = B->size[1];
      emxEnsureCapacity_boolean_T(Apad, i1);
      Apad_data = Apad->data;
      offset = B->size[0] * B->size[1];
      for (i1 = 0; i1 < offset; i1++) {
        Apad_data[i1] = Apadpre_data[i1];
      }
    }
  }
  emxFreeStruct_strel(&b_obj);
  emxFreeStruct_strel(&obj);
  emxFree_cell_wrap_22(&seq_DecomposedStrelArray);
  c_emxFree_images_internal_coder(&seq_StrelArray);
  emxFree_real_T(&allheightIn);
  emxFree_boolean_T(&nhoodIn);
  emxFree_uint32_T(&Apadpack);
  emxFree_boolean_T(&Apad);
  if (pre_pack) {
    if ((Bpack->size[0] == 0) || (Bpack->size[1] == 0)) {
      i = B->size[0] * B->size[1];
      B->size[0] = numRows;
      B->size[1] = Bpack->size[1];
      emxEnsureCapacity_boolean_T(B, i);
      Apadpre_data = B->data;
      offset = numRows * Bpack->size[1];
      for (i = 0; i < offset; i++) {
        Apadpre_data[i] = false;
      }
    } else {
      i = B->size[0] * B->size[1];
      B->size[0] = numRows;
      B->size[1] = Bpack->size[1];
      emxEnsureCapacity_boolean_T(B, i);
      Apadpre_data = B->data;
      bwpSize[0] = Bpack->size[0];
      sizeB[0] = numRows;
      bwpSize[1] = Bpack->size[1];
      sizeB[1] = Bpack->size[1];
      bwUnpackingtbb(&Bpack_data[0], &bwpSize[0], &Apadpre_data[0], &sizeB[0],
                     true);
    }
  }
  emxFree_uint32_T(&Bpack);
  if (pre_pad) {
    sizeB[0] =
        ((((pad_ul_data[0] + 1.0) + (double)B->size[0]) - pad_ul_data[0]) -
         pad_lr_data[0]) -
        1.0;
    sizeB[1] =
        ((((pad_ul_data[1] + 1.0) + (double)B->size[1]) - pad_ul_data[1]) -
         pad_lr_data[1]) -
        1.0;
    if (pad_ul_data[0] + 1.0 > sizeB[0]) {
      i = -1;
      i1 = -1;
    } else {
      i = (int)(pad_ul_data[0] + 1.0) - 2;
      i1 = (int)sizeB[0] - 1;
    }
    if (pad_ul_data[1] + 1.0 > sizeB[1]) {
      i2 = 0;
      n = 0;
    } else {
      i2 = (int)(pad_ul_data[1] + 1.0) - 1;
      n = (int)sizeB[1];
    }
    loop_ub_tmp = n - i2;
    for (n = 0; n < loop_ub_tmp; n++) {
      offset = i1 - i;
      for (nd2 = 0; nd2 < offset; nd2++) {
        Apadpre_data[nd2 + offset * n] =
            Apadpre_data[((i + nd2) + B->size[0] * (i2 + n)) + 1];
      }
    }
    i2 = B->size[0] * B->size[1];
    B->size[0] = i1 - i;
    B->size[1] = loop_ub_tmp;
    emxEnsureCapacity_boolean_T(B, i2);
  }
}

/* End of code generation (imdilate.c) */
