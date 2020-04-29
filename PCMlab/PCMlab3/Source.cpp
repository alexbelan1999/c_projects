#include <iostream>
#include <Windows.h>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<double> vectorx = { 2,3,4,5,6,7 };
	vector<double> vectory = { -2.8,5.6,12,16,14,5 };

	int n = vectorx.size();
	cout << "Таблица значений " << endl;
	cout << "x  ";
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << vectorx[i] << " ";
	}
	cout << endl;

	cout << "y  ";
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << vectory[i] << " ";
	}
	cout << endl;

	double sumx = 0;
	double sumy = 0;
	double sumx2 = 0;
	double sumx2y = 0;
	double sumx3 = 0;
	double sumx3y = 0;
	double sumx4 = 0;
	double sumx5 = 0;
	double sumx6 = 0;
	double sumxy = 0;


	for (int i = 0; i < n; i++) {
		sumx += vectorx[i];
		sumy += vectory[i];
		sumx2 += pow(vectorx[i],2);
		sumx2y += pow(vectorx[i], 2) * vectory[i];
		sumx3 += pow(vectorx[i], 3);
		sumx3y += pow(vectorx[i], 3) * vectory[i];
		sumx4 += pow(vectorx[i], 4);
		sumx5 += pow(vectorx[i], 5);
		sumx6 += pow(vectorx[i], 6);
		sumxy += vectorx[i] * vectory[i];
	}

	double a = (n * sumxy - sumy * sumx) / (n * sumx2 - sumx * sumx);
	double b = (sumy - a * sumx) / n;
	double infelicity = 0;
	for (int i = 0; i < n; i++) {
		infelicity += pow(vectory[i] - (a * vectorx[i] + b), 2);
	}

	cout << endl;
	cout << "f(x) = " << a << " x  +  " << b << endl;;
	cout << "Погрешность: "<<infelicity << endl;
	cout << endl;

	double det = sumx4 * sumx2 * n - sumx4 * pow(sumx, 2) - pow(sumx3, 2) * n + sumx3 * sumx2 * sumx + sumx2 * sumx3 * sumx - pow(sumx2, 3);
	a = (sumx2y * sumx2 * n - sumx2y * pow(sumx, 2) - sumx3 * sumxy * n + sumx3 * sumy * sumx + sumx2 * sumxy * sumx - sumx2 * sumy * sumx2) / det;
	b = (sumx4 * sumxy * n - sumx4 * sumy * sumx - sumx2y * sumx3 * n + sumx2y * sumx2 * sumx + sumx2 * sumx3 * sumy - pow(sumx2, 2) * sumxy) / det;
	double c = (sumx4 * sumx2 * sumy - sumx4 * sumx * sumxy - pow(sumx3, 2) * sumy + sumx3 * sumx2 * sumxy + sumx2y * sumx3 * sumx - sumx2y * pow(sumx2, 2)) / det;



	cout << "f(x) = " << a << " x^2  + " << b << " x " << " + " << c << endl;
	infelicity = 0;
	for (int i = 0; i < n; i++) {
		infelicity += pow(vectory[i] - (a * vectorx[i] * vectorx[i] + b * vectorx[i] + c), 2);
	}
	cout << "Погрешность: " << infelicity << endl;
	cout << endl;





	double det2 = sumx3 * sumx3 * sumx3 * sumx3 - sumx6 * sumx2 * sumx2 * sumx2 + sumx4 * sumx4 * sumx2 * sumx2 + 2 * sumx5 * sumx3 * sumx2 * sumx2 - 3 * sumx4 * sumx3 * sumx3 * sumx2 + sumx5 * sumx5 * sumx * sumx - sumx6 * sumx4 * sumx * sumx - 2 * sumx5 * sumx3 * sumx3 * sumx + 2 * sumx4 * sumx4 * sumx3 * sumx - 2 * sumx5 * sumx4 * sumx2 * sumx + 2 * sumx6 * sumx3 * sumx2 * sumx - sumx4 * sumx4 * sumx4 * n - sumx6 * sumx3 * sumx3 * n + 2 * sumx5 * sumx4 * sumx3 * n - sumx5 * sumx5 * sumx2 * n + sumx6 * sumx4 * sumx2 * n;
	a = (sumx2y * sumx3 * sumx2 * sumx2 + sumx2y * sumx5 * sumx * sumx - sumx2y * sumx3 * sumx3 * sumx - sumx2y * sumx4 * sumx2 * sumx + sumx2y * sumx4 * sumx3 * n - sumx2y * sumx5 * sumx2 * n - sumx2 * sumx2 * sumx2 * sumx3y - sumx4 * sumx * sumx * sumx3y + 2 * sumx3 * sumx2 * sumx * sumx3y - sumx3 * sumx3 * n * sumx3y + sumx4 * sumx2 * n * sumx3y + sumx4 * sumx2 * sumx2 * sumxy - sumx3 * sumx3 * sumx2 * sumxy + sumx4 * sumx3 * sumx * sumxy - sumx5 * sumx2 * sumx * sumxy - sumx4 * sumx4 * n * sumxy + sumx5 * sumx3 * n * sumxy + sumx3 * sumx3 * sumx3 * sumy + sumx5 * sumx2 * sumx2 * sumy - 2 * sumx4 * sumx3 * sumx2 * sumy + sumx4 * sumx4 * sumx * sumy - sumx5 * sumx3 * sumx * sumy) / det2;
	b = (-sumx2y * sumx3 * sumx3 * sumx2 - sumx2y * sumx6 * sumx * sumx + 2 * sumx2y * sumx4 * sumx3 * sumx - sumx2y * sumx4 * sumx4 * n + sumx2y * sumx6 * sumx2 * n + sumx3 * sumx2 * sumx2 * sumx3y + sumx5 * sumx * sumx * sumx3y - sumx3 * sumx3 * sumx * sumx3y - sumx4 * sumx2 * sumx * sumx3y + sumx4 * sumx3 * n * sumx3y - sumx5 * sumx2 * n * sumx3y + sumx3 * sumx3 * sumx3 * sumxy - sumx4 * sumx3 * sumx2 * sumxy - sumx5 * sumx3 * sumx * sumxy + sumx6 * sumx2 * sumx * sumxy + sumx5 * sumx4 * n * sumxy - sumx6 * sumx3 * n * sumxy - sumx4 * sumx3 * sumx3 * sumy - sumx6 * sumx2 * sumx2 * sumy + sumx4 * sumx4 * sumx2 * sumy + sumx5 * sumx3 * sumx2 * sumy - sumx5 * sumx4 * sumx * sumy + sumx6 * sumx3 * sumx * sumy) / det2;
	c = (sumx2y * sumx3 * sumx3 * sumx3 - sumx2y * sumx4 * sumx3 * sumx2 - sumx2y * sumx5 * sumx3 * sumx + sumx2y * sumx6 * sumx2 * sumx + sumx2y * sumx5 * sumx4 * n - sumx2y * sumx6 * sumx3 * n + sumx4 * sumx2 * sumx2 * sumx3y - sumx3 * sumx3 * sumx2 * sumx3y + sumx4 * sumx3 * sumx * sumx3y - sumx5 * sumx2 * sumx * sumx3y - sumx4 * sumx4 * n * sumx3y + sumx5 * sumx3 * n * sumx3y - sumx4 * sumx3 * sumx3 * sumxy - sumx6 * sumx2 * sumx2 * sumxy + 2 * sumx5 * sumx3 * sumx2 * sumxy - sumx5 * sumx5 * n * sumxy + sumx6 * sumx4 * n * sumxy - sumx5 * sumx3 * sumx3 * sumy + sumx4 * sumx4 * sumx3 * sumy - sumx5 * sumx4 * sumx2 * sumy + sumx6 * sumx3 * sumx2 * sumy + sumx5 * sumx5 * sumx * sumy - sumx6 * sumx4 * sumx * sumy) / det2;
	double d = (-sumx2y * sumx4 * sumx3 * sumx3 - sumx2y * sumx6 * sumx2 * sumx2 + sumx2y * sumx4 * sumx4 * sumx2 + sumx2y * sumx5 * sumx3 * sumx2 - sumx2y * sumx5 * sumx4 * sumx + sumx2y * sumx6 * sumx3 * sumx + sumx3 * sumx3 * sumx3 * sumx3y + sumx5 * sumx2 * sumx2 * sumx3y - 2 * sumx4 * sumx3 * sumx2 * sumx3y + sumx4 * sumx4 * sumx * sumx3y - sumx5 * sumx3 * sumx * sumx3y - sumx5 * sumx3 * sumx3 * sumxy + sumx4 * sumx4 * sumx3 * sumxy - sumx5 * sumx4 * sumx2 * sumxy + sumx6 * sumx3 * sumx2 * sumxy + sumx5 * sumx5 * sumx * sumxy - sumx6 * sumx4 * sumx * sumxy - sumx4 * sumx4 * sumx4 * sumy - sumx6 * sumx3 * sumx3 * sumy + 2 * sumx5 * sumx4 * sumx3 * sumy - sumx5 * sumx5 * sumx2 * sumy + sumx6 * sumx4 * sumx2 * sumy) / det2;

	cout << "f(x) = " << a << " x^3  + " << b << " x^2 + " << c << " x + " << d << endl;
	infelicity = 0;
	for (int i = 0; i < n; i++) {
		infelicity += pow(vectory[i] - (a * vectorx[i] * vectorx[i] * vectorx[i] + b * vectorx[i] * vectorx[i] + c * vectorx[i] + d), 2);
	}
	cout << "Погрешность: " << infelicity << endl;
	cout << endl;
	
	system("pause");
	return 0;
}