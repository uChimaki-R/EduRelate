#include<iostream>
using namespace std;
#define int long long

const int N = 100007;
int x[N], h[N];

signed main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> x[i] >> h[i];
	x[0] = -2e9 + 7;
	x[n] = 2e9 + 7;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (x[i] - x[i - 1] > h[i])ans++;
		else if (x[i + 1] - x[i] > h[i]) {
			ans++;
			x[i] = x[i] + h[i];
		}
	}
	cout << ans;
	return 0;
}