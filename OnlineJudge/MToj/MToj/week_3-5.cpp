#include<iostream>
using namespace std;

int cnt[20][3];

int main()
{
	string s1, s2;
	int n, k, ans = 0;
	cin >> n >> k >> s2 >> s1;
	for (int i = 0; i < (1 << n); i++)
	{
		int num = 0;
		for (int j = 0; j < n; j++)
		{
			if ((i >> j) & 1)
			{
				num++;
			}
		}
		if (num == k)
		{
			num = 0;
			for (int j = 0; j < n; j++)
			{
				if ((i >> j) & 1)
				{
					if (s1[j] == 'r')
					{
						cnt[num][0]++;
					}
					if (s1[j] == 's')
					{
						cnt[num][1]++;
					}
					if (s1[j] == 'p')
					{
						cnt[num][2]++;
					}
					num++;
				}
			}
		}
	}
	for (int i = 0; i < (1 << n); i++)
	{
		int num = 0;
		for (int j = 0; j < n; j++)
		{
			if ((i >> j) & 1)
			{
				num++;
			}
		}
		int ret = 0;
		if (num == k)
		{
			num = 0;
			for (int j = 0; j < n; j++)
			{
				if ((i >> j) & 1)
				{
					if (s2[j] == 'r')
					{
						ret += cnt[num][1];
					}
					if (s2[j] == 's')
					{
						ret += cnt[num][2];
					}
					if (s2[j] == 'p')
					{
						ret += cnt[num][0];
					}
					num++;
				}
				ans = max(ret, ans);
			}
		}
	}
	cout << ans;
	return 0;
}