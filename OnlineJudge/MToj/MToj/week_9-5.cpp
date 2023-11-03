#include <iostream>
#include <map>
#include <functional>
#include <vector>
using namespace std;

map<int, int, greater<int>> mp;

int main()
{
    int n, val;
    cin >> n;
    while (n--)
    {
        cin >> val;
        mp[val]++;
    }
    vector<pair<int, int>> v(mp.begin(), mp.end());
    int i = 0;
    for (; i < v.size(); i++)
    {
        if (v[i].second >= v[i].first)
        {
            cout << v[i].first;
            break;
        }
    }
    if (i == v.size())
    {
        cout << 0;
    }
    return 0;
}