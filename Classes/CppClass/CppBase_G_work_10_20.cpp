// //根据函数表达式写出对应程序
// #include<iostream>
// using namespace std;
// int main()
// {
//     int x;
//     cin >> x;
//     if(x<1)
//     {
//         cout << x;
//     }
//     else if(1<=x&&x<10)
//     {
//         cout << 2 * x - 1;
//     }
//     else
//     {
//         cout << 3 * x - 11;
//     }
//     return 0;
// }


// //评级程序
// #include<iostream>
// using namespace std;
// int main()
// {
//     int score;
//     cin>>score;
//     if(score>=90)
//     {
//         cout << "A";
//     }
//     else if(score>=80&&score<=89)
//     {
//         cout << "B";
//     }
//     else if(score>=70&&score<=79)
//     {
//         cout << "C";
//     }
//     else if(score>=60&&score<=69)
//     {
//         cout << "D";
//     }
//     else
//     {
//         cout << "E";
//     }
//     return 0;
// }



// //阶乘相加
// #include<iostream>
// using namespace std;
// int main()
// {
//     int n = 0;
//     cin >> n;
//     int i = 0;
//     int j = 0;
//     long long tmp = 1;
//     long long sum = 0;
//     for (i = 1; i <= n; i++)
//     {
//         j = 0;
//         tmp = 1;
//         for (j = i; j > 0; j--)
//         {
//             tmp *= j;
//         }
//         sum += tmp;
//     }
//     cout << sum;
//     return 0;
// }


// //输出水仙花数
// #include<iostream>
// #include<cmath>
// using namespace std;
// int main()
// {
//     int i = 0;
//     int num = 0;
//     for (i = 100; i < 1000; i++)
//     {
//         num = pow(i % 10, 3) + pow((i / 10) % 10, 3) + pow((i / 100), 3);
//         if(i==num)
//         {
//             cout << i << " ";
//         }
//     }
//         return 0;
// }


// //找出完数
// #include<iostream>
// using namespace std;
// int main()
// {
//     int i = 0;
//     int arr[1000] = {0};
//     int count = 0;
//     int j = 0;
//     int sum = 0;
//     for (i = 1; i <= 1000; i++)
//     {
//         count = 0;
//         sum = 0;
//         for (j = 1; j < i; j++)
//         {
//             if (i % j == 0)
//             {
//                 arr[count] = j;
//                 count++;
//                 sum += j;
//             }
//         }
//         if (sum == i)
//         {
//             cout << i << ",its factors are ";
//             int flag = 0;
//             for (j = 0; j < count; j++)
//             {
//                 if (flag != 0)
//                 {
//                     cout << ",";
//                 }
//                 cout << arr[j];
//                 flag = 1;
//             }
//             cout << endl;
//         }
//     }
//     return 0;
// }


//分数序列求和
#include<iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    if (n == 1)
    {
        cout << 2;
    }
    else if (n == 2)
    {
        cout << 2 + 3 / 2.0;
    }
    else
    {
        int i = 0;
        float sum = 2 / 1 + 3 / 2.0;
        float o1 = 2;
        float o2 = 3;
        float d1 = 1;
        float d2 = 2;
        float tmp = 0;
        for (i = 2; i < n; i++)
        {
            sum += (o1 + o2) / (d1 + d2);
            tmp = o2;
            o2 = o1 + o2;
            o1 = tmp;
            tmp = d2;
            d2 = d1 + d2;
            d1 = tmp;
        }
    cout << sum;
    }
    
    return 0;
}