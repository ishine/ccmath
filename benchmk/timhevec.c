/*  timhevec.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
/*
    Time computation of eigenvalues and eigenvectors of a Hermitian matrix.

    Input file:  created by hmatgen.c
*/
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ Cpx *a; double *ev; int n;
  clock_t st,en; double dt;
  FILE *fb;
  if(na!=2){ printf("para: input_file\n"); exit(1);}
  fb=fopen(*++av,"rb");
  fread((void *)&n,sizeof(int),1,fb);
  printf(" hermitian e-val and e-vec: dim=%d\n",n);
  a=(Cpx *)calloc(n*n,sizeof(Cpx));
  ev=(double *)calloc(n,sizeof(double));
  fread((void *)a,sizeof(Cpx),n*n,fb);
  st=clock();
  heigvec(a,ev,n);
  en=clock();
  dt=(double)(en-st)/(double)CLOCKS_PER_SEC;
  printf("    time= %.2f sec.\n",dt);
}
