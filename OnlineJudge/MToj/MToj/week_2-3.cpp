#include<iostream>
using namespace std;

int sum[1010][1010];

int main()
{
	int n, r, x, y, val;
	cin >> n >> r;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> val;
		if (sum[x + 1][y + 1])
		{
			//之前存过数
			sum[x + 1][y + 1] += val;
		}
		else
		{
			sum[x + 1][y + 1] = sum[x + 1][y] + val;
		}
		for (int j = y + 2; j <= 1000; j++)
		{
			//后面的更新数据
			sum[x + 1][j] += val;
		}
	}
	int max_z = 0;
	//从r开始防止向上向前越界
	for (int i = r; i <= 1000; i++)
	{
		for (int j = r; j <= 1000; j++)
		{
			int this_z = 0;
			for (int k = i; k > i - r; k--)
			{
				//统计往上r行
				this_z += (sum[k][j] - sum[k][j - r]);
			}
			max_z = max(max_z, this_z);
		}
	}
	cout << max_z;
	return 0;
}
