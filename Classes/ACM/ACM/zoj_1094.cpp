#include <iostream>
#include <map>
#include <stack>
using namespace std;

int zm_cnt = 0;//计算出来的新矩阵的字母
map<char, pair<int, int>> mp;//保存矩阵的行列数
stack<char> matrix;//数字栈（矩阵栈）
stack<char> op;//运算符号栈（括号读取，矩阵间和部分位置补'#'当运算符）
int ans = 0;//乘法总数

int getval()
{
	char m2 = matrix.top();
	matrix.pop();
	char m1 = matrix.top();
	matrix.pop();
	if (mp[m1].second != mp[m2].first)
	{
		// 不合法
		return -1;
	}
	ans += (mp[m1].first * mp[m1].second * mp[m2].second);
	//生成结果矩阵
	mp['a' + zm_cnt].first = mp[m1].first;
	mp['a' + zm_cnt].second = mp[m2].second;
	matrix.push('a' + zm_cnt);//将结果矩阵放入数字栈
	zm_cnt++;//下次的新矩阵字母改变
	return ans;
}

int main()
{
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		char ch;
		int r, c;
		cin >> ch >> r >> c;
		mp[ch].first = r;
		mp[ch].second = c;
	}
	string s;
	while (cin >> s)
	{
		//数字栈 运算符栈清空
		while (!matrix.empty())
		{
			matrix.pop();
		}
		while (!op.empty())
		{
			op.pop();
		}
		ans = 0;//结果置零
		int flag = 0; // 判断矩阵乘法是否合法
		for (int i = 0; i < s.length(); i++)
		{
			if (isalpha(s[i]))//是否是矩阵（字母）
			{
				//矩阵
				matrix.push(s[i]);
				if (i != s.length() - 1 && s[i + 1] != ')')
				{
					//不是在结尾或者下一个不是')'就是应该有运算符的
					op.push('#');
				}
			}
			else if (s[i] == '(')
			{
				//左括号
				op.push(s[i]);
			}
			else
			{
				//右括号
				//找到右括号就要把之前的计算出来，直到找到第一个左括号
				while (op.top() != '(')
				{
					if (getval() == -1)
					{
						flag = 1;
						cout << "error" << endl;
						break;
					}
					op.pop();//计算一次后弹出一次'#'
				}
				if (flag)
				{
					break;
				}
				op.pop();//弹出第一个遇到的左括号
				//找到右括号时也有可能下一个要补一个运算符号'#'
				//1、下一个是'('  "((D(EF))((GH)I))"中间的")("
				//2、下一个是矩阵
				if (i != s.length() - 1)
				{
					if (isalpha(s[i + 1]) || s[i + 1] == '(')
					{
						op.push('#');
					}
				}
			}
		}
		if (flag)
		{
			continue;
		}
		cout << ans << endl;
	}
	return 0;
}