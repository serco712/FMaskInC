/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: bwlabell.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 04-Dec-2023 22:23:48
 */

/* Include Files */
#include "bwlabel.h"
#include <math.h>

/* Function Declarations */
static double rt_roundd(double u);

/* Function Definitions */
/*
 * Arguments    : double u
 * Return Type  : double
 */
static double rt_roundd(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

/*
 * UNTITLED Summary of this function goes here
 *    Detailed explanation goes here
 *
 * Arguments    : const unsigned char A[100]
 *                double B[100]
 *                double *num
 * Return Type  : void
 */
void bwlabel(const unsigned char A[100], double B[100], double *num)
{
  double P[51];
  double d;
  double label;
  double rootj;
  int chunksSizeAndLabels[18];
  int b_i;
  int c;
  int chunksSizeAndLabels_tmp;
  int exitg1;
  int i;
  int i3;
  int r;
  int thread;
  P[0] = 0.0;
  for (thread = 0; thread < 2; thread++) {
    int firstLabel;
    int startC;
    c = thread * 5 + 1;
    chunksSizeAndLabels_tmp = (thread + 1) * 5;
    chunksSizeAndLabels[c - 1] = chunksSizeAndLabels_tmp + 1;
    label = floor((double)c / 2.0) * 5.0 + 1.0;
    firstLabel = (int)label;
    startC = c;
    i = thread * 5;
    b_i = chunksSizeAndLabels_tmp - i;
    for (chunksSizeAndLabels_tmp = 0; chunksSizeAndLabels_tmp < b_i;
         chunksSizeAndLabels_tmp++) {
      c = i + chunksSizeAndLabels_tmp;
      for (r = 0; r < 10; r++) {
        int i2;
        i2 = c + 10 * r;
        if (A[i2] != 0) {
          if ((c + 1 > startC) && (A[i2 - 1] != 0)) {
            B[i2] = B[i2 - 1];
          } else {
            int i4;
            bool guard1;
            bool guard2;
            bool guard3;
            bool guard4;
            guard1 = false;
            guard2 = false;
            guard3 = false;
            guard4 = false;
            if ((r + 1 < 10) && (c + 1 > startC)) {
              i3 = (c + 10 * (r + 1)) - 1;
              if (A[i3] != 0) {
                if ((c + 1 > startC) && (r + 1 > 1)) {
                  i4 = (c + 10 * (r - 1)) - 1;
                  if (A[i4] != 0) {
                    B[i2] = B[i4];
                    do {
                      exitg1 = 0;
                      d = B[i2];
                      rootj = P[(int)(d + 1.0) - 1];
                      if (rootj < d) {
                        B[i2] = rootj;
                      } else {
                        exitg1 = 1;
                      }
                    } while (exitg1 == 0);
                    if (B[i4] != B[i3]) {
                      rootj = B[i3];
                      while (P[(int)(rootj + 1.0) - 1] < rootj) {
                        rootj = P[(int)(rootj + 1.0) - 1];
                      }
                      if (d > rootj) {
                        B[i2] = rootj;
                      }
                      do {
                        exitg1 = 0;
                        d = B[i3];
                        rootj = P[(int)(d + 1.0) - 1];
                        if (rootj < d) {
                          P[(int)(d + 1.0) - 1] = B[i2];
                          B[i3] = rootj;
                        } else {
                          exitg1 = 1;
                        }
                      } while (exitg1 == 0);
                      P[(int)(d + 1.0) - 1] = B[i2];
                    }
                    do {
                      exitg1 = 0;
                      d = B[i4];
                      rootj = P[(int)(d + 1.0) - 1];
                      if (rootj < d) {
                        P[(int)(d + 1.0) - 1] = B[i2];
                        B[i4] = rootj;
                      } else {
                        exitg1 = 1;
                      }
                    } while (exitg1 == 0);
                    P[(int)(d + 1.0) - 1] = B[i2];
                  } else {
                    guard3 = true;
                  }
                } else {
                  guard3 = true;
                }
              } else {
                guard4 = true;
              }
            } else {
              guard4 = true;
            }
            if (guard4) {
              if ((c + 1 > startC) && (r + 1 > 1)) {
                i3 = (c + 10 * (r - 1)) - 1;
                if (A[i3] != 0) {
                  B[i2] = B[i3];
                } else {
                  guard2 = true;
                }
              } else {
                guard2 = true;
              }
            }
            if (guard3) {
              if (r + 1 > 1) {
                i4 = c + 10 * (r - 1);
                if (A[i4] != 0) {
                  B[i2] = B[i4];
                  do {
                    exitg1 = 0;
                    d = B[i2];
                    rootj = P[(int)(d + 1.0) - 1];
                    if (rootj < d) {
                      B[i2] = rootj;
                    } else {
                      exitg1 = 1;
                    }
                  } while (exitg1 == 0);
                  if (B[i4] != B[i3]) {
                    rootj = B[i3];
                    while (P[(int)(rootj + 1.0) - 1] < rootj) {
                      rootj = P[(int)(rootj + 1.0) - 1];
                    }
                    if (d > rootj) {
                      B[i2] = rootj;
                    }
                    do {
                      exitg1 = 0;
                      d = B[i3];
                      rootj = P[(int)(d + 1.0) - 1];
                      if (rootj < d) {
                        P[(int)(d + 1.0) - 1] = B[i2];
                        B[i3] = rootj;
                      } else {
                        exitg1 = 1;
                      }
                    } while (exitg1 == 0);
                    P[(int)(d + 1.0) - 1] = B[i2];
                  }
                  do {
                    exitg1 = 0;
                    d = B[i4];
                    rootj = P[(int)(d + 1.0) - 1];
                    if (rootj < d) {
                      P[(int)(d + 1.0) - 1] = B[i2];
                      B[i4] = rootj;
                    } else {
                      exitg1 = 1;
                    }
                  } while (exitg1 == 0);
                  P[(int)(d + 1.0) - 1] = B[i2];
                } else {
                  B[i2] = B[i3];
                }
              } else {
                B[i2] = B[i3];
              }
            }
            if (guard2) {
              if (r + 1 > 1) {
                i3 = c + 10 * (r - 1);
                if (A[i3] != 0) {
                  B[i2] = B[i3];
                } else {
                  guard1 = true;
                }
              } else {
                guard1 = true;
              }
            }
            if (guard1) {
              B[i2] = label;
              P[(int)(label + 1.0) - 1] = label;
              label++;
            }
          }
        } else {
          B[i2] = 0.0;
        }
      }
    }
    d = label - (double)firstLabel;
    if (d < 2.147483648E+9) {
      i = (int)d;
    } else {
      i = MAX_int32_T;
    }
    chunksSizeAndLabels[startC] = i;
  }
  for (c = chunksSizeAndLabels[0] - 1; c + 1 <= 10;
       c = chunksSizeAndLabels[c] - 1) {
    for (r = 0; r < 10; r++) {
      i = c + 10 * r;
      d = B[i];
      if (d != 0.0) {
        double root;
        if (r + 1 > 1) {
          label = B[(c + 10 * (r - 1)) - 1];
          if (label != 0.0) {
            root = label;
            while (P[(int)(root + 1.0) - 1] < root) {
              root = P[(int)(root + 1.0) - 1];
            }
            if (label != d) {
              rootj = B[i];
              while (P[(int)(rootj + 1.0) - 1] < rootj) {
                rootj = P[(int)(rootj + 1.0) - 1];
              }
              if (root > rootj) {
                root = rootj;
              }
              rootj = B[i];
              do {
                exitg1 = 0;
                d = P[(int)(rootj + 1.0) - 1];
                if (d < rootj) {
                  P[(int)(rootj + 1.0) - 1] = root;
                  rootj = d;
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              P[(int)(rootj + 1.0) - 1] = root;
            }
            do {
              exitg1 = 0;
              d = P[(int)(label + 1.0) - 1];
              if (d < label) {
                P[(int)(label + 1.0) - 1] = root;
                label = d;
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);
            P[(int)(label + 1.0) - 1] = root;
            B[i] = root;
          }
        }
        if (r + 1 < 10) {
          label = B[(c + 10 * (r + 1)) - 1];
          if (label != 0.0) {
            root = label;
            while (P[(int)(root + 1.0) - 1] < root) {
              root = P[(int)(root + 1.0) - 1];
            }
            if (label != B[i]) {
              rootj = B[i];
              while (P[(int)(rootj + 1.0) - 1] < rootj) {
                rootj = P[(int)(rootj + 1.0) - 1];
              }
              if (root > rootj) {
                root = rootj;
              }
              rootj = B[i];
              do {
                exitg1 = 0;
                d = P[(int)(rootj + 1.0) - 1];
                if (d < rootj) {
                  P[(int)(rootj + 1.0) - 1] = root;
                  rootj = d;
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              P[(int)(rootj + 1.0) - 1] = root;
            }
            do {
              exitg1 = 0;
              d = P[(int)(label + 1.0) - 1];
              if (d < label) {
                P[(int)(label + 1.0) - 1] = root;
                label = d;
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);
            P[(int)(label + 1.0) - 1] = root;
            B[i] = root;
          }
        }
        label = B[i - 1];
        if (label != 0.0) {
          root = label;
          while (P[(int)(root + 1.0) - 1] < root) {
            root = P[(int)(root + 1.0) - 1];
          }
          if (label != B[i]) {
            rootj = B[i];
            while (P[(int)(rootj + 1.0) - 1] < rootj) {
              rootj = P[(int)(rootj + 1.0) - 1];
            }
            if (root > rootj) {
              root = rootj;
            }
            rootj = B[i];
            do {
              exitg1 = 0;
              d = P[(int)(rootj + 1.0) - 1];
              if (d < rootj) {
                P[(int)(rootj + 1.0) - 1] = root;
                rootj = d;
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);
            P[(int)(rootj + 1.0) - 1] = root;
          }
          do {
            exitg1 = 0;
            d = P[(int)(label + 1.0) - 1];
            if (d < label) {
              P[(int)(label + 1.0) - 1] = root;
              label = d;
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);
          P[(int)(label + 1.0) - 1] = root;
          B[i] = root;
        }
      }
    }
  }
  rootj = 1.0;
  c = 1;
  while (c <= 10) {
    long long i1;
    if (c < -2147483647) {
      chunksSizeAndLabels_tmp = MIN_int32_T;
    } else {
      chunksSizeAndLabels_tmp = c - 1;
    }
    i1 = (long long)rt_roundd((double)chunksSizeAndLabels_tmp / 2.0) * 5LL;
    if (i1 > 2147483647LL) {
      i1 = 2147483647LL;
    } else if (i1 < -2147483648LL) {
      i1 = -2147483648LL;
    }
    i = (int)i1 + 2;
    chunksSizeAndLabels_tmp = chunksSizeAndLabels[c];
    if (((int)i1 + 1 < 0) &&
        (chunksSizeAndLabels_tmp < MAX_int32_T - (int)i1)) {
      chunksSizeAndLabels_tmp = MIN_int32_T;
    } else if (((int)i1 + 1 > 0) &&
               (chunksSizeAndLabels_tmp > 2147483646 - (int)i1)) {
      chunksSizeAndLabels_tmp = MAX_int32_T;
    } else {
      chunksSizeAndLabels_tmp = ((int)i1 + chunksSizeAndLabels_tmp) + 1;
    }
    for (b_i = i; b_i <= chunksSizeAndLabels_tmp; b_i++) {
      d = P[b_i - 1];
      if (d < (double)b_i - 1.0) {
        P[b_i - 1] = P[(int)(d + 1.0) - 1];
      } else {
        P[b_i - 1] = rootj;
        rootj++;
      }
    }
    c = chunksSizeAndLabels[c - 1];
  }
  *num = rootj - 1.0;
  for (c = 0; c < 10; c++) {
    for (r = 0; r < 10; r++) {
      chunksSizeAndLabels_tmp = c + 10 * r;
      B[chunksSizeAndLabels_tmp] =
          P[(int)(B[chunksSizeAndLabels_tmp] + 1.0) - 1];
    }
  }
}

/*
 * File trailer for bwlabell.c
 *
 * [EOF]
 */