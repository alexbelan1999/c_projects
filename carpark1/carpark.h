#pragma once
#include<iostream>
#include<string>
using namespace std;
class vehicle 
{
protected:
	int id;
	string producer;
	string country;
	int year;
	string type;
	string cargo;
public:
	vehicle();
	vehicle(int n, string pr, string co, int ye);
	void setID(int i);
	void setPR(string str);
	void setCO(string str);
	void setYE(int n);
	void setTY(string t);
	void setCA(string c);
	int getID();
	string getPR();
	string getCO();
	int getYE();
	string getTY();
	string getCA();
	friend istream& operator>> (istream& s, vehicle& v);
	friend ostream& operator<< (ostream& s, vehicle& v);
	~vehicle();
};
class car : public vehicle
{
	string type = "Car";
	string cargo = "People";
	int number_of_passangers = 4;
public:
	string getTY();
	int getNOP();
	car();
	~car();

};
class bus : public vehicle
{
	string type = "Bus";
	string cargo = "People";
	int number_of_passangers = 150;
public:
	int getNOP();
	string getTY();
	bus();
	~bus();
};
class truck : public vehicle
{
	string type = "Truck";
	string cargo = "";
	int cargo_weight = 20000;
public:
	string getTY();
	int getCW();
	truck();
	~truck();
};
void input(vehicle *transport, int number);
void output(vehicle *transport, int number);
void find(vehicle *transport, int number);