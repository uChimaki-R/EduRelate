////2
//#include<iostream>
//#include<iomanip>
//#include<cmath>
//using namespace std;
//int main()
//{
//	float r = 1.5f;
//	int h = 3;
//	cout << setiosflags(ios::fixed) << setprecision(2);
//	cout << "圆的周长是" << 2 * 3.14 * r << endl;
//	cout << "圆的面积是" << 3.14 * pow(r, 2)<<endl;
//	cout << "圆球表面积是" << 4 * 3.14 * pow(r, 2) << endl;
//	cout << "圆的体积是" << 4 / 3 * 3.14 * pow(r, 3);
//	return 0;
//}

////3.
//#include<iostream>
//#include<iomanip>
//using namespace std;
//int main()
//{
//	float t;
//	cin >> t;
//	cout << setiosflags(ios::fixed) << setprecision(2);
//	cout << "摄氏温度是：" <<(float)5 / 9 * (t - 32);
//	return 0;
//}

////4.
//#include<iostream>
//using namespace std;
//int main()
//{
//	char c1 = getchar(), c2 = getchar();
//	putchar(c1); putchar(c2); 
//	cout << c1 << c2;
//}

////8.
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 3;
//	int b = 4;
//	int c = 5;
//	int r1 = (a + b > c && b == c);
//	cout << r1 << endl;
//	a = 3; b = 4; c = 5;
//	int r2 = (a || b + c && b - c);
//	cout << r2 << endl;
//	a = 3; b = 4; c = 5;
//	int r3 = (!(a > b) && !c || 1);
//	cout << r3 << endl;
//	a = 3; b = 4; c = 5;
//	int x, y;
//	int r4 = (!(x = a) && (y = b) && 0);
//	cout << r4 << endl;
//	a = 3; b = 4; c = 5;
//	int r5 = (!(a + b) + c - 1 && b + c / 2);
//	cout << r5 << endl;
//	return 0;
//}

////9.
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a, b, c;
//	cin >> a >> b >> c;
//	int bigger = (a > b ? a : b);
//	int max = (bigger > c ? bigger : c);
//	cout << "max = " << max << endl;
//	return 0;
//}

////10.
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	int x;
//	int y = 0;
//	cin >> x;
//	if (x < 1)
//	{
//		y = x;
//	}
//	else if(x >= 1 && x < 10)
//	{
//		y = 2 * x - 1;
//	}
//	else if(x >= 10)
//	{
//		y = 3 * x - 11;
//	}
//	cout << y;
//	return 0;
//}

////11.
// #include<iostream>
// using namespace std;
// int main()
// {
//     int score;
//     cin>>score;
//     if(score >= 90)
//     {
//         cout << "A";
//     }
//     else if(score >= 80 && score <= 89)
//     {
//         cout << "B";
//     }
//     else if(score >= 70 && score <= 79)
//     {
//         cout << "C";
//     }
//     else if(score >= 60 && score <= 69)
//     {
//         cout << "D";
//     }
//     else
//     {
//         cout << "E";
//     }
//     return 0;
// }

////12.
//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	int a;
//	cin >> a;
//	if (a > 9999 || a < 0)
//	{
//		cout << "error";
//		return 0;
//	}
//	int count = 1;
//	int tmp = a;
//	while ((tmp = tmp / 10 )!= 0)
//	{
//		count++;
//	}
//	cout << count << endl;
//	tmp = a;
//	int i = 0;
//	for (i = count; i > 0 ; i--)
//	{
//		cout << tmp / (int)(pow(10, i - 1)) % 10;
//	}
//	cout << endl;
//	tmp = a;
//	for (i = 0; i < count; i++)
//	{
//		cout << tmp / (int)(pow(10, i)) % 10;
//	}
//	return 0;
//}

////13.
//#include<iostream>
//using namespace std;
//double if_way(double a);
//double switch_way(double a);
//int main()
//{
//	double a;
//	cin >> a;
//	cout << if_way(a) << endl;
//	cout << switch_way(a) << endl;
//	return 0;
//}
//double if_way(double a)
//{
//	if (a <= 100000)
//	{
//		return a * 0.1;
//	}
//	else if (a <= 200000)
//	{
//		return 10000 + (a - 100000) * 0.075;
//	}
//	else if (a <= 400000)
//	{
//		return 10000 + 7500 + (a - 200000) * 0.05;
//	}
//	else if (a <= 600000)
//	{
//		return 10000 + 7500 + 10000 + (a - 400000) * 0.03;
//	}
//	else if (a <= 1000000)
//	{
//		return 10000 + 7500 + 10000 + 6000 +(a - 600000) * 0.015;
//	}
//	else
//	{
//		return 10000 + 7500 + 10000 + 6000 + 6000 + (a - 1000000) * 0.01;
//	}
//}
//double switch_way(double a)
//{
//	switch ((int)a / 100000)
//	{
//	case 0:
//		return a * 0.1;
//		break;
//	case 1:
//		return 10000 + (a - 100000) * 0.075;
//		break;
//	case 2:
//	case 3:
//		return 10000 + 7500 + (a - 200000) * 0.05;
//		break;
//	case 4:
//	case 5:
//		return 10000 + 7500 + 10000 + (a - 400000) * 0.03;
//		break;
//	case 6:
//	case 7:
//	case 8:
//	case 9:
//		return 10000 + 7500 + 10000 + 6000 + (a - 600000) * 0.015;
//		break;
//	default:
//		return 10000 + 7500 + 10000 + 6000 + 6000 + (a - 1000000) * 0.01;
//		break;
//	}
//}

