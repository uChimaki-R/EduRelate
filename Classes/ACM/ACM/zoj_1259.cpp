#include<iostream>
#include<stack>
#include<queue>
#include<string.h>
using namespace std;

stack<int>st;
queue<int>qu;
int arr[100010];

int main()
{
	int len;
	bool flag = false;
	cin >> len;
	while (len)
	{
		cin >> arr[0];
		while (arr[0])
		{
			for (int i = 1; i < len; i++)
			{
				cin >> arr[i];//目标顺序
			}
			for (int i = 1; i <= len; i++)
			{
				qu.push(i);//输入固定顺序
			}
			int pos = 0;//当前判断的输出位置
			while (1)
			{
				if (pos == len)
				{
					//全部出去，有解
					flag = true;
					break;
				}
				if (qu.empty() && !st.empty() && st.top() != arr[pos])
				{
					//全部入栈后，栈没法出，无解
					break;
				}
				if (!qu.empty())
				{
					if (qu.front() == arr[pos])
					{
						//要入栈的刚好是要出栈的，直接出
						qu.pop();
						pos++;
					}
					else if (!st.empty() && st.top() == arr[pos])
					{
						//入栈前看看栈顶能不能先出，能就先出
						st.pop();
						pos++;
					}
					else
					{
						//栈没法出就直接压栈
						st.push(qu.front());
						qu.pop();
					}
				}
				//后来发现不判断这下面这个也可以，在上面else if包含了
				/*
				if (!st.empty())
				{
					if (st.top() == arr[pos])
					{
						st.pop();
						pos++;
					}
				}*/
			}
			if (flag)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
			//重置
			memset(arr, 0, sizeof(arr));
			flag = false;
			while (!st.empty())
			{
				//栈在无解时有留存数据，要清空
				st.pop();
			}
			cin >> arr[0];
		}
		cout << endl;//打印格式要求
		cin >> len;
	}
	return 0;
}



//以下超时

//#include<iostream>
//#include<stack>
//using namespace std;
//
//int len;
//stack<char>st;
//string in, out;
//bool toend;
//
//void dfs(int cnti, int cnto)
//{
//	if (toend)
//	{
//		return;
//	}
//	if (cnti == len && cnto == len)
//	{
//		toend = true;
//		return;
//	}
//	if (in.length())
//	{
//		char temp = in[0];
//		in.erase(0, 1);
//		st.push(temp);
//		dfs(cnti + 1, cnto);
//		st.pop();
//		in.insert(in.begin(), temp);
//	}
//	if (!st.empty() && st.top() == out[cnto])
//	{
//		char temp = st.top();
//		st.pop();
//		dfs(cnti, cnto + 1);
//		st.push(temp);
//	}
//}
//
//int main()
//{
//	cin >> len;
//	while (len)
//	{
//		in = "";
//		while (!st.empty())
//		{
//			st.pop();
//		}
//		for (int i = 1; i <= len; i++)
//		{
//			in += i;
//		}
//		int val;
//		cin >> val;
//		while (val)
//		{
//			out += val;
//			toend = false;
//			for (int i = 0; i < len - 1; i++)
//			{
//				int input;
//				cin >> input;
//				out += input;
//			}
//			dfs(0, 0);
//			if (toend)
//			{
//				cout << "Yes" << endl;
//			}
//			else
//			{
//				cout << "No" << endl;
//			}
//			out = "";
//			cin >> val;
//		}
//		cin >> len;
//	}
//	return 0;
//}