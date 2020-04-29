#include "winsock2.h"
#include <Ws2tcpip.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

#pragma comment (lib, "ws2_32.lib")
#pragma comment (lib, "mswsock.lib")

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char date[50];
	WSADATA wsaData;
	SOCKET sock;
	sockaddr_in clientAddress;
	WORD socketVersion = MAKEWORD(1, 1);

	if (WSAStartup(socketVersion, &wsaData) < 0)
	{
		cout << "Startup failed: " << WSAGetLastError() << endl;
		//return -1;
	}

	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock == INVALID_SOCKET)
	{
		cout << "Socket failed: " << WSAGetLastError() << endl;
		//return -1;
	}

	clientAddress.sin_family = AF_INET;
	clientAddress.sin_port = htons(13);
	inet_pton(AF_INET, "127.0.0.1", &(clientAddress.sin_addr));

	if (connect(sock, (sockaddr*)&clientAddress, sizeof(clientAddress)) < 0)
	{
		cout << "Connection failed: " << WSAGetLastError() << endl;
	}
		int i = recv(sock, date, 50, MSG_PEEK);
		while (date[i - 1] != '\n') {
			i = recv(sock, date, 50, MSG_PEEK);
		}

		date[i] = '\0';

		cout << "Date: " << date << endl;


		closesocket(sock);

	
	cout << "Finished" << endl;;

	shutdown(sock, 0);
	WSACleanup();

	cin.get();
}