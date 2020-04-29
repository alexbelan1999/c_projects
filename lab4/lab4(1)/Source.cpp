#include <windows.h>
#include <iostream>
#include <vector>
#include <dos.h>
#include <cstdlib>

using namespace std;
HANDLE hMutex;
DWORD WINAPI ThreadProc(CONST LPVOID lpParam);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hThread = NULL;
	CONST HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int signal = 0;
	bool flag = true;
	while (flag)
	{
		cout << "������� ����������� ������: 1 - ��������� �����, 2 - ����������, 3 - ����������, 4 - ��������� ������ ������" << endl;
		cin >> signal;
		switch (signal)
		{
			case 1:
			{
				hThread = CreateThread(NULL, 0, &ThreadProc, NULL, 0, NULL);
				if (NULL == hThread) {
					cout << "����� �� ������!" << endl;
					flag = false;
				}
				break;
			}
			case 2:
			{
				int res = SuspendThread(hThread);
				if (res == -1) {
					cout << "������ ��������������� ������!" << endl;
				}
				break;
			}
			case 3:
			{
				int res = ResumeThread(hThread);
				if (res == -1) {
					cout << "������ �������������� ������!" << endl;
				}
				break;
			}
			case 4:
			{
				int res = TerminateThread(hThread, 0);
				if (res == 0) {
					cout << "������ ���������� ������ ������!" << endl;
				}
				flag = false;
				break;
			}
			default:
			{
				cout << "������� ������������ �����!" << endl;
				
			}
		}
	}
	WaitForMultipleObjects(1, &hThread, TRUE, INFINITE);
	CloseHandle(hThread);
	CloseHandle(hMutex);
	system("pause");
	ExitProcess(0);
}

DWORD WINAPI ThreadProc(CONST LPVOID lpParam) {
	while (true)
	{
		Beep(247, 500);
		Beep(417, 500);
		Beep(417, 500);
		Beep(370, 500);
		Beep(417, 500);
		Beep(329, 500);
		Beep(247, 500);
		Beep(247, 500);
		Beep(247, 500);
		Beep(417, 500);
		Beep(417, 500);
		Beep(370, 500);
		Beep(417, 500);
		Beep(497, 500);
		//Sleep(500);
		Beep(497, 500);
		Beep(277, 500);
		Beep(277, 500);
		Beep(440, 500);
		Beep(440, 500);
		Beep(417, 500);
		Beep(370, 500);
		Beep(329, 500);
		Beep(247, 500);
		Beep(417, 500);
		Beep(417, 500);
		Beep(370, 500);
		Beep(417, 500);
		Beep(329, 500);
	}
	ExitThread(0);

}
