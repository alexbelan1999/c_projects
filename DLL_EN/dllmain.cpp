// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "stdafx.h"
#include "resource.h"
#include <iostream>
#include <Windows.h>

__declspec(dllexport) HICON hIcon1;


using namespace std;

extern "C" __declspec(dllexport) LPCSTR text = "Enter text";
extern "C" __declspec(dllexport) LPCSTR substr = "Enter substring";
extern "C" __declspec(dllexport) LPCSTR calc = "Calculate";
extern "C" __declspec(dllexport) LPCSTR result = "Result";

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH: {
		hIcon1 = LoadIcon(hModule, MAKEINTRESOURCE(IDI_ICON1));
		break;
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH: {
		DestroyIcon(hIcon1);
		break;
	}
	}
	return TRUE;
}


