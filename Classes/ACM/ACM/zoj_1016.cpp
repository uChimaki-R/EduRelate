#include <iostream>
#include <string.h>
using namespace std;

// P：右括号左边的左括号数
// W：右括号匹配的左括号是左边第几个左括号

int p[21];
int w[21];
int pos = 0;
bool vis[21];

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        memset(p, 0, sizeof(p));
        memset(w, 0, sizeof(w));
        memset(vis, false, sizeof(vis));
        pos = 0;
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> p[j];
        }

        // 简化方法
        int cnt = 0;
        string s = "";
        for (int j = 0; j < n; j++)
        {
            while (cnt < p[j])
            {
                s += '(';
                cnt++;
            }
            s += ')';
        }
        // cout << s;//打印测试

        cnt = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == ')')
            {
                for (int k = j - 1; k >= 0; k--)
                {
                    if(s[k]=='-')
                    {
                        cnt++; // 计算左边有多少左括号直到找到自己匹配的左括号
                    }
                    if (s[k] == '(')
                    {
                        s[k] = '-';
                        break;
                    }
                }
                w[pos++] = cnt + 1;
                cnt = 0;
            }
        }
        for (int j = 0; j < pos; j++)
        {
            if (j != 0)
            {
                cout << " ";
            }
            cout << w[j];
        }
        cout << endl;
    }
    return 0;
}

// 用这个方法时不知道为什么用的deque，string应该也可以
//  //第一个有括号前有p[0]个左括号
//  for (int j = 0; j < p[0]; j++)
//  {
//      s.push_back('(');
//  }
//  for (int j = 0; j < n - 1; j++)
//  {
//      s.push_back(')');
//      for (int k = 0; k < (p[j + 1] - p[j]); k++)
//      {
//          //大小差是中间的左括号数
//          s.push_back('(');
//      }
//  }
//  s.push_back(')');