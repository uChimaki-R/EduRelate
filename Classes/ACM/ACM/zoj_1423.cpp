#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

const int N = 300;
stack<char> st;
int cp[N];
bool toout[N];

bool check(string &s, int pos, int cnt)
{
	if (pos + 1 < s.length() && s[pos + 1] == '(')
	{
		// 左括号后面还有左括号，借用后面的左括号来判断这个左括号是否要删除，并把判断结果传递回来（会把这一段所有左括号都更新和最左的括号一样，不过没影响）
		// 因为主函数循环里后面还会对下一个左括号进行判断
		if (!check(s, pos + 1, cnt + 1)) // cnt+1可以得到要判断的运算符的位置（跳过后面的对应的右括号数），类似 -(((a))-(b)) 这种中间只有一个数的情况
		{
			toout[pos] = false;
			return false;
		}
		return true;
	}
	else if (pos + 2 < s.length() && (s[pos + 2] == '+' || s[pos + 2] == '-'))
	{
		// 下下个是运算符，前面又是减号，这个左括号不能删，对应类似 -((b-(c))) 这种左右对应括号里还有运算符的情况
		toout[pos] = false;
		return false;
	}
	else if (pos + cnt < s.length() && (s[pos + cnt] == '+' || s[pos + cnt] == '-'))
	{
		// 对应类似 -(((a))-(b)) 这种左右对应括号中间只有一个字母的情况
		toout[pos] = false;
		return false;
	}
	else
	{
		toout[pos] = true;
		return true;
	}
}

int main()
{
	int n;
	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++)
	{
		while (!st.empty())
		{
			st.pop();
		}
		memset(toout, true, sizeof(toout));
		string s;
		memset(cp, s.length(), sizeof(cp));
		getline(cin, s);
		int pos = s.find(' ');
		// 删去空格
		while (pos != s.npos)
		{
			s.erase(pos, 1);
			pos = s.find(' ', pos);
		}
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '(')
			{
				st.push(j);
				if (j - 1 >= 0 && s[j - 1] == '-')
				{
					check(s, j, 2);
				}
				else
				{
					// 连续的左括号会和最左括号一致，如果没进上面的if要改回要删除
					toout[j] = true;
				}
			}
			else if (s[j] == ')')
			{
				// 左右括号匹配
				cp[j] = st.top();
				cp[st.top()] = j;
				st.pop();
			}
		}
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '(')
			{
				// 匹配的括号的是否删去要对应
				toout[cp[j]] = toout[j];
			}
		}
		string ans = "";
		for (int j = 0; j < s.length(); j++)
		{
			if (isalpha(s[j]) || s[j] == '+' || s[j] == '-')
			{
				// 运算符号和字母不变
				ans += s[j];
			}
			else if (!toout[j])
			{
				// 括号要保留的才添加
				ans += s[j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}

// debug时两类错误尝试示例

// 1
// a + (b - c) - (((a)) - (b))
// a+(b-c)-a-b
// 修改了多个左括号要先判最右边那个，用递归尝试

// 1
// a-((b-(c)))
// a-b-c
// 上面那个修改的副作用，除了用 +cnt判断有无符号 外，原来的 +2判断有无符号 不能删去