#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int v, n, m;
//sum1：从下标0找到下标i的位置找m/2（偶数就少一个）个甜品的最低价格
//sum2：从下标i找到下标n-1的位置找m/2（偶数就少一个）个甜品的最低价格
int sum1[100005], sum2[100005];

//使用大顶堆可以方便把最大价格的弹出去
priority_queue<int>mp1, mp2;

class Sweet
{
public:
	int price, sweet;
}sw[100005];

bool mycmp(const Sweet& s1, const Sweet& s2)
{
	return s1.sweet < s2.sweet;
}

int main()
{
	cin >> v >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> sw[i].sweet >> sw[i].price;
	}
	sort(sw, sw + n, mycmp);
	//初始化sum1 sum2
	sum1[0] = sw[0].price;
	mp1.push(sw[0].price);
	for (int i = 1; i < n; i++)
	{
		sum1[i] = sum1[i - 1] + sw[i].price;
		mp1.push(sw[i].price);
		if (mp1.size() > (m / 2 - 1 + m % 2))
		{
			sum1[i] -= mp1.top();
			mp1.pop();//弹出最大的数
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		sum2[i] = sum2[i + 1] + sw[i].price;
		mp2.push(sw[i].price);
		if (mp2.size() > (m / 2 - 1 + m % 2))
		{
			sum2[i] -= mp2.top();
			mp2.pop();//弹出最大的数
		}
	}
	if (m % 2)
	{
		//奇数
		for (int i = n - 1 - m / 2; i >= m / 2; i--)
		{
			//i的范围是中位数的选择区间
			//从高往低遍历，第一个满足要求的就是最优解
			if (sum1[i - 1] + sw[i].price + sum2[i + 1] <= v)
			{
				//满足价格要求
				cout << sw[i].sweet;
				break;
			}
		}
	}
	else
	{
		//偶数
		int ans = -1;
		for (int i = m / 2 - 1; i < n - m / 2; i++)
		{
			//i的范围是第一个中位数的选择区间
			//此时i的位置是第一个中位数的位置
			//使用二分查找法找到第二个中位数的位置
			int l = i + 1;
			int r = n - m / 2;
			int ret = 0;
			while (l <= r)
			{
				int mid = l + (r - l) / 2;
				if (sum1[i - 1] + sw[i].price + sw[mid].price + sum2[mid + 1] <= v)
				{
					ret = mid;//保存可行解，向右继续寻找更优解
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
			ans = max(ans, (sw[i].sweet + sw[ret].sweet) / 2);
		}
		cout << ans;
	}
	return 0;
}