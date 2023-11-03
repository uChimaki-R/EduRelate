#pragma once
#ifndef _book_h_
#endif//0这里有与书本中不同

#define _book_h_
#include<iostream>
using namespace std;
class Book
{
private:

	int note;

	int number;

	char name[10];
	int onshelf;
public:

	Book() {}
	char* getname();
	int getnote();

	int getnumber();

	void setname(char na[]);

	void delbook();

	void addbook(int n, char*);

	int borrowbook();

	void shelf_to_0();

	void retbook();

	void list();


};