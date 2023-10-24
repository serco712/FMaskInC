/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imfilter.c
 *
 * Code generation for function 'imfilter'
 *
 */

/* Include files */
#include "imfilter.h"
#include "autoFmask_emxutil.h"
#include "autoFmask_types.h"
#include "padarray.h"
#include "svd.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"
#include <math.h>

/* Function Definitions */
void imfilter(emxArray_real_T *varargin_1, const emxArray_real_T *varargin_2)
{
  emxArray_boolean_T *b_conn;
  emxArray_boolean_T *c_conn;
  emxArray_boolean_T *conn;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *a;
  emxArray_real_T *a__2;
  emxArray_real_T *b_s;
  emxArray_real_T *hcol;
  emxArray_real_T *hrow;
  emxArray_real_T *s;
  emxArray_real_T *v;
  double outSizeT[2];
  double startT[2];
  const double *varargin_2_data;
  double *a_data;
  double *b_s_data;
  double *hcol_data;
  double *hrow_data;
  double *s_data;
  double *v_data;
  int b_outSizeT_tmp;
  int i;
  int k;
  int outSizeT_tmp;
  int u1;
  int *r2;
  boolean_T *conn_data;
  varargin_2_data = varargin_2->data;
  outSizeT_tmp = varargin_1->size[0];
  outSizeT[0] = outSizeT_tmp;
  startT[0] = (double)varargin_2->size[0] -
              floor(((double)varargin_2->size[0] + 1.0) / 2.0);
  b_outSizeT_tmp = varargin_1->size[1];
  outSizeT[1] = b_outSizeT_tmp;
  startT[1] = (double)varargin_2->size[1] -
              floor(((double)varargin_2->size[1] + 1.0) / 2.0);
  emxInit_real_T(&v, 2);
  emxInit_real_T(&a, 2);
  emxInit_real_T(&hcol, 1);
  emxInit_real_T(&hrow, 2);
  emxInit_real_T(&a__2, 2);
  emxInit_real_T(&s, 2);
  emxInit_real_T(&b_s, 1);
  emxInit_boolean_T(&conn, 2);
  emxInit_boolean_T(&b_conn, 2);
  emxInit_int32_T(&r, 1);
  emxInit_boolean_T(&c_conn, 1);
  emxInit_int32_T(&r1, 1);
  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    if ((varargin_2->size[0] == 0) || (varargin_2->size[1] == 0)) {
      i = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = outSizeT_tmp;
      emxEnsureCapacity_real_T(varargin_1, i);
      i = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[1] = b_outSizeT_tmp;
      emxEnsureCapacity_real_T(varargin_1, i);
      s_data = varargin_1->data;
      for (i = 0; i < b_outSizeT_tmp; i++) {
        for (u1 = 0; u1 < outSizeT_tmp; u1++) {
          s_data[u1 + varargin_1->size[0] * i] = 0.0;
        }
      }
    } else {
      double tol;
      int last;
      int loop_ub;
      boolean_T tooBig;
      loop_ub = varargin_2->size[0] * varargin_2->size[1];
      if (loop_ub >= 49) {
        boolean_T x[2];
        boolean_T exitg1;
        x[0] = (varargin_2->size[0] != 1);
        x[1] = (varargin_2->size[1] != 1);
        tooBig = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= 1)) {
          if (!x[k]) {
            tooBig = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
        if (tooBig) {
          svd(varargin_2, a, s, a__2);
          s_data = s->data;
          if ((s->size[0] == 1) && (s->size[1] == 1)) {
            i = b_s->size[0];
            b_s->size[0] = 1;
            emxEnsureCapacity_real_T(b_s, i);
            b_s_data = b_s->data;
            b_s_data[0] = s_data[0];
          } else {
            last = s->size[0];
            u1 = s->size[1];
            if (last <= u1) {
              u1 = last;
            }
            if (s->size[1] > 0) {
              last = u1;
            } else {
              last = 0;
            }
            i = b_s->size[0];
            b_s->size[0] = last;
            emxEnsureCapacity_real_T(b_s, i);
            b_s_data = b_s->data;
            i = last - 1;
            for (k = 0; k <= i; k++) {
              b_s_data[k] = s_data[k + s->size[0] * k];
            }
          }
          last = b_s->size[0];
          if (b_s->size[0] <= 2) {
            if (b_s->size[0] == 1) {
              tol = b_s_data[0];
            } else {
              tol = b_s_data[b_s->size[0] - 1];
              if (b_s_data[0] >= tol) {
                tol = b_s_data[0];
              }
            }
          } else {
            tol = b_s_data[0];
            for (k = 2; k <= last; k++) {
              double d;
              d = b_s_data[k - 1];
              if (tol < d) {
                tol = d;
              }
            }
          }
          last = varargin_2->size[0];
          u1 = varargin_2->size[1];
          if (last >= u1) {
            u1 = last;
          }
          tol = (double)u1 * tol * 2.2204460492503131E-16;
          i = c_conn->size[0];
          c_conn->size[0] = b_s->size[0];
          emxEnsureCapacity_boolean_T(c_conn, i);
          conn_data = c_conn->data;
          u1 = b_s->size[0];
          for (i = 0; i < u1; i++) {
            conn_data[i] = (b_s_data[i] > tol);
          }
          u1 = c_conn->size[0];
          last = conn_data[0];
          for (k = 2; k <= u1; k++) {
            last += conn_data[k - 1];
          }
          tooBig = (last == 1);
        } else {
          tooBig = false;
        }
      } else {
        tooBig = false;
      }
      if (tooBig) {
        double connDimsT[2];
        double out_size_row[2];
        double padSizeT[2];
        double start[2];
        padarray(varargin_1, startT, a);
        a_data = a->data;
        svd(varargin_2, a__2, s, v);
        v_data = v->data;
        s_data = s->data;
        hrow_data = a__2->data;
        if ((s->size[0] == 1) && (s->size[1] == 1)) {
          i = b_s->size[0];
          b_s->size[0] = 1;
          emxEnsureCapacity_real_T(b_s, i);
          b_s_data = b_s->data;
          b_s_data[0] = s_data[0];
        } else {
          last = s->size[0];
          u1 = s->size[1];
          if (last <= u1) {
            u1 = last;
          }
          if (s->size[1] > 0) {
            last = u1;
          } else {
            last = 0;
          }
          i = b_s->size[0];
          b_s->size[0] = last;
          emxEnsureCapacity_real_T(b_s, i);
          b_s_data = b_s->data;
          i = last - 1;
          for (k = 0; k <= i; k++) {
            b_s_data[k] = s_data[k + s->size[0] * k];
          }
        }
        tol = sqrt(b_s_data[0]);
        i = hcol->size[0];
        hcol->size[0] = a__2->size[0];
        emxEnsureCapacity_real_T(hcol, i);
        hcol_data = hcol->data;
        loop_ub = a__2->size[0];
        for (i = 0; i < loop_ub; i++) {
          hcol_data[i] = hrow_data[i] * tol;
        }
        i = hrow->size[0] * hrow->size[1];
        hrow->size[0] = 1;
        hrow->size[1] = v->size[0];
        emxEnsureCapacity_real_T(hrow, i);
        hrow_data = hrow->data;
        loop_ub = v->size[0];
        for (i = 0; i < loop_ub; i++) {
          hrow_data[i] = v_data[i] * tol;
        }
        out_size_row[0] = a->size[0];
        out_size_row[1] = b_outSizeT_tmp;
        start[0] = 0.0;
        start[1] = startT[1];
        i = b_conn->size[0] * b_conn->size[1];
        b_conn->size[0] = 1;
        b_conn->size[1] = hrow->size[1];
        emxEnsureCapacity_boolean_T(b_conn, i);
        conn_data = b_conn->data;
        loop_ub = hrow->size[1];
        for (i = 0; i < loop_ub; i++) {
          conn_data[i] = (hrow_data[i] != 0.0);
        }
        last = b_conn->size[1] - 1;
        u1 = 0;
        for (k = 0; k <= last; k++) {
          if (conn_data[k]) {
            u1++;
          }
        }
        i = r->size[0];
        r->size[0] = u1;
        emxEnsureCapacity_int32_T(r, i);
        r2 = r->data;
        u1 = 0;
        for (k = 0; k <= last; k++) {
          if (conn_data[k]) {
            r2[u1] = k;
            u1++;
          }
        }
        i = b_s->size[0];
        b_s->size[0] = r->size[0];
        emxEnsureCapacity_real_T(b_s, i);
        b_s_data = b_s->data;
        loop_ub = r->size[0];
        for (i = 0; i < loop_ub; i++) {
          b_s_data[i] = hrow_data[r2[i]];
        }
        tooBig = true;
        for (k = 0; k < 2; k++) {
          if ((!tooBig) || (out_size_row[k] <= 65500.0)) {
            tooBig = false;
          }
        }
        if (((double)r->size[0] / (double)hrow->size[1] > 0.05) && (!tooBig)) {
          tooBig = true;
        } else {
          tooBig = false;
        }
        i = varargin_1->size[0] * varargin_1->size[1];
        varargin_1->size[0] = a->size[0];
        varargin_1->size[1] = b_outSizeT_tmp;
        emxEnsureCapacity_real_T(varargin_1, i);
        s_data = varargin_1->data;
        if (tooBig) {
          padSizeT[0] = a->size[0];
          connDimsT[0] = 1.0;
          padSizeT[1] = a->size[1];
          connDimsT[1] = hrow->size[1];
          ippfilter_real64(&a_data[0], &s_data[0], &out_size_row[0], 2.0,
                           &padSizeT[0], &hrow_data[0], &connDimsT[0], false);
        } else {
          padSizeT[0] = a->size[0];
          connDimsT[0] = 1.0;
          padSizeT[1] = a->size[1];
          connDimsT[1] = b_conn->size[1];
          imfilter_real64(&a_data[0], &s_data[0], 2.0, &out_size_row[0], 2.0,
                          &padSizeT[0], &b_s_data[0], (double)r->size[0],
                          &conn_data[0], 2.0, &connDimsT[0], &start[0], 2.0,
                          true, false);
        }
        start[0] = startT[0];
        start[1] = 0.0;
        i = c_conn->size[0];
        c_conn->size[0] = hcol->size[0];
        emxEnsureCapacity_boolean_T(c_conn, i);
        conn_data = c_conn->data;
        loop_ub = hcol->size[0];
        for (i = 0; i < loop_ub; i++) {
          conn_data[i] = (hcol_data[i] != 0.0);
        }
        last = c_conn->size[0] - 1;
        u1 = 0;
        for (k = 0; k <= last; k++) {
          if (conn_data[k]) {
            u1++;
          }
        }
        i = r1->size[0];
        r1->size[0] = u1;
        emxEnsureCapacity_int32_T(r1, i);
        r2 = r1->data;
        u1 = 0;
        for (k = 0; k <= last; k++) {
          if (conn_data[k]) {
            r2[u1] = k;
            u1++;
          }
        }
        i = b_s->size[0];
        b_s->size[0] = r1->size[0];
        emxEnsureCapacity_real_T(b_s, i);
        b_s_data = b_s->data;
        loop_ub = r1->size[0];
        for (i = 0; i < loop_ub; i++) {
          b_s_data[i] = hcol_data[r2[i]];
        }
        tooBig = true;
        for (k = 0; k < 2; k++) {
          if ((!tooBig) || (outSizeT[k] <= 65500.0)) {
            tooBig = false;
          }
        }
        if (((double)r1->size[0] / (double)hcol->size[0] > 0.05) && (!tooBig)) {
          tooBig = true;
        } else {
          tooBig = false;
        }
        i = a->size[0] * a->size[1];
        a->size[0] = varargin_1->size[0];
        a->size[1] = varargin_1->size[1];
        emxEnsureCapacity_real_T(a, i);
        a_data = a->data;
        loop_ub = varargin_1->size[0] * varargin_1->size[1];
        for (i = 0; i < loop_ub; i++) {
          a_data[i] = s_data[i];
        }
        i = varargin_1->size[0] * varargin_1->size[1];
        varargin_1->size[0] = outSizeT_tmp;
        varargin_1->size[1] = b_outSizeT_tmp;
        emxEnsureCapacity_real_T(varargin_1, i);
        s_data = varargin_1->data;
        if (tooBig) {
          padSizeT[0] = a->size[0];
          padSizeT[1] = a->size[1];
          connDimsT[0] = hcol->size[0];
          connDimsT[1] = 1.0;
          ippfilter_real64(&a_data[0], &s_data[0], &outSizeT[0], 2.0,
                           &padSizeT[0], &hcol_data[0], &connDimsT[0], false);
        } else {
          padSizeT[0] = a->size[0];
          padSizeT[1] = a->size[1];
          connDimsT[0] = c_conn->size[0];
          connDimsT[1] = 1.0;
          imfilter_real64(&a_data[0], &s_data[0], 2.0, &outSizeT[0], 2.0,
                          &padSizeT[0], &b_s_data[0], (double)r1->size[0],
                          &conn_data[0], 2.0, &connDimsT[0], &start[0], 2.0,
                          true, false);
        }
      } else {
        padarray(varargin_1, startT, a);
        a_data = a->data;
        i = conn->size[0] * conn->size[1];
        conn->size[0] = varargin_2->size[0];
        conn->size[1] = varargin_2->size[1];
        emxEnsureCapacity_boolean_T(conn, i);
        conn_data = conn->data;
        for (i = 0; i < loop_ub; i++) {
          conn_data[i] = (varargin_2_data[i] != 0.0);
        }
        tooBig = ((varargin_2->size[0] == 1) || (varargin_2->size[1] == 1));
        if (tooBig) {
          last = loop_ub - 1;
          u1 = 0;
          for (k = 0; k <= last; k++) {
            if (conn_data[k]) {
              u1++;
            }
          }
          i = b_s->size[0];
          b_s->size[0] = u1;
          emxEnsureCapacity_real_T(b_s, i);
          b_s_data = b_s->data;
          u1 = 0;
          for (k = 0; k <= last; k++) {
            if (conn_data[k]) {
              b_s_data[u1] = varargin_2_data[k];
              u1++;
            }
          }
        } else {
          last = loop_ub - 1;
          u1 = 0;
          for (k = 0; k <= last; k++) {
            if (conn_data[k]) {
              u1++;
            }
          }
          i = b_s->size[0];
          b_s->size[0] = u1;
          emxEnsureCapacity_real_T(b_s, i);
          b_s_data = b_s->data;
          u1 = 0;
          for (k = 0; k <= last; k++) {
            if (conn_data[k]) {
              b_s_data[u1] = varargin_2_data[k];
              u1++;
            }
          }
        }
        tooBig = true;
        for (k = 0; k < 2; k++) {
          if ((!tooBig) || (outSizeT[k] <= 65500.0)) {
            tooBig = false;
          }
        }
        if (((double)b_s->size[0] / (double)loop_ub > 0.05) && (!tooBig)) {
          tooBig = true;
        } else {
          tooBig = false;
        }
        i = varargin_1->size[0] * varargin_1->size[1];
        varargin_1->size[0] = outSizeT_tmp;
        varargin_1->size[1] = b_outSizeT_tmp;
        emxEnsureCapacity_real_T(varargin_1, i);
        s_data = varargin_1->data;
        if (tooBig) {
          double connDimsT[2];
          double padSizeT[2];
          padSizeT[0] = a->size[0];
          connDimsT[0] = varargin_2->size[0];
          padSizeT[1] = a->size[1];
          connDimsT[1] = varargin_2->size[1];
          ippfilter_real64(&a_data[0], &s_data[0], &outSizeT[0], 2.0,
                           &padSizeT[0], &varargin_2_data[0], &connDimsT[0],
                           false);
        } else {
          double connDimsT[2];
          double padSizeT[2];
          padSizeT[0] = a->size[0];
          connDimsT[0] = conn->size[0];
          padSizeT[1] = a->size[1];
          connDimsT[1] = conn->size[1];
          imfilter_real64(&a_data[0], &s_data[0], 2.0, &outSizeT[0], 2.0,
                          &padSizeT[0], &b_s_data[0], (double)b_s->size[0],
                          &conn_data[0], 2.0, &connDimsT[0], &startT[0], 2.0,
                          true, false);
        }
      }
    }
  }
  emxFree_int32_T(&r1);
  emxFree_boolean_T(&c_conn);
  emxFree_int32_T(&r);
  emxFree_boolean_T(&b_conn);
  emxFree_boolean_T(&conn);
  emxFree_real_T(&b_s);
  emxFree_real_T(&s);
  emxFree_real_T(&a__2);
  emxFree_real_T(&hrow);
  emxFree_real_T(&hcol);
  emxFree_real_T(&a);
  emxFree_real_T(&v);
}

/* End of code generation (imfilter.c) */
