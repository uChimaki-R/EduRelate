////1.
//#include<iostream>
//using namespace std;
//#include<set>
//
//int main()
//{
//	set<int>s;
//	for (int i = 2; i <= 100; i++)
//	{
//		s.insert(i);
//	}
//
//	set<int>::iterator is = s.begin();
//	while (is != s.end())
//	{
//		//遍历之后的元素，找到倍数并删去
//		//因为要从下一个开始判断是否为其倍数，所以要先将迭代器向后偏移
//		set<int>::iterator tmp = is;//利用tmp记录原来迭代器位置
//		set<int>::iterator i = ++tmp;
//		while(i != s.end())
//		{
//			if ((*i) % (*is) == 0)
//			{
//				//直接删除*i会使i变成end()，报错越界
//
//				tmp = ++i;//先将i的下一位位置保存
//
//				i--;//i偏移了，需要偏移回来
//
//				s.erase(*i);//删去倍数的数
//
//				i = tmp;//i还原为下一位位置
//
//				continue;//此时i不需要++，直接跳过（这也是为什么写while的原因，for会重复++）
//			}
//			i++;
//		}
//		is++;//找到下一个要比较的数
//	}
//
//	for (set<int>::iterator i2 = s.begin(); i2 != s.end(); i2++)
//	{
//		cout << (*i2) << " ";
//	}
//
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
//	int arr[10];
//	for (int i = 0; i < 10; i++)
//	{
//		cin >> arr[i];
//	}
//	for (int i = 0; i < 9; i++)
//	{
//		int min = i;
//		for (int j = i + 1; j < 10; j++)
//		{
//			if (arr[min] > arr[j])
//			{
//				min = j;
//			}
//		}
//		if (min != i)
//		{
//			int tmp = arr[min];
//			arr[min] = arr[i];
//			arr[i] = tmp;
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}


////3.
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int arr[3][3];
//	int sum = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cin >> arr[i][j];
//			if (i == j)
//			{
//				sum += arr[i][j];
//			}
//		}
//	}
//	cout << sum << endl;
//	system("pause");
//	return 0;
//}



////5.
//#include<iostream>
//using namespace std;
//
//void swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int arr[5];
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> arr[i];
//	}
//	int* left = &arr[0];
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int* right = left + len - 1;
//	while (left <= right)
//	{
//		swap(*left, *right);
//		left++;
//		right--;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}



////6.
//#include<iostream>
//using namespace std;
//#define LENGTH 5
//
//int main()
//{
//	int arr[LENGTH][LENGTH] = { 0 };
//	for (int i = 0; i < LENGTH; i++)
//	{
//		arr[i][0] = 1;
//		for (int j = 0; j < LENGTH; j++)
//		{
//			if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//		}
//	}
//	for (int i = 1; i < LENGTH; i++)
//	{
//		for (int j = 1; j < LENGTH; j++)
//		{
//			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//		}
//	}
//	for (int i = 0; i < LENGTH; i++)
//	{
//		for (int j = 0; j < LENGTH; j++)
//		{
//			if (arr[i][j] != 0)
//			{
//				cout << arr[i][j] << " ";
//			}
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}



////7.
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int flag = 1;
//	int max = 0;
//	//int arr[5][5] = { {1,2,3,4,5},{9,8,7,6,5},{1,3,5,7,9},{10,8,6,4,2},{4,5,6,7,8} };
//	int arr[5][5] = { {1,2,3,4,5},{1,2,3,4,6} ,{1,2,3,4,7} ,{1,2,3,4,8},{1,2,3,4,9} };
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



////8.
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


////9.
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



