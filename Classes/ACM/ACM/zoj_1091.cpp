#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

const int N = 10;

struct Node
{
    int x, y, cnt;
};

bool vis[N][N];
int dir[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

bool legal(int x, int y)
{
    return (x >= 1) && (x <= 8) && (y >= 1) && (y <= 8);
}

int main()
{
    string p1, p2;
    while (cin >> p1 >> p2)
    {
        int sx = p1[1] - '0';
        int sy = p1[0] - 'a' + 1;
        int ex = p2[1] - '0';
        int ey = p2[0] - 'a' + 1;
        queue<Node> qu;
        qu.push({sx, sy, 0});
        memset(vis, false, sizeof(vis));
        while (!qu.empty())
        {
            Node top = qu.front();
            qu.pop();
            if (top.x == ex && top.y == ey)
            {
                cout << "To get from " << p1 << " to " << p2 << " takes " << top.cnt << " knight moves." << endl;
                break;
            }
            for (int i = 0; i < 8; i++)
            {
                int tx = top.x + dir[i][0];
                int ty = top.y + dir[i][1];
                if (legal(tx, ty) && !vis[tx][ty])
                {
                    vis[tx][ty] = true;
                    qu.push({tx, ty, top.cnt + 1});
                }
            }
        }
    }
    return 0;
}