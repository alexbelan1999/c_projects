#include <windows.h>
#include <cstdlib>
#include <string>
#define idExcel 1

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
	hWnd = CreateWindow("MyWindowClass","Задание1",WS_SYSMENU | WS_MINIMIZEBOX,200,100,500,300,HWND_DESKTOP,NULL,hInstance,NULL);

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
		static HBITMAP excel;
		static HWND button;
	case WM_CREATE:
	{

		HINSTANCE hInst;
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;
		excel = (HBITMAP)LoadImage(NULL,"excel.bmp",IMAGE_BITMAP,0, 0,LR_LOADFROMFILE);

		button = CreateWindow("BUTTON","Запустить Excel",WS_CHILD | WS_VISIBLE | BS_VCENTER | BS_BITMAP ,
			100, 90,
			250, 150,
			hwnd,
			(HMENU)idExcel,
			hInst,
			NULL
		);

		SendMessage(button, BM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)excel);

		break;
	}

	case WM_COMMAND:
	{


		if (HIWORD(wParam) == BN_CLICKED)
			switch (LOWORD(wParam))
			{

			case idExcel: {
				STARTUPINFO info = { sizeof(info) };
				PROCESS_INFORMATION processInfo;

				if (CreateProcessA(NULL, (LPSTR)"C:\\Program Files (x86)\\Microsoft Office\\Office16\\EXCEL.EXE", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
				{
					MessageBoxA(NULL, (LPSTR)("Process handle: " + std::to_string((long)processInfo.hProcess) + "; Process ID: " + std::to_string(processInfo.dwProcessId)).c_str(), "Info", MB_ICONWARNING);
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
