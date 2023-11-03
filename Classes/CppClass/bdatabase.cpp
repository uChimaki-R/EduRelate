//#include"stdafx.h"

#include<fstream>

#include<iostream>

#include"bdatabase.h"

using namespace std;

BDatabase::BDatabase()
{
	Book s;
	top = -1;

	fstream file;
	file.open("book.txt", ios::in | ios::binary);

	while (1)
	{
		file.read((char*)&s, sizeof(s));
		if (!file)
		{
			break;
		}

		top++;
		book[top] = s;
	}
	file.close();
}


void BDatabase::clear()
{
	top = -1;
}

void BDatabase::delete_onebook_0(Book* num)
{
	int pos = 0;
	for (int i = 0; i <= top; i++)
	{
		if (book[i].getnumber() == num->getnumber() && book[i].getnote() == 0)
		{
			pos = i;
			break;
		}
	}

	for (int i = pos; i <= top; i++)
	{
		book[i] = book[i + 1];
	}

	top -= 1;//减少一本


}



Book* BDatabase::query(int bookid)
{
	for (int i = 0; i <= top; i++)
	{
		if (book[i].getnumber() == bookid && book[i].getnote() == 0)
		{
			return &book[i];

		}
	}

	return NULL;
}


int BDatabase::addbook(int n, char* na)
{
	Book* p = query(n);
	if (p == NULL)
	{
		top++;
		book[top].addbook(n, na);
		return 1;

	}
	return 0;
}


void BDatabase::list()

{
	for (int i = 0; i <= top; i++)
	{
		book[i].list();
	}
}


BDatabase::~BDatabase()
{
	fstream file;

	file.open("book.txt", ios::out | ios::binary);

	for (int i = 0; i <= top; i++)
	{
		if (book[i].getnote() == 0)//这里的逻辑存在着矛盾
		{
			file.write((char*)&book[i], sizeof(book[i]));
		}

	}

	file.close();

}


void BDatabase::bookdata()
{
	int choice = 1;
	char bookname[20];
	 
	int bookid;

	Book* b;


	while (choice != 0)
	{
		cout << "图书维护：" << endl;
		cout << "--------------------------" << endl;

		cout << "1：新增  2：更改  3：删除\n4：查找  5：显示  6：全删  0：退出" << endl;

		cin >> choice;

		cout << "--------------------------" << endl;

		switch (choice)
		{
		case 1:
			cout << "输入图书编号：";
			cin >> bookid;

			cout << "输入图书名字：";
			cin >> bookname;
			addbook(bookid, bookname);
			break;
		case 2:
			cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);

			if (b == NULL)
			{
				cout << "该图书不存在！" << endl;

				break;
			}
			cout << "输入新的图书名：";


			cin >> bookname;
			b->setname(bookname);
			break;

		case 3:
			cout << "删除的编号为" << endl;
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在!" << endl;
				break;
			}
			//case3似乎存在着不可以break的情形产生，而且删除操作暂时没有经行实现
			//如果有
			this->delete_onebook_0(b);
			cout << "删除成功" << endl;
			
			break;

		case 4:
			cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在！" << endl;
				break;
			}
			b->list();
			break;

		case 5:

			list();//此处的list是BDatabase的list函数，与Book类的不同
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
			//似乎是未进行实现的全部删除
			break;

		}
	}

	
}
