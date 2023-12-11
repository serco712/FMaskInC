/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * plcloud.c
 *
 *
 */

/* Include files */
//#include "fcssm.h"
#include "imfill.h"
#include "minOrMax.h"
#include "nd2toarbt.h"
#include "plcoud.h"
#include "prctile.h"

#include <math.h>
#include <stdio.h>

/* Function Definitions */
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
             struct tData *data)
{

  int debug = 0;
  printf("%d\n", debug);
  debug++;

  unsigned char *aux_bdata1 = data->aux_bdata1;
  unsigned char *aux_bdata2 = data->aux_bdata2;
  unsigned char *aux_bdata3 = data->aux_bdata3;
  unsigned char *aux_bdata4 = data->aux_bdata4;
  unsigned char *aux_bdata5 = data->aux_bdata5;

  float *aux_fdata1 = data->aux_fdata1;
  float *aux_fdata2 = data->aux_fdata2;
  float *aux_fdata3 = data->aux_fdata3;
  float *aux_fdata4 = data->aux_fdata4;

  double *aux_ddata1 = data->aux_ddata1;

  // double ddata1[IMG_SIZE];
  // double ddata2[IMG_SIZE];
  // double ddata3[IMG_SIZE];
  // double ddata4[IMG_SIZE];
  // double ddata5[IMG_SIZE];

  int *idata1 = data->idata1;
  int *idata2 = data->idata2;
  int *idata3 = data->idata3;
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%constants%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  low percent */
  double l_pt = 0.175;
  /*  high percent */
  double  h_pt = 1-l_pt;

  float *im_B9_data = NULL;

  float *TOAref = NULL;

  float *NDSI_data = NULL;
  float *NDVI_data = NULL;
  float *Thin_prob_data = NULL;
  float *visimean_data = NULL;
  float *whiteness_data = NULL;
  float *HOT_data = NULL;
  float *Ratio4_5 = NULL; 
  float *Brightness_prob = NULL;
  float *Vari_prob_data = NULL;
  float *wfinal_prob_data = NULL;
  float *final_prob_data = NULL;

  float *nir_data = NULL;
  float *swir_data = NULL;

  float float_aux;

  double resolu[4];

  double clr_pct;
  
  float ptm = 0;
  float sum_mask = 0;
  float t_bright;

  float clr_max;
  float wclr_max;

  float backg_B4;
  float backg_B5;

  int i;
  int j;

  unsigned char *Cloud_data;
  unsigned char *Shadow_data;
  unsigned char *Snow_data;
  unsigned char *Water_data;

  unsigned char *idclr_data = NULL;
  unsigned char *idplcd_data = NULL;
  unsigned char *idlnd_data = NULL;
  unsigned char *idwt_data = NULL;
  unsigned char *mask_data = NULL;
  unsigned char *satu_B1_data = NULL;
  unsigned char *satu_B2_data = NULL;
  unsigned char *satu_B3_data = NULL;
  unsigned char *satu_Bv_data = NULL;
  unsigned char *id_final_cld_data = NULL;

  printf("%d\n", debug);
  debug++;

  Cloud_data = Cloud;
  Shadow_data = Shadow;
  Snow_data = Snow;
  Water_data = Water;

  NDVI_data = aux_fdata1;
  NDSI_data = aux_fdata2;

  Vari_prob_data = aux_fdata1;
  wfinal_prob_data = aux_fdata2;

  satu_B1_data = aux_bdata1;
  satu_B2_data = aux_bdata2;
  satu_B3_data = aux_bdata3;

  idlnd_data = aux_bdata2;
  idwt_data = aux_bdata3;

  satu_Bv_data = aux_bdata1;

  idclr_data = aux_bdata1;
  
  mask_data = aux_bdata4;

  idplcd_data = aux_bdata5;

  id_final_cld_data = aux_bdata3;

  final_prob_data = im_B7_data;
  Thin_prob_data = im_B1_data;
  Brightness_prob = im_B2_data;

  nir_data = im_B3_data;
  swir_data = im_B4_data;

  HOT_data = aux_fdata3;
  Ratio4_5 = aux_fdata3;
  visimean_data = aux_fdata3;
  whiteness_data = aux_fdata4;

