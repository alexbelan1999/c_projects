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
	WSADATA wsaData;//структура WSADATA  
	wVersionRequested = MAKEWORD(2, 2);
	WSAStartup(wVersionRequested, &wsaData);
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);/*Функция socket(domain,type,protocol)[(домен,тип сокета, протокол)]*//*Домен - это абстракция, подразумевающая
																													 конкретную стрктуру адресации и протоколы.*/
																													 /* Струкутура адреса - это структура типа sockaddr_in
																													 В поле sin_addr структуры sockaddr_in хранится физический IP - адрес компьютера в
																													 формате структуры in_addr, опписанной в заголовочном файле */
	if (s == INVALID_SOCKET) {
		WSACleanup();
		return -1;
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;//Данное поле имеет всегда значение AF_INET  
	local.sin_port = htons(13);//Определяет порт, который будет ассоциирован с сокетом
	local.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY - позволяет сокету принимать или посылать данные через любой IP адрес данного компьютера
	int c = bind(s, (struct sockaddr*)&local, sizeof(local));/*Функция bind связывает конкретный адрес с сокетом,
															 передается s - дескриптор сокета,указатель на структуру адреса, длниу этой структуры*/
	if (c == SOCKET_ERROR) {
		WSACleanup();
		return -1;
	}								 //После создания сокета и привязки его к адресу необходимо каким-то образом установить соедиение с клиентом.Для этого используется функция 
															 //liste(s,l),которая помещает пакет в состояние прослушивания
	int r = listen(s, 5);//Вызов функции инициирует ожидание запроса клиента на открытие соединения,параметр l,который в данном случае равен 5
	if (r == SOCKET_ERROR) {
		closesocket(s);
		WSACleanup();
		return -1;
	}

	while (true)
	{
		//Структура определяет удаленный адрес, с которым соединяется сокет
		sockaddr_in remote_addr;
		int size = sizeof(remote_addr);
		int count;
		SOCKET s2 = accept(s, (struct sockaddr*)&remote_addr, &size);
		if (s2 == INVALID_SOCKET) {
			return -1;
		}

		char* buff = getDate();
		//Посылает данные на соединенный сокет
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