#define _USE_MATH_DEFINES
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <vector>
#include <iomanip>
#include"func.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double alfa1 = 0;
	double alfa2 = 1;
	double beta1 = 1;
	double beta2 = 0;
	double gama1 = 0;
	double gama2 = 0.5;

	double start = 0;
	double end = 1;
	int index = 0;

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
		cout << setw(9) << vectorx[n] << " " << setw(9) << vectory[n] << endl;
	}


	double **arr = new double*[index1];
	for (int i = 0; i < index1; i++) {
		arr[i] = new double[index1];
	}


	double x = 0;
	int j = 0;
	int k = 1;
	for (int i = 0; i < index1; i++)

	{
		for (int j = 0; j <= index1; j++) {
			arr[i][j] = 0;
		}
	}

	for (int i = 0; i < index1; i++)

	{
		for (int j = 0; j <= index1; j++) {
			cout << setw(6) << arr[i][j] << " ";


		}
		cout << endl;
	}
	arr[0][0] = alfa2 + beta2 / h;
	arr[0][1] = -beta2 / h;
	arr[0][index1] = gama2;
	for (int i = index1 - 2; i >= 1; i--)
	{
		x = vectorx[i];
		j = k - 1;
		arr[k][j] = arg1(x);
		arr[k][j + 1] = arg2(x);
		arr[k][j + 2] = arg3(x);
		arr[k][index1] = fx(x);
		k++;

	}


	arr[index1 - 1][index1 - 2] = alfa1 - beta1 / h;
	arr[index1 - 1][index1 - 1] = beta1 / h;
	arr[index1 - 1][index1] = gama1;

	cout <<  endl;

	for (int i = 0; i < index1; i++)

	{
		for (int j = 0; j <= index1; j++) {
			cout << setw(6) << arr[i][j] << " ";


		}
		cout << endl;
	}

	double det1 = 0, det2 = 0;
	for (int i = 1; i < index1; i++) {
		det1 = arr[i][i - 1];
		det2 = arr[i - 1][i - 1];
		for (int j = i - 1; j <= index1; j++) {
			arr[i][j] -= arr[i - 1][j] * det1 / det2;
		}
	}

	cout <<  endl;

	for (int i = 0; i < index1; i++)

	{
		for (int j = 0; j <= index1; j++) {
			cout << setw(6) << arr[i][j] << " ";


		}
		cout << endl;
	}
	vector<double> vectorresult(index1);
	vectorresult[0] = arr[index1 - 1][index1] / arr[index1 - 1][index1 - 1];
	k = 1;
	for (int i = index1 - 2; i >= 1; i--)
	{
		vectorresult[k] = (arr[i][index1] - (vectorresult[k - 1] * arr[i][i + 1])) / arr[i][i];
		k++;
	}
	vectorresult[index1 - 1] = 0.5;

	cout << setw(9) << "x: " << setw(9) << "y: " << setw(9) << "Погрешность: " << endl;
	for (int n = 0; n < index; n++)
	{
		cout << setw(9) << vectorx[n] << " " << setw(9) << vectorresult[n] << "   " << setw(9) << abs(vectory[n] - vectorresult[n]) << endl;

	}

	system("pause");
	return 0;
}
