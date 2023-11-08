/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * regionprops.c
 *
 * Code generation for function 'regionprops'
 *
 */

/* Include files */
#include "regionprops.h"
#include "Fmask_emxutil.h"
#include "Fmask_rtwutil.h"
#include "Fmask_types.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void ComputePixelIdxList(const emxArray_real_T *L, double numObjs,
                                c_emxArray_struct_T *stats);

static void initializeStatsStruct(double numObjs, c_emxArray_struct_T *stats);

/* Function Definitions */
static void ComputePixelIdxList(const emxArray_real_T *L, double numObjs,
                                c_emxArray_struct_T *stats)
{
  c_struct_T *stats_data;
  emxArray_int32_T *idxCount;
  emxArray_int32_T *idxCount_tmp;
  emxArray_real_T *regionIndices;
  emxArray_real_T *regionLengths;
  const double *L_data;
  double *regionIndices_data;
  double *regionLengths_data;
  int hi;
  int i;
  int ib;
  int k;
  int lastBlockLength;
  int nblocks;
  int *idxCount_data;
  int *idxCount_tmp_data;
  stats_data = stats->data;
  L_data = L->data;
  if (numObjs != 0.0) {
    double y;
    int idx;
    emxInit_real_T(&regionLengths, 1);
    idx = (int)numObjs;
    i = regionLengths->size[0];
    regionLengths->size[0] = (int)numObjs;
    emxEnsureCapacity_real_T(regionLengths, i);
    regionLengths_data = regionLengths->data;
    for (i = 0; i < idx; i++) {
      regionLengths_data[i] = 0.0;
    }
    i = L->size[1];
    for (lastBlockLength = 0; lastBlockLength < i; lastBlockLength++) {
      ib = L->size[0];
      for (hi = 0; hi < ib; hi++) {
        idx = (int)L_data[hi + L->size[0] * lastBlockLength];
        if (idx > 0) {
          regionLengths_data[idx - 1]++;
        }
      }
    }
    if (regionLengths->size[0] <= 1024) {
      idx = regionLengths->size[0];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      idx = 1024;
      nblocks = (int)((unsigned int)regionLengths->size[0] >> 10);
      lastBlockLength = regionLengths->size[0] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    y = regionLengths_data[0];
    for (k = 2; k <= idx; k++) {
      y += regionLengths_data[k - 1];
    }
    for (ib = 2; ib <= nblocks; ib++) {
      double bsum;
      idx = (ib - 1) << 10;
      bsum = regionLengths_data[idx];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        bsum += regionLengths_data[(idx + k) - 1];
      }
      y += bsum;
    }
    emxInit_real_T(&regionIndices, 1);
    i = regionIndices->size[0];
    regionIndices->size[0] = (int)y;
    emxEnsureCapacity_real_T(regionIndices, i);
    regionIndices_data = regionIndices->data;
    if (regionLengths->size[0] != 1) {
      i = regionLengths->size[0];
      for (k = 0; k <= i - 2; k++) {
        regionLengths_data[k + 1] += regionLengths_data[k];
      }
    }
    emxInit_int32_T(&idxCount_tmp, 1);
    i = idxCount_tmp->size[0];
    idxCount_tmp->size[0] = regionLengths->size[0] + 1;
    emxEnsureCapacity_int32_T(idxCount_tmp, i);
    idxCount_tmp_data = idxCount_tmp->data;
    idxCount_tmp_data[0] = 0;
    idx = regionLengths->size[0];
    for (i = 0; i < idx; i++) {
      idxCount_tmp_data[i + 1] = (int)regionLengths_data[i];
    }
    emxFree_real_T(&regionLengths);
    emxInit_int32_T(&idxCount, 1);
    i = idxCount->size[0];
    idxCount->size[0] = idxCount_tmp->size[0];
    emxEnsureCapacity_int32_T(idxCount, i);
    idxCount_data = idxCount->data;
    idx = idxCount_tmp->size[0];
    for (i = 0; i < idx; i++) {
      idxCount_data[i] = idxCount_tmp_data[i];
    }
    lastBlockLength = 1;
    i = L->size[1];
    for (hi = 0; hi < i; hi++) {
      ib = L->size[0];
      for (nblocks = 0; nblocks < ib; nblocks++) {
        idx = (int)L_data[nblocks + L->size[0] * hi] - 1;
        if (idx + 1 > 0) {
          idxCount_data[idx]++;
          regionIndices_data[idxCount_data[idx] - 1] = lastBlockLength;
        }
        lastBlockLength++;
      }
    }
    emxFree_int32_T(&idxCount);
    i = stats->size[0];
    for (k = 0; k < i; k++) {
      ib = idxCount_tmp_data[k + 1];
      if (idxCount_tmp_data[k] + 1 > ib) {
        hi = 0;
        ib = 0;
      } else {
        hi = idxCount_tmp_data[k];
      }
      idx = ib - hi;
      ib = stats_data[k].PixelIdxList->size[0];
      stats_data[k].PixelIdxList->size[0] = idx;
      emxEnsureCapacity_real_T(stats_data[k].PixelIdxList, ib);
      for (ib = 0; ib < idx; ib++) {
        stats_data[k].PixelIdxList->data[ib] = regionIndices_data[hi + ib];
      }
    }
    emxFree_int32_T(&idxCount_tmp);
    emxFree_real_T(&regionIndices);
  }
}

