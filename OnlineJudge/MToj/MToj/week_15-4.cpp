#include<iostream>
using namespace std;

const int N = 510;
int a[N], f[N][N], n, m, b, mod, ans;

int main()
{
	cin >> n >> m >> b >> mod;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = a[i]; k <= b; k++)
			{
				f[j][k] += f[j - 1][k - a[i]];
				f[j][k] %= mod;
			}
		}
	}
	for (int i = 0; i <= b; i++)
	{
		ans += f[m][i];
		ans %= mod;
	}
	cout << ans;
	return 0;
}