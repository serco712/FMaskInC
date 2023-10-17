/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_DetectPotentialCloud_api.c
 *
 * Code generation for function 'DetectPotentialCloud'
 *
 */

/* Include files */
#include "_coder_DetectPotentialCloud_api.h"
#include "_coder_DetectPotentialCloud_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131643U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "DetectPotentialCloud",                               /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[4]);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, ObjMeta *y);

static const mxArray *b_emlrt_marshallOut(const emxArray_uint8_T *u);

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_boolean_T *ret);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_char_T *y);

static const mxArray *c_emlrt_marshallOut(const emxArray_boolean_T *u);

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_uint8_T *ret);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[4]);

static const mxArray *d_emlrt_marshallOut(const real32_T u);

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real32_T *ret);

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2]);

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_boolean_T *ret);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier, ObjMeta *y);

static const mxArray *emlrt_marshallOut(const real_T u);

static void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
                                        int32_T oldNumel);

static void emxEnsureCapacity_char_T(emxArray_char_T *emxArray,
                                     int32_T oldNumel);

static void emxEnsureCapacity_real32_T(emxArray_real32_T *emxArray,
                                       int32_T oldNumel);

static void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray,
                                      int32_T oldNumel);

static void emxFreeStruct_ObjMeta(const emlrtStack *sp, ObjMeta *pStruct);

static void emxFreeStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct);

static void emxFreeStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct);

static void emxFree_boolean_T(const emlrtStack *sp,
                              emxArray_boolean_T **pEmxArray);

static void emxFree_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray);

static void emxFree_real32_T(const emlrtStack *sp,
                             emxArray_real32_T **pEmxArray);

static void emxFree_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray);

static void emxInitStruct_ObjMeta(const emlrtStack *sp, ObjMeta *pStruct);

static void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct);

static void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct);

static void emxInit_boolean_T(const emlrtStack *sp,
                              emxArray_boolean_T **pEmxArray);

static void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray);

static void emxInit_real32_T(const emlrtStack *sp,
                             emxArray_real32_T **pEmxArray);

static void emxInit_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray);

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real32_T *ret);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2]);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[4]);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_boolean_T *y);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_boolean_T *y);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_uint8_T *y);

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_uint8_T *y);

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T *y);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T *y);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_boolean_T *y);

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct1_T *y);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct1_T *y);

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real32_T *y);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y);

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_char_T *ret);

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[4]);

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2]);

