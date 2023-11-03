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
	cout << "**          ��ӭʹ���������������           **" << endl;
	cout << "**   1����������               2����������   **" << endl;
	cout << "**   3��Ԫ�ز���               4��Ԫ�ز���   **" << endl;
	cout << "**   5��Ԫ��ɾ��               6���������   **" << endl;
	cout << "**   7�����ָ��λ��Ԫ��                     **" << endl;
	cout << "**   8����ָ������������Ԫ�����             **" << endl;
	cout << "**   0���˳�������                           **" << endl;
	cout << "***********************************************" << endl;
}

void input_val()
{
	cout << "������Ҫ�����Ԫ�ظ�����";
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cout << "������� " << i << " ��Ԫ�صĴ�С��";
		int val;
		cin >> val;
		arr[arr_size] = val;
		arr_size++;
	}
	cout << "ȫ��Ԫ��������ɣ�" << endl;
}

bool down(int a, int b)
{
	return a > b;
}

void sort_arr()
{
	if (arr_size == 0)
	{
		cout << "��ǰ�����СΪ0���޷�ִ�д˲�����" << endl;
		return;
	}
	cout << "1������  0������" << endl;
	cout << "���������򷽷���";
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
	cout << "������ɣ�" << endl;
}

void output_all()
{
	if (arr_size == 0)
	{
		cout << "��ǰ�����СΪ0���޷�ִ�д˲�����" << endl;
		return;
	}
	cout << "�����������£�" << endl;
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
		cout << "��ǰ�����СΪ0���޷�ִ�д˲�����" << endl;
		return;
	}
	cout << "��������Ҫ������±�λ�ã�";
	int pos;
	cin >> pos;
	if (pos < 0 || pos >= arr_size)
	{
		cout << "�����˷Ƿ��±꣡" << endl;
		return;
	}
	for (int i = arr_size; i > pos; i--)
	{
		arr[i] = arr[i - 1];
	}
	int val;
	cout << "��������Ҫ�����Ԫ�ش�С��";
	cin >> val;
	arr[pos] = val;
	arr_size++;
	cout << "Ԫ�ز�����ɣ�" << endl;
}

int find_val()
{
	if (arr_size == 0)
	{
		cout << "��ǰ�����СΪ0���޷�ִ�д˲�����" << endl;
		return -1;
	}
	cout << "������Ԫ�ش�С��";
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
		cout << "���鲻������Ԫ�أ�" << endl;
		return -1;
	}
	else
	{
		cout << "��Ԫ���±�Ϊ " << i << endl;
		return i;
	}
}

void erase_val()
{
	if (arr_size == 0)
	{
		cout << "��ǰ�����СΪ0���޷�ִ�д˲�����" << endl;
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
		cout << "��Ԫ��ɾ����ɣ�" << endl;
	}
}

void output_one()
{
	if (arr_size == 0)
	{
		cout << "��ǰ�����СΪ0���޷�ִ�д˲�����" << endl;
		return;
	}
	cout << "������Ҫ�����Ԫ���±꣺";
	int pos;
	cin >> pos;
	if (pos < 0 || pos >= arr_size)
	{
		cout << "�����˷Ƿ��±꣡" << endl;
		return;
	}
	cout << "���±�Ԫ�ش�СΪ��" << arr[pos] << endl;
}

void sum_val()
{
	if (arr_size == 0)
	{
		cout << "��ǰ�����СΪ0���޷�ִ�д˲�����" << endl;
		return;
	}
	cout << "������Ҫ��ӵ�Ԫ�ظ�����";
	int num,i = 1;
	cin >> num;
	int sum_arr[MAX_SIZE] = { 0 };
	while (1)
	{
		if (i==num+1)
		{
			break;
		}
		cout << "������� "<<i<<" ��Ԫ�ص��±꣺";
		int pos;
		cin >> pos;
		if (pos < 0 || pos >= arr_size)
		{
			cout << "�����˷Ƿ��±꣡�����ԣ�" << endl;
		}
		else
		{
			sum_arr[i - 1] = arr[pos];
			i++;
		}
	}
	int sum = 0;
	cout << "��¼����ǰѡ��Ԫ�����£�" << endl;
	for (int i = 0; i < num; i++)
	{
		sum += sum_arr[i];
		cout << sum_arr[i] << " ";
	}
	cout << endl;
	cout << "����ó��ܺ�Ϊ��" << sum << endl;
}

int main()
{
	while (1)
	{
		menu();
		cout << "���������ѡ��";
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
			cout << "��лʹ�ã�" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "�������������ԣ�" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}