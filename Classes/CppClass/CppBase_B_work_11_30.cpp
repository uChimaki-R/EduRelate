
////8) 使用递归函数，把任意一个正整数颠倒过来输出。例如，输入正整数 678，输出应为 876
//#include<iostream>
//using namespace std;
//
//void rprint(int input)
//{
//	if(input / 10)
//	{
//		cout << input % 10;
//		rprint(input / 10);
//	}
//	else
//	{
//		cout << input;
//	}
//}
//
//void test()
//{
//	int input = 0;
//	cin >> input;
//	rprint(input);
//}
//
//int main()
//{
//	test();
//	return 0;
//}


////9
//#include<iostream>
//using namespace std;
//
//int isadd15(int num)
//{
//	int sum = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		sum += (num % 10);
//		num /= 10;
//	}
//	if (sum == 15)
//	{
//		return 1;
//	}
//	return 0;
//}
//
//void test()
//{
//	int m_count = 0;
//	for (int i = 100; i <= 999; i++)
//	{
//		if (isadd15(i))
//		{
//			cout << i << " ";
//			m_count++;
//			if (m_count % 5 == 0)
//			{
//				cout << endl;
//			}
//		}
//	}
//	cout << endl << "count = " << m_count << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}



////13
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




////15
//#include<iostream>
//using namespace std;
//#include<cstdio>
//#include<ctime>
//
//void test()
//{
//	int arr[10] = { 0 };
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < 10; i++)
//	{
//		int num = rand() % 99 + 1;
//		arr[i] = num;
//		cout << arr[i] << " ";
//	}
//}
//
//int main()
//{
//	test();
//	return 0;
//}



////16
//#include<iostream>
//using namespace std;
//
//void isnegative(int input)
//{
//	if (input > 0)
//	{
//		cout << input << " ";
//	}
//	else
//	{
//		cout << 0 << " ";
//	}
//}
//
//void test()
//{
//	int arr[10] = { 0 };
//	int j = 0;
//	for (int i = -3; i < 7; i++)
//	{
//		arr[j] = i;
//		j++;
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		isnegative(arr[i]);
//	}
//
//}
//
//int main()
//{
//	test();
//	return 0;
//}



////17
//#include<iostream>
//using namespace std;
//
//int isequal(int arr[], int len, int b)
//{
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] == b)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//void test()
//{
//	int arr[10];
//	int input = 0;
//	cin >> input;
//	int j = 0;
//	for (int i = 10; i < 20; i++)
//	{
//		arr[j] = i;
//		j++;
//	}
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int ret = isequal(arr, len, input);
//	if (ret != -1)
//	{
//		cout << ret;
//		return;
//	}
//	cout << "no found" << endl;
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}


////18
//#include<iostream>
//using namespace std;
//
//int isequal(int arr[], int len, int b)
//{
//	int m_count = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] == b)
//		{
//			m_count++;
//		}
//	}
//	if (m_count == 0)
//	{
//		return -1;
//	}
//	return m_count;
//}
//
//
//void test()
//{
//	int arr[10];
//	int input = 0;
//	cin >> input;
//	int j = 0;
//	for (int i = 10; i < 20; i++)
//	{
//		arr[j] = i;
//		j++;
//	}
//	arr[3] = 10;
//	arr[4] = 10;
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int ret = isequal(arr, len, input);
//	if (ret != -1)
//	{
//		cout << "count = " << ret;
//		return;
//	}
//	cout << "no found" << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}



////19
//#include<iostream>
//using namespace std;
//
//template<typename T>
//int Max_Array(T* arr, int len)
//{
//	int max = 0;
//	int i = 0;
//	for (i = 1; i < len; i++)
//	{
//		if (arr[max] < arr[i])
//		{
//			max = i;
//		}
//	}
//	return max;
//}
//
//void test()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int num1 = Max_Array(arr, len);
//	cout << "Max = " << arr[num1] << endl;
//
//
//	char carr[10];
//	for (int i = 0; i < 10; i++)
//	{
//		carr[i] = 'a' + i;
//	}
//	int len2 = sizeof(carr) / sizeof(carr[0]);
//	int num2 = Max_Array(carr, len2);
//	cout << "Max = " << carr[num2] << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}


//20
#include<iostream>
using namespace std;

int find(int a[], int n, int sz)
{
	int left = 0;
	int right = sz - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] > n)
		{
			right = mid - 1;
		}
		else if (a[mid] < n)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	//有序数组
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 0;
	cin >> key;
	int size = sizeof(arr) / sizeof(arr[0]);
	int place = find(arr, key, size);
	if (place != -1)
	{
		cout << "下标为: " << place;
	}
	else
	{
		cout << "找不到";
	}
	return 0;
}