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
#include "nd2toarbt.h"
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"
#include <math.h>

/* Function Declarations */
static void b_or(emxArray_boolean_T *in1, const emxArray_boolean_T *in2,
                 const emxArray_boolean_T *in3);

static void
binary_expand_op(emxArray_boolean_T *in1, const emxArray_real32_T *in2,
                 const emxArray_real32_T *in3, const emxArray_real32_T *in4,
                 const emxArray_real32_T *in5, const emxArray_real32_T *in6,
                 const emxArray_real32_T *in7);

/* Function Definitions */
static void b_or(emxArray_boolean_T *in1, const emxArray_boolean_T *in2,
                 const emxArray_boolean_T *in3)
{
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  const boolean_T *in2_data;
  const boolean_T *in3_data;
  boolean_T *in1_data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  if (in3->size[1] == 1) {
    b_loop_ub = in2->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          (in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] ||
           in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1]);
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void
binary_expand_op(emxArray_boolean_T *in1, const emxArray_real32_T *in2,
                 const emxArray_real32_T *in3, const emxArray_real32_T *in4,
                 const emxArray_real32_T *in5, const emxArray_real32_T *in6,
                 const emxArray_real32_T *in7)
{
  const float *in2_data;
  const float *in3_data;
  const float *in4_data;
  const float *in5_data;
  const float *in6_data;
  const float *in7_data;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int aux_3_1;
  int aux_4_1;
  int aux_5_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  int stride_2_0;
  int stride_2_1;
  int stride_3_0;
  int stride_3_1;
  int stride_4_0;
  int stride_4_1;
  int stride_5_0;
  int stride_5_1;
  boolean_T *in1_data;
  in7_data = in7->data;
  in6_data = in6->data;
  in5_data = in5->data;
  in4_data = in4->data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in7->size[0] == 1) {
    if (in6->size[0] == 1) {
      if (in5->size[0] == 1) {
        if (in4->size[0] == 1) {
          if (in3->size[0] == 1) {
            loop_ub = in2->size[0];
          } else {
            loop_ub = in3->size[0];
          }
        } else {
          loop_ub = in4->size[0];
        }
      } else {
        loop_ub = in5->size[0];
      }
    } else {
      loop_ub = in6->size[0];
    }
  } else {
    loop_ub = in7->size[0];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  if (in7->size[1] == 1) {
    if (in6->size[1] == 1) {
      if (in5->size[1] == 1) {
        if (in4->size[1] == 1) {
          if (in3->size[1] == 1) {
            b_loop_ub = in2->size[1];
          } else {
            b_loop_ub = in3->size[1];
          }
        } else {
          b_loop_ub = in4->size[1];
        }
      } else {
        b_loop_ub = in5->size[1];
      }
    } else {
      b_loop_ub = in6->size[1];
    }
  } else {
    b_loop_ub = in7->size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  stride_2_0 = (in4->size[0] != 1);
  stride_2_1 = (in4->size[1] != 1);
  stride_3_0 = (in5->size[0] != 1);
  stride_3_1 = (in5->size[1] != 1);
  stride_4_0 = (in6->size[0] != 1);
  stride_4_1 = (in6->size[1] != 1);
  stride_5_0 = (in7->size[0] != 1);
  stride_5_1 = (in7->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  aux_3_1 = 0;
  aux_4_1 = 0;
  aux_5_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          ((in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] == 0.0F) ||
           (in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1] == 0.0F) ||
           (in4_data[i1 * stride_2_0 + in4->size[0] * aux_2_1] == 0.0F) ||
           (in5_data[i1 * stride_3_0 + in5->size[0] * aux_3_1] == 0.0F) ||
           (in6_data[i1 * stride_4_0 + in6->size[0] * aux_4_1] == 0.0F) ||
           (in7_data[i1 * stride_5_0 + in7->size[0] * aux_5_1] == 0.0F));
    }
    aux_5_1 += stride_5_1;
    aux_4_1 += stride_4_1;
    aux_3_1 += stride_3_1;
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

