#include<iostream>
#include"stack.hpp"
using namespace std;

Stack<int> snum;
Stack<char> sop;

void cal()
{
	int num2 = snum.top();
	snum.pop();
	int num1 = snum.top();
	snum.pop();
	char op = sop.top();
	sop.pop();
	if (op == '+')
	{
		int num3 = num1 + num2;
		snum.push(num3);
	}
	else if (op == '-')
	{
		int num3 = num1 - num2;
		snum.push(num3);
	}
	else if (op == '*')
	{
		int num3 = num1 * num2;
		snum.push(num3);
	}
	else if (op == '/')
	{
		int num3 = num1 / num2;
		snum.push(num3);
	}
}

int main()
{
	char sts[200];
	cout << "输入表达式：";
	cin >> sts;

	for (int i = 0; i < strlen(sts); i++)
	{
		if (sts[i] >= '0' && sts[i] <= '9')
		{
			int num = 0;
			while (sts[i] >= '0' && sts[i] <= '9')
			{
				num = num * 10 + (sts[i] - '0');
				i++;
			}
			snum.push(num);
			i--;
		}
		else
		{
			if (sts[i] == '(')
			{
				sop.push(sts[i]);
			}
			else if (sts[i] == ')')
			{
				while (sop.top() != '(')
				{
					cal();
				}
				sop.pop();
			}
			else if (sts[i] == '+' || sts[i] == '-')
			{
				if (!sop.empty())
				{
					while (sop.top() == '*' || sop.top() == '/')
					{
						int num2 = snum.top();
						snum.pop();
						int num1 = snum.top();
						snum.pop();
						char op = sop.top();
						sop.pop();
						if (op == '*')
						{
							int num3 = num1 * num2;
							snum.push(num3);
						}
						else if (op == '/')
						{
							int num3 = num1 / num2;
							snum.push(num3);
						}
						if (sop.empty() || sop.top() == '(')
						{
							break;
						}
					}
					sop.push(sts[i]);
				}
				else
				{
					sop.push(sts[i]);
				}
			}
			else if (sts[i] == '*' || sts[i] == '/')
			{
				sop.push(sts[i]);
			}
		}
	}

	while (!sop.empty())
	{
		cal();
	}

	cout << "计算结果是：" << snum.top() << endl;
	return 0;
}
