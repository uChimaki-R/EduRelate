#include <iostream>
#include <queue>
#include <map>
using namespace std;

queue<int> qu;
map<int, string> mp;

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        mp[i] = s;
        qu.push(i);
    }
    int s, t;
    char c;
    cin >> s >> c >> t;
    while (--s)
    {
        int i = qu.front();
        qu.pop();
        qu.push(i);
    }
    int cnt = 1;
    while (!qu.empty())
    {
        if (cnt % t == 0)
        {
            cout << mp[qu.front()] << endl;
            qu.pop();
        }
        else
        {
            int i = qu.front();
            qu.pop();
            qu.push(i);
        }
        cnt++;
    }
    return 0;
}