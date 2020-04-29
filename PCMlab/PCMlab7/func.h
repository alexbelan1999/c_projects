#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
double f1(double x)
{
	return 1 / (pow(x, 2) + 1);
}
double f2(double x, double y, double z)
{
	return z;

}
double f3(double x, double y, double z)
{
	return (-3 / pow((x*x + 1), 2)) - 4 * x*z / (x*x + 1) + y / (x*x + 1);
}
double f4(double x, double y, double z)
{
	return -4 * x*z / (x*x + 1) + y / (x*x + 1);

}
double f5(double x, double y, double z)
{
	return -4 * x*z / (x*x + 1) + y / (x*x + 1);

}