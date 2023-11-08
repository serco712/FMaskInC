/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fcssm.c
 *
 * Code generation for function 'fcssm'
 *
 */

/* Include files */
#include "fcssm.h"
#include "Fmask_emxutil.h"
#include "Fmask_rtwutil.h"
#include "Fmask_types.h"
#include "bwlabel.h"
#include "find.h"
#include "horzcatStructList.h"
#include "imdilate.h"
#include "ismember.h"
#include "minOrMax.h"
#include "regionprops.h"
#include "strel.h"
#include "sum.h"
#include <math.h>
#include <stdio.h>

/* Function Declarations */
static void binary_expand_op_21(emxArray_real_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real_T *in3, double in4);

static void binary_expand_op_22(emxArray_real_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real_T *in3, double in4);

/* Function Definitions */
static void binary_expand_op_21(emxArray_real_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real_T *in3, double in4)
{
  const double *in2_data;
  const double *in3_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in3_data = in3->data;
  in2_data = in2->data;
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    in1_data[i + in1->size[0]] = in2_data[i * stride_0_0 + in2->size[0]] +
                                 in3_data[i * stride_1_0] * in4;
  }
}

static void binary_expand_op_22(emxArray_real_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real_T *in3, double in4)
{
  const double *in2_data;
  const double *in3_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in3_data = in3->data;
  in2_data = in2->data;
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in2_data[i * stride_0_0] + in3_data[i * stride_1_0] * in4;
  }
}

