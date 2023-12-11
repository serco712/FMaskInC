/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * plcloud.h
 *
 *
 */

#ifndef PLCLOUD_H
#define PLCLOUD_H

/* Include files */
#include "rtwtypes.h"
#include "space.h"


#ifdef __cplusplus
extern "C" {
#endif


// unsigned char aux_udata1[IMG_SIZE_ITER];
// unsigned char aux_udata2[IMG_SIZE_ITER];
// unsigned char aux_udata3[IMG_SIZE_ITER];
// unsigned char aux_udata4[IMG_SIZE_ITER];
// unsigned char aux_udata5[IMG_SIZE_ITER];
// unsigned char aux_udata6[IMG_SIZE_ITER];


/* Function Declarations */
float plcloud(double cldpix, double sdpix, double snpix, double cldprob,
             double num_Lst, const double Lmax[9], const double Lmin[9],
             const double Qcalmax[9], const double Qcalmin[9],
             const double Refmax[7], const double Refmin[7],
             const double ijdim_ref[2], const double ijdim_thm[2],
             const double reso_ref[2], const double reso_thm[2],
             const double ul[2], double zen, double azi, const double zc[2],
             double Lnum, double doy, float *im_B1_data, float *im_B2_data, float *im_B3_data,
             float *im_B4_data, float *im_B5_data, float *im_B7_data, 
             unsigned char Cloud[IMG_SIZE_ITER], unsigned char Shadow[IMG_SIZE_ITER], 
             unsigned char Water[IMG_SIZE_ITER], unsigned char Snow[IMG_SIZE_ITER],
             struct tData *data);

#ifdef __cplusplus
}
#endif

#endif