static void initializeStatsStruct(double numObjs, c_emxArray_struct_T *stats)
{
  c_struct_T statsOneObj;
  c_struct_T *stats_data;
  int i;
  int loop_ub_tmp;
  emxInitStruct_struct_T(&statsOneObj);
  statsOneObj.Area = 0.0;
  statsOneObj.Centroid[0] = 0.0;
  statsOneObj.Centroid[1] = 0.0;
  statsOneObj.BoundingBox[0] = 0.0;
  statsOneObj.BoundingBox[1] = 0.0;
  statsOneObj.BoundingBox[2] = 0.0;
  statsOneObj.BoundingBox[3] = 0.0;
  statsOneObj.MajorAxisLength = 0.0;
  statsOneObj.MinorAxisLength = 0.0;
  statsOneObj.Eccentricity = 0.0;
  statsOneObj.Orientation = 0.0;
  statsOneObj.Image.size[0] = 0;
  statsOneObj.Image.size[1] = 0;
  statsOneObj.FilledImage.size[0] = 0;
  statsOneObj.FilledImage.size[1] = 0;
  statsOneObj.FilledArea = 0.0;
  statsOneObj.EulerNumber = 0.0;
  memset(&statsOneObj.Extrema[0], 0, 16U * sizeof(double));
  statsOneObj.EquivDiameter = 0.0;
  statsOneObj.Extent = 0.0;
  statsOneObj.PixelIdxList->size[0] = 0;
  statsOneObj.PixelList->size[0] = 0;
  statsOneObj.PixelList->size[1] = 2;
  statsOneObj.Perimeter = 0.0;
  statsOneObj.Circularity = 0.0;
  statsOneObj.PixelValues.size[0] = 0;
  statsOneObj.MeanIntensity = 0.0;
  statsOneObj.MinIntensity = 0.0;
  statsOneObj.MaxIntensity = 0.0;
  statsOneObj.SubarrayIdx.size[0] = 1;
  statsOneObj.SubarrayIdx.size[1] = 0;
  statsOneObj.WeightedCentroid[0] = 0.0;
  statsOneObj.SubarrayIdxLengths[0] = 0.0;
  statsOneObj.WeightedCentroid[1] = 0.0;
  statsOneObj.SubarrayIdxLengths[1] = 0.0;
  loop_ub_tmp = (int)numObjs;
  i = stats->size[0];
  stats->size[0] = (int)numObjs;
  emxEnsureCapacity_struct_T1(stats, i);
  stats_data = stats->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    emxCopyStruct_struct_T(&stats_data[i], &statsOneObj);
  }
  emxFreeStruct_struct_T1(&statsOneObj);
}

