#include<iostream>
using namespace std;
#define MOD 2333

const int N = 3010;
int map[N][N], f[N][N];
int n, m;

bool check(int x, int y)
{
	return (x >= 1) && (x <= n) && (y >= 1) && (y <= m);
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}
	f[n][1] = 1;
	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= m; j++)
		{
			if (check(i + 1, j) && !map[i + 1][j])
			{
				f[i][j] += f[i + 1][j];
				f[i][j] %= MOD;
			}
			if (check(i, j - 1) && !map[i][j - 1])
			{
				f[i][j] += f[i][j - 1];
				f[i][j] %= MOD;
			}
		}
	}
	cout << f[1][m];
	return 0;
}