static real_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2]);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = {1, 4};
  real_T(*r)[4];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[4])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  ret[3] = (*r)[3];
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, ObjMeta *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[10] = {"Name", "Sensor", "Resolution", "Dim",
                                         "UL",   "Zen",    "Azi",        "ZC",
                                         "BBox", "Output"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 10,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "Name";
  c_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "Name")),
      &thisId, y->Name);
  thisId.fIdentifier = "Sensor";
  c_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "Sensor")),
      &thisId, y->Sensor);
  thisId.fIdentifier = "Resolution";
  d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "Resolution")),
      &thisId, y->Resolution);
  thisId.fIdentifier = "Dim";
  e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "Dim")),
      &thisId, y->Dim);
  thisId.fIdentifier = "UL";
  e_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "UL")),
      &thisId, y->UL);
  thisId.fIdentifier = "Zen";
  y->Zen = f_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5, "Zen")),
      &thisId);
  thisId.fIdentifier = "Azi";
  y->Azi = f_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6, "Azi")),
      &thisId);
  thisId.fIdentifier = "ZC";
  g_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 7, "ZC")),
      &thisId, y->ZC);
  thisId.fIdentifier = "BBox";
  h_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 8, "BBox")),
      &thisId, y->BBox);
  thisId.fIdentifier = "Output";
  c_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 9, "Output")),
      &thisId, y->Output);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_uint8_T *u)
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  const uint8_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxUINT8_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_boolean_T *ret)
{
  static const int32_T dims[2] = {-1, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "logical", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_boolean_T(ret, i);
  ret->data = (boolean_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_char_T *y)
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *c_emlrt_marshallOut(const emxArray_boolean_T *u)
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  const boolean_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateLogicalArray(2, &iv[0]);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_uint8_T *ret)
{
  static const int32_T dims[2] = {-1, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "uint8", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_uint8_T(ret, i);
  ret->data = (uint8_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[4])
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *d_emlrt_marshallOut(const real32_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
  *(real32_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&y, m);
  return y;
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real32_T *ret)
{
  static const int32_T dims[2] = {-1, -1};
  int32_T iv[2];
  int32_T i;
  real32_T *ret_data;
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real32_T(ret, i);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtConstCTX)sp, src, &ret_data[0], 4, false);
  emlrtDestroyArray(&src);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2])
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_boolean_T *ret)
{
  static const int32_T dims[2] = {-1, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {true, true};
  boolean_T *ret_data;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "logical", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_boolean_T(ret, i);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtConstCTX)sp, src, &ret_data[0], 1, false);
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier, ObjMeta *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
                                        int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(boolean_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void emxEnsureCapacity_char_T(emxArray_char_T *emxArray,
                                     int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(char_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void emxEnsureCapacity_real32_T(emxArray_real32_T *emxArray,
                                       int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(real32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real32_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (real32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray,
                                      int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtMallocMex((uint32_T)i * sizeof(uint8_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(uint8_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (uint8_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void emxFreeStruct_ObjMeta(const emlrtStack *sp, ObjMeta *pStruct)
{
  emxFree_char_T(sp, &pStruct->Name);
  emxFree_char_T(sp, &pStruct->Sensor);
  emxFree_char_T(sp, &pStruct->Output);
}

static void emxFreeStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct)
{
  emxFree_real32_T(sp, &pStruct->BandCA);
  emxFree_real32_T(sp, &pStruct->BandBlue);
  emxFree_real32_T(sp, &pStruct->BandGreen);
  emxFree_real32_T(sp, &pStruct->BandRed);
  emxFree_real32_T(sp, &pStruct->BandVRE1);
  emxFree_real32_T(sp, &pStruct->BandVRE2);
  emxFree_real32_T(sp, &pStruct->BandVRE3);
  emxFree_real32_T(sp, &pStruct->BandNIR8);
  emxFree_real32_T(sp, &pStruct->BandNIR);
  emxFree_real32_T(sp, &pStruct->BandWV);
  emxFree_real32_T(sp, &pStruct->BandCirrus);
  emxFree_real32_T(sp, &pStruct->BandSWIR1);
  emxFree_real32_T(sp, &pStruct->BandSWIR2);
  emxFree_real32_T(sp, &pStruct->BandBT);
  emxFree_boolean_T(sp, &pStruct->SatuBlue);
  emxFree_boolean_T(sp, &pStruct->SatuGreen);
  emxFree_boolean_T(sp, &pStruct->SatuRed);
}

static void emxFreeStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct)
{
  emxFree_real32_T(sp, &pStruct->Z);
}

static void emxFree_boolean_T(const emlrtStack *sp,
                              emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

static void emxFree_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_char_T *)NULL;
  }
}

static void emxFree_real32_T(const emlrtStack *sp,
                             emxArray_real32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real32_T *)NULL) {
    if (((*pEmxArray)->data != (real32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_real32_T *)NULL;
  }
}

static void emxFree_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint8_T *)NULL) {
    if (((*pEmxArray)->data != (uint8_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_uint8_T *)NULL;
  }
}

static void emxInitStruct_ObjMeta(const emlrtStack *sp, ObjMeta *pStruct)
{
  emxInit_char_T(sp, &pStruct->Name);
  emxInit_char_T(sp, &pStruct->Sensor);
  emxInit_char_T(sp, &pStruct->Output);
}

static void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct)
{
  emxInit_real32_T(sp, &pStruct->BandCA);
  emxInit_real32_T(sp, &pStruct->BandBlue);
  emxInit_real32_T(sp, &pStruct->BandGreen);
  emxInit_real32_T(sp, &pStruct->BandRed);
  emxInit_real32_T(sp, &pStruct->BandVRE1);
  emxInit_real32_T(sp, &pStruct->BandVRE2);
  emxInit_real32_T(sp, &pStruct->BandVRE3);
  emxInit_real32_T(sp, &pStruct->BandNIR8);
  emxInit_real32_T(sp, &pStruct->BandNIR);
  emxInit_real32_T(sp, &pStruct->BandWV);
  emxInit_real32_T(sp, &pStruct->BandCirrus);
  emxInit_real32_T(sp, &pStruct->BandSWIR1);
  emxInit_real32_T(sp, &pStruct->BandSWIR2);
  emxInit_real32_T(sp, &pStruct->BandBT);
  emxInit_boolean_T(sp, &pStruct->SatuBlue);
  emxInit_boolean_T(sp, &pStruct->SatuGreen);
  emxInit_boolean_T(sp, &pStruct->SatuRed);
}

static void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct)
{
  emxInit_real32_T(sp, &pStruct->Z);
}

static void emxInit_boolean_T(const emlrtStack *sp,
                              emxArray_boolean_T **pEmxArray)
{
  emxArray_boolean_T *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_boolean_T *)emlrtMallocEmxArray(sizeof(emxArray_boolean_T));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_boolean_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray)
{
  emxArray_char_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T *)emlrtMallocEmxArray(sizeof(emxArray_char_T));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_char_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_real32_T(const emlrtStack *sp,
                             emxArray_real32_T **pEmxArray)
{
  emxArray_real32_T *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_real32_T *)emlrtMallocEmxArray(sizeof(emxArray_real32_T));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_real32_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (real32_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_uint8_T(const emlrtStack *sp, emxArray_uint8_T **pEmxArray)
{
  emxArray_uint8_T *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_uint8_T *)emlrtMallocEmxArray(sizeof(emxArray_uint8_T));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_uint8_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (uint8_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real32_T *ret)
{
  static const int32_T dims[2] = {-1, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "single", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real32_T(ret, i);
  ret->data = (real32_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2])
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[4])
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_boolean_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_boolean_T *y)
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_uint8_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  l_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_uint8_T *y)
{
  cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  n_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[17] = {
      "BandCA",     "BandBlue",  "BandGreen", "BandRed", "BandVRE1",
      "BandVRE2",   "BandVRE3",  "BandNIR8",  "BandNIR", "BandWV",
      "BandCirrus", "BandSWIR1", "BandSWIR2", "BandBT",  "SatuBlue",
      "SatuGreen",  "SatuRed"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 17,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "BandCA";
  o_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "BandCA")),
      &thisId, y->BandCA);
  thisId.fIdentifier = "BandBlue";
  o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1, "BandBlue")),
      &thisId, y->BandBlue);
  thisId.fIdentifier = "BandGreen";
  o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2, "BandGreen")),
      &thisId, y->BandGreen);
  thisId.fIdentifier = "BandRed";
  o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 3, "BandRed")),
      &thisId, y->BandRed);
  thisId.fIdentifier = "BandVRE1";
  o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 4, "BandVRE1")),
      &thisId, y->BandVRE1);
  thisId.fIdentifier = "BandVRE2";
  o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5, "BandVRE2")),
      &thisId, y->BandVRE2);
  thisId.fIdentifier = "BandVRE3";
  o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6, "BandVRE3")),
      &thisId, y->BandVRE3);
  thisId.fIdentifier = "BandNIR8";
  o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 7, "BandNIR8")),
      &thisId, y->BandNIR8);
  thisId.fIdentifier = "BandNIR";
  o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 8, "BandNIR")),
      &thisId, y->BandNIR);
  thisId.fIdentifier = "BandWV";
  o_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 9, "BandWV")),
      &thisId, y->BandWV);
  thisId.fIdentifier = "BandCirrus";
  o_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 10,
                                                    "BandCirrus")),
                     &thisId, y->BandCirrus);
  thisId.fIdentifier = "BandSWIR1";
  o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 11, "BandSWIR1")),
      &thisId, y->BandSWIR1);
  thisId.fIdentifier = "BandSWIR2";
  o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 12, "BandSWIR2")),
      &thisId, y->BandSWIR2);
  thisId.fIdentifier = "BandBT";
  o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 13, "BandBT")),
      &thisId, y->BandBT);
  thisId.fIdentifier = "SatuBlue";
  p_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 14, "SatuBlue")),
      &thisId, y->SatuBlue);
  thisId.fIdentifier = "SatuGreen";
  p_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 15, "SatuGreen")),
      &thisId, y->SatuGreen);
  thisId.fIdentifier = "SatuRed";
  p_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 16, "SatuRed")),
      &thisId, y->SatuRed);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y)
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_boolean_T *y)
{
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  r_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct1_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames = "Z";
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 1,
                         (const char_T **)&fieldNames, 0U, (const void *)&dims);
  thisId.fIdentifier = "Z";
  o_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 0, "Z")),
      &thisId, y->Z);
  emlrtDestroyArray(&u);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, emxArray_real32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  t_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real32_T *y)
{
  fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_char_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  char_T *ret_data;
  boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "char", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_char_T(ret, i);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtConstCTX)sp, src, &ret_data[0], 1, false);
  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = {2, 2};
  real_T(*r)[4];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[4])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  ret[3] = (*r)[3];
  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = {1, 2};
  real_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static real_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims = 2;
  real_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  r = (real_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

void DetectPotentialCloud_api(const mxArray *const prhs[13], int32_T nlhs,
                              const mxArray *plhs[5])
{
  ObjMeta b_data_meta;
  ObjMeta data_meta;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_boolean_T *idplcd;
  emxArray_boolean_T *idused;
  emxArray_boolean_T *mask;
  emxArray_real32_T *HOT;
  emxArray_real32_T *cldprob;
  emxArray_real32_T *ndbi;
  emxArray_real32_T *ndsi;
  emxArray_real32_T *ndvi;
  emxArray_real32_T *whiteness;
  emxArray_real32_T *wpt;
  emxArray_uint8_T *cloud;
  emxArray_uint8_T *water;
  struct0_T b_data_toabt;
  struct0_T data_toabt;
  struct1_T b_dem;
  struct1_T dem;
  real_T sum_clr;
  real32_T t_temph;
  real32_T t_templ;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  emxInitStruct_ObjMeta(&st, &data_meta);
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "data_meta", &data_meta);
  emxInit_boolean_T(&st, &mask);
  mask->canFreeData = false;
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "mask", mask);
  emxInit_uint8_T(&st, &water);
  water->canFreeData = false;
  k_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "water", water);
  emxInitStruct_struct0_T(&st, &data_toabt);
  m_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "data_toabt", &data_toabt);
  emxInitStruct_struct1_T(&st, &dem);
  q_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "dem", &dem);
  emxInit_real32_T(&st, &ndvi);
  ndvi->canFreeData = false;
  s_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "ndvi", ndvi);
  emxInit_real32_T(&st, &ndsi);
  ndsi->canFreeData = false;
  s_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "ndsi", ndsi);
  emxInit_real32_T(&st, &ndbi);
  ndbi->canFreeData = false;
  s_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "ndbi", ndbi);
  emxInit_boolean_T(&st, &idplcd);
  idplcd->canFreeData = false;
  i_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "idplcd", idplcd);
  emxInit_real32_T(&st, &whiteness);
  whiteness->canFreeData = false;
  s_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "whiteness", whiteness);
  emxInit_real32_T(&st, &HOT);
  HOT->canFreeData = false;
  s_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "HOT", HOT);
  emxInit_real32_T(&st, &wpt);
  wpt->canFreeData = false;
  s_emlrt_marshallIn(&st, emlrtAlias(prhs[11]), "wpt", wpt);
  emxInit_real32_T(&st, &cldprob);
  cldprob->canFreeData = false;
  s_emlrt_marshallIn(&st, emlrtAlias(prhs[12]), "cldprob", cldprob);
  /* Invoke the target function */
  emxInit_uint8_T(&st, &cloud);
  emxInit_boolean_T(&st, &idused);
  b_data_meta = data_meta;
  b_data_toabt = data_toabt;
  b_dem = dem;
  DetectPotentialCloud(&b_data_meta, mask, water, &b_data_toabt, &b_dem, ndvi,
                       ndsi, ndbi, idplcd, whiteness, HOT, wpt, cldprob,
                       &sum_clr, cloud, idused, &t_templ, &t_temph);
  emxFree_real32_T(&st, &cldprob);
  emxFree_real32_T(&st, &wpt);
  emxFree_real32_T(&st, &HOT);
  emxFree_real32_T(&st, &whiteness);
  emxFree_boolean_T(&st, &idplcd);
  emxFree_real32_T(&st, &ndbi);
  emxFree_real32_T(&st, &ndsi);
  emxFree_real32_T(&st, &ndvi);
  emxFreeStruct_struct1_T(&st, &dem);
  emxFreeStruct_struct0_T(&st, &data_toabt);
  emxFree_uint8_T(&st, &water);
  emxFree_boolean_T(&st, &mask);
  emxFreeStruct_ObjMeta(&st, &data_meta);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(sum_clr);
  if (nlhs > 1) {
    cloud->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(cloud);
  }
  emxFree_uint8_T(&st, &cloud);
  if (nlhs > 2) {
    idused->canFreeData = false;
    plhs[2] = c_emlrt_marshallOut(idused);
  }
  emxFree_boolean_T(&st, &idused);
  if (nlhs > 3) {
    plhs[3] = d_emlrt_marshallOut(t_templ);
  }
  if (nlhs > 4) {
    plhs[4] = d_emlrt_marshallOut(t_temph);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void DetectPotentialCloud_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  DetectPotentialCloud_xil_terminate();
  DetectPotentialCloud_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void DetectPotentialCloud_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void DetectPotentialCloud_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_DetectPotentialCloud_api.c) */
