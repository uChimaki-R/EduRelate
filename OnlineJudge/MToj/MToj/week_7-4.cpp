#include <iostream>
#include <cstdio>
using namespace std;

const int N = 5e6 + 5;
int st[N];

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int opr;
        scanf("%d", &opr);
        switch (opr)
        {
        case 1:
            int val;
            scanf("%d", &val);
            st[++*st] = val;
            break;
        case 2:
            printf("%d\n", st[*st]);
            break;
        case 3:
            int pos;
            scanf("%d", &pos);
            printf("%d\n", st[pos + 1]);
            break;
        case 4:
            --*st;
            break;
        }
    }
    return 0;
}

// #include <iostream>
// #include <stack>
// using namespace std;

// stack<int> st;

// int main()
// {
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         int opr;
//         cin >> opr;
//         if (opr == 1)
//         {
//             int val;
//             cin >> val;
//             st.push(val);
//         }
//         else if (opr == 2)
//         {
//             cout << st.top() << endl;
//         }
//         else if (opr == 3)
//         {
//             int pos;
//             cin >> pos;
//             stack<int> temp(st);
//             while (pos--)
//             {
//                 temp.pop();
//             }
//             cout << temp.top() << endl;
//         }
//         else
//         {
//             st.pop();
//         }
//     }
//     return 0;
// }

// // #include <iostream>
// // #include <vector>
// // using namespace std;

// // int main()
// // {
// //     vector<int> v;
// //     int n;
// //     cin >> n;
// //     while (n--)
// //     {
// //         int opr;
// //         cin >> opr;
// //         if (opr == 1)
// //         {
// //             int val;
// //             cin >> val;
// //             v.insert(v.begin(), val);
// //         }
// //         else if (opr == 2)
// //         {
// //             cout << v[0] << endl;
// //         }
// //         else if (opr == 3)
// //         {
// //             int pos;
// //             cin >> pos;
// //             cout << v[pos] << endl;
// //         }
// //         else
// //         {
// //             v.erase(v.begin());
// //         }
// //     }
// //     return 0;
// // }