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
		cout << "请输入选择：";
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
			cout << "感谢使用！" << endl;
			system("pause");
			exit(0);
		default:
			cout << "输入有误，请重试！" << endl;
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
	cout << "**      欢迎使用小学运算练习器        **" << endl;
	cout << "** 练习类型：1、仅加法                **" << endl;
	cout << "**           2、仅减法                **" << endl;
	cout << "**           3、仅乘法                **" << endl;
	cout << "**           4、仅除法        0、退出 **" << endl;
	cout << "****************************************" << endl;
}

void test(char c)
{
	double a = rand() % 20 + 1;
	double b = rand() % 20 + 1;
	cout << "请尝试计算此式子：" << a << " " << c << " " << b << endl;
	cout << "你的答案是：";
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
		cout << "恭喜你回答正确！" << endl;
	}
	else
	{
		cout << "很抱歉，回答错误，正确答案是：" << correct << endl;
	}
	cout << "是否继续此练习类型？" << endl;
	cout << "1、是 0、否" << endl;
	cin >> input;
	if (input)
	{
		test(c);
	}
}