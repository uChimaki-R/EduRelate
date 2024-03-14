#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> ans;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        ans[s]++;
    }
    cout << ans.size();
    return 0;
}