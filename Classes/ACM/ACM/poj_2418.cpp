#include <iostream>
#include <map>
#include <iomanip>
#include <string>
using namespace std;

typedef long long LL;

map<string, LL> mp;

int main()
{
    string s;
    double total = 0;
    while (getline(cin, s))
    {
        mp[s]++;
        total++;
    }
    for (map<string, LL>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << fixed << setprecision(4) << 100 * it->second / total << endl;
    }
    return 0;
}