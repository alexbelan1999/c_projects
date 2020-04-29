#include <windows.h>

LRESULT CALLBACK DCDemoWndProc(HWND, UINT, UINT, LONG);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
	HWND hWnd;
	WNDCLASS WndClass;
	MSG Msg;
	char szClassName[] = "Dimon";

	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = DCDemoWndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = (HICON)LoadImage(hInstance, MAKEINTRESOURCE(110), IMAGE_ICON, 18, 18, 0);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = "ALMANAX";
	WndClass.lpszClassName = szClassName;

	if (!RegisterClass(&WndClass)) {
		MessageBox(NULL, "Can't register class!", "ERR!", MB_OK);
		return 0;
	}

	hWnd = CreateWindow(szClassName, "WARgaming", WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX, 20,
		20, 620, 720, NULL, NULL, hInstance, NULL);
	if (!hWnd) {
		MessageBox(NULL, "Can't create window!", "ERR!", MB_OK);
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


	static HBITMAP warriorImage, warriorImage2, warriorImage3;
	static int key1 = 0, key2 = 0, key3 = 0, key4 = 0, key5 = 0, key6 = 0;
	static HWND warrior1, warrior2, warrior3, warrior4, warrior5, warrior6;

	switch (Message) {


	case WM_CREATE:
		warriorImage = (HBITMAP)LoadImage(NULL, "unnit3.bmp", IMAGE_BITMAP, 155, 200, LR_LOADFROMFILE);
		warriorImage2 = (HBITMAP)LoadImage(NULL, "unnit2.bmp", IMAGE_BITMAP, 155, 200, LR_LOADFROMFILE);
		warriorImage3 = (HBITMAP)LoadImage(NULL, "unnit1.bmp", IMAGE_BITMAP, 155, 200, LR_LOADFROMFILE);
		break;


	case WM_PAINT:

		hDC = BeginPaint(hWnd, &PaintStruct);/* получить контекст устройства */

		hBitmap = LoadImage(NULL, "b.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);/* загрузить bitmap который будет отображатьс€ в окне из файла */
		if (!hBitmap) {
			MessageBox(NULL, "File not found!", "Error", MB_OK);
			return 0;
		}

		GetObject(hBitmap, sizeof(BITMAP), &Bitmap);/* получть размерность изображени€ */

		hCompatibleDC = CreateCompatibleDC(hDC);/* создать совместимый с контекстом окна контекст в пам€ти */

		hOldBitmap = SelectObject(hCompatibleDC, hBitmap);/* делаем загруженный битмап текущим в совместимом контексте */

		GetClientRect(hWnd, &Rect);/* определить размер рабочей области окна */
		StretchBlt(hDC, 0, 0, Rect.right, Rect.bottom, hCompatibleDC, 0, 0, Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);

		SelectObject(hCompatibleDC, hOldBitmap);/* вновь делаем старый битмап текущим */

		DeleteObject(hBitmap);/* удалить загруженный битмап */

		DeleteDC(hCompatibleDC);/* удалить совместимый контекст */

		EndPaint(hWnd, &PaintStruct); /*освободить основной контекст, заверша€ перерисовку рабочей области окна */
		return 0;


	case WM_LBUTTONDOWN: {

		WORD xPos, yPos;

		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);

		//1
		if (xPos > 20 && xPos < 220 && yPos > 20 && yPos < 250) {

			if (key1 != 0) {
				MessageBox(NULL, "ƒанное место зан€то другим воином!", "Hohoho!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{


				warrior1 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 21, 10, 0, 0, hWnd, NULL, NULL, NULL);
				SendMessageW(warrior1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage);


				key1 = 1;
			}

		}
		//2
		if (xPos > 20 && xPos < 220 && yPos > 250 && yPos < 480) {
			if (key2 != 0) {
				MessageBox(NULL, "ƒанное место зан€то другим воином!", "Hohoho!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				warrior2 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 20, 240, 0, 0, hWnd, NULL, NULL, NULL);
				SendMessageW(warrior2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage);
				key2 = 1;
			}

		}
		//3
		if (xPos > 20 && xPos < 220 && yPos > 480 && yPos < 720) {
			if (key3 != 0) {
				MessageBox(NULL, "ƒанное место зан€то другим воином!", "Hohoho!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				warrior3 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 20, 470, 0, 0, hWnd, NULL, NULL, NULL);
				SendMessageW(warrior3, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage);
				key3 = 1;
			}
		}
		//4
		if (xPos > 420 && xPos < 620 && yPos > 20 && yPos < 250) {
			if (key4 != 0) {
				MessageBox(NULL, "ƒанное место зан€то другим воином!", "Hohoho!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				warrior4 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 430, 10, 0, 0, hWnd, NULL, NULL, NULL);
				SendMessageW(warrior4, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage);
				key4 = 1;
			}
		}
		//5
		if (xPos > 420 && xPos < 620 && yPos > 250 && yPos < 480) {
			if (key5 != 0) {
				MessageBox(NULL, "ƒанное место зан€то другим воином!", "Hohoho!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				warrior5 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 430, 240, 0, 0, hWnd, NULL, NULL, NULL);
				SendMessageW(warrior5, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage);
				key5 = 1;
			}
		}
		//6
		if (xPos > 420 && xPos < 620 && yPos > 480 && yPos < 720) {
			if (key6 != 0) {
				MessageBox(NULL, "ƒанное место зан€то другим воином!", "Hohoho!!", MB_ICONEXCLAMATION | MB_OK);
			}
			else
			{
				warrior6 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 430, 470, 0, 0, hWnd, NULL, NULL, NULL);
				SendMessageW(warrior6, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage);
				key6 = 1;
			}
		}

		return 0;
	}



	case WM_RBUTTONDOWN: {

		WORD xPos, yPos;

		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);

		//1
		if (xPos > 20 && xPos < 220 && yPos > 20 && yPos < 250) {


			if (key1 == 0) {
				if (HIBYTE(GetKeyState(0x31))) {
					warrior1 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 20, 10, 0, 0, hWnd, NULL, NULL, NULL);
					SendMessageW(warrior1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage3);
					key1 = 1;
					break;
				}

				if (HIBYTE(GetKeyState(0x32))) {
					warrior1 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 20, 10, 0, 0, hWnd, NULL, NULL, NULL);
					SendMessageW(warrior1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage2);
					key1 = 1;
					break;
				}
			}

			if (key1 != 0) {
				DestroyWindow(warrior1);
				key1 = 0;
			}
			else
			{
				MessageBox(NULL, "»звините,но вы используете правую кнопку мыши не по назначению)", "NO-NO-no!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		//2
		if (xPos > 20 && xPos < 220 && yPos > 250 && yPos < 480) {

			if (key2 == 0) {
				if (HIBYTE(GetKeyState(0x31))) {
					warrior2 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 20, 240, 0, 0, hWnd, NULL, NULL, NULL);
					SendMessageW(warrior2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage3);
					key2 = 1;
					break;
				}

				if (HIBYTE(GetKeyState(0x32))) {
					warrior2 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 20, 240, 0, 0, hWnd, NULL, NULL, NULL);
					SendMessageW(warrior2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage2);
					key2 = 1;
					break;
				}
			}

			if (key2 != 0) {
				DestroyWindow(warrior2);
				key2 = 0;
			}
			else
			{
				MessageBox(NULL, "»звините,но вы используете правую кнопку мыши не по назначению)", "NO-NO-no!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		//3
		if (xPos > 20 && xPos < 220 && yPos > 480 && yPos < 720) {

			if (key3 == 0) {
				if (HIBYTE(GetKeyState(0x31))) {
					warrior3 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 20, 470, 0, 0, hWnd, NULL, NULL, NULL);
					SendMessageW(warrior3, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage3);
					key3 = 1;
					break;
				}

				if (HIBYTE(GetKeyState(0x32))) {
					warrior3 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 20, 470, 0, 0, hWnd, NULL, NULL, NULL);
					SendMessageW(warrior3, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage2);
					key3 = 1;
					break;
				}
			}

			if (key3 != 0) {
				DestroyWindow(warrior3);
				key3 = 0;
			}
			else
			{
				MessageBox(NULL, "»звините,но вы используете правую кнопку мыши не по назначению)", "NO-NO-no!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		//4
		if (xPos > 420 && xPos < 620 && yPos > 20 && yPos < 250) {

			if (key4 == 0) {
				if (HIBYTE(GetKeyState(0x31))) {
					warrior4 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 430, 10, 0, 0, hWnd, NULL, NULL, NULL);
					SendMessageW(warrior4, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage3);
					key4 = 1;
					break;
				}

				if (HIBYTE(GetKeyState(0x32))) {
					warrior4 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 430, 10, 0, 0, hWnd, NULL, NULL, NULL);
					SendMessageW(warrior4, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage2);
					key4 = 1;
					break;
				}
			}

			if (key4 != 0) {
				DestroyWindow(warrior4);
				key4 = 0;
			}
			else
			{
				MessageBox(NULL, "»звините,но вы используете правую кнопку мыши не по назначению)", "NO-NO-no!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		//5
		if (xPos > 420 && xPos < 620 && yPos > 250 && yPos < 480) {

			if (key5 == 0) {
				if (HIBYTE(GetKeyState(0x31))) {
					warrior5 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 430, 240, 0, 0, hWnd, NULL, NULL, NULL);
					SendMessageW(warrior5, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage3);
					key5 = 1;
					break;
				}

				if (HIBYTE(GetKeyState(0x32))) {
					warrior5 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 430, 240, 0, 0, hWnd, NULL, NULL, NULL);
					SendMessageW(warrior5, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage2);
					key5 = 1;
					break;
				}
			}

			if (key5 != 0) {
				DestroyWindow(warrior5);
				key5 = 0;
			}
			else
			{
				MessageBox(NULL, "»звините,но вы используете правую кнопку мыши не по назначению)", "NO-NO-no!", MB_ICONEXCLAMATION | MB_OK);
			}
		}
		//6
		if (xPos > 420 && xPos < 620 && yPos > 480 && yPos < 720) {

			if (key6 == 0) {
				if (HIBYTE(GetKeyState(0x31))) {
					warrior6 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 430, 470, 0, 0, hWnd, NULL, NULL, NULL);
					SendMessageW(warrior6, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage3);
					key6 = 1;
					break;
				}

				if (HIBYTE(GetKeyState(0x32))) {
					warrior6 = CreateWindow("Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 430, 470, 0, 0, hWnd, NULL, NULL, NULL);
					SendMessageW(warrior6, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)warriorImage2);
					key6 = 1;
					break;
				}
			}

			if (key6 != 0) {
				DestroyWindow(warrior6);
				key6 = 0;
			}
			else
			{
				MessageBox(NULL, "»звините,но вы используете правую кнопку мыши не по назначению)", "NO-NO-no!", MB_ICONEXCLAMATION | MB_OK);
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