#include <iostream>
#include <queue>
using namespace std;

int n, t, ans = 0;
struct Tree
{
    int fruits;
    int sub;
    bool operator<(const Tree &_tree) const
    {
        if (fruits == _tree.fruits)
        {
            return sub > _tree.sub;
        }
        return fruits < _tree.fruits;
    }
} trees[30];

int times[30];
priority_queue<Tree> qu; // 大顶堆让每次能摘的最大果数在顶

int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i].fruits;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i].sub;
    }
    for (int i = 1; i < n; i++)
    {
        cin >> times[i];
        times[i] += times[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        // 枚举走到的最右边的树，可以去点后续对行走times的考虑，只考虑摘水果的times
        int _t = t - times[i];
        // 清空大顶堆
        while (!qu.empty())
        {
            qu.pop();
        }
        // 初始化大顶堆
        for (int j = 0; j <= i; j++)
        {
            qu.push(trees[j]);
        }
        int tans = 0;
        for (int j = 0; j < _t; j++)
        {
            // 只能有_t次操作
            Tree mtree = qu.top();
            qu.pop();
            if (mtree.fruits > 0)
            {
                tans += mtree.fruits;
            }
            mtree.fruits -= mtree.sub;
            qu.push(mtree);
        }
        ans = max(ans, tans);
    }
    cout << ans;
    return 0;
}