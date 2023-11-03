#pragma once
#include<iostream>
#include"People.h"
using namespace std;

class Cadre:virtual public People
{
public:
	string post;
	void init_post(string _post);
	string get_post();
};