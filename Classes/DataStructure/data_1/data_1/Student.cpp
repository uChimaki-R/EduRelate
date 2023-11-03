#include"Student.h"
#include<iostream>
using namespace std;

Student::Student() {}

Student::Student(string name, string id, int birth_year, int birth_month, int birth_day, bool gender, string health_info) {
	this->name = name;
	this->id = id;
	this->birth_year = birth_year;
	this->birth_month = birth_month;
	this->birth_day = birth_day;
	this->gender = gender;
	this->health_info = health_info;
}

void Student::show_info() {
	cout << "-------------------------------" << endl;
	cout << "学生姓名：" << name << endl;
	cout << "学生性别：";
	if (gender) {
		cout << "男" << endl;
	}
	else {
		cout << "女" << endl;
	}
	cout << "学生出生年月日，以空格分割：";
	cout << birth_year << ' ' << birth_month << ' ' << birth_day << endl;
	cout << "学生学号：";
	cout << id << endl;
	cout << "学生健康信息：";
	cout << health_info << endl;
	cout << "-------------------------------" << endl;
}