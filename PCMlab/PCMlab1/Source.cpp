#define _USE_MATH_DEFINES
#include <iostream>
#include <Windows.h>
#include <math.h>

using namespace std;

double myfunc(double x)
{
	double result;
	result = x - cos(x);
	return result;
}

double derivative1(double x)
{
	double result;
	result = 1 + sin(x);
	return result;
}

double derivative2(double x)
{
	double result;
	result = cos(x);
	return result;
}

double derivative3(double x)
{
	double result;
	result = -sin(x);
	return result;
}

double derivative4(double x)
{
	double result;
	result = -cos(x);
	return result;
}

double derivative5(double x)
{
	double result;
	result = sin(x);
	return result;
}

double derivative6(double x)
{
	double result;
	result = cos(x);
	return result;
}

double factorial(int n)
{
	int result = 1;

	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	//cout << "factorial:" << result << endl;
	return result;
}

double maxderivative(int n, double start,double end)
{
	double exp;
	if (end - start >= M_PI)
	{
		exp = 1;
	}
	else
	{
		int period = (int)(start / M_PI);
		//cout << "Период " << period << endl;
		start = start - M_PI * period;
		end = end - M_PI * period;
		//cout << "Start: " << start << "  End: " << end << endl;
		if ((start <= M_PI / 2) && (end >= M_PI / 2))
		{
			if( (n==2)|| (n==4))
			{
				exp = 1;
			}
		}
		else 
		{
			if (n == 2)
			{
				exp = max(abs(derivative3(start)), abs(derivative3(end)));
			}

			if (n == 4)
			{
				exp = max(abs(derivative5(start)), abs(derivative5(end)));
			}
		}
		if ((start == 0.0) || (end == M_PI))
		{
			if ((n == 1) || (n == 3) || (n == 5))
			{
				exp = 1;
			}
		}
		else
		{
			if (n == 1)
			{
				exp = max(abs(derivative2(start)), abs(derivative2(end)));
			}
			
			if (n == 3)
			{
				exp = max(abs(derivative4(start)), abs(derivative4(end)));
			}
			
			if (n == 5)
			{
				exp = max(abs(derivative6(start)), abs(derivative6(end)));
			}
		}
	}
	cout << "max exp:" << exp << endl;
	return exp;
}

double wx(int n,double x, double *xn)
{
	double result = 1;
	for (int i = 0; i <= n; i++)
	{
		result = result * (x - xn[i]);
	}
	return abs(result);
}

double infelicity(int n,double x,double start,double end,double * xn)
{
	double result = 0;
	double exp = 0;
	double exp1 = 0;
	exp = maxderivative(n, start, end);
	exp1 = wx(n, x, xn);
	result = (exp / factorial(n + 1))*exp1;
	return result;
}

double lagrange(double* arrx, double* arry, int n, double x)
{
	double result = 0.0;
	double P = 0.0;

	for (int i = 0; i <= n; i++)
	{
		double P = 1.0;

		for (int j = 0; j <= n; j++)
		{
			if (j != i)
			{
				P = P * (x - arrx[j]) / (arrx[i] - arrx[j]);
			}	
		}
		result = result + (P * arry[i]);
	}
	return result;
}

double calcnewton(int i, double *x,double *y, int index)
{
	if (i == 0)
	{
		return y[index];
	}
	else
	{
		i--;
		//cout << (calcnewton(i, x, y, index) - calcnewton(i, x, y, index - 1)) / (x[index] - x[index - i - 1]) << endl;
		return (calcnewton(i, x, y, index) - calcnewton(i, x, y, index - 1)) / (x[index] - x[index - i - 1]);

	}
	
}

