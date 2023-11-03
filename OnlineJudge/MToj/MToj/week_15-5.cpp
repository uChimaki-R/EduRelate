#include<iostream>
#include<string.h>
using namespace std;
#define INF 0x3f3f3f3f

int n, ans, cnt;
char a[7][7], b[7][7];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

bool check(int x, int y)
{
	return x > 0 && x < 6 && y>0 && y < 6;
}

void turn(int x, int y)
{
	b[x][y] ^= 1;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (check(tx, ty))
		{
			b[tx][ty] ^= 1;
		}
	}
	cnt++;
}

int main()
{
	cin >> n;
	while (n--)
	{
		ans = INF;
		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j <= 5; j++)
			{
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < 32; i++)
		{
			cnt = 0;
			memcpy(b, a, sizeof(a));
			for (int j = 1; j <= 5; j++)
			{
				if (i & (1 << (j - 1)))
				{
					turn(1, j);
				}
			}
			for (int j = 2; j <= 5; j++)
			{
				for (int k = 1; k <= 5; k++)
				{
					if (b[j - 1][k] == '0')
					{
						turn(j, k);
					}
				}
			}
			bool flag = true;
			for (int j = 1; j <= 5; j++)
			{
				if (b[5][j] == '0')
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				ans = min(ans, cnt);
			}
		}
		if (ans > 6)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << ans << endl;
		}
	}
	return 0;
}