#include<iostream>
using namespace std;

//目标是差分数组为全0
//每对一个区间操作，差分数组会有两个数一加一减
//差分数组正负数抵消完其中一方后会只剩下一个正数或者负数
//最后需要操作剩下的数的绝对值次
//综上，一共要处理原差分数组 正数和 和 负数和的绝对值 中的较大值

int main()
{
	int n, ps = 0, ng = 0;
	int last = 0, now;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> now;
		if (i > 1)
		{
			int sub = now - last;
			if (sub > 0)
			{
				ps += sub;
			}
			else
			{
				ng -= sub;
			}
		}
		last = now;
	}
	cout << max(ps, ng);
	return 0;
}