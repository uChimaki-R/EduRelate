#include <iostream>
#include <queue>
using namespace std;

const int N = 20;

typedef long long LL;

struct Color
{
    LL r, g, b;
    LL ans;
    bool operator>(const Color &c) const
    {
        return this->ans > c.ans;
    }
} colors[N];

int main()
{
    for (int i = 0; i < 16; i++)
    {
        cin >> colors[i].r >> colors[i].g >> colors[i].b;
    }
    LL r, g, b;
    cin >> r >> g >> b;
    while (r != -1 && g != -1 && b != -1)
    {
        priority_queue<Color, vector<Color>, greater<Color>> qu;
        for (int i = 0; i < 16; i++)
        {
            colors[i].ans = (r - colors[i].r) * (r - colors[i].r) + (g - colors[i].g) * (g - colors[i].g) + (b - colors[i].b) * (b - colors[i].b);
            qu.push(colors[i]);
        }
        Color c = qu.top();
        cout << "(" << r << "," << g << "," << b << ") maps to (" << c.r << "," << c.g << "," << c.b << ")" << endl;
        cin >> r >> g >> b;
    }
    return 0;
}

// #include<iostream>
// using namespace std;

// long long arr[17][4];

// int main()
// {
//     long long r, g, b;
//     for (int i = 0; i < 16; i++)
//     {
//         cin >> r >> g >> b;
//         arr[i][0] = r;
//         arr[i][1] = g;
//         arr[i][2] = b;
//     }
//     cin >> r >> g >> b;
//     while(r!=-1&&g!=-1&&b!=-1)
//     {
//         long long minf = 0x3f3f3f3f;
//         int pos = -1;
//         for(int i = 0; i < 16; i++)
//         {
//             long long d = (r - arr[i][0]) * (r - arr[i][0]) + (g - arr[i][1]) * (g - arr[i][1]) + (b - arr[i][2]) * (b - arr[i][2]);
//             if(d<minf)
//             {
//                 minf = d;
//                 pos = i;
//             }
//         }
//         cout << "(" << r << "," << g << "," << b << ") maps to (" << arr[pos][0] << "," << arr[pos][1] << "," << arr[pos][2] << ")" << endl;
//         cin >> r >> g >> b;
//     }
//     return 0;
// }