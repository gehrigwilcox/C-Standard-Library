/*

  cos.c

  Gehrig Wilcox

  11/13/20

*/

#include "math.h"
#include "math/CosTaylorSeries.c"


/*

  Returns cosine approximation of angle x in radians.

  For in-depth explanation, see github wiki page located at:
  https://github.com/lougehrig10/C-Standard-Library/wiki/cos_

*/
double cos(double x){

  // Mathematically identical to -1^(floor(x+pi/2)/pi)
  int flip = (((int)((x+M_PI/2)/M_PI))%2 ? -1 : 1);

  /*
    Shift input left a quarter of a circle, take half a circle, then shift back
    This gives us the bottom half of the circle.
  */
  x=fmod(x+M_PI/2,M_PI)-M_PI/2;

  return flip*cosTaylorSeries(x);
}
