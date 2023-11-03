//省去预编译

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

	cout << "欢迎进入“小小图书馆”管理软件" << endl;

	while (choice != 0)
	{
		//cout << "1：借书 2：还书 3：图书维护 4：读者维护 0：离开" << endl;
		cout << "  *************************" << endl;
		cout << "  *        1.借书         *" << endl;
		cout << "  *        2.还书         *" << endl;
		cout << "  *      3.图书管理       *" << endl;
		cout << "  *      4.读者管理       *" << endl;
		cout << "  *        0.退出         *" << endl;
		cout << "  *************************" << endl ;
		cout << "请选择功能" << endl;
		cin >> choice;

		

		switch (choice)
		{
		case 1:
			cout << "输入借书读者编号：";
			cin >> readerid;
			cout << "输入图书馆编号：";
			cin >> bookid;
			r = ReaderDB.query(readerid);

			if (r == NULL)
			{
				cout << "该读者不存在，不能借书" << endl;
				break;
			}

			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在，不能借书" << endl;
				break;
			}
			if (b->borrowbook() == 0)
			{
				cout << "该图书已经借出，不能借书" << endl;
				break;
			}
			
			//发生借书的行为
			r->borrowbook(b->getnumber());
			b->shelf_to_0();
			
			//没有完成对书本onshelf变量的改变

			break;

		case 2:
			cout << "输入还书读者编号：";
			cin >> readerid;
			cout << "输入图书编号：";
			cin >> bookid;

			r = ReaderDB.query(readerid);

			if (r == NULL)
			{
				cout << "该读者不存在，不能还书！" << endl;
				break;
			}

			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在，不能还书" << endl;
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
			cout << "感谢使用图书管理系统！" << endl;
			exit(0);
		}
		system("pause");
		system("cls");
	}//end while

	
	return 0;
}