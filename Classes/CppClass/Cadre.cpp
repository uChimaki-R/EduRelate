#include"Cadre.h"
#include<iostream>
using namespace std;

string Cadre::get_post()
{
	return post;
}

void Cadre::init_post(string _post)
{
	post = _post;
}