void b_regionprops(const emxArray_real_T *varargin_1,
                   b_emxArray_struct_T *outstats)
{
  b_struct_T statsOneObj;
  b_struct_T *outstats_data;
  c_emxArray_struct_T *stats;
  c_struct_T *stats_data;
  emxArray_int32_T *v1;
  emxArray_int32_T *vk;
  const double *varargin_1_data;
  double numObjs;
  int i;
  int i1;
  unsigned int imageSize_idx_0;
  int k;
  int last_tmp;
  int *v1_data;
  int *vk_data;
  varargin_1_data = varargin_1->data;
  imageSize_idx_0 = (unsigned int)varargin_1->size[0];
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    numObjs = 0.0;
  } else {
    last_tmp = varargin_1->size[0] * varargin_1->size[1];
    if (last_tmp <= 2) {
      if (last_tmp == 1) {
        numObjs = varargin_1_data[0];
      } else {
        numObjs = varargin_1_data[last_tmp - 1];
        if (varargin_1_data[0] >= numObjs) {
          numObjs = varargin_1_data[0];
        }
      }
    } else {
      numObjs = varargin_1_data[0];
      for (k = 2; k <= last_tmp; k++) {
        double d;
        d = varargin_1_data[k - 1];
        if (numObjs < d) {
          numObjs = d;
        }
      }
    }
    numObjs = fmax(0.0, floor(numObjs));
  }
  emxInitStruct_struct_T1(&statsOneObj);
  statsOneObj.PixelList->size[0] = 0;
  statsOneObj.PixelList->size[1] = 2;
  last_tmp = (int)numObjs;
  i = outstats->size[0];
  outstats->size[0] = (int)numObjs;
  emxEnsureCapacity_struct_T2(outstats, i);
  outstats_data = outstats->data;
  for (i = 0; i < last_tmp; i++) {
    emxCopyStruct_struct_T1(&outstats_data[i], &statsOneObj);
  }
  emxFreeStruct_struct_T(&statsOneObj);
  emxInit_struct_T2(&stats);
  initializeStatsStruct(numObjs, stats);
  ComputePixelIdxList(varargin_1, numObjs, stats);
  stats_data = stats->data;
  i = stats->size[0];
  emxInit_int32_T(&v1, 1);
  emxInit_int32_T(&vk, 1);
  for (k = 0; k < i; k++) {
    last_tmp = stats_data[k].PixelIdxList->size[0];
    if (stats_data[k].PixelIdxList->size[0] != 0) {
      i1 = v1->size[0];
      v1->size[0] = stats_data[k].PixelIdxList->size[0];
      emxEnsureCapacity_int32_T(v1, i1);
      v1_data = v1->data;
      for (i1 = 0; i1 < last_tmp; i1++) {
        v1_data[i1] = (int)stats_data[k].PixelIdxList->data[i1] - 1;
      }
      i1 = vk->size[0];
      vk->size[0] = v1->size[0];
      emxEnsureCapacity_int32_T(vk, i1);
      vk_data = vk->data;
      last_tmp = v1->size[0];
      for (i1 = 0; i1 < last_tmp; i1++) {
        int i2;
        i2 = div_s32(v1_data[i1], (int)imageSize_idx_0);
        vk_data[i1] = i2;
        v1_data[i1] -= i2 * (int)imageSize_idx_0;
      }
      i1 = stats_data[k].PixelList->size[0] * stats_data[k].PixelList->size[1];
      stats_data[k].PixelList->size[0] = vk->size[0];
      stats_data[k].PixelList->size[1] = 2;
      emxEnsureCapacity_real_T(stats_data[k].PixelList, i1);
      last_tmp = vk->size[0];
      for (i1 = 0; i1 < last_tmp; i1++) {
        stats_data[k].PixelList->data[i1] = vk_data[i1] + 1;
        stats_data[k].PixelList->data[i1 + stats_data[k].PixelList->size[0]] =
            v1_data[i1] + 1;
      }
    } else {
      stats_data[k].PixelList->size[0] = 0;
      stats_data[k].PixelList->size[1] = 2;
    }
  }
  emxFree_int32_T(&vk);
  emxFree_int32_T(&v1);
  i = stats->size[0];
  for (k = 0; k < i; k++) {
    i1 = outstats_data[k].PixelList->size[0] *
         outstats_data[k].PixelList->size[1];
    outstats_data[k].PixelList->size[0] = stats_data[k].PixelList->size[0];
    outstats_data[k].PixelList->size[1] = 2;
    emxEnsureCapacity_real_T(outstats_data[k].PixelList, i1);
    i1 = stats_data[k].PixelList->size[0] << 1;
    for (last_tmp = 0; last_tmp < i1; last_tmp++) {
      outstats_data[k].PixelList->data[last_tmp] =
          stats_data[k].PixelList->data[last_tmp];
    }
  }
  emxFree_struct_T2(&stats);
}

void regionprops(const emxArray_real_T *varargin_1, emxArray_struct_T *outstats)
{
  c_emxArray_struct_T *stats;
  c_struct_T *stats_data;
  struct_T *outstats_data;
  const double *varargin_1_data;
  double numObjs;
  int i;
  int k;
  int last_tmp;
  varargin_1_data = varargin_1->data;
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    numObjs = 0.0;
  } else {
    last_tmp = varargin_1->size[0] * varargin_1->size[1];
    if (last_tmp <= 2) {
      if (last_tmp == 1) {
        numObjs = varargin_1_data[0];
      } else {
        numObjs = varargin_1_data[last_tmp - 1];
        if (varargin_1_data[0] >= numObjs) {
          numObjs = varargin_1_data[0];
        }
      }
    } else {
      numObjs = varargin_1_data[0];
      for (k = 2; k <= last_tmp; k++) {
        double d;
        d = varargin_1_data[k - 1];
        if (numObjs < d) {
          numObjs = d;
        }
      }
    }
    numObjs = fmax(0.0, floor(numObjs));
  }
  last_tmp = (int)numObjs;
  i = outstats->size[0];
  outstats->size[0] = (int)numObjs;
  emxEnsureCapacity_struct_T(outstats, i);
  outstats_data = outstats->data;
  for (i = 0; i < last_tmp; i++) {
    outstats_data[i].Area = 0.0;
  }
  emxInit_struct_T2(&stats);
  initializeStatsStruct(numObjs, stats);
  ComputePixelIdxList(varargin_1, numObjs, stats);
  stats_data = stats->data;
  i = stats->size[0];
  for (k = 0; k < i; k++) {
    stats_data[k].Area = stats_data[k].PixelIdxList->size[0];
  }
  i = stats->size[0];
  for (k = 0; k < i; k++) {
    outstats_data[k].Area = stats_data[k].Area;
  }
  emxFree_struct_T2(&stats);
}

/* End of code generation (regionprops.c) */
