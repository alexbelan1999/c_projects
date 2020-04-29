#define _USE_MATH_DEFINES
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <vector>
#include <iomanip>
#include "func.h"
using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double start = 0;
	double end = 1;
	double h = 0.1;
	int index = 0;

	double alfa1 = 0;
	double alfa2 = 1;
	double gamma1 = 0;
	double gamma2 = 0.5;
	double beta1 = 1;
	double beta2 = 0;
	cout << "Метод редукции." << endl;
	for (double i = start; i <= end; i = i + h)
	{
		index++;

	}
	int index1 = index;
	vector<double> vectorx(index);
	vector<double> vectory(index);

	vector<double> vectorf(index);
	vector<double> error(index);
	index = 0;
	for (double i = start; i <= end; i = i + h)
	{
		vectorx[index] = i;
		vectory[index] = f1(i);
		index++;
	}
	for (int n = 0; n < index; n++)
	{
		cout << setw(8) << vectorx[n] << "  " << setw(8) << vectory[n] << endl;
	}

	vector<double> vectorl1(index);
	vector<double> vectorl2(index);
	vector<double> vectorl3(index);
	vector<double> vectorl4(index);
	vector<double> vectork1(index);
	vector<double> vectork2(index);
	vector<double> vectork3(index);
	vector<double> vectork4(index);

	vector<double> vectoryi(index);
	vector<double> vectorz(index);

	vectoryi[0] = 0;
	vectorz[0] = 0;

	cout << endl;

	for (index = 0; index < index1; index++)
	{
		vectork1[index] = f2(vectorx[index], vectoryi[index], vectorz[index]);
		vectorl1[index] = f3(vectorx[index], vectoryi[index], vectorz[index]);

		vectork2[index] = f2(vectorx[index] + h / 2, vectoryi[index] + (h / 2)*vectork1[index], vectorz[index] + (h*vectorl1[index]) / 2);
		vectorl2[index] = f3(vectorx[index] + h / 2, vectoryi[index] + (h / 2)*vectork1[index], vectorz[index] + (h*vectorl1[index]) / 2);

		vectork3[index] = f2(vectorx[index] + h / 2, vectoryi[index] + (h / 2)*vectork2[index], vectorz[index] + (h*vectorl2[index]) / 2);
		vectorl3[index] = f3(vectorx[index] + h / 2, vectoryi[index] + (h / 2)*vectork2[index], vectorz[index] + (h*vectorl2[index]) / 2);

		vectork4[index] = f2(vectorx[index] + h, vectoryi[index] + h * vectork3[index], vectorz[index] + h * vectorl3[index]);
		vectorl4[index] = f3(vectorx[index] + h, vectoryi[index] + h * vectork3[index], vectorz[index] + h * vectorl3[index]);

		error[index] = abs(vectory[index] - vectoryi[index]);

		if (index == index1 - 1)
		{
			break;
		}

		vectoryi[index + 1] = vectoryi[index] + (h*(vectork1[index] + 2 * vectork2[index] + 2 * vectork3[index] + vectork4[index])) / 6;
		vectorz[index + 1] = vectorz[index] + (h*(vectorl1[index] + 2 * vectorl2[index] + 2 * vectorl3[index] + vectorl4[index])) / 6;

	}
	cout << "1 задача Коши" << endl;
	for (int n = 0; n <= index; n++)
	{
		cout << setw(9) << vectorx[n] << " " << setw(9) << vectoryi[n] << "   " << setw(9) << vectorz[n] << endl;

	}

	double y0b = vectoryi[index];
	double s0b = vectorz[index];

	cout << endl;
	vector<double> vectoryi2(index1);
	vector<double> vectorz2(index1);
	vectoryi2[0] = 1;
	vectorz2[0] = 0;
	for (index = 0; index < index1; index++)
	{
		vectork1[index] = f2(vectorx[index], vectoryi2[index], vectorz2[index]);
		vectorl1[index] = f4(vectorx[index], vectoryi2[index], vectorz2[index]);

		vectork2[index] = f2(vectorx[index] + h / 2, vectoryi2[index] + (h / 2)*vectork1[index], vectorz2[index] + (h*vectorl1[index]) / 2);
		vectorl2[index] = f4(vectorx[index] + h / 2, vectoryi2[index] + (h / 2)*vectork1[index], vectorz2[index] + (h*vectorl1[index]) / 2);

		vectork3[index] = f2(vectorx[index] + h / 2, vectoryi2[index] + (h / 2)*vectork2[index], vectorz2[index] + (h*vectorl2[index]) / 2);
		vectorl3[index] = f4(vectorx[index] + h / 2, vectoryi2[index] + (h / 2)*vectork2[index], vectorz2[index] + (h*vectorl2[index]) / 2);
		vectork4[index] = f2(vectorx[index] + h, vectoryi2[index] + h * vectork3[index], vectorz2[index] + h * vectorl3[index]);
		vectorl4[index] = f4(vectorx[index] + h, vectoryi2[index] + h * vectork3[index], vectorz2[index] + h * vectorl3[index]);

		error[index] = abs(vectory[index] - vectoryi2[index]);

		if (index == index1 - 1)
		{
			break;
		}

		vectoryi2[index + 1] = vectoryi2[index] + (h*(vectork1[index] + 2 * vectork2[index] + 2 * vectork3[index] + vectork4[index])) / 6;
		vectorz2[index + 1] = vectorz2[index] + (h*(vectorl1[index] + 2 * vectorl2[index] + 2 * vectorl3[index] + vectorl4[index])) / 6;

	}

	cout << "2 задача Коши" << endl;
	for (int n = 0; n <= index; n++)
	{
		cout << setw(9) << vectorx[n] << " " << setw(9) << vectoryi2[n] << "   " << setw(9) << vectorz2[n] << endl;

	}


	double y1b = vectoryi2[index];
	double s1b = vectorz2[index];
	cout << endl;

	vector<double> vectoryi3(index1);
	vector<double> vectorz3(index1);
	vectoryi3[0] = 0;
	vectorz3[0] = 1;
	for (index = 0; index < index1; index++)
	{
		vectork1[index] = f2(vectorx[index], vectoryi3[index], vectorz3[index]);
		vectorl1[index] = f5(vectorx[index], vectoryi3[index], vectorz3[index]);

		vectork2[index] = f2(vectorx[index] + h / 2, vectoryi3[index] + (h / 2)*vectork1[index], vectorz3[index] + (h*vectorl1[index]) / 2);
		vectorl2[index] = f5(vectorx[index] + h / 2, vectoryi3[index] + (h / 2)*vectork1[index], vectorz3[index] + (h*vectorl1[index]) / 2);

		vectork3[index] = f2(vectorx[index] + h / 2, vectoryi3[index] + (h / 2)*vectork2[index], vectorz3[index] + (h*vectorl2[index]) / 2);
		vectorl3[index] = f5(vectorx[index] + h / 2, vectoryi3[index] + (h / 2)*vectork2[index], vectorz3[index] + (h*vectorl2[index]) / 2);

		vectork4[index] = f2(vectorx[index] + h, vectoryi3[index] + h * vectork3[index], vectorz3[index] + h * vectorl3[index]);
		vectorl4[index] = f5(vectorx[index] + h, vectoryi3[index] + h * vectork3[index], vectorz3[index] + h * vectorl3[index]);
		error[index] = abs(vectory[index] - vectoryi3[index]);

		if (index == index1 - 1)
		{
			break;
		}

		vectoryi3[index + 1] = vectoryi3[index] + (h*(vectork1[index] + 2 * vectork2[index] + 2 * vectork3[index] + vectork4[index])) / 6;
		vectorz3[index + 1] = vectorz3[index] + (h*(vectorl1[index] + 2 * vectorl2[index] + 2 * vectorl3[index] + vectorl4[index])) / 6;

	}
	cout << "3 задача Коши" << endl;
	for (int n = 0; n <= index; n++)
	{
		cout << setw(9) << vectorx[n] << " " << setw(9) << vectoryi3[n] << "   " << setw(9) << vectorz3[n] << endl;

	}


	cout << endl;

	double y2b = vectoryi3[index];
	double s2b = vectorz3[index];
	double c1 = 0;
	double c2 = 0;

	if (alfa1 == 0) {
		c2 = gamma1 / beta1;
		c1 = (gamma2 - alfa2 * y0b - alfa2 * c2*y2b - beta2 * s1b - c2 * beta2*s2b) / (alfa2*y1b + beta2 * s1b);
	}
	if (alfa1 != 0) {
		c2 = (gamma2*alfa1 - alfa2 * alfa1*y0b - alfa2 * gamma1*y1b - alfa1 * beta2 * s0b - gamma1 * beta2*s1b) / (alfa1*alfa2*y2b - alfa2 * beta1*y1b - beta1 * beta2*s1b + alfa1 * s2b * beta2);
		c1 = (gamma1 - c2 * beta1) / alfa1;
	}
	cout << endl;
	cout << " c1=  " << c1 << endl;
	cout << " c2=  " << c2 << endl;


	cout << " Общее решение диф.уравнения: y(x) = Y0(x)+ " << c1 << " * Y1(x) + " << c2 << " * Y2(x)." << endl;
	vector<double> vectorresult(index1);
	cout << setw(9) << "x: " << setw(9) << "y: " << setw(9) << "Погрешность: " << endl;
	for (int n = 0; n <= index; n++)
	{
		vectorresult[n] = vectoryi[n] + c1 * vectoryi2[n] + c2 * vectoryi3[n];
		cout << setw(9) << vectorx[n] << " " << setw(9) << vectorresult[n] << "   " << setw(9) << abs(vectory[n] - vectorresult[n]) << endl;

	}
	system("pause");
	return 0;
}