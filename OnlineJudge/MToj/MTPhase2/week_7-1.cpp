#include <iostream>
#include <set>
#include <cstdlib>
using namespace std;

const int N = 1e5 + 7;
int arr[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        st.insert(arr[i]);
        int j = i + 1;
        while (j < n && st.size() <= 2)
        {
            st.insert(arr[j]);
            if (st.size() > 2)
            {
                break;
            }
            j++;
        }
        ans = max(ans, j - i);
    }
    cout << ans;
    return 0;
}


//以下全部理解错题意，想太复杂了

// #include <iostream>
// #include <vector>
// using namespace std;

// const int N = 1e5 + 7;

// struct Ctn
// {
//     int start, left, right, len;
//     bool upper;
//     bool operator>(const Ctn &c) const
//     {
//         return this->len > c.len;
//     }
// };

// vector<Ctn> v;
// int arr[N];
// int ans = 1;

// void merge(vector<Ctn> v)
// {
//     vector<Ctn> temp;
//     int flag = true;
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = i + 1; j < v.size(); j++)
//         {
//             if (v[i].right == v[j].left - 1)
//             {
//                 if (v[i].upper)
//                 {
//                     if (v[j].upper)
//                     {
//                         if (v[j].start == v[i].start)
//                         {
//                             Ctn c = {v[i].start, v[i].left, v[j].right, v[i].len + v[j].len, v[i].upper};
//                             temp.push_back(c);
//                             flag = false;
//                             ans = max(ans, v[i].len + v[j].len);
//                         }
//                     }
//                     else
//                     {
//                         // 可以插上面或下面
//                         if (v[j].start == v[i].start + 1)
//                         {
//                             Ctn c = {v[i].start, v[i].left, v[j].right, v[i].len + v[j].len, v[i].upper};
//                             temp.push_back(c);
//                             flag = false;
//                             ans = max(ans, v[i].len + v[j].len);
//                         }
//                         if (v[j].start == v[i].start)
//                         {
//                             Ctn c = {v[i].start, v[i].left, v[j].right, v[i].len + v[j].len, v[j].upper};
//                             temp.push_back(c);
//                             flag = false;
//                             ans = max(ans, v[i].len + v[j].len);
//                         }
//                     }
//                 }
//                 else
//                 {
//                     if (v[j].upper)
//                     {
//                         if (v[j].start == v[i].start)
//                         {
//                             Ctn c = {v[i].start, v[i].left, v[j].right, v[i].len + v[j].len, v[j].upper};
//                             temp.push_back(c);
//                             flag = false;
//                             ans = max(ans, v[i].len + v[j].len);
//                         }
//                     }
//                     else
//                     {
//                         if (v[j].start == v[i].start + 1)
//                         {
//                             Ctn c = {v[i].start, v[i].left, v[j].right, v[i].len + v[j].len, true};
//                             temp.push_back(c);
//                             flag = false;
//                             ans = max(ans, v[i].len + v[j].len);
//                         }
//                         if (v[j].start == v[i].start)
//                         {
//                             Ctn c = {v[i].start, v[i].left, v[j].right, v[i].len + v[j].len, false};
//                             temp.push_back(c);
//                             flag = false;
//                             ans = max(ans, v[i].len + v[j].len);
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     if (flag)
//     {
//         return;
//     }
//     merge(temp);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         int len = 1;
//         int j = i + 1;
//         while (j < n && (arr[j] - arr[i] == 1 || arr[i] == arr[j]))
//         {
//             len++;
//             j++;
//         }
//         bool upper = true;
//         if (arr[j] == arr[i])
//         {
//             upper = false;
//         }
//         Ctn c = {arr[i], i, j - 1, len, upper};
//         v.push_back(c);
//         ans = max(ans, len);
//     }
//     merge(v);
//     cout << ans;
//     return 0;
// }