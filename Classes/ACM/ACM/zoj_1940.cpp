#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

const int N = 40;

struct Node
{
    int l, r, c, t;
};

int L, R, C, sl, sr, sc, el, er, ec, ans, flag;
char maze[N][N][N];
int dir[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
bool vis[N][N][N];

bool check(int l, int r, int c)
{
    return (l >= 1) && (l <= L) && (r >= 1) && (r <= R) && (c >= 1) && (c <= C);
}

void bfs(int l, int r, int c)
{
    queue<Node> qu;
    qu.push({l, r, c, 0});
    while (!qu.empty())
    {
        Node top = qu.front();
        qu.pop();
        if (top.l == el && top.r == er && top.c == ec)
        {
            flag = 1;
            ans = top.t;
            return;
        }
        for (int i = 0; i < 6; i++)
        {
            int tl = top.l + dir[i][0];
            int tr = top.r + dir[i][1];
            int tc = top.c + dir[i][2];
            if (check(tl, tr, tc) && !vis[tl][tr][tc] && maze[tl][tr][tc] != '#')
            {
                vis[tl][tr][tc] = true;
                qu.push({tl, tr, tc, top.t + 1});
            }
        }
    }
}

int main()
{
    while (1)
    {
        ans = 0;
        flag = 0;
        memset(vis, false, sizeof(vis));
        cin >> L >> R >> C;
        if (L + R + C == 0)
        {
            break;
        }
        for (int i = 1; i <= L; i++)
        {
            for (int j = 1; j <= R; j++)
            {
                for (int k = 1; k <= C; k++)
                {
                    cin >> maze[i][j][k];
                    if (maze[i][j][k] == 'S')
                    {
                        sl = i;
                        sr = j;
                        sc = k;
                    }
                    else if (maze[i][j][k] == 'E')
                    {
                        el = i;
                        er = j;
                        ec = k;
                    }
                }
            }
        }
        bfs(sl, sr, sc);
        if (flag)
        {
            cout << "Escaped in " << ans << " minute(s)." << endl;
        }
        else
        {
            cout << "Trapped!" << endl;
        }
    }
    return 0;
}