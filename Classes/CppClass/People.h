#pragma once
#include<iostream>
using namespace std;

class People
{
public:
	string name;
	bool sex;

	void init(string _name, bool _sex, int _age, string _tel = "", string _address = "");
	int get_age();
	string get_tel();
	string get_address();

private:
	int age;
	string tel;
	string address;
};