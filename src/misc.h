#ifndef MISC_H
#define MISC_H

#include "S.h"
#include "loess.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void anova(loess *one, loess *two, anova_struct *out);
double qt(double p, double df);

/*
 * Rational approximation to inverse Gaussian distribution.
 * Absolute error is bounded by 4.5e-4.
 * Reference: Abramowitz and Stegun, page 933.
 * Assumption: 0 < p < 1.
 */
double invigauss_quick(double p);

/*
 * Inverse incomplete beta function.
 * Assumption: 0 <= p <= 1, a,b > 0.
 */
double invibeta(double p, double a, double b);

/*
 * Quick approximation to inverse incomplete beta function,
 * by matching first two moments with the Gaussian distribution.
 * Assumption: 0 < p < 1, a,b > 0.
 */
double invibeta_quick(double p, double a, double b);

int max(int a, int b);

typedef double doublereal;
typedef int integer;

#ifdef __GNUC__
#define NORETURN __attribute__ ((noreturn))
#else
#define NORETURN
#endif

void Recover(char *a, int *b) NORETURN;
void Warning(char *a, int *b);

/*  d1mach may be replaced by Fortran code:
    mail netlib@netlib.bell-labs.com
    send d1mach from core.
*/
doublereal F77_SUB(d1mach) (integer *i);

#endif /* MISC_H */
