#include<iostream>
#include<algorithm>

#define MAX_SIZE 100
using namespace std;

int arr[MAX_SIZE];
int arr_size = 0;

enum func
{
	__exit,
	_input,
	_sort,
	_insert,
	_find,
	_erase,
	_output_all,
	_output_one,
	_sum
};

void menu()
{
	cout << "***********************************************" << endl;
	cout << "**          欢迎使用整型数组操作库           **" << endl;
	cout << "**   1、数组输入               2、数组排序   **" << endl;
	cout << "**   3、元素插入               4、元素查找   **" << endl;
	cout << "**   5、元素删除               6、数组输出   **" << endl;
	cout << "**   7、输出指定位置元素                     **" << endl;
	cout << "**   8、对指定个数的数组元素求和             **" << endl;
	cout << "**   0、退出操作库                           **" << endl;
	cout << "***********************************************" << endl;
}

void input_val()
{
	cout << "请输入要输入的元素个数：";
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cout << "请输入第 " << i << " 个元素的大小：";
		int val;
		cin >> val;
		arr[arr_size] = val;
		arr_size++;
	}
	cout << "全部元素输入完成！" << endl;
}

bool down(int a, int b)
{
	return a > b;
}

void sort_arr()
{
	if (arr_size == 0)
	{
		cout << "当前数组大小为0，无法执行此操作！" << endl;
		return;
	}
	cout << "1、升序  0、降序" << endl;
	cout << "请输入排序方法：";
	int input;
	cin >> input;
	if (input)
	{
		sort(arr, arr + arr_size);
	}
	else
	{
		sort(arr, arr + arr_size, down);
	}
	cout << "排序完成！" << endl;
}

void output_all()
{
	if (arr_size == 0)
	{
		cout << "当前数组大小为0，无法执行此操作！" << endl;
		return;
	}
	cout << "数组内容如下：" << endl;
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insert_val()
{
	if (arr_size == 0)
	{
		cout << "当前数组大小为0，无法执行此操作！" << endl;
		return;
	}
	cout << "请输入你要插入的下标位置：";
	int pos;
	cin >> pos;
	if (pos < 0 || pos >= arr_size)
	{
		cout << "输入了非法下标！" << endl;
		return;
	}
	for (int i = arr_size; i > pos; i--)
	{
		arr[i] = arr[i - 1];
	}
	int val;
	cout << "请输入你要插入的元素大小：";
	cin >> val;
	arr[pos] = val;
	arr_size++;
	cout << "元素插入完成！" << endl;
}

int find_val()
{
	if (arr_size == 0)
	{
		cout << "当前数组大小为0，无法执行此操作！" << endl;
		return -1;
	}
	cout << "请输入元素大小：";
	int val;
	cin >> val;
	int i = 0;
	for (; i < arr_size; i++)
	{
		if (arr[i] == val)
		{
			break;
		}
	}
	if (i == arr_size)
	{
		cout << "数组不包含该元素！" << endl;
		return -1;
	}
	else
	{
		cout << "该元素下标为 " << i << endl;
		return i;
	}
}

void erase_val()
{
	if (arr_size == 0)
	{
		cout << "当前数组大小为0，无法执行此操作！" << endl;
		return;
	}
	int pos = find_val();
	if (pos!=-1)
	{
		for (int i = pos; i < arr_size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr_size--;
		cout << "该元素删除完成！" << endl;
	}
}

void output_one()
{
	if (arr_size == 0)
	{
		cout << "当前数组大小为0，无法执行此操作！" << endl;
		return;
	}
	cout << "请输入要输出的元素下标：";
	int pos;
	cin >> pos;
	if (pos < 0 || pos >= arr_size)
	{
		cout << "输入了非法下标！" << endl;
		return;
	}
	cout << "该下标元素大小为：" << arr[pos] << endl;
}

void sum_val()
{
	if (arr_size == 0)
	{
		cout << "当前数组大小为0，无法执行此操作！" << endl;
		return;
	}
	cout << "请输入要相加的元素个数：";
	int num,i = 1;
	cin >> num;
	int sum_arr[MAX_SIZE] = { 0 };
	while (1)
	{
		if (i==num+1)
		{
			break;
		}
		cout << "请输入第 "<<i<<" 个元素的下标：";
		int pos;
		cin >> pos;
		if (pos < 0 || pos >= arr_size)
		{
			cout << "输入了非法下标！请重试！" << endl;
		}
		else
		{
			sum_arr[i - 1] = arr[pos];
			i++;
		}
	}
	int sum = 0;
	cout << "记录到当前选择元素如下：" << endl;
	for (int i = 0; i < num; i++)
	{
		sum += sum_arr[i];
		cout << sum_arr[i] << " ";
	}
	cout << endl;
	cout << "计算得出总和为：" << sum << endl;
}

int main()
{
	while (1)
	{
		menu();
		cout << "请输入你的选择：";
		char c;
		cin >> c;
		switch (c - '0')
		{
		case _input:
			input_val();
			break;
		case _sort:
			sort_arr();
			break;
		case _insert:
			insert_val();
			break;
		case _find:
			find_val();
			break;
		case _erase:
			erase_val();
			break;
		case _output_all:
			output_all();
			break;
		case _output_one:
			output_one();
			break;
		case _sum:
			sum_val();
			break;
		case __exit:
			cout << "感谢使用！" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "输入有误，请重试！" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}