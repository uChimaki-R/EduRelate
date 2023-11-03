#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct Msg
{
    string s;
    int val, cnt;
    bool operator>(const Msg &m) const
    {
        if (this->cnt != m.cnt)
        {
            return this->cnt > m.cnt;
        }
        return this->s > m.s;
    }
};

priority_queue<Msg, vector<Msg>, greater<Msg>> qu;

int main()
{
    string input;
    while (getline(cin, input))
    {
        if (input == "GET")
        {
            if (qu.empty())
            {
                cout << "EMPTY QUEUE!" << endl;
            }
            else
            {
                Msg m = qu.top();
                qu.pop();
                cout << m.s << " " << m.val << endl;
            }
        }
        else
        {
            Msg m;
            stringstream ss;
            ss << input;
            ss >> input >> m.s >> m.val >> m.cnt;
            qu.push(m);
        }
    }
    return 0;
}