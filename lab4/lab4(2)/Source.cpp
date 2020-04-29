#include <windows.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
HANDLE TableSem,EmptySem, Smoker1Thread, Smoker2Thread, Smoker3Thread, MiddlemanThread;
bool tobacco = false, paper = false, matches = false;
CONST HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);	

DWORD WINAPI Smoker1Proc(CONST LPVOID lpParam);
DWORD WINAPI Smoker2Proc(CONST LPVOID lpParam);
DWORD WINAPI Smoker3Proc(CONST LPVOID lpParam);
DWORD WINAPI MiddlemanProc(CONST LPVOID lpParam);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "�������� ������� ������ ������ ��������! ��������� ����������� � ����������." << endl;
	
	/*EmptySem = CreateSemaphore(NULL, 1, 1, NULL);
	if (NULL == EmptySem) {
		cout << "Failed to create semaphore." << endl;
	}
	WaitForSingleObject(EmptySem, INFINITE);*/

	MiddlemanThread = CreateThread(NULL, 0, &MiddlemanProc, NULL, 0, NULL);
	if (NULL == MiddlemanThread) {
		cout<<"Failed to create thread."<<endl;
	}
	

	TableSem = CreateSemaphore(NULL, 1, 1, NULL);
	if (NULL == TableSem) {
		cout << "Failed to create semaphore." << endl;
	}
	WaitForSingleObject(TableSem, INFINITE);

	Smoker1Thread = CreateThread(NULL, 0, &Smoker1Proc, NULL, 0, NULL);
	if (NULL == Smoker1Thread) {
		cout << "Failed to create thread." << endl;
	}
	Smoker2Thread = CreateThread(NULL, 0, &Smoker2Proc, NULL, 0, NULL);
	if (NULL == Smoker2Thread) {
		cout << "Failed to create thread." << endl;
	}
	Smoker3Thread = CreateThread(NULL, 0, &Smoker3Proc, NULL, 0, NULL);
	if (NULL == Smoker3Thread) {
		cout << "Failed to create thread." << endl;
	}
	WaitForSingleObject(MiddlemanThread, INFINITE);
	WaitForSingleObject(Smoker1Thread, INFINITE);
	WaitForSingleObject(Smoker2Thread, INFINITE);
	WaitForSingleObject(Smoker3Thread, INFINITE);
	//Sleep(100);
	CloseHandle(EmptySem);
	CloseHandle(TableSem);
	CloseHandle(MiddlemanThread);
	CloseHandle(Smoker1Thread);
	CloseHandle(Smoker2Thread);
	CloseHandle(Smoker3Thread);

	system("pause");
	ExitProcess(0);
}
DWORD WINAPI MiddlemanProc(CONST LPVOID lpParam) {
	
	while (true) 
	{
		//ReleaseSemaphore(EmptySem, 1, NULL);
		ReleaseSemaphore(TableSem, 1, NULL);
		//WaitForSingleObject(EmptySem, INFINITE);
		WaitForSingleObject(TableSem, INFINITE);
		cout << "�������� ���������. ";
		Sleep(10);
		int n1 = 0, n2 = 0;
		srand(time(NULL));
		n1 = rand() % 3 + 1;
		n2 = rand() % 3 + 1;
		while (n1 == n2)
		{
			n2 = rand() % 3 + 1;
		}
		//cout << n1 << " " << n2;
		if (((n1 == 1) && (n2 == 2)) || ((n2 == 1) && (n1 == 2)))
		{
			cout << "������� ����� � ������.";
			Sleep(10);
			tobacco = true;
			paper = true;
		}
		if (((n1 == 1) && (n2 == 3)) || ((n2 == 1) && (n1 == 3)))
		{
			cout << "������� ����� � ������.";
			Sleep(10);
			tobacco = true;
			matches = true;
		}
		if (((n1 == 2) && (n2 == 3)) || ((n2 == 2) && (n1 == 3)))
		{
			cout << "������� ������ � ������.";
			Sleep(10);
			paper = true;
			matches = true;
		}
		cout << "�������� ������." << endl;
		Sleep(1000);
		//ReleaseSemaphore(EmptySem, 1, NULL);
		//ReleaseSemaphore(TableSem, 1, NULL);
	}
	ExitThread(0);
}
DWORD WINAPI Smoker1Proc(CONST LPVOID lpParam) {
	while (true) 
	{	
		//WaitForSingleObject(EmptySem, INFINITE);
		WaitForSingleObject(TableSem, INFINITE);
		cout << "�������� ��������� 1. ���� �����. ";
		Sleep(10);
		if ((paper == true) && (matches == true))
		{
			cout << "���� ������ � ������. ������� ��������. �������.";
			Sleep(10);
			paper = false;
			matches = false;
		}
		else
		{
			cout << "�� ������� ������ � ������!";
			Sleep(10);
		}
		cout << "��������� 1 �������� ������." << endl;
		Sleep(1000);
		ReleaseSemaphore(TableSem, 1, NULL);
		//ReleaseSemaphore(EmptySem, 1, NULL);

	}
	ExitThread(0);
}
DWORD WINAPI Smoker2Proc(CONST LPVOID lpParam) {
	while (true) 
	{
		//ReleaseSemaphore(TableSem, 1, NULL);
		//WaitForSingleObject(EmptySem, INFINITE);
		WaitForSingleObject(TableSem, INFINITE);
		cout << "�������� ��������� 2. ���� ������. ";
		Sleep(10);
		if ((tobacco == true) && (matches == true))
		{
			cout << "���� ����� � ������. ������� ��������. �������.";
			Sleep(10);
			tobacco = false;
			matches = false;
		}
		else
		{
			cout << "�� ������� ������ � ������!";
			Sleep(10);
		}
		cout << "��������� 2 �������� ������." << endl;
		Sleep(1000);
		ReleaseSemaphore(TableSem, 1, NULL);
		//ReleaseSemaphore(EmptySem, 1, NULL);

	}
	ExitThread(0);
}
DWORD WINAPI Smoker3Proc(CONST LPVOID lpParam) {
	while (true) 
	{
		//ReleaseSemaphore(TableSem, 1, NULL);
		//WaitForSingleObject(EmptySem, INFINITE);
		WaitForSingleObject(TableSem, INFINITE);
		cout << "�������� ��������� 3. ���� ������. ";
		Sleep(10);
		if ((tobacco == true) && (paper == true))
		{
			cout << "���� ����� � ������. ������� ��������. �������.";
			Sleep(10);
			tobacco = false;
			paper = false;
		}
		else
		{
			cout << "�� ������� ������ � ������!";
			Sleep(10);
		}
		cout << "��������� 3 �������� ������." << endl;
		Sleep(1000);
		ReleaseSemaphore(TableSem, 1, NULL);
		//ReleaseSemaphore(EmptySem, 1, NULL);

	}
	ExitThread(0);
}