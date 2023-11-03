#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define INF 0x3f3f3f3f

const int N = 10;

struct Node
{
    int x, y, val, st;//val:到这个点的花费 st:到这个点后的状态
};

int map[N][N], st[N][N][5];//st记录以特定状态到达x,y点所需的最小花费
int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int sx, sy, ex, ey, ans;

bool legal(int x, int y)
{
    return (x >= 1) && (x <= 8) && (y >= 1) && (y <= 8);
}

void bfs(int x, int y)
{
    queue<Node> qu;
    qu.push({sx, sy, 0, 1});
    while (!qu.empty())
    {
        Node top = qu.front();
        qu.pop();
        if (top.x == ex && top.y == ey)
        {
            ans = min(ans, top.val);
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = top.x + dir[i][0];
            int ty = top.y + dir[i][1];
            int val = top.val + top.st * map[tx][ty];//从top的位置以top.st的状态到达tx,ty需要的花费
            int next = (top.st * map[tx][ty]) % 4 + 1;//到达tx,ty后状态的变化
            if (legal(tx, ty) && st[tx][ty][next] > val)//如果以next到达这个点所需花费比原来的小，就再从这个点bfs一次
            {
                st[tx][ty][next] = val;//更新最小花费
                qu.push({tx, ty, val, next});
            }
        }
    }
}

int main()
{
    while (cin >> sx >> sy >> ex >> ey)
    {
        if (sx + sy + ex + ey == 0)
        {
            break;
        }
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                cin >> map[i][j];
            }
        }
        ans = INF;
        memset(st, INF, sizeof(st));
        bfs(sx, sy);
        cout << ans << endl;
    }
    return 0;
}