#include<iostream>
using namespace std;
#define int long long 

const int N = 100007;
int n, m;
int s[N], v[N];

bool check(int time)
{
	int sum = 0, mmax = 0;
	for (int i = 0; i < n; i++)
	{
		int ctbt = max((int)0, (time - s[i]) * v[i]);
		sum += ctbt;
		mmax = max(mmax, ctbt);
	}
	return sum - mmax >= m;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> s[i] >> v[i];
	int l = 1, r = 5000000000, ans = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}