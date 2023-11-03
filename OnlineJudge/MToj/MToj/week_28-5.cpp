#include<iostream>
using namespace std;
#define MOD 12520

const int N = 10007;
int f[N][N];

int main() {
	f[0][0] = 1;
	for (int i = 1; i <= 10000; i++)
		for (int j = 0; j <= 100; j++)
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % MOD;
	int n, m;
	cin >> n >> m;
	int ans = 1;
	for (int i = 1; i <= m; i++) {
		int num;
		cin >> num;
		ans = ans * f[n][num] % MOD;
		n -= num;
	}
	cout << ans;
	return 0;
}