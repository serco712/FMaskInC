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

#include "connected_components.h"

#include <math.h>
#include <string.h>

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
void connected_components(const double L[100], const double num_el, const int width,
        int sizes[MAX_REGION], double orin_x[100], double orin_y[100])
{
    double i_d = 1.0;
    int i_i;
    int x = 1;
    int y = 1;
    int j = 0;
    int l = 0;
    int s = 0;

    memset(sizes, 0, num_el*4);

    for (i_i = 0; i_i < num_el; i_i++) {
        for (j = 0; j < 100; j++) {
            if (L[j] == i_d) {
                orin_x[l] = x;
                orin_y[l] = y;
                l++;
                s++;
            }

            x++;
            if (x == width+1) {
                x = 1;
                y++;
            }
        }
        
        sizes[i_i] = s;
        i_d++;

        x = 0;
        y = 0;
        s = 0;
    }
}

/*
 * File trailer for imfil.c
 *
 * [EOF]
 */