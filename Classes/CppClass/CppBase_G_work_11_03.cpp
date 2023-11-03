#include<iostream>
#include<cmath>
using namespace std;
int judge_p(int);
void gotbaha(int);
int main()
{
    int n = 0;
    cin >> n;
    while (n % 2 != 0 || n < 6)
    {
        cout << "You give an error num.Please try again:>" << endl;
        cin >> n;
    }
    gotbaha(n);
    return 0;
}
int judge_p(int n)
{
    int i = 0;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    if (n == 2)
    {
        return 1;
    }
    if (n == 1)
    {
        return 0;
    }
    return 1;
}
void gotbaha(int n)
{
    int i = 2;
    int j = 2;
    for (i = 2; i < n; i++)
    {
        for (j = 2; j < n && j <= i; j++)
        {
            if (judge_p(j) == 1 && judge_p(i) == 1 && j + i == n)
            {
                cout << n << '=' << j << '+' << i << endl;
            }
        }
    }
}