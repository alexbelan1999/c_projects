#define _WINSOCK_DEPRECATED_NO_WARNINGS 
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h> 
#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[])
{

	char* servIP = "127.0.0.1";
	char date[50];

	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(13);
	peer.sin_addr.s_addr = inet_addr(servIP);
	if (SOCKET_ERROR == connect(s, (struct sockaddr*) &peer, sizeof(peer)))
		return -1;
	int i = recv(s, date, 50, MSG_PEEK);
	while (date[i - 1] != '\n') {
		i = recv(s, date, 50, MSG_PEEK);
	}

	cout << i << endl;
	date[i] = '\0';

	cout << "Date: " << date << endl;

	closesocket(s);
	WSACleanup();

	_getch();

	return 0;
}