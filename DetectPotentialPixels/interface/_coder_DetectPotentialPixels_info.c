/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_DetectPotentialPixels_info.c
 *
 * Code generation for function 'DetectPotentialPixels'
 *
 */

/* Include files */
#include "_coder_DetectPotentialPixels_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[4] = {
      "789cc593514e8340108617531b1353253e788ce2837a005bd698d8da041e1a8da948c776"
      "cb2e5bd9a5a297e835bc90f7514a2914b3a106adf332fc7c59fe9f99"
      "2cd2ae3a1a42e8002535ad27bdb1d4fab2efa0f52a724dd1d3da45b5b573299f2fbbcb7d"
      "09914c84ef30589d1c72467cc797f6eb14500082d3190c17e48950b0",
      "09032b2fbab1623887562246f1736b0cae67850c05639125a479b19ac7bbe27f6b1bce03"
      "2be6a117f89d796f8c390343403022dc6883f0249f1aa690e1907061"
      "d8f8d2c0cc11dee07470fe8525b8b2c725f89238b44722a0a2c9b2dc51c5dc4725b953de"
      "e501732879735a240842d1363bc9fb34c743c51c75658e8408e28f28",
      "fcdebe5a4abf75fec37d7d1f53bc2c543ea7c30d73abee5d03ed2dfae3bc09dbf4dbffe8"
      "6bdbf44bebbffcaadeb763859f5ee07832c3cf1d6bd2bfb8f66ec4cb"
      "ad7d76125a38cbd12bf129cb8114faafbfff09c9e57578",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1672U, &nameCaptureInfo);
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
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 0, "Name",
                emlrtMxCreateString("DetectPotentialPixels"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath",
                emlrtMxCreateString("/home/sergio/Desktop/Estudios/TFG/"
                                    "Fmask_4_6/DetectPotentialPixels.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739176.65424768522));
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
                emlrtMxCreateString("r5IoHcIvRKJHy5XanhaIiB"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_DetectPotentialPixels_info.c) */
