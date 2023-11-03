#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

#define ERROR 1e-3

enum choose
{
	out,
	add,
	subtract,
	multiply,
	divide
};

void menu();
void test(char c);


int main()
{
	srand((unsigned int)time(NULL));
	int input = 1;
	while (input)
	{
		menu();
		cout << "������ѡ��";
		cin >> input;
		switch (input)
		{
		case add:
			test('+');
			system("pause");
			system("cls");
			break;
		case subtract:
			test('-');
			system("pause");
			system("cls");
			break;
		case multiply:
			test('*');
			system("pause");
			system("cls");
			break;
		case divide:
			test('/');
			system("pause");
			system("cls");
			break;
		case out:
			cout << "��лʹ�ã�" << endl;
			system("pause");
			exit(0);
		default:
			cout << "�������������ԣ�" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}


void menu()
{
	cout << "****************************************" << endl;
	cout << "**      ��ӭʹ��Сѧ������ϰ��        **" << endl;
	cout << "** ��ϰ���ͣ�1�����ӷ�                **" << endl;
	cout << "**           2��������                **" << endl;
	cout << "**           3�����˷�                **" << endl;
	cout << "**           4��������        0���˳� **" << endl;
	cout << "****************************************" << endl;
}

void test(char c)
{
	double a = rand() % 20 + 1;
	double b = rand() % 20 + 1;
	cout << "�볢�Լ����ʽ�ӣ�" << a << " " << c << " " << b << endl;
	cout << "��Ĵ��ǣ�";
	double input;
	cin >> input;
	double correct = 0;
	switch (c)
	{
	case '+':
		correct = a + b;
		break;
	case '-':
		correct = a - b;
		break;
	case '*':
		correct = a * b;
		break;
	case'/':
		correct = a / b;
		break;
	}
	if (abs(input - correct) < ERROR)
	{
		cout << "��ϲ��ش���ȷ��" << endl;
	}
	else
	{
		cout << "�ܱ�Ǹ���ش������ȷ���ǣ�" << correct << endl;
	}
	cout << "�Ƿ��������ϰ���ͣ�" << endl;
	cout << "1���� 0����" << endl;
	cin >> input;
	if (input)
	{
		test(c);
	}
}