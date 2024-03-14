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
	//开始数这个塔
	long long gold = 0;

	//每数一个部分i都有可能变为0，故多次判断

	temp--;//最下面的银币

	if (temp > 0)
	{
		//第一个n-1塔
		//计算在这个n-1塔数的数量
		long long this_i = min(height(n - 1), temp);//如果数的数量大过了n-1塔的高度，会得到n-1塔的高度，反之只能数i次
		temp -= this_i;
		gold += gold_num(n - 1, this_i);
	}
	if (temp > 0)
	{
		//n个金币
		//计算在这n个金币数的数量
		long long this_i = min(n, temp);
		temp -= this_i;
		gold += this_i;//全是金币直接加
	}
	if (temp > 0)
	{
		//第二个n-1塔
		long long this_i = min(height(n - 1), temp);
		temp -= this_i;
		gold += gold_num(n - 1, this_i);
	}

	temp--;//最上面的银币

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
