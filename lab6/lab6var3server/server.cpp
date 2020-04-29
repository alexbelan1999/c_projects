#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include<winsock2.h>
#include<iostream>
#include<cstdlib>
#include <ctime>
//#define _CRT_SECURE_NO_WARNINGS

using namespace std;

char* getDate() {
	char* res = new char[50];
	char* format = "%c";
	time_t t = time(NULL);
	strftime(res, 50, format, localtime(&t));
	return res;
}

char* stringCopy(char* a, int beg, int count) {
	if (beg < 0)
		return 0;

	char* res = new char[50];
	strcpy(res, &a[beg]);
	res[count - beg] = '\0';
	return res;
}

int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;//��������� WSADATA  
	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);/*������� socket(domain,type,protocol)[(�����,��� ������, ��������)]*//*����� - ��� ����������, ���������������
																													 ���������� �������� ��������� � ���������.*/
																													 /* ���������� ������ - ��� ��������� ���� sockaddr_in
																													 � ���� sin_addr ��������� sockaddr_in �������� ���������� IP - ����� ���������� �
																													 ������� ��������� in_addr, ���������� � ������������ ����� */
	if (s == INVALID_SOCKET) {
		WSACleanup();
		return -1;
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;//������ ���� ����� ������ �������� AF_INET  
	local.sin_port = htons(13);//���������� ����, ������� ����� ������������ � �������
	local.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY - ��������� ������ ��������� ��� �������� ������ ����� ����� IP ����� ������� ����������
	int c = bind(s, (struct sockaddr*)&local, sizeof(local));/*������� bind ��������� ���������� ����� � �������,
															 ���������� s - ���������� ������,��������� �� ��������� ������, ����� ���� ���������*/
	if (c == SOCKET_ERROR) {
		WSACleanup();
		return -1;
	}								 //����� �������� ������ � �������� ��� � ������ ���������� �����-�� ������� ���������� ��������� � ��������.��� ����� ������������ ������� 
															 //liste(s,l),������� �������� ����� � ��������� �������������
	int r = listen(s, 5);//����� ������� ���������� �������� ������� ������� �� �������� ����������,�������� l,������� � ������ ������ ����� 5
	if (r == SOCKET_ERROR) {
		closesocket(s);
		WSACleanup();
		return -1;
	}

	while (true)
	{
		//��������� ���������� ��������� �����, � ������� ����������� �����
		sockaddr_in remote_addr;
		int size = sizeof(remote_addr);
		int count;
		SOCKET s2 = accept(s, (struct sockaddr*)&remote_addr, &size);
		if (s2 == INVALID_SOCKET) {
			return -1;
		}

		char* buff = getDate();
		//�������� ������ �� ����������� �����
		count = strlen(buff);
		buff[strlen(buff)] = '\n';
		count++;

		cout << count << endl;
		cout << stringCopy(buff, 0, count) << endl;

		int i;
		char* a;
		char* b = buff;
		while (count != (i = send(s2, buff, count, 0))) {
			a = stringCopy(buff, i, count);
			delete buff;

			if (a == 0)
				break;

			buff = a;
			count -= i;
		}

		//cout << send(s2, buff, strlen(buff), 0) << endl;
		closesocket(s2);
		delete b;
		//delete res;
	}

	WSACleanup();
}