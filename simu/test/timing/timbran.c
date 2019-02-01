/*  timbran.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <time.h>
#include "ccmath.h"
void main(int na,char **av)
{ unsigned int s;
  int i,n,m,k; clock_t st,en;
  double dt,tms;
  if(na!=2){ printf("para: count\n"); exit(1);}
  n=atoi(*++av);
  s=0x5a7d3b28; m=256;
  setbran(s);
  st=clock();
  for(i=0; i<n ;++i) k=bran(m);
  en=clock();
  dt=(en-st)/(double)CLOCKS_PER_SEC;
  tms =1.e6*(dt/n);
  printf(" %d evaluations in %.3f sec.\n",n,dt);
  printf("  %.3e microsec per evaluation\n",tms);
}
