#ifndef LOESSF_H
#define LOESSF_H

#include "S.h"

#define F_INTEGER int *
#define F_DOUBLE  double *
#define F_LOGICAL  int *
#define F_INTEGER_VEC(len) int *
#define F_INTEGER_MAT(m,n) int *
#define F_DOUBLE_VEC(len) double *
#define F_DOUBLE_MAT(m,n) double *

void F77_SUB(lowesc)(F_INTEGER n, F_DOUBLE_MAT(n,n) l, F_DOUBLE_MAT(n,n) ll,
                     F_DOUBLE trl, F_DOUBLE delta1, F_DOUBLE delta2);

void F77_SUB(lowesa)(F_DOUBLE trl, F_INTEGER n, F_INTEGER d, F_INTEGER tau,
                     F_INTEGER nsing, F_DOUBLE delta1, F_DOUBLE delta2);

void F77_SUB(lowesb)(F_DOUBLE_VEC(*) xx, F_DOUBLE_VEC(*) yy, F_DOUBLE_VEC(*) ww,
                     F_DOUBLE_VEC(*) diagl, F_LOGICAL infl, F_INTEGER_VEC(*) iv,
                     F_INTEGER liv, F_INTEGER lv, F_DOUBLE_VEC(*) wv);

void F77_SUB(lowesd)(F_INTEGER versio, F_INTEGER_VEC(liv) iv, F_INTEGER liv,
                     F_INTEGER lv, F_DOUBLE_VEC(lv) v, F_INTEGER d, F_INTEGER n,
                     F_DOUBLE f, F_INTEGER ideg, F_INTEGER nvmax,
                     F_LOGICAL setlf);

void F77_SUB(lowese)(F_INTEGER_VEC(*) iv, F_INTEGER liv, F_INTEGER lv,
                     F_DOUBLE_VEC(*) wv, F_INTEGER m, F_DOUBLE_MAT(m,1) z,
                     F_DOUBLE_VEC(m) s);

void F77_SUB(lowesf)(F_DOUBLE_VEC(*) xx, F_DOUBLE_VEC(*) yy, F_DOUBLE_VEC(*) ww,
                     F_INTEGER_VEC(*) iv, F_INTEGER liv, F_INTEGER lv,
                     F_DOUBLE_VEC(*) wv, F_INTEGER m, F_DOUBLE_MAT(m,1) z,
                     F_DOUBLE_MAT(m,*) l, F_INTEGER ihat, F_DOUBLE_VEC(m) s);

void F77_SUB(lowesl)(F_INTEGER_VEC(*) iv, F_INTEGER liv, F_INTEGER lv,
                     F_DOUBLE_VEC(*) wv, F_INTEGER m, F_DOUBLE_MAT(m,1) z,
                     F_DOUBLE_MAT(m,*) l);

void F77_SUB(lowesr)(F_DOUBLE_VEC(*) yy, F_INTEGER_VEC(*) iv, F_INTEGER liv,
                     F_INTEGER lv, F_DOUBLE_VEC(*) wv);

void F77_SUB(lowesw)(F_DOUBLE_VEC(n) res, F_INTEGER n, F_DOUBLE_VEC(n) rw,
                     F_INTEGER_VEC(n) pi);

void F77_SUB(lowesp)(F_INTEGER n, F_DOUBLE_VEC(n) y, F_DOUBLE_VEC(n) yhat,
                     F_DOUBLE_VEC(n) pwgts, F_DOUBLE_VEC(n) rwgts,
                     F_INTEGER_VEC(n) pi, F_DOUBLE_VEC(n) ytilde);

void F77_SUB(ehg169)(F_INTEGER d, F_INTEGER vc, F_INTEGER nc, F_INTEGER ncmax,
                     F_INTEGER nv, F_INTEGER nvmax, F_DOUBLE_MAT(nvmax,d) v,
                     F_INTEGER_VEC(ncmax) a, F_DOUBLE_VEC(ncmax) xi,
                     F_INTEGER_MAT(vc,ncmax) c, F_INTEGER_VEC(ncmax) hi,
                     F_INTEGER_VEC(ncmax) lo);

void F77_SUB(ehg196)(F_INTEGER tau, F_INTEGER d, F_DOUBLE f, F_DOUBLE trl);


#endif /* LOESSF_H */
