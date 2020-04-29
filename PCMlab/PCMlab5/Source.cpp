#define _USE_MATH_DEFINES
#include <cmath>
#include <Windows.h>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

double myfunc(double x)
{
	double result;
	result = x * sin(2*x);
	return result;
}

double myFunc(double x)
{
	double result;
	result = (sin(2 * x) / 4) - (x * cos(2 * x) / 2);
	return result;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << " x * sin(2*x)" << endl;
	int index = 0;
	double start = 0.0;
	double end = M_PI /4;
	double h = (end - start) / 10;
	
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

	cout << "Значение интеграла по формуле Ньютона-Лейбница: " << myFunc(end) - myFunc(start) << endl;
	cout << endl;

	double leftrect = 0.0;
	for (double i = start; i < end; i = i + h)
	{
		leftrect += myfunc(i);
	}

	leftrect = leftrect * h;
	cout << "Значение левых прямоугольников: " << leftrect << endl;
	cout << endl;

	double rightrect = 0.0;
	for (double i = start + h; i <= end; i = i + h)
	{
		rightrect += myfunc(i);
	}

	rightrect = rightrect * h;
	cout << "Значение правых прямоугольников: " << rightrect << endl;
	cout << endl;

	double centralrect = 0.0;
	for (double i = start + h/2; i < end; i = i + h)
	{
		centralrect += myfunc(i);
	}

	centralrect = centralrect * h;
	cout << "Значение центральных прямоугольников: " << centralrect << endl;
	cout << endl;

	double trapeze = 0.0;
	for (double i = start ; i < end; i = i + h)
	{
		trapeze += ((myfunc(i) + myfunc(i + h)) / 2);
	}

	trapeze = trapeze * h;
	cout << "Значение метода трапеции: " << trapeze << endl;
	cout << endl;

	double parabol = 0.0;
	double H = (end - start) / (2 * 10);
	for (double i = start+H; i < end; i=i+2*H)
	{
		parabol +=(H / 3) * (myfunc(i - H) + 4 * myfunc(i) + myfunc(i + H));
	}
	cout << "Значение метода парабол: " << parabol << endl;
	cout << endl;

	double gauss = 0.0;
	vector<double>xk = { 0.1834346424, 0.5255324099, 0.7966664774, 0.96028985, -0.1834346424, -0.5255324099, -0.7966664774, -0.96028985 };
	vector<double>ck = { 0.3626837833, 0.3137066458, 0.2223810344, 0.10122853, 0.3626837833, 0.3137066458, 0.2223810344, 0.10122853 };
	for (double i = 0; i < ck.size(); i++)
	{
		gauss += myfunc((end - start) / 2 * xk[i] + (end + start) / 2) * ck[i];
	}
	gauss *= (end - start) / 2;
	cout << "Значение метода Гаусса: " << gauss << endl;
	cout << endl;
	
	system("pause");
	return 0;
}


