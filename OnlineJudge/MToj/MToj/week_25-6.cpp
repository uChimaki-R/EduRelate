#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a % b)return gcd(b, a % b);
	return b;
}

int main()
{
	int cnt;
	cin >> cnt;
	for (int k = 1; k <= cnt; k++)
	{
		int ans = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (gcd(i, j) == 1)ans++;
			}
		}
		cout << k << ' ' << n << ' ' << ans + 2 << endl;
	}
	return 0;
}