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
	cout << "Введите путь до  файла: ";
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
		NULL, //дескриптор не может быть унаследован (Указатель на структуру SECURITY_ATTRIBUTES) 
		PAGE_READONLY, //только для чтения или копирования при записи 
		//Задает защиту страницы объекта сопоставления файлов 
		0, //максимальный размер объекта отображения файла 
		0, //max размер объекта сопоставления файлов равен текущему размеру файла 
		NULL);
	if (!hFileMappingFile) {
		cout << "error hFileMappingFile " << GetLastError() << endl;
		_getch();
		return -1;
	}

	char* (file);
	DWORD sizeFile = GetFileSize(File,
		0); //Указатель на переменную, в которой возвращается старшее двойное слово размера файла. 
	char* (result);
	
	HANDLE heapResult = HeapCreate(HEAP_NO_SERIALIZE,
		//Сериализованный доступ не используется, когда функции кучи обращаются к этой куче 
		//Варианты размещения кучи (влияют на последующий доступ к новой куче) 
		sizeFile, //Начальный размер кучи, в байтах 
		sizeFile); //Максимальный размер кучи в байтах.
	
	result = (char*)HeapAlloc(
		heapResult, //Дескриптор кучи, из которой будет выделена память. 
	//Этот дескриптор возвращается функцией HeapCreate. 
		NULL, //Варианты размещения кучи. 
		sizeFile);

	file = (char*)MapViewOfFile(hFileMappingFile, //Дескриптор объекта сопоставления файлов. 
	//Функции CreateFileMapping и OpenFileMapping возвращают этот дескриптор. 
		FILE_MAP_READ, //Тип доступа к объекту сопоставления файлов, который определяет защиту страниц 
		//Отображается только для чтения файла 
		0, // старшая и младшая части смещения начала отображаемого участка от начала файла 
		0, // 
		0); //размер отображаемого участка файла в байтах 
	DWORD buffout, b;

	for (int i = 0, j = 0; i < (sizeFile); i += 256, j += 256)
	{
		//копирование блока памяти 
		CopyMemory(&result[i], //адрес блока назначения 
			&file[j + 128], //адрес исходного блока 
			128); //размер копируемого блока 
		CopyMemory(&result[i + 128], &file[j], 128);
	}



	if (!WriteFile(hResult,
		result, //откуда
		sizeFile, //сколько
		&buffout, //куда
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

	cout << "Файл перемешан" << endl;

	system("pause");
	return 0;
}
