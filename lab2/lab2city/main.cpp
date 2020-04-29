#include <windows.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>
LRESULT CALLBACK DCDemoWndProc(HWND, UINT, UINT, LONG);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
	HWND hWnd;
	WNDCLASS WndClass;
	MSG Msg;
	char szClassName[] = "City";

	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = DCDemoWndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = "City";
	WndClass.lpszClassName = szClassName;

	if (!RegisterClass(&WndClass)) {
		MessageBox(NULL, "Can't register class!", "ERR!", MB_OK);
		return 0;
	}
	//RECT window_rect = { 50,50,710,710 };
	//AdjustWindowRectEx(&window_rect, WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX, FALSE,NULL);
	hWnd = CreateWindowEx(NULL,szClassName, "Building plan", WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX, 100,
		10, 676, 699, NULL, NULL, hInstance, NULL);
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
	if (!hWnd) {
		MessageBox(NULL, "Окно не создано!", "Ошибка!", MB_OK);
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&Msg, NULL, 0, 0)) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return Msg.wParam;
}

LRESULT CALLBACK DCDemoWndProc(HWND hWnd, UINT Message, UINT wParam, LONG lParam) {
	HDC hDC, hCompatibleDC;
	PAINTSTRUCT PaintStruct;
	HANDLE hBitmap, hOldBitmap;
	RECT Rect;
	BITMAP Bitmap;


	static HBITMAP home1, home2, home3, home4, home5, home6;
	static int square[3][3] = {0};
	static HWND building1, building2, building3, building4, building5, building6, building7, building8, building9;
	switch (Message) {


	case WM_CREATE:
		home1 = (HBITMAP)LoadImage(NULL, "h1.bmp", IMAGE_BITMAP, 180, 180, LR_LOADFROMFILE);
		home2 = (HBITMAP)LoadImage(NULL, "h2.bmp", IMAGE_BITMAP, 180, 180, LR_LOADFROMFILE);
		home3 = (HBITMAP)LoadImage(NULL, "h3.bmp", IMAGE_BITMAP, 180, 180, LR_LOADFROMFILE);
		home4 = (HBITMAP)LoadImage(NULL, "h4.bmp", IMAGE_BITMAP, 180, 180, LR_LOADFROMFILE);
		home5 = (HBITMAP)LoadImage(NULL, "h5.bmp", IMAGE_BITMAP, 180, 180, LR_LOADFROMFILE);
		home6 = (HBITMAP)LoadImage(NULL, "h6.bmp", IMAGE_BITMAP, 180, 180, LR_LOADFROMFILE);
		break;


	case WM_PAINT:

		hDC = BeginPaint(hWnd, &PaintStruct);

		hBitmap = LoadImage(NULL, "fon1.bmp", IMAGE_BITMAP, 660, 660, LR_LOADFROMFILE);/* загрузить bitmap который будет отображаться в окне из файла */
		if (!hBitmap) {
			MessageBox(NULL, "Файл не найден!", "Error", MB_OK);
			return 0;
		}

		GetObject(hBitmap, sizeof(BITMAP), &Bitmap);

		hCompatibleDC = CreateCompatibleDC(hDC);

		hOldBitmap = SelectObject(hCompatibleDC, hBitmap);

		GetClientRect(hWnd, &Rect);
		StretchBlt(hDC, 0, 0, Rect.right, Rect.bottom, hCompatibleDC, 0, 0, Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);

		SelectObject(hCompatibleDC, hOldBitmap);

		DeleteObject(hBitmap);

		DeleteDC(hCompatibleDC);

		EndPaint(hWnd, &PaintStruct);
		return 0;


	case WM_LBUTTONDOWN: {

		WORD xPos, yPos;

		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);

		//1
		if (xPos > 0 && xPos < 180 && yPos > 0 && yPos < 180) {

			if (square[0][0] != 0) {
				MessageBox(NULL, "Данное место занято другим зданием!", "Ошибка!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				if (square[0][0] == 0) {
					if (HIBYTE(GetKeyState(0x31))) {
						building1 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home1);
						square[0][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x32))) {
						building1 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home2);
						square[0][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x33))) {
						building1 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home3);
						square[0][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x34))) {
						building1 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home4);
						square[0][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x35))) {
						building1 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home5);
						square[0][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x36))) {
						building1 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home6);
						square[0][0] = 1;
						break;
					}
				}

			}

		}
		//2
		if (xPos > 240 && xPos < 420 && yPos > 0 && yPos < 180) {

			if (square[0][1] != 0) {
				MessageBox(NULL, "Данное место занято другим зданием!", "Ошибка!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				if (square[0][1] == 0) {
					if (HIBYTE(GetKeyState(0x31))) {
						building2 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home1);
						square[0][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x32))) {
						building2 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home2);
						square[0][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x33))) {
						building2 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home3);
						square[0][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x34))) {
						building2 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home4);
						square[0][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x35))) {
						building2 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home5);
						square[0][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x36))) {
						building2 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home6);
						square[0][1] = 1;
						break;
					}
				}

			}

		}
		//3
		if (xPos > 480 && xPos < 660 && yPos > 0 && yPos < 180) {

			if (square[0][2] != 0) {
				MessageBox(NULL, "Данное место занято другим зданием!", "Ошибка!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				if (square[0][2] == 0) {
					if (HIBYTE(GetKeyState(0x31))) {
						building3 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building3, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home1);
						square[0][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x32))) {
						building3 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building3, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home2);
						square[0][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x33))) {
						building3 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building3, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home3);
						square[0][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x34))) {
						building3 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building3, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home4);
						square[0][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x35))) {
						building3 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building3, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home5);
						square[0][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x36))) {
						building3 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 0, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building3, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home6);
						square[0][2] = 1;
						break;
					}
				}

			}

		}
		//4
		if (xPos > 0 && xPos < 180 && yPos > 240 && yPos < 420) {

			if (square[1][0] != 0) {
				MessageBox(NULL, "Данное место занято другим зданием!", "Ошибка!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				if (square[1][0] == 0) {
					if (HIBYTE(GetKeyState(0x31))) {
						building4 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building4, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home1);
						square[1][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x32))) {
						building4 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building4, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home2);
						square[1][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x33))) {
						building4 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building4, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home3);
						square[1][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x34))) {
						building4 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building4, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home4);
						square[1][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x35))) {
						building4 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building4, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home5);
						square[1][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x36))) {
						building4 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building4, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home6);
						square[1][0] = 1;
						break;
					}
				}

			}

		}
		//5
		if (xPos > 240 && xPos < 420 && yPos > 240 && yPos < 420) {

			if (square[1][1] != 0) {
				MessageBox(NULL, "Данное место занято другим зданием!", "Ошибка!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				if (square[1][1] == 0) {
					if (HIBYTE(GetKeyState(0x31))) {
						building5 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building5, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home1);
						square[1][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x32))) {
						building5 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building5, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home2);
						square[1][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x33))) {
						building5 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building5, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home3);
						square[1][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x34))) {
						building5 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building5, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home4);
						square[1][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x35))) {
						building5 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building5, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home5);
						square[1][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x36))) {
						building5 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building5, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home6);
						square[1][1] = 1;
						break;
					}
				}

			}

		}
		//6
		if (xPos > 480 && xPos < 660 && yPos > 240 && yPos < 420) {

			if (square[1][2] != 0) {
				MessageBox(NULL, "Данное место занято другим зданием!", "Ошибка!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				if (square[1][2] == 0) {
					if (HIBYTE(GetKeyState(0x31))) {
						building6 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building6, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home1);
						square[1][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x32))) {
						building6 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building6, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home2);
						square[1][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x33))) {
						building6 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building6, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home3);
						square[1][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x34))) {
						building6 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building6, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home4);
						square[1][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x35))) {
						building6 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building6, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home5);
						square[1][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x36))) {
						building6 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 240, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building6, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home6);
						square[1][2] = 1;
						break;
					}
				}

			}

		}
		//7
		if (xPos > 0 && xPos < 180 && yPos > 480 && yPos < 660) {

			if (square[2][0] != 0) {
				MessageBox(NULL, "Данное место занято другим зданием!", "Ошибка!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				if (square[2][0] == 0) {
					if (HIBYTE(GetKeyState(0x31))) {
						building7 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building7, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home1);
						square[2][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x32))) {
						building7 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building7, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home2);
						square[2][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x33))) {
						building7 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building7, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home3);
						square[2][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x34))) {
						building7 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building7, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home4);
						square[2][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x35))) {
						building7 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building7, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home5);
						square[2][0] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x36))) {
						building7 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 0, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building7, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home6);
						square[2][0] = 1;
						break;
					}
				}

			}

		}
		//8
		if (xPos > 240 && xPos < 420 && yPos > 480 && yPos < 660) {

			if (square[2][1] != 0) {
				MessageBox(NULL, "Данное место занято другим зданием!", "Ошибка!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				if (square[2][1] == 0) {
					if (HIBYTE(GetKeyState(0x31))) {
						building8 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building8, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home1);
						square[2][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x32))) {
						building8 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building8, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home2);
						square[2][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x33))) {
						building8 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building8, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home3);
						square[2][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x34))) {
						building8 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building8, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home4);
						square[2][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x35))) {
						building8 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building8, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home5);
						square[2][1] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x36))) {
						building8 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 240, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building8, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home6);
						square[2][1] = 1;
						break;
					}
				}

			}

		}
		//9
		if (xPos > 480 && xPos < 660 && yPos > 480 && yPos < 660) {

			if (square[2][2] != 0) {
				MessageBox(NULL, "Данное место занято другим зданием!", "Ошибка!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				if (square[2][2] == 0) {
					if (HIBYTE(GetKeyState(0x31))) {
						building9 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building9, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home1);
						square[2][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x32))) {
						building9 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building9, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home2);
						square[2][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x33))) {
						building9 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building9, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home3);
						square[2][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x34))) {
						building9 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building9, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home4);
						square[2][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x35))) {
						building9 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building9, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home5);
						square[2][2] = 1;
						break;
					}

					if (HIBYTE(GetKeyState(0x36))) {
						building9 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 480, 480, 180, 180, hWnd, NULL, NULL, NULL);
						SendMessageW(building9, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)home6);
						square[2][2] = 1;
						break;
					}
				}

			}

		}
		return 0;
	}



	case WM_RBUTTONDOWN: {

		WORD xPos, yPos;

		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);

		//1
		if (xPos > 0 && xPos < 180 && yPos > 0 && yPos < 180) {
			if (square[0][0] != 0) {
				int result = DestroyWindow(building1);
				square[0][0] = 0;
			}
			else
			{
				MessageBox(NULL, "Тут ничего нет!", "Ошибка!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		//2
		if (xPos > 180 && xPos < 420 && yPos > 0 && yPos < 180) {
			if (square[0][1] != 0) {
				int result = DestroyWindow(building2);
				square[0][1] = 0;
			}
			else
			{
				MessageBox(NULL, "Тут ничего нет!", "Ошибка!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		//3
		if (xPos > 480 && xPos < 660 && yPos > 0 && yPos < 180) {
			if (square[0][2] != 0) {
				int result = DestroyWindow(building3);
				square[0][2] = 0;
			}
			else
			{
				MessageBox(NULL, "Тут ничего нет!", "Ошибка!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		//4
		if (xPos > 0 && xPos < 180 && yPos > 240 && yPos < 420) {
			if (square[1][0] != 0) {
				int result = DestroyWindow(building4);
				square[1][0] = 0;
			}
			else
			{
				MessageBox(NULL, "Тут ничего нет!", "Ошибка!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		//5
		if (xPos > 240 && xPos < 420 && yPos > 240 && yPos < 420) {
			if (square[1][1] != 0) {
				int result = DestroyWindow(building5);
				square[1][1] = 0;
			}
			else
			{
				MessageBox(NULL, "Тут ничего нет!", "Ошибка!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		//6
		if (xPos > 480 && xPos < 660 && yPos > 240 && yPos < 420) {
			if (square[1][2] != 0) {
				int result = DestroyWindow(building6);
				square[1][2] = 0;
			}
			else
			{
				MessageBox(NULL, "Тут ничего нет!", "Ошибка!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		//7
		if (xPos > 0 && xPos < 180 && yPos > 480 && yPos < 660) {
			if (square[2][0] != 0) {
				int result = DestroyWindow(building7);
				square[2][0] = 0;
			}
			else
			{
				MessageBox(NULL, "Тут ничего нет!", "Ошибка!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		//8
		if (xPos > 240 && xPos < 420 && yPos > 480 && yPos < 660) {
			if (square[2][1] != 0) {
				int result = DestroyWindow(building8);
				square[2][1] = 0;
			}
			else
			{
				MessageBox(NULL, "Тут ничего нет!", "Ошибка!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		//9
		if (xPos > 480 && xPos < 660 && yPos > 480 && yPos < 660) {
			if (square[2][2] != 0) {
				int result = DestroyWindow(building9);
				square[2][2] = 0;
			}
			else
			{
				MessageBox(NULL, "Тут ничего нет!", "Ошибка!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		return 0;


	}

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, Message, wParam, lParam);
}