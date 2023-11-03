//读者信息库

#include<fstream>
#include<iostream>

#include"rdatabase.h"
#include"reader.h"


using namespace std;
#include<algorithm>
#include<functional>


RDatabase::RDatabase()
{
	Reader s;
	top = -1;

	ifstream file;
	file.open("reader.txt", ios::in | ios::binary);

	while (1)
	{
		file.read((char*)&s, sizeof(s));

		if (!file)
		{
			break;
		}
		top++;
		read[top] = s;
		
	}

	file.close();
}

void RDatabase::clear()
{
	top = -1;
}

void RDatabase::delete_one_reader(Reader* num)
{
	int pos = 0;
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnumber() == num->getnumber() && read[i].getnote() == 0)
		{
			pos = i;
			break;
		}
	}
	
	for (int i = pos; i <= top; i++)
	{
		read[i] = read[i + 1];
	}

	top -= 1;//减少一个人
}


Reader* RDatabase::query(int readerid)
{
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnumber() == readerid && read[i].getnote() == 0)
		{
			return &read[i];
		}
	}

	return NULL;
}


int RDatabase::addreader(int n, char* na)//The "n"is "readerid"
{
	Reader* p = query(n);
	if (p != NULL)
	{
		cout << "已存在对应编号的读者" << endl;
	}

	if (p == NULL)
	{
		top++;
		read[top].addreader(n, na);
		return 1;
	}

	return 0;
}


void RDatabase::list()
{

	for (int i = 0; i <= top; i++)
	{
		read[i].list();
	}
}

RDatabase::~RDatabase()
{
	fstream file;
	file.open("reader.txt", ios::out | ios::binary);

	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnote() == 0)
		{
			file.write((char*)&read[i], sizeof(read[i]));
		}
	}
	//此处书本标注不明确
	file.close();

}


void RDatabase::readerdata()
{
	int choice = 1;

	char readername[20];

	int readerid;

	Reader* r;

	while (choice != 0)
	{
		cout << "读者维护" << endl;
		cout << "--------------------------" << endl;
		
		cout << "1：新增  2：更改  3：删除\n4：查找  5：显示  6：全删  0：退出" << endl;

		cin >> choice;

		cout << "--------------------------" << endl;

		switch (choice)
		{
		case 1:
			cout << "输入读者编号：";
			cin >> readerid;
			cout << "输入读者姓名：";
			cin >> readername;

			addreader(readerid, readername);
			break;

		case 2:
			cout << "输入读者编号：";
			cin >> readerid;

			r = query(readerid);

			if (r == NULL)
			{
				cout << "该读者不存在" << endl;
				break;
			}

			cout << "输入新的姓名：";
			cin >> readername;
			r->setname(readername);
			break;


		case 3:
			cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在" << endl;
				break;
			}
			//似乎缺少了什么//删除功能同样没有实现
			//如果读者存在的话
			this->delete_one_reader(r);
			cout << "删除成功" << endl;


			break;

		case 4:
			cout << "输入读者编号：";
			cin >> readerid;

			r = query(readerid);
			if(r == NULL)
			{
				cout << "该读者不存在" << endl;
				break;
			}

			r->list();
			break;

		case 5:
			list();
			break;

		case 6:
			cout << "是否确认删除 1：确认 0：取消" << endl;
			int input;
			cin >> input;
			if (input)
			{
				clear();
				cout << "删除成功" << endl;
			}
			break;//似乎没有实现全部删除的功能

		}

	}


}


