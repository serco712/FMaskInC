/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bwlabel.c
 *
 * Code generation for function 'bwlabel'
 *
 */

/* Include files */
#include "bwlabel.h"
#include "Fmask_emxutil.h"
#include "Fmask_rtwutil.h"
#include "Fmask_types.h"
#include "omp.h"
#include <math.h>

/* Function Declarations */
static double b_labelingWu_parallel(const emxArray_boolean_T *im, double M,
                                    double N, emxArray_real_T *L);

static double labelingWu_parallel(const emxArray_uint8_T *im, double M,
                                  double N, emxArray_real_T *L);

/* Function Definitions */
static double b_labelingWu_parallel(const emxArray_boolean_T *im, double M,
                                    double N, emxArray_real_T *L)
{
  emxArray_int32_T *chunksSizeAndLabels;
  emxArray_real_T *P;
  double b_c;
  double c_tmp;
  double d;
  double firstLabel;
  double k;
  double label;
  double rootj;
  double stripeWidth;
  double *L_data;
  double *P_data;
  int c;
  int c_c;
  int exitg1;
  int i;
  int i1;
  int nParallelStripes;
  int qY;
  int r;
  int thread;
  int *chunksSizeAndLabels_data;
  const boolean_T *im_data;
  im_data = im->data;
  i = (int)M;
  qY = L->size[0] * L->size[1];
  L->size[0] = (int)M;
  L->size[1] = (int)N;
  emxEnsureCapacity_real_T(L, qY);
  L_data = L->data;
  emxInit_int32_T(&chunksSizeAndLabels, 1);
  qY = chunksSizeAndLabels->size[0];
  chunksSizeAndLabels->size[0] = (int)(N + 8.0);
  emxEnsureCapacity_int32_T(chunksSizeAndLabels, qY);
  chunksSizeAndLabels_data = chunksSizeAndLabels->data;
  nParallelStripes = (int)fmax(1.0, fmin(floor(N / 4.0), 8.0));
  stripeWidth = ceil(N / (double)nParallelStripes);
  emxInit_real_T(&P, 1);
  qY = P->size[0];
  P->size[0] = (int)(ceil(M * N / 2.0) + 1.0);
  emxEnsureCapacity_real_T(P, qY);
  P_data = P->data;
  P_data[0] = 0.0;
  nParallelStripes--;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    rootj, b_c, firstLabel, label, c_tmp, d, i1, c_c, r, exitg1)

  for (thread = 0; thread <= nParallelStripes; thread++) {
    c_tmp = (double)thread * stripeWidth + 1.0;
    d = ((double)thread + 1.0) * stripeWidth;
    rootj = rt_roundd(fmin(d + 1.0, N + 1.0));
    if (rootj < 2.147483648E+9) {
      if (rootj >= -2.147483648E+9) {
        i1 = (int)rootj;
      } else {
        i1 = MIN_int32_T;
      }
    } else {
      i1 = MAX_int32_T;
    }
    chunksSizeAndLabels_data[(int)c_tmp - 1] = i1;
    label = floor(c_tmp / 2.0) * floor((M + 1.0) / 2.0) + 1.0;
    firstLabel = label;
    i1 = (int)(fmin(d, N) + (1.0 - c_tmp));
    for (c_c = 0; c_c < i1; c_c++) {
      b_c = c_tmp + (double)c_c;
      for (r = 0; r < i; r++) {
        if (im_data[r + im->size[0] * ((int)b_c - 1)]) {
          if ((b_c > c_tmp) && im_data[r + im->size[0] * ((int)b_c - 2)]) {
            L_data[r + L->size[0] * ((int)b_c - 1)] =
                L_data[r + L->size[0] * ((int)b_c - 2)];
          } else if (((double)r + 1.0 < M) && (b_c > c_tmp) &&
                     im_data[(r + im->size[0] * ((int)b_c - 2)) + 1]) {
            if ((b_c > c_tmp) && ((unsigned int)r + 1U > 1U) &&
                im_data[(r + im->size[0] * ((int)b_c - 2)) - 1]) {
              L_data[r + L->size[0] * ((int)b_c - 1)] =
                  L_data[(r + L->size[0] * ((int)b_c - 2)) - 1];
              do {
                exitg1 = 0;
                d = L_data[r + L->size[0] * ((int)b_c - 1)];
                if (P_data[(int)(d + 1.0) - 1] < d) {
                  L_data[r + L->size[0] * ((int)b_c - 1)] =
                      P_data[(int)(d + 1.0) - 1];
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              rootj = L_data[(r + L->size[0] * ((int)b_c - 2)) + 1];
              if (L_data[(r + L->size[0] * ((int)b_c - 2)) - 1] != rootj) {
                while (P_data[(int)(rootj + 1.0) - 1] < rootj) {
                  rootj = P_data[(int)(rootj + 1.0) - 1];
                }
                if (d > rootj) {
                  L_data[r + L->size[0] * ((int)b_c - 1)] = rootj;
                }
                do {
                  exitg1 = 0;
                  d = L_data[(r + L->size[0] * ((int)b_c - 2)) + 1];
                  rootj = P_data[(int)(d + 1.0) - 1];
                  if (rootj < d) {
                    P_data[(int)(d + 1.0) - 1] =
                        L_data[r + L->size[0] * ((int)b_c - 1)];
                    L_data[(r + L->size[0] * ((int)b_c - 2)) + 1] = rootj;
                  } else {
                    exitg1 = 1;
                  }
                } while (exitg1 == 0);
                P_data[(int)(d + 1.0) - 1] =
                    L_data[r + L->size[0] * ((int)b_c - 1)];
              }
              do {
                exitg1 = 0;
                d = L_data[(r + L->size[0] * ((int)b_c - 2)) - 1];
                rootj = P_data[(int)(d + 1.0) - 1];
                if (rootj < d) {
                  P_data[(int)(d + 1.0) - 1] =
                      L_data[r + L->size[0] * ((int)b_c - 1)];
                  L_data[(r + L->size[0] * ((int)b_c - 2)) - 1] = rootj;
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              P_data[(int)(d + 1.0) - 1] =
                  L_data[r + L->size[0] * ((int)b_c - 1)];
            } else if (((unsigned int)r + 1U > 1U) &&
                       im_data[(r + im->size[0] * ((int)b_c - 1)) - 1]) {
              L_data[r + L->size[0] * ((int)b_c - 1)] =
                  L_data[(r + L->size[0] * ((int)b_c - 1)) - 1];
              do {
                exitg1 = 0;
                d = L_data[r + L->size[0] * ((int)b_c - 1)];
                if (P_data[(int)(d + 1.0) - 1] < d) {
                  L_data[r + L->size[0] * ((int)b_c - 1)] =
                      P_data[(int)(d + 1.0) - 1];
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              rootj = L_data[(r + L->size[0] * ((int)b_c - 2)) + 1];
              if (L_data[(r + L->size[0] * ((int)b_c - 1)) - 1] != rootj) {
                while (P_data[(int)(rootj + 1.0) - 1] < rootj) {
                  rootj = P_data[(int)(rootj + 1.0) - 1];
                }
                if (d > rootj) {
                  L_data[r + L->size[0] * ((int)b_c - 1)] = rootj;
                }
                do {
                  exitg1 = 0;
                  d = L_data[(r + L->size[0] * ((int)b_c - 2)) + 1];
                  rootj = P_data[(int)(d + 1.0) - 1];
                  if (rootj < d) {
                    P_data[(int)(d + 1.0) - 1] =
                        L_data[r + L->size[0] * ((int)b_c - 1)];
                    L_data[(r + L->size[0] * ((int)b_c - 2)) + 1] = rootj;
                  } else {
                    exitg1 = 1;
                  }
                } while (exitg1 == 0);
                P_data[(int)(d + 1.0) - 1] =
                    L_data[r + L->size[0] * ((int)b_c - 1)];
              }
              do {
                exitg1 = 0;
                d = L_data[(r + L->size[0] * ((int)b_c - 1)) - 1];
                rootj = P_data[(int)(d + 1.0) - 1];
                if (rootj < d) {
                  P_data[(int)(d + 1.0) - 1] =
                      L_data[r + L->size[0] * ((int)b_c - 1)];
                  L_data[(r + L->size[0] * ((int)b_c - 1)) - 1] = rootj;
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              P_data[(int)(d + 1.0) - 1] =
                  L_data[r + L->size[0] * ((int)b_c - 1)];
            } else {
              L_data[r + L->size[0] * ((int)b_c - 1)] =
                  L_data[(r + L->size[0] * ((int)b_c - 2)) + 1];
            }
          } else if ((b_c > c_tmp) && ((unsigned int)r + 1U > 1U) &&
                     im_data[(r + im->size[0] * ((int)b_c - 2)) - 1]) {
            L_data[r + L->size[0] * ((int)b_c - 1)] =
                L_data[(r + L->size[0] * ((int)b_c - 2)) - 1];
          } else if (((unsigned int)r + 1U > 1U) &&
                     im_data[(r + im->size[0] * ((int)b_c - 1)) - 1]) {
            L_data[r + L->size[0] * ((int)b_c - 1)] =
                L_data[(r + L->size[0] * ((int)b_c - 1)) - 1];
          } else {
            L_data[r + L->size[0] * ((int)b_c - 1)] = label;
            P_data[(int)(label + 1.0) - 1] = label;
            label++;
          }
        } else {
          L_data[r + L->size[0] * ((int)b_c - 1)] = 0.0;
        }
      }
    }
    d = label - firstLabel;
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        i1 = (int)d;
      } else {
        i1 = MIN_int32_T;
      }
    } else {
      i1 = MAX_int32_T;
    }
    chunksSizeAndLabels_data[(int)(c_tmp + 1.0) - 1] = i1;
  }
  for (c = chunksSizeAndLabels_data[0] - 1; c + 1 <= N;
       c = chunksSizeAndLabels_data[c] - 1) {
    for (nParallelStripes = 0; nParallelStripes < i; nParallelStripes++) {
      if (L_data[nParallelStripes + L->size[0] * c] != 0.0) {
        double b_i;
        double j;
        double root;
        if ((unsigned int)nParallelStripes + 1U > 1U) {
          b_i = L_data[(nParallelStripes + L->size[0] * (c - 1)) - 1];
          if (b_i != 0.0) {
            j = L_data[nParallelStripes + L->size[0] * c];
            root = b_i;
            while (P_data[(int)(root + 1.0) - 1] < root) {
              root = P_data[(int)(root + 1.0) - 1];
            }
            if (b_i != j) {
              stripeWidth = j;
              while (P_data[(int)(stripeWidth + 1.0) - 1] < stripeWidth) {
                stripeWidth = P_data[(int)(stripeWidth + 1.0) - 1];
              }
              if (root > stripeWidth) {
                root = stripeWidth;
              }
              do {
                exitg1 = 0;
                stripeWidth = P_data[(int)(j + 1.0) - 1];
                if (stripeWidth < j) {
                  P_data[(int)(j + 1.0) - 1] = root;
                  j = stripeWidth;
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              P_data[(int)(j + 1.0) - 1] = root;
            }
            do {
              exitg1 = 0;
              stripeWidth = P_data[(int)(b_i + 1.0) - 1];
              if (stripeWidth < b_i) {
                P_data[(int)(b_i + 1.0) - 1] = root;
                b_i = stripeWidth;
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);
            P_data[(int)(b_i + 1.0) - 1] = root;
            L_data[nParallelStripes + L->size[0] * c] = root;
          }
        }
        if ((double)nParallelStripes + 1.0 < M) {
          b_i = L_data[(nParallelStripes + L->size[0] * (c - 1)) + 1];
          if (b_i != 0.0) {
            j = L_data[nParallelStripes + L->size[0] * c];
            root = b_i;
            while (P_data[(int)(root + 1.0) - 1] < root) {
              root = P_data[(int)(root + 1.0) - 1];
            }
            if (b_i != j) {
              stripeWidth = j;
              while (P_data[(int)(stripeWidth + 1.0) - 1] < stripeWidth) {
                stripeWidth = P_data[(int)(stripeWidth + 1.0) - 1];
              }
              if (root > stripeWidth) {
                root = stripeWidth;
              }
              do {
                exitg1 = 0;
                stripeWidth = P_data[(int)(j + 1.0) - 1];
                if (stripeWidth < j) {
                  P_data[(int)(j + 1.0) - 1] = root;
                  j = stripeWidth;
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              P_data[(int)(j + 1.0) - 1] = root;
            }
            do {
              exitg1 = 0;
              stripeWidth = P_data[(int)(b_i + 1.0) - 1];
              if (stripeWidth < b_i) {
                P_data[(int)(b_i + 1.0) - 1] = root;
                b_i = stripeWidth;
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);
            P_data[(int)(b_i + 1.0) - 1] = root;
            L_data[nParallelStripes + L->size[0] * c] = root;
          }
        }
        b_i = L_data[nParallelStripes + L->size[0] * (c - 1)];
        if (b_i != 0.0) {
          j = L_data[nParallelStripes + L->size[0] * c];
          root = b_i;
          while (P_data[(int)(root + 1.0) - 1] < root) {
            root = P_data[(int)(root + 1.0) - 1];
          }
          if (b_i != j) {
            stripeWidth = j;
            while (P_data[(int)(stripeWidth + 1.0) - 1] < stripeWidth) {
              stripeWidth = P_data[(int)(stripeWidth + 1.0) - 1];
            }
            if (root > stripeWidth) {
              root = stripeWidth;
            }
            do {
              exitg1 = 0;
              stripeWidth = P_data[(int)(j + 1.0) - 1];
              if (stripeWidth < j) {
                P_data[(int)(j + 1.0) - 1] = root;
                j = stripeWidth;
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);
            P_data[(int)(j + 1.0) - 1] = root;
          }
          do {
            exitg1 = 0;
            stripeWidth = P_data[(int)(b_i + 1.0) - 1];
            if (stripeWidth < b_i) {
              P_data[(int)(b_i + 1.0) - 1] = root;
              b_i = stripeWidth;
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);
          P_data[(int)(b_i + 1.0) - 1] = root;
          L_data[nParallelStripes + L->size[0] * c] = root;
        }
      }
    }
  }
  k = 1.0;
  c = 1;
  while (c <= N) {
    int b_qY;
    if (c < -2147483647) {
      qY = MIN_int32_T;
    } else {
      qY = c - 1;
    }
    stripeWidth = rt_roundd((double)qY / 2.0) * floor((M + 1.0) / 2.0);
    if (stripeWidth < 2.147483648E+9) {
      if (stripeWidth >= -2.147483648E+9) {
        qY = (int)stripeWidth;
      } else {
        qY = MIN_int32_T;
      }
    } else {
      qY = MAX_int32_T;
    }
    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }
    if (qY > 2147483646) {
      b_qY = MAX_int32_T;
    } else {
      b_qY = qY + 1;
    }
    if (c > 2147483646) {
      nParallelStripes = MAX_int32_T;
    } else {
      nParallelStripes = c + 1;
    }
    nParallelStripes = chunksSizeAndLabels_data[nParallelStripes - 1];
    if ((qY < 0) && (nParallelStripes < MIN_int32_T - qY)) {
      qY = MIN_int32_T;
    } else if ((qY > 0) && (nParallelStripes > MAX_int32_T - qY)) {
      qY = MAX_int32_T;
    } else {
      qY += nParallelStripes;
    }
    for (nParallelStripes = b_qY; nParallelStripes <= qY; nParallelStripes++) {
      stripeWidth = P_data[nParallelStripes - 1];
      if (stripeWidth < (double)nParallelStripes - 1.0) {
        P_data[nParallelStripes - 1] = P_data[(int)(stripeWidth + 1.0) - 1];
      } else {
        P_data[nParallelStripes - 1] = k;
        k++;
      }
    }
    c = chunksSizeAndLabels_data[c - 1];
  }
  emxFree_int32_T(&chunksSizeAndLabels);
  k--;
  nParallelStripes = (int)N - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(r)

  for (c_c = 0; c_c <= nParallelStripes; c_c++) {
    for (r = 0; r < i; r++) {
      L_data[r + L->size[0] * c_c] =
          P_data[(int)(L_data[r + L->size[0] * c_c] + 1.0) - 1];
    }
  }
  emxFree_real_T(&P);
  return k;
}

static double labelingWu_parallel(const emxArray_uint8_T *im, double M,
                                  double N, emxArray_real_T *L)
{
  emxArray_int32_T *chunksSizeAndLabels;
  emxArray_real_T *P;
  double b_c;
  double c_tmp;
  double d;
  double firstLabel;
  double k;
  double label;
  double rootj;
  double stripeWidth;
  double *L_data;
  double *P_data;
  int c;
  int c_c;
  int exitg1;
  int i;
  int i1;
  int nParallelStripes;
  int qY;
  int r;
  int thread;
  int *chunksSizeAndLabels_data;
  const unsigned char *im_data;
  im_data = im->data;
  i = (int)M;
  qY = L->size[0] * L->size[1];
  L->size[0] = (int)M;
  L->size[1] = (int)N;
  emxEnsureCapacity_real_T(L, qY);
  L_data = L->data;
  emxInit_int32_T(&chunksSizeAndLabels, 1);
  qY = chunksSizeAndLabels->size[0];
  chunksSizeAndLabels->size[0] = (int)(N + 8.0);
  emxEnsureCapacity_int32_T(chunksSizeAndLabels, qY);
  chunksSizeAndLabels_data = chunksSizeAndLabels->data;
  nParallelStripes = (int)fmax(1.0, fmin(floor(N / 4.0), 8.0));
  stripeWidth = ceil(N / (double)nParallelStripes);
  emxInit_real_T(&P, 1);
  qY = P->size[0];
  P->size[0] = (int)(ceil(M * N / 2.0) + 1.0);
  emxEnsureCapacity_real_T(P, qY);
  P_data = P->data;
  P_data[0] = 0.0;
  nParallelStripes--;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    rootj, b_c, firstLabel, label, c_tmp, d, i1, c_c, r, exitg1)

  for (thread = 0; thread <= nParallelStripes; thread++) {
    c_tmp = (double)thread * stripeWidth + 1.0;
    d = ((double)thread + 1.0) * stripeWidth;
    rootj = rt_roundd(fmin(d + 1.0, N + 1.0));
    if (rootj < 2.147483648E+9) {
      if (rootj >= -2.147483648E+9) {
        i1 = (int)rootj;
      } else {
        i1 = MIN_int32_T;
      }
    } else {
      i1 = MAX_int32_T;
    }
    chunksSizeAndLabels_data[(int)c_tmp - 1] = i1;
    label = floor(c_tmp / 2.0) * floor((M + 1.0) / 2.0) + 1.0;
    firstLabel = label;
    i1 = (int)(fmin(d, N) + (1.0 - c_tmp));
    for (c_c = 0; c_c < i1; c_c++) {
      b_c = c_tmp + (double)c_c;
      for (r = 0; r < i; r++) {
        if (im_data[r + im->size[0] * ((int)b_c - 1)] != 0) {
          if ((b_c > c_tmp) &&
              (im_data[r + im->size[0] * ((int)b_c - 2)] != 0)) {
            L_data[r + L->size[0] * ((int)b_c - 1)] =
                L_data[r + L->size[0] * ((int)b_c - 2)];
          } else if (((double)r + 1.0 < M) && (b_c > c_tmp) &&
                     (im_data[(r + im->size[0] * ((int)b_c - 2)) + 1] != 0)) {
            if ((b_c > c_tmp) && ((unsigned int)r + 1U > 1U) &&
                (im_data[(r + im->size[0] * ((int)b_c - 2)) - 1] != 0)) {
              L_data[r + L->size[0] * ((int)b_c - 1)] =
                  L_data[(r + L->size[0] * ((int)b_c - 2)) - 1];
              do {
                exitg1 = 0;
                d = L_data[r + L->size[0] * ((int)b_c - 1)];
                if (P_data[(int)(d + 1.0) - 1] < d) {
                  L_data[r + L->size[0] * ((int)b_c - 1)] =
                      P_data[(int)(d + 1.0) - 1];
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              rootj = L_data[(r + L->size[0] * ((int)b_c - 2)) + 1];
              if (L_data[(r + L->size[0] * ((int)b_c - 2)) - 1] != rootj) {
                while (P_data[(int)(rootj + 1.0) - 1] < rootj) {
                  rootj = P_data[(int)(rootj + 1.0) - 1];
                }
                if (d > rootj) {
                  L_data[r + L->size[0] * ((int)b_c - 1)] = rootj;
                }
                do {
                  exitg1 = 0;
                  d = L_data[(r + L->size[0] * ((int)b_c - 2)) + 1];
                  rootj = P_data[(int)(d + 1.0) - 1];
                  if (rootj < d) {
                    P_data[(int)(d + 1.0) - 1] =
                        L_data[r + L->size[0] * ((int)b_c - 1)];
                    L_data[(r + L->size[0] * ((int)b_c - 2)) + 1] = rootj;
                  } else {
                    exitg1 = 1;
                  }
                } while (exitg1 == 0);
                P_data[(int)(d + 1.0) - 1] =
                    L_data[r + L->size[0] * ((int)b_c - 1)];
              }
              do {
                exitg1 = 0;
                d = L_data[(r + L->size[0] * ((int)b_c - 2)) - 1];
                rootj = P_data[(int)(d + 1.0) - 1];
                if (rootj < d) {
                  P_data[(int)(d + 1.0) - 1] =
                      L_data[r + L->size[0] * ((int)b_c - 1)];
                  L_data[(r + L->size[0] * ((int)b_c - 2)) - 1] = rootj;
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              P_data[(int)(d + 1.0) - 1] =
                  L_data[r + L->size[0] * ((int)b_c - 1)];
            } else if (((unsigned int)r + 1U > 1U) &&
                       (im_data[(r + im->size[0] * ((int)b_c - 1)) - 1] != 0)) {
              L_data[r + L->size[0] * ((int)b_c - 1)] =
                  L_data[(r + L->size[0] * ((int)b_c - 1)) - 1];
              do {
                exitg1 = 0;
                d = L_data[r + L->size[0] * ((int)b_c - 1)];
                if (P_data[(int)(d + 1.0) - 1] < d) {
                  L_data[r + L->size[0] * ((int)b_c - 1)] =
                      P_data[(int)(d + 1.0) - 1];
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              rootj = L_data[(r + L->size[0] * ((int)b_c - 2)) + 1];
              if (L_data[(r + L->size[0] * ((int)b_c - 1)) - 1] != rootj) {
                while (P_data[(int)(rootj + 1.0) - 1] < rootj) {
                  rootj = P_data[(int)(rootj + 1.0) - 1];
                }
                if (d > rootj) {
                  L_data[r + L->size[0] * ((int)b_c - 1)] = rootj;
                }
                do {
                  exitg1 = 0;
                  d = L_data[(r + L->size[0] * ((int)b_c - 2)) + 1];
                  rootj = P_data[(int)(d + 1.0) - 1];
                  if (rootj < d) {
                    P_data[(int)(d + 1.0) - 1] =
                        L_data[r + L->size[0] * ((int)b_c - 1)];
                    L_data[(r + L->size[0] * ((int)b_c - 2)) + 1] = rootj;
                  } else {
                    exitg1 = 1;
                  }
                } while (exitg1 == 0);
                P_data[(int)(d + 1.0) - 1] =
                    L_data[r + L->size[0] * ((int)b_c - 1)];
              }
              do {
                exitg1 = 0;
                d = L_data[(r + L->size[0] * ((int)b_c - 1)) - 1];
                rootj = P_data[(int)(d + 1.0) - 1];
                if (rootj < d) {
                  P_data[(int)(d + 1.0) - 1] =
                      L_data[r + L->size[0] * ((int)b_c - 1)];
                  L_data[(r + L->size[0] * ((int)b_c - 1)) - 1] = rootj;
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              P_data[(int)(d + 1.0) - 1] =
                  L_data[r + L->size[0] * ((int)b_c - 1)];
            } else {
              L_data[r + L->size[0] * ((int)b_c - 1)] =
                  L_data[(r + L->size[0] * ((int)b_c - 2)) + 1];
            }
          } else if ((b_c > c_tmp) && ((unsigned int)r + 1U > 1U) &&
                     (im_data[(r + im->size[0] * ((int)b_c - 2)) - 1] != 0)) {
            L_data[r + L->size[0] * ((int)b_c - 1)] =
                L_data[(r + L->size[0] * ((int)b_c - 2)) - 1];
          } else if (((unsigned int)r + 1U > 1U) &&
                     (im_data[(r + im->size[0] * ((int)b_c - 1)) - 1] != 0)) {
            L_data[r + L->size[0] * ((int)b_c - 1)] =
                L_data[(r + L->size[0] * ((int)b_c - 1)) - 1];
          } else {
            L_data[r + L->size[0] * ((int)b_c - 1)] = label;
            P_data[(int)(label + 1.0) - 1] = label;
            label++;
          }
        } else {
          L_data[r + L->size[0] * ((int)b_c - 1)] = 0.0;
        }
      }
    }
    d = label - firstLabel;
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        i1 = (int)d;
      } else {
        i1 = MIN_int32_T;
      }
    } else {
      i1 = MAX_int32_T;
    }
    chunksSizeAndLabels_data[(int)(c_tmp + 1.0) - 1] = i1;
  }
  for (c = chunksSizeAndLabels_data[0] - 1; c + 1 <= N;
       c = chunksSizeAndLabels_data[c] - 1) {
    for (nParallelStripes = 0; nParallelStripes < i; nParallelStripes++) {
      if (L_data[nParallelStripes + L->size[0] * c] != 0.0) {
        double b_i;
        double j;
        double root;
        if ((unsigned int)nParallelStripes + 1U > 1U) {
          b_i = L_data[(nParallelStripes + L->size[0] * (c - 1)) - 1];
          if (b_i != 0.0) {
            j = L_data[nParallelStripes + L->size[0] * c];
            root = b_i;
            while (P_data[(int)(root + 1.0) - 1] < root) {
              root = P_data[(int)(root + 1.0) - 1];
            }
            if (b_i != j) {
              stripeWidth = j;
              while (P_data[(int)(stripeWidth + 1.0) - 1] < stripeWidth) {
                stripeWidth = P_data[(int)(stripeWidth + 1.0) - 1];
              }
              if (root > stripeWidth) {
                root = stripeWidth;
              }
              do {
                exitg1 = 0;
                stripeWidth = P_data[(int)(j + 1.0) - 1];
                if (stripeWidth < j) {
                  P_data[(int)(j + 1.0) - 1] = root;
                  j = stripeWidth;
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              P_data[(int)(j + 1.0) - 1] = root;
            }
            do {
              exitg1 = 0;
              stripeWidth = P_data[(int)(b_i + 1.0) - 1];
              if (stripeWidth < b_i) {
                P_data[(int)(b_i + 1.0) - 1] = root;
                b_i = stripeWidth;
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);
            P_data[(int)(b_i + 1.0) - 1] = root;
            L_data[nParallelStripes + L->size[0] * c] = root;
          }
        }
        if ((double)nParallelStripes + 1.0 < M) {
          b_i = L_data[(nParallelStripes + L->size[0] * (c - 1)) + 1];
          if (b_i != 0.0) {
            j = L_data[nParallelStripes + L->size[0] * c];
            root = b_i;
            while (P_data[(int)(root + 1.0) - 1] < root) {
              root = P_data[(int)(root + 1.0) - 1];
            }
            if (b_i != j) {
              stripeWidth = j;
              while (P_data[(int)(stripeWidth + 1.0) - 1] < stripeWidth) {
                stripeWidth = P_data[(int)(stripeWidth + 1.0) - 1];
              }
              if (root > stripeWidth) {
                root = stripeWidth;
              }
              do {
                exitg1 = 0;
                stripeWidth = P_data[(int)(j + 1.0) - 1];
                if (stripeWidth < j) {
                  P_data[(int)(j + 1.0) - 1] = root;
                  j = stripeWidth;
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              P_data[(int)(j + 1.0) - 1] = root;
            }
            do {
              exitg1 = 0;
              stripeWidth = P_data[(int)(b_i + 1.0) - 1];
              if (stripeWidth < b_i) {
                P_data[(int)(b_i + 1.0) - 1] = root;
                b_i = stripeWidth;
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);
            P_data[(int)(b_i + 1.0) - 1] = root;
            L_data[nParallelStripes + L->size[0] * c] = root;
          }
        }
        b_i = L_data[nParallelStripes + L->size[0] * (c - 1)];
        if (b_i != 0.0) {
          j = L_data[nParallelStripes + L->size[0] * c];
          root = b_i;
          while (P_data[(int)(root + 1.0) - 1] < root) {
            root = P_data[(int)(root + 1.0) - 1];
          }
          if (b_i != j) {
            stripeWidth = j;
            while (P_data[(int)(stripeWidth + 1.0) - 1] < stripeWidth) {
              stripeWidth = P_data[(int)(stripeWidth + 1.0) - 1];
            }
            if (root > stripeWidth) {
              root = stripeWidth;
            }
            do {
              exitg1 = 0;
              stripeWidth = P_data[(int)(j + 1.0) - 1];
              if (stripeWidth < j) {
                P_data[(int)(j + 1.0) - 1] = root;
                j = stripeWidth;
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);
            P_data[(int)(j + 1.0) - 1] = root;
          }
          do {
            exitg1 = 0;
            stripeWidth = P_data[(int)(b_i + 1.0) - 1];
            if (stripeWidth < b_i) {
              P_data[(int)(b_i + 1.0) - 1] = root;
              b_i = stripeWidth;
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);
          P_data[(int)(b_i + 1.0) - 1] = root;
          L_data[nParallelStripes + L->size[0] * c] = root;
        }
      }
    }
  }
  k = 1.0;
  c = 1;
  while (c <= N) {
    int b_qY;
    if (c < -2147483647) {
      qY = MIN_int32_T;
    } else {
      qY = c - 1;
    }
    stripeWidth = rt_roundd((double)qY / 2.0) * floor((M + 1.0) / 2.0);
    if (stripeWidth < 2.147483648E+9) {
      if (stripeWidth >= -2.147483648E+9) {
        qY = (int)stripeWidth;
      } else {
        qY = MIN_int32_T;
      }
    } else {
      qY = MAX_int32_T;
    }
    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }
    if (qY > 2147483646) {
      b_qY = MAX_int32_T;
    } else {
      b_qY = qY + 1;
    }
    if (c > 2147483646) {
      nParallelStripes = MAX_int32_T;
    } else {
      nParallelStripes = c + 1;
    }
    nParallelStripes = chunksSizeAndLabels_data[nParallelStripes - 1];
    if ((qY < 0) && (nParallelStripes < MIN_int32_T - qY)) {
      qY = MIN_int32_T;
    } else if ((qY > 0) && (nParallelStripes > MAX_int32_T - qY)) {
      qY = MAX_int32_T;
    } else {
      qY += nParallelStripes;
    }
    for (nParallelStripes = b_qY; nParallelStripes <= qY; nParallelStripes++) {
      stripeWidth = P_data[nParallelStripes - 1];
      if (stripeWidth < (double)nParallelStripes - 1.0) {
        P_data[nParallelStripes - 1] = P_data[(int)(stripeWidth + 1.0) - 1];
      } else {
        P_data[nParallelStripes - 1] = k;
        k++;
      }
    }
    c = chunksSizeAndLabels_data[c - 1];
  }
  emxFree_int32_T(&chunksSizeAndLabels);
  k--;
  nParallelStripes = (int)N - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(r)

  for (c_c = 0; c_c <= nParallelStripes; c_c++) {
    for (r = 0; r < i; r++) {
      L_data[r + L->size[0] * c_c] =
          P_data[(int)(L_data[r + L->size[0] * c_c] + 1.0) - 1];
    }
  }
  emxFree_real_T(&P);
  return k;
}

double b_bwlabel(const emxArray_boolean_T *varargin_1, emxArray_real_T *L)
{
  double numComponents;
  double *L_data;
  int i;
  numComponents = 0.0;
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    int loop_ub;
    i = L->size[0] * L->size[1];
    L->size[0] = varargin_1->size[0];
    L->size[1] = varargin_1->size[1];
    emxEnsureCapacity_real_T(L, i);
    L_data = L->data;
    loop_ub = varargin_1->size[0] * varargin_1->size[1];
    for (i = 0; i < loop_ub; i++) {
      L_data[i] = 0.0;
    }
  } else {
    numComponents = b_labelingWu_parallel(varargin_1, varargin_1->size[0],
                                          varargin_1->size[1], L);
  }
  return numComponents;
}

void bwlabel(const emxArray_uint8_T *varargin_1, emxArray_real_T *L)
{
  double *L_data;
  int i;
  if ((varargin_1->size[0] == 0) || (varargin_1->size[1] == 0)) {
    int loop_ub;
    i = L->size[0] * L->size[1];
    L->size[0] = varargin_1->size[0];
    L->size[1] = varargin_1->size[1];
    emxEnsureCapacity_real_T(L, i);
    L_data = L->data;
    loop_ub = varargin_1->size[0] * varargin_1->size[1];
    for (i = 0; i < loop_ub; i++) {
      L_data[i] = 0.0;
    }
  } else {
    labelingWu_parallel(varargin_1, varargin_1->size[0], varargin_1->size[1],
                        L);
  }
}

/* End of code generation (bwlabel.c) */