  printf("%d\n", debug);
  debug++;

  /*  3.0 stand alone version */
  /*  Output image data description: */
  /*  This algorithm provide mask for cloud, cloud Shadow, Snow, Land, and
   * Water. */
  /*  bsq ENVI readable '*Fmask' image */
  /*  tic */
  /*  Function for potential Cloud, cloud Shadow, and Snow Masking 3.2v */
  /*  Works for Sentinel 2 */
  /*  */
  /*  History of revisions: */
  /*  Remove the split window method in cirrus cloud detection (Zhe 10/29/2013)
   */
  /*  Add dynamic water threshold (Zhe 10/27/2013) */
  /*  Remove majority filter (Zhe 10/27/2013) */
  /*  Fix bugs in probs < 0 (Brightness_prob & wTemp_prob) (Zhe 09/11/2013) */
  /*  Capable of processing Landsat 4~7 images (Zhe 09/09/2013) */
  /*  Use metadata to covert DN to TOA ref (Zhe 09/05/2013) */
  /*  Use the news bands from L8 for better cloud masking (Zhe 06/20/2013)  */
  /*  Capable of processing Landsat 8 (Zhe 04/04/2013) */
  /*  Remove Snow(mask==0)=255; (Zhe 05/24/2012) */
  /*  Made it a stand alone version (Zhe 01/09/2012) */
  /*  Impoved accuracy in TOA reflectance computing in two ways: */
  /*  Firstly, used the more accurate ESUN provied by Chander et al. RSE (2009)
   */
  /*  Secondly, used more Sun-Earth distance table provied by Chander et al. */
  /*  RSE (2009) (Zhe 01/07/2012) */
  /*  Fixed visible bands abnormal saturation problem (Zhe 04/24/2011) */
  /*  Cloud/shadow prob mask (-1) when no cloud prob computed (Zhe 01/01/2011)
   */
  /*  Flood fill for band 5 in shadow detection (Zhe 12/23/2010) */
  /*  Fixed saturation pixels (Zhe 12/16/2010) */
  /*  Include the BT test for snow (Zhe 12/06/2010) */
  /*  Include probability mask (Zhe 11/01/2010) */
  /*  Temp < 300k for all clouds (Zhe 12/01/2009) */
  /*  Reduced computing memory from double to single (Zhe 12/01/2009) */
  /*  Detecting clouds for Landsat 8 without using new bands (Zhe 09/04/2013) */
  /*  Add customized snow dilation pixel number (Zhe 09/12/2013) */
  /*  Fix problem in snow detection because of temperature (Zhe 09/12/2013) */
  /*  resolution of Fmask results */
  int sombra = 0;
  double b_ul[2];
  b_ul[0] = ul[0];
  b_ul[1] = ul[1];
  printf("Antes nd2toarbt %d\n", debug);
  debug++;

  nd2toarbt(Lmax, Lmin, Qcalmax, Qcalmin, Refmax, Refmin, ijdim_ref,
            reso_ref, b_ul, zen, Lnum, doy, im_B1_data, im_B2_data, im_B3_data,
            im_B4_data, im_B5_data, im_B7_data, im_B9_data,resolu, satu_B1_data,
            satu_B2_data, satu_B3_data, aux_bdata4, TOAref);
  printf("Después nd2toarbt %d\n", debug);
  debug++;

  for (i = 0; i < IMG_SIZE; i++) {
    mask_data[i] = !aux_bdata4[i];
  }

  for (i = 0; i < IMG_SIZE_ITER; i++) {
    satu_Bv_data[i] = satu_B1_data[i] + satu_B2_data[i] + satu_B3_data[i];
  }

  for (i = 0; i < IMG_SIZE_ITER; i++) {
    if (im_B4_data[i] + im_B3_data[i] == 0)
      NDVI_data[i] = 0.01F;
    else 
      NDVI_data[i] = (im_B4_data[i] - im_B3_data[i]) /
                    (im_B4_data[i] + im_B3_data[i]);
  }

