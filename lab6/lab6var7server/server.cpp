#include "winsock2.h"
#include <Ws2tcpip.h>
#include <iostream>
#include <random>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;


int main()
{
	WSADATA wsaData;
	SOCKET sock;
	sockaddr_in serverAddress;
	WORD socketVersion = MAKEWORD(1, 1);

	if (WSAStartup(socketVersion, &wsaData) < 0)
	{
		cout << "Startup failed: " << WSAGetLastError() << endl;
		return -1;
	}

	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock == INVALID_SOCKET)
	{
		cout << "Socket failed: " << WSAGetLastError() << endl;
		return -1;
	}

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(7778);
	inet_pton(AF_INET, "127.0.0.1", &(serverAddress.sin_addr));

	if (bind(sock, (sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
	{
		cout << "Binding failed: " << WSAGetLastError() << endl;
		return -1;
	}

	while (listen(sock, 10) == 0)
	{
		cout << "\nListening...\n";

		SOCKET clientSock;
		sockaddr_in clientAddress;
		int addressSize = sizeof(clientAddress);
		clientSock = accept(sock, (sockaddr*)&clientAddress, &addressSize);
		cout << "Client connected" << endl;

		char character;

		do
		{
			character = (char)rand();
		} while (send(clientSock, &character, 1, 0) >= 0);

		closesocket(clientSock);
	}

	shutdown(sock, 0);
	WSACleanup();

	cin.get();
}