// /*
//  * Academic License - for use in teaching, academic research, and meeting
//  * course requirements at degree granting institutions only.  Not for
//  * government, commercial, or other organizational use.
//  *
//  * fcssm.c
//  *
//  * Code generation for function 'fcssm'
//  *
//  */

// /* Include files */
#include "fcssm.h"
#include "bwlabel.h"
#include "connected_components.h"
#include "viewgeo.h"
#include "imdilate.h"

//#include <bsp/bsp_printf.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

// // /* Function Declarations */
// // static void mat_truecloud(const emxArray_real_T *x, const emxArray_real_T *y,
// //                           double h, double A, double B, double C,
// //                           double omiga_par, double omiga_per,
// //                           emxArray_real_T *x_new, emxArray_real_T *y_new);

// // static double viewgeo(double x_ul, double y_ul, double x_ur, double y_ur,
// //                       double x_ll, double y_ll, double x_lr, double y_lr,
// //                       double *B, double *C, double *omiga_par,
// //                       double *omiga_per);

// // /* Function Definitions */

// #define IMG_SIZE 256*256

// unsigned char udata1[IMG_SIZE];
// //unsigned char udata2[IMG_SIZE];


void mat_truecloud(double *x, double *y,
                          double h, double A, double B, double C,
                          double omiga_par, double omiga_per, int n,
                          double *x_new, double *y_new)
{
  int i;
  int j;
  double aux;
  double H = 70500.0;
  double divid = h/(H*sqrt(A*A+B*B)*cos(omiga_per-omiga_par));

  printf("x=\n");
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      int aux = i * 10 + j;
      printf("%f, ", x[aux]);
    }
    printf("\n");
  }

  printf("y=\n");
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      int aux = i * 10 + j;
      printf("%f, ", y[aux]);
    }
    printf("\n");
  }

  printf("n= %d\n",n);
  for (i = 0; i < n; i++) {
    aux = (x[i]*A+y[i]*B+C)*divid;
    printf("aux=%f\n",aux);
    printf("cos=%f\n",cos(omiga_par));
    printf("sin=%f\n",sin(omiga_par));
    x_new[i] = aux*cos(omiga_par)+x[i];
    y_new[i] = aux*sin(omiga_par)+y[i];
  }

  /*  new y, i */
}

// // static double viewgeo(double x_ul, double y_ul, double x_ur, double y_ur,
// //                       double x_ll, double y_ll, double x_lr, double y_lr,
// //                       double *B, double *C, double *omiga_par,
// //                       double *omiga_per)
// // {
// //   double A;
// //   double x_l;
// //   double x_u;
// //   double y_l;
// //   double y_u;
// //   /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%(functions)%%%%%%%%%%%%%%%
// //    */
// //   /*  viewgeo function */
// //   /*  imput "x",j */
// //   /*  imput "y",i */
// //   /*  imput cloud height "h" */
// //   x_u = (x_ul + x_ur) / 2.0;
// //   x_l = (x_ll + x_lr) / 2.0;
// //   y_u = (y_ul + y_ur) / 2.0;
// //   y_l = (y_ll + y_lr) / 2.0;
// //   /*  get k of the upper left and right points */
// //   /*  get k of the lower left and right points */
// //   *omiga_par = atan(
// //       ((y_ul - y_ur) / (x_ul - x_ur) + (y_ll - y_lr) / (x_ll - x_lr)) / 2.0);
// //   /*  get the angle of parallel lines k (in pi) */
// //   /*  AX(j)+BY(i)+C=0 */
// //   A = y_u - y_l;
// //   *B = x_l - x_u;
// //   *C = y_l * x_u - x_l * y_u;
// //   *omiga_per = atan(*B / A);
// //   /*  get the angle which is perpendicular to the trace line */
// //   return A;
// // }

// // int filter(int sizes[MAX_REGION], int *num_el,
// //         double orin_x[IMG_SIZE], double orin_y[IMG_SIZE], const double num) {
    
// //     int i;
// //     int j;
// //     int k = 0;
// //     int size_old = 0;
// //     int size_new = 0;

// //     for (i = 1; i < *num_el; i++) {
// //       if (sizes[i] > num) {
// //         if (i != k) {
// //           for (j = 0; j < sizes[i]; j++) {
// //             orin_x[size_new+j] = orin_x[size_old+i];
// //             orin_y[size_new+j] = orin_y[size_old+j];
// //           }
// //           sizes[k] = sizes[i];
// //         }
// //         k++;
// //         size_new += sizes[i];
// //       }
// //       size_old += sizes[i];
// //     }

