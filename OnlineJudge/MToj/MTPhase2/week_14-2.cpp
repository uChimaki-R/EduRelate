#include<iostream>
using namespace std;

#define int long long
const int N = 150;

int xy(int a, int b)
{
	int c = a % b;
	if (c)
	{
		return xy(b, c);
	}
	return b;
}

int f[N][N];

signed main()
{
	int n;
	cin >> n;
	f[1][1] = f[1][2] = f[1][3] = f[1][4] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= 4 * n; j++)
		{
			for (int k = 1; k <= 4; k++)
			{
				if (j > k)
				{
					f[i][j] += f[i - 1][j - k];
				}
			}
		}
	}
	int sum1 = 0, sum2 = 0;
	for (int i = n; i < 2 * n; i++)
	{
		sum1 += f[n][i];
	}
	for (int i = 3 * n + 1; i <= 4 * n; i++)
	{
		sum2 += f[n][i];
	}
	int fm = 1;
	for (int i = 1; i <= n; i++)
	{
		fm *= 4;
	}
	int val1 = xy(sum1, fm);
	cout << sum1 / val1 << "/" << fm / val1 << endl;
	int val2 = xy(sum2, fm);
	cout << sum2 / val2 << "/" << fm / val2;
	return 0;
}