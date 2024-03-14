#include<iostream>
using namespace std;

const int N = 100010;

struct Node
{
	int pre, next, flag;
}link[N];

int main()
{
	int n, m;
	cin >> n;
	link[1].pre = 0;
	link[1].next = 0;
	for (int i = 2; i <= n; i++)
	{
		int pos, side;
		cin >> pos >> side;
		if (!side)
		{
			link[i].pre = link[pos].pre;
			link[pos].pre = i;
			link[i].next = pos;
			link[link[i].pre].next = i;
		}
		else
		{
			link[i].next = link[pos].next;
			link[pos].next = i;
			link[i].pre = pos;
			link[link[i].next].pre = i;
		}
	}
	cin >> m;
	while (m--)
	{
		int i;
		cin >> i;
		if (!link[i].flag)
		{
			link[link[i].pre].next = link[i].next;
			link[link[i].next].pre = link[i].pre;
			link[i].flag = 1;
		}
	}
	int flag = 0;
	int pos = link[0].next;
	while (pos)
	{
		if (flag)
		{
			cout << " ";
		}
		cout << pos;
		pos = link[pos].next;
		flag = 1;
	}
	return 0;
}