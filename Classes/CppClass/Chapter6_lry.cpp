////1.
//#include<iostream>
//using namespace std;
//
//void point_sort(int* pa, int* pb, int* pc)
//{
//	if (*pa > *pb)
//	{
//		int temp = *pa;
//		*pa = *pb;
//		*pb = temp;
//	}
//	if (*pb > *pc)
//	{
//		int temp = *pb;
//		*pb = *pc;
//		*pc = temp;
//	}
//	if (*pa > *pb)
//	{
//		int temp = *pa;
//		*pa = *pb;
//		*pb = temp;
//	}
//	cout << *pa << " <= " << *pb << " <= " << *pc << endl;
//}
//
//void quote_sort(int& a, int& b, int& c)
//{
//	if (a > b)
//	{
//		int temp = a;
//		a = b;
//		b = temp;
//	}
//	if (b > c)
//	{
//		int temp = b;
//		b = c;
//		c = temp;
//	}
//	if (a > b)
//	{
//		int temp = a;
//		a = b;
//		b = temp;
//	}
//	cout << a << " <= " << b << " <= " << c << endl;
//}
//
//int main()
//{
//	int a, b, c;
//	cout << "请输入三个整数：" << endl;
//	cin >> a >> b >> c;
//	point_sort(&a, &b, &c);
//	quote_sort(a, b, c);
//	system("pause");
//	return 0;
//}



////2.
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cout << "请输入人数：" << endl;
//	cin >> n;
//	int* p = new int[n];
//	//初始化
//	for (int i = 0; i < n; i++)
//	{
//		p[i] = 0;
//	}
//	int num_out = 1;//记录排除的人数（1开始，因为要留下一个人）
//	int num_count = 1;//记录报数
//	int i = 0;//数组下标
//	while (num_out < n)
//	{
//		if (i > n - 1)//超出了范围，减回来
//		{
//			i -= n;
//		}
//		while (p[i] == -1)//标记出局，跳过
//		{
//			i++;
//			if (i > n - 1)//超出了范围，减回来
//			{
//				i -= n;
//			}
//		}
//		if (num_count % 3 == 0)//出局
//		{
//			num_out++;
//			p[i] = -1;//标记出局
//		}
//		i++;
//		num_count++;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (p[i] == 0)
//		{
//			cout << "最后留下来的是第 " << i + 1 << " 号" << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}



////3.
//#include<iostream>
//using namespace std;
//
//void func(int* arr, int len, int val)
//{
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] == val)
//		{
//			arr[i] = 0;
//			return;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 2,4,6,3,5,7,1,9,12,17 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	func(arr, len, 5);
//	for (int i = 0; i < len; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}



//4.
#include<iostream>
using namespace std;

int main()
{
	string arr[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = i+1; j < 10; j++)
		{
			if (arr[i] > arr[j])
			{
				string temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << "--------------排序后---------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i+1 << "、 " << arr[i] << endl;
	}
	system("pause");
	return 0;
}