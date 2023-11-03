#include"Teacher.h"
#include<iostream>
using namespace std;

string Teacher::get_title()
{
	return title;
}

void Teacher::init_title(string _title)
{
	title = _title;
}

void Teacher::display()
{
	cout << "name: " << name << endl << "age = " << get_age() << endl;
	if (sex)
	{
		cout << "sex = boy" << endl;
	}
	else
	{
		cout << "sex = girl" << endl;
	}
	cout << "tel: " << get_tel() << endl << "address: " << get_address();
}