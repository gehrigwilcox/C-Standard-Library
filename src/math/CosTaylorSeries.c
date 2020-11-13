/*

  CosTaylorSeries.c

  Gehrig Wilcox

  11/9/20

*/


#include "math/pow.c"



/*

  Returns the factorial of input number

*/
inline int factorial(int x){
  int ret = x;
  for(x--; x > 0; x--){
    ret *= x;
  }
  return ret;
}

/*

  Returns the Taylor series approx. of x with desiredDegree (10) degrees

  Taylor series: 1+(((-1)^(floor(n/4)))*((x^n)/!n))
  i.e. 1-((x^2)/!2)+((x^4)/!4)-((x^6)/!6)+((x^8)/!8)-((x^10)/!10)

  Input: Radians

*/
double cosTaylorSeries(double x){
  int desiredDegree = 10;

  // Make sure desired degree is even
  desiredDegree += desiredDegree%2;

  double ret = 0;
  for(; desiredDegree>=0; desiredDegree-=2){
    ret += pow(-1,(i%4)/2)*pow(x,desiredDegree)/factorial(x);
  }

  return ret;

}
