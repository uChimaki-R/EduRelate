#include<iostream>
#include<stack>
using namespace std;

stack<char>st;

void cal()
{
	int num1 = 0, num2 = 0, big = 0;
	while (!st.empty() && st.top() == 'a')
	{
		//ȡ����һ���������Ǹ����ĳ���
		num1++;
		st.pop();
	}
	if (!st.empty() && st.top() == '|')
	{
		//ǰ�滹������Ҫ�ó����Ƚ�
		st.pop();//����'|'
		while (!st.empty() && st.top() == 'a')
		{
			num2++;
			st.pop();
		}
	}
	if (!st.empty())
	{
		//��Ϊ�գ�������
		//'('����������
		//'|'����������
		if (st.top() == '(')
		{
			st.pop();//��Ϊֻ����һ��ջ��Ҫ�ȵ���'('�ٷų��ȣ���Ȼ�ᵯ��'a'��Ȼ����ѭ��
			big = max(num1, num2);
			while (big--)
			{
				st.push('a');
			}
		}
		else
		{
			big = max(num1, num2);
			while (big--)
			{
				st.push('a');
			}
			cal();//��������
		}
	}
	else
	{
		//Ϊ�գ���������һ������
		big = max(num1, num2);
		while (big--)
		{
			st.push('a');
		}
	}
}


int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ')')
		{
			cal();
		}
		else
		{
			st.push(s[i]);
		}
	}
	int ans = 1, cnt = 0;
	//ʣ�µ�ʽ��û�����ţ�ֻ��|��a������ֻ�ñ����ҵ�����Ƕ�a�ĳ��Ⱦ���
	while (!st.empty())
	{
		cnt = 0;
		while (!st.empty() && st.top() == 'a')
		{
			cnt++;
			st.pop();
		}
		ans = max(ans, cnt);
		if (!st.empty() && st.top() == '|')
		{
			st.pop();
		}
	}
	cout << ans;
	return 0;
}

//#include<iostream>
//#include<stack>
//#include<string>
//#include<sstream>
//using namespace std;
//
//stack<int>num;
//stack<char>opr;
//
//void merge()
//{
//	while (num.size() >= 2 && opr.empty())
//	{
//		int num1 = num.top();
//		num.pop();
//		int num2 = num.top();
//		num.pop();
//		num.push(num1 + num2);
//	}
//}
//
//void cal()
//{
//	int num1 = num.top();
//	num.pop();
//	int num2 = num.top();
//	num.pop();
//	opr.pop();
//	num.push(max(num1, num2));
//}
//
//
//int main()
//{
//	string s;
//	getline(cin, s);
//	int pos = s.find('a');
//	while (pos != s.npos)
//	{
//		int cnt = 0;
//		while (pos < s.length() && s[pos] == 'a')
//		{
//			cnt++;
//			pos++;
//		}
//		s.insert(s.begin() + pos - cnt, cnt + '0');
//		s.erase(pos - cnt + 1, cnt);
//		pos = s.find('a', pos - cnt);
//	}
//	//cout << s << endl;
//	stringstream ss;
//	ss << s;
//	while (ss.peek() != EOF)
//	{
//		if (isdigit(ss.peek()))
//		{
//			int val;
//			ss >> val;
//			num.push(val);
//			merge();
//		}
//		else
//		{
//			char op;
//			ss >> op;
//			if (op == ')')
//			{
//				while (opr.top() != '(')
//				{
//					cal();
//				}
//				opr.pop();
//				merge();
//			}
//			else
//			{
//				opr.push(op);
//			}
//		}
//	}
//	int ans = 1;
//	while (!num.empty())
//	{
//		ans = max(ans, num.top());
//		num.pop();
//	}
//	cout << ans;
//	return 0;
//}