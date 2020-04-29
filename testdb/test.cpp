#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sql.h>
#include <sqlext.h>
#include <ctime>
#include <fstream>

using namespace std;

#define idEntryBtn1 1
#define idEntryBtn2 2
#define idEntryBtn3 3
#define idEntry1 4
#define idEntry2 5
#define idEntry3 6
#define idEntry4 7
#define idEntry5 8
#define idEntry6 9
#define idEntry7 10
#define idEntry8 11
#define idEntry9 12
#define idEntry10 13
#define idEntry11 14
#define idEntry12 15
#define idEntry13 16
#define idEntry14 17
#define idEntry15 18
#define idEntry16 19
#define idEntry17 20
#define idEntry18 21
#define idEntry19 22
#define idEntry20 23
#define idEntry21 24
#define idInt 25

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	WNDCLASS wcl;
	ZeroMemory(&wcl, sizeof(WNDCLASS));
	wcl.hInstance = hInstance;
	wcl.lpszClassName = "TestDBClass";
	wcl.lpfnWndProc = WndProc;
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpszMenuName = NULL;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
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

	hWnd = CreateWindow("TestDBClass","Тестирование баз данных",WS_SYSMENU | WS_MINIMIZEBOX,300,75,465,560,HWND_DESKTOP,NULL,hInstance,NULL);

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

