#include <iostream>
#include <queue>
using namespace std;

int f(int a, int b, int c, int x)
{
    return a * x * x + b * x + c;
}

struct Point
{
    int a, b, c, x, y;
    bool operator>(const Point &p) const
    {
        return this->y > p.y;
    }
};

priority_queue<Point, vector<Point>, greater<Point>> qu;

int main()
{
    int n, k;
    cin >> n >> k;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Point p = {a, b, c, 1, f(a, b, c, 1)};
        qu.push(p);
    }
    int ans = 0;
    while (k)
    {
        Point top = qu.top();
        qu.pop();
        k--;
        ans = top.y;
        Point next = {top.a, top.b, top.c, top.x + 1, f(top.a, top.b, top.c, top.x + 1)};
        qu.push(next);
    }
    cout << ans;
    return 0;
}

// 下面两个都理解错题意了

// #include <iostream>
// #include <queue>
// using namespace std;

// priority_queue<int, vector<int>, greater<int>> qu;

// int f(int a, int b, int c, int x)
// {
//     return a * x * x + b * x + c;
// }

// struct ABC
// {
//     int a, b, c;
// } arr[25];

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     int pos = 0;
//     while (n--)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         arr[pos] = {a, b, c};
//         pos++;
//     }
//     int x = 1, ans = 0;
//     while (k)
//     {
//         for (int i = 0; i < pos; i++)
//         {
//             qu.push(f(arr[i].a, arr[i].b, arr[i].c, x));
//         }
//         x++;
//         while (!qu.empty() && k)
//         {
//             if (k == 1 && ans)
//             {
//                 k--;
//                 break;
//             }
//             ans = qu.top();
//             qu.pop();
//             k--;
//         }
//     }
//     cout << ans;
//     return 0;
// }

// // #include <iostream>
// // #include <queue>
// // using namespace std;

// // int f(int a, int b, int c, int x)
// // {
// //     return a * x * x + b * x + c;
// // }

// // int main()
// // {
// //     int n, k;
// //     cin >> n >> k;
// //     priority_queue<int, vector<int>, greater<int>> qu;
// //     while (n--)
// //     {
// //         int a, b, c;
// //         cin >> a >> b >> c;
// //         int mid = -(b / (2 * a));
// //         if (mid < 1)
// //         {
// //             for (int i = 1; i <= k; i++)
// //             {
// //                 qu.push(f(a, b, c, i));
// //             }
// //         }
// //         else
// //         {
// //             qu.push(f(a, b, c, mid));
// //             for (int i = 1; i <= k; i++)
// //             {
// //                 if (mid - i >= 1)
// //                 {
// //                     qu.push(f(a, b, c, mid - i));
// //                 }
// //                 qu.push(f(a, b, c, mid + i));
// //             }
// //         }
// //     }
// //     while (--k)
// //     {
// //         qu.pop();
// //     }
// //     cout << qu.top();
// //     return 0;
// // }