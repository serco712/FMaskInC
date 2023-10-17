/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_DetectPotentialCloud_mex.c
 *
 * Code generation for function 'DetectPotentialCloud'
 *
 */

/* Include files */
#include "_coder_DetectPotentialCloud_mex.h"
#include "_coder_DetectPotentialCloud_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&DetectPotentialCloud_atexit);
  /* Module initialization. */
  DetectPotentialCloud_initialize();
  /* Dispatch the entry-point. */
  unsafe_DetectPotentialCloud_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  DetectPotentialCloud_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

void unsafe_DetectPotentialCloud_mexFunction(int32_T nlhs, mxArray *plhs[5],
                                             int32_T nrhs,
                                             const mxArray *prhs[13])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[13];
  const mxArray *outputs[5];
  int32_T i;
  int32_T i1;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 13) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 13, 4,
                        20, "DetectPotentialCloud");
  }
  if (nlhs > 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "DetectPotentialCloud");
  }
  /* Call the function. */
  for (i = 0; i < 13; i++) {
    b_prhs[i] = prhs[i];
  }
  DetectPotentialCloud_api(b_prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i1 = 1;
  } else {
    i1 = nlhs;
  }
  emlrtReturnArrays(i1, &plhs[0], &outputs[0]);
}

/* End of code generation (_coder_DetectPotentialCloud_mex.c) */
