#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <Lmcons.h>
#include<iostream>
#include <string>
#pragma comment (lib, "ws2_32.lib")
#pragma comment (lib, "mswsock.lib")
using namespace std;

void main(void) {
	setlocale(0, "");

	char PCName[30], ClientName[30];
	char Name[30];
	string Names;
	WSAData WSADat; // Свойства WinSock (результат функции WSAStartup)
	sockaddr_in sin; // Свойства(адрес) создаваемого сокета
	SOCKET Sock, Client; // Серверный и клиентский сокеты

	WSAStartup(0x0202, &WSADat); // Инициализация WinSock
								 // 0x0202 - версия WinSock. Может быть 1.0, 1.1, 2.0, 2.2
								 // WSADat - структура, куда будут занесены рез. инициализации
	gethostname(PCName, 30); // Получение имени текущего ПК

	sin.sin_family = AF_INET; // Тип адреса
	sin.sin_addr.s_addr = 0;  // IP-адрес сервера (пори создании сервера можно 0)
	sin.sin_port = htons(7); // Номер порта сервера
	Sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // Создание сокета
	bind(Sock, (sockaddr*)&sin, sizeof(sin)); // Связывание созданного сокета с адресом sin


	printf("Wait of client...\n");

	listen(Sock, SOMAXCONN); // Прослушивание сокета сервером (для подключения клиента)

	while (true) {
		cout << endl;
		Client = accept(Sock, (sockaddr*)&sin, 0); // Ожидание клиента
		recv(Client, ClientName, 30, 0); // Получение имени компьютера клиента
		send(Client, PCName, strlen(PCName) + 1, 0); // Отправка имени этого компьютера (сервера)

		printf("Client ( \"%s\" ) has connected!\n", ClientName);


		recv(Client, Name, 30, 0);
		for (int i = 0; i < strlen(Name); i++) {
			Names.push_back(Name[i]);
		}
		Names += " ";
		send(Client, Names.c_str(), Names.size() + 1, 0);
		cout << "Data sent successfully" << endl;


		// Закрытие сокетов и окончание работы с WinSock
		closesocket(Client);

	}
	closesocket(Sock);




	WSACleanup();
	_gettch();
}