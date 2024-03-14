#include <iostream>
using namespace std;

// 使用差分解决
int score[5000010];
int sub[5000010];

int main()
{
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> score[i];
        sub[i] = score[i] - score[i - 1];
    }
    for (int i = 1; i <= p; i++)
    {
        int start, end, add;
        cin >> start >> end >> add;
        sub[start] += add;
        sub[end + 1] -= add;
    }
    int min_score = 0x3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        score[i] = score[i - 1] + sub[i];
        min_score = min(min_score, score[i]);
    }
    cout << min_score;
    return 0;
}


// #include <iostream>
// using namespace std;

// int score[10000000];

// int main()
// {
//     int n, p;
//     cin >> n >> p;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> score[i];
//     }
//     for (int i = 1; i <= p; i++)
//     {
//         int start, end, add;
//         cin >> start >> end >> add;
//         for (int i = start; i <= end; i++)
//         {
//             score[i] += add;
//         }
//     }
//     int min_score = 10000;
//     for (int i = 1; i <= n; i++)
//     {
//         min_score = min(min_score, score[i]);
//     }
//     cout << min_score;
//     return 0;
// }