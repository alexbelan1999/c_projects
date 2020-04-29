#include <windows.h>
#include <cstdlib>
#include <iostream>
using namespace std;

#define idText 1

#define idSubStr 2
#define idEntryBtn 3
#define idEntry 4

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{

	WNDCLASS wcl;
	ZeroMemory(&wcl, sizeof(WNDCLASS));

	wcl.hInstance = hInstance;
	wcl.lpszClassName = "MyWindowClass";
	wcl.lpfnWndProc = WndProc;
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpszMenuName = NULL;
	wcl.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)(+COLOR_WINDOW);
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;

	if (!RegisterClass(&wcl))
	{
		MessageBox(NULL, "Класс окна не был создан!", "Ошибка", MB_ICONERROR);
		return 0;
	}
	HWND hWnd;
	hWnd = CreateWindow(
		"MyWindowClass",
		"Программа для подсчета числа вхождений подстрок в текст",	
		WS_SYSMENU | WS_MINIMIZEBOX, 	
		300, 
		200,
		600, 
		400, 
		HWND_DESKTOP,
		NULL,	
		hInstance,	
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL, "Окно не было создано!", "Ошибка", MB_ICONERROR);
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);



	MSG msg;	
	ZeroMemory(&msg, sizeof(MSG));

	while (GetMessage(&msg, NULL, 0, 0))	
	{
		TranslateMessage(&msg);	
		DispatchMessage(&msg); 
	}

	return 0;
}




void outRes(HWND hWnd, char str[], char substr[])
{
	HWND hEditEntry = GetDlgItem(hWnd, idEntry);
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
			if (strcmp(substr, tmp) == 0) { cnt++;}
		}
		
	
	}
	_itoa_s(cnt, bufRes, 10);
	SetWindowText(hEditEntry, bufRes);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg)
	{
	case WM_CREATE:
	{

		HINSTANCE hInst;
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;

		CreateWindow(
			"STATIC", 
			"Введите текст: ", 
			WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE, 
			10, 10, 
			120, 20, 
			hwnd,
			NULL, 
			hInst, 
			NULL
		);

		CreateWindow(
			"EDIT",
			NULL, 
			WS_CHILD | WS_BORDER | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL, 
			170, 10, 
			375, 175, 
			hwnd,
			(HMENU)idText, 
			hInst,
			NULL
		);

		CreateWindow(
			"STATIC", 
			"Введите подстроку: ", 
			WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE, 
			10, 200, 
			140, 20,
			hwnd,
			NULL, 
			hInst, 
			NULL 
		);

		CreateWindow(
			"EDIT", 
			NULL, 
			WS_CHILD | WS_BORDER | WS_VISIBLE, 
			170, 200, 
			375, 30,
			hwnd, 
			(HMENU)idSubStr,
			hInst, 
			NULL
		);

		CreateWindow(
			"BUTTON",
			"Подсчитать",
			WS_CHILD | WS_VISIBLE | BS_VCENTER | BS_FLAT,
			235, 250,
			100, 40,
			hwnd,	
			(HMENU)idEntryBtn,
			hInst,
			NULL
		);

		CreateWindow(
			"STATIC", 
			"Результат: ", 
			WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, 
			10, 300,
			80, 20, 
			hwnd,
			NULL, 
			hInst, 
			NULL
		);
		CreateWindow(
			"STATIC", 
			NULL, 
			WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE, 
			105, 300, 
			120, 20, 
			hwnd,
			(HMENU)idEntry,
			hInst,
			NULL 
		);


		break;
	}

	case WM_COMMAND:
	{
		char inText[100] = "";
		char Substr[100] = "";
		HWND hEdit = GetDlgItem(hwnd, idText);
		HWND hEdit1 = GetDlgItem(hwnd, idSubStr);
		
		if (HIWORD(wParam) == BN_CLICKED)
			switch (LOWORD(wParam))
			{

			case idEntryBtn: {
				GetWindowText(hEdit, inText, 100);
				GetWindowText(hEdit1, Substr, 100);
				outRes(hwnd, inText, Substr);
				break;
			}

			}

		break;
	}

	case WM_DESTROY: 
	{
		PostQuitMessage(0);
		return 0;
		break;
	}
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}
