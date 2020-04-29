#include "winsock2.h"
#include <Ws2tcpip.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <Lmcons.h>
using namespace std;

#pragma comment (lib, "ws2_32.lib")
#pragma comment (lib, "mswsock.lib")

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char PCName[30], ServerName[30];
	WSADATA wsaData;
	SOCKET sock;
	sockaddr_in clientAddress;
	WORD socketVersion = MAKEWORD(1, 1);
	

	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);


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
	clientAddress.sin_port = htons(11);
	inet_pton(AF_INET, "127.0.0.1", &(clientAddress.sin_addr));

	if (connect(sock, (sockaddr*)&clientAddress, sizeof(clientAddress)) < 0)
	{
		cout << "Connection failed: " << WSAGetLastError() << endl;
		//return -1;
	}
	gethostname(PCName, 30);
	cout << "Client: " << PCName << endl;
	send(sock, PCName, strlen(PCName) + 1, 0);
	recv(sock, ServerName, 30, 0);

	cout << "Connected to " << ServerName << endl;


	send(sock, username, strlen(username) + 1, 0);

	char usernames[200];
	recv(sock, usernames, 200, 0);
	cout << "Saved users in server: " << usernames << endl;
	
	closesocket(sock);
	

	cout << "Finished" << endl;;

	shutdown(sock, 0);
	WSACleanup();

	cin.get();
}