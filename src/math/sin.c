/*

  sin.c

  Gehrig Wilcox

  11/13/20

*/

#include "math.h"
#include "math/cos.c"


/*

  Returns sine approximation of angle x in radians.

  For in-depth explanation, see github wiki page located at:
  https://github.com/lougehrig10/C-Standard-Library/wiki/sin_

*/
double sin(double x){
  // sin is cos shifted right a quarter of a circle
  return cos(x-M_PI/2);
}
