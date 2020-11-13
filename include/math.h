/*

  math.h as defined by C17 ISO/IEC 9899:2017

  Gehrig Wilcox
  9/1/20

*/

#if FLT_EVAL_METHOD == 0

  typedef float float_t;
  typedef double double_t;

#elif FLT_EVAL_METHOD == 1

  typedef double float_t;
  typedef double double_t;

#elif FlT_EVAL_METHOD == 2

  typedef long double float_t;
  typedef long double double_t;

#else

  typedef float float_t;
  typedef double double_t;

#endif

/*

  Expands to a positive double constant expression, not necessarily representable
  as a float

*/
#define HUGE_VAL

/*

  Respectively float and long double analogs of HUGE_VAL

*/
#define HUGE_VALF
#define HUGE_VALL

/*

  Expands to a constant expression of type float representing positive or
  unsigned infinity, if available; else to a positive constant of type float
  that overflows at translation time

*/
#define INFINITY

/*

  If implementation supports quiet NaNs for the float type, NAN expands to a
  constant expression of type float representing a quiet NaN

*/
#if
  #define NAN
#endif


/*

  Represent the mutually exclusive kinds of floating point values.
  Expand to integer constant expressions with distinct values.

*/
#define FP_INFINITE
#define FP_NAN
#define FP_NORMAL
#define FP_SUBNORMAL
#define FP_ZERO

/*

  If FP_FAST_FMA is defined, it indicates that the fma function generally
  executes as fast, or faster than, a multiply and an add of double operands.

*/
//#define FP_FAST_FMA


/*

  float and long double analogs of FP_FAST_FMA, if defined, expand to 1

*/
//#define FP_FAST_FMAF
//#define FP_FAST_FMAL

/*

  Expand to integer constant expressions whose values are returned by ilogb(x)
  if x is zero or NaN respectively.

  The value of FP_ILOGB0 shall be either INT_MIN or -INT_MAX.

  The value of FP_ILOGBNAN shall be either INT_MAX or INT_MIN.

*/
#define FP_ILOGB0 INT_MIN
#define FP_ILOGBNAN INT_MAX


#define MATH_ERRNO 1
#define MATH_ERREXCEPT 2

#define math_errhandling MATH_ERRNO | MATH_ERREXCEPT

/*

  Can be used to allow or disallow the implementation to contract expressions

*/
#pragma STDC FP_CONTRACT OFF

/*

  Classifies its argument value as Nan, infinite, normal, subnormal, zero or
  another implementation-defined category. First, and argument represented in a
  format wider than its semantic type is converted to its semantic type. Then
  classification is based on the type of the argument

  Returns the value of the number classification macro appropriate to the value
  of its argument

*/
#define fpclassify(x)

/*

  Determines whether its argument has a finite value (zero, subnormal, or normal
  and not infinite or NaN). First, an argument represented in a format wider than
  its semantic type is converted to its semantic type. Then determination is
  based on the type of the argument

  Returns a nonzero value if and only if its argument has a finite value

*/
#define isfinite(x)

/*

  Determines whether its argument value is an infinity (positive or negative).
  First, an argument represented in a format wider than its semantic type is
  converted to its semantic type. Then determination is based on the type of the
  argument.

  Returns a nonzero value if and only if its argument has an infinite value

*/
#define isinf(x)

/*

  Determines whether its argument value is a NaN. First, an argument represented
  in a format wider than its semantic type is converted to its semantic type.
  Then determination is based on the type of the argument.

  Returns a nonzero value if and only if its argument has a NaN value

*/
#define isnan(x)

/*

  Determines whether its argument value is normal (neither zero, subnormal,
  infinite, nor NaN). First, an argument represented in a format wider than its
  semantic type is converted to its semantic type. Then determination is based
  on the type of the argument.

  Returns a nonzero value if and only if its argument has a normal value

*/
#define isnormal(x)

/*

  Determines whether the sign of its argument value is negative

  Returns a nonzero value if and only if the sign of its argument value is
  negative

*/
#define signbit(x)


/*

  Computes the principal value of the arc cosine of x.

  Domain error occurs for arguments not in interval [-1,1]

  Returns arccos x in the interval [0,pi] radians

*/
double acos(double x);
float acosf(float x);
long double acosl(long double x);


