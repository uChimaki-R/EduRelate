#include<iostream>
#include<map>
using namespace std;

long long height_arr[41];
map<pair<long long, long long>, long long> gold_num_arr;

long long height(const long long &n)
{
	if (height_arr[n])
	{
		return height_arr[n];
	}
	if (n == 0)
	{
		height_arr[n] = 1;
		return height_arr[n];
	}
	height_arr[n] = 2 * height(n - 1) + n + 2;
	return height_arr[n];
}

long long gold_num(const long long& n, const long long& i)
{
	long long temp = i;
	if (gold_num_arr.count({ n,i }))
	{
		return gold_num_arr[{n, i}];
	}
	if (n == 0 && i > 0)
	{
		gold_num_arr[{n, i}] = 1;
		return gold_num_arr[{n, i}];
	}
	//��ʼ�������
	long long gold = 0;

	//ÿ��һ������i���п��ܱ�Ϊ0���ʶ���ж�

	temp--;//�����������

	if (temp > 0)
	{
		//��һ��n-1��
		//���������n-1����������
		long long this_i = min(height(n - 1), temp);//����������������n-1���ĸ߶ȣ���õ�n-1���ĸ߶ȣ���ֻ֮����i��
		temp -= this_i;
		gold += gold_num(n - 1, this_i);
	}
	if (temp > 0)
	{
		//n�����
		//��������n�������������
		long long this_i = min(n, temp);
		temp -= this_i;
		gold += this_i;//ȫ�ǽ��ֱ�Ӽ�
	}
	if (temp > 0)
	{
		//�ڶ���n-1��
		long long this_i = min(height(n - 1), temp);
		temp -= this_i;
		gold += gold_num(n - 1, this_i);
	}

	temp--;//�����������

	gold_num_arr[{n, i}] = gold;
	return gold_num_arr[{n, i}];
}

int main()
{
	long long n, i;
	cin >> n >> i;
	cout << gold_num(n, i);
	return 0;
}
