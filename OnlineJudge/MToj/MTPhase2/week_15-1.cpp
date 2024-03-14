#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef long long LL;
const LL N = 11;
LL f[N][N];

void init()
{
	for (int i = 1; i < N; i++)
	{
		f[i][0] = f[i - 1][9];
		for (int j = 1; j <= 9; j++)
		{
			f[i][j] = j * pow(10, i - 1) + f[i][j - 1] + f[i][0];
		}
	}
}

LL dp(LL x)
{
	vector<LL>num;
	LL y = x;
	while (x)
	{
		num.push_back(x % 10);
		x /= 10;
	}
	LL res = 0;
	for (int i = num.size(); i >= 0; i--)
	{
		LL t = num[i];
		if (t != 0)
		{
			res += f[i + 1][t - 1] + (y % int(pow(10, i)) + 1) * t;
		}
	}
	return res;
}

int main()
{
	LL n;
	cin >> n;
	init();
	cout << dp(n);
	return 0;
}