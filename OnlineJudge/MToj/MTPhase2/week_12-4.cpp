#include<iostream>
using namespace std;

const int N = 1000010;

struct Node
{
	int left, right, flag;
}nodes[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		nodes[i].left = i;
		nodes[i].right = i;
	}
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		nodes[nodes[x].right].left = nodes[y].left;
		nodes[nodes[y].left].right = nodes[x].right;
		nodes[x].right = y;
		nodes[y].left = x;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!nodes[i].flag)
		{
			cout << i;
			nodes[i].flag = 1;
			int temp = nodes[i].right;
			while (!nodes[temp].flag)
			{
				cout << " " << temp;
				nodes[temp].flag = 1;
				temp = nodes[temp].right;
			}
			cout << endl;
		}
	}
	return 0;
}