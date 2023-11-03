#include<iostream>
#include<string.h>
using namespace std;
#define INF 0x3f3f3f3f

const int N = 80;
int a[N][N], f[N][N][N];
int n, m, mod;

int main()
{
	cin >> n >> m >> mod;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	memset(f, -INF, sizeof(f));
	f[0][0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j == 1)
			{
				for (int k = 0; k <= m / 2; k++)
				{
					for (int l = 0; l < mod; l++)
					{
						f[i][0][l] = max(f[i][0][l], f[i - 1][k][l]);
					}
				}
			}
			for (int k = m / 2 - 1; k >= 0; k--)
			{
				for (int l = 0; l < mod; l++)
				{
					f[i][k + 1][(l + a[i][j]) % mod] = max(f[i][k + 1][(l + a[i][j]) % mod], f[i][k][l] + a[i][j]);
				}
			}
		}
	}
	int ans = 0;
	for (int j = 0; j <= m / 2; j++)
	{
		ans = max(ans, f[n][j][0]);
	}
	cout << ans;
	return 0;
}