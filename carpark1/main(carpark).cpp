#include <vector>
#include <iostream>
#include <string>
#include<windows.h>
#include "carpark.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number;
	cout << "��������� ����.������� ���������� ����������� ���������: " << endl;
	cin >> number;
	vehicle *transport = new vehicle[number];
	input(transport, number);
	cout << "������� ��� ����: " << endl;
	output(transport, number);
	cout << "����� �� ����.������� ���:" << endl;
	find(transport, number);
	delete [] transport;
	system("pause");
	return 0;
}