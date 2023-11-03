#include <iostream>
#include <stack>
#include "Student.h"
#include <fstream>
#include "TreeNode.h"
using namespace std;

void menu() {
	cout << "******************************************" << endl;
	cout << "*****     学生健康情况管理系统       *****" << endl;
	cout << "*****    1.新建学生健康表            *****" << endl;
	cout << "*****    2.向健康表添加学生信息      *****" << endl;
	cout << "*****    3.从健康表删除学生信息      *****" << endl;
	cout << "*****    4.从文件读取健康表信息      *****" << endl;
	cout << "*****    5.向文件写入学生信息        *****" << endl;
	cout << "*****    6.从健康表查询学生信息      *****" << endl;
	cout << "*****    7.输出全部学生信息          *****" << endl;
	cout << "*****    8.退出                      *****" << endl;
	cout << "******************************************" << endl;
}

void create_table(bool& is_create) {
	if (!is_create) {
		cout << "成功创建健康表!" << endl;
		is_create = true;
	}
	else {
		cout << "健康表已经创建，请勿重复创建。" << endl;
	}
	system("pause");
	system("cls");
}

void insert_to_table(TreeNode*& root) {
	string name, id, health_info;
	int birth_year, birth_month, birth_day;
	bool gender;
	cout << "请输入学生信息：" << endl;
	cout << "学生姓名：";
	cin >> name;
	cout << "学生性别：";
	string word;
	cin >> word;
	if (word == "男") {
		gender = 1;
	}
	else {
		gender = 0;
	}
	cout << "学生出生年月日，以空格分割：";
	cin >> birth_year >> birth_month >> birth_day;
	cout << "学生学号：";
	cin >> id;
	cout << "学生健康信息：";
	cin >> health_info;
	Student stu(name, id, birth_year, birth_month, birth_day, gender, health_info);
	root = insertNode(root, stu);
	cout << "添加学生信息成功！" << endl;
	system("pause");
	system("cls");
}


TreeNode* inquire_from_table(TreeNode*& root) {
	cout << "请输入学生学号：";
	string id;
	cin >> id;
	TreeNode* val = searchNode(root, id);
	if (val) {
		cout << "查找到该学生信息如下：" << endl;
		val->data.show_info();
		return val;
	}
	else cout << "该学生不存在！" << endl;
	return NULL;
}

void delete_from_table(TreeNode*& root) {
	TreeNode* val = inquire_from_table(root);
	if (val == NULL) {
		system("pause");
		system("cls");
		return;
	}
	cout << "是否确认删除该学生信息：（1：是/2：否）" << endl;
	char choose;
	cin >> choose;
	if (choose == '1') {
		root = deleteNode(root, val->data.id);
		cout << "删除学生信息成功！" << endl;
	}
	system("pause");
	system("cls");
}

void get_info_from_file(TreeNode*& root) {
	cout << "请输入读取的文件名称（带后缀）：";
	string name;
	cin >> name;
	ifstream f(name, ios::in | ios::binary);
	if (f.is_open()) {
		while (!f.eof() && f.peek() != EOF) {
			Student stu;
			f >> stu;
			root = insertNode(root, stu);
		}
		f.close();
	}
	else {
		cout << "该文件不存在！" << endl;
	}
	system("pause");
	system("cls");
}

void saveNode(TreeNode* root, ofstream& f) {
	if (root == NULL)return;
	f << root->data;
	saveNode(root->left, f);
	saveNode(root->right, f);
}

void save_to_file(TreeNode*& root) {
	cout << "请输入写入的合法文件名称（带后缀）：";
	string name;
	cin >> name;
	ofstream f(name, ios::out | ios::binary);
	if (f.is_open()) {
		saveNode(root, f);
		f.close();
	}
	else {
		cout << "文件打开失败！" << endl;
	}
	system("pause");
	system("cls");
}

void show_all_info_from_table(TreeNode*& root) {
	preOrderTraversalRecursive(root);
	system("pause");
	system("cls");
}

int main() {
	bool is_create = false;
	TreeNode* root = NULL;
	while (true)
	{
		menu();
		cout << "请输入你的选择:";
		char choose;
		cin >> choose;
		if (choose >= '1' && choose <= '8') {
			switch (choose) {
			case '1':
				create_table(is_create);
				break;
			case'2':
				if (!is_create) {
					cout << "当前尚未创建健康表。" << endl;
					system("pause");
					system("cls");
				}
				else {
					insert_to_table(root);
				}
				break;
			case '3':
				if (!is_create) {
					cout << "当前尚未创建健康表。" << endl;
					system("pause");
					system("cls");
				}
				else {
					delete_from_table(root);
				}
				break;
			case '4':
				if (!is_create) {
					cout << "当前尚未创建健康表。" << endl;
					system("pause");
					system("cls");
				}
				else {
					get_info_from_file(root);
				}
				break;
			case '5':
				if (!is_create) {
					cout << "当前尚未创建健康表。" << endl;
					system("pause");
					system("cls");
				}
				else {
					save_to_file(root);
				}
				break;
			case '6':
				if (!is_create) {
					cout << "当前尚未创建健康表。" << endl;
					system("pause");
					system("cls");
				}
				else {
					inquire_from_table(root);
					system("pause");
					system("cls");
				}
				break;
			case '7':
				if (!is_create) {
					cout << "当前尚未创建健康表。" << endl;
					system("pause");
					system("cls");
				}
				else {
					show_all_info_from_table(root);
				}
				break;
			case '8':
				cout << "感谢使用学生健康情况管理系统！" << endl;
				exit(0);
				break;
			}
		}
		else {
			cout << "输入有误，请重试" << endl;
			system("pause");
			system("cls");
		}
	}
	return 0;
}