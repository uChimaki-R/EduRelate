// //喝果汁问题
// #include<iostream>
// using namespace std;
// int main()
// {
//     int m = 0;
//     cin >> m;
//     int i = 0;
//     float cost = 0;
//     int rest = m;
//     int j = 0;
//     if (m >= 20)
//     {
//         while ((m - 13*(i+1)) >= 7)
//         {
//             rest = rest - 20;
//             i++;
//         }
//         while (rest >= 3)
//         {
//             rest = rest - 3;
//             j++;
//         }
//     }
//     else if (m < 20 && m >= 3)
//     {
//         while ((rest - 2*(j+1)) >= 1)
//         {
//             rest = rest - 3;
//             j++;
//         }
//     }
//     cost = i * 13 * 1.4 + j * 2 * 1.4 + rest;
//     printf("%.2f", cost);
//     return 0;
// }

//选做
//条件分支结构第一题
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float x, y;
    cin >> x >> y;
    if (x * y >= 0)
    {
        cout << "Arithmetic mean:> " << (x + y) / 2.0 << endl
             << "Geometric mean:> " << sqrt(x * y);
    }
    return 0;
}