////10.
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int big = 0;
//	int small = 0;
//	int num = 0;
//	int space = 0;
//	int other = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		char c;
//		while ((c = getchar())!='\n')
//		{
//			if (c == ' ')
//			{
//				space++;
//			}
//			else if (c >= 'A' && c <= 'Z')
//			{
//				big++;
//			}
//			else if (c >= 'a' && c <= 'z')
//			{
//				small++;
//			}
//			else if (c >= '0' && c <= '9')
//			{
//				num++;
//			}
//			else
//			{
//				other++;
//			}
//		}
//	}
//	cout << "英文大写字母有 " << big << " 个" << endl;
//	cout << "英文小写字母有 " << small << " 个" << endl;
//	cout << "空格有 " << space << " 个" << endl;
//	cout << "数字有 " << num << " 个" << endl;
//	cout << "其他字符有 " << other << " 个" << endl;
//	system("pause");
//	return 0;
//}



////11.
//#include<iostream>
//#include<string>
//using namespace std;
//
//void test01()
//{
//	char arr[] = "*****";
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			cout << ' ';
//		}
//		for (int j = 0; j < 5; j++)
//		{
//			cout << arr[j];
//		}
//		cout << endl;
//	}
//}
//
//void test02()
//{
//	string s = "******";
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			cout << ' ';
//		}
//		cout << s;
//		cout << endl;
//	}
//}
//
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}


////12.
//#include<iostream>
//using namespace std;
//#include<string>
//
//int main()
//{
//	string s;
//	cout << "请输入原文:> ";
//	cin >> s;
//	for (int i = 0; i < s.length(); i++)
//	{
//		if (s[i] >= 'a' && s[i] <= 'z')
//		{
//			s[i] = 'a' + 26 - (s[i] - 'a' + 1);
//		}
//		else if (s[i] >= 'A' && s[i] <= 'Z')
//		{
//			s[i] = 'A' + 26 - (s[i] - 'A' + 1);
//		}
//	}
//	cout << "密码为:> " << s << endl;
//	system("pause");
//	return 0;
//}



////13.
//#include<iostream>
//using namespace std;
//#include<string>
//
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	s1 += s2;
//	cout << s1 << endl;
//	system("pause");
//	return 0;
//}



////14.
//#include<iostream>
//using namespace std;
//
//void sort(string& s)
//{
//	for (int i = 0; i < s.length() - 1; i++)
//	{
//		for (int j = i + 1; j < s.length(); j++)
//		{
//			if (s[i] > s[j])
//			{
//				char tmp = s[i];
//				s[i] = s[j];
//				s[j] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	string s;
//	cin >> s;
//	sort(s);
//	cout << s << endl;
//	system("pause");
//	return 0;
//}


////15.
//#include<iostream>
//using namespace std;
//#include<string>
//
//int main()
//{
//	string s, tmp;
//	int n = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> tmp;
//		if (tmp[0] == 'A')
//		{
//			s = tmp;
//		}
//	}
//	cout << s << endl;
//	system("pause");
//	return 0;
//}



////16.
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	string s;
//	cin >> s;
//	int j = s.length() - 1;
//	for (int i = 0; i < j; i++)
//	{
//		char tmp = s[i];
//		s[i] = s[j];
//		s[j] = tmp;
//		j--;
//	}
//	cout << s << endl;
//	system("pause");
//	return 0;
//}



//17.
#include<iostream>
using namespace std;
#include<string>
#include<vector>

class Student
{
public:
	Student(string name, int id, int score)
	{
		this->m_name = name;
		this->m_id = id;
		this->m_score = score;
	}
	string m_name;
	int m_id;
	int m_score;
};

ostream& operator<<(ostream& cout, Student& s)
{
	cout << "姓名: " << s.m_name << "学号: " << s.m_id << "成绩: " << s.m_score;
	return cout;
}

int main()
{
	vector<Student>v;
	for (int i = 0; i < 10; i++)
	{
		string name;
		int id, score;
		cout << "正在录入第 " << i + 1 << " 个学生的信息" << endl;
		cout << "请输入名字:> ";
		cin >> name;
		cout << "请输入学号:> ";
		cin >> id;
		cout << "请输入成绩:> ";
		cin >> score;
		Student s(name, id, score);
		v.push_back(s);
	}
	for (vector<Student>::iterator it = v.begin(); it != v.end(); it++)
	{
		if ((*it).m_score < 60)
		{
			cout << (*it) << endl;
		}
	}
	system("pause");
	return 0;
}