/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nd2toarbt.c
 *
 * Code generation for function 'nd2toarbt'
 *
 */

/* Include files */
#include "size.h"

#include <stdio.h>
#include <math.h>

/* Function Definitions */
void nd2toarbt(const double Lmax[9], const double Lmin[9],
               const double Qcalmax[9], const double Qcalmin[9],
               const double Refmax[7], const double Refmin[7],
               const double ijdim_ref[2],
               const double reso_ref[2], double ul[2],
               double zen, double Lnum, double doy, float *im_B1_data,
               float *im_B2_data, float *im_B3_data,
               float *im_B4_data, float *im_B5_data, float *im_B7_data,
               float *im_B9_data, double resolu[4], unsigned char *B1Satu_data,
               unsigned char *B2Satu_data, unsigned char *B3Satu_data,
               unsigned char *id_missing_data, float *TOAref_data)
{
  static const double Tab_ES_Dist[732] = {
      1.0,   0.98331, 2.0,   0.9833,  3.0,   0.9833,  4.0,   0.9833,
      5.0,   0.9833,  6.0,   0.98332, 7.0,   0.98333, 8.0,   0.98335,
      9.0,   0.98338, 10.0,  0.98341, 11.0,  0.98345, 12.0,  0.98349,
      13.0,  0.98354, 14.0,  0.98359, 15.0,  0.98365, 16.0,  0.98371,
      17.0,  0.98378, 18.0,  0.98385, 19.0,  0.98393, 20.0,  0.98401,
      21.0,  0.9841,  22.0,  0.98419, 23.0,  0.98428, 24.0,  0.98439,
      25.0,  0.98449, 26.0,  0.9846,  27.0,  0.98472, 28.0,  0.98484,
      29.0,  0.98496, 30.0,  0.98509, 31.0,  0.98523, 32.0,  0.98536,
      33.0,  0.98551, 34.0,  0.98565, 35.0,  0.9858,  36.0,  0.98596,
      37.0,  0.98612, 38.0,  0.98628, 39.0,  0.98645, 40.0,  0.98662,
      41.0,  0.9868,  42.0,  0.98698, 43.0,  0.98717, 44.0,  0.98735,
      45.0,  0.98755, 46.0,  0.98774, 47.0,  0.98794, 48.0,  0.98814,
      49.0,  0.98835, 50.0,  0.98856, 51.0,  0.98877, 52.0,  0.98899,
      53.0,  0.98921, 54.0,  0.98944, 55.0,  0.98966, 56.0,  0.98989,
      57.0,  0.99012, 58.0,  0.99036, 59.0,  0.9906,  60.0,  0.99084,
      61.0,  0.99108, 62.0,  0.99133, 63.0,  0.99158, 64.0,  0.99183,
      65.0,  0.99208, 66.0,  0.99234, 67.0,  0.9926,  68.0,  0.99286,
      69.0,  0.99312, 70.0,  0.99339, 71.0,  0.99365, 72.0,  0.99392,
      73.0,  0.99419, 74.0,  0.99446, 75.0,  0.99474, 76.0,  0.99501,
      77.0,  0.99529, 78.0,  0.99556, 79.0,  0.99584, 80.0,  0.99612,
      81.0,  0.9964,  82.0,  0.99669, 83.0,  0.99697, 84.0,  0.99725,
      85.0,  0.99754, 86.0,  0.99782, 87.0,  0.99811, 88.0,  0.9984,
      89.0,  0.99868, 90.0,  0.99897, 91.0,  0.99926, 92.0,  0.99954,
      93.0,  0.99983, 94.0,  1.00012, 95.0,  1.00041, 96.0,  1.00069,
      97.0,  1.00098, 98.0,  1.00127, 99.0,  1.00155, 100.0, 1.00184,
      101.0, 1.00212, 102.0, 1.0024,  103.0, 1.00269, 104.0, 1.00297,
      105.0, 1.00325, 106.0, 1.00353, 107.0, 1.00381, 108.0, 1.00409,
      109.0, 1.00437, 110.0, 1.00464, 111.0, 1.00492, 112.0, 1.00519,
      113.0, 1.00546, 114.0, 1.00573, 115.0, 1.006,   116.0, 1.00626,
      117.0, 1.00653, 118.0, 1.00679, 119.0, 1.00705, 120.0, 1.00731,
      121.0, 1.00756, 122.0, 1.00781, 123.0, 1.00806, 124.0, 1.00831,
      125.0, 1.00856, 126.0, 1.0088,  127.0, 1.00904, 128.0, 1.00928,
      129.0, 1.00952, 130.0, 1.00975, 131.0, 1.00998, 132.0, 1.0102,
      133.0, 1.01043, 134.0, 1.01065, 135.0, 1.01087, 136.0, 1.01108,
      137.0, 1.01129, 138.0, 1.0115,  139.0, 1.0117,  140.0, 1.01191,
      141.0, 1.0121,  142.0, 1.0123,  143.0, 1.01249, 144.0, 1.01267,
      145.0, 1.01286, 146.0, 1.01304, 147.0, 1.01321, 148.0, 1.01338,
      149.0, 1.01355, 150.0, 1.01371, 151.0, 1.01387, 152.0, 1.01403,
      153.0, 1.01418, 154.0, 1.01433, 155.0, 1.01447, 156.0, 1.01461,
      157.0, 1.01475, 158.0, 1.01488, 159.0, 1.015,   160.0, 1.01513,
      161.0, 1.01524, 162.0, 1.01536, 163.0, 1.01547, 164.0, 1.01557,
      165.0, 1.01567, 166.0, 1.01577, 167.0, 1.01586, 168.0, 1.01595,
      169.0, 1.01603, 170.0, 1.0161,  171.0, 1.01618, 172.0, 1.01625,
      173.0, 1.01631, 174.0, 1.01637, 175.0, 1.01642, 176.0, 1.01647,
      177.0, 1.01652, 178.0, 1.01656, 179.0, 1.01659, 180.0, 1.01662,
      181.0, 1.01665, 182.0, 1.01667, 183.0, 1.01668, 184.0, 1.0167,
      185.0, 1.0167,  186.0, 1.0167,  187.0, 1.0167,  188.0, 1.01669,
      189.0, 1.01668, 190.0, 1.01666, 191.0, 1.01664, 192.0, 1.01661,
      193.0, 1.01658, 194.0, 1.01655, 195.0, 1.0165,  196.0, 1.01646,
      197.0, 1.01641, 198.0, 1.01635, 199.0, 1.01629, 200.0, 1.01623,
      201.0, 1.01616, 202.0, 1.01609, 203.0, 1.01601, 204.0, 1.01592,
      205.0, 1.01584, 206.0, 1.01575, 207.0, 1.01565, 208.0, 1.01555,
      209.0, 1.01544, 210.0, 1.01533, 211.0, 1.01522, 212.0, 1.0151,
      213.0, 1.01497, 214.0, 1.01485, 215.0, 1.01471, 216.0, 1.01458,
      217.0, 1.01444, 218.0, 1.01429, 219.0, 1.01414, 220.0, 1.01399,
      221.0, 1.01383, 222.0, 1.01367, 223.0, 1.01351, 224.0, 1.01334,
      225.0, 1.01317, 226.0, 1.01299, 227.0, 1.01281, 228.0, 1.01263,
      229.0, 1.01244, 230.0, 1.01225, 231.0, 1.01205, 232.0, 1.01186,
      233.0, 1.01165, 234.0, 1.01145, 235.0, 1.01124, 236.0, 1.01103,
      237.0, 1.01081, 238.0, 1.0106,  239.0, 1.01037, 240.0, 1.01015,
      241.0, 1.00992, 242.0, 1.00969, 243.0, 1.00946, 244.0, 1.00922,
      245.0, 1.00898, 246.0, 1.00874, 247.0, 1.0085,  248.0, 1.00825,
      249.0, 1.008,   250.0, 1.00775, 251.0, 1.0075,  252.0, 1.00724,
      253.0, 1.00698, 254.0, 1.00672, 255.0, 1.00646, 256.0, 1.0062,
      257.0, 1.00593, 258.0, 1.00566, 259.0, 1.00539, 260.0, 1.00512,
      261.0, 1.00485, 262.0, 1.00457, 263.0, 1.0043,  264.0, 1.00402,
      265.0, 1.00374, 266.0, 1.00346, 267.0, 1.00318, 268.0, 1.0029,
      269.0, 1.00262, 270.0, 1.00234, 271.0, 1.00205, 272.0, 1.00177,
      273.0, 1.00148, 274.0, 1.00119, 275.0, 1.00091, 276.0, 1.00062,
      277.0, 1.00033, 278.0, 1.00005, 279.0, 0.99976, 280.0, 0.99947,
      281.0, 0.99918, 282.0, 0.9989,  283.0, 0.99861, 284.0, 0.99832,
      285.0, 0.99804, 286.0, 0.99775, 287.0, 0.99747, 288.0, 0.99718,
      289.0, 0.9969,  290.0, 0.99662, 291.0, 0.99634, 292.0, 0.99605,
      293.0, 0.99577, 294.0, 0.9955,  295.0, 0.99522, 296.0, 0.99494,
      297.0, 0.99467, 298.0, 0.9944,  299.0, 0.99412, 300.0, 0.99385,
      301.0, 0.99359, 302.0, 0.99332, 303.0, 0.99306, 304.0, 0.99279,
      305.0, 0.99253, 306.0, 0.99228, 307.0, 0.99202, 308.0, 0.99177,
      309.0, 0.99152, 310.0, 0.99127, 311.0, 0.99102, 312.0, 0.99078,
      313.0, 0.99054, 314.0, 0.9903,  315.0, 0.99007, 316.0, 0.98983,
      317.0, 0.98961, 318.0, 0.98938, 319.0, 0.98916, 320.0, 0.98894,
      321.0, 0.98872, 322.0, 0.98851, 323.0, 0.9883,  324.0, 0.98809,
      325.0, 0.98789, 326.0, 0.98769, 327.0, 0.9875,  328.0, 0.98731,
      329.0, 0.98712, 330.0, 0.98694, 331.0, 0.98676, 332.0, 0.98658,
      333.0, 0.98641, 334.0, 0.98624, 335.0, 0.98608, 336.0, 0.98592,
      337.0, 0.98577, 338.0, 0.98562, 339.0, 0.98547, 340.0, 0.98533,
      341.0, 0.98519, 342.0, 0.98506, 343.0, 0.98493, 344.0, 0.98481,
      345.0, 0.98469, 346.0, 0.98457, 347.0, 0.98446, 348.0, 0.98436,
      349.0, 0.98426, 350.0, 0.98416, 351.0, 0.98407, 352.0, 0.98399,
      353.0, 0.98391, 354.0, 0.98383, 355.0, 0.98376, 356.0, 0.9837,
      357.0, 0.98363, 358.0, 0.98358, 359.0, 0.98353, 360.0, 0.98348,
      361.0, 0.98344, 362.0, 0.9834,  363.0, 0.98337, 364.0, 0.98335,
      365.0, 0.98333, 366.0, 0.98331
      };
  static const double esun_L4[7] = {1983.0, 1795.0, 1539.0, 1028.0,
                                    219.8,  -1.0,   83.49};
  static const double esun_L5[7] = {1983.0, 1796.0, 1536.0, 1031.0,
                                    220.0,  -1.0,   83.44};
  static const double esun_L7[7] = {1997.0, 1812.0, 1533.0, 1039.0,
                                    230.8,  -1.0,   84.9};
                    
  int b_k;
  int i;
  double cos_zen;
  int loop_ub;
  /*  convert DNs to TOA ref and BT */
  /*  Revisions: */
  /*  Use REF vs. DN instead of RAD vs. DN (Zhe 06/20/2013) */
  /*  Combined the Earth-Sun distance table into the function (Zhe 04/09/2013)
   */
  /*  Process Landsat 8 DN values (Zhe 04/04/2013) */
  /*  Proces the new metadata for Landsat TM/ETM+ images (Zhe 09/28/2012) */
  /*  Fixed bugs caused by earth-sun distance table (Zhe 01/15/2012) */
  /*  */
  /*  [im_th,TOAref,ijdim_ref,ul,zen,azi,zc,B1Satu,B2Satu,B3Satu,resolu]=nd2toarbt(filename)
   */
  /*  Where: */
  /*  Inputs: */
  /*  filename='L*MTL.txt'; */
  /*  Outputs: */
  /*  1) im_th = Brightness Temperature (BT) */
  /*  2) TOAref = Top Of Atmoshpere (TOA) reflectance */
  /*  3) ijdim = [nrows,ncols]; % dimension of optical bands */
  /*  4) ul = [upperleft_mapx upperleft_mapy]; */
  /*  5) zen = solar zenith angle (degrees); */
  /*  6) azi = solar azimuth angle (degrees); */
  /*  7) zc = Zone Number */
  /*  8,9,10) Saturation (true) in the Visible bands */
  /*  11) resolution of Fmask results */
  printf("Read in header information & TIF images\n");
  /* [Lmax,Lmin,Qcalmax,Qcalmin,Refmax,Refmin,ijdim_ref,ijdim_thm,reso_ref,...
   */
  /*    reso_thm,ul,zen,azi,zc,Lnum,doy]=lndhdrread(filename); */
  /*  earth-sun distance see G. Chander et al. RSE 113 (2009) 893-903 */
  if ((Lnum >= 4.0) && (Lnum <= 7.0)) {
    double ESUN[7];
    double a;
    double b_a;
    double c_a;
    double d_a;
    double dsun_doy;
    double e_a;
    double f_a;
    double g_a;
    double h_a;
    int loop_ub_tmp;
    int suma = 0;
    /*  LPGS Upper lef corner alignment (see Landsat handbook for detail) */
    ul[0] -= 15.0;
    ul[1] += 15.0;
    resolu[0] = reso_ref[0];
    resolu[1] = reso_ref[0];
    resolu[2] = reso_ref[1];
    resolu[3] = reso_ref[1];
    /*  Read in all bands */
    /*  check to see whether need to resample thermal band */
    // if (reso_ref[0] != reso_thm[0] || reso_ref[1] != reso_thm[1]) {
    //   double b_reso_thm[4];
    //   double b_ijdim_ref[2];
    //   double b_ijdim_thm[2];
    //   double b_ul[2];
    //   double c_ul[2];
    //   /*  resmaple thermal band */
    //   b_ul[0] = ul[1];
    //   b_ul[1] = ul[0];
    //   c_ul[0] = ul[1];
    //   c_ul[1] = ul[0];
    //   b_reso_thm[0] = reso_thm[0];
    //   b_reso_thm[1] = reso_thm[0];
    //   b_reso_thm[2] = reso_thm[1];
    //   b_reso_thm[3] = reso_thm[1];
    //   b_ijdim_ref[0] = ijdim_ref[1];
    //   b_ijdim_ref[1] = ijdim_ref[0];
    //   b_ijdim_thm[0] = ijdim_thm[1];
    //   b_ijdim_thm[1] = ijdim_thm[0];
    //   i = b_im_B10->size[0] * b_im_B10->size[1];
    //   b_im_B10->size[1] = im_B6->size[1];
    //   b_im_B10->size[0] = im_B6->size[0];
    //   emxEnsureCapacity_real32_T(b_im_B10, i);
    //   im_th_data = b_im_B10->data;
    //   loop_ub = im_B6->size[1] * im_B6->size[0] - 1;
    //   for (i = 0; i <= loop_ub; i++) {
    //     im_th_data[i] = im_B6_data[i];
    //   }
    //   pixel2pixv(b_ul, c_ul, resolu, b_reso_thm, b_im_B10, b_ijdim_ref,
    //              b_ijdim_thm, im_B6);
    //   im_B6_data = im_B6->data;
    // }
    /*  Band7 */
    /*  n_B7=dir('*B7*'); */
    /*  im_B7=single(imread(n_B7.name)); */
    /*  only processing pixesl where all bands have values (id_mssing) */
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      id_missing_data[i] =
          ((im_B1_data[i] == 0.0F) || (im_B2_data[i] == 0.0F) ||
           (im_B3_data[i] == 0.0F) || (im_B4_data[i] == 0.0F) ||
           (im_B5_data[i] == 0.0F) || (im_B7_data[i] == 0.0F)) ? 1U : 0U;
    }
    /*  find pixels that are saturated in the visible bands */
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      B1Satu_data[i] = (im_B1_data[i] == 255.0F);
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      B2Satu_data[i] = (im_B2_data[i] == 255.0F);
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      B3Satu_data[i] = (im_B3_data[i] == 255.0F);
    }
    /*  ND to radiance first */
    printf("From DNs to TOA ref & BT\n");
    a = (Lmax[0] - Lmin[0]) / (Qcalmax[0] - Qcalmin[0]);
    b_a = (Lmax[1] - Lmin[1]) / (Qcalmax[1] - Qcalmin[1]);
    c_a = (Lmax[2] - Lmin[2]) / (Qcalmax[2] - Qcalmin[2]);
    d_a = (Lmax[3] - Lmin[3]) / (Qcalmax[3] - Qcalmin[3]);
    e_a = (Lmax[4] - Lmin[4]) / (Qcalmax[4] - Qcalmin[4]);
    g_a = (Lmax[6] - Lmin[6]) / (Qcalmax[6] - Qcalmin[6]);
    /*  Landsat 4, 5, and 7 solar spectral irradiance */
    /*  see G. Chander et al. RSE 113 (2009) 893-903 */
    if (Lnum == 7.0) {
      for (i = 0; i < 7; i++) {
        ESUN[i] = esun_L7[i];
      }
    } else if (Lnum == 5.0) {
      for (i = 0; i < 7; i++) {
        ESUN[i] = esun_L5[i];
      }
    } else {
      for (i = 0; i < 7; i++) {
        ESUN[i] = esun_L4[i];
      }
    }
    /*  earth-sun distance see G. Chander et al. RSE 113 (2009) 893-903     */
    dsun_doy = Tab_ES_Dist[(((int)doy - 1) << 1) + 1];
    /*  compute TOA reflectances */
    /*  converted from degrees to radiance */
    cos_zen = cos(0.017453292519943295 * zen);
    dsun_doy *= dsun_doy;
    h_a = ESUN[0] * cos_zen;
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      im_B1_data[i] =
          31415.9258F *
          ((float)a * (im_B1_data[i] - (float)Qcalmin[0]) + (float)Lmin[0]) *
          (float)dsun_doy / (float)h_a;
    }
    h_a = ESUN[1] * cos_zen;
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      im_B2_data[i] =
          31415.9258F *
          ((float)b_a * (im_B2_data[i] - (float)Qcalmin[1]) + (float)Lmin[1]) *
          (float)dsun_doy / (float)h_a;
    }
    h_a = ESUN[2] * cos_zen;
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      im_B3_data[i] =
          31415.9258F *
          ((float)c_a * (im_B3_data[i] - (float)Qcalmin[2]) + (float)Lmin[2]) *
          (float)dsun_doy / (float)h_a;
    }
    h_a = ESUN[3] * cos_zen;
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      im_B4_data[i] =
          31415.9258F *
          ((float)d_a * (im_B4_data[i] - (float)Qcalmin[3]) + (float)Lmin[3]) *
          (float)dsun_doy / (float)h_a;
    }
    h_a = ESUN[4] * cos_zen;
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      im_B5_data[i] =
          31415.9258F *
          ((float)e_a * (im_B5_data[i] - (float)Qcalmin[4]) + (float)Lmin[4]) *
          (float)dsun_doy / (float)h_a;
    }
    h_a = ESUN[6] * cos_zen;
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      im_B7_data[i] =
          31415.9258F *
          ((float)g_a * (im_B7_data[i] - (float)Qcalmin[6]) + (float)Lmin[6]) *
          (float)dsun_doy / (float)h_a;
    }
    /*  convert Band6 from radiance to BT */
    /*  fprintf('From Band 6 Radiance to Brightness Temperature\n'); */
    /*  see G. Chander et al. RSE 113 (2009) 893-903 */
    // if (Lnum == 7.0) {
    //   dsun_doy = 666.09;
    //   h_a = 1282.71;
    // } else if (Lnum == 5.0) {
    //   dsun_doy = 607.76;
    //   h_a = 1260.56;
    // } else {
    //   dsun_doy = 671.62;
    //   h_a = 1284.3;
    // }
    /*  get data ready for Fmask */

    /*  Band1,2,3,4,5,&7 */
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B1_data[i] = -9999.0F;
      }
    } 

    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B2_data[i] = -9999.0F;
      }
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B3_data[i] = -9999.0F;
      }
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B4_data[i] = -9999.0F;
      }
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B5_data[i] = -9999.0F;
      }
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B7_data[i] = -9999.0F;
      }
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B9_data[i] = -9999.0F;
      }
    }

  } else if (Lnum == 8.0) {
    double a;
    double b_a;
    double c_a;
    double d_a;
    double dsun_doy;
    double e_a;
    double f_a;
    double g_a;

    im_B9_data = im_B7_data;
    im_B7_data = im_B5_data;
    im_B5_data = im_B4_data;
    im_B4_data = im_B3_data;
    im_B3_data = im_B2_data;
    im_B2_data = im_B1_data;


    /*  LPGS Upper lef corner alignment (see Landsat handbook for detail) */
    ul[0] -= 15.0;
    ul[1] += 15.0;
    resolu[0] = reso_ref[0];
    resolu[1] = reso_ref[0];
    resolu[2] = reso_ref[1];
    resolu[3] = reso_ref[1];
    /*  check to see whether need to resample thermal band */
    /*  only processing pixesl where all bands have values (id_mssing) */
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      id_missing_data[i] =
          ((im_B2_data[i] == 0.0F) || (im_B3_data[i] == 0.0F) ||
           (im_B4_data[i] == 0.0F) || (im_B5_data[i] == 0.0F) ||
           (im_B7_data[i] == 0.0F) || (im_B9_data[i] == 0.0F));
    }
    /*  find pixels that are saturated in the visible bands */
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      B1Satu_data[i] = (im_B2_data[i] == 65535.0F);
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      B2Satu_data[i] = (im_B3_data[i] == 65535.0F);
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      B3Satu_data[i] = (im_B4_data[i] == 65535.0F);
    }
    /*  ND to TOA reflectance with 0.0001 scale_facor */
    printf("From DNs to TOA ref & BT\n");
    a = (Refmax[0] - Refmin[0]) / (Qcalmax[0] - Qcalmin[0]);
    b_a = (Refmax[1] - Refmin[1]) / (Qcalmax[1] - Qcalmin[1]);
    c_a = (Refmax[2] - Refmin[2]) / (Qcalmax[2] - Qcalmin[2]);
    d_a = (Refmax[3] - Refmin[3]) / (Qcalmax[3] - Qcalmin[3]);
    f_a = (Refmax[5] - Refmin[5]) / (Qcalmax[5] - Qcalmin[5]);
    g_a = (Refmax[6] - Refmin[6]) / (Qcalmax[6] - Qcalmin[6]);
    /*  compute TOA reflectances */
    /*  with a correction for the sun angle */
    cos_zen = cos(0.017453292519943295 * zen);

    for (i = 0; i < IMG_SIZE_ITER; i++) {
      im_B2_data[i] =
          10000.0F *
          ((float)a * (im_B2_data[i] - (float)Qcalmin[0]) + (float)Refmin[0]) /
          (float)cos_zen;
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      im_B3_data[i] = 10000.0F *
                      ((float)b_a * (im_B3_data[i] - (float)Qcalmin[1]) +
                       (float)Refmin[1]) /
                      (float)cos_zen;
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      im_B4_data[i] = 10000.0F *
                      ((float)c_a * (im_B4_data[i] - (float)Qcalmin[2]) +
                       (float)Refmin[2]) /
                      (float)cos_zen;
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      im_B5_data[i] = 10000.0F *
                      ((float)d_a * (im_B5_data[i] - (float)Qcalmin[3]) +
                       (float)Refmin[3]) /
                      (float)cos_zen;
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      im_B7_data[i] = 10000.0F *
                      ((float)f_a * (im_B7_data[i] - (float)Qcalmin[5]) +
                       (float)Refmin[5]) /
                      (float)cos_zen;
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      im_B9_data[i] = 10000.0F *
                      ((float)g_a * (im_B9_data[i] - (float)Qcalmin[6]) +
                       (float)Refmin[6]) /
                      (float)cos_zen;
    }
    /*  convert Band6 from radiance to BT */
    /*  fprintf('From Band 6 Radiance to Brightness Temperature\n'); */
    /*  convert from Kelvin to Celcius with 0.01 scale_facor */
    /*  get data ready for Fmask */
    /*  Band 2,3,4,5,6,7,& 9 */
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B1_data[i] = -9999.0F;
      }
    } 

    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B2_data[i] = -9999.0F;
      }
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B3_data[i] = -9999.0F;
      }
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B4_data[i] = -9999.0F;
      }
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B5_data[i] = -9999.0F;
      }
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B7_data[i] = -9999.0F;
      }
    }
    for (i = 0; i < IMG_SIZE_ITER; i++) {
      if (id_missing_data[i]) {
        im_B9_data[i] = -9999.0F;
      }
    }

  } else {
    printf("This sensor is not Landsat 4, 5, 7, or 8!\n");
  }

}

/* End of code generation (nd2toarbt.c) */
