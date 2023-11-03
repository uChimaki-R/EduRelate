#include<iostream>
#include<string.h>
using namespace std;

const int N = 30;

char map[N][N];
int vis[N][N];
int n, m, sx, sy, ans;
int dir[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };

bool legal(int x, int y)
{
	return (x >= 1) && (x <= m) && (y >= 1) && (y <= n);
}

void dfs(int x, int y)
{
	ans++;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (legal(tx, ty) && !vis[tx][ty] && map[tx][ty] == '.')
		{
			dfs(tx, ty);
		}
	}
}

int main()
{
	while (cin >> n >> m)
	{
		if (n + m == 0)
		{
			break;
		}
		memset(vis, false, sizeof(vis));
		ans = 0;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '@')
				{
					sx = i;
					sy = j;
				}
			}
		}
		dfs(sx, sy);
		cout << ans << endl;
	}
	return 0;
}