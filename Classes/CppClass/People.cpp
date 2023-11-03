#include<iostream>
#include"People.h"
using namespace std;

void People::init(string _name, bool _sex, int _age, string _tel, string _address)
{
	name = _name;
	sex = _sex;
	age = _age;
	tel = _tel;
	address = _address;
}
int People::get_age()
{
	return age;
}
string People::get_tel()
{
	return tel;
}
string People::get_address()
{
	return address;
}