////14.
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a, b, c, d;
//	cin >> a >> b >> c >> d;
//	int arr[4] = { a,b,c,d };
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	return 0;
//}

////15.
//#include<iostream>
//using namespace std;
//int max_yue(int, int);
//int min_bei(int, int,int);
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	int y = max_yue(m, n);
//	cout << y << endl;
//	int b = min_bei(m, n,y);
//	cout << b << endl;
//	return 0;
//}
//int max_yue(int m, int n)
//{
//	int tmp = m % n;
//	if (tmp != 0)
//	{
//		return max_yue(n, tmp);
//	}
//	return n;
//}
//int min_bei(int m, int n,int y)
//{
//	return m * n / y;
//}

////16.
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	int EN = 0;
//	int space = 0;
//	int other = 0;
//	int number = 0;
//	string str;
//	getline(cin, str);
//	for (int i = 0; i < str.length(); i++)
//	{
//		if ((65 <= (int)str[i] && (int)str[i] <= 90) || (97 <= (int)str[i] && (int)str[i] <= 122))
//		{
//			EN += 1;
//		}
//		else if (str[i] == ' ')
//		{
//			space += 1;
//		}
//		else if ('0' <= str[i] && str[i] <= '9')
//		{
//			number += 1;
//		}
//		else
//		{
//			other += 1;
//		}
//	}
//	cout << "英文有" << EN << "空格有" << space << "其他符号有" << other << "数字有" << number << endl;
//	return 0; 
//}

////17.
//#include<iostream>
//#include<cmath>
//using namespace std;
//void calcul(int, int);
//int ret = 0;
//int main()
//{
//	int a, n;
//	int b = 0;
//	cin >> a >> n;
//	if (a > 10 || a < 0)
//	{
//		cout << "error" << endl;
//		return 0;
//	}
//	calcul(a, n);
//	cout << ret << endl;
//	return 0;
//	  
//}
//void calcul(int a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		ret += a * pow(10, i);
//	}
//	if (n > 0)
//	{
//		calcul(a, n - 1);
//	}
//}

////18.
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

////19.
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
//     return 0;
// }

////20.
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

////21.
//#include<iostream>
//using namespace std;
//int main()
//{
//    int n = 0;
//    cin >> n;
//    if (n == 1)
//    {
//        cout << 2;
//    }
//    else if (n == 2)
//    {
//        cout << 2 + 3 / 2.0;
//    }
//    else
//    {
//        int i = 0;
//        float sum = 2 / 1 + 3 / 2.0;
//        float o1 = 2;
//        float o2 = 3;
//        float d1 = 1;
//        float d2 = 2;
//        float tmp = 0;
//        for (i = 2; i < n; i++)
//        {
//            sum += (o1 + o2) / (d1 + d2);
//            tmp = o2;
//            o2 = o1 + o2;
//            o1 = tmp;
//            tmp = d2;
//            d2 = d1 + d2;
//            d1 = tmp;
//        }
//        cout << sum;
//    }
//    return 0;
//}

////22.
//#include<iostream>
//int main()
//{
//	using namespace std;
//	int a = 1;
//	for (int i = 0; i < 9; i++)
//	{
//		a = ++a * 2;	
//	}
//	cout << a << endl;
//	return 0;
//}

////23.
//#include<iostream>
//#include <cmath>
//#include <iomanip>
//using namespace std;
//int main() 
//{
//	float x1, x0, a;
//	cin >> a;
//	x0=x1=a/2;
//	while (fabs(x1 - x0) > 1e-5);
//	{
//		x0 = x1;
//		x1 = (x0 + a / x0) / 2;
//	} 
//	cout << setiosflags(ios::fixed) << setprecision(3) << x1 << endl;
//	return 0;
//}

////24.
//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 2*i + 1; j++)
//		{
//			cout << '*';
//		}
//		cout << endl;
//	}
//	for (int i = 2; i >= 0; i--)
//	{
//		for (int j = 2*i+1; j >0; j--)
//		{
//			cout << '*';
//		}
//		cout << endl;
//	}
//	return 0;
//}

//25.
#include<iostream>
#include <cmath> 
using namespace std;
int main() 
{
    char a, b, c;
    for (a = 'x'; a <= 'z'; a++) 
    {
        for (b = 'x'; b <= 'z'; b++) 
        {
            for (c = 'x'; c <= 'z'; c++) 
            {
                if (a != 'x' && c != 'x' && c != 'z' && a != b && a != c && b != c)
                {
                    cout << "a with " << a << endl << "b with " << b << endl << "c with " << c << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}