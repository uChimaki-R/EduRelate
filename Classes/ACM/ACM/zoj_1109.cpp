#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> mp;
char s1[1000], s2[1000];
string s;

int main()
{
    getline(cin, s);
    while (s[0] != '\0')
    {
        sscanf(s.c_str(), "%s %s", s1, s2);
        mp[s2] = s1;
        getline(cin, s);
    }
    while (cin >> s)
    {
        if (mp.count(s))
        {
            cout << mp[s] << endl;
        }
        else
        {
            cout << "eh" << endl;
        }
    }
    return 0;
}