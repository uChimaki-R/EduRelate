#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll N = 200010;
ll f[N];

int main()
{
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		cin >> f[i];
	}
	ll ans = f[1];
	for (ll i = 1; i <= n; i++)
	{
		if (f[i - 1] > 0)
		{
			f[i] += f[i - 1];
		}
		ans = max(ans, f[i]);
	}
	cout << ans;
	return 0;
}