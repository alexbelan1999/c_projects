#include<iostream>
#include<windows.h> 
#include<tchar.h> 
using namespace std;
int main()
{
	setlocale(0, "");
	HANDLE hFile;
	char name[MAX_PATH] = "file.txt";
	hFile = CreateFile(name, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		cerr << "������ �������� �����" << endl;
		system("pause");
		return 1;
	}
	HANDLE hFileMapping;
	hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY,
		0, 0, NULL);
	if (!hFileMapping) {
		cerr << "������ �������� �����" << endl;
		system("pause");
		return 1;
	}
	char* file;
	file = (char*)MapViewOfFile(hFileMapping, FILE_MAP_READ, 0,
		0, 0);
	int count_a = 0;
	int viewsize = GetFileSize(hFile, 0);
	for (int i = 0; i < viewsize; i++)
		if (file[i] == 'a') count_a++;
	cout << "� ����� ������������ " << count_a << " ���� \"a\""
		<< endl;
	UnmapViewOfFile((LPVOID)file);
	CloseHandle(hFileMapping);
	CloseHandle(hFile);

	system("pause");
	return 0;
}

