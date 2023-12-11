/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: imfil.c
 *
 * MATLAB Coder version            : 23.2
 * C/C++ source code generated on  : 26-Nov-2023 20:14:52
 */

/* Include Files */

#include "imdilate.h"
#include "size.h"

/* Function Definitions */
/*
 * UNTITLED Summary of this function goes here
 *    Detailed explanation goes here
 *
 * Arguments    : const unsigned char a[128]
 *                double *A
 *                double *B
 *                double *C
 *                double *omiga_par
 *                double *omiga_per
 * Return Type  : void
 */
void imdilate(unsigned char L[IMG_SIZE], int k) 
{
    int i, j, m, n;
    int tmp_id;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tmp_id = i * 10 + j;
            if (L[tmp_id] == 1U) {
                for (m = (-k+1)/2; m < 0; m++) {
                    for (n = (-k+1)/2; n <= k/2; n++) {
                        if ((i + m >= 0) && (j + n >= 0) && (j + n < 10)) {
                            L[(i + m) * 10 + (j + n)] = 1;
                        }
                    }
                }
                for (n = (-k+1)/2; n < 0; n++) {
                    if ((j + n >= 0)) {
                        L[i * 10 + (j + n)] = 1U;
                    }
                }
                for (n = 1; n <= k/2; n++) {
                    if ((j + n < 10) && L[i * 10 + (j + n)] != 1U) {
                        L[i * 10 + (j + n)] = 2U;
                    }
                }
                for (m = 1; m <= k/2; m++) {
                    for (n = (-k+1)/2; n <= k/2; n++) {
                        if ((i + m < 10) && (j + n >= 0) && (j + n < 10) && L[(i + m) * 10 + (j + n)] != 1U) {
                            L[(i + m) * 10 + (j + n)] = 1;
                        }
                    }
                }
            }
            else if (L[tmp_id] == 2U) {
                L[tmp_id] = 1U;
            }
        }
    }
}

/*
 * File trailer for imfil.c
 *
 * [EOF]
 */