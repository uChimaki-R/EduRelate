//2. book.CPP(ͼ����ʵ��)
//#include<iomainip.h>
#include<iomanip>

//#include "stdafx.h"
#include "book.h"

//�Լ������ͷ�ļ�
#include<string.h>



char* Book::getname()

{
	return name;
}

int Book::getnote()
{
	return note;
}

int Book::getnumber()

{
	return number;
}

void Book::setname(char na[])
{
	//strcpy(name, na);
	strcpy_s(name, na);

}

void Book::addbook(int n, char* na)
{


note = 0;

number = n;

//strcpy(name, na);
strcpy_s(name, na);

onshelf = 1; 
}

void Book::delbook()

{
	note = 1;//note��1��ʱ���ǲ�д���ļ���
}

int Book::borrowbook()

{
	return onshelf;
}

void Book::shelf_to_0()
{
	this->onshelf = 0;
}

void Book::retbook()

{
	onshelf = 1;
}

void Book::list()

{
	//cout << setw(5) << number << setw(10) << name << setw(10) << onshelf << endl;
	cout << "���" << number << " ������" << name << " �Ƿ�����⣺";
	//<< onshelf << endl;
	if (onshelf)
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "��" << endl;

	}
}

//#endif
//���endif���鱾��ͬ