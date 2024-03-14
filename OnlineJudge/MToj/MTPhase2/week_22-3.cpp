#include<iostream>
using namespace std;
#define MOD 99999989

typedef long long ll;
ll n, ans, pre, suf;
ll arr[15], p[15];

int main()
{
	cin >> n;
	string s;
	cin >> s;
	p[0] = 1;
	for (ll i = 1; i <= n; i++)p[i] = p[i - 1] * 16;
	for (ll i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9')arr[i] = s[i] - '0';
		else arr[i] = s[i] - 'A' + 10;
	}
	for (ll i = 0; i < n; i++) {
		pre = suf = 0;
		for (ll j = 0; j <= i - 1; j++)pre = pre * 16 + arr[j];
		for (ll j = i + 1; j < n; j++)suf = suf * 16 + arr[j];
		if (arr[i] > 2)ans = (ans + ((pre + 1) * p[n - i - 1] % MOD)) % MOD;
		else if (arr[i] < 2)ans = (ans + (pre * p[n - i - 1] % MOD)) % MOD;
		else ans = (ans + (pre * p[n - i - 1] + suf + 1) % MOD) % MOD;
	}
	cout << ans;
	return 0;
}