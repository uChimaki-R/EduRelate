#include<iostream>
#include"People.h"
#include"Cadre.h"
#include"Teacher.h"
#include"Teacher_Cadre.h"
using namespace std;

void test1();
void test3();

int main()
{
	//test1();
	test3();
	return 0;
}

void test3()
{
	Teacher_Cadre tc;
	string name, tel, address;
	bool sex;
	int age;
	cout << "(ÿ������Ϣ��һ���ո�ָ�)\n�����������������Ա�1��/0Ů�������䡢�绰����ַ:" << endl;
	cin >> name >> sex >> age >> tel >> address;
	tc.init(name, sex, age, tel, address);
	tc.show();
}

void test1()
{
	People p;
	string name, tel;
	bool sex;
	int age;
	cin >> name >> sex >> age >> tel;
	p.init(name, sex, age, tel);
	cout << endl << "age: " << p.get_age() << " tel: " << p.get_tel() << endl;
}