/*

  Computes the principal value of the arc sine of x.

  Domain error occurs for arguments not in interval [-1,1]

  Returns arcsin x in the interval [-pi/2,pi/2] radians

*/
double asin(double x);
float asinf(float x);
long double asinl(long double x);


/*

  Computes the principal value of the arc tangent of x

  Returns arctan x in the interval [-pi/2,pi/2] radians

*/

double atan(double x);
float atanf(float x);
long double atanl(long double x);


/*

  Compute the value of the arc tangent of y/x, using the signs of both arguments
  to determine the quadrant of the return value.

  Domain error may occur if both arguments are zero.

  Returns arctan y/x in the interval [-pi.pi] radians

*/
double atan2(double y, double x);
float atan2f(float y, float x);
long double atan2l(long double y, long double x);


/*

  Compute the cosine of x (measured in radians)

  Implementation: We will be using the CORDIC Method:
  https://en.wikipedia.org/wiki/CORDIC
  https://www.allaboutcircuits.com/technical-articles/an-introduction-to-the-cordic-algorithm/

  Returns cos x

*/
double cos(double x);
float cosf(float x);
long double cosl(long double x);


/*

  Compute the sine of x (measured in radians)

  Implementation: We will be using the CORDIC Method:
  https://en.wikipedia.org/wiki/CORDIC
  https://www.allaboutcircuits.com/technical-articles/an-introduction-to-the-cordic-algorithm/

  Returns sin x

*/
double sin(double x);
float sinf(float x);
long double sinl(long double x);


/*

  Compute the tan of x (measured in radians)

  Implementation: We will be using the CORDIC Method:
  https://en.wikipedia.org/wiki/CORDIC
  https://www.allaboutcircuits.com/technical-articles/an-introduction-to-the-cordic-algorithm/

  Returns tan x

*/
double tan(double x);
float tanf(float x);
long double tanl(long double x);


/*

  Compute the (nonnegative) arc hyperbolic cosine of x.

  Domain error occurs for arguments less than 1

  Returns arcosh x in the interval [0,inf]

*/
double acosh(double x);
float acoshf(float x);
long double acoshl(long double x);


/*

  Compute the arc hyperbolic sine of x.

  Returns arsinh x

*/
double asinh(double x);
float asinhf(float x);
long double asinhl(long double x);


/*

  Compute the arc hyperbolic tangent of x.

  Domain error occurs for arguments not in the interval [-1,1]

  Pole error may occur if the argument equals -1 or 1

  Returns artanh x

*/
double atanh(double x);
float atanhf(float x);
long double atanhl(long double x);


/*

  Compute the hyperbolic cosine of x

  Range error occurs if magnitude of x is too large

  Returns cosh x

*/
double cosh(double x);
float coshf(float x);
long double coshl(long double x);


/*

  Computes the hyperbolic sine of x.

  Range error occurs if the magnitude of x is too large.

  Returns sinh x

*/
double sinh(double x);
float sinhf(float x);
long double sinhl(long double x);


/*

  Computes the hyperbolic tangent of x

  Returns tanh x

*/
double tanh(double x);
float tanhf(float x);
long double tanhl(long double x);


/*

  Compute the base-e exponential of x.

  Range error occurs if the magnitude of x is too large

  Returns e^x

*/
double exp(double x);
float expf(float x);
long double(long double x);


/*

  Compute the base-2 exponential of x

  Range error occurs if the magnitude of x is too large

  Returns 2^x

*/
double exp2(double x);
float exp2f(float x);
long double exp2l(long double x);


/*

  Compute the base-e exponential of the argument, minus 1.

  Range error occurs if positive x is too large

  Returns e^x-1

*/
double expm1(double x);
float expm1f(float x);
long double expm1l(long double x);


/*

  Break a floating-point number into a normalized fraction and an integral power
  of 2. They store the integer in the int object pointed to by exp

  If the value is not a floating-point number or if the integral power of 2 is
  outside the range of int, the results are unspecified. Otherwise, the frexp
  functions return the value x, such that x has a magnitude in the interval
  [1/2,1) or zero, and the value equals x * 2^*exp. If value is zero, both parts
  of the result are zero.

*/
double frexp(double value, int *exp);
float frexpf(float value, int *exp);
long double frexpl(long double value, int *exp);


