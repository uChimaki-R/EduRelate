#pragma once
#include<iostream>
using namespace std;


class Student
{
public:
	string name = "null", id = "null", health_info = "null";
	int birth_year = 0, birth_month = 0, birth_day = 0;
	bool gender = 0;
	Student();
	Student(string name, string id, int birth_year, int birth_month, int birth_day, bool gender, string health_info);
	void show_info();
	bool operator ==(Student& stu);
	friend istream& operator>>(istream& cin, Student& stu);
	friend ostream& operator<<(ostream& cout, const Student& stu);
	~Student();
};