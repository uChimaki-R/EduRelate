#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool mycmp(const pair<char, int> &p1, const pair<char, int> &p2)
{
    return p1.second > p2.second;
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        if (s1.length() != s2.length())
        {
            cout << "NO" << endl;
            continue;
        }
        map<char, int> mp1, mp2;
        for (int i = 0; i < s1.length(); i++)
        {
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        vector<pair<char, int>> v1(mp1.begin(), mp1.end());
        vector<pair<char, int>> v2(mp2.begin(), mp2.end());
        sort(v1.begin(), v1.end(), mycmp);
        sort(v2.begin(), v2.end(), mycmp);
        if (v1.size() != v2.size())
        {
            cout << "NO" << endl;
            continue;
        }
        int i = 0;
        for (; i < v1.size(); i++)
        {
            if (v1[i].second != v2[i].second)
            {
                cout << "NO" << endl;
                break;
            }
        }
        if (i == v1.size())
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}