void outRes(HWND hWnd, int idEntryBtn, const char * name, const char * filename, int number)
{	
	HWND hEditEntry = NULL; 
	HWND hEditEntry1 = NULL;
	HWND hEditEntry2 = NULL;
	HWND hEditEntry3 = NULL;
	HWND hEditEntry4 = NULL;
	HWND hEditEntry5 = NULL;
	HWND hEditEntry6 = NULL;
	
	double timeres1 = 0.0, timeres2 = 0.0, timeres3 = 0.0, timeres4 = 0.0, timeres5 = 0.0, timeres6 = 0.0, timeres7 = 0.0;
	if (idEntryBtn == 1) {
		hEditEntry = GetDlgItem(hWnd, idEntry1);
		hEditEntry1 = GetDlgItem(hWnd, idEntry4);
		hEditEntry2 = GetDlgItem(hWnd, idEntry7);
		hEditEntry3 = GetDlgItem(hWnd, idEntry10);
		hEditEntry4 = GetDlgItem(hWnd, idEntry13);
		hEditEntry5 = GetDlgItem(hWnd, idEntry16);
		hEditEntry6 = GetDlgItem(hWnd, idEntry19);
	}
	if (idEntryBtn == 2) {
		hEditEntry = GetDlgItem(hWnd, idEntry2);
		hEditEntry1 = GetDlgItem(hWnd, idEntry5);
		hEditEntry2 = GetDlgItem(hWnd, idEntry8);
		hEditEntry3 = GetDlgItem(hWnd, idEntry11);
		hEditEntry4 = GetDlgItem(hWnd, idEntry14);
		hEditEntry5 = GetDlgItem(hWnd, idEntry17);
		hEditEntry6 = GetDlgItem(hWnd, idEntry20);
	}
	if (idEntryBtn == 3) {
		hEditEntry = GetDlgItem(hWnd, idEntry3);
		hEditEntry1 = GetDlgItem(hWnd, idEntry6);
		hEditEntry2 = GetDlgItem(hWnd, idEntry9);
		hEditEntry3 = GetDlgItem(hWnd, idEntry12);
		hEditEntry4 = GetDlgItem(hWnd, idEntry15);
		hEditEntry5 = GetDlgItem(hWnd, idEntry18);
		hEditEntry6 = GetDlgItem(hWnd, idEntry21);
	}

	SQLCHAR msg[1000];
	int i = 1;
	SQLHENV hEnv = NULL;
	SQLRETURN r = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
	if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
	{
		r = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
		if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
		{
			SQLHDBC hDbc = NULL;
			r = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
			if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
			{
				r = SQLConnect(hDbc, (SQLCHAR*)name, SQL_NTS, NULL, 0, NULL, 0);
				if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
				{
					SQLHSTMT hStmt = NULL;
					r = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
					if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
					{	
						for (int k = 0; k < number; k++)
						{
							unsigned int start_time = 0, end_time = 0;
							unsigned int clock1 = 0, clock2 = 0, clock3 = 0, clock4 = 0, clock5 = 0;
							start_time = clock();
							string s;
							ifstream file(filename);

							if (!file.is_open()) 
							{
								MessageBox(NULL, "Файл не может быть открыт!", "Ошибка", MB_ICONERROR);
							}
							else
							{
								int n = 0;
								while (getline(file, s))
								{
									const char * sql = s.c_str();
									if (n == 4)
									{
										unsigned int time1 = clock();
										clock1 = time1;
									}
									if (n == 26)
									{
										unsigned int time2 = clock();
										clock2 = time2;
									}
									if (n == 126)
									{
										unsigned int time3 = clock();
										clock3 = time3;
									}
									if (n == 127)
									{
										unsigned int time4 = clock();
										clock4 = time4;
									}
									if (n == 227)
									{
										unsigned int time5 = clock();
										clock5 = time5;
									}

									r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);
									r = SQLExecDirect(hStmt, (SQLCHAR*)sql, SQL_NTS);
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLLEN rowCount;
										r = SQLRowCount(hStmt, &rowCount);
										if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
										{

										}
										else
										{
											MessageBox(NULL, "error process query result (count)", "Ошибка", MB_ICONERROR);
											if (r != SQL_SUCCESS)
											{
												while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
													MessageBox(NULL, (LPCSTR)msg, "Ошибка", MB_ICONERROR);
												if (r == SQL_NO_DATA)
												{
													MessageBox(NULL, "No data!", "Ошибка", MB_ICONERROR);
												}
														
											}
										}

									}
									else
									{
										MessageBox(NULL, "error executing query", "Ошибка", MB_ICONERROR);
										if (r != SQL_SUCCESS)
										{
											while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
												MessageBox(NULL, (LPCSTR)msg, "Ошибка", MB_ICONERROR);
											if (r == SQL_NO_DATA)
											{
												MessageBox(NULL, "No data!", "Ошибка", MB_ICONERROR);
											}
													
										}

									}

									SQLCloseCursor(hStmt);
									n++;
								}

								file.close();
								end_time = clock();
								timeres1 = timeres1 + (clock1 - start_time) / 1000.0;
								timeres2 = timeres2 + (clock2 - clock1) / 1000.0;
								timeres3 = timeres3 + (clock3 - clock2) / 1000.0;
								timeres4 = timeres4 + (clock4 - clock3) / 1000.0;
								timeres5 = timeres5 + (clock5 - clock4) / 1000.0;
								timeres6 = timeres6 + (end_time - clock5) / 1000.0;
								timeres7 = timeres7 + (end_time - start_time) / 1000.0;

							}
						}
						
					}
					else
					{

						MessageBox(NULL, "error allocation statemen!", "Ошибка", MB_ICONERROR);
						if (r != SQL_SUCCESS)
						{
							while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
								MessageBox(NULL, (LPCSTR)msg, "Ошибка", MB_ICONERROR);
							if (r == SQL_NO_DATA) {
								MessageBox(NULL, "No data!", "Ошибка", MB_ICONERROR);
							}		
						}
					}
					if (hStmt)
					{
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
					}
				}
				else
				{
					MessageBox(NULL, "error connection!", "Ошибка", MB_ICONERROR);
				}
			}
			else
			{
				MessageBox(NULL, "error allocation connection", "Ошибка", MB_ICONERROR);
			}
			if (hDbc)
			{
				SQLDisconnect(hDbc);
				SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
			}
		}
		else
		{
			MessageBox(NULL, "error setting version", "Ошибка", MB_ICONERROR);
		}
	}
	else
	{
		MessageBox(NULL, "error allocation of environment handle", "Ошибка", MB_ICONERROR);
	}
	if (hEnv)
	{
		SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
	}
	SetWindowText(hEditEntry, to_string(timeres1 / number).data());
	SetWindowText(hEditEntry1, to_string(timeres2 / number).data());
	SetWindowText(hEditEntry2, to_string(timeres3 / number).data());
	SetWindowText(hEditEntry3, to_string(timeres4 / number).data());
	SetWindowText(hEditEntry4, to_string(timeres5 / number).data());
	SetWindowText(hEditEntry5, to_string(timeres6 / number).data());
	SetWindowText(hEditEntry6, to_string(timeres7 / number).data());
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg)
	{
	case WM_CREATE:
	{
		HINSTANCE hInst;
		hInst = ((LPCREATESTRUCT)lParam)->hInstance;

		CreateWindow("BUTTON","Тест MySQL",WS_CHILD | WS_VISIBLE | BS_VCENTER | BS_FLAT,10, 10,100, 40,hwnd,(HMENU)idEntryBtn1,hInst,NULL);
		CreateWindow("BUTTON","Тест PostgreSQL",WS_CHILD | WS_VISIBLE | BS_VCENTER | BS_FLAT,120, 10,120, 40,hwnd,(HMENU)idEntryBtn2,hInst,NULL);
		CreateWindow("BUTTON","Тест Microsoft SQL Server",WS_CHILD | WS_VISIBLE | BS_VCENTER | BS_FLAT,250, 10,190, 40,hwnd,(HMENU)idEntryBtn3,hInst,NULL);
		CreateWindow("STATIC","Среднее время create в секундах: ",WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,10, 60,240, 20,hwnd,NULL,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,10, 90,100, 20,hwnd,(HMENU)idEntry1,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,120, 90,120, 20,hwnd,(HMENU)idEntry2,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,250, 90,190, 20,hwnd,(HMENU)idEntry3,hInst,NULL);
		CreateWindow("STATIC","Среднее время insert в секундах: ",WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,10, 120,240, 20,hwnd,NULL,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,10, 150,100, 20,hwnd,(HMENU)idEntry4,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,120, 150,120, 20,hwnd,(HMENU)idEntry5,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,250, 150,190, 20,hwnd,(HMENU)idEntry6,hInst,NULL);
		CreateWindow("STATIC","Среднее время select1 в секундах: ",WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,10, 180,240, 20,hwnd,NULL,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,10, 210,100, 20,hwnd,(HMENU)idEntry7,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,120, 210,120, 20,hwnd,(HMENU)idEntry8,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,250, 210,190, 20,hwnd,(HMENU)idEntry9,hInst,NULL);
		CreateWindow("STATIC","Среднее время update в секундах: ",WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,10, 240,240, 20,hwnd,NULL,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,10, 270,100, 20,hwnd,(HMENU)idEntry10,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,120, 270,120, 20,hwnd,(HMENU)idEntry11,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,250, 270,190, 20,hwnd,(HMENU)idEntry12,hInst,NULL);
		CreateWindow("STATIC","Среднее время select2 в секундах: ",WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,10, 300,240, 20,hwnd,NULL,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,10, 330,100, 20,hwnd,(HMENU)idEntry13,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,120, 330,120, 20,hwnd,(HMENU)idEntry14,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,250, 330,190, 20,hwnd,(HMENU)idEntry15,hInst,NULL);
		CreateWindow("STATIC","Среднее время drop в секундах: ",WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,10, 360,240, 20,hwnd,NULL,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,10, 390,100, 20,hwnd,(HMENU)idEntry16,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,120, 390,120, 20,hwnd,(HMENU)idEntry17,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,250, 390,190, 20,hwnd,(HMENU)idEntry18,hInst,NULL);
		CreateWindow("STATIC","Общее среднее время в секундах: ",WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,10, 420,240, 20,hwnd,NULL,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,10, 450,100, 20,hwnd,(HMENU)idEntry19,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,120, 450,120, 20,hwnd,(HMENU)idEntry20,hInst,NULL);
		CreateWindow("STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT | SS_CENTERIMAGE,250, 450,190, 20,hwnd,(HMENU)idEntry21,hInst,NULL);
		CreateWindow("STATIC","Количество тестов: ",WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,10, 480,150, 20,hwnd,NULL,hInst,NULL);
		CreateWindow("EDIT",NULL,WS_CHILD | WS_BORDER | WS_VISIBLE,170, 480,50, 20,hwnd,(HMENU)idInt,hInst,NULL);
		
		break;
	}

	case WM_COMMAND:
	{
		char inText[100] = "";
		HWND hInt = GetDlgItem(hwnd, idInt);
		GetWindowText(hInt, inText, 100);
		int a = atoi(inText);

		if (HIWORD(wParam) == BN_CLICKED)
			switch (LOWORD(wParam))
			{
			case idEntryBtn1: {

				outRes(hwnd, idEntryBtn1,"subscriptionm","c:\\Users\\Алексей\\source\\repos\\testdb\\testdb\\datam1.txt",a);
				break;
			}
			case idEntryBtn2: {

				outRes(hwnd, idEntryBtn2,"subscriptionp", "c:\\Users\\Алексей\\source\\repos\\testdb\\testdb\\datap1.txt",a);
				break;
			}
			case idEntryBtn3: {

				outRes(hwnd, idEntryBtn3, "subscriptionms", "c:\\Users\\Алексей\\source\\repos\\testdb\\testdb\\datams1.txt",a);
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
