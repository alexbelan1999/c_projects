#include <windows.h>
#include <cstdlib>
#include <iostream>
using namespace std;

#define idText 1

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
		"Задание 2.3",	
		WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME,
		300, 
		200, 
		500, 
		300,
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
			"Задание 2.3", 
			WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, 
			10, 10,
			480, 280,
			hwnd,
			NULL, 
			hInst, 
			NULL
		);

	case WM_COMMAND:
	{

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
}
