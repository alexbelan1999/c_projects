#include "winsock2.h"
#include <Ws2tcpip.h>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

int main()
{
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
	clientAddress.sin_port = htons(7778);
	inet_pton(AF_INET, "127.0.0.1", &(clientAddress.sin_addr));

	if (connect(sock, (sockaddr*)&clientAddress, sizeof(clientAddress)) < 0)
	{
		cout << "Connection failed: " << WSAGetLastError() << endl;
		//return -1;
	}

	int counter = 10000;
	int dataLength = 0;
	char buff[255];

	if ((dataLength = recv(sock, buff, 255, 0)) >= 0) {
		cout << buff << " ";

		/*if (!counter--)
		{*/
		closesocket(sock);
		//break;
	//}
	}

	cout << "\nFinished";

	shutdown(sock, 0);
	WSACleanup();

	cin.get();
}