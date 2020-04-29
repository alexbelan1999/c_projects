#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <Lmcons.h>
#include<iostream>
using namespace std;

#pragma comment (lib, "ws2_32.lib")
#pragma comment (lib, "mswsock.lib")

void main(void) {
	setlocale(0, "");

	char PCName[30], ServerName[30], IP[16] = { 0 };
	WSAData WSADat; // Свойства WinSock (результат функции WSAStartup)
	sockaddr_in sin; // Свойства(адрес) создаваемого сокета
	SOCKET Sock; // Клиентский сокет

				 // Ввод IP-адреса сервера
	printf("Enter server's IP: ");
	scanf_s("%15s", IP, 16);

	WSAStartup(0x0202, &WSADat); // Инициализация WinSock
								 // 0x0202 - версия WinSock. Может быть 1.0, 1.1, 2.0, 2.2
								 // WSADat - структура, куда будут занесены рез. инициализации
	gethostname(PCName, 30); // Получение имени текущего ПК

	sin.sin_family = AF_INET; // Тип адреса
	sin.sin_addr.s_addr = inet_addr(IP); // IP-адрес сервера (пори создании сервера можно 0)
	sin.sin_port = htons(7); // Номер порта сервера

	Sock = socket(AF_INET, SOCK_STREAM, 0); // Создание сокета

											// ***** Подключение к серверу
	printf("Connecting to server...\n");

	if (connect(Sock, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR) {
		printf("Connection error!\n");
		goto End;
	}

	send(Sock, PCName, strlen(PCName) + 1, 0); // Отправка имени этого компьютера (клиента)
	recv(Sock, ServerName, 30, 0); // Получение имени компьютера сервера


	printf("Connected to \"%s\"!\n", ServerName);

	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	send(Sock, username, strlen(username) + 1, 0);

	char usernames[200];
	recv(Sock, usernames, 200, 0);
	cout << "Saved users in server: " << usernames;

End:



	// Закрытие сокетов и окончание работы с WinSock
	closesocket(Sock);
	WSACleanup();
	_gettch();
}