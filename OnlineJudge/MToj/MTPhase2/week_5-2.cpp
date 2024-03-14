#include <iostream>
#include <algorithm>
using namespace std;

int n, b, ans = 0;
struct Sct
{
    int s, e, n;
} scts[10005];

// 根据e升序，可以让每个范围的前部分尽量重合
bool mycmp(const Sct &s1, const Sct &s2)
{
    return s1.e < s2.e;
}

bool is_build[100005];

int main()
{
    cin >> n >> b;
    for (int i = 0; i < b; i++)
    {
        cin >> scts[i].s >> scts[i].e >> scts[i].n;
    }
    sort(scts, scts + b, mycmp);
    for (int i = 0; i < b; i++)
    {
        int cnt = 0; // 统计这个建筑接受范围里的设施数量
        for (int j = scts[i].s; j <= scts[i].e; j++)
        {
            if (is_build[j])
            {
                cnt++;
            }
        }
        if (cnt >= scts[i].n)
        {
            // 设施已经足够
            continue;
        }
        for (int j = scts[i].e; j >= scts[i].s; j--)
        {
            //每次从末尾开始放设施
            if (!is_build[j])
            {
                cnt++;
                ans++;
                is_build[j] = true;
            }
            if (cnt == scts[i].n)
            {
                break;
            }
        }
    }
    cout << ans;
    return 0;
}