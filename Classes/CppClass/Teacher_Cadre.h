#pragma once
#include"Cadre.h"
#include"Teacher.h"
#include"People.h"
#include<iostream>
using namespace std;

class Teacher_Cadre :public Teacher, public Cadre
{
public:
	void init_wages(int _wages);
	int get_wages();
	void show();
private:
	int wages;
};