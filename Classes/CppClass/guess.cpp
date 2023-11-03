#include"guess.h"

void Game::menu()
{
	cout << "*************************************" << endl;
	cout << "******** 1����ʼ��Ϸ         ********" << endl;
	cout << "******** 2���鿴��Ϸ����     ********" << endl;
	cout << "******** 3��������Ϸ���׶�   ********" << endl;
	cout << "******** 4���˳���Ϸ         ********" << endl;
	cout << "*************************************" << endl;
}

void Game::exit()
{
	cout << "���˳���Ϸ����л���棡" << endl;
	system("pause");
}

void Game::rule()
{
	cout << "������(��λ��)��Ϸ����" << endl;
	cout << "1�������������׶ȣ��粻���ã���Ĭ����ͼ���" << endl;
	cout << "   ���׶ȿɷ�Ϊ2-n����2�����������֣�3�����������֣�n����n������" << endl;
	cout << "2��������²�����֣���������ʱҪ�ÿո�ֿ�ÿ������" << endl;
	cout << "3����ʾ�����������ֵ��ȷ��λ����ȷ�ĸ���" << endl;
	cout << "   �����������ֵ��ȷ��λ�ò���ȷ�ĸ���" << endl;
	cout << "4�������ظ�2��3����ֱ����������ȫ��ȷ����ʾ��Ϸ��ʤ��" << endl;
	cout << "   ��ʱ������ȷ��������Ϸ��ʧ�ܡ�" << endl;
	system("pause");
	system("cls");
}

void Game::set()
{
	cout << "��ǰ�Ѷ�Ϊ��" << this->game_level << endl;
	cout << "��������Ҫ����Ϸ�Ѷȣ�2-n����> ";
	int input;
	cin >> input;
	while (input < 2)
	{
		cout << "�����������������룺> ";
		cin >> input;
	}
	this->game_level = input;
	cout << "�޸ĳɹ���" << endl;
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
		//���ô�
		int* answer = new int[this->game_level];
		for (int i = 0; i < this->game_level; i++)
		{
			answer[i] = rand() % 100;
		}
		////��ӡ���𰸷������
		//int len = this->game_level;
		//print_answer(answer, len);


		cout << "��ǰ�Ѷ�Ϊ��" << this->game_level << endl;
		cout << "1����ʼ������Ϸ" << endl;
		cout << "0���ص��˵�ҳ��" << endl;
		cin >> choice;
		int count_correct = 0;//λ�ú���ֵ����ȷ
		int count_same = 0;//��ֵ��ȷ
		while(choice)
		{
			count_correct = 0;
			count_same = 0;
			cout << "��ǰ�ǵ� " << this->count_guess + 1 << " �β²�" << endl;
			cout << "������²�����֣�" << endl;
			int* player_answer = new int[this->game_level];
			for (int i = 0; i < this->game_level; i++)
			{
				cin >> player_answer[i];
			}

			//�²����+1
			this->count_guess++;

			//�Ƚ�������������
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

			//��ʾ����
			cout << "���β²���ֵλ�ö���ȷ�����ָ���Ϊ��" << count_correct << endl;
			cout << "��ֵ��ȷ��λ�ò���ȷ�����ָ���Ϊ��" << count_same << endl;

			//�˳�����
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
			cout << "��ϲ�㣬�¶����������֣�" << endl;
			cout << "��Ϊ������Ѷȵȼ���" << endl;
			this->game_level++;
			this->count_guess = 0;
		}
		else
		{
			this->count_guess = 0;
			cout << "���β²���������ˣ����ź���û�в³��������֡�" << endl;
		}

	} while (choice);
	system("pause");
	system("cls");
}