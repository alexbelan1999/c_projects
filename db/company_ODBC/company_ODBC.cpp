#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <stdafx.h>
#include <iostream>

using namespace std;

int main()
{
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
				wchar_t* name = L"company_db"; // имя ODBC-соединения, настроенного в Windows
				r = SQLConnect(hDbc, (SQLWCHAR*)name, SQL_NTS, NULL, 0, NULL, 0);
				if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
				{
					SQLHSTMT hStmt = NULL;
					r = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
					if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
					{
						wchar_t* sql = L"SELECT id, surname, name, patronymic, start_work, qualification FROM company_workers WHERE id=1";
						r = SQLExecDirect(hStmt, (SQLWCHAR*)sql, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{
								cout << "query return " << rowCount << " rows" << endl;
								SQLINTEGER fieldId;
								SQLWCHAR fieldSurname[50];
								SQLWCHAR fieldName[50];
								SQLWCHAR fieldPatronymic[50];
								SQLDATE fieldStart_work;
								SQLWCHAR fieldQualification[50];
								
								SQLLEN fieldDeathYearSize;
								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_SLONG, &fieldId, 0, NULL);
										SQLGetData(hStmt, 2, SQL_C_WCHAR, fieldSurname, 50, NULL);
										SQLGetData(hStmt, 3, SQL_C_WCHAR, fieldName, 50, NULL);
										SQLGetData(hStmt, 4, SQL_C_SLONG, &fieldPatronymic, 50, NULL);
										SQLGetData(hStmt, 5, SQL_C_SLONG, &fieldStart_work, 0, NULL);
										SQLGetData(hStmt, 5, SQL_C_SLONG, &fieldQualification, 0, NULL);
										wcout << "[" << fieldId << "] " << fieldSurname << " " << fieldName << " " << fieldPatronymic << " " << fieldStart_work << " " << fieldQualification;
									
									}
									else
									{
										cout << "error process query result (row)" << endl;
										break;
									}
								}
							}
							else
							{
								cout << "error process query result (count)" << endl;
							}
						}
						else
						{
							cout << "error executing query" << endl;
						}
					}
					else
					{
						cout << "error allocation statement" << endl;
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