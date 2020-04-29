// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;

extern "C" __declspec(dllexport) char Message[] = "Hello World!";
extern "C" __declspec(dllexport) void SayMessage(char* message) 
{
	cout << "DLL say> " << message << endl;
	return;
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
