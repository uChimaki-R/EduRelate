#include<iostream>
using namespace std;

const int N = 107;
bool matrix[N][N];

int main() {
	int k, n, m;
	cin >> k >> n >> m;
	for (int i = 1; i <= m; i++) {
		int e1, e2;
		cin >> e1 >> e2;
		matrix[e1][e2] = matrix[e2][e1] = true;
	}
	int ans = 0;
	if (n <= k)cout << m;
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int cnt = 0;
				for (int k = 1; k <= n; k++) {
					if (matrix[k][i] && matrix[k][j])cnt++;
				}
				ans = max(ans, m - cnt);
			}
		}
		cout << ans;
	}
	return 0;
}