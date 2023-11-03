//#include<iomainip.h>
#include<iomanip>
//include<stdafx.h>

#include"reader.h"

//const int Maxbor = 5;

#include<iostream>
#include<algorithm>
using namespace std;

char* Reader::getname()
{
	return name;
}

int Reader::getnote()
{
	return note;
}

int Reader::getnumber()
{
	return number;
}

void Reader::setname(char na[])
{
	strcpy_s(name, na);
}


void Reader::addreader(int n, char* na)
{
	note = 0;
	number = n;
	strcpy_s(name, na);
	for (int i = 0; i < Maxbor; i++)
	{
		borbook[i] = 0;
	}
}

void Reader::delbook()
{
	note = 1;
}

void Reader::borrowbook(int bookid)
{
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] == 0)
		{
			borbook[i] = bookid;
			return;
		}
	}
}

int Reader::retbook(int bookid)
{
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] == bookid)
		{
			borbook[i] = 0;
			return 1;
		}
	}

	return 0;
}

void Reader::list()
{
	//cout << setw(5) << number 
	//	<< setw(10) << name << "½èÊé±àºÅ£º[";

	cout<<"±àºÅ£º"<<number<<" ĞÕÃû£º"<<name<< "½èÊé±àºÅ£º[";

	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] != 0)
		{
			cout << borbook[i] << " ";
		}
		
	}
	cout << "]" << endl;
}
