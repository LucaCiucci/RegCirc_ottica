#include <stdio.h>
#include <math.h>



double regcirc(int n, double xx[], double yy[], double* xc, double* yc);


#define N 5
int main(int arcg, char* argv)
{
	double xx[N] = {-1, 0, 1, 0, 0};
	double yy[N] = {0, 1, 0, -1, 0};

	double xc, yc, r;
	r = regcirc(N, xx, yy, &xc, &yc);
	printf_s("xc = %f, yc = %f, r = %f", xc, yc, r);




	return 0;
}




double regcirc(int n, double* xx, double* yy, double* xc, double* yc)
{
	double xmed = 0, ymed = 0;

	for (int i = 0; i < n; i++)
	{
		xmed += xx[i];
		ymed += yy[i];
	}
	xmed /= n;
	ymed /= n;

	for (int i = 0; i < n; i++)
	{
		xx[i] -= xmed;
		yy[i] -= ymed;
	}


	
	double Suu = 0, Svv = 0, Suv = 0, Suuu = 0, Svvv = 0, Suuv = 0, Suvv = 0, uc, vc, R;
	for (int i = 0; i < n; i++) {
		Suu = Suu + xx[i] * xx[i];
		Svv = Svv + yy[i] * yy[i];
		Suv = Suv + xx[i] * yy[i];
		Suuu = Suuu + xx[i] * xx[i] * xx[i];
		Svvv = Svvv + yy[i] * yy[i] * yy[i];
		Suuv = Suuv + xx[i] * xx[i] * yy[i];
		Suvv = Suvv + xx[i] * yy[i] * yy[i];
	}
	uc = (Svv * (Suuu + Suvv) - Suv * (Svvv + Suuv)) / (2 * (Suu * Svv - Suv * Suv));
	vc = (Suv * (Suuu + Suvv) - Suu * (Svvv + Suuv)) / (2 * (Suv * Suv - Suu * Svv));
	R = sqrt(uc * uc + vc * vc + (Suu + Svv) / n);
	*xc = uc + xmed;
	*yc = vc + ymed;
	return R;
}