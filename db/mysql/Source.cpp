#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>
#include <ctime>
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

				const char* name = "subscriptionm"; // ��� ODBC-����������, ������������ � Windows

				r = SQLConnect(hDbc, (SQLCHAR*)name, SQL_NTS, NULL, 0, NULL, 0);
				if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
				{
					SQLHSTMT hStmt = NULL;
					r = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
					if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
					{	
						unsigned int start_time = clock();
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);
						const char* sql = "create table publication_type(id int(10) NOT NULL AUTO_INCREMENT, type varchar(50) NOT NULL, PRIMARY KEY (id));";
						//cout << "create table publication_type(id int(10) NOT NULL AUTO_INCREMENT, type varchar(50) NOT NULL, PRIMARY KEY (id));" << endl;
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql1 = "create table publication(id int(10) NOT NULL AUTO_INCREMENT, pub_index int(10) NOT NULL, type_id int(10) NOT NULL, name varchar(50) NOT NULL ,price int(10) NOT NULL CHECK (price > 0), PRIMARY KEY (id),FOREIGN KEY (type_id) REFERENCES publication_type(id));";
						
						//cout << "create table publication" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql1, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql2 = "create table subscriber(id int(10) NOT NULL auto_increment, surname varchar(50) NOT NULL , name varchar(50) NOT NULL , patronymic varchar(50) NULL , address varchar(50) NOT NULL , number varchar(50) not null, PRIMARY KEY (id));";
						//cout << "create table subscriber" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql2, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql3 = "create table ticket(id int(10) NOT NULL auto_increment, subscriber_id int(10) NOT NULL ,publication_id int(10) NOT NULL , subscription_term int(10) NOT NULL CHECK (subscription_term > 0), month int(10) NOT NULL CHECK (month > 0 AND month < 13),year int(10) NOT NULL CHECK (year > 1990 AND year < 2021), PRIMARY KEY (id),FOREIGN KEY (subscriber_id) REFERENCES subscriber(id),FOREIGN KEY (publication_id) REFERENCES publication(id));";
						//cout << "create table ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql3, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);
						
						
						const char* sql4 = "insert into publication_type(type)VALUES ('newspaper'),('magazine'),('book');";
						//cout << "insert into publication_type" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql4, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql5 = "insert into publication (pub_index, type_id, name, price) values  (751396, 2, 'Komsomolskaya Pravda in Belarus', 95) ,(673876, 3, 'Belarus today', 93) ,(600071, 3, 'Arguments and facts in Belarus', 43) ,(405539, 1, 'From hand to hand', 79) ,(352808, 1, 'Antenna', 74) ,(35296, 1, 'Republic', 41) ,(133567, 3, 'Peoples newspaper', 11) ,(935908, 2, 'Banner of youth', 38) ,(235412, 3, 'Star', 20) ,(981841, 3, 'Vitbichi', 57) ;";
						//cout << "insert into publication" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql5, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql6 = "insert into subscriber (surname, name, address, number) values ('Wellsman', 'Rosina', '6 Victoria Parkway', '+86 (837) 376-9132'),('Othick', 'Helenka', '01174 Superior Parkway', '+7 (514) 932-5368'),('Trusse', 'Corena', '8807 Quincy Terrace', '+7 (291) 583-4917'),('Dillet', 'Chad', '75 Transport Avenue', '+225 (951) 266-6525'),('Wainwright', 'Miquela', '519 Donald Drive', '+52 (914) 777-4712'),('Prujean', 'Ardyce', '66 Mayfield Way', '+263 (405) 253-6769'),('Kirgan', 'Blakeley', '5 Meadow Vale Alley', '+51 (939) 399-9161'),('Olenov', 'Flossi', '60368 Porter Lane', '+46 (633) 114-7053'),('Grier', 'Rebecca', '71154 Claremont Alley', '+680 (372) 733-8700'),('Liell', 'Cybill', '4 Oak Valley Drive', '+86 (320) 760-7581'),('Callery', 'Gale', '8 Shasta Center', '+1 (808) 100-0148'),('De Vaan', 'Tove', '58346 Sycamore Center', '+84 (697) 418-0822'),('Mountfort', 'Darius', '13591 Kings Way', '+46 (441) 484-9262'),('Fake', 'Teressa', '9 Stone Corner Hill', '+86 (462) 436-9008'),('Peltzer', 'Jori', '45377 Stephen Pass', '+963 (274) 123-4164'),('Slessor', 'Derril', '20 Basil Street', '+51 (239) 879-3243'),('Hold', 'Patti', '36441 Glendale Crossing', '+420 (268) 972-8286'),('Bergeau', 'Laurice', '20655 Manley Plaza', '+351 (568) 884-3646'),('Vedenyakin', 'Ursa', '8706 Ilene Hill', '+57 (410) 917-3333'),('Snyder', 'Myer', '9 Mifflin Trail', '+51 (882) 675-3356'),('Piche', 'Farley', '86314 Jay Center', '+54 (143) 929-5185'),('Roussel', 'Lorens', '46 Arrowood Hill', '+57 (507) 499-2689'),('Normanville', 'Oliver', '45 Raven Crossing', '+62 (836) 405-1531'),('Dran', 'Herculie', '1 Independence Point', '+64 (485) 977-0359'),('Sargerson', 'Rog', '21 Garrison Alley', '+232 (507) 432-8864'),('Bente', 'Garwin', '234 Luster Lane', '+62 (534) 528-5840'),('Millott', 'Kaila', '32297 Leroy Terrace', '+55 (587) 751-6391'),('Kett', 'Erasmus', '5 Lindbergh Point', '+62 (195) 258-9527'),('Nail', 'Alysia', '85 Hollow Ridge Court', '+1 (713) 837-2933'),('Templeman', 'Phillis', '452 Monica Road', '+268 (908) 928-1161'),('Arnao', 'Brnaba', '882 Declaration Circle', '+351 (459) 997-1477'),('Robke', 'Elvina', '5 Grasskamp Avenue', '+351 (463) 382-2743'),('Andrioletti', 'Una', '724 Thackeray Pass', '+961 (899) 856-5484'),('Lumsden', 'Daloris', '4244 Monument Alley', '+48 (135) 880-1724'),('Mollon', 'Roxanna', '40020 Dayton Trail', '+1 (869) 977-5425'),('Avory', 'Julienne', '9 Vermont Parkway', '+86 (259) 427-8994'),('Collen', 'Crista', '6 Main Street', '+86 (477) 479-1287'),('Pagett', 'Tony', '758 Buhler Hill', '+95 (372) 626-2568'),('Gillmor', 'Tiffany', '356 Mitchell Pass', '+57 (983) 214-6969'),('Hardes', 'Silvan', '7 Crowley Hill', '+98 (966) 941-5424'),('Legan', 'Iggy', '4 Weeping Birch Alley', '+86 (680) 625-8887'),('Seamon', 'Wit', '4 Londonderry Hill', '+420 (908) 895-5408'),('Broadfoot', 'Zonnya', '57 Riverside Road', '+30 (620) 255-5881'),('Hankinson', 'Bobine', '2239 Mcguire Junction', '+62 (712) 468-4437'),('Poncet', 'Brook', '85 Morrow Drive', '+86 (779) 390-3074'),('Birtwistle', 'Cherin', '613 Bluejay Center', '+30 (284) 823-2883'),('Behning', 'Rupert', '0 Carberry Crossing', '+51 (399) 616-0460'),('Gadsby', 'Caressa', '552 Hoard Avenue', '+86 (496) 223-6527'),('Tunn', 'Sullivan', '799 Colorado Hill', '+7 (682) 833-3257'),('Keeney', 'Benjamen', '66340 Kim Place', '+62 (712) 949-8727'),('Faughnan', 'Inger', '11 Sommers Place', '+86 (339) 434-6156'),('Ghion', 'Christabel', '23 Hollow Ridge Alley', '+39 (339) 999-2417'),('Cereceres', 'Timmie', '08 Monument Crossing', '+351 (839) 580-5939'),('Shawell', 'Mara', '416 Garrison Circle', '+351 (543) 691-6723'),('Scrancher', 'Selig', '5 Steensland Junction', '+98 (364) 679-4210'),('Coryndon', 'Dacie', '650 Superior Circle', '+86 (407) 750-2964'),('Mc Giffin', 'Christian', '71 Summerview Parkway', '+963 (613) 679-6009'),('Spaule', 'Enrica', '7229 Grover Way', '+86 (845) 496-7686'),('Van Velde', 'Uriel', '2 Drewry Terrace', '+7 (358) 475-8425'),('Alcoran', 'Janka', '99554 Moose Street', '+86 (328) 431-8150'),('Leathers', 'Creigh', '19379 Carioca Trail', '+86 (942) 449-3069'),('Klausen', 'Lennard', '5428 Maywood Drive', '+30 (130) 231-6109'),('Janko', 'Otto', '3 Ilene Road', '+63 (698) 624-2854'),('Ogg', 'Bruis', '49 Almo Circle', '+62 (238) 690-7577'),('Derrell', 'Giraud', '72444 Old Gate Trail', '+54 (134) 647-9224'),('Vynoll', 'Silvain', '520 Nancy Court', '+46 (874) 195-8499'),('Chuck', 'Neddy', '7 Darwin Point', '+60 (851) 696-4986'),('Swinerd', 'Josefina', '95 Green Avenue', '+86 (614) 790-4663'),('Butterfint', 'Leesa', '0 Upham Road', '+62 (510) 557-3654'),('Orrey', 'Johnathon', '992 Lyons Place', '+86 (684) 974-9805'),('Grayston', 'Carissa', '13436 Elgar Parkway', '+81 (257) 860-6251'),('Librey', 'Willi', '4244 Almo Trail', '+266 (769) 218-8354'),('Daton', 'Olav', '469 Russell Point', '+86 (906) 445-2523'),('Van der Spohr', 'Coreen', '5731 Stoughton Avenue', '+371 (496) 141-2473'),('Shwenn', 'Marcus', '06 Oak Valley Pass', '+86 (730) 739-1312'),('Garrattley', 'Mathew', '97458 Dixon Lane', '+54 (654) 779-7860'),('Castagnaro', 'Edgard', '4551 Gale Avenue', '+962 (390) 844-3193'),('Broz', 'Anallese', '89 Pond Avenue', '+53 (999) 339-4631'),('Brogan', 'Glendon', '1513 Superior Junction', '+7 (260) 852-3540'),('Hagstone', 'Rab', '55078 Service Pass', '+387 (137) 429-6018'),('Massei', 'Cris', '199 Eagan Drive', '+55 (289) 501-8703'),('Roseaman', 'Aurie', '8 8th Point', '+57 (926) 321-3829'),('Arthars', 'Cacilie', '7 Sherman Road', '+355 (885) 885-8485'),('Lowin', 'Edin', '2 Marcy Lane', '+62 (981) 100-8498'),('Trimme', 'Ronica', '0 Hagan Center', '+62 (202) 978-4136'),('Figg', 'Budd', '3 Hagan Trail', '+381 (953) 320-7314'),('Harlin', 'Dionis', '499 Morrow Road', '+86 (454) 638-9188'),('Chupin', 'Candice', '53000 Almo Court', '+86 (758) 411-1917'),('Gunner', 'Creighton', '10080 Parkside Crossing', '+54 (816) 768-3349'),('Daud', 'Rosemaria', '04 Paget Hill', '+86 (201) 696-0504'),('Renforth', 'Sullivan', '8554 Wayridge Terrace', '+86 (811) 855-6648'),('Hellens', 'Dian', '6130 Mandrake Alley', '+386 (682) 780-5579'),('Rigler', 'Tybi', '55 Nova Avenue', '+233 (606) 679-5162'),('Craze', 'Benedikta', '9304 Michigan Drive', '+7 (758) 689-1872'),('Coslitt', 'Golda', '12195 Johnson Drive', '+880 (472) 677-8070'),('Clayworth', 'Ora', '0 Novick Lane', '+27 (301) 614-6448'),('Hiley', 'Cristen', '208 Graceland Hill', '+51 (477) 326-6645'),('Mealing', 'Petronella', '647 Atwood Lane', '+380 (367) 333-3834'),('Stripling', 'Benedetta', '9221 Elka Trail', '+855 (862) 597-9922'),('Borleace', 'Tammie', '26780 Rigney Crossing', '+62 (170) 347-8211'),('Plews', 'Tony', '8326 Buhler Plaza', '+55 (747) 638-9398'),('Girodin', 'Wanda', '8849 Iowa Street', '+86 (199) 782-2467'),('MacKessock', 'Thadeus', '35 Gina Lane', '+7 (227) 230-8976'),('Shaxby', 'Joline', '974 5th Way', '+380 (438) 639-4348'),('Kix', 'Stanton', '5346 Mallory Road', '+994 (158) 534-0701'),('Ducker', 'Fania', '3 Mayfield Point', '+86 (863) 515-8798'),('Kunze', 'Verney', '0817 John Wall Lane', '+30 (988) 247-8300'),('Cant', 'Willetta', '5192 Gerald Pass', '+63 (436) 708-0761'),('Matuskiewicz', 'Andriette', '72837 Lukken Hill', '+49 (395) 952-3186'),('Deverock', 'Parke', '82468 Pankratz Point', '+380 (251) 628-4665'),('Brunini', 'Joceline', '42 Cambridge Court', '+51 (759) 518-6496'),('Kolis', 'Royall', '51 Kipling Park', '+54 (444) 129-5180'),('Gipp', 'Arthur', '44030 Merchant Hill', '+63 (259) 376-3080'),('McCaig', 'Kimbell', '2738 Mayer Parkway', '+55 (903) 879-9345'),('Heddan', 'Sephira', '3 Del Sol Hill', '+57 (596) 265-9299'),('Boaler', 'Isidoro', '4 Fair Oaks Junction', '+27 (355) 724-5667'),('Rosenzveig', 'Kleon', '2 Trailsway Center', '+86 (703) 476-1933'),('Carless', 'Crichton', '209 American Crossing', '+33 (237) 877-5952'),('Lindegard', 'Tabor', '1 Waubesa Terrace', '+234 (204) 368-0711'),('Tidey', 'Giffard', '7 Charing Cross Plaza', '+86 (553) 752-2906'),('Goldby', 'Brittney', '86051 Mandrake Way', '+63 (337) 687-4633'),('Hardiker', 'Hale', '2719 Columbus Hill', '+93 (879) 567-3455'),('Durrant', 'Ezmeralda', '86409 Ohio Road', '+370 (100) 299-2720'),('Berndtssen', 'Davy', '88 Alpine Crossing', '+81 (691) 254-1888'),('Cargenven', 'Ronna', '724 Fordem Street', '+269 (485) 739-3861'),('Camlin', 'Alfie', '565 Ruskin Crossing', '+351 (286) 528-2094'),('Millington', 'Bee', '8204 Drewry Crossing', '+86 (942) 272-7085'),('Danneil', 'Derrick', '4698 Meadow Valley Drive', '+7 (656) 402-2859'),('Wyldish', 'Caty', '8615 Division Lane', '+55 (541) 579-3545'),('Hunnawill', 'Wilfred', '851 Weeping Birch Alley', '+31 (383) 867-7687'),('Haldene', 'Mireille', '25 Hoard Parkway', '+33 (890) 543-3933'),('Vakhonin', 'Petrina', '26 Milwaukee Road', '+62 (839) 142-9446'),('Millis', 'Hedda', '760 Cascade Point', '+30 (848) 993-9551'),('Eastbrook', 'Marian', '9 Briar Crest Hill', '+57 (260) 466-9843'),('Travis', 'Randal', '05900 Goodland Street', '+30 (307) 460-6251'),('Casillas', 'Carroll', '12 Hanson Park', '+49 (406) 323-6418'),('Vossgen', 'Rosmunda', '9668 Westerfield Drive', '+86 (677) 730-5564'),('Merricks', 'Wallas', '9 Dennis Hill', '+420 (845) 781-7170'),('Costock', 'Alphonso', '27 Anderson Way', '+970 (762) 205-1874'),('Luckhurst', 'Wilmer', '96 Merchant Trail', '+86 (966) 938-2085'),('Genn', 'Anthe', '262 Old Shore Hill', '+353 (703) 998-9827'),('Dibben', 'Jacky', '658 Arizona Terrace', '+880 (196) 646-8171'),('Arnli', 'Janel', '7523 Towne Parkway', '+86 (521) 609-2344'),('Kelway', 'Irena', '19901 East Street', '+86 (398) 840-5182'),('Sinott', 'Ronalda', '78850 Leroy Way', '+7 (273) 619-8457'),('Tumioto', 'Rosemonde', '60338 American Ash Lane', '+64 (944) 553-3778'),('Copestick', 'Querida', '9 Haas Terrace', '+48 (476) 328-2199'),('Bentz', 'Glynis', '64 Red Cloud Trail', '+852 (235) 510-2726'),('McCart', 'Cherish', '504 Hoepker Crossing', '+86 (914) 897-6610'),('Naisey', 'Lucius', '738 Kenwood Parkway', '+92 (400) 494-0025'),('Neicho', 'Lavena', '67320 Bayside Trail', '+62 (752) 957-2746'),('Perrot', 'Nichol', '75214 Maywood Lane', '+62 (875) 609-3697'),('Acum', 'Terri', '5 Vera Terrace', '+48 (992) 667-4553'),('Rayner', 'Aldin', '000 Pierstorff Point', '+46 (102) 586-7242'),('Forryan', 'Garrard', '38621 Farmco Place', '+86 (203) 548-8478'),('Stainburn', 'Sampson', '55168 Ilene Place', '+86 (743) 294-8678'),('Firpi', 'Arny', '578 Ludington Lane', '+63 (115) 596-9057'),('Duckham', 'Ruddie', '88 Trailsway Junction', '+62 (521) 151-5586'),('Linster', 'Lyon', '216 Autumn Leaf Way', '+30 (438) 985-4029'),('Strephan', 'Caron', '9 Dottie Avenue', '+86 (287) 347-3872'),('Element', 'Celestine', '4081 North Center', '+966 (906) 887-6573'),('Southcomb', 'Baryram', '3 Starling Trail', '+57 (485) 863-0378'),('Attlee', 'Farly', '3363 Green Ridge Point', '+86 (828) 214-5461'),('Wenman', 'Myrna', '16 Arkansas Way', '+86 (821) 687-5621'),('Cleall', 'Nedi', '86659 Forest Dale Place', '+62 (737) 303-1990'),('Ludford', 'Trudi', '03803 Becker Street', '+976 (525) 491-2290'),('Kaine', 'Owen', '67 Annamark Court', '+420 (877) 347-5676'),('Breede', 'Arlyn', '0 Grover Plaza', '+62 (251) 993-6268'),('Ladds', 'Kizzee', '1439 Forster Court', '+977 (479) 820-6757'),('Isakson', 'Alexei', '46 Melody Way', '+62 (626) 695-9927'),('Thouless', 'Barbey', '22 Briar Crest Terrace', '+52 (481) 982-4453'),('Spenley', 'Johannah', '005 Havey Park', '+33 (540) 168-4298'),('Iacovacci', 'Arabelle', '7 Monica Avenue', '+86 (814) 228-3247'),('Blaszczyk', 'Doris', '98803 Buell Center', '+30 (790) 347-2009'),('Keher', 'Humberto', '227 Upham Court', '+27 (291) 899-7184'),('Bridel', 'Vonni', '43 Rigney Pass', '+86 (585) 504-1984'),('Frigout', 'Gleda', '81 Crownhardt Hill', '+52 (316) 778-6110'),('Veldens', 'Roscoe', '25 Riverside Terrace', '+86 (585) 741-6001'),('Manketell', 'Loren', '4 Lakewood Gardens Way', '+351 (875) 437-2082'),('Mulhall', 'Christie', '81657 Browning Plaza', '+86 (218) 399-1483'),('Sundin', 'Walsh', '76337 Buhler Road', '+62 (907) 771-6916'),('Sussams', 'Harcourt', '4915 Erie Lane', '+380 (959) 871-6188'),('Sket', 'Amii', '084 School Alley', '+84 (458) 555-3575'),('Tarry', 'Sande', '9196 Armistice Point', '+86 (888) 152-7176'),('Comsty', 'Harwilll', '1596 Golden Leaf Trail', '+255 (652) 356-3377'),('Skarman', 'Cash', '20171 Memorial Place', '+94 (305) 369-1618'),('Brinson', 'Nike', '978 Elmside Junction', '+55 (427) 775-1259'),('De Maria', 'Malcolm', '09423 Killdeer Junction', '+53 (726) 181-3473'),('Harkes', 'Orland', '6 Milwaukee Hill', '+47 (240) 185-3626'),('Chazerand', 'Debora', '38 Sutteridge Hill', '+86 (347) 713-8681'),('Mardee', 'Jandy', '8 Messerschmidt Alley', '+30 (136) 415-1304'),('Kitchinghan', 'Dalt', '2897 Lyons Terrace', '+86 (442) 818-0641'),('Bright', 'Nicolais', '082 Grayhawk Street', '+7 (150) 247-1355'),('Wilford', 'Warde', '1 Sunfield Drive', '+27 (458) 135-8739'),('Biffen', 'Zacharias', '72 Independence Street', '+7 (534) 921-4715'),('Hallifax', 'Biron', '4015 Heath Drive', '+381 (434) 956-3565'),('Rosenblatt', 'Libbie', '72 Oakridge Point', '+86 (304) 762-8346'),('Janjic', 'Burke', '6 Sutherland Avenue', '+84 (229) 608-1259'),('Mansour', 'Winslow', '592 Killdeer Plaza', '+62 (826) 665-8239'),('Baldacchi', 'Shoshana', '0 Warrior Drive', '+7 (832) 991-3179');"; 
						//cout << "insert into subscriber" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql6, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql61 = "insert into subscriber (surname, name, address, number) values ('Creaven', 'Marsha', '9 Judy Circle', '+55 (113) 456-0366'),('Treven', 'Davine', '34 Granby Crossing', '+62 (857) 691-9915'),('Mac Giany', 'Tonia', '80535 Melby Trail', '+86 (500) 672-5596'),('Antonopoulos', 'Yuri', '10454 Southridge Road', '+86 (781) 958-9291'),('Raden', 'Jozef', '8758 Johnson Place', '+81 (112) 221-1369'),('Skillington', 'Vic', '004 Bunting Terrace', '+86 (223) 965-9817'),('Pelling', 'Justus', '3358 Morningstar Avenue', '+86 (853) 411-6359'),('De Vaan', 'Chandal', '45 Warbler Crossing', '+234 (756) 531-9536'),('Maltman', 'Bryn', '2 Bultman Court', '+7 (683) 178-3563'),('Botley', 'Perrine', '29383 Vidon Center', '+48 (218) 465-6739'),('Rowbottom', 'Margaretha', '984 Pawling Junction', '+63 (578) 801-2373'),('Bloom', 'Shelagh', '5317 Sheridan Alley', '+86 (505) 876-5146'),('Sawden', 'Petey', '7701 Cherokee Hill', '+57 (192) 921-7336'),('Bordone', 'Mareah', '19805 Arapahoe Drive', '+358 (472) 840-7165'),('Bodsworth', 'Jordain', '7964 Golf Course Road', '+86 (686) 239-9201'),('De Ambrosis', 'Hugues', '710 Sloan Hill', '+86 (315) 937-3741'),('Whiskin', 'Sashenka', '1102 Laurel Trail', '+55 (202) 642-1337'),('Frarey', 'Bertrando', '3 Lindbergh Center', '+7 (512) 943-7357'),('Klampt', 'Allison', '3752 Upham Trail', '+260 (937) 438-4203'),('Shillabeer', 'Garry', '32286 Butterfield Terrace', '+964 (804) 598-6968'),('Pouck', 'Giorgio', '13915 Linden Crossing', '+86 (997) 425-3662'),('Burghall', 'Lewiss', '9 Packers Center', '+381 (463) 268-9545'),('Gniewosz', 'Cele', '0240 Prentice Trail', '+58 (979) 794-6792'),('Matityahu', 'Benoite', '42 3rd Alley', '+58 (831) 200-6775'),('Jedrzejczak', 'Trula', '4633 Buhler Way', '+33 (310) 237-0675'),('Gallier', 'Gui', '9 Wayridge Court', '+48 (632) 947-2874'),('Maggiore', 'Wait', '818 Forest Parkway', '+967 (691) 145-8935'),('Blitzer', 'Grethel', '7 High Crossing Avenue', '+46 (969) 763-0394'),('Statersfield', 'Tedman', '2389 Schmedeman Plaza', '+7 (268) 752-8983'),('Penhale', 'Bil', '4150 Northwestern Court', '+86 (355) 101-2116'),('Chesley', 'Isabella', '516 Almo Crossing', '+420 (355) 495-2357'),('Simmers', 'Ula', '9 Merrick Place', '+86 (892) 134-9956'),('Burhill', 'Alexandros', '55 Marcy Terrace', '+62 (751) 881-4277'),('Pybworth', 'Ebenezer', '6013 Monument Circle', '+98 (829) 116-7625'),('Leaney', 'Skippie', '828 Anthes Crossing', '+63 (260) 912-6929'),('Scarse', 'Ive', '28138 Crowley Place', '+86 (767) 397-6534'),('Batthew', 'Lenette', '7 Summit Crossing', '+86 (700) 978-1391'),('Cornall', 'Venus', '518 Bartelt Drive', '+351 (843) 508-8843'),('Buggs', 'Frasier', '4584 Park Meadow Parkway', '+53 (950) 399-6270'),('Avery', 'Rosabella', '609 Mockingbird Junction', '+51 (184) 411-0383'),('Morgen', 'Myles', '11760 Hanson Lane', '+351 (628) 470-9367'),('Brogioni', 'Pollyanna', '5817 Artisan Place', '+62 (881) 254-0047'),('Letts', 'Claudian', '6 Messerschmidt Park', '+86 (708) 145-1064'),('Lemme', 'Brietta', '6 Lotheville Drive', '+62 (422) 439-7770'),('Shrive', 'Claybourne', '5927 Crescent Oaks Pass', '+46 (370) 572-1055'),('Flood', 'Anderson', '296 Jackson Point', '+251 (538) 493-8523'),('Isacq', 'Aguistin', '0 Evergreen Avenue', '+66 (936) 862-5442'),('Eyam', 'Mandy', '9 Hauk Circle', '+63 (645) 201-2219'),('Measom', 'Patric', '4333 Westridge Alley', '+86 (370) 763-3345'),('Cossington', 'Kent', '08 Northland Terrace', '+1 (804) 734-2348'),('Mauditt', 'Anet', '87 Melody Trail', '+7 (676) 833-0270'),('Santoro', 'Gaelan', '3 Center Way', '+98 (454) 636-8751'),('Shickle', 'Tucky', '5173 Jackson Plaza', '+81 (804) 740-6218'),('Forge', 'Nita', '474 Grasskamp Road', '+976 (265) 514-1711'),('Garric', 'Kelsey', '04910 Holmberg Alley', '+7 (645) 116-5583'),('Voff', 'Joseito', '819 International Place', '+420 (307) 620-7366'),('Bocken', 'Jaine', '2 Oneill Parkway', '+63 (886) 759-6284'),('Gisburn', 'Dynah', '0798 Forest Run Pass', '+212 (725) 943-2391'),('Charlotte', 'Clair', '1 Truax Hill', '+86 (873) 427-2183'),('Calendar', 'Donny', '3 Dahle Place', '+260 (129) 181-7662'),('Filipchikov', 'Elie', '7 Arapahoe Way', '+86 (832) 279-7282'),('James', 'Angie', '783 Upham Alley', '+86 (526) 480-3811'),('Rudolph', 'Broderick', '204 Thompson Hill', '+381 (760) 106-5591'),('Welton', 'Juli', '2022 Lyons Point', '+358 (433) 168-1443'),('Tapson', 'Sonnie', '95 Johnson Street', '+92 (443) 707-2791'),('Winkett', 'Lari', '49861 Claremont Center', '+86 (339) 752-9240'),('Archell', 'Artemus', '95 Londonderry Park', '+45 (391) 166-9976'),('MacGettigen', 'Shani', '14472 Reinke Street', '+380 (152) 565-4298'),('Naisbet', 'Grissel', '515 Sunbrook Crossing', '+86 (495) 846-5805'),('Sibray', 'Jeramie', '95944 Kipling Street', '+351 (896) 276-5649'),('Pinard', 'Beck', '56 Union Crossing', '+7 (906) 359-4359'),('Dart', 'Ashley', '89 Anderson Avenue', '+62 (364) 634-7173'),('Kealey', 'Viole', '14 Forest Junction', '+86 (693) 679-3276'),('Salling', 'Lida', '60136 North Point', '+46 (907) 766-3168'),('Mogra', 'Anneliese', '46 Union Lane', '+63 (752) 575-0998'),('McDuffy', 'Tybalt', '9506 La Follette Point', '+86 (542) 967-7450'),('Aldie', 'Wendi', '64 Tennyson Circle', '+380 (351) 389-8302'),('Delea', 'Archie', '5 Main Court', '+51 (657) 289-5044'),('De Ambrosi', 'Denyse', '7 Beilfuss Avenue', '+86 (403) 673-7698'),('Mendenhall', 'Nicolea', '50 Prentice Court', '+46 (517) 819-9741'),('Schubert', 'Rosamond', '83 Milwaukee Terrace', '+86 (169) 615-2281'),('Grewer', 'Saree', '6649 Sycamore Court', '+81 (335) 914-8852'),('Sazio', 'Ebony', '83056 Randy Park', '+7 (627) 310-7924'),('Sauter', 'Phyllis', '798 Basil Plaza', '+90 (723) 149-1365'),('Ferrarone', 'Saul', '7 Truax Terrace', '+33 (690) 378-1033'),('Mitro', 'Maxwell', '39 Continental Road', '+251 (320) 161-7521'),('Libermore', 'Willy', '8 Fulton Way', '+33 (735) 988-8848'),('Cookman', 'Cullie', '68177 Old Gate Avenue', '+33 (967) 869-8954'),('Wake', 'Lurette', '27 Main Center', '+386 (971) 787-9318'),('Yeoland', 'Gerek', '5982 Northport Crossing', '+52 (312) 145-1976'),('Mawford', 'Horst', '569 Bartelt Court', '+86 (921) 927-1363'),('Brabin', 'Garrot', '7 John Wall Drive', '+48 (631) 490-3878'),('Simchenko', 'Sybille', '67867 Colorado Point', '+7 (940) 642-7758'),('Pottiphar', 'Balduin', '37 Artisan Drive', '+36 (809) 723-3264'),('Mannie', 'Alameda', '755 Dixon Park', '+66 (213) 633-4678'),('Wetton', 'Joanne', '979 Ridgeview Pass', '+63 (825) 706-5239'),('Doyland', 'Sullivan', '9434 Rowland Plaza', '+86 (386) 136-2413'),('Auden', 'Remington', '0702 Schurz Court', '+255 (326) 929-5374'),('McMillan', 'Thatch', '43555 Tony Court', '+420 (121) 446-6003'),('Cordero', 'Russell', '21 Harbort Place', '+86 (116) 451-3417'),('Manoch', 'Sharity', '6 Doe Crossing Plaza', '+62 (534) 734-8105'),('Grinston', 'Sonnnie', '45341 Victoria Alley', '+92 (455) 948-7111'),('Halse', 'Dinnie', '39734 Fulton Plaza', '+7 (176) 799-5303'),('Elia', 'Maurene', '76952 New Castle Point', '+66 (299) 518-4703'),('Dowdall', 'Dorothea', '1164 Donald Way', '+218 (649) 867-5977'),('Jolly', 'Humfrid', '0431 Schlimgen Court', '+63 (516) 908-8862'),('Best', 'Enrique', '14 Cardinal Alley', '+86 (274) 954-2832'),('Larroway', 'Loree', '423 Lotheville Lane', '+351 (280) 773-5831'),('Galle', 'Marji', '29589 Continental Hill', '+7 (195) 945-9559'),('Gorrie', 'Pauline', '64153 Dixon Point', '+63 (626) 425-2812'),('Petrou', 'Adolpho', '25717 Cherokee Place', '+86 (927) 913-1305'),('Edbrooke', 'Lanny', '9 Pierstorff Way', '+351 (916) 491-7415'),('Howieson', 'Domingo', '4468 Bowman Point', '+84 (298) 702-1606'),('McLese', 'Rianon', '61610 Barnett Crossing', '+86 (730) 525-7666'),('Clem', 'Weber', '698 American Alley', '+52 (549) 154-8461'),('Haggarty', 'Willie', '22 Scott Way', '+992 (768) 455-8578'),('Adnam', 'Mirelle', '99493 Debra Terrace', '+33 (859) 211-5930'),('Molden', 'Carmelia', '42738 Maywood Plaza', '+373 (596) 492-6379'),('Parnall', 'Pincas', '078 1st Junction', '+86 (313) 649-9789'),('McKeefry', 'Doro', '39018 Daystar Circle', '+62 (889) 227-2995'),('Clougher', 'Olva', '9141 Surrey Hill', '+358 (302) 480-8783'),('Crake', 'Tami', '7 Fordem Pass', '+351 (922) 598-2624'),('Tevelov', 'Conn', '507 Hoepker Trail', '+62 (966) 641-9990'),('Dandie', 'Lorrie', '58 Utah Avenue', '+670 (524) 471-4251'),('Helis', 'Worth', '2457 Sherman Trail', '+62 (522) 531-7522'),('Buxsy', 'Lynelle', '59 8th Court', '+98 (977) 399-7872'),('Hearns', 'Myrle', '3 Thompson Circle', '+7 (856) 697-4520'),('Dabrowski', 'Arturo', '60 Loftsgordon Plaza', '+1 (302) 766-1869'),('Foyle', 'Kiele', '249 Laurel Point', '+63 (140) 715-7992'),('Tewes', 'Felic', '90 Maple Crossing', '+48 (456) 406-0263'),('Schwandermann', 'Gayel', '51311 Scoville Circle', '+60 (469) 690-7320'),('Soall', 'Junia', '972 Eagan Court', '+66 (468) 328-2750'),('Grealey', 'Con', '4 Gulseth Hill', '+86 (512) 128-7803'),('Duley', 'Andriette', '5 Nancy Circle', '+60 (854) 120-2910'),('Francais', 'Evangeline', '29 Vernon Pass', '+57 (118) 141-1757'),('Draaisma', 'Carlotta', '77 Bellgrove Court', '+51 (582) 413-2920'),('Ghelarducci', 'Hernando', '235 Hoffman Hill', '+86 (544) 978-8823'),('Bardwell', 'Ali', '19164 Thackeray Park', '+7 (254) 703-7788'),('Gouth', 'Shaw', '6776 Elgar Road', '+381 (736) 251-5129'),('Mowsdill', 'Janelle', '9047 Norway Maple Junction', '+351 (309) 273-6210'),('Borkett', 'Germaine', '044 Glendale Street', '+93 (910) 655-8631'),('Camili', 'Gratiana', '35198 Artisan Parkway', '+86 (323) 409-6000'),('Mithan', 'Thedric', '09 Waxwing Crossing', '+86 (197) 229-2547'),('Huerta', 'Otto', '93 Springview Point', '+62 (676) 415-8778'),('Everex', 'Ibby', '2516 Forster Center', '+62 (349) 428-2852'),('Lampbrecht', 'Sandi', '84770 Saint Paul Crossing', '+7 (460) 902-3738'),('Ebbetts', 'Sisile', '8 Eagan Drive', '+33 (598) 365-2997'),('Wehnerr', 'Terry', '5350 Vermont Circle', '+86 (238) 343-8272'),('Duthy', 'Hollis', '8 Butternut Point', '+86 (745) 271-2220'),('Wharby', 'Julia', '8585 6th Circle', '+48 (743) 254-4097'),('Gosalvez', 'Phip', '1778 Atwood Center', '+30 (892) 746-2566'),('Pesek', 'Tobe', '42 Mesta Drive', '+86 (749) 180-4997'),('Overnell', 'Abra', '10900 Carey Lane', '+62 (504) 722-1700'),('Hutchin', 'Kliment', '9387 Jenna Trail', '+63 (278) 403-7105'),('Condict', 'Dani', '69 Prairieview Street', '+375 (612) 479-7665'),('Tanzer', 'Evanne', '64 Hintze Avenue', '+62 (952) 369-9498'),('Aulds', 'Shepherd', '42 Bluestem Terrace', '+55 (675) 461-1831'),('Coils', 'Danyette', '0 Columbus Lane', '+33 (990) 364-4726'),('Greenhow', 'Mischa', '311 Kim Crossing', '+7 (425) 244-4263'),('Butt', 'Jennifer', '4 Dawn Hill', '+383 (741) 809-7832'),('Alekseicik', 'Lindi', '1 Crowley Plaza', '+55 (626) 381-9746'),('Litel', 'Dee', '8 Reinke Drive', '+55 (389) 771-1553'),('Rohlfing', 'Bryn', '86188 Amoth Pass', '+62 (425) 613-3899'),('Darnody', 'Britni', '605 Lotheville Lane', '+63 (625) 371-4204'),('Ludl', 'Maryjo', '4 Canary Point', '+253 (561) 716-0234'),('Borzoni', 'Tadeas', '5787 Toban Junction', '+380 (328) 302-9800'),('Kettoe', 'Minta', '1 Fairfield Alley', '+500 (671) 854-3331'),('Lancashire', 'Khalil', '980 Waxwing Park', '+244 (702) 254-0347'),('Tuckerman', 'Janeczka', '799 Killdeer Junction', '+86 (360) 902-6103'),('Sautter', 'Town', '2117 Oriole Avenue', '+86 (946) 367-5261'),('McCraine', 'Pen', '7510 Hansons Alley', '+380 (672) 810-6455'),('Grinyov', 'Lari', '576 Pepper Wood Terrace', '+47 (695) 554-4134'),('Hinchshaw', 'Kerk', '39 Prairieview Terrace', '+62 (870) 145-3034'),('Ebbrell', 'Jimmie', '0106 Stang Trail', '+86 (575) 569-3313'),('Tomkiss', 'Geralda', '7 Golf Course Court', '+235 (785) 590-7260'),('Ricciardo', 'Montgomery', '7 Porter Center', '+375 (809) 218-6252'),('Killner', 'Atlanta', '3402 Cambridge Drive', '+7 (855) 831-3237'),('Feltoe', 'Milzie', '7 Scoville Alley', '+46 (411) 104-8801'),('Giraudel', 'Martha', '9 Oakridge Point', '+86 (375) 961-0463'),('Shoulders', 'Alverta', '290 Oak Plaza', '+262 (100) 273-5022'),('Sreenan', 'Shepperd', '0136 Cordelia Junction', '+62 (624) 286-1046'),('Mapledorum', 'Doralyn', '7 Forest Alley', '+62 (330) 335-8658'),('Collingham', 'Mignonne', '62 Browning Way', '+7 (571) 503-9997'),('Dearsley', 'Chiquita', '8 Londonderry Crossing', '+212 (782) 690-0464'),('Roden', 'Judye', '8 Derek Junction', '+86 (717) 742-2505'),('Attride', 'Paige', '92301 Tomscot Hill', '+63 (352) 520-5723'),('Farryann', 'Madelon', '665 Mosinee Junction', '+7 (587) 698-3676'),('Meth', 'Cole', '5 Sachs Place', '+86 (322) 998-7531'),('Cordobes', 'Janette', '92 Bartillon Parkway', '+86 (136) 442-0030'),('Pervew', 'Benjy', '80 Golf Junction', '+48 (772) 984-5212'),('Glynne', 'Keefer', '2 Waywood Lane', '+63 (890) 120-3101'),('Fewster', 'Wash', '95 Moulton Alley', '+235 (531) 124-2563'),('Bittlestone', 'Gannon', '3 Bonner Avenue', '+95 (985) 354-1884'),('Kibble', 'Kaylil', '82209 Jana Circle', '+351 (557) 744-7534'),('Morling', 'Lu', '48 Bay Court', '+63 (786) 201-5147'),('Rhoddie', 'Zandra', '80623 Fair Oaks Park', '+55 (274) 101-0529'),('Ellwood', 'Ingunna', '71 Macpherson Point', '+420 (688) 225-0277'),('Cunniff', 'Margy', '26 Heffernan Place', '+250 (395) 639-3314'),('Paulat', 'Linda', '3 American Plaza', '+355 (824) 310-7652'),('Harkin', 'Thomas', '8459 Summer Ridge Lane', '+45 (829) 585-5288');";
						//cout << "insert into subscriber" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql61, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql62 = "insert into subscriber (surname, name, address, number) values ('Andriesse', 'Thatch', '83953 Schlimgen Trail', '+263 (980) 982-0949'),('Pietrowski', 'Joyann', '6785 Bay Point', '+86 (579) 804-7063'),('Adamoli', 'Nicoli', '9 East Center', '+33 (239) 834-9865'),('Routham', 'Randa', '3 Hayes Court', '+1 (675) 935-2634'),('Pelerin', 'Clarance', '84 Talmadge Court', '+62 (933) 351-7851'),('Drayson', 'Hamil', '2 Dovetail Lane', '+62 (896) 657-9011'),('Wandrach', 'Lezley', '68600 Dorton Center', '+86 (332) 778-0962'),('Keysel', 'Benjamin', '453 Hoffman Alley', '+86 (800) 763-2076'),('Hewlings', 'Lonee', '49031 Orin Way', '+62 (218) 420-0106'),('Ruppeli', 'Adolph', '0 Spenser Way', '+48 (726) 852-4785'),('Ginn', 'Annamaria', '594 Corry Crossing', '+62 (968) 150-3542'),('Emanuelli', 'Marjory', '85229 Florence Court', '+1 (518) 918-9684'),('Magnus', 'Devondra', '8689 Susan Lane', '+370 (824) 710-8329'),('Rupke', 'Nancie', '7 Mendota Court', '+31 (628) 348-9432'),('Bessell', 'Milzie', '40688 Westend Way', '+62 (219) 110-7905'),('Pasque', 'Gilli', '9959 Forest Dale Road', '+62 (610) 900-7009'),('Ianinotti', 'Ransell', '8 Blaine Court', '+420 (195) 569-8601'),('Fairrie', 'Vinni', '6 Buhler Way', '+86 (415) 850-1791'),('Onyon', 'Zackariah', '63 Express Terrace', '+504 (962) 849-0955'),('Ewence', 'Kaleena', '76354 Moland Point', '+27 (159) 598-3371'),('Teodori', 'Ginevra', '21 Eastwood Circle', '+1 (616) 946-8020'),('Dohmann', 'Loydie', '1 Kennedy Hill', '+46 (425) 750-2462'),('Tatford', 'Phaedra', '11010 Jay Lane', '+994 (315) 515-2562'),('Bowerman', 'Graeme', '28 Nobel Road', '+54 (154) 794-9200'),('Kroch', 'Lelah', '1 Transport Alley', '+1 (786) 875-3754'),('MacAindreis', 'Carolann', '5 Vernon Park', '+62 (480) 236-4803'),('O''Moylan', 'Noell', '043 Fordem Crossing', '+233 (401) 454-0459'),('De La Haye', 'Sofie', '532 Dahle Road', '+7 (871) 791-7725'),('Codrington', 'Gloria', '5199 Anhalt Hill', '+7 (360) 303-1253'),('Matevosian', 'Dasie', '49385 Stang Plaza', '+33 (868) 853-4418'),('Trevena', 'Morgan', '0488 Judy Center', '+1 (898) 460-0124'),('Mollen', 'Farrel', '9 Bultman Avenue', '+55 (472) 922-7331'),('Chart', 'Annmaria', '6 Marquette Way', '+86 (770) 451-7982'),('Ledington', 'Benjy', '41193 Butternut Court', '+86 (341) 268-9036'),('Biaggetti', 'Shaina', '0 Dexter Hill', '+94 (480) 858-4659'),('Rutgers', 'Erny', '72245 Buhler Way', '+356 (432) 706-0807'),('Craisford', 'Oran', '2 Pearson Parkway', '+86 (358) 166-4808'),('Agglione', 'Hamid', '4 Shelley Hill', '+230 (936) 310-2055'),('Desport', 'Yalonda', '7633 Rigney Crossing', '+381 (204) 277-5087'),('O''Tuohy', 'Zackariah', '93969 Columbus Court', '+994 (866) 951-0325'),('Bampford', 'Freddy', '886 Duke Avenue', '+63 (516) 371-5594'),('Dolligon', 'Dominick', '91119 Vahlen Hill', '+86 (484) 292-5336'),('Thexton', 'Michal', '78686 Dakota Park', '+86 (771) 888-5781'),('Levicount', 'Layney', '5 Summit Pass', '+86 (974) 367-6842'),('Rentelll', 'Vitia', '8 Washington Road', '+86 (812) 361-4401'),('Lindsley', 'Hurlee', '91617 Fulton Park', '+220 (654) 712-1378'),('Brinkley', 'Susette', '5295 Lighthouse Bay Crossing', '+30 (573) 733-8772'),('Fursland', 'Katie', '17421 Manley Park', '+7 (572) 409-8110'),('Anglin', 'Nicky', '7535 Thompson Way', '+62 (738) 243-7134'),('Mumby', 'Madelene', '76 Glacier Hill Circle', '+370 (114) 593-0670'),('Corrison', 'Mary', '5 Mcguire Parkway', '+7 (811) 368-6262'),('Royall', 'Karia', '35 Sauthoff Crossing', '+62 (182) 112-1679'),('Abbey', 'Sherwin', '8005 Cherokee Avenue', '+420 (852) 436-5209'),('Doubrava', 'Leshia', '09531 Stone Corner Plaza', '+55 (922) 815-1901'),('Grigore', 'Alyss', '634 Veith Junction', '+52 (541) 472-1819'),('Shorte', 'Genevra', '088 Karstens Center', '+62 (502) 435-7622'),('Waggitt', 'Aaren', '10 Bunting Drive', '+86 (652) 310-5734'),('Cammacke', 'Zorina', '7 New Castle Crossing', '+57 (145) 287-4571'),('Leyban', 'Tiphany', '6 Commercial Parkway', '+86 (669) 497-9566'),('Clelle', 'Katharina', '8897 Farmco Terrace', '+380 (426) 961-8274'),('MacCaffrey', 'Wenona', '95794 Green Ridge Terrace', '+63 (330) 228-2270'),('Keen', 'Carlynn', '1 Westport Lane', '+86 (321) 605-5971'),('Bickerdicke', 'Sonia', '5137 Rusk Court', '+261 (924) 332-5078'),('Commucci', 'Rory', '97861 Columbus Hill', '+1 (140) 440-5350'),('Crackel', 'Clayborn', '46341 Continental Crossing', '+351 (855) 504-5785'),('Chadbourn', 'Forrest', '32890 Rockefeller Plaza', '+62 (705) 707-3732'),('Daniau', 'Clemmy', '257 Carpenter Trail', '+62 (393) 391-7346'),('Dimitriev', 'Beltran', '5256 Morrow Center', '+48 (152) 415-0714'),('Blaza', 'Cindee', '88671 Colorado Pass', '+86 (730) 759-1768'),('Girardengo', 'Farrel', '1 Valley Edge Crossing', '+1 (215) 148-9255'),('Lodevick', 'Adi', '018 Hoffman Terrace', '+351 (816) 370-4543'),('Dyter', 'Emilee', '24 Dryden Alley', '+66 (616) 776-7331'),('Trevallion', 'Guenna', '396 Thompson Plaza', '+41 (838) 205-1308'),('Pinckney', 'Amii', '1 Glacier Hill Alley', '+46 (203) 283-7431'),('Stanion', 'Morganne', '1 Corscot Pass', '+62 (719) 764-7703'),('Gittings', 'Birdie', '51 Superior Trail', '+55 (413) 941-1510'),('Dewett', 'Mord', '20 Fisk Way', '+81 (620) 322-9000'),('Biggs', 'Larine', '78465 Marcy Alley', '+502 (363) 247-8745'),('Vaadeland', 'Scotty', '6912 Menomonie Park', '+84 (579) 957-4085'),('Cordy', 'Sybil', '74 South Crossing', '+238 (792) 452-3022'),('Ringrose', 'Angelique', '43729 Meadow Vale Trail', '+86 (682) 592-9857'),('Cummine', 'Redd', '3 Nelson Drive', '+66 (716) 661-4444'),('Tennet', 'Ryon', '2 Jay Alley', '+86 (157) 621-8030'),('Reely', 'Wylma', '16700 Parkside Trail', '+1 (211) 720-2411'),('Brounfield', 'Ellene', '67 Emmet Drive', '+86 (645) 353-3047'),('Nance', 'Brandtr', '4 Kennedy Point', '+86 (442) 815-0772'),('Capaldi', 'Mellisent', '3720 Warner Road', '+353 (704) 547-8743'),('Feasby', 'Tadeo', '2 Thierer Terrace', '+261 (585) 217-7697'),('O''Gleasane', 'Mil', '79016 Spohn Plaza', '+7 (291) 481-4873'),('Feakins', 'Moyra', '1 Darwin Avenue', '+221 (446) 489-6979'),('Welburn', 'Evania', '7 Comanche Pass', '+86 (844) 485-6259'),('Longford', 'Caz', '65 Roxbury Junction', '+507 (228) 398-8253'),('O''Neil', 'Jaimie', '95 Northland Drive', '+374 (316) 256-6780'),('Humberston', 'Inessa', '2080 John Wall Center', '+55 (133) 286-2743'),('Ainley', 'Eugen', '0 Dexter Court', '+351 (709) 275-1999'),('Flay', 'Auria', '39088 Thierer Court', '+82 (181) 360-7967'),('McAnellye', 'Mycah', '73 Moulton Road', '+502 (140) 532-1732'),('Buggy', 'Nani', '34122 Golf Course Lane', '+86 (577) 457-0062'),('Duligal', 'Hendrika', '4406 Pepper Wood Court', '+62 (181) 705-9916'),('Masic', 'Michelle', '84 Del Sol Parkway', '+1 (650) 260-0416'),('Spracklin', 'Etty', '3 Manufacturers Crossing', '+86 (624) 418-4358'),('Dallas', 'Damien', '55054 Eastwood Way', '+62 (669) 918-2686'),('Urquhart', 'Dew', '53376 Di Loreto Pass', '+31 (503) 504-1807'),('Cleevely', 'Selinda', '119 Badeau Plaza', '+62 (263) 826-2638'),('Bartolomeotti', 'Sherilyn', '0550 Magdeline Trail', '+86 (347) 644-9371'),('Maggorini', 'Fedora', '138 Briar Crest Alley', '+86 (353) 453-2268'),('Irvine', 'Ward', '12 Scoville Parkway', '+967 (528) 463-8699'),('Rummings', 'Eddy', '83315 7th Avenue', '+86 (608) 124-8941'),('Dever', 'Thekla', '14862 Oak Valley Park', '+63 (336) 149-3853'),('Wraggs', 'Bettina', '43 Butterfield Court', '+33 (379) 162-5857'),('Rillatt', 'Tomasina', '4 Upham Way', '+62 (897) 947-9477'),('Weatherill', 'Jesse', '1 North Alley', '+63 (458) 619-9039'),('Sneesby', 'Carie', '78 Brown Center', '+351 (563) 559-7234'),('Mathivat', 'Shalna', '5010 Pierstorff Parkway', '+62 (428) 805-3942'),('Osler', 'Agata', '20319 Tennyson Road', '+55 (330) 627-4946'),('Stenet', 'Eugenius', '65643 Dawn Crossing', '+249 (495) 152-8669'),('McGaw', 'Torin', '01 Fuller Drive', '+1 (256) 251-8676'),('Winter', 'Darcy', '3 Mcbride Alley', '+1 (498) 875-9143'),('Cisson', 'Towny', '3 Mallory Road', '+967 (281) 559-5249'),('Yosifov', 'Lorettalorna', '067 Anzinger Center', '+86 (847) 302-6875'),('Rives', 'Ronda', '7 Delladonna Junction', '+355 (149) 182-6596'),('Jahns', 'Marty', '74 Oak Court', '+52 (381) 625-3685'),('Cassar', 'Gabriellia', '81 Mayfield Parkway', '+856 (977) 722-8302'),('Killik', 'Elwyn', '80673 Sullivan Street', '+216 (271) 439-4202'),('Alton', 'Yul', '01139 Stephen Lane', '+351 (525) 645-4504'),('Ollet', 'Bobinette', '285 Rigney Street', '+7 (100) 937-0025'),('McNeice', 'Micky', '48081 Browning Plaza', '+46 (800) 332-8779'),('Valens-Smith', 'Hatti', '4031 Jana Lane', '+33 (151) 622-3035'),('Prynne', 'Leesa', '09 Kingsford Terrace', '+63 (766) 761-9252'),('Jannasch', 'Murial', '3 Everett Parkway', '+886 (836) 918-4610'),('Paulo', 'Kristofer', '14 Dunning Center', '+351 (461) 647-2865'),('Orhtmann', 'Carlynne', '169 South Alley', '+995 (302) 224-9926'),('Harmon', 'Rochester', '5011 Drewry Lane', '+54 (971) 776-7785'),('Annear', 'Hamlin', '34595 Duke Lane', '+86 (567) 587-2776'),('Lockhead', 'Valeda', '833 Elgar Terrace', '+351 (216) 347-3100'),('Wortt', 'Carina', '618 Roxbury Way', '+63 (431) 653-3061'),('Rao', 'Silvie', '8 Linden Hill', '+221 (637) 941-8696'),('Bullier', 'Gratiana', '84252 Straubel Crossing', '+62 (275) 162-9659'),('Harbor', 'Gard', '97649 Northridge Court', '+55 (719) 576-5644'),('Bellward', 'Paxton', '4718 Debs Point', '+62 (279) 202-4594'),('Steanson', 'Bartholomeo', '29561 Goodland Court', '+81 (201) 459-9610'),('Dradey', 'Beaufort', '42 Gina Pass', '+58 (651) 320-5696'),('Vaillant', 'Zack', '3 Raven Park', '+46 (591) 843-1239'),('Effaunt', 'Braden', '18795 Gulseth Circle', '+33 (362) 462-6039'),('Crossland', 'Randie', '02895 Fairview Drive', '+233 (360) 406-9303'),('Westphal', 'Traver', '29 Mitchell Place', '+53 (445) 136-6452'),('Beddoe', 'Eleen', '0 Maple Road', '+263 (749) 521-6749'),('Thomson', 'Tomas', '33407 Porter Hill', '+55 (368) 329-6490'),('Gerretsen', 'Nelson', '0512 Arizona Hill', '+62 (101) 646-1249'),('Mattiassi', 'Karoline', '31 Londonderry Parkway', '+48 (763) 877-1620'),('Roust', 'Nadeen', '291 New Castle Crossing', '+82 (100) 828-3116'),('Izakovitz', 'Edmon', '7 Walton Junction', '+86 (747) 299-6220'),('Triggs', 'Zebadiah', '04 Bobwhite Place', '+62 (935) 880-1487'),('Croley', 'Dannel', '7301 Vernon Terrace', '+351 (233) 724-2011'),('Tremaine', 'Blakelee', '90 Kipling Street', '+385 (267) 751-2578'),('Mackerel', 'Cammi', '8069 Spohn Circle', '+86 (873) 342-4379'),('Robert', 'Vivien', '42 Shopko Circle', '+86 (997) 256-5573'),('Macartney', 'Fraser', '2 Sunbrook Avenue', '+62 (531) 612-2888'),('Jeandet', 'Robbert', '4 Holmberg Place', '+58 (922) 758-2364'),('Brabben', 'Rudd', '7 Coolidge Alley', '+54 (456) 530-2113'),('Matfield', 'Cale', '465 Acker Alley', '+82 (364) 844-9769'),('Seignior', 'Maddy', '3866 Merchant Hill', '+48 (506) 836-7121'),('Tripney', 'Rahal', '05836 Eliot Court', '+1 (651) 241-0846'),('Ireson', 'Gloriane', '6635 Marquette Center', '+86 (814) 594-9163'),('Stephens', 'Eden', '322 Schiller Hill', '+57 (311) 820-1207'),('O''Docherty', 'Hobard', '17 Harbort Place', '+267 (461) 541-4039'),('Buffin', 'Chev', '0407 Meadow Ridge Court', '+1 (540) 339-9895'),('Pentin', 'Mead', '61 International Plaza', '+44 (926) 615-0845'),('Macro', 'Karoly', '9255 Nobel Way', '+355 (185) 220-9257'),('Gurnee', 'Alf', '66 North Road', '+420 (323) 214-3702'),('Nutman', 'Vina', '2 Eastwood Alley', '+358 (633) 546-2918'),('Scrauniage', 'Cosme', '1245 Upham Trail', '+976 (366) 476-4482'),('Jutson', 'Maritsa', '51 Ilene Court', '+62 (284) 655-5707'),('Skyram', 'Archibold', '30560 Straubel Junction', '+51 (164) 623-7926'),('Smitherman', 'Thadeus', '55690 Lighthouse Bay Terrace', '+7 (566) 214-4644'),('Ben', 'Alphonse', '2441 Algoma Street', '+236 (186) 362-8987'),('Uccello', 'Jeremie', '18399 Pond Point', '+7 (351) 701-8265'),('Houchen', 'Tristan', '0 Moose Way', '+62 (789) 571-0351'),('Aggs', 'Kathy', '4507 High Crossing Road', '+375 (411) 340-2870'),('Matuszinski', 'Rustie', '975 Hudson Circle', '+46 (400) 495-0810'),('Latour', 'Nevins', '99 Esch Center', '+47 (406) 649-4092'),('Fillingham', 'Blancha', '72517 Fisk Park', '+86 (596) 889-6603'),('Stollberger', 'Bondie', '82 Marcy Road', '+30 (134) 878-6111'),('Garbutt', 'Cordey', '50 Macpherson Pass', '+1 (813) 592-2787'),('MacKerley', 'Gray', '123 Valley Edge Junction', '+62 (976) 584-3792'),('Goeff', 'Lynelle', '34 Sugar Road', '+352 (354) 318-0992'),('Crimes', 'Tybi', '29566 Grover Lane', '+27 (548) 205-2619'),('L''oiseau', 'Rafa', '3 Pierstorff Circle', '+81 (367) 445-5876'),('Crighton', 'Etienne', '4 Victoria Court', '+30 (179) 797-4697'),('Brenton', 'Gwynne', '908 Esker Place', '+66 (595) 135-6139'),('Vamplus', 'Valerye', '2264 Petterle Way', '+62 (897) 280-3632'),('Vasishchev', 'Bobette', '74802 Springview Way', '+86 (774) 126-6219'),('Isson', 'Onofredo', '7611 Dwight Terrace', '+267 (399) 478-0136'),('Franke', 'Christean', '29 Aberg Place', '+226 (516) 119-6856'),('Jarlmann', 'Loleta', '523 Graceland Junction', '+371 (993) 153-7705'),('Parysowna', 'Brietta', '1 Almo Pass', '+86 (505) 267-9744'),('Innocenti', 'Gabrielle', '4 Melvin Hill', '+86 (401) 188-9770'),('Fruin', 'Ardyth', '58949 Eastwood Park', '+63 (559) 932-6653'),('Kennally', 'Blakelee', '3 Marquette Lane', '+33 (192) 990-3113'),('Hansom', 'Barbara', '038 Katie Court', '+63 (371) 172-2177');";
						//cout << "insert into subscriber" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql62, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql63 = "insert into subscriber (surname, name, address, number) values ('Pittford', 'Hyacinthe', '17229 Express Alley', '+351 (593) 314-3009'),('Pryde', 'Fayre', '72 Maple Wood Junction', '+7 (441) 519-0946'),('Upward', 'Eustacia', '24104 Amoth Point', '+46 (448) 860-0727'),('Mountford', 'Chas', '5 Vermont Terrace', '+62 (667) 992-7596'),('Fiddiman', 'Hayward', '2 Moland Crossing', '+86 (354) 941-8051'),('Pincott', 'Edythe', '26 Ramsey Crossing', '+7 (508) 570-4113'),('Caneo', 'Lizabeth', '403 Clove Alley', '+380 (100) 671-9500'),('Stollery', 'Bernardo', '4 3rd Road', '+504 (544) 105-9534'),('Aleksic', 'Hinda', '049 8th Park', '+7 (308) 395-5226'),('Querree', 'Menard', '11 Rusk Plaza', '+48 (419) 629-0958'),('Godard', 'Bale', '54 Kinsman Place', '+7 (659) 631-2384'),('Newdick', 'Thorn', '68 Monterey Park', '+48 (311) 770-8416'),('Shavel', 'Lanna', '7722 Hansons Drive', '+269 (341) 862-1068'),('Jacques', 'Myrna', '8814 Sage Terrace', '+7 (848) 823-5063'),('Rake', 'Louie', '97481 Goodland Crossing', '+7 (315) 252-9145'),('Allman', 'Marcel', '795 Spenser Avenue', '+47 (646) 987-0117'),('Greydon', 'Lesley', '73497 Brickson Park Way', '+33 (807) 342-8252'),('Glyne', 'Seana', '8245 Tennyson Park', '+86 (518) 247-8472'),('Cruces', 'Dewitt', '8 Warbler Terrace', '+66 (249) 687-0545'),('Beek', 'Warner', '08 Kensington Terrace', '+502 (321) 693-5288'),('Chitty', 'Mignonne', '669 Brickson Park Avenue', '+63 (778) 743-7880'),('Corbould', 'Deanna', '441 Sunnyside Street', '+84 (352) 653-5393'),('Featherstonhalgh', 'Elvina', '888 Hanover Hill', '+55 (493) 285-7927'),('Neller', 'Hanan', '00256 Pepper Wood Avenue', '+98 (114) 510-5777'),('Writtle', 'Sauveur', '973 Nobel Point', '+93 (511) 409-0041'),('Guilbert', 'Lela', '74101 Columbus Trail', '+63 (692) 510-8594'),('Tousy', 'Vally', '101 Macpherson Court', '+86 (316) 464-8515'),('Gobel', 'Jacky', '12100 Mallard Plaza', '+81 (812) 490-1276'),('Stuckford', 'Sophronia', '09 Monument Drive', '+86 (694) 902-0506'),('Meneghi', 'Mariellen', '029 Maywood Point', '+55 (910) 248-9168'),('Grimmert', 'Oliver', '0291 Cottonwood Crossing', '+33 (136) 912-1577'),('Fautley', 'Freeland', '0 Springs Drive', '+86 (407) 405-8346'),('Stonhouse', 'Natalie', '892 Arkansas Street', '+86 (115) 321-5827'),('Seniour', 'Gamaliel', '40 Arizona Way', '+7 (814) 480-5392'),('Nequest', 'Waiter', '6340 Welch Terrace', '+220 (902) 177-3774'),('Maxworthy', 'Lewes', '32 Nobel Drive', '+62 (949) 949-9946'),('Besantie', 'Katrinka', '73 Spaight Way', '+55 (469) 657-5826'),('Goney', 'Adelina', '4 Twin Pines Drive', '+82 (445) 605-1119'),('Kipling', 'Kimbra', '66 Hermina Terrace', '+62 (368) 709-0940'),('Ambroziak', 'Hernando', '3443 Delaware Way', '+62 (998) 175-5221'),('Goodhew', 'Lauritz', '7722 Debra Junction', '+7 (308) 232-1143'),('Zeale', 'Dore', '60198 Gale Terrace', '+33 (167) 291-2758'),('Clavering', 'Mace', '769 Arrowood Plaza', '+55 (330) 218-3350'),('Dewes', 'Reggy', '67 2nd Parkway', '+62 (486) 153-1731'),('McCromley', 'Constantine', '5038 Saint Paul Lane', '+62 (248) 992-1202'),('Raggett', 'Tanitansy', '678 Scoville Plaza', '+970 (695) 897-1163'),('Jakubovicz', 'Keen', '2623 Esker Road', '+63 (753) 465-8555'),('Deavall', 'Zechariah', '60036 Corben Road', '+86 (335) 622-4219'),('Cribbin', 'Gherardo', '37665 Fuller Alley', '+7 (428) 968-4534'),('De Bruijn', 'Adda', '70718 Express Junction', '+62 (328) 889-5047'),('Barnwall', 'Rafa', '7 Commercial Road', '+1 (754) 230-5616'),('Yurocjkin', 'Gertie', '15 Swallow Way', '+86 (144) 228-5534'),('Curtiss', 'Betty', '5530 Pierstorff Way', '+52 (733) 915-9098'),('Ogger', 'Kellie', '7685 Hoard Point', '+358 (858) 170-7317'),('Leachman', 'Dasi', '743 Briar Crest Court', '+62 (861) 447-6724'),('Van T''Hoog', 'Ailbert', '4403 Emmet Street', '+34 (923) 528-8339'),('Hakking', 'Shanan', '26967 Milwaukee Plaza', '+1 (800) 660-6314'),('Climie', 'Valentijn', '52 Novick Road', '+86 (997) 911-4960'),('Hewes', 'Karin', '7268 Waxwing Crossing', '+7 (892) 997-5037'),('Morl', 'Gerrie', '9 Brickson Park Circle', '+63 (894) 608-2854'),('Hanssmann', 'Adara', '32 Sundown Junction', '+86 (284) 565-0613'),('Holton', 'Jacquette', '120 Springview Trail', '+86 (564) 658-9939'),('Kimbley', 'Anallise', '03453 Kings Point', '+62 (189) 621-3988'),('Dunkerton', 'Hugibert', '424 Del Sol Avenue', '+62 (549) 627-4549'),('Tumbridge', 'Rene', '817 Thierer Place', '+62 (791) 122-9080'),('Lammie', 'Leslie', '15826 Carpenter Drive', '+387 (391) 624-6234'),('Sieghard', 'Stafford', '203 Ronald Regan Center', '+30 (231) 205-8952'),('Berndsen', 'Jacinda', '99341 Drewry Place', '+30 (881) 945-8989'),('Tefft', 'Ebba', '24 Merrick Park', '+30 (250) 590-6467'),('Serotsky', 'Moira', '77757 Iowa Road', '+63 (255) 915-0602'),('Vogeler', 'Finley', '611 Sunfield Terrace', '+86 (717) 644-0693'),('Jiroutek', 'Jewel', '963 Aberg Circle', '+7 (582) 111-9391'),('Grossier', 'Paloma', '50 Dovetail Park', '+86 (824) 467-5617'),('Bardsley', 'Kissiah', '449 Clemons Drive', '+48 (603) 569-2070'),('Miles', 'Gabie', '617 Boyd Plaza', '+33 (382) 243-5437'),('Snawdon', 'Donetta', '4 Cascade Circle', '+86 (744) 297-2785'),('Tomaszek', 'Florrie', '17 Bunting Place', '+48 (861) 316-2564'),('Helm', 'Karia', '20429 Rutledge Street', '+33 (535) 517-6782'),('Di Bernardo', 'Ferdinand', '8269 Everett Drive', '+260 (339) 911-4904'),('Bryant', 'Lesley', '15 Carberry Trail', '+507 (148) 782-4854'),('Goudge', 'Valle', '1132 Maple Place', '+86 (514) 193-4244'),('Bargh', 'Mirabella', '3 Spohn Avenue', '+234 (251) 603-8373'),('Matyasik', 'Charmian', '557 Bunting Hill', '+380 (731) 305-6861'),('Gomby', 'Emilie', '508 Derek Circle', '+86 (394) 717-2964'),('Fidge', 'Nanette', '90618 Kedzie Street', '+234 (631) 278-4347'),('Byford', 'Nichols', '69 High Crossing Junction', '+33 (589) 520-3691'),('Witty', 'Timmy', '04 Killdeer Street', '+27 (358) 720-9579'),('Mowle', 'Ellerey', '8317 Saint Paul Plaza', '+31 (217) 724-6251'),('Dullingham', 'Killian', '3 Alpine Hill', '+7 (117) 977-4693'),('Mityakov', 'Raynell', '2107 Rockefeller Court', '+351 (694) 563-8420'),('Hallex', 'Estele', '2 Sunfield Avenue', '+40 (551) 850-1303'),('Rotchell', 'Hesther', '7065 Talisman Junction', '+420 (914) 642-3762'),('Skae', 'Shanda', '90 Merrick Drive', '+1 (195) 859-4707'),('Humbles', 'Rooney', '7 Pierstorff Road', '+1 (469) 206-8864'),('Doneld', 'Anetta', '138 Jenifer Way', '+86 (391) 693-5593'),('Kreber', 'Appolonia', '4330 Leroy Point', '+386 (625) 707-1458'),('Davidowsky', 'Cleve', '0 Bluestem Road', '+351 (869) 774-9636'),('Hothersall', 'Malanie', '7 Oriole Center', '+351 (998) 428-9860'),('Calway', 'Wilfrid', '2750 Victoria Place', '+86 (744) 992-9234'),('Frankowski', 'Lea', '07641 Riverside Pass', '+420 (476) 829-6507'),('Skehens', 'Aline', '770 Crest Line Alley', '+81 (960) 336-4312'),('Burstowe', 'Milt', '82359 Kennedy Court', '+46 (902) 660-3967'),('Dullard', 'Blaire', '47 Dorton Point', '+258 (355) 905-0760'),('Sunners', 'Arman', '67 Springview Street', '+420 (434) 645-5100'),('Tidmarsh', 'Shanan', '6982 Bunker Hill Junction', '+1 (412) 468-2376'),('Clerk', 'Hussein', '62937 Colorado Parkway', '+62 (251) 656-8825'),('Philipp', 'Stillmann', '31 Canary Parkway', '+385 (656) 287-2698'),('Lanphier', 'Muriel', '365 Orin Parkway', '+62 (360) 921-4638'),('Randerson', 'Leonanie', '824 Cordelia Center', '+52 (404) 203-9395'),('Hinkens', 'Jackqueline', '23 Carioca Parkway', '+86 (199) 196-3152'),('Putt', 'Clarie', '4 Briar Crest Point', '+506 (412) 176-6186'),('Tollady', 'Carma', '698 Service Junction', '+385 (875) 645-6643'),('Osbourne', 'Koralle', '3537 Mallory Road', '+351 (711) 491-3378'),('Guitonneau', 'Holli', '4 Daystar Circle', '+27 (303) 734-6630'),('Forsdike', 'Marylin', '9 Tennessee Lane', '+54 (600) 276-2479'),('Hegerty', 'Wakefield', '2 Killdeer Junction', '+55 (562) 347-8723'),('Hares', 'Jackqueline', '14501 Macpherson Junction', '+258 (476) 479-9765'),('Krollmann', 'Cathrine', '630 Charing Cross Pass', '+47 (221) 617-7741'),('Klamp', 'Pia', '07694 Summer Ridge Hill', '+86 (571) 689-9949'),('Damiata', 'Mamie', '56967 Vermont Way', '+380 (301) 250-4123'),('Huitt', 'Isaiah', '7 Calypso Park', '+86 (648) 176-7093'),('Fernley', 'Granger', '353 Cherokee Center', '+86 (260) 164-0527'),('Christophers', 'Gabie', '7 Cottonwood Parkway', '+86 (278) 114-4759'),('Gosker', 'Willabella', '76 Talisman Park', '+380 (340) 926-3797'),('Ivankov', 'Alfy', '2090 Erie Pass', '+46 (192) 236-3013'),('Shotboulte', 'Celestine', '6785 Lakewood Crossing', '+996 (849) 892-1159'),('Mapledorum', 'Loralyn', '23 Bartillon Crossing', '+62 (771) 586-7313'),('Scotchmoor', 'Orren', '181 Burning Wood Street', '+63 (256) 101-6707'),('Stopher', 'Marion', '76222 2nd Junction', '+420 (559) 459-5697'),('Coulbeck', 'Ursula', '4 Boyd Lane', '+1 (299) 815-2173'),('Tattersfield', 'Court', '31835 Maywood Court', '+63 (396) 171-4083'),('Buckberry', 'Irina', '026 Declaration Lane', '+93 (467) 661-0762'),('O''Day', 'Waiter', '7 Stone Corner Plaza', '+86 (994) 483-0155'),('Posthill', 'Danella', '91 Tony Park', '+86 (517) 162-5838'),('Licciardi', 'Ronny', '8 2nd Junction', '+212 (380) 228-5419'),('Bardey', 'Gwenora', '9 Pleasure Junction', '+84 (219) 204-4654'),('Coxwell', 'Sunshine', '038 3rd Terrace', '+62 (928) 325-2360'),('Pook', 'Eleni', '2063 Paget Hill', '+34 (328) 295-2813'),('Gilsthorpe', 'Linn', '1144 Elka Alley', '+48 (110) 228-8197'),('Sauter', 'Joell', '04 Larry Court', '+33 (721) 660-1964'),('Albion', 'Jessika', '02326 Calypso Park', '+33 (887) 893-9831'),('Saintsbury', 'Marcelo', '0 Grover Junction', '+7 (855) 551-2186'),('Asp', 'Leeann', '0 Porter Place', '+53 (125) 391-2038'),('Petley', 'Eolanda', '217 Vidon Circle', '+63 (772) 977-9030'),('Reyne', 'Evangeline', '8500 Sullivan Avenue', '+86 (330) 744-9125'),('Oulet', 'Francesca', '6 Eastlawn Lane', '+254 (807) 233-4823'),('Readmire', 'Horton', '610 Homewood Alley', '+1 (890) 143-2555'),('Daniells', 'Archaimbaud', '7854 Barby Street', '+86 (695) 347-8431'),('Ridsdole', 'Cherlyn', '82272 Nobel Junction', '+86 (478) 164-2905'),('Dodsley', 'Mathilde', '2 Scofield Point', '+86 (311) 583-5070'),('Garnson', 'Valentine', '06855 Golf Course Plaza', '+62 (856) 521-7594'),('Pischoff', 'Guillema', '02139 Hanover Crossing', '+54 (204) 481-5536'),('Phelip', 'Alanah', '7862 Old Shore Crossing', '+86 (642) 408-7069'),('Paullin', 'Lisle', '770 Stang Junction', '+84 (701) 665-6226'),('Tzar', 'Janette', '6 Miller Point', '+66 (172) 729-4352'),('Paxforde', 'Randie', '7068 Summer Ridge Road', '+63 (894) 369-5497'),('Hessing', 'Bryn', '084 Ohio Drive', '+48 (367) 628-7364'),('Atwell', 'Spense', '2512 Oxford Parkway', '+504 (778) 795-1607'),('Rozier', 'Corette', '086 Tomscot Junction', '+255 (117) 285-1951'),('Ewebank', 'Arluene', '9876 Dunning Place', '+86 (740) 486-4921'),('Kopke', 'Connie', '4011 Oneill Crossing', '+84 (855) 737-3251'),('Bebb', 'Gwenneth', '32881 Northland Drive', '+7 (425) 518-5360'),('Richings', 'Desiree', '2243 Park Meadow Court', '+86 (600) 227-4020'),('Fitchet', 'Garek', '56 Ramsey Street', '+51 (470) 416-4982'),('Alderwick', 'Trip', '064 Toban Hill', '+86 (494) 987-7321'),('Storr', 'Denis', '7 Pine View Lane', '+62 (670) 837-1516'),('Nickolls', 'Humbert', '069 Thackeray Court', '+7 (196) 993-8641'),('Tilling', 'Flori', '0 Charing Cross Trail', '+81 (715) 872-0178'),('Ambrois', 'Ossie', '5986 Mendota Avenue', '+225 (698) 550-7119'),('Muff', 'Karine', '92 Sunfield Junction', '+62 (787) 134-0020'),('Roome', 'Sigfrid', '7657 Erie Pass', '+62 (239) 217-0507'),('Fearfull', 'Tish', '76053 Corry Park', '+63 (709) 781-9446'),('Tiptaft', 'Toni', '95097 Morningstar Terrace', '+380 (232) 684-0135'),('Benian', 'Aubrie', '034 Manufacturers Place', '+63 (699) 368-8867'),('Sargeant', 'Gary', '1 Dryden Point', '+387 (732) 800-4753'),('Gellett', 'Valentia', '99 Fallview Alley', '+30 (512) 262-6752'),('Bracken', 'Fayette', '0461 Northridge Trail', '+224 (672) 967-5287'),('Fermin', 'Eloise', '173 Morrow Terrace', '+86 (143) 269-7899'),('Bricket', 'Rosamond', '8 Carpenter Hill', '+86 (287) 221-7591'),('Ledgerton', 'Pegeen', '61085 Lukken Road', '+976 (936) 886-4072'),('Rounsivall', 'Dannie', '649 Buhler Parkway', '+62 (852) 663-1256'),('Hallam', 'Daryn', '68 Del Mar Crossing', '+54 (322) 478-1911'),('Sanpher', 'Sumner', '31 Victoria Hill', '+234 (449) 194-2021'),('Hestrop', 'Baryram', '2 Dakota Place', '+46 (256) 596-6314'),('Sawday', 'Drake', '47743 Fair Oaks Park', '+62 (799) 741-8437'),('Whitear', 'Jerald', '25 Rutledge Terrace', '+249 (576) 591-1347'),('Rimour', 'May', '6 International Point', '+62 (889) 996-1686'),('Clibbery', 'Cecelia', '74 Green Terrace', '+7 (548) 275-9551'),('Ryburn', 'Joletta', '7 Northfield Point', '+92 (417) 478-1980'),('Reynard', 'Simone', '823 Artisan Avenue', '+55 (866) 879-9715'),('McComas', 'Kurt', '3185 Atwood Junction', '+66 (309) 130-8247'),('Giddins', 'Hall', '9 Anniversary Drive', '+53 (101) 296-7225'),('Astley', 'Arlan', '21113 Artisan Park', '+62 (428) 863-6118'),('Huws', 'Callean', '102 Granby Center', '+81 (928) 438-7123'),('Withers', 'Fitz', '35798 Ridge Oak Center', '+51 (344) 700-8201'),('Twamley', 'Iormina', '3 Lotheville Drive', '+355 (697) 196-7759'),('Pargetter', 'Michaella', '328 Pleasure Terrace', '+62 (162) 760-8897'),('Joliffe', 'Munroe', '47063 Buhler Park', '+260 (924) 290-8430'),('Doy', 'Darryl', '0642 Monterey Avenue', '+48 (182) 366-0327'),('Burgne', 'Tybi', '010 Fieldstone Lane', '+27 (803) 281-4213');";
						//cout << "insert into subscriber" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql63, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql64 = "insert into subscriber (surname, name, address, number) values ('Clem', 'Waverley', '29 Kropf Way', '+351 (964) 463-0306'),('Thurlow', 'Romola', '5 Eastwood Park', '+52 (369) 223-1036'),('Cammish', 'Rozanne', '378 Oak Circle', '+86 (936) 138-0110'),('Klimashevich', 'Dolph', '2828 Northwestern Drive', '+7 (221) 955-1437'),('Tolliday', 'Channa', '81 Forster Alley', '+63 (803) 844-2565'),('Ottery', 'Judye', '479 Judy Alley', '+86 (537) 377-0898'),('Oleszkiewicz', 'Etienne', '9545 Paget Place', '+387 (848) 556-4586'),('Rowson', 'Aurelie', '8074 Transport Way', '+380 (291) 867-3011'),('Sexti', 'Caritta', '244 Mallory Road', '+86 (432) 947-3156'),('Wileman', 'Geoff', '03601 Manufacturers Pass', '+33 (720) 860-8925'),('Pegden', 'Alva', '51490 Rusk Center', '+86 (126) 479-4233'),('Lepere', 'Silvana', '46474 School Road', '+7 (328) 271-7891'),('Gallant', 'Roby', '8624 Caliangt Pass', '+62 (906) 618-9316'),('Barlace', 'Lawrence', '58269 Bayside Point', '+256 (504) 266-6302'),('Kapelhoff', 'Lucius', '06699 Portage Alley', '+86 (610) 619-4865'),('Parlett', 'Raul', '3 Loomis Parkway', '+86 (795) 236-9410'),('Butchard', 'Josie', '22 8th Hill', '+351 (578) 523-4077'),('Emmer', 'Joannes', '3630 Lotheville Junction', '+86 (313) 672-5612'),('Dhillon', 'Jen', '0694 Crescent Oaks Junction', '+52 (634) 687-7138'),('Huck', 'Lexine', '299 Armistice Trail', '+86 (421) 969-6176'),('Reboul', 'Di', '3 Schiller Parkway', '+62 (535) 726-5401'),('Lidgely', 'Norene', '451 Reinke Place', '+33 (149) 868-9094'),('Braysher', 'Lanny', '2335 Shoshone Way', '+255 (239) 761-8573'),('Gouch', 'Marrilee', '08004 Lillian Way', '+86 (877) 633-6563'),('Simeoni', 'Angelique', '7557 Raven Parkway', '+33 (139) 362-6178'),('Gammie', 'Edwin', '9479 Melody Park', '+505 (894) 196-4851'),('Billie', 'Manda', '27 Acker Avenue', '+86 (632) 793-7524'),('Lambird', 'Ludwig', '25867 Sloan Court', '+62 (729) 331-9682'),('Valder', 'Nickolai', '93 Northland Junction', '+420 (128) 880-3211'),('Dopson', 'Monro', '1545 Namekagon Parkway', '+30 (248) 137-8664'),('aManger', 'Nonah', '88 Amoth Hill', '+7 (367) 206-1417'),('Crowd', 'Saul', '36841 North Plaza', '+30 (409) 400-9922'),('Dainton', 'Aidan', '9 Sunbrook Pass', '+62 (416) 348-9266'),('Fremantle', 'Rena', '4 Manley Hill', '+54 (193) 551-2196'),('Doneld', 'Ade', '9 Superior Street', '+55 (540) 642-4871'),('Wanne', 'Thom', '63631 Westridge Pass', '+61 (476) 293-3733'),('Decaze', 'Grissel', '67248 Blue Bill Park Crossing', '+225 (630) 262-9884'),('Nice', 'Nike', '2 Marcy Point', '+382 (670) 773-3339'),('Scholz', 'Barbaraanne', '440 Nancy Drive', '+351 (852) 162-9898'),('Pirie', 'Timoteo', '5 Carpenter Avenue', '+52 (706) 966-4846'),('MacRirie', 'Minnie', '976 Park Meadow Avenue', '+7 (149) 215-2064'),('Mathivet', 'Sashenka', '92 Banding Trail', '+387 (877) 933-9513'),('Dudin', 'Filbert', '76427 Spaight Lane', '+63 (836) 502-4887'),('Towsie', 'Daune', '64466 Graedel Junction', '+261 (794) 411-7106'),('Beamand', 'Breena', '27 Brentwood Point', '+51 (512) 534-9548'),('Wardhough', 'Sigmund', '285 Meadow Valley Drive', '+55 (416) 215-0856'),('Cicutto', 'Astrid', '74 Lotheville Court', '+86 (715) 816-7767'),('Grunder', 'Audre', '703 Katie Trail', '+30 (851) 973-4423'),('Oscroft', 'Holli', '7269 1st Alley', '+92 (625) 417-6480'),('Sealove', 'Gael', '7392 Novick Terrace', '+7 (853) 823-8595'),('Northridge', 'Giacopo', '29 American Hill', '+7 (740) 472-1129'),('Murrock', 'Rickert', '8 Hagan Court', '+374 (783) 751-3194'),('Gerriet', 'Maria', '39371 Alpine Street', '+356 (773) 937-0640'),('Mault', 'Lonnie', '93 Meadow Vale Place', '+86 (662) 606-8441'),('Kobu', 'Garek', '08749 Carberry Street', '+55 (186) 814-0181'),('Langfield', 'Selina', '173 Cody Parkway', '+86 (717) 738-4515'),('Petersen', 'Kean', '95 Sutherland Center', '+255 (258) 222-8602'),('Plak', 'Jamie', '70451 Waubesa Parkway', '+27 (926) 287-6038'),('Acock', 'Zeb', '4034 Melby Point', '+86 (202) 167-2144'),('Conigsby', 'Lyssa', '89002 Blaine Crossing', '+81 (937) 622-0725'),('Claye', 'Pennie', '42 Pankratz Pass', '+359 (580) 953-6489'),('Elloit', 'Dougy', '6876 Fremont Hill', '+86 (465) 817-0525'),('Novak', 'Finn', '01 Twin Pines Parkway', '+254 (598) 841-4814'),('Benneyworth', 'Brennen', '146 Bunker Hill Drive', '+48 (731) 623-6890'),('Furzey', 'Karmen', '9 Monument Pass', '+504 (386) 178-2038'),('Thonger', 'Jourdan', '60724 Sunbrook Crossing', '+48 (182) 902-1250'),('Garbert', 'Abdul', '962 Buell Lane', '+55 (677) 204-8735'),('Georgot', 'Lilah', '4 Anhalt Road', '+7 (841) 530-3777'),('Donnell', 'Rachel', '6330 Upham Junction', '+66 (754) 436-3204'),('Goodbarne', 'Ninnetta', '4850 Debs Lane', '+55 (814) 600-2961'),('Jacquemy', 'Giff', '4 Graedel Plaza', '+63 (564) 366-2097'),('Alfonsini', 'Frank', '486 Memorial Terrace', '+420 (778) 361-4379'),('Allridge', 'Lucine', '0493 Algoma Parkway', '+62 (205) 254-5999'),('Hugk', 'Neddie', '76 Delladonna Parkway', '+62 (269) 313-7251'),('Viant', 'Bron', '0 Killdeer Lane', '+86 (385) 308-0781'),('Pierpoint', 'Bobbee', '10795 Everett Center', '+63 (893) 991-8249'),('Sottell', 'Sigrid', '97 Sunfield Street', '+420 (739) 836-0652'),('Shutte', 'Rafaelita', '0 Arizona Circle', '+63 (901) 460-0981'),('Flaune', 'Caroljean', '2668 Continental Pass', '+351 (757) 646-1193'),('Viggers', 'Zelda', '9 Sullivan Center', '+234 (630) 256-7590'),('Edlington', 'Leelah', '7 Utah Way', '+63 (844) 166-2365'),('Laverenz', 'Candis', '239 Gale Drive', '+1 (503) 623-9932'),('Haster', 'Aurel', '3 Rockefeller Pass', '+351 (635) 561-6192'),('Tench', 'Atlanta', '7 Sachs Hill', '+63 (644) 370-6876'),('Wordley', 'Erwin', '73897 Talmadge Crossing', '+60 (538) 815-8161'),('Vassie', 'Yvonne', '34 Coolidge Drive', '+30 (619) 402-0367'),('Cork', 'Laural', '56 Acker Pass', '+358 (508) 204-8418'),('Shiel', 'Gene', '310 Washington Junction', '+33 (163) 455-2486'),('Pareman', 'Jammie', '306 Sommers Way', '+55 (277) 163-1463'),('Braddon', 'Melisenda', '24 Leroy Street', '+63 (779) 340-5235'),('Grisedale', 'Rainer', '68851 Fulton Parkway', '+63 (419) 145-8493'),('Rapkins', 'Jobye', '559 Atwood Terrace', '+86 (859) 286-6773'),('Boarer', 'Delly', '71964 Surrey Crossing', '+86 (388) 344-8177'),('Chapelhow', 'Keeley', '76750 Bashford Court', '+48 (456) 983-2349'),('Dmiterko', 'Lucinda', '365 Barnett Plaza', '+86 (326) 423-8860'),('Addicott', 'Bill', '40 Anthes Alley', '+53 (929) 402-2615'),('Rapaport', 'Dru', '5 Truax Terrace', '+30 (882) 562-3320'),('Vigneron', 'Natale', '17165 Basil Alley', '+54 (970) 956-2037'),('Rennicks', 'Seward', '797 Havey Street', '+234 (854) 102-7767'),('Beecraft', 'Yuma', '7340 Fulton Point', '+48 (710) 134-7482'),('Tille', 'Marshall', '14 Portage Pass', '+225 (672) 833-3479'),('Garrettson', 'Danya', '6 Dahle Place', '+596 (983) 496-5251'),('Fellos', 'Gillan', '60323 Hanson Terrace', '+7 (119) 383-7894'),('Troman', 'Vaughn', '17713 Fieldstone Point', '+386 (378) 988-7070'),('Degoe', 'Melony', '3231 Monterey Avenue', '+63 (353) 212-2846'),('Tremeer', 'Tandy', '8631 Corben Way', '+1 (202) 378-6745'),('Heppner', 'Stephi', '494 Westerfield Avenue', '+84 (480) 557-8742'),('Gasken', 'Fedora', '29570 Del Sol Circle', '+257 (915) 187-1325'),('O''Curran', 'Aubrey', '90974 Scoville Court', '+1 (480) 641-5588'),('McCane', 'Nolana', '74 Westport Alley', '+63 (781) 866-9446'),('Kingsbury', 'Wilbur', '5757 Service Court', '+55 (982) 244-4298'),('Infantino', 'Cherida', '7 Fallview Circle', '+33 (361) 919-2338'),('Sergent', 'Barton', '2 Loomis Court', '+62 (851) 104-6169'),('Sher', 'Genna', '77168 Reindahl Lane', '+86 (634) 480-6612'),('Robbins', 'Jabez', '08 Fieldstone Center', '+381 (747) 222-6570'),('Bonafacino', 'Chantal', '5620 Ramsey Lane', '+385 (182) 546-2710'),('Ions', 'Tanhya', '737 Elgar Lane', '+82 (959) 323-5318'),('Dancer', 'Melantha', '06690 Mayer Road', '+7 (132) 239-5682'),('Brinkley', 'Manon', '60669 Lighthouse Bay Place', '+86 (931) 240-4103'),('Duns', 'Georgie', '5252 Pleasure Trail', '+62 (561) 399-2981'),('McCrum', 'Randell', '993 Paget Crossing', '+7 (537) 212-0885'),('Munnion', 'Gregory', '015 Hintze Place', '+55 (191) 669-6322'),('Ascroft', 'Elianora', '566 Fulton Point', '+63 (667) 752-5978'),('Hastin', 'Lynnea', '67132 Algoma Trail', '+251 (927) 226-0988'),('Taynton', 'Tuckie', '96367 Manufacturers Trail', '+52 (753) 305-2085'),('Duckering', 'Leonardo', '9 Leroy Lane', '+86 (776) 898-1193'),('Heater', 'Amelia', '0 Westport Trail', '+420 (280) 649-3843'),('Lippatt', 'Lavinia', '59 Portage Street', '+591 (440) 401-6474'),('MacCambridge', 'Elliott', '8559 Rieder Junction', '+86 (574) 184-7558'),('Eliaz', 'Glynis', '92 Hoard Court', '+33 (696) 611-6582'),('Willett', 'Ferris', '7 Weeping Birch Trail', '+30 (209) 231-7905'),('des Remedios', 'Shalom', '1771 Straubel Trail', '+267 (839) 735-4786'),('McNeely', 'Kienan', '09 Caliangt Place', '+48 (292) 389-1930'),('Boteman', 'Andree', '306 Birchwood Plaza', '+86 (866) 370-9504'),('Wyss', 'Drucill', '01568 Clemons Pass', '+1 (742) 906-7385'),('Jaquemar', 'Fredrika', '85865 Lakewood Gardens Junction', '+86 (757) 244-3361'),('Burghall', 'Randolf', '001 Green Ridge Park', '+216 (476) 335-3707'),('Esselen', 'Joell', '28 Forest Drive', '+62 (672) 498-3980'),('Durward', 'Queenie', '82 Fisk Junction', '+598 (585) 779-7596'),('Binny', 'Inness', '3 Marquette Drive', '+7 (566) 664-8145'),('Cossell', 'Peirce', '93 South Place', '+62 (834) 933-6411'),('Binyon', 'Rycca', '9752 Moland Place', '+86 (207) 679-1339'),('Thewles', 'Dominic', '96606 Merry Road', '+86 (857) 555-5739'),('Pert', 'Jermaine', '9 1st Point', '+351 (581) 425-9331'),('Botwright', 'Abbi', '40 Petterle Place', '+86 (251) 287-7359'),('Hegarty', 'Virginia', '7813 Oak Pass', '+49 (443) 996-7923'),('Bartosik', 'Emelita', '805 Springview Crossing', '+86 (947) 605-6201'),('Vouls', 'Adrian', '37240 Ridgeway Circle', '+81 (984) 649-0940'),('Thornebarrow', 'Rebeca', '5963 Parkside Circle', '+84 (507) 670-9943'),('Baudains', 'Eduard', '5 Michigan Crossing', '+95 (526) 712-7797'),('Duplock', 'Marlie', '37451 Anthes Road', '+86 (327) 380-4101'),('Usmar', 'Weber', '7 Moulton Drive', '+351 (210) 188-4179'),('Corah', 'Mathias', '4 Debs Parkway', '+1 (717) 494-3303'),('Blackhurst', 'Bud', '48 Blackbird Alley', '+63 (588) 871-6449'),('Gatus', 'Gerhardine', '21910 Continental Pass', '+994 (667) 172-1527'),('Gawne', 'Karlens', '64 Coolidge Trail', '+46 (594) 440-6266'),('Minocchi', 'Margaux', '4 Dorton Plaza', '+33 (150) 598-3833'),('Bickmore', 'Tess', '66150 Daystar Way', '+7 (796) 126-5004'),('Enden', 'Batholomew', '00743 Pine View Hill', '+86 (413) 191-6569'),('MacCauley', 'Shirl', '9 Beilfuss Point', '+54 (785) 497-9686'),('Elverstone', 'Wanids', '58 Fordem Parkway', '+48 (972) 445-9741'),('Praundlin', 'Vitia', '8607 Bellgrove Crossing', '+55 (352) 828-6061'),('Shernock', 'Carlina', '39 Grim Drive', '+62 (601) 220-4377'),('Rushby', 'Kaylil', '17 Buena Vista Court', '+502 (546) 340-5005'),('Pawden', 'Terry', '9993 Paget Park', '+358 (282) 572-2280'),('Dykas', 'Ricky', '415 Bellgrove Hill', '+86 (794) 264-5022'),('Cote', 'Ailis', '19934 Russell Pass', '+1 (714) 133-1739'),('Jerschke', 'Barbee', '5 Dexter Avenue', '+86 (187) 699-0733'),('Hubery', 'Vincenty', '5472 Mccormick Pass', '+86 (289) 531-6978'),('Brunelli', 'Ev', '88 American Ash Pass', '+504 (145) 791-4691'),('Pendred', 'Iain', '3 Burrows Point', '+1 (699) 951-9314'),('Leyland', 'Jacquette', '4 Mayer Plaza', '+353 (288) 718-5245'),('Gregorio', 'Jada', '8 2nd Plaza', '+31 (948) 897-3068'),('Mangenet', 'Flem', '1 Clyde Gallagher Alley', '+86 (545) 861-1574'),('Kubczak', 'Cherilynn', '3775 Pennsylvania Drive', '+86 (323) 224-4732'),('Trayling', 'Base', '70372 Erie Alley', '+86 (195) 560-1028'),('Sibylla', 'Lizzy', '61 Cascade Street', '+62 (426) 867-4181'),('Enders', 'Lula', '26 Meadow Ridge Alley', '+86 (972) 904-5113'),('Peter', 'Tom', '557 Laurel Court', '+86 (274) 961-8273'),('Straffon', 'Melony', '8347 Granby Way', '+86 (141) 985-3446'),('Hansom', 'Kate', '225 Lunder Pass', '+86 (884) 117-6052'),('Hutcheon', 'Jameson', '58910 Aberg Avenue', '+7 (613) 302-7277'),('Newbegin', 'Wiley', '71 3rd Hill', '+86 (212) 607-4863'),('Wiltshier', 'Corny', '2 Bobwhite Junction', '+86 (122) 302-9540'),('Swettenham', 'Katerina', '5 Dunning Hill', '+62 (543) 942-1425'),('Bourrel', 'Ailene', '660 Fordem Point', '+52 (479) 215-9971'),('Borton', 'Hector', '792 Macpherson Park', '+62 (678) 527-3427'),('Brigginshaw', 'Neall', '67 Farmco Junction', '+373 (443) 731-7483'),('Curedell', 'Janaya', '78510 Kim Way', '+54 (916) 744-4768'),('Asty', 'Eadith', '45435 Forest Road', '+66 (223) 542-1297'),('Footitt', 'L,urette', '15 Oxford Alley', '+34 (115) 974-6946'),('Morman', 'Randee', '556 Rockefeller Court', '+994 (371) 798-8920'),('Bending', 'Betty', '246 Mccormick Road', '+33 (564) 238-6169'),('Phizacklea', 'Rosalynd', '43272 Kingsford Court', '+46 (343) 168-7266'),('Biset', 'Gypsy', '32696 Morrow Circle', '+66 (638) 200-5810'),('Robelow', 'Jocko', '39 Coolidge Plaza', '+86 (865) 172-0129'),('Semerad', 'Rudolf', '68 Buena Vista Point', '+55 (743) 741-9807'),('McKerrow', 'Larissa', '5475 Anhalt Way', '+1 (637) 847-6092'),('Marron', 'Glory', '0 Victoria Drive', '+252 (301) 753-1563'),('Pietruszka', 'Barrie', '28 Messerschmidt Trail', '+81 (786) 141-0904');";
						//cout << "insert into subscriber" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql64, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);


						const char* sql7 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (358, 10, 17, 10, 2016),(273, 2, 13, 8, 1992),(147, 8, 20, 12, 1995),(783, 4, 7, 6, 2013),(78, 3, 17, 7, 2002),(784, 9, 13, 2, 1999),(974, 5, 24, 4, 2009),(880, 10, 33, 1, 2019),(170, 7, 3, 2, 1996),(583, 7, 25, 8, 1998),(735, 1, 25, 2, 2010),(400, 5, 1, 3, 2008),(329, 8, 35, 4, 1991),(439, 8, 11, 11, 1994),(876, 2, 32, 1, 1993),(85, 6, 35, 1, 2010),(845, 8, 15, 12, 2019),(454, 9, 30, 10, 2006),(366, 8, 33, 11, 2002),(716, 9, 8, 2, 2006),(416, 5, 1, 7, 2004),(196, 4, 16, 7, 1994),(63, 1, 24, 5, 2018),(534, 1, 26, 7, 1997),(916, 2, 17, 7, 1993),(703, 6, 27, 3, 2016),(721, 6, 36, 12, 2011),(101, 8, 4, 5, 2007),(27, 4, 33, 3, 1998),(885, 8, 7, 8, 2019),(994, 1, 34, 10, 2000),(563, 1, 30, 1, 1994),(772, 6, 24, 3, 1991),(475, 6, 26, 1, 2005),(319, 9, 3, 8, 2008),(435, 3, 1, 10, 2001),(201, 5, 16, 5, 2016),(943, 10, 2, 2, 2003),(25, 3, 25, 6, 2014),(595, 4, 6, 9, 2005),(605, 2, 6, 2, 1992),(559, 6, 32, 5, 2015),(520, 7, 34, 5, 2010),(540, 3, 3, 5, 1994),(449, 5, 15, 2, 2012),(328, 10, 2, 5, 2010),(943, 3, 21, 10, 2020),(483, 4, 11, 6, 2006),(508, 1, 19, 11, 2018),(253, 10, 21, 7, 2016),(873, 4, 18, 8, 2013),(177, 2, 25, 5, 1993),(581, 1, 27, 2, 2013),(747, 6, 16, 8, 2015),(852, 10, 7, 1, 2016),(83, 8, 7, 8, 2020),(908, 9, 30, 4, 2011),(551, 10, 15, 6, 2004),(217, 10, 36, 2, 2010),(248, 6, 22, 11, 2000),(927, 1, 2, 5, 2010),(339, 1, 19, 12, 2008),(206, 2, 27, 9, 2002),(767, 10, 21, 10, 2001),(408, 10, 15, 8, 2011),(535, 1, 22, 1, 2016),(939, 2, 31, 7, 2019),(2, 4, 16, 1, 1991),(993, 8, 11, 10, 2008),(370, 5, 34, 3, 2011),(101, 7, 16, 8, 2007),(875, 9, 34, 4, 1995),(389, 6, 14, 6, 2002),(260, 9, 30, 2, 2008),(268, 1, 30, 9, 2007),(8, 9, 35, 4, 1997),(846, 2, 7, 9, 2016),(430, 4, 13, 7, 2016),(727, 8, 6, 9, 2005),(311, 4, 20, 9, 2001),(560, 1, 20, 6, 2002),(149, 1, 5, 1, 2014),(686, 10, 3, 10, 2010),(424, 7, 13, 2, 2019),(414, 5, 1, 7, 1992),(132, 8, 18, 2, 2002),(249, 3, 4, 4, 2013),(567, 9, 4, 8, 1996),(256, 10, 15, 8, 1992),(656, 5, 13, 1, 2013),(199, 4, 26, 4, 2001),(975, 2, 19, 12, 2019),(313, 10, 22, 3, 2000),(164, 6, 30, 3, 2013),(23, 1, 13, 3, 2001),(491, 5, 36, 8, 2006),(723, 8, 12, 5, 2006),(148, 9, 8, 12, 2017),(866, 2, 14, 10, 1994),(100, 8, 24, 5, 1994),(362, 2, 12, 9, 2012),(14, 6, 33, 10, 2000),(452, 9, 26, 6, 2007),(210, 4, 6, 2, 2018),(703, 4, 6, 4, 1998),(677, 3, 31, 6, 2000),(44, 1, 10, 9, 1996),(410, 1, 32, 2, 2004),(985, 1, 18, 1, 1999),(366, 9, 19, 1, 2007),(931, 3, 20, 9, 2013),(277, 7, 22, 8, 2002),(722, 7, 10, 10, 2002),(672, 8, 31, 2, 2002),(358, 7, 16, 9, 1991),(262, 4, 22, 2, 2002),(742, 1, 34, 7, 2000),(781, 4, 2, 9, 2001),(798, 5, 34, 3, 2004),(210, 1, 15, 8, 1997),(646, 9, 31, 5, 2018),(964, 9, 11, 9, 2016),(799, 5, 5, 2, 1999),(881, 3, 20, 10, 2013),(389, 7, 17, 9, 1995),(958, 1, 30, 11, 2003),(969, 4, 24, 6, 2017),(83, 9, 29, 3, 2008),(799, 9, 11, 1, 2005),(458, 3, 11, 4, 2018),(136, 1, 8, 5, 2006),(95, 1, 21, 8, 2017),(617, 8, 29, 5, 2017),(991, 2, 22, 4, 1992),(367, 3, 7, 12, 2014),(495, 3, 20, 3, 1992),(576, 9, 27, 4, 2004),(682, 6, 3, 7, 1996),(472, 7, 1, 4, 2010),(609, 4, 18, 6, 2003),(683, 1, 31, 11, 2011),(269, 1, 36, 3, 2010),(239, 9, 34, 6, 1993),(797, 6, 12, 8, 2012),(155, 10, 31, 7, 2017),(94, 10, 36, 4, 1997),(934, 5, 16, 6, 1996),(195, 6, 17, 3, 2007),(980, 10, 9, 10, 2012),(647, 8, 12, 12, 1992),(148, 10, 19, 2, 2010),(341, 1, 23, 9, 2007),(132, 10, 21, 11, 1991),(745, 9, 2, 7, 1991),(629, 1, 23, 4, 1994),(813, 10, 23, 9, 1993),(427, 9, 23, 2, 1991),(64, 5, 26, 7, 1999),(288, 4, 7, 2, 1993),(818, 2, 2, 4, 2005),(825, 7, 22, 4, 2009),(911, 10, 33, 11, 2019),(917, 7, 33, 7, 1994),(880, 10, 20, 7, 2005),(522, 7, 14, 8, 2013),(196, 1, 36, 11, 2020),(977, 9, 14, 12, 1996),(971, 9, 24, 5, 1994),(670, 10, 26, 4, 1994),(972, 6, 8, 9, 2013),(966, 8, 25, 10, 2010),(787, 6, 23, 7, 1992),(660, 4, 30, 1, 2001),(275, 9, 32, 2, 1993),(11, 2, 10, 6, 2002),(105, 5, 19, 1, 2011),(913, 5, 1, 8, 2007),(877, 1, 26, 2, 2006),(695, 7, 17, 1, 2005),(572, 4, 18, 2, 2019),(447, 3, 9, 9, 2013),(646, 8, 32, 10, 1993),(584, 6, 9, 9, 2009),(86, 9, 27, 1, 1994),(257, 5, 18, 8, 1994),(528, 5, 18, 12, 2009),(8, 9, 23, 2, 1996),(352, 3, 14, 1, 2003),(191, 1, 23, 11, 2004),(693, 3, 23, 10, 2017),(594, 9, 6, 8, 1998),(10, 6, 20, 1, 2000),(666, 10, 6, 11, 2012),(614, 10, 7, 11, 2015),(585, 6, 26, 2, 2000),(256, 9, 23, 3, 2006),(191, 3, 13, 1, 1992),(143, 10, 7, 8, 1999),(362, 4, 10, 12, 2003),(789, 8, 4, 11, 1995);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql7, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql71 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (476, 5, 28, 3, 2017),(418, 2, 35, 4, 2001),(939, 5, 23, 10, 1993),(63, 6, 20, 3, 1993),(704, 6, 24, 2, 2010),(733, 10, 24, 11, 1991),(56, 6, 27, 7, 2017),(601, 6, 20, 12, 2018),(952, 5, 23, 6, 1996),(825, 3, 35, 4, 1999),(937, 6, 1, 7, 2004),(601, 6, 19, 12, 2010),(926, 9, 5, 10, 2009),(339, 4, 29, 1, 1997),(818, 7, 25, 5, 1993),(328, 9, 8, 4, 2008),(864, 1, 12, 3, 2012),(46, 2, 20, 10, 2013),(959, 9, 11, 11, 2002),(947, 9, 12, 1, 2017),(778, 8, 13, 2, 1997),(908, 8, 23, 8, 1999),(960, 5, 34, 8, 1993),(133, 9, 15, 5, 2010),(256, 7, 28, 11, 1997),(64, 2, 2, 11, 2008),(820, 4, 33, 4, 1998),(43, 3, 34, 7, 2018),(756, 6, 19, 9, 2017),(891, 9, 19, 8, 2016),(225, 5, 3, 7, 2006),(738, 7, 6, 3, 1999),(296, 6, 28, 9, 2011),(493, 8, 22, 11, 2010),(489, 9, 7, 2, 2005),(434, 6, 7, 9, 1994),(261, 1, 15, 2, 2012),(827, 8, 4, 7, 2000),(131, 7, 14, 9, 2016),(947, 9, 26, 9, 2018),(488, 10, 1, 10, 2005),(670, 3, 3, 1, 2001),(861, 9, 5, 6, 1994),(346, 10, 26, 10, 1999),(236, 2, 5, 9, 2013),(88, 9, 24, 5, 2002),(928, 9, 21, 8, 2008),(509, 4, 1, 11, 2017),(835, 8, 26, 3, 1998),(911, 10, 18, 2, 2000),(348, 1, 33, 3, 2018),(652, 7, 26, 8, 1992),(489, 4, 16, 6, 2004),(220, 3, 11, 7, 2013),(969, 1, 33, 12, 2018),(822, 7, 8, 11, 1999),(895, 9, 28, 4, 1995),(204, 5, 19, 3, 2020),(366, 3, 36, 3, 2008),(49, 4, 14, 4, 1992),(20, 3, 6, 11, 2012),(280, 6, 11, 9, 1997),(527, 6, 4, 2, 2017),(842, 8, 21, 11, 2014),(666, 4, 36, 11, 2016),(547, 1, 23, 8, 2017),(609, 5, 16, 5, 2003),(527, 8, 12, 12, 2014),(871, 4, 21, 1, 1995),(960, 4, 27, 2, 2006),(463, 6, 1, 5, 2007),(223, 2, 35, 7, 1992),(943, 3, 24, 2, 1991),(953, 7, 33, 12, 2004),(620, 9, 25, 9, 2019),(529, 9, 26, 2, 2000),(379, 8, 10, 11, 2014),(332, 9, 20, 6, 2008),(634, 2, 29, 7, 1999),(245, 7, 34, 4, 2003),(945, 2, 12, 4, 2018),(629, 6, 24, 5, 2015),(620, 7, 25, 5, 2017),(728, 9, 24, 5, 2004),(81, 8, 20, 10, 2000),(999, 7, 23, 5, 2003),(720, 3, 25, 2, 1998),(961, 9, 5, 11, 1998),(553, 6, 11, 12, 2011),(887, 10, 21, 2, 2004),(706, 10, 22, 3, 2014),(899, 3, 31, 12, 1999),(602, 6, 6, 6, 2009),(689, 10, 31, 12, 1993),(882, 10, 20, 11, 2013),(86, 2, 27, 7, 2016),(536, 8, 27, 8, 1994),(131, 7, 3, 1, 2001),(252, 3, 25, 6, 2018),(715, 5, 7, 4, 2008),(324, 2, 28, 9, 2020),(112, 7, 34, 4, 1992),(585, 10, 2, 8, 1992),(326, 8, 36, 4, 2017),(488, 3, 23, 12, 1999),(489, 4, 7, 2, 2009),(332, 5, 33, 2, 2006),(39, 7, 1, 10, 2001),(319, 2, 6, 8, 1996),(273, 4, 16, 3, 1999),(925, 2, 36, 4, 2016),(642, 9, 6, 12, 2020),(810, 8, 17, 9, 2014),(332, 7, 11, 12, 2000),(439, 2, 13, 8, 1995),(716, 8, 8, 10, 1996),(174, 2, 3, 3, 2017),(700, 3, 17, 5, 2010),(808, 8, 15, 1, 2017),(361, 9, 28, 4, 1993),(492, 8, 9, 6, 1995),(929, 5, 3, 1, 2006),(108, 6, 10, 6, 1996),(679, 3, 2, 11, 2008),(215, 1, 31, 4, 2019),(985, 3, 11, 9, 2004),(218, 7, 24, 11, 2020),(176, 10, 29, 8, 1998),(365, 7, 21, 1, 2005),(142, 2, 28, 7, 2002),(854, 4, 3, 2, 1999),(265, 1, 21, 10, 1999),(56, 3, 30, 11, 2006),(853, 7, 10, 10, 2003),(196, 3, 31, 1, 2008),(137, 2, 28, 11, 2013),(2, 5, 31, 1, 1999),(395, 2, 6, 9, 1997),(85, 9, 24, 9, 1996),(32, 8, 23, 4, 2000),(830, 3, 21, 6, 2004),(838, 3, 10, 11, 1991),(192, 5, 24, 12, 2003),(128, 1, 10, 11, 2007),(433, 4, 10, 7, 1991),(543, 3, 21, 1, 2011),(266, 4, 4, 4, 1997),(113, 5, 21, 8, 2019),(915, 1, 22, 2, 1996),(566, 1, 14, 9, 2001),(91, 9, 31, 4, 1999),(564, 2, 30, 9, 1991),(501, 6, 21, 12, 2019),(367, 5, 19, 1, 1998),(600, 4, 35, 11, 2013),(376, 10, 25, 5, 2018),(700, 1, 31, 5, 2020),(315, 3, 7, 1, 2006),(836, 3, 4, 1, 1995),(652, 10, 9, 12, 1995),(31, 10, 22, 1, 2002),(225, 3, 7, 1, 2014),(390, 3, 2, 9, 2015),(965, 10, 25, 5, 2007),(534, 4, 17, 1, 2005),(972, 4, 23, 10, 2000),(908, 2, 6, 6, 2001),(803, 6, 24, 4, 2007),(154, 4, 15, 12, 2017),(20, 1, 21, 5, 1993),(908, 2, 32, 5, 2019),(852, 7, 5, 1, 2017),(195, 4, 5, 12, 2000),(544, 10, 23, 6, 1999),(343, 8, 19, 3, 2018),(984, 2, 27, 10, 2005),(234, 10, 28, 8, 1992),(879, 5, 11, 7, 2017),(132, 7, 27, 11, 1993),(394, 5, 32, 2, 1998),(363, 10, 21, 1, 2009),(146, 3, 15, 11, 1996),(194, 5, 2, 3, 2020),(426, 7, 34, 11, 2001),(527, 5, 4, 2, 2002),(108, 6, 6, 11, 2012),(796, 4, 13, 3, 2020),(851, 6, 32, 3, 2016),(145, 9, 31, 5, 2018),(759, 10, 3, 8, 2001),(681, 4, 34, 12, 2002),(665, 10, 19, 1, 2000),(770, 4, 6, 3, 2005),(100, 6, 6, 5, 1991),(592, 8, 15, 7, 2005),(638, 7, 25, 12, 2004),(40, 2, 18, 1, 2002),(280, 9, 8, 11, 2017),(247, 1, 1, 11, 1998),(643, 10, 2, 10, 1996);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql71, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql72 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (386, 9, 3, 1, 2020),(879, 2, 17, 7, 2011),(914, 10, 26, 6, 1998),(99, 5, 11, 6, 2014),(569, 10, 22, 2, 2007),(546, 9, 27, 9, 2001),(55, 1, 31, 1, 2016),(902, 10, 23, 3, 1991),(438, 4, 2, 7, 2009),(430, 8, 21, 4, 2010),(789, 8, 24, 9, 2001),(871, 2, 34, 12, 2001),(523, 9, 26, 8, 1997),(729, 6, 1, 11, 2000),(261, 4, 24, 8, 2014),(602, 5, 30, 12, 2018),(393, 10, 2, 5, 2010),(484, 7, 4, 12, 1997),(776, 9, 21, 5, 2012),(636, 7, 20, 1, 2005),(311, 6, 36, 12, 2012),(496, 6, 36, 7, 2001),(691, 4, 14, 5, 1994),(703, 7, 4, 9, 1992),(806, 6, 4, 8, 1991),(468, 1, 21, 8, 2013),(844, 7, 4, 3, 2012),(109, 6, 9, 11, 2009),(952, 2, 21, 2, 2002),(800, 9, 10, 6, 2006),(260, 1, 19, 11, 1996),(7, 5, 19, 3, 1996),(510, 7, 14, 9, 1994),(462, 8, 2, 4, 1994),(525, 8, 31, 11, 2012),(351, 10, 18, 2, 2019),(644, 1, 8, 9, 2000),(897, 4, 14, 2, 2019),(789, 6, 3, 11, 2013),(748, 3, 17, 12, 2000),(592, 8, 19, 12, 2016),(113, 3, 6, 5, 2015),(778, 1, 24, 7, 1991),(44, 5, 31, 3, 1994),(950, 1, 21, 4, 2007),(450, 2, 33, 5, 1996),(279, 4, 7, 4, 2010),(162, 2, 22, 3, 2014),(245, 9, 30, 2, 2011),(944, 2, 10, 9, 2004),(948, 3, 18, 11, 1992),(829, 8, 10, 1, 2005),(554, 10, 14, 2, 1996),(674, 10, 1, 9, 2014),(854, 6, 24, 2, 1992),(955, 4, 35, 7, 2009),(221, 5, 17, 3, 2015),(429, 7, 17, 5, 2015),(807, 1, 36, 11, 2001),(220, 4, 15, 9, 2010),(40, 5, 4, 1, 2016),(461, 4, 11, 7, 1997),(31, 10, 27, 5, 2019),(289, 4, 5, 6, 2013),(715, 10, 14, 12, 2013),(73, 6, 33, 10, 2006),(817, 1, 19, 8, 1997),(155, 2, 1, 1, 1994),(727, 6, 29, 3, 2014),(570, 4, 22, 8, 2004),(331, 8, 20, 12, 2014),(554, 5, 6, 7, 1993),(152, 1, 5, 2, 2020),(849, 2, 17, 11, 1992),(925, 5, 20, 6, 2000),(481, 1, 3, 10, 2011),(283, 1, 19, 6, 1991),(669, 3, 7, 9, 1999),(208, 7, 35, 6, 2017),(460, 2, 14, 8, 2002),(426, 8, 30, 8, 2014),(593, 6, 15, 12, 2005),(126, 2, 31, 7, 1992),(463, 10, 28, 2, 2013),(327, 2, 31, 5, 2004),(788, 2, 32, 6, 1994),(942, 5, 2, 11, 2015),(38, 10, 14, 10, 2018),(861, 10, 20, 7, 2001),(857, 6, 31, 10, 1991),(743, 5, 28, 1, 2004),(16, 2, 3, 7, 2005),(893, 1, 7, 2, 2020),(999, 7, 31, 10, 1995),(805, 7, 21, 12, 2007),(23, 10, 19, 7, 2009),(598, 8, 28, 9, 2015),(634, 3, 9, 4, 2016),(934, 5, 13, 12, 2005),(640, 8, 31, 12, 1993),(832, 2, 3, 2, 2009),(135, 1, 29, 11, 1994),(927, 8, 26, 12, 2012),(567, 1, 7, 4, 2012),(963, 7, 22, 9, 2004),(729, 10, 16, 6, 2006),(846, 1, 9, 2, 2020),(300, 7, 31, 6, 2007),(937, 10, 24, 9, 2013),(518, 6, 27, 1, 2011),(396, 4, 18, 12, 2011),(655, 7, 12, 1, 2007),(181, 3, 31, 10, 2005),(989, 7, 21, 1, 2005),(693, 9, 15, 3, 2017),(652, 9, 20, 1, 1995),(39, 1, 33, 12, 1996),(784, 8, 28, 7, 2020),(598, 1, 23, 4, 2011),(570, 5, 34, 7, 1991),(182, 3, 23, 11, 2011),(338, 3, 17, 10, 2008),(753, 1, 14, 5, 2000),(931, 4, 22, 5, 2017),(172, 4, 16, 5, 1992),(16, 6, 6, 7, 2012),(193, 2, 28, 2, 2020),(759, 8, 16, 7, 2018),(412, 2, 10, 6, 1994),(447, 5, 22, 1, 2013),(291, 5, 1, 12, 2020),(170, 4, 36, 9, 1993),(294, 5, 21, 7, 2003),(211, 3, 14, 6, 2013),(468, 5, 8, 6, 1992),(407, 8, 20, 8, 1993),(991, 3, 20, 1, 1994),(20, 8, 16, 3, 2017),(341, 3, 33, 9, 1997),(411, 10, 35, 9, 1991),(302, 6, 29, 1, 1998),(910, 6, 14, 12, 1993),(709, 5, 30, 9, 2006),(486, 10, 23, 7, 2007),(21, 7, 35, 12, 2004),(885, 1, 31, 7, 1996),(943, 2, 13, 12, 1995),(101, 8, 9, 4, 2017),(643, 3, 34, 4, 2007),(889, 8, 22, 1, 1991),(545, 9, 2, 4, 2005),(380, 8, 25, 4, 1996),(544, 5, 10, 3, 2014),(834, 1, 7, 2, 2000),(873, 2, 4, 9, 1995),(716, 4, 16, 1, 2018),(779, 9, 16, 10, 2003),(443, 7, 10, 6, 1999),(310, 7, 24, 4, 2014),(987, 2, 27, 2, 2006),(473, 4, 25, 11, 2005),(441, 2, 26, 11, 2003),(679, 3, 31, 12, 1993),(694, 1, 4, 4, 2016),(679, 4, 1, 1, 2020),(666, 3, 4, 3, 2009),(830, 8, 14, 6, 2015),(349, 3, 3, 4, 2007),(994, 3, 36, 10, 1998),(654, 5, 22, 7, 1994),(497, 2, 9, 5, 2001),(487, 2, 11, 9, 2013),(673, 5, 34, 5, 2010),(903, 4, 3, 4, 2017),(782, 2, 19, 10, 2005),(64, 4, 26, 3, 2013),(49, 1, 11, 12, 2007),(467, 4, 7, 2, 2004),(871, 7, 30, 9, 2011),(239, 8, 31, 3, 2001),(639, 2, 1, 11, 1995),(128, 7, 8, 7, 2006),(491, 2, 25, 1, 1997),(130, 4, 18, 6, 2016),(110, 2, 1, 11, 2002),(667, 1, 16, 4, 2003),(995, 4, 21, 12, 1994),(826, 5, 26, 12, 1991),(855, 9, 1, 7, 2011),(683, 10, 7, 6, 1996),(323, 6, 19, 11, 1994),(33, 2, 4, 6, 2015),(378, 2, 26, 6, 2011),(648, 8, 34, 8, 2004),(360, 3, 23, 7, 2014),(321, 8, 36, 10, 2014),(823, 8, 2, 8, 2013),(514, 4, 22, 5, 1992),(691, 2, 6, 12, 2016),(866, 7, 18, 4, 2009);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql72, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql73 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (205, 5, 4, 6, 2005),(27, 4, 13, 8, 2003),(468, 3, 29, 8, 2000),(862, 7, 35, 1, 1993),(424, 5, 26, 8, 1993),(814, 8, 2, 11, 2006),(841, 4, 2, 9, 1997),(760, 7, 11, 4, 2014),(484, 5, 36, 8, 2020),(303, 9, 9, 12, 2018),(371, 7, 18, 8, 2004),(513, 8, 24, 11, 1998),(620, 9, 17, 8, 2018),(270, 5, 3, 10, 2005),(29, 7, 25, 7, 2004),(195, 1, 5, 5, 2003),(726, 1, 30, 4, 2017),(234, 6, 17, 3, 2016),(916, 5, 12, 1, 2018),(18, 1, 18, 4, 2005),(210, 3, 29, 12, 2004),(967, 10, 10, 8, 2019),(57, 3, 28, 8, 1993),(72, 3, 24, 1, 2018),(678, 10, 7, 11, 2018),(997, 5, 19, 7, 2006),(272, 3, 26, 11, 2017),(757, 4, 13, 6, 2013),(919, 3, 10, 4, 1998),(262, 9, 4, 10, 2001),(651, 3, 12, 9, 2011),(701, 6, 9, 10, 2012),(499, 10, 21, 2, 2018),(659, 10, 22, 8, 2005),(201, 4, 20, 5, 2014),(204, 3, 16, 10, 2009),(770, 9, 21, 9, 2011),(144, 10, 23, 11, 2017),(43, 7, 11, 6, 2010),(177, 5, 11, 10, 2020),(541, 6, 8, 12, 1994),(944, 2, 4, 6, 2000),(684, 2, 5, 3, 1991),(706, 9, 22, 10, 2003),(8, 1, 15, 6, 1993),(62, 10, 24, 5, 2019),(972, 1, 10, 8, 2013),(7, 4, 20, 12, 2011),(371, 1, 30, 12, 1994),(560, 4, 17, 10, 2016),(981, 1, 32, 7, 2010),(420, 9, 17, 10, 1999),(112, 5, 28, 7, 1991),(218, 3, 13, 3, 2006),(50, 5, 6, 11, 2010),(51, 9, 23, 9, 2005),(594, 2, 30, 6, 2016),(305, 9, 31, 8, 2013),(658, 2, 22, 2, 2019),(610, 10, 30, 5, 1997),(845, 5, 30, 3, 2010),(632, 7, 2, 3, 2019),(650, 6, 27, 12, 2012),(155, 6, 5, 10, 2008),(388, 7, 30, 10, 1999),(756, 5, 26, 12, 2003),(995, 8, 22, 11, 2019),(94, 6, 15, 6, 1996),(383, 6, 25, 2, 1999),(242, 10, 4, 9, 2015),(653, 1, 11, 6, 1992),(573, 7, 16, 2, 1999),(447, 5, 31, 6, 2015),(343, 9, 14, 11, 2008),(141, 10, 13, 7, 1991),(7, 5, 20, 4, 1993),(989, 3, 36, 12, 1998),(943, 6, 4, 11, 2015),(666, 4, 24, 2, 2014),(179, 2, 34, 12, 1997),(338, 4, 26, 2, 1996),(524, 1, 2, 4, 1994),(734, 3, 16, 10, 1992),(268, 7, 17, 2, 2003),(242, 9, 22, 9, 1991),(558, 1, 2, 1, 2000),(773, 9, 27, 9, 1999),(169, 3, 25, 10, 1998),(581, 10, 28, 11, 2012),(936, 1, 26, 5, 2020),(390, 2, 32, 7, 1992),(246, 10, 34, 11, 1997),(601, 10, 13, 12, 2018),(245, 3, 21, 11, 2017),(462, 5, 5, 9, 2006),(16, 6, 6, 10, 2018),(695, 5, 2, 12, 2014),(105, 3, 5, 7, 1996),(102, 6, 8, 6, 2018),(901, 7, 25, 6, 2002),(978, 2, 15, 7, 1991),(35, 10, 1, 12, 2002),(100, 8, 36, 7, 1991),(860, 7, 31, 8, 2017),(808, 10, 27, 3, 1999),(268, 3, 13, 8, 2001),(438, 9, 1, 10, 2013),(530, 3, 29, 2, 2014),(623, 8, 31, 12, 2001),(491, 4, 3, 7, 1992),(255, 10, 13, 10, 2005),(135, 9, 16, 3, 2012),(403, 6, 1, 9, 2016),(694, 8, 35, 10, 2010),(998, 5, 18, 3, 2001),(783, 1, 12, 6, 2011),(365, 7, 21, 7, 2008),(419, 1, 10, 1, 2002),(212, 8, 33, 7, 2002),(671, 5, 21, 5, 2013),(724, 6, 13, 12, 1999),(291, 10, 26, 5, 1999),(330, 2, 32, 8, 1995),(283, 1, 15, 10, 2018),(150, 1, 7, 5, 2013),(687, 9, 21, 7, 2012),(987, 9, 10, 12, 1996),(362, 10, 18, 10, 2001),(936, 4, 36, 3, 2009),(74, 4, 28, 11, 2001),(772, 5, 1, 8, 2013),(964, 9, 5, 5, 2010),(805, 8, 18, 12, 1997),(349, 7, 33, 8, 2006),(720, 1, 17, 10, 1992),(616, 4, 1, 3, 2005),(248, 3, 5, 3, 2012),(228, 10, 21, 1, 2008),(643, 10, 19, 3, 2018),(726, 10, 2, 9, 1996),(855, 4, 19, 9, 1993),(149, 6, 6, 8, 2013),(429, 7, 24, 9, 1998),(508, 9, 17, 4, 2019),(281, 9, 12, 4, 2017),(463, 2, 7, 4, 2014),(193, 6, 15, 7, 1996),(336, 7, 11, 2, 1995),(656, 10, 3, 6, 2004),(991, 9, 16, 7, 1994),(313, 8, 30, 5, 2002),(423, 9, 36, 2, 2000),(262, 4, 4, 7, 2011),(203, 5, 22, 11, 1998),(776, 1, 16, 12, 2013),(418, 4, 2, 4, 2006),(512, 8, 5, 6, 2002),(284, 7, 16, 12, 1997),(734, 7, 32, 9, 2004),(569, 2, 1, 6, 2010),(532, 4, 4, 5, 2016),(651, 9, 3, 2, 1995),(801, 10, 11, 6, 1994),(341, 5, 11, 3, 2012),(953, 10, 23, 6, 1993),(867, 9, 1, 7, 2019),(235, 5, 28, 9, 1996),(425, 6, 18, 11, 1995),(929, 9, 28, 8, 1992),(708, 6, 27, 1, 2019),(63, 9, 30, 5, 2010),(244, 7, 17, 1, 1996),(49, 2, 33, 6, 1999),(431, 3, 4, 6, 2019),(970, 10, 19, 2, 2015),(424, 7, 8, 4, 2020),(832, 10, 22, 7, 2020),(663, 1, 20, 3, 2001),(421, 5, 26, 1, 2010),(58, 3, 5, 2, 2020),(29, 7, 33, 8, 2020),(680, 3, 25, 8, 2005),(810, 2, 21, 9, 1997),(913, 1, 13, 3, 2001),(693, 1, 9, 9, 2015),(584, 9, 2, 7, 1991),(765, 8, 28, 6, 2008),(179, 7, 19, 9, 2009),(606, 4, 6, 8, 2004),(268, 1, 2, 1, 2005),(527, 5, 3, 9, 1993),(202, 4, 2, 9, 2004),(440, 6, 10, 2, 2015),(840, 4, 4, 8, 1999),(551, 4, 32, 4, 2016),(123, 6, 9, 7, 2018),(832, 1, 11, 8, 1994),(934, 3, 15, 8, 2006),(293, 1, 8, 9, 2012),(738, 1, 21, 4, 2006);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql73, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql74 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (524, 10, 23, 4, 2016),(76, 2, 2, 4, 2012),(613, 1, 36, 7, 1999),(40, 5, 5, 9, 2004),(546, 2, 12, 3, 2009),(402, 4, 11, 2, 1995),(601, 4, 12, 6, 2005),(451, 3, 6, 5, 2017),(617, 5, 9, 1, 2016),(350, 8, 4, 9, 2005),(421, 7, 2, 6, 2004),(53, 6, 29, 11, 1994),(452, 5, 30, 5, 2005),(847, 6, 15, 12, 2007),(905, 4, 23, 4, 1996),(121, 1, 28, 12, 1991),(899, 6, 5, 4, 1993),(340, 7, 8, 11, 2014),(437, 8, 8, 3, 2009),(44, 1, 21, 1, 2008),(754, 8, 13, 3, 1991),(384, 9, 15, 6, 2000),(756, 10, 12, 2, 2007),(703, 1, 7, 10, 1999),(62, 5, 13, 10, 1999),(488, 7, 34, 1, 2002),(252, 4, 24, 6, 1996),(873, 3, 30, 2, 1995),(150, 4, 5, 11, 2009),(638, 4, 22, 1, 1994),(103, 5, 24, 11, 2012),(416, 1, 16, 6, 2018),(203, 9, 34, 7, 2011),(656, 2, 31, 7, 2001),(798, 1, 31, 6, 2020),(931, 6, 11, 1, 2011),(724, 7, 29, 1, 2017),(636, 2, 3, 2, 2016),(383, 2, 5, 3, 2016),(858, 5, 7, 9, 1998),(268, 5, 2, 7, 1999),(891, 5, 16, 2, 1996),(845, 1, 11, 5, 1991),(99, 3, 7, 1, 1994),(864, 7, 23, 12, 2009),(53, 4, 25, 5, 1996),(354, 7, 8, 12, 1999),(504, 7, 1, 8, 2011),(875, 3, 22, 5, 2016),(736, 10, 33, 5, 2005),(983, 4, 14, 12, 2017),(332, 3, 34, 6, 2009),(930, 8, 9, 5, 1999),(815, 1, 7, 6, 2014),(252, 3, 26, 12, 2020),(392, 5, 17, 9, 2010),(940, 4, 30, 4, 2002),(446, 7, 15, 3, 2007),(783, 6, 17, 10, 2000),(416, 6, 2, 9, 2017),(639, 2, 6, 4, 2009),(218, 5, 7, 9, 2009),(70, 9, 22, 2, 1995),(837, 7, 26, 11, 1995),(87, 5, 33, 3, 2020),(822, 6, 1, 12, 2009),(678, 3, 34, 6, 2010),(346, 2, 25, 12, 2012),(734, 9, 21, 11, 1995),(542, 2, 23, 10, 2016),(642, 2, 23, 2, 2015),(443, 5, 32, 5, 1997),(833, 2, 1, 8, 1999),(510, 10, 29, 5, 1996),(823, 1, 13, 6, 1995),(799, 4, 24, 12, 2001),(512, 9, 9, 11, 2009),(286, 7, 26, 11, 1997),(339, 9, 18, 2, 2001),(557, 7, 8, 11, 2000),(137, 3, 18, 2, 2010),(783, 10, 35, 11, 1995),(444, 5, 11, 11, 1996),(532, 8, 16, 7, 1996),(619, 1, 24, 11, 2000),(841, 6, 16, 3, 1995),(195, 2, 21, 3, 1996),(861, 4, 14, 5, 2015),(404, 4, 31, 3, 2005),(243, 8, 32, 7, 2012),(333, 6, 28, 11, 2020),(196, 3, 15, 8, 2011),(459, 10, 16, 5, 1991),(294, 6, 26, 2, 1994),(129, 5, 12, 8, 2020),(162, 5, 9, 12, 2007),(727, 7, 19, 3, 2014),(840, 9, 35, 4, 1997),(667, 4, 23, 12, 2020),(197, 1, 9, 7, 1998),(754, 3, 1, 11, 1996),(848, 9, 34, 12, 1996),(473, 10, 7, 4, 2015),(520, 4, 7, 4, 2006),(258, 5, 5, 9, 2017),(262, 2, 5, 12, 2008),(201, 7, 22, 10, 1992),(503, 8, 19, 6, 1996),(250, 8, 24, 5, 1994),(568, 10, 5, 3, 1994),(161, 5, 32, 8, 1999),(993, 2, 19, 12, 1999),(282, 8, 30, 7, 1994),(126, 9, 2, 10, 2015),(671, 2, 14, 5, 1998),(717, 1, 36, 2, 1992),(161, 4, 10, 8, 1994),(533, 10, 9, 3, 2001),(768, 3, 28, 12, 1997),(231, 2, 2, 9, 1997),(644, 10, 3, 3, 2009),(186, 3, 28, 7, 1994),(470, 5, 29, 4, 2012),(357, 6, 34, 10, 2018),(354, 1, 2, 3, 2005),(95, 6, 14, 12, 1998),(135, 8, 23, 9, 2005),(14, 6, 18, 1, 2000),(163, 7, 22, 8, 2007),(470, 2, 17, 7, 2003),(62, 10, 24, 5, 2005),(138, 5, 20, 7, 2004),(106, 9, 33, 7, 2005),(744, 9, 1, 12, 2009),(42, 9, 31, 5, 1993),(978, 5, 26, 12, 1991),(719, 1, 24, 6, 2020),(419, 4, 15, 12, 2006),(980, 5, 24, 1, 2001),(515, 7, 23, 9, 1995),(694, 4, 12, 2, 2003),(884, 4, 33, 11, 1997),(937, 8, 2, 12, 2020),(954, 10, 32, 3, 2019),(670, 1, 32, 4, 2006),(958, 3, 16, 2, 2015),(40, 9, 3, 6, 1995),(215, 3, 29, 3, 1992),(438, 2, 15, 9, 2017),(153, 9, 33, 7, 1994),(61, 1, 22, 11, 1994),(798, 2, 35, 6, 1993),(4, 10, 33, 11, 1994),(699, 1, 6, 11, 2012),(969, 6, 18, 9, 2001),(241, 9, 13, 5, 1991),(877, 6, 2, 11, 2008),(380, 1, 22, 2, 2010),(891, 2, 11, 6, 1999),(270, 1, 34, 2, 2013),(895, 2, 30, 11, 2017),(346, 10, 19, 9, 2001),(643, 6, 35, 12, 2002),(598, 9, 17, 2, 2011),(456, 6, 26, 5, 2016),(380, 4, 26, 3, 2005),(766, 8, 10, 7, 1994),(981, 10, 24, 2, 2009),(53, 9, 7, 6, 2000),(475, 10, 18, 11, 2010),(829, 5, 6, 9, 1997),(967, 5, 7, 8, 2005),(937, 7, 32, 8, 2011),(750, 3, 20, 3, 2005),(189, 5, 34, 8, 2007),(742, 10, 18, 3, 2002),(812, 8, 10, 10, 1994),(135, 2, 19, 4, 2012),(326, 6, 21, 1, 2004),(579, 4, 10, 3, 1997),(832, 6, 28, 10, 1999),(549, 1, 29, 2, 2011),(631, 10, 5, 7, 2013),(875, 4, 28, 12, 2011),(493, 5, 20, 2, 1998),(927, 10, 26, 7, 2010),(682, 5, 1, 8, 2009),(449, 6, 22, 12, 2007),(257, 8, 12, 9, 2013),(189, 8, 8, 11, 2007),(890, 1, 29, 3, 1997),(794, 3, 7, 5, 2009),(193, 10, 6, 4, 1999),(174, 6, 12, 1, 2011),(995, 3, 13, 3, 2004),(408, 8, 31, 11, 2008),(411, 2, 22, 8, 2004),(163, 5, 15, 9, 1993),(847, 1, 22, 12, 2015),(496, 10, 1, 11, 2011);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql74, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql75 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (952, 7, 4, 5, 1993),(325, 6, 33, 12, 2002),(898, 10, 26, 12, 1991),(368, 3, 7, 3, 2017),(98, 2, 29, 10, 2008),(629, 5, 2, 12, 2020),(188, 4, 33, 2, 2010),(800, 1, 27, 9, 2004),(684, 1, 19, 2, 2019),(812, 1, 12, 12, 2001),(119, 10, 9, 5, 1998),(293, 1, 8, 1, 1998),(599, 9, 30, 9, 2000),(581, 1, 23, 7, 2020),(2, 7, 17, 11, 1992),(411, 8, 27, 4, 1995),(892, 1, 29, 5, 1992),(233, 6, 33, 7, 2004),(658, 5, 35, 12, 2017),(921, 8, 31, 3, 2004),(940, 4, 7, 6, 2006),(257, 8, 21, 7, 2016),(385, 7, 6, 8, 2020),(141, 6, 3, 5, 1995),(384, 7, 18, 2, 2003),(66, 2, 16, 10, 1994),(873, 6, 30, 3, 2015),(660, 2, 29, 11, 1991),(876, 9, 13, 12, 2008),(304, 4, 25, 2, 2009),(615, 5, 30, 11, 1994),(181, 8, 36, 4, 1997),(776, 3, 12, 2, 2004),(707, 1, 24, 9, 2012),(457, 8, 36, 12, 2019),(808, 4, 22, 6, 2020),(15, 3, 1, 2, 1996),(135, 6, 11, 7, 2018),(823, 3, 3, 10, 2000),(669, 2, 13, 12, 1993),(701, 4, 20, 6, 2005),(297, 4, 6, 8, 2001),(848, 10, 35, 4, 1994),(971, 9, 34, 6, 2001),(854, 7, 32, 8, 2001),(723, 10, 26, 9, 2000),(394, 10, 36, 12, 2020),(316, 3, 14, 9, 1999),(618, 4, 11, 9, 2019),(245, 8, 35, 12, 2020),(42, 10, 27, 8, 2019),(631, 3, 11, 11, 2006),(806, 2, 1, 11, 2014),(800, 7, 35, 9, 2001),(871, 8, 16, 2, 2013),(858, 9, 11, 4, 2014),(780, 3, 18, 12, 1992),(576, 10, 9, 4, 2011),(403, 1, 8, 3, 2020),(26, 3, 17, 1, 2007),(955, 2, 23, 1, 2000),(421, 3, 2, 6, 1999),(979, 7, 21, 6, 1993),(647, 9, 18, 6, 1997),(488, 7, 28, 6, 2002),(175, 8, 30, 2, 1994),(954, 3, 36, 2, 1998),(638, 10, 24, 9, 1992),(286, 2, 30, 6, 1996),(851, 3, 9, 11, 2002),(99, 4, 1, 1, 2000),(60, 7, 15, 7, 2016),(580, 9, 35, 8, 1997),(255, 2, 11, 10, 1992),(813, 5, 8, 8, 2013),(32, 5, 25, 6, 2002),(23, 2, 24, 5, 2008),(901, 9, 24, 10, 2000),(84, 3, 29, 2, 2006),(953, 9, 7, 12, 1994),(256, 7, 7, 8, 2000),(703, 5, 8, 12, 2000),(838, 2, 12, 1, 2000),(523, 4, 12, 11, 2014),(991, 2, 36, 6, 2001),(585, 7, 4, 5, 1991),(227, 5, 13, 11, 2014),(241, 2, 27, 10, 1997),(688, 2, 29, 2, 2004),(699, 1, 27, 9, 1999),(897, 6, 11, 10, 2001),(809, 8, 17, 7, 2014),(897, 1, 28, 1, 2004),(385, 1, 36, 9, 2011),(611, 7, 18, 12, 2010),(715, 5, 32, 12, 1996),(320, 9, 30, 2, 2014),(176, 10, 36, 11, 1996),(209, 2, 27, 4, 2003),(325, 10, 6, 6, 2011),(479, 7, 16, 10, 2006),(508, 10, 8, 12, 2012),(551, 7, 23, 12, 2011),(402, 10, 33, 8, 1991),(561, 4, 22, 9, 2016),(311, 3, 6, 4, 2004),(639, 3, 1, 1, 2013),(489, 9, 9, 9, 2017),(721, 10, 20, 3, 1997),(222, 10, 35, 4, 1992),(552, 9, 7, 8, 2014),(653, 6, 6, 1, 2015),(413, 6, 26, 5, 2007),(447, 10, 27, 10, 2011),(841, 7, 31, 6, 2005),(657, 2, 8, 8, 2001),(305, 1, 32, 4, 1993),(787, 1, 27, 1, 1999),(627, 5, 24, 9, 2018),(450, 2, 30, 3, 2019),(172, 5, 10, 6, 1998),(786, 2, 29, 5, 1993),(655, 1, 30, 6, 2000),(3, 6, 5, 1, 2012),(864, 1, 36, 2, 1998),(472, 2, 15, 1, 2006),(848, 2, 7, 4, 2000),(230, 10, 2, 5, 2002),(941, 1, 22, 10, 2000),(223, 5, 26, 5, 2002),(890, 10, 23, 7, 1996),(859, 3, 32, 6, 2003),(16, 9, 10, 9, 2009),(604, 5, 2, 5, 2001),(578, 4, 24, 4, 2008),(861, 3, 1, 10, 2019),(588, 1, 11, 12, 2013),(337, 6, 9, 3, 2007),(903, 3, 18, 3, 2013),(448, 5, 28, 3, 1993),(227, 8, 8, 9, 1996),(870, 9, 19, 5, 2017),(932, 2, 28, 3, 2003),(873, 10, 16, 3, 2014),(902, 4, 32, 8, 2018),(868, 5, 17, 12, 2014),(458, 7, 23, 5, 2011),(548, 2, 32, 4, 2003),(513, 6, 5, 7, 1995),(561, 7, 26, 8, 1992),(453, 7, 9, 11, 2010),(932, 7, 7, 9, 2001),(307, 6, 14, 4, 2019),(923, 3, 9, 8, 1995),(902, 1, 5, 3, 2004),(477, 2, 10, 10, 2018),(503, 2, 14, 2, 2002),(403, 2, 33, 4, 2007),(653, 1, 1, 4, 2000),(413, 2, 13, 6, 1997),(866, 3, 5, 5, 2008),(686, 2, 32, 1, 1995),(236, 2, 20, 6, 2004),(416, 4, 11, 1, 2008),(121, 1, 20, 6, 2014),(868, 6, 14, 11, 2007),(989, 6, 6, 1, 2009),(423, 1, 33, 1, 1992),(733, 10, 33, 4, 1991),(261, 6, 21, 2, 2014),(185, 2, 9, 9, 1999),(533, 1, 7, 11, 1996),(814, 3, 5, 3, 2008),(426, 8, 24, 6, 2003),(449, 8, 6, 8, 2010),(30, 8, 22, 8, 2000),(85, 7, 22, 10, 2019),(775, 3, 25, 8, 1999),(484, 6, 13, 4, 1991),(132, 6, 12, 2, 2013),(261, 6, 6, 9, 2006),(113, 1, 10, 4, 2016),(351, 9, 21, 6, 2002),(508, 4, 2, 6, 2012),(58, 10, 13, 2, 1993),(657, 7, 36, 10, 1993),(292, 10, 31, 3, 2005),(683, 9, 27, 6, 1996),(604, 7, 8, 5, 1997),(274, 4, 31, 6, 2014),(853, 3, 35, 5, 1994),(551, 1, 28, 10, 1994),(421, 5, 11, 6, 1993),(734, 1, 32, 5, 1997),(377, 8, 15, 4, 2005),(854, 6, 11, 1, 1992),(326, 1, 33, 9, 2020),(83, 4, 13, 4, 2018),(509, 2, 11, 5, 2010),(947, 3, 5, 4, 2006);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql75, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql76 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (7, 7, 34, 8, 2009),(72, 1, 9, 8, 2015),(581, 7, 23, 8, 1997),(659, 7, 36, 5, 1997),(371, 9, 18, 12, 1998),(855, 2, 27, 9, 2005),(415, 9, 35, 2, 2015),(918, 7, 27, 4, 2002),(2, 7, 14, 10, 2005),(136, 4, 3, 5, 2006),(711, 2, 14, 5, 1999),(62, 5, 17, 10, 2011),(25, 7, 6, 6, 2011),(176, 7, 7, 9, 1997),(63, 6, 31, 4, 2009),(469, 9, 4, 11, 2002),(796, 5, 4, 4, 1999),(760, 8, 12, 9, 2016),(983, 9, 3, 7, 2016),(846, 4, 17, 11, 2004),(864, 10, 18, 10, 2017),(657, 7, 14, 8, 2009),(264, 9, 19, 10, 2007),(179, 3, 32, 8, 1997),(971, 3, 32, 3, 2007),(46, 4, 25, 1, 2003),(413, 5, 35, 11, 2014),(266, 8, 36, 11, 2015),(586, 7, 2, 3, 1998),(687, 8, 31, 5, 2010),(181, 6, 27, 4, 2000),(175, 3, 12, 8, 1999),(312, 9, 2, 11, 2016),(578, 1, 13, 7, 2018),(204, 3, 8, 5, 2016),(577, 3, 4, 12, 2000),(760, 6, 31, 6, 1991),(398, 8, 30, 11, 2016),(326, 5, 26, 2, 2016),(82, 6, 8, 7, 2005),(595, 6, 36, 10, 2002),(578, 9, 11, 3, 2008),(417, 2, 12, 4, 2016),(758, 5, 25, 5, 1995),(901, 3, 16, 8, 2017),(594, 2, 20, 7, 2001),(897, 6, 13, 3, 2009),(758, 7, 4, 12, 1997),(703, 3, 24, 6, 2009),(795, 6, 24, 4, 2008),(946, 8, 23, 11, 2008),(122, 1, 9, 10, 2000),(353, 10, 33, 10, 2014),(107, 3, 12, 11, 1992),(832, 4, 9, 4, 2012),(481, 3, 19, 5, 1999),(681, 5, 8, 5, 1991),(228, 5, 30, 4, 1994),(105, 8, 31, 3, 2012),(167, 8, 16, 10, 2002),(674, 2, 30, 9, 2014),(776, 6, 18, 8, 2014),(302, 1, 13, 7, 1999),(774, 8, 26, 11, 1997),(81, 2, 34, 6, 2019),(182, 10, 18, 11, 2011),(254, 8, 9, 5, 2006),(712, 4, 30, 6, 1993),(849, 1, 33, 3, 2019),(789, 3, 27, 7, 1999),(992, 8, 16, 8, 2005),(447, 5, 20, 6, 2012),(118, 2, 14, 2, 2013),(800, 1, 2, 10, 2002),(127, 6, 5, 4, 2015),(930, 1, 21, 7, 2003),(908, 5, 20, 6, 2002),(236, 10, 35, 12, 2003),(342, 5, 15, 5, 1999),(857, 9, 26, 5, 2006),(420, 10, 32, 3, 1993),(317, 4, 36, 11, 2011),(388, 9, 16, 3, 1991),(173, 1, 11, 8, 2018),(915, 8, 4, 2, 2002),(820, 4, 10, 1, 1998),(334, 2, 36, 8, 2000),(980, 4, 8, 3, 2007),(698, 5, 36, 5, 1997),(493, 4, 7, 6, 1997),(552, 9, 15, 6, 1998),(696, 5, 17, 6, 2017),(713, 1, 1, 11, 2001),(234, 7, 22, 6, 1992),(269, 4, 6, 8, 1991),(738, 10, 36, 3, 1996),(908, 10, 17, 9, 2000),(788, 9, 12, 7, 1995),(564, 8, 29, 2, 2017),(53, 3, 27, 4, 2000),(300, 10, 6, 6, 2002),(888, 4, 33, 12, 1994),(435, 8, 13, 9, 2013),(380, 7, 24, 4, 2005),(699, 8, 15, 2, 1994),(432, 8, 28, 12, 2005),(28, 3, 1, 12, 2010),(891, 10, 10, 8, 1997),(403, 3, 11, 2, 2001),(870, 3, 20, 2, 1995),(737, 4, 25, 9, 2010),(378, 7, 29, 8, 1999),(664, 3, 34, 10, 2011),(290, 4, 22, 1, 1996),(749, 6, 30, 8, 1994),(551, 1, 21, 11, 2005),(879, 7, 31, 6, 2008),(206, 1, 5, 7, 2018),(130, 6, 10, 3, 2009),(161, 4, 25, 2, 2010),(954, 10, 22, 1, 2009),(665, 2, 7, 7, 1993),(630, 9, 4, 10, 1999),(337, 5, 25, 8, 2011),(126, 2, 12, 6, 2004),(142, 9, 14, 4, 2004),(863, 5, 21, 8, 2008),(914, 8, 31, 8, 1995),(57, 5, 15, 8, 1998),(180, 10, 17, 12, 2004),(759, 8, 16, 8, 2011),(422, 4, 1, 12, 2000),(244, 5, 32, 8, 1992),(141, 5, 22, 11, 2004),(637, 1, 18, 7, 2015),(861, 6, 18, 8, 2011),(440, 3, 16, 4, 1994),(696, 6, 33, 9, 2007),(86, 8, 18, 4, 2020),(545, 1, 28, 4, 2016),(682, 10, 36, 6, 2014),(662, 5, 8, 2, 2002),(523, 6, 11, 7, 2009),(345, 7, 35, 7, 2004),(453, 9, 2, 3, 1998),(534, 7, 17, 9, 2012),(35, 4, 16, 9, 2001),(998, 8, 10, 6, 1997),(246, 10, 17, 2, 1998),(425, 1, 29, 11, 1991),(779, 6, 34, 3, 2015),(358, 6, 5, 12, 2001),(487, 4, 27, 12, 2018),(751, 2, 11, 1, 2014),(735, 2, 35, 9, 1991),(759, 4, 16, 6, 2007),(65, 5, 25, 10, 2016),(546, 8, 14, 4, 2009),(805, 9, 6, 11, 1994),(52, 4, 16, 4, 1992),(539, 6, 16, 8, 1999),(983, 9, 4, 4, 2013),(7, 5, 27, 7, 2007),(534, 10, 29, 5, 2002),(667, 8, 4, 10, 2007),(599, 9, 31, 5, 2020),(850, 3, 31, 3, 1995),(859, 3, 31, 2, 2010),(235, 9, 18, 9, 1999),(54, 4, 25, 4, 1993),(357, 4, 10, 3, 2005),(988, 1, 35, 4, 1995),(53, 10, 21, 10, 2009),(399, 7, 1, 5, 1996),(896, 7, 26, 4, 2000),(295, 5, 4, 2, 1992),(411, 8, 20, 1, 2018),(269, 3, 23, 1, 2006),(707, 7, 33, 1, 2005),(969, 9, 29, 9, 2008),(6, 3, 5, 2, 2009),(690, 2, 16, 5, 2010),(580, 9, 9, 8, 2015),(389, 1, 19, 12, 2000),(345, 7, 9, 4, 2019),(297, 5, 8, 12, 1995),(212, 1, 30, 6, 1997),(59, 8, 36, 11, 1998),(615, 7, 11, 5, 2004),(811, 6, 9, 6, 2004),(702, 9, 19, 11, 1998),(363, 4, 33, 1, 1996),(616, 1, 5, 7, 2000),(846, 6, 6, 8, 2018),(544, 1, 9, 11, 2007),(55, 6, 3, 7, 1997),(148, 5, 13, 4, 2018),(299, 3, 18, 3, 2003),(268, 6, 6, 7, 2017),(284, 8, 13, 12, 1998);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql76, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql77 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (146, 8, 26, 2, 2009),(971, 8, 21, 3, 1994),(940, 6, 17, 10, 2002),(361, 5, 27, 1, 2011),(854, 7, 16, 10, 2007),(936, 9, 32, 11, 2005),(357, 8, 13, 6, 1993),(826, 10, 27, 8, 2004),(124, 4, 26, 11, 1998),(689, 8, 15, 11, 2004),(340, 6, 24, 7, 2008),(293, 1, 14, 3, 2000),(119, 5, 2, 10, 2001),(630, 2, 7, 1, 2007),(669, 4, 34, 2, 1997),(319, 10, 10, 9, 1994),(314, 10, 35, 7, 1998),(297, 10, 35, 7, 2015),(936, 4, 13, 1, 2001),(893, 9, 19, 11, 2016),(102, 4, 6, 10, 1992),(363, 1, 13, 2, 1998),(883, 3, 18, 8, 1999),(237, 5, 27, 12, 2020),(995, 9, 13, 11, 2005),(508, 4, 29, 5, 2009),(934, 7, 32, 5, 2010),(121, 9, 6, 7, 2004),(938, 5, 34, 11, 1999),(790, 1, 23, 7, 2016),(321, 8, 10, 4, 1991),(862, 3, 4, 2, 2014),(159, 7, 33, 2, 2019),(330, 10, 36, 2, 2002),(287, 8, 15, 5, 2005),(691, 5, 8, 7, 2015),(180, 6, 23, 1, 1993),(39, 6, 33, 10, 2008),(901, 9, 25, 6, 1991),(516, 3, 13, 6, 1999),(14, 5, 15, 7, 1993),(770, 2, 29, 1, 2003),(674, 8, 3, 4, 1999),(240, 5, 5, 6, 1998),(458, 3, 36, 12, 2007),(70, 9, 16, 7, 1996),(286, 1, 3, 3, 2020),(927, 3, 20, 8, 2013),(487, 2, 36, 11, 2003),(903, 8, 30, 4, 2002),(62, 3, 11, 12, 2011),(475, 8, 19, 11, 2016),(367, 1, 8, 3, 2002),(528, 1, 27, 1, 1993),(762, 7, 12, 3, 1991),(475, 2, 6, 8, 1998),(981, 8, 27, 6, 2009),(977, 2, 29, 4, 1996),(339, 3, 19, 4, 2000),(693, 6, 11, 2, 2017),(758, 1, 16, 4, 1999),(870, 2, 24, 8, 2011),(130, 6, 21, 10, 2014),(323, 9, 7, 9, 2019),(533, 2, 8, 11, 1996),(301, 3, 1, 10, 2012),(282, 6, 12, 2, 2004),(172, 5, 25, 2, 2012),(889, 5, 23, 11, 2007),(540, 7, 25, 12, 2000),(122, 3, 8, 7, 2010),(263, 6, 22, 7, 2012),(245, 4, 9, 11, 2012),(313, 10, 27, 9, 1997),(948, 3, 16, 3, 1994),(436, 1, 6, 10, 2012),(574, 8, 21, 5, 1999),(150, 1, 14, 5, 1998),(129, 9, 16, 9, 2004),(348, 8, 30, 2, 2012),(894, 5, 20, 12, 1996),(943, 3, 18, 2, 2007),(703, 5, 13, 3, 2017),(239, 3, 15, 2, 2010),(671, 9, 1, 8, 2014),(914, 2, 34, 4, 2003),(589, 1, 22, 10, 2006),(865, 5, 5, 1, 2011),(778, 5, 10, 11, 2005),(784, 2, 26, 4, 2020),(948, 2, 11, 7, 2004),(832, 4, 17, 3, 1998),(94, 2, 2, 2, 1991),(264, 8, 27, 10, 1998),(362, 5, 23, 1, 2006),(525, 9, 33, 3, 2004),(80, 5, 22, 7, 1994),(35, 3, 29, 11, 2011),(664, 4, 23, 4, 2012),(378, 8, 11, 1, 2018),(178, 3, 25, 4, 2007),(826, 7, 20, 7, 2017),(741, 1, 18, 6, 2015),(272, 5, 31, 8, 2016),(458, 3, 26, 5, 2010),(722, 10, 19, 12, 2009),(658, 1, 11, 2, 1997),(941, 10, 36, 12, 1998),(118, 6, 18, 2, 2006),(237, 2, 12, 5, 1997),(974, 5, 1, 3, 2009),(599, 2, 24, 5, 1995),(394, 9, 30, 7, 2012),(247, 9, 8, 5, 1996),(552, 8, 1, 7, 2012),(2, 7, 13, 3, 2015),(617, 8, 35, 10, 2002),(718, 6, 14, 9, 1993),(621, 1, 16, 2, 2008),(919, 5, 19, 9, 1992),(247, 8, 1, 11, 2015),(911, 5, 18, 8, 2004),(213, 5, 2, 11, 1999),(783, 3, 36, 2, 1999),(532, 10, 19, 2, 2005),(4, 1, 24, 5, 2006),(122, 4, 6, 9, 2018),(165, 1, 26, 11, 2006),(417, 7, 8, 1, 2004),(984, 3, 6, 10, 2002),(964, 5, 3, 9, 2016),(485, 10, 13, 12, 2015),(254, 4, 24, 10, 2005),(774, 3, 16, 1, 2009),(246, 7, 33, 11, 1992),(302, 10, 19, 9, 2012),(222, 3, 20, 1, 1999),(765, 10, 30, 3, 1997),(103, 10, 4, 12, 1991),(964, 1, 21, 4, 2011),(693, 6, 33, 6, 2006),(508, 6, 14, 5, 2004),(159, 1, 28, 3, 1999),(49, 9, 6, 7, 1993),(117, 1, 24, 12, 2013),(749, 9, 21, 5, 1999),(565, 4, 26, 4, 2005),(359, 8, 17, 6, 2012),(913, 3, 34, 1, 1994),(306, 4, 10, 8, 2019),(944, 2, 17, 10, 1997),(990, 10, 31, 11, 2001),(688, 7, 21, 2, 2001),(182, 5, 25, 8, 2007),(892, 4, 15, 10, 2002),(907, 6, 29, 5, 2001),(391, 4, 34, 1, 2015),(165, 8, 14, 7, 1992),(344, 1, 23, 7, 1991),(430, 2, 3, 2, 2011),(403, 3, 8, 11, 2014),(224, 7, 13, 7, 1998),(120, 1, 22, 6, 1998),(275, 2, 9, 8, 2000),(258, 9, 13, 11, 1992),(426, 5, 15, 4, 2016),(438, 2, 10, 11, 2016),(120, 3, 19, 8, 1994),(366, 10, 16, 4, 2008),(628, 8, 33, 3, 2000),(348, 9, 34, 5, 2007),(991, 7, 24, 9, 2009),(24, 5, 11, 1, 2013),(528, 9, 6, 2, 2003),(51, 9, 11, 8, 1993),(881, 9, 16, 8, 2020),(239, 9, 20, 2, 2014),(555, 4, 26, 4, 1993),(646, 2, 29, 1, 2014),(234, 7, 17, 10, 2009),(17, 9, 4, 1, 2016),(628, 4, 32, 6, 2012),(182, 3, 8, 11, 1994),(527, 9, 14, 2, 2012),(620, 7, 27, 5, 2016),(733, 3, 14, 9, 1998),(597, 3, 10, 4, 2012),(869, 9, 2, 6, 1991),(461, 4, 5, 12, 2006),(592, 4, 30, 7, 1996),(403, 1, 27, 1, 2014),(567, 10, 27, 1, 2020),(644, 1, 21, 7, 2018),(123, 4, 5, 1, 2012),(294, 8, 35, 6, 2016),(815, 6, 1, 8, 2006),(736, 7, 23, 12, 2006),(622, 8, 27, 5, 2002),(408, 2, 29, 3, 1993),(764, 10, 33, 6, 1994);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql77, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql78 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (410, 5, 15, 6, 2004),(991, 3, 19, 6, 2002),(500, 7, 23, 8, 2008),(500, 2, 31, 10, 1998),(464, 6, 31, 5, 2018),(50, 5, 6, 5, 2005),(526, 4, 34, 6, 2012),(502, 10, 33, 12, 2019),(565, 5, 23, 2, 2003),(659, 5, 6, 7, 2016),(568, 3, 7, 4, 2010),(384, 5, 36, 10, 2016),(26, 4, 17, 5, 1998),(56, 8, 7, 8, 2019),(473, 3, 3, 10, 2013),(268, 8, 11, 7, 2017),(815, 6, 9, 12, 2019),(35, 9, 32, 1, 2004),(831, 6, 25, 5, 1993),(745, 3, 6, 5, 2002),(507, 4, 8, 4, 2008),(443, 6, 17, 11, 2016),(181, 1, 9, 6, 2004),(60, 5, 27, 7, 1995),(100, 2, 34, 8, 2009),(321, 7, 20, 10, 2012),(738, 3, 9, 12, 2014),(804, 3, 7, 1, 2003),(139, 4, 8, 12, 1992),(478, 9, 4, 3, 2020),(980, 4, 24, 3, 1998),(821, 6, 24, 5, 2007),(350, 8, 1, 9, 2018),(522, 4, 29, 12, 2011),(50, 5, 6, 11, 2017),(614, 1, 1, 3, 2016),(414, 6, 33, 12, 2003),(972, 3, 25, 10, 2007),(731, 6, 4, 9, 2009),(972, 9, 17, 6, 2010),(831, 7, 35, 5, 1992),(706, 1, 27, 12, 2005),(737, 9, 16, 8, 2007),(203, 1, 21, 4, 2000),(870, 3, 30, 6, 2001),(817, 6, 12, 11, 2006),(503, 4, 14, 7, 2019),(769, 3, 35, 9, 2010),(540, 10, 23, 12, 1997),(590, 9, 16, 9, 1997),(616, 10, 24, 9, 1991),(95, 5, 3, 11, 1999),(840, 7, 20, 4, 1998),(233, 10, 13, 9, 1997),(58, 10, 32, 7, 1996),(168, 4, 20, 1, 2019),(981, 4, 23, 2, 2003),(398, 9, 23, 10, 2016),(918, 3, 35, 6, 1994),(377, 6, 24, 10, 2001),(783, 2, 11, 12, 2004),(572, 8, 33, 11, 2011),(932, 3, 25, 9, 1995),(814, 2, 16, 12, 2004),(108, 9, 8, 2, 2001),(650, 6, 31, 1, 1992),(29, 9, 29, 12, 2020),(43, 8, 32, 4, 2018),(319, 8, 11, 1, 2008),(339, 1, 33, 7, 2004),(899, 1, 6, 4, 2003),(438, 7, 10, 5, 1997),(527, 8, 1, 5, 1991),(445, 7, 10, 7, 2002),(924, 5, 20, 4, 2016),(365, 3, 24, 4, 2007),(986, 8, 12, 5, 1994),(194, 8, 32, 2, 2000),(617, 3, 9, 1, 1999),(535, 6, 2, 7, 2006),(436, 5, 36, 1, 2003),(523, 2, 24, 10, 2007),(666, 5, 35, 8, 2006),(653, 6, 25, 6, 2003),(627, 1, 24, 2, 2000),(470, 8, 16, 9, 2017),(872, 4, 24, 2, 2005),(314, 5, 28, 5, 2019),(785, 3, 16, 8, 2001),(572, 2, 22, 7, 2006),(799, 7, 9, 9, 1996),(5, 8, 35, 3, 1991),(436, 1, 29, 1, 2015),(752, 6, 16, 3, 1994),(525, 7, 11, 8, 2010),(941, 3, 9, 8, 2003),(446, 5, 19, 9, 2002),(887, 10, 19, 5, 1996),(143, 4, 34, 8, 2016),(791, 1, 3, 8, 2018),(484, 2, 11, 6, 2005),(413, 10, 35, 9, 2009),(599, 10, 26, 8, 1995),(310, 4, 10, 3, 2017),(166, 9, 35, 8, 2016),(943, 7, 5, 10, 2016),(218, 5, 7, 6, 2015),(830, 8, 22, 3, 2013),(286, 1, 33, 8, 2005),(740, 9, 6, 6, 2013),(497, 1, 23, 8, 1995),(948, 10, 17, 9, 2008),(376, 4, 27, 11, 2013),(59, 10, 1, 12, 1992),(304, 8, 34, 5, 2014),(963, 10, 18, 1, 1997),(746, 1, 4, 7, 2005),(192, 9, 22, 8, 2005),(503, 5, 14, 3, 2001),(103, 1, 36, 2, 1993),(329, 10, 30, 7, 2003),(733, 5, 11, 1, 2001),(807, 3, 10, 12, 1997),(630, 9, 2, 5, 1998),(211, 7, 25, 2, 2016),(217, 6, 27, 8, 2007),(810, 8, 33, 10, 2002),(207, 10, 24, 6, 2015),(409, 6, 4, 5, 1992),(476, 1, 20, 2, 2010),(842, 10, 22, 4, 2010),(366, 6, 2, 10, 1998),(11, 3, 33, 7, 1991),(884, 2, 6, 4, 1999),(571, 10, 22, 12, 2006),(643, 2, 3, 4, 2019),(126, 2, 22, 1, 2012),(328, 8, 23, 11, 2016),(85, 2, 3, 4, 2011),(52, 2, 6, 4, 2002),(705, 5, 20, 5, 1997),(234, 10, 29, 2, 2003),(291, 7, 2, 11, 2019),(653, 5, 15, 2, 1993),(650, 8, 17, 9, 1992),(501, 5, 28, 8, 2000),(624, 1, 33, 2, 2000),(850, 2, 30, 1, 2001),(65, 7, 10, 6, 2009),(203, 10, 33, 12, 2003),(242, 10, 33, 4, 2004),(323, 8, 32, 12, 2020),(590, 4, 21, 11, 1993),(181, 2, 13, 11, 1999),(601, 3, 15, 1, 2006),(219, 9, 12, 3, 2002),(91, 10, 23, 1, 2003),(570, 6, 16, 5, 2020),(657, 6, 25, 4, 1999),(838, 2, 11, 1, 1995),(382, 8, 31, 4, 2005),(755, 5, 25, 7, 2001),(990, 5, 16, 7, 2012),(359, 9, 30, 11, 1991),(215, 7, 27, 6, 2000),(479, 2, 35, 8, 2018),(370, 9, 21, 12, 2020),(24, 10, 24, 4, 1993),(642, 2, 34, 10, 2003),(643, 7, 15, 10, 2000),(968, 6, 4, 3, 1995),(106, 2, 35, 8, 2002),(955, 2, 23, 9, 2000),(557, 2, 26, 8, 2016),(618, 8, 17, 11, 2019),(476, 10, 30, 6, 1994),(972, 2, 26, 1, 2017),(600, 7, 35, 3, 2003),(686, 2, 15, 2, 2017),(395, 8, 29, 12, 2004),(67, 9, 19, 9, 2011),(416, 3, 33, 5, 1993),(889, 5, 9, 8, 2012),(876, 8, 31, 9, 2012),(342, 7, 10, 9, 2003),(64, 5, 21, 5, 2012),(813, 6, 16, 3, 2001),(116, 1, 14, 12, 2017),(425, 9, 24, 2, 2012),(186, 3, 8, 2, 2019),(482, 9, 2, 1, 2018),(737, 7, 12, 6, 1994),(500, 1, 30, 9, 2013),(402, 1, 14, 11, 1994),(252, 3, 11, 5, 1991),(913, 4, 22, 7, 1995),(194, 2, 15, 7, 1994),(778, 3, 18, 11, 2001),(358, 9, 6, 2, 2009),(766, 3, 12, 6, 2011);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql78, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql79 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (522, 1, 24, 4, 2005),(876, 5, 17, 12, 1993),(492, 6, 12, 11, 2001),(69, 3, 5, 8, 2011),(481, 1, 17, 10, 1997),(226, 2, 8, 8, 1998),(243, 10, 29, 8, 2005),(737, 7, 14, 7, 2013),(547, 3, 11, 10, 2002),(351, 3, 19, 4, 2014),(153, 1, 3, 12, 1998),(350, 2, 5, 7, 1995),(378, 4, 26, 7, 2005),(374, 7, 9, 1, 2003),(920, 2, 25, 6, 2002),(398, 8, 28, 8, 2004),(785, 6, 36, 6, 2016),(933, 10, 13, 5, 2012),(887, 9, 36, 8, 2007),(749, 6, 5, 1, 2020),(480, 4, 29, 10, 2012),(602, 7, 28, 7, 2012),(94, 8, 26, 3, 1994),(323, 4, 35, 8, 1993),(731, 6, 22, 4, 2002),(807, 10, 22, 3, 2005),(271, 4, 14, 2, 1992),(314, 5, 21, 11, 2002),(641, 3, 23, 10, 2012),(284, 4, 34, 11, 2002),(972, 10, 23, 1, 2020),(307, 7, 30, 6, 2020),(688, 3, 17, 11, 2002),(689, 1, 9, 7, 2007),(472, 2, 6, 12, 2018),(254, 2, 30, 10, 1997),(395, 1, 19, 3, 1993),(739, 8, 16, 12, 1991),(941, 5, 13, 3, 1996),(519, 7, 5, 8, 2011),(903, 1, 14, 7, 2008),(802, 9, 9, 4, 2001),(945, 4, 1, 7, 2020),(114, 2, 26, 4, 1995),(132, 3, 20, 6, 2013),(784, 2, 26, 9, 1991),(382, 5, 13, 7, 1994),(687, 5, 1, 11, 2005),(597, 9, 16, 8, 1997),(556, 6, 17, 2, 2009),(94, 5, 28, 1, 2014),(922, 5, 21, 4, 2010),(952, 10, 21, 2, 2007),(21, 6, 11, 1, 1997),(181, 6, 14, 8, 2020),(255, 4, 28, 1, 2005),(203, 3, 7, 10, 2009),(385, 7, 2, 9, 1993),(36, 8, 2, 12, 2005),(26, 9, 20, 11, 2001),(481, 4, 17, 11, 2020),(697, 4, 5, 12, 1999),(19, 9, 29, 10, 1993),(983, 1, 10, 8, 2015),(638, 10, 17, 8, 1996),(350, 10, 14, 1, 1993),(60, 10, 5, 1, 2019),(904, 2, 33, 12, 2003),(735, 1, 21, 12, 2002),(536, 9, 31, 4, 2009),(887, 4, 30, 1, 1993),(374, 1, 16, 4, 2016),(750, 1, 20, 12, 1998),(737, 1, 9, 7, 1997),(266, 2, 9, 9, 2015),(519, 4, 9, 2, 2016),(564, 6, 19, 4, 2018),(861, 9, 23, 12, 2005),(287, 3, 29, 3, 1998),(978, 9, 8, 1, 2012),(413, 7, 10, 2, 2007),(867, 1, 1, 1, 2005),(239, 8, 8, 12, 2012),(860, 6, 26, 9, 2015),(897, 6, 11, 11, 2008),(681, 3, 8, 3, 1991),(900, 10, 15, 1, 2001),(839, 8, 34, 6, 2011),(339, 5, 34, 3, 2019),(41, 7, 32, 6, 1997),(999, 7, 26, 9, 2020),(866, 6, 31, 6, 2006),(789, 6, 11, 11, 2017),(414, 8, 11, 8, 1998),(944, 7, 28, 7, 2011),(433, 3, 15, 11, 2011),(523, 10, 8, 10, 2012),(286, 5, 5, 6, 2015),(125, 2, 21, 2, 2004),(83, 1, 2, 8, 1995),(930, 3, 26, 4, 2005),(556, 7, 23, 11, 2015),(428, 5, 6, 6, 2001),(479, 4, 2, 3, 2007),(754, 9, 12, 7, 1994),(104, 7, 8, 6, 2014),(637, 9, 18, 9, 1992),(496, 10, 11, 9, 1999),(790, 6, 25, 2, 1995),(689, 7, 25, 7, 2016),(194, 7, 3, 8, 1998),(587, 3, 30, 6, 1998),(659, 3, 30, 7, 1994),(855, 8, 11, 11, 2001),(855, 10, 23, 3, 2019),(340, 6, 16, 4, 1993),(780, 3, 11, 2, 2010),(323, 7, 29, 5, 2004),(52, 7, 25, 2, 2015),(294, 7, 16, 4, 1997),(671, 7, 7, 5, 1993),(968, 10, 26, 1, 2005),(97, 8, 27, 2, 2010),(184, 9, 21, 11, 1996),(341, 3, 27, 3, 1998),(646, 4, 32, 11, 2018),(591, 4, 22, 2, 2018),(416, 1, 35, 11, 2010),(158, 3, 28, 6, 2009),(61, 1, 24, 11, 2019),(958, 8, 26, 12, 2010),(943, 7, 29, 12, 1997),(113, 5, 10, 6, 2020),(249, 8, 31, 3, 2018),(354, 5, 33, 8, 2015),(999, 10, 36, 6, 2020),(162, 9, 16, 9, 2006),(135, 10, 24, 12, 2002),(763, 7, 9, 6, 1991),(784, 5, 15, 11, 2001),(130, 8, 30, 10, 2012),(36, 3, 18, 11, 2010),(781, 4, 3, 4, 2008),(481, 7, 4, 2, 2004),(628, 1, 25, 4, 1997),(213, 1, 16, 11, 2001),(916, 4, 29, 8, 2013),(321, 1, 1, 11, 2003),(445, 9, 33, 4, 2014),(333, 3, 36, 6, 2001),(997, 8, 2, 11, 2016),(571, 8, 1, 5, 2016),(912, 8, 27, 9, 1996),(691, 4, 7, 12, 2013),(583, 5, 13, 6, 2015),(149, 10, 18, 3, 2008),(346, 3, 13, 12, 2018),(471, 7, 14, 4, 2017),(987, 5, 30, 2, 1998),(446, 10, 7, 1, 1999),(18, 3, 26, 9, 2018),(242, 1, 16, 11, 2015),(790, 7, 5, 6, 1993),(909, 7, 9, 2, 2002),(415, 1, 32, 12, 2012),(369, 10, 1, 3, 2008),(845, 2, 32, 11, 2007),(779, 6, 12, 12, 2009),(165, 4, 3, 11, 2020),(861, 8, 4, 9, 2020),(90, 3, 32, 3, 2009),(223, 5, 29, 2, 2009),(846, 9, 5, 8, 1992),(752, 5, 35, 2, 2003),(577, 4, 4, 9, 2004),(865, 3, 36, 10, 1993),(496, 4, 11, 1, 2000),(751, 2, 2, 8, 2005),(772, 3, 7, 12, 1995),(444, 10, 1, 4, 2009),(715, 1, 9, 5, 2019),(536, 9, 23, 10, 1996),(24, 4, 3, 3, 2016),(879, 6, 13, 4, 2005),(75, 3, 19, 4, 2014),(461, 5, 22, 4, 2006),(103, 6, 35, 3, 1994),(914, 7, 15, 12, 2008),(842, 7, 16, 7, 1992),(9, 5, 13, 3, 2019),(248, 9, 30, 7, 2003),(705, 7, 4, 9, 1991),(187, 6, 6, 8, 2003),(49, 9, 5, 8, 2012),(635, 2, 5, 4, 2020),(589, 4, 18, 10, 1998),(320, 6, 10, 10, 2019),(763, 8, 31, 11, 2020),(315, 3, 11, 8, 2018),(113, 3, 9, 3, 2012);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql79, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql710 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (635, 2, 36, 1, 2010),(485, 5, 17, 9, 2003),(838, 10, 30, 1, 2016),(770, 1, 10, 4, 2002),(438, 8, 24, 11, 2010),(87, 9, 34, 6, 2005),(251, 10, 18, 5, 2017),(880, 3, 12, 2, 2008),(833, 1, 15, 10, 1995),(23, 4, 28, 10, 2016),(200, 5, 34, 6, 2005),(332, 1, 3, 11, 2001),(523, 1, 28, 11, 2013),(79, 5, 25, 1, 2003),(451, 6, 14, 2, 2006),(842, 2, 32, 9, 2020),(7, 4, 16, 8, 1994),(690, 8, 4, 3, 2017),(63, 5, 13, 4, 2004),(319, 3, 17, 8, 2004),(716, 5, 34, 11, 1992),(889, 6, 36, 12, 2002),(982, 3, 10, 11, 2002),(4, 9, 19, 12, 2013),(445, 1, 32, 4, 2007),(971, 5, 29, 10, 2014),(705, 3, 24, 1, 2015),(907, 4, 15, 12, 2019),(378, 7, 24, 10, 2017),(972, 7, 20, 5, 2017),(967, 6, 26, 10, 2015),(190, 7, 36, 9, 2015),(994, 7, 6, 5, 2017),(557, 8, 31, 11, 1994),(960, 5, 33, 9, 2008),(143, 9, 35, 2, 2020),(981, 9, 3, 5, 2014),(135, 10, 20, 4, 1993),(644, 3, 36, 9, 2001),(938, 5, 32, 6, 2002),(638, 5, 24, 6, 2018),(708, 7, 26, 11, 2008),(646, 1, 30, 2, 2013),(981, 7, 18, 7, 2000),(250, 1, 13, 10, 2003),(635, 2, 22, 1, 2010),(296, 9, 33, 3, 1999),(956, 7, 19, 10, 2009),(425, 1, 29, 9, 2001),(719, 8, 18, 5, 2013),(986, 8, 33, 9, 2006),(223, 3, 6, 3, 2002),(572, 8, 5, 12, 2011),(90, 1, 2, 5, 1996),(870, 9, 5, 6, 2000),(445, 9, 18, 3, 2003),(406, 6, 25, 2, 2013),(770, 4, 26, 5, 1998),(307, 4, 5, 1, 2011),(982, 6, 21, 5, 2013),(502, 8, 19, 11, 2006),(10, 6, 7, 5, 2003),(98, 8, 3, 2, 2004),(229, 3, 10, 1, 2015),(970, 2, 32, 10, 1999),(445, 2, 28, 7, 2001),(606, 9, 23, 5, 2020),(520, 7, 5, 10, 2016),(416, 5, 7, 9, 2005),(110, 7, 19, 8, 2008),(327, 9, 8, 9, 2020),(813, 3, 23, 3, 2000),(653, 3, 10, 11, 1991),(607, 2, 18, 6, 2016),(43, 3, 13, 11, 1999),(250, 2, 35, 8, 2001),(495, 8, 19, 5, 2005),(44, 10, 27, 11, 2007),(594, 1, 9, 5, 2019),(548, 8, 26, 11, 1996),(767, 7, 25, 9, 2000),(421, 2, 1, 10, 1991),(75, 9, 20, 6, 2004),(336, 3, 36, 11, 2019),(345, 10, 11, 4, 2017),(651, 1, 32, 4, 1996),(582, 1, 16, 5, 2019),(724, 5, 33, 7, 2014),(591, 5, 20, 12, 2000),(684, 8, 35, 8, 2012),(804, 9, 16, 7, 2020),(107, 8, 14, 6, 1995),(420, 9, 11, 12, 2016),(635, 1, 8, 11, 2007),(86, 5, 27, 10, 1991),(888, 1, 10, 8, 1998),(341, 1, 14, 2, 1998),(918, 5, 25, 4, 2019),(197, 10, 31, 8, 2000),(309, 5, 7, 11, 1997),(752, 9, 29, 3, 1995),(871, 5, 14, 6, 2004),(942, 5, 9, 6, 2006),(700, 3, 12, 8, 2016),(689, 5, 22, 12, 1994),(223, 4, 16, 4, 2004),(982, 10, 36, 1, 2019),(161, 5, 28, 3, 2015),(419, 8, 36, 11, 2006),(998, 8, 30, 9, 2014),(244, 9, 11, 10, 2015),(991, 7, 12, 5, 2012),(910, 9, 16, 12, 2007),(127, 3, 18, 11, 1998),(701, 2, 35, 12, 1995),(737, 9, 8, 8, 2003),(362, 8, 3, 7, 1991),(625, 8, 18, 10, 2020),(24, 7, 22, 10, 2009),(712, 2, 21, 8, 2005),(575, 4, 10, 4, 1993),(541, 3, 15, 11, 2012),(979, 10, 2, 11, 1999),(433, 9, 17, 5, 2012),(821, 8, 4, 5, 2011),(45, 1, 16, 3, 2002),(293, 4, 22, 7, 1992),(192, 7, 11, 6, 2015),(82, 1, 13, 4, 2020),(467, 5, 15, 6, 1993),(864, 1, 21, 11, 1996),(542, 5, 16, 4, 1998),(49, 9, 6, 10, 2018),(562, 10, 32, 10, 2013),(388, 7, 2, 6, 2017),(614, 2, 8, 4, 1994),(915, 6, 17, 11, 2007),(429, 6, 22, 12, 2016),(394, 4, 14, 2, 2018),(776, 8, 2, 8, 1992),(267, 8, 10, 3, 2018),(5, 6, 5, 3, 2006),(948, 4, 11, 9, 2003),(204, 7, 36, 11, 2015),(992, 8, 1, 6, 2016),(354, 6, 34, 10, 2019),(27, 1, 8, 4, 2015),(284, 4, 22, 6, 2010),(732, 6, 31, 1, 2006),(643, 9, 11, 8, 2002),(887, 2, 29, 3, 2014),(815, 6, 4, 7, 1998),(567, 4, 21, 9, 2019),(289, 4, 23, 6, 2007),(923, 2, 18, 2, 2015),(82, 7, 14, 8, 2001),(762, 2, 36, 3, 1995),(318, 8, 31, 8, 1996),(136, 4, 22, 5, 2002),(491, 7, 33, 2, 2013),(370, 5, 9, 7, 2009),(52, 5, 12, 11, 2008),(180, 1, 17, 4, 1998),(741, 2, 28, 6, 1991),(972, 2, 30, 10, 1997),(889, 9, 18, 3, 2019),(192, 4, 34, 8, 1998),(796, 1, 28, 4, 2013),(565, 7, 5, 2, 2017),(59, 7, 21, 7, 2000),(850, 8, 1, 12, 2010),(468, 6, 7, 5, 1998),(836, 3, 21, 10, 2020),(956, 5, 29, 3, 2004),(351, 5, 12, 7, 2005),(609, 8, 11, 7, 1997),(281, 1, 31, 3, 1992),(321, 2, 35, 9, 1994),(572, 9, 12, 7, 1992),(151, 3, 33, 12, 2000),(784, 9, 8, 3, 1997),(597, 7, 36, 10, 2006),(347, 6, 35, 3, 2019),(602, 2, 10, 8, 1997),(787, 5, 19, 2, 2014),(248, 1, 10, 3, 2019),(360, 10, 33, 6, 2015),(957, 9, 8, 9, 1995),(539, 9, 33, 7, 2012),(652, 3, 21, 8, 2011),(541, 7, 34, 6, 2020),(151, 2, 28, 6, 2015),(94, 7, 22, 2, 2018),(547, 6, 2, 4, 2020),(740, 5, 7, 6, 2012),(493, 1, 1, 8, 2006),(435, 10, 31, 4, 1996),(195, 6, 5, 3, 2009),(803, 4, 2, 9, 2008),(150, 3, 21, 2, 2015);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql710, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql711 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (413, 10, 1, 1, 2020),(874, 10, 7, 5, 2000),(8, 4, 24, 9, 2009),(139, 4, 1, 2, 1998),(372, 8, 22, 3, 2011),(880, 1, 26, 11, 1993),(488, 3, 14, 12, 2008),(905, 3, 13, 12, 2000),(559, 9, 4, 2, 2007),(69, 4, 32, 11, 2005),(749, 1, 22, 6, 2020),(43, 8, 24, 9, 1997),(619, 8, 17, 6, 1996),(31, 3, 31, 7, 2004),(497, 8, 22, 4, 1991),(812, 5, 8, 8, 1991),(692, 5, 19, 11, 1991),(210, 1, 18, 4, 1995),(984, 3, 27, 10, 2015),(895, 5, 36, 7, 2000),(169, 9, 33, 4, 1995),(856, 9, 26, 8, 2011),(656, 4, 3, 7, 2018),(943, 3, 17, 11, 2004),(187, 1, 23, 5, 1992),(473, 5, 5, 3, 2020),(837, 3, 8, 10, 2019),(490, 7, 14, 1, 1999),(170, 7, 32, 11, 2002),(68, 1, 34, 2, 2013),(88, 4, 23, 1, 1992),(166, 2, 8, 8, 2005),(743, 10, 11, 6, 2009),(819, 7, 19, 8, 2012),(741, 1, 11, 12, 2015),(847, 2, 31, 12, 2009),(905, 3, 18, 3, 2017),(702, 3, 4, 3, 2019),(314, 4, 13, 1, 1992),(849, 7, 19, 11, 2018),(533, 9, 8, 12, 2002),(923, 9, 19, 4, 2017),(648, 2, 21, 4, 2018),(102, 3, 9, 6, 1998),(968, 5, 5, 5, 2015),(364, 2, 20, 5, 1996),(918, 4, 16, 3, 2017),(746, 4, 2, 8, 2012),(226, 9, 31, 8, 2020),(314, 1, 30, 3, 2013),(393, 9, 35, 2, 2001),(710, 2, 1, 12, 1995),(362, 2, 15, 11, 2004),(524, 6, 13, 6, 2004),(58, 8, 2, 7, 2020),(424, 3, 31, 2, 1994),(868, 2, 2, 12, 2006),(819, 9, 16, 3, 2007),(981, 2, 1, 9, 2017),(801, 3, 23, 9, 1993),(630, 8, 14, 7, 1998),(640, 6, 30, 11, 1999),(456, 6, 29, 7, 2018),(964, 2, 25, 1, 2020),(341, 5, 1, 7, 2019),(268, 10, 4, 9, 2007),(223, 8, 6, 2, 2016),(473, 1, 6, 11, 2019),(74, 4, 9, 9, 1998),(306, 8, 20, 12, 2000),(268, 9, 8, 1, 1995),(854, 9, 23, 3, 2000),(349, 3, 15, 12, 2015),(427, 7, 30, 10, 2014),(217, 2, 19, 2, 2020),(511, 10, 5, 2, 1998),(98, 10, 9, 11, 1999),(4, 2, 13, 9, 2013),(212, 4, 15, 6, 2017),(620, 1, 36, 8, 1992),(354, 8, 4, 12, 1999),(958, 9, 3, 6, 1995),(351, 6, 29, 4, 1999),(404, 10, 31, 8, 1994),(142, 7, 36, 2, 2012),(290, 1, 26, 1, 1997),(120, 1, 15, 8, 2012),(336, 1, 25, 6, 1997),(843, 3, 29, 9, 1992),(409, 4, 17, 1, 1994),(888, 6, 19, 2, 2010),(361, 6, 1, 4, 2020),(408, 4, 4, 9, 1996),(216, 2, 34, 11, 2001),(870, 2, 32, 4, 2006),(813, 1, 26, 10, 1993),(951, 9, 21, 4, 2011),(443, 2, 6, 11, 1995),(107, 10, 17, 9, 2001),(176, 3, 10, 5, 2011),(841, 7, 20, 2, 2013),(86, 5, 13, 8, 1999),(192, 1, 24, 5, 2002),(59, 4, 36, 4, 1991),(578, 8, 28, 5, 2002),(830, 7, 19, 10, 1996),(169, 9, 21, 5, 1993),(548, 4, 15, 6, 2007),(867, 3, 27, 6, 2002),(245, 4, 4, 11, 2011),(808, 7, 8, 5, 2003),(224, 9, 2, 12, 2003),(230, 3, 30, 8, 2003),(165, 10, 24, 11, 2017),(180, 3, 32, 10, 1993),(366, 4, 32, 6, 1991),(66, 8, 11, 3, 2012),(819, 10, 31, 7, 2003),(204, 7, 34, 1, 2020),(29, 2, 32, 10, 2000),(167, 7, 30, 2, 2002),(991, 4, 28, 10, 2010),(782, 7, 32, 9, 2007),(626, 4, 26, 1, 2019),(167, 3, 9, 8, 1993),(759, 2, 36, 8, 2012),(414, 1, 1, 6, 2008),(858, 5, 9, 7, 2000),(592, 9, 27, 2, 1995),(897, 10, 31, 8, 1994),(505, 10, 15, 12, 2020),(787, 4, 5, 11, 1991),(7, 1, 13, 8, 1991),(695, 9, 23, 11, 2006),(726, 4, 15, 10, 2018),(753, 8, 16, 8, 2001),(325, 6, 8, 6, 1995),(64, 3, 25, 10, 1998),(822, 9, 26, 6, 2010),(450, 7, 2, 12, 2016),(40, 5, 5, 2, 2014),(79, 7, 36, 3, 2002),(674, 3, 4, 8, 2016),(695, 5, 10, 12, 1991),(590, 6, 34, 5, 2013),(868, 9, 23, 12, 2020),(517, 6, 30, 6, 2009),(588, 6, 27, 2, 2014),(28, 7, 33, 3, 2007),(255, 7, 21, 3, 1992),(749, 2, 34, 8, 2005),(166, 4, 30, 11, 1996),(538, 9, 8, 10, 2005),(244, 3, 21, 4, 2001),(266, 2, 3, 10, 1997),(781, 8, 18, 7, 2017),(39, 6, 31, 3, 1996),(735, 2, 28, 2, 2019),(831, 7, 26, 12, 2007),(991, 6, 4, 4, 2019),(422, 5, 25, 9, 2005),(275, 6, 3, 11, 2011),(499, 1, 30, 10, 1998),(585, 7, 28, 3, 1999),(628, 1, 35, 7, 1994),(621, 4, 21, 9, 1991),(256, 10, 17, 5, 2009),(43, 6, 27, 11, 2012),(693, 10, 2, 2, 1994),(42, 8, 13, 7, 1992),(100, 3, 7, 9, 2003),(998, 2, 17, 9, 2019),(413, 1, 21, 2, 2002),(248, 8, 17, 3, 2020),(430, 8, 15, 6, 2018),(785, 8, 9, 12, 2008),(706, 8, 6, 7, 1996),(125, 10, 6, 6, 2010),(158, 3, 7, 12, 2019),(773, 8, 5, 7, 2018),(611, 6, 24, 1, 2012),(199, 1, 28, 4, 1996),(296, 8, 23, 12, 2006),(33, 1, 16, 10, 2009),(968, 2, 5, 3, 1994),(826, 9, 4, 6, 1996),(124, 3, 18, 11, 2002),(756, 1, 26, 1, 2004),(26, 4, 13, 11, 1994),(154, 9, 18, 12, 2006),(536, 2, 24, 3, 1991),(533, 2, 25, 7, 1998),(863, 5, 16, 7, 2010),(426, 3, 12, 7, 2019),(957, 10, 14, 11, 2014),(906, 10, 28, 11, 1995),(494, 8, 25, 3, 2019),(213, 4, 22, 6, 2016),(815, 6, 1, 6, 2003),(206, 3, 23, 9, 2002);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql711, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql712 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (593, 9, 26, 1, 1991),(606, 3, 36, 11, 2014),(629, 1, 9, 2, 2002),(12, 9, 23, 4, 2018),(493, 6, 3, 3, 1999),(660, 6, 21, 7, 2009),(183, 9, 22, 12, 1994),(406, 4, 19, 4, 2014),(476, 4, 25, 2, 2000),(511, 10, 22, 11, 1994),(471, 9, 7, 3, 2007),(888, 1, 4, 10, 1995),(779, 7, 12, 9, 2013),(131, 6, 18, 1, 1999),(504, 2, 13, 9, 2002),(251, 5, 9, 9, 1992),(104, 9, 25, 12, 2001),(15, 9, 24, 5, 2019),(283, 9, 16, 3, 2017),(970, 3, 12, 4, 2014),(891, 5, 3, 12, 2011),(655, 2, 2, 7, 2013),(577, 5, 31, 3, 1995),(424, 7, 36, 12, 2009),(264, 10, 8, 6, 2003),(279, 9, 35, 1, 1998),(769, 7, 13, 3, 2007),(400, 3, 1, 8, 1994),(313, 5, 30, 2, 2011),(637, 10, 10, 2, 2001),(485, 4, 1, 10, 2019),(932, 5, 31, 3, 1993),(90, 9, 16, 4, 2017),(591, 8, 15, 9, 2014),(459, 4, 14, 5, 2018),(104, 6, 15, 3, 1993),(427, 7, 28, 6, 2013),(3, 3, 15, 10, 2020),(398, 6, 21, 7, 2000),(656, 1, 31, 5, 2005),(331, 7, 30, 1, 2012),(575, 1, 14, 8, 2016),(900, 4, 15, 2, 2006),(395, 1, 20, 5, 2005),(502, 2, 29, 12, 2005),(959, 9, 20, 9, 1995),(361, 10, 27, 10, 2008),(777, 6, 18, 8, 1996),(538, 5, 3, 2, 2020),(882, 5, 17, 7, 2020),(439, 8, 34, 9, 2002),(469, 10, 2, 1, 2016),(390, 2, 31, 9, 1991),(957, 10, 13, 4, 2002),(208, 9, 27, 3, 2014),(575, 3, 10, 1, 2002),(517, 10, 30, 3, 2018),(543, 1, 23, 4, 2007),(836, 6, 5, 7, 2016),(515, 5, 31, 7, 2009),(435, 7, 32, 3, 1991),(25, 8, 36, 8, 1993),(386, 3, 20, 10, 2018),(797, 5, 3, 5, 2008),(112, 2, 10, 11, 1994),(10, 2, 21, 8, 2019),(141, 7, 22, 6, 1991),(829, 8, 22, 12, 1999),(418, 4, 16, 7, 2015),(654, 3, 10, 10, 2013),(897, 6, 6, 1, 2020),(305, 9, 18, 10, 2017),(665, 7, 8, 3, 2008),(896, 5, 3, 7, 2001),(336, 10, 33, 9, 1993),(688, 1, 32, 1, 2013),(418, 3, 10, 9, 2011),(830, 6, 13, 10, 2008),(427, 3, 18, 8, 2017),(214, 4, 10, 9, 2009),(719, 8, 20, 8, 1998),(298, 9, 7, 4, 1997),(744, 2, 9, 11, 2005),(724, 3, 26, 1, 1997),(790, 3, 3, 11, 2003),(9, 8, 15, 2, 1992),(148, 9, 24, 11, 2004),(493, 8, 15, 7, 2002),(917, 6, 17, 12, 1998),(594, 9, 20, 5, 2011),(986, 8, 12, 9, 2013),(178, 5, 14, 6, 2005),(296, 5, 17, 7, 2011),(760, 4, 16, 11, 2006),(499, 3, 21, 9, 2006),(502, 10, 26, 1, 2008),(24, 6, 26, 5, 2005),(218, 2, 18, 3, 2019),(950, 5, 30, 6, 1995),(978, 6, 13, 4, 2005),(314, 8, 11, 2, 1992),(466, 5, 36, 2, 2015),(29, 3, 30, 1, 1994),(495, 2, 5, 4, 2006),(426, 6, 20, 3, 2006),(735, 10, 31, 5, 1997),(443, 10, 23, 2, 2008),(46, 4, 17, 5, 2001),(552, 3, 24, 9, 2016),(987, 3, 26, 9, 2017),(252, 7, 13, 1, 2009),(572, 2, 21, 5, 2004),(770, 8, 31, 10, 2016),(186, 1, 10, 3, 2011),(42, 1, 21, 10, 2004),(568, 6, 22, 9, 2006),(393, 2, 3, 5, 2009),(721, 2, 26, 11, 1995),(722, 3, 10, 11, 2007),(23, 3, 11, 1, 2009),(970, 5, 15, 11, 1999),(375, 3, 16, 3, 2012),(216, 8, 12, 7, 2011),(5, 8, 2, 10, 2006),(820, 10, 25, 10, 2002),(51, 2, 35, 10, 2002),(656, 10, 22, 3, 2014),(473, 2, 23, 5, 2000),(625, 1, 5, 8, 2019),(239, 8, 6, 4, 2012),(615, 3, 10, 4, 1998),(238, 8, 25, 6, 2009),(198, 3, 9, 10, 1995),(714, 3, 34, 2, 1992),(970, 5, 13, 12, 2009),(743, 10, 8, 12, 1993),(822, 4, 1, 10, 2009),(557, 7, 24, 2, 1994),(17, 1, 17, 11, 1996),(146, 7, 29, 9, 1997),(521, 7, 15, 11, 2011),(277, 1, 12, 4, 2001),(636, 2, 34, 7, 2012),(494, 3, 34, 7, 2006),(298, 5, 27, 3, 2019),(910, 5, 28, 6, 2011),(384, 10, 5, 2, 1992),(548, 8, 29, 11, 2005),(605, 2, 10, 7, 2013),(617, 9, 11, 2, 2017),(773, 1, 31, 9, 1994),(155, 8, 9, 2, 2005),(813, 10, 19, 6, 1995),(534, 3, 8, 1, 2020),(23, 7, 24, 8, 2004),(54, 9, 29, 10, 2004),(971, 3, 3, 11, 1991),(740, 4, 34, 9, 1997),(498, 10, 12, 9, 2001),(567, 4, 20, 3, 2016),(925, 2, 27, 11, 2009),(582, 9, 29, 12, 2019),(290, 10, 35, 4, 2007),(233, 4, 16, 11, 1998),(835, 10, 29, 8, 1996),(466, 2, 20, 12, 2002),(265, 10, 6, 12, 2000),(72, 3, 17, 12, 2018),(75, 6, 24, 9, 2014),(402, 10, 33, 5, 1997),(314, 3, 9, 6, 2008),(597, 3, 12, 8, 2019),(633, 2, 14, 4, 1991),(663, 1, 16, 12, 2018),(891, 6, 16, 7, 1991),(670, 2, 35, 3, 1991),(10, 3, 14, 8, 2006),(918, 6, 3, 12, 1992),(631, 7, 18, 4, 1996),(535, 3, 3, 9, 2017),(170, 9, 2, 1, 2016),(47, 8, 12, 12, 2007),(193, 8, 34, 3, 2009),(60, 1, 24, 1, 1994),(876, 10, 16, 1, 2017),(159, 9, 18, 8, 2018),(151, 10, 26, 6, 2017),(777, 4, 8, 9, 2004),(209, 5, 15, 7, 2010),(255, 7, 11, 5, 2010),(879, 8, 6, 6, 2019),(716, 5, 17, 8, 2020),(590, 9, 22, 10, 1997),(491, 3, 30, 4, 2004),(618, 8, 22, 6, 2008),(664, 2, 3, 1, 2013),(116, 4, 14, 1, 2011),(703, 4, 29, 6, 2010),(930, 6, 17, 2, 1991),(804, 3, 32, 6, 1991);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql712, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql713 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (168, 4, 13, 10, 2002),(217, 3, 5, 7, 2014),(228, 8, 11, 5, 2011),(905, 1, 10, 1, 2007),(459, 8, 4, 5, 2012),(288, 9, 24, 6, 1996),(492, 4, 14, 10, 1996),(849, 3, 16, 2, 1999),(437, 1, 3, 12, 2013),(904, 2, 33, 5, 1997),(149, 7, 13, 1, 1998),(418, 2, 15, 1, 2016),(504, 3, 15, 8, 2009),(894, 7, 20, 7, 2010),(336, 1, 23, 4, 2007),(706, 5, 32, 4, 2018),(19, 7, 30, 2, 1992),(657, 8, 5, 4, 1992),(72, 6, 25, 10, 2013),(286, 2, 20, 4, 2003),(11, 7, 2, 9, 1997),(626, 7, 12, 9, 2018),(166, 2, 5, 6, 2004),(313, 8, 17, 11, 2005),(616, 6, 19, 1, 2004),(505, 2, 22, 10, 2010),(64, 2, 2, 5, 1999),(852, 2, 5, 3, 1998),(683, 6, 36, 4, 2019),(221, 2, 6, 4, 2006),(644, 8, 5, 5, 2004),(153, 10, 6, 7, 2007),(553, 6, 4, 1, 2008),(170, 6, 28, 5, 2018),(983, 1, 21, 6, 1991),(276, 2, 20, 6, 2007),(246, 3, 14, 10, 2004),(328, 10, 31, 2, 2002),(414, 6, 16, 7, 2014),(299, 7, 14, 11, 2007),(274, 3, 12, 5, 2002),(103, 3, 34, 11, 1992),(676, 8, 24, 10, 1998),(220, 6, 3, 12, 2018),(738, 2, 3, 5, 2005),(198, 7, 14, 7, 2017),(346, 5, 12, 2, 1999),(160, 2, 1, 8, 2000),(730, 7, 4, 8, 2017),(253, 4, 31, 4, 2019),(625, 1, 33, 10, 1992),(821, 2, 2, 8, 1998),(39, 6, 2, 9, 2015),(492, 8, 33, 4, 1995),(866, 2, 36, 4, 2010),(585, 9, 18, 5, 2005),(339, 8, 22, 5, 2017),(512, 2, 11, 4, 2014),(220, 2, 31, 7, 2019),(553, 4, 6, 1, 2018),(212, 10, 30, 4, 2008),(481, 1, 23, 1, 2008),(647, 7, 29, 9, 2020),(945, 6, 6, 9, 1997),(834, 5, 6, 8, 2019),(457, 4, 25, 3, 1996),(580, 7, 11, 9, 2002),(481, 4, 36, 8, 2003),(222, 10, 22, 2, 2019),(534, 4, 24, 8, 1996),(615, 8, 4, 7, 1995),(775, 2, 21, 1, 2017),(571, 1, 9, 12, 2001),(32, 4, 33, 7, 2012),(216, 8, 36, 11, 2012),(51, 3, 32, 6, 2014),(787, 1, 3, 11, 2016),(359, 4, 8, 4, 2007),(93, 3, 7, 4, 1997),(88, 6, 35, 2, 1992),(562, 3, 35, 6, 2004),(680, 4, 11, 2, 1991),(887, 6, 18, 9, 1992),(789, 7, 32, 6, 2006),(356, 5, 1, 2, 1991),(811, 9, 28, 2, 2014),(389, 10, 34, 11, 2005),(706, 2, 15, 4, 1994),(167, 8, 14, 3, 1998),(876, 3, 21, 4, 2020),(920, 3, 35, 8, 1998),(882, 10, 34, 3, 1992),(857, 8, 23, 6, 2002),(655, 6, 4, 4, 1991),(877, 10, 33, 8, 1997),(116, 3, 23, 11, 1993),(922, 10, 5, 7, 1992),(552, 9, 32, 3, 2012),(211, 6, 10, 5, 1996),(952, 8, 1, 2, 2001),(579, 9, 11, 1, 2001),(810, 5, 32, 12, 1995),(576, 5, 4, 10, 2003),(404, 8, 16, 12, 2008),(411, 6, 26, 1, 2008),(181, 6, 5, 12, 2002),(91, 10, 11, 7, 2014),(206, 1, 16, 11, 2001),(489, 6, 1, 10, 2019),(99, 3, 25, 6, 1992),(530, 9, 33, 7, 2006),(932, 9, 25, 1, 2003),(396, 1, 27, 11, 2014),(908, 7, 2, 3, 2012),(722, 2, 4, 4, 1992),(386, 5, 6, 11, 1997),(50, 3, 2, 3, 1993),(992, 4, 30, 7, 1996),(726, 8, 26, 9, 1997),(857, 1, 28, 6, 2000),(444, 9, 10, 2, 1994),(387, 5, 34, 2, 2016),(314, 6, 27, 5, 2014),(712, 6, 16, 11, 2000),(376, 1, 23, 11, 2002),(448, 6, 2, 9, 2009),(834, 4, 20, 4, 1996),(192, 4, 36, 2, 1999),(595, 4, 27, 4, 2000),(975, 5, 6, 1, 2011),(228, 2, 36, 7, 1992),(209, 4, 16, 2, 2016),(869, 4, 7, 5, 2007),(238, 8, 21, 10, 2007),(661, 4, 28, 9, 2006),(776, 6, 25, 4, 2003),(607, 9, 9, 12, 1997),(618, 10, 18, 9, 2006),(931, 3, 22, 12, 2002),(157, 8, 21, 11, 2009),(569, 1, 6, 1, 2020),(120, 1, 10, 5, 1998),(411, 2, 15, 2, 1998),(311, 2, 33, 4, 1994),(658, 4, 36, 8, 2001),(930, 4, 26, 7, 2019),(796, 3, 31, 5, 2020),(22, 7, 20, 5, 2000),(681, 9, 20, 7, 2015),(338, 4, 19, 11, 1994),(952, 1, 15, 5, 2005),(409, 2, 24, 12, 1993),(412, 4, 21, 11, 2008),(639, 10, 26, 12, 2007),(797, 9, 6, 8, 2009),(939, 9, 32, 11, 1997),(967, 9, 1, 11, 2020),(435, 8, 21, 12, 1991),(938, 6, 20, 3, 2015),(339, 7, 28, 3, 2016),(766, 9, 34, 9, 1995),(521, 1, 22, 4, 2017),(199, 6, 21, 5, 2010),(705, 9, 5, 12, 2005),(901, 7, 13, 4, 2019),(164, 7, 3, 2, 2019),(106, 6, 4, 10, 2015),(304, 6, 11, 9, 1991),(74, 6, 24, 2, 1997),(307, 4, 32, 6, 2003),(701, 7, 25, 7, 2017),(846, 8, 33, 3, 2016),(357, 5, 5, 1, 1991),(183, 10, 24, 6, 1997),(616, 6, 23, 3, 2002),(808, 4, 18, 2, 2017),(92, 10, 31, 8, 2004),(72, 10, 3, 9, 2011),(539, 8, 18, 12, 2006),(759, 5, 32, 4, 1993),(380, 10, 24, 7, 2011),(156, 1, 9, 8, 2001),(295, 8, 4, 10, 2019),(841, 8, 27, 6, 2006),(378, 7, 26, 5, 1995),(491, 9, 21, 8, 2010),(998, 9, 15, 3, 2006),(264, 6, 35, 3, 2007),(707, 9, 20, 3, 2010),(382, 7, 30, 12, 1999),(301, 9, 15, 6, 2020),(502, 4, 23, 5, 2014),(250, 7, 6, 4, 1991),(466, 8, 17, 9, 2013),(502, 9, 27, 10, 2018),(781, 7, 31, 3, 2002),(546, 2, 33, 1, 1999),(42, 1, 16, 8, 1999),(919, 10, 24, 3, 1996),(250, 6, 21, 6, 2016);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql713, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql714 = "insert into ticket (subscriber_id, publication_id, subscription_term, month, year) values (3, 5, 23, 2, 2020),(543, 1, 20, 7, 1996),(873, 2, 9, 5, 2003),(365, 4, 29, 11, 2002),(982, 3, 31, 7, 2013),(117, 5, 29, 10, 1994),(352, 5, 14, 1, 2017),(52, 3, 24, 1, 1998),(342, 10, 34, 7, 2015),(943, 10, 8, 12, 2004),(65, 7, 13, 9, 2001),(908, 8, 31, 1, 2018),(811, 6, 14, 2, 2020),(175, 9, 29, 7, 1995),(354, 9, 28, 1, 2020),(533, 8, 12, 8, 2006),(518, 3, 23, 5, 1999),(852, 1, 18, 11, 2015),(377, 5, 33, 12, 2003),(544, 8, 12, 6, 1999),(281, 4, 35, 4, 1992),(656, 3, 5, 5, 2020),(680, 5, 1, 7, 2007),(786, 8, 19, 4, 1999),(33, 5, 1, 11, 2002),(166, 8, 6, 6, 1996),(339, 10, 27, 2, 2014),(32, 5, 13, 10, 2017),(434, 2, 11, 6, 2017),(567, 5, 15, 3, 2011),(314, 1, 26, 9, 1995),(5, 9, 34, 9, 2005),(350, 9, 28, 12, 2019),(566, 8, 13, 5, 2002),(862, 6, 35, 9, 2018),(571, 9, 34, 5, 1991),(526, 5, 17, 7, 2003),(638, 10, 27, 9, 1996),(955, 8, 16, 7, 2006),(785, 10, 13, 4, 2002),(470, 5, 24, 9, 2005),(886, 6, 15, 12, 2014),(53, 10, 33, 9, 2011),(908, 1, 29, 6, 1994),(762, 5, 9, 2, 1991),(191, 5, 24, 1, 2004),(697, 4, 4, 6, 2013),(313, 8, 27, 9, 1994),(141, 9, 6, 2, 2017),(18, 3, 6, 8, 2019),(642, 10, 15, 9, 2004),(197, 10, 4, 9, 1993),(982, 9, 35, 10, 2009),(264, 10, 18, 4, 1991),(930, 4, 13, 3, 1991),(824, 10, 3, 6, 2017),(809, 5, 14, 6, 1994),(964, 3, 28, 5, 1993),(952, 4, 1, 11, 2004),(171, 9, 20, 12, 2005),(959, 7, 5, 10, 1995),(547, 7, 16, 6, 2008),(125, 4, 9, 1, 2001),(372, 4, 29, 12, 2017),(331, 8, 2, 8, 1993),(456, 5, 2, 10, 2015),(144, 10, 34, 5, 1993),(507, 9, 33, 12, 2003),(563, 4, 3, 6, 2014),(322, 6, 29, 12, 2002),(907, 5, 35, 9, 2017),(529, 9, 30, 7, 2020),(392, 4, 30, 1, 2003),(672, 6, 27, 7, 2003),(488, 3, 3, 12, 1993),(839, 7, 11, 10, 2017),(74, 8, 16, 9, 2003),(376, 10, 35, 7, 2020),(230, 2, 16, 11, 2012),(152, 10, 34, 10, 2017),(305, 2, 15, 1, 2015),(832, 3, 34, 8, 1999),(726, 8, 7, 11, 1996),(692, 9, 4, 9, 1994),(856, 7, 11, 9, 1999),(955, 5, 12, 9, 2020),(146, 2, 3, 8, 1999),(970, 8, 36, 6, 2018),(490, 4, 7, 2, 1999),(937, 4, 2, 3, 2013),(658, 2, 10, 12, 2018),(815, 3, 9, 11, 2020),(12, 8, 26, 12, 2016),(674, 6, 10, 12, 2015),(549, 4, 31, 1, 2013),(973, 2, 10, 4, 2001),(54, 7, 21, 7, 2019),(675, 5, 12, 6, 1997),(211, 5, 19, 5, 2004),(880, 5, 15, 5, 1991),(405, 10, 30, 11, 1998),(120, 9, 15, 7, 2019),(334, 4, 1, 4, 2004),(295, 1, 13, 5, 1992),(733, 1, 28, 10, 2004),(495, 3, 14, 8, 2015),(784, 4, 8, 1, 2009),(133, 9, 7, 6, 1995),(859, 7, 15, 10, 2003),(737, 9, 32, 4, 2008),(508, 5, 4, 10, 1998),(532, 7, 27, 7, 2001),(975, 8, 20, 1, 2008),(52, 4, 27, 10, 1996),(602, 5, 2, 1, 2001),(226, 4, 32, 11, 2013),(330, 7, 7, 10, 2018),(14, 3, 34, 5, 2015),(897, 1, 14, 4, 2012),(557, 6, 25, 3, 2018),(551, 7, 6, 4, 2014),(604, 2, 1, 3, 2015),(670, 1, 8, 11, 2003),(952, 8, 8, 3, 2019),(227, 1, 20, 8, 2005),(809, 2, 4, 11, 1991),(445, 2, 11, 1, 1993),(681, 9, 33, 7, 2020),(188, 3, 3, 1, 1992),(776, 8, 6, 5, 1997),(20, 5, 29, 2, 2000),(512, 2, 22, 12, 1994),(929, 4, 5, 2, 1997),(413, 10, 16, 4, 2016),(323, 3, 9, 8, 2015),(635, 8, 20, 11, 1997),(665, 10, 23, 9, 2013),(235, 1, 6, 1, 2002),(153, 3, 14, 12, 1999),(264, 10, 19, 12, 2015),(976, 4, 17, 7, 2013),(475, 2, 17, 5, 1995),(139, 8, 36, 3, 2008),(294, 2, 15, 4, 2016),(952, 8, 2, 3, 1991),(409, 5, 5, 10, 1995),(240, 5, 7, 3, 2018),(947, 6, 1, 12, 1995),(486, 10, 20, 9, 2009),(568, 9, 1, 12, 2014),(782, 9, 13, 7, 1995),(276, 3, 23, 1, 2017),(252, 6, 14, 2, 2002),(466, 9, 23, 8, 2013),(593, 1, 33, 6, 2016),(67, 5, 36, 9, 2000),(801, 4, 19, 1, 2020),(387, 2, 32, 8, 1992),(391, 6, 6, 7, 2001),(31, 2, 28, 12, 2007),(321, 4, 10, 5, 2000),(233, 6, 10, 2, 2018),(413, 6, 6, 12, 1993),(945, 6, 15, 7, 1993),(343, 3, 16, 3, 1997),(167, 10, 25, 5, 2009),(38, 5, 9, 7, 2018),(813, 10, 5, 6, 2004),(935, 9, 22, 12, 2002),(192, 9, 11, 12, 2011),(155, 6, 31, 8, 2011),(913, 7, 16, 6, 1992),(232, 6, 5, 3, 1996),(741, 6, 8, 8, 2004),(410, 4, 25, 7, 2020),(80, 1, 30, 4, 2000),(439, 4, 31, 7, 1996),(693, 10, 28, 1, 1996),(921, 3, 17, 6, 1999),(314, 5, 10, 3, 2013),(534, 1, 24, 11, 2003),(591, 3, 11, 4, 2020),(999, 6, 30, 10, 2009),(120, 4, 34, 3, 2020),(805, 3, 4, 6, 2017),(601, 3, 26, 6, 2008),(335, 4, 13, 10, 2008),(529, 10, 33, 4, 2003),(474, 8, 21, 6, 2016),(554, 7, 7, 5, 2019),(563, 5, 6, 5, 1999),(508, 7, 13, 11, 2018),(412, 1, 35, 2, 2009),(98, 9, 34, 10, 1992),(841, 7, 9, 10, 2008),(72, 2, 10, 8, 2013),(401, 7, 23, 9, 2007),(197, 5, 31, 8, 1994),(331, 10, 23, 10, 1995),(454, 7, 19, 6, 1996);";
						//cout << "insert into ticket" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql714, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);


						const char* sql8 = "SELECT id,subscriber_id,publication_id,subscription_term,month,year FROM ticket ORDER BY subscription_term;";
						//cout << "SELECT id, subscriber_id, publication_id, subscription_term, month, year FROM ticket ORDER BY subscription_term; " << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql8, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{
								//cout << endl;
								//cout << "query return " << rowCount << " rows" << endl;
								//cout << "SELECT id,subscriber_id,publication_id,subscription_term,month,year FROM ticket ORDER BY subscription_term; " << endl;
								SQLINTEGER fieldId;
								SQLINTEGER fieldSubscriberid;
								SQLINTEGER fieldPublicationid;
								SQLINTEGER fieldSubscriptionterm;
								SQLINTEGER fieldMonth;
								SQLINTEGER fieldYear;
								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_SLONG, &fieldId, 0, NULL);
										SQLGetData(hStmt, 2, SQL_C_SLONG, &fieldSubscriberid, 0, NULL);
										SQLGetData(hStmt, 3, SQL_C_SLONG, &fieldPublicationid, 0, NULL);
										SQLGetData(hStmt, 4, SQL_C_SLONG, &fieldSubscriptionterm, 0, NULL);
										SQLGetData(hStmt, 5, SQL_C_SLONG, &fieldMonth, 0, NULL);
										SQLGetData(hStmt, 6, SQL_C_SLONG, &fieldYear, 0, NULL);
		
										//wcout << "Id: " << fieldId << " Subscriber id: " << fieldSubscriberid << " Publication id: " << fieldPublicationid << " Subscription term: " << fieldSubscriptionterm << " Month: " << fieldMonth << " Year: " << fieldYear << endl;


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

						const char* sql9 = "UPDATE ticket SET subscription_term = subscription_term + 1 where subscription_term >= 12;";						
						//cout << "UPDATE ticket SET subscription_term = subscription_term + 1 where subscription_term >= 12;" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql9, SQL_NTS);
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
						r = SQLSetStmtAttr(hStmt, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER)SQL_ODBC_CURSORS, SQL_IS_INTEGER);

						const char* sql10 = "SELECT id,subscriber_id,publication_id,subscription_term,month,year FROM ticket ORDER BY subscription_term;";
						//cout << "SELECT id,subscriber_id,publication_id,subscription_term,month,year FROM ticket ORDER BY subscription_term;" << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql10, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{
								//cout << endl;
								//cout << "query return " << rowCount << " rows" << endl;
								//cout << "SELECT id,subscriber_id,publication_id,subscription_term,month,year FROM ticket ORDER BY subscription_term; " << endl;
								SQLINTEGER fieldId;
								SQLINTEGER fieldSubscriberid;
								SQLINTEGER fieldPublicationid;
								SQLINTEGER fieldSubscriptionterm;
								SQLINTEGER fieldMonth;
								SQLINTEGER fieldYear;
								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_SLONG, &fieldId, 0, NULL);
										SQLGetData(hStmt, 2, SQL_C_SLONG, &fieldSubscriberid, 0, NULL);
										SQLGetData(hStmt, 3, SQL_C_SLONG, &fieldPublicationid, 0, NULL);
										SQLGetData(hStmt, 4, SQL_C_SLONG, &fieldSubscriptionterm, 0, NULL);
										SQLGetData(hStmt, 5, SQL_C_SLONG, &fieldMonth, 0, NULL);
										SQLGetData(hStmt, 6, SQL_C_SLONG, &fieldYear, 0, NULL);

										//wcout << "Id: " << fieldId << " Subscriber id: " << fieldSubscriberid << " Publication id: " << fieldPublicationid << " Subscription term: " << fieldSubscriptionterm << " Month: " << fieldMonth << " Year: " << fieldYear << endl;


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


						const char* sql11 = "select subscriber.surname, subscriber.name,publication.name,publication_type.type, ticket.subscription_term,ticket.month,ticket.year from ticket left join subscriber ON ticket.subscriber_id = subscriber.id left join publication on ticket.publication_id = publication.id left join publication_type on publication.type_id = publication_type.id;";
						//cout << "select subscriber.surname, ...." << endl;
						r = SQLExecDirect(hStmt, (SQLCHAR*)sql11, SQL_NTS);
						if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
						{
							SQLLEN rowCount;
							r = SQLRowCount(hStmt, &rowCount);
							if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
							{
								//cout << endl;
								//cout << "query return " << rowCount << " rows" << endl;
						
								SQLWCHAR fieldSurname[50];
								SQLWCHAR fieldName[50];
								SQLWCHAR fieldPName[50];
								SQLWCHAR fieldType[50];
								SQLINTEGER fieldTerm;
								SQLINTEGER fieldMonth;
								SQLINTEGER fieldYear;
								while ((r = SQLFetch(hStmt)) != SQL_NO_DATA)
								{
									if (r == SQL_SUCCESS || r == SQL_SUCCESS_WITH_INFO)
									{
										SQLGetData(hStmt, 1, SQL_C_WCHAR, &fieldSurname, 50, NULL);
										SQLGetData(hStmt, 2, SQL_C_WCHAR, &fieldName, 50, NULL);
										SQLGetData(hStmt, 3, SQL_C_WCHAR, &fieldPName, 50, NULL);
										SQLGetData(hStmt, 4, SQL_C_WCHAR, &fieldType, 50, NULL);
										SQLGetData(hStmt, 5, SQL_C_SLONG, &fieldTerm, 0, NULL);
										SQLGetData(hStmt, 6, SQL_C_SLONG, &fieldMonth, 0, NULL);
										SQLGetData(hStmt, 7, SQL_C_SLONG, &fieldYear, 0, NULL);
										
										//wcout <<"Surname: " << fieldSurname << " Name: " << fieldName << " PName: " << fieldPName << " Type: " << fieldType << " Term: " << fieldTerm << " Month: " << fieldMonth << " Year: " << fieldYear << endl;


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

					
						const char* sql12 = "drop table ticket,subscriber,publication,publication_type;";
						//cout << "drop" << endl;
 						r = SQLExecDirect(hStmt, (SQLCHAR*)sql12, SQL_NTS);
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
						unsigned int end_time = clock();
						cout << endl;
						cout << "����� ����������: " << (end_time - start_time) / 1000.0 << endl;


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