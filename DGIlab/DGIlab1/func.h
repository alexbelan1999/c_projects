#pragma once
#include<iostream>
#include<iomanip>

using namespace std;

const int n = 10;


void transpor(double array[n][n], double transp_array[n][n]) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			transp_array[i][j] = array[j][i];
		}
	}
}

void show(double array[n][n]) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cout << setw(4) << array[i][j] << " ";
		}
		cout << endl;
	}
}

void showvector(double array[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(array[i][j]==1)
			{
				cout << "X" << " ";
			}
			else
			{
				cout << " " << " ";
			}
			
		}
		cout << endl;
	}
}


void mult(double array1[n][n], double array2[n][n], double mult_array[n][n]) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int k = 0; k < n; k++) 
		{
			int result = 0;
			for (int j = 0; j < n; j++) 
			{
				result += array1[i][j] * array2[j][k];
			}
			mult_array[i][k] = result;
		}
	}
}

void mult_cof(double array[n][n], double mult_cof_array[n][n]) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			array[i][j] *= 0.1;
			mult_cof_array[i][j] = array[i][j];
		}
	}
}

void sum_10(double array1[n][n], double array2[n][n], double array3[n][n], double array4[n][n], double array5[n][n], double array6[n][n], double array7[n][n], double array8[n][n], double array9[n][n], double array10[n][n], double sum_array[n][n]) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			sum_array[i][j] = array1[i][j] + array2[i][j] + array3[i][j] + array4[i][j] + array5[i][j] + array6[i][j] + array7[i][j] + array8[i][j] + array9[i][j] + array10[i][j];
		}
	}
}

void sign(double array[n][n]) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (array[i][j] >= 0) 
			{
				array[i][j] = 1;
			}
			else 
			{
				array[i][j] = -1;
			}
		}
	}
}

double dist(double array[n][n], double arrayY[n][n]) 
{
	double distant = 0.0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			distant = distant + pow((array[i][j] - arrayY[i][j]), 2);
		}
	}
	return sqrt(distant);
}

double minim(double K[n]) 
{
	double min = K[0];
	for (int i = 0; i < n; i++)
	{
		if (K[i] < min)
		{
			min = K[i];
		}
	}
	return min;
}

double maxim(double K[n])
{
	double max = K[0];
	for (int i = 0; i < n; i++)
	{
		if (K[i] > max)
		{
			max = K[i];
		}
	}
	return max;
}

double av(double K[n]) {
	double s = 0.0;
	for (int i = 0; i < n; i++)
	{

		s = s + K[i];

	}
	return s / n;
}