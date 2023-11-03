// //顺序结构部分第（3）题 3）
// #include<iostream>
// using namespace std;
// int main()
// {
//     cout << "How many jin of apples do you want to buy?" << endl;
//     float apples;
//     cin >> apples;
//     cout << "How many jin of pears do you want to buy?" << endl;
//     float pears;
//     cin >> pears;
//     cout << "How many jin of bananas do you want to buy?" << endl;
//     float bananas;
//     cin >> bananas;
//     cout << "How many jin of oranges do you want to buy?" << endl;
//     float oranges;
//     cin >> oranges;
//     float prize = apples * 2.50 + pears * 1.80 + bananas * 2.00 + oranges * 1.60;
//     cout << "You should pay me " << prize << " yuan." << endl;
//     cout << "Give:>";
//     float pay;
//     float differ = prize;
//     cin >> pay;
//     while(pay<differ)
//     {
//         cout << "You didn't give me enough money!Please give me more!" << endl;
//         differ = differ - pay;
//         cout << "You have to pay another " << differ << " yuan." << endl;
//         cout << "Give:>";
//         cin >> pay;
//     }
//     if(pay>differ)
//     {
//         cout << "You pay me too much.I will give " << pay - differ << " yuan back to you.";
//     }
//     return 0;
// }

// //选择结构部分第（3）题 4）
// #include<iostream>
// using namespace std;
// void judge_by_if(float);
// void judge_by_switch(float);
// int main()
// {
//     cout << "Please give two examination results:>" << endl;
//     float a, b;
//     cin >> a >> b;
//     while (!(a >= 0 && a <= 100) || !(b >= 0 && b <= 100))
//     {
//         cout << "You give error input.Please try again." << endl;
//         cin >> a >> b;
//     }
//     float sum = a + b;
//     cout << "judge_by_if:>" << endl;
//     judge_by_if(sum);
//     cout << endl;
//     cout << "judge_by_switch:>" << endl;
//     judge_by_switch(sum);
//     return 0;
// }
// void judge_by_if(float sum)
// {
//     cout << sum;
//     if (sum >= 180)
//     {
//         cout << "-->" << 'A';
//     }
//     else if (sum >= 160 && sum < 180)
//     {
//         cout << "-->" << 'B';
//     }
//     else if (sum >= 140 && sum < 160)
//     {
//         cout << "-->" << 'C';
//     }
//     else if (sum >= 120 && sum < 140)
//     {
//         cout << "-->" << 'D';
//     }
//     else
//     {
//         cout << "-->" << 'E';
//     }
// }
// void judge_by_switch(float sum)
// {
//     cout << sum;
//     switch((int)sum/10)
//     {
//         case 20:
//         case 19:
//         case 18:
//             cout << "-->" << 'A';
//             break;
//         case 17:
//         case 16:
//             cout << "-->" << 'B';
//             break;
//         case 15:
//         case 14:
//             cout << "-->" << 'C';
//             break;
//         case 13:
//         case 12:
//             cout << "-->" << 'D';
//             break;
//         default:
//             cout << "-->" << 'E';
//             break;
//     }
// }

// //循环结构部分第（2）题 4）
// #include<iostream>
// using namespace std;
// void print(int, char);
// int main()
// {
//     cout << "The number of layers and the pattern you want to print:>" << endl;
//     int l;
//     char p;
//     cin >> l >> p;
//     print(l, p);
//     return 0;
// }
// void print(int l, char p)
// {
//     int i = 0;
//     int j = 0;
//     for (i = 0; i < l; i++)
//     {
//         //打印空格
//         for (j = 0; j < i; j++)
//         {
//             cout << ' ';
//         }
//         //打印字符
//         for (j = 0; j < (l - i) * 2 - 1; j++)
//         {
//             cout << p;
//         }
//         cout << endl;
//     }
// }

// //6)
// //要求使用二重循环
// #include<iostream>
// using namespace std;
// int main()
// {
//     int i = 0;
//     int j = 0;
//     int sum = 0;
//     int tmp = 0;
//     for (i = 100; i <= 1000;i++)//500到1000其实都不是，上限可改为500
//     {
//         sum = 0;
//         tmp = i;
//         while(1)
//         {
//             if (tmp == 0)
//             {
//                 break;
//             }
//             sum += (tmp % 10);
//             tmp /= 10;
//         }
//         if(sum==5)
//         {
//             cout << i << ' ';
//         }
//     }
//     return 0;
// }

//8）
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 0;
    for (i = 0; i <= n; i++)
    {
        if (i % 10 == 3)
        {
            if (i % 3 == 0)
            {
                cout << i << ' ';
            }
        }
    }
    return 0;
}