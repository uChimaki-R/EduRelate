#include<iostream>
using namespace std;

int month[] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };

struct Date
{
	int year;
	int month;
};

int days(Date& d)
{
	if (d.month == 2 && (d.year % 4 == 0 && d.year % 100 != 0 || d.year % 400 == 0))
	{
		return month[0];
	}
	return month[d.month];
}

int main()
{
	Date d;
	cout << "��������ݣ�";
	cin >> d.year;
	cout << "�������·ݣ�";
	cin >> d.month;
	cout << "���·�����Ϊ��";
	cout << days(d);
	return 0;
}