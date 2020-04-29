#include <iostream>
#include <Windows.h>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

double myfunc(double x)
{
	double result;
	result = x/(3*x+5);
	return result;
}
double derivat1(double x)
{
	double result;
	result = -3*x/((3*x+5)*(3 * x + 5))+1/ (3 * x + 5);
	return result;
}

double derivat2(double x)
{
	double result;
	result = 18*x/((3 * x + 5)*(3 * x + 5)*(3 * x + 5));
	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "x*sin(x)+ x^2" << endl;
	int index = 0;
	double start = 1.0;
	double end = 3.0;
	double h = 0.5;

	for (double i = start; i <= end; i = i + h)
	{
		index++;
	}

	vector<double> vectorx(index);
	vector<double> vectory(index);

	index = 0;
	for (double i = start; i <= end; i = i + h)
	{
		vectorx[index] = i;
		vectory[index] = myfunc(i);
		index++;
	}

	cout << "Таблица значений " << endl;
	cout << "x    ";
	for (int n = 0; n < index; n++)
	{
		cout << setw(10) << vectorx[n] << " ";
	}
	cout << endl;

	cout << "y(x) ";
	for (int n = 0; n < index; n++)
	{
		cout << setw(10) << vectory[n] << " ";
	}
	cout << endl;
	cout << endl;

	vector<double> d1(index);
	vector<double> d2(index);
	vector<double> d1l(index);
	vector<double> d1c(index);
	vector<double> d1r(index);
	vector<double> d22(index);

	for (int i = 0; i < index; i++) {
		d1[i] = derivat1(vectorx[i]);
	}

	cout << "Первая производная: " << endl;
	for (int n = 0; n < index; n++)
	{
		cout << "x["<<n<<"]     " << d1[n] << endl;
	}
	cout << endl;

	for (int i = 0; i < index-1; i++) {
		d1r[i] = (vectory[i + 1] - vectory[i]) / h;
	}

	cout << "Правая производная: " << endl;
	for (int n = 0; n < index-1; n++)
	{
		cout << "x[" << n << "]     " << d1r[n] << endl;
	}
	cout << endl;

	for (int i = 1; i < index; i++) {
		d1l[i] = (vectory[i] - vectory[i-1]) / h;
	}

	cout << "Левая производная: " << endl;
	for (int n = 1; n < index ; n++)
	{
		cout << "x[" << n << "]     " << d1l[n] << endl;
	}
	cout << endl;

	for (int i = 1; i < index - 1; i++) {
		d1c[i] = (vectory[i + 1] - vectory[i - 1]) / (2 * h);
	}

	cout << "Центральная производная: " << endl;
	for (int n = 1; n < index - 1; n++)
	{
		cout << "x[" << n << "]     " << d1c[n] << endl;
	}
	cout << endl;

	for (int i = 0; i < index; i++) {
		d2[i] = derivat2(vectorx[i]);
	}

	cout << "Вторая производная: " << endl;
	for (int n = 0; n < index; n++)
	{
		cout << "x[" << n << "]     " << d2[n] << endl;
	}
	cout << endl;


	for (int i = 1; i < index-1; i++) {
		d22[i] = (vectory[i + 1] - 2 * vectory[i] + vectory[i - 1]) / (h*h);
	}

	cout << "Приближенное значение второй производной:  " << endl;
	for (int n = 1; n < index-1; n++)
	{
		cout << "x[" << n << "]     " << d22[n] << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}
