#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

// 前一半较小的数使用降序排序，最大的数（靠近中间的数）在栈顶
priority_queue<int, vector<int>, less<int>> q_front;
// 后一半较大的数使用升序排序，最小的数（靠近中间的数）在栈顶
priority_queue<int, vector<int>, greater<int>> q_back;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            int num;
            cin >> num;
            if (q_front.size() > q_back.size())
            {
                q_front.push(num);
                // 插入后q_front就多了两个数字，把较大的转移到后面
                q_back.push(q_front.top());
                q_front.pop();
            }
            else
            {
                q_front.push(num);
                // 这里要判断后面的是否为空，否则为空时也会执行弹出语句
                if (q_back.size() != 0 && q_front.top() > q_back.top())
                {
                    // 插入后中间的数错了，交换一下
                    q_back.push(q_front.top());
                    q_front.pop();
                    q_front.push(q_back.top());
                    q_back.pop();
                }
            }
        }
        else
        {
            if (q_front.size() == q_back.size())
            {
                // 偶数个
                cout << (q_front.top() + q_back.top()) / 2.0 << endl;
            }
            else
            {
                // 奇数个
                cout << q_front.top() << endl;
            }
        }
    }
    return 0;
}


// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// vector<double> vll;
// vector<double> out;

// int main()
// {
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         char c;
//         cin >> c;
//         if (c == '+')
//         {
//             int num;
//             cin >> num;
//             vll.push_back(num);
//         }
//         else if (c == '?')
//         {
//             int mid = vll.size() / 2;
//             if (vll.size() % 2 == 0)
//             {
//                 // 偶数个
//                 out.push_back((vll[mid - 1] + vll[mid]) / 2.0);
//             }
//             else
//             {
//                 // 奇数个
//                 out.push_back(vll[mid]);
//             }
//         }
//         sort(vll.begin(), vll.end());
//     }
//     for (vector<double>::iterator it = out.begin(); it != out.end(); it++)
//     {
//         cout << *it << endl;
//     }
//     return 0;
// }