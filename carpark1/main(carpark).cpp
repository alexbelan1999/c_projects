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
	cout << "Заполняем базу.Введите количество добавляемых элементов: " << endl;
	cin >> number;
	vehicle *transport = new vehicle[number];
	input(transport, number);
	cout << "Выводим всю базу: " << endl;
	output(transport, number);
	cout << "Поиск по типу.Введите тип:" << endl;
	find(transport, number);
	delete [] transport;
	system("pause");
	return 0;
}