#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int a, b, t;
bool toend;
bool vis[1000][1000];
vector<int> opr;

void print_opr(int val)
{
    if (val == 1)
    {
        cout << "fill A" << endl;
    }
    else if (val == 2)
    {
        cout << "fill B" << endl;
    }
    else if (val == 10)
    {
        cout << "empty A" << endl;
    }
    else if (val == 20)
    {
        cout << "empty B" << endl;
    }
    else if (val == 12)
    {
        cout << "pour A B" << endl;
    }
    else if (val == 21)
    {
        cout << "pour B A" << endl;
    }
}

void dfs(int va, int vb)
{
    if (toend)
    {
        return;
    }
    if (vis[va][vb])
    {
        return;
    }
    vis[va][vb] = true;
    if (va == t || vb == t)
    {
        toend = true;
        for_each(opr.begin(), opr.end(), print_opr);
        cout << "success" << endl;
        return;
    }
    if (va != 0)
    {
        opr.push_back(10);
        dfs(0, vb);
        opr.pop_back();
        opr.push_back(12);
        if ((va + vb) <= b)
        {
            dfs(0, va + vb);
        }
        else
        {
            int differ = (va + vb - b);
            dfs(differ, b);
        }
        opr.pop_back();
    }
    if (vb != 0)
    {
        opr.push_back(20);
        dfs(va, 0);
        opr.pop_back();
        opr.push_back(21);
        if ((va + vb) <= a)
        {
            dfs(va + vb, 0);
        }
        else
        {
            int differ = (va + vb - a);
            dfs(a, differ);
        }
        opr.pop_back();
    }
    if (va != a)
    {
        opr.push_back(1);
        dfs(a, vb);
        opr.pop_back();
    }
    if (vb != b)
    {
        opr.push_back(2);
        dfs(va, b);
        opr.pop_back();
    }
}

int main()
{
    while (cin >> a >> b >> t)
    {
        toend = false;
        memset(vis, false, sizeof(vis));
        opr.clear();
        dfs(0, 0);
    }
    return 0;
}