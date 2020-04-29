#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>
#include <ctime>
#include <string> 
#include <fstream>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
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

				const char* name = "subscriptionm"; 

				r = SQLConnect(hDbc, (SQLCHAR*)name, SQL_NTS, NULL, 0, NULL, 0);
				if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
				{
					SQLHSTMT hStmt = NULL;
					r = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
					if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
					{
						unsigned int start_time = clock();
						unsigned int clock1 = 0, clock2 = 0, clock3 = 0, clock4 = 0,clock5 = 0;
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);
						
						string s; 
						ifstream file("datam1.txt");
						if (!file.is_open()) {
							cout << "Файл не может быть открыт!" << endl;
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
										//cout << "query return " << rowCount << " rows" << endl;

									}
									else
									{
										cout << "error process query result (count)" << endl;
										if (r != SQL_SUCCESS)
										{
											while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
												cout << msg << endl;
											if (r == SQL_NO_DATA)
												cout << "No data" << endl;
										}
									}

								}
								else
								{
									cout << "error executing query" << endl;
									if (r != SQL_SUCCESS)
									{
										while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
											cout << msg << endl;
										if (r == SQL_NO_DATA)
											cout << "No data" << endl;
									}

								}

								SQLCloseCursor(hStmt);
								n++;
							}

						file.close();
						unsigned int end_time = clock();
						cout << "Время create: " << (clock1 - start_time) / 1000.0 << endl;
						cout << "Время insert: " << (clock2 - clock1) / 1000.0 << endl;
						cout << "Время select1: " << (clock3 - clock2) / 1000.0 << endl;
						cout << "Время update: " << (clock4 - clock3) / 1000.0 << endl;
						cout << "Время select2: " << (clock5 - clock4) / 1000.0 << endl;
						cout << "Время drop: " << (end_time - clock5) / 1000.0 << endl;
						cout << "Время выполнения: " << (end_time - start_time) / 1000.0 << endl;

							
						}
						


					}///////////////////////////////////////////////////////////////
					else
					{
						cout << "error allocation statement" << endl;
						if (r != SQL_SUCCESS)
						{
							while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
								cout << msg << endl;
							if (r == SQL_NO_DATA)
								cout << "No data" << endl;
						}
					}
					if (hStmt)
					{
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
					}
				}
				else
				{
					cout << "error connection" << endl;

				}
			}
			else
			{
				cout << "error allocation connection" << endl;
			}
			if (hDbc)
			{
				SQLDisconnect(hDbc);
				SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
			}
		}
		else
		{
			cout << "error setting version" << endl;
		}
	}
	else
	{
		cout << "error allocation of environment handle" << endl;
	}
	if (hEnv)
	{
		SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
	}
	system("pause");
	return 0;
}