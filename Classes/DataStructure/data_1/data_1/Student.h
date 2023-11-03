#pragma once
#include<iostream>
using namespace std;


class Student
{
public:
	string name, id, health_info;
	int birth_year, birth_month, birth_day;
	bool gender;
	Student();
	Student(string name, string id, int birth_year, int birth_month, int birth_day, bool gender, string health_info);
	void show_info();

};