/*

  Extract the exponent of x as a signed int value. If x is zero they compute the
  value FP_ILOGB0; if x is infinite they compute the value INT_MAX; if x is a
  NaN they compute the value FP_ILOGBNAN; otherwise, they are equivalent to
  calling the corresponding logb function and casting the returned value to type
  int.

  Domain error or range error may occur if x is zero, infinite, or NaN. If the
  correct value is outside the range of the return type, the numeric result is
  unspecified and a domain error or range error may occur

  Returns the exponent of x as a signed int value

*/
int ilogb(double x);
int ilogbf(float x);
int ilogbl(long double x);


/*

  Multiplies a floating-point number by an integral power of 2.

  Range error may occur

  Returns x*2^exp

*/
double ldexp(double x, int exp);
float ldexpf(float x, int exp);
long double ldexpl(long double x, int exp);


/*

  Computes the base-e (natural) logarithm of x

  Domain error occurs if the argument is negative.

  Pole error may occur if the argument is zero

  Returns log_e x

*/
double log(double x);
float logf(float x);
long double logl(long double x);


/*

  Computes the base-10 (common) logarithm of x.

  Domain error occurs if the argument is negative

  Pole error may occur if the argument is zero

  Returns log_10 x

*/
double log10(double x);
float log10f(float x);
long double log10l(long double x);


/*

  Compute the base-e (natural) logarithm of 1 plus the argument.

  Domain error occurs if the argument is less than -1.

  Pole error may occur if the argument equals -1

  Returns log_e(1+x)

*/
double log1p(double x);
float log1pf(float x);
long double log1pl(long double x);


/*

  Compute the base-2 logarithm of x.

  Domain error occurs if the argument is less than zero.

  Pole error may occur if the argument is zero

  Returns log_2 x

*/
double log2(double x);
float log2f(float x);
long double log2l(long double x);


/*

  Extract the exponent of x, as a signed integer value in floating-point format.
  If x is subnormal it is treated as though it were normalized; thus, for
  positive finite x,
   1 <= x * FLT_RADIX^(-logb(x)) < FLT_RADIX

  Domain error or pole error may occur if the argument is zero

  Returns the signed exponent of x

*/
double logb(double x);
float logbf(float x);
long double logbl(long double x);


/*

  Breaks the argument value into integral and fractional parts, each of which has
  the same type and sign as the argument. They store the integral part (in
  floating-point format) in the object pointed to by iptr

  Returns the signed fractional part of value

*/
double modf(double value, double *iptr);
float modff(float value, float *iptr);
long double modfl(long double value, long double *iptr);


/*

  Compute x * FLT_RADIX^n efficiently, not normally by computing FLT_RADIX^n
  explicitly.

  Range error may occur

  Returns x * FLT_RADIX^n

*/
double scalbn(double x, int n);
float scalbnf(float x, int n);
long double scalbnl(long double x, int n);
double scalbln(double x, long int n);
float scalblnf(float x, long int n);
long double scalblnl(long double x, long int n);


/*

  Compute the real cube root of x

  Returns x^1/3

*/
double cbrt(double x);
float cbrtf(float x);
long double cbrtl(long double x);


/*

  Compute the absolute value of a floating-point number x

  Returns |x|

*/
double fabs(double x);
float fabsf(float x);
long double fabsl(long double x);


/*

  Compute the square root of the sum of the squares of x and y, without undue
  overflow or underflow.

  Range error may occur

  Returns sqrt(x^2+y^2)

*/
double hypot(double x, double y);
float hypotf(float x, float y);
long double hypotl(long double x, long double y);


/*

  Computes x raised to the power y

  Domain error occurs if x is finite and negative and y is finite and not an
  integer value

  Range error may occur.

  Domain error may occur if x is zero and y is zero.

  Domain error or pole error may occur if x is zero and y is less than zero

  Returns x^y

*/
double pow(double x, double y);
float powf(float x, float y);
long double powl(long double x, long double y);


/*

  Computes the nonnegative square root of x

  Domain error occurs if the argument is less than zero

  Returns sqrt(x)

*/
double sqrt(double x);
float sqrtf(float x);
long double sqrtl(long double x);


