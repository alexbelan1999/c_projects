#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>

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
				//const char* name = "test"; // имя ODBC-соединения, настроенного в Windows
				const char* name = "psql"; // имя ODBC-соединения, настроенного в Windows
				//const char* name = "msql"; // имя ODBC-соединения, настроенного в Windows
				r = SQLConnect(hDbc, (SQLCHAR*)name, SQL_NTS, NULL, 0, NULL, 0);
				if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
				{	
					SQLHSTMT hStmt = NULL;
					r = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
					
					if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
					{
						const char* sql = "SELECT id, surname , name, patronymic, start_work, qualification FROM company_workers WHERE id=1;";
						//const char* sql = "DECLARE curs1 CURSOR FOR SELECT id, surname , name, patronymic, start_work, qualification FROM company_workers WHERE id=1; FETCH FORWARD ALL FROM curs1; CLOSE curs1";
						//const char* sql = "DECLARE curs1 CURSOR FOR SELECT id, surname , name, patronymic, start_work, qualification FROM company_workers WHERE id=1; FETCH FORWARD ALL FROM curs1; ";
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{
								cout << "query return " << rowCount << " rows" << endl;
								cout << "SELECT id, surname, name, patronymic, start_work, qualification FROM company_workers WHERE id=1; " << endl;
								SQLINTEGER fieldId;
								SQLWCHAR fieldSurname[50];
								SQLWCHAR fieldName[50];
								SQLWCHAR fieldPatronymic[50];
								SQLWCHAR fieldStart_work[22];
								SQLWCHAR fieldQualification[50];
								SQLLEN fieldPatronymicSize;

								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_SLONG, &fieldId, 0, NULL);
										SQLGetData(hStmt, 2, SQL_C_WCHAR, &fieldSurname, 50, NULL);
										SQLGetData(hStmt, 3, SQL_C_WCHAR, &fieldName, 50, NULL);
										SQLGetData(hStmt, 4, SQL_C_WCHAR, &fieldPatronymic, 50, &fieldPatronymicSize);
										SQLGetData(hStmt, 5, SQL_C_WCHAR, &fieldStart_work, 22, NULL);
										SQLGetData(hStmt, 6, SQL_C_WCHAR, &fieldQualification, 50, NULL);
										wcout << "id [" << fieldId << "] Surname: " << fieldSurname << " Name: " << fieldName;
										if (fieldPatronymicSize != SQL_NULL_DATA)
										{
											wcout << " Patronymic: " << fieldPatronymic;
										}
										else
										{
											wcout << " Patronymic: -  ";
										}
										wcout<< " Start_work: " << fieldStart_work << " Qualification: " << fieldQualification << endl;

									}
									else
									{
										cout << "error process query result (row)" << endl;
										if (r != SQL_SUCCESS)
										{
											while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
												cout << msg << endl;
											if (r == SQL_NO_DATA)
												cout << "No data" << endl;
										}
										break;
									}
								}
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql1 = "SELECT id, surname, name, patronymic, customers_id, position, e_mail FROM contact_person WHERE id=1;";
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql1, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{
								cout << endl;
								cout << "query return " << rowCount << " rows" << endl;
								cout << "SELECT id, surname, name, patronymic, customers_id, position, e_mail FROM contact_person WHERE id=1 " << endl;
								SQLINTEGER fieldId;
								SQLWCHAR fieldSurname[50];
								SQLWCHAR fieldName[50];
								SQLWCHAR fieldPatronymic[50];
								SQLINTEGER fieldCustomersid;
								SQLWCHAR fieldPosition[50];
								SQLWCHAR fieldEmail[50];
								SQLLEN fieldPatronymicSize;
								SQLLEN fieldEmailSize;
								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_SLONG, &fieldId, 0, NULL);
										SQLGetData(hStmt, 2, SQL_C_WCHAR, &fieldSurname, 50, NULL);
										SQLGetData(hStmt, 3, SQL_C_WCHAR, &fieldName, 50, NULL);
										SQLGetData(hStmt, 4, SQL_C_WCHAR, &fieldPatronymic, 50, &fieldPatronymicSize);
										SQLGetData(hStmt, 5, SQL_C_SLONG, &fieldCustomersid, 0, NULL);
										SQLGetData(hStmt, 6, SQL_C_WCHAR, &fieldPosition, 50, NULL);
										SQLGetData(hStmt, 7, SQL_C_WCHAR, &fieldEmail, 50, &fieldEmailSize);
										wcout << "id [" << fieldId << "] Surname: " << fieldSurname << " Name: " << fieldName;
										if (fieldPatronymicSize != SQL_NULL_DATA)
										{
											wcout << " Patronymic: " <<  fieldPatronymic;
										}
										else
										{
											wcout << " Patronymic: -  ";
										}
										wcout << " Customers_id: " << fieldCustomersid << " Position: " << fieldPosition;
										if (fieldEmailSize != SQL_NULL_DATA)
										{
											wcout << " E_mail: " << fieldEmail << endl;
										}
										else
										{
											wcout << " E_mail: -  "<< endl;
										}
									}
									else
									{
										cout << "error process query result (row)" << endl;
										if (r != SQL_SUCCESS)
										{
											while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
												cout << msg << endl;
											if (r == SQL_NO_DATA)
												cout << "No data" << endl;
										}
										break;
									}
								}
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);


						const char* sql2 = "SELECT id, name, address FROM customers WHERE id=1;";
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql2, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{	
								cout << endl;
								cout << "query return " << rowCount << " rows" << endl;
								cout << "SELECT id, name, address FROM customers WHERE id=1 " << endl;
								SQLINTEGER fieldId;
								SQLWCHAR fieldName[50];
								SQLWCHAR fieldAddress[50];
								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_SLONG, &fieldId, 0, NULL);
										SQLGetData(hStmt, 2, SQL_C_WCHAR, &fieldName, 50, NULL);
										SQLGetData(hStmt, 3, SQL_C_WCHAR, &fieldAddress, 50, NULL);
										wcout << "id [" << fieldId << "] Name: " << fieldName << " Address: " << fieldAddress << endl;
									}
									else
									{
										cout << "error process query result (row)" << endl;
										if (r != SQL_SUCCESS)
										{
											while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
												cout << msg << endl;
											if (r == SQL_NO_DATA)
												cout << "No data" << endl;
										}
										break;
									}
								}
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);


						const char* sql3 = "SELECT id, customer_id, project_name, start_date, plan_end_date, end_date, success FROM project_data WHERE id=1;";
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql3, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{	
								cout << endl;
								cout << "query return " << rowCount << " rows" << endl;
								cout << "SELECT id, customer_id, project_name, start_date, plan_end_date, end_date, success FROM project_data WHERE id=1 " << endl;
								SQLINTEGER fieldId;
								SQLINTEGER fieldCustomerid;
								SQLWCHAR fieldProjectname[50];
								SQLWCHAR fieldStartdate[22];
								SQLWCHAR fieldPlanenddate[22];
								SQLWCHAR fieldEnddate[22];
								SQLINTEGER fieldSuccess;
								SQLLEN fieldEnddateSize;
								SQLLEN fieldSuccessSize;
								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_SLONG, &fieldId, 0, NULL);
										SQLGetData(hStmt, 2, SQL_C_SLONG, &fieldCustomerid, 0, NULL);
										SQLGetData(hStmt, 3, SQL_C_WCHAR, &fieldProjectname, 50, NULL);
										SQLGetData(hStmt, 4, SQL_C_WCHAR, &fieldStartdate, 22, NULL);
										SQLGetData(hStmt, 5, SQL_C_WCHAR, &fieldPlanenddate, 22, NULL);
										SQLGetData(hStmt, 6, SQL_C_WCHAR, &fieldEnddate, 22, &fieldEnddateSize);
										SQLGetData(hStmt, 7, SQL_C_SLONG, &fieldSuccess, 0, &fieldSuccessSize);
										wcout << "id [" << fieldId << "] Customer_id: " << fieldCustomerid << " Project name: " << fieldProjectname << " Start date: " << fieldStartdate << " Plan end date: " << fieldPlanenddate;
										if (fieldEnddateSize != SQL_NULL_DATA)
										{
											wcout << " End date: " << fieldEnddate;
										}
										else
										{
											wcout << " End date: -  ";
										}

										if (fieldSuccessSize != SQL_NULL_DATA)
										{
											wcout << " Success: " << fieldSuccess << endl;
										}
										else
										{
											wcout << " Success: -  " << endl;
										}
									}
									else
									{
										cout << "error process query result (row)" << endl;
										if (r != SQL_SUCCESS)
										{
											while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
												cout << msg << endl;
											if (r == SQL_NO_DATA)
												cout << "No data" << endl;
										}
										break;
									}
								}
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);


						const char* sql4 = "SELECT id, project_id, worker_id, position, start_work, end_work FROM workers_project WHERE project_id=1;";
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql4, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{	
								cout << endl;
								cout << "query return " << rowCount << " rows" << endl;
								cout << "SELECT id, project_id, worker_id, position, start_work, end_work FROM workers_project WHERE id=1 " << endl;
								SQLINTEGER fieldId;
								SQLINTEGER fieldProjectid;
								SQLINTEGER fieldWorkerid;
								SQLWCHAR fieldPosition[50];
								SQLWCHAR fieldStartwork[22];
								SQLWCHAR fieldEndwork[22];
								SQLLEN fieldEnddateSize;
								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_SLONG, &fieldId, 0, NULL);
										SQLGetData(hStmt, 2, SQL_C_SLONG, &fieldProjectid, 0, NULL);
										SQLGetData(hStmt, 3, SQL_C_SLONG, &fieldWorkerid, 0, NULL);
										SQLGetData(hStmt, 4, SQL_C_WCHAR, &fieldPosition, 50, NULL);
										SQLGetData(hStmt, 5, SQL_C_WCHAR, &fieldStartwork, 22, NULL);
										SQLGetData(hStmt, 6, SQL_C_WCHAR, &fieldEndwork, 22, &fieldEnddateSize);
										wcout << "id [" << fieldId << "] Project_id: " << fieldProjectid << " Worker id: " << fieldWorkerid << " Position: " << fieldPosition << " Start work: " << fieldStartwork;
										if (fieldEnddateSize != SQL_NULL_DATA)
										{
											wcout << " End work: " << fieldEndwork << endl;
										}
										else
										{
											wcout << " End work: -  " << endl;
										}
										
									}
									else
									{
										cout << "error process query result (row)" << endl;
										if (r != SQL_SUCCESS)
										{
											while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
												cout << msg << endl;
											if (r == SQL_NO_DATA)
												cout << "No data" << endl;
										}
										break;
									}
								}
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);


						const char* sql5 = "SELECT id, contact_id, number FROM phone_number WHERE id=1;";
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql5, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{	
								cout << endl;
								cout << "query return " << rowCount << " rows" << endl;
								cout << "SELECT id, name, address FROM customers WHERE id=1 " << endl;
								SQLINTEGER fieldId;
								SQLINTEGER fieldContactid;
								SQLWCHAR fieldNumber[50];
								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_SLONG, &fieldId, 0, NULL);
										SQLGetData(hStmt, 2, SQL_C_SLONG, &fieldContactid, 0, NULL);
										SQLGetData(hStmt, 3, SQL_C_WCHAR, &fieldNumber, 50, NULL);
										wcout << "id [" << fieldId << "] Contactid: " << fieldContactid << " Number: " << fieldNumber << endl;

									}
									else
									{
										cout << "error process query result (row)" << endl;
										if (r != SQL_SUCCESS)
										{
											while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
												cout << msg << endl;
											if (r == SQL_NO_DATA)
												cout << "No data" << endl;
										}
										break;
									}
								}
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);


						const char* sql6 = "SELECT contact_person.surname, contact_person.name, contact_person.patronymic, phone_number.number FROM contact_person LEFT JOIN phone_number ON contact_person.id=phone_number.contact_id WHERE contact_person.customers_id=1;";
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql6, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{	
								cout << endl;
								cout << "query return " << rowCount << " rows" << endl;
								cout << "SELECT contact_person.surname, contact_person.name, contact_person.patronymic, phone_number.number FROM contact_person LEFT JOIN phone_number ON contact_person.id=phone_number.contact_id WHERE contact_person.customers_id=1; " << endl;
								SQLWCHAR fieldSurname[50];
								SQLWCHAR fieldName[50];
								SQLWCHAR fieldPatronymic[50];
								SQLWCHAR fieldNumber[50];
								SQLLEN fieldPatronymicSize;
								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_WCHAR, &fieldSurname, 50, NULL);
										SQLGetData(hStmt, 2, SQL_C_WCHAR, &fieldName, 50, NULL);
										SQLGetData(hStmt, 3, SQL_C_WCHAR, &fieldPatronymic, 50, &fieldPatronymicSize);
										SQLGetData(hStmt, 4, SQL_C_WCHAR, &fieldNumber, 50, NULL);
										wcout << "Surname: " << fieldSurname << " Name: " << fieldName;
										if (fieldPatronymicSize != SQL_NULL_DATA)
										{
											wcout << " Patronymic: " << fieldPatronymic;
										}
										else
										{
											wcout << " Patronymic: -  ";
										}
										wcout << " Number: " << fieldNumber << endl;
									}
									else
									{
										cout << "error process query result (row)" << endl;
										if (r != SQL_SUCCESS)
										{
											while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
												cout << msg << endl;
											if (r == SQL_NO_DATA)
												cout << "No data" << endl;
										}
										break;
									}
								}
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);


						const char* sql7 = "SELECT company_workers.surname,company_workers.name,company_workers.patronymic,project_data.project_name FROM company_workers LEFT JOIN workers_project ON company_workers.id=workers_project.worker_id LEFT JOIN project_data ON workers_project.project_id=project_data.id WHERE company_workers.id=1;";
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql7, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{	
								cout << endl;
								cout << "query return " << rowCount << " rows" << endl;
								cout << "SELECT company_workers.surname,company_workers.name,company_workers.patronymic,project_data.project_name FROM company_workers LEFT JOIN workers_project ON company_workers.id=workers_project.worker_id LEFT JOIN project_data ON workers_project.project_id=project_data.id WHERE company_workers.id=1; " << endl;
								SQLWCHAR fieldSurname[50];
								SQLWCHAR fieldName[50];
								SQLWCHAR fieldPatronymic[50];
								SQLWCHAR fieldProjectname[50];
								SQLLEN fieldPatronymicSize;
								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_WCHAR, &fieldSurname, 50, NULL);
										SQLGetData(hStmt, 2, SQL_C_WCHAR, &fieldName, 50, NULL);
										SQLGetData(hStmt, 3, SQL_C_WCHAR, &fieldPatronymic, 50, &fieldPatronymicSize);
										SQLGetData(hStmt, 4, SQL_C_WCHAR, &fieldProjectname, 50, NULL);
										wcout << "Surname: " << fieldSurname << " Name: " << fieldName;
										if (fieldPatronymicSize != SQL_NULL_DATA)
										{
											wcout << " Patronymic: " << fieldPatronymic;
										}
										else
										{
											wcout << " Patronymic: -  ";
										}
										wcout << " Project name: " << fieldProjectname << endl;
									}
									else
									{
										cout << "error process query result (row)" << endl;
										if (r != SQL_SUCCESS)
										{
											while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
												cout << msg << endl;
											if (r == SQL_NO_DATA)
												cout << "No data" << endl;
										}
										break;
									}
								}
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);


						const char* sql8 = "SELECT worker_id,position,start_work FROM workers_project ORDER BY position DESC,start_work DESC;";
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql8, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{	
								cout << endl;
								cout << "query return " << rowCount << " rows" << endl;
								cout << "SELECT worker_id,position,start_work FROM workers_project ORDER BY position DESC,start_work DESC ; " << endl;
								SQLINTEGER fieldWorkerid;
								SQLWCHAR fieldPosition[50];
								SQLWCHAR fieldStartwork[22];
								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_SLONG, &fieldWorkerid, 0, NULL);
										SQLGetData(hStmt, 2, SQL_C_WCHAR, &fieldPosition, 50, NULL);
										SQLGetData(hStmt, 3, SQL_C_WCHAR, &fieldStartwork, 22, NULL);
					
										wcout << "Worker id: " << fieldWorkerid << " Position: " << fieldPosition << " Start work: " << fieldStartwork << endl;
									
									}
									else
									{
										cout << "error process query result (row)" << endl;
										if (r != SQL_SUCCESS)
										{
											while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
												cout << msg << endl;
											if (r == SQL_NO_DATA)
												cout << "No data" << endl;
										}
										break;
									}
								}
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);


						const char* sql9 = "SELECT customers.name, contact_person.surname,contact_person.name, contact_person.patronymic, phone_number.number FROM customers LEFT JOIN contact_person ON customers.id = contact_person.customers_id  LEFT JOIN phone_number ON (contact_person.id = phone_number.contact_id) WHERE contact_person.customers_id IN (SELECT customers.id FROM customers LEFT JOIN project_data ON (customers.id = project_data.customer_id) WHERE project_data.end_date IS NULL GROUP BY customers.id HAVING COUNT(project_data.customer_id) > 1);";
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql9, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{	
								cout << endl;
								cout << "query return " << rowCount << " rows" << endl;
								cout << "SELECT customers.name, contact_person.surname,contact_person.name, contact_person.patronymic, phone_number.number FROM customers LEFT JOIN contact_person ON customers.id = contact_person.customers_id  LEFT JOIN phone_number ON (contact_person.id = phone_number.contact_id) WHERE contact_person.customers_id IN (SELECT customers.id FROM customers LEFT JOIN project_data ON (customers.id = project_data.customer_id) WHERE project_data.end_date IS NULL GROUP BY customers.id HAVING COUNT(project_data.customer_id) > 1); " << endl;
								SQLWCHAR fieldCustomername[50];
								SQLWCHAR fieldSurname[50];
								SQLWCHAR fieldName[50];
								SQLWCHAR fieldPatronymic[50];
								SQLWCHAR fieldNumber[50];
								SQLLEN fieldPatronymicSize;
								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_WCHAR, &fieldCustomername, 50, NULL);
										SQLGetData(hStmt, 2, SQL_C_WCHAR, &fieldSurname, 50, NULL);
										SQLGetData(hStmt, 3, SQL_C_WCHAR, &fieldName, 50, NULL);
										SQLGetData(hStmt, 4, SQL_C_WCHAR, &fieldPatronymic, 50, &fieldPatronymicSize);
										SQLGetData(hStmt, 5, SQL_C_WCHAR, &fieldNumber, 50, NULL);

										wcout << "Customers name: " << fieldCustomername << " Surname: " << fieldSurname << " Name: " << fieldName;
										if (fieldPatronymicSize != SQL_NULL_DATA)
										{
											wcout << " Patronymic: " << fieldPatronymic;
										}
										else
										{
											wcout << " Patronymic: -  ";
										}
										wcout << " Number: " << fieldNumber << endl;
									}
									else
									{
										cout << "error process query result (row)" << endl;
										if (r != SQL_SUCCESS)
										{
											while (SQLGetDiagRec(SQL_HANDLE_STMT, hStmt, i++, NULL, NULL, msg, 1000, NULL) == SQL_SUCCESS)
												cout << msg << endl;
											if (r == SQL_NO_DATA)
												cout << "No data" << endl;
										}
										break;
									}
								}
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