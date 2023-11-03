#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;

//最多猜数字次数
#define MAX_GUESS 5

enum choice
{
	start_game = 1,
	read_rule,
	set_level,
	exit_game
};

class Game
{
public:
	Game(int game_level, int count_guess)
	{
		this->game_level = game_level;
		this->count_guess = count_guess;
	}
	//游戏菜单
	void menu();

	//退出游戏
	void exit();

	//开始游戏
	void start();

	//设置游戏难易度
	void set();

	//打印规则
	void rule();
	
	int game_level;//记录当前游戏难度
	int count_guess;//记录当前猜测次数
};