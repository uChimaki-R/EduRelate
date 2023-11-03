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

	top -= 1;//����һ��


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
		if (book[i].getnote() == 0)//������߼�������ì��
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
		cout << "ͼ��ά����" << endl;
		cout << "--------------------------" << endl;

		cout << "1������  2������  3��ɾ��\n4������  5����ʾ  6��ȫɾ  0���˳�" << endl;

		cin >> choice;

		cout << "--------------------------" << endl;

		switch (choice)
		{
		case 1:
			cout << "����ͼ���ţ�";
			cin >> bookid;

			cout << "����ͼ�����֣�";
			cin >> bookname;
			addbook(bookid, bookname);
			break;
		case 2:
			cout << "����ͼ���ţ�";
			cin >> bookid;
			b = query(bookid);

			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ�" << endl;

				break;
			}
			cout << "�����µ�ͼ������";


			cin >> bookname;
			b->setname(bookname);
			break;

		case 3:
			cout << "ɾ���ı��Ϊ" << endl;
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻����!" << endl;
				break;
			}
			//case3�ƺ������Ų�����break�����β���������ɾ��������ʱû�о���ʵ��
			//�����
			this->delete_onebook_0(b);
			cout << "ɾ���ɹ�" << endl;
			
			break;

		case 4:
			cout << "����ͼ���ţ�";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ�" << endl;
				break;
			}
			b->list();
			break;

		case 5:

			list();//�˴���list��BDatabase��list��������Book��Ĳ�ͬ
			break;

		case 6:
			cout << "�Ƿ�ȷ��ɾ�� 1��ȷ�� 0��ȡ��" << endl;
			int input;
			cin >> input;
			if (input)
			{
				clear();
				cout << "ɾ���ɹ�" << endl;
			}
			//�ƺ���δ����ʵ�ֵ�ȫ��ɾ��
			break;

		}
	}

	
}
