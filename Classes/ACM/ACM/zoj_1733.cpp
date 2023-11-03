#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

const int N = 1001;
char x[N], y[N];
int f[N][N];

int Count(int n, int m)
{
    if (f[n][m] >= 0)
    {
        return f[n][m];
    }
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (x[n - 1] == y[m - 1])
    {
        f[n - 1][m - 1] = Count(n - 1, m - 1);
        return f[n][m] = f[n - 1][m - 1] + 1;
    }
    f[n - 1][m] = Count(n - 1, m);
    f[n][m - 1] = Count(n, m - 1);
    return f[n][m] = max(f[n - 1][m], f[n][m - 1]);
}

int main()
{
    int lx, ly;
    while (scanf("%s%s", x, y) != EOF)
    {
        memset(f, -1, sizeof(f));
        lx = strlen(x);
        ly = strlen(y);
        printf("%d\n", Count(lx, ly));
        memset(x, '\0', sizeof(x));
        memset(y, '\0', sizeof(y));
    }
    return 0;
}

// #include <iostream>
// #include <string.h>
// using namespace std;

// const int N = 1010;
// int f[N][N];
// string s1, s2;

// int main()
// {
//     while (cin >> s1 >> s2)
//     {
//         memset(f, 0, sizeof(f));
//         for (int i = 1; i <= s1.length(); i++)
//         {
//             for (int j = 1; j <= s2.length(); j++)
//             {
//                 if (s1[i - 1] == s2[j - 1])
//                 {
//                     f[i][j] = f[i - 1][j - 1] + 1;
//                 }
//                 else
//                 {
//                     f[i][j] = max(f[i - 1][j], f[i][j - 1]);
//                 }
//             }
//         }
//         cout << f[s1.length()][s2.length()] << endl;
//     }
//     return 0;
// }