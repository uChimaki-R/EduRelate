#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> num;
stack<char> opr;

int toi(char c)
{
    if (c == 'V')
    {
        return 1;
    }
    return 0;
}

char toc(int i)
{
    if (i)
    {
        return 'V';
    }
    return 'F';
}

void cal()
{
    int n1 = toi(num.top());
    num.pop();
    int n2 = toi(num.top());
    num.pop();
    char op = opr.top();
    opr.pop();
    if (op == '&')
    {
        num.push(toc(n1 * n2));
    }
    else
    {
        num.push(toc(n1 + n2));
    }
}

int main()
{
    string s;
    int cnt = 1;
    while (getline(cin, s))
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            if (s[i] == '!')
            {
                if (s[i + 1] == '(')
                {
                    opr.push(s[i]);
                }
                else if (s[i + 1] == '!')
                {
                    i++;
                }
                else
                {
                    if (s[i + 1] == 'V')
                    {
                        s[i + 1] = 'F';
                    }
                    else
                    {
                        s[i + 1] = 'V';
                    }
                }
            }
            else if (s[i] == ')')
            {
                while (opr.top() != '(')
                {
                    cal();
                }
                opr.pop();
                if (!opr.empty() && opr.top() == '!')
                {
                    char c = num.top();
                    num.pop();
                    if (c == 'V')
                    {
                        num.push('F');
                    }
                    else
                    {
                        num.push('V');
                    }
                    opr.pop();
                }
            }
            else if (isalpha(s[i]))
            {
                num.push(s[i]);
            }
            else if (s[i] == '(')
            {
                opr.push(s[i]);
            }
            else if (s[i] == '|' || s[i] == '&')
            {
                while (!opr.empty() && opr.top() != '(') // 之前判断!opr.empty() && opr.top() == '&'一直WA，应该把之前的运算符全部计算，直到为空或者到了左括号（范围）
                {
                    cal();
                }
                opr.push(s[i]);
            }
        }
        while (!opr.empty())
        {
            cal();
        }
        cout << "Expression " << cnt++ << ": " << num.top() << endl;
        num.pop();
    }
    return 0;
}