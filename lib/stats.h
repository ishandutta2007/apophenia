#include <math.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_multimin.h>
#include <gsl/gsl_statistics_double.h>
#include "linear_algebra.h"


	//The following are just convenient hooks to gsl vector functions.
	//var_m lets you input a mean if you've already calculated it, saving
	//some repetition.
inline double mean(gsl_vector *in);
inline double var(gsl_vector *in);
inline double var_m(gsl_vector *in, double mean);
inline double covar(gsl_vector *ina, gsl_vector *inb);
inline double cov(gsl_vector *ina, gsl_vector *inb);


void normalize_vector(gsl_vector *in, gsl_vector **out);
	//Give me a vector of input data of any old mean and variance,
	//and I'll put in your output vector's address a vector with 
	//mean zero and variance one.
	//Uses sample variance (stuff/N-1, not stuff/N).
	//call: 
	//	gsl_vector, *unnormed, *normed;
	//	normalize_vector(unnormed, &normed)

void normalize_data_matrix(gsl_matrix *data);
	//Move every column of the data matrix to the mean; often required for regressions.

inline double test_chi_squared_var_not_zero(gsl_vector *in);
	//As described: give it a vector, and it'll tell you the confidence 
	//with which you can say that the vector is not zero.

inline double double_abs(double a);
	//This has to exist somewhere...




double randombeta(double m, double v, gsl_rng *r) ;
	/*Give me mean m and variance v, and I'll give you
	 * n draws from the appropriate beta dist.
	 * remember: 0<m<1, and v is tiny (<<1/12). You get NaNs if no
	 * appropriate distribution exists.*/


double multivariate_normal_prob(gsl_vector *x, gsl_vector* mu, gsl_matrix* sigma, int first_use);
	//Evaluate a multivariate normal(mu, sigma) at the point x.
//The equation:
//	exp(-1/2 (X-mu)' sigma^-1 (x-mu))
//	--------------------------
//	sqrt((2 Pi)^n det(sigma))
//
//The inverse and determinant are expensive, so keep them around where possible: on the first call, set 
//first_use to 1, then feed in as many new values of X as you want.
