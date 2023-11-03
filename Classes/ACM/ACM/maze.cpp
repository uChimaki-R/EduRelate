#include<iostream>
#include<string.h>
using namespace std;

const int N = 500;

int n, m, tx, ty, flag;
int maze[N][N];
bool vis[N][N];
int dir[8][2] = { {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };

void dfs(int x, int y)
{
	if (flag)
	{
		return;
	}
	if (x == tx && y == ty)
	{
		flag = 1;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		int px = x + dir[i][0];
		int py = y + dir[i][1];
		if (maze[px][py] == 0 && !vis[px][py])
		{
			vis[px][py] = true;
			dfs(px, py);
		}
	}
}

int main()
{
	while (1)
	{
		cin >> n >> m;
		if (!(n + m))
		{
			break;
		}
		memset(vis, false, sizeof(vis));
		memset(maze, 1, sizeof(maze));
		flag = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> maze[i][j];
			}
		}
		int sx, sy;
		cin >> sx >> sy >> tx >> ty;
		dfs(sx, sy);
		if (flag)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}



////bfsËã·¨£º
//#include<iostream>
//#include<queue>
//#include<string.h>
//using namespace std;
//
//const int N = 510;
//
//struct Node
//{
//	int x, y;
//};
//
//int maze[N][N], dir[8][2] = { {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1} };
//bool vis[N][N];
//int flag, ex, ey;
//
//void bfs(int x, int y)
//{
//	queue<Node> qu;
//	qu.push({ x, y });
//	while (!qu.empty())
//	{
//		Node top = qu.front();
//		qu.pop();
//		if (top.x == ex && top.y == ey)
//		{
//			flag = 1;
//		}
//		for (int i = 0; i < 8; i++)
//		{
//			int tx = top.x + dir[i][0];
//			int ty = top.y + dir[i][1];
//			if (maze[tx][ty] == 0 && !vis[tx][ty])
//			{
//				qu.push({ tx, ty });
//				vis[tx][ty] = true;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int n, m;
//	while (1)
//	{
//		cin >> n >> m;
//		if (!(n + m))
//		{
//			break;
//		}
//		memset(maze, 1, sizeof(maze));
//		memset(vis, false, sizeof(vis));
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				cin >> maze[i][j];
//			}
//		}
//		flag = 0;
//		int sx, sy;
//		cin >> sx >> sy >> ex >> ey;
//		bfs(sx, sy);
//		if (flag)
//		{
//			cout << "Yes" << endl;
//		}
//		else
//		{
//			cout << "No" << endl;
//		}
//	}
//	return 0;
//}