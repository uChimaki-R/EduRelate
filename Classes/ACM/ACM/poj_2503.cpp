#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

struct Dict
{
    char c1[11];
    char c2[11];
};

Dict arr[100005];
char input[11];
int cnt = 0;

void bs(Dict arr[], char *s)
{
    int left = 0;
    int right = cnt - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int ret = strcmp(arr[mid].c1, s);
        if (ret == 0)
        {
            printf("%s\n", arr[mid].c2);
            return;
        }
        else if (ret < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    printf("eh\n");
}

bool mycompare(Dict d1, Dict d2)
{
    return (strcmp(d1.c1, d2.c1) < 0);
}

int main()
{
    while (1)
    {
        Dict d;
        memset(input, '\0', sizeof(input));
        gets(input);
        if (input[0] == '\0')//之前判的空格一直re，估计是死循环了
        {
            break;
        }
        sscanf(input, "%s %s", d.c2, d.c1);
        arr[cnt++] = d;
    }
    sort(arr, arr + cnt, mycompare);
    while (1)
    {
        memset(input, '\0', sizeof(input));
        char *r = gets(input);
        if (r == NULL)//最后判的是文件结尾
        {
            break;
        }
        bs(arr, input);
    }
    return 0;
}

// 可能是vector读写速度比较慢，尝试使用数组

// #include <iostream>
// #include <vector>
// #include <string.h>
// #include <string>
// #include <algorithm>
// using namespace std;

// void bs(const vector<pair<string, string>> &v, const string &s)
// {
//     int left = 0;
//     int right = v.size() - 1;
//     while (left <= right)
//     {
//         int mid = (left + right) / 2;
//         int ret = v[mid].first.compare(s);
//         if (ret == 0)
//         {
//             printf("%s\n", v[mid].second.c_str());
//             return;
//         }
//         else if (ret < 0)
//         {
//             left = mid + 1;
//         }
//         else
//         {
//             right = mid - 1;
//         }
//     }
//     printf("eh\n");
// }

// char c1[100005];
// char c2[100005];
// char c;

// bool mycompare(const pair<string, string> &p1, const pair<string, string> &p2)
// {
//     return p1.first.compare(p2.first) < 0;
// }

// int main()
// {
//     vector<pair<string, string>> vm;
//     while ((c = getchar()) != ' ')
//     {
//         ungetc(c, stdin);
//         memset(c1, 0, sizeof(c1));
//         memset(c2, 0, sizeof(c1));
//         scanf("%s %s", &c1, &c2);
//         getchar();
//         string s1(c1);
//         string s2(c2);
//         vm.push_back(make_pair(s2, s1));
//     }
//     sort(vm.begin(), vm.end(), mycompare);
//     getchar();
//     while ((c = getchar()) != ' ')
//     {
//         ungetc(c, stdin);
//         memset(c1, 0, sizeof(c1));
//         scanf("%s", &c1);
//         string input(c1);
//         bs(vm, input);
//         getchar();
//     }
//     return 0;
// }