#include<iostream>
using namespace std;

int sub[10005];

int main()
{
	int n, h, f;
	cin >> n >> h >> f;
	for (int i = 1; i <= f; i++)
	{
		int x, y;
		cin >> x >> y;
		if (x == y)
		{
			continue;
		}
		if (x < y)
		{
			sub[x + 1] -= 1;
			sub[y] += 1;
		}
		else
		{
			sub[y + 1] -= 1;
			sub[x] += 1;
		}
	}
	cout << 1000 + sub[1] << endl;
	for (int i = 2; i <= n; i++)
	{
		sub[i] += sub[i - 1];
		cout << 1000 + sub[i] << endl;
	}
	return 0;
}