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
	double step = 0.1;
	int index = 0;
	for (double i = start; i <= end; i = i + step)
	{
		index++;
		
	}

	vector<double> vectorx(index);
	vector<double> vectory(index);
	vector<double> vectoryi(index);
	vector<double> vectorf(index);
	vector<double> error(index);
	vector<double> vectorfpoint(index);
	vector<double> vectorftrap(index);
	vector<double> vectork1(index);
	vector<double> vectork2(index);
	vector<double> vectork3(index);
	vector<double> vectork4(index);
	vector<double> vectorl1(index);
	vector<double> vectorl2(index);
	vector<double> vectorl3(index);
	vector<double> vectorl4(index);
	vector<double> vectorz(index);

	index = 0;
	cout << "Задание 1" << endl;
	for (double i = start; i <= end; i = i + step)
	{
		vectorx[index] = i;
		vectory[index] = f1(i);
		index++;
	}

	cout << setw(9) << " x" << setw(9) << " f(x)" << endl;
	for (int n = 0; n < index; n++)
	{
		cout << setw(9) << vectorx[n] << " " << setw(9) << vectory[n] << endl;

	}
	

	vectoryi[0] = 1;
	vectorf[0] = f2(vectorx[0], vectoryi[0]);
	cout << endl;


	index = 1;


	cout << "Метод Эйлера" << endl;
	for (index; index < (int)(vectorx.size()); index++)
	{
		vectoryi[index] = vectoryi[index - 1] + step * vectorf[index - 1];
		vectorf[index] = f2(vectorx[index], vectoryi[index]);
		error[index - 1] = abs(vectory[index - 1] - vectoryi[index - 1]);
	}

	cout << " x[i]" << setw(9) << " y[i]" << setw(9) << " f(x[i],y[i])" << setw(9) << " y[i+1] " << setw(10) << " точное значение " << setw(10) << " погрешность" << endl;
	for (int i = 0; i < (int)(vectorx.size()); i++)
	{
		if (i == vectorx.size()-1) {
			cout << vectorx[i] << "   " << setw(10) << vectoryi[i] << "   " << setw(10) << vectorf[i] << "   " << setw(10) << " ------  " << setw(10) << vectory[i] << "   " << setw(10) << error[i] << endl;
			break;
		}
		cout << vectorx[i] << "   " << setw(9) << vectoryi[i] << "   " << setw(9) << vectorf[i] << "   " << setw(9) << vectoryi[i + 1] << "   " << setw(9) << vectory[i] << "   " << setw(9) << error[i] << endl;
		
	}
	cout << endl;
	cout << "Метод средней точки" << endl;
	index = 1;
	
	vectorfpoint[0] = f2(vectorx[0] + step / 2, vectoryi[0] + (step*vectorf[0]) / 2);
	for (index; index < (int)(vectorx.size()); index++)
	{
	
		vectoryi[index] = vectoryi[index - 1] + step * vectorfpoint[index - 1];
		vectorf[index] = f2(vectorx[index], vectoryi[index]);
		vectorfpoint[index] = f2(vectorx[index] + step / 2, vectoryi[index] + (step*vectorf[index]) / 2);
		error[index - 1] = abs(vectory[index - 1] - vectoryi[index - 1]);
	}
	cout << " x[i]" << setw(9) << " y[i]" << setw(9) << " f(x[i],y[i])" << setw(9) << " f(...)" << setw(9) << "    y[i+1] " << setw(10) << " точное значение " << setw(10) << " погрешность" << endl;
	for (int i = 0; i < (int)(vectorx.size()); i++)
	{
		if (i == vectorx.size() - 1) {
			cout << vectorx[i] << "   " << setw(10) << vectoryi[i] << "   " << setw(10) << vectorf[i] << "   " << setw(10) << vectorfpoint[i] << "   " << setw(10) << " ------  " << setw(10) << vectory[i] << "   " << setw(10) << error[i] << endl;
			break;
		}
		cout << vectorx[i] << "   " << setw(9) << vectoryi[i] << "   " << setw(9) << vectorf[i] << "   " << setw(9) << vectorfpoint[i] << "   " << setw(9) << vectoryi[i + 1] << "   " << setw(9) << vectory[i] << "   " << setw(9) << error[i] << endl;

	}
	cout << endl;
	cout << "Метод трапеций" << endl;
	index = 1;

	vectorftrap[0] = f2(vectorx[1], vectoryi[0] + step * vectorf[0]);
	for (index; index < (int)(vectorx.size()); index++)
	{
		vectoryi[index] = vectoryi[index - 1] + step * (vectorf[index - 1] + vectorftrap[index - 1]) / 2;
		vectorf[index] = f2(vectorx[index], vectoryi[index]);
		if (index == vectorx.size()-1)
		{
			break;
		}
		vectorftrap[index] = f2(vectorx[index + 1], vectoryi[index] + step * vectorf[index]);
		error[index - 1] = abs(vectory[index - 1] - vectoryi[index - 1]);
	}
	
	cout << " x[i]" << setw(9) << " y[i]" << setw(9) << " f(x[i],y[i])" << setw(9) << " f(...)" << setw(9) << "    y[i+1] " << setw(10) << " точное значение " << setw(10) << " погрешность" << endl;
	for (int i = 0; i < (int)(vectorx.size()); i++)
	{
		if (i == vectorx.size() - 1) {
			cout << vectorx[i] << "   " << setw(10) << vectoryi[i] << "   " << setw(10) << vectorf[i] << "   " << setw(10) << vectorftrap[i] << "   " << setw(10) << " ------  " << setw(10) << vectory[i] << "   " << setw(10) << error[i] << endl;
			break;
		}
		cout << vectorx[i] << "   " << setw(9) << vectoryi[i] << "   " << setw(9) << vectorf[i] << "   " << setw(9) << vectorftrap[i] << "   " << setw(9) << vectoryi[i + 1] << "   " << setw(9) << vectory[i] << "   " << setw(9) << error[i] << endl;

	}
	cout << endl;
	cout << "Метод Рунге-Кутты" << endl;

	vectoryi[0] = 1;
	for (index = 0; index < (int)(vectorx.size()); index++)
	{	
		
		vectork1[index] = f2(vectorx[index], vectoryi[index]);
		vectork2[index] = f2(vectorx[index] + step / 2, vectoryi[index] + (step*vectork1[index]) / 2);
		vectork3[index] = f2(vectorx[index] + step / 2, vectoryi[index] + (step*vectork2[index]) / 2);
		vectork4[index] = f2(vectorx[index] + step, vectoryi[index] + step * vectork3[index]);
		error[index] = abs(vectory[index] - vectoryi[index]);
		if (index == vectorx.size() - 1)
		{
			break;
		}
		vectoryi[index + 1] = vectoryi[index] + (step * (vectork1[index] + 2 * vectork2[index] + 2 * vectork3[index] + vectork4[index])) / 6;
		
	}

	cout << " x[i]" << setw(11) << " y[i]" << setw(11) << " k1" << setw(11) << " k2" << setw(11) << "  k3 " << setw(11) << " k4 " << setw(11) << " y[i+1]" << setw(11) << " точное значение " << setw(11) << " погрешность" << endl;
	for (int i = 0; i < (int)(vectorx.size()); i++)
	{
		if (i == vectorx.size() - 1) {
			cout << vectorx[i] << "   " << setw(9) << vectoryi[i] << "   " << setw(9) << vectork1[i] << "   " << setw(9) << vectork2[i] << "   " << setw(9) << vectork3[i] << "   " << setw(9) << vectork4[i] << "   " << setw(10) << " ------  " << "   " << setw(9) << vectory[i] << "   " << setw(9) << error[i] << endl;
			break;
		}
		cout << vectorx[i] << "   " << setw(9) << vectoryi[i] << "   " << setw(9) << vectork1[i] << "   " << setw(9) << vectork2[i] << "   " << setw(9) << vectork3[i] << "   " << setw(9) << vectork4[i] << "   " << setw(9) << vectoryi[i + 1] << "   " << setw(9) << vectory[i] << "   " << setw(9) << error[i] << endl;

	}
	cout << endl;
	
	cout << "Метод Рунге-Кутты 2" << endl;

	start = 0;
	end = 1;
	step = 0.2;
	double h = 0.2;
	index = 0;

	for (double i = start; i <= end; i = i + step)
	{
		index++;

	}
	int index1 = index;
	index = 0;
	for (double i = start; i <= end; i = i + step)
	{
		vectorx[index] = i;
		vectory[index] = f3(i);
		index++;
	}

	cout << setw(9) << " x" << setw(9) << " f(x)" << endl;
	for (int n = 0; n < index; n++)
	{
		cout << setw(9) << vectorx[n] << " " << setw(9) << vectory[n] << endl;

	}

	vectoryi[0] = 1;
	vectorz[0] = 3;

	cout << endl;

	index = 0;
	for (index = 0; index <index1; index++)
	{
		vectork1[index] = f4(vectorx[index], vectoryi[index], vectorz[index]);
		vectorl1[index] = f5(vectorx[index], vectoryi[index], vectorz[index]);

		vectork2[index] = f4(vectorx[index] + h / 2, vectoryi[index] + (h / 2)*vectork1[index], vectorz[index] + (h*vectorl1[index]) / 2);
		vectorl2[index] = f5(vectorx[index] + h / 2, vectoryi[index] + (h / 2)*vectork1[index], vectorz[index] + (h*vectorl1[index]) / 2);

		vectork3[index] = f4(vectorx[index] + h / 2, vectoryi[index] + (h / 2)*vectork2[index], vectorz[index] + (h*vectorl2[index]) / 2);
		vectorl3[index] = f5(vectorx[index] + h / 2, vectoryi[index] + (h / 2)*vectork2[index], vectorz[index] + (h*vectorl2[index]) / 2);

		vectork4[index] = f4(vectorx[index] + h, vectoryi[index] + h * vectork3[index], vectorz[index] + h * vectorl3[index]);
		vectorl4[index] = f5(vectorx[index] + h, vectoryi[index] + h * vectork3[index], vectorz[index] + h * vectorl3[index]);

		error[index] = abs(vectory[index] - vectoryi[index]);

		if (index == vectorx.size() - 1)
		{
			break;
		}

		vectoryi[index + 1] = vectoryi[index] + (step*(vectork1[index] + 2 * vectork2[index] + 2 * vectork3[index] + vectork4[index])) / 6;
		vectorz[index + 1] = vectorz[index] + (step*(vectorl1[index] + 2 * vectorl2[index] + 2 * vectorl3[index] + vectorl4[index])) / 6;
		
	}


	cout << " x[i]" << setw(11) << " y[i]" << setw(11) << " z[i]" << setw(11) << " k1" << setw(11) << " l1" << setw(11) << " k2" << setw(11) << " l2" << setw(11) << "  k3 " << setw(11) << " l3" << setw(11) << " k4 " << setw(11) << " l4" << setw(11) << " y[i+1]" << setw(11) << " z[i+1]" << setw(11) << " точное значение " << setw(11) << " погрешность" << endl;
	for (int i = 0; i <index1; i++)
	{
		if (i == index1 - 1) {
			cout << vectorx[i] << "   " << setw(9) << vectoryi[i] << "   " << setw(9) << vectorz[i] << "   " << setw(9) << vectork1[i] << "   " << setw(9) << vectorl1[i] << "   " << setw(9) << vectork2[i] << "   " << setw(9) << vectorl2[i] << "   " << setw(9) << vectork3[i] << "   " << setw(9) << vectorl3[i] << "   " << setw(9) << vectork4[i] << "   " << setw(9) << vectorl4[i] << "   " << setw(10) << " ------  " << "   " << setw(10) << " ------  " << "   " << setw(9) << vectory[i] << "   " << setw(9) << error[i] << endl;
			break;
		}
		cout << vectorx[i] << "   " << setw(9) << vectoryi[i] << "   " << setw(9) << vectorz[i] << "   " << setw(9) << vectork1[i] << "   " << setw(9) << vectorl1[i] << "   " << setw(9) << vectork2[i] << "   " << setw(9) << vectorl2[i] << "   " << setw(9) << vectork3[i] << "   " << setw(9) << vectorl3[i] << "   " << setw(9) << vectork4[i] << "   " << setw(9) << vectorl4[i] << "   " << setw(9) << vectoryi[i + 1] << "   " << setw(9) << vectorz[i + 1] << "   " << setw(9) << vectory[i] << "   " << setw(9) << error[i] << endl;

	}
	cout << endl;
	cout << "Задание 2" << endl;
	start = 0;
	end = 0.5;
	step = 0.1;
	index = 0;
	for (double i = start; i <= end; i = i + step)
	{
		index++;

	}
	int index2 = index;
	index = 0;
	for (double i = start; i <= end; i = i + step)
	{
		vectorx[index] = i;
		vectory[index] = f6(i);
		index++;
	}

	cout << setw(9) << " x" << setw(9) << " f(x)" << endl;
	for (int n = 0; n < index2; n++)
	{
		cout << setw(9) << vectorx[n] << " " << setw(9) << vectory[n] << endl;

	}


	vectoryi[0] = 1;
	vectorf[0] = f7(vectorx[0], vectoryi[0]);
	cout << endl;


	index = 1;


	cout << "Метод Эйлера" << endl;
	for (index; index < index2; index++)
	{
		vectoryi[index] = vectoryi[index - 1] + step * vectorf[index - 1];
		vectorf[index] = f7(vectorx[index], vectoryi[index]);
		error[index - 1] = abs(vectory[index - 1] - vectoryi[index - 1]);
	}

	cout << " x[i]" << setw(9) << " y[i]" << setw(9) << " f(x[i],y[i])" << setw(9) << " y[i+1] " << setw(10) << " точное значение " << setw(10) << " погрешность" << endl;
	for (int i = 0; i < index2; i++)
	{
		if (i == index2 - 1) {
			cout << vectorx[i] << "   " << setw(10) << vectoryi[i] << "   " << setw(10) << vectorf[i] << "   " << setw(10) << " ------  " << setw(10) << vectory[i] << "   " << setw(10) << error[i] << endl;
			break;
		}
		cout << vectorx[i] << "   " << setw(9) << vectoryi[i] << "   " << setw(9) << vectorf[i] << "   " << setw(9) << vectoryi[i + 1] << "   " << setw(9) << vectory[i] << "   " << setw(9) << error[i] << endl;

	}
	cout << endl;
	cout << "Метод средней точки" << endl;
	index = 1;

	vectorfpoint[0] = f7(vectorx[0] + step / 2, vectoryi[0] + (step*vectorf[0]) / 2);
	for (index; index < index2; index++)
	{

		vectoryi[index] = vectoryi[index - 1] + step * vectorfpoint[index - 1];
		vectorf[index] = f7(vectorx[index], vectoryi[index]);
		vectorfpoint[index] = f7(vectorx[index] + step / 2, vectoryi[index] + (step*vectorf[index]) / 2);
		error[index - 1] = abs(vectory[index - 1] - vectoryi[index - 1]);
	}
	cout << " x[i]" << setw(9) << " y[i]" << setw(9) << " f(x[i],y[i])" << setw(9) << " f(...)" << setw(9) << "    y[i+1] " << setw(10) << " точное значение " << setw(10) << " погрешность" << endl;
	for (int i = 0; i < index2; i++)
	{
		if (i == index2 - 1) {
			cout << vectorx[i] << "   " << setw(10) << vectoryi[i] << "   " << setw(10) << vectorf[i] << "   " << setw(10) << vectorfpoint[i] << "   " << setw(10) << " ------  " << setw(10) << vectory[i] << "   " << setw(10) << error[i] << endl;
			break;
		}
		cout << vectorx[i] << "   " << setw(9) << vectoryi[i] << "   " << setw(9) << vectorf[i] << "   " << setw(9) << vectorfpoint[i] << "   " << setw(9) << vectoryi[i + 1] << "   " << setw(9) << vectory[i] << "   " << setw(9) << error[i] << endl;

	}
	cout << endl;
	cout << "Метод трапеций" << endl;
	index = 1;

	vectorftrap[0] = f7(vectorx[1], vectoryi[0] + step * vectorf[0]);
	for (index; index < index2; index++)
	{
		vectoryi[index] = vectoryi[index - 1] + step * (vectorf[index - 1] + vectorftrap[index - 1]) / 2;
		vectorf[index] = f7(vectorx[index], vectoryi[index]);
		if (index == index2 - 1)
		{
			break;
		}
		vectorftrap[index] = f7(vectorx[index + 1], vectoryi[index] + step * vectorf[index]);
		error[index - 1] = abs(vectory[index - 1] - vectoryi[index - 1]);
	}

	cout << " x[i]" << setw(9) << " y[i]" << setw(9) << " f(x[i],y[i])" << setw(9) << " f(...)" << setw(9) << "    y[i+1] " << setw(10) << " точное значение " << setw(10) << " погрешность" << endl;
	for (int i = 0; i < index2; i++)
	{
		if (i == index2 - 1) {
			cout << vectorx[i] << "   " << setw(10) << vectoryi[i] << "   " << setw(10) << vectorf[i] << "   " << setw(10) << vectorftrap[i] << "   " << setw(10) << " ------  " << setw(10) << vectory[i] << "   " << setw(10) << error[i] << endl;
			break;
		}
		cout << vectorx[i] << "   " << setw(9) << vectoryi[i] << "   " << setw(9) << vectorf[i] << "   " << setw(9) << vectorftrap[i] << "   " << setw(9) << vectoryi[i + 1] << "   " << setw(9) << vectory[i] << "   " << setw(9) << error[i] << endl;

	}
	cout << endl;
	cout << "Метод Рунге-Кутты" << endl;

	vectoryi[0] = 1;
	for (index = 0; index < index2; index++)
	{

		vectork1[index] = f7(vectorx[index], vectoryi[index]);
		vectork2[index] = f7(vectorx[index] + step / 2, vectoryi[index] + (step*vectork1[index]) / 2);
		vectork3[index] = f7(vectorx[index] + step / 2, vectoryi[index] + (step*vectork2[index]) / 2);
		vectork4[index] = f7(vectorx[index] + step, vectoryi[index] + step * vectork3[index]);
		error[index] = abs(vectory[index] - vectoryi[index]);
		if (index == index2 - 1)
		{
			break;
		}
		vectoryi[index + 1] = vectoryi[index] + (step * (vectork1[index] + 2 * vectork2[index] + 2 * vectork3[index] + vectork4[index])) / 6;

	}

	cout << " x[i]" << setw(11) << " y[i]" << setw(11) << " k1" << setw(11) << " k2" << setw(11) << "  k3 " << setw(11) << " k4 " << setw(11) << " y[i+1]" << setw(11) << " точное значение " << setw(11) << " погрешность" << endl;
	for (int i = 0; i < index2; i++)
	{
		if (i == index2 - 1) {
			cout << vectorx[i] << "   " << setw(9) << vectoryi[i] << "   " << setw(9) << vectork1[i] << "   " << setw(9) << vectork2[i] << "   " << setw(9) << vectork3[i] << "   " << setw(9) << vectork4[i] << "   " << setw(10) << " ------  " << "   " << setw(9) << vectory[i] << "   " << setw(9) << error[i] << endl;
			break;
		}
		cout << vectorx[i] << "   " << setw(9) << vectoryi[i] << "   " << setw(9) << vectork1[i] << "   " << setw(9) << vectork2[i] << "   " << setw(9) << vectork3[i] << "   " << setw(9) << vectork4[i] << "   " << setw(9) << vectoryi[i + 1] << "   " << setw(9) << vectory[i] << "   " << setw(9) << error[i] << endl;

	}
	cout << endl;



	system("pause");
	return 0;
}