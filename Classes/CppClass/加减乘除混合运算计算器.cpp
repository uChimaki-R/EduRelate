#include<iostream>
using namespace std;

//表达式 = 项
//       = 项 +或- 项
//项 = 因子
//   = 因子 *或/ 因子
//因子 = （表达式）
//     = 整数

double expression();
double term();
double factor();

int main()
{
	double ret = expression();
	cout << "ret = " << ret << endl;
	system("pause");
	return 0;
}

double factor()
{
	double result = 0;
	char c = cin.peek();
	if (c == '(')
	{
		cin.get();
		result = expression();
		cin.get();
	}
	else
	{
		while (isdigit(c))
		{
			result = result * 10 + c - '0';
			cin.get();
			c = cin.peek();
		}
	}
	return result;
}

double term()
{
	double result = factor();
	while (true)
	{
		char next = cin.peek();
		if (next == '*')
		{
			cin.get();
			result *= factor();
		}
		else if (next == '/')
		{
			cin.get();
			result /= factor();
		}
		else
		{
			break;
		}
	}
	return result;
}

double expression()
{
	double result = term();
	while (true)
	{
		char next = cin.peek();
		if (next == '+')
		{
			cin.get();
			result += term();
		}
		else if (next == '-')
		{
			cin.get();
			result -= term();
		}
		else
		{
			break;
		}
	}
	return result;
}