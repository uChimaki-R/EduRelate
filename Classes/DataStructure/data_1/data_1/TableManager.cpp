#pragma once
#include"TableManager.h"
#include<iostream>
using namespace std;


TableManager::TableManager(Table<Student>& stu_table) {
	this->stu_table = stu_table;
}

bool TableManager::insert_one(Student& stu) {
	if (stu_table.last == stu_table.MaxSize - 1) return false;
	stu_table.data[++stu_table.last] = stu;
	return true;
}

void TableManager::show_table_info() {
	for (int i = 0; i <= stu_table.last; i++) {
		stu_table.data[i].show_info();
	}
}

void TableManager::delete_one(int& pos) {
	for (int i = pos; i <= stu_table.last; i++) {
		stu_table.data[pos] = stu_table.data[pos + 1];
	}
	stu_table.last--;
}

int TableManager::find_one(string &id) {
	for (int i = 0; i <= stu_table.last; i++) {
		if (stu_table.data[i].id == id)return i;
	}
	return -1;
}

TableManager::~TableManager() {}
