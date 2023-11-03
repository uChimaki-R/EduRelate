#pragma once
#include<iostream>
#include"People.h"
using namespace std;

class Teacher :virtual public People
{
public:
	string title;
	void init_title(string _title);
	void display();
	string get_title();
};