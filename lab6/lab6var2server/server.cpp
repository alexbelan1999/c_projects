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
	WSAData WSADat; // �������� WinSock (��������� ������� WSAStartup)
	sockaddr_in sin; // ��������(�����) ������������ ������
	SOCKET Sock, Client; // ��������� � ���������� ������

	WSAStartup(0x0202, &WSADat); // ������������� WinSock
								 // 0x0202 - ������ WinSock. ����� ���� 1.0, 1.1, 2.0, 2.2
								 // WSADat - ���������, ���� ����� �������� ���. �������������
	gethostname(PCName, 30); // ��������� ����� �������� ��

	sin.sin_family = AF_INET; // ��� ������
	sin.sin_addr.s_addr = 0;  // IP-����� ������� (���� �������� ������� ����� 0)
	sin.sin_port = htons(7); // ����� ����� �������
	Sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // �������� ������
	bind(Sock, (sockaddr*)&sin, sizeof(sin)); // ���������� ���������� ������ � ������� sin


	printf("Wait of client...\n");

	listen(Sock, SOMAXCONN); // ������������� ������ �������� (��� ����������� �������)

	while (true) {
		cout << endl;
		Client = accept(Sock, (sockaddr*)&sin, 0); // �������� �������
		recv(Client, ClientName, 30, 0); // ��������� ����� ���������� �������
		send(Client, PCName, strlen(PCName) + 1, 0); // �������� ����� ����� ���������� (�������)

		printf("Client ( \"%s\" ) has connected!\n", ClientName);


		recv(Client, Name, 30, 0);
		for (int i = 0; i < strlen(Name); i++) {
			Names.push_back(Name[i]);
		}
		Names += " ";
		send(Client, Names.c_str(), Names.size() + 1, 0);
		cout << "Data sent successfully" << endl;


		// �������� ������� � ��������� ������ � WinSock
		closesocket(Client);

	}
	closesocket(Sock);




	WSACleanup();
	_gettch();
}