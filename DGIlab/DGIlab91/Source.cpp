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

	vector<string> alf1 = { "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�","�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�","�", "�", "�" };
	vector<string> alf2 = { "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�","�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�","�", "�", "�","�", "�", "�" };
	cout << "���� ������" << endl;
	cout << "������� ����� ��� �����������:" << endl;
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
	cout << "��������� �����������: " << endl;
	for (int i = 0; i < (int)(strlen(str2)); i++)
	{

		cout << cipher[i];
	}
	cout << endl;
	vector<string> tarab1 = { "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�","�", "�" };
	vector<string> tarab2 = { "�", "�", "�", "�", "�", "�", "�", "�","�", "�" , "�", "�", "�", "�", "�", "�", "�", "�", "�", "�" };
	
	cout << endl;
	cout << "����������� �������" << endl;
	cout << "������� ����� ��� �����������:" << endl;
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
		if (str3[i] == "�" || str3[i] == "�" || str3[i] == "�" || str3[i] == "�" || str3[i] == "�" || str3[i] == "�" || str3[i] == "�" || str3[i] == "�" || str3[i] == "�" || str3[i] == "�" || str3[i] == "�" || str3[i] == "�" || str3[i] == "�")
		{
			cipher1[i] = str3[i];
		}

	}
	cout << "��������� �����������: " << endl;
	for (int i = 0; i < (int)(strlen(TARAB)); i++) {

		cout << cipher1[i];
	}
	cout << endl;
	cout << endl;

	cout << "������������ ������������" << endl;
	cout << "������� ����� ��� �����������:" << '\n';
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
	cout << "������������� " << n << " X " << m << endl;
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

	cout << "��������� �����������: " << endl;
	for (int i = 0; i < (int)(strlen(stolb)); i++)
	{

		cout << cipher2[i];
	}
	cout << endl;
	system("pause");
	return 0;
}