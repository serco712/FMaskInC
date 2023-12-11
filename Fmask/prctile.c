/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: percentil.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 25-Nov-2023 20:17:30
 */

/* Include Files */
#include "prctile.h"

#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * UNTITLED Summary of this function goes here
 *    Detailed explanation goes here
 *
 * Arguments    : const float A[IMG_SIZE_ITER]
 *                const bool L[IMG_SIZE_ITER]
 *                float prc
 * Return Type  : float
 */

// static double rt_roundd(double u)
// {
//   double y;
//   if (fabs(u) < 4.503599627370496E+15) {
//     if (u >= 0.5) {
//       y = floor(u + 0.5);
//     } else if (u > -0.5) {
//       y = 0.0;
//     } else {
//       y = ceil(u - 0.5);
//     }
//   } else {
//     y = u;
//   }
//   return y;
// }

float prctile(const float A[IMG_SIZE_ITER], const unsigned char B[IMG_SIZE_ITER], double pt)
{
  float x_data[100];
  float C;
  int b_tmp_data[100];
  int idx_data[100];
  int iwork_data[100];
  int b_i;
  int i;
  int k;
  int pEnd;
  int partialTrueCount;
  int qEnd;
  int trueCount;
  signed char tmp_data[100];
  trueCount = 0;
  partialTrueCount = 0;
  for (i = 0; i < 100; i++) {
    if (B[i % 10 * 10 + i / 10]) {
      trueCount++;
      tmp_data[partialTrueCount] = (signed char)i;
      partialTrueCount++;
    }
  }
  for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++) {
    b_i = tmp_data[partialTrueCount];
    x_data[partialTrueCount] = A[b_i % 10 * 10 + b_i / 10];
  }
  if (trueCount == 0) {
    C = 0.0F;
  } else {
    memset(&idx_data[0], 0, (unsigned int)trueCount * sizeof(int));
    memset(&b_tmp_data[0], 0, (unsigned int)trueCount * sizeof(int));
    partialTrueCount = trueCount - 1;
    for (k = 1; k <= partialTrueCount; k += 2) {
      if (x_data[k - 1] <= x_data[k]) {
        b_tmp_data[k - 1] = k;
        b_tmp_data[k] = k + 1;
      } else {
        b_tmp_data[k - 1] = k + 1;
        b_tmp_data[k] = k;
      }
    }
    if ((trueCount & 1) != 0) {
      b_tmp_data[trueCount - 1] = trueCount;
    }
    i = 2;
    while (i < trueCount) {
      int i2;
      int j;
      i2 = i << 1;
      j = 1;
      for (pEnd = i + 1; pEnd < trueCount + 1; pEnd = qEnd + i) {
        int kEnd;
        int p;
        int q;
        p = j;
        q = pEnd;
        qEnd = j + i2;
        if (qEnd > trueCount + 1) {
          qEnd = trueCount + 1;
        }
        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          partialTrueCount = b_tmp_data[p - 1];
          b_i = b_tmp_data[q - 1];
          if (x_data[partialTrueCount - 1] <= x_data[b_i - 1]) {
            iwork_data[k] = partialTrueCount;
            p++;
            if (p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork_data[k] = b_tmp_data[q - 1];
                q++;
              }
            }
          } else {
            iwork_data[k] = b_i;
            q++;
            if (q == qEnd) {
              while (p < pEnd) {
                k++;
                iwork_data[k] = b_tmp_data[p - 1];
                p++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          b_tmp_data[(j + k) - 1] = iwork_data[k];
        }
        j = qEnd;
      }
      i = i2;
    }
    memcpy(&idx_data[0], &b_tmp_data[0], (unsigned int)trueCount * sizeof(int));
    if (trueCount == 1) {
      C = x_data[idx_data[0] - 1];
    } else {
      float c_i;
      float r;
      r = 100.0F * pt / 100.0F * (float)trueCount;
      c_i = roundf(r);
      if (c_i < 1.0F) {
        C = x_data[idx_data[0] - 1];
      } else if ((c_i >= 2.14748365E+9F) ||
                 ((c_i >= -2.14748365E+9F) && (trueCount <= (int)c_i))) {
        C = x_data[idx_data[trueCount - 1] - 1];
      } else {
        r -= c_i;
        C = (0.5F - r) * x_data[idx_data[(int)c_i - 1] - 1] +
            (r + 0.5F) * x_data[idx_data[(int)(c_i + 1.0F) - 1] - 1];
      }
    }
  }
  return C;
}

/*
 * File trailer for percentil.c
 *
 * [EOF]
 */