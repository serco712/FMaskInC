/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_DetectPotentialCloud_info.c
 *
 * Code generation for function 'DetectPotentialCloud'
 *
 */

/* Include files */
#include "_coder_DetectPotentialCloud_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[7] = {
      "789ced98cd729a5014c7b19376ba69c3a6eda2abbc40b0d189935d13056dd44423b5c64e"
      "2705bcc28d172ec2354a5ea2afd0651fa1d3e933f5191a3f50a073e3"
      "0711c794bb399ef90bffc339cc6fcec0243e94130cc3bc64c6a7b2378e2f26393b894f18"
      "ff09ea89497c16c8ddf394d9f15de7eadf2651c1060103324e0c4907",
      "d32b5b5887866410d1310163011ba31bd01a296d8880087550f32667c34c173cd234194a"
      "c3df590d289d5a4f672ccd9e5588bcc9b41f3f28cfbbb3603f784a3f"
      "d880fe99ffc26958079c0d2c15622e07ec0ec126c7dba4d782d8e64421cf09ba6477aed2"
      "57877732010aa960020c02259445b8d7dad73d757f0d59f7736add63",
      "c5b4b02c6ad078283fda7bc34e141b1a2a02b3e7fb1ed2ef88eae7d7979c8bdb96d12c86"
      "675e7f7617ac371867ff1fcfe3f79fb772947eeef95ffc0694fb2dfa"
      "bebda2f8b101bd7891aca9b73290cbe7c269b35d34cd52b7e8a9a332c7675e1d0c258fea"
      "fedbca533364ddb43eb1813804485f04ba092c89f42cb029be869dd3",
      "31d5cfafafc0576f7b22e7ecaf98b36bf50bcbd9d7143f36a05f2751432ea1eb4c23d7e0"
      "493955fd3418a07cccd96de7ec6e200fd6edea23909c5850d588016c"
      "fbc1f6e6a8f7d8f7543fbfbe0a6767edd9d763be3e0ebfa8f86a1cf7958be669b15414f8"
      "2ebc4c966e14745e88f9baed7c5d668f45f11e7b1f5fd126f7d89f31",
      "67d7ea17d5f78283862349aaa135d3ed8c853bb0dacd2b6926e6ecb67376993d16c57bec"
      "bd9cddc41e1bf375bd7e51edb14ed369759a03e99d739429007052b7"
      "ea679742ccd74df335ecfcdfcca9dbd54700a99977c55812aa4b16942182c4d91867c3ce"
      "ab40f5f3ebab70f6df36c5df0d1e8b5f54bcbd6d6753f601c81d8a7d",
      "94497dc4b09acef5f9ede7ed5f82bef777",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 8552U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "Name",     "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "FullPath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 13);
  emlrtSetField(xEntryPoints, 0, "Name",
                emlrtMxCreateString("DetectPotentialCloud"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(13.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(5.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath",
                emlrtMxCreateString("/home/sergio/Desktop/Estudios/TFG/"
                                    "Fmask_4_6/DetectPotentialCloud.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739176.41469907411));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2380103 (R2023b) Update 1"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("DDH1IZUE5YxKcqGkEQ1ASD"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_DetectPotentialCloud_info.c) */
