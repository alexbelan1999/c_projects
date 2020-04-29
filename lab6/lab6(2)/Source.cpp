#include<iostream>
#include<windows.h> 
#include<tchar.h> 
#include<string>
#include<conio.h>
using namespace std;

string getFileType(string path) {
	return path.substr(path.find_last_of("."));
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string file1;
	cout << "������� ���� ��  �����: ";
	cin >> file1;

	string resFileType = getFileType(file1);

	HANDLE File = CreateFile(file1.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (!File) {
		cout << "File  don't found" << endl;
		_getch();
		return -1;
	}

	string resFileName = "result" + resFileType;

	HANDLE hResult = CreateFile(resFileName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (!hResult) {
		cout << "result error # " << GetLastError() << endl;
		_getch();
		return -1;
	}
	

	HANDLE hFileMappingFile = CreateFileMapping(File,
		NULL, //���������� �� ����� ���� ����������� (��������� �� ��������� SECURITY_ATTRIBUTES) 
		PAGE_READONLY, //������ ��� ������ ��� ����������� ��� ������ 
		//������ ������ �������� ������� ������������� ������ 
		0, //������������ ������ ������� ����������� ����� 
		0, //max ������ ������� ������������� ������ ����� �������� ������� ����� 
		NULL);
	if (!hFileMappingFile) {
		cout << "error hFileMappingFile " << GetLastError() << endl;
		_getch();
		return -1;
	}

	char* (file);
	DWORD sizeFile = GetFileSize(File,
		0); //��������� �� ����������, � ������� ������������ ������� ������� ����� ������� �����. 
	char* (result);
	
	HANDLE heapResult = HeapCreate(HEAP_NO_SERIALIZE,
		//��������������� ������ �� ������������, ����� ������� ���� ���������� � ���� ���� 
		//�������� ���������� ���� (������ �� ����������� ������ � ����� ����) 
		sizeFile, //��������� ������ ����, � ������ 
		sizeFile); //������������ ������ ���� � ������.
	
	result = (char*)HeapAlloc(
		heapResult, //���������� ����, �� ������� ����� �������� ������. 
	//���� ���������� ������������ �������� HeapCreate. 
		NULL, //�������� ���������� ����. 
		sizeFile);

	file = (char*)MapViewOfFile(hFileMappingFile, //���������� ������� ������������� ������. 
	//������� CreateFileMapping � OpenFileMapping ���������� ���� ����������. 
		FILE_MAP_READ, //��� ������� � ������� ������������� ������, ������� ���������� ������ ������� 
		//������������ ������ ��� ������ ����� 
		0, // ������� � ������� ����� �������� ������ ������������� ������� �� ������ ����� 
		0, // 
		0); //������ ������������� ������� ����� � ������ 
	DWORD buffout, b;

	for (int i = 0, j = 0; i < (sizeFile); i += 256, j += 256)
	{
		//����������� ����� ������ 
		CopyMemory(&result[i], //����� ����� ���������� 
			&file[j + 128], //����� ��������� ����� 
			128); //������ ����������� ����� 
		CopyMemory(&result[i + 128], &file[j], 128);
	}



	if (!WriteFile(hResult,
		result, //������
		sizeFile, //�������
		&buffout, //����
		NULL)) {
	}


	
	if (!HeapDestroy(heapResult))
	{
		cout << "HeapDestroy " << GetLastError() << endl;
		_getch();
		return -1;
	}

	UnmapViewOfFile(file);

	CloseHandle(hFileMappingFile);


	CloseHandle(File);
	CloseHandle(hResult);

	cout << "���� ���������" << endl;

	system("pause");
	return 0;
}
