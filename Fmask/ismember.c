/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ismember.c
 *
 * Code generation for function 'ismember'
 *
 */

/* Include files */
#include "ismember.h"
#include "Fmask_emxutil.h"
#include "Fmask_types.h"
#include "sort.h"
#include "omp.h"

/* Function Declarations */
static int bsearchni(int k, const emxArray_real_T *x, const emxArray_real_T *s);

/* Function Definitions */
static int bsearchni(int k, const emxArray_real_T *x, const emxArray_real_T *s)
{
  const double *s_data;
  const double *x_data;
  double b_x;
  int idx;
  int ihi;
  int ilo;
  boolean_T exitg1;
  s_data = s->data;
  x_data = x->data;
  b_x = x_data[k - 1];
  ihi = s->size[0];
  idx = 0;
  ilo = 1;
  exitg1 = false;
  while ((!exitg1) && (ihi >= ilo)) {
    int imid;
    imid = ((ilo >> 1) + (ihi >> 1)) - 1;
    if (((ilo & 1) == 1) && ((ihi & 1) == 1)) {
      imid++;
    }
    if (b_x == s_data[imid]) {
      idx = imid + 1;
      exitg1 = true;
    } else if (b_x < s_data[imid]) {
      ihi = imid;
    } else {
      ilo = imid + 2;
    }
  }
  if (idx > 0) {
    idx--;
    while ((idx > 0) && (b_x == s_data[idx - 1])) {
      idx--;
    }
    idx++;
  }
  return idx;
}

void isMember(const emxArray_real_T *a, const emxArray_real_T *s,
              emxArray_boolean_T *tf)
{
  emxArray_int32_T *b_ss;
  emxArray_real_T *ss;
  const double *a_data;
  const double *s_data;
  double *ss_data;
  int k;
  int n;
  int na;
  int ns;
  int pmax;
  int pmin;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T *tf_data;
  s_data = s->data;
  a_data = a->data;
  na = a->size[0] * a->size[1] - 1;
  ns = s->size[0];
  pmin = tf->size[0] * tf->size[1];
  tf->size[0] = a->size[0];
  tf->size[1] = a->size[1];
  emxEnsureCapacity_boolean_T(tf, pmin);
  tf_data = tf->data;
  pmax = a->size[0] * a->size[1];
  for (pmin = 0; pmin < pmax; pmin++) {
    tf_data[pmin] = false;
  }
  emxInit_real_T(&ss, 1);
  emxInit_int32_T(&b_ss, 1);
  guard1 = false;
  if (s->size[0] <= 4) {
    guard1 = true;
  } else {
    pmax = 31;
    pmin = 0;
    exitg1 = false;
    while ((!exitg1) && (pmax - pmin > 1)) {
      int p;
      int pow2p;
      p = (pmin + pmax) >> 1;
      pow2p = 1 << p;
      if (pow2p == ns) {
        pmax = p;
        exitg1 = true;
      } else if (pow2p > ns) {
        pmax = p;
      } else {
        pmin = p;
      }
    }
    if (na + 1 <= pmax + 4) {
      guard1 = true;
    } else {
      boolean_T y;
      y = true;
      pmax = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax <= s->size[0] - 2)) {
        y = (s_data[pmax] <= s_data[pmax + 1]);
        if (!y) {
          exitg1 = true;
        } else {
          pmax++;
        }
      }
      if (!y) {
        pmin = ss->size[0];
        ss->size[0] = s->size[0];
        emxEnsureCapacity_real_T(ss, pmin);
        ss_data = ss->data;
        pmax = s->size[0];
        for (pmin = 0; pmin < pmax; pmin++) {
          ss_data[pmin] = s_data[pmin];
        }
        sort(ss, b_ss);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(n)

        for (k = 0; k <= na; k++) {
          n = bsearchni(k + 1, a, ss);
          if (n > 0) {
            tf_data[k] = true;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(n)

        for (k = 0; k <= na; k++) {
          n = bsearchni(k + 1, a, s);
          if (n > 0) {
            tf_data[k] = true;
          }
        }
      }
    }
  }
  if (guard1) {
    for (pmin = 0; pmin <= na; pmin++) {
      pmax = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax <= ns - 1)) {
        if (a_data[pmin] == s_data[pmax]) {
          tf_data[pmin] = true;
          exitg1 = true;
        } else {
          pmax++;
        }
      }
    }
  }
  emxFree_int32_T(&b_ss);
  emxFree_real_T(&ss);
}

/* End of code generation (ismember.c) */
