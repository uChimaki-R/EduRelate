#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

const int N = 1001;
char str[N];
int f[N][N];

int cost(int start, int end)
{
    if (f[start][end] >= 0)
    {
        return f[start][end];
    }
    int x, y;
    if (start >= end)
    {
        return 0;
    }
    if (str[start] == str[end])
    {
        return f[start][end] = cost(start + 1, end - 1);
    }
    x = cost(start + 1, end);
    y = cost(start, end - 1);
    return f[start][end] = min(x, y) + 1;
}

int main()
{
    while (scanf("%s", str) != EOF)
    {
        int len = strlen(str);
        cout << cost(0, len - 1) << endl;
        memset(str, '\0', sizeof(str));
        memset(f, -1, sizeof(f));
    }
    return 0;
}