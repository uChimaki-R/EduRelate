#include <iostream>
#include <queue>
using namespace std;

bool is_ok(int i, queue<int> q)
{
    int temp;
    int cnt = 1;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (cnt % i == 0)
        {
            cnt = 0;
        }
        else
        {
            q.push(temp);
        }
        cnt++;
    }
    return temp == 2;
}

int main()
{
    int input;
    cin >> input;
    while (input)
    {
        queue<int> q;
        for (int i = 2; i <= input; i++)
        {
            q.push(i);
        }
        int i = 1;
        while (i++)
        {
            if (is_ok(i, q))
            {
                cout << i << endl;
                break;
            }
        }
        cin >> input;
    }
    return 0;
}