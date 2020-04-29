#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

double f1(double x)
{
	return (3 * pow(M_E, -2 * x)) / 4 + pow(x, 2) / 2 - x / 2 + pow(4, -1);
}

double f2(double x, double y)
{
	return pow(x, 2) - 2 * y;
}

double f3(double x)
{
	return x *x*x + 3 * x + 1;

}

double f4(double x, double y, double z)
{
	return z;

}

double f5(double x, double y, double z)
{
	return (2 * x*z) / (x*x + 1);

}

double f6(double x)
{
	return -(pow(M_E, x) / (-1 + pow(M_E, x)*x));

}

double f7(double x, double y)
{
	return y + (1 + x)*y*y;

}
