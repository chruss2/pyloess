#ifndef LOESSC_H
#define LOESSC_H

#include "S.h"
#include "loess.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define  GAUSSIAN  1
#define  SYMMETRIC 0

void
loess_raw(double *y, double *x, double *weights, double *robust, int *d,
          int*n, double *span, int *degree, int *nonparametric,
          int *drop_square, int *sum_drop_sqr, double *cell, char **surf_stat,
          double *surface, long *parameter, long *a, double *xi, double *vert,
          double *vval, double *diagonal, double *trL, double *one_delta,
          double *two_delta, int *setLf);

void
loess_dfit(double *y, double *x, double *x_evaluate, double *weights,
           double *span, int *degree, int *nonparametric,
           int *drop_square, int *sum_drop_sqr, int *d, int *n, int *m,
           double *fit);

void
loess_dfitse(double *y, double *x, double *x_evaluate, double *weights,
             double *robust, int *family, double *span, int *degree,
             int *nonparametric, int *drop_square, int *sum_drop_sqr,
             int *d, int *n, int *m, double *fit, double *L);

void
loess_ifit(long *parameter, long *a, double *xi, double *vert, double *vval,
           int *m, double *x_evaluate, double *fit);

void
loess_ise(double *y, double *x, double *x_evaluate, double *weights,
          double *span, int *degree, int *nonparametric, int *drop_square,
          int *sum_drop_sqr, double *cell, int *d, int *n, int *m,
          double *fit, double *L);

void
loess_workspace(int *d, int *n, double *span, int *degree,
                int *nonparametric, int *drop_square, int *sum_drop_sqr,
                int *setLf);

void
loess_prune(long *parameter, long *a, double *xi, double *vert, double *vval);

void
loess_grow(long *parameter, long *a, double *xi, double *vert, double *vval);

void
loess_free(void);

#endif /* LOESSC_H */
