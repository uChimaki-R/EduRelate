#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n, p;
	cin >> n >> p;
	queue<int>qu;
	for (int i = 1; i <= n; i++)
	{
		qu.push(i);
	}
	int cnt = 0;
	while (qu.size() != 1)
	{
		int top = qu.front();
		qu.pop();
		cnt++;
		if (cnt % p)
		{
			qu.push(top);
		}
	}
	cout << qu.front();
	return 0;
}