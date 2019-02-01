/*  htgsss.c    CCMATH mathematics library source code.
 *
 *  Copyright (C)  2000   Daniel A. Atkinson    All rights reserved.
 *  This code may be redistributed under the terms of the GNU library
 *  public license (LGPL). ( See the lgpl.license file for details.)
 * ------------------------------------------------------------------------
 */
#include <math.h>
int htgsss(double a,double b,double c,double *ang)
{ double s;
  s=.5*(a+b+c);
  if(s-a<0. || s-b<0. || s-c<0.) return -1;
  a=cosh(a); b=cosh(b); c=cosh(c);
  s=a*b*c; s+=s;
  s=sqrt(1.-a*a-b*b-c*c+s);
  ang[0]=atan2(s,b*c-a);
  ang[1]=atan2(s,c*a-b);
  ang[2]=atan2(s,a*b-c);
  return 0;
}
