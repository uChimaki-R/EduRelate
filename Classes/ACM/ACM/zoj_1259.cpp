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
				cin >> arr[i];//Ŀ��˳��
			}
			for (int i = 1; i <= len; i++)
			{
				qu.push(i);//����̶�˳��
			}
			int pos = 0;//��ǰ�жϵ����λ��
			while (1)
			{
				if (pos == len)
				{
					//ȫ����ȥ���н�
					flag = true;
					break;
				}
				if (qu.empty() && !st.empty() && st.top() != arr[pos])
				{
					//ȫ����ջ��ջû�������޽�
					break;
				}
				if (!qu.empty())
				{
					if (qu.front() == arr[pos])
					{
						//Ҫ��ջ�ĸպ���Ҫ��ջ�ģ�ֱ�ӳ�
						qu.pop();
						pos++;
					}
					else if (!st.empty() && st.top() == arr[pos])
					{
						//��ջǰ����ջ���ܲ����ȳ����ܾ��ȳ�
						st.pop();
						pos++;
					}
					else
					{
						//ջû������ֱ��ѹջ
						st.push(qu.front());
						qu.pop();
					}
				}
				//�������ֲ��ж����������Ҳ���ԣ�������else if������
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
			//����
			memset(arr, 0, sizeof(arr));
			flag = false;
			while (!st.empty())
			{
				//ջ���޽�ʱ���������ݣ�Ҫ���
				st.pop();
			}
			cin >> arr[0];
		}
		cout << endl;//��ӡ��ʽҪ��
		cin >> len;
	}
	return 0;
}



//���³�ʱ

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