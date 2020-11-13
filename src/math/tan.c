/*

  tan.c

  Gehrig Wilcox

  11/13/20

*/

#include "math.h"
#include "math/cos.c"
#include "math/sin.c"


/*

  Returns tangent approximation of angle x in radians.

  For in-depth explanation, see github wiki page located at:
  https://github.com/lougehrig10/C-Standard-Library/wiki/tan_

*/
double tan(double x){
  // tan is the relationship between sin and cos
  return sin(x)/cos(x);
}