double newton (double varx, double *x, double *y, int n)
{
	double result = 0;
	for (int i = 0; i <= n; i++)
	{
		double slag = calcnewton(i, x, y, i);
		cout << slag << endl;
		for (int j = 0; j < i; j++)
		{
			slag = slag * (varx - x[j]);
		}
		result = result + slag;
	}
	return result;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "y(x) = x - cos(x)" << endl;
	int index = 0;
	double start = 0.0;
	double end = M_PI*2;
	double h = M_PI / 5;
	
	for (double i = start; i <= end; i = i + h)
	{
		index++;
	}

	double *arrx = new double [index];
	double *arry = new double[index];
	
	index = 0;
	for (double i = start; i <= end; i = i + h)
	{
		//cout << "x[" << index << "]  ";
		arrx[index] = i;
		arry[index] = myfunc(i);
		//cout << i << " " << endl;
		index++;
	}

	cout << "Таблица значений " << endl;
	cout << "x      ";
	for (int n = 0; n < index; n++)
	{
		cout << arrx[n] << "   ";
	}
	cout << endl;

	cout << "y(x)  ";
	for (int n = 0; n < index; n++)
	{
		cout << arry[n] << "   ";
	}
	cout << endl;

	int n1=-1, n2=-1;
	bool flag1 = false, flag2 = false;
	cout << "Введите степень интерполяционного многочлена Лагранжа: " << endl;
	while (flag1 == false)
	{
		cin >> n1;
		if ((n1 <= index - 1)&&(n1>0))
		{
			flag1 = true;
			break;
		}
		cout << "Ошибка в степени многочлена!" << endl;

	}
	
	cout << "Введите степень интерполяционного многочлена Ньютона: " << endl;
	while (flag2 == false)
	{
		cin >> n2;
		if ((n2 <= index - 1) && (n2 > 0))
		{
			flag2 = true;
			break;
		}
		cout << "Ошибка в степени многочлена!" << endl;
	}

	double *x = new double[3];
	bool flag3 = false, flag4 = false, flag5 = false;
	cout << "Введите три точки для вычисления значений интерполяционных многочленов" << endl;
	while (flag3 == false) 
	{
		cin >> x[0];
		if ((start <= x[0]) && (x[0] <= end)) 
		{
			flag3 = true;
			break;
		}
		cout << "Вне промежутка!" << endl;
	}
	while (flag4 == false)
	{
		cin >> x[1];
		if ((start <= x[1]) && (x[1] <= end))
		{
			flag4 = true;
			break;
		}
		cout << "Вне промежутка!" << endl;
	}
	while (flag5 == false)
	{
		cin >> x[2];
		if ((start <= x[2]) && (x[2] <= end))
		{
			flag5 = true;
			break;
		}
		cout << "Вне промежутка!" << endl;
	}

	int *numberpoint = new int[3];
	for (int t = 0; t < 3; t++)
	{
		for (int m = 0; m < index - 1; m++)
		{
			if ((x[t] >= arrx[m]) && (x[t]) <= arrx[m + 1])
			{
				cout << "Точка " << x[t] << " находится в промежутке [" << arrx[m] << "," << arrx[m + 1] << "]" << endl;
				numberpoint[t] = m;
				break;
			}
				
		}
	}
	cout << "Точки начала промежутка:" << endl;
	for (int t = 0; t < 3; t++)
	{
		cout << numberpoint[t] << " ";
	}
	cout << endl;

	int *startpoint = new int[3];
	int *endpoint = new int[3];

	int *startpoint1 = new int[3];
	int *endpoint1 = new int[3];

	for (int t = 0; t < 3; t++)
	{
		if (numberpoint[t] <= (n1 - 1))
		{
			startpoint[t] = 0;
			endpoint[t] = n1;
		}
		else
		{
			endpoint[t] = numberpoint[t] + 1;
			startpoint[t] = endpoint[t] - n1;

		}
	}
	
	for (int t = 0; t < 3; t++)
	{
		if (numberpoint[t] <= (n2 - 1))
		{
			startpoint1[t] = 0;
			endpoint1[t] = n2;
		}
		else
		{
			endpoint1[t] = numberpoint[t] + 1;
			startpoint1[t] = endpoint1[t] - n2;

		}
	}

	
	cout << "Лангранж" << endl;

	for (int t = 0; t < 3; t++)
	{
		cout << "Для точки "<< t+1 <<" выбраны точки начиная с "<<startpoint[t]<<" до "<< endpoint[t] << endl;
	}

	cout << "Ньютон" << endl;
	for (int t = 0; t < 3; t++)
	{
		cout << "Для точки " << t + 1 << " выбраны точки начиная с " << startpoint1[t] << " до " << endpoint1[t] << endl;
	}
	
	double *x1 = new double[n1+1];
	double *x2 = new double[n1+1];
	double *x3 = new double[n1+1];
	double *y1 = new double[n1+1];
	double *y2 = new double[n1+1];
	double *y3 = new double[n1+1];

	double *x11 = new double[n2 + 1];
	double *x21 = new double[n2 + 1];
	double *x31 = new double[n2 + 1];
	double *y11 = new double[n2 + 1];
	double *y21 = new double[n2 + 1];
	double *y31 = new double[n2 + 1];

	int r = 0;

	for (int t = 0; t < 3; t++)
	{
		r = 0;
		if (t == 0)
		{
			//cout << startpoint[t] << "  " << endpoint[t] << endl;
			for (int a = startpoint[t]; a <= endpoint[t]; a++)
			{
				//cout << arrx[a] << "  " << arry[a] << endl;
				x1[r] = arrx[a];
				y1[r] = arry[a];
				//cout << x1[r] << "  " << y1[r] << endl;
				r++;
			}
			
		}
		else if (t == 1)
		{
			//cout << startpoint[t] << "  " << endpoint[t] << endl;
			for (int a = startpoint[t]; a <= endpoint[t]; a++)
			{
				//cout << arrx[a] << "  " << arry[a] << endl;
				x2[r] = arrx[a];
				y2[r] = arry[a];
				//cout << x2[r] << "  " << y2[r] << endl;
				r++;
			}
			
		}
		else if (t == 2)
		{
			//cout << startpoint[t] << "  " << endpoint[t] << endl;
			for (int a = startpoint[t]; a <= endpoint[t]; a++)
			{
				//cout << arrx[a] << "  " << arry[a] << endl;
				x3[r] = arrx[a];
				y3[r] = arry[a];
				//cout << x3[r] << "  " << y3[r] << endl;
				r++;
			}
			
		}
		
	}
	/*
	cout << "Точки для Лангранжа" << endl;
	for (int t = 0; t < 3; t++)
	{
		if (t == 0)
		{
			cout << "Точка 1" << endl;
			for (int z = 0; z < n1 + 1; z++)
			{
				cout << x1[z] << " " << y1[z] << endl;
			}
			
		}
		else if (t == 1)
		{

			cout << "Точка 2" << endl;
			for (int z = 0; z < n1 + 1; z++)
			{
				cout << x2[z] << " " << y2[z] << endl;
			}
			
		}
		else if (t == 2)
		{
			cout << "Точка 3" << endl;
			for (int z = 0; z < n1 + 1; z++)
			{
				cout << x3[z] << " " << y3[z] << endl;

			}
			
		}
		
	}
	*/

	r = 0;

	for (int t = 0; t < 3; t++)
	{
		r = 0;
		if (t == 0)
		{
			//cout << startpoint[t] << "  " << endpoint[t] << endl;
			for (int a = startpoint1[t]; a <= endpoint1[t]; a++)
			{
				//cout << arrx[a] << "  " << arry[a] << endl;
				x11[r] = arrx[a];
				y11[r] = arry[a];
				//cout << x1[r] << "  " << y1[r] << endl;
				r++;
			}

		}
		else if (t == 1)
		{
			//cout << startpoint[t] << "  " << endpoint[t] << endl;
			for (int a = startpoint1[t]; a <= endpoint1[t]; a++)
			{
				//cout << arrx[a] << "  " << arry[a] << endl;
				x21[r] = arrx[a];
				y21[r] = arry[a];
				//cout << x2[r] << "  " << y2[r] << endl;
				r++;
			}

		}
		else if (t == 2)
		{
			//cout << startpoint[t] << "  " << endpoint[t] << endl;
			for (int a = startpoint1[t]; a <= endpoint1[t]; a++)
			{
				//cout << arrx[a] << "  " << arry[a] << endl;
				x31[r] = arrx[a];
				y31[r] = arry[a];
				//cout << x3[r] << "  " << y3[r] << endl;
				r++;
			}

		}

	}

	/*
	cout << "Точки для Ньютона" << endl;
	for (int t = 0; t < 3; t++)
	{
		if (t == 0)
		{
			cout << "Точка 1" << endl;
			for (int z = 0; z < n2 + 1; z++)
			{
				cout << x11[z] << " " << y11[z] << endl;
			}

		}
		else if (t == 1)
		{

			cout << "Точка 2" << endl;
			for (int z = 0; z < n2 + 1; z++)
			{
				cout << x21[z] << " " << y21[z] << endl;
			}

		}
		else if (t == 2)
		{
			cout << "Точка 3" << endl;
			for (int z = 0; z < n2 + 1; z++)
			{
				cout << x31[z] << " " << y31[z] << endl;

			}

		}

	}
	*/

	cout << "Значение фукции для трёx точек:" << endl;
	for (int t = 0; t < 3; t++)
	{
		cout << "x[" << t << "] " << myfunc(x[t]) << endl;
	}

	cout << "Значение фукции для трёx точек интерполяционного многочлена Лагранжа:" << endl;
	cout << "x[0] " << lagrange(x1, y1, n1, x[0]) << " погрешность " << infelicity(n1, x[0], start, end, x1) << " разность " << abs(myfunc(x[0]) - lagrange(x1, y1, n1, x[0])) << endl;
	cout << "x[1] " << lagrange(x2, y2, n1, x[1]) << " погрешность " << infelicity(n1, x[1], start, end, x2) << " разность " << abs(myfunc(x[1]) - lagrange(x2, y2, n1, x[1])) << endl;
	cout << "x[2] " << lagrange(x3, y3, n1, x[2]) << " погрешность " << infelicity(n1, x[2], start, end, x3) << " разность " << abs(myfunc(x[2]) - lagrange(x3, y3, n1, x[2])) << endl;

	cout << "Значение фукции для трёx точек интерполяционного многочлена Ньютона:" << endl;
	cout << "x[0] " << newton(x[0], x11, y11, n2) << " погрешность " << infelicity(n2, x[0], start, end, x11) << " разность " << abs(myfunc(x[0]) - newton(x[0], x11, y11, n2)) << endl;
	cout << "x[1] " << newton(x[1], x21, y21, n2) << " погрешность " << infelicity(n2, x[1], start, end, x21) << " разность " << abs(myfunc(x[1]) - newton(x[1], x21, y21, n2)) << endl;
	cout << "x[2] " << newton(x[2], x31, y31, n2) << " погрешность " << infelicity(n2, x[2], start, end, x31) << " разность " << abs(myfunc(x[2]) - newton(x[2], x31, y31, n2)) << endl;

	delete[] arrx;
	delete[] arry;
	delete[] x;
	delete[] numberpoint;
	delete[] startpoint;
	delete[] endpoint;
	delete[] x1; 
	delete[] x2;
	delete[] x3; 
	delete[] y1; 
	delete[] y2;
	delete[] y3;
	delete[] x11;
	delete[] x21;
	delete[] x31;
	delete[] y11;
	delete[] y21;
	delete[] y31;

	system("pause");
	return 0;
}