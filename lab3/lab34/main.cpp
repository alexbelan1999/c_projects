#include <windows.h>
#include <cstdlib>
#include <string>
#define idFileExplorer 1
#define idTotalCommander 2 
#define idGoogle 3
#define idAcrobatReader 4

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
	hWnd = CreateWindow("MyWindowClass", "Задание4", WS_SYSMENU | WS_MINIMIZEBOX, 150, 100, 386, 154, HWND_DESKTOP, NULL, hInstance, NULL);

	if (!hWnd)
	{
		MessageBox(NULL, "Окно не было создано!", "Ошибка", MB_OK);
		return 0;
	}
	/*RECT win;
	GetClientRect(hWnd, &win);
	char str[50], str1[10], str2[10], str3[10], str4[10];

	_itoa_s(win.left, str1, 10);
	_itoa_s(win.right, str2, 10);
	_itoa_s(win.bottom, str3, 10);
	_itoa_s(win.top, str4, 10);
	MessageBox(NULL, str1,"left", MB_OK);
	MessageBox(NULL, str2, "right", MB_OK);
	MessageBox(NULL, str3, "bottom", MB_OK);
	MessageBox(NULL, str4, "top", MB_OK);*/

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
		static HBITMAP fileexplore,totalcommander,google,acrobatreader;
		static HWND button1, button2, button3, button4;
	case WM_CREATE:
	{

		HINSTANCE hInst;
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		fileexplore = (HBITMAP)LoadImage(NULL, "fe.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		button1 = CreateWindow("BUTTON", "Открытие архива", WS_CHILD | WS_VISIBLE | BS_VCENTER | BS_BITMAP,
			20, 20,
			75, 75,
			hwnd,
			(HMENU)idFileExplorer,
			hInst,
			NULL
		);

		SendMessage(button1, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)fileexplore);

		totalcommander = (HBITMAP)LoadImage(NULL, "tc.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		button2 = CreateWindow("BUTTON", "Открытие архива", WS_CHILD | WS_VISIBLE | BS_VCENTER | BS_BITMAP,
			105, 20,
			75, 75,
			hwnd,
			(HMENU)idTotalCommander,
			hInst,
			NULL
		);

		SendMessage(button2, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)totalcommander);

		google = (HBITMAP)LoadImage(NULL, "chrome.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		button3 = CreateWindow("BUTTON", "Открытие архива", WS_CHILD | WS_VISIBLE | BS_VCENTER | BS_BITMAP,
			190, 20,
			75, 75,
			hwnd,
			(HMENU)idGoogle,
			hInst,
			NULL
		);

		SendMessage(button3, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)google);

		acrobatreader = (HBITMAP)LoadImage(NULL, "ar.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		button4 = CreateWindow("BUTTON", "Открытие архива", WS_CHILD | WS_VISIBLE | BS_VCENTER | BS_BITMAP,
			275, 20,
			75, 75,
			hwnd,
			(HMENU)idAcrobatReader,
			hInst,
			NULL
		);

		SendMessage(button4, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)acrobatreader);

		break;
	}

	case WM_COMMAND:
	{


		if (HIWORD(wParam) == BN_CLICKED)
			switch (LOWORD(wParam))
			{

			case idFileExplorer: {
				STARTUPINFO info = { sizeof(info) };
				PROCESS_INFORMATION processInfo;

				if (CreateProcessA(NULL, (LPSTR)"C:\\Windows\\explorer.exe", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
				{

				}
				else
				{
					MessageBoxA(NULL, (LPSTR)"Error", "Error", MB_OK);
				}

				break;
			}
			case idTotalCommander: {
				STARTUPINFO info = { sizeof(info) };
				PROCESS_INFORMATION processInfo;

				if (CreateProcessA(NULL, (LPSTR)"C:\\Program Files (x86)\\Total Commander\\TOTALCMD64.EXE", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
				{

				}
				else
				{
					MessageBoxA(NULL, (LPSTR)"Error", "Error", MB_OK);
				}

				break;
			}

			case idGoogle: {
				STARTUPINFO info = { sizeof(info) };
				PROCESS_INFORMATION processInfo;

				if (CreateProcessA(NULL, (LPSTR)"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
				{

				}
				else
				{
					MessageBoxA(NULL, (LPSTR)"Error", "Error", MB_OK);
				}

				break;
			}

			case idAcrobatReader: {
				STARTUPINFO info = { sizeof(info) };
				PROCESS_INFORMATION processInfo;

				if (CreateProcessA(NULL, (LPSTR)"C:\\Program Files (x86)\\Adobe\\Acrobat Reader DC\\Reader\\AcroRd32.exe", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
				{

				}
				else
				{
					MessageBoxA(NULL, (LPSTR)"Error", "Error", MB_OK);
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