  for (i = 0; i < IMG_SIZE_ITER; i++) {
    if (im_B2_data[i] + im_B5_data[i] == 0)    
      NDSI_data[i] = 0.01F;
    else
      NDSI_data[i] = (im_B2_data[i] - im_B5_data[i]) /
                    (im_B2_data[i] + im_B5_data[i]);
  }

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Basic cloud test */

  for (i = 0; i < IMG_SIZE_ITER; i++) {
    idplcd_data[i] = (NDSI_data[i] < 0.8F) && (NDVI_data[i] < 0.8F)
                      && (im_B7_data[i] > 300.0F);
  }

  /*  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Whiteness test */
  /*  visible bands flatness (sum(abs)/mean < 0.6 => brigt and dark cloud ) */
  for (i = 0; i < IMG_SIZE_ITER; i++) {
    visimean_data[i] =
        (im_B1_data[i] + im_B2_data[i] + im_B3_data[i]) / 3.0F;
  }

  for (i = 0; i < IMG_SIZE_ITER; i++) {
    whiteness_data[i] = satu_Bv_data[i] ? 0.0F : (fabsf(im_B1_data[i]-visimean_data[i])+
                  fabsf(im_B2_data[i]-visimean_data[i]) + fabsf(im_B3_data[i]-visimean_data[i])) / visimean_data[i];
  }

  /*  If one visible is saturated whiteness == 0 */
  for (i = 0; i < IMG_SIZE_ITER; i++) {
    idplcd_data[i] = idplcd_data[i] && (whiteness_data[i] < 0.7F);
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Haze test */
  /*  Haze test */
  for (i = 0; i < IMG_SIZE_ITER; i++) {
    HOT_data[i] = im_B1_data[i]-0.5F*im_B3_data[i]-800.0F;
  }
  /*  need to find thick warm cloud */
  for (i = 0; i < IMG_SIZE_ITER; i++) {
    idplcd_data[i] = idplcd_data[i] && ((HOT_data[i] > 0.0F)
                      || satu_Bv_data[i]);
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Ratio4/5>0.75 cloud test */
  for (i = 0; i < IMG_SIZE_ITER; i++) {
    Ratio4_5[i] = im_B4_data[i] / im_B5_data[i];
  }

  for (i = 0; i < IMG_SIZE_ITER; i++) {
    idplcd_data[i] = idplcd_data[i] && (Ratio4_5[i] > 0.75F);
  }

  printf("%d\n", debug);
  debug++;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Snow test */
  /*  It takes every snow pixels including snow pixel under thin clouds or icy
   * clouds */

  for (i = 0; i < IMG_SIZE_ITER; i++) {
    Snow_data[i] = (NDSI_data[i] > 0.15F && im_B4_data[i] > 1100.0F && im_B2_data[i] > 1000.0F) ? 1U : 0U;
  }

  if (num_Lst < 8.0) {
    /*  Landsat 4~7 */
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      Thin_prob_data[i] = 0.0F;
    }    /*  there is no contribution from the new bands */
  } else {
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Cirrus tests from Landsat 8 */
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      Thin_prob_data[i] = im_B7_data[i] / 400.0F;
      idplcd_data[i] = idplcd_data[i] || Thin_prob_data[i] > 0.25F;
    }
  }


  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Water test */
  /*  Zhe's water test (works over thin cloud) */

  for (i = 0; i < IMG_SIZE_ITER; i++) {
    Water_data[i] = (NDVI_data[i] < 0.01F && im_B4_data[i] < 1100.0F) || 
              (NDVI_data[i] < 0.1F && NDVI_data[i] > 0 && im_B4_data[i] < 500.0F);

    if (!mask_data[i])
      Water_data[i] = 255U;
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%(temperature & snow test )
   */
  /*  test whether use thermal or not */

  for (i = 0; i < IMG_SIZE_ITER; i++) {
    idclr_data[i] = !idplcd_data[i] && mask_data[i];
  }

  printf("idclr\n");
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      int aux = i * 10 + j;
      printf("%u, ", idclr_data[aux]);
    }
    printf("\n");
  }

  printf("idplcd\n");
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      int aux = i * 10 + j;
      printf("%u, ", idplcd_data[aux]);
    }
    printf("\n");
  }

  ptm = 0;
  sum_mask = 0;
  int sum_idplcd = 0;

  for (i = 0; i < IMG_SIZE_ITER; i++) {
    sum_idplcd += idplcd_data[i];
    ptm += idclr_data[i];
    sum_mask += mask_data[i];
  }

  printf("%d\n",sum_idplcd);

  ptm = 100.0F * ptm / sum_mask;
  printf("%d\n", debug);
  debug++;
