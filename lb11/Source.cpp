#include "Header1.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	RingList<int> list;
	int n;
	cout << "Введите количество элементов списка:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		list.insert(i);
	}

	list.remove(5);
	list.remove(2);
	list.remove(9);

	cout << "Начинаем процесс удаления:" << endl;;

	list.~RingList();
	system ("pause");
	return 0;
}