#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;

//�������ִ���
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
	//��Ϸ�˵�
	void menu();

	//�˳���Ϸ
	void exit();

	//��ʼ��Ϸ
	void start();

	//������Ϸ���׶�
	void set();

	//��ӡ����
	void rule();
	
	int game_level;//��¼��ǰ��Ϸ�Ѷ�
	int count_guess;//��¼��ǰ�²����
};