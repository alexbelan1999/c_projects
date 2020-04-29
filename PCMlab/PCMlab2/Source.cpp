#define _USE_MATH_DEFINES
#include <iostream>
#include <Windows.h>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

double myfunc(double x)
{
	double result;
	result = x - cos(x);
	return result;
}

int pointfor(double x, vector<double> v)
{
	int i = 0;
	while (x > v[i])
	{
		i++;
	}
	return i;
}

double calcalpha(int i,double h, vector<double> y)
{
	return (6 / (h * h)) * (y[i + 1] - 2 * y[i] + y[i - 1]);
}

vector<double> calca(vector<double> y)
{
	vector<double> a(size(y));
	for (int i = 0; i < (int)size(y); i++)
	{
		a[i] = y[i];
	}
	return a;
}

vector<int> calccoeff(int i)
{
	vector<int> coeff(i);
	coeff[0] = 0;
	coeff[1] = 1;
	for (int n = 2; n < i; n++) 
	{
		coeff[n] = 4 * coeff[n - 1] - coeff[n - 2];
		
	}

	return coeff;
}

vector<double> calcc(int index, double h, vector<double> y, vector<int> coeff)
{
	vector<double> c(index);
	//c[0] = 0;
	for (int i = index - 1; i > 1; i--)
	{
		
		double slag = 0.0;
		int minus = 1;
		for (int j = i - 1; j > 0; j--)
		{
			slag += minus * coeff[j] * calcalpha(j, h, y);
			minus *= -1;
		}
		slag = (slag - c[0] * coeff[i - 1]) / coeff[i];
		c.insert(c.begin(),slag);
		//c[0] = slag;
	}
	//c[0] = 0;
	c.insert(c.begin(), 0);
	return c;
}

vector<double> calcd(int index, double h, vector<double> c)
{
	vector<double> d(index);
	d[0] = 0;
	for (int i = 1; i < index; i++)
	{
		d[i] = (c[i] - c[i - 1]) / h;
	}

	return d;
}

vector<double> calcb(int index, double h, vector<double> c, vector<double> d, vector<double> y)
{
	vector<double> b(index);
	b[0] = 0;
	for (int i = 1; i < index; i++) {
		b[i] = (c[i] * h / 2) - (d[i] * h*h / 6) + ((y[i] - y[i - 1]) / h);
	}

	return b;
}
double calcspline(int index, vector<double> vx, vector<double> a, vector<double> b, vector<double> c, vector<double> d, double x)
{
	double sum = 0.0;
	double mult = x - vx[index];
	sum = a[index] + b[index] * mult + c[index] / 2 * mult*mult + d[index] / 6 * mult*mult*mult;
	return sum;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "y(x) = x - cos(x)" << endl;
	int index = 0;
	double start = 0.0;
	double end = M_PI;
	double h = M_PI / 5;

	for (double i = start; i <= end; i = i + h)
	{
		index++;
	}

	vector<double> vectorx(index);
	vector<double> vectory(index);
	index = 0;
	for (double i = start; i <= end; i = i + h)
	{
		//cout << "x[" << index << "]  ";
		vectorx[index] = i;
		vectory[index] = myfunc(i);
		//cout << i << " " << endl;
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

	cout << "Степень интерполяционного сплайна: 3 " << endl;

	double x1 = start + 0.5 * h;
	double x2 = 0.5*start + 0.5*end;
	double x3 = end - 0.5 * h;

	cout << "Точки: " << endl;
	cout << x1 << endl;
	cout << x2 << endl;
	cout << x3 << endl;

	int p1 = pointfor(x1, vectorx);
	int p2 = pointfor(x2, vectorx);
	int p3 = pointfor(x3, vectorx);
	
	
	cout << "Ближайшие точки: " << endl;
	cout << vectorx[p1] << endl;
	cout << vectorx[p2] << endl;
	cout << vectorx[p3] << endl;
	
	
	vector<double> vectora(index);
	vectora = calca(vectory);
	
	
	cout << "Значение a для " << endl;
	for (int i = 0; i < index; i++)
	{
		cout << "x[" << i << "] равно " << vectora[i] << endl;
	}
	

	vector<int> vectorcoeff(index);
	vectorcoeff = calccoeff(index);

	cout << "Значение coeff для " << endl;
	for (int i = 0; i < index; i++)
	{
		cout << "x[" << i << "] равно " << vectorcoeff[i] << endl;
	}
	
	vector<double> vectorc(index);
	vectorc = calcc(index,h,vectory,vectorcoeff);

	cout << "Значение c для " << endl;
	for (int i = 0; i < index; i++)
	{
		cout << "x[" << i << "] равно " << vectorc[i] << endl;
	}
	

	vector<double> vectord(index);
	vectord = calcd(index, h,vectorc);

	cout << "Значение d для " << endl;
	for (int i = 0; i < index; i++)
	{
		cout << "x[" << i << "] равно " << vectord[i] << endl;
	}
	
	vector<double> vectorb(index);
	vectorb = calcb(index, h, vectorc, vectord, vectory);

	cout << "Значение b для " << endl;
	for (int i = 0; i < index; i++)
	{
		cout << "x[" << i << "] равно " << vectorb[i] << endl;
	}
	
	cout << "Значение функции в точках: " << endl;
	cout << "x[0] " << myfunc(x1) << endl;
	cout << "x[1] " << myfunc(x2) << endl;
	cout << "x[2] " << myfunc(x3) << endl;
	cout << "Значение сплайна в точках: " << endl;
	cout << "x[0] " << calcspline(p1, vectorx, vectora, vectorb, vectorc, vectord, x1) << endl;
	cout << "x[1] " << calcspline(p2, vectorx, vectora, vectorb, vectorc, vectord, x2) << endl;
	cout << "x[2] " << calcspline(p3, vectorx, vectora, vectorb, vectorc, vectord, x3) << endl;
	system("pause");
	return 0;
}