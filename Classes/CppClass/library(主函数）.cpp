//ʡȥԤ����

#include<iostream>
#include"rdatabase.h"
#include"bdatabase.h"
#include"book.h"
#include"reader.h"


using namespace std;

int main()
{
	int choice = 1, bookid, readerid;
	RDatabase ReaderDB;
	BDatabase BookDB;
	Reader* r;
	Book* b;

	cout << "��ӭ���롰ССͼ��ݡ��������" << endl;

	while (choice != 0)
	{
		//cout << "1������ 2������ 3��ͼ��ά�� 4������ά�� 0���뿪" << endl;
		cout << "  *************************" << endl;
		cout << "  *        1.����         *" << endl;
		cout << "  *        2.����         *" << endl;
		cout << "  *      3.ͼ�����       *" << endl;
		cout << "  *      4.���߹���       *" << endl;
		cout << "  *        0.�˳�         *" << endl;
		cout << "  *************************" << endl ;
		cout << "��ѡ����" << endl;
		cin >> choice;

		

		switch (choice)
		{
		case 1:
			cout << "���������߱�ţ�";
			cin >> readerid;
			cout << "����ͼ��ݱ�ţ�";
			cin >> bookid;
			r = ReaderDB.query(readerid);

			if (r == NULL)
			{
				cout << "�ö��߲����ڣ����ܽ���" << endl;
				break;
			}

			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ����ܽ���" << endl;
				break;
			}
			if (b->borrowbook() == 0)
			{
				cout << "��ͼ���Ѿ���������ܽ���" << endl;
				break;
			}
			
			//�����������Ϊ
			r->borrowbook(b->getnumber());
			b->shelf_to_0();
			
			//û����ɶ��鱾onshelf�����ĸı�

			break;

		case 2:
			cout << "���뻹����߱�ţ�";
			cin >> readerid;
			cout << "����ͼ���ţ�";
			cin >> bookid;

			r = ReaderDB.query(readerid);

			if (r == NULL)
			{
				cout << "�ö��߲����ڣ����ܻ��飡" << endl;
				break;
			}

			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ����ܻ���" << endl;
				break;
			}
			
			b->retbook();
			r->retbook(b->getnumber());

			break;
			
		case 3:
			BookDB.bookdata();
			break;

		case 4:
			ReaderDB.readerdata();
			break;

		case 0:
			cout << "��лʹ��ͼ�����ϵͳ��" << endl;
			exit(0);
		}
		system("pause");
		system("cls");
	}//end while

	
	return 0;
}