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


bool Student::operator==(Student& stu) {
	if (this->name == stu.name && this->id == stu.id && this->birth_year == stu.birth_year && this->birth_month == stu.birth_month && this->birth_day == stu.birth_day && this->gender == stu.gender && this->health_info == stu.health_info)return true;
	return false;
}

Student::~Student() {}


istream& operator>>(istream& cin, Student& stu) {
	cin.read((char*)&stu.birth_year, sizeof(stu.birth_year));
	cin.read((char*)&stu.birth_month, sizeof(stu.birth_month));
	cin.read((char*)&stu.birth_day, sizeof(stu.birth_day));
	cin.read((char*)&stu.gender, sizeof(stu.gender));
	stu.name.resize(cin.gcount());
	cin.read((char*)&stu.name[0], stu.name.size());
	stu.id.resize(cin.gcount());
	cin.read((char*)&stu.id[0], stu.id.size());
	stu.health_info.resize(cin.gcount());
	cin.read((char*)&stu.health_info[0], stu.health_info.size());
	return cin;
}

ostream& operator<<(ostream& cout, const Student& stu) {
	cout.write((const char*)&stu.birth_year, sizeof(stu.birth_year));
	cout.write((const char*)&stu.birth_month, sizeof(stu.birth_month));
	cout.write((const char*)&stu.birth_day, sizeof(stu.birth_day));
	cout.write((const char*)&stu.gender, sizeof(stu.gender));
	cout.write((const char*)&stu.name[0], stu.name.size());
	cout.write((const char*)&stu.id[0], stu.id.size());
	cout.write((const char*)&stu.health_info[0], stu.health_info.size());
	return cout;
}