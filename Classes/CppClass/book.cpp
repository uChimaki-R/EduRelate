//2. book.CPP(图书类实现)
//#include<iomainip.h>
#include<iomanip>

//#include "stdafx.h"
#include "book.h"

//自己补充的头文件
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
	note = 1;//note在1的时候是不写入文件的
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
	cout << "编号" << number << " 书名：" << name << " 是否在书库：";
	//<< onshelf << endl;
	if (onshelf)
	{
		cout << "是" << endl;
	}
	else
	{
		cout << "否" << endl;

	}
}

//#endif
//这个endif与书本不同