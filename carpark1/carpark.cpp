#include<iostream>
#include<string>
#include "carpark.h"
using namespace std;
vehicle::vehicle()
{

}
car::car()
{

}
bus::bus()
{

}
truck::truck()
{

}
vehicle::vehicle(int n, string pr, string co, int ye)
{
	id = n;
	producer = pr;
	country = co;
	year = ye;
}
void vehicle::setID(int i)
{
	id = i;
}
void vehicle::setPR(string pr) 
{
	producer = pr;
}
void vehicle::setCO(string co)
{
	country = co;
}
void vehicle::setYE(int n)
{
	year = n;
}
void vehicle::setTY(string t)
{
	type = t;
}
void vehicle::setCA(string c)
{
	cargo = c;
}
int vehicle::getID()
{
	return id;
}
string vehicle::getCO()
{
	return country;
}
string vehicle::getPR()
{
	return producer;
}
int vehicle::getYE()
{
	return year;
}
string vehicle::getTY()
{
	return type;
}
string vehicle::getCA()
{
	return cargo;
}
string car::getTY()
{	
	string str;
	str = type + "- легковой автомобиль";
	return str;
}
string bus::getTY()
{
	string str;
	str = type + "- автобус";
	return type + "- автобус";
}
string truck::getTY()
{
	string str;
	str = type + "- грузовик";
	return type + "- грузовик";
}
int car::getNOP()
{
	return number_of_passangers;
}
int bus::getNOP()
{
	return number_of_passangers;
}
int truck::getCW()
{
	return cargo_weight;
}
istream& operator >> (istream& s, vehicle& v)
{
	cout << "Введите груз:" << endl;
	s >> v.cargo;
	cout << "Введите ID:" << endl;
	s >> v.id; 
	cout << "Введите производителя:" << endl;
	s >> v.producer;
	cout << "Введите страну производителя:" << endl;
	s >> v.country;
	cout << "Введите год выпуска:" << endl;
	s >> v.year;
	return s;
}
ostream& operator << (ostream& s, vehicle& v)
{
	cout << "Тип:" << endl;
	s << v.getTY() << endl;
	cout << "Груз:" << endl;
	s << v.getCA() << endl;
	cout << "ID:" << endl;
	s << v.getID() << endl;
	cout << "Производитель:" << endl;
	s << v.getPR() << endl;
	cout << "Страна производителя:" << endl;
	s << v.getCO() << endl;
	cout << "Год выпуска:" << endl;
	s << v.getYE() << endl;
	return s;
}
vehicle::~vehicle()
{
	
}
car::~car()
{

}
bus::~bus()
{

}
truck::~truck()
{
	
}
void input(vehicle *transport, int number)
{
	for (int i = 0; i < number; i++)
	{
		cout << "Введите тип содаваемого транспорта(0 - car, 1 - bus, 2 - truck): " << endl;
		int typet;
		cin >> typet;
		bool flag = false;
		if (typet == 0)
		{
			car Car = car();
			cin >> Car;
			Car.setTY("Car");
			transport[i] = Car;
			flag = true;
		}
		if (typet == 1)
		{
			bus Bus = bus();
			cin >> Bus;
			Bus.setTY("Bus");
			transport[i] = Bus;
			flag = true;
		}
		if (typet == 2)
		{
			truck Truck = truck();
			cin >> Truck;
			Truck.setTY("Truck");
			transport[i] = Truck;
			flag = true;
		}
		if (flag == false)
		{
			cout << "Неправильный тип." << endl;
		}

	}
}
void output(vehicle *transport, int number)
{
	for (int n = 0; n < number; n++)
	{
		cout << transport[n];
	}
}
void find(vehicle *transport, int number)
{
	string typefind;
	cin >> typefind;
	for (int n = 0; n < number; n++)
	{
		bool flag = false;
		if (transport[n].getTY() == typefind)
		{
			cout << transport[n];
			flag = true;
		}
		if (flag == false)
		{
			cout << "Совпадений нет." << endl;
		}

	}
}