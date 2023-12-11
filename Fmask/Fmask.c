/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Fmask.c
 *
 * Code generation for function 'Fmask'
 *
 */

/* Include files */
#include "Fmask.h"
#include "fcssm.h"
#include "data/data.h"
#include "plcoud.h"
#include "space.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

struct tData data;

unsigned char Cloud_mask[IMG_SIZE];
unsigned char Shadow_mask[IMG_SIZE];
unsigned char Water_mask[IMG_SIZE];
unsigned char Snow_mask[IMG_SIZE];

/* Function Definitions */
double Fmask(double cldpix, double sdpix, double snpix, double cldprob,
             double num_Lst, const double Lmax[9], const double Lmin[9],
             const double Qcalmax[9], const double Qcalmin[9],
             const double Refmax[7], const double Refmin[7],
             const double ijdim_ref[2], const double ijdim_thm[2],
             const double reso_ref[2], const double reso_thm[2],
             const double ul[2], double zen, double azi, const double zc[2],
             double Lnum, double doy)
{
  double clr_pct;
  float ptm = 0.0F;
  double ptm_d;
  int i;
  int j;
  int pos = 0;
  int n_iter = 1;
  int d = 0;

  float *im_B1_data = NULL;
  float *im_B2_data = NULL;
  float *im_B3_data = NULL;
  float *im_B4_data = NULL;
  float *im_B5_data = NULL;
  float *im_B7_data = NULL;

  unsigned char *Cloud_m_pointer = Cloud_mask;
  unsigned char *Water_m_pointer = Water_mask;
  unsigned char *Shadow_m_pointer = Shadow_mask;
  unsigned char *Snow_m_pointer = Snow_mask;

  im_B1_data = data.TOA_fdata;
  im_B2_data = &data.TOA_fdata[IMG_SIZE_ITER];
  im_B3_data = &data.TOA_fdata[IMG_SIZE_ITER*2];
  im_B4_data = &data.TOA_fdata[IMG_SIZE_ITER*3];
  im_B5_data = &data.TOA_fdata[IMG_SIZE_ITER*4];
  im_B7_data = &data.TOA_fdata[IMG_SIZE_ITER*5];

  printf("Antes de empezar\n");

  for (i = 0; i < IMG_SIZE_ITER; i++) {
    im_B1_data[i] = band1[i];
    im_B2_data[i] = band2[i];
    im_B3_data[i] = band3[i];
    im_B4_data[i] = band4[i];
    im_B5_data[i] = band5[i];
    im_B7_data[i] = band7[i];
  }
  


  ptm += plcloud(cldpix, sdpix, snpix, cldprob, num_Lst, Lmax, Lmin, Qcalmax, Qcalmin,
      Refmax, Refmin, ijdim_ref, ijdim_thm, reso_ref, reso_thm, ul, zen, azi, zc,
      Lnum, doy, im_B1_data, im_B2_data, im_B3_data,im_B4_data,
      im_B5_data, im_B7_data, Cloud_m_pointer, Shadow_m_pointer, Water_m_pointer,
      Snow_m_pointer, &data);

  // for (i = 0; i < IMG_SIZE_ITER; i++) {
  //   if (Cloud_m_pointer[i] == 1U)
  //     printf("Un pixel de nube\n");
  // }

  //   Cloud_m_pointer += IMG_SIZE_ITER;
  //   Water_m_pointer += IMG_SIZE_ITER;
  //   Shadow_m_pointer += IMG_SIZE_ITER;
  //   Snow_m_pointer += IMG_SIZE_ITER;
  //   pos += IMG_SIZE_ITER;
  // }

  printf("Fin del bucle\n");

  for (i = 0; i < IMG_SIZE; i++) {
    d += Cloud_mask[i];
  }

  printf("La suma es %d\n", d);

  //ptm_d = ((double)ptm)/((double)n_iter);
  clr_pct = fcssm(zen, azi, (double)ptm, Water_mask, Snow_mask, Cloud_mask, Shadow_mask, ijdim_ref,
                  reso_ref, cldpix, sdpix, snpix, &data);


  /*  toc */
  return clr_pct;
}

/* End of code generation (Fmask.c) */