if (ptm <= 0.1) {
    /*  no thermal test => meanless for snow detection (0~1) */
    /*  fprintf('No clear pixel in this image (clear prct = %.2f)\n',ptm); */
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      /*  all cld */
      Cloud_data[i] = idplcd_data[i] ? 1U : 0U;
      /*  % improving by majority filtering */
      Shadow_data[i] = Cloud_data[i] == 0U ? 1U : 0U;
    }
  } else {
    /*  Get cloud prob over water */
    /*     %% Brightness test (over water) */
    t_bright = 1100.0F;
    
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      float_aux = im_B5_data[i] / t_bright;
      if (float_aux > 1.0F)
        Brightness_prob[i] = 1.0F;
      else if (float_aux < 0.0F)
        Brightness_prob[i] = 0.0F;
      else
        Brightness_prob[i] = float_aux;
    }

    printf("brightness\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%f, ", Brightness_prob[aux]);
      }
      printf("\n");
    }

    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (satu_B2_data[i] && NDSI_data[i] < 0.0F)
        NDSI_data[i] = 0.0F;
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (satu_B3_data[i] && NDVI_data[i] > 0.0F)
        NDVI_data[i] = 0.0F;
    }

    for (i = 0; i < IMG_SIZE_ITER; i++) {
      Vari_prob_data[i] = 1 - fmaxf(fmaxf(fabsf(NDSI_data[i]),fabsf(NDVI_data[i])), whiteness_data[i]);
    }

    printf("vari_prob\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%f, ", Vari_prob_data[aux]);
      }
      printf("\n");
    }

    printf("Thin_prob\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%f, ", Thin_prob_data[aux]);
      }
      printf("\n");
    }
    
    for (i = 0; i < IMG_SIZE_ITER; i++) {
          /*     %% Final prob mask (water) */
      wfinal_prob_data[i] = (Brightness_prob[i] + Thin_prob_data[i]) * 100.0F;
          /*     %% Final prob mask (land)  */
      final_prob_data[i] = (Vari_prob_data[i] + Thin_prob_data[i]) * 100.0F;
    }

    printf("wfinal_prob\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%f, ", wfinal_prob_data[aux]);
      }
      printf("\n");
    }

    printf("final_prob\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%f, ", final_prob_data[aux]);
      }
      printf("\n");
    }

    for (i = 0; i < IMG_SIZE_ITER; i++) {
      idlnd_data[i] = idclr_data[i] && !Water_data[i];
      idwt_data[i] = idclr_data[i] && Water_data[i];
    }

    printf("idlnd\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%u, ", idlnd_data[aux]);
      }
      printf("\n");
    }

    printf("idwt\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%u, ", idwt_data[aux]);
      }
      printf("\n");
    }

    /*  dynamic threshold (water) */
    /*  wclr_max=50;% fixed threshold (water) */
    wclr_max = prctile(wfinal_prob_data, idwt_data, h_pt) + cldprob;

    /*  dynamic threshold (land) */
    clr_max = prctile(final_prob_data, idlnd_data, h_pt) + cldprob;

    printf("cldprob=%f\n",cldprob);
    printf("wclr_max=%f\n",wclr_max);
    printf("clr_max=%f\n",clr_max);
    printf("ptm=%f\n",ptm);


    for (i = 0; i < IMG_SIZE_ITER; i++) {
      id_final_cld_data[i] = (idplcd_data[i] && final_prob_data[i] > clr_max && Water_data[i] == 0U) /* % cloud over land */
                          || (idplcd_data[i] && wfinal_prob_data[i] > wclr_max && Water_data[i] == 1U);  /*  thin cloud over water */
    }

    /*     %% Star with potential cloud mask */
    /*  % potential cloud mask */

    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_final_cld_data[i])
        Cloud_data[i] = 1U;
    }

    printf("id_final\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%u, ", id_final_cld_data[aux]);
      }
      printf("\n");
    }

  
    /*  cloud over water probability */
    
    /*  % improving by majority filtering */
    /*  Cloud=bwmorph(Cloud,'majority');% exclude <5/9 */
    /*  release memory */
    /*       final_prob = final_prob - clr_max; */
    /*     %% Star with potential cloud shadow mask */
    /*  band 4 flood fill */

    for (i = 0; i < IMG_SIZE_ITER; i++) {
      nir_data[i] = im_B4_data[i];
    }

    /*  estimating background (land) Band 4 ref */
    backg_B4 = prctile(nir_data, idlnd_data, l_pt);

    printf("backg_b4=%f\n",backg_B4);

    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (!mask_data[i])
        nir_data[i] = backg_B4;
    }

    /*  fill in regional minimum Band 4 ref */
    imfill(nir_data,nir_data);

    for (i = 0; i < IMG_SIZE_ITER; i++) {
      nir_data[i] -= im_B4_data[i];
    }

    printf("imfill_nir\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%f, ", nir_data[aux]);
      }
      printf("\n");
    }

    /*  band 5 flood fill */
    
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      swir_data[i] = im_B5_data[i];
    }

    /*  estimating background (land) Band 4 ref */
    
    backg_B5 = prctile(swir_data, idlnd_data, l_pt);

    printf("backg_b5=%f\n",backg_B5);

    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (!mask_data[i])
        swir_data[i] = backg_B5;
    }

    /*  fill in regional minimum Band 5 ref */
    
    imfill(swir_data,swir_data);

    for (i = 0; i < IMG_SIZE_ITER; i++) {
      swir_data[i] -= im_B5_data[i];
    }

    printf("imfill_swir\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%f, ", swir_data[aux]);
      }
      printf("\n");
    }

    /*  compute shadow probability */

    for (i = 0; i < IMG_SIZE_ITER; i++) {
      float_aux = fminf(nir_data[i], swir_data[i]);
      if (float_aux > 200.0F) {
        Shadow_data[i] = 1U;
        sombra++;
      }
    }

    printf("Sombra: %d", sombra);
  }


  /*  fprintf('Read in TOA ref ...\n'); */
  
  /*  shadow mask */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%saturation in the three
   * visible bands */
  /*  clear satu_B; */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Basic cloud test */
  /*  Snow(mask==0)=255; */

  /*  enviwrite(['Eq6_cloud_potential'],tmpidplcd,'uint8',resolu,ul,'bsq',zc); %
   * Equation 6 */

  /*  percent of clear pixel */

  /*  refine Water mask - Zhe's water mask (no confusion water/cloud) */

  for (i = 0; i < IMG_SIZE_ITER; i++) {
    Water_data[i] = Water_data[i] && !Cloud_data[i];
  }

  /*  bwmorph changed Cloud to Binary */
  
  for (i = 0; i < IMG_SIZE_ITER; i++) {
    if (!mask_data[i]) {
      Cloud_data[i] = 255U;
      Shadow_data[i] = 255U;
    }
  }

  printf("Water\n");
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      int aux = i * 10 + j;
      printf("%u, ", Water_data[aux]);
    }
    printf("\n");
  }

  /*  enviwrite('TOA3.2',data,'int16',resolu,ul,'bsq',zc); */
  /*  enviwrite('BT3.2',BT,'int16',resolu,ul,'bsq',zc); */
  /*  enviwrite('final_prob',final_prob,'single',resolu,ul,'bsq',zc); */
  /*  enviwrite('thin_prob',100*Thin_prob,'single',resolu,ul,'bsq',zc); */

  //end_tmp = Cloud->size[0] * Cloud->size[1];

  //for (i = 0; i < end_tmp; i++)
    //printf("%hhu,\n",Cloud->data[i]);

  /*  toc */

  return ptm;
}

/* End of code generation (Fmask.c) */
