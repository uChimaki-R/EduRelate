// #include<iostream>
// using namespace std;
// int main()
// {
//     char c1 = 'a',c2 = 'b',c3 = 'c';
//     int i1 = 10,i2 = 20,i3 = 30;
//     double d1 = 0.1,d2 = 0.2,d3 = 0.4;
//     //(d)
//     //int i = (i1>i2>i3<d1<d2<d3);
//     //cout<<i;
//     //(e)
//     //int ret = ((c1=i2*i3)!=(i2%i1));
//     //cout<<ret;
//     //(i)
//     //i1 += i2 *= i3;
//     //cout<<i1;
//     //(j)
//     i3 = (i1=1,i2--);
//     cout
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main()
// {
//     char i = '0';
//     while(1)
//     {
//         cin>>i;
//         if((65<=i&&i<=91)||(97<=i&&i<=123))
//         {
//             cout<<(int)i<<endl;
//             break;
//         }
//         else
//         {
//             cout<<"The input is not a letter, please re-enter!"<<endl;
//         }
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    char ch;
    cin >> ch;
    if (64 < ch&&ch < 91)//大写字母判断
    {
        cout << (char)(ch+32) << endl;
    }
    else if (96 < ch&&ch < 121)//小写字母判断
    {
        cout << (char)(ch - 32)<< endl;
    }
    else
    {
        cout << "please input a correct character" << endl;
    }
    return 0;
}