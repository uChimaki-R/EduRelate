#include<iostream>
#include<ctime>
using namespace std;
#include"guess.h"

int main()
{
	srand((unsigned int)time(NULL));
	//初识设定难度为2 猜测次数为0
	Game game(2, 0);

	int choice;
	do 
	{
		game.menu();
		cout << "请输入你的选择:> ";
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
			cout << "输入有误，请重试！" << endl;
			break;
		}

	} while (choice != exit_game);
	return 0;
}