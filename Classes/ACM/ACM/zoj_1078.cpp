#include <iostream>
#include <vector>
using namespace std;

string trans(int val, int i)
{
    string s = "";
    while (val)
    {
        int y = val % i;
        char c = y + '0';
        string ss(1, c);
        s.insert(0, ss);
        val /= i;
    }
    return s;
}

bool is_hui(string &s)
{
    int i = 0;
    while (i < (s.length() / 2))
    {
        if (s[i] != s[s.length() - 1 - i])
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    int input;
    cin >> input;
    while (input)
    {
        vector<int> v;
        bool flag = true;
        for (int i = 2; i <= 16; i++)
        {
            string s = trans(input, i);
            if (is_hui(s))
            {
                flag = false;
                v.push_back(i);
            }
        }
        if (flag)
        {
            cout << "Number " << input << " is not a palindrom" << endl;
        }
        else
        {
            cout << "Number " << input << " is palindrom in basis ";
            for (int i = 0; i < v.size(); i++)
            {
                if (i != 0)
                {
                    cout << " ";
                }
                cout << v[i];
            }
            cout << endl;
        }
        cin >> input;
    }
    return 0;
}