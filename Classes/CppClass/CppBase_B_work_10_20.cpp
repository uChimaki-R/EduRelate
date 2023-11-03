// //判断三角形
// #include<iostream>
// using namespace std;
// int main()
// {
//     int a,b,c;
//     cin>>a>>b>>c;
//     if(a+b>c&&a+c>b&&b+c>a)
//     {
//         cout<<"Can form a triangle"<<endl;
//     }
//     else
//     {
//         cout<<"Cannot form a triangle"<<endl;
//     }
//     return 0;
// }

// //计算矩形面积
// #include<iostream>
// using namespace std;
// int main()
// {
//     float a,b;
//     cin>>a>>b;
//     cout<<a*b;
//     return 0;
// }

// //交换两个整数
// #include<iostream>
// using namespace std;
// int main()
// {
//     float a,b;
//     cout<<"put in a and then b:"<<endl;
//     cin>>a>>b;
//     float c = a;
//     a = b;
//     b = c;
//     cout<<"after change:"<<endl;
//     cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
//     return 0;
// }

// //判断整数奇偶性
// #include<iostream>
// using namespace std;
// int main()
// {
//     int a;
//     cin>>a;
//     if(a%2==0)
//     {
//         cout<<"This num is ou."<<endl;
//     }
//     else
//     {
//         cout<<"This num is ji."<<endl;
//     }
//     return 0;
// }

// //判断性别
// #include<iostream>
// using namespace std;
// int main()
// {
//     char a;
//     cout << "What's your sex(b/g)?" << endl;
//     while(1)
//     {
//         cin>>a;
//         if(a=='b')
//         {
//             cout << "You are a boy." << endl;
//             break;
//         }
//         else if(a=='g')
//         {
//             cout << "You are a girl." << endl;
//             break;
//         }
//         else
//         {
//             cout << "?Say again please." << endl;
//         }
//     }
//     return 0;
// }

//判断闰年
#include<iostream>
using namespace std;
int main()
{
    int start,end;
    cin>>start>>end;
    int i = 0;
    int count = 0;
    for(i=start;i<=end;i++)
    {
        if((i%4==0&&i%100!=0)||i%400==0)
        {
            count++;
            cout<<i<<' ';
        }
    }
    cout<<endl<<"count = "<<count<<endl;
    return 0;
}