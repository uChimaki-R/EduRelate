#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> st;
queue<int> qu;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int cnt;
        cin >> cnt;
        for (int i = 0; i < cnt; i++)
        {
            int input;
            cin >> input;
            st.push(input);
            qu.push(input);
        }
        bool is_st = true, is_qu = true;
        for (int i = 0; i < cnt; i++)
        {
            int output;
            cin >> output;
            if (st.top() != output)
            {
                is_st = false;
            }
            if (qu.front() != output)
            {
                is_qu = false;
            }
            st.pop();
            qu.pop();
        }
        if (is_st && is_qu)
        {
            cout << "both" << endl;
        }
        else if (is_st)
        {
            cout << "stack" << endl;
        }
        else if (is_qu)
        {
            cout << "queue" << endl;
        }
        else
        {
            cout << "neither" << endl;
        }
    }
    return 0;
}