double fcssm(double Sun_zen, double Sun_azi, double ptm,
             const emxArray_uint8_T *Water, emxArray_uint8_T *Snow,
             const emxArray_uint8_T *plcim, const emxArray_uint8_T *plsim,
             const double ijDim[2], const double resolu[4], double cldpix,
             double sdpix, double snpix)
{
  b_emxArray_struct_T *xys;
  b_struct_T *xys_data;
  c_emxArray_images_internal_code *SEc_StrelArray;
  c_emxArray_images_internal_code *SEs_StrelArray;
  emxArray_boolean_T *b_area_final;
  emxArray_boolean_T *out_id;
  emxArray_boolean_T *segm_cloud_tmp;
  emxArray_cell_wrap_14 *SEc_DecomposedStrelArray;
  emxArray_cell_wrap_14 *SEs_DecomposedStrelArray;
  emxArray_int32_T *ii;
  emxArray_int32_T *jj;
  emxArray_int32_T *r;
  emxArray_int8_T *shadow_test;
  emxArray_real_T *XY_type;
  emxArray_real_T *area_final;
  emxArray_real_T *dist_move;
  emxArray_real_T *orin_xys;
  emxArray_real_T *segm_cloud_init;
  emxArray_real_T *tmp_XY_type;
  emxArray_real_T *tmp_srow;
  emxArray_real_T *tmp_xys;
  emxArray_struct_T *s;
  emxArray_uint8_T b_boundary_test;
  emxArray_uint8_T b_cloud_test;
  emxArray_uint8_T *boundary_test;
  emxArray_uint8_T *cloud_cal;
  emxArray_uint8_T *cloud_test;
  emxArray_uint8_T *cs_final;
  emxArray_uint8_T *shadow_cal;
  double clr_pct;
  double sub_size;
  double sun_tazi_rad;
  double win_height;
  double win_width;
  double *area_final_data;
  double *dist_move_data;
  double *orin_xys_data;
  double *segm_cloud_init_data;
  double *tmp_XY_type_data;
  double *tmp_srow_data;
  double *tmp_xys_data;
  int b_i;
  int b_ijDim;
  int c_boundary_test;
  int cloud_type;
  int d_boundary_test;
  int end_tmp;
  int i;
  int i1;
  int k;
  int loop_ub;
  int loop_ub_tmp;
  int nx;
  int tmp_id_tmp_idx_0_tmp;
  int vlen;
  int *ii_data;
  int *jj_data;
  const unsigned char *Water_data;
  const unsigned char *plcim_data;
  const unsigned char *plsim_data;
  unsigned char *Snow_data;
  unsigned char *boundary_test_data;
  unsigned char *cloud_cal_data;
  unsigned char *cloud_test_data;
  unsigned char *cs_final_data;
  unsigned char *shadow_cal_data;
  signed char *shadow_test_data;
  boolean_T guard1;
  boolean_T *out_id_data;
  boolean_T *segm_cloud_tmp_data;
  plsim_data = plsim->data;
  plcim_data = plcim->data;
  Snow_data = Snow->data;
  Water_data = Water->data;
  /*  Function for Cloud, cloud Shadow, and Snow Masking 2.1sav */
  /*  */
  /*  History of revisions: */
  /*  calculate cloud DEM with recorded height (Zhe 08/19/2015) */
  /*  exclude small cloud object < 3 pixels (Zhe 10/27/2013) */
  /*  Fix bug in calculating r_obj and change num_pix value (Zhe 09/27/2013) */
  /*  Output clear pixel percent for the whole Landsat image (Zhe 09/13/2013) */
  /*  Change Tbuffer to 0.95 to fix ealier stops in cloud shadow match (Zhe
   * 03/01/2013) */
  /*  change the Fmask band name to "*Fmask" (Zhe 09/27/2012) */
  /*  dilate snow by default 3 pixels in 8 connect directions (Zhe 05/24/2012)
   */
  /*  exclude small cloud object <= 9 pixels (Zhe 3/07/2012) */
  /*  cloud shadow do not have to overlap with potential cloud shadow layer (Zhe
   * 04/24/2011) */
  /*  dilate shadow again (3 pixels as default) (Zhe 12/23/2010); */
  /*  similarity < 0.95 (Zhe 11/06/2010) */
  /*  boosts data by >5/9 (Zhe Zhu 12/08/2009) */
  /*  use temperature to narrow iteration height (Zhe 12/09/2009) */
  /*  fixed bug for height (Zhe 12/09/2009) */
  /*  cloud DEM by thermal in cloud and shadow match (Zhe 1/03/2009) */
  /*  fprintf('Read in potential mask ...\n'); */
  /*  solar elevation angle */
  /*  solar azimuth anngle */
  sun_tazi_rad = 0.017453292519943295 * (Sun_azi - 90.0);
  /*  [plcim,jiDim,jiUL,resolu,ZC]=enviread([dir_im,'plcloud']); */
  /*  plsim=enviread([dir_im,'plshadow']); */
  /*  assume resolu.x=resolu.y */
  sub_size = resolu[0];
  win_height = ijDim[0];
  win_width = ijDim[1];
  /*  potential cloud & shadow layer */
  emxInit_uint8_T(&cloud_test);
  tmp_id_tmp_idx_0_tmp = (int)ijDim[0];
  i = cloud_test->size[0] * cloud_test->size[1];
  cloud_test->size[0] = (int)ijDim[0];
  cloud_test->size[1] = (int)ijDim[1];
  emxEnsureCapacity_uint8_T(cloud_test, i);
  cloud_test_data = cloud_test->data;
  loop_ub_tmp = (int)ijDim[0] * (int)ijDim[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    cloud_test_data[i] = 0U;
  }
  emxInit_int8_T(&shadow_test, 2);
  i = shadow_test->size[0] * shadow_test->size[1];
  shadow_test->size[0] = (int)ijDim[0];
  shadow_test->size[1] = (int)ijDim[1];
  emxEnsureCapacity_int8_T(shadow_test, i);
  shadow_test_data = shadow_test->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    shadow_test_data[i] = 0;
  }
  /*  matched cloud & shadow layer */
  emxInit_uint8_T(&shadow_cal);
  i = shadow_cal->size[0] * shadow_cal->size[1];
  shadow_cal->size[0] = (int)ijDim[0];
  shadow_cal->size[1] = (int)ijDim[1];
  emxEnsureCapacity_uint8_T(shadow_cal, i);
  shadow_cal_data = shadow_cal->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    shadow_cal_data[i] = 0U;
  }
  emxInit_uint8_T(&cloud_cal);
  i = cloud_cal->size[0] * cloud_cal->size[1];
  cloud_cal->size[0] = (int)ijDim[0];
  cloud_cal->size[1] = (int)ijDim[1];
  emxEnsureCapacity_uint8_T(cloud_cal, i);
  cloud_cal_data = cloud_cal->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    cloud_cal_data[i] = 0U;
  }
  /*  cloud_height=zeros(ijDim);% cloud relative height (m) */
  /*  boundary layer */
  emxInit_uint8_T(&boundary_test);
  i = boundary_test->size[0] * boundary_test->size[1];
  boundary_test->size[0] = (int)ijDim[0];
  boundary_test->size[1] = (int)ijDim[1];
  emxEnsureCapacity_uint8_T(boundary_test, i);
  boundary_test_data = boundary_test->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    boundary_test_data[i] = 0U;
  }
  /*  final cloud, shadow and snow mask */
  emxInit_uint8_T(&cs_final);
  i = cs_final->size[0] * cs_final->size[1];
  cs_final->size[0] = (int)ijDim[0];
  cs_final->size[1] = (int)ijDim[1];
  emxEnsureCapacity_uint8_T(cs_final, i);
  cs_final_data = cs_final->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    cs_final_data[i] = 0U;
  }
  /*  get potential mask values */
  nx = plsim->size[0] * plsim->size[1] - 1;
  for (b_i = 0; b_i <= nx; b_i++) {
    if (plsim_data[b_i] == 1) {
      shadow_test_data[b_i] = 1;
    }
  }
  /*  plshadow layer */
  /*  empty memory */
  emxInit_real_T(&segm_cloud_init, 2);
  i = segm_cloud_init->size[0] * segm_cloud_init->size[1];
  segm_cloud_init->size[0] = plcim->size[0];
  segm_cloud_init->size[1] = plcim->size[1];
  emxEnsureCapacity_real_T(segm_cloud_init, i);
  segm_cloud_init_data = segm_cloud_init->data;
  nx = plcim->size[0] * plcim->size[1];
  for (i = 0; i < nx; i++) {
    segm_cloud_init_data[i] = plcim_data[i];
  }
  end_tmp = nx - 1;
  for (b_i = 0; b_i <= end_tmp; b_i++) {
    if (segm_cloud_init_data[b_i] < 255.0) {
      boundary_test_data[b_i] = 1U;
    }
  }
  /*  boundary layer */
  for (b_i = 0; b_i <= end_tmp; b_i++) {
    if (segm_cloud_init_data[b_i] == 1.0) {
      cloud_test_data[b_i] = 1U;
    }
  }
  /*  plcloud layer */
  /*  empty memory */
  /*  revised percent of cloud on the scene after plcloud */
  /*  no t test  => more than 99.9 % clouds and partly cloud over land */
  /*  => no match => rest are definite shadows */
  /*  cloud covers more than 90% of the scene */
  /*  => no match => rest are definite shadows */
  /*  fprintf('Cloud and cloud shadow matching ...\n'); */
  emxInit_struct_T(&s);
  emxInit_boolean_T(&segm_cloud_tmp, 2);
  emxInit_real_T(&area_final, 2);
  emxInit_struct_T1(&xys);
  emxInit_real_T(&XY_type, 2);
  emxInit_real_T(&tmp_XY_type, 2);
  emxInit_real_T(&tmp_xys, 2);
  emxInit_real_T(&orin_xys, 2);
  emxInit_boolean_T(&out_id, 1);
  emxInit_real_T(&tmp_srow, 1);
  d_emxInit_images_internal_coder(&SEc_StrelArray);
  emxInit_cell_wrap_14(&SEc_DecomposedStrelArray);
  d_emxInit_images_internal_coder(&SEs_StrelArray);
  emxInit_cell_wrap_14(&SEs_DecomposedStrelArray);
  emxInit_int32_T(&ii, 1);
  emxInit_int32_T(&jj, 1);
  emxInit_real_T(&dist_move, 1);
  emxInit_int32_T(&r, 1);
  emxInit_boolean_T(&b_area_final, 2);
  guard1 = false;
  if (ptm <= 0.1) {
    guard1 = true;
  } else {
    b_cloud_test = *cloud_test;
    b_ijDim = loop_ub_tmp;
    b_cloud_test.size = &b_ijDim;
    b_cloud_test.numDimensions = 1;
    b_boundary_test = *boundary_test;
    c_boundary_test = loop_ub_tmp;
    b_boundary_test.size = &c_boundary_test;
    b_boundary_test.numDimensions = 1;
    if (sum(&b_cloud_test) / sum(&b_boundary_test) >= 0.9) {
      guard1 = true;
    } else {
      double A;
      double B;
      double C;
      double i_step;
      double i_step_tmp;
      double i_vir;
      double i_xy;
      double omiga_par;
      double omiga_per;
      double record_h;
      double record_thresh;
      double thresh_match;
      double x_l;
      double x_l_tmp;
      double x_u;
      double x_ur;
      double y_l;
      double y_u;
      double y_u_tmp;
      printf("Cloud & cloud shadow matching ...\n");
      fflush(stdout);
      /*  define constants */
      /*  threshold for matching buffering */
      /*  max similarity threshold */
      /*  minimum matched cloud object (pixels) */
      /*  num_pix=3; % number of inward pixes (90m) for cloud base temperature
       */
      /*  % enviromental lapse rate 6.5 degrees/km */
      /*  % dry adiabatic lapse rate 9.8 degrees/km */
      /*  rate_elapse=6.5;% degrees/km */
      /*  rate_dlapse=9.8;% degrees/km */
      /*      fprintf('Set cloud similarity = %.3f\n',Tsimilar); */
      /*      fprintf('Set matching buffer = %.3f\n',Tbuffer); */
      /*      fprintf('Shadow match for cloud object >= %d pixels\n',num_cldoj);
       */
      i_step_tmp = tan(0.017453292519943295 * (90.0 - Sun_zen));
      i_step = 2.0 * resolu[0] * i_step_tmp;
      /*  move 2 pixel at a time */
      /*  get moving direction */
      i = segm_cloud_tmp->size[0] * segm_cloud_tmp->size[1];
      segm_cloud_tmp->size[0] = boundary_test->size[0];
      segm_cloud_tmp->size[1] = boundary_test->size[1];
      emxEnsureCapacity_boolean_T(segm_cloud_tmp, i);
      segm_cloud_tmp_data = segm_cloud_tmp->data;
      for (i = 0; i < loop_ub_tmp; i++) {
        segm_cloud_tmp_data[i] = (boundary_test_data[i] == 1);
      }
      eml_find(segm_cloud_tmp, ii, jj);
      jj_data = jj->data;
      ii_data = ii->data;
      i = dist_move->size[0];
      dist_move->size[0] = ii->size[0];
      emxEnsureCapacity_real_T(dist_move, i);
      dist_move_data = dist_move->data;
      loop_ub = ii->size[0];
      for (i = 0; i < loop_ub; i++) {
        dist_move_data[i] = ii_data[i];
      }
      i = tmp_srow->size[0];
      tmp_srow->size[0] = jj->size[0];
      emxEnsureCapacity_real_T(tmp_srow, i);
      tmp_srow_data = tmp_srow->data;
      loop_ub = jj->size[0];
      for (i = 0; i < loop_ub; i++) {
        tmp_srow_data[i] = jj_data[i];
      }
      thresh_match = minimum(dist_move, &nx);
      i_vir = maximum(dist_move, &vlen);
      i_xy = minimum(tmp_srow, &loop_ub);
      x_ur = maximum(tmp_srow, &b_i);
      /*  get view angle geometry */
      /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%(functions)%%%%%%%%%%%%%%%
       */
      /*  viewgeo function */
      /*  imput "x",j */
      /*  imput "y",i */
      /*  imput cloud height "h" */
      record_thresh = tmp_srow_data[nx - 1];
      x_u = (record_thresh + x_ur) / 2.0;
      x_l_tmp = tmp_srow_data[vlen - 1];
      x_l = (i_xy + x_l_tmp) / 2.0;
      y_u_tmp = dist_move_data[b_i - 1];
      y_u = (thresh_match + y_u_tmp) / 2.0;
      record_h = dist_move_data[loop_ub - 1];
      y_l = (record_h + i_vir) / 2.0;
      /*  get k of the upper left and right points */
      /*  get k of the lower left and right points */
      omiga_par = atan(((thresh_match - y_u_tmp) / (record_thresh - x_ur) +
                        (record_h - i_vir) / (i_xy - x_l_tmp)) /
                       2.0);
      /*  get the angle of parallel lines k (in pi) */
      /*  AX(j)+BY(i)+C=0 */
      A = y_u - y_l;
      B = x_l - x_u;
      C = y_l * x_u - x_l * y_u;
      omiga_per = atan(B / A);
      /*  get the angle which is perpendicular to the trace line */
      /*  Segmentate each cloud */
      /*      fprintf('Cloud segmentation & matching\n'); */
      bwlabel(cloud_test, segm_cloud_init);
      regionprops(segm_cloud_init, s);
      /*  filter out cloud object < than num_cldoj pixels */
      horzcatStructList(s, area_final);
      area_final_data = area_final->data;
      i = b_area_final->size[0] * b_area_final->size[1];
      b_area_final->size[0] = 1;
      b_area_final->size[1] = area_final->size[1];
      emxEnsureCapacity_boolean_T(b_area_final, i);
      segm_cloud_tmp_data = b_area_final->data;
      loop_ub = area_final->size[1];
      for (i = 0; i < loop_ub; i++) {
        segm_cloud_tmp_data[i] = (area_final_data[i] >= 3.0);
      }
      b_eml_find(b_area_final, ii);
      ii_data = ii->data;
      i = dist_move->size[0];
      dist_move->size[0] = ii->size[0];
      emxEnsureCapacity_real_T(dist_move, i);
      dist_move_data = dist_move->data;
      loop_ub = ii->size[0];
      for (i = 0; i < loop_ub; i++) {
        dist_move_data[i] = ii_data[i];
      }
      isMember(segm_cloud_init, dist_move, segm_cloud_tmp);
      segm_cloud_tmp_data = segm_cloud_tmp->data;
      thresh_match = b_bwlabel(segm_cloud_tmp, segm_cloud_init);
      segm_cloud_init_data = segm_cloud_init->data;
      regionprops(segm_cloud_init, s);
      horzcatStructList(s, area_final);
      area_final_data = area_final->data;
      /*  Get the x,y of each cloud */
      /*  Matrix used in recording the x,y */
      b_regionprops(segm_cloud_init, xys);
      xys_data = xys->data;
      /*  Use iteration to get the optimal move distance */
      /*  Calulate the moving cloud shadow */
      /*  height_num=zeros(1,num); % cloud relative height (m) */
      /*  cloud shadow match similarity (m) */
      i = (int)thresh_match;
      if ((int)thresh_match - 1 >= 0) {
        i1 = (int)(((i_step - 200.0) + 12000.0) / i_step);
      }
      for (cloud_type = 0; cloud_type < i; cloud_type++) {
        int base_h;
        boolean_T exitg1;
        /* fprintf('Shadow Match of the %d/%d_th cloud with %d */
        /* pixels\n',cloud_type,num,obj_num(cloud_type)); */
        /*  moving cloud xys */
        i_xy = area_final_data[cloud_type];
        k = XY_type->size[0] * XY_type->size[1];
        XY_type->size[0] = (int)i_xy;
        XY_type->size[1] = 2;
        emxEnsureCapacity_real_T(XY_type, k);
        tmp_srow_data = XY_type->data;
        nx = (int)i_xy << 1;
        for (k = 0; k < nx; k++) {
          tmp_srow_data[k] = 0.0;
        }
        /*  record the max threshold moving cloud xys */
        k = tmp_XY_type->size[0] * tmp_XY_type->size[1];
        tmp_XY_type->size[0] = (int)i_xy;
        tmp_XY_type->size[1] = 2;
        emxEnsureCapacity_real_T(tmp_XY_type, k);
        tmp_XY_type_data = tmp_XY_type->data;
        for (k = 0; k < nx; k++) {
          tmp_XY_type_data[k] = 0.0;
        }
        /*  corrected for view angle xys */
        k = tmp_xys->size[0] * tmp_xys->size[1];
        tmp_xys->size[0] = (int)i_xy;
        tmp_xys->size[1] = 2;
        emxEnsureCapacity_real_T(tmp_xys, k);
        tmp_xys_data = tmp_xys->data;
        for (k = 0; k < nx; k++) {
          tmp_xys_data[k] = 0.0;
        }
        /*  record the original xys */
        k = orin_xys->size[0] * orin_xys->size[1];
        orin_xys->size[0] = (int)i_xy;
        orin_xys->size[1] = 2;
        emxEnsureCapacity_real_T(orin_xys, k);
        orin_xys_data = orin_xys->data;
        for (k = 0; k < nx; k++) {
          orin_xys_data[k] = 0.0;
        }
        /*  record the original xys */
        loop_ub = xys_data[cloud_type].PixelList->size[0];
        for (k = 0; k < 2; k++) {
          for (b_i = 0; b_i < loop_ub; b_i++) {
            orin_xys_data[b_i + orin_xys->size[0] * k] =
                xys_data[cloud_type]
                    .PixelList
                    ->data[b_i + xys_data[cloud_type].PixelList->size[0] * k];
          }
        }
        /*  record this orinal ids */
        /* orin_cid=sub2ind(ijDim,orin_xys(:,2),orin_xys(:,1)); */
        /*           % Temperature of the cloud object */
        /*           temp_obj=Temp(orin_cid); */
        /*           % the base temperature for cloud */
        /*           % assume object is round r_obj is radium of object */
        /*           r_obj=sqrt(obj_num(cloud_type)/2*pi); */
        /*           % number of inward pixes for correct temperature */
        /*           %        num_pix=8; */
        /*           pct_obj=(r_obj-num_pix)^2/r_obj^2; */
        /*           pct_obj=min(pct_obj,1); % pct of edge pixel should be less
         * than 1 */
        /*           t_obj=quantile(temp_obj(:),pct_obj); */
        /*           % put the edge of the cloud the same value as t_obj */
        /*           temp_obj(temp_obj>t_obj)=t_obj; */
        /*  wet adiabatic lapse rate 6.5 degrees/km */
        /*  dry adiabatic lapse rate 9.8 degrees/km */
        /*         rate_wlapse=6.5;% degrees/km */
        /*         rate_dlapse=9.8;% degrees/km */
        /*  Max cloud base height (m) */
        /*  Min cloud base height (m) */
        /*  refine cloud height range (m) */
        /*           Min_cl_height=max(Min_cl_height,10*(t_templ-400-t_obj)/rate_dlapse);
         */
        /*           Max_cl_height=min(Max_cl_height,10*(t_temph+400-t_obj)); */
        /*  initialize height and similarity info */
        record_h = 0.0;
        record_thresh = 0.0;
        base_h = 0;
        exitg1 = false;
        while ((!exitg1) && (base_h <= i1 - 1)) {
          x_l_tmp = (double)base_h * i_step + 200.0;
          /*  iterate in height (m) */
          /*  Get the true postion of the cloud */
          /*  calculate cloud DEM with initial base height */
          /* (10*(t_obj-temp_obj)/rate_elapse+base_h); */
          /*  mat_truecloud function */
          /*  imput "x",j col */
          /*  imput "y",i row */
          /*  imput cloud height "h" */
          /*  average Landsat 4,5,&7 height (m) */
          x_u = sqrt(A * A + B * B);
          /*  from the cetral perpendicular (unit: pixel) */
          x_l = cos(omiga_per - omiga_par);
          k = dist_move->size[0];
          dist_move->size[0] = orin_xys->size[0];
          emxEnsureCapacity_real_T(dist_move, k);
          dist_move_data = dist_move->data;
          loop_ub = orin_xys->size[0];
          for (k = 0; k < loop_ub; k++) {
            dist_move_data[k] = ((A * orin_xys_data[k] +
                                  B * orin_xys_data[k + orin_xys->size[0]]) +
                                 C) /
                                x_u / x_l * x_l_tmp / 705000.0;
          }
          /*  cloud move distance (m); */
          y_u = cos(omiga_par);
          y_l = sin(omiga_par);
          /*  new x, j */
          /*  new y, i */
          if (orin_xys->size[0] == dist_move->size[0]) {
            loop_ub = orin_xys->size[0];
            for (k = 0; k < loop_ub; k++) {
              tmp_xys_data[k] = orin_xys_data[k] + dist_move_data[k] * y_u;
            }
          } else {
            binary_expand_op_22(tmp_xys, orin_xys, dist_move, y_u);
            tmp_xys_data = tmp_xys->data;
          }
          if (orin_xys->size[0] == dist_move->size[0]) {
            loop_ub = orin_xys->size[0];
            for (k = 0; k < loop_ub; k++) {
              tmp_xys_data[k + tmp_xys->size[0]] =
                  orin_xys_data[k + orin_xys->size[0]] +
                  dist_move_data[k] * y_l;
            }
          } else {
            binary_expand_op_21(tmp_xys, orin_xys, dist_move, y_l);
            tmp_xys_data = tmp_xys->data;
          }
          /*  shadow moved distance (pixel) */
          /*  i_xy=h*cos(sun_tazi_rad)/(sub_size*tan(sun_ele_rad)); */
          y_u_tmp = sub_size * i_step_tmp;
          i_xy = x_l_tmp / y_u_tmp;
          if (Sun_azi < 180.0) {
            x_ur = i_xy * cos(sun_tazi_rad);
            k = dist_move->size[0];
            dist_move->size[0] = tmp_xys->size[0];
            emxEnsureCapacity_real_T(dist_move, k);
            dist_move_data = dist_move->data;
            loop_ub = tmp_xys->size[0];
            for (k = 0; k < loop_ub; k++) {
              dist_move_data[k] = tmp_xys_data[k] - x_ur;
            }
            nx = dist_move->size[0];
            for (k = 0; k < nx; k++) {
              dist_move_data[k] = rt_roundd(dist_move_data[k]);
            }
            loop_ub = dist_move->size[0];
            for (k = 0; k < loop_ub; k++) {
              tmp_srow_data[k + XY_type->size[0]] = dist_move_data[k];
            }
            /*  X is for j,2 */
            i_xy *= sin(sun_tazi_rad);
            k = dist_move->size[0];
            dist_move->size[0] = tmp_xys->size[0];
            emxEnsureCapacity_real_T(dist_move, k);
            dist_move_data = dist_move->data;
            loop_ub = tmp_xys->size[0];
            for (k = 0; k < loop_ub; k++) {
              dist_move_data[k] = tmp_xys_data[k + tmp_xys->size[0]] - i_xy;
            }
            nx = dist_move->size[0];
            for (k = 0; k < nx; k++) {
              dist_move_data[k] = rt_roundd(dist_move_data[k]);
            }
            loop_ub = dist_move->size[0];
            for (k = 0; k < loop_ub; k++) {
              tmp_srow_data[k] = dist_move_data[k];
            }
            /*  Y is for i,1 */
          } else {
            x_ur = i_xy * cos(sun_tazi_rad);
            k = dist_move->size[0];
            dist_move->size[0] = tmp_xys->size[0];
            emxEnsureCapacity_real_T(dist_move, k);
            dist_move_data = dist_move->data;
            loop_ub = tmp_xys->size[0];
            for (k = 0; k < loop_ub; k++) {
              dist_move_data[k] = tmp_xys_data[k] + x_ur;
            }
            nx = dist_move->size[0];
            for (k = 0; k < nx; k++) {
              dist_move_data[k] = rt_roundd(dist_move_data[k]);
            }
            loop_ub = dist_move->size[0];
            for (k = 0; k < loop_ub; k++) {
              tmp_srow_data[k + XY_type->size[0]] = dist_move_data[k];
            }
            /*  X is for j,2 */
            i_xy *= sin(sun_tazi_rad);
            k = dist_move->size[0];
            dist_move->size[0] = tmp_xys->size[0];
            emxEnsureCapacity_real_T(dist_move, k);
            dist_move_data = dist_move->data;
            loop_ub = tmp_xys->size[0];
            for (k = 0; k < loop_ub; k++) {
              dist_move_data[k] = tmp_xys_data[k + tmp_xys->size[0]] + i_xy;
            }
            nx = dist_move->size[0];
            for (k = 0; k < nx; k++) {
              dist_move_data[k] = rt_roundd(dist_move_data[k]);
            }
            loop_ub = dist_move->size[0];
            for (k = 0; k < loop_ub; k++) {
              tmp_srow_data[k] = dist_move_data[k];
            }
            /*  Y is for i,1 */
          }
          /*  col */
          /*  row */
          /*  the id that is out of the image */
          k = out_id->size[0];
          out_id->size[0] = XY_type->size[0];
          emxEnsureCapacity_boolean_T(out_id, k);
          out_id_data = out_id->data;
          loop_ub = XY_type->size[0];
          for (k = 0; k < loop_ub; k++) {
            i_xy = tmp_srow_data[k];
            x_ur = tmp_srow_data[k + XY_type->size[0]];
            out_id_data[k] = ((i_xy < 1.0) || (i_xy > win_height) ||
                              (x_ur < 1.0) || (x_ur > win_width));
          }
          vlen = out_id->size[0];
          if (out_id->size[0] == 0) {
            nx = 0;
          } else {
            nx = out_id_data[0];
            for (k = 2; k <= vlen; k++) {
              nx += out_id_data[k - 1];
            }
          }
          end_tmp = out_id->size[0] - 1;
          vlen = 0;
          for (b_i = 0; b_i <= end_tmp; b_i++) {
            if (!out_id_data[b_i]) {
              vlen++;
            }
          }
          k = r->size[0];
          r->size[0] = vlen;
          emxEnsureCapacity_int32_T(r, k);
          jj_data = r->data;
          vlen = 0;
          for (b_i = 0; b_i <= end_tmp; b_i++) {
            if (!out_id_data[b_i]) {
              jj_data[vlen] = b_i;
              vlen++;
            }
          }
          k = dist_move->size[0];
          dist_move->size[0] = r->size[0];
          emxEnsureCapacity_real_T(dist_move, k);
          dist_move_data = dist_move->data;
          loop_ub = r->size[0];
          for (k = 0; k < loop_ub; k++) {
            dist_move_data[k] =
                (int)tmp_srow_data[jj_data[k]] +
                tmp_id_tmp_idx_0_tmp *
                    ((int)tmp_srow_data[jj_data[k] + XY_type->size[0]] - 1);
          }
          /*  the id that is matched (exclude original cloud) */
          /*  the id that is the total pixel (exclude original cloud) */
          k = out_id->size[0];
          out_id->size[0] = dist_move->size[0];
          emxEnsureCapacity_boolean_T(out_id, k);
          out_id_data = out_id->data;
          loop_ub = dist_move->size[0];
          for (k = 0; k < loop_ub; k++) {
            vlen = (int)dist_move_data[k] - 1;
            out_id_data[k] =
                ((boundary_test_data[vlen] == 0) ||
                 ((segm_cloud_init_data[vlen] != (double)cloud_type + 1.0) &&
                  ((cloud_test_data[vlen] > 0) ||
                   (shadow_test_data[vlen] == 1))));
          }
          vlen = out_id->size[0];
          if (out_id->size[0] == 0) {
            b_i = 0;
          } else {
            b_i = out_id_data[0];
            for (k = 2; k <= vlen; k++) {
              b_i += out_id_data[k - 1];
            }
          }
          k = out_id->size[0];
          out_id->size[0] = dist_move->size[0];
          emxEnsureCapacity_boolean_T(out_id, k);
          out_id_data = out_id->data;
          loop_ub = dist_move->size[0];
          for (k = 0; k < loop_ub; k++) {
            out_id_data[k] =
                (segm_cloud_init_data[(int)dist_move_data[k] - 1] !=
                 (double)cloud_type + 1.0);
          }
          vlen = out_id->size[0];
          if (out_id->size[0] == 0) {
            loop_ub = 0;
          } else {
            loop_ub = out_id_data[0];
            for (k = 2; k <= vlen; k++) {
              loop_ub += out_id_data[k - 1];
            }
          }
          thresh_match =
              ((double)b_i + (double)nx) / ((double)loop_ub + (double)nx);
          if ((thresh_match >= 0.95 * record_thresh) &&
              (x_l_tmp < 12000.0 - i_step) && (record_thresh < 0.95)) {
            if (thresh_match > record_thresh) {
              record_thresh = thresh_match;
              record_h = x_l_tmp;
            }
            base_h++;
          } else if (record_thresh > 0.3) {
            i_vir = record_h / y_u_tmp;
            /*  height_num=record_h; */
            /*  calculate cloud DEM with recorded height (Zhe 08/19/2015) */
            /*  mat_truecloud function */
            /*  imput "x",j col */
            /*  imput "y",i row */
            /*  imput cloud height "h" */
            /*  average Landsat 4,5,&7 height (m) */
            /*  from the cetral perpendicular (unit: pixel) */
            k = dist_move->size[0];
            dist_move->size[0] = orin_xys->size[0];
            emxEnsureCapacity_real_T(dist_move, k);
            dist_move_data = dist_move->data;
            loop_ub = orin_xys->size[0];
            for (k = 0; k < loop_ub; k++) {
              dist_move_data[k] = ((A * orin_xys_data[k] +
                                    B * orin_xys_data[k + orin_xys->size[0]]) +
                                   C) /
                                  x_u / x_l * record_h / 705000.0;
            }
            /*  cloud move distance (m); */
            /*  new x, j */
            /*  new y, i */
            if (orin_xys->size[0] == dist_move->size[0]) {
              loop_ub = orin_xys->size[0];
              for (k = 0; k < loop_ub; k++) {
                tmp_xys_data[k] = orin_xys_data[k] + dist_move_data[k] * y_u;
              }
            } else {
              binary_expand_op_22(tmp_xys, orin_xys, dist_move, y_u);
              tmp_xys_data = tmp_xys->data;
            }
            if (orin_xys->size[0] == dist_move->size[0]) {
              loop_ub = orin_xys->size[0];
              for (k = 0; k < loop_ub; k++) {
                tmp_xys_data[k + tmp_xys->size[0]] =
                    orin_xys_data[k + orin_xys->size[0]] +
                    dist_move_data[k] * y_l;
              }
            } else {
              binary_expand_op_21(tmp_xys, orin_xys, dist_move, y_l);
              tmp_xys_data = tmp_xys->data;
            }
            if (Sun_azi < 180.0) {
              thresh_match = i_vir * cos(sun_tazi_rad);
              k = dist_move->size[0];
              dist_move->size[0] = tmp_xys->size[0];
              emxEnsureCapacity_real_T(dist_move, k);
              dist_move_data = dist_move->data;
              loop_ub = tmp_xys->size[0];
              for (k = 0; k < loop_ub; k++) {
                dist_move_data[k] = tmp_xys_data[k] - thresh_match;
              }
              nx = dist_move->size[0];
              for (k = 0; k < nx; k++) {
                dist_move_data[k] = rt_roundd(dist_move_data[k]);
              }
              loop_ub = dist_move->size[0];
              for (k = 0; k < loop_ub; k++) {
                tmp_XY_type_data[k + tmp_XY_type->size[0]] = dist_move_data[k];
              }
              /*  X is for col j,2 */
              i_vir *= sin(sun_tazi_rad);
              k = dist_move->size[0];
              dist_move->size[0] = tmp_xys->size[0];
              emxEnsureCapacity_real_T(dist_move, k);
              dist_move_data = dist_move->data;
              loop_ub = tmp_xys->size[0];
              for (k = 0; k < loop_ub; k++) {
                dist_move_data[k] = tmp_xys_data[k + tmp_xys->size[0]] - i_vir;
              }
              nx = dist_move->size[0];
              for (k = 0; k < nx; k++) {
                dist_move_data[k] = rt_roundd(dist_move_data[k]);
              }
              loop_ub = dist_move->size[0];
              for (k = 0; k < loop_ub; k++) {
                tmp_XY_type_data[k] = dist_move_data[k];
              }
              /*  Y is for row i,1 */
            } else {
              thresh_match = i_vir * cos(sun_tazi_rad);
              k = dist_move->size[0];
              dist_move->size[0] = tmp_xys->size[0];
              emxEnsureCapacity_real_T(dist_move, k);
              dist_move_data = dist_move->data;
              loop_ub = tmp_xys->size[0];
              for (k = 0; k < loop_ub; k++) {
                dist_move_data[k] = tmp_xys_data[k] + thresh_match;
              }
              nx = dist_move->size[0];
              for (k = 0; k < nx; k++) {
                dist_move_data[k] = rt_roundd(dist_move_data[k]);
              }
              loop_ub = dist_move->size[0];
              for (k = 0; k < loop_ub; k++) {
                tmp_XY_type_data[k + tmp_XY_type->size[0]] = dist_move_data[k];
              }
              /*  X is for col j,2 */
              i_vir *= sin(sun_tazi_rad);
              k = dist_move->size[0];
              dist_move->size[0] = tmp_xys->size[0];
              emxEnsureCapacity_real_T(dist_move, k);
              dist_move_data = dist_move->data;
              loop_ub = tmp_xys->size[0];
              for (k = 0; k < loop_ub; k++) {
                dist_move_data[k] = tmp_xys_data[k + tmp_xys->size[0]] + i_vir;
              }
              nx = dist_move->size[0];
              for (k = 0; k < nx; k++) {
                dist_move_data[k] = rt_roundd(dist_move_data[k]);
              }
              loop_ub = dist_move->size[0];
              for (k = 0; k < loop_ub; k++) {
                tmp_XY_type_data[k] = dist_move_data[k];
              }
              /*  Y is for row i,1 */
            }
            k = dist_move->size[0];
            dist_move->size[0] = tmp_XY_type->size[0];
            emxEnsureCapacity_real_T(dist_move, k);
            dist_move_data = dist_move->data;
            loop_ub = tmp_XY_type->size[0];
            k = tmp_srow->size[0];
            tmp_srow->size[0] = tmp_XY_type->size[0];
            emxEnsureCapacity_real_T(tmp_srow, k);
            tmp_srow_data = tmp_srow->data;
            for (k = 0; k < loop_ub; k++) {
              dist_move_data[k] = tmp_XY_type_data[k + tmp_XY_type->size[0]];
              tmp_srow_data[k] = tmp_XY_type_data[k];
            }
            /*  put data within range */
            for (b_i = 0; b_i <= end_tmp; b_i++) {
              if (tmp_srow_data[b_i] < 1.0) {
                tmp_srow_data[b_i] = 1.0;
              }
            }
            for (b_i = 0; b_i <= end_tmp; b_i++) {
              if (tmp_srow_data[b_i] > win_height) {
                tmp_srow_data[b_i] = win_height;
              }
            }
            for (b_i = 0; b_i <= end_tmp; b_i++) {
              if (dist_move_data[b_i] < 1.0) {
                dist_move_data[b_i] = 1.0;
              }
            }
            for (b_i = 0; b_i <= end_tmp; b_i++) {
              if (dist_move_data[b_i] > win_width) {
                dist_move_data[b_i] = win_width;
              }
            }
            /*  give shadow_cal=1 */
            k = ii->size[0];
            ii->size[0] = tmp_srow->size[0];
            emxEnsureCapacity_int32_T(ii, k);
            ii_data = ii->data;
            loop_ub = tmp_srow->size[0];
            for (k = 0; k < loop_ub; k++) {
              ii_data[k] = (int)tmp_srow_data[k] +
                           tmp_id_tmp_idx_0_tmp * ((int)dist_move_data[k] - 1);
            }
            for (k = 0; k <= end_tmp; k++) {
              shadow_cal_data[ii_data[k] - 1] = 1U;
            }
            /*  record matched cloud */
            /*  cloud_cal(orin_cid)=1; */
            /*  cloud_height(orin_cid)=record_h; */
            /*  fprintf('cloud_type = %d & base_h = %d & rt_obj
             * =%d\n',cloud_type,base_h,t_obj); */
            exitg1 = true;
          } else {
            record_thresh = 0.0;
            base_h++;
          }
        }
      }
      /*  % dilate each cloud and shadow object by 3 and 3 pixel outward in 8
       * connect directions */
      /*     cldpix=3; % number of pixels to be dilated for cloud */
      /*     sdpix=3; % number of pixels to be dilated for shadow */
      /*     fprintf('Dilate %d pixels for cloud & %d pixels for shadow
       * objects\n',cldpix,sdpix); */
      strel_strel(2.0 * cldpix + 1.0, SEc_StrelArray, SEc_DecomposedStrelArray);
      strel_strel(2.0 * sdpix + 1.0, SEs_StrelArray, SEs_DecomposedStrelArray);
      /*  dialte shadow first */
      i = cloud_test->size[0] * cloud_test->size[1];
      cloud_test->size[0] = shadow_cal->size[0];
      cloud_test->size[1] = shadow_cal->size[1];
      emxEnsureCapacity_uint8_T(cloud_test, i);
      cloud_test_data = cloud_test->data;
      loop_ub = shadow_cal->size[0] * shadow_cal->size[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        cloud_test_data[i] = shadow_cal_data[i];
      }
      imdilate(cloud_test, SEs_StrelArray, SEs_DecomposedStrelArray,
               shadow_cal);
      shadow_cal_data = shadow_cal->data;
      /*      % find shadow within plshadow */
      /*      shadow_cal(shadow_test~=1)=0; */
      /*      % dilate shadow again with the more accurate cloud shadow */
      /*      shadow_cal=imdilate(shadow_cal,SEs); */
      i = cloud_test->size[0] * cloud_test->size[1];
      cloud_test->size[0] = segm_cloud_tmp->size[0];
      cloud_test->size[1] = segm_cloud_tmp->size[1];
      emxEnsureCapacity_uint8_T(cloud_test, i);
      cloud_test_data = cloud_test->data;
      loop_ub = segm_cloud_tmp->size[0] * segm_cloud_tmp->size[1];
      for (i = 0; i < loop_ub; i++) {
        cloud_test_data[i] = segm_cloud_tmp_data[i];
      }
      imdilate(cloud_test, SEc_StrelArray, SEc_DecomposedStrelArray, cloud_cal);
      cloud_cal_data = cloud_cal->data;
      /*  dilate snow by snpix pixels in 8 connect directions (Zhe 09/12/2012)
       */
      strel_strel(2.0 * snpix + 1.0, SEc_StrelArray, SEc_DecomposedStrelArray);
      i = cloud_test->size[0] * cloud_test->size[1];
      cloud_test->size[0] = Snow->size[0];
      cloud_test->size[1] = Snow->size[1];
      emxEnsureCapacity_uint8_T(cloud_test, i);
      cloud_test_data = cloud_test->data;
      loop_ub = Snow->size[0] * Snow->size[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        cloud_test_data[i] = Snow_data[i];
      }
      imdilate(cloud_test, SEc_StrelArray, SEc_DecomposedStrelArray, Snow);
      Snow_data = Snow->data;
    }
  }
  if (guard1) {
    printf("Skip cloud & cloud shadow matching because high cloud cover\n");
    fflush(stdout);
    end_tmp = loop_ub_tmp - 1;
    for (b_i = 0; b_i <= end_tmp; b_i++) {
      if (cloud_test_data[b_i] == 1) {
        cloud_cal_data[b_i] = 1U;
      }
    }
    for (b_i = 0; b_i <= end_tmp; b_i++) {
      if (cloud_test_data[b_i] == 0) {
        shadow_cal_data[b_i] = 1U;
      }
    }
    /*  similar_num=-1; */
    /*    height_num=-1; */
  }
  emxFree_boolean_T(&b_area_final);
  emxFree_int32_T(&r);
  emxFree_real_T(&dist_move);
  emxFree_int32_T(&jj);
  emxFree_int32_T(&ii);
  emxFree_cell_wrap_14(&SEs_DecomposedStrelArray);
  c_emxFree_images_internal_coder(&SEs_StrelArray);
  emxFree_cell_wrap_14(&SEc_DecomposedStrelArray);
  c_emxFree_images_internal_coder(&SEc_StrelArray);
  emxFree_real_T(&tmp_srow);
  emxFree_boolean_T(&out_id);
  emxFree_real_T(&orin_xys);
  emxFree_real_T(&tmp_xys);
  emxFree_real_T(&tmp_XY_type);
  emxFree_real_T(&XY_type);
  emxFree_struct_T1(&xys);
  emxFree_real_T(&area_final);
  emxFree_struct_T(&s);
  emxFree_real_T(&segm_cloud_init);
  emxFree_int8_T(&shadow_test);
  emxFree_uint8_T(&cloud_test);
  nx = Water->size[0] * Water->size[1] - 1;
  for (b_i = 0; b_i <= nx; b_i++) {
    if (Water_data[b_i] == 1) {
      cs_final_data[b_i] = 1U;
    }
  }
  /*  mask from plcloud */
  /*  step 1 snow or unknow */
  nx = Snow->size[0] * Snow->size[1] - 1;
  for (b_i = 0; b_i <= nx; b_i++) {
    if (Snow_data[b_i] == 1) {
      cs_final_data[b_i] = 3U;
    }
  }
  /*  snow */
  /*  step 2 shadow above snow and everyting */
  nx = shadow_cal->size[0] * shadow_cal->size[1] - 1;
  for (b_i = 0; b_i <= nx; b_i++) {
    if (shadow_cal_data[b_i] == 1) {
      cs_final_data[b_i] = 2U;
    }
  }
  emxFree_uint8_T(&shadow_cal);
  /* shadow */
  /*  step 3 cloud above all */
  nx = cloud_cal->size[0] * cloud_cal->size[1] - 1;
  for (b_i = 0; b_i <= nx; b_i++) {
    if (cloud_cal_data[b_i] == 1) {
      cs_final_data[b_i] = 4U;
    }
  }
  emxFree_uint8_T(&cloud_cal);
  /*  cloud */
  nx = loop_ub_tmp - 1;
  for (b_i = 0; b_i <= nx; b_i++) {
    if (boundary_test_data[b_i] == 0) {
      cs_final_data[b_i] = MAX_uint8_T;
    }
  }
  /*  reedit dir_im */
  /*  norln=strread(dir_im,'%s','delimiter','.');  */
  /*  n_name=char(norln(1)); */
  /*  enviwrite([n_name,'Fmask'],cs_final,'uint8',resolu,jiUL,'bsq',ZC); */
  /*  record clear pixel percent; */
  i = segm_cloud_tmp->size[0] * segm_cloud_tmp->size[1];
  segm_cloud_tmp->size[0] = cs_final->size[0];
  segm_cloud_tmp->size[1] = cs_final->size[1];
  emxEnsureCapacity_boolean_T(segm_cloud_tmp, i);
  segm_cloud_tmp_data = segm_cloud_tmp->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    segm_cloud_tmp_data[i] = (cs_final_data[i] <= 1);
  }
  emxFree_uint8_T(&cs_final);
  if (loop_ub_tmp == 0) {
    nx = 0;
  } else {
    nx = segm_cloud_tmp_data[0];
    for (k = 2; k <= loop_ub_tmp; k++) {
      nx += segm_cloud_tmp_data[k - 1];
    }
  }
  emxFree_boolean_T(&segm_cloud_tmp);
  b_boundary_test = *boundary_test;
  d_boundary_test = loop_ub_tmp;
  b_boundary_test.size = &d_boundary_test;
  b_boundary_test.numDimensions = 1;
  clr_pct = 100.0 * (double)nx / sum(&b_boundary_test);
  emxFree_uint8_T(&boundary_test);
  return clr_pct;
}

/* End of code generation (fcssm.c) */
