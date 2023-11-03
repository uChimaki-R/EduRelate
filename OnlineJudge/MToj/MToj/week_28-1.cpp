#include<iostream>
using namespace std;
#define int long long
#define MOD 1007

int ksm(int a, int b) {
	a %= MOD;
	int ans = 1;
	while (b) {
		if (b & 1)ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}

signed main() {
	int m, n;
	cin >> m >> n;
	int ret = ksm(m, n) - m * ksm(m - 1, n - 1) % MOD;
	ret = (ret % MOD + MOD) % MOD;
	cout << ret;
	return 0;
}