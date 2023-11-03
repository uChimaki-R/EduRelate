#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int len;
string s1, s2;
stack<char> st;
vector<char> opr;

//入栈次数 出栈次数
void dfs(int cnti, int cnto)
{
    if (cnti == len && cnto == len)
    {
        for (int i = 0; i < opr.size(); i++)
        {
            cout << opr[i] << " ";
        }
        cout << endl;
        return;
    }
    if (s1.length())
    {
        //s1还有内容，可以入栈（从最前面开始入）
        opr.push_back('i');
        char temp = s1[0];//保留副本
        s1.erase(0, 1);//擦去第一个（入栈的内容）
        st.push(temp);//入栈
        dfs(cnti + 1, cnto);
        //还原
        opr.pop_back();
        st.pop();
        string stemp(1,temp);
        s1.insert(0,stemp);
    }
    if (!st.empty() && st.top() == s2[cnto])
    {
        //栈中还有内容并且顶部是想要的元素
        char temp = st.top();//保留副本
        st.pop();//出栈
        opr.push_back('o');
        dfs(cnti, cnto + 1);
        //还原
        opr.pop_back();
        st.push(temp);
    }
}

int main()
{
    while (getline(cin, s1) && getline(cin, s2))
    {
        opr.clear();
        //dfs里面s1的长度会变，所以提前存下来
        len = s1.size();
        cout << "[" << endl;
        dfs(0, 0);
        cout << "]" << endl;
    }
    return 0;
}


//失败的dfs

// void dfs(int pos, int p, string s)
// {
//     if (pos == -1)
//     {
//         if (s == s2)
//         {
//             for (int i = 0; opr[i]!='\0'; i++)
//             {
//                 if (i != 0)
//                 {
//                     cout << " ";
//                 }
//                 cout << opr[i];
//             }
//             cout << endl;
//         }
//         return;
//     }
//     if (s1.length() != 0)
//     {
//         //只放
//         char temp = s1[pos];
//         st.push(temp);
//         s1.erase(pos, 1);
//         opr[p] = 'i';
//         dfs(pos - 1, p + 1, s);
//         st.pop();
//         s1 += temp;
//     }
//     if (!st.empty())
//     {
//         //只出
//         char temp = st.top();
//         s += temp;
//         st.pop();
//         opr[p] = 'o';
//         dfs(pos, p + 1, s);
//         st.push(temp);
//         s.erase(s.length() - 1, 1);
//     }
//     if(s1.length()!=0)
//     {
//         //放入之后就出
//         char temp = s1[pos];
//         s1.erase(pos, 1);
//         s += temp;
//         opr[p] = 'i';
//         opr[p + 1] = 'o';
//         dfs(pos - 1, p + 2, s);
//         s1 += temp;
//         s.erase(s.length() - 1, 1);
//     }
// }