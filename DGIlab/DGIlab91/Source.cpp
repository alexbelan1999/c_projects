#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <cctype>
#include <vector>
#include <locale>
#include <fstream>
#include <streambuf>
#include <string.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<string> alf1 = { "а", "б", "в", "г", "д", "е", "ж", "з", "и", "й", "к", "л", "м", "н","о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ы", "ь","э", "ю", "я" };
	vector<string> alf2 = { "г", "д", "е", "ж", "з", "и", "й", "к", "л", "м", "н","о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ы", "ь","э", "ю", "я","а", "б", "в" };
	cout << "Шифр Цезаря" << endl;
	cout << "Введите текст для расшифровки:" << endl;
	char str2[100];
	cin.getline(str2, 100);

	vector< string > str(strlen(str2));
	vector< string > cipher(strlen(str2));

	for (int i = 0; i < (int)(strlen(str2)); i++)
	{
		str[i] = str2[i];

	}
	for (int i = 0; i < (int)(strlen(str2)); i++)
	{
		for (int j = 0; j <= 30; j++) 
		{
			if (str[i] == alf2[j]) 
			{ 
				cipher[i] = alf1[j]; 
			}

		}
		if (str[i] == " ") 
		{
			cipher[i] = " "; 
		}

		if (str[i] == ",") 
		{ 
			cipher[i] = ","; 
		}

		if (str[i] == "-") 
		{
			cipher[i] = "-"; 
		}
	}
	cout << "Результат расшифровки: " << endl;
	for (int i = 0; i < (int)(strlen(str2)); i++)
	{

		cout << cipher[i];
	}
	cout << endl;
	vector<string> tarab1 = { "б", "в", "г", "д", "ж", "з", "к", "л", "м", "н", "щ", "ш", "ч", "ц", "х", "ф", "т", "с","р", "п" };
	vector<string> tarab2 = { "щ", "ш", "ч", "ц", "х", "ф", "т", "с","р", "п" , "б", "в", "г", "д", "ж", "з", "к", "л", "м", "н" };
	
	cout << endl;
	cout << "Тарабарская грамота" << endl;
	cout << "Введите текст для расшифровки:" << endl;
	char TARAB[100];
	cin.getline(TARAB, 100);

	vector< string > str3(strlen(TARAB));
	vector< string > cipher1(strlen(TARAB));

	for (int i = 0; i < (int)(strlen(TARAB)); i++)
	{
		str3[i] = TARAB[i];

	}

	for (int i = 0; i < (int)(strlen(TARAB)); i++)
	{
		for (int j = 0; j <= 19; j++) 
		{
			if (str3[i] == tarab1[j]) 
			{ 
				cipher1[i] = tarab2[j]; 
			}

		}
		if (str3[i] == " ") 
		{ 
			cipher1[i] = " "; 
		}
		if (str3[i] == ",") 
		{ 
			cipher1[i] = ","; 
		}
		if (str3[i] == "-")
		{ 
			cipher1[i] = "-"; 
		}
		if (str3[i] == "е" || str3[i] == "ё" || str3[i] == "у" || str3[i] == "ъ" || str3[i] == "ы" || str3[i] == "а" || str3[i] == "о" || str3[i] == "э" || str3[i] == "я" || str3[i] == "и" || str3[i] == "ь" || str3[i] == "ю" || str3[i] == "й")
		{
			cipher1[i] = str3[i];
		}

	}
	cout << "Результат расшифровки: " << endl;
	for (int i = 0; i < (int)(strlen(TARAB)); i++) {

		cout << cipher1[i];
	}
	cout << endl;
	cout << endl;

	cout << "Постолбцевая транспозиция" << endl;
	cout << "Введите текст для расшифровки:" << '\n';
	char stolb[100];
	cin.getline(stolb, 100);

	vector< string > str4(strlen(stolb));
	vector< string > cipher2(strlen(stolb));

	for (int i = 0; i < (int)(strlen(stolb)); i++)
	{
		str4[i] = stolb[i];

	}
	int n = 0;
	for (int i = 0; i < (int)(strlen(stolb)); i++)
	{
		if (str4[i] == " ")
		{
			break;
		}
		n++;
	}

	int m = ((strlen(stolb) + 1) / (n + 1));
	cout << "Прямоугольник " << n << " X " << m << endl;
	int f = 0;
	int x = 0;
	for (int i = 0; i < n; i++) 
	{
		f = i;
		for (int j = 0; j < m; j++) 
		{
			cipher2[x] = str4[f];
			f = f + n + 1;
			x++;
		}
	}

	cout << "Результат расшифровки: " << endl;
	for (int i = 0; i < (int)(strlen(stolb)); i++)
	{

		cout << cipher2[i];
	}
	cout << endl;
	system("pause");
	return 0;
}