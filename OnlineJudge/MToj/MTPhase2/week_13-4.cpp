#include<iostream>
using namespace std;

typedef long long ll;
const ll N = 4e6 + 5;
ll n, mod;
ll dp[N], sum[N];

int main()
{
	cin >> n >> mod;
	dp[n] = sum[n] = 1;
	for (ll i = n - 1; i >= 1; i--)
	{
		dp[i] = sum[i + 1];
		for (ll j = 2; j * i <= n; j++)
		{
			ll r = min(n, j * i + j - 1);
			dp[i] = (dp[i] + sum[i * j] - sum[r + 1]) % mod;
		}
		sum[i] = (dp[i] + sum[i + 1]) % mod;
	}
	cout << dp[1];
	return 0;
}