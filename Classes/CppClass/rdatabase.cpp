//������Ϣ��

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

	top -= 1;//����һ����
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
		cout << "�Ѵ��ڶ�Ӧ��ŵĶ���" << endl;
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
	//�˴��鱾��ע����ȷ
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
		cout << "����ά��" << endl;
		cout << "--------------------------" << endl;
		
		cout << "1������  2������  3��ɾ��\n4������  5����ʾ  6��ȫɾ  0���˳�" << endl;

		cin >> choice;

		cout << "--------------------------" << endl;

		switch (choice)
		{
		case 1:
			cout << "������߱�ţ�";
			cin >> readerid;
			cout << "�������������";
			cin >> readername;

			addreader(readerid, readername);
			break;

		case 2:
			cout << "������߱�ţ�";
			cin >> readerid;

			r = query(readerid);

			if (r == NULL)
			{
				cout << "�ö��߲�����" << endl;
				break;
			}

			cout << "�����µ�������";
			cin >> readername;
			r->setname(readername);
			break;


		case 3:
			cout << "������߱�ţ�";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲�����" << endl;
				break;
			}
			//�ƺ�ȱ����ʲô//ɾ������ͬ��û��ʵ��
			//������ߴ��ڵĻ�
			this->delete_one_reader(r);
			cout << "ɾ���ɹ�" << endl;


			break;

		case 4:
			cout << "������߱�ţ�";
			cin >> readerid;

			r = query(readerid);
			if(r == NULL)
			{
				cout << "�ö��߲�����" << endl;
				break;
			}

			r->list();
			break;

		case 5:
			list();
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
			break;//�ƺ�û��ʵ��ȫ��ɾ���Ĺ���

		}

	}


}


