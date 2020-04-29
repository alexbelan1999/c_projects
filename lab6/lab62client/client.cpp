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

	char PCName[30], ServerName[30], IP[16] = "127.0.0.1";
	int PORT[6];
	WSAData WSADat; 
	sockaddr_in sin; 
	SOCKET Sock;

				 
	
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	WSAStartup(0x0202, &WSADat); 
	gethostname(PCName, 30); 

	sin.sin_family = AF_INET; 
	sin.sin_addr.s_addr = inet_addr(IP); 
	sin.sin_port = htons(0); 
	Sock = socket(AF_INET, SOCK_STREAM, 0); 

											
	printf("Connecting to server...\n");

	if (connect(Sock, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR) {
		printf("Connection error!\n");
		goto End;
	}

	send(Sock, PCName, strlen(PCName) + 1, 0); 
	recv(Sock, ServerName, 30, 0);


	printf("Connected to \"%s\"!\n", ServerName);


	send(Sock, username, strlen(username) + 1, 0);

	char usernames[200];
	recv(Sock, usernames, 200, 0);
	cout << "Saved users in server: " << usernames;

End:


	closesocket(Sock);
	WSACleanup();
	_gettch();
}