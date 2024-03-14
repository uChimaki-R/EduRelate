#include<iostream>
#include<stack>
using namespace std;

const int N = 1e6 + 7;

stack<char>st;
stack<int>num;
bool legal[N];
int ans1, ans2;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			st.push(s[i]);
			num.push(i);
		}
		else
		{
			if (!st.empty() && st.top() == '(')
			{
				legal[i] = true;
				legal[num.top()] = true;
				num.pop();
				st.pop();
			}
			else
			{
				st.push(s[i]);
				num.push(i);
			}
		}
	}
	for (int i = 0; i < s.length(); i++)
	{
		int j = i, cnt = 0;
		while (legal[j])
		{
			cnt++;
			j++;
		}
		if (cnt > ans1)
		{
			ans1 = cnt;
			ans2 = 1;
		}
		else if (cnt == ans1)
		{
			ans2++;
		}
		i = j;
	}
	if (ans1)
	{
		cout << ans1 << " " << ans2;
	}
	else
	{
		cout << "0 1";
	}
	return 0;
}