#include<iostream>
#include"Teacher_Cadre.h"
using namespace std;

void Teacher_Cadre::init_wages(int _wages)
{
	wages = _wages;
}

int Teacher_Cadre::get_wages()
{
	return wages;
}

void Teacher_Cadre::show()
{
	Teacher::display();
}