/*

  Compute the error function of x

  Returns erf x = (2/sqrt(pi)) * (integrate from 0 to x (e^(-t^2)) with respect to t)

*/
double erf(double x);
float erff(float x);
long double erfl(long double x);


/*

  Compute the complementary error function of x

  Range error occurs if positive x is too large

  Returns erfc x = 1 - erf x = (2/sqrt(pi)) * (integrate from x to infinity (e^(-t^2)) with respect to t)

*/
double erfc(double x);
float erfcf(float x);
long double erfcl(long double x);


/*

  Computes the natural logarithm of the absolute value of gamma of x

  Range error occurs if positive x is too large.

  Pole error may occur if x is a negative integer or zero

  Returns log_e|gamma(x)|

*/
double lgamma(double x);
float lgammaf(float x);
long double lgammal(long double x);


/*

  Computes the gamma function of x.

  Domain error or pole error may occur if x is a negative integer or zero.

  Range error occurs if magnitude of x is too large and may occur if magnitude
  of x is too small

  Returns gamma(x)

*/
double tgamma(double x);
float tgammaf(float x);
long double tgammal(long double x);


/*

  Computes the smallest integer value not less than x

  Returns ceil(x), expressed as a floating-point number

*/
double ceil(double x);
float ceilf(float x);
long double ceill(long double x);


/*

  Computes the largest integer value not greater than x

  Returns floor(x), expressed as a floating-point number

*/
double floor(double x);
float floorf(float x);
long double floorl(long double x);


/*

  Rounds x to an integer value in floating-point format, using the current
  rounding direction and without raising the "inexact" floating-point exception

  Returns the rounded integer value

*/
double nearbyint(double x);
float nearbyintf(float x);
long double nearbyintl(long double x);


/*

  Same as nearbyint, but also raises "inexact" exception if result differs from
  argument

  Returns the rounded integer value

*/
double rint(double x);
float rintf(float x);
long double rintl(long double x);


/*

  Rounds x to nearest integer value, rounding according to the current rounding
  direction. If the rounded value is outside the range of the return type,
  result is unspecified and a domain error or range error may occur

  Returns the rounded integer value

*/
long int lrint(double x);
long int lrintf(float x);
long int lrintl(long double x);
long long int llrint(double x);
long long int llrintf(float x);
long long int llrintl(long double x);


/*

  Rounds x to the nearest integer value in floating-point format, rounding
  halfway cases away from zero, regardless of current rounding direction

  Returns the rounded integer value

*/
double round(double x);
float roundf(float x);
long double roundl(long double x);


/*

  Rounds x to the nearest integer value, rounding halfway cases away from zero,
  regardless of the current rounding direction. If the rounded value is outside
  the range of the return type, the numeric result is unspecified and a domain
  error or range error may occur

  Returns the rounded integer value

*/
long int lround(double x);
long int lroundf(float x);
long int lroundl(long double x);
long long int llround(double x);
long long int llroundf(float x);
long long int llroundl(long double x);


/*

  Rounds x to the integer value, in floating format, nearest to but no larger
  in magnitude than the argument

  Returns the truncated integer value

*/
double trunc(double x);
float truncf(float x);
long double truncl(long double x);


/*

  Computes the floating-point remainder of x/y

  Returns the value x-ny for some integer n such that, if y is nonzero, the
  result has the same sign as x and magnitude less than the magnitude of y. If
  y is zero, whether a domain error occurs or the fmod functions return zero is
  is implementation-defined

*/
double fmod(double x, double y);
float fmodf(float x, float y);
long double fmodl(long double x, long double y);


/*

  Computes the remainder x REM y required by IEC 60559

  Returns x REM y. If y is zero, whether a domain error occurs or the functions
  return zero is implementation defined

*/
double remainder(double x, double y);
float remainderf(float x, float y);
long double remainderl(long double x, long double y);


/*

  Computes the same remainder as the remainder functions. In the object pointed
  to by quo they store a value whose sign is the sign of x/y and whose magnitude
  is congruent modulo 2^n to the magnitude of the integral quotient of x/y,
  where n is an implementation-defined integer greater than or equal to 3

  Returns x REM y. If y is zero, the value stored in the object pointed to by
  quo is unspecified and whether a domain error occurs or the functions return
  zero is implementation defined

*/
double remquo(double x, double y, int *quo);
float remquof(float x, float y, int *quo);
long double remquol(long double x, long double y, int *quo);


