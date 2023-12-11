/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: imreconstruct.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 04-Dec-2023 17:32:24
 */

/* Include Files */
#include "imreconstruct.h"
#include "NeighborhoodProcessor.h"
#include "minOrMax.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : float marker[144]
 *                const float mask[144]
 * Return Type  : void
 */
void imreconstruct(float marker[144], const float mask[144])
{
  static const bool nhConn[9] = {false, true,  false, true, true,
                                 true,  false, true,  false};
  float marker_data[5];
  float f;
  int locationStack[288];
  int imnhSubs[10];
  int iv1[10];
  int imnhInds_[5];
  int imnhInds_data[5];
  int iv[5];
  int b_i;
  int i;
  int i1;
  int pInd;
  int partialTrueCount;
  int r;
  int stackTop;
  int z;
  unsigned char tmp_data[144];
  bool isInside[5];
  bool b;
  bool exitg1;
  partialTrueCount = 0;
  for (i = 0; i < 144; i++) {
    b_i = i % 12 * 12 + i / 12;
    if (marker[b_i] > mask[b_i]) {
      tmp_data[partialTrueCount] = (unsigned char)i;
      partialTrueCount++;
    }
  }
  partialTrueCount = 0;
  for (i = 0; i < 144; i++) {
    b_i = i % 12 * 12 + i / 12;
    if (marker[b_i] > mask[b_i]) {
      marker[b_i] = mask[tmp_data[partialTrueCount] % 12 * 12 +
                         tmp_data[partialTrueCount] / 12];
      partialTrueCount++;
    }
  }
  for (i = 0; i < 5; i++) {
    iv[i] = 0;
    imnhInds_[i] = 0;
  }
  for (b_i = 0; b_i < 10; b_i++) {
    iv1[b_i] = 0;
  }
  int iv2[2];
  int k[2];
  int pixelSub[2];
  iv2[0] = 12;
  iv2[1] = 12;
  c_NeighborhoodProcessor_compute(iv2, nhConn, iv, imnhInds_, iv1, pixelSub, k);
  b = true;
  b_i = 0;
  for (pInd = 0; pInd < 144; pInd++) {
    if (b) {
      b = false;
      b_i = pInd % 12 * 12 + pInd / 12;
    } else {
      b_i += 12;
      if (b_i > 143) {
        b_i -= 143;
      }
    }
    for (i = 0; i < 5; i++) {
      imnhInds_[i] = (iv[i] + pInd) + 1;
    }
    r = pInd - 12 * (pInd / 12);
    i = pInd - r;
    if (i >= 0) {
      partialTrueCount = i;
    } else {
      partialTrueCount = -i;
    }
    z = (unsigned char)partialTrueCount / 12;
    partialTrueCount -= z * 12;
    if (partialTrueCount >= 6) {
      z++;
    }
    if (i < 0) {
      z = -z;
    }
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      i = partialTrueCount << 1;
      imnhSubs[i] = (iv1[i] + r) + 1;
      imnhSubs[i + 1] = (iv1[i + 1] + z) + 1;
      isInside[partialTrueCount] = true;
    }
    r = 0;
    partialTrueCount = 0;
    for (z = 0; z < 5; z++) {
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 2)) {
        i1 = imnhSubs[i + (z << 1)];
        if ((i1 < 1) || (i1 > 12)) {
          isInside[z] = false;
          exitg1 = true;
        } else {
          i++;
        }
      }
      if (isInside[z]) {
        r++;
        imnhInds_data[partialTrueCount] = imnhInds_[z];
        partialTrueCount++;
      }
    }
    for (i1 = 0; i1 < r; i1++) {
      i = imnhInds_data[i1];
      marker_data[i1] = marker[(i - 1) % 12 * 12 + (i - 1) / 12];
    }
    marker[b_i] = fminf(fmaximum(marker_data, r), mask[b_i]);
  }
  stackTop = -1;
  b = true;
  b_i = 0;
  for (pInd = 143; pInd >= 0; pInd--) {
    if (b) {
      b = false;
      b_i = pInd % 12 * 12 + pInd / 12;
    } else {
      b_i += -12;
      if (b_i < 0) {
        b_i += 143;
      }
    }
    for (i = 0; i < 5; i++) {
      imnhInds_[i] = (iv[i] + pInd) + 1;
    }
    r = pInd - 12 * (pInd / 12);
    i = pInd - r;
    if (i >= 0) {
      partialTrueCount = i;
    } else {
      partialTrueCount = -i;
    }
    z = (unsigned char)partialTrueCount / 12;
    partialTrueCount -= z * 12;
    if (partialTrueCount >= 6) {
      z++;
    }
    if (i < 0) {
      z = -z;
    }
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      i = partialTrueCount << 1;
      imnhSubs[i] = (iv1[i] + r) + 1;
      imnhSubs[i + 1] = (iv1[i + 1] + z) + 1;
      isInside[partialTrueCount] = true;
    }
    r = 0;
    partialTrueCount = 0;
    for (z = 0; z < 5; z++) {
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 2)) {
        i1 = imnhSubs[i + (z << 1)];
        if ((i1 < 1) || (i1 > 12)) {
          isInside[z] = false;
          exitg1 = true;
        } else {
          i++;
        }
      }
      if (isInside[z]) {
        r++;
        imnhInds_data[partialTrueCount] = imnhInds_[z];
        partialTrueCount++;
      }
    }
    for (i1 = 0; i1 < r; i1++) {
      i = imnhInds_data[i1];
      marker_data[i1] = marker[(i - 1) % 12 * 12 + (i - 1) / 12];
    }
    marker[b_i] = fminf(fmaximum(marker_data, r), mask[b_i]);
    z = 0;
    exitg1 = false;
    while ((!exitg1) && (z <= r - 1)) {
      i1 = (imnhInds_data[z] - 1) % 12 * 12 + (imnhInds_data[z] - 1) / 12;
      f = marker[i1];
      if ((f < marker[b_i]) && (f < mask[i1])) {
        stackTop++;
        locationStack[stackTop] = pInd + 1;
        exitg1 = true;
      } else {
        z++;
      }
    }
  }
  while (stackTop + 1 > 0) {
    pInd = locationStack[stackTop] - 1;
    stackTop--;
    for (i = 0; i < 5; i++) {
      imnhInds_[i] = (iv[i] + pInd) + 1;
    }
    r = pInd - 12 * (pInd / 12);
    i = pInd - r;
    if (i >= 0) {
      partialTrueCount = i;
    } else if (i == MIN_int32_T) {
      partialTrueCount = MAX_int32_T;
    } else {
      partialTrueCount = -i;
    }
    z = (unsigned char)partialTrueCount / 12;
    partialTrueCount -= z * 12;
    if (partialTrueCount >= 6) {
      z++;
    }
    if (i < 0) {
      z = -z;
    }
    for (partialTrueCount = 0; partialTrueCount < 5; partialTrueCount++) {
      i = partialTrueCount << 1;
      imnhSubs[i] = (iv1[i] + r) + 1;
      imnhSubs[i + 1] = (iv1[i + 1] + z) + 1;
      isInside[partialTrueCount] = true;
    }
    r = 0;
    partialTrueCount = 0;
    for (z = 0; z < 5; z++) {
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 2)) {
        b_i = imnhSubs[i + (z << 1)];
        if ((b_i < 1) || (b_i > 12)) {
          isInside[z] = false;
          exitg1 = true;
        } else {
          i++;
        }
      }
      if (isInside[z]) {
        r++;
        imnhInds_data[partialTrueCount] = imnhInds_[z];
        partialTrueCount++;
      }
    }
    for (z = 0; z < r; z++) {
      float f1;
      b_i = imnhInds_data[z];
      i1 = (b_i - 1) % 12 * 12 + (b_i - 1) / 12;
      f = marker[i1];
      f1 = marker[pInd % 12 * 12 + pInd / 12];
      if (f < f1) {
        float f2;
        f2 = mask[i1];
        if (f != f2) {
          marker[i1] = fminf(f1, f2);
          stackTop++;
          locationStack[stackTop] = b_i;
        }
      }
    }
  }
}

/*
 * File trailer for imreconstruct.c
 *
 * [EOF]
 */
