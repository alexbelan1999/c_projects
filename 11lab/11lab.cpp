#include "stdafx.h"
#include "Header.h"

int main()
{
	RingList<int> list;

	for (int i = 0; i < 9; i++)
	{
		list.insert(i);
	}

	list.remove(4);
	list.remove(0);
	list.remove(9);

	cout << "\n\"Remove all\" process was started...\n";

	list.~RingList();

	cin.get();
}
