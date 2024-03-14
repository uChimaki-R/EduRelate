#include<iostream>
#include<algorithm>
using namespace std;
#define MOD 1000000007

typedef long long ll;

const ll N = 1010;
ll f[N];

int main()
{
	ll x, n, m, k;
	cin >> x >> n >> m >> k;
	f[0] = 1;
	for (ll i = 1; i <= x; i++)
	{
		if (i >= n)
		{
			f[i] = (f[i] + f[i - n]) % MOD;
		}
		if (i >= m)
		{
			f[i] = (f[i] + f[i - m]) % MOD;
		}
		if (i >= k)
		{
			f[i] = (f[i] + f[i - k]) % MOD;
		}
	}
	if (f[x])
	{
		cout << f[x];
	}
	else
	{
		cout << "impossible";
	}
	return 0;
}