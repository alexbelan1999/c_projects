#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
double h = 0.1;

double f1(double x)
{
	return 1 / (pow(x, 2) + 1);
}
double arg1(double x)
{
	return 1 / (h *h) + 4 * x / ((x*x + 1) * (2 * h));
}
double arg2(double x)
{
	return -2 / (h *h) - 1 / (x*x + 1);
}
double arg3(double x)
{
	return 1 / (h *h) - (4 * x) / ((x*x + 1) *(2 * h));
}
double fx(double x)
{
	return -3 / (pow((x*x + 1), 2));
}