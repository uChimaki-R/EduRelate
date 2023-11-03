#include<iostream>
using namespace std;

const int N = 100010;

int a[N], t[N], ans[N];//ans[i]代表去掉i之后对于整体record的影响数
int n;

int lowbit(int x)
{
	return x & -x;
}

void add(int x, int k)
{
	for (; x <= n; x += lowbit(x))
	{
		t[x] += k;
	}
}

int sum(int x)
{
	int ans = 0;
	for (; x; x -= lowbit(x))
	{
		ans += t[x];
	}
	return ans;
}

int main()
{
	cin >> n;
	int val, m = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> val;
		m = max(m, val);
		int s = sum(val - 1);//比val小的数在前面出现的次数
		if (s == i - 1)//全部出现了
		{
			ans[val]--;//去掉val会使整体record减少1
		}
		else if (s == i - 2)//刚好差一个，说明前面有一个比val大的，正是m（到第i个为止的最大数）
		{
			ans[m]++;//去掉这个最大数可以让val成为一个record，使得整体record增加1
		}
		add(val, 1);//val出现过，标记次数1（因为是排列，所以实际上只会是0/1）
	}
	int ret = 0;
	m = -0x3f3f3f3f;//要设负数，因为可能有都是负数/0的情况，设0就进不去比较，结果会是0
	for (int i = 1; i <= n; i++)
	{
		if (m < ans[i])
		{
			ret = i;
			m = ans[i];
		}
	}
	cout << ret;
	return 0;
}