/*

  Produces a value with the magnitude of x and sign of y. Produces a NaN with
  sign of y if x is NaN. Implementations that represent a signed zero but to not
  treat negative zero consistantly in arithmetic operations, the copysign
  functions regard the sign of zero as positive

  Returns a value with the magnitude of x and the sign of y

*/
double copysign(double x, double y);
float copysignf(float x, float y);
long double copysignl(long double x, long double y);


/*

  Converts the string pointed to by tagp according to the following rules.

  nan("n-char-sequence") == strtod("NAN(n-char-sequence)",(char**)NULL)
  nan("") == strtod("NAN()",(char**)NULL)

  If tagp does not point to an n-char sequence or an empty string, the call
  is equivalent to strtod("NAN",(char**)NULL)

  Calls to nanf and nanl are equivalent to the corresponding calls to strtof
  and strtold

  Returns a quiet NaN, if available, with content indicated through tagp. If
  the implementation does not support quiet NaNs, the functions return zero

*/
double nan(const char *tagp);
float nanf(const char *tagp);
long double nanl(const char *tagp);


/*

  Determines the next representable value, in the type of the function, after x
  in the direction of y, where x and y are first converted to the type of the
  function. The nextafter functions return y if x equals y.

  Range error may occur if the magnitude of x is the largest finite value
  representable in the type and the result is infinite or not representable in
  the type

  Returns the next representable value in the specified format after x in the
  direction of y.

*/
double nextafter(double x, double y);
float nextafterf(float x, float y);
long double nextafterl(long double x, long double y);


/*

  Equal to nextafter functions except that functions return y converted to type
  of the function if x equals y

*/
double nexttoward(double x, long double y);
float nexttowardf(float x, long double y);
long double nexttowardl(long double x, long double y);


/*

  Determines positive difference between arguments

  Range error may occur

  Returns x-y if x > y
  Returns 0 if x <= y

*/
double fdim(double x, double y);
float fdimf(float x, float y);
long double fdiml(long double x, long double y);


/*

  Determines the maximum numeric value of their arguments

  Returns the maximum numeric value of their arguments

*/
double fmax(double x, double y);
float fmaxf(float x, float y);
long double fmaxl(long double x, long double y);


/*

  Determines the minimum numeric value of their arguments

  Returns the minimum numeric value of their arguments

*/
double fmin(double x, double y);
float fminf(float x, float y);
long double fminl(long double x, long double y);


/*

  Computes (x*y)+z, rounded as one ternary operation: they compute the value
  (as if) to infinite precision and round once to the result format, according
  to the current rounding mode

  Range error may occur

  Returns (x*y)+z rounded as one ternary operation

*/
double fma(double x, double y, double z);
float fmaf(float x, float y, float z);
long double fmal(long double x, long double y, long double z);


/*

  Determines whether its first argument is greater than its second argument
  The value of isgreater(x,y) is always equal to x>y however, unlike x>y,
  isgreater(x,y) does not raise the "invalid" floating-point exception when x
  and y are unordered

  Returns the value of x > y

*/
#define isgreater(x, y);


/*

  Determines whether its first argument is greater than or equal to its second
  argument. isgreaterequal(x,y) does not raise the "invalid" floating-point
  exception when x and y are unordered

  Returns the value of x >= y

*/
#define isgreaterequal(x,y);


/*

  Determines whether its first argument is less than its second argument.
  isless(x,y) does not raise the "invalid" floating-point exception when x and y
  are unordered

  Returns the value of x < y

*/
#define isless(x,y);


/*

  Determines whether its first argument is less than or equal to its second
  argument. islessequal does not raise the "invalid" floating-point exception
  when x and y are unordered

  Returns x <= y

*/
#define islessequal(x,y);


/*

  Determines whether its first argument is less than or equal to its second
  argument. islessgreater(x,y) does not raise the "invalid" floating-point
  exception when x and y are unordered (nor does it evaluate x and y twice)

  Returns the value of x<y || x>y

*/
#define islessgreater(x,y);


/*

  Determines whether its arguments are unordered

  Returns 1 if its arguments are unordered and 0 otherwise

*/
#define isunordered(x,y);
