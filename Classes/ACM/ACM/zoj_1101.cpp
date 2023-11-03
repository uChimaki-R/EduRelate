#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

long long arr[1005];

bool cmp(const long long &v1, const long long &v2)
{
    return v1 > v2;
}

int main()
{
    int cnt;
restart:
    cin >> cnt;
    if (!cnt)
    {
        return 0;
    }
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < cnt; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + cnt, cmp);
    for (int k = 0; k < cnt; k++)
    {
        // arr[k]是这次的目标和
        // i、j选择两个数
        for (int i = 0; i < cnt; i++)
        {
            if (i == k)
            {
                continue;
            }
            for (int j = 0; j < cnt; j++)
            {
                if (j == i || j == k)
                {
                    // 不能选同一个数
                    // 不能选arr[k]
                    continue;
                }
                long long target = (arr[k] - arr[i] - arr[j]);
                // 使用二分找第三个数
                int l = 0;
                int r = cnt - 1;
                while (l <= r)
                {
                    int mid = l + (r - l) / 2;
                    if (arr[mid] == target)
                    {
                        if (mid == i || mid == j || mid == k)
                        {
                            break;
                        }
                        cout << arr[k] << endl;
                        goto restart;
                    }
                    else if (arr[mid] < target)
                    {
                        // 数字找大了，去后部分继续找
                        r = mid - 1;
                    }
                    else
                    {
                        // 数字找小了，去前部分继续找
                        l = mid + 1;
                    }
                }
            }
        }
    }
    cout << "no solution" << endl;
    goto restart;
}