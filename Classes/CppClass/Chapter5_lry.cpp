////1.
//#include<iostream>
//using namespace std;
//
//void move(int* p, int place)
//{
//	for (int i = 6; i >= place; i--)
//	{
//		p[i + 1] = p[i];
//	}
//}
//
//int main()
//{
//	int* p = new int[8];
//	cout << "---------------插入前----------------" << endl;
//	for (int i = 0; i < 7; i++)
//	{
//		p[i] = i;
//		cout << p[i] << " ";
//	}
//	cout << endl;
//	int input;
//	cout << "请输入要插入的数字：" << endl;
//	cin >> input;
//	for (int i = 0; i < 7; i++)
//	{
//		if (i == 0 && p[0] >= input)
//		{
//			move(p, 0);
//			p[0] = input;
//			break;
//		}
//		else if (i == 6 && p[6] <= input)
//		{
//			p[7] = input;
//			break;
//		}
//		else if (p[i] <= input && p[i + 1] >= input)
//		{
//			move(p, i + 1);
//			p[i + 1] = input;
//			break;
//		}
//	}
//	cout << "---------------插入后----------------" << endl;
//	for (int i = 0; i < 8; i++)
//	{
//		cout << p[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}


////2.
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int flag = 1;
//	int max = 0;
//	int arr[5][5] = { {1,2,3,4,5},{9,8,7,6,5},{1,3,5,7,9},{10,8,6,4,2},{4,5,6,7,8} };
//	//int arr[5][5] = { {1,2,3,4,5},{1,2,3,4,6} ,{1,2,3,4,7} ,{1,2,3,4,8},{1,2,3,4,9} };
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		flag = 1;
//		max = 0;
//		for (int j = 0; j < 5; j++)
//		{
//			//找出这行最大数的列数
//			if (arr[i][max] < arr[i][j])
//			{
//				max = j;
//			}
//		}
//		for (int j = 0; j < 5; j++)
//		{
//			if (j == i)
//			{
//				continue;
//			}
//			if (arr[j][max] < arr[i][max])//说明该列有比这个数小的，不符合题意
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag)
//		{
//			break;
//		}
//	}
//	if (flag)
//	{
//		cout << "有鞍点，坐标：" << i << " ," << max << endl;
//	}
//	else
//	{
//		cout << "无鞍点" << endl;
//	}
//	system("pause");
//	return 0;
//}




////3.
//#include<iostream>
//using namespace std;
//
//int HalfFind(int arr[], int len, int value)
//{
//	int left = 0;
//	int right = left + len - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > value)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < value)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int ret = HalfFind(arr, len, 9);
//	if (ret != -1)
//	{
//		cout << "找到该数字，下标为：" << ret << endl;
//	}
//	else
//	{
//		cout << "未找到该数字" << endl;
//	}
//	system("pause");
//	return 0;
//}


////4.
//#include<iostream>
//using namespace std;
//
//char find_only_one(string& s)
//{
//	for (int i = 0; i < s.length(); i++)
//	{
//		int count = 0;
//		for (int j = 0; j < s.length(); j++)
//		{
//			if (s[i] == s[j] && i != j)
//			{
//				count++;
//			}
//		}
//		if (count == 0)
//		{
//			return s[i];
//		}
//	}
//	return 'N';
//}
//
//int main()
//{
//	string s1 = "ggaaabccddeeffgg";
//	string s2 = "aabbccddeeffgghh";
//	char ch = find_only_one(s2);
//	if (ch == 'N')
//	{
//		cout << "no" << endl;
//	}
//	else
//	{
//		cout << ch << endl;
//	}
//	system("pause");
//	return 0;
//}



////5.
//#include<iostream>
//using namespace std;
//
//bool lr_same(string& s)
//{
//	int left = 0;
//	int right = s.length() - 1;
//	while (left <= right)
//	{
//		if (s[left] != s[right])
//		{
//			return false;
//		}
//		left++;
//		right--;
//	}
//	return true;
//}
//
//int main()
//{
//	string s = "abcdedcba";
//	bool check = lr_same(s);
//	if (check)
//	{
//		cout << "yes" << endl;
//	}
//	else
//	{
//		cout << "no" << endl;
//	}
//	system("pause");
//	return 0;
//}