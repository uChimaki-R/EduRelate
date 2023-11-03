#pragma once
#include<iostream>
#include"Table.hpp"
#include"Student.h"
using namespace std;

class TableManager
{
public:
	Table<Student> stu_table;
	TableManager(Table<Student>& stu_table);
	bool insert_one(Student& stu);
	void show_table_info();
	int find_one(string& id);
	void delete_one(int& pos);
	~TableManager();
};