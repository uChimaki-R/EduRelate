#include <iostream>
#include <queue>
using namespace std;

typedef long long LL;
priority_queue<LL, vector<LL>, greater<LL>> qu;

//如果多次使用长木板，如把一个长木板和很多小木板一一组合，每次的费用都会很高
//为了减少长的木板的使用次数，每次都取最短的两块板合并（锯板子的逆过程）

int main()
{
    LL n, ans = 0;
    cin >> n;
    while (n--)
    {
        LL val;
        cin >> val;
        qu.push(val);
    }
    while (qu.size() != 1)
    {
        LL v1 = qu.top();
        qu.pop();
        LL v2 = qu.top();
        qu.pop();
        LL v = v1 + v2;
        ans += v;
        qu.push(v);
    }
    cout << ans;
    return 0;
}