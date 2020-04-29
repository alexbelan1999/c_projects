#include <windows.h>
#include <cstdlib>
#include <string>
#include <shellapi.h>
#define idGoogle 1

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
	hWnd = CreateWindow("MyWindowClass", "Задание3", WS_SYSMENU | WS_MINIMIZEBOX, 200, 100, 500, 300, HWND_DESKTOP, NULL, hInstance, NULL);

	if (!hWnd)
	{
		MessageBox(NULL, "Окно не было создано!", "Ошибка", MB_OK);
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
		static HBITMAP google;
		static HWND button;
	case WM_CREATE:
	{

		HINSTANCE hInst;
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		google = (HBITMAP)LoadImage(NULL, "google.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		button = CreateWindow("BUTTON", "Открытие архива", WS_CHILD | WS_VISIBLE | BS_VCENTER | BS_BITMAP,
			100, 90,
			250, 150,
			hwnd,
			(HMENU)idGoogle,
			hInst,
			NULL
		);

		SendMessage(button, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)google);

		break;
	}

	case WM_COMMAND:
	{


		if (HIWORD(wParam) == BN_CLICKED)
			switch (LOWORD(wParam))
			{

			case idGoogle: {
				STARTUPINFO info = { sizeof(info) };
				PROCESS_INFORMATION processInfo;

				if ((int)ShellExecute(NULL,"open","https://sdo.vsu.by/" ,NULL,NULL, SW_SHOWNORMAL) <= 32)
				{
					MessageBoxA(NULL, (LPSTR)"Error", "Error", MB_ICONWARNING);
				}

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
