#include<iostream>
#include<ctime>
using namespace std;
#include"guess.h"

int main()
{
	srand((unsigned int)time(NULL));
	//��ʶ�趨�Ѷ�Ϊ2 �²����Ϊ0
	Game game(2, 0);

	int choice;
	do 
	{
		game.menu();
		cout << "���������ѡ��:> ";
		cin >> choice;
		switch (choice)
		{
		case start_game:
			game.start();
			break;
		case read_rule:
			game.rule();
			break;
		case set_level:
			game.set();
			break;
		case exit_game:
			game.exit();
			break;
		default:
			system("cls");
			cout << "�������������ԣ�" << endl;
			break;
		}

	} while (choice != exit_game);
	return 0;
}