// //     *num_el = k;

// //   return size_new;
// // }

int filter(int sizes[MAX_REGION], double *num_el, unsigned char im[IMG_SIZE],
        double orin_x[IMG_SIZE], double orin_y[IMG_SIZE], const double num,
        const int width) {
    
    int i;
    int j;
    int k = 0;
    int size_old = 0;
    int size_new = 0;
    int num_sizes = (int)*num_el;
    int threshold = (int)num;

    for (i = 0; i < num_sizes; i++) {
      if (sizes[i] >= threshold) {
          for (j = 0; j < sizes[i]; j++) {
            int tmpId = (orin_y[size_old+j]-1) * width + (orin_x[size_old+j]-1);
            im[tmpId] = 1U;
            if (i != k) {
              orin_x[size_new+j] = orin_x[size_old+j];
              orin_y[size_new+j] = orin_y[size_old+j];
            }
          }
          size_new += sizes[i];
          sizes[k] = sizes[i];
          k++;
      }
      size_old += sizes[i];
    }

    *num_el = (double)k;

  return k;
}

int iroundd(double d) {
  if (d < 0)
    return (int)(d-0.5);
  else
    return (int)(d+0.5);
}

double fcssm(double Sun_zen, double Sun_azi, double ptm,
             unsigned char Water[IMG_SIZE], unsigned char Snow[IMG_SIZE],
             unsigned char plcim[IMG_SIZE], unsigned char plsim[IMG_SIZE],
             const double ijDim[2], const double resolu[4], double cldpix,
             double sdpix, double snpix, struct tData *data)
{
  /*  define constants */

  unsigned char* udata1 = data->aux_bdata1;

  double *ddata1 = data->ddata1;
  double *ddata2 = data->ddata2;
  double *ddata3 = data->ddata3;
  double *ddata4 = data->ddata4;
  double *ddata5 = data->ddata5;

  int *idata1 = data->idata1;
  int *idata2 = data->idata2;
  int *idata3 = data->idata3;


  const double Tsimilar = 0.30;
  /*  threshold for matching buffering */
  const double Tbuffer = 0.95;
  /*  max similarity threshold */
  const double max_similar = 0.95;
  /*  minimum matched cloud object (pixels) */
  const double num_cldoj = 3;
  /*  num_pix=3; % number of inward pixes (90m) for cloud base temperature */
  /*  % enviromental lapse rate 6.5 degrees/km */
  /*  % dry adiabatic lapse rate 9.8 degrees/km */
  /*  rate_elapse=6.5;% degrees/km */
  /*  rate_dlapse=9.8;% degrees/km */

  int total = 0;
  int bounds = IMG_SIZE;
  int sombra = 0;
  int nubes = 0;

  unsigned char *shadow_test_data = NULL;
  unsigned char *cloud_test_data = NULL;
  unsigned char *shadow_cal_data = NULL;
  unsigned char *cloud_cal_data = NULL;
  unsigned char *boundary_test_data = NULL;
  unsigned char *cs_final_data = NULL;


  double sun_ele_rad;
  double sun_tazi_rad;
  
  int win_height;
  int win_width;
  double sub_size;

  double revised_ptm;

  double *segm_cloud_init_data = NULL;
  double *segm_cloud_data = NULL;

  double A;
  double B;
  double C;
  double omiga_par;
  double omiga_per;

  int i;
  int j;
  int aux_i1;
  int aux_i2;
  
  cs_final_data = Water;

  shadow_test_data = plsim;
  boundary_test_data = udata1;
  cloud_test_data = plcim;

  shadow_cal_data = plsim;
  cloud_cal_data = plcim;

  segm_cloud_init_data = ddata1;



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
  sun_ele_rad = 0.017453292519943295 * (90.0 - Sun_zen);

  /*  solar azimuth anngle */
  sun_tazi_rad = 0.017453292519943295 * (Sun_azi - 90.0);
  /*  [plcim,jiDim,jiUL,resolu,ZC]=enviread([dir_im,'plcloud']); */
  /*  plsim=enviread([dir_im,'plshadow']); */
  /*  assume resolu.x=resolu.y */
  sub_size = resolu[0];
  win_height = ijDim[0];
  win_width = ijDim[1];
  /*  potential cloud & shadow layer */
  
  /*  matched cloud & shadow layer */
  
  /*  cloud_height=zeros(ijDim);% cloud relative height (m) */
  /*  boundary layer */
  
  /*  final cloud, shadow and snow mask */
  
  /*  get potential mask values */
  /*  plshadow layer */
  for (i = 0; i < IMG_SIZE; i++) {
    shadow_test_data[i] = (plsim[i] == 1U);
  }

  
  for (i = 0; i < IMG_SIZE; i++) {
    /*  boundary layer */
    boundary_test_data[i] = (plcim[i] < 255U);
    /*  plcloud layer */
    cloud_test_data[i] = (plcim[i] == 1U);
  }

  printf("Boundary\n");
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      int aux = i * 10 + j;
      printf("%u, ", boundary_test_data[aux]);
    }
    printf("\n");
  }

  printf("Cloud\n");
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      int aux = i * 10 + j;
      printf("%u, ", cloud_test_data[aux]);
    }
    printf("\n");
  }



  /*  revised percent of cloud on the scene after plcloud */
  aux_i1 = 0;
  aux_i2 = 0;
  for (i = 0; i < IMG_SIZE_ITER; i++) {
    aux_i1 += cloud_test_data[i];
    aux_i2 += boundary_test_data[i];
  }

  for (i = 0; i < IMG_SIZE; i++) {
    if (cloud_test_data[i] == 1U)
      nubes++;
    
    if (shadow_test_data[i] == 1U)
      sombra++;
  }

  revised_ptm = ((double)aux_i1)/((double)aux_i2);
  printf("La sombra es %d\n", sombra);
  printf("Las nubes son %d\n", nubes);

  /*  no t test  => more than 99.9 % clouds and partly cloud over land */
  /*  => no match => rest are definite shadows */
  /*  cloud covers more than 90% of the scene */
  /*  => no match => rest are definite shadows */
  /*  fprintf('Cloud and cloud shadow matching ...\n'); */
  if ((ptm <= 0.1) || (revised_ptm >= 0.9)) {
    printf("Skip cloud & cloud shadow matching because high cloud cover\n");

    for (i = 0; i < IMG_SIZE; i++) {
      cloud_cal_data[i] = cloud_test_data[i] ? 1U : 0U;
      shadow_cal_data[i] = cloud_test_data[i] ? 1U : 0U;
    }



    /*  similar_num=-1; */
    /*    height_num=-1; */
  } else {
    // double A;
    // double B;
    // double C;
    // double omiga_par;
    // double omiga_per;
    double i_step;
    double i_xy;
    double record_thresh = 0.0;
    double thresh_match;
    double x_ll;
    int size_xy;

    double num;
    // int size_xy;
    int cloud_type;

    int *cloud_sizes = NULL;

    // double *area = NULL;
    // double *XY_type = NULL;
    // double *tmp_XY_type = NULL;
    // double *tmp_xys = NULL;
    // double *obj_num = NULL;

    double *orin_x = NULL;
    double *orin_y = NULL;
    /*  Max cloud base height (m) */
    const double Max_cl_height = 12000;
    /*  Min cloud base height (m) */
    const double Min_cl_height = 200;

    double record_h = 0;

    orin_x = ddata2;
    orin_y = ddata3;

    cloud_sizes = idata1;


    printf("Cloud & cloud shadow matching ...\n");


    /*      fprintf('Set cloud similarity = %.3f\n',Tsimilar); */
    /*      fprintf('Set matching buffer = %.3f\n',Tbuffer); */
    /*      fprintf('Shadow match for cloud object >= %d pixels\n',num_cldoj);
     */
    /*  move 2 pixel at a time */
    i_step = 2.0 * sub_size * tan(sun_ele_rad);

    printf("i_step=%f\n",i_step);
    /*  get moving direction */
    /*  get view angle geometry */
    
    viewgeo(boundary_test_data, &A, &B, &C, &omiga_par, &omiga_per);
    
    printf("A=%f\n",A);
    printf("B=%f\n",B);
    printf("C=%f\n",C);
    printf("omiga_par=%f\n",omiga_par);
    printf("omiga_per=%f\n",omiga_per);

    /*  Segmentate each cloud */
    /*      fprintf('Cloud segmentation & matching\n'); */

    
    
    bwlabel(cloud_test_data, segm_cloud_init_data, &num);

    printf("Cloud_init\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%f, ", segm_cloud_init_data[aux]);
      }
      printf("\n");
    }

    connected_components(segm_cloud_init_data, num, win_width, cloud_sizes, orin_x, orin_y);

    printf("num=%f", num);

    printf("cloud_sizes\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%d, ", cloud_sizes[aux]);
      }
      printf("\n");
    }

    printf("orin_x\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%f, ", orin_x[aux]);
      }
      printf("\n");
    }

    printf("orin_y\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%f, ", orin_y[aux]);
      }
      printf("\n");
    }

    /*  filter out cloud object < than num_cldoj pixels */
    /*  Get the x,y of each cloud */
    /*  Matrix used in recording the x,y */
    total = 0;

    for (i = 0; i < IMG_SIZE; i++) {
      if (cloud_cal_data[i] == 1)
        total++;
    }


    filter(cloud_sizes, &num, cloud_cal_data, orin_x, orin_y, cldpix, win_width);

    printf("num=%f\n", num);

    printf("cloud_cal\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%u, ", cloud_cal_data[aux]);
      }
      printf("\n");
    }
    
    total = 0;
    for (i = 0; i < IMG_SIZE; i++) {
      if (cloud_cal_data[i] == 1)
        total++;
    }

    memset(segm_cloud_init_data, 0, IMG_SIZE*8);

    size_xy = 0;
    for (i = 0; i < num; i++) {
      int tmp_id;
      for (j = 0; j < cloud_sizes[i]; j++) {
        tmp_id = (orin_y[size_xy]-1) * win_width + (orin_x[size_xy]-1);

        segm_cloud_init_data[tmp_id] = (double)i;
        size_xy++;
      }
    }

    printf("cloud_init\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%f, ", segm_cloud_init_data[aux]);
      }
      printf("\n");
    }


    /*  Use iteration to get the optimal move distance */
    /*  Calulate the moving cloud shadow */
    /*  height_num=zeros(1,num); % cloud relative height (m) */
    /*  cloud shadow match similarity (m) */
    for (cloud_type = 1; cloud_type <= num; cloud_type++) {
      double record_h;
      double base_h;
      int num_el = cloud_sizes[cloud_type-1];
      bool exitg1;
      
      /* fprintf('Shadow Match of the %d/%d_th cloud with %d */
      /* pixels\n',cloud_type,num,obj_num(cloud_type)); */
      /*  moving cloud xys */


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
      
      /*  refine cloud height range (m) */
      /*           Min_cl_height=max(Min_cl_height,10*(t_templ-400-t_obj)/rate_dlapse);
       */
      /*           Max_cl_height=min(Max_cl_height,10*(t_temph+400-t_obj)); */
      /*  initialize height and similarity info */

      for (base_h = Min_cl_height; base_h < 500; base_h += i_step ) {
        double matched_all;
        double total_all;

        double out_all = 0.0;
        int k = 0;

        double *tmp_x = ddata4;
        double *tmp_y = ddata5;

        int *tmp_srow = idata2;
        int *tmp_scol = idata3;

        printf("base_h=%f\n",base_h);

        printf("orin_x\n");
        for (i = 0; i < 10; i++) {
          for (j = 0; j < 10; j++) {
            int aux = i * 10 + j;
            printf("%f, ", orin_x[aux]);
          }
          printf("\n");
        }



        /*  iterate in height (m) */
        /*  Get the true postion of the cloud */
        /*  calculate cloud DEM with initial base height */
        /* (10*(t_obj-temp_obj)/rate_elapse+base_h); */
        mat_truecloud(orin_x,orin_y,base_h,A,B,C,omiga_par,omiga_per,num_el,tmp_x,tmp_y);
        /*  shadow moved distance (pixel) */
        /*  i_xy=h*cos(sun_tazi_rad)/(sub_size*tan(sun_ele_rad)); */

        printf("tmp_x\n");
        for (i = 0; i < 10; i++) {
          for (j = 0; j < 10; j++) {
            int aux = i * 10 + j;
            printf("%f, ", tmp_x[aux]);
          }
          printf("\n");
        }

        printf("tmp_y\n");
        for (i = 0; i < 10; i++) {
          for (j = 0; j < 10; j++) {
            int aux = i * 10 + j;
            printf("%f, ", tmp_y[aux]);
          }
          printf("\n");
        }

        
        i_xy=base_h/(sub_size*tan(sun_ele_rad));

        printf("i_xy=%f",i_xy);
        if (Sun_azi < 180.0) {
          /*  X is for col j,2 */
          double aux_cos = i_xy*cos(sun_tazi_rad);
          for (i = 0; i < num_el; i++) {
            tmp_scol[i] = iroundd(tmp_x[i]-aux_cos);
          }
          /*  Y is for row i,1 */
          double aux_sin = i_xy*sin(sun_tazi_rad);
          for (i = 0; i < num_el; i++) {
            tmp_srow[i] = iroundd(tmp_y[i]-aux_sin);
          }
        } else {
          /*  X is for col j,2 */
          double aux_cos = i_xy*cos(sun_tazi_rad);
          for (i = 0; i < num_el; i++) {
            tmp_scol[i] = iroundd(tmp_x[i]+aux_cos);
          }
          /*  Y is for row i,1 */
          double aux_sin = i_xy*sin(sun_tazi_rad);
          for (i = 0; i < num_el; i++) {
            tmp_srow[i] = iroundd(tmp_y[i]+aux_sin);
          }
        }
        /*  col */
        /*  row */
        /*  the id that is out of the image */
        printf("tmp_scol\n");
        for (i = 0; i < 10; i++) {
          for (j = 0; j < 10; j++) {
            int aux = i * 10 + j;
            printf("%d, ", tmp_scol[aux]);
          }
          printf("\n");
        }

        printf("tmp_srow\n");
        for (i = 0; i < 10; i++) {
          for (j = 0; j < 10; j++) {
            int aux = i * 10 + j;
            printf("%d, ", tmp_srow[aux]);
          }
          printf("\n");
        }
        
        /*  the id that is matched (exclude original cloud) */
        for (i = 0; i < num_el; i++) {
          if (tmp_srow[i] < 1 || tmp_srow[i] > win_height || tmp_scol[i] < 1 || tmp_scol[i] > win_width)
            out_all++;
          else if (k != i) {
            tmp_srow[k] = tmp_srow[i];
            tmp_scol[k] = tmp_scol[i];
            k++;
          }
          else
            k++;
        }

        printf("tmp_scol\n");
        for (i = 0; i < 10; i++) {
          for (j = 0; j < 10; j++) {
            int aux = i * 10 + j;
            printf("%d, ", tmp_scol[aux]);
          }
          printf("\n");
        }

        printf("tmp_srow\n");
        for (i = 0; i < 10; i++) {
          for (j = 0; j < 10; j++) {
            int aux = i * 10 + j;
            printf("%d, ", tmp_srow[aux]);
          }
          printf("\n");
        }



        /*  the id that is the total pixel (exclude original cloud) */

        matched_all = out_all;
        total_all = out_all;

        for (i = 0; i < k; i++) {
          int tmp_id = (tmp_srow[i]-1) * win_width + (tmp_scol[i]-1);
          if (boundary_test_data[i] == 0 || (segm_cloud_data[tmp_id] != cloud_type
            && (cloud_test_data[tmp_id] > 0 || shadow_test_data[tmp_id] == 1))) {
              matched_all++;
          }
          else if (cloud_test_data[tmp_id] != cloud_type)
            total_all++;
        }

        printf("matched_all=%f\n",matched_all);
        printf("total_all=%f\n",total_all);


        thresh_match = matched_all/total_all;
        
        if ((thresh_match >= Tbuffer * record_thresh) &&
            (base_h < Max_cl_height - i_step) && (record_thresh < max_similar)) {
          if (thresh_match > record_thresh) {
            record_thresh = thresh_match;
            record_h = base_h;
          }
        } else if (record_thresh > Tsimilar) {
          
          double i_vir = record_h/(sub_size*tan(sun_ele_rad));

          /*  height_num=record_h; */
          /*  calculate cloud DEM with recorded height (Zhe 08/19/2015) */

          mat_truecloud(orin_x, orin_y,record_h,A,B,C,omiga_par,omiga_per,
                num_el, tmp_x, tmp_y);


          if (Sun_azi < 180.0) {
            /*  X is for col j,2 */
            double aux_cos = i_vir*cos(sun_tazi_rad);
            for (i = 0; i < num_el; i++) {
              tmp_scol[i] = iroundd(tmp_x[i]-aux_cos);
            }
            /*  Y is for row i,1 */
            double aux_sin = i_vir*sin(sun_tazi_rad);
            for (i = 0; i < num_el; i++) {
              tmp_srow[i] = iroundd(tmp_y[i]-aux_sin);
            }
          } else {
            /*  X is for col j,2 */
            double aux_cos = i_vir*cos(sun_tazi_rad);
            for (i = 0; i < num_el; i++) {
              tmp_scol[i] = iroundd(tmp_x[i]+aux_cos);
            }
            /*  Y is for row i,1 */
            double aux_sin = i_vir*sin(sun_tazi_rad);
            for (i = 0; i < num_el; i++) {
              tmp_srow[i] = iroundd(tmp_y[i]+aux_sin);
            }
          }


          /*  put data within range */


          for (i = 0; i < num_el; i++) {
            if (tmp_srow[i] <= 0)
              tmp_srow[i] = 1;
            else if (tmp_srow[i] > win_height)
              tmp_srow[i] = win_height;
            
            if (tmp_scol[i] <= 0)
              tmp_scol[i] = 1;
            else if (tmp_scol[i] >= win_width)
              tmp_scol[i] = win_width;
          }

          printf("tmp_scol\n");
          for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
              int aux = i * 10 + j;
              printf("%d, ", tmp_scol[aux]);
            }
            printf("\n");
          }

          printf("tmp_srow\n");
          for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
              int aux = i * 10 + j;
              printf("%d, ", tmp_srow[aux]);
            }
            printf("\n");
          }


          /*  give shadow_cal=1 */

          for (i = 0; i < num_el; i++) {
            shadow_cal_data[(tmp_srow[i]-1) * win_width + (tmp_scol[i]-1)] = 1U;
          }

          /*  record matched cloud */
          /*  cloud_cal(orin_cid)=1; */
          /*  cloud_height(orin_cid)=record_h; */
          /*  fprintf('cloud_type = %d & base_h = %d & rt_obj
           * =%d\n',cloud_type,base_h,t_obj); */
          break;
        } else {
          record_thresh = 0.0;
        }
      }

      orin_x += num_el*8;
      orin_y += num_el*8;
    }
    /*  % dilate each cloud and shadow object by 3 and 3 pixel outward in 8
     * connect directions */
    /*     cldpix=3; % number of pixels to be dilated for cloud */
    /*     sdpix=3; % number of pixels to be dilated for shadow */
    /*     fprintf('Dilate %d pixels for cloud & %d pixels for shadow
     * objects\n',cldpix,sdpix); */


    imdilate(shadow_cal_data, 2*((int)sdpix)+1);
    printf("shadow\n");
    for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
        int aux = i * 10 + j;
        printf("%d, ", shadow_cal_data[aux]);
      }
      printf("\n");
    }   
    /*  dialte shadow first */
    imdilate(cloud_cal_data, 2*((int)cldpix)+1);
    
    /*      % find shadow within plshadow */
    /*      shadow_cal(shadow_test~=1)=0; */
    /*      % dilate shadow again with the more accurate cloud shadow */
    /*      shadow_cal=imdilate(shadow_cal,SEs); */
    

    /*  dilate snow by snpix pixels in 8 connect directions (Zhe 09/12/2012) */
    imdilate(Snow, 2*((int)snpix)+1);


  }

  nubes = 0;
  sombra = 0;
  for (i = 0; i < IMG_SIZE; i++) {
    cs_final_data[i] = Water[i] == 1U ? 1U : 0U;
  }

  /*  mask from plcloud */
  /*  step 1 snow or unknow */
  /*  snow */

  for (i = 0; i < IMG_SIZE; i++) {
    if (Snow[i] == 1U)
      cs_final_data[i] = 3U;
  }

  /*  step 2 shadow above snow and everyting */
  /*  shadow */

  for (i = 0; i < IMG_SIZE; i++) {
    if (shadow_cal_data[i] == 1U) {
      cs_final_data[i] = 2U;
      sombra++;
    }
  }

  /*  step 3 cloud above all */
  /*  cloud */

  for (i = 0; i < IMG_SIZE; i++) {
    if (cloud_cal_data[i] == 1U) {
      cs_final_data[i] = 4U;
      nubes++;
    }
  }

  for (i = 0; i < IMG_SIZE; i++) {
    if (boundary_test_data[i] == 0) {
      cs_final_data[i] = 255U;
      bounds--;
    }
  }

  /*  reedit dir_im */
  /*  norln=strread(dir_im,'%s','delimiter','.');  */
  /*  n_name=char(norln(1)); */
  /*  enviwrite([n_name,'Fmask'],cs_final,'uint8',resolu,jiUL,'bsq',ZC); */
  /*  record clear pixel percent; */

  total = 0;
  for (i = 0; i < IMG_SIZE; i++) {
    if (cs_final_data[i] <= 1U)
      total++;
  }

  printf("La sombra es %d\n", sombra);
  printf("Las nubes son %d\n", nubes);
  printf("El total es %d\n", total);
  printf("La imagen real es %d\n", bounds);

  return 100.0*((double)total)/((double)bounds);
}

// /* End of code generation (fcssm.c) */
