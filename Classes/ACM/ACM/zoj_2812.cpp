#include<iostream>
using namespace std;

int Quicksum(string s)
{
    int ret = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i]!=' ')
        {
            ret += ((s[i] - 64) * (i + 1));
        }
    }
    return ret;
}

int main()
{
    string s;
    getline(cin, s);
    while(s!="#")
    {
        cout << Quicksum(s) << endl;
        getline(cin, s);
    }
    return 0;
}