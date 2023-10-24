/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * autoFmask.c
 *
 * Code generation for function 'autoFmask'
 *
 */

/* Include files */
#include "autoFmask.h"
#include "DetectAbsSnow.h"
#include "DetectPotentialCloud.h"
#include "DetectPotentialPixels.h"
#include "DetectSnow.h"
#include "DetectWater.h"
#include "NDSI.h"
#include "NDVI.h"
#include "Saturate.h"
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"
#include "div.h"
#include "imdilate.h"
#include "prctile.h"
#include "strel.h"
#include <math.h>
#include <stdio.h>

/* Function Declarations */
static double
binary_expand_op(const ObjMeta *in1, const emxArray_boolean_T *in2,
                 const emxArray_uint8_T *in3, const ObjTOABT *in4,
                 const emxArray_real32_T *in5, const emxArray_real32_T *in6,
                 const emxArray_boolean_T *in7, const emxArray_real32_T *in8,
                 const emxArray_real32_T *in9, double in10, double in11,
                 emxArray_boolean_T *in12);

/* Function Definitions */
static double
binary_expand_op(const ObjMeta *in1, const emxArray_boolean_T *in2,
                 const emxArray_uint8_T *in3, const ObjTOABT *in4,
                 const emxArray_real32_T *in5, const emxArray_real32_T *in6,
                 const emxArray_boolean_T *in7, const emxArray_real32_T *in8,
                 const emxArray_real32_T *in9, double in10, double in11,
                 emxArray_boolean_T *in12)
{
  emxArray_real32_T *b_in4;
  double out1;
  float *in4_data;
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int aux_3_1;
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
  emxInit_real32_T(&b_in4, 2);
  i = b_in4->size[0] * b_in4->size[1];
  if (in4->BandNIR->size[0] == 1) {
    b_in4->size[0] = in4->BandSWIR1->size[0];
  } else {
    b_in4->size[0] = in4->BandNIR->size[0];
  }
  if (in4->BandNIR->size[1] == 1) {
    b_in4->size[1] = in4->BandSWIR1->size[1];
  } else {
    b_in4->size[1] = in4->BandNIR->size[1];
  }
  emxEnsureCapacity_real32_T(b_in4, i);
  in4_data = b_in4->data;
  stride_0_0 = (in4->BandSWIR1->size[0] != 1);
  stride_0_1 = (in4->BandSWIR1->size[1] != 1);
  stride_1_0 = (in4->BandNIR->size[0] != 1);
  stride_1_1 = (in4->BandNIR->size[1] != 1);
  stride_2_0 = (in4->BandSWIR1->size[0] != 1);
  stride_2_1 = (in4->BandSWIR1->size[1] != 1);
  stride_3_0 = (in4->BandNIR->size[0] != 1);
  stride_3_1 = (in4->BandNIR->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  aux_3_1 = 0;
  if (in4->BandNIR->size[1] == 1) {
    loop_ub = in4->BandSWIR1->size[1];
  } else {
    loop_ub = in4->BandNIR->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    int b_loop_ub;
    if (in4->BandNIR->size[0] == 1) {
      b_loop_ub = in4->BandSWIR1->size[0];
    } else {
      b_loop_ub = in4->BandNIR->size[0];
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in4_data[i1 + b_in4->size[0] * i] =
          (in4->BandSWIR1
               ->data[i1 * stride_0_0 + in4->BandSWIR1->size[0] * aux_0_1] -
           in4->BandNIR
               ->data[i1 * stride_1_0 + in4->BandNIR->size[0] * aux_1_1]) /
          (in4->BandSWIR1
               ->data[i1 * stride_2_0 + in4->BandSWIR1->size[0] * aux_2_1] +
           in4->BandNIR
               ->data[i1 * stride_3_0 + in4->BandNIR->size[0] * aux_3_1]);
    }
    aux_3_1 += stride_3_1;
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  out1 =
      DetectPotentialCloud(in1->Dim, in2, in3, in4->BandCirrus, in4->BandSWIR1,
                           in4->BandBT, in4->SatuGreen, in4->SatuRed, in5, in6,
                           b_in4, in7, in8, in9, in10, in11, in12);
  emxFree_real32_T(&b_in4);
  return out1;
}

double autoFmask(const ObjMeta *data_meta, const ObjTOABT *data_toabt,
                 const emxArray_real32_T *water_occur, double cldpix,
                 double snpix, double cldprob, double tpw)
{
  c_emxArray_images_internal_code *CEs_StrelArray;
  emxArray_boolean_T *b_pcloud_all;
  emxArray_boolean_T *b_psnow;
  emxArray_boolean_T *idplcd;
  emxArray_boolean_T *mask;
  emxArray_boolean_T *pcloud_all;
  emxArray_boolean_T *psnow;
  emxArray_cell_wrap_22 *CEs_DecomposedStrelArray;
  emxArray_int32_T *r2;
  emxArray_int32_T *r4;
  emxArray_int8_T *r;
  emxArray_real32_T *b_water_occur;
  emxArray_real32_T *ndsi;
  emxArray_real32_T *ndvi;
  emxArray_real32_T *r6;
  emxArray_real32_T *r7;
  emxArray_real32_T *visimean;
  emxArray_real32_T *whiteness;
  emxArray_real32_T *x;
  emxArray_uint8_T *water;
  double y;
  const float *water_occur_data;
  float *b_water_occur_data;
  float *ndsi_data;
  float *ndvi_data;
  float *r8;
  float *visimean_data;
  int b_loop_ub_tmp;
  int c_loop_ub_tmp;
  int firstBlockLength;
  int hi;
  int k;
  int lastBlockLength;
  int loop_ub_tmp;
  int nblocks;
  int xblockoffset;
  int *r3;
  int *r5;
  signed char *r1;
  unsigned char *water_data;
  boolean_T b;
  boolean_T *b_pcloud_all_data;
  boolean_T *mask_data;
  boolean_T *pcloud_all_data;
  boolean_T *psnow_data;
  water_occur_data = water_occur->data;
  /*  AUTOFMASK Automatedly detect clouds, cloud shadows, snow, and water for */
  /*      Landsats 4-7 TM/EMT+, Landsat 8 OLI/TIRS, and Sentinel 2 MSI images.
   */
  /*  */
  /*  Description */
  /*  */
  /*      This 4.6 version has better cloud, cloud shadow, and snow detection */
  /*      results for Sentinel-2 data and better results (compared to the 3.3 */
  /*      version that is being used by USGS as the Colection 1 QA Band) for */
  /*      Landsats 4-8 data as well. */
  /*       */
  /*      If any questions, please do not hesitate to contact  */
  /*      Shi Qiu (shi.qiu@uconn.edu) and Zhe Zhu (zhe@uconn.edu) data_meta,
   * data_toabt, dem, slope, aspect, water_occur, ... */
  /*    cldpix, sdpix, snpix, expdpix, erdpix, cldprob, isShadowater */
  /*  */
  /*  Input arguments */
  /*  */
  /*      cloud     Dilated number of pixels for cloud with default value of 3.
   */
  /*      shadow    Dilated number of pixels for cloud shadow with default value
   * of 3. */
  /*      snow      Dilated number of pixels for snow with default value of 0.
   */
  /*      p         Cloud probability threshold with default values of 10.0 for
   */
  /*                Landsats 4~7, 17.5 for Landsat 8, and 20.0 for Sentinel 2.
   */
  /*      d         Radius of dilation for Potential False Positive Cloud such
   * as */
  /*                urban/built-up and (mountian) snow/ice. Default: 0 meters.
   */
  /*                Higher the value, Larger the potential false positive cloud
   */
  /*                layer. This is used for the places where the orginal
   * Potential  */
  /*                False Positive Cloud Layer fails to include the false */
  /*                posistive clouds. */
  /*      e         Radius of erosion for Potential False Positive Cloud such as
   */
  /*                urban/built-up and (mountian) snow/ice. Default: 150 meters
   */
  /*                for Landsats 4-7 and 90 meters for Landsat 8 and */
  /*                Sentinel-2. */
  /*      sw      ShadowWater (SW) means the shadow of cloud over water. */
  /*                Default: False */
  /*                We do not suggest mask out the cloud shadow over water */
  /*                since it is less meanful and very time-comsuing. */
  /*      udem      The path of User's DEM data. (.tiff). If users provide */
  /*                local DEM data, Fmask 4.1 will process the image along with
   * this DEM */
  /*                data; or, the default USGS GTOPO30 will be used. */
  /*      auxi      The path of the auxiliary data ('AuxiData'). (for standalone
   * only) */
  /*  */
  /*  Output arguments */
  /*  */
  /*      fmask      0: clear land */
  /*                 1: clear water */
  /*                 2: cloud shadow */
  /*                 3: snow */
  /*                 4: cloud */
  /*                 255: filled (outside) */
  /*  */
  /*  Examples */
  /*  */
  /*      clr_pct = autoFmask('cloud',0, 'shadow', 0) will produce the mask
   * without buffers. */
  /*      clr_pct = autoFmask('p',20) forces cloud probablity thershold as 20.
   */
  /*      clr_pct = autoFmask('e',500) forces erosion radius for Potential False
   * Positive Cloud as 500 meters to remove the large commission errors. */
  /*  */
  /*          */
  /*  Author:  Shi Qiu (shi.qiu@uconn.edu) and Zhe Zhu (zhe@uconn.edu) */
  /*  Last Date: Feb. 25, 2022 */
  /*  Copyright @ GERS Lab, UCONN. */
  /*  warning('off','all'); % do not show warning information */
  /*  tic */
  /*  fmask_soft_name='Fmask 4.6'; */
  /*  fprintf('%s start ...\n',fmask_soft_name); */
  /*  path_data=pwd; */
  /*   */
  /*  %% get parameters from inputs */
  /*  p = inputParser; */
  /*  p.FunctionName = 'FmaskParas'; */
  /*  % optional */
  /*  % default values. */
  /*  addParameter(p,'cloud',3); */
  /*  addParameter(p,'shadow',3); */
  /*  addParameter(p,'snow',0); */
  /*   */
  /*  %% read info from .xml. */
  /*  [sensor,~,InputFile,main_meta] =
   * LoadSensorType(strcat(path_data,'/LANDSAT')); */
  /*  if isempty(sensor) */
  /*      error('%s works only for Landsats 4-7, Landsat 8, and Sentinel 2
   * images.\n',fmask_soft_name); */
  /*  end */
  /*   */
  /*  default_paras = FmaskParameters(sensor); */
  /*  tpw = default_paras.ThinWeight; */
  /*  addParameter(p,'d',default_paras.PFPCLayerExtensinRadius); */
  /*  addParameter(p,'e',default_paras.PFPCErosionRadius); */
  /*  addParameter(p,'p',default_paras.CloudProbabilityThershold); */
  /*  addParameter(p,'resolution',default_paras.OutputResolution); */
  /*   */
  /*  addParameter(p,'sw',default_paras.ShadowWater); */
  /*   */
  /*  % user's path for DEM */
  /*  addParameter(p,'udem',''); */
  /*   */
  /*  % user's path for the auxiliaray data */
  /*  addParameter(p,'auxi',''); */
  /*   */
  /*  % request user's input */
  /*  parse(p,varargin{:}); */
  /*  resolution=p.Results.resolution; */
  /*  cldpix=p.Results.cloud; */
  /*  sdpix=p.Results.shadow; */
  /*  snpix=p.Results.snow; */
  /*  expdpix = round(p.Results.d/resolution); */
  /*  erdpix=round(p.Results.e/resolution); */
  /*  cldprob=p.Results.p; */
  /*  isShadowater = p.Results.sw; */
  /*   */
  /*  % users can use the local dem. */
  /*  userdem = p.Results.udem; */
  /*  % input the folder of auxiliaray data */
  /*  pathauxi = p.Results.auxi; */
  /*  clear p; */
  /*   */
  /*  fprintf('Cloud/cloud shadow/snow dilated by %d/%d/%d
   * pixels.\n',cldpix,sdpix,snpix); */
  printf("Cloud probability threshold of %.2f%%.\n", cldprob);
  fflush(stdout);
  /*   */
  printf("Load or calculate TOA reflectances.\n");
  fflush(stdout);
  /*   */
  /*  fprintf(strcat(InputFile,'\n')); */
  /*   */
  /*  %% load data */
  /*  [data_meta,data_toabt,angles_view,trgt] =
   * LoadData(strcat(path_data,'/LANDSAT'),sensor,InputFile,main_meta); */
  /*  clear InputFile norMTL; */
  /*   */
  /*  if isempty(userdem) */
  /*      % default DEM */
  /*      [dem,slope,aspect,water_occur] =
   * LoadAuxiData(fullfile(strcat(path_data,'/LANDSAT'),data_meta.Output),data_meta.Name,data_meta.BBox,trgt,false,
   * 'auxi', pathauxi); % true false */
  /*  else */
  /*      [dem,slope,aspect,water_occur] =
   * LoadAuxiData(fullfile(strcat(path_data,'/LANDSAT'),data_meta.Output),data_meta.Name,data_meta.BBox,trgt,false,
   * 'userdem',userdem, 'auxi', pathauxi); % true false */
  /*  end */
  /*   */
  printf("Detect potential clouds, cloud shadows, snow, and water.\n");
  fflush(stdout);
  /*     %% public data */
  /* MASK Create the mask of obervation using the overlap of all bands. */
  /*  */
  /*  Syntax */
  /*  */
  /*      obs_mask= ObservMask( band ) */
  /*  */
  /*  Description */
  /*  */
  /*      Create the mask of obervation using the overlap of all bands, which */
  /*      have been calculated in LoadData. */
  /*  History */
  /*  */
  /*      1. Create this function. (22. September, 2017)  */
  /*  */
  /*  Input arguments */
  /*  */
  /*      band     Blue band. */
  /*  */
  /*  Output arguments */
  /*  */
  /*      obs_mask      Observation mask(outside). */
  /*  */
  /*  See also: Loaddata */
  /*  */
  /*          */
  /*  Author:  Shi Qiu (shi.qiu@ttu.edu) */
  /*  Date: 22. September, 2017  */
  emxInit_boolean_T(&mask, 2);
  hi = mask->size[0] * mask->size[1];
  mask->size[0] = data_toabt->BandBlue->size[0];
  mask->size[1] = data_toabt->BandBlue->size[1];
  emxEnsureCapacity_boolean_T(mask, hi);
  mask_data = mask->data;
  loop_ub_tmp = data_toabt->BandBlue->size[0] * data_toabt->BandBlue->size[1];
  for (hi = 0; hi < loop_ub_tmp; hi++) {
    mask_data[hi] = (data_toabt->BandBlue->data[hi] > -9999.0F);
  }
  /*   */
  /*      obs_mask=band~=0; */
  /*       */
  /*      %% simulate Sentinel 2 scene by 100 km x 100 km. */
  /*      % spatial resolution is 30 m for each pixel. That means there will be
   */
  /*      % 3333 x 3333 30m pixels should be selected expanding from the centre.
   */
  /*      s2_pixels=[3333 3333]; */
  /*      s2_pixels_half=round(s2_pixels./2); */
  /*      obs_dim=size(obs_mask); */
  /*      pixel_centre=round(obs_dim./2); */
  /*       */
  /*      s2_mask=obs_mask.*0; */
  /*      r_start=pixel_centre(1)-s2_pixels_half(1); */
  /*      r_end=pixel_centre(1)+s2_pixels_half(1); */
  /*      c_start=pixel_centre(2)-s2_pixels_half(2); */
  /*      c_end=pixel_centre(2)+s2_pixels_half(2); */
  /*      s2_mask(r_start:r_end,c_start:c_end)=1; */
  /*      obs_mask=s2_mask&obs_mask; */
  /* a pixel's DEM can be set as the lowest value derived from the all workable
   * pixels. */
  /* if ~isempty(dem) */
  /*     dem_nan=isnan(dem); */
  /*     dem(dem_nan)=double(prctile(dem(~dem_nan&mask),0.001)); % exclude DEM
   * errors. */
  /*     clear dem_nan; */
  /* end */
  /*  NDVI NDSI NDBI */
  /* NDVI Calculate Normalized Difference Vegetation Index (NDVI) using NIR and
   */
  /*      Red bands. */
  /*  */
  /*  Syntax */
  /*  */
  /*      ndvi = NDVI(red,nir) */
  /*  */
  /*  Description */
  /*  */
  /*      This function calculates Normalized Difference Vegetation Index (NDVI)
   */
  /*      using NIR and Red bands (as following equation). This range is between
   */
  /*      -1 and 1. */
  /*      NDVI=(NIR-Red)/(NIR+Red). */
  /*  */
  /*  Input arguments */
  /*  */
  /*      red         Red band */
  /*      nir         Near-infrared band */
  /*  */
  /*  Output arguments */
  /*  */
  /*      ndvi        Normalized Difference Vegetation Index */
  /*  */
  /*  Author: Shi Qiu (shi.qiu@ttu.edu) */
  /*  Date: 19. October, 2017 */
  /*  calculate NDVI */
  b = ((data_toabt->BandNIR->size[0] == data_toabt->BandRed->size[0]) &&
       (data_toabt->BandNIR->size[1] == data_toabt->BandRed->size[1]));
  emxInit_real32_T(&visimean, 2);
  if (b) {
    hi = visimean->size[0] * visimean->size[1];
    visimean->size[0] = data_toabt->BandNIR->size[0];
    visimean->size[1] = data_toabt->BandNIR->size[1];
    emxEnsureCapacity_real32_T(visimean, hi);
    visimean_data = visimean->data;
    firstBlockLength =
        data_toabt->BandNIR->size[0] * data_toabt->BandNIR->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      visimean_data[hi] =
          data_toabt->BandNIR->data[hi] + data_toabt->BandRed->data[hi];
    }
  } else {
    binary_expand_op_20(visimean, data_toabt);
    visimean_data = visimean->data;
  }
  emxInit_real32_T(&ndvi, 2);
  if (data_toabt->BandNIR->size[0] == 1) {
    xblockoffset = data_toabt->BandRed->size[0];
  } else {
    xblockoffset = data_toabt->BandNIR->size[0];
  }
  if (data_toabt->BandNIR->size[1] == 1) {
    b_loop_ub_tmp = data_toabt->BandRed->size[1];
  } else {
    b_loop_ub_tmp = data_toabt->BandNIR->size[1];
  }
  if (b && (xblockoffset == visimean->size[0]) &&
      (b_loop_ub_tmp == visimean->size[1])) {
    hi = ndvi->size[0] * ndvi->size[1];
    ndvi->size[0] = data_toabt->BandNIR->size[0];
    ndvi->size[1] = data_toabt->BandNIR->size[1];
    emxEnsureCapacity_real32_T(ndvi, hi);
    ndvi_data = ndvi->data;
    firstBlockLength =
        data_toabt->BandNIR->size[0] * data_toabt->BandNIR->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      ndvi_data[hi] =
          (data_toabt->BandNIR->data[hi] - data_toabt->BandRed->data[hi]) /
          visimean_data[hi];
    }
  } else {
    binary_expand_op_19(ndvi, data_toabt, visimean);
    ndvi_data = ndvi->data;
  }
  /*  fix unnormal pixels */
  xblockoffset = visimean->size[0] * visimean->size[1] - 1;
  for (hi = 0; hi <= xblockoffset; hi++) {
    if (visimean_data[hi] == 0.0F) {
      ndvi_data[hi] = 0.01F;
    }
  }
  /* NDSI calculate Normalized Difference Snow Index (NDSI) using Green and */
  /*      SWIR bands. */
  /*  Syntax */
  /*  */
  /*      ndsi = NDSI(green,swir) */
  /*  */
  /*  Description */
  /*  */
  /*      This function calculates Normalized Difference Snow Index (NDSI)  */
  /*      using Green and SWIR bands (as following equation). This can be used
   */
  /*      to detect snow, as the atmosphere is transparent at both these  */
  /*      wavelengths, while snow is very reflective at 0.66 mm and not  */
  /*      reflective at 1.6mm. At visible wavelengths (e.g. 0.66 microns), snow
   */
  /*      cover is just as bright as clouds, and is therefore difficult to  */
  /*      distinguish from cloud cover. However, at 1.6 microns, snow cover  */
  /*      absorbs sunlight, and therefore appears much darker than clouds. */
  /*  */
  /*      NDSI=(Green-SWIR)/(Green+SWIR). */
  /*  */
  /*  Input arguments */
  /*  */
  /*      green       Green band */
  /*      swir        Short-wave infrared band */
  /*  */
  /*  Output arguments */
  /*  */
  /*      ndsi        Normalized Difference Snow Index */
  /*  */
  /*  Author: Shi Qiu (shi.qiu@ttu.edu) */
  /*  Date: 19. October, 2017 */
  /*  calculate NDSI */
  b = ((data_toabt->BandGreen->size[0] == data_toabt->BandSWIR1->size[0]) &&
       (data_toabt->BandGreen->size[1] == data_toabt->BandSWIR1->size[1]));
  if (b) {
    hi = visimean->size[0] * visimean->size[1];
    visimean->size[0] = data_toabt->BandGreen->size[0];
    visimean->size[1] = data_toabt->BandGreen->size[1];
    emxEnsureCapacity_real32_T(visimean, hi);
    visimean_data = visimean->data;
    firstBlockLength =
        data_toabt->BandGreen->size[0] * data_toabt->BandGreen->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      visimean_data[hi] =
          data_toabt->BandGreen->data[hi] + data_toabt->BandSWIR1->data[hi];
    }
  } else {
    binary_expand_op_18(visimean, data_toabt);
    visimean_data = visimean->data;
  }
  emxInit_real32_T(&ndsi, 2);
  if (data_toabt->BandGreen->size[0] == 1) {
    xblockoffset = data_toabt->BandSWIR1->size[0];
  } else {
    xblockoffset = data_toabt->BandGreen->size[0];
  }
  if (data_toabt->BandGreen->size[1] == 1) {
    b_loop_ub_tmp = data_toabt->BandSWIR1->size[1];
  } else {
    b_loop_ub_tmp = data_toabt->BandGreen->size[1];
  }
  if (b && (xblockoffset == visimean->size[0]) &&
      (b_loop_ub_tmp == visimean->size[1])) {
    hi = ndsi->size[0] * ndsi->size[1];
    ndsi->size[0] = data_toabt->BandGreen->size[0];
    ndsi->size[1] = data_toabt->BandGreen->size[1];
    emxEnsureCapacity_real32_T(ndsi, hi);
    ndsi_data = ndsi->data;
    firstBlockLength =
        data_toabt->BandGreen->size[0] * data_toabt->BandGreen->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      ndsi_data[hi] =
          (data_toabt->BandGreen->data[hi] - data_toabt->BandSWIR1->data[hi]) /
          visimean_data[hi];
    }
  } else {
    binary_expand_op_17(ndsi, data_toabt, visimean);
    ndsi_data = ndsi->data;
  }
  /*  fix unnormal pixels */
  xblockoffset = visimean->size[0] * visimean->size[1] - 1;
  for (hi = 0; hi <= xblockoffset; hi++) {
    if (visimean_data[hi] == 0.0F) {
      ndsi_data[hi] = 0.01F;
    }
  }
  /* cdi = CDI(data_toabt.BandVRE3,data_toabt.BandNIR8,data_toabt.BandNIR);%
   * band 7, 8, AND 8a */
  /*  Statured Visible Bands */
  /* SATURE Summary of this function goes here */
  /*    Detailed explanation goes here */
  emxInit_int8_T(&r, 2);
  if ((data_toabt->SatuBlue->size[0] == data_toabt->SatuGreen->size[0]) &&
      (data_toabt->SatuBlue->size[1] == data_toabt->SatuGreen->size[1])) {
    hi = r->size[0] * r->size[1];
    r->size[0] = data_toabt->SatuBlue->size[0];
    r->size[1] = data_toabt->SatuBlue->size[1];
    emxEnsureCapacity_int8_T(r, hi);
    r1 = r->data;
    firstBlockLength =
        data_toabt->SatuBlue->size[0] * data_toabt->SatuBlue->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      r1[hi] = (signed char)(data_toabt->SatuBlue->data[hi] +
                             data_toabt->SatuGreen->data[hi]);
    }
  } else {
    binary_expand_op_16(r, data_toabt);
    r1 = r->data;
  }
  /*  saturated pixes at any visible bands. */
  /*     %% select potential cloud pixels (PCPs) */
  /*  inputs: BandSWIR2 BandBT BandBlue BandGreen BandRed BandNIR BandSWIR1 */
  /*  BandCirrus */
  /*      [idplcd,BandCirrusNormal,whiteness,HOT] =
   * DetectPotentialPixels(mask,data_toabt,dem,ndvi,ndsi,satu_Bv); */
  /*     %% detect snow */
  /* DETECSNOW Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*  %     snow=zeros(dim,'uint8'); % Snow mask */
  /*  It takes every snow pixels including snow pixel under thin clouds or icy
   * clouds */
  emxInit_boolean_T(&psnow, 2);
  if (ndsi->size[0] == 1) {
    xblockoffset = data_toabt->BandNIR->size[0];
  } else {
    xblockoffset = ndsi->size[0];
  }
  if (ndsi->size[1] == 1) {
    b_loop_ub_tmp = data_toabt->BandNIR->size[1];
  } else {
    b_loop_ub_tmp = ndsi->size[1];
  }
  if ((ndsi->size[0] == data_toabt->BandNIR->size[0]) &&
      (ndsi->size[1] == data_toabt->BandNIR->size[1]) &&
      (xblockoffset == data_toabt->BandGreen->size[0]) &&
      (b_loop_ub_tmp == data_toabt->BandGreen->size[1])) {
    hi = psnow->size[0] * psnow->size[1];
    psnow->size[0] = ndsi->size[0];
    psnow->size[1] = ndsi->size[1];
    emxEnsureCapacity_boolean_T(psnow, hi);
    psnow_data = psnow->data;
    firstBlockLength = ndsi->size[0] * ndsi->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      psnow_data[hi] = ((ndsi_data[hi] > 0.15) &&
                        (data_toabt->BandNIR->data[hi] > 1100.0F) &&
                        (data_toabt->BandGreen->data[hi] > 1000.0F));
    }
  } else {
    binary_expand_op_15(psnow, ndsi, data_toabt);
    psnow_data = psnow->data;
  }
  b = ((data_toabt->BandBT->size[0] != 0) &&
       (data_toabt->BandBT->size[1] != 0));
  if (b) {
    if ((psnow->size[0] == data_toabt->BandBT->size[0]) &&
        (psnow->size[1] == data_toabt->BandBT->size[1])) {
      firstBlockLength = psnow->size[0] * psnow->size[1];
      for (hi = 0; hi < firstBlockLength; hi++) {
        psnow_data[hi] =
            (psnow_data[hi] && (data_toabt->BandBT->data[hi] < 1000.0F));
      }
    } else {
      binary_expand_op_14(psnow, data_toabt);
      psnow_data = psnow->data;
    }
  }
  /*      snow(ids_snow)=1; */
  /*     %% detect water */
  /* DETECTWATER Detect water by combining spectral-derived water and */
  /* GSWO-derived water togeter. */
  /*  */
  /*  Syntax */
  /*  */
  /*      water = DetectWater( dim, mask, nir, NDVI, psnow, slope, gswater) */
  /*  */
  /*  Description */
  /*  */
  /*      History: */
  /*      1. Create this function. (1. January, 2018) */
  /*      2. The sepctral-derived water may be incorrect, resulting in a 100% */
  /*      absolutely wrong low level GSWO (equal to 0). The GWSO will be used */
  /*      only when the low level GSWO is larger than 0. (9. March, 2018) */
  /*      3. Remove the coastline because of its frequent changes.  (6. May,
   * 2018) */
  /*      4. Add a water layer which does not snoe/ice because some clouds may
   */
  /*      be like snoe/ice. This will be used to exclude processing of cloud */
  /*      shadow over water. (17. March, 2020) */
  /*  */
  /*  Input arguments */
  /*  */
  /*      dim            Dim for data. */
  /*      mask           Mask for observations. */
  /*      nir            NIR. */
  /*      NDVI           NDVI. */
  /*      psnow          Potential snow. */
  /*      slope          Slope. */
  /*      gswater        GSWO. */
  /*  */
  /*  Output arguments */
  /*  */
  /*      water          Water map. */
  /*  */
  /*          */
  /*  Author:  Shi Qiu (shi.qiu@uconn.edu) */
  /*  Date: 17. March, 2020 */
  emxInit_uint8_T(&water);
  hi = water->size[0] * water->size[1];
  water->size[0] = (int)data_meta->Dim[0];
  water->size[1] = (int)data_meta->Dim[1];
  emxEnsureCapacity_uint8_T(water, hi);
  water_data = water->data;
  b_loop_ub_tmp = (int)data_meta->Dim[0] * (int)data_meta->Dim[1];
  for (hi = 0; hi < b_loop_ub_tmp; hi++) {
    water_data[hi] = 0U;
  }
  /*  Water msk */
  /*     %% Zhe's water test (works over thin cloud) */
  emxInit_boolean_T(&pcloud_all, 2);
  if ((ndvi->size[0] == data_toabt->BandNIR->size[0]) &&
      (ndvi->size[1] == data_toabt->BandNIR->size[1]) &&
      (ndvi->size[0] == data_toabt->BandNIR->size[0]) &&
      (ndvi->size[1] == data_toabt->BandNIR->size[1])) {
    hi = pcloud_all->size[0] * pcloud_all->size[1];
    pcloud_all->size[0] = ndvi->size[0];
    pcloud_all->size[1] = ndvi->size[1];
    emxEnsureCapacity_boolean_T(pcloud_all, hi);
    pcloud_all_data = pcloud_all->data;
    firstBlockLength = ndvi->size[0] * ndvi->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      pcloud_all_data[hi] = (((ndvi_data[hi] < 0.01) &&
                              (data_toabt->BandNIR->data[hi] < 1100.0F)) ||
                             ((ndvi_data[hi] < 0.1) && (ndvi_data[hi] > 0.0F) &&
                              (data_toabt->BandNIR->data[hi] < 500.0F)));
    }
  } else {
    binary_expand_op_13(pcloud_all, ndvi, data_toabt);
    pcloud_all_data = pcloud_all->data;
  }
  xblockoffset = pcloud_all->size[0] * pcloud_all->size[1] - 1;
  for (hi = 0; hi <= xblockoffset; hi++) {
    if (pcloud_all_data[hi]) {
      water_data[hi] = 1U;
    }
  }
  /*  within observation. */
  xblockoffset = loop_ub_tmp - 1;
  firstBlockLength = 0;
  for (hi = 0; hi <= xblockoffset; hi++) {
    if (!mask_data[hi]) {
      firstBlockLength++;
    }
  }
  emxInit_int32_T(&r2, 1);
  hi = r2->size[0];
  r2->size[0] = firstBlockLength;
  emxEnsureCapacity_int32_T(r2, hi);
  r3 = r2->data;
  firstBlockLength = 0;
  for (hi = 0; hi <= xblockoffset; hi++) {
    if (!mask_data[hi]) {
      r3[firstBlockLength] = hi;
      firstBlockLength++;
    }
  }
  c_loop_ub_tmp = r2->size[0] - 1;
  for (hi = 0; hi <= c_loop_ub_tmp; hi++) {
    water_data[r3[hi]] = 0U;
  }
  /*  do not exclude snow over water because clouds may be like snow and */
  /*  will be excluded ... */
  /*     %% the GSWO data to enhance water map. */
  if (b_loop_ub_tmp == 0) {
    y = 0.0;
  } else {
    if (b_loop_ub_tmp <= 1024) {
      firstBlockLength = b_loop_ub_tmp;
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = (int)((unsigned int)b_loop_ub_tmp >> 10);
      lastBlockLength = b_loop_ub_tmp - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    y = water_data[0];
    for (k = 2; k <= firstBlockLength; k++) {
      y += (double)water_data[k - 1];
    }
    for (firstBlockLength = 2; firstBlockLength <= nblocks;
         firstBlockLength++) {
      double bsum;
      xblockoffset = (firstBlockLength - 1) << 10;
      bsum = water_data[xblockoffset];
      if (firstBlockLength == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        bsum += (double)water_data[(xblockoffset + k) - 1];
      }
      y += bsum;
    }
  }
  emxInit_boolean_T(&b_pcloud_all, 2);
  emxInit_int32_T(&r4, 1);
  emxInit_real32_T(&b_water_occur, 1);
  if ((y > 0.0) &&
      ((water_occur->size[0] != 0) && (water_occur->size[1] != 0))) {
    float gswater_occur;
    int ndvi_idx_0;
    ndvi_idx_0 = water_occur->size[0] * water_occur->size[1];
    if (ndvi_idx_0 == 0) {
      gswater_occur = 0.0F;
    } else {
      if (ndvi_idx_0 <= 1024) {
        firstBlockLength = ndvi_idx_0;
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        firstBlockLength = 1024;
        nblocks = ndvi_idx_0 / 1024;
        lastBlockLength = ndvi_idx_0 - (nblocks << 10);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }
      gswater_occur = water_occur_data[0];
      for (k = 2; k <= firstBlockLength; k++) {
        gswater_occur += water_occur_data[k - 1];
      }
      for (firstBlockLength = 2; firstBlockLength <= nblocks;
           firstBlockLength++) {
        float b_bsum;
        xblockoffset = (firstBlockLength - 1) << 10;
        b_bsum = water_occur_data[xblockoffset];
        if (firstBlockLength == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }
        for (k = 2; k <= hi; k++) {
          b_bsum += water_occur_data[(xblockoffset + k) - 1];
        }
        gswater_occur += b_bsum;
      }
    }
    if (gswater_occur > 0.0F) {
      /*  have water occurences. */
      /*  assume the water occurances are same in each whole scene. */
      /*  global surface water occurance (GSWO) */
      /*  low level to exclude the commssion errors as water. */
      /*  5% tolerances. */
      xblockoffset = b_loop_ub_tmp - 1;
      firstBlockLength = 0;
      for (hi = 0; hi <= xblockoffset; hi++) {
        if (water_data[hi] == 1) {
          firstBlockLength++;
        }
      }
      hi = r4->size[0];
      r4->size[0] = firstBlockLength;
      emxEnsureCapacity_int32_T(r4, hi);
      r5 = r4->data;
      firstBlockLength = 0;
      for (hi = 0; hi <= xblockoffset; hi++) {
        if (water_data[hi] == 1) {
          r5[firstBlockLength] = hi;
          firstBlockLength++;
        }
      }
      hi = b_water_occur->size[0];
      b_water_occur->size[0] = r4->size[0];
      emxEnsureCapacity_real32_T(b_water_occur, hi);
      b_water_occur_data = b_water_occur->data;
      firstBlockLength = r4->size[0];
      for (hi = 0; hi < firstBlockLength; hi++) {
        b_water_occur_data[hi] = water_occur_data[r5[hi]];
      }
      gswater_occur = prctile(b_water_occur) - 5.0F;
      if (gswater_occur > 0.0F) {
        /*  must be more than 0. */
        hi = b_pcloud_all->size[0] * b_pcloud_all->size[1];
        b_pcloud_all->size[0] = water_occur->size[0];
        b_pcloud_all->size[1] = water_occur->size[1];
        emxEnsureCapacity_boolean_T(b_pcloud_all, hi);
        b_pcloud_all_data = b_pcloud_all->data;
        for (hi = 0; hi < ndvi_idx_0; hi++) {
          b_pcloud_all_data[hi] = (water_occur_data[hi] > gswater_occur);
        }
        /*  extend water regions based on GSWO, but do not exclude snow/ice */
        /*  sometimes ice may be over water. Snow covered sea ice is determined
         */
        /*  using the potential snow/ice. */
        xblockoffset = psnow->size[0] * psnow->size[1] - 1;
        for (hi = 0; hi <= xblockoffset; hi++) {
          if (psnow_data[hi]) {
            b_pcloud_all_data[hi] = false;
          }
        }
        /*  remove out ice water. */
        xblockoffset = ndvi_idx_0 - 1;
        for (hi = 0; hi <= xblockoffset; hi++) {
          if (b_pcloud_all_data[hi]) {
            water_data[hi] = 1U;
          }
        }
        /*  extend water regions based on GSWO.  */
        /*  equal to the theshold because it may be 100%. */
        /*              water(psnow)=0; % remove out ice water. I think this
         * snow */
        /*              cannot be removed because there are sometimes ice clouds
         * over */
        /*              water. */
        for (hi = 0; hi <= c_loop_ub_tmp; hi++) {
          water_data[r3[hi]] = 0U;
        }
      }
    }
    /*  note that 255 indicates no data in GSWO, that is ocean pixels or */
    /*  permenate snow/ice pixels (which can be identified as land pixels). */
  }
  emxFree_real32_T(&b_water_occur);
  emxFree_int32_T(&r4);
  emxFree_int32_T(&r2);
  /*  DETECTPOTENTIALCLOUD detect potential cloud pixels (PCPs) */
  /*  Cirrus Probability  This is unavailable here because some high */
  /*  mountianus have high cirrus values. */
  /*  inputs: BandSWIR2 BandBT BandBlue BandGreen BandRed BandNIR BandSWIR1 */
  /*  BandCirrus */
  /*     %% Step 1: detect possible cloud pixels (PCPs) */
  /*  [Basic cloud test] */
  emxInit_boolean_T(&idplcd, 2);
  if (ndsi->size[0] == 1) {
    xblockoffset = ndvi->size[0];
  } else {
    xblockoffset = ndsi->size[0];
  }
  if (ndsi->size[1] == 1) {
    b_loop_ub_tmp = ndvi->size[1];
  } else {
    b_loop_ub_tmp = ndsi->size[1];
  }
  if ((ndsi->size[0] == ndvi->size[0]) && (ndsi->size[1] == ndvi->size[1]) &&
      (xblockoffset == data_toabt->BandSWIR2->size[0]) &&
      (b_loop_ub_tmp == data_toabt->BandSWIR2->size[1])) {
    hi = idplcd->size[0] * idplcd->size[1];
    idplcd->size[0] = ndsi->size[0];
    idplcd->size[1] = ndsi->size[1];
    emxEnsureCapacity_boolean_T(idplcd, hi);
    psnow_data = idplcd->data;
    firstBlockLength = ndsi->size[0] * ndsi->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      psnow_data[hi] = ((ndsi_data[hi] < 0.8) && (ndvi_data[hi] < 0.8) &&
                        (data_toabt->BandSWIR2->data[hi] > 300.0F));
    }
  } else {
    binary_expand_op_12(idplcd, ndsi, ndvi, data_toabt);
    psnow_data = idplcd->data;
  }
  /*  memory. */
  /*  when have BT data. */
  if (b) {
    if ((idplcd->size[0] == data_toabt->BandBT->size[0]) &&
        (idplcd->size[1] == data_toabt->BandBT->size[1])) {
      firstBlockLength = idplcd->size[0] * idplcd->size[1];
      for (hi = 0; hi < firstBlockLength; hi++) {
        psnow_data[hi] =
            (psnow_data[hi] && (data_toabt->BandBT->data[hi] < 2700.0F));
      }
    } else {
      binary_expand_op_11(idplcd, data_toabt);
      psnow_data = idplcd->data;
    }
  }
  /*  [Whiteness test] */
  /*  visible bands flatness (sum(abs)/mean < 0.6 => brigt and dark cloud ) */
  if (data_toabt->BandBlue->size[0] == 1) {
    xblockoffset = data_toabt->BandGreen->size[0];
  } else {
    xblockoffset = data_toabt->BandBlue->size[0];
  }
  if (data_toabt->BandBlue->size[1] == 1) {
    b_loop_ub_tmp = data_toabt->BandGreen->size[1];
  } else {
    b_loop_ub_tmp = data_toabt->BandBlue->size[1];
  }
  if ((data_toabt->BandBlue->size[0] == data_toabt->BandGreen->size[0]) &&
      (data_toabt->BandBlue->size[1] == data_toabt->BandGreen->size[1]) &&
      (xblockoffset == data_toabt->BandRed->size[0]) &&
      (b_loop_ub_tmp == data_toabt->BandRed->size[1])) {
    hi = visimean->size[0] * visimean->size[1];
    visimean->size[0] = data_toabt->BandBlue->size[0];
    visimean->size[1] = data_toabt->BandBlue->size[1];
    emxEnsureCapacity_real32_T(visimean, hi);
    visimean_data = visimean->data;
    for (hi = 0; hi < loop_ub_tmp; hi++) {
      visimean_data[hi] =
          ((data_toabt->BandBlue->data[hi] + data_toabt->BandGreen->data[hi]) +
           data_toabt->BandRed->data[hi]) /
          3.0F;
    }
  } else {
    binary_expand_op_10(visimean, data_toabt);
    visimean_data = visimean->data;
  }
  emxInit_real32_T(&x, 2);
  if ((data_toabt->BandBlue->size[0] == visimean->size[0]) &&
      (data_toabt->BandBlue->size[1] == visimean->size[1])) {
    hi = x->size[0] * x->size[1];
    x->size[0] = data_toabt->BandBlue->size[0];
    x->size[1] = data_toabt->BandBlue->size[1];
    emxEnsureCapacity_real32_T(x, hi);
    b_water_occur_data = x->data;
    for (hi = 0; hi < loop_ub_tmp; hi++) {
      b_water_occur_data[hi] =
          data_toabt->BandBlue->data[hi] - visimean_data[hi];
    }
  } else {
    binary_expand_op_9(x, data_toabt, visimean);
    b_water_occur_data = x->data;
  }
  firstBlockLength = x->size[0] * x->size[1];
  emxInit_real32_T(&whiteness, 2);
  hi = whiteness->size[0] * whiteness->size[1];
  whiteness->size[0] = x->size[0];
  whiteness->size[1] = x->size[1];
  emxEnsureCapacity_real32_T(whiteness, hi);
  ndvi_data = whiteness->data;
  for (k = 0; k < firstBlockLength; k++) {
    ndvi_data[k] = fabsf(b_water_occur_data[k]);
  }
  if ((data_toabt->BandGreen->size[0] == visimean->size[0]) &&
      (data_toabt->BandGreen->size[1] == visimean->size[1])) {
    hi = x->size[0] * x->size[1];
    x->size[0] = data_toabt->BandGreen->size[0];
    x->size[1] = data_toabt->BandGreen->size[1];
    emxEnsureCapacity_real32_T(x, hi);
    b_water_occur_data = x->data;
    firstBlockLength =
        data_toabt->BandGreen->size[0] * data_toabt->BandGreen->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      b_water_occur_data[hi] =
          data_toabt->BandGreen->data[hi] - visimean_data[hi];
    }
  } else {
    binary_expand_op_8(x, data_toabt, visimean);
    b_water_occur_data = x->data;
  }
  firstBlockLength = x->size[0] * x->size[1];
  emxInit_real32_T(&r6, 2);
  hi = r6->size[0] * r6->size[1];
  r6->size[0] = x->size[0];
  r6->size[1] = x->size[1];
  emxEnsureCapacity_real32_T(r6, hi);
  ndsi_data = r6->data;
  for (k = 0; k < firstBlockLength; k++) {
    ndsi_data[k] = fabsf(b_water_occur_data[k]);
  }
  if ((data_toabt->BandRed->size[0] == visimean->size[0]) &&
      (data_toabt->BandRed->size[1] == visimean->size[1])) {
    hi = x->size[0] * x->size[1];
    x->size[0] = data_toabt->BandRed->size[0];
    x->size[1] = data_toabt->BandRed->size[1];
    emxEnsureCapacity_real32_T(x, hi);
    b_water_occur_data = x->data;
    firstBlockLength =
        data_toabt->BandRed->size[0] * data_toabt->BandRed->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      b_water_occur_data[hi] =
          data_toabt->BandRed->data[hi] - visimean_data[hi];
    }
  } else {
    binary_expand_op_7(x, data_toabt, visimean);
    b_water_occur_data = x->data;
  }
  firstBlockLength = x->size[0] * x->size[1];
  emxInit_real32_T(&r7, 2);
  hi = r7->size[0] * r7->size[1];
  r7->size[0] = x->size[0];
  r7->size[1] = x->size[1];
  emxEnsureCapacity_real32_T(r7, hi);
  r8 = r7->data;
  for (k = 0; k < firstBlockLength; k++) {
    r8[k] = fabsf(b_water_occur_data[k]);
  }
  if (whiteness->size[0] == 1) {
    hi = r6->size[0];
  } else {
    hi = whiteness->size[0];
  }
  if (whiteness->size[1] == 1) {
    firstBlockLength = r6->size[1];
  } else {
    firstBlockLength = whiteness->size[1];
  }
  if (hi == 1) {
    xblockoffset = r7->size[0];
  } else {
    xblockoffset = hi;
  }
  if (firstBlockLength == 1) {
    b_loop_ub_tmp = r7->size[1];
  } else {
    b_loop_ub_tmp = firstBlockLength;
  }
  if ((whiteness->size[0] == r6->size[0]) &&
      (whiteness->size[1] == r6->size[1]) && (hi == r7->size[0]) &&
      (firstBlockLength == r7->size[1]) &&
      (xblockoffset == visimean->size[0]) &&
      (b_loop_ub_tmp == visimean->size[1])) {
    firstBlockLength = whiteness->size[0] * whiteness->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      ndvi_data[hi] =
          ((ndvi_data[hi] + ndsi_data[hi]) + r8[hi]) / visimean_data[hi];
    }
  } else {
    binary_expand_op_6(whiteness, r6, r7, visimean);
    ndvi_data = whiteness->data;
  }
  emxFree_real32_T(&r7);
  emxFree_real32_T(&r6);
  /*  update idplcd */
  if ((r->size[0] == data_toabt->SatuRed->size[0]) &&
      (r->size[1] == data_toabt->SatuRed->size[1])) {
    hi = b_pcloud_all->size[0] * b_pcloud_all->size[1];
    b_pcloud_all->size[0] = r->size[0];
    b_pcloud_all->size[1] = r->size[1];
    emxEnsureCapacity_boolean_T(b_pcloud_all, hi);
    b_pcloud_all_data = b_pcloud_all->data;
    firstBlockLength = r->size[0] * r->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      b_pcloud_all_data[hi] = (r1[hi] + data_toabt->SatuRed->data[hi] >= 1);
    }
  } else {
    binary_expand_op_5(b_pcloud_all, r, data_toabt);
    b_pcloud_all_data = b_pcloud_all->data;
  }
  emxFree_int8_T(&r);
  firstBlockLength = b_pcloud_all->size[0] * b_pcloud_all->size[1];
  xblockoffset = firstBlockLength - 1;
  for (hi = 0; hi <= xblockoffset; hi++) {
    if (b_pcloud_all_data[hi]) {
      ndvi_data[hi] = 0.0F;
    }
  }
  /*  If one visible is saturated whiteness == 0 */
  if ((idplcd->size[0] == whiteness->size[0]) &&
      (idplcd->size[1] == whiteness->size[1])) {
    firstBlockLength = idplcd->size[0] * idplcd->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      psnow_data[hi] = (psnow_data[hi] && (ndvi_data[hi] < 0.7));
    }
  } else {
    binary_expand_op_4(idplcd, whiteness);
    psnow_data = idplcd->data;
  }
  /*  [Haze test] */
  if ((data_toabt->BandBlue->size[0] == data_toabt->BandRed->size[0]) &&
      (data_toabt->BandBlue->size[1] == data_toabt->BandRed->size[1])) {
    hi = visimean->size[0] * visimean->size[1];
    visimean->size[0] = data_toabt->BandBlue->size[0];
    visimean->size[1] = data_toabt->BandBlue->size[1];
    emxEnsureCapacity_real32_T(visimean, hi);
    visimean_data = visimean->data;
    for (hi = 0; hi < loop_ub_tmp; hi++) {
      visimean_data[hi] = (data_toabt->BandBlue->data[hi] -
                           0.5F * data_toabt->BandRed->data[hi]) -
                          800.0F;
    }
  } else {
    binary_expand_op_3(visimean, data_toabt);
    visimean_data = visimean->data;
  }
  /*  Haze test */
  if (visimean->size[0] == 1) {
    xblockoffset = b_pcloud_all->size[0];
  } else {
    xblockoffset = visimean->size[0];
  }
  if (visimean->size[1] == 1) {
    b_loop_ub_tmp = b_pcloud_all->size[1];
  } else {
    b_loop_ub_tmp = visimean->size[1];
  }
  if ((visimean->size[0] == b_pcloud_all->size[0]) &&
      (visimean->size[1] == b_pcloud_all->size[1]) &&
      (idplcd->size[0] == xblockoffset) && (idplcd->size[1] == b_loop_ub_tmp)) {
    firstBlockLength = idplcd->size[0] * idplcd->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      psnow_data[hi] = (psnow_data[hi] &&
                        ((visimean_data[hi] > 0.0F) || b_pcloud_all_data[hi]));
    }
  } else {
    binary_expand_op_2(idplcd, visimean, b_pcloud_all);
    psnow_data = idplcd->data;
  }
  /*  need to find thick warm cloud */
  /*  [Ratio4/5>0.75 cloud test] */
  b = ((data_toabt->BandNIR->size[0] == data_toabt->BandSWIR1->size[0]) &&
       (data_toabt->BandNIR->size[1] == data_toabt->BandSWIR1->size[1]));
  if (data_toabt->BandNIR->size[0] == 1) {
    xblockoffset = data_toabt->BandSWIR1->size[0];
  } else {
    xblockoffset = data_toabt->BandNIR->size[0];
  }
  if (data_toabt->BandNIR->size[1] == 1) {
    b_loop_ub_tmp = data_toabt->BandSWIR1->size[1];
  } else {
    b_loop_ub_tmp = data_toabt->BandNIR->size[1];
  }
  if (b && (idplcd->size[0] == xblockoffset) &&
      (idplcd->size[1] == b_loop_ub_tmp)) {
    firstBlockLength = idplcd->size[0] * idplcd->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      psnow_data[hi] = (psnow_data[hi] && (data_toabt->BandNIR->data[hi] /
                                               data_toabt->BandSWIR1->data[hi] >
                                           0.75F));
    }
  } else {
    binary_expand_op_1(idplcd, data_toabt);
    psnow_data = idplcd->data;
  }
  /*  normalize Cirrus band [Cirrus test] from Landsat 8 and Sentinel 2 images
   */
  /*  if ~isempty(data_toabt.BandCirrus) */
  /* BandCirrusNormal=NormalizaCirrusDEM( mask, idplcd, data_toabt.BandCirrus,
   * dem ); */
  /*          BandCirrusNormal= data_toabt.BandCirrus; */
  /* clear data_toabt mask dem; */
  /* idplcd=idplcd==true|BandCirrusNormal > 100; % When TOA at Cirrus band is
   * more than 0.01, it may be cloudy. */
  /* end */
  /*     %% select pure snow/ice pixels. */
  DetectAbsSnow(data_toabt->BandGreen, data_toabt->SatuGreen, ndsi, psnow,
                data_meta->Resolution[0], b_pcloud_all);
  b_pcloud_all_data = b_pcloud_all->data;
  if ((b_pcloud_all->size[0] != 0) && (b_pcloud_all->size[1] != 0)) {
    xblockoffset = b_pcloud_all->size[0] * b_pcloud_all->size[1] - 1;
    for (hi = 0; hi <= xblockoffset; hi++) {
      if (b_pcloud_all_data[hi]) {
        psnow_data[hi] = false;
      }
    }
    /*  remove pure snow/ice pixels from all PCPs. */
  }
  /*     %% detect potential cloud  */
  /* NDBI Calculate Normalized Difference Build-up Index (NDBI) using NIR and */
  /*      SWIR bands. */
  /*  Syntax */
  /*  */
  /*      ndbi = NDBI(swir,nir) */
  /*  */
  /*  Description */
  /*  */
  /*      This function calculates Normalized Difference Build-up Index (NDBI)
   */
  /*      using SWIR and NIR bands (as following equation). */
  /*  */
  /*  Input arguments */
  /*  */
  /*      swir        Short-wave infrared band */
  /*      nir         Near infrared band */
  /*  */
  /*  Output arguments */
  /*  */
  /*      ndbi        Normalized Difference Build-up Index */
  /*  */
  /*  Author: Shi Qiu (shi.qiu@ttu.edu) */
  /*  Date: 19. Dec., 2017 */
  /*  calculate NDBI */
  /*  fix unnormal pixels */
  /*  not 0.01 any more because we will identify urban pixel using ndbi more
   * than 0. */
  /*      ndbi((nir+swir)==0)=0.0; */
  /*  inputs: BandCirrus BandBT BandSWIR1 SatuGreen SatuRed */
  if (b && (data_toabt->BandSWIR1->size[0] == data_toabt->BandNIR->size[0]) &&
      (data_toabt->BandSWIR1->size[1] == data_toabt->BandNIR->size[1])) {
    hi = x->size[0] * x->size[1];
    x->size[0] = data_toabt->BandSWIR1->size[0];
    x->size[1] = data_toabt->BandSWIR1->size[1];
    emxEnsureCapacity_real32_T(x, hi);
    b_water_occur_data = x->data;
    firstBlockLength =
        data_toabt->BandSWIR1->size[0] * data_toabt->BandSWIR1->size[1];
    for (hi = 0; hi < firstBlockLength; hi++) {
      b_water_occur_data[hi] =
          (data_toabt->BandSWIR1->data[hi] - data_toabt->BandNIR->data[hi]) /
          (data_toabt->BandSWIR1->data[hi] + data_toabt->BandNIR->data[hi]);
    }
    y = DetectPotentialCloud(data_meta->Dim, mask, water,
                             data_toabt->BandCirrus, data_toabt->BandSWIR1,
                             data_toabt->BandBT, data_toabt->SatuGreen,
                             data_toabt->SatuRed, ndvi, ndsi, x, idplcd,
                             whiteness, visimean, tpw, cldprob, b_pcloud_all);
    b_pcloud_all_data = b_pcloud_all->data;
  } else {
    y = binary_expand_op(data_meta, mask, water, data_toabt, ndvi, ndsi, idplcd,
                         whiteness, visimean, tpw, cldprob, b_pcloud_all);
    b_pcloud_all_data = b_pcloud_all->data;
  }
  emxFree_real32_T(&x);
  emxFree_real32_T(&visimean);
  emxFree_real32_T(&whiteness);
  emxFree_uint8_T(&water);
  emxFree_boolean_T(&idplcd);
  emxFree_real32_T(&ndsi);
  emxFree_real32_T(&ndvi);
  /*     %% detect potential flase positive cloud layer, including urban,
   * coastline, and snow/ice. */
  /* pfpl = DetectPotentialFalsePositivePixels(mask, psnow, slope, ndbi, ndvi,
   * data_toabt.BandBT,cdi, water,data_meta.Resolution(1)); */
  /*  buffer the potential false positive cloud layer. */
  /*  if expdpix>0 */
  /*      % PFPCEs=strel('square',2*expdpix+1); */
  /*      % pfpl=imdilate(pfpl,PFPCEs); */
  /*      clear PFPCEs; */
  /*  end */
  /*     %% remove most of commission errors from urban, bright rock, and
   * coastline. */
  /* pcloud = ErodeCommissons(data_meta,pcloud_all,pfpl,water,cdi,erdpix); */
  /*     %% detect cloud shadow */
  /* cs_final = zeros(data_meta.Dim,'uint8');  % final masks, including cloud,
   * cloud shadow, snow, and water. */
  /* cs_final(water==1)=1; %water is fistly stacked because of its always lowest
   * prioty. */
  /*  note that 0.1% Landsat obersavtion is about 40,000 pixels, which will be
   * used in the next statistic analyses. */
  /*  when potential cloud cover less than 0.1%, directly screen all PCPs out.
   */
  if (y <= 40000.0) {
    printf("No clear pixel in this image (clear-sky pixels = %.0f%%)\n", y);
    fflush(stdout);
    /* pshadow=~pcloud; */
  } else {
    printf("Match cloud shadows with clouds.\n");
    fflush(stdout);
    /*  detect potential cloud shadow */
    /*  pshadow = DetectPotentialCloudShadow(data_meta,
     * data_toabt.BandNIR,data_toabt.BandSWIR1,idlnd,mask,... */
    /*  slope,aspect); */
    /*  match cloud shadow, and return clouds and cloud shadows. */
    /* [ ~,pcloud, pshadow] = MatchCloudShadow(... */
    /* mask,pcloud,pshadow,isShadowater,waterAll, dem
     * ,data_bt_c,t_templ,t_temph,data_meta,sum_clr,14,angles_view); */
    /*  make buffer for final masks. */
    /*  the called cloud indicate those clouds are have highest piroity. */
    /*  This is final cloud! */
    /*  BUFFERMASKS Dilate cloud/cloud shadow/snow with cdpix/csdpix/sdpix with
     */
    /*      default value of 3/3/3. */
    /*  */
    /*  Syntax */
    /*  */
    /*      [cloud,shadow,snow] = */
    /*      BufferMasks(pcloud,cdpix,pshadow,csdpix,psnow,sdpix) */
    /*  */
    /*  Description */
    /*  */
    /*      Dilate cloud/cloud shadow/snow with cdpix/csdpix/sdpix with */
    /*      default value of 3/3/3. */
    /*  */
    /*  Input arguments */
    /*      pcloud    Cloud mask. */
    /*      cldpix    Dilated number of pixels for cloud with default value
     * of 3. */
    /*      pshadow   Cloud shadow mask. */
    /*      sdpix     Dilated number of pixels for cloud shadow value of 3. */
    /*      psnow     Snow mask. */
    /*      snpix     Dilated number of pixels for snow value of 3. */
    /*  */
    /*  Output arguments */
    /*  */
    /*      cloud    Final dilated cloud mask. */
    /*      shadow   Final dilated cloud shadow mask. */
    /*      snow     Final dilated snow mask. */
    /*  */
    /*  Example */
    /*  */
    /*      [cloud,shadow,snow] = */
    /*      BufferMasks(pcloud,3,pshadow,3,psnow,3); */
    /*  */
    /*          */
    /*  Author:  Shi Qiu (shi.qiu@ttu.edu) */
    /*  Date: 2. November, 2017  */
    /*  buffer cloud */
    d_emxInit_images_internal_coder(&CEs_StrelArray);
    emxInit_cell_wrap_22(&CEs_DecomposedStrelArray);
    if (cldpix > 0.0) {
      strel_strel(2.0 * cldpix + 1.0, CEs_StrelArray, CEs_DecomposedStrelArray);
      hi = pcloud_all->size[0] * pcloud_all->size[1];
      pcloud_all->size[0] = b_pcloud_all->size[0];
      pcloud_all->size[1] = b_pcloud_all->size[1];
      emxEnsureCapacity_boolean_T(pcloud_all, hi);
      pcloud_all_data = pcloud_all->data;
      firstBlockLength = b_pcloud_all->size[0] * b_pcloud_all->size[1] - 1;
      for (hi = 0; hi <= firstBlockLength; hi++) {
        pcloud_all_data[hi] = b_pcloud_all_data[hi];
      }
      imdilate(pcloud_all, CEs_StrelArray, CEs_DecomposedStrelArray,
               b_pcloud_all);
      b_pcloud_all_data = b_pcloud_all->data;
    }
    /*  % buffer cloud shadow */
    /*  if csdpix>0 */
    /*      CSEs=strel('square',2*csdpix+1); */
    /*      shadow=imdilate(pshadow,CSEs); */
    /*      clear pshadow CSEs csdpix; */
    /*  else */
    /*      shadow=pshadow; */
    /*      clear pshadow */
    /*  end */
    /*  buffer snow */
    if (snpix > 0.0) {
      strel_strel(2.0 * snpix + 1.0, CEs_StrelArray, CEs_DecomposedStrelArray);
      emxInit_boolean_T(&b_psnow, 2);
      imdilate(psnow, CEs_StrelArray, CEs_DecomposedStrelArray, b_psnow);
      emxFree_boolean_T(&b_psnow);
    }
    emxFree_cell_wrap_22(&CEs_DecomposedStrelArray);
    c_emxFree_images_internal_coder(&CEs_StrelArray);
  }
  emxFree_boolean_T(&pcloud_all);
  emxFree_boolean_T(&psnow);
  /*     %% stack results together.  */
  /*  % step 1 snow or unknow */
  /*  cs_final(psnow==1)=3; % snow */
  /*  % step 2 shadow above snow and everyting */
  /*  cs_final(pshadow==1)=2; %shadow */
  /*  % step 3 cloud above all */
  /*  cs_final(pcloud==1)=4; % cloud */
  /*  % mask out no data. */
  /*  cs_final(mask==0)=255; % mask */
  /*  clear pixels percentage */
  firstBlockLength = b_pcloud_all->size[0] * b_pcloud_all->size[1];
  if (firstBlockLength == 0) {
    xblockoffset = 0;
  } else {
    xblockoffset = b_pcloud_all_data[0];
    for (k = 2; k <= firstBlockLength; k++) {
      xblockoffset += b_pcloud_all_data[k - 1];
    }
  }
  emxFree_boolean_T(&b_pcloud_all);
  firstBlockLength = mask->size[0] * mask->size[1];
  if (firstBlockLength == 0) {
    hi = 0;
  } else {
    hi = mask_data[0];
    for (k = 2; k <= firstBlockLength; k++) {
      hi += mask_data[k - 1];
    }
  }
  emxFree_boolean_T(&mask);
  return 100.0 * (1.0 - (double)xblockoffset / (double)hi);
  /*     %% output as geotiff. */
  /*  trgt.Z=cs_final; */
  /*  fmask_name=[data_meta.Name,'_Fmask4']; */
  /*  trgt.name=fmask_name; */
  /*   */
  /*  fmask_output=fullfile(path_data,data_meta.Output,[fmask_name,'.tif']); */
  /*  GRIDobj2geotiff(trgt,fmask_output); */
  /*  time=toc; */
  /*  time=time/60; */
  /*  fprintf('%s finished (%.2f minutes)\nfor %s with %.2f%% clear
   * pixels\n\n',... */
  /*      fmask_soft_name,time,data_meta.Name,clr_pct); */
}

/* End of code generation (autoFmask.c) */
