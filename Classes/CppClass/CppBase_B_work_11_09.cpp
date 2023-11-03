// //1

// #include<iostream>
// using namespace std;
// int main()
// {
//     int i = 0;
//     while(1)
//     {
//         if ((i % 2 == 1) && (i % 3 == 2) && (i % 4 == 3) && (i % 5 == 4) && (i % 6 == 5) && (i % 7 == 0))
//         {
//             break;
//         }
//         i++;
//     }
//     cout << i;
//     return 0;
// }

// //2

// #include<iostream>
// using namespace std;
// int main()
// {
//     int a = 0, b = 0, c = 0, d = 0;
//     for (a = 0; a < 2;a++)
//     {
//         for (b = 0; b < 2;b++)
//         {
//             for (c = 0; c < 2;c++)
//             {
//                 for (d = 0; d < 2;d++)
//                 {
//                     if ((a + b + c + d) == 1)
//                     {
//                         if(((b+d)==1)&&((b+c)==1)&&((a+b)==1))
//                         {
//                             cout << a << b << c << d;
//                             return 0;
//                         }
//                     }
//                 }
//             }
//         }
//     }
// }

// //3.1

// #include<iostream>
// using namespace std;
// int main()
// {
//     int a = 0, b = 0, c = 0;
//     int x, y, z;
//     for (a = 0; a < 2; a++)
//     {
//         for (b = 0; b < 2; b++)
//         {
//             for (c = 0; c < 2; c++)
//             {
//                 x = a;
//                 y = b;
//                 z = c;
//                 if(a==0)
//                 {
//                     y = 1;
//                 }
//                 if(b==0)
//                 {
//                     z = 1;
//                 }
//                 if(c==0)
//                 {
//                     if(a==0&&b==1)
//                     {
//                         y = 1;
//                         z = 0;
//                     }
//                     else if(a==1&&b==1)
//                     {
//                         y = 0;
//                         z = 0;
//                     }
//                     else if(a==0&&b==1)
//                     {
//                         y = 1;
//                         z = 0;
//                     }
//                 }
//                 if(a==x&&b==y&&c==z)
//                 {
//                     cout << a << b << c;
//                     return 0;
//                 }
//             }
//         }
//     }
// }

// //3.2

// #include<iostream>
// using namespace std;
// int main()
// {
//     int a = 0, b = 0, c = 0;
//     int x, y, z;
//     for (a = 0; a < 2; a++)
//     {
//         for (b = 0; b < 2; b++)
//         {
//             for (c = 0; c < 2; c++)
//             {
//                 x = (b == 0);
//                 y = (c == 0);
//                 z = (a == 0 && b == 0);
//                 if(a==0)
//                 {
//                     x = !(b == 0);
//                 }
//                 if(b==0)
//                 {
//                     y = !(c == 0);
//                 }
//                 if(c==0)
//                 {
//                     z = !(a == 0 && b == 0);
//                 }
//                 if(x+y+z==3)
//                 {
//                     cout << a << b << c;
//                     return 0;
//                 }
//             }
//         }
//     }
// }

//4

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double s(double, double);
int main()
{
    double d, n;
    cin >> d >> n;
    double ret = s(d, n);
    cout << fixed << setprecision(8) << ret;
    return 0;
}
double s (double d,double n)
{
    if(n==1)
    {
        return d/10.0;
    }
    int i = 0;
    double ret = 0;
    for (i = 0; i < n; i++)
    {
        ret += d / (pow(10, i + 1));
    }
    return ret+s(d,n-1);
}