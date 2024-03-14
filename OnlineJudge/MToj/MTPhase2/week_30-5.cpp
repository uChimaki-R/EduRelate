#include<iostream>
using namespace std;
#define int long long
int n, m;
const int N = 100007;
int s[N], v[N];

bool check(int t) {
	int _max = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		int cur = max(0ll, (t - s[i]) * v[i]);
		_max = max(_max, cur);
		sum += cur;
	}
	return sum - _max >= m;
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> s[i] >> v[i];
	int ans = -1, l = 1, r = 5e9;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}