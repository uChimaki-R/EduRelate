#include <iostream>
#include <vector>
using namespace std;

int s, n, k;

void func(int n, int k, int now, vector<int> &v)
{
    if (k == 1)
    {
        v.push_back(n);
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        v.pop_back();
        cout << endl;
        s++;
    }
    else
    {
        for (int i = now; i <= n / k; i++)
        {
            v.push_back(i);
            func(n - i, k - 1, i, v);
            v.pop_back();
        }
    }
}

int main()
{
    cin >> n >> k;
    vector<int> v;
    func(n, k, 1, v);
    cout << s;
    return 0;
}

// 以下动规写法

// #include <iostream>
// using namespace std;

// const int N = 210;
// int f[N][7];

// int main()
// {
//     f[0][0] = 1;
//     for (int i = 1; i < N; i++)
//     {
//         for (int j = 1; j < 7; j++)
//         {
//             if (i >= j)
//             {
//                 f[i][j] = f[i - 1][j - 1] + f[i - j][j];
//             }
//         }
//     }
//     cout << f[7][3];
//     return 0;
// }