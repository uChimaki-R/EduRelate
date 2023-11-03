#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

const int N = 210;

struct Node
{
    int x, y, step;
    bool operator>(const Node &no) const
    {
        return step > no.step;
    }
};

char map[N][N];
bool vis[N][N];
int n, m, sx, sy, flag, ex, ey, ans;
int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

bool legal(int x, int y)
{
    return (x >= 1) && (x <= n) && (y >= 1) && (y <= m);
}

void bfs(int x, int y)
{
    priority_queue<Node, vector<Node>, greater<Node>> qu; // 因为遇到x等价于走两步，不能确保队列是小顶堆，所以要用堆来实现
    qu.push({x, y, 0});
    while (!qu.empty())
    {
        Node top = qu.top();
        qu.pop();
        if (top.x == ex && top.y == ey)
        {
            flag = 1;
            ans = top.step;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = top.x + dir[i][0];
            int ty = top.y + dir[i][1];
            if (legal(tx, ty) && map[tx][ty] != '#' && !vis[tx][ty])
            {
                vis[tx][ty] = true;
                int s = top.step + 1;
                if (map[tx][ty] == 'x')
                {
                    qu.push({tx, ty, s + 1});
                }
                else
                {
                    qu.push({tx, ty, s});
                }
            }
        }
    }
}

int main()
{
    while (cin >> n >> m)
    {
        flag = 0;
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 'r')
                {
                    sx = i;
                    sy = j;
                }
                if (map[i][j] == 'a')
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        bfs(sx, sy);
        if (flag)
        {
            cout << ans << endl;
        }
        else
        {
            cout << "Poor ANGEL has to stay in the prison all his life." << endl;
        }
    }
    return 0;
}