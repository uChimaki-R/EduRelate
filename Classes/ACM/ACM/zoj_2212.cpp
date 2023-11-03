#include <iostream>
#include <queue>
using namespace std;

struct RGT
{
    int val, t, T;
    bool operator>(const RGT &r) const
    {
        if (this->t != r.t)
        {
            return this->t > r.t;
        }
        return this->val > r.val;
    }
};

priority_queue<RGT, vector<RGT>, greater<RGT>> qu;

int main()
{
    string s;
    cin >> s;
    while (s == "Register")
    {
        int val, t;
        cin >> val >> t;
        RGT r = {val, t, t};
        qu.push(r);
        cin >> s;
    }
    int cnt;
    cin >> cnt;
    while (cnt--)
    {
        RGT top = qu.top();
        qu.pop();
        cout << top.val << endl;
        top.t += top.T;
        qu.push(top);
    }
    return 0;
}