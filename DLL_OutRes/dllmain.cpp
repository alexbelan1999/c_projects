#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include "stdafx.h"

using namespace std;

extern"C" __declspec(dllexport) int outRes(char str[], char substr[])
{
	int k = 0, cnt = 0;
	char bufRes[100] = "";
	int const la = strlen(str);
	int const lb = strlen(substr);
	for (int i = 0; i < la; i++) {
		char tmp[256] = "";
		k = 0;
		if (str[i] == substr[0]) {
			int j = i;
			while (str[j] == substr[k]) {
				tmp[k] = str[j];
				j++; k++;
			}
			if (substr[i] == substr[i + 1]) {
				i = i + k - 1;
			}
			if (strcmp(substr, tmp) == 0) { cnt++; }
		}
		//i = i + k - 1;


	}
	return cnt;

}

BOOL WINAPI DLLMain(
	HINSTANCE hinstDll,
	DWORD fdwReason,
	LPVOID lpvReserved
) {
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;

}