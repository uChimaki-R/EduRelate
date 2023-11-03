
////1.
//#include<iostream>
//using namespace std;
//
//int get_count(int input, int val)
//{
//	int ret = 0;
//	int temp = input;
//	while (temp)
//	{
//		if (temp % 10 == val)
//		{
//			ret++;
//		}
//		temp /= 10;
//	}
//	return ret;
//}
//
//int main()
//{
//	cout << "请输入一个正整数：" << endl;
//	int input;
//	cin >> input;
//	cout << "请输入要统计个数的数字：" << endl;
//	int val;
//	cin >> val;
//	int count = get_count(input, val);
//	cout << "该数字中有 " << count << " 个 " << val << endl;
//	system("pause");
//	return 0;
//}



////2.
//#include<iostream>
//#include<cmath>
//using namespace std;
//int judge_p(int);
//void gotbaha(int);
//int main()
//{
//    int n = 0;
//    cin >> n;
//    while (n % 2 != 0 || n < 6)
//    {
//        cout << "You give an error num.Please try again:>" << endl;
//        cin >> n;
//    }
//    gotbaha(n);
//    return 0;
//}
//int judge_p(int n)
//{
//    int i = 0;
//    for (i = 2; i <= sqrt(n); i++)
//    {
//        if (n % i == 0)
//        {
//            return 0;
//        }
//    }
//    if (n == 2)
//    {
//        return 1;
//    }
//    if (n == 1)
//    {
//        return 0;
//    }
//    return 1;
//}
//void gotbaha(int n)
//{
//    int i = 2;
//    int j = 2;
//    for (i = 2; i < n; i++)
//    {
//        for (j = 2; j < n && j <= i; j++)
//        {
//            if (judge_p(j) == 1 && judge_p(i) == 1 && j + i == n)
//            {
//                cout << n << '=' << j << '+' << i << endl;
//            }
//        }
//    }
//}



////3.
//#include<iostream>
//using namespace std;
//
//int calculate(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * n + calculate(n - 1);
//	}
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int ret = calculate(n);
//	cout << "ret = " << ret << endl;
//	system("pause");
//	return 0;
//}



////4.
//#include<iostream>
//using namespace std;
//#include<cmath>
//
//double func(double x, int n)
//{
//	if (n == 1)
//	{
//		return sqrt(1.0 + x);
//	}
//	else
//	{
//		return sqrt(n + func(x, n - 1));
//	}
//}
//
//int main()
//{
//	double x;
//	int n;
//	cin >> x >> n;
//	double ret = func(x, n);
//	cout << "ret = " << ret << endl;
//	system("pause");
//	return 0;
//}


////5.
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int year, month, day;
//	cin >> year >> month >> day;
//	int flag = 0;
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		flag = 1;
//	}
//	int sum = 0;
//	switch (month)
//	{
//		case 1:
//			sum = day;
//			break;
//		case 2:
//			sum = 31 + day;
//			break;
//		case 3:
//			sum = 31 + 28 + flag + day;
//			break;
//		case 4:
//			sum = 31 + 28 + flag + 31 + day;
//			break;
//		case 5:
//			sum = 31 + 28 + flag + 31 + 30 + day;
//			break;
//		case 6:
//			sum = 31 + 28 + flag + 31 + 30 + 31 + day;
//			break;
//		case 7:
//			sum = 31 + 28 + flag + 31 + 30 + 31 + 30 + day;
//			break;
//		case 8:
//			sum = 31 + 28 + flag + 31 + 30 + 31 + 30 + 31 + day;
//			break;
//		case 9:
//			sum = 31 + 28 + flag + 31 + 30 + 31 + 30 + 31 + 31 + day;
//			break;
//		case 10:
//			sum = 31 + 28 + flag + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
//			break;
//		case 11:
//			sum = 31 + 28 + flag + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
//			break;
//		case 12:
//			sum = 31 + 28 + flag + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
//			break;
//		default:
//			break;
//	}
//	cout << "是该年的第 " << sum << " 天" << endl;
//	std::system("pause");
//	return 0;
//}



