#include"guess.h"

void Game::menu()
{
	cout << "*************************************" << endl;
	cout << "******** 1、开始游戏         ********" << endl;
	cout << "******** 2、查看游戏规则     ********" << endl;
	cout << "******** 3、设置游戏难易度   ********" << endl;
	cout << "******** 4、退出游戏         ********" << endl;
	cout << "*************************************" << endl;
}

void Game::exit()
{
	cout << "已退出游戏，感谢游玩！" << endl;
	system("pause");
}

void Game::rule()
{
	cout << "猜数字(两位数)游戏规则：" << endl;
	cout << "1：可先设置难易度，如不设置，则默认最低级。" << endl;
	cout << "   难易度可分为2-n级，2级猜两个数字，3级猜三个数字，n级猜n个数字" << endl;
	cout << "2：请输入猜测的数字，输入数字时要用空格分开每个数字" << endl;
	cout << "3：提示输入的数字数值正确和位置正确的个数" << endl;
	cout << "   输入的数字数值正确但位置不正确的个数" << endl;
	cout << "4：不断重复2、3步，直到猜数字完全正确，提示游戏者胜利" << endl;
	cout << "   或到时而不正确，宣布游戏者失败。" << endl;
	system("pause");
	system("cls");
}

void Game::set()
{
	cout << "当前难度为：" << this->game_level << endl;
	cout << "请输入想要的游戏难度（2-n）：> ";
	int input;
	cin >> input;
	while (input < 2)
	{
		cout << "输入有误，请重新输入：> ";
		cin >> input;
	}
	this->game_level = input;
	cout << "修改成功！" << endl;
	system("pause");
	system("cls");
}

void print_answer(int* answer, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << answer[i] << " ";
	}
	cout << endl;
}

void Game::start()
{
	int choice;
	do
	{
		//设置答案
		int* answer = new int[this->game_level];
		for (int i = 0; i < this->game_level; i++)
		{
			answer[i] = rand() % 100;
		}
		////打印出答案方便调试
		//int len = this->game_level;
		//print_answer(answer, len);


		cout << "当前难度为：" << this->game_level << endl;
		cout << "1、开始本次游戏" << endl;
		cout << "0、回到菜单页面" << endl;
		cin >> choice;
		int count_correct = 0;//位置和数值都正确
		int count_same = 0;//数值正确
		while(choice)
		{
			count_correct = 0;
			count_same = 0;
			cout << "当前是第 " << this->count_guess + 1 << " 次猜测" << endl;
			cout << "请输入猜测的数字：" << endl;
			int* player_answer = new int[this->game_level];
			for (int i = 0; i < this->game_level; i++)
			{
				cin >> player_answer[i];
			}

			//猜测次数+1
			this->count_guess++;

			//比较两个数组内容
			for (int i = 0; i < this->game_level; i++)
			{
				for (int j = 0; j < this->game_level; j++)
				{
					if (player_answer[i] == answer[j])
					{
						if (i == j)
						{
							count_correct++;
						}
						else
						{
							count_same++;
						}
					}
				}
			}

			//提示内容
			cout << "本次猜测数值位置都正确的数字个数为：" << count_correct << endl;
			cout << "数值正确但位置不正确的数字个数为：" << count_same << endl;

			//退出条件
			if (count_correct == this->game_level || this->count_guess == MAX_GUESS)
			{
				delete[]answer;
				delete[]player_answer;
				break;
			}
		}
		if (choice == 0)
		{
			break;
		}
		else if (count_correct == this->game_level)
		{
			cout << "恭喜你，猜对了所有数字！" << endl;
			cout << "已为你提高难度等级！" << endl;
			this->game_level++;
			this->count_guess = 0;
		}
		else
		{
			this->count_guess = 0;
			cout << "本次猜测次数用完了，很遗憾你没有猜出所有数字。" << endl;
		}

	} while (choice);
	system("pause");
	system("cls");
}