void nd2toarbt(emxArray_real32_T *im_B1, emxArray_real32_T *im_B2,
               emxArray_real32_T *im_B3, emxArray_real32_T *im_B4,
               emxArray_real32_T *im_B5, emxArray_real32_T *im_th,
               emxArray_real32_T *im_B7, const float Lmax[7],
               const float Lmin[7], const float Qcalmax[7],
               const float Qcalmin[7], const float ijdim_ref[2], float reso_ref,
               float reso_thm, double ul[2], const double bbox[4],
               const double *zen, const double *azi, const double *zc,
               double Lnum, double doy, emxArray_real32_T *TOAref,
               emxArray_boolean_T *B1Satu, emxArray_boolean_T *B2Satu,
               emxArray_boolean_T *B3Satu, float resolu[2])
{
  static const double Tab_ES_Dist[732] = {
      1.0,     2.0,     3.0,     4.0,     5.0,     6.0,     7.0,     8.0,
      9.0,     10.0,    11.0,    12.0,    13.0,    14.0,    15.0,    16.0,
      17.0,    18.0,    19.0,    20.0,    21.0,    22.0,    23.0,    24.0,
      25.0,    26.0,    27.0,    28.0,    29.0,    30.0,    31.0,    32.0,
      33.0,    34.0,    35.0,    36.0,    37.0,    38.0,    39.0,    40.0,
      41.0,    42.0,    43.0,    44.0,    45.0,    46.0,    47.0,    48.0,
      49.0,    50.0,    51.0,    52.0,    53.0,    54.0,    55.0,    56.0,
      57.0,    58.0,    59.0,    60.0,    61.0,    62.0,    63.0,    64.0,
      65.0,    66.0,    67.0,    68.0,    69.0,    70.0,    71.0,    72.0,
      73.0,    74.0,    75.0,    76.0,    77.0,    78.0,    79.0,    80.0,
      81.0,    82.0,    83.0,    84.0,    85.0,    86.0,    87.0,    88.0,
      89.0,    90.0,    91.0,    92.0,    93.0,    94.0,    95.0,    96.0,
      97.0,    98.0,    99.0,    100.0,   101.0,   102.0,   103.0,   104.0,
      105.0,   106.0,   107.0,   108.0,   109.0,   110.0,   111.0,   112.0,
      113.0,   114.0,   115.0,   116.0,   117.0,   118.0,   119.0,   120.0,
      121.0,   122.0,   123.0,   124.0,   125.0,   126.0,   127.0,   128.0,
      129.0,   130.0,   131.0,   132.0,   133.0,   134.0,   135.0,   136.0,
      137.0,   138.0,   139.0,   140.0,   141.0,   142.0,   143.0,   144.0,
      145.0,   146.0,   147.0,   148.0,   149.0,   150.0,   151.0,   152.0,
      153.0,   154.0,   155.0,   156.0,   157.0,   158.0,   159.0,   160.0,
      161.0,   162.0,   163.0,   164.0,   165.0,   166.0,   167.0,   168.0,
      169.0,   170.0,   171.0,   172.0,   173.0,   174.0,   175.0,   176.0,
      177.0,   178.0,   179.0,   180.0,   181.0,   182.0,   183.0,   184.0,
      185.0,   186.0,   187.0,   188.0,   189.0,   190.0,   191.0,   192.0,
      193.0,   194.0,   195.0,   196.0,   197.0,   198.0,   199.0,   200.0,
      201.0,   202.0,   203.0,   204.0,   205.0,   206.0,   207.0,   208.0,
      209.0,   210.0,   211.0,   212.0,   213.0,   214.0,   215.0,   216.0,
      217.0,   218.0,   219.0,   220.0,   221.0,   222.0,   223.0,   224.0,
      225.0,   226.0,   227.0,   228.0,   229.0,   230.0,   231.0,   232.0,
      233.0,   234.0,   235.0,   236.0,   237.0,   238.0,   239.0,   240.0,
      241.0,   242.0,   243.0,   244.0,   245.0,   246.0,   247.0,   248.0,
      249.0,   250.0,   251.0,   252.0,   253.0,   254.0,   255.0,   256.0,
      257.0,   258.0,   259.0,   260.0,   261.0,   262.0,   263.0,   264.0,
      265.0,   266.0,   267.0,   268.0,   269.0,   270.0,   271.0,   272.0,
      273.0,   274.0,   275.0,   276.0,   277.0,   278.0,   279.0,   280.0,
      281.0,   282.0,   283.0,   284.0,   285.0,   286.0,   287.0,   288.0,
      289.0,   290.0,   291.0,   292.0,   293.0,   294.0,   295.0,   296.0,
      297.0,   298.0,   299.0,   300.0,   301.0,   302.0,   303.0,   304.0,
      305.0,   306.0,   307.0,   308.0,   309.0,   310.0,   311.0,   312.0,
      313.0,   314.0,   315.0,   316.0,   317.0,   318.0,   319.0,   320.0,
      321.0,   322.0,   323.0,   324.0,   325.0,   326.0,   327.0,   328.0,
      329.0,   330.0,   331.0,   332.0,   333.0,   334.0,   335.0,   336.0,
      337.0,   338.0,   339.0,   340.0,   341.0,   342.0,   343.0,   344.0,
      345.0,   346.0,   347.0,   348.0,   349.0,   350.0,   351.0,   352.0,
      353.0,   354.0,   355.0,   356.0,   357.0,   358.0,   359.0,   360.0,
      361.0,   362.0,   363.0,   364.0,   365.0,   366.0,   0.98331, 0.9833,
      0.9833,  0.9833,  0.9833,  0.98332, 0.98333, 0.98335, 0.98338, 0.98341,
      0.98345, 0.98349, 0.98354, 0.98359, 0.98365, 0.98371, 0.98378, 0.98385,
      0.98393, 0.98401, 0.9841,  0.98419, 0.98428, 0.98439, 0.98449, 0.9846,
      0.98472, 0.98484, 0.98496, 0.98509, 0.98523, 0.98536, 0.98551, 0.98565,
      0.9858,  0.98596, 0.98612, 0.98628, 0.98645, 0.98662, 0.9868,  0.98698,
      0.98717, 0.98735, 0.98755, 0.98774, 0.98794, 0.98814, 0.98835, 0.98856,
      0.98877, 0.98899, 0.98921, 0.98944, 0.98966, 0.98989, 0.99012, 0.99036,
      0.9906,  0.99084, 0.99108, 0.99133, 0.99158, 0.99183, 0.99208, 0.99234,
      0.9926,  0.99286, 0.99312, 0.99339, 0.99365, 0.99392, 0.99419, 0.99446,
      0.99474, 0.99501, 0.99529, 0.99556, 0.99584, 0.99612, 0.9964,  0.99669,
      0.99697, 0.99725, 0.99754, 0.99782, 0.99811, 0.9984,  0.99868, 0.99897,
      0.99926, 0.99954, 0.99983, 1.00012, 1.00041, 1.00069, 1.00098, 1.00127,
      1.00155, 1.00184, 1.00212, 1.0024,  1.00269, 1.00297, 1.00325, 1.00353,
      1.00381, 1.00409, 1.00437, 1.00464, 1.00492, 1.00519, 1.00546, 1.00573,
      1.006,   1.00626, 1.00653, 1.00679, 1.00705, 1.00731, 1.00756, 1.00781,
      1.00806, 1.00831, 1.00856, 1.0088,  1.00904, 1.00928, 1.00952, 1.00975,
      1.00998, 1.0102,  1.01043, 1.01065, 1.01087, 1.01108, 1.01129, 1.0115,
      1.0117,  1.01191, 1.0121,  1.0123,  1.01249, 1.01267, 1.01286, 1.01304,
      1.01321, 1.01338, 1.01355, 1.01371, 1.01387, 1.01403, 1.01418, 1.01433,
      1.01447, 1.01461, 1.01475, 1.01488, 1.015,   1.01513, 1.01524, 1.01536,
      1.01547, 1.01557, 1.01567, 1.01577, 1.01586, 1.01595, 1.01603, 1.0161,
      1.01618, 1.01625, 1.01631, 1.01637, 1.01642, 1.01647, 1.01652, 1.01656,
      1.01659, 1.01662, 1.01665, 1.01667, 1.01668, 1.0167,  1.0167,  1.0167,
      1.0167,  1.01669, 1.01668, 1.01666, 1.01664, 1.01661, 1.01658, 1.01655,
      1.0165,  1.01646, 1.01641, 1.01635, 1.01629, 1.01623, 1.01616, 1.01609,
      1.01601, 1.01592, 1.01584, 1.01575, 1.01565, 1.01555, 1.01544, 1.01533,
      1.01522, 1.0151,  1.01497, 1.01485, 1.01471, 1.01458, 1.01444, 1.01429,
      1.01414, 1.01399, 1.01383, 1.01367, 1.01351, 1.01334, 1.01317, 1.01299,
      1.01281, 1.01263, 1.01244, 1.01225, 1.01205, 1.01186, 1.01165, 1.01145,
      1.01124, 1.01103, 1.01081, 1.0106,  1.01037, 1.01015, 1.00992, 1.00969,
      1.00946, 1.00922, 1.00898, 1.00874, 1.0085,  1.00825, 1.008,   1.00775,
      1.0075,  1.00724, 1.00698, 1.00672, 1.00646, 1.0062,  1.00593, 1.00566,
      1.00539, 1.00512, 1.00485, 1.00457, 1.0043,  1.00402, 1.00374, 1.00346,
      1.00318, 1.0029,  1.00262, 1.00234, 1.00205, 1.00177, 1.00148, 1.00119,
      1.00091, 1.00062, 1.00033, 1.00005, 0.99976, 0.99947, 0.99918, 0.9989,
      0.99861, 0.99832, 0.99804, 0.99775, 0.99747, 0.99718, 0.9969,  0.99662,
      0.99634, 0.99605, 0.99577, 0.9955,  0.99522, 0.99494, 0.99467, 0.9944,
      0.99412, 0.99385, 0.99359, 0.99332, 0.99306, 0.99279, 0.99253, 0.99228,
      0.99202, 0.99177, 0.99152, 0.99127, 0.99102, 0.99078, 0.99054, 0.9903,
      0.99007, 0.98983, 0.98961, 0.98938, 0.98916, 0.98894, 0.98872, 0.98851,
      0.9883,  0.98809, 0.98789, 0.98769, 0.9875,  0.98731, 0.98712, 0.98694,
      0.98676, 0.98658, 0.98641, 0.98624, 0.98608, 0.98592, 0.98577, 0.98562,
      0.98547, 0.98533, 0.98519, 0.98506, 0.98493, 0.98481, 0.98469, 0.98457,
      0.98446, 0.98436, 0.98426, 0.98416, 0.98407, 0.98399, 0.98391, 0.98383,
      0.98376, 0.9837,  0.98363, 0.98358, 0.98353, 0.98348, 0.98344, 0.9834,
      0.98337, 0.98335, 0.98333, 0.98331};
  static const double esun_L4[7] = {1983.0, 1795.0, 1539.0, 1028.0,
                                    219.8,  -1.0,   83.49};
  static const double esun_L5[7] = {1983.0, 1796.0, 1536.0, 1031.0,
                                    220.0,  -1.0,   83.44};
  static const double esun_L7[7] = {1997.0, 1812.0, 1533.0, 1039.0,
                                    230.8,  -1.0,   84.9};
  emxArray_boolean_T *r;
  emxArray_boolean_T *r2;
  emxArray_boolean_T *r4;
  emxArray_int32_T *r5;
  double ESUN[7];
  double b_tmp;
  double im_B1_tmp;
  double y;
  float a;
  float b_a;
  float c_a;
  float d_a;
  float e_a;
  float f_a;
  float g_a;
  float *im_B1_data;
  float *im_B2_data;
  float *im_B3_data;
  float *im_B4_data;
  float *im_B5_data;
  float *im_B7_data;
  float *im_th_data;
  int b_loop_ub_tmp;
  int c_loop_ub_tmp;
  int i;
  int i1;
  int i2;
  int i3;
  int loop_ub;
  int loop_ub_tmp;
  int *r6;
  boolean_T *B1Satu_data;
  boolean_T *r1;
  boolean_T *r3;
  (void)reso_thm;
  (void)bbox;
  (void)azi;
  (void)zc;
  im_B7_data = im_B7->data;
  im_th_data = im_th->data;
  im_B5_data = im_B5->data;
  im_B4_data = im_B4->data;
  im_B3_data = im_B3->data;
  im_B2_data = im_B2->data;
  im_B1_data = im_B1->data;
  /*  convert DNs to TOA ref and BT */
  /*  Revisions: */
  /*  Add Landsat 9 (Shi 2/17/2022) */
  /*  Cannot use the GRIDobj to read our band, because it may result in Nan
   * data. */
  /*  (Shi 2/26/2018) */
  /*  Added a target image based on blue band, which will be helpfull to */
  /*  resample and reproject the auxiliary data.  (Shi 2/16/2018) */
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
  /*  3) trgt = Target Grid Object */
  /*  4) ijdim = [nrows,ncols]; % dimension of optical bands */
  /*  5) ul = [upperleft_mapx upperleft_mapy]; */
  /*  6) zen = solar zenith angle (degrees); */
  /*  7) azi = solar azimuth angle (degrees); */
  /*  8) zc = Zone Number */
  /*  9,10,11) Saturation (true) in the Visible bands */
  /*  12) resolution of Fmask results */
  /*  % % fprintf('Read in header information & TIF images\n'); */
  /* [Lmax,Lmin,Qcalmax,Qcalmin,Refmax,Refmin,ijdim_ref,ijdim_thm,reso_ref,...
   */
  /*    reso_thm,ul,bbox,zen,azi,zc,Lnum,doy]=lndhdrread(path_top,filename); */
  /*  earth-sun distance see G. Chander et al. RSE 113 (2009) 893-903 */
  /* if Lnum >= 4 && Lnum <= 7 */
  /*  LPGS Upper lef corner alignment (see Landsat handbook for detail) */
  ul[0] -= 15.0;
  ul[1] += 15.0;
  resolu[0] = reso_ref;
  resolu[1] = reso_ref;
  /*  Read in all bands */
  /*  Band1 */
  /*      n_B1=dir(fullfile(path_top,'L*B1*')); */
  /*      if isempty(n_B1) */
  /*          n_B1=dir(fullfile(path_top,'L*b1*')); */
  /*      end */
  /*      im_B1=single(imread(fullfile(path_top,n_B1.name))); */
  /*      % Band2 */
  /*      % Also used to be target or referenced image when resampling and
   * reprojecting to the image extent and resolution. */
  /*      n_B2=dir(fullfile(path_top,'L*B2*')); */
  /*      if isempty(n_B2) */
  /*          n_B2=dir(fullfile(path_top,'L*b2*')); */
  /*      end */
  /*      im_B2=single(imread(fullfile(path_top,n_B2.name))); */
  /*      trgt = GRIDobj(fullfile(path_top,n_B2.name)); */
  /*  %     im_B2=single(trgt.Z); */
  /*      trgt.Z=[];% remove non-used values to save memory. */
  /*   */
  /*      % Band3 */
  /*      n_B3=dir(fullfile(path_top,'L*B3*')); */
  /*      if isempty(n_B3) */
  /*          n_B3=dir(fullfile(path_top,'L*b3*')); */
  /*      end */
  /*      im_B3=single(imread(fullfile(path_top,n_B3.name))); */
  /*      % Band4 */
  /*      n_B4=dir(fullfile(path_top,'L*B4*')); */
  /*      if isempty(n_B4) */
  /*          n_B4=dir(fullfile(path_top,'L*b4*')); */
  /*      end */
  /*      im_B4=single(imread(fullfile(path_top,n_B4.name))); */
  /*      % Band5 */
  /*      n_B5=dir(fullfile(path_top,'L*B5*')); */
  /*      if isempty(n_B5) */
  /*          n_B5=dir(fullfile(path_top,'L*b5*')); */
  /*      end */
  /*      im_B5=single(imread(fullfile(path_top,n_B5.name))); */
  /*      % Band6 */
  /*      if Lnum==7 */
  /*          n_B6=dir(fullfile(path_top,'L*B6*1*')); */
  /*          if isempty(n_B6) */
  /*              n_B6=dir(fullfile(path_top,'L*b6*1*')); */
  /*          end */
  /*      else */
  /*          n_B6=dir(fullfile(path_top,'L*B6*')); */
  /*          if isempty(n_B6) */
  /*              n_B6=dir(fullfile(path_top,'L*b6*')); */
  /*          end */
  /*      end */
  /*      im_th=single(imread(fullfile(path_top,n_B6.name))); */
  /*      % check to see whether need to resample thermal band */
  /*      if reso_ref~=reso_thm */
  /*          % resmaple thermal band */
  /*          im_th=pixel2pixv([ul(2),ul(1)],[ul(2),ul(1)],... */
  /*              resolu,[reso_thm,reso_thm],... */
  /*              im_th,[ijdim_ref(2),ijdim_ref(1)],[ijdim_thm(2),ijdim_thm(1)]);
   */
  /*      end */
  /*      % Band7 */
  /*      n_B7=dir(fullfile(path_top,'L*B7*')); */
  /*      if isempty(n_B7) */
  /*          n_B7=dir(fullfile(path_top,'L*b7*')); */
  /*      end */
  /*      im_B7=single(imread(fullfile(path_top,n_B7.name))); */
  /*  only processing pixesl where all bands have values (id_mssing) */
  if (im_B1->size[0] == 1) {
    i = im_B2->size[0];
  } else {
    i = im_B1->size[0];
  }
  if (im_B1->size[1] == 1) {
    i1 = im_B2->size[1];
  } else {
    i1 = im_B1->size[1];
  }
  if (i == 1) {
    loop_ub = im_B3->size[0];
  } else {
    loop_ub = i;
  }
  if (i1 == 1) {
    loop_ub_tmp = im_B3->size[1];
  } else {
    loop_ub_tmp = i1;
  }
  if (loop_ub == 1) {
    b_loop_ub_tmp = im_B4->size[0];
  } else {
    b_loop_ub_tmp = loop_ub;
  }
  if (loop_ub_tmp == 1) {
    c_loop_ub_tmp = im_B4->size[1];
  } else {
    c_loop_ub_tmp = loop_ub_tmp;
  }
  emxInit_boolean_T(&r, 2);
  if (b_loop_ub_tmp == 1) {
    i2 = im_B5->size[0];
  } else {
    i2 = b_loop_ub_tmp;
  }
  if (c_loop_ub_tmp == 1) {
    i3 = im_B5->size[1];
  } else {
    i3 = c_loop_ub_tmp;
  }
  if ((im_B1->size[0] == im_B2->size[0]) &&
      (im_B1->size[1] == im_B2->size[1]) && (i == im_B3->size[0]) &&
      (i1 == im_B3->size[1]) && (loop_ub == im_B4->size[0]) &&
      (loop_ub_tmp == im_B4->size[1]) && (b_loop_ub_tmp == im_B5->size[0]) &&
      (c_loop_ub_tmp == im_B5->size[1]) && (i2 == im_th->size[0]) &&
      (i3 == im_th->size[1])) {
    i = r->size[0] * r->size[1];
    r->size[0] = im_B1->size[0];
    r->size[1] = im_B1->size[1];
    emxEnsureCapacity_boolean_T(r, i);
    r1 = r->data;
    loop_ub = im_B1->size[0] * im_B1->size[1];
    for (i = 0; i < loop_ub; i++) {
      r1[i] = ((im_B1_data[i] == 0.0F) || (im_B2_data[i] == 0.0F) ||
               (im_B3_data[i] == 0.0F) || (im_B4_data[i] == 0.0F) ||
               (im_B5_data[i] == 0.0F) || (im_th_data[i] == 0.0F));
    }
  } else {
    binary_expand_op(r, im_B1, im_B2, im_B3, im_B4, im_B5, im_th);
    r1 = r->data;
  }
  emxInit_boolean_T(&r2, 2);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = im_B7->size[0];
  r2->size[1] = im_B7->size[1];
  emxEnsureCapacity_boolean_T(r2, i);
  r3 = r2->data;
  c_loop_ub_tmp = im_B7->size[0] * im_B7->size[1];
  for (i = 0; i < c_loop_ub_tmp; i++) {
    r3[i] = (im_B7_data[i] == 0.0F);
  }
  /*  find pixels that are saturated in the visible bands */
  i = B1Satu->size[0] * B1Satu->size[1];
  B1Satu->size[0] = im_B1->size[0];
  B1Satu->size[1] = im_B1->size[1];
  emxEnsureCapacity_boolean_T(B1Satu, i);
  B1Satu_data = B1Satu->data;
  loop_ub_tmp = im_B1->size[0] * im_B1->size[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    B1Satu_data[i] = (im_B1_data[i] == 255.0F);
  }
  i = B2Satu->size[0] * B2Satu->size[1];
  B2Satu->size[0] = im_B2->size[0];
  B2Satu->size[1] = im_B2->size[1];
  emxEnsureCapacity_boolean_T(B2Satu, i);
  B1Satu_data = B2Satu->data;
  loop_ub = im_B2->size[0] * im_B2->size[1];
  for (i = 0; i < loop_ub; i++) {
    B1Satu_data[i] = (im_B2_data[i] == 255.0F);
  }
  i = B3Satu->size[0] * B3Satu->size[1];
  B3Satu->size[0] = im_B3->size[0];
  B3Satu->size[1] = im_B3->size[1];
  emxEnsureCapacity_boolean_T(B3Satu, i);
  B1Satu_data = B3Satu->data;
  b_loop_ub_tmp = im_B3->size[0] * im_B3->size[1];
  for (i = 0; i < b_loop_ub_tmp; i++) {
    B1Satu_data[i] = (im_B3_data[i] == 255.0F);
  }
  /*  ND to radiance first */
  /*  % %     fprintf('From DNs to TOA ref & BT\n'); */
  a = (Lmax[0] - Lmin[0]) / (Qcalmax[0] - Qcalmin[0]);
  b_a = (Lmax[1] - Lmin[1]) / (Qcalmax[1] - Qcalmin[1]);
  c_a = (Lmax[2] - Lmin[2]) / (Qcalmax[2] - Qcalmin[2]);
  d_a = (Lmax[3] - Lmin[3]) / (Qcalmax[3] - Qcalmin[3]);
  e_a = (Lmax[4] - Lmin[4]) / (Qcalmax[4] - Qcalmin[4]);
  f_a = (Lmax[5] - Lmin[5]) / (Qcalmax[5] - Qcalmin[5]);
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
  /*  compute TOA reflectances */
  /*  converted from degrees to radiance */
  im_B1_tmp = cos(0.017453292519943295 * *zen);
  b_tmp = Tab_ES_Dist[(int)doy + 365];
  b_tmp *= b_tmp;
  y = ESUN[0] * im_B1_tmp;
  for (i = 0; i < loop_ub_tmp; i++) {
    im_B1_data[i] = 31415.9258F * (a * (im_B1_data[i] - Qcalmin[0]) + Lmin[0]) *
                    (float)b_tmp / (float)y;
  }
  y = ESUN[1] * im_B1_tmp;
  for (i = 0; i < loop_ub; i++) {
    im_B2_data[i] = 31415.9258F *
                    (b_a * (im_B2_data[i] - Qcalmin[1]) + Lmin[1]) *
                    (float)b_tmp / (float)y;
  }
  y = ESUN[2] * im_B1_tmp;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    im_B3_data[i] = 31415.9258F *
                    (c_a * (im_B3_data[i] - Qcalmin[2]) + Lmin[2]) *
                    (float)b_tmp / (float)y;
  }
  y = ESUN[3] * im_B1_tmp;
  loop_ub = im_B4->size[0] * im_B4->size[1];
  for (i = 0; i < loop_ub; i++) {
    im_B4_data[i] = 31415.9258F *
                    (d_a * (im_B4_data[i] - Qcalmin[3]) + Lmin[3]) *
                    (float)b_tmp / (float)y;
  }
  y = ESUN[4] * im_B1_tmp;
  loop_ub = im_B5->size[0] * im_B5->size[1];
  for (i = 0; i < loop_ub; i++) {
    im_B5_data[i] = 31415.9258F *
                    (e_a * (im_B5_data[i] - Qcalmin[4]) + Lmin[4]) *
                    (float)b_tmp / (float)y;
  }
  y = ESUN[6] * im_B1_tmp;
  for (i = 0; i < c_loop_ub_tmp; i++) {
    im_B7_data[i] = 31415.9258F *
                    (g_a * (im_B7_data[i] - Qcalmin[6]) + Lmin[6]) *
                    (float)b_tmp / (float)y;
  }
  /*  convert Band6 from radiance to BT */
  /*  fprintf('From Band 6 Radiance to Brightness Temperature\n'); */
  /*  see G. Chander et al. RSE 113 (2009) 893-903 */
  if (Lnum == 7.0) {
    im_B1_tmp = 666.09;
    b_tmp = 1282.71;
  } else if (Lnum == 5.0) {
    im_B1_tmp = 607.76;
    b_tmp = 1260.56;
  } else {
    im_B1_tmp = 671.62;
    b_tmp = 1284.3;
  }
  loop_ub = im_th->size[1];
  for (i = 0; i < loop_ub; i++) {
    loop_ub_tmp = im_th->size[0];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      im_th_data[i1 + im_th->size[0] * i] =
          (float)im_B1_tmp /
              (f_a * (im_th_data[i1 + im_th->size[0] * i] - Qcalmin[5]) +
               Lmin[5]) +
          1.0F;
    }
  }
  loop_ub_tmp = im_th->size[0] * im_th->size[1];
  for (loop_ub = 0; loop_ub < loop_ub_tmp; loop_ub++) {
    im_th_data[loop_ub] = logf(im_th_data[loop_ub]);
  }
  /*  convert from Kelvin to Celcius with 0.01 scale_facor */
  loop_ub = im_th->size[1];
  for (i = 0; i < loop_ub; i++) {
    loop_ub_tmp = im_th->size[0];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      im_th_data[i1 + im_th->size[0] * i] =
          100.0F *
          ((float)b_tmp / im_th_data[i1 + im_th->size[0] * i] - 273.15F);
    }
  }
  /*  get data ready for Fmask */
  emxInit_boolean_T(&r4, 2);
  if ((r->size[0] == r2->size[0]) && (r->size[1] == r2->size[1])) {
    i = r4->size[0] * r4->size[1];
    r4->size[0] = r->size[0];
    r4->size[1] = r->size[1];
    emxEnsureCapacity_boolean_T(r4, i);
    B1Satu_data = r4->data;
    loop_ub = r->size[0] * r->size[1];
    for (i = 0; i < loop_ub; i++) {
      B1Satu_data[i] = (r1[i] || r3[i]);
    }
  } else {
    b_or(r4, r, r2);
    B1Satu_data = r4->data;
  }
  emxFree_boolean_T(&r2);
  emxFree_boolean_T(&r);
  loop_ub = r4->size[0] * r4->size[1] - 1;
  loop_ub_tmp = 0;
  for (b_loop_ub_tmp = 0; b_loop_ub_tmp <= loop_ub; b_loop_ub_tmp++) {
    if (B1Satu_data[b_loop_ub_tmp]) {
      loop_ub_tmp++;
    }
  }
  emxInit_int32_T(&r5,1);
  i = r5->size[0];
  r5->size[0] = loop_ub_tmp;
  emxEnsureCapacity_int32_T(r5, i);
  r6 = r5->data;
  loop_ub_tmp = 0;
  for (b_loop_ub_tmp = 0; b_loop_ub_tmp <= loop_ub; b_loop_ub_tmp++) {
    if (B1Satu_data[b_loop_ub_tmp]) {
      r6[loop_ub_tmp] = b_loop_ub_tmp;
      loop_ub_tmp++;
    }
  }
  emxFree_boolean_T(&r4);
  c_loop_ub_tmp = r5->size[0] - 1;
  for (i = 0; i <= c_loop_ub_tmp; i++) {
    im_B1_data[r6[i]] = -9999.0F;
  }
  for (i = 0; i <= c_loop_ub_tmp; i++) {
    im_B2_data[r6[i]] = -9999.0F;
  }
  for (i = 0; i <= c_loop_ub_tmp; i++) {
    im_B3_data[r6[i]] = -9999.0F;
  }
  for (i = 0; i <= c_loop_ub_tmp; i++) {
    im_B4_data[r6[i]] = -9999.0F;
  }
  for (i = 0; i <= c_loop_ub_tmp; i++) {
    im_B5_data[r6[i]] = -9999.0F;
  }
  loop_ub = r5->size[0];
  for (i = 0; i < loop_ub; i++) {
    im_th_data[r6[i]] = -9999.0F;
  }
  for (i = 0; i <= c_loop_ub_tmp; i++) {
    im_B7_data[r6[i]] = -9999.0F;
  }
  emxFree_int32_T(&r5);
  i = (int)ijdim_ref[0];
  i1 = TOAref->size[0] * TOAref->size[1] * TOAref->size[2];
  TOAref->size[0] = i;
  loop_ub = (int)ijdim_ref[1];
  TOAref->size[1] = loop_ub;
  TOAref->size[2] = 6;
  emxEnsureCapacity_real32_T(TOAref, i1);
  im_th_data = TOAref->data;
  loop_ub = i * loop_ub * 6;
  for (i = 0; i < loop_ub; i++) {
    im_th_data[i] = 0.0F;
  }
  /*  Band1,2,3,4,5,&7 */
  loop_ub = im_B1->size[1];
  for (i = 0; i < loop_ub; i++) {
    loop_ub_tmp = im_B1->size[0];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      im_th_data[i1 + TOAref->size[0] * i] =
          im_B1_data[i1 + im_B1->size[0] * i];
    }
  }
  loop_ub = im_B2->size[1];
  for (i = 0; i < loop_ub; i++) {
    loop_ub_tmp = im_B2->size[0];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      im_th_data[(i1 + TOAref->size[0] * i) +
                 TOAref->size[0] * TOAref->size[1]] =
          im_B2_data[i1 + im_B2->size[0] * i];
    }
  }
  loop_ub = im_B3->size[1];
  for (i = 0; i < loop_ub; i++) {
    loop_ub_tmp = im_B3->size[0];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      im_th_data[(i1 + TOAref->size[0] * i) +
                 TOAref->size[0] * TOAref->size[1] * 2] =
          im_B3_data[i1 + im_B3->size[0] * i];
    }
  }
  loop_ub = im_B4->size[1];
  for (i = 0; i < loop_ub; i++) {
    loop_ub_tmp = im_B4->size[0];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      im_th_data[(i1 + TOAref->size[0] * i) +
                 TOAref->size[0] * TOAref->size[1] * 3] =
          im_B4_data[i1 + im_B4->size[0] * i];
    }
  }
  loop_ub = im_B5->size[1];
  for (i = 0; i < loop_ub; i++) {
    loop_ub_tmp = im_B5->size[0];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      im_th_data[(i1 + TOAref->size[0] * i) +
                 TOAref->size[0] * TOAref->size[1] * 4] =
          im_B5_data[i1 + im_B5->size[0] * i];
    }
  }
  loop_ub = im_B7->size[1];
  for (i = 0; i < loop_ub; i++) {
    loop_ub_tmp = im_B7->size[0];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      im_th_data[(i1 + TOAref->size[0] * i) +
                 TOAref->size[0] * TOAref->size[1] * 5] =
          im_B7_data[i1 + im_B7->size[0] * i];
    }
  }
  /*  elseif Lnum == 8 || Lnum == 9 */
  /*      LPGS Upper lef corner alignment (see Landsat handbook for detail) */
  /*      ul(1)=ul(1)-15; */
  /*      ul(2)=ul(2)+15; */
  /*      resolu=[reso_ref,reso_ref]; */
  /*      Read in all bands */
  /*      Band2 */
  /*      n_B2=dir(fullfile(path_top,'L*B2*')); */
  /*      if isempty(n_B2) */
  /*          n_B2=dir(fullfile(path_top,'L*b2*')); */
  /*      end */
  /*      im_B2=single(imread(fullfile(path_top,n_B2(1).name))); clear n_B2; */
  /*      % Band3 */
  /*      % Also used to be target or referenced image when resampling and
   * reprojecting to the image extent and resolution. */
  /*      n_B3=dir(fullfile(path_top,'L*B3*')); */
  /*      if isempty(n_B3) */
  /*          n_B3=dir(fullfile(path_top,'L*b3*')); */
  /*      end */
  /*      im_B3=single(imread(fullfile(path_top,n_B3(1).name))); */
  /*      trgt = GRIDobj(fullfile(path_top,n_B3.name)); clear n_B3; */
  /*  %     im_B3=single(trgt.Z); */
  /*      trgt.Z=[];% remove non-used values to save memory. */
  /*   */
  /*      % Band4 */
  /*      n_B4=dir(fullfile(path_top,'L*B4*')); */
  /*      if isempty(n_B4) */
  /*          n_B4=dir(fullfile(path_top,'L*b4*')); */
  /*      end */
  /*      im_B4=single(imread(fullfile(path_top,n_B4(1).name))); clear n_B4; */
  /*      % Band5 */
  /*      n_B5=dir(fullfile(path_top,'L*B5*')); */
  /*      if isempty(n_B5) */
  /*          n_B5=dir(fullfile(path_top,'L*b5*')); */
  /*      end */
  /*      im_B5=single(imread(fullfile(path_top,n_B5(1).name))); clear n_B5; */
  /*      % Band6 */
  /*      n_B6=dir(fullfile(path_top,'L*B6*')); */
  /*      if isempty(n_B6) */
  /*          n_B6=dir(fullfile(path_top,'L*b6*')); */
  /*      end */
  /*      im_B6=single(imread(fullfile(path_top,n_B6(1).name))); clear n_B6; */
  /*      % Band7 */
  /*      n_B7=dir(fullfile(path_top,'L*B7*')); */
  /*      if isempty(n_B7) */
  /*          n_B7=dir(fullfile(path_top,'L*b7*')); */
  /*      end */
  /*      im_B7=single(imread(fullfile(path_top,n_B7(1).name))); clear n_B7; */
  /*      % Band9 */
  /*      n_B9=dir(fullfile(path_top,'L*B9.*')); */
  /*      if isempty(n_B9) */
  /*          n_B9=dir(fullfile(path_top,'L*b9.*')); */
  /*      end */
  /*      im_B9=single(imread(fullfile(path_top,n_B9(1).name))); clear n_B9; */
  /*      % Band10 */
  /*      n_B10=dir(fullfile(path_top,'L*B10*')); */
  /*      if isempty(n_B10) */
  /*          n_B10=dir(fullfile(path_top,'L*b10*')); */
  /*      end */
  /*      im_B10=single(imread(fullfile(path_top,n_B10(1).name))); clear n_B10
   * path_top; */
  /*   */
  /*      % check to see whether need to resample thermal band */
  /*      if reso_ref~=reso_thm */
  /*          % resmaple thermal band */
  /*          im_B10=pixel2pixv([ul(2),ul(1)],[ul(2),ul(1)],... */
  /*              resolu,[reso_thm,reso_thm],... */
  /*              im_B10,[ijdim_ref(2),ijdim_ref(1)],[ijdim_thm(2),ijdim_thm(1)]);
   */
  /*      end */
  /*   */
  /*      % only processing pixesl where all bands have values (id_mssing) */
  /*      id_missing=im_B2==0|im_B3==0|im_B4==0|im_B5==0|im_B6==0|im_B7==0|im_B9==0|im_B10==0;
   */
  /*      % find pixels that are saturated in the visible bands */
  /*      B1Satu=im_B2==65535; */
  /*      B2Satu=im_B3==65535;n */
  /*      B3Satu=im_B4==65535; */
  /*   */
  /*      % ND to TOA reflectance with 0.0001 scale_facor */
  /*  % % %     fprintf('From DNs to TOA ref & BT\n'); */
  /*      im_B2=((Refmax(1)-Refmin(1))/(Qcalmax(1)-Qcalmin(1)))*(im_B2-Qcalmin(1))+Refmin(1);
   */
  /*      im_B3=((Refmax(2)-Refmin(2))/(Qcalmax(2)-Qcalmin(2)))*(im_B3-Qcalmin(2))+Refmin(2);
   */
  /*      im_B4=((Refmax(3)-Refmin(3))/(Qcalmax(3)-Qcalmin(3)))*(im_B4-Qcalmin(3))+Refmin(3);
   */
  /*      im_B5=((Refmax(4)-Refmin(4))/(Qcalmax(4)-Qcalmin(4)))*(im_B5-Qcalmin(4))+Refmin(4);
   */
  /*      im_B6=((Refmax(5)-Refmin(5))/(Qcalmax(5)-Qcalmin(5)))*(im_B6-Qcalmin(5))+Refmin(5);
   */
  /*      im_B7=((Refmax(6)-Refmin(6))/(Qcalmax(6)-Qcalmin(6)))*(im_B7-Qcalmin(6))+Refmin(6);
   */
  /*      im_B9=((Refmax(7)-Refmin(7))/(Qcalmax(7)-Qcalmin(7)))*(im_B9-Qcalmin(7))+Refmin(7);
   */
  /*      im_B10=((Lmax(8)-Lmin(8))/(Qcalmax(8)-Qcalmin(8)))*(im_B10-Qcalmin(8))+Lmin(8);
   */
  /*   */
  /*      % compute TOA reflectances */
  /*      % with a correction for the sun angle */
  /*      s_zen=deg2rad(zen); */
  /*      im_B2=10^4*im_B2/cos(s_zen); */
  /*      im_B3=10^4*im_B3/cos(s_zen); */
  /*      im_B4=10^4*im_B4/cos(s_zen); */
  /*      im_B5=10^4*im_B5/cos(s_zen); */
  /*      im_B6=10^4*im_B6/cos(s_zen); */
  /*      im_B7=10^4*im_B7/cos(s_zen); */
  /*      im_B9=10^4*im_B9/cos(s_zen); */
  /*   */
  /*      % convert Band6 from radiance to BT */
  /*      % fprintf('From Band 6 Radiance to Brightness Temperature\n'); */
  /*      K1_B10 =  774.89; */
  /*      K2_B10 = 1321.08; */
  /*   */
  /*      im_B10=K2_B10./log((K1_B10./im_B10)+1); */
  /*   */
  /*      % convert from Kelvin to Celcius with 0.01 scale_facor */
  /*      im_B10=100*(im_B10-273.15); */
  /*   */
  /*      % get data ready for Fmask */
  /*      im_B2(id_missing)=-9999; */
  /*      im_B3(id_missing)=-9999; */
  /*      im_B4(id_missing)=-9999; */
  /*      im_B5(id_missing)=-9999; */
  /*      im_B6(id_missing)=-9999; */
  /*      im_B7(id_missing)=-9999; */
  /*      im_B9(id_missing)=-9999; */
  /*      im_B10(id_missing) = -9999; */
  /*      clear id_missing; % empty memory */
  /*   */
  /*      TOAref=zeros(ijdim_ref(1),ijdim_ref(2),7,'single');% Band
   * 2,3,4,5,6,7,& 9 */
  /*      TOAref(:,:,1)=im_B2; clear im_B2; */
  /*      TOAref(:,:,2)=im_B3; clear im_B3; */
  /*      TOAref(:,:,3)=im_B4; clear im_B4; */
  /*      TOAref(:,:,4)=im_B5; clear im_B5; */
  /*      TOAref(:,:,5)=im_B6; clear im_B6; */
  /*      TOAref(:,:,6)=im_B7; clear im_B7; */
  /*      TOAref(:,:,7)=im_B9; clear im_B9; */
  /*   */
  /*      im_th=zeros(ijdim_ref(1),ijdim_ref(2),'single');% Band 10  */
  /*      im_th(:,:) = im_B10; clear im_B10;  */
  /*  else */
  /*      fprintf('This sensor is not Landsat 4, 5, 7, or 8!\n'); */
  /*      return; */
  /* end */
}

/* End of code generation (nd2toarbt.c) */
