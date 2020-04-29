#include <Windows.h>
#include <iostream>


using namespace std;

int main() {
	HMODULE hMyDll;
	void(*Say)(char*);
	char* word;

	hMyDll = LoadLibrary("MyDLL");
	if (hMyDll == NULL) {
		wcerr << L"error load" << endl;
		system("pause");
		return 3;
	}

	word = (char*)GetProcAddress(hMyDll, "Message");

	if (!word) {
		wcerr << L"error mes" << endl;
		system("pause");
		return 4;
	}

	Say = (void(*)(char*))GetProcAddress(hMyDll, "SayMessage");
	if (!Say) {
		wcerr << L"error fun" << endl;
		system("pause");
		return 5;
	}

	Say(word);

	system("pause");

	FreeLibrary(hMyDll);


}