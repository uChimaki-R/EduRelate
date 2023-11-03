//#include<iostream>
//using namespace std;
//
//bool isPrime(int val)
//{
//	if (val == 1)
//	{
//		return false;
//	}
//	else if (val == 2)
//	{
//		return true;
//	}
//	else
//	{
//		for (int i = 2; i <= sqrt(val); i++)
//		{
//			if (val % i == 0)
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//}
//
//int main()
//{
//	int x, y;
//	cout << "请输入区间：" << endl;
//	cin >> x >> y;
//	int count = 0;
//	for (int i = x; i <= y; i++)
//	{
//		if (isPrime(i))
//		{
//			count++;
//		}
//	}
//	cout << "该区间内有 " << count << " 个素数" << endl;
//	system("pause");
//	return 0;
//}